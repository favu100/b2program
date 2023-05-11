#![ allow( dead_code, unused, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::env;
use std::sync::atomic::{AtomicU64, Ordering};
use std::sync::{Arc, mpsc, Mutex};
use std::collections::{HashSet, LinkedList};
use dashmap::DashSet;
use threadpool::ThreadPool;
use std::sync::mpsc::channel;
use derivative::Derivative;
use std::time::{Duration};
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::bobject;
use btypes::bboolean::{IntoBool, BBooleanT};
use btypes::bboolean::BBoolean;
use btypes::brelation::BRelation;
use btypes::bset::BSet;
use btypes::bobject::BObject;
use btypes::btuple::BTuple;

#[derive(Clone, Copy)]
pub enum MC_TYPE { BFS, DFS, MIXED }


#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum DOOR_STATE {
    open, 
    closed, 
    door_moving
}
impl DOOR_STATE {
    pub fn equal(&self, other: &DOOR_STATE) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &DOOR_STATE) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for DOOR_STATE {}
impl Default for DOOR_STATE {
    fn default() -> Self { DOOR_STATE::open }
}
impl fmt::Display for DOOR_STATE {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           DOOR_STATE::open => write!(f, "open"),
           DOOR_STATE::closed => write!(f, "closed"),
           DOOR_STATE::door_moving => write!(f, "door_moving"),
       }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum GEAR_STATE {
    retracted, 
    extended, 
    gear_moving
}
impl GEAR_STATE {
    pub fn equal(&self, other: &GEAR_STATE) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &GEAR_STATE) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for GEAR_STATE {}
impl Default for GEAR_STATE {
    fn default() -> Self { GEAR_STATE::retracted }
}
impl fmt::Display for GEAR_STATE {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           GEAR_STATE::retracted => write!(f, "retracted"),
           GEAR_STATE::extended => write!(f, "extended"),
           GEAR_STATE::gear_moving => write!(f, "gear_moving"),
       }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum HANDLE_STATE {
    up, 
    down
}
impl HANDLE_STATE {
    pub fn equal(&self, other: &HANDLE_STATE) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &HANDLE_STATE) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for HANDLE_STATE {}
impl Default for HANDLE_STATE {
    fn default() -> Self { HANDLE_STATE::up }
}
impl fmt::Display for HANDLE_STATE {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           HANDLE_STATE::up => write!(f, "up"),
           HANDLE_STATE::down => write!(f, "down"),
       }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum POSITION {
    fr, 
    lt, 
    rt
}
impl POSITION {
    pub fn equal(&self, other: &POSITION) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &POSITION) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for POSITION {}
impl Default for POSITION {
    fn default() -> Self { POSITION::fr }
}
impl fmt::Display for POSITION {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           POSITION::fr => write!(f, "fr"),
           POSITION::lt => write!(f, "lt"),
           POSITION::rt => write!(f, "rt"),
       }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum SWITCH_STATE {
    switch_open, 
    switch_closed
}
impl SWITCH_STATE {
    pub fn equal(&self, other: &SWITCH_STATE) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &SWITCH_STATE) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for SWITCH_STATE {}
impl Default for SWITCH_STATE {
    fn default() -> Self { SWITCH_STATE::switch_open }
}
impl fmt::Display for SWITCH_STATE {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           SWITCH_STATE::switch_open => write!(f, "switch_open"),
           SWITCH_STATE::switch_closed => write!(f, "switch_closed"),
       }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum PLANE_STATE {
    ground, 
    flight
}
impl PLANE_STATE {
    pub fn equal(&self, other: &PLANE_STATE) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &PLANE_STATE) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for PLANE_STATE {}
impl Default for PLANE_STATE {
    fn default() -> Self { PLANE_STATE::ground }
}
impl fmt::Display for PLANE_STATE {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           PLANE_STATE::ground => write!(f, "ground"),
           PLANE_STATE::flight => write!(f, "flight"),
       }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum VALVE_STATE {
    valve_open, 
    valve_closed
}
impl VALVE_STATE {
    pub fn equal(&self, other: &VALVE_STATE) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &VALVE_STATE) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for VALVE_STATE {}
impl Default for VALVE_STATE {
    fn default() -> Self { VALVE_STATE::valve_open }
}
impl fmt::Display for VALVE_STATE {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           VALVE_STATE::valve_open => write!(f, "valve_open"),
           VALVE_STATE::valve_closed => write!(f, "valve_closed"),
       }
    }
}

#[derive(Derivative)]
#[derivative(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct LandingGear_R6 {
    analogical_switch: SWITCH_STATE,
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
    doors: BRelation<POSITION, DOOR_STATE>,
    gears: BRelation<POSITION, GEAR_STATE>,
    handle: HANDLE_STATE,
    door: DOOR_STATE,
    gear: GEAR_STATE,
    _DOOR_STATE: BSet<DOOR_STATE>,
    _GEAR_STATE: BSet<GEAR_STATE>,
    _HANDLE_STATE: BSet<HANDLE_STATE>,
    _POSITION: BSet<POSITION>,
    _SWITCH_STATE: BSet<SWITCH_STATE>,
    _PLANE_STATE: BSet<PLANE_STATE>,
    _VALVE_STATE: BSet<VALVE_STATE>,
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
    _tr_cache_env_start_retracting_first: Option<BSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_retract_gear_skip: Option<BSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_retract_gear_last: Option<BSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_start_extending: Option<BSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_extend_gear_last: Option<BSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_extend_gear_skip: Option<BSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_start_open_door: Option<BSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_open_door_last: Option<BSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_open_door_skip: Option<BSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_start_close_door: Option<BSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_close_door: Option<BSet<POSITION>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_env_close_door_skip: Option<BSet<POSITION>>,
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

impl fmt::Display for LandingGear_R6 {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let mut result = "LandingGear_R6: (".to_owned();
        result += &format!("_get_analogical_switch: {}, ", self._get_analogical_switch());
        result += &format!("_get_general_EV: {}, ", self._get_general_EV());
        result += &format!("_get_general_valve: {}, ", self._get_general_valve());
        result += &format!("_get_handle_move: {}, ", self._get_handle_move());
        result += &format!("_get_close_EV: {}, ", self._get_close_EV());
        result += &format!("_get_extend_EV: {}, ", self._get_extend_EV());
        result += &format!("_get_open_EV: {}, ", self._get_open_EV());
        result += &format!("_get_retract_EV: {}, ", self._get_retract_EV());
        result += &format!("_get_shock_absorber: {}, ", self._get_shock_absorber());
        result += &format!("_get_valve_close_door: {}, ", self._get_valve_close_door());
        result += &format!("_get_valve_extend_gear: {}, ", self._get_valve_extend_gear());
        result += &format!("_get_valve_open_door: {}, ", self._get_valve_open_door());
        result += &format!("_get_valve_retract_gear: {}, ", self._get_valve_retract_gear());
        result += &format!("_get_doors: {}, ", self._get_doors());
        result += &format!("_get_gears: {}, ", self._get_gears());
        result += &format!("_get_handle: {}, ", self._get_handle());
        result += &format!("_get_door: {}, ", self._get_door());
        result += &format!("_get_gear: {}, ", self._get_gear());
        result = result + ")";
        return write!(f, "{}", result);
    }
}

impl LandingGear_R6 {

