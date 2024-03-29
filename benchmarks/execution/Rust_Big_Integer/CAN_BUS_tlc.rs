#![ allow( dead_code, unused_imports, unused_mut, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::bboolean::BBoolean;
use btypes::binteger::BInteger;
use btypes::brelation::BRelation;
use btypes::bset::BSet;
use btypes::bobject::BObject;
use btypes::btuple::BTuple;


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

#[derive(Default, Debug)]
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
}

impl CAN_BUS_tlc {

    pub fn new() -> CAN_BUS_tlc {
        //values: ''
        let mut m: CAN_BUS_tlc = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.NATSET = BSet::<BInteger>::interval(&BInteger::new(b"0"), &BInteger::new(b"5"));
        self._T1state = BSet::new(vec![T1state::T1_EN, T1state::T1_CALC, T1state::T1_SEND, T1state::T1_WAIT]);
        self._T2mode = BSet::new(vec![T2mode::T2MODE_SENSE, T2mode::T2MODE_TRANSMIT, T2mode::T2MODE_RELEASE]);
        self._T2state = BSet::new(vec![T2state::T2_EN, T2state::T2_RCV, T2state::T2_PROC, T2state::T2_CALC, T2state::T2_SEND, T2state::T2_WAIT, T2state::T2_RELEASE]);
        self._T3state = BSet::new(vec![T3state::T3_READY, T3state::T3_WRITE, T3state::T3_RELEASE, T3state::T3_READ, T3state::T3_PROC, T3state::T3_WAIT]);
        self.T2v = BInteger::new(b"0").clone();
        self.T3_evaluated = BBoolean::new(true).clone();
        self.T3_enabled = BBoolean::new(true).clone();
        self.T1_state = T1state::T1_EN.clone();
        self.T2_state = T2state::T2_EN.clone();
        self.T3_state = T3state::T3_READY.clone();
        self.T1_writevalue = BInteger::new(b"0").clone();
        self.T2_writevalue = BInteger::new(b"0").clone();
        self.T2_readvalue = BInteger::new(b"0").clone();
        self.T2_readpriority = BInteger::new(b"0").clone();
        self.T3_readvalue = BInteger::new(b"0").clone();
        self.T3_readpriority = BInteger::new(b"0").clone();
        self.T1_timer = BInteger::new(b"2").clone();
        self.T2_timer = BInteger::new(b"3").clone();
        self.BUSwrite = BRelation::new(vec![BTuple::from_refs(&BInteger::new(b"0"), &BInteger::new(b"0"))]).clone().clone();
        self.BUSvalue = BInteger::new(b"0").clone();
        self.BUSpriority = BInteger::new(b"0").clone();
        self.T2_mode = T2mode::T2MODE_SENSE.clone();
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
        self.T1_timer = BInteger::new(b"0").clone();
        self.T1_state = T1state::T1_CALC.clone();
    }

    pub fn T1Calculate(&mut self, mut p: BInteger) -> () {
        self.T1_writevalue = p.clone();
        self.T1_state = T1state::T1_SEND.clone();
    }

    pub fn T1SendResult(&mut self, mut ppriority: BInteger, mut pv: BInteger) -> () {
        let mut _ld_BUSwrite = self.BUSwrite.clone();
        self.BUSwrite = _ld_BUSwrite._override(&BRelation::new(vec![BTuple::from_refs(&ppriority, &pv)])).clone().clone();
        self.T1_state = T1state::T1_WAIT.clone();
    }

    pub fn T1Wait(&mut self, mut pt: BInteger) -> () {
        self.T1_timer = pt.clone();
        self.T1_state = T1state::T1_EN.clone();
    }

    pub fn T2Evaluate(&mut self) -> () {
        self.T2_timer = BInteger::new(b"0").clone();
        self.T2_state = T2state::T2_RCV.clone();
    }

    pub fn T2ReadBus(&mut self, mut ppriority: BInteger, mut pv: BInteger) -> () {
        self.T2_readvalue = pv.clone();
        self.T2_readpriority = ppriority.clone();
        self.T2_state = T2state::T2_PROC.clone();
    }

