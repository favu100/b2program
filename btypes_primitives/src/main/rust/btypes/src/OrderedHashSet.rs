use std::collections::hash_map::DefaultHasher;
use std::cell::RefCell;
use std::hash::{Hash, Hasher};

use im::OrdSet;
use crate::bobject::BObject;

#[derive(Default, Debug, PartialEq, Eq, PartialOrd, Ord, Clone)]
pub struct OrderedHashSet<I: BObject> {
    set: OrdSet<I>,
    hash_cache: RefCell<Option<u64>>,
}

impl<I: BObject> Hash for OrderedHashSet<I> {
    fn hash<H: Hasher>(self: &OrderedHashSet<I>, state: &mut H) {
        let cache = self.hash_cache.clone().take();
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

impl<I: BObject> OrderedHashSet<I> {
    pub fn new() -> Self { Self::from_set(OrdSet::new()) }

    pub fn from_set(val: OrdSet<I>) -> Self { OrderedHashSet {set: val, hash_cache: RefCell::new(Option::None)} }

    pub fn unit(item: I) -> Self { Self::from_set(OrdSet::unit(item)) }

    pub fn from(items: Vec<I>) -> Self { Self::from_set(OrdSet::from(items)) }

    pub fn update(&self, item: I) -> Self { Self::from_set(self.set.update(item)) }

    pub fn unions<A: IntoIterator<Item = Self>>(a: A) -> Self {
        Self::from_set(OrdSet::unions(a))
    }

    pub fn iter(&self) -> Iter<I> { self.set.iter() }

    pub fn len(&self) -> usize { self.set.len() }
    pub fn is_empty(&self) -> bool { self.set.is_empty() }

    pub fn contains(&self, value: &I) -> bool { self.set.contains(value) }

    pub fn union(&self, other: Self) -> Self { Self::from_set(self.set.union(other.set)) }
    pub fn intersection(&self, other: Self) -> Self { Self::from_set(self.set.intersection(other.set)) }
    pub fn relative_complement(&self, other: Self) -> Self { Self::from_set(self.set.relative_complement(other.set)) }
}