use std::hash::{Hasher};
use std::cmp::Ordering;
use std::fmt::{Debug};
use im::ordset::Iter;

use crate::bobject::BObject;
use crate::bset::BSet;

pub trait SetOp: SetOpTraits + Debug {

    fn compute(&self, lhs: &BSet<Self::Item>) -> BSet<Self::Item>;
    fn clone_box(&self) -> Box<dyn SetOp<Item = Self::Item>>;

    fn get_op_name(&self) -> &str;
    fn get_rhs(&self) -> Option<Box<dyn SetOp<Item = Self::Item>>>;

    fn to_string(&self, lhs: Option<&str>) -> String {
        let mut result = format!("{}(", self.get_op_name());
        let mut has_lhs = false;
        if lhs.is_some() {
            result.push_str(lhs.unwrap());
            has_lhs = true;
        }
        match self.get_rhs() {
            Some(v) => {
                if has_lhs { result.push_str(", "); }
                result.push_str(format!("{}", v.to_string(Option::None)).as_str())
            },
            None => {},
        }
        result.push_str(")");

        return result;
    }

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
    type Item: BObject;

    fn iter_lazy<'a>(&'a self, lhs: &'a BSet<Self::Item>) -> IterWrapper<'a, Self::Item>;
    fn contains_lazy(&self, lhs: &BSet<Self::Item>, o:&Self::Item) -> bool;
    fn is_empty_lazy(&self, lhs: &BSet<Self::Item>) -> bool;
    fn size_lazy(&self, lhs: &BSet<Self::Item>) -> usize;
    //fn hash_val(&self) -> u64;
}

pub enum IterWrapperE<'a, T: BObject> {
    Empty,
    Single(Iter<'a, T>),
    Chain(Box<IterWrapper<'a, T>>, Box<IterWrapper<'a, T>>),
    Filtered(Box<IterWrapper<'a, T>>, BSet<T>),
}

pub struct IterWrapper<'a, T: BObject> {
    iter: IterWrapperE<'a, T>,
}

impl<'a, T: BObject> IterWrapper<'a, T> {
    pub fn empty() -> IterWrapper<'a, T> { IterWrapper { iter: IterWrapperE::Empty }}
    pub fn single(iter: Iter<'a, T>) -> IterWrapper<'a, T> { IterWrapper { iter: IterWrapperE::Single(iter)} }
    pub fn chain(iter_a: IterWrapper<'a, T>, iter_b: IterWrapper<'a, T>) -> IterWrapper<'a, T> {
        IterWrapper { iter: IterWrapperE::Chain(Box::new(iter_a),
                                                Box::new(iter_b))}
    }
    pub fn filtered(iter: IterWrapper<'a, T>, filter: BSet<T>) -> IterWrapper<'a, T> {
        IterWrapper { iter: IterWrapperE::Filtered(Box::new(iter), filter)}
    }
}

impl<'a, T: BObject> Iterator for IterWrapper<'a, T> {
    type Item = &'a T;

    fn next(&mut self) -> Option<Self::Item> {
        match self.iter {
            IterWrapperE::Empty => Option::None,
            IterWrapperE::Single(ref mut s) => s.next(),
            IterWrapperE::Chain(ref mut a, ref mut b) => {
                let option_a = a.next();
                match option_a {
                    Some(result) => Some(result),
                    None => b.next(),
                }
            },
            IterWrapperE::Filtered(ref mut i, ref filter) => {
                let mut option = i.next();
                while option.is_some() {
                    let val = option.unwrap();
                    if !filter.contains(val) { return Option::Some(val); }
                    option = i.next();
                }
                return option;
            }
        }
    }
}


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