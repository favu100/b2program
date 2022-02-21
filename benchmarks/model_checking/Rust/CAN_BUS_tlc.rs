#![ allow( dead_code, unused_imports, unused_mut, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::env;
use std::sync::atomic::{AtomicI32, AtomicI64, AtomicBool, Ordering};
use std::sync::{Arc, Mutex};
use std::thread;
use std::collections::{HashMap, HashSet, LinkedList};
use im::HashMap as PersistentHashMap;
use threadpool::ThreadPool;
use std::sync::mpsc::channel;
use derivative::Derivative;
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::bboolean::BBoolean;
use btypes::binteger::BInteger;
use btypes::brelation::BRelation;
use btypes::bset::BSet;
use btypes::bobject::BObject;
use btypes::btuple::BTuple;

#[derive(Clone, Copy)]
pub enum MC_TYPE { BFS, DFS, MIXED }


#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum T1state {
    T1_EN, 
    T1_CALC, 
    T1_SEND, 
    T1_WAIT
}
impl T1state {
    pub fn equal(&self, other: &T1state) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &T1state) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for T1state {}
impl Default for T1state {
    fn default() -> Self { T1state::T1_EN }
}
impl fmt::Display for T1state {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           T1state::T1_EN => write!(f, "T1_EN"),
           T1state::T1_CALC => write!(f, "T1_CALC"),
           T1state::T1_SEND => write!(f, "T1_SEND"),
           T1state::T1_WAIT => write!(f, "T1_WAIT"),
       }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum T2mode {
    T2MODE_SENSE, 
    T2MODE_TRANSMIT, 
    T2MODE_RELEASE
}
impl T2mode {
    pub fn equal(&self, other: &T2mode) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &T2mode) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for T2mode {}
impl Default for T2mode {
    fn default() -> Self { T2mode::T2MODE_SENSE }
}
impl fmt::Display for T2mode {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           T2mode::T2MODE_SENSE => write!(f, "T2MODE_SENSE"),
           T2mode::T2MODE_TRANSMIT => write!(f, "T2MODE_TRANSMIT"),
           T2mode::T2MODE_RELEASE => write!(f, "T2MODE_RELEASE"),
       }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum T2state {
    T2_EN, 
    T2_RCV, 
    T2_PROC, 
    T2_CALC, 
    T2_SEND, 
    T2_WAIT, 
    T2_RELEASE
}
impl T2state {
    pub fn equal(&self, other: &T2state) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &T2state) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for T2state {}
impl Default for T2state {
    fn default() -> Self { T2state::T2_EN }
}
impl fmt::Display for T2state {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           T2state::T2_EN => write!(f, "T2_EN"),
           T2state::T2_RCV => write!(f, "T2_RCV"),
           T2state::T2_PROC => write!(f, "T2_PROC"),
           T2state::T2_CALC => write!(f, "T2_CALC"),
           T2state::T2_SEND => write!(f, "T2_SEND"),
           T2state::T2_WAIT => write!(f, "T2_WAIT"),
           T2state::T2_RELEASE => write!(f, "T2_RELEASE"),
       }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum T3state {
    T3_READY, 
    T3_WRITE, 
    T3_RELEASE, 
    T3_READ, 
    T3_PROC, 
    T3_WAIT
}
impl T3state {
    pub fn equal(&self, other: &T3state) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &T3state) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for T3state {}
impl Default for T3state {
    fn default() -> Self { T3state::T3_READY }
}
impl fmt::Display for T3state {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           T3state::T3_READY => write!(f, "T3_READY"),
           T3state::T3_WRITE => write!(f, "T3_WRITE"),
           T3state::T3_RELEASE => write!(f, "T3_RELEASE"),
           T3state::T3_READ => write!(f, "T3_READ"),
           T3state::T3_PROC => write!(f, "T3_PROC"),
           T3state::T3_WAIT => write!(f, "T3_WAIT"),
       }
    }
}

#[derive(Derivative)]
#[derivative(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct CAN_BUS_tlc {
    BUSpriority: BInteger,
    BUSvalue: BInteger,
    BUSwrite: BRelation<BInteger, BInteger>,
    T1_state: T1state,
    T1_timer: BInteger,
    T1_writevalue: BInteger,
    T2_mode: T2mode,
    T2_readpriority: BInteger,
    T2_readvalue: BInteger,
    T2_state: T2state,
    T2_timer: BInteger,
    T2_writevalue: BInteger,
    T2v: BInteger,
    T3_enabled: BBoolean,
    T3_evaluated: BBoolean,
    T3_readpriority: BInteger,
    T3_readvalue: BInteger,
    T3_state: T3state,
    NATSET: BSet<BInteger>,
    _T1state: BSet<T1state>,
    _T2mode: BSet<T2mode>,
    _T2state: BSet<T2state>,
    _T3state: BSet<T3state>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T1Evaluate: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T1Calculate: Option<BSet<BInteger>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T1SendResult: Option<BSet<BTuple<BInteger, BInteger>>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T1Wait: Option<BSet<BInteger>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T2Evaluate: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T2ReadBus: Option<BSet<BTuple<BInteger, BInteger>>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T2Reset: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T2Complete: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T2ReleaseBus: Option<BSet<BInteger>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T2Calculate: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T2WriteBus: Option<BSet<BTuple<BInteger, BInteger>>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T2Wait: Option<BSet<BInteger>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T3Initiate: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T3Evaluate: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T3writebus: Option<BSet<BTuple<BInteger, BInteger>>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T3Read: Option<BSet<BTuple<BInteger, BInteger>>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T3Poll: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T3ReleaseBus: Option<BSet<BInteger>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T3Wait: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T3ReEnableWait: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_Update: Option<BSet<BInteger>>,}

impl CAN_BUS_tlc {

    pub fn new() -> CAN_BUS_tlc {
        //values: ''
        let mut m: CAN_BUS_tlc = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.NATSET = BSet::<BInteger>::interval(&BInteger::new(0), &BInteger::new(5));
        self._T1state = BSet::new(vec![T1state::T1_EN, T1state::T1_CALC, T1state::T1_SEND, T1state::T1_WAIT]);
        self._T2mode = BSet::new(vec![T2mode::T2MODE_SENSE, T2mode::T2MODE_TRANSMIT, T2mode::T2MODE_RELEASE]);
        self._T2state = BSet::new(vec![T2state::T2_EN, T2state::T2_RCV, T2state::T2_PROC, T2state::T2_CALC, T2state::T2_SEND, T2state::T2_WAIT, T2state::T2_RELEASE]);
        self._T3state = BSet::new(vec![T3state::T3_READY, T3state::T3_WRITE, T3state::T3_RELEASE, T3state::T3_READ, T3state::T3_PROC, T3state::T3_WAIT]);
        self.T2v = BInteger::new(0);
        self.T3_evaluated = BBoolean::new(true);
        self.T3_enabled = BBoolean::new(true);
        self.T1_state = T1state::T1_EN;
        self.T2_state = T2state::T2_EN;
        self.T3_state = T3state::T3_READY;
        self.T1_writevalue = BInteger::new(0);
        self.T2_writevalue = BInteger::new(0);
        self.T2_readvalue = BInteger::new(0);
        self.T2_readpriority = BInteger::new(0);
        self.T3_readvalue = BInteger::new(0);
        self.T3_readpriority = BInteger::new(0);
        self.T1_timer = BInteger::new(2);
        self.T2_timer = BInteger::new(3);
        self.BUSwrite = BRelation::new(vec![BTuple::from_refs(&BInteger::new(0), &BInteger::new(0))]).clone().clone();
        self.BUSvalue = BInteger::new(0);
        self.BUSpriority = BInteger::new(0);
        self.T2_mode = T2mode::T2MODE_SENSE;
    }

    pub fn get_NATSET(&self) -> BSet<BInteger> {
        return self.NATSET.clone();
    }

    pub fn get_BUSpriority(&self) -> BInteger {
        return self.BUSpriority.clone();
    }

    pub fn get_BUSvalue(&self) -> BInteger {
        return self.BUSvalue.clone();
    }

    pub fn get_BUSwrite(&self) -> BRelation<BInteger, BInteger> {
        return self.BUSwrite.clone();
    }

    pub fn get_T1_state(&self) -> T1state {
        return self.T1_state.clone();
    }

    pub fn get_T1_timer(&self) -> BInteger {
        return self.T1_timer.clone();
    }

