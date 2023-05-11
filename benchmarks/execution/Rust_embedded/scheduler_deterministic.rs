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
pub enum PID {
    #[default]
    process1 = 0, 
    process2 = 1, 
    process3 = 2
}

impl PID {
    pub fn equal(&self, other: &PID) -> bool { *self == *other }
    pub fn unequal(&self, other: &PID) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::process1, 
            1 => Self::process2, 
            2 => Self::process3, 
            _ => panic!("PID index out of range! {:?}", idx)
        }
    }
}

impl SetItem<3> for PID {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_PID = BSet<PID, 3>;
//set_enum_declaration done


#[derive(Default, Debug)]pub struct scheduler_deterministic {
    /*declarations*/active: set_PID,
    _ready: set_PID,
    waiting: set_PID,
    /*sets*//*set_declaration*/_PID: set_PID,
}


impl scheduler_deterministic {

    pub fn new() -> scheduler_deterministic {
        //values: ''
        let mut m: scheduler_deterministic = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        /*set_initializations*///set_initialization
    self._PID = bset![PID, /*enum_call*/PID::process1, /*enum_call*/PID::process2, /*enum_call*/PID::process3];
        /*properties*/
        /*body*/self.active = bset![PID].clone().clone();
    self._ready = bset![PID].clone().clone();
    self.waiting = bset![PID].clone().clone();
        /*includesInitialization*/
    }

    pub fn get_active(&self) -> set_PID {
        return self.active.clone();
    }

    pub fn get__ready(&self) -> set_PID {
        return self._ready.clone();
    }

    pub fn get_waiting(&self) -> set_PID {
        return self.waiting.clone();
    }

    pub fn get__PID(&self) -> set_PID {
        return self._PID.clone();
    }

    pub fn _new(&mut self, mut pp: PID) -> () {
        //select
        if ((self._PID.elementOf(&pp) && self.active.notElementOf(&pp)) && self._ready.union(&self.waiting).notElementOf(&pp)) {
            self.waiting = self.waiting.union(&bset![PID, pp]).clone().clone();
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn del(&mut self, mut pp: PID) -> () {
        //select
        if self.waiting.elementOf(&pp) {
            self.waiting = self.waiting.difference(&bset![PID, pp]).clone().clone();
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ready(&mut self, mut rr: PID) -> () {
        //select
        if self.waiting.elementOf(&rr) {
            self.waiting = self.waiting.difference(&bset![PID, rr]).clone().clone();
            //if
            if self.active.equal(&bset![PID]) {
                self.active = bset![PID, rr].clone().clone();
            } //else
            else {
                self._ready = self._ready.union(&bset![PID, rr]).clone().clone();
            }
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn swap(&mut self, mut pp: PID) -> () {
        //pre_assert
        //select
        if self.active.unequal(&bset![PID]) {
            self.waiting = self.waiting.union(&self.active).clone().clone();
            //if
            if self._ready.equal(&bset![PID]) {
                self.active = bset![PID].clone().clone();
            } //else
            else {
                self.active = bset![PID, pp].clone().clone();
                self._ready = self._ready.difference(&bset![PID, pp]).clone().clone();
            }
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }

    }
}


