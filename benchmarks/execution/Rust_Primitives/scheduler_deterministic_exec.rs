#![ allow( dead_code, unused, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::bobject;
use btypes::bboolean::{IntoBool, BBooleanT};
use btypes::binteger::BInteger;
use btypes::bboolean::BBoolean;
use btypes::bobject::BObject;
mod scheduler_deterministic;



#[derive(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct scheduler_deterministic_exec {
    counter: BInteger,
    _scheduler_deterministic: scheduler_deterministic::scheduler_deterministic,
}

impl fmt::Display for scheduler_deterministic_exec {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let mut result = "scheduler_deterministic_exec: (".to_owned();
        result += &format!("_get_counter: {}, ", self._get_counter());
        result = result + ")";
        return write!(f, "{}", result);
    }
}

impl scheduler_deterministic_exec {

    pub fn new() -> scheduler_deterministic_exec {
        //values: ''
        let mut m: scheduler_deterministic_exec = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.counter = BInteger::new(0);
        self._scheduler_deterministic = scheduler_deterministic::scheduler_deterministic::new();
    }

    pub fn _get_counter(&self) -> BInteger {
        return self.counter.clone();
    }

    pub fn simulate(&mut self) -> () {
        while (self.counter.less(&BInteger::new(300000))).booleanValue() {
            self._scheduler_deterministic._new(scheduler_deterministic::PID::process1);
            self._scheduler_deterministic._new(scheduler_deterministic::PID::process2);
            self._scheduler_deterministic._new(scheduler_deterministic::PID::process3);
            self._scheduler_deterministic.del(scheduler_deterministic::PID::process1);
            self._scheduler_deterministic._new(scheduler_deterministic::PID::process1);
            self._scheduler_deterministic.del(scheduler_deterministic::PID::process2);
            self._scheduler_deterministic.del(scheduler_deterministic::PID::process1);
            self._scheduler_deterministic.del(scheduler_deterministic::PID::process3);
            self._scheduler_deterministic._new(scheduler_deterministic::PID::process1);
            self._scheduler_deterministic._new(scheduler_deterministic::PID::process2);
            self._scheduler_deterministic.del(scheduler_deterministic::PID::process1);
            self._scheduler_deterministic.ready(scheduler_deterministic::PID::process2);
            self._scheduler_deterministic._new(scheduler_deterministic::PID::process1);
            self._scheduler_deterministic._new(scheduler_deterministic::PID::process3);
            self._scheduler_deterministic.del(scheduler_deterministic::PID::process1);
            self._scheduler_deterministic.ready(scheduler_deterministic::PID::process3);
            self._scheduler_deterministic._new(scheduler_deterministic::PID::process1);
            self._scheduler_deterministic.ready(scheduler_deterministic::PID::process1);
            self._scheduler_deterministic.swap(scheduler_deterministic::PID::process1);
            self._scheduler_deterministic.del(scheduler_deterministic::PID::process2);
            self._scheduler_deterministic.swap(scheduler_deterministic::PID::process3);
            self._scheduler_deterministic._new(scheduler_deterministic::PID::process2);
            self._scheduler_deterministic.del(scheduler_deterministic::PID::process1);
            self._scheduler_deterministic.del(scheduler_deterministic::PID::process2);
            self._scheduler_deterministic.swap(scheduler_deterministic::PID::process1);
            self._scheduler_deterministic._new(scheduler_deterministic::PID::process1);
            self._scheduler_deterministic._new(scheduler_deterministic::PID::process2);
            self._scheduler_deterministic.del(scheduler_deterministic::PID::process1);
            self._scheduler_deterministic.del(scheduler_deterministic::PID::process3);
            self._scheduler_deterministic._new(scheduler_deterministic::PID::process1);
            self._scheduler_deterministic.del(scheduler_deterministic::PID::process2);
            self._scheduler_deterministic.del(scheduler_deterministic::PID::process1);
            self.counter = self.counter.plus(&BInteger::new(1));
        }
    }
}

fn main() {
    let mut exec = scheduler_deterministic_exec::new();
    exec.simulate();
}