#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef Equivalent_H
#define Equivalent_H

using namespace std;

class Equivalent {



    private:



        BInteger counter;

    public:

        Equivalent() {
            counter = (BInteger("0"));
        }

        void simulate() {
            while((counter.less((BInteger("5000000"))).equivalent((BInteger("1")).equal((BInteger("1"))))).booleanValue()) {
                counter = counter.plus((BInteger("1")));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    Equivalent exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