    pub fn get_T1_writevalue(&self) -> BInteger {
        return self.T1_writevalue.clone();
    }

    pub fn get_T2_mode(&self) -> T2mode {
        return self.T2_mode.clone();
    }

    pub fn get_T2_readpriority(&self) -> BInteger {
        return self.T2_readpriority.clone();
    }

    pub fn get_T2_readvalue(&self) -> BInteger {
        return self.T2_readvalue.clone();
    }

    pub fn get_T2_state(&self) -> T2state {
        return self.T2_state.clone();
    }

    pub fn get_T2_timer(&self) -> BInteger {
        return self.T2_timer.clone();
    }

    pub fn get_T2_writevalue(&self) -> BInteger {
        return self.T2_writevalue.clone();
    }

    pub fn get_T2v(&self) -> BInteger {
        return self.T2v.clone();
    }

    pub fn get_T3_enabled(&self) -> BBoolean {
        return self.T3_enabled.clone();
    }

    pub fn get_T3_evaluated(&self) -> BBoolean {
        return self.T3_evaluated.clone();
    }

    pub fn get_T3_readpriority(&self) -> BInteger {
        return self.T3_readpriority.clone();
    }

    pub fn get_T3_readvalue(&self) -> BInteger {
        return self.T3_readvalue.clone();
    }

    pub fn get_T3_state(&self) -> T3state {
        return self.T3_state.clone();
    }

    pub fn get__T1state(&self) -> BSet<T1state> {
        return self._T1state.clone();
    }

    pub fn get__T2mode(&self) -> BSet<T2mode> {
        return self._T2mode.clone();
    }

    pub fn get__T2state(&self) -> BSet<T2state> {
        return self._T2state.clone();
    }

    pub fn get__T3state(&self) -> BSet<T3state> {
        return self._T3state.clone();
    }

    pub fn T1Evaluate(&mut self) -> () {
        //pre_assert
        self.T1_timer = BInteger::new(0);
        self.T1_state = T1state::T1_CALC;

    }

    pub fn T1Calculate(&mut self, mut p: BInteger) -> () {
        //pre_assert
        self.T1_writevalue = p;
        self.T1_state = T1state::T1_SEND;

    }

    pub fn T1SendResult(&mut self, mut ppriority: BInteger, mut pv: BInteger) -> () {
        //pre_assert
        let mut _ld_BUSwrite = self.BUSwrite.clone();
        self.BUSwrite = _ld_BUSwrite._override(&BRelation::new(vec![BTuple::from_refs(&ppriority, &pv)])).clone().clone();
        self.T1_state = T1state::T1_WAIT;

    }

    pub fn T1Wait(&mut self, mut pt: BInteger) -> () {
        //pre_assert
        self.T1_timer = pt;
        self.T1_state = T1state::T1_EN;

    }

    pub fn T2Evaluate(&mut self) -> () {
        //pre_assert
        self.T2_timer = BInteger::new(0);
        self.T2_state = T2state::T2_RCV;

    }

    pub fn T2ReadBus(&mut self, mut ppriority: BInteger, mut pv: BInteger) -> () {
        //pre_assert
        self.T2_readvalue = pv;
        self.T2_readpriority = ppriority;
        self.T2_state = T2state::T2_PROC;

    }

    pub fn T2Reset(&mut self) -> () {
        //pre_assert
        let mut _ld_T2v = self.T2v.clone();
        self.T2_writevalue = _ld_T2v;
        self.T2v = BInteger::new(0);
        self.T2_state = T2state::T2_SEND;
        self.T2_mode = T2mode::T2MODE_TRANSMIT;

    }

    pub fn T2Complete(&mut self) -> () {
        //pre_assert
        self.T2_state = T2state::T2_RELEASE;
        self.T2_mode = T2mode::T2MODE_SENSE;

    }

    pub fn T2ReleaseBus(&mut self, mut ppriority: BInteger) -> () {
        //pre_assert
        let mut _ld_BUSwrite = self.BUSwrite.clone();
        self.BUSwrite = _ld_BUSwrite.domainSubstraction(&BSet::new(vec![ppriority])).clone().clone();
        self.T2_state = T2state::T2_WAIT;

    }

    pub fn T2Calculate(&mut self) -> () {
        //pre_assert
        self.T2v = self.T2_readvalue;
        self.T2_state = T2state::T2_WAIT;

    }

    pub fn T2WriteBus(&mut self, mut ppriority: BInteger, mut pv: BInteger) -> () {
        //pre_assert
        let mut _ld_BUSwrite = self.BUSwrite.clone();
        self.BUSwrite = _ld_BUSwrite._override(&BRelation::new(vec![BTuple::from_refs(&ppriority, &pv)])).clone().clone();
        self.T2_state = T2state::T2_WAIT;

    }

    pub fn T2Wait(&mut self, mut pt: BInteger) -> () {
        //pre_assert
        self.T2_timer = pt;
        self.T2_state = T2state::T2_EN;

    }

    pub fn T3Initiate(&mut self) -> () {
        //pre_assert
        self.T3_state = T3state::T3_WRITE;
        self.T3_enabled = BBoolean::new(false);

    }

    pub fn T3Evaluate(&mut self) -> () {
        //pre_assert
        self.T3_state = T3state::T3_READ;

    }

    pub fn T3writebus(&mut self, mut ppriority: BInteger, mut pv: BInteger) -> () {
        //pre_assert
        let mut _ld_BUSwrite = self.BUSwrite.clone();
        self.BUSwrite = _ld_BUSwrite._override(&BRelation::new(vec![BTuple::from_refs(&ppriority, &pv)])).clone().clone();
        self.T3_state = T3state::T3_WAIT;

    }

    pub fn T3Read(&mut self, mut ppriority: BInteger, mut pv: BInteger) -> () {
        //pre_assert
        self.T3_readvalue = pv;
        self.T3_readpriority = ppriority;
        self.T3_state = T3state::T3_PROC;

    }

    pub fn T3Poll(&mut self) -> () {
        //pre_assert
        self.T3_state = T3state::T3_WAIT;

    }

    pub fn T3ReleaseBus(&mut self, mut ppriority: BInteger) -> () {
        //pre_assert
        let mut _ld_BUSwrite = self.BUSwrite.clone();
        self.BUSwrite = _ld_BUSwrite.domainSubstraction(&BSet::new(vec![ppriority])).clone().clone();
        self.T3_state = T3state::T3_RELEASE;

    }

    pub fn T3Wait(&mut self) -> () {
        //pre_assert
        self.T3_state = T3state::T3_READY;
        self.T3_evaluated = BBoolean::new(true);

    }

    pub fn T3ReEnableWait(&mut self) -> () {
        //pre_assert
        self.T3_state = T3state::T3_READY;
        self.T3_evaluated = BBoolean::new(true);
        self.T3_enabled = BBoolean::new(true);

    }

    pub fn Update(&mut self, mut pmax: BInteger) -> () {
        //pre_assert
        let mut _ld_T1_timer = self.T1_timer.clone();
        let mut _ld_T2_timer = self.T2_timer.clone();
        self.BUSvalue = self.BUSwrite.functionCall(&pmax);
        self.BUSpriority = pmax;
        self.T1_timer = _ld_T1_timer.minus(&BInteger::new(1));
        self.T2_timer = _ld_T2_timer.minus(&BInteger::new(1));
        self.T3_evaluated = BBoolean::new(false);

    }

