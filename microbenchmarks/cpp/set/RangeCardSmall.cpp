#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef RangeCardSmall_H
#define RangeCardSmall_H

using namespace std;

class RangeCardSmall {



    private:



        BInteger counter;
        BInteger result;

    public:

        RangeCardSmall() {
            counter = (BInteger(0));
            result = (BInteger(0));
        }

        void simulate() {
            while((counter.less((BInteger(5000000)))).booleanValue()) {
                result = (BSet<BInteger>::range((BInteger(0)),(BInteger(5)))).card();
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    RangeCardSmall exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

