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
pub struct DataValidationTest {
    counter: BInteger,
    error: BBoolean,
    checked: BBoolean,
    n: BInteger,
    ids: BSet<BInteger>,
    value: BRelation<BInteger, BInteger>,
    ids_for_value: BRelation<BInteger, BInteger>,
}

impl DataValidationTest {

    pub fn new() -> DataValidationTest {
        //values: ''
        let mut m: DataValidationTest = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.counter = BInteger::new(0);
        self.error = BBoolean::new(false);
        self.checked = BBoolean::new(false);
        self.n = BInteger::new(20001);
        self.ids = BSet::<BInteger>::interval(&BInteger::new(1), &self.n);
        let mut _ic_set_0 = BRelation::<BInteger, BInteger>::new(vec![]);
        for _ic_x_1 in BSet::<BInteger>::interval(&BInteger::new(1), &self.n).clone().iter().cloned() {
            _ic_set_0 = _ic_set_0._union(&BRelation::<BInteger, BInteger>::new(vec![BTuple::new(_ic_x_1, _ic_x_1.modulo(&BInteger::new(100)))]));

        }
        self.value = _ic_set_0;
        self.ids_for_value = self.value.inverse();
    }

    pub fn get_n(&self) -> BInteger {
        return self.n.clone();
    }

    pub fn get_ids(&self) -> BSet<BInteger> {
        return self.ids.clone();
    }

    pub fn get_value(&self) -> BRelation<BInteger, BInteger> {
        return self.value.clone();
    }

    pub fn get_ids_for_value(&self) -> BRelation<BInteger, BInteger> {
        return self.ids_for_value.clone();
    }

    pub fn get_counter(&self) -> BInteger {
        return self.counter.clone();
    }

    pub fn get_error(&self) -> BBoolean {
        return self.error.clone();
    }

    pub fn get_checked(&self) -> BBoolean {
        return self.checked.clone();
    }

    pub fn Validate(&mut self) -> () {
        while (self.counter.less(&self.n)).booleanValue() {
            self.counter = self.counter.plus(&BInteger::new(1));
            if (self.ids.notElementOf(&self.counter)).booleanValue() {
                self.error = BBoolean::new(true);
            } else if (BSet::<BInteger>::interval(&BInteger::new(0), &BInteger::new(99)).notElementOf(&self.value.functionCall(&self.counter))).booleanValue() {
                self.error = BBoolean::new(true);
            } else if (self.ids_for_value.relationImage(&BSet::new(vec![self.value.functionCall(&self.counter)])).card().less(&self.n.divide(&BInteger::new(100)))).booleanValue() {
                self.error = BBoolean::new(true);
            }
        }
        self.checked = BBoolean::new(true);
    }
}

