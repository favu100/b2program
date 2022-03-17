use std::convert::TryInto;
use crate::bboolean::{BBoolean, BBooleanT};
use crate::bobject::BObject;

use std::fmt;
use std::hash::Hash;

pub trait BInt: BObject { fn get_binteger_value(&self) -> BInteger { panic!("get_integer_value not implemented!"); }}
pub trait FromBInt { fn from<T: BInt>(value: &T) -> Self; }

#[derive(Default, Debug, Copy, Clone, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub struct BInteger {
    val: i64,
}

impl BObject for BInteger {}
impl BInt for BInteger {
    fn get_binteger_value(&self) -> BInteger { return *self; }
}

impl FromBInt for BInteger {
    fn from<T: BInt>(value: &T) -> Self {
        return value.get_binteger_value();
    }
}

impl BInteger {
    #![allow(non_snake_case, dead_code)]

    pub const fn new(init: i64) -> BInteger {
        return BInteger {
            val: init,
        }
    }

    pub fn get_val(&self) -> i64 { return self.val; }

    pub fn compareTo(&self, o: &BInteger) -> i64 {
        return self.val - o.val;
    }

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
        return BInteger::new(self.val + v.val);
    }

    pub fn minus(&self, v: &BInteger) -> BInteger {
        return BInteger::new(self.val - v.val);
    }

    pub fn multiply(&self, v: &BInteger) -> BInteger {
        return BInteger::new(self.val * v.val);
    }

    pub fn power(&self, v: &BInteger) -> BInteger {
        if v.val < 0 { panic!("Power with negative exponent!") }
        let exp: u32 = v.val.unsigned_abs().try_into().unwrap();
        return BInteger::new(self.val.pow(exp));
    }

    pub fn divide(&self, v: &BInteger) -> BInteger {
        return BInteger::new(self.val / v.val);
    }

    pub fn modulo(&self, v: &BInteger) -> BInteger {
        //return BInteger::new(self.val.rem_euclid(v.val));
        return BInteger::new(self.val % v.val);
    }

    pub fn succ(&self) -> BInteger {
        return BInteger::new(self.val + 1);
    }

    pub fn pred(&self) -> BInteger {
        return BInteger::new(self.val - 1);
    }

    pub fn negative(&self) -> BInteger {
        return BInteger::new(-self.val);
    }

    pub fn positive(&self) -> BInteger {
        return *self;
    }

    pub fn isInteger(&self) -> BBoolean {
        return BBoolean::new(true);
    }

    pub fn isNotInteger(&self) -> BBoolean {
        return BBoolean::new(false);
    }

    pub fn isNatural(&self) -> BBoolean {
        return BBoolean::new(self.val >= 0);
    }

    pub fn isNotNatural(&self) -> BBoolean {
        return BBoolean::new(self.val < 0);
    }

    pub fn isNatural1(&self) -> BBoolean {
        return BBoolean::new(self.val > 0);
    }

    pub fn isNotNatural1(&self) -> BBoolean {
        return BBoolean::new(self.val < 1);
    }
}

impl fmt::Display for BInteger {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{}", self.val)
    }
}