#![ allow( non_snake_case) ]

use core::marker::PhantomData;
use crate::bboolean::BBoolean;
use crate::binteger::BInteger;
use crate::bset::{BSet, PowSetItem, Set, SetItem};

#[derive(Debug, Clone, Eq, PartialEq, Hash, PartialOrd, Ord)]
pub struct BRelation<L: SetItem<LS>, const LS: usize, R: SetItem<RS>, const RS: usize, const REL_SIZE: usize> {
    rel: [[bool; RS]; LS], // indexing: rel[l_idx][r_idx]
    _p: core::marker::PhantomData<L>,
    _p2: core::marker::PhantomData<R>,
}

impl<L, const LS: usize, R, const RS: usize, const REL_SIZE: usize> Default for BRelation<L, LS, R, RS, REL_SIZE>
where L: SetItem<LS>,
      R: SetItem<RS>{
    fn default() -> Self {
        BRelation { rel: [[false; RS]; LS], _p: PhantomData, _p2: PhantomData }
    }
}

pub trait RelLeftItem<const LEFT_SIZE: usize, RightItem: SetItem<RIGHT_SIZE>, const RIGHT_SIZE: usize, const REL_VARIANTS: usize, const REL_SIZE: usize>: SetItem<LEFT_SIZE> {
    type RelEnum: PowSetItem<REL_VARIANTS, REL_SIZE>;

    fn rel_to_idx(rel_arr: [[bool; RIGHT_SIZE]; LEFT_SIZE]) -> usize {
        let mut flat_arr = [false; REL_SIZE];
        for left_idx in 0..LEFT_SIZE {
            for right_idx in 0..RIGHT_SIZE {
                flat_arr[left_idx * RIGHT_SIZE + right_idx] = rel_arr[left_idx][right_idx];
            }
        }
        return Self::RelEnum::arr_to_idx(flat_arr);
    }

    fn idx_to_rel(idx: usize) -> [[bool; RIGHT_SIZE]; LEFT_SIZE] {
        let flat_arr = Self::RelEnum::idx_to_arr(idx);
        let mut result = [[false; RIGHT_SIZE]; LEFT_SIZE];
        for left_idx in 0..LEFT_SIZE {
            for right_idx in 0..RIGHT_SIZE {
                result[left_idx][right_idx] = flat_arr[left_idx * RIGHT_SIZE + right_idx];
            }
        }
        return result;
    }
}

impl<L, const LS: usize, R, const RS: usize, const SIZE: usize, const REL_SIZE: usize> SetItem<SIZE> for BRelation<L, LS, R, RS, REL_SIZE>
where L: SetItem<LS> + RelLeftItem<LS, R, RS, SIZE, REL_SIZE>,
      R: SetItem<RS>{
    fn as_idx(&self) -> usize {
        return L::rel_to_idx(self.rel);
    }

    fn from_idx(idx: usize) -> Self {
        return BRelation { rel: L::idx_to_rel(idx), _p: PhantomData, _p2: PhantomData };
    }
}

//impl<I> PowAble<> for I
//where I: SetItem<>
//TODO: pow/fin/pow1/fin1, maybe

