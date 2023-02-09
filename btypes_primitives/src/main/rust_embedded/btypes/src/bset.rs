#![ allow( non_snake_case) ]

use core::fmt::Debug;
use core::marker::PhantomData;
use crate::binteger::BInteger;

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
    fn from_arr(arr: [bool; SIZE]) -> Self;
    fn contains_idx(&self, idx: usize) -> bool;
    //checks if self is a subset of other
    fn subset_of(&self, other: &Self) -> bool;

}

#[derive(Debug, Clone, Eq, PartialEq, Hash, PartialOrd, Ord)]
pub struct BSet<I: SetItem<SIZE>, const SIZE: usize> {
    arr: [bool; SIZE],
    _p: PhantomData<I>,
}

impl<I: SetItem<SIZE>, const SIZE: usize> Default for BSet<I, SIZE> {
    fn default() -> Self { BSet { arr: [false; SIZE], _p: PhantomData } }
}

impl<I: SetItem<SIZE>, const SIZE: usize> Set<SIZE> for BSet<I, SIZE> {
    type ItemType = I;
    fn as_arr(&self) -> [bool; SIZE] { self.arr }
    fn from_arr(arr: [bool; SIZE]) -> Self { BSet { arr: arr, _p: PhantomData } }
    fn contains_idx(&self, idx: usize) -> bool { self.arr[idx] }
    fn subset_of(&self, other: &Self) -> bool {
        for i in 0..SIZE {
            if self.arr[i] && !other.arr[i] { return false; }
        }
        return true;
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
    where I: SetItem<SIZE> + PowSetItem<POWSIZE, SIZE> {
    fn as_idx(&self) -> usize { I::arr_to_idx(self.as_arr()) }
    fn from_idx(idx: usize) -> Self { Self::const_from_arr(I::idx_to_arr(idx)) }
}

impl<const SETVARIANTS: usize, const ITEMVARIANTS: usize, const A: usize, I> PowSetItem<SETVARIANTS, ITEMVARIANTS> for BSet<I, A>
    where I: SetItem<A> + PowSetItem<ITEMVARIANTS, A>,
          I::SetRepr: SetItem<ITEMVARIANTS> + PowSetItem<SETVARIANTS, ITEMVARIANTS> {
    type SetRepr = <<I as PowSetItem<ITEMVARIANTS, A>>::SetRepr as PowSetItem<SETVARIANTS, ITEMVARIANTS>>::SetRepr;
    fn arr_to_idx(set_arr: [bool; ITEMVARIANTS]) -> usize { I::SetRepr::arr_to_idx(set_arr) }
    fn idx_to_arr(idx: usize) -> [bool; ITEMVARIANTS] { I::SetRepr::idx_to_arr(idx) }
}

pub trait PowAble<const SETLEN: usize, const ITEMVARS: usize>: Set<SETLEN> + SetItem<ITEMVARS> {
    fn pow(&self) -> BSet<Self, ITEMVARS>;
}

/// To generate the powerset of a BSet we need the corresponding enum already generated.
/// This is the case if the BSet implements the [SetItem]-trait, so here we generically implement
/// the pow-function for any struct that implements [Set] and [SetItem]
/// (In theory, this would then automatically extend to BRelations as well, if we implement the traits there)
impl<const SETLEN: usize, const ITEMVARS: usize , I> PowAble<SETLEN, ITEMVARS> for I
    where I: Set<SETLEN> + SetItem<ITEMVARS>{

    fn pow(&self) -> BSet<Self, ITEMVARS> {
        let mut result = BSet::<Self, ITEMVARS>::empty();
        for idx in 0..ITEMVARS {
            let a = Self::from_idx(idx);
            if a.subset_of(self) { result.arr[idx] = true; }
        }
        return result;
    }
}


impl<I: SetItem<SIZE>, const SIZE: usize> BSet<I, SIZE> {
    pub const fn empty() -> Self { BSet { arr: [false; SIZE], _p: PhantomData } }
    pub const fn copy(&self) -> Self { BSet { arr: self.arr, _p: PhantomData } }
    pub const fn const_from_arr(arr: [bool; SIZE]) -> Self { BSet { arr: arr, _p: PhantomData } }
    pub const fn iter(&self) -> BSetIter<I, SIZE> { BSetIter::new(self.arr) }
    pub fn add(&mut self, element: I) { self.arr[element.as_idx()] = true; }

    pub fn is_empty(&self) -> bool { !self.arr.contains(&true) }

    pub fn equal(&self, other: &Self) -> bool { self.arr.eq(&other.arr) }

    pub fn card(&self) -> BInteger {
        return self.arr.iter().fold(0,
                             |size, next_item| if *next_item { size + 1 }
                                                                 else { size });
    }

    pub fn subset(&self, other: &Self) -> bool { self.subset_of(other) }

    pub fn _union(&self, other: &Self) -> Self {
        let mut result = self.copy();
        for i in 0..SIZE {
            if other.arr[i] { result.arr[i] = true; }
        }
        return result;
    }

    pub fn difference(&self, other: &Self) -> Self {
        let mut result = self.copy();
        for i in 0..SIZE {
            if other.arr[i] { result.arr[i] = false; }
        }
        return result;
    }

    pub fn intersect(&self, other: &Self) -> Self {
        let mut result = Self::empty();
        for i in 0..SIZE {
            if self.arr[i] && other.arr[i] { result.arr[i] = true; }
        }
        return result;
    }

    //name hard-coded in b2program
    pub fn elementOf(&self, element: &I) -> bool { self.arr[element.as_idx()] }
    pub fn notElementOf(&self, element: &I) -> bool { !self.arr[element.as_idx()] }
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
            BSet::<$set_type, { <$set_type>::VARIANTS }>::const_from_arr(__temp_gen_arr__)
        }
    };
}
