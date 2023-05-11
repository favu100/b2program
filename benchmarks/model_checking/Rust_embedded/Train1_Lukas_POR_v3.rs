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

use std::env;
use std::sync::atomic::{AtomicU64, Ordering};
use std::sync::{Arc, mpsc, Mutex};
use std::collections::{HashSet, LinkedList};
use dashmap::DashSet;
use threadpool::ThreadPool;
use std::sync::mpsc::channel;
use derivative::Derivative;
use std::time::{Duration};



#[derive(Clone, Copy)]
pub enum MC_TYPE { BFS, DFS, MIXED }


//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum BLOCKS {
    #[default]
    A = 0, 
    B = 1, 
    C = 2, 
    D = 3, 
    E = 4, 
    F = 5, 
    G = 6, 
    H = 7, 
    I = 8
}

impl BLOCKS {
    pub fn equal(&self, other: &BLOCKS) -> bool { *self == *other }
    pub fn unequal(&self, other: &BLOCKS) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::A, 
            1 => Self::B, 
            2 => Self::C, 
            3 => Self::D, 
            4 => Self::E, 
            5 => Self::F, 
            6 => Self::G, 
            7 => Self::H, 
            8 => Self::I, 
            _ => panic!("BLOCKS index out of range! {:?}", idx)
        }
    }
}

impl SetItem<9> for BLOCKS {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_BLOCKS = BSet<BLOCKS, 9>;
//set_enum_declaration done

//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum ROUTES {
    #[default]
    R1 = 0, 
    R2 = 1, 
    R3 = 2, 
    R4 = 3, 
    R5 = 4, 
    R6 = 5, 
    R7 = 6, 
    R8 = 7
}

impl ROUTES {
    pub fn equal(&self, other: &ROUTES) -> bool { *self == *other }
    pub fn unequal(&self, other: &ROUTES) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::R1, 
            1 => Self::R2, 
            2 => Self::R3, 
            3 => Self::R4, 
            4 => Self::R5, 
            5 => Self::R6, 
            6 => Self::R7, 
            7 => Self::R8, 
            _ => panic!("ROUTES index out of range! {:?}", idx)
        }
    }
}

impl SetItem<8> for ROUTES {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_ROUTES = BSet<ROUTES, 8>;
//set_enum_declaration done

//relation_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum BLOCKS_X_BLOCKS {
    #[default]
    A_A = 0, 
    A_B = 1, 
    A_C = 2, 
    A_D = 3, 
    A_E = 4, 
    A_F = 5, 
    A_G = 6, 
    A_H = 7, 
    A_I = 8, 
    B_A = 9, 
    B_B = 10, 
    B_C = 11, 
    B_D = 12, 
    B_E = 13, 
    B_F = 14, 
    B_G = 15, 
    B_H = 16, 
    B_I = 17, 
    C_A = 18, 
    C_B = 19, 
    C_C = 20, 
    C_D = 21, 
    C_E = 22, 
    C_F = 23, 
    C_G = 24, 
    C_H = 25, 
    C_I = 26, 
    D_A = 27, 
    D_B = 28, 
    D_C = 29, 
    D_D = 30, 
    D_E = 31, 
    D_F = 32, 
    D_G = 33, 
    D_H = 34, 
    D_I = 35, 
    E_A = 36, 
    E_B = 37, 
    E_C = 38, 
    E_D = 39, 
    E_E = 40, 
    E_F = 41, 
    E_G = 42, 
    E_H = 43, 
    E_I = 44, 
    F_A = 45, 
    F_B = 46, 
    F_C = 47, 
    F_D = 48, 
    F_E = 49, 
    F_F = 50, 
    F_G = 51, 
    F_H = 52, 
    F_I = 53, 
    G_A = 54, 
    G_B = 55, 
    G_C = 56, 
    G_D = 57, 
    G_E = 58, 
    G_F = 59, 
    G_G = 60, 
    G_H = 61, 
    G_I = 62, 
    H_A = 63, 
    H_B = 64, 
    H_C = 65, 
    H_D = 66, 
    H_E = 67, 
    H_F = 68, 
    H_G = 69, 
    H_H = 70, 
    H_I = 71, 
    I_A = 72, 
    I_B = 73, 
    I_C = 74, 
    I_D = 75, 
    I_E = 76, 
    I_F = 77, 
    I_G = 78, 
    I_H = 79, 
    I_I = 80
}
type rel_BLOCKS_X_BLOCKS = BRelation<BLOCKS, { BLOCKS::VARIANTS }, BLOCKS, { BLOCKS::VARIANTS }, 81>;
//relation_declaration done



//relation_declaration
type rel_ROUTES_X_SetBLOCKS_X_BLOCKS = BRelation<ROUTES, { ROUTES::VARIANTS }, rel_BLOCKS_X_BLOCKS, { rel_BLOCKS_X_BLOCKS::VARIANTS }, 0>;
//relation_declaration done



