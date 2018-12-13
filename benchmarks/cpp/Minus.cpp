#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef Minus_H
#define Minus_H

using namespace std;

class Minus {



    private:



        BInteger counter;
        BInteger value;

    public:

        Minus() {
            counter = static_cast<BInteger >((BInteger(0)));
            value = static_cast<BInteger >((BInteger(0)));
        }

        void simulate() {
            while((counter.less((BInteger(5000000)))).booleanValue()) {
                counter = static_cast<BInteger >(counter.plus((BInteger(1))));
                value = static_cast<BInteger >(value.minus((BInteger(1))));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    Minus exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

