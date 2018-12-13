#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef SetCardBig2_H
#define SetCardBig2_H

using namespace std;

class SetCardBig2 {



    private:



        BInteger counter;
        BSet<BInteger > set;
        BInteger result;

    public:

        SetCardBig2() {
            counter = static_cast<BInteger >((BInteger(0)));
            set = static_cast<BSet<BInteger > >((BSet<BInteger>::range((BInteger(1)),(BInteger(25000)))).complement((BSet<BInteger >((BInteger(24999))))));
            result = static_cast<BInteger >((BInteger(0)));
        }

        void simulate() {
            while((counter.less((BInteger(10000)))).booleanValue()) {
                result = static_cast<BInteger >(set.card());
                counter = static_cast<BInteger >(counter.plus((BInteger(1))));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    SetCardBig2 exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

