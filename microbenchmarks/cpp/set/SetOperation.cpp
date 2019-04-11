#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef SetOperation_H
#define SetOperation_H

using namespace std;

class SetOperation {



    private:



        BInteger counter;
        BSet<BInteger > set;

    public:

        SetOperation() {
            counter = (BInteger(0));
            set = (BSet<BInteger >((BInteger(1)), (BInteger(2)), (BInteger(3))));
        }

        void simulate() {
            while((counter.less((BInteger(500000)))).booleanValue()) {
                set = set._union((BSet<BInteger >((BInteger(1)))));
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    SetOperation exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

