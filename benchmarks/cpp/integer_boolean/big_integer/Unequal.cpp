#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BBigInteger.cpp"
#include "BBoolean.cpp"

#ifndef Unequal_H
#define Unequal_H

using namespace std;

class Unequal {



    private:



        BBigInteger counter;

    public:

        Unequal() {
            counter = static_cast<BBigInteger >((BBigInteger("0")));
        }

        void simulate() {
            while((counter.less((BBigInteger("5000000")))._and((BBigInteger("1")).unequal((BBigInteger("2"))))).booleanValue()) {
                counter = static_cast<BBigInteger >(counter.plus((BBigInteger("1"))));
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

