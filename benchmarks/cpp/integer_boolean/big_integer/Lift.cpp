#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BBigInteger.cpp"

#ifndef Lift_H
#define Lift_H

using namespace std;

class Lift {



    private:



        BBigInteger floor;

    public:

        Lift() {
            floor = static_cast<BBigInteger >((BBigInteger("0")));
        }

        void inc() {
            floor = static_cast<BBigInteger >(floor.plus((BBigInteger("1"))));
        }

        void dec() {
            floor = static_cast<BBigInteger >(floor.minus((BBigInteger("1"))));
        }

};
#endif