//enum_set_declaration start
#[derive(Default, Debug, Clone, Copy)]
// each enum value corresponds to one BSet
pub enum SetBLOCKS_X_BLOCKS {
    #[default]
    SET_SET_A_B__B_C_TES_TES = 0, 
    SET_SET_A_B__B_D__D_E__E_F_TES_TES = 1, 
    SET_SET_E_F__G_E__H_G_TES_TES = 2, 
    SET_SET_E_F__G_E__I_G_TES_TES = 3, 
    SET_SET_B_A__C_B_TES_TES = 4, 
    SET_SET_B_A__D_B__E_D__F_E_TES_TES = 5, 
    SET_SET_E_G__F_E__G_H_TES_TES = 6, 
    SET_SET_E_G__F_E__G_I_TES_TES = 7
}
type set_SetBLOCKS_X_BLOCKS = BSet<rel_BLOCKS_X_BLOCKS, 8>;

impl PowSetItem<8, 81> for BLOCKS_X_BLOCKS {
    type SetRepr = SetBLOCKS_X_BLOCKS;
    fn arr_to_idx(set: [bool; 81]) -> usize {
        match set {
            [false, true, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false] => 0,
            [false, true, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false] => 1,
            [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false] => 2,
            [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false] => 3,
            [false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false] => 4,
            [false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false] => 5,
            [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false] => 6,
            [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false] => 7,
            _ => panic!("Attempting to convert non-existing set to index!") // only happens if this is a const-set and code-generation missed a necessary value
        }
    }
    fn idx_to_arr(idx: usize) -> [bool; 81] {
        match idx {
            0 => [false, true, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false],
            1 => [false, true, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false],
            2 => [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false],
            3 => [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false],
            4 => [false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false],
            5 => [false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false],
            6 => [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false],
            7 => [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false],
            _ => panic!("SetBLOCKS_X_BLOCKS index out of range! {:?}", idx)
        }
    }
}
impl RelLeftItem<{BLOCKS::VARIANTS}, BLOCKS, { BLOCKS::VARIANTS}, 8, 81> for BLOCKS {
    type RelEnum = BLOCKS_X_BLOCKS;
}
impl SetBLOCKS_X_BLOCKS {
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::SET_SET_A_B__B_C_TES_TES, 
            1 => Self::SET_SET_A_B__B_D__D_E__E_F_TES_TES, 
            2 => Self::SET_SET_E_F__G_E__H_G_TES_TES, 
            3 => Self::SET_SET_E_F__G_E__I_G_TES_TES, 
            4 => Self::SET_SET_B_A__C_B_TES_TES, 
            5 => Self::SET_SET_B_A__D_B__E_D__F_E_TES_TES, 
            6 => Self::SET_SET_E_G__F_E__G_H_TES_TES, 
            7 => Self::SET_SET_E_G__F_E__G_I_TES_TES, 
            _ => panic!("SetBLOCKS_X_BLOCKS index out of range! {:?}", idx)
        }
    }
}

impl SetItem<8> for SetBLOCKS_X_BLOCKS {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

//enum_set_declaration done

//relation_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum ROUTES_X_BLOCKS {
    #[default]
    R1_A = 0, 
    R1_B = 1, 
    R1_C = 2, 
    R1_D = 3, 
    R1_E = 4, 
    R1_F = 5, 
    R1_G = 6, 
    R1_H = 7, 
    R1_I = 8, 
    R2_A = 9, 
    R2_B = 10, 
    R2_C = 11, 
    R2_D = 12, 
    R2_E = 13, 
    R2_F = 14, 
    R2_G = 15, 
    R2_H = 16, 
    R2_I = 17, 
    R3_A = 18, 
    R3_B = 19, 
    R3_C = 20, 
    R3_D = 21, 
    R3_E = 22, 
    R3_F = 23, 
    R3_G = 24, 
    R3_H = 25, 
    R3_I = 26, 
    R4_A = 27, 
    R4_B = 28, 
    R4_C = 29, 
    R4_D = 30, 
    R4_E = 31, 
    R4_F = 32, 
    R4_G = 33, 
    R4_H = 34, 
    R4_I = 35, 
    R5_A = 36, 
    R5_B = 37, 
    R5_C = 38, 
    R5_D = 39, 
    R5_E = 40, 
    R5_F = 41, 
    R5_G = 42, 
    R5_H = 43, 
    R5_I = 44, 
    R6_A = 45, 
    R6_B = 46, 
    R6_C = 47, 
    R6_D = 48, 
    R6_E = 49, 
    R6_F = 50, 
    R6_G = 51, 
    R6_H = 52, 
    R6_I = 53, 
    R7_A = 54, 
    R7_B = 55, 
    R7_C = 56, 
    R7_D = 57, 
    R7_E = 58, 
    R7_F = 59, 
    R7_G = 60, 
    R7_H = 61, 
    R7_I = 62, 
    R8_A = 63, 
    R8_B = 64, 
    R8_C = 65, 
    R8_D = 66, 
    R8_E = 67, 
    R8_F = 68, 
    R8_G = 69, 
    R8_H = 70, 
    R8_I = 71
}
type rel_ROUTES_X_BLOCKS = BRelation<ROUTES, { ROUTES::VARIANTS }, BLOCKS, { BLOCKS::VARIANTS }, 72>;
//relation_declaration done

