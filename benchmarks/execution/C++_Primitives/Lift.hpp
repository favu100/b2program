#include <iostream>
#include <string>
#include <btypes_primitives/BUtils.hpp>
#include <btypes_primitives/BInteger.hpp>

#ifndef Lift_H
#define Lift_H

using namespace std;

class Lift {

    public:

    private:




        BInteger floor;

    public:

        Lift() {
            floor = (BInteger(0));
        }

        void inc() {
            floor = floor.plus((BInteger(1)));
        }

        void dec() {
            floor = floor.minus((BInteger(1)));
        }

};


#endif