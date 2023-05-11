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





//relation_declaration
type rel_BInteger_X_BInteger = BRelation<BInteger, { BInteger::VARIANTS }, BInteger, { BInteger::VARIANTS }, 0>;
//relation_declaration done



#[derive(Default, Debug)]pub struct InsertionSortWhile {
    /*declarations*/arr: rel_BInteger_X_BInteger,
    sorted: BBoolean,
    /*constant_declarations*/n: BInteger,
}


impl InsertionSortWhile {

    pub fn new() -> InsertionSortWhile {
        //values: ''
        let mut m: InsertionSortWhile = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        /*set_initializations*/
        /*properties*///constant_initialization
    self.n = 1000;
        /*body*/let mut _ic_set_0 = rel_BInteger_X_BInteger::empty();
    //iteration_construct_enumeration
    for _ic_i_1 in set_BInteger::interval(&1, &self.n).clone().iter() {
        //lambda_expression TODO: FASTER
        _ic_set_0 = _ic_set_0.union(&brel![rel_BInteger_X_BInteger, (_ic_i_1.clone(), self.n.minus(&_ic_i_1))]);

    }
    self.arr = _ic_set_0.clone().clone();
    self.sorted = false;
        /*includesInitialization*/
    }

    pub fn get_n(&self) -> BInteger {
        return self.n.clone();
    }

    pub fn get_arr(&self) -> rel_BInteger_X_BInteger {
        return self.arr.clone();
    }

    pub fn get_sorted(&self) -> BBoolean {
        return self.sorted.clone();
    }

    pub fn Sort(&mut self) -> () {
        //select
        if self.sorted.equal(&false) {
            let mut i: Option<BInteger> = Option::None;
            i = Option::Some(2);
            while i.unwrap().lessEqual(&self.n) {
                let mut key: Option<BInteger> = Option::None;
                let mut j: Option<BInteger> = Option::None;
                key = Option::Some(self.arr.functionCall(&i.unwrap()));
                j = Option::Some(i.unwrap().minus(&1));
                while (j.unwrap().greaterEqual(&1) && self.arr.functionCall(&j.unwrap()).greater(&key.unwrap())) {
                    self.arr = self.arr._override_single(j.unwrap().plus(&1), self.arr.functionCall(&j.unwrap()));
                    j = Option::Some(j.unwrap().minus(&1));
                }
                self.arr = self.arr._override_single(j.unwrap().plus(&1), key.unwrap());
                i = Option::Some(i.unwrap().plus(&1));
            }
            self.sorted = true;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }
}


