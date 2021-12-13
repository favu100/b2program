#![ allow( dead_code, unused_imports, unused_mut, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
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

#[derive(Default, Debug)]
pub struct scheduler_deterministic {
    active: BSet<PID>,
    _ready: BSet<PID>,
    waiting: BSet<PID>,
    _PID: BSet<PID>,
}

impl scheduler_deterministic {

    pub fn new() -> scheduler_deterministic {
        //values: ''
        let mut m: scheduler_deterministic = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.active = BSet::new(vec![]).clone().clone();
        self._ready = BSet::new(vec![]).clone().clone();
        self.waiting = BSet::new(vec![]).clone().clone();
        self._PID = BSet::new(vec![PID::process1, PID::process2, PID::process3]);
    }

    pub fn get_active(&self) -> BSet<PID> {
        return self.active.clone();
    }

    pub fn get__ready(&self) -> BSet<PID> {
        return self._ready.clone();
    }

    pub fn get_waiting(&self) -> BSet<PID> {
        return self.waiting.clone();
    }

    pub fn get__PID(&self) -> BSet<PID> {
        return self._PID.clone();
    }

    pub fn _new(&mut self, mut pp: PID) -> () {
        if (self._PID.elementOf(&pp).and(&self.active.notElementOf(&pp)).and(&self._ready._union(&self.waiting).notElementOf(&pp))).booleanValue() {
            self.waiting = self.waiting._union(&BSet::new(vec![pp])).clone().clone();
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn del(&mut self, mut pp: PID) -> () {
        if (self.waiting.elementOf(&pp)).booleanValue() {
            self.waiting = self.waiting.difference(&BSet::new(vec![pp])).clone().clone();
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ready(&mut self, mut rr: PID) -> () {
        if (self.waiting.elementOf(&rr)).booleanValue() {
            self.waiting = self.waiting.difference(&BSet::new(vec![rr])).clone().clone();
            if (self.active.equal(&BSet::new(vec![]))).booleanValue() {
                self.active = BSet::new(vec![rr]).clone().clone();
            } else {
                self._ready = self._ready._union(&BSet::new(vec![rr])).clone().clone();
            }
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn swap(&mut self, mut pp: PID) -> () {
        if (self.active.unequal(&BSet::new(vec![]))).booleanValue() {
            self.waiting = self.waiting._union(&self.active).clone().clone();
            if (self._ready.equal(&BSet::new(vec![]))).booleanValue() {
                self.active = BSet::new(vec![]).clone().clone();
            } else {
                self.active = BSet::new(vec![pp]).clone().clone();
                self._ready = self._ready.difference(&BSet::new(vec![pp])).clone().clone();
            }
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }
}

