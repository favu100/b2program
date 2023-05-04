#![ allow( non_snake_case) ]

use core::fmt::Debug;
use core::marker::PhantomData;
use bitvec::array::BitArray;
use bitvec::mem;
use bitvec::prelude::Lsb0;
use crate::bboolean::BBoolean;
use crate::binteger;
use crate::binteger::{BInt, BInteger, set_BInteger};
use crate::brelation::BRelation;

/// Used to map an Enum to the position in a Set of it's type. \
/// This is necessary since, even though a [BSet] is alway represented as a flat, 1D-array,
/// we want to interact with the Set via more readable names, like the Enum itself. \
/// Especially when it comes to nested sets, we need to be able to consistently convert the subsets
/// into the corresponding array-index. This Trait, with its associated functions, allows us
/// (and Rust) to make sure that such a conversion[^note] always exists and is consistent.
///
/// Ex.: Assume the EnumeratedSet `Counters = {C1, C2, C3}` \
/// This will lead to the following enum in Rust (excerpt):
/// ```rust
/// pub enum Counters {
///     C1 = 0,
///     C2 = 1,
///     C3 = 2,
/// }
/// impl SetItem<3> for Counters{/*...*/}
/// type set_Counters = BSet<Counters, 3>;
/// ```
/// If we now create a set with that type, we can add elements to it simply by using these enums.
/// ```rust
/// let c: set_Counters = set_Counters::empty();
/// c.add(Counters::C2);
/// ```
///
/// [^note]: This conversion always goes in both directions, from enum to index and from index to enum.
pub trait SetItem<const VARIANTS: usize>: Default + Debug {

    /// Number of variations this SetItem has (i.e. size of the biggest set of this type)
    const VARIANTS: usize = VARIANTS;

    /// converts this SetItem into the index it corresponds to in any [BSet] of its type.
    fn as_idx(&self) -> usize;

    /// converts an index of any [BSet] of this SetItem's type into the SetItem. \
    /// Note: this is the inverse to [SetItem::as_idx], `set_item = SetItem::from_idx(set_item.as_idx())`
    fn from_idx(idx: usize) -> Self;
}



pub trait Set<const SIZE: usize>: Default {
    type ItemType: SetItem<SIZE>;

    fn as_arr(&self) -> [bool; SIZE];
    fn as_bitarray(&self) -> BitArray<[usize; mem::elts::<usize>(SIZE)], Lsb0>;
    fn from_arr(arr: [bool; SIZE]) -> Self;
    fn contains_idx(&self, idx: usize) -> bool;
    //checks if self is a subset of other
    fn subset_of(&self, other: &Self) -> bool;

}

#[derive(Debug, Clone, Eq, PartialEq, Hash, PartialOrd, Ord)]
pub struct BSet<I: SetItem<SIZE>, const SIZE: usize>
where [usize; mem::elts::<usize>(SIZE)]: Sized {
    arr: BitArray<[usize; mem::elts::<usize>(SIZE)], Lsb0>,
    //arr: BitArray<[usize; {SIZE - 1}], Lsb0>,
    _p: PhantomData<I>,
}

impl<I: SetItem<SIZE>, const SIZE: usize> Default for BSet<I, SIZE>
where [usize; mem::elts::<usize>(SIZE)]: Sized {
    fn default() -> Self { BSet { arr: BitArray::ZERO, _p: PhantomData } }
}

impl<I: SetItem<SIZE>, const SIZE: usize> Set<SIZE> for BSet<I, SIZE>
where [usize; mem::elts::<usize>(SIZE)]: Sized {
    type ItemType = I;
    fn as_arr(&self) -> [bool; SIZE] {
        let mut result = [false; SIZE];
        for i in 0..SIZE { result[i] = self.arr[i]; }
        return result;
    }

    fn as_bitarray(&self) -> BitArray<[usize; mem::elts::<usize>(SIZE)], Lsb0> { return self.arr.clone(); }
    fn from_arr(arr: [bool; SIZE]) -> Self {
        let mut bit_arr = BitArray::ZERO;
        for i in 0..SIZE {
            bit_arr.set(i, arr[i]);
        }
        return BSet { arr: bit_arr, _p: PhantomData };
    }
    fn contains_idx(&self, idx: usize) -> bool { self.arr[idx] }
    fn subset_of(&self, other: &Self) -> bool {
        return self.arr.eq(&(self.arr & other.arr));
    }
}

