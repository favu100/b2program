#![ allow( dead_code, unused, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::bobject;
use btypes::bboolean::{IntoBool, BBooleanT};
use btypes::binteger::BInteger;
use btypes::bboolean::BBoolean;
mod TrafficLight;



#[derive(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct TrafficLightExec {
    counter: BInteger,
    _TrafficLight: TrafficLight::TrafficLight,
}

impl fmt::Display for TrafficLightExec {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let mut result = "TrafficLightExec: (".to_owned();
        result += &format!("_get_counter: {}, ", self._get_counter());
        result = result + ")";
        return write!(f, "{}", result);
    }
}

impl TrafficLightExec {

    pub fn new() -> TrafficLightExec {
        //values: ''
        let mut m: TrafficLightExec = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.counter = BInteger::new(0);
        self._TrafficLight = TrafficLight::TrafficLight::new();
    }

    pub fn _get_counter(&self) -> BInteger {
        return self.counter.clone();
    }

    pub fn simulate(&mut self) -> () {
        while (self.counter.less(&BInteger::new(300000000))).booleanValue() {
            self._TrafficLight.cars_ry();
            self._TrafficLight.cars_g();
            self._TrafficLight.cars_y();
            self._TrafficLight.cars_r();
            self._TrafficLight.peds_g();
            self._TrafficLight.peds_r();
            self.counter = self.counter.plus(&BInteger::new(1));
        }
    }
}

fn main() {
    let mut exec = TrafficLightExec::new();
    exec.simulate();
}
