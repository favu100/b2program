#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef Unequal_H
#define Unequal_H

using namespace std;

class Unequal {



    private:



        BInteger counter;

    public:

        Unequal() {
            counter = static_cast<BInteger >((BInteger(0)));
        }

        void simulate() {
            while((counter.less((BInteger(5000000)))._and((BInteger(1)).unequal((BInteger(2))))).booleanValue()) {
                counter = static_cast<BInteger >(counter.plus((BInteger(1))));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    Unequal exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

