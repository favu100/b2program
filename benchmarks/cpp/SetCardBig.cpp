#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef SetCardBig_H
#define SetCardBig_H

using namespace std;

class SetCardBig {



    private:



        BInteger counter;
        BInteger result;

    public:

        SetCardBig() {
            counter = static_cast<BInteger >((BInteger(0)));
            result = static_cast<BInteger >((BInteger(0)));
        }

        void simulate() {
            while((counter.less((BInteger(10000)))).booleanValue()) {
                result = static_cast<BInteger >((BSet<BInteger>::range((BInteger(1)),(BInteger(25000)))).complement((BSet<BInteger >((BInteger(24999))))).card());
                counter = static_cast<BInteger >(counter.plus((BInteger(1))));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    SetCardBig exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

