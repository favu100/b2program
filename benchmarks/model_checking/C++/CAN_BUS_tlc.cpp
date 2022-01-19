#include <iostream>
#include <string>
#include <immer/map.hpp>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <atomic>
#include <mutex>
#include <future>
#include <boost/asio/post.hpp>
#include <boost/asio/thread_pool.hpp>
#include <boost/any.hpp>
#include <btypes_primitives/BUtils.hpp>
#include <btypes_primitives/StateNotReachableError.hpp>
#include <btypes_primitives/PreconditionOrAssertionViolation.hpp>
#include <btypes_primitives/BSet.hpp>
#include <btypes_primitives/BBoolean.hpp>
#include <btypes_primitives/BObject.hpp>
#include <btypes_primitives/BRelation.hpp>
#include <btypes_primitives/BInteger.hpp>
#include <btypes_primitives/BTuple.hpp>

#ifndef CAN_BUS_tlc_H
#define CAN_BUS_tlc_H

using namespace std;

class CAN_BUS_tlc {

    public:

        enum Type { BFS, DFS, MIXED };


        class T1state : public BObject {
            public:

                typedef T1state current_type;
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

                T1state(const T1state_type& type) {
                    this->value = type;
                }

                BBoolean equal(const T1state& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const T1state& o) const {
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
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class T2mode : public BObject {
            public:

                typedef T2mode current_type;
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

                T2mode(const T2mode_type& type) {
                    this->value = type;
                }

                BBoolean equal(const T2mode& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const T2mode& o) const {
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
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class T2state : public BObject {
            public:

                typedef T2state current_type;
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

                T2state(const T2state_type& type) {
                    this->value = type;
                }

                BBoolean equal(const T2state& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const T2state& o) const {
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
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class T3state : public BObject {
            public:

                typedef T3state current_type;
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

                T3state(const T3state_type& type) {
                    this->value = type;
                }

                BBoolean equal(const T3state& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const T3state& o) const {
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
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        struct Hash {
            public:
                size_t operator()(const CAN_BUS_tlc& obj) const {
                    return obj.hashCode();
                }
        };

        struct HashEqual {
            public:
                bool operator()(const CAN_BUS_tlc& obj1, const CAN_BUS_tlc& obj2) const {
                    if (obj1 == obj2)
                        return true;
                    else
                        return false;
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

        CAN_BUS_tlc(const BSet<BInteger >& NATSET, const BInteger& BUSpriority, const BInteger& BUSvalue, const BRelation<BInteger, BInteger >& BUSwrite, const T1state& T1_state, const BInteger& T1_timer, const BInteger& T1_writevalue, const T2mode& T2_mode, const BInteger& T2_readpriority, const BInteger& T2_readvalue, const T2state& T2_state, const BInteger& T2_timer, const BInteger& T2_writevalue, const BInteger& T2v, const BBoolean& T3_enabled, const BBoolean& T3_evaluated, const BInteger& T3_readpriority, const BInteger& T3_readvalue, const T3state& T3_state) {
            this->NATSET = NATSET;
            this->BUSpriority = BUSpriority;
            this->BUSvalue = BUSvalue;
            this->BUSwrite = BUSwrite;
            this->T1_state = T1_state;
            this->T1_timer = T1_timer;
            this->T1_writevalue = T1_writevalue;
            this->T2_mode = T2_mode;
            this->T2_readpriority = T2_readpriority;
            this->T2_readvalue = T2_readvalue;
            this->T2_state = T2_state;
            this->T2_timer = T2_timer;
            this->T2_writevalue = T2_writevalue;
            this->T2v = T2v;
            this->T3_enabled = T3_enabled;
            this->T3_evaluated = T3_evaluated;
            this->T3_readpriority = T3_readpriority;
            this->T3_readvalue = T3_readvalue;
            this->T3_state = T3_state;
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

        BSet<BInteger > _get_NATSET() const {
            return NATSET;
        }

        BInteger _get_BUSpriority() const {
            return BUSpriority;
        }

        BInteger _get_BUSvalue() const {
            return BUSvalue;
        }

        BRelation<BInteger, BInteger > _get_BUSwrite() const {
            return BUSwrite;
        }

        T1state _get_T1_state() const {
            return T1_state;
        }

        BInteger _get_T1_timer() const {
            return T1_timer;
        }

        BInteger _get_T1_writevalue() const {
            return T1_writevalue;
        }

        T2mode _get_T2_mode() const {
            return T2_mode;
        }

        BInteger _get_T2_readpriority() const {
            return T2_readpriority;
        }

        BInteger _get_T2_readvalue() const {
            return T2_readvalue;
        }

        T2state _get_T2_state() const {
            return T2_state;
        }

        BInteger _get_T2_timer() const {
            return T2_timer;
        }

        BInteger _get_T2_writevalue() const {
            return T2_writevalue;
        }

        BInteger _get_T2v() const {
            return T2v;
        }

        BBoolean _get_T3_enabled() const {
            return T3_enabled;
        }

        BBoolean _get_T3_evaluated() const {
            return T3_evaluated;
        }

        BInteger _get_T3_readpriority() const {
            return T3_readpriority;
        }

        BInteger _get_T3_readvalue() const {
            return T3_readvalue;
        }

        T3state _get_T3_state() const {
            return T3_state;
        }

        BSet<T1state > _get__T1state() const {
            return _T1state;
        }

        BSet<T2mode > _get__T2mode() const {
            return _T2mode;
        }

        BSet<T2state > _get__T2state() const {
            return _T2state;
        }

        BSet<T3state > _get__T3state() const {
            return _T3state;
        }


        bool _tr_T1Evaluate() const {
            return ((BBoolean(T1_timer.equal((BInteger(0))).booleanValue() && T1_state.equal((T1state(T1state::T1_EN))).booleanValue()))).booleanValue();
        }

        BSet<BInteger> _tr_T1Calculate() const {
            BSet<BInteger> _ic_set_1 = BSet<BInteger>();
            for(BInteger _ic_p_1 : (BSet<BInteger>::interval((BInteger(1)).negative(),(BInteger(3))))) {
                if((T1_state.equal((T1state(T1state::T1_CALC)))).booleanValue()) {
                    _ic_set_1 = _ic_set_1._union(BSet<BInteger>(_ic_p_1));
                }

            }
            return _ic_set_1;
        }

        BSet<BTuple<BInteger, BInteger >> _tr_T1SendResult() const {
            BSet<BTuple<BInteger, BInteger >> _ic_set_2 = BSet<BTuple<BInteger, BInteger >>();
            for(BInteger _ic_ppriority_1 : {(BInteger(3))}) {
                for(BInteger _ic_pv_1 : {T1_writevalue}) {
                    if((T1_state.equal((T1state(T1state::T1_SEND)))).booleanValue()) {
                        _ic_set_2 = _ic_set_2._union(BSet<BTuple<BInteger, BInteger >>((BTuple<BInteger, BInteger >(_ic_ppriority_1, _ic_pv_1))));
                    }

                }

            }

            return _ic_set_2;
        }

        BSet<BInteger> _tr_T1Wait() const {
            BSet<BInteger> _ic_set_3 = BSet<BInteger>();
            for(BInteger _ic_pt_1 : {(BInteger(2))}) {
                if((T1_state.equal((T1state(T1state::T1_WAIT)))).booleanValue()) {
                    _ic_set_3 = _ic_set_3._union(BSet<BInteger>(_ic_pt_1));
                }

            }

            return _ic_set_3;
        }

        bool _tr_T2Evaluate() const {
            return ((BBoolean(T2_timer.equal((BInteger(0))).booleanValue() && T2_state.equal((T2state(T2state::T2_EN))).booleanValue()))).booleanValue();
        }

        BSet<BTuple<BInteger, BInteger >> _tr_T2ReadBus() const {
            BSet<BTuple<BInteger, BInteger >> _ic_set_5 = BSet<BTuple<BInteger, BInteger >>();
            for(BInteger _ic_ppriority_1 : {BUSpriority}) {
                for(BInteger _ic_pv_1 : {BUSvalue}) {
                    if((T2_state.equal((T2state(T2state::T2_RCV)))).booleanValue()) {
                        _ic_set_5 = _ic_set_5._union(BSet<BTuple<BInteger, BInteger >>((BTuple<BInteger, BInteger >(_ic_ppriority_1, _ic_pv_1))));
                    }

                }

            }

            return _ic_set_5;
        }

        bool _tr_T2Reset() const {
            return ((BBoolean(T2_readpriority.equal((BInteger(4))).booleanValue() && T2_state.equal((T2state(T2state::T2_PROC))).booleanValue()))).booleanValue();
        }

        bool _tr_T2Complete() const {
            return ((BBoolean((BBoolean(T2_state.equal((T2state(T2state::T2_PROC))).booleanValue() && T2_readpriority.equal((BInteger(5))).booleanValue())).booleanValue() && T2_mode.equal((T2mode(T2mode::T2MODE_TRANSMIT))).booleanValue()))).booleanValue();
        }

        BSet<BInteger> _tr_T2ReleaseBus() const {
            BSet<BInteger> _ic_set_8 = BSet<BInteger>();
            for(BInteger _ic_ppriority_1 : {T2_readpriority}) {
                if(((BBoolean(BUSwrite.domain().elementOf(_ic_ppriority_1).booleanValue() && T2_state.equal((T2state(T2state::T2_RELEASE))).booleanValue()))).booleanValue()) {
                    _ic_set_8 = _ic_set_8._union(BSet<BInteger>(_ic_ppriority_1));
                }

            }

            return _ic_set_8;
        }

        bool _tr_T2Calculate() const {
            return ((BBoolean(T2_readpriority.equal((BInteger(3))).booleanValue() && T2_state.equal((T2state(T2state::T2_PROC))).booleanValue()))).booleanValue();
        }

        BSet<BTuple<BInteger, BInteger >> _tr_T2WriteBus() const {
            BSet<BTuple<BInteger, BInteger >> _ic_set_10 = BSet<BTuple<BInteger, BInteger >>();
            for(BInteger _ic_ppriority_1 : {(BInteger(5))}) {
                for(BInteger _ic_pv_1 : {T2_writevalue}) {
                    if((T2_state.equal((T2state(T2state::T2_SEND)))).booleanValue()) {
                        _ic_set_10 = _ic_set_10._union(BSet<BTuple<BInteger, BInteger >>((BTuple<BInteger, BInteger >(_ic_ppriority_1, _ic_pv_1))));
                    }

                }

            }

            return _ic_set_10;
        }

        BSet<BInteger> _tr_T2Wait() const {
            BSet<BInteger> _ic_set_11 = BSet<BInteger>();
            for(BInteger _ic_pt_1 : {(BInteger(3))}) {
                if((T2_state.equal((T2state(T2state::T2_WAIT)))).booleanValue()) {
                    _ic_set_11 = _ic_set_11._union(BSet<BInteger>(_ic_pt_1));
                }

            }

            return _ic_set_11;
        }

        bool _tr_T3Initiate() const {
            return ((BBoolean((BBoolean(T3_state.equal((T3state(T3state::T3_READY))).booleanValue() && T3_evaluated.equal((BBoolean(false))).booleanValue())).booleanValue() && T3_enabled.equal((BBoolean(true))).booleanValue()))).booleanValue();
        }

        bool _tr_T3Evaluate() const {
            return ((BBoolean((BBoolean(T3_state.equal((T3state(T3state::T3_READY))).booleanValue() && T3_evaluated.equal((BBoolean(false))).booleanValue())).booleanValue() && T3_enabled.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        BSet<BTuple<BInteger, BInteger >> _tr_T3writebus() const {
            BSet<BTuple<BInteger, BInteger >> _ic_set_14 = BSet<BTuple<BInteger, BInteger >>();
            for(BInteger _ic_ppriority_1 : {(BInteger(4))}) {
                for(BInteger _ic_pv_1 : {(BInteger(0))}) {
                    if((T3_state.equal((T3state(T3state::T3_WRITE)))).booleanValue()) {
                        _ic_set_14 = _ic_set_14._union(BSet<BTuple<BInteger, BInteger >>((BTuple<BInteger, BInteger >(_ic_ppriority_1, _ic_pv_1))));
                    }

                }

            }

            return _ic_set_14;
        }

        BSet<BTuple<BInteger, BInteger >> _tr_T3Read() const {
            BSet<BTuple<BInteger, BInteger >> _ic_set_15 = BSet<BTuple<BInteger, BInteger >>();
            for(BInteger _ic_ppriority_1 : {BUSpriority}) {
                for(BInteger _ic_pv_1 : {BUSvalue}) {
                    if((T3_state.equal((T3state(T3state::T3_READ)))).booleanValue()) {
                        _ic_set_15 = _ic_set_15._union(BSet<BTuple<BInteger, BInteger >>((BTuple<BInteger, BInteger >(_ic_ppriority_1, _ic_pv_1))));
                    }

                }

            }

            return _ic_set_15;
        }

        bool _tr_T3Poll() const {
            return ((BBoolean(T3_readpriority.less((BInteger(5))).booleanValue() && T3_state.equal((T3state(T3state::T3_PROC))).booleanValue()))).booleanValue();
        }

        BSet<BInteger> _tr_T3ReleaseBus() const {
            BSet<BInteger> _ic_set_17 = BSet<BInteger>();
            for(BInteger _ic_ppriority_1 : {(BInteger(4))}) {
                if(((BBoolean(T3_readpriority.equal((BInteger(5))).booleanValue() && T3_state.equal((T3state(T3state::T3_PROC))).booleanValue()))).booleanValue()) {
                    _ic_set_17 = _ic_set_17._union(BSet<BInteger>(_ic_ppriority_1));
                }

            }

            return _ic_set_17;
        }

        bool _tr_T3Wait() const {
            return (T3_state.equal((T3state(T3state::T3_WAIT)))).booleanValue();
        }

        bool _tr_T3ReEnableWait() const {
            return (T3_state.equal((T3state(T3state::T3_RELEASE)))).booleanValue();
        }

        BSet<BInteger> _tr_Update() const {
            BSet<BInteger> _ic_set_20 = BSet<BInteger>();
            for(BInteger _ic_pmax_1 : {BUSwrite.domain().max()}) {
                if(((BBoolean((BBoolean(T1_timer.greater((BInteger(0))).booleanValue() && T2_timer.greater((BInteger(0))).booleanValue())).booleanValue() && (BBoolean(T3_enabled.equal((BBoolean(true))).booleanValue() || T3_evaluated.equal((BBoolean(true))).booleanValue())).booleanValue()))).booleanValue()) {
                    _ic_set_20 = _ic_set_20._union(BSet<BInteger>(_ic_pmax_1));
                }

            }

            return _ic_set_20;
        }

        bool _check_inv_1() const {
            return ((T2v.isInteger())).booleanValue();
        }

        bool _check_inv_2() const {
            return ((BOOL).elementOf(T3_evaluated)).booleanValue();
        }

        bool _check_inv_3() const {
            return ((BOOL).elementOf(T3_enabled)).booleanValue();
        }

        bool _check_inv_4() const {
            return (_T1state.elementOf(T1_state)).booleanValue();
        }

        bool _check_inv_5() const {
            return (_T2state.elementOf(T2_state)).booleanValue();
        }

        bool _check_inv_6() const {
            return (_T3state.elementOf(T3_state)).booleanValue();
        }

        bool _check_inv_7() const {
            return ((T1_writevalue.isInteger())).booleanValue();
        }

        bool _check_inv_8() const {
            return ((T2_writevalue.isInteger())).booleanValue();
        }

        bool _check_inv_9() const {
            return ((T2_readvalue.isInteger())).booleanValue();
        }

        bool _check_inv_10() const {
            return ((T1_timer.isNatural())).booleanValue();
        }

        bool _check_inv_11() const {
            return ((T2_timer.isNatural())).booleanValue();
        }

        bool _check_inv_12() const {
            return (_T2mode.elementOf(T2_mode)).booleanValue();
        }

        bool _check_inv_13() const {
            return ((BUSvalue.isInteger())).booleanValue();
        }

        bool _check_inv_14() const {
            return (NATSET.elementOf(BUSpriority)).booleanValue();
        }

        bool _check_inv_15() const {
            return ((T3_readvalue.isInteger())).booleanValue();
        }

        bool _check_inv_16() const {
            return (NATSET.elementOf(T3_readpriority)).booleanValue();
        }

        bool _check_inv_17() const {
            return (NATSET.elementOf(T2_readpriority)).booleanValue();
        }

        bool _check_inv_18() const {
            return (((BUSwrite.checkDomain(NATSET))._and((BUSwrite.checkRangeInteger()))._and((BUSwrite.isFunction()))._and((BUSwrite.isPartial(NATSET))))).booleanValue();
        }

        bool _check_inv_19() const {
            return (BUSwrite.unequal((BRelation<BInteger, BInteger >()))).booleanValue();
        }

        bool _check_inv_20() const {
            return (BUSwrite.domain().elementOf((BInteger(0)))).booleanValue();
        }

        CAN_BUS_tlc _copy() const {
            return CAN_BUS_tlc(NATSET, BUSpriority, BUSvalue, BUSwrite, T1_state, T1_timer, T1_writevalue, T2_mode, T2_readpriority, T2_readvalue, T2_state, T2_timer, T2_writevalue, T2v, T3_enabled, T3_evaluated, T3_readpriority, T3_readvalue, T3_state);
        }

        friend bool operator ==(const CAN_BUS_tlc& o1, const CAN_BUS_tlc& o2) {
            return o1._get_BUSpriority() == o2._get_BUSpriority() && o1._get_BUSvalue() == o2._get_BUSvalue() && o1._get_BUSwrite() == o2._get_BUSwrite() && o1._get_T1_state() == o2._get_T1_state() && o1._get_T1_timer() == o2._get_T1_timer() && o1._get_T1_writevalue() == o2._get_T1_writevalue() && o1._get_T2_mode() == o2._get_T2_mode() && o1._get_T2_readpriority() == o2._get_T2_readpriority() && o1._get_T2_readvalue() == o2._get_T2_readvalue() && o1._get_T2_state() == o2._get_T2_state() && o1._get_T2_timer() == o2._get_T2_timer() && o1._get_T2_writevalue() == o2._get_T2_writevalue() && o1._get_T2v() == o2._get_T2v() && o1._get_T3_enabled() == o2._get_T3_enabled() && o1._get_T3_evaluated() == o2._get_T3_evaluated() && o1._get_T3_readpriority() == o2._get_T3_readpriority() && o1._get_T3_readvalue() == o2._get_T3_readvalue() && o1._get_T3_state() == o2._get_T3_state();
        }

        friend bool operator !=(const CAN_BUS_tlc& o1, const CAN_BUS_tlc& o2) {
            return o1._get_BUSpriority() != o2._get_BUSpriority() || o1._get_BUSvalue() != o2._get_BUSvalue() || o1._get_BUSwrite() != o2._get_BUSwrite() || o1._get_T1_state() != o2._get_T1_state() || o1._get_T1_timer() != o2._get_T1_timer() || o1._get_T1_writevalue() != o2._get_T1_writevalue() || o1._get_T2_mode() != o2._get_T2_mode() || o1._get_T2_readpriority() != o2._get_T2_readpriority() || o1._get_T2_readvalue() != o2._get_T2_readvalue() || o1._get_T2_state() != o2._get_T2_state() || o1._get_T2_timer() != o2._get_T2_timer() || o1._get_T2_writevalue() != o2._get_T2_writevalue() || o1._get_T2v() != o2._get_T2v() || o1._get_T3_enabled() != o2._get_T3_enabled() || o1._get_T3_evaluated() != o2._get_T3_evaluated() || o1._get_T3_readpriority() != o2._get_T3_readpriority() || o1._get_T3_readvalue() != o2._get_T3_readvalue() || o1._get_T3_state() != o2._get_T3_state();
        }

        int hashCode() const {
            return this->_hashCode_1();
        }

        int _hashCode_1() const {
            int result = 1;
            result = (1543 * result) ^ ((this->_get_BUSpriority()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_BUSvalue()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_BUSwrite()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_T1_state()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_T1_timer()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_T1_writevalue()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_T2_mode()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_T2_readpriority()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_T2_readvalue()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_T2_state()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_T2_timer()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_T2_writevalue()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_T2v()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_T3_enabled()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_T3_evaluated()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_T3_readpriority()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_T3_readvalue()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_T3_state()).hashCode() << 1);
            return result;
        }

        int _hashCode_2() const {
            int result = 1;
            result = (6151 * result) ^ ((this->_get_BUSpriority()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_BUSvalue()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_BUSwrite()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_T1_state()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_T1_timer()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_T1_writevalue()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_T2_mode()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_T2_readpriority()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_T2_readvalue()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_T2_state()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_T2_timer()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_T2_writevalue()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_T2v()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_T3_enabled()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_T3_evaluated()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_T3_readpriority()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_T3_readvalue()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_T3_state()).hashCode() << 1);
            return result;
        }

        friend std::ostream& operator<<(std::ostream &strm, const CAN_BUS_tlc &machine) {
          strm << "_get_BUSpriority: " << machine._get_BUSpriority() << "\n";
          strm << "_get_BUSvalue: " << machine._get_BUSvalue() << "\n";
          strm << "_get_BUSwrite: " << machine._get_BUSwrite() << "\n";
          strm << "_get_T1_state: " << machine._get_T1_state() << "\n";
          strm << "_get_T1_timer: " << machine._get_T1_timer() << "\n";
          strm << "_get_T1_writevalue: " << machine._get_T1_writevalue() << "\n";
          strm << "_get_T2_mode: " << machine._get_T2_mode() << "\n";
          strm << "_get_T2_readpriority: " << machine._get_T2_readpriority() << "\n";
          strm << "_get_T2_readvalue: " << machine._get_T2_readvalue() << "\n";
          strm << "_get_T2_state: " << machine._get_T2_state() << "\n";
          strm << "_get_T2_timer: " << machine._get_T2_timer() << "\n";
          strm << "_get_T2_writevalue: " << machine._get_T2_writevalue() << "\n";
          strm << "_get_T2v: " << machine._get_T2v() << "\n";
          strm << "_get_T3_enabled: " << machine._get_T3_enabled() << "\n";
          strm << "_get_T3_evaluated: " << machine._get_T3_evaluated() << "\n";
          strm << "_get_T3_readpriority: " << machine._get_T3_readpriority() << "\n";
          strm << "_get_T3_readvalue: " << machine._get_T3_readvalue() << "\n";
          strm << "_get_T3_state: " << machine._get_T3_state() << "\n";
          return strm;
        }


};


static std::unordered_set<CAN_BUS_tlc, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual> generateNextStates(std::mutex& guardMutex, const CAN_BUS_tlc& state, bool isCaching, std::unordered_map<string, std::unordered_set<string>>& invariantDependency, std::unordered_map<CAN_BUS_tlc, std::unordered_set<string>, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual>& dependentInvariant, std::unordered_map<string, std::unordered_set<string>>& guardDependency, std::unordered_map<CAN_BUS_tlc, std::unordered_set<string>, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual>& dependentGuard, std::unordered_map<CAN_BUS_tlc, immer::map<string, boost::any>, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual>& guardCache, std::unordered_map<CAN_BUS_tlc, CAN_BUS_tlc, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual>& parents, std::atomic<int>& transitions) {
    std::unordered_set<CAN_BUS_tlc, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual> result = std::unordered_set<CAN_BUS_tlc, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual>();
    if(isCaching) {
        immer::map<string, boost::any> parentsGuard;
        std::unordered_set<string> dependentGuardsOfState;
        bool parentsExist = false;
        bool dependentGuardsExist = false;
        {
            std::unique_lock<std::mutex> lock(guardMutex);
            parentsExist = (parents.find(state) != parents.end());
            dependentGuardsExist = (dependentGuard.find(state) != dependentGuard.end());
            if(parentsExist) {
                parentsGuard = guardCache[parents[state]];
            }
            if(dependentGuardsExist) {
                dependentGuardsOfState = dependentGuard[state];
            }
        }
        immer::map<string, boost::any> newCache = parentsGuard;
        boost::any cachedValue;
        bool dependentGuardsBoolean = true;
        bool _trid_1;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_T1Evaluate"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_T1Evaluate") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_1 = state._tr_T1Evaluate();
        } else {
            _trid_1 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_T1Evaluate", _trid_1);
        if(_trid_1) {
            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T1Evaluate();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["T1Evaluate"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["T1Evaluate"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BInteger> _trid_2;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_T1Calculate"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_T1Calculate") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_2 = state._tr_T1Calculate();
        } else {
            _trid_2 = boost::any_cast<BSet<BInteger>>(cachedValue);
        }
        newCache = newCache.set("_tr_T1Calculate", _trid_2);
        for(const BInteger& param : _trid_2) {
            BInteger _tmp_1 = param;

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T1Calculate(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["T1Calculate"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["T1Calculate"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BInteger, BInteger >> _trid_3;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_T1SendResult"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_T1SendResult") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_3 = state._tr_T1SendResult();
        } else {
            _trid_3 = boost::any_cast<BSet<BTuple<BInteger, BInteger >>>(cachedValue);
        }
        newCache = newCache.set("_tr_T1SendResult", _trid_3);
        for(const BTuple<BInteger, BInteger >& param : _trid_3) {
            BInteger _tmp_1 = param.projection2();
            BInteger _tmp_2 = param.projection1();

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T1SendResult(_tmp_2, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["T1SendResult"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["T1SendResult"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BInteger> _trid_4;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_T1Wait"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_T1Wait") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_4 = state._tr_T1Wait();
        } else {
            _trid_4 = boost::any_cast<BSet<BInteger>>(cachedValue);
        }
        newCache = newCache.set("_tr_T1Wait", _trid_4);
        for(const BInteger& param : _trid_4) {
            BInteger _tmp_1 = param;

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T1Wait(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["T1Wait"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["T1Wait"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_5;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_T2Evaluate"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_T2Evaluate") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_5 = state._tr_T2Evaluate();
        } else {
            _trid_5 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_T2Evaluate", _trid_5);
        if(_trid_5) {
            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T2Evaluate();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["T2Evaluate"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["T2Evaluate"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BInteger, BInteger >> _trid_6;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_T2ReadBus"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_T2ReadBus") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_6 = state._tr_T2ReadBus();
        } else {
            _trid_6 = boost::any_cast<BSet<BTuple<BInteger, BInteger >>>(cachedValue);
        }
        newCache = newCache.set("_tr_T2ReadBus", _trid_6);
        for(const BTuple<BInteger, BInteger >& param : _trid_6) {
            BInteger _tmp_1 = param.projection2();
            BInteger _tmp_2 = param.projection1();

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T2ReadBus(_tmp_2, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["T2ReadBus"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["T2ReadBus"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_7;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_T2Reset"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_T2Reset") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_7 = state._tr_T2Reset();
        } else {
            _trid_7 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_T2Reset", _trid_7);
        if(_trid_7) {
            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T2Reset();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["T2Reset"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["T2Reset"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_8;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_T2Complete"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_T2Complete") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_8 = state._tr_T2Complete();
        } else {
            _trid_8 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_T2Complete", _trid_8);
        if(_trid_8) {
            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T2Complete();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["T2Complete"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["T2Complete"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BInteger> _trid_9;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_T2ReleaseBus"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_T2ReleaseBus") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_9 = state._tr_T2ReleaseBus();
        } else {
            _trid_9 = boost::any_cast<BSet<BInteger>>(cachedValue);
        }
        newCache = newCache.set("_tr_T2ReleaseBus", _trid_9);
        for(const BInteger& param : _trid_9) {
            BInteger _tmp_1 = param;

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T2ReleaseBus(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["T2ReleaseBus"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["T2ReleaseBus"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_10;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_T2Calculate"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_T2Calculate") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_10 = state._tr_T2Calculate();
        } else {
            _trid_10 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_T2Calculate", _trid_10);
        if(_trid_10) {
            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T2Calculate();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["T2Calculate"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["T2Calculate"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BInteger, BInteger >> _trid_11;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_T2WriteBus"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_T2WriteBus") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_11 = state._tr_T2WriteBus();
        } else {
            _trid_11 = boost::any_cast<BSet<BTuple<BInteger, BInteger >>>(cachedValue);
        }
        newCache = newCache.set("_tr_T2WriteBus", _trid_11);
        for(const BTuple<BInteger, BInteger >& param : _trid_11) {
            BInteger _tmp_1 = param.projection2();
            BInteger _tmp_2 = param.projection1();

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T2WriteBus(_tmp_2, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["T2WriteBus"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["T2WriteBus"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BInteger> _trid_12;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_T2Wait"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_T2Wait") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_12 = state._tr_T2Wait();
        } else {
            _trid_12 = boost::any_cast<BSet<BInteger>>(cachedValue);
        }
        newCache = newCache.set("_tr_T2Wait", _trid_12);
        for(const BInteger& param : _trid_12) {
            BInteger _tmp_1 = param;

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T2Wait(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["T2Wait"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["T2Wait"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_13;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_T3Initiate"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_T3Initiate") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_13 = state._tr_T3Initiate();
        } else {
            _trid_13 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_T3Initiate", _trid_13);
        if(_trid_13) {
            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T3Initiate();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["T3Initiate"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["T3Initiate"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_14;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_T3Evaluate"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_T3Evaluate") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_14 = state._tr_T3Evaluate();
        } else {
            _trid_14 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_T3Evaluate", _trid_14);
        if(_trid_14) {
            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T3Evaluate();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["T3Evaluate"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["T3Evaluate"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BInteger, BInteger >> _trid_15;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_T3writebus"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_T3writebus") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_15 = state._tr_T3writebus();
        } else {
            _trid_15 = boost::any_cast<BSet<BTuple<BInteger, BInteger >>>(cachedValue);
        }
        newCache = newCache.set("_tr_T3writebus", _trid_15);
        for(const BTuple<BInteger, BInteger >& param : _trid_15) {
            BInteger _tmp_1 = param.projection2();
            BInteger _tmp_2 = param.projection1();

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T3writebus(_tmp_2, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["T3writebus"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["T3writebus"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BInteger, BInteger >> _trid_16;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_T3Read"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_T3Read") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_16 = state._tr_T3Read();
        } else {
            _trid_16 = boost::any_cast<BSet<BTuple<BInteger, BInteger >>>(cachedValue);
        }
        newCache = newCache.set("_tr_T3Read", _trid_16);
        for(const BTuple<BInteger, BInteger >& param : _trid_16) {
            BInteger _tmp_1 = param.projection2();
            BInteger _tmp_2 = param.projection1();

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T3Read(_tmp_2, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["T3Read"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["T3Read"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_17;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_T3Poll"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_T3Poll") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_17 = state._tr_T3Poll();
        } else {
            _trid_17 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_T3Poll", _trid_17);
        if(_trid_17) {
            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T3Poll();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["T3Poll"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["T3Poll"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BInteger> _trid_18;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_T3ReleaseBus"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_T3ReleaseBus") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_18 = state._tr_T3ReleaseBus();
        } else {
            _trid_18 = boost::any_cast<BSet<BInteger>>(cachedValue);
        }
        newCache = newCache.set("_tr_T3ReleaseBus", _trid_18);
        for(const BInteger& param : _trid_18) {
            BInteger _tmp_1 = param;

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T3ReleaseBus(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["T3ReleaseBus"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["T3ReleaseBus"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_19;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_T3Wait"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_T3Wait") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_19 = state._tr_T3Wait();
        } else {
            _trid_19 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_T3Wait", _trid_19);
        if(_trid_19) {
            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T3Wait();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["T3Wait"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["T3Wait"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_20;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_T3ReEnableWait"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_T3ReEnableWait") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_20 = state._tr_T3ReEnableWait();
        } else {
            _trid_20 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_T3ReEnableWait", _trid_20);
        if(_trid_20) {
            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T3ReEnableWait();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["T3ReEnableWait"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["T3ReEnableWait"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BInteger> _trid_21;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_Update"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_Update") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_21 = state._tr_Update();
        } else {
            _trid_21 = boost::any_cast<BSet<BInteger>>(cachedValue);
        }
        newCache = newCache.set("_tr_Update", _trid_21);
        for(const BInteger& param : _trid_21) {
            BInteger _tmp_1 = param;

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.Update(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["Update"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["Update"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }

        {
            std::unique_lock<std::mutex> lock(guardMutex);
            guardCache.insert({state, newCache});
        }
    } else {
        if(state._tr_T1Evaluate()) {
            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T1Evaluate();
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BInteger> _trid_2 = state._tr_T1Calculate();
        for(const BInteger& param : _trid_2) {
            BInteger _tmp_1 = param;

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T1Calculate(_tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BInteger, BInteger >> _trid_3 = state._tr_T1SendResult();
        for(const BTuple<BInteger, BInteger >& param : _trid_3) {
            BInteger _tmp_1 = param.projection2();
            BInteger _tmp_2 = param.projection1();

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T1SendResult(_tmp_2, _tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BInteger> _trid_4 = state._tr_T1Wait();
        for(const BInteger& param : _trid_4) {
            BInteger _tmp_1 = param;

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T1Wait(_tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_T2Evaluate()) {
            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T2Evaluate();
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BInteger, BInteger >> _trid_6 = state._tr_T2ReadBus();
        for(const BTuple<BInteger, BInteger >& param : _trid_6) {
            BInteger _tmp_1 = param.projection2();
            BInteger _tmp_2 = param.projection1();

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T2ReadBus(_tmp_2, _tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_T2Reset()) {
            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T2Reset();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_T2Complete()) {
            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T2Complete();
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BInteger> _trid_9 = state._tr_T2ReleaseBus();
        for(const BInteger& param : _trid_9) {
            BInteger _tmp_1 = param;

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T2ReleaseBus(_tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_T2Calculate()) {
            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T2Calculate();
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BInteger, BInteger >> _trid_11 = state._tr_T2WriteBus();
        for(const BTuple<BInteger, BInteger >& param : _trid_11) {
            BInteger _tmp_1 = param.projection2();
            BInteger _tmp_2 = param.projection1();

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T2WriteBus(_tmp_2, _tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BInteger> _trid_12 = state._tr_T2Wait();
        for(const BInteger& param : _trid_12) {
            BInteger _tmp_1 = param;

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T2Wait(_tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_T3Initiate()) {
            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T3Initiate();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_T3Evaluate()) {
            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T3Evaluate();
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BInteger, BInteger >> _trid_15 = state._tr_T3writebus();
        for(const BTuple<BInteger, BInteger >& param : _trid_15) {
            BInteger _tmp_1 = param.projection2();
            BInteger _tmp_2 = param.projection1();

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T3writebus(_tmp_2, _tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BInteger, BInteger >> _trid_16 = state._tr_T3Read();
        for(const BTuple<BInteger, BInteger >& param : _trid_16) {
            BInteger _tmp_1 = param.projection2();
            BInteger _tmp_2 = param.projection1();

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T3Read(_tmp_2, _tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_T3Poll()) {
            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T3Poll();
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BInteger> _trid_18 = state._tr_T3ReleaseBus();
        for(const BInteger& param : _trid_18) {
            BInteger _tmp_1 = param;

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T3ReleaseBus(_tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_T3Wait()) {
            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T3Wait();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_T3ReEnableWait()) {
            CAN_BUS_tlc copiedState = state._copy();
            copiedState.T3ReEnableWait();
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BInteger> _trid_21 = state._tr_Update();
        for(const BInteger& param : _trid_21) {
            BInteger _tmp_1 = param;

            CAN_BUS_tlc copiedState = state._copy();
            copiedState.Update(_tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }

    }
    return result;
}

static void printResult(int states, int transitions, bool deadlockDetected, bool invariantViolated) {
    if(deadlockDetected) {
        cout << "DEADLOCK DETECTED" << "\n";
    }
    if(invariantViolated) {
        cout << "INVARIANT VIOLATED" << "\n";
    }
    if(!deadlockDetected && !invariantViolated) {
        cout << "MODEL CHECKING SUCCESSFUL" << "\n";
    }
    cout << "Number of States: " << states << "\n";
    cout << "Number of Transitions: " << transitions << "\n";
}

static bool checkInvariants(std::mutex& guardMutex, const CAN_BUS_tlc& state, bool isCaching, std::unordered_map<CAN_BUS_tlc, std::unordered_set<string>, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual>& dependentInvariant) {
    if(isCaching) {
        std::unordered_set<string> dependentInvariantsOfState;
        {
            std::unique_lock<std::mutex> lock(guardMutex);
            dependentInvariantsOfState = dependentInvariant[state];
        }
        if(dependentInvariantsOfState.find("_check_inv_1") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_1()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_2") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_2()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_3") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_3()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_4") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_4()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_5") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_5()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_6") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_6()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_7") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_7()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_8") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_8()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_9") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_9()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_10") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_10()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_11") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_11()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_12") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_12()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_13") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_13()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_14") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_14()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_15") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_15()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_16") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_16()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_17") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_17()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_18") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_18()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_19") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_19()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_20") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_20()) {
                return false;
            }
        }
        return true;
    }
    return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6() || !state._check_inv_7() || !state._check_inv_8() || !state._check_inv_9() || !state._check_inv_10() || !state._check_inv_11() || !state._check_inv_12() || !state._check_inv_13() || !state._check_inv_14() || !state._check_inv_15() || !state._check_inv_16() || !state._check_inv_17() || !state._check_inv_18() || !state._check_inv_19() || !state._check_inv_20());
}

static CAN_BUS_tlc next(std::list<CAN_BUS_tlc>& collection, std::mutex& mutex, CAN_BUS_tlc::Type type) {
    std::unique_lock<std::mutex> lock(mutex);
    switch(type) {
        case CAN_BUS_tlc::BFS: {
            CAN_BUS_tlc state = collection.front();
            collection.pop_front();
            return state;
        }
        case CAN_BUS_tlc::DFS: {
            CAN_BUS_tlc state = collection.back();
            collection.pop_back();
            return state;
        }
        case CAN_BUS_tlc::MIXED: {
            if(collection.size() % 2 == 0) {
                CAN_BUS_tlc state = collection.front();
                collection.pop_front();
                return state;
            } else {
                CAN_BUS_tlc state = collection.back();
                collection.pop_back();
                return state;
            }
        }
    };
}

static void modelCheckSingleThreaded(CAN_BUS_tlc::Type type, bool isCaching) {
    std::mutex mutex;
    std::mutex guardMutex;

    CAN_BUS_tlc machine = CAN_BUS_tlc();

    std::atomic<bool> invariantViolated;
    invariantViolated = false;
    std::atomic<bool> deadlockDetected;
    deadlockDetected = false;
    std::atomic<bool> stopThreads;
    stopThreads = false;

    std::unordered_set<CAN_BUS_tlc, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual> states = std::unordered_set<CAN_BUS_tlc, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual>();
    states.insert(machine);
    std::atomic<int> numberStates;
    numberStates = 1;

    std::list<CAN_BUS_tlc> collection = std::list<CAN_BUS_tlc>();
    collection.push_back(machine);

    std::atomic<int> transitions;
    transitions = 0;

    std::unordered_map<string, std::unordered_set<string>> invariantDependency;
    std::unordered_map<string, std::unordered_set<string>> guardDependency;
    std::unordered_map<CAN_BUS_tlc, std::unordered_set<string>, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual> dependentInvariant;
    std::unordered_map<CAN_BUS_tlc, std::unordered_set<string>, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual> dependentGuard;
    std::unordered_map<CAN_BUS_tlc, immer::map<string, boost::any>, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual> guardCache;
    std::unordered_map<CAN_BUS_tlc, CAN_BUS_tlc, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual> parents;
    if(isCaching) {
        invariantDependency.insert({"T1Wait", {"_check_inv_10", "_check_inv_4"}});
        invariantDependency.insert({"T1Calculate", {"_check_inv_7", "_check_inv_4"}});
        invariantDependency.insert({"T1SendResult", {"_check_inv_18", "_check_inv_19", "_check_inv_20", "_check_inv_4"}});
        invariantDependency.insert({"T2ReadBus", {"_check_inv_17", "_check_inv_5", "_check_inv_9"}});
        invariantDependency.insert({"T2Reset", {"_check_inv_1", "_check_inv_5", "_check_inv_8", "_check_inv_12"}});
        invariantDependency.insert({"T2Complete", {"_check_inv_5", "_check_inv_12"}});
        invariantDependency.insert({"T2Evaluate", {"_check_inv_5", "_check_inv_11"}});
        invariantDependency.insert({"T3Evaluate", {"_check_inv_6"}});
        invariantDependency.insert({"T3ReleaseBus", {"_check_inv_18", "_check_inv_19", "_check_inv_6", "_check_inv_20"}});
        invariantDependency.insert({"T1Evaluate", {"_check_inv_10", "_check_inv_4"}});
        invariantDependency.insert({"T3Initiate", {"_check_inv_3", "_check_inv_6"}});
        invariantDependency.insert({"T3ReEnableWait", {"_check_inv_2", "_check_inv_3", "_check_inv_6"}});
        invariantDependency.insert({"T3writebus", {"_check_inv_18", "_check_inv_19", "_check_inv_6", "_check_inv_20"}});
        invariantDependency.insert({"Update", {"_check_inv_2", "_check_inv_10", "_check_inv_14", "_check_inv_13", "_check_inv_11"}});
        invariantDependency.insert({"T2ReleaseBus", {"_check_inv_18", "_check_inv_19", "_check_inv_20", "_check_inv_5"}});
        invariantDependency.insert({"T2Wait", {"_check_inv_5", "_check_inv_11"}});
        invariantDependency.insert({"T3Poll", {"_check_inv_6"}});
        invariantDependency.insert({"T2Calculate", {"_check_inv_1", "_check_inv_5"}});
        invariantDependency.insert({"T3Read", {"_check_inv_16", "_check_inv_15", "_check_inv_6"}});
        invariantDependency.insert({"T3Wait", {"_check_inv_2", "_check_inv_6"}});
        invariantDependency.insert({"T2WriteBus", {"_check_inv_18", "_check_inv_19", "_check_inv_20", "_check_inv_5"}});
        guardDependency.insert({"T1Wait", {"_tr_T1Evaluate", "_tr_Update", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"}});
        guardDependency.insert({"T1Calculate", {"_tr_T1Evaluate", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"}});
        guardDependency.insert({"T1SendResult", {"_tr_T1Evaluate", "_tr_T2ReleaseBus", "_tr_Update", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"}});
        guardDependency.insert({"T2ReadBus", {"_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"}});
        guardDependency.insert({"T2Reset", {"_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"}});
        guardDependency.insert({"T2Complete", {"_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"}});
        guardDependency.insert({"T2Evaluate", {"_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"}});
        guardDependency.insert({"T3Evaluate", {"_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"}});
        guardDependency.insert({"T3ReleaseBus", {"_tr_T2ReleaseBus", "_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"}});
        guardDependency.insert({"T1Evaluate", {"_tr_T1Evaluate", "_tr_Update", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"}});
        guardDependency.insert({"T3Initiate", {"_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"}});
        guardDependency.insert({"T3ReEnableWait", {"_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"}});
        guardDependency.insert({"T3writebus", {"_tr_T2ReleaseBus", "_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"}});
        guardDependency.insert({"Update", {"_tr_T1Evaluate", "_tr_T3Read", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T3Evaluate", "_tr_T3Initiate"}});
        guardDependency.insert({"T2ReleaseBus", {"_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"}});
        guardDependency.insert({"T2Wait", {"_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"}});
        guardDependency.insert({"T3Poll", {"_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"}});
        guardDependency.insert({"T2Calculate", {"_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"}});
        guardDependency.insert({"T3Read", {"_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"}});
        guardDependency.insert({"T3Wait", {"_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"}});
        guardDependency.insert({"T2WriteBus", {"_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"}});
        dependentInvariant.insert({machine, std::unordered_set<string>()});
    }

    while(!collection.empty() && !stopThreads) {
        CAN_BUS_tlc state = next(collection, mutex, type);

        if(!checkInvariants(guardMutex, state, isCaching, dependentInvariant)) {
            invariantViolated = true;
            stopThreads = true;
            break;
        }

        std::unordered_set<CAN_BUS_tlc, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual> nextStates = generateNextStates(guardMutex, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, transitions);
        for(auto nextState : nextStates) {
            if(states.find(nextState) == states.end()) {
                numberStates += 1;
                states.insert(nextState);
                collection.push_back(nextState);
                if(numberStates % 50000 == 0) {
                    cout << "VISITED STATES: " << numberStates << "\n";
                    cout << "EVALUATED TRANSITIONS: " << transitions << "\n";
                    cout << "-------------------" << "\n";
                }
            }
        }

        if(nextStates.empty()) {
            deadlockDetected = true;
            stopThreads = true;
        }

    }
    printResult(numberStates, transitions, deadlockDetected, invariantViolated);
}

static void modelCheckMultiThreaded(CAN_BUS_tlc::Type type, int threads, bool isCaching) {
    std::mutex mutex;
    std::mutex waitMutex;
    std::mutex guardMutex;
    std::condition_variable waitCV;

    CAN_BUS_tlc machine = CAN_BUS_tlc();


    std::atomic<bool> invariantViolated;
    invariantViolated = false;
    std::atomic<bool> deadlockDetected;
    deadlockDetected = false;
    std::atomic<bool> stopThreads;
    stopThreads = false;

    std::unordered_set<CAN_BUS_tlc, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual> states = std::unordered_set<CAN_BUS_tlc, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual>();
    states.insert(machine);
    std::atomic<int> numberStates;
    numberStates = 1;

    std::list<CAN_BUS_tlc> collection = std::list<CAN_BUS_tlc>();
    collection.push_back(machine);

    std::atomic<int> transitions;
    transitions = 0;

    std::atomic<int> possibleQueueChanges;
    possibleQueueChanges = 0;

    std::atomic<bool> waitFlag;
    waitFlag = true;

    std::unordered_map<string, std::unordered_set<string>> invariantDependency;
    std::unordered_map<string, std::unordered_set<string>> guardDependency;
    std::unordered_map<CAN_BUS_tlc, std::unordered_set<string>, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual> dependentInvariant;
    std::unordered_map<CAN_BUS_tlc, std::unordered_set<string>, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual> dependentGuard;
    std::unordered_map<CAN_BUS_tlc, immer::map<string, boost::any>, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual> guardCache;
    std::unordered_map<CAN_BUS_tlc, CAN_BUS_tlc, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual> parents;
    if(isCaching) {
        invariantDependency.insert({"T1Wait", {"_check_inv_10", "_check_inv_4"}});
        invariantDependency.insert({"T1Calculate", {"_check_inv_7", "_check_inv_4"}});
        invariantDependency.insert({"T1SendResult", {"_check_inv_18", "_check_inv_19", "_check_inv_20", "_check_inv_4"}});
        invariantDependency.insert({"T2ReadBus", {"_check_inv_17", "_check_inv_5", "_check_inv_9"}});
        invariantDependency.insert({"T2Reset", {"_check_inv_1", "_check_inv_5", "_check_inv_8", "_check_inv_12"}});
        invariantDependency.insert({"T2Complete", {"_check_inv_5", "_check_inv_12"}});
        invariantDependency.insert({"T2Evaluate", {"_check_inv_5", "_check_inv_11"}});
        invariantDependency.insert({"T3Evaluate", {"_check_inv_6"}});
        invariantDependency.insert({"T3ReleaseBus", {"_check_inv_18", "_check_inv_19", "_check_inv_6", "_check_inv_20"}});
        invariantDependency.insert({"T1Evaluate", {"_check_inv_10", "_check_inv_4"}});
        invariantDependency.insert({"T3Initiate", {"_check_inv_3", "_check_inv_6"}});
        invariantDependency.insert({"T3ReEnableWait", {"_check_inv_2", "_check_inv_3", "_check_inv_6"}});
        invariantDependency.insert({"T3writebus", {"_check_inv_18", "_check_inv_19", "_check_inv_6", "_check_inv_20"}});
        invariantDependency.insert({"Update", {"_check_inv_2", "_check_inv_10", "_check_inv_14", "_check_inv_13", "_check_inv_11"}});
        invariantDependency.insert({"T2ReleaseBus", {"_check_inv_18", "_check_inv_19", "_check_inv_20", "_check_inv_5"}});
        invariantDependency.insert({"T2Wait", {"_check_inv_5", "_check_inv_11"}});
        invariantDependency.insert({"T3Poll", {"_check_inv_6"}});
        invariantDependency.insert({"T2Calculate", {"_check_inv_1", "_check_inv_5"}});
        invariantDependency.insert({"T3Read", {"_check_inv_16", "_check_inv_15", "_check_inv_6"}});
        invariantDependency.insert({"T3Wait", {"_check_inv_2", "_check_inv_6"}});
        invariantDependency.insert({"T2WriteBus", {"_check_inv_18", "_check_inv_19", "_check_inv_20", "_check_inv_5"}});
        guardDependency.insert({"T1Wait", {"_tr_T1Evaluate", "_tr_Update", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"}});
        guardDependency.insert({"T1Calculate", {"_tr_T1Evaluate", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"}});
        guardDependency.insert({"T1SendResult", {"_tr_T1Evaluate", "_tr_T2ReleaseBus", "_tr_Update", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"}});
        guardDependency.insert({"T2ReadBus", {"_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"}});
        guardDependency.insert({"T2Reset", {"_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"}});
        guardDependency.insert({"T2Complete", {"_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"}});
        guardDependency.insert({"T2Evaluate", {"_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"}});
        guardDependency.insert({"T3Evaluate", {"_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"}});
        guardDependency.insert({"T3ReleaseBus", {"_tr_T2ReleaseBus", "_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"}});
        guardDependency.insert({"T1Evaluate", {"_tr_T1Evaluate", "_tr_Update", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"}});
        guardDependency.insert({"T3Initiate", {"_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"}});
        guardDependency.insert({"T3ReEnableWait", {"_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"}});
        guardDependency.insert({"T3writebus", {"_tr_T2ReleaseBus", "_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"}});
        guardDependency.insert({"Update", {"_tr_T1Evaluate", "_tr_T3Read", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T3Evaluate", "_tr_T3Initiate"}});
        guardDependency.insert({"T2ReleaseBus", {"_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"}});
        guardDependency.insert({"T2Wait", {"_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"}});
        guardDependency.insert({"T3Poll", {"_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"}});
        guardDependency.insert({"T2Calculate", {"_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"}});
        guardDependency.insert({"T3Read", {"_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"}});
        guardDependency.insert({"T3Wait", {"_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"}});
        guardDependency.insert({"T2WriteBus", {"_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"}});
        dependentInvariant.insert({machine, std::unordered_set<string>()});
    }

    boost::asio::thread_pool workers(threads);

    while(!collection.empty() && !stopThreads) {
        possibleQueueChanges += 1;
        CAN_BUS_tlc state = next(collection, mutex, type);
        std::packaged_task<void()> task([&, state] {
            std::unordered_set<CAN_BUS_tlc, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual> nextStates = generateNextStates(guardMutex, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, transitions);


            for(auto nextState : nextStates) {
                {
                    std::unique_lock<std::mutex> lock(mutex);
                    if(states.find(nextState) == states.end()) {
                        numberStates += 1;
                        states.insert(nextState);
                        collection.push_back(nextState);
                        if(numberStates % 50000 == 0) {
                            cout << "VISITED STATES: " << numberStates << "\n";
                            cout << "EVALUATED TRANSITIONS: " << transitions << "\n";
                            cout << "-------------------" << "\n";
                        }
                    }
                }
            }

            {
                std::unique_lock<std::mutex> lock(mutex);
                possibleQueueChanges -= 1;
                int running = possibleQueueChanges;
                if (!collection.empty() || running == 0) {
                    {
                        std::unique_lock<std::mutex> lock(waitMutex);
                        waitFlag = false;
                        waitCV.notify_one();
                    }
                }
            }

            if(nextStates.empty()) {
                deadlockDetected = true;
                stopThreads = true;
            }

            if(!checkInvariants(guardMutex, state, isCaching, dependentInvariant)) {
                invariantViolated = true;
                stopThreads = true;
            }


        });
        waitFlag = true;
        boost::asio::post(workers, std::move(task));

        {
            std::unique_lock<std::mutex> lock(waitMutex);
            if (collection.empty() && possibleQueueChanges > 0) {
                waitCV.wait(lock, [&] {
                    return waitFlag == false;
                });
            }
        }
    }
    workers.join();
    printResult(numberStates, transitions, deadlockDetected, invariantViolated);
}

int main(int argc, char *argv[]) {
    if(argc != 4) {
        cout << "Number of arguments errorneous\n";
        return -1;
    }
    string strategy = argv[1];
    string numberThreads = argv[2];
    string caching = argv[3];

    CAN_BUS_tlc::Type type;

    if(std::string("mixed").compare(strategy) == 0) {
        type = CAN_BUS_tlc::Type::MIXED;
    } else if(std::string("bf").compare(strategy) == 0) {
        type = CAN_BUS_tlc::Type::BFS;
    } else if (std::string("df").compare(strategy) == 0) {
        type = CAN_BUS_tlc::Type::DFS;
    } else {
        cout << "Input for strategy is wrong.\n";
        return -1;
    }

    int threads = 0;
    try {
        threads = std::stoi(numberThreads);
    } catch(std::invalid_argument e) {
        cout << "Input for number of threads is wrong.\n";
        return -1;
    }

    if(threads <= 0) {
        cout << "Input for number of threads is wrong.\n";
        return -1;
    }

    bool isCaching = true;


    if(std::string("true").compare(caching) == 0) {
        isCaching = true;
    } else if(std::string("false").compare(caching) == 0) {
        isCaching = false;
    } else {
        cout << "Input for caching is wrong.\n";
        return - 1;
    }

    if(threads == 1) {
        modelCheckSingleThreaded(type, isCaching);
    } else {
        modelCheckMultiThreaded(type, threads, isCaching);
    }
    return 0;
}



#endif
