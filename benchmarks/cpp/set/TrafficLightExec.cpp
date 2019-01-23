#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"
#include "TrafficLight.cpp"

#ifndef TrafficLightExec_H
#define TrafficLightExec_H

using namespace std;

class TrafficLightExec {



    private:

        TrafficLight _TrafficLight;


        BInteger counter;

    public:

        TrafficLightExec() {
            counter = (BInteger(0));
        }

        void simulate() {
            while((counter.less((BInteger(500000)))).booleanValue()) {
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
    clock_t start,finish;
    double time;
    TrafficLightExec exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

