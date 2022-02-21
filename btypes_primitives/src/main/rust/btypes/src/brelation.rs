#![ allow( dead_code, non_snake_case) ]

use std::collections::LinkedList;
use crate::bobject::BObject;
use crate::binteger::{BInt, BInteger, FromBInt};
use crate::btuple::BTuple;

use std::fmt;
use std::hash::{Hash, Hasher};
use std::convert::TryInto;
use std::iter::FromIterator;
use rand::prelude::IteratorRandom;
use im::{HashMap, OrdSet};
use crate::bboolean::BBoolean;
use crate::brelation::CombiningType::{DIFFERENCE, INTERSECTION, UNION};
use crate::bset::{BSet, SetLike, TBSet};
use crate::bstring::TBString;
use crate::bstruct::BStruct;

enum CombiningType {
    DIFFERENCE,
    INTERSECTION,
    UNION
}

#[derive(Default, Debug, Clone, PartialEq, Eq, PartialOrd, Ord)]
pub struct BRelation<L: BObject, R: BObject> {
    map: HashMap<L, OrdSet<R>>,
}

impl<L: BObject, R: BObject> Hash for BRelation<L, R> {
    fn hash<H: Hasher>(&self, state: &mut H) {
        let mut kvs = self.map.iter().collect::<Vec<(&L, &OrdSet<R>)>>();
        kvs.sort_by(|(k1, _v1), (k2, _v2)| k1.cmp(k2));
        for (key, value) in kvs {
            key.hash(state);
            value.iter().for_each(|v| v.hash(state));
        }
    }
}

pub trait TBRelation {
    type Left: BObject;
    type Right: BObject;

    fn get_as_brelation(&self) -> &BRelation<Self::Left, Self::Right>;

    fn isPartialInteger(&self) -> BBoolean { return BBoolean::new(false); }
    fn checkDomainInteger(&self) -> BBoolean { return BBoolean::new(false); }
    fn isPartialNatural(&self) -> BBoolean { return BBoolean::new(false); }
    fn checkDomainNatural(&self) -> BBoolean { return BBoolean::new(false); }
    fn isPartialNatural1(&self) -> BBoolean { return BBoolean::new(false); }
    fn checkDomainNatural1(&self) -> BBoolean { return BBoolean::new(false); }
    fn checkRangeInteger(&self) -> BBoolean { return BBoolean::new(false); }
    fn checkRangeNatural(&self) -> BBoolean { return BBoolean::new(false); }
    fn checkRangeNatural1(&self) -> BBoolean { return BBoolean::new(false); }
    fn checkDomainString(&self) -> BBoolean { return BBoolean::new(false); }
    fn isPartialString(&self) -> BBoolean { return BBoolean::new(false); }
    fn checkRangeString(&self) -> BBoolean { return BBoolean::new(false); }
    fn checkDomainStruct(&self) -> BBoolean { return BBoolean::new(false); }
    fn isPartialStruct(&self) -> BBoolean { return BBoolean::new(false); }
    fn checkRangeStruct(&self) -> BBoolean { return BBoolean::new(false); }
}

impl<L: BObject, R: BObject> fmt::Display for BRelation<L, R> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let mut result = "{".to_owned();
        let mut first = true;
        for (key, range) in self.map.iter() {
            for value in range.iter() {
                if !first { result = result + ", " }
                else { first = false; }
                result = result + &format!("({} |-> {})", key, value).to_string();
            }
        }
        result = result + "}";
        return write!(f, "{}", result);
    }
}
impl<L: BObject, R: BObject> TBRelation for BRelation<L, R> {
    type Left = L;
    type Right = R;
    fn get_as_brelation(&self) -> &BRelation<Self::Left, Self::Right> { self }
}
impl<L: BObject, R: BObject> BObject for BRelation<L, R> {}

