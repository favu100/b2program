#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BTuple.cpp"
#include "BObject.cpp"
#include "BBoolean.cpp"
#include "BInteger.cpp"
#include "BRelation.cpp"

#ifndef CAN_BUS_tlc_H
#define CAN_BUS_tlc_H

using namespace std;

class CAN_BUS_tlc {

    public:
        class T1state : public BObject {
            public:

                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum T1state_type {
                    T1_EN, 
                    T1_CALC, 
                    T1_SEND, 
                    T1_WAIT
                };

                T1state_type value;

                T1state(){}

                T1state(T1state_type type) {
                    this->value = type;
                }

                BBoolean equal(const T1state& o) {
                    return value == o.value;
                }

                BBoolean unequal(const T1state& o) {
                    return value != o.value;
                }

                friend bool operator ==(const T1state& p1, const T1state& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const T1state& p1, const T1state& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const T1state& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const T1state& e) {
                    switch(e.value) {
                        case T1_EN: return strm << "T1_EN";
                        case T1_CALC: return strm << "T1_CALC";
                        case T1_SEND: return strm << "T1_SEND";
                        case T1_WAIT: return strm << "T1_WAIT";
                    }
                }

                int hashCode() const {
                    return static_cast<int>(value);
                }
        };

        class T2mode : public BObject {
            public:

                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum T2mode_type {
                    T2MODE_SENSE, 
                    T2MODE_TRANSMIT, 
                    T2MODE_RELEASE
                };

                T2mode_type value;

                T2mode(){}

                T2mode(T2mode_type type) {
                    this->value = type;
                }

                BBoolean equal(const T2mode& o) {
                    return value == o.value;
                }

                BBoolean unequal(const T2mode& o) {
                    return value != o.value;
                }

                friend bool operator ==(const T2mode& p1, const T2mode& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const T2mode& p1, const T2mode& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const T2mode& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const T2mode& e) {
                    switch(e.value) {
                        case T2MODE_SENSE: return strm << "T2MODE_SENSE";
                        case T2MODE_TRANSMIT: return strm << "T2MODE_TRANSMIT";
                        case T2MODE_RELEASE: return strm << "T2MODE_RELEASE";
                    }
                }

                int hashCode() const {
                    return static_cast<int>(value);
                }
        };

        class T2state : public BObject {
            public:

                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum T2state_type {
                    T2_EN, 
                    T2_RCV, 
                    T2_PROC, 
                    T2_CALC, 
                    T2_SEND, 
                    T2_WAIT, 
                    T2_RELEASE
                };

                T2state_type value;

                T2state(){}

                T2state(T2state_type type) {
                    this->value = type;
                }

                BBoolean equal(const T2state& o) {
                    return value == o.value;
                }

                BBoolean unequal(const T2state& o) {
                    return value != o.value;
                }

                friend bool operator ==(const T2state& p1, const T2state& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const T2state& p1, const T2state& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const T2state& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const T2state& e) {
                    switch(e.value) {
                        case T2_EN: return strm << "T2_EN";
                        case T2_RCV: return strm << "T2_RCV";
                        case T2_PROC: return strm << "T2_PROC";
                        case T2_CALC: return strm << "T2_CALC";
                        case T2_SEND: return strm << "T2_SEND";
                        case T2_WAIT: return strm << "T2_WAIT";
                        case T2_RELEASE: return strm << "T2_RELEASE";
                    }
                }

                int hashCode() const {
                    return static_cast<int>(value);
                }
        };

        class T3state : public BObject {
            public:

                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum T3state_type {
                    T3_READY, 
                    T3_WRITE, 
                    T3_RELEASE, 
                    T3_READ, 
                    T3_PROC, 
                    T3_WAIT
                };

                T3state_type value;

                T3state(){}

                T3state(T3state_type type) {
                    this->value = type;
                }

                BBoolean equal(const T3state& o) {
                    return value == o.value;
                }

