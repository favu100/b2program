#![ allow( dead_code, unused_imports, unused_mut, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::binteger::BInteger;
use btypes::bboolean::BBoolean;



#[derive(Default, Debug)]
pub struct Counter10000 {
    counter: BInteger,
}

impl Counter10000 {

    pub fn new() -> Counter10000 {
        //values: ''
        let mut m: Counter10000 = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.counter = BInteger::new(0);
    }

    pub fn get_counter(&self) -> BInteger {
        return self.counter.clone();
    }

    pub fn simulate(&mut self) -> () {
        while (self.counter.less(&BInteger::new(100000))).booleanValue() {
            self.counter = self.counter.plus(&BInteger::new(1));
        }
    }
}

fn main() {
    let mut counter = Counter10000::new();
    counter.simulate();
}