impl<L: 'static + BObject, R: 'static + BObject> BRelation<L, R> {
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
        set.iter().for_each(|current_tuple| ret.insert(current_tuple));
        return ret;
    }

    fn insert(&mut self, tuple: &BTuple<L, R>) {
        let set = self.map.get(&tuple.projection1());
        let new_set: OrdSet<R>;
        if set.is_some() {
            new_set = set.unwrap().update(tuple.projection2());
        } else {
            new_set = OrdSet::from(vec![tuple.projection2()]);
        }
        self.map.insert(tuple.projection1(), new_set);
    }

    fn update(&self, key: L, value: OrdSet<R>) -> Self {
        BRelation{ map: self.map.update(key, value) }
    }

    fn update_unit(&self, key: L, value: R) -> Self {
        self.update(key, OrdSet::unit(value))
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

    pub fn _union(&self, relation: &BRelation<L, R>) -> BRelation<L, R> {
        return self.relation_combine(relation, UNION);
    }

    fn relation_combine(&self, relation: &BRelation<L, R>, comb_type: CombiningType) -> BRelation<L, R> {
        let other_map = &relation.map;
        let other_domain: OrdSet<L> = OrdSet::from_iter(relation.map.keys().cloned().collect::<Vec<L>>());
        let this_domain: OrdSet<L> = OrdSet::from_iter(self.map.keys().cloned().collect::<Vec<L>>());
        let intersection_domain = this_domain.clone().intersection(other_domain.clone());
        let difference_domain = this_domain.relative_complement(other_domain.clone());

        let loop1_set;
        let loop2_set;
        match comb_type {
            CombiningType::DIFFERENCE => {loop1_set = difference_domain; loop2_set = intersection_domain;}
            CombiningType::INTERSECTION => {loop1_set = intersection_domain; loop2_set = difference_domain;}
            CombiningType::UNION => {loop1_set = other_domain; loop2_set = OrdSet::new();}
        }

        let empty_map = OrdSet::new();
        let mut result_map = BRelation{map: self.map.clone()};
        for domain_element in loop1_set {
            let this_range_set = self.map.get(&domain_element).unwrap_or(&empty_map).clone();
            let other_range_set = other_map.get(&domain_element).unwrap_or(&empty_map).clone();
            let new_range_set;
            match comb_type {
                CombiningType::DIFFERENCE => {new_range_set = this_range_set.relative_complement(other_range_set);}
                CombiningType::INTERSECTION => {new_range_set = this_range_set.intersection(other_range_set);}
                CombiningType::UNION => {new_range_set = this_range_set.union(other_range_set);}
            }
            if new_range_set.is_empty() {
                result_map.map.remove(&domain_element);
            } else {
                result_map.map.insert(domain_element, new_range_set);
            }
        }

        for domain_element in loop2_set {
            result_map.map.remove(&domain_element);
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
        return BBoolean::new(self.map.get(&prj1).unwrap_or(&OrdSet::new()).contains(&prj2));
    }

    pub fn notElementOf(&self, element: &BTuple<L, R>) -> BBoolean {
        let prj1 = element.projection1();
        let prj2 = element.projection2();
        return BBoolean::new(!self.map.get(&prj1).unwrap_or(&OrdSet::new()).contains(&prj2));
    }

    pub fn relationImage(&self, domain: &BSet<L>) -> BSet<R> {
        let result_set = OrdSet::unions(domain.iter().map(|e| self.map.get(&e).unwrap_or(&OrdSet::new()).clone()).into_iter());
        return BSet::fromOrdSet(result_set);
    }

    pub fn functionCall(&self, arg: &L) -> R {
        let range = self.map.get(arg);
        if range.is_none() {
            panic!("Argument is not in the domain of this relation");
        }

        return range.unwrap().iter().next().unwrap_or_else(|| panic!("Argument is not in the domain of this relation")).clone();
    }

    pub fn pow(&self) -> BSet<BRelation<L, R>> { return self._pow(true); }
    pub fn fin(&self) -> BSet<BRelation<L, R>> { return self.pow(); }
    pub fn pow1(&self) -> BSet<BRelation<L, R>> { return self._pow(false); }
    pub fn fin1(&self) -> BSet<BRelation<L, R>> { return self.pow1(); }

    fn _pow(&self, with_empty_set: bool) -> BSet<BRelation<L, R>> {
        let this_map = &self.map;

        let mut result: BSet<BRelation<L, R>> = BSet::new(vec![]);
        let start: BRelation<L, R> = BRelation::new(vec![]);
        let mut queue: LinkedList<BRelation<L, R>> = LinkedList::new();
        queue.push_back(start.clone());
        if with_empty_set { result = result._union(&BSet::<BRelation<L, R>>::new(vec![start])); }
        while !queue.is_empty() {
            let current_set = queue.pop_front().unwrap();

            for domain_element in self.map.keys() {
                let range_option = this_map.get(&domain_element);
                if range_option.is_none() { break; }
                let mut range = range_option.unwrap().clone();
                while !range.is_empty() {
                    let range_element = range.remove_min().unwrap();
                    let next_relation = current_set._union(&BRelation::fromSet(BSet::new(vec![BTuple::new(domain_element.clone(), range_element)])));
                    let previous_size = result.size();
                    result = result._union(&BSet::new(vec![next_relation.clone()]));
                    if previous_size < result.size() { queue.push_back(next_relation) }
                }
            }
        }
        return result;
    }

    pub fn domain(&self) -> BSet<L> {
        let result_set: Vec<L> = self.map.iter().filter_map(|(k, v)| return if !v.is_empty() { Some(k.clone()) } else { None }).collect();
        return BSet::new(result_set);
    }

    pub fn range(&self) -> BSet<R> {
        if self.map.is_empty() {
            return BSet::<R>::new(vec![]);
        } else {
            return BSet::fromOrdSet(self.map.values().cloned().reduce(|v1, v2| v1.union(v2)).unwrap());
        }
    }

    pub fn inverse(&self) -> BRelation<R, L> {
        if self.map.is_empty() {
            return BRelation::new(vec![]);
        } else {
            return self.map.iter().fold(BRelation::<R, L>::new(vec![]),
                                        |mut map, (k, v)| {
                                            v.iter().for_each(|cv| map.insert(&BTuple::new(cv.clone(), k.clone())));
                                            return map
                                        });
        }
    }

    pub fn domainRestriction(&self, arg: &BSet<L>) -> BRelation<L, R> {
        return self.domainSubstraction(&self.domain().difference(&arg));
    }

    pub fn domainSubstraction(&self, arg: &BSet<L>) -> BRelation<L, R> {
        return BRelation {map: arg.iter().fold(self.map.clone(), |map, e| map.without(e))}
    }

    pub fn rangeRestriction(&self, arg: &BSet<R>) -> BRelation<L, R> {
        //return self.rangeSubstraction(self.range().difference(arg));
        return self.map.iter().filter_map(|(key, value)| {
            let resut_range = BSet::fromOrdSet(value.clone()).intersect(arg);
            if resut_range.isEmpty() { Option::None } else { Option::Some((key, resut_range)) }
        }).fold(BRelation::<L, R>::new(vec![]), |rel, (key, val)| rel.update(key.clone(), val.as_ord_set()));
    }

    pub fn rangeSubstraction(&self, arg: &BSet<R>) -> BRelation<L, R> {
        return self.map.iter().filter_map(|(key, value)| {
                let resut_range = BSet::fromOrdSet(value.clone()).difference(arg);
                if resut_range.isEmpty() { Option::None } else { Option::Some((key, resut_range)) }
            }).fold(BRelation::<L, R>::new(vec![]), |rel, (key, val)| rel.update(key.clone(), val.as_ord_set()));
    }

    pub fn subset(&self, arg: &BRelation<L, R>) -> BBoolean {
        let emptySet = OrdSet::new();
        for (k, v) in self.map.clone() {
            let arg_v = arg.map.get(&k).unwrap_or(&emptySet).clone();
            if !v.is_subset(arg_v) { return BBoolean::new(false) }
        }
        return BBoolean::new(true);
    }

    pub fn notSubset(&self, arg: &BRelation<L, R>) -> BBoolean {
        return self.subset(arg).not();
    }

    pub fn _override(&self, arg: &BRelation<L, R>) -> BRelation<L, R> {
        return BRelation { map: arg.map.clone().union(self.map.clone())}
    }

    pub fn directProduct<ArgR: 'static + BObject>(&self, arg: &BRelation<L, ArgR>) -> BRelation<L, BTuple<R, ArgR>> {
        self.map.iter()
            .fold(BRelation::<L, BTuple<R, ArgR>>::new(vec![]),
                  |mut rel, (k, v)| {
                      let option = arg.map.get(k);
                      if option.is_some() {
                          rel.map.insert(k.clone(), BSet::<R>::cartesian::<R, ArgR>(v, option.unwrap()));
                      }
                      return rel;
                  })
    }

    pub fn parallelProduct<ArgL, ArgR>(&self, arg: &BRelation<ArgL, ArgR>)
        -> BRelation<BTuple<L, ArgL>, BTuple<R, ArgR>>
    where ArgL: 'static + BObject,
          ArgR: 'static + BObject {
        let mut result_relation: BRelation<BTuple<L, ArgL>, BTuple<R, ArgR>> = BRelation::new(vec![]);
        for (this_key, this_range) in self.map.clone() {
            for (that_key, that_range) in arg.map.clone() {
                result_relation.map.insert(BTuple::new(this_key.clone(), that_key),
                                           BSet::<R>::cartesian::<R, ArgR>(&this_range, &that_range));
            }
        }
        return result_relation; //TODO?
    }

    pub fn composition<NewR: 'static + BObject>(&self, arg: &BRelation<R, NewR>) -> BRelation<L, NewR> {
        let mut result_set: BRelation<L, NewR> = BRelation::new(vec![]);
        let empty_set = OrdSet::<NewR>::new();
        for (this_key, this_range) in self.map.iter() {
            let new_range = this_range.iter().fold(OrdSet::<NewR>::new(),
                                                   |set, element| set.union(arg.map.get(element).unwrap_or(&empty_set).clone()));
            if !new_range.is_empty() { result_set.map.insert(this_key.clone(), new_range); }
        }
        return result_set;
    }

    pub fn projection1(arg1: &BSet<L>, arg2: &BSet<R>) -> BRelation<BTuple<L,R>,L> {
        return arg1.iter().fold(BRelation::new(vec![]), |rel, element1|
            arg2.iter().cloned().fold(rel, |nrel, element2|
                nrel.update_unit(BTuple::new(element1.clone(), element2), element1.clone())));
    }

    pub fn projection2(arg1: &BSet<L>, arg2: &BSet<R>) -> BRelation<BTuple<L,R>,R> {
        return arg1.iter().fold(BRelation::new(vec![]), |rel, element1|
            arg2.iter().cloned().fold(rel, |nrel, element2|
                nrel.update_unit(BTuple::new(element1.clone(), element2.clone()), element2)));
    }

    pub fn fnc(&self) -> BRelation<L, BSet<R>> {
        return self.map.iter().fold(BRelation::new(vec![]), |rel, (key, range)|
            rel.update_unit(key.clone(), BSet::fromOrdSet(range.clone())))
    }

    pub fn cartesianProduct(set_a: &BSet<L>, set_b: &BSet<R>) -> BRelation<L, R> {
        // slightly inefficient due to double iteration
        return BSet::<L>::cartesian::<L, R>(&set_a.as_ord_set(), &set_b.as_ord_set()).iter()
            .fold(BRelation::new(vec![]), |mut rel, tuple| { rel.insert(tuple); return rel; });
    }

    pub fn nondeterminism(&self) -> BTuple<L, R> {
        let mut rng = rand::thread_rng();
        let tuple = self.map.iter().choose(&mut rng).unwrap();
        return BTuple::new(tuple.0.clone(), tuple.1.iter().choose(&mut rng).unwrap().clone());
    }

    pub fn isTotal(&self, domain: &BSet<L>) -> BBoolean { return self.domain().equal(domain); }
    pub fn isTotalInteger(&self) -> BBoolean { return BBoolean::new(false); }
    pub fn isTotalNatural(&self) -> BBoolean { return BBoolean::new(false); }
    pub fn isTotalNatural1(&self) -> BBoolean { return BBoolean::new(false); }
    pub fn isTotalString(&self) -> BBoolean { return BBoolean::new(false); }
    pub fn isTotalStruct(&self) -> BBoolean { return BBoolean::new(false); }
    pub fn isPartial(&self, domain: &BSet<L>) -> BBoolean { return self.domain().strictSubset(domain); }
    pub fn checkDomain(&self, domain: &BSet<L>) -> BBoolean { return self.domain().subset(domain); }
    pub fn checkRange(&self, range: &BSet<R>) -> BBoolean { return self.range().subset(range); }

    pub fn isRelation(&self) -> BBoolean { return BBoolean::new(true); }

    pub fn isFunction(&self) -> BBoolean {
        return BBoolean::new(self.map.values().find(|set| set.len() > 1).is_none());
    }

    pub fn isSurjection(&self, range: &BSet<R>) -> BBoolean { return self.range().equal(range); }
    pub fn isSurjectionInteger(&self) -> BBoolean { return BBoolean::new(false); }
    pub fn isSurjectionNatural(&self) -> BBoolean { return BBoolean::new(false); }
    pub fn isSurjectionNatural1(&self) -> BBoolean { return BBoolean::new(false); }
    pub fn isSurjectionString(&self) -> BBoolean { return BBoolean::new(false); }
    pub fn isSurjectionStruct(&self) -> BBoolean { return BBoolean::new(false); }

    pub fn isInjection(&self) -> BBoolean {
        if self.map.is_empty() { return BBoolean::new(true); }
        let mut ranges = self.map.values().cloned();
        let mut checked = ranges.next().unwrap();
        for to_check in ranges {
            //current range "hits" and element that was already "hit" before
            if !checked.clone().intersection(to_check.clone()).is_empty() { return BBoolean::new(false); }
            checked = checked.union(to_check);
        }
        return BBoolean::new(true);
    }

    pub fn isBijection(&self, range: &BSet<R>) -> BBoolean { return self.isSurjection(range).and(&self.isInjection()); }
    pub fn isBijectionInteger(&self) -> BBoolean { return BBoolean::new(false); }
    pub fn isBijectionNatural(&self) -> BBoolean { return BBoolean::new(false); }
    pub fn isBijectionNatural1(&self) -> BBoolean { return BBoolean::new(false); }
    pub fn isBijectionString(&self) -> BBoolean { return BBoolean::new(false); }
    pub fn isBijectionStruct(&self) -> BBoolean { return BBoolean::new(false); }
}


