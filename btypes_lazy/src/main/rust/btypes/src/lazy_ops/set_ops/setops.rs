use std::cmp::Ordering;
use std::fmt;
use std::fmt::{Debug, Formatter};
use std::marker::PhantomData;
use crate::bobject::BObject;
use crate::bset::BSet;

pub trait SetOp: SetOpTraits + Debug {
    type Item: BObject;

    fn compute(&self, lhs: &BSet<Self::Item>) -> BSet<Self::Item>;
    fn clone_box(&self) -> Box<dyn SetOp<Item = Self::Item>>;

    //PartialEq
    fn eq(&self, other: &Box<dyn SetOp<Item = Self::Item>>) -> bool;

    //PartialOrd
    fn partial_cmp(&self, other: &Box<dyn SetOp<Item = Self::Item>>) -> Option<Ordering>;

    //Ord
    fn cmp(&self, other: &Box<dyn SetOp<Item = Self::Item>>) -> Ordering;
    fn max(&self, other: &Box<dyn SetOp<Item = Self::Item>>) -> Box<dyn SetOp<Item = Self::Item>>;
    fn min(&self, other: &Box<dyn SetOp<Item = Self::Item>>) -> Box<dyn SetOp<Item = Self::Item>>;
    fn clamp(&self, min: &Box<dyn SetOp<Item = Self::Item>>, max: &Box<dyn SetOp<Item = Self::Item>>) -> Box<dyn SetOp<Item = Self::Item>>;
}

pub trait SetOpTraits {
    //type Bla: BObject;

    //fn clone_box(&self) -> Box<dyn SetOp<Item = Self::Bla>>;
    //fn default_box() -> Box<dyn SetOp>;
}
/*
impl<T> SetOpTraits for T
where T: 'static + SetOp + Clone,
{
    fn clone_box<S: BObject>(&self) -> Box<dyn SetOp<Item = S>> {
        Box::new(self.clone())
    }
}
*/
impl<T: BObject> Clone for Box<dyn SetOp<Item = T>> {
    fn clone(&self) -> Self {
        self.clone_box()
    }
}

impl<T: BObject> Eq for Box<dyn SetOp<Item=T>> {}

impl<T: BObject> PartialEq<Self> for Box<dyn SetOp<Item=T>> {
    fn eq(&self, other: &Self) -> bool {
        self.eq(other)
    }
}

impl<T: BObject> PartialOrd<Self> for Box<dyn SetOp<Item=T>> {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        self.partial_cmp(other)
    }
}

impl<T: BObject> Ord for Box<dyn SetOp<Item = T>> {
    fn cmp(&self, other: &Self) -> Ordering {
        self.cmp(other)
    }
}

impl<T: 'static +  BObject> dyn SetOp<Item = T> {
    fn default() -> Box<Self> {
        Box::new(Identity {phantom: PhantomData})
    }
}






#[derive(Clone)]
pub struct Identity<T: BObject> {
    phantom: PhantomData<T>,
}

impl<T: BObject> Debug for Identity<T> {
    fn fmt(&self, f: &mut Formatter<'_>) -> fmt::Result {
        write!(f, "Identity()")
    }
}

impl<T: 'static +  BObject> SetOp for Identity<T> {
    type Item = T;

    fn compute(&self, lhs: &BSet<T>) -> BSet<T> {
        lhs.clone()
    }

    fn clone_box(&self) -> Box<dyn SetOp<Item=Self::Item>> {
        Box::new(Identity{phantom: PhantomData})
    }
}

impl<T: 'static +  BObject> SetOpTraits for Identity<T>{}