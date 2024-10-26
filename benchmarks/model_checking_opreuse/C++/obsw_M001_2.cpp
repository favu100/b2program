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

#ifndef obsw_M001_2_H
#define obsw_M001_2_H

using namespace std;

class obsw_M001_2 {

    public:

        enum Type { BFS, DFS, MIXED };

        class TC_SET : public BObject {
            public:

                typedef TC_SET current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum TC_SET_type {
                    TC_SET1, 
                    TC_SET2
                };

                TC_SET_type value;

                TC_SET(){}

                TC_SET(const TC_SET_type& type) {
                    this->value = type;
                }

                BBoolean equal(const TC_SET& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const TC_SET& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const TC_SET& p1, const TC_SET& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const TC_SET& p1, const TC_SET& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const TC_SET& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const TC_SET& e) {
                    switch(e.value) {
                        case TC_SET1: return strm << "TC_SET1";
                        case TC_SET2: return strm << "TC_SET2";
                    }
                    return strm;
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class TC_STATUSES : public BObject {
            public:

                typedef TC_STATUSES current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum TC_STATUSES_type {
                    TC_Unchecked, 
                    TC_Accepted, 
                    TC_Rejected, 
                    TC_Waiting_for_Execution, 
                    TC_Successfully_Executed, 
                    TC_Execution_Failed, 
                    TC_Removable
                };

                TC_STATUSES_type value;

                TC_STATUSES(){}

                TC_STATUSES(const TC_STATUSES_type& type) {
                    this->value = type;
                }

                BBoolean equal(const TC_STATUSES& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const TC_STATUSES& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const TC_STATUSES& p1, const TC_STATUSES& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const TC_STATUSES& p1, const TC_STATUSES& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const TC_STATUSES& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const TC_STATUSES& e) {
                    switch(e.value) {
                        case TC_Unchecked: return strm << "TC_Unchecked";
                        case TC_Accepted: return strm << "TC_Accepted";
                        case TC_Rejected: return strm << "TC_Rejected";
                        case TC_Waiting_for_Execution: return strm << "TC_Waiting_for_Execution";
                        case TC_Successfully_Executed: return strm << "TC_Successfully_Executed";
                        case TC_Execution_Failed: return strm << "TC_Execution_Failed";
                        case TC_Removable: return strm << "TC_Removable";
                    }
                    return strm;
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class TM_STATUSES : public BObject {
            public:

                typedef TM_STATUSES current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum TM_STATUSES_type {
                    TM_Effective, 
                    TM_Removable
                };

                TM_STATUSES_type value;

                TM_STATUSES(){}

                TM_STATUSES(const TM_STATUSES_type& type) {
                    this->value = type;
                }

                BBoolean equal(const TM_STATUSES& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const TM_STATUSES& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const TM_STATUSES& p1, const TM_STATUSES& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const TM_STATUSES& p1, const TM_STATUSES& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const TM_STATUSES& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const TM_STATUSES& e) {
                    switch(e.value) {
                        case TM_Effective: return strm << "TM_Effective";
                        case TM_Removable: return strm << "TM_Removable";
                    }
                    return strm;
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class PACKET_START_ADDRESSES_IN_TC_BUFFER : public BObject {
            public:

                typedef PACKET_START_ADDRESSES_IN_TC_BUFFER current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum PACKET_START_ADDRESSES_IN_TC_BUFFER_type {
                    PACKET_START_ADDRESSES_IN_TC_BUFFER1, 
                    PACKET_START_ADDRESSES_IN_TC_BUFFER2
                };

                PACKET_START_ADDRESSES_IN_TC_BUFFER_type value;

                PACKET_START_ADDRESSES_IN_TC_BUFFER(){}

                PACKET_START_ADDRESSES_IN_TC_BUFFER(const PACKET_START_ADDRESSES_IN_TC_BUFFER_type& type) {
                    this->value = type;
                }

                BBoolean equal(const PACKET_START_ADDRESSES_IN_TC_BUFFER& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const PACKET_START_ADDRESSES_IN_TC_BUFFER& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const PACKET_START_ADDRESSES_IN_TC_BUFFER& p1, const PACKET_START_ADDRESSES_IN_TC_BUFFER& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const PACKET_START_ADDRESSES_IN_TC_BUFFER& p1, const PACKET_START_ADDRESSES_IN_TC_BUFFER& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const PACKET_START_ADDRESSES_IN_TC_BUFFER& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const PACKET_START_ADDRESSES_IN_TC_BUFFER& e) {
                    switch(e.value) {
                        case PACKET_START_ADDRESSES_IN_TC_BUFFER1: return strm << "PACKET_START_ADDRESSES_IN_TC_BUFFER1";
                        case PACKET_START_ADDRESSES_IN_TC_BUFFER2: return strm << "PACKET_START_ADDRESSES_IN_TC_BUFFER2";
                    }
                    return strm;
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class PACKET_START_ADDRESSES_IN_TC_POOL : public BObject {
            public:

                typedef PACKET_START_ADDRESSES_IN_TC_POOL current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum PACKET_START_ADDRESSES_IN_TC_POOL_type {
                    PACKET_START_ADDRESSES_IN_TC_POOL1, 
                    PACKET_START_ADDRESSES_IN_TC_POOL2
                };

                PACKET_START_ADDRESSES_IN_TC_POOL_type value;

                PACKET_START_ADDRESSES_IN_TC_POOL(){}

                PACKET_START_ADDRESSES_IN_TC_POOL(const PACKET_START_ADDRESSES_IN_TC_POOL_type& type) {
                    this->value = type;
                }

                BBoolean equal(const PACKET_START_ADDRESSES_IN_TC_POOL& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const PACKET_START_ADDRESSES_IN_TC_POOL& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const PACKET_START_ADDRESSES_IN_TC_POOL& p1, const PACKET_START_ADDRESSES_IN_TC_POOL& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const PACKET_START_ADDRESSES_IN_TC_POOL& p1, const PACKET_START_ADDRESSES_IN_TC_POOL& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const PACKET_START_ADDRESSES_IN_TC_POOL& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const PACKET_START_ADDRESSES_IN_TC_POOL& e) {
                    switch(e.value) {
                        case PACKET_START_ADDRESSES_IN_TC_POOL1: return strm << "PACKET_START_ADDRESSES_IN_TC_POOL1";
                        case PACKET_START_ADDRESSES_IN_TC_POOL2: return strm << "PACKET_START_ADDRESSES_IN_TC_POOL2";
                    }
                    return strm;
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class PACKET_START_ADDRESSES_IN_TM_BUFFER : public BObject {
            public:

                typedef PACKET_START_ADDRESSES_IN_TM_BUFFER current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum PACKET_START_ADDRESSES_IN_TM_BUFFER_type {
                    PACKET_START_ADDRESSES_IN_TM_BUFFER1, 
                    PACKET_START_ADDRESSES_IN_TM_BUFFER2
                };

                PACKET_START_ADDRESSES_IN_TM_BUFFER_type value;

                PACKET_START_ADDRESSES_IN_TM_BUFFER(){}

                PACKET_START_ADDRESSES_IN_TM_BUFFER(const PACKET_START_ADDRESSES_IN_TM_BUFFER_type& type) {
                    this->value = type;
                }

                BBoolean equal(const PACKET_START_ADDRESSES_IN_TM_BUFFER& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const PACKET_START_ADDRESSES_IN_TM_BUFFER& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const PACKET_START_ADDRESSES_IN_TM_BUFFER& p1, const PACKET_START_ADDRESSES_IN_TM_BUFFER& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const PACKET_START_ADDRESSES_IN_TM_BUFFER& p1, const PACKET_START_ADDRESSES_IN_TM_BUFFER& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const PACKET_START_ADDRESSES_IN_TM_BUFFER& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const PACKET_START_ADDRESSES_IN_TM_BUFFER& e) {
                    switch(e.value) {
                        case PACKET_START_ADDRESSES_IN_TM_BUFFER1: return strm << "PACKET_START_ADDRESSES_IN_TM_BUFFER1";
                        case PACKET_START_ADDRESSES_IN_TM_BUFFER2: return strm << "PACKET_START_ADDRESSES_IN_TM_BUFFER2";
                    }
                    return strm;
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class PACKET_START_ADDRESSES_IN_TM_POOL : public BObject {
            public:

                typedef PACKET_START_ADDRESSES_IN_TM_POOL current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum PACKET_START_ADDRESSES_IN_TM_POOL_type {
                    PACKET_START_ADDRESSES_IN_TM_POOL1, 
                    PACKET_START_ADDRESSES_IN_TM_POOL2
                };

                PACKET_START_ADDRESSES_IN_TM_POOL_type value;

                PACKET_START_ADDRESSES_IN_TM_POOL(){}

                PACKET_START_ADDRESSES_IN_TM_POOL(const PACKET_START_ADDRESSES_IN_TM_POOL_type& type) {
                    this->value = type;
                }

                BBoolean equal(const PACKET_START_ADDRESSES_IN_TM_POOL& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const PACKET_START_ADDRESSES_IN_TM_POOL& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const PACKET_START_ADDRESSES_IN_TM_POOL& p1, const PACKET_START_ADDRESSES_IN_TM_POOL& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const PACKET_START_ADDRESSES_IN_TM_POOL& p1, const PACKET_START_ADDRESSES_IN_TM_POOL& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const PACKET_START_ADDRESSES_IN_TM_POOL& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const PACKET_START_ADDRESSES_IN_TM_POOL& e) {
                    switch(e.value) {
                        case PACKET_START_ADDRESSES_IN_TM_POOL1: return strm << "PACKET_START_ADDRESSES_IN_TM_POOL1";
                        case PACKET_START_ADDRESSES_IN_TM_POOL2: return strm << "PACKET_START_ADDRESSES_IN_TM_POOL2";
                    }
                    return strm;
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class TM_SET : public BObject {
            public:

                typedef TM_SET current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum TM_SET_type {
                    TM_SET1, 
                    TM_SET2
                };

                TM_SET_type value;

                TM_SET(){}

                TM_SET(const TM_SET_type& type) {
                    this->value = type;
                }

                BBoolean equal(const TM_SET& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const TM_SET& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const TM_SET& p1, const TM_SET& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const TM_SET& p1, const TM_SET& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const TM_SET& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const TM_SET& e) {
                    switch(e.value) {
                        case TM_SET1: return strm << "TM_SET1";
                        case TM_SET2: return strm << "TM_SET2";
                    }
                    return strm;
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };


        struct Hash {
            public:
                size_t operator()(const obsw_M001_2& obj) const {
                    return obj.hashCode();
                }
        };

        struct HashEqual {
            public:
                bool operator()(const obsw_M001_2& obj1, const obsw_M001_2& obj2) const {
                    if (obj1 == obj2)
                        return true;
                    else
                        return false;
                    }
            };

        class _ProjectionRead_env_Receive_TC {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_env_Receive_TC& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_env_Receive_TC& obj1, const _ProjectionRead_env_Receive_TC& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET > TCbuffer;

                _ProjectionRead_env_Receive_TC(const BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET >& TCbuffer) {
                    this->TCbuffer = TCbuffer;
                }

                friend bool operator ==(const _ProjectionRead_env_Receive_TC& o1, const _ProjectionRead_env_Receive_TC& o2) {
                    return o1.TCbuffer == (o2.TCbuffer);
                }

                friend bool operator !=(const _ProjectionRead_env_Receive_TC& o1, const _ProjectionRead_env_Receive_TC& o2) {
                    return o1.TCbuffer != (o2.TCbuffer);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_env_Receive_TC& e) {
                    strm << "{";
                    strm << "TCbuffer: " << e.TCbuffer;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCbuffer.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_env_Receive_TC {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_env_Receive_TC& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_env_Receive_TC& obj1, const _ProjectionRead__tr_env_Receive_TC& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET > TCbuffer;

                _ProjectionRead__tr_env_Receive_TC(const BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET >& TCbuffer) {
                    this->TCbuffer = TCbuffer;
                }

                friend bool operator ==(const _ProjectionRead__tr_env_Receive_TC& o1, const _ProjectionRead__tr_env_Receive_TC& o2) {
                    return o1.TCbuffer == (o2.TCbuffer);
                }

                friend bool operator !=(const _ProjectionRead__tr_env_Receive_TC& o1, const _ProjectionRead__tr_env_Receive_TC& o2) {
                    return o1.TCbuffer != (o2.TCbuffer);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_env_Receive_TC& e) {
                    strm << "{";
                    strm << "TCbuffer: " << e.TCbuffer;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCbuffer.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_env_Receive_TC {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_env_Receive_TC& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_env_Receive_TC& obj1, const _ProjectionWrite_env_Receive_TC& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET > TCbuffer;

                _ProjectionWrite_env_Receive_TC(const BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET >& TCbuffer) {
                    this->TCbuffer = TCbuffer;
                }

                friend bool operator ==(const _ProjectionWrite_env_Receive_TC& o1, const _ProjectionWrite_env_Receive_TC& o2) {
                    return o1.TCbuffer == (o2.TCbuffer);
                }

                friend bool operator !=(const _ProjectionWrite_env_Receive_TC& o1, const _ProjectionWrite_env_Receive_TC& o2) {
                    return o1.TCbuffer != (o2.TCbuffer);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_env_Receive_TC& e) {
                    strm << "{";
                    strm << "TCbuffer: " << e.TCbuffer;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCbuffer.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_Poll_TC {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_Poll_TC& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_Poll_TC& obj1, const _ProjectionRead_Poll_TC& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET > TCbuffer;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead_Poll_TC(const BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET >& TCbuffer, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCbuffer = TCbuffer;
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead_Poll_TC& o1, const _ProjectionRead_Poll_TC& o2) {
                    return o1.TCbuffer == (o2.TCbuffer) && o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead_Poll_TC& o1, const _ProjectionRead_Poll_TC& o2) {
                    return o1.TCbuffer != (o2.TCbuffer) || o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_Poll_TC& e) {
                    strm << "{";
                    strm << "TCbuffer: " << e.TCbuffer;
                    strm << ", ";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", ";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCbuffer.hashCode() << 1);
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_Poll_TC {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_Poll_TC& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_Poll_TC& obj1, const _ProjectionRead__tr_Poll_TC& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET > TCbuffer;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;

                _ProjectionRead__tr_Poll_TC(const BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET >& TCbuffer, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool) {
                    this->TCbuffer = TCbuffer;
                    this->TCpool = TCpool;
                }

                friend bool operator ==(const _ProjectionRead__tr_Poll_TC& o1, const _ProjectionRead__tr_Poll_TC& o2) {
                    return o1.TCbuffer == (o2.TCbuffer) && o1.TCpool == (o2.TCpool);
                }

                friend bool operator !=(const _ProjectionRead__tr_Poll_TC& o1, const _ProjectionRead__tr_Poll_TC& o2) {
                    return o1.TCbuffer != (o2.TCbuffer) || o1.TCpool != (o2.TCpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_Poll_TC& e) {
                    strm << "{";
                    strm << "TCbuffer: " << e.TCbuffer;
                    strm << ", "; 
                    strm << "TCpool: " << e.TCpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCbuffer.hashCode() << 1);
                    result = 31 * result + (TCpool.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_Poll_TC {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_Poll_TC& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_Poll_TC& obj1, const _ProjectionWrite_Poll_TC& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET > TCbuffer;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionWrite_Poll_TC(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET >& TCbuffer, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCbuffer = TCbuffer;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionWrite_Poll_TC& o1, const _ProjectionWrite_Poll_TC& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCbuffer == (o2.TCbuffer) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionWrite_Poll_TC& o1, const _ProjectionWrite_Poll_TC& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCbuffer != (o2.TCbuffer) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_Poll_TC& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", ";
                    strm << "TCbuffer: " << e.TCbuffer;
                    strm << ", ";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCbuffer.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_Accept_TC {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_Accept_TC& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_Accept_TC& obj1, const _ProjectionRead_Accept_TC& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead_Accept_TC(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead_Accept_TC& o1, const _ProjectionRead_Accept_TC& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead_Accept_TC& o1, const _ProjectionRead_Accept_TC& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_Accept_TC& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", ";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_Accept_TC {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_Accept_TC& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_Accept_TC& obj1, const _ProjectionRead__tr_Accept_TC& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead__tr_Accept_TC(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead__tr_Accept_TC& o1, const _ProjectionRead__tr_Accept_TC& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead__tr_Accept_TC& o1, const _ProjectionRead__tr_Accept_TC& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_Accept_TC& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", "; 
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_Accept_TC {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_Accept_TC& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_Accept_TC& obj1, const _ProjectionWrite_Accept_TC& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionWrite_Accept_TC(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionWrite_Accept_TC& o1, const _ProjectionWrite_Accept_TC& o2) {
                    return o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionWrite_Accept_TC& o1, const _ProjectionWrite_Accept_TC& o2) {
                    return o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_Accept_TC& e) {
                    strm << "{";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_Reject_TC {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_Reject_TC& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_Reject_TC& obj1, const _ProjectionRead_Reject_TC& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead_Reject_TC(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead_Reject_TC& o1, const _ProjectionRead_Reject_TC& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead_Reject_TC& o1, const _ProjectionRead_Reject_TC& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_Reject_TC& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", ";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_Reject_TC {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_Reject_TC& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_Reject_TC& obj1, const _ProjectionRead__tr_Reject_TC& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead__tr_Reject_TC(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead__tr_Reject_TC& o1, const _ProjectionRead__tr_Reject_TC& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead__tr_Reject_TC& o1, const _ProjectionRead__tr_Reject_TC& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_Reject_TC& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", "; 
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_Reject_TC {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_Reject_TC& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_Reject_TC& obj1, const _ProjectionWrite_Reject_TC& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionWrite_Reject_TC(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionWrite_Reject_TC& o1, const _ProjectionWrite_Reject_TC& o2) {
                    return o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionWrite_Reject_TC& o1, const _ProjectionWrite_Reject_TC& o2) {
                    return o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_Reject_TC& e) {
                    strm << "{";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_Report_TC_Acceptance {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_Report_TC_Acceptance& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_Report_TC_Acceptance& obj1, const _ProjectionRead_Report_TC_Acceptance& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionRead_Report_TC_Acceptance(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >& TMstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                    this->TMstatus = TMstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionRead_Report_TC_Acceptance& o1, const _ProjectionRead_Report_TC_Acceptance& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus) && o1.TMstatus == (o2.TMstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionRead_Report_TC_Acceptance& o1, const _ProjectionRead_Report_TC_Acceptance& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus) || o1.TMstatus != (o2.TMstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_Report_TC_Acceptance& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", ";
                    strm << "TCstatus: " << e.TCstatus;
                    strm << ", ";
                    strm << "TMstatus: " << e.TMstatus;
                    strm << ", ";
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    result = 31 * result + (TMstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_Report_TC_Acceptance {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_Report_TC_Acceptance& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_Report_TC_Acceptance& obj1, const _ProjectionRead__tr_Report_TC_Acceptance& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionRead__tr_Report_TC_Acceptance(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionRead__tr_Report_TC_Acceptance& o1, const _ProjectionRead__tr_Report_TC_Acceptance& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionRead__tr_Report_TC_Acceptance& o1, const _ProjectionRead__tr_Report_TC_Acceptance& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_Report_TC_Acceptance& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", "; 
                    strm << "TCstatus: " << e.TCstatus;
                    strm << ", "; 
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_Report_TC_Acceptance {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_Report_TC_Acceptance& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_Report_TC_Acceptance& obj1, const _ProjectionWrite_Report_TC_Acceptance& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionWrite_Report_TC_Acceptance(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >& TMstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TCstatus = TCstatus;
                    this->TMstatus = TMstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionWrite_Report_TC_Acceptance& o1, const _ProjectionWrite_Report_TC_Acceptance& o2) {
                    return o1.TCstatus == (o2.TCstatus) && o1.TMstatus == (o2.TMstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionWrite_Report_TC_Acceptance& o1, const _ProjectionWrite_Report_TC_Acceptance& o2) {
                    return o1.TCstatus != (o2.TCstatus) || o1.TMstatus != (o2.TMstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_Report_TC_Acceptance& e) {
                    strm << "{";
                    strm << "TCstatus: " << e.TCstatus;
                    strm << ", ";
                    strm << "TMstatus: " << e.TMstatus;
                    strm << ", ";
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    result = 31 * result + (TMstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_Skip_TC_Acceptance_Report {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_Skip_TC_Acceptance_Report& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_Skip_TC_Acceptance_Report& obj1, const _ProjectionRead_Skip_TC_Acceptance_Report& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead_Skip_TC_Acceptance_Report(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead_Skip_TC_Acceptance_Report& o1, const _ProjectionRead_Skip_TC_Acceptance_Report& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead_Skip_TC_Acceptance_Report& o1, const _ProjectionRead_Skip_TC_Acceptance_Report& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_Skip_TC_Acceptance_Report& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", ";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_Skip_TC_Acceptance_Report {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_Skip_TC_Acceptance_Report& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_Skip_TC_Acceptance_Report& obj1, const _ProjectionRead__tr_Skip_TC_Acceptance_Report& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead__tr_Skip_TC_Acceptance_Report(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead__tr_Skip_TC_Acceptance_Report& o1, const _ProjectionRead__tr_Skip_TC_Acceptance_Report& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead__tr_Skip_TC_Acceptance_Report& o1, const _ProjectionRead__tr_Skip_TC_Acceptance_Report& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_Skip_TC_Acceptance_Report& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", "; 
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_Skip_TC_Acceptance_Report {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_Skip_TC_Acceptance_Report& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_Skip_TC_Acceptance_Report& obj1, const _ProjectionWrite_Skip_TC_Acceptance_Report& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionWrite_Skip_TC_Acceptance_Report(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionWrite_Skip_TC_Acceptance_Report& o1, const _ProjectionWrite_Skip_TC_Acceptance_Report& o2) {
                    return o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionWrite_Skip_TC_Acceptance_Report& o1, const _ProjectionWrite_Skip_TC_Acceptance_Report& o2) {
                    return o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_Skip_TC_Acceptance_Report& e) {
                    strm << "{";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_Report_TC_Rejection {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_Report_TC_Rejection& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_Report_TC_Rejection& obj1, const _ProjectionRead_Report_TC_Rejection& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionRead_Report_TC_Rejection(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >& TMstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                    this->TMstatus = TMstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionRead_Report_TC_Rejection& o1, const _ProjectionRead_Report_TC_Rejection& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus) && o1.TMstatus == (o2.TMstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionRead_Report_TC_Rejection& o1, const _ProjectionRead_Report_TC_Rejection& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus) || o1.TMstatus != (o2.TMstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_Report_TC_Rejection& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", ";
                    strm << "TCstatus: " << e.TCstatus;
                    strm << ", ";
                    strm << "TMstatus: " << e.TMstatus;
                    strm << ", ";
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    result = 31 * result + (TMstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_Report_TC_Rejection {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_Report_TC_Rejection& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_Report_TC_Rejection& obj1, const _ProjectionRead__tr_Report_TC_Rejection& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionRead__tr_Report_TC_Rejection(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionRead__tr_Report_TC_Rejection& o1, const _ProjectionRead__tr_Report_TC_Rejection& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionRead__tr_Report_TC_Rejection& o1, const _ProjectionRead__tr_Report_TC_Rejection& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_Report_TC_Rejection& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", "; 
                    strm << "TCstatus: " << e.TCstatus;
                    strm << ", "; 
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_Report_TC_Rejection {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_Report_TC_Rejection& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_Report_TC_Rejection& obj1, const _ProjectionWrite_Report_TC_Rejection& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionWrite_Report_TC_Rejection(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >& TMstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TCstatus = TCstatus;
                    this->TMstatus = TMstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionWrite_Report_TC_Rejection& o1, const _ProjectionWrite_Report_TC_Rejection& o2) {
                    return o1.TCstatus == (o2.TCstatus) && o1.TMstatus == (o2.TMstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionWrite_Report_TC_Rejection& o1, const _ProjectionWrite_Report_TC_Rejection& o2) {
                    return o1.TCstatus != (o2.TCstatus) || o1.TMstatus != (o2.TMstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_Report_TC_Rejection& e) {
                    strm << "{";
                    strm << "TCstatus: " << e.TCstatus;
                    strm << ", ";
                    strm << "TMstatus: " << e.TMstatus;
                    strm << ", ";
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    result = 31 * result + (TMstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_Skip_TC_Rejection_Report {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_Skip_TC_Rejection_Report& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_Skip_TC_Rejection_Report& obj1, const _ProjectionRead_Skip_TC_Rejection_Report& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead_Skip_TC_Rejection_Report(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead_Skip_TC_Rejection_Report& o1, const _ProjectionRead_Skip_TC_Rejection_Report& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead_Skip_TC_Rejection_Report& o1, const _ProjectionRead_Skip_TC_Rejection_Report& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_Skip_TC_Rejection_Report& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", ";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_Skip_TC_Rejection_Report {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_Skip_TC_Rejection_Report& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_Skip_TC_Rejection_Report& obj1, const _ProjectionRead__tr_Skip_TC_Rejection_Report& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead__tr_Skip_TC_Rejection_Report(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead__tr_Skip_TC_Rejection_Report& o1, const _ProjectionRead__tr_Skip_TC_Rejection_Report& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead__tr_Skip_TC_Rejection_Report& o1, const _ProjectionRead__tr_Skip_TC_Rejection_Report& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_Skip_TC_Rejection_Report& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", "; 
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_Skip_TC_Rejection_Report {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_Skip_TC_Rejection_Report& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_Skip_TC_Rejection_Report& obj1, const _ProjectionWrite_Skip_TC_Rejection_Report& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionWrite_Skip_TC_Rejection_Report(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionWrite_Skip_TC_Rejection_Report& o1, const _ProjectionWrite_Skip_TC_Rejection_Report& o2) {
                    return o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionWrite_Skip_TC_Rejection_Report& o1, const _ProjectionWrite_Skip_TC_Rejection_Report& o2) {
                    return o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_Skip_TC_Rejection_Report& e) {
                    strm << "{";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_Execute_TC_Successfully {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_Execute_TC_Successfully& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_Execute_TC_Successfully& obj1, const _ProjectionRead_Execute_TC_Successfully& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead_Execute_TC_Successfully(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead_Execute_TC_Successfully& o1, const _ProjectionRead_Execute_TC_Successfully& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead_Execute_TC_Successfully& o1, const _ProjectionRead_Execute_TC_Successfully& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_Execute_TC_Successfully& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", ";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_Execute_TC_Successfully {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_Execute_TC_Successfully& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_Execute_TC_Successfully& obj1, const _ProjectionRead__tr_Execute_TC_Successfully& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead__tr_Execute_TC_Successfully(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead__tr_Execute_TC_Successfully& o1, const _ProjectionRead__tr_Execute_TC_Successfully& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead__tr_Execute_TC_Successfully& o1, const _ProjectionRead__tr_Execute_TC_Successfully& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_Execute_TC_Successfully& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", "; 
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_Execute_TC_Successfully {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_Execute_TC_Successfully& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_Execute_TC_Successfully& obj1, const _ProjectionWrite_Execute_TC_Successfully& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionWrite_Execute_TC_Successfully(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionWrite_Execute_TC_Successfully& o1, const _ProjectionWrite_Execute_TC_Successfully& o2) {
                    return o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionWrite_Execute_TC_Successfully& o1, const _ProjectionWrite_Execute_TC_Successfully& o2) {
                    return o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_Execute_TC_Successfully& e) {
                    strm << "{";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_Reset_TM_Buffer {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_Reset_TM_Buffer& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_Reset_TM_Buffer& obj1, const _ProjectionRead_Reset_TM_Buffer& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead_Reset_TM_Buffer(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead_Reset_TM_Buffer& o1, const _ProjectionRead_Reset_TM_Buffer& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead_Reset_TM_Buffer& o1, const _ProjectionRead_Reset_TM_Buffer& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_Reset_TM_Buffer& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", ";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_Reset_TM_Buffer {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_Reset_TM_Buffer& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_Reset_TM_Buffer& obj1, const _ProjectionRead__tr_Reset_TM_Buffer& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead__tr_Reset_TM_Buffer(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead__tr_Reset_TM_Buffer& o1, const _ProjectionRead__tr_Reset_TM_Buffer& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead__tr_Reset_TM_Buffer& o1, const _ProjectionRead__tr_Reset_TM_Buffer& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_Reset_TM_Buffer& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", "; 
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_Reset_TM_Buffer {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_Reset_TM_Buffer& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_Reset_TM_Buffer& obj1, const _ProjectionWrite_Reset_TM_Buffer& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET > TMbuffer;

                _ProjectionWrite_Reset_TM_Buffer(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET >& TMbuffer) {
                    this->TCstatus = TCstatus;
                    this->TMbuffer = TMbuffer;
                }

                friend bool operator ==(const _ProjectionWrite_Reset_TM_Buffer& o1, const _ProjectionWrite_Reset_TM_Buffer& o2) {
                    return o1.TCstatus == (o2.TCstatus) && o1.TMbuffer == (o2.TMbuffer);
                }

                friend bool operator !=(const _ProjectionWrite_Reset_TM_Buffer& o1, const _ProjectionWrite_Reset_TM_Buffer& o2) {
                    return o1.TCstatus != (o2.TCstatus) || o1.TMbuffer != (o2.TMbuffer);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_Reset_TM_Buffer& e) {
                    strm << "{";
                    strm << "TCstatus: " << e.TCstatus;
                    strm << ", ";
                    strm << "TMbuffer: " << e.TMbuffer;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    result = 31 * result + (TMbuffer.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_Fail_TC_Execution {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_Fail_TC_Execution& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_Fail_TC_Execution& obj1, const _ProjectionRead_Fail_TC_Execution& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead_Fail_TC_Execution(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead_Fail_TC_Execution& o1, const _ProjectionRead_Fail_TC_Execution& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead_Fail_TC_Execution& o1, const _ProjectionRead_Fail_TC_Execution& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_Fail_TC_Execution& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", ";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_Fail_TC_Execution {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_Fail_TC_Execution& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_Fail_TC_Execution& obj1, const _ProjectionRead__tr_Fail_TC_Execution& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead__tr_Fail_TC_Execution(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead__tr_Fail_TC_Execution& o1, const _ProjectionRead__tr_Fail_TC_Execution& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead__tr_Fail_TC_Execution& o1, const _ProjectionRead__tr_Fail_TC_Execution& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_Fail_TC_Execution& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", "; 
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_Fail_TC_Execution {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_Fail_TC_Execution& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_Fail_TC_Execution& obj1, const _ProjectionWrite_Fail_TC_Execution& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionWrite_Fail_TC_Execution(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionWrite_Fail_TC_Execution& o1, const _ProjectionWrite_Fail_TC_Execution& o2) {
                    return o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionWrite_Fail_TC_Execution& o1, const _ProjectionWrite_Fail_TC_Execution& o2) {
                    return o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_Fail_TC_Execution& e) {
                    strm << "{";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_Report_TC_Execution_Success {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_Report_TC_Execution_Success& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_Report_TC_Execution_Success& obj1, const _ProjectionRead_Report_TC_Execution_Success& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionRead_Report_TC_Execution_Success(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >& TMstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                    this->TMstatus = TMstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionRead_Report_TC_Execution_Success& o1, const _ProjectionRead_Report_TC_Execution_Success& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus) && o1.TMstatus == (o2.TMstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionRead_Report_TC_Execution_Success& o1, const _ProjectionRead_Report_TC_Execution_Success& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus) || o1.TMstatus != (o2.TMstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_Report_TC_Execution_Success& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", ";
                    strm << "TCstatus: " << e.TCstatus;
                    strm << ", ";
                    strm << "TMstatus: " << e.TMstatus;
                    strm << ", ";
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    result = 31 * result + (TMstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_Report_TC_Execution_Success {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_Report_TC_Execution_Success& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_Report_TC_Execution_Success& obj1, const _ProjectionRead__tr_Report_TC_Execution_Success& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionRead__tr_Report_TC_Execution_Success(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionRead__tr_Report_TC_Execution_Success& o1, const _ProjectionRead__tr_Report_TC_Execution_Success& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionRead__tr_Report_TC_Execution_Success& o1, const _ProjectionRead__tr_Report_TC_Execution_Success& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_Report_TC_Execution_Success& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", "; 
                    strm << "TCstatus: " << e.TCstatus;
                    strm << ", "; 
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_Report_TC_Execution_Success {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_Report_TC_Execution_Success& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_Report_TC_Execution_Success& obj1, const _ProjectionWrite_Report_TC_Execution_Success& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionWrite_Report_TC_Execution_Success(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >& TMstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TCstatus = TCstatus;
                    this->TMstatus = TMstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionWrite_Report_TC_Execution_Success& o1, const _ProjectionWrite_Report_TC_Execution_Success& o2) {
                    return o1.TCstatus == (o2.TCstatus) && o1.TMstatus == (o2.TMstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionWrite_Report_TC_Execution_Success& o1, const _ProjectionWrite_Report_TC_Execution_Success& o2) {
                    return o1.TCstatus != (o2.TCstatus) || o1.TMstatus != (o2.TMstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_Report_TC_Execution_Success& e) {
                    strm << "{";
                    strm << "TCstatus: " << e.TCstatus;
                    strm << ", ";
                    strm << "TMstatus: " << e.TMstatus;
                    strm << ", ";
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    result = 31 * result + (TMstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_Skip_TC_Success_Report {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_Skip_TC_Success_Report& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_Skip_TC_Success_Report& obj1, const _ProjectionRead_Skip_TC_Success_Report& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead_Skip_TC_Success_Report(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead_Skip_TC_Success_Report& o1, const _ProjectionRead_Skip_TC_Success_Report& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead_Skip_TC_Success_Report& o1, const _ProjectionRead_Skip_TC_Success_Report& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_Skip_TC_Success_Report& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", ";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_Skip_TC_Success_Report {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_Skip_TC_Success_Report& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_Skip_TC_Success_Report& obj1, const _ProjectionRead__tr_Skip_TC_Success_Report& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead__tr_Skip_TC_Success_Report(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead__tr_Skip_TC_Success_Report& o1, const _ProjectionRead__tr_Skip_TC_Success_Report& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead__tr_Skip_TC_Success_Report& o1, const _ProjectionRead__tr_Skip_TC_Success_Report& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_Skip_TC_Success_Report& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", "; 
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_Skip_TC_Success_Report {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_Skip_TC_Success_Report& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_Skip_TC_Success_Report& obj1, const _ProjectionWrite_Skip_TC_Success_Report& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionWrite_Skip_TC_Success_Report(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionWrite_Skip_TC_Success_Report& o1, const _ProjectionWrite_Skip_TC_Success_Report& o2) {
                    return o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionWrite_Skip_TC_Success_Report& o1, const _ProjectionWrite_Skip_TC_Success_Report& o2) {
                    return o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_Skip_TC_Success_Report& e) {
                    strm << "{";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_Report_TC_Execution_Failure {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_Report_TC_Execution_Failure& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_Report_TC_Execution_Failure& obj1, const _ProjectionRead_Report_TC_Execution_Failure& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionRead_Report_TC_Execution_Failure(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >& TMstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                    this->TMstatus = TMstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionRead_Report_TC_Execution_Failure& o1, const _ProjectionRead_Report_TC_Execution_Failure& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus) && o1.TMstatus == (o2.TMstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionRead_Report_TC_Execution_Failure& o1, const _ProjectionRead_Report_TC_Execution_Failure& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus) || o1.TMstatus != (o2.TMstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_Report_TC_Execution_Failure& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", ";
                    strm << "TCstatus: " << e.TCstatus;
                    strm << ", ";
                    strm << "TMstatus: " << e.TMstatus;
                    strm << ", ";
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    result = 31 * result + (TMstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_Report_TC_Execution_Failure {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_Report_TC_Execution_Failure& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_Report_TC_Execution_Failure& obj1, const _ProjectionRead__tr_Report_TC_Execution_Failure& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionRead__tr_Report_TC_Execution_Failure(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionRead__tr_Report_TC_Execution_Failure& o1, const _ProjectionRead__tr_Report_TC_Execution_Failure& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionRead__tr_Report_TC_Execution_Failure& o1, const _ProjectionRead__tr_Report_TC_Execution_Failure& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_Report_TC_Execution_Failure& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", "; 
                    strm << "TCstatus: " << e.TCstatus;
                    strm << ", "; 
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_Report_TC_Execution_Failure {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_Report_TC_Execution_Failure& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_Report_TC_Execution_Failure& obj1, const _ProjectionWrite_Report_TC_Execution_Failure& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionWrite_Report_TC_Execution_Failure(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >& TMstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TCstatus = TCstatus;
                    this->TMstatus = TMstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionWrite_Report_TC_Execution_Failure& o1, const _ProjectionWrite_Report_TC_Execution_Failure& o2) {
                    return o1.TCstatus == (o2.TCstatus) && o1.TMstatus == (o2.TMstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionWrite_Report_TC_Execution_Failure& o1, const _ProjectionWrite_Report_TC_Execution_Failure& o2) {
                    return o1.TCstatus != (o2.TCstatus) || o1.TMstatus != (o2.TMstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_Report_TC_Execution_Failure& e) {
                    strm << "{";
                    strm << "TCstatus: " << e.TCstatus;
                    strm << ", ";
                    strm << "TMstatus: " << e.TMstatus;
                    strm << ", ";
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    result = 31 * result + (TMstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_Skip_TC_Failure_Report {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_Skip_TC_Failure_Report& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_Skip_TC_Failure_Report& obj1, const _ProjectionRead_Skip_TC_Failure_Report& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead_Skip_TC_Failure_Report(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead_Skip_TC_Failure_Report& o1, const _ProjectionRead_Skip_TC_Failure_Report& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead_Skip_TC_Failure_Report& o1, const _ProjectionRead_Skip_TC_Failure_Report& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_Skip_TC_Failure_Report& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", ";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_Skip_TC_Failure_Report {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_Skip_TC_Failure_Report& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_Skip_TC_Failure_Report& obj1, const _ProjectionRead__tr_Skip_TC_Failure_Report& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead__tr_Skip_TC_Failure_Report(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead__tr_Skip_TC_Failure_Report& o1, const _ProjectionRead__tr_Skip_TC_Failure_Report& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead__tr_Skip_TC_Failure_Report& o1, const _ProjectionRead__tr_Skip_TC_Failure_Report& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_Skip_TC_Failure_Report& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", "; 
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_Skip_TC_Failure_Report {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_Skip_TC_Failure_Report& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_Skip_TC_Failure_Report& obj1, const _ProjectionWrite_Skip_TC_Failure_Report& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionWrite_Skip_TC_Failure_Report(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionWrite_Skip_TC_Failure_Report& o1, const _ProjectionWrite_Skip_TC_Failure_Report& o2) {
                    return o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionWrite_Skip_TC_Failure_Report& o1, const _ProjectionWrite_Skip_TC_Failure_Report& o2) {
                    return o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_Skip_TC_Failure_Report& e) {
                    strm << "{";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_Drop_TC {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_Drop_TC& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_Drop_TC& obj1, const _ProjectionRead_Drop_TC& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead_Drop_TC(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead_Drop_TC& o1, const _ProjectionRead_Drop_TC& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead_Drop_TC& o1, const _ProjectionRead_Drop_TC& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_Drop_TC& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", ";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_Drop_TC {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_Drop_TC& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_Drop_TC& obj1, const _ProjectionRead__tr_Drop_TC& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead__tr_Drop_TC(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead__tr_Drop_TC& o1, const _ProjectionRead__tr_Drop_TC& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead__tr_Drop_TC& o1, const _ProjectionRead__tr_Drop_TC& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_Drop_TC& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", "; 
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_Drop_TC {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_Drop_TC& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_Drop_TC& obj1, const _ProjectionWrite_Drop_TC& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionWrite_Drop_TC(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionWrite_Drop_TC& o1, const _ProjectionWrite_Drop_TC& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionWrite_Drop_TC& o1, const _ProjectionWrite_Drop_TC& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_Drop_TC& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", ";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_Produce_TM {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_Produce_TM& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_Produce_TM& obj1, const _ProjectionRead_Produce_TM& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionRead_Produce_TM(const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >& TMstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TMstatus = TMstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionRead_Produce_TM& o1, const _ProjectionRead_Produce_TM& o2) {
                    return o1.TMstatus == (o2.TMstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionRead_Produce_TM& o1, const _ProjectionRead_Produce_TM& o2) {
                    return o1.TMstatus != (o2.TMstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_Produce_TM& e) {
                    strm << "{";
                    strm << "TMstatus: " << e.TMstatus;
                    strm << ", ";
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TMstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_Produce_TM {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_Produce_TM& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_Produce_TM& obj1, const _ProjectionRead__tr_Produce_TM& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionRead__tr_Produce_TM(const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionRead__tr_Produce_TM& o1, const _ProjectionRead__tr_Produce_TM& o2) {
                    return o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionRead__tr_Produce_TM& o1, const _ProjectionRead__tr_Produce_TM& o2) {
                    return o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_Produce_TM& e) {
                    strm << "{";
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_Produce_TM {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_Produce_TM& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_Produce_TM& obj1, const _ProjectionWrite_Produce_TM& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionWrite_Produce_TM(const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >& TMstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TMstatus = TMstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionWrite_Produce_TM& o1, const _ProjectionWrite_Produce_TM& o2) {
                    return o1.TMstatus == (o2.TMstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionWrite_Produce_TM& o1, const _ProjectionWrite_Produce_TM& o2) {
                    return o1.TMstatus != (o2.TMstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_Produce_TM& e) {
                    strm << "{";
                    strm << "TMstatus: " << e.TMstatus;
                    strm << ", ";
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TMstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_Pass_TM {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_Pass_TM& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_Pass_TM& obj1, const _ProjectionRead_Pass_TM& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET > TMbuffer;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionRead_Pass_TM(const BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET >& TMbuffer, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >& TMstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TMbuffer = TMbuffer;
                    this->TMstatus = TMstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionRead_Pass_TM& o1, const _ProjectionRead_Pass_TM& o2) {
                    return o1.TMbuffer == (o2.TMbuffer) && o1.TMstatus == (o2.TMstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionRead_Pass_TM& o1, const _ProjectionRead_Pass_TM& o2) {
                    return o1.TMbuffer != (o2.TMbuffer) || o1.TMstatus != (o2.TMstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_Pass_TM& e) {
                    strm << "{";
                    strm << "TMbuffer: " << e.TMbuffer;
                    strm << ", ";
                    strm << "TMstatus: " << e.TMstatus;
                    strm << ", ";
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TMbuffer.hashCode() << 1);
                    result = 31 * result + (TMstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_Pass_TM {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_Pass_TM& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_Pass_TM& obj1, const _ProjectionRead__tr_Pass_TM& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET > TMbuffer;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionRead__tr_Pass_TM(const BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET >& TMbuffer, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >& TMstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TMbuffer = TMbuffer;
                    this->TMstatus = TMstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionRead__tr_Pass_TM& o1, const _ProjectionRead__tr_Pass_TM& o2) {
                    return o1.TMbuffer == (o2.TMbuffer) && o1.TMstatus == (o2.TMstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionRead__tr_Pass_TM& o1, const _ProjectionRead__tr_Pass_TM& o2) {
                    return o1.TMbuffer != (o2.TMbuffer) || o1.TMstatus != (o2.TMstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_Pass_TM& e) {
                    strm << "{";
                    strm << "TMbuffer: " << e.TMbuffer;
                    strm << ", "; 
                    strm << "TMstatus: " << e.TMstatus;
                    strm << ", "; 
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TMbuffer.hashCode() << 1);
                    result = 31 * result + (TMstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_Pass_TM {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_Pass_TM& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_Pass_TM& obj1, const _ProjectionWrite_Pass_TM& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET > TMbuffer;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;

                _ProjectionWrite_Pass_TM(const BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET >& TMbuffer, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >& TMstatus) {
                    this->TMbuffer = TMbuffer;
                    this->TMstatus = TMstatus;
                }

                friend bool operator ==(const _ProjectionWrite_Pass_TM& o1, const _ProjectionWrite_Pass_TM& o2) {
                    return o1.TMbuffer == (o2.TMbuffer) && o1.TMstatus == (o2.TMstatus);
                }

                friend bool operator !=(const _ProjectionWrite_Pass_TM& o1, const _ProjectionWrite_Pass_TM& o2) {
                    return o1.TMbuffer != (o2.TMbuffer) || o1.TMstatus != (o2.TMstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_Pass_TM& e) {
                    strm << "{";
                    strm << "TMbuffer: " << e.TMbuffer;
                    strm << ", ";
                    strm << "TMstatus: " << e.TMstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TMbuffer.hashCode() << 1);
                    result = 31 * result + (TMstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_Cancel_TM {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_Cancel_TM& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_Cancel_TM& obj1, const _ProjectionRead_Cancel_TM& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionRead_Cancel_TM(const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >& TMstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TMstatus = TMstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionRead_Cancel_TM& o1, const _ProjectionRead_Cancel_TM& o2) {
                    return o1.TMstatus == (o2.TMstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionRead_Cancel_TM& o1, const _ProjectionRead_Cancel_TM& o2) {
                    return o1.TMstatus != (o2.TMstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_Cancel_TM& e) {
                    strm << "{";
                    strm << "TMstatus: " << e.TMstatus;
                    strm << ", ";
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TMstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_Cancel_TM {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_Cancel_TM& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_Cancel_TM& obj1, const _ProjectionRead__tr_Cancel_TM& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionRead__tr_Cancel_TM(const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >& TMstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TMstatus = TMstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionRead__tr_Cancel_TM& o1, const _ProjectionRead__tr_Cancel_TM& o2) {
                    return o1.TMstatus == (o2.TMstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionRead__tr_Cancel_TM& o1, const _ProjectionRead__tr_Cancel_TM& o2) {
                    return o1.TMstatus != (o2.TMstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_Cancel_TM& e) {
                    strm << "{";
                    strm << "TMstatus: " << e.TMstatus;
                    strm << ", "; 
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TMstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_Cancel_TM {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_Cancel_TM& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_Cancel_TM& obj1, const _ProjectionWrite_Cancel_TM& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;

                _ProjectionWrite_Cancel_TM(const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >& TMstatus) {
                    this->TMstatus = TMstatus;
                }

                friend bool operator ==(const _ProjectionWrite_Cancel_TM& o1, const _ProjectionWrite_Cancel_TM& o2) {
                    return o1.TMstatus == (o2.TMstatus);
                }

                friend bool operator !=(const _ProjectionWrite_Cancel_TM& o1, const _ProjectionWrite_Cancel_TM& o2) {
                    return o1.TMstatus != (o2.TMstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_Cancel_TM& e) {
                    strm << "{";
                    strm << "TMstatus: " << e.TMstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TMstatus.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_Drop_TM {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_Drop_TM& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_Drop_TM& obj1, const _ProjectionRead_Drop_TM& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionRead_Drop_TM(const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >& TMstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TMstatus = TMstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionRead_Drop_TM& o1, const _ProjectionRead_Drop_TM& o2) {
                    return o1.TMstatus == (o2.TMstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionRead_Drop_TM& o1, const _ProjectionRead_Drop_TM& o2) {
                    return o1.TMstatus != (o2.TMstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_Drop_TM& e) {
                    strm << "{";
                    strm << "TMstatus: " << e.TMstatus;
                    strm << ", ";
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TMstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_Drop_TM {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_Drop_TM& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_Drop_TM& obj1, const _ProjectionRead__tr_Drop_TM& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionRead__tr_Drop_TM(const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >& TMstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TMstatus = TMstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionRead__tr_Drop_TM& o1, const _ProjectionRead__tr_Drop_TM& o2) {
                    return o1.TMstatus == (o2.TMstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionRead__tr_Drop_TM& o1, const _ProjectionRead__tr_Drop_TM& o2) {
                    return o1.TMstatus != (o2.TMstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_Drop_TM& e) {
                    strm << "{";
                    strm << "TMstatus: " << e.TMstatus;
                    strm << ", "; 
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TMstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_Drop_TM {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_Drop_TM& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_Drop_TM& obj1, const _ProjectionWrite_Drop_TM& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionWrite_Drop_TM(const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >& TMstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TMstatus = TMstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionWrite_Drop_TM& o1, const _ProjectionWrite_Drop_TM& o2) {
                    return o1.TMstatus == (o2.TMstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionWrite_Drop_TM& o1, const _ProjectionWrite_Drop_TM& o2) {
                    return o1.TMstatus != (o2.TMstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_Drop_TM& e) {
                    strm << "{";
                    strm << "TMstatus: " << e.TMstatus;
                    strm << ", ";
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TMstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_env_Deliver_TM {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_env_Deliver_TM& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_env_Deliver_TM& obj1, const _ProjectionRead_env_Deliver_TM& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET > TMbuffer;

                _ProjectionRead_env_Deliver_TM(const BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET >& TMbuffer) {
                    this->TMbuffer = TMbuffer;
                }

                friend bool operator ==(const _ProjectionRead_env_Deliver_TM& o1, const _ProjectionRead_env_Deliver_TM& o2) {
                    return o1.TMbuffer == (o2.TMbuffer);
                }

                friend bool operator !=(const _ProjectionRead_env_Deliver_TM& o1, const _ProjectionRead_env_Deliver_TM& o2) {
                    return o1.TMbuffer != (o2.TMbuffer);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_env_Deliver_TM& e) {
                    strm << "{";
                    strm << "TMbuffer: " << e.TMbuffer;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TMbuffer.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_env_Deliver_TM {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_env_Deliver_TM& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_env_Deliver_TM& obj1, const _ProjectionRead__tr_env_Deliver_TM& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET > TMbuffer;

                _ProjectionRead__tr_env_Deliver_TM(const BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET >& TMbuffer) {
                    this->TMbuffer = TMbuffer;
                }

                friend bool operator ==(const _ProjectionRead__tr_env_Deliver_TM& o1, const _ProjectionRead__tr_env_Deliver_TM& o2) {
                    return o1.TMbuffer == (o2.TMbuffer);
                }

                friend bool operator !=(const _ProjectionRead__tr_env_Deliver_TM& o1, const _ProjectionRead__tr_env_Deliver_TM& o2) {
                    return o1.TMbuffer != (o2.TMbuffer);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_env_Deliver_TM& e) {
                    strm << "{";
                    strm << "TMbuffer: " << e.TMbuffer;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TMbuffer.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_env_Deliver_TM {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_env_Deliver_TM& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_env_Deliver_TM& obj1, const _ProjectionWrite_env_Deliver_TM& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET > TMbuffer;

                _ProjectionWrite_env_Deliver_TM(const BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET >& TMbuffer) {
                    this->TMbuffer = TMbuffer;
                }

                friend bool operator ==(const _ProjectionWrite_env_Deliver_TM& o1, const _ProjectionWrite_env_Deliver_TM& o2) {
                    return o1.TMbuffer == (o2.TMbuffer);
                }

                friend bool operator !=(const _ProjectionWrite_env_Deliver_TM& o1, const _ProjectionWrite_env_Deliver_TM& o2) {
                    return o1.TMbuffer != (o2.TMbuffer);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_env_Deliver_TM& e) {
                    strm << "{";
                    strm << "TMbuffer: " << e.TMbuffer;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TMbuffer.hashCode() << 1);
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

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead__check_inv_1(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_1& e) {
                    strm << "{";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCstatus.hashCode() << 1);
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

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead__check_inv_2(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_2& o1, const _ProjectionRead__check_inv_2& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_2& o1, const _ProjectionRead__check_inv_2& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_2& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", ";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
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

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;

                _ProjectionRead__check_inv_3(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool, const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >& TCstatus) {
                    this->TCpool = TCpool;
                    this->TCstatus = TCstatus;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_3& o1, const _ProjectionRead__check_inv_3& o2) {
                    return o1.TCpool == (o2.TCpool) && o1.TCstatus == (o2.TCstatus);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_3& o1, const _ProjectionRead__check_inv_3& o2) {
                    return o1.TCpool != (o2.TCpool) || o1.TCstatus != (o2.TCstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_3& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;
                    strm << ", ";
                    strm << "TCstatus: " << e.TCstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
                    result = 31 * result + (TCstatus.hashCode() << 1);
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

                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;

                _ProjectionRead__check_inv_4(const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >& TMstatus) {
                    this->TMstatus = TMstatus;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_4& o1, const _ProjectionRead__check_inv_4& o2) {
                    return o1.TMstatus == (o2.TMstatus);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_4& o1, const _ProjectionRead__check_inv_4& o2) {
                    return o1.TMstatus != (o2.TMstatus);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_4& e) {
                    strm << "{";
                    strm << "TMstatus: " << e.TMstatus;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TMstatus.hashCode() << 1);
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

                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;
                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionRead__check_inv_5(const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >& TMstatus, const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TMstatus = TMstatus;
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_5& o1, const _ProjectionRead__check_inv_5& o2) {
                    return o1.TMstatus == (o2.TMstatus) && o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_5& o1, const _ProjectionRead__check_inv_5& o2) {
                    return o1.TMstatus != (o2.TMstatus) || o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_5& e) {
                    strm << "{";
                    strm << "TMstatus: " << e.TMstatus;
                    strm << ", ";
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TMstatus.hashCode() << 1);
                    result = 31 * result + (TMpool.hashCode() << 1);
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

                BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET > TCbuffer;

                _ProjectionRead__check_inv_6(const BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET >& TCbuffer) {
                    this->TCbuffer = TCbuffer;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_6& o1, const _ProjectionRead__check_inv_6& o2) {
                    return o1.TCbuffer == (o2.TCbuffer);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_6& o1, const _ProjectionRead__check_inv_6& o2) {
                    return o1.TCbuffer != (o2.TCbuffer);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_6& e) {
                    strm << "{";
                    strm << "TCbuffer: " << e.TCbuffer;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCbuffer.hashCode() << 1);
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

                BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET > TMbuffer;

                _ProjectionRead__check_inv_7(const BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET >& TMbuffer) {
                    this->TMbuffer = TMbuffer;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_7& o1, const _ProjectionRead__check_inv_7& o2) {
                    return o1.TMbuffer == (o2.TMbuffer);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_7& o1, const _ProjectionRead__check_inv_7& o2) {
                    return o1.TMbuffer != (o2.TMbuffer);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_7& e) {
                    strm << "{";
                    strm << "TMbuffer: " << e.TMbuffer;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TMbuffer.hashCode() << 1);
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

                BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;

                _ProjectionRead__check_inv_8(const BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >& TCpool) {
                    this->TCpool = TCpool;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_8& o1, const _ProjectionRead__check_inv_8& o2) {
                    return o1.TCpool == (o2.TCpool);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_8& o1, const _ProjectionRead__check_inv_8& o2) {
                    return o1.TCpool != (o2.TCpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_8& e) {
                    strm << "{";
                    strm << "TCpool: " << e.TCpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TCpool.hashCode() << 1);
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

                BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;

                _ProjectionRead__check_inv_9(const BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >& TMpool) {
                    this->TMpool = TMpool;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_9& o1, const _ProjectionRead__check_inv_9& o2) {
                    return o1.TMpool == (o2.TMpool);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_9& o1, const _ProjectionRead__check_inv_9& o2) {
                    return o1.TMpool != (o2.TMpool);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_9& e) {
                    strm << "{";
                    strm << "TMpool: " << e.TMpool;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TMpool.hashCode() << 1);
                    return result;
                }

        };



    private:

        BSet<TC_SET > VALID_TCS;


        #define _TC_SET (BSet<TC_SET >((TC_SET(TC_SET::TC_SET1)), (TC_SET(TC_SET::TC_SET2))))
        #define _TC_STATUSES (BSet<TC_STATUSES >((TC_STATUSES(TC_STATUSES::TC_Unchecked)), (TC_STATUSES(TC_STATUSES::TC_Accepted)), (TC_STATUSES(TC_STATUSES::TC_Rejected)), (TC_STATUSES(TC_STATUSES::TC_Waiting_for_Execution)), (TC_STATUSES(TC_STATUSES::TC_Successfully_Executed)), (TC_STATUSES(TC_STATUSES::TC_Execution_Failed)), (TC_STATUSES(TC_STATUSES::TC_Removable))))
        #define _TM_STATUSES (BSet<TM_STATUSES >((TM_STATUSES(TM_STATUSES::TM_Effective)), (TM_STATUSES(TM_STATUSES::TM_Removable))))
        #define _PACKET_START_ADDRESSES_IN_TC_BUFFER (BSet<PACKET_START_ADDRESSES_IN_TC_BUFFER >((PACKET_START_ADDRESSES_IN_TC_BUFFER(PACKET_START_ADDRESSES_IN_TC_BUFFER::PACKET_START_ADDRESSES_IN_TC_BUFFER1)), (PACKET_START_ADDRESSES_IN_TC_BUFFER(PACKET_START_ADDRESSES_IN_TC_BUFFER::PACKET_START_ADDRESSES_IN_TC_BUFFER2))))
        #define _PACKET_START_ADDRESSES_IN_TC_POOL (BSet<PACKET_START_ADDRESSES_IN_TC_POOL >((PACKET_START_ADDRESSES_IN_TC_POOL(PACKET_START_ADDRESSES_IN_TC_POOL::PACKET_START_ADDRESSES_IN_TC_POOL1)), (PACKET_START_ADDRESSES_IN_TC_POOL(PACKET_START_ADDRESSES_IN_TC_POOL::PACKET_START_ADDRESSES_IN_TC_POOL2))))
        #define _PACKET_START_ADDRESSES_IN_TM_BUFFER (BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER >((PACKET_START_ADDRESSES_IN_TM_BUFFER(PACKET_START_ADDRESSES_IN_TM_BUFFER::PACKET_START_ADDRESSES_IN_TM_BUFFER1)), (PACKET_START_ADDRESSES_IN_TM_BUFFER(PACKET_START_ADDRESSES_IN_TM_BUFFER::PACKET_START_ADDRESSES_IN_TM_BUFFER2))))
        #define _PACKET_START_ADDRESSES_IN_TM_POOL (BSet<PACKET_START_ADDRESSES_IN_TM_POOL >((PACKET_START_ADDRESSES_IN_TM_POOL(PACKET_START_ADDRESSES_IN_TM_POOL::PACKET_START_ADDRESSES_IN_TM_POOL1)), (PACKET_START_ADDRESSES_IN_TM_POOL(PACKET_START_ADDRESSES_IN_TM_POOL::PACKET_START_ADDRESSES_IN_TM_POOL2))))
        #define _TM_SET (BSet<TM_SET >((TM_SET(TM_SET::TM_SET1)), (TM_SET(TM_SET::TM_SET2))))

        BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > TCstatus;
        BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > TMstatus;
        BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET > TCbuffer;
        BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > TCpool;
        BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET > TMbuffer;
        BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > TMpool;


    public:

        std::string stateAccessedVia;

        obsw_M001_2() {
            VALID_TCS = (BSet<TC_SET >((TC_SET(TC_SET::TC_SET1))));
            if(!((BBoolean(_TC_SET.card().equal((BInteger(2))).booleanValue() && _TC_SET.difference(VALID_TCS).unequal((BSet<TC_SET >())).booleanValue()))).booleanValue()) {
                throw std::runtime_error("Contradiction in PROPERTIES detected!");
            }
            TCbuffer = (BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET >());
            TMbuffer = (BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET >());
            TCpool = (BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >());
            TMpool = (BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >());
            TCstatus = (BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >());
            TMstatus = (BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >());
        }

        obsw_M001_2(const obsw_M001_2& copy) {
            this->VALID_TCS = copy.VALID_TCS;
            this->TCstatus = copy.TCstatus;
            this->TMstatus = copy.TMstatus;
            this->TCbuffer = copy.TCbuffer;
            this->TCpool = copy.TCpool;
            this->TMbuffer = copy.TMbuffer;
            this->TMpool = copy.TMpool;
        }

        void env_Receive_TC(const TC_SET& tc, const PACKET_START_ADDRESSES_IN_TC_BUFFER& tc_pointer) {
            TCbuffer = TCbuffer.override((BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET >((BTuple<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET >(tc_pointer, tc)))));

        }

        void Poll_TC(const PACKET_START_ADDRESSES_IN_TC_POOL& tc_handler, const PACKET_START_ADDRESSES_IN_TC_BUFFER& tc_pointer) {
            BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > _ld_TCpool = TCpool;
            BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET > _ld_TCbuffer = TCbuffer;
            BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > _ld_TCstatus = TCstatus;
            TCpool = _ld_TCpool.override((BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >((BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET >(tc_handler, _ld_TCbuffer.functionCall(tc_pointer))))));
            TCbuffer = _ld_TCbuffer.domainSubstraction((BSet<PACKET_START_ADDRESSES_IN_TC_BUFFER >(tc_pointer)));
            TCstatus = _ld_TCstatus.override((BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >((BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >(tc_handler, (TC_STATUSES(TC_STATUSES::TC_Unchecked)))))));

        }

        void Accept_TC(const PACKET_START_ADDRESSES_IN_TC_POOL& tc_handler) {
            TCstatus = TCstatus.override((BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >((BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >(tc_handler, (TC_STATUSES(TC_STATUSES::TC_Accepted)))))));

        }

        void Reject_TC(const PACKET_START_ADDRESSES_IN_TC_POOL& tc_handler) {
            TCstatus = TCstatus.override((BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >((BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >(tc_handler, (TC_STATUSES(TC_STATUSES::TC_Rejected)))))));

        }

        void Report_TC_Acceptance(const PACKET_START_ADDRESSES_IN_TC_POOL& tc_handler, const TM_SET& tm, const PACKET_START_ADDRESSES_IN_TM_POOL& tm_handler) {
            BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > _ld_TMpool = TMpool;
            BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > _ld_TMstatus = TMstatus;
            BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > _ld_TCstatus = TCstatus;
            TMpool = _ld_TMpool.override((BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >((BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >(tm_handler, tm)))));
            TCstatus = _ld_TCstatus.override((BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >((BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >(tc_handler, (TC_STATUSES(TC_STATUSES::TC_Waiting_for_Execution)))))));
            TMstatus = _ld_TMstatus.override((BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >((BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >(tm_handler, (TM_STATUSES(TM_STATUSES::TM_Effective)))))));

        }

        void Skip_TC_Acceptance_Report(const PACKET_START_ADDRESSES_IN_TC_POOL& tc_handler) {
            TCstatus = TCstatus.override((BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >((BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >(tc_handler, (TC_STATUSES(TC_STATUSES::TC_Waiting_for_Execution)))))));

        }

        void Report_TC_Rejection(const PACKET_START_ADDRESSES_IN_TC_POOL& tc_handler, const TM_SET& tm, const PACKET_START_ADDRESSES_IN_TM_POOL& tm_handler) {
            BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > _ld_TMpool = TMpool;
            BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > _ld_TMstatus = TMstatus;
            BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > _ld_TCstatus = TCstatus;
            TMpool = _ld_TMpool.override((BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >((BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >(tm_handler, tm)))));
            TCstatus = _ld_TCstatus.override((BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >((BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >(tc_handler, (TC_STATUSES(TC_STATUSES::TC_Removable)))))));
            TMstatus = _ld_TMstatus.override((BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >((BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >(tm_handler, (TM_STATUSES(TM_STATUSES::TM_Effective)))))));

        }

        void Skip_TC_Rejection_Report(const PACKET_START_ADDRESSES_IN_TC_POOL& tc_handler) {
            TCstatus = TCstatus.override((BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >((BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >(tc_handler, (TC_STATUSES(TC_STATUSES::TC_Removable)))))));

        }

        void Execute_TC_Successfully(const PACKET_START_ADDRESSES_IN_TC_POOL& tc_handler) {
            TCstatus = TCstatus.override((BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >((BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >(tc_handler, (TC_STATUSES(TC_STATUSES::TC_Successfully_Executed)))))));

        }

        void Reset_TM_Buffer(const PACKET_START_ADDRESSES_IN_TC_POOL& tc_handler) {
            BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > _ld_TCstatus = TCstatus;
            TMbuffer = (BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET >());
            TCstatus = _ld_TCstatus.override((BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >((BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >(tc_handler, (TC_STATUSES(TC_STATUSES::TC_Successfully_Executed)))))));

        }

        void Fail_TC_Execution(const PACKET_START_ADDRESSES_IN_TC_POOL& tc_handler) {
            TCstatus = TCstatus.override((BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >((BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >(tc_handler, (TC_STATUSES(TC_STATUSES::TC_Execution_Failed)))))));

        }

        void Report_TC_Execution_Success(const PACKET_START_ADDRESSES_IN_TC_POOL& tc_handler, const TM_SET& tm, const PACKET_START_ADDRESSES_IN_TM_POOL& tm_handler) {
            BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > _ld_TMpool = TMpool;
            BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > _ld_TMstatus = TMstatus;
            BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > _ld_TCstatus = TCstatus;
            TMpool = _ld_TMpool.override((BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >((BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >(tm_handler, tm)))));
            TCstatus = _ld_TCstatus.override((BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >((BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >(tc_handler, (TC_STATUSES(TC_STATUSES::TC_Removable)))))));
            TMstatus = _ld_TMstatus.override((BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >((BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >(tm_handler, (TM_STATUSES(TM_STATUSES::TM_Effective)))))));

        }

        void Skip_TC_Success_Report(const PACKET_START_ADDRESSES_IN_TC_POOL& tc_handler) {
            TCstatus = TCstatus.override((BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >((BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >(tc_handler, (TC_STATUSES(TC_STATUSES::TC_Removable)))))));

        }

        void Report_TC_Execution_Failure(const PACKET_START_ADDRESSES_IN_TC_POOL& tc_handler, const TM_SET& tm, const PACKET_START_ADDRESSES_IN_TM_POOL& tm_handler) {
            BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > _ld_TMpool = TMpool;
            BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > _ld_TMstatus = TMstatus;
            BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > _ld_TCstatus = TCstatus;
            TMpool = _ld_TMpool.override((BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >((BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >(tm_handler, tm)))));
            TCstatus = _ld_TCstatus.override((BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >((BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >(tc_handler, (TC_STATUSES(TC_STATUSES::TC_Removable)))))));
            TMstatus = _ld_TMstatus.override((BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >((BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >(tm_handler, (TM_STATUSES(TM_STATUSES::TM_Effective)))))));

        }

        void Skip_TC_Failure_Report(const PACKET_START_ADDRESSES_IN_TC_POOL& tc_handler) {
            TCstatus = TCstatus.override((BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >((BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES >(tc_handler, (TC_STATUSES(TC_STATUSES::TC_Removable)))))));

        }

        void Drop_TC(const PACKET_START_ADDRESSES_IN_TC_POOL& tc_handler) {
            BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > _ld_TCpool = TCpool;
            BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > _ld_TCstatus = TCstatus;
            TCpool = _ld_TCpool.domainSubstraction((BSet<PACKET_START_ADDRESSES_IN_TC_POOL >(tc_handler)));
            TCstatus = _ld_TCstatus.domainSubstraction((BSet<PACKET_START_ADDRESSES_IN_TC_POOL >(tc_handler)));

        }

        void Produce_TM(const TM_SET& tm, const PACKET_START_ADDRESSES_IN_TM_POOL& tm_handler) {
            BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > _ld_TMpool = TMpool;
            BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > _ld_TMstatus = TMstatus;
            TMpool = _ld_TMpool.override((BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >((BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET >(tm_handler, tm)))));
            TMstatus = _ld_TMstatus.override((BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >((BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >(tm_handler, (TM_STATUSES(TM_STATUSES::TM_Effective)))))));

        }

        void Pass_TM(const PACKET_START_ADDRESSES_IN_TM_POOL& tm_handler, const PACKET_START_ADDRESSES_IN_TM_BUFFER& tm_pointer) {
            BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > _ld_TMstatus = TMstatus;
            BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET > _ld_TMbuffer = TMbuffer;
            TMbuffer = _ld_TMbuffer.override((BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET >((BTuple<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET >(tm_pointer, TMpool.functionCall(tm_handler))))));
            TMstatus = _ld_TMstatus.override((BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >((BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >(tm_handler, (TM_STATUSES(TM_STATUSES::TM_Removable)))))));

        }

        void Cancel_TM(const PACKET_START_ADDRESSES_IN_TM_POOL& tm_handler) {
            TMstatus = TMstatus.override((BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >((BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES >(tm_handler, (TM_STATUSES(TM_STATUSES::TM_Removable)))))));

        }

        void Drop_TM(const PACKET_START_ADDRESSES_IN_TM_POOL& tm_handler) {
            BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > _ld_TMpool = TMpool;
            BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > _ld_TMstatus = TMstatus;
            TMpool = _ld_TMpool.domainSubstraction((BSet<PACKET_START_ADDRESSES_IN_TM_POOL >(tm_handler)));
            TMstatus = _ld_TMstatus.domainSubstraction((BSet<PACKET_START_ADDRESSES_IN_TM_POOL >(tm_handler)));

        }

        void env_Deliver_TM(const PACKET_START_ADDRESSES_IN_TM_BUFFER& tm_pointer) {
            TMbuffer = TMbuffer.domainSubstraction((BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER >(tm_pointer)));

        }

        BSet<TC_SET > _get_VALID_TCS() const {
            return VALID_TCS;
        }

        BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES > _get_TCstatus() const {
            return TCstatus;
        }

        BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES > _get_TMstatus() const {
            return TMstatus;
        }

        BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET > _get_TCbuffer() const {
            return TCbuffer;
        }

        BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET > _get_TCpool() const {
            return TCpool;
        }

        BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET > _get_TMbuffer() const {
            return TMbuffer;
        }

        BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET > _get_TMpool() const {
            return TMpool;
        }

        BSet<TC_SET > _get__TC_SET() const {
            return _TC_SET;
        }

        BSet<TC_STATUSES > _get__TC_STATUSES() const {
            return _TC_STATUSES;
        }

        BSet<TM_STATUSES > _get__TM_STATUSES() const {
            return _TM_STATUSES;
        }


        BSet<BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER >> _tr_env_Receive_TC() const {
            BSet<BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER >> _ic_set_0 = BSet<BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER >>();
            for(const PACKET_START_ADDRESSES_IN_TC_BUFFER& _ic_tc_pointer_1 : _PACKET_START_ADDRESSES_IN_TC_BUFFER) {
                if(((TCbuffer.isNotInDomain(_ic_tc_pointer_1))).booleanValue()) {
                    for(const TC_SET& _ic_tc_1 : _TC_SET) {
                        if((_TC_SET.elementOf(_ic_tc_1)).booleanValue()) {
                            _ic_set_0 = _ic_set_0._union(BSet<BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER >>((BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER >(_ic_tc_1, _ic_tc_pointer_1))));
                        }

                    }

                }
            }

            return _ic_set_0;
        }

        BSet<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER >> _tr_Poll_TC() const {
            BSet<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER >> _ic_set_1 = BSet<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER >>();
            for(const PACKET_START_ADDRESSES_IN_TC_BUFFER& _ic_tc_pointer_1 : TCbuffer.domain()) {
                for(const PACKET_START_ADDRESSES_IN_TC_POOL& _ic_tc_handler_1 : _PACKET_START_ADDRESSES_IN_TC_POOL) {
                    if(((TCpool.isNotInDomain(_ic_tc_handler_1))).booleanValue()) {
                        _ic_set_1 = _ic_set_1._union(BSet<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER >>((BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER >(_ic_tc_handler_1, _ic_tc_pointer_1))));
                    }

                }

            }

            return _ic_set_1;
        }

        BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _tr_Accept_TC() const {
            BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _ic_set_2 = BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
            for(const PACKET_START_ADDRESSES_IN_TC_POOL& _ic_tc_handler_1 : TCpool.domain()) {
                if(((BBoolean((BBoolean(VALID_TCS.elementOf(TCpool.functionCall(_ic_tc_handler_1)).booleanValue() && (TCstatus.isInDomain(_ic_tc_handler_1)).booleanValue())).booleanValue() && TCstatus.functionCall(_ic_tc_handler_1).equal((TC_STATUSES(TC_STATUSES::TC_Unchecked))).booleanValue()))).booleanValue()) {
                    _ic_set_2 = _ic_set_2._union(BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
                }

            }

            return _ic_set_2;
        }

        BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _tr_Reject_TC() const {
            BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _ic_set_3 = BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
            for(const PACKET_START_ADDRESSES_IN_TC_POOL& _ic_tc_handler_1 : TCpool.domain()) {
                if(((BBoolean((TCstatus.isInDomain(_ic_tc_handler_1)).booleanValue() && TCstatus.functionCall(_ic_tc_handler_1).equal((TC_STATUSES(TC_STATUSES::TC_Unchecked))).booleanValue()))).booleanValue()) {
                    _ic_set_3 = _ic_set_3._union(BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
                }

            }

            return _ic_set_3;
        }

        BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >, PACKET_START_ADDRESSES_IN_TM_POOL >> _tr_Report_TC_Acceptance() const {
            BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >, PACKET_START_ADDRESSES_IN_TM_POOL >> _ic_set_4 = BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >, PACKET_START_ADDRESSES_IN_TM_POOL >>();
            for(const PACKET_START_ADDRESSES_IN_TC_POOL& _ic_tc_handler_1 : TCpool.domain()) {
                if(((TCstatus.isInDomain(_ic_tc_handler_1))).booleanValue()) {
                    if((TCstatus.functionCall(_ic_tc_handler_1).equal((TC_STATUSES(TC_STATUSES::TC_Accepted)))).booleanValue()) {
                        for(const TM_SET& _ic_tm_1 : _TM_SET) {
                            for(const PACKET_START_ADDRESSES_IN_TM_POOL& _ic_tm_handler_1 : _PACKET_START_ADDRESSES_IN_TM_POOL) {
                                if(((TMpool.isNotInDomain(_ic_tm_handler_1))).booleanValue()) {
                                    _ic_set_4 = _ic_set_4._union(BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >, PACKET_START_ADDRESSES_IN_TM_POOL >>((BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >, PACKET_START_ADDRESSES_IN_TM_POOL >((BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >(_ic_tc_handler_1, _ic_tm_1)), _ic_tm_handler_1))));
                                }

                            }

                        }

                    }
                }
            }

            return _ic_set_4;
        }

        BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _tr_Skip_TC_Acceptance_Report() const {
            BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _ic_set_5 = BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
            for(const PACKET_START_ADDRESSES_IN_TC_POOL& _ic_tc_handler_1 : TCpool.domain()) {
                if(((BBoolean((TCstatus.isInDomain(_ic_tc_handler_1)).booleanValue() && TCstatus.functionCall(_ic_tc_handler_1).equal((TC_STATUSES(TC_STATUSES::TC_Accepted))).booleanValue()))).booleanValue()) {
                    _ic_set_5 = _ic_set_5._union(BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
                }

            }

            return _ic_set_5;
        }

        BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >, PACKET_START_ADDRESSES_IN_TM_POOL >> _tr_Report_TC_Rejection() const {
            BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >, PACKET_START_ADDRESSES_IN_TM_POOL >> _ic_set_6 = BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >, PACKET_START_ADDRESSES_IN_TM_POOL >>();
            for(const PACKET_START_ADDRESSES_IN_TC_POOL& _ic_tc_handler_1 : TCpool.domain()) {
                if(((TCstatus.isInDomain(_ic_tc_handler_1))).booleanValue()) {
                    if((TCstatus.functionCall(_ic_tc_handler_1).equal((TC_STATUSES(TC_STATUSES::TC_Rejected)))).booleanValue()) {
                        for(const TM_SET& _ic_tm_1 : _TM_SET) {
                            for(const PACKET_START_ADDRESSES_IN_TM_POOL& _ic_tm_handler_1 : _PACKET_START_ADDRESSES_IN_TM_POOL) {
                                if(((TMpool.isNotInDomain(_ic_tm_handler_1))).booleanValue()) {
                                    _ic_set_6 = _ic_set_6._union(BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >, PACKET_START_ADDRESSES_IN_TM_POOL >>((BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >, PACKET_START_ADDRESSES_IN_TM_POOL >((BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >(_ic_tc_handler_1, _ic_tm_1)), _ic_tm_handler_1))));
                                }

                            }

                        }

                    }
                }
            }

            return _ic_set_6;
        }

        BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _tr_Skip_TC_Rejection_Report() const {
            BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _ic_set_7 = BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
            for(const PACKET_START_ADDRESSES_IN_TC_POOL& _ic_tc_handler_1 : TCpool.domain()) {
                if(((BBoolean((TCstatus.isInDomain(_ic_tc_handler_1)).booleanValue() && TCstatus.functionCall(_ic_tc_handler_1).equal((TC_STATUSES(TC_STATUSES::TC_Rejected))).booleanValue()))).booleanValue()) {
                    _ic_set_7 = _ic_set_7._union(BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
                }

            }

            return _ic_set_7;
        }

        BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _tr_Execute_TC_Successfully() const {
            BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _ic_set_8 = BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
            for(const PACKET_START_ADDRESSES_IN_TC_POOL& _ic_tc_handler_1 : TCpool.domain()) {
                if(((BBoolean((TCstatus.isInDomain(_ic_tc_handler_1)).booleanValue() && TCstatus.functionCall(_ic_tc_handler_1).equal((TC_STATUSES(TC_STATUSES::TC_Waiting_for_Execution))).booleanValue()))).booleanValue()) {
                    _ic_set_8 = _ic_set_8._union(BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
                }

            }

            return _ic_set_8;
        }

        BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _tr_Reset_TM_Buffer() const {
            BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _ic_set_9 = BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
            for(const PACKET_START_ADDRESSES_IN_TC_POOL& _ic_tc_handler_1 : TCpool.domain()) {
                if(((BBoolean((TCstatus.isInDomain(_ic_tc_handler_1)).booleanValue() && TCstatus.functionCall(_ic_tc_handler_1).equal((TC_STATUSES(TC_STATUSES::TC_Waiting_for_Execution))).booleanValue()))).booleanValue()) {
                    _ic_set_9 = _ic_set_9._union(BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
                }

            }

            return _ic_set_9;
        }

        BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _tr_Fail_TC_Execution() const {
            BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _ic_set_10 = BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
            for(const PACKET_START_ADDRESSES_IN_TC_POOL& _ic_tc_handler_1 : TCpool.domain()) {
                if(((BBoolean((TCstatus.isInDomain(_ic_tc_handler_1)).booleanValue() && TCstatus.functionCall(_ic_tc_handler_1).equal((TC_STATUSES(TC_STATUSES::TC_Waiting_for_Execution))).booleanValue()))).booleanValue()) {
                    _ic_set_10 = _ic_set_10._union(BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
                }

            }

            return _ic_set_10;
        }

        BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >, PACKET_START_ADDRESSES_IN_TM_POOL >> _tr_Report_TC_Execution_Success() const {
            BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >, PACKET_START_ADDRESSES_IN_TM_POOL >> _ic_set_11 = BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >, PACKET_START_ADDRESSES_IN_TM_POOL >>();
            for(const PACKET_START_ADDRESSES_IN_TC_POOL& _ic_tc_handler_1 : TCpool.domain()) {
                if(((TCstatus.isInDomain(_ic_tc_handler_1))).booleanValue()) {
                    if((TCstatus.functionCall(_ic_tc_handler_1).equal((TC_STATUSES(TC_STATUSES::TC_Successfully_Executed)))).booleanValue()) {
                        for(const TM_SET& _ic_tm_1 : _TM_SET) {
                            for(const PACKET_START_ADDRESSES_IN_TM_POOL& _ic_tm_handler_1 : _PACKET_START_ADDRESSES_IN_TM_POOL) {
                                if(((TMpool.isNotInDomain(_ic_tm_handler_1))).booleanValue()) {
                                    _ic_set_11 = _ic_set_11._union(BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >, PACKET_START_ADDRESSES_IN_TM_POOL >>((BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >, PACKET_START_ADDRESSES_IN_TM_POOL >((BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >(_ic_tc_handler_1, _ic_tm_1)), _ic_tm_handler_1))));
                                }

                            }

                        }

                    }
                }
            }

            return _ic_set_11;
        }

        BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _tr_Skip_TC_Success_Report() const {
            BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _ic_set_12 = BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
            for(const PACKET_START_ADDRESSES_IN_TC_POOL& _ic_tc_handler_1 : TCpool.domain()) {
                if(((BBoolean((TCstatus.isInDomain(_ic_tc_handler_1)).booleanValue() && TCstatus.functionCall(_ic_tc_handler_1).equal((TC_STATUSES(TC_STATUSES::TC_Successfully_Executed))).booleanValue()))).booleanValue()) {
                    _ic_set_12 = _ic_set_12._union(BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
                }

            }

            return _ic_set_12;
        }

        BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >, PACKET_START_ADDRESSES_IN_TM_POOL >> _tr_Report_TC_Execution_Failure() const {
            BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >, PACKET_START_ADDRESSES_IN_TM_POOL >> _ic_set_13 = BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >, PACKET_START_ADDRESSES_IN_TM_POOL >>();
            for(const PACKET_START_ADDRESSES_IN_TC_POOL& _ic_tc_handler_1 : TCpool.domain()) {
                if(((TCstatus.isInDomain(_ic_tc_handler_1))).booleanValue()) {
                    if((TCstatus.functionCall(_ic_tc_handler_1).equal((TC_STATUSES(TC_STATUSES::TC_Execution_Failed)))).booleanValue()) {
                        for(const TM_SET& _ic_tm_1 : _TM_SET) {
                            for(const PACKET_START_ADDRESSES_IN_TM_POOL& _ic_tm_handler_1 : _PACKET_START_ADDRESSES_IN_TM_POOL) {
                                if(((TMpool.isNotInDomain(_ic_tm_handler_1))).booleanValue()) {
                                    _ic_set_13 = _ic_set_13._union(BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >, PACKET_START_ADDRESSES_IN_TM_POOL >>((BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >, PACKET_START_ADDRESSES_IN_TM_POOL >((BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET >(_ic_tc_handler_1, _ic_tm_1)), _ic_tm_handler_1))));
                                }

                            }

                        }

                    }
                }
            }

            return _ic_set_13;
        }

        BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _tr_Skip_TC_Failure_Report() const {
            BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _ic_set_14 = BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
            for(const PACKET_START_ADDRESSES_IN_TC_POOL& _ic_tc_handler_1 : TCpool.domain()) {
                if(((BBoolean((TCstatus.isInDomain(_ic_tc_handler_1)).booleanValue() && TCstatus.functionCall(_ic_tc_handler_1).equal((TC_STATUSES(TC_STATUSES::TC_Execution_Failed))).booleanValue()))).booleanValue()) {
                    _ic_set_14 = _ic_set_14._union(BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
                }

            }

            return _ic_set_14;
        }

        BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _tr_Drop_TC() const {
            BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _ic_set_15 = BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
            for(const PACKET_START_ADDRESSES_IN_TC_POOL& _ic_tc_handler_1 : TCpool.domain()) {
                if(((BBoolean((TCstatus.isInDomain(_ic_tc_handler_1)).booleanValue() && TCstatus.functionCall(_ic_tc_handler_1).equal((TC_STATUSES(TC_STATUSES::TC_Removable))).booleanValue()))).booleanValue()) {
                    _ic_set_15 = _ic_set_15._union(BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
                }

            }

            return _ic_set_15;
        }

        BSet<BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL >> _tr_Produce_TM() const {
            BSet<BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL >> _ic_set_16 = BSet<BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL >>();
            for(const TM_SET& _ic_tm_1 : _TM_SET) {
                for(const PACKET_START_ADDRESSES_IN_TM_POOL& _ic_tm_handler_1 : _PACKET_START_ADDRESSES_IN_TM_POOL) {
                    if(((TMpool.isNotInDomain(_ic_tm_handler_1))).booleanValue()) {
                        _ic_set_16 = _ic_set_16._union(BSet<BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL >>((BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL >(_ic_tm_1, _ic_tm_handler_1))));
                    }

                }

            }

            return _ic_set_16;
        }

        BSet<BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER >> _tr_Pass_TM() const {
            BSet<BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER >> _ic_set_17 = BSet<BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER >>();
            for(const PACKET_START_ADDRESSES_IN_TM_POOL& _ic_tm_handler_1 : TMpool.domain()) {
                if(((TMstatus.isInDomain(_ic_tm_handler_1))).booleanValue()) {
                    if((TMstatus.functionCall(_ic_tm_handler_1).equal((TM_STATUSES(TM_STATUSES::TM_Effective)))).booleanValue()) {
                        for(const PACKET_START_ADDRESSES_IN_TM_BUFFER& _ic_tm_pointer_1 : _PACKET_START_ADDRESSES_IN_TM_BUFFER) {
                            if(((TMbuffer.isNotInDomain(_ic_tm_pointer_1))).booleanValue()) {
                                _ic_set_17 = _ic_set_17._union(BSet<BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER >>((BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER >(_ic_tm_handler_1, _ic_tm_pointer_1))));
                            }

                        }

                    }
                }
            }

            return _ic_set_17;
        }

        BSet<PACKET_START_ADDRESSES_IN_TM_POOL> _tr_Cancel_TM() const {
            BSet<PACKET_START_ADDRESSES_IN_TM_POOL> _ic_set_18 = BSet<PACKET_START_ADDRESSES_IN_TM_POOL>();
            for(const PACKET_START_ADDRESSES_IN_TM_POOL& _ic_tm_handler_1 : TMpool.domain()) {
                if(((BBoolean((TMstatus.isInDomain(_ic_tm_handler_1)).booleanValue() && TMstatus.functionCall(_ic_tm_handler_1).equal((TM_STATUSES(TM_STATUSES::TM_Effective))).booleanValue()))).booleanValue()) {
                    _ic_set_18 = _ic_set_18._union(BSet<PACKET_START_ADDRESSES_IN_TM_POOL>(_ic_tm_handler_1));
                }

            }

            return _ic_set_18;
        }

        BSet<PACKET_START_ADDRESSES_IN_TM_POOL> _tr_Drop_TM() const {
            BSet<PACKET_START_ADDRESSES_IN_TM_POOL> _ic_set_19 = BSet<PACKET_START_ADDRESSES_IN_TM_POOL>();
            for(const PACKET_START_ADDRESSES_IN_TM_POOL& _ic_tm_handler_1 : TMpool.domain()) {
                if(((BBoolean((TMstatus.isInDomain(_ic_tm_handler_1)).booleanValue() && TMstatus.functionCall(_ic_tm_handler_1).equal((TM_STATUSES(TM_STATUSES::TM_Removable))).booleanValue()))).booleanValue()) {
                    _ic_set_19 = _ic_set_19._union(BSet<PACKET_START_ADDRESSES_IN_TM_POOL>(_ic_tm_handler_1));
                }

            }

            return _ic_set_19;
        }

        BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER> _tr_env_Deliver_TM() const {
            BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER> _ic_set_20 = BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER>();
            for(const PACKET_START_ADDRESSES_IN_TM_BUFFER& _ic_tm_pointer_1 : TMbuffer.domain()) {
                _ic_set_20 = _ic_set_20._union(BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER>(_ic_tm_pointer_1));

            }

            return _ic_set_20;
        }

        _ProjectionRead_Report_TC_Rejection _projected_state_for_Report_TC_Rejection() const {
            return _ProjectionRead_Report_TC_Rejection(TCpool,TCstatus,TMstatus,TMpool);
        }

        _ProjectionRead_Report_TC_Execution_Success _projected_state_for_Report_TC_Execution_Success() const {
            return _ProjectionRead_Report_TC_Execution_Success(TCpool,TCstatus,TMstatus,TMpool);
        }

        _ProjectionRead_Cancel_TM _projected_state_for_Cancel_TM() const {
            return _ProjectionRead_Cancel_TM(TMstatus,TMpool);
        }

        _ProjectionRead_env_Receive_TC _projected_state_for_env_Receive_TC() const {
            return _ProjectionRead_env_Receive_TC(TCbuffer);
        }

        _ProjectionRead_Report_TC_Execution_Failure _projected_state_for_Report_TC_Execution_Failure() const {
            return _ProjectionRead_Report_TC_Execution_Failure(TCpool,TCstatus,TMstatus,TMpool);
        }

        _ProjectionRead_Pass_TM _projected_state_for_Pass_TM() const {
            return _ProjectionRead_Pass_TM(TMbuffer,TMstatus,TMpool);
        }

        _ProjectionRead_Drop_TM _projected_state_for_Drop_TM() const {
            return _ProjectionRead_Drop_TM(TMstatus,TMpool);
        }

        _ProjectionRead_Reset_TM_Buffer _projected_state_for_Reset_TM_Buffer() const {
            return _ProjectionRead_Reset_TM_Buffer(TCpool,TCstatus);
        }

        _ProjectionRead_Skip_TC_Failure_Report _projected_state_for_Skip_TC_Failure_Report() const {
            return _ProjectionRead_Skip_TC_Failure_Report(TCpool,TCstatus);
        }

        _ProjectionRead_Poll_TC _projected_state_for_Poll_TC() const {
            return _ProjectionRead_Poll_TC(TCbuffer,TCpool,TCstatus);
        }

        _ProjectionRead_Skip_TC_Acceptance_Report _projected_state_for_Skip_TC_Acceptance_Report() const {
            return _ProjectionRead_Skip_TC_Acceptance_Report(TCpool,TCstatus);
        }

        _ProjectionRead_Accept_TC _projected_state_for_Accept_TC() const {
            return _ProjectionRead_Accept_TC(TCpool,TCstatus);
        }

        _ProjectionRead_Fail_TC_Execution _projected_state_for_Fail_TC_Execution() const {
            return _ProjectionRead_Fail_TC_Execution(TCpool,TCstatus);
        }

        _ProjectionRead_Report_TC_Acceptance _projected_state_for_Report_TC_Acceptance() const {
            return _ProjectionRead_Report_TC_Acceptance(TCpool,TCstatus,TMstatus,TMpool);
        }

        _ProjectionRead_Reject_TC _projected_state_for_Reject_TC() const {
            return _ProjectionRead_Reject_TC(TCpool,TCstatus);
        }

        _ProjectionRead_Skip_TC_Rejection_Report _projected_state_for_Skip_TC_Rejection_Report() const {
            return _ProjectionRead_Skip_TC_Rejection_Report(TCpool,TCstatus);
        }

        _ProjectionRead_env_Deliver_TM _projected_state_for_env_Deliver_TM() const {
            return _ProjectionRead_env_Deliver_TM(TMbuffer);
        }

        _ProjectionRead_Execute_TC_Successfully _projected_state_for_Execute_TC_Successfully() const {
            return _ProjectionRead_Execute_TC_Successfully(TCpool,TCstatus);
        }

        _ProjectionRead_Skip_TC_Success_Report _projected_state_for_Skip_TC_Success_Report() const {
            return _ProjectionRead_Skip_TC_Success_Report(TCpool,TCstatus);
        }

        _ProjectionRead_Drop_TC _projected_state_for_Drop_TC() const {
            return _ProjectionRead_Drop_TC(TCpool,TCstatus);
        }

        _ProjectionRead_Produce_TM _projected_state_for_Produce_TM() const {
            return _ProjectionRead_Produce_TM(TMstatus,TMpool);
        }

        _ProjectionRead__tr_Poll_TC _projected_state_for__tr_Poll_TC() const {
            return _ProjectionRead__tr_Poll_TC(TCbuffer,TCpool);
        }

        _ProjectionRead__tr_Reset_TM_Buffer _projected_state_for__tr_Reset_TM_Buffer() const {
            return _ProjectionRead__tr_Reset_TM_Buffer(TCpool,TCstatus);
        }

        _ProjectionRead__tr_Drop_TM _projected_state_for__tr_Drop_TM() const {
            return _ProjectionRead__tr_Drop_TM(TMstatus,TMpool);
        }

        _ProjectionRead__tr_env_Receive_TC _projected_state_for__tr_env_Receive_TC() const {
            return _ProjectionRead__tr_env_Receive_TC(TCbuffer);
        }

        _ProjectionRead__tr_Accept_TC _projected_state_for__tr_Accept_TC() const {
            return _ProjectionRead__tr_Accept_TC(TCpool,TCstatus);
        }

        _ProjectionRead__tr_Skip_TC_Failure_Report _projected_state_for__tr_Skip_TC_Failure_Report() const {
            return _ProjectionRead__tr_Skip_TC_Failure_Report(TCpool,TCstatus);
        }

        _ProjectionRead__tr_Cancel_TM _projected_state_for__tr_Cancel_TM() const {
            return _ProjectionRead__tr_Cancel_TM(TMstatus,TMpool);
        }

        _ProjectionRead__tr_Report_TC_Execution_Success _projected_state_for__tr_Report_TC_Execution_Success() const {
            return _ProjectionRead__tr_Report_TC_Execution_Success(TCpool,TCstatus,TMpool);
        }

        _ProjectionRead__tr_Execute_TC_Successfully _projected_state_for__tr_Execute_TC_Successfully() const {
            return _ProjectionRead__tr_Execute_TC_Successfully(TCpool,TCstatus);
        }

        _ProjectionRead__tr_Drop_TC _projected_state_for__tr_Drop_TC() const {
            return _ProjectionRead__tr_Drop_TC(TCpool,TCstatus);
        }

        _ProjectionRead__tr_Skip_TC_Acceptance_Report _projected_state_for__tr_Skip_TC_Acceptance_Report() const {
            return _ProjectionRead__tr_Skip_TC_Acceptance_Report(TCpool,TCstatus);
        }

        _ProjectionRead__tr_Report_TC_Rejection _projected_state_for__tr_Report_TC_Rejection() const {
            return _ProjectionRead__tr_Report_TC_Rejection(TCpool,TCstatus,TMpool);
        }

        _ProjectionRead__tr_Produce_TM _projected_state_for__tr_Produce_TM() const {
            return _ProjectionRead__tr_Produce_TM(TMpool);
        }

        _ProjectionRead__tr_Pass_TM _projected_state_for__tr_Pass_TM() const {
            return _ProjectionRead__tr_Pass_TM(TMbuffer,TMstatus,TMpool);
        }

        _ProjectionRead__tr_Fail_TC_Execution _projected_state_for__tr_Fail_TC_Execution() const {
            return _ProjectionRead__tr_Fail_TC_Execution(TCpool,TCstatus);
        }

        _ProjectionRead__tr_Report_TC_Acceptance _projected_state_for__tr_Report_TC_Acceptance() const {
            return _ProjectionRead__tr_Report_TC_Acceptance(TCpool,TCstatus,TMpool);
        }

        _ProjectionRead__tr_Reject_TC _projected_state_for__tr_Reject_TC() const {
            return _ProjectionRead__tr_Reject_TC(TCpool,TCstatus);
        }

        _ProjectionRead__tr_Skip_TC_Success_Report _projected_state_for__tr_Skip_TC_Success_Report() const {
            return _ProjectionRead__tr_Skip_TC_Success_Report(TCpool,TCstatus);
        }

        _ProjectionRead__tr_Report_TC_Execution_Failure _projected_state_for__tr_Report_TC_Execution_Failure() const {
            return _ProjectionRead__tr_Report_TC_Execution_Failure(TCpool,TCstatus,TMpool);
        }

        _ProjectionRead__tr_env_Deliver_TM _projected_state_for__tr_env_Deliver_TM() const {
            return _ProjectionRead__tr_env_Deliver_TM(TMbuffer);
        }

        _ProjectionRead__tr_Skip_TC_Rejection_Report _projected_state_for__tr_Skip_TC_Rejection_Report() const {
            return _ProjectionRead__tr_Skip_TC_Rejection_Report(TCpool,TCstatus);
        }

        _ProjectionRead__check_inv_2 _projected_state_for__check_inv_2() const {
            return _ProjectionRead__check_inv_2(TCpool,TCstatus);
        }

        _ProjectionRead__check_inv_3 _projected_state_for__check_inv_3() const {
            return _ProjectionRead__check_inv_3(TCpool,TCstatus);
        }

        _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() const {
            return _ProjectionRead__check_inv_1(TCstatus);
        }

        _ProjectionRead__check_inv_6 _projected_state_for__check_inv_6() const {
            return _ProjectionRead__check_inv_6(TCbuffer);
        }

        _ProjectionRead__check_inv_7 _projected_state_for__check_inv_7() const {
            return _ProjectionRead__check_inv_7(TMbuffer);
        }

        _ProjectionRead__check_inv_4 _projected_state_for__check_inv_4() const {
            return _ProjectionRead__check_inv_4(TMstatus);
        }

        _ProjectionRead__check_inv_5 _projected_state_for__check_inv_5() const {
            return _ProjectionRead__check_inv_5(TMstatus,TMpool);
        }

        _ProjectionRead__check_inv_8 _projected_state_for__check_inv_8() const {
            return _ProjectionRead__check_inv_8(TCpool);
        }

        _ProjectionRead__check_inv_9 _projected_state_for__check_inv_9() const {
            return _ProjectionRead__check_inv_9(TMpool);
        }

        _ProjectionWrite_Report_TC_Rejection _update_for_Report_TC_Rejection() const {
            return _ProjectionWrite_Report_TC_Rejection(TCstatus,TMstatus,TMpool);
        }

        _ProjectionWrite_Report_TC_Execution_Success _update_for_Report_TC_Execution_Success() const {
            return _ProjectionWrite_Report_TC_Execution_Success(TCstatus,TMstatus,TMpool);
        }

        _ProjectionWrite_Cancel_TM _update_for_Cancel_TM() const {
            return _ProjectionWrite_Cancel_TM(TMstatus);
        }

        _ProjectionWrite_env_Receive_TC _update_for_env_Receive_TC() const {
            return _ProjectionWrite_env_Receive_TC(TCbuffer);
        }

        _ProjectionWrite_Report_TC_Execution_Failure _update_for_Report_TC_Execution_Failure() const {
            return _ProjectionWrite_Report_TC_Execution_Failure(TCstatus,TMstatus,TMpool);
        }

        _ProjectionWrite_Pass_TM _update_for_Pass_TM() const {
            return _ProjectionWrite_Pass_TM(TMbuffer,TMstatus);
        }

        _ProjectionWrite_Drop_TM _update_for_Drop_TM() const {
            return _ProjectionWrite_Drop_TM(TMstatus,TMpool);
        }

        _ProjectionWrite_Reset_TM_Buffer _update_for_Reset_TM_Buffer() const {
            return _ProjectionWrite_Reset_TM_Buffer(TCstatus,TMbuffer);
        }

        _ProjectionWrite_Skip_TC_Failure_Report _update_for_Skip_TC_Failure_Report() const {
            return _ProjectionWrite_Skip_TC_Failure_Report(TCstatus);
        }

        _ProjectionWrite_Poll_TC _update_for_Poll_TC() const {
            return _ProjectionWrite_Poll_TC(TCpool,TCbuffer,TCstatus);
        }

        _ProjectionWrite_Skip_TC_Acceptance_Report _update_for_Skip_TC_Acceptance_Report() const {
            return _ProjectionWrite_Skip_TC_Acceptance_Report(TCstatus);
        }

        _ProjectionWrite_Accept_TC _update_for_Accept_TC() const {
            return _ProjectionWrite_Accept_TC(TCstatus);
        }

        _ProjectionWrite_Fail_TC_Execution _update_for_Fail_TC_Execution() const {
            return _ProjectionWrite_Fail_TC_Execution(TCstatus);
        }

        _ProjectionWrite_Report_TC_Acceptance _update_for_Report_TC_Acceptance() const {
            return _ProjectionWrite_Report_TC_Acceptance(TCstatus,TMstatus,TMpool);
        }

        _ProjectionWrite_Reject_TC _update_for_Reject_TC() const {
            return _ProjectionWrite_Reject_TC(TCstatus);
        }

        _ProjectionWrite_Skip_TC_Rejection_Report _update_for_Skip_TC_Rejection_Report() const {
            return _ProjectionWrite_Skip_TC_Rejection_Report(TCstatus);
        }

        _ProjectionWrite_env_Deliver_TM _update_for_env_Deliver_TM() const {
            return _ProjectionWrite_env_Deliver_TM(TMbuffer);
        }

        _ProjectionWrite_Execute_TC_Successfully _update_for_Execute_TC_Successfully() const {
            return _ProjectionWrite_Execute_TC_Successfully(TCstatus);
        }

        _ProjectionWrite_Skip_TC_Success_Report _update_for_Skip_TC_Success_Report() const {
            return _ProjectionWrite_Skip_TC_Success_Report(TCstatus);
        }

        _ProjectionWrite_Drop_TC _update_for_Drop_TC() const {
            return _ProjectionWrite_Drop_TC(TCpool,TCstatus);
        }

        _ProjectionWrite_Produce_TM _update_for_Produce_TM() const {
            return _ProjectionWrite_Produce_TM(TMstatus,TMpool);
        }

        void _apply_update_for_Report_TC_Rejection(const _ProjectionWrite_Report_TC_Rejection& update) {
            this->TCstatus = update.TCstatus;
            this->TMstatus = update.TMstatus;
            this->TMpool = update.TMpool;
        }

        void _apply_update_for_Report_TC_Execution_Success(const _ProjectionWrite_Report_TC_Execution_Success& update) {
            this->TCstatus = update.TCstatus;
            this->TMstatus = update.TMstatus;
            this->TMpool = update.TMpool;
        }

        void _apply_update_for_Cancel_TM(const _ProjectionWrite_Cancel_TM& update) {
            this->TMstatus = update.TMstatus;
        }

        void _apply_update_for_env_Receive_TC(const _ProjectionWrite_env_Receive_TC& update) {
            this->TCbuffer = update.TCbuffer;
        }

        void _apply_update_for_Report_TC_Execution_Failure(const _ProjectionWrite_Report_TC_Execution_Failure& update) {
            this->TCstatus = update.TCstatus;
            this->TMstatus = update.TMstatus;
            this->TMpool = update.TMpool;
        }

        void _apply_update_for_Pass_TM(const _ProjectionWrite_Pass_TM& update) {
            this->TMbuffer = update.TMbuffer;
            this->TMstatus = update.TMstatus;
        }

        void _apply_update_for_Drop_TM(const _ProjectionWrite_Drop_TM& update) {
            this->TMstatus = update.TMstatus;
            this->TMpool = update.TMpool;
        }

        void _apply_update_for_Reset_TM_Buffer(const _ProjectionWrite_Reset_TM_Buffer& update) {
            this->TCstatus = update.TCstatus;
            this->TMbuffer = update.TMbuffer;
        }

        void _apply_update_for_Skip_TC_Failure_Report(const _ProjectionWrite_Skip_TC_Failure_Report& update) {
            this->TCstatus = update.TCstatus;
        }

        void _apply_update_for_Poll_TC(const _ProjectionWrite_Poll_TC& update) {
            this->TCpool = update.TCpool;
            this->TCbuffer = update.TCbuffer;
            this->TCstatus = update.TCstatus;
        }

        void _apply_update_for_Skip_TC_Acceptance_Report(const _ProjectionWrite_Skip_TC_Acceptance_Report& update) {
            this->TCstatus = update.TCstatus;
        }

        void _apply_update_for_Accept_TC(const _ProjectionWrite_Accept_TC& update) {
            this->TCstatus = update.TCstatus;
        }

        void _apply_update_for_Fail_TC_Execution(const _ProjectionWrite_Fail_TC_Execution& update) {
            this->TCstatus = update.TCstatus;
        }

        void _apply_update_for_Report_TC_Acceptance(const _ProjectionWrite_Report_TC_Acceptance& update) {
            this->TCstatus = update.TCstatus;
            this->TMstatus = update.TMstatus;
            this->TMpool = update.TMpool;
        }

        void _apply_update_for_Reject_TC(const _ProjectionWrite_Reject_TC& update) {
            this->TCstatus = update.TCstatus;
        }

        void _apply_update_for_Skip_TC_Rejection_Report(const _ProjectionWrite_Skip_TC_Rejection_Report& update) {
            this->TCstatus = update.TCstatus;
        }

        void _apply_update_for_env_Deliver_TM(const _ProjectionWrite_env_Deliver_TM& update) {
            this->TMbuffer = update.TMbuffer;
        }

        void _apply_update_for_Execute_TC_Successfully(const _ProjectionWrite_Execute_TC_Successfully& update) {
            this->TCstatus = update.TCstatus;
        }

        void _apply_update_for_Skip_TC_Success_Report(const _ProjectionWrite_Skip_TC_Success_Report& update) {
            this->TCstatus = update.TCstatus;
        }

        void _apply_update_for_Drop_TC(const _ProjectionWrite_Drop_TC& update) {
            this->TCpool = update.TCpool;
            this->TCstatus = update.TCstatus;
        }

        void _apply_update_for_Produce_TM(const _ProjectionWrite_Produce_TM& update) {
            this->TMstatus = update.TMstatus;
            this->TMpool = update.TMpool;
        }

        bool _check_inv_1() const {
            return (((TCstatus.checkDomain(_PACKET_START_ADDRESSES_IN_TC_POOL))._and((TCstatus.checkRange(_TC_STATUSES)))._and((TCstatus.isFunction()))._and((TCstatus.isPartial(_PACKET_START_ADDRESSES_IN_TC_POOL))))).booleanValue();
        }

        bool _check_inv_2() const {
            return (TCstatus.domain().equal(TCpool.domain())).booleanValue();
        }

        bool _check_inv_3() const {
            BBoolean _ic_boolean_21 = BBoolean(true);
            for(const PACKET_START_ADDRESSES_IN_TC_POOL& _ic_tc_handler_1 : TCstatus.domain()) {
                if(!((BBoolean(!(BSet<TC_STATUSES >((TC_STATUSES(TC_STATUSES::TC_Accepted)), (TC_STATUSES(TC_STATUSES::TC_Waiting_for_Execution)), (TC_STATUSES(TC_STATUSES::TC_Successfully_Executed)), (TC_STATUSES(TC_STATUSES::TC_Execution_Failed)))).elementOf(TCstatus.functionCall(_ic_tc_handler_1)).booleanValue() || VALID_TCS.elementOf(TCpool.functionCall(_ic_tc_handler_1)).booleanValue()))).booleanValue()) {
                    _ic_boolean_21 = BBoolean(false);
                    break;
                }

            }

            return (_ic_boolean_21).booleanValue();
        }

        bool _check_inv_4() const {
            return (((TMstatus.checkDomain(_PACKET_START_ADDRESSES_IN_TM_POOL))._and((TMstatus.checkRange(_TM_STATUSES)))._and((TMstatus.isFunction()))._and((TMstatus.isPartial(_PACKET_START_ADDRESSES_IN_TM_POOL))))).booleanValue();
        }

        bool _check_inv_5() const {
            return (TMstatus.domain().equal(TMpool.domain())).booleanValue();
        }

        bool _check_inv_6() const {
            return (((TCbuffer.checkDomain(_PACKET_START_ADDRESSES_IN_TC_BUFFER))._and((TCbuffer.checkRange(_TC_SET)))._and((TCbuffer.isFunction()))._and((TCbuffer.isPartial(_PACKET_START_ADDRESSES_IN_TC_BUFFER))))).booleanValue();
        }

        bool _check_inv_7() const {
            return (((TMbuffer.checkDomain(_PACKET_START_ADDRESSES_IN_TM_BUFFER))._and((TMbuffer.checkRange(_TM_SET)))._and((TMbuffer.isFunction()))._and((TMbuffer.isPartial(_PACKET_START_ADDRESSES_IN_TM_BUFFER))))).booleanValue();
        }

        bool _check_inv_8() const {
            return (((TCpool.checkDomain(_PACKET_START_ADDRESSES_IN_TC_POOL))._and((TCpool.checkRange(_TC_SET)))._and((TCpool.isFunction()))._and((TCpool.isPartial(_PACKET_START_ADDRESSES_IN_TC_POOL))))).booleanValue();
        }

        bool _check_inv_9() const {
            return (((TMpool.checkDomain(_PACKET_START_ADDRESSES_IN_TM_POOL))._and((TMpool.checkRange(_TM_SET)))._and((TMpool.isFunction()))._and((TMpool.isPartial(_PACKET_START_ADDRESSES_IN_TM_POOL))))).booleanValue();
        }

        obsw_M001_2 _copy() const {
            return obsw_M001_2(*this);
        }

        friend bool operator ==(const obsw_M001_2& o1, const obsw_M001_2& o2) {
            return o1._get_TCstatus() == o2._get_TCstatus() && o1._get_TMstatus() == o2._get_TMstatus() && o1._get_TCbuffer() == o2._get_TCbuffer() && o1._get_TCpool() == o2._get_TCpool() && o1._get_TMbuffer() == o2._get_TMbuffer() && o1._get_TMpool() == o2._get_TMpool();
        }

        friend bool operator !=(const obsw_M001_2& o1, const obsw_M001_2& o2) {
            return o1._get_TCstatus() != o2._get_TCstatus() || o1._get_TMstatus() != o2._get_TMstatus() || o1._get_TCbuffer() != o2._get_TCbuffer() || o1._get_TCpool() != o2._get_TCpool() || o1._get_TMbuffer() != o2._get_TMbuffer() || o1._get_TMpool() != o2._get_TMpool();
        }

        int hashCode() const {
            return this->_hashCode_1();
        }

        int _hashCode_1() const {
            int result = 1;
            result = (1543 * result) ^ ((this->_get_TCstatus()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_TMstatus()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_TCbuffer()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_TCpool()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_TMbuffer()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_TMpool()).hashCode() << 1);
            return result;
        }

        int _hashCode_2() const {
            int result = 1;
            result = (6151 * result) ^ ((this->_get_TCstatus()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_TMstatus()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_TCbuffer()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_TCpool()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_TMbuffer()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_TMpool()).hashCode() << 1);
            return result;
        }

        friend std::ostream& operator<<(std::ostream &strm, const obsw_M001_2 &machine) {
          strm << "_get_TCstatus: " << machine._get_TCstatus() << "\n";
          strm << "_get_TMstatus: " << machine._get_TMstatus() << "\n";
          strm << "_get_TCbuffer: " << machine._get_TCbuffer() << "\n";
          strm << "_get_TCpool: " << machine._get_TCpool() << "\n";
          strm << "_get_TMbuffer: " << machine._get_TMbuffer() << "\n";
          strm << "_get_TMpool: " << machine._get_TMpool() << "\n";
          return strm;
        }


};


class ModelChecker {
    private:
        obsw_M001_2::Type type;
        int threads;
        bool isCaching;
        bool isDebug;

        std::list<obsw_M001_2> unvisitedStates;
        std::unordered_set<obsw_M001_2, obsw_M001_2::Hash, obsw_M001_2::HashEqual> states;
        std::atomic<int> transitions;
        std::mutex mutex;
        std::mutex waitMutex;
        std::mutex cacheMutex;
        std::condition_variable waitCV;

        std::atomic<bool> invariantViolatedBool;
        std::atomic<bool> deadlockDetected;
        obsw_M001_2 counterExampleState;

        std::unordered_map<BSet<BTuple<obsw_M001_2::TC_SET, obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER >>, std::unordered_map<obsw_M001_2::_ProjectionRead_env_Receive_TC, obsw_M001_2::_ProjectionWrite_env_Receive_TC, obsw_M001_2::_ProjectionRead_env_Receive_TC::Hash, obsw_M001_2::_ProjectionRead_env_Receive_TC::HashEqual>, BSet<BTuple<obsw_M001_2::TC_SET, obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER >>::SetHash, BSet<BTuple<obsw_M001_2::TC_SET, obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER >>::SetHashEqual> _OpCache_env_Receive_TC;
        std::unordered_map<obsw_M001_2::_ProjectionRead__tr_env_Receive_TC,  BSet<BTuple<obsw_M001_2::TC_SET, obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER >>, obsw_M001_2::_ProjectionRead__tr_env_Receive_TC::Hash, obsw_M001_2::_ProjectionRead__tr_env_Receive_TC::HashEqual> _OpCache_tr_env_Receive_TC;
        std::mutex _ProjectionRead_env_Receive_TC_mutex;
        std::mutex _ProjectionRead__tr_env_Receive_TC_mutex;

        std::unordered_map<BSet<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER >>, std::unordered_map<obsw_M001_2::_ProjectionRead_Poll_TC, obsw_M001_2::_ProjectionWrite_Poll_TC, obsw_M001_2::_ProjectionRead_Poll_TC::Hash, obsw_M001_2::_ProjectionRead_Poll_TC::HashEqual>, BSet<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER >>::SetHash, BSet<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER >>::SetHashEqual> _OpCache_Poll_TC;
        std::unordered_map<obsw_M001_2::_ProjectionRead__tr_Poll_TC,  BSet<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER >>, obsw_M001_2::_ProjectionRead__tr_Poll_TC::Hash, obsw_M001_2::_ProjectionRead__tr_Poll_TC::HashEqual> _OpCache_tr_Poll_TC;
        std::mutex _ProjectionRead_Poll_TC_mutex;
        std::mutex _ProjectionRead__tr_Poll_TC_mutex;

        std::unordered_map<BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>, std::unordered_map<obsw_M001_2::_ProjectionRead_Accept_TC, obsw_M001_2::_ProjectionWrite_Accept_TC, obsw_M001_2::_ProjectionRead_Accept_TC::Hash, obsw_M001_2::_ProjectionRead_Accept_TC::HashEqual>, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>::SetHash, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>::SetHashEqual> _OpCache_Accept_TC;
        std::unordered_map<obsw_M001_2::_ProjectionRead__tr_Accept_TC,  BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>, obsw_M001_2::_ProjectionRead__tr_Accept_TC::Hash, obsw_M001_2::_ProjectionRead__tr_Accept_TC::HashEqual> _OpCache_tr_Accept_TC;
        std::mutex _ProjectionRead_Accept_TC_mutex;
        std::mutex _ProjectionRead__tr_Accept_TC_mutex;

        std::unordered_map<BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>, std::unordered_map<obsw_M001_2::_ProjectionRead_Reject_TC, obsw_M001_2::_ProjectionWrite_Reject_TC, obsw_M001_2::_ProjectionRead_Reject_TC::Hash, obsw_M001_2::_ProjectionRead_Reject_TC::HashEqual>, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>::SetHash, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>::SetHashEqual> _OpCache_Reject_TC;
        std::unordered_map<obsw_M001_2::_ProjectionRead__tr_Reject_TC,  BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>, obsw_M001_2::_ProjectionRead__tr_Reject_TC::Hash, obsw_M001_2::_ProjectionRead__tr_Reject_TC::HashEqual> _OpCache_tr_Reject_TC;
        std::mutex _ProjectionRead_Reject_TC_mutex;
        std::mutex _ProjectionRead__tr_Reject_TC_mutex;

        std::unordered_map<BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >>, std::unordered_map<obsw_M001_2::_ProjectionRead_Report_TC_Acceptance, obsw_M001_2::_ProjectionWrite_Report_TC_Acceptance, obsw_M001_2::_ProjectionRead_Report_TC_Acceptance::Hash, obsw_M001_2::_ProjectionRead_Report_TC_Acceptance::HashEqual>, BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >>::SetHash, BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >>::SetHashEqual> _OpCache_Report_TC_Acceptance;
        std::unordered_map<obsw_M001_2::_ProjectionRead__tr_Report_TC_Acceptance,  BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >>, obsw_M001_2::_ProjectionRead__tr_Report_TC_Acceptance::Hash, obsw_M001_2::_ProjectionRead__tr_Report_TC_Acceptance::HashEqual> _OpCache_tr_Report_TC_Acceptance;
        std::mutex _ProjectionRead_Report_TC_Acceptance_mutex;
        std::mutex _ProjectionRead__tr_Report_TC_Acceptance_mutex;

        std::unordered_map<BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>, std::unordered_map<obsw_M001_2::_ProjectionRead_Skip_TC_Acceptance_Report, obsw_M001_2::_ProjectionWrite_Skip_TC_Acceptance_Report, obsw_M001_2::_ProjectionRead_Skip_TC_Acceptance_Report::Hash, obsw_M001_2::_ProjectionRead_Skip_TC_Acceptance_Report::HashEqual>, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>::SetHash, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>::SetHashEqual> _OpCache_Skip_TC_Acceptance_Report;
        std::unordered_map<obsw_M001_2::_ProjectionRead__tr_Skip_TC_Acceptance_Report,  BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>, obsw_M001_2::_ProjectionRead__tr_Skip_TC_Acceptance_Report::Hash, obsw_M001_2::_ProjectionRead__tr_Skip_TC_Acceptance_Report::HashEqual> _OpCache_tr_Skip_TC_Acceptance_Report;
        std::mutex _ProjectionRead_Skip_TC_Acceptance_Report_mutex;
        std::mutex _ProjectionRead__tr_Skip_TC_Acceptance_Report_mutex;

        std::unordered_map<BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >>, std::unordered_map<obsw_M001_2::_ProjectionRead_Report_TC_Rejection, obsw_M001_2::_ProjectionWrite_Report_TC_Rejection, obsw_M001_2::_ProjectionRead_Report_TC_Rejection::Hash, obsw_M001_2::_ProjectionRead_Report_TC_Rejection::HashEqual>, BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >>::SetHash, BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >>::SetHashEqual> _OpCache_Report_TC_Rejection;
        std::unordered_map<obsw_M001_2::_ProjectionRead__tr_Report_TC_Rejection,  BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >>, obsw_M001_2::_ProjectionRead__tr_Report_TC_Rejection::Hash, obsw_M001_2::_ProjectionRead__tr_Report_TC_Rejection::HashEqual> _OpCache_tr_Report_TC_Rejection;
        std::mutex _ProjectionRead_Report_TC_Rejection_mutex;
        std::mutex _ProjectionRead__tr_Report_TC_Rejection_mutex;

        std::unordered_map<BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>, std::unordered_map<obsw_M001_2::_ProjectionRead_Skip_TC_Rejection_Report, obsw_M001_2::_ProjectionWrite_Skip_TC_Rejection_Report, obsw_M001_2::_ProjectionRead_Skip_TC_Rejection_Report::Hash, obsw_M001_2::_ProjectionRead_Skip_TC_Rejection_Report::HashEqual>, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>::SetHash, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>::SetHashEqual> _OpCache_Skip_TC_Rejection_Report;
        std::unordered_map<obsw_M001_2::_ProjectionRead__tr_Skip_TC_Rejection_Report,  BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>, obsw_M001_2::_ProjectionRead__tr_Skip_TC_Rejection_Report::Hash, obsw_M001_2::_ProjectionRead__tr_Skip_TC_Rejection_Report::HashEqual> _OpCache_tr_Skip_TC_Rejection_Report;
        std::mutex _ProjectionRead_Skip_TC_Rejection_Report_mutex;
        std::mutex _ProjectionRead__tr_Skip_TC_Rejection_Report_mutex;

        std::unordered_map<BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>, std::unordered_map<obsw_M001_2::_ProjectionRead_Execute_TC_Successfully, obsw_M001_2::_ProjectionWrite_Execute_TC_Successfully, obsw_M001_2::_ProjectionRead_Execute_TC_Successfully::Hash, obsw_M001_2::_ProjectionRead_Execute_TC_Successfully::HashEqual>, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>::SetHash, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>::SetHashEqual> _OpCache_Execute_TC_Successfully;
        std::unordered_map<obsw_M001_2::_ProjectionRead__tr_Execute_TC_Successfully,  BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>, obsw_M001_2::_ProjectionRead__tr_Execute_TC_Successfully::Hash, obsw_M001_2::_ProjectionRead__tr_Execute_TC_Successfully::HashEqual> _OpCache_tr_Execute_TC_Successfully;
        std::mutex _ProjectionRead_Execute_TC_Successfully_mutex;
        std::mutex _ProjectionRead__tr_Execute_TC_Successfully_mutex;

        std::unordered_map<BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>, std::unordered_map<obsw_M001_2::_ProjectionRead_Reset_TM_Buffer, obsw_M001_2::_ProjectionWrite_Reset_TM_Buffer, obsw_M001_2::_ProjectionRead_Reset_TM_Buffer::Hash, obsw_M001_2::_ProjectionRead_Reset_TM_Buffer::HashEqual>, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>::SetHash, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>::SetHashEqual> _OpCache_Reset_TM_Buffer;
        std::unordered_map<obsw_M001_2::_ProjectionRead__tr_Reset_TM_Buffer,  BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>, obsw_M001_2::_ProjectionRead__tr_Reset_TM_Buffer::Hash, obsw_M001_2::_ProjectionRead__tr_Reset_TM_Buffer::HashEqual> _OpCache_tr_Reset_TM_Buffer;
        std::mutex _ProjectionRead_Reset_TM_Buffer_mutex;
        std::mutex _ProjectionRead__tr_Reset_TM_Buffer_mutex;

        std::unordered_map<BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>, std::unordered_map<obsw_M001_2::_ProjectionRead_Fail_TC_Execution, obsw_M001_2::_ProjectionWrite_Fail_TC_Execution, obsw_M001_2::_ProjectionRead_Fail_TC_Execution::Hash, obsw_M001_2::_ProjectionRead_Fail_TC_Execution::HashEqual>, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>::SetHash, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>::SetHashEqual> _OpCache_Fail_TC_Execution;
        std::unordered_map<obsw_M001_2::_ProjectionRead__tr_Fail_TC_Execution,  BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>, obsw_M001_2::_ProjectionRead__tr_Fail_TC_Execution::Hash, obsw_M001_2::_ProjectionRead__tr_Fail_TC_Execution::HashEqual> _OpCache_tr_Fail_TC_Execution;
        std::mutex _ProjectionRead_Fail_TC_Execution_mutex;
        std::mutex _ProjectionRead__tr_Fail_TC_Execution_mutex;

        std::unordered_map<BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >>, std::unordered_map<obsw_M001_2::_ProjectionRead_Report_TC_Execution_Success, obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Success, obsw_M001_2::_ProjectionRead_Report_TC_Execution_Success::Hash, obsw_M001_2::_ProjectionRead_Report_TC_Execution_Success::HashEqual>, BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >>::SetHash, BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >>::SetHashEqual> _OpCache_Report_TC_Execution_Success;
        std::unordered_map<obsw_M001_2::_ProjectionRead__tr_Report_TC_Execution_Success,  BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >>, obsw_M001_2::_ProjectionRead__tr_Report_TC_Execution_Success::Hash, obsw_M001_2::_ProjectionRead__tr_Report_TC_Execution_Success::HashEqual> _OpCache_tr_Report_TC_Execution_Success;
        std::mutex _ProjectionRead_Report_TC_Execution_Success_mutex;
        std::mutex _ProjectionRead__tr_Report_TC_Execution_Success_mutex;

        std::unordered_map<BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>, std::unordered_map<obsw_M001_2::_ProjectionRead_Skip_TC_Success_Report, obsw_M001_2::_ProjectionWrite_Skip_TC_Success_Report, obsw_M001_2::_ProjectionRead_Skip_TC_Success_Report::Hash, obsw_M001_2::_ProjectionRead_Skip_TC_Success_Report::HashEqual>, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>::SetHash, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>::SetHashEqual> _OpCache_Skip_TC_Success_Report;
        std::unordered_map<obsw_M001_2::_ProjectionRead__tr_Skip_TC_Success_Report,  BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>, obsw_M001_2::_ProjectionRead__tr_Skip_TC_Success_Report::Hash, obsw_M001_2::_ProjectionRead__tr_Skip_TC_Success_Report::HashEqual> _OpCache_tr_Skip_TC_Success_Report;
        std::mutex _ProjectionRead_Skip_TC_Success_Report_mutex;
        std::mutex _ProjectionRead__tr_Skip_TC_Success_Report_mutex;

        std::unordered_map<BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >>, std::unordered_map<obsw_M001_2::_ProjectionRead_Report_TC_Execution_Failure, obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Failure, obsw_M001_2::_ProjectionRead_Report_TC_Execution_Failure::Hash, obsw_M001_2::_ProjectionRead_Report_TC_Execution_Failure::HashEqual>, BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >>::SetHash, BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >>::SetHashEqual> _OpCache_Report_TC_Execution_Failure;
        std::unordered_map<obsw_M001_2::_ProjectionRead__tr_Report_TC_Execution_Failure,  BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >>, obsw_M001_2::_ProjectionRead__tr_Report_TC_Execution_Failure::Hash, obsw_M001_2::_ProjectionRead__tr_Report_TC_Execution_Failure::HashEqual> _OpCache_tr_Report_TC_Execution_Failure;
        std::mutex _ProjectionRead_Report_TC_Execution_Failure_mutex;
        std::mutex _ProjectionRead__tr_Report_TC_Execution_Failure_mutex;

        std::unordered_map<BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>, std::unordered_map<obsw_M001_2::_ProjectionRead_Skip_TC_Failure_Report, obsw_M001_2::_ProjectionWrite_Skip_TC_Failure_Report, obsw_M001_2::_ProjectionRead_Skip_TC_Failure_Report::Hash, obsw_M001_2::_ProjectionRead_Skip_TC_Failure_Report::HashEqual>, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>::SetHash, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>::SetHashEqual> _OpCache_Skip_TC_Failure_Report;
        std::unordered_map<obsw_M001_2::_ProjectionRead__tr_Skip_TC_Failure_Report,  BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>, obsw_M001_2::_ProjectionRead__tr_Skip_TC_Failure_Report::Hash, obsw_M001_2::_ProjectionRead__tr_Skip_TC_Failure_Report::HashEqual> _OpCache_tr_Skip_TC_Failure_Report;
        std::mutex _ProjectionRead_Skip_TC_Failure_Report_mutex;
        std::mutex _ProjectionRead__tr_Skip_TC_Failure_Report_mutex;

        std::unordered_map<BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>, std::unordered_map<obsw_M001_2::_ProjectionRead_Drop_TC, obsw_M001_2::_ProjectionWrite_Drop_TC, obsw_M001_2::_ProjectionRead_Drop_TC::Hash, obsw_M001_2::_ProjectionRead_Drop_TC::HashEqual>, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>::SetHash, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>::SetHashEqual> _OpCache_Drop_TC;
        std::unordered_map<obsw_M001_2::_ProjectionRead__tr_Drop_TC,  BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL>, obsw_M001_2::_ProjectionRead__tr_Drop_TC::Hash, obsw_M001_2::_ProjectionRead__tr_Drop_TC::HashEqual> _OpCache_tr_Drop_TC;
        std::mutex _ProjectionRead_Drop_TC_mutex;
        std::mutex _ProjectionRead__tr_Drop_TC_mutex;

        std::unordered_map<BSet<BTuple<obsw_M001_2::TM_SET, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >>, std::unordered_map<obsw_M001_2::_ProjectionRead_Produce_TM, obsw_M001_2::_ProjectionWrite_Produce_TM, obsw_M001_2::_ProjectionRead_Produce_TM::Hash, obsw_M001_2::_ProjectionRead_Produce_TM::HashEqual>, BSet<BTuple<obsw_M001_2::TM_SET, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >>::SetHash, BSet<BTuple<obsw_M001_2::TM_SET, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >>::SetHashEqual> _OpCache_Produce_TM;
        std::unordered_map<obsw_M001_2::_ProjectionRead__tr_Produce_TM,  BSet<BTuple<obsw_M001_2::TM_SET, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >>, obsw_M001_2::_ProjectionRead__tr_Produce_TM::Hash, obsw_M001_2::_ProjectionRead__tr_Produce_TM::HashEqual> _OpCache_tr_Produce_TM;
        std::mutex _ProjectionRead_Produce_TM_mutex;
        std::mutex _ProjectionRead__tr_Produce_TM_mutex;

        std::unordered_map<BSet<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER >>, std::unordered_map<obsw_M001_2::_ProjectionRead_Pass_TM, obsw_M001_2::_ProjectionWrite_Pass_TM, obsw_M001_2::_ProjectionRead_Pass_TM::Hash, obsw_M001_2::_ProjectionRead_Pass_TM::HashEqual>, BSet<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER >>::SetHash, BSet<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER >>::SetHashEqual> _OpCache_Pass_TM;
        std::unordered_map<obsw_M001_2::_ProjectionRead__tr_Pass_TM,  BSet<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER >>, obsw_M001_2::_ProjectionRead__tr_Pass_TM::Hash, obsw_M001_2::_ProjectionRead__tr_Pass_TM::HashEqual> _OpCache_tr_Pass_TM;
        std::mutex _ProjectionRead_Pass_TM_mutex;
        std::mutex _ProjectionRead__tr_Pass_TM_mutex;

        std::unordered_map<BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL>, std::unordered_map<obsw_M001_2::_ProjectionRead_Cancel_TM, obsw_M001_2::_ProjectionWrite_Cancel_TM, obsw_M001_2::_ProjectionRead_Cancel_TM::Hash, obsw_M001_2::_ProjectionRead_Cancel_TM::HashEqual>, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL>::SetHash, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL>::SetHashEqual> _OpCache_Cancel_TM;
        std::unordered_map<obsw_M001_2::_ProjectionRead__tr_Cancel_TM,  BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL>, obsw_M001_2::_ProjectionRead__tr_Cancel_TM::Hash, obsw_M001_2::_ProjectionRead__tr_Cancel_TM::HashEqual> _OpCache_tr_Cancel_TM;
        std::mutex _ProjectionRead_Cancel_TM_mutex;
        std::mutex _ProjectionRead__tr_Cancel_TM_mutex;

        std::unordered_map<BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL>, std::unordered_map<obsw_M001_2::_ProjectionRead_Drop_TM, obsw_M001_2::_ProjectionWrite_Drop_TM, obsw_M001_2::_ProjectionRead_Drop_TM::Hash, obsw_M001_2::_ProjectionRead_Drop_TM::HashEqual>, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL>::SetHash, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL>::SetHashEqual> _OpCache_Drop_TM;
        std::unordered_map<obsw_M001_2::_ProjectionRead__tr_Drop_TM,  BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL>, obsw_M001_2::_ProjectionRead__tr_Drop_TM::Hash, obsw_M001_2::_ProjectionRead__tr_Drop_TM::HashEqual> _OpCache_tr_Drop_TM;
        std::mutex _ProjectionRead_Drop_TM_mutex;
        std::mutex _ProjectionRead__tr_Drop_TM_mutex;

        std::unordered_map<BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER>, std::unordered_map<obsw_M001_2::_ProjectionRead_env_Deliver_TM, obsw_M001_2::_ProjectionWrite_env_Deliver_TM, obsw_M001_2::_ProjectionRead_env_Deliver_TM::Hash, obsw_M001_2::_ProjectionRead_env_Deliver_TM::HashEqual>, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER>::SetHash, BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER>::SetHashEqual> _OpCache_env_Deliver_TM;
        std::unordered_map<obsw_M001_2::_ProjectionRead__tr_env_Deliver_TM,  BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER>, obsw_M001_2::_ProjectionRead__tr_env_Deliver_TM::Hash, obsw_M001_2::_ProjectionRead__tr_env_Deliver_TM::HashEqual> _OpCache_tr_env_Deliver_TM;
        std::mutex _ProjectionRead_env_Deliver_TM_mutex;
        std::mutex _ProjectionRead__tr_env_Deliver_TM_mutex;

        std::unordered_map<obsw_M001_2::_ProjectionRead__check_inv_1, bool, obsw_M001_2::_ProjectionRead__check_inv_1::Hash, obsw_M001_2::_ProjectionRead__check_inv_1::HashEqual> _InvCache__check_inv_1;
        std::mutex _ProjectionRead__check_inv_1_mutex;
        std::unordered_map<obsw_M001_2::_ProjectionRead__check_inv_2, bool, obsw_M001_2::_ProjectionRead__check_inv_2::Hash, obsw_M001_2::_ProjectionRead__check_inv_2::HashEqual> _InvCache__check_inv_2;
        std::mutex _ProjectionRead__check_inv_2_mutex;
        std::unordered_map<obsw_M001_2::_ProjectionRead__check_inv_3, bool, obsw_M001_2::_ProjectionRead__check_inv_3::Hash, obsw_M001_2::_ProjectionRead__check_inv_3::HashEqual> _InvCache__check_inv_3;
        std::mutex _ProjectionRead__check_inv_3_mutex;
        std::unordered_map<obsw_M001_2::_ProjectionRead__check_inv_4, bool, obsw_M001_2::_ProjectionRead__check_inv_4::Hash, obsw_M001_2::_ProjectionRead__check_inv_4::HashEqual> _InvCache__check_inv_4;
        std::mutex _ProjectionRead__check_inv_4_mutex;
        std::unordered_map<obsw_M001_2::_ProjectionRead__check_inv_5, bool, obsw_M001_2::_ProjectionRead__check_inv_5::Hash, obsw_M001_2::_ProjectionRead__check_inv_5::HashEqual> _InvCache__check_inv_5;
        std::mutex _ProjectionRead__check_inv_5_mutex;
        std::unordered_map<obsw_M001_2::_ProjectionRead__check_inv_6, bool, obsw_M001_2::_ProjectionRead__check_inv_6::Hash, obsw_M001_2::_ProjectionRead__check_inv_6::HashEqual> _InvCache__check_inv_6;
        std::mutex _ProjectionRead__check_inv_6_mutex;
        std::unordered_map<obsw_M001_2::_ProjectionRead__check_inv_7, bool, obsw_M001_2::_ProjectionRead__check_inv_7::Hash, obsw_M001_2::_ProjectionRead__check_inv_7::HashEqual> _InvCache__check_inv_7;
        std::mutex _ProjectionRead__check_inv_7_mutex;
        std::unordered_map<obsw_M001_2::_ProjectionRead__check_inv_8, bool, obsw_M001_2::_ProjectionRead__check_inv_8::Hash, obsw_M001_2::_ProjectionRead__check_inv_8::HashEqual> _InvCache__check_inv_8;
        std::mutex _ProjectionRead__check_inv_8_mutex;
        std::unordered_map<obsw_M001_2::_ProjectionRead__check_inv_9, bool, obsw_M001_2::_ProjectionRead__check_inv_9::Hash, obsw_M001_2::_ProjectionRead__check_inv_9::HashEqual> _InvCache__check_inv_9;
        std::mutex _ProjectionRead__check_inv_9_mutex;

        std::unordered_map<obsw_M001_2, obsw_M001_2, obsw_M001_2::Hash, obsw_M001_2::HashEqual> parents;

    public:
        ModelChecker() {}

        ModelChecker(obsw_M001_2::Type type, int threads, bool isCaching, bool isDebug) {
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
            obsw_M001_2 machine = obsw_M001_2();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            while(!unvisitedStates.empty()) {
                obsw_M001_2 state = next();

                std::unordered_set<obsw_M001_2, obsw_M001_2::Hash, obsw_M001_2::HashEqual> nextStates = generateNextStates(state);

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
            obsw_M001_2 machine = obsw_M001_2();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            std::atomic<bool> stopThreads(false);
            std::atomic<int> possibleQueueChanges;
            possibleQueueChanges = 0;

            while(!unvisitedStates.empty() && !stopThreads.load()) {
                possibleQueueChanges.fetch_add(1);
                obsw_M001_2 state = next();
                std::packaged_task<void()> task([&, state] {
                    std::unordered_set<obsw_M001_2, obsw_M001_2::Hash, obsw_M001_2::HashEqual> nextStates = generateNextStates(state);

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
        obsw_M001_2 next() {
            {
                std::unique_lock<std::mutex> lock(mutex);
                switch(type) {
                    case obsw_M001_2::BFS: {
                        obsw_M001_2 state = unvisitedStates.front();
                        unvisitedStates.pop_front();
                        return state;
                    }
                    case obsw_M001_2::DFS: {
                        obsw_M001_2 state = unvisitedStates.back();
                        unvisitedStates.pop_back();
                        return state;
                    }
                    case obsw_M001_2::MIXED: {
                        if(unvisitedStates.size() % 2 == 0) {
                            obsw_M001_2 state = unvisitedStates.front();
                            unvisitedStates.pop_front();
                            return state;
                        } else {
                            obsw_M001_2 state = unvisitedStates.back();
                            unvisitedStates.pop_back();
                            return state;
                        }
                    }
                }
                obsw_M001_2 state = unvisitedStates.front();
                unvisitedStates.pop_front();
                return state;
            };
        }

        std::unordered_set<obsw_M001_2, obsw_M001_2::Hash, obsw_M001_2::HashEqual> generateNextStates(const obsw_M001_2& state) {
            std::unordered_set<obsw_M001_2, obsw_M001_2::Hash, obsw_M001_2::HashEqual> result = std::unordered_set<obsw_M001_2, obsw_M001_2::Hash, obsw_M001_2::HashEqual>();
            if(isCaching) {
                obsw_M001_2::_ProjectionRead__tr_env_Receive_TC read__tr_env_Receive_TC_state = state._projected_state_for__tr_env_Receive_TC();
                auto _trid_1_ptr = _OpCache_tr_env_Receive_TC.find(read__tr_env_Receive_TC_state);
                if(_trid_1_ptr == _OpCache_tr_env_Receive_TC.end()) {
                    BSet<BTuple<obsw_M001_2::TC_SET, obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER >> _trid_1 = state._tr_env_Receive_TC();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_env_Receive_TC_lock(_ProjectionRead__tr_env_Receive_TC_mutex);
                        _OpCache_tr_env_Receive_TC.insert({read__tr_env_Receive_TC_state, _trid_1});
                    }
                    for(const BTuple<obsw_M001_2::TC_SET, obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER >& param : _trid_1) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER _tmp_1 = param.projection2();
                        obsw_M001_2::TC_SET _tmp_2 = param.projection1();

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_env_Receive_TC readState = state._projected_state_for_env_Receive_TC();

                        auto _OpCache_with_parameter_env_Receive_TC_ptr = _OpCache_env_Receive_TC.find(param);
                        if(_OpCache_with_parameter_env_Receive_TC_ptr == _OpCache_env_Receive_TC.end()) {
                            copiedState.env_Receive_TC(_tmp_2, _tmp_1);
                            obsw_M001_2::_ProjectionWrite_env_Receive_TC writeState = copiedState._update_for_env_Receive_TC();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_env_Receive_TC, obsw_M001_2::_ProjectionWrite_env_Receive_TC, obsw_M001_2::_ProjectionRead_env_Receive_TC::Hash, obsw_M001_2::_ProjectionRead_env_Receive_TC::HashEqual> _OpCache_with_parameter_env_Receive_TC;
                            _OpCache_with_parameter_env_Receive_TC.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_Receive_TC_lock(_ProjectionRead_env_Receive_TC_mutex);
                                _OpCache_env_Receive_TC.insert({param, _OpCache_with_parameter_env_Receive_TC});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_env_Receive_TC, obsw_M001_2::_ProjectionWrite_env_Receive_TC, obsw_M001_2::_ProjectionRead_env_Receive_TC::Hash, obsw_M001_2::_ProjectionRead_env_Receive_TC::HashEqual> _OpCache_with_parameter_env_Receive_TC = _OpCache_with_parameter_env_Receive_TC_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_Receive_TC.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_Receive_TC.end()) {
                                obsw_M001_2::_ProjectionWrite_env_Receive_TC writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_Receive_TC(writeState);
                            } else {
                                copiedState.env_Receive_TC(_tmp_2, _tmp_1);
                                obsw_M001_2::_ProjectionWrite_env_Receive_TC writeState = copiedState._update_for_env_Receive_TC();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_Receive_TC_lock(_ProjectionRead_env_Receive_TC_mutex);
                                    _OpCache_with_parameter_env_Receive_TC.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_Receive_TC";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BTuple<obsw_M001_2::TC_SET, obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER >> _trid_1 = _trid_1_ptr->second;
                    for(const BTuple<obsw_M001_2::TC_SET, obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER >& param : _trid_1) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER _tmp_1 = param.projection2();
                        obsw_M001_2::TC_SET _tmp_2 = param.projection1();

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_env_Receive_TC readState = state._projected_state_for_env_Receive_TC();

                        auto _OpCache_with_parameter_env_Receive_TC_ptr = _OpCache_env_Receive_TC.find(param);
                        if(_OpCache_with_parameter_env_Receive_TC_ptr == _OpCache_env_Receive_TC.end()) {
                            copiedState.env_Receive_TC(_tmp_2, _tmp_1);
                            obsw_M001_2::_ProjectionWrite_env_Receive_TC writeState = copiedState._update_for_env_Receive_TC();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_env_Receive_TC, obsw_M001_2::_ProjectionWrite_env_Receive_TC, obsw_M001_2::_ProjectionRead_env_Receive_TC::Hash, obsw_M001_2::_ProjectionRead_env_Receive_TC::HashEqual> _OpCache_with_parameter_env_Receive_TC;
                            _OpCache_with_parameter_env_Receive_TC.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_Receive_TC_lock(_ProjectionRead_env_Receive_TC_mutex);
                                _OpCache_env_Receive_TC.insert({param, _OpCache_with_parameter_env_Receive_TC});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_env_Receive_TC, obsw_M001_2::_ProjectionWrite_env_Receive_TC, obsw_M001_2::_ProjectionRead_env_Receive_TC::Hash, obsw_M001_2::_ProjectionRead_env_Receive_TC::HashEqual> _OpCache_with_parameter_env_Receive_TC = _OpCache_with_parameter_env_Receive_TC_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_Receive_TC.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_Receive_TC.end()) {
                                obsw_M001_2::_ProjectionWrite_env_Receive_TC writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_Receive_TC(writeState);
                            } else {
                                copiedState.env_Receive_TC(_tmp_2, _tmp_1);
                                obsw_M001_2::_ProjectionWrite_env_Receive_TC writeState = copiedState._update_for_env_Receive_TC();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_Receive_TC_lock(_ProjectionRead_env_Receive_TC_mutex);
                                    _OpCache_with_parameter_env_Receive_TC.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_Receive_TC";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                obsw_M001_2::_ProjectionRead__tr_Poll_TC read__tr_Poll_TC_state = state._projected_state_for__tr_Poll_TC();
                auto _trid_2_ptr = _OpCache_tr_Poll_TC.find(read__tr_Poll_TC_state);
                if(_trid_2_ptr == _OpCache_tr_Poll_TC.end()) {
                    BSet<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER >> _trid_2 = state._tr_Poll_TC();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_Poll_TC_lock(_ProjectionRead__tr_Poll_TC_mutex);
                        _OpCache_tr_Poll_TC.insert({read__tr_Poll_TC_state, _trid_2});
                    }
                    for(const BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER >& param : _trid_2) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER _tmp_1 = param.projection2();
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_2 = param.projection1();

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Poll_TC readState = state._projected_state_for_Poll_TC();

                        auto _OpCache_with_parameter_Poll_TC_ptr = _OpCache_Poll_TC.find(param);
                        if(_OpCache_with_parameter_Poll_TC_ptr == _OpCache_Poll_TC.end()) {
                            copiedState.Poll_TC(_tmp_2, _tmp_1);
                            obsw_M001_2::_ProjectionWrite_Poll_TC writeState = copiedState._update_for_Poll_TC();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Poll_TC, obsw_M001_2::_ProjectionWrite_Poll_TC, obsw_M001_2::_ProjectionRead_Poll_TC::Hash, obsw_M001_2::_ProjectionRead_Poll_TC::HashEqual> _OpCache_with_parameter_Poll_TC;
                            _OpCache_with_parameter_Poll_TC.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Poll_TC_lock(_ProjectionRead_Poll_TC_mutex);
                                _OpCache_Poll_TC.insert({param, _OpCache_with_parameter_Poll_TC});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Poll_TC, obsw_M001_2::_ProjectionWrite_Poll_TC, obsw_M001_2::_ProjectionRead_Poll_TC::Hash, obsw_M001_2::_ProjectionRead_Poll_TC::HashEqual> _OpCache_with_parameter_Poll_TC = _OpCache_with_parameter_Poll_TC_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Poll_TC.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Poll_TC.end()) {
                                obsw_M001_2::_ProjectionWrite_Poll_TC writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Poll_TC(writeState);
                            } else {
                                copiedState.Poll_TC(_tmp_2, _tmp_1);
                                obsw_M001_2::_ProjectionWrite_Poll_TC writeState = copiedState._update_for_Poll_TC();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Poll_TC_lock(_ProjectionRead_Poll_TC_mutex);
                                    _OpCache_with_parameter_Poll_TC.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Poll_TC";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER >> _trid_2 = _trid_2_ptr->second;
                    for(const BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER >& param : _trid_2) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER _tmp_1 = param.projection2();
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_2 = param.projection1();

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Poll_TC readState = state._projected_state_for_Poll_TC();

                        auto _OpCache_with_parameter_Poll_TC_ptr = _OpCache_Poll_TC.find(param);
                        if(_OpCache_with_parameter_Poll_TC_ptr == _OpCache_Poll_TC.end()) {
                            copiedState.Poll_TC(_tmp_2, _tmp_1);
                            obsw_M001_2::_ProjectionWrite_Poll_TC writeState = copiedState._update_for_Poll_TC();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Poll_TC, obsw_M001_2::_ProjectionWrite_Poll_TC, obsw_M001_2::_ProjectionRead_Poll_TC::Hash, obsw_M001_2::_ProjectionRead_Poll_TC::HashEqual> _OpCache_with_parameter_Poll_TC;
                            _OpCache_with_parameter_Poll_TC.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Poll_TC_lock(_ProjectionRead_Poll_TC_mutex);
                                _OpCache_Poll_TC.insert({param, _OpCache_with_parameter_Poll_TC});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Poll_TC, obsw_M001_2::_ProjectionWrite_Poll_TC, obsw_M001_2::_ProjectionRead_Poll_TC::Hash, obsw_M001_2::_ProjectionRead_Poll_TC::HashEqual> _OpCache_with_parameter_Poll_TC = _OpCache_with_parameter_Poll_TC_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Poll_TC.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Poll_TC.end()) {
                                obsw_M001_2::_ProjectionWrite_Poll_TC writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Poll_TC(writeState);
                            } else {
                                copiedState.Poll_TC(_tmp_2, _tmp_1);
                                obsw_M001_2::_ProjectionWrite_Poll_TC writeState = copiedState._update_for_Poll_TC();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Poll_TC_lock(_ProjectionRead_Poll_TC_mutex);
                                    _OpCache_with_parameter_Poll_TC.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Poll_TC";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                obsw_M001_2::_ProjectionRead__tr_Accept_TC read__tr_Accept_TC_state = state._projected_state_for__tr_Accept_TC();
                auto _trid_3_ptr = _OpCache_tr_Accept_TC.find(read__tr_Accept_TC_state);
                if(_trid_3_ptr == _OpCache_tr_Accept_TC.end()) {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_3 = state._tr_Accept_TC();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_Accept_TC_lock(_ProjectionRead__tr_Accept_TC_mutex);
                        _OpCache_tr_Accept_TC.insert({read__tr_Accept_TC_state, _trid_3});
                    }
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_3) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Accept_TC readState = state._projected_state_for_Accept_TC();

                        auto _OpCache_with_parameter_Accept_TC_ptr = _OpCache_Accept_TC.find(param);
                        if(_OpCache_with_parameter_Accept_TC_ptr == _OpCache_Accept_TC.end()) {
                            copiedState.Accept_TC(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Accept_TC writeState = copiedState._update_for_Accept_TC();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Accept_TC, obsw_M001_2::_ProjectionWrite_Accept_TC, obsw_M001_2::_ProjectionRead_Accept_TC::Hash, obsw_M001_2::_ProjectionRead_Accept_TC::HashEqual> _OpCache_with_parameter_Accept_TC;
                            _OpCache_with_parameter_Accept_TC.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Accept_TC_lock(_ProjectionRead_Accept_TC_mutex);
                                _OpCache_Accept_TC.insert({param, _OpCache_with_parameter_Accept_TC});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Accept_TC, obsw_M001_2::_ProjectionWrite_Accept_TC, obsw_M001_2::_ProjectionRead_Accept_TC::Hash, obsw_M001_2::_ProjectionRead_Accept_TC::HashEqual> _OpCache_with_parameter_Accept_TC = _OpCache_with_parameter_Accept_TC_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Accept_TC.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Accept_TC.end()) {
                                obsw_M001_2::_ProjectionWrite_Accept_TC writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Accept_TC(writeState);
                            } else {
                                copiedState.Accept_TC(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Accept_TC writeState = copiedState._update_for_Accept_TC();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Accept_TC_lock(_ProjectionRead_Accept_TC_mutex);
                                    _OpCache_with_parameter_Accept_TC.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Accept_TC";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_3 = _trid_3_ptr->second;
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_3) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Accept_TC readState = state._projected_state_for_Accept_TC();

                        auto _OpCache_with_parameter_Accept_TC_ptr = _OpCache_Accept_TC.find(param);
                        if(_OpCache_with_parameter_Accept_TC_ptr == _OpCache_Accept_TC.end()) {
                            copiedState.Accept_TC(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Accept_TC writeState = copiedState._update_for_Accept_TC();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Accept_TC, obsw_M001_2::_ProjectionWrite_Accept_TC, obsw_M001_2::_ProjectionRead_Accept_TC::Hash, obsw_M001_2::_ProjectionRead_Accept_TC::HashEqual> _OpCache_with_parameter_Accept_TC;
                            _OpCache_with_parameter_Accept_TC.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Accept_TC_lock(_ProjectionRead_Accept_TC_mutex);
                                _OpCache_Accept_TC.insert({param, _OpCache_with_parameter_Accept_TC});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Accept_TC, obsw_M001_2::_ProjectionWrite_Accept_TC, obsw_M001_2::_ProjectionRead_Accept_TC::Hash, obsw_M001_2::_ProjectionRead_Accept_TC::HashEqual> _OpCache_with_parameter_Accept_TC = _OpCache_with_parameter_Accept_TC_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Accept_TC.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Accept_TC.end()) {
                                obsw_M001_2::_ProjectionWrite_Accept_TC writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Accept_TC(writeState);
                            } else {
                                copiedState.Accept_TC(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Accept_TC writeState = copiedState._update_for_Accept_TC();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Accept_TC_lock(_ProjectionRead_Accept_TC_mutex);
                                    _OpCache_with_parameter_Accept_TC.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Accept_TC";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                obsw_M001_2::_ProjectionRead__tr_Reject_TC read__tr_Reject_TC_state = state._projected_state_for__tr_Reject_TC();
                auto _trid_4_ptr = _OpCache_tr_Reject_TC.find(read__tr_Reject_TC_state);
                if(_trid_4_ptr == _OpCache_tr_Reject_TC.end()) {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_4 = state._tr_Reject_TC();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_Reject_TC_lock(_ProjectionRead__tr_Reject_TC_mutex);
                        _OpCache_tr_Reject_TC.insert({read__tr_Reject_TC_state, _trid_4});
                    }
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_4) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Reject_TC readState = state._projected_state_for_Reject_TC();

                        auto _OpCache_with_parameter_Reject_TC_ptr = _OpCache_Reject_TC.find(param);
                        if(_OpCache_with_parameter_Reject_TC_ptr == _OpCache_Reject_TC.end()) {
                            copiedState.Reject_TC(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Reject_TC writeState = copiedState._update_for_Reject_TC();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Reject_TC, obsw_M001_2::_ProjectionWrite_Reject_TC, obsw_M001_2::_ProjectionRead_Reject_TC::Hash, obsw_M001_2::_ProjectionRead_Reject_TC::HashEqual> _OpCache_with_parameter_Reject_TC;
                            _OpCache_with_parameter_Reject_TC.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Reject_TC_lock(_ProjectionRead_Reject_TC_mutex);
                                _OpCache_Reject_TC.insert({param, _OpCache_with_parameter_Reject_TC});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Reject_TC, obsw_M001_2::_ProjectionWrite_Reject_TC, obsw_M001_2::_ProjectionRead_Reject_TC::Hash, obsw_M001_2::_ProjectionRead_Reject_TC::HashEqual> _OpCache_with_parameter_Reject_TC = _OpCache_with_parameter_Reject_TC_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Reject_TC.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Reject_TC.end()) {
                                obsw_M001_2::_ProjectionWrite_Reject_TC writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Reject_TC(writeState);
                            } else {
                                copiedState.Reject_TC(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Reject_TC writeState = copiedState._update_for_Reject_TC();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Reject_TC_lock(_ProjectionRead_Reject_TC_mutex);
                                    _OpCache_with_parameter_Reject_TC.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Reject_TC";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_4 = _trid_4_ptr->second;
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_4) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Reject_TC readState = state._projected_state_for_Reject_TC();

                        auto _OpCache_with_parameter_Reject_TC_ptr = _OpCache_Reject_TC.find(param);
                        if(_OpCache_with_parameter_Reject_TC_ptr == _OpCache_Reject_TC.end()) {
                            copiedState.Reject_TC(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Reject_TC writeState = copiedState._update_for_Reject_TC();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Reject_TC, obsw_M001_2::_ProjectionWrite_Reject_TC, obsw_M001_2::_ProjectionRead_Reject_TC::Hash, obsw_M001_2::_ProjectionRead_Reject_TC::HashEqual> _OpCache_with_parameter_Reject_TC;
                            _OpCache_with_parameter_Reject_TC.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Reject_TC_lock(_ProjectionRead_Reject_TC_mutex);
                                _OpCache_Reject_TC.insert({param, _OpCache_with_parameter_Reject_TC});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Reject_TC, obsw_M001_2::_ProjectionWrite_Reject_TC, obsw_M001_2::_ProjectionRead_Reject_TC::Hash, obsw_M001_2::_ProjectionRead_Reject_TC::HashEqual> _OpCache_with_parameter_Reject_TC = _OpCache_with_parameter_Reject_TC_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Reject_TC.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Reject_TC.end()) {
                                obsw_M001_2::_ProjectionWrite_Reject_TC writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Reject_TC(writeState);
                            } else {
                                copiedState.Reject_TC(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Reject_TC writeState = copiedState._update_for_Reject_TC();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Reject_TC_lock(_ProjectionRead_Reject_TC_mutex);
                                    _OpCache_with_parameter_Reject_TC.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Reject_TC";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                obsw_M001_2::_ProjectionRead__tr_Report_TC_Acceptance read__tr_Report_TC_Acceptance_state = state._projected_state_for__tr_Report_TC_Acceptance();
                auto _trid_5_ptr = _OpCache_tr_Report_TC_Acceptance.find(read__tr_Report_TC_Acceptance_state);
                if(_trid_5_ptr == _OpCache_tr_Report_TC_Acceptance.end()) {
                    BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >> _trid_5 = state._tr_Report_TC_Acceptance();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_Report_TC_Acceptance_lock(_ProjectionRead__tr_Report_TC_Acceptance_mutex);
                        _OpCache_tr_Report_TC_Acceptance.insert({read__tr_Report_TC_Acceptance_state, _trid_5});
                    }
                    for(const BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >& param : _trid_5) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                        BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET > _tmp_2 = param.projection1();
                        obsw_M001_2::TM_SET _tmp_3 = _tmp_2.projection2();
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_4 = _tmp_2.projection1();

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Report_TC_Acceptance readState = state._projected_state_for_Report_TC_Acceptance();

                        auto _OpCache_with_parameter_Report_TC_Acceptance_ptr = _OpCache_Report_TC_Acceptance.find(param);
                        if(_OpCache_with_parameter_Report_TC_Acceptance_ptr == _OpCache_Report_TC_Acceptance.end()) {
                            copiedState.Report_TC_Acceptance(_tmp_4, _tmp_3, _tmp_1);
                            obsw_M001_2::_ProjectionWrite_Report_TC_Acceptance writeState = copiedState._update_for_Report_TC_Acceptance();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Report_TC_Acceptance, obsw_M001_2::_ProjectionWrite_Report_TC_Acceptance, obsw_M001_2::_ProjectionRead_Report_TC_Acceptance::Hash, obsw_M001_2::_ProjectionRead_Report_TC_Acceptance::HashEqual> _OpCache_with_parameter_Report_TC_Acceptance;
                            _OpCache_with_parameter_Report_TC_Acceptance.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Report_TC_Acceptance_lock(_ProjectionRead_Report_TC_Acceptance_mutex);
                                _OpCache_Report_TC_Acceptance.insert({param, _OpCache_with_parameter_Report_TC_Acceptance});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Report_TC_Acceptance, obsw_M001_2::_ProjectionWrite_Report_TC_Acceptance, obsw_M001_2::_ProjectionRead_Report_TC_Acceptance::Hash, obsw_M001_2::_ProjectionRead_Report_TC_Acceptance::HashEqual> _OpCache_with_parameter_Report_TC_Acceptance = _OpCache_with_parameter_Report_TC_Acceptance_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Report_TC_Acceptance.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Report_TC_Acceptance.end()) {
                                obsw_M001_2::_ProjectionWrite_Report_TC_Acceptance writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Report_TC_Acceptance(writeState);
                            } else {
                                copiedState.Report_TC_Acceptance(_tmp_4, _tmp_3, _tmp_1);
                                obsw_M001_2::_ProjectionWrite_Report_TC_Acceptance writeState = copiedState._update_for_Report_TC_Acceptance();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Report_TC_Acceptance_lock(_ProjectionRead_Report_TC_Acceptance_mutex);
                                    _OpCache_with_parameter_Report_TC_Acceptance.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Report_TC_Acceptance";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >> _trid_5 = _trid_5_ptr->second;
                    for(const BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >& param : _trid_5) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                        BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET > _tmp_2 = param.projection1();
                        obsw_M001_2::TM_SET _tmp_3 = _tmp_2.projection2();
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_4 = _tmp_2.projection1();

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Report_TC_Acceptance readState = state._projected_state_for_Report_TC_Acceptance();

                        auto _OpCache_with_parameter_Report_TC_Acceptance_ptr = _OpCache_Report_TC_Acceptance.find(param);
                        if(_OpCache_with_parameter_Report_TC_Acceptance_ptr == _OpCache_Report_TC_Acceptance.end()) {
                            copiedState.Report_TC_Acceptance(_tmp_4, _tmp_3, _tmp_1);
                            obsw_M001_2::_ProjectionWrite_Report_TC_Acceptance writeState = copiedState._update_for_Report_TC_Acceptance();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Report_TC_Acceptance, obsw_M001_2::_ProjectionWrite_Report_TC_Acceptance, obsw_M001_2::_ProjectionRead_Report_TC_Acceptance::Hash, obsw_M001_2::_ProjectionRead_Report_TC_Acceptance::HashEqual> _OpCache_with_parameter_Report_TC_Acceptance;
                            _OpCache_with_parameter_Report_TC_Acceptance.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Report_TC_Acceptance_lock(_ProjectionRead_Report_TC_Acceptance_mutex);
                                _OpCache_Report_TC_Acceptance.insert({param, _OpCache_with_parameter_Report_TC_Acceptance});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Report_TC_Acceptance, obsw_M001_2::_ProjectionWrite_Report_TC_Acceptance, obsw_M001_2::_ProjectionRead_Report_TC_Acceptance::Hash, obsw_M001_2::_ProjectionRead_Report_TC_Acceptance::HashEqual> _OpCache_with_parameter_Report_TC_Acceptance = _OpCache_with_parameter_Report_TC_Acceptance_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Report_TC_Acceptance.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Report_TC_Acceptance.end()) {
                                obsw_M001_2::_ProjectionWrite_Report_TC_Acceptance writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Report_TC_Acceptance(writeState);
                            } else {
                                copiedState.Report_TC_Acceptance(_tmp_4, _tmp_3, _tmp_1);
                                obsw_M001_2::_ProjectionWrite_Report_TC_Acceptance writeState = copiedState._update_for_Report_TC_Acceptance();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Report_TC_Acceptance_lock(_ProjectionRead_Report_TC_Acceptance_mutex);
                                    _OpCache_with_parameter_Report_TC_Acceptance.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Report_TC_Acceptance";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                obsw_M001_2::_ProjectionRead__tr_Skip_TC_Acceptance_Report read__tr_Skip_TC_Acceptance_Report_state = state._projected_state_for__tr_Skip_TC_Acceptance_Report();
                auto _trid_6_ptr = _OpCache_tr_Skip_TC_Acceptance_Report.find(read__tr_Skip_TC_Acceptance_Report_state);
                if(_trid_6_ptr == _OpCache_tr_Skip_TC_Acceptance_Report.end()) {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_6 = state._tr_Skip_TC_Acceptance_Report();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_Skip_TC_Acceptance_Report_lock(_ProjectionRead__tr_Skip_TC_Acceptance_Report_mutex);
                        _OpCache_tr_Skip_TC_Acceptance_Report.insert({read__tr_Skip_TC_Acceptance_Report_state, _trid_6});
                    }
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_6) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Skip_TC_Acceptance_Report readState = state._projected_state_for_Skip_TC_Acceptance_Report();

                        auto _OpCache_with_parameter_Skip_TC_Acceptance_Report_ptr = _OpCache_Skip_TC_Acceptance_Report.find(param);
                        if(_OpCache_with_parameter_Skip_TC_Acceptance_Report_ptr == _OpCache_Skip_TC_Acceptance_Report.end()) {
                            copiedState.Skip_TC_Acceptance_Report(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Skip_TC_Acceptance_Report writeState = copiedState._update_for_Skip_TC_Acceptance_Report();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Skip_TC_Acceptance_Report, obsw_M001_2::_ProjectionWrite_Skip_TC_Acceptance_Report, obsw_M001_2::_ProjectionRead_Skip_TC_Acceptance_Report::Hash, obsw_M001_2::_ProjectionRead_Skip_TC_Acceptance_Report::HashEqual> _OpCache_with_parameter_Skip_TC_Acceptance_Report;
                            _OpCache_with_parameter_Skip_TC_Acceptance_Report.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Skip_TC_Acceptance_Report_lock(_ProjectionRead_Skip_TC_Acceptance_Report_mutex);
                                _OpCache_Skip_TC_Acceptance_Report.insert({param, _OpCache_with_parameter_Skip_TC_Acceptance_Report});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Skip_TC_Acceptance_Report, obsw_M001_2::_ProjectionWrite_Skip_TC_Acceptance_Report, obsw_M001_2::_ProjectionRead_Skip_TC_Acceptance_Report::Hash, obsw_M001_2::_ProjectionRead_Skip_TC_Acceptance_Report::HashEqual> _OpCache_with_parameter_Skip_TC_Acceptance_Report = _OpCache_with_parameter_Skip_TC_Acceptance_Report_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Skip_TC_Acceptance_Report.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Skip_TC_Acceptance_Report.end()) {
                                obsw_M001_2::_ProjectionWrite_Skip_TC_Acceptance_Report writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Skip_TC_Acceptance_Report(writeState);
                            } else {
                                copiedState.Skip_TC_Acceptance_Report(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Skip_TC_Acceptance_Report writeState = copiedState._update_for_Skip_TC_Acceptance_Report();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Skip_TC_Acceptance_Report_lock(_ProjectionRead_Skip_TC_Acceptance_Report_mutex);
                                    _OpCache_with_parameter_Skip_TC_Acceptance_Report.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Skip_TC_Acceptance_Report";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_6 = _trid_6_ptr->second;
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_6) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Skip_TC_Acceptance_Report readState = state._projected_state_for_Skip_TC_Acceptance_Report();

                        auto _OpCache_with_parameter_Skip_TC_Acceptance_Report_ptr = _OpCache_Skip_TC_Acceptance_Report.find(param);
                        if(_OpCache_with_parameter_Skip_TC_Acceptance_Report_ptr == _OpCache_Skip_TC_Acceptance_Report.end()) {
                            copiedState.Skip_TC_Acceptance_Report(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Skip_TC_Acceptance_Report writeState = copiedState._update_for_Skip_TC_Acceptance_Report();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Skip_TC_Acceptance_Report, obsw_M001_2::_ProjectionWrite_Skip_TC_Acceptance_Report, obsw_M001_2::_ProjectionRead_Skip_TC_Acceptance_Report::Hash, obsw_M001_2::_ProjectionRead_Skip_TC_Acceptance_Report::HashEqual> _OpCache_with_parameter_Skip_TC_Acceptance_Report;
                            _OpCache_with_parameter_Skip_TC_Acceptance_Report.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Skip_TC_Acceptance_Report_lock(_ProjectionRead_Skip_TC_Acceptance_Report_mutex);
                                _OpCache_Skip_TC_Acceptance_Report.insert({param, _OpCache_with_parameter_Skip_TC_Acceptance_Report});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Skip_TC_Acceptance_Report, obsw_M001_2::_ProjectionWrite_Skip_TC_Acceptance_Report, obsw_M001_2::_ProjectionRead_Skip_TC_Acceptance_Report::Hash, obsw_M001_2::_ProjectionRead_Skip_TC_Acceptance_Report::HashEqual> _OpCache_with_parameter_Skip_TC_Acceptance_Report = _OpCache_with_parameter_Skip_TC_Acceptance_Report_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Skip_TC_Acceptance_Report.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Skip_TC_Acceptance_Report.end()) {
                                obsw_M001_2::_ProjectionWrite_Skip_TC_Acceptance_Report writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Skip_TC_Acceptance_Report(writeState);
                            } else {
                                copiedState.Skip_TC_Acceptance_Report(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Skip_TC_Acceptance_Report writeState = copiedState._update_for_Skip_TC_Acceptance_Report();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Skip_TC_Acceptance_Report_lock(_ProjectionRead_Skip_TC_Acceptance_Report_mutex);
                                    _OpCache_with_parameter_Skip_TC_Acceptance_Report.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Skip_TC_Acceptance_Report";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                obsw_M001_2::_ProjectionRead__tr_Report_TC_Rejection read__tr_Report_TC_Rejection_state = state._projected_state_for__tr_Report_TC_Rejection();
                auto _trid_7_ptr = _OpCache_tr_Report_TC_Rejection.find(read__tr_Report_TC_Rejection_state);
                if(_trid_7_ptr == _OpCache_tr_Report_TC_Rejection.end()) {
                    BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >> _trid_7 = state._tr_Report_TC_Rejection();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_Report_TC_Rejection_lock(_ProjectionRead__tr_Report_TC_Rejection_mutex);
                        _OpCache_tr_Report_TC_Rejection.insert({read__tr_Report_TC_Rejection_state, _trid_7});
                    }
                    for(const BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >& param : _trid_7) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                        BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET > _tmp_2 = param.projection1();
                        obsw_M001_2::TM_SET _tmp_3 = _tmp_2.projection2();
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_4 = _tmp_2.projection1();

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Report_TC_Rejection readState = state._projected_state_for_Report_TC_Rejection();

                        auto _OpCache_with_parameter_Report_TC_Rejection_ptr = _OpCache_Report_TC_Rejection.find(param);
                        if(_OpCache_with_parameter_Report_TC_Rejection_ptr == _OpCache_Report_TC_Rejection.end()) {
                            copiedState.Report_TC_Rejection(_tmp_4, _tmp_3, _tmp_1);
                            obsw_M001_2::_ProjectionWrite_Report_TC_Rejection writeState = copiedState._update_for_Report_TC_Rejection();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Report_TC_Rejection, obsw_M001_2::_ProjectionWrite_Report_TC_Rejection, obsw_M001_2::_ProjectionRead_Report_TC_Rejection::Hash, obsw_M001_2::_ProjectionRead_Report_TC_Rejection::HashEqual> _OpCache_with_parameter_Report_TC_Rejection;
                            _OpCache_with_parameter_Report_TC_Rejection.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Report_TC_Rejection_lock(_ProjectionRead_Report_TC_Rejection_mutex);
                                _OpCache_Report_TC_Rejection.insert({param, _OpCache_with_parameter_Report_TC_Rejection});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Report_TC_Rejection, obsw_M001_2::_ProjectionWrite_Report_TC_Rejection, obsw_M001_2::_ProjectionRead_Report_TC_Rejection::Hash, obsw_M001_2::_ProjectionRead_Report_TC_Rejection::HashEqual> _OpCache_with_parameter_Report_TC_Rejection = _OpCache_with_parameter_Report_TC_Rejection_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Report_TC_Rejection.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Report_TC_Rejection.end()) {
                                obsw_M001_2::_ProjectionWrite_Report_TC_Rejection writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Report_TC_Rejection(writeState);
                            } else {
                                copiedState.Report_TC_Rejection(_tmp_4, _tmp_3, _tmp_1);
                                obsw_M001_2::_ProjectionWrite_Report_TC_Rejection writeState = copiedState._update_for_Report_TC_Rejection();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Report_TC_Rejection_lock(_ProjectionRead_Report_TC_Rejection_mutex);
                                    _OpCache_with_parameter_Report_TC_Rejection.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Report_TC_Rejection";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >> _trid_7 = _trid_7_ptr->second;
                    for(const BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >& param : _trid_7) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                        BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET > _tmp_2 = param.projection1();
                        obsw_M001_2::TM_SET _tmp_3 = _tmp_2.projection2();
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_4 = _tmp_2.projection1();

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Report_TC_Rejection readState = state._projected_state_for_Report_TC_Rejection();

                        auto _OpCache_with_parameter_Report_TC_Rejection_ptr = _OpCache_Report_TC_Rejection.find(param);
                        if(_OpCache_with_parameter_Report_TC_Rejection_ptr == _OpCache_Report_TC_Rejection.end()) {
                            copiedState.Report_TC_Rejection(_tmp_4, _tmp_3, _tmp_1);
                            obsw_M001_2::_ProjectionWrite_Report_TC_Rejection writeState = copiedState._update_for_Report_TC_Rejection();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Report_TC_Rejection, obsw_M001_2::_ProjectionWrite_Report_TC_Rejection, obsw_M001_2::_ProjectionRead_Report_TC_Rejection::Hash, obsw_M001_2::_ProjectionRead_Report_TC_Rejection::HashEqual> _OpCache_with_parameter_Report_TC_Rejection;
                            _OpCache_with_parameter_Report_TC_Rejection.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Report_TC_Rejection_lock(_ProjectionRead_Report_TC_Rejection_mutex);
                                _OpCache_Report_TC_Rejection.insert({param, _OpCache_with_parameter_Report_TC_Rejection});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Report_TC_Rejection, obsw_M001_2::_ProjectionWrite_Report_TC_Rejection, obsw_M001_2::_ProjectionRead_Report_TC_Rejection::Hash, obsw_M001_2::_ProjectionRead_Report_TC_Rejection::HashEqual> _OpCache_with_parameter_Report_TC_Rejection = _OpCache_with_parameter_Report_TC_Rejection_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Report_TC_Rejection.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Report_TC_Rejection.end()) {
                                obsw_M001_2::_ProjectionWrite_Report_TC_Rejection writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Report_TC_Rejection(writeState);
                            } else {
                                copiedState.Report_TC_Rejection(_tmp_4, _tmp_3, _tmp_1);
                                obsw_M001_2::_ProjectionWrite_Report_TC_Rejection writeState = copiedState._update_for_Report_TC_Rejection();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Report_TC_Rejection_lock(_ProjectionRead_Report_TC_Rejection_mutex);
                                    _OpCache_with_parameter_Report_TC_Rejection.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Report_TC_Rejection";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                obsw_M001_2::_ProjectionRead__tr_Skip_TC_Rejection_Report read__tr_Skip_TC_Rejection_Report_state = state._projected_state_for__tr_Skip_TC_Rejection_Report();
                auto _trid_8_ptr = _OpCache_tr_Skip_TC_Rejection_Report.find(read__tr_Skip_TC_Rejection_Report_state);
                if(_trid_8_ptr == _OpCache_tr_Skip_TC_Rejection_Report.end()) {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_8 = state._tr_Skip_TC_Rejection_Report();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_Skip_TC_Rejection_Report_lock(_ProjectionRead__tr_Skip_TC_Rejection_Report_mutex);
                        _OpCache_tr_Skip_TC_Rejection_Report.insert({read__tr_Skip_TC_Rejection_Report_state, _trid_8});
                    }
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_8) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Skip_TC_Rejection_Report readState = state._projected_state_for_Skip_TC_Rejection_Report();

                        auto _OpCache_with_parameter_Skip_TC_Rejection_Report_ptr = _OpCache_Skip_TC_Rejection_Report.find(param);
                        if(_OpCache_with_parameter_Skip_TC_Rejection_Report_ptr == _OpCache_Skip_TC_Rejection_Report.end()) {
                            copiedState.Skip_TC_Rejection_Report(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Skip_TC_Rejection_Report writeState = copiedState._update_for_Skip_TC_Rejection_Report();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Skip_TC_Rejection_Report, obsw_M001_2::_ProjectionWrite_Skip_TC_Rejection_Report, obsw_M001_2::_ProjectionRead_Skip_TC_Rejection_Report::Hash, obsw_M001_2::_ProjectionRead_Skip_TC_Rejection_Report::HashEqual> _OpCache_with_parameter_Skip_TC_Rejection_Report;
                            _OpCache_with_parameter_Skip_TC_Rejection_Report.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Skip_TC_Rejection_Report_lock(_ProjectionRead_Skip_TC_Rejection_Report_mutex);
                                _OpCache_Skip_TC_Rejection_Report.insert({param, _OpCache_with_parameter_Skip_TC_Rejection_Report});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Skip_TC_Rejection_Report, obsw_M001_2::_ProjectionWrite_Skip_TC_Rejection_Report, obsw_M001_2::_ProjectionRead_Skip_TC_Rejection_Report::Hash, obsw_M001_2::_ProjectionRead_Skip_TC_Rejection_Report::HashEqual> _OpCache_with_parameter_Skip_TC_Rejection_Report = _OpCache_with_parameter_Skip_TC_Rejection_Report_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Skip_TC_Rejection_Report.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Skip_TC_Rejection_Report.end()) {
                                obsw_M001_2::_ProjectionWrite_Skip_TC_Rejection_Report writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Skip_TC_Rejection_Report(writeState);
                            } else {
                                copiedState.Skip_TC_Rejection_Report(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Skip_TC_Rejection_Report writeState = copiedState._update_for_Skip_TC_Rejection_Report();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Skip_TC_Rejection_Report_lock(_ProjectionRead_Skip_TC_Rejection_Report_mutex);
                                    _OpCache_with_parameter_Skip_TC_Rejection_Report.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Skip_TC_Rejection_Report";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_8 = _trid_8_ptr->second;
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_8) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Skip_TC_Rejection_Report readState = state._projected_state_for_Skip_TC_Rejection_Report();

                        auto _OpCache_with_parameter_Skip_TC_Rejection_Report_ptr = _OpCache_Skip_TC_Rejection_Report.find(param);
                        if(_OpCache_with_parameter_Skip_TC_Rejection_Report_ptr == _OpCache_Skip_TC_Rejection_Report.end()) {
                            copiedState.Skip_TC_Rejection_Report(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Skip_TC_Rejection_Report writeState = copiedState._update_for_Skip_TC_Rejection_Report();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Skip_TC_Rejection_Report, obsw_M001_2::_ProjectionWrite_Skip_TC_Rejection_Report, obsw_M001_2::_ProjectionRead_Skip_TC_Rejection_Report::Hash, obsw_M001_2::_ProjectionRead_Skip_TC_Rejection_Report::HashEqual> _OpCache_with_parameter_Skip_TC_Rejection_Report;
                            _OpCache_with_parameter_Skip_TC_Rejection_Report.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Skip_TC_Rejection_Report_lock(_ProjectionRead_Skip_TC_Rejection_Report_mutex);
                                _OpCache_Skip_TC_Rejection_Report.insert({param, _OpCache_with_parameter_Skip_TC_Rejection_Report});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Skip_TC_Rejection_Report, obsw_M001_2::_ProjectionWrite_Skip_TC_Rejection_Report, obsw_M001_2::_ProjectionRead_Skip_TC_Rejection_Report::Hash, obsw_M001_2::_ProjectionRead_Skip_TC_Rejection_Report::HashEqual> _OpCache_with_parameter_Skip_TC_Rejection_Report = _OpCache_with_parameter_Skip_TC_Rejection_Report_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Skip_TC_Rejection_Report.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Skip_TC_Rejection_Report.end()) {
                                obsw_M001_2::_ProjectionWrite_Skip_TC_Rejection_Report writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Skip_TC_Rejection_Report(writeState);
                            } else {
                                copiedState.Skip_TC_Rejection_Report(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Skip_TC_Rejection_Report writeState = copiedState._update_for_Skip_TC_Rejection_Report();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Skip_TC_Rejection_Report_lock(_ProjectionRead_Skip_TC_Rejection_Report_mutex);
                                    _OpCache_with_parameter_Skip_TC_Rejection_Report.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Skip_TC_Rejection_Report";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                obsw_M001_2::_ProjectionRead__tr_Execute_TC_Successfully read__tr_Execute_TC_Successfully_state = state._projected_state_for__tr_Execute_TC_Successfully();
                auto _trid_9_ptr = _OpCache_tr_Execute_TC_Successfully.find(read__tr_Execute_TC_Successfully_state);
                if(_trid_9_ptr == _OpCache_tr_Execute_TC_Successfully.end()) {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_9 = state._tr_Execute_TC_Successfully();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_Execute_TC_Successfully_lock(_ProjectionRead__tr_Execute_TC_Successfully_mutex);
                        _OpCache_tr_Execute_TC_Successfully.insert({read__tr_Execute_TC_Successfully_state, _trid_9});
                    }
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_9) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Execute_TC_Successfully readState = state._projected_state_for_Execute_TC_Successfully();

                        auto _OpCache_with_parameter_Execute_TC_Successfully_ptr = _OpCache_Execute_TC_Successfully.find(param);
                        if(_OpCache_with_parameter_Execute_TC_Successfully_ptr == _OpCache_Execute_TC_Successfully.end()) {
                            copiedState.Execute_TC_Successfully(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Execute_TC_Successfully writeState = copiedState._update_for_Execute_TC_Successfully();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Execute_TC_Successfully, obsw_M001_2::_ProjectionWrite_Execute_TC_Successfully, obsw_M001_2::_ProjectionRead_Execute_TC_Successfully::Hash, obsw_M001_2::_ProjectionRead_Execute_TC_Successfully::HashEqual> _OpCache_with_parameter_Execute_TC_Successfully;
                            _OpCache_with_parameter_Execute_TC_Successfully.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Execute_TC_Successfully_lock(_ProjectionRead_Execute_TC_Successfully_mutex);
                                _OpCache_Execute_TC_Successfully.insert({param, _OpCache_with_parameter_Execute_TC_Successfully});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Execute_TC_Successfully, obsw_M001_2::_ProjectionWrite_Execute_TC_Successfully, obsw_M001_2::_ProjectionRead_Execute_TC_Successfully::Hash, obsw_M001_2::_ProjectionRead_Execute_TC_Successfully::HashEqual> _OpCache_with_parameter_Execute_TC_Successfully = _OpCache_with_parameter_Execute_TC_Successfully_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Execute_TC_Successfully.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Execute_TC_Successfully.end()) {
                                obsw_M001_2::_ProjectionWrite_Execute_TC_Successfully writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Execute_TC_Successfully(writeState);
                            } else {
                                copiedState.Execute_TC_Successfully(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Execute_TC_Successfully writeState = copiedState._update_for_Execute_TC_Successfully();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Execute_TC_Successfully_lock(_ProjectionRead_Execute_TC_Successfully_mutex);
                                    _OpCache_with_parameter_Execute_TC_Successfully.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Execute_TC_Successfully";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_9 = _trid_9_ptr->second;
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_9) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Execute_TC_Successfully readState = state._projected_state_for_Execute_TC_Successfully();

                        auto _OpCache_with_parameter_Execute_TC_Successfully_ptr = _OpCache_Execute_TC_Successfully.find(param);
                        if(_OpCache_with_parameter_Execute_TC_Successfully_ptr == _OpCache_Execute_TC_Successfully.end()) {
                            copiedState.Execute_TC_Successfully(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Execute_TC_Successfully writeState = copiedState._update_for_Execute_TC_Successfully();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Execute_TC_Successfully, obsw_M001_2::_ProjectionWrite_Execute_TC_Successfully, obsw_M001_2::_ProjectionRead_Execute_TC_Successfully::Hash, obsw_M001_2::_ProjectionRead_Execute_TC_Successfully::HashEqual> _OpCache_with_parameter_Execute_TC_Successfully;
                            _OpCache_with_parameter_Execute_TC_Successfully.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Execute_TC_Successfully_lock(_ProjectionRead_Execute_TC_Successfully_mutex);
                                _OpCache_Execute_TC_Successfully.insert({param, _OpCache_with_parameter_Execute_TC_Successfully});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Execute_TC_Successfully, obsw_M001_2::_ProjectionWrite_Execute_TC_Successfully, obsw_M001_2::_ProjectionRead_Execute_TC_Successfully::Hash, obsw_M001_2::_ProjectionRead_Execute_TC_Successfully::HashEqual> _OpCache_with_parameter_Execute_TC_Successfully = _OpCache_with_parameter_Execute_TC_Successfully_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Execute_TC_Successfully.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Execute_TC_Successfully.end()) {
                                obsw_M001_2::_ProjectionWrite_Execute_TC_Successfully writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Execute_TC_Successfully(writeState);
                            } else {
                                copiedState.Execute_TC_Successfully(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Execute_TC_Successfully writeState = copiedState._update_for_Execute_TC_Successfully();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Execute_TC_Successfully_lock(_ProjectionRead_Execute_TC_Successfully_mutex);
                                    _OpCache_with_parameter_Execute_TC_Successfully.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Execute_TC_Successfully";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                obsw_M001_2::_ProjectionRead__tr_Reset_TM_Buffer read__tr_Reset_TM_Buffer_state = state._projected_state_for__tr_Reset_TM_Buffer();
                auto _trid_10_ptr = _OpCache_tr_Reset_TM_Buffer.find(read__tr_Reset_TM_Buffer_state);
                if(_trid_10_ptr == _OpCache_tr_Reset_TM_Buffer.end()) {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_10 = state._tr_Reset_TM_Buffer();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_Reset_TM_Buffer_lock(_ProjectionRead__tr_Reset_TM_Buffer_mutex);
                        _OpCache_tr_Reset_TM_Buffer.insert({read__tr_Reset_TM_Buffer_state, _trid_10});
                    }
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_10) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Reset_TM_Buffer readState = state._projected_state_for_Reset_TM_Buffer();

                        auto _OpCache_with_parameter_Reset_TM_Buffer_ptr = _OpCache_Reset_TM_Buffer.find(param);
                        if(_OpCache_with_parameter_Reset_TM_Buffer_ptr == _OpCache_Reset_TM_Buffer.end()) {
                            copiedState.Reset_TM_Buffer(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Reset_TM_Buffer writeState = copiedState._update_for_Reset_TM_Buffer();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Reset_TM_Buffer, obsw_M001_2::_ProjectionWrite_Reset_TM_Buffer, obsw_M001_2::_ProjectionRead_Reset_TM_Buffer::Hash, obsw_M001_2::_ProjectionRead_Reset_TM_Buffer::HashEqual> _OpCache_with_parameter_Reset_TM_Buffer;
                            _OpCache_with_parameter_Reset_TM_Buffer.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Reset_TM_Buffer_lock(_ProjectionRead_Reset_TM_Buffer_mutex);
                                _OpCache_Reset_TM_Buffer.insert({param, _OpCache_with_parameter_Reset_TM_Buffer});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Reset_TM_Buffer, obsw_M001_2::_ProjectionWrite_Reset_TM_Buffer, obsw_M001_2::_ProjectionRead_Reset_TM_Buffer::Hash, obsw_M001_2::_ProjectionRead_Reset_TM_Buffer::HashEqual> _OpCache_with_parameter_Reset_TM_Buffer = _OpCache_with_parameter_Reset_TM_Buffer_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Reset_TM_Buffer.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Reset_TM_Buffer.end()) {
                                obsw_M001_2::_ProjectionWrite_Reset_TM_Buffer writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Reset_TM_Buffer(writeState);
                            } else {
                                copiedState.Reset_TM_Buffer(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Reset_TM_Buffer writeState = copiedState._update_for_Reset_TM_Buffer();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Reset_TM_Buffer_lock(_ProjectionRead_Reset_TM_Buffer_mutex);
                                    _OpCache_with_parameter_Reset_TM_Buffer.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Reset_TM_Buffer";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_10 = _trid_10_ptr->second;
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_10) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Reset_TM_Buffer readState = state._projected_state_for_Reset_TM_Buffer();

                        auto _OpCache_with_parameter_Reset_TM_Buffer_ptr = _OpCache_Reset_TM_Buffer.find(param);
                        if(_OpCache_with_parameter_Reset_TM_Buffer_ptr == _OpCache_Reset_TM_Buffer.end()) {
                            copiedState.Reset_TM_Buffer(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Reset_TM_Buffer writeState = copiedState._update_for_Reset_TM_Buffer();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Reset_TM_Buffer, obsw_M001_2::_ProjectionWrite_Reset_TM_Buffer, obsw_M001_2::_ProjectionRead_Reset_TM_Buffer::Hash, obsw_M001_2::_ProjectionRead_Reset_TM_Buffer::HashEqual> _OpCache_with_parameter_Reset_TM_Buffer;
                            _OpCache_with_parameter_Reset_TM_Buffer.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Reset_TM_Buffer_lock(_ProjectionRead_Reset_TM_Buffer_mutex);
                                _OpCache_Reset_TM_Buffer.insert({param, _OpCache_with_parameter_Reset_TM_Buffer});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Reset_TM_Buffer, obsw_M001_2::_ProjectionWrite_Reset_TM_Buffer, obsw_M001_2::_ProjectionRead_Reset_TM_Buffer::Hash, obsw_M001_2::_ProjectionRead_Reset_TM_Buffer::HashEqual> _OpCache_with_parameter_Reset_TM_Buffer = _OpCache_with_parameter_Reset_TM_Buffer_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Reset_TM_Buffer.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Reset_TM_Buffer.end()) {
                                obsw_M001_2::_ProjectionWrite_Reset_TM_Buffer writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Reset_TM_Buffer(writeState);
                            } else {
                                copiedState.Reset_TM_Buffer(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Reset_TM_Buffer writeState = copiedState._update_for_Reset_TM_Buffer();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Reset_TM_Buffer_lock(_ProjectionRead_Reset_TM_Buffer_mutex);
                                    _OpCache_with_parameter_Reset_TM_Buffer.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Reset_TM_Buffer";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                obsw_M001_2::_ProjectionRead__tr_Fail_TC_Execution read__tr_Fail_TC_Execution_state = state._projected_state_for__tr_Fail_TC_Execution();
                auto _trid_11_ptr = _OpCache_tr_Fail_TC_Execution.find(read__tr_Fail_TC_Execution_state);
                if(_trid_11_ptr == _OpCache_tr_Fail_TC_Execution.end()) {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_11 = state._tr_Fail_TC_Execution();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_Fail_TC_Execution_lock(_ProjectionRead__tr_Fail_TC_Execution_mutex);
                        _OpCache_tr_Fail_TC_Execution.insert({read__tr_Fail_TC_Execution_state, _trid_11});
                    }
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_11) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Fail_TC_Execution readState = state._projected_state_for_Fail_TC_Execution();

                        auto _OpCache_with_parameter_Fail_TC_Execution_ptr = _OpCache_Fail_TC_Execution.find(param);
                        if(_OpCache_with_parameter_Fail_TC_Execution_ptr == _OpCache_Fail_TC_Execution.end()) {
                            copiedState.Fail_TC_Execution(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Fail_TC_Execution writeState = copiedState._update_for_Fail_TC_Execution();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Fail_TC_Execution, obsw_M001_2::_ProjectionWrite_Fail_TC_Execution, obsw_M001_2::_ProjectionRead_Fail_TC_Execution::Hash, obsw_M001_2::_ProjectionRead_Fail_TC_Execution::HashEqual> _OpCache_with_parameter_Fail_TC_Execution;
                            _OpCache_with_parameter_Fail_TC_Execution.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Fail_TC_Execution_lock(_ProjectionRead_Fail_TC_Execution_mutex);
                                _OpCache_Fail_TC_Execution.insert({param, _OpCache_with_parameter_Fail_TC_Execution});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Fail_TC_Execution, obsw_M001_2::_ProjectionWrite_Fail_TC_Execution, obsw_M001_2::_ProjectionRead_Fail_TC_Execution::Hash, obsw_M001_2::_ProjectionRead_Fail_TC_Execution::HashEqual> _OpCache_with_parameter_Fail_TC_Execution = _OpCache_with_parameter_Fail_TC_Execution_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Fail_TC_Execution.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Fail_TC_Execution.end()) {
                                obsw_M001_2::_ProjectionWrite_Fail_TC_Execution writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Fail_TC_Execution(writeState);
                            } else {
                                copiedState.Fail_TC_Execution(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Fail_TC_Execution writeState = copiedState._update_for_Fail_TC_Execution();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Fail_TC_Execution_lock(_ProjectionRead_Fail_TC_Execution_mutex);
                                    _OpCache_with_parameter_Fail_TC_Execution.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Fail_TC_Execution";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_11 = _trid_11_ptr->second;
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_11) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Fail_TC_Execution readState = state._projected_state_for_Fail_TC_Execution();

                        auto _OpCache_with_parameter_Fail_TC_Execution_ptr = _OpCache_Fail_TC_Execution.find(param);
                        if(_OpCache_with_parameter_Fail_TC_Execution_ptr == _OpCache_Fail_TC_Execution.end()) {
                            copiedState.Fail_TC_Execution(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Fail_TC_Execution writeState = copiedState._update_for_Fail_TC_Execution();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Fail_TC_Execution, obsw_M001_2::_ProjectionWrite_Fail_TC_Execution, obsw_M001_2::_ProjectionRead_Fail_TC_Execution::Hash, obsw_M001_2::_ProjectionRead_Fail_TC_Execution::HashEqual> _OpCache_with_parameter_Fail_TC_Execution;
                            _OpCache_with_parameter_Fail_TC_Execution.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Fail_TC_Execution_lock(_ProjectionRead_Fail_TC_Execution_mutex);
                                _OpCache_Fail_TC_Execution.insert({param, _OpCache_with_parameter_Fail_TC_Execution});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Fail_TC_Execution, obsw_M001_2::_ProjectionWrite_Fail_TC_Execution, obsw_M001_2::_ProjectionRead_Fail_TC_Execution::Hash, obsw_M001_2::_ProjectionRead_Fail_TC_Execution::HashEqual> _OpCache_with_parameter_Fail_TC_Execution = _OpCache_with_parameter_Fail_TC_Execution_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Fail_TC_Execution.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Fail_TC_Execution.end()) {
                                obsw_M001_2::_ProjectionWrite_Fail_TC_Execution writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Fail_TC_Execution(writeState);
                            } else {
                                copiedState.Fail_TC_Execution(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Fail_TC_Execution writeState = copiedState._update_for_Fail_TC_Execution();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Fail_TC_Execution_lock(_ProjectionRead_Fail_TC_Execution_mutex);
                                    _OpCache_with_parameter_Fail_TC_Execution.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Fail_TC_Execution";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                obsw_M001_2::_ProjectionRead__tr_Report_TC_Execution_Success read__tr_Report_TC_Execution_Success_state = state._projected_state_for__tr_Report_TC_Execution_Success();
                auto _trid_12_ptr = _OpCache_tr_Report_TC_Execution_Success.find(read__tr_Report_TC_Execution_Success_state);
                if(_trid_12_ptr == _OpCache_tr_Report_TC_Execution_Success.end()) {
                    BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >> _trid_12 = state._tr_Report_TC_Execution_Success();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_Report_TC_Execution_Success_lock(_ProjectionRead__tr_Report_TC_Execution_Success_mutex);
                        _OpCache_tr_Report_TC_Execution_Success.insert({read__tr_Report_TC_Execution_Success_state, _trid_12});
                    }
                    for(const BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >& param : _trid_12) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                        BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET > _tmp_2 = param.projection1();
                        obsw_M001_2::TM_SET _tmp_3 = _tmp_2.projection2();
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_4 = _tmp_2.projection1();

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Report_TC_Execution_Success readState = state._projected_state_for_Report_TC_Execution_Success();

                        auto _OpCache_with_parameter_Report_TC_Execution_Success_ptr = _OpCache_Report_TC_Execution_Success.find(param);
                        if(_OpCache_with_parameter_Report_TC_Execution_Success_ptr == _OpCache_Report_TC_Execution_Success.end()) {
                            copiedState.Report_TC_Execution_Success(_tmp_4, _tmp_3, _tmp_1);
                            obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Success writeState = copiedState._update_for_Report_TC_Execution_Success();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Report_TC_Execution_Success, obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Success, obsw_M001_2::_ProjectionRead_Report_TC_Execution_Success::Hash, obsw_M001_2::_ProjectionRead_Report_TC_Execution_Success::HashEqual> _OpCache_with_parameter_Report_TC_Execution_Success;
                            _OpCache_with_parameter_Report_TC_Execution_Success.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Report_TC_Execution_Success_lock(_ProjectionRead_Report_TC_Execution_Success_mutex);
                                _OpCache_Report_TC_Execution_Success.insert({param, _OpCache_with_parameter_Report_TC_Execution_Success});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Report_TC_Execution_Success, obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Success, obsw_M001_2::_ProjectionRead_Report_TC_Execution_Success::Hash, obsw_M001_2::_ProjectionRead_Report_TC_Execution_Success::HashEqual> _OpCache_with_parameter_Report_TC_Execution_Success = _OpCache_with_parameter_Report_TC_Execution_Success_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Report_TC_Execution_Success.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Report_TC_Execution_Success.end()) {
                                obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Success writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Report_TC_Execution_Success(writeState);
                            } else {
                                copiedState.Report_TC_Execution_Success(_tmp_4, _tmp_3, _tmp_1);
                                obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Success writeState = copiedState._update_for_Report_TC_Execution_Success();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Report_TC_Execution_Success_lock(_ProjectionRead_Report_TC_Execution_Success_mutex);
                                    _OpCache_with_parameter_Report_TC_Execution_Success.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Report_TC_Execution_Success";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >> _trid_12 = _trid_12_ptr->second;
                    for(const BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >& param : _trid_12) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                        BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET > _tmp_2 = param.projection1();
                        obsw_M001_2::TM_SET _tmp_3 = _tmp_2.projection2();
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_4 = _tmp_2.projection1();

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Report_TC_Execution_Success readState = state._projected_state_for_Report_TC_Execution_Success();

                        auto _OpCache_with_parameter_Report_TC_Execution_Success_ptr = _OpCache_Report_TC_Execution_Success.find(param);
                        if(_OpCache_with_parameter_Report_TC_Execution_Success_ptr == _OpCache_Report_TC_Execution_Success.end()) {
                            copiedState.Report_TC_Execution_Success(_tmp_4, _tmp_3, _tmp_1);
                            obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Success writeState = copiedState._update_for_Report_TC_Execution_Success();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Report_TC_Execution_Success, obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Success, obsw_M001_2::_ProjectionRead_Report_TC_Execution_Success::Hash, obsw_M001_2::_ProjectionRead_Report_TC_Execution_Success::HashEqual> _OpCache_with_parameter_Report_TC_Execution_Success;
                            _OpCache_with_parameter_Report_TC_Execution_Success.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Report_TC_Execution_Success_lock(_ProjectionRead_Report_TC_Execution_Success_mutex);
                                _OpCache_Report_TC_Execution_Success.insert({param, _OpCache_with_parameter_Report_TC_Execution_Success});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Report_TC_Execution_Success, obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Success, obsw_M001_2::_ProjectionRead_Report_TC_Execution_Success::Hash, obsw_M001_2::_ProjectionRead_Report_TC_Execution_Success::HashEqual> _OpCache_with_parameter_Report_TC_Execution_Success = _OpCache_with_parameter_Report_TC_Execution_Success_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Report_TC_Execution_Success.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Report_TC_Execution_Success.end()) {
                                obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Success writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Report_TC_Execution_Success(writeState);
                            } else {
                                copiedState.Report_TC_Execution_Success(_tmp_4, _tmp_3, _tmp_1);
                                obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Success writeState = copiedState._update_for_Report_TC_Execution_Success();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Report_TC_Execution_Success_lock(_ProjectionRead_Report_TC_Execution_Success_mutex);
                                    _OpCache_with_parameter_Report_TC_Execution_Success.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Report_TC_Execution_Success";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                obsw_M001_2::_ProjectionRead__tr_Skip_TC_Success_Report read__tr_Skip_TC_Success_Report_state = state._projected_state_for__tr_Skip_TC_Success_Report();
                auto _trid_13_ptr = _OpCache_tr_Skip_TC_Success_Report.find(read__tr_Skip_TC_Success_Report_state);
                if(_trid_13_ptr == _OpCache_tr_Skip_TC_Success_Report.end()) {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_13 = state._tr_Skip_TC_Success_Report();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_Skip_TC_Success_Report_lock(_ProjectionRead__tr_Skip_TC_Success_Report_mutex);
                        _OpCache_tr_Skip_TC_Success_Report.insert({read__tr_Skip_TC_Success_Report_state, _trid_13});
                    }
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_13) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Skip_TC_Success_Report readState = state._projected_state_for_Skip_TC_Success_Report();

                        auto _OpCache_with_parameter_Skip_TC_Success_Report_ptr = _OpCache_Skip_TC_Success_Report.find(param);
                        if(_OpCache_with_parameter_Skip_TC_Success_Report_ptr == _OpCache_Skip_TC_Success_Report.end()) {
                            copiedState.Skip_TC_Success_Report(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Skip_TC_Success_Report writeState = copiedState._update_for_Skip_TC_Success_Report();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Skip_TC_Success_Report, obsw_M001_2::_ProjectionWrite_Skip_TC_Success_Report, obsw_M001_2::_ProjectionRead_Skip_TC_Success_Report::Hash, obsw_M001_2::_ProjectionRead_Skip_TC_Success_Report::HashEqual> _OpCache_with_parameter_Skip_TC_Success_Report;
                            _OpCache_with_parameter_Skip_TC_Success_Report.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Skip_TC_Success_Report_lock(_ProjectionRead_Skip_TC_Success_Report_mutex);
                                _OpCache_Skip_TC_Success_Report.insert({param, _OpCache_with_parameter_Skip_TC_Success_Report});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Skip_TC_Success_Report, obsw_M001_2::_ProjectionWrite_Skip_TC_Success_Report, obsw_M001_2::_ProjectionRead_Skip_TC_Success_Report::Hash, obsw_M001_2::_ProjectionRead_Skip_TC_Success_Report::HashEqual> _OpCache_with_parameter_Skip_TC_Success_Report = _OpCache_with_parameter_Skip_TC_Success_Report_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Skip_TC_Success_Report.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Skip_TC_Success_Report.end()) {
                                obsw_M001_2::_ProjectionWrite_Skip_TC_Success_Report writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Skip_TC_Success_Report(writeState);
                            } else {
                                copiedState.Skip_TC_Success_Report(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Skip_TC_Success_Report writeState = copiedState._update_for_Skip_TC_Success_Report();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Skip_TC_Success_Report_lock(_ProjectionRead_Skip_TC_Success_Report_mutex);
                                    _OpCache_with_parameter_Skip_TC_Success_Report.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Skip_TC_Success_Report";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_13 = _trid_13_ptr->second;
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_13) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Skip_TC_Success_Report readState = state._projected_state_for_Skip_TC_Success_Report();

                        auto _OpCache_with_parameter_Skip_TC_Success_Report_ptr = _OpCache_Skip_TC_Success_Report.find(param);
                        if(_OpCache_with_parameter_Skip_TC_Success_Report_ptr == _OpCache_Skip_TC_Success_Report.end()) {
                            copiedState.Skip_TC_Success_Report(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Skip_TC_Success_Report writeState = copiedState._update_for_Skip_TC_Success_Report();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Skip_TC_Success_Report, obsw_M001_2::_ProjectionWrite_Skip_TC_Success_Report, obsw_M001_2::_ProjectionRead_Skip_TC_Success_Report::Hash, obsw_M001_2::_ProjectionRead_Skip_TC_Success_Report::HashEqual> _OpCache_with_parameter_Skip_TC_Success_Report;
                            _OpCache_with_parameter_Skip_TC_Success_Report.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Skip_TC_Success_Report_lock(_ProjectionRead_Skip_TC_Success_Report_mutex);
                                _OpCache_Skip_TC_Success_Report.insert({param, _OpCache_with_parameter_Skip_TC_Success_Report});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Skip_TC_Success_Report, obsw_M001_2::_ProjectionWrite_Skip_TC_Success_Report, obsw_M001_2::_ProjectionRead_Skip_TC_Success_Report::Hash, obsw_M001_2::_ProjectionRead_Skip_TC_Success_Report::HashEqual> _OpCache_with_parameter_Skip_TC_Success_Report = _OpCache_with_parameter_Skip_TC_Success_Report_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Skip_TC_Success_Report.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Skip_TC_Success_Report.end()) {
                                obsw_M001_2::_ProjectionWrite_Skip_TC_Success_Report writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Skip_TC_Success_Report(writeState);
                            } else {
                                copiedState.Skip_TC_Success_Report(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Skip_TC_Success_Report writeState = copiedState._update_for_Skip_TC_Success_Report();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Skip_TC_Success_Report_lock(_ProjectionRead_Skip_TC_Success_Report_mutex);
                                    _OpCache_with_parameter_Skip_TC_Success_Report.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Skip_TC_Success_Report";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                obsw_M001_2::_ProjectionRead__tr_Report_TC_Execution_Failure read__tr_Report_TC_Execution_Failure_state = state._projected_state_for__tr_Report_TC_Execution_Failure();
                auto _trid_14_ptr = _OpCache_tr_Report_TC_Execution_Failure.find(read__tr_Report_TC_Execution_Failure_state);
                if(_trid_14_ptr == _OpCache_tr_Report_TC_Execution_Failure.end()) {
                    BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >> _trid_14 = state._tr_Report_TC_Execution_Failure();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_Report_TC_Execution_Failure_lock(_ProjectionRead__tr_Report_TC_Execution_Failure_mutex);
                        _OpCache_tr_Report_TC_Execution_Failure.insert({read__tr_Report_TC_Execution_Failure_state, _trid_14});
                    }
                    for(const BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >& param : _trid_14) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                        BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET > _tmp_2 = param.projection1();
                        obsw_M001_2::TM_SET _tmp_3 = _tmp_2.projection2();
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_4 = _tmp_2.projection1();

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Report_TC_Execution_Failure readState = state._projected_state_for_Report_TC_Execution_Failure();

                        auto _OpCache_with_parameter_Report_TC_Execution_Failure_ptr = _OpCache_Report_TC_Execution_Failure.find(param);
                        if(_OpCache_with_parameter_Report_TC_Execution_Failure_ptr == _OpCache_Report_TC_Execution_Failure.end()) {
                            copiedState.Report_TC_Execution_Failure(_tmp_4, _tmp_3, _tmp_1);
                            obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Failure writeState = copiedState._update_for_Report_TC_Execution_Failure();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Report_TC_Execution_Failure, obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Failure, obsw_M001_2::_ProjectionRead_Report_TC_Execution_Failure::Hash, obsw_M001_2::_ProjectionRead_Report_TC_Execution_Failure::HashEqual> _OpCache_with_parameter_Report_TC_Execution_Failure;
                            _OpCache_with_parameter_Report_TC_Execution_Failure.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Report_TC_Execution_Failure_lock(_ProjectionRead_Report_TC_Execution_Failure_mutex);
                                _OpCache_Report_TC_Execution_Failure.insert({param, _OpCache_with_parameter_Report_TC_Execution_Failure});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Report_TC_Execution_Failure, obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Failure, obsw_M001_2::_ProjectionRead_Report_TC_Execution_Failure::Hash, obsw_M001_2::_ProjectionRead_Report_TC_Execution_Failure::HashEqual> _OpCache_with_parameter_Report_TC_Execution_Failure = _OpCache_with_parameter_Report_TC_Execution_Failure_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Report_TC_Execution_Failure.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Report_TC_Execution_Failure.end()) {
                                obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Failure writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Report_TC_Execution_Failure(writeState);
                            } else {
                                copiedState.Report_TC_Execution_Failure(_tmp_4, _tmp_3, _tmp_1);
                                obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Failure writeState = copiedState._update_for_Report_TC_Execution_Failure();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Report_TC_Execution_Failure_lock(_ProjectionRead_Report_TC_Execution_Failure_mutex);
                                    _OpCache_with_parameter_Report_TC_Execution_Failure.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Report_TC_Execution_Failure";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >> _trid_14 = _trid_14_ptr->second;
                    for(const BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >& param : _trid_14) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                        BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET > _tmp_2 = param.projection1();
                        obsw_M001_2::TM_SET _tmp_3 = _tmp_2.projection2();
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_4 = _tmp_2.projection1();

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Report_TC_Execution_Failure readState = state._projected_state_for_Report_TC_Execution_Failure();

                        auto _OpCache_with_parameter_Report_TC_Execution_Failure_ptr = _OpCache_Report_TC_Execution_Failure.find(param);
                        if(_OpCache_with_parameter_Report_TC_Execution_Failure_ptr == _OpCache_Report_TC_Execution_Failure.end()) {
                            copiedState.Report_TC_Execution_Failure(_tmp_4, _tmp_3, _tmp_1);
                            obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Failure writeState = copiedState._update_for_Report_TC_Execution_Failure();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Report_TC_Execution_Failure, obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Failure, obsw_M001_2::_ProjectionRead_Report_TC_Execution_Failure::Hash, obsw_M001_2::_ProjectionRead_Report_TC_Execution_Failure::HashEqual> _OpCache_with_parameter_Report_TC_Execution_Failure;
                            _OpCache_with_parameter_Report_TC_Execution_Failure.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Report_TC_Execution_Failure_lock(_ProjectionRead_Report_TC_Execution_Failure_mutex);
                                _OpCache_Report_TC_Execution_Failure.insert({param, _OpCache_with_parameter_Report_TC_Execution_Failure});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Report_TC_Execution_Failure, obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Failure, obsw_M001_2::_ProjectionRead_Report_TC_Execution_Failure::Hash, obsw_M001_2::_ProjectionRead_Report_TC_Execution_Failure::HashEqual> _OpCache_with_parameter_Report_TC_Execution_Failure = _OpCache_with_parameter_Report_TC_Execution_Failure_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Report_TC_Execution_Failure.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Report_TC_Execution_Failure.end()) {
                                obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Failure writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Report_TC_Execution_Failure(writeState);
                            } else {
                                copiedState.Report_TC_Execution_Failure(_tmp_4, _tmp_3, _tmp_1);
                                obsw_M001_2::_ProjectionWrite_Report_TC_Execution_Failure writeState = copiedState._update_for_Report_TC_Execution_Failure();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Report_TC_Execution_Failure_lock(_ProjectionRead_Report_TC_Execution_Failure_mutex);
                                    _OpCache_with_parameter_Report_TC_Execution_Failure.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Report_TC_Execution_Failure";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                obsw_M001_2::_ProjectionRead__tr_Skip_TC_Failure_Report read__tr_Skip_TC_Failure_Report_state = state._projected_state_for__tr_Skip_TC_Failure_Report();
                auto _trid_15_ptr = _OpCache_tr_Skip_TC_Failure_Report.find(read__tr_Skip_TC_Failure_Report_state);
                if(_trid_15_ptr == _OpCache_tr_Skip_TC_Failure_Report.end()) {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_15 = state._tr_Skip_TC_Failure_Report();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_Skip_TC_Failure_Report_lock(_ProjectionRead__tr_Skip_TC_Failure_Report_mutex);
                        _OpCache_tr_Skip_TC_Failure_Report.insert({read__tr_Skip_TC_Failure_Report_state, _trid_15});
                    }
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_15) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Skip_TC_Failure_Report readState = state._projected_state_for_Skip_TC_Failure_Report();

                        auto _OpCache_with_parameter_Skip_TC_Failure_Report_ptr = _OpCache_Skip_TC_Failure_Report.find(param);
                        if(_OpCache_with_parameter_Skip_TC_Failure_Report_ptr == _OpCache_Skip_TC_Failure_Report.end()) {
                            copiedState.Skip_TC_Failure_Report(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Skip_TC_Failure_Report writeState = copiedState._update_for_Skip_TC_Failure_Report();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Skip_TC_Failure_Report, obsw_M001_2::_ProjectionWrite_Skip_TC_Failure_Report, obsw_M001_2::_ProjectionRead_Skip_TC_Failure_Report::Hash, obsw_M001_2::_ProjectionRead_Skip_TC_Failure_Report::HashEqual> _OpCache_with_parameter_Skip_TC_Failure_Report;
                            _OpCache_with_parameter_Skip_TC_Failure_Report.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Skip_TC_Failure_Report_lock(_ProjectionRead_Skip_TC_Failure_Report_mutex);
                                _OpCache_Skip_TC_Failure_Report.insert({param, _OpCache_with_parameter_Skip_TC_Failure_Report});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Skip_TC_Failure_Report, obsw_M001_2::_ProjectionWrite_Skip_TC_Failure_Report, obsw_M001_2::_ProjectionRead_Skip_TC_Failure_Report::Hash, obsw_M001_2::_ProjectionRead_Skip_TC_Failure_Report::HashEqual> _OpCache_with_parameter_Skip_TC_Failure_Report = _OpCache_with_parameter_Skip_TC_Failure_Report_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Skip_TC_Failure_Report.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Skip_TC_Failure_Report.end()) {
                                obsw_M001_2::_ProjectionWrite_Skip_TC_Failure_Report writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Skip_TC_Failure_Report(writeState);
                            } else {
                                copiedState.Skip_TC_Failure_Report(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Skip_TC_Failure_Report writeState = copiedState._update_for_Skip_TC_Failure_Report();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Skip_TC_Failure_Report_lock(_ProjectionRead_Skip_TC_Failure_Report_mutex);
                                    _OpCache_with_parameter_Skip_TC_Failure_Report.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Skip_TC_Failure_Report";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_15 = _trid_15_ptr->second;
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_15) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Skip_TC_Failure_Report readState = state._projected_state_for_Skip_TC_Failure_Report();

                        auto _OpCache_with_parameter_Skip_TC_Failure_Report_ptr = _OpCache_Skip_TC_Failure_Report.find(param);
                        if(_OpCache_with_parameter_Skip_TC_Failure_Report_ptr == _OpCache_Skip_TC_Failure_Report.end()) {
                            copiedState.Skip_TC_Failure_Report(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Skip_TC_Failure_Report writeState = copiedState._update_for_Skip_TC_Failure_Report();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Skip_TC_Failure_Report, obsw_M001_2::_ProjectionWrite_Skip_TC_Failure_Report, obsw_M001_2::_ProjectionRead_Skip_TC_Failure_Report::Hash, obsw_M001_2::_ProjectionRead_Skip_TC_Failure_Report::HashEqual> _OpCache_with_parameter_Skip_TC_Failure_Report;
                            _OpCache_with_parameter_Skip_TC_Failure_Report.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Skip_TC_Failure_Report_lock(_ProjectionRead_Skip_TC_Failure_Report_mutex);
                                _OpCache_Skip_TC_Failure_Report.insert({param, _OpCache_with_parameter_Skip_TC_Failure_Report});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Skip_TC_Failure_Report, obsw_M001_2::_ProjectionWrite_Skip_TC_Failure_Report, obsw_M001_2::_ProjectionRead_Skip_TC_Failure_Report::Hash, obsw_M001_2::_ProjectionRead_Skip_TC_Failure_Report::HashEqual> _OpCache_with_parameter_Skip_TC_Failure_Report = _OpCache_with_parameter_Skip_TC_Failure_Report_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Skip_TC_Failure_Report.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Skip_TC_Failure_Report.end()) {
                                obsw_M001_2::_ProjectionWrite_Skip_TC_Failure_Report writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Skip_TC_Failure_Report(writeState);
                            } else {
                                copiedState.Skip_TC_Failure_Report(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Skip_TC_Failure_Report writeState = copiedState._update_for_Skip_TC_Failure_Report();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Skip_TC_Failure_Report_lock(_ProjectionRead_Skip_TC_Failure_Report_mutex);
                                    _OpCache_with_parameter_Skip_TC_Failure_Report.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Skip_TC_Failure_Report";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                obsw_M001_2::_ProjectionRead__tr_Drop_TC read__tr_Drop_TC_state = state._projected_state_for__tr_Drop_TC();
                auto _trid_16_ptr = _OpCache_tr_Drop_TC.find(read__tr_Drop_TC_state);
                if(_trid_16_ptr == _OpCache_tr_Drop_TC.end()) {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_16 = state._tr_Drop_TC();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_Drop_TC_lock(_ProjectionRead__tr_Drop_TC_mutex);
                        _OpCache_tr_Drop_TC.insert({read__tr_Drop_TC_state, _trid_16});
                    }
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_16) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Drop_TC readState = state._projected_state_for_Drop_TC();

                        auto _OpCache_with_parameter_Drop_TC_ptr = _OpCache_Drop_TC.find(param);
                        if(_OpCache_with_parameter_Drop_TC_ptr == _OpCache_Drop_TC.end()) {
                            copiedState.Drop_TC(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Drop_TC writeState = copiedState._update_for_Drop_TC();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Drop_TC, obsw_M001_2::_ProjectionWrite_Drop_TC, obsw_M001_2::_ProjectionRead_Drop_TC::Hash, obsw_M001_2::_ProjectionRead_Drop_TC::HashEqual> _OpCache_with_parameter_Drop_TC;
                            _OpCache_with_parameter_Drop_TC.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Drop_TC_lock(_ProjectionRead_Drop_TC_mutex);
                                _OpCache_Drop_TC.insert({param, _OpCache_with_parameter_Drop_TC});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Drop_TC, obsw_M001_2::_ProjectionWrite_Drop_TC, obsw_M001_2::_ProjectionRead_Drop_TC::Hash, obsw_M001_2::_ProjectionRead_Drop_TC::HashEqual> _OpCache_with_parameter_Drop_TC = _OpCache_with_parameter_Drop_TC_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Drop_TC.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Drop_TC.end()) {
                                obsw_M001_2::_ProjectionWrite_Drop_TC writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Drop_TC(writeState);
                            } else {
                                copiedState.Drop_TC(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Drop_TC writeState = copiedState._update_for_Drop_TC();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Drop_TC_lock(_ProjectionRead_Drop_TC_mutex);
                                    _OpCache_with_parameter_Drop_TC.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Drop_TC";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_16 = _trid_16_ptr->second;
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_16) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Drop_TC readState = state._projected_state_for_Drop_TC();

                        auto _OpCache_with_parameter_Drop_TC_ptr = _OpCache_Drop_TC.find(param);
                        if(_OpCache_with_parameter_Drop_TC_ptr == _OpCache_Drop_TC.end()) {
                            copiedState.Drop_TC(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Drop_TC writeState = copiedState._update_for_Drop_TC();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Drop_TC, obsw_M001_2::_ProjectionWrite_Drop_TC, obsw_M001_2::_ProjectionRead_Drop_TC::Hash, obsw_M001_2::_ProjectionRead_Drop_TC::HashEqual> _OpCache_with_parameter_Drop_TC;
                            _OpCache_with_parameter_Drop_TC.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Drop_TC_lock(_ProjectionRead_Drop_TC_mutex);
                                _OpCache_Drop_TC.insert({param, _OpCache_with_parameter_Drop_TC});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Drop_TC, obsw_M001_2::_ProjectionWrite_Drop_TC, obsw_M001_2::_ProjectionRead_Drop_TC::Hash, obsw_M001_2::_ProjectionRead_Drop_TC::HashEqual> _OpCache_with_parameter_Drop_TC = _OpCache_with_parameter_Drop_TC_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Drop_TC.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Drop_TC.end()) {
                                obsw_M001_2::_ProjectionWrite_Drop_TC writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Drop_TC(writeState);
                            } else {
                                copiedState.Drop_TC(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Drop_TC writeState = copiedState._update_for_Drop_TC();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Drop_TC_lock(_ProjectionRead_Drop_TC_mutex);
                                    _OpCache_with_parameter_Drop_TC.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Drop_TC";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                obsw_M001_2::_ProjectionRead__tr_Produce_TM read__tr_Produce_TM_state = state._projected_state_for__tr_Produce_TM();
                auto _trid_17_ptr = _OpCache_tr_Produce_TM.find(read__tr_Produce_TM_state);
                if(_trid_17_ptr == _OpCache_tr_Produce_TM.end()) {
                    BSet<BTuple<obsw_M001_2::TM_SET, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >> _trid_17 = state._tr_Produce_TM();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_Produce_TM_lock(_ProjectionRead__tr_Produce_TM_mutex);
                        _OpCache_tr_Produce_TM.insert({read__tr_Produce_TM_state, _trid_17});
                    }
                    for(const BTuple<obsw_M001_2::TM_SET, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >& param : _trid_17) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                        obsw_M001_2::TM_SET _tmp_2 = param.projection1();

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Produce_TM readState = state._projected_state_for_Produce_TM();

                        auto _OpCache_with_parameter_Produce_TM_ptr = _OpCache_Produce_TM.find(param);
                        if(_OpCache_with_parameter_Produce_TM_ptr == _OpCache_Produce_TM.end()) {
                            copiedState.Produce_TM(_tmp_2, _tmp_1);
                            obsw_M001_2::_ProjectionWrite_Produce_TM writeState = copiedState._update_for_Produce_TM();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Produce_TM, obsw_M001_2::_ProjectionWrite_Produce_TM, obsw_M001_2::_ProjectionRead_Produce_TM::Hash, obsw_M001_2::_ProjectionRead_Produce_TM::HashEqual> _OpCache_with_parameter_Produce_TM;
                            _OpCache_with_parameter_Produce_TM.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Produce_TM_lock(_ProjectionRead_Produce_TM_mutex);
                                _OpCache_Produce_TM.insert({param, _OpCache_with_parameter_Produce_TM});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Produce_TM, obsw_M001_2::_ProjectionWrite_Produce_TM, obsw_M001_2::_ProjectionRead_Produce_TM::Hash, obsw_M001_2::_ProjectionRead_Produce_TM::HashEqual> _OpCache_with_parameter_Produce_TM = _OpCache_with_parameter_Produce_TM_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Produce_TM.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Produce_TM.end()) {
                                obsw_M001_2::_ProjectionWrite_Produce_TM writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Produce_TM(writeState);
                            } else {
                                copiedState.Produce_TM(_tmp_2, _tmp_1);
                                obsw_M001_2::_ProjectionWrite_Produce_TM writeState = copiedState._update_for_Produce_TM();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Produce_TM_lock(_ProjectionRead_Produce_TM_mutex);
                                    _OpCache_with_parameter_Produce_TM.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Produce_TM";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BTuple<obsw_M001_2::TM_SET, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >> _trid_17 = _trid_17_ptr->second;
                    for(const BTuple<obsw_M001_2::TM_SET, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >& param : _trid_17) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                        obsw_M001_2::TM_SET _tmp_2 = param.projection1();

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Produce_TM readState = state._projected_state_for_Produce_TM();

                        auto _OpCache_with_parameter_Produce_TM_ptr = _OpCache_Produce_TM.find(param);
                        if(_OpCache_with_parameter_Produce_TM_ptr == _OpCache_Produce_TM.end()) {
                            copiedState.Produce_TM(_tmp_2, _tmp_1);
                            obsw_M001_2::_ProjectionWrite_Produce_TM writeState = copiedState._update_for_Produce_TM();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Produce_TM, obsw_M001_2::_ProjectionWrite_Produce_TM, obsw_M001_2::_ProjectionRead_Produce_TM::Hash, obsw_M001_2::_ProjectionRead_Produce_TM::HashEqual> _OpCache_with_parameter_Produce_TM;
                            _OpCache_with_parameter_Produce_TM.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Produce_TM_lock(_ProjectionRead_Produce_TM_mutex);
                                _OpCache_Produce_TM.insert({param, _OpCache_with_parameter_Produce_TM});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Produce_TM, obsw_M001_2::_ProjectionWrite_Produce_TM, obsw_M001_2::_ProjectionRead_Produce_TM::Hash, obsw_M001_2::_ProjectionRead_Produce_TM::HashEqual> _OpCache_with_parameter_Produce_TM = _OpCache_with_parameter_Produce_TM_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Produce_TM.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Produce_TM.end()) {
                                obsw_M001_2::_ProjectionWrite_Produce_TM writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Produce_TM(writeState);
                            } else {
                                copiedState.Produce_TM(_tmp_2, _tmp_1);
                                obsw_M001_2::_ProjectionWrite_Produce_TM writeState = copiedState._update_for_Produce_TM();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Produce_TM_lock(_ProjectionRead_Produce_TM_mutex);
                                    _OpCache_with_parameter_Produce_TM.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Produce_TM";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                obsw_M001_2::_ProjectionRead__tr_Pass_TM read__tr_Pass_TM_state = state._projected_state_for__tr_Pass_TM();
                auto _trid_18_ptr = _OpCache_tr_Pass_TM.find(read__tr_Pass_TM_state);
                if(_trid_18_ptr == _OpCache_tr_Pass_TM.end()) {
                    BSet<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER >> _trid_18 = state._tr_Pass_TM();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_Pass_TM_lock(_ProjectionRead__tr_Pass_TM_mutex);
                        _OpCache_tr_Pass_TM.insert({read__tr_Pass_TM_state, _trid_18});
                    }
                    for(const BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER >& param : _trid_18) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER _tmp_1 = param.projection2();
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_2 = param.projection1();

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Pass_TM readState = state._projected_state_for_Pass_TM();

                        auto _OpCache_with_parameter_Pass_TM_ptr = _OpCache_Pass_TM.find(param);
                        if(_OpCache_with_parameter_Pass_TM_ptr == _OpCache_Pass_TM.end()) {
                            copiedState.Pass_TM(_tmp_2, _tmp_1);
                            obsw_M001_2::_ProjectionWrite_Pass_TM writeState = copiedState._update_for_Pass_TM();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Pass_TM, obsw_M001_2::_ProjectionWrite_Pass_TM, obsw_M001_2::_ProjectionRead_Pass_TM::Hash, obsw_M001_2::_ProjectionRead_Pass_TM::HashEqual> _OpCache_with_parameter_Pass_TM;
                            _OpCache_with_parameter_Pass_TM.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Pass_TM_lock(_ProjectionRead_Pass_TM_mutex);
                                _OpCache_Pass_TM.insert({param, _OpCache_with_parameter_Pass_TM});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Pass_TM, obsw_M001_2::_ProjectionWrite_Pass_TM, obsw_M001_2::_ProjectionRead_Pass_TM::Hash, obsw_M001_2::_ProjectionRead_Pass_TM::HashEqual> _OpCache_with_parameter_Pass_TM = _OpCache_with_parameter_Pass_TM_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Pass_TM.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Pass_TM.end()) {
                                obsw_M001_2::_ProjectionWrite_Pass_TM writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Pass_TM(writeState);
                            } else {
                                copiedState.Pass_TM(_tmp_2, _tmp_1);
                                obsw_M001_2::_ProjectionWrite_Pass_TM writeState = copiedState._update_for_Pass_TM();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Pass_TM_lock(_ProjectionRead_Pass_TM_mutex);
                                    _OpCache_with_parameter_Pass_TM.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Pass_TM";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER >> _trid_18 = _trid_18_ptr->second;
                    for(const BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER >& param : _trid_18) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER _tmp_1 = param.projection2();
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_2 = param.projection1();

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Pass_TM readState = state._projected_state_for_Pass_TM();

                        auto _OpCache_with_parameter_Pass_TM_ptr = _OpCache_Pass_TM.find(param);
                        if(_OpCache_with_parameter_Pass_TM_ptr == _OpCache_Pass_TM.end()) {
                            copiedState.Pass_TM(_tmp_2, _tmp_1);
                            obsw_M001_2::_ProjectionWrite_Pass_TM writeState = copiedState._update_for_Pass_TM();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Pass_TM, obsw_M001_2::_ProjectionWrite_Pass_TM, obsw_M001_2::_ProjectionRead_Pass_TM::Hash, obsw_M001_2::_ProjectionRead_Pass_TM::HashEqual> _OpCache_with_parameter_Pass_TM;
                            _OpCache_with_parameter_Pass_TM.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Pass_TM_lock(_ProjectionRead_Pass_TM_mutex);
                                _OpCache_Pass_TM.insert({param, _OpCache_with_parameter_Pass_TM});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Pass_TM, obsw_M001_2::_ProjectionWrite_Pass_TM, obsw_M001_2::_ProjectionRead_Pass_TM::Hash, obsw_M001_2::_ProjectionRead_Pass_TM::HashEqual> _OpCache_with_parameter_Pass_TM = _OpCache_with_parameter_Pass_TM_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Pass_TM.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Pass_TM.end()) {
                                obsw_M001_2::_ProjectionWrite_Pass_TM writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Pass_TM(writeState);
                            } else {
                                copiedState.Pass_TM(_tmp_2, _tmp_1);
                                obsw_M001_2::_ProjectionWrite_Pass_TM writeState = copiedState._update_for_Pass_TM();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Pass_TM_lock(_ProjectionRead_Pass_TM_mutex);
                                    _OpCache_with_parameter_Pass_TM.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Pass_TM";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                obsw_M001_2::_ProjectionRead__tr_Cancel_TM read__tr_Cancel_TM_state = state._projected_state_for__tr_Cancel_TM();
                auto _trid_19_ptr = _OpCache_tr_Cancel_TM.find(read__tr_Cancel_TM_state);
                if(_trid_19_ptr == _OpCache_tr_Cancel_TM.end()) {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL> _trid_19 = state._tr_Cancel_TM();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_Cancel_TM_lock(_ProjectionRead__tr_Cancel_TM_mutex);
                        _OpCache_tr_Cancel_TM.insert({read__tr_Cancel_TM_state, _trid_19});
                    }
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL& param : _trid_19) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Cancel_TM readState = state._projected_state_for_Cancel_TM();

                        auto _OpCache_with_parameter_Cancel_TM_ptr = _OpCache_Cancel_TM.find(param);
                        if(_OpCache_with_parameter_Cancel_TM_ptr == _OpCache_Cancel_TM.end()) {
                            copiedState.Cancel_TM(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Cancel_TM writeState = copiedState._update_for_Cancel_TM();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Cancel_TM, obsw_M001_2::_ProjectionWrite_Cancel_TM, obsw_M001_2::_ProjectionRead_Cancel_TM::Hash, obsw_M001_2::_ProjectionRead_Cancel_TM::HashEqual> _OpCache_with_parameter_Cancel_TM;
                            _OpCache_with_parameter_Cancel_TM.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Cancel_TM_lock(_ProjectionRead_Cancel_TM_mutex);
                                _OpCache_Cancel_TM.insert({param, _OpCache_with_parameter_Cancel_TM});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Cancel_TM, obsw_M001_2::_ProjectionWrite_Cancel_TM, obsw_M001_2::_ProjectionRead_Cancel_TM::Hash, obsw_M001_2::_ProjectionRead_Cancel_TM::HashEqual> _OpCache_with_parameter_Cancel_TM = _OpCache_with_parameter_Cancel_TM_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Cancel_TM.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Cancel_TM.end()) {
                                obsw_M001_2::_ProjectionWrite_Cancel_TM writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Cancel_TM(writeState);
                            } else {
                                copiedState.Cancel_TM(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Cancel_TM writeState = copiedState._update_for_Cancel_TM();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Cancel_TM_lock(_ProjectionRead_Cancel_TM_mutex);
                                    _OpCache_with_parameter_Cancel_TM.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Cancel_TM";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL> _trid_19 = _trid_19_ptr->second;
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL& param : _trid_19) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Cancel_TM readState = state._projected_state_for_Cancel_TM();

                        auto _OpCache_with_parameter_Cancel_TM_ptr = _OpCache_Cancel_TM.find(param);
                        if(_OpCache_with_parameter_Cancel_TM_ptr == _OpCache_Cancel_TM.end()) {
                            copiedState.Cancel_TM(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Cancel_TM writeState = copiedState._update_for_Cancel_TM();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Cancel_TM, obsw_M001_2::_ProjectionWrite_Cancel_TM, obsw_M001_2::_ProjectionRead_Cancel_TM::Hash, obsw_M001_2::_ProjectionRead_Cancel_TM::HashEqual> _OpCache_with_parameter_Cancel_TM;
                            _OpCache_with_parameter_Cancel_TM.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Cancel_TM_lock(_ProjectionRead_Cancel_TM_mutex);
                                _OpCache_Cancel_TM.insert({param, _OpCache_with_parameter_Cancel_TM});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Cancel_TM, obsw_M001_2::_ProjectionWrite_Cancel_TM, obsw_M001_2::_ProjectionRead_Cancel_TM::Hash, obsw_M001_2::_ProjectionRead_Cancel_TM::HashEqual> _OpCache_with_parameter_Cancel_TM = _OpCache_with_parameter_Cancel_TM_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Cancel_TM.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Cancel_TM.end()) {
                                obsw_M001_2::_ProjectionWrite_Cancel_TM writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Cancel_TM(writeState);
                            } else {
                                copiedState.Cancel_TM(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Cancel_TM writeState = copiedState._update_for_Cancel_TM();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Cancel_TM_lock(_ProjectionRead_Cancel_TM_mutex);
                                    _OpCache_with_parameter_Cancel_TM.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Cancel_TM";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                obsw_M001_2::_ProjectionRead__tr_Drop_TM read__tr_Drop_TM_state = state._projected_state_for__tr_Drop_TM();
                auto _trid_20_ptr = _OpCache_tr_Drop_TM.find(read__tr_Drop_TM_state);
                if(_trid_20_ptr == _OpCache_tr_Drop_TM.end()) {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL> _trid_20 = state._tr_Drop_TM();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_Drop_TM_lock(_ProjectionRead__tr_Drop_TM_mutex);
                        _OpCache_tr_Drop_TM.insert({read__tr_Drop_TM_state, _trid_20});
                    }
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL& param : _trid_20) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Drop_TM readState = state._projected_state_for_Drop_TM();

                        auto _OpCache_with_parameter_Drop_TM_ptr = _OpCache_Drop_TM.find(param);
                        if(_OpCache_with_parameter_Drop_TM_ptr == _OpCache_Drop_TM.end()) {
                            copiedState.Drop_TM(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Drop_TM writeState = copiedState._update_for_Drop_TM();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Drop_TM, obsw_M001_2::_ProjectionWrite_Drop_TM, obsw_M001_2::_ProjectionRead_Drop_TM::Hash, obsw_M001_2::_ProjectionRead_Drop_TM::HashEqual> _OpCache_with_parameter_Drop_TM;
                            _OpCache_with_parameter_Drop_TM.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Drop_TM_lock(_ProjectionRead_Drop_TM_mutex);
                                _OpCache_Drop_TM.insert({param, _OpCache_with_parameter_Drop_TM});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Drop_TM, obsw_M001_2::_ProjectionWrite_Drop_TM, obsw_M001_2::_ProjectionRead_Drop_TM::Hash, obsw_M001_2::_ProjectionRead_Drop_TM::HashEqual> _OpCache_with_parameter_Drop_TM = _OpCache_with_parameter_Drop_TM_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Drop_TM.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Drop_TM.end()) {
                                obsw_M001_2::_ProjectionWrite_Drop_TM writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Drop_TM(writeState);
                            } else {
                                copiedState.Drop_TM(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Drop_TM writeState = copiedState._update_for_Drop_TM();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Drop_TM_lock(_ProjectionRead_Drop_TM_mutex);
                                    _OpCache_with_parameter_Drop_TM.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Drop_TM";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL> _trid_20 = _trid_20_ptr->second;
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL& param : _trid_20) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_Drop_TM readState = state._projected_state_for_Drop_TM();

                        auto _OpCache_with_parameter_Drop_TM_ptr = _OpCache_Drop_TM.find(param);
                        if(_OpCache_with_parameter_Drop_TM_ptr == _OpCache_Drop_TM.end()) {
                            copiedState.Drop_TM(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_Drop_TM writeState = copiedState._update_for_Drop_TM();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Drop_TM, obsw_M001_2::_ProjectionWrite_Drop_TM, obsw_M001_2::_ProjectionRead_Drop_TM::Hash, obsw_M001_2::_ProjectionRead_Drop_TM::HashEqual> _OpCache_with_parameter_Drop_TM;
                            _OpCache_with_parameter_Drop_TM.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Drop_TM_lock(_ProjectionRead_Drop_TM_mutex);
                                _OpCache_Drop_TM.insert({param, _OpCache_with_parameter_Drop_TM});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_Drop_TM, obsw_M001_2::_ProjectionWrite_Drop_TM, obsw_M001_2::_ProjectionRead_Drop_TM::Hash, obsw_M001_2::_ProjectionRead_Drop_TM::HashEqual> _OpCache_with_parameter_Drop_TM = _OpCache_with_parameter_Drop_TM_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_Drop_TM.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_Drop_TM.end()) {
                                obsw_M001_2::_ProjectionWrite_Drop_TM writeState = writeState_ptr->second;
                                copiedState._apply_update_for_Drop_TM(writeState);
                            } else {
                                copiedState.Drop_TM(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_Drop_TM writeState = copiedState._update_for_Drop_TM();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_Drop_TM_lock(_ProjectionRead_Drop_TM_mutex);
                                    _OpCache_with_parameter_Drop_TM.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "Drop_TM";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                obsw_M001_2::_ProjectionRead__tr_env_Deliver_TM read__tr_env_Deliver_TM_state = state._projected_state_for__tr_env_Deliver_TM();
                auto _trid_21_ptr = _OpCache_tr_env_Deliver_TM.find(read__tr_env_Deliver_TM_state);
                if(_trid_21_ptr == _OpCache_tr_env_Deliver_TM.end()) {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER> _trid_21 = state._tr_env_Deliver_TM();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_env_Deliver_TM_lock(_ProjectionRead__tr_env_Deliver_TM_mutex);
                        _OpCache_tr_env_Deliver_TM.insert({read__tr_env_Deliver_TM_state, _trid_21});
                    }
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER& param : _trid_21) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_env_Deliver_TM readState = state._projected_state_for_env_Deliver_TM();

                        auto _OpCache_with_parameter_env_Deliver_TM_ptr = _OpCache_env_Deliver_TM.find(param);
                        if(_OpCache_with_parameter_env_Deliver_TM_ptr == _OpCache_env_Deliver_TM.end()) {
                            copiedState.env_Deliver_TM(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_env_Deliver_TM writeState = copiedState._update_for_env_Deliver_TM();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_env_Deliver_TM, obsw_M001_2::_ProjectionWrite_env_Deliver_TM, obsw_M001_2::_ProjectionRead_env_Deliver_TM::Hash, obsw_M001_2::_ProjectionRead_env_Deliver_TM::HashEqual> _OpCache_with_parameter_env_Deliver_TM;
                            _OpCache_with_parameter_env_Deliver_TM.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_Deliver_TM_lock(_ProjectionRead_env_Deliver_TM_mutex);
                                _OpCache_env_Deliver_TM.insert({param, _OpCache_with_parameter_env_Deliver_TM});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_env_Deliver_TM, obsw_M001_2::_ProjectionWrite_env_Deliver_TM, obsw_M001_2::_ProjectionRead_env_Deliver_TM::Hash, obsw_M001_2::_ProjectionRead_env_Deliver_TM::HashEqual> _OpCache_with_parameter_env_Deliver_TM = _OpCache_with_parameter_env_Deliver_TM_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_Deliver_TM.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_Deliver_TM.end()) {
                                obsw_M001_2::_ProjectionWrite_env_Deliver_TM writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_Deliver_TM(writeState);
                            } else {
                                copiedState.env_Deliver_TM(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_env_Deliver_TM writeState = copiedState._update_for_env_Deliver_TM();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_Deliver_TM_lock(_ProjectionRead_env_Deliver_TM_mutex);
                                    _OpCache_with_parameter_env_Deliver_TM.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_Deliver_TM";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER> _trid_21 = _trid_21_ptr->second;
                    for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER& param : _trid_21) {
                        obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER _tmp_1 = param;

                        obsw_M001_2 copiedState = state._copy();
                        obsw_M001_2::_ProjectionRead_env_Deliver_TM readState = state._projected_state_for_env_Deliver_TM();

                        auto _OpCache_with_parameter_env_Deliver_TM_ptr = _OpCache_env_Deliver_TM.find(param);
                        if(_OpCache_with_parameter_env_Deliver_TM_ptr == _OpCache_env_Deliver_TM.end()) {
                            copiedState.env_Deliver_TM(_tmp_1);
                            obsw_M001_2::_ProjectionWrite_env_Deliver_TM writeState = copiedState._update_for_env_Deliver_TM();
                            std::unordered_map<obsw_M001_2::_ProjectionRead_env_Deliver_TM, obsw_M001_2::_ProjectionWrite_env_Deliver_TM, obsw_M001_2::_ProjectionRead_env_Deliver_TM::Hash, obsw_M001_2::_ProjectionRead_env_Deliver_TM::HashEqual> _OpCache_with_parameter_env_Deliver_TM;
                            _OpCache_with_parameter_env_Deliver_TM.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_Deliver_TM_lock(_ProjectionRead_env_Deliver_TM_mutex);
                                _OpCache_env_Deliver_TM.insert({param, _OpCache_with_parameter_env_Deliver_TM});
                            }

                        } else {
                            std::unordered_map<obsw_M001_2::_ProjectionRead_env_Deliver_TM, obsw_M001_2::_ProjectionWrite_env_Deliver_TM, obsw_M001_2::_ProjectionRead_env_Deliver_TM::Hash, obsw_M001_2::_ProjectionRead_env_Deliver_TM::HashEqual> _OpCache_with_parameter_env_Deliver_TM = _OpCache_with_parameter_env_Deliver_TM_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_Deliver_TM.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_Deliver_TM.end()) {
                                obsw_M001_2::_ProjectionWrite_env_Deliver_TM writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_Deliver_TM(writeState);
                            } else {
                                copiedState.env_Deliver_TM(_tmp_1);
                                obsw_M001_2::_ProjectionWrite_env_Deliver_TM writeState = copiedState._update_for_env_Deliver_TM();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_Deliver_TM_lock(_ProjectionRead_env_Deliver_TM_mutex);
                                    _OpCache_with_parameter_env_Deliver_TM.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_Deliver_TM";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }

            } else {
                BSet<BTuple<obsw_M001_2::TC_SET, obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER >> _trid_1 = state._tr_env_Receive_TC();
                for(const BTuple<obsw_M001_2::TC_SET, obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER >& param : _trid_1) {
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER _tmp_1 = param.projection2();
                    obsw_M001_2::TC_SET _tmp_2 = param.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.env_Receive_TC(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "env_Receive_TC";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER >> _trid_2 = state._tr_Poll_TC();
                for(const BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER >& param : _trid_2) {
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_BUFFER _tmp_1 = param.projection2();
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_2 = param.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Poll_TC(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "Poll_TC";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_3 = state._tr_Accept_TC();
                for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_3) {
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Accept_TC(_tmp_1);
                    copiedState.stateAccessedVia = "Accept_TC";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_4 = state._tr_Reject_TC();
                for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_4) {
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Reject_TC(_tmp_1);
                    copiedState.stateAccessedVia = "Reject_TC";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >> _trid_5 = state._tr_Report_TC_Acceptance();
                for(const BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >& param : _trid_5) {
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                    BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET > _tmp_2 = param.projection1();
                    obsw_M001_2::TM_SET _tmp_3 = _tmp_2.projection2();
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_4 = _tmp_2.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Report_TC_Acceptance(_tmp_4, _tmp_3, _tmp_1);
                    copiedState.stateAccessedVia = "Report_TC_Acceptance";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_6 = state._tr_Skip_TC_Acceptance_Report();
                for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_6) {
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Skip_TC_Acceptance_Report(_tmp_1);
                    copiedState.stateAccessedVia = "Skip_TC_Acceptance_Report";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >> _trid_7 = state._tr_Report_TC_Rejection();
                for(const BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >& param : _trid_7) {
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                    BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET > _tmp_2 = param.projection1();
                    obsw_M001_2::TM_SET _tmp_3 = _tmp_2.projection2();
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_4 = _tmp_2.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Report_TC_Rejection(_tmp_4, _tmp_3, _tmp_1);
                    copiedState.stateAccessedVia = "Report_TC_Rejection";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_8 = state._tr_Skip_TC_Rejection_Report();
                for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_8) {
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Skip_TC_Rejection_Report(_tmp_1);
                    copiedState.stateAccessedVia = "Skip_TC_Rejection_Report";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_9 = state._tr_Execute_TC_Successfully();
                for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_9) {
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Execute_TC_Successfully(_tmp_1);
                    copiedState.stateAccessedVia = "Execute_TC_Successfully";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_10 = state._tr_Reset_TM_Buffer();
                for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_10) {
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Reset_TM_Buffer(_tmp_1);
                    copiedState.stateAccessedVia = "Reset_TM_Buffer";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_11 = state._tr_Fail_TC_Execution();
                for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_11) {
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Fail_TC_Execution(_tmp_1);
                    copiedState.stateAccessedVia = "Fail_TC_Execution";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >> _trid_12 = state._tr_Report_TC_Execution_Success();
                for(const BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >& param : _trid_12) {
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                    BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET > _tmp_2 = param.projection1();
                    obsw_M001_2::TM_SET _tmp_3 = _tmp_2.projection2();
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_4 = _tmp_2.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Report_TC_Execution_Success(_tmp_4, _tmp_3, _tmp_1);
                    copiedState.stateAccessedVia = "Report_TC_Execution_Success";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_13 = state._tr_Skip_TC_Success_Report();
                for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_13) {
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Skip_TC_Success_Report(_tmp_1);
                    copiedState.stateAccessedVia = "Skip_TC_Success_Report";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >> _trid_14 = state._tr_Report_TC_Execution_Failure();
                for(const BTuple<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET >, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >& param : _trid_14) {
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                    BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL, obsw_M001_2::TM_SET > _tmp_2 = param.projection1();
                    obsw_M001_2::TM_SET _tmp_3 = _tmp_2.projection2();
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_4 = _tmp_2.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Report_TC_Execution_Failure(_tmp_4, _tmp_3, _tmp_1);
                    copiedState.stateAccessedVia = "Report_TC_Execution_Failure";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_15 = state._tr_Skip_TC_Failure_Report();
                for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_15) {
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Skip_TC_Failure_Report(_tmp_1);
                    copiedState.stateAccessedVia = "Skip_TC_Failure_Report";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL> _trid_16 = state._tr_Drop_TC();
                for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL& param : _trid_16) {
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Drop_TC(_tmp_1);
                    copiedState.stateAccessedVia = "Drop_TC";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BTuple<obsw_M001_2::TM_SET, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >> _trid_17 = state._tr_Produce_TM();
                for(const BTuple<obsw_M001_2::TM_SET, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL >& param : _trid_17) {
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                    obsw_M001_2::TM_SET _tmp_2 = param.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Produce_TM(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "Produce_TM";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER >> _trid_18 = state._tr_Pass_TM();
                for(const BTuple<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL, obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER >& param : _trid_18) {
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER _tmp_1 = param.projection2();
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_2 = param.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Pass_TM(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "Pass_TM";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL> _trid_19 = state._tr_Cancel_TM();
                for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL& param : _trid_19) {
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Cancel_TM(_tmp_1);
                    copiedState.stateAccessedVia = "Cancel_TM";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL> _trid_20 = state._tr_Drop_TM();
                for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL& param : _trid_20) {
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Drop_TM(_tmp_1);
                    copiedState.stateAccessedVia = "Drop_TM";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER> _trid_21 = state._tr_env_Deliver_TM();
                for(const obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER& param : _trid_21) {
                    obsw_M001_2::PACKET_START_ADDRESSES_IN_TM_BUFFER _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.env_Deliver_TM(_tmp_1);
                    copiedState.stateAccessedVia = "env_Deliver_TM";
                    result.insert(copiedState);
                    transitions += 1;
                }

            }
            return result;
        }

        bool invariantViolated(const obsw_M001_2& state) {
            bool _check_inv_1;
            if(isCaching) {
                obsw_M001_2::_ProjectionRead__check_inv_1 read__check_inv_1_state = state._projected_state_for__check_inv_1();
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
                obsw_M001_2::_ProjectionRead__check_inv_2 read__check_inv_2_state = state._projected_state_for__check_inv_2();
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
                obsw_M001_2::_ProjectionRead__check_inv_3 read__check_inv_3_state = state._projected_state_for__check_inv_3();
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
                obsw_M001_2::_ProjectionRead__check_inv_4 read__check_inv_4_state = state._projected_state_for__check_inv_4();
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
                obsw_M001_2::_ProjectionRead__check_inv_5 read__check_inv_5_state = state._projected_state_for__check_inv_5();
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
                obsw_M001_2::_ProjectionRead__check_inv_6 read__check_inv_6_state = state._projected_state_for__check_inv_6();
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
                obsw_M001_2::_ProjectionRead__check_inv_7 read__check_inv_7_state = state._projected_state_for__check_inv_7();
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
                obsw_M001_2::_ProjectionRead__check_inv_8 read__check_inv_8_state = state._projected_state_for__check_inv_8();
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
                obsw_M001_2::_ProjectionRead__check_inv_9 read__check_inv_9_state = state._projected_state_for__check_inv_9();
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

    obsw_M001_2::Type type;

    if(std::string("mixed").compare(strategy) == 0) {
        type = obsw_M001_2::Type::MIXED;
    } else if(std::string("bf").compare(strategy) == 0) {
        type = obsw_M001_2::Type::BFS;
    } else if (std::string("df").compare(strategy) == 0) {
        type = obsw_M001_2::Type::DFS;
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