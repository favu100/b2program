#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef Less_H
#define Less_H

using namespace std;

class Less {



    private:



        BInteger counter;

    public:

        Less() {
            counter = (BInteger(0));
        }

        void simulate() {
            while((counter.less((BInteger(5000000)))._and((BInteger(1)).less((BInteger(2))))).booleanValue()) {
                counter = counter.plus((BInteger(1)));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    Less exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

