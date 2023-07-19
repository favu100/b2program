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
pub enum LIFTS {
    #[default]
    Lift1 = 0, 
    Lift2 = 1, 
    Lift3 = 2, 
    Lift4 = 3
}

impl LIFTS {
    pub fn equal(&self, other: &LIFTS) -> bool { *self == *other }
    pub fn unequal(&self, other: &LIFTS) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::Lift1, 
            1 => Self::Lift2, 
            2 => Self::Lift3, 
            3 => Self::Lift4, 
            _ => panic!("LIFTS index out of range! {:?}", idx)
        }
    }
}

impl SetItem<4> for LIFTS {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_LIFTS = BSet<LIFTS, 4>;
//set_enum_declaration done

//relation_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum LIFTS_X_LIFTS {
    #[default]
    Lift1_Lift1 = 0, 
    Lift1_Lift2 = 1, 
    Lift1_Lift3 = 2, 
    Lift1_Lift4 = 3, 
    Lift2_Lift1 = 4, 
    Lift2_Lift2 = 5, 
    Lift2_Lift3 = 6, 
    Lift2_Lift4 = 7, 
    Lift3_Lift1 = 8, 
    Lift3_Lift2 = 9, 
    Lift3_Lift3 = 10, 
    Lift3_Lift4 = 11, 
    Lift4_Lift1 = 12, 
    Lift4_Lift2 = 13, 
    Lift4_Lift3 = 14, 
    Lift4_Lift4 = 15
}
type rel_LIFTS_X_LIFTS = BRelation<LIFTS, { LIFTS::VARIANTS }, LIFTS, { LIFTS::VARIANTS }, 16>;
//relation_declaration done



//relation_declaration
type rel_LIFTS_X_BInteger = BRelation<LIFTS, { LIFTS::VARIANTS }, BInteger, { BInteger::VARIANTS }, 0>;
//relation_declaration done



#[derive(Default, Debug)]
pub struct MultiLift {
    /*declarations*/ActiveLifts: rel_LIFTS_X_BInteger,
    InactiveLifts: set_LIFTS,
    NextActiveLift: rel_LIFTS_X_LIFTS,
    /*constant_declarations*/LiftOrder: rel_LIFTS_X_BInteger,
    /*sets*//*set_declaration*/_LIFTS: set_LIFTS,
}


impl MultiLift {

    pub fn new() -> MultiLift {
        //values: ''
        let mut m: MultiLift = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        /*set_initializations*///set_initialization
    self._LIFTS = bset![LIFTS, /*enum_call*/LIFTS::Lift1, /*enum_call*/LIFTS::Lift2, /*enum_call*/LIFTS::Lift3, /*enum_call*/LIFTS::Lift4];
        /*properties*///constant_initialization
    self.LiftOrder = brel![rel_LIFTS_X_BInteger, (/*enum_call*/LIFTS::Lift1.clone(), 1.clone()), (/*enum_call*/LIFTS::Lift2.clone(), 2.clone()), (/*enum_call*/LIFTS::Lift3.clone(), 3.clone()), (/*enum_call*/LIFTS::Lift4.clone(), 4.clone())];
        /*body*/self.ActiveLifts = brel![rel_LIFTS_X_BInteger, (/*enum_call*/LIFTS::Lift1.clone(), 0.clone())].clone().clone();
    self.InactiveLifts = bset![LIFTS, /*enum_call*/LIFTS::Lift2, /*enum_call*/LIFTS::Lift3, /*enum_call*/LIFTS::Lift4].clone().clone();
    self.NextActiveLift = brel![rel_LIFTS_X_LIFTS, (/*enum_call*/LIFTS::Lift1.clone(), /*enum_call*/LIFTS::Lift1.clone())].clone().clone();
        /*includesInitialization*/
    }

    pub fn get_LiftOrder(&self) -> rel_LIFTS_X_BInteger {
        return self.LiftOrder.clone();
    }

    pub fn get_ActiveLifts(&self) -> rel_LIFTS_X_BInteger {
        return self.ActiveLifts.clone();
    }

    pub fn get_InactiveLifts(&self) -> set_LIFTS {
        return self.InactiveLifts.clone();
    }

    pub fn get_NextActiveLift(&self) -> rel_LIFTS_X_LIFTS {
        return self.NextActiveLift.clone();
    }

    pub fn get__LIFTS(&self) -> set_LIFTS {
        return self._LIFTS.clone();
    }

    pub fn inc_lift(&mut self, mut l: LIFTS) -> () {
        //pre_assert
        self.ActiveLifts = self.ActiveLifts._override_single(l, self.ActiveLifts.functionCall(&l).plus(&1));

    }

    pub fn dec_lift(&mut self, mut l: LIFTS) -> () {
        //pre_assert
        self.ActiveLifts = self.ActiveLifts._override_single(l, self.ActiveLifts.functionCall(&l).minus(&1));

    }

