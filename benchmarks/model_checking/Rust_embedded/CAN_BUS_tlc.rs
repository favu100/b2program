#![ allow( dead_code, unused, non_snake_case, non_camel_case_types, unused_assignments ) ]
//#![no_std] //std is enabled for the generated machine by default, since without it there is no println which makes unit-testing very difficult
use btypes::{bset, brel};
use btypes::bset::BSet;
use btypes::bset::SetItem;
use btypes::bset::PowSetItem;
use btypes::bset::PowAble;
use btypes::bset::NestedSet;
use btypes::brelation::BRelation;
use btypes::brelation::RelLeftItem;
use btypes::brelation::RelPowAble;
use btypes::bboolean::BBoolean;
use btypes::bboolean::BBool;
use btypes::bboolean::BOOL;
use btypes::binteger::BInteger;
use btypes::binteger::BInt;
use btypes::binteger::set_BInteger;
use btypes::btuple::BTuple;

use std::env;
use std::sync::atomic::{AtomicU64, Ordering};
use std::sync::{Arc, mpsc, Mutex};
use std::collections::{HashSet, LinkedList};
use dashmap::DashSet;
use threadpool::ThreadPool;
use std::sync::mpsc::channel;
use derivative::Derivative;
use std::time::{Duration};



#[derive(Clone, Copy)]
pub enum MC_TYPE { BFS, DFS, MIXED }


//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum T1state {
    #[default]
    T1_EN = 0, 
    T1_CALC = 1, 
    T1_SEND = 2, 
    T1_WAIT = 3
}

impl T1state {
    pub fn equal(&self, other: &T1state) -> bool { *self == *other }
    pub fn unequal(&self, other: &T1state) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::T1_EN, 
            1 => Self::T1_CALC, 
            2 => Self::T1_SEND, 
            3 => Self::T1_WAIT, 
            _ => panic!("T1state index out of range! {:?}", idx)
        }
    }
}

impl SetItem<4> for T1state {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_T1state = BSet<T1state, 4>;
//set_enum_declaration done

//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum T2mode {
    #[default]
    T2MODE_SENSE = 0, 
    T2MODE_TRANSMIT = 1, 
    T2MODE_RELEASE = 2
}

impl T2mode {
    pub fn equal(&self, other: &T2mode) -> bool { *self == *other }
    pub fn unequal(&self, other: &T2mode) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::T2MODE_SENSE, 
            1 => Self::T2MODE_TRANSMIT, 
            2 => Self::T2MODE_RELEASE, 
            _ => panic!("T2mode index out of range! {:?}", idx)
        }
    }
}

impl SetItem<3> for T2mode {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_T2mode = BSet<T2mode, 3>;
//set_enum_declaration done

//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum T2state {
    #[default]
    T2_EN = 0, 
    T2_RCV = 1, 
    T2_PROC = 2, 
    T2_CALC = 3, 
    T2_SEND = 4, 
    T2_WAIT = 5, 
    T2_RELEASE = 6
}

impl T2state {
    pub fn equal(&self, other: &T2state) -> bool { *self == *other }
    pub fn unequal(&self, other: &T2state) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::T2_EN, 
            1 => Self::T2_RCV, 
            2 => Self::T2_PROC, 
            3 => Self::T2_CALC, 
            4 => Self::T2_SEND, 
            5 => Self::T2_WAIT, 
            6 => Self::T2_RELEASE, 
            _ => panic!("T2state index out of range! {:?}", idx)
        }
    }
}

impl SetItem<7> for T2state {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_T2state = BSet<T2state, 7>;
//set_enum_declaration done

//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum T3state {
    #[default]
    T3_READY = 0, 
    T3_WRITE = 1, 
    T3_RELEASE = 2, 
    T3_READ = 3, 
    T3_PROC = 4, 
    T3_WAIT = 5
}

impl T3state {
    pub fn equal(&self, other: &T3state) -> bool { *self == *other }
    pub fn unequal(&self, other: &T3state) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::T3_READY, 
            1 => Self::T3_WRITE, 
            2 => Self::T3_RELEASE, 
            3 => Self::T3_READ, 
            4 => Self::T3_PROC, 
            5 => Self::T3_WAIT, 
            _ => panic!("T3state index out of range! {:?}", idx)
        }
    }
}

impl SetItem<6> for T3state {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_T3state = BSet<T3state, 6>;
//set_enum_declaration done

//relation_declaration
type rel_BInteger_X_BInteger = BRelation<BInteger, { BInteger::VARIANTS }, BInteger, { BInteger::VARIANTS }, 0>;
//relation_declaration done









#[derive(Derivative)]
#[derivative(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct CAN_BUS_tlc {
    /*declarations*/BUSpriority: BInteger,
    BUSvalue: BInteger,
    BUSwrite: rel_BInteger_X_BInteger,
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
    /*constant_declarations*/NATSET: set_BInteger,
    /*sets*//*set_declaration*/_T1state: set_T1state,
    /*set_declaration*/_T2mode: set_T2mode,
    /*set_declaration*/_T2state: set_T2state,
    /*set_declaration*/_T3state: set_T3state,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T1Evaluate: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T1Calculate: Option<HashSet<BInteger>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T1SendResult: Option<HashSet<(BInteger, BInteger)>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T1Wait: Option<HashSet<BInteger>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T2Evaluate: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T2ReadBus: Option<HashSet<(BInteger, BInteger)>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T2Reset: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T2Complete: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T2ReleaseBus: Option<HashSet<BInteger>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T2Calculate: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T2WriteBus: Option<HashSet<(BInteger, BInteger)>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T2Wait: Option<HashSet<BInteger>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T3Initiate: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T3Evaluate: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T3writebus: Option<HashSet<(BInteger, BInteger)>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T3Read: Option<HashSet<(BInteger, BInteger)>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T3Poll: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T3ReleaseBus: Option<HashSet<BInteger>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T3Wait: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_T3ReEnableWait: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_Update: Option<HashSet<BInteger>>,}


