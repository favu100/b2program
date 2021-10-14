use std::fmt::{Display, Formatter};
use crate::bobject::BObject;

#[derive(Default, Debug, Clone, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub struct BString {
    val: String,
}

impl Display for BString {
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", self.val)
    }
}

impl BObject for BString {}