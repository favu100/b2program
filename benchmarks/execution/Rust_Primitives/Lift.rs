#![ allow( dead_code, unused, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::bobject;
use btypes::bboolean::{IntoBool, BBooleanT};
use btypes::binteger::BInteger;
use btypes::bboolean::BBoolean;



#[derive(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct Lift {
    floor: BInteger,
}

impl fmt::Display for Lift {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let mut result = "Lift: (".to_owned();
        result += &format!("_get_floor: {}, ", self._get_floor());
        result = result + ")";
        return write!(f, "{}", result);
    }
}

impl Lift {

    pub fn new() -> Lift {
        //values: ''
        let mut m: Lift = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.floor = BInteger::new(0);
    }

    pub fn _get_floor(&self) -> BInteger {
        return self.floor.clone();
    }

    pub fn inc(&mut self) -> () {
        //pre_assert
        self.floor = self.floor.plus(&BInteger::new(1));

    }

    pub fn dec(&mut self) -> () {
        //pre_assert
        self.floor = self.floor.minus(&BInteger::new(1));

    }
}