    pub fn _tr_T1Evaluate(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_T1Evaluate.is_none() {
            let mut __tmp__val__ = self.T1_timer.equal(&BInteger::new(0)).and(&self.T1_state.equal(&T1state::T1_EN)).booleanValue();
            self._tr_cache_T1Evaluate = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_T1Evaluate.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T1Calculate(&mut self, is_caching: bool) -> BSet<BInteger> {
        //transition
        if !is_caching || self._tr_cache_T1Calculate.is_none() {
            let mut _ic_set_1: BSet<BInteger> = BSet::new(vec![]);
            for _ic_p_1 in BSet::<BInteger>::interval(&BInteger::new(1).negative(), &BInteger::new(3)).clone().iter().cloned() {
                if (self.T1_state.equal(&T1state::T1_CALC)).booleanValue() {
                    _ic_set_1 = _ic_set_1._union(&BSet::new(vec![_ic_p_1]));
                }

            }
            self._tr_cache_T1Calculate = Option::Some(_ic_set_1.clone());
            return _ic_set_1;
        } else {
            return self._tr_cache_T1Calculate.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T1SendResult(&mut self, is_caching: bool) -> BSet<BTuple<BInteger, BInteger>> {
        //transition
        if !is_caching || self._tr_cache_T1SendResult.is_none() {
            let mut _ic_set_2: BSet<BTuple<BInteger, BInteger>> = BSet::new(vec![]);
            {
                let mut _ic_ppriority_1 = BInteger::new(3);
                {
                    let mut _ic_pv_1 = self.T1_writevalue;
                    if (self.T1_state.equal(&T1state::T1_SEND)).booleanValue() {
                        _ic_set_2 = _ic_set_2._union(&BSet::new(vec![BTuple::from_refs(&_ic_ppriority_1, &_ic_pv_1)]));
                    }

                }
            }
            self._tr_cache_T1SendResult = Option::Some(_ic_set_2.clone());
            return _ic_set_2;
        } else {
            return self._tr_cache_T1SendResult.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T1Wait(&mut self, is_caching: bool) -> BSet<BInteger> {
        //transition
        if !is_caching || self._tr_cache_T1Wait.is_none() {
            let mut _ic_set_3: BSet<BInteger> = BSet::new(vec![]);
            {
                let mut _ic_pt_1 = BInteger::new(2);
                if (self.T1_state.equal(&T1state::T1_WAIT)).booleanValue() {
                    _ic_set_3 = _ic_set_3._union(&BSet::new(vec![_ic_pt_1]));
                }

            }
            self._tr_cache_T1Wait = Option::Some(_ic_set_3.clone());
            return _ic_set_3;
        } else {
            return self._tr_cache_T1Wait.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T2Evaluate(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_T2Evaluate.is_none() {
            let mut __tmp__val__ = self.T2_timer.equal(&BInteger::new(0)).and(&self.T2_state.equal(&T2state::T2_EN)).booleanValue();
            self._tr_cache_T2Evaluate = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_T2Evaluate.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T2ReadBus(&mut self, is_caching: bool) -> BSet<BTuple<BInteger, BInteger>> {
        //transition
        if !is_caching || self._tr_cache_T2ReadBus.is_none() {
            let mut _ic_set_5: BSet<BTuple<BInteger, BInteger>> = BSet::new(vec![]);
            {
                let mut _ic_ppriority_1 = self.BUSpriority;
                {
                    let mut _ic_pv_1 = self.BUSvalue;
                    if (self.T2_state.equal(&T2state::T2_RCV)).booleanValue() {
                        _ic_set_5 = _ic_set_5._union(&BSet::new(vec![BTuple::from_refs(&_ic_ppriority_1, &_ic_pv_1)]));
                    }

                }
            }
            self._tr_cache_T2ReadBus = Option::Some(_ic_set_5.clone());
            return _ic_set_5;
        } else {
            return self._tr_cache_T2ReadBus.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T2Reset(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_T2Reset.is_none() {
            let mut __tmp__val__ = self.T2_readpriority.equal(&BInteger::new(4)).and(&self.T2_state.equal(&T2state::T2_PROC)).booleanValue();
            self._tr_cache_T2Reset = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_T2Reset.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T2Complete(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_T2Complete.is_none() {
            let mut __tmp__val__ = self.T2_state.equal(&T2state::T2_PROC).and(&self.T2_readpriority.equal(&BInteger::new(5))).and(&self.T2_mode.equal(&T2mode::T2MODE_TRANSMIT)).booleanValue();
            self._tr_cache_T2Complete = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_T2Complete.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T2ReleaseBus(&mut self, is_caching: bool) -> BSet<BInteger> {
        //transition
        if !is_caching || self._tr_cache_T2ReleaseBus.is_none() {
            let mut _ic_set_8: BSet<BInteger> = BSet::new(vec![]);
            {
                let mut _ic_ppriority_1 = self.T2_readpriority;
                if (self.BUSwrite.domain().elementOf(&_ic_ppriority_1).and(&self.T2_state.equal(&T2state::T2_RELEASE))).booleanValue() {
                    _ic_set_8 = _ic_set_8._union(&BSet::new(vec![_ic_ppriority_1]));
                }

            }
            self._tr_cache_T2ReleaseBus = Option::Some(_ic_set_8.clone());
            return _ic_set_8;
        } else {
            return self._tr_cache_T2ReleaseBus.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T2Calculate(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_T2Calculate.is_none() {
            let mut __tmp__val__ = self.T2_readpriority.equal(&BInteger::new(3)).and(&self.T2_state.equal(&T2state::T2_PROC)).booleanValue();
            self._tr_cache_T2Calculate = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_T2Calculate.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T2WriteBus(&mut self, is_caching: bool) -> BSet<BTuple<BInteger, BInteger>> {
        //transition
        if !is_caching || self._tr_cache_T2WriteBus.is_none() {
            let mut _ic_set_10: BSet<BTuple<BInteger, BInteger>> = BSet::new(vec![]);
            {
                let mut _ic_ppriority_1 = BInteger::new(5);
                {
                    let mut _ic_pv_1 = self.T2_writevalue;
                    if (self.T2_state.equal(&T2state::T2_SEND)).booleanValue() {
                        _ic_set_10 = _ic_set_10._union(&BSet::new(vec![BTuple::from_refs(&_ic_ppriority_1, &_ic_pv_1)]));
                    }

                }
            }
            self._tr_cache_T2WriteBus = Option::Some(_ic_set_10.clone());
            return _ic_set_10;
        } else {
            return self._tr_cache_T2WriteBus.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T2Wait(&mut self, is_caching: bool) -> BSet<BInteger> {
        //transition
        if !is_caching || self._tr_cache_T2Wait.is_none() {
            let mut _ic_set_11: BSet<BInteger> = BSet::new(vec![]);
            {
                let mut _ic_pt_1 = BInteger::new(3);
                if (self.T2_state.equal(&T2state::T2_WAIT)).booleanValue() {
                    _ic_set_11 = _ic_set_11._union(&BSet::new(vec![_ic_pt_1]));
                }

            }
            self._tr_cache_T2Wait = Option::Some(_ic_set_11.clone());
            return _ic_set_11;
        } else {
            return self._tr_cache_T2Wait.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T3Initiate(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_T3Initiate.is_none() {
            let mut __tmp__val__ = self.T3_state.equal(&T3state::T3_READY).and(&self.T3_evaluated.equal(&BBoolean::new(false))).and(&self.T3_enabled.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_T3Initiate = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_T3Initiate.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T3Evaluate(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_T3Evaluate.is_none() {
            let mut __tmp__val__ = self.T3_state.equal(&T3state::T3_READY).and(&self.T3_evaluated.equal(&BBoolean::new(false))).and(&self.T3_enabled.equal(&BBoolean::new(false))).booleanValue();
            self._tr_cache_T3Evaluate = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_T3Evaluate.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T3writebus(&mut self, is_caching: bool) -> BSet<BTuple<BInteger, BInteger>> {
        //transition
        if !is_caching || self._tr_cache_T3writebus.is_none() {
            let mut _ic_set_14: BSet<BTuple<BInteger, BInteger>> = BSet::new(vec![]);
            {
                let mut _ic_ppriority_1 = BInteger::new(4);
                {
                    let mut _ic_pv_1 = BInteger::new(0);
                    if (self.T3_state.equal(&T3state::T3_WRITE)).booleanValue() {
                        _ic_set_14 = _ic_set_14._union(&BSet::new(vec![BTuple::from_refs(&_ic_ppriority_1, &_ic_pv_1)]));
                    }

                }
            }
            self._tr_cache_T3writebus = Option::Some(_ic_set_14.clone());
            return _ic_set_14;
        } else {
            return self._tr_cache_T3writebus.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T3Read(&mut self, is_caching: bool) -> BSet<BTuple<BInteger, BInteger>> {
        //transition
        if !is_caching || self._tr_cache_T3Read.is_none() {
            let mut _ic_set_15: BSet<BTuple<BInteger, BInteger>> = BSet::new(vec![]);
            {
                let mut _ic_ppriority_1 = self.BUSpriority;
                {
                    let mut _ic_pv_1 = self.BUSvalue;
                    if (self.T3_state.equal(&T3state::T3_READ)).booleanValue() {
                        _ic_set_15 = _ic_set_15._union(&BSet::new(vec![BTuple::from_refs(&_ic_ppriority_1, &_ic_pv_1)]));
                    }

                }
            }
            self._tr_cache_T3Read = Option::Some(_ic_set_15.clone());
            return _ic_set_15;
        } else {
            return self._tr_cache_T3Read.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T3Poll(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_T3Poll.is_none() {
            let mut __tmp__val__ = self.T3_readpriority.less(&BInteger::new(5)).and(&self.T3_state.equal(&T3state::T3_PROC)).booleanValue();
            self._tr_cache_T3Poll = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_T3Poll.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T3ReleaseBus(&mut self, is_caching: bool) -> BSet<BInteger> {
        //transition
        if !is_caching || self._tr_cache_T3ReleaseBus.is_none() {
            let mut _ic_set_17: BSet<BInteger> = BSet::new(vec![]);
            {
                let mut _ic_ppriority_1 = BInteger::new(4);
                if (self.T3_readpriority.equal(&BInteger::new(5)).and(&self.T3_state.equal(&T3state::T3_PROC))).booleanValue() {
                    _ic_set_17 = _ic_set_17._union(&BSet::new(vec![_ic_ppriority_1]));
                }

            }
            self._tr_cache_T3ReleaseBus = Option::Some(_ic_set_17.clone());
            return _ic_set_17;
        } else {
            return self._tr_cache_T3ReleaseBus.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T3Wait(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_T3Wait.is_none() {
            let mut __tmp__val__ = self.T3_state.equal(&T3state::T3_WAIT).booleanValue();
            self._tr_cache_T3Wait = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_T3Wait.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T3ReEnableWait(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_T3ReEnableWait.is_none() {
            let mut __tmp__val__ = self.T3_state.equal(&T3state::T3_RELEASE).booleanValue();
            self._tr_cache_T3ReEnableWait = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_T3ReEnableWait.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_Update(&mut self, is_caching: bool) -> BSet<BInteger> {
        //transition
        if !is_caching || self._tr_cache_Update.is_none() {
            let mut _ic_set_20: BSet<BInteger> = BSet::new(vec![]);
            {
                let mut _ic_pmax_1 = self.BUSwrite.domain()._max();
                if (self.T1_timer.greater(&BInteger::new(0)).and(&self.T2_timer.greater(&BInteger::new(0))).and(&self.T3_enabled.equal(&BBoolean::new(true)).or(&self.T3_evaluated.equal(&BBoolean::new(true))))).booleanValue() {
                    _ic_set_20 = _ic_set_20._union(&BSet::new(vec![_ic_pmax_1]));
                }

            }
            self._tr_cache_Update = Option::Some(_ic_set_20.clone());
            return _ic_set_20;
        } else {
            return self._tr_cache_Update.as_ref().unwrap().clone();
        }
    }

    pub fn _check_inv_1(&self) -> bool {
        //invariant
        return self.T2v.isInteger().booleanValue();
    }

    pub fn _check_inv_2(&self) -> bool {
        //invariant
        return butils::BOOL.elementOf(&self.T3_evaluated).booleanValue();
    }

    pub fn _check_inv_3(&self) -> bool {
        //invariant
        return butils::BOOL.elementOf(&self.T3_enabled).booleanValue();
    }

    pub fn _check_inv_4(&self) -> bool {
        //invariant
        return self._T1state.elementOf(&self.T1_state).booleanValue();
    }

    pub fn _check_inv_5(&self) -> bool {
        //invariant
        return self._T2state.elementOf(&self.T2_state).booleanValue();
    }

    pub fn _check_inv_6(&self) -> bool {
        //invariant
        return self._T3state.elementOf(&self.T3_state).booleanValue();
    }

    pub fn _check_inv_7(&self) -> bool {
        //invariant
        return self.T1_writevalue.isInteger().booleanValue();
    }

    pub fn _check_inv_8(&self) -> bool {
        //invariant
        return self.T2_writevalue.isInteger().booleanValue();
    }

    pub fn _check_inv_9(&self) -> bool {
        //invariant
        return self.T2_readvalue.isInteger().booleanValue();
    }

    pub fn _check_inv_10(&self) -> bool {
        //invariant
        return self.T1_timer.isNatural().booleanValue();
    }

    pub fn _check_inv_11(&self) -> bool {
        //invariant
        return self.T2_timer.isNatural().booleanValue();
    }

    pub fn _check_inv_12(&self) -> bool {
        //invariant
        return self._T2mode.elementOf(&self.T2_mode).booleanValue();
    }

    pub fn _check_inv_13(&self) -> bool {
        //invariant
        return self.BUSvalue.isInteger().booleanValue();
    }

    pub fn _check_inv_14(&self) -> bool {
        //invariant
        return self.NATSET.elementOf(&self.BUSpriority).booleanValue();
    }

    pub fn _check_inv_15(&self) -> bool {
        //invariant
        return self.T3_readvalue.isInteger().booleanValue();
    }

    pub fn _check_inv_16(&self) -> bool {
        //invariant
        return self.NATSET.elementOf(&self.T3_readpriority).booleanValue();
    }

    pub fn _check_inv_17(&self) -> bool {
        //invariant
        return self.NATSET.elementOf(&self.T2_readpriority).booleanValue();
    }

    pub fn _check_inv_18(&self) -> bool {
        //invariant
        return self.BUSwrite.checkDomain(&self.NATSET).and(&self.BUSwrite.checkRangeInteger()).and(&self.BUSwrite.isFunction()).and(&self.BUSwrite.isPartial(&self.NATSET)).booleanValue();
    }

    pub fn _check_inv_19(&self) -> bool {
        //invariant
        return self.BUSwrite.unequal(&BRelation::new(vec![])).booleanValue();
    }

    pub fn _check_inv_20(&self) -> bool {
        //invariant
        return self.BUSwrite.domain().elementOf(&BInteger::new(0)).booleanValue();
    }

    fn invalidate_caches(&mut self, to_invalidate: &HashSet<&'static str>) {
        //calling the given functions without caching will recalculate them and cache them afterwards
        //if caching is enabled globally, this will just prefill those, if caching is
        for trans in to_invalidate.iter() {
            match *trans {
                "_tr_T1Evaluate" => {self._tr_T1Evaluate(false);}, 
                "_tr_T1Calculate" => {self._tr_T1Calculate(false);}, 
                "_tr_T1SendResult" => {self._tr_T1SendResult(false);}, 
                "_tr_T1Wait" => {self._tr_T1Wait(false);}, 
                "_tr_T2Evaluate" => {self._tr_T2Evaluate(false);}, 
                "_tr_T2ReadBus" => {self._tr_T2ReadBus(false);}, 
                "_tr_T2Reset" => {self._tr_T2Reset(false);}, 
                "_tr_T2Complete" => {self._tr_T2Complete(false);}, 
                "_tr_T2ReleaseBus" => {self._tr_T2ReleaseBus(false);}, 
                "_tr_T2Calculate" => {self._tr_T2Calculate(false);}, 
                "_tr_T2WriteBus" => {self._tr_T2WriteBus(false);}, 
                "_tr_T2Wait" => {self._tr_T2Wait(false);}, 
                "_tr_T3Initiate" => {self._tr_T3Initiate(false);}, 
                "_tr_T3Evaluate" => {self._tr_T3Evaluate(false);}, 
                "_tr_T3writebus" => {self._tr_T3writebus(false);}, 
                "_tr_T3Read" => {self._tr_T3Read(false);}, 
                "_tr_T3Poll" => {self._tr_T3Poll(false);}, 
                "_tr_T3ReleaseBus" => {self._tr_T3ReleaseBus(false);}, 
                "_tr_T3Wait" => {self._tr_T3Wait(false);}, 
                "_tr_T3ReEnableWait" => {self._tr_T3ReEnableWait(false);}, 
                "_tr_Update" => {self._tr_Update(false);}, 
                _ => {},
            }
        }
    }

    //model_check_next_states
    fn generateNextStates(state: &mut CAN_BUS_tlc,
                          isCaching: bool,
                          invariant_dependency: &HashMap<&str, HashSet<&'static str>>,
                          dependent_invariant_m: Arc<Mutex<HashMap<CAN_BUS_tlc, HashSet<&str>>>>,
                          guard_dependency: &HashMap<&str, HashSet<&'static str>>,
                          dependent_guard_m: Arc<Mutex<HashMap<CAN_BUS_tlc, HashSet<&str>>>>,
                          guardCache: Arc<Mutex<HashMap<CAN_BUS_tlc, PersistentHashMap<&str, bool>>>>,
                          parents_m: Arc<Mutex<HashMap<CAN_BUS_tlc, CAN_BUS_tlc>>>,
                          transitions: Arc<AtomicI64>) -> HashSet<CAN_BUS_tlc> {
        let mut result = HashSet::<CAN_BUS_tlc>::new();
        if isCaching {
            let mut parents_guard_o = parents_m.lock().unwrap().get(state).and_then(|p| guardCache.lock().unwrap().get(p).cloned());
            let mut newCache = if parents_guard_o.is_none() { PersistentHashMap::new() } else { parents_guard_o.as_ref().unwrap().clone() };
            //model_check_transition
            let mut _trid_1 = state._tr_T1Evaluate(isCaching);
            if _trid_1 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.T1Evaluate();
                match guard_dependency.get("T1Evaluate") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("T1Evaluate").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("T1Evaluate").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_2 = state._tr_T1Calculate(isCaching);
            for param in _trid_2.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.T1Calculate(_tmp_1);
                match guard_dependency.get("T1Calculate") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("T1Calculate").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("T1Calculate").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_3 = state._tr_T1SendResult(isCaching);
            for param in _trid_3.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param.projection2();
                //model_check_transition_param_assignment
                let mut _tmp_2 = param.projection1();

                let mut copiedState = state.clone();
                copiedState.T1SendResult(_tmp_2, _tmp_1);
                match guard_dependency.get("T1SendResult") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("T1SendResult").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("T1SendResult").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_4 = state._tr_T1Wait(isCaching);
            for param in _trid_4.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.T1Wait(_tmp_1);
                match guard_dependency.get("T1Wait") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("T1Wait").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("T1Wait").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_5 = state._tr_T2Evaluate(isCaching);
            if _trid_5 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.T2Evaluate();
                match guard_dependency.get("T2Evaluate") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("T2Evaluate").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("T2Evaluate").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_6 = state._tr_T2ReadBus(isCaching);
            for param in _trid_6.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param.projection2();
                //model_check_transition_param_assignment
                let mut _tmp_2 = param.projection1();

                let mut copiedState = state.clone();
                copiedState.T2ReadBus(_tmp_2, _tmp_1);
                match guard_dependency.get("T2ReadBus") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("T2ReadBus").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("T2ReadBus").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_7 = state._tr_T2Reset(isCaching);
            if _trid_7 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.T2Reset();
                match guard_dependency.get("T2Reset") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("T2Reset").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("T2Reset").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_8 = state._tr_T2Complete(isCaching);
            if _trid_8 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.T2Complete();
                match guard_dependency.get("T2Complete") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("T2Complete").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("T2Complete").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_9 = state._tr_T2ReleaseBus(isCaching);
            for param in _trid_9.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.T2ReleaseBus(_tmp_1);
                match guard_dependency.get("T2ReleaseBus") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("T2ReleaseBus").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("T2ReleaseBus").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_10 = state._tr_T2Calculate(isCaching);
            if _trid_10 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.T2Calculate();
                match guard_dependency.get("T2Calculate") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("T2Calculate").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("T2Calculate").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_11 = state._tr_T2WriteBus(isCaching);
            for param in _trid_11.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param.projection2();
                //model_check_transition_param_assignment
                let mut _tmp_2 = param.projection1();

                let mut copiedState = state.clone();
                copiedState.T2WriteBus(_tmp_2, _tmp_1);
                match guard_dependency.get("T2WriteBus") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("T2WriteBus").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("T2WriteBus").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_12 = state._tr_T2Wait(isCaching);
            for param in _trid_12.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.T2Wait(_tmp_1);
                match guard_dependency.get("T2Wait") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("T2Wait").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("T2Wait").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_13 = state._tr_T3Initiate(isCaching);
            if _trid_13 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.T3Initiate();
                match guard_dependency.get("T3Initiate") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("T3Initiate").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("T3Initiate").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_14 = state._tr_T3Evaluate(isCaching);
            if _trid_14 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.T3Evaluate();
                match guard_dependency.get("T3Evaluate") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("T3Evaluate").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("T3Evaluate").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_15 = state._tr_T3writebus(isCaching);
            for param in _trid_15.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param.projection2();
                //model_check_transition_param_assignment
                let mut _tmp_2 = param.projection1();

                let mut copiedState = state.clone();
                copiedState.T3writebus(_tmp_2, _tmp_1);
                match guard_dependency.get("T3writebus") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("T3writebus").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("T3writebus").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_16 = state._tr_T3Read(isCaching);
            for param in _trid_16.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param.projection2();
                //model_check_transition_param_assignment
                let mut _tmp_2 = param.projection1();

                let mut copiedState = state.clone();
                copiedState.T3Read(_tmp_2, _tmp_1);
                match guard_dependency.get("T3Read") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("T3Read").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("T3Read").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_17 = state._tr_T3Poll(isCaching);
            if _trid_17 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.T3Poll();
                match guard_dependency.get("T3Poll") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("T3Poll").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("T3Poll").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_18 = state._tr_T3ReleaseBus(isCaching);
            for param in _trid_18.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.T3ReleaseBus(_tmp_1);
                match guard_dependency.get("T3ReleaseBus") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("T3ReleaseBus").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("T3ReleaseBus").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_19 = state._tr_T3Wait(isCaching);
            if _trid_19 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.T3Wait();
                match guard_dependency.get("T3Wait") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("T3Wait").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("T3Wait").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_20 = state._tr_T3ReEnableWait(isCaching);
            if _trid_20 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.T3ReEnableWait();
                match guard_dependency.get("T3ReEnableWait") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("T3ReEnableWait").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("T3ReEnableWait").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_21 = state._tr_Update(isCaching);
            for param in _trid_21.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.Update(_tmp_1);
                match guard_dependency.get("Update") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("Update").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("Update").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }

            guardCache.lock().unwrap().insert(state.clone(), newCache);
        } else {
            //model_check_transition
            if state._tr_T1Evaluate(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.T1Evaluate();
                match guard_dependency.get("T1Evaluate") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_2 = state._tr_T1Calculate(isCaching);
            for param in _trid_2.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.T1Calculate(_tmp_1);
                match guard_dependency.get("T1Calculate") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_3 = state._tr_T1SendResult(isCaching);
            for param in _trid_3.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param.projection2();
                //model_check_transition_param_assignment
                let mut _tmp_2 = param.projection1();

                let mut copiedState = state.clone();
                copiedState.T1SendResult(_tmp_2, _tmp_1);
                match guard_dependency.get("T1SendResult") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_4 = state._tr_T1Wait(isCaching);
            for param in _trid_4.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.T1Wait(_tmp_1);
                match guard_dependency.get("T1Wait") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_T2Evaluate(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.T2Evaluate();
                match guard_dependency.get("T2Evaluate") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_6 = state._tr_T2ReadBus(isCaching);
            for param in _trid_6.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param.projection2();
                //model_check_transition_param_assignment
                let mut _tmp_2 = param.projection1();

                let mut copiedState = state.clone();
                copiedState.T2ReadBus(_tmp_2, _tmp_1);
                match guard_dependency.get("T2ReadBus") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_T2Reset(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.T2Reset();
                match guard_dependency.get("T2Reset") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_T2Complete(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.T2Complete();
                match guard_dependency.get("T2Complete") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_9 = state._tr_T2ReleaseBus(isCaching);
            for param in _trid_9.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.T2ReleaseBus(_tmp_1);
                match guard_dependency.get("T2ReleaseBus") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_T2Calculate(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.T2Calculate();
                match guard_dependency.get("T2Calculate") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_11 = state._tr_T2WriteBus(isCaching);
            for param in _trid_11.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param.projection2();
                //model_check_transition_param_assignment
                let mut _tmp_2 = param.projection1();

                let mut copiedState = state.clone();
                copiedState.T2WriteBus(_tmp_2, _tmp_1);
                match guard_dependency.get("T2WriteBus") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_12 = state._tr_T2Wait(isCaching);
            for param in _trid_12.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.T2Wait(_tmp_1);
                match guard_dependency.get("T2Wait") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_T3Initiate(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.T3Initiate();
                match guard_dependency.get("T3Initiate") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_T3Evaluate(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.T3Evaluate();
                match guard_dependency.get("T3Evaluate") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_15 = state._tr_T3writebus(isCaching);
            for param in _trid_15.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param.projection2();
                //model_check_transition_param_assignment
                let mut _tmp_2 = param.projection1();

                let mut copiedState = state.clone();
                copiedState.T3writebus(_tmp_2, _tmp_1);
                match guard_dependency.get("T3writebus") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_16 = state._tr_T3Read(isCaching);
            for param in _trid_16.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param.projection2();
                //model_check_transition_param_assignment
                let mut _tmp_2 = param.projection1();

                let mut copiedState = state.clone();
                copiedState.T3Read(_tmp_2, _tmp_1);
                match guard_dependency.get("T3Read") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_T3Poll(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.T3Poll();
                match guard_dependency.get("T3Poll") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_18 = state._tr_T3ReleaseBus(isCaching);
            for param in _trid_18.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.T3ReleaseBus(_tmp_1);
                match guard_dependency.get("T3ReleaseBus") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_T3Wait(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.T3Wait();
                match guard_dependency.get("T3Wait") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_T3ReEnableWait(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.T3ReEnableWait();
                match guard_dependency.get("T3ReEnableWait") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_21 = state._tr_Update(isCaching);
            for param in _trid_21.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.Update(_tmp_1);
                match guard_dependency.get("Update") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }

        }
        return result;
    }

    //model_check_evaluate_state

    //model_check_invariants
    pub fn checkInvariants(state: &CAN_BUS_tlc,
                           isCaching: bool,
                           dependent_invariant_m: Arc<Mutex<HashMap<CAN_BUS_tlc, HashSet<&str>>>> ) -> bool {
        let cached_invariants = dependent_invariant_m.lock().unwrap().get(&state).cloned();
        if cached_invariants.is_some() && isCaching {
            let dependent_invariants_of_state = cached_invariants.unwrap().clone();
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_1") {
                if !state._check_inv_1() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_2") {
                if !state._check_inv_2() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_3") {
                if !state._check_inv_3() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_4") {
                if !state._check_inv_4() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_5") {
                if !state._check_inv_5() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_6") {
                if !state._check_inv_6() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_7") {
                if !state._check_inv_7() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_8") {
                if !state._check_inv_8() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_9") {
                if !state._check_inv_9() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_10") {
                if !state._check_inv_10() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_11") {
                if !state._check_inv_11() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_12") {
                if !state._check_inv_12() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_13") {
                if !state._check_inv_13() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_14") {
                if !state._check_inv_14() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_15") {
                if !state._check_inv_15() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_16") {
                if !state._check_inv_16() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_17") {
                if !state._check_inv_17() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_18") {
                if !state._check_inv_18() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_19") {
                if !state._check_inv_19() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_20") {
                if !state._check_inv_20() {
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6() || !state._check_inv_7() || !state._check_inv_8() || !state._check_inv_9() || !state._check_inv_10() || !state._check_inv_11() || !state._check_inv_12() || !state._check_inv_13() || !state._check_inv_14() || !state._check_inv_15() || !state._check_inv_16() || !state._check_inv_17() || !state._check_inv_18() || !state._check_inv_19() || !state._check_inv_20());
    }

    //model_check_print
    fn print_result(states: i64, transitions: i64, deadlock_detected: bool, invariant_violated: bool) {
        if deadlock_detected { println!("DEADLOCK DETECTED"); }
        if invariant_violated { println!("INVARIANT VIOLATED"); }
        if !deadlock_detected && !invariant_violated { println!("MODEL CHECKING SUCCESSFUL"); }
        println!("Number of States: {}", states);
        println!("Number of Transitions: {}", transitions);
    }

    //model_check_main
    fn next(collection_m: Arc<Mutex<LinkedList<CAN_BUS_tlc>>>, mc_type: MC_TYPE) -> CAN_BUS_tlc {
        let mut collection = collection_m.lock().unwrap();
        return match mc_type {
                MC_TYPE::BFS   => collection.pop_front().unwrap(),
                MC_TYPE::DFS   => collection.pop_back().unwrap(),
                MC_TYPE::MIXED => if collection.len() % 2 == 0 { collection.pop_front().unwrap() } else { collection.pop_back().unwrap() }
            };
    }

    fn model_check_single_threaded(mc_type: MC_TYPE, is_caching: bool) {
        let mut machine = CAN_BUS_tlc::new();

        let invariant_violated = AtomicBool::new(false);
        let deadlock_detected = AtomicBool::new(false);
        let stop_threads = AtomicBool::new(false);

        if !machine._check_inv_1() || !machine._check_inv_2() || !machine._check_inv_3() || !machine._check_inv_4() || !machine._check_inv_5() || !machine._check_inv_6() || !machine._check_inv_7() || !machine._check_inv_8() || !machine._check_inv_9() || !machine._check_inv_10() || !machine._check_inv_11() || !machine._check_inv_12() || !machine._check_inv_13() || !machine._check_inv_14() || !machine._check_inv_15() || !machine._check_inv_16() || !machine._check_inv_17() || !machine._check_inv_18() || !machine._check_inv_19() || !machine._check_inv_20() {
            invariant_violated.store(true, Ordering::Release);
        }

        let mut states = HashSet::<CAN_BUS_tlc>::new();
        states.insert(machine.clone());
        let number_states = AtomicI64::new(1);

        let collection_m = Arc::new(Mutex::new(LinkedList::<CAN_BUS_tlc>::new()));
        collection_m.lock().unwrap().push_back(machine.clone());

        let mut invariantDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut guardDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut dependent_invariant_m = Arc::new(Mutex::new(HashMap::<CAN_BUS_tlc, HashSet<&str>>::new()));
        let mut dependent_guard_m = Arc::new(Mutex::new(HashMap::<CAN_BUS_tlc, HashSet<&str>>::new()));
        let mut guard_cache = Arc::new(Mutex::new(HashMap::<CAN_BUS_tlc, PersistentHashMap<&'static str, bool>>::new()));
        let mut parents_m = Arc::new(Mutex::new(HashMap::<CAN_BUS_tlc, CAN_BUS_tlc>::new()));

        if is_caching {
            //model_check_init_static
            invariantDependency.insert("T1Wait", HashSet::from(["_check_inv_10", "_check_inv_4"]));
            //model_check_init_static
            invariantDependency.insert("T1Calculate", HashSet::from(["_check_inv_7", "_check_inv_4"]));
            //model_check_init_static
            invariantDependency.insert("T1SendResult", HashSet::from(["_check_inv_18", "_check_inv_19", "_check_inv_20", "_check_inv_4"]));
            //model_check_init_static
            invariantDependency.insert("T2ReadBus", HashSet::from(["_check_inv_17", "_check_inv_5", "_check_inv_9"]));
            //model_check_init_static
            invariantDependency.insert("T2Reset", HashSet::from(["_check_inv_1", "_check_inv_5", "_check_inv_8", "_check_inv_12"]));
            //model_check_init_static
            invariantDependency.insert("T2Complete", HashSet::from(["_check_inv_5", "_check_inv_12"]));
            //model_check_init_static
            invariantDependency.insert("T2Evaluate", HashSet::from(["_check_inv_5", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("T3Evaluate", HashSet::from(["_check_inv_6"]));
            //model_check_init_static
            invariantDependency.insert("T3ReleaseBus", HashSet::from(["_check_inv_18", "_check_inv_19", "_check_inv_6", "_check_inv_20"]));
            //model_check_init_static
            invariantDependency.insert("T1Evaluate", HashSet::from(["_check_inv_10", "_check_inv_4"]));
            //model_check_init_static
            invariantDependency.insert("T3Initiate", HashSet::from(["_check_inv_3", "_check_inv_6"]));
            //model_check_init_static
            invariantDependency.insert("T3ReEnableWait", HashSet::from(["_check_inv_2", "_check_inv_3", "_check_inv_6"]));
            //model_check_init_static
            invariantDependency.insert("T3writebus", HashSet::from(["_check_inv_18", "_check_inv_19", "_check_inv_6", "_check_inv_20"]));
            //model_check_init_static
            invariantDependency.insert("Update", HashSet::from(["_check_inv_2", "_check_inv_10", "_check_inv_14", "_check_inv_13", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("T2ReleaseBus", HashSet::from(["_check_inv_18", "_check_inv_19", "_check_inv_20", "_check_inv_5"]));
            //model_check_init_static
            invariantDependency.insert("T2Wait", HashSet::from(["_check_inv_5", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("T3Poll", HashSet::from(["_check_inv_6"]));
            //model_check_init_static
            invariantDependency.insert("T2Calculate", HashSet::from(["_check_inv_1", "_check_inv_5"]));
            //model_check_init_static
            invariantDependency.insert("T3Read", HashSet::from(["_check_inv_16", "_check_inv_15", "_check_inv_6"]));
            //model_check_init_static
            invariantDependency.insert("T3Wait", HashSet::from(["_check_inv_2", "_check_inv_6"]));
            //model_check_init_static
            invariantDependency.insert("T2WriteBus", HashSet::from(["_check_inv_18", "_check_inv_19", "_check_inv_20", "_check_inv_5"]));
            //model_check_init_static
            guardDependency.insert("T1Wait", HashSet::from(["_tr_T1Evaluate", "_tr_Update", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"]));
            //model_check_init_static
            guardDependency.insert("T1Calculate", HashSet::from(["_tr_T1Evaluate", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"]));
            //model_check_init_static
            guardDependency.insert("T1SendResult", HashSet::from(["_tr_T1Evaluate", "_tr_T2ReleaseBus", "_tr_Update", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"]));
            //model_check_init_static
            guardDependency.insert("T2ReadBus", HashSet::from(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
            //model_check_init_static
            guardDependency.insert("T2Reset", HashSet::from(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
            //model_check_init_static
            guardDependency.insert("T2Complete", HashSet::from(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
            //model_check_init_static
            guardDependency.insert("T2Evaluate", HashSet::from(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
            //model_check_init_static
            guardDependency.insert("T3Evaluate", HashSet::from(["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
            //model_check_init_static
            guardDependency.insert("T3ReleaseBus", HashSet::from(["_tr_T2ReleaseBus", "_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
            //model_check_init_static
            guardDependency.insert("T1Evaluate", HashSet::from(["_tr_T1Evaluate", "_tr_Update", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"]));
            //model_check_init_static
            guardDependency.insert("T3Initiate", HashSet::from(["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
            //model_check_init_static
            guardDependency.insert("T3ReEnableWait", HashSet::from(["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
            //model_check_init_static
            guardDependency.insert("T3writebus", HashSet::from(["_tr_T2ReleaseBus", "_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
            //model_check_init_static
            guardDependency.insert("Update", HashSet::from(["_tr_T1Evaluate", "_tr_T3Read", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T3Evaluate", "_tr_T3Initiate"]));
            //model_check_init_static
            guardDependency.insert("T2ReleaseBus", HashSet::from(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
            //model_check_init_static
            guardDependency.insert("T2Wait", HashSet::from(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
            //model_check_init_static
            guardDependency.insert("T3Poll", HashSet::from(["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
            //model_check_init_static
            guardDependency.insert("T2Calculate", HashSet::from(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
            //model_check_init_static
            guardDependency.insert("T3Read", HashSet::from(["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
            //model_check_init_static
            guardDependency.insert("T3Wait", HashSet::from(["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
            //model_check_init_static
            guardDependency.insert("T2WriteBus", HashSet::from(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
            dependent_invariant_m.lock().unwrap().insert(machine.clone(), HashSet::new());
            parents_m.lock().unwrap().remove(&machine);
        }

        let transitions = Arc::new(AtomicI64::new(0));

        while !stop_threads.load(Ordering::Acquire) && !collection_m.lock().unwrap().is_empty() {
            let mut state = Self::next(Arc::clone(&collection_m), mc_type);

            let next_states = Self::generateNextStates(&mut state, is_caching, &mut invariantDependency, Arc::clone(&dependent_invariant_m), &mut guardDependency, Arc::clone(&dependent_guard_m), Arc::clone(&guard_cache), Arc::clone(&parents_m), Arc::clone(&transitions));

            next_states.iter().for_each(|next_state| {
                if !states.contains(next_state) {
                    let cnum_states = number_states.fetch_add(1, Ordering::AcqRel) + 1;
                    states.insert(next_state.clone());
                    collection_m.lock().unwrap().push_back(next_state.clone());
                    if cnum_states % 50000 == 0 {
                        println!("VISITED STATES: {}", cnum_states);
                        println!("EVALUATED TRANSITIONS: {}", transitions.load(Ordering::Acquire));
                        println!("-------------------");
                    }
                }
            });

            if next_states.is_empty() {
                deadlock_detected.store(true, Ordering::Release);
                stop_threads.store(true, Ordering::Release);
            }

            if !Self::checkInvariants(&state, is_caching, Arc::clone(&dependent_invariant_m)) {
                invariant_violated.store(true, Ordering::Release);
                stop_threads.store(true, Ordering::Release);
            }

        }
        Self::print_result(number_states.load(Ordering::Acquire), transitions.load(Ordering::Acquire), deadlock_detected.load(Ordering::Acquire), invariant_violated.load(Ordering::Acquire));
    }

    fn modelCheckMultiThreaded(mc_type: MC_TYPE, threads: usize, is_caching: bool) {
        let threadPool = ThreadPool::new(threads);

        let machine = CAN_BUS_tlc::new();


        let invariant_violated_b = Arc::new(AtomicBool::new(false));
        let deadlock_detected_b = Arc::new(AtomicBool::new(false));
        let stop_threads_b = Arc::new(AtomicBool::new(false));
        let possible_queue_changes_b = Arc::new(AtomicI32::new(0));

        if !machine._check_inv_1() || !machine._check_inv_2() || !machine._check_inv_3() || !machine._check_inv_4() || !machine._check_inv_5() || !machine._check_inv_6() || !machine._check_inv_7() || !machine._check_inv_8() || !machine._check_inv_9() || !machine._check_inv_10() || !machine._check_inv_11() || !machine._check_inv_12() || !machine._check_inv_13() || !machine._check_inv_14() || !machine._check_inv_15() || !machine._check_inv_16() || !machine._check_inv_17() || !machine._check_inv_18() || !machine._check_inv_19() || !machine._check_inv_20() {
                invariant_violated_b.store(true, Ordering::Release);
        }

        let states_m = Arc::new(Mutex::new(HashSet::<CAN_BUS_tlc>::new()));
        states_m.lock().unwrap().insert(machine.clone());
        let number_states_arc = Arc::new(AtomicI64::new(1));

        let collection_m = Arc::new(Mutex::new(LinkedList::<CAN_BUS_tlc>::new()));
        collection_m.lock().unwrap().push_back(machine.clone());

        let mut invariantDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut guardDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut dependent_invariant_m = Arc::new(Mutex::new(HashMap::<CAN_BUS_tlc, HashSet<&str>>::new()));
        let mut dependent_guard_m = Arc::new(Mutex::new(HashMap::<CAN_BUS_tlc, HashSet<&str>>::new()));
        let mut guard_cache_b = Arc::new(Mutex::new(HashMap::<CAN_BUS_tlc, PersistentHashMap<&'static str, bool>>::new()));
        let mut parents_m = Arc::new(Mutex::new(HashMap::<CAN_BUS_tlc, CAN_BUS_tlc>::new()));

        if is_caching {
            //model_check_init_static
            invariantDependency.insert("T1Wait", HashSet::from(["_check_inv_10", "_check_inv_4"]));
            //model_check_init_static
            invariantDependency.insert("T1Calculate", HashSet::from(["_check_inv_7", "_check_inv_4"]));
            //model_check_init_static
            invariantDependency.insert("T1SendResult", HashSet::from(["_check_inv_18", "_check_inv_19", "_check_inv_20", "_check_inv_4"]));
            //model_check_init_static
            invariantDependency.insert("T2ReadBus", HashSet::from(["_check_inv_17", "_check_inv_5", "_check_inv_9"]));
            //model_check_init_static
            invariantDependency.insert("T2Reset", HashSet::from(["_check_inv_1", "_check_inv_5", "_check_inv_8", "_check_inv_12"]));
            //model_check_init_static
            invariantDependency.insert("T2Complete", HashSet::from(["_check_inv_5", "_check_inv_12"]));
            //model_check_init_static
            invariantDependency.insert("T2Evaluate", HashSet::from(["_check_inv_5", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("T3Evaluate", HashSet::from(["_check_inv_6"]));
            //model_check_init_static
            invariantDependency.insert("T3ReleaseBus", HashSet::from(["_check_inv_18", "_check_inv_19", "_check_inv_6", "_check_inv_20"]));
            //model_check_init_static
            invariantDependency.insert("T1Evaluate", HashSet::from(["_check_inv_10", "_check_inv_4"]));
            //model_check_init_static
            invariantDependency.insert("T3Initiate", HashSet::from(["_check_inv_3", "_check_inv_6"]));
            //model_check_init_static
            invariantDependency.insert("T3ReEnableWait", HashSet::from(["_check_inv_2", "_check_inv_3", "_check_inv_6"]));
            //model_check_init_static
            invariantDependency.insert("T3writebus", HashSet::from(["_check_inv_18", "_check_inv_19", "_check_inv_6", "_check_inv_20"]));
            //model_check_init_static
            invariantDependency.insert("Update", HashSet::from(["_check_inv_2", "_check_inv_10", "_check_inv_14", "_check_inv_13", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("T2ReleaseBus", HashSet::from(["_check_inv_18", "_check_inv_19", "_check_inv_20", "_check_inv_5"]));
            //model_check_init_static
            invariantDependency.insert("T2Wait", HashSet::from(["_check_inv_5", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("T3Poll", HashSet::from(["_check_inv_6"]));
            //model_check_init_static
            invariantDependency.insert("T2Calculate", HashSet::from(["_check_inv_1", "_check_inv_5"]));
            //model_check_init_static
            invariantDependency.insert("T3Read", HashSet::from(["_check_inv_16", "_check_inv_15", "_check_inv_6"]));
            //model_check_init_static
            invariantDependency.insert("T3Wait", HashSet::from(["_check_inv_2", "_check_inv_6"]));
            //model_check_init_static
            invariantDependency.insert("T2WriteBus", HashSet::from(["_check_inv_18", "_check_inv_19", "_check_inv_20", "_check_inv_5"]));
            //model_check_init_static
            guardDependency.insert("T1Wait", HashSet::from(["_tr_T1Evaluate", "_tr_Update", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"]));
            //model_check_init_static
            guardDependency.insert("T1Calculate", HashSet::from(["_tr_T1Evaluate", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"]));
            //model_check_init_static
            guardDependency.insert("T1SendResult", HashSet::from(["_tr_T1Evaluate", "_tr_T2ReleaseBus", "_tr_Update", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"]));
            //model_check_init_static
            guardDependency.insert("T2ReadBus", HashSet::from(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
            //model_check_init_static
            guardDependency.insert("T2Reset", HashSet::from(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
            //model_check_init_static
            guardDependency.insert("T2Complete", HashSet::from(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
            //model_check_init_static
            guardDependency.insert("T2Evaluate", HashSet::from(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
            //model_check_init_static
            guardDependency.insert("T3Evaluate", HashSet::from(["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
            //model_check_init_static
            guardDependency.insert("T3ReleaseBus", HashSet::from(["_tr_T2ReleaseBus", "_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
            //model_check_init_static
            guardDependency.insert("T1Evaluate", HashSet::from(["_tr_T1Evaluate", "_tr_Update", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"]));
            //model_check_init_static
            guardDependency.insert("T3Initiate", HashSet::from(["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
            //model_check_init_static
            guardDependency.insert("T3ReEnableWait", HashSet::from(["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
            //model_check_init_static
            guardDependency.insert("T3writebus", HashSet::from(["_tr_T2ReleaseBus", "_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
            //model_check_init_static
            guardDependency.insert("Update", HashSet::from(["_tr_T1Evaluate", "_tr_T3Read", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T3Evaluate", "_tr_T3Initiate"]));
            //model_check_init_static
            guardDependency.insert("T2ReleaseBus", HashSet::from(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
            //model_check_init_static
            guardDependency.insert("T2Wait", HashSet::from(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
            //model_check_init_static
            guardDependency.insert("T3Poll", HashSet::from(["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
            //model_check_init_static
            guardDependency.insert("T2Calculate", HashSet::from(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
            //model_check_init_static
            guardDependency.insert("T3Read", HashSet::from(["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
            //model_check_init_static
            guardDependency.insert("T3Wait", HashSet::from(["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
            //model_check_init_static
            guardDependency.insert("T2WriteBus", HashSet::from(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
            dependent_invariant_m.lock().unwrap().insert(machine.clone(), HashSet::new());
            parents_m.lock().unwrap().remove(&machine);
        }

        let num_transitions = Arc::new(AtomicI64::new(0));
        let invariant_dependency_arc = Arc::new(invariantDependency);
        let guard_dependency_arc = Arc::new(guardDependency);

        let (tx, rx) = channel();
        //println!("Thread {:?} starting threads", thread::current().id());
        while !stop_threads_b.load(Ordering::Acquire) && !collection_m.lock().unwrap().is_empty() {
            possible_queue_changes_b.fetch_add(1, Ordering::AcqRel);
            let mut state = Self::next(Arc::clone(&collection_m), mc_type);

            let invariant_violated = Arc::clone(&invariant_violated_b);
            let deadlock_detected = Arc::clone(&deadlock_detected_b);
            let stop_threads = Arc::clone(&stop_threads_b);
            let possible_queue_changes = Arc::clone(&possible_queue_changes_b);
            let collection_m2 = Arc::clone(&collection_m);
            let invariant_dependency = Arc::clone(&invariant_dependency_arc);
            let guard_dependency = Arc::clone(&guard_dependency_arc);
            let dependent_invariant_m2 = Arc::clone(&dependent_invariant_m);
            let dependent_guard_m2 = Arc::clone(&dependent_guard_m);
            let parents_m2 = Arc::clone(&parents_m);
            let guard_cache = Arc::clone(&guard_cache_b);
            let transitions = Arc::clone(&num_transitions);
            let states_m2 = Arc::clone(&states_m);
            let number_states = Arc::clone(&number_states_arc);
            let tx = tx.clone();
            //println!("Thread {:?} spawning a thread", thread::current().id());
            threadPool.execute(move|| {
                let next_states = Self::generateNextStates(&mut state, is_caching, &invariant_dependency, Arc::clone(&dependent_invariant_m2), &guard_dependency, dependent_guard_m2, guard_cache, parents_m2, Arc::clone(&transitions));

                //println!("Thread {:?} executing", thread::current().id());
                next_states.iter().for_each(|next_state| {
                    {
                        let mut states = states_m2.lock().unwrap();
                        let mut collection = collection_m2.lock().unwrap();
                        if !states.contains(next_state) {
                            let cnum_states = number_states.fetch_add(1, Ordering::AcqRel) + 1;
                            states.insert(next_state.clone());
                            collection.push_back(next_state.clone());
                            //println!("Thread {:?}: states in collection {}", thread::current().id(), collection.len());
                            if cnum_states % 50000 == 0 {
                                println!("VISITED STATES: {}", cnum_states);
                                println!("EVALUATED TRANSITIONS: {}", transitions.load(Ordering::Acquire));
                                println!("-------------------");
                            }
                        }
                    }
                });
                possible_queue_changes.fetch_sub(1, Ordering::AcqRel);

                if next_states.is_empty() {
                    deadlock_detected.store(true, Ordering::Release);
                    stop_threads.store(true, Ordering::Release);
                }

                if !Self::checkInvariants(&state, is_caching, Arc::clone(&dependent_invariant_m2)) {
                    invariant_violated.store(true, Ordering::Release);
                    stop_threads.store(true, Ordering::Release);
                }
                //println!("Thread {:?} done", thread::current().id());
                tx.send(1).expect("");
            });
            while collection_m.lock().unwrap().is_empty() && possible_queue_changes_b.load(Ordering::Acquire) > 0 {
                //println!("Thread {:?} (main) waiting for a thread to finish", thread::current().id());
                rx.recv().expect("Waiting for a thread to finish: ");
            }
        }

        Self::print_result(number_states_arc.load(Ordering::Acquire), num_transitions.load(Ordering::Acquire), deadlock_detected_b.load(Ordering::Acquire), invariant_violated_b.load(Ordering::Acquire));
    }

}


fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() != 4 { panic!("Number of arguments errorneous"); }

    let threads = args.get(2).unwrap().parse::<usize>().unwrap();
    if threads <= 0 { panic!("Input for number of threads is wrong."); }

    let is_caching = args.get(3).unwrap().parse::<bool>().unwrap();
    let mc_type = match args.get(1).unwrap().as_str() {
        "mixed" => MC_TYPE::MIXED,
        "bf" => MC_TYPE::BFS,
        "df" => MC_TYPE::DFS,
        _    => panic!("Input for strategy is wrong.")
    };

    if threads == 1 {
        CAN_BUS_tlc::model_check_single_threaded(mc_type, is_caching);
    } else {
        CAN_BUS_tlc::modelCheckMultiThreaded(mc_type, threads, is_caching);
    }
}
