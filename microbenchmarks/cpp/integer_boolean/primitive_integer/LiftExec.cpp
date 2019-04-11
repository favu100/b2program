#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"
#include "Lift.cpp"

#ifndef LiftExec_H
#define LiftExec_H

using namespace std;

class LiftExec {



    private:

        Lift _Lift;


        BInteger counter;

    public:

        LiftExec() {
            counter = (BInteger(0));
        }

        void simulate() {
            while((counter.less((BInteger(3000)))).booleanValue()) {
                BInteger i;
                i = (BInteger(0));
                while((i.less((BInteger(100)))).booleanValue()) {
                    this->_Lift.inc();
                    i = i.plus((BInteger(1)));
                }
                BInteger _i;
                _i = (BInteger(0));
                while((_i.less((BInteger(100)))).booleanValue()) {
                    this->_Lift.dec();
                    _i = _i.plus((BInteger(1)));
                }
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    LiftExec exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

