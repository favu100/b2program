use crate::bobject::BObject;
use crate::binteger::BInteger;
use crate::btuple::BTuple;

use std::fmt;
use std::hash::Hash;
use std::convert::TryInto;
use std::iter::FromIterator;
use im::{HashSet, HashMap};

#[derive(Default, Debug, Clone, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct BRelation<L: BObject, R: BObject> {
    map: HashMap<L, HashSet<R>>,
}

impl<L: BObject, R: BObject> fmt::Display for BRelation<L, R> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let mut result = "{ ".to_owned();
        let mut first = true;
        for (key, range) in self.map.iter() {
            for value in range.iter() {
                if !first { result = result + ", " }
                else { first = false; }
                result = result + &format!("({} ↦ {})", key, value).to_string() + " ";
            }
        }
        result = result + "}";
        return write!(f, "{}", result);
    }
}

impl<L: BObject, R: BObject> BObject for BRelation<L, R> {}

impl<L: 'static + BObject, R: 'static + BObject> BRelation<L, R> {
    pub fn new(mut args: Vec<BTuple<L, R>>) -> BRelation<L,R> {
        let mut ret: BRelation<L, R> = BRelation {map: HashMap::new() };
        while !args.is_empty() {
            let current_tuple = args.remove(0);
            let set = ret.map.get(&current_tuple.projection1());
            let new_set: HashSet<R>;
            if set.is_some() {
                new_set = set.unwrap().insert(current_tuple.projection2());
            } else {
                new_set = HashSet::from(vec![current_tuple.projection2()]);
            }
            ret.map = ret.map.insert(current_tuple.projection1(), new_set);
        }
        return ret;
    }

    pub fn card(&self) -> BInteger {
        return self.size();
    }

    pub fn size(&self) -> BInteger {
        let mut size = 0;
        for val in self.map.values() {
            size += val.len();
        }
        return BInteger::new(size.try_into().unwrap());
    }

    pub fn intersect(&self, relation: &BRelation<L, R>) -> BRelation<L, R> {
        let other_map = &relation.map;
        let other_domain: HashSet<L> = HashSet::from_iter(relation.map.keys());
        let this_domain: HashSet<L> = HashSet::from_iter(self.map.keys());
        let intersection_domain = this_domain.intersection(&other_domain);
        let difference_domain = this_domain.difference(&other_domain);

        let mut result_map = BRelation{map: self.map.clone()};
        for obj in intersection_domain {
            let domain_element = obj;
            let this_range_set = self.map.get(&domain_element).unwrap();
            let other_range_set = other_map.get(&domain_element).unwrap();
            result_map.map = result_map.map.insert(domain_element, this_range_set.union(&other_range_set));
        }

        for obj in difference_domain {
            let domain_element = obj;
            result_map.map = result_map.map.remove(&domain_element);
        }

        return result_map;
    }
}