//relation_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum BLOCKS_X_ROUTES {
    #[default]
    A_R1 = 0, 
    A_R2 = 1, 
    A_R3 = 2, 
    A_R4 = 3, 
    A_R5 = 4, 
    A_R6 = 5, 
    A_R7 = 6, 
    A_R8 = 7, 
    B_R1 = 8, 
    B_R2 = 9, 
    B_R3 = 10, 
    B_R4 = 11, 
    B_R5 = 12, 
    B_R6 = 13, 
    B_R7 = 14, 
    B_R8 = 15, 
    C_R1 = 16, 
    C_R2 = 17, 
    C_R3 = 18, 
    C_R4 = 19, 
    C_R5 = 20, 
    C_R6 = 21, 
    C_R7 = 22, 
    C_R8 = 23, 
    D_R1 = 24, 
    D_R2 = 25, 
    D_R3 = 26, 
    D_R4 = 27, 
    D_R5 = 28, 
    D_R6 = 29, 
    D_R7 = 30, 
    D_R8 = 31, 
    E_R1 = 32, 
    E_R2 = 33, 
    E_R3 = 34, 
    E_R4 = 35, 
    E_R5 = 36, 
    E_R6 = 37, 
    E_R7 = 38, 
    E_R8 = 39, 
    F_R1 = 40, 
    F_R2 = 41, 
    F_R3 = 42, 
    F_R4 = 43, 
    F_R5 = 44, 
    F_R6 = 45, 
    F_R7 = 46, 
    F_R8 = 47, 
    G_R1 = 48, 
    G_R2 = 49, 
    G_R3 = 50, 
    G_R4 = 51, 
    G_R5 = 52, 
    G_R6 = 53, 
    G_R7 = 54, 
    G_R8 = 55, 
    H_R1 = 56, 
    H_R2 = 57, 
    H_R3 = 58, 
    H_R4 = 59, 
    H_R5 = 60, 
    H_R6 = 61, 
    H_R7 = 62, 
    H_R8 = 63, 
    I_R1 = 64, 
    I_R2 = 65, 
    I_R3 = 66, 
    I_R4 = 67, 
    I_R5 = 68, 
    I_R6 = 69, 
    I_R7 = 70, 
    I_R8 = 71
}
type rel_BLOCKS_X_ROUTES = BRelation<BLOCKS, { BLOCKS::VARIANTS }, ROUTES, { ROUTES::VARIANTS }, 72>;
//relation_declaration done

#[derive(Derivative)]
#[derivative(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct Train1_Lukas_POR_v3 {
    /*declarations*/LBT: set_BLOCKS,
    TRK: rel_BLOCKS_X_BLOCKS,
    frm: set_ROUTES,
    OCC: set_BLOCKS,
    resbl: set_BLOCKS,
    resrt: set_ROUTES,
    rsrtbl: rel_BLOCKS_X_ROUTES,
    /*constant_declarations*/fst: rel_ROUTES_X_BLOCKS,
    lst: rel_ROUTES_X_BLOCKS,
    nxt: rel_ROUTES_X_SetBLOCKS_X_BLOCKS,
    rtbl: rel_BLOCKS_X_ROUTES,
    /*sets*//*set_declaration*/_BLOCKS: set_BLOCKS,
    /*set_declaration*/_ROUTES: set_ROUTES,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_route_reservation: Option<HashSet<ROUTES>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_route_freeing: Option<HashSet<ROUTES>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_FRONT_MOVE_1: Option<HashSet<ROUTES>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_FRONT_MOVE_2: Option<HashSet<BLOCKS>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_BACK_MOVE_1: Option<HashSet<BLOCKS>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_BACK_MOVE_2: Option<HashSet<BLOCKS>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_point_positionning: Option<HashSet<ROUTES>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_route_formation: Option<HashSet<ROUTES>>,}


impl Train1_Lukas_POR_v3 {

