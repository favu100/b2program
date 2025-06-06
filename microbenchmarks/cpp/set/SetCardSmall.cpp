#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef SetCardSmall_H
#define SetCardSmall_H

using namespace std;

class SetCardSmall {



    private:



        BInteger counter;
        BInteger result;

    public:

        SetCardSmall() {
            counter = (BInteger(0));
            result = (BInteger(0));
        }

        void simulate() {
            while((counter.less((BInteger(5000000)))).booleanValue()) {
                result = (BSet<BInteger >((BInteger(1)))).card();
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    SetCardSmall exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