/// Used to link the Enum-representation of a Set to the Enum-representation of it's subtype wich
/// allows the use of [BSet]s as [SetItem]s.
///
/// In the generated code, we want to be able to use [BSet]s themselves as SetItems.
/// This way, we can write `let some_set: BSet<BSet<Counters>>` which not only makes the type
/// itself more readable, but any methods on `some_set` automatically use the 'correct' types. (i.e.
/// iterating through the elements of `some_set` would automatically iterate through elements of type
/// `BSet<Counters>`, instead of some enum-type.
///
/// To do this, [BSet] has to implement the [SetItem]-trait, which in turn requires an enum defining
/// every possible variation of that Set. Unfortunately, we cannot implement that trait for the
/// specific [BSet]s which need it during code-generation (Rust does not allow implementing external-traits
/// for external structs). \
/// However, we can implement the trait for [BSet] generically by defining some requirements that are
/// needed for the implementation to work correctly. This requirement is the existence of an enum
/// that fully represents the Set (i.e. carries one element for each possible SubSet). \
/// That enum is then linked to the enum of it's subtype via this [PowSetItem]-trait, which the
/// Rust-compiler can use to generate the specific impl's of the given Set (via the impl-definitions
/// defined below).
///
/// todo(): example?
///
///
/// SETVARIANTS-parameter is necessary to pass value along to SetItem-impl
/// (caclulation on the fly is not possible (yet, generic_const_exprs is unstable/nightly)
pub trait PowSetItem<const SETVARIANTS: usize, const ITEMVARIANTS: usize> {
    //const SETVARIANTS: usize = SETVARIANTS;
    //Implemented on top of SetItems, connects a SetItem to the Enum-representation of its Set
    //SetRepr used to impl PowSetItem for BSet
    type SetRepr: SetItem<SETVARIANTS>;
    fn arr_to_idx(set_arr: [bool; ITEMVARIANTS]) -> usize;
    fn idx_to_arr(idx: usize) -> [bool; ITEMVARIANTS];
}

impl<const SIZE: usize, const POWSIZE: usize, I> SetItem<POWSIZE> for BSet<I, SIZE>
    where I: SetItem<SIZE> + PowSetItem<POWSIZE, SIZE>,
          [usize; mem::elts::<usize>(SIZE)]: Sized {
    fn as_idx(&self) -> usize { I::arr_to_idx(self.as_arr()) }
    fn from_idx(idx: usize) -> Self { Self::from_arr(I::idx_to_arr(idx)) }
}

impl<const SETVARIANTS: usize, const ITEMVARIANTS: usize, const A: usize, I> PowSetItem<SETVARIANTS, ITEMVARIANTS> for BSet<I, A>
    where I: SetItem<A> + PowSetItem<ITEMVARIANTS, A>,
          I::SetRepr: SetItem<ITEMVARIANTS> + PowSetItem<SETVARIANTS, ITEMVARIANTS>,
          [usize; mem::elts::<usize>(A)]: Sized  {
    type SetRepr = <<I as PowSetItem<ITEMVARIANTS, A>>::SetRepr as PowSetItem<SETVARIANTS, ITEMVARIANTS>>::SetRepr;
    fn arr_to_idx(set_arr: [bool; ITEMVARIANTS]) -> usize { I::SetRepr::arr_to_idx(set_arr) }
    fn idx_to_arr(idx: usize) -> [bool; ITEMVARIANTS] { I::SetRepr::idx_to_arr(idx) }
}

pub trait PowAble<const SETLEN: usize, const ITEMVARS: usize>: Set<SETLEN> + SetItem<ITEMVARS>
where [usize; mem::elts::<usize>(ITEMVARS)]: Sized{
    fn pow(&self) -> BSet<Self, ITEMVARS>;
    fn pow1(&self) -> BSet<Self, ITEMVARS>;
    fn fin(&self) -> BSet<Self, ITEMVARS> { self.pow() }
    fn fin1(&self) -> BSet<Self, ITEMVARS> { self.pow1() }
}

