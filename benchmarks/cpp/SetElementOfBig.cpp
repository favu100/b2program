#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef SetElementOfBig2_H
#define SetElementOfBig2_H

using namespace std;

class SetElementOfBig {



    private:



        BInteger counter;

    public:

        SetElementOfBig() {
            counter = static_cast<BInteger >((BInteger(0)));
        }

        void simulate() {
            while((counter.less((BInteger(10000)))._and((BSet<BInteger>::range((BInteger(1)),(BInteger(25000)))).complement((BSet<BInteger >((BInteger(24999))))).elementOf((BInteger(25000))))).booleanValue()) {
                counter = static_cast<BInteger >(counter.plus((BInteger(1))));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    SetElementOfBig exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

