#![ allow( dead_code, unused, non_snake_case, non_camel_case_types, unused_assignments ) ]
//#![no_std] //std is enabled for the generated machine by default, since without it there is no println which makes unit-testing very difficult
use btypes::{bset, brel};
use btypes::bset::BSet;
use btypes::bset::SetItem;
use btypes::bset::PowSetItem;
use btypes::bset::PowAble;
use btypes::bset::NestedSet;
use btypes::brelation::BRelation;
use btypes::brelation::RelLeftItem;
use btypes::brelation::RelPowAble;
use btypes::bboolean::BBoolean;
use btypes::bboolean::BBool;
use btypes::bboolean::BOOL;
use btypes::binteger::BInteger;
use btypes::binteger::BInt;
use btypes::binteger::set_BInteger;
use btypes::btuple::BTuple;


mod Train_1_beebook_deterministic;




#[derive(Default, Debug)]pub struct Train_1_beebook_deterministic_exec {
    /*declarations*/counter: BInteger,
    /*includes*/_Train_1_beebook_deterministic: Train_1_beebook_deterministic::Train_1_beebook_deterministic,
}


impl Train_1_beebook_deterministic_exec {

    pub fn new() -> Train_1_beebook_deterministic_exec {
        //values: ''
        let mut m: Train_1_beebook_deterministic_exec = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        /*set_initializations*/
        /*properties*/
        /*body*/self.counter = 0;
        /*includesInitialization*/self._Train_1_beebook_deterministic = Train_1_beebook_deterministic::Train_1_beebook_deterministic::new();
    }

    pub fn get_counter(&self) -> BInteger {
        return self.counter.clone();
    }

    pub fn simulate(&mut self) -> () {
        while self.counter.less(&10000) {
            self._Train_1_beebook_deterministic.route_reservation(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R1);
            self._Train_1_beebook_deterministic.route_reservation(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R4);
            self._Train_1_beebook_deterministic.point_positionning(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R1);
            self._Train_1_beebook_deterministic.point_positionning(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R4);
            self._Train_1_beebook_deterministic.route_formation(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R1);
            self._Train_1_beebook_deterministic.FRONT_MOVE_1(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R1);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::L);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::A);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::B);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::L);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::A);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::B);
            self._Train_1_beebook_deterministic.BACK_MOVE_1(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::C);
            self._Train_1_beebook_deterministic.route_reservation(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R6);
            self._Train_1_beebook_deterministic.route_freeing(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R1);
            self._Train_1_beebook_deterministic.route_formation(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R4);
            self._Train_1_beebook_deterministic.point_positionning(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R6);
            self._Train_1_beebook_deterministic.route_formation(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R6);
            self._Train_1_beebook_deterministic.FRONT_MOVE_1(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R4);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::M);
            self._Train_1_beebook_deterministic.FRONT_MOVE_1(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R6);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::C);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::H);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::C);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::M);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::I);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::H);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::B);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::B);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::I);
            self._Train_1_beebook_deterministic.route_reservation(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R5);
            self._Train_1_beebook_deterministic.point_positionning(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R5);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::A);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::K);
            self._Train_1_beebook_deterministic.route_formation(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R5);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::A);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::K);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::F);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::F);
            self._Train_1_beebook_deterministic.FRONT_MOVE_1(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R5);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::M);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::M);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::H);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::H);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::I);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::J);
            self._Train_1_beebook_deterministic.BACK_MOVE_1(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::L);
            self._Train_1_beebook_deterministic.BACK_MOVE_1(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::G);
            self._Train_1_beebook_deterministic.route_reservation(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R1);
            self._Train_1_beebook_deterministic.point_positionning(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R1);
            self._Train_1_beebook_deterministic.route_formation(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R1);
            self._Train_1_beebook_deterministic.route_freeing(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R4);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::I);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::J);
            self._Train_1_beebook_deterministic.route_freeing(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R6);
            self._Train_1_beebook_deterministic.route_reservation(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R9);
            self._Train_1_beebook_deterministic.FRONT_MOVE_1(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R1);
            self._Train_1_beebook_deterministic.BACK_MOVE_1(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::N);
            self._Train_1_beebook_deterministic.point_positionning(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R9);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::L);
            self._Train_1_beebook_deterministic.route_formation(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R9);
            self._Train_1_beebook_deterministic.route_freeing(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R5);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::L);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::A);
            self._Train_1_beebook_deterministic.FRONT_MOVE_1(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R9);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::B);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::G);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::A);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::G);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::B);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::F);
            self._Train_1_beebook_deterministic.BACK_MOVE_1(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::C);
            self._Train_1_beebook_deterministic.route_reservation(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R6);
            self._Train_1_beebook_deterministic.point_positionning(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R6);
            self._Train_1_beebook_deterministic.route_formation(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R6);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::F);
            self._Train_1_beebook_deterministic.route_freeing(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R1);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::K);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::I);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::H);
            self._Train_1_beebook_deterministic.FRONT_MOVE_1(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R6);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::C);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::B);
            self._Train_1_beebook_deterministic.FRONT_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::A);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::K);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::I);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::H);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::C);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::B);
            self._Train_1_beebook_deterministic.BACK_MOVE_2(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::A);
            self._Train_1_beebook_deterministic.BACK_MOVE_1(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::L);
            self._Train_1_beebook_deterministic.BACK_MOVE_1(/*enum_call*/Train_1_beebook_deterministic::BLOCKS::M);
            self._Train_1_beebook_deterministic.route_freeing(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R6);
            self._Train_1_beebook_deterministic.route_freeing(/*enum_call*/Train_1_beebook_deterministic::ROUTES::R9);
            self.counter = self.counter.plus(&1);
        }
    }
}

fn main() {
    let mut exec = Train_1_beebook_deterministic_exec::new();
    exec.simulate();
}
