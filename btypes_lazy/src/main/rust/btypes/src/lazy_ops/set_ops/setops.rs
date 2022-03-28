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

    fn get_op_name(&self) -> &str;
    fn get_rhs(&self) -> Option<&Box<dyn SetOp<Item = Self::Item>>>;

    //PartialEq
    fn eq_box(&self, other: &Box<dyn SetOp<Item = Self::Item>>) -> bool {
        self.get_op_name().eq(other.get_op_name()) && self.get_rhs().eq(&other.get_rhs())
    }

    //PartialOrd
    fn partial_cmp_box(&self, other: &Box<dyn SetOp<Item = Self::Item>>) -> Option<Ordering> {
        let mut result = self.get_op_name().partial_cmp(other.get_op_name());
        if result.is_some() {
            if result.clone().unwrap().eq(&Ordering::Equal) {
                result = self.get_rhs().partial_cmp(&other.get_rhs());
            }
        }
        return result;
    }

    //Ord
    fn cmp_box(&self, other: &Box<dyn SetOp<Item = Self::Item>>) -> Ordering {
        let mut result = self.get_op_name().cmp(other.get_op_name());
        if result.eq(&Ordering::Equal) {
            result = self.get_rhs().cmp(&other.get_rhs());
        }
        return result;
    }
    fn lt(&self, other: &Box<dyn SetOp<Item = Self::Item>>) -> bool { self.cmp_box(other).eq(&Ordering::Less) }
    fn le(&self, other: &Box<dyn SetOp<Item = Self::Item>>) -> bool { [Ordering::Less, Ordering::Equal].contains(&self.cmp_box(other)) }
    fn gt(&self, other: &Box<dyn SetOp<Item = Self::Item>>) -> bool { self.cmp_box(other).eq(&Ordering::Greater) }
    fn ge(&self, other: &Box<dyn SetOp<Item = Self::Item>>) -> bool { [Ordering::Greater, Ordering::Equal].contains(&self.cmp_box(other)) }

    fn max(&self, other: &Box<dyn SetOp<Item = Self::Item>>) -> Box<dyn SetOp<Item = Self::Item>> {
        match self.cmp_box(other) {
            Ordering::Less => other.clone(),
            Ordering::Equal => other.clone(),
            Ordering::Greater => self.clone_box(),
        }
    }

    fn min(&self, other: &Box<dyn SetOp<Item = Self::Item>>) -> Box<dyn SetOp<Item = Self::Item>> {
        match self.cmp_box(other) {
            Ordering::Less => self.clone_box(),
            Ordering::Equal => self.clone_box(),
            Ordering::Greater => other.clone(),
        }
    }

    fn clamp(&self, min: &Box<dyn SetOp<Item = Self::Item>>, max: &Box<dyn SetOp<Item = Self::Item>>) -> Box<dyn SetOp<Item = Self::Item>> {
        if self.lt(min) {
            return min.clone()
        } else if self.gt(max) {
            max.clone()
        } else {
            self.clone_box()
        }
    }
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
        self.eq_box(other)
    }
}

impl<T: BObject> PartialOrd<Self> for Box<dyn SetOp<Item=T>> {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        self.partial_cmp_box(other)
    }
}

impl<T: BObject> Ord for Box<dyn SetOp<Item = T>> {
    fn cmp(&self, other: &Self) -> Ordering {
        self.cmp_box(other)
    }
}
/*
impl<T: 'static +  BObject> Default for Box<dyn SetOp<Item = T>> {
    fn default() -> Box<Self> {
        Box::new(Identity {phantom: PhantomData})
    }
}
*/





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
    type Item = T;

    fn compute(&self, lhs: &BSet<T>) -> BSet<T> {
        lhs.clone()
    }

    fn clone_box(&self) -> Box<dyn SetOp<Item=Self::Item>> {
        Box::new(Identity{phantom: PhantomData})
    }

    fn get_op_name(&self) -> &str {
        return Identity::<T>::OP_NAME;
    }

    fn get_rhs(&self) -> Option<&Box<dyn SetOp<Item=Self::Item>>> {
        return Option::None;
    }
}

impl<T: 'static +  BObject> SetOpTraits for Identity<T>{}