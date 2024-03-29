#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef SetElementOfSmall_H
#define SetElementOfSmall_H

using namespace std;

class SetElementOfSmall {



    private:



        BInteger counter;

    public:

        SetElementOfSmall() {
            counter = (BInteger(0));
        }

        void simulate() {
            while((counter.less((BInteger(5000000)))._and((BSet<BInteger >((BInteger(1)))).elementOf((BInteger(1))))).booleanValue()) {
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    SetElementOfSmall exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

