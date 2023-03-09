#![allow(non_snake_case)]

use core::convert::TryInto;

pub type BInteger = i128;

pub trait BInt {
    fn equal(&self, other: &Self) -> bool;
    fn unequal(&self, other: &Self) -> bool;

    fn greater(&self, other: &Self) -> bool;
    fn greaterEqual(&self, other: &Self) -> bool;
    fn less(&self, other: &Self) -> bool;
    fn lessEqual(&self, other: &Self) -> bool;

    fn plus(&self, other: &Self) -> Self;
    fn minus(&self, other: &Self) -> Self;
    fn multiply(&self, other: &Self) -> Self;
    fn divide(&self, other: &Self) -> Self;
    fn modulo(&self, other: &Self) -> Self;
    fn power(&self, exp: &Self) -> Self;

    fn negative(&self) -> Self;
    fn pred(&self) -> Self;
    fn succ(&self) -> Self;
}

impl BInt for BInteger {
    fn equal(&self, other: &Self) -> bool { self.eq(&other) }
    fn unequal(&self, other: &Self) -> bool { !self.eq(&other) }

    fn greater(&self, other: &Self) -> bool { self > other }
    fn greaterEqual(&self, other: &Self) -> bool { self >= other }
    fn less(&self, other: &Self) -> bool { self < other }
    fn lessEqual(&self, other: &Self) -> bool { self <= other }

    fn plus(&self, other: &Self) -> Self { self + other }
    fn minus(&self, other: &Self) -> Self { self - other }
    fn multiply(&self, other: &Self) -> Self { self * other }
    fn divide(&self, other: &Self) -> Self { self / other }
    fn modulo(&self, other: &Self) -> Self { self % other }
    fn power(&self, exp: &Self) -> Self {
        if exp < &0 { panic!("Power with negative exponent!") }
        let u32_exp: u32 = exp.unsigned_abs().try_into().unwrap();
        return self.pow(u32_exp);
    }

    fn negative(&self) -> Self { -self }
    fn pred(&self) -> Self { self - 1 }
    fn succ(&self) -> Self { self + 1 }
}