    pub fn new() -> Train1_Lukas_POR_v3 {
        //values: ''
        let mut m: Train1_Lukas_POR_v3 = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        /*set_initializations*///set_initialization
    self._BLOCKS = bset![BLOCKS, /*enum_call*/BLOCKS::A, /*enum_call*/BLOCKS::B, /*enum_call*/BLOCKS::C, /*enum_call*/BLOCKS::D, /*enum_call*/BLOCKS::E, /*enum_call*/BLOCKS::F, /*enum_call*/BLOCKS::G, /*enum_call*/BLOCKS::H, /*enum_call*/BLOCKS::I];
    //set_initialization
    self._ROUTES = bset![ROUTES, /*enum_call*/ROUTES::R1, /*enum_call*/ROUTES::R2, /*enum_call*/ROUTES::R3, /*enum_call*/ROUTES::R4, /*enum_call*/ROUTES::R5, /*enum_call*/ROUTES::R6, /*enum_call*/ROUTES::R7, /*enum_call*/ROUTES::R8];
        /*properties*///constant_initialization
    self.nxt = brel![rel_ROUTES_X_SetBLOCKS_X_BLOCKS, (/*enum_call*/ROUTES::R1.clone(), brel![rel_BLOCKS_X_BLOCKS, (/*enum_call*/BLOCKS::A.clone(), /*enum_call*/BLOCKS::B.clone()), (/*enum_call*/BLOCKS::B.clone(), /*enum_call*/BLOCKS::C.clone())].clone()), (/*enum_call*/ROUTES::R2.clone(), brel![rel_BLOCKS_X_BLOCKS, (/*enum_call*/BLOCKS::A.clone(), /*enum_call*/BLOCKS::B.clone()), (/*enum_call*/BLOCKS::B.clone(), /*enum_call*/BLOCKS::D.clone()), (/*enum_call*/BLOCKS::D.clone(), /*enum_call*/BLOCKS::E.clone()), (/*enum_call*/BLOCKS::E.clone(), /*enum_call*/BLOCKS::F.clone())].clone()), (/*enum_call*/ROUTES::R3.clone(), brel![rel_BLOCKS_X_BLOCKS, (/*enum_call*/BLOCKS::H.clone(), /*enum_call*/BLOCKS::G.clone()), (/*enum_call*/BLOCKS::G.clone(), /*enum_call*/BLOCKS::E.clone()), (/*enum_call*/BLOCKS::E.clone(), /*enum_call*/BLOCKS::F.clone())].clone()), (/*enum_call*/ROUTES::R4.clone(), brel![rel_BLOCKS_X_BLOCKS, (/*enum_call*/BLOCKS::I.clone(), /*enum_call*/BLOCKS::G.clone()), (/*enum_call*/BLOCKS::G.clone(), /*enum_call*/BLOCKS::E.clone()), (/*enum_call*/BLOCKS::E.clone(), /*enum_call*/BLOCKS::F.clone())].clone()), (/*enum_call*/ROUTES::R5.clone(), brel![rel_BLOCKS_X_BLOCKS, (/*enum_call*/BLOCKS::C.clone(), /*enum_call*/BLOCKS::B.clone()), (/*enum_call*/BLOCKS::B.clone(), /*enum_call*/BLOCKS::A.clone())].clone()), (/*enum_call*/ROUTES::R6.clone(), brel![rel_BLOCKS_X_BLOCKS, (/*enum_call*/BLOCKS::F.clone(), /*enum_call*/BLOCKS::E.clone()), (/*enum_call*/BLOCKS::E.clone(), /*enum_call*/BLOCKS::D.clone()), (/*enum_call*/BLOCKS::D.clone(), /*enum_call*/BLOCKS::B.clone()), (/*enum_call*/BLOCKS::B.clone(), /*enum_call*/BLOCKS::A.clone())].clone()), (/*enum_call*/ROUTES::R7.clone(), brel![rel_BLOCKS_X_BLOCKS, (/*enum_call*/BLOCKS::F.clone(), /*enum_call*/BLOCKS::E.clone()), (/*enum_call*/BLOCKS::E.clone(), /*enum_call*/BLOCKS::G.clone()), (/*enum_call*/BLOCKS::G.clone(), /*enum_call*/BLOCKS::H.clone())].clone()), (/*enum_call*/ROUTES::R8.clone(), brel![rel_BLOCKS_X_BLOCKS, (/*enum_call*/BLOCKS::F.clone(), /*enum_call*/BLOCKS::E.clone()), (/*enum_call*/BLOCKS::E.clone(), /*enum_call*/BLOCKS::G.clone()), (/*enum_call*/BLOCKS::G.clone(), /*enum_call*/BLOCKS::I.clone())].clone())];
    //constant_initialization
    self.fst = brel![rel_ROUTES_X_BLOCKS, (/*enum_call*/ROUTES::R1.clone(), /*enum_call*/BLOCKS::A.clone()), (/*enum_call*/ROUTES::R2.clone(), /*enum_call*/BLOCKS::A.clone()), (/*enum_call*/ROUTES::R3.clone(), /*enum_call*/BLOCKS::H.clone()), (/*enum_call*/ROUTES::R4.clone(), /*enum_call*/BLOCKS::I.clone()), (/*enum_call*/ROUTES::R5.clone(), /*enum_call*/BLOCKS::C.clone()), (/*enum_call*/ROUTES::R6.clone(), /*enum_call*/BLOCKS::F.clone()), (/*enum_call*/ROUTES::R7.clone(), /*enum_call*/BLOCKS::F.clone()), (/*enum_call*/ROUTES::R8.clone(), /*enum_call*/BLOCKS::F.clone())];
    //constant_initialization
    self.lst = brel![rel_ROUTES_X_BLOCKS, (/*enum_call*/ROUTES::R1.clone(), /*enum_call*/BLOCKS::C.clone()), (/*enum_call*/ROUTES::R2.clone(), /*enum_call*/BLOCKS::F.clone()), (/*enum_call*/ROUTES::R3.clone(), /*enum_call*/BLOCKS::F.clone()), (/*enum_call*/ROUTES::R4.clone(), /*enum_call*/BLOCKS::F.clone()), (/*enum_call*/ROUTES::R5.clone(), /*enum_call*/BLOCKS::A.clone()), (/*enum_call*/ROUTES::R6.clone(), /*enum_call*/BLOCKS::A.clone()), (/*enum_call*/ROUTES::R7.clone(), /*enum_call*/BLOCKS::H.clone()), (/*enum_call*/ROUTES::R8.clone(), /*enum_call*/BLOCKS::I.clone())];
    //constant_initialization
    self.rtbl = brel![rel_BLOCKS_X_ROUTES, (/*enum_call*/BLOCKS::A.clone(), /*enum_call*/ROUTES::R1.clone()), (/*enum_call*/BLOCKS::A.clone(), /*enum_call*/ROUTES::R2.clone()), (/*enum_call*/BLOCKS::A.clone(), /*enum_call*/ROUTES::R5.clone()), (/*enum_call*/BLOCKS::A.clone(), /*enum_call*/ROUTES::R6.clone()), (/*enum_call*/BLOCKS::B.clone(), /*enum_call*/ROUTES::R1.clone()), (/*enum_call*/BLOCKS::B.clone(), /*enum_call*/ROUTES::R2.clone()), (/*enum_call*/BLOCKS::B.clone(), /*enum_call*/ROUTES::R5.clone()), (/*enum_call*/BLOCKS::B.clone(), /*enum_call*/ROUTES::R6.clone()), (/*enum_call*/BLOCKS::C.clone(), /*enum_call*/ROUTES::R1.clone()), (/*enum_call*/BLOCKS::C.clone(), /*enum_call*/ROUTES::R5.clone()), (/*enum_call*/BLOCKS::D.clone(), /*enum_call*/ROUTES::R2.clone()), (/*enum_call*/BLOCKS::D.clone(), /*enum_call*/ROUTES::R6.clone()), (/*enum_call*/BLOCKS::E.clone(), /*enum_call*/ROUTES::R2.clone()), (/*enum_call*/BLOCKS::E.clone(), /*enum_call*/ROUTES::R3.clone()), (/*enum_call*/BLOCKS::E.clone(), /*enum_call*/ROUTES::R4.clone()), (/*enum_call*/BLOCKS::E.clone(), /*enum_call*/ROUTES::R6.clone()), (/*enum_call*/BLOCKS::E.clone(), /*enum_call*/ROUTES::R7.clone()), (/*enum_call*/BLOCKS::E.clone(), /*enum_call*/ROUTES::R8.clone()), (/*enum_call*/BLOCKS::F.clone(), /*enum_call*/ROUTES::R2.clone()), (/*enum_call*/BLOCKS::F.clone(), /*enum_call*/ROUTES::R3.clone()), (/*enum_call*/BLOCKS::F.clone(), /*enum_call*/ROUTES::R4.clone()), (/*enum_call*/BLOCKS::F.clone(), /*enum_call*/ROUTES::R6.clone()), (/*enum_call*/BLOCKS::F.clone(), /*enum_call*/ROUTES::R7.clone()), (/*enum_call*/BLOCKS::F.clone(), /*enum_call*/ROUTES::R8.clone()), (/*enum_call*/BLOCKS::G.clone(), /*enum_call*/ROUTES::R3.clone()), (/*enum_call*/BLOCKS::G.clone(), /*enum_call*/ROUTES::R4.clone()), (/*enum_call*/BLOCKS::G.clone(), /*enum_call*/ROUTES::R4.clone()), (/*enum_call*/BLOCKS::G.clone(), /*enum_call*/ROUTES::R7.clone()), (/*enum_call*/BLOCKS::G.clone(), /*enum_call*/ROUTES::R8.clone()), (/*enum_call*/BLOCKS::H.clone(), /*enum_call*/ROUTES::R3.clone()), (/*enum_call*/BLOCKS::H.clone(), /*enum_call*/ROUTES::R7.clone()), (/*enum_call*/BLOCKS::I.clone(), /*enum_call*/ROUTES::R4.clone()), (/*enum_call*/BLOCKS::I.clone(), /*enum_call*/ROUTES::R8.clone())];
        /*body*/self.resrt = bset![ROUTES].clone().clone();
    self.resbl = bset![BLOCKS].clone().clone();
    self.rsrtbl = brel![rel_BLOCKS_X_ROUTES].clone().clone();
    self.OCC = bset![BLOCKS].clone().clone();
    self.TRK = brel![rel_BLOCKS_X_BLOCKS].clone().clone();
    self.frm = bset![ROUTES].clone().clone();
    self.LBT = bset![BLOCKS].clone().clone();
        /*includesInitialization*/
    }