impl<L: 'static + BObject> BRelation<L, L> {
    pub fn identity(set: &BSet<L>) -> BRelation<L, L> {
        return set.iter().fold(BRelation::<L, L>::new(vec![]), |rel, v| rel.update_unit(v.clone(), v.clone()));
    }

    pub fn iterate(&self, n: &BInteger) -> BRelation<L, L> {
        return (0..n.get_val()).fold(BRelation::identity(&self.domain()._union(&self.range())),
                                     |rel, _| rel.composition(self));
    }

    pub fn closure(&self) -> BRelation<L, L> {
        return self.closure_closure1(false);
    }

    pub fn closure1(&self) -> BRelation<L, L> {
        return self.closure_closure1(true);
    }

    fn closure_closure1(&self, is_closure1: bool) -> BRelation<L, L> {
        let mut result = if is_closure1 { BRelation::new(vec![]) } else { self.iterate(&BInteger::new(0)) };
        let mut current_iteration = self.iterate(&BInteger::new(1));
        let mut next_result = result._union(&current_iteration);
        while !result.eq(&next_result) {
            result = next_result;
            current_iteration = current_iteration.composition(self);
            next_result = result._union(&current_iteration);
        }
        return result;
    }
}

//sequence
impl<L, R> BRelation<L, R>
where L: 'static + BInt + FromBInt,
      R: 'static + BObject {
    //this actually works, ridiculous...
    pub fn first(&self) -> R {
        return self.functionCall(&L::from(&BInteger::new(1)));
    }

    pub fn last(&self) -> R {
        return self.functionCall(&L::from(&self.card()));
    }

    pub fn reverse(&self) -> BRelation<L, R> {
        let size = self.card().succ();
        return BRelation {
            map: self.map.iter().fold(HashMap::<L, OrdSet<R>>::new(),
                                      |result, (k, v)|
                                          result.update(L::from(&size.minus(&k.get_binteger_value())), v.clone())),
        }
    }

    pub fn front(&self) -> BRelation<L, R> {
        return self.domainSubstraction(&BSet::new(vec![L::from(&self.card())]));
    }

    pub fn tail(&self) -> BRelation<L, R> {
        return self.drop(&BInteger::new(1))
    }

    pub fn take(&self, n: &BInteger) -> BRelation<L, R> {
        return self.domainRestriction(&BSet::new((1..n.get_val()+1).map(|i| L::from(&BInteger::new(i))).collect()));
    }

    pub fn drop(&self, n: &BInteger) -> BRelation<L, R> {
        return BSet::<BInteger>::interval(&n.succ(), &self.card()).iter().map(|i| (L::from(&i.minus(n)), L::from(i)))
            .fold(BRelation::<L, R>::new(vec![]), |rel, (i, i2)| rel.update(i, self.map.get(&i2).unwrap().clone()));
    }

    pub fn concat(&self, arg: &BRelation<L,R>) -> BRelation<L, R> {
        return arg.map.iter().fold(self.clone(), |rel, (k, v)|
            rel.update(L::from(&k.get_binteger_value().plus(&self.card())), v.clone()));
    }

    pub fn append(&self, arg: &R) -> BRelation<L, R> {
        return self.update_unit(L::from(&self.card().succ()), arg.clone());
    }

    pub fn prepend(&self, arg: &R) -> BRelation<L, R> {
        return self.map.iter().fold(self.clone(), |rel, (k, v)|
                                    rel.update(L::from(&k.get_binteger_value().succ()), v.clone()))
                   .update_unit(L::from(&self.card().succ()), arg.clone());
    }

    pub fn isPartialInteger(&self) -> BBoolean { return BBoolean::new(true); }
    pub fn checkDomainInteger(&self) -> BBoolean { return self.isPartialInteger(); }
    pub fn isPartialNatural(&self) -> BBoolean { return self.domain().subsetOfNatural(); }
    pub fn checkDomainNatural(&self) -> BBoolean { return self.isPartialNatural(); }
    pub fn isPartialNatural1(&self) -> BBoolean { return self.domain().subsetOfNatural1(); }
    pub fn checkDomainNatural1(&self) -> BBoolean { return self.isPartialNatural1(); }
}

