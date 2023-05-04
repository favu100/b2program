#![ allow( dead_code ) ]


use crate::bset::{BSet, SetItem};

pub type BBoolean = bool;

impl SetItem<2> for BBoolean {
    fn from_idx(idx: usize) -> Self {
        match idx {
            0 => false,
            1 => true,
            _ => panic!("Bool index {:?} out of range!", idx)
        }
    }
    fn as_idx(&self) -> usize {
        if *self { 1 } else { 0 }
    }
}

pub const BOOL: BSet<bool, 2> = BSet::full();//BSet::const_from_arr([true, true]);

pub trait BBool {
    fn new(val: bool) -> BBoolean;
    fn equal(&self, other: &Self) -> bool;
    fn or(&self, other: &Self) -> Self;
    fn xor(&self, other: &Self) -> Self;
    fn and(&self, other: &Self) -> Self;
    fn not(&self) -> Self;
    fn implies<F: FnOnce() -> bool>(&self, other: F) -> Self;
    fn equivalent(&self, other: &Self) -> Self;
    fn unequal(&self, other: &Self) -> Self;
}

impl BBool for bool {
    fn new(val: bool) -> BBoolean { val }
    fn equal(&self, other: &Self) -> bool { *self == *other }
    fn or(&self, other: &Self) -> Self { *self || *other }
    fn xor(&self, other: &Self) -> Self { *self ^ *other }
    fn and(&self, other: &Self) -> Self { *self && *other }
    fn not(&self) -> Self { !*self }
    fn implies<F: FnOnce() -> bool>(&self, other: F) -> Self { !*self || other() }
    fn equivalent(&self, other: &Self) -> Self { *self == *other }
    fn unequal(&self, other: &Self) -> Self { *self != *other }
}