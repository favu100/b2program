#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BInteger.cpp"

#ifndef Lift_H
#define Lift_H

using namespace std;

class Lift {



    private:



        BInteger floor;

    public:

        Lift() {
            floor = static_cast<BInteger >((BInteger(0)));
        }

        void inc() {
            floor = static_cast<BInteger >(floor.plus((BInteger(1))));
        }

        void dec() {
            floor = static_cast<BInteger >(floor.minus((BInteger(1))));
        }

};
#endif

