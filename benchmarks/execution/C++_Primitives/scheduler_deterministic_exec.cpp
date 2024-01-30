#include <iostream>
#include <string>
#include <btypes_primitives/BUtils.hpp>
#include <btypes_primitives/StateNotReachableError.hpp>
#include <btypes_primitives/PreconditionOrAssertionViolation.hpp>
#include <btypes_primitives/BBoolean.hpp>
#include <btypes_primitives/BObject.hpp>
#include <btypes_primitives/BInteger.hpp>
#include "scheduler_deterministic.hpp"

#ifndef scheduler_deterministic_exec_H
#define scheduler_deterministic_exec_H

using namespace std;

class scheduler_deterministic_exec {

    public:



    private:


        scheduler_deterministic _scheduler_deterministic;


        BInteger counter;
    public:
        scheduler_deterministic_exec() {
            counter = (BInteger(0));
        }

        void simulate() {
            while((counter.less((BInteger(300000)))).booleanValue()) {
                this->_scheduler_deterministic._new((scheduler_deterministic::PID(scheduler_deterministic::PID::process1)));
                this->_scheduler_deterministic._new((scheduler_deterministic::PID(scheduler_deterministic::PID::process2)));
                this->_scheduler_deterministic._new((scheduler_deterministic::PID(scheduler_deterministic::PID::process3)));
                this->_scheduler_deterministic.del((scheduler_deterministic::PID(scheduler_deterministic::PID::process1)));
                this->_scheduler_deterministic._new((scheduler_deterministic::PID(scheduler_deterministic::PID::process1)));
                this->_scheduler_deterministic.del((scheduler_deterministic::PID(scheduler_deterministic::PID::process2)));
                this->_scheduler_deterministic.del((scheduler_deterministic::PID(scheduler_deterministic::PID::process1)));
                this->_scheduler_deterministic.del((scheduler_deterministic::PID(scheduler_deterministic::PID::process3)));
                this->_scheduler_deterministic._new((scheduler_deterministic::PID(scheduler_deterministic::PID::process1)));
                this->_scheduler_deterministic._new((scheduler_deterministic::PID(scheduler_deterministic::PID::process2)));
                this->_scheduler_deterministic.del((scheduler_deterministic::PID(scheduler_deterministic::PID::process1)));
                this->_scheduler_deterministic.ready((scheduler_deterministic::PID(scheduler_deterministic::PID::process2)));
                this->_scheduler_deterministic._new((scheduler_deterministic::PID(scheduler_deterministic::PID::process1)));
                this->_scheduler_deterministic._new((scheduler_deterministic::PID(scheduler_deterministic::PID::process3)));
                this->_scheduler_deterministic.del((scheduler_deterministic::PID(scheduler_deterministic::PID::process1)));
                this->_scheduler_deterministic.ready((scheduler_deterministic::PID(scheduler_deterministic::PID::process3)));
                this->_scheduler_deterministic._new((scheduler_deterministic::PID(scheduler_deterministic::PID::process1)));
                this->_scheduler_deterministic.ready((scheduler_deterministic::PID(scheduler_deterministic::PID::process1)));
                this->_scheduler_deterministic.swap((scheduler_deterministic::PID(scheduler_deterministic::PID::process1)));
                this->_scheduler_deterministic.del((scheduler_deterministic::PID(scheduler_deterministic::PID::process2)));
                this->_scheduler_deterministic.swap((scheduler_deterministic::PID(scheduler_deterministic::PID::process3)));
                this->_scheduler_deterministic._new((scheduler_deterministic::PID(scheduler_deterministic::PID::process2)));
                this->_scheduler_deterministic.del((scheduler_deterministic::PID(scheduler_deterministic::PID::process1)));
                this->_scheduler_deterministic.del((scheduler_deterministic::PID(scheduler_deterministic::PID::process2)));
                this->_scheduler_deterministic.swap((scheduler_deterministic::PID(scheduler_deterministic::PID::process1)));
                this->_scheduler_deterministic._new((scheduler_deterministic::PID(scheduler_deterministic::PID::process1)));
                this->_scheduler_deterministic._new((scheduler_deterministic::PID(scheduler_deterministic::PID::process2)));
                this->_scheduler_deterministic.del((scheduler_deterministic::PID(scheduler_deterministic::PID::process1)));
                this->_scheduler_deterministic.del((scheduler_deterministic::PID(scheduler_deterministic::PID::process3)));
                this->_scheduler_deterministic._new((scheduler_deterministic::PID(scheduler_deterministic::PID::process1)));
                this->_scheduler_deterministic.del((scheduler_deterministic::PID(scheduler_deterministic::PID::process2)));
                this->_scheduler_deterministic.del((scheduler_deterministic::PID(scheduler_deterministic::PID::process1)));
                counter = counter.plus((BInteger(1)));
            }
        }

        BInteger _get_counter() const {
            return counter;
        }

        friend std::ostream& operator<<(std::ostream &strm, const scheduler_deterministic_exec &machine) {
          strm << "_scheduler_deterministic: " << machine._scheduler_deterministic << "\n";
          strm << "_get_counter: " << machine._get_counter() << "\n";
          return strm;
        }

};

int main() {
    scheduler_deterministic_exec exec;
    exec.simulate();
    cout << exec << "\n";
    return 0;
}

#endif