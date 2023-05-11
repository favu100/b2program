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






#[derive(Default, Debug)]pub struct Lift {
    /*declarations*/floor: BInteger,
}


impl Lift {

    pub fn new() -> Lift {
        //values: ''
        let mut m: Lift = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        /*set_initializations*/
        /*properties*/
        /*body*/self.floor = 0;
        /*includesInitialization*/
    }

    pub fn get_floor(&self) -> BInteger {
        return self.floor.clone();
    }

    pub fn inc(&mut self) -> () {
        //pre_assert
        self.floor = self.floor.plus(&1);

    }

    pub fn dec(&mut self) -> () {
        //pre_assert
        self.floor = self.floor.minus(&1);

    }
}