    pub fn T2Reset(&mut self) -> () {
        let mut _ld_T2v = self.T2v.clone();
        self.T2_writevalue = _ld_T2v.clone();
        self.T2v = BInteger::new(b"0").clone();
        self.T2_state = T2state::T2_SEND.clone();
        self.T2_mode = T2mode::T2MODE_TRANSMIT.clone();
    }

    pub fn T2Complete(&mut self) -> () {
        self.T2_state = T2state::T2_RELEASE.clone();
        self.T2_mode = T2mode::T2MODE_SENSE.clone();
    }

    pub fn T2ReleaseBus(&mut self, mut ppriority: BInteger) -> () {
        let mut _ld_BUSwrite = self.BUSwrite.clone();
        self.BUSwrite = _ld_BUSwrite.domainSubstraction(&BSet::new(vec![ppriority])).clone().clone();
        self.T2_state = T2state::T2_WAIT.clone();
    }

    pub fn T2Calculate(&mut self) -> () {
        self.T2v = self.T2_readvalue.clone();
        self.T2_state = T2state::T2_WAIT.clone();
    }

    pub fn T2WriteBus(&mut self, mut ppriority: BInteger, mut pv: BInteger) -> () {
        let mut _ld_BUSwrite = self.BUSwrite.clone();
        self.BUSwrite = _ld_BUSwrite._override(&BRelation::new(vec![BTuple::from_refs(&ppriority, &pv)])).clone().clone();
        self.T2_state = T2state::T2_WAIT.clone();
    }

    pub fn T2Wait(&mut self, mut pt: BInteger) -> () {
        self.T2_timer = pt.clone();
        self.T2_state = T2state::T2_EN.clone();
    }

    pub fn T3Initiate(&mut self) -> () {
        self.T3_state = T3state::T3_WRITE.clone();
        self.T3_enabled = BBoolean::new(false).clone();
    }

    pub fn T3Evaluate(&mut self) -> () {
        self.T3_state = T3state::T3_READ.clone();
    }

    pub fn T3writebus(&mut self, mut ppriority: BInteger, mut pv: BInteger) -> () {
        let mut _ld_BUSwrite = self.BUSwrite.clone();
        self.BUSwrite = _ld_BUSwrite._override(&BRelation::new(vec![BTuple::from_refs(&ppriority, &pv)])).clone().clone();
        self.T3_state = T3state::T3_WAIT.clone();
    }

    pub fn T3Read(&mut self, mut ppriority: BInteger, mut pv: BInteger) -> () {
        self.T3_readvalue = pv.clone();
        self.T3_readpriority = ppriority.clone();
        self.T3_state = T3state::T3_PROC.clone();
    }

    pub fn T3Poll(&mut self) -> () {
        self.T3_state = T3state::T3_WAIT.clone();
    }

    pub fn T3ReleaseBus(&mut self, mut ppriority: BInteger) -> () {
        let mut _ld_BUSwrite = self.BUSwrite.clone();
        self.BUSwrite = _ld_BUSwrite.domainSubstraction(&BSet::new(vec![ppriority])).clone().clone();
        self.T3_state = T3state::T3_RELEASE.clone();
    }

    pub fn T3Wait(&mut self) -> () {
        self.T3_state = T3state::T3_READY.clone();
        self.T3_evaluated = BBoolean::new(true).clone();
    }

    pub fn T3ReEnableWait(&mut self) -> () {
        self.T3_state = T3state::T3_READY.clone();
        self.T3_evaluated = BBoolean::new(true).clone();
        self.T3_enabled = BBoolean::new(true).clone();
    }

    pub fn Update(&mut self, mut pmax: BInteger) -> () {
        let mut _ld_T1_timer = self.T1_timer.clone();
        let mut _ld_T2_timer = self.T2_timer.clone();
        self.BUSvalue = self.BUSwrite.functionCall(&pmax).clone();
        self.BUSpriority = pmax.clone();
        self.T1_timer = _ld_T1_timer.minus(&BInteger::new(b"1")).clone();
        self.T2_timer = _ld_T2_timer.minus(&BInteger::new(b"1")).clone();
        self.T3_evaluated = BBoolean::new(false).clone();
    }
}