    pub fn new() -> LandingGear_R6 {
        //values: ''
        let mut m: LandingGear_R6 = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self._DOOR_STATE = BSet::new(vec![DOOR_STATE::open, DOOR_STATE::closed, DOOR_STATE::door_moving]);
        self._GEAR_STATE = BSet::new(vec![GEAR_STATE::retracted, GEAR_STATE::extended, GEAR_STATE::gear_moving]);
        self._HANDLE_STATE = BSet::new(vec![HANDLE_STATE::up, HANDLE_STATE::down]);
        self._POSITION = BSet::new(vec![POSITION::fr, POSITION::lt, POSITION::rt]);
        self._SWITCH_STATE = BSet::new(vec![SWITCH_STATE::switch_open, SWITCH_STATE::switch_closed]);
        self._PLANE_STATE = BSet::new(vec![PLANE_STATE::ground, PLANE_STATE::flight]);
        self._VALVE_STATE = BSet::new(vec![VALVE_STATE::valve_open, VALVE_STATE::valve_closed]);
        self.gears = BRelation::cartesianProduct(&self._POSITION, &BSet::new(vec![GEAR_STATE::extended.clone()])).clone().clone();
        self.doors = BRelation::cartesianProduct(&self._POSITION, &BSet::new(vec![DOOR_STATE::closed.clone()])).clone().clone();
        self.handle = HANDLE_STATE::down;
        self.valve_extend_gear = VALVE_STATE::valve_closed;
        self.valve_retract_gear = VALVE_STATE::valve_closed;
        self.valve_open_door = VALVE_STATE::valve_closed;
        self.valve_close_door = VALVE_STATE::valve_closed;
        self.open_EV = BBoolean::new(false);
        self.close_EV = BBoolean::new(false);
        self.retract_EV = BBoolean::new(false);
        self.extend_EV = BBoolean::new(false);
        self.shock_absorber = PLANE_STATE::ground;
        self.general_EV = BBoolean::new(false);
        self.general_valve = VALVE_STATE::valve_closed;
        self.analogical_switch = SWITCH_STATE::switch_open;
        self.handle_move = BBoolean::new(false);
        self.gear = GEAR_STATE::extended;
        self.door = DOOR_STATE::closed;
    }

    pub fn _get_analogical_switch(&self) -> SWITCH_STATE {
        return self.analogical_switch.clone();
    }

    pub fn _get_general_EV(&self) -> BBoolean {
        return self.general_EV.clone();
    }

    pub fn _get_general_valve(&self) -> VALVE_STATE {
        return self.general_valve.clone();
    }

    pub fn _get_handle_move(&self) -> BBoolean {
        return self.handle_move.clone();
    }

    pub fn _get_close_EV(&self) -> BBoolean {
        return self.close_EV.clone();
    }

    pub fn _get_extend_EV(&self) -> BBoolean {
        return self.extend_EV.clone();
    }

    pub fn _get_open_EV(&self) -> BBoolean {
        return self.open_EV.clone();
    }

    pub fn _get_retract_EV(&self) -> BBoolean {
        return self.retract_EV.clone();
    }

    pub fn _get_shock_absorber(&self) -> PLANE_STATE {
        return self.shock_absorber.clone();
    }

    pub fn _get_valve_close_door(&self) -> VALVE_STATE {
        return self.valve_close_door.clone();
    }

    pub fn _get_valve_extend_gear(&self) -> VALVE_STATE {
        return self.valve_extend_gear.clone();
    }

    pub fn _get_valve_open_door(&self) -> VALVE_STATE {
        return self.valve_open_door.clone();
    }

    pub fn _get_valve_retract_gear(&self) -> VALVE_STATE {
        return self.valve_retract_gear.clone();
    }

    pub fn _get_doors(&self) -> BRelation<POSITION, DOOR_STATE> {
        return self.doors.clone();
    }

    pub fn _get_gears(&self) -> BRelation<POSITION, GEAR_STATE> {
        return self.gears.clone();
    }

    pub fn _get_handle(&self) -> HANDLE_STATE {
        return self.handle.clone();
    }

    pub fn _get_door(&self) -> DOOR_STATE {
        return self.door.clone();
    }

    pub fn _get_gear(&self) -> GEAR_STATE {
        return self.gear.clone();
    }

    pub fn _get__DOOR_STATE(&self) -> BSet<DOOR_STATE> {
        return self._DOOR_STATE.clone();
    }

    pub fn _get__GEAR_STATE(&self) -> BSet<GEAR_STATE> {
        return self._GEAR_STATE.clone();
    }

    pub fn _get__HANDLE_STATE(&self) -> BSet<HANDLE_STATE> {
        return self._HANDLE_STATE.clone();
    }

    pub fn _get__POSITION(&self) -> BSet<POSITION> {
        return self._POSITION.clone();
    }

    pub fn _get__SWITCH_STATE(&self) -> BSet<SWITCH_STATE> {
        return self._SWITCH_STATE.clone();
    }

    pub fn _get__PLANE_STATE(&self) -> BSet<PLANE_STATE> {
        return self._PLANE_STATE.clone();
    }

    pub fn _get__VALVE_STATE(&self) -> BSet<VALVE_STATE> {
        return self._VALVE_STATE.clone();
    }

