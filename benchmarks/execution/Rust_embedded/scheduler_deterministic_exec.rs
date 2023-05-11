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


mod scheduler_deterministic;




#[derive(Default, Debug)]pub struct scheduler_deterministic_exec {
    /*declarations*/counter: BInteger,
    /*includes*/_scheduler_deterministic: scheduler_deterministic::scheduler_deterministic,
}


impl scheduler_deterministic_exec {

    pub fn new() -> scheduler_deterministic_exec {
        //values: ''
        let mut m: scheduler_deterministic_exec = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        /*set_initializations*/
        /*properties*/
        /*body*/self.counter = 0;
        /*includesInitialization*/self._scheduler_deterministic = scheduler_deterministic::scheduler_deterministic::new();
    }

    pub fn get_counter(&self) -> BInteger {
        return self.counter.clone();
    }

    pub fn simulate(&mut self) -> () {
        while self.counter.less(&300000) {
            self._scheduler_deterministic._new(/*enum_call*/scheduler_deterministic::PID::process1);
            self._scheduler_deterministic._new(/*enum_call*/scheduler_deterministic::PID::process2);
            self._scheduler_deterministic._new(/*enum_call*/scheduler_deterministic::PID::process3);
            self._scheduler_deterministic.del(/*enum_call*/scheduler_deterministic::PID::process1);
            self._scheduler_deterministic._new(/*enum_call*/scheduler_deterministic::PID::process1);
            self._scheduler_deterministic.del(/*enum_call*/scheduler_deterministic::PID::process2);
            self._scheduler_deterministic.del(/*enum_call*/scheduler_deterministic::PID::process1);
            self._scheduler_deterministic.del(/*enum_call*/scheduler_deterministic::PID::process3);
            self._scheduler_deterministic._new(/*enum_call*/scheduler_deterministic::PID::process1);
            self._scheduler_deterministic._new(/*enum_call*/scheduler_deterministic::PID::process2);
            self._scheduler_deterministic.del(/*enum_call*/scheduler_deterministic::PID::process1);
            self._scheduler_deterministic.ready(/*enum_call*/scheduler_deterministic::PID::process2);
            self._scheduler_deterministic._new(/*enum_call*/scheduler_deterministic::PID::process1);
            self._scheduler_deterministic._new(/*enum_call*/scheduler_deterministic::PID::process3);
            self._scheduler_deterministic.del(/*enum_call*/scheduler_deterministic::PID::process1);
            self._scheduler_deterministic.ready(/*enum_call*/scheduler_deterministic::PID::process3);
            self._scheduler_deterministic._new(/*enum_call*/scheduler_deterministic::PID::process1);
            self._scheduler_deterministic.ready(/*enum_call*/scheduler_deterministic::PID::process1);
            self._scheduler_deterministic.swap(/*enum_call*/scheduler_deterministic::PID::process1);
            self._scheduler_deterministic.del(/*enum_call*/scheduler_deterministic::PID::process2);
            self._scheduler_deterministic.swap(/*enum_call*/scheduler_deterministic::PID::process3);
            self._scheduler_deterministic._new(/*enum_call*/scheduler_deterministic::PID::process2);
            self._scheduler_deterministic.del(/*enum_call*/scheduler_deterministic::PID::process1);
            self._scheduler_deterministic.del(/*enum_call*/scheduler_deterministic::PID::process2);
            self._scheduler_deterministic.swap(/*enum_call*/scheduler_deterministic::PID::process1);
            self._scheduler_deterministic._new(/*enum_call*/scheduler_deterministic::PID::process1);
            self._scheduler_deterministic._new(/*enum_call*/scheduler_deterministic::PID::process2);
            self._scheduler_deterministic.del(/*enum_call*/scheduler_deterministic::PID::process1);
            self._scheduler_deterministic.del(/*enum_call*/scheduler_deterministic::PID::process3);
            self._scheduler_deterministic._new(/*enum_call*/scheduler_deterministic::PID::process1);
            self._scheduler_deterministic.del(/*enum_call*/scheduler_deterministic::PID::process2);
            self._scheduler_deterministic.del(/*enum_call*/scheduler_deterministic::PID::process1);
            self.counter = self.counter.plus(&1);
        }
    }
}

fn main() {
    let mut exec = scheduler_deterministic_exec::new();
    exec.simulate();
}