/// To generate the powerset of a BSet we need the corresponding enum already generated.
/// This is the case if the BSet implements the [SetItem]-trait, so here we generically implement
/// the pow-function for any struct that implements [Set] and [SetItem]
/// (In theory, this would then automatically extend to BRelations as well, if we implement the traits there)
impl<const SETLEN: usize, const ITEMVARS: usize , I> PowAble<SETLEN, ITEMVARS> for I
    where I: Set<SETLEN> + SetItem<ITEMVARS>,
    [usize; mem::elts::<usize>(ITEMVARS)]: Sized {

    fn pow(&self) -> BSet<Self, ITEMVARS> {
        let mut result = BSet::<Self, ITEMVARS>::empty();
        for idx in 0..ITEMVARS {
            let a = Self::from_idx(idx);
            if a.subset_of(self) { result.arr.set(idx, true); }
        }
        return result;
    }

    fn pow1(&self) -> BSet<Self, ITEMVARS> {
        let mut result = self.pow();
        //remove empty set (usually, the index should always be 0, but this ensures that we get the correct one)
        result.arr.set(Self::from_arr([false; SETLEN]).as_idx(), false);
        return result;
    }
}


impl<I: SetItem<SIZE>, const SIZE: usize> BSet<I, SIZE>
where [usize; mem::elts::<usize>(SIZE)]: Sized  {
    pub const fn empty() -> Self { BSet { arr: BitArray::ZERO, _p: PhantomData } }
    pub const fn full() -> Self {
        let mut res = Self::empty();
        res.arr.data = [usize::MAX; mem::elts::<usize>(SIZE)];
        return res;
    }

    pub fn from_bitarray(arr: BitArray<[usize; mem::elts::<usize>(SIZE)], Lsb0>) -> Self { BSet { arr, _p: PhantomData } }

    pub const fn copy(&self) -> Self { BSet { arr: self.arr, _p: PhantomData } }
    pub fn from_arr(arr: [bool; SIZE]) -> Self { <Self as Set<SIZE>>::from_arr(arr) }
    pub fn iter(&self) -> BSetIter<I, SIZE> { BSetIter::new(self.as_arr()) } //TODO!
    pub fn add(&mut self, element: I) { self.arr.set(element.as_idx(), true); }
    pub fn add_idx(&mut self, idx: usize) { self.arr.set(idx, true); }

    pub fn is_empty(&self) -> bool { self.arr.is_empty() }

    pub fn equal(&self, other: &Self) -> BBoolean { self.arr.eq(&other.arr) }
    pub fn unequal(&self, other: &Self) -> BBoolean { !self.arr.eq(&other.arr) }

    pub fn card(&self) -> BInteger {
        return self.arr.iter().fold(0,
                             |size, next_item| if *next_item { size + 1 }
                                                                 else { size });
    }

    pub fn subset(&self, other: &Self) -> BBoolean { self.subset_of(other) }
    pub fn strictSubset(&self, other: &Self) -> BBoolean { self.card() < other.card() && self.subset_of(other) }
    pub fn notSubset(&self, other: &Self) -> BBoolean { !self.subset_of(other) }
    pub fn strictNotSubset(&self, other: &Self) -> BBoolean { self.card() >= other.card() || self.notSubset(other) }

    pub fn union(&self, other: &Self) -> Self {
        return BSet { arr: self.arr | other.arr, _p: PhantomData };
    }

    pub fn difference(&self, other: &Self) -> Self {
        return BSet { arr: self.arr ^ (self.arr & other.arr), _p: PhantomData };
    }

    pub fn intersect(&self, other: &Self) -> Self {
        return BSet { arr: self.arr & other.arr, _p: PhantomData };
    }

    //name hard-coded in b2program
    pub fn elementOf(&self, element: &I) -> BBoolean { self.arr[element.as_idx()] }
    pub fn notElementOf(&self, element: &I) -> BBoolean { !self.arr[element.as_idx()] }

    //TODO: nondeterminism needs external libraries

    pub fn interval(a: &BInteger, b: &BInteger) -> binteger::set_BInteger {
        let mut result = set_BInteger::empty();
        for idx in a.as_idx()..=b.as_idx() {
            result.arr.set(idx, true);
        }
        return result;
    }

    pub const fn equalInteger(&self) -> BBoolean { false }

    pub const fn unequalInteger(&self) -> BBoolean { true }

    pub const fn equalNatural(&self) -> BBoolean { false }

    pub const fn unequalNatural(&self) -> BBoolean { true }

    pub const fn equalNatural1(&self) -> BBoolean { false }

    pub const fn unequalNatural1(&self) -> BBoolean { true }

    pub const fn equalString(&self) -> BBoolean { false }

    pub const fn unequalString(&self) -> BBoolean { true }

    pub const fn equalStruct(&self) -> BBoolean { false }

    pub const fn unequalStruct(&self) -> BBoolean { true }

    pub const fn subsetOfString(&self) -> BBoolean { false } //TODO?

    pub const fn strictSubsetOfString(&self) -> BBoolean { return self.subsetOfString(); }

    pub const fn notSubsetOfString(&self) -> BBoolean { return !self.subsetOfString(); }

    pub const fn notStrictSubsetOfString(&self) -> BBoolean { return !self.strictSubsetOfString(); }

    pub const fn subsetOfStruct(&self) -> BBoolean { false } //TODO?

    pub const fn strictsubsetOfStruct(&self) -> BBoolean { return self.subsetOfStruct(); }

    pub const fn notsubsetOfStruct(&self) -> BBoolean { return !self.subsetOfStruct(); }

    pub const fn notStrictsubsetOfStruct(&self) -> BBoolean { return !self.strictsubsetOfStruct(); }

    //equals BRelation.checkDomain(BSet)
    pub fn check_domain_of<R, const RS: usize, const TOTAL_REL: usize>(&self, of: &BRelation<I, SIZE, R, RS, TOTAL_REL>) -> BBoolean
    where R: SetItem<RS>,
          [usize; mem::elts::<usize>(RS)]: Sized,
          [usize; mem::elts::<usize>(SIZE*RS)]: Sized {
        return self.is_superset(&of.domain());
    }

    //equals BRelation.checkRange(BSet)
    pub fn check_range_of<L, const LS: usize, const TOTAL_REL: usize>(&self, of: &BRelation<L, LS, I, SIZE, TOTAL_REL>) -> BBoolean
        where L: SetItem<LS>,
              [usize; mem::elts::<usize>(LS)]: Sized,
              [usize; mem::elts::<usize>(LS*SIZE)]: Sized {
        return self.is_superset(&of.range());
    }

    pub fn check_partial_of<R: SetItem<RS>, const RS: usize, const TOTAL_REL: usize>(&self, of: &BRelation<I, SIZE, R, RS, TOTAL_REL>) -> BBoolean
        where R: SetItem<RS>,
              [usize; mem::elts::<usize>(RS)]: Sized,
              [usize; mem::elts::<usize>(SIZE*RS)]: Sized {
        return self.is_superset(&of.domain());
    }

    pub fn is_superset(&self, other: &Self) -> BBoolean { return other.subset(self); }

    pub fn check_total_of<R: SetItem<RS>, const RS: usize, const TOTAL_REL: usize>(&self, of: &BRelation<I, SIZE, R, RS, TOTAL_REL>) -> BBoolean
        where R: SetItem<RS>,
              [usize; mem::elts::<usize>(RS)]: Sized,
              [usize; mem::elts::<usize>(SIZE*RS)]: Sized {
        return self.equal(&of.domain());
    }
}

