#include <iostream>
#include <string>
#include <btypes_primitives/BUtils.hpp>
#include <btypes_primitives/StateNotReachableError.hpp>
#include <btypes_primitives/PreconditionOrAssertionViolation.hpp>
#include <btypes_primitives/BSet.hpp>
#include <btypes_primitives/BBoolean.hpp>
#include <btypes_primitives/BObject.hpp>

#ifndef scheduler_deterministic_H
#define scheduler_deterministic_H

using namespace std;

class scheduler_deterministic {

    public:

        class PID : public BObject {
            public:

                typedef PID current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum PID_type {
                    process1, 
                    process2, 
                    process3
                };

                PID_type value;

                PID(){}

                PID(const PID_type& type) {
                    this->value = type;
                }

                BBoolean equal(const PID& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const PID& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const PID& p1, const PID& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const PID& p1, const PID& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const PID& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const PID& e) {
                    switch(e.value) {
                        case process1: return strm << "process1";
                        case process2: return strm << "process2";
                        case process3: return strm << "process3";
                    }
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };


    private:



        #define _PID (BSet<PID >((PID(PID::process1)), (PID(PID::process2)), (PID(PID::process3))))

        BSet<PID > active;
        BSet<PID > _ready;
        BSet<PID > waiting;
    public:
        scheduler_deterministic() {
            active = (BSet<PID >());
            _ready = (BSet<PID >());
            waiting = (BSet<PID >());
        }

        void _new(const PID& pp) {
            if(((BBoolean((BBoolean(_PID.elementOf(pp).booleanValue() && active.notElementOf(pp).booleanValue())).booleanValue() && _ready._union(waiting).notElementOf(pp).booleanValue()))).booleanValue()) {
                waiting = waiting._union((BSet<PID >(pp)));
            } else {
                throw StateNotReachableError();
            }

        }

        void del(const PID& pp) {
            if((waiting.elementOf(pp)).booleanValue()) {
                waiting = waiting.difference((BSet<PID >(pp)));
            } else {
                throw StateNotReachableError();
            }

        }

        void ready(const PID& rr) {
            if((waiting.elementOf(rr)).booleanValue()) {
                waiting = waiting.difference((BSet<PID >(rr)));
                if((active.equal((BSet<PID >()))).booleanValue()) {
                    active = (BSet<PID >(rr));
                } else {
                    _ready = _ready._union((BSet<PID >(rr)));
                }
            } else {
                throw StateNotReachableError();
            }

        }

        void swap(const PID& pp) {
            if((active.unequal((BSet<PID >()))).booleanValue()) {
                waiting = waiting._union(active);
                if((_ready.equal((BSet<PID >()))).booleanValue()) {
                    active = (BSet<PID >());
                } else {
                    active = (BSet<PID >(pp));
                    _ready = _ready.difference((BSet<PID >(pp)));
                }
            } else {
                throw StateNotReachableError();
            }


        }

        BSet<PID > _get_active() const {
            return active;
        }

        BSet<PID > _get__ready() const {
            return _ready;
        }

        BSet<PID > _get_waiting() const {
            return waiting;
        }

        BSet<PID > _get__PID() const {
            return _PID;
        }

        friend std::ostream& operator<<(std::ostream &strm, const scheduler_deterministic &machine) {
          strm << "_get_active: " << machine._get_active() << "\n";
          strm << "_get__ready: " << machine._get__ready() << "\n";
          strm << "_get_waiting: " << machine._get_waiting() << "\n";
          return strm;
        }

};


#endif