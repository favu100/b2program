#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef SetElementOfSmall2_H
#define SetElementOfSmall2_H

using namespace std;

class SetElementOfSmall2 {



    private:



        BInteger counter;
        BSet<BInteger > set;

    public:

        SetElementOfSmall2() {
            counter = (BInteger(0));
            set = (BSet<BInteger >((BInteger(1))));
        }

        void simulate() {
            while((counter.less((BInteger(5000000)))._and(set.elementOf((BInteger(1))))).booleanValue()) {
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    SetElementOfSmall2 exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

