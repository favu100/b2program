#![ allow( dead_code, unused, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::bobject;
use btypes::bboolean::{IntoBool, BBooleanT};
use btypes::binteger::BInteger;
use btypes::bboolean::BBoolean;
mod Lift;



#[derive(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct LiftExec {
    counter: BInteger,
    _Lift: Lift::Lift,
}

impl fmt::Display for LiftExec {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let mut result = "LiftExec: (".to_owned();
        result += &format!("_get_counter: {}, ", self._get_counter());
        result = result + ")";
        return write!(f, "{}", result);
    }
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

    pub fn _get_counter(&self) -> BInteger {
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
