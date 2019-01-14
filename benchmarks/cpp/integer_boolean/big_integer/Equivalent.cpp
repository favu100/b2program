#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BBigInteger.cpp"
#include "BBoolean.cpp"

#ifndef Equivalent_H
#define Equivalent_H

using namespace std;

class Equivalent {



    private:



        BBigInteger counter;

    public:

        Equivalent() {
            counter = static_cast<BBigInteger >((BBigInteger("0")));
        }

        void simulate() {
            while((counter.less((BBigInteger("5000000"))).equivalent((BBigInteger("1")).equal((BBigInteger("1"))))).booleanValue()) {
                counter = static_cast<BBigInteger >(counter.plus((BBigInteger("1"))));
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

