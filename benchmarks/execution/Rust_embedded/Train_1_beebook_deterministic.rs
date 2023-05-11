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
    I = 8, 
    J = 9, 
    K = 10, 
    L = 11, 
    M = 12, 
    N = 13
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
            9 => Self::J, 
            10 => Self::K, 
            11 => Self::L, 
            12 => Self::M, 
            13 => Self::N, 
            _ => panic!("BLOCKS index out of range! {:?}", idx)
        }
    }
}

impl SetItem<14> for BLOCKS {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_BLOCKS = BSet<BLOCKS, 14>;
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
    R8 = 7, 
    R9 = 8, 
    R10 = 9
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
            8 => Self::R9, 
            9 => Self::R10, 
            _ => panic!("ROUTES index out of range! {:?}", idx)
        }
    }
}

impl SetItem<10> for ROUTES {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_ROUTES = BSet<ROUTES, 10>;
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
    A_J = 9, 
    A_K = 10, 
    A_L = 11, 
    A_M = 12, 
    A_N = 13, 
    B_A = 14, 
    B_B = 15, 
    B_C = 16, 
    B_D = 17, 
    B_E = 18, 
    B_F = 19, 
    B_G = 20, 
    B_H = 21, 
    B_I = 22, 
    B_J = 23, 
    B_K = 24, 
    B_L = 25, 
    B_M = 26, 
    B_N = 27, 
    C_A = 28, 
    C_B = 29, 
    C_C = 30, 
    C_D = 31, 
    C_E = 32, 
    C_F = 33, 
    C_G = 34, 
    C_H = 35, 
    C_I = 36, 
    C_J = 37, 
    C_K = 38, 
    C_L = 39, 
    C_M = 40, 
    C_N = 41, 
    D_A = 42, 
    D_B = 43, 
    D_C = 44, 
    D_D = 45, 
    D_E = 46, 
    D_F = 47, 
    D_G = 48, 
    D_H = 49, 
    D_I = 50, 
    D_J = 51, 
    D_K = 52, 
    D_L = 53, 
    D_M = 54, 
    D_N = 55, 
    E_A = 56, 
    E_B = 57, 
    E_C = 58, 
    E_D = 59, 
    E_E = 60, 
    E_F = 61, 
    E_G = 62, 
    E_H = 63, 
    E_I = 64, 
    E_J = 65, 
    E_K = 66, 
    E_L = 67, 
    E_M = 68, 
    E_N = 69, 
    F_A = 70, 
    F_B = 71, 
    F_C = 72, 
    F_D = 73, 
    F_E = 74, 
    F_F = 75, 
    F_G = 76, 
    F_H = 77, 
    F_I = 78, 
    F_J = 79, 
    F_K = 80, 
    F_L = 81, 
    F_M = 82, 
    F_N = 83, 
    G_A = 84, 
    G_B = 85, 
    G_C = 86, 
    G_D = 87, 
    G_E = 88, 
    G_F = 89, 
    G_G = 90, 
    G_H = 91, 
    G_I = 92, 
    G_J = 93, 
    G_K = 94, 
    G_L = 95, 
    G_M = 96, 
    G_N = 97, 
    H_A = 98, 
    H_B = 99, 
    H_C = 100, 
    H_D = 101, 
    H_E = 102, 
    H_F = 103, 
    H_G = 104, 
    H_H = 105, 
    H_I = 106, 
    H_J = 107, 
    H_K = 108, 
    H_L = 109, 
    H_M = 110, 
    H_N = 111, 
    I_A = 112, 
    I_B = 113, 
    I_C = 114, 
    I_D = 115, 
    I_E = 116, 
    I_F = 117, 
    I_G = 118, 
    I_H = 119, 
    I_I = 120, 
    I_J = 121, 
    I_K = 122, 
    I_L = 123, 
    I_M = 124, 
    I_N = 125, 
    J_A = 126, 
    J_B = 127, 
    J_C = 128, 
    J_D = 129, 
    J_E = 130, 
    J_F = 131, 
    J_G = 132, 
    J_H = 133, 
    J_I = 134, 
    J_J = 135, 
    J_K = 136, 
    J_L = 137, 
    J_M = 138, 
    J_N = 139, 
    K_A = 140, 
    K_B = 141, 
    K_C = 142, 
    K_D = 143, 
    K_E = 144, 
    K_F = 145, 
    K_G = 146, 
    K_H = 147, 
    K_I = 148, 
    K_J = 149, 
    K_K = 150, 
    K_L = 151, 
    K_M = 152, 
    K_N = 153, 
    L_A = 154, 
    L_B = 155, 
    L_C = 156, 
    L_D = 157, 
    L_E = 158, 
    L_F = 159, 
    L_G = 160, 
    L_H = 161, 
    L_I = 162, 
    L_J = 163, 
    L_K = 164, 
    L_L = 165, 
    L_M = 166, 
    L_N = 167, 
    M_A = 168, 
    M_B = 169, 
    M_C = 170, 
    M_D = 171, 
    M_E = 172, 
    M_F = 173, 
    M_G = 174, 
    M_H = 175, 
    M_I = 176, 
    M_J = 177, 
    M_K = 178, 
    M_L = 179, 
    M_M = 180, 
    M_N = 181, 
    N_A = 182, 
    N_B = 183, 
    N_C = 184, 
    N_D = 185, 
    N_E = 186, 
    N_F = 187, 
    N_G = 188, 
    N_H = 189, 
    N_I = 190, 
    N_J = 191, 
    N_K = 192, 
    N_L = 193, 
    N_M = 194, 
    N_N = 195
}
type rel_BLOCKS_X_BLOCKS = BRelation<BLOCKS, { BLOCKS::VARIANTS }, BLOCKS, { BLOCKS::VARIANTS }, 196>;
//relation_declaration done



