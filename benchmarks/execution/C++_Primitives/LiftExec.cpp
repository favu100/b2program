#include <iostream>
#include <string>
#include <btypes_primitives/BUtils.hpp>
#include <btypes_primitives/StateNotReachableError.hpp>
#include <btypes_primitives/PreconditionOrAssertionViolation.hpp>
#include <btypes_primitives/BBoolean.hpp>
#include <btypes_primitives/BInteger.hpp>
#include "Lift.hpp"

#ifndef LiftExec_H
#define LiftExec_H

using namespace std;

class LiftExec {

    public:



    private:


        Lift _Lift;


        BInteger counter;
    public:
        LiftExec() {
            counter = (BInteger(0));
        }

        void simulate() {
            while((counter.less((BInteger(10000000)))).booleanValue()) {
                BInteger i;
                i = (BInteger(0));
                while((i.less((BInteger(100)))).booleanValue()) {
                    this->_Lift.inc();
                    i = i.plus((BInteger(1)));
                }
                BInteger _i;
                _i = (BInteger(0));
                while((_i.less((BInteger(100)))).booleanValue()) {
                    this->_Lift.dec();
                    _i = _i.plus((BInteger(1)));
                }
                counter = counter.plus((BInteger(1)));
            }
        }

        BInteger getCounter() {
            BInteger out;
            out = counter;
            return out;
        }

        BInteger _get_counter() const {
            return counter;
        }

        friend std::ostream& operator<<(std::ostream &strm, const LiftExec &machine) {
          strm << "_Lift: " << machine._Lift << "\n";
          strm << "_get_counter: " << machine._get_counter() << "\n";
          return strm;
        }

};

int main() {
    LiftExec lift;
    lift.simulate();
    cout << lift << "\n";
    return 0;
}

#endif