impl<L, const LS: usize, R, const RS: usize, const REL_SIZE: usize> BRelation<L, LS, R, RS, REL_SIZE>
    where L: SetItem<LS>,
          R: SetItem<RS>{
    
    pub const fn empty() -> Self {
        BRelation { rel: [[false; RS]; LS], _p: PhantomData, _p2: PhantomData }
    }
    
    pub const fn copy(&self) -> Self {
        BRelation { rel: self.rel, _p: PhantomData, _p2: PhantomData }
    }

    pub fn _override_single(&self, left_item: L, right_item: R) -> Self {
        let mut result = self.copy();
        let left_idx = left_item.as_idx();
        let right_idx = right_item.as_idx();
        result.rel[left_idx] = [false; RS];
        result.rel[left_idx][right_idx] = true;
        return result;
    }

    pub fn add_tuple(&mut self, left_item: &L, right_item: &R) {
        //println!("adding tuple ({:?},{:?}), idx = [{}][{}]", left_item, right_item, left_item.as_idx(), right_item.as_idx());
        self.rel[left_item.as_idx()][right_item.as_idx()] = true;
    }

    //b2program has this name hardcoded...
    pub fn functionCall(&self, key: &L) -> R {
        let result_set: [bool; RS] = self.rel[key.as_idx()];
        for i in 0..RS {
            if result_set[i] { return R::from_idx(i) }
        }
        panic!("ERROR: key {:?} not found in set!", key);
    }

    pub fn fcall_to_set(&self, key: L) -> BSet<R, RS> {
        BSet::const_from_arr(self.rel[key.as_idx()])
    }

    pub fn card(&self) -> BInteger {
        let mut result: BInteger = 0;
        for left_idx in 0..LS {
            for right_idx in 0..RS {
                result += self.rel[left_idx][right_idx] as BInteger;
            }
        }
        return result;
    }

    //this name is also hard-coded...
    //checks if self.domain is a subset of the given set
    pub fn checkDomain(&self, domain: &BSet<L, LS>) -> bool {
        for left_idx in 0..LS {
            if self.rel[left_idx].contains(&true) && !domain.contains_idx(left_idx) {
                return false;
            }
        }
        return true
    }

    pub fn isPartial(&self, domain: &BSet<L, LS>) -> bool { self.checkDomain(domain) }

    pub fn isTotal(&self, domain: &BSet<L, LS>) -> bool {
        for left_idx in 0..LS {
            // self.domain.contains(left_idx) <=> domain.contains(left_idx)
            if self.rel[left_idx].contains(&true) != domain.contains_idx(left_idx) {
                return false;
            }
        }
        return true
    }

    //this name is also hard-coded...
    //checks if self.range is a subset of the given set
    pub fn checkRange(&self, range: &BSet<R, RS>) -> bool {
        for left_idx in 0..LS {
            for right_idx in 0..RS {
                if self.rel[left_idx][right_idx] && !range.contains_idx(right_idx) { return false; }
            }
        }
        return true;
    }

    //this name is also hard-coded...
    //checks if for each L there is at most one R
    pub fn isFunction(&self) -> bool {
        for left_idx in 0..LS {
            let mut found = false;
            for right_idx in 0..RS {
                if self.rel[left_idx][right_idx] {
                    if found { return false; }
                    found = true;
                }
            }
        }
        return true;
    }

    //checks f(x1) = f(x2) => x1 = x2
    pub fn isInjection(&self) -> bool {
        let mut checked = BSet::<R, RS>::empty(); //stores all the R's that were already 'used'
        for to_check in self.rel.iter().cloned().map(|arr| BSet::<R, RS>::const_from_arr(arr)) {
            if !checked.intersect(&to_check).is_empty() { return false; }
            checked = checked._union(&to_check);
        }
        return true;
    }

    pub fn domain(&self) -> BSet<L, LS> {
        let mut result = [false; LS];
        for i in 0..LS {
            if self.rel[i].contains(&true) { result[i] = true; }
        }
        return BSet::const_from_arr(result);
    }

    pub fn range(&self) -> BSet<R, RS> {
        let mut result = [false; RS];
        for left_idx in 0..LS {
            let current_arr = self.rel[left_idx];
            for right_idx in 0..RS {
                result[right_idx] |= current_arr[right_idx];
            }
        }
        return BSet::const_from_arr(result);
    }

    pub fn cartesian_product<TL, TR>(left_set: &TL, right_set: &TR) -> Self
        where TL: Set<LS, ItemType = L>,
              TR: Set<RS, ItemType = R> {
        let mut result = Self::empty();
        for l_idx in 0..LS {
            if left_set.contains_idx(l_idx) {
                result.rel[l_idx] = right_set.as_arr();
            }
        }
        return result;
    }

    pub fn inverse(&self) -> BRelation<R, RS, L, LS, REL_SIZE> {
        let mut result = BRelation::<R, RS, L, LS, REL_SIZE>::empty();
        for left_idx in 0..LS {
            for right_idx in 0..RS {
                result.rel[right_idx][left_idx] = self.rel[left_idx][right_idx];
            }
        }
        return result;
    }

    pub fn domainRestriction(&self, domain_set: &BSet<L, LS>) -> Self {
        let mut result = self.copy();
        for left_idx in 0..LS {
            if !domain_set.contains_idx(left_idx) { result.rel[left_idx] = [false; RS]; }
        }
        return result;
    }

    pub fn domainSubstraction(&self, domain_set: &BSet<L, LS>) -> Self {
        let mut result = self.copy();
        for left_idx in 0..LS {
            if domain_set.contains_idx(left_idx) { result.rel[left_idx] = [false; RS]; }
        }
        return result;
    }

    pub fn rangeRestriction(&self, range_set: &BSet<R, RS>) -> Self {
        let mut result = self.copy();
        let range_arr = range_set.as_arr();
        for left_idx in 0..LS {
            for right_idx in 0..RS {
                //retain only elements that are in self *and* in range_set
                result.rel[left_idx][right_idx] &= range_arr[right_idx];
            }
        }
        return result;
    }

    pub fn rangeSubstraction(&self, range_set: &BSet<R, RS>) -> Self {
        let mut result = self.copy();
        let range_arr = range_set.as_arr();
        for left_idx in 0..LS {
            for right_idx in 0..RS {
                //retain only elements that are in self *but not* in range_set
                result.rel[left_idx][right_idx] &= !range_arr[right_idx];
            }
        }
        return result;
    }

    pub fn relationImage(&self, result_domain: &BSet<L, LS>) -> BSet<R, RS> {
        let mut result_arr = [false; RS];
        for left_idx in 0..LS {
            if result_domain.contains_idx(left_idx) {
                for right_idx in 0..RS {
                    result_arr[right_idx] |= self.rel[left_idx][right_idx];
                }
            }
        }
        return BSet::<R, RS>::const_from_arr(result_arr);
    }

    pub fn intersect(&self, other: &Self) -> Self {
        return self.relation_combine(other, |s, o| s && o);
    }

    pub fn difference(&self, other: &Self) -> Self {
        return self.relation_combine(other, |s, o| s && !o);
    }

    pub fn _union(&self, other: &Self) -> Self {
        return self.relation_combine(other, |s, o| s | o);
    }

    fn relation_combine(&self, other: &Self, combine_fn: fn(bool, bool) -> bool) -> Self {
        let mut result = self.copy();
        for left_idx in 0..LS {
            for right_idx in 0..RS {
                result.rel[left_idx][right_idx] = combine_fn(result.rel[left_idx][right_idx], other.rel[left_idx][right_idx]);
            }
        }
        return result;
    }

    pub fn equal(&self, other: &Self) -> BBoolean {
        return self.rel.eq(&other.rel);
    }

    pub fn unequal(&self, other: &Self) -> BBoolean {
        return !self.rel.eq(&other.rel);
    }

    pub fn elementOf(&self, (k, v): (L, R)) -> BBoolean {
        return self.rel[k.as_idx()][v.as_idx()];
    }

    pub fn noElementOf(&self, (k, v): (L, R)) -> BBoolean {
        return !self.rel[k.as_idx()][v.as_idx()];
    }

    pub fn subset(&self, other: &Self) -> BBoolean {
        for left_idx in 0..LS {
            for right_idx in 0..RS {
                if other.rel[left_idx][right_idx] && !self.rel[left_idx][right_idx] { return false; }
            }
        }
        return true;
    }

    pub fn notSubset(&self, other: &Self) -> BBoolean {
        return !self.subset(other);
    }

    pub fn _override(&self, other: &Self) -> Self {
        let mut result = self.copy();
        for left_idx in 0..LS {
            if other.rel[left_idx].contains(&true) { result.rel[left_idx] = other.rel[left_idx]; }
        }
        return result;
    }

    //TODO: directProduct/ParallelProduct maybe?

    //TODO: support const-params in template? maybe compiler can figure them out itself?
    pub fn composition<NewR, const NewRS: usize, const ParamTotal: usize, const NewTotal: usize>(&self, arg: &BRelation<R, RS, NewR, NewRS, ParamTotal>) -> BRelation<L, LS, NewR, NewRS, NewTotal>
    where NewR: SetItem<NewRS>{
        let mut result = BRelation::<L, LS, NewR, NewRS, NewTotal>::empty();
        for left_idx in 0..LS {
            result.rel[left_idx] = arg.relationImage(&BSet::const_from_arr(self.rel[left_idx])).as_arr()
        }
        return result;
    }

    //TODO: projection1/2 maybe? would need to impl SetItem for (L,R) and (R,L), might need adjustment in codegenerator?
    //      or we use the relation-item enums for the tuples as well...

    //TODO: support const-params in template? maybe compiler can figure them out itself?
    pub fn fnc<NewR, const NewRS: usize, const newRelTotal: usize>(&self) -> BRelation<L, LS, NewR, NewRS, newRelTotal>
    where NewR: Set<RS> + SetItem<NewRS>{                                  //BRelation<L, LS, BSet<R, RS>, NewRS, newRelTotal
        //NewR::ItemType = R; not yet supported in rust, NewR: Set<RS, I = R> might be, but I'd need to rewrite the trait for that and the related code. For now, we assume the code-generator creates correct code (if it wouldn't the code probably wouldn't run anyway...)
        let mut result = BRelation::<L, LS, NewR, NewRS, newRelTotal>::empty();
        for left_idx in 0..LS {
            result.rel[left_idx][NewR::from_arr(self.rel[left_idx]).as_idx()] = true;
        }
        return result;
    }
}

#[macro_export]
macro_rules! brel {
    ($rel_type:ty $( ,$e:expr )* ) => {
        {
            let mut __temp_gen_rel__ = <$rel_type>::empty();
            $(
                __temp_gen_rel__.add_tuple($e.0, $e.1);
            )*
            __temp_gen_rel__
        }
    };
}