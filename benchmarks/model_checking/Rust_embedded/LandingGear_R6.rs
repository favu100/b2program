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
pub enum DOOR_STATE {
    #[default]
    open = 0, 
    closed = 1, 
    door_moving = 2
}

impl DOOR_STATE {
    pub fn equal(&self, other: &DOOR_STATE) -> bool { *self == *other }
    pub fn unequal(&self, other: &DOOR_STATE) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::open, 
            1 => Self::closed, 
            2 => Self::door_moving, 
            _ => panic!("DOOR_STATE index out of range! {:?}", idx)
        }
    }
}

impl SetItem<3> for DOOR_STATE {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_DOOR_STATE = BSet<DOOR_STATE, 3>;
//set_enum_declaration done

//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum GEAR_STATE {
    #[default]
    retracted = 0, 
    extended = 1, 
    gear_moving = 2
}

impl GEAR_STATE {
    pub fn equal(&self, other: &GEAR_STATE) -> bool { *self == *other }
    pub fn unequal(&self, other: &GEAR_STATE) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::retracted, 
            1 => Self::extended, 
            2 => Self::gear_moving, 
            _ => panic!("GEAR_STATE index out of range! {:?}", idx)
        }
    }
}

impl SetItem<3> for GEAR_STATE {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_GEAR_STATE = BSet<GEAR_STATE, 3>;
//set_enum_declaration done

//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum HANDLE_STATE {
    #[default]
    up = 0, 
    down = 1
}

impl HANDLE_STATE {
    pub fn equal(&self, other: &HANDLE_STATE) -> bool { *self == *other }
    pub fn unequal(&self, other: &HANDLE_STATE) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::up, 
            1 => Self::down, 
            _ => panic!("HANDLE_STATE index out of range! {:?}", idx)
        }
    }
}

impl SetItem<2> for HANDLE_STATE {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_HANDLE_STATE = BSet<HANDLE_STATE, 2>;
//set_enum_declaration done

//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum POSITION {
    #[default]
    fr = 0, 
    lt = 1, 
    rt = 2
}

impl POSITION {
    pub fn equal(&self, other: &POSITION) -> bool { *self == *other }
    pub fn unequal(&self, other: &POSITION) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::fr, 
            1 => Self::lt, 
            2 => Self::rt, 
            _ => panic!("POSITION index out of range! {:?}", idx)
        }
    }
}

impl SetItem<3> for POSITION {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_POSITION = BSet<POSITION, 3>;
//set_enum_declaration done

//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum SWITCH_STATE {
    #[default]
    switch_open = 0, 
    switch_closed = 1
}

impl SWITCH_STATE {
    pub fn equal(&self, other: &SWITCH_STATE) -> bool { *self == *other }
    pub fn unequal(&self, other: &SWITCH_STATE) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::switch_open, 
            1 => Self::switch_closed, 
            _ => panic!("SWITCH_STATE index out of range! {:?}", idx)
        }
    }
}

impl SetItem<2> for SWITCH_STATE {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_SWITCH_STATE = BSet<SWITCH_STATE, 2>;
//set_enum_declaration done

//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum PLANE_STATE {
    #[default]
    ground = 0, 
    flight = 1
}

impl PLANE_STATE {
    pub fn equal(&self, other: &PLANE_STATE) -> bool { *self == *other }
    pub fn unequal(&self, other: &PLANE_STATE) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::ground, 
            1 => Self::flight, 
            _ => panic!("PLANE_STATE index out of range! {:?}", idx)
        }
    }
}

impl SetItem<2> for PLANE_STATE {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_PLANE_STATE = BSet<PLANE_STATE, 2>;
//set_enum_declaration done

//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum VALVE_STATE {
    #[default]
    valve_open = 0, 
    valve_closed = 1
}

impl VALVE_STATE {
    pub fn equal(&self, other: &VALVE_STATE) -> bool { *self == *other }
    pub fn unequal(&self, other: &VALVE_STATE) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::valve_open, 
            1 => Self::valve_closed, 
            _ => panic!("VALVE_STATE index out of range! {:?}", idx)
        }
    }
}

impl SetItem<2> for VALVE_STATE {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_VALVE_STATE = BSet<VALVE_STATE, 2>;
//set_enum_declaration done

//relation_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum POSITION_X_DOOR_STATE {
    #[default]
    fr_open = 0, 
    fr_closed = 1, 
    fr_door_moving = 2, 
    lt_open = 3, 
    lt_closed = 4, 
    lt_door_moving = 5, 
    rt_open = 6, 
    rt_closed = 7, 
    rt_door_moving = 8
}
type rel_POSITION_X_DOOR_STATE = BRelation<POSITION, { POSITION::VARIANTS }, DOOR_STATE, { DOOR_STATE::VARIANTS }, 9>;
//relation_declaration done







//relation_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum POSITION_X_GEAR_STATE {
    #[default]
    fr_retracted = 0, 
    fr_extended = 1, 
    fr_gear_moving = 2, 
    lt_retracted = 3, 
    lt_extended = 4, 
    lt_gear_moving = 5, 
    rt_retracted = 6, 
    rt_extended = 7, 
    rt_gear_moving = 8
}
type rel_POSITION_X_GEAR_STATE = BRelation<POSITION, { POSITION::VARIANTS }, GEAR_STATE, { GEAR_STATE::VARIANTS }, 9>;
//relation_declaration done







//enum_set_declaration start
#[derive(Default, Debug, Clone, Copy)]
// each enum value corresponds to one BSet
pub enum SetGEAR_STATE {
    #[default]
    SET_SET__TES_TES = 0, 
    SET_SET_retracted_TES_TES = 1, 
    SET_SET_extended_TES_TES = 2, 
    SET_SET_retracted__extended_TES_TES = 3, 
    SET_SET_gear_moving_TES_TES = 4, 
    SET_SET_retracted__gear_moving_TES_TES = 5, 
    SET_SET_extended__gear_moving_TES_TES = 6, 
    SET_SET_retracted__extended__gear_moving_TES_TES = 7
}
type set_SetGEAR_STATE = BSet<set_GEAR_STATE, 8>;

impl PowSetItem<8, 3> for GEAR_STATE {
    type SetRepr = SetGEAR_STATE;
    fn arr_to_idx(set: [bool; 3]) -> usize {
        match set {
            [false, false, false] => 0,
            [true, false, false] => 1,
            [false, true, false] => 2,
            [true, true, false] => 3,
            [false, false, true] => 4,
            [true, false, true] => 5,
            [false, true, true] => 6,
            [true, true, true] => 7,
            _ => panic!("Attempting to convert non-existing set to index!") // only happens if this is a const-set and code-generation missed a necessary value
        }
    }
    fn idx_to_arr(idx: usize) -> [bool; 3] {
        match idx {
            0 => [false, false, false],
            1 => [true, false, false],
            2 => [false, true, false],
            3 => [true, true, false],
            4 => [false, false, true],
            5 => [true, false, true],
            6 => [false, true, true],
            7 => [true, true, true],
            _ => panic!("SetGEAR_STATE index out of range! {:?}", idx)
        }
    }
}
impl SetGEAR_STATE {
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::SET_SET__TES_TES, 
            1 => Self::SET_SET_retracted_TES_TES, 
            2 => Self::SET_SET_extended_TES_TES, 
            3 => Self::SET_SET_retracted__extended_TES_TES, 
            4 => Self::SET_SET_gear_moving_TES_TES, 
            5 => Self::SET_SET_retracted__gear_moving_TES_TES, 
            6 => Self::SET_SET_extended__gear_moving_TES_TES, 
            7 => Self::SET_SET_retracted__extended__gear_moving_TES_TES, 
            _ => panic!("SetGEAR_STATE index out of range! {:?}", idx)
        }
    }
}

impl SetItem<8> for SetGEAR_STATE {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

//enum_set_declaration done

//enum_set_declaration start
#[derive(Default, Debug, Clone, Copy)]
// each enum value corresponds to one BSet
pub enum SetDOOR_STATE {
    #[default]
    SET_SET__TES_TES = 0, 
    SET_SET_open_TES_TES = 1, 
    SET_SET_closed_TES_TES = 2, 
    SET_SET_open__closed_TES_TES = 3, 
    SET_SET_door_moving_TES_TES = 4, 
    SET_SET_open__door_moving_TES_TES = 5, 
    SET_SET_closed__door_moving_TES_TES = 6, 
    SET_SET_open__closed__door_moving_TES_TES = 7
}
type set_SetDOOR_STATE = BSet<set_DOOR_STATE, 8>;

impl PowSetItem<8, 3> for DOOR_STATE {
    type SetRepr = SetDOOR_STATE;
    fn arr_to_idx(set: [bool; 3]) -> usize {
        match set {
            [false, false, false] => 0,
            [true, false, false] => 1,
            [false, true, false] => 2,
            [true, true, false] => 3,
            [false, false, true] => 4,
            [true, false, true] => 5,
            [false, true, true] => 6,
            [true, true, true] => 7,
            _ => panic!("Attempting to convert non-existing set to index!") // only happens if this is a const-set and code-generation missed a necessary value
        }
    }
    fn idx_to_arr(idx: usize) -> [bool; 3] {
        match idx {
            0 => [false, false, false],
            1 => [true, false, false],
            2 => [false, true, false],
            3 => [true, true, false],
            4 => [false, false, true],
            5 => [true, false, true],
            6 => [false, true, true],
            7 => [true, true, true],
            _ => panic!("SetDOOR_STATE index out of range! {:?}", idx)
        }
    }
}
impl SetDOOR_STATE {
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::SET_SET__TES_TES, 
            1 => Self::SET_SET_open_TES_TES, 
            2 => Self::SET_SET_closed_TES_TES, 
            3 => Self::SET_SET_open__closed_TES_TES, 
            4 => Self::SET_SET_door_moving_TES_TES, 
            5 => Self::SET_SET_open__door_moving_TES_TES, 
            6 => Self::SET_SET_closed__door_moving_TES_TES, 
            7 => Self::SET_SET_open__closed__door_moving_TES_TES, 
            _ => panic!("SetDOOR_STATE index out of range! {:?}", idx)
        }
    }
}

impl SetItem<8> for SetDOOR_STATE {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

//enum_set_declaration done

//enum_set_declaration start
#[derive(Default, Debug, Clone, Copy)]
// each enum value corresponds to one BSet
pub enum SetPOSITION {
    #[default]
    SET_SET__TES_TES = 0, 
    SET_SET_fr_TES_TES = 1, 
    SET_SET_lt_TES_TES = 2, 
    SET_SET_fr__lt_TES_TES = 3, 
    SET_SET_rt_TES_TES = 4, 
    SET_SET_fr__rt_TES_TES = 5, 
    SET_SET_lt__rt_TES_TES = 6, 
    SET_SET_fr__lt__rt_TES_TES = 7
}
type set_SetPOSITION = BSet<set_POSITION, 8>;

impl PowSetItem<8, 3> for POSITION {
    type SetRepr = SetPOSITION;
    fn arr_to_idx(set: [bool; 3]) -> usize {
        match set {
            [false, false, false] => 0,
            [true, false, false] => 1,
            [false, true, false] => 2,
            [true, true, false] => 3,
            [false, false, true] => 4,
            [true, false, true] => 5,
            [false, true, true] => 6,
            [true, true, true] => 7,
            _ => panic!("Attempting to convert non-existing set to index!") // only happens if this is a const-set and code-generation missed a necessary value
        }
    }
    fn idx_to_arr(idx: usize) -> [bool; 3] {
        match idx {
            0 => [false, false, false],
            1 => [true, false, false],
            2 => [false, true, false],
            3 => [true, true, false],
            4 => [false, false, true],
            5 => [true, false, true],
            6 => [false, true, true],
            7 => [true, true, true],
            _ => panic!("SetPOSITION index out of range! {:?}", idx)
        }
    }
}
impl SetPOSITION {
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::SET_SET__TES_TES, 
            1 => Self::SET_SET_fr_TES_TES, 
            2 => Self::SET_SET_lt_TES_TES, 
            3 => Self::SET_SET_fr__lt_TES_TES, 
            4 => Self::SET_SET_rt_TES_TES, 
            5 => Self::SET_SET_fr__rt_TES_TES, 
            6 => Self::SET_SET_lt__rt_TES_TES, 
            7 => Self::SET_SET_fr__lt__rt_TES_TES, 
            _ => panic!("SetPOSITION index out of range! {:?}", idx)
        }
    }
}

