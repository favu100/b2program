use crate::bboolean::BBoolean;
use crate::binteger::BInteger;
use crate::bstring::BString;
use crate::bobject::BObject;

//TODO: use immutable_map::TreeSet;
use std::any::TypeId;
use std::convert::TryInto;
use std::collections::BTreeSet;
use std::hash::Hash;
use std::collections::LinkedList;
use std::fmt;
use rand::Rng;

#[derive(Default, Debug, PartialEq, Eq, Hash, PartialOrd, Ord, Clone)]
pub struct BSet<T: BObject> {
    set: BTreeSet<T>,
}

impl<T: BObject> fmt::Display for BSet<T> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let mut result = "{ ".to_owned();
        let mut first = true;
        for e in self.set.iter() {
            if !first { result = result + ", " }
            else { first = false; }
            result = result + &format!("{}", e).to_string() + " ";
        }
        result = result + "}";
        return write!(f, "{}", result);
    }
}

impl<T: BObject> BObject for BSet<T> {}

impl<T: 'static + BObject> BSet<T> {
    #![allow(non_snake_case, dead_code)]

    pub fn new(mut args: Vec<T>) -> BSet<T> {
        let mut ret: BSet<T> = BSet {
            set: BTreeSet::new()
        };
        while !args.is_empty() {
            ret.set.insert(args.remove(0));
        }
        return ret;
    }

    pub fn size(&self) -> usize {
        return self.set.len();
    }

    pub fn isEmpty(&self) -> bool {
        return self.set.is_empty();
    }

    pub fn contains(&self, o: &T) -> bool {
        return self.set.contains(o);
    }

    pub fn intersect(&self, set: &BSet<T>) -> BSet<T> {
        return BSet::new(self.set.intersection(&set.set).cloned().collect());
    }

    pub fn difference(&self, set: &BSet<T>) -> BSet<T> {
        return BSet::new(self.set.difference(&set.set).cloned().collect());
    }

    pub fn _union(&self, set: &BSet<T>) -> BSet<T> {
        return BSet::new(self.set.union(&set.set).cloned().collect());
    }

    pub fn interval(a: &BInteger, b: &BInteger) -> BSet<BInteger> {
        let mut result: BSet<BInteger> = BSet::new(vec![]);
        for i in a.get_val()..b.get_val()+1 {
            result.set.insert(BInteger::new(i));
        }
        return result;
    }

    pub fn card(&self) -> BInteger {
        return self._size();
    }

    pub fn _size(&self) -> BInteger {
        return BInteger::new(self.set.len().try_into().unwrap());
    }

    pub fn elementOf(&self, object: &T) -> BBoolean {
        return BBoolean::new(self.contains(object));
    }

    pub fn notElementOf(&self, object: &T) -> BBoolean {
        return BBoolean::new(!self.contains(object));
    }

    pub fn subset(&self, set: &BSet<T>) -> BBoolean {
        return BBoolean::new(self.set.is_subset(&set.set));
    }

    pub fn notSubset(&self, set: &BSet<T>) -> BBoolean {
        return BBoolean::new(!self.set.is_subset(&set.set));
    }

    pub fn strictSubset(&self, set: &BSet<T>) -> BBoolean {
        return BBoolean::new(self.set.len() < set.set.len() && self.set.is_subset(&set.set));
    }

    pub fn strictNotSubset(&self, set: &BSet<T>) -> BBoolean {
        return BBoolean::new(self.set.len() == set.set.len() || !self.set.is_subset(&set.set));
    }

    pub fn fin(&self) -> BSet<BSet<T>> {
        return self.pow();
    }

    pub fn pow(&self) -> BSet<BSet<T>> {
        return self._pow(true);
    }

    pub fn fin1(&self) -> BSet<BSet<T>> {
        return self.pow1();
    }

    pub fn pow1(&self) -> BSet<BSet<T>> {
        return self._pow(false);
    }

    fn _pow(&self, with_empty_set: bool) -> BSet<BSet<T>> {
        let mut result: BSet<BSet<T>> = BSet::new(vec![]);
        let start: BSet<T> = BSet::new(vec![]);
        let mut queue: LinkedList<BSet<T>> = LinkedList::new();
        queue.push_back(start.clone());
        if with_empty_set { result = result._union(&BSet::new(vec![start])); }

        while !queue.is_empty() {
            let current_set: BSet<T> = queue.pop_front().unwrap();
            for element in self.set.iter() {
                let next_set: BSet<T> = current_set._union(&BSet::new(vec![element.clone()]));
                let previous_size = result.size();
                result = result._union(&BSet::new(vec![next_set.clone()]));
                if previous_size < result.size() {
                    queue.push_back(next_set);
                }
            }
        }

        return result;
    }

    pub fn _min(self: &BSet<T>) -> BInteger {
        if TypeId::of::<BInteger>() == TypeId::of::<T>() {
            return self.set.iter().next().unwrap().get_binteger_value();
        } else {
            panic!("Called interval function of BSet which doesnt hold integers!")
        }
    }

    pub fn _max(self: &BSet<T>) -> BInteger {
        if TypeId::of::<BInteger>() == TypeId::of::<T>() {
            return self.set.iter().next_back().unwrap().get_binteger_value();
        } else {
            panic!("Called interval function of BSet which doesnt hold integers!")
        }
    }

    pub fn nondeterminism(&self) -> T {
        let mut rng = rand::thread_rng();
        return self.set.iter().nth(rng.gen_range(0..self.set.len())).unwrap().clone();
    }

    pub fn equal(&self, other: &BSet<T>) -> BBoolean {
        return BBoolean::new(self.set.eq(&other.set));
    }

    pub fn unequal(&self, other: &BSet<T>) -> BBoolean {
        return BBoolean::new(!self.set.eq(&other.set));
    }

    pub fn subsetOfInteger(&self) -> BBoolean {
        return BBoolean::new(TypeId::of::<BInteger>() == TypeId::of::<T>());
    }

    pub fn strictSubsetOfInteger(&self) -> BBoolean {
        return self.subsetOfInteger();
    }

    pub fn notSubsetOfInteger(&self) -> BBoolean {
        return self.subsetOfInteger().not();
    }

    pub fn equalInteger(&self) -> BBoolean {
        return BBoolean::new(false);
    }

    pub fn unequalInteger(&self) -> BBoolean {
        return BBoolean::new(true);
    }

    pub fn equalNatural(&self) -> BBoolean {
        return BBoolean::new(false);
    }

    pub fn unequalNatural(&self) -> BBoolean {
        return BBoolean::new(true);
    }

    pub fn equalNatural1(&self) -> BBoolean {
        return BBoolean::new(false);
    }

    pub fn unequalNatural1(&self) -> BBoolean {
        return BBoolean::new(true);
    }

    pub fn equalString(&self) -> BBoolean {
        return BBoolean::new(false);
    }

    pub fn unequalString(&self) -> BBoolean {
        return BBoolean::new(true);
    }

    pub fn equalStruct(&self) -> BBoolean {
        return BBoolean::new(false);
    }

    pub fn unequalStruct(&self) -> BBoolean {
        return BBoolean::new(true);
    }

    pub fn notStrictSubsetOfInteger(&self) -> BBoolean {
        return self.strictSubsetOfInteger().not();
    }

    pub fn subsetOfNatural(&self) -> BBoolean {
        if self.subsetOfInteger().booleanValue() {
            return BBoolean::new(self.set.iter().find(|&i| i.get_binteger_value().isNotNatural().booleanValue()).is_none());
        }
        return BBoolean::new(false);
    }

    pub fn strictSubsetOfNatural(&self) -> BBoolean {
        return self.subsetOfNatural();
    }

    pub fn notSubsetOfNatural(&self) -> BBoolean {
        return self.subsetOfNatural().not();
    }

    pub fn notStrictSubsetOfNatural(&self) -> BBoolean {
        return self.strictSubsetOfNatural().not();
    }

    pub fn subsetOfNatural1(&self) -> BBoolean {
        if self.subsetOfInteger().booleanValue() {
            return BBoolean::new(self.set.iter().find(|&i| i.get_binteger_value().isNotNatural1().booleanValue()).is_none());
        }
        return BBoolean::new(false);
    }

    pub fn strictSubsetOfNatural1(&self) -> BBoolean {
        return self.subsetOfNatural();
    }

    pub fn notSubsetOfNatural1(&self) -> BBoolean {
        return self.subsetOfNatural1().not();
    }

    pub fn notStrictSubsetOfNatural1(&self) -> BBoolean {
        return self.strictSubsetOfNatural1().not();
    }

    pub fn subsetOfString(&self) -> BBoolean {
        return BBoolean::new(TypeId::of::<BString>() == TypeId::of::<T>());
    }

    pub fn strictSubsetOfString(&self) -> BBoolean {
        return self.subsetOfString();
    }

    pub fn notSubsetOfString(&self) -> BBoolean {
        return self.subsetOfString().not();
    }

    pub fn notStrictSubsetOfString(&self) -> BBoolean {
        return self.strictSubsetOfString().not();
    }

    pub fn subsetOfStruct(&self) -> BBoolean {
        return self.is_struct();
    }

    pub fn strictsubsetOfStruct(&self) -> BBoolean {
        return self.subsetOfStruct();
    }

    pub fn notsubsetOfStruct(&self) -> BBoolean {
        return self.subsetOfStruct().not();
    }

    pub fn notStrictsubsetOfStruct(&self) -> BBoolean {
        return self.strictsubsetOfStruct().not();
    }
}
