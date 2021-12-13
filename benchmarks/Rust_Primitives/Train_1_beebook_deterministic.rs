#![ allow( dead_code, unused_imports, unused_mut, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::bboolean::BBoolean;
use btypes::brelation::BRelation;
use btypes::bset::BSet;
use btypes::bobject::BObject;
use btypes::btuple::BTuple;


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

#[derive(Default, Debug)]
pub struct Train_1_beebook_deterministic {
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
}

impl Train_1_beebook_deterministic {

    pub fn new() -> Train_1_beebook_deterministic {
        //values: ''
        let mut m: Train_1_beebook_deterministic = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.resrt = BSet::new(vec![]).clone().clone();
        self.resbl = BSet::new(vec![]).clone().clone();
        self.rsrtbl = BRelation::new(vec![]).clone().clone();
        self.OCC = BSet::new(vec![]).clone().clone();
        self.TRK = BRelation::new(vec![]).clone().clone();
        self.frm = BSet::new(vec![]).clone().clone();
        self.LBT = BSet::new(vec![]).clone().clone();
        self._BLOCKS = BSet::new(vec![BLOCKS::A, BLOCKS::B, BLOCKS::C, BLOCKS::D, BLOCKS::E, BLOCKS::F, BLOCKS::G, BLOCKS::H, BLOCKS::I, BLOCKS::J, BLOCKS::K, BLOCKS::L, BLOCKS::M, BLOCKS::N]);
        self._ROUTES = BSet::new(vec![ROUTES::R1, ROUTES::R2, ROUTES::R3, ROUTES::R4, ROUTES::R5, ROUTES::R6, ROUTES::R7, ROUTES::R8, ROUTES::R9, ROUTES::R10]);
        self.fst = BRelation::new(vec![BTuple::from_refs(&ROUTES::R1, &BLOCKS::L), BTuple::from_refs(&ROUTES::R2, &BLOCKS::L), BTuple::from_refs(&ROUTES::R3, &BLOCKS::L), BTuple::from_refs(&ROUTES::R4, &BLOCKS::M), BTuple::from_refs(&ROUTES::R5, &BLOCKS::M), BTuple::from_refs(&ROUTES::R6, &BLOCKS::C), BTuple::from_refs(&ROUTES::R7, &BLOCKS::G), BTuple::from_refs(&ROUTES::R8, &BLOCKS::N), BTuple::from_refs(&ROUTES::R9, &BLOCKS::G), BTuple::from_refs(&ROUTES::R10, &BLOCKS::N)]);
        self.lst = BRelation::new(vec![BTuple::from_refs(&ROUTES::R1, &BLOCKS::C), BTuple::from_refs(&ROUTES::R2, &BLOCKS::G), BTuple::from_refs(&ROUTES::R3, &BLOCKS::N), BTuple::from_refs(&ROUTES::R4, &BLOCKS::G), BTuple::from_refs(&ROUTES::R5, &BLOCKS::N), BTuple::from_refs(&ROUTES::R6, &BLOCKS::L), BTuple::from_refs(&ROUTES::R7, &BLOCKS::L), BTuple::from_refs(&ROUTES::R8, &BLOCKS::L), BTuple::from_refs(&ROUTES::R9, &BLOCKS::M), BTuple::from_refs(&ROUTES::R10, &BLOCKS::M)]);
        self.nxt = BRelation::new(vec![BTuple::from_refs(&ROUTES::R1, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::L, &BLOCKS::A), BTuple::from_refs(&BLOCKS::A, &BLOCKS::B), BTuple::from_refs(&BLOCKS::B, &BLOCKS::C)])), BTuple::from_refs(&ROUTES::R2, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::L, &BLOCKS::A), BTuple::from_refs(&BLOCKS::A, &BLOCKS::B), BTuple::from_refs(&BLOCKS::B, &BLOCKS::D), BTuple::from_refs(&BLOCKS::D, &BLOCKS::E), BTuple::from_refs(&BLOCKS::E, &BLOCKS::F), BTuple::from_refs(&BLOCKS::F, &BLOCKS::G)])), BTuple::from_refs(&ROUTES::R3, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::L, &BLOCKS::A), BTuple::from_refs(&BLOCKS::A, &BLOCKS::B), BTuple::from_refs(&BLOCKS::B, &BLOCKS::D), BTuple::from_refs(&BLOCKS::D, &BLOCKS::K), BTuple::from_refs(&BLOCKS::K, &BLOCKS::J), BTuple::from_refs(&BLOCKS::J, &BLOCKS::N)])), BTuple::from_refs(&ROUTES::R4, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::M, &BLOCKS::H), BTuple::from_refs(&BLOCKS::H, &BLOCKS::I), BTuple::from_refs(&BLOCKS::I, &BLOCKS::K), BTuple::from_refs(&BLOCKS::K, &BLOCKS::F), BTuple::from_refs(&BLOCKS::F, &BLOCKS::G)])), BTuple::from_refs(&ROUTES::R5, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::M, &BLOCKS::H), BTuple::from_refs(&BLOCKS::H, &BLOCKS::I), BTuple::from_refs(&BLOCKS::I, &BLOCKS::J), BTuple::from_refs(&BLOCKS::J, &BLOCKS::N)])), BTuple::from_refs(&ROUTES::R6, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::C, &BLOCKS::B), BTuple::from_refs(&BLOCKS::B, &BLOCKS::A), BTuple::from_refs(&BLOCKS::A, &BLOCKS::L)])), BTuple::from_refs(&ROUTES::R7, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::G, &BLOCKS::F), BTuple::from_refs(&BLOCKS::F, &BLOCKS::E), BTuple::from_refs(&BLOCKS::E, &BLOCKS::D), BTuple::from_refs(&BLOCKS::D, &BLOCKS::B), BTuple::from_refs(&BLOCKS::B, &BLOCKS::A), BTuple::from_refs(&BLOCKS::A, &BLOCKS::L)])), BTuple::from_refs(&ROUTES::R8, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::N, &BLOCKS::J), BTuple::from_refs(&BLOCKS::J, &BLOCKS::K), BTuple::from_refs(&BLOCKS::K, &BLOCKS::D), BTuple::from_refs(&BLOCKS::D, &BLOCKS::B), BTuple::from_refs(&BLOCKS::B, &BLOCKS::A), BTuple::from_refs(&BLOCKS::A, &BLOCKS::L)])), BTuple::from_refs(&ROUTES::R9, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::G, &BLOCKS::F), BTuple::from_refs(&BLOCKS::F, &BLOCKS::K), BTuple::from_refs(&BLOCKS::K, &BLOCKS::I), BTuple::from_refs(&BLOCKS::I, &BLOCKS::H), BTuple::from_refs(&BLOCKS::H, &BLOCKS::M)])), BTuple::from_refs(&ROUTES::R10, &BRelation::new(vec![BTuple::from_refs(&BLOCKS::N, &BLOCKS::J), BTuple::from_refs(&BLOCKS::J, &BLOCKS::I), BTuple::from_refs(&BLOCKS::I, &BLOCKS::H), BTuple::from_refs(&BLOCKS::H, &BLOCKS::M)]))]);
        let mut _ic_set_0 = BRelation::<BLOCKS, ROUTES>::new(vec![]);
        for _ic_b_1 in self._BLOCKS.clone().iter().cloned() {
            for _ic_r_1 in self._ROUTES.clone().iter().cloned() {
                if (self.nxt.domain().elementOf(&_ic_r_1).and(&self.nxt.functionCall(&_ic_r_1).domain().elementOf(&_ic_b_1).or(&self.nxt.functionCall(&_ic_r_1).range().elementOf(&_ic_b_1)))).booleanValue() {
                    _ic_set_0 = _ic_set_0._union(&BRelation::<BLOCKS, ROUTES>::new(vec![BTuple::from_refs(&_ic_b_1, &_ic_r_1)]));
                }

            }
        }
        self.rtbl = _ic_set_0;
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
        let mut _ld_resrt = self.resrt.clone();
        let mut _ld_rsrtbl = self.rsrtbl.clone();
        let mut _ld_resbl = self.resbl.clone();
        self.resrt = _ld_resrt._union(&BSet::new(vec![r])).clone().clone();
        self.rsrtbl = _ld_rsrtbl._union(&self.rtbl.rangeRestriction(&BSet::new(vec![r]))).clone().clone();
        self.resbl = _ld_resbl._union(&self.rtbl.inverse().relationImage(&BSet::new(vec![r]))).clone().clone();
    }

    pub fn route_freeing(&mut self, mut r: ROUTES) -> () {
        let mut _ld_frm = self.frm.clone();
        let mut _ld_resrt = self.resrt.clone();
        self.resrt = _ld_resrt.difference(&BSet::new(vec![r])).clone().clone();
        self.frm = _ld_frm.difference(&BSet::new(vec![r])).clone().clone();
    }

    pub fn FRONT_MOVE_1(&mut self, mut r: ROUTES) -> () {
        let mut _ld_OCC = self.OCC.clone();
        let mut _ld_LBT = self.LBT.clone();
        self.OCC = _ld_OCC._union(&BSet::new(vec![self.fst.functionCall(&r)])).clone().clone();
        self.LBT = _ld_LBT._union(&BSet::new(vec![self.fst.functionCall(&r)])).clone().clone();
    }

    pub fn FRONT_MOVE_2(&mut self, mut b: BLOCKS) -> () {
        self.OCC = self.OCC._union(&BSet::new(vec![self.TRK.functionCall(&b)])).clone().clone();
    }

    pub fn BACK_MOVE_1(&mut self, mut b: BLOCKS) -> () {
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
        self.TRK = self.TRK.domainSubstraction(&self.nxt.functionCall(&r).domain()).rangeSubstraction(&self.nxt.functionCall(&r).range())._union(&self.nxt.functionCall(&r)).clone().clone();
    }

    pub fn route_formation(&mut self, mut r: ROUTES) -> () {
        self.frm = self.frm._union(&BSet::new(vec![r])).clone().clone();
    }
}

