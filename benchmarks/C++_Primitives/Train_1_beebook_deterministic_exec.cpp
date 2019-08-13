#include <iostream>
#include <string>
#include "BUtils.h"
#include "BInteger.h"
#include "BBoolean.h"
#include "BObject.h"
#include "Train_1_beebook_deterministic.cpp"

#ifndef Train_1_beebook_deterministic_exec_H
#define Train_1_beebook_deterministic_exec_H

using namespace std;

class Train_1_beebook_deterministic_exec {

    public:

    private:


        Train_1_beebook_deterministic _Train_1_beebook_deterministic;


        BInteger counter;

    public:

        Train_1_beebook_deterministic_exec() {
            counter = (BInteger(0));
        }

        void simulate() {
            while((counter.less((BInteger(10000)))).booleanValue()) {
                this->_Train_1_beebook_deterministic.route_reservation((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R1)));
                this->_Train_1_beebook_deterministic.route_reservation((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R4)));
                this->_Train_1_beebook_deterministic.point_positionning((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R1)));
                this->_Train_1_beebook_deterministic.point_positionning((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R4)));
                this->_Train_1_beebook_deterministic.route_formation((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R1)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_1((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R1)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::L)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::A)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::B)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::L)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::A)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::B)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_1((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::C)));
                this->_Train_1_beebook_deterministic.route_reservation((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R6)));
                this->_Train_1_beebook_deterministic.route_freeing((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R1)));
                this->_Train_1_beebook_deterministic.route_formation((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R4)));
                this->_Train_1_beebook_deterministic.point_positionning((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R6)));
                this->_Train_1_beebook_deterministic.route_formation((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R6)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_1((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R4)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::M)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_1((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R6)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::C)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::H)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::C)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::M)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::I)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::H)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::B)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::B)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::I)));
                this->_Train_1_beebook_deterministic.route_reservation((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R5)));
                this->_Train_1_beebook_deterministic.point_positionning((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R5)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::A)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::K)));
                this->_Train_1_beebook_deterministic.route_formation((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R5)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::A)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::K)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::F)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::F)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_1((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R5)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::M)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::M)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::H)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::H)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::I)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::J)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_1((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::L)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_1((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::G)));
                this->_Train_1_beebook_deterministic.route_reservation((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R1)));
                this->_Train_1_beebook_deterministic.point_positionning((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R1)));
                this->_Train_1_beebook_deterministic.route_formation((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R1)));
                this->_Train_1_beebook_deterministic.route_freeing((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R4)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::I)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::J)));
                this->_Train_1_beebook_deterministic.route_freeing((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R6)));
                this->_Train_1_beebook_deterministic.route_reservation((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R9)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_1((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R1)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_1((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::N)));
                this->_Train_1_beebook_deterministic.point_positionning((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R9)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::L)));
                this->_Train_1_beebook_deterministic.route_formation((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R9)));
                this->_Train_1_beebook_deterministic.route_freeing((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R5)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::L)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::A)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_1((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R9)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::B)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::G)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::A)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::G)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::B)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::F)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_1((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::C)));
                this->_Train_1_beebook_deterministic.route_reservation((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R6)));
                this->_Train_1_beebook_deterministic.point_positionning((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R6)));
                this->_Train_1_beebook_deterministic.route_formation((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R6)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::F)));
                this->_Train_1_beebook_deterministic.route_freeing((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R1)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::K)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::I)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::H)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_1((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R6)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::C)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::B)));
                this->_Train_1_beebook_deterministic.FRONT_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::A)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::K)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::I)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::H)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::C)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::B)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_2((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::A)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_1((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::L)));
                this->_Train_1_beebook_deterministic.BACK_MOVE_1((Train_1_beebook_deterministic::BLOCKS(Train_1_beebook_deterministic::BLOCKS::M)));
                this->_Train_1_beebook_deterministic.route_freeing((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R6)));
                this->_Train_1_beebook_deterministic.route_freeing((Train_1_beebook_deterministic::ROUTES(Train_1_beebook_deterministic::ROUTES::R9)));
                counter = counter.plus((BInteger(1)));
            }
        }

};

int main() {
    Train_1_beebook_deterministic_exec exec;
    exec.simulate();
    return 0;
}

#endif