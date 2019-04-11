#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef RangeUnionSmall_H
#define RangeUnionSmall_H

using namespace std;

class RangeUnionSmall {



    private:



        BInteger counter;
        BSet<BInteger > set;

    public:

        RangeUnionSmall() {
            counter = (BInteger(0));
            set = (BSet<BInteger>::range((BInteger(0)),(BInteger(5))));
        }

        void simulate() {
            while((counter.less((BInteger(5000000)))).booleanValue()) {
                set = set._union((BSet<BInteger>::range((BInteger(1)),(BInteger(2)))));
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    RangeUnionSmall exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

