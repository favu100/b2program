#![ allow( dead_code, unused_imports, unused_mut, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::binteger::BInteger;
use btypes::bboolean::BBoolean;
use btypes::brelation::BRelation;
use btypes::bset::BSet;
use btypes::btuple::BTuple;



#[derive(Default, Debug)]
pub struct InsertionSortWhile {
    arr: BRelation<BInteger, BInteger>,
    sorted: BBoolean,
    n: BInteger,
}

impl InsertionSortWhile {

    pub fn new() -> InsertionSortWhile {
        //values: ''
        let mut m: InsertionSortWhile = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        let mut _ic_set_0 = BRelation::<BInteger, BInteger>::new(vec![]);
        for _ic_i_1 in BSet::<BInteger>::interval(&BInteger::new(1), &self.n).clone().iter().cloned() {
            _ic_set_0 = _ic_set_0._union(&BRelation::<BInteger, BInteger>::new(vec![BTuple::new(_ic_i_1, self.n.minus(&_ic_i_1))]));

        }
        self.arr = _ic_set_0.clone().clone();
        self.sorted = BBoolean::new(false);
        self.n = BInteger::new(1000);
    }

    pub fn get_n(&self) -> BInteger {
        return self.n.clone();
    }

    pub fn get_arr(&self) -> BRelation<BInteger, BInteger> {
        return self.arr.clone();
    }

    pub fn get_sorted(&self) -> BBoolean {
        return self.sorted.clone();
    }

    pub fn Sort(&mut self) -> () {
        if (self.sorted.equal(&BBoolean::new(false))).booleanValue() {
            let mut i: Option<BInteger> = Option::None;
            i = Option::Some(BInteger::new(2));
            while (i.unwrap().lessEqual(&self.n)).booleanValue() {
                let mut key: Option<BInteger> = Option::None;
                let mut j: Option<BInteger> = Option::None;
                key = Option::Some(self.arr.functionCall(&i.unwrap()));
                j = Option::Some(i.unwrap().minus(&BInteger::new(1)));
                while (j.unwrap().greaterEqual(&BInteger::new(1)).and(&self.arr.functionCall(&j.unwrap()).greater(&key.unwrap()))).booleanValue() {
                    self.arr = self.arr._override(&BRelation::<BInteger, BInteger>::new(vec![BTuple::new(j.unwrap().plus(&BInteger::new(1)),self.arr.functionCall(&j.unwrap()))]));
                    j = Option::Some(j.unwrap().minus(&BInteger::new(1)));
                }
                self.arr = self.arr._override(&BRelation::<BInteger, BInteger>::new(vec![BTuple::new(j.unwrap().plus(&BInteger::new(1)),key.unwrap())]));
                i = Option::Some(i.unwrap().plus(&BInteger::new(1)));
            }
            self.sorted = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }
}

