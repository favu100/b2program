#![ allow( dead_code, unused_imports, unused_mut, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::binteger::BInteger;
use btypes::bboolean::BBoolean;
mod sort_m2_data1000;



#[derive(Default, Debug)]
pub struct sort_m2_data1000_exec {
    counter: BInteger,
    sorted: BInteger,
    _sort_m2_data1000: sort_m2_data1000::sort_m2_data1000,
}

impl sort_m2_data1000_exec {

    pub fn new() -> sort_m2_data1000_exec {
        //values: ''
        let mut m: sort_m2_data1000_exec = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.counter = BInteger::new(b"0");
        self.sorted = BInteger::new(b"0");
        self._sort_m2_data1000 = sort_m2_data1000::sort_m2_data1000::new();
    }

    pub fn get_counter(&self) -> BInteger {
        return self.counter.clone();
    }

    pub fn get_sorted(&self) -> BInteger {
        return self.sorted.clone();
    }

    pub fn simulate(&mut self) -> () {
        while (self.sorted.less(&BInteger::new(b"500"))).booleanValue() {
            self.counter = BInteger::new(b"0");
            while (self.counter.less(&BInteger::new(b"999").minus(&BInteger::new(b"2").multiply(&self.sorted)))).booleanValue() {
                self._sort_m2_data1000.prog2();
                self.counter = self.counter.plus(&BInteger::new(b"1"));
            }
            self.counter = BInteger::new(b"0");
            while (self.counter.less(&self.sorted)).booleanValue() {
                self._sort_m2_data1000.prog1();
                self.counter = self.counter.plus(&BInteger::new(b"1"));
            }
            self._sort_m2_data1000.progress();
            self.sorted = self.sorted.plus(&BInteger::new(b"1"));
        }
        while (self.sorted.less(&BInteger::new(b"999"))).booleanValue() {
            self.counter = BInteger::new(b"0");
            while (self.counter.less(&BInteger::new(b"999").minus(&self.sorted))).booleanValue() {
                self._sort_m2_data1000.prog1();
                self.counter = self.counter.plus(&BInteger::new(b"1"));
            }
            self._sort_m2_data1000.progress();
            self.sorted = self.sorted.plus(&BInteger::new(b"1"));
        }
        self._sort_m2_data1000.final_evt();
    }
}

fn main() {
    let mut exec = sort_m2_data1000_exec::new();
    exec.simulate();
}
