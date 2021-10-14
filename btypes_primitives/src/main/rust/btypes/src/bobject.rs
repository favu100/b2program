use std::hash::Hash;
use std::clone::Clone;
use crate::binteger::BInteger;
use std::fmt::Display;
use crate::bboolean::BBoolean;

pub trait BObject: Eq + Hash + Ord + Clone + Display {
    fn get_binteger_value(&self) -> BInteger { panic!("get_integer_value not implemented!"); }

    fn is_struct(&self) -> BBoolean { BBoolean::new(false) }
}