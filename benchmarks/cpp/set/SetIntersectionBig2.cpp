#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef SetIntersectionBig2_H
#define SetIntersectionBig2_H

using namespace std;

class SetIntersectionBig2 {



    private:



        BInteger counter;
        BSet<BInteger > set1;
        BSet<BInteger > set2;

    public:

        SetIntersectionBig2() {
            counter = (BInteger(0));
            set1 = (BSet<BInteger>::range((BInteger(1)),(BInteger(25000)))).difference((BSet<BInteger >((BInteger(24999)))));
            set2 = (BSet<BInteger>::range((BInteger(1)),(BInteger(3000))));
        }

        void simulate() {
            while((counter.less((BInteger(10000)))).booleanValue()) {
                set1 = set1.intersect(set2);
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    SetIntersectionBig2 exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

