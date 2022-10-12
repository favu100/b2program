#![ allow( dead_code, unused, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::bobject;
use btypes::bboolean::{IntoBool, BBooleanT};
use btypes::binteger::BInteger;
use btypes::bboolean::BBoolean;
use btypes::bobject::BObject;
mod Train_1_beebook_deterministic;



#[derive(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct Train_1_beebook_deterministic_exec {
    counter: BInteger,
    _Train_1_beebook_deterministic: Train_1_beebook_deterministic::Train_1_beebook_deterministic,
}

impl fmt::Display for Train_1_beebook_deterministic_exec {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let mut result = "Train_1_beebook_deterministic_exec: (".to_owned();
        result += &format!("_get_counter: {}, ", self._get_counter());
        result = result + ")";
        return write!(f, "{}", result);
    }
}

impl Train_1_beebook_deterministic_exec {

    pub fn new() -> Train_1_beebook_deterministic_exec {
        //values: ''
        let mut m: Train_1_beebook_deterministic_exec = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.counter = BInteger::new(0);
        self._Train_1_beebook_deterministic = Train_1_beebook_deterministic::Train_1_beebook_deterministic::new();
    }

    pub fn _get_counter(&self) -> BInteger {
        return self.counter.clone();
    }

    pub fn simulate(&mut self) -> () {
        while (self.counter.less(&BInteger::new(10000))).booleanValue() {
            self._Train_1_beebook_deterministic.route_reservation(Train_1_beebook_deterministic::ROUTES::R1);
            self._Train_1_beebook_deterministic.route_reservation(Train_1_beebook_deterministic::ROUTES::R4);
            self._Train_1_beebook_deterministic.point_positionning(Train_1_beebook_deterministic::ROUTES::R1);
            self._Train_1_beebook_deterministic.point_positionning(Train_1_beebook_deterministic::ROUTES::R4);
            self._Train_1_beebook_deterministic.route_formation(Train_1_beebook_deterministic::ROUTES::R1);
            self._Train_1_beebook_deterministic.FRONT_MOVE_1(Train_1_beebook_deterministic::ROUTES::R1);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::L);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::A);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::B);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::L);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::A);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::B);
            self._Train_1_beebook_deterministic.BACK_MOVE_1(Train_1_beebook_deterministic::BLOCKS::C);
            self._Train_1_beebook_deterministic.route_reservation(Train_1_beebook_deterministic::ROUTES::R6);
            self._Train_1_beebook_deterministic.route_freeing(Train_1_beebook_deterministic::ROUTES::R1);
            self._Train_1_beebook_deterministic.route_formation(Train_1_beebook_deterministic::ROUTES::R4);
            self._Train_1_beebook_deterministic.point_positionning(Train_1_beebook_deterministic::ROUTES::R6);
            self._Train_1_beebook_deterministic.route_formation(Train_1_beebook_deterministic::ROUTES::R6);
            self._Train_1_beebook_deterministic.FRONT_MOVE_1(Train_1_beebook_deterministic::ROUTES::R4);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::M);
            self._Train_1_beebook_deterministic.FRONT_MOVE_1(Train_1_beebook_deterministic::ROUTES::R6);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::C);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::H);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::C);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::M);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::I);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::H);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::B);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::B);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::I);
            self._Train_1_beebook_deterministic.route_reservation(Train_1_beebook_deterministic::ROUTES::R5);
            self._Train_1_beebook_deterministic.point_positionning(Train_1_beebook_deterministic::ROUTES::R5);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::A);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::K);
            self._Train_1_beebook_deterministic.route_formation(Train_1_beebook_deterministic::ROUTES::R5);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::A);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::K);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::F);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::F);
            self._Train_1_beebook_deterministic.FRONT_MOVE_1(Train_1_beebook_deterministic::ROUTES::R5);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::M);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::M);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::H);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::H);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::I);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::J);
            self._Train_1_beebook_deterministic.BACK_MOVE_1(Train_1_beebook_deterministic::BLOCKS::L);
            self._Train_1_beebook_deterministic.BACK_MOVE_1(Train_1_beebook_deterministic::BLOCKS::G);
            self._Train_1_beebook_deterministic.route_reservation(Train_1_beebook_deterministic::ROUTES::R1);
            self._Train_1_beebook_deterministic.point_positionning(Train_1_beebook_deterministic::ROUTES::R1);
            self._Train_1_beebook_deterministic.route_formation(Train_1_beebook_deterministic::ROUTES::R1);
            self._Train_1_beebook_deterministic.route_freeing(Train_1_beebook_deterministic::ROUTES::R4);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::I);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::J);
            self._Train_1_beebook_deterministic.route_freeing(Train_1_beebook_deterministic::ROUTES::R6);
            self._Train_1_beebook_deterministic.route_reservation(Train_1_beebook_deterministic::ROUTES::R9);
            self._Train_1_beebook_deterministic.FRONT_MOVE_1(Train_1_beebook_deterministic::ROUTES::R1);
            self._Train_1_beebook_deterministic.BACK_MOVE_1(Train_1_beebook_deterministic::BLOCKS::N);
            self._Train_1_beebook_deterministic.point_positionning(Train_1_beebook_deterministic::ROUTES::R9);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::L);
            self._Train_1_beebook_deterministic.route_formation(Train_1_beebook_deterministic::ROUTES::R9);
            self._Train_1_beebook_deterministic.route_freeing(Train_1_beebook_deterministic::ROUTES::R5);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::L);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::A);
            self._Train_1_beebook_deterministic.FRONT_MOVE_1(Train_1_beebook_deterministic::ROUTES::R9);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::B);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::G);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::A);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::G);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::B);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::F);
            self._Train_1_beebook_deterministic.BACK_MOVE_1(Train_1_beebook_deterministic::BLOCKS::C);
            self._Train_1_beebook_deterministic.route_reservation(Train_1_beebook_deterministic::ROUTES::R6);
            self._Train_1_beebook_deterministic.point_positionning(Train_1_beebook_deterministic::ROUTES::R6);
            self._Train_1_beebook_deterministic.route_formation(Train_1_beebook_deterministic::ROUTES::R6);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::F);
            self._Train_1_beebook_deterministic.route_freeing(Train_1_beebook_deterministic::ROUTES::R1);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::K);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::I);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::H);
            self._Train_1_beebook_deterministic.FRONT_MOVE_1(Train_1_beebook_deterministic::ROUTES::R6);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::C);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::B);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic::BLOCKS::A);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::K);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::I);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::H);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::C);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::B);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic::BLOCKS::A);
            self._Train_1_beebook_deterministic.BACK_MOVE_1(Train_1_beebook_deterministic::BLOCKS::L);
            self._Train_1_beebook_deterministic.BACK_MOVE_1(Train_1_beebook_deterministic::BLOCKS::M);
            self._Train_1_beebook_deterministic.route_freeing(Train_1_beebook_deterministic::ROUTES::R6);
            self._Train_1_beebook_deterministic.route_freeing(Train_1_beebook_deterministic::ROUTES::R9);
            self.counter = self.counter.plus(&BInteger::new(1));
        }
    }
}

fn main() {
    let mut exec = Train_1_beebook_deterministic_exec::new();
    exec.simulate();
}

