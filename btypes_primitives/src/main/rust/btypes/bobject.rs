use std::hash::Hash;
use std::clone::Clone;
use btypes::binteger::BInteger;
use std::fmt::Display;

pub trait BObject: Eq + Hash + Ord + Clone + Display {
    fn get_binteger_value(&self) -> BInteger { panic!("get_integer_value not implemented!"); }
}