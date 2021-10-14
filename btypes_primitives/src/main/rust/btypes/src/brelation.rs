use crate::BObject;

use btuple::BTuple;

use immutable_map::TreeMap;

#[derive(Default, Debug, Copy, Clone)]
pub struct BRelation<L: BObject, R: BObject> {
    map: TreeMap<L, R>,
}

impl BObject for BRelation {}

impl<L: BObject, R: BObject> BRelation<L, R> {
    fn new() -> BRelation {

    }
}