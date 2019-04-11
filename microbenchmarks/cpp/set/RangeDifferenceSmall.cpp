#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef RangeDifferenceSmall_H
#define RangeDifferenceSmall_H

using namespace std;

class RangeDifferenceSmall {



    private:



        BInteger counter;
        BSet<BInteger > set;

    public:

        RangeDifferenceSmall() {
            counter = (BInteger(0));
            set = (BSet<BInteger>::range((BInteger(0)),(BInteger(5))));
        }

        void simulate() {
            while((counter.less((BInteger(5000000)))).booleanValue()) {
                set = set.difference((BSet<BInteger>::range((BInteger(1)),(BInteger(2)))));
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    RangeDifferenceSmall exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

