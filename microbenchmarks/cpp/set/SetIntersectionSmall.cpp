#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef SetIntersectionSmall_H
#define SetIntersectionSmall_H

using namespace std;

class SetIntersectionSmall {



    private:



        BInteger counter;
        BSet<BInteger > set;

    public:

        SetIntersectionSmall() {
            counter = (BInteger(0));
            set = (BSet<BInteger >((BInteger(1))));
        }

        void simulate() {
            while((counter.less((BInteger(5000000)))).booleanValue()) {
                set = set.intersect((BSet<BInteger >()));
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    SetIntersectionSmall exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

