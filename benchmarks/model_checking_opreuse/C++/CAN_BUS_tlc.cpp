#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <immer/map.hpp>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <atomic>
#include <any>
#include <mutex>
#include <shared_mutex>
#include <future>
#include <boost/asio/post.hpp>
#include <boost/asio/thread_pool.hpp>
#include <btypes_primitives/BUtils.hpp>
#include <btypes_primitives/StateNotReachableError.hpp>
#include <btypes_primitives/PreconditionOrAssertionViolation.hpp>
#include <btypes_primitives/VariantViolation.hpp>
#include <btypes_primitives/LoopInvariantViolation.hpp>
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
                    return strm;
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
                    return strm;
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
                    return strm;
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
                    return strm;
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

        class _ProjectionRead_T1Evaluate {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_T1Evaluate& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_T1Evaluate& obj1, const _ProjectionRead_T1Evaluate& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T1state T1_state;
                BInteger T1_timer;

                _ProjectionRead_T1Evaluate(const T1state& T1_state, const BInteger& T1_timer) {
                    this->T1_state = T1_state;
                    this->T1_timer = T1_timer;
                }

                friend bool operator ==(const _ProjectionRead_T1Evaluate& o1, const _ProjectionRead_T1Evaluate& o2) {
                    return o1.T1_state == (o2.T1_state) && o1.T1_timer == (o2.T1_timer);
                }

                friend bool operator !=(const _ProjectionRead_T1Evaluate& o1, const _ProjectionRead_T1Evaluate& o2) {
                    return o1.T1_state != (o2.T1_state) || o1.T1_timer != (o2.T1_timer);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_T1Evaluate& e) {
                    strm << "{";
                    strm << "T1_state: " << e.T1_state;
                    strm << ", ";
                    strm << "T1_timer: " << e.T1_timer;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T1_state.hashCode() << 1);
                    result = 31 * result + (T1_timer.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_T1Evaluate {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_T1Evaluate& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_T1Evaluate& obj1, const _ProjectionRead__tr_T1Evaluate& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T1state T1_state;
                BInteger T1_timer;

                _ProjectionRead__tr_T1Evaluate(const T1state& T1_state, const BInteger& T1_timer) {
                    this->T1_state = T1_state;
                    this->T1_timer = T1_timer;
                }

                friend bool operator ==(const _ProjectionRead__tr_T1Evaluate& o1, const _ProjectionRead__tr_T1Evaluate& o2) {
                    return o1.T1_state == (o2.T1_state) && o1.T1_timer == (o2.T1_timer);
                }

                friend bool operator !=(const _ProjectionRead__tr_T1Evaluate& o1, const _ProjectionRead__tr_T1Evaluate& o2) {
                    return o1.T1_state != (o2.T1_state) || o1.T1_timer != (o2.T1_timer);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_T1Evaluate& e) {
                    strm << "{";
                    strm << "T1_state: " << e.T1_state;
                    strm << ", "; 
                    strm << "T1_timer: " << e.T1_timer;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T1_state.hashCode() << 1);
                    result = 31 * result + (T1_timer.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_T1Evaluate {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_T1Evaluate& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_T1Evaluate& obj1, const _ProjectionWrite_T1Evaluate& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T1state T1_state;
                BInteger T1_timer;

                _ProjectionWrite_T1Evaluate(const T1state& T1_state, const BInteger& T1_timer) {
                    this->T1_state = T1_state;
                    this->T1_timer = T1_timer;
                }

                friend bool operator ==(const _ProjectionWrite_T1Evaluate& o1, const _ProjectionWrite_T1Evaluate& o2) {
                    return o1.T1_state == (o2.T1_state) && o1.T1_timer == (o2.T1_timer);
                }

                friend bool operator !=(const _ProjectionWrite_T1Evaluate& o1, const _ProjectionWrite_T1Evaluate& o2) {
                    return o1.T1_state != (o2.T1_state) || o1.T1_timer != (o2.T1_timer);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_T1Evaluate& e) {
                    strm << "{";
                    strm << "T1_state: " << e.T1_state;
                    strm << ", ";
                    strm << "T1_timer: " << e.T1_timer;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T1_state.hashCode() << 1);
                    result = 31 * result + (T1_timer.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_T1Calculate {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_T1Calculate& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_T1Calculate& obj1, const _ProjectionRead_T1Calculate& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T1state T1_state;

                _ProjectionRead_T1Calculate(const T1state& T1_state) {
                    this->T1_state = T1_state;
                }

                friend bool operator ==(const _ProjectionRead_T1Calculate& o1, const _ProjectionRead_T1Calculate& o2) {
                    return o1.T1_state == (o2.T1_state);
                }

                friend bool operator !=(const _ProjectionRead_T1Calculate& o1, const _ProjectionRead_T1Calculate& o2) {
                    return o1.T1_state != (o2.T1_state);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_T1Calculate& e) {
                    strm << "{";
                    strm << "T1_state: " << e.T1_state;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T1_state.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_T1Calculate {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_T1Calculate& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_T1Calculate& obj1, const _ProjectionRead__tr_T1Calculate& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T1state T1_state;

                _ProjectionRead__tr_T1Calculate(const T1state& T1_state) {
                    this->T1_state = T1_state;
                }

                friend bool operator ==(const _ProjectionRead__tr_T1Calculate& o1, const _ProjectionRead__tr_T1Calculate& o2) {
                    return o1.T1_state == (o2.T1_state);
                }

                friend bool operator !=(const _ProjectionRead__tr_T1Calculate& o1, const _ProjectionRead__tr_T1Calculate& o2) {
                    return o1.T1_state != (o2.T1_state);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_T1Calculate& e) {
                    strm << "{";
                    strm << "T1_state: " << e.T1_state;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T1_state.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_T1Calculate {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_T1Calculate& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_T1Calculate& obj1, const _ProjectionWrite_T1Calculate& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T1state T1_state;
                BInteger T1_writevalue;

                _ProjectionWrite_T1Calculate(const T1state& T1_state, const BInteger& T1_writevalue) {
                    this->T1_state = T1_state;
                    this->T1_writevalue = T1_writevalue;
                }

                friend bool operator ==(const _ProjectionWrite_T1Calculate& o1, const _ProjectionWrite_T1Calculate& o2) {
                    return o1.T1_state == (o2.T1_state) && o1.T1_writevalue == (o2.T1_writevalue);
                }

                friend bool operator !=(const _ProjectionWrite_T1Calculate& o1, const _ProjectionWrite_T1Calculate& o2) {
                    return o1.T1_state != (o2.T1_state) || o1.T1_writevalue != (o2.T1_writevalue);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_T1Calculate& e) {
                    strm << "{";
                    strm << "T1_state: " << e.T1_state;
                    strm << ", ";
                    strm << "T1_writevalue: " << e.T1_writevalue;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T1_state.hashCode() << 1);
                    result = 31 * result + (T1_writevalue.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_T1SendResult {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_T1SendResult& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_T1SendResult& obj1, const _ProjectionRead_T1SendResult& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T1state T1_state;
                BInteger T1_writevalue;
                BRelation<BInteger, BInteger > BUSwrite;

                _ProjectionRead_T1SendResult(const T1state& T1_state, const BInteger& T1_writevalue, const BRelation<BInteger, BInteger >& BUSwrite) {
                    this->T1_state = T1_state;
                    this->T1_writevalue = T1_writevalue;
                    this->BUSwrite = BUSwrite;
                }

                friend bool operator ==(const _ProjectionRead_T1SendResult& o1, const _ProjectionRead_T1SendResult& o2) {
                    return o1.T1_state == (o2.T1_state) && o1.T1_writevalue == (o2.T1_writevalue) && o1.BUSwrite == (o2.BUSwrite);
                }

                friend bool operator !=(const _ProjectionRead_T1SendResult& o1, const _ProjectionRead_T1SendResult& o2) {
                    return o1.T1_state != (o2.T1_state) || o1.T1_writevalue != (o2.T1_writevalue) || o1.BUSwrite != (o2.BUSwrite);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_T1SendResult& e) {
                    strm << "{";
                    strm << "T1_state: " << e.T1_state;
                    strm << ", ";
                    strm << "T1_writevalue: " << e.T1_writevalue;
                    strm << ", ";
                    strm << "BUSwrite: " << e.BUSwrite;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T1_state.hashCode() << 1);
                    result = 31 * result + (T1_writevalue.hashCode() << 1);
                    result = 31 * result + (BUSwrite.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_T1SendResult {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_T1SendResult& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_T1SendResult& obj1, const _ProjectionRead__tr_T1SendResult& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T1state T1_state;
                BInteger T1_writevalue;

                _ProjectionRead__tr_T1SendResult(const T1state& T1_state, const BInteger& T1_writevalue) {
                    this->T1_state = T1_state;
                    this->T1_writevalue = T1_writevalue;
                }

                friend bool operator ==(const _ProjectionRead__tr_T1SendResult& o1, const _ProjectionRead__tr_T1SendResult& o2) {
                    return o1.T1_state == (o2.T1_state) && o1.T1_writevalue == (o2.T1_writevalue);
                }

                friend bool operator !=(const _ProjectionRead__tr_T1SendResult& o1, const _ProjectionRead__tr_T1SendResult& o2) {
                    return o1.T1_state != (o2.T1_state) || o1.T1_writevalue != (o2.T1_writevalue);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_T1SendResult& e) {
                    strm << "{";
                    strm << "T1_state: " << e.T1_state;
                    strm << ", "; 
                    strm << "T1_writevalue: " << e.T1_writevalue;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T1_state.hashCode() << 1);
                    result = 31 * result + (T1_writevalue.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_T1SendResult {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_T1SendResult& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_T1SendResult& obj1, const _ProjectionWrite_T1SendResult& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T1state T1_state;
                BRelation<BInteger, BInteger > BUSwrite;

                _ProjectionWrite_T1SendResult(const T1state& T1_state, const BRelation<BInteger, BInteger >& BUSwrite) {
                    this->T1_state = T1_state;
                    this->BUSwrite = BUSwrite;
                }

                friend bool operator ==(const _ProjectionWrite_T1SendResult& o1, const _ProjectionWrite_T1SendResult& o2) {
                    return o1.T1_state == (o2.T1_state) && o1.BUSwrite == (o2.BUSwrite);
                }

                friend bool operator !=(const _ProjectionWrite_T1SendResult& o1, const _ProjectionWrite_T1SendResult& o2) {
                    return o1.T1_state != (o2.T1_state) || o1.BUSwrite != (o2.BUSwrite);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_T1SendResult& e) {
                    strm << "{";
                    strm << "T1_state: " << e.T1_state;
                    strm << ", ";
                    strm << "BUSwrite: " << e.BUSwrite;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T1_state.hashCode() << 1);
                    result = 31 * result + (BUSwrite.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_T1Wait {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_T1Wait& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_T1Wait& obj1, const _ProjectionRead_T1Wait& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T1state T1_state;

                _ProjectionRead_T1Wait(const T1state& T1_state) {
                    this->T1_state = T1_state;
                }

                friend bool operator ==(const _ProjectionRead_T1Wait& o1, const _ProjectionRead_T1Wait& o2) {
                    return o1.T1_state == (o2.T1_state);
                }

                friend bool operator !=(const _ProjectionRead_T1Wait& o1, const _ProjectionRead_T1Wait& o2) {
                    return o1.T1_state != (o2.T1_state);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_T1Wait& e) {
                    strm << "{";
                    strm << "T1_state: " << e.T1_state;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T1_state.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_T1Wait {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_T1Wait& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_T1Wait& obj1, const _ProjectionRead__tr_T1Wait& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T1state T1_state;

                _ProjectionRead__tr_T1Wait(const T1state& T1_state) {
                    this->T1_state = T1_state;
                }

                friend bool operator ==(const _ProjectionRead__tr_T1Wait& o1, const _ProjectionRead__tr_T1Wait& o2) {
                    return o1.T1_state == (o2.T1_state);
                }

                friend bool operator !=(const _ProjectionRead__tr_T1Wait& o1, const _ProjectionRead__tr_T1Wait& o2) {
                    return o1.T1_state != (o2.T1_state);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_T1Wait& e) {
                    strm << "{";
                    strm << "T1_state: " << e.T1_state;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T1_state.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_T1Wait {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_T1Wait& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_T1Wait& obj1, const _ProjectionWrite_T1Wait& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T1state T1_state;
                BInteger T1_timer;

                _ProjectionWrite_T1Wait(const T1state& T1_state, const BInteger& T1_timer) {
                    this->T1_state = T1_state;
                    this->T1_timer = T1_timer;
                }

                friend bool operator ==(const _ProjectionWrite_T1Wait& o1, const _ProjectionWrite_T1Wait& o2) {
                    return o1.T1_state == (o2.T1_state) && o1.T1_timer == (o2.T1_timer);
                }

                friend bool operator !=(const _ProjectionWrite_T1Wait& o1, const _ProjectionWrite_T1Wait& o2) {
                    return o1.T1_state != (o2.T1_state) || o1.T1_timer != (o2.T1_timer);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_T1Wait& e) {
                    strm << "{";
                    strm << "T1_state: " << e.T1_state;
                    strm << ", ";
                    strm << "T1_timer: " << e.T1_timer;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T1_state.hashCode() << 1);
                    result = 31 * result + (T1_timer.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_T2Evaluate {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_T2Evaluate& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_T2Evaluate& obj1, const _ProjectionRead_T2Evaluate& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                BInteger T2_timer;

                _ProjectionRead_T2Evaluate(const T2state& T2_state, const BInteger& T2_timer) {
                    this->T2_state = T2_state;
                    this->T2_timer = T2_timer;
                }

                friend bool operator ==(const _ProjectionRead_T2Evaluate& o1, const _ProjectionRead_T2Evaluate& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.T2_timer == (o2.T2_timer);
                }

                friend bool operator !=(const _ProjectionRead_T2Evaluate& o1, const _ProjectionRead_T2Evaluate& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.T2_timer != (o2.T2_timer);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_T2Evaluate& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", ";
                    strm << "T2_timer: " << e.T2_timer;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (T2_timer.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_T2Evaluate {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_T2Evaluate& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_T2Evaluate& obj1, const _ProjectionRead__tr_T2Evaluate& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                BInteger T2_timer;

                _ProjectionRead__tr_T2Evaluate(const T2state& T2_state, const BInteger& T2_timer) {
                    this->T2_state = T2_state;
                    this->T2_timer = T2_timer;
                }

                friend bool operator ==(const _ProjectionRead__tr_T2Evaluate& o1, const _ProjectionRead__tr_T2Evaluate& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.T2_timer == (o2.T2_timer);
                }

                friend bool operator !=(const _ProjectionRead__tr_T2Evaluate& o1, const _ProjectionRead__tr_T2Evaluate& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.T2_timer != (o2.T2_timer);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_T2Evaluate& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", "; 
                    strm << "T2_timer: " << e.T2_timer;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (T2_timer.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_T2Evaluate {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_T2Evaluate& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_T2Evaluate& obj1, const _ProjectionWrite_T2Evaluate& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                BInteger T2_timer;

                _ProjectionWrite_T2Evaluate(const T2state& T2_state, const BInteger& T2_timer) {
                    this->T2_state = T2_state;
                    this->T2_timer = T2_timer;
                }

                friend bool operator ==(const _ProjectionWrite_T2Evaluate& o1, const _ProjectionWrite_T2Evaluate& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.T2_timer == (o2.T2_timer);
                }

                friend bool operator !=(const _ProjectionWrite_T2Evaluate& o1, const _ProjectionWrite_T2Evaluate& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.T2_timer != (o2.T2_timer);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_T2Evaluate& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", ";
                    strm << "T2_timer: " << e.T2_timer;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (T2_timer.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_T2ReadBus {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_T2ReadBus& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_T2ReadBus& obj1, const _ProjectionRead_T2ReadBus& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                BInteger BUSpriority;
                BInteger BUSvalue;

                _ProjectionRead_T2ReadBus(const T2state& T2_state, const BInteger& BUSpriority, const BInteger& BUSvalue) {
                    this->T2_state = T2_state;
                    this->BUSpriority = BUSpriority;
                    this->BUSvalue = BUSvalue;
                }

                friend bool operator ==(const _ProjectionRead_T2ReadBus& o1, const _ProjectionRead_T2ReadBus& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.BUSpriority == (o2.BUSpriority) && o1.BUSvalue == (o2.BUSvalue);
                }

                friend bool operator !=(const _ProjectionRead_T2ReadBus& o1, const _ProjectionRead_T2ReadBus& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.BUSpriority != (o2.BUSpriority) || o1.BUSvalue != (o2.BUSvalue);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_T2ReadBus& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", ";
                    strm << "BUSpriority: " << e.BUSpriority;
                    strm << ", ";
                    strm << "BUSvalue: " << e.BUSvalue;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (BUSpriority.hashCode() << 1);
                    result = 31 * result + (BUSvalue.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_T2ReadBus {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_T2ReadBus& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_T2ReadBus& obj1, const _ProjectionRead__tr_T2ReadBus& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                BInteger BUSpriority;
                BInteger BUSvalue;

                _ProjectionRead__tr_T2ReadBus(const T2state& T2_state, const BInteger& BUSpriority, const BInteger& BUSvalue) {
                    this->T2_state = T2_state;
                    this->BUSpriority = BUSpriority;
                    this->BUSvalue = BUSvalue;
                }

                friend bool operator ==(const _ProjectionRead__tr_T2ReadBus& o1, const _ProjectionRead__tr_T2ReadBus& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.BUSpriority == (o2.BUSpriority) && o1.BUSvalue == (o2.BUSvalue);
                }

                friend bool operator !=(const _ProjectionRead__tr_T2ReadBus& o1, const _ProjectionRead__tr_T2ReadBus& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.BUSpriority != (o2.BUSpriority) || o1.BUSvalue != (o2.BUSvalue);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_T2ReadBus& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", "; 
                    strm << "BUSpriority: " << e.BUSpriority;
                    strm << ", "; 
                    strm << "BUSvalue: " << e.BUSvalue;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (BUSpriority.hashCode() << 1);
                    result = 31 * result + (BUSvalue.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_T2ReadBus {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_T2ReadBus& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_T2ReadBus& obj1, const _ProjectionWrite_T2ReadBus& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                BInteger T2_readpriority;
                BInteger T2_readvalue;

                _ProjectionWrite_T2ReadBus(const T2state& T2_state, const BInteger& T2_readpriority, const BInteger& T2_readvalue) {
                    this->T2_state = T2_state;
                    this->T2_readpriority = T2_readpriority;
                    this->T2_readvalue = T2_readvalue;
                }

                friend bool operator ==(const _ProjectionWrite_T2ReadBus& o1, const _ProjectionWrite_T2ReadBus& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.T2_readpriority == (o2.T2_readpriority) && o1.T2_readvalue == (o2.T2_readvalue);
                }

                friend bool operator !=(const _ProjectionWrite_T2ReadBus& o1, const _ProjectionWrite_T2ReadBus& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.T2_readpriority != (o2.T2_readpriority) || o1.T2_readvalue != (o2.T2_readvalue);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_T2ReadBus& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", ";
                    strm << "T2_readpriority: " << e.T2_readpriority;
                    strm << ", ";
                    strm << "T2_readvalue: " << e.T2_readvalue;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (T2_readpriority.hashCode() << 1);
                    result = 31 * result + (T2_readvalue.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_T2Reset {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_T2Reset& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_T2Reset& obj1, const _ProjectionRead_T2Reset& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                BInteger T2_readpriority;
                BInteger T2v;

                _ProjectionRead_T2Reset(const T2state& T2_state, const BInteger& T2_readpriority, const BInteger& T2v) {
                    this->T2_state = T2_state;
                    this->T2_readpriority = T2_readpriority;
                    this->T2v = T2v;
                }

                friend bool operator ==(const _ProjectionRead_T2Reset& o1, const _ProjectionRead_T2Reset& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.T2_readpriority == (o2.T2_readpriority) && o1.T2v == (o2.T2v);
                }

                friend bool operator !=(const _ProjectionRead_T2Reset& o1, const _ProjectionRead_T2Reset& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.T2_readpriority != (o2.T2_readpriority) || o1.T2v != (o2.T2v);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_T2Reset& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", ";
                    strm << "T2_readpriority: " << e.T2_readpriority;
                    strm << ", ";
                    strm << "T2v: " << e.T2v;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (T2_readpriority.hashCode() << 1);
                    result = 31 * result + (T2v.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_T2Reset {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_T2Reset& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_T2Reset& obj1, const _ProjectionRead__tr_T2Reset& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                BInteger T2_readpriority;

                _ProjectionRead__tr_T2Reset(const T2state& T2_state, const BInteger& T2_readpriority) {
                    this->T2_state = T2_state;
                    this->T2_readpriority = T2_readpriority;
                }

                friend bool operator ==(const _ProjectionRead__tr_T2Reset& o1, const _ProjectionRead__tr_T2Reset& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.T2_readpriority == (o2.T2_readpriority);
                }

                friend bool operator !=(const _ProjectionRead__tr_T2Reset& o1, const _ProjectionRead__tr_T2Reset& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.T2_readpriority != (o2.T2_readpriority);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_T2Reset& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", "; 
                    strm << "T2_readpriority: " << e.T2_readpriority;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (T2_readpriority.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_T2Reset {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_T2Reset& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_T2Reset& obj1, const _ProjectionWrite_T2Reset& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                BInteger T2_writevalue;
                BInteger T2v;
                T2mode T2_mode;

                _ProjectionWrite_T2Reset(const T2state& T2_state, const BInteger& T2_writevalue, const BInteger& T2v, const T2mode& T2_mode) {
                    this->T2_state = T2_state;
                    this->T2_writevalue = T2_writevalue;
                    this->T2v = T2v;
                    this->T2_mode = T2_mode;
                }

                friend bool operator ==(const _ProjectionWrite_T2Reset& o1, const _ProjectionWrite_T2Reset& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.T2_writevalue == (o2.T2_writevalue) && o1.T2v == (o2.T2v) && o1.T2_mode == (o2.T2_mode);
                }

                friend bool operator !=(const _ProjectionWrite_T2Reset& o1, const _ProjectionWrite_T2Reset& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.T2_writevalue != (o2.T2_writevalue) || o1.T2v != (o2.T2v) || o1.T2_mode != (o2.T2_mode);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_T2Reset& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", ";
                    strm << "T2_writevalue: " << e.T2_writevalue;
                    strm << ", ";
                    strm << "T2v: " << e.T2v;
                    strm << ", ";
                    strm << "T2_mode: " << e.T2_mode;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (T2_writevalue.hashCode() << 1);
                    result = 31 * result + (T2v.hashCode() << 1);
                    result = 31 * result + (T2_mode.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_T2Complete {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_T2Complete& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_T2Complete& obj1, const _ProjectionRead_T2Complete& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                BInteger T2_readpriority;
                T2mode T2_mode;

                _ProjectionRead_T2Complete(const T2state& T2_state, const BInteger& T2_readpriority, const T2mode& T2_mode) {
                    this->T2_state = T2_state;
                    this->T2_readpriority = T2_readpriority;
                    this->T2_mode = T2_mode;
                }

                friend bool operator ==(const _ProjectionRead_T2Complete& o1, const _ProjectionRead_T2Complete& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.T2_readpriority == (o2.T2_readpriority) && o1.T2_mode == (o2.T2_mode);
                }

                friend bool operator !=(const _ProjectionRead_T2Complete& o1, const _ProjectionRead_T2Complete& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.T2_readpriority != (o2.T2_readpriority) || o1.T2_mode != (o2.T2_mode);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_T2Complete& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", ";
                    strm << "T2_readpriority: " << e.T2_readpriority;
                    strm << ", ";
                    strm << "T2_mode: " << e.T2_mode;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (T2_readpriority.hashCode() << 1);
                    result = 31 * result + (T2_mode.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_T2Complete {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_T2Complete& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_T2Complete& obj1, const _ProjectionRead__tr_T2Complete& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                BInteger T2_readpriority;
                T2mode T2_mode;

                _ProjectionRead__tr_T2Complete(const T2state& T2_state, const BInteger& T2_readpriority, const T2mode& T2_mode) {
                    this->T2_state = T2_state;
                    this->T2_readpriority = T2_readpriority;
                    this->T2_mode = T2_mode;
                }

                friend bool operator ==(const _ProjectionRead__tr_T2Complete& o1, const _ProjectionRead__tr_T2Complete& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.T2_readpriority == (o2.T2_readpriority) && o1.T2_mode == (o2.T2_mode);
                }

                friend bool operator !=(const _ProjectionRead__tr_T2Complete& o1, const _ProjectionRead__tr_T2Complete& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.T2_readpriority != (o2.T2_readpriority) || o1.T2_mode != (o2.T2_mode);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_T2Complete& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", "; 
                    strm << "T2_readpriority: " << e.T2_readpriority;
                    strm << ", "; 
                    strm << "T2_mode: " << e.T2_mode;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (T2_readpriority.hashCode() << 1);
                    result = 31 * result + (T2_mode.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_T2Complete {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_T2Complete& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_T2Complete& obj1, const _ProjectionWrite_T2Complete& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                T2mode T2_mode;

                _ProjectionWrite_T2Complete(const T2state& T2_state, const T2mode& T2_mode) {
                    this->T2_state = T2_state;
                    this->T2_mode = T2_mode;
                }

                friend bool operator ==(const _ProjectionWrite_T2Complete& o1, const _ProjectionWrite_T2Complete& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.T2_mode == (o2.T2_mode);
                }

                friend bool operator !=(const _ProjectionWrite_T2Complete& o1, const _ProjectionWrite_T2Complete& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.T2_mode != (o2.T2_mode);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_T2Complete& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", ";
                    strm << "T2_mode: " << e.T2_mode;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (T2_mode.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_T2ReleaseBus {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_T2ReleaseBus& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_T2ReleaseBus& obj1, const _ProjectionRead_T2ReleaseBus& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                BInteger T2_readpriority;
                BRelation<BInteger, BInteger > BUSwrite;

                _ProjectionRead_T2ReleaseBus(const T2state& T2_state, const BInteger& T2_readpriority, const BRelation<BInteger, BInteger >& BUSwrite) {
                    this->T2_state = T2_state;
                    this->T2_readpriority = T2_readpriority;
                    this->BUSwrite = BUSwrite;
                }

                friend bool operator ==(const _ProjectionRead_T2ReleaseBus& o1, const _ProjectionRead_T2ReleaseBus& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.T2_readpriority == (o2.T2_readpriority) && o1.BUSwrite == (o2.BUSwrite);
                }

                friend bool operator !=(const _ProjectionRead_T2ReleaseBus& o1, const _ProjectionRead_T2ReleaseBus& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.T2_readpriority != (o2.T2_readpriority) || o1.BUSwrite != (o2.BUSwrite);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_T2ReleaseBus& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", ";
                    strm << "T2_readpriority: " << e.T2_readpriority;
                    strm << ", ";
                    strm << "BUSwrite: " << e.BUSwrite;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (T2_readpriority.hashCode() << 1);
                    result = 31 * result + (BUSwrite.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_T2ReleaseBus {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_T2ReleaseBus& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_T2ReleaseBus& obj1, const _ProjectionRead__tr_T2ReleaseBus& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                BInteger T2_readpriority;
                BRelation<BInteger, BInteger > BUSwrite;

                _ProjectionRead__tr_T2ReleaseBus(const T2state& T2_state, const BInteger& T2_readpriority, const BRelation<BInteger, BInteger >& BUSwrite) {
                    this->T2_state = T2_state;
                    this->T2_readpriority = T2_readpriority;
                    this->BUSwrite = BUSwrite;
                }

                friend bool operator ==(const _ProjectionRead__tr_T2ReleaseBus& o1, const _ProjectionRead__tr_T2ReleaseBus& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.T2_readpriority == (o2.T2_readpriority) && o1.BUSwrite == (o2.BUSwrite);
                }

                friend bool operator !=(const _ProjectionRead__tr_T2ReleaseBus& o1, const _ProjectionRead__tr_T2ReleaseBus& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.T2_readpriority != (o2.T2_readpriority) || o1.BUSwrite != (o2.BUSwrite);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_T2ReleaseBus& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", "; 
                    strm << "T2_readpriority: " << e.T2_readpriority;
                    strm << ", "; 
                    strm << "BUSwrite: " << e.BUSwrite;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (T2_readpriority.hashCode() << 1);
                    result = 31 * result + (BUSwrite.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_T2ReleaseBus {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_T2ReleaseBus& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_T2ReleaseBus& obj1, const _ProjectionWrite_T2ReleaseBus& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                BRelation<BInteger, BInteger > BUSwrite;

                _ProjectionWrite_T2ReleaseBus(const T2state& T2_state, const BRelation<BInteger, BInteger >& BUSwrite) {
                    this->T2_state = T2_state;
                    this->BUSwrite = BUSwrite;
                }

                friend bool operator ==(const _ProjectionWrite_T2ReleaseBus& o1, const _ProjectionWrite_T2ReleaseBus& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.BUSwrite == (o2.BUSwrite);
                }

                friend bool operator !=(const _ProjectionWrite_T2ReleaseBus& o1, const _ProjectionWrite_T2ReleaseBus& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.BUSwrite != (o2.BUSwrite);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_T2ReleaseBus& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", ";
                    strm << "BUSwrite: " << e.BUSwrite;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (BUSwrite.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_T2Calculate {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_T2Calculate& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_T2Calculate& obj1, const _ProjectionRead_T2Calculate& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                BInteger T2_readpriority;
                BInteger T2_readvalue;

                _ProjectionRead_T2Calculate(const T2state& T2_state, const BInteger& T2_readpriority, const BInteger& T2_readvalue) {
                    this->T2_state = T2_state;
                    this->T2_readpriority = T2_readpriority;
                    this->T2_readvalue = T2_readvalue;
                }

                friend bool operator ==(const _ProjectionRead_T2Calculate& o1, const _ProjectionRead_T2Calculate& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.T2_readpriority == (o2.T2_readpriority) && o1.T2_readvalue == (o2.T2_readvalue);
                }

                friend bool operator !=(const _ProjectionRead_T2Calculate& o1, const _ProjectionRead_T2Calculate& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.T2_readpriority != (o2.T2_readpriority) || o1.T2_readvalue != (o2.T2_readvalue);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_T2Calculate& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", ";
                    strm << "T2_readpriority: " << e.T2_readpriority;
                    strm << ", ";
                    strm << "T2_readvalue: " << e.T2_readvalue;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (T2_readpriority.hashCode() << 1);
                    result = 31 * result + (T2_readvalue.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_T2Calculate {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_T2Calculate& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_T2Calculate& obj1, const _ProjectionRead__tr_T2Calculate& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                BInteger T2_readpriority;

                _ProjectionRead__tr_T2Calculate(const T2state& T2_state, const BInteger& T2_readpriority) {
                    this->T2_state = T2_state;
                    this->T2_readpriority = T2_readpriority;
                }

                friend bool operator ==(const _ProjectionRead__tr_T2Calculate& o1, const _ProjectionRead__tr_T2Calculate& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.T2_readpriority == (o2.T2_readpriority);
                }

                friend bool operator !=(const _ProjectionRead__tr_T2Calculate& o1, const _ProjectionRead__tr_T2Calculate& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.T2_readpriority != (o2.T2_readpriority);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_T2Calculate& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", "; 
                    strm << "T2_readpriority: " << e.T2_readpriority;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (T2_readpriority.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_T2Calculate {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_T2Calculate& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_T2Calculate& obj1, const _ProjectionWrite_T2Calculate& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                BInteger T2v;

                _ProjectionWrite_T2Calculate(const T2state& T2_state, const BInteger& T2v) {
                    this->T2_state = T2_state;
                    this->T2v = T2v;
                }

                friend bool operator ==(const _ProjectionWrite_T2Calculate& o1, const _ProjectionWrite_T2Calculate& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.T2v == (o2.T2v);
                }

                friend bool operator !=(const _ProjectionWrite_T2Calculate& o1, const _ProjectionWrite_T2Calculate& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.T2v != (o2.T2v);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_T2Calculate& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", ";
                    strm << "T2v: " << e.T2v;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (T2v.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_T2WriteBus {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_T2WriteBus& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_T2WriteBus& obj1, const _ProjectionRead_T2WriteBus& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                BInteger T2_writevalue;
                BRelation<BInteger, BInteger > BUSwrite;

                _ProjectionRead_T2WriteBus(const T2state& T2_state, const BInteger& T2_writevalue, const BRelation<BInteger, BInteger >& BUSwrite) {
                    this->T2_state = T2_state;
                    this->T2_writevalue = T2_writevalue;
                    this->BUSwrite = BUSwrite;
                }

                friend bool operator ==(const _ProjectionRead_T2WriteBus& o1, const _ProjectionRead_T2WriteBus& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.T2_writevalue == (o2.T2_writevalue) && o1.BUSwrite == (o2.BUSwrite);
                }

                friend bool operator !=(const _ProjectionRead_T2WriteBus& o1, const _ProjectionRead_T2WriteBus& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.T2_writevalue != (o2.T2_writevalue) || o1.BUSwrite != (o2.BUSwrite);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_T2WriteBus& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", ";
                    strm << "T2_writevalue: " << e.T2_writevalue;
                    strm << ", ";
                    strm << "BUSwrite: " << e.BUSwrite;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (T2_writevalue.hashCode() << 1);
                    result = 31 * result + (BUSwrite.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_T2WriteBus {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_T2WriteBus& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_T2WriteBus& obj1, const _ProjectionRead__tr_T2WriteBus& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                BInteger T2_writevalue;

                _ProjectionRead__tr_T2WriteBus(const T2state& T2_state, const BInteger& T2_writevalue) {
                    this->T2_state = T2_state;
                    this->T2_writevalue = T2_writevalue;
                }

                friend bool operator ==(const _ProjectionRead__tr_T2WriteBus& o1, const _ProjectionRead__tr_T2WriteBus& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.T2_writevalue == (o2.T2_writevalue);
                }

                friend bool operator !=(const _ProjectionRead__tr_T2WriteBus& o1, const _ProjectionRead__tr_T2WriteBus& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.T2_writevalue != (o2.T2_writevalue);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_T2WriteBus& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", "; 
                    strm << "T2_writevalue: " << e.T2_writevalue;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (T2_writevalue.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_T2WriteBus {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_T2WriteBus& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_T2WriteBus& obj1, const _ProjectionWrite_T2WriteBus& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                BRelation<BInteger, BInteger > BUSwrite;

                _ProjectionWrite_T2WriteBus(const T2state& T2_state, const BRelation<BInteger, BInteger >& BUSwrite) {
                    this->T2_state = T2_state;
                    this->BUSwrite = BUSwrite;
                }

                friend bool operator ==(const _ProjectionWrite_T2WriteBus& o1, const _ProjectionWrite_T2WriteBus& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.BUSwrite == (o2.BUSwrite);
                }

                friend bool operator !=(const _ProjectionWrite_T2WriteBus& o1, const _ProjectionWrite_T2WriteBus& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.BUSwrite != (o2.BUSwrite);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_T2WriteBus& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", ";
                    strm << "BUSwrite: " << e.BUSwrite;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (BUSwrite.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_T2Wait {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_T2Wait& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_T2Wait& obj1, const _ProjectionRead_T2Wait& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;

                _ProjectionRead_T2Wait(const T2state& T2_state) {
                    this->T2_state = T2_state;
                }

                friend bool operator ==(const _ProjectionRead_T2Wait& o1, const _ProjectionRead_T2Wait& o2) {
                    return o1.T2_state == (o2.T2_state);
                }

                friend bool operator !=(const _ProjectionRead_T2Wait& o1, const _ProjectionRead_T2Wait& o2) {
                    return o1.T2_state != (o2.T2_state);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_T2Wait& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_T2Wait {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_T2Wait& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_T2Wait& obj1, const _ProjectionRead__tr_T2Wait& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;

                _ProjectionRead__tr_T2Wait(const T2state& T2_state) {
                    this->T2_state = T2_state;
                }

                friend bool operator ==(const _ProjectionRead__tr_T2Wait& o1, const _ProjectionRead__tr_T2Wait& o2) {
                    return o1.T2_state == (o2.T2_state);
                }

                friend bool operator !=(const _ProjectionRead__tr_T2Wait& o1, const _ProjectionRead__tr_T2Wait& o2) {
                    return o1.T2_state != (o2.T2_state);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_T2Wait& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_T2Wait {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_T2Wait& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_T2Wait& obj1, const _ProjectionWrite_T2Wait& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;
                BInteger T2_timer;

                _ProjectionWrite_T2Wait(const T2state& T2_state, const BInteger& T2_timer) {
                    this->T2_state = T2_state;
                    this->T2_timer = T2_timer;
                }

                friend bool operator ==(const _ProjectionWrite_T2Wait& o1, const _ProjectionWrite_T2Wait& o2) {
                    return o1.T2_state == (o2.T2_state) && o1.T2_timer == (o2.T2_timer);
                }

                friend bool operator !=(const _ProjectionWrite_T2Wait& o1, const _ProjectionWrite_T2Wait& o2) {
                    return o1.T2_state != (o2.T2_state) || o1.T2_timer != (o2.T2_timer);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_T2Wait& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;
                    strm << ", ";
                    strm << "T2_timer: " << e.T2_timer;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    result = 31 * result + (T2_timer.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_T3Initiate {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_T3Initiate& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_T3Initiate& obj1, const _ProjectionRead_T3Initiate& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean T3_evaluated;
                T3state T3_state;
                BBoolean T3_enabled;

                _ProjectionRead_T3Initiate(const BBoolean& T3_evaluated, const T3state& T3_state, const BBoolean& T3_enabled) {
                    this->T3_evaluated = T3_evaluated;
                    this->T3_state = T3_state;
                    this->T3_enabled = T3_enabled;
                }

                friend bool operator ==(const _ProjectionRead_T3Initiate& o1, const _ProjectionRead_T3Initiate& o2) {
                    return o1.T3_evaluated == (o2.T3_evaluated) && o1.T3_state == (o2.T3_state) && o1.T3_enabled == (o2.T3_enabled);
                }

                friend bool operator !=(const _ProjectionRead_T3Initiate& o1, const _ProjectionRead_T3Initiate& o2) {
                    return o1.T3_evaluated != (o2.T3_evaluated) || o1.T3_state != (o2.T3_state) || o1.T3_enabled != (o2.T3_enabled);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_T3Initiate& e) {
                    strm << "{";
                    strm << "T3_evaluated: " << e.T3_evaluated;
                    strm << ", ";
                    strm << "T3_state: " << e.T3_state;
                    strm << ", ";
                    strm << "T3_enabled: " << e.T3_enabled;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_evaluated.hashCode() << 1);
                    result = 31 * result + (T3_state.hashCode() << 1);
                    result = 31 * result + (T3_enabled.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_T3Initiate {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_T3Initiate& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_T3Initiate& obj1, const _ProjectionRead__tr_T3Initiate& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean T3_evaluated;
                T3state T3_state;
                BBoolean T3_enabled;

                _ProjectionRead__tr_T3Initiate(const BBoolean& T3_evaluated, const T3state& T3_state, const BBoolean& T3_enabled) {
                    this->T3_evaluated = T3_evaluated;
                    this->T3_state = T3_state;
                    this->T3_enabled = T3_enabled;
                }

                friend bool operator ==(const _ProjectionRead__tr_T3Initiate& o1, const _ProjectionRead__tr_T3Initiate& o2) {
                    return o1.T3_evaluated == (o2.T3_evaluated) && o1.T3_state == (o2.T3_state) && o1.T3_enabled == (o2.T3_enabled);
                }

                friend bool operator !=(const _ProjectionRead__tr_T3Initiate& o1, const _ProjectionRead__tr_T3Initiate& o2) {
                    return o1.T3_evaluated != (o2.T3_evaluated) || o1.T3_state != (o2.T3_state) || o1.T3_enabled != (o2.T3_enabled);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_T3Initiate& e) {
                    strm << "{";
                    strm << "T3_evaluated: " << e.T3_evaluated;
                    strm << ", "; 
                    strm << "T3_state: " << e.T3_state;
                    strm << ", "; 
                    strm << "T3_enabled: " << e.T3_enabled;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_evaluated.hashCode() << 1);
                    result = 31 * result + (T3_state.hashCode() << 1);
                    result = 31 * result + (T3_enabled.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_T3Initiate {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_T3Initiate& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_T3Initiate& obj1, const _ProjectionWrite_T3Initiate& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T3state T3_state;
                BBoolean T3_enabled;

                _ProjectionWrite_T3Initiate(const T3state& T3_state, const BBoolean& T3_enabled) {
                    this->T3_state = T3_state;
                    this->T3_enabled = T3_enabled;
                }

                friend bool operator ==(const _ProjectionWrite_T3Initiate& o1, const _ProjectionWrite_T3Initiate& o2) {
                    return o1.T3_state == (o2.T3_state) && o1.T3_enabled == (o2.T3_enabled);
                }

                friend bool operator !=(const _ProjectionWrite_T3Initiate& o1, const _ProjectionWrite_T3Initiate& o2) {
                    return o1.T3_state != (o2.T3_state) || o1.T3_enabled != (o2.T3_enabled);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_T3Initiate& e) {
                    strm << "{";
                    strm << "T3_state: " << e.T3_state;
                    strm << ", ";
                    strm << "T3_enabled: " << e.T3_enabled;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_state.hashCode() << 1);
                    result = 31 * result + (T3_enabled.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_T3Evaluate {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_T3Evaluate& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_T3Evaluate& obj1, const _ProjectionRead_T3Evaluate& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean T3_evaluated;
                T3state T3_state;
                BBoolean T3_enabled;

                _ProjectionRead_T3Evaluate(const BBoolean& T3_evaluated, const T3state& T3_state, const BBoolean& T3_enabled) {
                    this->T3_evaluated = T3_evaluated;
                    this->T3_state = T3_state;
                    this->T3_enabled = T3_enabled;
                }

                friend bool operator ==(const _ProjectionRead_T3Evaluate& o1, const _ProjectionRead_T3Evaluate& o2) {
                    return o1.T3_evaluated == (o2.T3_evaluated) && o1.T3_state == (o2.T3_state) && o1.T3_enabled == (o2.T3_enabled);
                }

                friend bool operator !=(const _ProjectionRead_T3Evaluate& o1, const _ProjectionRead_T3Evaluate& o2) {
                    return o1.T3_evaluated != (o2.T3_evaluated) || o1.T3_state != (o2.T3_state) || o1.T3_enabled != (o2.T3_enabled);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_T3Evaluate& e) {
                    strm << "{";
                    strm << "T3_evaluated: " << e.T3_evaluated;
                    strm << ", ";
                    strm << "T3_state: " << e.T3_state;
                    strm << ", ";
                    strm << "T3_enabled: " << e.T3_enabled;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_evaluated.hashCode() << 1);
                    result = 31 * result + (T3_state.hashCode() << 1);
                    result = 31 * result + (T3_enabled.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_T3Evaluate {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_T3Evaluate& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_T3Evaluate& obj1, const _ProjectionRead__tr_T3Evaluate& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean T3_evaluated;
                T3state T3_state;
                BBoolean T3_enabled;

                _ProjectionRead__tr_T3Evaluate(const BBoolean& T3_evaluated, const T3state& T3_state, const BBoolean& T3_enabled) {
                    this->T3_evaluated = T3_evaluated;
                    this->T3_state = T3_state;
                    this->T3_enabled = T3_enabled;
                }

                friend bool operator ==(const _ProjectionRead__tr_T3Evaluate& o1, const _ProjectionRead__tr_T3Evaluate& o2) {
                    return o1.T3_evaluated == (o2.T3_evaluated) && o1.T3_state == (o2.T3_state) && o1.T3_enabled == (o2.T3_enabled);
                }

                friend bool operator !=(const _ProjectionRead__tr_T3Evaluate& o1, const _ProjectionRead__tr_T3Evaluate& o2) {
                    return o1.T3_evaluated != (o2.T3_evaluated) || o1.T3_state != (o2.T3_state) || o1.T3_enabled != (o2.T3_enabled);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_T3Evaluate& e) {
                    strm << "{";
                    strm << "T3_evaluated: " << e.T3_evaluated;
                    strm << ", "; 
                    strm << "T3_state: " << e.T3_state;
                    strm << ", "; 
                    strm << "T3_enabled: " << e.T3_enabled;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_evaluated.hashCode() << 1);
                    result = 31 * result + (T3_state.hashCode() << 1);
                    result = 31 * result + (T3_enabled.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_T3Evaluate {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_T3Evaluate& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_T3Evaluate& obj1, const _ProjectionWrite_T3Evaluate& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T3state T3_state;

                _ProjectionWrite_T3Evaluate(const T3state& T3_state) {
                    this->T3_state = T3_state;
                }

                friend bool operator ==(const _ProjectionWrite_T3Evaluate& o1, const _ProjectionWrite_T3Evaluate& o2) {
                    return o1.T3_state == (o2.T3_state);
                }

                friend bool operator !=(const _ProjectionWrite_T3Evaluate& o1, const _ProjectionWrite_T3Evaluate& o2) {
                    return o1.T3_state != (o2.T3_state);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_T3Evaluate& e) {
                    strm << "{";
                    strm << "T3_state: " << e.T3_state;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_state.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_T3writebus {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_T3writebus& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_T3writebus& obj1, const _ProjectionRead_T3writebus& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T3state T3_state;
                BRelation<BInteger, BInteger > BUSwrite;

                _ProjectionRead_T3writebus(const T3state& T3_state, const BRelation<BInteger, BInteger >& BUSwrite) {
                    this->T3_state = T3_state;
                    this->BUSwrite = BUSwrite;
                }

                friend bool operator ==(const _ProjectionRead_T3writebus& o1, const _ProjectionRead_T3writebus& o2) {
                    return o1.T3_state == (o2.T3_state) && o1.BUSwrite == (o2.BUSwrite);
                }

                friend bool operator !=(const _ProjectionRead_T3writebus& o1, const _ProjectionRead_T3writebus& o2) {
                    return o1.T3_state != (o2.T3_state) || o1.BUSwrite != (o2.BUSwrite);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_T3writebus& e) {
                    strm << "{";
                    strm << "T3_state: " << e.T3_state;
                    strm << ", ";
                    strm << "BUSwrite: " << e.BUSwrite;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_state.hashCode() << 1);
                    result = 31 * result + (BUSwrite.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_T3writebus {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_T3writebus& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_T3writebus& obj1, const _ProjectionRead__tr_T3writebus& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T3state T3_state;

                _ProjectionRead__tr_T3writebus(const T3state& T3_state) {
                    this->T3_state = T3_state;
                }

                friend bool operator ==(const _ProjectionRead__tr_T3writebus& o1, const _ProjectionRead__tr_T3writebus& o2) {
                    return o1.T3_state == (o2.T3_state);
                }

                friend bool operator !=(const _ProjectionRead__tr_T3writebus& o1, const _ProjectionRead__tr_T3writebus& o2) {
                    return o1.T3_state != (o2.T3_state);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_T3writebus& e) {
                    strm << "{";
                    strm << "T3_state: " << e.T3_state;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_state.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_T3writebus {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_T3writebus& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_T3writebus& obj1, const _ProjectionWrite_T3writebus& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T3state T3_state;
                BRelation<BInteger, BInteger > BUSwrite;

                _ProjectionWrite_T3writebus(const T3state& T3_state, const BRelation<BInteger, BInteger >& BUSwrite) {
                    this->T3_state = T3_state;
                    this->BUSwrite = BUSwrite;
                }

                friend bool operator ==(const _ProjectionWrite_T3writebus& o1, const _ProjectionWrite_T3writebus& o2) {
                    return o1.T3_state == (o2.T3_state) && o1.BUSwrite == (o2.BUSwrite);
                }

                friend bool operator !=(const _ProjectionWrite_T3writebus& o1, const _ProjectionWrite_T3writebus& o2) {
                    return o1.T3_state != (o2.T3_state) || o1.BUSwrite != (o2.BUSwrite);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_T3writebus& e) {
                    strm << "{";
                    strm << "T3_state: " << e.T3_state;
                    strm << ", ";
                    strm << "BUSwrite: " << e.BUSwrite;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_state.hashCode() << 1);
                    result = 31 * result + (BUSwrite.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_T3Read {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_T3Read& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_T3Read& obj1, const _ProjectionRead_T3Read& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger BUSpriority;
                T3state T3_state;
                BInteger BUSvalue;

                _ProjectionRead_T3Read(const BInteger& BUSpriority, const T3state& T3_state, const BInteger& BUSvalue) {
                    this->BUSpriority = BUSpriority;
                    this->T3_state = T3_state;
                    this->BUSvalue = BUSvalue;
                }

                friend bool operator ==(const _ProjectionRead_T3Read& o1, const _ProjectionRead_T3Read& o2) {
                    return o1.BUSpriority == (o2.BUSpriority) && o1.T3_state == (o2.T3_state) && o1.BUSvalue == (o2.BUSvalue);
                }

                friend bool operator !=(const _ProjectionRead_T3Read& o1, const _ProjectionRead_T3Read& o2) {
                    return o1.BUSpriority != (o2.BUSpriority) || o1.T3_state != (o2.T3_state) || o1.BUSvalue != (o2.BUSvalue);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_T3Read& e) {
                    strm << "{";
                    strm << "BUSpriority: " << e.BUSpriority;
                    strm << ", ";
                    strm << "T3_state: " << e.T3_state;
                    strm << ", ";
                    strm << "BUSvalue: " << e.BUSvalue;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (BUSpriority.hashCode() << 1);
                    result = 31 * result + (T3_state.hashCode() << 1);
                    result = 31 * result + (BUSvalue.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_T3Read {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_T3Read& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_T3Read& obj1, const _ProjectionRead__tr_T3Read& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger BUSpriority;
                T3state T3_state;
                BInteger BUSvalue;

                _ProjectionRead__tr_T3Read(const BInteger& BUSpriority, const T3state& T3_state, const BInteger& BUSvalue) {
                    this->BUSpriority = BUSpriority;
                    this->T3_state = T3_state;
                    this->BUSvalue = BUSvalue;
                }

                friend bool operator ==(const _ProjectionRead__tr_T3Read& o1, const _ProjectionRead__tr_T3Read& o2) {
                    return o1.BUSpriority == (o2.BUSpriority) && o1.T3_state == (o2.T3_state) && o1.BUSvalue == (o2.BUSvalue);
                }

                friend bool operator !=(const _ProjectionRead__tr_T3Read& o1, const _ProjectionRead__tr_T3Read& o2) {
                    return o1.BUSpriority != (o2.BUSpriority) || o1.T3_state != (o2.T3_state) || o1.BUSvalue != (o2.BUSvalue);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_T3Read& e) {
                    strm << "{";
                    strm << "BUSpriority: " << e.BUSpriority;
                    strm << ", "; 
                    strm << "T3_state: " << e.T3_state;
                    strm << ", "; 
                    strm << "BUSvalue: " << e.BUSvalue;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (BUSpriority.hashCode() << 1);
                    result = 31 * result + (T3_state.hashCode() << 1);
                    result = 31 * result + (BUSvalue.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_T3Read {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_T3Read& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_T3Read& obj1, const _ProjectionWrite_T3Read& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger T3_readpriority;
                BInteger T3_readvalue;
                T3state T3_state;

                _ProjectionWrite_T3Read(const BInteger& T3_readpriority, const BInteger& T3_readvalue, const T3state& T3_state) {
                    this->T3_readpriority = T3_readpriority;
                    this->T3_readvalue = T3_readvalue;
                    this->T3_state = T3_state;
                }

                friend bool operator ==(const _ProjectionWrite_T3Read& o1, const _ProjectionWrite_T3Read& o2) {
                    return o1.T3_readpriority == (o2.T3_readpriority) && o1.T3_readvalue == (o2.T3_readvalue) && o1.T3_state == (o2.T3_state);
                }

                friend bool operator !=(const _ProjectionWrite_T3Read& o1, const _ProjectionWrite_T3Read& o2) {
                    return o1.T3_readpriority != (o2.T3_readpriority) || o1.T3_readvalue != (o2.T3_readvalue) || o1.T3_state != (o2.T3_state);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_T3Read& e) {
                    strm << "{";
                    strm << "T3_readpriority: " << e.T3_readpriority;
                    strm << ", ";
                    strm << "T3_readvalue: " << e.T3_readvalue;
                    strm << ", ";
                    strm << "T3_state: " << e.T3_state;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_readpriority.hashCode() << 1);
                    result = 31 * result + (T3_readvalue.hashCode() << 1);
                    result = 31 * result + (T3_state.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_T3Poll {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_T3Poll& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_T3Poll& obj1, const _ProjectionRead_T3Poll& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger T3_readpriority;
                T3state T3_state;

                _ProjectionRead_T3Poll(const BInteger& T3_readpriority, const T3state& T3_state) {
                    this->T3_readpriority = T3_readpriority;
                    this->T3_state = T3_state;
                }

                friend bool operator ==(const _ProjectionRead_T3Poll& o1, const _ProjectionRead_T3Poll& o2) {
                    return o1.T3_readpriority == (o2.T3_readpriority) && o1.T3_state == (o2.T3_state);
                }

                friend bool operator !=(const _ProjectionRead_T3Poll& o1, const _ProjectionRead_T3Poll& o2) {
                    return o1.T3_readpriority != (o2.T3_readpriority) || o1.T3_state != (o2.T3_state);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_T3Poll& e) {
                    strm << "{";
                    strm << "T3_readpriority: " << e.T3_readpriority;
                    strm << ", ";
                    strm << "T3_state: " << e.T3_state;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_readpriority.hashCode() << 1);
                    result = 31 * result + (T3_state.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_T3Poll {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_T3Poll& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_T3Poll& obj1, const _ProjectionRead__tr_T3Poll& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger T3_readpriority;
                T3state T3_state;

                _ProjectionRead__tr_T3Poll(const BInteger& T3_readpriority, const T3state& T3_state) {
                    this->T3_readpriority = T3_readpriority;
                    this->T3_state = T3_state;
                }

                friend bool operator ==(const _ProjectionRead__tr_T3Poll& o1, const _ProjectionRead__tr_T3Poll& o2) {
                    return o1.T3_readpriority == (o2.T3_readpriority) && o1.T3_state == (o2.T3_state);
                }

                friend bool operator !=(const _ProjectionRead__tr_T3Poll& o1, const _ProjectionRead__tr_T3Poll& o2) {
                    return o1.T3_readpriority != (o2.T3_readpriority) || o1.T3_state != (o2.T3_state);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_T3Poll& e) {
                    strm << "{";
                    strm << "T3_readpriority: " << e.T3_readpriority;
                    strm << ", "; 
                    strm << "T3_state: " << e.T3_state;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_readpriority.hashCode() << 1);
                    result = 31 * result + (T3_state.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_T3Poll {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_T3Poll& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_T3Poll& obj1, const _ProjectionWrite_T3Poll& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T3state T3_state;

                _ProjectionWrite_T3Poll(const T3state& T3_state) {
                    this->T3_state = T3_state;
                }

                friend bool operator ==(const _ProjectionWrite_T3Poll& o1, const _ProjectionWrite_T3Poll& o2) {
                    return o1.T3_state == (o2.T3_state);
                }

                friend bool operator !=(const _ProjectionWrite_T3Poll& o1, const _ProjectionWrite_T3Poll& o2) {
                    return o1.T3_state != (o2.T3_state);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_T3Poll& e) {
                    strm << "{";
                    strm << "T3_state: " << e.T3_state;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_state.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_T3ReleaseBus {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_T3ReleaseBus& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_T3ReleaseBus& obj1, const _ProjectionRead_T3ReleaseBus& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger T3_readpriority;
                T3state T3_state;
                BRelation<BInteger, BInteger > BUSwrite;

                _ProjectionRead_T3ReleaseBus(const BInteger& T3_readpriority, const T3state& T3_state, const BRelation<BInteger, BInteger >& BUSwrite) {
                    this->T3_readpriority = T3_readpriority;
                    this->T3_state = T3_state;
                    this->BUSwrite = BUSwrite;
                }

                friend bool operator ==(const _ProjectionRead_T3ReleaseBus& o1, const _ProjectionRead_T3ReleaseBus& o2) {
                    return o1.T3_readpriority == (o2.T3_readpriority) && o1.T3_state == (o2.T3_state) && o1.BUSwrite == (o2.BUSwrite);
                }

                friend bool operator !=(const _ProjectionRead_T3ReleaseBus& o1, const _ProjectionRead_T3ReleaseBus& o2) {
                    return o1.T3_readpriority != (o2.T3_readpriority) || o1.T3_state != (o2.T3_state) || o1.BUSwrite != (o2.BUSwrite);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_T3ReleaseBus& e) {
                    strm << "{";
                    strm << "T3_readpriority: " << e.T3_readpriority;
                    strm << ", ";
                    strm << "T3_state: " << e.T3_state;
                    strm << ", ";
                    strm << "BUSwrite: " << e.BUSwrite;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_readpriority.hashCode() << 1);
                    result = 31 * result + (T3_state.hashCode() << 1);
                    result = 31 * result + (BUSwrite.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_T3ReleaseBus {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_T3ReleaseBus& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_T3ReleaseBus& obj1, const _ProjectionRead__tr_T3ReleaseBus& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger T3_readpriority;
                T3state T3_state;

                _ProjectionRead__tr_T3ReleaseBus(const BInteger& T3_readpriority, const T3state& T3_state) {
                    this->T3_readpriority = T3_readpriority;
                    this->T3_state = T3_state;
                }

                friend bool operator ==(const _ProjectionRead__tr_T3ReleaseBus& o1, const _ProjectionRead__tr_T3ReleaseBus& o2) {
                    return o1.T3_readpriority == (o2.T3_readpriority) && o1.T3_state == (o2.T3_state);
                }

                friend bool operator !=(const _ProjectionRead__tr_T3ReleaseBus& o1, const _ProjectionRead__tr_T3ReleaseBus& o2) {
                    return o1.T3_readpriority != (o2.T3_readpriority) || o1.T3_state != (o2.T3_state);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_T3ReleaseBus& e) {
                    strm << "{";
                    strm << "T3_readpriority: " << e.T3_readpriority;
                    strm << ", "; 
                    strm << "T3_state: " << e.T3_state;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_readpriority.hashCode() << 1);
                    result = 31 * result + (T3_state.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_T3ReleaseBus {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_T3ReleaseBus& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_T3ReleaseBus& obj1, const _ProjectionWrite_T3ReleaseBus& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T3state T3_state;
                BRelation<BInteger, BInteger > BUSwrite;

                _ProjectionWrite_T3ReleaseBus(const T3state& T3_state, const BRelation<BInteger, BInteger >& BUSwrite) {
                    this->T3_state = T3_state;
                    this->BUSwrite = BUSwrite;
                }

                friend bool operator ==(const _ProjectionWrite_T3ReleaseBus& o1, const _ProjectionWrite_T3ReleaseBus& o2) {
                    return o1.T3_state == (o2.T3_state) && o1.BUSwrite == (o2.BUSwrite);
                }

                friend bool operator !=(const _ProjectionWrite_T3ReleaseBus& o1, const _ProjectionWrite_T3ReleaseBus& o2) {
                    return o1.T3_state != (o2.T3_state) || o1.BUSwrite != (o2.BUSwrite);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_T3ReleaseBus& e) {
                    strm << "{";
                    strm << "T3_state: " << e.T3_state;
                    strm << ", ";
                    strm << "BUSwrite: " << e.BUSwrite;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_state.hashCode() << 1);
                    result = 31 * result + (BUSwrite.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_T3Wait {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_T3Wait& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_T3Wait& obj1, const _ProjectionRead_T3Wait& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T3state T3_state;

                _ProjectionRead_T3Wait(const T3state& T3_state) {
                    this->T3_state = T3_state;
                }

                friend bool operator ==(const _ProjectionRead_T3Wait& o1, const _ProjectionRead_T3Wait& o2) {
                    return o1.T3_state == (o2.T3_state);
                }

                friend bool operator !=(const _ProjectionRead_T3Wait& o1, const _ProjectionRead_T3Wait& o2) {
                    return o1.T3_state != (o2.T3_state);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_T3Wait& e) {
                    strm << "{";
                    strm << "T3_state: " << e.T3_state;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_state.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_T3Wait {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_T3Wait& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_T3Wait& obj1, const _ProjectionRead__tr_T3Wait& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T3state T3_state;

                _ProjectionRead__tr_T3Wait(const T3state& T3_state) {
                    this->T3_state = T3_state;
                }

                friend bool operator ==(const _ProjectionRead__tr_T3Wait& o1, const _ProjectionRead__tr_T3Wait& o2) {
                    return o1.T3_state == (o2.T3_state);
                }

                friend bool operator !=(const _ProjectionRead__tr_T3Wait& o1, const _ProjectionRead__tr_T3Wait& o2) {
                    return o1.T3_state != (o2.T3_state);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_T3Wait& e) {
                    strm << "{";
                    strm << "T3_state: " << e.T3_state;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_state.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_T3Wait {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_T3Wait& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_T3Wait& obj1, const _ProjectionWrite_T3Wait& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean T3_evaluated;
                T3state T3_state;

                _ProjectionWrite_T3Wait(const BBoolean& T3_evaluated, const T3state& T3_state) {
                    this->T3_evaluated = T3_evaluated;
                    this->T3_state = T3_state;
                }

                friend bool operator ==(const _ProjectionWrite_T3Wait& o1, const _ProjectionWrite_T3Wait& o2) {
                    return o1.T3_evaluated == (o2.T3_evaluated) && o1.T3_state == (o2.T3_state);
                }

                friend bool operator !=(const _ProjectionWrite_T3Wait& o1, const _ProjectionWrite_T3Wait& o2) {
                    return o1.T3_evaluated != (o2.T3_evaluated) || o1.T3_state != (o2.T3_state);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_T3Wait& e) {
                    strm << "{";
                    strm << "T3_evaluated: " << e.T3_evaluated;
                    strm << ", ";
                    strm << "T3_state: " << e.T3_state;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_evaluated.hashCode() << 1);
                    result = 31 * result + (T3_state.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_T3ReEnableWait {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_T3ReEnableWait& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_T3ReEnableWait& obj1, const _ProjectionRead_T3ReEnableWait& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T3state T3_state;

                _ProjectionRead_T3ReEnableWait(const T3state& T3_state) {
                    this->T3_state = T3_state;
                }

                friend bool operator ==(const _ProjectionRead_T3ReEnableWait& o1, const _ProjectionRead_T3ReEnableWait& o2) {
                    return o1.T3_state == (o2.T3_state);
                }

                friend bool operator !=(const _ProjectionRead_T3ReEnableWait& o1, const _ProjectionRead_T3ReEnableWait& o2) {
                    return o1.T3_state != (o2.T3_state);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_T3ReEnableWait& e) {
                    strm << "{";
                    strm << "T3_state: " << e.T3_state;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_state.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_T3ReEnableWait {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_T3ReEnableWait& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_T3ReEnableWait& obj1, const _ProjectionRead__tr_T3ReEnableWait& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T3state T3_state;

                _ProjectionRead__tr_T3ReEnableWait(const T3state& T3_state) {
                    this->T3_state = T3_state;
                }

                friend bool operator ==(const _ProjectionRead__tr_T3ReEnableWait& o1, const _ProjectionRead__tr_T3ReEnableWait& o2) {
                    return o1.T3_state == (o2.T3_state);
                }

                friend bool operator !=(const _ProjectionRead__tr_T3ReEnableWait& o1, const _ProjectionRead__tr_T3ReEnableWait& o2) {
                    return o1.T3_state != (o2.T3_state);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_T3ReEnableWait& e) {
                    strm << "{";
                    strm << "T3_state: " << e.T3_state;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_state.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_T3ReEnableWait {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_T3ReEnableWait& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_T3ReEnableWait& obj1, const _ProjectionWrite_T3ReEnableWait& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean T3_evaluated;
                T3state T3_state;
                BBoolean T3_enabled;

                _ProjectionWrite_T3ReEnableWait(const BBoolean& T3_evaluated, const T3state& T3_state, const BBoolean& T3_enabled) {
                    this->T3_evaluated = T3_evaluated;
                    this->T3_state = T3_state;
                    this->T3_enabled = T3_enabled;
                }

                friend bool operator ==(const _ProjectionWrite_T3ReEnableWait& o1, const _ProjectionWrite_T3ReEnableWait& o2) {
                    return o1.T3_evaluated == (o2.T3_evaluated) && o1.T3_state == (o2.T3_state) && o1.T3_enabled == (o2.T3_enabled);
                }

                friend bool operator !=(const _ProjectionWrite_T3ReEnableWait& o1, const _ProjectionWrite_T3ReEnableWait& o2) {
                    return o1.T3_evaluated != (o2.T3_evaluated) || o1.T3_state != (o2.T3_state) || o1.T3_enabled != (o2.T3_enabled);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_T3ReEnableWait& e) {
                    strm << "{";
                    strm << "T3_evaluated: " << e.T3_evaluated;
                    strm << ", ";
                    strm << "T3_state: " << e.T3_state;
                    strm << ", ";
                    strm << "T3_enabled: " << e.T3_enabled;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_evaluated.hashCode() << 1);
                    result = 31 * result + (T3_state.hashCode() << 1);
                    result = 31 * result + (T3_enabled.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_Update {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_Update& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_Update& obj1, const _ProjectionRead_Update& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean T3_evaluated;
                BInteger T1_timer;
                BBoolean T3_enabled;
                BRelation<BInteger, BInteger > BUSwrite;
                BInteger T2_timer;

                _ProjectionRead_Update(const BBoolean& T3_evaluated, const BInteger& T1_timer, const BBoolean& T3_enabled, const BRelation<BInteger, BInteger >& BUSwrite, const BInteger& T2_timer) {
                    this->T3_evaluated = T3_evaluated;
                    this->T1_timer = T1_timer;
                    this->T3_enabled = T3_enabled;
                    this->BUSwrite = BUSwrite;
                    this->T2_timer = T2_timer;
                }

                friend bool operator ==(const _ProjectionRead_Update& o1, const _ProjectionRead_Update& o2) {
                    return o1.T3_evaluated == (o2.T3_evaluated) && o1.T1_timer == (o2.T1_timer) && o1.T3_enabled == (o2.T3_enabled) && o1.BUSwrite == (o2.BUSwrite) && o1.T2_timer == (o2.T2_timer);
                }

                friend bool operator !=(const _ProjectionRead_Update& o1, const _ProjectionRead_Update& o2) {
                    return o1.T3_evaluated != (o2.T3_evaluated) || o1.T1_timer != (o2.T1_timer) || o1.T3_enabled != (o2.T3_enabled) || o1.BUSwrite != (o2.BUSwrite) || o1.T2_timer != (o2.T2_timer);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_Update& e) {
                    strm << "{";
                    strm << "T3_evaluated: " << e.T3_evaluated;
                    strm << ", ";
                    strm << "T1_timer: " << e.T1_timer;
                    strm << ", ";
                    strm << "T3_enabled: " << e.T3_enabled;
                    strm << ", ";
                    strm << "BUSwrite: " << e.BUSwrite;
                    strm << ", ";
                    strm << "T2_timer: " << e.T2_timer;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_evaluated.hashCode() << 1);
                    result = 31 * result + (T1_timer.hashCode() << 1);
                    result = 31 * result + (T3_enabled.hashCode() << 1);
                    result = 31 * result + (BUSwrite.hashCode() << 1);
                    result = 31 * result + (T2_timer.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_Update {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_Update& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_Update& obj1, const _ProjectionRead__tr_Update& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean T3_evaluated;
                BInteger T1_timer;
                BBoolean T3_enabled;
                BRelation<BInteger, BInteger > BUSwrite;
                BInteger T2_timer;

                _ProjectionRead__tr_Update(const BBoolean& T3_evaluated, const BInteger& T1_timer, const BBoolean& T3_enabled, const BRelation<BInteger, BInteger >& BUSwrite, const BInteger& T2_timer) {
                    this->T3_evaluated = T3_evaluated;
                    this->T1_timer = T1_timer;
                    this->T3_enabled = T3_enabled;
                    this->BUSwrite = BUSwrite;
                    this->T2_timer = T2_timer;
                }

                friend bool operator ==(const _ProjectionRead__tr_Update& o1, const _ProjectionRead__tr_Update& o2) {
                    return o1.T3_evaluated == (o2.T3_evaluated) && o1.T1_timer == (o2.T1_timer) && o1.T3_enabled == (o2.T3_enabled) && o1.BUSwrite == (o2.BUSwrite) && o1.T2_timer == (o2.T2_timer);
                }

                friend bool operator !=(const _ProjectionRead__tr_Update& o1, const _ProjectionRead__tr_Update& o2) {
                    return o1.T3_evaluated != (o2.T3_evaluated) || o1.T1_timer != (o2.T1_timer) || o1.T3_enabled != (o2.T3_enabled) || o1.BUSwrite != (o2.BUSwrite) || o1.T2_timer != (o2.T2_timer);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_Update& e) {
                    strm << "{";
                    strm << "T3_evaluated: " << e.T3_evaluated;
                    strm << ", "; 
                    strm << "T1_timer: " << e.T1_timer;
                    strm << ", "; 
                    strm << "T3_enabled: " << e.T3_enabled;
                    strm << ", "; 
                    strm << "BUSwrite: " << e.BUSwrite;
                    strm << ", "; 
                    strm << "T2_timer: " << e.T2_timer;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_evaluated.hashCode() << 1);
                    result = 31 * result + (T1_timer.hashCode() << 1);
                    result = 31 * result + (T3_enabled.hashCode() << 1);
                    result = 31 * result + (BUSwrite.hashCode() << 1);
                    result = 31 * result + (T2_timer.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_Update {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_Update& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_Update& obj1, const _ProjectionWrite_Update& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean T3_evaluated;
                BInteger BUSpriority;
                BInteger T1_timer;
                BInteger T2_timer;
                BInteger BUSvalue;

                _ProjectionWrite_Update(const BBoolean& T3_evaluated, const BInteger& BUSpriority, const BInteger& T1_timer, const BInteger& T2_timer, const BInteger& BUSvalue) {
                    this->T3_evaluated = T3_evaluated;
                    this->BUSpriority = BUSpriority;
                    this->T1_timer = T1_timer;
                    this->T2_timer = T2_timer;
                    this->BUSvalue = BUSvalue;
                }

                friend bool operator ==(const _ProjectionWrite_Update& o1, const _ProjectionWrite_Update& o2) {
                    return o1.T3_evaluated == (o2.T3_evaluated) && o1.BUSpriority == (o2.BUSpriority) && o1.T1_timer == (o2.T1_timer) && o1.T2_timer == (o2.T2_timer) && o1.BUSvalue == (o2.BUSvalue);
                }

                friend bool operator !=(const _ProjectionWrite_Update& o1, const _ProjectionWrite_Update& o2) {
                    return o1.T3_evaluated != (o2.T3_evaluated) || o1.BUSpriority != (o2.BUSpriority) || o1.T1_timer != (o2.T1_timer) || o1.T2_timer != (o2.T2_timer) || o1.BUSvalue != (o2.BUSvalue);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_Update& e) {
                    strm << "{";
                    strm << "T3_evaluated: " << e.T3_evaluated;
                    strm << ", ";
                    strm << "BUSpriority: " << e.BUSpriority;
                    strm << ", ";
                    strm << "T1_timer: " << e.T1_timer;
                    strm << ", ";
                    strm << "T2_timer: " << e.T2_timer;
                    strm << ", ";
                    strm << "BUSvalue: " << e.BUSvalue;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_evaluated.hashCode() << 1);
                    result = 31 * result + (BUSpriority.hashCode() << 1);
                    result = 31 * result + (T1_timer.hashCode() << 1);
                    result = 31 * result + (T2_timer.hashCode() << 1);
                    result = 31 * result + (BUSvalue.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_1 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_1& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_1& obj1, const _ProjectionRead__check_inv_1& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger T2v;

                _ProjectionRead__check_inv_1(const BInteger& T2v) {
                    this->T2v = T2v;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.T2v == (o2.T2v);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.T2v != (o2.T2v);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_1& e) {
                    strm << "{";
                    strm << "T2v: " << e.T2v;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2v.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_2 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_2& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_2& obj1, const _ProjectionRead__check_inv_2& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean T3_evaluated;

                _ProjectionRead__check_inv_2(const BBoolean& T3_evaluated) {
                    this->T3_evaluated = T3_evaluated;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_2& o1, const _ProjectionRead__check_inv_2& o2) {
                    return o1.T3_evaluated == (o2.T3_evaluated);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_2& o1, const _ProjectionRead__check_inv_2& o2) {
                    return o1.T3_evaluated != (o2.T3_evaluated);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_2& e) {
                    strm << "{";
                    strm << "T3_evaluated: " << e.T3_evaluated;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_evaluated.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_3 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_3& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_3& obj1, const _ProjectionRead__check_inv_3& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean T3_enabled;

                _ProjectionRead__check_inv_3(const BBoolean& T3_enabled) {
                    this->T3_enabled = T3_enabled;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_3& o1, const _ProjectionRead__check_inv_3& o2) {
                    return o1.T3_enabled == (o2.T3_enabled);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_3& o1, const _ProjectionRead__check_inv_3& o2) {
                    return o1.T3_enabled != (o2.T3_enabled);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_3& e) {
                    strm << "{";
                    strm << "T3_enabled: " << e.T3_enabled;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_enabled.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_4 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_4& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_4& obj1, const _ProjectionRead__check_inv_4& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T1state T1_state;

                _ProjectionRead__check_inv_4(const T1state& T1_state) {
                    this->T1_state = T1_state;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_4& o1, const _ProjectionRead__check_inv_4& o2) {
                    return o1.T1_state == (o2.T1_state);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_4& o1, const _ProjectionRead__check_inv_4& o2) {
                    return o1.T1_state != (o2.T1_state);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_4& e) {
                    strm << "{";
                    strm << "T1_state: " << e.T1_state;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T1_state.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_5 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_5& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_5& obj1, const _ProjectionRead__check_inv_5& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2state T2_state;

                _ProjectionRead__check_inv_5(const T2state& T2_state) {
                    this->T2_state = T2_state;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_5& o1, const _ProjectionRead__check_inv_5& o2) {
                    return o1.T2_state == (o2.T2_state);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_5& o1, const _ProjectionRead__check_inv_5& o2) {
                    return o1.T2_state != (o2.T2_state);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_5& e) {
                    strm << "{";
                    strm << "T2_state: " << e.T2_state;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_state.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_6 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_6& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_6& obj1, const _ProjectionRead__check_inv_6& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T3state T3_state;

                _ProjectionRead__check_inv_6(const T3state& T3_state) {
                    this->T3_state = T3_state;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_6& o1, const _ProjectionRead__check_inv_6& o2) {
                    return o1.T3_state == (o2.T3_state);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_6& o1, const _ProjectionRead__check_inv_6& o2) {
                    return o1.T3_state != (o2.T3_state);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_6& e) {
                    strm << "{";
                    strm << "T3_state: " << e.T3_state;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_state.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_7 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_7& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_7& obj1, const _ProjectionRead__check_inv_7& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger T1_writevalue;

                _ProjectionRead__check_inv_7(const BInteger& T1_writevalue) {
                    this->T1_writevalue = T1_writevalue;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_7& o1, const _ProjectionRead__check_inv_7& o2) {
                    return o1.T1_writevalue == (o2.T1_writevalue);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_7& o1, const _ProjectionRead__check_inv_7& o2) {
                    return o1.T1_writevalue != (o2.T1_writevalue);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_7& e) {
                    strm << "{";
                    strm << "T1_writevalue: " << e.T1_writevalue;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T1_writevalue.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_8 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_8& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_8& obj1, const _ProjectionRead__check_inv_8& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger T2_writevalue;

                _ProjectionRead__check_inv_8(const BInteger& T2_writevalue) {
                    this->T2_writevalue = T2_writevalue;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_8& o1, const _ProjectionRead__check_inv_8& o2) {
                    return o1.T2_writevalue == (o2.T2_writevalue);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_8& o1, const _ProjectionRead__check_inv_8& o2) {
                    return o1.T2_writevalue != (o2.T2_writevalue);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_8& e) {
                    strm << "{";
                    strm << "T2_writevalue: " << e.T2_writevalue;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_writevalue.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_9 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_9& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_9& obj1, const _ProjectionRead__check_inv_9& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger T2_readvalue;

                _ProjectionRead__check_inv_9(const BInteger& T2_readvalue) {
                    this->T2_readvalue = T2_readvalue;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_9& o1, const _ProjectionRead__check_inv_9& o2) {
                    return o1.T2_readvalue == (o2.T2_readvalue);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_9& o1, const _ProjectionRead__check_inv_9& o2) {
                    return o1.T2_readvalue != (o2.T2_readvalue);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_9& e) {
                    strm << "{";
                    strm << "T2_readvalue: " << e.T2_readvalue;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_readvalue.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_10 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_10& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_10& obj1, const _ProjectionRead__check_inv_10& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger T1_timer;

                _ProjectionRead__check_inv_10(const BInteger& T1_timer) {
                    this->T1_timer = T1_timer;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_10& o1, const _ProjectionRead__check_inv_10& o2) {
                    return o1.T1_timer == (o2.T1_timer);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_10& o1, const _ProjectionRead__check_inv_10& o2) {
                    return o1.T1_timer != (o2.T1_timer);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_10& e) {
                    strm << "{";
                    strm << "T1_timer: " << e.T1_timer;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T1_timer.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_11 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_11& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_11& obj1, const _ProjectionRead__check_inv_11& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger T2_timer;

                _ProjectionRead__check_inv_11(const BInteger& T2_timer) {
                    this->T2_timer = T2_timer;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_11& o1, const _ProjectionRead__check_inv_11& o2) {
                    return o1.T2_timer == (o2.T2_timer);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_11& o1, const _ProjectionRead__check_inv_11& o2) {
                    return o1.T2_timer != (o2.T2_timer);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_11& e) {
                    strm << "{";
                    strm << "T2_timer: " << e.T2_timer;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_timer.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_12 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_12& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_12& obj1, const _ProjectionRead__check_inv_12& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                T2mode T2_mode;

                _ProjectionRead__check_inv_12(const T2mode& T2_mode) {
                    this->T2_mode = T2_mode;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_12& o1, const _ProjectionRead__check_inv_12& o2) {
                    return o1.T2_mode == (o2.T2_mode);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_12& o1, const _ProjectionRead__check_inv_12& o2) {
                    return o1.T2_mode != (o2.T2_mode);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_12& e) {
                    strm << "{";
                    strm << "T2_mode: " << e.T2_mode;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_mode.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_13 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_13& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_13& obj1, const _ProjectionRead__check_inv_13& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger BUSvalue;

                _ProjectionRead__check_inv_13(const BInteger& BUSvalue) {
                    this->BUSvalue = BUSvalue;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_13& o1, const _ProjectionRead__check_inv_13& o2) {
                    return o1.BUSvalue == (o2.BUSvalue);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_13& o1, const _ProjectionRead__check_inv_13& o2) {
                    return o1.BUSvalue != (o2.BUSvalue);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_13& e) {
                    strm << "{";
                    strm << "BUSvalue: " << e.BUSvalue;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (BUSvalue.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_14 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_14& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_14& obj1, const _ProjectionRead__check_inv_14& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger BUSpriority;

                _ProjectionRead__check_inv_14(const BInteger& BUSpriority) {
                    this->BUSpriority = BUSpriority;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_14& o1, const _ProjectionRead__check_inv_14& o2) {
                    return o1.BUSpriority == (o2.BUSpriority);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_14& o1, const _ProjectionRead__check_inv_14& o2) {
                    return o1.BUSpriority != (o2.BUSpriority);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_14& e) {
                    strm << "{";
                    strm << "BUSpriority: " << e.BUSpriority;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (BUSpriority.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_15 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_15& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_15& obj1, const _ProjectionRead__check_inv_15& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger T3_readvalue;

                _ProjectionRead__check_inv_15(const BInteger& T3_readvalue) {
                    this->T3_readvalue = T3_readvalue;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_15& o1, const _ProjectionRead__check_inv_15& o2) {
                    return o1.T3_readvalue == (o2.T3_readvalue);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_15& o1, const _ProjectionRead__check_inv_15& o2) {
                    return o1.T3_readvalue != (o2.T3_readvalue);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_15& e) {
                    strm << "{";
                    strm << "T3_readvalue: " << e.T3_readvalue;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_readvalue.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_16 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_16& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_16& obj1, const _ProjectionRead__check_inv_16& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger T3_readpriority;

                _ProjectionRead__check_inv_16(const BInteger& T3_readpriority) {
                    this->T3_readpriority = T3_readpriority;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_16& o1, const _ProjectionRead__check_inv_16& o2) {
                    return o1.T3_readpriority == (o2.T3_readpriority);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_16& o1, const _ProjectionRead__check_inv_16& o2) {
                    return o1.T3_readpriority != (o2.T3_readpriority);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_16& e) {
                    strm << "{";
                    strm << "T3_readpriority: " << e.T3_readpriority;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T3_readpriority.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_17 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_17& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_17& obj1, const _ProjectionRead__check_inv_17& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger T2_readpriority;

                _ProjectionRead__check_inv_17(const BInteger& T2_readpriority) {
                    this->T2_readpriority = T2_readpriority;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_17& o1, const _ProjectionRead__check_inv_17& o2) {
                    return o1.T2_readpriority == (o2.T2_readpriority);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_17& o1, const _ProjectionRead__check_inv_17& o2) {
                    return o1.T2_readpriority != (o2.T2_readpriority);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_17& e) {
                    strm << "{";
                    strm << "T2_readpriority: " << e.T2_readpriority;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (T2_readpriority.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_18 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_18& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_18& obj1, const _ProjectionRead__check_inv_18& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<BInteger, BInteger > BUSwrite;

                _ProjectionRead__check_inv_18(const BRelation<BInteger, BInteger >& BUSwrite) {
                    this->BUSwrite = BUSwrite;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_18& o1, const _ProjectionRead__check_inv_18& o2) {
                    return o1.BUSwrite == (o2.BUSwrite);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_18& o1, const _ProjectionRead__check_inv_18& o2) {
                    return o1.BUSwrite != (o2.BUSwrite);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_18& e) {
                    strm << "{";
                    strm << "BUSwrite: " << e.BUSwrite;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (BUSwrite.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_19 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_19& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_19& obj1, const _ProjectionRead__check_inv_19& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<BInteger, BInteger > BUSwrite;

                _ProjectionRead__check_inv_19(const BRelation<BInteger, BInteger >& BUSwrite) {
                    this->BUSwrite = BUSwrite;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_19& o1, const _ProjectionRead__check_inv_19& o2) {
                    return o1.BUSwrite == (o2.BUSwrite);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_19& o1, const _ProjectionRead__check_inv_19& o2) {
                    return o1.BUSwrite != (o2.BUSwrite);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_19& e) {
                    strm << "{";
                    strm << "BUSwrite: " << e.BUSwrite;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (BUSwrite.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_20 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_20& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_20& obj1, const _ProjectionRead__check_inv_20& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<BInteger, BInteger > BUSwrite;

                _ProjectionRead__check_inv_20(const BRelation<BInteger, BInteger >& BUSwrite) {
                    this->BUSwrite = BUSwrite;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_20& o1, const _ProjectionRead__check_inv_20& o2) {
                    return o1.BUSwrite == (o2.BUSwrite);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_20& o1, const _ProjectionRead__check_inv_20& o2) {
                    return o1.BUSwrite != (o2.BUSwrite);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_20& e) {
                    strm << "{";
                    strm << "BUSwrite: " << e.BUSwrite;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (BUSwrite.hashCode() << 1);
                    return result;
                }

        };



    private:

        BSet<BInteger > NATSET;
        BSet<BInteger > __aux_constant_1;


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

        std::string stateAccessedVia;

        CAN_BUS_tlc() {
            NATSET = (BSet<BInteger>::interval((BInteger(0)),(BInteger(5))));
            __aux_constant_1 = (BSet<BInteger>::interval((BInteger(1)).negative(),(BInteger(3))));
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

        CAN_BUS_tlc(const CAN_BUS_tlc& copy) {
            this->NATSET = copy.NATSET;
            this->__aux_constant_1 = copy.__aux_constant_1;
            this->BUSpriority = copy.BUSpriority;
            this->BUSvalue = copy.BUSvalue;
            this->BUSwrite = copy.BUSwrite;
            this->T1_state = copy.T1_state;
            this->T1_timer = copy.T1_timer;
            this->T1_writevalue = copy.T1_writevalue;
            this->T2_mode = copy.T2_mode;
            this->T2_readpriority = copy.T2_readpriority;
            this->T2_readvalue = copy.T2_readvalue;
            this->T2_state = copy.T2_state;
            this->T2_timer = copy.T2_timer;
            this->T2_writevalue = copy.T2_writevalue;
            this->T2v = copy.T2v;
            this->T3_enabled = copy.T3_enabled;
            this->T3_evaluated = copy.T3_evaluated;
            this->T3_readpriority = copy.T3_readpriority;
            this->T3_readvalue = copy.T3_readvalue;
            this->T3_state = copy.T3_state;
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

        BSet<BInteger > _get___aux_constant_1() const {
            return __aux_constant_1;
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
            for(const BInteger& _ic_p_1 : __aux_constant_1) {
                if((T1_state.equal((T1state(T1state::T1_CALC)))).booleanValue()) {
                    _ic_set_1 = _ic_set_1._union(BSet<BInteger>(_ic_p_1));
                }

            }

            return _ic_set_1;
        }

        BSet<BTuple<BInteger, BInteger >> _tr_T1SendResult() const {
            BSet<BTuple<BInteger, BInteger >> _ic_set_2 = BSet<BTuple<BInteger, BInteger >>();
            for(const BInteger& _ic_ppriority_1 : {(BInteger(3))}) {
                for(const BInteger& _ic_pv_1 : {T1_writevalue}) {
                    if((T1_state.equal((T1state(T1state::T1_SEND)))).booleanValue()) {
                        _ic_set_2 = _ic_set_2._union(BSet<BTuple<BInteger, BInteger >>((BTuple<BInteger, BInteger >(_ic_ppriority_1, _ic_pv_1))));
                    }

                }

            }

            return _ic_set_2;
        }

        BSet<BInteger> _tr_T1Wait() const {
            BSet<BInteger> _ic_set_3 = BSet<BInteger>();
            for(const BInteger& _ic_pt_1 : {(BInteger(2))}) {
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
            for(const BInteger& _ic_ppriority_1 : {BUSpriority}) {
                for(const BInteger& _ic_pv_1 : {BUSvalue}) {
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
            for(const BInteger& _ic_ppriority_1 : {T2_readpriority}) {
                if(((BBoolean((BUSwrite.isInDomain(_ic_ppriority_1)).booleanValue() && T2_state.equal((T2state(T2state::T2_RELEASE))).booleanValue()))).booleanValue()) {
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
            for(const BInteger& _ic_ppriority_1 : {(BInteger(5))}) {
                for(const BInteger& _ic_pv_1 : {T2_writevalue}) {
                    if((T2_state.equal((T2state(T2state::T2_SEND)))).booleanValue()) {
                        _ic_set_10 = _ic_set_10._union(BSet<BTuple<BInteger, BInteger >>((BTuple<BInteger, BInteger >(_ic_ppriority_1, _ic_pv_1))));
                    }

                }

            }

            return _ic_set_10;
        }

        BSet<BInteger> _tr_T2Wait() const {
            BSet<BInteger> _ic_set_11 = BSet<BInteger>();
            for(const BInteger& _ic_pt_1 : {(BInteger(3))}) {
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
            for(const BInteger& _ic_ppriority_1 : {(BInteger(4))}) {
                for(const BInteger& _ic_pv_1 : {(BInteger(0))}) {
                    if((T3_state.equal((T3state(T3state::T3_WRITE)))).booleanValue()) {
                        _ic_set_14 = _ic_set_14._union(BSet<BTuple<BInteger, BInteger >>((BTuple<BInteger, BInteger >(_ic_ppriority_1, _ic_pv_1))));
                    }

                }

            }

            return _ic_set_14;
        }

        BSet<BTuple<BInteger, BInteger >> _tr_T3Read() const {
            BSet<BTuple<BInteger, BInteger >> _ic_set_15 = BSet<BTuple<BInteger, BInteger >>();
            for(const BInteger& _ic_ppriority_1 : {BUSpriority}) {
                for(const BInteger& _ic_pv_1 : {BUSvalue}) {
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
            for(const BInteger& _ic_ppriority_1 : {(BInteger(4))}) {
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
            for(const BInteger& _ic_pmax_1 : {BUSwrite.domain().max()}) {
                if(((BBoolean((BBoolean(T1_timer.greater((BInteger(0))).booleanValue() && T2_timer.greater((BInteger(0))).booleanValue())).booleanValue() && (BBoolean(T3_enabled.equal((BBoolean(true))).booleanValue() || T3_evaluated.equal((BBoolean(true))).booleanValue())).booleanValue()))).booleanValue()) {
                    _ic_set_20 = _ic_set_20._union(BSet<BInteger>(_ic_pmax_1));
                }

            }

            return _ic_set_20;
        }

        _ProjectionRead_T1Wait _projected_state_for_T1Wait() const {
            return _ProjectionRead_T1Wait(T1_state);
        }

        _ProjectionRead_T1Calculate _projected_state_for_T1Calculate() const {
            return _ProjectionRead_T1Calculate(T1_state);
        }

        _ProjectionRead_T1SendResult _projected_state_for_T1SendResult() const {
            return _ProjectionRead_T1SendResult(T1_state,T1_writevalue,BUSwrite);
        }

        _ProjectionRead_T2ReadBus _projected_state_for_T2ReadBus() const {
            return _ProjectionRead_T2ReadBus(T2_state,BUSpriority,BUSvalue);
        }

        _ProjectionRead_T2Reset _projected_state_for_T2Reset() const {
            return _ProjectionRead_T2Reset(T2_state,T2_readpriority,T2v);
        }

        _ProjectionRead_T2Complete _projected_state_for_T2Complete() const {
            return _ProjectionRead_T2Complete(T2_state,T2_readpriority,T2_mode);
        }

        _ProjectionRead_T2Evaluate _projected_state_for_T2Evaluate() const {
            return _ProjectionRead_T2Evaluate(T2_state,T2_timer);
        }

        _ProjectionRead_T3Evaluate _projected_state_for_T3Evaluate() const {
            return _ProjectionRead_T3Evaluate(T3_evaluated,T3_state,T3_enabled);
        }

        _ProjectionRead_T3ReleaseBus _projected_state_for_T3ReleaseBus() const {
            return _ProjectionRead_T3ReleaseBus(T3_readpriority,T3_state,BUSwrite);
        }

        _ProjectionRead_T1Evaluate _projected_state_for_T1Evaluate() const {
            return _ProjectionRead_T1Evaluate(T1_state,T1_timer);
        }

        _ProjectionRead_T3Initiate _projected_state_for_T3Initiate() const {
            return _ProjectionRead_T3Initiate(T3_evaluated,T3_state,T3_enabled);
        }

        _ProjectionRead_T3ReEnableWait _projected_state_for_T3ReEnableWait() const {
            return _ProjectionRead_T3ReEnableWait(T3_state);
        }

        _ProjectionRead_T3writebus _projected_state_for_T3writebus() const {
            return _ProjectionRead_T3writebus(T3_state,BUSwrite);
        }

        _ProjectionRead_Update _projected_state_for_Update() const {
            return _ProjectionRead_Update(T3_evaluated,T1_timer,T3_enabled,BUSwrite,T2_timer);
        }

        _ProjectionRead_T2ReleaseBus _projected_state_for_T2ReleaseBus() const {
            return _ProjectionRead_T2ReleaseBus(T2_state,T2_readpriority,BUSwrite);
        }

        _ProjectionRead_T2Wait _projected_state_for_T2Wait() const {
            return _ProjectionRead_T2Wait(T2_state);
        }

        _ProjectionRead_T3Poll _projected_state_for_T3Poll() const {
            return _ProjectionRead_T3Poll(T3_readpriority,T3_state);
        }

        _ProjectionRead_T2Calculate _projected_state_for_T2Calculate() const {
            return _ProjectionRead_T2Calculate(T2_state,T2_readpriority,T2_readvalue);
        }

        _ProjectionRead_T3Read _projected_state_for_T3Read() const {
            return _ProjectionRead_T3Read(BUSpriority,T3_state,BUSvalue);
        }

        _ProjectionRead_T3Wait _projected_state_for_T3Wait() const {
            return _ProjectionRead_T3Wait(T3_state);
        }

        _ProjectionRead_T2WriteBus _projected_state_for_T2WriteBus() const {
            return _ProjectionRead_T2WriteBus(T2_state,T2_writevalue,BUSwrite);
        }

        _ProjectionRead__tr_T1Evaluate _projected_state_for__tr_T1Evaluate() const {
            return _ProjectionRead__tr_T1Evaluate(T1_state,T1_timer);
        }

        _ProjectionRead__tr_T2Complete _projected_state_for__tr_T2Complete() const {
            return _ProjectionRead__tr_T2Complete(T2_state,T2_readpriority,T2_mode);
        }

        _ProjectionRead__tr_T2Calculate _projected_state_for__tr_T2Calculate() const {
            return _ProjectionRead__tr_T2Calculate(T2_state,T2_readpriority);
        }

        _ProjectionRead__tr_T2Evaluate _projected_state_for__tr_T2Evaluate() const {
            return _ProjectionRead__tr_T2Evaluate(T2_state,T2_timer);
        }

        _ProjectionRead__tr_T3Poll _projected_state_for__tr_T3Poll() const {
            return _ProjectionRead__tr_T3Poll(T3_readpriority,T3_state);
        }

        _ProjectionRead__tr_T3ReEnableWait _projected_state_for__tr_T3ReEnableWait() const {
            return _ProjectionRead__tr_T3ReEnableWait(T3_state);
        }

        _ProjectionRead__tr_T2ReadBus _projected_state_for__tr_T2ReadBus() const {
            return _ProjectionRead__tr_T2ReadBus(T2_state,BUSpriority,BUSvalue);
        }

        _ProjectionRead__tr_T2WriteBus _projected_state_for__tr_T2WriteBus() const {
            return _ProjectionRead__tr_T2WriteBus(T2_state,T2_writevalue);
        }

        _ProjectionRead__tr_T2Wait _projected_state_for__tr_T2Wait() const {
            return _ProjectionRead__tr_T2Wait(T2_state);
        }

        _ProjectionRead__tr_T2Reset _projected_state_for__tr_T2Reset() const {
            return _ProjectionRead__tr_T2Reset(T2_state,T2_readpriority);
        }

        _ProjectionRead__tr_T2ReleaseBus _projected_state_for__tr_T2ReleaseBus() const {
            return _ProjectionRead__tr_T2ReleaseBus(T2_state,T2_readpriority,BUSwrite);
        }

        _ProjectionRead__tr_T3writebus _projected_state_for__tr_T3writebus() const {
            return _ProjectionRead__tr_T3writebus(T3_state);
        }

        _ProjectionRead__tr_T3Read _projected_state_for__tr_T3Read() const {
            return _ProjectionRead__tr_T3Read(BUSpriority,T3_state,BUSvalue);
        }

        _ProjectionRead__tr_T3ReleaseBus _projected_state_for__tr_T3ReleaseBus() const {
            return _ProjectionRead__tr_T3ReleaseBus(T3_readpriority,T3_state);
        }

        _ProjectionRead__tr_Update _projected_state_for__tr_Update() const {
            return _ProjectionRead__tr_Update(T3_evaluated,T1_timer,T3_enabled,BUSwrite,T2_timer);
        }

        _ProjectionRead__tr_T1SendResult _projected_state_for__tr_T1SendResult() const {
            return _ProjectionRead__tr_T1SendResult(T1_state,T1_writevalue);
        }

        _ProjectionRead__tr_T3Evaluate _projected_state_for__tr_T3Evaluate() const {
            return _ProjectionRead__tr_T3Evaluate(T3_evaluated,T3_state,T3_enabled);
        }

        _ProjectionRead__tr_T1Calculate _projected_state_for__tr_T1Calculate() const {
            return _ProjectionRead__tr_T1Calculate(T1_state);
        }

        _ProjectionRead__tr_T3Wait _projected_state_for__tr_T3Wait() const {
            return _ProjectionRead__tr_T3Wait(T3_state);
        }

        _ProjectionRead__tr_T1Wait _projected_state_for__tr_T1Wait() const {
            return _ProjectionRead__tr_T1Wait(T1_state);
        }

        _ProjectionRead__tr_T3Initiate _projected_state_for__tr_T3Initiate() const {
            return _ProjectionRead__tr_T3Initiate(T3_evaluated,T3_state,T3_enabled);
        }

        _ProjectionRead__check_inv_18 _projected_state_for__check_inv_18() const {
            return _ProjectionRead__check_inv_18(BUSwrite);
        }

        _ProjectionRead__check_inv_17 _projected_state_for__check_inv_17() const {
            return _ProjectionRead__check_inv_17(T2_readpriority);
        }

        _ProjectionRead__check_inv_16 _projected_state_for__check_inv_16() const {
            return _ProjectionRead__check_inv_16(T3_readpriority);
        }

        _ProjectionRead__check_inv_15 _projected_state_for__check_inv_15() const {
            return _ProjectionRead__check_inv_15(T3_readvalue);
        }

        _ProjectionRead__check_inv_19 _projected_state_for__check_inv_19() const {
            return _ProjectionRead__check_inv_19(BUSwrite);
        }

        _ProjectionRead__check_inv_6 _projected_state_for__check_inv_6() const {
            return _ProjectionRead__check_inv_6(T3_state);
        }

        _ProjectionRead__check_inv_10 _projected_state_for__check_inv_10() const {
            return _ProjectionRead__check_inv_10(T1_timer);
        }

        _ProjectionRead__check_inv_7 _projected_state_for__check_inv_7() const {
            return _ProjectionRead__check_inv_7(T1_writevalue);
        }

        _ProjectionRead__check_inv_20 _projected_state_for__check_inv_20() const {
            return _ProjectionRead__check_inv_20(BUSwrite);
        }

        _ProjectionRead__check_inv_4 _projected_state_for__check_inv_4() const {
            return _ProjectionRead__check_inv_4(T1_state);
        }

        _ProjectionRead__check_inv_5 _projected_state_for__check_inv_5() const {
            return _ProjectionRead__check_inv_5(T2_state);
        }

        _ProjectionRead__check_inv_14 _projected_state_for__check_inv_14() const {
            return _ProjectionRead__check_inv_14(BUSpriority);
        }

        _ProjectionRead__check_inv_13 _projected_state_for__check_inv_13() const {
            return _ProjectionRead__check_inv_13(BUSvalue);
        }

        _ProjectionRead__check_inv_8 _projected_state_for__check_inv_8() const {
            return _ProjectionRead__check_inv_8(T2_writevalue);
        }

        _ProjectionRead__check_inv_12 _projected_state_for__check_inv_12() const {
            return _ProjectionRead__check_inv_12(T2_mode);
        }

        _ProjectionRead__check_inv_9 _projected_state_for__check_inv_9() const {
            return _ProjectionRead__check_inv_9(T2_readvalue);
        }

        _ProjectionRead__check_inv_11 _projected_state_for__check_inv_11() const {
            return _ProjectionRead__check_inv_11(T2_timer);
        }

        _ProjectionRead__check_inv_2 _projected_state_for__check_inv_2() const {
            return _ProjectionRead__check_inv_2(T3_evaluated);
        }

        _ProjectionRead__check_inv_3 _projected_state_for__check_inv_3() const {
            return _ProjectionRead__check_inv_3(T3_enabled);
        }

        _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() const {
            return _ProjectionRead__check_inv_1(T2v);
        }

        _ProjectionWrite_T1Wait _update_for_T1Wait() const {
            return _ProjectionWrite_T1Wait(T1_state,T1_timer);
        }

        _ProjectionWrite_T1Calculate _update_for_T1Calculate() const {
            return _ProjectionWrite_T1Calculate(T1_state,T1_writevalue);
        }

        _ProjectionWrite_T1SendResult _update_for_T1SendResult() const {
            return _ProjectionWrite_T1SendResult(T1_state,BUSwrite);
        }

        _ProjectionWrite_T2ReadBus _update_for_T2ReadBus() const {
            return _ProjectionWrite_T2ReadBus(T2_state,T2_readpriority,T2_readvalue);
        }

        _ProjectionWrite_T2Reset _update_for_T2Reset() const {
            return _ProjectionWrite_T2Reset(T2_state,T2_writevalue,T2v,T2_mode);
        }

        _ProjectionWrite_T2Complete _update_for_T2Complete() const {
            return _ProjectionWrite_T2Complete(T2_state,T2_mode);
        }

        _ProjectionWrite_T2Evaluate _update_for_T2Evaluate() const {
            return _ProjectionWrite_T2Evaluate(T2_state,T2_timer);
        }

        _ProjectionWrite_T3Evaluate _update_for_T3Evaluate() const {
            return _ProjectionWrite_T3Evaluate(T3_state);
        }

        _ProjectionWrite_T3ReleaseBus _update_for_T3ReleaseBus() const {
            return _ProjectionWrite_T3ReleaseBus(T3_state,BUSwrite);
        }

        _ProjectionWrite_T1Evaluate _update_for_T1Evaluate() const {
            return _ProjectionWrite_T1Evaluate(T1_state,T1_timer);
        }

        _ProjectionWrite_T3Initiate _update_for_T3Initiate() const {
            return _ProjectionWrite_T3Initiate(T3_state,T3_enabled);
        }

        _ProjectionWrite_T3ReEnableWait _update_for_T3ReEnableWait() const {
            return _ProjectionWrite_T3ReEnableWait(T3_evaluated,T3_state,T3_enabled);
        }

        _ProjectionWrite_T3writebus _update_for_T3writebus() const {
            return _ProjectionWrite_T3writebus(T3_state,BUSwrite);
        }

        _ProjectionWrite_Update _update_for_Update() const {
            return _ProjectionWrite_Update(T3_evaluated,BUSpriority,T1_timer,T2_timer,BUSvalue);
        }

        _ProjectionWrite_T2ReleaseBus _update_for_T2ReleaseBus() const {
            return _ProjectionWrite_T2ReleaseBus(T2_state,BUSwrite);
        }

        _ProjectionWrite_T2Wait _update_for_T2Wait() const {
            return _ProjectionWrite_T2Wait(T2_state,T2_timer);
        }

        _ProjectionWrite_T3Poll _update_for_T3Poll() const {
            return _ProjectionWrite_T3Poll(T3_state);
        }

        _ProjectionWrite_T2Calculate _update_for_T2Calculate() const {
            return _ProjectionWrite_T2Calculate(T2_state,T2v);
        }

        _ProjectionWrite_T3Read _update_for_T3Read() const {
            return _ProjectionWrite_T3Read(T3_readpriority,T3_readvalue,T3_state);
        }

        _ProjectionWrite_T3Wait _update_for_T3Wait() const {
            return _ProjectionWrite_T3Wait(T3_evaluated,T3_state);
        }

        _ProjectionWrite_T2WriteBus _update_for_T2WriteBus() const {
            return _ProjectionWrite_T2WriteBus(T2_state,BUSwrite);
        }

        void _apply_update_for_T1Wait(const _ProjectionWrite_T1Wait& update) {
            this->T1_state = update.T1_state;
            this->T1_timer = update.T1_timer;
        }

        void _apply_update_for_T1Calculate(const _ProjectionWrite_T1Calculate& update) {
            this->T1_state = update.T1_state;
            this->T1_writevalue = update.T1_writevalue;
        }

        void _apply_update_for_T1SendResult(const _ProjectionWrite_T1SendResult& update) {
            this->T1_state = update.T1_state;
            this->BUSwrite = update.BUSwrite;
        }

        void _apply_update_for_T2ReadBus(const _ProjectionWrite_T2ReadBus& update) {
            this->T2_state = update.T2_state;
            this->T2_readpriority = update.T2_readpriority;
            this->T2_readvalue = update.T2_readvalue;
        }

        void _apply_update_for_T2Reset(const _ProjectionWrite_T2Reset& update) {
            this->T2_state = update.T2_state;
            this->T2_writevalue = update.T2_writevalue;
            this->T2v = update.T2v;
            this->T2_mode = update.T2_mode;
        }

        void _apply_update_for_T2Complete(const _ProjectionWrite_T2Complete& update) {
            this->T2_state = update.T2_state;
            this->T2_mode = update.T2_mode;
        }

        void _apply_update_for_T2Evaluate(const _ProjectionWrite_T2Evaluate& update) {
            this->T2_state = update.T2_state;
            this->T2_timer = update.T2_timer;
        }

        void _apply_update_for_T3Evaluate(const _ProjectionWrite_T3Evaluate& update) {
            this->T3_state = update.T3_state;
        }

        void _apply_update_for_T3ReleaseBus(const _ProjectionWrite_T3ReleaseBus& update) {
            this->T3_state = update.T3_state;
            this->BUSwrite = update.BUSwrite;
        }

        void _apply_update_for_T1Evaluate(const _ProjectionWrite_T1Evaluate& update) {
            this->T1_state = update.T1_state;
            this->T1_timer = update.T1_timer;
        }

        void _apply_update_for_T3Initiate(const _ProjectionWrite_T3Initiate& update) {
            this->T3_state = update.T3_state;
            this->T3_enabled = update.T3_enabled;
        }

        void _apply_update_for_T3ReEnableWait(const _ProjectionWrite_T3ReEnableWait& update) {
            this->T3_evaluated = update.T3_evaluated;
            this->T3_state = update.T3_state;
            this->T3_enabled = update.T3_enabled;
        }

        void _apply_update_for_T3writebus(const _ProjectionWrite_T3writebus& update) {
            this->T3_state = update.T3_state;
            this->BUSwrite = update.BUSwrite;
        }

        void _apply_update_for_Update(const _ProjectionWrite_Update& update) {
            this->T3_evaluated = update.T3_evaluated;
            this->BUSpriority = update.BUSpriority;
            this->T1_timer = update.T1_timer;
            this->T2_timer = update.T2_timer;
            this->BUSvalue = update.BUSvalue;
        }

        void _apply_update_for_T2ReleaseBus(const _ProjectionWrite_T2ReleaseBus& update) {
            this->T2_state = update.T2_state;
            this->BUSwrite = update.BUSwrite;
        }

        void _apply_update_for_T2Wait(const _ProjectionWrite_T2Wait& update) {
            this->T2_state = update.T2_state;
            this->T2_timer = update.T2_timer;
        }

        void _apply_update_for_T3Poll(const _ProjectionWrite_T3Poll& update) {
            this->T3_state = update.T3_state;
        }

        void _apply_update_for_T2Calculate(const _ProjectionWrite_T2Calculate& update) {
            this->T2_state = update.T2_state;
            this->T2v = update.T2v;
        }

        void _apply_update_for_T3Read(const _ProjectionWrite_T3Read& update) {
            this->T3_readpriority = update.T3_readpriority;
            this->T3_readvalue = update.T3_readvalue;
            this->T3_state = update.T3_state;
        }

        void _apply_update_for_T3Wait(const _ProjectionWrite_T3Wait& update) {
            this->T3_evaluated = update.T3_evaluated;
            this->T3_state = update.T3_state;
        }

        void _apply_update_for_T2WriteBus(const _ProjectionWrite_T2WriteBus& update) {
            this->T2_state = update.T2_state;
            this->BUSwrite = update.BUSwrite;
        }

        bool _check_inv_1() const {
            return ((T2v.isInteger())).booleanValue();
        }

        bool _check_inv_2() const {
            return ((T3_evaluated.isBoolean())).booleanValue();
        }

        bool _check_inv_3() const {
            return ((T3_enabled.isBoolean())).booleanValue();
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
            return ((BUSwrite.isInDomain((BInteger(0))))).booleanValue();
        }

        CAN_BUS_tlc _copy() const {
            return CAN_BUS_tlc(*this);
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


class ModelChecker {
    private:
        CAN_BUS_tlc::Type type;
        int threads;
        bool isCaching;
        bool isDebug;

        std::list<CAN_BUS_tlc> unvisitedStates;
        std::unordered_set<CAN_BUS_tlc, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual> states;
        std::atomic<int> transitions;
        std::mutex mutex;
        std::mutex waitMutex;
        std::mutex cacheMutex;
        std::condition_variable waitCV;

        std::atomic<bool> invariantViolatedBool;
        std::atomic<bool> deadlockDetected;
        CAN_BUS_tlc counterExampleState;

        std::unordered_map<bool, std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T1Evaluate, CAN_BUS_tlc::_ProjectionWrite_T1Evaluate, CAN_BUS_tlc::_ProjectionRead_T1Evaluate::Hash, CAN_BUS_tlc::_ProjectionRead_T1Evaluate::HashEqual>> _OpCache_T1Evaluate;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__tr_T1Evaluate, bool, CAN_BUS_tlc::_ProjectionRead__tr_T1Evaluate::Hash, CAN_BUS_tlc::_ProjectionRead__tr_T1Evaluate::HashEqual> _OpCache_tr_T1Evaluate;
        std::mutex _ProjectionRead_T1Evaluate_mutex;
        std::mutex _ProjectionRead__tr_T1Evaluate_mutex;

        std::unordered_map<BSet<BInteger>, std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T1Calculate, CAN_BUS_tlc::_ProjectionWrite_T1Calculate, CAN_BUS_tlc::_ProjectionRead_T1Calculate::Hash, CAN_BUS_tlc::_ProjectionRead_T1Calculate::HashEqual>, BSet<BInteger>::SetHash, BSet<BInteger>::SetHashEqual> _OpCache_T1Calculate;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__tr_T1Calculate,  BSet<BInteger>, CAN_BUS_tlc::_ProjectionRead__tr_T1Calculate::Hash, CAN_BUS_tlc::_ProjectionRead__tr_T1Calculate::HashEqual> _OpCache_tr_T1Calculate;
        std::mutex _ProjectionRead_T1Calculate_mutex;
        std::mutex _ProjectionRead__tr_T1Calculate_mutex;

        std::unordered_map<BSet<BTuple<BInteger, BInteger >>, std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T1SendResult, CAN_BUS_tlc::_ProjectionWrite_T1SendResult, CAN_BUS_tlc::_ProjectionRead_T1SendResult::Hash, CAN_BUS_tlc::_ProjectionRead_T1SendResult::HashEqual>, BSet<BTuple<BInteger, BInteger >>::SetHash, BSet<BTuple<BInteger, BInteger >>::SetHashEqual> _OpCache_T1SendResult;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__tr_T1SendResult,  BSet<BTuple<BInteger, BInteger >>, CAN_BUS_tlc::_ProjectionRead__tr_T1SendResult::Hash, CAN_BUS_tlc::_ProjectionRead__tr_T1SendResult::HashEqual> _OpCache_tr_T1SendResult;
        std::mutex _ProjectionRead_T1SendResult_mutex;
        std::mutex _ProjectionRead__tr_T1SendResult_mutex;

        std::unordered_map<BSet<BInteger>, std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T1Wait, CAN_BUS_tlc::_ProjectionWrite_T1Wait, CAN_BUS_tlc::_ProjectionRead_T1Wait::Hash, CAN_BUS_tlc::_ProjectionRead_T1Wait::HashEqual>, BSet<BInteger>::SetHash, BSet<BInteger>::SetHashEqual> _OpCache_T1Wait;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__tr_T1Wait,  BSet<BInteger>, CAN_BUS_tlc::_ProjectionRead__tr_T1Wait::Hash, CAN_BUS_tlc::_ProjectionRead__tr_T1Wait::HashEqual> _OpCache_tr_T1Wait;
        std::mutex _ProjectionRead_T1Wait_mutex;
        std::mutex _ProjectionRead__tr_T1Wait_mutex;

        std::unordered_map<bool, std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2Evaluate, CAN_BUS_tlc::_ProjectionWrite_T2Evaluate, CAN_BUS_tlc::_ProjectionRead_T2Evaluate::Hash, CAN_BUS_tlc::_ProjectionRead_T2Evaluate::HashEqual>> _OpCache_T2Evaluate;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__tr_T2Evaluate, bool, CAN_BUS_tlc::_ProjectionRead__tr_T2Evaluate::Hash, CAN_BUS_tlc::_ProjectionRead__tr_T2Evaluate::HashEqual> _OpCache_tr_T2Evaluate;
        std::mutex _ProjectionRead_T2Evaluate_mutex;
        std::mutex _ProjectionRead__tr_T2Evaluate_mutex;

        std::unordered_map<BSet<BTuple<BInteger, BInteger >>, std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2ReadBus, CAN_BUS_tlc::_ProjectionWrite_T2ReadBus, CAN_BUS_tlc::_ProjectionRead_T2ReadBus::Hash, CAN_BUS_tlc::_ProjectionRead_T2ReadBus::HashEqual>, BSet<BTuple<BInteger, BInteger >>::SetHash, BSet<BTuple<BInteger, BInteger >>::SetHashEqual> _OpCache_T2ReadBus;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__tr_T2ReadBus,  BSet<BTuple<BInteger, BInteger >>, CAN_BUS_tlc::_ProjectionRead__tr_T2ReadBus::Hash, CAN_BUS_tlc::_ProjectionRead__tr_T2ReadBus::HashEqual> _OpCache_tr_T2ReadBus;
        std::mutex _ProjectionRead_T2ReadBus_mutex;
        std::mutex _ProjectionRead__tr_T2ReadBus_mutex;

        std::unordered_map<bool, std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2Reset, CAN_BUS_tlc::_ProjectionWrite_T2Reset, CAN_BUS_tlc::_ProjectionRead_T2Reset::Hash, CAN_BUS_tlc::_ProjectionRead_T2Reset::HashEqual>> _OpCache_T2Reset;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__tr_T2Reset, bool, CAN_BUS_tlc::_ProjectionRead__tr_T2Reset::Hash, CAN_BUS_tlc::_ProjectionRead__tr_T2Reset::HashEqual> _OpCache_tr_T2Reset;
        std::mutex _ProjectionRead_T2Reset_mutex;
        std::mutex _ProjectionRead__tr_T2Reset_mutex;

        std::unordered_map<bool, std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2Complete, CAN_BUS_tlc::_ProjectionWrite_T2Complete, CAN_BUS_tlc::_ProjectionRead_T2Complete::Hash, CAN_BUS_tlc::_ProjectionRead_T2Complete::HashEqual>> _OpCache_T2Complete;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__tr_T2Complete, bool, CAN_BUS_tlc::_ProjectionRead__tr_T2Complete::Hash, CAN_BUS_tlc::_ProjectionRead__tr_T2Complete::HashEqual> _OpCache_tr_T2Complete;
        std::mutex _ProjectionRead_T2Complete_mutex;
        std::mutex _ProjectionRead__tr_T2Complete_mutex;

        std::unordered_map<BSet<BInteger>, std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2ReleaseBus, CAN_BUS_tlc::_ProjectionWrite_T2ReleaseBus, CAN_BUS_tlc::_ProjectionRead_T2ReleaseBus::Hash, CAN_BUS_tlc::_ProjectionRead_T2ReleaseBus::HashEqual>, BSet<BInteger>::SetHash, BSet<BInteger>::SetHashEqual> _OpCache_T2ReleaseBus;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__tr_T2ReleaseBus,  BSet<BInteger>, CAN_BUS_tlc::_ProjectionRead__tr_T2ReleaseBus::Hash, CAN_BUS_tlc::_ProjectionRead__tr_T2ReleaseBus::HashEqual> _OpCache_tr_T2ReleaseBus;
        std::mutex _ProjectionRead_T2ReleaseBus_mutex;
        std::mutex _ProjectionRead__tr_T2ReleaseBus_mutex;

        std::unordered_map<bool, std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2Calculate, CAN_BUS_tlc::_ProjectionWrite_T2Calculate, CAN_BUS_tlc::_ProjectionRead_T2Calculate::Hash, CAN_BUS_tlc::_ProjectionRead_T2Calculate::HashEqual>> _OpCache_T2Calculate;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__tr_T2Calculate, bool, CAN_BUS_tlc::_ProjectionRead__tr_T2Calculate::Hash, CAN_BUS_tlc::_ProjectionRead__tr_T2Calculate::HashEqual> _OpCache_tr_T2Calculate;
        std::mutex _ProjectionRead_T2Calculate_mutex;
        std::mutex _ProjectionRead__tr_T2Calculate_mutex;

        std::unordered_map<BSet<BTuple<BInteger, BInteger >>, std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2WriteBus, CAN_BUS_tlc::_ProjectionWrite_T2WriteBus, CAN_BUS_tlc::_ProjectionRead_T2WriteBus::Hash, CAN_BUS_tlc::_ProjectionRead_T2WriteBus::HashEqual>, BSet<BTuple<BInteger, BInteger >>::SetHash, BSet<BTuple<BInteger, BInteger >>::SetHashEqual> _OpCache_T2WriteBus;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__tr_T2WriteBus,  BSet<BTuple<BInteger, BInteger >>, CAN_BUS_tlc::_ProjectionRead__tr_T2WriteBus::Hash, CAN_BUS_tlc::_ProjectionRead__tr_T2WriteBus::HashEqual> _OpCache_tr_T2WriteBus;
        std::mutex _ProjectionRead_T2WriteBus_mutex;
        std::mutex _ProjectionRead__tr_T2WriteBus_mutex;

        std::unordered_map<BSet<BInteger>, std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2Wait, CAN_BUS_tlc::_ProjectionWrite_T2Wait, CAN_BUS_tlc::_ProjectionRead_T2Wait::Hash, CAN_BUS_tlc::_ProjectionRead_T2Wait::HashEqual>, BSet<BInteger>::SetHash, BSet<BInteger>::SetHashEqual> _OpCache_T2Wait;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__tr_T2Wait,  BSet<BInteger>, CAN_BUS_tlc::_ProjectionRead__tr_T2Wait::Hash, CAN_BUS_tlc::_ProjectionRead__tr_T2Wait::HashEqual> _OpCache_tr_T2Wait;
        std::mutex _ProjectionRead_T2Wait_mutex;
        std::mutex _ProjectionRead__tr_T2Wait_mutex;

        std::unordered_map<bool, std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3Initiate, CAN_BUS_tlc::_ProjectionWrite_T3Initiate, CAN_BUS_tlc::_ProjectionRead_T3Initiate::Hash, CAN_BUS_tlc::_ProjectionRead_T3Initiate::HashEqual>> _OpCache_T3Initiate;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__tr_T3Initiate, bool, CAN_BUS_tlc::_ProjectionRead__tr_T3Initiate::Hash, CAN_BUS_tlc::_ProjectionRead__tr_T3Initiate::HashEqual> _OpCache_tr_T3Initiate;
        std::mutex _ProjectionRead_T3Initiate_mutex;
        std::mutex _ProjectionRead__tr_T3Initiate_mutex;

        std::unordered_map<bool, std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3Evaluate, CAN_BUS_tlc::_ProjectionWrite_T3Evaluate, CAN_BUS_tlc::_ProjectionRead_T3Evaluate::Hash, CAN_BUS_tlc::_ProjectionRead_T3Evaluate::HashEqual>> _OpCache_T3Evaluate;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__tr_T3Evaluate, bool, CAN_BUS_tlc::_ProjectionRead__tr_T3Evaluate::Hash, CAN_BUS_tlc::_ProjectionRead__tr_T3Evaluate::HashEqual> _OpCache_tr_T3Evaluate;
        std::mutex _ProjectionRead_T3Evaluate_mutex;
        std::mutex _ProjectionRead__tr_T3Evaluate_mutex;

        std::unordered_map<BSet<BTuple<BInteger, BInteger >>, std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3writebus, CAN_BUS_tlc::_ProjectionWrite_T3writebus, CAN_BUS_tlc::_ProjectionRead_T3writebus::Hash, CAN_BUS_tlc::_ProjectionRead_T3writebus::HashEqual>, BSet<BTuple<BInteger, BInteger >>::SetHash, BSet<BTuple<BInteger, BInteger >>::SetHashEqual> _OpCache_T3writebus;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__tr_T3writebus,  BSet<BTuple<BInteger, BInteger >>, CAN_BUS_tlc::_ProjectionRead__tr_T3writebus::Hash, CAN_BUS_tlc::_ProjectionRead__tr_T3writebus::HashEqual> _OpCache_tr_T3writebus;
        std::mutex _ProjectionRead_T3writebus_mutex;
        std::mutex _ProjectionRead__tr_T3writebus_mutex;

        std::unordered_map<BSet<BTuple<BInteger, BInteger >>, std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3Read, CAN_BUS_tlc::_ProjectionWrite_T3Read, CAN_BUS_tlc::_ProjectionRead_T3Read::Hash, CAN_BUS_tlc::_ProjectionRead_T3Read::HashEqual>, BSet<BTuple<BInteger, BInteger >>::SetHash, BSet<BTuple<BInteger, BInteger >>::SetHashEqual> _OpCache_T3Read;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__tr_T3Read,  BSet<BTuple<BInteger, BInteger >>, CAN_BUS_tlc::_ProjectionRead__tr_T3Read::Hash, CAN_BUS_tlc::_ProjectionRead__tr_T3Read::HashEqual> _OpCache_tr_T3Read;
        std::mutex _ProjectionRead_T3Read_mutex;
        std::mutex _ProjectionRead__tr_T3Read_mutex;

        std::unordered_map<bool, std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3Poll, CAN_BUS_tlc::_ProjectionWrite_T3Poll, CAN_BUS_tlc::_ProjectionRead_T3Poll::Hash, CAN_BUS_tlc::_ProjectionRead_T3Poll::HashEqual>> _OpCache_T3Poll;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__tr_T3Poll, bool, CAN_BUS_tlc::_ProjectionRead__tr_T3Poll::Hash, CAN_BUS_tlc::_ProjectionRead__tr_T3Poll::HashEqual> _OpCache_tr_T3Poll;
        std::mutex _ProjectionRead_T3Poll_mutex;
        std::mutex _ProjectionRead__tr_T3Poll_mutex;

        std::unordered_map<BSet<BInteger>, std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3ReleaseBus, CAN_BUS_tlc::_ProjectionWrite_T3ReleaseBus, CAN_BUS_tlc::_ProjectionRead_T3ReleaseBus::Hash, CAN_BUS_tlc::_ProjectionRead_T3ReleaseBus::HashEqual>, BSet<BInteger>::SetHash, BSet<BInteger>::SetHashEqual> _OpCache_T3ReleaseBus;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__tr_T3ReleaseBus,  BSet<BInteger>, CAN_BUS_tlc::_ProjectionRead__tr_T3ReleaseBus::Hash, CAN_BUS_tlc::_ProjectionRead__tr_T3ReleaseBus::HashEqual> _OpCache_tr_T3ReleaseBus;
        std::mutex _ProjectionRead_T3ReleaseBus_mutex;
        std::mutex _ProjectionRead__tr_T3ReleaseBus_mutex;

        std::unordered_map<bool, std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3Wait, CAN_BUS_tlc::_ProjectionWrite_T3Wait, CAN_BUS_tlc::_ProjectionRead_T3Wait::Hash, CAN_BUS_tlc::_ProjectionRead_T3Wait::HashEqual>> _OpCache_T3Wait;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__tr_T3Wait, bool, CAN_BUS_tlc::_ProjectionRead__tr_T3Wait::Hash, CAN_BUS_tlc::_ProjectionRead__tr_T3Wait::HashEqual> _OpCache_tr_T3Wait;
        std::mutex _ProjectionRead_T3Wait_mutex;
        std::mutex _ProjectionRead__tr_T3Wait_mutex;

        std::unordered_map<bool, std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3ReEnableWait, CAN_BUS_tlc::_ProjectionWrite_T3ReEnableWait, CAN_BUS_tlc::_ProjectionRead_T3ReEnableWait::Hash, CAN_BUS_tlc::_ProjectionRead_T3ReEnableWait::HashEqual>> _OpCache_T3ReEnableWait;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__tr_T3ReEnableWait, bool, CAN_BUS_tlc::_ProjectionRead__tr_T3ReEnableWait::Hash, CAN_BUS_tlc::_ProjectionRead__tr_T3ReEnableWait::HashEqual> _OpCache_tr_T3ReEnableWait;
        std::mutex _ProjectionRead_T3ReEnableWait_mutex;
        std::mutex _ProjectionRead__tr_T3ReEnableWait_mutex;

        std::unordered_map<BSet<BInteger>, std::unordered_map<CAN_BUS_tlc::_ProjectionRead_Update, CAN_BUS_tlc::_ProjectionWrite_Update, CAN_BUS_tlc::_ProjectionRead_Update::Hash, CAN_BUS_tlc::_ProjectionRead_Update::HashEqual>, BSet<BInteger>::SetHash, BSet<BInteger>::SetHashEqual> _OpCache_Update;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__tr_Update,  BSet<BInteger>, CAN_BUS_tlc::_ProjectionRead__tr_Update::Hash, CAN_BUS_tlc::_ProjectionRead__tr_Update::HashEqual> _OpCache_tr_Update;
        std::mutex _ProjectionRead_Update_mutex;
        std::mutex _ProjectionRead__tr_Update_mutex;

        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__check_inv_1, bool, CAN_BUS_tlc::_ProjectionRead__check_inv_1::Hash, CAN_BUS_tlc::_ProjectionRead__check_inv_1::HashEqual> _InvCache__check_inv_1;
        std::mutex _ProjectionRead__check_inv_1_mutex;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__check_inv_2, bool, CAN_BUS_tlc::_ProjectionRead__check_inv_2::Hash, CAN_BUS_tlc::_ProjectionRead__check_inv_2::HashEqual> _InvCache__check_inv_2;
        std::mutex _ProjectionRead__check_inv_2_mutex;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__check_inv_3, bool, CAN_BUS_tlc::_ProjectionRead__check_inv_3::Hash, CAN_BUS_tlc::_ProjectionRead__check_inv_3::HashEqual> _InvCache__check_inv_3;
        std::mutex _ProjectionRead__check_inv_3_mutex;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__check_inv_4, bool, CAN_BUS_tlc::_ProjectionRead__check_inv_4::Hash, CAN_BUS_tlc::_ProjectionRead__check_inv_4::HashEqual> _InvCache__check_inv_4;
        std::mutex _ProjectionRead__check_inv_4_mutex;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__check_inv_5, bool, CAN_BUS_tlc::_ProjectionRead__check_inv_5::Hash, CAN_BUS_tlc::_ProjectionRead__check_inv_5::HashEqual> _InvCache__check_inv_5;
        std::mutex _ProjectionRead__check_inv_5_mutex;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__check_inv_6, bool, CAN_BUS_tlc::_ProjectionRead__check_inv_6::Hash, CAN_BUS_tlc::_ProjectionRead__check_inv_6::HashEqual> _InvCache__check_inv_6;
        std::mutex _ProjectionRead__check_inv_6_mutex;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__check_inv_7, bool, CAN_BUS_tlc::_ProjectionRead__check_inv_7::Hash, CAN_BUS_tlc::_ProjectionRead__check_inv_7::HashEqual> _InvCache__check_inv_7;
        std::mutex _ProjectionRead__check_inv_7_mutex;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__check_inv_8, bool, CAN_BUS_tlc::_ProjectionRead__check_inv_8::Hash, CAN_BUS_tlc::_ProjectionRead__check_inv_8::HashEqual> _InvCache__check_inv_8;
        std::mutex _ProjectionRead__check_inv_8_mutex;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__check_inv_9, bool, CAN_BUS_tlc::_ProjectionRead__check_inv_9::Hash, CAN_BUS_tlc::_ProjectionRead__check_inv_9::HashEqual> _InvCache__check_inv_9;
        std::mutex _ProjectionRead__check_inv_9_mutex;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__check_inv_10, bool, CAN_BUS_tlc::_ProjectionRead__check_inv_10::Hash, CAN_BUS_tlc::_ProjectionRead__check_inv_10::HashEqual> _InvCache__check_inv_10;
        std::mutex _ProjectionRead__check_inv_10_mutex;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__check_inv_11, bool, CAN_BUS_tlc::_ProjectionRead__check_inv_11::Hash, CAN_BUS_tlc::_ProjectionRead__check_inv_11::HashEqual> _InvCache__check_inv_11;
        std::mutex _ProjectionRead__check_inv_11_mutex;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__check_inv_12, bool, CAN_BUS_tlc::_ProjectionRead__check_inv_12::Hash, CAN_BUS_tlc::_ProjectionRead__check_inv_12::HashEqual> _InvCache__check_inv_12;
        std::mutex _ProjectionRead__check_inv_12_mutex;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__check_inv_13, bool, CAN_BUS_tlc::_ProjectionRead__check_inv_13::Hash, CAN_BUS_tlc::_ProjectionRead__check_inv_13::HashEqual> _InvCache__check_inv_13;
        std::mutex _ProjectionRead__check_inv_13_mutex;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__check_inv_14, bool, CAN_BUS_tlc::_ProjectionRead__check_inv_14::Hash, CAN_BUS_tlc::_ProjectionRead__check_inv_14::HashEqual> _InvCache__check_inv_14;
        std::mutex _ProjectionRead__check_inv_14_mutex;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__check_inv_15, bool, CAN_BUS_tlc::_ProjectionRead__check_inv_15::Hash, CAN_BUS_tlc::_ProjectionRead__check_inv_15::HashEqual> _InvCache__check_inv_15;
        std::mutex _ProjectionRead__check_inv_15_mutex;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__check_inv_16, bool, CAN_BUS_tlc::_ProjectionRead__check_inv_16::Hash, CAN_BUS_tlc::_ProjectionRead__check_inv_16::HashEqual> _InvCache__check_inv_16;
        std::mutex _ProjectionRead__check_inv_16_mutex;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__check_inv_17, bool, CAN_BUS_tlc::_ProjectionRead__check_inv_17::Hash, CAN_BUS_tlc::_ProjectionRead__check_inv_17::HashEqual> _InvCache__check_inv_17;
        std::mutex _ProjectionRead__check_inv_17_mutex;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__check_inv_18, bool, CAN_BUS_tlc::_ProjectionRead__check_inv_18::Hash, CAN_BUS_tlc::_ProjectionRead__check_inv_18::HashEqual> _InvCache__check_inv_18;
        std::mutex _ProjectionRead__check_inv_18_mutex;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__check_inv_19, bool, CAN_BUS_tlc::_ProjectionRead__check_inv_19::Hash, CAN_BUS_tlc::_ProjectionRead__check_inv_19::HashEqual> _InvCache__check_inv_19;
        std::mutex _ProjectionRead__check_inv_19_mutex;
        std::unordered_map<CAN_BUS_tlc::_ProjectionRead__check_inv_20, bool, CAN_BUS_tlc::_ProjectionRead__check_inv_20::Hash, CAN_BUS_tlc::_ProjectionRead__check_inv_20::HashEqual> _InvCache__check_inv_20;
        std::mutex _ProjectionRead__check_inv_20_mutex;

        std::unordered_map<CAN_BUS_tlc, CAN_BUS_tlc, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual> parents;

    public:
        ModelChecker() {}

        ModelChecker(CAN_BUS_tlc::Type type, int threads, bool isCaching, bool isDebug) {
            this->type = type;
            this->threads = threads;
            this->isCaching = isCaching;
            this->isDebug = isDebug;
            this->invariantViolatedBool = false;
            this->deadlockDetected = false;
            this->transitions = 0;
        }

        void modelCheck() {
            if (isDebug) {
                cout << "Starting Modelchecking, STRATEGY=" << type << ", THREADS=" << threads << ", CACHING=" << isCaching << "\n";
            }

            if (threads <= 1) {
                modelCheckSingleThreaded();
            } else {
                boost::asio::thread_pool workers(threads-1); // threads indicates the number of workers (without the coordinator)
                modelCheckMultiThreaded(workers);
            }
        }

        void modelCheckSingleThreaded() {
            CAN_BUS_tlc machine = CAN_BUS_tlc();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            while(!unvisitedStates.empty()) {
                CAN_BUS_tlc state = next();

                std::unordered_set<CAN_BUS_tlc, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual> nextStates = generateNextStates(state);

                for(auto& nextState : nextStates) {
                    if(states.find(nextState) == states.end()) {
                        states.insert(nextState);
                        parents.insert({nextState, state});
                        unvisitedStates.push_back(nextState);
                        if(isDebug && states.size() % 50000 == 0) {
                            cout << "VISITED STATES: " << states.size() << "\n";
                            cout << "EVALUATED TRANSITIONS: " << transitions << "\n";
                            cout << "-------------------" << "\n";
                        }
                    }
                }

                if(invariantViolated(state)) {
                    invariantViolatedBool = true;
                    counterExampleState = state;
                    break;
                }

                if(nextStates.empty()) {
                    deadlockDetected = true;
                    counterExampleState = state;
                    break;
                }

            }
            printResult();
        }

        void modelCheckMultiThreaded(boost::asio::thread_pool& workers) {
            CAN_BUS_tlc machine = CAN_BUS_tlc();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            std::atomic<bool> stopThreads(false);
            std::atomic<int> possibleQueueChanges;
            possibleQueueChanges = 0;

            while(!unvisitedStates.empty() && !stopThreads.load()) {
                possibleQueueChanges.fetch_add(1);
                CAN_BUS_tlc state = next();
                std::packaged_task<void()> task([&, state] {
                    std::unordered_set<CAN_BUS_tlc, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual> nextStates = generateNextStates(state);

                    for(auto& nextState : nextStates) {
                        {
                            std::unique_lock<std::mutex> lock(mutex);
                            if(states.find(nextState) == states.end()) {
                                states.insert(nextState);
                                parents.insert({nextState, state});
                                unvisitedStates.push_back(nextState);
                                if(isDebug && states.size() % 50000 == 0) {
                                    cout << "VISITED STATES: " << states.size() << "\n";
                                    cout << "EVALUATED TRANSITIONS: " << transitions << "\n";
                                    cout << "-------------------" << "\n";
                                }
                            }
                        }
                    }

                    possibleQueueChanges.fetch_sub(1);
                    {
                        std::unique_lock<std::mutex> lock(waitMutex);
                        if (!unvisitedStates.empty() || possibleQueueChanges.load() == 0) {
                            waitCV.notify_one();
                        }
                    }


                    if(invariantViolated(state)) {
                        invariantViolatedBool = true;
                        counterExampleState = state;
                        stopThreads.store(true);
                    }

                    if(nextStates.empty()) {
                        deadlockDetected = true;
                        counterExampleState = state;
                        stopThreads.store(true);
                    }

                });

                boost::asio::post(workers, std::move(task));

                {
                    std::unique_lock<std::mutex> lock(waitMutex);
                    waitCV.wait(lock, [&] {
                        return !unvisitedStates.empty() || possibleQueueChanges == 0;
                    });
                }
            }
            workers.join();
            printResult();
        }


    private:
        CAN_BUS_tlc next() {
            {
                std::unique_lock<std::mutex> lock(mutex);
                switch(type) {
                    case CAN_BUS_tlc::BFS: {
                        CAN_BUS_tlc state = unvisitedStates.front();
                        unvisitedStates.pop_front();
                        return state;
                    }
                    case CAN_BUS_tlc::DFS: {
                        CAN_BUS_tlc state = unvisitedStates.back();
                        unvisitedStates.pop_back();
                        return state;
                    }
                    case CAN_BUS_tlc::MIXED: {
                        if(unvisitedStates.size() % 2 == 0) {
                            CAN_BUS_tlc state = unvisitedStates.front();
                            unvisitedStates.pop_front();
                            return state;
                        } else {
                            CAN_BUS_tlc state = unvisitedStates.back();
                            unvisitedStates.pop_back();
                            return state;
                        }
                    }
                }
                CAN_BUS_tlc state = unvisitedStates.front();
                unvisitedStates.pop_front();
                return state;
            };
        }

        std::unordered_set<CAN_BUS_tlc, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual> generateNextStates(const CAN_BUS_tlc& state) {
            std::unordered_set<CAN_BUS_tlc, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual> result = std::unordered_set<CAN_BUS_tlc, CAN_BUS_tlc::Hash, CAN_BUS_tlc::HashEqual>();
            if(isCaching) {
                CAN_BUS_tlc::_ProjectionRead__tr_T1Evaluate read__tr_T1Evaluate_state = state._projected_state_for__tr_T1Evaluate();
                bool _trid_1;
                auto _obj__trid_1_ptr = _OpCache_tr_T1Evaluate.find(read__tr_T1Evaluate_state);
                if(_obj__trid_1_ptr == _OpCache_tr_T1Evaluate.end()) {
                    _trid_1 = state._tr_T1Evaluate();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_T1Evaluate_lock(_ProjectionRead__tr_T1Evaluate_mutex);
                        _OpCache_tr_T1Evaluate.insert({read__tr_T1Evaluate_state, _trid_1});
                    }
                } else {
                    _trid_1 = _obj__trid_1_ptr->second;
                }
                if(_trid_1) {
                    CAN_BUS_tlc copiedState = state._copy();
                    CAN_BUS_tlc::_ProjectionRead_T1Evaluate readState = state._projected_state_for_T1Evaluate();

                    auto _OpCache_with_parameter_T1Evaluate_ptr = _OpCache_T1Evaluate.find(_trid_1);
                    if(_OpCache_with_parameter_T1Evaluate_ptr == _OpCache_T1Evaluate.end()) {
                        copiedState.T1Evaluate();
                        CAN_BUS_tlc::_ProjectionWrite_T1Evaluate writeState = copiedState._update_for_T1Evaluate();
                        std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T1Evaluate, CAN_BUS_tlc::_ProjectionWrite_T1Evaluate, CAN_BUS_tlc::_ProjectionRead_T1Evaluate::Hash, CAN_BUS_tlc::_ProjectionRead_T1Evaluate::HashEqual> _OpCache_with_parameter_T1Evaluate;
                        _OpCache_with_parameter_T1Evaluate.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_T1Evaluate_lock(_ProjectionRead_T1Evaluate_mutex);
                            _OpCache_T1Evaluate.insert({_trid_1, _OpCache_with_parameter_T1Evaluate});
                        }

                    } else {
                        std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T1Evaluate, CAN_BUS_tlc::_ProjectionWrite_T1Evaluate, CAN_BUS_tlc::_ProjectionRead_T1Evaluate::Hash, CAN_BUS_tlc::_ProjectionRead_T1Evaluate::HashEqual> _OpCache_with_parameter_T1Evaluate = _OpCache_with_parameter_T1Evaluate_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_T1Evaluate.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_T1Evaluate.end()) {
                            CAN_BUS_tlc::_ProjectionWrite_T1Evaluate writeState = writeState_ptr->second;
                            copiedState._apply_update_for_T1Evaluate(writeState);
                        } else {
                            copiedState.T1Evaluate();
                            CAN_BUS_tlc::_ProjectionWrite_T1Evaluate writeState = copiedState._update_for_T1Evaluate();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T1Evaluate_lock(_ProjectionRead_T1Evaluate_mutex);
                                _OpCache_with_parameter_T1Evaluate.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "T1Evaluate";
                    result.insert(copiedState);
                    transitions += 1;
                }
                CAN_BUS_tlc::_ProjectionRead__tr_T1Calculate read__tr_T1Calculate_state = state._projected_state_for__tr_T1Calculate();
                auto _trid_2_ptr = _OpCache_tr_T1Calculate.find(read__tr_T1Calculate_state);
                if(_trid_2_ptr == _OpCache_tr_T1Calculate.end()) {
                    BSet<BInteger> _trid_2 = state._tr_T1Calculate();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_T1Calculate_lock(_ProjectionRead__tr_T1Calculate_mutex);
                        _OpCache_tr_T1Calculate.insert({read__tr_T1Calculate_state, _trid_2});
                    }
                    for(const BInteger& param : _trid_2) {
                        BInteger _tmp_1 = param;

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_T1Calculate readState = state._projected_state_for_T1Calculate();

                        auto _OpCache_with_parameter_T1Calculate_ptr = _OpCache_T1Calculate.find(param);
                        if(_OpCache_with_parameter_T1Calculate_ptr == _OpCache_T1Calculate.end()) {
                            copiedState.T1Calculate(_tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_T1Calculate writeState = copiedState._update_for_T1Calculate();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T1Calculate, CAN_BUS_tlc::_ProjectionWrite_T1Calculate, CAN_BUS_tlc::_ProjectionRead_T1Calculate::Hash, CAN_BUS_tlc::_ProjectionRead_T1Calculate::HashEqual> _OpCache_with_parameter_T1Calculate;
                            _OpCache_with_parameter_T1Calculate.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T1Calculate_lock(_ProjectionRead_T1Calculate_mutex);
                                _OpCache_T1Calculate.insert({param, _OpCache_with_parameter_T1Calculate});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T1Calculate, CAN_BUS_tlc::_ProjectionWrite_T1Calculate, CAN_BUS_tlc::_ProjectionRead_T1Calculate::Hash, CAN_BUS_tlc::_ProjectionRead_T1Calculate::HashEqual> _OpCache_with_parameter_T1Calculate = _OpCache_with_parameter_T1Calculate_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_T1Calculate.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_T1Calculate.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_T1Calculate writeState = writeState_ptr->second;
                                copiedState._apply_update_for_T1Calculate(writeState);
                            } else {
                                copiedState.T1Calculate(_tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_T1Calculate writeState = copiedState._update_for_T1Calculate();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_T1Calculate_lock(_ProjectionRead_T1Calculate_mutex);
                                    _OpCache_with_parameter_T1Calculate.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "T1Calculate";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BInteger> _trid_2 = _trid_2_ptr->second;
                    for(const BInteger& param : _trid_2) {
                        BInteger _tmp_1 = param;

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_T1Calculate readState = state._projected_state_for_T1Calculate();

                        auto _OpCache_with_parameter_T1Calculate_ptr = _OpCache_T1Calculate.find(param);
                        if(_OpCache_with_parameter_T1Calculate_ptr == _OpCache_T1Calculate.end()) {
                            copiedState.T1Calculate(_tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_T1Calculate writeState = copiedState._update_for_T1Calculate();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T1Calculate, CAN_BUS_tlc::_ProjectionWrite_T1Calculate, CAN_BUS_tlc::_ProjectionRead_T1Calculate::Hash, CAN_BUS_tlc::_ProjectionRead_T1Calculate::HashEqual> _OpCache_with_parameter_T1Calculate;
                            _OpCache_with_parameter_T1Calculate.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T1Calculate_lock(_ProjectionRead_T1Calculate_mutex);
                                _OpCache_T1Calculate.insert({param, _OpCache_with_parameter_T1Calculate});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T1Calculate, CAN_BUS_tlc::_ProjectionWrite_T1Calculate, CAN_BUS_tlc::_ProjectionRead_T1Calculate::Hash, CAN_BUS_tlc::_ProjectionRead_T1Calculate::HashEqual> _OpCache_with_parameter_T1Calculate = _OpCache_with_parameter_T1Calculate_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_T1Calculate.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_T1Calculate.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_T1Calculate writeState = writeState_ptr->second;
                                copiedState._apply_update_for_T1Calculate(writeState);
                            } else {
                                copiedState.T1Calculate(_tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_T1Calculate writeState = copiedState._update_for_T1Calculate();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_T1Calculate_lock(_ProjectionRead_T1Calculate_mutex);
                                    _OpCache_with_parameter_T1Calculate.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "T1Calculate";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                CAN_BUS_tlc::_ProjectionRead__tr_T1SendResult read__tr_T1SendResult_state = state._projected_state_for__tr_T1SendResult();
                auto _trid_3_ptr = _OpCache_tr_T1SendResult.find(read__tr_T1SendResult_state);
                if(_trid_3_ptr == _OpCache_tr_T1SendResult.end()) {
                    BSet<BTuple<BInteger, BInteger >> _trid_3 = state._tr_T1SendResult();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_T1SendResult_lock(_ProjectionRead__tr_T1SendResult_mutex);
                        _OpCache_tr_T1SendResult.insert({read__tr_T1SendResult_state, _trid_3});
                    }
                    for(const BTuple<BInteger, BInteger >& param : _trid_3) {
                        BInteger _tmp_1 = param.projection2();
                        BInteger _tmp_2 = param.projection1();

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_T1SendResult readState = state._projected_state_for_T1SendResult();

                        auto _OpCache_with_parameter_T1SendResult_ptr = _OpCache_T1SendResult.find(param);
                        if(_OpCache_with_parameter_T1SendResult_ptr == _OpCache_T1SendResult.end()) {
                            copiedState.T1SendResult(_tmp_2, _tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_T1SendResult writeState = copiedState._update_for_T1SendResult();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T1SendResult, CAN_BUS_tlc::_ProjectionWrite_T1SendResult, CAN_BUS_tlc::_ProjectionRead_T1SendResult::Hash, CAN_BUS_tlc::_ProjectionRead_T1SendResult::HashEqual> _OpCache_with_parameter_T1SendResult;
                            _OpCache_with_parameter_T1SendResult.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T1SendResult_lock(_ProjectionRead_T1SendResult_mutex);
                                _OpCache_T1SendResult.insert({param, _OpCache_with_parameter_T1SendResult});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T1SendResult, CAN_BUS_tlc::_ProjectionWrite_T1SendResult, CAN_BUS_tlc::_ProjectionRead_T1SendResult::Hash, CAN_BUS_tlc::_ProjectionRead_T1SendResult::HashEqual> _OpCache_with_parameter_T1SendResult = _OpCache_with_parameter_T1SendResult_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_T1SendResult.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_T1SendResult.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_T1SendResult writeState = writeState_ptr->second;
                                copiedState._apply_update_for_T1SendResult(writeState);
                            } else {
                                copiedState.T1SendResult(_tmp_2, _tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_T1SendResult writeState = copiedState._update_for_T1SendResult();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_T1SendResult_lock(_ProjectionRead_T1SendResult_mutex);
                                    _OpCache_with_parameter_T1SendResult.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "T1SendResult";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BTuple<BInteger, BInteger >> _trid_3 = _trid_3_ptr->second;
                    for(const BTuple<BInteger, BInteger >& param : _trid_3) {
                        BInteger _tmp_1 = param.projection2();
                        BInteger _tmp_2 = param.projection1();

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_T1SendResult readState = state._projected_state_for_T1SendResult();

                        auto _OpCache_with_parameter_T1SendResult_ptr = _OpCache_T1SendResult.find(param);
                        if(_OpCache_with_parameter_T1SendResult_ptr == _OpCache_T1SendResult.end()) {
                            copiedState.T1SendResult(_tmp_2, _tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_T1SendResult writeState = copiedState._update_for_T1SendResult();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T1SendResult, CAN_BUS_tlc::_ProjectionWrite_T1SendResult, CAN_BUS_tlc::_ProjectionRead_T1SendResult::Hash, CAN_BUS_tlc::_ProjectionRead_T1SendResult::HashEqual> _OpCache_with_parameter_T1SendResult;
                            _OpCache_with_parameter_T1SendResult.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T1SendResult_lock(_ProjectionRead_T1SendResult_mutex);
                                _OpCache_T1SendResult.insert({param, _OpCache_with_parameter_T1SendResult});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T1SendResult, CAN_BUS_tlc::_ProjectionWrite_T1SendResult, CAN_BUS_tlc::_ProjectionRead_T1SendResult::Hash, CAN_BUS_tlc::_ProjectionRead_T1SendResult::HashEqual> _OpCache_with_parameter_T1SendResult = _OpCache_with_parameter_T1SendResult_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_T1SendResult.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_T1SendResult.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_T1SendResult writeState = writeState_ptr->second;
                                copiedState._apply_update_for_T1SendResult(writeState);
                            } else {
                                copiedState.T1SendResult(_tmp_2, _tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_T1SendResult writeState = copiedState._update_for_T1SendResult();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_T1SendResult_lock(_ProjectionRead_T1SendResult_mutex);
                                    _OpCache_with_parameter_T1SendResult.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "T1SendResult";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                CAN_BUS_tlc::_ProjectionRead__tr_T1Wait read__tr_T1Wait_state = state._projected_state_for__tr_T1Wait();
                auto _trid_4_ptr = _OpCache_tr_T1Wait.find(read__tr_T1Wait_state);
                if(_trid_4_ptr == _OpCache_tr_T1Wait.end()) {
                    BSet<BInteger> _trid_4 = state._tr_T1Wait();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_T1Wait_lock(_ProjectionRead__tr_T1Wait_mutex);
                        _OpCache_tr_T1Wait.insert({read__tr_T1Wait_state, _trid_4});
                    }
                    for(const BInteger& param : _trid_4) {
                        BInteger _tmp_1 = param;

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_T1Wait readState = state._projected_state_for_T1Wait();

                        auto _OpCache_with_parameter_T1Wait_ptr = _OpCache_T1Wait.find(param);
                        if(_OpCache_with_parameter_T1Wait_ptr == _OpCache_T1Wait.end()) {
                            copiedState.T1Wait(_tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_T1Wait writeState = copiedState._update_for_T1Wait();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T1Wait, CAN_BUS_tlc::_ProjectionWrite_T1Wait, CAN_BUS_tlc::_ProjectionRead_T1Wait::Hash, CAN_BUS_tlc::_ProjectionRead_T1Wait::HashEqual> _OpCache_with_parameter_T1Wait;
                            _OpCache_with_parameter_T1Wait.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T1Wait_lock(_ProjectionRead_T1Wait_mutex);
                                _OpCache_T1Wait.insert({param, _OpCache_with_parameter_T1Wait});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T1Wait, CAN_BUS_tlc::_ProjectionWrite_T1Wait, CAN_BUS_tlc::_ProjectionRead_T1Wait::Hash, CAN_BUS_tlc::_ProjectionRead_T1Wait::HashEqual> _OpCache_with_parameter_T1Wait = _OpCache_with_parameter_T1Wait_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_T1Wait.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_T1Wait.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_T1Wait writeState = writeState_ptr->second;
                                copiedState._apply_update_for_T1Wait(writeState);
                            } else {
                                copiedState.T1Wait(_tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_T1Wait writeState = copiedState._update_for_T1Wait();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_T1Wait_lock(_ProjectionRead_T1Wait_mutex);
                                    _OpCache_with_parameter_T1Wait.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "T1Wait";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BInteger> _trid_4 = _trid_4_ptr->second;
                    for(const BInteger& param : _trid_4) {
                        BInteger _tmp_1 = param;

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_T1Wait readState = state._projected_state_for_T1Wait();

                        auto _OpCache_with_parameter_T1Wait_ptr = _OpCache_T1Wait.find(param);
                        if(_OpCache_with_parameter_T1Wait_ptr == _OpCache_T1Wait.end()) {
                            copiedState.T1Wait(_tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_T1Wait writeState = copiedState._update_for_T1Wait();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T1Wait, CAN_BUS_tlc::_ProjectionWrite_T1Wait, CAN_BUS_tlc::_ProjectionRead_T1Wait::Hash, CAN_BUS_tlc::_ProjectionRead_T1Wait::HashEqual> _OpCache_with_parameter_T1Wait;
                            _OpCache_with_parameter_T1Wait.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T1Wait_lock(_ProjectionRead_T1Wait_mutex);
                                _OpCache_T1Wait.insert({param, _OpCache_with_parameter_T1Wait});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T1Wait, CAN_BUS_tlc::_ProjectionWrite_T1Wait, CAN_BUS_tlc::_ProjectionRead_T1Wait::Hash, CAN_BUS_tlc::_ProjectionRead_T1Wait::HashEqual> _OpCache_with_parameter_T1Wait = _OpCache_with_parameter_T1Wait_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_T1Wait.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_T1Wait.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_T1Wait writeState = writeState_ptr->second;
                                copiedState._apply_update_for_T1Wait(writeState);
                            } else {
                                copiedState.T1Wait(_tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_T1Wait writeState = copiedState._update_for_T1Wait();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_T1Wait_lock(_ProjectionRead_T1Wait_mutex);
                                    _OpCache_with_parameter_T1Wait.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "T1Wait";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                CAN_BUS_tlc::_ProjectionRead__tr_T2Evaluate read__tr_T2Evaluate_state = state._projected_state_for__tr_T2Evaluate();
                bool _trid_5;
                auto _obj__trid_5_ptr = _OpCache_tr_T2Evaluate.find(read__tr_T2Evaluate_state);
                if(_obj__trid_5_ptr == _OpCache_tr_T2Evaluate.end()) {
                    _trid_5 = state._tr_T2Evaluate();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_T2Evaluate_lock(_ProjectionRead__tr_T2Evaluate_mutex);
                        _OpCache_tr_T2Evaluate.insert({read__tr_T2Evaluate_state, _trid_5});
                    }
                } else {
                    _trid_5 = _obj__trid_5_ptr->second;
                }
                if(_trid_5) {
                    CAN_BUS_tlc copiedState = state._copy();
                    CAN_BUS_tlc::_ProjectionRead_T2Evaluate readState = state._projected_state_for_T2Evaluate();

                    auto _OpCache_with_parameter_T2Evaluate_ptr = _OpCache_T2Evaluate.find(_trid_5);
                    if(_OpCache_with_parameter_T2Evaluate_ptr == _OpCache_T2Evaluate.end()) {
                        copiedState.T2Evaluate();
                        CAN_BUS_tlc::_ProjectionWrite_T2Evaluate writeState = copiedState._update_for_T2Evaluate();
                        std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2Evaluate, CAN_BUS_tlc::_ProjectionWrite_T2Evaluate, CAN_BUS_tlc::_ProjectionRead_T2Evaluate::Hash, CAN_BUS_tlc::_ProjectionRead_T2Evaluate::HashEqual> _OpCache_with_parameter_T2Evaluate;
                        _OpCache_with_parameter_T2Evaluate.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_T2Evaluate_lock(_ProjectionRead_T2Evaluate_mutex);
                            _OpCache_T2Evaluate.insert({_trid_5, _OpCache_with_parameter_T2Evaluate});
                        }

                    } else {
                        std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2Evaluate, CAN_BUS_tlc::_ProjectionWrite_T2Evaluate, CAN_BUS_tlc::_ProjectionRead_T2Evaluate::Hash, CAN_BUS_tlc::_ProjectionRead_T2Evaluate::HashEqual> _OpCache_with_parameter_T2Evaluate = _OpCache_with_parameter_T2Evaluate_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_T2Evaluate.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_T2Evaluate.end()) {
                            CAN_BUS_tlc::_ProjectionWrite_T2Evaluate writeState = writeState_ptr->second;
                            copiedState._apply_update_for_T2Evaluate(writeState);
                        } else {
                            copiedState.T2Evaluate();
                            CAN_BUS_tlc::_ProjectionWrite_T2Evaluate writeState = copiedState._update_for_T2Evaluate();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T2Evaluate_lock(_ProjectionRead_T2Evaluate_mutex);
                                _OpCache_with_parameter_T2Evaluate.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "T2Evaluate";
                    result.insert(copiedState);
                    transitions += 1;
                }
                CAN_BUS_tlc::_ProjectionRead__tr_T2ReadBus read__tr_T2ReadBus_state = state._projected_state_for__tr_T2ReadBus();
                auto _trid_6_ptr = _OpCache_tr_T2ReadBus.find(read__tr_T2ReadBus_state);
                if(_trid_6_ptr == _OpCache_tr_T2ReadBus.end()) {
                    BSet<BTuple<BInteger, BInteger >> _trid_6 = state._tr_T2ReadBus();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_T2ReadBus_lock(_ProjectionRead__tr_T2ReadBus_mutex);
                        _OpCache_tr_T2ReadBus.insert({read__tr_T2ReadBus_state, _trid_6});
                    }
                    for(const BTuple<BInteger, BInteger >& param : _trid_6) {
                        BInteger _tmp_1 = param.projection2();
                        BInteger _tmp_2 = param.projection1();

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_T2ReadBus readState = state._projected_state_for_T2ReadBus();

                        auto _OpCache_with_parameter_T2ReadBus_ptr = _OpCache_T2ReadBus.find(param);
                        if(_OpCache_with_parameter_T2ReadBus_ptr == _OpCache_T2ReadBus.end()) {
                            copiedState.T2ReadBus(_tmp_2, _tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_T2ReadBus writeState = copiedState._update_for_T2ReadBus();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2ReadBus, CAN_BUS_tlc::_ProjectionWrite_T2ReadBus, CAN_BUS_tlc::_ProjectionRead_T2ReadBus::Hash, CAN_BUS_tlc::_ProjectionRead_T2ReadBus::HashEqual> _OpCache_with_parameter_T2ReadBus;
                            _OpCache_with_parameter_T2ReadBus.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T2ReadBus_lock(_ProjectionRead_T2ReadBus_mutex);
                                _OpCache_T2ReadBus.insert({param, _OpCache_with_parameter_T2ReadBus});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2ReadBus, CAN_BUS_tlc::_ProjectionWrite_T2ReadBus, CAN_BUS_tlc::_ProjectionRead_T2ReadBus::Hash, CAN_BUS_tlc::_ProjectionRead_T2ReadBus::HashEqual> _OpCache_with_parameter_T2ReadBus = _OpCache_with_parameter_T2ReadBus_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_T2ReadBus.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_T2ReadBus.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_T2ReadBus writeState = writeState_ptr->second;
                                copiedState._apply_update_for_T2ReadBus(writeState);
                            } else {
                                copiedState.T2ReadBus(_tmp_2, _tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_T2ReadBus writeState = copiedState._update_for_T2ReadBus();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_T2ReadBus_lock(_ProjectionRead_T2ReadBus_mutex);
                                    _OpCache_with_parameter_T2ReadBus.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "T2ReadBus";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BTuple<BInteger, BInteger >> _trid_6 = _trid_6_ptr->second;
                    for(const BTuple<BInteger, BInteger >& param : _trid_6) {
                        BInteger _tmp_1 = param.projection2();
                        BInteger _tmp_2 = param.projection1();

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_T2ReadBus readState = state._projected_state_for_T2ReadBus();

                        auto _OpCache_with_parameter_T2ReadBus_ptr = _OpCache_T2ReadBus.find(param);
                        if(_OpCache_with_parameter_T2ReadBus_ptr == _OpCache_T2ReadBus.end()) {
                            copiedState.T2ReadBus(_tmp_2, _tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_T2ReadBus writeState = copiedState._update_for_T2ReadBus();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2ReadBus, CAN_BUS_tlc::_ProjectionWrite_T2ReadBus, CAN_BUS_tlc::_ProjectionRead_T2ReadBus::Hash, CAN_BUS_tlc::_ProjectionRead_T2ReadBus::HashEqual> _OpCache_with_parameter_T2ReadBus;
                            _OpCache_with_parameter_T2ReadBus.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T2ReadBus_lock(_ProjectionRead_T2ReadBus_mutex);
                                _OpCache_T2ReadBus.insert({param, _OpCache_with_parameter_T2ReadBus});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2ReadBus, CAN_BUS_tlc::_ProjectionWrite_T2ReadBus, CAN_BUS_tlc::_ProjectionRead_T2ReadBus::Hash, CAN_BUS_tlc::_ProjectionRead_T2ReadBus::HashEqual> _OpCache_with_parameter_T2ReadBus = _OpCache_with_parameter_T2ReadBus_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_T2ReadBus.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_T2ReadBus.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_T2ReadBus writeState = writeState_ptr->second;
                                copiedState._apply_update_for_T2ReadBus(writeState);
                            } else {
                                copiedState.T2ReadBus(_tmp_2, _tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_T2ReadBus writeState = copiedState._update_for_T2ReadBus();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_T2ReadBus_lock(_ProjectionRead_T2ReadBus_mutex);
                                    _OpCache_with_parameter_T2ReadBus.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "T2ReadBus";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                CAN_BUS_tlc::_ProjectionRead__tr_T2Reset read__tr_T2Reset_state = state._projected_state_for__tr_T2Reset();
                bool _trid_7;
                auto _obj__trid_7_ptr = _OpCache_tr_T2Reset.find(read__tr_T2Reset_state);
                if(_obj__trid_7_ptr == _OpCache_tr_T2Reset.end()) {
                    _trid_7 = state._tr_T2Reset();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_T2Reset_lock(_ProjectionRead__tr_T2Reset_mutex);
                        _OpCache_tr_T2Reset.insert({read__tr_T2Reset_state, _trid_7});
                    }
                } else {
                    _trid_7 = _obj__trid_7_ptr->second;
                }
                if(_trid_7) {
                    CAN_BUS_tlc copiedState = state._copy();
                    CAN_BUS_tlc::_ProjectionRead_T2Reset readState = state._projected_state_for_T2Reset();

                    auto _OpCache_with_parameter_T2Reset_ptr = _OpCache_T2Reset.find(_trid_7);
                    if(_OpCache_with_parameter_T2Reset_ptr == _OpCache_T2Reset.end()) {
                        copiedState.T2Reset();
                        CAN_BUS_tlc::_ProjectionWrite_T2Reset writeState = copiedState._update_for_T2Reset();
                        std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2Reset, CAN_BUS_tlc::_ProjectionWrite_T2Reset, CAN_BUS_tlc::_ProjectionRead_T2Reset::Hash, CAN_BUS_tlc::_ProjectionRead_T2Reset::HashEqual> _OpCache_with_parameter_T2Reset;
                        _OpCache_with_parameter_T2Reset.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_T2Reset_lock(_ProjectionRead_T2Reset_mutex);
                            _OpCache_T2Reset.insert({_trid_7, _OpCache_with_parameter_T2Reset});
                        }

                    } else {
                        std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2Reset, CAN_BUS_tlc::_ProjectionWrite_T2Reset, CAN_BUS_tlc::_ProjectionRead_T2Reset::Hash, CAN_BUS_tlc::_ProjectionRead_T2Reset::HashEqual> _OpCache_with_parameter_T2Reset = _OpCache_with_parameter_T2Reset_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_T2Reset.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_T2Reset.end()) {
                            CAN_BUS_tlc::_ProjectionWrite_T2Reset writeState = writeState_ptr->second;
                            copiedState._apply_update_for_T2Reset(writeState);
                        } else {
                            copiedState.T2Reset();
                            CAN_BUS_tlc::_ProjectionWrite_T2Reset writeState = copiedState._update_for_T2Reset();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T2Reset_lock(_ProjectionRead_T2Reset_mutex);
                                _OpCache_with_parameter_T2Reset.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "T2Reset";
                    result.insert(copiedState);
                    transitions += 1;
                }
                CAN_BUS_tlc::_ProjectionRead__tr_T2Complete read__tr_T2Complete_state = state._projected_state_for__tr_T2Complete();
                bool _trid_8;
                auto _obj__trid_8_ptr = _OpCache_tr_T2Complete.find(read__tr_T2Complete_state);
                if(_obj__trid_8_ptr == _OpCache_tr_T2Complete.end()) {
                    _trid_8 = state._tr_T2Complete();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_T2Complete_lock(_ProjectionRead__tr_T2Complete_mutex);
                        _OpCache_tr_T2Complete.insert({read__tr_T2Complete_state, _trid_8});
                    }
                } else {
                    _trid_8 = _obj__trid_8_ptr->second;
                }
                if(_trid_8) {
                    CAN_BUS_tlc copiedState = state._copy();
                    CAN_BUS_tlc::_ProjectionRead_T2Complete readState = state._projected_state_for_T2Complete();

                    auto _OpCache_with_parameter_T2Complete_ptr = _OpCache_T2Complete.find(_trid_8);
                    if(_OpCache_with_parameter_T2Complete_ptr == _OpCache_T2Complete.end()) {
                        copiedState.T2Complete();
                        CAN_BUS_tlc::_ProjectionWrite_T2Complete writeState = copiedState._update_for_T2Complete();
                        std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2Complete, CAN_BUS_tlc::_ProjectionWrite_T2Complete, CAN_BUS_tlc::_ProjectionRead_T2Complete::Hash, CAN_BUS_tlc::_ProjectionRead_T2Complete::HashEqual> _OpCache_with_parameter_T2Complete;
                        _OpCache_with_parameter_T2Complete.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_T2Complete_lock(_ProjectionRead_T2Complete_mutex);
                            _OpCache_T2Complete.insert({_trid_8, _OpCache_with_parameter_T2Complete});
                        }

                    } else {
                        std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2Complete, CAN_BUS_tlc::_ProjectionWrite_T2Complete, CAN_BUS_tlc::_ProjectionRead_T2Complete::Hash, CAN_BUS_tlc::_ProjectionRead_T2Complete::HashEqual> _OpCache_with_parameter_T2Complete = _OpCache_with_parameter_T2Complete_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_T2Complete.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_T2Complete.end()) {
                            CAN_BUS_tlc::_ProjectionWrite_T2Complete writeState = writeState_ptr->second;
                            copiedState._apply_update_for_T2Complete(writeState);
                        } else {
                            copiedState.T2Complete();
                            CAN_BUS_tlc::_ProjectionWrite_T2Complete writeState = copiedState._update_for_T2Complete();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T2Complete_lock(_ProjectionRead_T2Complete_mutex);
                                _OpCache_with_parameter_T2Complete.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "T2Complete";
                    result.insert(copiedState);
                    transitions += 1;
                }
                CAN_BUS_tlc::_ProjectionRead__tr_T2ReleaseBus read__tr_T2ReleaseBus_state = state._projected_state_for__tr_T2ReleaseBus();
                auto _trid_9_ptr = _OpCache_tr_T2ReleaseBus.find(read__tr_T2ReleaseBus_state);
                if(_trid_9_ptr == _OpCache_tr_T2ReleaseBus.end()) {
                    BSet<BInteger> _trid_9 = state._tr_T2ReleaseBus();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_T2ReleaseBus_lock(_ProjectionRead__tr_T2ReleaseBus_mutex);
                        _OpCache_tr_T2ReleaseBus.insert({read__tr_T2ReleaseBus_state, _trid_9});
                    }
                    for(const BInteger& param : _trid_9) {
                        BInteger _tmp_1 = param;

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_T2ReleaseBus readState = state._projected_state_for_T2ReleaseBus();

                        auto _OpCache_with_parameter_T2ReleaseBus_ptr = _OpCache_T2ReleaseBus.find(param);
                        if(_OpCache_with_parameter_T2ReleaseBus_ptr == _OpCache_T2ReleaseBus.end()) {
                            copiedState.T2ReleaseBus(_tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_T2ReleaseBus writeState = copiedState._update_for_T2ReleaseBus();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2ReleaseBus, CAN_BUS_tlc::_ProjectionWrite_T2ReleaseBus, CAN_BUS_tlc::_ProjectionRead_T2ReleaseBus::Hash, CAN_BUS_tlc::_ProjectionRead_T2ReleaseBus::HashEqual> _OpCache_with_parameter_T2ReleaseBus;
                            _OpCache_with_parameter_T2ReleaseBus.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T2ReleaseBus_lock(_ProjectionRead_T2ReleaseBus_mutex);
                                _OpCache_T2ReleaseBus.insert({param, _OpCache_with_parameter_T2ReleaseBus});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2ReleaseBus, CAN_BUS_tlc::_ProjectionWrite_T2ReleaseBus, CAN_BUS_tlc::_ProjectionRead_T2ReleaseBus::Hash, CAN_BUS_tlc::_ProjectionRead_T2ReleaseBus::HashEqual> _OpCache_with_parameter_T2ReleaseBus = _OpCache_with_parameter_T2ReleaseBus_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_T2ReleaseBus.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_T2ReleaseBus.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_T2ReleaseBus writeState = writeState_ptr->second;
                                copiedState._apply_update_for_T2ReleaseBus(writeState);
                            } else {
                                copiedState.T2ReleaseBus(_tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_T2ReleaseBus writeState = copiedState._update_for_T2ReleaseBus();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_T2ReleaseBus_lock(_ProjectionRead_T2ReleaseBus_mutex);
                                    _OpCache_with_parameter_T2ReleaseBus.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "T2ReleaseBus";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BInteger> _trid_9 = _trid_9_ptr->second;
                    for(const BInteger& param : _trid_9) {
                        BInteger _tmp_1 = param;

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_T2ReleaseBus readState = state._projected_state_for_T2ReleaseBus();

                        auto _OpCache_with_parameter_T2ReleaseBus_ptr = _OpCache_T2ReleaseBus.find(param);
                        if(_OpCache_with_parameter_T2ReleaseBus_ptr == _OpCache_T2ReleaseBus.end()) {
                            copiedState.T2ReleaseBus(_tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_T2ReleaseBus writeState = copiedState._update_for_T2ReleaseBus();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2ReleaseBus, CAN_BUS_tlc::_ProjectionWrite_T2ReleaseBus, CAN_BUS_tlc::_ProjectionRead_T2ReleaseBus::Hash, CAN_BUS_tlc::_ProjectionRead_T2ReleaseBus::HashEqual> _OpCache_with_parameter_T2ReleaseBus;
                            _OpCache_with_parameter_T2ReleaseBus.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T2ReleaseBus_lock(_ProjectionRead_T2ReleaseBus_mutex);
                                _OpCache_T2ReleaseBus.insert({param, _OpCache_with_parameter_T2ReleaseBus});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2ReleaseBus, CAN_BUS_tlc::_ProjectionWrite_T2ReleaseBus, CAN_BUS_tlc::_ProjectionRead_T2ReleaseBus::Hash, CAN_BUS_tlc::_ProjectionRead_T2ReleaseBus::HashEqual> _OpCache_with_parameter_T2ReleaseBus = _OpCache_with_parameter_T2ReleaseBus_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_T2ReleaseBus.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_T2ReleaseBus.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_T2ReleaseBus writeState = writeState_ptr->second;
                                copiedState._apply_update_for_T2ReleaseBus(writeState);
                            } else {
                                copiedState.T2ReleaseBus(_tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_T2ReleaseBus writeState = copiedState._update_for_T2ReleaseBus();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_T2ReleaseBus_lock(_ProjectionRead_T2ReleaseBus_mutex);
                                    _OpCache_with_parameter_T2ReleaseBus.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "T2ReleaseBus";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                CAN_BUS_tlc::_ProjectionRead__tr_T2Calculate read__tr_T2Calculate_state = state._projected_state_for__tr_T2Calculate();
                bool _trid_10;
                auto _obj__trid_10_ptr = _OpCache_tr_T2Calculate.find(read__tr_T2Calculate_state);
                if(_obj__trid_10_ptr == _OpCache_tr_T2Calculate.end()) {
                    _trid_10 = state._tr_T2Calculate();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_T2Calculate_lock(_ProjectionRead__tr_T2Calculate_mutex);
                        _OpCache_tr_T2Calculate.insert({read__tr_T2Calculate_state, _trid_10});
                    }
                } else {
                    _trid_10 = _obj__trid_10_ptr->second;
                }
                if(_trid_10) {
                    CAN_BUS_tlc copiedState = state._copy();
                    CAN_BUS_tlc::_ProjectionRead_T2Calculate readState = state._projected_state_for_T2Calculate();

                    auto _OpCache_with_parameter_T2Calculate_ptr = _OpCache_T2Calculate.find(_trid_10);
                    if(_OpCache_with_parameter_T2Calculate_ptr == _OpCache_T2Calculate.end()) {
                        copiedState.T2Calculate();
                        CAN_BUS_tlc::_ProjectionWrite_T2Calculate writeState = copiedState._update_for_T2Calculate();
                        std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2Calculate, CAN_BUS_tlc::_ProjectionWrite_T2Calculate, CAN_BUS_tlc::_ProjectionRead_T2Calculate::Hash, CAN_BUS_tlc::_ProjectionRead_T2Calculate::HashEqual> _OpCache_with_parameter_T2Calculate;
                        _OpCache_with_parameter_T2Calculate.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_T2Calculate_lock(_ProjectionRead_T2Calculate_mutex);
                            _OpCache_T2Calculate.insert({_trid_10, _OpCache_with_parameter_T2Calculate});
                        }

                    } else {
                        std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2Calculate, CAN_BUS_tlc::_ProjectionWrite_T2Calculate, CAN_BUS_tlc::_ProjectionRead_T2Calculate::Hash, CAN_BUS_tlc::_ProjectionRead_T2Calculate::HashEqual> _OpCache_with_parameter_T2Calculate = _OpCache_with_parameter_T2Calculate_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_T2Calculate.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_T2Calculate.end()) {
                            CAN_BUS_tlc::_ProjectionWrite_T2Calculate writeState = writeState_ptr->second;
                            copiedState._apply_update_for_T2Calculate(writeState);
                        } else {
                            copiedState.T2Calculate();
                            CAN_BUS_tlc::_ProjectionWrite_T2Calculate writeState = copiedState._update_for_T2Calculate();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T2Calculate_lock(_ProjectionRead_T2Calculate_mutex);
                                _OpCache_with_parameter_T2Calculate.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "T2Calculate";
                    result.insert(copiedState);
                    transitions += 1;
                }
                CAN_BUS_tlc::_ProjectionRead__tr_T2WriteBus read__tr_T2WriteBus_state = state._projected_state_for__tr_T2WriteBus();
                auto _trid_11_ptr = _OpCache_tr_T2WriteBus.find(read__tr_T2WriteBus_state);
                if(_trid_11_ptr == _OpCache_tr_T2WriteBus.end()) {
                    BSet<BTuple<BInteger, BInteger >> _trid_11 = state._tr_T2WriteBus();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_T2WriteBus_lock(_ProjectionRead__tr_T2WriteBus_mutex);
                        _OpCache_tr_T2WriteBus.insert({read__tr_T2WriteBus_state, _trid_11});
                    }
                    for(const BTuple<BInteger, BInteger >& param : _trid_11) {
                        BInteger _tmp_1 = param.projection2();
                        BInteger _tmp_2 = param.projection1();

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_T2WriteBus readState = state._projected_state_for_T2WriteBus();

                        auto _OpCache_with_parameter_T2WriteBus_ptr = _OpCache_T2WriteBus.find(param);
                        if(_OpCache_with_parameter_T2WriteBus_ptr == _OpCache_T2WriteBus.end()) {
                            copiedState.T2WriteBus(_tmp_2, _tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_T2WriteBus writeState = copiedState._update_for_T2WriteBus();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2WriteBus, CAN_BUS_tlc::_ProjectionWrite_T2WriteBus, CAN_BUS_tlc::_ProjectionRead_T2WriteBus::Hash, CAN_BUS_tlc::_ProjectionRead_T2WriteBus::HashEqual> _OpCache_with_parameter_T2WriteBus;
                            _OpCache_with_parameter_T2WriteBus.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T2WriteBus_lock(_ProjectionRead_T2WriteBus_mutex);
                                _OpCache_T2WriteBus.insert({param, _OpCache_with_parameter_T2WriteBus});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2WriteBus, CAN_BUS_tlc::_ProjectionWrite_T2WriteBus, CAN_BUS_tlc::_ProjectionRead_T2WriteBus::Hash, CAN_BUS_tlc::_ProjectionRead_T2WriteBus::HashEqual> _OpCache_with_parameter_T2WriteBus = _OpCache_with_parameter_T2WriteBus_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_T2WriteBus.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_T2WriteBus.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_T2WriteBus writeState = writeState_ptr->second;
                                copiedState._apply_update_for_T2WriteBus(writeState);
                            } else {
                                copiedState.T2WriteBus(_tmp_2, _tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_T2WriteBus writeState = copiedState._update_for_T2WriteBus();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_T2WriteBus_lock(_ProjectionRead_T2WriteBus_mutex);
                                    _OpCache_with_parameter_T2WriteBus.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "T2WriteBus";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BTuple<BInteger, BInteger >> _trid_11 = _trid_11_ptr->second;
                    for(const BTuple<BInteger, BInteger >& param : _trid_11) {
                        BInteger _tmp_1 = param.projection2();
                        BInteger _tmp_2 = param.projection1();

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_T2WriteBus readState = state._projected_state_for_T2WriteBus();

                        auto _OpCache_with_parameter_T2WriteBus_ptr = _OpCache_T2WriteBus.find(param);
                        if(_OpCache_with_parameter_T2WriteBus_ptr == _OpCache_T2WriteBus.end()) {
                            copiedState.T2WriteBus(_tmp_2, _tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_T2WriteBus writeState = copiedState._update_for_T2WriteBus();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2WriteBus, CAN_BUS_tlc::_ProjectionWrite_T2WriteBus, CAN_BUS_tlc::_ProjectionRead_T2WriteBus::Hash, CAN_BUS_tlc::_ProjectionRead_T2WriteBus::HashEqual> _OpCache_with_parameter_T2WriteBus;
                            _OpCache_with_parameter_T2WriteBus.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T2WriteBus_lock(_ProjectionRead_T2WriteBus_mutex);
                                _OpCache_T2WriteBus.insert({param, _OpCache_with_parameter_T2WriteBus});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2WriteBus, CAN_BUS_tlc::_ProjectionWrite_T2WriteBus, CAN_BUS_tlc::_ProjectionRead_T2WriteBus::Hash, CAN_BUS_tlc::_ProjectionRead_T2WriteBus::HashEqual> _OpCache_with_parameter_T2WriteBus = _OpCache_with_parameter_T2WriteBus_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_T2WriteBus.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_T2WriteBus.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_T2WriteBus writeState = writeState_ptr->second;
                                copiedState._apply_update_for_T2WriteBus(writeState);
                            } else {
                                copiedState.T2WriteBus(_tmp_2, _tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_T2WriteBus writeState = copiedState._update_for_T2WriteBus();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_T2WriteBus_lock(_ProjectionRead_T2WriteBus_mutex);
                                    _OpCache_with_parameter_T2WriteBus.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "T2WriteBus";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                CAN_BUS_tlc::_ProjectionRead__tr_T2Wait read__tr_T2Wait_state = state._projected_state_for__tr_T2Wait();
                auto _trid_12_ptr = _OpCache_tr_T2Wait.find(read__tr_T2Wait_state);
                if(_trid_12_ptr == _OpCache_tr_T2Wait.end()) {
                    BSet<BInteger> _trid_12 = state._tr_T2Wait();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_T2Wait_lock(_ProjectionRead__tr_T2Wait_mutex);
                        _OpCache_tr_T2Wait.insert({read__tr_T2Wait_state, _trid_12});
                    }
                    for(const BInteger& param : _trid_12) {
                        BInteger _tmp_1 = param;

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_T2Wait readState = state._projected_state_for_T2Wait();

                        auto _OpCache_with_parameter_T2Wait_ptr = _OpCache_T2Wait.find(param);
                        if(_OpCache_with_parameter_T2Wait_ptr == _OpCache_T2Wait.end()) {
                            copiedState.T2Wait(_tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_T2Wait writeState = copiedState._update_for_T2Wait();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2Wait, CAN_BUS_tlc::_ProjectionWrite_T2Wait, CAN_BUS_tlc::_ProjectionRead_T2Wait::Hash, CAN_BUS_tlc::_ProjectionRead_T2Wait::HashEqual> _OpCache_with_parameter_T2Wait;
                            _OpCache_with_parameter_T2Wait.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T2Wait_lock(_ProjectionRead_T2Wait_mutex);
                                _OpCache_T2Wait.insert({param, _OpCache_with_parameter_T2Wait});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2Wait, CAN_BUS_tlc::_ProjectionWrite_T2Wait, CAN_BUS_tlc::_ProjectionRead_T2Wait::Hash, CAN_BUS_tlc::_ProjectionRead_T2Wait::HashEqual> _OpCache_with_parameter_T2Wait = _OpCache_with_parameter_T2Wait_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_T2Wait.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_T2Wait.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_T2Wait writeState = writeState_ptr->second;
                                copiedState._apply_update_for_T2Wait(writeState);
                            } else {
                                copiedState.T2Wait(_tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_T2Wait writeState = copiedState._update_for_T2Wait();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_T2Wait_lock(_ProjectionRead_T2Wait_mutex);
                                    _OpCache_with_parameter_T2Wait.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "T2Wait";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BInteger> _trid_12 = _trid_12_ptr->second;
                    for(const BInteger& param : _trid_12) {
                        BInteger _tmp_1 = param;

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_T2Wait readState = state._projected_state_for_T2Wait();

                        auto _OpCache_with_parameter_T2Wait_ptr = _OpCache_T2Wait.find(param);
                        if(_OpCache_with_parameter_T2Wait_ptr == _OpCache_T2Wait.end()) {
                            copiedState.T2Wait(_tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_T2Wait writeState = copiedState._update_for_T2Wait();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2Wait, CAN_BUS_tlc::_ProjectionWrite_T2Wait, CAN_BUS_tlc::_ProjectionRead_T2Wait::Hash, CAN_BUS_tlc::_ProjectionRead_T2Wait::HashEqual> _OpCache_with_parameter_T2Wait;
                            _OpCache_with_parameter_T2Wait.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T2Wait_lock(_ProjectionRead_T2Wait_mutex);
                                _OpCache_T2Wait.insert({param, _OpCache_with_parameter_T2Wait});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T2Wait, CAN_BUS_tlc::_ProjectionWrite_T2Wait, CAN_BUS_tlc::_ProjectionRead_T2Wait::Hash, CAN_BUS_tlc::_ProjectionRead_T2Wait::HashEqual> _OpCache_with_parameter_T2Wait = _OpCache_with_parameter_T2Wait_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_T2Wait.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_T2Wait.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_T2Wait writeState = writeState_ptr->second;
                                copiedState._apply_update_for_T2Wait(writeState);
                            } else {
                                copiedState.T2Wait(_tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_T2Wait writeState = copiedState._update_for_T2Wait();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_T2Wait_lock(_ProjectionRead_T2Wait_mutex);
                                    _OpCache_with_parameter_T2Wait.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "T2Wait";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                CAN_BUS_tlc::_ProjectionRead__tr_T3Initiate read__tr_T3Initiate_state = state._projected_state_for__tr_T3Initiate();
                bool _trid_13;
                auto _obj__trid_13_ptr = _OpCache_tr_T3Initiate.find(read__tr_T3Initiate_state);
                if(_obj__trid_13_ptr == _OpCache_tr_T3Initiate.end()) {
                    _trid_13 = state._tr_T3Initiate();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_T3Initiate_lock(_ProjectionRead__tr_T3Initiate_mutex);
                        _OpCache_tr_T3Initiate.insert({read__tr_T3Initiate_state, _trid_13});
                    }
                } else {
                    _trid_13 = _obj__trid_13_ptr->second;
                }
                if(_trid_13) {
                    CAN_BUS_tlc copiedState = state._copy();
                    CAN_BUS_tlc::_ProjectionRead_T3Initiate readState = state._projected_state_for_T3Initiate();

                    auto _OpCache_with_parameter_T3Initiate_ptr = _OpCache_T3Initiate.find(_trid_13);
                    if(_OpCache_with_parameter_T3Initiate_ptr == _OpCache_T3Initiate.end()) {
                        copiedState.T3Initiate();
                        CAN_BUS_tlc::_ProjectionWrite_T3Initiate writeState = copiedState._update_for_T3Initiate();
                        std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3Initiate, CAN_BUS_tlc::_ProjectionWrite_T3Initiate, CAN_BUS_tlc::_ProjectionRead_T3Initiate::Hash, CAN_BUS_tlc::_ProjectionRead_T3Initiate::HashEqual> _OpCache_with_parameter_T3Initiate;
                        _OpCache_with_parameter_T3Initiate.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_T3Initiate_lock(_ProjectionRead_T3Initiate_mutex);
                            _OpCache_T3Initiate.insert({_trid_13, _OpCache_with_parameter_T3Initiate});
                        }

                    } else {
                        std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3Initiate, CAN_BUS_tlc::_ProjectionWrite_T3Initiate, CAN_BUS_tlc::_ProjectionRead_T3Initiate::Hash, CAN_BUS_tlc::_ProjectionRead_T3Initiate::HashEqual> _OpCache_with_parameter_T3Initiate = _OpCache_with_parameter_T3Initiate_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_T3Initiate.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_T3Initiate.end()) {
                            CAN_BUS_tlc::_ProjectionWrite_T3Initiate writeState = writeState_ptr->second;
                            copiedState._apply_update_for_T3Initiate(writeState);
                        } else {
                            copiedState.T3Initiate();
                            CAN_BUS_tlc::_ProjectionWrite_T3Initiate writeState = copiedState._update_for_T3Initiate();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T3Initiate_lock(_ProjectionRead_T3Initiate_mutex);
                                _OpCache_with_parameter_T3Initiate.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "T3Initiate";
                    result.insert(copiedState);
                    transitions += 1;
                }
                CAN_BUS_tlc::_ProjectionRead__tr_T3Evaluate read__tr_T3Evaluate_state = state._projected_state_for__tr_T3Evaluate();
                bool _trid_14;
                auto _obj__trid_14_ptr = _OpCache_tr_T3Evaluate.find(read__tr_T3Evaluate_state);
                if(_obj__trid_14_ptr == _OpCache_tr_T3Evaluate.end()) {
                    _trid_14 = state._tr_T3Evaluate();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_T3Evaluate_lock(_ProjectionRead__tr_T3Evaluate_mutex);
                        _OpCache_tr_T3Evaluate.insert({read__tr_T3Evaluate_state, _trid_14});
                    }
                } else {
                    _trid_14 = _obj__trid_14_ptr->second;
                }
                if(_trid_14) {
                    CAN_BUS_tlc copiedState = state._copy();
                    CAN_BUS_tlc::_ProjectionRead_T3Evaluate readState = state._projected_state_for_T3Evaluate();

                    auto _OpCache_with_parameter_T3Evaluate_ptr = _OpCache_T3Evaluate.find(_trid_14);
                    if(_OpCache_with_parameter_T3Evaluate_ptr == _OpCache_T3Evaluate.end()) {
                        copiedState.T3Evaluate();
                        CAN_BUS_tlc::_ProjectionWrite_T3Evaluate writeState = copiedState._update_for_T3Evaluate();
                        std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3Evaluate, CAN_BUS_tlc::_ProjectionWrite_T3Evaluate, CAN_BUS_tlc::_ProjectionRead_T3Evaluate::Hash, CAN_BUS_tlc::_ProjectionRead_T3Evaluate::HashEqual> _OpCache_with_parameter_T3Evaluate;
                        _OpCache_with_parameter_T3Evaluate.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_T3Evaluate_lock(_ProjectionRead_T3Evaluate_mutex);
                            _OpCache_T3Evaluate.insert({_trid_14, _OpCache_with_parameter_T3Evaluate});
                        }

                    } else {
                        std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3Evaluate, CAN_BUS_tlc::_ProjectionWrite_T3Evaluate, CAN_BUS_tlc::_ProjectionRead_T3Evaluate::Hash, CAN_BUS_tlc::_ProjectionRead_T3Evaluate::HashEqual> _OpCache_with_parameter_T3Evaluate = _OpCache_with_parameter_T3Evaluate_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_T3Evaluate.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_T3Evaluate.end()) {
                            CAN_BUS_tlc::_ProjectionWrite_T3Evaluate writeState = writeState_ptr->second;
                            copiedState._apply_update_for_T3Evaluate(writeState);
                        } else {
                            copiedState.T3Evaluate();
                            CAN_BUS_tlc::_ProjectionWrite_T3Evaluate writeState = copiedState._update_for_T3Evaluate();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T3Evaluate_lock(_ProjectionRead_T3Evaluate_mutex);
                                _OpCache_with_parameter_T3Evaluate.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "T3Evaluate";
                    result.insert(copiedState);
                    transitions += 1;
                }
                CAN_BUS_tlc::_ProjectionRead__tr_T3writebus read__tr_T3writebus_state = state._projected_state_for__tr_T3writebus();
                auto _trid_15_ptr = _OpCache_tr_T3writebus.find(read__tr_T3writebus_state);
                if(_trid_15_ptr == _OpCache_tr_T3writebus.end()) {
                    BSet<BTuple<BInteger, BInteger >> _trid_15 = state._tr_T3writebus();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_T3writebus_lock(_ProjectionRead__tr_T3writebus_mutex);
                        _OpCache_tr_T3writebus.insert({read__tr_T3writebus_state, _trid_15});
                    }
                    for(const BTuple<BInteger, BInteger >& param : _trid_15) {
                        BInteger _tmp_1 = param.projection2();
                        BInteger _tmp_2 = param.projection1();

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_T3writebus readState = state._projected_state_for_T3writebus();

                        auto _OpCache_with_parameter_T3writebus_ptr = _OpCache_T3writebus.find(param);
                        if(_OpCache_with_parameter_T3writebus_ptr == _OpCache_T3writebus.end()) {
                            copiedState.T3writebus(_tmp_2, _tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_T3writebus writeState = copiedState._update_for_T3writebus();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3writebus, CAN_BUS_tlc::_ProjectionWrite_T3writebus, CAN_BUS_tlc::_ProjectionRead_T3writebus::Hash, CAN_BUS_tlc::_ProjectionRead_T3writebus::HashEqual> _OpCache_with_parameter_T3writebus;
                            _OpCache_with_parameter_T3writebus.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T3writebus_lock(_ProjectionRead_T3writebus_mutex);
                                _OpCache_T3writebus.insert({param, _OpCache_with_parameter_T3writebus});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3writebus, CAN_BUS_tlc::_ProjectionWrite_T3writebus, CAN_BUS_tlc::_ProjectionRead_T3writebus::Hash, CAN_BUS_tlc::_ProjectionRead_T3writebus::HashEqual> _OpCache_with_parameter_T3writebus = _OpCache_with_parameter_T3writebus_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_T3writebus.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_T3writebus.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_T3writebus writeState = writeState_ptr->second;
                                copiedState._apply_update_for_T3writebus(writeState);
                            } else {
                                copiedState.T3writebus(_tmp_2, _tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_T3writebus writeState = copiedState._update_for_T3writebus();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_T3writebus_lock(_ProjectionRead_T3writebus_mutex);
                                    _OpCache_with_parameter_T3writebus.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "T3writebus";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BTuple<BInteger, BInteger >> _trid_15 = _trid_15_ptr->second;
                    for(const BTuple<BInteger, BInteger >& param : _trid_15) {
                        BInteger _tmp_1 = param.projection2();
                        BInteger _tmp_2 = param.projection1();

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_T3writebus readState = state._projected_state_for_T3writebus();

                        auto _OpCache_with_parameter_T3writebus_ptr = _OpCache_T3writebus.find(param);
                        if(_OpCache_with_parameter_T3writebus_ptr == _OpCache_T3writebus.end()) {
                            copiedState.T3writebus(_tmp_2, _tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_T3writebus writeState = copiedState._update_for_T3writebus();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3writebus, CAN_BUS_tlc::_ProjectionWrite_T3writebus, CAN_BUS_tlc::_ProjectionRead_T3writebus::Hash, CAN_BUS_tlc::_ProjectionRead_T3writebus::HashEqual> _OpCache_with_parameter_T3writebus;
                            _OpCache_with_parameter_T3writebus.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T3writebus_lock(_ProjectionRead_T3writebus_mutex);
                                _OpCache_T3writebus.insert({param, _OpCache_with_parameter_T3writebus});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3writebus, CAN_BUS_tlc::_ProjectionWrite_T3writebus, CAN_BUS_tlc::_ProjectionRead_T3writebus::Hash, CAN_BUS_tlc::_ProjectionRead_T3writebus::HashEqual> _OpCache_with_parameter_T3writebus = _OpCache_with_parameter_T3writebus_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_T3writebus.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_T3writebus.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_T3writebus writeState = writeState_ptr->second;
                                copiedState._apply_update_for_T3writebus(writeState);
                            } else {
                                copiedState.T3writebus(_tmp_2, _tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_T3writebus writeState = copiedState._update_for_T3writebus();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_T3writebus_lock(_ProjectionRead_T3writebus_mutex);
                                    _OpCache_with_parameter_T3writebus.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "T3writebus";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                CAN_BUS_tlc::_ProjectionRead__tr_T3Read read__tr_T3Read_state = state._projected_state_for__tr_T3Read();
                auto _trid_16_ptr = _OpCache_tr_T3Read.find(read__tr_T3Read_state);
                if(_trid_16_ptr == _OpCache_tr_T3Read.end()) {
                    BSet<BTuple<BInteger, BInteger >> _trid_16 = state._tr_T3Read();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_T3Read_lock(_ProjectionRead__tr_T3Read_mutex);
                        _OpCache_tr_T3Read.insert({read__tr_T3Read_state, _trid_16});
                    }
                    for(const BTuple<BInteger, BInteger >& param : _trid_16) {
                        BInteger _tmp_1 = param.projection2();
                        BInteger _tmp_2 = param.projection1();

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_T3Read readState = state._projected_state_for_T3Read();

                        auto _OpCache_with_parameter_T3Read_ptr = _OpCache_T3Read.find(param);
                        if(_OpCache_with_parameter_T3Read_ptr == _OpCache_T3Read.end()) {
                            copiedState.T3Read(_tmp_2, _tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_T3Read writeState = copiedState._update_for_T3Read();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3Read, CAN_BUS_tlc::_ProjectionWrite_T3Read, CAN_BUS_tlc::_ProjectionRead_T3Read::Hash, CAN_BUS_tlc::_ProjectionRead_T3Read::HashEqual> _OpCache_with_parameter_T3Read;
                            _OpCache_with_parameter_T3Read.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T3Read_lock(_ProjectionRead_T3Read_mutex);
                                _OpCache_T3Read.insert({param, _OpCache_with_parameter_T3Read});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3Read, CAN_BUS_tlc::_ProjectionWrite_T3Read, CAN_BUS_tlc::_ProjectionRead_T3Read::Hash, CAN_BUS_tlc::_ProjectionRead_T3Read::HashEqual> _OpCache_with_parameter_T3Read = _OpCache_with_parameter_T3Read_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_T3Read.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_T3Read.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_T3Read writeState = writeState_ptr->second;
                                copiedState._apply_update_for_T3Read(writeState);
                            } else {
                                copiedState.T3Read(_tmp_2, _tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_T3Read writeState = copiedState._update_for_T3Read();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_T3Read_lock(_ProjectionRead_T3Read_mutex);
                                    _OpCache_with_parameter_T3Read.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "T3Read";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BTuple<BInteger, BInteger >> _trid_16 = _trid_16_ptr->second;
                    for(const BTuple<BInteger, BInteger >& param : _trid_16) {
                        BInteger _tmp_1 = param.projection2();
                        BInteger _tmp_2 = param.projection1();

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_T3Read readState = state._projected_state_for_T3Read();

                        auto _OpCache_with_parameter_T3Read_ptr = _OpCache_T3Read.find(param);
                        if(_OpCache_with_parameter_T3Read_ptr == _OpCache_T3Read.end()) {
                            copiedState.T3Read(_tmp_2, _tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_T3Read writeState = copiedState._update_for_T3Read();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3Read, CAN_BUS_tlc::_ProjectionWrite_T3Read, CAN_BUS_tlc::_ProjectionRead_T3Read::Hash, CAN_BUS_tlc::_ProjectionRead_T3Read::HashEqual> _OpCache_with_parameter_T3Read;
                            _OpCache_with_parameter_T3Read.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T3Read_lock(_ProjectionRead_T3Read_mutex);
                                _OpCache_T3Read.insert({param, _OpCache_with_parameter_T3Read});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3Read, CAN_BUS_tlc::_ProjectionWrite_T3Read, CAN_BUS_tlc::_ProjectionRead_T3Read::Hash, CAN_BUS_tlc::_ProjectionRead_T3Read::HashEqual> _OpCache_with_parameter_T3Read = _OpCache_with_parameter_T3Read_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_T3Read.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_T3Read.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_T3Read writeState = writeState_ptr->second;
                                copiedState._apply_update_for_T3Read(writeState);
                            } else {
                                copiedState.T3Read(_tmp_2, _tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_T3Read writeState = copiedState._update_for_T3Read();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_T3Read_lock(_ProjectionRead_T3Read_mutex);
                                    _OpCache_with_parameter_T3Read.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "T3Read";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                CAN_BUS_tlc::_ProjectionRead__tr_T3Poll read__tr_T3Poll_state = state._projected_state_for__tr_T3Poll();
                bool _trid_17;
                auto _obj__trid_17_ptr = _OpCache_tr_T3Poll.find(read__tr_T3Poll_state);
                if(_obj__trid_17_ptr == _OpCache_tr_T3Poll.end()) {
                    _trid_17 = state._tr_T3Poll();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_T3Poll_lock(_ProjectionRead__tr_T3Poll_mutex);
                        _OpCache_tr_T3Poll.insert({read__tr_T3Poll_state, _trid_17});
                    }
                } else {
                    _trid_17 = _obj__trid_17_ptr->second;
                }
                if(_trid_17) {
                    CAN_BUS_tlc copiedState = state._copy();
                    CAN_BUS_tlc::_ProjectionRead_T3Poll readState = state._projected_state_for_T3Poll();

                    auto _OpCache_with_parameter_T3Poll_ptr = _OpCache_T3Poll.find(_trid_17);
                    if(_OpCache_with_parameter_T3Poll_ptr == _OpCache_T3Poll.end()) {
                        copiedState.T3Poll();
                        CAN_BUS_tlc::_ProjectionWrite_T3Poll writeState = copiedState._update_for_T3Poll();
                        std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3Poll, CAN_BUS_tlc::_ProjectionWrite_T3Poll, CAN_BUS_tlc::_ProjectionRead_T3Poll::Hash, CAN_BUS_tlc::_ProjectionRead_T3Poll::HashEqual> _OpCache_with_parameter_T3Poll;
                        _OpCache_with_parameter_T3Poll.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_T3Poll_lock(_ProjectionRead_T3Poll_mutex);
                            _OpCache_T3Poll.insert({_trid_17, _OpCache_with_parameter_T3Poll});
                        }

                    } else {
                        std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3Poll, CAN_BUS_tlc::_ProjectionWrite_T3Poll, CAN_BUS_tlc::_ProjectionRead_T3Poll::Hash, CAN_BUS_tlc::_ProjectionRead_T3Poll::HashEqual> _OpCache_with_parameter_T3Poll = _OpCache_with_parameter_T3Poll_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_T3Poll.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_T3Poll.end()) {
                            CAN_BUS_tlc::_ProjectionWrite_T3Poll writeState = writeState_ptr->second;
                            copiedState._apply_update_for_T3Poll(writeState);
                        } else {
                            copiedState.T3Poll();
                            CAN_BUS_tlc::_ProjectionWrite_T3Poll writeState = copiedState._update_for_T3Poll();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T3Poll_lock(_ProjectionRead_T3Poll_mutex);
                                _OpCache_with_parameter_T3Poll.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "T3Poll";
                    result.insert(copiedState);
                    transitions += 1;
                }
                CAN_BUS_tlc::_ProjectionRead__tr_T3ReleaseBus read__tr_T3ReleaseBus_state = state._projected_state_for__tr_T3ReleaseBus();
                auto _trid_18_ptr = _OpCache_tr_T3ReleaseBus.find(read__tr_T3ReleaseBus_state);
                if(_trid_18_ptr == _OpCache_tr_T3ReleaseBus.end()) {
                    BSet<BInteger> _trid_18 = state._tr_T3ReleaseBus();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_T3ReleaseBus_lock(_ProjectionRead__tr_T3ReleaseBus_mutex);
                        _OpCache_tr_T3ReleaseBus.insert({read__tr_T3ReleaseBus_state, _trid_18});
                    }
                    for(const BInteger& param : _trid_18) {
                        BInteger _tmp_1 = param;

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_T3ReleaseBus readState = state._projected_state_for_T3ReleaseBus();

                        auto _OpCache_with_parameter_T3ReleaseBus_ptr = _OpCache_T3ReleaseBus.find(param);
                        if(_OpCache_with_parameter_T3ReleaseBus_ptr == _OpCache_T3ReleaseBus.end()) {
                            copiedState.T3ReleaseBus(_tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_T3ReleaseBus writeState = copiedState._update_for_T3ReleaseBus();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3ReleaseBus, CAN_BUS_tlc::_ProjectionWrite_T3ReleaseBus, CAN_BUS_tlc::_ProjectionRead_T3ReleaseBus::Hash, CAN_BUS_tlc::_ProjectionRead_T3ReleaseBus::HashEqual> _OpCache_with_parameter_T3ReleaseBus;
                            _OpCache_with_parameter_T3ReleaseBus.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T3ReleaseBus_lock(_ProjectionRead_T3ReleaseBus_mutex);
                                _OpCache_T3ReleaseBus.insert({param, _OpCache_with_parameter_T3ReleaseBus});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3ReleaseBus, CAN_BUS_tlc::_ProjectionWrite_T3ReleaseBus, CAN_BUS_tlc::_ProjectionRead_T3ReleaseBus::Hash, CAN_BUS_tlc::_ProjectionRead_T3ReleaseBus::HashEqual> _OpCache_with_parameter_T3ReleaseBus = _OpCache_with_parameter_T3ReleaseBus_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_T3ReleaseBus.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_T3ReleaseBus.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_T3ReleaseBus writeState = writeState_ptr->second;
                                copiedState._apply_update_for_T3ReleaseBus(writeState);
                            } else {
                                copiedState.T3ReleaseBus(_tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_T3ReleaseBus writeState = copiedState._update_for_T3ReleaseBus();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_T3ReleaseBus_lock(_ProjectionRead_T3ReleaseBus_mutex);
                                    _OpCache_with_parameter_T3ReleaseBus.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "T3ReleaseBus";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BInteger> _trid_18 = _trid_18_ptr->second;
                    for(const BInteger& param : _trid_18) {
                        BInteger _tmp_1 = param;

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_T3ReleaseBus readState = state._projected_state_for_T3ReleaseBus();

                        auto _OpCache_with_parameter_T3ReleaseBus_ptr = _OpCache_T3ReleaseBus.find(param);
                        if(_OpCache_with_parameter_T3ReleaseBus_ptr == _OpCache_T3ReleaseBus.end()) {
                            copiedState.T3ReleaseBus(_tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_T3ReleaseBus writeState = copiedState._update_for_T3ReleaseBus();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3ReleaseBus, CAN_BUS_tlc::_ProjectionWrite_T3ReleaseBus, CAN_BUS_tlc::_ProjectionRead_T3ReleaseBus::Hash, CAN_BUS_tlc::_ProjectionRead_T3ReleaseBus::HashEqual> _OpCache_with_parameter_T3ReleaseBus;
                            _OpCache_with_parameter_T3ReleaseBus.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T3ReleaseBus_lock(_ProjectionRead_T3ReleaseBus_mutex);
                                _OpCache_T3ReleaseBus.insert({param, _OpCache_with_parameter_T3ReleaseBus});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3ReleaseBus, CAN_BUS_tlc::_ProjectionWrite_T3ReleaseBus, CAN_BUS_tlc::_ProjectionRead_T3ReleaseBus::Hash, CAN_BUS_tlc::_ProjectionRead_T3ReleaseBus::HashEqual> _OpCache_with_parameter_T3ReleaseBus = _OpCache_with_parameter_T3ReleaseBus_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_T3ReleaseBus.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_T3ReleaseBus.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_T3ReleaseBus writeState = writeState_ptr->second;
                                copiedState._apply_update_for_T3ReleaseBus(writeState);
                            } else {
                                copiedState.T3ReleaseBus(_tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_T3ReleaseBus writeState = copiedState._update_for_T3ReleaseBus();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_T3ReleaseBus_lock(_ProjectionRead_T3ReleaseBus_mutex);
                                    _OpCache_with_parameter_T3ReleaseBus.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "T3ReleaseBus";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                CAN_BUS_tlc::_ProjectionRead__tr_T3Wait read__tr_T3Wait_state = state._projected_state_for__tr_T3Wait();
                bool _trid_19;
                auto _obj__trid_19_ptr = _OpCache_tr_T3Wait.find(read__tr_T3Wait_state);
                if(_obj__trid_19_ptr == _OpCache_tr_T3Wait.end()) {
                    _trid_19 = state._tr_T3Wait();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_T3Wait_lock(_ProjectionRead__tr_T3Wait_mutex);
                        _OpCache_tr_T3Wait.insert({read__tr_T3Wait_state, _trid_19});
                    }
                } else {
                    _trid_19 = _obj__trid_19_ptr->second;
                }
                if(_trid_19) {
                    CAN_BUS_tlc copiedState = state._copy();
                    CAN_BUS_tlc::_ProjectionRead_T3Wait readState = state._projected_state_for_T3Wait();

                    auto _OpCache_with_parameter_T3Wait_ptr = _OpCache_T3Wait.find(_trid_19);
                    if(_OpCache_with_parameter_T3Wait_ptr == _OpCache_T3Wait.end()) {
                        copiedState.T3Wait();
                        CAN_BUS_tlc::_ProjectionWrite_T3Wait writeState = copiedState._update_for_T3Wait();
                        std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3Wait, CAN_BUS_tlc::_ProjectionWrite_T3Wait, CAN_BUS_tlc::_ProjectionRead_T3Wait::Hash, CAN_BUS_tlc::_ProjectionRead_T3Wait::HashEqual> _OpCache_with_parameter_T3Wait;
                        _OpCache_with_parameter_T3Wait.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_T3Wait_lock(_ProjectionRead_T3Wait_mutex);
                            _OpCache_T3Wait.insert({_trid_19, _OpCache_with_parameter_T3Wait});
                        }

                    } else {
                        std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3Wait, CAN_BUS_tlc::_ProjectionWrite_T3Wait, CAN_BUS_tlc::_ProjectionRead_T3Wait::Hash, CAN_BUS_tlc::_ProjectionRead_T3Wait::HashEqual> _OpCache_with_parameter_T3Wait = _OpCache_with_parameter_T3Wait_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_T3Wait.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_T3Wait.end()) {
                            CAN_BUS_tlc::_ProjectionWrite_T3Wait writeState = writeState_ptr->second;
                            copiedState._apply_update_for_T3Wait(writeState);
                        } else {
                            copiedState.T3Wait();
                            CAN_BUS_tlc::_ProjectionWrite_T3Wait writeState = copiedState._update_for_T3Wait();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T3Wait_lock(_ProjectionRead_T3Wait_mutex);
                                _OpCache_with_parameter_T3Wait.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "T3Wait";
                    result.insert(copiedState);
                    transitions += 1;
                }
                CAN_BUS_tlc::_ProjectionRead__tr_T3ReEnableWait read__tr_T3ReEnableWait_state = state._projected_state_for__tr_T3ReEnableWait();
                bool _trid_20;
                auto _obj__trid_20_ptr = _OpCache_tr_T3ReEnableWait.find(read__tr_T3ReEnableWait_state);
                if(_obj__trid_20_ptr == _OpCache_tr_T3ReEnableWait.end()) {
                    _trid_20 = state._tr_T3ReEnableWait();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_T3ReEnableWait_lock(_ProjectionRead__tr_T3ReEnableWait_mutex);
                        _OpCache_tr_T3ReEnableWait.insert({read__tr_T3ReEnableWait_state, _trid_20});
                    }
                } else {
                    _trid_20 = _obj__trid_20_ptr->second;
                }
                if(_trid_20) {
                    CAN_BUS_tlc copiedState = state._copy();
                    CAN_BUS_tlc::_ProjectionRead_T3ReEnableWait readState = state._projected_state_for_T3ReEnableWait();

                    auto _OpCache_with_parameter_T3ReEnableWait_ptr = _OpCache_T3ReEnableWait.find(_trid_20);
                    if(_OpCache_with_parameter_T3ReEnableWait_ptr == _OpCache_T3ReEnableWait.end()) {
                        copiedState.T3ReEnableWait();
                        CAN_BUS_tlc::_ProjectionWrite_T3ReEnableWait writeState = copiedState._update_for_T3ReEnableWait();
                        std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3ReEnableWait, CAN_BUS_tlc::_ProjectionWrite_T3ReEnableWait, CAN_BUS_tlc::_ProjectionRead_T3ReEnableWait::Hash, CAN_BUS_tlc::_ProjectionRead_T3ReEnableWait::HashEqual> _OpCache_with_parameter_T3ReEnableWait;
                        _OpCache_with_parameter_T3ReEnableWait.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_T3ReEnableWait_lock(_ProjectionRead_T3ReEnableWait_mutex);
                            _OpCache_T3ReEnableWait.insert({_trid_20, _OpCache_with_parameter_T3ReEnableWait});
                        }

                    } else {
                        std::unordered_map<CAN_BUS_tlc::_ProjectionRead_T3ReEnableWait, CAN_BUS_tlc::_ProjectionWrite_T3ReEnableWait, CAN_BUS_tlc::_ProjectionRead_T3ReEnableWait::Hash, CAN_BUS_tlc::_ProjectionRead_T3ReEnableWait::HashEqual> _OpCache_with_parameter_T3ReEnableWait = _OpCache_with_parameter_T3ReEnableWait_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_T3ReEnableWait.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_T3ReEnableWait.end()) {
                            CAN_BUS_tlc::_ProjectionWrite_T3ReEnableWait writeState = writeState_ptr->second;
                            copiedState._apply_update_for_T3ReEnableWait(writeState);
                        } else {
                            copiedState.T3ReEnableWait();
                            CAN_BUS_tlc::_ProjectionWrite_T3ReEnableWait writeState = copiedState._update_for_T3ReEnableWait();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_T3ReEnableWait_lock(_ProjectionRead_T3ReEnableWait_mutex);
                                _OpCache_with_parameter_T3ReEnableWait.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "T3ReEnableWait";
                    result.insert(copiedState);
                    transitions += 1;
                }
                CAN_BUS_tlc::_ProjectionRead__tr_Update read__tr_Update_state = state._projected_state_for__tr_Update();
                auto _trid_21_ptr = _OpCache_tr_Update.find(read__tr_Update_state);
                if(_trid_21_ptr == _OpCache_tr_Update.end()) {
                    BSet<BInteger> _trid_21 = state._tr_Update();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_Update_lock(_ProjectionRead__tr_Update_mutex);
                        _OpCache_tr_Update.insert({read__tr_Update_state, _trid_21});
                    }
                    for(const BInteger& param : _trid_21) {
                        BInteger _tmp_1 = param;

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_Update readState = state._projected_state_for_Update();

                        auto _OpCache_with_parameter_Update_ptr = _OpCache_Update.find(param);
                        if(_OpCache_with_parameter_Update_ptr == _OpCache_Update.end()) {
                            copiedState.Update(_tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_Update writeState = copiedState._update_for_Update();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_Update, CAN_BUS_tlc::_ProjectionWrite_Update, CAN_BUS_tlc::_ProjectionRead_Update::Hash, CAN_BUS_tlc::_ProjectionRead_Update::HashEqual> _OpCache_with_parameter_Update;
                            _OpCache_with_parameter_Update.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Update_lock(_ProjectionRead_Update_mutex);
                                _OpCache_Update.insert({param, _OpCache_with_parameter_Update});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_Update, CAN_BUS_tlc::_ProjectionWrite_Update, CAN_BUS_tlc::_ProjectionRead_Update::Hash, CAN_BUS_tlc::_ProjectionRead_Update::HashEqual> _OpCache_with_parameter_Update = _OpCache_with_parameter_Update_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Update.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Update.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_Update writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Update(writeState);
                            } else {
                                copiedState.Update(_tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_Update writeState = copiedState._update_for_Update();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Update_lock(_ProjectionRead_Update_mutex);
                                    _OpCache_with_parameter_Update.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Update";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BInteger> _trid_21 = _trid_21_ptr->second;
                    for(const BInteger& param : _trid_21) {
                        BInteger _tmp_1 = param;

                        CAN_BUS_tlc copiedState = state._copy();
                        CAN_BUS_tlc::_ProjectionRead_Update readState = state._projected_state_for_Update();

                        auto _OpCache_with_parameter_Update_ptr = _OpCache_Update.find(param);
                        if(_OpCache_with_parameter_Update_ptr == _OpCache_Update.end()) {
                            copiedState.Update(_tmp_1);
                            CAN_BUS_tlc::_ProjectionWrite_Update writeState = copiedState._update_for_Update();
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_Update, CAN_BUS_tlc::_ProjectionWrite_Update, CAN_BUS_tlc::_ProjectionRead_Update::Hash, CAN_BUS_tlc::_ProjectionRead_Update::HashEqual> _OpCache_with_parameter_Update;
                            _OpCache_with_parameter_Update.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Update_lock(_ProjectionRead_Update_mutex);
                                _OpCache_Update.insert({param, _OpCache_with_parameter_Update});
                            }

                        } else {
                            std::unordered_map<CAN_BUS_tlc::_ProjectionRead_Update, CAN_BUS_tlc::_ProjectionWrite_Update, CAN_BUS_tlc::_ProjectionRead_Update::Hash, CAN_BUS_tlc::_ProjectionRead_Update::HashEqual> _OpCache_with_parameter_Update = _OpCache_with_parameter_Update_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Update.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Update.end()) {
                                CAN_BUS_tlc::_ProjectionWrite_Update writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Update(writeState);
                            } else {
                                copiedState.Update(_tmp_1);
                                CAN_BUS_tlc::_ProjectionWrite_Update writeState = copiedState._update_for_Update();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Update_lock(_ProjectionRead_Update_mutex);
                                    _OpCache_with_parameter_Update.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Update";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }

            } else {
                if(state._tr_T1Evaluate()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T1Evaluate();
                    copiedState.stateAccessedVia = "T1Evaluate";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BInteger> _trid_2 = state._tr_T1Calculate();
                for(const BInteger& param : _trid_2) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T1Calculate(_tmp_1);
                    copiedState.stateAccessedVia = "T1Calculate";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BTuple<BInteger, BInteger >> _trid_3 = state._tr_T1SendResult();
                for(const BTuple<BInteger, BInteger >& param : _trid_3) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T1SendResult(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "T1SendResult";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BInteger> _trid_4 = state._tr_T1Wait();
                for(const BInteger& param : _trid_4) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T1Wait(_tmp_1);
                    copiedState.stateAccessedVia = "T1Wait";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_T2Evaluate()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2Evaluate();
                    copiedState.stateAccessedVia = "T2Evaluate";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BTuple<BInteger, BInteger >> _trid_6 = state._tr_T2ReadBus();
                for(const BTuple<BInteger, BInteger >& param : _trid_6) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2ReadBus(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "T2ReadBus";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_T2Reset()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2Reset();
                    copiedState.stateAccessedVia = "T2Reset";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_T2Complete()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2Complete();
                    copiedState.stateAccessedVia = "T2Complete";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BInteger> _trid_9 = state._tr_T2ReleaseBus();
                for(const BInteger& param : _trid_9) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2ReleaseBus(_tmp_1);
                    copiedState.stateAccessedVia = "T2ReleaseBus";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_T2Calculate()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2Calculate();
                    copiedState.stateAccessedVia = "T2Calculate";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BTuple<BInteger, BInteger >> _trid_11 = state._tr_T2WriteBus();
                for(const BTuple<BInteger, BInteger >& param : _trid_11) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2WriteBus(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "T2WriteBus";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BInteger> _trid_12 = state._tr_T2Wait();
                for(const BInteger& param : _trid_12) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2Wait(_tmp_1);
                    copiedState.stateAccessedVia = "T2Wait";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_T3Initiate()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3Initiate();
                    copiedState.stateAccessedVia = "T3Initiate";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_T3Evaluate()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3Evaluate();
                    copiedState.stateAccessedVia = "T3Evaluate";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BTuple<BInteger, BInteger >> _trid_15 = state._tr_T3writebus();
                for(const BTuple<BInteger, BInteger >& param : _trid_15) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3writebus(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "T3writebus";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BTuple<BInteger, BInteger >> _trid_16 = state._tr_T3Read();
                for(const BTuple<BInteger, BInteger >& param : _trid_16) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3Read(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "T3Read";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_T3Poll()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3Poll();
                    copiedState.stateAccessedVia = "T3Poll";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BInteger> _trid_18 = state._tr_T3ReleaseBus();
                for(const BInteger& param : _trid_18) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3ReleaseBus(_tmp_1);
                    copiedState.stateAccessedVia = "T3ReleaseBus";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_T3Wait()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3Wait();
                    copiedState.stateAccessedVia = "T3Wait";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_T3ReEnableWait()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3ReEnableWait();
                    copiedState.stateAccessedVia = "T3ReEnableWait";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BInteger> _trid_21 = state._tr_Update();
                for(const BInteger& param : _trid_21) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.Update(_tmp_1);
                    copiedState.stateAccessedVia = "Update";
                    result.insert(copiedState);
                    transitions += 1;
                }

            }
            return result;
        }

        bool invariantViolated(const CAN_BUS_tlc& state) {
            bool _check_inv_1;
            if(isCaching) {
                CAN_BUS_tlc::_ProjectionRead__check_inv_1 read__check_inv_1_state = state._projected_state_for__check_inv_1();
                auto _obj__check_inv_1_ptr = _InvCache__check_inv_1.find(read__check_inv_1_state);
                if(_obj__check_inv_1_ptr == _InvCache__check_inv_1.end()) {
                    _check_inv_1 = state._check_inv_1();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_1_lock(_ProjectionRead__check_inv_1_mutex);
                        _InvCache__check_inv_1.insert({read__check_inv_1_state, _check_inv_1});
                    }
                } else {
                    _check_inv_1 = _obj__check_inv_1_ptr->second;
                }
            } else {
                _check_inv_1 = state._check_inv_1();
            }
            if(!_check_inv_1) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_1" << "\n";
              return true;
            }
            bool _check_inv_2;
            if(isCaching) {
                CAN_BUS_tlc::_ProjectionRead__check_inv_2 read__check_inv_2_state = state._projected_state_for__check_inv_2();
                auto _obj__check_inv_2_ptr = _InvCache__check_inv_2.find(read__check_inv_2_state);
                if(_obj__check_inv_2_ptr == _InvCache__check_inv_2.end()) {
                    _check_inv_2 = state._check_inv_2();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_2_lock(_ProjectionRead__check_inv_2_mutex);
                        _InvCache__check_inv_2.insert({read__check_inv_2_state, _check_inv_2});
                    }
                } else {
                    _check_inv_2 = _obj__check_inv_2_ptr->second;
                }
            } else {
                _check_inv_2 = state._check_inv_2();
            }
            if(!_check_inv_2) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_2" << "\n";
              return true;
            }
            bool _check_inv_3;
            if(isCaching) {
                CAN_BUS_tlc::_ProjectionRead__check_inv_3 read__check_inv_3_state = state._projected_state_for__check_inv_3();
                auto _obj__check_inv_3_ptr = _InvCache__check_inv_3.find(read__check_inv_3_state);
                if(_obj__check_inv_3_ptr == _InvCache__check_inv_3.end()) {
                    _check_inv_3 = state._check_inv_3();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_3_lock(_ProjectionRead__check_inv_3_mutex);
                        _InvCache__check_inv_3.insert({read__check_inv_3_state, _check_inv_3});
                    }
                } else {
                    _check_inv_3 = _obj__check_inv_3_ptr->second;
                }
            } else {
                _check_inv_3 = state._check_inv_3();
            }
            if(!_check_inv_3) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_3" << "\n";
              return true;
            }
            bool _check_inv_4;
            if(isCaching) {
                CAN_BUS_tlc::_ProjectionRead__check_inv_4 read__check_inv_4_state = state._projected_state_for__check_inv_4();
                auto _obj__check_inv_4_ptr = _InvCache__check_inv_4.find(read__check_inv_4_state);
                if(_obj__check_inv_4_ptr == _InvCache__check_inv_4.end()) {
                    _check_inv_4 = state._check_inv_4();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_4_lock(_ProjectionRead__check_inv_4_mutex);
                        _InvCache__check_inv_4.insert({read__check_inv_4_state, _check_inv_4});
                    }
                } else {
                    _check_inv_4 = _obj__check_inv_4_ptr->second;
                }
            } else {
                _check_inv_4 = state._check_inv_4();
            }
            if(!_check_inv_4) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_4" << "\n";
              return true;
            }
            bool _check_inv_5;
            if(isCaching) {
                CAN_BUS_tlc::_ProjectionRead__check_inv_5 read__check_inv_5_state = state._projected_state_for__check_inv_5();
                auto _obj__check_inv_5_ptr = _InvCache__check_inv_5.find(read__check_inv_5_state);
                if(_obj__check_inv_5_ptr == _InvCache__check_inv_5.end()) {
                    _check_inv_5 = state._check_inv_5();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_5_lock(_ProjectionRead__check_inv_5_mutex);
                        _InvCache__check_inv_5.insert({read__check_inv_5_state, _check_inv_5});
                    }
                } else {
                    _check_inv_5 = _obj__check_inv_5_ptr->second;
                }
            } else {
                _check_inv_5 = state._check_inv_5();
            }
            if(!_check_inv_5) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_5" << "\n";
              return true;
            }
            bool _check_inv_6;
            if(isCaching) {
                CAN_BUS_tlc::_ProjectionRead__check_inv_6 read__check_inv_6_state = state._projected_state_for__check_inv_6();
                auto _obj__check_inv_6_ptr = _InvCache__check_inv_6.find(read__check_inv_6_state);
                if(_obj__check_inv_6_ptr == _InvCache__check_inv_6.end()) {
                    _check_inv_6 = state._check_inv_6();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_6_lock(_ProjectionRead__check_inv_6_mutex);
                        _InvCache__check_inv_6.insert({read__check_inv_6_state, _check_inv_6});
                    }
                } else {
                    _check_inv_6 = _obj__check_inv_6_ptr->second;
                }
            } else {
                _check_inv_6 = state._check_inv_6();
            }
            if(!_check_inv_6) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_6" << "\n";
              return true;
            }
            bool _check_inv_7;
            if(isCaching) {
                CAN_BUS_tlc::_ProjectionRead__check_inv_7 read__check_inv_7_state = state._projected_state_for__check_inv_7();
                auto _obj__check_inv_7_ptr = _InvCache__check_inv_7.find(read__check_inv_7_state);
                if(_obj__check_inv_7_ptr == _InvCache__check_inv_7.end()) {
                    _check_inv_7 = state._check_inv_7();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_7_lock(_ProjectionRead__check_inv_7_mutex);
                        _InvCache__check_inv_7.insert({read__check_inv_7_state, _check_inv_7});
                    }
                } else {
                    _check_inv_7 = _obj__check_inv_7_ptr->second;
                }
            } else {
                _check_inv_7 = state._check_inv_7();
            }
            if(!_check_inv_7) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_7" << "\n";
              return true;
            }
            bool _check_inv_8;
            if(isCaching) {
                CAN_BUS_tlc::_ProjectionRead__check_inv_8 read__check_inv_8_state = state._projected_state_for__check_inv_8();
                auto _obj__check_inv_8_ptr = _InvCache__check_inv_8.find(read__check_inv_8_state);
                if(_obj__check_inv_8_ptr == _InvCache__check_inv_8.end()) {
                    _check_inv_8 = state._check_inv_8();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_8_lock(_ProjectionRead__check_inv_8_mutex);
                        _InvCache__check_inv_8.insert({read__check_inv_8_state, _check_inv_8});
                    }
                } else {
                    _check_inv_8 = _obj__check_inv_8_ptr->second;
                }
            } else {
                _check_inv_8 = state._check_inv_8();
            }
            if(!_check_inv_8) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_8" << "\n";
              return true;
            }
            bool _check_inv_9;
            if(isCaching) {
                CAN_BUS_tlc::_ProjectionRead__check_inv_9 read__check_inv_9_state = state._projected_state_for__check_inv_9();
                auto _obj__check_inv_9_ptr = _InvCache__check_inv_9.find(read__check_inv_9_state);
                if(_obj__check_inv_9_ptr == _InvCache__check_inv_9.end()) {
                    _check_inv_9 = state._check_inv_9();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_9_lock(_ProjectionRead__check_inv_9_mutex);
                        _InvCache__check_inv_9.insert({read__check_inv_9_state, _check_inv_9});
                    }
                } else {
                    _check_inv_9 = _obj__check_inv_9_ptr->second;
                }
            } else {
                _check_inv_9 = state._check_inv_9();
            }
            if(!_check_inv_9) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_9" << "\n";
              return true;
            }
            bool _check_inv_10;
            if(isCaching) {
                CAN_BUS_tlc::_ProjectionRead__check_inv_10 read__check_inv_10_state = state._projected_state_for__check_inv_10();
                auto _obj__check_inv_10_ptr = _InvCache__check_inv_10.find(read__check_inv_10_state);
                if(_obj__check_inv_10_ptr == _InvCache__check_inv_10.end()) {
                    _check_inv_10 = state._check_inv_10();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_10_lock(_ProjectionRead__check_inv_10_mutex);
                        _InvCache__check_inv_10.insert({read__check_inv_10_state, _check_inv_10});
                    }
                } else {
                    _check_inv_10 = _obj__check_inv_10_ptr->second;
                }
            } else {
                _check_inv_10 = state._check_inv_10();
            }
            if(!_check_inv_10) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_10" << "\n";
              return true;
            }
            bool _check_inv_11;
            if(isCaching) {
                CAN_BUS_tlc::_ProjectionRead__check_inv_11 read__check_inv_11_state = state._projected_state_for__check_inv_11();
                auto _obj__check_inv_11_ptr = _InvCache__check_inv_11.find(read__check_inv_11_state);
                if(_obj__check_inv_11_ptr == _InvCache__check_inv_11.end()) {
                    _check_inv_11 = state._check_inv_11();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_11_lock(_ProjectionRead__check_inv_11_mutex);
                        _InvCache__check_inv_11.insert({read__check_inv_11_state, _check_inv_11});
                    }
                } else {
                    _check_inv_11 = _obj__check_inv_11_ptr->second;
                }
            } else {
                _check_inv_11 = state._check_inv_11();
            }
            if(!_check_inv_11) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_11" << "\n";
              return true;
            }
            bool _check_inv_12;
            if(isCaching) {
                CAN_BUS_tlc::_ProjectionRead__check_inv_12 read__check_inv_12_state = state._projected_state_for__check_inv_12();
                auto _obj__check_inv_12_ptr = _InvCache__check_inv_12.find(read__check_inv_12_state);
                if(_obj__check_inv_12_ptr == _InvCache__check_inv_12.end()) {
                    _check_inv_12 = state._check_inv_12();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_12_lock(_ProjectionRead__check_inv_12_mutex);
                        _InvCache__check_inv_12.insert({read__check_inv_12_state, _check_inv_12});
                    }
                } else {
                    _check_inv_12 = _obj__check_inv_12_ptr->second;
                }
            } else {
                _check_inv_12 = state._check_inv_12();
            }
            if(!_check_inv_12) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_12" << "\n";
              return true;
            }
            bool _check_inv_13;
            if(isCaching) {
                CAN_BUS_tlc::_ProjectionRead__check_inv_13 read__check_inv_13_state = state._projected_state_for__check_inv_13();
                auto _obj__check_inv_13_ptr = _InvCache__check_inv_13.find(read__check_inv_13_state);
                if(_obj__check_inv_13_ptr == _InvCache__check_inv_13.end()) {
                    _check_inv_13 = state._check_inv_13();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_13_lock(_ProjectionRead__check_inv_13_mutex);
                        _InvCache__check_inv_13.insert({read__check_inv_13_state, _check_inv_13});
                    }
                } else {
                    _check_inv_13 = _obj__check_inv_13_ptr->second;
                }
            } else {
                _check_inv_13 = state._check_inv_13();
            }
            if(!_check_inv_13) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_13" << "\n";
              return true;
            }
            bool _check_inv_14;
            if(isCaching) {
                CAN_BUS_tlc::_ProjectionRead__check_inv_14 read__check_inv_14_state = state._projected_state_for__check_inv_14();
                auto _obj__check_inv_14_ptr = _InvCache__check_inv_14.find(read__check_inv_14_state);
                if(_obj__check_inv_14_ptr == _InvCache__check_inv_14.end()) {
                    _check_inv_14 = state._check_inv_14();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_14_lock(_ProjectionRead__check_inv_14_mutex);
                        _InvCache__check_inv_14.insert({read__check_inv_14_state, _check_inv_14});
                    }
                } else {
                    _check_inv_14 = _obj__check_inv_14_ptr->second;
                }
            } else {
                _check_inv_14 = state._check_inv_14();
            }
            if(!_check_inv_14) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_14" << "\n";
              return true;
            }
            bool _check_inv_15;
            if(isCaching) {
                CAN_BUS_tlc::_ProjectionRead__check_inv_15 read__check_inv_15_state = state._projected_state_for__check_inv_15();
                auto _obj__check_inv_15_ptr = _InvCache__check_inv_15.find(read__check_inv_15_state);
                if(_obj__check_inv_15_ptr == _InvCache__check_inv_15.end()) {
                    _check_inv_15 = state._check_inv_15();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_15_lock(_ProjectionRead__check_inv_15_mutex);
                        _InvCache__check_inv_15.insert({read__check_inv_15_state, _check_inv_15});
                    }
                } else {
                    _check_inv_15 = _obj__check_inv_15_ptr->second;
                }
            } else {
                _check_inv_15 = state._check_inv_15();
            }
            if(!_check_inv_15) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_15" << "\n";
              return true;
            }
            bool _check_inv_16;
            if(isCaching) {
                CAN_BUS_tlc::_ProjectionRead__check_inv_16 read__check_inv_16_state = state._projected_state_for__check_inv_16();
                auto _obj__check_inv_16_ptr = _InvCache__check_inv_16.find(read__check_inv_16_state);
                if(_obj__check_inv_16_ptr == _InvCache__check_inv_16.end()) {
                    _check_inv_16 = state._check_inv_16();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_16_lock(_ProjectionRead__check_inv_16_mutex);
                        _InvCache__check_inv_16.insert({read__check_inv_16_state, _check_inv_16});
                    }
                } else {
                    _check_inv_16 = _obj__check_inv_16_ptr->second;
                }
            } else {
                _check_inv_16 = state._check_inv_16();
            }
            if(!_check_inv_16) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_16" << "\n";
              return true;
            }
            bool _check_inv_17;
            if(isCaching) {
                CAN_BUS_tlc::_ProjectionRead__check_inv_17 read__check_inv_17_state = state._projected_state_for__check_inv_17();
                auto _obj__check_inv_17_ptr = _InvCache__check_inv_17.find(read__check_inv_17_state);
                if(_obj__check_inv_17_ptr == _InvCache__check_inv_17.end()) {
                    _check_inv_17 = state._check_inv_17();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_17_lock(_ProjectionRead__check_inv_17_mutex);
                        _InvCache__check_inv_17.insert({read__check_inv_17_state, _check_inv_17});
                    }
                } else {
                    _check_inv_17 = _obj__check_inv_17_ptr->second;
                }
            } else {
                _check_inv_17 = state._check_inv_17();
            }
            if(!_check_inv_17) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_17" << "\n";
              return true;
            }
            bool _check_inv_18;
            if(isCaching) {
                CAN_BUS_tlc::_ProjectionRead__check_inv_18 read__check_inv_18_state = state._projected_state_for__check_inv_18();
                auto _obj__check_inv_18_ptr = _InvCache__check_inv_18.find(read__check_inv_18_state);
                if(_obj__check_inv_18_ptr == _InvCache__check_inv_18.end()) {
                    _check_inv_18 = state._check_inv_18();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_18_lock(_ProjectionRead__check_inv_18_mutex);
                        _InvCache__check_inv_18.insert({read__check_inv_18_state, _check_inv_18});
                    }
                } else {
                    _check_inv_18 = _obj__check_inv_18_ptr->second;
                }
            } else {
                _check_inv_18 = state._check_inv_18();
            }
            if(!_check_inv_18) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_18" << "\n";
              return true;
            }
            bool _check_inv_19;
            if(isCaching) {
                CAN_BUS_tlc::_ProjectionRead__check_inv_19 read__check_inv_19_state = state._projected_state_for__check_inv_19();
                auto _obj__check_inv_19_ptr = _InvCache__check_inv_19.find(read__check_inv_19_state);
                if(_obj__check_inv_19_ptr == _InvCache__check_inv_19.end()) {
                    _check_inv_19 = state._check_inv_19();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_19_lock(_ProjectionRead__check_inv_19_mutex);
                        _InvCache__check_inv_19.insert({read__check_inv_19_state, _check_inv_19});
                    }
                } else {
                    _check_inv_19 = _obj__check_inv_19_ptr->second;
                }
            } else {
                _check_inv_19 = state._check_inv_19();
            }
            if(!_check_inv_19) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_19" << "\n";
              return true;
            }
            bool _check_inv_20;
            if(isCaching) {
                CAN_BUS_tlc::_ProjectionRead__check_inv_20 read__check_inv_20_state = state._projected_state_for__check_inv_20();
                auto _obj__check_inv_20_ptr = _InvCache__check_inv_20.find(read__check_inv_20_state);
                if(_obj__check_inv_20_ptr == _InvCache__check_inv_20.end()) {
                    _check_inv_20 = state._check_inv_20();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_20_lock(_ProjectionRead__check_inv_20_mutex);
                        _InvCache__check_inv_20.insert({read__check_inv_20_state, _check_inv_20});
                    }
                } else {
                    _check_inv_20 = _obj__check_inv_20_ptr->second;
                }
            } else {
                _check_inv_20 = state._check_inv_20();
            }
            if(!_check_inv_20) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_20" << "\n";
              return true;
            }
            return false;
        }

        void printResult() {
            if(deadlockDetected || invariantViolatedBool) {
                if(deadlockDetected) {
                    cout << "DEADLOCK DETECTED" << "\n";
                } else {
                    cout << "INVARIANT VIOLATED" << "\n";
                }

                cout << "COUNTER EXAMPLE TRACE: " << "\n";

                std::string trace = "";
                while(parents.find(counterExampleState) != parents.end()) {
                    std::stringstream stringStream;
                    stringStream << counterExampleState;
                    trace.insert(0, stringStream.str());
                    trace.insert(0, "\n");
                    trace.insert(0, counterExampleState.stateAccessedVia);
                    trace.insert(0, "\n\n");
                    counterExampleState = parents[counterExampleState];
                }
                cout << trace;
            } else {
                cout << "MODEL CHECKING SUCCESSFUL" << "\n";
            }

            cout << "Number of States: " << states.size() << "\n";
            cout << "Number of Transitions: " << transitions << "\n";
        }
};

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

    bool isDebug = false;

    ModelChecker modelchecker(type, threads, isCaching, isDebug);
    modelchecker.modelCheck();

    return 0;
}



#endif