impl SetItem<8> for SetPOSITION {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

//enum_set_declaration done

#[derive(Derivative)]
#[derivative(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct LandingGear_R6 {
    /*declarations*/analogical_switch: SWITCH_STATE,
    general_EV: BBoolean,
    general_valve: VALVE_STATE,
    handle_move: BBoolean,
    close_EV: BBoolean,
    extend_EV: BBoolean,
    open_EV: BBoolean,
    retract_EV: BBoolean,
    shock_absorber: PLANE_STATE,
    valve_close_door: VALVE_STATE,
    valve_extend_gear: VALVE_STATE,
    valve_open_door: VALVE_STATE,
    valve_retract_gear: VALVE_STATE,
    doors: rel_POSITION_X_DOOR_STATE,
    gears: rel_POSITION_X_GEAR_STATE,
    handle: HANDLE_STATE,
    door: DOOR_STATE,
    gear: GEAR_STATE,
    /*sets*//*set_declaration*/_DOOR_STATE: set_DOOR_STATE,
    /*set_declaration*/_GEAR_STATE: set_GEAR_STATE,
    /*set_declaration*/_HANDLE_STATE: set_HANDLE_STATE,
    /*set_declaration*/_POSITION: set_POSITION,
    /*set_declaration*/_SWITCH_STATE: set_SWITCH_STATE,
    /*set_declaration*/_PLANE_STATE: set_PLANE_STATE,
    /*set_declaration*/_VALVE_STATE: set_VALVE_STATE,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_begin_flying: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_land_plane: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_open_valve_door_open: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_close_valve_door_open: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_open_valve_door_close: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_close_valve_door_close: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_open_valve_retract_gear: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_close_valve_retract_gear: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_open_valve_extend_gear: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_close_valve_extend_gear: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_con_stimulate_open_door_valve: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_con_stop_stimulate_open_door_valve: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_con_stimulate_close_door_valve: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_con_stop_stimulate_close_door_valve: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_con_stimulate_retract_gear_valve: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_con_stop_stimulate_retract_gear_valve: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_con_stimulate_extend_gear_valve: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_con_stop_stimulate_extend_gear_valve: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_start_retracting_first: Option<HashSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_retract_gear_skip: Option<HashSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_retract_gear_last: Option<HashSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_start_extending: Option<HashSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_extend_gear_last: Option<HashSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_extend_gear_skip: Option<HashSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_start_open_door: Option<HashSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_open_door_last: Option<HashSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_open_door_skip: Option<HashSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_start_close_door: Option<HashSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_close_door: Option<HashSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_close_door_skip: Option<HashSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_toggle_handle_up: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_toggle_handle_down: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_con_stimulate_general_valve: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_con_stop_stimulate_general_valve: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_evn_open_general_valve: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_evn_close_general_valve: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_close_analogical_switch: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_open_analogical_switch: Option<bool>,}


impl LandingGear_R6 {

