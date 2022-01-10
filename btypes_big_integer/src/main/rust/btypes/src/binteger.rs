use crate::bboolean::BBoolean;
use crate::bobject::BObject;

use num_bigint::{BigInt, BigUint};
use num_traits::pow::Pow;
use core::ops::Rem;
use std::fmt;
use std::hash::Hash;
use std::ops::{Neg};

pub trait BInt: BObject { fn get_binteger_value(&self) -> BInteger { panic!("get_integer_value not implemented!"); }}
pub trait FromBInt { fn from<T: BInt>(value: &T) -> Self; }

#[derive(Default, Debug, Clone, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub struct BInteger {
    val: BigInt,
}

impl BObject for BInteger {}
impl BInt for BInteger {
    fn get_binteger_value(&self) -> BInteger { return self.clone(); }
}

impl FromBInt for BInteger {
    fn from<T: BInt>(value: &T) -> Self {
        return value.get_binteger_value();
    }
}

impl BInteger {
    #![allow(non_snake_case, dead_code)]

    pub fn new(init: &[u8]) -> BInteger {
        return BInteger {
            val: BigInt::parse_bytes(init, 10).unwrap(),
        }
    }

    pub const fn new_from_bigint(init: BigInt) -> BInteger {
        return BInteger {
            val: init,
        }
    }

    pub fn get_val(&self) -> BigInt { return self.val.clone(); }

    pub fn lessEqual(&self, o: &BInteger) -> BBoolean {
        return BBoolean::new(self.val <= o.val);
    }

    pub fn greaterEqual(&self, o: &BInteger) -> BBoolean {
        return BBoolean::new(self.val >= o.val);
    }

    pub fn less(&self, o: &BInteger) -> BBoolean {
        return BBoolean::new(self.val < o.val);
    }

    pub fn greater(&self, o: &BInteger) -> BBoolean {
        return BBoolean::new(self.val > o.val);
    }

    pub fn equal(&self, o: &BInteger) -> BBoolean {
        return BBoolean::new(self.val == o.val);
    }

    pub fn unequal(&self, o: &BInteger) -> BBoolean {
        return BBoolean::new(self.val != o.val);
    }

    pub fn plus(&self, v: &BInteger) -> BInteger {
        return BInteger::new_from_bigint(&self.val + v.val.clone());
    }

    pub fn minus(&self, v: &BInteger) -> BInteger {
        return BInteger::new_from_bigint(&self.val - v.val.clone());
    }

    pub fn multiply(&self, v: &BInteger) -> BInteger {
        return BInteger::new_from_bigint(&self.val * v.val.clone());
    }

    pub fn power(&self, v: &BInteger) -> BInteger {
        if v.val.sign() == num_bigint::Sign::Minus { panic!("Power with negative exponent!") }
        return BInteger::new_from_bigint(Pow::<BigUint>::pow(&self.val, v.val.to_biguint().unwrap()));
    }

    pub fn divide(&self, v: &BInteger) -> BInteger {
        return BInteger::new_from_bigint(&self.val / v.val.clone());
    }

    pub fn modulo(&self, v: &BInteger) -> BInteger {
        return BInteger::new_from_bigint(Rem::rem(&self.val, v.val.clone()));
    }

    pub fn succ(&self) -> BInteger {
        return BInteger::new_from_bigint(&self.val + BigInt::from(1));
    }

    pub fn inc(&mut self) {
        self.val = &self.val + BigInt::from(1);
    }

    pub fn pred(&self) -> BInteger {
        return BInteger::new_from_bigint(&self.val - BigInt::from(1));
    }

    pub fn negative(&self) -> BInteger {
        return BInteger::new_from_bigint((&self.val).neg());
    }

    pub fn positive(&self) -> BInteger {
        return self.clone();
    }

    pub fn isInteger() -> BBoolean {
        return BBoolean::new(true);
    }

    pub fn isNotInteger() -> BBoolean {
        return BBoolean::new(false);
    }

    pub fn isNatural(&self) -> BBoolean {
        return BBoolean::new(self.val.sign() != num_bigint::Sign::Minus);
    }

    pub fn isNotNatural(&self) -> BBoolean {
        return BBoolean::new(self.val.sign() == num_bigint::Sign::Minus);
    }

    pub fn isNatural1(&self) -> BBoolean {
        return BBoolean::new(self.val.sign() == num_bigint::Sign::Plus);
    }

    pub fn isNotNatural1(&self) -> BBoolean {
        return BBoolean::new(self.val.sign() != num_bigint::Sign::Plus);
    }
}

impl fmt::Display for BInteger {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{}", self.val)
    }
}