impl CAN_BUS_tlc {

    pub fn new() -> CAN_BUS_tlc {
        //values: ''
        let mut m: CAN_BUS_tlc = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        /*set_initializations*///set_initialization
    self._T1state = bset![T1state, /*enum_call*/T1state::T1_EN, /*enum_call*/T1state::T1_CALC, /*enum_call*/T1state::T1_SEND, /*enum_call*/T1state::T1_WAIT];
    //set_initialization
    self._T2mode = bset![T2mode, /*enum_call*/T2mode::T2MODE_SENSE, /*enum_call*/T2mode::T2MODE_TRANSMIT, /*enum_call*/T2mode::T2MODE_RELEASE];
    //set_initialization
    self._T2state = bset![T2state, /*enum_call*/T2state::T2_EN, /*enum_call*/T2state::T2_RCV, /*enum_call*/T2state::T2_PROC, /*enum_call*/T2state::T2_CALC, /*enum_call*/T2state::T2_SEND, /*enum_call*/T2state::T2_WAIT, /*enum_call*/T2state::T2_RELEASE];
    //set_initialization
    self._T3state = bset![T3state, /*enum_call*/T3state::T3_READY, /*enum_call*/T3state::T3_WRITE, /*enum_call*/T3state::T3_RELEASE, /*enum_call*/T3state::T3_READ, /*enum_call*/T3state::T3_PROC, /*enum_call*/T3state::T3_WAIT];
        /*properties*///constant_initialization
    self.NATSET = set_BInteger::interval(&0, &5);
        /*body*/self.T2v = 0;
    self.T3_evaluated = true;
    self.T3_enabled = true;
    self.T1_state = /*enum_call*/T1state::T1_EN;
    self.T2_state = /*enum_call*/T2state::T2_EN;
    self.T3_state = /*enum_call*/T3state::T3_READY;
    self.T1_writevalue = 0;
    self.T2_writevalue = 0;
    self.T2_readvalue = 0;
    self.T2_readpriority = 0;
    self.T3_readvalue = 0;
    self.T3_readpriority = 0;
    self.T1_timer = 2;
    self.T2_timer = 3;
    self.BUSwrite = brel![rel_BInteger_X_BInteger, (0.clone(), 0.clone())].clone().clone();
    self.BUSvalue = 0;
    self.BUSpriority = 0;
    self.T2_mode = /*enum_call*/T2mode::T2MODE_SENSE;
        /*includesInitialization*/
    }

    pub fn get_NATSET(&self) -> set_BInteger {
        return self.NATSET.clone();
    }

    pub fn get_BUSpriority(&self) -> BInteger {
        return self.BUSpriority.clone();
    }

    pub fn get_BUSvalue(&self) -> BInteger {
        return self.BUSvalue.clone();
    }

