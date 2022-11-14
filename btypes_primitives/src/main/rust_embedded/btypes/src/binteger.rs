

pub type BInteger = i128;

pub trait BInt {
    fn equal(&self, other: Self) -> bool;
}

impl BInt for BInteger {
    fn equal(&self, other: Self) -> bool { self.eq(&other) }
}