impl <I: SetItem<SIZE> + BInt, const SIZE: usize> BSet<I, SIZE>
where [usize; mem::elts::<usize>(SIZE)]: Sized  {

    pub const fn subsetOfInteger(&self) -> BBoolean { true }

    pub const fn notSubsetOfInteger(&self) -> BBoolean { !self.subsetOfInteger() }

    pub const fn strictSubsetOfInteger(&self) -> BBoolean { self.subsetOfInteger() }

    pub fn notStrictSubsetOfInteger(&self) -> BBoolean { !self.strictSubsetOfInteger() }

    pub fn subsetOfNatural(&self) -> BBoolean {
        if binteger::LOWER_BOUND < 0 { // if LB >= 0, every Int-set only holds Integers >= 0
            for idx in 0..BInteger::as_idx(&0) {
                if self.arr[idx] { return false; }
            }
        }
        return true;
    }

    pub fn notSubsetOfNatural(&self) -> BBoolean { !self.subsetOfNatural() }

    pub fn strictSubsetOfNatural(&self) -> BBoolean { self.subsetOfNatural() }

    pub fn notStrictSubsetOfNatural(&self) -> BBoolean { self.strictSubsetOfNatural() }

    pub fn subsetOfNatural1(&self) -> BBoolean {
        if binteger::LOWER_BOUND < 1 {
            for idx in 0..BInteger::as_idx(&1) {
                if self.arr[idx] { return false; }
            }
        }
        // we could also do self.min() > 0, but that might be slower
        return true;
    }

    pub fn notSubsetOfNatural1(&self) -> BBoolean { !self.subsetOfNatural1() }

    pub fn strictSubsetOfNatural1(&self) -> BBoolean { self.subsetOfNatural() }

    pub fn notStrictSubsetOfNatural1(&self) -> BBoolean { !self.strictSubsetOfNatural1() }

    pub fn _min(&self) -> BInteger {
        for idx in 0..SIZE {
            if self.arr[idx] { return BInteger::from_idx(idx); }
        }
        panic!("Called min on empty Set!");
    }

    pub fn _max(&self) -> BInteger {
        for idx in (0..SIZE).rev() {
            if self.arr[idx] { return BInteger::from_idx(idx); }
        }
        panic!("Called max on empty Set!");
    }
}