    pub fn begin_flying(&mut self) -> () {
        if (self.shock_absorber.equal(&PLANE_STATE::ground)).booleanValue() {
            self.shock_absorber = PLANE_STATE::flight;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn land_plane(&mut self) -> () {
        if (self.shock_absorber.equal(&PLANE_STATE::flight)).booleanValue() {
            self.shock_absorber = PLANE_STATE::ground;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn open_valve_door_open(&mut self) -> () {
        if ((self.valve_open_door.equal(&VALVE_STATE::valve_closed) && self.open_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.valve_open_door = VALVE_STATE::valve_open;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn close_valve_door_open(&mut self) -> () {
        if ((self.valve_open_door.equal(&VALVE_STATE::valve_open) && self.open_EV.equal(&BBoolean::new(false)))).booleanValue() {
            self.valve_open_door = VALVE_STATE::valve_closed;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn open_valve_door_close(&mut self) -> () {
        if ((self.valve_close_door.equal(&VALVE_STATE::valve_closed) && self.close_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.valve_close_door = VALVE_STATE::valve_open;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn close_valve_door_close(&mut self) -> () {
        if ((self.valve_close_door.equal(&VALVE_STATE::valve_open) && self.close_EV.equal(&BBoolean::new(false)))).booleanValue() {
            self.valve_close_door = VALVE_STATE::valve_closed;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn open_valve_retract_gear(&mut self) -> () {
        if ((self.valve_retract_gear.equal(&VALVE_STATE::valve_closed) && self.retract_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.valve_retract_gear = VALVE_STATE::valve_open;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn close_valve_retract_gear(&mut self) -> () {
        if ((self.valve_retract_gear.equal(&VALVE_STATE::valve_open) && self.retract_EV.equal(&BBoolean::new(false)))).booleanValue() {
            self.valve_retract_gear = VALVE_STATE::valve_closed;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn open_valve_extend_gear(&mut self) -> () {
        if ((self.valve_extend_gear.equal(&VALVE_STATE::valve_closed) && self.extend_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.valve_extend_gear = VALVE_STATE::valve_open;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn close_valve_extend_gear(&mut self) -> () {
        if ((self.valve_extend_gear.equal(&VALVE_STATE::valve_open) && self.extend_EV.equal(&BBoolean::new(false)))).booleanValue() {
            self.valve_extend_gear = VALVE_STATE::valve_closed;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stimulate_open_door_valve(&mut self) -> () {
        if ((((self.open_EV.equal(&BBoolean::new(false)) && self.close_EV.equal(&BBoolean::new(false))) && ((self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()])).not()) || ((self.handle.equal(&HANDLE_STATE::up) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()])).not()) && (self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open.clone()])) && self.shock_absorber.equal(&PLANE_STATE::ground)).not()))) && self.general_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.open_EV = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stop_stimulate_open_door_valve(&mut self) -> () {
        if (((((self.open_EV.equal(&BBoolean::new(true)) && self.extend_EV.equal(&BBoolean::new(false))) && self.retract_EV.equal(&BBoolean::new(false))) && ((self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))) || ((self.handle.equal(&HANDLE_STATE::up) && (self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()])) || self.shock_absorber.equal(&PLANE_STATE::ground))) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open.clone()]))))) && self.general_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.open_EV = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stimulate_close_door_valve(&mut self) -> () {
        if (((((((self.close_EV.equal(&BBoolean::new(false)) && self.open_EV.equal(&BBoolean::new(false))) && self.extend_EV.equal(&BBoolean::new(false))) && self.retract_EV.equal(&BBoolean::new(false))) && ((self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))) || (self.handle.equal(&HANDLE_STATE::up) && (self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()])) || self.shock_absorber.equal(&PLANE_STATE::ground))))) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed.clone()])).not()) && self.general_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.close_EV = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stop_stimulate_close_door_valve(&mut self) -> () {
        if (((self.close_EV.equal(&BBoolean::new(true)) && (((self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed.clone()]))) || ((self.handle.equal(&HANDLE_STATE::up) && (self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()])) || self.shock_absorber.equal(&PLANE_STATE::ground))) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed.clone()]))))) && self.general_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.close_EV = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stimulate_retract_gear_valve(&mut self) -> () {
        if ((((((((self.retract_EV.equal(&BBoolean::new(false)) && self.extend_EV.equal(&BBoolean::new(false))) && self.open_EV.equal(&BBoolean::new(true))) && self.handle.equal(&HANDLE_STATE::up)) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()])).not()) && self.shock_absorber.equal(&PLANE_STATE::flight)) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open.clone()]))) && self.general_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.retract_EV = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stop_stimulate_retract_gear_valve(&mut self) -> () {
        if (((self.retract_EV.equal(&BBoolean::new(true)) && (self.handle.equal(&HANDLE_STATE::down) || self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()])))) && self.general_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.retract_EV = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stimulate_extend_gear_valve(&mut self) -> () {
        if (((((((self.extend_EV.equal(&BBoolean::new(false)) && self.retract_EV.equal(&BBoolean::new(false))) && self.open_EV.equal(&BBoolean::new(true))) && self.handle.equal(&HANDLE_STATE::down)) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()])).not()) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open.clone()]))) && self.general_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.extend_EV = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stop_stimulate_extend_gear_valve(&mut self) -> () {
        if (((self.extend_EV.equal(&BBoolean::new(true)) && (self.handle.equal(&HANDLE_STATE::up) || self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()])))) && self.general_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.extend_EV = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_start_retracting_first(&mut self, mut gr: POSITION) -> () {
        if ((((((((self.gears.domain().elementOf(&gr) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open.clone()]))) && self.handle.equal(&HANDLE_STATE::up)) && self.gears.functionCall(&gr).equal(&GEAR_STATE::extended)) && self.valve_retract_gear.equal(&VALVE_STATE::valve_open)) && self.general_valve.equal(&VALVE_STATE::valve_open)) && BSet::new(vec![GEAR_STATE::extended.clone(), GEAR_STATE::gear_moving.clone()]).elementOf(&self.gear)) && self.door.equal(&DOOR_STATE::open))).booleanValue() {
            let mut _ld_gears = self.gears.clone();
            self.gears = _ld_gears._override(&BRelation::new(vec![BTuple::from_refs(&gr, &GEAR_STATE::gear_moving)])).clone().clone();
            self.gear = GEAR_STATE::gear_moving;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_retract_gear_skip(&mut self, mut gr: POSITION) -> () {
        if ((((((self.gears.domain().elementOf(&gr) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open.clone()]))) && self.gears.relationImage(&self._POSITION.difference(&BSet::new(vec![gr.clone()]))).unequal(&BSet::new(vec![GEAR_STATE::retracted.clone()]))) && self.handle.equal(&HANDLE_STATE::up)) && self.gears.functionCall(&gr).equal(&GEAR_STATE::gear_moving)) && self.general_valve.equal(&VALVE_STATE::valve_open))).booleanValue() {
            self.gears = self.gears._override(&BRelation::new(vec![BTuple::from_refs(&gr, &GEAR_STATE::retracted)])).clone().clone();
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_retract_gear_last(&mut self, mut gr: POSITION) -> () {
        if ((((((((self.gears.domain().elementOf(&gr) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open.clone()]))) && self.gears.relationImage(&self._POSITION.difference(&BSet::new(vec![gr.clone()]))).equal(&BSet::new(vec![GEAR_STATE::retracted.clone()]))) && self.handle.equal(&HANDLE_STATE::up)) && self.gears.functionCall(&gr).equal(&GEAR_STATE::gear_moving)) && self.general_valve.equal(&VALVE_STATE::valve_open)) && self.gear.equal(&GEAR_STATE::gear_moving)) && self.door.equal(&DOOR_STATE::open))).booleanValue() {
            let mut _ld_gears = self.gears.clone();
            self.gears = _ld_gears._override(&BRelation::new(vec![BTuple::from_refs(&gr, &GEAR_STATE::retracted)])).clone().clone();
            self.gear = GEAR_STATE::retracted;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_start_extending(&mut self, mut gr: POSITION) -> () {
        if ((((((((self.gears.domain().elementOf(&gr) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open.clone()]))) && self.handle.equal(&HANDLE_STATE::down)) && self.gears.functionCall(&gr).equal(&GEAR_STATE::retracted)) && self.valve_extend_gear.equal(&VALVE_STATE::valve_open)) && self.general_valve.equal(&VALVE_STATE::valve_open)) && BSet::new(vec![GEAR_STATE::gear_moving.clone(), GEAR_STATE::retracted.clone()]).elementOf(&self.gear)) && self.door.equal(&DOOR_STATE::open))).booleanValue() {
            let mut _ld_gears = self.gears.clone();
            self.gears = _ld_gears._override(&BRelation::new(vec![BTuple::from_refs(&gr, &GEAR_STATE::gear_moving)])).clone().clone();
            self.gear = GEAR_STATE::gear_moving;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_extend_gear_last(&mut self, mut gr: POSITION) -> () {
        if ((((((((self.gears.domain().elementOf(&gr) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open.clone()]))) && self.handle.equal(&HANDLE_STATE::down)) && self.gears.relationImage(&self._POSITION.difference(&BSet::new(vec![gr.clone()]))).equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))) && self.gears.functionCall(&gr).equal(&GEAR_STATE::gear_moving)) && self.general_valve.equal(&VALVE_STATE::valve_open)) && self.gear.equal(&GEAR_STATE::gear_moving)) && self.door.equal(&DOOR_STATE::open))).booleanValue() {
            let mut _ld_gears = self.gears.clone();
            self.gears = _ld_gears._override(&BRelation::new(vec![BTuple::from_refs(&gr, &GEAR_STATE::extended)])).clone().clone();
            self.gear = GEAR_STATE::extended;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_extend_gear_skip(&mut self, mut gr: POSITION) -> () {
        if ((((((self.gears.domain().elementOf(&gr) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open.clone()]))) && self.handle.equal(&HANDLE_STATE::down)) && self.gears.relationImage(&self._POSITION.difference(&BSet::new(vec![gr.clone()]))).unequal(&BSet::new(vec![GEAR_STATE::extended.clone()]))) && self.gears.functionCall(&gr).equal(&GEAR_STATE::gear_moving)) && self.general_valve.equal(&VALVE_STATE::valve_open))).booleanValue() {
            self.gears = self.gears._override(&BRelation::new(vec![BTuple::from_refs(&gr, &GEAR_STATE::extended)])).clone().clone();
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_start_open_door(&mut self, mut gr: POSITION) -> () {
        if ((((((((((self.gears.domain().elementOf(&gr) && self.doors.functionCall(&gr).equal(&DOOR_STATE::closed)) && self.gears.functionCall(&gr).unequal(&GEAR_STATE::gear_moving)) && self.gears.range().notElementOf(&GEAR_STATE::gear_moving)) && ((self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()]))) || (self.handle.equal(&HANDLE_STATE::up) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))))) && self.valve_open_door.equal(&VALVE_STATE::valve_open)) && self.general_valve.equal(&VALVE_STATE::valve_open)) && BSet::new(vec![DOOR_STATE::closed.clone(), DOOR_STATE::door_moving.clone()]).elementOf(&self.door)) && self.gear.unequal(&GEAR_STATE::gear_moving)) && ((self.handle.equal(&HANDLE_STATE::down) && self.gear.equal(&GEAR_STATE::retracted)) || (self.handle.equal(&HANDLE_STATE::up) && self.gear.equal(&GEAR_STATE::extended))))).booleanValue() {
            let mut _ld_doors = self.doors.clone();
            self.doors = _ld_doors._override(&BRelation::new(vec![BTuple::from_refs(&gr, &DOOR_STATE::door_moving)])).clone().clone();
            self.door = DOOR_STATE::door_moving;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_open_door_last(&mut self, mut gr: POSITION) -> () {
        if (((((((((((self.gears.domain().elementOf(&gr) && self.doors.functionCall(&gr).equal(&DOOR_STATE::door_moving)) && self.gears.functionCall(&gr).unequal(&GEAR_STATE::gear_moving)) && self.gears.range().notElementOf(&GEAR_STATE::gear_moving)) && self.doors.relationImage(&self._POSITION.difference(&BSet::new(vec![gr.clone()]))).equal(&BSet::new(vec![DOOR_STATE::open.clone()]))) && ((self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()]))) || (self.handle.equal(&HANDLE_STATE::up) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))))) && self.valve_open_door.equal(&VALVE_STATE::valve_open)) && self.general_valve.equal(&VALVE_STATE::valve_open)) && self.door.equal(&DOOR_STATE::door_moving)) && self.gear.unequal(&GEAR_STATE::gear_moving)) && ((self.handle.equal(&HANDLE_STATE::down) && self.gear.equal(&GEAR_STATE::retracted)) || (self.handle.equal(&HANDLE_STATE::up) && self.gear.equal(&GEAR_STATE::extended))))).booleanValue() {
            let mut _ld_doors = self.doors.clone();
            self.doors = _ld_doors._override(&BRelation::new(vec![BTuple::from_refs(&gr, &DOOR_STATE::open)])).clone().clone();
            self.door = DOOR_STATE::open;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_open_door_skip(&mut self, mut gr: POSITION) -> () {
        if ((((((((self.gears.domain().elementOf(&gr) && self.doors.functionCall(&gr).equal(&DOOR_STATE::door_moving)) && self.gears.functionCall(&gr).unequal(&GEAR_STATE::gear_moving)) && self.gears.range().notElementOf(&GEAR_STATE::gear_moving)) && self.doors.relationImage(&self._POSITION.difference(&BSet::new(vec![gr.clone()]))).unequal(&BSet::new(vec![DOOR_STATE::open.clone()]))) && ((self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()]))) || (self.handle.equal(&HANDLE_STATE::up) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))))) && self.valve_open_door.equal(&VALVE_STATE::valve_open)) && self.general_valve.equal(&VALVE_STATE::valve_open))).booleanValue() {
            self.doors = self.doors._override(&BRelation::new(vec![BTuple::from_refs(&gr, &DOOR_STATE::open)])).clone().clone();
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_start_close_door(&mut self, mut gr: POSITION) -> () {
        if (((((((((self.gears.domain().elementOf(&gr) && self.doors.functionCall(&gr).equal(&DOOR_STATE::open)) && self.gears.functionCall(&gr).unequal(&GEAR_STATE::gear_moving)) && ((self.handle.equal(&HANDLE_STATE::up) && (self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()])) || self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()])))) || (self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))))) && self.valve_close_door.equal(&VALVE_STATE::valve_open)) && self.general_valve.equal(&VALVE_STATE::valve_open)) && BSet::new(vec![DOOR_STATE::door_moving.clone(), DOOR_STATE::open.clone()]).elementOf(&self.door)) && self.gear.unequal(&GEAR_STATE::gear_moving)) && ((self.handle.equal(&HANDLE_STATE::down) && self.gear.equal(&GEAR_STATE::extended)) || (self.handle.equal(&HANDLE_STATE::up) && BSet::new(vec![GEAR_STATE::extended.clone(), GEAR_STATE::retracted.clone()]).elementOf(&self.gear))))).booleanValue() {
            let mut _ld_doors = self.doors.clone();
            self.doors = _ld_doors._override(&BRelation::new(vec![BTuple::from_refs(&gr, &DOOR_STATE::door_moving)])).clone().clone();
            self.door = DOOR_STATE::door_moving;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_close_door(&mut self, mut gr: POSITION) -> () {
        if ((((((((((((self.gears.domain().elementOf(&gr) && self.doors.functionCall(&gr).equal(&DOOR_STATE::door_moving)) && self.gears.functionCall(&gr).unequal(&GEAR_STATE::gear_moving)) && self.gears.range().notElementOf(&GEAR_STATE::gear_moving)) && self.doors.relationImage(&self._POSITION.difference(&BSet::new(vec![gr.clone()]))).equal(&BSet::new(vec![DOOR_STATE::closed.clone()]))) && ((self.handle.equal(&HANDLE_STATE::up) && (self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()])) || self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()])))) || (self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))))) && self.valve_close_door.equal(&VALVE_STATE::valve_open)) && (self.handle.equal(&HANDLE_STATE::up) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))).implies(|| self.shock_absorber.equal(&PLANE_STATE::ground).booleanValue())) && self.general_valve.equal(&VALVE_STATE::valve_open)) && self.door.equal(&DOOR_STATE::door_moving)) && self.gear.unequal(&GEAR_STATE::gear_moving)) && ((self.handle.equal(&HANDLE_STATE::down) && self.gear.equal(&GEAR_STATE::extended)) || (self.handle.equal(&HANDLE_STATE::up) && BSet::new(vec![GEAR_STATE::extended.clone(), GEAR_STATE::retracted.clone()]).elementOf(&self.gear))))).booleanValue() {
            let mut _ld_doors = self.doors.clone();
            self.doors = _ld_doors._override(&BRelation::new(vec![BTuple::from_refs(&gr, &DOOR_STATE::closed)])).clone().clone();
            self.door = DOOR_STATE::closed;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_close_door_skip(&mut self, mut gr: POSITION) -> () {
        if (((((((((self.gears.domain().elementOf(&gr) && self.doors.functionCall(&gr).equal(&DOOR_STATE::door_moving)) && self.gears.functionCall(&gr).unequal(&GEAR_STATE::gear_moving)) && self.gears.range().notElementOf(&GEAR_STATE::gear_moving)) && self.doors.relationImage(&self._POSITION.difference(&BSet::new(vec![gr.clone()]))).unequal(&BSet::new(vec![DOOR_STATE::closed.clone()]))) && ((self.handle.equal(&HANDLE_STATE::up) && (self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()])) || self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()])))) || (self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))))) && self.valve_close_door.equal(&VALVE_STATE::valve_open)) && (self.handle.equal(&HANDLE_STATE::up) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))).implies(|| self.shock_absorber.equal(&PLANE_STATE::ground).booleanValue())) && self.general_valve.equal(&VALVE_STATE::valve_open))).booleanValue() {
            self.doors = self.doors._override(&BRelation::new(vec![BTuple::from_refs(&gr, &DOOR_STATE::closed)])).clone().clone();
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn toggle_handle_up(&mut self) -> () {
        if (self.handle.equal(&HANDLE_STATE::down)).booleanValue() {
            self.handle = HANDLE_STATE::up;
            self.handle_move = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn toggle_handle_down(&mut self) -> () {
        if (self.handle.equal(&HANDLE_STATE::up)).booleanValue() {
            self.handle = HANDLE_STATE::down;
            self.handle_move = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stimulate_general_valve(&mut self) -> () {
        if ((self.general_EV.equal(&BBoolean::new(false)) && self.handle_move.equal(&BBoolean::new(true)))).booleanValue() {
            self.general_EV = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stop_stimulate_general_valve(&mut self) -> () {
        if (((((((self.general_EV.equal(&BBoolean::new(true)) && self.open_EV.equal(&BBoolean::new(false))) && self.close_EV.equal(&BBoolean::new(false))) && self.retract_EV.equal(&BBoolean::new(false))) && self.extend_EV.equal(&BBoolean::new(false))) && self.close_EV.equal(&BBoolean::new(false))) && (((((self.handle.equal(&HANDLE_STATE::up) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()]))) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed.clone()]))) && self.open_EV.equal(&BBoolean::new(false))) || (((self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed.clone()]))) && self.open_EV.equal(&BBoolean::new(false)))) || (((self.handle.equal(&HANDLE_STATE::up) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed.clone()]))) && self.open_EV.equal(&BBoolean::new(false)))))).booleanValue() {
            self.general_EV = BBoolean::new(false);
            self.handle_move = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn evn_open_general_valve(&mut self) -> () {
        if (((self.general_EV.equal(&BBoolean::new(true)) && self.general_valve.equal(&VALVE_STATE::valve_closed)) && self.analogical_switch.equal(&SWITCH_STATE::switch_closed))).booleanValue() {
            self.general_valve = VALVE_STATE::valve_open;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn evn_close_general_valve(&mut self) -> () {
        if (((self.general_EV.equal(&BBoolean::new(false)) || self.analogical_switch.equal(&SWITCH_STATE::switch_open)) && self.general_valve.equal(&VALVE_STATE::valve_open))).booleanValue() {
            self.general_valve = VALVE_STATE::valve_closed;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_close_analogical_switch(&mut self) -> () {
        if ((self.analogical_switch.equal(&SWITCH_STATE::switch_open) && self.handle_move.equal(&BBoolean::new(true)))).booleanValue() {
            self.analogical_switch = SWITCH_STATE::switch_closed;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_open_analogical_switch(&mut self) -> () {
        if (self.analogical_switch.equal(&SWITCH_STATE::switch_closed)).booleanValue() {
            self.analogical_switch = SWITCH_STATE::switch_open;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn _tr_begin_flying(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_begin_flying.is_none() {
            let mut __tmp__val__ = self.shock_absorber.equal(&PLANE_STATE::ground).booleanValue();
            self._tr_cache_begin_flying = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_begin_flying.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_land_plane(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_land_plane.is_none() {
            let mut __tmp__val__ = self.shock_absorber.equal(&PLANE_STATE::flight).booleanValue();
            self._tr_cache_land_plane = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_land_plane.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_open_valve_door_open(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_open_valve_door_open.is_none() {
            let mut __tmp__val__ = (self.valve_open_door.equal(&VALVE_STATE::valve_closed) && self.open_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_open_valve_door_open = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_open_valve_door_open.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_close_valve_door_open(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_close_valve_door_open.is_none() {
            let mut __tmp__val__ = (self.valve_open_door.equal(&VALVE_STATE::valve_open) && self.open_EV.equal(&BBoolean::new(false))).booleanValue();
            self._tr_cache_close_valve_door_open = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_close_valve_door_open.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_open_valve_door_close(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_open_valve_door_close.is_none() {
            let mut __tmp__val__ = (self.valve_close_door.equal(&VALVE_STATE::valve_closed) && self.close_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_open_valve_door_close = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_open_valve_door_close.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_close_valve_door_close(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_close_valve_door_close.is_none() {
            let mut __tmp__val__ = (self.valve_close_door.equal(&VALVE_STATE::valve_open) && self.close_EV.equal(&BBoolean::new(false))).booleanValue();
            self._tr_cache_close_valve_door_close = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_close_valve_door_close.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_open_valve_retract_gear(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_open_valve_retract_gear.is_none() {
            let mut __tmp__val__ = (self.valve_retract_gear.equal(&VALVE_STATE::valve_closed) && self.retract_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_open_valve_retract_gear = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_open_valve_retract_gear.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_close_valve_retract_gear(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_close_valve_retract_gear.is_none() {
            let mut __tmp__val__ = (self.valve_retract_gear.equal(&VALVE_STATE::valve_open) && self.retract_EV.equal(&BBoolean::new(false))).booleanValue();
            self._tr_cache_close_valve_retract_gear = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_close_valve_retract_gear.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_open_valve_extend_gear(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_open_valve_extend_gear.is_none() {
            let mut __tmp__val__ = (self.valve_extend_gear.equal(&VALVE_STATE::valve_closed) && self.extend_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_open_valve_extend_gear = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_open_valve_extend_gear.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_close_valve_extend_gear(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_close_valve_extend_gear.is_none() {
            let mut __tmp__val__ = (self.valve_extend_gear.equal(&VALVE_STATE::valve_open) && self.extend_EV.equal(&BBoolean::new(false))).booleanValue();
            self._tr_cache_close_valve_extend_gear = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_close_valve_extend_gear.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stimulate_open_door_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stimulate_open_door_valve.is_none() {
            let mut __tmp__val__ = (((self.open_EV.equal(&BBoolean::new(false)) && self.close_EV.equal(&BBoolean::new(false))) && ((self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()])).not()) || ((self.handle.equal(&HANDLE_STATE::up) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()])).not()) && (self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open.clone()])) && self.shock_absorber.equal(&PLANE_STATE::ground)).not()))) && self.general_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_con_stimulate_open_door_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stimulate_open_door_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stop_stimulate_open_door_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stop_stimulate_open_door_valve.is_none() {
            let mut __tmp__val__ = ((((self.open_EV.equal(&BBoolean::new(true)) && self.extend_EV.equal(&BBoolean::new(false))) && self.retract_EV.equal(&BBoolean::new(false))) && ((self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))) || ((self.handle.equal(&HANDLE_STATE::up) && (self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()])) || self.shock_absorber.equal(&PLANE_STATE::ground))) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open.clone()]))))) && self.general_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_con_stop_stimulate_open_door_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stop_stimulate_open_door_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stimulate_close_door_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stimulate_close_door_valve.is_none() {
            let mut __tmp__val__ = ((((((self.close_EV.equal(&BBoolean::new(false)) && self.open_EV.equal(&BBoolean::new(false))) && self.extend_EV.equal(&BBoolean::new(false))) && self.retract_EV.equal(&BBoolean::new(false))) && ((self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))) || (self.handle.equal(&HANDLE_STATE::up) && (self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()])) || self.shock_absorber.equal(&PLANE_STATE::ground))))) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed.clone()])).not()) && self.general_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_con_stimulate_close_door_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stimulate_close_door_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stop_stimulate_close_door_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stop_stimulate_close_door_valve.is_none() {
            let mut __tmp__val__ = ((self.close_EV.equal(&BBoolean::new(true)) && (((self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed.clone()]))) || ((self.handle.equal(&HANDLE_STATE::up) && (self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()])) || self.shock_absorber.equal(&PLANE_STATE::ground))) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed.clone()]))))) && self.general_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_con_stop_stimulate_close_door_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stop_stimulate_close_door_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stimulate_retract_gear_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stimulate_retract_gear_valve.is_none() {
            let mut __tmp__val__ = (((((((self.retract_EV.equal(&BBoolean::new(false)) && self.extend_EV.equal(&BBoolean::new(false))) && self.open_EV.equal(&BBoolean::new(true))) && self.handle.equal(&HANDLE_STATE::up)) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()])).not()) && self.shock_absorber.equal(&PLANE_STATE::flight)) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open.clone()]))) && self.general_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_con_stimulate_retract_gear_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stimulate_retract_gear_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stop_stimulate_retract_gear_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stop_stimulate_retract_gear_valve.is_none() {
            let mut __tmp__val__ = ((self.retract_EV.equal(&BBoolean::new(true)) && (self.handle.equal(&HANDLE_STATE::down) || self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()])))) && self.general_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_con_stop_stimulate_retract_gear_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stop_stimulate_retract_gear_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stimulate_extend_gear_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stimulate_extend_gear_valve.is_none() {
            let mut __tmp__val__ = ((((((self.extend_EV.equal(&BBoolean::new(false)) && self.retract_EV.equal(&BBoolean::new(false))) && self.open_EV.equal(&BBoolean::new(true))) && self.handle.equal(&HANDLE_STATE::down)) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()])).not()) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open.clone()]))) && self.general_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_con_stimulate_extend_gear_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stimulate_extend_gear_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stop_stimulate_extend_gear_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stop_stimulate_extend_gear_valve.is_none() {
            let mut __tmp__val__ = ((self.extend_EV.equal(&BBoolean::new(true)) && (self.handle.equal(&HANDLE_STATE::up) || self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()])))) && self.general_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_con_stop_stimulate_extend_gear_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stop_stimulate_extend_gear_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_start_retracting_first(&mut self, is_caching: bool) -> BSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_start_retracting_first.is_none() {
            let mut _ic_set_18: BSet<POSITION> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                //parameter_combination_predicate
                if (((((((self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open.clone()])) && self.handle.equal(&HANDLE_STATE::up)) && self.gears.functionCall(&_ic_gr_1).equal(&GEAR_STATE::extended)) && self.valve_retract_gear.equal(&VALVE_STATE::valve_open)) && self.general_valve.equal(&VALVE_STATE::valve_open)) && BSet::new(vec![GEAR_STATE::extended.clone(), GEAR_STATE::gear_moving.clone()]).elementOf(&self.gear)) && self.door.equal(&DOOR_STATE::open))).booleanValue() {
                    _ic_set_18 = _ic_set_18._union(&BSet::new(vec![_ic_gr_1]));
                }

            }
            self._tr_cache_env_start_retracting_first = Option::Some(_ic_set_18.clone());
            return _ic_set_18;
        } else {
            return self._tr_cache_env_start_retracting_first.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_retract_gear_skip(&mut self, is_caching: bool) -> BSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_retract_gear_skip.is_none() {
            let mut _ic_set_19: BSet<POSITION> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                //parameter_combination_predicate
                if (((((self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open.clone()])) && self.gears.relationImage(&self._POSITION.difference(&BSet::new(vec![_ic_gr_1.clone()]))).unequal(&BSet::new(vec![GEAR_STATE::retracted.clone()]))) && self.handle.equal(&HANDLE_STATE::up)) && self.gears.functionCall(&_ic_gr_1).equal(&GEAR_STATE::gear_moving)) && self.general_valve.equal(&VALVE_STATE::valve_open))).booleanValue() {
                    _ic_set_19 = _ic_set_19._union(&BSet::new(vec![_ic_gr_1]));
                }

            }
            self._tr_cache_env_retract_gear_skip = Option::Some(_ic_set_19.clone());
            return _ic_set_19;
        } else {
            return self._tr_cache_env_retract_gear_skip.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_retract_gear_last(&mut self, is_caching: bool) -> BSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_retract_gear_last.is_none() {
            let mut _ic_set_20: BSet<POSITION> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                //parameter_combination_predicate
                if (((((((self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open.clone()])) && self.gears.relationImage(&self._POSITION.difference(&BSet::new(vec![_ic_gr_1.clone()]))).equal(&BSet::new(vec![GEAR_STATE::retracted.clone()]))) && self.handle.equal(&HANDLE_STATE::up)) && self.gears.functionCall(&_ic_gr_1).equal(&GEAR_STATE::gear_moving)) && self.general_valve.equal(&VALVE_STATE::valve_open)) && self.gear.equal(&GEAR_STATE::gear_moving)) && self.door.equal(&DOOR_STATE::open))).booleanValue() {
                    _ic_set_20 = _ic_set_20._union(&BSet::new(vec![_ic_gr_1]));
                }

            }
            self._tr_cache_env_retract_gear_last = Option::Some(_ic_set_20.clone());
            return _ic_set_20;
        } else {
            return self._tr_cache_env_retract_gear_last.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_start_extending(&mut self, is_caching: bool) -> BSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_start_extending.is_none() {
            let mut _ic_set_21: BSet<POSITION> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                //parameter_combination_predicate
                if (((((((self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open.clone()])) && self.handle.equal(&HANDLE_STATE::down)) && self.gears.functionCall(&_ic_gr_1).equal(&GEAR_STATE::retracted)) && self.valve_extend_gear.equal(&VALVE_STATE::valve_open)) && self.general_valve.equal(&VALVE_STATE::valve_open)) && BSet::new(vec![GEAR_STATE::gear_moving.clone(), GEAR_STATE::retracted.clone()]).elementOf(&self.gear)) && self.door.equal(&DOOR_STATE::open))).booleanValue() {
                    _ic_set_21 = _ic_set_21._union(&BSet::new(vec![_ic_gr_1]));
                }

            }
            self._tr_cache_env_start_extending = Option::Some(_ic_set_21.clone());
            return _ic_set_21;
        } else {
            return self._tr_cache_env_start_extending.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_extend_gear_last(&mut self, is_caching: bool) -> BSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_extend_gear_last.is_none() {
            let mut _ic_set_22: BSet<POSITION> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                //parameter_combination_predicate
                if (((((((self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open.clone()])) && self.handle.equal(&HANDLE_STATE::down)) && self.gears.relationImage(&self._POSITION.difference(&BSet::new(vec![_ic_gr_1.clone()]))).equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))) && self.gears.functionCall(&_ic_gr_1).equal(&GEAR_STATE::gear_moving)) && self.general_valve.equal(&VALVE_STATE::valve_open)) && self.gear.equal(&GEAR_STATE::gear_moving)) && self.door.equal(&DOOR_STATE::open))).booleanValue() {
                    _ic_set_22 = _ic_set_22._union(&BSet::new(vec![_ic_gr_1]));
                }

            }
            self._tr_cache_env_extend_gear_last = Option::Some(_ic_set_22.clone());
            return _ic_set_22;
        } else {
            return self._tr_cache_env_extend_gear_last.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_extend_gear_skip(&mut self, is_caching: bool) -> BSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_extend_gear_skip.is_none() {
            let mut _ic_set_23: BSet<POSITION> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                //parameter_combination_predicate
                if (((((self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open.clone()])) && self.handle.equal(&HANDLE_STATE::down)) && self.gears.relationImage(&self._POSITION.difference(&BSet::new(vec![_ic_gr_1.clone()]))).unequal(&BSet::new(vec![GEAR_STATE::extended.clone()]))) && self.gears.functionCall(&_ic_gr_1).equal(&GEAR_STATE::gear_moving)) && self.general_valve.equal(&VALVE_STATE::valve_open))).booleanValue() {
                    _ic_set_23 = _ic_set_23._union(&BSet::new(vec![_ic_gr_1]));
                }

            }
            self._tr_cache_env_extend_gear_skip = Option::Some(_ic_set_23.clone());
            return _ic_set_23;
        } else {
            return self._tr_cache_env_extend_gear_skip.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_start_open_door(&mut self, is_caching: bool) -> BSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_start_open_door.is_none() {
            let mut _ic_set_24: BSet<POSITION> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                //parameter_combination_predicate
                if (((((((((self.doors.functionCall(&_ic_gr_1).equal(&DOOR_STATE::closed) && self.gears.functionCall(&_ic_gr_1).unequal(&GEAR_STATE::gear_moving)) && self.gears.range().notElementOf(&GEAR_STATE::gear_moving)) && ((self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()]))) || (self.handle.equal(&HANDLE_STATE::up) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))))) && self.valve_open_door.equal(&VALVE_STATE::valve_open)) && self.general_valve.equal(&VALVE_STATE::valve_open)) && BSet::new(vec![DOOR_STATE::closed.clone(), DOOR_STATE::door_moving.clone()]).elementOf(&self.door)) && self.gear.unequal(&GEAR_STATE::gear_moving)) && ((self.handle.equal(&HANDLE_STATE::down) && self.gear.equal(&GEAR_STATE::retracted)) || (self.handle.equal(&HANDLE_STATE::up) && self.gear.equal(&GEAR_STATE::extended))))).booleanValue() {
                    _ic_set_24 = _ic_set_24._union(&BSet::new(vec![_ic_gr_1]));
                }

            }
            self._tr_cache_env_start_open_door = Option::Some(_ic_set_24.clone());
            return _ic_set_24;
        } else {
            return self._tr_cache_env_start_open_door.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_open_door_last(&mut self, is_caching: bool) -> BSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_open_door_last.is_none() {
            let mut _ic_set_25: BSet<POSITION> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                //parameter_combination_predicate
                if ((((((((((self.doors.functionCall(&_ic_gr_1).equal(&DOOR_STATE::door_moving) && self.gears.functionCall(&_ic_gr_1).unequal(&GEAR_STATE::gear_moving)) && self.gears.range().notElementOf(&GEAR_STATE::gear_moving)) && self.doors.relationImage(&self._POSITION.difference(&BSet::new(vec![_ic_gr_1.clone()]))).equal(&BSet::new(vec![DOOR_STATE::open.clone()]))) && ((self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()]))) || (self.handle.equal(&HANDLE_STATE::up) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))))) && self.valve_open_door.equal(&VALVE_STATE::valve_open)) && self.general_valve.equal(&VALVE_STATE::valve_open)) && self.door.equal(&DOOR_STATE::door_moving)) && self.gear.unequal(&GEAR_STATE::gear_moving)) && ((self.handle.equal(&HANDLE_STATE::down) && self.gear.equal(&GEAR_STATE::retracted)) || (self.handle.equal(&HANDLE_STATE::up) && self.gear.equal(&GEAR_STATE::extended))))).booleanValue() {
                    _ic_set_25 = _ic_set_25._union(&BSet::new(vec![_ic_gr_1]));
                }

            }
            self._tr_cache_env_open_door_last = Option::Some(_ic_set_25.clone());
            return _ic_set_25;
        } else {
            return self._tr_cache_env_open_door_last.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_open_door_skip(&mut self, is_caching: bool) -> BSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_open_door_skip.is_none() {
            let mut _ic_set_26: BSet<POSITION> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                //parameter_combination_predicate
                if (((((((self.doors.functionCall(&_ic_gr_1).equal(&DOOR_STATE::door_moving) && self.gears.functionCall(&_ic_gr_1).unequal(&GEAR_STATE::gear_moving)) && self.gears.range().notElementOf(&GEAR_STATE::gear_moving)) && self.doors.relationImage(&self._POSITION.difference(&BSet::new(vec![_ic_gr_1.clone()]))).unequal(&BSet::new(vec![DOOR_STATE::open.clone()]))) && ((self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()]))) || (self.handle.equal(&HANDLE_STATE::up) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))))) && self.valve_open_door.equal(&VALVE_STATE::valve_open)) && self.general_valve.equal(&VALVE_STATE::valve_open))).booleanValue() {
                    _ic_set_26 = _ic_set_26._union(&BSet::new(vec![_ic_gr_1]));
                }

            }
            self._tr_cache_env_open_door_skip = Option::Some(_ic_set_26.clone());
            return _ic_set_26;
        } else {
            return self._tr_cache_env_open_door_skip.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_start_close_door(&mut self, is_caching: bool) -> BSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_start_close_door.is_none() {
            let mut _ic_set_27: BSet<POSITION> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                //parameter_combination_predicate
                if ((((((((self.doors.functionCall(&_ic_gr_1).equal(&DOOR_STATE::open) && self.gears.functionCall(&_ic_gr_1).unequal(&GEAR_STATE::gear_moving)) && ((self.handle.equal(&HANDLE_STATE::up) && (self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()])) || self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()])))) || (self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))))) && self.valve_close_door.equal(&VALVE_STATE::valve_open)) && self.general_valve.equal(&VALVE_STATE::valve_open)) && BSet::new(vec![DOOR_STATE::door_moving.clone(), DOOR_STATE::open.clone()]).elementOf(&self.door)) && self.gear.unequal(&GEAR_STATE::gear_moving)) && ((self.handle.equal(&HANDLE_STATE::down) && self.gear.equal(&GEAR_STATE::extended)) || (self.handle.equal(&HANDLE_STATE::up) && BSet::new(vec![GEAR_STATE::extended.clone(), GEAR_STATE::retracted.clone()]).elementOf(&self.gear))))).booleanValue() {
                    _ic_set_27 = _ic_set_27._union(&BSet::new(vec![_ic_gr_1]));
                }

            }
            self._tr_cache_env_start_close_door = Option::Some(_ic_set_27.clone());
            return _ic_set_27;
        } else {
            return self._tr_cache_env_start_close_door.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_close_door(&mut self, is_caching: bool) -> BSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_close_door.is_none() {
            let mut _ic_set_28: BSet<POSITION> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                //parameter_combination_predicate
                if (((((((((((self.doors.functionCall(&_ic_gr_1).equal(&DOOR_STATE::door_moving) && self.gears.functionCall(&_ic_gr_1).unequal(&GEAR_STATE::gear_moving)) && self.gears.range().notElementOf(&GEAR_STATE::gear_moving)) && self.doors.relationImage(&self._POSITION.difference(&BSet::new(vec![_ic_gr_1.clone()]))).equal(&BSet::new(vec![DOOR_STATE::closed.clone()]))) && ((self.handle.equal(&HANDLE_STATE::up) && (self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()])) || self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()])))) || (self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))))) && self.valve_close_door.equal(&VALVE_STATE::valve_open)) && (self.handle.equal(&HANDLE_STATE::up) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))).implies(|| self.shock_absorber.equal(&PLANE_STATE::ground).booleanValue())) && self.general_valve.equal(&VALVE_STATE::valve_open)) && self.door.equal(&DOOR_STATE::door_moving)) && self.gear.unequal(&GEAR_STATE::gear_moving)) && ((self.handle.equal(&HANDLE_STATE::down) && self.gear.equal(&GEAR_STATE::extended)) || (self.handle.equal(&HANDLE_STATE::up) && BSet::new(vec![GEAR_STATE::extended.clone(), GEAR_STATE::retracted.clone()]).elementOf(&self.gear))))).booleanValue() {
                    _ic_set_28 = _ic_set_28._union(&BSet::new(vec![_ic_gr_1]));
                }

            }
            self._tr_cache_env_close_door = Option::Some(_ic_set_28.clone());
            return _ic_set_28;
        } else {
            return self._tr_cache_env_close_door.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_close_door_skip(&mut self, is_caching: bool) -> BSet<POSITION> {
        //transition
        if !is_caching || self._tr_cache_env_close_door_skip.is_none() {
            let mut _ic_set_29: BSet<POSITION> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                //parameter_combination_predicate
                if ((((((((self.doors.functionCall(&_ic_gr_1).equal(&DOOR_STATE::door_moving) && self.gears.functionCall(&_ic_gr_1).unequal(&GEAR_STATE::gear_moving)) && self.gears.range().notElementOf(&GEAR_STATE::gear_moving)) && self.doors.relationImage(&self._POSITION.difference(&BSet::new(vec![_ic_gr_1.clone()]))).unequal(&BSet::new(vec![DOOR_STATE::closed.clone()]))) && ((self.handle.equal(&HANDLE_STATE::up) && (self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()])) || self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()])))) || (self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))))) && self.valve_close_door.equal(&VALVE_STATE::valve_open)) && (self.handle.equal(&HANDLE_STATE::up) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))).implies(|| self.shock_absorber.equal(&PLANE_STATE::ground).booleanValue())) && self.general_valve.equal(&VALVE_STATE::valve_open))).booleanValue() {
                    _ic_set_29 = _ic_set_29._union(&BSet::new(vec![_ic_gr_1]));
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
            let mut __tmp__val__ = self.handle.equal(&HANDLE_STATE::down).booleanValue();
            self._tr_cache_toggle_handle_up = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_toggle_handle_up.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_toggle_handle_down(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_toggle_handle_down.is_none() {
            let mut __tmp__val__ = self.handle.equal(&HANDLE_STATE::up).booleanValue();
            self._tr_cache_toggle_handle_down = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_toggle_handle_down.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stimulate_general_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stimulate_general_valve.is_none() {
            let mut __tmp__val__ = (self.general_EV.equal(&BBoolean::new(false)) && self.handle_move.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_con_stimulate_general_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stimulate_general_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stop_stimulate_general_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stop_stimulate_general_valve.is_none() {
            let mut __tmp__val__ = ((((((self.general_EV.equal(&BBoolean::new(true)) && self.open_EV.equal(&BBoolean::new(false))) && self.close_EV.equal(&BBoolean::new(false))) && self.retract_EV.equal(&BBoolean::new(false))) && self.extend_EV.equal(&BBoolean::new(false))) && self.close_EV.equal(&BBoolean::new(false))) && (((((self.handle.equal(&HANDLE_STATE::up) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()]))) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed.clone()]))) && self.open_EV.equal(&BBoolean::new(false))) || (((self.handle.equal(&HANDLE_STATE::down) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed.clone()]))) && self.open_EV.equal(&BBoolean::new(false)))) || (((self.handle.equal(&HANDLE_STATE::up) && self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))) && self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed.clone()]))) && self.open_EV.equal(&BBoolean::new(false))))).booleanValue();
            self._tr_cache_con_stop_stimulate_general_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stop_stimulate_general_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_evn_open_general_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_evn_open_general_valve.is_none() {
            let mut __tmp__val__ = ((self.general_EV.equal(&BBoolean::new(true)) && self.general_valve.equal(&VALVE_STATE::valve_closed)) && self.analogical_switch.equal(&SWITCH_STATE::switch_closed)).booleanValue();
            self._tr_cache_evn_open_general_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_evn_open_general_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_evn_close_general_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_evn_close_general_valve.is_none() {
            let mut __tmp__val__ = ((self.general_EV.equal(&BBoolean::new(false)) || self.analogical_switch.equal(&SWITCH_STATE::switch_open)) && self.general_valve.equal(&VALVE_STATE::valve_open)).booleanValue();
            self._tr_cache_evn_close_general_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_evn_close_general_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_close_analogical_switch(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_env_close_analogical_switch.is_none() {
            let mut __tmp__val__ = (self.analogical_switch.equal(&SWITCH_STATE::switch_open) && self.handle_move.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_env_close_analogical_switch = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_env_close_analogical_switch.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_open_analogical_switch(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_env_open_analogical_switch.is_none() {
            let mut __tmp__val__ = self.analogical_switch.equal(&SWITCH_STATE::switch_closed).booleanValue();
            self._tr_cache_env_open_analogical_switch = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_env_open_analogical_switch.as_ref().unwrap().clone();
        }
    }

    pub fn _check_inv_1(&self) -> bool {
        //invariant
        return self._SWITCH_STATE.elementOf(&self.analogical_switch).booleanValue();
    }

    pub fn _check_inv_2(&self) -> bool {
        //invariant
        return (*butils::BOOL).elementOf(&self.general_EV).booleanValue();
    }

    pub fn _check_inv_3(&self) -> bool {
        //invariant
        return self._VALVE_STATE.elementOf(&self.general_valve).booleanValue();
    }

    pub fn _check_inv_4(&self) -> bool {
        //invariant
        return (*butils::BOOL).elementOf(&self.handle_move).booleanValue();
    }

    pub fn _check_inv_5(&self) -> bool {
        //invariant
        return (*butils::BOOL).elementOf(&self.close_EV).booleanValue();
    }

    pub fn _check_inv_6(&self) -> bool {
        //invariant
        return (*butils::BOOL).elementOf(&self.extend_EV).booleanValue();
    }

    pub fn _check_inv_7(&self) -> bool {
        //invariant
        return (*butils::BOOL).elementOf(&self.open_EV).booleanValue();
    }

    pub fn _check_inv_8(&self) -> bool {
        //invariant
        return (*butils::BOOL).elementOf(&self.retract_EV).booleanValue();
    }

    pub fn _check_inv_9(&self) -> bool {
        //invariant
        return self._PLANE_STATE.elementOf(&self.shock_absorber).booleanValue();
    }

    pub fn _check_inv_10(&self) -> bool {
        //invariant
        return self._VALVE_STATE.elementOf(&self.valve_close_door).booleanValue();
    }

    pub fn _check_inv_11(&self) -> bool {
        //invariant
        return self._VALVE_STATE.elementOf(&self.valve_extend_gear).booleanValue();
    }

    pub fn _check_inv_12(&self) -> bool {
        //invariant
        return self._VALVE_STATE.elementOf(&self.valve_open_door).booleanValue();
    }

    pub fn _check_inv_13(&self) -> bool {
        //invariant
        return self._VALVE_STATE.elementOf(&self.valve_retract_gear).booleanValue();
    }

    pub fn _check_inv_14(&self) -> bool {
        //invariant
        return self._HANDLE_STATE.elementOf(&self.handle).booleanValue();
    }

    pub fn _check_inv_15(&self) -> bool {
        //invariant
        return self._DOOR_STATE.elementOf(&self.door).booleanValue();
    }

    pub fn _check_inv_16(&self) -> bool {
        //invariant
        return self._GEAR_STATE.elementOf(&self.gear).booleanValue();
    }

    pub fn _check_inv_17(&self) -> bool {
        //invariant
        return (((self.open_EV.equal(&BBoolean::new(true)) || self.close_EV.equal(&BBoolean::new(true))) || self.retract_EV.equal(&BBoolean::new(true))) || self.extend_EV.equal(&BBoolean::new(true))).implies(|| self.general_EV.equal(&BBoolean::new(true)).booleanValue()).booleanValue();
    }

    pub fn _check_inv_18(&self) -> bool {
        //invariant
        return (self.open_EV.equal(&BBoolean::new(true)) && self.close_EV.equal(&BBoolean::new(true))).not().booleanValue();
    }

    pub fn _check_inv_19(&self) -> bool {
        //invariant
        return self._POSITION.check_domain_of(&self.gears).and(&self._GEAR_STATE.check_range_of(&self.gears)).and(&self.gears.isFunction()).and(&self._POSITION.check_total_of(&self.gears)).booleanValue();
    }

    pub fn _check_inv_20(&self) -> bool {
        //invariant
        return self._POSITION.check_domain_of(&self.doors).and(&self._DOOR_STATE.check_range_of(&self.doors)).and(&self.doors.isFunction()).and(&self._POSITION.check_total_of(&self.doors)).booleanValue();
    }

    pub fn _check_inv_21(&self) -> bool {
        //invariant
        return self.door.equal(&DOOR_STATE::closed).equivalent(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed.clone()]))).booleanValue();
    }

    pub fn _check_inv_22(&self) -> bool {
        //invariant
        return self.door.equal(&DOOR_STATE::open).equivalent(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open.clone()]))).booleanValue();
    }

    pub fn _check_inv_23(&self) -> bool {
        //invariant
        return self.gear.equal(&GEAR_STATE::extended).equivalent(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended.clone()]))).booleanValue();
    }

    pub fn _check_inv_24(&self) -> bool {
        //invariant
        return self.gear.equal(&GEAR_STATE::retracted).equivalent(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted.clone()]))).booleanValue();
    }

    pub fn _check_inv_25(&self) -> bool {
        //invariant
        return self.gear.equal(&GEAR_STATE::gear_moving).implies(|| self.door.equal(&DOOR_STATE::open).booleanValue()).booleanValue();
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
