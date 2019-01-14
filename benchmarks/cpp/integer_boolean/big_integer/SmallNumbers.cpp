#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BBigInteger.cpp"
#include "BBoolean.cpp"

#ifndef SmallNumbers_H
#define SmallNumbers_H

using namespace std;

class SmallNumbers {



    private:



        BBigInteger counter;
        BBigInteger value;

    public:

        SmallNumbers() {
            counter = static_cast<BBigInteger >((BBigInteger("0")));
            value = static_cast<BBigInteger >((BBigInteger("0")));
        }

        void simulate() {
            while((counter.less((BBigInteger("5000000")))).booleanValue()) {
                counter = static_cast<BBigInteger >(counter.plus((BBigInteger("1"))));
                value = static_cast<BBigInteger >(value.plus((BBigInteger("1"))));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    SmallNumbers exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

