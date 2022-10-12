#![ allow( dead_code, unused, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::bobject;
use btypes::bboolean::{IntoBool, BBooleanT};
use btypes::binteger::BInteger;
use btypes::bboolean::BBoolean;
use btypes::bset::BSet;



#[derive(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct Sieve {
    numbers: BSet<BInteger>,
    cur: BInteger,
    limit: BInteger,
}

impl fmt::Display for Sieve {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let mut result = "Sieve: (".to_owned();
        result += &format!("_get_numbers: {}, ", self._get_numbers());
        result += &format!("_get_cur: {}, ", self._get_cur());
        result += &format!("_get_limit: {}, ", self._get_limit());
        result = result + ")";
        return write!(f, "{}", result);
    }
}

impl Sieve {

    pub fn new() -> Sieve {
        //values: ''
        let mut m: Sieve = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.numbers = BSet::<BInteger>::interval(&BInteger::new(2), &BInteger::new(2000000)).clone().clone();
        self.cur = BInteger::new(2);
        self.limit = BInteger::new(2000000);
    }

    pub fn _get_numbers(&self) -> BSet<BInteger> {
        return self.numbers.clone();
    }

    pub fn _get_cur(&self) -> BInteger {
        return self.cur.clone();
    }

    pub fn _get_limit(&self) -> BInteger {
        return self.limit.clone();
    }

    pub fn ComputeNumberOfPrimes(&mut self) -> BInteger {
        let mut res: Option<BInteger> = Option::None;
        while ((self.cur.greater(&BInteger::new(1)) && self.cur.multiply(&self.cur).lessEqual(&self.limit))).booleanValue() {
            if (self.numbers.elementOf(&self.cur)).booleanValue() {
                let mut n: Option<BInteger> = Option::None;
                let mut set: Option<BSet<BInteger>> = Option::None;
                n = Option::Some(self.cur);
                set = Option::Some(BSet::<BInteger>::new(vec![]).clone()).clone();
                while (n.unwrap().lessEqual(&self.limit.divide(&self.cur))).booleanValue() {
                    set = Option::Some(set.unwrap()._union(&BSet::new(vec![self.cur.multiply(&n.unwrap()).clone()])).clone()).clone();
                    n = Option::Some(n.unwrap().plus(&BInteger::new(1)));
                }
                self.numbers = self.numbers.difference(&set.unwrap()).clone().clone();
            }
            self.cur = self.cur.plus(&BInteger::new(1));
        }
        res = Option::Some(self.numbers.card());
        return res.unwrap();
    }
}

