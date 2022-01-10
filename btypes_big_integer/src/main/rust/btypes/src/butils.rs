use crate::bboolean::BBoolean;
use crate::bset::BSet;

lazy_static! {
    pub static ref BOOL: BSet<BBoolean> = BSet::new(vec![BBoolean::new(true), BBoolean::new(false)]);
}