#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

#ifndef Or_H
#define Or_H

using namespace std;

class Or {



    private:



        BInteger counter;

    public:

        Or() {
            counter = (BInteger("0"));
        }

        void simulate() {
            while((counter.less((BInteger("5000000")))._or((BInteger("1")).equal((BInteger("2"))))).booleanValue()) {
                counter = counter.plus((BInteger("1")));
            }
        }

};
int main() {
    clock_t start,finish;
    double time;
    Or exec;
    start = clock();
    exec.simulate();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

