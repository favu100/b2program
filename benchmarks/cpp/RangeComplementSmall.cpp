#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef RangeComplementSmall_H
#define RangeComplementSmall_H

using namespace std;

class RangeComplementSmall {



    private:



        BInteger counter;
        BSet<BInteger > set;

    public:

        RangeComplementSmall() {
            counter = static_cast<BInteger >((BInteger(0)));
            set = static_cast<BSet<BInteger > >((BSet<BInteger>::range((BInteger(0)),(BInteger(5)))));
        }

        void simulate() {
            while((counter.less((BInteger(5000000)))).booleanValue()) {
                set = static_cast<BSet<BInteger > >(set.complement((BSet<BInteger>::range((BInteger(1)),(BInteger(2))))));
                counter = static_cast<BInteger >(counter.plus((BInteger(1))));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    RangeComplementSmall exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

