#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef Negative_H
#define Negative_H

using namespace std;

class Negative {



    private:



        BInteger counter;
        BInteger value;

    public:

        Negative() {
            counter = static_cast<BInteger >((BInteger(0)));
            value = static_cast<BInteger >((BInteger(0)));
        }

        void simulate() {
            while((counter.less((BInteger(5000000)))).booleanValue()) {
                counter = static_cast<BInteger >(counter.plus((BInteger(1))));
                value = static_cast<BInteger >(value.negative());
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    Negative exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

