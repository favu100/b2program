#![ allow( dead_code, unused_imports, unused_mut, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::binteger::BInteger;
use btypes::bboolean::BBoolean;
mod Lift;



#[derive(Default, Debug)]
pub struct LiftExec {
    counter: BInteger,
    _Lift: Lift::Lift,
}

impl LiftExec {

    pub fn new() -> LiftExec {
        //values: ''
        let mut m: LiftExec = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.counter = BInteger::new(0);
        self._Lift = Lift::Lift::new();
    }

    pub fn get_counter(&self) -> BInteger {
        return self.counter.clone();
    }

    pub fn simulate(&mut self) -> () {
        while (self.counter.less(&BInteger::new(10000000))).booleanValue() {
            let mut i: Option<BInteger> = Option::None;
            i = Option::Some(BInteger::new(0));
            while (i.unwrap().less(&BInteger::new(100))).booleanValue() {
                self._Lift.inc();
                i = Option::Some(i.unwrap().plus(&BInteger::new(1)));
            }
            let mut _i: Option<BInteger> = Option::None;
            _i = Option::Some(BInteger::new(0));
            while (_i.unwrap().less(&BInteger::new(100))).booleanValue() {
                self._Lift.dec();
                _i = Option::Some(_i.unwrap().plus(&BInteger::new(1)));
            }
            self.counter = self.counter.plus(&BInteger::new(1));
        }
    }
}

fn main() {
    let mut exec = LiftExec::new();
    exec.simulate();
}