//relation_declaration
type rel_ROUTES_X_SetBLOCKS_X_BLOCKS = BRelation<ROUTES, { ROUTES::VARIANTS }, rel_BLOCKS_X_BLOCKS, { rel_BLOCKS_X_BLOCKS::VARIANTS }, 0>;
//relation_declaration done



//enum_set_declaration start
#[derive(Default, Debug, Clone, Copy)]
// each enum value corresponds to one BSet
pub enum SetBLOCKS_X_BLOCKS {
    #[default]
    SET_SET_A_B__B_C__L_A_TES_TES = 0, 
    SET_SET_A_B__B_D__D_E__E_F__F_G__L_A_TES_TES = 1, 
    SET_SET_A_B__B_D__D_K__J_N__K_J__L_A_TES_TES = 2, 
    SET_SET_F_G__H_I__I_K__K_F__M_H_TES_TES = 3, 
    SET_SET_H_I__I_J__J_N__M_H_TES_TES = 4, 
    SET_SET_A_L__B_A__C_B_TES_TES = 5, 
    SET_SET_A_L__B_A__D_B__E_D__F_E__G_F_TES_TES = 6, 
    SET_SET_A_L__B_A__D_B__J_K__K_D__N_J_TES_TES = 7, 
    SET_SET_F_K__G_F__H_M__I_H__K_I_TES_TES = 8, 
    SET_SET_H_M__I_H__J_I__N_J_TES_TES = 9
}
type set_SetBLOCKS_X_BLOCKS = BSet<rel_BLOCKS_X_BLOCKS, 10>;

