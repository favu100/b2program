use std::cell::RefCell;
use crate::bobject::BObject;
use crate::bset::BSet;
use crate::lazy_ops::set_ops::setops::{IterWrapper, SetOp, SetOpTraits};

use std::fmt;
use std::fmt::{Debug, Formatter};
use std::ops::Not;

#[derive(Clone)]
pub struct Union<T: BObject> {
    rhs: BSet<T>,
    rhs_is_reduced: bool,
}

impl<T: BObject> Union<T> {
    const OP_NAME: &'static str = "Union";
}

impl<T: 'static + BObject> Debug for Union<T> {
    fn fmt(&self, f: &mut Formatter<'_>) -> fmt::Result {
        write!(f, "Union({})", self.rhs)
    }
}

impl<T: BObject> Union<T> {
    pub fn new(rhs: BSet<T>) -> Union<T> {
        Union {rhs: rhs, rhs_is_reduced: false}
    }
}

impl<T: 'static +  BObject> Union<T> {
    fn check_reduced(&mut self, lhs: &BSet<T>) {
        if !self.rhs_is_reduced {
            let new_rhs = self.rhs.difference(&lhs.get_direct_set());
            self.rhs = new_rhs;
            self.rhs_is_reduced = true;
        }
    }
}

impl<T: 'static +  BObject> SetOpTraits for Union<T>{
    type Item = T;

    fn iter_lazy<'a>(&'a self, lhs: &'a BSet<Self::Item>) -> IterWrapper<'a, T> {
        //self.check_reduced(lhs); <-- would need me to make this function take &mut self, which would propagate to BSet::iter, which would break everything...
        let iter_a = IterWrapper::single(lhs.iter_directly());
        let iter_b = self.rhs.iter_complete();
        if self.rhs_is_reduced {
            return IterWrapper::chain(iter_a, iter_b);
        }
        return IterWrapper::chain(iter_a, IterWrapper::filtered(iter_b, lhs.get_direct_set()));
    }

    fn contains_lazy(&self, lhs: &BSet<Self::Item>, o: &Self::Item) -> bool {
        lhs.contains_directly(o) || self.rhs.contains(o)
    }

    fn is_empty_lazy(&self, lhs: &BSet<Self::Item>) -> bool {
        lhs.is_empty_directly() && self.rhs.isEmpty()
    }

    fn size_lazy(&self, lhs: &BSet<Self::Item>) -> usize {
        if self.rhs_is_reduced {
            return lhs.size_directly() + self.rhs.size();
        }
        return lhs.size_directly() + self.rhs.difference(&lhs.get_direct_set()).size();
    }
}

impl<T: 'static +  BObject> SetOp for Union<T> {
    fn compute(&self, lhs: &BSet<T>) -> BSet<T> {
        lhs.real_union(&self.rhs)
    }

    fn clone_box(&self) -> Box<dyn SetOp<Item=Self::Item>> {
        Box::new(Union{rhs: self.rhs.clone(),
                          rhs_is_reduced: self.rhs_is_reduced})
    }

    fn get_op_name(&self) -> &str {
        return Union::<T>::OP_NAME;
    }

    fn get_rhs(&self) -> Option<Box<dyn SetOp<Item=Self::Item>>> {
        return Option::Some(self.rhs.clone_box());
    }
}