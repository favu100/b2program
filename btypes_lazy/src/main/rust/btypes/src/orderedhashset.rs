use std::borrow::Borrow;
use std::collections::hash_map::DefaultHasher;
use std::cell::RefCell;
use std::cmp::Ordering;
use std::hash::{Hash, Hasher};

use im::OrdSet;
use im::ordset::Iter;
use crate::bobject::BObject;

#[derive(Default, Debug, Eq)]
pub struct OrderedHashSet<I: BObject> {
    set: OrdSet<I>,
    hash_cache: RefCell<Option<u64>>,
}

impl<I: BObject> Clone for OrderedHashSet<I> {
    fn clone(&self) -> Self {
        OrderedHashSet { set: self.set.clone(), hash_cache: RefCell::new(self.hash_cache.borrow().clone()) }
    }
}

impl<I: BObject> PartialOrd for OrderedHashSet<I> {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> { self.set.partial_cmp(&other.set) }
    fn lt(&self, other: &Self) -> bool { self.set.lt(&other.set) }
    fn le(&self, other: &Self) -> bool { self.set.le(&other.set) }
    fn gt(&self, other: &Self) -> bool { self.set.gt(&other.set) }
    fn ge(&self, other: &Self) -> bool { self.set.ge(&other.set) }
}

impl<I: BObject> Ord for OrderedHashSet<I> {
    fn cmp(&self, other: &Self) -> Ordering { self.set.cmp(&other.set) }
    fn max(self, other: Self) -> Self {
        match self.cmp(&other) {
            Ordering::Less => other,
            Ordering::Greater => self,
            Ordering::Equal => other,
        }
    }
    fn min(self, other: Self) -> Self {
        match self.cmp(&other) {
            Ordering::Less => self,
            Ordering::Greater => other,
            Ordering::Equal => self,
        }
    }
    fn clamp(self, min: Self, max: Self) -> Self {
        if self < min {
            min
        } else if self > max {
            max
        } else {
            self
        }
    }
}

//TODO: check if replacing cache with mutex works and does not impact permormance too much
unsafe impl<T: BObject> Sync for OrderedHashSet<T> {}

impl<I: BObject> PartialEq for OrderedHashSet<I> {
    fn eq(&self, other: &Self) -> bool {
        self.set.eq(&other.set)
    }
}

impl<I: BObject> Hash for OrderedHashSet<I> {
    fn hash<H: Hasher>(self: &OrderedHashSet<I>, state: &mut H) {
        let cache = self.hash_cache.borrow().clone();
        let hash: u64;

        if cache.is_none() {
            let mut hasher = DefaultHasher::new();
            self.set.hash(&mut hasher);
            hash = hasher.finish();
            self.hash_cache.replace(Option::Some(hash));
        } else {
            hash = cache.unwrap();
        }
        hash.hash(state);
    }
}

impl<A: BObject> IntoIterator for OrderedHashSet<A> {
    type Item = A;
    type IntoIter = im::ordset::ConsumingIter<A>;

    fn into_iter(self) -> Self::IntoIter {
        self.set.into_iter()
    }
}

impl<I: BObject> OrderedHashSet<I> {
    pub fn new() -> Self { Self::from_set(OrdSet::new()) }

    pub fn from_set(val: OrdSet<I>) -> Self { OrderedHashSet {set: val, hash_cache: RefCell::new(Option::None)} }

    pub fn unit(item: I) -> Self { Self::from_set(OrdSet::unit(item)) }

    pub fn from(items: Vec<I>) -> Self { Self::from_set(OrdSet::from(items)) }

    pub fn update(&self, item: I) -> Self { Self::from_set(self.set.update(item)) }

    pub fn unions<A: IntoIterator<Item = Self>>(a: A) -> Self {
        a.into_iter().fold(Self::new(), Self::union)
    }

    pub fn iter(&self) -> Iter<'_, I> { self.set.iter() }

    pub fn len(&self) -> usize { self.set.len() }
    pub fn is_empty(&self) -> bool { self.set.is_empty() }

    pub fn contains(&self, value: &I) -> bool { self.set.contains(value) }
    pub fn is_subset<RS: Borrow<Self>>(&self, other: RS) -> bool {
        let other = other.borrow();
        self.set.is_subset(&other.set)
    }

    pub fn insert(&mut self, value: I) -> Option<I> {
        self.hash_cache.replace(Option::None);
        return self.set.insert(value);
    }

    pub fn remove_min(&mut self) -> Option<I> {
        self.hash_cache.replace(Option::None);
        return self.set.remove_min()
    }

    pub fn get_min(&self) -> Option<&I> { self.set.get_min() }
    pub fn get_max(&self) -> Option<&I> { self.set.get_max() }

    pub fn union(self, other: Self) -> Self {
        self.hash_cache.replace(Option::None);
        return Self::from_set(self.set.union(other.set));
    }

    pub fn intersection(self, other: Self) -> Self {
        self.hash_cache.replace(Option::None);
        return Self::from_set(self.set.intersection(other.set));
    }

    pub fn relative_complement(self, other: Self) -> Self {
        self.hash_cache.replace(Option::None);
        return Self::from_set(self.set.relative_complement(other.set));
    }

    pub fn get_set(self) -> OrdSet<I> { return self.set }
}