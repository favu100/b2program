#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef RangeElementOfSmall_H
#define RangeElementOfSmall_H

using namespace std;

class RangeElementOfSmall {



    private:



        BInteger counter;

    public:

        RangeElementOfSmall() {
            counter = (BInteger(0));
        }

        void simulate() {
            while((counter.less((BInteger(5000000)))._and((BSet<BInteger>::range((BInteger(0)),(BInteger(5)))).elementOf((BInteger(1))))).booleanValue()) {
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    RangeElementOfSmall exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

