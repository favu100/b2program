use std::fmt::{Display, Formatter};
use crate::bobject::BObject;
use crate::bboolean::BBoolean;

#[derive(Default, Debug, Clone, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub struct BString {
    val: String,
}

pub trait TBString {}

impl TBString for BString {}

impl Display for BString {
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", self.val)
    }
}

impl BObject for BString {}

impl BString {
    #![allow(non_snake_case, dead_code)]

    pub fn new(init: &str) -> BString {
        return BString { val: String::from(init) }
    }

    pub fn isString(&self) -> BBoolean {
        return true;
    }

    pub fn isNotString(&self) -> BBoolean {
        return false;
    }

    pub fn equal(&self, other: &BString) -> BBoolean {
        return self.eq(other);
    }

    pub fn unequal(&self, other: &BString) -> BBoolean {
        return !self.eq(other);
    }
}
