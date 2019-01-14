#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BBigInteger.cpp"
#include "BBoolean.cpp"

#ifndef Negative_H
#define Negative_H

using namespace std;

class Negative {



    private:



        BBigInteger counter;
        BBigInteger value;

    public:

        Negative() {
            counter = static_cast<BBigInteger >((BBigInteger("0")));
            value = static_cast<BBigInteger >((BBigInteger("0")));
        }

        void simulate() {
            while((counter.less((BBigInteger("5000000")))).booleanValue()) {
                counter = static_cast<BBigInteger >(counter.plus((BBigInteger("1"))));
                value = static_cast<BBigInteger >(value.negative());
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

