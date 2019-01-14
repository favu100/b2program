#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BBigInteger.cpp"
#include "BBoolean.cpp"

#ifndef Minus_H
#define Minus_H

using namespace std;

class Minus {



    private:



        BBigInteger counter;
        BBigInteger value;

    public:

        Minus() {
            counter = static_cast<BBigInteger >((BBigInteger("0")));
            value = static_cast<BBigInteger >((BBigInteger("0")));
        }

        void simulate() {
            while((counter.less((BBigInteger("5000000")))).booleanValue()) {
                counter = static_cast<BBigInteger >(counter.plus((BBigInteger("1"))));
                value = static_cast<BBigInteger >(value.minus((BBigInteger("1"))));
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

