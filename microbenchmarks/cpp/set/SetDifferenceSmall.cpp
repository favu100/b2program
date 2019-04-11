#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef SetDifferenceSmall_H
#define SetDifferenceSmall_H

using namespace std;

class SetDifferenceSmall {



    private:



        BInteger counter;
        BSet<BInteger > set;

    public:

        SetDifferenceSmall() {
            counter = (BInteger(0));
            set = (BSet<BInteger >());
        }

        void simulate() {
            while((counter.less((BInteger(5000000)))).booleanValue()) {
                set = set.difference((BSet<BInteger >((BInteger(1)))));
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    SetDifferenceSmall exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

