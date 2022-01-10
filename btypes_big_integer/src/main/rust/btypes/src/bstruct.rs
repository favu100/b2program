use crate::bboolean::BBoolean;
use crate::bobject::BObject;

pub trait BStruct: BObject{
    fn is_struct(&self) -> BBoolean { BBoolean::new(true) }
}