impl PowSetItem<10, 196> for BLOCKS_X_BLOCKS {
    type SetRepr = SetBLOCKS_X_BLOCKS;
    fn arr_to_idx(set: [bool; 196]) -> usize {
        match set {
            [false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false] => 0,
            [false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false] => 1,
            [false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false] => 2,
            [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false] => 3,
            [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false] => 4,
            [false, false, false, false, false, false, false, false, false, false, false, true, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false] => 5,
            [false, false, false, false, false, false, false, false, false, false, false, true, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false] => 6,
            [false, false, false, false, false, false, false, false, false, false, false, true, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false] => 7,
            [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false] => 8,
            [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false] => 9,
            _ => panic!("Attempting to convert non-existing set to index!") // only happens if this is a const-set and code-generation missed a necessary value
        }
    }
    fn idx_to_arr(idx: usize) -> [bool; 196] {
        match idx {
            0 => [false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false],
            1 => [false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false],
            2 => [false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false],
            3 => [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false],
            4 => [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false],
            5 => [false, false, false, false, false, false, false, false, false, false, false, true, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false],
            6 => [false, false, false, false, false, false, false, false, false, false, false, true, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false],
            7 => [false, false, false, false, false, false, false, false, false, false, false, true, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false],
            8 => [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false],
            9 => [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false],
            _ => panic!("SetBLOCKS_X_BLOCKS index out of range! {:?}", idx)
        }
    }
}
impl RelLeftItem<{BLOCKS::VARIANTS}, BLOCKS, { BLOCKS::VARIANTS}, 10, 196> for BLOCKS {
    type RelEnum = BLOCKS_X_BLOCKS;
}
impl SetBLOCKS_X_BLOCKS {
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::SET_SET_A_B__B_C__L_A_TES_TES, 
            1 => Self::SET_SET_A_B__B_D__D_E__E_F__F_G__L_A_TES_TES, 
            2 => Self::SET_SET_A_B__B_D__D_K__J_N__K_J__L_A_TES_TES, 
            3 => Self::SET_SET_F_G__H_I__I_K__K_F__M_H_TES_TES, 
            4 => Self::SET_SET_H_I__I_J__J_N__M_H_TES_TES, 
            5 => Self::SET_SET_A_L__B_A__C_B_TES_TES, 
            6 => Self::SET_SET_A_L__B_A__D_B__E_D__F_E__G_F_TES_TES, 
            7 => Self::SET_SET_A_L__B_A__D_B__J_K__K_D__N_J_TES_TES, 
            8 => Self::SET_SET_F_K__G_F__H_M__I_H__K_I_TES_TES, 
            9 => Self::SET_SET_H_M__I_H__J_I__N_J_TES_TES, 
            _ => panic!("SetBLOCKS_X_BLOCKS index out of range! {:?}", idx)
        }
    }
}

