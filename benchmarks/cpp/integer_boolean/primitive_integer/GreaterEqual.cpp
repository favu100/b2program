#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef GreaterEqual_H
#define GreaterEqual_H

using namespace std;

class GreaterEqual {



    private:



        BInteger counter;

    public:

        GreaterEqual() {
            counter = (BInteger(0));
        }

        void simulate() {
            while((counter.less((BInteger(5000000)))._and((BInteger(2)).greaterEqual((BInteger(1))))).booleanValue()) {
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    GreaterEqual exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

