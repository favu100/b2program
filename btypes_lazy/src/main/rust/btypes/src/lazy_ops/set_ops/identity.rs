use crate::bobject::BObject;
use crate::bset::BSet;
use crate::lazy_ops::set_ops::setops::{SetOp, SetOpTraits};

use std::fmt;
use std::fmt::{Debug, Formatter};
use std::marker::PhantomData;


#[derive(Clone)]
pub struct Identity<T: BObject> {
    phantom: PhantomData<T>,
}

impl<T: BObject> Identity<T> {
    const OP_NAME: &'static str = "Identity";
}

impl<T: BObject> Debug for Identity<T> {
    fn fmt(&self, f: &mut Formatter<'_>) -> fmt::Result {
        write!(f, "Identity()")
    }
}

impl<T: 'static +  BObject> SetOp for Identity<T> {

    fn compute(&self, lhs: &BSet<T>) -> BSet<T> {
        lhs.clone()
    }

    fn clone_box(&self) -> Box<dyn SetOp<Item=Self::Item>> {
        Box::new(Identity{phantom: PhantomData})
    }

    fn get_op_name(&self) -> &str {
        return Identity::<T>::OP_NAME;
    }

    fn get_rhs(&self) -> Option<Box<dyn SetOp<Item=Self::Item>>> {
        return Option::None;
    }
}

impl<T: 'static +  BObject> SetOpTraits for Identity<T>{
    type Item = T;

    fn contains_lazy(&self, lhs: &BSet<Self::Item>, o: &Self::Item) -> bool { lhs.contains_directly(o) }
    fn is_empty_lazy(&self, lhs: &BSet<Self::Item>) -> bool { lhs.is_empty_directly() }
    fn size_lazy(&self, lhs: &BSet<Self::Item>) -> usize { lhs.size_directly() }
}