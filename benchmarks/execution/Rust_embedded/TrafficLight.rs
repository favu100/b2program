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




//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum colors {
    #[default]
    red = 0, 
    redyellow = 1, 
    yellow = 2, 
    green = 3
}

impl colors {
    pub fn equal(&self, other: &colors) -> bool { *self == *other }
    pub fn unequal(&self, other: &colors) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::red, 
            1 => Self::redyellow, 
            2 => Self::yellow, 
            3 => Self::green, 
            _ => panic!("colors index out of range! {:?}", idx)
        }
    }
}

impl SetItem<4> for colors {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_colors = BSet<colors, 4>;
//set_enum_declaration done


#[derive(Default, Debug)]pub struct TrafficLight {
    /*declarations*/tl_cars: colors,
    tl_peds: colors,
    /*sets*//*set_declaration*/_colors: set_colors,
}


impl TrafficLight {

    pub fn new() -> TrafficLight {
        //values: ''
        let mut m: TrafficLight = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        /*set_initializations*///set_initialization
    self._colors = bset![colors, /*enum_call*/colors::red, /*enum_call*/colors::redyellow, /*enum_call*/colors::yellow, /*enum_call*/colors::green];
        /*properties*/
        /*body*/self.tl_cars = /*enum_call*/colors::red;
    self.tl_peds = /*enum_call*/colors::red;
        /*includesInitialization*/
    }

    pub fn get_tl_cars(&self) -> colors {
        return self.tl_cars.clone();
    }

    pub fn get_tl_peds(&self) -> colors {
        return self.tl_peds.clone();
    }

    pub fn get__colors(&self) -> set_colors {
        return self._colors.clone();
    }

    pub fn cars_ry(&mut self) -> () {
        //select
        if (self.tl_cars.equal(&/*enum_call*/colors::red) && self.tl_peds.equal(&/*enum_call*/colors::red)) {
            self.tl_cars = /*enum_call*/colors::redyellow;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn cars_y(&mut self) -> () {
        //select
        if (self.tl_cars.equal(&/*enum_call*/colors::green) && self.tl_peds.equal(&/*enum_call*/colors::red)) {
            self.tl_cars = /*enum_call*/colors::yellow;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn cars_g(&mut self) -> () {
        //select
        if (self.tl_cars.equal(&/*enum_call*/colors::redyellow) && self.tl_peds.equal(&/*enum_call*/colors::red)) {
            self.tl_cars = /*enum_call*/colors::green;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn cars_r(&mut self) -> () {
        //select
        if (self.tl_cars.equal(&/*enum_call*/colors::yellow) && self.tl_peds.equal(&/*enum_call*/colors::red)) {
            self.tl_cars = /*enum_call*/colors::red;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn peds_r(&mut self) -> () {
        //select
        if (self.tl_peds.equal(&/*enum_call*/colors::green) && self.tl_cars.equal(&/*enum_call*/colors::red)) {
            self.tl_peds = /*enum_call*/colors::red;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn peds_g(&mut self) -> () {
        //select
        if (self.tl_peds.equal(&/*enum_call*/colors::red) && self.tl_cars.equal(&/*enum_call*/colors::red)) {
            self.tl_peds = /*enum_call*/colors::green;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }
}


