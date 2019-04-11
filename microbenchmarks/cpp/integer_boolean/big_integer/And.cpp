#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef And_H
#define And_H

using namespace std;

class And {



    private:



        BInteger counter;

    public:

        And() {
            counter = (BInteger("0"));
        }

        void simulate() {
            while((counter.less((BInteger("5000000")))._and((BInteger("1")).equal((BInteger("1"))))).booleanValue()) {
                counter = counter.plus((BInteger("1")));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    And exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

