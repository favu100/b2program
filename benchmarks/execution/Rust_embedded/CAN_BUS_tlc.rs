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









#[derive(Default, Debug)]pub struct CAN_BUS_tlc {
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
}


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
}


