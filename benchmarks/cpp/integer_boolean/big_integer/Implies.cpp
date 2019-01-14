#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BBigInteger.cpp"
#include "BBoolean.cpp"

#ifndef Implies_H
#define Implies_H

using namespace std;

class Implies {



    private:



        BBigInteger counter;

    public:

        Implies() {
            counter = static_cast<BBigInteger >((BBigInteger("0")));
        }

        void simulate() {
            while(((BBigInteger("1")).equal((BBigInteger("1"))).implies(counter.less((BBigInteger("5000000"))))).booleanValue()) {
                counter = static_cast<BBigInteger >(counter.plus((BBigInteger("1"))));
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

