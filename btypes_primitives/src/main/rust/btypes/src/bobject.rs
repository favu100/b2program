use std::hash::Hash;
use std::clone::Clone;
use std::fmt;
use crate::bboolean::{BBoolean, BBooleanT};

pub trait BObject: Eq + Hash + Ord + Clone + fmt::Display {
    fn is_struct(&self) -> BBoolean { BBoolean::new(false) }
}

#[derive(Clone, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub struct Dummy {}
impl fmt::Display for Dummy {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result { write!(f, "None") }
}

impl BObject for Dummy {}
