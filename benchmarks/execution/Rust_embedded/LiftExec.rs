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


mod Lift;




#[derive(Default, Debug)]pub struct LiftExec {
    /*declarations*/counter: BInteger,
    /*includes*/_Lift: Lift::Lift,
}


impl LiftExec {

    pub fn new() -> LiftExec {
        //values: ''
        let mut m: LiftExec = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        /*set_initializations*/
        /*properties*/
        /*body*/self.counter = 0;
        /*includesInitialization*/self._Lift = Lift::Lift::new();
    }

    pub fn get_counter(&self) -> BInteger {
        return self.counter.clone();
    }

    pub fn simulate(&mut self) -> () {
        while self.counter.less(&10000000) {
            let mut i: Option<BInteger> = Option::None;
            i = Option::Some(0);
            while i.unwrap().less(&100) {
                self._Lift.inc();
                i = Option::Some(i.unwrap().plus(&1));
            }
            let mut _i: Option<BInteger> = Option::None;
            _i = Option::Some(0);
            while _i.unwrap().less(&100) {
                self._Lift.dec();
                _i = Option::Some(_i.unwrap().plus(&1));
            }
            self.counter = self.counter.plus(&1);
        }
    }
}

fn main() {
    let mut exec = LiftExec::new();
    exec.simulate();
}