impl SetItem<10> for SetBLOCKS_X_BLOCKS {
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
    R1_J = 9, 
    R1_K = 10, 
    R1_L = 11, 
    R1_M = 12, 
    R1_N = 13, 
    R2_A = 14, 
    R2_B = 15, 
    R2_C = 16, 
    R2_D = 17, 
    R2_E = 18, 
    R2_F = 19, 
    R2_G = 20, 
    R2_H = 21, 
    R2_I = 22, 
    R2_J = 23, 
    R2_K = 24, 
    R2_L = 25, 
    R2_M = 26, 
    R2_N = 27, 
    R3_A = 28, 
    R3_B = 29, 
    R3_C = 30, 
    R3_D = 31, 
    R3_E = 32, 
    R3_F = 33, 
    R3_G = 34, 
    R3_H = 35, 
    R3_I = 36, 
    R3_J = 37, 
    R3_K = 38, 
    R3_L = 39, 
    R3_M = 40, 
    R3_N = 41, 
    R4_A = 42, 
    R4_B = 43, 
    R4_C = 44, 
    R4_D = 45, 
    R4_E = 46, 
    R4_F = 47, 
    R4_G = 48, 
    R4_H = 49, 
    R4_I = 50, 
    R4_J = 51, 
    R4_K = 52, 
    R4_L = 53, 
    R4_M = 54, 
    R4_N = 55, 
    R5_A = 56, 
    R5_B = 57, 
    R5_C = 58, 
    R5_D = 59, 
    R5_E = 60, 
    R5_F = 61, 
    R5_G = 62, 
    R5_H = 63, 
    R5_I = 64, 
    R5_J = 65, 
    R5_K = 66, 
    R5_L = 67, 
    R5_M = 68, 
    R5_N = 69, 
    R6_A = 70, 
    R6_B = 71, 
    R6_C = 72, 
    R6_D = 73, 
    R6_E = 74, 
    R6_F = 75, 
    R6_G = 76, 
    R6_H = 77, 
    R6_I = 78, 
    R6_J = 79, 
    R6_K = 80, 
    R6_L = 81, 
    R6_M = 82, 
    R6_N = 83, 
    R7_A = 84, 
    R7_B = 85, 
    R7_C = 86, 
    R7_D = 87, 
    R7_E = 88, 
    R7_F = 89, 
    R7_G = 90, 
    R7_H = 91, 
    R7_I = 92, 
    R7_J = 93, 
    R7_K = 94, 
    R7_L = 95, 
    R7_M = 96, 
    R7_N = 97, 
    R8_A = 98, 
    R8_B = 99, 
    R8_C = 100, 
    R8_D = 101, 
    R8_E = 102, 
    R8_F = 103, 
    R8_G = 104, 
    R8_H = 105, 
    R8_I = 106, 
    R8_J = 107, 
    R8_K = 108, 
    R8_L = 109, 
    R8_M = 110, 
    R8_N = 111, 
    R9_A = 112, 
    R9_B = 113, 
    R9_C = 114, 
    R9_D = 115, 
    R9_E = 116, 
    R9_F = 117, 
    R9_G = 118, 
    R9_H = 119, 
    R9_I = 120, 
    R9_J = 121, 
    R9_K = 122, 
    R9_L = 123, 
    R9_M = 124, 
    R9_N = 125, 
    R10_A = 126, 
    R10_B = 127, 
    R10_C = 128, 
    R10_D = 129, 
    R10_E = 130, 
    R10_F = 131, 
    R10_G = 132, 
    R10_H = 133, 
    R10_I = 134, 
    R10_J = 135, 
    R10_K = 136, 
    R10_L = 137, 
    R10_M = 138, 
    R10_N = 139
}
type rel_ROUTES_X_BLOCKS = BRelation<ROUTES, { ROUTES::VARIANTS }, BLOCKS, { BLOCKS::VARIANTS }, 140>;
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
    A_R9 = 8, 
    A_R10 = 9, 
    B_R1 = 10, 
    B_R2 = 11, 
    B_R3 = 12, 
    B_R4 = 13, 
    B_R5 = 14, 
    B_R6 = 15, 
    B_R7 = 16, 
    B_R8 = 17, 
    B_R9 = 18, 
    B_R10 = 19, 
    C_R1 = 20, 
    C_R2 = 21, 
    C_R3 = 22, 
    C_R4 = 23, 
    C_R5 = 24, 
    C_R6 = 25, 
    C_R7 = 26, 
    C_R8 = 27, 
    C_R9 = 28, 
    C_R10 = 29, 
    D_R1 = 30, 
    D_R2 = 31, 
    D_R3 = 32, 
    D_R4 = 33, 
    D_R5 = 34, 
    D_R6 = 35, 
    D_R7 = 36, 
    D_R8 = 37, 
    D_R9 = 38, 
    D_R10 = 39, 
    E_R1 = 40, 
    E_R2 = 41, 
    E_R3 = 42, 
    E_R4 = 43, 
    E_R5 = 44, 
    E_R6 = 45, 
    E_R7 = 46, 
    E_R8 = 47, 
    E_R9 = 48, 
    E_R10 = 49, 
    F_R1 = 50, 
    F_R2 = 51, 
    F_R3 = 52, 
    F_R4 = 53, 
    F_R5 = 54, 
    F_R6 = 55, 
    F_R7 = 56, 
    F_R8 = 57, 
    F_R9 = 58, 
    F_R10 = 59, 
    G_R1 = 60, 
    G_R2 = 61, 
    G_R3 = 62, 
    G_R4 = 63, 
    G_R5 = 64, 
    G_R6 = 65, 
    G_R7 = 66, 
    G_R8 = 67, 
    G_R9 = 68, 
    G_R10 = 69, 
    H_R1 = 70, 
    H_R2 = 71, 
    H_R3 = 72, 
    H_R4 = 73, 
    H_R5 = 74, 
    H_R6 = 75, 
    H_R7 = 76, 
    H_R8 = 77, 
    H_R9 = 78, 
    H_R10 = 79, 
    I_R1 = 80, 
    I_R2 = 81, 
    I_R3 = 82, 
    I_R4 = 83, 
    I_R5 = 84, 
    I_R6 = 85, 
    I_R7 = 86, 
    I_R8 = 87, 
    I_R9 = 88, 
    I_R10 = 89, 
    J_R1 = 90, 
    J_R2 = 91, 
    J_R3 = 92, 
    J_R4 = 93, 
    J_R5 = 94, 
    J_R6 = 95, 
    J_R7 = 96, 
    J_R8 = 97, 
    J_R9 = 98, 
    J_R10 = 99, 
    K_R1 = 100, 
    K_R2 = 101, 
    K_R3 = 102, 
    K_R4 = 103, 
    K_R5 = 104, 
    K_R6 = 105, 
    K_R7 = 106, 
    K_R8 = 107, 
    K_R9 = 108, 
    K_R10 = 109, 
    L_R1 = 110, 
    L_R2 = 111, 
    L_R3 = 112, 
    L_R4 = 113, 
    L_R5 = 114, 
    L_R6 = 115, 
    L_R7 = 116, 
    L_R8 = 117, 
    L_R9 = 118, 
    L_R10 = 119, 
    M_R1 = 120, 
    M_R2 = 121, 
    M_R3 = 122, 
    M_R4 = 123, 
    M_R5 = 124, 
    M_R6 = 125, 
    M_R7 = 126, 
    M_R8 = 127, 
    M_R9 = 128, 
    M_R10 = 129, 
    N_R1 = 130, 
    N_R2 = 131, 
    N_R3 = 132, 
    N_R4 = 133, 
    N_R5 = 134, 
    N_R6 = 135, 
    N_R7 = 136, 
    N_R8 = 137, 
    N_R9 = 138, 
    N_R10 = 139
}
type rel_BLOCKS_X_ROUTES = BRelation<BLOCKS, { BLOCKS::VARIANTS }, ROUTES, { ROUTES::VARIANTS }, 140>;
//relation_declaration done

