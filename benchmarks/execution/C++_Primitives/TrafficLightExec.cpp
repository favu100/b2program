#include <iostream>
#include <string>
#include <btypes_primitives/BUtils.hpp>
#include <btypes_primitives/StateNotReachableError.hpp>
#include <btypes_primitives/PreconditionOrAssertionViolation.hpp>
#include <btypes_primitives/BBoolean.hpp>
#include <btypes_primitives/BInteger.hpp>
#include "TrafficLight.hpp"

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

        BInteger getCounter() {
            BInteger out;
            out = counter;
            return out;
        }

        BInteger _get_counter() const {
            return counter;
        }

        friend std::ostream& operator<<(std::ostream &strm, const TrafficLightExec &machine) {
          strm << "_TrafficLight: " << machine._TrafficLight << "\n";
          strm << "_get_counter: " << machine._get_counter() << "\n";
          return strm;
        }

};

int main() {
    TrafficLightExec exec;
    exec.simulate();
    cout << exec << "\n";
    return 0;
}

#endif