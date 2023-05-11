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



#[derive(Default, Debug)]pub struct DataValidationTest {
    /*declarations*/counter: BInteger,
    error: BBoolean,
    checked: BBoolean,
    /*constant_declarations*/n: BInteger,
    ids: set_BInteger,
    value: rel_BInteger_X_BInteger,
    ids_for_value: rel_BInteger_X_BInteger,
}


impl DataValidationTest {

    pub fn new() -> DataValidationTest {
        //values: ''
        let mut m: DataValidationTest = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        /*set_initializations*/
        /*properties*///constant_initialization
    self.n = 20001;
    //constant_initialization
    self.ids = set_BInteger::interval(&1, &self.n);
    //constant_initialization
    let mut _ic_set_0 = rel_BInteger_X_BInteger::empty();
    //iteration_construct_enumeration
    for _ic_x_1 in set_BInteger::interval(&1, &self.n).clone().iter() {
        //lambda_expression TODO: FASTER
        _ic_set_0 = _ic_set_0.union(&brel![rel_BInteger_X_BInteger, (_ic_x_1.clone(), _ic_x_1.modulo(&100))]);

    }
    self.value = _ic_set_0;
    //constant_initialization
    self.ids_for_value = self.value.inverse();
        /*body*/self.counter = 0;
    self.error = false;
    self.checked = false;
        /*includesInitialization*/
    }

    pub fn get_n(&self) -> BInteger {
        return self.n.clone();
    }

    pub fn get_ids(&self) -> set_BInteger {
        return self.ids.clone();
    }

    pub fn get_value(&self) -> rel_BInteger_X_BInteger {
        return self.value.clone();
    }

    pub fn get_ids_for_value(&self) -> rel_BInteger_X_BInteger {
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
        while self.counter.less(&self.n) {
            self.counter = self.counter.plus(&1);
            //if
            if self.ids.notElementOf(&self.counter) {
                self.error = true;
            } //elseif
            else if set_BInteger::interval(&0, &99).notElementOf(&self.value.functionCall(&self.counter)) {
                self.error = true;
            } //elseif
            else if self.ids_for_value.relationImage(&bset![BInteger, self.value.functionCall(&self.counter)]).card().less(&self.n.divide(&100)) {
                self.error = true;
            }
        }
        self.checked = true;
    }
}


