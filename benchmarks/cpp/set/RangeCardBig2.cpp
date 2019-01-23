#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef RangeCardBig2_H
#define RangeCardBig2_H

using namespace std;

class RangeCardBig2 {



    private:



        BInteger counter;
        BSet<BInteger > set;
        BInteger result;

    public:

        RangeCardBig2() {
            counter = (BInteger(0));
            set = (BSet<BInteger>::range((BInteger(1)),(BInteger(25000))));
            result = (BInteger(0));
        }

        void simulate() {
            while((counter.less((BInteger(10000)))).booleanValue()) {
                result = set.card();
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    RangeCardBig2 exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

