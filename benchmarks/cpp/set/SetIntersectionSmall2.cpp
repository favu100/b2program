#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef SetIntersectionSmall2_H
#define SetIntersectionSmall2_H

using namespace std;

class SetIntersectionSmall2 {



    private:



        BInteger counter;
        BSet<BInteger > set1;
        BSet<BInteger > set2;

    public:

        SetIntersectionSmall2() {
            counter = (BInteger(0));
            set1 = (BSet<BInteger >((BInteger(1))));
            set2 = (BSet<BInteger >((BInteger(1))));
        }

        void simulate() {
            while((counter.less((BInteger(5000000)))).booleanValue()) {
                set1 = set1.intersect(set2);
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    SetIntersectionSmall2 exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

