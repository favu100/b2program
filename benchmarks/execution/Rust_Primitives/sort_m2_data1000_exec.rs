#![ allow( dead_code, unused, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::bobject;
use btypes::bboolean::{IntoBool, BBooleanT};
use btypes::binteger::BInteger;
use btypes::bboolean::BBoolean;
mod sort_m2_data1000;



#[derive(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct sort_m2_data1000_exec {
    counter: BInteger,
    sorted: BInteger,
    _sort_m2_data1000: sort_m2_data1000::sort_m2_data1000,
}

impl fmt::Display for sort_m2_data1000_exec {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let mut result = "sort_m2_data1000_exec: (".to_owned();
        result += &format!("_get_counter: {}, ", self._get_counter());
        result += &format!("_get_sorted: {}, ", self._get_sorted());
        result = result + ")";
        return write!(f, "{}", result);
    }
}

impl sort_m2_data1000_exec {

    pub fn new() -> sort_m2_data1000_exec {
        //values: ''
        let mut m: sort_m2_data1000_exec = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.counter = BInteger::new(0);
        self.sorted = BInteger::new(0);
        self._sort_m2_data1000 = sort_m2_data1000::sort_m2_data1000::new();
    }

    pub fn _get_counter(&self) -> BInteger {
        return self.counter.clone();
    }

    pub fn _get_sorted(&self) -> BInteger {
        return self.sorted.clone();
    }

    pub fn simulate(&mut self) -> () {
        while (self.sorted.less(&BInteger::new(500))).booleanValue() {
            self.counter = BInteger::new(0);
            while (self.counter.less(&BInteger::new(999).minus(&BInteger::new(2).multiply(&self.sorted)))).booleanValue() {
                self._sort_m2_data1000.prog2();
                self.counter = self.counter.plus(&BInteger::new(1));
            }
            self.counter = BInteger::new(0);
            while (self.counter.less(&self.sorted)).booleanValue() {
                self._sort_m2_data1000.prog1();
                self.counter = self.counter.plus(&BInteger::new(1));
            }
            self._sort_m2_data1000.progress();
            self.sorted = self.sorted.plus(&BInteger::new(1));
        }
        while (self.sorted.less(&BInteger::new(999))).booleanValue() {
            self.counter = BInteger::new(0);
            while (self.counter.less(&BInteger::new(999).minus(&self.sorted))).booleanValue() {
                self._sort_m2_data1000.prog1();
                self.counter = self.counter.plus(&BInteger::new(1));
            }
            self._sort_m2_data1000.progress();
            self.sorted = self.sorted.plus(&BInteger::new(1));
        }
        self._sort_m2_data1000.final_evt();
    }
}

fn main() {
    let mut exec = sort_m2_data1000_exec::new();
    exec.simulate();
}