    pub fn get_fst(&self) -> rel_ROUTES_X_BLOCKS {
        return self.fst.clone();
    }

    pub fn get_lst(&self) -> rel_ROUTES_X_BLOCKS {
        return self.lst.clone();
    }

    pub fn get_nxt(&self) -> rel_ROUTES_X_SetBLOCKS_X_BLOCKS {
        return self.nxt.clone();
    }

    pub fn get_rtbl(&self) -> rel_BLOCKS_X_ROUTES {
        return self.rtbl.clone();
    }

    pub fn get_LBT(&self) -> set_BLOCKS {
        return self.LBT.clone();
    }

    pub fn get_TRK(&self) -> rel_BLOCKS_X_BLOCKS {
        return self.TRK.clone();
    }

    pub fn get_frm(&self) -> set_ROUTES {
        return self.frm.clone();
    }

    pub fn get_OCC(&self) -> set_BLOCKS {
        return self.OCC.clone();
    }

    pub fn get_resbl(&self) -> set_BLOCKS {
        return self.resbl.clone();
    }

    pub fn get_resrt(&self) -> set_ROUTES {
        return self.resrt.clone();
    }

    pub fn get_rsrtbl(&self) -> rel_BLOCKS_X_ROUTES {
        return self.rsrtbl.clone();
    }

    pub fn get__BLOCKS(&self) -> set_BLOCKS {
        return self._BLOCKS.clone();
    }

