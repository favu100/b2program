#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef SetElementOfBig2_H
#define SetElementOfBig2_H

using namespace std;

class SetElementOfBig2 {



    private:



        BInteger counter;
        BSet<BInteger > set;

    public:

        SetElementOfBig2() {
            counter = (BInteger(0));
            set = (BSet<BInteger>::range((BInteger(1)),(BInteger(25000)))).difference((BSet<BInteger >((BInteger(24999)))));
        }

        void simulate() {
            while((counter.less((BInteger(10000)))._and(set.elementOf((BInteger(25000))))).booleanValue()) {
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    SetElementOfBig2 exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