                BBoolean unequal(const T3state& o) {
                    return value != o.value;
                }

                friend bool operator ==(const T3state& p1, const T3state& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const T3state& p1, const T3state& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const T3state& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const T3state& e) {
                    switch(e.value) {
                        case T3_READY: return strm << "T3_READY";
                        case T3_WRITE: return strm << "T3_WRITE";
                        case T3_RELEASE: return strm << "T3_RELEASE";
                        case T3_READ: return strm << "T3_READ";
                        case T3_PROC: return strm << "T3_PROC";
                        case T3_WAIT: return strm << "T3_WAIT";
                    }
                }

                int hashCode() const {
                    return static_cast<int>(value);
                }
        };

    private:

        BSet<BInteger > NATSET;


        #define _T1state (BSet<T1state >((T1state(T1state::T1_EN)), (T1state(T1state::T1_CALC)), (T1state(T1state::T1_SEND)), (T1state(T1state::T1_WAIT))))
        #define _T2mode (BSet<T2mode >((T2mode(T2mode::T2MODE_SENSE)), (T2mode(T2mode::T2MODE_TRANSMIT)), (T2mode(T2mode::T2MODE_RELEASE))))
        #define _T2state (BSet<T2state >((T2state(T2state::T2_EN)), (T2state(T2state::T2_RCV)), (T2state(T2state::T2_PROC)), (T2state(T2state::T2_CALC)), (T2state(T2state::T2_SEND)), (T2state(T2state::T2_WAIT)), (T2state(T2state::T2_RELEASE))))
        #define _T3state (BSet<T3state >((T3state(T3state::T3_READY)), (T3state(T3state::T3_WRITE)), (T3state(T3state::T3_RELEASE)), (T3state(T3state::T3_READ)), (T3state(T3state::T3_PROC)), (T3state(T3state::T3_WAIT))))

        BInteger BUSpriority;
        BInteger BUSvalue;
        BRelation<BInteger, BInteger > BUSwrite;
        T1state T1_state;
        BInteger T1_timer;
        BInteger T1_writevalue;
        T2mode T2_mode;
        BInteger T2_readpriority;
        BInteger T2_readvalue;
        T2state T2_state;
        BInteger T2_timer;
        BInteger T2_writevalue;
        BInteger T2v;
        BBoolean T3_enabled;
        BBoolean T3_evaluated;
        BInteger T3_readpriority;
        BInteger T3_readvalue;
        T3state T3_state;

    public:

