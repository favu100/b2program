#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef RangeElementOfBig_H
#define RangeElementOfBig_H

using namespace std;

class RangeElementOfBig2 {



    private:



        BInteger counter;
        BSet<BInteger > set;

    public:

        RangeElementOfBig2() {
            counter = static_cast<BInteger >((BInteger(0)));
            set = static_cast<BSet<BInteger > >((BSet<BInteger>::range((BInteger(1)),(BInteger(25000)))));
        }

        void simulate() {
            while((counter.less((BInteger(10000)))._and(set.elementOf((BInteger(25000))))).booleanValue()) {
                counter = static_cast<BInteger >(counter.plus((BInteger(1))));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    RangeElementOfBig2 exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