    pub fn new() -> LandingGear_R6 {
        //values: ''
        let mut m: LandingGear_R6 = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        /*set_initializations*///set_initialization
    self._DOOR_STATE = bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open, /*enum_call*/DOOR_STATE::closed, /*enum_call*/DOOR_STATE::door_moving];
    //set_initialization
    self._GEAR_STATE = bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted, /*enum_call*/GEAR_STATE::extended, /*enum_call*/GEAR_STATE::gear_moving];
    //set_initialization
    self._HANDLE_STATE = bset![HANDLE_STATE, /*enum_call*/HANDLE_STATE::up, /*enum_call*/HANDLE_STATE::down];
    //set_initialization
    self._POSITION = bset![POSITION, /*enum_call*/POSITION::fr, /*enum_call*/POSITION::lt, /*enum_call*/POSITION::rt];
    //set_initialization
    self._SWITCH_STATE = bset![SWITCH_STATE, /*enum_call*/SWITCH_STATE::switch_open, /*enum_call*/SWITCH_STATE::switch_closed];
    //set_initialization
    self._PLANE_STATE = bset![PLANE_STATE, /*enum_call*/PLANE_STATE::ground, /*enum_call*/PLANE_STATE::flight];
    //set_initialization
    self._VALVE_STATE = bset![VALVE_STATE, /*enum_call*/VALVE_STATE::valve_open, /*enum_call*/VALVE_STATE::valve_closed];
        /*properties*/
        /*body*/self.gears = rel_POSITION_X_GEAR_STATE::cartesian_product(&self._POSITION, &bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended]).clone().clone();
    self.doors = rel_POSITION_X_DOOR_STATE::cartesian_product(&self._POSITION, &bset![DOOR_STATE, /*enum_call*/DOOR_STATE::closed]).clone().clone();
    self.handle = /*enum_call*/HANDLE_STATE::down;
    self.valve_extend_gear = /*enum_call*/VALVE_STATE::valve_closed;
    self.valve_retract_gear = /*enum_call*/VALVE_STATE::valve_closed;
    self.valve_open_door = /*enum_call*/VALVE_STATE::valve_closed;
    self.valve_close_door = /*enum_call*/VALVE_STATE::valve_closed;
    self.open_EV = false;
    self.close_EV = false;
    self.retract_EV = false;
    self.extend_EV = false;
    self.shock_absorber = /*enum_call*/PLANE_STATE::ground;
    self.general_EV = false;
    self.general_valve = /*enum_call*/VALVE_STATE::valve_closed;
    self.analogical_switch = /*enum_call*/SWITCH_STATE::switch_open;
    self.handle_move = false;
    self.gear = /*enum_call*/GEAR_STATE::extended;
    self.door = /*enum_call*/DOOR_STATE::closed;
        /*includesInitialization*/
    }

    pub fn get_analogical_switch(&self) -> SWITCH_STATE {
        return self.analogical_switch.clone();
    }

    pub fn get_general_EV(&self) -> BBoolean {
        return self.general_EV.clone();
    }

    pub fn get_general_valve(&self) -> VALVE_STATE {
        return self.general_valve.clone();
    }

    pub fn get_handle_move(&self) -> BBoolean {
        return self.handle_move.clone();
    }

    pub fn get_close_EV(&self) -> BBoolean {
        return self.close_EV.clone();
    }

    pub fn get_extend_EV(&self) -> BBoolean {
        return self.extend_EV.clone();
    }

    pub fn get_open_EV(&self) -> BBoolean {
        return self.open_EV.clone();
    }

    pub fn get_retract_EV(&self) -> BBoolean {
        return self.retract_EV.clone();
    }

    pub fn get_shock_absorber(&self) -> PLANE_STATE {
        return self.shock_absorber.clone();
    }

    pub fn get_valve_close_door(&self) -> VALVE_STATE {
        return self.valve_close_door.clone();
    }

    pub fn get_valve_extend_gear(&self) -> VALVE_STATE {
        return self.valve_extend_gear.clone();
    }

    pub fn get_valve_open_door(&self) -> VALVE_STATE {
        return self.valve_open_door.clone();
    }

    pub fn get_valve_retract_gear(&self) -> VALVE_STATE {
        return self.valve_retract_gear.clone();
    }

    pub fn get_doors(&self) -> rel_POSITION_X_DOOR_STATE {
        return self.doors.clone();
    }

    pub fn get_gears(&self) -> rel_POSITION_X_GEAR_STATE {
        return self.gears.clone();
    }

    pub fn get_handle(&self) -> HANDLE_STATE {
        return self.handle.clone();
    }

    pub fn get_door(&self) -> DOOR_STATE {
        return self.door.clone();
    }

    pub fn get_gear(&self) -> GEAR_STATE {
        return self.gear.clone();
    }

    pub fn get__DOOR_STATE(&self) -> set_DOOR_STATE {
        return self._DOOR_STATE.clone();
    }

    pub fn get__GEAR_STATE(&self) -> set_GEAR_STATE {
        return self._GEAR_STATE.clone();
    }

    pub fn get__HANDLE_STATE(&self) -> set_HANDLE_STATE {
        return self._HANDLE_STATE.clone();
    }

    pub fn get__POSITION(&self) -> set_POSITION {
        return self._POSITION.clone();
    }

    pub fn get__SWITCH_STATE(&self) -> set_SWITCH_STATE {
        return self._SWITCH_STATE.clone();
    }

    pub fn get__PLANE_STATE(&self) -> set_PLANE_STATE {
        return self._PLANE_STATE.clone();
    }

    pub fn get__VALVE_STATE(&self) -> set_VALVE_STATE {
        return self._VALVE_STATE.clone();
    }

    pub fn begin_flying(&mut self) -> () {
        //select
        if self.shock_absorber.equal(&/*enum_call*/PLANE_STATE::ground) {
            self.shock_absorber = /*enum_call*/PLANE_STATE::flight;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn land_plane(&mut self) -> () {
        //select
        if self.shock_absorber.equal(&/*enum_call*/PLANE_STATE::flight) {
            self.shock_absorber = /*enum_call*/PLANE_STATE::ground;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn open_valve_door_open(&mut self) -> () {
        //select
        if (self.valve_open_door.equal(&/*enum_call*/VALVE_STATE::valve_closed) && self.open_EV.equal(&true)) {
            self.valve_open_door = /*enum_call*/VALVE_STATE::valve_open;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn close_valve_door_open(&mut self) -> () {
        //select
        if (self.valve_open_door.equal(&/*enum_call*/VALVE_STATE::valve_open) && self.open_EV.equal(&false)) {
            self.valve_open_door = /*enum_call*/VALVE_STATE::valve_closed;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn open_valve_door_close(&mut self) -> () {
        //select
        if (self.valve_close_door.equal(&/*enum_call*/VALVE_STATE::valve_closed) && self.close_EV.equal(&true)) {
            self.valve_close_door = /*enum_call*/VALVE_STATE::valve_open;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn close_valve_door_close(&mut self) -> () {
        //select
        if (self.valve_close_door.equal(&/*enum_call*/VALVE_STATE::valve_open) && self.close_EV.equal(&false)) {
            self.valve_close_door = /*enum_call*/VALVE_STATE::valve_closed;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn open_valve_retract_gear(&mut self) -> () {
        //select
        if (self.valve_retract_gear.equal(&/*enum_call*/VALVE_STATE::valve_closed) && self.retract_EV.equal(&true)) {
            self.valve_retract_gear = /*enum_call*/VALVE_STATE::valve_open;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn close_valve_retract_gear(&mut self) -> () {
        //select
        if (self.valve_retract_gear.equal(&/*enum_call*/VALVE_STATE::valve_open) && self.retract_EV.equal(&false)) {
            self.valve_retract_gear = /*enum_call*/VALVE_STATE::valve_closed;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn open_valve_extend_gear(&mut self) -> () {
        //select
        if (self.valve_extend_gear.equal(&/*enum_call*/VALVE_STATE::valve_closed) && self.extend_EV.equal(&true)) {
            self.valve_extend_gear = /*enum_call*/VALVE_STATE::valve_open;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn close_valve_extend_gear(&mut self) -> () {
        //select
        if (self.valve_extend_gear.equal(&/*enum_call*/VALVE_STATE::valve_open) && self.extend_EV.equal(&false)) {
            self.valve_extend_gear = /*enum_call*/VALVE_STATE::valve_closed;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stimulate_open_door_valve(&mut self) -> () {
        //select
        if (((self.open_EV.equal(&false) && self.close_EV.equal(&false)) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended]).not()) || ((self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted]).not()) && (self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open]) && self.shock_absorber.equal(&/*enum_call*/PLANE_STATE::ground)).not()))) && self.general_EV.equal(&true)) {
            self.open_EV = true;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stop_stimulate_open_door_valve(&mut self) -> () {
        //select
        if ((((self.open_EV.equal(&true) && self.extend_EV.equal(&false)) && self.retract_EV.equal(&false)) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])) || ((self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && (self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted]) || self.shock_absorber.equal(&/*enum_call*/PLANE_STATE::ground))) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open])))) && self.general_EV.equal(&true)) {
            self.open_EV = false;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stimulate_close_door_valve(&mut self) -> () {
        //select
        if ((((((self.close_EV.equal(&false) && self.open_EV.equal(&false)) && self.extend_EV.equal(&false)) && self.retract_EV.equal(&false)) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && (self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted]) || self.shock_absorber.equal(&/*enum_call*/PLANE_STATE::ground))))) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::closed]).not()) && self.general_EV.equal(&true)) {
            self.close_EV = true;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stop_stimulate_close_door_valve(&mut self) -> () {
        //select
        if ((self.close_EV.equal(&true) && (((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::closed])) || ((self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && (self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted]) || self.shock_absorber.equal(&/*enum_call*/PLANE_STATE::ground))) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::closed])))) && self.general_EV.equal(&true)) {
            self.close_EV = false;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stimulate_retract_gear_valve(&mut self) -> () {
        //select
        if (((((((self.retract_EV.equal(&false) && self.extend_EV.equal(&false)) && self.open_EV.equal(&true)) && self.handle.equal(&/*enum_call*/HANDLE_STATE::up)) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted]).not()) && self.shock_absorber.equal(&/*enum_call*/PLANE_STATE::flight)) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open])) && self.general_EV.equal(&true)) {
            self.retract_EV = true;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stop_stimulate_retract_gear_valve(&mut self) -> () {
        //select
        if ((self.retract_EV.equal(&true) && (self.handle.equal(&/*enum_call*/HANDLE_STATE::down) || self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted]))) && self.general_EV.equal(&true)) {
            self.retract_EV = false;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stimulate_extend_gear_valve(&mut self) -> () {
        //select
        if ((((((self.extend_EV.equal(&false) && self.retract_EV.equal(&false)) && self.open_EV.equal(&true)) && self.handle.equal(&/*enum_call*/HANDLE_STATE::down)) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended]).not()) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open])) && self.general_EV.equal(&true)) {
            self.extend_EV = true;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stop_stimulate_extend_gear_valve(&mut self) -> () {
        //select
        if ((self.extend_EV.equal(&true) && (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) || self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended]))) && self.general_EV.equal(&true)) {
            self.extend_EV = false;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_start_retracting_first(&mut self, mut gr: POSITION) -> () {
        //select
        if (((((((self.gears.domain().elementOf(&gr) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open])) && self.handle.equal(&/*enum_call*/HANDLE_STATE::up)) && self.gears.functionCall(&gr).equal(&/*enum_call*/GEAR_STATE::extended)) && self.valve_retract_gear.equal(&/*enum_call*/VALVE_STATE::valve_open)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) && bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended, /*enum_call*/GEAR_STATE::gear_moving].elementOf(&self.gear)) && self.door.equal(&/*enum_call*/DOOR_STATE::open)) {
            let mut _ld_gears = self.gears.clone();
            self.gears = _ld_gears._override(&brel![rel_POSITION_X_GEAR_STATE, (gr.clone(), /*enum_call*/GEAR_STATE::gear_moving.clone())]).clone().clone();
            self.gear = /*enum_call*/GEAR_STATE::gear_moving;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_retract_gear_skip(&mut self, mut gr: POSITION) -> () {
        //select
        if (((((self.gears.domain().elementOf(&gr) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open])) && self.gears.relationImage(&self._POSITION.difference(&bset![POSITION, gr])).unequal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted])) && self.handle.equal(&/*enum_call*/HANDLE_STATE::up)) && self.gears.functionCall(&gr).equal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) {
            self.gears = self.gears._override(&brel![rel_POSITION_X_GEAR_STATE, (gr.clone(), /*enum_call*/GEAR_STATE::retracted.clone())]).clone().clone();
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_retract_gear_last(&mut self, mut gr: POSITION) -> () {
        //select
        if (((((((self.gears.domain().elementOf(&gr) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open])) && self.gears.relationImage(&self._POSITION.difference(&bset![POSITION, gr])).equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted])) && self.handle.equal(&/*enum_call*/HANDLE_STATE::up)) && self.gears.functionCall(&gr).equal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) && self.gear.equal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.door.equal(&/*enum_call*/DOOR_STATE::open)) {
            let mut _ld_gears = self.gears.clone();
            self.gears = _ld_gears._override(&brel![rel_POSITION_X_GEAR_STATE, (gr.clone(), /*enum_call*/GEAR_STATE::retracted.clone())]).clone().clone();
            self.gear = /*enum_call*/GEAR_STATE::retracted;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_start_extending(&mut self, mut gr: POSITION) -> () {
        //select
        if (((((((self.gears.domain().elementOf(&gr) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open])) && self.handle.equal(&/*enum_call*/HANDLE_STATE::down)) && self.gears.functionCall(&gr).equal(&/*enum_call*/GEAR_STATE::retracted)) && self.valve_extend_gear.equal(&/*enum_call*/VALVE_STATE::valve_open)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) && bset![GEAR_STATE, /*enum_call*/GEAR_STATE::gear_moving, /*enum_call*/GEAR_STATE::retracted].elementOf(&self.gear)) && self.door.equal(&/*enum_call*/DOOR_STATE::open)) {
            let mut _ld_gears = self.gears.clone();
            self.gears = _ld_gears._override(&brel![rel_POSITION_X_GEAR_STATE, (gr.clone(), /*enum_call*/GEAR_STATE::gear_moving.clone())]).clone().clone();
            self.gear = /*enum_call*/GEAR_STATE::gear_moving;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_extend_gear_last(&mut self, mut gr: POSITION) -> () {
        //select
        if (((((((self.gears.domain().elementOf(&gr) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open])) && self.handle.equal(&/*enum_call*/HANDLE_STATE::down)) && self.gears.relationImage(&self._POSITION.difference(&bset![POSITION, gr])).equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])) && self.gears.functionCall(&gr).equal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) && self.gear.equal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.door.equal(&/*enum_call*/DOOR_STATE::open)) {
            let mut _ld_gears = self.gears.clone();
            self.gears = _ld_gears._override(&brel![rel_POSITION_X_GEAR_STATE, (gr.clone(), /*enum_call*/GEAR_STATE::extended.clone())]).clone().clone();
            self.gear = /*enum_call*/GEAR_STATE::extended;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_extend_gear_skip(&mut self, mut gr: POSITION) -> () {
        //select
        if (((((self.gears.domain().elementOf(&gr) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open])) && self.handle.equal(&/*enum_call*/HANDLE_STATE::down)) && self.gears.relationImage(&self._POSITION.difference(&bset![POSITION, gr])).unequal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])) && self.gears.functionCall(&gr).equal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) {
            self.gears = self.gears._override(&brel![rel_POSITION_X_GEAR_STATE, (gr.clone(), /*enum_call*/GEAR_STATE::extended.clone())]).clone().clone();
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_start_open_door(&mut self, mut gr: POSITION) -> () {
        //select
        if (((((((((self.gears.domain().elementOf(&gr) && self.doors.functionCall(&gr).equal(&/*enum_call*/DOOR_STATE::closed)) && self.gears.functionCall(&gr).unequal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.gears.range().notElementOf(&/*enum_call*/GEAR_STATE::gear_moving)) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted])) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])))) && self.valve_open_door.equal(&/*enum_call*/VALVE_STATE::valve_open)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) && bset![DOOR_STATE, /*enum_call*/DOOR_STATE::closed, /*enum_call*/DOOR_STATE::door_moving].elementOf(&self.door)) && self.gear.unequal(&/*enum_call*/GEAR_STATE::gear_moving)) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gear.equal(&/*enum_call*/GEAR_STATE::retracted)) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && self.gear.equal(&/*enum_call*/GEAR_STATE::extended)))) {
            let mut _ld_doors = self.doors.clone();
            self.doors = _ld_doors._override(&brel![rel_POSITION_X_DOOR_STATE, (gr.clone(), /*enum_call*/DOOR_STATE::door_moving.clone())]).clone().clone();
            self.door = /*enum_call*/DOOR_STATE::door_moving;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_open_door_last(&mut self, mut gr: POSITION) -> () {
        //select
        if ((((((((((self.gears.domain().elementOf(&gr) && self.doors.functionCall(&gr).equal(&/*enum_call*/DOOR_STATE::door_moving)) && self.gears.functionCall(&gr).unequal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.gears.range().notElementOf(&/*enum_call*/GEAR_STATE::gear_moving)) && self.doors.relationImage(&self._POSITION.difference(&bset![POSITION, gr])).equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open])) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted])) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])))) && self.valve_open_door.equal(&/*enum_call*/VALVE_STATE::valve_open)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) && self.door.equal(&/*enum_call*/DOOR_STATE::door_moving)) && self.gear.unequal(&/*enum_call*/GEAR_STATE::gear_moving)) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gear.equal(&/*enum_call*/GEAR_STATE::retracted)) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && self.gear.equal(&/*enum_call*/GEAR_STATE::extended)))) {
            let mut _ld_doors = self.doors.clone();
            self.doors = _ld_doors._override(&brel![rel_POSITION_X_DOOR_STATE, (gr.clone(), /*enum_call*/DOOR_STATE::open.clone())]).clone().clone();
            self.door = /*enum_call*/DOOR_STATE::open;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_open_door_skip(&mut self, mut gr: POSITION) -> () {
        //select
        if (((((((self.gears.domain().elementOf(&gr) && self.doors.functionCall(&gr).equal(&/*enum_call*/DOOR_STATE::door_moving)) && self.gears.functionCall(&gr).unequal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.gears.range().notElementOf(&/*enum_call*/GEAR_STATE::gear_moving)) && self.doors.relationImage(&self._POSITION.difference(&bset![POSITION, gr])).unequal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open])) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted])) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])))) && self.valve_open_door.equal(&/*enum_call*/VALVE_STATE::valve_open)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) {
            self.doors = self.doors._override(&brel![rel_POSITION_X_DOOR_STATE, (gr.clone(), /*enum_call*/DOOR_STATE::open.clone())]).clone().clone();
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_start_close_door(&mut self, mut gr: POSITION) -> () {
        //select
        if ((((((((self.gears.domain().elementOf(&gr) && self.doors.functionCall(&gr).equal(&/*enum_call*/DOOR_STATE::open)) && self.gears.functionCall(&gr).unequal(&/*enum_call*/GEAR_STATE::gear_moving)) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && (self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted]) || self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended]))) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])))) && self.valve_close_door.equal(&/*enum_call*/VALVE_STATE::valve_open)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) && bset![DOOR_STATE, /*enum_call*/DOOR_STATE::door_moving, /*enum_call*/DOOR_STATE::open].elementOf(&self.door)) && self.gear.unequal(&/*enum_call*/GEAR_STATE::gear_moving)) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gear.equal(&/*enum_call*/GEAR_STATE::extended)) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended, /*enum_call*/GEAR_STATE::retracted].elementOf(&self.gear)))) {
            let mut _ld_doors = self.doors.clone();
            self.doors = _ld_doors._override(&brel![rel_POSITION_X_DOOR_STATE, (gr.clone(), /*enum_call*/DOOR_STATE::door_moving.clone())]).clone().clone();
            self.door = /*enum_call*/DOOR_STATE::door_moving;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_close_door(&mut self, mut gr: POSITION) -> () {
        //select
        if (((((((((((self.gears.domain().elementOf(&gr) && self.doors.functionCall(&gr).equal(&/*enum_call*/DOOR_STATE::door_moving)) && self.gears.functionCall(&gr).unequal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.gears.range().notElementOf(&/*enum_call*/GEAR_STATE::gear_moving)) && self.doors.relationImage(&self._POSITION.difference(&bset![POSITION, gr])).equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::closed])) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && (self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted]) || self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended]))) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])))) && self.valve_close_door.equal(&/*enum_call*/VALVE_STATE::valve_open)) && (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])).implies(|| self.shock_absorber.equal(&/*enum_call*/PLANE_STATE::ground))) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) && self.door.equal(&/*enum_call*/DOOR_STATE::door_moving)) && self.gear.unequal(&/*enum_call*/GEAR_STATE::gear_moving)) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gear.equal(&/*enum_call*/GEAR_STATE::extended)) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended, /*enum_call*/GEAR_STATE::retracted].elementOf(&self.gear)))) {
            let mut _ld_doors = self.doors.clone();
            self.doors = _ld_doors._override(&brel![rel_POSITION_X_DOOR_STATE, (gr.clone(), /*enum_call*/DOOR_STATE::closed.clone())]).clone().clone();
            self.door = /*enum_call*/DOOR_STATE::closed;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_close_door_skip(&mut self, mut gr: POSITION) -> () {
        //select
        if ((((((((self.gears.domain().elementOf(&gr) && self.doors.functionCall(&gr).equal(&/*enum_call*/DOOR_STATE::door_moving)) && self.gears.functionCall(&gr).unequal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.gears.range().notElementOf(&/*enum_call*/GEAR_STATE::gear_moving)) && self.doors.relationImage(&self._POSITION.difference(&bset![POSITION, gr])).unequal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::closed])) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && (self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted]) || self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended]))) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])))) && self.valve_close_door.equal(&/*enum_call*/VALVE_STATE::valve_open)) && (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])).implies(|| self.shock_absorber.equal(&/*enum_call*/PLANE_STATE::ground))) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) {
            self.doors = self.doors._override(&brel![rel_POSITION_X_DOOR_STATE, (gr.clone(), /*enum_call*/DOOR_STATE::closed.clone())]).clone().clone();
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn toggle_handle_up(&mut self) -> () {
        //select
        if self.handle.equal(&/*enum_call*/HANDLE_STATE::down) {
            self.handle = /*enum_call*/HANDLE_STATE::up;
            self.handle_move = true;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn toggle_handle_down(&mut self) -> () {
        //select
        if self.handle.equal(&/*enum_call*/HANDLE_STATE::up) {
            self.handle = /*enum_call*/HANDLE_STATE::down;
            self.handle_move = true;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stimulate_general_valve(&mut self) -> () {
        //select
        if (self.general_EV.equal(&false) && self.handle_move.equal(&true)) {
            self.general_EV = true;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stop_stimulate_general_valve(&mut self) -> () {
        //select
        if ((((((self.general_EV.equal(&true) && self.open_EV.equal(&false)) && self.close_EV.equal(&false)) && self.retract_EV.equal(&false)) && self.extend_EV.equal(&false)) && self.close_EV.equal(&false)) && (((((self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted])) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::closed])) && self.open_EV.equal(&false)) || (((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::closed])) && self.open_EV.equal(&false))) || (((self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::closed])) && self.open_EV.equal(&false)))) {
            self.general_EV = false;
            self.handle_move = false;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn evn_open_general_valve(&mut self) -> () {
        //select
        if ((self.general_EV.equal(&true) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_closed)) && self.analogical_switch.equal(&/*enum_call*/SWITCH_STATE::switch_closed)) {
            self.general_valve = /*enum_call*/VALVE_STATE::valve_open;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn evn_close_general_valve(&mut self) -> () {
        //select
        if ((self.general_EV.equal(&false) || self.analogical_switch.equal(&/*enum_call*/SWITCH_STATE::switch_open)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) {
            self.general_valve = /*enum_call*/VALVE_STATE::valve_closed;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_close_analogical_switch(&mut self) -> () {
        //select
        if (self.analogical_switch.equal(&/*enum_call*/SWITCH_STATE::switch_open) && self.handle_move.equal(&true)) {
            self.analogical_switch = /*enum_call*/SWITCH_STATE::switch_closed;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_open_analogical_switch(&mut self) -> () {
        //select
        if self.analogical_switch.equal(&/*enum_call*/SWITCH_STATE::switch_closed) {
            self.analogical_switch = /*enum_call*/SWITCH_STATE::switch_open;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn _tr_begin_flying(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_begin_flying.is_none() {
            let mut __tmp__val__ = self.shock_absorber.equal(&/*enum_call*/PLANE_STATE::ground);
            self._tr_cache_begin_flying = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_begin_flying.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_land_plane(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_land_plane.is_none() {
            let mut __tmp__val__ = self.shock_absorber.equal(&/*enum_call*/PLANE_STATE::flight);
            self._tr_cache_land_plane = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_land_plane.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_open_valve_door_open(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_open_valve_door_open.is_none() {
            let mut __tmp__val__ = (self.valve_open_door.equal(&/*enum_call*/VALVE_STATE::valve_closed) && self.open_EV.equal(&true));
            self._tr_cache_open_valve_door_open = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_open_valve_door_open.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_close_valve_door_open(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_close_valve_door_open.is_none() {
            let mut __tmp__val__ = (self.valve_open_door.equal(&/*enum_call*/VALVE_STATE::valve_open) && self.open_EV.equal(&false));
            self._tr_cache_close_valve_door_open = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_close_valve_door_open.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_open_valve_door_close(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_open_valve_door_close.is_none() {
            let mut __tmp__val__ = (self.valve_close_door.equal(&/*enum_call*/VALVE_STATE::valve_closed) && self.close_EV.equal(&true));
            self._tr_cache_open_valve_door_close = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_open_valve_door_close.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_close_valve_door_close(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_close_valve_door_close.is_none() {
            let mut __tmp__val__ = (self.valve_close_door.equal(&/*enum_call*/VALVE_STATE::valve_open) && self.close_EV.equal(&false));
            self._tr_cache_close_valve_door_close = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_close_valve_door_close.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_open_valve_retract_gear(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_open_valve_retract_gear.is_none() {
            let mut __tmp__val__ = (self.valve_retract_gear.equal(&/*enum_call*/VALVE_STATE::valve_closed) && self.retract_EV.equal(&true));
            self._tr_cache_open_valve_retract_gear = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_open_valve_retract_gear.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_close_valve_retract_gear(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_close_valve_retract_gear.is_none() {
            let mut __tmp__val__ = (self.valve_retract_gear.equal(&/*enum_call*/VALVE_STATE::valve_open) && self.retract_EV.equal(&false));
            self._tr_cache_close_valve_retract_gear = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_close_valve_retract_gear.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_open_valve_extend_gear(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_open_valve_extend_gear.is_none() {
            let mut __tmp__val__ = (self.valve_extend_gear.equal(&/*enum_call*/VALVE_STATE::valve_closed) && self.extend_EV.equal(&true));
            self._tr_cache_open_valve_extend_gear = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_open_valve_extend_gear.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_close_valve_extend_gear(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_close_valve_extend_gear.is_none() {
            let mut __tmp__val__ = (self.valve_extend_gear.equal(&/*enum_call*/VALVE_STATE::valve_open) && self.extend_EV.equal(&false));
            self._tr_cache_close_valve_extend_gear = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_close_valve_extend_gear.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stimulate_open_door_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stimulate_open_door_valve.is_none() {
            let mut __tmp__val__ = (((self.open_EV.equal(&false) && self.close_EV.equal(&false)) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended]).not()) || ((self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted]).not()) && (self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open]) && self.shock_absorber.equal(&/*enum_call*/PLANE_STATE::ground)).not()))) && self.general_EV.equal(&true));
            self._tr_cache_con_stimulate_open_door_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stimulate_open_door_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stop_stimulate_open_door_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stop_stimulate_open_door_valve.is_none() {
            let mut __tmp__val__ = ((((self.open_EV.equal(&true) && self.extend_EV.equal(&false)) && self.retract_EV.equal(&false)) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])) || ((self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && (self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted]) || self.shock_absorber.equal(&/*enum_call*/PLANE_STATE::ground))) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open])))) && self.general_EV.equal(&true));
            self._tr_cache_con_stop_stimulate_open_door_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stop_stimulate_open_door_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stimulate_close_door_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stimulate_close_door_valve.is_none() {
            let mut __tmp__val__ = ((((((self.close_EV.equal(&false) && self.open_EV.equal(&false)) && self.extend_EV.equal(&false)) && self.retract_EV.equal(&false)) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && (self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted]) || self.shock_absorber.equal(&/*enum_call*/PLANE_STATE::ground))))) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::closed]).not()) && self.general_EV.equal(&true));
            self._tr_cache_con_stimulate_close_door_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stimulate_close_door_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stop_stimulate_close_door_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stop_stimulate_close_door_valve.is_none() {
            let mut __tmp__val__ = ((self.close_EV.equal(&true) && (((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::closed])) || ((self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && (self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted]) || self.shock_absorber.equal(&/*enum_call*/PLANE_STATE::ground))) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::closed])))) && self.general_EV.equal(&true));
            self._tr_cache_con_stop_stimulate_close_door_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stop_stimulate_close_door_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stimulate_retract_gear_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stimulate_retract_gear_valve.is_none() {
            let mut __tmp__val__ = (((((((self.retract_EV.equal(&false) && self.extend_EV.equal(&false)) && self.open_EV.equal(&true)) && self.handle.equal(&/*enum_call*/HANDLE_STATE::up)) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted]).not()) && self.shock_absorber.equal(&/*enum_call*/PLANE_STATE::flight)) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open])) && self.general_EV.equal(&true));
            self._tr_cache_con_stimulate_retract_gear_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stimulate_retract_gear_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stop_stimulate_retract_gear_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stop_stimulate_retract_gear_valve.is_none() {
            let mut __tmp__val__ = ((self.retract_EV.equal(&true) && (self.handle.equal(&/*enum_call*/HANDLE_STATE::down) || self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted]))) && self.general_EV.equal(&true));
            self._tr_cache_con_stop_stimulate_retract_gear_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stop_stimulate_retract_gear_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stimulate_extend_gear_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stimulate_extend_gear_valve.is_none() {
            let mut __tmp__val__ = ((((((self.extend_EV.equal(&false) && self.retract_EV.equal(&false)) && self.open_EV.equal(&true)) && self.handle.equal(&/*enum_call*/HANDLE_STATE::down)) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended]).not()) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open])) && self.general_EV.equal(&true));
            self._tr_cache_con_stimulate_extend_gear_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stimulate_extend_gear_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stop_stimulate_extend_gear_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stop_stimulate_extend_gear_valve.is_none() {
            let mut __tmp__val__ = ((self.extend_EV.equal(&true) && (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) || self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended]))) && self.general_EV.equal(&true));
            self._tr_cache_con_stop_stimulate_extend_gear_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stop_stimulate_extend_gear_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_start_retracting_first(&mut self, is_caching: bool) -> HashSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_start_retracting_first.is_none() {
            let mut _ic_set_18: HashSet<POSITION> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_gr_1 in self.gears.domain().clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if ((((((self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open]) && self.handle.equal(&/*enum_call*/HANDLE_STATE::up)) && self.gears.functionCall(&_ic_gr_1).equal(&/*enum_call*/GEAR_STATE::extended)) && self.valve_retract_gear.equal(&/*enum_call*/VALVE_STATE::valve_open)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) && bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended, /*enum_call*/GEAR_STATE::gear_moving].elementOf(&self.gear)) && self.door.equal(&/*enum_call*/DOOR_STATE::open)) {
                    _ic_set_18.insert(_ic_gr_1);
                }

            }
            self._tr_cache_env_start_retracting_first = Option::Some(_ic_set_18.clone());
            return _ic_set_18;
        } else {
            return self._tr_cache_env_start_retracting_first.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_retract_gear_skip(&mut self, is_caching: bool) -> HashSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_retract_gear_skip.is_none() {
            let mut _ic_set_19: HashSet<POSITION> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_gr_1 in self.gears.domain().clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if ((((self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open]) && self.gears.relationImage(&self._POSITION.difference(&bset![POSITION, _ic_gr_1])).unequal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted])) && self.handle.equal(&/*enum_call*/HANDLE_STATE::up)) && self.gears.functionCall(&_ic_gr_1).equal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) {
                    _ic_set_19.insert(_ic_gr_1);
                }

            }
            self._tr_cache_env_retract_gear_skip = Option::Some(_ic_set_19.clone());
            return _ic_set_19;
        } else {
            return self._tr_cache_env_retract_gear_skip.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_retract_gear_last(&mut self, is_caching: bool) -> HashSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_retract_gear_last.is_none() {
            let mut _ic_set_20: HashSet<POSITION> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_gr_1 in self.gears.domain().clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if ((((((self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open]) && self.gears.relationImage(&self._POSITION.difference(&bset![POSITION, _ic_gr_1])).equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted])) && self.handle.equal(&/*enum_call*/HANDLE_STATE::up)) && self.gears.functionCall(&_ic_gr_1).equal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) && self.gear.equal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.door.equal(&/*enum_call*/DOOR_STATE::open)) {
                    _ic_set_20.insert(_ic_gr_1);
                }

            }
            self._tr_cache_env_retract_gear_last = Option::Some(_ic_set_20.clone());
            return _ic_set_20;
        } else {
            return self._tr_cache_env_retract_gear_last.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_start_extending(&mut self, is_caching: bool) -> HashSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_start_extending.is_none() {
            let mut _ic_set_21: HashSet<POSITION> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_gr_1 in self.gears.domain().clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if ((((((self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open]) && self.handle.equal(&/*enum_call*/HANDLE_STATE::down)) && self.gears.functionCall(&_ic_gr_1).equal(&/*enum_call*/GEAR_STATE::retracted)) && self.valve_extend_gear.equal(&/*enum_call*/VALVE_STATE::valve_open)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) && bset![GEAR_STATE, /*enum_call*/GEAR_STATE::gear_moving, /*enum_call*/GEAR_STATE::retracted].elementOf(&self.gear)) && self.door.equal(&/*enum_call*/DOOR_STATE::open)) {
                    _ic_set_21.insert(_ic_gr_1);
                }

            }
            self._tr_cache_env_start_extending = Option::Some(_ic_set_21.clone());
            return _ic_set_21;
        } else {
            return self._tr_cache_env_start_extending.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_extend_gear_last(&mut self, is_caching: bool) -> HashSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_extend_gear_last.is_none() {
            let mut _ic_set_22: HashSet<POSITION> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_gr_1 in self.gears.domain().clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if ((((((self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open]) && self.handle.equal(&/*enum_call*/HANDLE_STATE::down)) && self.gears.relationImage(&self._POSITION.difference(&bset![POSITION, _ic_gr_1])).equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])) && self.gears.functionCall(&_ic_gr_1).equal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) && self.gear.equal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.door.equal(&/*enum_call*/DOOR_STATE::open)) {
                    _ic_set_22.insert(_ic_gr_1);
                }

            }
            self._tr_cache_env_extend_gear_last = Option::Some(_ic_set_22.clone());
            return _ic_set_22;
        } else {
            return self._tr_cache_env_extend_gear_last.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_extend_gear_skip(&mut self, is_caching: bool) -> HashSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_extend_gear_skip.is_none() {
            let mut _ic_set_23: HashSet<POSITION> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_gr_1 in self.gears.domain().clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if ((((self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open]) && self.handle.equal(&/*enum_call*/HANDLE_STATE::down)) && self.gears.relationImage(&self._POSITION.difference(&bset![POSITION, _ic_gr_1])).unequal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])) && self.gears.functionCall(&_ic_gr_1).equal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) {
                    _ic_set_23.insert(_ic_gr_1);
                }

            }
            self._tr_cache_env_extend_gear_skip = Option::Some(_ic_set_23.clone());
            return _ic_set_23;
        } else {
            return self._tr_cache_env_extend_gear_skip.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_start_open_door(&mut self, is_caching: bool) -> HashSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_start_open_door.is_none() {
            let mut _ic_set_24: HashSet<POSITION> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_gr_1 in self.gears.domain().clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if ((((((((self.doors.functionCall(&_ic_gr_1).equal(&/*enum_call*/DOOR_STATE::closed) && self.gears.functionCall(&_ic_gr_1).unequal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.gears.range().notElementOf(&/*enum_call*/GEAR_STATE::gear_moving)) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted])) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])))) && self.valve_open_door.equal(&/*enum_call*/VALVE_STATE::valve_open)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) && bset![DOOR_STATE, /*enum_call*/DOOR_STATE::closed, /*enum_call*/DOOR_STATE::door_moving].elementOf(&self.door)) && self.gear.unequal(&/*enum_call*/GEAR_STATE::gear_moving)) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gear.equal(&/*enum_call*/GEAR_STATE::retracted)) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && self.gear.equal(&/*enum_call*/GEAR_STATE::extended)))) {
                    _ic_set_24.insert(_ic_gr_1);
                }

            }
            self._tr_cache_env_start_open_door = Option::Some(_ic_set_24.clone());
            return _ic_set_24;
        } else {
            return self._tr_cache_env_start_open_door.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_open_door_last(&mut self, is_caching: bool) -> HashSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_open_door_last.is_none() {
            let mut _ic_set_25: HashSet<POSITION> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_gr_1 in self.gears.domain().clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if (((((((((self.doors.functionCall(&_ic_gr_1).equal(&/*enum_call*/DOOR_STATE::door_moving) && self.gears.functionCall(&_ic_gr_1).unequal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.gears.range().notElementOf(&/*enum_call*/GEAR_STATE::gear_moving)) && self.doors.relationImage(&self._POSITION.difference(&bset![POSITION, _ic_gr_1])).equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open])) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted])) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])))) && self.valve_open_door.equal(&/*enum_call*/VALVE_STATE::valve_open)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) && self.door.equal(&/*enum_call*/DOOR_STATE::door_moving)) && self.gear.unequal(&/*enum_call*/GEAR_STATE::gear_moving)) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gear.equal(&/*enum_call*/GEAR_STATE::retracted)) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && self.gear.equal(&/*enum_call*/GEAR_STATE::extended)))) {
                    _ic_set_25.insert(_ic_gr_1);
                }

            }
            self._tr_cache_env_open_door_last = Option::Some(_ic_set_25.clone());
            return _ic_set_25;
        } else {
            return self._tr_cache_env_open_door_last.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_open_door_skip(&mut self, is_caching: bool) -> HashSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_open_door_skip.is_none() {
            let mut _ic_set_26: HashSet<POSITION> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_gr_1 in self.gears.domain().clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if ((((((self.doors.functionCall(&_ic_gr_1).equal(&/*enum_call*/DOOR_STATE::door_moving) && self.gears.functionCall(&_ic_gr_1).unequal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.gears.range().notElementOf(&/*enum_call*/GEAR_STATE::gear_moving)) && self.doors.relationImage(&self._POSITION.difference(&bset![POSITION, _ic_gr_1])).unequal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open])) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted])) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])))) && self.valve_open_door.equal(&/*enum_call*/VALVE_STATE::valve_open)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) {
                    _ic_set_26.insert(_ic_gr_1);
                }

            }
            self._tr_cache_env_open_door_skip = Option::Some(_ic_set_26.clone());
            return _ic_set_26;
        } else {
            return self._tr_cache_env_open_door_skip.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_start_close_door(&mut self, is_caching: bool) -> HashSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_start_close_door.is_none() {
            let mut _ic_set_27: HashSet<POSITION> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_gr_1 in self.gears.domain().clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if (((((((self.doors.functionCall(&_ic_gr_1).equal(&/*enum_call*/DOOR_STATE::open) && self.gears.functionCall(&_ic_gr_1).unequal(&/*enum_call*/GEAR_STATE::gear_moving)) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && (self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted]) || self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended]))) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])))) && self.valve_close_door.equal(&/*enum_call*/VALVE_STATE::valve_open)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) && bset![DOOR_STATE, /*enum_call*/DOOR_STATE::door_moving, /*enum_call*/DOOR_STATE::open].elementOf(&self.door)) && self.gear.unequal(&/*enum_call*/GEAR_STATE::gear_moving)) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gear.equal(&/*enum_call*/GEAR_STATE::extended)) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended, /*enum_call*/GEAR_STATE::retracted].elementOf(&self.gear)))) {
                    _ic_set_27.insert(_ic_gr_1);
                }

            }
            self._tr_cache_env_start_close_door = Option::Some(_ic_set_27.clone());
            return _ic_set_27;
        } else {
            return self._tr_cache_env_start_close_door.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_close_door(&mut self, is_caching: bool) -> HashSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_close_door.is_none() {
            let mut _ic_set_28: HashSet<POSITION> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_gr_1 in self.gears.domain().clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if ((((((((((self.doors.functionCall(&_ic_gr_1).equal(&/*enum_call*/DOOR_STATE::door_moving) && self.gears.functionCall(&_ic_gr_1).unequal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.gears.range().notElementOf(&/*enum_call*/GEAR_STATE::gear_moving)) && self.doors.relationImage(&self._POSITION.difference(&bset![POSITION, _ic_gr_1])).equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::closed])) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && (self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted]) || self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended]))) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])))) && self.valve_close_door.equal(&/*enum_call*/VALVE_STATE::valve_open)) && (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])).implies(|| self.shock_absorber.equal(&/*enum_call*/PLANE_STATE::ground))) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) && self.door.equal(&/*enum_call*/DOOR_STATE::door_moving)) && self.gear.unequal(&/*enum_call*/GEAR_STATE::gear_moving)) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gear.equal(&/*enum_call*/GEAR_STATE::extended)) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended, /*enum_call*/GEAR_STATE::retracted].elementOf(&self.gear)))) {
                    _ic_set_28.insert(_ic_gr_1);
                }

            }
            self._tr_cache_env_close_door = Option::Some(_ic_set_28.clone());
            return _ic_set_28;
        } else {
            return self._tr_cache_env_close_door.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_close_door_skip(&mut self, is_caching: bool) -> HashSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_close_door_skip.is_none() {
            let mut _ic_set_29: HashSet<POSITION> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_gr_1 in self.gears.domain().clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if (((((((self.doors.functionCall(&_ic_gr_1).equal(&/*enum_call*/DOOR_STATE::door_moving) && self.gears.functionCall(&_ic_gr_1).unequal(&/*enum_call*/GEAR_STATE::gear_moving)) && self.gears.range().notElementOf(&/*enum_call*/GEAR_STATE::gear_moving)) && self.doors.relationImage(&self._POSITION.difference(&bset![POSITION, _ic_gr_1])).unequal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::closed])) && ((self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && (self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted]) || self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended]))) || (self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])))) && self.valve_close_door.equal(&/*enum_call*/VALVE_STATE::valve_open)) && (self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])).implies(|| self.shock_absorber.equal(&/*enum_call*/PLANE_STATE::ground))) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open)) {
                    _ic_set_29.insert(_ic_gr_1);
                }

            }
            self._tr_cache_env_close_door_skip = Option::Some(_ic_set_29.clone());
            return _ic_set_29;
        } else {
            return self._tr_cache_env_close_door_skip.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_toggle_handle_up(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_toggle_handle_up.is_none() {
            let mut __tmp__val__ = self.handle.equal(&/*enum_call*/HANDLE_STATE::down);
            self._tr_cache_toggle_handle_up = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_toggle_handle_up.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_toggle_handle_down(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_toggle_handle_down.is_none() {
            let mut __tmp__val__ = self.handle.equal(&/*enum_call*/HANDLE_STATE::up);
            self._tr_cache_toggle_handle_down = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_toggle_handle_down.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stimulate_general_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stimulate_general_valve.is_none() {
            let mut __tmp__val__ = (self.general_EV.equal(&false) && self.handle_move.equal(&true));
            self._tr_cache_con_stimulate_general_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stimulate_general_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stop_stimulate_general_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stop_stimulate_general_valve.is_none() {
            let mut __tmp__val__ = ((((((self.general_EV.equal(&true) && self.open_EV.equal(&false)) && self.close_EV.equal(&false)) && self.retract_EV.equal(&false)) && self.extend_EV.equal(&false)) && self.close_EV.equal(&false)) && (((((self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted])) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::closed])) && self.open_EV.equal(&false)) || (((self.handle.equal(&/*enum_call*/HANDLE_STATE::down) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::closed])) && self.open_EV.equal(&false))) || (((self.handle.equal(&/*enum_call*/HANDLE_STATE::up) && self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended])) && self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::closed])) && self.open_EV.equal(&false))));
            self._tr_cache_con_stop_stimulate_general_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stop_stimulate_general_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_evn_open_general_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_evn_open_general_valve.is_none() {
            let mut __tmp__val__ = ((self.general_EV.equal(&true) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_closed)) && self.analogical_switch.equal(&/*enum_call*/SWITCH_STATE::switch_closed));
            self._tr_cache_evn_open_general_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_evn_open_general_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_evn_close_general_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_evn_close_general_valve.is_none() {
            let mut __tmp__val__ = ((self.general_EV.equal(&false) || self.analogical_switch.equal(&/*enum_call*/SWITCH_STATE::switch_open)) && self.general_valve.equal(&/*enum_call*/VALVE_STATE::valve_open));
            self._tr_cache_evn_close_general_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_evn_close_general_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_close_analogical_switch(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_env_close_analogical_switch.is_none() {
            let mut __tmp__val__ = (self.analogical_switch.equal(&/*enum_call*/SWITCH_STATE::switch_open) && self.handle_move.equal(&true));
            self._tr_cache_env_close_analogical_switch = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_env_close_analogical_switch.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_open_analogical_switch(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_env_open_analogical_switch.is_none() {
            let mut __tmp__val__ = self.analogical_switch.equal(&/*enum_call*/SWITCH_STATE::switch_closed);
            self._tr_cache_env_open_analogical_switch = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_env_open_analogical_switch.as_ref().unwrap().clone();
        }
    }

    pub fn _check_inv_1(&self) -> bool {
        //invariant
        return self._SWITCH_STATE.elementOf(&self.analogical_switch);
    }

    pub fn _check_inv_2(&self) -> bool {
        //invariant
        return BOOL.elementOf(&self.general_EV);
    }

    pub fn _check_inv_3(&self) -> bool {
        //invariant
        return self._VALVE_STATE.elementOf(&self.general_valve);
    }

    pub fn _check_inv_4(&self) -> bool {
        //invariant
        return BOOL.elementOf(&self.handle_move);
    }

    pub fn _check_inv_5(&self) -> bool {
        //invariant
        return BOOL.elementOf(&self.close_EV);
    }

    pub fn _check_inv_6(&self) -> bool {
        //invariant
        return BOOL.elementOf(&self.extend_EV);
    }

    pub fn _check_inv_7(&self) -> bool {
        //invariant
        return BOOL.elementOf(&self.open_EV);
    }

    pub fn _check_inv_8(&self) -> bool {
        //invariant
        return BOOL.elementOf(&self.retract_EV);
    }

    pub fn _check_inv_9(&self) -> bool {
        //invariant
        return self._PLANE_STATE.elementOf(&self.shock_absorber);
    }

    pub fn _check_inv_10(&self) -> bool {
        //invariant
        return self._VALVE_STATE.elementOf(&self.valve_close_door);
    }

    pub fn _check_inv_11(&self) -> bool {
        //invariant
        return self._VALVE_STATE.elementOf(&self.valve_extend_gear);
    }

    pub fn _check_inv_12(&self) -> bool {
        //invariant
        return self._VALVE_STATE.elementOf(&self.valve_open_door);
    }

    pub fn _check_inv_13(&self) -> bool {
        //invariant
        return self._VALVE_STATE.elementOf(&self.valve_retract_gear);
    }

    pub fn _check_inv_14(&self) -> bool {
        //invariant
        return self._HANDLE_STATE.elementOf(&self.handle);
    }

    pub fn _check_inv_15(&self) -> bool {
        //invariant
        return self._DOOR_STATE.elementOf(&self.door);
    }

    pub fn _check_inv_16(&self) -> bool {
        //invariant
        return self._GEAR_STATE.elementOf(&self.gear);
    }

    pub fn _check_inv_17(&self) -> bool {
        //invariant
        return (((self.open_EV.equal(&true) || self.close_EV.equal(&true)) || self.retract_EV.equal(&true)) || self.extend_EV.equal(&true)).implies(|| self.general_EV.equal(&true));
    }

    pub fn _check_inv_18(&self) -> bool {
        //invariant
        return (self.open_EV.equal(&true) && self.close_EV.equal(&true)).not();
    }

    pub fn _check_inv_19(&self) -> bool {
        //invariant
        return self._POSITION.check_domain_of(&self.gears).and(&self._GEAR_STATE.check_range_of(&self.gears)).and(&self.gears.isFunction()).and(&self._POSITION.check_total_of(&self.gears));
    }

    pub fn _check_inv_20(&self) -> bool {
        //invariant
        return self._POSITION.check_domain_of(&self.doors).and(&self._DOOR_STATE.check_range_of(&self.doors)).and(&self.doors.isFunction()).and(&self._POSITION.check_total_of(&self.doors));
    }

    pub fn _check_inv_21(&self) -> bool {
        //invariant
        return self.door.equal(&/*enum_call*/DOOR_STATE::closed).equivalent(&self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::closed]));
    }

    pub fn _check_inv_22(&self) -> bool {
        //invariant
        return self.door.equal(&/*enum_call*/DOOR_STATE::open).equivalent(&self.doors.range().equal(&bset![DOOR_STATE, /*enum_call*/DOOR_STATE::open]));
    }

    pub fn _check_inv_23(&self) -> bool {
        //invariant
        return self.gear.equal(&/*enum_call*/GEAR_STATE::extended).equivalent(&self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::extended]));
    }

    pub fn _check_inv_24(&self) -> bool {
        //invariant
        return self.gear.equal(&/*enum_call*/GEAR_STATE::retracted).equivalent(&self.gears.range().equal(&bset![GEAR_STATE, /*enum_call*/GEAR_STATE::retracted]));
    }

    pub fn _check_inv_25(&self) -> bool {
        //invariant
        return self.gear.equal(&/*enum_call*/GEAR_STATE::gear_moving).implies(|| self.door.equal(&/*enum_call*/DOOR_STATE::open));
    }

    fn invalidate_caches(&mut self, to_invalidate: Vec<&'static str>) {
        //calling the given functions without caching will recalculate them and cache them afterwards
        for trans in to_invalidate {
            match trans {
                "_tr_begin_flying" => {self._tr_begin_flying(false);},
                "_tr_land_plane" => {self._tr_land_plane(false);},
                "_tr_open_valve_door_open" => {self._tr_open_valve_door_open(false);},
                "_tr_close_valve_door_open" => {self._tr_close_valve_door_open(false);},
                "_tr_open_valve_door_close" => {self._tr_open_valve_door_close(false);},
                "_tr_close_valve_door_close" => {self._tr_close_valve_door_close(false);},
                "_tr_open_valve_retract_gear" => {self._tr_open_valve_retract_gear(false);},
                "_tr_close_valve_retract_gear" => {self._tr_close_valve_retract_gear(false);},
                "_tr_open_valve_extend_gear" => {self._tr_open_valve_extend_gear(false);},
                "_tr_close_valve_extend_gear" => {self._tr_close_valve_extend_gear(false);},
                "_tr_con_stimulate_open_door_valve" => {self._tr_con_stimulate_open_door_valve(false);},
                "_tr_con_stop_stimulate_open_door_valve" => {self._tr_con_stop_stimulate_open_door_valve(false);},
                "_tr_con_stimulate_close_door_valve" => {self._tr_con_stimulate_close_door_valve(false);},
                "_tr_con_stop_stimulate_close_door_valve" => {self._tr_con_stop_stimulate_close_door_valve(false);},
                "_tr_con_stimulate_retract_gear_valve" => {self._tr_con_stimulate_retract_gear_valve(false);},
                "_tr_con_stop_stimulate_retract_gear_valve" => {self._tr_con_stop_stimulate_retract_gear_valve(false);},
                "_tr_con_stimulate_extend_gear_valve" => {self._tr_con_stimulate_extend_gear_valve(false);},
                "_tr_con_stop_stimulate_extend_gear_valve" => {self._tr_con_stop_stimulate_extend_gear_valve(false);},
                "_tr_env_start_retracting_first" => {self._tr_env_start_retracting_first(false);},
                "_tr_env_retract_gear_skip" => {self._tr_env_retract_gear_skip(false);},
                "_tr_env_retract_gear_last" => {self._tr_env_retract_gear_last(false);},
                "_tr_env_start_extending" => {self._tr_env_start_extending(false);},
                "_tr_env_extend_gear_last" => {self._tr_env_extend_gear_last(false);},
                "_tr_env_extend_gear_skip" => {self._tr_env_extend_gear_skip(false);},
                "_tr_env_start_open_door" => {self._tr_env_start_open_door(false);},
                "_tr_env_open_door_last" => {self._tr_env_open_door_last(false);},
                "_tr_env_open_door_skip" => {self._tr_env_open_door_skip(false);},
                "_tr_env_start_close_door" => {self._tr_env_start_close_door(false);},
                "_tr_env_close_door" => {self._tr_env_close_door(false);},
                "_tr_env_close_door_skip" => {self._tr_env_close_door_skip(false);},
                "_tr_toggle_handle_up" => {self._tr_toggle_handle_up(false);},
                "_tr_toggle_handle_down" => {self._tr_toggle_handle_down(false);},
                "_tr_con_stimulate_general_valve" => {self._tr_con_stimulate_general_valve(false);},
                "_tr_con_stop_stimulate_general_valve" => {self._tr_con_stop_stimulate_general_valve(false);},
                "_tr_evn_open_general_valve" => {self._tr_evn_open_general_valve(false);},
                "_tr_evn_close_general_valve" => {self._tr_evn_close_general_valve(false);},
                "_tr_env_close_analogical_switch" => {self._tr_env_close_analogical_switch(false);},
                "_tr_env_open_analogical_switch" => {self._tr_env_open_analogical_switch(false);},
                _ => {},
            }
        }
    }

    //model_check_next_states
    fn generateNextStates(state: &mut LandingGear_R6,
                          isCaching: bool,
                          transitions: Arc<AtomicU64>) -> HashSet<(LandingGear_R6, &'static str)> {
        let mut result = HashSet::<(LandingGear_R6, &'static str)>::new();
        let mut evaluated_transitions: u64 = 0;
        //model_check_transition
        if state._tr_begin_flying(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.begin_flying();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("begin_flying")); }
            result.insert((copiedState, "begin_flying"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_land_plane(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.land_plane();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("land_plane")); }
            result.insert((copiedState, "land_plane"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_open_valve_door_open(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.open_valve_door_open();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("open_valve_door_open")); }
            result.insert((copiedState, "open_valve_door_open"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_close_valve_door_open(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.close_valve_door_open();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("close_valve_door_open")); }
            result.insert((copiedState, "close_valve_door_open"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_open_valve_door_close(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.open_valve_door_close();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("open_valve_door_close")); }
            result.insert((copiedState, "open_valve_door_close"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_close_valve_door_close(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.close_valve_door_close();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("close_valve_door_close")); }
            result.insert((copiedState, "close_valve_door_close"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_open_valve_retract_gear(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.open_valve_retract_gear();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("open_valve_retract_gear")); }
            result.insert((copiedState, "open_valve_retract_gear"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_close_valve_retract_gear(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.close_valve_retract_gear();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("close_valve_retract_gear")); }
            result.insert((copiedState, "close_valve_retract_gear"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_open_valve_extend_gear(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.open_valve_extend_gear();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("open_valve_extend_gear")); }
            result.insert((copiedState, "open_valve_extend_gear"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_close_valve_extend_gear(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.close_valve_extend_gear();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("close_valve_extend_gear")); }
            result.insert((copiedState, "close_valve_extend_gear"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_con_stimulate_open_door_valve(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.con_stimulate_open_door_valve();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("con_stimulate_open_door_valve")); }
            result.insert((copiedState, "con_stimulate_open_door_valve"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_con_stop_stimulate_open_door_valve(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.con_stop_stimulate_open_door_valve();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("con_stop_stimulate_open_door_valve")); }
            result.insert((copiedState, "con_stop_stimulate_open_door_valve"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_con_stimulate_close_door_valve(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.con_stimulate_close_door_valve();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("con_stimulate_close_door_valve")); }
            result.insert((copiedState, "con_stimulate_close_door_valve"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_con_stop_stimulate_close_door_valve(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.con_stop_stimulate_close_door_valve();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("con_stop_stimulate_close_door_valve")); }
            result.insert((copiedState, "con_stop_stimulate_close_door_valve"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_con_stimulate_retract_gear_valve(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.con_stimulate_retract_gear_valve();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("con_stimulate_retract_gear_valve")); }
            result.insert((copiedState, "con_stimulate_retract_gear_valve"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_con_stop_stimulate_retract_gear_valve(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.con_stop_stimulate_retract_gear_valve();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("con_stop_stimulate_retract_gear_valve")); }
            result.insert((copiedState, "con_stop_stimulate_retract_gear_valve"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_con_stimulate_extend_gear_valve(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.con_stimulate_extend_gear_valve();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("con_stimulate_extend_gear_valve")); }
            result.insert((copiedState, "con_stimulate_extend_gear_valve"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_con_stop_stimulate_extend_gear_valve(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.con_stop_stimulate_extend_gear_valve();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("con_stop_stimulate_extend_gear_valve")); }
            result.insert((copiedState, "con_stop_stimulate_extend_gear_valve"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_19 = state._tr_env_start_retracting_first(isCaching);
        for param in _trid_19.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.env_start_retracting_first(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("env_start_retracting_first")); }
            result.insert((copiedState, "env_start_retracting_first"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_20 = state._tr_env_retract_gear_skip(isCaching);
        for param in _trid_20.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.env_retract_gear_skip(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("env_retract_gear_skip")); }
            result.insert((copiedState, "env_retract_gear_skip"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_21 = state._tr_env_retract_gear_last(isCaching);
        for param in _trid_21.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.env_retract_gear_last(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("env_retract_gear_last")); }
            result.insert((copiedState, "env_retract_gear_last"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_22 = state._tr_env_start_extending(isCaching);
        for param in _trid_22.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.env_start_extending(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("env_start_extending")); }
            result.insert((copiedState, "env_start_extending"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_23 = state._tr_env_extend_gear_last(isCaching);
        for param in _trid_23.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.env_extend_gear_last(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("env_extend_gear_last")); }
            result.insert((copiedState, "env_extend_gear_last"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_24 = state._tr_env_extend_gear_skip(isCaching);
        for param in _trid_24.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.env_extend_gear_skip(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("env_extend_gear_skip")); }
            result.insert((copiedState, "env_extend_gear_skip"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_25 = state._tr_env_start_open_door(isCaching);
        for param in _trid_25.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.env_start_open_door(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("env_start_open_door")); }
            result.insert((copiedState, "env_start_open_door"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_26 = state._tr_env_open_door_last(isCaching);
        for param in _trid_26.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.env_open_door_last(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("env_open_door_last")); }
            result.insert((copiedState, "env_open_door_last"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_27 = state._tr_env_open_door_skip(isCaching);
        for param in _trid_27.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.env_open_door_skip(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("env_open_door_skip")); }
            result.insert((copiedState, "env_open_door_skip"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_28 = state._tr_env_start_close_door(isCaching);
        for param in _trid_28.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.env_start_close_door(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("env_start_close_door")); }
            result.insert((copiedState, "env_start_close_door"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_29 = state._tr_env_close_door(isCaching);
        for param in _trid_29.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.env_close_door(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("env_close_door")); }
            result.insert((copiedState, "env_close_door"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_30 = state._tr_env_close_door_skip(isCaching);
        for param in _trid_30.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.env_close_door_skip(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("env_close_door_skip")); }
            result.insert((copiedState, "env_close_door_skip"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_toggle_handle_up(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.toggle_handle_up();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("toggle_handle_up")); }
            result.insert((copiedState, "toggle_handle_up"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_toggle_handle_down(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.toggle_handle_down();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("toggle_handle_down")); }
            result.insert((copiedState, "toggle_handle_down"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_con_stimulate_general_valve(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.con_stimulate_general_valve();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("con_stimulate_general_valve")); }
            result.insert((copiedState, "con_stimulate_general_valve"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_con_stop_stimulate_general_valve(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.con_stop_stimulate_general_valve();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("con_stop_stimulate_general_valve")); }
            result.insert((copiedState, "con_stop_stimulate_general_valve"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_evn_open_general_valve(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.evn_open_general_valve();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("evn_open_general_valve")); }
            result.insert((copiedState, "evn_open_general_valve"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_evn_close_general_valve(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.evn_close_general_valve();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("evn_close_general_valve")); }
            result.insert((copiedState, "evn_close_general_valve"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_env_close_analogical_switch(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.env_close_analogical_switch();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("env_close_analogical_switch")); }
            result.insert((copiedState, "env_close_analogical_switch"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_env_open_analogical_switch(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.env_open_analogical_switch();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("env_open_analogical_switch")); }
            result.insert((copiedState, "env_open_analogical_switch"));
            evaluated_transitions += 1;
        }


        transitions.fetch_add(evaluated_transitions, Ordering::AcqRel);
        return result;
    }

    //model_check_invariants
    pub fn checkInvariants(state: &LandingGear_R6, last_op: &'static str, isCaching: bool) -> bool {
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
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_21") {
                if !state._check_inv_21() {
                    println!("_check_inv_21 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_22") {
                if !state._check_inv_22() {
                    println!("_check_inv_22 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_23") {
                if !state._check_inv_23() {
                    println!("_check_inv_23 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_24") {
                if !state._check_inv_24() {
                    println!("_check_inv_24 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_25") {
                if !state._check_inv_25() {
                    println!("_check_inv_25 failed!");
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6() || !state._check_inv_7() || !state._check_inv_8() || !state._check_inv_9() || !state._check_inv_10() || !state._check_inv_11() || !state._check_inv_12() || !state._check_inv_13() || !state._check_inv_14() || !state._check_inv_15() || !state._check_inv_16() || !state._check_inv_17() || !state._check_inv_18() || !state._check_inv_19() || !state._check_inv_20() || !state._check_inv_21() || !state._check_inv_22() || !state._check_inv_23() || !state._check_inv_24() || !state._check_inv_25());
    }

    //model_check_print
    fn print_result(states: usize, transitions: u64, error_detected: bool) {
        if !error_detected { println!("MODEL CHECKING SUCCESSFUL"); }
        println!("Number of States: {}", states);
        println!("Number of Transitions: {}", transitions);
    }

    //model_check_main
    fn next(collection_m: Arc<Mutex<LinkedList<(LandingGear_R6, &'static str)>>>, mc_type: MC_TYPE) -> (LandingGear_R6, &'static str) {
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
            "close_valve_door_close" => vec!["_tr_open_valve_door_close", "_tr_env_close_door_skip", "_tr_env_start_close_door", "_tr_env_close_door", "_tr_close_valve_door_close"],
            //model_check_init_static
            "close_valve_retract_gear" => vec!["_tr_close_valve_retract_gear", "_tr_open_valve_retract_gear", "_tr_env_start_retracting_first"],
            //model_check_init_static
            "con_stimulate_open_door_valve" => vec!["_tr_open_valve_door_open", "_tr_con_stimulate_extend_gear_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_open"],
            //model_check_init_static
            "env_close_door" => vec!["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"],
            //model_check_init_static
            "env_start_close_door" => vec!["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"],
            //model_check_init_static
            "toggle_handle_up" => vec!["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_close_analogical_switch", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip", "_tr_con_stimulate_general_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_toggle_handle_down", "_tr_env_open_door_last", "_tr_toggle_handle_up", "_tr_env_start_close_door", "_tr_con_stop_stimulate_close_door_valve"],
            //model_check_init_static
            "toggle_handle_down" => vec!["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_close_analogical_switch", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip", "_tr_con_stimulate_general_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_toggle_handle_down", "_tr_env_open_door_last", "_tr_toggle_handle_up", "_tr_env_start_close_door", "_tr_con_stop_stimulate_close_door_valve"],
            //model_check_init_static
            "open_valve_door_open" => vec!["_tr_open_valve_door_open", "_tr_env_open_door_last", "_tr_env_start_open_door", "_tr_env_open_door_skip", "_tr_close_valve_door_open"],
            //model_check_init_static
            "env_retract_gear_last" => vec!["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"],
            //model_check_init_static
            "env_open_door_last" => vec!["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"],
            //model_check_init_static
            "con_stop_stimulate_retract_gear_valve" => vec!["_tr_close_valve_retract_gear", "_tr_con_stimulate_extend_gear_valve", "_tr_open_valve_retract_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_retract_gear_valve"],
            //model_check_init_static
            "env_close_door_skip" => vec!["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"],
            //model_check_init_static
            "con_stop_stimulate_close_door_valve" => vec!["_tr_open_valve_door_close", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_close"],
            //model_check_init_static
            "env_open_analogical_switch" => vec!["_tr_env_open_analogical_switch", "_tr_evn_open_general_valve", "_tr_env_close_analogical_switch", "_tr_evn_close_general_valve"],
            //model_check_init_static
            "con_stop_stimulate_general_valve" => vec!["_tr_con_stimulate_extend_gear_valve", "_tr_con_stimulate_general_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_evn_open_general_valve", "_tr_env_close_analogical_switch", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_evn_close_general_valve", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve"],
            //model_check_init_static
            "env_extend_gear_last" => vec!["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"],
            //model_check_init_static
            "evn_open_general_valve" => vec!["_tr_env_retract_gear_last", "_tr_env_close_door_skip", "_tr_evn_open_general_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_evn_close_general_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"],
            //model_check_init_static
            "land_plane" => vec!["_tr_land_plane", "_tr_begin_flying", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_close_door"],
            //model_check_init_static
            "con_stimulate_retract_gear_valve" => vec!["_tr_close_valve_retract_gear", "_tr_con_stimulate_extend_gear_valve", "_tr_open_valve_retract_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_retract_gear_valve"],
            //model_check_init_static
            "con_stimulate_general_valve" => vec!["_tr_con_stimulate_extend_gear_valve", "_tr_con_stimulate_general_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_evn_open_general_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_evn_close_general_valve", "_tr_con_stop_stimulate_retract_gear_valve"],
            //model_check_init_static
            "env_start_retracting_first" => vec!["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"],
            //model_check_init_static
            "env_retract_gear_skip" => vec!["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"],
            //model_check_init_static
            "open_valve_extend_gear" => vec!["_tr_close_valve_extend_gear", "_tr_open_valve_extend_gear", "_tr_env_start_extending"],
            //model_check_init_static
            "begin_flying" => vec!["_tr_land_plane", "_tr_begin_flying", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_close_door"],
            //model_check_init_static
            "open_valve_retract_gear" => vec!["_tr_close_valve_retract_gear", "_tr_open_valve_retract_gear", "_tr_env_start_retracting_first"],
            //model_check_init_static
            "env_close_analogical_switch" => vec!["_tr_env_open_analogical_switch", "_tr_evn_open_general_valve", "_tr_env_close_analogical_switch", "_tr_evn_close_general_valve"],
            //model_check_init_static
            "env_start_extending" => vec!["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"],
            //model_check_init_static
            "open_valve_door_close" => vec!["_tr_open_valve_door_close", "_tr_env_close_door_skip", "_tr_env_start_close_door", "_tr_env_close_door", "_tr_close_valve_door_close"],
            //model_check_init_static
            "con_stop_stimulate_open_door_valve" => vec!["_tr_open_valve_door_open", "_tr_con_stimulate_extend_gear_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_open"],
            //model_check_init_static
            "con_stop_stimulate_extend_gear_valve" => vec!["_tr_con_stimulate_extend_gear_valve", "_tr_close_valve_extend_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_open_valve_extend_gear", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_extend_gear_valve"],
            //model_check_init_static
            "evn_close_general_valve" => vec!["_tr_env_retract_gear_last", "_tr_env_close_door_skip", "_tr_evn_open_general_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_evn_close_general_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"],
            //model_check_init_static
            "close_valve_extend_gear" => vec!["_tr_close_valve_extend_gear", "_tr_open_valve_extend_gear", "_tr_env_start_extending"],
            //model_check_init_static
            "con_stimulate_extend_gear_valve" => vec!["_tr_con_stimulate_extend_gear_valve", "_tr_close_valve_extend_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_open_valve_extend_gear", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_extend_gear_valve"],
            //model_check_init_static
            "close_valve_door_open" => vec!["_tr_open_valve_door_open", "_tr_env_open_door_last", "_tr_env_start_open_door", "_tr_env_open_door_skip", "_tr_close_valve_door_open"],
            //model_check_init_static
            "con_stimulate_close_door_valve" => vec!["_tr_open_valve_door_close", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_close"],
            //model_check_init_static
            "env_extend_gear_skip" => vec!["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"],
            //model_check_init_static
            "env_open_door_skip" => vec!["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"],
            //model_check_init_static
            "env_start_open_door" => vec!["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"],
            _ => vec![],
        }
    }

    fn get_invariant_dependencies(op: &'static str) -> Vec<&str> {
        return match op {
            //model_check_init_static
            "close_valve_door_close" => vec!["_check_inv_10"],
            //model_check_init_static
            "close_valve_retract_gear" => vec!["_check_inv_13"],
            //model_check_init_static
            "con_stimulate_open_door_valve" => vec!["_check_inv_18", "_check_inv_17", "_check_inv_7"],
            //model_check_init_static
            "env_close_door" => vec!["_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22"],
            //model_check_init_static
            "env_start_close_door" => vec!["_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22"],
            //model_check_init_static
            "toggle_handle_up" => vec!["_check_inv_4", "_check_inv_14"],
            //model_check_init_static
            "toggle_handle_down" => vec!["_check_inv_4", "_check_inv_14"],
            //model_check_init_static
            "open_valve_door_open" => vec!["_check_inv_12"],
            //model_check_init_static
            "env_retract_gear_last" => vec!["_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23"],
            //model_check_init_static
            "env_open_door_last" => vec!["_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22"],
            //model_check_init_static
            "con_stop_stimulate_retract_gear_valve" => vec!["_check_inv_17", "_check_inv_8"],
            //model_check_init_static
            "env_close_door_skip" => vec!["_check_inv_21", "_check_inv_20", "_check_inv_22"],
            //model_check_init_static
            "con_stop_stimulate_close_door_valve" => vec!["_check_inv_18", "_check_inv_17", "_check_inv_5"],
            //model_check_init_static
            "env_open_analogical_switch" => vec!["_check_inv_1"],
            //model_check_init_static
            "con_stop_stimulate_general_valve" => vec!["_check_inv_17", "_check_inv_2", "_check_inv_4"],
            //model_check_init_static
            "env_extend_gear_last" => vec!["_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23"],
            //model_check_init_static
            "evn_open_general_valve" => vec!["_check_inv_3"],
            //model_check_init_static
            "land_plane" => vec!["_check_inv_9"],
            //model_check_init_static
            "con_stimulate_retract_gear_valve" => vec!["_check_inv_17", "_check_inv_8"],
            //model_check_init_static
            "con_stimulate_general_valve" => vec!["_check_inv_17", "_check_inv_2"],
            //model_check_init_static
            "env_start_retracting_first" => vec!["_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23"],
            //model_check_init_static
            "env_retract_gear_skip" => vec!["_check_inv_19", "_check_inv_24", "_check_inv_23"],
            //model_check_init_static
            "open_valve_extend_gear" => vec!["_check_inv_11"],
            //model_check_init_static
            "begin_flying" => vec!["_check_inv_9"],
            //model_check_init_static
            "open_valve_retract_gear" => vec!["_check_inv_13"],
            //model_check_init_static
            "env_close_analogical_switch" => vec!["_check_inv_1"],
            //model_check_init_static
            "env_start_extending" => vec!["_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23"],
            //model_check_init_static
            "open_valve_door_close" => vec!["_check_inv_10"],
            //model_check_init_static
            "con_stop_stimulate_open_door_valve" => vec!["_check_inv_18", "_check_inv_17", "_check_inv_7"],
            //model_check_init_static
            "con_stop_stimulate_extend_gear_valve" => vec!["_check_inv_17", "_check_inv_6"],
            //model_check_init_static
            "evn_close_general_valve" => vec!["_check_inv_3"],
            //model_check_init_static
            "close_valve_extend_gear" => vec!["_check_inv_11"],
            //model_check_init_static
            "con_stimulate_extend_gear_valve" => vec!["_check_inv_17", "_check_inv_6"],
            //model_check_init_static
            "close_valve_door_open" => vec!["_check_inv_12"],
            //model_check_init_static
            "con_stimulate_close_door_valve" => vec!["_check_inv_18", "_check_inv_17", "_check_inv_5"],
            //model_check_init_static
            "env_extend_gear_skip" => vec!["_check_inv_19", "_check_inv_24", "_check_inv_23"],
            //model_check_init_static
            "env_open_door_skip" => vec!["_check_inv_21", "_check_inv_20", "_check_inv_22"],
            //model_check_init_static
            "env_start_open_door" => vec!["_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22"],
            _ => vec![],
        }
    }

    fn model_check_single_threaded(mc_type: MC_TYPE, is_caching: bool, no_dead: bool, no_inv: bool) {
        let mut machine = LandingGear_R6::new();

        let mut all_states = HashSet::<LandingGear_R6>::new();
        all_states.insert(machine.clone());

        let states_to_process_mutex = Arc::new(Mutex::new(LinkedList::<(LandingGear_R6, &'static str)>::new()));
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

        let machine = LandingGear_R6::new();

        let all_states = Arc::new(DashSet::<LandingGear_R6>::new());
        all_states.insert(machine.clone());

        let states_to_process_mutex = Arc::new(Mutex::new(LinkedList::<(LandingGear_R6, &'static str)>::new()));
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
        LandingGear_R6::model_check_single_threaded(mc_type, is_caching, no_dead, no_inv);
    } else {
        LandingGear_R6::modelCheckMultiThreaded(mc_type, threads, is_caching, no_dead, no_inv);
    }
}