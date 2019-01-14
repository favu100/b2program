#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BBigInteger.cpp"
#include "BBoolean.cpp"

#ifndef And_H
#define And_H

using namespace std;

class And {



    private:



        BBigInteger counter;

    public:

        And() {
            counter = static_cast<BBigInteger >((BBigInteger("0")));
        }

        void simulate() {
            while((counter.less((BBigInteger("5000000")))._and((BBigInteger("1")).equal((BBigInteger("1"))))).booleanValue()) {
                counter = static_cast<BBigInteger >(counter.plus((BBigInteger("1"))));
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

