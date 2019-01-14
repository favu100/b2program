#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BBigInteger.cpp"
#include "BBoolean.cpp"
#include "Lift.cpp"

#ifndef LiftExec_H
#define LiftExec_H

using namespace std;

class LiftExec {



    private:

        Lift _Lift;


        BBigInteger counter;

    public:

        LiftExec() {
            counter = static_cast<BBigInteger >((BBigInteger("0")));
        }

        void simulate() {
            while((counter.less((BBigInteger("3000")))).booleanValue()) {
                BBigInteger i;
                i = static_cast<BBigInteger >((BBigInteger("0")));
                while((i.less((BBigInteger("100")))).booleanValue()) {
                    this->_Lift.inc();
                    i = static_cast<BBigInteger >(i.plus((BBigInteger("1"))));
                }
                BBigInteger _i;
                _i = static_cast<BBigInteger >((BBigInteger("0")));
                while((_i.less((BBigInteger("100")))).booleanValue()) {
                    this->_Lift.dec();
                    _i = static_cast<BBigInteger >(_i.plus((BBigInteger("1"))));
                }
                counter = static_cast<BBigInteger >(counter.plus((BBigInteger("1"))));
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

