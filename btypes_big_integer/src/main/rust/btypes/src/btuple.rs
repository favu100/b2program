use crate::bobject::BObject;
use std::fmt;

#[derive(Default, Debug, Copy, Clone, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub struct BTuple<L: BObject, R: BObject>{
    left_val: L,
    right_val: R,
}

impl<L: BObject, R: BObject> fmt::Display for BTuple<L, R> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        return write!(f, "({} |-> {})", self.left_val, self.right_val);
    }
}

impl<L: BObject, R:BObject> BObject for BTuple<L, R>{}

impl<L: BObject, R: BObject> BTuple<L, R> {
    pub fn new(left: L, right: R) -> BTuple<L, R> {
        return BTuple {left_val: left, right_val: right,};
    }

    pub fn from_refs(left: &L, right: &R) -> BTuple<L, R> {
        return BTuple {left_val: left.clone(), right_val: right.clone(),};
    }

    pub fn projection1(&self) -> L {
        return self.left_val.clone();
    }

    pub fn projection2(&self) -> R {
        return self.right_val.clone();
    }

}
