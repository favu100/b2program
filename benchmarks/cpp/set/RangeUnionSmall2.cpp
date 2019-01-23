#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef RangeUnionSmall2_H
#define RangeUnionSmall2_H

using namespace std;

class RangeUnionSmall2 {



    private:



        BInteger counter;
        BSet<BInteger > set1;
        BSet<BInteger > set2;

    public:

        RangeUnionSmall2() {
            counter = (BInteger(0));
            set1 = (BSet<BInteger>::range((BInteger(0)),(BInteger(5))));
            set2 = (BSet<BInteger>::range((BInteger(1)),(BInteger(2))));
        }

        void simulate() {
            while((counter.less((BInteger(5000000)))).booleanValue()) {
                set1 = set1._union(set2);
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    RangeUnionSmall2 exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

