#![ allow( dead_code, unused, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::bobject;
use btypes::bboolean::{IntoBool, BBooleanT};
use btypes::bboolean::BBoolean;
use btypes::bset::BSet;
use btypes::bobject::BObject;


#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum PID {
    process1,
    process2,
    process3
}
impl PID {
    pub fn equal(&self, other: &PID) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &PID) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for PID {}
impl Default for PID {
    fn default() -> Self { PID::process1 }
}
impl fmt::Display for PID {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match *self {
            PID::process1 => write!(f, "process1"),
            PID::process2 => write!(f, "process2"),
            PID::process3 => write!(f, "process3"),
        }
    }
}

#[derive(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct scheduler_deterministic {
    active: BSet<PID>,
    _ready: BSet<PID>,
    waiting: BSet<PID>,
    _PID: BSet<PID>,
}

impl fmt::Display for scheduler_deterministic {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let mut result = "scheduler_deterministic: (".to_owned();
        result += &format!("_get_active: {}, ", self._get_active());
        result += &format!("_get__ready: {}, ", self._get__ready());
        result += &format!("_get_waiting: {}, ", self._get_waiting());
        result = result + ")";
        return write!(f, "{}", result);
    }
}

impl scheduler_deterministic {

    pub fn new() -> scheduler_deterministic {
        //values: ''
        let mut m: scheduler_deterministic = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self._PID = BSet::new(vec![PID::process1, PID::process2, PID::process3]);
        self.active = BSet::<PID>::new(vec![]).clone().clone();
        self._ready = BSet::<PID>::new(vec![]).clone().clone();
        self.waiting = BSet::<PID>::new(vec![]).clone().clone();
    }

    pub fn _get_active(&self) -> BSet<PID> {
        return self.active.clone();
    }

    pub fn _get__ready(&self) -> BSet<PID> {
        return self._ready.clone();
    }

    pub fn _get_waiting(&self) -> BSet<PID> {
        return self.waiting.clone();
    }

    pub fn _get__PID(&self) -> BSet<PID> {
        return self._PID.clone();
    }

    pub fn _new(&mut self, mut pp: PID) -> () {
        if (((self._PID.elementOf(&pp) && self.active.notElementOf(&pp)) && self._ready._union(&self.waiting).notElementOf(&pp))).booleanValue() {
            self.waiting = self.waiting._union(&BSet::new(vec![pp.clone()])).clone().clone();
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn del(&mut self, mut pp: PID) -> () {
        if (self.waiting.elementOf(&pp)).booleanValue() {
            self.waiting = self.waiting.difference(&BSet::new(vec![pp.clone()])).clone().clone();
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ready(&mut self, mut rr: PID) -> () {
        if (self.waiting.elementOf(&rr)).booleanValue() {
            self.waiting = self.waiting.difference(&BSet::new(vec![rr.clone()])).clone().clone();
            if (self.active.equal(&BSet::<PID>::new(vec![]))).booleanValue() {
                self.active = BSet::new(vec![rr.clone()]).clone().clone();
            } else {
                self._ready = self._ready._union(&BSet::new(vec![rr.clone()])).clone().clone();
            }
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn swap(&mut self, mut pp: PID) -> () {
        //pre_assert
        if (self.active.unequal(&BSet::<PID>::new(vec![]))).booleanValue() {
            self.waiting = self.waiting._union(&self.active).clone().clone();
            if (self._ready.equal(&BSet::<PID>::new(vec![]))).booleanValue() {
                self.active = BSet::<PID>::new(vec![]).clone().clone();
            } else {
                self.active = BSet::new(vec![pp.clone()]).clone().clone();
                self._ready = self._ready.difference(&BSet::new(vec![pp.clone()])).clone().clone();
            }
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }
}