    pub fn get__ROUTES(&self) -> set_ROUTES {
        return self._ROUTES.clone();
    }

    pub fn route_reservation(&mut self, mut r: ROUTES) -> () {
        //pre_assert
        let mut _ld_resrt = self.resrt.clone();
        let mut _ld_rsrtbl = self.rsrtbl.clone();
        let mut _ld_resbl = self.resbl.clone();
        self.resrt = _ld_resrt.union(&bset![ROUTES, r]).clone().clone();
        self.rsrtbl = _ld_rsrtbl.union(&self.rtbl.rangeRestriction(&bset![ROUTES, r])).clone().clone();
        self.resbl = _ld_resbl.union(&self.rtbl.inverse().relationImage(&bset![ROUTES, r])).clone().clone();

    }

    pub fn route_freeing(&mut self, mut r: ROUTES) -> () {
        //pre_assert
        let mut _ld_frm = self.frm.clone();
        let mut _ld_resrt = self.resrt.clone();
        self.resrt = _ld_resrt.difference(&bset![ROUTES, r]).clone().clone();
        self.frm = _ld_frm.difference(&bset![ROUTES, r]).clone().clone();

    }

    pub fn FRONT_MOVE_1(&mut self, mut r: ROUTES) -> () {
        //pre_assert
        let mut _ld_OCC = self.OCC.clone();
        let mut _ld_LBT = self.LBT.clone();
        self.OCC = _ld_OCC.union(&bset![BLOCKS, self.fst.functionCall(&r)]).clone().clone();
        self.LBT = _ld_LBT.union(&bset![BLOCKS, self.fst.functionCall(&r)]).clone().clone();

    }

    pub fn FRONT_MOVE_2(&mut self, mut b: BLOCKS) -> () {
        //pre_assert
        self.OCC = self.OCC.union(&bset![BLOCKS, self.TRK.functionCall(&b)]).clone().clone();

    }

    pub fn BACK_MOVE_1(&mut self, mut b: BLOCKS) -> () {
        //pre_assert
        let mut _ld_rsrtbl = self.rsrtbl.clone();
        let mut _ld_resbl = self.resbl.clone();
        let mut _ld_OCC = self.OCC.clone();
        let mut _ld_LBT = self.LBT.clone();
        self.OCC = _ld_OCC.difference(&bset![BLOCKS, b]).clone().clone();
        self.rsrtbl = _ld_rsrtbl.domainSubstraction(&bset![BLOCKS, b]).clone().clone();
        self.resbl = _ld_resbl.difference(&bset![BLOCKS, b]).clone().clone();
        self.LBT = _ld_LBT.difference(&bset![BLOCKS, b]).clone().clone();

    }

    pub fn BACK_MOVE_2(&mut self, mut b: BLOCKS) -> () {
        //pre_assert
        let mut _ld_rsrtbl = self.rsrtbl.clone();
        let mut _ld_resbl = self.resbl.clone();
        let mut _ld_OCC = self.OCC.clone();
        let mut _ld_LBT = self.LBT.clone();
        self.OCC = _ld_OCC.difference(&bset![BLOCKS, b]).clone().clone();
        self.rsrtbl = _ld_rsrtbl.domainSubstraction(&bset![BLOCKS, b]).clone().clone();
        self.resbl = _ld_resbl.difference(&bset![BLOCKS, b]).clone().clone();
        self.LBT = _ld_LBT.difference(&bset![BLOCKS, b]).union(&bset![BLOCKS, self.TRK.functionCall(&b)]).clone().clone();

    }

    pub fn point_positionning(&mut self, mut r: ROUTES) -> () {
        //pre_assert
        self.TRK = self.TRK.domainSubstraction(&self.nxt.functionCall(&r).domain()).rangeSubstraction(&self.nxt.functionCall(&r).range()).union(&self.nxt.functionCall(&r)).clone().clone();

    }

    pub fn route_formation(&mut self, mut r: ROUTES) -> () {
        //pre_assert
        self.frm = self.frm.union(&bset![ROUTES, r]).clone().clone();

    }

