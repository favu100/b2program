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


mod TrafficLight;




#[derive(Default, Debug)]pub struct TrafficLightExec {
    /*declarations*/counter: BInteger,
    /*includes*/_TrafficLight: TrafficLight::TrafficLight,
}


impl TrafficLightExec {

    pub fn new() -> TrafficLightExec {
        //values: ''
        let mut m: TrafficLightExec = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        /*set_initializations*/
        /*properties*/
        /*body*/self.counter = 0;
        /*includesInitialization*/self._TrafficLight = TrafficLight::TrafficLight::new();
    }

    pub fn get_counter(&self) -> BInteger {
        return self.counter.clone();
    }

    pub fn simulate(&mut self) -> () {
        while self.counter.less(&300000000) {
            self._TrafficLight.cars_ry();
            self._TrafficLight.cars_g();
            self._TrafficLight.cars_y();
            self._TrafficLight.cars_r();
            self._TrafficLight.peds_g();
            self._TrafficLight.peds_r();
            self.counter = self.counter.plus(&1);
        }
    }
}

fn main() {
    let mut exec = TrafficLightExec::new();
    exec.simulate();
}
