#![ allow( non_snake_case) ]

use core::fmt::Debug;
use core::marker::PhantomData;
use crate::binteger::BInteger;


pub trait SetItem<const VARIANTS: usize>: Default + Debug {
    //type SetEnumType: SetEnum<VARIANTS>;
    const VARIANTS: usize = VARIANTS; // number of variatins this SetItem has (i.e. lenght of an array necessary to build the maximum set)
    fn as_idx(&self) -> usize;
    fn from_idx(idx: usize) -> Self;
}

pub trait SetEnum<const ITEMVARIANTS: usize> { // Enum representing sets, Enum SetFoo = BSet<Foo>
    //type ItemType: SetItem<SIZE>;
    // SIZE = max-lenght of the Set
    fn as_idx(set_arr: [bool; ITEMVARIANTS]) -> usize;
    fn from_idx(idx: usize) -> [bool; ITEMVARIANTS];
}
/*
pub trait EnumRepresented<const SIZE: usize> {
    type SetRepr: SetEnum<SIZE>;
}
*/
pub trait PowEnumRepresented<const SETVARIANTS: usize, const ITEMVARIANTS: usize> {
    const SETVARIANTS: usize = SETVARIANTS;
    //Implemented on top of SetItems, connects a SetItem to the Enum-representation of its Set
    type SetRepr: SetEnum<ITEMVARIANTS>;
}

pub trait Set<const SIZE: usize>: Default {
    //type SetRepr: SetEnum<SIZE>;
    type ItemType: SetItem<SIZE>;

    fn as_arr(&self) -> [bool; SIZE];
    fn from_arr(arr: [bool; SIZE]) -> Self;
    fn contains_idx(&self, idx: usize) -> bool;
    //checks if self is a subset of other
    fn subset_of(&self, other: &Self) -> bool;
    //fn as_idx(&self) { Self::SetRepr::as_idx(self.as_arr()) }

    //fn contains(&self, other: T) {
    //    self[other.as_idx()]
    //}
}
/*
impl<const SIZE: usize, I, T> SetItem<SIZE> for T
where I: SetItem<SIZE> ,
      T: Set<I, SIZE> {
    type SetEnumType = T::SetRepr;
    fn as_idx(&self) -> usize { T::SetRepr::as_idx(self.as_arr()) }
    fn from_idx(idx: usize) -> Self { T::from_arr(T::SetRepr::from_idx(idx)) }
}*/
/*
Set<Person>::contains(Person)
  --> Set[Persion.idx()]
  --> SetEnum = PowPerson

Set<Set<Person>>::contains(Set<Person>)
  -> Set[Set<Persion>.idx()]
  ->

*/
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

impl<const SIZE: usize, const POWSIZE: usize, I> SetItem<POWSIZE> for BSet<I, SIZE>
    where I: SetItem<SIZE> + PowEnumRepresented<POWSIZE, SIZE> {

    fn as_idx(&self) -> usize { I::SetRepr::as_idx(self.as_arr()) }
    fn from_idx(idx: usize) -> Self { Self::const_from_arr(I::SetRepr::from_idx(idx)) }
}

pub trait PowAble<const SETLEN: usize, const ITEMVARS: usize>: Set<SETLEN> + SetItem<ITEMVARS> {
    fn pow(&self) -> BSet<Self, ITEMVARS>;
}

impl<const SETLEN: usize, const ITEMVARS: usize , I> PowAble<SETLEN, ITEMVARS> for I
    where I: Set<SETLEN> + SetItem<ITEMVARS>{

    //Self = BSet<SOCKET>
    //SETLEN = 2
    //ITEMVARS = 4

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

/*
impl<I: SetItem<SIZE> + PowEnumRepresented<SIZE>, const SIZE: usize> BSet<I, SIZE> {
    pub const fn to_idx(&self) -> usize {
        I::SetRepr::
    }
}
*/

// cannot make this const in rust yet, since we can't have const fns in traits
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