    pub fn _tr_route_reservation(&mut self, is_caching: bool) -> HashSet<ROUTES> {
        //transition
        if !is_caching || self._tr_cache_route_reservation.is_none() {
            let mut _ic_set_0: HashSet<ROUTES> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_r_1 in self._ROUTES.difference(&self.resrt).clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if (self.rtbl.inverse().relationImage(&bset![ROUTES, _ic_r_1]).intersect(&self.resbl).equal(&bset![BLOCKS]) && bset![ROUTES].equal(&self.resrt.difference(&self.rsrtbl.range()))) {
                    _ic_set_0.insert(_ic_r_1);
                }

            }
            self._tr_cache_route_reservation = Option::Some(_ic_set_0.clone());
            return _ic_set_0;
        } else {
            return self._tr_cache_route_reservation.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_route_freeing(&mut self, is_caching: bool) -> HashSet<ROUTES> {
        //transition
        if !is_caching || self._tr_cache_route_freeing.is_none() {
            let mut _ic_set_1: HashSet<ROUTES> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_r_1 in self.resrt.difference(&self.rsrtbl.range()).clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                _ic_set_1.insert(_ic_r_1);

            }
            self._tr_cache_route_freeing = Option::Some(_ic_set_1.clone());
            return _ic_set_1;
        } else {
            return self._tr_cache_route_freeing.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_FRONT_MOVE_1(&mut self, is_caching: bool) -> HashSet<ROUTES> {
        //transition
        if !is_caching || self._tr_cache_FRONT_MOVE_1.is_none() {
            let mut _ic_set_2: HashSet<ROUTES> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_r_1 in self.frm.clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if ((self.resbl.difference(&self.OCC).elementOf(&self.fst.functionCall(&_ic_r_1)) && _ic_r_1.equal(&self.rsrtbl.functionCall(&self.fst.functionCall(&_ic_r_1)))) && bset![ROUTES].equal(&self.resrt.difference(&self.rsrtbl.range()))) {
                    _ic_set_2.insert(_ic_r_1);
                }

            }
            self._tr_cache_FRONT_MOVE_1 = Option::Some(_ic_set_2.clone());
            return _ic_set_2;
        } else {
            return self._tr_cache_FRONT_MOVE_1.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_FRONT_MOVE_2(&mut self, is_caching: bool) -> HashSet<BLOCKS> {
        //transition
        if !is_caching || self._tr_cache_FRONT_MOVE_2.is_none() {
            let mut _ic_set_3: HashSet<BLOCKS> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_b_1 in self.OCC.intersect(&self.TRK.domain()).clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if (self.OCC.notElementOf(&self.TRK.functionCall(&_ic_b_1)) && bset![ROUTES].equal(&self.resrt.difference(&self.rsrtbl.range()))) {
                    _ic_set_3.insert(_ic_b_1);
                }

            }
            self._tr_cache_FRONT_MOVE_2 = Option::Some(_ic_set_3.clone());
            return _ic_set_3;
        } else {
            return self._tr_cache_FRONT_MOVE_2.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_BACK_MOVE_1(&mut self, is_caching: bool) -> HashSet<BLOCKS> {
        //transition
        if !is_caching || self._tr_cache_BACK_MOVE_1.is_none() {
            let mut _ic_set_4: HashSet<BLOCKS> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_b_1 in self.LBT.difference(&self.TRK.domain()).clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if bset![ROUTES].equal(&self.resrt.difference(&self.rsrtbl.range())) {
                    _ic_set_4.insert(_ic_b_1);
                }

            }
            self._tr_cache_BACK_MOVE_1 = Option::Some(_ic_set_4.clone());
            return _ic_set_4;
        } else {
            return self._tr_cache_BACK_MOVE_1.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_BACK_MOVE_2(&mut self, is_caching: bool) -> HashSet<BLOCKS> {
        //transition
        if !is_caching || self._tr_cache_BACK_MOVE_2.is_none() {
            let mut _ic_set_5: HashSet<BLOCKS> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_b_1 in self.LBT.intersect(&self.TRK.domain()).clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if (self.OCC.elementOf(&self.TRK.functionCall(&_ic_b_1)) && bset![ROUTES].equal(&self.resrt.difference(&self.rsrtbl.range()))) {
                    _ic_set_5.insert(_ic_b_1);
                }

            }
            self._tr_cache_BACK_MOVE_2 = Option::Some(_ic_set_5.clone());
            return _ic_set_5;
        } else {
            return self._tr_cache_BACK_MOVE_2.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_point_positionning(&mut self, is_caching: bool) -> HashSet<ROUTES> {
        //transition
        if !is_caching || self._tr_cache_point_positionning.is_none() {
            let mut _ic_set_6: HashSet<ROUTES> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_r_1 in self.resrt.difference(&self.frm).clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if bset![ROUTES].equal(&self.resrt.difference(&self.rsrtbl.range())) {
                    _ic_set_6.insert(_ic_r_1);
                }

            }
            self._tr_cache_point_positionning = Option::Some(_ic_set_6.clone());
            return _ic_set_6;
        } else {
            return self._tr_cache_point_positionning.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_route_formation(&mut self, is_caching: bool) -> HashSet<ROUTES> {
        //transition
        if !is_caching || self._tr_cache_route_formation.is_none() {
            let mut _ic_set_7: HashSet<ROUTES> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_r_1 in self.resrt.difference(&self.frm).clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if (self.nxt.functionCall(&_ic_r_1).domainRestriction(&self.rsrtbl.inverse().relationImage(&bset![ROUTES, _ic_r_1])).equal(&self.TRK.domainRestriction(&self.rsrtbl.inverse().relationImage(&bset![ROUTES, _ic_r_1]))) && bset![ROUTES].equal(&self.resrt.difference(&self.rsrtbl.range()))) {
                    _ic_set_7.insert(_ic_r_1);
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
        return self._BLOCKS.check_domain_of(&self.TRK).and(&self._BLOCKS.check_range_of(&self.TRK)).and(&self.TRK.isFunction()).and(&self._BLOCKS.check_partial_of(&self.TRK)).and(&self.TRK.isInjection());
    }

    pub fn _check_inv_2(&self) -> bool {
        //invariant
        //quantified_predicate
        let mut _ic_boolean_8 = true;
        //iteration_construct_enumeration
        for _ic_r_1 in self.resrt.difference(&self.frm).clone().iter() {
            //iteration_construct_assignment
            {
                let mut _ic_a_1 = bset![ROUTES, _ic_r_1];
                if !self.rtbl.rangeRestriction(&_ic_a_1).equal(&self.rsrtbl.rangeRestriction(&_ic_a_1)) {
                    _ic_boolean_8 = false;
                    break;
                }

            }
        }

        return _ic_boolean_8;
    }

    pub fn _check_inv_3(&self) -> bool {
        //invariant
        //quantified_predicate
        let mut _ic_boolean_10 = true;
        //iteration_construct_enumeration
        for _ic_x_1 in self.TRK.domain().clone().iter() {
            //iteration_construct_enumeration
            for _ic_y_1 in self.TRK.relationImage(&bset![BLOCKS, _ic_x_1]).clone().iter() {
                //quantified_predicate
                let mut _ic_boolean_9 = false;
                //iteration_construct_enumeration
                for _ic_r_1 in self._ROUTES.clone().iter() {
                    if self.nxt.functionCall(&_ic_r_1).elementOf(&(_ic_x_1.clone(), _ic_y_1.clone())) {
                        _ic_boolean_9 = true;
                        break;
                    }

                }

                if !_ic_boolean_9 {
                    _ic_boolean_10 = false;
                    break;
                }

            }
        }

        return _ic_boolean_10;
    }

    pub fn _check_inv_4(&self) -> bool {
        //invariant
        //quantified_predicate
        let mut _ic_boolean_11 = true;
        //iteration_construct_enumeration
        for _ic_r_1 in self.frm.clone().iter() {
            //iteration_construct_assignment
            {
                let mut _ic_a_1 = self.rsrtbl.inverse().relationImage(&bset![ROUTES, _ic_r_1]);
                if !self.nxt.functionCall(&_ic_r_1).domainRestriction(&_ic_a_1).equal(&self.TRK.domainRestriction(&_ic_a_1)) {
                    _ic_boolean_11 = false;
                    break;
                }

            }
        }

        return _ic_boolean_11;
    }

    pub fn _check_inv_5(&self) -> bool {
        //invariant
        return self.LBT.subset(&self.OCC);
    }

    pub fn _check_inv_6(&self) -> bool {
        //invariant
        //quantified_predicate
        let mut _ic_boolean_12 = true;
        //iteration_construct_enumeration
        for _ic_a_1 in self.rsrtbl.domain().clone().iter() {
            //iteration_construct_enumeration
            for _ic_b_1 in self.LBT.clone().iter() {
                //iteration_construct_assignment
                {
                    let mut _ic_c_1 = self.rsrtbl.functionCall(&_ic_b_1);
                    //iteration_construct_assignment
                    {
                        let mut _ic_d_1 = self.nxt.functionCall(&_ic_c_1);
                        if !(_ic_d_1.range().elementOf(&_ic_b_1) && _ic_a_1.equal(&_ic_d_1.inverse().functionCall(&_ic_b_1))).implies(|| self.rsrtbl.functionCall(&_ic_a_1).unequal(&_ic_c_1)) {
                            _ic_boolean_12 = false;
                            break;
                        }

                    }
                }
            }
        }

        return _ic_boolean_12;
    }

    pub fn _check_inv_7(&self) -> bool {
        //invariant
        return self.resbl.check_domain_of(&self.rsrtbl).and(&self.resrt.check_range_of(&self.rsrtbl)).and(&self.rsrtbl.isFunction()).and(&self.resbl.check_total_of(&self.rsrtbl));
    }

    pub fn _check_inv_8(&self) -> bool {
        //invariant
        return self.rsrtbl.subset(&self.rtbl);
    }

    pub fn _check_inv_9(&self) -> bool {
        //invariant
        return self.OCC.subset(&self.resbl);
    }

    pub fn _check_inv_10(&self) -> bool {
        //invariant
        //quantified_predicate
        let mut _ic_boolean_13 = true;
        //iteration_construct_enumeration
        for _ic_r_1 in self._ROUTES.clone().iter() {
            //iteration_construct_assignment
            {
                let mut _ic_a_1 = self.nxt.functionCall(&_ic_r_1);
                //iteration_construct_assignment
                {
                    let mut _ic_b_1 = self.rsrtbl.inverse().relationImage(&bset![ROUTES, _ic_r_1]);
                    //iteration_construct_assignment
                    {
                        let mut _ic_c_1 = _ic_b_1.difference(&self.OCC);
                        if !((_ic_a_1.relationImage(&self.rtbl.inverse().relationImage(&bset![ROUTES, _ic_r_1]).difference(&_ic_b_1)).intersect(&_ic_c_1).equal(&bset![BLOCKS]) && _ic_a_1.relationImage(&_ic_b_1).subset(&_ic_b_1)) && _ic_a_1.relationImage(&_ic_c_1).subset(&_ic_c_1)) {
                            _ic_boolean_13 = false;
                            break;
                        }

                    }
                }
            }
        }

        return _ic_boolean_13;
    }

    pub fn _check_inv_11(&self) -> bool {
        //invariant
        return self.frm.subset(&self.resrt);
    }

    pub fn _check_inv_12(&self) -> bool {
        //invariant
        return self.rsrtbl.relationImage(&self.OCC).subset(&self.frm);
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
