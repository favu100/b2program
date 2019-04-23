#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BObject.cpp"
#include "BBoolean.cpp"

#ifndef scheduler_deterministic_H
#define scheduler_deterministic_H

using namespace std;

class scheduler_deterministic {

    public:
        class PID : public BObject {
            public:

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

                BBoolean equal(const PID& o) {
                    return value == o.value;
                }

                BBoolean unequal(const PID& o) {
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
                    return static_cast<int>(value);
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
            if((_PID.elementOf(pp)._and(active.notElementOf(pp))._and(_ready._union(waiting).notElementOf(pp))).booleanValue()) {
                waiting = waiting._union((BSet<PID >(pp)));
            }
        }

        void del(const PID& pp) {
            if((waiting.elementOf(pp)).booleanValue()) {
                waiting = waiting.difference((BSet<PID >(pp)));
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
            }
        }

};


#endif