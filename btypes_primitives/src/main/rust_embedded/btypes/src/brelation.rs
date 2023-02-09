#![ allow( non_snake_case) ]

use core::marker::PhantomData;
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
        for left_idx in 0..6 {
            for right_idx in 0..6 {
                flat_arr[left_idx * 6 + right_idx] = rel_arr[left_idx][right_idx];
            }
        }
        return Self::RelEnum::arr_to_idx(flat_arr);
    }

    fn idx_to_rel(idx: usize) -> [[bool; RIGHT_SIZE]; LEFT_SIZE] {
        let flat_arr = Self::RelEnum::idx_to_arr(idx);
        let mut result = [[false; RIGHT_SIZE]; LEFT_SIZE];
        for left_idx in 0..LEFT_SIZE {
            for right_idx in 0..RIGHT_SIZE {
                result[left_idx][right_idx] = flat_arr[left_idx * 6 + right_idx];
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

    pub fn _union(&self, other: &Self) -> Self {
        let mut result = self.copy();
        for left_idx in 0..LS {
            for right_idx in 0..RS {
                if other.rel[left_idx][right_idx] { result.rel[left_idx][right_idx] = true; }
            }
        }
        return result;
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