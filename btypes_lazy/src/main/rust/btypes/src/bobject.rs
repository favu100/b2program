use std::hash::Hash;
use std::clone::Clone;
use std::fmt::{Debug, Display};
use crate::bboolean::{BBoolean, BBooleanT};

pub trait BObject: Eq + Hash + Ord + Clone + Display + Debug {
    fn is_struct(&self) -> BBoolean { BBoolean::new(false) }
}