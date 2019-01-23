#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef SetUnionSmall_H
#define SetUnionSmall_H

using namespace std;

class SetUnionSmall {



    private:



        BInteger counter;
        BSet<BInteger > set;

    public:

        SetUnionSmall() {
            counter = (BInteger(0));
            set = (BSet<BInteger >((BInteger(1))));
        }

        void simulate() {
            while((counter.less((BInteger(5000000)))).booleanValue()) {
                set = set._union((BSet<BInteger >((BInteger(2)))));
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    SetUnionSmall exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