/*
EINT: SetItem<4> + PowSetItem<16, 4>
BSet<EINT, 4>: Set<4> + SetItem<16>
BSet<BSet<Enit, 4>, 16>: Set<16>
*/

pub trait NestedSet<const OUTER_SIZE: usize, const INNER_SIZE: usize>
where Self: Set<OUTER_SIZE>,
      Self::ItemType: Set<INNER_SIZE> + SetItem<OUTER_SIZE> {

    fn unary_union(&self) -> Self::ItemType { self.unary_combine(|l, r| l || r) }
    fn unary_intersect(&self) -> Self::ItemType { self.unary_combine(|l, r| l && r) }
    fn unary_combine(&self, comb_fn: fn(left_bool:bool, right_bool: bool) -> bool) -> Self::ItemType;
}

/// Implements functions for nested-Sets.
/// A nested-Set is still just a 1D-array, but the Set-Item implements the Set-trait,
/// so the index can be converted to another 1D-array (this then being the representation of the inners Sets)
///
/// Because Rust is a bit constrained in how these implementations can be defined, we need to use
/// a trait to define how the specific Set should look, and then implement that trait generically for
/// any I that conforms to further constrictions.
/// (This will ulitmately only apply to BSets where the inner-type is also a BSet.)
impl<const OUTER_SIZE: usize, const INNER_SIZE: usize, I> NestedSet<OUTER_SIZE, INNER_SIZE> for I
where I: Set<OUTER_SIZE>,
      I::ItemType: Set<INNER_SIZE> + SetItem<OUTER_SIZE>{

    fn unary_combine(&self, comb_fn: fn(left_bool:bool, right_bool: bool) -> bool) -> I::ItemType {
        let mut result_arr = [false; INNER_SIZE]; // empty array representation of the inner settype
        for outer_idx in 0..OUTER_SIZE {
            if self.contains_idx(outer_idx) {
                let inner_set_arr = I::ItemType::from_idx(outer_idx).as_arr(); // array representation of the current inner-set
                for inner_idx in 0..INNER_SIZE { result_arr[inner_idx] = comb_fn(result_arr[inner_idx], inner_set_arr[inner_idx]); } // logical combination between the arrays (or = union; and = intersection between sets)
            }
        }
        return I::ItemType::from_arr(result_arr);
    }
}

pub struct BSetIter<I: SetItem<SIZE>, const SIZE: usize> {
    bset: [bool; SIZE],
    c: usize,
    _p: PhantomData<I>,
}

impl<I: SetItem<SIZE>, const SIZE: usize> BSetIter<I, SIZE> {
    pub const fn new(arr: [bool; SIZE]) -> Self { BSetIter { bset: arr, c: 0, _p: PhantomData } }
}

impl<I: SetItem<SIZE>, const SIZE: usize> Iterator for BSetIter<I, SIZE> {
    type Item = I;

    fn next(&mut self) -> Option<Self::Item> {
        while self.c < SIZE {
            if self.bset[self.c] {
                self.c += 1;
                return Option::Some(I::from_idx(self.c-1));
            }
            self.c += 1;
        }
        return Option::None;
    }
}

/// Macro to simplify the creation of [Bset]s.
/// Originally, this was supposed to only use constant expressions, so that
/// these could be evaluated at compile-time. However, in rust it is currently
/// not possible to define trait-functions as const, which would be necessary to make this
/// work generically.
#[macro_export]
macro_rules! bset {
    ($set_type:ty$(, $e:expr )* ) => {
        {
            let mut __temp_gen_arr__ = [false; <$set_type>::VARIANTS];
            $(
                __temp_gen_arr__[($e).as_idx()] = true;
            )*
            BSet::<$set_type, { <$set_type>::VARIANTS }>::from_arr(__temp_gen_arr__)
        }
    };
}