    pub fn get_BUSwrite(&self) -> rel_BInteger_X_BInteger {
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

    pub fn get__T1state(&self) -> set_T1state {
        return self._T1state.clone();
    }

    pub fn get__T2mode(&self) -> set_T2mode {
        return self._T2mode.clone();
    }

    pub fn get__T2state(&self) -> set_T2state {
        return self._T2state.clone();
    }

    pub fn get__T3state(&self) -> set_T3state {
        return self._T3state.clone();
    }

    pub fn T1Evaluate(&mut self) -> () {
        //pre_assert
        self.T1_timer = 0;
        self.T1_state = /*enum_call*/T1state::T1_CALC;

    }

    pub fn T1Calculate(&mut self, mut p: BInteger) -> () {
        //pre_assert
        self.T1_writevalue = p;
        self.T1_state = /*enum_call*/T1state::T1_SEND;

    }

    pub fn T1SendResult(&mut self, mut ppriority: BInteger, mut pv: BInteger) -> () {
        //pre_assert
        let mut _ld_BUSwrite = self.BUSwrite.clone();
        self.BUSwrite = _ld_BUSwrite._override(&brel![rel_BInteger_X_BInteger, (ppriority.clone(), pv.clone())]).clone().clone();
        self.T1_state = /*enum_call*/T1state::T1_WAIT;

    }

    pub fn T1Wait(&mut self, mut pt: BInteger) -> () {
        //pre_assert
        self.T1_timer = pt;
        self.T1_state = /*enum_call*/T1state::T1_EN;

    }

    pub fn T2Evaluate(&mut self) -> () {
        //pre_assert
        self.T2_timer = 0;
        self.T2_state = /*enum_call*/T2state::T2_RCV;

    }

    pub fn T2ReadBus(&mut self, mut ppriority: BInteger, mut pv: BInteger) -> () {
        //pre_assert
        self.T2_readvalue = pv;
        self.T2_readpriority = ppriority;
        self.T2_state = /*enum_call*/T2state::T2_PROC;

    }

    pub fn T2Reset(&mut self) -> () {
        //pre_assert
        let mut _ld_T2v = self.T2v.clone();
        self.T2_writevalue = _ld_T2v;
        self.T2v = 0;
        self.T2_state = /*enum_call*/T2state::T2_SEND;
        self.T2_mode = /*enum_call*/T2mode::T2MODE_TRANSMIT;

    }

    pub fn T2Complete(&mut self) -> () {
        //pre_assert
        self.T2_state = /*enum_call*/T2state::T2_RELEASE;
        self.T2_mode = /*enum_call*/T2mode::T2MODE_SENSE;

    }

    pub fn T2ReleaseBus(&mut self, mut ppriority: BInteger) -> () {
        //pre_assert
        let mut _ld_BUSwrite = self.BUSwrite.clone();
        self.BUSwrite = _ld_BUSwrite.domainSubstraction(&bset![BInteger, ppriority]).clone().clone();
        self.T2_state = /*enum_call*/T2state::T2_WAIT;

    }

    pub fn T2Calculate(&mut self) -> () {
        //pre_assert
        self.T2v = self.T2_readvalue;
        self.T2_state = /*enum_call*/T2state::T2_WAIT;

    }

    pub fn T2WriteBus(&mut self, mut ppriority: BInteger, mut pv: BInteger) -> () {
        //pre_assert
        let mut _ld_BUSwrite = self.BUSwrite.clone();
        self.BUSwrite = _ld_BUSwrite._override(&brel![rel_BInteger_X_BInteger, (ppriority.clone(), pv.clone())]).clone().clone();
        self.T2_state = /*enum_call*/T2state::T2_WAIT;

    }

    pub fn T2Wait(&mut self, mut pt: BInteger) -> () {
        //pre_assert
        self.T2_timer = pt;
        self.T2_state = /*enum_call*/T2state::T2_EN;

    }

    pub fn T3Initiate(&mut self) -> () {
        //pre_assert
        self.T3_state = /*enum_call*/T3state::T3_WRITE;
        self.T3_enabled = false;

    }

    pub fn T3Evaluate(&mut self) -> () {
        //pre_assert
        self.T3_state = /*enum_call*/T3state::T3_READ;

    }

    pub fn T3writebus(&mut self, mut ppriority: BInteger, mut pv: BInteger) -> () {
        //pre_assert
        let mut _ld_BUSwrite = self.BUSwrite.clone();
        self.BUSwrite = _ld_BUSwrite._override(&brel![rel_BInteger_X_BInteger, (ppriority.clone(), pv.clone())]).clone().clone();
        self.T3_state = /*enum_call*/T3state::T3_WAIT;

    }

    pub fn T3Read(&mut self, mut ppriority: BInteger, mut pv: BInteger) -> () {
        //pre_assert
        self.T3_readvalue = pv;
        self.T3_readpriority = ppriority;
        self.T3_state = /*enum_call*/T3state::T3_PROC;

    }

    pub fn T3Poll(&mut self) -> () {
        //pre_assert
        self.T3_state = /*enum_call*/T3state::T3_WAIT;

    }

    pub fn T3ReleaseBus(&mut self, mut ppriority: BInteger) -> () {
        //pre_assert
        let mut _ld_BUSwrite = self.BUSwrite.clone();
        self.BUSwrite = _ld_BUSwrite.domainSubstraction(&bset![BInteger, ppriority]).clone().clone();
        self.T3_state = /*enum_call*/T3state::T3_RELEASE;

    }

    pub fn T3Wait(&mut self) -> () {
        //pre_assert
        self.T3_state = /*enum_call*/T3state::T3_READY;
        self.T3_evaluated = true;

    }

    pub fn T3ReEnableWait(&mut self) -> () {
        //pre_assert
        self.T3_state = /*enum_call*/T3state::T3_READY;
        self.T3_evaluated = true;
        self.T3_enabled = true;

    }

    pub fn Update(&mut self, mut pmax: BInteger) -> () {
        //pre_assert
        let mut _ld_T1_timer = self.T1_timer.clone();
        let mut _ld_T2_timer = self.T2_timer.clone();
        self.BUSvalue = self.BUSwrite.functionCall(&pmax);
        self.BUSpriority = pmax;
        self.T1_timer = _ld_T1_timer.minus(&1);
        self.T2_timer = _ld_T2_timer.minus(&1);
        self.T3_evaluated = false;

    }

    pub fn _tr_T1Evaluate(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_T1Evaluate.is_none() {
            let mut __tmp__val__ = (self.T1_timer.equal(&0) && self.T1_state.equal(&/*enum_call*/T1state::T1_EN));
            self._tr_cache_T1Evaluate = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_T1Evaluate.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T1Calculate(&mut self, is_caching: bool) -> HashSet<BInteger> {
        //transition
        if !is_caching || self._tr_cache_T1Calculate.is_none() {
            let mut _ic_set_1: HashSet<BInteger> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_p_1 in set_BInteger::interval(&1.negative(), &3).clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if self.T1_state.equal(&/*enum_call*/T1state::T1_CALC) {
                    _ic_set_1.insert(_ic_p_1);
                }

            }
            self._tr_cache_T1Calculate = Option::Some(_ic_set_1.clone());
            return _ic_set_1;
        } else {
            return self._tr_cache_T1Calculate.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T1SendResult(&mut self, is_caching: bool) -> HashSet<(BInteger, BInteger)> {
        //transition
        if !is_caching || self._tr_cache_T1SendResult.is_none() {
            let mut _ic_set_2: HashSet<(BInteger, BInteger)> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_assignment
            {
                let mut _ic_ppriority_1 = 3;
                //iteration_construct_assignment
                {
                    let mut _ic_pv_1 = self.T1_writevalue;
                    //parameter_combination_predicate TODO: FASTER
                    if self.T1_state.equal(&/*enum_call*/T1state::T1_SEND) {
                        _ic_set_2.insert((_ic_ppriority_1.clone(), _ic_pv_1.clone()));
                    }

                }
            }
            self._tr_cache_T1SendResult = Option::Some(_ic_set_2.clone());
            return _ic_set_2;
        } else {
            return self._tr_cache_T1SendResult.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T1Wait(&mut self, is_caching: bool) -> HashSet<BInteger> {
        //transition
        if !is_caching || self._tr_cache_T1Wait.is_none() {
            let mut _ic_set_3: HashSet<BInteger> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_assignment
            {
                let mut _ic_pt_1 = 2;
                //parameter_combination_predicate TODO: FASTER
                if self.T1_state.equal(&/*enum_call*/T1state::T1_WAIT) {
                    _ic_set_3.insert(_ic_pt_1);
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
            let mut __tmp__val__ = (self.T2_timer.equal(&0) && self.T2_state.equal(&/*enum_call*/T2state::T2_EN));
            self._tr_cache_T2Evaluate = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_T2Evaluate.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T2ReadBus(&mut self, is_caching: bool) -> HashSet<(BInteger, BInteger)> {
        //transition
        if !is_caching || self._tr_cache_T2ReadBus.is_none() {
            let mut _ic_set_5: HashSet<(BInteger, BInteger)> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_assignment
            {
                let mut _ic_ppriority_1 = self.BUSpriority;
                //iteration_construct_assignment
                {
                    let mut _ic_pv_1 = self.BUSvalue;
                    //parameter_combination_predicate TODO: FASTER
                    if self.T2_state.equal(&/*enum_call*/T2state::T2_RCV) {
                        _ic_set_5.insert((_ic_ppriority_1.clone(), _ic_pv_1.clone()));
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
            let mut __tmp__val__ = (self.T2_readpriority.equal(&4) && self.T2_state.equal(&/*enum_call*/T2state::T2_PROC));
            self._tr_cache_T2Reset = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_T2Reset.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T2Complete(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_T2Complete.is_none() {
            let mut __tmp__val__ = ((self.T2_state.equal(&/*enum_call*/T2state::T2_PROC) && self.T2_readpriority.equal(&5)) && self.T2_mode.equal(&/*enum_call*/T2mode::T2MODE_TRANSMIT));
            self._tr_cache_T2Complete = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_T2Complete.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T2ReleaseBus(&mut self, is_caching: bool) -> HashSet<BInteger> {
        //transition
        if !is_caching || self._tr_cache_T2ReleaseBus.is_none() {
            let mut _ic_set_8: HashSet<BInteger> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_assignment
            {
                let mut _ic_ppriority_1 = self.T2_readpriority;
                //parameter_combination_predicate TODO: FASTER
                if (self.BUSwrite.domain().elementOf(&_ic_ppriority_1) && self.T2_state.equal(&/*enum_call*/T2state::T2_RELEASE)) {
                    _ic_set_8.insert(_ic_ppriority_1);
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
            let mut __tmp__val__ = (self.T2_readpriority.equal(&3) && self.T2_state.equal(&/*enum_call*/T2state::T2_PROC));
            self._tr_cache_T2Calculate = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_T2Calculate.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T2WriteBus(&mut self, is_caching: bool) -> HashSet<(BInteger, BInteger)> {
        //transition
        if !is_caching || self._tr_cache_T2WriteBus.is_none() {
            let mut _ic_set_10: HashSet<(BInteger, BInteger)> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_assignment
            {
                let mut _ic_ppriority_1 = 5;
                //iteration_construct_assignment
                {
                    let mut _ic_pv_1 = self.T2_writevalue;
                    //parameter_combination_predicate TODO: FASTER
                    if self.T2_state.equal(&/*enum_call*/T2state::T2_SEND) {
                        _ic_set_10.insert((_ic_ppriority_1.clone(), _ic_pv_1.clone()));
                    }

                }
            }
            self._tr_cache_T2WriteBus = Option::Some(_ic_set_10.clone());
            return _ic_set_10;
        } else {
            return self._tr_cache_T2WriteBus.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T2Wait(&mut self, is_caching: bool) -> HashSet<BInteger> {
        //transition
        if !is_caching || self._tr_cache_T2Wait.is_none() {
            let mut _ic_set_11: HashSet<BInteger> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_assignment
            {
                let mut _ic_pt_1 = 3;
                //parameter_combination_predicate TODO: FASTER
                if self.T2_state.equal(&/*enum_call*/T2state::T2_WAIT) {
                    _ic_set_11.insert(_ic_pt_1);
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
            let mut __tmp__val__ = ((self.T3_state.equal(&/*enum_call*/T3state::T3_READY) && self.T3_evaluated.equal(&false)) && self.T3_enabled.equal(&true));
            self._tr_cache_T3Initiate = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_T3Initiate.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T3Evaluate(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_T3Evaluate.is_none() {
            let mut __tmp__val__ = ((self.T3_state.equal(&/*enum_call*/T3state::T3_READY) && self.T3_evaluated.equal(&false)) && self.T3_enabled.equal(&false));
            self._tr_cache_T3Evaluate = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_T3Evaluate.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T3writebus(&mut self, is_caching: bool) -> HashSet<(BInteger, BInteger)> {
        //transition
        if !is_caching || self._tr_cache_T3writebus.is_none() {
            let mut _ic_set_14: HashSet<(BInteger, BInteger)> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_assignment
            {
                let mut _ic_ppriority_1 = 4;
                //iteration_construct_assignment
                {
                    let mut _ic_pv_1 = 0;
                    //parameter_combination_predicate TODO: FASTER
                    if self.T3_state.equal(&/*enum_call*/T3state::T3_WRITE) {
                        _ic_set_14.insert((_ic_ppriority_1.clone(), _ic_pv_1.clone()));
                    }

                }
            }
            self._tr_cache_T3writebus = Option::Some(_ic_set_14.clone());
            return _ic_set_14;
        } else {
            return self._tr_cache_T3writebus.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T3Read(&mut self, is_caching: bool) -> HashSet<(BInteger, BInteger)> {
        //transition
        if !is_caching || self._tr_cache_T3Read.is_none() {
            let mut _ic_set_15: HashSet<(BInteger, BInteger)> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_assignment
            {
                let mut _ic_ppriority_1 = self.BUSpriority;
                //iteration_construct_assignment
                {
                    let mut _ic_pv_1 = self.BUSvalue;
                    //parameter_combination_predicate TODO: FASTER
                    if self.T3_state.equal(&/*enum_call*/T3state::T3_READ) {
                        _ic_set_15.insert((_ic_ppriority_1.clone(), _ic_pv_1.clone()));
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
            let mut __tmp__val__ = (self.T3_readpriority.less(&5) && self.T3_state.equal(&/*enum_call*/T3state::T3_PROC));
            self._tr_cache_T3Poll = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_T3Poll.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T3ReleaseBus(&mut self, is_caching: bool) -> HashSet<BInteger> {
        //transition
        if !is_caching || self._tr_cache_T3ReleaseBus.is_none() {
            let mut _ic_set_17: HashSet<BInteger> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_assignment
            {
                let mut _ic_ppriority_1 = 4;
                //parameter_combination_predicate TODO: FASTER
                if (self.T3_readpriority.equal(&5) && self.T3_state.equal(&/*enum_call*/T3state::T3_PROC)) {
                    _ic_set_17.insert(_ic_ppriority_1);
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
            let mut __tmp__val__ = self.T3_state.equal(&/*enum_call*/T3state::T3_WAIT);
            self._tr_cache_T3Wait = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_T3Wait.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_T3ReEnableWait(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_T3ReEnableWait.is_none() {
            let mut __tmp__val__ = self.T3_state.equal(&/*enum_call*/T3state::T3_RELEASE);
            self._tr_cache_T3ReEnableWait = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_T3ReEnableWait.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_Update(&mut self, is_caching: bool) -> HashSet<BInteger> {
        //transition
        if !is_caching || self._tr_cache_Update.is_none() {
            let mut _ic_set_20: HashSet<BInteger> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_assignment
            {
                let mut _ic_pmax_1 = self.BUSwrite.domain()._max();
                //parameter_combination_predicate TODO: FASTER
                if ((self.T1_timer.greater(&0) && self.T2_timer.greater(&0)) && (self.T3_enabled.equal(&true) || self.T3_evaluated.equal(&true))) {
                    _ic_set_20.insert(_ic_pmax_1);
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
        return self.T2v.isInteger();
    }

    pub fn _check_inv_2(&self) -> bool {
        //invariant
        return BOOL.elementOf(&self.T3_evaluated);
    }

    pub fn _check_inv_3(&self) -> bool {
        //invariant
        return BOOL.elementOf(&self.T3_enabled);
    }

    pub fn _check_inv_4(&self) -> bool {
        //invariant
        return self._T1state.elementOf(&self.T1_state);
    }

    pub fn _check_inv_5(&self) -> bool {
        //invariant
        return self._T2state.elementOf(&self.T2_state);
    }

    pub fn _check_inv_6(&self) -> bool {
        //invariant
        return self._T3state.elementOf(&self.T3_state);
    }

    pub fn _check_inv_7(&self) -> bool {
        //invariant
        return self.T1_writevalue.isInteger();
    }

    pub fn _check_inv_8(&self) -> bool {
        //invariant
        return self.T2_writevalue.isInteger();
    }

    pub fn _check_inv_9(&self) -> bool {
        //invariant
        return self.T2_readvalue.isInteger();
    }

    pub fn _check_inv_10(&self) -> bool {
        //invariant
        return self.T1_timer.isNatural();
    }

    pub fn _check_inv_11(&self) -> bool {
        //invariant
        return self.T2_timer.isNatural();
    }

    pub fn _check_inv_12(&self) -> bool {
        //invariant
        return self._T2mode.elementOf(&self.T2_mode);
    }

    pub fn _check_inv_13(&self) -> bool {
        //invariant
        return self.BUSvalue.isInteger();
    }

    pub fn _check_inv_14(&self) -> bool {
        //invariant
        return self.NATSET.elementOf(&self.BUSpriority);
    }

    pub fn _check_inv_15(&self) -> bool {
        //invariant
        return self.T3_readvalue.isInteger();
    }

    pub fn _check_inv_16(&self) -> bool {
        //invariant
        return self.NATSET.elementOf(&self.T3_readpriority);
    }

    pub fn _check_inv_17(&self) -> bool {
        //invariant
        return self.NATSET.elementOf(&self.T2_readpriority);
    }

    pub fn _check_inv_18(&self) -> bool {
        //invariant
        return self.NATSET.check_domain_of(&self.BUSwrite).and(&self.BUSwrite.checkRangeInteger()).and(&self.BUSwrite.isFunction()).and(&self.NATSET.check_partial_of(&self.BUSwrite));
    }

    pub fn _check_inv_19(&self) -> bool {
        //invariant
        return self.BUSwrite.unequal(&brel![rel_BInteger_X_BInteger]);
    }

    pub fn _check_inv_20(&self) -> bool {
        //invariant
        return self.BUSwrite.domain().elementOf(&0);
    }

    fn invalidate_caches(&mut self, to_invalidate: Vec<&'static str>) {
        //calling the given functions without caching will recalculate them and cache them afterwards
        for trans in to_invalidate {
            match trans {
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
                          transitions: Arc<AtomicU64>) -> HashSet<(CAN_BUS_tlc, &'static str)> {
        let mut result = HashSet::<(CAN_BUS_tlc, &'static str)>::new();
        let mut evaluated_transitions: u64 = 0;
        //model_check_transition
        if state._tr_T1Evaluate(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.T1Evaluate();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("T1Evaluate")); }
            result.insert((copiedState, "T1Evaluate"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_2 = state._tr_T1Calculate(isCaching);
        for param in _trid_2.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.T1Calculate(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("T1Calculate")); }
            result.insert((copiedState, "T1Calculate"));
            evaluated_transitions += 1;
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
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("T1SendResult")); }
            result.insert((copiedState, "T1SendResult"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_4 = state._tr_T1Wait(isCaching);
        for param in _trid_4.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.T1Wait(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("T1Wait")); }
            result.insert((copiedState, "T1Wait"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_T2Evaluate(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.T2Evaluate();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("T2Evaluate")); }
            result.insert((copiedState, "T2Evaluate"));
            evaluated_transitions += 1;
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
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("T2ReadBus")); }
            result.insert((copiedState, "T2ReadBus"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_T2Reset(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.T2Reset();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("T2Reset")); }
            result.insert((copiedState, "T2Reset"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_T2Complete(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.T2Complete();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("T2Complete")); }
            result.insert((copiedState, "T2Complete"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_9 = state._tr_T2ReleaseBus(isCaching);
        for param in _trid_9.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.T2ReleaseBus(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("T2ReleaseBus")); }
            result.insert((copiedState, "T2ReleaseBus"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_T2Calculate(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.T2Calculate();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("T2Calculate")); }
            result.insert((copiedState, "T2Calculate"));
            evaluated_transitions += 1;
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
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("T2WriteBus")); }
            result.insert((copiedState, "T2WriteBus"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_12 = state._tr_T2Wait(isCaching);
        for param in _trid_12.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.T2Wait(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("T2Wait")); }
            result.insert((copiedState, "T2Wait"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_T3Initiate(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.T3Initiate();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("T3Initiate")); }
            result.insert((copiedState, "T3Initiate"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_T3Evaluate(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.T3Evaluate();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("T3Evaluate")); }
            result.insert((copiedState, "T3Evaluate"));
            evaluated_transitions += 1;
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
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("T3writebus")); }
            result.insert((copiedState, "T3writebus"));
            evaluated_transitions += 1;
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
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("T3Read")); }
            result.insert((copiedState, "T3Read"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_T3Poll(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.T3Poll();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("T3Poll")); }
            result.insert((copiedState, "T3Poll"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_18 = state._tr_T3ReleaseBus(isCaching);
        for param in _trid_18.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.T3ReleaseBus(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("T3ReleaseBus")); }
            result.insert((copiedState, "T3ReleaseBus"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_T3Wait(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.T3Wait();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("T3Wait")); }
            result.insert((copiedState, "T3Wait"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_T3ReEnableWait(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.T3ReEnableWait();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("T3ReEnableWait")); }
            result.insert((copiedState, "T3ReEnableWait"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_21 = state._tr_Update(isCaching);
        for param in _trid_21.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.Update(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("Update")); }
            result.insert((copiedState, "Update"));
            evaluated_transitions += 1;
        }


        transitions.fetch_add(evaluated_transitions, Ordering::AcqRel);
        return result;
    }

    //model_check_invariants
    pub fn checkInvariants(state: &CAN_BUS_tlc, last_op: &'static str, isCaching: bool) -> bool {
        if isCaching {
            let dependent_invariants_of_state = Self::get_invariant_dependencies(last_op);
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_1") {
                if !state._check_inv_1() {
                    println!("_check_inv_1 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_2") {
                if !state._check_inv_2() {
                    println!("_check_inv_2 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_3") {
                if !state._check_inv_3() {
                    println!("_check_inv_3 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_4") {
                if !state._check_inv_4() {
                    println!("_check_inv_4 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_5") {
                if !state._check_inv_5() {
                    println!("_check_inv_5 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_6") {
                if !state._check_inv_6() {
                    println!("_check_inv_6 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_7") {
                if !state._check_inv_7() {
                    println!("_check_inv_7 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_8") {
                if !state._check_inv_8() {
                    println!("_check_inv_8 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_9") {
                if !state._check_inv_9() {
                    println!("_check_inv_9 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_10") {
                if !state._check_inv_10() {
                    println!("_check_inv_10 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_11") {
                if !state._check_inv_11() {
                    println!("_check_inv_11 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_12") {
                if !state._check_inv_12() {
                    println!("_check_inv_12 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_13") {
                if !state._check_inv_13() {
                    println!("_check_inv_13 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_14") {
                if !state._check_inv_14() {
                    println!("_check_inv_14 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_15") {
                if !state._check_inv_15() {
                    println!("_check_inv_15 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_16") {
                if !state._check_inv_16() {
                    println!("_check_inv_16 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_17") {
                if !state._check_inv_17() {
                    println!("_check_inv_17 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_18") {
                if !state._check_inv_18() {
                    println!("_check_inv_18 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_19") {
                if !state._check_inv_19() {
                    println!("_check_inv_19 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_20") {
                if !state._check_inv_20() {
                    println!("_check_inv_20 failed!");
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6() || !state._check_inv_7() || !state._check_inv_8() || !state._check_inv_9() || !state._check_inv_10() || !state._check_inv_11() || !state._check_inv_12() || !state._check_inv_13() || !state._check_inv_14() || !state._check_inv_15() || !state._check_inv_16() || !state._check_inv_17() || !state._check_inv_18() || !state._check_inv_19() || !state._check_inv_20());
    }

    //model_check_print
    fn print_result(states: usize, transitions: u64, error_detected: bool) {
        if !error_detected { println!("MODEL CHECKING SUCCESSFUL"); }
        println!("Number of States: {}", states);
        println!("Number of Transitions: {}", transitions);
    }

    //model_check_main
    fn next(collection_m: Arc<Mutex<LinkedList<(CAN_BUS_tlc, &'static str)>>>, mc_type: MC_TYPE) -> (CAN_BUS_tlc, &'static str) {
        let mut collection = collection_m.lock().unwrap();
        return match mc_type {
            MC_TYPE::BFS   => collection.pop_front().unwrap(),
            MC_TYPE::DFS   => collection.pop_back().unwrap(),
            MC_TYPE::MIXED => if collection.len() % 2 == 0 { collection.pop_front().unwrap() } else { collection.pop_back().unwrap() }
        };
    }

    fn get_guard_dependencies(op: &'static str) -> Vec<&str> {
        return match op {
            //model_check_init_static
            "T1Wait" => vec!["_tr_T1Evaluate", "_tr_Update", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"],
            //model_check_init_static
            "T1Calculate" => vec!["_tr_T1Evaluate", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"],
            //model_check_init_static
            "T1SendResult" => vec!["_tr_T1Evaluate", "_tr_T2ReleaseBus", "_tr_Update", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"],
            //model_check_init_static
            "T2ReadBus" => vec!["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"],
            //model_check_init_static
            "T2Reset" => vec!["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"],
            //model_check_init_static
            "T2Complete" => vec!["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"],
            //model_check_init_static
            "T2Evaluate" => vec!["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"],
            //model_check_init_static
            "T3Evaluate" => vec!["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"],
            //model_check_init_static
            "T3ReleaseBus" => vec!["_tr_T2ReleaseBus", "_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"],
            //model_check_init_static
            "T1Evaluate" => vec!["_tr_T1Evaluate", "_tr_Update", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"],
            //model_check_init_static
            "T3Initiate" => vec!["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"],
            //model_check_init_static
            "T3ReEnableWait" => vec!["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"],
            //model_check_init_static
            "T3writebus" => vec!["_tr_T2ReleaseBus", "_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"],
            //model_check_init_static
            "Update" => vec!["_tr_T1Evaluate", "_tr_T3Read", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T3Evaluate", "_tr_T3Initiate"],
            //model_check_init_static
            "T2ReleaseBus" => vec!["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"],
            //model_check_init_static
            "T2Wait" => vec!["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"],
            //model_check_init_static
            "T3Poll" => vec!["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"],
            //model_check_init_static
            "T2Calculate" => vec!["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"],
            //model_check_init_static
            "T3Read" => vec!["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"],
            //model_check_init_static
            "T3Wait" => vec!["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"],
            //model_check_init_static
            "T2WriteBus" => vec!["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"],
            _ => vec![],
        }
    }

    fn get_invariant_dependencies(op: &'static str) -> Vec<&str> {
        return match op {
            //model_check_init_static
            "T1Wait" => vec!["_check_inv_10", "_check_inv_4"],
            //model_check_init_static
            "T1Calculate" => vec!["_check_inv_7", "_check_inv_4"],
            //model_check_init_static
            "T1SendResult" => vec!["_check_inv_18", "_check_inv_19", "_check_inv_20", "_check_inv_4"],
            //model_check_init_static
            "T2ReadBus" => vec!["_check_inv_17", "_check_inv_5", "_check_inv_9"],
            //model_check_init_static
            "T2Reset" => vec!["_check_inv_1", "_check_inv_5", "_check_inv_8", "_check_inv_12"],
            //model_check_init_static
            "T2Complete" => vec!["_check_inv_5", "_check_inv_12"],
            //model_check_init_static
            "T2Evaluate" => vec!["_check_inv_5", "_check_inv_11"],
            //model_check_init_static
            "T3Evaluate" => vec!["_check_inv_6"],
            //model_check_init_static
            "T3ReleaseBus" => vec!["_check_inv_18", "_check_inv_19", "_check_inv_6", "_check_inv_20"],
            //model_check_init_static
            "T1Evaluate" => vec!["_check_inv_10", "_check_inv_4"],
            //model_check_init_static
            "T3Initiate" => vec!["_check_inv_3", "_check_inv_6"],
            //model_check_init_static
            "T3ReEnableWait" => vec!["_check_inv_2", "_check_inv_3", "_check_inv_6"],
            //model_check_init_static
            "T3writebus" => vec!["_check_inv_18", "_check_inv_19", "_check_inv_6", "_check_inv_20"],
            //model_check_init_static
            "Update" => vec!["_check_inv_2", "_check_inv_10", "_check_inv_14", "_check_inv_13", "_check_inv_11"],
            //model_check_init_static
            "T2ReleaseBus" => vec!["_check_inv_18", "_check_inv_19", "_check_inv_20", "_check_inv_5"],
            //model_check_init_static
            "T2Wait" => vec!["_check_inv_5", "_check_inv_11"],
            //model_check_init_static
            "T3Poll" => vec!["_check_inv_6"],
            //model_check_init_static
            "T2Calculate" => vec!["_check_inv_1", "_check_inv_5"],
            //model_check_init_static
            "T3Read" => vec!["_check_inv_16", "_check_inv_15", "_check_inv_6"],
            //model_check_init_static
            "T3Wait" => vec!["_check_inv_2", "_check_inv_6"],
            //model_check_init_static
            "T2WriteBus" => vec!["_check_inv_18", "_check_inv_19", "_check_inv_20", "_check_inv_5"],
            _ => vec![],
        }
    }

    fn model_check_single_threaded(mc_type: MC_TYPE, is_caching: bool, no_dead: bool, no_inv: bool) {
        let mut machine = CAN_BUS_tlc::new();

        let mut all_states = HashSet::<CAN_BUS_tlc>::new();
        all_states.insert(machine.clone());

        let states_to_process_mutex = Arc::new(Mutex::new(LinkedList::<(CAN_BUS_tlc, &'static str)>::new()));
        states_to_process_mutex.lock().unwrap().push_back((machine.clone(), ""));

        let num_transitions = Arc::new(AtomicU64::new(0));

        let mut stop_threads = false;

        while !stop_threads && !states_to_process_mutex.lock().unwrap().is_empty() {
            let (mut state, last_op) = Self::next(Arc::clone(&states_to_process_mutex), mc_type);

            let next_states = Self::generateNextStates(&mut state, is_caching, Arc::clone(&num_transitions));

            if !no_inv && !Self::checkInvariants(&state, last_op, is_caching) {
                println!("INVARIANT VIOLATED");
                stop_threads = true;
            }
            if !no_dead && next_states.is_empty() {
                print!("DEADLOCK DETECTED");
                stop_threads = true;
            }

            next_states.into_iter()
                       .filter(|(next_state, _)| all_states.insert((*next_state).clone()))
                       .for_each(|(next_state, last_op)| states_to_process_mutex.lock().unwrap().push_back((next_state, last_op)));

            if all_states.len() % 50000 == 0 {
                println!("VISITED STATES: {}", all_states.len());
                println!("EVALUATED TRANSITIONS: {}", num_transitions.load(Ordering::Acquire));
                println!("-------------------");
            }
        }
        Self::print_result(all_states.len(), num_transitions.load(Ordering::Acquire), stop_threads);
    }

    fn modelCheckMultiThreaded(mc_type: MC_TYPE, threads: usize, is_caching: bool, no_dead: bool, no_inv: bool) {
        let threadPool = ThreadPool::new(threads);

        let machine = CAN_BUS_tlc::new();

        let all_states = Arc::new(DashSet::<CAN_BUS_tlc>::new());
        all_states.insert(machine.clone());

        let states_to_process_mutex = Arc::new(Mutex::new(LinkedList::<(CAN_BUS_tlc, &'static str)>::new()));
        states_to_process_mutex.lock().unwrap().push_back((machine, ""));

        let num_transitions = Arc::new(AtomicU64::new(0));

        let mut stop_threads = false;
        let mut spawned_tasks: u64 = 0;
        let mut finished_tasks: u64 = 0;

        let (tx, rx) = channel();
        //println!("Thread {:?} starting threads", thread::current().id());
        while !stop_threads && !states_to_process_mutex.lock().unwrap().is_empty() {
            let (mut state, last_op) = Self::next(Arc::clone(&states_to_process_mutex), mc_type);

            let states_to_process = Arc::clone(&states_to_process_mutex);
            let transitions = Arc::clone(&num_transitions);
            let states = Arc::clone(&all_states);
            let tx = tx.clone();
            //println!("Thread {:?} spawning a thread", thread::current().id());
            threadPool.execute(move|| {
                let next_states = Self::generateNextStates(&mut state, is_caching, transitions);
                if !no_dead && next_states.is_empty() { let _ = tx.send(Err("DEADLOCK DETECTED")); }

                //println!("Thread {:?} executing", thread::current().id());
                next_states.into_iter()
                           .filter(|(next_state, _)| states.insert((*next_state).clone()))
                           .for_each(|(next_state, last_op)| states_to_process.lock().unwrap().push_back((next_state, last_op)));

                if !no_inv && !Self::checkInvariants(&state, last_op, is_caching) {
                    let _ = tx.send(Err("INVARIANT VIOLATED"));
                }
                //println!("Thread {:?} done", thread::current().id());
                let _ = tx.send(Ok(1));
            });

            spawned_tasks += 1;
            if spawned_tasks % 50000 == 0 {
                println!("VISITED STATES: {}", all_states.len());
                println!("EVALUATED TRANSITIONS: {}", num_transitions.load(Ordering::Acquire));
                println!("-------------------");
            }

            while states_to_process_mutex.lock().unwrap().is_empty() && spawned_tasks - finished_tasks > 0 {
                //println!("Thread {:?} (main) waiting for a thread to finish", thread::current().id());
                match rx.try_recv() {
                    Ok(val)  => match val {
                            Ok(_) => finished_tasks += 1,
                            Err(msg) => { println!("{}", msg); stop_threads = true; },
                        },
                    Err(_) => (),
                }
                if threadPool.panic_count() > 0 { stop_threads = true; }
            }
        }

        Self::print_result(all_states.len(), num_transitions.load(Ordering::Acquire), stop_threads);
    }

}


fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() < 4 { panic!("Number of arguments errorneous"); }

    let threads = args.get(2).unwrap().parse::<usize>().unwrap();
    if threads <= 0 { panic!("Input for number of threads is wrong."); }

    let is_caching = args.get(3).unwrap().parse::<bool>().unwrap();
    let mc_type = match args.get(1).unwrap().as_str() {
        "mixed" => MC_TYPE::MIXED,
        "bf" => MC_TYPE::BFS,
        "df" => MC_TYPE::DFS,
        _    => panic!("Input for strategy is wrong.")
    };

    let mut no_dead = false;
    let mut no_inv = false;

    if args.len() > 4 {
        for arg in args.iter().skip(4) {
            match arg.as_str() {
                "-nodead" => no_dead = true,
                "-noinv" => no_inv = true,
                _ => {}
            }
        }
    }

    if threads == 1 {
        CAN_BUS_tlc::model_check_single_threaded(mc_type, is_caching, no_dead, no_inv);
    } else {
        CAN_BUS_tlc::modelCheckMultiThreaded(mc_type, threads, is_caching, no_dead, no_inv);
    }
}
