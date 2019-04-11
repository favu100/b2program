#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef Implies_H
#define Implies_H

using namespace std;

class Implies {



    private:



        BInteger counter;

    public:

        Implies() {
            counter = (BInteger(0));
        }

        void simulate() {
            while(((BInteger(1)).equal((BInteger(1))).implies(counter.less((BInteger(5000000))))).booleanValue()) {
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    Implies exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

