#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef SetComplementSmall_H
#define SetComplementSmall_H

using namespace std;

class SetComplementSmall {



    private:



        BInteger counter;
        BSet<BInteger > set;

    public:

        SetComplementSmall() {
            counter = static_cast<BInteger >((BInteger(0)));
            set = static_cast<BSet<BInteger > >((BSet<BInteger >()));
        }

        void simulate() {
            while((counter.less((BInteger(5000000)))).booleanValue()) {
                set = static_cast<BSet<BInteger > >(set.complement((BSet<BInteger >((BInteger(1))))));
                counter = static_cast<BInteger >(counter.plus((BInteger(1))));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    SetComplementSmall exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

