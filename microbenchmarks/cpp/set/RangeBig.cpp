#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef RangeBig_H
#define RangeBig_H

using namespace std;

class RangeBig {



    private:



        BInteger counter;
        BSet<BInteger > set;

    public:

        RangeBig() {
            counter = (BInteger(0));
            set = (BSet<BInteger >());
        }

        void simulate() {
            while((counter.less((BInteger(1000)))).booleanValue()) {
                set = (BSet<BInteger>::range((BInteger(1)),(BInteger(25000))));
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    RangeBig exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

