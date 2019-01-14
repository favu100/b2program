#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BBigInteger.cpp"
#include "BBoolean.cpp"

#ifndef Plus_H
#define Plus_H

using namespace std;

class Plus {



    private:



        BBigInteger counter;
        BBigInteger value;

    public:

        Plus() {
            counter = (BBigInteger("0"));
            value = (BBigInteger("10000000000000000000000000000000000000"));
        }

        void simulate() {
            while((counter.less((BBigInteger("5000000")))).booleanValue()) {
                counter = counter.plus((BBigInteger("1")));
                value = value.plus((BBigInteger("1")));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    BBigInteger x = (BBigInteger("1")).plus(BBigInteger("1"));
    BBoolean y = x.less(BBigInteger("123"));
    Plus exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