impl<L, R> BRelation<L, R>
    where L: 'static + BInt + FromBInt,
          R: 'static + BObject + TBRelation,
          R::Left: 'static + BInt + FromBInt {

    pub fn conc(&self) -> BRelation<R::Left, R::Right> {
        return self.map.values().map(|set| set.iter().next().unwrap().get_as_brelation())
            .fold(BRelation::<R::Left, R::Right>::new(vec![]),
                  |result, next| result.concat(next));
    }
}

impl<L, R> BRelation<L, R>
    where L: 'static + BObject,
          R: 'static + BInt + FromBInt {

    pub fn checkRangeInteger(&self) -> BBoolean { return BBoolean::new(true); }
    pub fn checkRangeNatural(&self) -> BBoolean { return self.range().subsetOfNatural(); }
    pub fn checkRangeNatural1(&self) -> BBoolean { return self.range().subsetOfNatural1(); }
}

impl<L, R> BRelation<L, R>
where L: 'static + BObject,
      R: 'static + BObject + TBSet {

    pub fn rel(&self) -> BRelation<L, R::Item> {
        return self.map.iter().fold(BRelation::<L, R::Item>::new(vec![]), |rel, (key, range)|
            rel.update(key.clone(), range.iter().next().unwrap().as_ord_set()));
    }

}