#[derive(Default, Debug)]pub struct Train_1_beebook_deterministic {
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
}


impl Train_1_beebook_deterministic {

    pub fn new() -> Train_1_beebook_deterministic {
        //values: ''
        let mut m: Train_1_beebook_deterministic = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        /*set_initializations*///set_initialization
    self._BLOCKS = bset![BLOCKS, /*enum_call*/BLOCKS::A, /*enum_call*/BLOCKS::B, /*enum_call*/BLOCKS::C, /*enum_call*/BLOCKS::D, /*enum_call*/BLOCKS::E, /*enum_call*/BLOCKS::F, /*enum_call*/BLOCKS::G, /*enum_call*/BLOCKS::H, /*enum_call*/BLOCKS::I, /*enum_call*/BLOCKS::J, /*enum_call*/BLOCKS::K, /*enum_call*/BLOCKS::L, /*enum_call*/BLOCKS::M, /*enum_call*/BLOCKS::N];
    //set_initialization
    self._ROUTES = bset![ROUTES, /*enum_call*/ROUTES::R1, /*enum_call*/ROUTES::R2, /*enum_call*/ROUTES::R3, /*enum_call*/ROUTES::R4, /*enum_call*/ROUTES::R5, /*enum_call*/ROUTES::R6, /*enum_call*/ROUTES::R7, /*enum_call*/ROUTES::R8, /*enum_call*/ROUTES::R9, /*enum_call*/ROUTES::R10];
        /*properties*///constant_initialization
    self.nxt = brel![rel_ROUTES_X_SetBLOCKS_X_BLOCKS, (/*enum_call*/ROUTES::R1.clone(), brel![rel_BLOCKS_X_BLOCKS, (/*enum_call*/BLOCKS::L.clone(), /*enum_call*/BLOCKS::A.clone()), (/*enum_call*/BLOCKS::A.clone(), /*enum_call*/BLOCKS::B.clone()), (/*enum_call*/BLOCKS::B.clone(), /*enum_call*/BLOCKS::C.clone())].clone()), (/*enum_call*/ROUTES::R2.clone(), brel![rel_BLOCKS_X_BLOCKS, (/*enum_call*/BLOCKS::L.clone(), /*enum_call*/BLOCKS::A.clone()), (/*enum_call*/BLOCKS::A.clone(), /*enum_call*/BLOCKS::B.clone()), (/*enum_call*/BLOCKS::B.clone(), /*enum_call*/BLOCKS::D.clone()), (/*enum_call*/BLOCKS::D.clone(), /*enum_call*/BLOCKS::E.clone()), (/*enum_call*/BLOCKS::E.clone(), /*enum_call*/BLOCKS::F.clone()), (/*enum_call*/BLOCKS::F.clone(), /*enum_call*/BLOCKS::G.clone())].clone()), (/*enum_call*/ROUTES::R3.clone(), brel![rel_BLOCKS_X_BLOCKS, (/*enum_call*/BLOCKS::L.clone(), /*enum_call*/BLOCKS::A.clone()), (/*enum_call*/BLOCKS::A.clone(), /*enum_call*/BLOCKS::B.clone()), (/*enum_call*/BLOCKS::B.clone(), /*enum_call*/BLOCKS::D.clone()), (/*enum_call*/BLOCKS::D.clone(), /*enum_call*/BLOCKS::K.clone()), (/*enum_call*/BLOCKS::K.clone(), /*enum_call*/BLOCKS::J.clone()), (/*enum_call*/BLOCKS::J.clone(), /*enum_call*/BLOCKS::N.clone())].clone()), (/*enum_call*/ROUTES::R4.clone(), brel![rel_BLOCKS_X_BLOCKS, (/*enum_call*/BLOCKS::M.clone(), /*enum_call*/BLOCKS::H.clone()), (/*enum_call*/BLOCKS::H.clone(), /*enum_call*/BLOCKS::I.clone()), (/*enum_call*/BLOCKS::I.clone(), /*enum_call*/BLOCKS::K.clone()), (/*enum_call*/BLOCKS::K.clone(), /*enum_call*/BLOCKS::F.clone()), (/*enum_call*/BLOCKS::F.clone(), /*enum_call*/BLOCKS::G.clone())].clone()), (/*enum_call*/ROUTES::R5.clone(), brel![rel_BLOCKS_X_BLOCKS, (/*enum_call*/BLOCKS::M.clone(), /*enum_call*/BLOCKS::H.clone()), (/*enum_call*/BLOCKS::H.clone(), /*enum_call*/BLOCKS::I.clone()), (/*enum_call*/BLOCKS::I.clone(), /*enum_call*/BLOCKS::J.clone()), (/*enum_call*/BLOCKS::J.clone(), /*enum_call*/BLOCKS::N.clone())].clone()), (/*enum_call*/ROUTES::R6.clone(), brel![rel_BLOCKS_X_BLOCKS, (/*enum_call*/BLOCKS::C.clone(), /*enum_call*/BLOCKS::B.clone()), (/*enum_call*/BLOCKS::B.clone(), /*enum_call*/BLOCKS::A.clone()), (/*enum_call*/BLOCKS::A.clone(), /*enum_call*/BLOCKS::L.clone())].clone()), (/*enum_call*/ROUTES::R7.clone(), brel![rel_BLOCKS_X_BLOCKS, (/*enum_call*/BLOCKS::G.clone(), /*enum_call*/BLOCKS::F.clone()), (/*enum_call*/BLOCKS::F.clone(), /*enum_call*/BLOCKS::E.clone()), (/*enum_call*/BLOCKS::E.clone(), /*enum_call*/BLOCKS::D.clone()), (/*enum_call*/BLOCKS::D.clone(), /*enum_call*/BLOCKS::B.clone()), (/*enum_call*/BLOCKS::B.clone(), /*enum_call*/BLOCKS::A.clone()), (/*enum_call*/BLOCKS::A.clone(), /*enum_call*/BLOCKS::L.clone())].clone()), (/*enum_call*/ROUTES::R8.clone(), brel![rel_BLOCKS_X_BLOCKS, (/*enum_call*/BLOCKS::N.clone(), /*enum_call*/BLOCKS::J.clone()), (/*enum_call*/BLOCKS::J.clone(), /*enum_call*/BLOCKS::K.clone()), (/*enum_call*/BLOCKS::K.clone(), /*enum_call*/BLOCKS::D.clone()), (/*enum_call*/BLOCKS::D.clone(), /*enum_call*/BLOCKS::B.clone()), (/*enum_call*/BLOCKS::B.clone(), /*enum_call*/BLOCKS::A.clone()), (/*enum_call*/BLOCKS::A.clone(), /*enum_call*/BLOCKS::L.clone())].clone()), (/*enum_call*/ROUTES::R9.clone(), brel![rel_BLOCKS_X_BLOCKS, (/*enum_call*/BLOCKS::G.clone(), /*enum_call*/BLOCKS::F.clone()), (/*enum_call*/BLOCKS::F.clone(), /*enum_call*/BLOCKS::K.clone()), (/*enum_call*/BLOCKS::K.clone(), /*enum_call*/BLOCKS::I.clone()), (/*enum_call*/BLOCKS::I.clone(), /*enum_call*/BLOCKS::H.clone()), (/*enum_call*/BLOCKS::H.clone(), /*enum_call*/BLOCKS::M.clone())].clone()), (/*enum_call*/ROUTES::R10.clone(), brel![rel_BLOCKS_X_BLOCKS, (/*enum_call*/BLOCKS::N.clone(), /*enum_call*/BLOCKS::J.clone()), (/*enum_call*/BLOCKS::J.clone(), /*enum_call*/BLOCKS::I.clone()), (/*enum_call*/BLOCKS::I.clone(), /*enum_call*/BLOCKS::H.clone()), (/*enum_call*/BLOCKS::H.clone(), /*enum_call*/BLOCKS::M.clone())].clone())];
    //constant_initialization
    self.fst = brel![rel_ROUTES_X_BLOCKS, (/*enum_call*/ROUTES::R1.clone(), /*enum_call*/BLOCKS::L.clone()), (/*enum_call*/ROUTES::R2.clone(), /*enum_call*/BLOCKS::L.clone()), (/*enum_call*/ROUTES::R3.clone(), /*enum_call*/BLOCKS::L.clone()), (/*enum_call*/ROUTES::R4.clone(), /*enum_call*/BLOCKS::M.clone()), (/*enum_call*/ROUTES::R5.clone(), /*enum_call*/BLOCKS::M.clone()), (/*enum_call*/ROUTES::R6.clone(), /*enum_call*/BLOCKS::C.clone()), (/*enum_call*/ROUTES::R7.clone(), /*enum_call*/BLOCKS::G.clone()), (/*enum_call*/ROUTES::R8.clone(), /*enum_call*/BLOCKS::N.clone()), (/*enum_call*/ROUTES::R9.clone(), /*enum_call*/BLOCKS::G.clone()), (/*enum_call*/ROUTES::R10.clone(), /*enum_call*/BLOCKS::N.clone())];
    //constant_initialization
    self.lst = brel![rel_ROUTES_X_BLOCKS, (/*enum_call*/ROUTES::R1.clone(), /*enum_call*/BLOCKS::C.clone()), (/*enum_call*/ROUTES::R2.clone(), /*enum_call*/BLOCKS::G.clone()), (/*enum_call*/ROUTES::R3.clone(), /*enum_call*/BLOCKS::N.clone()), (/*enum_call*/ROUTES::R4.clone(), /*enum_call*/BLOCKS::G.clone()), (/*enum_call*/ROUTES::R5.clone(), /*enum_call*/BLOCKS::N.clone()), (/*enum_call*/ROUTES::R6.clone(), /*enum_call*/BLOCKS::L.clone()), (/*enum_call*/ROUTES::R7.clone(), /*enum_call*/BLOCKS::L.clone()), (/*enum_call*/ROUTES::R8.clone(), /*enum_call*/BLOCKS::L.clone()), (/*enum_call*/ROUTES::R9.clone(), /*enum_call*/BLOCKS::M.clone()), (/*enum_call*/ROUTES::R10.clone(), /*enum_call*/BLOCKS::M.clone())];
    //constant_initialization
    let mut _ic_set_0 = rel_BLOCKS_X_ROUTES::empty();
    //iteration_construct_enumeration
    for _ic_b_1 in self._BLOCKS.clone().iter() {
        //iteration_construct_enumeration
        for _ic_r_1 in self._ROUTES.clone().iter() {
            //set_comprehension_predicate
            if (self.nxt.domain().elementOf(&_ic_r_1) && (self.nxt.functionCall(&_ic_r_1).domain().elementOf(&_ic_b_1) || self.nxt.functionCall(&_ic_r_1).range().elementOf(&_ic_b_1))) {
                _ic_set_0 = _ic_set_0.union(&brel![rel_BLOCKS_X_ROUTES, (_ic_b_1.clone(), _ic_r_1.clone())]);
            }

        }
    }
    self.rtbl = _ic_set_0;
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
}


