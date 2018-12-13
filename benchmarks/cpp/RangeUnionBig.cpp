#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef RangeUnionBig_H
#define RangeUnionBig_H

using namespace std;

class RangeUnionBig {



    private:



        BInteger counter;
        BSet<BInteger > set;

    public:

        RangeUnionBig() {
            counter = static_cast<BInteger >((BInteger(0)));
            set = static_cast<BSet<BInteger > >((BSet<BInteger>::range((BInteger(1)),(BInteger(25000)))));
        }

        void simulate() {
            while((counter.less((BInteger(10000)))).booleanValue()) {
                set = static_cast<BSet<BInteger > >(set._union((BSet<BInteger>::range((BInteger(1)),(BInteger(3000))))));
                counter = static_cast<BInteger >(counter.plus((BInteger(1))));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    RangeUnionBig exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

