use std::hash::Hash;
use std::clone::Clone;
use std::fmt::Display;
use crate::bboolean::BBoolean;

pub trait BObject: Eq + Hash + Ord + Clone + Display {
    fn is_struct(&self) -> BBoolean { BBoolean::new(false) }
}