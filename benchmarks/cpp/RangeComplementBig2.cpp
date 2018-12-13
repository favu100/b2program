#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef RangeComplementBig_H
#define RangeComplementBig_H

using namespace std;

class RangeComplementBig2 {



    private:



        BInteger counter;
        BSet<BInteger > set1;
        BSet<BInteger > set2;

    public:

        RangeComplementBig2() {
            counter = static_cast<BInteger >((BInteger(0)));
            set1 = static_cast<BSet<BInteger > >((BSet<BInteger>::range((BInteger(1)),(BInteger(25000)))));
            set2 = static_cast<BSet<BInteger > >((BSet<BInteger>::range((BInteger(1)),(BInteger(3000)))));
        }

        void simulate() {
            while((counter.less((BInteger(10000)))).booleanValue()) {
                set1 = static_cast<BSet<BInteger > >(set1.complement(set2));
                counter = static_cast<BInteger >(counter.plus((BInteger(1))));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    RangeComplementBig2 exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