impl<L, R> BRelation<L, R>
    where L: 'static + BObject + TBString,
          R: 'static + BObject {

    pub fn checkDomainString(&self) -> BBoolean { return BBoolean::new(true); }
    pub fn isPartialString(&self) -> BBoolean { return self.checkDomainString(); }
}

impl<L, R> BRelation<L, R>
    where L: 'static + BObject,
          R: 'static + BObject + TBString {

    pub fn checkRangeString(&self) -> BBoolean { return BBoolean::new(true); }
}

impl<L, R> BRelation<L, R>
where L: 'static + BObject + BStruct,
      R: 'static + BObject {

    pub fn checkDomainStruct(&self) -> BBoolean { return BBoolean::new(true); }
    pub fn isPartialStruct(&self) -> BBoolean { return self.checkDomainStruct(); }
}

impl<L, R> BRelation<L, R>
    where L: 'static + BObject,
          R: 'static + BObject + BStruct {

    pub fn checkRangeStruct(&self) -> BBoolean { return BBoolean::new(true); }
}

impl<L: 'static + BObject, R: 'static + BObject> SetLike for BRelation<L, R> {
    fn get_empty() -> Self { BRelation::<L, R>::new(vec![]) }
    fn _union(&self, other: &Self) -> Self { self._union(other) }
    fn intersect(&self, other: &Self) -> Self { self.intersect(other) }
}