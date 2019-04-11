#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef SetDifferenceSmall2_H
#define SetDifferenceSmall2_H

using namespace std;

class SetDifferenceSmall2 {



    private:



        BInteger counter;
        BSet<BInteger > set1;
        BSet<BInteger > set2;

    public:

        SetDifferenceSmall2() {
            counter = (BInteger(0));
            set1 = (BSet<BInteger >());
            set2 = (BSet<BInteger >((BInteger(1))));
        }

        void simulate() {
            while((counter.less((BInteger(5000000)))).booleanValue()) {
                set1 = set1.difference(set2);
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    SetDifferenceSmall2 exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

