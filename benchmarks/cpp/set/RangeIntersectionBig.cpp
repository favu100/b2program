#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef RangeIntersectionBig_H
#define RangeIntersectionBig_H

using namespace std;

class RangeIntersectionBig {



    private:



        BInteger counter;
        BSet<BInteger > set;

    public:

        RangeIntersectionBig() {
            counter = (BInteger(0));
            set = (BSet<BInteger>::range((BInteger(1)),(BInteger(25000))));
        }

        void simulate() {
            while((counter.less((BInteger(10000)))).booleanValue()) {
                set = set.intersect((BSet<BInteger>::range((BInteger(1)),(BInteger(3000)))));
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    RangeIntersectionBig exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

