#![ allow( dead_code, unused_imports, unused_mut, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::binteger::BInteger;



#[derive(Default, Debug)]
pub struct Lift {
    floor: BInteger,
}

impl Lift {

    pub fn new() -> Lift {
        //values: ''
        let mut m: Lift = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.floor = BInteger::new(b"0");
    }

    pub fn get_floor(&self) -> BInteger {
        return self.floor.clone();
    }

    pub fn inc(&mut self) -> () {
        self.floor = self.floor.plus(&BInteger::new(b"1"));
    }

    pub fn dec(&mut self) -> () {
        self.floor = self.floor.minus(&BInteger::new(b"1"));
    }
}