    pub fn init_lift(&mut self, mut l: LIFTS) -> () {
        //pre_assert
        //any
        //iteration_construct_assignment
        let mut _ic_set_0 = set_LIFTS::empty();
        //iteration_construct_enumeration
        for _ic_al_1 in self.NextActiveLift.domain().clone().iter() {
            //set_comprehension_predicate
            if self.LiftOrder.functionCall(&_ic_al_1).less(&self.LiftOrder.functionCall(&l)) {
                _ic_set_0 = _ic_set_0.union(&bset![LIFTS, _ic_al_1]);
            }

        }
        {
            let mut _ic_smallerLifts_1 = _ic_set_0;
            //iteration_construct_assignment
            let mut _ic_set_1 = set_LIFTS::empty();
            //iteration_construct_enumeration
            for _ic_al_1 in self.NextActiveLift.domain().clone().iter() {
                //set_comprehension_predicate
                if self.LiftOrder.functionCall(&_ic_al_1).greater(&self.LiftOrder.functionCall(&l)) {
                    _ic_set_1 = _ic_set_1.union(&bset![LIFTS, _ic_al_1]);
                }

            }
            {
                let mut _ic_biggerLifts_1 = _ic_set_1;
                //any_body
                let mut _ic_set_2 = set_LIFTS::empty();
                //iteration_construct_enumeration
                for _ic_al_1 in self.NextActiveLift.domain().clone().iter() {
                    //set_comprehension_predicate
                    if self.LiftOrder.functionCall(&_ic_al_1).less(&self.LiftOrder.functionCall(&l)) {
                        _ic_set_2 = _ic_set_2.union(&bset![LIFTS, _ic_al_1]);
                    }

                }let mut _ic_set_3 = set_LIFTS::empty();
                //iteration_construct_enumeration
                for _ic_al_1 in self.NextActiveLift.domain().clone().iter() {
                    //set_comprehension_predicate
                    if self.LiftOrder.functionCall(&_ic_al_1).greater(&self.LiftOrder.functionCall(&l)) {
                        _ic_set_3 = _ic_set_3.union(&bset![LIFTS, _ic_al_1]);
                    }

                }
                let mut _ld_InactiveLifts = self.InactiveLifts.clone();
                self.ActiveLifts = self.ActiveLifts._override_single(l, 0);
                self.InactiveLifts = _ld_InactiveLifts.difference(&bset![LIFTS, l]).clone().clone();
                //if
                if _ic_smallerLifts_1.card().equal(&0) {
                    self.NextActiveLift = self.NextActiveLift._override_single(self.LiftOrder.inverse().functionCall(&self.LiftOrder.relationImage(&_ic_biggerLifts_1)._max()), l);
                    self.NextActiveLift = self.NextActiveLift._override_single(l, self.LiftOrder.inverse().functionCall(&self.LiftOrder.relationImage(&_ic_biggerLifts_1)._min()));
                } //else
                else {
                    self.NextActiveLift = self.NextActiveLift._override_single(self.LiftOrder.inverse().functionCall(&self.LiftOrder.relationImage(&_ic_smallerLifts_1)._max()), l);
                    //if
                    if _ic_biggerLifts_1.card().equal(&0) {
                        self.NextActiveLift = self.NextActiveLift._override_single(l, self.LiftOrder.inverse().functionCall(&self.LiftOrder.relationImage(&_ic_smallerLifts_1)._min()));
                    } //else
                    else {
                        self.NextActiveLift = self.NextActiveLift._override_single(l, self.LiftOrder.inverse().functionCall(&self.LiftOrder.relationImage(&_ic_biggerLifts_1)._min()));
                    }
                }

            }
        }

    }

    pub fn close_lift(&mut self, mut l: LIFTS) -> () {
        //pre_assert
        let mut _ld_InactiveLifts = self.InactiveLifts.clone();
        let mut _ld_ActiveLifts = self.ActiveLifts.clone();
        self.ActiveLifts = _ld_ActiveLifts.domainSubstraction(&bset![LIFTS, l]).clone().clone();
        self.InactiveLifts = _ld_InactiveLifts.union(&bset![LIFTS, l]).clone().clone();
        //any
        //iteration_construct_assignment
        {
            let mut _ic_l_pred_1 = self.NextActiveLift.inverse().functionCall(&l);
            //iteration_construct_assignment
            {
                let mut _ic_l_succ_1 = self.NextActiveLift.functionCall(&l);
                //any_body
                self.NextActiveLift = self.NextActiveLift.difference(&brel![rel_LIFTS_X_LIFTS, (l.clone(), _ic_l_succ_1.clone())]).clone().clone();
                self.NextActiveLift = self.NextActiveLift._override_single(_ic_l_pred_1, _ic_l_succ_1);

            }
        }

    }

    pub fn getFloor(&mut self, mut l: LIFTS) -> BInteger {
        let mut out: Option<BInteger> = Option::None;
        //pre_assert
        out = Option::Some(self.ActiveLifts.functionCall(&l));

        return out.unwrap();
    }
}

