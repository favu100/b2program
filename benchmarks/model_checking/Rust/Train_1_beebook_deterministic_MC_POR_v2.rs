#![ allow( dead_code, unused_imports, unused_mut, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::env;
use std::sync::atomic::{AtomicI32, AtomicI64, AtomicBool, Ordering};
use std::sync::{Arc, Mutex};
use std::thread;
use std::collections::{HashMap, HashSet, LinkedList};
use im::HashMap as PersistentHashMap;
use threadpool::ThreadPool;
use std::sync::mpsc::channel;
use derivative::Derivative;
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
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
    I, 
    J, 
    K, 
    L, 
    M, 
    N
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
           BLOCKS::J => write!(f, "J"),
           BLOCKS::K => write!(f, "K"),
           BLOCKS::L => write!(f, "L"),
           BLOCKS::M => write!(f, "M"),
           BLOCKS::N => write!(f, "N"),
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
    R8, 
    R9, 
    R10
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
           ROUTES::R9 => write!(f, "R9"),
           ROUTES::R10 => write!(f, "R10"),
       }
    }
}

#[derive(Derivative)]
#[derivative(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct Train_1_beebook_deterministic_MC_POR_v2 {
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

impl Train_1_beebook_deterministic_MC_POR_v2 {

    pub fn new() -> Train_1_beebook_deterministic_MC_POR_v2 {
        //values: ''
        let mut m: Train_1_beebook_deterministic_MC_POR_v2 = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.nxt = BRelation::new(vec![BTuple::from_refs(&ROUTES::R1, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::L, &BLOCKS::A), BTuple::from_refs(&BLOCKS::A, &BLOCKS::B), BTuple::from_refs(&BLOCKS::B, &BLOCKS::C)])), BTuple::from_refs(&ROUTES::R2, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::L, &BLOCKS::A), BTuple::from_refs(&BLOCKS::A, &BLOCKS::B), BTuple::from_refs(&BLOCKS::B, &BLOCKS::D), BTuple::from_refs(&BLOCKS::D, &BLOCKS::E), BTuple::from_refs(&BLOCKS::E, &BLOCKS::F), BTuple::from_refs(&BLOCKS::F, &BLOCKS::G)])), BTuple::from_refs(&ROUTES::R3, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::L, &BLOCKS::A), BTuple::from_refs(&BLOCKS::A, &BLOCKS::B), BTuple::from_refs(&BLOCKS::B, &BLOCKS::D), BTuple::from_refs(&BLOCKS::D, &BLOCKS::K), BTuple::from_refs(&BLOCKS::K, &BLOCKS::J), BTuple::from_refs(&BLOCKS::J, &BLOCKS::N)])), BTuple::from_refs(&ROUTES::R4, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::M, &BLOCKS::H), BTuple::from_refs(&BLOCKS::H, &BLOCKS::I), BTuple::from_refs(&BLOCKS::I, &BLOCKS::K), BTuple::from_refs(&BLOCKS::K, &BLOCKS::F), BTuple::from_refs(&BLOCKS::F, &BLOCKS::G)])), BTuple::from_refs(&ROUTES::R5, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::M, &BLOCKS::H), BTuple::from_refs(&BLOCKS::H, &BLOCKS::I), BTuple::from_refs(&BLOCKS::I, &BLOCKS::J), BTuple::from_refs(&BLOCKS::J, &BLOCKS::N)])), BTuple::from_refs(&ROUTES::R6, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::C, &BLOCKS::B), BTuple::from_refs(&BLOCKS::B, &BLOCKS::A), BTuple::from_refs(&BLOCKS::A, &BLOCKS::L)])), BTuple::from_refs(&ROUTES::R7, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::G, &BLOCKS::F), BTuple::from_refs(&BLOCKS::F, &BLOCKS::E), BTuple::from_refs(&BLOCKS::E, &BLOCKS::D), BTuple::from_refs(&BLOCKS::D, &BLOCKS::B), BTuple::from_refs(&BLOCKS::B, &BLOCKS::A), BTuple::from_refs(&BLOCKS::A, &BLOCKS::L)])), BTuple::from_refs(&ROUTES::R8, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::N, &BLOCKS::J), BTuple::from_refs(&BLOCKS::J, &BLOCKS::K), BTuple::from_refs(&BLOCKS::K, &BLOCKS::D), BTuple::from_refs(&BLOCKS::D, &BLOCKS::B), BTuple::from_refs(&BLOCKS::B, &BLOCKS::A), BTuple::from_refs(&BLOCKS::A, &BLOCKS::L)])), BTuple::from_refs(&ROUTES::R9, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::G, &BLOCKS::F), BTuple::from_refs(&BLOCKS::F, &BLOCKS::K), BTuple::from_refs(&BLOCKS::K, &BLOCKS::I), BTuple::from_refs(&BLOCKS::I, &BLOCKS::H), BTuple::from_refs(&BLOCKS::H, &BLOCKS::M)])), BTuple::from_refs(&ROUTES::R10, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::N, &BLOCKS::J), BTuple::from_refs(&BLOCKS::J, &BLOCKS::I), BTuple::from_refs(&BLOCKS::I, &BLOCKS::H), BTuple::from_refs(&BLOCKS::H, &BLOCKS::M)]))]);
        self.fst = BRelation::new(vec![BTuple::from_refs(&ROUTES::R1, &BLOCKS::L), BTuple::from_refs(&ROUTES::R2, &BLOCKS::L), BTuple::from_refs(&ROUTES::R3, &BLOCKS::L), BTuple::from_refs(&ROUTES::R4, &BLOCKS::M), BTuple::from_refs(&ROUTES::R5, &BLOCKS::M), BTuple::from_refs(&ROUTES::R6, &BLOCKS::C), BTuple::from_refs(&ROUTES::R7, &BLOCKS::G), BTuple::from_refs(&ROUTES::R8, &BLOCKS::N), BTuple::from_refs(&ROUTES::R9, &BLOCKS::G), BTuple::from_refs(&ROUTES::R10, &BLOCKS::N)]);
        self.lst = BRelation::new(vec![BTuple::from_refs(&ROUTES::R1, &BLOCKS::C), BTuple::from_refs(&ROUTES::R2, &BLOCKS::G), BTuple::from_refs(&ROUTES::R3, &BLOCKS::N), BTuple::from_refs(&ROUTES::R4, &BLOCKS::G), BTuple::from_refs(&ROUTES::R5, &BLOCKS::N), BTuple::from_refs(&ROUTES::R6, &BLOCKS::L), BTuple::from_refs(&ROUTES::R7, &BLOCKS::L), BTuple::from_refs(&ROUTES::R8, &BLOCKS::L), BTuple::from_refs(&ROUTES::R9, &BLOCKS::M), BTuple::from_refs(&ROUTES::R10, &BLOCKS::M)]);
        let mut _ic_set_0 = BRelation::<BLOCKS, ROUTES>::new(vec![]);
        for _ic_b_1 in self._BLOCKS.clone().iter().cloned() {
            for _ic_r_1 in self._ROUTES.clone().iter().cloned() {
                if (self.nxt.domain().elementOf(&_ic_r_1).and(&self.nxt.functionCall(&_ic_r_1).domain().elementOf(&_ic_b_1).or(&self.nxt.functionCall(&_ic_r_1).range().elementOf(&_ic_b_1)))).booleanValue() {
                    _ic_set_0 = _ic_set_0._union(&BRelation::<BLOCKS, ROUTES>::new(vec![BTuple::from_refs(&_ic_b_1, &_ic_r_1)]));
                }

            }
        }
        self.rtbl = _ic_set_0;
        self._BLOCKS = BSet::new(vec![BLOCKS::A, BLOCKS::B, BLOCKS::C, BLOCKS::D, BLOCKS::E, BLOCKS::F, BLOCKS::G, BLOCKS::H, BLOCKS::I, BLOCKS::J, BLOCKS::K, BLOCKS::L, BLOCKS::M, BLOCKS::N]);
        self._ROUTES = BSet::new(vec![ROUTES::R1, ROUTES::R2, ROUTES::R3, ROUTES::R4, ROUTES::R5, ROUTES::R6, ROUTES::R7, ROUTES::R8, ROUTES::R9, ROUTES::R10]);
        self.resrt = BSet::new(vec![]).clone().clone();
        self.resbl = BSet::new(vec![]).clone().clone();
        self.rsrtbl = BRelation::new(vec![]).clone().clone();
        self.OCC = BSet::new(vec![]).clone().clone();
        self.TRK = BRelation::new(vec![]).clone().clone();
        self.frm = BSet::new(vec![]).clone().clone();
        self.LBT = BSet::new(vec![]).clone().clone();
    }

    pub fn get_fst(&self) -> BRelation<ROUTES, BLOCKS> {
        return self.fst.clone();
    }

    pub fn get_lst(&self) -> BRelation<ROUTES, BLOCKS> {
        return self.lst.clone();
    }

    pub fn get_nxt(&self) -> BRelation<ROUTES, BRelation<BLOCKS, BLOCKS>> {
        return self.nxt.clone();
    }

    pub fn get_rtbl(&self) -> BRelation<BLOCKS, ROUTES> {
        return self.rtbl.clone();
    }

    pub fn get_LBT(&self) -> BSet<BLOCKS> {
        return self.LBT.clone();
    }

    pub fn get_TRK(&self) -> BRelation<BLOCKS, BLOCKS> {
        return self.TRK.clone();
    }

    pub fn get_frm(&self) -> BSet<ROUTES> {
        return self.frm.clone();
    }

    pub fn get_OCC(&self) -> BSet<BLOCKS> {
        return self.OCC.clone();
    }

    pub fn get_resbl(&self) -> BSet<BLOCKS> {
        return self.resbl.clone();
    }

    pub fn get_resrt(&self) -> BSet<ROUTES> {
        return self.resrt.clone();
    }

    pub fn get_rsrtbl(&self) -> BRelation<BLOCKS, ROUTES> {
        return self.rsrtbl.clone();
    }

    pub fn get__BLOCKS(&self) -> BSet<BLOCKS> {
        return self._BLOCKS.clone();
    }

    pub fn get__ROUTES(&self) -> BSet<ROUTES> {
        return self._ROUTES.clone();
    }

    pub fn route_reservation(&mut self, mut r: ROUTES) -> () {
        //pre_assert
        let mut _ld_resrt = self.resrt.clone();
        let mut _ld_rsrtbl = self.rsrtbl.clone();
        let mut _ld_resbl = self.resbl.clone();
        self.resrt = _ld_resrt._union(&BSet::new(vec![r])).clone().clone();
        self.rsrtbl = _ld_rsrtbl._union(&self.rtbl.rangeRestriction(&BSet::new(vec![r]))).clone().clone();
        self.resbl = _ld_resbl._union(&self.rtbl.inverse().relationImage(&BSet::new(vec![r]))).clone().clone();

    }

    pub fn route_freeing(&mut self, mut r: ROUTES) -> () {
        //pre_assert
        let mut _ld_frm = self.frm.clone();
        let mut _ld_resrt = self.resrt.clone();
        self.resrt = _ld_resrt.difference(&BSet::new(vec![r])).clone().clone();
        self.frm = _ld_frm.difference(&BSet::new(vec![r])).clone().clone();

    }

    pub fn FRONT_MOVE_1(&mut self, mut r: ROUTES) -> () {
        //pre_assert
        let mut _ld_OCC = self.OCC.clone();
        let mut _ld_LBT = self.LBT.clone();
        self.OCC = _ld_OCC._union(&BSet::new(vec![self.fst.functionCall(&r)])).clone().clone();
        self.LBT = _ld_LBT._union(&BSet::new(vec![self.fst.functionCall(&r)])).clone().clone();

    }

    pub fn FRONT_MOVE_2(&mut self, mut b: BLOCKS) -> () {
        //pre_assert
        self.OCC = self.OCC._union(&BSet::new(vec![self.TRK.functionCall(&b)])).clone().clone();

    }

    pub fn BACK_MOVE_1(&mut self, mut b: BLOCKS) -> () {
        //pre_assert
        let mut _ld_rsrtbl = self.rsrtbl.clone();
        let mut _ld_resbl = self.resbl.clone();
        let mut _ld_OCC = self.OCC.clone();
        let mut _ld_LBT = self.LBT.clone();
        self.OCC = _ld_OCC.difference(&BSet::new(vec![b])).clone().clone();
        self.rsrtbl = _ld_rsrtbl.domainSubstraction(&BSet::new(vec![b])).clone().clone();
        self.resbl = _ld_resbl.difference(&BSet::new(vec![b])).clone().clone();
        self.LBT = _ld_LBT.difference(&BSet::new(vec![b])).clone().clone();

    }

    pub fn BACK_MOVE_2(&mut self, mut b: BLOCKS) -> () {
        //pre_assert
        let mut _ld_rsrtbl = self.rsrtbl.clone();
        let mut _ld_resbl = self.resbl.clone();
        let mut _ld_OCC = self.OCC.clone();
        let mut _ld_LBT = self.LBT.clone();
        self.OCC = _ld_OCC.difference(&BSet::new(vec![b])).clone().clone();
        self.rsrtbl = _ld_rsrtbl.domainSubstraction(&BSet::new(vec![b])).clone().clone();
        self.resbl = _ld_resbl.difference(&BSet::new(vec![b])).clone().clone();
        self.LBT = _ld_LBT.difference(&BSet::new(vec![b]))._union(&BSet::new(vec![self.TRK.functionCall(&b)])).clone().clone();

    }

    pub fn point_positionning(&mut self, mut r: ROUTES) -> () {
        //pre_assert
        self.TRK = self.TRK.domainSubstraction(&self.nxt.functionCall(&r).domain()).rangeSubstraction(&self.nxt.functionCall(&r).range())._union(&self.nxt.functionCall(&r)).clone().clone();

    }

    pub fn route_formation(&mut self, mut r: ROUTES) -> () {
        //pre_assert
        self.frm = self.frm._union(&BSet::new(vec![r])).clone().clone();

    }

    pub fn _tr_route_reservation(&mut self, is_caching: bool) -> BSet<ROUTES> {
        //transition
        if !is_caching || self._tr_cache_route_reservation.is_none() {
            let mut _ic_set_1: BSet<ROUTES> = BSet::new(vec![]);
            for _ic_r_1 in self._ROUTES.difference(&self.resrt).clone().iter().cloned() {
                if (self.rtbl.inverse().relationImage(&BSet::new(vec![_ic_r_1])).intersect(&self.resbl).equal(&BSet::new(vec![])).and(&BSet::new(vec![]).equal(&self.resrt.difference(&self.rsrtbl.range())))).booleanValue() {
                    _ic_set_1 = _ic_set_1._union(&BSet::new(vec![_ic_r_1]));
                }

            }
            self._tr_cache_route_reservation = Option::Some(_ic_set_1.clone());
            return _ic_set_1;
        } else {
            return self._tr_cache_route_reservation.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_route_freeing(&mut self, is_caching: bool) -> BSet<ROUTES> {
        //transition
        if !is_caching || self._tr_cache_route_freeing.is_none() {
            let mut _ic_set_2: BSet<ROUTES> = BSet::new(vec![]);
            for _ic_r_1 in self.resrt.difference(&self.rsrtbl.range()).clone().iter().cloned() {
                _ic_set_2 = _ic_set_2._union(&BSet::new(vec![_ic_r_1]));

            }
            self._tr_cache_route_freeing = Option::Some(_ic_set_2.clone());
            return _ic_set_2;
        } else {
            return self._tr_cache_route_freeing.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_FRONT_MOVE_1(&mut self, is_caching: bool) -> BSet<ROUTES> {
        //transition
        if !is_caching || self._tr_cache_FRONT_MOVE_1.is_none() {
            let mut _ic_set_3: BSet<ROUTES> = BSet::new(vec![]);
            for _ic_r_1 in self.frm.clone().iter().cloned() {
                if (self.resbl.difference(&self.OCC).elementOf(&self.fst.functionCall(&_ic_r_1)).and(&_ic_r_1.equal(&self.rsrtbl.functionCall(&self.fst.functionCall(&_ic_r_1)))).and(&BSet::new(vec![]).equal(&self.resrt.difference(&self.rsrtbl.range())))).booleanValue() {
                    _ic_set_3 = _ic_set_3._union(&BSet::new(vec![_ic_r_1]));
                }

            }
            self._tr_cache_FRONT_MOVE_1 = Option::Some(_ic_set_3.clone());
            return _ic_set_3;
        } else {
            return self._tr_cache_FRONT_MOVE_1.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_FRONT_MOVE_2(&mut self, is_caching: bool) -> BSet<BLOCKS> {
        //transition
        if !is_caching || self._tr_cache_FRONT_MOVE_2.is_none() {
            let mut _ic_set_4: BSet<BLOCKS> = BSet::new(vec![]);
            for _ic_b_1 in self.OCC.intersect(&self.TRK.domain()).clone().iter().cloned() {
                if (self.OCC.notElementOf(&self.TRK.functionCall(&_ic_b_1))).booleanValue() {
                    _ic_set_4 = _ic_set_4._union(&BSet::new(vec![_ic_b_1]));
                }

            }
            self._tr_cache_FRONT_MOVE_2 = Option::Some(_ic_set_4.clone());
            return _ic_set_4;
        } else {
            return self._tr_cache_FRONT_MOVE_2.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_BACK_MOVE_1(&mut self, is_caching: bool) -> BSet<BLOCKS> {
        //transition
        if !is_caching || self._tr_cache_BACK_MOVE_1.is_none() {
            let mut _ic_set_5: BSet<BLOCKS> = BSet::new(vec![]);
            for _ic_b_1 in self.LBT.difference(&self.TRK.domain()).clone().iter().cloned() {
                if (BSet::new(vec![]).equal(&self.resrt.difference(&self.rsrtbl.range()))).booleanValue() {
                    _ic_set_5 = _ic_set_5._union(&BSet::new(vec![_ic_b_1]));
                }

            }
            self._tr_cache_BACK_MOVE_1 = Option::Some(_ic_set_5.clone());
            return _ic_set_5;
        } else {
            return self._tr_cache_BACK_MOVE_1.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_BACK_MOVE_2(&mut self, is_caching: bool) -> BSet<BLOCKS> {
        //transition
        if !is_caching || self._tr_cache_BACK_MOVE_2.is_none() {
            let mut _ic_set_6: BSet<BLOCKS> = BSet::new(vec![]);
            for _ic_b_1 in self.LBT.intersect(&self.TRK.domain()).clone().iter().cloned() {
                if (self.OCC.elementOf(&self.TRK.functionCall(&_ic_b_1)).and(&BSet::new(vec![]).equal(&self.resrt.difference(&self.rsrtbl.range())))).booleanValue() {
                    _ic_set_6 = _ic_set_6._union(&BSet::new(vec![_ic_b_1]));
                }

            }
            self._tr_cache_BACK_MOVE_2 = Option::Some(_ic_set_6.clone());
            return _ic_set_6;
        } else {
            return self._tr_cache_BACK_MOVE_2.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_point_positionning(&mut self, is_caching: bool) -> BSet<ROUTES> {
        //transition
        if !is_caching || self._tr_cache_point_positionning.is_none() {
            let mut _ic_set_7: BSet<ROUTES> = BSet::new(vec![]);
            for _ic_r_1 in self.resrt.difference(&self.frm).clone().iter().cloned() {
                if (BSet::new(vec![]).equal(&self.resrt.difference(&self.rsrtbl.range()))).booleanValue() {
                    _ic_set_7 = _ic_set_7._union(&BSet::new(vec![_ic_r_1]));
                }

            }
            self._tr_cache_point_positionning = Option::Some(_ic_set_7.clone());
            return _ic_set_7;
        } else {
            return self._tr_cache_point_positionning.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_route_formation(&mut self, is_caching: bool) -> BSet<ROUTES> {
        //transition
        if !is_caching || self._tr_cache_route_formation.is_none() {
            let mut _ic_set_8: BSet<ROUTES> = BSet::new(vec![]);
            for _ic_r_1 in self.resrt.difference(&self.frm).clone().iter().cloned() {
                if (self.nxt.functionCall(&_ic_r_1).domainRestriction(&self.rsrtbl.inverse().relationImage(&BSet::new(vec![_ic_r_1]))).equal(&self.TRK.domainRestriction(&self.rsrtbl.inverse().relationImage(&BSet::new(vec![_ic_r_1])))).and(&BSet::new(vec![]).equal(&self.resrt.difference(&self.rsrtbl.range())))).booleanValue() {
                    _ic_set_8 = _ic_set_8._union(&BSet::new(vec![_ic_r_1]));
                }

            }
            self._tr_cache_route_formation = Option::Some(_ic_set_8.clone());
            return _ic_set_8;
        } else {
            return self._tr_cache_route_formation.as_ref().unwrap().clone();
        }
    }

    pub fn _check_inv_1(&self) -> bool {
        //invariant
        return self.TRK.checkDomain(&self._BLOCKS).and(&self.TRK.checkRange(&self._BLOCKS)).and(&self.TRK.isFunction()).and(&self.TRK.isPartial(&self._BLOCKS)).and(&self.TRK.isInjection()).booleanValue();
    }

    pub fn _check_inv_2(&self) -> bool {
        //invariant
        let mut _ic_boolean_9 = BBoolean::new(true);
        for _ic_r_1 in self.resrt.difference(&self.frm).clone().iter().cloned() {
            {
                let mut _ic_a_1 = BSet::new(vec![_ic_r_1]);
                if !(self.rtbl.rangeRestriction(&_ic_a_1).equal(&self.rsrtbl.rangeRestriction(&_ic_a_1))).booleanValue() {
                    _ic_boolean_9 = BBoolean::new(false);
                    break;
                }

            }
        }
        return _ic_boolean_9.booleanValue();
    }

    pub fn _check_inv_3(&self) -> bool {
        //invariant
        let mut _ic_boolean_11 = BBoolean::new(true);
        for _ic_x_1 in self.TRK.domain().clone().iter().cloned() {
            for _ic_y_1 in self.TRK.relationImage(&BSet::new(vec![_ic_x_1])).clone().iter().cloned() {
                let mut _ic_boolean_10 = BBoolean::new(false);
                for _ic_r_1 in self._ROUTES.clone().iter().cloned() {
                    if (self.nxt.functionCall(&_ic_r_1).elementOf(&BTuple::from_refs(&_ic_x_1, &_ic_y_1))).booleanValue() {
                        _ic_boolean_10 = BBoolean::new(true);
                        break;
                    }

                }
                if !(_ic_boolean_10).booleanValue() {
                    _ic_boolean_11 = BBoolean::new(false);
                    break;
                }

            }
        }
        return _ic_boolean_11.booleanValue();
    }

    pub fn _check_inv_4(&self) -> bool {
        //invariant
        let mut _ic_boolean_12 = BBoolean::new(true);
        for _ic_r_1 in self.frm.clone().iter().cloned() {
            {
                let mut _ic_a_1 = self.rsrtbl.inverse().relationImage(&BSet::new(vec![_ic_r_1]));
                if !(self.nxt.functionCall(&_ic_r_1).domainRestriction(&_ic_a_1).equal(&self.TRK.domainRestriction(&_ic_a_1))).booleanValue() {
                    _ic_boolean_12 = BBoolean::new(false);
                    break;
                }

            }
        }
        return _ic_boolean_12.booleanValue();
    }

    pub fn _check_inv_5(&self) -> bool {
        //invariant
        return self.LBT.subset(&self.OCC).booleanValue();
    }

    pub fn _check_inv_6(&self) -> bool {
        //invariant
        let mut _ic_boolean_13 = BBoolean::new(true);
        for _ic_a_1 in self.rsrtbl.domain().clone().iter().cloned() {
            for _ic_b_1 in self.LBT.clone().iter().cloned() {
                {
                    let mut _ic_c_1 = self.rsrtbl.functionCall(&_ic_b_1);
                    {
                        let mut _ic_d_1 = self.nxt.functionCall(&_ic_c_1);
                        if !(_ic_d_1.range().elementOf(&_ic_b_1).and(&_ic_a_1.equal(&_ic_d_1.inverse().functionCall(&_ic_b_1))).implies(&self.rsrtbl.functionCall(&_ic_a_1).unequal(&_ic_c_1))).booleanValue() {
                            _ic_boolean_13 = BBoolean::new(false);
                            break;
                        }

                    }
                }
            }
        }
        return _ic_boolean_13.booleanValue();
    }

    pub fn _check_inv_7(&self) -> bool {
        //invariant
        return self.rsrtbl.checkDomain(&self.resbl).and(&self.rsrtbl.checkRange(&self.resrt)).and(&self.rsrtbl.isFunction()).and(&self.rsrtbl.isTotal(&self.resbl)).booleanValue();
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
        let mut _ic_boolean_14 = BBoolean::new(true);
        for _ic_r_1 in self._ROUTES.clone().iter().cloned() {
            {
                let mut _ic_a_1 = self.nxt.functionCall(&_ic_r_1);
                {
                    let mut _ic_b_1 = self.rsrtbl.inverse().relationImage(&BSet::new(vec![_ic_r_1]));
                    {
                        let mut _ic_c_1 = _ic_b_1.difference(&self.OCC);
                        if !(_ic_a_1.relationImage(&self.rtbl.inverse().relationImage(&BSet::new(vec![_ic_r_1])).difference(&_ic_b_1)).intersect(&_ic_c_1).equal(&BSet::new(vec![])).and(&_ic_a_1.relationImage(&_ic_b_1).subset(&_ic_b_1)).and(&_ic_a_1.relationImage(&_ic_c_1).subset(&_ic_c_1))).booleanValue() {
                            _ic_boolean_14 = BBoolean::new(false);
                            break;
                        }

                    }
                }
            }
        }
        return _ic_boolean_14.booleanValue();
    }

    pub fn _check_inv_11(&self) -> bool {
        //invariant
        return self.frm.subset(&self.resrt).booleanValue();
    }

    pub fn _check_inv_12(&self) -> bool {
        //invariant
        return self.rsrtbl.relationImage(&self.OCC).subset(&self.frm).booleanValue();
    }

    fn invalidate_caches(&mut self, to_invalidate: &HashSet<&'static str>) {
        //calling the given functions without caching will recalculate them and cache them afterwards
        //if caching is enabled globally, this will just prefill those, if caching is
        for trans in to_invalidate.iter() {
            match *trans {
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
    fn generateNextStates(state: &mut Train_1_beebook_deterministic_MC_POR_v2,
                          isCaching: bool,
                          invariant_dependency: &HashMap<&str, HashSet<&'static str>>,
                          dependent_invariant_m: Arc<Mutex<HashMap<Train_1_beebook_deterministic_MC_POR_v2, HashSet<&str>>>>,
                          guard_dependency: &HashMap<&str, HashSet<&'static str>>,
                          dependent_guard_m: Arc<Mutex<HashMap<Train_1_beebook_deterministic_MC_POR_v2, HashSet<&str>>>>,
                          guardCache: Arc<Mutex<HashMap<Train_1_beebook_deterministic_MC_POR_v2, PersistentHashMap<&str, bool>>>>,
                          parents_m: Arc<Mutex<HashMap<Train_1_beebook_deterministic_MC_POR_v2, Train_1_beebook_deterministic_MC_POR_v2>>>,
                          transitions: Arc<AtomicI64>) -> HashSet<Train_1_beebook_deterministic_MC_POR_v2> {
        let mut result = HashSet::<Train_1_beebook_deterministic_MC_POR_v2>::new();
        if isCaching {
            let mut parents_guard_o = parents_m.lock().unwrap().get(state).and_then(|p| guardCache.lock().unwrap().get(p).cloned());
            let mut newCache = if parents_guard_o.is_none() { PersistentHashMap::new() } else { parents_guard_o.as_ref().unwrap().clone() };
            //model_check_transition
            let mut _trid_1 = state._tr_route_reservation(isCaching);
            for param in _trid_1.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.route_reservation(_tmp_1);
                match guard_dependency.get("route_reservation") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("route_reservation").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("route_reservation").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_2 = state._tr_route_freeing(isCaching);
            for param in _trid_2.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.route_freeing(_tmp_1);
                match guard_dependency.get("route_freeing") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("route_freeing").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("route_freeing").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_3 = state._tr_FRONT_MOVE_1(isCaching);
            for param in _trid_3.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.FRONT_MOVE_1(_tmp_1);
                match guard_dependency.get("FRONT_MOVE_1") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("FRONT_MOVE_1").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("FRONT_MOVE_1").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_4 = state._tr_FRONT_MOVE_2(isCaching);
            for param in _trid_4.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.FRONT_MOVE_2(_tmp_1);
                match guard_dependency.get("FRONT_MOVE_2") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("FRONT_MOVE_2").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("FRONT_MOVE_2").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_5 = state._tr_BACK_MOVE_1(isCaching);
            for param in _trid_5.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.BACK_MOVE_1(_tmp_1);
                match guard_dependency.get("BACK_MOVE_1") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("BACK_MOVE_1").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("BACK_MOVE_1").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_6 = state._tr_BACK_MOVE_2(isCaching);
            for param in _trid_6.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.BACK_MOVE_2(_tmp_1);
                match guard_dependency.get("BACK_MOVE_2") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("BACK_MOVE_2").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("BACK_MOVE_2").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_7 = state._tr_point_positionning(isCaching);
            for param in _trid_7.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.point_positionning(_tmp_1);
                match guard_dependency.get("point_positionning") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("point_positionning").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("point_positionning").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_8 = state._tr_route_formation(isCaching);
            for param in _trid_8.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.route_formation(_tmp_1);
                match guard_dependency.get("route_formation") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("route_formation").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("route_formation").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }

            guardCache.lock().unwrap().insert(state.clone(), newCache);
        } else {
            //model_check_transition
            let mut _trid_1 = state._tr_route_reservation(isCaching);
            for param in _trid_1.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.route_reservation(_tmp_1);
                match guard_dependency.get("route_reservation") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_2 = state._tr_route_freeing(isCaching);
            for param in _trid_2.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.route_freeing(_tmp_1);
                match guard_dependency.get("route_freeing") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_3 = state._tr_FRONT_MOVE_1(isCaching);
            for param in _trid_3.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.FRONT_MOVE_1(_tmp_1);
                match guard_dependency.get("FRONT_MOVE_1") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_4 = state._tr_FRONT_MOVE_2(isCaching);
            for param in _trid_4.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.FRONT_MOVE_2(_tmp_1);
                match guard_dependency.get("FRONT_MOVE_2") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_5 = state._tr_BACK_MOVE_1(isCaching);
            for param in _trid_5.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.BACK_MOVE_1(_tmp_1);
                match guard_dependency.get("BACK_MOVE_1") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_6 = state._tr_BACK_MOVE_2(isCaching);
            for param in _trid_6.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.BACK_MOVE_2(_tmp_1);
                match guard_dependency.get("BACK_MOVE_2") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_7 = state._tr_point_positionning(isCaching);
            for param in _trid_7.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.point_positionning(_tmp_1);
                match guard_dependency.get("point_positionning") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_8 = state._tr_route_formation(isCaching);
            for param in _trid_8.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.route_formation(_tmp_1);
                match guard_dependency.get("route_formation") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }

        }
        return result;
    }

    //model_check_evaluate_state

    //model_check_invariants
    pub fn checkInvariants(state: &Train_1_beebook_deterministic_MC_POR_v2,
                           isCaching: bool,
                           dependent_invariant_m: Arc<Mutex<HashMap<Train_1_beebook_deterministic_MC_POR_v2, HashSet<&str>>>> ) -> bool {
        let cached_invariants = dependent_invariant_m.lock().unwrap().get(&state).cloned();
        if cached_invariants.is_some() && isCaching {
            let dependent_invariants_of_state = cached_invariants.unwrap().clone();
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_1") {
                if !state._check_inv_1() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_2") {
                if !state._check_inv_2() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_3") {
                if !state._check_inv_3() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_4") {
                if !state._check_inv_4() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_5") {
                if !state._check_inv_5() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_6") {
                if !state._check_inv_6() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_7") {
                if !state._check_inv_7() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_8") {
                if !state._check_inv_8() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_9") {
                if !state._check_inv_9() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_10") {
                if !state._check_inv_10() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_11") {
                if !state._check_inv_11() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_12") {
                if !state._check_inv_12() {
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6() || !state._check_inv_7() || !state._check_inv_8() || !state._check_inv_9() || !state._check_inv_10() || !state._check_inv_11() || !state._check_inv_12());
    }

    //model_check_print
    fn print_result(states: i64, transitions: i64, deadlock_detected: bool, invariant_violated: bool) {
        if deadlock_detected { println!("DEADLOCK DETECTED"); }
        if invariant_violated { println!("INVARIANT VIOLATED"); }
        if !deadlock_detected && !invariant_violated { println!("MODEL CHECKING SUCCESSFUL"); }
        println!("Number of States: {}", states);
        println!("Number of Transitions: {}", transitions);
    }

    //model_check_main
    fn next(collection_m: Arc<Mutex<LinkedList<Train_1_beebook_deterministic_MC_POR_v2>>>, mc_type: MC_TYPE) -> Train_1_beebook_deterministic_MC_POR_v2 {
        let mut collection = collection_m.lock().unwrap();
        return match mc_type {
                MC_TYPE::BFS   => collection.pop_front().unwrap(),
                MC_TYPE::DFS   => collection.pop_back().unwrap(),
                MC_TYPE::MIXED => if collection.len() % 2 == 0 { collection.pop_front().unwrap() } else { collection.pop_back().unwrap() }
            };
    }

    fn model_check_single_threaded(mc_type: MC_TYPE, is_caching: bool) {
        let mut machine = Train_1_beebook_deterministic_MC_POR_v2::new();

        let invariant_violated = AtomicBool::new(false);
        let deadlock_detected = AtomicBool::new(false);
        let stop_threads = AtomicBool::new(false);

        if !machine._check_inv_1() || !machine._check_inv_2() || !machine._check_inv_3() || !machine._check_inv_4() || !machine._check_inv_5() || !machine._check_inv_6() || !machine._check_inv_7() || !machine._check_inv_8() || !machine._check_inv_9() || !machine._check_inv_10() || !machine._check_inv_11() || !machine._check_inv_12() {
            invariant_violated.store(true, Ordering::Release);
        }

        let mut states = HashSet::<Train_1_beebook_deterministic_MC_POR_v2>::new();
        states.insert(machine.clone());
        let number_states = AtomicI64::new(1);

        let collection_m = Arc::new(Mutex::new(LinkedList::<Train_1_beebook_deterministic_MC_POR_v2>::new()));
        collection_m.lock().unwrap().push_back(machine.clone());

        let mut invariantDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut guardDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut dependent_invariant_m = Arc::new(Mutex::new(HashMap::<Train_1_beebook_deterministic_MC_POR_v2, HashSet<&str>>::new()));
        let mut dependent_guard_m = Arc::new(Mutex::new(HashMap::<Train_1_beebook_deterministic_MC_POR_v2, HashSet<&str>>::new()));
        let mut guard_cache = Arc::new(Mutex::new(HashMap::<Train_1_beebook_deterministic_MC_POR_v2, PersistentHashMap<&'static str, bool>>::new()));
        let mut parents_m = Arc::new(Mutex::new(HashMap::<Train_1_beebook_deterministic_MC_POR_v2, Train_1_beebook_deterministic_MC_POR_v2>::new()));

        if is_caching {
            //model_check_init_static
            invariantDependency.insert("point_positionning", HashSet::from(["_check_inv_3", "_check_inv_1", "_check_inv_4"]));
            //model_check_init_static
            invariantDependency.insert("route_reservation", HashSet::from(["_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_8", "_check_inv_12", "_check_inv_9", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("FRONT_MOVE_1", HashSet::from(["_check_inv_6", "_check_inv_10", "_check_inv_5", "_check_inv_12", "_check_inv_9"]));
            //model_check_init_static
            invariantDependency.insert("BACK_MOVE_1", HashSet::from(["_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_5", "_check_inv_8", "_check_inv_12", "_check_inv_9"]));
            //model_check_init_static
            invariantDependency.insert("FRONT_MOVE_2", HashSet::from(["_check_inv_10", "_check_inv_5", "_check_inv_12", "_check_inv_9"]));
            //model_check_init_static
            invariantDependency.insert("route_formation", HashSet::from(["_check_inv_2", "_check_inv_4", "_check_inv_12", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("route_freeing", HashSet::from(["_check_inv_2", "_check_inv_7", "_check_inv_4", "_check_inv_12", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("BACK_MOVE_2", HashSet::from(["_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_5", "_check_inv_8", "_check_inv_12", "_check_inv_9"]));
            //model_check_init_static
            guardDependency.insert("point_positionning", HashSet::from(["_tr_route_formation", "_tr_BACK_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"]));
            //model_check_init_static
            guardDependency.insert("route_reservation", HashSet::from(["_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_BACK_MOVE_2"]));
            //model_check_init_static
            guardDependency.insert("FRONT_MOVE_1", HashSet::from(["_tr_FRONT_MOVE_1", "_tr_BACK_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"]));
            //model_check_init_static
            guardDependency.insert("BACK_MOVE_1", HashSet::from(["_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"]));
            //model_check_init_static
            guardDependency.insert("FRONT_MOVE_2", HashSet::from(["_tr_FRONT_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"]));
            //model_check_init_static
            guardDependency.insert("route_formation", HashSet::from(["_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_point_positionning"]));
            //model_check_init_static
            guardDependency.insert("route_freeing", HashSet::from(["_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_BACK_MOVE_2"]));
            //model_check_init_static
            guardDependency.insert("BACK_MOVE_2", HashSet::from(["_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"]));
            dependent_invariant_m.lock().unwrap().insert(machine.clone(), HashSet::new());
            parents_m.lock().unwrap().remove(&machine);
        }

        let transitions = Arc::new(AtomicI64::new(0));

        while !stop_threads.load(Ordering::Acquire) && !collection_m.lock().unwrap().is_empty() {
            let mut state = Self::next(Arc::clone(&collection_m), mc_type);

            let next_states = Self::generateNextStates(&mut state, is_caching, &mut invariantDependency, Arc::clone(&dependent_invariant_m), &mut guardDependency, Arc::clone(&dependent_guard_m), Arc::clone(&guard_cache), Arc::clone(&parents_m), Arc::clone(&transitions));

            next_states.iter().for_each(|next_state| {
                if !states.contains(next_state) {
                    let cnum_states = number_states.fetch_add(1, Ordering::AcqRel) + 1;
                    states.insert(next_state.clone());
                    collection_m.lock().unwrap().push_back(next_state.clone());
                    if cnum_states % 50000 == 0 {
                        println!("VISITED STATES: {}", cnum_states);
                        println!("EVALUATED TRANSITIONS: {}", transitions.load(Ordering::Acquire));
                        println!("-------------------");
                    }
                }
            });

            if next_states.is_empty() {
                deadlock_detected.store(true, Ordering::Release);
                stop_threads.store(true, Ordering::Release);
            }

            if !Self::checkInvariants(&state, is_caching, Arc::clone(&dependent_invariant_m)) {
                invariant_violated.store(true, Ordering::Release);
                stop_threads.store(true, Ordering::Release);
            }

        }
        Self::print_result(number_states.load(Ordering::Acquire), transitions.load(Ordering::Acquire), deadlock_detected.load(Ordering::Acquire), invariant_violated.load(Ordering::Acquire));
    }

    fn modelCheckMultiThreaded(mc_type: MC_TYPE, threads: usize, is_caching: bool) {
        let threadPool = ThreadPool::new(threads);

        let machine = Train_1_beebook_deterministic_MC_POR_v2::new();


        let invariant_violated_b = Arc::new(AtomicBool::new(false));
        let deadlock_detected_b = Arc::new(AtomicBool::new(false));
        let stop_threads_b = Arc::new(AtomicBool::new(false));
        let possible_queue_changes_b = Arc::new(AtomicI32::new(0));

        if !machine._check_inv_1() || !machine._check_inv_2() || !machine._check_inv_3() || !machine._check_inv_4() || !machine._check_inv_5() || !machine._check_inv_6() || !machine._check_inv_7() || !machine._check_inv_8() || !machine._check_inv_9() || !machine._check_inv_10() || !machine._check_inv_11() || !machine._check_inv_12() {
                invariant_violated_b.store(true, Ordering::Release);
        }

        let states_m = Arc::new(Mutex::new(HashSet::<Train_1_beebook_deterministic_MC_POR_v2>::new()));
        states_m.lock().unwrap().insert(machine.clone());
        let number_states_arc = Arc::new(AtomicI64::new(1));

        let collection_m = Arc::new(Mutex::new(LinkedList::<Train_1_beebook_deterministic_MC_POR_v2>::new()));
        collection_m.lock().unwrap().push_back(machine.clone());

        let mut invariantDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut guardDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut dependent_invariant_m = Arc::new(Mutex::new(HashMap::<Train_1_beebook_deterministic_MC_POR_v2, HashSet<&str>>::new()));
        let mut dependent_guard_m = Arc::new(Mutex::new(HashMap::<Train_1_beebook_deterministic_MC_POR_v2, HashSet<&str>>::new()));
        let mut guard_cache_b = Arc::new(Mutex::new(HashMap::<Train_1_beebook_deterministic_MC_POR_v2, PersistentHashMap<&'static str, bool>>::new()));
        let mut parents_m = Arc::new(Mutex::new(HashMap::<Train_1_beebook_deterministic_MC_POR_v2, Train_1_beebook_deterministic_MC_POR_v2>::new()));

        if is_caching {
            //model_check_init_static
            invariantDependency.insert("point_positionning", HashSet::from(["_check_inv_3", "_check_inv_1", "_check_inv_4"]));
            //model_check_init_static
            invariantDependency.insert("route_reservation", HashSet::from(["_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_8", "_check_inv_12", "_check_inv_9", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("FRONT_MOVE_1", HashSet::from(["_check_inv_6", "_check_inv_10", "_check_inv_5", "_check_inv_12", "_check_inv_9"]));
            //model_check_init_static
            invariantDependency.insert("BACK_MOVE_1", HashSet::from(["_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_5", "_check_inv_8", "_check_inv_12", "_check_inv_9"]));
            //model_check_init_static
            invariantDependency.insert("FRONT_MOVE_2", HashSet::from(["_check_inv_10", "_check_inv_5", "_check_inv_12", "_check_inv_9"]));
            //model_check_init_static
            invariantDependency.insert("route_formation", HashSet::from(["_check_inv_2", "_check_inv_4", "_check_inv_12", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("route_freeing", HashSet::from(["_check_inv_2", "_check_inv_7", "_check_inv_4", "_check_inv_12", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("BACK_MOVE_2", HashSet::from(["_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_5", "_check_inv_8", "_check_inv_12", "_check_inv_9"]));
            //model_check_init_static
            guardDependency.insert("point_positionning", HashSet::from(["_tr_route_formation", "_tr_BACK_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"]));
            //model_check_init_static
            guardDependency.insert("route_reservation", HashSet::from(["_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_BACK_MOVE_2"]));
            //model_check_init_static
            guardDependency.insert("FRONT_MOVE_1", HashSet::from(["_tr_FRONT_MOVE_1", "_tr_BACK_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"]));
            //model_check_init_static
            guardDependency.insert("BACK_MOVE_1", HashSet::from(["_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"]));
            //model_check_init_static
            guardDependency.insert("FRONT_MOVE_2", HashSet::from(["_tr_FRONT_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"]));
            //model_check_init_static
            guardDependency.insert("route_formation", HashSet::from(["_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_point_positionning"]));
            //model_check_init_static
            guardDependency.insert("route_freeing", HashSet::from(["_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_BACK_MOVE_2"]));
            //model_check_init_static
            guardDependency.insert("BACK_MOVE_2", HashSet::from(["_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"]));
            dependent_invariant_m.lock().unwrap().insert(machine.clone(), HashSet::new());
            parents_m.lock().unwrap().remove(&machine);
        }

        let num_transitions = Arc::new(AtomicI64::new(0));
        let invariant_dependency_arc = Arc::new(invariantDependency);
        let guard_dependency_arc = Arc::new(guardDependency);

        let (tx, rx) = channel();
        //println!("Thread {:?} starting threads", thread::current().id());
        while !stop_threads_b.load(Ordering::Acquire) && !collection_m.lock().unwrap().is_empty() {
            possible_queue_changes_b.fetch_add(1, Ordering::AcqRel);
            let mut state = Self::next(Arc::clone(&collection_m), mc_type);

            let invariant_violated = Arc::clone(&invariant_violated_b);
            let deadlock_detected = Arc::clone(&deadlock_detected_b);
            let stop_threads = Arc::clone(&stop_threads_b);
            let possible_queue_changes = Arc::clone(&possible_queue_changes_b);
            let collection_m2 = Arc::clone(&collection_m);
            let invariant_dependency = Arc::clone(&invariant_dependency_arc);
            let guard_dependency = Arc::clone(&guard_dependency_arc);
            let dependent_invariant_m2 = Arc::clone(&dependent_invariant_m);
            let dependent_guard_m2 = Arc::clone(&dependent_guard_m);
            let parents_m2 = Arc::clone(&parents_m);
            let guard_cache = Arc::clone(&guard_cache_b);
            let transitions = Arc::clone(&num_transitions);
            let states_m2 = Arc::clone(&states_m);
            let number_states = Arc::clone(&number_states_arc);
            let tx = tx.clone();
            //println!("Thread {:?} spawning a thread", thread::current().id());
            threadPool.execute(move|| {
                let next_states = Self::generateNextStates(&mut state, is_caching, &invariant_dependency, Arc::clone(&dependent_invariant_m2), &guard_dependency, dependent_guard_m2, guard_cache, parents_m2, Arc::clone(&transitions));

                //println!("Thread {:?} executing", thread::current().id());
                next_states.iter().for_each(|next_state| {
                    {
                        let mut states = states_m2.lock().unwrap();
                        let mut collection = collection_m2.lock().unwrap();
                        if !states.contains(next_state) {
                            let cnum_states = number_states.fetch_add(1, Ordering::AcqRel) + 1;
                            states.insert(next_state.clone());
                            collection.push_back(next_state.clone());
                            //println!("Thread {:?}: states in collection {}", thread::current().id(), collection.len());
                            if cnum_states % 50000 == 0 {
                                println!("VISITED STATES: {}", cnum_states);
                                println!("EVALUATED TRANSITIONS: {}", transitions.load(Ordering::Acquire));
                                println!("-------------------");
                            }
                        }
                    }
                });
                possible_queue_changes.fetch_sub(1, Ordering::AcqRel);

                if next_states.is_empty() {
                    deadlock_detected.store(true, Ordering::Release);
                    stop_threads.store(true, Ordering::Release);
                }

                if !Self::checkInvariants(&state, is_caching, Arc::clone(&dependent_invariant_m2)) {
                    invariant_violated.store(true, Ordering::Release);
                    stop_threads.store(true, Ordering::Release);
                }
                //println!("Thread {:?} done", thread::current().id());
                tx.send(1).expect("");
            });
            while collection_m.lock().unwrap().is_empty() && possible_queue_changes_b.load(Ordering::Acquire) > 0 {
                //println!("Thread {:?} (main) waiting for a thread to finish", thread::current().id());
                rx.recv().expect("Waiting for a thread to finish: ");
            }
        }

        Self::print_result(number_states_arc.load(Ordering::Acquire), num_transitions.load(Ordering::Acquire), deadlock_detected_b.load(Ordering::Acquire), invariant_violated_b.load(Ordering::Acquire));
    }

}


fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() != 4 { panic!("Number of arguments errorneous"); }

    let threads = args.get(2).unwrap().parse::<usize>().unwrap();
    if threads <= 0 { panic!("Input for number of threads is wrong."); }

    let is_caching = args.get(3).unwrap().parse::<bool>().unwrap();
    let mc_type = match args.get(1).unwrap().as_str() {
        "mixed" => MC_TYPE::MIXED,
        "bf" => MC_TYPE::BFS,
        "df" => MC_TYPE::DFS,
        _    => panic!("Input for strategy is wrong.")
    };

    if threads == 1 {
        Train_1_beebook_deterministic_MC_POR_v2::model_check_single_threaded(mc_type, is_caching);
    } else {
        Train_1_beebook_deterministic_MC_POR_v2::modelCheckMultiThreaded(mc_type, threads, is_caching);
    }
}
