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

#ifndef rether_H
#define rether_H

using namespace std;

class rether {

    public:

        enum Type { BFS, DFS, MIXED };

        class Nodes : public BObject {
            public:

                typedef Nodes current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum Nodes_type {
                    node1, 
                    node2, 
                    node3, 
                    node4, 
                    node5
                };

                Nodes_type value;

                Nodes(){}

                Nodes(const Nodes_type& type) {
                    this->value = type;
                }

                BBoolean equal(const Nodes& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const Nodes& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const Nodes& p1, const Nodes& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const Nodes& p1, const Nodes& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const Nodes& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const Nodes& e) {
                    switch(e.value) {
                        case node1: return strm << "node1";
                        case node2: return strm << "node2";
                        case node3: return strm << "node3";
                        case node4: return strm << "node4";
                        case node5: return strm << "node5";
                    }
                    return strm;
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class Slots : public BObject {
            public:

                typedef Slots current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum Slots_type {
                    slot1, 
                    slot2, 
                    slot3, 
                    slot4
                };

                Slots_type value;

                Slots(){}

                Slots(const Slots_type& type) {
                    this->value = type;
                }

                BBoolean equal(const Slots& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const Slots& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const Slots& p1, const Slots& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const Slots& p1, const Slots& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const Slots& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const Slots& e) {
                    switch(e.value) {
                        case slot1: return strm << "slot1";
                        case slot2: return strm << "slot2";
                        case slot3: return strm << "slot3";
                        case slot4: return strm << "slot4";
                    }
                    return strm;
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };


        struct Hash {
            public:
                size_t operator()(const rether& obj) const {
                    return obj.hashCode();
                }
        };

        struct HashEqual {
            public:
                bool operator()(const rether& obj1, const rether& obj2) const {
                    if (obj1 == obj2)
                        return true;
                    else
                        return false;
                    }
            };

        class _ProjectionRead_elapse_time {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_elapse_time& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_elapse_time& obj1, const _ProjectionRead_elapse_time& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                Slots time;

                _ProjectionRead_elapse_time(const Slots& time) {
                    this->time = time;
                }

                friend bool operator ==(const _ProjectionRead_elapse_time& o1, const _ProjectionRead_elapse_time& o2) {
                    return o1.time == (o2.time);
                }

                friend bool operator !=(const _ProjectionRead_elapse_time& o1, const _ProjectionRead_elapse_time& o2) {
                    return o1.time != (o2.time);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_elapse_time& e) {
                    strm << "{";
                    strm << "time: " << e.time;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (time.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_elapse_time {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_elapse_time& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_elapse_time& obj1, const _ProjectionRead__tr_elapse_time& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                Slots time;

                _ProjectionRead__tr_elapse_time(const Slots& time) {
                    this->time = time;
                }

                friend bool operator ==(const _ProjectionRead__tr_elapse_time& o1, const _ProjectionRead__tr_elapse_time& o2) {
                    return o1.time == (o2.time);
                }

                friend bool operator !=(const _ProjectionRead__tr_elapse_time& o1, const _ProjectionRead__tr_elapse_time& o2) {
                    return o1.time != (o2.time);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_elapse_time& e) {
                    strm << "{";
                    strm << "time: " << e.time;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (time.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_elapse_time {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_elapse_time& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_elapse_time& obj1, const _ProjectionWrite_elapse_time& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                Slots time;

                _ProjectionWrite_elapse_time(const Slots& time) {
                    this->time = time;
                }

                friend bool operator ==(const _ProjectionWrite_elapse_time& o1, const _ProjectionWrite_elapse_time& o2) {
                    return o1.time == (o2.time);
                }

                friend bool operator !=(const _ProjectionWrite_elapse_time& o1, const _ProjectionWrite_elapse_time& o2) {
                    return o1.time != (o2.time);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_elapse_time& e) {
                    strm << "{";
                    strm << "time: " << e.time;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (time.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_reserve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_reserve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_reserve& obj1, const _ProjectionRead_reserve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<Nodes, Slots > grants;
                BRelation<Nodes, Slots > open_reservations;

                _ProjectionRead_reserve(const BRelation<Nodes, Slots >& grants, const BRelation<Nodes, Slots >& open_reservations) {
                    this->grants = grants;
                    this->open_reservations = open_reservations;
                }

                friend bool operator ==(const _ProjectionRead_reserve& o1, const _ProjectionRead_reserve& o2) {
                    return o1.grants == (o2.grants) && o1.open_reservations == (o2.open_reservations);
                }

                friend bool operator !=(const _ProjectionRead_reserve& o1, const _ProjectionRead_reserve& o2) {
                    return o1.grants != (o2.grants) || o1.open_reservations != (o2.open_reservations);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_reserve& e) {
                    strm << "{";
                    strm << "grants: " << e.grants;
                    strm << ", ";
                    strm << "open_reservations: " << e.open_reservations;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (grants.hashCode() << 1);
                    result = 31 * result + (open_reservations.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_reserve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_reserve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_reserve& obj1, const _ProjectionRead__tr_reserve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<Nodes, Slots > grants;
                BRelation<Nodes, Slots > open_reservations;

                _ProjectionRead__tr_reserve(const BRelation<Nodes, Slots >& grants, const BRelation<Nodes, Slots >& open_reservations) {
                    this->grants = grants;
                    this->open_reservations = open_reservations;
                }

                friend bool operator ==(const _ProjectionRead__tr_reserve& o1, const _ProjectionRead__tr_reserve& o2) {
                    return o1.grants == (o2.grants) && o1.open_reservations == (o2.open_reservations);
                }

                friend bool operator !=(const _ProjectionRead__tr_reserve& o1, const _ProjectionRead__tr_reserve& o2) {
                    return o1.grants != (o2.grants) || o1.open_reservations != (o2.open_reservations);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_reserve& e) {
                    strm << "{";
                    strm << "grants: " << e.grants;
                    strm << ", "; 
                    strm << "open_reservations: " << e.open_reservations;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (grants.hashCode() << 1);
                    result = 31 * result + (open_reservations.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_reserve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_reserve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_reserve& obj1, const _ProjectionWrite_reserve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<Nodes, Slots > open_reservations;

                _ProjectionWrite_reserve(const BRelation<Nodes, Slots >& open_reservations) {
                    this->open_reservations = open_reservations;
                }

                friend bool operator ==(const _ProjectionWrite_reserve& o1, const _ProjectionWrite_reserve& o2) {
                    return o1.open_reservations == (o2.open_reservations);
                }

                friend bool operator !=(const _ProjectionWrite_reserve& o1, const _ProjectionWrite_reserve& o2) {
                    return o1.open_reservations != (o2.open_reservations);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_reserve& e) {
                    strm << "{";
                    strm << "open_reservations: " << e.open_reservations;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (open_reservations.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_release {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_release& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_release& obj1, const _ProjectionRead_release& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<Nodes, Slots > grants;
                BInteger RT_count;

                _ProjectionRead_release(const BRelation<Nodes, Slots >& grants, const BInteger& RT_count) {
                    this->grants = grants;
                    this->RT_count = RT_count;
                }

                friend bool operator ==(const _ProjectionRead_release& o1, const _ProjectionRead_release& o2) {
                    return o1.grants == (o2.grants) && o1.RT_count == (o2.RT_count);
                }

                friend bool operator !=(const _ProjectionRead_release& o1, const _ProjectionRead_release& o2) {
                    return o1.grants != (o2.grants) || o1.RT_count != (o2.RT_count);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_release& e) {
                    strm << "{";
                    strm << "grants: " << e.grants;
                    strm << ", ";
                    strm << "RT_count: " << e.RT_count;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (grants.hashCode() << 1);
                    result = 31 * result + (RT_count.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_release {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_release& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_release& obj1, const _ProjectionRead__tr_release& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<Nodes, Slots > grants;

                _ProjectionRead__tr_release(const BRelation<Nodes, Slots >& grants) {
                    this->grants = grants;
                }

                friend bool operator ==(const _ProjectionRead__tr_release& o1, const _ProjectionRead__tr_release& o2) {
                    return o1.grants == (o2.grants);
                }

                friend bool operator !=(const _ProjectionRead__tr_release& o1, const _ProjectionRead__tr_release& o2) {
                    return o1.grants != (o2.grants);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_release& e) {
                    strm << "{";
                    strm << "grants: " << e.grants;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (grants.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_release {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_release& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_release& obj1, const _ProjectionWrite_release& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<Nodes, Slots > grants;
                BInteger RT_count;

                _ProjectionWrite_release(const BRelation<Nodes, Slots >& grants, const BInteger& RT_count) {
                    this->grants = grants;
                    this->RT_count = RT_count;
                }

                friend bool operator ==(const _ProjectionWrite_release& o1, const _ProjectionWrite_release& o2) {
                    return o1.grants == (o2.grants) && o1.RT_count == (o2.RT_count);
                }

                friend bool operator !=(const _ProjectionWrite_release& o1, const _ProjectionWrite_release& o2) {
                    return o1.grants != (o2.grants) || o1.RT_count != (o2.RT_count);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_release& e) {
                    strm << "{";
                    strm << "grants: " << e.grants;
                    strm << ", ";
                    strm << "RT_count: " << e.RT_count;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (grants.hashCode() << 1);
                    result = 31 * result + (RT_count.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_grant {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_grant& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_grant& obj1, const _ProjectionRead_grant& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<Nodes, Slots > grants;
                BRelation<Nodes, Slots > open_reservations;
                BInteger RT_count;

                _ProjectionRead_grant(const BRelation<Nodes, Slots >& grants, const BRelation<Nodes, Slots >& open_reservations, const BInteger& RT_count) {
                    this->grants = grants;
                    this->open_reservations = open_reservations;
                    this->RT_count = RT_count;
                }

                friend bool operator ==(const _ProjectionRead_grant& o1, const _ProjectionRead_grant& o2) {
                    return o1.grants == (o2.grants) && o1.open_reservations == (o2.open_reservations) && o1.RT_count == (o2.RT_count);
                }

                friend bool operator !=(const _ProjectionRead_grant& o1, const _ProjectionRead_grant& o2) {
                    return o1.grants != (o2.grants) || o1.open_reservations != (o2.open_reservations) || o1.RT_count != (o2.RT_count);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_grant& e) {
                    strm << "{";
                    strm << "grants: " << e.grants;
                    strm << ", ";
                    strm << "open_reservations: " << e.open_reservations;
                    strm << ", ";
                    strm << "RT_count: " << e.RT_count;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (grants.hashCode() << 1);
                    result = 31 * result + (open_reservations.hashCode() << 1);
                    result = 31 * result + (RT_count.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_grant {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_grant& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_grant& obj1, const _ProjectionRead__tr_grant& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<Nodes, Slots > open_reservations;
                BInteger RT_count;

                _ProjectionRead__tr_grant(const BRelation<Nodes, Slots >& open_reservations, const BInteger& RT_count) {
                    this->open_reservations = open_reservations;
                    this->RT_count = RT_count;
                }

                friend bool operator ==(const _ProjectionRead__tr_grant& o1, const _ProjectionRead__tr_grant& o2) {
                    return o1.open_reservations == (o2.open_reservations) && o1.RT_count == (o2.RT_count);
                }

                friend bool operator !=(const _ProjectionRead__tr_grant& o1, const _ProjectionRead__tr_grant& o2) {
                    return o1.open_reservations != (o2.open_reservations) || o1.RT_count != (o2.RT_count);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_grant& e) {
                    strm << "{";
                    strm << "open_reservations: " << e.open_reservations;
                    strm << ", "; 
                    strm << "RT_count: " << e.RT_count;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (open_reservations.hashCode() << 1);
                    result = 31 * result + (RT_count.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_grant {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_grant& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_grant& obj1, const _ProjectionWrite_grant& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<Nodes, Slots > grants;
                BRelation<Nodes, Slots > open_reservations;
                BInteger RT_count;

                _ProjectionWrite_grant(const BRelation<Nodes, Slots >& grants, const BRelation<Nodes, Slots >& open_reservations, const BInteger& RT_count) {
                    this->grants = grants;
                    this->open_reservations = open_reservations;
                    this->RT_count = RT_count;
                }

                friend bool operator ==(const _ProjectionWrite_grant& o1, const _ProjectionWrite_grant& o2) {
                    return o1.grants == (o2.grants) && o1.open_reservations == (o2.open_reservations) && o1.RT_count == (o2.RT_count);
                }

                friend bool operator !=(const _ProjectionWrite_grant& o1, const _ProjectionWrite_grant& o2) {
                    return o1.grants != (o2.grants) || o1.open_reservations != (o2.open_reservations) || o1.RT_count != (o2.RT_count);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_grant& e) {
                    strm << "{";
                    strm << "grants: " << e.grants;
                    strm << ", ";
                    strm << "open_reservations: " << e.open_reservations;
                    strm << ", ";
                    strm << "RT_count: " << e.RT_count;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (grants.hashCode() << 1);
                    result = 31 * result + (open_reservations.hashCode() << 1);
                    result = 31 * result + (RT_count.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_no_grant {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_no_grant& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_no_grant& obj1, const _ProjectionRead_no_grant& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<Nodes, Slots > open_reservations;

                _ProjectionRead_no_grant(const BRelation<Nodes, Slots >& open_reservations) {
                    this->open_reservations = open_reservations;
                }

                friend bool operator ==(const _ProjectionRead_no_grant& o1, const _ProjectionRead_no_grant& o2) {
                    return o1.open_reservations == (o2.open_reservations);
                }

                friend bool operator !=(const _ProjectionRead_no_grant& o1, const _ProjectionRead_no_grant& o2) {
                    return o1.open_reservations != (o2.open_reservations);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_no_grant& e) {
                    strm << "{";
                    strm << "open_reservations: " << e.open_reservations;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (open_reservations.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_no_grant {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_no_grant& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_no_grant& obj1, const _ProjectionRead__tr_no_grant& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<Nodes, Slots > open_reservations;

                _ProjectionRead__tr_no_grant(const BRelation<Nodes, Slots >& open_reservations) {
                    this->open_reservations = open_reservations;
                }

                friend bool operator ==(const _ProjectionRead__tr_no_grant& o1, const _ProjectionRead__tr_no_grant& o2) {
                    return o1.open_reservations == (o2.open_reservations);
                }

                friend bool operator !=(const _ProjectionRead__tr_no_grant& o1, const _ProjectionRead__tr_no_grant& o2) {
                    return o1.open_reservations != (o2.open_reservations);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_no_grant& e) {
                    strm << "{";
                    strm << "open_reservations: " << e.open_reservations;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (open_reservations.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_no_grant {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_no_grant& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_no_grant& obj1, const _ProjectionWrite_no_grant& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<Nodes, Slots > open_reservations;

                _ProjectionWrite_no_grant(const BRelation<Nodes, Slots >& open_reservations) {
                    this->open_reservations = open_reservations;
                }

                friend bool operator ==(const _ProjectionWrite_no_grant& o1, const _ProjectionWrite_no_grant& o2) {
                    return o1.open_reservations == (o2.open_reservations);
                }

                friend bool operator !=(const _ProjectionWrite_no_grant& o1, const _ProjectionWrite_no_grant& o2) {
                    return o1.open_reservations != (o2.open_reservations);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_no_grant& e) {
                    strm << "{";
                    strm << "open_reservations: " << e.open_reservations;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (open_reservations.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_use_RT_Slot {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_use_RT_Slot& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_use_RT_Slot& obj1, const _ProjectionRead_use_RT_Slot& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<Nodes, Slots > grants;
                Slots time;
                Nodes token;

                _ProjectionRead_use_RT_Slot(const BRelation<Nodes, Slots >& grants, const Slots& time, const Nodes& token) {
                    this->grants = grants;
                    this->time = time;
                    this->token = token;
                }

                friend bool operator ==(const _ProjectionRead_use_RT_Slot& o1, const _ProjectionRead_use_RT_Slot& o2) {
                    return o1.grants == (o2.grants) && o1.time == (o2.time) && o1.token == (o2.token);
                }

                friend bool operator !=(const _ProjectionRead_use_RT_Slot& o1, const _ProjectionRead_use_RT_Slot& o2) {
                    return o1.grants != (o2.grants) || o1.time != (o2.time) || o1.token != (o2.token);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_use_RT_Slot& e) {
                    strm << "{";
                    strm << "grants: " << e.grants;
                    strm << ", ";
                    strm << "time: " << e.time;
                    strm << ", ";
                    strm << "token: " << e.token;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (grants.hashCode() << 1);
                    result = 31 * result + (time.hashCode() << 1);
                    result = 31 * result + (token.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_use_RT_Slot {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_use_RT_Slot& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_use_RT_Slot& obj1, const _ProjectionRead__tr_use_RT_Slot& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<Nodes, Slots > grants;
                Slots time;
                Nodes token;

                _ProjectionRead__tr_use_RT_Slot(const BRelation<Nodes, Slots >& grants, const Slots& time, const Nodes& token) {
                    this->grants = grants;
                    this->time = time;
                    this->token = token;
                }

                friend bool operator ==(const _ProjectionRead__tr_use_RT_Slot& o1, const _ProjectionRead__tr_use_RT_Slot& o2) {
                    return o1.grants == (o2.grants) && o1.time == (o2.time) && o1.token == (o2.token);
                }

                friend bool operator !=(const _ProjectionRead__tr_use_RT_Slot& o1, const _ProjectionRead__tr_use_RT_Slot& o2) {
                    return o1.grants != (o2.grants) || o1.time != (o2.time) || o1.token != (o2.token);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_use_RT_Slot& e) {
                    strm << "{";
                    strm << "grants: " << e.grants;
                    strm << ", "; 
                    strm << "time: " << e.time;
                    strm << ", "; 
                    strm << "token: " << e.token;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (grants.hashCode() << 1);
                    result = 31 * result + (time.hashCode() << 1);
                    result = 31 * result + (token.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_use_RT_Slot {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_use_RT_Slot& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_use_RT_Slot& obj1, const _ProjectionWrite_use_RT_Slot& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };


                _ProjectionWrite_use_RT_Slot() {
                }

                friend bool operator ==(const _ProjectionWrite_use_RT_Slot& o1, const _ProjectionWrite_use_RT_Slot& o2) {
                    return true;
                }

                friend bool operator !=(const _ProjectionWrite_use_RT_Slot& o1, const _ProjectionWrite_use_RT_Slot& o2) {
                    return true;
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_use_RT_Slot& e) {
                    strm << "{";
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    return result;
                }

        };

        class _ProjectionRead_use_NRT_Slot {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_use_NRT_Slot& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_use_NRT_Slot& obj1, const _ProjectionRead_use_NRT_Slot& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<Nodes, Slots > grants;
                Slots time;
                Nodes token;

                _ProjectionRead_use_NRT_Slot(const BRelation<Nodes, Slots >& grants, const Slots& time, const Nodes& token) {
                    this->grants = grants;
                    this->time = time;
                    this->token = token;
                }

                friend bool operator ==(const _ProjectionRead_use_NRT_Slot& o1, const _ProjectionRead_use_NRT_Slot& o2) {
                    return o1.grants == (o2.grants) && o1.time == (o2.time) && o1.token == (o2.token);
                }

                friend bool operator !=(const _ProjectionRead_use_NRT_Slot& o1, const _ProjectionRead_use_NRT_Slot& o2) {
                    return o1.grants != (o2.grants) || o1.time != (o2.time) || o1.token != (o2.token);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_use_NRT_Slot& e) {
                    strm << "{";
                    strm << "grants: " << e.grants;
                    strm << ", ";
                    strm << "time: " << e.time;
                    strm << ", ";
                    strm << "token: " << e.token;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (grants.hashCode() << 1);
                    result = 31 * result + (time.hashCode() << 1);
                    result = 31 * result + (token.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_use_NRT_Slot {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_use_NRT_Slot& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_use_NRT_Slot& obj1, const _ProjectionRead__tr_use_NRT_Slot& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<Nodes, Slots > grants;
                Slots time;
                Nodes token;

                _ProjectionRead__tr_use_NRT_Slot(const BRelation<Nodes, Slots >& grants, const Slots& time, const Nodes& token) {
                    this->grants = grants;
                    this->time = time;
                    this->token = token;
                }

                friend bool operator ==(const _ProjectionRead__tr_use_NRT_Slot& o1, const _ProjectionRead__tr_use_NRT_Slot& o2) {
                    return o1.grants == (o2.grants) && o1.time == (o2.time) && o1.token == (o2.token);
                }

                friend bool operator !=(const _ProjectionRead__tr_use_NRT_Slot& o1, const _ProjectionRead__tr_use_NRT_Slot& o2) {
                    return o1.grants != (o2.grants) || o1.time != (o2.time) || o1.token != (o2.token);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_use_NRT_Slot& e) {
                    strm << "{";
                    strm << "grants: " << e.grants;
                    strm << ", "; 
                    strm << "time: " << e.time;
                    strm << ", "; 
                    strm << "token: " << e.token;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (grants.hashCode() << 1);
                    result = 31 * result + (time.hashCode() << 1);
                    result = 31 * result + (token.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_use_NRT_Slot {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_use_NRT_Slot& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_use_NRT_Slot& obj1, const _ProjectionWrite_use_NRT_Slot& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };


                _ProjectionWrite_use_NRT_Slot() {
                }

                friend bool operator ==(const _ProjectionWrite_use_NRT_Slot& o1, const _ProjectionWrite_use_NRT_Slot& o2) {
                    return true;
                }

                friend bool operator !=(const _ProjectionWrite_use_NRT_Slot& o1, const _ProjectionWrite_use_NRT_Slot& o2) {
                    return true;
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_use_NRT_Slot& e) {
                    strm << "{";
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    return result;
                }

        };

        class _ProjectionRead_pass_token {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_pass_token& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_pass_token& obj1, const _ProjectionRead_pass_token& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                Nodes token;

                _ProjectionRead_pass_token(const Nodes& token) {
                    this->token = token;
                }

                friend bool operator ==(const _ProjectionRead_pass_token& o1, const _ProjectionRead_pass_token& o2) {
                    return o1.token == (o2.token);
                }

                friend bool operator !=(const _ProjectionRead_pass_token& o1, const _ProjectionRead_pass_token& o2) {
                    return o1.token != (o2.token);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_pass_token& e) {
                    strm << "{";
                    strm << "token: " << e.token;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (token.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_pass_token {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_pass_token& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_pass_token& obj1, const _ProjectionRead__tr_pass_token& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                Nodes token;

                _ProjectionRead__tr_pass_token(const Nodes& token) {
                    this->token = token;
                }

                friend bool operator ==(const _ProjectionRead__tr_pass_token& o1, const _ProjectionRead__tr_pass_token& o2) {
                    return o1.token == (o2.token);
                }

                friend bool operator !=(const _ProjectionRead__tr_pass_token& o1, const _ProjectionRead__tr_pass_token& o2) {
                    return o1.token != (o2.token);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_pass_token& e) {
                    strm << "{";
                    strm << "token: " << e.token;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (token.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_pass_token {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_pass_token& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_pass_token& obj1, const _ProjectionWrite_pass_token& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                Nodes token;

                _ProjectionWrite_pass_token(const Nodes& token) {
                    this->token = token;
                }

                friend bool operator ==(const _ProjectionWrite_pass_token& o1, const _ProjectionWrite_pass_token& o2) {
                    return o1.token == (o2.token);
                }

                friend bool operator !=(const _ProjectionWrite_pass_token& o1, const _ProjectionWrite_pass_token& o2) {
                    return o1.token != (o2.token);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_pass_token& e) {
                    strm << "{";
                    strm << "token: " << e.token;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (token.hashCode() << 1);
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

                Slots time;

                _ProjectionRead__check_inv_1(const Slots& time) {
                    this->time = time;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.time == (o2.time);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.time != (o2.time);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_1& e) {
                    strm << "{";
                    strm << "time: " << e.time;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (time.hashCode() << 1);
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

                Nodes token;

                _ProjectionRead__check_inv_2(const Nodes& token) {
                    this->token = token;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_2& o1, const _ProjectionRead__check_inv_2& o2) {
                    return o1.token == (o2.token);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_2& o1, const _ProjectionRead__check_inv_2& o2) {
                    return o1.token != (o2.token);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_2& e) {
                    strm << "{";
                    strm << "token: " << e.token;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (token.hashCode() << 1);
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

                BRelation<Nodes, Slots > open_reservations;

                _ProjectionRead__check_inv_3(const BRelation<Nodes, Slots >& open_reservations) {
                    this->open_reservations = open_reservations;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_3& o1, const _ProjectionRead__check_inv_3& o2) {
                    return o1.open_reservations == (o2.open_reservations);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_3& o1, const _ProjectionRead__check_inv_3& o2) {
                    return o1.open_reservations != (o2.open_reservations);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_3& e) {
                    strm << "{";
                    strm << "open_reservations: " << e.open_reservations;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (open_reservations.hashCode() << 1);
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

                BRelation<Nodes, Slots > grants;

                _ProjectionRead__check_inv_4(const BRelation<Nodes, Slots >& grants) {
                    this->grants = grants;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_4& o1, const _ProjectionRead__check_inv_4& o2) {
                    return o1.grants == (o2.grants);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_4& o1, const _ProjectionRead__check_inv_4& o2) {
                    return o1.grants != (o2.grants);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_4& e) {
                    strm << "{";
                    strm << "grants: " << e.grants;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (grants.hashCode() << 1);
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

                BInteger RT_count;

                _ProjectionRead__check_inv_5(const BInteger& RT_count) {
                    this->RT_count = RT_count;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_5& o1, const _ProjectionRead__check_inv_5& o2) {
                    return o1.RT_count == (o2.RT_count);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_5& o1, const _ProjectionRead__check_inv_5& o2) {
                    return o1.RT_count != (o2.RT_count);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_5& e) {
                    strm << "{";
                    strm << "RT_count: " << e.RT_count;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (RT_count.hashCode() << 1);
                    return result;
                }

        };



    private:

        BSet<Slots > RT_Slots;
        BRelation<Nodes, Nodes > nextNodes;
        BRelation<Slots, Slots > nextSlots;


        #define _Nodes (BSet<Nodes >((Nodes(Nodes::node1)), (Nodes(Nodes::node2)), (Nodes(Nodes::node3)), (Nodes(Nodes::node4)), (Nodes(Nodes::node5))))
        #define _Slots (BSet<Slots >((Slots(Slots::slot1)), (Slots(Slots::slot2)), (Slots(Slots::slot3)), (Slots(Slots::slot4))))

        BInteger RT_count;
        BRelation<Nodes, Slots > grants;
        BRelation<Nodes, Slots > open_reservations;
        Slots time;
        Nodes token;


    public:

        std::string stateAccessedVia;

        rether() {
            RT_Slots = (BSet<Slots >((Slots(Slots::slot1)), (Slots(Slots::slot2))));
            nextNodes = (BRelation<Nodes, Nodes >((BTuple<Nodes, Nodes >((Nodes(Nodes::node1)), (Nodes(Nodes::node2)))), (BTuple<Nodes, Nodes >((Nodes(Nodes::node2)), (Nodes(Nodes::node3)))), (BTuple<Nodes, Nodes >((Nodes(Nodes::node3)), (Nodes(Nodes::node4)))), (BTuple<Nodes, Nodes >((Nodes(Nodes::node4)), (Nodes(Nodes::node1)))), (BTuple<Nodes, Nodes >((Nodes(Nodes::node5)), (Nodes(Nodes::node1))))));
            nextSlots = (BRelation<Slots, Slots >((BTuple<Slots, Slots >((Slots(Slots::slot1)), (Slots(Slots::slot2)))), (BTuple<Slots, Slots >((Slots(Slots::slot2)), (Slots(Slots::slot3)))), (BTuple<Slots, Slots >((Slots(Slots::slot3)), (Slots(Slots::slot1)))), (BTuple<Slots, Slots >((Slots(Slots::slot4)), (Slots(Slots::slot1))))));
            if(!((BBoolean((BBoolean(((nextSlots.checkDomain(_Slots))._and((nextSlots.checkRange(_Slots)))._and((nextSlots.isFunction()))._and((nextSlots.isTotal(_Slots)))).booleanValue() && RT_Slots.strictSubset(_Slots).booleanValue())).booleanValue() && ((nextNodes.checkDomain(_Nodes))._and((nextNodes.checkRange(_Nodes)))._and((nextNodes.isFunction()))._and((nextNodes.isTotal(_Nodes)))).booleanValue()))).booleanValue()) {
                throw std::runtime_error("Contradiction in PROPERTIES detected!");
            }
            time = (Slots(Slots::slot1));
            token = (Nodes(Nodes::node1));
            open_reservations = (BRelation<Nodes, Slots >());
            grants = (BRelation<Nodes, Slots >());
            RT_count = RT_Slots.card();
        }

        rether(const rether& copy) {
            this->RT_Slots = copy.RT_Slots;
            this->nextNodes = copy.nextNodes;
            this->nextSlots = copy.nextSlots;
            this->RT_count = copy.RT_count;
            this->grants = copy.grants;
            this->open_reservations = copy.open_reservations;
            this->time = copy.time;
            this->token = copy.token;
        }

        void elapse_time(const Slots& next, const Slots& slot) {
            time = next;

        }

        void reserve(const Nodes& node, const Slots& slot) {
            open_reservations = open_reservations._union((BRelation<Nodes, Slots >((BTuple<Nodes, Slots >(node, slot)))));

        }

        void release(const Nodes& node, const Slots& slot) {
            BInteger _ld_RT_count = RT_count;
            BRelation<Nodes, Slots > _ld_grants = grants;
            grants = _ld_grants.difference((BRelation<Nodes, Slots >((BTuple<Nodes, Slots >(node, slot)))));
            RT_count = _ld_RT_count.plus((BInteger(1)));

        }

        void grant(const Nodes& node, const Slots& slot) {
            BInteger _ld_RT_count = RT_count;
            BRelation<Nodes, Slots > _ld_grants = grants;
            BRelation<Nodes, Slots > _ld_open_reservations = open_reservations;
            open_reservations = _ld_open_reservations.difference((BRelation<Nodes, Slots >((BTuple<Nodes, Slots >(node, slot)))));
            grants = _ld_grants._union((BRelation<Nodes, Slots >((BTuple<Nodes, Slots >(node, slot)))));
            RT_count = _ld_RT_count.minus((BInteger(1)));

        }

        void no_grant(const Nodes& node, const Slots& slot) {
            open_reservations = open_reservations.difference((BRelation<Nodes, Slots >((BTuple<Nodes, Slots >(node, slot)))));

        }

        void use_RT_Slot(const Nodes& node, const Slots& slot) {
        }

        void use_NRT_Slot(const Nodes& node, const Slots& slot) {
        }

        void pass_token(const Nodes& node) {
            token = nextNodes.functionCall(node);

        }

        BSet<Slots > _get_RT_Slots() const {
            return RT_Slots;
        }

        BRelation<Nodes, Nodes > _get_nextNodes() const {
            return nextNodes;
        }

        BRelation<Slots, Slots > _get_nextSlots() const {
            return nextSlots;
        }

        BInteger _get_RT_count() const {
            return RT_count;
        }

        BRelation<Nodes, Slots > _get_grants() const {
            return grants;
        }

        BRelation<Nodes, Slots > _get_open_reservations() const {
            return open_reservations;
        }

        Slots _get_time() const {
            return time;
        }

        Nodes _get_token() const {
            return token;
        }

        BSet<Nodes > _get__Nodes() const {
            return _Nodes;
        }

        BSet<Slots > _get__Slots() const {
            return _Slots;
        }


        BSet<BTuple<Slots, Slots >> _tr_elapse_time() const {
            BSet<BTuple<Slots, Slots >> _ic_set_0 = BSet<BTuple<Slots, Slots >>();
            for(const Slots& _ic_next_1 : _Slots) {
                for(const Slots& _ic_slot_1 : _Slots) {
                    if(((BBoolean(nextSlots.elementOf((BTuple<Slots, Slots >(_ic_slot_1, _ic_next_1))).booleanValue() && _ic_slot_1.equal(time).booleanValue()))).booleanValue()) {
                        _ic_set_0 = _ic_set_0._union(BSet<BTuple<Slots, Slots >>((BTuple<Slots, Slots >(_ic_next_1, _ic_slot_1))));
                    }

                }

            }

            return _ic_set_0;
        }

        BSet<BTuple<Nodes, Slots >> _tr_reserve() const {
            BSet<BTuple<Nodes, Slots >> _ic_set_1 = BSet<BTuple<Nodes, Slots >>();
            for(const Nodes& _ic_node_1 : _Nodes) {
                for(const Slots& _ic_slot_1 : _Slots) {
                    if(((BBoolean((BBoolean((BBoolean((BBoolean((open_reservations.isNotInDomain(_ic_node_1)).booleanValue() && (open_reservations.isNotInRange(_ic_slot_1)).booleanValue())).booleanValue() && open_reservations.notElementOf((BTuple<Nodes, Slots >(_ic_node_1, _ic_slot_1))).booleanValue())).booleanValue() && (grants.isNotInDomain(_ic_node_1)).booleanValue())).booleanValue() && (grants.isNotInRange(_ic_slot_1)).booleanValue()))).booleanValue()) {
                        _ic_set_1 = _ic_set_1._union(BSet<BTuple<Nodes, Slots >>((BTuple<Nodes, Slots >(_ic_node_1, _ic_slot_1))));
                    }

                }

            }

            return _ic_set_1;
        }

        BSet<BTuple<Nodes, Slots >> _tr_release() const {
            BSet<BTuple<Nodes, Slots >> _ic_set_2 = BSet<BTuple<Nodes, Slots >>();
            for(const Nodes& _ic_node_1 : _Nodes) {
                for(const Slots& _ic_slot_1 : _Slots) {
                    if((grants.elementOf((BTuple<Nodes, Slots >(_ic_node_1, _ic_slot_1)))).booleanValue()) {
                        _ic_set_2 = _ic_set_2._union(BSet<BTuple<Nodes, Slots >>((BTuple<Nodes, Slots >(_ic_node_1, _ic_slot_1))));
                    }

                }

            }

            return _ic_set_2;
        }

        BSet<BTuple<Nodes, Slots >> _tr_grant() const {
            BSet<BTuple<Nodes, Slots >> _ic_set_3 = BSet<BTuple<Nodes, Slots >>();
            for(const Nodes& _ic_node_1 : _Nodes) {
                for(const Slots& _ic_slot_1 : _Slots) {
                    if(((BBoolean((BBoolean((BBoolean((open_reservations.isInDomain(_ic_node_1)).booleanValue() && (open_reservations.isInRange(_ic_slot_1)).booleanValue())).booleanValue() && open_reservations.elementOf((BTuple<Nodes, Slots >(_ic_node_1, _ic_slot_1))).booleanValue())).booleanValue() && RT_count.greater((BInteger(0))).booleanValue()))).booleanValue()) {
                        _ic_set_3 = _ic_set_3._union(BSet<BTuple<Nodes, Slots >>((BTuple<Nodes, Slots >(_ic_node_1, _ic_slot_1))));
                    }

                }

            }

            return _ic_set_3;
        }

        BSet<BTuple<Nodes, Slots >> _tr_no_grant() const {
            BSet<BTuple<Nodes, Slots >> _ic_set_4 = BSet<BTuple<Nodes, Slots >>();
            for(const Nodes& _ic_node_1 : _Nodes) {
                for(const Slots& _ic_slot_1 : _Slots) {
                    if(((BBoolean((BBoolean((open_reservations.isInDomain(_ic_node_1)).booleanValue() && (open_reservations.isInRange(_ic_slot_1)).booleanValue())).booleanValue() && open_reservations.elementOf((BTuple<Nodes, Slots >(_ic_node_1, _ic_slot_1))).booleanValue()))).booleanValue()) {
                        _ic_set_4 = _ic_set_4._union(BSet<BTuple<Nodes, Slots >>((BTuple<Nodes, Slots >(_ic_node_1, _ic_slot_1))));
                    }

                }

            }

            return _ic_set_4;
        }

        BSet<BTuple<Nodes, Slots >> _tr_use_RT_Slot() const {
            BSet<BTuple<Nodes, Slots >> _ic_set_5 = BSet<BTuple<Nodes, Slots >>();
            for(const Nodes& _ic_node_1 : _Nodes) {
                for(const Slots& _ic_slot_1 : _Slots) {
                    if(((BBoolean((BBoolean(grants.elementOf((BTuple<Nodes, Slots >(_ic_node_1, _ic_slot_1))).booleanValue() && _ic_slot_1.equal(time).booleanValue())).booleanValue() && _ic_node_1.equal(token).booleanValue()))).booleanValue()) {
                        _ic_set_5 = _ic_set_5._union(BSet<BTuple<Nodes, Slots >>((BTuple<Nodes, Slots >(_ic_node_1, _ic_slot_1))));
                    }

                }

            }

            return _ic_set_5;
        }

        BSet<BTuple<Nodes, Slots >> _tr_use_NRT_Slot() const {
            BSet<BTuple<Nodes, Slots >> _ic_set_6 = BSet<BTuple<Nodes, Slots >>();
            for(const Nodes& _ic_node_1 : _Nodes) {
                for(const Slots& _ic_slot_1 : _Slots) {
                    if(((BBoolean((BBoolean((BBoolean((BBoolean(grants.notElementOf((BTuple<Nodes, Slots >(_ic_node_1, _ic_slot_1))).booleanValue() && _ic_slot_1.equal(time).booleanValue())).booleanValue() && (grants.isNotInDomain(_ic_node_1)).booleanValue())).booleanValue() && (grants.isNotInRange(_ic_slot_1)).booleanValue())).booleanValue() && _ic_node_1.equal(token).booleanValue()))).booleanValue()) {
                        _ic_set_6 = _ic_set_6._union(BSet<BTuple<Nodes, Slots >>((BTuple<Nodes, Slots >(_ic_node_1, _ic_slot_1))));
                    }

                }

            }

            return _ic_set_6;
        }

        BSet<Nodes> _tr_pass_token() const {
            BSet<Nodes> _ic_set_7 = BSet<Nodes>();
            for(const Nodes& _ic_node_1 : _Nodes) {
                if((_ic_node_1.equal(token)).booleanValue()) {
                    _ic_set_7 = _ic_set_7._union(BSet<Nodes>(_ic_node_1));
                }

            }

            return _ic_set_7;
        }

        _ProjectionRead_release _projected_state_for_release() const {
            return _ProjectionRead_release(grants,RT_count);
        }

        _ProjectionRead_reserve _projected_state_for_reserve() const {
            return _ProjectionRead_reserve(grants,open_reservations);
        }

        _ProjectionRead_use_RT_Slot _projected_state_for_use_RT_Slot() const {
            return _ProjectionRead_use_RT_Slot(grants,time,token);
        }

        _ProjectionRead_use_NRT_Slot _projected_state_for_use_NRT_Slot() const {
            return _ProjectionRead_use_NRT_Slot(grants,time,token);
        }

        _ProjectionRead_elapse_time _projected_state_for_elapse_time() const {
            return _ProjectionRead_elapse_time(time);
        }

        _ProjectionRead_grant _projected_state_for_grant() const {
            return _ProjectionRead_grant(grants,open_reservations,RT_count);
        }

        _ProjectionRead_no_grant _projected_state_for_no_grant() const {
            return _ProjectionRead_no_grant(open_reservations);
        }

        _ProjectionRead_pass_token _projected_state_for_pass_token() const {
            return _ProjectionRead_pass_token(token);
        }

        _ProjectionRead__tr_pass_token _projected_state_for__tr_pass_token() const {
            return _ProjectionRead__tr_pass_token(token);
        }

        _ProjectionRead__tr_elapse_time _projected_state_for__tr_elapse_time() const {
            return _ProjectionRead__tr_elapse_time(time);
        }

        _ProjectionRead__tr_use_NRT_Slot _projected_state_for__tr_use_NRT_Slot() const {
            return _ProjectionRead__tr_use_NRT_Slot(grants,time,token);
        }

        _ProjectionRead__tr_reserve _projected_state_for__tr_reserve() const {
            return _ProjectionRead__tr_reserve(grants,open_reservations);
        }

        _ProjectionRead__tr_no_grant _projected_state_for__tr_no_grant() const {
            return _ProjectionRead__tr_no_grant(open_reservations);
        }

        _ProjectionRead__tr_release _projected_state_for__tr_release() const {
            return _ProjectionRead__tr_release(grants);
        }

        _ProjectionRead__tr_grant _projected_state_for__tr_grant() const {
            return _ProjectionRead__tr_grant(open_reservations,RT_count);
        }

        _ProjectionRead__tr_use_RT_Slot _projected_state_for__tr_use_RT_Slot() const {
            return _ProjectionRead__tr_use_RT_Slot(grants,time,token);
        }

        _ProjectionRead__check_inv_2 _projected_state_for__check_inv_2() const {
            return _ProjectionRead__check_inv_2(token);
        }

        _ProjectionRead__check_inv_3 _projected_state_for__check_inv_3() const {
            return _ProjectionRead__check_inv_3(open_reservations);
        }

        _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() const {
            return _ProjectionRead__check_inv_1(time);
        }

        _ProjectionRead__check_inv_4 _projected_state_for__check_inv_4() const {
            return _ProjectionRead__check_inv_4(grants);
        }

        _ProjectionRead__check_inv_5 _projected_state_for__check_inv_5() const {
            return _ProjectionRead__check_inv_5(RT_count);
        }

        _ProjectionWrite_release _update_for_release() const {
            return _ProjectionWrite_release(grants,RT_count);
        }

        _ProjectionWrite_reserve _update_for_reserve() const {
            return _ProjectionWrite_reserve(open_reservations);
        }

        _ProjectionWrite_use_RT_Slot _update_for_use_RT_Slot() const {
            return _ProjectionWrite_use_RT_Slot();
        }

        _ProjectionWrite_use_NRT_Slot _update_for_use_NRT_Slot() const {
            return _ProjectionWrite_use_NRT_Slot();
        }

        _ProjectionWrite_elapse_time _update_for_elapse_time() const {
            return _ProjectionWrite_elapse_time(time);
        }

        _ProjectionWrite_grant _update_for_grant() const {
            return _ProjectionWrite_grant(grants,open_reservations,RT_count);
        }

        _ProjectionWrite_no_grant _update_for_no_grant() const {
            return _ProjectionWrite_no_grant(open_reservations);
        }

        _ProjectionWrite_pass_token _update_for_pass_token() const {
            return _ProjectionWrite_pass_token(token);
        }

        void _apply_update_for_release(const _ProjectionWrite_release& update) {
            this->grants = update.grants;
            this->RT_count = update.RT_count;
        }

        void _apply_update_for_reserve(const _ProjectionWrite_reserve& update) {
            this->open_reservations = update.open_reservations;
        }

        void _apply_update_for_use_RT_Slot(const _ProjectionWrite_use_RT_Slot& update) {
        }

        void _apply_update_for_use_NRT_Slot(const _ProjectionWrite_use_NRT_Slot& update) {
        }

        void _apply_update_for_elapse_time(const _ProjectionWrite_elapse_time& update) {
            this->time = update.time;
        }

        void _apply_update_for_grant(const _ProjectionWrite_grant& update) {
            this->grants = update.grants;
            this->open_reservations = update.open_reservations;
            this->RT_count = update.RT_count;
        }

        void _apply_update_for_no_grant(const _ProjectionWrite_no_grant& update) {
            this->open_reservations = update.open_reservations;
        }

        void _apply_update_for_pass_token(const _ProjectionWrite_pass_token& update) {
            this->token = update.token;
        }

        bool _check_inv_1() const {
            return (_Slots.elementOf(time)).booleanValue();
        }

        bool _check_inv_2() const {
            return (_Nodes.elementOf(token)).booleanValue();
        }

        bool _check_inv_3() const {
            return (((open_reservations.checkDomain(_Nodes))._and((open_reservations.checkRange(_Slots)))._and((open_reservations.isFunction()))._and((open_reservations.isPartial(_Nodes))))).booleanValue();
        }

        bool _check_inv_4() const {
            return (((grants.checkDomain(_Nodes))._and((grants.checkRange(_Slots)))._and((grants.isFunction()))._and((grants.isPartial(_Nodes))))).booleanValue();
        }

        bool _check_inv_5() const {
            return ((BBoolean(RT_count.greaterEqual((BInteger(0))).booleanValue() && RT_count.lessEqual((BInteger(2147483647))).booleanValue()))).booleanValue();
        }

        rether _copy() const {
            return rether(*this);
        }

        friend bool operator ==(const rether& o1, const rether& o2) {
            return o1._get_RT_count() == o2._get_RT_count() && o1._get_grants() == o2._get_grants() && o1._get_open_reservations() == o2._get_open_reservations() && o1._get_time() == o2._get_time() && o1._get_token() == o2._get_token();
        }

        friend bool operator !=(const rether& o1, const rether& o2) {
            return o1._get_RT_count() != o2._get_RT_count() || o1._get_grants() != o2._get_grants() || o1._get_open_reservations() != o2._get_open_reservations() || o1._get_time() != o2._get_time() || o1._get_token() != o2._get_token();
        }

        int hashCode() const {
            return this->_hashCode_1();
        }

        int _hashCode_1() const {
            int result = 1;
            result = (1543 * result) ^ ((this->_get_RT_count()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_grants()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_open_reservations()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_time()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_token()).hashCode() << 1);
            return result;
        }

        int _hashCode_2() const {
            int result = 1;
            result = (6151 * result) ^ ((this->_get_RT_count()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_grants()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_open_reservations()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_time()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_token()).hashCode() << 1);
            return result;
        }

        friend std::ostream& operator<<(std::ostream &strm, const rether& machine) {
          strm << "_get_RT_count: " << machine._get_RT_count() << "\n";
          strm << "_get_grants: " << machine._get_grants() << "\n";
          strm << "_get_open_reservations: " << machine._get_open_reservations() << "\n";
          strm << "_get_time: " << machine._get_time() << "\n";
          strm << "_get_token: " << machine._get_token() << "\n";
          return strm;
        }


};


class ModelChecker {
    private:
        rether::Type type;
        int threads;
        bool isCaching;
        bool isDebug;

        std::list<rether> unvisitedStates;
        std::unordered_set<rether, rether::Hash, rether::HashEqual> states;
        std::atomic<int> transitions;
        std::mutex mutex;
        std::mutex waitMutex;
        std::mutex cacheMutex;
        std::condition_variable waitCV;

        std::atomic<bool> invariantViolatedBool;
        std::atomic<bool> deadlockDetected;
        rether counterExampleState;

        std::unordered_map<BSet<BTuple<rether::Slots, rether::Slots >>, std::unordered_map<rether::_ProjectionRead_elapse_time, rether::_ProjectionWrite_elapse_time, rether::_ProjectionRead_elapse_time::Hash, rether::_ProjectionRead_elapse_time::HashEqual>, BSet<BTuple<rether::Slots, rether::Slots >>::SetHash, BSet<BTuple<rether::Slots, rether::Slots >>::SetHashEqual> _OpCache_elapse_time;
        std::unordered_map<rether::_ProjectionRead__tr_elapse_time,  BSet<BTuple<rether::Slots, rether::Slots >>, rether::_ProjectionRead__tr_elapse_time::Hash, rether::_ProjectionRead__tr_elapse_time::HashEqual> _OpCache_tr_elapse_time;
        std::mutex _ProjectionRead_elapse_time_mutex;
        std::mutex _ProjectionRead__tr_elapse_time_mutex;

        std::unordered_map<BSet<BTuple<rether::Nodes, rether::Slots >>, std::unordered_map<rether::_ProjectionRead_reserve, rether::_ProjectionWrite_reserve, rether::_ProjectionRead_reserve::Hash, rether::_ProjectionRead_reserve::HashEqual>, BSet<BTuple<rether::Nodes, rether::Slots >>::SetHash, BSet<BTuple<rether::Nodes, rether::Slots >>::SetHashEqual> _OpCache_reserve;
        std::unordered_map<rether::_ProjectionRead__tr_reserve,  BSet<BTuple<rether::Nodes, rether::Slots >>, rether::_ProjectionRead__tr_reserve::Hash, rether::_ProjectionRead__tr_reserve::HashEqual> _OpCache_tr_reserve;
        std::mutex _ProjectionRead_reserve_mutex;
        std::mutex _ProjectionRead__tr_reserve_mutex;

        std::unordered_map<BSet<BTuple<rether::Nodes, rether::Slots >>, std::unordered_map<rether::_ProjectionRead_release, rether::_ProjectionWrite_release, rether::_ProjectionRead_release::Hash, rether::_ProjectionRead_release::HashEqual>, BSet<BTuple<rether::Nodes, rether::Slots >>::SetHash, BSet<BTuple<rether::Nodes, rether::Slots >>::SetHashEqual> _OpCache_release;
        std::unordered_map<rether::_ProjectionRead__tr_release,  BSet<BTuple<rether::Nodes, rether::Slots >>, rether::_ProjectionRead__tr_release::Hash, rether::_ProjectionRead__tr_release::HashEqual> _OpCache_tr_release;
        std::mutex _ProjectionRead_release_mutex;
        std::mutex _ProjectionRead__tr_release_mutex;

        std::unordered_map<BSet<BTuple<rether::Nodes, rether::Slots >>, std::unordered_map<rether::_ProjectionRead_grant, rether::_ProjectionWrite_grant, rether::_ProjectionRead_grant::Hash, rether::_ProjectionRead_grant::HashEqual>, BSet<BTuple<rether::Nodes, rether::Slots >>::SetHash, BSet<BTuple<rether::Nodes, rether::Slots >>::SetHashEqual> _OpCache_grant;
        std::unordered_map<rether::_ProjectionRead__tr_grant,  BSet<BTuple<rether::Nodes, rether::Slots >>, rether::_ProjectionRead__tr_grant::Hash, rether::_ProjectionRead__tr_grant::HashEqual> _OpCache_tr_grant;
        std::mutex _ProjectionRead_grant_mutex;
        std::mutex _ProjectionRead__tr_grant_mutex;

        std::unordered_map<BSet<BTuple<rether::Nodes, rether::Slots >>, std::unordered_map<rether::_ProjectionRead_no_grant, rether::_ProjectionWrite_no_grant, rether::_ProjectionRead_no_grant::Hash, rether::_ProjectionRead_no_grant::HashEqual>, BSet<BTuple<rether::Nodes, rether::Slots >>::SetHash, BSet<BTuple<rether::Nodes, rether::Slots >>::SetHashEqual> _OpCache_no_grant;
        std::unordered_map<rether::_ProjectionRead__tr_no_grant,  BSet<BTuple<rether::Nodes, rether::Slots >>, rether::_ProjectionRead__tr_no_grant::Hash, rether::_ProjectionRead__tr_no_grant::HashEqual> _OpCache_tr_no_grant;
        std::mutex _ProjectionRead_no_grant_mutex;
        std::mutex _ProjectionRead__tr_no_grant_mutex;

        std::unordered_map<BSet<BTuple<rether::Nodes, rether::Slots >>, std::unordered_map<rether::_ProjectionRead_use_RT_Slot, rether::_ProjectionWrite_use_RT_Slot, rether::_ProjectionRead_use_RT_Slot::Hash, rether::_ProjectionRead_use_RT_Slot::HashEqual>, BSet<BTuple<rether::Nodes, rether::Slots >>::SetHash, BSet<BTuple<rether::Nodes, rether::Slots >>::SetHashEqual> _OpCache_use_RT_Slot;
        std::unordered_map<rether::_ProjectionRead__tr_use_RT_Slot,  BSet<BTuple<rether::Nodes, rether::Slots >>, rether::_ProjectionRead__tr_use_RT_Slot::Hash, rether::_ProjectionRead__tr_use_RT_Slot::HashEqual> _OpCache_tr_use_RT_Slot;
        std::mutex _ProjectionRead_use_RT_Slot_mutex;
        std::mutex _ProjectionRead__tr_use_RT_Slot_mutex;

        std::unordered_map<BSet<BTuple<rether::Nodes, rether::Slots >>, std::unordered_map<rether::_ProjectionRead_use_NRT_Slot, rether::_ProjectionWrite_use_NRT_Slot, rether::_ProjectionRead_use_NRT_Slot::Hash, rether::_ProjectionRead_use_NRT_Slot::HashEqual>, BSet<BTuple<rether::Nodes, rether::Slots >>::SetHash, BSet<BTuple<rether::Nodes, rether::Slots >>::SetHashEqual> _OpCache_use_NRT_Slot;
        std::unordered_map<rether::_ProjectionRead__tr_use_NRT_Slot,  BSet<BTuple<rether::Nodes, rether::Slots >>, rether::_ProjectionRead__tr_use_NRT_Slot::Hash, rether::_ProjectionRead__tr_use_NRT_Slot::HashEqual> _OpCache_tr_use_NRT_Slot;
        std::mutex _ProjectionRead_use_NRT_Slot_mutex;
        std::mutex _ProjectionRead__tr_use_NRT_Slot_mutex;

        std::unordered_map<BSet<rether::Nodes>, std::unordered_map<rether::_ProjectionRead_pass_token, rether::_ProjectionWrite_pass_token, rether::_ProjectionRead_pass_token::Hash, rether::_ProjectionRead_pass_token::HashEqual>, BSet<rether::Nodes>::SetHash, BSet<rether::Nodes>::SetHashEqual> _OpCache_pass_token;
        std::unordered_map<rether::_ProjectionRead__tr_pass_token,  BSet<rether::Nodes>, rether::_ProjectionRead__tr_pass_token::Hash, rether::_ProjectionRead__tr_pass_token::HashEqual> _OpCache_tr_pass_token;
        std::mutex _ProjectionRead_pass_token_mutex;
        std::mutex _ProjectionRead__tr_pass_token_mutex;

        std::unordered_map<rether::_ProjectionRead__check_inv_1, bool, rether::_ProjectionRead__check_inv_1::Hash, rether::_ProjectionRead__check_inv_1::HashEqual> _InvCache__check_inv_1;
        std::mutex _ProjectionRead__check_inv_1_mutex;
        std::unordered_map<rether::_ProjectionRead__check_inv_2, bool, rether::_ProjectionRead__check_inv_2::Hash, rether::_ProjectionRead__check_inv_2::HashEqual> _InvCache__check_inv_2;
        std::mutex _ProjectionRead__check_inv_2_mutex;
        std::unordered_map<rether::_ProjectionRead__check_inv_3, bool, rether::_ProjectionRead__check_inv_3::Hash, rether::_ProjectionRead__check_inv_3::HashEqual> _InvCache__check_inv_3;
        std::mutex _ProjectionRead__check_inv_3_mutex;
        std::unordered_map<rether::_ProjectionRead__check_inv_4, bool, rether::_ProjectionRead__check_inv_4::Hash, rether::_ProjectionRead__check_inv_4::HashEqual> _InvCache__check_inv_4;
        std::mutex _ProjectionRead__check_inv_4_mutex;
        std::unordered_map<rether::_ProjectionRead__check_inv_5, bool, rether::_ProjectionRead__check_inv_5::Hash, rether::_ProjectionRead__check_inv_5::HashEqual> _InvCache__check_inv_5;
        std::mutex _ProjectionRead__check_inv_5_mutex;

        std::unordered_map<rether, rether, rether::Hash, rether::HashEqual> parents;

    public:
        ModelChecker() {}

        ModelChecker(rether::Type type, int threads, bool isCaching, bool isDebug) {
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
            rether machine = rether();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            while(!unvisitedStates.empty()) {
                rether state = next();

                std::unordered_set<rether, rether::Hash, rether::HashEqual> nextStates = generateNextStates(state);

                for(const rether& nextState : nextStates) {
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
            rether machine = rether();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            std::atomic<bool> stopThreads;
            stopThreads = false;
            std::atomic<int> possibleQueueChanges;
            possibleQueueChanges = 0;

            std::atomic<bool> waitFlag;
            waitFlag = true;

            while(!unvisitedStates.empty() && !stopThreads) {
                possibleQueueChanges += 1;
                rether state = next();
                std::packaged_task<void()> task([&, state] {
                    std::unordered_set<rether, rether::Hash, rether::HashEqual> nextStates = generateNextStates(state);

                    for(const rether& nextState : nextStates) {
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

                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        possibleQueueChanges -= 1;
                        int running = possibleQueueChanges;
                        if (!unvisitedStates.empty() || running == 0) {
                            {
                                std::unique_lock<std::mutex> lock(waitMutex);
                                waitFlag = false;
                                waitCV.notify_one();
                            }
                        }
                    }


                    if(invariantViolated(state)) {
                        invariantViolatedBool = true;
                        counterExampleState = state;
                        stopThreads = true;
                    }

                    if(nextStates.empty()) {
                        deadlockDetected = true;
                        counterExampleState = state;
                        stopThreads = true;
                    }

                });

                waitFlag = true;
                boost::asio::post(workers, std::move(task));

                {
                    std::unique_lock<std::mutex> lock(waitMutex);
                    if(unvisitedStates.empty() && possibleQueueChanges > 0) {
                        waitCV.wait(lock, [&] {
                            return waitFlag == false;
                        });
                    }
                }
            }
            workers.join();
            printResult();
        }


    private:
        rether next() {
            {
                std::unique_lock<std::mutex> lock(mutex);
                switch(type) {
                    case rether::BFS: {
                        rether state = unvisitedStates.front();
                        unvisitedStates.pop_front();
                        return state;
                    }
                    case rether::DFS: {
                        rether state = unvisitedStates.back();
                        unvisitedStates.pop_back();
                        return state;
                    }
                    case rether::MIXED: {
                        if(unvisitedStates.size() % 2 == 0) {
                            rether state = unvisitedStates.front();
                            unvisitedStates.pop_front();
                            return state;
                        } else {
                            rether state = unvisitedStates.back();
                            unvisitedStates.pop_back();
                            return state;
                        }
                    }
                }
                rether state = unvisitedStates.front();
                unvisitedStates.pop_front();
                return state;
            };
        }

        std::unordered_set<rether, rether::Hash, rether::HashEqual> generateNextStates(const rether& state) {
            std::unordered_set<rether, rether::Hash, rether::HashEqual> result = std::unordered_set<rether, rether::Hash, rether::HashEqual>();
            if(isCaching) {
                rether::_ProjectionRead__tr_elapse_time read__tr_elapse_time_state = state._projected_state_for__tr_elapse_time();
                {
                    std::unique_lock<std::mutex> _ProjectionRead__tr_elapse_time_lock(_ProjectionRead__tr_elapse_time_mutex);
                    auto _trid_1_ptr = _OpCache_tr_elapse_time.find(read__tr_elapse_time_state);
                    if(_trid_1_ptr == _OpCache_tr_elapse_time.end()) {
                        BSet<BTuple<rether::Slots, rether::Slots >> _trid_1 = state._tr_elapse_time();
                        _OpCache_tr_elapse_time.insert({read__tr_elapse_time_state, _trid_1});
                        for(const BTuple<rether::Slots, rether::Slots >& param : _trid_1) {
                            rether::Slots _tmp_1 = param.projection2();
                            rether::Slots _tmp_2 = param.projection1();

                            rether copiedState = state._copy();
                            rether::_ProjectionRead_elapse_time readState = state._projected_state_for_elapse_time();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_elapse_time_lock(_ProjectionRead_elapse_time_mutex);
                                auto _OpCache_with_parameter_elapse_time_ptr = _OpCache_elapse_time.find(param);
                                if(_OpCache_with_parameter_elapse_time_ptr == _OpCache_elapse_time.end()) {
                                    copiedState.elapse_time(_tmp_2, _tmp_1);
                                    rether::_ProjectionWrite_elapse_time writeState = copiedState._update_for_elapse_time();
                                    std::unordered_map<rether::_ProjectionRead_elapse_time, rether::_ProjectionWrite_elapse_time, rether::_ProjectionRead_elapse_time::Hash, rether::_ProjectionRead_elapse_time::HashEqual> _OpCache_with_parameter_elapse_time = std::unordered_map<rether::_ProjectionRead_elapse_time, rether::_ProjectionWrite_elapse_time, rether::_ProjectionRead_elapse_time::Hash, rether::_ProjectionRead_elapse_time::HashEqual>();
                                    _OpCache_with_parameter_elapse_time.insert({readState, writeState});
                                    _OpCache_elapse_time.insert({param, _OpCache_with_parameter_elapse_time});
                                } else {
                                    std::unordered_map<rether::_ProjectionRead_elapse_time, rether::_ProjectionWrite_elapse_time, rether::_ProjectionRead_elapse_time::Hash, rether::_ProjectionRead_elapse_time::HashEqual> _OpCache_with_parameter_elapse_time = _OpCache_with_parameter_elapse_time_ptr->second;
                                    auto writeState_ptr = _OpCache_with_parameter_elapse_time.find(readState);
                                    if(writeState_ptr != _OpCache_with_parameter_elapse_time.end()) {
                                        rether::_ProjectionWrite_elapse_time writeState = writeState_ptr->second;
                                        copiedState._apply_update_for_elapse_time(writeState);
                                    } else {
                                        copiedState.elapse_time(_tmp_2, _tmp_1);
                                        rether::_ProjectionWrite_elapse_time writeState = copiedState._update_for_elapse_time();
                                        _OpCache_with_parameter_elapse_time.insert({readState, writeState});
                                    }
                                }
                            }
                            copiedState.stateAccessedVia = "elapse_time";
                            result.insert(copiedState);
                            {
                                std::unique_lock<std::mutex> lock(mutex);
                                transitions += 1;
                            }
                        }
                    } else {
                        BSet<BTuple<rether::Slots, rether::Slots >> _trid_1 = _trid_1_ptr->second;
                        for(const BTuple<rether::Slots, rether::Slots >& param : _trid_1) {
                            rether::Slots _tmp_1 = param.projection2();
                            rether::Slots _tmp_2 = param.projection1();

                            rether copiedState = state._copy();
                            rether::_ProjectionRead_elapse_time readState = state._projected_state_for_elapse_time();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_elapse_time_lock(_ProjectionRead_elapse_time_mutex);
                                auto _OpCache_with_parameter_elapse_time_ptr = _OpCache_elapse_time.find(param);
                                if(_OpCache_with_parameter_elapse_time_ptr == _OpCache_elapse_time.end()) {
                                    copiedState.elapse_time(_tmp_2, _tmp_1);
                                    rether::_ProjectionWrite_elapse_time writeState = copiedState._update_for_elapse_time();
                                    std::unordered_map<rether::_ProjectionRead_elapse_time, rether::_ProjectionWrite_elapse_time, rether::_ProjectionRead_elapse_time::Hash, rether::_ProjectionRead_elapse_time::HashEqual> _OpCache_with_parameter_elapse_time = std::unordered_map<rether::_ProjectionRead_elapse_time, rether::_ProjectionWrite_elapse_time, rether::_ProjectionRead_elapse_time::Hash, rether::_ProjectionRead_elapse_time::HashEqual>();
                                    _OpCache_with_parameter_elapse_time.insert({readState, writeState});
                                    _OpCache_elapse_time.insert({param, _OpCache_with_parameter_elapse_time});
                                } else {
                                    std::unordered_map<rether::_ProjectionRead_elapse_time, rether::_ProjectionWrite_elapse_time, rether::_ProjectionRead_elapse_time::Hash, rether::_ProjectionRead_elapse_time::HashEqual> _OpCache_with_parameter_elapse_time = _OpCache_with_parameter_elapse_time_ptr->second;
                                    auto writeState_ptr = _OpCache_with_parameter_elapse_time.find(readState);
                                    if(writeState_ptr != _OpCache_with_parameter_elapse_time.end()) {
                                        rether::_ProjectionWrite_elapse_time writeState = writeState_ptr->second;
                                        copiedState._apply_update_for_elapse_time(writeState);
                                    } else {
                                        copiedState.elapse_time(_tmp_2, _tmp_1);
                                        rether::_ProjectionWrite_elapse_time writeState = copiedState._update_for_elapse_time();
                                        _OpCache_with_parameter_elapse_time.insert({readState, writeState});
                                    }
                                }
                            }
                            copiedState.stateAccessedVia = "elapse_time";
                            result.insert(copiedState);
                            {
                                std::unique_lock<std::mutex> lock(mutex);
                                transitions += 1;
                            }
                        }
                    }
                }
                rether::_ProjectionRead__tr_reserve read__tr_reserve_state = state._projected_state_for__tr_reserve();
                {
                    std::unique_lock<std::mutex> _ProjectionRead__tr_reserve_lock(_ProjectionRead__tr_reserve_mutex);
                    auto _trid_2_ptr = _OpCache_tr_reserve.find(read__tr_reserve_state);
                    if(_trid_2_ptr == _OpCache_tr_reserve.end()) {
                        BSet<BTuple<rether::Nodes, rether::Slots >> _trid_2 = state._tr_reserve();
                        _OpCache_tr_reserve.insert({read__tr_reserve_state, _trid_2});
                        for(const BTuple<rether::Nodes, rether::Slots >& param : _trid_2) {
                            rether::Slots _tmp_1 = param.projection2();
                            rether::Nodes _tmp_2 = param.projection1();

                            rether copiedState = state._copy();
                            rether::_ProjectionRead_reserve readState = state._projected_state_for_reserve();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_reserve_lock(_ProjectionRead_reserve_mutex);
                                auto _OpCache_with_parameter_reserve_ptr = _OpCache_reserve.find(param);
                                if(_OpCache_with_parameter_reserve_ptr == _OpCache_reserve.end()) {
                                    copiedState.reserve(_tmp_2, _tmp_1);
                                    rether::_ProjectionWrite_reserve writeState = copiedState._update_for_reserve();
                                    std::unordered_map<rether::_ProjectionRead_reserve, rether::_ProjectionWrite_reserve, rether::_ProjectionRead_reserve::Hash, rether::_ProjectionRead_reserve::HashEqual> _OpCache_with_parameter_reserve = std::unordered_map<rether::_ProjectionRead_reserve, rether::_ProjectionWrite_reserve, rether::_ProjectionRead_reserve::Hash, rether::_ProjectionRead_reserve::HashEqual>();
                                    _OpCache_with_parameter_reserve.insert({readState, writeState});
                                    _OpCache_reserve.insert({param, _OpCache_with_parameter_reserve});
                                } else {
                                    std::unordered_map<rether::_ProjectionRead_reserve, rether::_ProjectionWrite_reserve, rether::_ProjectionRead_reserve::Hash, rether::_ProjectionRead_reserve::HashEqual> _OpCache_with_parameter_reserve = _OpCache_with_parameter_reserve_ptr->second;
                                    auto writeState_ptr = _OpCache_with_parameter_reserve.find(readState);
                                    if(writeState_ptr != _OpCache_with_parameter_reserve.end()) {
                                        rether::_ProjectionWrite_reserve writeState = writeState_ptr->second;
                                        copiedState._apply_update_for_reserve(writeState);
                                    } else {
                                        copiedState.reserve(_tmp_2, _tmp_1);
                                        rether::_ProjectionWrite_reserve writeState = copiedState._update_for_reserve();
                                        _OpCache_with_parameter_reserve.insert({readState, writeState});
                                    }
                                }
                            }
                            copiedState.stateAccessedVia = "reserve";
                            result.insert(copiedState);
                            {
                                std::unique_lock<std::mutex> lock(mutex);
                                transitions += 1;
                            }
                        }
                    } else {
                        BSet<BTuple<rether::Nodes, rether::Slots >> _trid_2 = _trid_2_ptr->second;
                        for(const BTuple<rether::Nodes, rether::Slots >& param : _trid_2) {
                            rether::Slots _tmp_1 = param.projection2();
                            rether::Nodes _tmp_2 = param.projection1();

                            rether copiedState = state._copy();
                            rether::_ProjectionRead_reserve readState = state._projected_state_for_reserve();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_reserve_lock(_ProjectionRead_reserve_mutex);
                                auto _OpCache_with_parameter_reserve_ptr = _OpCache_reserve.find(param);
                                if(_OpCache_with_parameter_reserve_ptr == _OpCache_reserve.end()) {
                                    copiedState.reserve(_tmp_2, _tmp_1);
                                    rether::_ProjectionWrite_reserve writeState = copiedState._update_for_reserve();
                                    std::unordered_map<rether::_ProjectionRead_reserve, rether::_ProjectionWrite_reserve, rether::_ProjectionRead_reserve::Hash, rether::_ProjectionRead_reserve::HashEqual> _OpCache_with_parameter_reserve = std::unordered_map<rether::_ProjectionRead_reserve, rether::_ProjectionWrite_reserve, rether::_ProjectionRead_reserve::Hash, rether::_ProjectionRead_reserve::HashEqual>();
                                    _OpCache_with_parameter_reserve.insert({readState, writeState});
                                    _OpCache_reserve.insert({param, _OpCache_with_parameter_reserve});
                                } else {
                                    std::unordered_map<rether::_ProjectionRead_reserve, rether::_ProjectionWrite_reserve, rether::_ProjectionRead_reserve::Hash, rether::_ProjectionRead_reserve::HashEqual> _OpCache_with_parameter_reserve = _OpCache_with_parameter_reserve_ptr->second;
                                    auto writeState_ptr = _OpCache_with_parameter_reserve.find(readState);
                                    if(writeState_ptr != _OpCache_with_parameter_reserve.end()) {
                                        rether::_ProjectionWrite_reserve writeState = writeState_ptr->second;
                                        copiedState._apply_update_for_reserve(writeState);
                                    } else {
                                        copiedState.reserve(_tmp_2, _tmp_1);
                                        rether::_ProjectionWrite_reserve writeState = copiedState._update_for_reserve();
                                        _OpCache_with_parameter_reserve.insert({readState, writeState});
                                    }
                                }
                            }
                            copiedState.stateAccessedVia = "reserve";
                            result.insert(copiedState);
                            {
                                std::unique_lock<std::mutex> lock(mutex);
                                transitions += 1;
                            }
                        }
                    }
                }
                rether::_ProjectionRead__tr_release read__tr_release_state = state._projected_state_for__tr_release();
                {
                    std::unique_lock<std::mutex> _ProjectionRead__tr_release_lock(_ProjectionRead__tr_release_mutex);
                    auto _trid_3_ptr = _OpCache_tr_release.find(read__tr_release_state);
                    if(_trid_3_ptr == _OpCache_tr_release.end()) {
                        BSet<BTuple<rether::Nodes, rether::Slots >> _trid_3 = state._tr_release();
                        _OpCache_tr_release.insert({read__tr_release_state, _trid_3});
                        for(const BTuple<rether::Nodes, rether::Slots >& param : _trid_3) {
                            rether::Slots _tmp_1 = param.projection2();
                            rether::Nodes _tmp_2 = param.projection1();

                            rether copiedState = state._copy();
                            rether::_ProjectionRead_release readState = state._projected_state_for_release();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_release_lock(_ProjectionRead_release_mutex);
                                auto _OpCache_with_parameter_release_ptr = _OpCache_release.find(param);
                                if(_OpCache_with_parameter_release_ptr == _OpCache_release.end()) {
                                    copiedState.release(_tmp_2, _tmp_1);
                                    rether::_ProjectionWrite_release writeState = copiedState._update_for_release();
                                    std::unordered_map<rether::_ProjectionRead_release, rether::_ProjectionWrite_release, rether::_ProjectionRead_release::Hash, rether::_ProjectionRead_release::HashEqual> _OpCache_with_parameter_release = std::unordered_map<rether::_ProjectionRead_release, rether::_ProjectionWrite_release, rether::_ProjectionRead_release::Hash, rether::_ProjectionRead_release::HashEqual>();
                                    _OpCache_with_parameter_release.insert({readState, writeState});
                                    _OpCache_release.insert({param, _OpCache_with_parameter_release});
                                } else {
                                    std::unordered_map<rether::_ProjectionRead_release, rether::_ProjectionWrite_release, rether::_ProjectionRead_release::Hash, rether::_ProjectionRead_release::HashEqual> _OpCache_with_parameter_release = _OpCache_with_parameter_release_ptr->second;
                                    auto writeState_ptr = _OpCache_with_parameter_release.find(readState);
                                    if(writeState_ptr != _OpCache_with_parameter_release.end()) {
                                        rether::_ProjectionWrite_release writeState = writeState_ptr->second;
                                        copiedState._apply_update_for_release(writeState);
                                    } else {
                                        copiedState.release(_tmp_2, _tmp_1);
                                        rether::_ProjectionWrite_release writeState = copiedState._update_for_release();
                                        _OpCache_with_parameter_release.insert({readState, writeState});
                                    }
                                }
                            }
                            copiedState.stateAccessedVia = "release";
                            result.insert(copiedState);
                            {
                                std::unique_lock<std::mutex> lock(mutex);
                                transitions += 1;
                            }
                        }
                    } else {
                        BSet<BTuple<rether::Nodes, rether::Slots >> _trid_3 = _trid_3_ptr->second;
                        for(const BTuple<rether::Nodes, rether::Slots >& param : _trid_3) {
                            rether::Slots _tmp_1 = param.projection2();
                            rether::Nodes _tmp_2 = param.projection1();

                            rether copiedState = state._copy();
                            rether::_ProjectionRead_release readState = state._projected_state_for_release();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_release_lock(_ProjectionRead_release_mutex);
                                auto _OpCache_with_parameter_release_ptr = _OpCache_release.find(param);
                                if(_OpCache_with_parameter_release_ptr == _OpCache_release.end()) {
                                    copiedState.release(_tmp_2, _tmp_1);
                                    rether::_ProjectionWrite_release writeState = copiedState._update_for_release();
                                    std::unordered_map<rether::_ProjectionRead_release, rether::_ProjectionWrite_release, rether::_ProjectionRead_release::Hash, rether::_ProjectionRead_release::HashEqual> _OpCache_with_parameter_release = std::unordered_map<rether::_ProjectionRead_release, rether::_ProjectionWrite_release, rether::_ProjectionRead_release::Hash, rether::_ProjectionRead_release::HashEqual>();
                                    _OpCache_with_parameter_release.insert({readState, writeState});
                                    _OpCache_release.insert({param, _OpCache_with_parameter_release});
                                } else {
                                    std::unordered_map<rether::_ProjectionRead_release, rether::_ProjectionWrite_release, rether::_ProjectionRead_release::Hash, rether::_ProjectionRead_release::HashEqual> _OpCache_with_parameter_release = _OpCache_with_parameter_release_ptr->second;
                                    auto writeState_ptr = _OpCache_with_parameter_release.find(readState);
                                    if(writeState_ptr != _OpCache_with_parameter_release.end()) {
                                        rether::_ProjectionWrite_release writeState = writeState_ptr->second;
                                        copiedState._apply_update_for_release(writeState);
                                    } else {
                                        copiedState.release(_tmp_2, _tmp_1);
                                        rether::_ProjectionWrite_release writeState = copiedState._update_for_release();
                                        _OpCache_with_parameter_release.insert({readState, writeState});
                                    }
                                }
                            }
                            copiedState.stateAccessedVia = "release";
                            result.insert(copiedState);
                            {
                                std::unique_lock<std::mutex> lock(mutex);
                                transitions += 1;
                            }
                        }
                    }
                }
                rether::_ProjectionRead__tr_grant read__tr_grant_state = state._projected_state_for__tr_grant();
                {
                    std::unique_lock<std::mutex> _ProjectionRead__tr_grant_lock(_ProjectionRead__tr_grant_mutex);
                    auto _trid_4_ptr = _OpCache_tr_grant.find(read__tr_grant_state);
                    if(_trid_4_ptr == _OpCache_tr_grant.end()) {
                        BSet<BTuple<rether::Nodes, rether::Slots >> _trid_4 = state._tr_grant();
                        _OpCache_tr_grant.insert({read__tr_grant_state, _trid_4});
                        for(const BTuple<rether::Nodes, rether::Slots >& param : _trid_4) {
                            rether::Slots _tmp_1 = param.projection2();
                            rether::Nodes _tmp_2 = param.projection1();

                            rether copiedState = state._copy();
                            rether::_ProjectionRead_grant readState = state._projected_state_for_grant();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_grant_lock(_ProjectionRead_grant_mutex);
                                auto _OpCache_with_parameter_grant_ptr = _OpCache_grant.find(param);
                                if(_OpCache_with_parameter_grant_ptr == _OpCache_grant.end()) {
                                    copiedState.grant(_tmp_2, _tmp_1);
                                    rether::_ProjectionWrite_grant writeState = copiedState._update_for_grant();
                                    std::unordered_map<rether::_ProjectionRead_grant, rether::_ProjectionWrite_grant, rether::_ProjectionRead_grant::Hash, rether::_ProjectionRead_grant::HashEqual> _OpCache_with_parameter_grant = std::unordered_map<rether::_ProjectionRead_grant, rether::_ProjectionWrite_grant, rether::_ProjectionRead_grant::Hash, rether::_ProjectionRead_grant::HashEqual>();
                                    _OpCache_with_parameter_grant.insert({readState, writeState});
                                    _OpCache_grant.insert({param, _OpCache_with_parameter_grant});
                                } else {
                                    std::unordered_map<rether::_ProjectionRead_grant, rether::_ProjectionWrite_grant, rether::_ProjectionRead_grant::Hash, rether::_ProjectionRead_grant::HashEqual> _OpCache_with_parameter_grant = _OpCache_with_parameter_grant_ptr->second;
                                    auto writeState_ptr = _OpCache_with_parameter_grant.find(readState);
                                    if(writeState_ptr != _OpCache_with_parameter_grant.end()) {
                                        rether::_ProjectionWrite_grant writeState = writeState_ptr->second;
                                        copiedState._apply_update_for_grant(writeState);
                                    } else {
                                        copiedState.grant(_tmp_2, _tmp_1);
                                        rether::_ProjectionWrite_grant writeState = copiedState._update_for_grant();
                                        _OpCache_with_parameter_grant.insert({readState, writeState});
                                    }
                                }
                            }
                            copiedState.stateAccessedVia = "grant";
                            result.insert(copiedState);
                            {
                                std::unique_lock<std::mutex> lock(mutex);
                                transitions += 1;
                            }
                        }
                    } else {
                        BSet<BTuple<rether::Nodes, rether::Slots >> _trid_4 = _trid_4_ptr->second;
                        for(const BTuple<rether::Nodes, rether::Slots >& param : _trid_4) {
                            rether::Slots _tmp_1 = param.projection2();
                            rether::Nodes _tmp_2 = param.projection1();

                            rether copiedState = state._copy();
                            rether::_ProjectionRead_grant readState = state._projected_state_for_grant();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_grant_lock(_ProjectionRead_grant_mutex);
                                auto _OpCache_with_parameter_grant_ptr = _OpCache_grant.find(param);
                                if(_OpCache_with_parameter_grant_ptr == _OpCache_grant.end()) {
                                    copiedState.grant(_tmp_2, _tmp_1);
                                    rether::_ProjectionWrite_grant writeState = copiedState._update_for_grant();
                                    std::unordered_map<rether::_ProjectionRead_grant, rether::_ProjectionWrite_grant, rether::_ProjectionRead_grant::Hash, rether::_ProjectionRead_grant::HashEqual> _OpCache_with_parameter_grant = std::unordered_map<rether::_ProjectionRead_grant, rether::_ProjectionWrite_grant, rether::_ProjectionRead_grant::Hash, rether::_ProjectionRead_grant::HashEqual>();
                                    _OpCache_with_parameter_grant.insert({readState, writeState});
                                    _OpCache_grant.insert({param, _OpCache_with_parameter_grant});
                                } else {
                                    std::unordered_map<rether::_ProjectionRead_grant, rether::_ProjectionWrite_grant, rether::_ProjectionRead_grant::Hash, rether::_ProjectionRead_grant::HashEqual> _OpCache_with_parameter_grant = _OpCache_with_parameter_grant_ptr->second;
                                    auto writeState_ptr = _OpCache_with_parameter_grant.find(readState);
                                    if(writeState_ptr != _OpCache_with_parameter_grant.end()) {
                                        rether::_ProjectionWrite_grant writeState = writeState_ptr->second;
                                        copiedState._apply_update_for_grant(writeState);
                                    } else {
                                        copiedState.grant(_tmp_2, _tmp_1);
                                        rether::_ProjectionWrite_grant writeState = copiedState._update_for_grant();
                                        _OpCache_with_parameter_grant.insert({readState, writeState});
                                    }
                                }
                            }
                            copiedState.stateAccessedVia = "grant";
                            result.insert(copiedState);
                            {
                                std::unique_lock<std::mutex> lock(mutex);
                                transitions += 1;
                            }
                        }
                    }
                }
                rether::_ProjectionRead__tr_no_grant read__tr_no_grant_state = state._projected_state_for__tr_no_grant();
                {
                    std::unique_lock<std::mutex> _ProjectionRead__tr_no_grant_lock(_ProjectionRead__tr_no_grant_mutex);
                    auto _trid_5_ptr = _OpCache_tr_no_grant.find(read__tr_no_grant_state);
                    if(_trid_5_ptr == _OpCache_tr_no_grant.end()) {
                        BSet<BTuple<rether::Nodes, rether::Slots >> _trid_5 = state._tr_no_grant();
                        _OpCache_tr_no_grant.insert({read__tr_no_grant_state, _trid_5});
                        for(const BTuple<rether::Nodes, rether::Slots >& param : _trid_5) {
                            rether::Slots _tmp_1 = param.projection2();
                            rether::Nodes _tmp_2 = param.projection1();

                            rether copiedState = state._copy();
                            rether::_ProjectionRead_no_grant readState = state._projected_state_for_no_grant();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_no_grant_lock(_ProjectionRead_no_grant_mutex);
                                auto _OpCache_with_parameter_no_grant_ptr = _OpCache_no_grant.find(param);
                                if(_OpCache_with_parameter_no_grant_ptr == _OpCache_no_grant.end()) {
                                    copiedState.no_grant(_tmp_2, _tmp_1);
                                    rether::_ProjectionWrite_no_grant writeState = copiedState._update_for_no_grant();
                                    std::unordered_map<rether::_ProjectionRead_no_grant, rether::_ProjectionWrite_no_grant, rether::_ProjectionRead_no_grant::Hash, rether::_ProjectionRead_no_grant::HashEqual> _OpCache_with_parameter_no_grant = std::unordered_map<rether::_ProjectionRead_no_grant, rether::_ProjectionWrite_no_grant, rether::_ProjectionRead_no_grant::Hash, rether::_ProjectionRead_no_grant::HashEqual>();
                                    _OpCache_with_parameter_no_grant.insert({readState, writeState});
                                    _OpCache_no_grant.insert({param, _OpCache_with_parameter_no_grant});
                                } else {
                                    std::unordered_map<rether::_ProjectionRead_no_grant, rether::_ProjectionWrite_no_grant, rether::_ProjectionRead_no_grant::Hash, rether::_ProjectionRead_no_grant::HashEqual> _OpCache_with_parameter_no_grant = _OpCache_with_parameter_no_grant_ptr->second;
                                    auto writeState_ptr = _OpCache_with_parameter_no_grant.find(readState);
                                    if(writeState_ptr != _OpCache_with_parameter_no_grant.end()) {
                                        rether::_ProjectionWrite_no_grant writeState = writeState_ptr->second;
                                        copiedState._apply_update_for_no_grant(writeState);
                                    } else {
                                        copiedState.no_grant(_tmp_2, _tmp_1);
                                        rether::_ProjectionWrite_no_grant writeState = copiedState._update_for_no_grant();
                                        _OpCache_with_parameter_no_grant.insert({readState, writeState});
                                    }
                                }
                            }
                            copiedState.stateAccessedVia = "no_grant";
                            result.insert(copiedState);
                            {
                                std::unique_lock<std::mutex> lock(mutex);
                                transitions += 1;
                            }
                        }
                    } else {
                        BSet<BTuple<rether::Nodes, rether::Slots >> _trid_5 = _trid_5_ptr->second;
                        for(const BTuple<rether::Nodes, rether::Slots >& param : _trid_5) {
                            rether::Slots _tmp_1 = param.projection2();
                            rether::Nodes _tmp_2 = param.projection1();

                            rether copiedState = state._copy();
                            rether::_ProjectionRead_no_grant readState = state._projected_state_for_no_grant();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_no_grant_lock(_ProjectionRead_no_grant_mutex);
                                auto _OpCache_with_parameter_no_grant_ptr = _OpCache_no_grant.find(param);
                                if(_OpCache_with_parameter_no_grant_ptr == _OpCache_no_grant.end()) {
                                    copiedState.no_grant(_tmp_2, _tmp_1);
                                    rether::_ProjectionWrite_no_grant writeState = copiedState._update_for_no_grant();
                                    std::unordered_map<rether::_ProjectionRead_no_grant, rether::_ProjectionWrite_no_grant, rether::_ProjectionRead_no_grant::Hash, rether::_ProjectionRead_no_grant::HashEqual> _OpCache_with_parameter_no_grant = std::unordered_map<rether::_ProjectionRead_no_grant, rether::_ProjectionWrite_no_grant, rether::_ProjectionRead_no_grant::Hash, rether::_ProjectionRead_no_grant::HashEqual>();
                                    _OpCache_with_parameter_no_grant.insert({readState, writeState});
                                    _OpCache_no_grant.insert({param, _OpCache_with_parameter_no_grant});
                                } else {
                                    std::unordered_map<rether::_ProjectionRead_no_grant, rether::_ProjectionWrite_no_grant, rether::_ProjectionRead_no_grant::Hash, rether::_ProjectionRead_no_grant::HashEqual> _OpCache_with_parameter_no_grant = _OpCache_with_parameter_no_grant_ptr->second;
                                    auto writeState_ptr = _OpCache_with_parameter_no_grant.find(readState);
                                    if(writeState_ptr != _OpCache_with_parameter_no_grant.end()) {
                                        rether::_ProjectionWrite_no_grant writeState = writeState_ptr->second;
                                        copiedState._apply_update_for_no_grant(writeState);
                                    } else {
                                        copiedState.no_grant(_tmp_2, _tmp_1);
                                        rether::_ProjectionWrite_no_grant writeState = copiedState._update_for_no_grant();
                                        _OpCache_with_parameter_no_grant.insert({readState, writeState});
                                    }
                                }
                            }
                            copiedState.stateAccessedVia = "no_grant";
                            result.insert(copiedState);
                            {
                                std::unique_lock<std::mutex> lock(mutex);
                                transitions += 1;
                            }
                        }
                    }
                }
                rether::_ProjectionRead__tr_use_RT_Slot read__tr_use_RT_Slot_state = state._projected_state_for__tr_use_RT_Slot();
                {
                    std::unique_lock<std::mutex> _ProjectionRead__tr_use_RT_Slot_lock(_ProjectionRead__tr_use_RT_Slot_mutex);
                    auto _trid_6_ptr = _OpCache_tr_use_RT_Slot.find(read__tr_use_RT_Slot_state);
                    if(_trid_6_ptr == _OpCache_tr_use_RT_Slot.end()) {
                        BSet<BTuple<rether::Nodes, rether::Slots >> _trid_6 = state._tr_use_RT_Slot();
                        _OpCache_tr_use_RT_Slot.insert({read__tr_use_RT_Slot_state, _trid_6});
                        for(const BTuple<rether::Nodes, rether::Slots >& param : _trid_6) {
                            rether::Slots _tmp_1 = param.projection2();
                            rether::Nodes _tmp_2 = param.projection1();

                            rether copiedState = state._copy();
                            rether::_ProjectionRead_use_RT_Slot readState = state._projected_state_for_use_RT_Slot();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_use_RT_Slot_lock(_ProjectionRead_use_RT_Slot_mutex);
                                auto _OpCache_with_parameter_use_RT_Slot_ptr = _OpCache_use_RT_Slot.find(param);
                                if(_OpCache_with_parameter_use_RT_Slot_ptr == _OpCache_use_RT_Slot.end()) {
                                    copiedState.use_RT_Slot(_tmp_2, _tmp_1);
                                    rether::_ProjectionWrite_use_RT_Slot writeState = copiedState._update_for_use_RT_Slot();
                                    std::unordered_map<rether::_ProjectionRead_use_RT_Slot, rether::_ProjectionWrite_use_RT_Slot, rether::_ProjectionRead_use_RT_Slot::Hash, rether::_ProjectionRead_use_RT_Slot::HashEqual> _OpCache_with_parameter_use_RT_Slot = std::unordered_map<rether::_ProjectionRead_use_RT_Slot, rether::_ProjectionWrite_use_RT_Slot, rether::_ProjectionRead_use_RT_Slot::Hash, rether::_ProjectionRead_use_RT_Slot::HashEqual>();
                                    _OpCache_with_parameter_use_RT_Slot.insert({readState, writeState});
                                    _OpCache_use_RT_Slot.insert({param, _OpCache_with_parameter_use_RT_Slot});
                                } else {
                                    std::unordered_map<rether::_ProjectionRead_use_RT_Slot, rether::_ProjectionWrite_use_RT_Slot, rether::_ProjectionRead_use_RT_Slot::Hash, rether::_ProjectionRead_use_RT_Slot::HashEqual> _OpCache_with_parameter_use_RT_Slot = _OpCache_with_parameter_use_RT_Slot_ptr->second;
                                    auto writeState_ptr = _OpCache_with_parameter_use_RT_Slot.find(readState);
                                    if(writeState_ptr != _OpCache_with_parameter_use_RT_Slot.end()) {
                                        rether::_ProjectionWrite_use_RT_Slot writeState = writeState_ptr->second;
                                        copiedState._apply_update_for_use_RT_Slot(writeState);
                                    } else {
                                        copiedState.use_RT_Slot(_tmp_2, _tmp_1);
                                        rether::_ProjectionWrite_use_RT_Slot writeState = copiedState._update_for_use_RT_Slot();
                                        _OpCache_with_parameter_use_RT_Slot.insert({readState, writeState});
                                    }
                                }
                            }
                            copiedState.stateAccessedVia = "use_RT_Slot";
                            result.insert(copiedState);
                            {
                                std::unique_lock<std::mutex> lock(mutex);
                                transitions += 1;
                            }
                        }
                    } else {
                        BSet<BTuple<rether::Nodes, rether::Slots >> _trid_6 = _trid_6_ptr->second;
                        for(const BTuple<rether::Nodes, rether::Slots >& param : _trid_6) {
                            rether::Slots _tmp_1 = param.projection2();
                            rether::Nodes _tmp_2 = param.projection1();

                            rether copiedState = state._copy();
                            rether::_ProjectionRead_use_RT_Slot readState = state._projected_state_for_use_RT_Slot();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_use_RT_Slot_lock(_ProjectionRead_use_RT_Slot_mutex);
                                auto _OpCache_with_parameter_use_RT_Slot_ptr = _OpCache_use_RT_Slot.find(param);
                                if(_OpCache_with_parameter_use_RT_Slot_ptr == _OpCache_use_RT_Slot.end()) {
                                    copiedState.use_RT_Slot(_tmp_2, _tmp_1);
                                    rether::_ProjectionWrite_use_RT_Slot writeState = copiedState._update_for_use_RT_Slot();
                                    std::unordered_map<rether::_ProjectionRead_use_RT_Slot, rether::_ProjectionWrite_use_RT_Slot, rether::_ProjectionRead_use_RT_Slot::Hash, rether::_ProjectionRead_use_RT_Slot::HashEqual> _OpCache_with_parameter_use_RT_Slot = std::unordered_map<rether::_ProjectionRead_use_RT_Slot, rether::_ProjectionWrite_use_RT_Slot, rether::_ProjectionRead_use_RT_Slot::Hash, rether::_ProjectionRead_use_RT_Slot::HashEqual>();
                                    _OpCache_with_parameter_use_RT_Slot.insert({readState, writeState});
                                    _OpCache_use_RT_Slot.insert({param, _OpCache_with_parameter_use_RT_Slot});
                                } else {
                                    std::unordered_map<rether::_ProjectionRead_use_RT_Slot, rether::_ProjectionWrite_use_RT_Slot, rether::_ProjectionRead_use_RT_Slot::Hash, rether::_ProjectionRead_use_RT_Slot::HashEqual> _OpCache_with_parameter_use_RT_Slot = _OpCache_with_parameter_use_RT_Slot_ptr->second;
                                    auto writeState_ptr = _OpCache_with_parameter_use_RT_Slot.find(readState);
                                    if(writeState_ptr != _OpCache_with_parameter_use_RT_Slot.end()) {
                                        rether::_ProjectionWrite_use_RT_Slot writeState = writeState_ptr->second;
                                        copiedState._apply_update_for_use_RT_Slot(writeState);
                                    } else {
                                        copiedState.use_RT_Slot(_tmp_2, _tmp_1);
                                        rether::_ProjectionWrite_use_RT_Slot writeState = copiedState._update_for_use_RT_Slot();
                                        _OpCache_with_parameter_use_RT_Slot.insert({readState, writeState});
                                    }
                                }
                            }
                            copiedState.stateAccessedVia = "use_RT_Slot";
                            result.insert(copiedState);
                            {
                                std::unique_lock<std::mutex> lock(mutex);
                                transitions += 1;
                            }
                        }
                    }
                }
                rether::_ProjectionRead__tr_use_NRT_Slot read__tr_use_NRT_Slot_state = state._projected_state_for__tr_use_NRT_Slot();
                {
                    std::unique_lock<std::mutex> _ProjectionRead__tr_use_NRT_Slot_lock(_ProjectionRead__tr_use_NRT_Slot_mutex);
                    auto _trid_7_ptr = _OpCache_tr_use_NRT_Slot.find(read__tr_use_NRT_Slot_state);
                    if(_trid_7_ptr == _OpCache_tr_use_NRT_Slot.end()) {
                        BSet<BTuple<rether::Nodes, rether::Slots >> _trid_7 = state._tr_use_NRT_Slot();
                        _OpCache_tr_use_NRT_Slot.insert({read__tr_use_NRT_Slot_state, _trid_7});
                        for(const BTuple<rether::Nodes, rether::Slots >& param : _trid_7) {
                            rether::Slots _tmp_1 = param.projection2();
                            rether::Nodes _tmp_2 = param.projection1();

                            rether copiedState = state._copy();
                            rether::_ProjectionRead_use_NRT_Slot readState = state._projected_state_for_use_NRT_Slot();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_use_NRT_Slot_lock(_ProjectionRead_use_NRT_Slot_mutex);
                                auto _OpCache_with_parameter_use_NRT_Slot_ptr = _OpCache_use_NRT_Slot.find(param);
                                if(_OpCache_with_parameter_use_NRT_Slot_ptr == _OpCache_use_NRT_Slot.end()) {
                                    copiedState.use_NRT_Slot(_tmp_2, _tmp_1);
                                    rether::_ProjectionWrite_use_NRT_Slot writeState = copiedState._update_for_use_NRT_Slot();
                                    std::unordered_map<rether::_ProjectionRead_use_NRT_Slot, rether::_ProjectionWrite_use_NRT_Slot, rether::_ProjectionRead_use_NRT_Slot::Hash, rether::_ProjectionRead_use_NRT_Slot::HashEqual> _OpCache_with_parameter_use_NRT_Slot = std::unordered_map<rether::_ProjectionRead_use_NRT_Slot, rether::_ProjectionWrite_use_NRT_Slot, rether::_ProjectionRead_use_NRT_Slot::Hash, rether::_ProjectionRead_use_NRT_Slot::HashEqual>();
                                    _OpCache_with_parameter_use_NRT_Slot.insert({readState, writeState});
                                    _OpCache_use_NRT_Slot.insert({param, _OpCache_with_parameter_use_NRT_Slot});
                                } else {
                                    std::unordered_map<rether::_ProjectionRead_use_NRT_Slot, rether::_ProjectionWrite_use_NRT_Slot, rether::_ProjectionRead_use_NRT_Slot::Hash, rether::_ProjectionRead_use_NRT_Slot::HashEqual> _OpCache_with_parameter_use_NRT_Slot = _OpCache_with_parameter_use_NRT_Slot_ptr->second;
                                    auto writeState_ptr = _OpCache_with_parameter_use_NRT_Slot.find(readState);
                                    if(writeState_ptr != _OpCache_with_parameter_use_NRT_Slot.end()) {
                                        rether::_ProjectionWrite_use_NRT_Slot writeState = writeState_ptr->second;
                                        copiedState._apply_update_for_use_NRT_Slot(writeState);
                                    } else {
                                        copiedState.use_NRT_Slot(_tmp_2, _tmp_1);
                                        rether::_ProjectionWrite_use_NRT_Slot writeState = copiedState._update_for_use_NRT_Slot();
                                        _OpCache_with_parameter_use_NRT_Slot.insert({readState, writeState});
                                    }
                                }
                            }
                            copiedState.stateAccessedVia = "use_NRT_Slot";
                            result.insert(copiedState);
                            {
                                std::unique_lock<std::mutex> lock(mutex);
                                transitions += 1;
                            }
                        }
                    } else {
                        BSet<BTuple<rether::Nodes, rether::Slots >> _trid_7 = _trid_7_ptr->second;
                        for(const BTuple<rether::Nodes, rether::Slots >& param : _trid_7) {
                            rether::Slots _tmp_1 = param.projection2();
                            rether::Nodes _tmp_2 = param.projection1();

                            rether copiedState = state._copy();
                            rether::_ProjectionRead_use_NRT_Slot readState = state._projected_state_for_use_NRT_Slot();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_use_NRT_Slot_lock(_ProjectionRead_use_NRT_Slot_mutex);
                                auto _OpCache_with_parameter_use_NRT_Slot_ptr = _OpCache_use_NRT_Slot.find(param);
                                if(_OpCache_with_parameter_use_NRT_Slot_ptr == _OpCache_use_NRT_Slot.end()) {
                                    copiedState.use_NRT_Slot(_tmp_2, _tmp_1);
                                    rether::_ProjectionWrite_use_NRT_Slot writeState = copiedState._update_for_use_NRT_Slot();
                                    std::unordered_map<rether::_ProjectionRead_use_NRT_Slot, rether::_ProjectionWrite_use_NRT_Slot, rether::_ProjectionRead_use_NRT_Slot::Hash, rether::_ProjectionRead_use_NRT_Slot::HashEqual> _OpCache_with_parameter_use_NRT_Slot = std::unordered_map<rether::_ProjectionRead_use_NRT_Slot, rether::_ProjectionWrite_use_NRT_Slot, rether::_ProjectionRead_use_NRT_Slot::Hash, rether::_ProjectionRead_use_NRT_Slot::HashEqual>();
                                    _OpCache_with_parameter_use_NRT_Slot.insert({readState, writeState});
                                    _OpCache_use_NRT_Slot.insert({param, _OpCache_with_parameter_use_NRT_Slot});
                                } else {
                                    std::unordered_map<rether::_ProjectionRead_use_NRT_Slot, rether::_ProjectionWrite_use_NRT_Slot, rether::_ProjectionRead_use_NRT_Slot::Hash, rether::_ProjectionRead_use_NRT_Slot::HashEqual> _OpCache_with_parameter_use_NRT_Slot = _OpCache_with_parameter_use_NRT_Slot_ptr->second;
                                    auto writeState_ptr = _OpCache_with_parameter_use_NRT_Slot.find(readState);
                                    if(writeState_ptr != _OpCache_with_parameter_use_NRT_Slot.end()) {
                                        rether::_ProjectionWrite_use_NRT_Slot writeState = writeState_ptr->second;
                                        copiedState._apply_update_for_use_NRT_Slot(writeState);
                                    } else {
                                        copiedState.use_NRT_Slot(_tmp_2, _tmp_1);
                                        rether::_ProjectionWrite_use_NRT_Slot writeState = copiedState._update_for_use_NRT_Slot();
                                        _OpCache_with_parameter_use_NRT_Slot.insert({readState, writeState});
                                    }
                                }
                            }
                            copiedState.stateAccessedVia = "use_NRT_Slot";
                            result.insert(copiedState);
                            {
                                std::unique_lock<std::mutex> lock(mutex);
                                transitions += 1;
                            }
                        }
                    }
                }
                rether::_ProjectionRead__tr_pass_token read__tr_pass_token_state = state._projected_state_for__tr_pass_token();
                {
                    std::unique_lock<std::mutex> _ProjectionRead__tr_pass_token_lock(_ProjectionRead__tr_pass_token_mutex);
                    auto _trid_8_ptr = _OpCache_tr_pass_token.find(read__tr_pass_token_state);
                    if(_trid_8_ptr == _OpCache_tr_pass_token.end()) {
                        BSet<rether::Nodes> _trid_8 = state._tr_pass_token();
                        _OpCache_tr_pass_token.insert({read__tr_pass_token_state, _trid_8});
                        for(const rether::Nodes& param : _trid_8) {
                            rether::Nodes _tmp_1 = param;

                            rether copiedState = state._copy();
                            rether::_ProjectionRead_pass_token readState = state._projected_state_for_pass_token();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_pass_token_lock(_ProjectionRead_pass_token_mutex);
                                auto _OpCache_with_parameter_pass_token_ptr = _OpCache_pass_token.find(param);
                                if(_OpCache_with_parameter_pass_token_ptr == _OpCache_pass_token.end()) {
                                    copiedState.pass_token(_tmp_1);
                                    rether::_ProjectionWrite_pass_token writeState = copiedState._update_for_pass_token();
                                    std::unordered_map<rether::_ProjectionRead_pass_token, rether::_ProjectionWrite_pass_token, rether::_ProjectionRead_pass_token::Hash, rether::_ProjectionRead_pass_token::HashEqual> _OpCache_with_parameter_pass_token = std::unordered_map<rether::_ProjectionRead_pass_token, rether::_ProjectionWrite_pass_token, rether::_ProjectionRead_pass_token::Hash, rether::_ProjectionRead_pass_token::HashEqual>();
                                    _OpCache_with_parameter_pass_token.insert({readState, writeState});
                                    _OpCache_pass_token.insert({param, _OpCache_with_parameter_pass_token});
                                } else {
                                    std::unordered_map<rether::_ProjectionRead_pass_token, rether::_ProjectionWrite_pass_token, rether::_ProjectionRead_pass_token::Hash, rether::_ProjectionRead_pass_token::HashEqual> _OpCache_with_parameter_pass_token = _OpCache_with_parameter_pass_token_ptr->second;
                                    auto writeState_ptr = _OpCache_with_parameter_pass_token.find(readState);
                                    if(writeState_ptr != _OpCache_with_parameter_pass_token.end()) {
                                        rether::_ProjectionWrite_pass_token writeState = writeState_ptr->second;
                                        copiedState._apply_update_for_pass_token(writeState);
                                    } else {
                                        copiedState.pass_token(_tmp_1);
                                        rether::_ProjectionWrite_pass_token writeState = copiedState._update_for_pass_token();
                                        _OpCache_with_parameter_pass_token.insert({readState, writeState});
                                    }
                                }
                            }
                            copiedState.stateAccessedVia = "pass_token";
                            result.insert(copiedState);
                            {
                                std::unique_lock<std::mutex> lock(mutex);
                                transitions += 1;
                            }
                        }
                    } else {
                        BSet<rether::Nodes> _trid_8 = _trid_8_ptr->second;
                        for(const rether::Nodes& param : _trid_8) {
                            rether::Nodes _tmp_1 = param;

                            rether copiedState = state._copy();
                            rether::_ProjectionRead_pass_token readState = state._projected_state_for_pass_token();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_pass_token_lock(_ProjectionRead_pass_token_mutex);
                                auto _OpCache_with_parameter_pass_token_ptr = _OpCache_pass_token.find(param);
                                if(_OpCache_with_parameter_pass_token_ptr == _OpCache_pass_token.end()) {
                                    copiedState.pass_token(_tmp_1);
                                    rether::_ProjectionWrite_pass_token writeState = copiedState._update_for_pass_token();
                                    std::unordered_map<rether::_ProjectionRead_pass_token, rether::_ProjectionWrite_pass_token, rether::_ProjectionRead_pass_token::Hash, rether::_ProjectionRead_pass_token::HashEqual> _OpCache_with_parameter_pass_token = std::unordered_map<rether::_ProjectionRead_pass_token, rether::_ProjectionWrite_pass_token, rether::_ProjectionRead_pass_token::Hash, rether::_ProjectionRead_pass_token::HashEqual>();
                                    _OpCache_with_parameter_pass_token.insert({readState, writeState});
                                    _OpCache_pass_token.insert({param, _OpCache_with_parameter_pass_token});
                                } else {
                                    std::unordered_map<rether::_ProjectionRead_pass_token, rether::_ProjectionWrite_pass_token, rether::_ProjectionRead_pass_token::Hash, rether::_ProjectionRead_pass_token::HashEqual> _OpCache_with_parameter_pass_token = _OpCache_with_parameter_pass_token_ptr->second;
                                    auto writeState_ptr = _OpCache_with_parameter_pass_token.find(readState);
                                    if(writeState_ptr != _OpCache_with_parameter_pass_token.end()) {
                                        rether::_ProjectionWrite_pass_token writeState = writeState_ptr->second;
                                        copiedState._apply_update_for_pass_token(writeState);
                                    } else {
                                        copiedState.pass_token(_tmp_1);
                                        rether::_ProjectionWrite_pass_token writeState = copiedState._update_for_pass_token();
                                        _OpCache_with_parameter_pass_token.insert({readState, writeState});
                                    }
                                }
                            }
                            copiedState.stateAccessedVia = "pass_token";
                            result.insert(copiedState);
                            {
                                std::unique_lock<std::mutex> lock(mutex);
                                transitions += 1;
                            }
                        }
                    }
                }

            } else {
                BSet<BTuple<rether::Slots, rether::Slots >> _trid_1 = state._tr_elapse_time();
                for(const BTuple<rether::Slots, rether::Slots >& param : _trid_1) {
                    rether::Slots _tmp_1 = param.projection2();
                    rether::Slots _tmp_2 = param.projection1();

                    rether copiedState = state._copy();
                    copiedState.elapse_time(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "elapse_time";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                BSet<BTuple<rether::Nodes, rether::Slots >> _trid_2 = state._tr_reserve();
                for(const BTuple<rether::Nodes, rether::Slots >& param : _trid_2) {
                    rether::Slots _tmp_1 = param.projection2();
                    rether::Nodes _tmp_2 = param.projection1();

                    rether copiedState = state._copy();
                    copiedState.reserve(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "reserve";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                BSet<BTuple<rether::Nodes, rether::Slots >> _trid_3 = state._tr_release();
                for(const BTuple<rether::Nodes, rether::Slots >& param : _trid_3) {
                    rether::Slots _tmp_1 = param.projection2();
                    rether::Nodes _tmp_2 = param.projection1();

                    rether copiedState = state._copy();
                    copiedState.release(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "release";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                BSet<BTuple<rether::Nodes, rether::Slots >> _trid_4 = state._tr_grant();
                for(const BTuple<rether::Nodes, rether::Slots >& param : _trid_4) {
                    rether::Slots _tmp_1 = param.projection2();
                    rether::Nodes _tmp_2 = param.projection1();

                    rether copiedState = state._copy();
                    copiedState.grant(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "grant";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                BSet<BTuple<rether::Nodes, rether::Slots >> _trid_5 = state._tr_no_grant();
                for(const BTuple<rether::Nodes, rether::Slots >& param : _trid_5) {
                    rether::Slots _tmp_1 = param.projection2();
                    rether::Nodes _tmp_2 = param.projection1();

                    rether copiedState = state._copy();
                    copiedState.no_grant(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "no_grant";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                BSet<BTuple<rether::Nodes, rether::Slots >> _trid_6 = state._tr_use_RT_Slot();
                for(const BTuple<rether::Nodes, rether::Slots >& param : _trid_6) {
                    rether::Slots _tmp_1 = param.projection2();
                    rether::Nodes _tmp_2 = param.projection1();

                    rether copiedState = state._copy();
                    copiedState.use_RT_Slot(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "use_RT_Slot";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                BSet<BTuple<rether::Nodes, rether::Slots >> _trid_7 = state._tr_use_NRT_Slot();
                for(const BTuple<rether::Nodes, rether::Slots >& param : _trid_7) {
                    rether::Slots _tmp_1 = param.projection2();
                    rether::Nodes _tmp_2 = param.projection1();

                    rether copiedState = state._copy();
                    copiedState.use_NRT_Slot(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "use_NRT_Slot";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                BSet<rether::Nodes> _trid_8 = state._tr_pass_token();
                for(const rether::Nodes& param : _trid_8) {
                    rether::Nodes _tmp_1 = param;

                    rether copiedState = state._copy();
                    copiedState.pass_token(_tmp_1);
                    copiedState.stateAccessedVia = "pass_token";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }

            }
            return result;
        }

        bool invariantViolated(const rether& state) {
            bool _check_inv_1 = true;
            if(isCaching) {
                {
                    std::unique_lock<std::mutex> _ProjectionRead__check_inv_1_lock(_ProjectionRead__check_inv_1_mutex);
                    rether::_ProjectionRead__check_inv_1 read__check_inv_1_state = state._projected_state_for__check_inv_1();
                    auto _obj__check_inv_1_ptr = _InvCache__check_inv_1.find(read__check_inv_1_state);
                    if(_obj__check_inv_1_ptr == _InvCache__check_inv_1.end()) {
                        _check_inv_1 = state._check_inv_1();
                        _InvCache__check_inv_1.insert({read__check_inv_1_state, _check_inv_1});
                    } else {
                        _check_inv_1 = _obj__check_inv_1_ptr->second;
                    }
                }
            } else {
                _check_inv_1 = state._check_inv_1();
            }
            if(!_check_inv_1) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_1" << "\n";
              return true;
            }
            bool _check_inv_2 = true;
            if(isCaching) {
                {
                    std::unique_lock<std::mutex> _ProjectionRead__check_inv_2_lock(_ProjectionRead__check_inv_2_mutex);
                    rether::_ProjectionRead__check_inv_2 read__check_inv_2_state = state._projected_state_for__check_inv_2();
                    auto _obj__check_inv_2_ptr = _InvCache__check_inv_2.find(read__check_inv_2_state);
                    if(_obj__check_inv_2_ptr == _InvCache__check_inv_2.end()) {
                        _check_inv_2 = state._check_inv_2();
                        _InvCache__check_inv_2.insert({read__check_inv_2_state, _check_inv_2});
                    } else {
                        _check_inv_2 = _obj__check_inv_2_ptr->second;
                    }
                }
            } else {
                _check_inv_2 = state._check_inv_2();
            }
            if(!_check_inv_2) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_2" << "\n";
              return true;
            }
            bool _check_inv_3 = true;
            if(isCaching) {
                {
                    std::unique_lock<std::mutex> _ProjectionRead__check_inv_3_lock(_ProjectionRead__check_inv_3_mutex);
                    rether::_ProjectionRead__check_inv_3 read__check_inv_3_state = state._projected_state_for__check_inv_3();
                    auto _obj__check_inv_3_ptr = _InvCache__check_inv_3.find(read__check_inv_3_state);
                    if(_obj__check_inv_3_ptr == _InvCache__check_inv_3.end()) {
                        _check_inv_3 = state._check_inv_3();
                        _InvCache__check_inv_3.insert({read__check_inv_3_state, _check_inv_3});
                    } else {
                        _check_inv_3 = _obj__check_inv_3_ptr->second;
                    }
                }
            } else {
                _check_inv_3 = state._check_inv_3();
            }
            if(!_check_inv_3) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_3" << "\n";
              return true;
            }
            bool _check_inv_4 = true;
            if(isCaching) {
                {
                    std::unique_lock<std::mutex> _ProjectionRead__check_inv_4_lock(_ProjectionRead__check_inv_4_mutex);
                    rether::_ProjectionRead__check_inv_4 read__check_inv_4_state = state._projected_state_for__check_inv_4();
                    auto _obj__check_inv_4_ptr = _InvCache__check_inv_4.find(read__check_inv_4_state);
                    if(_obj__check_inv_4_ptr == _InvCache__check_inv_4.end()) {
                        _check_inv_4 = state._check_inv_4();
                        _InvCache__check_inv_4.insert({read__check_inv_4_state, _check_inv_4});
                    } else {
                        _check_inv_4 = _obj__check_inv_4_ptr->second;
                    }
                }
            } else {
                _check_inv_4 = state._check_inv_4();
            }
            if(!_check_inv_4) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_4" << "\n";
              return true;
            }
            bool _check_inv_5 = true;
            if(isCaching) {
                {
                    std::unique_lock<std::mutex> _ProjectionRead__check_inv_5_lock(_ProjectionRead__check_inv_5_mutex);
                    rether::_ProjectionRead__check_inv_5 read__check_inv_5_state = state._projected_state_for__check_inv_5();
                    auto _obj__check_inv_5_ptr = _InvCache__check_inv_5.find(read__check_inv_5_state);
                    if(_obj__check_inv_5_ptr == _InvCache__check_inv_5.end()) {
                        _check_inv_5 = state._check_inv_5();
                        _InvCache__check_inv_5.insert({read__check_inv_5_state, _check_inv_5});
                    } else {
                        _check_inv_5 = _obj__check_inv_5_ptr->second;
                    }
                }
            } else {
                _check_inv_5 = state._check_inv_5();
            }
            if(!_check_inv_5) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_5" << "\n";
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

    rether::Type type;

    if(std::string("mixed").compare(strategy) == 0) {
        type = rether::Type::MIXED;
    } else if(std::string("bf").compare(strategy) == 0) {
        type = rether::Type::BFS;
    } else if (std::string("df").compare(strategy) == 0) {
        type = rether::Type::DFS;
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