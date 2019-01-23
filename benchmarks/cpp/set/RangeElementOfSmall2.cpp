#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef RangeElementOfSmall2_H
#define RangeElementOfSmall2_H

using namespace std;

class RangeElementOfSmall2 {



    private:



        BInteger counter;
        BSet<BInteger > set;

    public:

        RangeElementOfSmall2() {
            counter = (BInteger(0));
            set = (BSet<BInteger>::range((BInteger(0)),(BInteger(5))));
        }

        void simulate() {
            while((counter.less((BInteger(5000000)))._and(set.elementOf((BInteger(1))))).booleanValue()) {
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    RangeElementOfSmall2 exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

