use crate::bobject::BObject;

pub type BBoolean = bool;

pub trait IntoBool {
    #![allow(non_snake_case)]
    fn booleanValue(&self) -> bool;
}

pub trait BBooleanT: BObject + IntoBool + Copy {
    fn new(val: bool) -> Self;
    fn or(&self, other: &Self) -> Self;
    fn xor(&self, other: &Self) -> Self;
    fn and(&self, other: &Self) -> Self;
    fn not(&self) -> Self;
    fn implies<F: FnOnce() -> bool>(&self, other: F) -> Self;
    fn equivalent(&self, other: &Self) -> Self;
    fn equal(&self, other: &Self) -> Self;
    fn unequal(&self, other: &Self) -> Self;
}

impl IntoBool for bool {
    fn booleanValue(&self) -> bool {
        return *self;
    }
}

impl BObject for bool {}

impl BBooleanT for bool {
    fn new(val: bool) -> Self { val }
    fn or(&self, other: &Self) -> Self { *self || *other }
    fn xor(&self, other: &Self) -> Self { *self ^ *other }
    fn and(&self, other: &Self) -> Self { *self && *other }
    fn not(&self) -> Self { !*self }
    fn implies<F: FnOnce() -> bool>(&self, other: F) -> Self { !*self || other() }
    fn equivalent(&self, other: &Self) -> Self { *self == *other }
    fn equal(&self, other: &Self) -> Self { *self == *other }
    fn unequal(&self, other: &Self) -> Self { *self != *other }
}
