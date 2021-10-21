use crate::bobject::BObject;
use crate::binteger::BInteger;
use crate::btuple::BTuple;

use std::fmt;
use std::hash::Hash;
use std::convert::TryInto;
use std::iter::FromIterator;
use im::{HashMap, OrdSet};
use crate::bboolean::BBoolean;
use crate::brelation::CombiningType::{DIFFERENCE, INTERSECTION, UNION};
use crate::bset::BSet;

enum CombiningType {
    DIFFERENCE,
    INTERSECTION,
    UNION
}

#[derive(Default, Debug, Clone, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct BRelation<L: BObject, R: BObject> {
    map: HashMap<L, OrdSet<R>>,
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
    #![ allow( dead_code, non_snake_case) ]

    pub fn new(mut args: Vec<BTuple<L, R>>) -> BRelation<L,R> {
        let mut ret: BRelation<L, R> = BRelation {map: HashMap::new() };
        while !args.is_empty() {
            let current_tuple = args.remove(0);
            ret.insert(&current_tuple);
        }
        return ret;
    }

    pub fn fromSet(set: BSet<BTuple<L, R>>) -> BRelation<L, R> {
        let mut ret: BRelation<L, R> = BRelation {map: HashMap::new()};
        set.iter().for_each(|current_tuple| ret.insert(current_tuple.as_ref()));
        return ret;
    }

    fn insert(&mut self, tuple: &BTuple<L, R>) {
        let set = self.map.get(&tuple.projection1());
        let new_set: OrdSet<R>;
        if set.is_some() {
            new_set = set.unwrap().insert(tuple.projection2());
        } else {
            new_set = OrdSet::from(vec![tuple.projection2()]);
        }
        self.map = self.map.insert(tuple.projection1(), new_set);
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
        return self.relation_combine(relation, INTERSECTION)
    }

    pub fn difference(&self, relation: &BRelation<L, R>) -> BRelation<L, R> {
        return self.relation_combine(relation, DIFFERENCE);
    }

    pub fn union(&self, relation: &BRelation<L, R>) -> BRelation<L, R> {
        return self.relation_combine(relation, UNION);
    }

    fn relation_combine(&self, relation: &BRelation<L, R>, comb_type: CombiningType) -> BRelation<L, R> {
        let other_map = &relation.map;
        let other_domain: OrdSet<L> = OrdSet::from_iter(relation.map.keys());
        let this_domain: OrdSet<L> = OrdSet::from_iter(self.map.keys());
        let intersection_domain = this_domain.intersection(&other_domain);
        let difference_domain = this_domain.difference(&other_domain);

        let loop1_set;
        let loop2_set;
        match comb_type {
            CombiningType::DIFFERENCE => {loop1_set = difference_domain; loop2_set = intersection_domain;}
            CombiningType::INTERSECTION => {loop1_set = intersection_domain; loop2_set = difference_domain;}
            CombiningType::UNION => {loop1_set = other_domain; loop2_set = OrdSet::new();}
        }

        let mut result_map = BRelation{map: self.map.clone()};
        for domain_element in loop1_set {
            let this_range_set = self.map.get(&domain_element).unwrap();
            let other_range_set = other_map.get_or(&domain_element, OrdSet::new());
            let new_range_set;
            match comb_type {
                CombiningType::DIFFERENCE => {new_range_set = this_range_set.difference(other_range_set.as_ref());}
                CombiningType::INTERSECTION => {new_range_set = this_range_set.intersection(other_range_set.as_ref());}
                CombiningType::UNION => {new_range_set = this_range_set.union(other_range_set.as_ref());}
            }
            if new_range_set.is_empty() {
                result_map.map.remove(domain_element.as_ref());
            } else {
                result_map.map = result_map.map.insert(domain_element, new_range_set);
            }
        }

        for domain_element in loop2_set {
            result_map.map = result_map.map.remove(&domain_element);
        }

        return result_map;
    }

    pub fn equal(&self, o: &BRelation<L, R>) -> BBoolean {
        return BBoolean::new(self.eq(o));
    }

    pub fn unequal(&self, o: &BRelation<L, R>) -> BBoolean {
        return BBoolean::new(!self.eq(o));
    }

    pub fn elementOf(&self, element: &BTuple<L, R>) -> BBoolean {
        let prj1 = element.projection1();
        let prj2 = element.projection2();
        return BBoolean::new(self.map.get_or(&prj1, OrdSet::new()).contains(&prj2));
    }

    pub fn notElementOf(&self, element: &BTuple<L, R>) -> BBoolean {
        let prj1 = element.projection1();
        let prj2 = element.projection2();
        return BBoolean::new(!self.map.get_or(&prj1, OrdSet::new()).contains(&prj2));
    }

    pub fn relationImage(&self, domain: &BSet<L>) -> BSet<R> {
        let result_set = OrdSet::unions(domain.iter().map(|e| self.map.get_or(&e, OrdSet::new()).as_ref().clone()).into_iter());
        return BSet::fromOrdSet(result_set);
    }

    pub fn functionCall(&self, arg: &L) -> R {
        let range = self.map.get(arg);
        if range.is_none() {
            panic!("Argument is not in the domain of this relation");
        }

        for element in range.unwrap().iter() {
            return element.as_ref().clone();
        }

        panic!("Argument is not in the domain of this relation");
    }
}
