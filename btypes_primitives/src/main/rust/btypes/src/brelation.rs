use std::collections::LinkedList;
use crate::bobject::BObject;
use crate::binteger::{BInt, BInteger, FromBInt};
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
        return result_relation;
    }

    pub fn composition<NewR: 'static + BObject>(&self, arg: &BRelation<R, NewR>) -> BRelation<L, NewR> {
        let mut result_set: BRelation<L, NewR> = BRelation::new(vec![]);
        let empty_set = OrdSet::<NewR>::new();
        for (this_key, this_range) in self.map.iter() {
            let new_range = this_range.iter().fold(OrdSet::<NewR>::new(),
                                                   |set, element| set.union(arg.map.get(element).unwrap_or(&empty_set).clone()));
            if !new_range.is_empty() { result_set.map.insert(this_key.clone(), new_range); }
        }
        return result_set;//TODO
    }

    pub fn identity(&self) {
        //TODO
    }
}


impl<L: 'static + BObject> BRelation<L, L> {
    pub fn iterate(&self, n: &BInteger) -> BRelation<L, L> {
        return [0..n.pred().get_val()].iter()
            .fold(self.clone(), |rel, _| rel._union(&rel.composition(self)));
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

    pub fn reverse(&self) -> BRelation<R, L> {
        return BRelation {
            map: self.map.iter().fold(HashMap::<R, OrdSet<L>>::new(),
                                      |result, (k, v)|
                                          result.update(v.iter().next().unwrap().clone(), OrdSet::unit(k.clone()))),
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

    //TODO: pub fn concat(&self, arg: &BRelation<L,R>) -> BRelation<L, R> {}

    //TODO: pub fn conc(&self) -> BRelation<Ln, Rn> {} ??

    //TODO: pub fn append(&self, arg: &T) -> BRelation<L, R> {}

    //TODO: pub fn prepend(&self, arg: &T) -> BRelation<L, R> {}
}