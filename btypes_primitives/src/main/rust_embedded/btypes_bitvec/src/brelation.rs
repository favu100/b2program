#![ allow( non_snake_case) ]

use core::convert::TryInto;
use core::marker::PhantomData;
use core::ops::{BitAnd, BitOrAssign};
use bitvec::mem;
use bitvec::array::BitArray;
use bitvec::prelude::Lsb0;
use crate::bboolean::BBoolean;
use crate::binteger::{BInt, BInteger};
use crate::bset::{BSet, PowSetItem, Set, SetItem};

#[derive(Debug, Clone, Eq, PartialEq, Hash, PartialOrd, Ord)]
pub struct BRelation<L: SetItem<LS>, const LS: usize, R: SetItem<RS>, const RS: usize, const REL_SIZE: usize>
where [usize; mem::elts::<usize>(LS*RS)]: Sized {
    rel: BitArray<[usize; mem::elts::<usize>(LS*RS)], Lsb0>, // indexing: rel[l_idx*RS + r_idx]
    _p: core::marker::PhantomData<L>,
    _p2: core::marker::PhantomData<R>,
}

impl<L, const LS: usize, R, const RS: usize, const REL_SIZE: usize> Default for BRelation<L, LS, R, RS, REL_SIZE>
where L: SetItem<LS>,
      R: SetItem<RS>,
      [usize; mem::elts::<usize>(LS*RS)]: Sized {
    fn default() -> Self {
        BRelation { rel: BitArray::ZERO, _p: PhantomData, _p2: PhantomData }
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
      R: SetItem<RS>,
      [usize; mem::elts::<usize>(LS*RS)]: Sized {
    fn as_idx(&self) -> usize {
        let mut rel_arr: [[bool; RS]; LS] = [[false; RS]; LS];
        for l_idx in 0..LS {
            let left_idx = l_idx * RS;
            for r_idx in 0..RS {
                rel_arr[l_idx][r_idx] = self.rel[left_idx + r_idx];
            }
        }
        return L::rel_to_idx(rel_arr);
    }

    fn from_idx(idx: usize) -> Self {
        let mut res = BitArray::<[usize; mem::elts::<usize>(LS*RS)], Lsb0>::ZERO;
        let rel_arr: [[bool; RS]; LS] = L::idx_to_rel(idx);
        for l_idx in 0..LS {
            let left_idx = l_idx * RS;
            for r_idx in 0..RS {
                res.set(left_idx + r_idx, rel_arr[l_idx][r_idx]);
            }
        }
        return BRelation { rel: res, _p: PhantomData, _p2: PhantomData };
    }
}


pub trait RelPowAble<const REL_VARIANTS: usize, const REL_SIZE: usize>: SetItem<REL_VARIANTS>
where [usize; mem::elts::<usize>(REL_VARIANTS)]: Sized {
    fn pow(&self) -> BSet<Self, REL_VARIANTS>;
    fn pow1(&self) -> BSet<Self, REL_VARIANTS>;
}

impl<L, const LS: usize, R, const RS: usize, const SIZE: usize, const REL_SIZE: usize> RelPowAble<SIZE, REL_SIZE> for BRelation<L, LS, R, RS, REL_SIZE>
    where L: SetItem<LS> + RelLeftItem<LS, R, RS, SIZE, REL_SIZE>,
          R: SetItem<RS>,
          [usize; mem::elts::<usize>(LS)]: Sized,
          [usize; mem::elts::<usize>(RS)]: Sized,
          [usize; mem::elts::<usize>(SIZE)]: Sized,
          [usize; mem::elts::<usize>(LS*RS)]: Sized {
    fn pow(&self) -> BSet<Self, SIZE> {
        let mut result_arr = [false; SIZE];
        for idx in 0..SIZE {
            let crel = Self::from_idx(idx);
            result_arr[idx] = crel.subset(&self);
        }
        return BSet::<Self, SIZE>::from_arr(result_arr);
    }

    fn pow1(&self) -> BSet<Self, SIZE> {
        let mut result_arr = self.pow().as_arr();
        let empty_self = Self::empty();
        let empty_idx = empty_self.as_idx();
        result_arr[empty_idx] = false;
        return BSet::from_arr(result_arr);
    }
}



pub trait TBRelation {
    fn isPartialInteger(&self) -> BBoolean { false }
    fn checkDomainInteger(&self) -> BBoolean { false }
    fn isPartialNatural(&self) -> BBoolean { false }
    fn checkDomainNatural(&self) -> BBoolean { false }
    fn isPartialNatural1(&self) -> BBoolean { false }
    fn checkDomainNatural1(&self) -> BBoolean { false }
    fn checkRangeInteger(&self) -> BBoolean { false }
    fn checkRangeNatural(&self) -> BBoolean { false }
    fn checkRangeNatural1(&self) -> BBoolean { false }
    fn checkDomainString(&self) -> BBoolean { false }
    fn isPartialString(&self) -> BBoolean { false }
    fn checkRangeString(&self) -> BBoolean { false }
    fn checkDomainStruct(&self) -> BBoolean { false }
    fn isPartialStruct(&self) -> BBoolean { false }
    fn checkRangeStruct(&self) -> BBoolean { false }
}

impl<L: SetItem<LS>, const LS: usize, R: SetItem<RS>, const RS: usize, const REL_SIZE: usize> TBRelation for BRelation<L, LS, R, RS, REL_SIZE>
where [usize; mem::elts::<usize>(LS*RS)]: Sized {}

impl<L, const LS: usize, R, const RS: usize, const REL_SIZE: usize> BRelation<L, LS, R, RS, REL_SIZE>
    where L: SetItem<LS>,
          R: SetItem<RS>,
          [usize; mem::elts::<usize>(LS)]: Sized,
          [usize; mem::elts::<usize>(RS)]: Sized,
          [usize; mem::elts::<usize>(LS*RS)]: Sized {
    
    pub const fn empty() -> Self {
        BRelation { rel: BitArray::ZERO, _p: PhantomData, _p2: PhantomData }
    }
    
    pub const fn copy(&self) -> Self {
        BRelation { rel: self.rel, _p: PhantomData, _p2: PhantomData }
    }

    pub fn slice_as_array(&self, left_idx: usize) -> [bool; RS] {
        let l_idx = left_idx*RS;
        let mut result = [false; RS];
        for i in 0..RS { result[i] = self.rel[l_idx+i]; }
        return result;
    }

    //TODO: pub fn iter(&self) -> BRelIter<L, LS, R, RS> { BRelIter::new(self.rel) }

    pub fn _override_single(&self, left_item: L, right_item: R) -> Self {
        let mut result = self.copy();
        let left_idx = left_item.as_idx();
        let right_idx = right_item.as_idx();
        result.rel[left_idx*RS .. (left_idx*RS + RS-1)].fill(false);
        result.rel.set(left_idx*RS + right_idx, true);
        return result;
    }

    pub fn add_tuple(&mut self, left_item: &L, right_item: &R) {
        //println!("adding tuple ({:?},{:?}), idx = [{}][{}]", left_item, right_item, left_item.as_idx(), right_item.as_idx());
        self.rel.set(left_item.as_idx()*RS + right_item.as_idx(), true);
    }

    //b2program has this name hardcoded...
    pub fn functionCall(&self, key: &L) -> R {
        let l_idx = key.as_idx()*RS;
        for i in 0..RS {
            if self.rel[l_idx+i] { return R::from_idx(i) }
        }
        panic!("ERROR: key {:?} not found in set!", key);
    }
/*
    pub fn fcall_to_set(&self, key: L) -> BSet<R, RS> {
        let l_idx = key.as_idx()*RS;
        let mut res = [false; RS];
        for i in 0..RS {
            res[i] = self.rel[l_idx+i];
        }
        return BSet::from_arr(res);
    }
*/
    pub fn card(&self) -> BInteger {
        return self.rel[0 .. RS*LS].count_ones().try_into().unwrap();
    }

    //this name is also hard-coded...
    //checks if self.domain is a subset of the given set
    pub fn checkDomain(&self, domain: &BSet<L, LS>) -> bool {
        for left_idx in 0..LS {
            if !domain.contains_idx(left_idx) && self.rel[left_idx * RS..(left_idx + 1) * RS].any() {
                return false;
            }
        }
        return true
    }

    pub fn isPartial(&self, domain: &BSet<L, LS>) -> bool { self.checkDomain(domain) }

    pub fn isTotal(&self, domain: &BSet<L, LS>) -> bool {
        for left_idx in 0..LS {
            // self.domain.contains(left_idx) <=> domain.contains(left_idx)
            if domain.contains_idx(left_idx) != self.rel[left_idx * RS..(left_idx + 1) * RS].any() {
                return false;
            }
        }
        return true
    }

    //this name is also hard-coded...
    //checks if self.range is a subset of the given set
    pub fn checkRange(&self, range: &BSet<R, RS>) -> bool {
        let range_arr = range.as_bitarray();
        for left_idx in 0..LS {
            let current_range = &self.rel[left_idx * RS..(left_idx + 1) * RS];
            if (range_arr & current_range) != current_range {
                return false;
            }
        }
        return true
    }

    //this name is also hard-coded...
    //checks if for each L there is at most one R
    pub fn isFunction(&self) -> bool {
        for left_idx in 0..LS {
            if self.rel[left_idx*RS .. (left_idx+1)*RS].count_ones() > 1 { return false; }
        }
        return true;
    }

    //checks f(x1) = f(x2) => x1 = x2
    pub fn isInjection(&self) -> bool {
        let mut checked = BitArray::<[usize; mem::elts::<usize>(RS)], Lsb0>::ZERO; //stores all the R's that were already 'used'
        for i in 0..LS {
            let current_slice = &self.rel[i*RS .. (i+1)*RS];
            if checked.bitand(current_slice).any() { return false; } // one R of current slice is already in checked -> no injection
            checked |= current_slice;
        }
        return true;
    }

    pub fn domain(&self) -> BSet<L, LS> {
        let mut result = BitArray::<[usize; mem::elts::<usize>(LS)], Lsb0>::ZERO;
        for i in 0..LS {
            result.set(i, self.rel[i*RS .. (i+1)*RS].any());
        }
        return BSet::<L, LS>::from_bitarray(result);
    }

    pub fn range(&self) -> BSet<R, RS> {
        let mut result = BitArray::<[usize; mem::elts::<usize>(RS)], Lsb0>::ZERO;
        for left_idx in 0..LS {
            result |= &self.rel[left_idx*RS .. (left_idx+1)*RS];
        }
        return BSet::<R, RS>::from_bitarray(result);
    }

    pub fn cartesian_product<TL, TR>(left_set: &TL, right_set: &TR) -> Self
        where TL: Set<LS, ItemType = L>,
              TR: Set<RS, ItemType = R> {
        let right_arr = right_set.as_bitarray();
        let mut bit_mask = BitArray::<[usize; mem::elts::<usize>(RS)], Lsb0>::ZERO;
        let mut result = Self::empty();
        for l_idx in 0..LS {
            bit_mask.fill(left_set.contains_idx(l_idx));
            result.rel[l_idx*RS .. (l_idx+1)*RS].copy_from_bitslice(&(right_arr & bit_mask));
        }
        return result;
    }

    pub fn inverse(&self) -> BRelation<R, RS, L, LS, REL_SIZE>
    where [usize; mem::elts::<usize>(RS*LS)]: Sized {
        let mut result = BRelation::<R, RS, L, LS, REL_SIZE>::empty();
        for left_idx in 0..LS {
            for right_idx in 0..RS {
                result.rel.set(right_idx*LS + left_idx, self.rel[left_idx*RS + right_idx]);
            }
        }
        return result;
    }

    pub fn domainRestriction(&self, domain_set: &BSet<L, LS>) -> Self {
        let mut result = self.copy();
        for left_idx in 0..LS {
            if !domain_set.contains_idx(left_idx) { result.rel[left_idx*RS .. (left_idx+1)*RS].fill(false); }
        }
        return result;
    }

    pub fn domainSubstraction(&self, domain_set: &BSet<L, LS>) -> Self {
        let mut result = self.copy();
        for left_idx in 0..LS {
            if domain_set.contains_idx(left_idx) { result.rel[left_idx*RS .. (left_idx+1)*RS].fill(false); }
        }
        return result;
    }

    pub fn rangeRestriction(&self, range_set: &BSet<R, RS>) -> Self {
        let mut result = self.copy();
        let range_arr = range_set.as_bitarray();
        for left_idx in 0..LS {
            //retain only elements that are in self *and* in range_set
            result.rel[left_idx*RS .. (left_idx+1)*RS] &= range_arr;
        }
        return result;
    }

    pub fn rangeSubstraction(&self, range_set: &BSet<R, RS>) -> Self {
        let mut result = self.copy();
        let not_range_arr = !range_set.as_bitarray();
        for left_idx in 0..LS {
            //retain only elements that are in self *but not* in range_set
            result.rel[left_idx*RS .. (left_idx+1)*RS] &= not_range_arr;
        }
        return result;
    }

    pub fn relationImage(&self, result_domain: &BSet<L, LS>) -> BSet<R, RS> {
        let mut result_arr = BitArray::<[usize; mem::elts::<usize>(RS)], Lsb0>::ZERO;
        for left_idx in 0..LS {
            if result_domain.contains_idx(left_idx) {
                result_arr.bitor_assign(&self.rel[left_idx*RS .. (left_idx+1)*RS]);
            }
        }
        return BSet::<R, RS>::from_bitarray(result_arr);
    }

    pub fn intersect(&self, other: &Self) -> Self {
        let mut result = self.copy();
        result.rel &= other.rel;
        return result;
    }

    pub fn difference(&self, other: &Self) -> Self {
        let mut result = self.copy();
        result.rel &= !other.rel;
        return result;
    }

    pub fn union(&self, other: &Self) -> Self {
        let mut result = self.copy();
        result.rel |= other.rel;
        return result;
    }

    pub fn equal(&self, other: &Self) -> BBoolean {
        return self.rel.eq(&other.rel);
    }

    pub fn unequal(&self, other: &Self) -> BBoolean {
        return !self.rel.eq(&other.rel);
    }

    pub fn elementOf(&self, (k, v): &(L, R)) -> BBoolean {
        return self.rel[k.as_idx()*RS + v.as_idx()];
    }

    pub fn noElementOf(&self, (k, v): &(L, R)) -> BBoolean {
        return !self.rel[k.as_idx()*RS + v.as_idx()];
    }

    //subset or equal
    pub fn subset(&self, other: &Self) -> BBoolean {
        return (other.rel & self.rel) == self.rel;
    }

    pub fn notSubset(&self, other: &Self) -> BBoolean {
        return !self.subset(other);
    }

    pub fn _override(&self, other: &Self) -> Self {
        let mut result = self.copy();
        for left_idx in 0..LS {
            let other_slice = &other.rel[left_idx*RS .. (left_idx+1)*RS];
            if other_slice.any() { result.rel[left_idx*RS .. (left_idx+1)*RS].copy_from_bitslice(other_slice); }
        }
        return result;
    }

    //TODO: directProduct/ParallelProduct maybe?

    pub fn composition<NewR, const NEW_RS: usize, const PARAM_TOTAL: usize, const NEW_TOTAL: usize>(&self, arg: &BRelation<R, RS, NewR, NEW_RS, PARAM_TOTAL>) -> BRelation<L, LS, NewR, NEW_RS, NEW_TOTAL>
    where NewR: SetItem<NEW_RS>,
          [usize; mem::elts::<usize>(NEW_RS)]: Sized,
          [usize; mem::elts::<usize>(RS*NEW_RS)]: Sized,
          [usize; mem::elts::<usize>(LS*NEW_RS)]: Sized {
        let mut result = BRelation::<L, LS, NewR, NEW_RS, NEW_TOTAL>::empty();
        for left_idx in 0..LS {
            let l_idx = left_idx*NEW_RS;
            //let mut foo: BitArray<[usize; mem::elts::<usize>(NEW_RS)], Lsb0> = BitArray::ZERO;
            for r_idx in 0..RS {
                if self.rel[l_idx+r_idx] { result.rel[l_idx .. l_idx+NEW_RS] |= &arg.rel[r_idx*NEW_RS .. (r_idx+1)*NEW_RS]; }
            }
            //result.rel[l_idx .. l_idx+NEW_RS].copy_from_bitslice(&foo);
        }
        return result;
    }

    //TODO: projection1/2 maybe? would need to impl SetItem for (L,R) and (R,L), might need adjustment in codegenerator?
    //      or we use the relation-item enums for the tuples as well...
    //BRelation<L,R> -> BRelation<L, BTuple<L, R>>
    //BSet<BTuple<L, R>>

    //TODO: support const-params in template? maybe compiler can figure them out itself?
    pub fn fnc<NewR, const NEW_RS: usize, const NEW_REL_TOTAL: usize>(&self) -> BRelation<L, LS, NewR, NEW_RS, NEW_REL_TOTAL>
    where NewR: Set<RS> + SetItem<NEW_RS>,                                  //BRelation<L, LS, BSet<R, RS>, NewRS, newRelTotal
          [usize; mem::elts::<usize>(NEW_RS)]: Sized,
          [usize; mem::elts::<usize>(LS*NEW_RS)]: Sized {
        let mut result = BRelation::<L, LS, NewR, NEW_RS, NEW_REL_TOTAL>::empty();
        for left_idx in 0..LS {
            let result_set: [bool; RS] = self.slice_as_array(left_idx);
            if !result_set.contains(&true) { continue; } // dont create mappings to empty set
            result.rel.set(left_idx*LS + NewR::from_arr(result_set).as_idx(), true);
        }
        return result;
    }

    //pub fn nondeterminism(&self) -> (L, R) {
    //    !todo!(RNG does not work without std/external crates)
    //}

    pub fn isTotalInteger(&self) -> BBoolean { return false; }
    pub fn isTotalNatural(&self) -> BBoolean { return false; }
    pub fn isTotalNatural1(&self) -> BBoolean { return false; }
    pub fn isTotalString(&self) -> BBoolean { return false; }
    pub fn isTotalStruct(&self) -> BBoolean { return false; }
    pub fn isRelation(&self) -> BBoolean { return true;}
    pub fn isSurjection(&self, range: &BSet<R, RS>) -> BBoolean { return self.range().equal(range); }
    pub fn isSurjectionInteger(&self) -> BBoolean { return false; }
    pub fn isSurjectionNatural(&self) -> BBoolean { return false; }
    pub fn isSurjectionNatural1(&self) -> BBoolean { return false; }
    pub fn isSurjectionString(&self) -> BBoolean { return false; }
    pub fn isSurjectionStruct(&self) -> BBoolean { return false; }
    pub fn isBijection(&self, range: &BSet<R, RS>) -> BBoolean { return self.isSurjection(range) && self.isInjection(); }
    pub fn isBijectionInteger(&self) -> BBoolean { return false; }
    pub fn isBijectionNatural(&self) -> BBoolean { return false; }
    pub fn isBijectionNatural1(&self) -> BBoolean { return false; }
    pub fn isBijectionString(&self) -> BBoolean { return false; }
    pub fn isBijectionStruct(&self) -> BBoolean { return false; }
}

impl<L, const LS: usize, const REL_SIZE: usize> BRelation<L, LS, L, LS, REL_SIZE>
where L: SetItem<LS>,
      [usize; mem::elts::<usize>(LS)]: Sized,
      [usize; mem::elts::<usize>(LS*LS)]: Sized {
    pub fn identity(set: &BSet<L, LS>) -> Self {
        let mut result = Self::empty();
        for i in 0..LS {
            if set.contains_idx(i) { result.rel.set(i*(LS+1), true); }
        }
        return result;
    }

    pub fn iterate(&self, n: &BInteger) -> Self {
        return (0..*n).fold(BRelation::identity(&self.domain().union(&self.range())),
                                     |rel, _| rel.composition(self));
    }

    pub fn closure(&self) -> Self { return self.closure_closure1(false); }

    pub fn closure1(&self) -> Self { return self.closure_closure1(true); }

    fn closure_closure1(&self, is_closure1: bool) -> Self {
        let mut result = if is_closure1 { Self::empty() } else { self.iterate(&0) };
        let mut current_iteration = self.iterate(&1);
        let mut next_result = result.union(&current_iteration);
        while !result.equal(&next_result) {
            result = next_result;
            current_iteration = current_iteration.composition(self);
            next_result = result.union(&current_iteration);
        }
        return result;
    }
}

//Sequence
impl<L, const LS: usize, R, const RS: usize, const REL_SIZE: usize> BRelation<L, LS, R, RS, REL_SIZE>
where L: SetItem<LS> + BInt,
      R: SetItem<RS>,
      [usize; mem::elts::<usize>(LS)]: Sized,
      [usize; mem::elts::<usize>(RS)]: Sized,
      [usize; mem::elts::<usize>(LS*RS)]: Sized {

    pub fn first(&self) -> R { self.functionCall(&L::from(1)) }
    pub fn last(&self) -> R { self.functionCall(&L::from(self.card())) }
    pub fn size(&self) -> BInteger { self.card() }

    pub fn concat(&self, other: &Self) -> Self {
        let mut result = self.copy();
        let self_size = self.size();
        for i in 1..=other.size() {
            result.add_tuple(&L::from(self_size + i), &other.functionCall(&L::from(i)));
        }
        return result;
    }

    pub fn prepend(&self, e: &R) -> Self {
        let mut result = Self::empty();
        result.add_tuple(&L::from(1), e);
        return result.concat(self);
    }

    pub fn append(&self, e: &R) -> Self {
        let mut result = self.copy();
        result.add_tuple(&L::from(self.size()+1), e);
        return result;
    }

    pub fn reverse(&self) -> Self {
        let mut result = Self::empty();
        let self_size = self.size();
        for i in 1..=self_size {
            result.add_tuple(&L::from(i), &self.functionCall(&L::from(self_size - i + 1)))
        }
        return result;
    }

    pub fn front(&self) -> Self {
        return self.take(&self.size().pred());
    }

    pub fn tail(&self) -> Self {
        return self.drop(&1);
    }

    pub fn take(&self, n: &BInteger) -> Self {
        let mut result = self.copy();
        for i in (*n+1)..=self.size() {
            let i_as_l = L::from(i);
            result.rel.set(i_as_l.as_idx()*RS + self.functionCall(&i_as_l).as_idx(), false);
        }
        return result;
    }

    pub fn drop(&self, n: &BInteger) -> Self {
        let mut result = Self::empty();
        for i in (*n+1)..=self.size() {
            result.add_tuple(&L::from(i-(*n)), &self.functionCall(&L::from(i)))
        }
        return result;
    }

    pub fn isPartialInteger(&self) -> BBoolean { true }
    pub fn checkDomainInteger(&self) -> BBoolean { return self.isPartialInteger(); }
    pub fn isPartialNatural(&self) -> BBoolean { return self.domain().subsetOfNatural(); }
    pub fn checkDomainNatural(&self) -> BBoolean { return self.isPartialNatural(); }
    pub fn isPartialNatural1(&self) -> BBoolean { return self.domain().subsetOfNatural1(); }
    pub fn checkDomainNatural1(&self) -> BBoolean { return self.isPartialNatural1(); }
}

impl<L, const LS: usize, R, const RS: usize, const REL_SIZE: usize> BRelation<L, LS, R, RS, REL_SIZE>
where L: SetItem<LS>,
      R: SetItem<RS> + BInt,
      [usize; mem::elts::<usize>(LS)]: Sized,
      [usize; mem::elts::<usize>(RS)]: Sized,
      [usize; mem::elts::<usize>(LS*RS)]: Sized {
    pub fn checkRangeInteger(&self) -> BBoolean { true }
    pub fn checkRangeNatural(&self) -> BBoolean { return self.range().subsetOfNatural(); }
    pub fn checkRangeNatural1(&self) -> BBoolean { return self.range().subsetOfNatural1(); }
}


pub struct BRelIter<L: SetItem<LS>, const LS: usize, R: SetItem<RS>, const RS: usize> {
    brel: [[bool; RS]; LS],
    c_l: usize,
    c_r: usize,
    _p: PhantomData<L>,
    _p2: PhantomData<R>,
}

impl<L: SetItem<LS>, const LS: usize, R: SetItem<RS>, const RS: usize> BRelIter<L, LS, R, RS> {
    pub const fn new(arr: [[bool; RS]; LS]) -> Self { BRelIter { brel: arr, c_l: 0, c_r: 0, _p: PhantomData, _p2: PhantomData } }
}

impl<L: SetItem<LS>, const LS: usize, R: SetItem<RS>, const RS: usize> Iterator for BRelIter<L, LS, R, RS> {
    type Item = (L, R);

    fn next(&mut self) -> Option<Self::Item> {
        while self.c_l < LS {
            while self.c_r < RS {
                if self.brel[self.c_l][self.c_r] {
                    self.c_r += 1;
                    return Option::Some((L::from_idx(self.c_l), R::from_idx(self.c_r-1)));
                }
                self.c_r += 1;
            }
            self.c_l += 1;
            self.c_r = 0;
        }
        return Option::None;
    }
}


/* // Does not work in stable rust
impl<L, const LS: usize, R, const RS: usize, const TOTAL: usize, const INNER_RS: usize> BRelation<L, LS, R, RS, TOTAL>
  where L: SetItem<LS>,
        R: SetItem<RS> + Set<RS>,
        R::ItemType: SetItem<INNER_RS>{
    pub fn rel<const NEWSIZE: usize>(&self) -> BRelation<L, LS, R::ItemType, INNER_RS, NEWSIZE> {
        let result = BRelation::<L, LS, R::ItemType, R::ItemType::VARIS, NEWSIZE>::empty();
        return result;
    }
}
*/
/* //Needs SetItem on (L, R)/BTuple
impl<L, const LS: usize, R, const RS: usize, const REL_SIZE: usize> Set<REL_SIZE> for BRelation<L, LS, R, RS, REL_SIZE>
where L: SetItem<LS>,
      R: SetItem<RS> {

}
*/
#[macro_export]
macro_rules! brel {
    ($rel_type:ty $( ,$e:expr )* ) => {
        {
            let mut __temp_gen_rel__ = <$rel_type>::empty();
            $(
                __temp_gen_rel__.add_tuple(&$e.0, &$e.1);
            )*
            __temp_gen_rel__
        }
    };
}