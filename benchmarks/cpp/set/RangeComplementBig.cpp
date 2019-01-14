#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef RangeComplementBig_H
#define RangeComplementBig_H

using namespace std;

class RangeComplementBig {



    private:



        BInteger counter;
        BSet<BInteger > set;

    public:

        RangeComplementBig() {
            counter = static_cast<BInteger >((BInteger(0)));
            set = static_cast<BSet<BInteger > >((BSet<BInteger>::range((BInteger(1)),(BInteger(25000)))));
        }

        void simulate() {
            while((counter.less((BInteger(10000)))).booleanValue()) {
                set = static_cast<BSet<BInteger > >(set.complement((BSet<BInteger>::range((BInteger(1)),(BInteger(3000))))));
                counter = static_cast<BInteger >(counter.plus((BInteger(1))));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    RangeComplementBig exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

