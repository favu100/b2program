#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef SetDifferenceBig_H
#define SetDifferenceBig_H

using namespace std;

class SetDifferenceBig {



    private:



        BInteger counter;
        BSet<BInteger > set;

    public:

        SetDifferenceBig() {
            counter = (BInteger(0));
            set = (BSet<BInteger>::range((BInteger(1)),(BInteger(25000)))).difference((BSet<BInteger >((BInteger(24999)))));
        }

        void simulate() {
            while((counter.less((BInteger(10000)))).booleanValue()) {
                set = set.difference((BSet<BInteger>::range((BInteger(1)),(BInteger(3000)))));
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    SetDifferenceBig exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

