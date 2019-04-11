#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef BigNumbers_H
#define BigNumbers_H

using namespace std;

class BigNumbers {



    private:



        BInteger counter;
        BInteger value;

    public:

        BigNumbers() {
            counter = (BInteger("0"));
            value = (BInteger("10000000000000000000"));
        }

        void simulate() {
            while((counter.less((BInteger("5000000")))).booleanValue()) {
                counter = counter.plus((BInteger("1")));
                value = value.plus((BInteger("1")));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    BigNumbers exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