        CAN_BUS_tlc() {
            NATSET = (BSet<BInteger>::interval((BInteger(0)),(BInteger(5))));
            T2v = (BInteger(0));
            T3_evaluated = (BBoolean(true));
            T3_enabled = (BBoolean(true));
            T1_state = (T1state(T1state::T1_EN));
            T2_state = (T2state(T2state::T2_EN));
            T3_state = (T3state(T3state::T3_READY));
            T1_writevalue = (BInteger(0));
            T2_writevalue = (BInteger(0));
            T2_readvalue = (BInteger(0));
            T2_readpriority = (BInteger(0));
            T3_readvalue = (BInteger(0));
            T3_readpriority = (BInteger(0));
            T1_timer = (BInteger(2));
            T2_timer = (BInteger(3));
            BUSwrite = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(0))))));
            BUSvalue = (BInteger(0));
            BUSpriority = (BInteger(0));
            T2_mode = (T2mode(T2mode::T2MODE_SENSE));
        }

        void T1Evaluate() {
            T1_timer = (BInteger(0));
            T1_state = (T1state(T1state::T1_CALC));
        }

        void T1Calculate(const BInteger& p) {
            T1_writevalue = p;
            T1_state = (T1state(T1state::T1_SEND));
        }

        void T1SendResult(const BInteger& ppriority, const BInteger& pv) {
            BRelation<BInteger, BInteger > _ld_BUSwrite = BUSwrite;
            BUSwrite = _ld_BUSwrite.override((BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >(ppriority, pv)))));
            T1_state = (T1state(T1state::T1_WAIT));
        }

        void T1Wait(const BInteger& pt) {
            T1_timer = pt;
            T1_state = (T1state(T1state::T1_EN));
        }

        void T2Evaluate() {
            T2_timer = (BInteger(0));
            T2_state = (T2state(T2state::T2_RCV));
        }

        void T2ReadBus(const BInteger& ppriority, const BInteger& pv) {
            T2_readvalue = pv;
            T2_readpriority = ppriority;
            T2_state = (T2state(T2state::T2_PROC));
        }

        void T2Reset() {
            BInteger _ld_T2v = T2v;
            T2_writevalue = _ld_T2v;
            T2v = (BInteger(0));
            T2_state = (T2state(T2state::T2_SEND));
            T2_mode = (T2mode(T2mode::T2MODE_TRANSMIT));
        }

        void T2Complete() {
            T2_state = (T2state(T2state::T2_RELEASE));
            T2_mode = (T2mode(T2mode::T2MODE_SENSE));
        }

        void T2ReleaseBus(const BInteger& ppriority) {
            BRelation<BInteger, BInteger > _ld_BUSwrite = BUSwrite;
            BUSwrite = _ld_BUSwrite.domainSubstraction((BSet<BInteger >(ppriority)));
            T2_state = (T2state(T2state::T2_WAIT));
        }

        void T2Calculate() {
            T2v = T2_readvalue;
            T2_state = (T2state(T2state::T2_WAIT));
        }

        void T2WriteBus(const BInteger& ppriority, const BInteger& pv) {
            BRelation<BInteger, BInteger > _ld_BUSwrite = BUSwrite;
            BUSwrite = _ld_BUSwrite.override((BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >(ppriority, pv)))));
            T2_state = (T2state(T2state::T2_WAIT));
        }

        void T2Wait(const BInteger& pt) {
            T2_timer = pt;
            T2_state = (T2state(T2state::T2_EN));
        }

        void T3Initiate() {
            T3_state = (T3state(T3state::T3_WRITE));
            T3_enabled = (BBoolean(false));
        }

        void T3Evaluate() {
            T3_state = (T3state(T3state::T3_READ));
        }

        void T3writebus(const BInteger& ppriority, const BInteger& pv) {
            BRelation<BInteger, BInteger > _ld_BUSwrite = BUSwrite;
            BUSwrite = _ld_BUSwrite.override((BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >(ppriority, pv)))));
            T3_state = (T3state(T3state::T3_WAIT));
        }

        void T3Read(const BInteger& ppriority, const BInteger& pv) {
            T3_readvalue = pv;
            T3_readpriority = ppriority;
            T3_state = (T3state(T3state::T3_PROC));
        }

        void T3Poll() {
            T3_state = (T3state(T3state::T3_WAIT));
        }

        void T3ReleaseBus(const BInteger& ppriority) {
            BRelation<BInteger, BInteger > _ld_BUSwrite = BUSwrite;
            BUSwrite = _ld_BUSwrite.domainSubstraction((BSet<BInteger >(ppriority)));
            T3_state = (T3state(T3state::T3_RELEASE));
        }

        void T3Wait() {
            T3_state = (T3state(T3state::T3_READY));
            T3_evaluated = (BBoolean(true));
        }

        void T3ReEnableWait() {
            T3_state = (T3state(T3state::T3_READY));
            T3_evaluated = (BBoolean(true));
            T3_enabled = (BBoolean(true));
        }

        void Update(const BInteger& pmax) {
            BInteger _ld_T2_timer = T2_timer;
            BInteger _ld_T1_timer = T1_timer;
            BUSvalue = BUSwrite.functionCall(pmax);
            BUSpriority = pmax;
            T1_timer = _ld_T1_timer.minus((BInteger(1)));
            T2_timer = _ld_T2_timer.minus((BInteger(1)));
            T3_evaluated = (BBoolean(false));
        }

};


#endif