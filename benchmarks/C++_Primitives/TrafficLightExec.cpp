#include <iostream>
#include <string>
#include "BUtils.h"
#include "BInteger.h"
#include "BBoolean.h"
#include "TrafficLight.cpp"

#ifndef TrafficLightExec_H
#define TrafficLightExec_H

using namespace std;

class TrafficLightExec {

    public:

    private:


        TrafficLight _TrafficLight;


        BInteger counter;

    public:

        TrafficLightExec() {
            counter = (BInteger(0));
        }

        void simulate() {
            while((counter.less((BInteger(300000000)))).booleanValue()) {
                this->_TrafficLight.cars_ry();
                this->_TrafficLight.cars_g();
                this->_TrafficLight.cars_y();
                this->_TrafficLight.cars_r();
                this->_TrafficLight.peds_g();
                this->_TrafficLight.peds_r();
                counter = counter.plus((BInteger(1)));
            }
        }
};

int main() {
    TrafficLightExec exec;
    exec.simulate();
    return 0;
}

#endif