#![ allow( dead_code, unused, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::env;
use std::sync::atomic::{AtomicU64, Ordering};
use std::sync::{Arc, mpsc, Mutex};
use std::collections::{HashSet, LinkedList};
use dashmap::DashSet;
use threadpool::ThreadPool;
use std::sync::mpsc::channel;
use derivative::Derivative;
use std::time::{Duration};
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::bobject;
use btypes::bboolean::{IntoBool, BBooleanT};
use btypes::bboolean::BBoolean;
use btypes::brelation::BRelation;
use btypes::bset::BSet;
use btypes::bobject::BObject;
use btypes::btuple::BTuple;

#[derive(Clone, Copy)]
pub enum MC_TYPE { BFS, DFS, MIXED }


#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum BLOCKS {
    A, 
    B, 
    C, 
    D, 
    E, 
    F, 
    G, 
    H, 
    I
}
impl BLOCKS {
    pub fn equal(&self, other: &BLOCKS) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &BLOCKS) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for BLOCKS {}
impl Default for BLOCKS {
    fn default() -> Self { BLOCKS::A }
}
impl fmt::Display for BLOCKS {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           BLOCKS::A => write!(f, "A"),
           BLOCKS::B => write!(f, "B"),
           BLOCKS::C => write!(f, "C"),
           BLOCKS::D => write!(f, "D"),
           BLOCKS::E => write!(f, "E"),
           BLOCKS::F => write!(f, "F"),
           BLOCKS::G => write!(f, "G"),
           BLOCKS::H => write!(f, "H"),
           BLOCKS::I => write!(f, "I"),
       }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum ROUTES {
    R1, 
    R2, 
    R3, 
    R4, 
    R5, 
    R6, 
    R7, 
    R8
}
impl ROUTES {
    pub fn equal(&self, other: &ROUTES) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &ROUTES) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for ROUTES {}
impl Default for ROUTES {
    fn default() -> Self { ROUTES::R1 }
}
impl fmt::Display for ROUTES {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           ROUTES::R1 => write!(f, "R1"),
           ROUTES::R2 => write!(f, "R2"),
           ROUTES::R3 => write!(f, "R3"),
           ROUTES::R4 => write!(f, "R4"),
           ROUTES::R5 => write!(f, "R5"),
           ROUTES::R6 => write!(f, "R6"),
           ROUTES::R7 => write!(f, "R7"),
           ROUTES::R8 => write!(f, "R8"),
       }
    }
}

#[derive(Derivative)]
#[derivative(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct Train1_Lukas_POR_v3 {
    LBT: BSet<BLOCKS>,
    TRK: BRelation<BLOCKS, BLOCKS>,
    frm: BSet<ROUTES>,
    OCC: BSet<BLOCKS>,
    resbl: BSet<BLOCKS>,
    resrt: BSet<ROUTES>,
    rsrtbl: BRelation<BLOCKS, ROUTES>,
    fst: BRelation<ROUTES, BLOCKS>,
    lst: BRelation<ROUTES, BLOCKS>,
    nxt: BRelation<ROUTES, BRelation<BLOCKS, BLOCKS>>,
    rtbl: BRelation<BLOCKS, ROUTES>,
    _BLOCKS: BSet<BLOCKS>,
    _ROUTES: BSet<ROUTES>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_route_reservation: Option<BSet<ROUTES>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_route_freeing: Option<BSet<ROUTES>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_FRONT_MOVE_1: Option<BSet<ROUTES>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_FRONT_MOVE_2: Option<BSet<BLOCKS>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_BACK_MOVE_1: Option<BSet<BLOCKS>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_BACK_MOVE_2: Option<BSet<BLOCKS>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_point_positionning: Option<BSet<ROUTES>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_route_formation: Option<BSet<ROUTES>>,}

impl fmt::Display for Train1_Lukas_POR_v3 {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let mut result = "Train1_Lukas_POR_v3: (".to_owned();
        result += &format!("_get_LBT: {}, ", self._get_LBT());
        result += &format!("_get_TRK: {}, ", self._get_TRK());
        result += &format!("_get_frm: {}, ", self._get_frm());
        result += &format!("_get_OCC: {}, ", self._get_OCC());
        result += &format!("_get_resbl: {}, ", self._get_resbl());
        result += &format!("_get_resrt: {}, ", self._get_resrt());
        result += &format!("_get_rsrtbl: {}, ", self._get_rsrtbl());
        result = result + ")";
        return write!(f, "{}", result);
    }
}

impl Train1_Lukas_POR_v3 {

