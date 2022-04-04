use std::cell::RefCell;
use std::convert::TryInto;
use crate::bobject::BObject;
use crate::bset::BSet;
use crate::lazy_ops::set_ops::setops::{SetOp, SetOpTraits};

use std::fmt;
use std::fmt::{Debug, Formatter};
use std::iter::Chain;
use std::ops::Not;
use im::ordset::Iter;

#[derive(Clone)]
pub struct Union<T: BObject> {
    rhs: RefCell<BSet<T>>,
    rhs_is_reduced: RefCell<bool>,
}

impl<T: BObject> Union<T> {
    const OP_NAME: &'static str = "Union";
}

impl<T: 'static + BObject> Debug for Union<T> {
    fn fmt(&self, f: &mut Formatter<'_>) -> fmt::Result {
        write!(f, "Union({})", self.rhs.borrow())
    }
}

impl<T: BObject> Union<T> {
    pub fn new(rhs: BSet<T>) -> Union<T> {
        Union {rhs: RefCell::new(rhs), rhs_is_reduced: RefCell::new(false)}
    }
}

impl<T: 'static +  BObject> SetOpTraits for Union<T>{
    type Item = T;

    fn iter_lazy(&self, lhs: &BSet<Self::Item>) -> Chain<Iter<T>, Iter<T>> {
        return lhs.iter_directly().chain(self.rhs.borrow().iter());
    }

    fn contains_lazy(&self, lhs: &BSet<Self::Item>, o: &Self::Item) -> bool {
        lhs.contains_directly(o) || self.rhs.borrow().contains_directly(o)
    }

    fn is_empty_lazy(&self, lhs: &BSet<Self::Item>) -> bool {
        lhs.is_empty_directly() && self.rhs.borrow().is_empty_directly()
    }

    fn size_lazy(&self, lhs: &BSet<Self::Item>) -> usize {
        if (*self.rhs_is_reduced.borrow()).not() {
            let new_rhs = self.rhs.borrow().difference(lhs);
            self.rhs.replace(new_rhs);
            self.rhs_is_reduced.replace(true);
        }
        return lhs.size_directly() + self.rhs.borrow().size_directly();
    }
}

impl<T: 'static +  BObject> SetOp for Union<T> {
    fn compute(&self, lhs: &BSet<T>) -> BSet<T> {
        lhs.real_union(&self.rhs.borrow())
    }

    fn clone_box(&self) -> Box<dyn SetOp<Item=Self::Item>> {
        Box::new(Union{rhs: RefCell::new(self.rhs.borrow().clone()),
                          rhs_is_reduced: RefCell::new(*self.rhs_is_reduced.borrow())})
    }

    fn get_op_name(&self) -> &str {
        return Union::<T>::OP_NAME;
    }

    fn get_rhs(&self) -> Option<Box<dyn SetOp<Item=Self::Item>>> {
        return Option::Some(self.rhs.borrow().clone_box());
    }
}