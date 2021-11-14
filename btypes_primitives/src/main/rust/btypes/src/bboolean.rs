use std::hash::Hash;
use crate::bobject::BObject;
use std::fmt;

#[derive(Default, Debug, Copy, Clone, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub struct BBoolean {
    val: bool,
}

impl fmt::Display for BBoolean {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{}", self.val)
    }
}

impl BObject for BBoolean {}

impl BBoolean {
    #![allow(non_snake_case, dead_code)]

    pub const fn new(v: bool) -> BBoolean {
        return BBoolean {
            val: v,
        }
    }

    pub fn booleanValue(&self) -> bool {
        return self.val;
    }

    pub fn or(&self, other: &BBoolean) -> BBoolean {
        return BBoolean::new(self.val || other.val);
    }

    pub fn xor(&self, other: &BBoolean) -> BBoolean {
        return BBoolean::new(self.val ^ other.val);
    }

    pub fn and(&self, other: &BBoolean) -> BBoolean {
        return BBoolean::new(self.val && other.val);
    }

    pub fn not(&self) -> BBoolean {
        return BBoolean::new(!self.val);
    }

    pub fn implies(&self, other: &BBoolean) -> BBoolean {
        return BBoolean::new(!self.val || other.val);
    }

    pub fn equivalent(&self, other: &BBoolean) -> BBoolean {
        return BBoolean::new(self.val == other.val);
    }

    pub fn equal(&self, other: &BBoolean) -> BBoolean {
        return BBoolean::new(self.val == other.val);
    }

    pub fn unequal(&self, other: &BBoolean) -> BBoolean {
        return BBoolean::new(self.val != other.val);
    }
}