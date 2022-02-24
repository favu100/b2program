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
        self.gears = BRelation::cartesianProduct(&self._POSITION, &BSet::new(vec![GEAR_STATE::extended])).clone().clone();
        self.doors = BRelation::cartesianProduct(&self._POSITION, &BSet::new(vec![DOOR_STATE::closed])).clone().clone();
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

    pub fn get_doors(&self) -> BRelation<POSITION, DOOR_STATE> {
        return self.doors.clone();
    }

    pub fn get_gears(&self) -> BRelation<POSITION, GEAR_STATE> {
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

    pub fn get__DOOR_STATE(&self) -> BSet<DOOR_STATE> {
        return self._DOOR_STATE.clone();
    }

    pub fn get__GEAR_STATE(&self) -> BSet<GEAR_STATE> {
        return self._GEAR_STATE.clone();
    }

    pub fn get__HANDLE_STATE(&self) -> BSet<HANDLE_STATE> {
        return self._HANDLE_STATE.clone();
    }

    pub fn get__POSITION(&self) -> BSet<POSITION> {
        return self._POSITION.clone();
    }

    pub fn get__SWITCH_STATE(&self) -> BSet<SWITCH_STATE> {
        return self._SWITCH_STATE.clone();
    }

    pub fn get__PLANE_STATE(&self) -> BSet<PLANE_STATE> {
        return self._PLANE_STATE.clone();
    }

    pub fn get__VALVE_STATE(&self) -> BSet<VALVE_STATE> {
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
        if (self.valve_open_door.equal(&VALVE_STATE::valve_closed).and(&self.open_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.valve_open_door = VALVE_STATE::valve_open;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn close_valve_door_open(&mut self) -> () {
        if (self.valve_open_door.equal(&VALVE_STATE::valve_open).and(&self.open_EV.equal(&BBoolean::new(false)))).booleanValue() {
            self.valve_open_door = VALVE_STATE::valve_closed;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn open_valve_door_close(&mut self) -> () {
        if (self.valve_close_door.equal(&VALVE_STATE::valve_closed).and(&self.close_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.valve_close_door = VALVE_STATE::valve_open;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn close_valve_door_close(&mut self) -> () {
        if (self.valve_close_door.equal(&VALVE_STATE::valve_open).and(&self.close_EV.equal(&BBoolean::new(false)))).booleanValue() {
            self.valve_close_door = VALVE_STATE::valve_closed;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn open_valve_retract_gear(&mut self) -> () {
        if (self.valve_retract_gear.equal(&VALVE_STATE::valve_closed).and(&self.retract_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.valve_retract_gear = VALVE_STATE::valve_open;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn close_valve_retract_gear(&mut self) -> () {
        if (self.valve_retract_gear.equal(&VALVE_STATE::valve_open).and(&self.retract_EV.equal(&BBoolean::new(false)))).booleanValue() {
            self.valve_retract_gear = VALVE_STATE::valve_closed;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn open_valve_extend_gear(&mut self) -> () {
        if (self.valve_extend_gear.equal(&VALVE_STATE::valve_closed).and(&self.extend_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.valve_extend_gear = VALVE_STATE::valve_open;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn close_valve_extend_gear(&mut self) -> () {
        if (self.valve_extend_gear.equal(&VALVE_STATE::valve_open).and(&self.extend_EV.equal(&BBoolean::new(false)))).booleanValue() {
            self.valve_extend_gear = VALVE_STATE::valve_closed;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stimulate_open_door_valve(&mut self) -> () {
        if (self.open_EV.equal(&BBoolean::new(false)).and(&self.close_EV.equal(&BBoolean::new(false))).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended])).not()).or(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted])).not()).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open])).and(&self.shock_absorber.equal(&PLANE_STATE::ground)).not()))).and(&self.general_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.open_EV = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stop_stimulate_open_door_valve(&mut self) -> () {
        if (self.open_EV.equal(&BBoolean::new(true)).and(&self.extend_EV.equal(&BBoolean::new(false))).and(&self.retract_EV.equal(&BBoolean::new(false))).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))).or(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted])).or(&self.shock_absorber.equal(&PLANE_STATE::ground))).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open]))))).and(&self.general_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.open_EV = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stimulate_close_door_valve(&mut self) -> () {
        if (self.close_EV.equal(&BBoolean::new(false)).and(&self.open_EV.equal(&BBoolean::new(false))).and(&self.extend_EV.equal(&BBoolean::new(false))).and(&self.retract_EV.equal(&BBoolean::new(false))).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))).or(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted])).or(&self.shock_absorber.equal(&PLANE_STATE::ground))))).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed])).not()).and(&self.general_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.close_EV = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stop_stimulate_close_door_valve(&mut self) -> () {
        if (self.close_EV.equal(&BBoolean::new(true)).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed]))).or(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted])).or(&self.shock_absorber.equal(&PLANE_STATE::ground))).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed]))))).and(&self.general_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.close_EV = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stimulate_retract_gear_valve(&mut self) -> () {
        if (self.retract_EV.equal(&BBoolean::new(false)).and(&self.extend_EV.equal(&BBoolean::new(false))).and(&self.open_EV.equal(&BBoolean::new(true))).and(&self.handle.equal(&HANDLE_STATE::up)).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted])).not()).and(&self.shock_absorber.equal(&PLANE_STATE::flight)).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open]))).and(&self.general_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.retract_EV = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stop_stimulate_retract_gear_valve(&mut self) -> () {
        if (self.retract_EV.equal(&BBoolean::new(true)).and(&self.handle.equal(&HANDLE_STATE::down).or(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted])))).and(&self.general_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.retract_EV = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stimulate_extend_gear_valve(&mut self) -> () {
        if (self.extend_EV.equal(&BBoolean::new(false)).and(&self.retract_EV.equal(&BBoolean::new(false))).and(&self.open_EV.equal(&BBoolean::new(true))).and(&self.handle.equal(&HANDLE_STATE::down)).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended])).not()).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open]))).and(&self.general_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.extend_EV = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stop_stimulate_extend_gear_valve(&mut self) -> () {
        if (self.extend_EV.equal(&BBoolean::new(true)).and(&self.handle.equal(&HANDLE_STATE::up).or(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended])))).and(&self.general_EV.equal(&BBoolean::new(true)))).booleanValue() {
            self.extend_EV = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_start_retracting_first(&mut self, mut gr: POSITION) -> () {
        if (self.gears.domain().elementOf(&gr).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open]))).and(&self.handle.equal(&HANDLE_STATE::up)).and(&self.gears.functionCall(&gr).equal(&GEAR_STATE::extended)).and(&self.valve_retract_gear.equal(&VALVE_STATE::valve_open)).and(&self.general_valve.equal(&VALVE_STATE::valve_open)).and(&BSet::new(vec![GEAR_STATE::extended, GEAR_STATE::gear_moving]).elementOf(&self.gear)).and(&self.door.equal(&DOOR_STATE::open))).booleanValue() {
            let mut _ld_gears = self.gears.clone();
            self.gears = _ld_gears._override(&BRelation::new(vec![BTuple::from_refs(&gr, &GEAR_STATE::gear_moving)])).clone().clone();
            self.gear = GEAR_STATE::gear_moving;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_retract_gear_skip(&mut self, mut gr: POSITION) -> () {
        if (self.gears.domain().elementOf(&gr).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open]))).and(&self.gears.relationImage(&self._POSITION.difference(&BSet::new(vec![gr]))).unequal(&BSet::new(vec![GEAR_STATE::retracted]))).and(&self.handle.equal(&HANDLE_STATE::up)).and(&self.gears.functionCall(&gr).equal(&GEAR_STATE::gear_moving)).and(&self.general_valve.equal(&VALVE_STATE::valve_open))).booleanValue() {
            self.gears = self.gears._override(&BRelation::new(vec![BTuple::from_refs(&gr, &GEAR_STATE::retracted)])).clone().clone();
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_retract_gear_last(&mut self, mut gr: POSITION) -> () {
        if (self.gears.domain().elementOf(&gr).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open]))).and(&self.gears.relationImage(&self._POSITION.difference(&BSet::new(vec![gr]))).equal(&BSet::new(vec![GEAR_STATE::retracted]))).and(&self.handle.equal(&HANDLE_STATE::up)).and(&self.gears.functionCall(&gr).equal(&GEAR_STATE::gear_moving)).and(&self.general_valve.equal(&VALVE_STATE::valve_open)).and(&self.gear.equal(&GEAR_STATE::gear_moving)).and(&self.door.equal(&DOOR_STATE::open))).booleanValue() {
            let mut _ld_gears = self.gears.clone();
            self.gears = _ld_gears._override(&BRelation::new(vec![BTuple::from_refs(&gr, &GEAR_STATE::retracted)])).clone().clone();
            self.gear = GEAR_STATE::retracted;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_start_extending(&mut self, mut gr: POSITION) -> () {
        if (self.gears.domain().elementOf(&gr).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open]))).and(&self.handle.equal(&HANDLE_STATE::down)).and(&self.gears.functionCall(&gr).equal(&GEAR_STATE::retracted)).and(&self.valve_extend_gear.equal(&VALVE_STATE::valve_open)).and(&self.general_valve.equal(&VALVE_STATE::valve_open)).and(&BSet::new(vec![GEAR_STATE::gear_moving, GEAR_STATE::retracted]).elementOf(&self.gear)).and(&self.door.equal(&DOOR_STATE::open))).booleanValue() {
            let mut _ld_gears = self.gears.clone();
            self.gears = _ld_gears._override(&BRelation::new(vec![BTuple::from_refs(&gr, &GEAR_STATE::gear_moving)])).clone().clone();
            self.gear = GEAR_STATE::gear_moving;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_extend_gear_last(&mut self, mut gr: POSITION) -> () {
        if (self.gears.domain().elementOf(&gr).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open]))).and(&self.handle.equal(&HANDLE_STATE::down)).and(&self.gears.relationImage(&self._POSITION.difference(&BSet::new(vec![gr]))).equal(&BSet::new(vec![GEAR_STATE::extended]))).and(&self.gears.functionCall(&gr).equal(&GEAR_STATE::gear_moving)).and(&self.general_valve.equal(&VALVE_STATE::valve_open)).and(&self.gear.equal(&GEAR_STATE::gear_moving)).and(&self.door.equal(&DOOR_STATE::open))).booleanValue() {
            let mut _ld_gears = self.gears.clone();
            self.gears = _ld_gears._override(&BRelation::new(vec![BTuple::from_refs(&gr, &GEAR_STATE::extended)])).clone().clone();
            self.gear = GEAR_STATE::extended;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_extend_gear_skip(&mut self, mut gr: POSITION) -> () {
        if (self.gears.domain().elementOf(&gr).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open]))).and(&self.handle.equal(&HANDLE_STATE::down)).and(&self.gears.relationImage(&self._POSITION.difference(&BSet::new(vec![gr]))).unequal(&BSet::new(vec![GEAR_STATE::extended]))).and(&self.gears.functionCall(&gr).equal(&GEAR_STATE::gear_moving)).and(&self.general_valve.equal(&VALVE_STATE::valve_open))).booleanValue() {
            self.gears = self.gears._override(&BRelation::new(vec![BTuple::from_refs(&gr, &GEAR_STATE::extended)])).clone().clone();
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_start_open_door(&mut self, mut gr: POSITION) -> () {
        if (self.gears.domain().elementOf(&gr).and(&self.doors.functionCall(&gr).equal(&DOOR_STATE::closed)).and(&self.gears.functionCall(&gr).unequal(&GEAR_STATE::gear_moving)).and(&self.gears.range().notElementOf(&GEAR_STATE::gear_moving)).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted]))).or(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))))).and(&self.valve_open_door.equal(&VALVE_STATE::valve_open)).and(&self.general_valve.equal(&VALVE_STATE::valve_open)).and(&BSet::new(vec![DOOR_STATE::closed, DOOR_STATE::door_moving]).elementOf(&self.door)).and(&self.gear.unequal(&GEAR_STATE::gear_moving)).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gear.equal(&GEAR_STATE::retracted)).or(&self.handle.equal(&HANDLE_STATE::up).and(&self.gear.equal(&GEAR_STATE::extended))))).booleanValue() {
            let mut _ld_doors = self.doors.clone();
            self.doors = _ld_doors._override(&BRelation::new(vec![BTuple::from_refs(&gr, &DOOR_STATE::door_moving)])).clone().clone();
            self.door = DOOR_STATE::door_moving;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_open_door_last(&mut self, mut gr: POSITION) -> () {
        if (self.gears.domain().elementOf(&gr).and(&self.doors.functionCall(&gr).equal(&DOOR_STATE::door_moving)).and(&self.gears.functionCall(&gr).unequal(&GEAR_STATE::gear_moving)).and(&self.gears.range().notElementOf(&GEAR_STATE::gear_moving)).and(&self.doors.relationImage(&self._POSITION.difference(&BSet::new(vec![gr]))).equal(&BSet::new(vec![DOOR_STATE::open]))).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted]))).or(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))))).and(&self.valve_open_door.equal(&VALVE_STATE::valve_open)).and(&self.general_valve.equal(&VALVE_STATE::valve_open)).and(&self.door.equal(&DOOR_STATE::door_moving)).and(&self.gear.unequal(&GEAR_STATE::gear_moving)).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gear.equal(&GEAR_STATE::retracted)).or(&self.handle.equal(&HANDLE_STATE::up).and(&self.gear.equal(&GEAR_STATE::extended))))).booleanValue() {
            let mut _ld_doors = self.doors.clone();
            self.doors = _ld_doors._override(&BRelation::new(vec![BTuple::from_refs(&gr, &DOOR_STATE::open)])).clone().clone();
            self.door = DOOR_STATE::open;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_open_door_skip(&mut self, mut gr: POSITION) -> () {
        if (self.gears.domain().elementOf(&gr).and(&self.doors.functionCall(&gr).equal(&DOOR_STATE::door_moving)).and(&self.gears.functionCall(&gr).unequal(&GEAR_STATE::gear_moving)).and(&self.gears.range().notElementOf(&GEAR_STATE::gear_moving)).and(&self.doors.relationImage(&self._POSITION.difference(&BSet::new(vec![gr]))).unequal(&BSet::new(vec![DOOR_STATE::open]))).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted]))).or(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))))).and(&self.valve_open_door.equal(&VALVE_STATE::valve_open)).and(&self.general_valve.equal(&VALVE_STATE::valve_open))).booleanValue() {
            self.doors = self.doors._override(&BRelation::new(vec![BTuple::from_refs(&gr, &DOOR_STATE::open)])).clone().clone();
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_start_close_door(&mut self, mut gr: POSITION) -> () {
        if (self.gears.domain().elementOf(&gr).and(&self.doors.functionCall(&gr).equal(&DOOR_STATE::open)).and(&self.gears.functionCall(&gr).unequal(&GEAR_STATE::gear_moving)).and(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted])).or(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended])))).or(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))))).and(&self.valve_close_door.equal(&VALVE_STATE::valve_open)).and(&self.general_valve.equal(&VALVE_STATE::valve_open)).and(&BSet::new(vec![DOOR_STATE::door_moving, DOOR_STATE::open]).elementOf(&self.door)).and(&self.gear.unequal(&GEAR_STATE::gear_moving)).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gear.equal(&GEAR_STATE::extended)).or(&self.handle.equal(&HANDLE_STATE::up).and(&BSet::new(vec![GEAR_STATE::extended, GEAR_STATE::retracted]).elementOf(&self.gear))))).booleanValue() {
            let mut _ld_doors = self.doors.clone();
            self.doors = _ld_doors._override(&BRelation::new(vec![BTuple::from_refs(&gr, &DOOR_STATE::door_moving)])).clone().clone();
            self.door = DOOR_STATE::door_moving;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_close_door(&mut self, mut gr: POSITION) -> () {
        if (self.gears.domain().elementOf(&gr).and(&self.doors.functionCall(&gr).equal(&DOOR_STATE::door_moving)).and(&self.gears.functionCall(&gr).unequal(&GEAR_STATE::gear_moving)).and(&self.gears.range().notElementOf(&GEAR_STATE::gear_moving)).and(&self.doors.relationImage(&self._POSITION.difference(&BSet::new(vec![gr]))).equal(&BSet::new(vec![DOOR_STATE::closed]))).and(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted])).or(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended])))).or(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))))).and(&self.valve_close_door.equal(&VALVE_STATE::valve_open)).and(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))).implies(&self.shock_absorber.equal(&PLANE_STATE::ground))).and(&self.general_valve.equal(&VALVE_STATE::valve_open)).and(&self.door.equal(&DOOR_STATE::door_moving)).and(&self.gear.unequal(&GEAR_STATE::gear_moving)).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gear.equal(&GEAR_STATE::extended)).or(&self.handle.equal(&HANDLE_STATE::up).and(&BSet::new(vec![GEAR_STATE::extended, GEAR_STATE::retracted]).elementOf(&self.gear))))).booleanValue() {
            let mut _ld_doors = self.doors.clone();
            self.doors = _ld_doors._override(&BRelation::new(vec![BTuple::from_refs(&gr, &DOOR_STATE::closed)])).clone().clone();
            self.door = DOOR_STATE::closed;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_close_door_skip(&mut self, mut gr: POSITION) -> () {
        if (self.gears.domain().elementOf(&gr).and(&self.doors.functionCall(&gr).equal(&DOOR_STATE::door_moving)).and(&self.gears.functionCall(&gr).unequal(&GEAR_STATE::gear_moving)).and(&self.gears.range().notElementOf(&GEAR_STATE::gear_moving)).and(&self.doors.relationImage(&self._POSITION.difference(&BSet::new(vec![gr]))).unequal(&BSet::new(vec![DOOR_STATE::closed]))).and(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted])).or(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended])))).or(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))))).and(&self.valve_close_door.equal(&VALVE_STATE::valve_open)).and(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))).implies(&self.shock_absorber.equal(&PLANE_STATE::ground))).and(&self.general_valve.equal(&VALVE_STATE::valve_open))).booleanValue() {
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
        if (self.general_EV.equal(&BBoolean::new(false)).and(&self.handle_move.equal(&BBoolean::new(true)))).booleanValue() {
            self.general_EV = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn con_stop_stimulate_general_valve(&mut self) -> () {
        if (self.general_EV.equal(&BBoolean::new(true)).and(&self.open_EV.equal(&BBoolean::new(false))).and(&self.close_EV.equal(&BBoolean::new(false))).and(&self.retract_EV.equal(&BBoolean::new(false))).and(&self.extend_EV.equal(&BBoolean::new(false))).and(&self.close_EV.equal(&BBoolean::new(false))).and(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted]))).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed]))).and(&self.open_EV.equal(&BBoolean::new(false))).or(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed]))).and(&self.open_EV.equal(&BBoolean::new(false)))).or(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed]))).and(&self.open_EV.equal(&BBoolean::new(false)))))).booleanValue() {
            self.general_EV = BBoolean::new(false);
            self.handle_move = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn evn_open_general_valve(&mut self) -> () {
        if (self.general_EV.equal(&BBoolean::new(true)).and(&self.general_valve.equal(&VALVE_STATE::valve_closed)).and(&self.analogical_switch.equal(&SWITCH_STATE::switch_closed))).booleanValue() {
            self.general_valve = VALVE_STATE::valve_open;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn evn_close_general_valve(&mut self) -> () {
        if (self.general_EV.equal(&BBoolean::new(false)).or(&self.analogical_switch.equal(&SWITCH_STATE::switch_open)).and(&self.general_valve.equal(&VALVE_STATE::valve_open))).booleanValue() {
            self.general_valve = VALVE_STATE::valve_closed;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn env_close_analogical_switch(&mut self) -> () {
        if (self.analogical_switch.equal(&SWITCH_STATE::switch_open).and(&self.handle_move.equal(&BBoolean::new(true)))).booleanValue() {
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
            let mut __tmp__val__ = self.valve_open_door.equal(&VALVE_STATE::valve_closed).and(&self.open_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_open_valve_door_open = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_open_valve_door_open.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_close_valve_door_open(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_close_valve_door_open.is_none() {
            let mut __tmp__val__ = self.valve_open_door.equal(&VALVE_STATE::valve_open).and(&self.open_EV.equal(&BBoolean::new(false))).booleanValue();
            self._tr_cache_close_valve_door_open = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_close_valve_door_open.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_open_valve_door_close(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_open_valve_door_close.is_none() {
            let mut __tmp__val__ = self.valve_close_door.equal(&VALVE_STATE::valve_closed).and(&self.close_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_open_valve_door_close = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_open_valve_door_close.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_close_valve_door_close(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_close_valve_door_close.is_none() {
            let mut __tmp__val__ = self.valve_close_door.equal(&VALVE_STATE::valve_open).and(&self.close_EV.equal(&BBoolean::new(false))).booleanValue();
            self._tr_cache_close_valve_door_close = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_close_valve_door_close.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_open_valve_retract_gear(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_open_valve_retract_gear.is_none() {
            let mut __tmp__val__ = self.valve_retract_gear.equal(&VALVE_STATE::valve_closed).and(&self.retract_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_open_valve_retract_gear = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_open_valve_retract_gear.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_close_valve_retract_gear(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_close_valve_retract_gear.is_none() {
            let mut __tmp__val__ = self.valve_retract_gear.equal(&VALVE_STATE::valve_open).and(&self.retract_EV.equal(&BBoolean::new(false))).booleanValue();
            self._tr_cache_close_valve_retract_gear = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_close_valve_retract_gear.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_open_valve_extend_gear(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_open_valve_extend_gear.is_none() {
            let mut __tmp__val__ = self.valve_extend_gear.equal(&VALVE_STATE::valve_closed).and(&self.extend_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_open_valve_extend_gear = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_open_valve_extend_gear.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_close_valve_extend_gear(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_close_valve_extend_gear.is_none() {
            let mut __tmp__val__ = self.valve_extend_gear.equal(&VALVE_STATE::valve_open).and(&self.extend_EV.equal(&BBoolean::new(false))).booleanValue();
            self._tr_cache_close_valve_extend_gear = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_close_valve_extend_gear.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stimulate_open_door_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stimulate_open_door_valve.is_none() {
            let mut __tmp__val__ = self.open_EV.equal(&BBoolean::new(false)).and(&self.close_EV.equal(&BBoolean::new(false))).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended])).not()).or(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted])).not()).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open])).and(&self.shock_absorber.equal(&PLANE_STATE::ground)).not()))).and(&self.general_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_con_stimulate_open_door_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stimulate_open_door_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stop_stimulate_open_door_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stop_stimulate_open_door_valve.is_none() {
            let mut __tmp__val__ = self.open_EV.equal(&BBoolean::new(true)).and(&self.extend_EV.equal(&BBoolean::new(false))).and(&self.retract_EV.equal(&BBoolean::new(false))).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))).or(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted])).or(&self.shock_absorber.equal(&PLANE_STATE::ground))).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open]))))).and(&self.general_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_con_stop_stimulate_open_door_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stop_stimulate_open_door_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stimulate_close_door_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stimulate_close_door_valve.is_none() {
            let mut __tmp__val__ = self.close_EV.equal(&BBoolean::new(false)).and(&self.open_EV.equal(&BBoolean::new(false))).and(&self.extend_EV.equal(&BBoolean::new(false))).and(&self.retract_EV.equal(&BBoolean::new(false))).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))).or(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted])).or(&self.shock_absorber.equal(&PLANE_STATE::ground))))).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed])).not()).and(&self.general_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_con_stimulate_close_door_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stimulate_close_door_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stop_stimulate_close_door_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stop_stimulate_close_door_valve.is_none() {
            let mut __tmp__val__ = self.close_EV.equal(&BBoolean::new(true)).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed]))).or(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted])).or(&self.shock_absorber.equal(&PLANE_STATE::ground))).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed]))))).and(&self.general_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_con_stop_stimulate_close_door_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stop_stimulate_close_door_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stimulate_retract_gear_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stimulate_retract_gear_valve.is_none() {
            let mut __tmp__val__ = self.retract_EV.equal(&BBoolean::new(false)).and(&self.extend_EV.equal(&BBoolean::new(false))).and(&self.open_EV.equal(&BBoolean::new(true))).and(&self.handle.equal(&HANDLE_STATE::up)).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted])).not()).and(&self.shock_absorber.equal(&PLANE_STATE::flight)).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open]))).and(&self.general_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_con_stimulate_retract_gear_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stimulate_retract_gear_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stop_stimulate_retract_gear_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stop_stimulate_retract_gear_valve.is_none() {
            let mut __tmp__val__ = self.retract_EV.equal(&BBoolean::new(true)).and(&self.handle.equal(&HANDLE_STATE::down).or(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted])))).and(&self.general_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_con_stop_stimulate_retract_gear_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stop_stimulate_retract_gear_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stimulate_extend_gear_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stimulate_extend_gear_valve.is_none() {
            let mut __tmp__val__ = self.extend_EV.equal(&BBoolean::new(false)).and(&self.retract_EV.equal(&BBoolean::new(false))).and(&self.open_EV.equal(&BBoolean::new(true))).and(&self.handle.equal(&HANDLE_STATE::down)).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended])).not()).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open]))).and(&self.general_EV.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_con_stimulate_extend_gear_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stimulate_extend_gear_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stop_stimulate_extend_gear_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stop_stimulate_extend_gear_valve.is_none() {
            let mut __tmp__val__ = self.extend_EV.equal(&BBoolean::new(true)).and(&self.handle.equal(&HANDLE_STATE::up).or(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended])))).and(&self.general_EV.equal(&BBoolean::new(true))).booleanValue();
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
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                if (self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open])).and(&self.handle.equal(&HANDLE_STATE::up)).and(&self.gears.functionCall(&_ic_gr_1).equal(&GEAR_STATE::extended)).and(&self.valve_retract_gear.equal(&VALVE_STATE::valve_open)).and(&self.general_valve.equal(&VALVE_STATE::valve_open)).and(&BSet::new(vec![GEAR_STATE::extended, GEAR_STATE::gear_moving]).elementOf(&self.gear)).and(&self.door.equal(&DOOR_STATE::open))).booleanValue() {
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
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                if (self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open])).and(&self.gears.relationImage(&self._POSITION.difference(&BSet::new(vec![_ic_gr_1]))).unequal(&BSet::new(vec![GEAR_STATE::retracted]))).and(&self.handle.equal(&HANDLE_STATE::up)).and(&self.gears.functionCall(&_ic_gr_1).equal(&GEAR_STATE::gear_moving)).and(&self.general_valve.equal(&VALVE_STATE::valve_open))).booleanValue() {
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
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                if (self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open])).and(&self.gears.relationImage(&self._POSITION.difference(&BSet::new(vec![_ic_gr_1]))).equal(&BSet::new(vec![GEAR_STATE::retracted]))).and(&self.handle.equal(&HANDLE_STATE::up)).and(&self.gears.functionCall(&_ic_gr_1).equal(&GEAR_STATE::gear_moving)).and(&self.general_valve.equal(&VALVE_STATE::valve_open)).and(&self.gear.equal(&GEAR_STATE::gear_moving)).and(&self.door.equal(&DOOR_STATE::open))).booleanValue() {
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
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                if (self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open])).and(&self.handle.equal(&HANDLE_STATE::down)).and(&self.gears.functionCall(&_ic_gr_1).equal(&GEAR_STATE::retracted)).and(&self.valve_extend_gear.equal(&VALVE_STATE::valve_open)).and(&self.general_valve.equal(&VALVE_STATE::valve_open)).and(&BSet::new(vec![GEAR_STATE::gear_moving, GEAR_STATE::retracted]).elementOf(&self.gear)).and(&self.door.equal(&DOOR_STATE::open))).booleanValue() {
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
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                if (self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open])).and(&self.handle.equal(&HANDLE_STATE::down)).and(&self.gears.relationImage(&self._POSITION.difference(&BSet::new(vec![_ic_gr_1]))).equal(&BSet::new(vec![GEAR_STATE::extended]))).and(&self.gears.functionCall(&_ic_gr_1).equal(&GEAR_STATE::gear_moving)).and(&self.general_valve.equal(&VALVE_STATE::valve_open)).and(&self.gear.equal(&GEAR_STATE::gear_moving)).and(&self.door.equal(&DOOR_STATE::open))).booleanValue() {
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
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                if (self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open])).and(&self.handle.equal(&HANDLE_STATE::down)).and(&self.gears.relationImage(&self._POSITION.difference(&BSet::new(vec![_ic_gr_1]))).unequal(&BSet::new(vec![GEAR_STATE::extended]))).and(&self.gears.functionCall(&_ic_gr_1).equal(&GEAR_STATE::gear_moving)).and(&self.general_valve.equal(&VALVE_STATE::valve_open))).booleanValue() {
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
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                if (self.doors.functionCall(&_ic_gr_1).equal(&DOOR_STATE::closed).and(&self.gears.functionCall(&_ic_gr_1).unequal(&GEAR_STATE::gear_moving)).and(&self.gears.range().notElementOf(&GEAR_STATE::gear_moving)).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted]))).or(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))))).and(&self.valve_open_door.equal(&VALVE_STATE::valve_open)).and(&self.general_valve.equal(&VALVE_STATE::valve_open)).and(&BSet::new(vec![DOOR_STATE::closed, DOOR_STATE::door_moving]).elementOf(&self.door)).and(&self.gear.unequal(&GEAR_STATE::gear_moving)).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gear.equal(&GEAR_STATE::retracted)).or(&self.handle.equal(&HANDLE_STATE::up).and(&self.gear.equal(&GEAR_STATE::extended))))).booleanValue() {
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
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                if (self.doors.functionCall(&_ic_gr_1).equal(&DOOR_STATE::door_moving).and(&self.gears.functionCall(&_ic_gr_1).unequal(&GEAR_STATE::gear_moving)).and(&self.gears.range().notElementOf(&GEAR_STATE::gear_moving)).and(&self.doors.relationImage(&self._POSITION.difference(&BSet::new(vec![_ic_gr_1]))).equal(&BSet::new(vec![DOOR_STATE::open]))).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted]))).or(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))))).and(&self.valve_open_door.equal(&VALVE_STATE::valve_open)).and(&self.general_valve.equal(&VALVE_STATE::valve_open)).and(&self.door.equal(&DOOR_STATE::door_moving)).and(&self.gear.unequal(&GEAR_STATE::gear_moving)).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gear.equal(&GEAR_STATE::retracted)).or(&self.handle.equal(&HANDLE_STATE::up).and(&self.gear.equal(&GEAR_STATE::extended))))).booleanValue() {
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
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                if (self.doors.functionCall(&_ic_gr_1).equal(&DOOR_STATE::door_moving).and(&self.gears.functionCall(&_ic_gr_1).unequal(&GEAR_STATE::gear_moving)).and(&self.gears.range().notElementOf(&GEAR_STATE::gear_moving)).and(&self.doors.relationImage(&self._POSITION.difference(&BSet::new(vec![_ic_gr_1]))).unequal(&BSet::new(vec![DOOR_STATE::open]))).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted]))).or(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))))).and(&self.valve_open_door.equal(&VALVE_STATE::valve_open)).and(&self.general_valve.equal(&VALVE_STATE::valve_open))).booleanValue() {
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
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                if (self.doors.functionCall(&_ic_gr_1).equal(&DOOR_STATE::open).and(&self.gears.functionCall(&_ic_gr_1).unequal(&GEAR_STATE::gear_moving)).and(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted])).or(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended])))).or(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))))).and(&self.valve_close_door.equal(&VALVE_STATE::valve_open)).and(&self.general_valve.equal(&VALVE_STATE::valve_open)).and(&BSet::new(vec![DOOR_STATE::door_moving, DOOR_STATE::open]).elementOf(&self.door)).and(&self.gear.unequal(&GEAR_STATE::gear_moving)).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gear.equal(&GEAR_STATE::extended)).or(&self.handle.equal(&HANDLE_STATE::up).and(&BSet::new(vec![GEAR_STATE::extended, GEAR_STATE::retracted]).elementOf(&self.gear))))).booleanValue() {
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
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                if (self.doors.functionCall(&_ic_gr_1).equal(&DOOR_STATE::door_moving).and(&self.gears.functionCall(&_ic_gr_1).unequal(&GEAR_STATE::gear_moving)).and(&self.gears.range().notElementOf(&GEAR_STATE::gear_moving)).and(&self.doors.relationImage(&self._POSITION.difference(&BSet::new(vec![_ic_gr_1]))).equal(&BSet::new(vec![DOOR_STATE::closed]))).and(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted])).or(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended])))).or(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))))).and(&self.valve_close_door.equal(&VALVE_STATE::valve_open)).and(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))).implies(&self.shock_absorber.equal(&PLANE_STATE::ground))).and(&self.general_valve.equal(&VALVE_STATE::valve_open)).and(&self.door.equal(&DOOR_STATE::door_moving)).and(&self.gear.unequal(&GEAR_STATE::gear_moving)).and(&self.handle.equal(&HANDLE_STATE::down).and(&self.gear.equal(&GEAR_STATE::extended)).or(&self.handle.equal(&HANDLE_STATE::up).and(&BSet::new(vec![GEAR_STATE::extended, GEAR_STATE::retracted]).elementOf(&self.gear))))).booleanValue() {
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
            for _ic_gr_1 in self.gears.domain().clone().iter().cloned() {
                if (self.doors.functionCall(&_ic_gr_1).equal(&DOOR_STATE::door_moving).and(&self.gears.functionCall(&_ic_gr_1).unequal(&GEAR_STATE::gear_moving)).and(&self.gears.range().notElementOf(&GEAR_STATE::gear_moving)).and(&self.doors.relationImage(&self._POSITION.difference(&BSet::new(vec![_ic_gr_1]))).unequal(&BSet::new(vec![DOOR_STATE::closed]))).and(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted])).or(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended])))).or(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))))).and(&self.valve_close_door.equal(&VALVE_STATE::valve_open)).and(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))).implies(&self.shock_absorber.equal(&PLANE_STATE::ground))).and(&self.general_valve.equal(&VALVE_STATE::valve_open))).booleanValue() {
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
            let mut __tmp__val__ = self.general_EV.equal(&BBoolean::new(false)).and(&self.handle_move.equal(&BBoolean::new(true))).booleanValue();
            self._tr_cache_con_stimulate_general_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stimulate_general_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_con_stop_stimulate_general_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_con_stop_stimulate_general_valve.is_none() {
            let mut __tmp__val__ = self.general_EV.equal(&BBoolean::new(true)).and(&self.open_EV.equal(&BBoolean::new(false))).and(&self.close_EV.equal(&BBoolean::new(false))).and(&self.retract_EV.equal(&BBoolean::new(false))).and(&self.extend_EV.equal(&BBoolean::new(false))).and(&self.close_EV.equal(&BBoolean::new(false))).and(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted]))).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed]))).and(&self.open_EV.equal(&BBoolean::new(false))).or(&self.handle.equal(&HANDLE_STATE::down).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed]))).and(&self.open_EV.equal(&BBoolean::new(false)))).or(&self.handle.equal(&HANDLE_STATE::up).and(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))).and(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed]))).and(&self.open_EV.equal(&BBoolean::new(false))))).booleanValue();
            self._tr_cache_con_stop_stimulate_general_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_con_stop_stimulate_general_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_evn_open_general_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_evn_open_general_valve.is_none() {
            let mut __tmp__val__ = self.general_EV.equal(&BBoolean::new(true)).and(&self.general_valve.equal(&VALVE_STATE::valve_closed)).and(&self.analogical_switch.equal(&SWITCH_STATE::switch_closed)).booleanValue();
            self._tr_cache_evn_open_general_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_evn_open_general_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_evn_close_general_valve(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_evn_close_general_valve.is_none() {
            let mut __tmp__val__ = self.general_EV.equal(&BBoolean::new(false)).or(&self.analogical_switch.equal(&SWITCH_STATE::switch_open)).and(&self.general_valve.equal(&VALVE_STATE::valve_open)).booleanValue();
            self._tr_cache_evn_close_general_valve = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_evn_close_general_valve.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_env_close_analogical_switch(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_env_close_analogical_switch.is_none() {
            let mut __tmp__val__ = self.analogical_switch.equal(&SWITCH_STATE::switch_open).and(&self.handle_move.equal(&BBoolean::new(true))).booleanValue();
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
        return butils::BOOL.elementOf(&self.general_EV).booleanValue();
    }

    pub fn _check_inv_3(&self) -> bool {
        //invariant
        return self._VALVE_STATE.elementOf(&self.general_valve).booleanValue();
    }

    pub fn _check_inv_4(&self) -> bool {
        //invariant
        return butils::BOOL.elementOf(&self.handle_move).booleanValue();
    }

    pub fn _check_inv_5(&self) -> bool {
        //invariant
        return butils::BOOL.elementOf(&self.close_EV).booleanValue();
    }

    pub fn _check_inv_6(&self) -> bool {
        //invariant
        return butils::BOOL.elementOf(&self.extend_EV).booleanValue();
    }

    pub fn _check_inv_7(&self) -> bool {
        //invariant
        return butils::BOOL.elementOf(&self.open_EV).booleanValue();
    }

    pub fn _check_inv_8(&self) -> bool {
        //invariant
        return butils::BOOL.elementOf(&self.retract_EV).booleanValue();
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
        return self.open_EV.equal(&BBoolean::new(true)).or(&self.close_EV.equal(&BBoolean::new(true))).or(&self.retract_EV.equal(&BBoolean::new(true))).or(&self.extend_EV.equal(&BBoolean::new(true))).implies(&self.general_EV.equal(&BBoolean::new(true))).booleanValue();
    }

    pub fn _check_inv_18(&self) -> bool {
        //invariant
        return self.open_EV.equal(&BBoolean::new(true)).and(&self.close_EV.equal(&BBoolean::new(true))).not().booleanValue();
    }

    pub fn _check_inv_19(&self) -> bool {
        //invariant
        return self.gears.checkDomain(&self._POSITION).and(&self.gears.checkRange(&self._GEAR_STATE)).and(&self.gears.isFunction()).and(&self.gears.isTotal(&self._POSITION)).booleanValue();
    }

    pub fn _check_inv_20(&self) -> bool {
        //invariant
        return self.doors.checkDomain(&self._POSITION).and(&self.doors.checkRange(&self._DOOR_STATE)).and(&self.doors.isFunction()).and(&self.doors.isTotal(&self._POSITION)).booleanValue();
    }

    pub fn _check_inv_21(&self) -> bool {
        //invariant
        return self.door.equal(&DOOR_STATE::closed).equivalent(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::closed]))).booleanValue();
    }

    pub fn _check_inv_22(&self) -> bool {
        //invariant
        return self.door.equal(&DOOR_STATE::open).equivalent(&self.doors.range().equal(&BSet::new(vec![DOOR_STATE::open]))).booleanValue();
    }

    pub fn _check_inv_23(&self) -> bool {
        //invariant
        return self.gear.equal(&GEAR_STATE::extended).equivalent(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::extended]))).booleanValue();
    }

    pub fn _check_inv_24(&self) -> bool {
        //invariant
        return self.gear.equal(&GEAR_STATE::retracted).equivalent(&self.gears.range().equal(&BSet::new(vec![GEAR_STATE::retracted]))).booleanValue();
    }

    pub fn _check_inv_25(&self) -> bool {
        //invariant
        return self.gear.equal(&GEAR_STATE::gear_moving).implies(&self.door.equal(&DOOR_STATE::open)).booleanValue();
    }

    fn invalidate_caches(&mut self, to_invalidate: &HashSet<&'static str>) {
        //calling the given functions without caching will recalculate them and cache them afterwards
        //if caching is enabled globally, this will just prefill those, if caching is
        for trans in to_invalidate.iter() {
            match *trans {
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
                          invariant_dependency: &HashMap<&str, HashSet<&'static str>>,
                          dependent_invariant_m: Arc<Mutex<HashMap<LandingGear_R6, HashSet<&str>>>>,
                          guard_dependency: &HashMap<&str, HashSet<&'static str>>,
                          dependent_guard_m: Arc<Mutex<HashMap<LandingGear_R6, HashSet<&str>>>>,
                          guardCache: Arc<Mutex<HashMap<LandingGear_R6, PersistentHashMap<&str, bool>>>>,
                          parents_m: Arc<Mutex<HashMap<LandingGear_R6, LandingGear_R6>>>,
                          transitions: Arc<AtomicI64>) -> HashSet<LandingGear_R6> {
        let mut result = HashSet::<LandingGear_R6>::new();
        if isCaching {
            let mut parents_guard_o = parents_m.lock().unwrap().get(state).and_then(|p| guardCache.lock().unwrap().get(p).cloned());
            let mut newCache = if parents_guard_o.is_none() { PersistentHashMap::new() } else { parents_guard_o.as_ref().unwrap().clone() };
            //model_check_transition
            let mut _trid_1 = state._tr_begin_flying(isCaching);
            if _trid_1 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.begin_flying();
                match guard_dependency.get("begin_flying") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("begin_flying").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("begin_flying").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_2 = state._tr_land_plane(isCaching);
            if _trid_2 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.land_plane();
                match guard_dependency.get("land_plane") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("land_plane").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("land_plane").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_3 = state._tr_open_valve_door_open(isCaching);
            if _trid_3 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.open_valve_door_open();
                match guard_dependency.get("open_valve_door_open") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("open_valve_door_open").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("open_valve_door_open").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_4 = state._tr_close_valve_door_open(isCaching);
            if _trid_4 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.close_valve_door_open();
                match guard_dependency.get("close_valve_door_open") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("close_valve_door_open").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("close_valve_door_open").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_5 = state._tr_open_valve_door_close(isCaching);
            if _trid_5 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.open_valve_door_close();
                match guard_dependency.get("open_valve_door_close") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("open_valve_door_close").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("open_valve_door_close").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_6 = state._tr_close_valve_door_close(isCaching);
            if _trid_6 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.close_valve_door_close();
                match guard_dependency.get("close_valve_door_close") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("close_valve_door_close").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("close_valve_door_close").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_7 = state._tr_open_valve_retract_gear(isCaching);
            if _trid_7 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.open_valve_retract_gear();
                match guard_dependency.get("open_valve_retract_gear") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("open_valve_retract_gear").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("open_valve_retract_gear").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_8 = state._tr_close_valve_retract_gear(isCaching);
            if _trid_8 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.close_valve_retract_gear();
                match guard_dependency.get("close_valve_retract_gear") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("close_valve_retract_gear").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("close_valve_retract_gear").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_9 = state._tr_open_valve_extend_gear(isCaching);
            if _trid_9 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.open_valve_extend_gear();
                match guard_dependency.get("open_valve_extend_gear") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("open_valve_extend_gear").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("open_valve_extend_gear").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_10 = state._tr_close_valve_extend_gear(isCaching);
            if _trid_10 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.close_valve_extend_gear();
                match guard_dependency.get("close_valve_extend_gear") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("close_valve_extend_gear").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("close_valve_extend_gear").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_11 = state._tr_con_stimulate_open_door_valve(isCaching);
            if _trid_11 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.con_stimulate_open_door_valve();
                match guard_dependency.get("con_stimulate_open_door_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("con_stimulate_open_door_valve").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("con_stimulate_open_door_valve").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_12 = state._tr_con_stop_stimulate_open_door_valve(isCaching);
            if _trid_12 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.con_stop_stimulate_open_door_valve();
                match guard_dependency.get("con_stop_stimulate_open_door_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("con_stop_stimulate_open_door_valve").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("con_stop_stimulate_open_door_valve").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_13 = state._tr_con_stimulate_close_door_valve(isCaching);
            if _trid_13 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.con_stimulate_close_door_valve();
                match guard_dependency.get("con_stimulate_close_door_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("con_stimulate_close_door_valve").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("con_stimulate_close_door_valve").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_14 = state._tr_con_stop_stimulate_close_door_valve(isCaching);
            if _trid_14 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.con_stop_stimulate_close_door_valve();
                match guard_dependency.get("con_stop_stimulate_close_door_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("con_stop_stimulate_close_door_valve").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("con_stop_stimulate_close_door_valve").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_15 = state._tr_con_stimulate_retract_gear_valve(isCaching);
            if _trid_15 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.con_stimulate_retract_gear_valve();
                match guard_dependency.get("con_stimulate_retract_gear_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("con_stimulate_retract_gear_valve").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("con_stimulate_retract_gear_valve").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_16 = state._tr_con_stop_stimulate_retract_gear_valve(isCaching);
            if _trid_16 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.con_stop_stimulate_retract_gear_valve();
                match guard_dependency.get("con_stop_stimulate_retract_gear_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("con_stop_stimulate_retract_gear_valve").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("con_stop_stimulate_retract_gear_valve").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_17 = state._tr_con_stimulate_extend_gear_valve(isCaching);
            if _trid_17 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.con_stimulate_extend_gear_valve();
                match guard_dependency.get("con_stimulate_extend_gear_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("con_stimulate_extend_gear_valve").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("con_stimulate_extend_gear_valve").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_18 = state._tr_con_stop_stimulate_extend_gear_valve(isCaching);
            if _trid_18 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.con_stop_stimulate_extend_gear_valve();
                match guard_dependency.get("con_stop_stimulate_extend_gear_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("con_stop_stimulate_extend_gear_valve").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("con_stop_stimulate_extend_gear_valve").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_19 = state._tr_env_start_retracting_first(isCaching);
            for param in _trid_19.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_start_retracting_first(_tmp_1);
                match guard_dependency.get("env_start_retracting_first") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("env_start_retracting_first").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("env_start_retracting_first").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_20 = state._tr_env_retract_gear_skip(isCaching);
            for param in _trid_20.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_retract_gear_skip(_tmp_1);
                match guard_dependency.get("env_retract_gear_skip") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("env_retract_gear_skip").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("env_retract_gear_skip").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_21 = state._tr_env_retract_gear_last(isCaching);
            for param in _trid_21.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_retract_gear_last(_tmp_1);
                match guard_dependency.get("env_retract_gear_last") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("env_retract_gear_last").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("env_retract_gear_last").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_22 = state._tr_env_start_extending(isCaching);
            for param in _trid_22.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_start_extending(_tmp_1);
                match guard_dependency.get("env_start_extending") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("env_start_extending").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("env_start_extending").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_23 = state._tr_env_extend_gear_last(isCaching);
            for param in _trid_23.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_extend_gear_last(_tmp_1);
                match guard_dependency.get("env_extend_gear_last") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("env_extend_gear_last").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("env_extend_gear_last").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_24 = state._tr_env_extend_gear_skip(isCaching);
            for param in _trid_24.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_extend_gear_skip(_tmp_1);
                match guard_dependency.get("env_extend_gear_skip") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("env_extend_gear_skip").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("env_extend_gear_skip").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_25 = state._tr_env_start_open_door(isCaching);
            for param in _trid_25.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_start_open_door(_tmp_1);
                match guard_dependency.get("env_start_open_door") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("env_start_open_door").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("env_start_open_door").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_26 = state._tr_env_open_door_last(isCaching);
            for param in _trid_26.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_open_door_last(_tmp_1);
                match guard_dependency.get("env_open_door_last") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("env_open_door_last").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("env_open_door_last").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_27 = state._tr_env_open_door_skip(isCaching);
            for param in _trid_27.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_open_door_skip(_tmp_1);
                match guard_dependency.get("env_open_door_skip") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("env_open_door_skip").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("env_open_door_skip").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_28 = state._tr_env_start_close_door(isCaching);
            for param in _trid_28.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_start_close_door(_tmp_1);
                match guard_dependency.get("env_start_close_door") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("env_start_close_door").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("env_start_close_door").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_29 = state._tr_env_close_door(isCaching);
            for param in _trid_29.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_close_door(_tmp_1);
                match guard_dependency.get("env_close_door") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("env_close_door").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("env_close_door").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_30 = state._tr_env_close_door_skip(isCaching);
            for param in _trid_30.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_close_door_skip(_tmp_1);
                match guard_dependency.get("env_close_door_skip") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("env_close_door_skip").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("env_close_door_skip").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_31 = state._tr_toggle_handle_up(isCaching);
            if _trid_31 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.toggle_handle_up();
                match guard_dependency.get("toggle_handle_up") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("toggle_handle_up").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("toggle_handle_up").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_32 = state._tr_toggle_handle_down(isCaching);
            if _trid_32 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.toggle_handle_down();
                match guard_dependency.get("toggle_handle_down") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("toggle_handle_down").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("toggle_handle_down").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_33 = state._tr_con_stimulate_general_valve(isCaching);
            if _trid_33 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.con_stimulate_general_valve();
                match guard_dependency.get("con_stimulate_general_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("con_stimulate_general_valve").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("con_stimulate_general_valve").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_34 = state._tr_con_stop_stimulate_general_valve(isCaching);
            if _trid_34 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.con_stop_stimulate_general_valve();
                match guard_dependency.get("con_stop_stimulate_general_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("con_stop_stimulate_general_valve").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("con_stop_stimulate_general_valve").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_35 = state._tr_evn_open_general_valve(isCaching);
            if _trid_35 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.evn_open_general_valve();
                match guard_dependency.get("evn_open_general_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("evn_open_general_valve").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("evn_open_general_valve").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_36 = state._tr_evn_close_general_valve(isCaching);
            if _trid_36 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.evn_close_general_valve();
                match guard_dependency.get("evn_close_general_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("evn_close_general_valve").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("evn_close_general_valve").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_37 = state._tr_env_close_analogical_switch(isCaching);
            if _trid_37 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.env_close_analogical_switch();
                match guard_dependency.get("env_close_analogical_switch") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("env_close_analogical_switch").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("env_close_analogical_switch").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_38 = state._tr_env_open_analogical_switch(isCaching);
            if _trid_38 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.env_open_analogical_switch();
                match guard_dependency.get("env_open_analogical_switch") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("env_open_analogical_switch").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("env_open_analogical_switch").unwrap().clone());
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
            if state._tr_begin_flying(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.begin_flying();
                match guard_dependency.get("begin_flying") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_land_plane(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.land_plane();
                match guard_dependency.get("land_plane") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_open_valve_door_open(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.open_valve_door_open();
                match guard_dependency.get("open_valve_door_open") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_close_valve_door_open(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.close_valve_door_open();
                match guard_dependency.get("close_valve_door_open") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_open_valve_door_close(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.open_valve_door_close();
                match guard_dependency.get("open_valve_door_close") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_close_valve_door_close(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.close_valve_door_close();
                match guard_dependency.get("close_valve_door_close") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_open_valve_retract_gear(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.open_valve_retract_gear();
                match guard_dependency.get("open_valve_retract_gear") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_close_valve_retract_gear(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.close_valve_retract_gear();
                match guard_dependency.get("close_valve_retract_gear") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_open_valve_extend_gear(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.open_valve_extend_gear();
                match guard_dependency.get("open_valve_extend_gear") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_close_valve_extend_gear(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.close_valve_extend_gear();
                match guard_dependency.get("close_valve_extend_gear") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_con_stimulate_open_door_valve(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.con_stimulate_open_door_valve();
                match guard_dependency.get("con_stimulate_open_door_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_con_stop_stimulate_open_door_valve(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.con_stop_stimulate_open_door_valve();
                match guard_dependency.get("con_stop_stimulate_open_door_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_con_stimulate_close_door_valve(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.con_stimulate_close_door_valve();
                match guard_dependency.get("con_stimulate_close_door_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_con_stop_stimulate_close_door_valve(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.con_stop_stimulate_close_door_valve();
                match guard_dependency.get("con_stop_stimulate_close_door_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_con_stimulate_retract_gear_valve(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.con_stimulate_retract_gear_valve();
                match guard_dependency.get("con_stimulate_retract_gear_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_con_stop_stimulate_retract_gear_valve(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.con_stop_stimulate_retract_gear_valve();
                match guard_dependency.get("con_stop_stimulate_retract_gear_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_con_stimulate_extend_gear_valve(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.con_stimulate_extend_gear_valve();
                match guard_dependency.get("con_stimulate_extend_gear_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_con_stop_stimulate_extend_gear_valve(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.con_stop_stimulate_extend_gear_valve();
                match guard_dependency.get("con_stop_stimulate_extend_gear_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_19 = state._tr_env_start_retracting_first(isCaching);
            for param in _trid_19.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_start_retracting_first(_tmp_1);
                match guard_dependency.get("env_start_retracting_first") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_20 = state._tr_env_retract_gear_skip(isCaching);
            for param in _trid_20.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_retract_gear_skip(_tmp_1);
                match guard_dependency.get("env_retract_gear_skip") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_21 = state._tr_env_retract_gear_last(isCaching);
            for param in _trid_21.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_retract_gear_last(_tmp_1);
                match guard_dependency.get("env_retract_gear_last") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_22 = state._tr_env_start_extending(isCaching);
            for param in _trid_22.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_start_extending(_tmp_1);
                match guard_dependency.get("env_start_extending") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_23 = state._tr_env_extend_gear_last(isCaching);
            for param in _trid_23.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_extend_gear_last(_tmp_1);
                match guard_dependency.get("env_extend_gear_last") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_24 = state._tr_env_extend_gear_skip(isCaching);
            for param in _trid_24.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_extend_gear_skip(_tmp_1);
                match guard_dependency.get("env_extend_gear_skip") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_25 = state._tr_env_start_open_door(isCaching);
            for param in _trid_25.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_start_open_door(_tmp_1);
                match guard_dependency.get("env_start_open_door") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_26 = state._tr_env_open_door_last(isCaching);
            for param in _trid_26.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_open_door_last(_tmp_1);
                match guard_dependency.get("env_open_door_last") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_27 = state._tr_env_open_door_skip(isCaching);
            for param in _trid_27.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_open_door_skip(_tmp_1);
                match guard_dependency.get("env_open_door_skip") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_28 = state._tr_env_start_close_door(isCaching);
            for param in _trid_28.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_start_close_door(_tmp_1);
                match guard_dependency.get("env_start_close_door") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_29 = state._tr_env_close_door(isCaching);
            for param in _trid_29.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_close_door(_tmp_1);
                match guard_dependency.get("env_close_door") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_30 = state._tr_env_close_door_skip(isCaching);
            for param in _trid_30.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.env_close_door_skip(_tmp_1);
                match guard_dependency.get("env_close_door_skip") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_toggle_handle_up(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.toggle_handle_up();
                match guard_dependency.get("toggle_handle_up") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_toggle_handle_down(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.toggle_handle_down();
                match guard_dependency.get("toggle_handle_down") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_con_stimulate_general_valve(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.con_stimulate_general_valve();
                match guard_dependency.get("con_stimulate_general_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_con_stop_stimulate_general_valve(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.con_stop_stimulate_general_valve();
                match guard_dependency.get("con_stop_stimulate_general_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_evn_open_general_valve(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.evn_open_general_valve();
                match guard_dependency.get("evn_open_general_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_evn_close_general_valve(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.evn_close_general_valve();
                match guard_dependency.get("evn_close_general_valve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_env_close_analogical_switch(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.env_close_analogical_switch();
                match guard_dependency.get("env_close_analogical_switch") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_env_open_analogical_switch(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.env_open_analogical_switch();
                match guard_dependency.get("env_open_analogical_switch") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }

        }
        return result;
    }

    //model_check_evaluate_state

    //model_check_invariants
    pub fn checkInvariants(state: &LandingGear_R6,
                           isCaching: bool,
                           dependent_invariant_m: Arc<Mutex<HashMap<LandingGear_R6, HashSet<&str>>>> ) -> bool {
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
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_21") {
                if !state._check_inv_21() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_22") {
                if !state._check_inv_22() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_23") {
                if !state._check_inv_23() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_24") {
                if !state._check_inv_24() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_25") {
                if !state._check_inv_25() {
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6() || !state._check_inv_7() || !state._check_inv_8() || !state._check_inv_9() || !state._check_inv_10() || !state._check_inv_11() || !state._check_inv_12() || !state._check_inv_13() || !state._check_inv_14() || !state._check_inv_15() || !state._check_inv_16() || !state._check_inv_17() || !state._check_inv_18() || !state._check_inv_19() || !state._check_inv_20() || !state._check_inv_21() || !state._check_inv_22() || !state._check_inv_23() || !state._check_inv_24() || !state._check_inv_25());
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
    fn next(collection_m: Arc<Mutex<LinkedList<LandingGear_R6>>>, mc_type: MC_TYPE) -> LandingGear_R6 {
        let mut collection = collection_m.lock().unwrap();
        return match mc_type {
            MC_TYPE::BFS   => collection.pop_front().unwrap(),
            MC_TYPE::DFS   => collection.pop_back().unwrap(),
            MC_TYPE::MIXED => if collection.len() % 2 == 0 { collection.pop_front().unwrap() } else { collection.pop_back().unwrap() }
        };
    }

    fn model_check_single_threaded(mc_type: MC_TYPE, is_caching: bool) {
        let mut machine = LandingGear_R6::new();

        let invariant_violated = AtomicBool::new(false);
        let deadlock_detected = AtomicBool::new(false);
        let stop_threads = AtomicBool::new(false);

        if !machine._check_inv_1() || !machine._check_inv_2() || !machine._check_inv_3() || !machine._check_inv_4() || !machine._check_inv_5() || !machine._check_inv_6() || !machine._check_inv_7() || !machine._check_inv_8() || !machine._check_inv_9() || !machine._check_inv_10() || !machine._check_inv_11() || !machine._check_inv_12() || !machine._check_inv_13() || !machine._check_inv_14() || !machine._check_inv_15() || !machine._check_inv_16() || !machine._check_inv_17() || !machine._check_inv_18() || !machine._check_inv_19() || !machine._check_inv_20() || !machine._check_inv_21() || !machine._check_inv_22() || !machine._check_inv_23() || !machine._check_inv_24() || !machine._check_inv_25() {
            invariant_violated.store(true, Ordering::Release);
        }

        let mut states = HashSet::<LandingGear_R6>::new();
        states.insert(machine.clone());
        let number_states = AtomicI64::new(1);

        let collection_m = Arc::new(Mutex::new(LinkedList::<LandingGear_R6>::new()));
        collection_m.lock().unwrap().push_back(machine.clone());

        let mut invariantDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut guardDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut dependent_invariant_m = Arc::new(Mutex::new(HashMap::<LandingGear_R6, HashSet<&str>>::new()));
        let mut dependent_guard_m = Arc::new(Mutex::new(HashMap::<LandingGear_R6, HashSet<&str>>::new()));
        let mut guard_cache = Arc::new(Mutex::new(HashMap::<LandingGear_R6, PersistentHashMap<&'static str, bool>>::new()));
        let mut parents_m = Arc::new(Mutex::new(HashMap::<LandingGear_R6, LandingGear_R6>::new()));

        if is_caching {
            //model_check_init_static
            invariantDependency.insert("close_valve_door_close", HashSet::from(["_check_inv_10"]));
            //model_check_init_static
            invariantDependency.insert("close_valve_retract_gear", HashSet::from(["_check_inv_13"]));
            //model_check_init_static
            invariantDependency.insert("con_stimulate_open_door_valve", HashSet::from(["_check_inv_18", "_check_inv_17", "_check_inv_7"]));
            //model_check_init_static
            invariantDependency.insert("env_close_door", HashSet::from(["_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22"]));
            //model_check_init_static
            invariantDependency.insert("env_start_close_door", HashSet::from(["_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22"]));
            //model_check_init_static
            invariantDependency.insert("toggle_handle_up", HashSet::from(["_check_inv_4", "_check_inv_14"]));
            //model_check_init_static
            invariantDependency.insert("toggle_handle_down", HashSet::from(["_check_inv_4", "_check_inv_14"]));
            //model_check_init_static
            invariantDependency.insert("open_valve_door_open", HashSet::from(["_check_inv_12"]));
            //model_check_init_static
            invariantDependency.insert("env_retract_gear_last", HashSet::from(["_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23"]));
            //model_check_init_static
            invariantDependency.insert("env_open_door_last", HashSet::from(["_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22"]));
            //model_check_init_static
            invariantDependency.insert("con_stop_stimulate_retract_gear_valve", HashSet::from(["_check_inv_17", "_check_inv_8"]));
            //model_check_init_static
            invariantDependency.insert("env_close_door_skip", HashSet::from(["_check_inv_21", "_check_inv_20", "_check_inv_22"]));
            //model_check_init_static
            invariantDependency.insert("con_stop_stimulate_close_door_valve", HashSet::from(["_check_inv_18", "_check_inv_17", "_check_inv_5"]));
            //model_check_init_static
            invariantDependency.insert("env_open_analogical_switch", HashSet::from(["_check_inv_1"]));
            //model_check_init_static
            invariantDependency.insert("con_stop_stimulate_general_valve", HashSet::from(["_check_inv_17", "_check_inv_2", "_check_inv_4"]));
            //model_check_init_static
            invariantDependency.insert("env_extend_gear_last", HashSet::from(["_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23"]));
            //model_check_init_static
            invariantDependency.insert("evn_open_general_valve", HashSet::from(["_check_inv_3"]));
            //model_check_init_static
            invariantDependency.insert("land_plane", HashSet::from(["_check_inv_9"]));
            //model_check_init_static
            invariantDependency.insert("con_stimulate_retract_gear_valve", HashSet::from(["_check_inv_17", "_check_inv_8"]));
            //model_check_init_static
            invariantDependency.insert("con_stimulate_general_valve", HashSet::from(["_check_inv_17", "_check_inv_2"]));
            //model_check_init_static
            invariantDependency.insert("env_start_retracting_first", HashSet::from(["_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23"]));
            //model_check_init_static
            invariantDependency.insert("env_retract_gear_skip", HashSet::from(["_check_inv_19", "_check_inv_24", "_check_inv_23"]));
            //model_check_init_static
            invariantDependency.insert("open_valve_extend_gear", HashSet::from(["_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("begin_flying", HashSet::from(["_check_inv_9"]));
            //model_check_init_static
            invariantDependency.insert("open_valve_retract_gear", HashSet::from(["_check_inv_13"]));
            //model_check_init_static
            invariantDependency.insert("env_close_analogical_switch", HashSet::from(["_check_inv_1"]));
            //model_check_init_static
            invariantDependency.insert("env_start_extending", HashSet::from(["_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23"]));
            //model_check_init_static
            invariantDependency.insert("open_valve_door_close", HashSet::from(["_check_inv_10"]));
            //model_check_init_static
            invariantDependency.insert("con_stop_stimulate_open_door_valve", HashSet::from(["_check_inv_18", "_check_inv_17", "_check_inv_7"]));
            //model_check_init_static
            invariantDependency.insert("con_stop_stimulate_extend_gear_valve", HashSet::from(["_check_inv_17", "_check_inv_6"]));
            //model_check_init_static
            invariantDependency.insert("evn_close_general_valve", HashSet::from(["_check_inv_3"]));
            //model_check_init_static
            invariantDependency.insert("close_valve_extend_gear", HashSet::from(["_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("con_stimulate_extend_gear_valve", HashSet::from(["_check_inv_17", "_check_inv_6"]));
            //model_check_init_static
            invariantDependency.insert("close_valve_door_open", HashSet::from(["_check_inv_12"]));
            //model_check_init_static
            invariantDependency.insert("con_stimulate_close_door_valve", HashSet::from(["_check_inv_18", "_check_inv_17", "_check_inv_5"]));
            //model_check_init_static
            invariantDependency.insert("env_extend_gear_skip", HashSet::from(["_check_inv_19", "_check_inv_24", "_check_inv_23"]));
            //model_check_init_static
            invariantDependency.insert("env_open_door_skip", HashSet::from(["_check_inv_21", "_check_inv_20", "_check_inv_22"]));
            //model_check_init_static
            invariantDependency.insert("env_start_open_door", HashSet::from(["_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22"]));
            //model_check_init_static
            guardDependency.insert("close_valve_door_close", HashSet::from(["_tr_open_valve_door_close", "_tr_env_close_door_skip", "_tr_env_start_close_door", "_tr_env_close_door", "_tr_close_valve_door_close"]));
            //model_check_init_static
            guardDependency.insert("close_valve_retract_gear", HashSet::from(["_tr_close_valve_retract_gear", "_tr_open_valve_retract_gear", "_tr_env_start_retracting_first"]));
            //model_check_init_static
            guardDependency.insert("con_stimulate_open_door_valve", HashSet::from(["_tr_open_valve_door_open", "_tr_con_stimulate_extend_gear_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_open"]));
            //model_check_init_static
            guardDependency.insert("env_close_door", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("env_start_close_door", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("toggle_handle_up", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_close_analogical_switch", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip", "_tr_con_stimulate_general_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_toggle_handle_down", "_tr_env_open_door_last", "_tr_toggle_handle_up", "_tr_env_start_close_door", "_tr_con_stop_stimulate_close_door_valve"]));
            //model_check_init_static
            guardDependency.insert("toggle_handle_down", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_close_analogical_switch", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip", "_tr_con_stimulate_general_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_toggle_handle_down", "_tr_env_open_door_last", "_tr_toggle_handle_up", "_tr_env_start_close_door", "_tr_con_stop_stimulate_close_door_valve"]));
            //model_check_init_static
            guardDependency.insert("open_valve_door_open", HashSet::from(["_tr_open_valve_door_open", "_tr_env_open_door_last", "_tr_env_start_open_door", "_tr_env_open_door_skip", "_tr_close_valve_door_open"]));
            //model_check_init_static
            guardDependency.insert("env_retract_gear_last", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("env_open_door_last", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("con_stop_stimulate_retract_gear_valve", HashSet::from(["_tr_close_valve_retract_gear", "_tr_con_stimulate_extend_gear_valve", "_tr_open_valve_retract_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_retract_gear_valve"]));
            //model_check_init_static
            guardDependency.insert("env_close_door_skip", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("con_stop_stimulate_close_door_valve", HashSet::from(["_tr_open_valve_door_close", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_close"]));
            //model_check_init_static
            guardDependency.insert("env_open_analogical_switch", HashSet::from(["_tr_env_open_analogical_switch", "_tr_evn_open_general_valve", "_tr_env_close_analogical_switch", "_tr_evn_close_general_valve"]));
            //model_check_init_static
            guardDependency.insert("con_stop_stimulate_general_valve", HashSet::from(["_tr_con_stimulate_extend_gear_valve", "_tr_con_stimulate_general_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_evn_open_general_valve", "_tr_env_close_analogical_switch", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_evn_close_general_valve", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve"]));
            //model_check_init_static
            guardDependency.insert("env_extend_gear_last", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("evn_open_general_valve", HashSet::from(["_tr_env_retract_gear_last", "_tr_env_close_door_skip", "_tr_evn_open_general_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_evn_close_general_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("land_plane", HashSet::from(["_tr_land_plane", "_tr_begin_flying", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_close_door"]));
            //model_check_init_static
            guardDependency.insert("con_stimulate_retract_gear_valve", HashSet::from(["_tr_close_valve_retract_gear", "_tr_con_stimulate_extend_gear_valve", "_tr_open_valve_retract_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_retract_gear_valve"]));
            //model_check_init_static
            guardDependency.insert("con_stimulate_general_valve", HashSet::from(["_tr_con_stimulate_extend_gear_valve", "_tr_con_stimulate_general_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_evn_open_general_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_evn_close_general_valve", "_tr_con_stop_stimulate_retract_gear_valve"]));
            //model_check_init_static
            guardDependency.insert("env_start_retracting_first", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("env_retract_gear_skip", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("open_valve_extend_gear", HashSet::from(["_tr_close_valve_extend_gear", "_tr_open_valve_extend_gear", "_tr_env_start_extending"]));
            //model_check_init_static
            guardDependency.insert("begin_flying", HashSet::from(["_tr_land_plane", "_tr_begin_flying", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_close_door"]));
            //model_check_init_static
            guardDependency.insert("open_valve_retract_gear", HashSet::from(["_tr_close_valve_retract_gear", "_tr_open_valve_retract_gear", "_tr_env_start_retracting_first"]));
            //model_check_init_static
            guardDependency.insert("env_close_analogical_switch", HashSet::from(["_tr_env_open_analogical_switch", "_tr_evn_open_general_valve", "_tr_env_close_analogical_switch", "_tr_evn_close_general_valve"]));
            //model_check_init_static
            guardDependency.insert("env_start_extending", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("open_valve_door_close", HashSet::from(["_tr_open_valve_door_close", "_tr_env_close_door_skip", "_tr_env_start_close_door", "_tr_env_close_door", "_tr_close_valve_door_close"]));
            //model_check_init_static
            guardDependency.insert("con_stop_stimulate_open_door_valve", HashSet::from(["_tr_open_valve_door_open", "_tr_con_stimulate_extend_gear_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_open"]));
            //model_check_init_static
            guardDependency.insert("con_stop_stimulate_extend_gear_valve", HashSet::from(["_tr_con_stimulate_extend_gear_valve", "_tr_close_valve_extend_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_open_valve_extend_gear", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_extend_gear_valve"]));
            //model_check_init_static
            guardDependency.insert("evn_close_general_valve", HashSet::from(["_tr_env_retract_gear_last", "_tr_env_close_door_skip", "_tr_evn_open_general_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_evn_close_general_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("close_valve_extend_gear", HashSet::from(["_tr_close_valve_extend_gear", "_tr_open_valve_extend_gear", "_tr_env_start_extending"]));
            //model_check_init_static
            guardDependency.insert("con_stimulate_extend_gear_valve", HashSet::from(["_tr_con_stimulate_extend_gear_valve", "_tr_close_valve_extend_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_open_valve_extend_gear", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_extend_gear_valve"]));
            //model_check_init_static
            guardDependency.insert("close_valve_door_open", HashSet::from(["_tr_open_valve_door_open", "_tr_env_open_door_last", "_tr_env_start_open_door", "_tr_env_open_door_skip", "_tr_close_valve_door_open"]));
            //model_check_init_static
            guardDependency.insert("con_stimulate_close_door_valve", HashSet::from(["_tr_open_valve_door_close", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_close"]));
            //model_check_init_static
            guardDependency.insert("env_extend_gear_skip", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("env_open_door_skip", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("env_start_open_door", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            dependent_invariant_m.lock().unwrap().insert(machine.clone(), HashSet::new());
            parents_m.lock().unwrap().remove(&machine);
        }

        let transitions = Arc::new(AtomicI64::new(0));

        while !stop_threads.load(Ordering::Acquire) && !collection_m.lock().unwrap().is_empty() {
            let mut state = Self::next(Arc::clone(&collection_m), mc_type);

            let next_states = Self::generateNextStates(&mut state, is_caching, &mut invariantDependency, Arc::clone(&dependent_invariant_m), &mut guardDependency, Arc::clone(&dependent_guard_m), Arc::clone(&guard_cache), Arc::clone(&parents_m), Arc::clone(&transitions));

            next_states.iter().cloned().for_each(|next_state| {
                if !states.contains(&next_state) {
                    let cnum_states = number_states.fetch_add(1, Ordering::AcqRel) + 1;
                    states.insert(next_state.clone());
                    collection_m.lock().unwrap().push_back(next_state);
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

        let machine = LandingGear_R6::new();


        let invariant_violated_b = Arc::new(AtomicBool::new(false));
        let deadlock_detected_b = Arc::new(AtomicBool::new(false));
        let stop_threads_b = Arc::new(AtomicBool::new(false));
        let possible_queue_changes_b = Arc::new(AtomicI32::new(0));

        if !machine._check_inv_1() || !machine._check_inv_2() || !machine._check_inv_3() || !machine._check_inv_4() || !machine._check_inv_5() || !machine._check_inv_6() || !machine._check_inv_7() || !machine._check_inv_8() || !machine._check_inv_9() || !machine._check_inv_10() || !machine._check_inv_11() || !machine._check_inv_12() || !machine._check_inv_13() || !machine._check_inv_14() || !machine._check_inv_15() || !machine._check_inv_16() || !machine._check_inv_17() || !machine._check_inv_18() || !machine._check_inv_19() || !machine._check_inv_20() || !machine._check_inv_21() || !machine._check_inv_22() || !machine._check_inv_23() || !machine._check_inv_24() || !machine._check_inv_25() {
            invariant_violated_b.store(true, Ordering::Release);
        }

        let states_m = Arc::new(Mutex::new(HashSet::<LandingGear_R6>::new()));
        states_m.lock().unwrap().insert(machine.clone());
        let number_states_arc = Arc::new(AtomicI64::new(1));

        let collection_m = Arc::new(Mutex::new(LinkedList::<LandingGear_R6>::new()));
        collection_m.lock().unwrap().push_back(machine.clone());

        let mut invariantDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut guardDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut dependent_invariant_m = Arc::new(Mutex::new(HashMap::<LandingGear_R6, HashSet<&str>>::new()));
        let mut dependent_guard_m = Arc::new(Mutex::new(HashMap::<LandingGear_R6, HashSet<&str>>::new()));
        let mut guard_cache_b = Arc::new(Mutex::new(HashMap::<LandingGear_R6, PersistentHashMap<&'static str, bool>>::new()));
        let mut parents_m = Arc::new(Mutex::new(HashMap::<LandingGear_R6, LandingGear_R6>::new()));

        if is_caching {
            //model_check_init_static
            invariantDependency.insert("close_valve_door_close", HashSet::from(["_check_inv_10"]));
            //model_check_init_static
            invariantDependency.insert("close_valve_retract_gear", HashSet::from(["_check_inv_13"]));
            //model_check_init_static
            invariantDependency.insert("con_stimulate_open_door_valve", HashSet::from(["_check_inv_18", "_check_inv_17", "_check_inv_7"]));
            //model_check_init_static
            invariantDependency.insert("env_close_door", HashSet::from(["_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22"]));
            //model_check_init_static
            invariantDependency.insert("env_start_close_door", HashSet::from(["_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22"]));
            //model_check_init_static
            invariantDependency.insert("toggle_handle_up", HashSet::from(["_check_inv_4", "_check_inv_14"]));
            //model_check_init_static
            invariantDependency.insert("toggle_handle_down", HashSet::from(["_check_inv_4", "_check_inv_14"]));
            //model_check_init_static
            invariantDependency.insert("open_valve_door_open", HashSet::from(["_check_inv_12"]));
            //model_check_init_static
            invariantDependency.insert("env_retract_gear_last", HashSet::from(["_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23"]));
            //model_check_init_static
            invariantDependency.insert("env_open_door_last", HashSet::from(["_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22"]));
            //model_check_init_static
            invariantDependency.insert("con_stop_stimulate_retract_gear_valve", HashSet::from(["_check_inv_17", "_check_inv_8"]));
            //model_check_init_static
            invariantDependency.insert("env_close_door_skip", HashSet::from(["_check_inv_21", "_check_inv_20", "_check_inv_22"]));
            //model_check_init_static
            invariantDependency.insert("con_stop_stimulate_close_door_valve", HashSet::from(["_check_inv_18", "_check_inv_17", "_check_inv_5"]));
            //model_check_init_static
            invariantDependency.insert("env_open_analogical_switch", HashSet::from(["_check_inv_1"]));
            //model_check_init_static
            invariantDependency.insert("con_stop_stimulate_general_valve", HashSet::from(["_check_inv_17", "_check_inv_2", "_check_inv_4"]));
            //model_check_init_static
            invariantDependency.insert("env_extend_gear_last", HashSet::from(["_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23"]));
            //model_check_init_static
            invariantDependency.insert("evn_open_general_valve", HashSet::from(["_check_inv_3"]));
            //model_check_init_static
            invariantDependency.insert("land_plane", HashSet::from(["_check_inv_9"]));
            //model_check_init_static
            invariantDependency.insert("con_stimulate_retract_gear_valve", HashSet::from(["_check_inv_17", "_check_inv_8"]));
            //model_check_init_static
            invariantDependency.insert("con_stimulate_general_valve", HashSet::from(["_check_inv_17", "_check_inv_2"]));
            //model_check_init_static
            invariantDependency.insert("env_start_retracting_first", HashSet::from(["_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23"]));
            //model_check_init_static
            invariantDependency.insert("env_retract_gear_skip", HashSet::from(["_check_inv_19", "_check_inv_24", "_check_inv_23"]));
            //model_check_init_static
            invariantDependency.insert("open_valve_extend_gear", HashSet::from(["_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("begin_flying", HashSet::from(["_check_inv_9"]));
            //model_check_init_static
            invariantDependency.insert("open_valve_retract_gear", HashSet::from(["_check_inv_13"]));
            //model_check_init_static
            invariantDependency.insert("env_close_analogical_switch", HashSet::from(["_check_inv_1"]));
            //model_check_init_static
            invariantDependency.insert("env_start_extending", HashSet::from(["_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23"]));
            //model_check_init_static
            invariantDependency.insert("open_valve_door_close", HashSet::from(["_check_inv_10"]));
            //model_check_init_static
            invariantDependency.insert("con_stop_stimulate_open_door_valve", HashSet::from(["_check_inv_18", "_check_inv_17", "_check_inv_7"]));
            //model_check_init_static
            invariantDependency.insert("con_stop_stimulate_extend_gear_valve", HashSet::from(["_check_inv_17", "_check_inv_6"]));
            //model_check_init_static
            invariantDependency.insert("evn_close_general_valve", HashSet::from(["_check_inv_3"]));
            //model_check_init_static
            invariantDependency.insert("close_valve_extend_gear", HashSet::from(["_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("con_stimulate_extend_gear_valve", HashSet::from(["_check_inv_17", "_check_inv_6"]));
            //model_check_init_static
            invariantDependency.insert("close_valve_door_open", HashSet::from(["_check_inv_12"]));
            //model_check_init_static
            invariantDependency.insert("con_stimulate_close_door_valve", HashSet::from(["_check_inv_18", "_check_inv_17", "_check_inv_5"]));
            //model_check_init_static
            invariantDependency.insert("env_extend_gear_skip", HashSet::from(["_check_inv_19", "_check_inv_24", "_check_inv_23"]));
            //model_check_init_static
            invariantDependency.insert("env_open_door_skip", HashSet::from(["_check_inv_21", "_check_inv_20", "_check_inv_22"]));
            //model_check_init_static
            invariantDependency.insert("env_start_open_door", HashSet::from(["_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22"]));
            //model_check_init_static
            guardDependency.insert("close_valve_door_close", HashSet::from(["_tr_open_valve_door_close", "_tr_env_close_door_skip", "_tr_env_start_close_door", "_tr_env_close_door", "_tr_close_valve_door_close"]));
            //model_check_init_static
            guardDependency.insert("close_valve_retract_gear", HashSet::from(["_tr_close_valve_retract_gear", "_tr_open_valve_retract_gear", "_tr_env_start_retracting_first"]));
            //model_check_init_static
            guardDependency.insert("con_stimulate_open_door_valve", HashSet::from(["_tr_open_valve_door_open", "_tr_con_stimulate_extend_gear_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_open"]));
            //model_check_init_static
            guardDependency.insert("env_close_door", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("env_start_close_door", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("toggle_handle_up", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_close_analogical_switch", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip", "_tr_con_stimulate_general_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_toggle_handle_down", "_tr_env_open_door_last", "_tr_toggle_handle_up", "_tr_env_start_close_door", "_tr_con_stop_stimulate_close_door_valve"]));
            //model_check_init_static
            guardDependency.insert("toggle_handle_down", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_close_analogical_switch", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip", "_tr_con_stimulate_general_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_toggle_handle_down", "_tr_env_open_door_last", "_tr_toggle_handle_up", "_tr_env_start_close_door", "_tr_con_stop_stimulate_close_door_valve"]));
            //model_check_init_static
            guardDependency.insert("open_valve_door_open", HashSet::from(["_tr_open_valve_door_open", "_tr_env_open_door_last", "_tr_env_start_open_door", "_tr_env_open_door_skip", "_tr_close_valve_door_open"]));
            //model_check_init_static
            guardDependency.insert("env_retract_gear_last", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("env_open_door_last", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("con_stop_stimulate_retract_gear_valve", HashSet::from(["_tr_close_valve_retract_gear", "_tr_con_stimulate_extend_gear_valve", "_tr_open_valve_retract_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_retract_gear_valve"]));
            //model_check_init_static
            guardDependency.insert("env_close_door_skip", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("con_stop_stimulate_close_door_valve", HashSet::from(["_tr_open_valve_door_close", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_close"]));
            //model_check_init_static
            guardDependency.insert("env_open_analogical_switch", HashSet::from(["_tr_env_open_analogical_switch", "_tr_evn_open_general_valve", "_tr_env_close_analogical_switch", "_tr_evn_close_general_valve"]));
            //model_check_init_static
            guardDependency.insert("con_stop_stimulate_general_valve", HashSet::from(["_tr_con_stimulate_extend_gear_valve", "_tr_con_stimulate_general_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_evn_open_general_valve", "_tr_env_close_analogical_switch", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_evn_close_general_valve", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve"]));
            //model_check_init_static
            guardDependency.insert("env_extend_gear_last", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("evn_open_general_valve", HashSet::from(["_tr_env_retract_gear_last", "_tr_env_close_door_skip", "_tr_evn_open_general_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_evn_close_general_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("land_plane", HashSet::from(["_tr_land_plane", "_tr_begin_flying", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_close_door"]));
            //model_check_init_static
            guardDependency.insert("con_stimulate_retract_gear_valve", HashSet::from(["_tr_close_valve_retract_gear", "_tr_con_stimulate_extend_gear_valve", "_tr_open_valve_retract_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_retract_gear_valve"]));
            //model_check_init_static
            guardDependency.insert("con_stimulate_general_valve", HashSet::from(["_tr_con_stimulate_extend_gear_valve", "_tr_con_stimulate_general_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_evn_open_general_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_evn_close_general_valve", "_tr_con_stop_stimulate_retract_gear_valve"]));
            //model_check_init_static
            guardDependency.insert("env_start_retracting_first", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("env_retract_gear_skip", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("open_valve_extend_gear", HashSet::from(["_tr_close_valve_extend_gear", "_tr_open_valve_extend_gear", "_tr_env_start_extending"]));
            //model_check_init_static
            guardDependency.insert("begin_flying", HashSet::from(["_tr_land_plane", "_tr_begin_flying", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_close_door"]));
            //model_check_init_static
            guardDependency.insert("open_valve_retract_gear", HashSet::from(["_tr_close_valve_retract_gear", "_tr_open_valve_retract_gear", "_tr_env_start_retracting_first"]));
            //model_check_init_static
            guardDependency.insert("env_close_analogical_switch", HashSet::from(["_tr_env_open_analogical_switch", "_tr_evn_open_general_valve", "_tr_env_close_analogical_switch", "_tr_evn_close_general_valve"]));
            //model_check_init_static
            guardDependency.insert("env_start_extending", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("open_valve_door_close", HashSet::from(["_tr_open_valve_door_close", "_tr_env_close_door_skip", "_tr_env_start_close_door", "_tr_env_close_door", "_tr_close_valve_door_close"]));
            //model_check_init_static
            guardDependency.insert("con_stop_stimulate_open_door_valve", HashSet::from(["_tr_open_valve_door_open", "_tr_con_stimulate_extend_gear_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_open"]));
            //model_check_init_static
            guardDependency.insert("con_stop_stimulate_extend_gear_valve", HashSet::from(["_tr_con_stimulate_extend_gear_valve", "_tr_close_valve_extend_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_open_valve_extend_gear", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_extend_gear_valve"]));
            //model_check_init_static
            guardDependency.insert("evn_close_general_valve", HashSet::from(["_tr_env_retract_gear_last", "_tr_env_close_door_skip", "_tr_evn_open_general_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_evn_close_general_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("close_valve_extend_gear", HashSet::from(["_tr_close_valve_extend_gear", "_tr_open_valve_extend_gear", "_tr_env_start_extending"]));
            //model_check_init_static
            guardDependency.insert("con_stimulate_extend_gear_valve", HashSet::from(["_tr_con_stimulate_extend_gear_valve", "_tr_close_valve_extend_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_open_valve_extend_gear", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_extend_gear_valve"]));
            //model_check_init_static
            guardDependency.insert("close_valve_door_open", HashSet::from(["_tr_open_valve_door_open", "_tr_env_open_door_last", "_tr_env_start_open_door", "_tr_env_open_door_skip", "_tr_close_valve_door_open"]));
            //model_check_init_static
            guardDependency.insert("con_stimulate_close_door_valve", HashSet::from(["_tr_open_valve_door_close", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_close"]));
            //model_check_init_static
            guardDependency.insert("env_extend_gear_skip", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("env_open_door_skip", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
            //model_check_init_static
            guardDependency.insert("env_start_open_door", HashSet::from(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
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
                next_states.iter().cloned().for_each(|next_state| {
                    {
                        let mut states = states_m2.lock().unwrap();
                        let mut collection = collection_m2.lock().unwrap();
                        if !states.contains(&next_state) {
                            let cnum_states = number_states.fetch_add(1, Ordering::AcqRel) + 1;
                            states.insert(next_state.clone());
                            collection.push_back(next_state);
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
        LandingGear_R6::model_check_single_threaded(mc_type, is_caching);
    } else {
        LandingGear_R6::modelCheckMultiThreaded(mc_type, threads, is_caching);
    }
}
