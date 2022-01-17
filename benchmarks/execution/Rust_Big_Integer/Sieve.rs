#![ allow( dead_code, unused_imports, unused_mut, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::binteger::BInteger;
use btypes::bboolean::BBoolean;
use btypes::bset::BSet;



#[derive(Default, Debug)]
pub struct Sieve {
    numbers: BSet<BInteger>,
    cur: BInteger,
    limit: BInteger,
}

impl Sieve {

    pub fn new() -> Sieve {
        //values: ''
        let mut m: Sieve = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.numbers = BSet::<BInteger>::interval(&BInteger::new(b"2"), &BInteger::new(b"2000000")).clone().clone();
        self.cur = BInteger::new(b"2").clone();
        self.limit = BInteger::new(b"2000000").clone();
    }

    pub fn get_numbers(&self) -> BSet<BInteger> {
        return self.numbers.clone();
    }

    pub fn get_cur(&self) -> BInteger {
        return self.cur.clone();
    }

    pub fn get_limit(&self) -> BInteger {
        return self.limit.clone();
    }

    pub fn ComputeNumberOfPrimes(&mut self) -> BInteger {
        let mut res: Option<BInteger> = Option::None;
        while (self.cur.greater(&BInteger::new(b"1")).and(&self.cur.multiply(&self.cur).lessEqual(&self.limit))).booleanValue() {
            if (self.numbers.elementOf(&self.cur)).booleanValue() {
                let mut n: Option<BInteger> = Option::None;
                let mut set: Option<BSet<BInteger>> = Option::None;
                n = Option::Some(self.cur.clone());
                set = Option::Some(BSet::new(vec![]).clone()).clone();
                while (n.as_ref().unwrap().lessEqual(&self.limit.divide(&self.cur))).booleanValue() {
                    set = Option::Some(set.as_ref().unwrap()._union(&BSet::new(vec![self.cur.multiply(&n.as_ref().unwrap())])).clone()).clone();
                    n = Option::Some(n.as_ref().unwrap().plus(&BInteger::new(b"1")).clone());
                }
                self.numbers = self.numbers.difference(&set.as_ref().unwrap()).clone().clone();
            } 
            self.cur = self.cur.plus(&BInteger::new(b"1")).clone();
        }
        res = Option::Some(self.numbers.card().clone());
        return res.unwrap();
    }
}