    pub fn new() -> Train1_Lukas_POR_v3 {
        //values: ''
        let mut m: Train1_Lukas_POR_v3 = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self._BLOCKS = BSet::new(vec![BLOCKS::A, BLOCKS::B, BLOCKS::C, BLOCKS::D, BLOCKS::E, BLOCKS::F, BLOCKS::G, BLOCKS::H, BLOCKS::I]);
        self._ROUTES = BSet::new(vec![ROUTES::R1, ROUTES::R2, ROUTES::R3, ROUTES::R4, ROUTES::R5, ROUTES::R6, ROUTES::R7, ROUTES::R8]);
        self.nxt = BRelation::new(vec![BTuple::from_refs(&ROUTES::R1, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::A, &BLOCKS::B), BTuple::from_refs(&BLOCKS::B, &BLOCKS::C)])), BTuple::from_refs(&ROUTES::R2, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::A, &BLOCKS::B), BTuple::from_refs(&BLOCKS::B, &BLOCKS::D), BTuple::from_refs(&BLOCKS::D, &BLOCKS::E), BTuple::from_refs(&BLOCKS::E, &BLOCKS::F)])), BTuple::from_refs(&ROUTES::R3, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::H, &BLOCKS::G), BTuple::from_refs(&BLOCKS::G, &BLOCKS::E), BTuple::from_refs(&BLOCKS::E, &BLOCKS::F)])), BTuple::from_refs(&ROUTES::R4, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::I, &BLOCKS::G), BTuple::from_refs(&BLOCKS::G, &BLOCKS::E), BTuple::from_refs(&BLOCKS::E, &BLOCKS::F)])), BTuple::from_refs(&ROUTES::R5, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::C, &BLOCKS::B), BTuple::from_refs(&BLOCKS::B, &BLOCKS::A)])), BTuple::from_refs(&ROUTES::R6, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::F, &BLOCKS::E), BTuple::from_refs(&BLOCKS::E, &BLOCKS::D), BTuple::from_refs(&BLOCKS::D, &BLOCKS::B), BTuple::from_refs(&BLOCKS::B, &BLOCKS::A)])), BTuple::from_refs(&ROUTES::R7, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::F, &BLOCKS::E), BTuple::from_refs(&BLOCKS::E, &BLOCKS::G), BTuple::from_refs(&BLOCKS::G, &BLOCKS::H)])), BTuple::from_refs(&ROUTES::R8, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::F, &BLOCKS::E), BTuple::from_refs(&BLOCKS::E, &BLOCKS::G), BTuple::from_refs(&BLOCKS::G, &BLOCKS::I)]))]);
        self.fst = BRelation::new(vec![BTuple::from_refs(&ROUTES::R1, &BLOCKS::A), BTuple::from_refs(&ROUTES::R2, &BLOCKS::A), BTuple::from_refs(&ROUTES::R3, &BLOCKS::H), BTuple::from_refs(&ROUTES::R4, &BLOCKS::I), BTuple::from_refs(&ROUTES::R5, &BLOCKS::C), BTuple::from_refs(&ROUTES::R6, &BLOCKS::F), BTuple::from_refs(&ROUTES::R7, &BLOCKS::F), BTuple::from_refs(&ROUTES::R8, &BLOCKS::F)]);
        self.lst = BRelation::new(vec![BTuple::from_refs(&ROUTES::R1, &BLOCKS::C), BTuple::from_refs(&ROUTES::R2, &BLOCKS::F), BTuple::from_refs(&ROUTES::R3, &BLOCKS::F), BTuple::from_refs(&ROUTES::R4, &BLOCKS::F), BTuple::from_refs(&ROUTES::R5, &BLOCKS::A), BTuple::from_refs(&ROUTES::R6, &BLOCKS::A), BTuple::from_refs(&ROUTES::R7, &BLOCKS::H), BTuple::from_refs(&ROUTES::R8, &BLOCKS::I)]);
        self.rtbl = BRelation::new(vec![BTuple::from_refs(&BLOCKS::A, &ROUTES::R1), BTuple::from_refs(&BLOCKS::A, &ROUTES::R2), BTuple::from_refs(&BLOCKS::A, &ROUTES::R5), BTuple::from_refs(&BLOCKS::A, &ROUTES::R6), BTuple::from_refs(&BLOCKS::B, &ROUTES::R1), BTuple::from_refs(&BLOCKS::B, &ROUTES::R2), BTuple::from_refs(&BLOCKS::B, &ROUTES::R5), BTuple::from_refs(&BLOCKS::B, &ROUTES::R6), BTuple::from_refs(&BLOCKS::C, &ROUTES::R1), BTuple::from_refs(&BLOCKS::C, &ROUTES::R5), BTuple::from_refs(&BLOCKS::D, &ROUTES::R2), BTuple::from_refs(&BLOCKS::D, &ROUTES::R6), BTuple::from_refs(&BLOCKS::E, &ROUTES::R2), BTuple::from_refs(&BLOCKS::E, &ROUTES::R3), BTuple::from_refs(&BLOCKS::E, &ROUTES::R4), BTuple::from_refs(&BLOCKS::E, &ROUTES::R6), BTuple::from_refs(&BLOCKS::E, &ROUTES::R7), BTuple::from_refs(&BLOCKS::E, &ROUTES::R8), BTuple::from_refs(&BLOCKS::F, &ROUTES::R2), BTuple::from_refs(&BLOCKS::F, &ROUTES::R3), BTuple::from_refs(&BLOCKS::F, &ROUTES::R4), BTuple::from_refs(&BLOCKS::F, &ROUTES::R6), BTuple::from_refs(&BLOCKS::F, &ROUTES::R7), BTuple::from_refs(&BLOCKS::F, &ROUTES::R8), BTuple::from_refs(&BLOCKS::G, &ROUTES::R3), BTuple::from_refs(&BLOCKS::G, &ROUTES::R4), BTuple::from_refs(&BLOCKS::G, &ROUTES::R4), BTuple::from_refs(&BLOCKS::G, &ROUTES::R7), BTuple::from_refs(&BLOCKS::G, &ROUTES::R8), BTuple::from_refs(&BLOCKS::H, &ROUTES::R3), BTuple::from_refs(&BLOCKS::H, &ROUTES::R7), BTuple::from_refs(&BLOCKS::I, &ROUTES::R4), BTuple::from_refs(&BLOCKS::I, &ROUTES::R8)]);
        self.resrt = BSet::<ROUTES>::new(vec![]).clone().clone();
        self.resbl = BSet::<BLOCKS>::new(vec![]).clone().clone();
        self.rsrtbl = BRelation::<BLOCKS, ROUTES>::new(vec![]).clone().clone();
        self.OCC = BSet::<BLOCKS>::new(vec![]).clone().clone();
        self.TRK = BRelation::<BLOCKS, BLOCKS>::new(vec![]).clone().clone();
        self.frm = BSet::<ROUTES>::new(vec![]).clone().clone();
        self.LBT = BSet::<BLOCKS>::new(vec![]).clone().clone();
    }

    pub fn _get_fst(&self) -> BRelation<ROUTES, BLOCKS> {
        return self.fst.clone();
    }

    pub fn _get_lst(&self) -> BRelation<ROUTES, BLOCKS> {
        return self.lst.clone();
    }

    pub fn _get_nxt(&self) -> BRelation<ROUTES, BRelation<BLOCKS, BLOCKS>> {
        return self.nxt.clone();
    }

    pub fn _get_rtbl(&self) -> BRelation<BLOCKS, ROUTES> {
        return self.rtbl.clone();
    }

    pub fn _get_LBT(&self) -> BSet<BLOCKS> {
        return self.LBT.clone();
    }

    pub fn _get_TRK(&self) -> BRelation<BLOCKS, BLOCKS> {
        return self.TRK.clone();
    }

    pub fn _get_frm(&self) -> BSet<ROUTES> {
        return self.frm.clone();
    }

    pub fn _get_OCC(&self) -> BSet<BLOCKS> {
        return self.OCC.clone();
    }

    pub fn _get_resbl(&self) -> BSet<BLOCKS> {
        return self.resbl.clone();
    }

    pub fn _get_resrt(&self) -> BSet<ROUTES> {
        return self.resrt.clone();
    }

    pub fn _get_rsrtbl(&self) -> BRelation<BLOCKS, ROUTES> {
        return self.rsrtbl.clone();
    }

    pub fn _get__BLOCKS(&self) -> BSet<BLOCKS> {
        return self._BLOCKS.clone();
    }

    pub fn _get__ROUTES(&self) -> BSet<ROUTES> {
        return self._ROUTES.clone();
    }

    pub fn route_reservation(&mut self, mut r: ROUTES) -> () {
        //pre_assert
        let mut _ld_resrt = self.resrt.clone();
        let mut _ld_rsrtbl = self.rsrtbl.clone();
        let mut _ld_resbl = self.resbl.clone();
        self.resrt = _ld_resrt._union(&BSet::new(vec![r.clone()])).clone().clone();
        self.rsrtbl = _ld_rsrtbl._union(&self.rtbl.rangeRestriction(&BSet::new(vec![r.clone()]))).clone().clone();
        self.resbl = _ld_resbl._union(&self.rtbl.inverse().relationImage(&BSet::new(vec![r.clone()]))).clone().clone();

    }

    pub fn route_freeing(&mut self, mut r: ROUTES) -> () {
        //pre_assert
        let mut _ld_frm = self.frm.clone();
        let mut _ld_resrt = self.resrt.clone();
        self.resrt = _ld_resrt.difference(&BSet::new(vec![r.clone()])).clone().clone();
        self.frm = _ld_frm.difference(&BSet::new(vec![r.clone()])).clone().clone();

    }

    pub fn FRONT_MOVE_1(&mut self, mut r: ROUTES) -> () {
        //pre_assert
        let mut _ld_OCC = self.OCC.clone();
        let mut _ld_LBT = self.LBT.clone();
        self.OCC = _ld_OCC._union(&BSet::new(vec![self.fst.functionCall(&r).clone()])).clone().clone();
        self.LBT = _ld_LBT._union(&BSet::new(vec![self.fst.functionCall(&r).clone()])).clone().clone();

    }

    pub fn FRONT_MOVE_2(&mut self, mut b: BLOCKS) -> () {
        //pre_assert
        self.OCC = self.OCC._union(&BSet::new(vec![self.TRK.functionCall(&b).clone()])).clone().clone();

    }

    pub fn BACK_MOVE_1(&mut self, mut b: BLOCKS) -> () {
        //pre_assert
        let mut _ld_rsrtbl = self.rsrtbl.clone();
        let mut _ld_resbl = self.resbl.clone();
        let mut _ld_OCC = self.OCC.clone();
        let mut _ld_LBT = self.LBT.clone();
        self.OCC = _ld_OCC.difference(&BSet::new(vec![b.clone()])).clone().clone();
        self.rsrtbl = _ld_rsrtbl.domainSubstraction(&BSet::new(vec![b.clone()])).clone().clone();
        self.resbl = _ld_resbl.difference(&BSet::new(vec![b.clone()])).clone().clone();
        self.LBT = _ld_LBT.difference(&BSet::new(vec![b.clone()])).clone().clone();

    }

    pub fn BACK_MOVE_2(&mut self, mut b: BLOCKS) -> () {
        //pre_assert
        let mut _ld_rsrtbl = self.rsrtbl.clone();
        let mut _ld_resbl = self.resbl.clone();
        let mut _ld_OCC = self.OCC.clone();
        let mut _ld_LBT = self.LBT.clone();
        self.OCC = _ld_OCC.difference(&BSet::new(vec![b.clone()])).clone().clone();
        self.rsrtbl = _ld_rsrtbl.domainSubstraction(&BSet::new(vec![b.clone()])).clone().clone();
        self.resbl = _ld_resbl.difference(&BSet::new(vec![b.clone()])).clone().clone();
        self.LBT = _ld_LBT.difference(&BSet::new(vec![b.clone()]))._union(&BSet::new(vec![self.TRK.functionCall(&b).clone()])).clone().clone();

    }

    pub fn point_positionning(&mut self, mut r: ROUTES) -> () {
        //pre_assert
        self.TRK = self.TRK.domainSubstraction(&self.nxt.functionCall(&r).domain()).rangeSubstraction(&self.nxt.functionCall(&r).range())._union(&self.nxt.functionCall(&r)).clone().clone();

    }

    pub fn route_formation(&mut self, mut r: ROUTES) -> () {
        //pre_assert
        self.frm = self.frm._union(&BSet::new(vec![r.clone()])).clone().clone();

    }

    pub fn _tr_route_reservation(&mut self, is_caching: bool) -> BSet<ROUTES> {
        //transition
        if !is_caching || self._tr_cache_route_reservation.is_none() {
            let mut _ic_set_0: BSet<ROUTES> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_r_1 in self._ROUTES.difference(&self.resrt).clone().iter().cloned() {
                //parameter_combination_predicate
                if ((self.rtbl.inverse().relationImage(&BSet::new(vec![_ic_r_1.clone()])).intersect(&self.resbl).equal(&BSet::<BLOCKS>::new(vec![])) && BSet::<ROUTES>::new(vec![]).equal(&self.resrt.difference(&self.rsrtbl.range())))).booleanValue() {
                    _ic_set_0 = _ic_set_0._union(&BSet::new(vec![_ic_r_1]));
                }

            }
            self._tr_cache_route_reservation = Option::Some(_ic_set_0.clone());
            return _ic_set_0;
        } else {
            return self._tr_cache_route_reservation.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_route_freeing(&mut self, is_caching: bool) -> BSet<ROUTES> {
        //transition
        if !is_caching || self._tr_cache_route_freeing.is_none() {
            let mut _ic_set_1: BSet<ROUTES> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_r_1 in self.resrt.difference(&self.rsrtbl.range()).clone().iter().cloned() {
                //parameter_combination_predicate
                _ic_set_1 = _ic_set_1._union(&BSet::new(vec![_ic_r_1]));

            }
            self._tr_cache_route_freeing = Option::Some(_ic_set_1.clone());
            return _ic_set_1;
        } else {
            return self._tr_cache_route_freeing.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_FRONT_MOVE_1(&mut self, is_caching: bool) -> BSet<ROUTES> {
        //transition
        if !is_caching || self._tr_cache_FRONT_MOVE_1.is_none() {
            let mut _ic_set_2: BSet<ROUTES> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_r_1 in self.frm.clone().iter().cloned() {
                //parameter_combination_predicate
                if (((self.resbl.difference(&self.OCC).elementOf(&self.fst.functionCall(&_ic_r_1)) && _ic_r_1.equal(&self.rsrtbl.functionCall(&self.fst.functionCall(&_ic_r_1)))) && BSet::<ROUTES>::new(vec![]).equal(&self.resrt.difference(&self.rsrtbl.range())))).booleanValue() {
                    _ic_set_2 = _ic_set_2._union(&BSet::new(vec![_ic_r_1]));
                }

            }
            self._tr_cache_FRONT_MOVE_1 = Option::Some(_ic_set_2.clone());
            return _ic_set_2;
        } else {
            return self._tr_cache_FRONT_MOVE_1.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_FRONT_MOVE_2(&mut self, is_caching: bool) -> BSet<BLOCKS> {
        //transition
        if !is_caching || self._tr_cache_FRONT_MOVE_2.is_none() {
            let mut _ic_set_3: BSet<BLOCKS> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_b_1 in self.OCC.intersect(&self.TRK.domain()).clone().iter().cloned() {
                //parameter_combination_predicate
                if ((self.OCC.notElementOf(&self.TRK.functionCall(&_ic_b_1)) && BSet::<ROUTES>::new(vec![]).equal(&self.resrt.difference(&self.rsrtbl.range())))).booleanValue() {
                    _ic_set_3 = _ic_set_3._union(&BSet::new(vec![_ic_b_1]));
                }

            }
            self._tr_cache_FRONT_MOVE_2 = Option::Some(_ic_set_3.clone());
            return _ic_set_3;
        } else {
            return self._tr_cache_FRONT_MOVE_2.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_BACK_MOVE_1(&mut self, is_caching: bool) -> BSet<BLOCKS> {
        //transition
        if !is_caching || self._tr_cache_BACK_MOVE_1.is_none() {
            let mut _ic_set_4: BSet<BLOCKS> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_b_1 in self.LBT.difference(&self.TRK.domain()).clone().iter().cloned() {
                //parameter_combination_predicate
                if (BSet::<ROUTES>::new(vec![]).equal(&self.resrt.difference(&self.rsrtbl.range()))).booleanValue() {
                    _ic_set_4 = _ic_set_4._union(&BSet::new(vec![_ic_b_1]));
                }

            }
            self._tr_cache_BACK_MOVE_1 = Option::Some(_ic_set_4.clone());
            return _ic_set_4;
        } else {
            return self._tr_cache_BACK_MOVE_1.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_BACK_MOVE_2(&mut self, is_caching: bool) -> BSet<BLOCKS> {
        //transition
        if !is_caching || self._tr_cache_BACK_MOVE_2.is_none() {
            let mut _ic_set_5: BSet<BLOCKS> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_b_1 in self.LBT.intersect(&self.TRK.domain()).clone().iter().cloned() {
                //parameter_combination_predicate
                if ((self.OCC.elementOf(&self.TRK.functionCall(&_ic_b_1)) && BSet::<ROUTES>::new(vec![]).equal(&self.resrt.difference(&self.rsrtbl.range())))).booleanValue() {
                    _ic_set_5 = _ic_set_5._union(&BSet::new(vec![_ic_b_1]));
                }

            }
            self._tr_cache_BACK_MOVE_2 = Option::Some(_ic_set_5.clone());
            return _ic_set_5;
        } else {
            return self._tr_cache_BACK_MOVE_2.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_point_positionning(&mut self, is_caching: bool) -> BSet<ROUTES> {
        //transition
        if !is_caching || self._tr_cache_point_positionning.is_none() {
            let mut _ic_set_6: BSet<ROUTES> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_r_1 in self.resrt.difference(&self.frm).clone().iter().cloned() {
                //parameter_combination_predicate
                if (BSet::<ROUTES>::new(vec![]).equal(&self.resrt.difference(&self.rsrtbl.range()))).booleanValue() {
                    _ic_set_6 = _ic_set_6._union(&BSet::new(vec![_ic_r_1]));
                }

            }
            self._tr_cache_point_positionning = Option::Some(_ic_set_6.clone());
            return _ic_set_6;
        } else {
            return self._tr_cache_point_positionning.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_route_formation(&mut self, is_caching: bool) -> BSet<ROUTES> {
        //transition
        if !is_caching || self._tr_cache_route_formation.is_none() {
            let mut _ic_set_7: BSet<ROUTES> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_r_1 in self.resrt.difference(&self.frm).clone().iter().cloned() {
                //parameter_combination_predicate
                if ((self.nxt.functionCall(&_ic_r_1).domainRestriction(&self.rsrtbl.inverse().relationImage(&BSet::new(vec![_ic_r_1.clone()]))).equal(&self.TRK.domainRestriction(&self.rsrtbl.inverse().relationImage(&BSet::new(vec![_ic_r_1.clone()])))) && BSet::<ROUTES>::new(vec![]).equal(&self.resrt.difference(&self.rsrtbl.range())))).booleanValue() {
                    _ic_set_7 = _ic_set_7._union(&BSet::new(vec![_ic_r_1]));
                }

            }
            self._tr_cache_route_formation = Option::Some(_ic_set_7.clone());
            return _ic_set_7;
        } else {
            return self._tr_cache_route_formation.as_ref().unwrap().clone();
        }
    }

    pub fn _check_inv_1(&self) -> bool {
        //invariant
        return self._BLOCKS.check_domain_of(&self.TRK).and(&self._BLOCKS.check_range_of(&self.TRK)).and(&self.TRK.isFunction()).and(&self._BLOCKS.check_partial_of(&self.TRK)).and(&self.TRK.isInjection()).booleanValue();
    }

    pub fn _check_inv_2(&self) -> bool {
        //invariant
        //quantified_predicate
        let mut _ic_boolean_8 = BBoolean::new(true);
        for _ic_r_1 in self.resrt.difference(&self.frm).clone().iter().cloned() {
            {
                let mut _ic_a_1 = BSet::new(vec![_ic_r_1.clone()]);
                if !(self.rtbl.rangeRestriction(&_ic_a_1).equal(&self.rsrtbl.rangeRestriction(&_ic_a_1))).booleanValue() {
                    _ic_boolean_8 = BBoolean::new(false);
                    break;
                }

            }
        }

        return _ic_boolean_8.booleanValue();
    }

    pub fn _check_inv_3(&self) -> bool {
        //invariant
        //quantified_predicate
        let mut _ic_boolean_10 = BBoolean::new(true);
        for _ic_x_1 in self.TRK.domain().clone().iter().cloned() {
            for _ic_y_1 in self.TRK.relationImage(&BSet::new(vec![_ic_x_1.clone()])).clone().iter().cloned() {
                //quantified_predicate
                let mut _ic_boolean_9 = BBoolean::new(false);
                for _ic_r_1 in self._ROUTES.clone().iter().cloned() {
                    if (self.nxt.functionCall(&_ic_r_1).elementOf(&BTuple::from_refs(&_ic_x_1, &_ic_y_1))).booleanValue() {
                        _ic_boolean_9 = BBoolean::new(true);
                        break;
                    }

                }

                if !(_ic_boolean_9).booleanValue() {
                    _ic_boolean_10 = BBoolean::new(false);
                    break;
                }

            }
        }

        return _ic_boolean_10.booleanValue();
    }

    pub fn _check_inv_4(&self) -> bool {
        //invariant
        //quantified_predicate
        let mut _ic_boolean_11 = BBoolean::new(true);
        for _ic_r_1 in self.frm.clone().iter().cloned() {
            {
                let mut _ic_a_1 = self.rsrtbl.inverse().relationImage(&BSet::new(vec![_ic_r_1.clone()]));
                if !(self.nxt.functionCall(&_ic_r_1).domainRestriction(&_ic_a_1).equal(&self.TRK.domainRestriction(&_ic_a_1))).booleanValue() {
                    _ic_boolean_11 = BBoolean::new(false);
                    break;
                }

            }
        }

        return _ic_boolean_11.booleanValue();
    }

    pub fn _check_inv_5(&self) -> bool {
        //invariant
        return self.LBT.subset(&self.OCC).booleanValue();
    }

    pub fn _check_inv_6(&self) -> bool {
        //invariant
        //quantified_predicate
        let mut _ic_boolean_12 = BBoolean::new(true);
        for _ic_a_1 in self.rsrtbl.domain().clone().iter().cloned() {
            for _ic_b_1 in self.LBT.clone().iter().cloned() {
                {
                    let mut _ic_c_1 = self.rsrtbl.functionCall(&_ic_b_1);
                    {
                        let mut _ic_d_1 = self.nxt.functionCall(&_ic_c_1);
                        if !((_ic_d_1.range().elementOf(&_ic_b_1) && _ic_a_1.equal(&_ic_d_1.inverse().functionCall(&_ic_b_1))).implies(|| self.rsrtbl.functionCall(&_ic_a_1).unequal(&_ic_c_1).booleanValue())).booleanValue() {
                            _ic_boolean_12 = BBoolean::new(false);
                            break;
                        }

                    }
                }
            }
        }

        return _ic_boolean_12.booleanValue();
    }

    pub fn _check_inv_7(&self) -> bool {
        //invariant
        return self.resbl.check_domain_of(&self.rsrtbl).and(&self.resrt.check_range_of(&self.rsrtbl)).and(&self.rsrtbl.isFunction()).and(&self.resbl.check_total_of(&self.rsrtbl)).booleanValue();
    }

    pub fn _check_inv_8(&self) -> bool {
        //invariant
        return self.rsrtbl.subset(&self.rtbl).booleanValue();
    }

    pub fn _check_inv_9(&self) -> bool {
        //invariant
        return self.OCC.subset(&self.resbl).booleanValue();
    }

    pub fn _check_inv_10(&self) -> bool {
        //invariant
        //quantified_predicate
        let mut _ic_boolean_13 = BBoolean::new(true);
        for _ic_r_1 in self._ROUTES.clone().iter().cloned() {
            {
                let mut _ic_a_1 = self.nxt.functionCall(&_ic_r_1);
                {
                    let mut _ic_b_1 = self.rsrtbl.inverse().relationImage(&BSet::new(vec![_ic_r_1.clone()]));
                    {
                        let mut _ic_c_1 = _ic_b_1.difference(&self.OCC);
                        if !(((_ic_a_1.relationImage(&self.rtbl.inverse().relationImage(&BSet::new(vec![_ic_r_1.clone()])).difference(&_ic_b_1)).intersect(&_ic_c_1).equal(&BSet::<BLOCKS>::new(vec![])) && _ic_a_1.relationImage(&_ic_b_1).subset(&_ic_b_1)) && _ic_a_1.relationImage(&_ic_c_1).subset(&_ic_c_1))).booleanValue() {
                            _ic_boolean_13 = BBoolean::new(false);
                            break;
                        }

                    }
                }
            }
        }

        return _ic_boolean_13.booleanValue();
    }

    pub fn _check_inv_11(&self) -> bool {
        //invariant
        return self.frm.subset(&self.resrt).booleanValue();
    }

    pub fn _check_inv_12(&self) -> bool {
        //invariant
        return self.rsrtbl.relationImage(&self.OCC).subset(&self.frm).booleanValue();
    }

    fn invalidate_caches(&mut self, to_invalidate: Vec<&'static str>) {
        //calling the given functions without caching will recalculate them and cache them afterwards
        for trans in to_invalidate {
            match trans {
                "_tr_route_reservation" => {self._tr_route_reservation(false);},
                "_tr_route_freeing" => {self._tr_route_freeing(false);},
                "_tr_FRONT_MOVE_1" => {self._tr_FRONT_MOVE_1(false);},
                "_tr_FRONT_MOVE_2" => {self._tr_FRONT_MOVE_2(false);},
                "_tr_BACK_MOVE_1" => {self._tr_BACK_MOVE_1(false);},
                "_tr_BACK_MOVE_2" => {self._tr_BACK_MOVE_2(false);},
                "_tr_point_positionning" => {self._tr_point_positionning(false);},
                "_tr_route_formation" => {self._tr_route_formation(false);},
                _ => {},
            }
        }
    }

    //model_check_next_states
    fn generateNextStates(state: &mut Train1_Lukas_POR_v3,
                          isCaching: bool,
                          transitions: Arc<AtomicU64>) -> HashSet<(Train1_Lukas_POR_v3, &'static str)> {
        let mut result = HashSet::<(Train1_Lukas_POR_v3, &'static str)>::new();
        let mut evaluated_transitions: u64 = 0;
        //model_check_transition
        let mut _trid_1 = state._tr_route_reservation(isCaching);
        for param in _trid_1.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.route_reservation(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("route_reservation")); }
            result.insert((copiedState, "route_reservation"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_2 = state._tr_route_freeing(isCaching);
        for param in _trid_2.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.route_freeing(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("route_freeing")); }
            result.insert((copiedState, "route_freeing"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_3 = state._tr_FRONT_MOVE_1(isCaching);
        for param in _trid_3.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.FRONT_MOVE_1(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("FRONT_MOVE_1")); }
            result.insert((copiedState, "FRONT_MOVE_1"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_4 = state._tr_FRONT_MOVE_2(isCaching);
        for param in _trid_4.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.FRONT_MOVE_2(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("FRONT_MOVE_2")); }
            result.insert((copiedState, "FRONT_MOVE_2"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_5 = state._tr_BACK_MOVE_1(isCaching);
        for param in _trid_5.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.BACK_MOVE_1(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("BACK_MOVE_1")); }
            result.insert((copiedState, "BACK_MOVE_1"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_6 = state._tr_BACK_MOVE_2(isCaching);
        for param in _trid_6.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.BACK_MOVE_2(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("BACK_MOVE_2")); }
            result.insert((copiedState, "BACK_MOVE_2"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_7 = state._tr_point_positionning(isCaching);
        for param in _trid_7.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.point_positionning(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("point_positionning")); }
            result.insert((copiedState, "point_positionning"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_8 = state._tr_route_formation(isCaching);
        for param in _trid_8.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.route_formation(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("route_formation")); }
            result.insert((copiedState, "route_formation"));
            evaluated_transitions += 1;
        }


        transitions.fetch_add(evaluated_transitions, Ordering::AcqRel);
        return result;
    }

    //model_check_invariants
    pub fn checkInvariants(state: &Train1_Lukas_POR_v3, last_op: &'static str, isCaching: bool) -> bool {
        if isCaching {
            let dependent_invariants_of_state = Self::get_invariant_dependencies(last_op);
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_1") {
                if !state._check_inv_1() {
                    println!("_check_inv_1 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_2") {
                if !state._check_inv_2() {
                    println!("_check_inv_2 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_3") {
                if !state._check_inv_3() {
                    println!("_check_inv_3 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_4") {
                if !state._check_inv_4() {
                    println!("_check_inv_4 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_5") {
                if !state._check_inv_5() {
                    println!("_check_inv_5 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_6") {
                if !state._check_inv_6() {
                    println!("_check_inv_6 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_7") {
                if !state._check_inv_7() {
                    println!("_check_inv_7 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_8") {
                if !state._check_inv_8() {
                    println!("_check_inv_8 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_9") {
                if !state._check_inv_9() {
                    println!("_check_inv_9 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_10") {
                if !state._check_inv_10() {
                    println!("_check_inv_10 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_11") {
                if !state._check_inv_11() {
                    println!("_check_inv_11 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_12") {
                if !state._check_inv_12() {
                    println!("_check_inv_12 failed!");
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6() || !state._check_inv_7() || !state._check_inv_8() || !state._check_inv_9() || !state._check_inv_10() || !state._check_inv_11() || !state._check_inv_12());
    }

    //model_check_print
    fn print_result(states: usize, transitions: u64, error_detected: bool) {
        if !error_detected { println!("MODEL CHECKING SUCCESSFUL"); }
        println!("Number of States: {}", states);
        println!("Number of Transitions: {}", transitions);
    }

    //model_check_main
    fn next(collection_m: Arc<Mutex<LinkedList<(Train1_Lukas_POR_v3, &'static str)>>>, mc_type: MC_TYPE) -> (Train1_Lukas_POR_v3, &'static str) {
        let mut collection = collection_m.lock().unwrap();
        return match mc_type {
            MC_TYPE::BFS   => collection.pop_front().unwrap(),
            MC_TYPE::DFS   => collection.pop_back().unwrap(),
            MC_TYPE::MIXED => if collection.len() % 2 == 0 { collection.pop_front().unwrap() } else { collection.pop_back().unwrap() }
        };
    }

    fn get_guard_dependencies(op: &'static str) -> Vec<&str> {
        return match op {
            //model_check_init_static
            "point_positionning" => vec!["_tr_route_formation", "_tr_BACK_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"],
            //model_check_init_static
            "route_reservation" => vec!["_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"],
            //model_check_init_static
            "FRONT_MOVE_1" => vec!["_tr_FRONT_MOVE_1", "_tr_BACK_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"],
            //model_check_init_static
            "BACK_MOVE_1" => vec!["_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"],
            //model_check_init_static
            "FRONT_MOVE_2" => vec!["_tr_FRONT_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"],
            //model_check_init_static
            "route_formation" => vec!["_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_point_positionning"],
            //model_check_init_static
            "route_freeing" => vec!["_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"],
            //model_check_init_static
            "BACK_MOVE_2" => vec!["_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"],
            _ => vec![],
        }
    }

    fn get_invariant_dependencies(op: &'static str) -> Vec<&str> {
        return match op {
            //model_check_init_static
            "point_positionning" => vec!["_check_inv_3", "_check_inv_1", "_check_inv_4"],
            //model_check_init_static
            "route_reservation" => vec!["_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_8", "_check_inv_12", "_check_inv_9", "_check_inv_11"],
            //model_check_init_static
            "FRONT_MOVE_1" => vec!["_check_inv_6", "_check_inv_10", "_check_inv_5", "_check_inv_12", "_check_inv_9"],
            //model_check_init_static
            "BACK_MOVE_1" => vec!["_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_5", "_check_inv_8", "_check_inv_12", "_check_inv_9"],
            //model_check_init_static
            "FRONT_MOVE_2" => vec!["_check_inv_10", "_check_inv_5", "_check_inv_12", "_check_inv_9"],
            //model_check_init_static
            "route_formation" => vec!["_check_inv_2", "_check_inv_4", "_check_inv_12", "_check_inv_11"],
            //model_check_init_static
            "route_freeing" => vec!["_check_inv_2", "_check_inv_7", "_check_inv_4", "_check_inv_12", "_check_inv_11"],
            //model_check_init_static
            "BACK_MOVE_2" => vec!["_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_5", "_check_inv_8", "_check_inv_12", "_check_inv_9"],
            _ => vec![],
        }
    }

    fn model_check_single_threaded(mc_type: MC_TYPE, is_caching: bool, no_dead: bool, no_inv: bool) {
        let mut machine = Train1_Lukas_POR_v3::new();

        let mut all_states = HashSet::<Train1_Lukas_POR_v3>::new();
        all_states.insert(machine.clone());

        let states_to_process_mutex = Arc::new(Mutex::new(LinkedList::<(Train1_Lukas_POR_v3, &'static str)>::new()));
        states_to_process_mutex.lock().unwrap().push_back((machine.clone(), ""));

        let num_transitions = Arc::new(AtomicU64::new(0));

        let mut stop_threads = false;

        while !stop_threads && !states_to_process_mutex.lock().unwrap().is_empty() {
            let (mut state, last_op) = Self::next(Arc::clone(&states_to_process_mutex), mc_type);

            let next_states = Self::generateNextStates(&mut state, is_caching, Arc::clone(&num_transitions));

            if !no_inv && !Self::checkInvariants(&state, last_op, is_caching) {
                println!("INVARIANT VIOLATED");
                stop_threads = true;
            }
            if !no_dead && next_states.is_empty() {
                print!("DEADLOCK DETECTED");
                stop_threads = true;
            }

            next_states.into_iter()
                       .filter(|(next_state, _)| all_states.insert((*next_state).clone()))
                       .for_each(|(next_state, last_op)| states_to_process_mutex.lock().unwrap().push_back((next_state, last_op)));

            if all_states.len() % 50000 == 0 {
                println!("VISITED STATES: {}", all_states.len());
                println!("EVALUATED TRANSITIONS: {}", num_transitions.load(Ordering::Acquire));
                println!("-------------------");
            }
        }
        Self::print_result(all_states.len(), num_transitions.load(Ordering::Acquire), stop_threads);
    }

    fn modelCheckMultiThreaded(mc_type: MC_TYPE, threads: usize, is_caching: bool, no_dead: bool, no_inv: bool) {
        let threadPool = ThreadPool::new(threads);

        let machine = Train1_Lukas_POR_v3::new();

        let all_states = Arc::new(DashSet::<Train1_Lukas_POR_v3>::new());
        all_states.insert(machine.clone());

        let states_to_process_mutex = Arc::new(Mutex::new(LinkedList::<(Train1_Lukas_POR_v3, &'static str)>::new()));
        states_to_process_mutex.lock().unwrap().push_back((machine, ""));

        let num_transitions = Arc::new(AtomicU64::new(0));

        let mut stop_threads = false;
        let mut spawned_tasks: u64 = 0;
        let mut finished_tasks: u64 = 0;

        let (tx, rx) = channel();
        //println!("Thread {:?} starting threads", thread::current().id());
        while !stop_threads && !states_to_process_mutex.lock().unwrap().is_empty() {
            let (mut state, last_op) = Self::next(Arc::clone(&states_to_process_mutex), mc_type);

            let states_to_process = Arc::clone(&states_to_process_mutex);
            let transitions = Arc::clone(&num_transitions);
            let states = Arc::clone(&all_states);
            let tx = tx.clone();
            //println!("Thread {:?} spawning a thread", thread::current().id());
            threadPool.execute(move|| {
                let next_states = Self::generateNextStates(&mut state, is_caching, transitions);
                if !no_dead && next_states.is_empty() { let _ = tx.send(Err("DEADLOCK DETECTED")); }

                //println!("Thread {:?} executing", thread::current().id());
                next_states.into_iter()
                           .filter(|(next_state, _)| states.insert((*next_state).clone()))
                           .for_each(|(next_state, last_op)| states_to_process.lock().unwrap().push_back((next_state, last_op)));

                if !no_inv && !Self::checkInvariants(&state, last_op, is_caching) {
                    let _ = tx.send(Err("INVARIANT VIOLATED"));
                }
                //println!("Thread {:?} done", thread::current().id());
                let _ = tx.send(Ok(1));
            });

            spawned_tasks += 1;
            if spawned_tasks % 50000 == 0 {
                println!("VISITED STATES: {}", all_states.len());
                println!("EVALUATED TRANSITIONS: {}", num_transitions.load(Ordering::Acquire));
                println!("-------------------");
            }

            while states_to_process_mutex.lock().unwrap().is_empty() && spawned_tasks - finished_tasks > 0 {
                //println!("Thread {:?} (main) waiting for a thread to finish", thread::current().id());
                match rx.try_recv() {
                    Ok(val)  => match val {
                            Ok(_) => finished_tasks += 1,
                            Err(msg) => { println!("{}", msg); stop_threads = true; },
                        },
                    Err(_) => (),
                }
                if threadPool.panic_count() > 0 { stop_threads = true; }
            }
        }

        Self::print_result(all_states.len(), num_transitions.load(Ordering::Acquire), stop_threads);
    }

}


fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() < 4 { panic!("Number of arguments errorneous"); }

    let threads = args.get(2).unwrap().parse::<usize>().unwrap();
    if threads <= 0 { panic!("Input for number of threads is wrong."); }

    let is_caching = args.get(3).unwrap().parse::<bool>().unwrap();
    let mc_type = match args.get(1).unwrap().as_str() {
        "mixed" => MC_TYPE::MIXED,
        "bf" => MC_TYPE::BFS,
        "df" => MC_TYPE::DFS,
        _    => panic!("Input for strategy is wrong.")
    };

    let mut no_dead = false;
    let mut no_inv = false;

    if args.len() > 4 {
        for arg in args.iter().skip(4) {
            match arg.as_str() {
                "-nodead" => no_dead = true,
                "-noinv" => no_inv = true,
                _ => {}
            }
        }
    }

    if threads == 1 {
        Train1_Lukas_POR_v3::model_check_single_threaded(mc_type, is_caching, no_dead, no_inv);
    } else {
        Train1_Lukas_POR_v3::modelCheckMultiThreaded(mc_type, threads, is_caching, no_dead, no_inv);
    }
}
