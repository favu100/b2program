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
#include <btypes_primitives/BTuple.hpp>

#ifndef LandingGear_R6_H
#define LandingGear_R6_H

using namespace std;

class LandingGear_R6 {

    public:

        enum Type { BFS, DFS, MIXED };

        class DOOR_STATE : public BObject {
            public:

                typedef DOOR_STATE current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum DOOR_STATE_type {
                    open, 
                    closed, 
                    door_moving
                };

                DOOR_STATE_type value;

                DOOR_STATE(){}

                DOOR_STATE(const DOOR_STATE_type& type) {
                    this->value = type;
                }

                BBoolean equal(const DOOR_STATE& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const DOOR_STATE& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const DOOR_STATE& p1, const DOOR_STATE& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const DOOR_STATE& p1, const DOOR_STATE& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const DOOR_STATE& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const DOOR_STATE& e) {
                    switch(e.value) {
                        case open: return strm << "open";
                        case closed: return strm << "closed";
                        case door_moving: return strm << "door_moving";
                    }
                    return strm;
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class GEAR_STATE : public BObject {
            public:

                typedef GEAR_STATE current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum GEAR_STATE_type {
                    retracted, 
                    extended, 
                    gear_moving
                };

                GEAR_STATE_type value;

                GEAR_STATE(){}

                GEAR_STATE(const GEAR_STATE_type& type) {
                    this->value = type;
                }

                BBoolean equal(const GEAR_STATE& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const GEAR_STATE& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const GEAR_STATE& p1, const GEAR_STATE& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const GEAR_STATE& p1, const GEAR_STATE& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const GEAR_STATE& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const GEAR_STATE& e) {
                    switch(e.value) {
                        case retracted: return strm << "retracted";
                        case extended: return strm << "extended";
                        case gear_moving: return strm << "gear_moving";
                    }
                    return strm;
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class HANDLE_STATE : public BObject {
            public:

                typedef HANDLE_STATE current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum HANDLE_STATE_type {
                    up, 
                    down
                };

                HANDLE_STATE_type value;

                HANDLE_STATE(){}

                HANDLE_STATE(const HANDLE_STATE_type& type) {
                    this->value = type;
                }

                BBoolean equal(const HANDLE_STATE& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const HANDLE_STATE& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const HANDLE_STATE& p1, const HANDLE_STATE& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const HANDLE_STATE& p1, const HANDLE_STATE& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const HANDLE_STATE& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const HANDLE_STATE& e) {
                    switch(e.value) {
                        case up: return strm << "up";
                        case down: return strm << "down";
                    }
                    return strm;
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class POSITION : public BObject {
            public:

                typedef POSITION current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum POSITION_type {
                    fr, 
                    lt, 
                    rt
                };

                POSITION_type value;

                POSITION(){}

                POSITION(const POSITION_type& type) {
                    this->value = type;
                }

                BBoolean equal(const POSITION& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const POSITION& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const POSITION& p1, const POSITION& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const POSITION& p1, const POSITION& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const POSITION& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const POSITION& e) {
                    switch(e.value) {
                        case fr: return strm << "fr";
                        case lt: return strm << "lt";
                        case rt: return strm << "rt";
                    }
                    return strm;
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class SWITCH_STATE : public BObject {
            public:

                typedef SWITCH_STATE current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum SWITCH_STATE_type {
                    switch_open, 
                    switch_closed
                };

                SWITCH_STATE_type value;

                SWITCH_STATE(){}

                SWITCH_STATE(const SWITCH_STATE_type& type) {
                    this->value = type;
                }

                BBoolean equal(const SWITCH_STATE& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const SWITCH_STATE& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const SWITCH_STATE& p1, const SWITCH_STATE& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const SWITCH_STATE& p1, const SWITCH_STATE& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const SWITCH_STATE& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const SWITCH_STATE& e) {
                    switch(e.value) {
                        case switch_open: return strm << "switch_open";
                        case switch_closed: return strm << "switch_closed";
                    }
                    return strm;
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class PLANE_STATE : public BObject {
            public:

                typedef PLANE_STATE current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum PLANE_STATE_type {
                    ground, 
                    flight
                };

                PLANE_STATE_type value;

                PLANE_STATE(){}

                PLANE_STATE(const PLANE_STATE_type& type) {
                    this->value = type;
                }

                BBoolean equal(const PLANE_STATE& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const PLANE_STATE& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const PLANE_STATE& p1, const PLANE_STATE& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const PLANE_STATE& p1, const PLANE_STATE& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const PLANE_STATE& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const PLANE_STATE& e) {
                    switch(e.value) {
                        case ground: return strm << "ground";
                        case flight: return strm << "flight";
                    }
                    return strm;
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class VALVE_STATE : public BObject {
            public:

                typedef VALVE_STATE current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum VALVE_STATE_type {
                    valve_open, 
                    valve_closed
                };

                VALVE_STATE_type value;

                VALVE_STATE(){}

                VALVE_STATE(const VALVE_STATE_type& type) {
                    this->value = type;
                }

                BBoolean equal(const VALVE_STATE& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const VALVE_STATE& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const VALVE_STATE& p1, const VALVE_STATE& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const VALVE_STATE& p1, const VALVE_STATE& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const VALVE_STATE& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const VALVE_STATE& e) {
                    switch(e.value) {
                        case valve_open: return strm << "valve_open";
                        case valve_closed: return strm << "valve_closed";
                    }
                    return strm;
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };


        struct Hash {
            public:
                size_t operator()(const LandingGear_R6& obj) const {
                    return obj.hashCode();
                }
        };

        struct HashEqual {
            public:
                bool operator()(const LandingGear_R6& obj1, const LandingGear_R6& obj2) const {
                    if (obj1 == obj2)
                        return true;
                    else
                        return false;
                    }
            };

        class _ProjectionRead_begin_flying {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_begin_flying& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_begin_flying& obj1, const _ProjectionRead_begin_flying& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                PLANE_STATE shock_absorber;

                _ProjectionRead_begin_flying(const PLANE_STATE& shock_absorber) {
                    this->shock_absorber = shock_absorber;
                }

                friend bool operator ==(const _ProjectionRead_begin_flying& o1, const _ProjectionRead_begin_flying& o2) {
                    return o1.shock_absorber == (o2.shock_absorber);
                }

                friend bool operator !=(const _ProjectionRead_begin_flying& o1, const _ProjectionRead_begin_flying& o2) {
                    return o1.shock_absorber != (o2.shock_absorber);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_begin_flying& e) {
                    strm << "{";
                    strm << "shock_absorber: " << e.shock_absorber;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (shock_absorber.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_begin_flying {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_begin_flying& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_begin_flying& obj1, const _ProjectionRead__tr_begin_flying& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                PLANE_STATE shock_absorber;

                _ProjectionRead__tr_begin_flying(const PLANE_STATE& shock_absorber) {
                    this->shock_absorber = shock_absorber;
                }

                friend bool operator ==(const _ProjectionRead__tr_begin_flying& o1, const _ProjectionRead__tr_begin_flying& o2) {
                    return o1.shock_absorber == (o2.shock_absorber);
                }

                friend bool operator !=(const _ProjectionRead__tr_begin_flying& o1, const _ProjectionRead__tr_begin_flying& o2) {
                    return o1.shock_absorber != (o2.shock_absorber);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_begin_flying& e) {
                    strm << "{";
                    strm << "shock_absorber: " << e.shock_absorber;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (shock_absorber.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_begin_flying {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_begin_flying& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_begin_flying& obj1, const _ProjectionWrite_begin_flying& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                PLANE_STATE shock_absorber;

                _ProjectionWrite_begin_flying(const PLANE_STATE& shock_absorber) {
                    this->shock_absorber = shock_absorber;
                }

                friend bool operator ==(const _ProjectionWrite_begin_flying& o1, const _ProjectionWrite_begin_flying& o2) {
                    return o1.shock_absorber == (o2.shock_absorber);
                }

                friend bool operator !=(const _ProjectionWrite_begin_flying& o1, const _ProjectionWrite_begin_flying& o2) {
                    return o1.shock_absorber != (o2.shock_absorber);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_begin_flying& e) {
                    strm << "{";
                    strm << "shock_absorber: " << e.shock_absorber;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (shock_absorber.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_land_plane {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_land_plane& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_land_plane& obj1, const _ProjectionRead_land_plane& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                PLANE_STATE shock_absorber;

                _ProjectionRead_land_plane(const PLANE_STATE& shock_absorber) {
                    this->shock_absorber = shock_absorber;
                }

                friend bool operator ==(const _ProjectionRead_land_plane& o1, const _ProjectionRead_land_plane& o2) {
                    return o1.shock_absorber == (o2.shock_absorber);
                }

                friend bool operator !=(const _ProjectionRead_land_plane& o1, const _ProjectionRead_land_plane& o2) {
                    return o1.shock_absorber != (o2.shock_absorber);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_land_plane& e) {
                    strm << "{";
                    strm << "shock_absorber: " << e.shock_absorber;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (shock_absorber.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_land_plane {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_land_plane& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_land_plane& obj1, const _ProjectionRead__tr_land_plane& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                PLANE_STATE shock_absorber;

                _ProjectionRead__tr_land_plane(const PLANE_STATE& shock_absorber) {
                    this->shock_absorber = shock_absorber;
                }

                friend bool operator ==(const _ProjectionRead__tr_land_plane& o1, const _ProjectionRead__tr_land_plane& o2) {
                    return o1.shock_absorber == (o2.shock_absorber);
                }

                friend bool operator !=(const _ProjectionRead__tr_land_plane& o1, const _ProjectionRead__tr_land_plane& o2) {
                    return o1.shock_absorber != (o2.shock_absorber);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_land_plane& e) {
                    strm << "{";
                    strm << "shock_absorber: " << e.shock_absorber;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (shock_absorber.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_land_plane {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_land_plane& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_land_plane& obj1, const _ProjectionWrite_land_plane& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                PLANE_STATE shock_absorber;

                _ProjectionWrite_land_plane(const PLANE_STATE& shock_absorber) {
                    this->shock_absorber = shock_absorber;
                }

                friend bool operator ==(const _ProjectionWrite_land_plane& o1, const _ProjectionWrite_land_plane& o2) {
                    return o1.shock_absorber == (o2.shock_absorber);
                }

                friend bool operator !=(const _ProjectionWrite_land_plane& o1, const _ProjectionWrite_land_plane& o2) {
                    return o1.shock_absorber != (o2.shock_absorber);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_land_plane& e) {
                    strm << "{";
                    strm << "shock_absorber: " << e.shock_absorber;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (shock_absorber.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_open_valve_door_open {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_open_valve_door_open& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_open_valve_door_open& obj1, const _ProjectionRead_open_valve_door_open& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_open_door;
                BBoolean open_EV;

                _ProjectionRead_open_valve_door_open(const VALVE_STATE& valve_open_door, const BBoolean& open_EV) {
                    this->valve_open_door = valve_open_door;
                    this->open_EV = open_EV;
                }

                friend bool operator ==(const _ProjectionRead_open_valve_door_open& o1, const _ProjectionRead_open_valve_door_open& o2) {
                    return o1.valve_open_door == (o2.valve_open_door) && o1.open_EV == (o2.open_EV);
                }

                friend bool operator !=(const _ProjectionRead_open_valve_door_open& o1, const _ProjectionRead_open_valve_door_open& o2) {
                    return o1.valve_open_door != (o2.valve_open_door) || o1.open_EV != (o2.open_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_open_valve_door_open& e) {
                    strm << "{";
                    strm << "valve_open_door: " << e.valve_open_door;
                    strm << ", ";
                    strm << "open_EV: " << e.open_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_open_door.hashCode() << 1);
                    result = 31 * result + (open_EV.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_open_valve_door_open {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_open_valve_door_open& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_open_valve_door_open& obj1, const _ProjectionRead__tr_open_valve_door_open& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_open_door;
                BBoolean open_EV;

                _ProjectionRead__tr_open_valve_door_open(const VALVE_STATE& valve_open_door, const BBoolean& open_EV) {
                    this->valve_open_door = valve_open_door;
                    this->open_EV = open_EV;
                }

                friend bool operator ==(const _ProjectionRead__tr_open_valve_door_open& o1, const _ProjectionRead__tr_open_valve_door_open& o2) {
                    return o1.valve_open_door == (o2.valve_open_door) && o1.open_EV == (o2.open_EV);
                }

                friend bool operator !=(const _ProjectionRead__tr_open_valve_door_open& o1, const _ProjectionRead__tr_open_valve_door_open& o2) {
                    return o1.valve_open_door != (o2.valve_open_door) || o1.open_EV != (o2.open_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_open_valve_door_open& e) {
                    strm << "{";
                    strm << "valve_open_door: " << e.valve_open_door;
                    strm << ", "; 
                    strm << "open_EV: " << e.open_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_open_door.hashCode() << 1);
                    result = 31 * result + (open_EV.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_open_valve_door_open {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_open_valve_door_open& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_open_valve_door_open& obj1, const _ProjectionWrite_open_valve_door_open& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_open_door;

                _ProjectionWrite_open_valve_door_open(const VALVE_STATE& valve_open_door) {
                    this->valve_open_door = valve_open_door;
                }

                friend bool operator ==(const _ProjectionWrite_open_valve_door_open& o1, const _ProjectionWrite_open_valve_door_open& o2) {
                    return o1.valve_open_door == (o2.valve_open_door);
                }

                friend bool operator !=(const _ProjectionWrite_open_valve_door_open& o1, const _ProjectionWrite_open_valve_door_open& o2) {
                    return o1.valve_open_door != (o2.valve_open_door);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_open_valve_door_open& e) {
                    strm << "{";
                    strm << "valve_open_door: " << e.valve_open_door;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_open_door.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_close_valve_door_open {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_close_valve_door_open& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_close_valve_door_open& obj1, const _ProjectionRead_close_valve_door_open& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_open_door;
                BBoolean open_EV;

                _ProjectionRead_close_valve_door_open(const VALVE_STATE& valve_open_door, const BBoolean& open_EV) {
                    this->valve_open_door = valve_open_door;
                    this->open_EV = open_EV;
                }

                friend bool operator ==(const _ProjectionRead_close_valve_door_open& o1, const _ProjectionRead_close_valve_door_open& o2) {
                    return o1.valve_open_door == (o2.valve_open_door) && o1.open_EV == (o2.open_EV);
                }

                friend bool operator !=(const _ProjectionRead_close_valve_door_open& o1, const _ProjectionRead_close_valve_door_open& o2) {
                    return o1.valve_open_door != (o2.valve_open_door) || o1.open_EV != (o2.open_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_close_valve_door_open& e) {
                    strm << "{";
                    strm << "valve_open_door: " << e.valve_open_door;
                    strm << ", ";
                    strm << "open_EV: " << e.open_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_open_door.hashCode() << 1);
                    result = 31 * result + (open_EV.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_close_valve_door_open {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_close_valve_door_open& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_close_valve_door_open& obj1, const _ProjectionRead__tr_close_valve_door_open& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_open_door;
                BBoolean open_EV;

                _ProjectionRead__tr_close_valve_door_open(const VALVE_STATE& valve_open_door, const BBoolean& open_EV) {
                    this->valve_open_door = valve_open_door;
                    this->open_EV = open_EV;
                }

                friend bool operator ==(const _ProjectionRead__tr_close_valve_door_open& o1, const _ProjectionRead__tr_close_valve_door_open& o2) {
                    return o1.valve_open_door == (o2.valve_open_door) && o1.open_EV == (o2.open_EV);
                }

                friend bool operator !=(const _ProjectionRead__tr_close_valve_door_open& o1, const _ProjectionRead__tr_close_valve_door_open& o2) {
                    return o1.valve_open_door != (o2.valve_open_door) || o1.open_EV != (o2.open_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_close_valve_door_open& e) {
                    strm << "{";
                    strm << "valve_open_door: " << e.valve_open_door;
                    strm << ", "; 
                    strm << "open_EV: " << e.open_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_open_door.hashCode() << 1);
                    result = 31 * result + (open_EV.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_close_valve_door_open {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_close_valve_door_open& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_close_valve_door_open& obj1, const _ProjectionWrite_close_valve_door_open& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_open_door;

                _ProjectionWrite_close_valve_door_open(const VALVE_STATE& valve_open_door) {
                    this->valve_open_door = valve_open_door;
                }

                friend bool operator ==(const _ProjectionWrite_close_valve_door_open& o1, const _ProjectionWrite_close_valve_door_open& o2) {
                    return o1.valve_open_door == (o2.valve_open_door);
                }

                friend bool operator !=(const _ProjectionWrite_close_valve_door_open& o1, const _ProjectionWrite_close_valve_door_open& o2) {
                    return o1.valve_open_door != (o2.valve_open_door);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_close_valve_door_open& e) {
                    strm << "{";
                    strm << "valve_open_door: " << e.valve_open_door;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_open_door.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_open_valve_door_close {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_open_valve_door_close& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_open_valve_door_close& obj1, const _ProjectionRead_open_valve_door_close& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_close_door;
                BBoolean close_EV;

                _ProjectionRead_open_valve_door_close(const VALVE_STATE& valve_close_door, const BBoolean& close_EV) {
                    this->valve_close_door = valve_close_door;
                    this->close_EV = close_EV;
                }

                friend bool operator ==(const _ProjectionRead_open_valve_door_close& o1, const _ProjectionRead_open_valve_door_close& o2) {
                    return o1.valve_close_door == (o2.valve_close_door) && o1.close_EV == (o2.close_EV);
                }

                friend bool operator !=(const _ProjectionRead_open_valve_door_close& o1, const _ProjectionRead_open_valve_door_close& o2) {
                    return o1.valve_close_door != (o2.valve_close_door) || o1.close_EV != (o2.close_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_open_valve_door_close& e) {
                    strm << "{";
                    strm << "valve_close_door: " << e.valve_close_door;
                    strm << ", ";
                    strm << "close_EV: " << e.close_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_close_door.hashCode() << 1);
                    result = 31 * result + (close_EV.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_open_valve_door_close {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_open_valve_door_close& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_open_valve_door_close& obj1, const _ProjectionRead__tr_open_valve_door_close& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_close_door;
                BBoolean close_EV;

                _ProjectionRead__tr_open_valve_door_close(const VALVE_STATE& valve_close_door, const BBoolean& close_EV) {
                    this->valve_close_door = valve_close_door;
                    this->close_EV = close_EV;
                }

                friend bool operator ==(const _ProjectionRead__tr_open_valve_door_close& o1, const _ProjectionRead__tr_open_valve_door_close& o2) {
                    return o1.valve_close_door == (o2.valve_close_door) && o1.close_EV == (o2.close_EV);
                }

                friend bool operator !=(const _ProjectionRead__tr_open_valve_door_close& o1, const _ProjectionRead__tr_open_valve_door_close& o2) {
                    return o1.valve_close_door != (o2.valve_close_door) || o1.close_EV != (o2.close_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_open_valve_door_close& e) {
                    strm << "{";
                    strm << "valve_close_door: " << e.valve_close_door;
                    strm << ", "; 
                    strm << "close_EV: " << e.close_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_close_door.hashCode() << 1);
                    result = 31 * result + (close_EV.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_open_valve_door_close {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_open_valve_door_close& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_open_valve_door_close& obj1, const _ProjectionWrite_open_valve_door_close& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_close_door;

                _ProjectionWrite_open_valve_door_close(const VALVE_STATE& valve_close_door) {
                    this->valve_close_door = valve_close_door;
                }

                friend bool operator ==(const _ProjectionWrite_open_valve_door_close& o1, const _ProjectionWrite_open_valve_door_close& o2) {
                    return o1.valve_close_door == (o2.valve_close_door);
                }

                friend bool operator !=(const _ProjectionWrite_open_valve_door_close& o1, const _ProjectionWrite_open_valve_door_close& o2) {
                    return o1.valve_close_door != (o2.valve_close_door);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_open_valve_door_close& e) {
                    strm << "{";
                    strm << "valve_close_door: " << e.valve_close_door;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_close_door.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_close_valve_door_close {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_close_valve_door_close& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_close_valve_door_close& obj1, const _ProjectionRead_close_valve_door_close& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_close_door;
                BBoolean close_EV;

                _ProjectionRead_close_valve_door_close(const VALVE_STATE& valve_close_door, const BBoolean& close_EV) {
                    this->valve_close_door = valve_close_door;
                    this->close_EV = close_EV;
                }

                friend bool operator ==(const _ProjectionRead_close_valve_door_close& o1, const _ProjectionRead_close_valve_door_close& o2) {
                    return o1.valve_close_door == (o2.valve_close_door) && o1.close_EV == (o2.close_EV);
                }

                friend bool operator !=(const _ProjectionRead_close_valve_door_close& o1, const _ProjectionRead_close_valve_door_close& o2) {
                    return o1.valve_close_door != (o2.valve_close_door) || o1.close_EV != (o2.close_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_close_valve_door_close& e) {
                    strm << "{";
                    strm << "valve_close_door: " << e.valve_close_door;
                    strm << ", ";
                    strm << "close_EV: " << e.close_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_close_door.hashCode() << 1);
                    result = 31 * result + (close_EV.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_close_valve_door_close {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_close_valve_door_close& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_close_valve_door_close& obj1, const _ProjectionRead__tr_close_valve_door_close& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_close_door;
                BBoolean close_EV;

                _ProjectionRead__tr_close_valve_door_close(const VALVE_STATE& valve_close_door, const BBoolean& close_EV) {
                    this->valve_close_door = valve_close_door;
                    this->close_EV = close_EV;
                }

                friend bool operator ==(const _ProjectionRead__tr_close_valve_door_close& o1, const _ProjectionRead__tr_close_valve_door_close& o2) {
                    return o1.valve_close_door == (o2.valve_close_door) && o1.close_EV == (o2.close_EV);
                }

                friend bool operator !=(const _ProjectionRead__tr_close_valve_door_close& o1, const _ProjectionRead__tr_close_valve_door_close& o2) {
                    return o1.valve_close_door != (o2.valve_close_door) || o1.close_EV != (o2.close_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_close_valve_door_close& e) {
                    strm << "{";
                    strm << "valve_close_door: " << e.valve_close_door;
                    strm << ", "; 
                    strm << "close_EV: " << e.close_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_close_door.hashCode() << 1);
                    result = 31 * result + (close_EV.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_close_valve_door_close {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_close_valve_door_close& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_close_valve_door_close& obj1, const _ProjectionWrite_close_valve_door_close& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_close_door;

                _ProjectionWrite_close_valve_door_close(const VALVE_STATE& valve_close_door) {
                    this->valve_close_door = valve_close_door;
                }

                friend bool operator ==(const _ProjectionWrite_close_valve_door_close& o1, const _ProjectionWrite_close_valve_door_close& o2) {
                    return o1.valve_close_door == (o2.valve_close_door);
                }

                friend bool operator !=(const _ProjectionWrite_close_valve_door_close& o1, const _ProjectionWrite_close_valve_door_close& o2) {
                    return o1.valve_close_door != (o2.valve_close_door);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_close_valve_door_close& e) {
                    strm << "{";
                    strm << "valve_close_door: " << e.valve_close_door;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_close_door.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_open_valve_retract_gear {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_open_valve_retract_gear& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_open_valve_retract_gear& obj1, const _ProjectionRead_open_valve_retract_gear& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_retract_gear;
                BBoolean retract_EV;

                _ProjectionRead_open_valve_retract_gear(const VALVE_STATE& valve_retract_gear, const BBoolean& retract_EV) {
                    this->valve_retract_gear = valve_retract_gear;
                    this->retract_EV = retract_EV;
                }

                friend bool operator ==(const _ProjectionRead_open_valve_retract_gear& o1, const _ProjectionRead_open_valve_retract_gear& o2) {
                    return o1.valve_retract_gear == (o2.valve_retract_gear) && o1.retract_EV == (o2.retract_EV);
                }

                friend bool operator !=(const _ProjectionRead_open_valve_retract_gear& o1, const _ProjectionRead_open_valve_retract_gear& o2) {
                    return o1.valve_retract_gear != (o2.valve_retract_gear) || o1.retract_EV != (o2.retract_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_open_valve_retract_gear& e) {
                    strm << "{";
                    strm << "valve_retract_gear: " << e.valve_retract_gear;
                    strm << ", ";
                    strm << "retract_EV: " << e.retract_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_retract_gear.hashCode() << 1);
                    result = 31 * result + (retract_EV.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_open_valve_retract_gear {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_open_valve_retract_gear& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_open_valve_retract_gear& obj1, const _ProjectionRead__tr_open_valve_retract_gear& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_retract_gear;
                BBoolean retract_EV;

                _ProjectionRead__tr_open_valve_retract_gear(const VALVE_STATE& valve_retract_gear, const BBoolean& retract_EV) {
                    this->valve_retract_gear = valve_retract_gear;
                    this->retract_EV = retract_EV;
                }

                friend bool operator ==(const _ProjectionRead__tr_open_valve_retract_gear& o1, const _ProjectionRead__tr_open_valve_retract_gear& o2) {
                    return o1.valve_retract_gear == (o2.valve_retract_gear) && o1.retract_EV == (o2.retract_EV);
                }

                friend bool operator !=(const _ProjectionRead__tr_open_valve_retract_gear& o1, const _ProjectionRead__tr_open_valve_retract_gear& o2) {
                    return o1.valve_retract_gear != (o2.valve_retract_gear) || o1.retract_EV != (o2.retract_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_open_valve_retract_gear& e) {
                    strm << "{";
                    strm << "valve_retract_gear: " << e.valve_retract_gear;
                    strm << ", "; 
                    strm << "retract_EV: " << e.retract_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_retract_gear.hashCode() << 1);
                    result = 31 * result + (retract_EV.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_open_valve_retract_gear {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_open_valve_retract_gear& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_open_valve_retract_gear& obj1, const _ProjectionWrite_open_valve_retract_gear& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_retract_gear;

                _ProjectionWrite_open_valve_retract_gear(const VALVE_STATE& valve_retract_gear) {
                    this->valve_retract_gear = valve_retract_gear;
                }

                friend bool operator ==(const _ProjectionWrite_open_valve_retract_gear& o1, const _ProjectionWrite_open_valve_retract_gear& o2) {
                    return o1.valve_retract_gear == (o2.valve_retract_gear);
                }

                friend bool operator !=(const _ProjectionWrite_open_valve_retract_gear& o1, const _ProjectionWrite_open_valve_retract_gear& o2) {
                    return o1.valve_retract_gear != (o2.valve_retract_gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_open_valve_retract_gear& e) {
                    strm << "{";
                    strm << "valve_retract_gear: " << e.valve_retract_gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_retract_gear.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_close_valve_retract_gear {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_close_valve_retract_gear& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_close_valve_retract_gear& obj1, const _ProjectionRead_close_valve_retract_gear& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_retract_gear;
                BBoolean retract_EV;

                _ProjectionRead_close_valve_retract_gear(const VALVE_STATE& valve_retract_gear, const BBoolean& retract_EV) {
                    this->valve_retract_gear = valve_retract_gear;
                    this->retract_EV = retract_EV;
                }

                friend bool operator ==(const _ProjectionRead_close_valve_retract_gear& o1, const _ProjectionRead_close_valve_retract_gear& o2) {
                    return o1.valve_retract_gear == (o2.valve_retract_gear) && o1.retract_EV == (o2.retract_EV);
                }

                friend bool operator !=(const _ProjectionRead_close_valve_retract_gear& o1, const _ProjectionRead_close_valve_retract_gear& o2) {
                    return o1.valve_retract_gear != (o2.valve_retract_gear) || o1.retract_EV != (o2.retract_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_close_valve_retract_gear& e) {
                    strm << "{";
                    strm << "valve_retract_gear: " << e.valve_retract_gear;
                    strm << ", ";
                    strm << "retract_EV: " << e.retract_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_retract_gear.hashCode() << 1);
                    result = 31 * result + (retract_EV.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_close_valve_retract_gear {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_close_valve_retract_gear& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_close_valve_retract_gear& obj1, const _ProjectionRead__tr_close_valve_retract_gear& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_retract_gear;
                BBoolean retract_EV;

                _ProjectionRead__tr_close_valve_retract_gear(const VALVE_STATE& valve_retract_gear, const BBoolean& retract_EV) {
                    this->valve_retract_gear = valve_retract_gear;
                    this->retract_EV = retract_EV;
                }

                friend bool operator ==(const _ProjectionRead__tr_close_valve_retract_gear& o1, const _ProjectionRead__tr_close_valve_retract_gear& o2) {
                    return o1.valve_retract_gear == (o2.valve_retract_gear) && o1.retract_EV == (o2.retract_EV);
                }

                friend bool operator !=(const _ProjectionRead__tr_close_valve_retract_gear& o1, const _ProjectionRead__tr_close_valve_retract_gear& o2) {
                    return o1.valve_retract_gear != (o2.valve_retract_gear) || o1.retract_EV != (o2.retract_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_close_valve_retract_gear& e) {
                    strm << "{";
                    strm << "valve_retract_gear: " << e.valve_retract_gear;
                    strm << ", "; 
                    strm << "retract_EV: " << e.retract_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_retract_gear.hashCode() << 1);
                    result = 31 * result + (retract_EV.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_close_valve_retract_gear {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_close_valve_retract_gear& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_close_valve_retract_gear& obj1, const _ProjectionWrite_close_valve_retract_gear& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_retract_gear;

                _ProjectionWrite_close_valve_retract_gear(const VALVE_STATE& valve_retract_gear) {
                    this->valve_retract_gear = valve_retract_gear;
                }

                friend bool operator ==(const _ProjectionWrite_close_valve_retract_gear& o1, const _ProjectionWrite_close_valve_retract_gear& o2) {
                    return o1.valve_retract_gear == (o2.valve_retract_gear);
                }

                friend bool operator !=(const _ProjectionWrite_close_valve_retract_gear& o1, const _ProjectionWrite_close_valve_retract_gear& o2) {
                    return o1.valve_retract_gear != (o2.valve_retract_gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_close_valve_retract_gear& e) {
                    strm << "{";
                    strm << "valve_retract_gear: " << e.valve_retract_gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_retract_gear.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_open_valve_extend_gear {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_open_valve_extend_gear& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_open_valve_extend_gear& obj1, const _ProjectionRead_open_valve_extend_gear& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean extend_EV;
                VALVE_STATE valve_extend_gear;

                _ProjectionRead_open_valve_extend_gear(const BBoolean& extend_EV, const VALVE_STATE& valve_extend_gear) {
                    this->extend_EV = extend_EV;
                    this->valve_extend_gear = valve_extend_gear;
                }

                friend bool operator ==(const _ProjectionRead_open_valve_extend_gear& o1, const _ProjectionRead_open_valve_extend_gear& o2) {
                    return o1.extend_EV == (o2.extend_EV) && o1.valve_extend_gear == (o2.valve_extend_gear);
                }

                friend bool operator !=(const _ProjectionRead_open_valve_extend_gear& o1, const _ProjectionRead_open_valve_extend_gear& o2) {
                    return o1.extend_EV != (o2.extend_EV) || o1.valve_extend_gear != (o2.valve_extend_gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_open_valve_extend_gear& e) {
                    strm << "{";
                    strm << "extend_EV: " << e.extend_EV;
                    strm << ", ";
                    strm << "valve_extend_gear: " << e.valve_extend_gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (extend_EV.hashCode() << 1);
                    result = 31 * result + (valve_extend_gear.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_open_valve_extend_gear {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_open_valve_extend_gear& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_open_valve_extend_gear& obj1, const _ProjectionRead__tr_open_valve_extend_gear& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean extend_EV;
                VALVE_STATE valve_extend_gear;

                _ProjectionRead__tr_open_valve_extend_gear(const BBoolean& extend_EV, const VALVE_STATE& valve_extend_gear) {
                    this->extend_EV = extend_EV;
                    this->valve_extend_gear = valve_extend_gear;
                }

                friend bool operator ==(const _ProjectionRead__tr_open_valve_extend_gear& o1, const _ProjectionRead__tr_open_valve_extend_gear& o2) {
                    return o1.extend_EV == (o2.extend_EV) && o1.valve_extend_gear == (o2.valve_extend_gear);
                }

                friend bool operator !=(const _ProjectionRead__tr_open_valve_extend_gear& o1, const _ProjectionRead__tr_open_valve_extend_gear& o2) {
                    return o1.extend_EV != (o2.extend_EV) || o1.valve_extend_gear != (o2.valve_extend_gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_open_valve_extend_gear& e) {
                    strm << "{";
                    strm << "extend_EV: " << e.extend_EV;
                    strm << ", "; 
                    strm << "valve_extend_gear: " << e.valve_extend_gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (extend_EV.hashCode() << 1);
                    result = 31 * result + (valve_extend_gear.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_open_valve_extend_gear {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_open_valve_extend_gear& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_open_valve_extend_gear& obj1, const _ProjectionWrite_open_valve_extend_gear& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_extend_gear;

                _ProjectionWrite_open_valve_extend_gear(const VALVE_STATE& valve_extend_gear) {
                    this->valve_extend_gear = valve_extend_gear;
                }

                friend bool operator ==(const _ProjectionWrite_open_valve_extend_gear& o1, const _ProjectionWrite_open_valve_extend_gear& o2) {
                    return o1.valve_extend_gear == (o2.valve_extend_gear);
                }

                friend bool operator !=(const _ProjectionWrite_open_valve_extend_gear& o1, const _ProjectionWrite_open_valve_extend_gear& o2) {
                    return o1.valve_extend_gear != (o2.valve_extend_gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_open_valve_extend_gear& e) {
                    strm << "{";
                    strm << "valve_extend_gear: " << e.valve_extend_gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_extend_gear.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_close_valve_extend_gear {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_close_valve_extend_gear& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_close_valve_extend_gear& obj1, const _ProjectionRead_close_valve_extend_gear& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean extend_EV;
                VALVE_STATE valve_extend_gear;

                _ProjectionRead_close_valve_extend_gear(const BBoolean& extend_EV, const VALVE_STATE& valve_extend_gear) {
                    this->extend_EV = extend_EV;
                    this->valve_extend_gear = valve_extend_gear;
                }

                friend bool operator ==(const _ProjectionRead_close_valve_extend_gear& o1, const _ProjectionRead_close_valve_extend_gear& o2) {
                    return o1.extend_EV == (o2.extend_EV) && o1.valve_extend_gear == (o2.valve_extend_gear);
                }

                friend bool operator !=(const _ProjectionRead_close_valve_extend_gear& o1, const _ProjectionRead_close_valve_extend_gear& o2) {
                    return o1.extend_EV != (o2.extend_EV) || o1.valve_extend_gear != (o2.valve_extend_gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_close_valve_extend_gear& e) {
                    strm << "{";
                    strm << "extend_EV: " << e.extend_EV;
                    strm << ", ";
                    strm << "valve_extend_gear: " << e.valve_extend_gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (extend_EV.hashCode() << 1);
                    result = 31 * result + (valve_extend_gear.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_close_valve_extend_gear {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_close_valve_extend_gear& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_close_valve_extend_gear& obj1, const _ProjectionRead__tr_close_valve_extend_gear& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean extend_EV;
                VALVE_STATE valve_extend_gear;

                _ProjectionRead__tr_close_valve_extend_gear(const BBoolean& extend_EV, const VALVE_STATE& valve_extend_gear) {
                    this->extend_EV = extend_EV;
                    this->valve_extend_gear = valve_extend_gear;
                }

                friend bool operator ==(const _ProjectionRead__tr_close_valve_extend_gear& o1, const _ProjectionRead__tr_close_valve_extend_gear& o2) {
                    return o1.extend_EV == (o2.extend_EV) && o1.valve_extend_gear == (o2.valve_extend_gear);
                }

                friend bool operator !=(const _ProjectionRead__tr_close_valve_extend_gear& o1, const _ProjectionRead__tr_close_valve_extend_gear& o2) {
                    return o1.extend_EV != (o2.extend_EV) || o1.valve_extend_gear != (o2.valve_extend_gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_close_valve_extend_gear& e) {
                    strm << "{";
                    strm << "extend_EV: " << e.extend_EV;
                    strm << ", "; 
                    strm << "valve_extend_gear: " << e.valve_extend_gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (extend_EV.hashCode() << 1);
                    result = 31 * result + (valve_extend_gear.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_close_valve_extend_gear {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_close_valve_extend_gear& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_close_valve_extend_gear& obj1, const _ProjectionWrite_close_valve_extend_gear& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_extend_gear;

                _ProjectionWrite_close_valve_extend_gear(const VALVE_STATE& valve_extend_gear) {
                    this->valve_extend_gear = valve_extend_gear;
                }

                friend bool operator ==(const _ProjectionWrite_close_valve_extend_gear& o1, const _ProjectionWrite_close_valve_extend_gear& o2) {
                    return o1.valve_extend_gear == (o2.valve_extend_gear);
                }

                friend bool operator !=(const _ProjectionWrite_close_valve_extend_gear& o1, const _ProjectionWrite_close_valve_extend_gear& o2) {
                    return o1.valve_extend_gear != (o2.valve_extend_gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_close_valve_extend_gear& e) {
                    strm << "{";
                    strm << "valve_extend_gear: " << e.valve_extend_gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_extend_gear.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_con_stimulate_open_door_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_con_stimulate_open_door_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_con_stimulate_open_door_valve& obj1, const _ProjectionRead_con_stimulate_open_door_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                BBoolean open_EV;
                PLANE_STATE shock_absorber;
                BBoolean close_EV;
                BBoolean general_EV;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead_con_stimulate_open_door_valve(const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const BBoolean& open_EV, const PLANE_STATE& shock_absorber, const BBoolean& close_EV, const BBoolean& general_EV, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->handle = handle;
                    this->doors = doors;
                    this->open_EV = open_EV;
                    this->shock_absorber = shock_absorber;
                    this->close_EV = close_EV;
                    this->general_EV = general_EV;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead_con_stimulate_open_door_valve& o1, const _ProjectionRead_con_stimulate_open_door_valve& o2) {
                    return o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.open_EV == (o2.open_EV) && o1.shock_absorber == (o2.shock_absorber) && o1.close_EV == (o2.close_EV) && o1.general_EV == (o2.general_EV) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead_con_stimulate_open_door_valve& o1, const _ProjectionRead_con_stimulate_open_door_valve& o2) {
                    return o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.open_EV != (o2.open_EV) || o1.shock_absorber != (o2.shock_absorber) || o1.close_EV != (o2.close_EV) || o1.general_EV != (o2.general_EV) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_con_stimulate_open_door_valve& e) {
                    strm << "{";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "open_EV: " << e.open_EV;
                    strm << ", ";
                    strm << "shock_absorber: " << e.shock_absorber;
                    strm << ", ";
                    strm << "close_EV: " << e.close_EV;
                    strm << ", ";
                    strm << "general_EV: " << e.general_EV;
                    strm << ", ";
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (open_EV.hashCode() << 1);
                    result = 31 * result + (shock_absorber.hashCode() << 1);
                    result = 31 * result + (close_EV.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_con_stimulate_open_door_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_con_stimulate_open_door_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_con_stimulate_open_door_valve& obj1, const _ProjectionRead__tr_con_stimulate_open_door_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                BBoolean open_EV;
                PLANE_STATE shock_absorber;
                BBoolean close_EV;
                BBoolean general_EV;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead__tr_con_stimulate_open_door_valve(const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const BBoolean& open_EV, const PLANE_STATE& shock_absorber, const BBoolean& close_EV, const BBoolean& general_EV, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->handle = handle;
                    this->doors = doors;
                    this->open_EV = open_EV;
                    this->shock_absorber = shock_absorber;
                    this->close_EV = close_EV;
                    this->general_EV = general_EV;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead__tr_con_stimulate_open_door_valve& o1, const _ProjectionRead__tr_con_stimulate_open_door_valve& o2) {
                    return o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.open_EV == (o2.open_EV) && o1.shock_absorber == (o2.shock_absorber) && o1.close_EV == (o2.close_EV) && o1.general_EV == (o2.general_EV) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead__tr_con_stimulate_open_door_valve& o1, const _ProjectionRead__tr_con_stimulate_open_door_valve& o2) {
                    return o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.open_EV != (o2.open_EV) || o1.shock_absorber != (o2.shock_absorber) || o1.close_EV != (o2.close_EV) || o1.general_EV != (o2.general_EV) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_con_stimulate_open_door_valve& e) {
                    strm << "{";
                    strm << "handle: " << e.handle;
                    strm << ", "; 
                    strm << "doors: " << e.doors;
                    strm << ", "; 
                    strm << "open_EV: " << e.open_EV;
                    strm << ", "; 
                    strm << "shock_absorber: " << e.shock_absorber;
                    strm << ", "; 
                    strm << "close_EV: " << e.close_EV;
                    strm << ", "; 
                    strm << "general_EV: " << e.general_EV;
                    strm << ", "; 
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (open_EV.hashCode() << 1);
                    result = 31 * result + (shock_absorber.hashCode() << 1);
                    result = 31 * result + (close_EV.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_con_stimulate_open_door_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_con_stimulate_open_door_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_con_stimulate_open_door_valve& obj1, const _ProjectionWrite_con_stimulate_open_door_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean open_EV;

                _ProjectionWrite_con_stimulate_open_door_valve(const BBoolean& open_EV) {
                    this->open_EV = open_EV;
                }

                friend bool operator ==(const _ProjectionWrite_con_stimulate_open_door_valve& o1, const _ProjectionWrite_con_stimulate_open_door_valve& o2) {
                    return o1.open_EV == (o2.open_EV);
                }

                friend bool operator !=(const _ProjectionWrite_con_stimulate_open_door_valve& o1, const _ProjectionWrite_con_stimulate_open_door_valve& o2) {
                    return o1.open_EV != (o2.open_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_con_stimulate_open_door_valve& e) {
                    strm << "{";
                    strm << "open_EV: " << e.open_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (open_EV.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_con_stop_stimulate_open_door_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_con_stop_stimulate_open_door_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_con_stop_stimulate_open_door_valve& obj1, const _ProjectionRead_con_stop_stimulate_open_door_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean extend_EV;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                BBoolean open_EV;
                PLANE_STATE shock_absorber;
                BBoolean general_EV;
                BBoolean retract_EV;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead_con_stop_stimulate_open_door_valve(const BBoolean& extend_EV, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const BBoolean& open_EV, const PLANE_STATE& shock_absorber, const BBoolean& general_EV, const BBoolean& retract_EV, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->extend_EV = extend_EV;
                    this->handle = handle;
                    this->doors = doors;
                    this->open_EV = open_EV;
                    this->shock_absorber = shock_absorber;
                    this->general_EV = general_EV;
                    this->retract_EV = retract_EV;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead_con_stop_stimulate_open_door_valve& o1, const _ProjectionRead_con_stop_stimulate_open_door_valve& o2) {
                    return o1.extend_EV == (o2.extend_EV) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.open_EV == (o2.open_EV) && o1.shock_absorber == (o2.shock_absorber) && o1.general_EV == (o2.general_EV) && o1.retract_EV == (o2.retract_EV) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead_con_stop_stimulate_open_door_valve& o1, const _ProjectionRead_con_stop_stimulate_open_door_valve& o2) {
                    return o1.extend_EV != (o2.extend_EV) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.open_EV != (o2.open_EV) || o1.shock_absorber != (o2.shock_absorber) || o1.general_EV != (o2.general_EV) || o1.retract_EV != (o2.retract_EV) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_con_stop_stimulate_open_door_valve& e) {
                    strm << "{";
                    strm << "extend_EV: " << e.extend_EV;
                    strm << ", ";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "open_EV: " << e.open_EV;
                    strm << ", ";
                    strm << "shock_absorber: " << e.shock_absorber;
                    strm << ", ";
                    strm << "general_EV: " << e.general_EV;
                    strm << ", ";
                    strm << "retract_EV: " << e.retract_EV;
                    strm << ", ";
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (extend_EV.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (open_EV.hashCode() << 1);
                    result = 31 * result + (shock_absorber.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    result = 31 * result + (retract_EV.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_con_stop_stimulate_open_door_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_con_stop_stimulate_open_door_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_con_stop_stimulate_open_door_valve& obj1, const _ProjectionRead__tr_con_stop_stimulate_open_door_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean extend_EV;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                BBoolean open_EV;
                PLANE_STATE shock_absorber;
                BBoolean general_EV;
                BBoolean retract_EV;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead__tr_con_stop_stimulate_open_door_valve(const BBoolean& extend_EV, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const BBoolean& open_EV, const PLANE_STATE& shock_absorber, const BBoolean& general_EV, const BBoolean& retract_EV, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->extend_EV = extend_EV;
                    this->handle = handle;
                    this->doors = doors;
                    this->open_EV = open_EV;
                    this->shock_absorber = shock_absorber;
                    this->general_EV = general_EV;
                    this->retract_EV = retract_EV;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead__tr_con_stop_stimulate_open_door_valve& o1, const _ProjectionRead__tr_con_stop_stimulate_open_door_valve& o2) {
                    return o1.extend_EV == (o2.extend_EV) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.open_EV == (o2.open_EV) && o1.shock_absorber == (o2.shock_absorber) && o1.general_EV == (o2.general_EV) && o1.retract_EV == (o2.retract_EV) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead__tr_con_stop_stimulate_open_door_valve& o1, const _ProjectionRead__tr_con_stop_stimulate_open_door_valve& o2) {
                    return o1.extend_EV != (o2.extend_EV) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.open_EV != (o2.open_EV) || o1.shock_absorber != (o2.shock_absorber) || o1.general_EV != (o2.general_EV) || o1.retract_EV != (o2.retract_EV) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_con_stop_stimulate_open_door_valve& e) {
                    strm << "{";
                    strm << "extend_EV: " << e.extend_EV;
                    strm << ", "; 
                    strm << "handle: " << e.handle;
                    strm << ", "; 
                    strm << "doors: " << e.doors;
                    strm << ", "; 
                    strm << "open_EV: " << e.open_EV;
                    strm << ", "; 
                    strm << "shock_absorber: " << e.shock_absorber;
                    strm << ", "; 
                    strm << "general_EV: " << e.general_EV;
                    strm << ", "; 
                    strm << "retract_EV: " << e.retract_EV;
                    strm << ", "; 
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (extend_EV.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (open_EV.hashCode() << 1);
                    result = 31 * result + (shock_absorber.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    result = 31 * result + (retract_EV.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_con_stop_stimulate_open_door_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_con_stop_stimulate_open_door_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_con_stop_stimulate_open_door_valve& obj1, const _ProjectionWrite_con_stop_stimulate_open_door_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean open_EV;

                _ProjectionWrite_con_stop_stimulate_open_door_valve(const BBoolean& open_EV) {
                    this->open_EV = open_EV;
                }

                friend bool operator ==(const _ProjectionWrite_con_stop_stimulate_open_door_valve& o1, const _ProjectionWrite_con_stop_stimulate_open_door_valve& o2) {
                    return o1.open_EV == (o2.open_EV);
                }

                friend bool operator !=(const _ProjectionWrite_con_stop_stimulate_open_door_valve& o1, const _ProjectionWrite_con_stop_stimulate_open_door_valve& o2) {
                    return o1.open_EV != (o2.open_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_con_stop_stimulate_open_door_valve& e) {
                    strm << "{";
                    strm << "open_EV: " << e.open_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (open_EV.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_con_stimulate_close_door_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_con_stimulate_close_door_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_con_stimulate_close_door_valve& obj1, const _ProjectionRead_con_stimulate_close_door_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean extend_EV;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                BBoolean open_EV;
                PLANE_STATE shock_absorber;
                BBoolean close_EV;
                BBoolean general_EV;
                BBoolean retract_EV;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead_con_stimulate_close_door_valve(const BBoolean& extend_EV, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const BBoolean& open_EV, const PLANE_STATE& shock_absorber, const BBoolean& close_EV, const BBoolean& general_EV, const BBoolean& retract_EV, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->extend_EV = extend_EV;
                    this->handle = handle;
                    this->doors = doors;
                    this->open_EV = open_EV;
                    this->shock_absorber = shock_absorber;
                    this->close_EV = close_EV;
                    this->general_EV = general_EV;
                    this->retract_EV = retract_EV;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead_con_stimulate_close_door_valve& o1, const _ProjectionRead_con_stimulate_close_door_valve& o2) {
                    return o1.extend_EV == (o2.extend_EV) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.open_EV == (o2.open_EV) && o1.shock_absorber == (o2.shock_absorber) && o1.close_EV == (o2.close_EV) && o1.general_EV == (o2.general_EV) && o1.retract_EV == (o2.retract_EV) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead_con_stimulate_close_door_valve& o1, const _ProjectionRead_con_stimulate_close_door_valve& o2) {
                    return o1.extend_EV != (o2.extend_EV) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.open_EV != (o2.open_EV) || o1.shock_absorber != (o2.shock_absorber) || o1.close_EV != (o2.close_EV) || o1.general_EV != (o2.general_EV) || o1.retract_EV != (o2.retract_EV) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_con_stimulate_close_door_valve& e) {
                    strm << "{";
                    strm << "extend_EV: " << e.extend_EV;
                    strm << ", ";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "open_EV: " << e.open_EV;
                    strm << ", ";
                    strm << "shock_absorber: " << e.shock_absorber;
                    strm << ", ";
                    strm << "close_EV: " << e.close_EV;
                    strm << ", ";
                    strm << "general_EV: " << e.general_EV;
                    strm << ", ";
                    strm << "retract_EV: " << e.retract_EV;
                    strm << ", ";
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (extend_EV.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (open_EV.hashCode() << 1);
                    result = 31 * result + (shock_absorber.hashCode() << 1);
                    result = 31 * result + (close_EV.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    result = 31 * result + (retract_EV.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_con_stimulate_close_door_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_con_stimulate_close_door_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_con_stimulate_close_door_valve& obj1, const _ProjectionRead__tr_con_stimulate_close_door_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean extend_EV;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                BBoolean open_EV;
                PLANE_STATE shock_absorber;
                BBoolean close_EV;
                BBoolean general_EV;
                BBoolean retract_EV;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead__tr_con_stimulate_close_door_valve(const BBoolean& extend_EV, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const BBoolean& open_EV, const PLANE_STATE& shock_absorber, const BBoolean& close_EV, const BBoolean& general_EV, const BBoolean& retract_EV, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->extend_EV = extend_EV;
                    this->handle = handle;
                    this->doors = doors;
                    this->open_EV = open_EV;
                    this->shock_absorber = shock_absorber;
                    this->close_EV = close_EV;
                    this->general_EV = general_EV;
                    this->retract_EV = retract_EV;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead__tr_con_stimulate_close_door_valve& o1, const _ProjectionRead__tr_con_stimulate_close_door_valve& o2) {
                    return o1.extend_EV == (o2.extend_EV) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.open_EV == (o2.open_EV) && o1.shock_absorber == (o2.shock_absorber) && o1.close_EV == (o2.close_EV) && o1.general_EV == (o2.general_EV) && o1.retract_EV == (o2.retract_EV) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead__tr_con_stimulate_close_door_valve& o1, const _ProjectionRead__tr_con_stimulate_close_door_valve& o2) {
                    return o1.extend_EV != (o2.extend_EV) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.open_EV != (o2.open_EV) || o1.shock_absorber != (o2.shock_absorber) || o1.close_EV != (o2.close_EV) || o1.general_EV != (o2.general_EV) || o1.retract_EV != (o2.retract_EV) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_con_stimulate_close_door_valve& e) {
                    strm << "{";
                    strm << "extend_EV: " << e.extend_EV;
                    strm << ", "; 
                    strm << "handle: " << e.handle;
                    strm << ", "; 
                    strm << "doors: " << e.doors;
                    strm << ", "; 
                    strm << "open_EV: " << e.open_EV;
                    strm << ", "; 
                    strm << "shock_absorber: " << e.shock_absorber;
                    strm << ", "; 
                    strm << "close_EV: " << e.close_EV;
                    strm << ", "; 
                    strm << "general_EV: " << e.general_EV;
                    strm << ", "; 
                    strm << "retract_EV: " << e.retract_EV;
                    strm << ", "; 
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (extend_EV.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (open_EV.hashCode() << 1);
                    result = 31 * result + (shock_absorber.hashCode() << 1);
                    result = 31 * result + (close_EV.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    result = 31 * result + (retract_EV.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_con_stimulate_close_door_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_con_stimulate_close_door_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_con_stimulate_close_door_valve& obj1, const _ProjectionWrite_con_stimulate_close_door_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean close_EV;

                _ProjectionWrite_con_stimulate_close_door_valve(const BBoolean& close_EV) {
                    this->close_EV = close_EV;
                }

                friend bool operator ==(const _ProjectionWrite_con_stimulate_close_door_valve& o1, const _ProjectionWrite_con_stimulate_close_door_valve& o2) {
                    return o1.close_EV == (o2.close_EV);
                }

                friend bool operator !=(const _ProjectionWrite_con_stimulate_close_door_valve& o1, const _ProjectionWrite_con_stimulate_close_door_valve& o2) {
                    return o1.close_EV != (o2.close_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_con_stimulate_close_door_valve& e) {
                    strm << "{";
                    strm << "close_EV: " << e.close_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (close_EV.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_con_stop_stimulate_close_door_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_con_stop_stimulate_close_door_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_con_stop_stimulate_close_door_valve& obj1, const _ProjectionRead_con_stop_stimulate_close_door_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, DOOR_STATE > doors;
                PLANE_STATE shock_absorber;
                HANDLE_STATE handle;
                BBoolean close_EV;
                BBoolean general_EV;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead_con_stop_stimulate_close_door_valve(const BRelation<POSITION, DOOR_STATE >& doors, const PLANE_STATE& shock_absorber, const HANDLE_STATE& handle, const BBoolean& close_EV, const BBoolean& general_EV, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->doors = doors;
                    this->shock_absorber = shock_absorber;
                    this->handle = handle;
                    this->close_EV = close_EV;
                    this->general_EV = general_EV;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead_con_stop_stimulate_close_door_valve& o1, const _ProjectionRead_con_stop_stimulate_close_door_valve& o2) {
                    return o1.doors == (o2.doors) && o1.shock_absorber == (o2.shock_absorber) && o1.handle == (o2.handle) && o1.close_EV == (o2.close_EV) && o1.general_EV == (o2.general_EV) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead_con_stop_stimulate_close_door_valve& o1, const _ProjectionRead_con_stop_stimulate_close_door_valve& o2) {
                    return o1.doors != (o2.doors) || o1.shock_absorber != (o2.shock_absorber) || o1.handle != (o2.handle) || o1.close_EV != (o2.close_EV) || o1.general_EV != (o2.general_EV) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_con_stop_stimulate_close_door_valve& e) {
                    strm << "{";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "shock_absorber: " << e.shock_absorber;
                    strm << ", ";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "close_EV: " << e.close_EV;
                    strm << ", ";
                    strm << "general_EV: " << e.general_EV;
                    strm << ", ";
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (shock_absorber.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (close_EV.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_con_stop_stimulate_close_door_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_con_stop_stimulate_close_door_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_con_stop_stimulate_close_door_valve& obj1, const _ProjectionRead__tr_con_stop_stimulate_close_door_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, DOOR_STATE > doors;
                PLANE_STATE shock_absorber;
                HANDLE_STATE handle;
                BBoolean close_EV;
                BBoolean general_EV;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead__tr_con_stop_stimulate_close_door_valve(const BRelation<POSITION, DOOR_STATE >& doors, const PLANE_STATE& shock_absorber, const HANDLE_STATE& handle, const BBoolean& close_EV, const BBoolean& general_EV, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->doors = doors;
                    this->shock_absorber = shock_absorber;
                    this->handle = handle;
                    this->close_EV = close_EV;
                    this->general_EV = general_EV;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead__tr_con_stop_stimulate_close_door_valve& o1, const _ProjectionRead__tr_con_stop_stimulate_close_door_valve& o2) {
                    return o1.doors == (o2.doors) && o1.shock_absorber == (o2.shock_absorber) && o1.handle == (o2.handle) && o1.close_EV == (o2.close_EV) && o1.general_EV == (o2.general_EV) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead__tr_con_stop_stimulate_close_door_valve& o1, const _ProjectionRead__tr_con_stop_stimulate_close_door_valve& o2) {
                    return o1.doors != (o2.doors) || o1.shock_absorber != (o2.shock_absorber) || o1.handle != (o2.handle) || o1.close_EV != (o2.close_EV) || o1.general_EV != (o2.general_EV) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_con_stop_stimulate_close_door_valve& e) {
                    strm << "{";
                    strm << "doors: " << e.doors;
                    strm << ", "; 
                    strm << "shock_absorber: " << e.shock_absorber;
                    strm << ", "; 
                    strm << "handle: " << e.handle;
                    strm << ", "; 
                    strm << "close_EV: " << e.close_EV;
                    strm << ", "; 
                    strm << "general_EV: " << e.general_EV;
                    strm << ", "; 
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (shock_absorber.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (close_EV.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_con_stop_stimulate_close_door_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_con_stop_stimulate_close_door_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_con_stop_stimulate_close_door_valve& obj1, const _ProjectionWrite_con_stop_stimulate_close_door_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean close_EV;

                _ProjectionWrite_con_stop_stimulate_close_door_valve(const BBoolean& close_EV) {
                    this->close_EV = close_EV;
                }

                friend bool operator ==(const _ProjectionWrite_con_stop_stimulate_close_door_valve& o1, const _ProjectionWrite_con_stop_stimulate_close_door_valve& o2) {
                    return o1.close_EV == (o2.close_EV);
                }

                friend bool operator !=(const _ProjectionWrite_con_stop_stimulate_close_door_valve& o1, const _ProjectionWrite_con_stop_stimulate_close_door_valve& o2) {
                    return o1.close_EV != (o2.close_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_con_stop_stimulate_close_door_valve& e) {
                    strm << "{";
                    strm << "close_EV: " << e.close_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (close_EV.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_con_stimulate_retract_gear_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_con_stimulate_retract_gear_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_con_stimulate_retract_gear_valve& obj1, const _ProjectionRead_con_stimulate_retract_gear_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean extend_EV;
                BRelation<POSITION, DOOR_STATE > doors;
                BBoolean open_EV;
                PLANE_STATE shock_absorber;
                HANDLE_STATE handle;
                BBoolean general_EV;
                BBoolean retract_EV;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead_con_stimulate_retract_gear_valve(const BBoolean& extend_EV, const BRelation<POSITION, DOOR_STATE >& doors, const BBoolean& open_EV, const PLANE_STATE& shock_absorber, const HANDLE_STATE& handle, const BBoolean& general_EV, const BBoolean& retract_EV, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->extend_EV = extend_EV;
                    this->doors = doors;
                    this->open_EV = open_EV;
                    this->shock_absorber = shock_absorber;
                    this->handle = handle;
                    this->general_EV = general_EV;
                    this->retract_EV = retract_EV;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead_con_stimulate_retract_gear_valve& o1, const _ProjectionRead_con_stimulate_retract_gear_valve& o2) {
                    return o1.extend_EV == (o2.extend_EV) && o1.doors == (o2.doors) && o1.open_EV == (o2.open_EV) && o1.shock_absorber == (o2.shock_absorber) && o1.handle == (o2.handle) && o1.general_EV == (o2.general_EV) && o1.retract_EV == (o2.retract_EV) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead_con_stimulate_retract_gear_valve& o1, const _ProjectionRead_con_stimulate_retract_gear_valve& o2) {
                    return o1.extend_EV != (o2.extend_EV) || o1.doors != (o2.doors) || o1.open_EV != (o2.open_EV) || o1.shock_absorber != (o2.shock_absorber) || o1.handle != (o2.handle) || o1.general_EV != (o2.general_EV) || o1.retract_EV != (o2.retract_EV) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_con_stimulate_retract_gear_valve& e) {
                    strm << "{";
                    strm << "extend_EV: " << e.extend_EV;
                    strm << ", ";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "open_EV: " << e.open_EV;
                    strm << ", ";
                    strm << "shock_absorber: " << e.shock_absorber;
                    strm << ", ";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "general_EV: " << e.general_EV;
                    strm << ", ";
                    strm << "retract_EV: " << e.retract_EV;
                    strm << ", ";
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (extend_EV.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (open_EV.hashCode() << 1);
                    result = 31 * result + (shock_absorber.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    result = 31 * result + (retract_EV.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_con_stimulate_retract_gear_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_con_stimulate_retract_gear_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_con_stimulate_retract_gear_valve& obj1, const _ProjectionRead__tr_con_stimulate_retract_gear_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean extend_EV;
                BRelation<POSITION, DOOR_STATE > doors;
                BBoolean open_EV;
                PLANE_STATE shock_absorber;
                HANDLE_STATE handle;
                BBoolean general_EV;
                BBoolean retract_EV;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead__tr_con_stimulate_retract_gear_valve(const BBoolean& extend_EV, const BRelation<POSITION, DOOR_STATE >& doors, const BBoolean& open_EV, const PLANE_STATE& shock_absorber, const HANDLE_STATE& handle, const BBoolean& general_EV, const BBoolean& retract_EV, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->extend_EV = extend_EV;
                    this->doors = doors;
                    this->open_EV = open_EV;
                    this->shock_absorber = shock_absorber;
                    this->handle = handle;
                    this->general_EV = general_EV;
                    this->retract_EV = retract_EV;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead__tr_con_stimulate_retract_gear_valve& o1, const _ProjectionRead__tr_con_stimulate_retract_gear_valve& o2) {
                    return o1.extend_EV == (o2.extend_EV) && o1.doors == (o2.doors) && o1.open_EV == (o2.open_EV) && o1.shock_absorber == (o2.shock_absorber) && o1.handle == (o2.handle) && o1.general_EV == (o2.general_EV) && o1.retract_EV == (o2.retract_EV) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead__tr_con_stimulate_retract_gear_valve& o1, const _ProjectionRead__tr_con_stimulate_retract_gear_valve& o2) {
                    return o1.extend_EV != (o2.extend_EV) || o1.doors != (o2.doors) || o1.open_EV != (o2.open_EV) || o1.shock_absorber != (o2.shock_absorber) || o1.handle != (o2.handle) || o1.general_EV != (o2.general_EV) || o1.retract_EV != (o2.retract_EV) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_con_stimulate_retract_gear_valve& e) {
                    strm << "{";
                    strm << "extend_EV: " << e.extend_EV;
                    strm << ", "; 
                    strm << "doors: " << e.doors;
                    strm << ", "; 
                    strm << "open_EV: " << e.open_EV;
                    strm << ", "; 
                    strm << "shock_absorber: " << e.shock_absorber;
                    strm << ", "; 
                    strm << "handle: " << e.handle;
                    strm << ", "; 
                    strm << "general_EV: " << e.general_EV;
                    strm << ", "; 
                    strm << "retract_EV: " << e.retract_EV;
                    strm << ", "; 
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (extend_EV.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (open_EV.hashCode() << 1);
                    result = 31 * result + (shock_absorber.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    result = 31 * result + (retract_EV.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_con_stimulate_retract_gear_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_con_stimulate_retract_gear_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_con_stimulate_retract_gear_valve& obj1, const _ProjectionWrite_con_stimulate_retract_gear_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean retract_EV;

                _ProjectionWrite_con_stimulate_retract_gear_valve(const BBoolean& retract_EV) {
                    this->retract_EV = retract_EV;
                }

                friend bool operator ==(const _ProjectionWrite_con_stimulate_retract_gear_valve& o1, const _ProjectionWrite_con_stimulate_retract_gear_valve& o2) {
                    return o1.retract_EV == (o2.retract_EV);
                }

                friend bool operator !=(const _ProjectionWrite_con_stimulate_retract_gear_valve& o1, const _ProjectionWrite_con_stimulate_retract_gear_valve& o2) {
                    return o1.retract_EV != (o2.retract_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_con_stimulate_retract_gear_valve& e) {
                    strm << "{";
                    strm << "retract_EV: " << e.retract_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (retract_EV.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_con_stop_stimulate_retract_gear_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_con_stop_stimulate_retract_gear_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_con_stop_stimulate_retract_gear_valve& obj1, const _ProjectionRead_con_stop_stimulate_retract_gear_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                HANDLE_STATE handle;
                BBoolean general_EV;
                BBoolean retract_EV;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead_con_stop_stimulate_retract_gear_valve(const HANDLE_STATE& handle, const BBoolean& general_EV, const BBoolean& retract_EV, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->handle = handle;
                    this->general_EV = general_EV;
                    this->retract_EV = retract_EV;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead_con_stop_stimulate_retract_gear_valve& o1, const _ProjectionRead_con_stop_stimulate_retract_gear_valve& o2) {
                    return o1.handle == (o2.handle) && o1.general_EV == (o2.general_EV) && o1.retract_EV == (o2.retract_EV) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead_con_stop_stimulate_retract_gear_valve& o1, const _ProjectionRead_con_stop_stimulate_retract_gear_valve& o2) {
                    return o1.handle != (o2.handle) || o1.general_EV != (o2.general_EV) || o1.retract_EV != (o2.retract_EV) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_con_stop_stimulate_retract_gear_valve& e) {
                    strm << "{";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "general_EV: " << e.general_EV;
                    strm << ", ";
                    strm << "retract_EV: " << e.retract_EV;
                    strm << ", ";
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    result = 31 * result + (retract_EV.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve& obj1, const _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                HANDLE_STATE handle;
                BBoolean general_EV;
                BBoolean retract_EV;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve(const HANDLE_STATE& handle, const BBoolean& general_EV, const BBoolean& retract_EV, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->handle = handle;
                    this->general_EV = general_EV;
                    this->retract_EV = retract_EV;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve& o1, const _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve& o2) {
                    return o1.handle == (o2.handle) && o1.general_EV == (o2.general_EV) && o1.retract_EV == (o2.retract_EV) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve& o1, const _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve& o2) {
                    return o1.handle != (o2.handle) || o1.general_EV != (o2.general_EV) || o1.retract_EV != (o2.retract_EV) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve& e) {
                    strm << "{";
                    strm << "handle: " << e.handle;
                    strm << ", "; 
                    strm << "general_EV: " << e.general_EV;
                    strm << ", "; 
                    strm << "retract_EV: " << e.retract_EV;
                    strm << ", "; 
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    result = 31 * result + (retract_EV.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_con_stop_stimulate_retract_gear_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_con_stop_stimulate_retract_gear_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_con_stop_stimulate_retract_gear_valve& obj1, const _ProjectionWrite_con_stop_stimulate_retract_gear_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean retract_EV;

                _ProjectionWrite_con_stop_stimulate_retract_gear_valve(const BBoolean& retract_EV) {
                    this->retract_EV = retract_EV;
                }

                friend bool operator ==(const _ProjectionWrite_con_stop_stimulate_retract_gear_valve& o1, const _ProjectionWrite_con_stop_stimulate_retract_gear_valve& o2) {
                    return o1.retract_EV == (o2.retract_EV);
                }

                friend bool operator !=(const _ProjectionWrite_con_stop_stimulate_retract_gear_valve& o1, const _ProjectionWrite_con_stop_stimulate_retract_gear_valve& o2) {
                    return o1.retract_EV != (o2.retract_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_con_stop_stimulate_retract_gear_valve& e) {
                    strm << "{";
                    strm << "retract_EV: " << e.retract_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (retract_EV.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_con_stimulate_extend_gear_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_con_stimulate_extend_gear_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_con_stimulate_extend_gear_valve& obj1, const _ProjectionRead_con_stimulate_extend_gear_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean extend_EV;
                BRelation<POSITION, DOOR_STATE > doors;
                BBoolean open_EV;
                HANDLE_STATE handle;
                BBoolean general_EV;
                BBoolean retract_EV;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead_con_stimulate_extend_gear_valve(const BBoolean& extend_EV, const BRelation<POSITION, DOOR_STATE >& doors, const BBoolean& open_EV, const HANDLE_STATE& handle, const BBoolean& general_EV, const BBoolean& retract_EV, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->extend_EV = extend_EV;
                    this->doors = doors;
                    this->open_EV = open_EV;
                    this->handle = handle;
                    this->general_EV = general_EV;
                    this->retract_EV = retract_EV;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead_con_stimulate_extend_gear_valve& o1, const _ProjectionRead_con_stimulate_extend_gear_valve& o2) {
                    return o1.extend_EV == (o2.extend_EV) && o1.doors == (o2.doors) && o1.open_EV == (o2.open_EV) && o1.handle == (o2.handle) && o1.general_EV == (o2.general_EV) && o1.retract_EV == (o2.retract_EV) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead_con_stimulate_extend_gear_valve& o1, const _ProjectionRead_con_stimulate_extend_gear_valve& o2) {
                    return o1.extend_EV != (o2.extend_EV) || o1.doors != (o2.doors) || o1.open_EV != (o2.open_EV) || o1.handle != (o2.handle) || o1.general_EV != (o2.general_EV) || o1.retract_EV != (o2.retract_EV) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_con_stimulate_extend_gear_valve& e) {
                    strm << "{";
                    strm << "extend_EV: " << e.extend_EV;
                    strm << ", ";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "open_EV: " << e.open_EV;
                    strm << ", ";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "general_EV: " << e.general_EV;
                    strm << ", ";
                    strm << "retract_EV: " << e.retract_EV;
                    strm << ", ";
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (extend_EV.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (open_EV.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    result = 31 * result + (retract_EV.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_con_stimulate_extend_gear_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_con_stimulate_extend_gear_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_con_stimulate_extend_gear_valve& obj1, const _ProjectionRead__tr_con_stimulate_extend_gear_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean extend_EV;
                BRelation<POSITION, DOOR_STATE > doors;
                BBoolean open_EV;
                HANDLE_STATE handle;
                BBoolean general_EV;
                BBoolean retract_EV;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead__tr_con_stimulate_extend_gear_valve(const BBoolean& extend_EV, const BRelation<POSITION, DOOR_STATE >& doors, const BBoolean& open_EV, const HANDLE_STATE& handle, const BBoolean& general_EV, const BBoolean& retract_EV, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->extend_EV = extend_EV;
                    this->doors = doors;
                    this->open_EV = open_EV;
                    this->handle = handle;
                    this->general_EV = general_EV;
                    this->retract_EV = retract_EV;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead__tr_con_stimulate_extend_gear_valve& o1, const _ProjectionRead__tr_con_stimulate_extend_gear_valve& o2) {
                    return o1.extend_EV == (o2.extend_EV) && o1.doors == (o2.doors) && o1.open_EV == (o2.open_EV) && o1.handle == (o2.handle) && o1.general_EV == (o2.general_EV) && o1.retract_EV == (o2.retract_EV) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead__tr_con_stimulate_extend_gear_valve& o1, const _ProjectionRead__tr_con_stimulate_extend_gear_valve& o2) {
                    return o1.extend_EV != (o2.extend_EV) || o1.doors != (o2.doors) || o1.open_EV != (o2.open_EV) || o1.handle != (o2.handle) || o1.general_EV != (o2.general_EV) || o1.retract_EV != (o2.retract_EV) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_con_stimulate_extend_gear_valve& e) {
                    strm << "{";
                    strm << "extend_EV: " << e.extend_EV;
                    strm << ", "; 
                    strm << "doors: " << e.doors;
                    strm << ", "; 
                    strm << "open_EV: " << e.open_EV;
                    strm << ", "; 
                    strm << "handle: " << e.handle;
                    strm << ", "; 
                    strm << "general_EV: " << e.general_EV;
                    strm << ", "; 
                    strm << "retract_EV: " << e.retract_EV;
                    strm << ", "; 
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (extend_EV.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (open_EV.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    result = 31 * result + (retract_EV.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_con_stimulate_extend_gear_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_con_stimulate_extend_gear_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_con_stimulate_extend_gear_valve& obj1, const _ProjectionWrite_con_stimulate_extend_gear_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean extend_EV;

                _ProjectionWrite_con_stimulate_extend_gear_valve(const BBoolean& extend_EV) {
                    this->extend_EV = extend_EV;
                }

                friend bool operator ==(const _ProjectionWrite_con_stimulate_extend_gear_valve& o1, const _ProjectionWrite_con_stimulate_extend_gear_valve& o2) {
                    return o1.extend_EV == (o2.extend_EV);
                }

                friend bool operator !=(const _ProjectionWrite_con_stimulate_extend_gear_valve& o1, const _ProjectionWrite_con_stimulate_extend_gear_valve& o2) {
                    return o1.extend_EV != (o2.extend_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_con_stimulate_extend_gear_valve& e) {
                    strm << "{";
                    strm << "extend_EV: " << e.extend_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (extend_EV.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_con_stop_stimulate_extend_gear_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_con_stop_stimulate_extend_gear_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_con_stop_stimulate_extend_gear_valve& obj1, const _ProjectionRead_con_stop_stimulate_extend_gear_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean extend_EV;
                HANDLE_STATE handle;
                BBoolean general_EV;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead_con_stop_stimulate_extend_gear_valve(const BBoolean& extend_EV, const HANDLE_STATE& handle, const BBoolean& general_EV, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->extend_EV = extend_EV;
                    this->handle = handle;
                    this->general_EV = general_EV;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead_con_stop_stimulate_extend_gear_valve& o1, const _ProjectionRead_con_stop_stimulate_extend_gear_valve& o2) {
                    return o1.extend_EV == (o2.extend_EV) && o1.handle == (o2.handle) && o1.general_EV == (o2.general_EV) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead_con_stop_stimulate_extend_gear_valve& o1, const _ProjectionRead_con_stop_stimulate_extend_gear_valve& o2) {
                    return o1.extend_EV != (o2.extend_EV) || o1.handle != (o2.handle) || o1.general_EV != (o2.general_EV) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_con_stop_stimulate_extend_gear_valve& e) {
                    strm << "{";
                    strm << "extend_EV: " << e.extend_EV;
                    strm << ", ";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "general_EV: " << e.general_EV;
                    strm << ", ";
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (extend_EV.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve& obj1, const _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean extend_EV;
                HANDLE_STATE handle;
                BBoolean general_EV;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve(const BBoolean& extend_EV, const HANDLE_STATE& handle, const BBoolean& general_EV, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->extend_EV = extend_EV;
                    this->handle = handle;
                    this->general_EV = general_EV;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve& o1, const _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve& o2) {
                    return o1.extend_EV == (o2.extend_EV) && o1.handle == (o2.handle) && o1.general_EV == (o2.general_EV) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve& o1, const _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve& o2) {
                    return o1.extend_EV != (o2.extend_EV) || o1.handle != (o2.handle) || o1.general_EV != (o2.general_EV) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve& e) {
                    strm << "{";
                    strm << "extend_EV: " << e.extend_EV;
                    strm << ", "; 
                    strm << "handle: " << e.handle;
                    strm << ", "; 
                    strm << "general_EV: " << e.general_EV;
                    strm << ", "; 
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (extend_EV.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_con_stop_stimulate_extend_gear_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_con_stop_stimulate_extend_gear_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_con_stop_stimulate_extend_gear_valve& obj1, const _ProjectionWrite_con_stop_stimulate_extend_gear_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean extend_EV;

                _ProjectionWrite_con_stop_stimulate_extend_gear_valve(const BBoolean& extend_EV) {
                    this->extend_EV = extend_EV;
                }

                friend bool operator ==(const _ProjectionWrite_con_stop_stimulate_extend_gear_valve& o1, const _ProjectionWrite_con_stop_stimulate_extend_gear_valve& o2) {
                    return o1.extend_EV == (o2.extend_EV);
                }

                friend bool operator !=(const _ProjectionWrite_con_stop_stimulate_extend_gear_valve& o1, const _ProjectionWrite_con_stop_stimulate_extend_gear_valve& o2) {
                    return o1.extend_EV != (o2.extend_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_con_stop_stimulate_extend_gear_valve& e) {
                    strm << "{";
                    strm << "extend_EV: " << e.extend_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (extend_EV.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_env_start_retracting_first {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_env_start_retracting_first& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_env_start_retracting_first& obj1, const _ProjectionRead_env_start_retracting_first& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                DOOR_STATE door;
                HANDLE_STATE handle;
                VALVE_STATE valve_retract_gear;
                BRelation<POSITION, DOOR_STATE > doors;
                VALVE_STATE general_valve;
                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionRead_env_start_retracting_first(const DOOR_STATE& door, const HANDLE_STATE& handle, const VALVE_STATE& valve_retract_gear, const BRelation<POSITION, DOOR_STATE >& doors, const VALVE_STATE& general_valve, const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->door = door;
                    this->handle = handle;
                    this->valve_retract_gear = valve_retract_gear;
                    this->doors = doors;
                    this->general_valve = general_valve;
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionRead_env_start_retracting_first& o1, const _ProjectionRead_env_start_retracting_first& o2) {
                    return o1.door == (o2.door) && o1.handle == (o2.handle) && o1.valve_retract_gear == (o2.valve_retract_gear) && o1.doors == (o2.doors) && o1.general_valve == (o2.general_valve) && o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionRead_env_start_retracting_first& o1, const _ProjectionRead_env_start_retracting_first& o2) {
                    return o1.door != (o2.door) || o1.handle != (o2.handle) || o1.valve_retract_gear != (o2.valve_retract_gear) || o1.doors != (o2.doors) || o1.general_valve != (o2.general_valve) || o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_env_start_retracting_first& e) {
                    strm << "{";
                    strm << "door: " << e.door;
                    strm << ", ";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "valve_retract_gear: " << e.valve_retract_gear;
                    strm << ", ";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "general_valve: " << e.general_valve;
                    strm << ", ";
                    strm << "gears: " << e.gears;
                    strm << ", ";
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (door.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (valve_retract_gear.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_env_start_retracting_first {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_env_start_retracting_first& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_env_start_retracting_first& obj1, const _ProjectionRead__tr_env_start_retracting_first& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                DOOR_STATE door;
                HANDLE_STATE handle;
                VALVE_STATE valve_retract_gear;
                BRelation<POSITION, DOOR_STATE > doors;
                VALVE_STATE general_valve;
                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionRead__tr_env_start_retracting_first(const DOOR_STATE& door, const HANDLE_STATE& handle, const VALVE_STATE& valve_retract_gear, const BRelation<POSITION, DOOR_STATE >& doors, const VALVE_STATE& general_valve, const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->door = door;
                    this->handle = handle;
                    this->valve_retract_gear = valve_retract_gear;
                    this->doors = doors;
                    this->general_valve = general_valve;
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionRead__tr_env_start_retracting_first& o1, const _ProjectionRead__tr_env_start_retracting_first& o2) {
                    return o1.door == (o2.door) && o1.handle == (o2.handle) && o1.valve_retract_gear == (o2.valve_retract_gear) && o1.doors == (o2.doors) && o1.general_valve == (o2.general_valve) && o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionRead__tr_env_start_retracting_first& o1, const _ProjectionRead__tr_env_start_retracting_first& o2) {
                    return o1.door != (o2.door) || o1.handle != (o2.handle) || o1.valve_retract_gear != (o2.valve_retract_gear) || o1.doors != (o2.doors) || o1.general_valve != (o2.general_valve) || o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_env_start_retracting_first& e) {
                    strm << "{";
                    strm << "door: " << e.door;
                    strm << ", "; 
                    strm << "handle: " << e.handle;
                    strm << ", "; 
                    strm << "valve_retract_gear: " << e.valve_retract_gear;
                    strm << ", "; 
                    strm << "doors: " << e.doors;
                    strm << ", "; 
                    strm << "general_valve: " << e.general_valve;
                    strm << ", "; 
                    strm << "gears: " << e.gears;
                    strm << ", "; 
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (door.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (valve_retract_gear.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_env_start_retracting_first {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_env_start_retracting_first& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_env_start_retracting_first& obj1, const _ProjectionWrite_env_start_retracting_first& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionWrite_env_start_retracting_first(const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionWrite_env_start_retracting_first& o1, const _ProjectionWrite_env_start_retracting_first& o2) {
                    return o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionWrite_env_start_retracting_first& o1, const _ProjectionWrite_env_start_retracting_first& o2) {
                    return o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_env_start_retracting_first& e) {
                    strm << "{";
                    strm << "gears: " << e.gears;
                    strm << ", ";
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_env_retract_gear_skip {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_env_retract_gear_skip& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_env_retract_gear_skip& obj1, const _ProjectionRead_env_retract_gear_skip& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, DOOR_STATE > doors;
                VALVE_STATE general_valve;
                HANDLE_STATE handle;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead_env_retract_gear_skip(const BRelation<POSITION, DOOR_STATE >& doors, const VALVE_STATE& general_valve, const HANDLE_STATE& handle, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->doors = doors;
                    this->general_valve = general_valve;
                    this->handle = handle;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead_env_retract_gear_skip& o1, const _ProjectionRead_env_retract_gear_skip& o2) {
                    return o1.doors == (o2.doors) && o1.general_valve == (o2.general_valve) && o1.handle == (o2.handle) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead_env_retract_gear_skip& o1, const _ProjectionRead_env_retract_gear_skip& o2) {
                    return o1.doors != (o2.doors) || o1.general_valve != (o2.general_valve) || o1.handle != (o2.handle) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_env_retract_gear_skip& e) {
                    strm << "{";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "general_valve: " << e.general_valve;
                    strm << ", ";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_env_retract_gear_skip {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_env_retract_gear_skip& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_env_retract_gear_skip& obj1, const _ProjectionRead__tr_env_retract_gear_skip& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, DOOR_STATE > doors;
                VALVE_STATE general_valve;
                HANDLE_STATE handle;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead__tr_env_retract_gear_skip(const BRelation<POSITION, DOOR_STATE >& doors, const VALVE_STATE& general_valve, const HANDLE_STATE& handle, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->doors = doors;
                    this->general_valve = general_valve;
                    this->handle = handle;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead__tr_env_retract_gear_skip& o1, const _ProjectionRead__tr_env_retract_gear_skip& o2) {
                    return o1.doors == (o2.doors) && o1.general_valve == (o2.general_valve) && o1.handle == (o2.handle) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead__tr_env_retract_gear_skip& o1, const _ProjectionRead__tr_env_retract_gear_skip& o2) {
                    return o1.doors != (o2.doors) || o1.general_valve != (o2.general_valve) || o1.handle != (o2.handle) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_env_retract_gear_skip& e) {
                    strm << "{";
                    strm << "doors: " << e.doors;
                    strm << ", "; 
                    strm << "general_valve: " << e.general_valve;
                    strm << ", "; 
                    strm << "handle: " << e.handle;
                    strm << ", "; 
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_env_retract_gear_skip {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_env_retract_gear_skip& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_env_retract_gear_skip& obj1, const _ProjectionWrite_env_retract_gear_skip& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionWrite_env_retract_gear_skip(const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionWrite_env_retract_gear_skip& o1, const _ProjectionWrite_env_retract_gear_skip& o2) {
                    return o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionWrite_env_retract_gear_skip& o1, const _ProjectionWrite_env_retract_gear_skip& o2) {
                    return o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_env_retract_gear_skip& e) {
                    strm << "{";
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_env_retract_gear_last {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_env_retract_gear_last& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_env_retract_gear_last& obj1, const _ProjectionRead_env_retract_gear_last& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                DOOR_STATE door;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                VALVE_STATE general_valve;
                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionRead_env_retract_gear_last(const DOOR_STATE& door, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const VALVE_STATE& general_valve, const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->door = door;
                    this->handle = handle;
                    this->doors = doors;
                    this->general_valve = general_valve;
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionRead_env_retract_gear_last& o1, const _ProjectionRead_env_retract_gear_last& o2) {
                    return o1.door == (o2.door) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.general_valve == (o2.general_valve) && o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionRead_env_retract_gear_last& o1, const _ProjectionRead_env_retract_gear_last& o2) {
                    return o1.door != (o2.door) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.general_valve != (o2.general_valve) || o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_env_retract_gear_last& e) {
                    strm << "{";
                    strm << "door: " << e.door;
                    strm << ", ";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "general_valve: " << e.general_valve;
                    strm << ", ";
                    strm << "gears: " << e.gears;
                    strm << ", ";
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (door.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_env_retract_gear_last {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_env_retract_gear_last& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_env_retract_gear_last& obj1, const _ProjectionRead__tr_env_retract_gear_last& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                DOOR_STATE door;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                VALVE_STATE general_valve;
                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionRead__tr_env_retract_gear_last(const DOOR_STATE& door, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const VALVE_STATE& general_valve, const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->door = door;
                    this->handle = handle;
                    this->doors = doors;
                    this->general_valve = general_valve;
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionRead__tr_env_retract_gear_last& o1, const _ProjectionRead__tr_env_retract_gear_last& o2) {
                    return o1.door == (o2.door) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.general_valve == (o2.general_valve) && o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionRead__tr_env_retract_gear_last& o1, const _ProjectionRead__tr_env_retract_gear_last& o2) {
                    return o1.door != (o2.door) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.general_valve != (o2.general_valve) || o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_env_retract_gear_last& e) {
                    strm << "{";
                    strm << "door: " << e.door;
                    strm << ", "; 
                    strm << "handle: " << e.handle;
                    strm << ", "; 
                    strm << "doors: " << e.doors;
                    strm << ", "; 
                    strm << "general_valve: " << e.general_valve;
                    strm << ", "; 
                    strm << "gears: " << e.gears;
                    strm << ", "; 
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (door.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_env_retract_gear_last {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_env_retract_gear_last& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_env_retract_gear_last& obj1, const _ProjectionWrite_env_retract_gear_last& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionWrite_env_retract_gear_last(const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionWrite_env_retract_gear_last& o1, const _ProjectionWrite_env_retract_gear_last& o2) {
                    return o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionWrite_env_retract_gear_last& o1, const _ProjectionWrite_env_retract_gear_last& o2) {
                    return o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_env_retract_gear_last& e) {
                    strm << "{";
                    strm << "gears: " << e.gears;
                    strm << ", ";
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_env_start_extending {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_env_start_extending& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_env_start_extending& obj1, const _ProjectionRead_env_start_extending& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                DOOR_STATE door;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                VALVE_STATE general_valve;
                VALVE_STATE valve_extend_gear;
                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionRead_env_start_extending(const DOOR_STATE& door, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const VALVE_STATE& general_valve, const VALVE_STATE& valve_extend_gear, const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->door = door;
                    this->handle = handle;
                    this->doors = doors;
                    this->general_valve = general_valve;
                    this->valve_extend_gear = valve_extend_gear;
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionRead_env_start_extending& o1, const _ProjectionRead_env_start_extending& o2) {
                    return o1.door == (o2.door) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.general_valve == (o2.general_valve) && o1.valve_extend_gear == (o2.valve_extend_gear) && o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionRead_env_start_extending& o1, const _ProjectionRead_env_start_extending& o2) {
                    return o1.door != (o2.door) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.general_valve != (o2.general_valve) || o1.valve_extend_gear != (o2.valve_extend_gear) || o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_env_start_extending& e) {
                    strm << "{";
                    strm << "door: " << e.door;
                    strm << ", ";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "general_valve: " << e.general_valve;
                    strm << ", ";
                    strm << "valve_extend_gear: " << e.valve_extend_gear;
                    strm << ", ";
                    strm << "gears: " << e.gears;
                    strm << ", ";
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (door.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (valve_extend_gear.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_env_start_extending {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_env_start_extending& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_env_start_extending& obj1, const _ProjectionRead__tr_env_start_extending& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                DOOR_STATE door;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                VALVE_STATE general_valve;
                VALVE_STATE valve_extend_gear;
                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionRead__tr_env_start_extending(const DOOR_STATE& door, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const VALVE_STATE& general_valve, const VALVE_STATE& valve_extend_gear, const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->door = door;
                    this->handle = handle;
                    this->doors = doors;
                    this->general_valve = general_valve;
                    this->valve_extend_gear = valve_extend_gear;
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionRead__tr_env_start_extending& o1, const _ProjectionRead__tr_env_start_extending& o2) {
                    return o1.door == (o2.door) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.general_valve == (o2.general_valve) && o1.valve_extend_gear == (o2.valve_extend_gear) && o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionRead__tr_env_start_extending& o1, const _ProjectionRead__tr_env_start_extending& o2) {
                    return o1.door != (o2.door) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.general_valve != (o2.general_valve) || o1.valve_extend_gear != (o2.valve_extend_gear) || o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_env_start_extending& e) {
                    strm << "{";
                    strm << "door: " << e.door;
                    strm << ", "; 
                    strm << "handle: " << e.handle;
                    strm << ", "; 
                    strm << "doors: " << e.doors;
                    strm << ", "; 
                    strm << "general_valve: " << e.general_valve;
                    strm << ", "; 
                    strm << "valve_extend_gear: " << e.valve_extend_gear;
                    strm << ", "; 
                    strm << "gears: " << e.gears;
                    strm << ", "; 
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (door.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (valve_extend_gear.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_env_start_extending {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_env_start_extending& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_env_start_extending& obj1, const _ProjectionWrite_env_start_extending& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionWrite_env_start_extending(const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionWrite_env_start_extending& o1, const _ProjectionWrite_env_start_extending& o2) {
                    return o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionWrite_env_start_extending& o1, const _ProjectionWrite_env_start_extending& o2) {
                    return o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_env_start_extending& e) {
                    strm << "{";
                    strm << "gears: " << e.gears;
                    strm << ", ";
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_env_extend_gear_last {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_env_extend_gear_last& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_env_extend_gear_last& obj1, const _ProjectionRead_env_extend_gear_last& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                DOOR_STATE door;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                VALVE_STATE general_valve;
                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionRead_env_extend_gear_last(const DOOR_STATE& door, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const VALVE_STATE& general_valve, const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->door = door;
                    this->handle = handle;
                    this->doors = doors;
                    this->general_valve = general_valve;
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionRead_env_extend_gear_last& o1, const _ProjectionRead_env_extend_gear_last& o2) {
                    return o1.door == (o2.door) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.general_valve == (o2.general_valve) && o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionRead_env_extend_gear_last& o1, const _ProjectionRead_env_extend_gear_last& o2) {
                    return o1.door != (o2.door) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.general_valve != (o2.general_valve) || o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_env_extend_gear_last& e) {
                    strm << "{";
                    strm << "door: " << e.door;
                    strm << ", ";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "general_valve: " << e.general_valve;
                    strm << ", ";
                    strm << "gears: " << e.gears;
                    strm << ", ";
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (door.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_env_extend_gear_last {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_env_extend_gear_last& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_env_extend_gear_last& obj1, const _ProjectionRead__tr_env_extend_gear_last& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                DOOR_STATE door;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                VALVE_STATE general_valve;
                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionRead__tr_env_extend_gear_last(const DOOR_STATE& door, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const VALVE_STATE& general_valve, const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->door = door;
                    this->handle = handle;
                    this->doors = doors;
                    this->general_valve = general_valve;
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionRead__tr_env_extend_gear_last& o1, const _ProjectionRead__tr_env_extend_gear_last& o2) {
                    return o1.door == (o2.door) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.general_valve == (o2.general_valve) && o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionRead__tr_env_extend_gear_last& o1, const _ProjectionRead__tr_env_extend_gear_last& o2) {
                    return o1.door != (o2.door) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.general_valve != (o2.general_valve) || o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_env_extend_gear_last& e) {
                    strm << "{";
                    strm << "door: " << e.door;
                    strm << ", "; 
                    strm << "handle: " << e.handle;
                    strm << ", "; 
                    strm << "doors: " << e.doors;
                    strm << ", "; 
                    strm << "general_valve: " << e.general_valve;
                    strm << ", "; 
                    strm << "gears: " << e.gears;
                    strm << ", "; 
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (door.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_env_extend_gear_last {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_env_extend_gear_last& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_env_extend_gear_last& obj1, const _ProjectionWrite_env_extend_gear_last& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionWrite_env_extend_gear_last(const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionWrite_env_extend_gear_last& o1, const _ProjectionWrite_env_extend_gear_last& o2) {
                    return o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionWrite_env_extend_gear_last& o1, const _ProjectionWrite_env_extend_gear_last& o2) {
                    return o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_env_extend_gear_last& e) {
                    strm << "{";
                    strm << "gears: " << e.gears;
                    strm << ", ";
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_env_extend_gear_skip {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_env_extend_gear_skip& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_env_extend_gear_skip& obj1, const _ProjectionRead_env_extend_gear_skip& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, DOOR_STATE > doors;
                VALVE_STATE general_valve;
                HANDLE_STATE handle;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead_env_extend_gear_skip(const BRelation<POSITION, DOOR_STATE >& doors, const VALVE_STATE& general_valve, const HANDLE_STATE& handle, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->doors = doors;
                    this->general_valve = general_valve;
                    this->handle = handle;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead_env_extend_gear_skip& o1, const _ProjectionRead_env_extend_gear_skip& o2) {
                    return o1.doors == (o2.doors) && o1.general_valve == (o2.general_valve) && o1.handle == (o2.handle) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead_env_extend_gear_skip& o1, const _ProjectionRead_env_extend_gear_skip& o2) {
                    return o1.doors != (o2.doors) || o1.general_valve != (o2.general_valve) || o1.handle != (o2.handle) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_env_extend_gear_skip& e) {
                    strm << "{";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "general_valve: " << e.general_valve;
                    strm << ", ";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_env_extend_gear_skip {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_env_extend_gear_skip& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_env_extend_gear_skip& obj1, const _ProjectionRead__tr_env_extend_gear_skip& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, DOOR_STATE > doors;
                VALVE_STATE general_valve;
                HANDLE_STATE handle;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead__tr_env_extend_gear_skip(const BRelation<POSITION, DOOR_STATE >& doors, const VALVE_STATE& general_valve, const HANDLE_STATE& handle, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->doors = doors;
                    this->general_valve = general_valve;
                    this->handle = handle;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead__tr_env_extend_gear_skip& o1, const _ProjectionRead__tr_env_extend_gear_skip& o2) {
                    return o1.doors == (o2.doors) && o1.general_valve == (o2.general_valve) && o1.handle == (o2.handle) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead__tr_env_extend_gear_skip& o1, const _ProjectionRead__tr_env_extend_gear_skip& o2) {
                    return o1.doors != (o2.doors) || o1.general_valve != (o2.general_valve) || o1.handle != (o2.handle) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_env_extend_gear_skip& e) {
                    strm << "{";
                    strm << "doors: " << e.doors;
                    strm << ", "; 
                    strm << "general_valve: " << e.general_valve;
                    strm << ", "; 
                    strm << "handle: " << e.handle;
                    strm << ", "; 
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_env_extend_gear_skip {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_env_extend_gear_skip& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_env_extend_gear_skip& obj1, const _ProjectionWrite_env_extend_gear_skip& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionWrite_env_extend_gear_skip(const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionWrite_env_extend_gear_skip& o1, const _ProjectionWrite_env_extend_gear_skip& o2) {
                    return o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionWrite_env_extend_gear_skip& o1, const _ProjectionWrite_env_extend_gear_skip& o2) {
                    return o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_env_extend_gear_skip& e) {
                    strm << "{";
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_env_start_open_door {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_env_start_open_door& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_env_start_open_door& obj1, const _ProjectionRead_env_start_open_door& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_open_door;
                DOOR_STATE door;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                VALVE_STATE general_valve;
                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionRead_env_start_open_door(const VALVE_STATE& valve_open_door, const DOOR_STATE& door, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const VALVE_STATE& general_valve, const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->valve_open_door = valve_open_door;
                    this->door = door;
                    this->handle = handle;
                    this->doors = doors;
                    this->general_valve = general_valve;
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionRead_env_start_open_door& o1, const _ProjectionRead_env_start_open_door& o2) {
                    return o1.valve_open_door == (o2.valve_open_door) && o1.door == (o2.door) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.general_valve == (o2.general_valve) && o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionRead_env_start_open_door& o1, const _ProjectionRead_env_start_open_door& o2) {
                    return o1.valve_open_door != (o2.valve_open_door) || o1.door != (o2.door) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.general_valve != (o2.general_valve) || o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_env_start_open_door& e) {
                    strm << "{";
                    strm << "valve_open_door: " << e.valve_open_door;
                    strm << ", ";
                    strm << "door: " << e.door;
                    strm << ", ";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "general_valve: " << e.general_valve;
                    strm << ", ";
                    strm << "gears: " << e.gears;
                    strm << ", ";
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_open_door.hashCode() << 1);
                    result = 31 * result + (door.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_env_start_open_door {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_env_start_open_door& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_env_start_open_door& obj1, const _ProjectionRead__tr_env_start_open_door& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_open_door;
                DOOR_STATE door;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                VALVE_STATE general_valve;
                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionRead__tr_env_start_open_door(const VALVE_STATE& valve_open_door, const DOOR_STATE& door, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const VALVE_STATE& general_valve, const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->valve_open_door = valve_open_door;
                    this->door = door;
                    this->handle = handle;
                    this->doors = doors;
                    this->general_valve = general_valve;
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionRead__tr_env_start_open_door& o1, const _ProjectionRead__tr_env_start_open_door& o2) {
                    return o1.valve_open_door == (o2.valve_open_door) && o1.door == (o2.door) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.general_valve == (o2.general_valve) && o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionRead__tr_env_start_open_door& o1, const _ProjectionRead__tr_env_start_open_door& o2) {
                    return o1.valve_open_door != (o2.valve_open_door) || o1.door != (o2.door) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.general_valve != (o2.general_valve) || o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_env_start_open_door& e) {
                    strm << "{";
                    strm << "valve_open_door: " << e.valve_open_door;
                    strm << ", "; 
                    strm << "door: " << e.door;
                    strm << ", "; 
                    strm << "handle: " << e.handle;
                    strm << ", "; 
                    strm << "doors: " << e.doors;
                    strm << ", "; 
                    strm << "general_valve: " << e.general_valve;
                    strm << ", "; 
                    strm << "gears: " << e.gears;
                    strm << ", "; 
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_open_door.hashCode() << 1);
                    result = 31 * result + (door.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_env_start_open_door {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_env_start_open_door& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_env_start_open_door& obj1, const _ProjectionWrite_env_start_open_door& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, DOOR_STATE > doors;
                DOOR_STATE door;

                _ProjectionWrite_env_start_open_door(const BRelation<POSITION, DOOR_STATE >& doors, const DOOR_STATE& door) {
                    this->doors = doors;
                    this->door = door;
                }

                friend bool operator ==(const _ProjectionWrite_env_start_open_door& o1, const _ProjectionWrite_env_start_open_door& o2) {
                    return o1.doors == (o2.doors) && o1.door == (o2.door);
                }

                friend bool operator !=(const _ProjectionWrite_env_start_open_door& o1, const _ProjectionWrite_env_start_open_door& o2) {
                    return o1.doors != (o2.doors) || o1.door != (o2.door);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_env_start_open_door& e) {
                    strm << "{";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "door: " << e.door;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (door.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_env_open_door_last {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_env_open_door_last& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_env_open_door_last& obj1, const _ProjectionRead_env_open_door_last& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_open_door;
                DOOR_STATE door;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                VALVE_STATE general_valve;
                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionRead_env_open_door_last(const VALVE_STATE& valve_open_door, const DOOR_STATE& door, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const VALVE_STATE& general_valve, const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->valve_open_door = valve_open_door;
                    this->door = door;
                    this->handle = handle;
                    this->doors = doors;
                    this->general_valve = general_valve;
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionRead_env_open_door_last& o1, const _ProjectionRead_env_open_door_last& o2) {
                    return o1.valve_open_door == (o2.valve_open_door) && o1.door == (o2.door) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.general_valve == (o2.general_valve) && o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionRead_env_open_door_last& o1, const _ProjectionRead_env_open_door_last& o2) {
                    return o1.valve_open_door != (o2.valve_open_door) || o1.door != (o2.door) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.general_valve != (o2.general_valve) || o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_env_open_door_last& e) {
                    strm << "{";
                    strm << "valve_open_door: " << e.valve_open_door;
                    strm << ", ";
                    strm << "door: " << e.door;
                    strm << ", ";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "general_valve: " << e.general_valve;
                    strm << ", ";
                    strm << "gears: " << e.gears;
                    strm << ", ";
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_open_door.hashCode() << 1);
                    result = 31 * result + (door.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_env_open_door_last {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_env_open_door_last& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_env_open_door_last& obj1, const _ProjectionRead__tr_env_open_door_last& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_open_door;
                DOOR_STATE door;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                VALVE_STATE general_valve;
                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionRead__tr_env_open_door_last(const VALVE_STATE& valve_open_door, const DOOR_STATE& door, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const VALVE_STATE& general_valve, const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->valve_open_door = valve_open_door;
                    this->door = door;
                    this->handle = handle;
                    this->doors = doors;
                    this->general_valve = general_valve;
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionRead__tr_env_open_door_last& o1, const _ProjectionRead__tr_env_open_door_last& o2) {
                    return o1.valve_open_door == (o2.valve_open_door) && o1.door == (o2.door) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.general_valve == (o2.general_valve) && o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionRead__tr_env_open_door_last& o1, const _ProjectionRead__tr_env_open_door_last& o2) {
                    return o1.valve_open_door != (o2.valve_open_door) || o1.door != (o2.door) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.general_valve != (o2.general_valve) || o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_env_open_door_last& e) {
                    strm << "{";
                    strm << "valve_open_door: " << e.valve_open_door;
                    strm << ", "; 
                    strm << "door: " << e.door;
                    strm << ", "; 
                    strm << "handle: " << e.handle;
                    strm << ", "; 
                    strm << "doors: " << e.doors;
                    strm << ", "; 
                    strm << "general_valve: " << e.general_valve;
                    strm << ", "; 
                    strm << "gears: " << e.gears;
                    strm << ", "; 
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_open_door.hashCode() << 1);
                    result = 31 * result + (door.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_env_open_door_last {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_env_open_door_last& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_env_open_door_last& obj1, const _ProjectionWrite_env_open_door_last& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, DOOR_STATE > doors;
                DOOR_STATE door;

                _ProjectionWrite_env_open_door_last(const BRelation<POSITION, DOOR_STATE >& doors, const DOOR_STATE& door) {
                    this->doors = doors;
                    this->door = door;
                }

                friend bool operator ==(const _ProjectionWrite_env_open_door_last& o1, const _ProjectionWrite_env_open_door_last& o2) {
                    return o1.doors == (o2.doors) && o1.door == (o2.door);
                }

                friend bool operator !=(const _ProjectionWrite_env_open_door_last& o1, const _ProjectionWrite_env_open_door_last& o2) {
                    return o1.doors != (o2.doors) || o1.door != (o2.door);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_env_open_door_last& e) {
                    strm << "{";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "door: " << e.door;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (door.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_env_open_door_skip {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_env_open_door_skip& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_env_open_door_skip& obj1, const _ProjectionRead_env_open_door_skip& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_open_door;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                VALVE_STATE general_valve;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead_env_open_door_skip(const VALVE_STATE& valve_open_door, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const VALVE_STATE& general_valve, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->valve_open_door = valve_open_door;
                    this->handle = handle;
                    this->doors = doors;
                    this->general_valve = general_valve;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead_env_open_door_skip& o1, const _ProjectionRead_env_open_door_skip& o2) {
                    return o1.valve_open_door == (o2.valve_open_door) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.general_valve == (o2.general_valve) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead_env_open_door_skip& o1, const _ProjectionRead_env_open_door_skip& o2) {
                    return o1.valve_open_door != (o2.valve_open_door) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.general_valve != (o2.general_valve) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_env_open_door_skip& e) {
                    strm << "{";
                    strm << "valve_open_door: " << e.valve_open_door;
                    strm << ", ";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "general_valve: " << e.general_valve;
                    strm << ", ";
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_open_door.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_env_open_door_skip {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_env_open_door_skip& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_env_open_door_skip& obj1, const _ProjectionRead__tr_env_open_door_skip& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_open_door;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                VALVE_STATE general_valve;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead__tr_env_open_door_skip(const VALVE_STATE& valve_open_door, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const VALVE_STATE& general_valve, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->valve_open_door = valve_open_door;
                    this->handle = handle;
                    this->doors = doors;
                    this->general_valve = general_valve;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead__tr_env_open_door_skip& o1, const _ProjectionRead__tr_env_open_door_skip& o2) {
                    return o1.valve_open_door == (o2.valve_open_door) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.general_valve == (o2.general_valve) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead__tr_env_open_door_skip& o1, const _ProjectionRead__tr_env_open_door_skip& o2) {
                    return o1.valve_open_door != (o2.valve_open_door) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.general_valve != (o2.general_valve) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_env_open_door_skip& e) {
                    strm << "{";
                    strm << "valve_open_door: " << e.valve_open_door;
                    strm << ", "; 
                    strm << "handle: " << e.handle;
                    strm << ", "; 
                    strm << "doors: " << e.doors;
                    strm << ", "; 
                    strm << "general_valve: " << e.general_valve;
                    strm << ", "; 
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_open_door.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_env_open_door_skip {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_env_open_door_skip& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_env_open_door_skip& obj1, const _ProjectionWrite_env_open_door_skip& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, DOOR_STATE > doors;

                _ProjectionWrite_env_open_door_skip(const BRelation<POSITION, DOOR_STATE >& doors) {
                    this->doors = doors;
                }

                friend bool operator ==(const _ProjectionWrite_env_open_door_skip& o1, const _ProjectionWrite_env_open_door_skip& o2) {
                    return o1.doors == (o2.doors);
                }

                friend bool operator !=(const _ProjectionWrite_env_open_door_skip& o1, const _ProjectionWrite_env_open_door_skip& o2) {
                    return o1.doors != (o2.doors);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_env_open_door_skip& e) {
                    strm << "{";
                    strm << "doors: " << e.doors;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (doors.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_env_start_close_door {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_env_start_close_door& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_env_start_close_door& obj1, const _ProjectionRead_env_start_close_door& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                DOOR_STATE door;
                VALVE_STATE valve_close_door;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                VALVE_STATE general_valve;
                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionRead_env_start_close_door(const DOOR_STATE& door, const VALVE_STATE& valve_close_door, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const VALVE_STATE& general_valve, const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->door = door;
                    this->valve_close_door = valve_close_door;
                    this->handle = handle;
                    this->doors = doors;
                    this->general_valve = general_valve;
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionRead_env_start_close_door& o1, const _ProjectionRead_env_start_close_door& o2) {
                    return o1.door == (o2.door) && o1.valve_close_door == (o2.valve_close_door) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.general_valve == (o2.general_valve) && o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionRead_env_start_close_door& o1, const _ProjectionRead_env_start_close_door& o2) {
                    return o1.door != (o2.door) || o1.valve_close_door != (o2.valve_close_door) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.general_valve != (o2.general_valve) || o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_env_start_close_door& e) {
                    strm << "{";
                    strm << "door: " << e.door;
                    strm << ", ";
                    strm << "valve_close_door: " << e.valve_close_door;
                    strm << ", ";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "general_valve: " << e.general_valve;
                    strm << ", ";
                    strm << "gears: " << e.gears;
                    strm << ", ";
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (door.hashCode() << 1);
                    result = 31 * result + (valve_close_door.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_env_start_close_door {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_env_start_close_door& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_env_start_close_door& obj1, const _ProjectionRead__tr_env_start_close_door& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                DOOR_STATE door;
                VALVE_STATE valve_close_door;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                VALVE_STATE general_valve;
                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionRead__tr_env_start_close_door(const DOOR_STATE& door, const VALVE_STATE& valve_close_door, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const VALVE_STATE& general_valve, const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->door = door;
                    this->valve_close_door = valve_close_door;
                    this->handle = handle;
                    this->doors = doors;
                    this->general_valve = general_valve;
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionRead__tr_env_start_close_door& o1, const _ProjectionRead__tr_env_start_close_door& o2) {
                    return o1.door == (o2.door) && o1.valve_close_door == (o2.valve_close_door) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.general_valve == (o2.general_valve) && o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionRead__tr_env_start_close_door& o1, const _ProjectionRead__tr_env_start_close_door& o2) {
                    return o1.door != (o2.door) || o1.valve_close_door != (o2.valve_close_door) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.general_valve != (o2.general_valve) || o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_env_start_close_door& e) {
                    strm << "{";
                    strm << "door: " << e.door;
                    strm << ", "; 
                    strm << "valve_close_door: " << e.valve_close_door;
                    strm << ", "; 
                    strm << "handle: " << e.handle;
                    strm << ", "; 
                    strm << "doors: " << e.doors;
                    strm << ", "; 
                    strm << "general_valve: " << e.general_valve;
                    strm << ", "; 
                    strm << "gears: " << e.gears;
                    strm << ", "; 
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (door.hashCode() << 1);
                    result = 31 * result + (valve_close_door.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_env_start_close_door {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_env_start_close_door& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_env_start_close_door& obj1, const _ProjectionWrite_env_start_close_door& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, DOOR_STATE > doors;
                DOOR_STATE door;

                _ProjectionWrite_env_start_close_door(const BRelation<POSITION, DOOR_STATE >& doors, const DOOR_STATE& door) {
                    this->doors = doors;
                    this->door = door;
                }

                friend bool operator ==(const _ProjectionWrite_env_start_close_door& o1, const _ProjectionWrite_env_start_close_door& o2) {
                    return o1.doors == (o2.doors) && o1.door == (o2.door);
                }

                friend bool operator !=(const _ProjectionWrite_env_start_close_door& o1, const _ProjectionWrite_env_start_close_door& o2) {
                    return o1.doors != (o2.doors) || o1.door != (o2.door);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_env_start_close_door& e) {
                    strm << "{";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "door: " << e.door;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (door.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_env_close_door {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_env_close_door& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_env_close_door& obj1, const _ProjectionRead_env_close_door& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                DOOR_STATE door;
                VALVE_STATE valve_close_door;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                PLANE_STATE shock_absorber;
                VALVE_STATE general_valve;
                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionRead_env_close_door(const DOOR_STATE& door, const VALVE_STATE& valve_close_door, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const PLANE_STATE& shock_absorber, const VALVE_STATE& general_valve, const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->door = door;
                    this->valve_close_door = valve_close_door;
                    this->handle = handle;
                    this->doors = doors;
                    this->shock_absorber = shock_absorber;
                    this->general_valve = general_valve;
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionRead_env_close_door& o1, const _ProjectionRead_env_close_door& o2) {
                    return o1.door == (o2.door) && o1.valve_close_door == (o2.valve_close_door) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.shock_absorber == (o2.shock_absorber) && o1.general_valve == (o2.general_valve) && o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionRead_env_close_door& o1, const _ProjectionRead_env_close_door& o2) {
                    return o1.door != (o2.door) || o1.valve_close_door != (o2.valve_close_door) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.shock_absorber != (o2.shock_absorber) || o1.general_valve != (o2.general_valve) || o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_env_close_door& e) {
                    strm << "{";
                    strm << "door: " << e.door;
                    strm << ", ";
                    strm << "valve_close_door: " << e.valve_close_door;
                    strm << ", ";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "shock_absorber: " << e.shock_absorber;
                    strm << ", ";
                    strm << "general_valve: " << e.general_valve;
                    strm << ", ";
                    strm << "gears: " << e.gears;
                    strm << ", ";
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (door.hashCode() << 1);
                    result = 31 * result + (valve_close_door.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (shock_absorber.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_env_close_door {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_env_close_door& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_env_close_door& obj1, const _ProjectionRead__tr_env_close_door& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                DOOR_STATE door;
                VALVE_STATE valve_close_door;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                PLANE_STATE shock_absorber;
                VALVE_STATE general_valve;
                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionRead__tr_env_close_door(const DOOR_STATE& door, const VALVE_STATE& valve_close_door, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const PLANE_STATE& shock_absorber, const VALVE_STATE& general_valve, const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->door = door;
                    this->valve_close_door = valve_close_door;
                    this->handle = handle;
                    this->doors = doors;
                    this->shock_absorber = shock_absorber;
                    this->general_valve = general_valve;
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionRead__tr_env_close_door& o1, const _ProjectionRead__tr_env_close_door& o2) {
                    return o1.door == (o2.door) && o1.valve_close_door == (o2.valve_close_door) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.shock_absorber == (o2.shock_absorber) && o1.general_valve == (o2.general_valve) && o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionRead__tr_env_close_door& o1, const _ProjectionRead__tr_env_close_door& o2) {
                    return o1.door != (o2.door) || o1.valve_close_door != (o2.valve_close_door) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.shock_absorber != (o2.shock_absorber) || o1.general_valve != (o2.general_valve) || o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_env_close_door& e) {
                    strm << "{";
                    strm << "door: " << e.door;
                    strm << ", "; 
                    strm << "valve_close_door: " << e.valve_close_door;
                    strm << ", "; 
                    strm << "handle: " << e.handle;
                    strm << ", "; 
                    strm << "doors: " << e.doors;
                    strm << ", "; 
                    strm << "shock_absorber: " << e.shock_absorber;
                    strm << ", "; 
                    strm << "general_valve: " << e.general_valve;
                    strm << ", "; 
                    strm << "gears: " << e.gears;
                    strm << ", "; 
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (door.hashCode() << 1);
                    result = 31 * result + (valve_close_door.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (shock_absorber.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_env_close_door {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_env_close_door& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_env_close_door& obj1, const _ProjectionWrite_env_close_door& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, DOOR_STATE > doors;
                DOOR_STATE door;

                _ProjectionWrite_env_close_door(const BRelation<POSITION, DOOR_STATE >& doors, const DOOR_STATE& door) {
                    this->doors = doors;
                    this->door = door;
                }

                friend bool operator ==(const _ProjectionWrite_env_close_door& o1, const _ProjectionWrite_env_close_door& o2) {
                    return o1.doors == (o2.doors) && o1.door == (o2.door);
                }

                friend bool operator !=(const _ProjectionWrite_env_close_door& o1, const _ProjectionWrite_env_close_door& o2) {
                    return o1.doors != (o2.doors) || o1.door != (o2.door);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_env_close_door& e) {
                    strm << "{";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "door: " << e.door;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (door.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_env_close_door_skip {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_env_close_door_skip& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_env_close_door_skip& obj1, const _ProjectionRead_env_close_door_skip& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_close_door;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                PLANE_STATE shock_absorber;
                VALVE_STATE general_valve;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead_env_close_door_skip(const VALVE_STATE& valve_close_door, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const PLANE_STATE& shock_absorber, const VALVE_STATE& general_valve, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->valve_close_door = valve_close_door;
                    this->handle = handle;
                    this->doors = doors;
                    this->shock_absorber = shock_absorber;
                    this->general_valve = general_valve;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead_env_close_door_skip& o1, const _ProjectionRead_env_close_door_skip& o2) {
                    return o1.valve_close_door == (o2.valve_close_door) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.shock_absorber == (o2.shock_absorber) && o1.general_valve == (o2.general_valve) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead_env_close_door_skip& o1, const _ProjectionRead_env_close_door_skip& o2) {
                    return o1.valve_close_door != (o2.valve_close_door) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.shock_absorber != (o2.shock_absorber) || o1.general_valve != (o2.general_valve) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_env_close_door_skip& e) {
                    strm << "{";
                    strm << "valve_close_door: " << e.valve_close_door;
                    strm << ", ";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "shock_absorber: " << e.shock_absorber;
                    strm << ", ";
                    strm << "general_valve: " << e.general_valve;
                    strm << ", ";
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_close_door.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (shock_absorber.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_env_close_door_skip {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_env_close_door_skip& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_env_close_door_skip& obj1, const _ProjectionRead__tr_env_close_door_skip& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE valve_close_door;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                PLANE_STATE shock_absorber;
                VALVE_STATE general_valve;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead__tr_env_close_door_skip(const VALVE_STATE& valve_close_door, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const PLANE_STATE& shock_absorber, const VALVE_STATE& general_valve, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->valve_close_door = valve_close_door;
                    this->handle = handle;
                    this->doors = doors;
                    this->shock_absorber = shock_absorber;
                    this->general_valve = general_valve;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead__tr_env_close_door_skip& o1, const _ProjectionRead__tr_env_close_door_skip& o2) {
                    return o1.valve_close_door == (o2.valve_close_door) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.shock_absorber == (o2.shock_absorber) && o1.general_valve == (o2.general_valve) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead__tr_env_close_door_skip& o1, const _ProjectionRead__tr_env_close_door_skip& o2) {
                    return o1.valve_close_door != (o2.valve_close_door) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.shock_absorber != (o2.shock_absorber) || o1.general_valve != (o2.general_valve) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_env_close_door_skip& e) {
                    strm << "{";
                    strm << "valve_close_door: " << e.valve_close_door;
                    strm << ", "; 
                    strm << "handle: " << e.handle;
                    strm << ", "; 
                    strm << "doors: " << e.doors;
                    strm << ", "; 
                    strm << "shock_absorber: " << e.shock_absorber;
                    strm << ", "; 
                    strm << "general_valve: " << e.general_valve;
                    strm << ", "; 
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_close_door.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (shock_absorber.hashCode() << 1);
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_env_close_door_skip {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_env_close_door_skip& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_env_close_door_skip& obj1, const _ProjectionWrite_env_close_door_skip& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, DOOR_STATE > doors;

                _ProjectionWrite_env_close_door_skip(const BRelation<POSITION, DOOR_STATE >& doors) {
                    this->doors = doors;
                }

                friend bool operator ==(const _ProjectionWrite_env_close_door_skip& o1, const _ProjectionWrite_env_close_door_skip& o2) {
                    return o1.doors == (o2.doors);
                }

                friend bool operator !=(const _ProjectionWrite_env_close_door_skip& o1, const _ProjectionWrite_env_close_door_skip& o2) {
                    return o1.doors != (o2.doors);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_env_close_door_skip& e) {
                    strm << "{";
                    strm << "doors: " << e.doors;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (doors.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_toggle_handle_up {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_toggle_handle_up& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_toggle_handle_up& obj1, const _ProjectionRead_toggle_handle_up& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                HANDLE_STATE handle;

                _ProjectionRead_toggle_handle_up(const HANDLE_STATE& handle) {
                    this->handle = handle;
                }

                friend bool operator ==(const _ProjectionRead_toggle_handle_up& o1, const _ProjectionRead_toggle_handle_up& o2) {
                    return o1.handle == (o2.handle);
                }

                friend bool operator !=(const _ProjectionRead_toggle_handle_up& o1, const _ProjectionRead_toggle_handle_up& o2) {
                    return o1.handle != (o2.handle);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_toggle_handle_up& e) {
                    strm << "{";
                    strm << "handle: " << e.handle;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (handle.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_toggle_handle_up {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_toggle_handle_up& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_toggle_handle_up& obj1, const _ProjectionRead__tr_toggle_handle_up& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                HANDLE_STATE handle;

                _ProjectionRead__tr_toggle_handle_up(const HANDLE_STATE& handle) {
                    this->handle = handle;
                }

                friend bool operator ==(const _ProjectionRead__tr_toggle_handle_up& o1, const _ProjectionRead__tr_toggle_handle_up& o2) {
                    return o1.handle == (o2.handle);
                }

                friend bool operator !=(const _ProjectionRead__tr_toggle_handle_up& o1, const _ProjectionRead__tr_toggle_handle_up& o2) {
                    return o1.handle != (o2.handle);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_toggle_handle_up& e) {
                    strm << "{";
                    strm << "handle: " << e.handle;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (handle.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_toggle_handle_up {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_toggle_handle_up& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_toggle_handle_up& obj1, const _ProjectionWrite_toggle_handle_up& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                HANDLE_STATE handle;
                BBoolean handle_move;

                _ProjectionWrite_toggle_handle_up(const HANDLE_STATE& handle, const BBoolean& handle_move) {
                    this->handle = handle;
                    this->handle_move = handle_move;
                }

                friend bool operator ==(const _ProjectionWrite_toggle_handle_up& o1, const _ProjectionWrite_toggle_handle_up& o2) {
                    return o1.handle == (o2.handle) && o1.handle_move == (o2.handle_move);
                }

                friend bool operator !=(const _ProjectionWrite_toggle_handle_up& o1, const _ProjectionWrite_toggle_handle_up& o2) {
                    return o1.handle != (o2.handle) || o1.handle_move != (o2.handle_move);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_toggle_handle_up& e) {
                    strm << "{";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "handle_move: " << e.handle_move;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (handle_move.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_toggle_handle_down {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_toggle_handle_down& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_toggle_handle_down& obj1, const _ProjectionRead_toggle_handle_down& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                HANDLE_STATE handle;

                _ProjectionRead_toggle_handle_down(const HANDLE_STATE& handle) {
                    this->handle = handle;
                }

                friend bool operator ==(const _ProjectionRead_toggle_handle_down& o1, const _ProjectionRead_toggle_handle_down& o2) {
                    return o1.handle == (o2.handle);
                }

                friend bool operator !=(const _ProjectionRead_toggle_handle_down& o1, const _ProjectionRead_toggle_handle_down& o2) {
                    return o1.handle != (o2.handle);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_toggle_handle_down& e) {
                    strm << "{";
                    strm << "handle: " << e.handle;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (handle.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_toggle_handle_down {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_toggle_handle_down& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_toggle_handle_down& obj1, const _ProjectionRead__tr_toggle_handle_down& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                HANDLE_STATE handle;

                _ProjectionRead__tr_toggle_handle_down(const HANDLE_STATE& handle) {
                    this->handle = handle;
                }

                friend bool operator ==(const _ProjectionRead__tr_toggle_handle_down& o1, const _ProjectionRead__tr_toggle_handle_down& o2) {
                    return o1.handle == (o2.handle);
                }

                friend bool operator !=(const _ProjectionRead__tr_toggle_handle_down& o1, const _ProjectionRead__tr_toggle_handle_down& o2) {
                    return o1.handle != (o2.handle);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_toggle_handle_down& e) {
                    strm << "{";
                    strm << "handle: " << e.handle;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (handle.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_toggle_handle_down {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_toggle_handle_down& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_toggle_handle_down& obj1, const _ProjectionWrite_toggle_handle_down& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                HANDLE_STATE handle;
                BBoolean handle_move;

                _ProjectionWrite_toggle_handle_down(const HANDLE_STATE& handle, const BBoolean& handle_move) {
                    this->handle = handle;
                    this->handle_move = handle_move;
                }

                friend bool operator ==(const _ProjectionWrite_toggle_handle_down& o1, const _ProjectionWrite_toggle_handle_down& o2) {
                    return o1.handle == (o2.handle) && o1.handle_move == (o2.handle_move);
                }

                friend bool operator !=(const _ProjectionWrite_toggle_handle_down& o1, const _ProjectionWrite_toggle_handle_down& o2) {
                    return o1.handle != (o2.handle) || o1.handle_move != (o2.handle_move);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_toggle_handle_down& e) {
                    strm << "{";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "handle_move: " << e.handle_move;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (handle_move.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_con_stimulate_general_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_con_stimulate_general_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_con_stimulate_general_valve& obj1, const _ProjectionRead_con_stimulate_general_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean handle_move;
                BBoolean general_EV;

                _ProjectionRead_con_stimulate_general_valve(const BBoolean& handle_move, const BBoolean& general_EV) {
                    this->handle_move = handle_move;
                    this->general_EV = general_EV;
                }

                friend bool operator ==(const _ProjectionRead_con_stimulate_general_valve& o1, const _ProjectionRead_con_stimulate_general_valve& o2) {
                    return o1.handle_move == (o2.handle_move) && o1.general_EV == (o2.general_EV);
                }

                friend bool operator !=(const _ProjectionRead_con_stimulate_general_valve& o1, const _ProjectionRead_con_stimulate_general_valve& o2) {
                    return o1.handle_move != (o2.handle_move) || o1.general_EV != (o2.general_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_con_stimulate_general_valve& e) {
                    strm << "{";
                    strm << "handle_move: " << e.handle_move;
                    strm << ", ";
                    strm << "general_EV: " << e.general_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (handle_move.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_con_stimulate_general_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_con_stimulate_general_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_con_stimulate_general_valve& obj1, const _ProjectionRead__tr_con_stimulate_general_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean handle_move;
                BBoolean general_EV;

                _ProjectionRead__tr_con_stimulate_general_valve(const BBoolean& handle_move, const BBoolean& general_EV) {
                    this->handle_move = handle_move;
                    this->general_EV = general_EV;
                }

                friend bool operator ==(const _ProjectionRead__tr_con_stimulate_general_valve& o1, const _ProjectionRead__tr_con_stimulate_general_valve& o2) {
                    return o1.handle_move == (o2.handle_move) && o1.general_EV == (o2.general_EV);
                }

                friend bool operator !=(const _ProjectionRead__tr_con_stimulate_general_valve& o1, const _ProjectionRead__tr_con_stimulate_general_valve& o2) {
                    return o1.handle_move != (o2.handle_move) || o1.general_EV != (o2.general_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_con_stimulate_general_valve& e) {
                    strm << "{";
                    strm << "handle_move: " << e.handle_move;
                    strm << ", "; 
                    strm << "general_EV: " << e.general_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (handle_move.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_con_stimulate_general_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_con_stimulate_general_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_con_stimulate_general_valve& obj1, const _ProjectionWrite_con_stimulate_general_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean general_EV;

                _ProjectionWrite_con_stimulate_general_valve(const BBoolean& general_EV) {
                    this->general_EV = general_EV;
                }

                friend bool operator ==(const _ProjectionWrite_con_stimulate_general_valve& o1, const _ProjectionWrite_con_stimulate_general_valve& o2) {
                    return o1.general_EV == (o2.general_EV);
                }

                friend bool operator !=(const _ProjectionWrite_con_stimulate_general_valve& o1, const _ProjectionWrite_con_stimulate_general_valve& o2) {
                    return o1.general_EV != (o2.general_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_con_stimulate_general_valve& e) {
                    strm << "{";
                    strm << "general_EV: " << e.general_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (general_EV.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_con_stop_stimulate_general_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_con_stop_stimulate_general_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_con_stop_stimulate_general_valve& obj1, const _ProjectionRead_con_stop_stimulate_general_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean extend_EV;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                BBoolean open_EV;
                BBoolean close_EV;
                BBoolean general_EV;
                BBoolean retract_EV;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead_con_stop_stimulate_general_valve(const BBoolean& extend_EV, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const BBoolean& open_EV, const BBoolean& close_EV, const BBoolean& general_EV, const BBoolean& retract_EV, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->extend_EV = extend_EV;
                    this->handle = handle;
                    this->doors = doors;
                    this->open_EV = open_EV;
                    this->close_EV = close_EV;
                    this->general_EV = general_EV;
                    this->retract_EV = retract_EV;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead_con_stop_stimulate_general_valve& o1, const _ProjectionRead_con_stop_stimulate_general_valve& o2) {
                    return o1.extend_EV == (o2.extend_EV) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.open_EV == (o2.open_EV) && o1.close_EV == (o2.close_EV) && o1.general_EV == (o2.general_EV) && o1.retract_EV == (o2.retract_EV) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead_con_stop_stimulate_general_valve& o1, const _ProjectionRead_con_stop_stimulate_general_valve& o2) {
                    return o1.extend_EV != (o2.extend_EV) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.open_EV != (o2.open_EV) || o1.close_EV != (o2.close_EV) || o1.general_EV != (o2.general_EV) || o1.retract_EV != (o2.retract_EV) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_con_stop_stimulate_general_valve& e) {
                    strm << "{";
                    strm << "extend_EV: " << e.extend_EV;
                    strm << ", ";
                    strm << "handle: " << e.handle;
                    strm << ", ";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "open_EV: " << e.open_EV;
                    strm << ", ";
                    strm << "close_EV: " << e.close_EV;
                    strm << ", ";
                    strm << "general_EV: " << e.general_EV;
                    strm << ", ";
                    strm << "retract_EV: " << e.retract_EV;
                    strm << ", ";
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (extend_EV.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (open_EV.hashCode() << 1);
                    result = 31 * result + (close_EV.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    result = 31 * result + (retract_EV.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_con_stop_stimulate_general_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_con_stop_stimulate_general_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_con_stop_stimulate_general_valve& obj1, const _ProjectionRead__tr_con_stop_stimulate_general_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean extend_EV;
                HANDLE_STATE handle;
                BRelation<POSITION, DOOR_STATE > doors;
                BBoolean open_EV;
                BBoolean close_EV;
                BBoolean general_EV;
                BBoolean retract_EV;
                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead__tr_con_stop_stimulate_general_valve(const BBoolean& extend_EV, const HANDLE_STATE& handle, const BRelation<POSITION, DOOR_STATE >& doors, const BBoolean& open_EV, const BBoolean& close_EV, const BBoolean& general_EV, const BBoolean& retract_EV, const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->extend_EV = extend_EV;
                    this->handle = handle;
                    this->doors = doors;
                    this->open_EV = open_EV;
                    this->close_EV = close_EV;
                    this->general_EV = general_EV;
                    this->retract_EV = retract_EV;
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead__tr_con_stop_stimulate_general_valve& o1, const _ProjectionRead__tr_con_stop_stimulate_general_valve& o2) {
                    return o1.extend_EV == (o2.extend_EV) && o1.handle == (o2.handle) && o1.doors == (o2.doors) && o1.open_EV == (o2.open_EV) && o1.close_EV == (o2.close_EV) && o1.general_EV == (o2.general_EV) && o1.retract_EV == (o2.retract_EV) && o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead__tr_con_stop_stimulate_general_valve& o1, const _ProjectionRead__tr_con_stop_stimulate_general_valve& o2) {
                    return o1.extend_EV != (o2.extend_EV) || o1.handle != (o2.handle) || o1.doors != (o2.doors) || o1.open_EV != (o2.open_EV) || o1.close_EV != (o2.close_EV) || o1.general_EV != (o2.general_EV) || o1.retract_EV != (o2.retract_EV) || o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_con_stop_stimulate_general_valve& e) {
                    strm << "{";
                    strm << "extend_EV: " << e.extend_EV;
                    strm << ", "; 
                    strm << "handle: " << e.handle;
                    strm << ", "; 
                    strm << "doors: " << e.doors;
                    strm << ", "; 
                    strm << "open_EV: " << e.open_EV;
                    strm << ", "; 
                    strm << "close_EV: " << e.close_EV;
                    strm << ", "; 
                    strm << "general_EV: " << e.general_EV;
                    strm << ", "; 
                    strm << "retract_EV: " << e.retract_EV;
                    strm << ", "; 
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (extend_EV.hashCode() << 1);
                    result = 31 * result + (handle.hashCode() << 1);
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (open_EV.hashCode() << 1);
                    result = 31 * result + (close_EV.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    result = 31 * result + (retract_EV.hashCode() << 1);
                    result = 31 * result + (gears.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_con_stop_stimulate_general_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_con_stop_stimulate_general_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_con_stop_stimulate_general_valve& obj1, const _ProjectionWrite_con_stop_stimulate_general_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean handle_move;
                BBoolean general_EV;

                _ProjectionWrite_con_stop_stimulate_general_valve(const BBoolean& handle_move, const BBoolean& general_EV) {
                    this->handle_move = handle_move;
                    this->general_EV = general_EV;
                }

                friend bool operator ==(const _ProjectionWrite_con_stop_stimulate_general_valve& o1, const _ProjectionWrite_con_stop_stimulate_general_valve& o2) {
                    return o1.handle_move == (o2.handle_move) && o1.general_EV == (o2.general_EV);
                }

                friend bool operator !=(const _ProjectionWrite_con_stop_stimulate_general_valve& o1, const _ProjectionWrite_con_stop_stimulate_general_valve& o2) {
                    return o1.handle_move != (o2.handle_move) || o1.general_EV != (o2.general_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_con_stop_stimulate_general_valve& e) {
                    strm << "{";
                    strm << "handle_move: " << e.handle_move;
                    strm << ", ";
                    strm << "general_EV: " << e.general_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (handle_move.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_evn_open_general_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_evn_open_general_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_evn_open_general_valve& obj1, const _ProjectionRead_evn_open_general_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE general_valve;
                SWITCH_STATE analogical_switch;
                BBoolean general_EV;

                _ProjectionRead_evn_open_general_valve(const VALVE_STATE& general_valve, const SWITCH_STATE& analogical_switch, const BBoolean& general_EV) {
                    this->general_valve = general_valve;
                    this->analogical_switch = analogical_switch;
                    this->general_EV = general_EV;
                }

                friend bool operator ==(const _ProjectionRead_evn_open_general_valve& o1, const _ProjectionRead_evn_open_general_valve& o2) {
                    return o1.general_valve == (o2.general_valve) && o1.analogical_switch == (o2.analogical_switch) && o1.general_EV == (o2.general_EV);
                }

                friend bool operator !=(const _ProjectionRead_evn_open_general_valve& o1, const _ProjectionRead_evn_open_general_valve& o2) {
                    return o1.general_valve != (o2.general_valve) || o1.analogical_switch != (o2.analogical_switch) || o1.general_EV != (o2.general_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_evn_open_general_valve& e) {
                    strm << "{";
                    strm << "general_valve: " << e.general_valve;
                    strm << ", ";
                    strm << "analogical_switch: " << e.analogical_switch;
                    strm << ", ";
                    strm << "general_EV: " << e.general_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (analogical_switch.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_evn_open_general_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_evn_open_general_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_evn_open_general_valve& obj1, const _ProjectionRead__tr_evn_open_general_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE general_valve;
                SWITCH_STATE analogical_switch;
                BBoolean general_EV;

                _ProjectionRead__tr_evn_open_general_valve(const VALVE_STATE& general_valve, const SWITCH_STATE& analogical_switch, const BBoolean& general_EV) {
                    this->general_valve = general_valve;
                    this->analogical_switch = analogical_switch;
                    this->general_EV = general_EV;
                }

                friend bool operator ==(const _ProjectionRead__tr_evn_open_general_valve& o1, const _ProjectionRead__tr_evn_open_general_valve& o2) {
                    return o1.general_valve == (o2.general_valve) && o1.analogical_switch == (o2.analogical_switch) && o1.general_EV == (o2.general_EV);
                }

                friend bool operator !=(const _ProjectionRead__tr_evn_open_general_valve& o1, const _ProjectionRead__tr_evn_open_general_valve& o2) {
                    return o1.general_valve != (o2.general_valve) || o1.analogical_switch != (o2.analogical_switch) || o1.general_EV != (o2.general_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_evn_open_general_valve& e) {
                    strm << "{";
                    strm << "general_valve: " << e.general_valve;
                    strm << ", "; 
                    strm << "analogical_switch: " << e.analogical_switch;
                    strm << ", "; 
                    strm << "general_EV: " << e.general_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (analogical_switch.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_evn_open_general_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_evn_open_general_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_evn_open_general_valve& obj1, const _ProjectionWrite_evn_open_general_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE general_valve;

                _ProjectionWrite_evn_open_general_valve(const VALVE_STATE& general_valve) {
                    this->general_valve = general_valve;
                }

                friend bool operator ==(const _ProjectionWrite_evn_open_general_valve& o1, const _ProjectionWrite_evn_open_general_valve& o2) {
                    return o1.general_valve == (o2.general_valve);
                }

                friend bool operator !=(const _ProjectionWrite_evn_open_general_valve& o1, const _ProjectionWrite_evn_open_general_valve& o2) {
                    return o1.general_valve != (o2.general_valve);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_evn_open_general_valve& e) {
                    strm << "{";
                    strm << "general_valve: " << e.general_valve;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (general_valve.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_evn_close_general_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_evn_close_general_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_evn_close_general_valve& obj1, const _ProjectionRead_evn_close_general_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE general_valve;
                SWITCH_STATE analogical_switch;
                BBoolean general_EV;

                _ProjectionRead_evn_close_general_valve(const VALVE_STATE& general_valve, const SWITCH_STATE& analogical_switch, const BBoolean& general_EV) {
                    this->general_valve = general_valve;
                    this->analogical_switch = analogical_switch;
                    this->general_EV = general_EV;
                }

                friend bool operator ==(const _ProjectionRead_evn_close_general_valve& o1, const _ProjectionRead_evn_close_general_valve& o2) {
                    return o1.general_valve == (o2.general_valve) && o1.analogical_switch == (o2.analogical_switch) && o1.general_EV == (o2.general_EV);
                }

                friend bool operator !=(const _ProjectionRead_evn_close_general_valve& o1, const _ProjectionRead_evn_close_general_valve& o2) {
                    return o1.general_valve != (o2.general_valve) || o1.analogical_switch != (o2.analogical_switch) || o1.general_EV != (o2.general_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_evn_close_general_valve& e) {
                    strm << "{";
                    strm << "general_valve: " << e.general_valve;
                    strm << ", ";
                    strm << "analogical_switch: " << e.analogical_switch;
                    strm << ", ";
                    strm << "general_EV: " << e.general_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (analogical_switch.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_evn_close_general_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_evn_close_general_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_evn_close_general_valve& obj1, const _ProjectionRead__tr_evn_close_general_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE general_valve;
                SWITCH_STATE analogical_switch;
                BBoolean general_EV;

                _ProjectionRead__tr_evn_close_general_valve(const VALVE_STATE& general_valve, const SWITCH_STATE& analogical_switch, const BBoolean& general_EV) {
                    this->general_valve = general_valve;
                    this->analogical_switch = analogical_switch;
                    this->general_EV = general_EV;
                }

                friend bool operator ==(const _ProjectionRead__tr_evn_close_general_valve& o1, const _ProjectionRead__tr_evn_close_general_valve& o2) {
                    return o1.general_valve == (o2.general_valve) && o1.analogical_switch == (o2.analogical_switch) && o1.general_EV == (o2.general_EV);
                }

                friend bool operator !=(const _ProjectionRead__tr_evn_close_general_valve& o1, const _ProjectionRead__tr_evn_close_general_valve& o2) {
                    return o1.general_valve != (o2.general_valve) || o1.analogical_switch != (o2.analogical_switch) || o1.general_EV != (o2.general_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_evn_close_general_valve& e) {
                    strm << "{";
                    strm << "general_valve: " << e.general_valve;
                    strm << ", "; 
                    strm << "analogical_switch: " << e.analogical_switch;
                    strm << ", "; 
                    strm << "general_EV: " << e.general_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (general_valve.hashCode() << 1);
                    result = 31 * result + (analogical_switch.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_evn_close_general_valve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_evn_close_general_valve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_evn_close_general_valve& obj1, const _ProjectionWrite_evn_close_general_valve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                VALVE_STATE general_valve;

                _ProjectionWrite_evn_close_general_valve(const VALVE_STATE& general_valve) {
                    this->general_valve = general_valve;
                }

                friend bool operator ==(const _ProjectionWrite_evn_close_general_valve& o1, const _ProjectionWrite_evn_close_general_valve& o2) {
                    return o1.general_valve == (o2.general_valve);
                }

                friend bool operator !=(const _ProjectionWrite_evn_close_general_valve& o1, const _ProjectionWrite_evn_close_general_valve& o2) {
                    return o1.general_valve != (o2.general_valve);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_evn_close_general_valve& e) {
                    strm << "{";
                    strm << "general_valve: " << e.general_valve;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (general_valve.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_env_close_analogical_switch {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_env_close_analogical_switch& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_env_close_analogical_switch& obj1, const _ProjectionRead_env_close_analogical_switch& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                SWITCH_STATE analogical_switch;
                BBoolean handle_move;

                _ProjectionRead_env_close_analogical_switch(const SWITCH_STATE& analogical_switch, const BBoolean& handle_move) {
                    this->analogical_switch = analogical_switch;
                    this->handle_move = handle_move;
                }

                friend bool operator ==(const _ProjectionRead_env_close_analogical_switch& o1, const _ProjectionRead_env_close_analogical_switch& o2) {
                    return o1.analogical_switch == (o2.analogical_switch) && o1.handle_move == (o2.handle_move);
                }

                friend bool operator !=(const _ProjectionRead_env_close_analogical_switch& o1, const _ProjectionRead_env_close_analogical_switch& o2) {
                    return o1.analogical_switch != (o2.analogical_switch) || o1.handle_move != (o2.handle_move);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_env_close_analogical_switch& e) {
                    strm << "{";
                    strm << "analogical_switch: " << e.analogical_switch;
                    strm << ", ";
                    strm << "handle_move: " << e.handle_move;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (analogical_switch.hashCode() << 1);
                    result = 31 * result + (handle_move.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_env_close_analogical_switch {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_env_close_analogical_switch& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_env_close_analogical_switch& obj1, const _ProjectionRead__tr_env_close_analogical_switch& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                SWITCH_STATE analogical_switch;
                BBoolean handle_move;

                _ProjectionRead__tr_env_close_analogical_switch(const SWITCH_STATE& analogical_switch, const BBoolean& handle_move) {
                    this->analogical_switch = analogical_switch;
                    this->handle_move = handle_move;
                }

                friend bool operator ==(const _ProjectionRead__tr_env_close_analogical_switch& o1, const _ProjectionRead__tr_env_close_analogical_switch& o2) {
                    return o1.analogical_switch == (o2.analogical_switch) && o1.handle_move == (o2.handle_move);
                }

                friend bool operator !=(const _ProjectionRead__tr_env_close_analogical_switch& o1, const _ProjectionRead__tr_env_close_analogical_switch& o2) {
                    return o1.analogical_switch != (o2.analogical_switch) || o1.handle_move != (o2.handle_move);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_env_close_analogical_switch& e) {
                    strm << "{";
                    strm << "analogical_switch: " << e.analogical_switch;
                    strm << ", "; 
                    strm << "handle_move: " << e.handle_move;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (analogical_switch.hashCode() << 1);
                    result = 31 * result + (handle_move.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_env_close_analogical_switch {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_env_close_analogical_switch& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_env_close_analogical_switch& obj1, const _ProjectionWrite_env_close_analogical_switch& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                SWITCH_STATE analogical_switch;

                _ProjectionWrite_env_close_analogical_switch(const SWITCH_STATE& analogical_switch) {
                    this->analogical_switch = analogical_switch;
                }

                friend bool operator ==(const _ProjectionWrite_env_close_analogical_switch& o1, const _ProjectionWrite_env_close_analogical_switch& o2) {
                    return o1.analogical_switch == (o2.analogical_switch);
                }

                friend bool operator !=(const _ProjectionWrite_env_close_analogical_switch& o1, const _ProjectionWrite_env_close_analogical_switch& o2) {
                    return o1.analogical_switch != (o2.analogical_switch);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_env_close_analogical_switch& e) {
                    strm << "{";
                    strm << "analogical_switch: " << e.analogical_switch;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (analogical_switch.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_env_open_analogical_switch {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_env_open_analogical_switch& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_env_open_analogical_switch& obj1, const _ProjectionRead_env_open_analogical_switch& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                SWITCH_STATE analogical_switch;

                _ProjectionRead_env_open_analogical_switch(const SWITCH_STATE& analogical_switch) {
                    this->analogical_switch = analogical_switch;
                }

                friend bool operator ==(const _ProjectionRead_env_open_analogical_switch& o1, const _ProjectionRead_env_open_analogical_switch& o2) {
                    return o1.analogical_switch == (o2.analogical_switch);
                }

                friend bool operator !=(const _ProjectionRead_env_open_analogical_switch& o1, const _ProjectionRead_env_open_analogical_switch& o2) {
                    return o1.analogical_switch != (o2.analogical_switch);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_env_open_analogical_switch& e) {
                    strm << "{";
                    strm << "analogical_switch: " << e.analogical_switch;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (analogical_switch.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_env_open_analogical_switch {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_env_open_analogical_switch& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_env_open_analogical_switch& obj1, const _ProjectionRead__tr_env_open_analogical_switch& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                SWITCH_STATE analogical_switch;

                _ProjectionRead__tr_env_open_analogical_switch(const SWITCH_STATE& analogical_switch) {
                    this->analogical_switch = analogical_switch;
                }

                friend bool operator ==(const _ProjectionRead__tr_env_open_analogical_switch& o1, const _ProjectionRead__tr_env_open_analogical_switch& o2) {
                    return o1.analogical_switch == (o2.analogical_switch);
                }

                friend bool operator !=(const _ProjectionRead__tr_env_open_analogical_switch& o1, const _ProjectionRead__tr_env_open_analogical_switch& o2) {
                    return o1.analogical_switch != (o2.analogical_switch);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_env_open_analogical_switch& e) {
                    strm << "{";
                    strm << "analogical_switch: " << e.analogical_switch;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (analogical_switch.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_env_open_analogical_switch {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_env_open_analogical_switch& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_env_open_analogical_switch& obj1, const _ProjectionWrite_env_open_analogical_switch& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                SWITCH_STATE analogical_switch;

                _ProjectionWrite_env_open_analogical_switch(const SWITCH_STATE& analogical_switch) {
                    this->analogical_switch = analogical_switch;
                }

                friend bool operator ==(const _ProjectionWrite_env_open_analogical_switch& o1, const _ProjectionWrite_env_open_analogical_switch& o2) {
                    return o1.analogical_switch == (o2.analogical_switch);
                }

                friend bool operator !=(const _ProjectionWrite_env_open_analogical_switch& o1, const _ProjectionWrite_env_open_analogical_switch& o2) {
                    return o1.analogical_switch != (o2.analogical_switch);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_env_open_analogical_switch& e) {
                    strm << "{";
                    strm << "analogical_switch: " << e.analogical_switch;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (analogical_switch.hashCode() << 1);
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

                SWITCH_STATE analogical_switch;

                _ProjectionRead__check_inv_1(const SWITCH_STATE& analogical_switch) {
                    this->analogical_switch = analogical_switch;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.analogical_switch == (o2.analogical_switch);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.analogical_switch != (o2.analogical_switch);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_1& e) {
                    strm << "{";
                    strm << "analogical_switch: " << e.analogical_switch;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (analogical_switch.hashCode() << 1);
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

                BBoolean general_EV;

                _ProjectionRead__check_inv_2(const BBoolean& general_EV) {
                    this->general_EV = general_EV;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_2& o1, const _ProjectionRead__check_inv_2& o2) {
                    return o1.general_EV == (o2.general_EV);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_2& o1, const _ProjectionRead__check_inv_2& o2) {
                    return o1.general_EV != (o2.general_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_2& e) {
                    strm << "{";
                    strm << "general_EV: " << e.general_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (general_EV.hashCode() << 1);
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

                VALVE_STATE general_valve;

                _ProjectionRead__check_inv_3(const VALVE_STATE& general_valve) {
                    this->general_valve = general_valve;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_3& o1, const _ProjectionRead__check_inv_3& o2) {
                    return o1.general_valve == (o2.general_valve);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_3& o1, const _ProjectionRead__check_inv_3& o2) {
                    return o1.general_valve != (o2.general_valve);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_3& e) {
                    strm << "{";
                    strm << "general_valve: " << e.general_valve;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (general_valve.hashCode() << 1);
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

                BBoolean handle_move;

                _ProjectionRead__check_inv_4(const BBoolean& handle_move) {
                    this->handle_move = handle_move;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_4& o1, const _ProjectionRead__check_inv_4& o2) {
                    return o1.handle_move == (o2.handle_move);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_4& o1, const _ProjectionRead__check_inv_4& o2) {
                    return o1.handle_move != (o2.handle_move);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_4& e) {
                    strm << "{";
                    strm << "handle_move: " << e.handle_move;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (handle_move.hashCode() << 1);
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

                BBoolean close_EV;

                _ProjectionRead__check_inv_5(const BBoolean& close_EV) {
                    this->close_EV = close_EV;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_5& o1, const _ProjectionRead__check_inv_5& o2) {
                    return o1.close_EV == (o2.close_EV);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_5& o1, const _ProjectionRead__check_inv_5& o2) {
                    return o1.close_EV != (o2.close_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_5& e) {
                    strm << "{";
                    strm << "close_EV: " << e.close_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (close_EV.hashCode() << 1);
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

                BBoolean extend_EV;

                _ProjectionRead__check_inv_6(const BBoolean& extend_EV) {
                    this->extend_EV = extend_EV;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_6& o1, const _ProjectionRead__check_inv_6& o2) {
                    return o1.extend_EV == (o2.extend_EV);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_6& o1, const _ProjectionRead__check_inv_6& o2) {
                    return o1.extend_EV != (o2.extend_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_6& e) {
                    strm << "{";
                    strm << "extend_EV: " << e.extend_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (extend_EV.hashCode() << 1);
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

                BBoolean open_EV;

                _ProjectionRead__check_inv_7(const BBoolean& open_EV) {
                    this->open_EV = open_EV;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_7& o1, const _ProjectionRead__check_inv_7& o2) {
                    return o1.open_EV == (o2.open_EV);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_7& o1, const _ProjectionRead__check_inv_7& o2) {
                    return o1.open_EV != (o2.open_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_7& e) {
                    strm << "{";
                    strm << "open_EV: " << e.open_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (open_EV.hashCode() << 1);
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

                BBoolean retract_EV;

                _ProjectionRead__check_inv_8(const BBoolean& retract_EV) {
                    this->retract_EV = retract_EV;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_8& o1, const _ProjectionRead__check_inv_8& o2) {
                    return o1.retract_EV == (o2.retract_EV);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_8& o1, const _ProjectionRead__check_inv_8& o2) {
                    return o1.retract_EV != (o2.retract_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_8& e) {
                    strm << "{";
                    strm << "retract_EV: " << e.retract_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (retract_EV.hashCode() << 1);
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

                PLANE_STATE shock_absorber;

                _ProjectionRead__check_inv_9(const PLANE_STATE& shock_absorber) {
                    this->shock_absorber = shock_absorber;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_9& o1, const _ProjectionRead__check_inv_9& o2) {
                    return o1.shock_absorber == (o2.shock_absorber);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_9& o1, const _ProjectionRead__check_inv_9& o2) {
                    return o1.shock_absorber != (o2.shock_absorber);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_9& e) {
                    strm << "{";
                    strm << "shock_absorber: " << e.shock_absorber;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (shock_absorber.hashCode() << 1);
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

                VALVE_STATE valve_close_door;

                _ProjectionRead__check_inv_10(const VALVE_STATE& valve_close_door) {
                    this->valve_close_door = valve_close_door;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_10& o1, const _ProjectionRead__check_inv_10& o2) {
                    return o1.valve_close_door == (o2.valve_close_door);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_10& o1, const _ProjectionRead__check_inv_10& o2) {
                    return o1.valve_close_door != (o2.valve_close_door);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_10& e) {
                    strm << "{";
                    strm << "valve_close_door: " << e.valve_close_door;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_close_door.hashCode() << 1);
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

                VALVE_STATE valve_extend_gear;

                _ProjectionRead__check_inv_11(const VALVE_STATE& valve_extend_gear) {
                    this->valve_extend_gear = valve_extend_gear;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_11& o1, const _ProjectionRead__check_inv_11& o2) {
                    return o1.valve_extend_gear == (o2.valve_extend_gear);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_11& o1, const _ProjectionRead__check_inv_11& o2) {
                    return o1.valve_extend_gear != (o2.valve_extend_gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_11& e) {
                    strm << "{";
                    strm << "valve_extend_gear: " << e.valve_extend_gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_extend_gear.hashCode() << 1);
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

                VALVE_STATE valve_open_door;

                _ProjectionRead__check_inv_12(const VALVE_STATE& valve_open_door) {
                    this->valve_open_door = valve_open_door;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_12& o1, const _ProjectionRead__check_inv_12& o2) {
                    return o1.valve_open_door == (o2.valve_open_door);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_12& o1, const _ProjectionRead__check_inv_12& o2) {
                    return o1.valve_open_door != (o2.valve_open_door);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_12& e) {
                    strm << "{";
                    strm << "valve_open_door: " << e.valve_open_door;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_open_door.hashCode() << 1);
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

                VALVE_STATE valve_retract_gear;

                _ProjectionRead__check_inv_13(const VALVE_STATE& valve_retract_gear) {
                    this->valve_retract_gear = valve_retract_gear;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_13& o1, const _ProjectionRead__check_inv_13& o2) {
                    return o1.valve_retract_gear == (o2.valve_retract_gear);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_13& o1, const _ProjectionRead__check_inv_13& o2) {
                    return o1.valve_retract_gear != (o2.valve_retract_gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_13& e) {
                    strm << "{";
                    strm << "valve_retract_gear: " << e.valve_retract_gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (valve_retract_gear.hashCode() << 1);
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

                HANDLE_STATE handle;

                _ProjectionRead__check_inv_14(const HANDLE_STATE& handle) {
                    this->handle = handle;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_14& o1, const _ProjectionRead__check_inv_14& o2) {
                    return o1.handle == (o2.handle);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_14& o1, const _ProjectionRead__check_inv_14& o2) {
                    return o1.handle != (o2.handle);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_14& e) {
                    strm << "{";
                    strm << "handle: " << e.handle;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (handle.hashCode() << 1);
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

                DOOR_STATE door;

                _ProjectionRead__check_inv_15(const DOOR_STATE& door) {
                    this->door = door;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_15& o1, const _ProjectionRead__check_inv_15& o2) {
                    return o1.door == (o2.door);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_15& o1, const _ProjectionRead__check_inv_15& o2) {
                    return o1.door != (o2.door);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_15& e) {
                    strm << "{";
                    strm << "door: " << e.door;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (door.hashCode() << 1);
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

                GEAR_STATE gear;

                _ProjectionRead__check_inv_16(const GEAR_STATE& gear) {
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_16& o1, const _ProjectionRead__check_inv_16& o2) {
                    return o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_16& o1, const _ProjectionRead__check_inv_16& o2) {
                    return o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_16& e) {
                    strm << "{";
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (gear.hashCode() << 1);
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

                BBoolean extend_EV;
                BBoolean open_EV;
                BBoolean close_EV;
                BBoolean general_EV;
                BBoolean retract_EV;

                _ProjectionRead__check_inv_17(const BBoolean& extend_EV, const BBoolean& open_EV, const BBoolean& close_EV, const BBoolean& general_EV, const BBoolean& retract_EV) {
                    this->extend_EV = extend_EV;
                    this->open_EV = open_EV;
                    this->close_EV = close_EV;
                    this->general_EV = general_EV;
                    this->retract_EV = retract_EV;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_17& o1, const _ProjectionRead__check_inv_17& o2) {
                    return o1.extend_EV == (o2.extend_EV) && o1.open_EV == (o2.open_EV) && o1.close_EV == (o2.close_EV) && o1.general_EV == (o2.general_EV) && o1.retract_EV == (o2.retract_EV);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_17& o1, const _ProjectionRead__check_inv_17& o2) {
                    return o1.extend_EV != (o2.extend_EV) || o1.open_EV != (o2.open_EV) || o1.close_EV != (o2.close_EV) || o1.general_EV != (o2.general_EV) || o1.retract_EV != (o2.retract_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_17& e) {
                    strm << "{";
                    strm << "extend_EV: " << e.extend_EV;
                    strm << ", ";
                    strm << "open_EV: " << e.open_EV;
                    strm << ", ";
                    strm << "close_EV: " << e.close_EV;
                    strm << ", ";
                    strm << "general_EV: " << e.general_EV;
                    strm << ", ";
                    strm << "retract_EV: " << e.retract_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (extend_EV.hashCode() << 1);
                    result = 31 * result + (open_EV.hashCode() << 1);
                    result = 31 * result + (close_EV.hashCode() << 1);
                    result = 31 * result + (general_EV.hashCode() << 1);
                    result = 31 * result + (retract_EV.hashCode() << 1);
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

                BBoolean open_EV;
                BBoolean close_EV;

                _ProjectionRead__check_inv_18(const BBoolean& open_EV, const BBoolean& close_EV) {
                    this->open_EV = open_EV;
                    this->close_EV = close_EV;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_18& o1, const _ProjectionRead__check_inv_18& o2) {
                    return o1.open_EV == (o2.open_EV) && o1.close_EV == (o2.close_EV);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_18& o1, const _ProjectionRead__check_inv_18& o2) {
                    return o1.open_EV != (o2.open_EV) || o1.close_EV != (o2.close_EV);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_18& e) {
                    strm << "{";
                    strm << "open_EV: " << e.open_EV;
                    strm << ", ";
                    strm << "close_EV: " << e.close_EV;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (open_EV.hashCode() << 1);
                    result = 31 * result + (close_EV.hashCode() << 1);
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

                BRelation<POSITION, GEAR_STATE > gears;

                _ProjectionRead__check_inv_19(const BRelation<POSITION, GEAR_STATE >& gears) {
                    this->gears = gears;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_19& o1, const _ProjectionRead__check_inv_19& o2) {
                    return o1.gears == (o2.gears);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_19& o1, const _ProjectionRead__check_inv_19& o2) {
                    return o1.gears != (o2.gears);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_19& e) {
                    strm << "{";
                    strm << "gears: " << e.gears;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (gears.hashCode() << 1);
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

                BRelation<POSITION, DOOR_STATE > doors;

                _ProjectionRead__check_inv_20(const BRelation<POSITION, DOOR_STATE >& doors) {
                    this->doors = doors;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_20& o1, const _ProjectionRead__check_inv_20& o2) {
                    return o1.doors == (o2.doors);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_20& o1, const _ProjectionRead__check_inv_20& o2) {
                    return o1.doors != (o2.doors);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_20& e) {
                    strm << "{";
                    strm << "doors: " << e.doors;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (doors.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_21 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_21& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_21& obj1, const _ProjectionRead__check_inv_21& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, DOOR_STATE > doors;
                DOOR_STATE door;

                _ProjectionRead__check_inv_21(const BRelation<POSITION, DOOR_STATE >& doors, const DOOR_STATE& door) {
                    this->doors = doors;
                    this->door = door;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_21& o1, const _ProjectionRead__check_inv_21& o2) {
                    return o1.doors == (o2.doors) && o1.door == (o2.door);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_21& o1, const _ProjectionRead__check_inv_21& o2) {
                    return o1.doors != (o2.doors) || o1.door != (o2.door);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_21& e) {
                    strm << "{";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "door: " << e.door;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (door.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_22 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_22& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_22& obj1, const _ProjectionRead__check_inv_22& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, DOOR_STATE > doors;
                DOOR_STATE door;

                _ProjectionRead__check_inv_22(const BRelation<POSITION, DOOR_STATE >& doors, const DOOR_STATE& door) {
                    this->doors = doors;
                    this->door = door;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_22& o1, const _ProjectionRead__check_inv_22& o2) {
                    return o1.doors == (o2.doors) && o1.door == (o2.door);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_22& o1, const _ProjectionRead__check_inv_22& o2) {
                    return o1.doors != (o2.doors) || o1.door != (o2.door);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_22& e) {
                    strm << "{";
                    strm << "doors: " << e.doors;
                    strm << ", ";
                    strm << "door: " << e.door;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (doors.hashCode() << 1);
                    result = 31 * result + (door.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_23 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_23& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_23& obj1, const _ProjectionRead__check_inv_23& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionRead__check_inv_23(const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_23& o1, const _ProjectionRead__check_inv_23& o2) {
                    return o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_23& o1, const _ProjectionRead__check_inv_23& o2) {
                    return o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_23& e) {
                    strm << "{";
                    strm << "gears: " << e.gears;
                    strm << ", ";
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_24 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_24& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_24& obj1, const _ProjectionRead__check_inv_24& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<POSITION, GEAR_STATE > gears;
                GEAR_STATE gear;

                _ProjectionRead__check_inv_24(const BRelation<POSITION, GEAR_STATE >& gears, const GEAR_STATE& gear) {
                    this->gears = gears;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_24& o1, const _ProjectionRead__check_inv_24& o2) {
                    return o1.gears == (o2.gears) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_24& o1, const _ProjectionRead__check_inv_24& o2) {
                    return o1.gears != (o2.gears) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_24& e) {
                    strm << "{";
                    strm << "gears: " << e.gears;
                    strm << ", ";
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (gears.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_25 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_25& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_25& obj1, const _ProjectionRead__check_inv_25& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                DOOR_STATE door;
                GEAR_STATE gear;

                _ProjectionRead__check_inv_25(const DOOR_STATE& door, const GEAR_STATE& gear) {
                    this->door = door;
                    this->gear = gear;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_25& o1, const _ProjectionRead__check_inv_25& o2) {
                    return o1.door == (o2.door) && o1.gear == (o2.gear);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_25& o1, const _ProjectionRead__check_inv_25& o2) {
                    return o1.door != (o2.door) || o1.gear != (o2.gear);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_25& e) {
                    strm << "{";
                    strm << "door: " << e.door;
                    strm << ", ";
                    strm << "gear: " << e.gear;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (door.hashCode() << 1);
                    result = 31 * result + (gear.hashCode() << 1);
                    return result;
                }

        };



    private:



        #define _DOOR_STATE (BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open)), (DOOR_STATE(DOOR_STATE::closed)), (DOOR_STATE(DOOR_STATE::door_moving))))
        #define _GEAR_STATE (BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted)), (GEAR_STATE(GEAR_STATE::extended)), (GEAR_STATE(GEAR_STATE::gear_moving))))
        #define _HANDLE_STATE (BSet<HANDLE_STATE >((HANDLE_STATE(HANDLE_STATE::up)), (HANDLE_STATE(HANDLE_STATE::down))))
        #define _POSITION (BSet<POSITION >((POSITION(POSITION::fr)), (POSITION(POSITION::lt)), (POSITION(POSITION::rt))))
        #define _SWITCH_STATE (BSet<SWITCH_STATE >((SWITCH_STATE(SWITCH_STATE::switch_open)), (SWITCH_STATE(SWITCH_STATE::switch_closed))))
        #define _PLANE_STATE (BSet<PLANE_STATE >((PLANE_STATE(PLANE_STATE::ground)), (PLANE_STATE(PLANE_STATE::flight))))
        #define _VALVE_STATE (BSet<VALVE_STATE >((VALVE_STATE(VALVE_STATE::valve_open)), (VALVE_STATE(VALVE_STATE::valve_closed))))

        SWITCH_STATE analogical_switch;
        BBoolean general_EV;
        VALVE_STATE general_valve;
        BBoolean handle_move;
        BBoolean close_EV;
        BBoolean extend_EV;
        BBoolean open_EV;
        BBoolean retract_EV;
        PLANE_STATE shock_absorber;
        VALVE_STATE valve_close_door;
        VALVE_STATE valve_extend_gear;
        VALVE_STATE valve_open_door;
        VALVE_STATE valve_retract_gear;
        BRelation<POSITION, DOOR_STATE > doors;
        BRelation<POSITION, GEAR_STATE > gears;
        HANDLE_STATE handle;
        DOOR_STATE door;
        GEAR_STATE gear;


    public:

        std::string stateAccessedVia;

        LandingGear_R6() {
            gears = (BRelation<POSITION, GEAR_STATE >::cartesianProduct(_POSITION, (BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))));
            doors = (BRelation<POSITION, DOOR_STATE >::cartesianProduct(_POSITION, (BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed))))));
            handle = (HANDLE_STATE(HANDLE_STATE::down));
            valve_extend_gear = (VALVE_STATE(VALVE_STATE::valve_closed));
            valve_retract_gear = (VALVE_STATE(VALVE_STATE::valve_closed));
            valve_open_door = (VALVE_STATE(VALVE_STATE::valve_closed));
            valve_close_door = (VALVE_STATE(VALVE_STATE::valve_closed));
            open_EV = (BBoolean(false));
            close_EV = (BBoolean(false));
            retract_EV = (BBoolean(false));
            extend_EV = (BBoolean(false));
            shock_absorber = (PLANE_STATE(PLANE_STATE::ground));
            general_EV = (BBoolean(false));
            general_valve = (VALVE_STATE(VALVE_STATE::valve_closed));
            analogical_switch = (SWITCH_STATE(SWITCH_STATE::switch_open));
            handle_move = (BBoolean(false));
            gear = (GEAR_STATE(GEAR_STATE::extended));
            door = (DOOR_STATE(DOOR_STATE::closed));
        }

        LandingGear_R6(const LandingGear_R6& copy) {
            this->analogical_switch = copy.analogical_switch;
            this->general_EV = copy.general_EV;
            this->general_valve = copy.general_valve;
            this->handle_move = copy.handle_move;
            this->close_EV = copy.close_EV;
            this->extend_EV = copy.extend_EV;
            this->open_EV = copy.open_EV;
            this->retract_EV = copy.retract_EV;
            this->shock_absorber = copy.shock_absorber;
            this->valve_close_door = copy.valve_close_door;
            this->valve_extend_gear = copy.valve_extend_gear;
            this->valve_open_door = copy.valve_open_door;
            this->valve_retract_gear = copy.valve_retract_gear;
            this->doors = copy.doors;
            this->gears = copy.gears;
            this->handle = copy.handle;
            this->door = copy.door;
            this->gear = copy.gear;
        }

        void begin_flying() {
            shock_absorber = (PLANE_STATE(PLANE_STATE::flight));

        }

        void land_plane() {
            shock_absorber = (PLANE_STATE(PLANE_STATE::ground));

        }

        void open_valve_door_open() {
            valve_open_door = (VALVE_STATE(VALVE_STATE::valve_open));

        }

        void close_valve_door_open() {
            valve_open_door = (VALVE_STATE(VALVE_STATE::valve_closed));

        }

        void open_valve_door_close() {
            valve_close_door = (VALVE_STATE(VALVE_STATE::valve_open));

        }

        void close_valve_door_close() {
            valve_close_door = (VALVE_STATE(VALVE_STATE::valve_closed));

        }

        void open_valve_retract_gear() {
            valve_retract_gear = (VALVE_STATE(VALVE_STATE::valve_open));

        }

        void close_valve_retract_gear() {
            valve_retract_gear = (VALVE_STATE(VALVE_STATE::valve_closed));

        }

        void open_valve_extend_gear() {
            valve_extend_gear = (VALVE_STATE(VALVE_STATE::valve_open));

        }

        void close_valve_extend_gear() {
            valve_extend_gear = (VALVE_STATE(VALVE_STATE::valve_closed));

        }

        void con_stimulate_open_door_valve() {
            open_EV = (BBoolean(true));

        }

        void con_stop_stimulate_open_door_valve() {
            open_EV = (BBoolean(false));

        }

        void con_stimulate_close_door_valve() {
            close_EV = (BBoolean(true));

        }

        void con_stop_stimulate_close_door_valve() {
            close_EV = (BBoolean(false));

        }

        void con_stimulate_retract_gear_valve() {
            retract_EV = (BBoolean(true));

        }

        void con_stop_stimulate_retract_gear_valve() {
            retract_EV = (BBoolean(false));

        }

        void con_stimulate_extend_gear_valve() {
            extend_EV = (BBoolean(true));

        }

        void con_stop_stimulate_extend_gear_valve() {
            extend_EV = (BBoolean(false));

        }

        void env_start_retracting_first(const POSITION& gr) {
            BRelation<POSITION, GEAR_STATE > _ld_gears = gears;
            gears = _ld_gears.override((BRelation<POSITION, GEAR_STATE >((BTuple<POSITION, GEAR_STATE >(gr, (GEAR_STATE(GEAR_STATE::gear_moving)))))));
            gear = (GEAR_STATE(GEAR_STATE::gear_moving));

        }

        void env_retract_gear_skip(const POSITION& gr) {
            gears = gears.override((BRelation<POSITION, GEAR_STATE >((BTuple<POSITION, GEAR_STATE >(gr, (GEAR_STATE(GEAR_STATE::retracted)))))));

        }

        void env_retract_gear_last(const POSITION& gr) {
            BRelation<POSITION, GEAR_STATE > _ld_gears = gears;
            gears = _ld_gears.override((BRelation<POSITION, GEAR_STATE >((BTuple<POSITION, GEAR_STATE >(gr, (GEAR_STATE(GEAR_STATE::retracted)))))));
            gear = (GEAR_STATE(GEAR_STATE::retracted));

        }

        void env_start_extending(const POSITION& gr) {
            BRelation<POSITION, GEAR_STATE > _ld_gears = gears;
            gears = _ld_gears.override((BRelation<POSITION, GEAR_STATE >((BTuple<POSITION, GEAR_STATE >(gr, (GEAR_STATE(GEAR_STATE::gear_moving)))))));
            gear = (GEAR_STATE(GEAR_STATE::gear_moving));

        }

        void env_extend_gear_last(const POSITION& gr) {
            BRelation<POSITION, GEAR_STATE > _ld_gears = gears;
            gears = _ld_gears.override((BRelation<POSITION, GEAR_STATE >((BTuple<POSITION, GEAR_STATE >(gr, (GEAR_STATE(GEAR_STATE::extended)))))));
            gear = (GEAR_STATE(GEAR_STATE::extended));

        }

        void env_extend_gear_skip(const POSITION& gr) {
            gears = gears.override((BRelation<POSITION, GEAR_STATE >((BTuple<POSITION, GEAR_STATE >(gr, (GEAR_STATE(GEAR_STATE::extended)))))));

        }

        void env_start_open_door(const POSITION& gr) {
            BRelation<POSITION, DOOR_STATE > _ld_doors = doors;
            doors = _ld_doors.override((BRelation<POSITION, DOOR_STATE >((BTuple<POSITION, DOOR_STATE >(gr, (DOOR_STATE(DOOR_STATE::door_moving)))))));
            door = (DOOR_STATE(DOOR_STATE::door_moving));

        }

        void env_open_door_last(const POSITION& gr) {
            BRelation<POSITION, DOOR_STATE > _ld_doors = doors;
            doors = _ld_doors.override((BRelation<POSITION, DOOR_STATE >((BTuple<POSITION, DOOR_STATE >(gr, (DOOR_STATE(DOOR_STATE::open)))))));
            door = (DOOR_STATE(DOOR_STATE::open));

        }

        void env_open_door_skip(const POSITION& gr) {
            doors = doors.override((BRelation<POSITION, DOOR_STATE >((BTuple<POSITION, DOOR_STATE >(gr, (DOOR_STATE(DOOR_STATE::open)))))));

        }

        void env_start_close_door(const POSITION& gr) {
            BRelation<POSITION, DOOR_STATE > _ld_doors = doors;
            doors = _ld_doors.override((BRelation<POSITION, DOOR_STATE >((BTuple<POSITION, DOOR_STATE >(gr, (DOOR_STATE(DOOR_STATE::door_moving)))))));
            door = (DOOR_STATE(DOOR_STATE::door_moving));

        }

        void env_close_door(const POSITION& gr) {
            BRelation<POSITION, DOOR_STATE > _ld_doors = doors;
            doors = _ld_doors.override((BRelation<POSITION, DOOR_STATE >((BTuple<POSITION, DOOR_STATE >(gr, (DOOR_STATE(DOOR_STATE::closed)))))));
            door = (DOOR_STATE(DOOR_STATE::closed));

        }

        void env_close_door_skip(const POSITION& gr) {
            doors = doors.override((BRelation<POSITION, DOOR_STATE >((BTuple<POSITION, DOOR_STATE >(gr, (DOOR_STATE(DOOR_STATE::closed)))))));

        }

        void toggle_handle_up() {
            handle = (HANDLE_STATE(HANDLE_STATE::up));
            handle_move = (BBoolean(true));

        }

        void toggle_handle_down() {
            handle = (HANDLE_STATE(HANDLE_STATE::down));
            handle_move = (BBoolean(true));

        }

        void con_stimulate_general_valve() {
            general_EV = (BBoolean(true));

        }

        void con_stop_stimulate_general_valve() {
            general_EV = (BBoolean(false));
            handle_move = (BBoolean(false));

        }

        void evn_open_general_valve() {
            general_valve = (VALVE_STATE(VALVE_STATE::valve_open));

        }

        void evn_close_general_valve() {
            general_valve = (VALVE_STATE(VALVE_STATE::valve_closed));

        }

        void env_close_analogical_switch() {
            analogical_switch = (SWITCH_STATE(SWITCH_STATE::switch_closed));

        }

        void env_open_analogical_switch() {
            analogical_switch = (SWITCH_STATE(SWITCH_STATE::switch_open));

        }

        SWITCH_STATE _get_analogical_switch() const {
            return analogical_switch;
        }

        BBoolean _get_general_EV() const {
            return general_EV;
        }

        VALVE_STATE _get_general_valve() const {
            return general_valve;
        }

        BBoolean _get_handle_move() const {
            return handle_move;
        }

        BBoolean _get_close_EV() const {
            return close_EV;
        }

        BBoolean _get_extend_EV() const {
            return extend_EV;
        }

        BBoolean _get_open_EV() const {
            return open_EV;
        }

        BBoolean _get_retract_EV() const {
            return retract_EV;
        }

        PLANE_STATE _get_shock_absorber() const {
            return shock_absorber;
        }

        VALVE_STATE _get_valve_close_door() const {
            return valve_close_door;
        }

        VALVE_STATE _get_valve_extend_gear() const {
            return valve_extend_gear;
        }

        VALVE_STATE _get_valve_open_door() const {
            return valve_open_door;
        }

        VALVE_STATE _get_valve_retract_gear() const {
            return valve_retract_gear;
        }

        BRelation<POSITION, DOOR_STATE > _get_doors() const {
            return doors;
        }

        BRelation<POSITION, GEAR_STATE > _get_gears() const {
            return gears;
        }

        HANDLE_STATE _get_handle() const {
            return handle;
        }

        DOOR_STATE _get_door() const {
            return door;
        }

        GEAR_STATE _get_gear() const {
            return gear;
        }

        BSet<DOOR_STATE > _get__DOOR_STATE() const {
            return _DOOR_STATE;
        }

        BSet<GEAR_STATE > _get__GEAR_STATE() const {
            return _GEAR_STATE;
        }

        BSet<HANDLE_STATE > _get__HANDLE_STATE() const {
            return _HANDLE_STATE;
        }

        BSet<POSITION > _get__POSITION() const {
            return _POSITION;
        }

        BSet<SWITCH_STATE > _get__SWITCH_STATE() const {
            return _SWITCH_STATE;
        }

        BSet<PLANE_STATE > _get__PLANE_STATE() const {
            return _PLANE_STATE;
        }

        BSet<VALVE_STATE > _get__VALVE_STATE() const {
            return _VALVE_STATE;
        }


        bool _tr_begin_flying() const {
            return (shock_absorber.equal((PLANE_STATE(PLANE_STATE::ground)))).booleanValue();
        }

        bool _tr_land_plane() const {
            return (shock_absorber.equal((PLANE_STATE(PLANE_STATE::flight)))).booleanValue();
        }

        bool _tr_open_valve_door_open() const {
            return ((BBoolean(valve_open_door.equal((VALVE_STATE(VALVE_STATE::valve_closed))).booleanValue() && open_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
        }

        bool _tr_close_valve_door_open() const {
            return ((BBoolean(valve_open_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue() && open_EV.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        bool _tr_open_valve_door_close() const {
            return ((BBoolean(valve_close_door.equal((VALVE_STATE(VALVE_STATE::valve_closed))).booleanValue() && close_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
        }

        bool _tr_close_valve_door_close() const {
            return ((BBoolean(valve_close_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue() && close_EV.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        bool _tr_open_valve_retract_gear() const {
            return ((BBoolean(valve_retract_gear.equal((VALVE_STATE(VALVE_STATE::valve_closed))).booleanValue() && retract_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
        }

        bool _tr_close_valve_retract_gear() const {
            return ((BBoolean(valve_retract_gear.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue() && retract_EV.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        bool _tr_open_valve_extend_gear() const {
            return ((BBoolean(valve_extend_gear.equal((VALVE_STATE(VALVE_STATE::valve_closed))).booleanValue() && extend_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
        }

        bool _tr_close_valve_extend_gear() const {
            return ((BBoolean(valve_extend_gear.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue() && extend_EV.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        bool _tr_con_stimulate_open_door_valve() const {
            return ((BBoolean((BBoolean((BBoolean(open_EV.equal((BBoolean(false))).booleanValue() && close_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended)))))._not().booleanValue())).booleanValue() || (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted)))))._not().booleanValue())).booleanValue() && (BBoolean(doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue() && shock_absorber.equal((PLANE_STATE(PLANE_STATE::ground))).booleanValue()))._not().booleanValue())).booleanValue())).booleanValue())).booleanValue() && general_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
        }

        bool _tr_con_stop_stimulate_open_door_valve() const {
            return ((BBoolean((BBoolean((BBoolean((BBoolean(open_EV.equal((BBoolean(true))).booleanValue() && extend_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && retract_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() || (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && (BBoolean(gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue() || shock_absorber.equal((PLANE_STATE(PLANE_STATE::ground))).booleanValue())).booleanValue())).booleanValue() && doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && general_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
        }

        bool _tr_con_stimulate_close_door_valve() const {
            return ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(close_EV.equal((BBoolean(false))).booleanValue() && open_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && extend_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && retract_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && (BBoolean(gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue() || shock_absorber.equal((PLANE_STATE(PLANE_STATE::ground))).booleanValue())).booleanValue())).booleanValue())).booleanValue())).booleanValue() && doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed)))))._not().booleanValue())).booleanValue() && general_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
        }

        bool _tr_con_stop_stimulate_close_door_valve() const {
            return ((BBoolean((BBoolean(close_EV.equal((BBoolean(true))).booleanValue() && (BBoolean((BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() && doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed))))).booleanValue())).booleanValue() || (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && (BBoolean(gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue() || shock_absorber.equal((PLANE_STATE(PLANE_STATE::ground))).booleanValue())).booleanValue())).booleanValue() && doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && general_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
        }

        bool _tr_con_stimulate_retract_gear_valve() const {
            return ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(retract_EV.equal((BBoolean(false))).booleanValue() && extend_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && open_EV.equal((BBoolean(true))).booleanValue())).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue())).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted)))))._not().booleanValue())).booleanValue() && shock_absorber.equal((PLANE_STATE(PLANE_STATE::flight))).booleanValue())).booleanValue() && doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue())).booleanValue() && general_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
        }

        bool _tr_con_stop_stimulate_retract_gear_valve() const {
            return ((BBoolean((BBoolean(retract_EV.equal((BBoolean(true))).booleanValue() && (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() || gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue())).booleanValue())).booleanValue() && general_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
        }

        bool _tr_con_stimulate_extend_gear_valve() const {
            return ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(extend_EV.equal((BBoolean(false))).booleanValue() && retract_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && open_EV.equal((BBoolean(true))).booleanValue())).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue())).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended)))))._not().booleanValue())).booleanValue() && doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue())).booleanValue() && general_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
        }

        bool _tr_con_stop_stimulate_extend_gear_valve() const {
            return ((BBoolean((BBoolean(extend_EV.equal((BBoolean(true))).booleanValue() && (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() || gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue() && general_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
        }

        BSet<POSITION> _tr_env_start_retracting_first() const {
            BSet<POSITION> _ic_set_18 = BSet<POSITION>();
            for(const POSITION& _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue())).booleanValue() && gears.functionCall(_ic_gr_1).equal((GEAR_STATE(GEAR_STATE::extended))).booleanValue())).booleanValue() && valve_retract_gear.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && (BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended)), (GEAR_STATE(GEAR_STATE::gear_moving)))).elementOf(gear).booleanValue())).booleanValue() && door.equal((DOOR_STATE(DOOR_STATE::open))).booleanValue()))).booleanValue()) {
                    _ic_set_18 = _ic_set_18._union(BSet<POSITION>(_ic_gr_1));
                }

            }

            return _ic_set_18;
        }

        BSet<POSITION> _tr_env_retract_gear_skip() const {
            BSet<POSITION> _ic_set_19 = BSet<POSITION>();
            for(const POSITION& _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean(doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue() && gears.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).unequal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue())).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue())).booleanValue() && gears.functionCall(_ic_gr_1).equal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue()))).booleanValue()) {
                    _ic_set_19 = _ic_set_19._union(BSet<POSITION>(_ic_gr_1));
                }

            }

            return _ic_set_19;
        }

        BSet<POSITION> _tr_env_retract_gear_last() const {
            BSet<POSITION> _ic_set_20 = BSet<POSITION>();
            for(const POSITION& _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue() && gears.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue())).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue())).booleanValue() && gears.functionCall(_ic_gr_1).equal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && door.equal((DOOR_STATE(DOOR_STATE::open))).booleanValue()))).booleanValue()) {
                    _ic_set_20 = _ic_set_20._union(BSet<POSITION>(_ic_gr_1));
                }

            }

            return _ic_set_20;
        }

        BSet<POSITION> _tr_env_start_extending() const {
            BSet<POSITION> _ic_set_21 = BSet<POSITION>();
            for(const POSITION& _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue())).booleanValue() && gears.functionCall(_ic_gr_1).equal((GEAR_STATE(GEAR_STATE::retracted))).booleanValue())).booleanValue() && valve_extend_gear.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && (BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::gear_moving)), (GEAR_STATE(GEAR_STATE::retracted)))).elementOf(gear).booleanValue())).booleanValue() && door.equal((DOOR_STATE(DOOR_STATE::open))).booleanValue()))).booleanValue()) {
                    _ic_set_21 = _ic_set_21._union(BSet<POSITION>(_ic_gr_1));
                }

            }

            return _ic_set_21;
        }

        BSet<POSITION> _tr_env_extend_gear_last() const {
            BSet<POSITION> _ic_set_22 = BSet<POSITION>();
            for(const POSITION& _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue())).booleanValue() && gears.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() && gears.functionCall(_ic_gr_1).equal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && door.equal((DOOR_STATE(DOOR_STATE::open))).booleanValue()))).booleanValue()) {
                    _ic_set_22 = _ic_set_22._union(BSet<POSITION>(_ic_gr_1));
                }

            }

            return _ic_set_22;
        }

        BSet<POSITION> _tr_env_extend_gear_skip() const {
            BSet<POSITION> _ic_set_23 = BSet<POSITION>();
            for(const POSITION& _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean(doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue())).booleanValue() && gears.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).unequal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() && gears.functionCall(_ic_gr_1).equal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue()))).booleanValue()) {
                    _ic_set_23 = _ic_set_23._union(BSet<POSITION>(_ic_gr_1));
                }

            }

            return _ic_set_23;
        }

        BSet<POSITION> _tr_env_start_open_door() const {
            BSet<POSITION> _ic_set_24 = BSet<POSITION>();
            for(const POSITION& _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.functionCall(_ic_gr_1).equal((DOOR_STATE(DOOR_STATE::closed))).booleanValue() && gears.functionCall(_ic_gr_1).unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (gears.isNotInRange((GEAR_STATE(GEAR_STATE::gear_moving)))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && valve_open_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && (BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed)), (DOOR_STATE(DOOR_STATE::door_moving)))).elementOf(door).booleanValue())).booleanValue() && gear.unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::retracted))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::extended))).booleanValue())).booleanValue())).booleanValue()))).booleanValue()) {
                    _ic_set_24 = _ic_set_24._union(BSet<POSITION>(_ic_gr_1));
                }

            }

            return _ic_set_24;
        }

        BSet<POSITION> _tr_env_open_door_last() const {
            BSet<POSITION> _ic_set_25 = BSet<POSITION>();
            for(const POSITION& _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.functionCall(_ic_gr_1).equal((DOOR_STATE(DOOR_STATE::door_moving))).booleanValue() && gears.functionCall(_ic_gr_1).unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (gears.isNotInRange((GEAR_STATE(GEAR_STATE::gear_moving)))).booleanValue())).booleanValue() && doors.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && valve_open_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && door.equal((DOOR_STATE(DOOR_STATE::door_moving))).booleanValue())).booleanValue() && gear.unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::retracted))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::extended))).booleanValue())).booleanValue())).booleanValue()))).booleanValue()) {
                    _ic_set_25 = _ic_set_25._union(BSet<POSITION>(_ic_gr_1));
                }

            }

            return _ic_set_25;
        }

        BSet<POSITION> _tr_env_open_door_skip() const {
            BSet<POSITION> _ic_set_26 = BSet<POSITION>();
            for(const POSITION& _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.functionCall(_ic_gr_1).equal((DOOR_STATE(DOOR_STATE::door_moving))).booleanValue() && gears.functionCall(_ic_gr_1).unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (gears.isNotInRange((GEAR_STATE(GEAR_STATE::gear_moving)))).booleanValue())).booleanValue() && doors.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).unequal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && valve_open_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue()))).booleanValue()) {
                    _ic_set_26 = _ic_set_26._union(BSet<POSITION>(_ic_gr_1));
                }

            }

            return _ic_set_26;
        }

        BSet<POSITION> _tr_env_start_close_door() const {
            BSet<POSITION> _ic_set_27 = BSet<POSITION>();
            for(const POSITION& _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.functionCall(_ic_gr_1).equal((DOOR_STATE(DOOR_STATE::open))).booleanValue() && gears.functionCall(_ic_gr_1).unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && (BBoolean(gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue() || gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && valve_close_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && (BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::door_moving)), (DOOR_STATE(DOOR_STATE::open)))).elementOf(door).booleanValue())).booleanValue() && gear.unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::extended))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && (BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended)), (GEAR_STATE(GEAR_STATE::retracted)))).elementOf(gear).booleanValue())).booleanValue())).booleanValue()))).booleanValue()) {
                    _ic_set_27 = _ic_set_27._union(BSet<POSITION>(_ic_gr_1));
                }

            }

            return _ic_set_27;
        }

        BSet<POSITION> _tr_env_close_door() const {
            BSet<POSITION> _ic_set_28 = BSet<POSITION>();
            for(const POSITION& _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.functionCall(_ic_gr_1).equal((DOOR_STATE(DOOR_STATE::door_moving))).booleanValue() && gears.functionCall(_ic_gr_1).unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (gears.isNotInRange((GEAR_STATE(GEAR_STATE::gear_moving)))).booleanValue())).booleanValue() && doors.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed))))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && (BBoolean(gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue() || gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && valve_close_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() || shock_absorber.equal((PLANE_STATE(PLANE_STATE::ground))).booleanValue())).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && door.equal((DOOR_STATE(DOOR_STATE::door_moving))).booleanValue())).booleanValue() && gear.unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::extended))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && (BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended)), (GEAR_STATE(GEAR_STATE::retracted)))).elementOf(gear).booleanValue())).booleanValue())).booleanValue()))).booleanValue()) {
                    _ic_set_28 = _ic_set_28._union(BSet<POSITION>(_ic_gr_1));
                }

            }

            return _ic_set_28;
        }

        BSet<POSITION> _tr_env_close_door_skip() const {
            BSet<POSITION> _ic_set_29 = BSet<POSITION>();
            for(const POSITION& _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.functionCall(_ic_gr_1).equal((DOOR_STATE(DOOR_STATE::door_moving))).booleanValue() && gears.functionCall(_ic_gr_1).unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (gears.isNotInRange((GEAR_STATE(GEAR_STATE::gear_moving)))).booleanValue())).booleanValue() && doors.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).unequal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed))))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && (BBoolean(gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue() || gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && valve_close_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() || shock_absorber.equal((PLANE_STATE(PLANE_STATE::ground))).booleanValue())).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue()))).booleanValue()) {
                    _ic_set_29 = _ic_set_29._union(BSet<POSITION>(_ic_gr_1));
                }

            }

            return _ic_set_29;
        }

        bool _tr_toggle_handle_up() const {
            return (handle.equal((HANDLE_STATE(HANDLE_STATE::down)))).booleanValue();
        }

        bool _tr_toggle_handle_down() const {
            return (handle.equal((HANDLE_STATE(HANDLE_STATE::up)))).booleanValue();
        }

        bool _tr_con_stimulate_general_valve() const {
            return ((BBoolean(general_EV.equal((BBoolean(false))).booleanValue() && handle_move.equal((BBoolean(true))).booleanValue()))).booleanValue();
        }

        bool _tr_con_stop_stimulate_general_valve() const {
            return ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(general_EV.equal((BBoolean(true))).booleanValue() && open_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && close_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && retract_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && extend_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && close_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && (BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue())).booleanValue() && doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed))))).booleanValue())).booleanValue() && open_EV.equal((BBoolean(false))).booleanValue())).booleanValue() || (BBoolean((BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() && doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed))))).booleanValue())).booleanValue() && open_EV.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() || (BBoolean((BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() && doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed))))).booleanValue())).booleanValue() && open_EV.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue()))).booleanValue();
        }

        bool _tr_evn_open_general_valve() const {
            return ((BBoolean((BBoolean(general_EV.equal((BBoolean(true))).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_closed))).booleanValue())).booleanValue() && analogical_switch.equal((SWITCH_STATE(SWITCH_STATE::switch_closed))).booleanValue()))).booleanValue();
        }

        bool _tr_evn_close_general_valve() const {
            return ((BBoolean((BBoolean(general_EV.equal((BBoolean(false))).booleanValue() || analogical_switch.equal((SWITCH_STATE(SWITCH_STATE::switch_open))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue()))).booleanValue();
        }

        bool _tr_env_close_analogical_switch() const {
            return ((BBoolean(analogical_switch.equal((SWITCH_STATE(SWITCH_STATE::switch_open))).booleanValue() && handle_move.equal((BBoolean(true))).booleanValue()))).booleanValue();
        }

        bool _tr_env_open_analogical_switch() const {
            return (analogical_switch.equal((SWITCH_STATE(SWITCH_STATE::switch_closed)))).booleanValue();
        }

        _ProjectionRead_close_valve_door_close _projected_state_for_close_valve_door_close() const {
            return _ProjectionRead_close_valve_door_close(valve_close_door,close_EV);
        }

        _ProjectionRead_close_valve_retract_gear _projected_state_for_close_valve_retract_gear() const {
            return _ProjectionRead_close_valve_retract_gear(valve_retract_gear,retract_EV);
        }

        _ProjectionRead_con_stimulate_open_door_valve _projected_state_for_con_stimulate_open_door_valve() const {
            return _ProjectionRead_con_stimulate_open_door_valve(handle,doors,open_EV,shock_absorber,close_EV,general_EV,gears);
        }

        _ProjectionRead_env_close_door _projected_state_for_env_close_door() const {
            return _ProjectionRead_env_close_door(door,valve_close_door,handle,doors,shock_absorber,general_valve,gears,gear);
        }

        _ProjectionRead_env_start_close_door _projected_state_for_env_start_close_door() const {
            return _ProjectionRead_env_start_close_door(door,valve_close_door,handle,doors,general_valve,gears,gear);
        }

        _ProjectionRead_toggle_handle_up _projected_state_for_toggle_handle_up() const {
            return _ProjectionRead_toggle_handle_up(handle);
        }

        _ProjectionRead_toggle_handle_down _projected_state_for_toggle_handle_down() const {
            return _ProjectionRead_toggle_handle_down(handle);
        }

        _ProjectionRead_open_valve_door_open _projected_state_for_open_valve_door_open() const {
            return _ProjectionRead_open_valve_door_open(valve_open_door,open_EV);
        }

        _ProjectionRead_env_retract_gear_last _projected_state_for_env_retract_gear_last() const {
            return _ProjectionRead_env_retract_gear_last(door,handle,doors,general_valve,gears,gear);
        }

        _ProjectionRead_env_open_door_last _projected_state_for_env_open_door_last() const {
            return _ProjectionRead_env_open_door_last(valve_open_door,door,handle,doors,general_valve,gears,gear);
        }

        _ProjectionRead_con_stop_stimulate_retract_gear_valve _projected_state_for_con_stop_stimulate_retract_gear_valve() const {
            return _ProjectionRead_con_stop_stimulate_retract_gear_valve(handle,general_EV,retract_EV,gears);
        }

        _ProjectionRead_env_close_door_skip _projected_state_for_env_close_door_skip() const {
            return _ProjectionRead_env_close_door_skip(valve_close_door,handle,doors,shock_absorber,general_valve,gears);
        }

        _ProjectionRead_con_stop_stimulate_close_door_valve _projected_state_for_con_stop_stimulate_close_door_valve() const {
            return _ProjectionRead_con_stop_stimulate_close_door_valve(doors,shock_absorber,handle,close_EV,general_EV,gears);
        }

        _ProjectionRead_env_open_analogical_switch _projected_state_for_env_open_analogical_switch() const {
            return _ProjectionRead_env_open_analogical_switch(analogical_switch);
        }

        _ProjectionRead_con_stop_stimulate_general_valve _projected_state_for_con_stop_stimulate_general_valve() const {
            return _ProjectionRead_con_stop_stimulate_general_valve(extend_EV,handle,doors,open_EV,close_EV,general_EV,retract_EV,gears);
        }

        _ProjectionRead_env_extend_gear_last _projected_state_for_env_extend_gear_last() const {
            return _ProjectionRead_env_extend_gear_last(door,handle,doors,general_valve,gears,gear);
        }

        _ProjectionRead_evn_open_general_valve _projected_state_for_evn_open_general_valve() const {
            return _ProjectionRead_evn_open_general_valve(general_valve,analogical_switch,general_EV);
        }

        _ProjectionRead_land_plane _projected_state_for_land_plane() const {
            return _ProjectionRead_land_plane(shock_absorber);
        }

        _ProjectionRead_con_stimulate_retract_gear_valve _projected_state_for_con_stimulate_retract_gear_valve() const {
            return _ProjectionRead_con_stimulate_retract_gear_valve(extend_EV,doors,open_EV,shock_absorber,handle,general_EV,retract_EV,gears);
        }

        _ProjectionRead_con_stimulate_general_valve _projected_state_for_con_stimulate_general_valve() const {
            return _ProjectionRead_con_stimulate_general_valve(handle_move,general_EV);
        }

        _ProjectionRead_env_start_retracting_first _projected_state_for_env_start_retracting_first() const {
            return _ProjectionRead_env_start_retracting_first(door,handle,valve_retract_gear,doors,general_valve,gears,gear);
        }

        _ProjectionRead_env_retract_gear_skip _projected_state_for_env_retract_gear_skip() const {
            return _ProjectionRead_env_retract_gear_skip(doors,general_valve,handle,gears);
        }

        _ProjectionRead_open_valve_extend_gear _projected_state_for_open_valve_extend_gear() const {
            return _ProjectionRead_open_valve_extend_gear(extend_EV,valve_extend_gear);
        }

        _ProjectionRead_begin_flying _projected_state_for_begin_flying() const {
            return _ProjectionRead_begin_flying(shock_absorber);
        }

        _ProjectionRead_open_valve_retract_gear _projected_state_for_open_valve_retract_gear() const {
            return _ProjectionRead_open_valve_retract_gear(valve_retract_gear,retract_EV);
        }

        _ProjectionRead_env_close_analogical_switch _projected_state_for_env_close_analogical_switch() const {
            return _ProjectionRead_env_close_analogical_switch(analogical_switch,handle_move);
        }

        _ProjectionRead_env_start_extending _projected_state_for_env_start_extending() const {
            return _ProjectionRead_env_start_extending(door,handle,doors,general_valve,valve_extend_gear,gears,gear);
        }

        _ProjectionRead_open_valve_door_close _projected_state_for_open_valve_door_close() const {
            return _ProjectionRead_open_valve_door_close(valve_close_door,close_EV);
        }

        _ProjectionRead_con_stop_stimulate_open_door_valve _projected_state_for_con_stop_stimulate_open_door_valve() const {
            return _ProjectionRead_con_stop_stimulate_open_door_valve(extend_EV,handle,doors,open_EV,shock_absorber,general_EV,retract_EV,gears);
        }

        _ProjectionRead_con_stop_stimulate_extend_gear_valve _projected_state_for_con_stop_stimulate_extend_gear_valve() const {
            return _ProjectionRead_con_stop_stimulate_extend_gear_valve(extend_EV,handle,general_EV,gears);
        }

        _ProjectionRead_evn_close_general_valve _projected_state_for_evn_close_general_valve() const {
            return _ProjectionRead_evn_close_general_valve(general_valve,analogical_switch,general_EV);
        }

        _ProjectionRead_close_valve_extend_gear _projected_state_for_close_valve_extend_gear() const {
            return _ProjectionRead_close_valve_extend_gear(extend_EV,valve_extend_gear);
        }

        _ProjectionRead_con_stimulate_extend_gear_valve _projected_state_for_con_stimulate_extend_gear_valve() const {
            return _ProjectionRead_con_stimulate_extend_gear_valve(extend_EV,doors,open_EV,handle,general_EV,retract_EV,gears);
        }

        _ProjectionRead_close_valve_door_open _projected_state_for_close_valve_door_open() const {
            return _ProjectionRead_close_valve_door_open(valve_open_door,open_EV);
        }

        _ProjectionRead_con_stimulate_close_door_valve _projected_state_for_con_stimulate_close_door_valve() const {
            return _ProjectionRead_con_stimulate_close_door_valve(extend_EV,handle,doors,open_EV,shock_absorber,close_EV,general_EV,retract_EV,gears);
        }

        _ProjectionRead_env_extend_gear_skip _projected_state_for_env_extend_gear_skip() const {
            return _ProjectionRead_env_extend_gear_skip(doors,general_valve,handle,gears);
        }

        _ProjectionRead_env_open_door_skip _projected_state_for_env_open_door_skip() const {
            return _ProjectionRead_env_open_door_skip(valve_open_door,handle,doors,general_valve,gears);
        }

        _ProjectionRead_env_start_open_door _projected_state_for_env_start_open_door() const {
            return _ProjectionRead_env_start_open_door(valve_open_door,door,handle,doors,general_valve,gears,gear);
        }

        _ProjectionRead__tr_env_retract_gear_last _projected_state_for__tr_env_retract_gear_last() const {
            return _ProjectionRead__tr_env_retract_gear_last(door,handle,doors,general_valve,gears,gear);
        }

        _ProjectionRead__tr_open_valve_door_open _projected_state_for__tr_open_valve_door_open() const {
            return _ProjectionRead__tr_open_valve_door_open(valve_open_door,open_EV);
        }

        _ProjectionRead__tr_env_open_analogical_switch _projected_state_for__tr_env_open_analogical_switch() const {
            return _ProjectionRead__tr_env_open_analogical_switch(analogical_switch);
        }

        _ProjectionRead__tr_con_stimulate_extend_gear_valve _projected_state_for__tr_con_stimulate_extend_gear_valve() const {
            return _ProjectionRead__tr_con_stimulate_extend_gear_valve(extend_EV,doors,open_EV,handle,general_EV,retract_EV,gears);
        }

        _ProjectionRead__tr_env_close_door_skip _projected_state_for__tr_env_close_door_skip() const {
            return _ProjectionRead__tr_env_close_door_skip(valve_close_door,handle,doors,shock_absorber,general_valve,gears);
        }

        _ProjectionRead__tr_con_stop_stimulate_open_door_valve _projected_state_for__tr_con_stop_stimulate_open_door_valve() const {
            return _ProjectionRead__tr_con_stop_stimulate_open_door_valve(extend_EV,handle,doors,open_EV,shock_absorber,general_EV,retract_EV,gears);
        }

        _ProjectionRead__tr_con_stimulate_close_door_valve _projected_state_for__tr_con_stimulate_close_door_valve() const {
            return _ProjectionRead__tr_con_stimulate_close_door_valve(extend_EV,handle,doors,open_EV,shock_absorber,close_EV,general_EV,retract_EV,gears);
        }

        _ProjectionRead__tr_env_close_analogical_switch _projected_state_for__tr_env_close_analogical_switch() const {
            return _ProjectionRead__tr_env_close_analogical_switch(analogical_switch,handle_move);
        }

        _ProjectionRead__tr_evn_close_general_valve _projected_state_for__tr_evn_close_general_valve() const {
            return _ProjectionRead__tr_evn_close_general_valve(general_valve,analogical_switch,general_EV);
        }

        _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve _projected_state_for__tr_con_stop_stimulate_retract_gear_valve() const {
            return _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve(handle,general_EV,retract_EV,gears);
        }

        _ProjectionRead__tr_land_plane _projected_state_for__tr_land_plane() const {
            return _ProjectionRead__tr_land_plane(shock_absorber);
        }

        _ProjectionRead__tr_open_valve_door_close _projected_state_for__tr_open_valve_door_close() const {
            return _ProjectionRead__tr_open_valve_door_close(valve_close_door,close_EV);
        }

        _ProjectionRead__tr_con_stop_stimulate_general_valve _projected_state_for__tr_con_stop_stimulate_general_valve() const {
            return _ProjectionRead__tr_con_stop_stimulate_general_valve(extend_EV,handle,doors,open_EV,close_EV,general_EV,retract_EV,gears);
        }

        _ProjectionRead__tr_con_stimulate_open_door_valve _projected_state_for__tr_con_stimulate_open_door_valve() const {
            return _ProjectionRead__tr_con_stimulate_open_door_valve(handle,doors,open_EV,shock_absorber,close_EV,general_EV,gears);
        }

        _ProjectionRead__tr_env_start_extending _projected_state_for__tr_env_start_extending() const {
            return _ProjectionRead__tr_env_start_extending(door,handle,doors,general_valve,valve_extend_gear,gears,gear);
        }

        _ProjectionRead__tr_env_extend_gear_last _projected_state_for__tr_env_extend_gear_last() const {
            return _ProjectionRead__tr_env_extend_gear_last(door,handle,doors,general_valve,gears,gear);
        }

        _ProjectionRead__tr_env_open_door_skip _projected_state_for__tr_env_open_door_skip() const {
            return _ProjectionRead__tr_env_open_door_skip(valve_open_door,handle,doors,general_valve,gears);
        }

        _ProjectionRead__tr_close_valve_retract_gear _projected_state_for__tr_close_valve_retract_gear() const {
            return _ProjectionRead__tr_close_valve_retract_gear(valve_retract_gear,retract_EV);
        }

        _ProjectionRead__tr_close_valve_extend_gear _projected_state_for__tr_close_valve_extend_gear() const {
            return _ProjectionRead__tr_close_valve_extend_gear(extend_EV,valve_extend_gear);
        }

        _ProjectionRead__tr_con_stimulate_general_valve _projected_state_for__tr_con_stimulate_general_valve() const {
            return _ProjectionRead__tr_con_stimulate_general_valve(handle_move,general_EV);
        }

        _ProjectionRead__tr_open_valve_extend_gear _projected_state_for__tr_open_valve_extend_gear() const {
            return _ProjectionRead__tr_open_valve_extend_gear(extend_EV,valve_extend_gear);
        }

        _ProjectionRead__tr_con_stimulate_retract_gear_valve _projected_state_for__tr_con_stimulate_retract_gear_valve() const {
            return _ProjectionRead__tr_con_stimulate_retract_gear_valve(extend_EV,doors,open_EV,shock_absorber,handle,general_EV,retract_EV,gears);
        }

        _ProjectionRead__tr_evn_open_general_valve _projected_state_for__tr_evn_open_general_valve() const {
            return _ProjectionRead__tr_evn_open_general_valve(general_valve,analogical_switch,general_EV);
        }

        _ProjectionRead__tr_env_retract_gear_skip _projected_state_for__tr_env_retract_gear_skip() const {
            return _ProjectionRead__tr_env_retract_gear_skip(doors,general_valve,handle,gears);
        }

        _ProjectionRead__tr_env_start_open_door _projected_state_for__tr_env_start_open_door() const {
            return _ProjectionRead__tr_env_start_open_door(valve_open_door,door,handle,doors,general_valve,gears,gear);
        }

        _ProjectionRead__tr_env_close_door _projected_state_for__tr_env_close_door() const {
            return _ProjectionRead__tr_env_close_door(door,valve_close_door,handle,doors,shock_absorber,general_valve,gears,gear);
        }

        _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve _projected_state_for__tr_con_stop_stimulate_extend_gear_valve() const {
            return _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve(extend_EV,handle,general_EV,gears);
        }

        _ProjectionRead__tr_close_valve_door_open _projected_state_for__tr_close_valve_door_open() const {
            return _ProjectionRead__tr_close_valve_door_open(valve_open_door,open_EV);
        }

        _ProjectionRead__tr_env_start_retracting_first _projected_state_for__tr_env_start_retracting_first() const {
            return _ProjectionRead__tr_env_start_retracting_first(door,handle,valve_retract_gear,doors,general_valve,gears,gear);
        }

        _ProjectionRead__tr_env_extend_gear_skip _projected_state_for__tr_env_extend_gear_skip() const {
            return _ProjectionRead__tr_env_extend_gear_skip(doors,general_valve,handle,gears);
        }

        _ProjectionRead__tr_toggle_handle_down _projected_state_for__tr_toggle_handle_down() const {
            return _ProjectionRead__tr_toggle_handle_down(handle);
        }

        _ProjectionRead__tr_begin_flying _projected_state_for__tr_begin_flying() const {
            return _ProjectionRead__tr_begin_flying(shock_absorber);
        }

        _ProjectionRead__tr_open_valve_retract_gear _projected_state_for__tr_open_valve_retract_gear() const {
            return _ProjectionRead__tr_open_valve_retract_gear(valve_retract_gear,retract_EV);
        }

        _ProjectionRead__tr_env_open_door_last _projected_state_for__tr_env_open_door_last() const {
            return _ProjectionRead__tr_env_open_door_last(valve_open_door,door,handle,doors,general_valve,gears,gear);
        }

        _ProjectionRead__tr_toggle_handle_up _projected_state_for__tr_toggle_handle_up() const {
            return _ProjectionRead__tr_toggle_handle_up(handle);
        }

        _ProjectionRead__tr_env_start_close_door _projected_state_for__tr_env_start_close_door() const {
            return _ProjectionRead__tr_env_start_close_door(door,valve_close_door,handle,doors,general_valve,gears,gear);
        }

        _ProjectionRead__tr_con_stop_stimulate_close_door_valve _projected_state_for__tr_con_stop_stimulate_close_door_valve() const {
            return _ProjectionRead__tr_con_stop_stimulate_close_door_valve(doors,shock_absorber,handle,close_EV,general_EV,gears);
        }

        _ProjectionRead__tr_close_valve_door_close _projected_state_for__tr_close_valve_door_close() const {
            return _ProjectionRead__tr_close_valve_door_close(valve_close_door,close_EV);
        }

        _ProjectionRead__check_inv_18 _projected_state_for__check_inv_18() const {
            return _ProjectionRead__check_inv_18(open_EV,close_EV);
        }

        _ProjectionRead__check_inv_17 _projected_state_for__check_inv_17() const {
            return _ProjectionRead__check_inv_17(extend_EV,open_EV,close_EV,general_EV,retract_EV);
        }

        _ProjectionRead__check_inv_16 _projected_state_for__check_inv_16() const {
            return _ProjectionRead__check_inv_16(gear);
        }

        _ProjectionRead__check_inv_15 _projected_state_for__check_inv_15() const {
            return _ProjectionRead__check_inv_15(door);
        }

        _ProjectionRead__check_inv_19 _projected_state_for__check_inv_19() const {
            return _ProjectionRead__check_inv_19(gears);
        }

        _ProjectionRead__check_inv_10 _projected_state_for__check_inv_10() const {
            return _ProjectionRead__check_inv_10(valve_close_door);
        }

        _ProjectionRead__check_inv_14 _projected_state_for__check_inv_14() const {
            return _ProjectionRead__check_inv_14(handle);
        }

        _ProjectionRead__check_inv_13 _projected_state_for__check_inv_13() const {
            return _ProjectionRead__check_inv_13(valve_retract_gear);
        }

        _ProjectionRead__check_inv_12 _projected_state_for__check_inv_12() const {
            return _ProjectionRead__check_inv_12(valve_open_door);
        }

        _ProjectionRead__check_inv_11 _projected_state_for__check_inv_11() const {
            return _ProjectionRead__check_inv_11(valve_extend_gear);
        }

        _ProjectionRead__check_inv_6 _projected_state_for__check_inv_6() const {
            return _ProjectionRead__check_inv_6(extend_EV);
        }

        _ProjectionRead__check_inv_21 _projected_state_for__check_inv_21() const {
            return _ProjectionRead__check_inv_21(doors,door);
        }

        _ProjectionRead__check_inv_7 _projected_state_for__check_inv_7() const {
            return _ProjectionRead__check_inv_7(open_EV);
        }

        _ProjectionRead__check_inv_20 _projected_state_for__check_inv_20() const {
            return _ProjectionRead__check_inv_20(doors);
        }

        _ProjectionRead__check_inv_4 _projected_state_for__check_inv_4() const {
            return _ProjectionRead__check_inv_4(handle_move);
        }

        _ProjectionRead__check_inv_5 _projected_state_for__check_inv_5() const {
            return _ProjectionRead__check_inv_5(close_EV);
        }

        _ProjectionRead__check_inv_25 _projected_state_for__check_inv_25() const {
            return _ProjectionRead__check_inv_25(door,gear);
        }

        _ProjectionRead__check_inv_24 _projected_state_for__check_inv_24() const {
            return _ProjectionRead__check_inv_24(gears,gear);
        }

        _ProjectionRead__check_inv_8 _projected_state_for__check_inv_8() const {
            return _ProjectionRead__check_inv_8(retract_EV);
        }

        _ProjectionRead__check_inv_23 _projected_state_for__check_inv_23() const {
            return _ProjectionRead__check_inv_23(gears,gear);
        }

        _ProjectionRead__check_inv_9 _projected_state_for__check_inv_9() const {
            return _ProjectionRead__check_inv_9(shock_absorber);
        }

        _ProjectionRead__check_inv_22 _projected_state_for__check_inv_22() const {
            return _ProjectionRead__check_inv_22(doors,door);
        }

        _ProjectionRead__check_inv_2 _projected_state_for__check_inv_2() const {
            return _ProjectionRead__check_inv_2(general_EV);
        }

        _ProjectionRead__check_inv_3 _projected_state_for__check_inv_3() const {
            return _ProjectionRead__check_inv_3(general_valve);
        }

        _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() const {
            return _ProjectionRead__check_inv_1(analogical_switch);
        }

        _ProjectionWrite_close_valve_door_close _update_for_close_valve_door_close() const {
            return _ProjectionWrite_close_valve_door_close(valve_close_door);
        }

        _ProjectionWrite_close_valve_retract_gear _update_for_close_valve_retract_gear() const {
            return _ProjectionWrite_close_valve_retract_gear(valve_retract_gear);
        }

        _ProjectionWrite_con_stimulate_open_door_valve _update_for_con_stimulate_open_door_valve() const {
            return _ProjectionWrite_con_stimulate_open_door_valve(open_EV);
        }

        _ProjectionWrite_env_close_door _update_for_env_close_door() const {
            return _ProjectionWrite_env_close_door(doors,door);
        }

        _ProjectionWrite_env_start_close_door _update_for_env_start_close_door() const {
            return _ProjectionWrite_env_start_close_door(doors,door);
        }

        _ProjectionWrite_toggle_handle_up _update_for_toggle_handle_up() const {
            return _ProjectionWrite_toggle_handle_up(handle,handle_move);
        }

        _ProjectionWrite_toggle_handle_down _update_for_toggle_handle_down() const {
            return _ProjectionWrite_toggle_handle_down(handle,handle_move);
        }

        _ProjectionWrite_open_valve_door_open _update_for_open_valve_door_open() const {
            return _ProjectionWrite_open_valve_door_open(valve_open_door);
        }

        _ProjectionWrite_env_retract_gear_last _update_for_env_retract_gear_last() const {
            return _ProjectionWrite_env_retract_gear_last(gears,gear);
        }

        _ProjectionWrite_env_open_door_last _update_for_env_open_door_last() const {
            return _ProjectionWrite_env_open_door_last(doors,door);
        }

        _ProjectionWrite_con_stop_stimulate_retract_gear_valve _update_for_con_stop_stimulate_retract_gear_valve() const {
            return _ProjectionWrite_con_stop_stimulate_retract_gear_valve(retract_EV);
        }

        _ProjectionWrite_env_close_door_skip _update_for_env_close_door_skip() const {
            return _ProjectionWrite_env_close_door_skip(doors);
        }

        _ProjectionWrite_con_stop_stimulate_close_door_valve _update_for_con_stop_stimulate_close_door_valve() const {
            return _ProjectionWrite_con_stop_stimulate_close_door_valve(close_EV);
        }

        _ProjectionWrite_env_open_analogical_switch _update_for_env_open_analogical_switch() const {
            return _ProjectionWrite_env_open_analogical_switch(analogical_switch);
        }

        _ProjectionWrite_con_stop_stimulate_general_valve _update_for_con_stop_stimulate_general_valve() const {
            return _ProjectionWrite_con_stop_stimulate_general_valve(handle_move,general_EV);
        }

        _ProjectionWrite_env_extend_gear_last _update_for_env_extend_gear_last() const {
            return _ProjectionWrite_env_extend_gear_last(gears,gear);
        }

        _ProjectionWrite_evn_open_general_valve _update_for_evn_open_general_valve() const {
            return _ProjectionWrite_evn_open_general_valve(general_valve);
        }

        _ProjectionWrite_land_plane _update_for_land_plane() const {
            return _ProjectionWrite_land_plane(shock_absorber);
        }

        _ProjectionWrite_con_stimulate_retract_gear_valve _update_for_con_stimulate_retract_gear_valve() const {
            return _ProjectionWrite_con_stimulate_retract_gear_valve(retract_EV);
        }

        _ProjectionWrite_con_stimulate_general_valve _update_for_con_stimulate_general_valve() const {
            return _ProjectionWrite_con_stimulate_general_valve(general_EV);
        }

        _ProjectionWrite_env_start_retracting_first _update_for_env_start_retracting_first() const {
            return _ProjectionWrite_env_start_retracting_first(gears,gear);
        }

        _ProjectionWrite_env_retract_gear_skip _update_for_env_retract_gear_skip() const {
            return _ProjectionWrite_env_retract_gear_skip(gears);
        }

        _ProjectionWrite_open_valve_extend_gear _update_for_open_valve_extend_gear() const {
            return _ProjectionWrite_open_valve_extend_gear(valve_extend_gear);
        }

        _ProjectionWrite_begin_flying _update_for_begin_flying() const {
            return _ProjectionWrite_begin_flying(shock_absorber);
        }

        _ProjectionWrite_open_valve_retract_gear _update_for_open_valve_retract_gear() const {
            return _ProjectionWrite_open_valve_retract_gear(valve_retract_gear);
        }

        _ProjectionWrite_env_close_analogical_switch _update_for_env_close_analogical_switch() const {
            return _ProjectionWrite_env_close_analogical_switch(analogical_switch);
        }

        _ProjectionWrite_env_start_extending _update_for_env_start_extending() const {
            return _ProjectionWrite_env_start_extending(gears,gear);
        }

        _ProjectionWrite_open_valve_door_close _update_for_open_valve_door_close() const {
            return _ProjectionWrite_open_valve_door_close(valve_close_door);
        }

        _ProjectionWrite_con_stop_stimulate_open_door_valve _update_for_con_stop_stimulate_open_door_valve() const {
            return _ProjectionWrite_con_stop_stimulate_open_door_valve(open_EV);
        }

        _ProjectionWrite_con_stop_stimulate_extend_gear_valve _update_for_con_stop_stimulate_extend_gear_valve() const {
            return _ProjectionWrite_con_stop_stimulate_extend_gear_valve(extend_EV);
        }

        _ProjectionWrite_evn_close_general_valve _update_for_evn_close_general_valve() const {
            return _ProjectionWrite_evn_close_general_valve(general_valve);
        }

        _ProjectionWrite_close_valve_extend_gear _update_for_close_valve_extend_gear() const {
            return _ProjectionWrite_close_valve_extend_gear(valve_extend_gear);
        }

        _ProjectionWrite_con_stimulate_extend_gear_valve _update_for_con_stimulate_extend_gear_valve() const {
            return _ProjectionWrite_con_stimulate_extend_gear_valve(extend_EV);
        }

        _ProjectionWrite_close_valve_door_open _update_for_close_valve_door_open() const {
            return _ProjectionWrite_close_valve_door_open(valve_open_door);
        }

        _ProjectionWrite_con_stimulate_close_door_valve _update_for_con_stimulate_close_door_valve() const {
            return _ProjectionWrite_con_stimulate_close_door_valve(close_EV);
        }

        _ProjectionWrite_env_extend_gear_skip _update_for_env_extend_gear_skip() const {
            return _ProjectionWrite_env_extend_gear_skip(gears);
        }

        _ProjectionWrite_env_open_door_skip _update_for_env_open_door_skip() const {
            return _ProjectionWrite_env_open_door_skip(doors);
        }

        _ProjectionWrite_env_start_open_door _update_for_env_start_open_door() const {
            return _ProjectionWrite_env_start_open_door(doors,door);
        }

        void _apply_update_for_close_valve_door_close(const _ProjectionWrite_close_valve_door_close& update) {
            this->valve_close_door = update.valve_close_door;
        }

        void _apply_update_for_close_valve_retract_gear(const _ProjectionWrite_close_valve_retract_gear& update) {
            this->valve_retract_gear = update.valve_retract_gear;
        }

        void _apply_update_for_con_stimulate_open_door_valve(const _ProjectionWrite_con_stimulate_open_door_valve& update) {
            this->open_EV = update.open_EV;
        }

        void _apply_update_for_env_close_door(const _ProjectionWrite_env_close_door& update) {
            this->doors = update.doors;
            this->door = update.door;
        }

        void _apply_update_for_env_start_close_door(const _ProjectionWrite_env_start_close_door& update) {
            this->doors = update.doors;
            this->door = update.door;
        }

        void _apply_update_for_toggle_handle_up(const _ProjectionWrite_toggle_handle_up& update) {
            this->handle = update.handle;
            this->handle_move = update.handle_move;
        }

        void _apply_update_for_toggle_handle_down(const _ProjectionWrite_toggle_handle_down& update) {
            this->handle = update.handle;
            this->handle_move = update.handle_move;
        }

        void _apply_update_for_open_valve_door_open(const _ProjectionWrite_open_valve_door_open& update) {
            this->valve_open_door = update.valve_open_door;
        }

        void _apply_update_for_env_retract_gear_last(const _ProjectionWrite_env_retract_gear_last& update) {
            this->gears = update.gears;
            this->gear = update.gear;
        }

        void _apply_update_for_env_open_door_last(const _ProjectionWrite_env_open_door_last& update) {
            this->doors = update.doors;
            this->door = update.door;
        }

        void _apply_update_for_con_stop_stimulate_retract_gear_valve(const _ProjectionWrite_con_stop_stimulate_retract_gear_valve& update) {
            this->retract_EV = update.retract_EV;
        }

        void _apply_update_for_env_close_door_skip(const _ProjectionWrite_env_close_door_skip& update) {
            this->doors = update.doors;
        }

        void _apply_update_for_con_stop_stimulate_close_door_valve(const _ProjectionWrite_con_stop_stimulate_close_door_valve& update) {
            this->close_EV = update.close_EV;
        }

        void _apply_update_for_env_open_analogical_switch(const _ProjectionWrite_env_open_analogical_switch& update) {
            this->analogical_switch = update.analogical_switch;
        }

        void _apply_update_for_con_stop_stimulate_general_valve(const _ProjectionWrite_con_stop_stimulate_general_valve& update) {
            this->handle_move = update.handle_move;
            this->general_EV = update.general_EV;
        }

        void _apply_update_for_env_extend_gear_last(const _ProjectionWrite_env_extend_gear_last& update) {
            this->gears = update.gears;
            this->gear = update.gear;
        }

        void _apply_update_for_evn_open_general_valve(const _ProjectionWrite_evn_open_general_valve& update) {
            this->general_valve = update.general_valve;
        }

        void _apply_update_for_land_plane(const _ProjectionWrite_land_plane& update) {
            this->shock_absorber = update.shock_absorber;
        }

        void _apply_update_for_con_stimulate_retract_gear_valve(const _ProjectionWrite_con_stimulate_retract_gear_valve& update) {
            this->retract_EV = update.retract_EV;
        }

        void _apply_update_for_con_stimulate_general_valve(const _ProjectionWrite_con_stimulate_general_valve& update) {
            this->general_EV = update.general_EV;
        }

        void _apply_update_for_env_start_retracting_first(const _ProjectionWrite_env_start_retracting_first& update) {
            this->gears = update.gears;
            this->gear = update.gear;
        }

        void _apply_update_for_env_retract_gear_skip(const _ProjectionWrite_env_retract_gear_skip& update) {
            this->gears = update.gears;
        }

        void _apply_update_for_open_valve_extend_gear(const _ProjectionWrite_open_valve_extend_gear& update) {
            this->valve_extend_gear = update.valve_extend_gear;
        }

        void _apply_update_for_begin_flying(const _ProjectionWrite_begin_flying& update) {
            this->shock_absorber = update.shock_absorber;
        }

        void _apply_update_for_open_valve_retract_gear(const _ProjectionWrite_open_valve_retract_gear& update) {
            this->valve_retract_gear = update.valve_retract_gear;
        }

        void _apply_update_for_env_close_analogical_switch(const _ProjectionWrite_env_close_analogical_switch& update) {
            this->analogical_switch = update.analogical_switch;
        }

        void _apply_update_for_env_start_extending(const _ProjectionWrite_env_start_extending& update) {
            this->gears = update.gears;
            this->gear = update.gear;
        }

        void _apply_update_for_open_valve_door_close(const _ProjectionWrite_open_valve_door_close& update) {
            this->valve_close_door = update.valve_close_door;
        }

        void _apply_update_for_con_stop_stimulate_open_door_valve(const _ProjectionWrite_con_stop_stimulate_open_door_valve& update) {
            this->open_EV = update.open_EV;
        }

        void _apply_update_for_con_stop_stimulate_extend_gear_valve(const _ProjectionWrite_con_stop_stimulate_extend_gear_valve& update) {
            this->extend_EV = update.extend_EV;
        }

        void _apply_update_for_evn_close_general_valve(const _ProjectionWrite_evn_close_general_valve& update) {
            this->general_valve = update.general_valve;
        }

        void _apply_update_for_close_valve_extend_gear(const _ProjectionWrite_close_valve_extend_gear& update) {
            this->valve_extend_gear = update.valve_extend_gear;
        }

        void _apply_update_for_con_stimulate_extend_gear_valve(const _ProjectionWrite_con_stimulate_extend_gear_valve& update) {
            this->extend_EV = update.extend_EV;
        }

        void _apply_update_for_close_valve_door_open(const _ProjectionWrite_close_valve_door_open& update) {
            this->valve_open_door = update.valve_open_door;
        }

        void _apply_update_for_con_stimulate_close_door_valve(const _ProjectionWrite_con_stimulate_close_door_valve& update) {
            this->close_EV = update.close_EV;
        }

        void _apply_update_for_env_extend_gear_skip(const _ProjectionWrite_env_extend_gear_skip& update) {
            this->gears = update.gears;
        }

        void _apply_update_for_env_open_door_skip(const _ProjectionWrite_env_open_door_skip& update) {
            this->doors = update.doors;
        }

        void _apply_update_for_env_start_open_door(const _ProjectionWrite_env_start_open_door& update) {
            this->doors = update.doors;
            this->door = update.door;
        }

        bool _check_inv_1() const {
            return (_SWITCH_STATE.elementOf(analogical_switch)).booleanValue();
        }

        bool _check_inv_2() const {
            return ((general_EV.isBoolean())).booleanValue();
        }

        bool _check_inv_3() const {
            return (_VALVE_STATE.elementOf(general_valve)).booleanValue();
        }

        bool _check_inv_4() const {
            return ((handle_move.isBoolean())).booleanValue();
        }

        bool _check_inv_5() const {
            return ((close_EV.isBoolean())).booleanValue();
        }

        bool _check_inv_6() const {
            return ((extend_EV.isBoolean())).booleanValue();
        }

        bool _check_inv_7() const {
            return ((open_EV.isBoolean())).booleanValue();
        }

        bool _check_inv_8() const {
            return ((retract_EV.isBoolean())).booleanValue();
        }

        bool _check_inv_9() const {
            return (_PLANE_STATE.elementOf(shock_absorber)).booleanValue();
        }

        bool _check_inv_10() const {
            return (_VALVE_STATE.elementOf(valve_close_door)).booleanValue();
        }

        bool _check_inv_11() const {
            return (_VALVE_STATE.elementOf(valve_extend_gear)).booleanValue();
        }

        bool _check_inv_12() const {
            return (_VALVE_STATE.elementOf(valve_open_door)).booleanValue();
        }

        bool _check_inv_13() const {
            return (_VALVE_STATE.elementOf(valve_retract_gear)).booleanValue();
        }

        bool _check_inv_14() const {
            return (_HANDLE_STATE.elementOf(handle)).booleanValue();
        }

        bool _check_inv_15() const {
            return (_DOOR_STATE.elementOf(door)).booleanValue();
        }

        bool _check_inv_16() const {
            return (_GEAR_STATE.elementOf(gear)).booleanValue();
        }

        bool _check_inv_17() const {
            return ((BBoolean(!(BBoolean((BBoolean((BBoolean(open_EV.equal((BBoolean(true))).booleanValue() || close_EV.equal((BBoolean(true))).booleanValue())).booleanValue() || retract_EV.equal((BBoolean(true))).booleanValue())).booleanValue() || extend_EV.equal((BBoolean(true))).booleanValue())).booleanValue() || general_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
        }

        bool _check_inv_18() const {
            return ((BBoolean(open_EV.equal((BBoolean(true))).booleanValue() && close_EV.equal((BBoolean(true))).booleanValue()))._not()).booleanValue();
        }

        bool _check_inv_19() const {
            return (((gears.checkDomain(_POSITION))._and((gears.checkRange(_GEAR_STATE)))._and((gears.isFunction()))._and((gears.isTotal(_POSITION))))).booleanValue();
        }

        bool _check_inv_20() const {
            return (((doors.checkDomain(_POSITION))._and((doors.checkRange(_DOOR_STATE)))._and((doors.isFunction()))._and((doors.isTotal(_POSITION))))).booleanValue();
        }

        bool _check_inv_21() const {
            return ((BBoolean((!door.equal((DOOR_STATE(DOOR_STATE::closed))).booleanValue() || doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed))))).booleanValue()) && (!doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed))))).booleanValue() || door.equal((DOOR_STATE(DOOR_STATE::closed))).booleanValue())))).booleanValue();
        }

        bool _check_inv_22() const {
            return ((BBoolean((!door.equal((DOOR_STATE(DOOR_STATE::open))).booleanValue() || doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue()) && (!doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue() || door.equal((DOOR_STATE(DOOR_STATE::open))).booleanValue())))).booleanValue();
        }

        bool _check_inv_23() const {
            return ((BBoolean((!gear.equal((GEAR_STATE(GEAR_STATE::extended))).booleanValue() || gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue()) && (!gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue() || gear.equal((GEAR_STATE(GEAR_STATE::extended))).booleanValue())))).booleanValue();
        }

        bool _check_inv_24() const {
            return ((BBoolean((!gear.equal((GEAR_STATE(GEAR_STATE::retracted))).booleanValue() || gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue()) && (!gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue() || gear.equal((GEAR_STATE(GEAR_STATE::retracted))).booleanValue())))).booleanValue();
        }

        bool _check_inv_25() const {
            return ((BBoolean(!gear.equal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue() || door.equal((DOOR_STATE(DOOR_STATE::open))).booleanValue()))).booleanValue();
        }

        LandingGear_R6 _copy() const {
            return LandingGear_R6(*this);
        }

        friend bool operator ==(const LandingGear_R6& o1, const LandingGear_R6& o2) {
            return o1._get_analogical_switch() == o2._get_analogical_switch() && o1._get_general_EV() == o2._get_general_EV() && o1._get_general_valve() == o2._get_general_valve() && o1._get_handle_move() == o2._get_handle_move() && o1._get_close_EV() == o2._get_close_EV() && o1._get_extend_EV() == o2._get_extend_EV() && o1._get_open_EV() == o2._get_open_EV() && o1._get_retract_EV() == o2._get_retract_EV() && o1._get_shock_absorber() == o2._get_shock_absorber() && o1._get_valve_close_door() == o2._get_valve_close_door() && o1._get_valve_extend_gear() == o2._get_valve_extend_gear() && o1._get_valve_open_door() == o2._get_valve_open_door() && o1._get_valve_retract_gear() == o2._get_valve_retract_gear() && o1._get_doors() == o2._get_doors() && o1._get_gears() == o2._get_gears() && o1._get_handle() == o2._get_handle() && o1._get_door() == o2._get_door() && o1._get_gear() == o2._get_gear();
        }

        friend bool operator !=(const LandingGear_R6& o1, const LandingGear_R6& o2) {
            return o1._get_analogical_switch() != o2._get_analogical_switch() || o1._get_general_EV() != o2._get_general_EV() || o1._get_general_valve() != o2._get_general_valve() || o1._get_handle_move() != o2._get_handle_move() || o1._get_close_EV() != o2._get_close_EV() || o1._get_extend_EV() != o2._get_extend_EV() || o1._get_open_EV() != o2._get_open_EV() || o1._get_retract_EV() != o2._get_retract_EV() || o1._get_shock_absorber() != o2._get_shock_absorber() || o1._get_valve_close_door() != o2._get_valve_close_door() || o1._get_valve_extend_gear() != o2._get_valve_extend_gear() || o1._get_valve_open_door() != o2._get_valve_open_door() || o1._get_valve_retract_gear() != o2._get_valve_retract_gear() || o1._get_doors() != o2._get_doors() || o1._get_gears() != o2._get_gears() || o1._get_handle() != o2._get_handle() || o1._get_door() != o2._get_door() || o1._get_gear() != o2._get_gear();
        }

        int hashCode() const {
            return this->_hashCode_1();
        }

        int _hashCode_1() const {
            int result = 1;
            result = (1543 * result) ^ ((this->_get_analogical_switch()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_general_EV()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_general_valve()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_handle_move()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_close_EV()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_extend_EV()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_open_EV()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_retract_EV()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_shock_absorber()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_valve_close_door()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_valve_extend_gear()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_valve_open_door()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_valve_retract_gear()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_doors()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_gears()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_handle()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_door()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_gear()).hashCode() << 1);
            return result;
        }

        int _hashCode_2() const {
            int result = 1;
            result = (6151 * result) ^ ((this->_get_analogical_switch()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_general_EV()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_general_valve()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_handle_move()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_close_EV()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_extend_EV()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_open_EV()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_retract_EV()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_shock_absorber()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_valve_close_door()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_valve_extend_gear()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_valve_open_door()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_valve_retract_gear()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_doors()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_gears()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_handle()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_door()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_gear()).hashCode() << 1);
            return result;
        }

        friend std::ostream& operator<<(std::ostream &strm, const LandingGear_R6 &machine) {
          strm << "_get_analogical_switch: " << machine._get_analogical_switch() << "\n";
          strm << "_get_general_EV: " << machine._get_general_EV() << "\n";
          strm << "_get_general_valve: " << machine._get_general_valve() << "\n";
          strm << "_get_handle_move: " << machine._get_handle_move() << "\n";
          strm << "_get_close_EV: " << machine._get_close_EV() << "\n";
          strm << "_get_extend_EV: " << machine._get_extend_EV() << "\n";
          strm << "_get_open_EV: " << machine._get_open_EV() << "\n";
          strm << "_get_retract_EV: " << machine._get_retract_EV() << "\n";
          strm << "_get_shock_absorber: " << machine._get_shock_absorber() << "\n";
          strm << "_get_valve_close_door: " << machine._get_valve_close_door() << "\n";
          strm << "_get_valve_extend_gear: " << machine._get_valve_extend_gear() << "\n";
          strm << "_get_valve_open_door: " << machine._get_valve_open_door() << "\n";
          strm << "_get_valve_retract_gear: " << machine._get_valve_retract_gear() << "\n";
          strm << "_get_doors: " << machine._get_doors() << "\n";
          strm << "_get_gears: " << machine._get_gears() << "\n";
          strm << "_get_handle: " << machine._get_handle() << "\n";
          strm << "_get_door: " << machine._get_door() << "\n";
          strm << "_get_gear: " << machine._get_gear() << "\n";
          return strm;
        }


};


class ModelChecker {
    private:
        LandingGear_R6::Type type;
        int threads;
        bool isCaching;
        bool isDebug;

        std::list<LandingGear_R6> unvisitedStates;
        std::unordered_set<LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual> states;
        std::atomic<int> transitions;
        std::mutex mutex;
        std::mutex waitMutex;
        std::mutex cacheMutex;
        std::condition_variable waitCV;

        std::atomic<bool> invariantViolatedBool;
        std::atomic<bool> deadlockDetected;
        LandingGear_R6 counterExampleState;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_begin_flying, LandingGear_R6::_ProjectionWrite_begin_flying, LandingGear_R6::_ProjectionRead_begin_flying::Hash, LandingGear_R6::_ProjectionRead_begin_flying::HashEqual>> _OpCache_begin_flying;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_begin_flying, bool, LandingGear_R6::_ProjectionRead__tr_begin_flying::Hash, LandingGear_R6::_ProjectionRead__tr_begin_flying::HashEqual> _OpCache_tr_begin_flying;
        std::mutex _ProjectionRead_begin_flying_mutex;
        std::mutex _ProjectionRead__tr_begin_flying_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_land_plane, LandingGear_R6::_ProjectionWrite_land_plane, LandingGear_R6::_ProjectionRead_land_plane::Hash, LandingGear_R6::_ProjectionRead_land_plane::HashEqual>> _OpCache_land_plane;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_land_plane, bool, LandingGear_R6::_ProjectionRead__tr_land_plane::Hash, LandingGear_R6::_ProjectionRead__tr_land_plane::HashEqual> _OpCache_tr_land_plane;
        std::mutex _ProjectionRead_land_plane_mutex;
        std::mutex _ProjectionRead__tr_land_plane_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_open_valve_door_open, LandingGear_R6::_ProjectionWrite_open_valve_door_open, LandingGear_R6::_ProjectionRead_open_valve_door_open::Hash, LandingGear_R6::_ProjectionRead_open_valve_door_open::HashEqual>> _OpCache_open_valve_door_open;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_open_valve_door_open, bool, LandingGear_R6::_ProjectionRead__tr_open_valve_door_open::Hash, LandingGear_R6::_ProjectionRead__tr_open_valve_door_open::HashEqual> _OpCache_tr_open_valve_door_open;
        std::mutex _ProjectionRead_open_valve_door_open_mutex;
        std::mutex _ProjectionRead__tr_open_valve_door_open_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_close_valve_door_open, LandingGear_R6::_ProjectionWrite_close_valve_door_open, LandingGear_R6::_ProjectionRead_close_valve_door_open::Hash, LandingGear_R6::_ProjectionRead_close_valve_door_open::HashEqual>> _OpCache_close_valve_door_open;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_close_valve_door_open, bool, LandingGear_R6::_ProjectionRead__tr_close_valve_door_open::Hash, LandingGear_R6::_ProjectionRead__tr_close_valve_door_open::HashEqual> _OpCache_tr_close_valve_door_open;
        std::mutex _ProjectionRead_close_valve_door_open_mutex;
        std::mutex _ProjectionRead__tr_close_valve_door_open_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_open_valve_door_close, LandingGear_R6::_ProjectionWrite_open_valve_door_close, LandingGear_R6::_ProjectionRead_open_valve_door_close::Hash, LandingGear_R6::_ProjectionRead_open_valve_door_close::HashEqual>> _OpCache_open_valve_door_close;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_open_valve_door_close, bool, LandingGear_R6::_ProjectionRead__tr_open_valve_door_close::Hash, LandingGear_R6::_ProjectionRead__tr_open_valve_door_close::HashEqual> _OpCache_tr_open_valve_door_close;
        std::mutex _ProjectionRead_open_valve_door_close_mutex;
        std::mutex _ProjectionRead__tr_open_valve_door_close_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_close_valve_door_close, LandingGear_R6::_ProjectionWrite_close_valve_door_close, LandingGear_R6::_ProjectionRead_close_valve_door_close::Hash, LandingGear_R6::_ProjectionRead_close_valve_door_close::HashEqual>> _OpCache_close_valve_door_close;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_close_valve_door_close, bool, LandingGear_R6::_ProjectionRead__tr_close_valve_door_close::Hash, LandingGear_R6::_ProjectionRead__tr_close_valve_door_close::HashEqual> _OpCache_tr_close_valve_door_close;
        std::mutex _ProjectionRead_close_valve_door_close_mutex;
        std::mutex _ProjectionRead__tr_close_valve_door_close_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_open_valve_retract_gear, LandingGear_R6::_ProjectionWrite_open_valve_retract_gear, LandingGear_R6::_ProjectionRead_open_valve_retract_gear::Hash, LandingGear_R6::_ProjectionRead_open_valve_retract_gear::HashEqual>> _OpCache_open_valve_retract_gear;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_open_valve_retract_gear, bool, LandingGear_R6::_ProjectionRead__tr_open_valve_retract_gear::Hash, LandingGear_R6::_ProjectionRead__tr_open_valve_retract_gear::HashEqual> _OpCache_tr_open_valve_retract_gear;
        std::mutex _ProjectionRead_open_valve_retract_gear_mutex;
        std::mutex _ProjectionRead__tr_open_valve_retract_gear_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_close_valve_retract_gear, LandingGear_R6::_ProjectionWrite_close_valve_retract_gear, LandingGear_R6::_ProjectionRead_close_valve_retract_gear::Hash, LandingGear_R6::_ProjectionRead_close_valve_retract_gear::HashEqual>> _OpCache_close_valve_retract_gear;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_close_valve_retract_gear, bool, LandingGear_R6::_ProjectionRead__tr_close_valve_retract_gear::Hash, LandingGear_R6::_ProjectionRead__tr_close_valve_retract_gear::HashEqual> _OpCache_tr_close_valve_retract_gear;
        std::mutex _ProjectionRead_close_valve_retract_gear_mutex;
        std::mutex _ProjectionRead__tr_close_valve_retract_gear_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_open_valve_extend_gear, LandingGear_R6::_ProjectionWrite_open_valve_extend_gear, LandingGear_R6::_ProjectionRead_open_valve_extend_gear::Hash, LandingGear_R6::_ProjectionRead_open_valve_extend_gear::HashEqual>> _OpCache_open_valve_extend_gear;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_open_valve_extend_gear, bool, LandingGear_R6::_ProjectionRead__tr_open_valve_extend_gear::Hash, LandingGear_R6::_ProjectionRead__tr_open_valve_extend_gear::HashEqual> _OpCache_tr_open_valve_extend_gear;
        std::mutex _ProjectionRead_open_valve_extend_gear_mutex;
        std::mutex _ProjectionRead__tr_open_valve_extend_gear_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_close_valve_extend_gear, LandingGear_R6::_ProjectionWrite_close_valve_extend_gear, LandingGear_R6::_ProjectionRead_close_valve_extend_gear::Hash, LandingGear_R6::_ProjectionRead_close_valve_extend_gear::HashEqual>> _OpCache_close_valve_extend_gear;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_close_valve_extend_gear, bool, LandingGear_R6::_ProjectionRead__tr_close_valve_extend_gear::Hash, LandingGear_R6::_ProjectionRead__tr_close_valve_extend_gear::HashEqual> _OpCache_tr_close_valve_extend_gear;
        std::mutex _ProjectionRead_close_valve_extend_gear_mutex;
        std::mutex _ProjectionRead__tr_close_valve_extend_gear_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_con_stimulate_open_door_valve, LandingGear_R6::_ProjectionWrite_con_stimulate_open_door_valve, LandingGear_R6::_ProjectionRead_con_stimulate_open_door_valve::Hash, LandingGear_R6::_ProjectionRead_con_stimulate_open_door_valve::HashEqual>> _OpCache_con_stimulate_open_door_valve;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_con_stimulate_open_door_valve, bool, LandingGear_R6::_ProjectionRead__tr_con_stimulate_open_door_valve::Hash, LandingGear_R6::_ProjectionRead__tr_con_stimulate_open_door_valve::HashEqual> _OpCache_tr_con_stimulate_open_door_valve;
        std::mutex _ProjectionRead_con_stimulate_open_door_valve_mutex;
        std::mutex _ProjectionRead__tr_con_stimulate_open_door_valve_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_con_stop_stimulate_open_door_valve, LandingGear_R6::_ProjectionWrite_con_stop_stimulate_open_door_valve, LandingGear_R6::_ProjectionRead_con_stop_stimulate_open_door_valve::Hash, LandingGear_R6::_ProjectionRead_con_stop_stimulate_open_door_valve::HashEqual>> _OpCache_con_stop_stimulate_open_door_valve;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_con_stop_stimulate_open_door_valve, bool, LandingGear_R6::_ProjectionRead__tr_con_stop_stimulate_open_door_valve::Hash, LandingGear_R6::_ProjectionRead__tr_con_stop_stimulate_open_door_valve::HashEqual> _OpCache_tr_con_stop_stimulate_open_door_valve;
        std::mutex _ProjectionRead_con_stop_stimulate_open_door_valve_mutex;
        std::mutex _ProjectionRead__tr_con_stop_stimulate_open_door_valve_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_con_stimulate_close_door_valve, LandingGear_R6::_ProjectionWrite_con_stimulate_close_door_valve, LandingGear_R6::_ProjectionRead_con_stimulate_close_door_valve::Hash, LandingGear_R6::_ProjectionRead_con_stimulate_close_door_valve::HashEqual>> _OpCache_con_stimulate_close_door_valve;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_con_stimulate_close_door_valve, bool, LandingGear_R6::_ProjectionRead__tr_con_stimulate_close_door_valve::Hash, LandingGear_R6::_ProjectionRead__tr_con_stimulate_close_door_valve::HashEqual> _OpCache_tr_con_stimulate_close_door_valve;
        std::mutex _ProjectionRead_con_stimulate_close_door_valve_mutex;
        std::mutex _ProjectionRead__tr_con_stimulate_close_door_valve_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_con_stop_stimulate_close_door_valve, LandingGear_R6::_ProjectionWrite_con_stop_stimulate_close_door_valve, LandingGear_R6::_ProjectionRead_con_stop_stimulate_close_door_valve::Hash, LandingGear_R6::_ProjectionRead_con_stop_stimulate_close_door_valve::HashEqual>> _OpCache_con_stop_stimulate_close_door_valve;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_con_stop_stimulate_close_door_valve, bool, LandingGear_R6::_ProjectionRead__tr_con_stop_stimulate_close_door_valve::Hash, LandingGear_R6::_ProjectionRead__tr_con_stop_stimulate_close_door_valve::HashEqual> _OpCache_tr_con_stop_stimulate_close_door_valve;
        std::mutex _ProjectionRead_con_stop_stimulate_close_door_valve_mutex;
        std::mutex _ProjectionRead__tr_con_stop_stimulate_close_door_valve_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_con_stimulate_retract_gear_valve, LandingGear_R6::_ProjectionWrite_con_stimulate_retract_gear_valve, LandingGear_R6::_ProjectionRead_con_stimulate_retract_gear_valve::Hash, LandingGear_R6::_ProjectionRead_con_stimulate_retract_gear_valve::HashEqual>> _OpCache_con_stimulate_retract_gear_valve;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_con_stimulate_retract_gear_valve, bool, LandingGear_R6::_ProjectionRead__tr_con_stimulate_retract_gear_valve::Hash, LandingGear_R6::_ProjectionRead__tr_con_stimulate_retract_gear_valve::HashEqual> _OpCache_tr_con_stimulate_retract_gear_valve;
        std::mutex _ProjectionRead_con_stimulate_retract_gear_valve_mutex;
        std::mutex _ProjectionRead__tr_con_stimulate_retract_gear_valve_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_con_stop_stimulate_retract_gear_valve, LandingGear_R6::_ProjectionWrite_con_stop_stimulate_retract_gear_valve, LandingGear_R6::_ProjectionRead_con_stop_stimulate_retract_gear_valve::Hash, LandingGear_R6::_ProjectionRead_con_stop_stimulate_retract_gear_valve::HashEqual>> _OpCache_con_stop_stimulate_retract_gear_valve;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_con_stop_stimulate_retract_gear_valve, bool, LandingGear_R6::_ProjectionRead__tr_con_stop_stimulate_retract_gear_valve::Hash, LandingGear_R6::_ProjectionRead__tr_con_stop_stimulate_retract_gear_valve::HashEqual> _OpCache_tr_con_stop_stimulate_retract_gear_valve;
        std::mutex _ProjectionRead_con_stop_stimulate_retract_gear_valve_mutex;
        std::mutex _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_con_stimulate_extend_gear_valve, LandingGear_R6::_ProjectionWrite_con_stimulate_extend_gear_valve, LandingGear_R6::_ProjectionRead_con_stimulate_extend_gear_valve::Hash, LandingGear_R6::_ProjectionRead_con_stimulate_extend_gear_valve::HashEqual>> _OpCache_con_stimulate_extend_gear_valve;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_con_stimulate_extend_gear_valve, bool, LandingGear_R6::_ProjectionRead__tr_con_stimulate_extend_gear_valve::Hash, LandingGear_R6::_ProjectionRead__tr_con_stimulate_extend_gear_valve::HashEqual> _OpCache_tr_con_stimulate_extend_gear_valve;
        std::mutex _ProjectionRead_con_stimulate_extend_gear_valve_mutex;
        std::mutex _ProjectionRead__tr_con_stimulate_extend_gear_valve_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_con_stop_stimulate_extend_gear_valve, LandingGear_R6::_ProjectionWrite_con_stop_stimulate_extend_gear_valve, LandingGear_R6::_ProjectionRead_con_stop_stimulate_extend_gear_valve::Hash, LandingGear_R6::_ProjectionRead_con_stop_stimulate_extend_gear_valve::HashEqual>> _OpCache_con_stop_stimulate_extend_gear_valve;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_con_stop_stimulate_extend_gear_valve, bool, LandingGear_R6::_ProjectionRead__tr_con_stop_stimulate_extend_gear_valve::Hash, LandingGear_R6::_ProjectionRead__tr_con_stop_stimulate_extend_gear_valve::HashEqual> _OpCache_tr_con_stop_stimulate_extend_gear_valve;
        std::mutex _ProjectionRead_con_stop_stimulate_extend_gear_valve_mutex;
        std::mutex _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve_mutex;

        std::unordered_map<BSet<LandingGear_R6::POSITION>, std::unordered_map<LandingGear_R6::_ProjectionRead_env_start_retracting_first, LandingGear_R6::_ProjectionWrite_env_start_retracting_first, LandingGear_R6::_ProjectionRead_env_start_retracting_first::Hash, LandingGear_R6::_ProjectionRead_env_start_retracting_first::HashEqual>, BSet<LandingGear_R6::POSITION>::SetHash, BSet<LandingGear_R6::POSITION>::SetHashEqual> _OpCache_env_start_retracting_first;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_env_start_retracting_first,  BSet<LandingGear_R6::POSITION>, LandingGear_R6::_ProjectionRead__tr_env_start_retracting_first::Hash, LandingGear_R6::_ProjectionRead__tr_env_start_retracting_first::HashEqual> _OpCache_tr_env_start_retracting_first;
        std::mutex _ProjectionRead_env_start_retracting_first_mutex;
        std::mutex _ProjectionRead__tr_env_start_retracting_first_mutex;

        std::unordered_map<BSet<LandingGear_R6::POSITION>, std::unordered_map<LandingGear_R6::_ProjectionRead_env_retract_gear_skip, LandingGear_R6::_ProjectionWrite_env_retract_gear_skip, LandingGear_R6::_ProjectionRead_env_retract_gear_skip::Hash, LandingGear_R6::_ProjectionRead_env_retract_gear_skip::HashEqual>, BSet<LandingGear_R6::POSITION>::SetHash, BSet<LandingGear_R6::POSITION>::SetHashEqual> _OpCache_env_retract_gear_skip;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_env_retract_gear_skip,  BSet<LandingGear_R6::POSITION>, LandingGear_R6::_ProjectionRead__tr_env_retract_gear_skip::Hash, LandingGear_R6::_ProjectionRead__tr_env_retract_gear_skip::HashEqual> _OpCache_tr_env_retract_gear_skip;
        std::mutex _ProjectionRead_env_retract_gear_skip_mutex;
        std::mutex _ProjectionRead__tr_env_retract_gear_skip_mutex;

        std::unordered_map<BSet<LandingGear_R6::POSITION>, std::unordered_map<LandingGear_R6::_ProjectionRead_env_retract_gear_last, LandingGear_R6::_ProjectionWrite_env_retract_gear_last, LandingGear_R6::_ProjectionRead_env_retract_gear_last::Hash, LandingGear_R6::_ProjectionRead_env_retract_gear_last::HashEqual>, BSet<LandingGear_R6::POSITION>::SetHash, BSet<LandingGear_R6::POSITION>::SetHashEqual> _OpCache_env_retract_gear_last;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_env_retract_gear_last,  BSet<LandingGear_R6::POSITION>, LandingGear_R6::_ProjectionRead__tr_env_retract_gear_last::Hash, LandingGear_R6::_ProjectionRead__tr_env_retract_gear_last::HashEqual> _OpCache_tr_env_retract_gear_last;
        std::mutex _ProjectionRead_env_retract_gear_last_mutex;
        std::mutex _ProjectionRead__tr_env_retract_gear_last_mutex;

        std::unordered_map<BSet<LandingGear_R6::POSITION>, std::unordered_map<LandingGear_R6::_ProjectionRead_env_start_extending, LandingGear_R6::_ProjectionWrite_env_start_extending, LandingGear_R6::_ProjectionRead_env_start_extending::Hash, LandingGear_R6::_ProjectionRead_env_start_extending::HashEqual>, BSet<LandingGear_R6::POSITION>::SetHash, BSet<LandingGear_R6::POSITION>::SetHashEqual> _OpCache_env_start_extending;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_env_start_extending,  BSet<LandingGear_R6::POSITION>, LandingGear_R6::_ProjectionRead__tr_env_start_extending::Hash, LandingGear_R6::_ProjectionRead__tr_env_start_extending::HashEqual> _OpCache_tr_env_start_extending;
        std::mutex _ProjectionRead_env_start_extending_mutex;
        std::mutex _ProjectionRead__tr_env_start_extending_mutex;

        std::unordered_map<BSet<LandingGear_R6::POSITION>, std::unordered_map<LandingGear_R6::_ProjectionRead_env_extend_gear_last, LandingGear_R6::_ProjectionWrite_env_extend_gear_last, LandingGear_R6::_ProjectionRead_env_extend_gear_last::Hash, LandingGear_R6::_ProjectionRead_env_extend_gear_last::HashEqual>, BSet<LandingGear_R6::POSITION>::SetHash, BSet<LandingGear_R6::POSITION>::SetHashEqual> _OpCache_env_extend_gear_last;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_env_extend_gear_last,  BSet<LandingGear_R6::POSITION>, LandingGear_R6::_ProjectionRead__tr_env_extend_gear_last::Hash, LandingGear_R6::_ProjectionRead__tr_env_extend_gear_last::HashEqual> _OpCache_tr_env_extend_gear_last;
        std::mutex _ProjectionRead_env_extend_gear_last_mutex;
        std::mutex _ProjectionRead__tr_env_extend_gear_last_mutex;

        std::unordered_map<BSet<LandingGear_R6::POSITION>, std::unordered_map<LandingGear_R6::_ProjectionRead_env_extend_gear_skip, LandingGear_R6::_ProjectionWrite_env_extend_gear_skip, LandingGear_R6::_ProjectionRead_env_extend_gear_skip::Hash, LandingGear_R6::_ProjectionRead_env_extend_gear_skip::HashEqual>, BSet<LandingGear_R6::POSITION>::SetHash, BSet<LandingGear_R6::POSITION>::SetHashEqual> _OpCache_env_extend_gear_skip;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_env_extend_gear_skip,  BSet<LandingGear_R6::POSITION>, LandingGear_R6::_ProjectionRead__tr_env_extend_gear_skip::Hash, LandingGear_R6::_ProjectionRead__tr_env_extend_gear_skip::HashEqual> _OpCache_tr_env_extend_gear_skip;
        std::mutex _ProjectionRead_env_extend_gear_skip_mutex;
        std::mutex _ProjectionRead__tr_env_extend_gear_skip_mutex;

        std::unordered_map<BSet<LandingGear_R6::POSITION>, std::unordered_map<LandingGear_R6::_ProjectionRead_env_start_open_door, LandingGear_R6::_ProjectionWrite_env_start_open_door, LandingGear_R6::_ProjectionRead_env_start_open_door::Hash, LandingGear_R6::_ProjectionRead_env_start_open_door::HashEqual>, BSet<LandingGear_R6::POSITION>::SetHash, BSet<LandingGear_R6::POSITION>::SetHashEqual> _OpCache_env_start_open_door;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_env_start_open_door,  BSet<LandingGear_R6::POSITION>, LandingGear_R6::_ProjectionRead__tr_env_start_open_door::Hash, LandingGear_R6::_ProjectionRead__tr_env_start_open_door::HashEqual> _OpCache_tr_env_start_open_door;
        std::mutex _ProjectionRead_env_start_open_door_mutex;
        std::mutex _ProjectionRead__tr_env_start_open_door_mutex;

        std::unordered_map<BSet<LandingGear_R6::POSITION>, std::unordered_map<LandingGear_R6::_ProjectionRead_env_open_door_last, LandingGear_R6::_ProjectionWrite_env_open_door_last, LandingGear_R6::_ProjectionRead_env_open_door_last::Hash, LandingGear_R6::_ProjectionRead_env_open_door_last::HashEqual>, BSet<LandingGear_R6::POSITION>::SetHash, BSet<LandingGear_R6::POSITION>::SetHashEqual> _OpCache_env_open_door_last;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_env_open_door_last,  BSet<LandingGear_R6::POSITION>, LandingGear_R6::_ProjectionRead__tr_env_open_door_last::Hash, LandingGear_R6::_ProjectionRead__tr_env_open_door_last::HashEqual> _OpCache_tr_env_open_door_last;
        std::mutex _ProjectionRead_env_open_door_last_mutex;
        std::mutex _ProjectionRead__tr_env_open_door_last_mutex;

        std::unordered_map<BSet<LandingGear_R6::POSITION>, std::unordered_map<LandingGear_R6::_ProjectionRead_env_open_door_skip, LandingGear_R6::_ProjectionWrite_env_open_door_skip, LandingGear_R6::_ProjectionRead_env_open_door_skip::Hash, LandingGear_R6::_ProjectionRead_env_open_door_skip::HashEqual>, BSet<LandingGear_R6::POSITION>::SetHash, BSet<LandingGear_R6::POSITION>::SetHashEqual> _OpCache_env_open_door_skip;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_env_open_door_skip,  BSet<LandingGear_R6::POSITION>, LandingGear_R6::_ProjectionRead__tr_env_open_door_skip::Hash, LandingGear_R6::_ProjectionRead__tr_env_open_door_skip::HashEqual> _OpCache_tr_env_open_door_skip;
        std::mutex _ProjectionRead_env_open_door_skip_mutex;
        std::mutex _ProjectionRead__tr_env_open_door_skip_mutex;

        std::unordered_map<BSet<LandingGear_R6::POSITION>, std::unordered_map<LandingGear_R6::_ProjectionRead_env_start_close_door, LandingGear_R6::_ProjectionWrite_env_start_close_door, LandingGear_R6::_ProjectionRead_env_start_close_door::Hash, LandingGear_R6::_ProjectionRead_env_start_close_door::HashEqual>, BSet<LandingGear_R6::POSITION>::SetHash, BSet<LandingGear_R6::POSITION>::SetHashEqual> _OpCache_env_start_close_door;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_env_start_close_door,  BSet<LandingGear_R6::POSITION>, LandingGear_R6::_ProjectionRead__tr_env_start_close_door::Hash, LandingGear_R6::_ProjectionRead__tr_env_start_close_door::HashEqual> _OpCache_tr_env_start_close_door;
        std::mutex _ProjectionRead_env_start_close_door_mutex;
        std::mutex _ProjectionRead__tr_env_start_close_door_mutex;

        std::unordered_map<BSet<LandingGear_R6::POSITION>, std::unordered_map<LandingGear_R6::_ProjectionRead_env_close_door, LandingGear_R6::_ProjectionWrite_env_close_door, LandingGear_R6::_ProjectionRead_env_close_door::Hash, LandingGear_R6::_ProjectionRead_env_close_door::HashEqual>, BSet<LandingGear_R6::POSITION>::SetHash, BSet<LandingGear_R6::POSITION>::SetHashEqual> _OpCache_env_close_door;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_env_close_door,  BSet<LandingGear_R6::POSITION>, LandingGear_R6::_ProjectionRead__tr_env_close_door::Hash, LandingGear_R6::_ProjectionRead__tr_env_close_door::HashEqual> _OpCache_tr_env_close_door;
        std::mutex _ProjectionRead_env_close_door_mutex;
        std::mutex _ProjectionRead__tr_env_close_door_mutex;

        std::unordered_map<BSet<LandingGear_R6::POSITION>, std::unordered_map<LandingGear_R6::_ProjectionRead_env_close_door_skip, LandingGear_R6::_ProjectionWrite_env_close_door_skip, LandingGear_R6::_ProjectionRead_env_close_door_skip::Hash, LandingGear_R6::_ProjectionRead_env_close_door_skip::HashEqual>, BSet<LandingGear_R6::POSITION>::SetHash, BSet<LandingGear_R6::POSITION>::SetHashEqual> _OpCache_env_close_door_skip;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_env_close_door_skip,  BSet<LandingGear_R6::POSITION>, LandingGear_R6::_ProjectionRead__tr_env_close_door_skip::Hash, LandingGear_R6::_ProjectionRead__tr_env_close_door_skip::HashEqual> _OpCache_tr_env_close_door_skip;
        std::mutex _ProjectionRead_env_close_door_skip_mutex;
        std::mutex _ProjectionRead__tr_env_close_door_skip_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_toggle_handle_up, LandingGear_R6::_ProjectionWrite_toggle_handle_up, LandingGear_R6::_ProjectionRead_toggle_handle_up::Hash, LandingGear_R6::_ProjectionRead_toggle_handle_up::HashEqual>> _OpCache_toggle_handle_up;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_toggle_handle_up, bool, LandingGear_R6::_ProjectionRead__tr_toggle_handle_up::Hash, LandingGear_R6::_ProjectionRead__tr_toggle_handle_up::HashEqual> _OpCache_tr_toggle_handle_up;
        std::mutex _ProjectionRead_toggle_handle_up_mutex;
        std::mutex _ProjectionRead__tr_toggle_handle_up_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_toggle_handle_down, LandingGear_R6::_ProjectionWrite_toggle_handle_down, LandingGear_R6::_ProjectionRead_toggle_handle_down::Hash, LandingGear_R6::_ProjectionRead_toggle_handle_down::HashEqual>> _OpCache_toggle_handle_down;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_toggle_handle_down, bool, LandingGear_R6::_ProjectionRead__tr_toggle_handle_down::Hash, LandingGear_R6::_ProjectionRead__tr_toggle_handle_down::HashEqual> _OpCache_tr_toggle_handle_down;
        std::mutex _ProjectionRead_toggle_handle_down_mutex;
        std::mutex _ProjectionRead__tr_toggle_handle_down_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_con_stimulate_general_valve, LandingGear_R6::_ProjectionWrite_con_stimulate_general_valve, LandingGear_R6::_ProjectionRead_con_stimulate_general_valve::Hash, LandingGear_R6::_ProjectionRead_con_stimulate_general_valve::HashEqual>> _OpCache_con_stimulate_general_valve;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_con_stimulate_general_valve, bool, LandingGear_R6::_ProjectionRead__tr_con_stimulate_general_valve::Hash, LandingGear_R6::_ProjectionRead__tr_con_stimulate_general_valve::HashEqual> _OpCache_tr_con_stimulate_general_valve;
        std::mutex _ProjectionRead_con_stimulate_general_valve_mutex;
        std::mutex _ProjectionRead__tr_con_stimulate_general_valve_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_con_stop_stimulate_general_valve, LandingGear_R6::_ProjectionWrite_con_stop_stimulate_general_valve, LandingGear_R6::_ProjectionRead_con_stop_stimulate_general_valve::Hash, LandingGear_R6::_ProjectionRead_con_stop_stimulate_general_valve::HashEqual>> _OpCache_con_stop_stimulate_general_valve;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_con_stop_stimulate_general_valve, bool, LandingGear_R6::_ProjectionRead__tr_con_stop_stimulate_general_valve::Hash, LandingGear_R6::_ProjectionRead__tr_con_stop_stimulate_general_valve::HashEqual> _OpCache_tr_con_stop_stimulate_general_valve;
        std::mutex _ProjectionRead_con_stop_stimulate_general_valve_mutex;
        std::mutex _ProjectionRead__tr_con_stop_stimulate_general_valve_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_evn_open_general_valve, LandingGear_R6::_ProjectionWrite_evn_open_general_valve, LandingGear_R6::_ProjectionRead_evn_open_general_valve::Hash, LandingGear_R6::_ProjectionRead_evn_open_general_valve::HashEqual>> _OpCache_evn_open_general_valve;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_evn_open_general_valve, bool, LandingGear_R6::_ProjectionRead__tr_evn_open_general_valve::Hash, LandingGear_R6::_ProjectionRead__tr_evn_open_general_valve::HashEqual> _OpCache_tr_evn_open_general_valve;
        std::mutex _ProjectionRead_evn_open_general_valve_mutex;
        std::mutex _ProjectionRead__tr_evn_open_general_valve_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_evn_close_general_valve, LandingGear_R6::_ProjectionWrite_evn_close_general_valve, LandingGear_R6::_ProjectionRead_evn_close_general_valve::Hash, LandingGear_R6::_ProjectionRead_evn_close_general_valve::HashEqual>> _OpCache_evn_close_general_valve;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_evn_close_general_valve, bool, LandingGear_R6::_ProjectionRead__tr_evn_close_general_valve::Hash, LandingGear_R6::_ProjectionRead__tr_evn_close_general_valve::HashEqual> _OpCache_tr_evn_close_general_valve;
        std::mutex _ProjectionRead_evn_close_general_valve_mutex;
        std::mutex _ProjectionRead__tr_evn_close_general_valve_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_env_close_analogical_switch, LandingGear_R6::_ProjectionWrite_env_close_analogical_switch, LandingGear_R6::_ProjectionRead_env_close_analogical_switch::Hash, LandingGear_R6::_ProjectionRead_env_close_analogical_switch::HashEqual>> _OpCache_env_close_analogical_switch;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_env_close_analogical_switch, bool, LandingGear_R6::_ProjectionRead__tr_env_close_analogical_switch::Hash, LandingGear_R6::_ProjectionRead__tr_env_close_analogical_switch::HashEqual> _OpCache_tr_env_close_analogical_switch;
        std::mutex _ProjectionRead_env_close_analogical_switch_mutex;
        std::mutex _ProjectionRead__tr_env_close_analogical_switch_mutex;

        std::unordered_map<bool, std::unordered_map<LandingGear_R6::_ProjectionRead_env_open_analogical_switch, LandingGear_R6::_ProjectionWrite_env_open_analogical_switch, LandingGear_R6::_ProjectionRead_env_open_analogical_switch::Hash, LandingGear_R6::_ProjectionRead_env_open_analogical_switch::HashEqual>> _OpCache_env_open_analogical_switch;
        std::unordered_map<LandingGear_R6::_ProjectionRead__tr_env_open_analogical_switch, bool, LandingGear_R6::_ProjectionRead__tr_env_open_analogical_switch::Hash, LandingGear_R6::_ProjectionRead__tr_env_open_analogical_switch::HashEqual> _OpCache_tr_env_open_analogical_switch;
        std::mutex _ProjectionRead_env_open_analogical_switch_mutex;
        std::mutex _ProjectionRead__tr_env_open_analogical_switch_mutex;

        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_1, bool, LandingGear_R6::_ProjectionRead__check_inv_1::Hash, LandingGear_R6::_ProjectionRead__check_inv_1::HashEqual> _InvCache__check_inv_1;
        std::mutex _ProjectionRead__check_inv_1_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_2, bool, LandingGear_R6::_ProjectionRead__check_inv_2::Hash, LandingGear_R6::_ProjectionRead__check_inv_2::HashEqual> _InvCache__check_inv_2;
        std::mutex _ProjectionRead__check_inv_2_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_3, bool, LandingGear_R6::_ProjectionRead__check_inv_3::Hash, LandingGear_R6::_ProjectionRead__check_inv_3::HashEqual> _InvCache__check_inv_3;
        std::mutex _ProjectionRead__check_inv_3_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_4, bool, LandingGear_R6::_ProjectionRead__check_inv_4::Hash, LandingGear_R6::_ProjectionRead__check_inv_4::HashEqual> _InvCache__check_inv_4;
        std::mutex _ProjectionRead__check_inv_4_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_5, bool, LandingGear_R6::_ProjectionRead__check_inv_5::Hash, LandingGear_R6::_ProjectionRead__check_inv_5::HashEqual> _InvCache__check_inv_5;
        std::mutex _ProjectionRead__check_inv_5_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_6, bool, LandingGear_R6::_ProjectionRead__check_inv_6::Hash, LandingGear_R6::_ProjectionRead__check_inv_6::HashEqual> _InvCache__check_inv_6;
        std::mutex _ProjectionRead__check_inv_6_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_7, bool, LandingGear_R6::_ProjectionRead__check_inv_7::Hash, LandingGear_R6::_ProjectionRead__check_inv_7::HashEqual> _InvCache__check_inv_7;
        std::mutex _ProjectionRead__check_inv_7_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_8, bool, LandingGear_R6::_ProjectionRead__check_inv_8::Hash, LandingGear_R6::_ProjectionRead__check_inv_8::HashEqual> _InvCache__check_inv_8;
        std::mutex _ProjectionRead__check_inv_8_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_9, bool, LandingGear_R6::_ProjectionRead__check_inv_9::Hash, LandingGear_R6::_ProjectionRead__check_inv_9::HashEqual> _InvCache__check_inv_9;
        std::mutex _ProjectionRead__check_inv_9_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_10, bool, LandingGear_R6::_ProjectionRead__check_inv_10::Hash, LandingGear_R6::_ProjectionRead__check_inv_10::HashEqual> _InvCache__check_inv_10;
        std::mutex _ProjectionRead__check_inv_10_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_11, bool, LandingGear_R6::_ProjectionRead__check_inv_11::Hash, LandingGear_R6::_ProjectionRead__check_inv_11::HashEqual> _InvCache__check_inv_11;
        std::mutex _ProjectionRead__check_inv_11_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_12, bool, LandingGear_R6::_ProjectionRead__check_inv_12::Hash, LandingGear_R6::_ProjectionRead__check_inv_12::HashEqual> _InvCache__check_inv_12;
        std::mutex _ProjectionRead__check_inv_12_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_13, bool, LandingGear_R6::_ProjectionRead__check_inv_13::Hash, LandingGear_R6::_ProjectionRead__check_inv_13::HashEqual> _InvCache__check_inv_13;
        std::mutex _ProjectionRead__check_inv_13_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_14, bool, LandingGear_R6::_ProjectionRead__check_inv_14::Hash, LandingGear_R6::_ProjectionRead__check_inv_14::HashEqual> _InvCache__check_inv_14;
        std::mutex _ProjectionRead__check_inv_14_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_15, bool, LandingGear_R6::_ProjectionRead__check_inv_15::Hash, LandingGear_R6::_ProjectionRead__check_inv_15::HashEqual> _InvCache__check_inv_15;
        std::mutex _ProjectionRead__check_inv_15_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_16, bool, LandingGear_R6::_ProjectionRead__check_inv_16::Hash, LandingGear_R6::_ProjectionRead__check_inv_16::HashEqual> _InvCache__check_inv_16;
        std::mutex _ProjectionRead__check_inv_16_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_17, bool, LandingGear_R6::_ProjectionRead__check_inv_17::Hash, LandingGear_R6::_ProjectionRead__check_inv_17::HashEqual> _InvCache__check_inv_17;
        std::mutex _ProjectionRead__check_inv_17_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_18, bool, LandingGear_R6::_ProjectionRead__check_inv_18::Hash, LandingGear_R6::_ProjectionRead__check_inv_18::HashEqual> _InvCache__check_inv_18;
        std::mutex _ProjectionRead__check_inv_18_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_19, bool, LandingGear_R6::_ProjectionRead__check_inv_19::Hash, LandingGear_R6::_ProjectionRead__check_inv_19::HashEqual> _InvCache__check_inv_19;
        std::mutex _ProjectionRead__check_inv_19_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_20, bool, LandingGear_R6::_ProjectionRead__check_inv_20::Hash, LandingGear_R6::_ProjectionRead__check_inv_20::HashEqual> _InvCache__check_inv_20;
        std::mutex _ProjectionRead__check_inv_20_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_21, bool, LandingGear_R6::_ProjectionRead__check_inv_21::Hash, LandingGear_R6::_ProjectionRead__check_inv_21::HashEqual> _InvCache__check_inv_21;
        std::mutex _ProjectionRead__check_inv_21_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_22, bool, LandingGear_R6::_ProjectionRead__check_inv_22::Hash, LandingGear_R6::_ProjectionRead__check_inv_22::HashEqual> _InvCache__check_inv_22;
        std::mutex _ProjectionRead__check_inv_22_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_23, bool, LandingGear_R6::_ProjectionRead__check_inv_23::Hash, LandingGear_R6::_ProjectionRead__check_inv_23::HashEqual> _InvCache__check_inv_23;
        std::mutex _ProjectionRead__check_inv_23_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_24, bool, LandingGear_R6::_ProjectionRead__check_inv_24::Hash, LandingGear_R6::_ProjectionRead__check_inv_24::HashEqual> _InvCache__check_inv_24;
        std::mutex _ProjectionRead__check_inv_24_mutex;
        std::unordered_map<LandingGear_R6::_ProjectionRead__check_inv_25, bool, LandingGear_R6::_ProjectionRead__check_inv_25::Hash, LandingGear_R6::_ProjectionRead__check_inv_25::HashEqual> _InvCache__check_inv_25;
        std::mutex _ProjectionRead__check_inv_25_mutex;

        std::unordered_map<LandingGear_R6, LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual> parents;

    public:
        ModelChecker() {}

        ModelChecker(LandingGear_R6::Type type, int threads, bool isCaching, bool isDebug) {
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
            LandingGear_R6 machine = LandingGear_R6();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            while(!unvisitedStates.empty()) {
                LandingGear_R6 state = next();

                std::unordered_set<LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual> nextStates = generateNextStates(state);

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
            LandingGear_R6 machine = LandingGear_R6();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            std::atomic<bool> stopThreads(false);
            std::atomic<int> possibleQueueChanges;
            possibleQueueChanges = 0;

            while(!unvisitedStates.empty() && !stopThreads.load()) {
                possibleQueueChanges.fetch_add(1);
                LandingGear_R6 state = next();
                std::packaged_task<void()> task([&, state] {
                    std::unordered_set<LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual> nextStates = generateNextStates(state);

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
        LandingGear_R6 next() {
            {
                std::unique_lock<std::mutex> lock(mutex);
                switch(type) {
                    case LandingGear_R6::BFS: {
                        LandingGear_R6 state = unvisitedStates.front();
                        unvisitedStates.pop_front();
                        return state;
                    }
                    case LandingGear_R6::DFS: {
                        LandingGear_R6 state = unvisitedStates.back();
                        unvisitedStates.pop_back();
                        return state;
                    }
                    case LandingGear_R6::MIXED: {
                        if(unvisitedStates.size() % 2 == 0) {
                            LandingGear_R6 state = unvisitedStates.front();
                            unvisitedStates.pop_front();
                            return state;
                        } else {
                            LandingGear_R6 state = unvisitedStates.back();
                            unvisitedStates.pop_back();
                            return state;
                        }
                    }
                }
                LandingGear_R6 state = unvisitedStates.front();
                unvisitedStates.pop_front();
                return state;
            };
        }

        std::unordered_set<LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual> generateNextStates(const LandingGear_R6& state) {
            std::unordered_set<LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual> result = std::unordered_set<LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual>();
            if(isCaching) {
                LandingGear_R6::_ProjectionRead__tr_begin_flying read__tr_begin_flying_state = state._projected_state_for__tr_begin_flying();
                bool _trid_1;
                auto _obj__trid_1_ptr = _OpCache_tr_begin_flying.find(read__tr_begin_flying_state);
                if(_obj__trid_1_ptr == _OpCache_tr_begin_flying.end()) {
                    _trid_1 = state._tr_begin_flying();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_begin_flying_lock(_ProjectionRead__tr_begin_flying_mutex);
                        _OpCache_tr_begin_flying.insert({read__tr_begin_flying_state, _trid_1});
                    }
                } else {
                    _trid_1 = _obj__trid_1_ptr->second;
                }
                if(_trid_1) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_begin_flying readState = state._projected_state_for_begin_flying();

                    auto _OpCache_with_parameter_begin_flying_ptr = _OpCache_begin_flying.find(_trid_1);
                    if(_OpCache_with_parameter_begin_flying_ptr == _OpCache_begin_flying.end()) {
                        copiedState.begin_flying();
                        LandingGear_R6::_ProjectionWrite_begin_flying writeState = copiedState._update_for_begin_flying();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_begin_flying, LandingGear_R6::_ProjectionWrite_begin_flying, LandingGear_R6::_ProjectionRead_begin_flying::Hash, LandingGear_R6::_ProjectionRead_begin_flying::HashEqual> _OpCache_with_parameter_begin_flying;
                        _OpCache_with_parameter_begin_flying.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_begin_flying_lock(_ProjectionRead_begin_flying_mutex);
                            _OpCache_begin_flying.insert({_trid_1, _OpCache_with_parameter_begin_flying});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_begin_flying, LandingGear_R6::_ProjectionWrite_begin_flying, LandingGear_R6::_ProjectionRead_begin_flying::Hash, LandingGear_R6::_ProjectionRead_begin_flying::HashEqual> _OpCache_with_parameter_begin_flying = _OpCache_with_parameter_begin_flying_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_begin_flying.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_begin_flying.end()) {
                            LandingGear_R6::_ProjectionWrite_begin_flying writeState = writeState_ptr->second;
                            copiedState._apply_update_for_begin_flying(writeState);
                        } else {
                            copiedState.begin_flying();
                            LandingGear_R6::_ProjectionWrite_begin_flying writeState = copiedState._update_for_begin_flying();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_begin_flying_lock(_ProjectionRead_begin_flying_mutex);
                                _OpCache_with_parameter_begin_flying.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "begin_flying";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_land_plane read__tr_land_plane_state = state._projected_state_for__tr_land_plane();
                bool _trid_2;
                auto _obj__trid_2_ptr = _OpCache_tr_land_plane.find(read__tr_land_plane_state);
                if(_obj__trid_2_ptr == _OpCache_tr_land_plane.end()) {
                    _trid_2 = state._tr_land_plane();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_land_plane_lock(_ProjectionRead__tr_land_plane_mutex);
                        _OpCache_tr_land_plane.insert({read__tr_land_plane_state, _trid_2});
                    }
                } else {
                    _trid_2 = _obj__trid_2_ptr->second;
                }
                if(_trid_2) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_land_plane readState = state._projected_state_for_land_plane();

                    auto _OpCache_with_parameter_land_plane_ptr = _OpCache_land_plane.find(_trid_2);
                    if(_OpCache_with_parameter_land_plane_ptr == _OpCache_land_plane.end()) {
                        copiedState.land_plane();
                        LandingGear_R6::_ProjectionWrite_land_plane writeState = copiedState._update_for_land_plane();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_land_plane, LandingGear_R6::_ProjectionWrite_land_plane, LandingGear_R6::_ProjectionRead_land_plane::Hash, LandingGear_R6::_ProjectionRead_land_plane::HashEqual> _OpCache_with_parameter_land_plane;
                        _OpCache_with_parameter_land_plane.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_land_plane_lock(_ProjectionRead_land_plane_mutex);
                            _OpCache_land_plane.insert({_trid_2, _OpCache_with_parameter_land_plane});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_land_plane, LandingGear_R6::_ProjectionWrite_land_plane, LandingGear_R6::_ProjectionRead_land_plane::Hash, LandingGear_R6::_ProjectionRead_land_plane::HashEqual> _OpCache_with_parameter_land_plane = _OpCache_with_parameter_land_plane_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_land_plane.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_land_plane.end()) {
                            LandingGear_R6::_ProjectionWrite_land_plane writeState = writeState_ptr->second;
                            copiedState._apply_update_for_land_plane(writeState);
                        } else {
                            copiedState.land_plane();
                            LandingGear_R6::_ProjectionWrite_land_plane writeState = copiedState._update_for_land_plane();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_land_plane_lock(_ProjectionRead_land_plane_mutex);
                                _OpCache_with_parameter_land_plane.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "land_plane";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_open_valve_door_open read__tr_open_valve_door_open_state = state._projected_state_for__tr_open_valve_door_open();
                bool _trid_3;
                auto _obj__trid_3_ptr = _OpCache_tr_open_valve_door_open.find(read__tr_open_valve_door_open_state);
                if(_obj__trid_3_ptr == _OpCache_tr_open_valve_door_open.end()) {
                    _trid_3 = state._tr_open_valve_door_open();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_open_valve_door_open_lock(_ProjectionRead__tr_open_valve_door_open_mutex);
                        _OpCache_tr_open_valve_door_open.insert({read__tr_open_valve_door_open_state, _trid_3});
                    }
                } else {
                    _trid_3 = _obj__trid_3_ptr->second;
                }
                if(_trid_3) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_open_valve_door_open readState = state._projected_state_for_open_valve_door_open();

                    auto _OpCache_with_parameter_open_valve_door_open_ptr = _OpCache_open_valve_door_open.find(_trid_3);
                    if(_OpCache_with_parameter_open_valve_door_open_ptr == _OpCache_open_valve_door_open.end()) {
                        copiedState.open_valve_door_open();
                        LandingGear_R6::_ProjectionWrite_open_valve_door_open writeState = copiedState._update_for_open_valve_door_open();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_open_valve_door_open, LandingGear_R6::_ProjectionWrite_open_valve_door_open, LandingGear_R6::_ProjectionRead_open_valve_door_open::Hash, LandingGear_R6::_ProjectionRead_open_valve_door_open::HashEqual> _OpCache_with_parameter_open_valve_door_open;
                        _OpCache_with_parameter_open_valve_door_open.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_open_valve_door_open_lock(_ProjectionRead_open_valve_door_open_mutex);
                            _OpCache_open_valve_door_open.insert({_trid_3, _OpCache_with_parameter_open_valve_door_open});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_open_valve_door_open, LandingGear_R6::_ProjectionWrite_open_valve_door_open, LandingGear_R6::_ProjectionRead_open_valve_door_open::Hash, LandingGear_R6::_ProjectionRead_open_valve_door_open::HashEqual> _OpCache_with_parameter_open_valve_door_open = _OpCache_with_parameter_open_valve_door_open_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_open_valve_door_open.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_open_valve_door_open.end()) {
                            LandingGear_R6::_ProjectionWrite_open_valve_door_open writeState = writeState_ptr->second;
                            copiedState._apply_update_for_open_valve_door_open(writeState);
                        } else {
                            copiedState.open_valve_door_open();
                            LandingGear_R6::_ProjectionWrite_open_valve_door_open writeState = copiedState._update_for_open_valve_door_open();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_open_valve_door_open_lock(_ProjectionRead_open_valve_door_open_mutex);
                                _OpCache_with_parameter_open_valve_door_open.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "open_valve_door_open";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_close_valve_door_open read__tr_close_valve_door_open_state = state._projected_state_for__tr_close_valve_door_open();
                bool _trid_4;
                auto _obj__trid_4_ptr = _OpCache_tr_close_valve_door_open.find(read__tr_close_valve_door_open_state);
                if(_obj__trid_4_ptr == _OpCache_tr_close_valve_door_open.end()) {
                    _trid_4 = state._tr_close_valve_door_open();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_close_valve_door_open_lock(_ProjectionRead__tr_close_valve_door_open_mutex);
                        _OpCache_tr_close_valve_door_open.insert({read__tr_close_valve_door_open_state, _trid_4});
                    }
                } else {
                    _trid_4 = _obj__trid_4_ptr->second;
                }
                if(_trid_4) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_close_valve_door_open readState = state._projected_state_for_close_valve_door_open();

                    auto _OpCache_with_parameter_close_valve_door_open_ptr = _OpCache_close_valve_door_open.find(_trid_4);
                    if(_OpCache_with_parameter_close_valve_door_open_ptr == _OpCache_close_valve_door_open.end()) {
                        copiedState.close_valve_door_open();
                        LandingGear_R6::_ProjectionWrite_close_valve_door_open writeState = copiedState._update_for_close_valve_door_open();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_close_valve_door_open, LandingGear_R6::_ProjectionWrite_close_valve_door_open, LandingGear_R6::_ProjectionRead_close_valve_door_open::Hash, LandingGear_R6::_ProjectionRead_close_valve_door_open::HashEqual> _OpCache_with_parameter_close_valve_door_open;
                        _OpCache_with_parameter_close_valve_door_open.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_close_valve_door_open_lock(_ProjectionRead_close_valve_door_open_mutex);
                            _OpCache_close_valve_door_open.insert({_trid_4, _OpCache_with_parameter_close_valve_door_open});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_close_valve_door_open, LandingGear_R6::_ProjectionWrite_close_valve_door_open, LandingGear_R6::_ProjectionRead_close_valve_door_open::Hash, LandingGear_R6::_ProjectionRead_close_valve_door_open::HashEqual> _OpCache_with_parameter_close_valve_door_open = _OpCache_with_parameter_close_valve_door_open_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_close_valve_door_open.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_close_valve_door_open.end()) {
                            LandingGear_R6::_ProjectionWrite_close_valve_door_open writeState = writeState_ptr->second;
                            copiedState._apply_update_for_close_valve_door_open(writeState);
                        } else {
                            copiedState.close_valve_door_open();
                            LandingGear_R6::_ProjectionWrite_close_valve_door_open writeState = copiedState._update_for_close_valve_door_open();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_close_valve_door_open_lock(_ProjectionRead_close_valve_door_open_mutex);
                                _OpCache_with_parameter_close_valve_door_open.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "close_valve_door_open";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_open_valve_door_close read__tr_open_valve_door_close_state = state._projected_state_for__tr_open_valve_door_close();
                bool _trid_5;
                auto _obj__trid_5_ptr = _OpCache_tr_open_valve_door_close.find(read__tr_open_valve_door_close_state);
                if(_obj__trid_5_ptr == _OpCache_tr_open_valve_door_close.end()) {
                    _trid_5 = state._tr_open_valve_door_close();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_open_valve_door_close_lock(_ProjectionRead__tr_open_valve_door_close_mutex);
                        _OpCache_tr_open_valve_door_close.insert({read__tr_open_valve_door_close_state, _trid_5});
                    }
                } else {
                    _trid_5 = _obj__trid_5_ptr->second;
                }
                if(_trid_5) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_open_valve_door_close readState = state._projected_state_for_open_valve_door_close();

                    auto _OpCache_with_parameter_open_valve_door_close_ptr = _OpCache_open_valve_door_close.find(_trid_5);
                    if(_OpCache_with_parameter_open_valve_door_close_ptr == _OpCache_open_valve_door_close.end()) {
                        copiedState.open_valve_door_close();
                        LandingGear_R6::_ProjectionWrite_open_valve_door_close writeState = copiedState._update_for_open_valve_door_close();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_open_valve_door_close, LandingGear_R6::_ProjectionWrite_open_valve_door_close, LandingGear_R6::_ProjectionRead_open_valve_door_close::Hash, LandingGear_R6::_ProjectionRead_open_valve_door_close::HashEqual> _OpCache_with_parameter_open_valve_door_close;
                        _OpCache_with_parameter_open_valve_door_close.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_open_valve_door_close_lock(_ProjectionRead_open_valve_door_close_mutex);
                            _OpCache_open_valve_door_close.insert({_trid_5, _OpCache_with_parameter_open_valve_door_close});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_open_valve_door_close, LandingGear_R6::_ProjectionWrite_open_valve_door_close, LandingGear_R6::_ProjectionRead_open_valve_door_close::Hash, LandingGear_R6::_ProjectionRead_open_valve_door_close::HashEqual> _OpCache_with_parameter_open_valve_door_close = _OpCache_with_parameter_open_valve_door_close_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_open_valve_door_close.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_open_valve_door_close.end()) {
                            LandingGear_R6::_ProjectionWrite_open_valve_door_close writeState = writeState_ptr->second;
                            copiedState._apply_update_for_open_valve_door_close(writeState);
                        } else {
                            copiedState.open_valve_door_close();
                            LandingGear_R6::_ProjectionWrite_open_valve_door_close writeState = copiedState._update_for_open_valve_door_close();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_open_valve_door_close_lock(_ProjectionRead_open_valve_door_close_mutex);
                                _OpCache_with_parameter_open_valve_door_close.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "open_valve_door_close";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_close_valve_door_close read__tr_close_valve_door_close_state = state._projected_state_for__tr_close_valve_door_close();
                bool _trid_6;
                auto _obj__trid_6_ptr = _OpCache_tr_close_valve_door_close.find(read__tr_close_valve_door_close_state);
                if(_obj__trid_6_ptr == _OpCache_tr_close_valve_door_close.end()) {
                    _trid_6 = state._tr_close_valve_door_close();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_close_valve_door_close_lock(_ProjectionRead__tr_close_valve_door_close_mutex);
                        _OpCache_tr_close_valve_door_close.insert({read__tr_close_valve_door_close_state, _trid_6});
                    }
                } else {
                    _trid_6 = _obj__trid_6_ptr->second;
                }
                if(_trid_6) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_close_valve_door_close readState = state._projected_state_for_close_valve_door_close();

                    auto _OpCache_with_parameter_close_valve_door_close_ptr = _OpCache_close_valve_door_close.find(_trid_6);
                    if(_OpCache_with_parameter_close_valve_door_close_ptr == _OpCache_close_valve_door_close.end()) {
                        copiedState.close_valve_door_close();
                        LandingGear_R6::_ProjectionWrite_close_valve_door_close writeState = copiedState._update_for_close_valve_door_close();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_close_valve_door_close, LandingGear_R6::_ProjectionWrite_close_valve_door_close, LandingGear_R6::_ProjectionRead_close_valve_door_close::Hash, LandingGear_R6::_ProjectionRead_close_valve_door_close::HashEqual> _OpCache_with_parameter_close_valve_door_close;
                        _OpCache_with_parameter_close_valve_door_close.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_close_valve_door_close_lock(_ProjectionRead_close_valve_door_close_mutex);
                            _OpCache_close_valve_door_close.insert({_trid_6, _OpCache_with_parameter_close_valve_door_close});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_close_valve_door_close, LandingGear_R6::_ProjectionWrite_close_valve_door_close, LandingGear_R6::_ProjectionRead_close_valve_door_close::Hash, LandingGear_R6::_ProjectionRead_close_valve_door_close::HashEqual> _OpCache_with_parameter_close_valve_door_close = _OpCache_with_parameter_close_valve_door_close_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_close_valve_door_close.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_close_valve_door_close.end()) {
                            LandingGear_R6::_ProjectionWrite_close_valve_door_close writeState = writeState_ptr->second;
                            copiedState._apply_update_for_close_valve_door_close(writeState);
                        } else {
                            copiedState.close_valve_door_close();
                            LandingGear_R6::_ProjectionWrite_close_valve_door_close writeState = copiedState._update_for_close_valve_door_close();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_close_valve_door_close_lock(_ProjectionRead_close_valve_door_close_mutex);
                                _OpCache_with_parameter_close_valve_door_close.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "close_valve_door_close";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_open_valve_retract_gear read__tr_open_valve_retract_gear_state = state._projected_state_for__tr_open_valve_retract_gear();
                bool _trid_7;
                auto _obj__trid_7_ptr = _OpCache_tr_open_valve_retract_gear.find(read__tr_open_valve_retract_gear_state);
                if(_obj__trid_7_ptr == _OpCache_tr_open_valve_retract_gear.end()) {
                    _trid_7 = state._tr_open_valve_retract_gear();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_open_valve_retract_gear_lock(_ProjectionRead__tr_open_valve_retract_gear_mutex);
                        _OpCache_tr_open_valve_retract_gear.insert({read__tr_open_valve_retract_gear_state, _trid_7});
                    }
                } else {
                    _trid_7 = _obj__trid_7_ptr->second;
                }
                if(_trid_7) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_open_valve_retract_gear readState = state._projected_state_for_open_valve_retract_gear();

                    auto _OpCache_with_parameter_open_valve_retract_gear_ptr = _OpCache_open_valve_retract_gear.find(_trid_7);
                    if(_OpCache_with_parameter_open_valve_retract_gear_ptr == _OpCache_open_valve_retract_gear.end()) {
                        copiedState.open_valve_retract_gear();
                        LandingGear_R6::_ProjectionWrite_open_valve_retract_gear writeState = copiedState._update_for_open_valve_retract_gear();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_open_valve_retract_gear, LandingGear_R6::_ProjectionWrite_open_valve_retract_gear, LandingGear_R6::_ProjectionRead_open_valve_retract_gear::Hash, LandingGear_R6::_ProjectionRead_open_valve_retract_gear::HashEqual> _OpCache_with_parameter_open_valve_retract_gear;
                        _OpCache_with_parameter_open_valve_retract_gear.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_open_valve_retract_gear_lock(_ProjectionRead_open_valve_retract_gear_mutex);
                            _OpCache_open_valve_retract_gear.insert({_trid_7, _OpCache_with_parameter_open_valve_retract_gear});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_open_valve_retract_gear, LandingGear_R6::_ProjectionWrite_open_valve_retract_gear, LandingGear_R6::_ProjectionRead_open_valve_retract_gear::Hash, LandingGear_R6::_ProjectionRead_open_valve_retract_gear::HashEqual> _OpCache_with_parameter_open_valve_retract_gear = _OpCache_with_parameter_open_valve_retract_gear_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_open_valve_retract_gear.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_open_valve_retract_gear.end()) {
                            LandingGear_R6::_ProjectionWrite_open_valve_retract_gear writeState = writeState_ptr->second;
                            copiedState._apply_update_for_open_valve_retract_gear(writeState);
                        } else {
                            copiedState.open_valve_retract_gear();
                            LandingGear_R6::_ProjectionWrite_open_valve_retract_gear writeState = copiedState._update_for_open_valve_retract_gear();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_open_valve_retract_gear_lock(_ProjectionRead_open_valve_retract_gear_mutex);
                                _OpCache_with_parameter_open_valve_retract_gear.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "open_valve_retract_gear";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_close_valve_retract_gear read__tr_close_valve_retract_gear_state = state._projected_state_for__tr_close_valve_retract_gear();
                bool _trid_8;
                auto _obj__trid_8_ptr = _OpCache_tr_close_valve_retract_gear.find(read__tr_close_valve_retract_gear_state);
                if(_obj__trid_8_ptr == _OpCache_tr_close_valve_retract_gear.end()) {
                    _trid_8 = state._tr_close_valve_retract_gear();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_close_valve_retract_gear_lock(_ProjectionRead__tr_close_valve_retract_gear_mutex);
                        _OpCache_tr_close_valve_retract_gear.insert({read__tr_close_valve_retract_gear_state, _trid_8});
                    }
                } else {
                    _trid_8 = _obj__trid_8_ptr->second;
                }
                if(_trid_8) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_close_valve_retract_gear readState = state._projected_state_for_close_valve_retract_gear();

                    auto _OpCache_with_parameter_close_valve_retract_gear_ptr = _OpCache_close_valve_retract_gear.find(_trid_8);
                    if(_OpCache_with_parameter_close_valve_retract_gear_ptr == _OpCache_close_valve_retract_gear.end()) {
                        copiedState.close_valve_retract_gear();
                        LandingGear_R6::_ProjectionWrite_close_valve_retract_gear writeState = copiedState._update_for_close_valve_retract_gear();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_close_valve_retract_gear, LandingGear_R6::_ProjectionWrite_close_valve_retract_gear, LandingGear_R6::_ProjectionRead_close_valve_retract_gear::Hash, LandingGear_R6::_ProjectionRead_close_valve_retract_gear::HashEqual> _OpCache_with_parameter_close_valve_retract_gear;
                        _OpCache_with_parameter_close_valve_retract_gear.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_close_valve_retract_gear_lock(_ProjectionRead_close_valve_retract_gear_mutex);
                            _OpCache_close_valve_retract_gear.insert({_trid_8, _OpCache_with_parameter_close_valve_retract_gear});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_close_valve_retract_gear, LandingGear_R6::_ProjectionWrite_close_valve_retract_gear, LandingGear_R6::_ProjectionRead_close_valve_retract_gear::Hash, LandingGear_R6::_ProjectionRead_close_valve_retract_gear::HashEqual> _OpCache_with_parameter_close_valve_retract_gear = _OpCache_with_parameter_close_valve_retract_gear_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_close_valve_retract_gear.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_close_valve_retract_gear.end()) {
                            LandingGear_R6::_ProjectionWrite_close_valve_retract_gear writeState = writeState_ptr->second;
                            copiedState._apply_update_for_close_valve_retract_gear(writeState);
                        } else {
                            copiedState.close_valve_retract_gear();
                            LandingGear_R6::_ProjectionWrite_close_valve_retract_gear writeState = copiedState._update_for_close_valve_retract_gear();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_close_valve_retract_gear_lock(_ProjectionRead_close_valve_retract_gear_mutex);
                                _OpCache_with_parameter_close_valve_retract_gear.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "close_valve_retract_gear";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_open_valve_extend_gear read__tr_open_valve_extend_gear_state = state._projected_state_for__tr_open_valve_extend_gear();
                bool _trid_9;
                auto _obj__trid_9_ptr = _OpCache_tr_open_valve_extend_gear.find(read__tr_open_valve_extend_gear_state);
                if(_obj__trid_9_ptr == _OpCache_tr_open_valve_extend_gear.end()) {
                    _trid_9 = state._tr_open_valve_extend_gear();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_open_valve_extend_gear_lock(_ProjectionRead__tr_open_valve_extend_gear_mutex);
                        _OpCache_tr_open_valve_extend_gear.insert({read__tr_open_valve_extend_gear_state, _trid_9});
                    }
                } else {
                    _trid_9 = _obj__trid_9_ptr->second;
                }
                if(_trid_9) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_open_valve_extend_gear readState = state._projected_state_for_open_valve_extend_gear();

                    auto _OpCache_with_parameter_open_valve_extend_gear_ptr = _OpCache_open_valve_extend_gear.find(_trid_9);
                    if(_OpCache_with_parameter_open_valve_extend_gear_ptr == _OpCache_open_valve_extend_gear.end()) {
                        copiedState.open_valve_extend_gear();
                        LandingGear_R6::_ProjectionWrite_open_valve_extend_gear writeState = copiedState._update_for_open_valve_extend_gear();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_open_valve_extend_gear, LandingGear_R6::_ProjectionWrite_open_valve_extend_gear, LandingGear_R6::_ProjectionRead_open_valve_extend_gear::Hash, LandingGear_R6::_ProjectionRead_open_valve_extend_gear::HashEqual> _OpCache_with_parameter_open_valve_extend_gear;
                        _OpCache_with_parameter_open_valve_extend_gear.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_open_valve_extend_gear_lock(_ProjectionRead_open_valve_extend_gear_mutex);
                            _OpCache_open_valve_extend_gear.insert({_trid_9, _OpCache_with_parameter_open_valve_extend_gear});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_open_valve_extend_gear, LandingGear_R6::_ProjectionWrite_open_valve_extend_gear, LandingGear_R6::_ProjectionRead_open_valve_extend_gear::Hash, LandingGear_R6::_ProjectionRead_open_valve_extend_gear::HashEqual> _OpCache_with_parameter_open_valve_extend_gear = _OpCache_with_parameter_open_valve_extend_gear_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_open_valve_extend_gear.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_open_valve_extend_gear.end()) {
                            LandingGear_R6::_ProjectionWrite_open_valve_extend_gear writeState = writeState_ptr->second;
                            copiedState._apply_update_for_open_valve_extend_gear(writeState);
                        } else {
                            copiedState.open_valve_extend_gear();
                            LandingGear_R6::_ProjectionWrite_open_valve_extend_gear writeState = copiedState._update_for_open_valve_extend_gear();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_open_valve_extend_gear_lock(_ProjectionRead_open_valve_extend_gear_mutex);
                                _OpCache_with_parameter_open_valve_extend_gear.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "open_valve_extend_gear";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_close_valve_extend_gear read__tr_close_valve_extend_gear_state = state._projected_state_for__tr_close_valve_extend_gear();
                bool _trid_10;
                auto _obj__trid_10_ptr = _OpCache_tr_close_valve_extend_gear.find(read__tr_close_valve_extend_gear_state);
                if(_obj__trid_10_ptr == _OpCache_tr_close_valve_extend_gear.end()) {
                    _trid_10 = state._tr_close_valve_extend_gear();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_close_valve_extend_gear_lock(_ProjectionRead__tr_close_valve_extend_gear_mutex);
                        _OpCache_tr_close_valve_extend_gear.insert({read__tr_close_valve_extend_gear_state, _trid_10});
                    }
                } else {
                    _trid_10 = _obj__trid_10_ptr->second;
                }
                if(_trid_10) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_close_valve_extend_gear readState = state._projected_state_for_close_valve_extend_gear();

                    auto _OpCache_with_parameter_close_valve_extend_gear_ptr = _OpCache_close_valve_extend_gear.find(_trid_10);
                    if(_OpCache_with_parameter_close_valve_extend_gear_ptr == _OpCache_close_valve_extend_gear.end()) {
                        copiedState.close_valve_extend_gear();
                        LandingGear_R6::_ProjectionWrite_close_valve_extend_gear writeState = copiedState._update_for_close_valve_extend_gear();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_close_valve_extend_gear, LandingGear_R6::_ProjectionWrite_close_valve_extend_gear, LandingGear_R6::_ProjectionRead_close_valve_extend_gear::Hash, LandingGear_R6::_ProjectionRead_close_valve_extend_gear::HashEqual> _OpCache_with_parameter_close_valve_extend_gear;
                        _OpCache_with_parameter_close_valve_extend_gear.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_close_valve_extend_gear_lock(_ProjectionRead_close_valve_extend_gear_mutex);
                            _OpCache_close_valve_extend_gear.insert({_trid_10, _OpCache_with_parameter_close_valve_extend_gear});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_close_valve_extend_gear, LandingGear_R6::_ProjectionWrite_close_valve_extend_gear, LandingGear_R6::_ProjectionRead_close_valve_extend_gear::Hash, LandingGear_R6::_ProjectionRead_close_valve_extend_gear::HashEqual> _OpCache_with_parameter_close_valve_extend_gear = _OpCache_with_parameter_close_valve_extend_gear_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_close_valve_extend_gear.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_close_valve_extend_gear.end()) {
                            LandingGear_R6::_ProjectionWrite_close_valve_extend_gear writeState = writeState_ptr->second;
                            copiedState._apply_update_for_close_valve_extend_gear(writeState);
                        } else {
                            copiedState.close_valve_extend_gear();
                            LandingGear_R6::_ProjectionWrite_close_valve_extend_gear writeState = copiedState._update_for_close_valve_extend_gear();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_close_valve_extend_gear_lock(_ProjectionRead_close_valve_extend_gear_mutex);
                                _OpCache_with_parameter_close_valve_extend_gear.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "close_valve_extend_gear";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_con_stimulate_open_door_valve read__tr_con_stimulate_open_door_valve_state = state._projected_state_for__tr_con_stimulate_open_door_valve();
                bool _trid_11;
                auto _obj__trid_11_ptr = _OpCache_tr_con_stimulate_open_door_valve.find(read__tr_con_stimulate_open_door_valve_state);
                if(_obj__trid_11_ptr == _OpCache_tr_con_stimulate_open_door_valve.end()) {
                    _trid_11 = state._tr_con_stimulate_open_door_valve();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_con_stimulate_open_door_valve_lock(_ProjectionRead__tr_con_stimulate_open_door_valve_mutex);
                        _OpCache_tr_con_stimulate_open_door_valve.insert({read__tr_con_stimulate_open_door_valve_state, _trid_11});
                    }
                } else {
                    _trid_11 = _obj__trid_11_ptr->second;
                }
                if(_trid_11) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_con_stimulate_open_door_valve readState = state._projected_state_for_con_stimulate_open_door_valve();

                    auto _OpCache_with_parameter_con_stimulate_open_door_valve_ptr = _OpCache_con_stimulate_open_door_valve.find(_trid_11);
                    if(_OpCache_with_parameter_con_stimulate_open_door_valve_ptr == _OpCache_con_stimulate_open_door_valve.end()) {
                        copiedState.con_stimulate_open_door_valve();
                        LandingGear_R6::_ProjectionWrite_con_stimulate_open_door_valve writeState = copiedState._update_for_con_stimulate_open_door_valve();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_con_stimulate_open_door_valve, LandingGear_R6::_ProjectionWrite_con_stimulate_open_door_valve, LandingGear_R6::_ProjectionRead_con_stimulate_open_door_valve::Hash, LandingGear_R6::_ProjectionRead_con_stimulate_open_door_valve::HashEqual> _OpCache_with_parameter_con_stimulate_open_door_valve;
                        _OpCache_with_parameter_con_stimulate_open_door_valve.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_con_stimulate_open_door_valve_lock(_ProjectionRead_con_stimulate_open_door_valve_mutex);
                            _OpCache_con_stimulate_open_door_valve.insert({_trid_11, _OpCache_with_parameter_con_stimulate_open_door_valve});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_con_stimulate_open_door_valve, LandingGear_R6::_ProjectionWrite_con_stimulate_open_door_valve, LandingGear_R6::_ProjectionRead_con_stimulate_open_door_valve::Hash, LandingGear_R6::_ProjectionRead_con_stimulate_open_door_valve::HashEqual> _OpCache_with_parameter_con_stimulate_open_door_valve = _OpCache_with_parameter_con_stimulate_open_door_valve_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_con_stimulate_open_door_valve.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_con_stimulate_open_door_valve.end()) {
                            LandingGear_R6::_ProjectionWrite_con_stimulate_open_door_valve writeState = writeState_ptr->second;
                            copiedState._apply_update_for_con_stimulate_open_door_valve(writeState);
                        } else {
                            copiedState.con_stimulate_open_door_valve();
                            LandingGear_R6::_ProjectionWrite_con_stimulate_open_door_valve writeState = copiedState._update_for_con_stimulate_open_door_valve();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_con_stimulate_open_door_valve_lock(_ProjectionRead_con_stimulate_open_door_valve_mutex);
                                _OpCache_with_parameter_con_stimulate_open_door_valve.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "con_stimulate_open_door_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_con_stop_stimulate_open_door_valve read__tr_con_stop_stimulate_open_door_valve_state = state._projected_state_for__tr_con_stop_stimulate_open_door_valve();
                bool _trid_12;
                auto _obj__trid_12_ptr = _OpCache_tr_con_stop_stimulate_open_door_valve.find(read__tr_con_stop_stimulate_open_door_valve_state);
                if(_obj__trid_12_ptr == _OpCache_tr_con_stop_stimulate_open_door_valve.end()) {
                    _trid_12 = state._tr_con_stop_stimulate_open_door_valve();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_con_stop_stimulate_open_door_valve_lock(_ProjectionRead__tr_con_stop_stimulate_open_door_valve_mutex);
                        _OpCache_tr_con_stop_stimulate_open_door_valve.insert({read__tr_con_stop_stimulate_open_door_valve_state, _trid_12});
                    }
                } else {
                    _trid_12 = _obj__trid_12_ptr->second;
                }
                if(_trid_12) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_con_stop_stimulate_open_door_valve readState = state._projected_state_for_con_stop_stimulate_open_door_valve();

                    auto _OpCache_with_parameter_con_stop_stimulate_open_door_valve_ptr = _OpCache_con_stop_stimulate_open_door_valve.find(_trid_12);
                    if(_OpCache_with_parameter_con_stop_stimulate_open_door_valve_ptr == _OpCache_con_stop_stimulate_open_door_valve.end()) {
                        copiedState.con_stop_stimulate_open_door_valve();
                        LandingGear_R6::_ProjectionWrite_con_stop_stimulate_open_door_valve writeState = copiedState._update_for_con_stop_stimulate_open_door_valve();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_con_stop_stimulate_open_door_valve, LandingGear_R6::_ProjectionWrite_con_stop_stimulate_open_door_valve, LandingGear_R6::_ProjectionRead_con_stop_stimulate_open_door_valve::Hash, LandingGear_R6::_ProjectionRead_con_stop_stimulate_open_door_valve::HashEqual> _OpCache_with_parameter_con_stop_stimulate_open_door_valve;
                        _OpCache_with_parameter_con_stop_stimulate_open_door_valve.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_con_stop_stimulate_open_door_valve_lock(_ProjectionRead_con_stop_stimulate_open_door_valve_mutex);
                            _OpCache_con_stop_stimulate_open_door_valve.insert({_trid_12, _OpCache_with_parameter_con_stop_stimulate_open_door_valve});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_con_stop_stimulate_open_door_valve, LandingGear_R6::_ProjectionWrite_con_stop_stimulate_open_door_valve, LandingGear_R6::_ProjectionRead_con_stop_stimulate_open_door_valve::Hash, LandingGear_R6::_ProjectionRead_con_stop_stimulate_open_door_valve::HashEqual> _OpCache_with_parameter_con_stop_stimulate_open_door_valve = _OpCache_with_parameter_con_stop_stimulate_open_door_valve_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_con_stop_stimulate_open_door_valve.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_con_stop_stimulate_open_door_valve.end()) {
                            LandingGear_R6::_ProjectionWrite_con_stop_stimulate_open_door_valve writeState = writeState_ptr->second;
                            copiedState._apply_update_for_con_stop_stimulate_open_door_valve(writeState);
                        } else {
                            copiedState.con_stop_stimulate_open_door_valve();
                            LandingGear_R6::_ProjectionWrite_con_stop_stimulate_open_door_valve writeState = copiedState._update_for_con_stop_stimulate_open_door_valve();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_con_stop_stimulate_open_door_valve_lock(_ProjectionRead_con_stop_stimulate_open_door_valve_mutex);
                                _OpCache_with_parameter_con_stop_stimulate_open_door_valve.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "con_stop_stimulate_open_door_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_con_stimulate_close_door_valve read__tr_con_stimulate_close_door_valve_state = state._projected_state_for__tr_con_stimulate_close_door_valve();
                bool _trid_13;
                auto _obj__trid_13_ptr = _OpCache_tr_con_stimulate_close_door_valve.find(read__tr_con_stimulate_close_door_valve_state);
                if(_obj__trid_13_ptr == _OpCache_tr_con_stimulate_close_door_valve.end()) {
                    _trid_13 = state._tr_con_stimulate_close_door_valve();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_con_stimulate_close_door_valve_lock(_ProjectionRead__tr_con_stimulate_close_door_valve_mutex);
                        _OpCache_tr_con_stimulate_close_door_valve.insert({read__tr_con_stimulate_close_door_valve_state, _trid_13});
                    }
                } else {
                    _trid_13 = _obj__trid_13_ptr->second;
                }
                if(_trid_13) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_con_stimulate_close_door_valve readState = state._projected_state_for_con_stimulate_close_door_valve();

                    auto _OpCache_with_parameter_con_stimulate_close_door_valve_ptr = _OpCache_con_stimulate_close_door_valve.find(_trid_13);
                    if(_OpCache_with_parameter_con_stimulate_close_door_valve_ptr == _OpCache_con_stimulate_close_door_valve.end()) {
                        copiedState.con_stimulate_close_door_valve();
                        LandingGear_R6::_ProjectionWrite_con_stimulate_close_door_valve writeState = copiedState._update_for_con_stimulate_close_door_valve();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_con_stimulate_close_door_valve, LandingGear_R6::_ProjectionWrite_con_stimulate_close_door_valve, LandingGear_R6::_ProjectionRead_con_stimulate_close_door_valve::Hash, LandingGear_R6::_ProjectionRead_con_stimulate_close_door_valve::HashEqual> _OpCache_with_parameter_con_stimulate_close_door_valve;
                        _OpCache_with_parameter_con_stimulate_close_door_valve.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_con_stimulate_close_door_valve_lock(_ProjectionRead_con_stimulate_close_door_valve_mutex);
                            _OpCache_con_stimulate_close_door_valve.insert({_trid_13, _OpCache_with_parameter_con_stimulate_close_door_valve});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_con_stimulate_close_door_valve, LandingGear_R6::_ProjectionWrite_con_stimulate_close_door_valve, LandingGear_R6::_ProjectionRead_con_stimulate_close_door_valve::Hash, LandingGear_R6::_ProjectionRead_con_stimulate_close_door_valve::HashEqual> _OpCache_with_parameter_con_stimulate_close_door_valve = _OpCache_with_parameter_con_stimulate_close_door_valve_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_con_stimulate_close_door_valve.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_con_stimulate_close_door_valve.end()) {
                            LandingGear_R6::_ProjectionWrite_con_stimulate_close_door_valve writeState = writeState_ptr->second;
                            copiedState._apply_update_for_con_stimulate_close_door_valve(writeState);
                        } else {
                            copiedState.con_stimulate_close_door_valve();
                            LandingGear_R6::_ProjectionWrite_con_stimulate_close_door_valve writeState = copiedState._update_for_con_stimulate_close_door_valve();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_con_stimulate_close_door_valve_lock(_ProjectionRead_con_stimulate_close_door_valve_mutex);
                                _OpCache_with_parameter_con_stimulate_close_door_valve.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "con_stimulate_close_door_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_con_stop_stimulate_close_door_valve read__tr_con_stop_stimulate_close_door_valve_state = state._projected_state_for__tr_con_stop_stimulate_close_door_valve();
                bool _trid_14;
                auto _obj__trid_14_ptr = _OpCache_tr_con_stop_stimulate_close_door_valve.find(read__tr_con_stop_stimulate_close_door_valve_state);
                if(_obj__trid_14_ptr == _OpCache_tr_con_stop_stimulate_close_door_valve.end()) {
                    _trid_14 = state._tr_con_stop_stimulate_close_door_valve();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_con_stop_stimulate_close_door_valve_lock(_ProjectionRead__tr_con_stop_stimulate_close_door_valve_mutex);
                        _OpCache_tr_con_stop_stimulate_close_door_valve.insert({read__tr_con_stop_stimulate_close_door_valve_state, _trid_14});
                    }
                } else {
                    _trid_14 = _obj__trid_14_ptr->second;
                }
                if(_trid_14) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_con_stop_stimulate_close_door_valve readState = state._projected_state_for_con_stop_stimulate_close_door_valve();

                    auto _OpCache_with_parameter_con_stop_stimulate_close_door_valve_ptr = _OpCache_con_stop_stimulate_close_door_valve.find(_trid_14);
                    if(_OpCache_with_parameter_con_stop_stimulate_close_door_valve_ptr == _OpCache_con_stop_stimulate_close_door_valve.end()) {
                        copiedState.con_stop_stimulate_close_door_valve();
                        LandingGear_R6::_ProjectionWrite_con_stop_stimulate_close_door_valve writeState = copiedState._update_for_con_stop_stimulate_close_door_valve();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_con_stop_stimulate_close_door_valve, LandingGear_R6::_ProjectionWrite_con_stop_stimulate_close_door_valve, LandingGear_R6::_ProjectionRead_con_stop_stimulate_close_door_valve::Hash, LandingGear_R6::_ProjectionRead_con_stop_stimulate_close_door_valve::HashEqual> _OpCache_with_parameter_con_stop_stimulate_close_door_valve;
                        _OpCache_with_parameter_con_stop_stimulate_close_door_valve.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_con_stop_stimulate_close_door_valve_lock(_ProjectionRead_con_stop_stimulate_close_door_valve_mutex);
                            _OpCache_con_stop_stimulate_close_door_valve.insert({_trid_14, _OpCache_with_parameter_con_stop_stimulate_close_door_valve});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_con_stop_stimulate_close_door_valve, LandingGear_R6::_ProjectionWrite_con_stop_stimulate_close_door_valve, LandingGear_R6::_ProjectionRead_con_stop_stimulate_close_door_valve::Hash, LandingGear_R6::_ProjectionRead_con_stop_stimulate_close_door_valve::HashEqual> _OpCache_with_parameter_con_stop_stimulate_close_door_valve = _OpCache_with_parameter_con_stop_stimulate_close_door_valve_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_con_stop_stimulate_close_door_valve.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_con_stop_stimulate_close_door_valve.end()) {
                            LandingGear_R6::_ProjectionWrite_con_stop_stimulate_close_door_valve writeState = writeState_ptr->second;
                            copiedState._apply_update_for_con_stop_stimulate_close_door_valve(writeState);
                        } else {
                            copiedState.con_stop_stimulate_close_door_valve();
                            LandingGear_R6::_ProjectionWrite_con_stop_stimulate_close_door_valve writeState = copiedState._update_for_con_stop_stimulate_close_door_valve();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_con_stop_stimulate_close_door_valve_lock(_ProjectionRead_con_stop_stimulate_close_door_valve_mutex);
                                _OpCache_with_parameter_con_stop_stimulate_close_door_valve.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "con_stop_stimulate_close_door_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_con_stimulate_retract_gear_valve read__tr_con_stimulate_retract_gear_valve_state = state._projected_state_for__tr_con_stimulate_retract_gear_valve();
                bool _trid_15;
                auto _obj__trid_15_ptr = _OpCache_tr_con_stimulate_retract_gear_valve.find(read__tr_con_stimulate_retract_gear_valve_state);
                if(_obj__trid_15_ptr == _OpCache_tr_con_stimulate_retract_gear_valve.end()) {
                    _trid_15 = state._tr_con_stimulate_retract_gear_valve();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_con_stimulate_retract_gear_valve_lock(_ProjectionRead__tr_con_stimulate_retract_gear_valve_mutex);
                        _OpCache_tr_con_stimulate_retract_gear_valve.insert({read__tr_con_stimulate_retract_gear_valve_state, _trid_15});
                    }
                } else {
                    _trid_15 = _obj__trid_15_ptr->second;
                }
                if(_trid_15) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_con_stimulate_retract_gear_valve readState = state._projected_state_for_con_stimulate_retract_gear_valve();

                    auto _OpCache_with_parameter_con_stimulate_retract_gear_valve_ptr = _OpCache_con_stimulate_retract_gear_valve.find(_trid_15);
                    if(_OpCache_with_parameter_con_stimulate_retract_gear_valve_ptr == _OpCache_con_stimulate_retract_gear_valve.end()) {
                        copiedState.con_stimulate_retract_gear_valve();
                        LandingGear_R6::_ProjectionWrite_con_stimulate_retract_gear_valve writeState = copiedState._update_for_con_stimulate_retract_gear_valve();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_con_stimulate_retract_gear_valve, LandingGear_R6::_ProjectionWrite_con_stimulate_retract_gear_valve, LandingGear_R6::_ProjectionRead_con_stimulate_retract_gear_valve::Hash, LandingGear_R6::_ProjectionRead_con_stimulate_retract_gear_valve::HashEqual> _OpCache_with_parameter_con_stimulate_retract_gear_valve;
                        _OpCache_with_parameter_con_stimulate_retract_gear_valve.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_con_stimulate_retract_gear_valve_lock(_ProjectionRead_con_stimulate_retract_gear_valve_mutex);
                            _OpCache_con_stimulate_retract_gear_valve.insert({_trid_15, _OpCache_with_parameter_con_stimulate_retract_gear_valve});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_con_stimulate_retract_gear_valve, LandingGear_R6::_ProjectionWrite_con_stimulate_retract_gear_valve, LandingGear_R6::_ProjectionRead_con_stimulate_retract_gear_valve::Hash, LandingGear_R6::_ProjectionRead_con_stimulate_retract_gear_valve::HashEqual> _OpCache_with_parameter_con_stimulate_retract_gear_valve = _OpCache_with_parameter_con_stimulate_retract_gear_valve_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_con_stimulate_retract_gear_valve.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_con_stimulate_retract_gear_valve.end()) {
                            LandingGear_R6::_ProjectionWrite_con_stimulate_retract_gear_valve writeState = writeState_ptr->second;
                            copiedState._apply_update_for_con_stimulate_retract_gear_valve(writeState);
                        } else {
                            copiedState.con_stimulate_retract_gear_valve();
                            LandingGear_R6::_ProjectionWrite_con_stimulate_retract_gear_valve writeState = copiedState._update_for_con_stimulate_retract_gear_valve();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_con_stimulate_retract_gear_valve_lock(_ProjectionRead_con_stimulate_retract_gear_valve_mutex);
                                _OpCache_with_parameter_con_stimulate_retract_gear_valve.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "con_stimulate_retract_gear_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_con_stop_stimulate_retract_gear_valve read__tr_con_stop_stimulate_retract_gear_valve_state = state._projected_state_for__tr_con_stop_stimulate_retract_gear_valve();
                bool _trid_16;
                auto _obj__trid_16_ptr = _OpCache_tr_con_stop_stimulate_retract_gear_valve.find(read__tr_con_stop_stimulate_retract_gear_valve_state);
                if(_obj__trid_16_ptr == _OpCache_tr_con_stop_stimulate_retract_gear_valve.end()) {
                    _trid_16 = state._tr_con_stop_stimulate_retract_gear_valve();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve_lock(_ProjectionRead__tr_con_stop_stimulate_retract_gear_valve_mutex);
                        _OpCache_tr_con_stop_stimulate_retract_gear_valve.insert({read__tr_con_stop_stimulate_retract_gear_valve_state, _trid_16});
                    }
                } else {
                    _trid_16 = _obj__trid_16_ptr->second;
                }
                if(_trid_16) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_con_stop_stimulate_retract_gear_valve readState = state._projected_state_for_con_stop_stimulate_retract_gear_valve();

                    auto _OpCache_with_parameter_con_stop_stimulate_retract_gear_valve_ptr = _OpCache_con_stop_stimulate_retract_gear_valve.find(_trid_16);
                    if(_OpCache_with_parameter_con_stop_stimulate_retract_gear_valve_ptr == _OpCache_con_stop_stimulate_retract_gear_valve.end()) {
                        copiedState.con_stop_stimulate_retract_gear_valve();
                        LandingGear_R6::_ProjectionWrite_con_stop_stimulate_retract_gear_valve writeState = copiedState._update_for_con_stop_stimulate_retract_gear_valve();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_con_stop_stimulate_retract_gear_valve, LandingGear_R6::_ProjectionWrite_con_stop_stimulate_retract_gear_valve, LandingGear_R6::_ProjectionRead_con_stop_stimulate_retract_gear_valve::Hash, LandingGear_R6::_ProjectionRead_con_stop_stimulate_retract_gear_valve::HashEqual> _OpCache_with_parameter_con_stop_stimulate_retract_gear_valve;
                        _OpCache_with_parameter_con_stop_stimulate_retract_gear_valve.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_con_stop_stimulate_retract_gear_valve_lock(_ProjectionRead_con_stop_stimulate_retract_gear_valve_mutex);
                            _OpCache_con_stop_stimulate_retract_gear_valve.insert({_trid_16, _OpCache_with_parameter_con_stop_stimulate_retract_gear_valve});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_con_stop_stimulate_retract_gear_valve, LandingGear_R6::_ProjectionWrite_con_stop_stimulate_retract_gear_valve, LandingGear_R6::_ProjectionRead_con_stop_stimulate_retract_gear_valve::Hash, LandingGear_R6::_ProjectionRead_con_stop_stimulate_retract_gear_valve::HashEqual> _OpCache_with_parameter_con_stop_stimulate_retract_gear_valve = _OpCache_with_parameter_con_stop_stimulate_retract_gear_valve_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_con_stop_stimulate_retract_gear_valve.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_con_stop_stimulate_retract_gear_valve.end()) {
                            LandingGear_R6::_ProjectionWrite_con_stop_stimulate_retract_gear_valve writeState = writeState_ptr->second;
                            copiedState._apply_update_for_con_stop_stimulate_retract_gear_valve(writeState);
                        } else {
                            copiedState.con_stop_stimulate_retract_gear_valve();
                            LandingGear_R6::_ProjectionWrite_con_stop_stimulate_retract_gear_valve writeState = copiedState._update_for_con_stop_stimulate_retract_gear_valve();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_con_stop_stimulate_retract_gear_valve_lock(_ProjectionRead_con_stop_stimulate_retract_gear_valve_mutex);
                                _OpCache_with_parameter_con_stop_stimulate_retract_gear_valve.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "con_stop_stimulate_retract_gear_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_con_stimulate_extend_gear_valve read__tr_con_stimulate_extend_gear_valve_state = state._projected_state_for__tr_con_stimulate_extend_gear_valve();
                bool _trid_17;
                auto _obj__trid_17_ptr = _OpCache_tr_con_stimulate_extend_gear_valve.find(read__tr_con_stimulate_extend_gear_valve_state);
                if(_obj__trid_17_ptr == _OpCache_tr_con_stimulate_extend_gear_valve.end()) {
                    _trid_17 = state._tr_con_stimulate_extend_gear_valve();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_con_stimulate_extend_gear_valve_lock(_ProjectionRead__tr_con_stimulate_extend_gear_valve_mutex);
                        _OpCache_tr_con_stimulate_extend_gear_valve.insert({read__tr_con_stimulate_extend_gear_valve_state, _trid_17});
                    }
                } else {
                    _trid_17 = _obj__trid_17_ptr->second;
                }
                if(_trid_17) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_con_stimulate_extend_gear_valve readState = state._projected_state_for_con_stimulate_extend_gear_valve();

                    auto _OpCache_with_parameter_con_stimulate_extend_gear_valve_ptr = _OpCache_con_stimulate_extend_gear_valve.find(_trid_17);
                    if(_OpCache_with_parameter_con_stimulate_extend_gear_valve_ptr == _OpCache_con_stimulate_extend_gear_valve.end()) {
                        copiedState.con_stimulate_extend_gear_valve();
                        LandingGear_R6::_ProjectionWrite_con_stimulate_extend_gear_valve writeState = copiedState._update_for_con_stimulate_extend_gear_valve();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_con_stimulate_extend_gear_valve, LandingGear_R6::_ProjectionWrite_con_stimulate_extend_gear_valve, LandingGear_R6::_ProjectionRead_con_stimulate_extend_gear_valve::Hash, LandingGear_R6::_ProjectionRead_con_stimulate_extend_gear_valve::HashEqual> _OpCache_with_parameter_con_stimulate_extend_gear_valve;
                        _OpCache_with_parameter_con_stimulate_extend_gear_valve.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_con_stimulate_extend_gear_valve_lock(_ProjectionRead_con_stimulate_extend_gear_valve_mutex);
                            _OpCache_con_stimulate_extend_gear_valve.insert({_trid_17, _OpCache_with_parameter_con_stimulate_extend_gear_valve});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_con_stimulate_extend_gear_valve, LandingGear_R6::_ProjectionWrite_con_stimulate_extend_gear_valve, LandingGear_R6::_ProjectionRead_con_stimulate_extend_gear_valve::Hash, LandingGear_R6::_ProjectionRead_con_stimulate_extend_gear_valve::HashEqual> _OpCache_with_parameter_con_stimulate_extend_gear_valve = _OpCache_with_parameter_con_stimulate_extend_gear_valve_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_con_stimulate_extend_gear_valve.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_con_stimulate_extend_gear_valve.end()) {
                            LandingGear_R6::_ProjectionWrite_con_stimulate_extend_gear_valve writeState = writeState_ptr->second;
                            copiedState._apply_update_for_con_stimulate_extend_gear_valve(writeState);
                        } else {
                            copiedState.con_stimulate_extend_gear_valve();
                            LandingGear_R6::_ProjectionWrite_con_stimulate_extend_gear_valve writeState = copiedState._update_for_con_stimulate_extend_gear_valve();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_con_stimulate_extend_gear_valve_lock(_ProjectionRead_con_stimulate_extend_gear_valve_mutex);
                                _OpCache_with_parameter_con_stimulate_extend_gear_valve.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "con_stimulate_extend_gear_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_con_stop_stimulate_extend_gear_valve read__tr_con_stop_stimulate_extend_gear_valve_state = state._projected_state_for__tr_con_stop_stimulate_extend_gear_valve();
                bool _trid_18;
                auto _obj__trid_18_ptr = _OpCache_tr_con_stop_stimulate_extend_gear_valve.find(read__tr_con_stop_stimulate_extend_gear_valve_state);
                if(_obj__trid_18_ptr == _OpCache_tr_con_stop_stimulate_extend_gear_valve.end()) {
                    _trid_18 = state._tr_con_stop_stimulate_extend_gear_valve();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve_lock(_ProjectionRead__tr_con_stop_stimulate_extend_gear_valve_mutex);
                        _OpCache_tr_con_stop_stimulate_extend_gear_valve.insert({read__tr_con_stop_stimulate_extend_gear_valve_state, _trid_18});
                    }
                } else {
                    _trid_18 = _obj__trid_18_ptr->second;
                }
                if(_trid_18) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_con_stop_stimulate_extend_gear_valve readState = state._projected_state_for_con_stop_stimulate_extend_gear_valve();

                    auto _OpCache_with_parameter_con_stop_stimulate_extend_gear_valve_ptr = _OpCache_con_stop_stimulate_extend_gear_valve.find(_trid_18);
                    if(_OpCache_with_parameter_con_stop_stimulate_extend_gear_valve_ptr == _OpCache_con_stop_stimulate_extend_gear_valve.end()) {
                        copiedState.con_stop_stimulate_extend_gear_valve();
                        LandingGear_R6::_ProjectionWrite_con_stop_stimulate_extend_gear_valve writeState = copiedState._update_for_con_stop_stimulate_extend_gear_valve();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_con_stop_stimulate_extend_gear_valve, LandingGear_R6::_ProjectionWrite_con_stop_stimulate_extend_gear_valve, LandingGear_R6::_ProjectionRead_con_stop_stimulate_extend_gear_valve::Hash, LandingGear_R6::_ProjectionRead_con_stop_stimulate_extend_gear_valve::HashEqual> _OpCache_with_parameter_con_stop_stimulate_extend_gear_valve;
                        _OpCache_with_parameter_con_stop_stimulate_extend_gear_valve.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_con_stop_stimulate_extend_gear_valve_lock(_ProjectionRead_con_stop_stimulate_extend_gear_valve_mutex);
                            _OpCache_con_stop_stimulate_extend_gear_valve.insert({_trid_18, _OpCache_with_parameter_con_stop_stimulate_extend_gear_valve});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_con_stop_stimulate_extend_gear_valve, LandingGear_R6::_ProjectionWrite_con_stop_stimulate_extend_gear_valve, LandingGear_R6::_ProjectionRead_con_stop_stimulate_extend_gear_valve::Hash, LandingGear_R6::_ProjectionRead_con_stop_stimulate_extend_gear_valve::HashEqual> _OpCache_with_parameter_con_stop_stimulate_extend_gear_valve = _OpCache_with_parameter_con_stop_stimulate_extend_gear_valve_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_con_stop_stimulate_extend_gear_valve.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_con_stop_stimulate_extend_gear_valve.end()) {
                            LandingGear_R6::_ProjectionWrite_con_stop_stimulate_extend_gear_valve writeState = writeState_ptr->second;
                            copiedState._apply_update_for_con_stop_stimulate_extend_gear_valve(writeState);
                        } else {
                            copiedState.con_stop_stimulate_extend_gear_valve();
                            LandingGear_R6::_ProjectionWrite_con_stop_stimulate_extend_gear_valve writeState = copiedState._update_for_con_stop_stimulate_extend_gear_valve();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_con_stop_stimulate_extend_gear_valve_lock(_ProjectionRead_con_stop_stimulate_extend_gear_valve_mutex);
                                _OpCache_with_parameter_con_stop_stimulate_extend_gear_valve.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "con_stop_stimulate_extend_gear_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_env_start_retracting_first read__tr_env_start_retracting_first_state = state._projected_state_for__tr_env_start_retracting_first();
                auto _trid_19_ptr = _OpCache_tr_env_start_retracting_first.find(read__tr_env_start_retracting_first_state);
                if(_trid_19_ptr == _OpCache_tr_env_start_retracting_first.end()) {
                    BSet<LandingGear_R6::POSITION> _trid_19 = state._tr_env_start_retracting_first();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_env_start_retracting_first_lock(_ProjectionRead__tr_env_start_retracting_first_mutex);
                        _OpCache_tr_env_start_retracting_first.insert({read__tr_env_start_retracting_first_state, _trid_19});
                    }
                    for(const LandingGear_R6::POSITION& param : _trid_19) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_start_retracting_first readState = state._projected_state_for_env_start_retracting_first();

                        auto _OpCache_with_parameter_env_start_retracting_first_ptr = _OpCache_env_start_retracting_first.find(param);
                        if(_OpCache_with_parameter_env_start_retracting_first_ptr == _OpCache_env_start_retracting_first.end()) {
                            copiedState.env_start_retracting_first(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_start_retracting_first writeState = copiedState._update_for_env_start_retracting_first();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_start_retracting_first, LandingGear_R6::_ProjectionWrite_env_start_retracting_first, LandingGear_R6::_ProjectionRead_env_start_retracting_first::Hash, LandingGear_R6::_ProjectionRead_env_start_retracting_first::HashEqual> _OpCache_with_parameter_env_start_retracting_first;
                            _OpCache_with_parameter_env_start_retracting_first.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_start_retracting_first_lock(_ProjectionRead_env_start_retracting_first_mutex);
                                _OpCache_env_start_retracting_first.insert({param, _OpCache_with_parameter_env_start_retracting_first});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_start_retracting_first, LandingGear_R6::_ProjectionWrite_env_start_retracting_first, LandingGear_R6::_ProjectionRead_env_start_retracting_first::Hash, LandingGear_R6::_ProjectionRead_env_start_retracting_first::HashEqual> _OpCache_with_parameter_env_start_retracting_first = _OpCache_with_parameter_env_start_retracting_first_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_start_retracting_first.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_start_retracting_first.end()) {
                                LandingGear_R6::_ProjectionWrite_env_start_retracting_first writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_start_retracting_first(writeState);
                            } else {
                                copiedState.env_start_retracting_first(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_start_retracting_first writeState = copiedState._update_for_env_start_retracting_first();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_start_retracting_first_lock(_ProjectionRead_env_start_retracting_first_mutex);
                                    _OpCache_with_parameter_env_start_retracting_first.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_start_retracting_first";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<LandingGear_R6::POSITION> _trid_19 = _trid_19_ptr->second;
                    for(const LandingGear_R6::POSITION& param : _trid_19) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_start_retracting_first readState = state._projected_state_for_env_start_retracting_first();

                        auto _OpCache_with_parameter_env_start_retracting_first_ptr = _OpCache_env_start_retracting_first.find(param);
                        if(_OpCache_with_parameter_env_start_retracting_first_ptr == _OpCache_env_start_retracting_first.end()) {
                            copiedState.env_start_retracting_first(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_start_retracting_first writeState = copiedState._update_for_env_start_retracting_first();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_start_retracting_first, LandingGear_R6::_ProjectionWrite_env_start_retracting_first, LandingGear_R6::_ProjectionRead_env_start_retracting_first::Hash, LandingGear_R6::_ProjectionRead_env_start_retracting_first::HashEqual> _OpCache_with_parameter_env_start_retracting_first;
                            _OpCache_with_parameter_env_start_retracting_first.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_start_retracting_first_lock(_ProjectionRead_env_start_retracting_first_mutex);
                                _OpCache_env_start_retracting_first.insert({param, _OpCache_with_parameter_env_start_retracting_first});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_start_retracting_first, LandingGear_R6::_ProjectionWrite_env_start_retracting_first, LandingGear_R6::_ProjectionRead_env_start_retracting_first::Hash, LandingGear_R6::_ProjectionRead_env_start_retracting_first::HashEqual> _OpCache_with_parameter_env_start_retracting_first = _OpCache_with_parameter_env_start_retracting_first_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_start_retracting_first.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_start_retracting_first.end()) {
                                LandingGear_R6::_ProjectionWrite_env_start_retracting_first writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_start_retracting_first(writeState);
                            } else {
                                copiedState.env_start_retracting_first(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_start_retracting_first writeState = copiedState._update_for_env_start_retracting_first();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_start_retracting_first_lock(_ProjectionRead_env_start_retracting_first_mutex);
                                    _OpCache_with_parameter_env_start_retracting_first.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_start_retracting_first";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                LandingGear_R6::_ProjectionRead__tr_env_retract_gear_skip read__tr_env_retract_gear_skip_state = state._projected_state_for__tr_env_retract_gear_skip();
                auto _trid_20_ptr = _OpCache_tr_env_retract_gear_skip.find(read__tr_env_retract_gear_skip_state);
                if(_trid_20_ptr == _OpCache_tr_env_retract_gear_skip.end()) {
                    BSet<LandingGear_R6::POSITION> _trid_20 = state._tr_env_retract_gear_skip();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_env_retract_gear_skip_lock(_ProjectionRead__tr_env_retract_gear_skip_mutex);
                        _OpCache_tr_env_retract_gear_skip.insert({read__tr_env_retract_gear_skip_state, _trid_20});
                    }
                    for(const LandingGear_R6::POSITION& param : _trid_20) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_retract_gear_skip readState = state._projected_state_for_env_retract_gear_skip();

                        auto _OpCache_with_parameter_env_retract_gear_skip_ptr = _OpCache_env_retract_gear_skip.find(param);
                        if(_OpCache_with_parameter_env_retract_gear_skip_ptr == _OpCache_env_retract_gear_skip.end()) {
                            copiedState.env_retract_gear_skip(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_retract_gear_skip writeState = copiedState._update_for_env_retract_gear_skip();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_retract_gear_skip, LandingGear_R6::_ProjectionWrite_env_retract_gear_skip, LandingGear_R6::_ProjectionRead_env_retract_gear_skip::Hash, LandingGear_R6::_ProjectionRead_env_retract_gear_skip::HashEqual> _OpCache_with_parameter_env_retract_gear_skip;
                            _OpCache_with_parameter_env_retract_gear_skip.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_retract_gear_skip_lock(_ProjectionRead_env_retract_gear_skip_mutex);
                                _OpCache_env_retract_gear_skip.insert({param, _OpCache_with_parameter_env_retract_gear_skip});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_retract_gear_skip, LandingGear_R6::_ProjectionWrite_env_retract_gear_skip, LandingGear_R6::_ProjectionRead_env_retract_gear_skip::Hash, LandingGear_R6::_ProjectionRead_env_retract_gear_skip::HashEqual> _OpCache_with_parameter_env_retract_gear_skip = _OpCache_with_parameter_env_retract_gear_skip_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_retract_gear_skip.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_retract_gear_skip.end()) {
                                LandingGear_R6::_ProjectionWrite_env_retract_gear_skip writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_retract_gear_skip(writeState);
                            } else {
                                copiedState.env_retract_gear_skip(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_retract_gear_skip writeState = copiedState._update_for_env_retract_gear_skip();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_retract_gear_skip_lock(_ProjectionRead_env_retract_gear_skip_mutex);
                                    _OpCache_with_parameter_env_retract_gear_skip.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_retract_gear_skip";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<LandingGear_R6::POSITION> _trid_20 = _trid_20_ptr->second;
                    for(const LandingGear_R6::POSITION& param : _trid_20) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_retract_gear_skip readState = state._projected_state_for_env_retract_gear_skip();

                        auto _OpCache_with_parameter_env_retract_gear_skip_ptr = _OpCache_env_retract_gear_skip.find(param);
                        if(_OpCache_with_parameter_env_retract_gear_skip_ptr == _OpCache_env_retract_gear_skip.end()) {
                            copiedState.env_retract_gear_skip(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_retract_gear_skip writeState = copiedState._update_for_env_retract_gear_skip();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_retract_gear_skip, LandingGear_R6::_ProjectionWrite_env_retract_gear_skip, LandingGear_R6::_ProjectionRead_env_retract_gear_skip::Hash, LandingGear_R6::_ProjectionRead_env_retract_gear_skip::HashEqual> _OpCache_with_parameter_env_retract_gear_skip;
                            _OpCache_with_parameter_env_retract_gear_skip.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_retract_gear_skip_lock(_ProjectionRead_env_retract_gear_skip_mutex);
                                _OpCache_env_retract_gear_skip.insert({param, _OpCache_with_parameter_env_retract_gear_skip});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_retract_gear_skip, LandingGear_R6::_ProjectionWrite_env_retract_gear_skip, LandingGear_R6::_ProjectionRead_env_retract_gear_skip::Hash, LandingGear_R6::_ProjectionRead_env_retract_gear_skip::HashEqual> _OpCache_with_parameter_env_retract_gear_skip = _OpCache_with_parameter_env_retract_gear_skip_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_retract_gear_skip.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_retract_gear_skip.end()) {
                                LandingGear_R6::_ProjectionWrite_env_retract_gear_skip writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_retract_gear_skip(writeState);
                            } else {
                                copiedState.env_retract_gear_skip(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_retract_gear_skip writeState = copiedState._update_for_env_retract_gear_skip();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_retract_gear_skip_lock(_ProjectionRead_env_retract_gear_skip_mutex);
                                    _OpCache_with_parameter_env_retract_gear_skip.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_retract_gear_skip";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                LandingGear_R6::_ProjectionRead__tr_env_retract_gear_last read__tr_env_retract_gear_last_state = state._projected_state_for__tr_env_retract_gear_last();
                auto _trid_21_ptr = _OpCache_tr_env_retract_gear_last.find(read__tr_env_retract_gear_last_state);
                if(_trid_21_ptr == _OpCache_tr_env_retract_gear_last.end()) {
                    BSet<LandingGear_R6::POSITION> _trid_21 = state._tr_env_retract_gear_last();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_env_retract_gear_last_lock(_ProjectionRead__tr_env_retract_gear_last_mutex);
                        _OpCache_tr_env_retract_gear_last.insert({read__tr_env_retract_gear_last_state, _trid_21});
                    }
                    for(const LandingGear_R6::POSITION& param : _trid_21) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_retract_gear_last readState = state._projected_state_for_env_retract_gear_last();

                        auto _OpCache_with_parameter_env_retract_gear_last_ptr = _OpCache_env_retract_gear_last.find(param);
                        if(_OpCache_with_parameter_env_retract_gear_last_ptr == _OpCache_env_retract_gear_last.end()) {
                            copiedState.env_retract_gear_last(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_retract_gear_last writeState = copiedState._update_for_env_retract_gear_last();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_retract_gear_last, LandingGear_R6::_ProjectionWrite_env_retract_gear_last, LandingGear_R6::_ProjectionRead_env_retract_gear_last::Hash, LandingGear_R6::_ProjectionRead_env_retract_gear_last::HashEqual> _OpCache_with_parameter_env_retract_gear_last;
                            _OpCache_with_parameter_env_retract_gear_last.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_retract_gear_last_lock(_ProjectionRead_env_retract_gear_last_mutex);
                                _OpCache_env_retract_gear_last.insert({param, _OpCache_with_parameter_env_retract_gear_last});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_retract_gear_last, LandingGear_R6::_ProjectionWrite_env_retract_gear_last, LandingGear_R6::_ProjectionRead_env_retract_gear_last::Hash, LandingGear_R6::_ProjectionRead_env_retract_gear_last::HashEqual> _OpCache_with_parameter_env_retract_gear_last = _OpCache_with_parameter_env_retract_gear_last_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_retract_gear_last.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_retract_gear_last.end()) {
                                LandingGear_R6::_ProjectionWrite_env_retract_gear_last writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_retract_gear_last(writeState);
                            } else {
                                copiedState.env_retract_gear_last(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_retract_gear_last writeState = copiedState._update_for_env_retract_gear_last();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_retract_gear_last_lock(_ProjectionRead_env_retract_gear_last_mutex);
                                    _OpCache_with_parameter_env_retract_gear_last.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_retract_gear_last";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<LandingGear_R6::POSITION> _trid_21 = _trid_21_ptr->second;
                    for(const LandingGear_R6::POSITION& param : _trid_21) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_retract_gear_last readState = state._projected_state_for_env_retract_gear_last();

                        auto _OpCache_with_parameter_env_retract_gear_last_ptr = _OpCache_env_retract_gear_last.find(param);
                        if(_OpCache_with_parameter_env_retract_gear_last_ptr == _OpCache_env_retract_gear_last.end()) {
                            copiedState.env_retract_gear_last(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_retract_gear_last writeState = copiedState._update_for_env_retract_gear_last();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_retract_gear_last, LandingGear_R6::_ProjectionWrite_env_retract_gear_last, LandingGear_R6::_ProjectionRead_env_retract_gear_last::Hash, LandingGear_R6::_ProjectionRead_env_retract_gear_last::HashEqual> _OpCache_with_parameter_env_retract_gear_last;
                            _OpCache_with_parameter_env_retract_gear_last.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_retract_gear_last_lock(_ProjectionRead_env_retract_gear_last_mutex);
                                _OpCache_env_retract_gear_last.insert({param, _OpCache_with_parameter_env_retract_gear_last});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_retract_gear_last, LandingGear_R6::_ProjectionWrite_env_retract_gear_last, LandingGear_R6::_ProjectionRead_env_retract_gear_last::Hash, LandingGear_R6::_ProjectionRead_env_retract_gear_last::HashEqual> _OpCache_with_parameter_env_retract_gear_last = _OpCache_with_parameter_env_retract_gear_last_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_retract_gear_last.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_retract_gear_last.end()) {
                                LandingGear_R6::_ProjectionWrite_env_retract_gear_last writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_retract_gear_last(writeState);
                            } else {
                                copiedState.env_retract_gear_last(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_retract_gear_last writeState = copiedState._update_for_env_retract_gear_last();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_retract_gear_last_lock(_ProjectionRead_env_retract_gear_last_mutex);
                                    _OpCache_with_parameter_env_retract_gear_last.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_retract_gear_last";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                LandingGear_R6::_ProjectionRead__tr_env_start_extending read__tr_env_start_extending_state = state._projected_state_for__tr_env_start_extending();
                auto _trid_22_ptr = _OpCache_tr_env_start_extending.find(read__tr_env_start_extending_state);
                if(_trid_22_ptr == _OpCache_tr_env_start_extending.end()) {
                    BSet<LandingGear_R6::POSITION> _trid_22 = state._tr_env_start_extending();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_env_start_extending_lock(_ProjectionRead__tr_env_start_extending_mutex);
                        _OpCache_tr_env_start_extending.insert({read__tr_env_start_extending_state, _trid_22});
                    }
                    for(const LandingGear_R6::POSITION& param : _trid_22) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_start_extending readState = state._projected_state_for_env_start_extending();

                        auto _OpCache_with_parameter_env_start_extending_ptr = _OpCache_env_start_extending.find(param);
                        if(_OpCache_with_parameter_env_start_extending_ptr == _OpCache_env_start_extending.end()) {
                            copiedState.env_start_extending(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_start_extending writeState = copiedState._update_for_env_start_extending();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_start_extending, LandingGear_R6::_ProjectionWrite_env_start_extending, LandingGear_R6::_ProjectionRead_env_start_extending::Hash, LandingGear_R6::_ProjectionRead_env_start_extending::HashEqual> _OpCache_with_parameter_env_start_extending;
                            _OpCache_with_parameter_env_start_extending.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_start_extending_lock(_ProjectionRead_env_start_extending_mutex);
                                _OpCache_env_start_extending.insert({param, _OpCache_with_parameter_env_start_extending});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_start_extending, LandingGear_R6::_ProjectionWrite_env_start_extending, LandingGear_R6::_ProjectionRead_env_start_extending::Hash, LandingGear_R6::_ProjectionRead_env_start_extending::HashEqual> _OpCache_with_parameter_env_start_extending = _OpCache_with_parameter_env_start_extending_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_start_extending.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_start_extending.end()) {
                                LandingGear_R6::_ProjectionWrite_env_start_extending writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_start_extending(writeState);
                            } else {
                                copiedState.env_start_extending(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_start_extending writeState = copiedState._update_for_env_start_extending();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_start_extending_lock(_ProjectionRead_env_start_extending_mutex);
                                    _OpCache_with_parameter_env_start_extending.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_start_extending";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<LandingGear_R6::POSITION> _trid_22 = _trid_22_ptr->second;
                    for(const LandingGear_R6::POSITION& param : _trid_22) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_start_extending readState = state._projected_state_for_env_start_extending();

                        auto _OpCache_with_parameter_env_start_extending_ptr = _OpCache_env_start_extending.find(param);
                        if(_OpCache_with_parameter_env_start_extending_ptr == _OpCache_env_start_extending.end()) {
                            copiedState.env_start_extending(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_start_extending writeState = copiedState._update_for_env_start_extending();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_start_extending, LandingGear_R6::_ProjectionWrite_env_start_extending, LandingGear_R6::_ProjectionRead_env_start_extending::Hash, LandingGear_R6::_ProjectionRead_env_start_extending::HashEqual> _OpCache_with_parameter_env_start_extending;
                            _OpCache_with_parameter_env_start_extending.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_start_extending_lock(_ProjectionRead_env_start_extending_mutex);
                                _OpCache_env_start_extending.insert({param, _OpCache_with_parameter_env_start_extending});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_start_extending, LandingGear_R6::_ProjectionWrite_env_start_extending, LandingGear_R6::_ProjectionRead_env_start_extending::Hash, LandingGear_R6::_ProjectionRead_env_start_extending::HashEqual> _OpCache_with_parameter_env_start_extending = _OpCache_with_parameter_env_start_extending_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_start_extending.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_start_extending.end()) {
                                LandingGear_R6::_ProjectionWrite_env_start_extending writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_start_extending(writeState);
                            } else {
                                copiedState.env_start_extending(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_start_extending writeState = copiedState._update_for_env_start_extending();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_start_extending_lock(_ProjectionRead_env_start_extending_mutex);
                                    _OpCache_with_parameter_env_start_extending.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_start_extending";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                LandingGear_R6::_ProjectionRead__tr_env_extend_gear_last read__tr_env_extend_gear_last_state = state._projected_state_for__tr_env_extend_gear_last();
                auto _trid_23_ptr = _OpCache_tr_env_extend_gear_last.find(read__tr_env_extend_gear_last_state);
                if(_trid_23_ptr == _OpCache_tr_env_extend_gear_last.end()) {
                    BSet<LandingGear_R6::POSITION> _trid_23 = state._tr_env_extend_gear_last();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_env_extend_gear_last_lock(_ProjectionRead__tr_env_extend_gear_last_mutex);
                        _OpCache_tr_env_extend_gear_last.insert({read__tr_env_extend_gear_last_state, _trid_23});
                    }
                    for(const LandingGear_R6::POSITION& param : _trid_23) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_extend_gear_last readState = state._projected_state_for_env_extend_gear_last();

                        auto _OpCache_with_parameter_env_extend_gear_last_ptr = _OpCache_env_extend_gear_last.find(param);
                        if(_OpCache_with_parameter_env_extend_gear_last_ptr == _OpCache_env_extend_gear_last.end()) {
                            copiedState.env_extend_gear_last(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_extend_gear_last writeState = copiedState._update_for_env_extend_gear_last();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_extend_gear_last, LandingGear_R6::_ProjectionWrite_env_extend_gear_last, LandingGear_R6::_ProjectionRead_env_extend_gear_last::Hash, LandingGear_R6::_ProjectionRead_env_extend_gear_last::HashEqual> _OpCache_with_parameter_env_extend_gear_last;
                            _OpCache_with_parameter_env_extend_gear_last.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_extend_gear_last_lock(_ProjectionRead_env_extend_gear_last_mutex);
                                _OpCache_env_extend_gear_last.insert({param, _OpCache_with_parameter_env_extend_gear_last});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_extend_gear_last, LandingGear_R6::_ProjectionWrite_env_extend_gear_last, LandingGear_R6::_ProjectionRead_env_extend_gear_last::Hash, LandingGear_R6::_ProjectionRead_env_extend_gear_last::HashEqual> _OpCache_with_parameter_env_extend_gear_last = _OpCache_with_parameter_env_extend_gear_last_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_extend_gear_last.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_extend_gear_last.end()) {
                                LandingGear_R6::_ProjectionWrite_env_extend_gear_last writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_extend_gear_last(writeState);
                            } else {
                                copiedState.env_extend_gear_last(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_extend_gear_last writeState = copiedState._update_for_env_extend_gear_last();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_extend_gear_last_lock(_ProjectionRead_env_extend_gear_last_mutex);
                                    _OpCache_with_parameter_env_extend_gear_last.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_extend_gear_last";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<LandingGear_R6::POSITION> _trid_23 = _trid_23_ptr->second;
                    for(const LandingGear_R6::POSITION& param : _trid_23) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_extend_gear_last readState = state._projected_state_for_env_extend_gear_last();

                        auto _OpCache_with_parameter_env_extend_gear_last_ptr = _OpCache_env_extend_gear_last.find(param);
                        if(_OpCache_with_parameter_env_extend_gear_last_ptr == _OpCache_env_extend_gear_last.end()) {
                            copiedState.env_extend_gear_last(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_extend_gear_last writeState = copiedState._update_for_env_extend_gear_last();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_extend_gear_last, LandingGear_R6::_ProjectionWrite_env_extend_gear_last, LandingGear_R6::_ProjectionRead_env_extend_gear_last::Hash, LandingGear_R6::_ProjectionRead_env_extend_gear_last::HashEqual> _OpCache_with_parameter_env_extend_gear_last;
                            _OpCache_with_parameter_env_extend_gear_last.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_extend_gear_last_lock(_ProjectionRead_env_extend_gear_last_mutex);
                                _OpCache_env_extend_gear_last.insert({param, _OpCache_with_parameter_env_extend_gear_last});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_extend_gear_last, LandingGear_R6::_ProjectionWrite_env_extend_gear_last, LandingGear_R6::_ProjectionRead_env_extend_gear_last::Hash, LandingGear_R6::_ProjectionRead_env_extend_gear_last::HashEqual> _OpCache_with_parameter_env_extend_gear_last = _OpCache_with_parameter_env_extend_gear_last_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_extend_gear_last.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_extend_gear_last.end()) {
                                LandingGear_R6::_ProjectionWrite_env_extend_gear_last writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_extend_gear_last(writeState);
                            } else {
                                copiedState.env_extend_gear_last(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_extend_gear_last writeState = copiedState._update_for_env_extend_gear_last();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_extend_gear_last_lock(_ProjectionRead_env_extend_gear_last_mutex);
                                    _OpCache_with_parameter_env_extend_gear_last.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_extend_gear_last";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                LandingGear_R6::_ProjectionRead__tr_env_extend_gear_skip read__tr_env_extend_gear_skip_state = state._projected_state_for__tr_env_extend_gear_skip();
                auto _trid_24_ptr = _OpCache_tr_env_extend_gear_skip.find(read__tr_env_extend_gear_skip_state);
                if(_trid_24_ptr == _OpCache_tr_env_extend_gear_skip.end()) {
                    BSet<LandingGear_R6::POSITION> _trid_24 = state._tr_env_extend_gear_skip();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_env_extend_gear_skip_lock(_ProjectionRead__tr_env_extend_gear_skip_mutex);
                        _OpCache_tr_env_extend_gear_skip.insert({read__tr_env_extend_gear_skip_state, _trid_24});
                    }
                    for(const LandingGear_R6::POSITION& param : _trid_24) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_extend_gear_skip readState = state._projected_state_for_env_extend_gear_skip();

                        auto _OpCache_with_parameter_env_extend_gear_skip_ptr = _OpCache_env_extend_gear_skip.find(param);
                        if(_OpCache_with_parameter_env_extend_gear_skip_ptr == _OpCache_env_extend_gear_skip.end()) {
                            copiedState.env_extend_gear_skip(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_extend_gear_skip writeState = copiedState._update_for_env_extend_gear_skip();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_extend_gear_skip, LandingGear_R6::_ProjectionWrite_env_extend_gear_skip, LandingGear_R6::_ProjectionRead_env_extend_gear_skip::Hash, LandingGear_R6::_ProjectionRead_env_extend_gear_skip::HashEqual> _OpCache_with_parameter_env_extend_gear_skip;
                            _OpCache_with_parameter_env_extend_gear_skip.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_extend_gear_skip_lock(_ProjectionRead_env_extend_gear_skip_mutex);
                                _OpCache_env_extend_gear_skip.insert({param, _OpCache_with_parameter_env_extend_gear_skip});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_extend_gear_skip, LandingGear_R6::_ProjectionWrite_env_extend_gear_skip, LandingGear_R6::_ProjectionRead_env_extend_gear_skip::Hash, LandingGear_R6::_ProjectionRead_env_extend_gear_skip::HashEqual> _OpCache_with_parameter_env_extend_gear_skip = _OpCache_with_parameter_env_extend_gear_skip_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_extend_gear_skip.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_extend_gear_skip.end()) {
                                LandingGear_R6::_ProjectionWrite_env_extend_gear_skip writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_extend_gear_skip(writeState);
                            } else {
                                copiedState.env_extend_gear_skip(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_extend_gear_skip writeState = copiedState._update_for_env_extend_gear_skip();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_extend_gear_skip_lock(_ProjectionRead_env_extend_gear_skip_mutex);
                                    _OpCache_with_parameter_env_extend_gear_skip.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_extend_gear_skip";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<LandingGear_R6::POSITION> _trid_24 = _trid_24_ptr->second;
                    for(const LandingGear_R6::POSITION& param : _trid_24) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_extend_gear_skip readState = state._projected_state_for_env_extend_gear_skip();

                        auto _OpCache_with_parameter_env_extend_gear_skip_ptr = _OpCache_env_extend_gear_skip.find(param);
                        if(_OpCache_with_parameter_env_extend_gear_skip_ptr == _OpCache_env_extend_gear_skip.end()) {
                            copiedState.env_extend_gear_skip(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_extend_gear_skip writeState = copiedState._update_for_env_extend_gear_skip();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_extend_gear_skip, LandingGear_R6::_ProjectionWrite_env_extend_gear_skip, LandingGear_R6::_ProjectionRead_env_extend_gear_skip::Hash, LandingGear_R6::_ProjectionRead_env_extend_gear_skip::HashEqual> _OpCache_with_parameter_env_extend_gear_skip;
                            _OpCache_with_parameter_env_extend_gear_skip.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_extend_gear_skip_lock(_ProjectionRead_env_extend_gear_skip_mutex);
                                _OpCache_env_extend_gear_skip.insert({param, _OpCache_with_parameter_env_extend_gear_skip});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_extend_gear_skip, LandingGear_R6::_ProjectionWrite_env_extend_gear_skip, LandingGear_R6::_ProjectionRead_env_extend_gear_skip::Hash, LandingGear_R6::_ProjectionRead_env_extend_gear_skip::HashEqual> _OpCache_with_parameter_env_extend_gear_skip = _OpCache_with_parameter_env_extend_gear_skip_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_extend_gear_skip.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_extend_gear_skip.end()) {
                                LandingGear_R6::_ProjectionWrite_env_extend_gear_skip writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_extend_gear_skip(writeState);
                            } else {
                                copiedState.env_extend_gear_skip(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_extend_gear_skip writeState = copiedState._update_for_env_extend_gear_skip();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_extend_gear_skip_lock(_ProjectionRead_env_extend_gear_skip_mutex);
                                    _OpCache_with_parameter_env_extend_gear_skip.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_extend_gear_skip";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                LandingGear_R6::_ProjectionRead__tr_env_start_open_door read__tr_env_start_open_door_state = state._projected_state_for__tr_env_start_open_door();
                auto _trid_25_ptr = _OpCache_tr_env_start_open_door.find(read__tr_env_start_open_door_state);
                if(_trid_25_ptr == _OpCache_tr_env_start_open_door.end()) {
                    BSet<LandingGear_R6::POSITION> _trid_25 = state._tr_env_start_open_door();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_env_start_open_door_lock(_ProjectionRead__tr_env_start_open_door_mutex);
                        _OpCache_tr_env_start_open_door.insert({read__tr_env_start_open_door_state, _trid_25});
                    }
                    for(const LandingGear_R6::POSITION& param : _trid_25) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_start_open_door readState = state._projected_state_for_env_start_open_door();

                        auto _OpCache_with_parameter_env_start_open_door_ptr = _OpCache_env_start_open_door.find(param);
                        if(_OpCache_with_parameter_env_start_open_door_ptr == _OpCache_env_start_open_door.end()) {
                            copiedState.env_start_open_door(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_start_open_door writeState = copiedState._update_for_env_start_open_door();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_start_open_door, LandingGear_R6::_ProjectionWrite_env_start_open_door, LandingGear_R6::_ProjectionRead_env_start_open_door::Hash, LandingGear_R6::_ProjectionRead_env_start_open_door::HashEqual> _OpCache_with_parameter_env_start_open_door;
                            _OpCache_with_parameter_env_start_open_door.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_start_open_door_lock(_ProjectionRead_env_start_open_door_mutex);
                                _OpCache_env_start_open_door.insert({param, _OpCache_with_parameter_env_start_open_door});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_start_open_door, LandingGear_R6::_ProjectionWrite_env_start_open_door, LandingGear_R6::_ProjectionRead_env_start_open_door::Hash, LandingGear_R6::_ProjectionRead_env_start_open_door::HashEqual> _OpCache_with_parameter_env_start_open_door = _OpCache_with_parameter_env_start_open_door_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_start_open_door.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_start_open_door.end()) {
                                LandingGear_R6::_ProjectionWrite_env_start_open_door writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_start_open_door(writeState);
                            } else {
                                copiedState.env_start_open_door(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_start_open_door writeState = copiedState._update_for_env_start_open_door();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_start_open_door_lock(_ProjectionRead_env_start_open_door_mutex);
                                    _OpCache_with_parameter_env_start_open_door.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_start_open_door";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<LandingGear_R6::POSITION> _trid_25 = _trid_25_ptr->second;
                    for(const LandingGear_R6::POSITION& param : _trid_25) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_start_open_door readState = state._projected_state_for_env_start_open_door();

                        auto _OpCache_with_parameter_env_start_open_door_ptr = _OpCache_env_start_open_door.find(param);
                        if(_OpCache_with_parameter_env_start_open_door_ptr == _OpCache_env_start_open_door.end()) {
                            copiedState.env_start_open_door(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_start_open_door writeState = copiedState._update_for_env_start_open_door();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_start_open_door, LandingGear_R6::_ProjectionWrite_env_start_open_door, LandingGear_R6::_ProjectionRead_env_start_open_door::Hash, LandingGear_R6::_ProjectionRead_env_start_open_door::HashEqual> _OpCache_with_parameter_env_start_open_door;
                            _OpCache_with_parameter_env_start_open_door.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_start_open_door_lock(_ProjectionRead_env_start_open_door_mutex);
                                _OpCache_env_start_open_door.insert({param, _OpCache_with_parameter_env_start_open_door});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_start_open_door, LandingGear_R6::_ProjectionWrite_env_start_open_door, LandingGear_R6::_ProjectionRead_env_start_open_door::Hash, LandingGear_R6::_ProjectionRead_env_start_open_door::HashEqual> _OpCache_with_parameter_env_start_open_door = _OpCache_with_parameter_env_start_open_door_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_start_open_door.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_start_open_door.end()) {
                                LandingGear_R6::_ProjectionWrite_env_start_open_door writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_start_open_door(writeState);
                            } else {
                                copiedState.env_start_open_door(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_start_open_door writeState = copiedState._update_for_env_start_open_door();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_start_open_door_lock(_ProjectionRead_env_start_open_door_mutex);
                                    _OpCache_with_parameter_env_start_open_door.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_start_open_door";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                LandingGear_R6::_ProjectionRead__tr_env_open_door_last read__tr_env_open_door_last_state = state._projected_state_for__tr_env_open_door_last();
                auto _trid_26_ptr = _OpCache_tr_env_open_door_last.find(read__tr_env_open_door_last_state);
                if(_trid_26_ptr == _OpCache_tr_env_open_door_last.end()) {
                    BSet<LandingGear_R6::POSITION> _trid_26 = state._tr_env_open_door_last();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_env_open_door_last_lock(_ProjectionRead__tr_env_open_door_last_mutex);
                        _OpCache_tr_env_open_door_last.insert({read__tr_env_open_door_last_state, _trid_26});
                    }
                    for(const LandingGear_R6::POSITION& param : _trid_26) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_open_door_last readState = state._projected_state_for_env_open_door_last();

                        auto _OpCache_with_parameter_env_open_door_last_ptr = _OpCache_env_open_door_last.find(param);
                        if(_OpCache_with_parameter_env_open_door_last_ptr == _OpCache_env_open_door_last.end()) {
                            copiedState.env_open_door_last(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_open_door_last writeState = copiedState._update_for_env_open_door_last();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_open_door_last, LandingGear_R6::_ProjectionWrite_env_open_door_last, LandingGear_R6::_ProjectionRead_env_open_door_last::Hash, LandingGear_R6::_ProjectionRead_env_open_door_last::HashEqual> _OpCache_with_parameter_env_open_door_last;
                            _OpCache_with_parameter_env_open_door_last.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_open_door_last_lock(_ProjectionRead_env_open_door_last_mutex);
                                _OpCache_env_open_door_last.insert({param, _OpCache_with_parameter_env_open_door_last});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_open_door_last, LandingGear_R6::_ProjectionWrite_env_open_door_last, LandingGear_R6::_ProjectionRead_env_open_door_last::Hash, LandingGear_R6::_ProjectionRead_env_open_door_last::HashEqual> _OpCache_with_parameter_env_open_door_last = _OpCache_with_parameter_env_open_door_last_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_open_door_last.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_open_door_last.end()) {
                                LandingGear_R6::_ProjectionWrite_env_open_door_last writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_open_door_last(writeState);
                            } else {
                                copiedState.env_open_door_last(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_open_door_last writeState = copiedState._update_for_env_open_door_last();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_open_door_last_lock(_ProjectionRead_env_open_door_last_mutex);
                                    _OpCache_with_parameter_env_open_door_last.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_open_door_last";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<LandingGear_R6::POSITION> _trid_26 = _trid_26_ptr->second;
                    for(const LandingGear_R6::POSITION& param : _trid_26) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_open_door_last readState = state._projected_state_for_env_open_door_last();

                        auto _OpCache_with_parameter_env_open_door_last_ptr = _OpCache_env_open_door_last.find(param);
                        if(_OpCache_with_parameter_env_open_door_last_ptr == _OpCache_env_open_door_last.end()) {
                            copiedState.env_open_door_last(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_open_door_last writeState = copiedState._update_for_env_open_door_last();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_open_door_last, LandingGear_R6::_ProjectionWrite_env_open_door_last, LandingGear_R6::_ProjectionRead_env_open_door_last::Hash, LandingGear_R6::_ProjectionRead_env_open_door_last::HashEqual> _OpCache_with_parameter_env_open_door_last;
                            _OpCache_with_parameter_env_open_door_last.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_open_door_last_lock(_ProjectionRead_env_open_door_last_mutex);
                                _OpCache_env_open_door_last.insert({param, _OpCache_with_parameter_env_open_door_last});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_open_door_last, LandingGear_R6::_ProjectionWrite_env_open_door_last, LandingGear_R6::_ProjectionRead_env_open_door_last::Hash, LandingGear_R6::_ProjectionRead_env_open_door_last::HashEqual> _OpCache_with_parameter_env_open_door_last = _OpCache_with_parameter_env_open_door_last_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_open_door_last.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_open_door_last.end()) {
                                LandingGear_R6::_ProjectionWrite_env_open_door_last writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_open_door_last(writeState);
                            } else {
                                copiedState.env_open_door_last(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_open_door_last writeState = copiedState._update_for_env_open_door_last();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_open_door_last_lock(_ProjectionRead_env_open_door_last_mutex);
                                    _OpCache_with_parameter_env_open_door_last.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_open_door_last";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                LandingGear_R6::_ProjectionRead__tr_env_open_door_skip read__tr_env_open_door_skip_state = state._projected_state_for__tr_env_open_door_skip();
                auto _trid_27_ptr = _OpCache_tr_env_open_door_skip.find(read__tr_env_open_door_skip_state);
                if(_trid_27_ptr == _OpCache_tr_env_open_door_skip.end()) {
                    BSet<LandingGear_R6::POSITION> _trid_27 = state._tr_env_open_door_skip();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_env_open_door_skip_lock(_ProjectionRead__tr_env_open_door_skip_mutex);
                        _OpCache_tr_env_open_door_skip.insert({read__tr_env_open_door_skip_state, _trid_27});
                    }
                    for(const LandingGear_R6::POSITION& param : _trid_27) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_open_door_skip readState = state._projected_state_for_env_open_door_skip();

                        auto _OpCache_with_parameter_env_open_door_skip_ptr = _OpCache_env_open_door_skip.find(param);
                        if(_OpCache_with_parameter_env_open_door_skip_ptr == _OpCache_env_open_door_skip.end()) {
                            copiedState.env_open_door_skip(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_open_door_skip writeState = copiedState._update_for_env_open_door_skip();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_open_door_skip, LandingGear_R6::_ProjectionWrite_env_open_door_skip, LandingGear_R6::_ProjectionRead_env_open_door_skip::Hash, LandingGear_R6::_ProjectionRead_env_open_door_skip::HashEqual> _OpCache_with_parameter_env_open_door_skip;
                            _OpCache_with_parameter_env_open_door_skip.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_open_door_skip_lock(_ProjectionRead_env_open_door_skip_mutex);
                                _OpCache_env_open_door_skip.insert({param, _OpCache_with_parameter_env_open_door_skip});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_open_door_skip, LandingGear_R6::_ProjectionWrite_env_open_door_skip, LandingGear_R6::_ProjectionRead_env_open_door_skip::Hash, LandingGear_R6::_ProjectionRead_env_open_door_skip::HashEqual> _OpCache_with_parameter_env_open_door_skip = _OpCache_with_parameter_env_open_door_skip_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_open_door_skip.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_open_door_skip.end()) {
                                LandingGear_R6::_ProjectionWrite_env_open_door_skip writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_open_door_skip(writeState);
                            } else {
                                copiedState.env_open_door_skip(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_open_door_skip writeState = copiedState._update_for_env_open_door_skip();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_open_door_skip_lock(_ProjectionRead_env_open_door_skip_mutex);
                                    _OpCache_with_parameter_env_open_door_skip.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_open_door_skip";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<LandingGear_R6::POSITION> _trid_27 = _trid_27_ptr->second;
                    for(const LandingGear_R6::POSITION& param : _trid_27) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_open_door_skip readState = state._projected_state_for_env_open_door_skip();

                        auto _OpCache_with_parameter_env_open_door_skip_ptr = _OpCache_env_open_door_skip.find(param);
                        if(_OpCache_with_parameter_env_open_door_skip_ptr == _OpCache_env_open_door_skip.end()) {
                            copiedState.env_open_door_skip(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_open_door_skip writeState = copiedState._update_for_env_open_door_skip();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_open_door_skip, LandingGear_R6::_ProjectionWrite_env_open_door_skip, LandingGear_R6::_ProjectionRead_env_open_door_skip::Hash, LandingGear_R6::_ProjectionRead_env_open_door_skip::HashEqual> _OpCache_with_parameter_env_open_door_skip;
                            _OpCache_with_parameter_env_open_door_skip.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_open_door_skip_lock(_ProjectionRead_env_open_door_skip_mutex);
                                _OpCache_env_open_door_skip.insert({param, _OpCache_with_parameter_env_open_door_skip});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_open_door_skip, LandingGear_R6::_ProjectionWrite_env_open_door_skip, LandingGear_R6::_ProjectionRead_env_open_door_skip::Hash, LandingGear_R6::_ProjectionRead_env_open_door_skip::HashEqual> _OpCache_with_parameter_env_open_door_skip = _OpCache_with_parameter_env_open_door_skip_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_open_door_skip.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_open_door_skip.end()) {
                                LandingGear_R6::_ProjectionWrite_env_open_door_skip writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_open_door_skip(writeState);
                            } else {
                                copiedState.env_open_door_skip(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_open_door_skip writeState = copiedState._update_for_env_open_door_skip();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_open_door_skip_lock(_ProjectionRead_env_open_door_skip_mutex);
                                    _OpCache_with_parameter_env_open_door_skip.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_open_door_skip";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                LandingGear_R6::_ProjectionRead__tr_env_start_close_door read__tr_env_start_close_door_state = state._projected_state_for__tr_env_start_close_door();
                auto _trid_28_ptr = _OpCache_tr_env_start_close_door.find(read__tr_env_start_close_door_state);
                if(_trid_28_ptr == _OpCache_tr_env_start_close_door.end()) {
                    BSet<LandingGear_R6::POSITION> _trid_28 = state._tr_env_start_close_door();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_env_start_close_door_lock(_ProjectionRead__tr_env_start_close_door_mutex);
                        _OpCache_tr_env_start_close_door.insert({read__tr_env_start_close_door_state, _trid_28});
                    }
                    for(const LandingGear_R6::POSITION& param : _trid_28) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_start_close_door readState = state._projected_state_for_env_start_close_door();

                        auto _OpCache_with_parameter_env_start_close_door_ptr = _OpCache_env_start_close_door.find(param);
                        if(_OpCache_with_parameter_env_start_close_door_ptr == _OpCache_env_start_close_door.end()) {
                            copiedState.env_start_close_door(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_start_close_door writeState = copiedState._update_for_env_start_close_door();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_start_close_door, LandingGear_R6::_ProjectionWrite_env_start_close_door, LandingGear_R6::_ProjectionRead_env_start_close_door::Hash, LandingGear_R6::_ProjectionRead_env_start_close_door::HashEqual> _OpCache_with_parameter_env_start_close_door;
                            _OpCache_with_parameter_env_start_close_door.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_start_close_door_lock(_ProjectionRead_env_start_close_door_mutex);
                                _OpCache_env_start_close_door.insert({param, _OpCache_with_parameter_env_start_close_door});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_start_close_door, LandingGear_R6::_ProjectionWrite_env_start_close_door, LandingGear_R6::_ProjectionRead_env_start_close_door::Hash, LandingGear_R6::_ProjectionRead_env_start_close_door::HashEqual> _OpCache_with_parameter_env_start_close_door = _OpCache_with_parameter_env_start_close_door_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_start_close_door.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_start_close_door.end()) {
                                LandingGear_R6::_ProjectionWrite_env_start_close_door writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_start_close_door(writeState);
                            } else {
                                copiedState.env_start_close_door(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_start_close_door writeState = copiedState._update_for_env_start_close_door();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_start_close_door_lock(_ProjectionRead_env_start_close_door_mutex);
                                    _OpCache_with_parameter_env_start_close_door.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_start_close_door";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<LandingGear_R6::POSITION> _trid_28 = _trid_28_ptr->second;
                    for(const LandingGear_R6::POSITION& param : _trid_28) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_start_close_door readState = state._projected_state_for_env_start_close_door();

                        auto _OpCache_with_parameter_env_start_close_door_ptr = _OpCache_env_start_close_door.find(param);
                        if(_OpCache_with_parameter_env_start_close_door_ptr == _OpCache_env_start_close_door.end()) {
                            copiedState.env_start_close_door(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_start_close_door writeState = copiedState._update_for_env_start_close_door();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_start_close_door, LandingGear_R6::_ProjectionWrite_env_start_close_door, LandingGear_R6::_ProjectionRead_env_start_close_door::Hash, LandingGear_R6::_ProjectionRead_env_start_close_door::HashEqual> _OpCache_with_parameter_env_start_close_door;
                            _OpCache_with_parameter_env_start_close_door.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_start_close_door_lock(_ProjectionRead_env_start_close_door_mutex);
                                _OpCache_env_start_close_door.insert({param, _OpCache_with_parameter_env_start_close_door});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_start_close_door, LandingGear_R6::_ProjectionWrite_env_start_close_door, LandingGear_R6::_ProjectionRead_env_start_close_door::Hash, LandingGear_R6::_ProjectionRead_env_start_close_door::HashEqual> _OpCache_with_parameter_env_start_close_door = _OpCache_with_parameter_env_start_close_door_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_start_close_door.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_start_close_door.end()) {
                                LandingGear_R6::_ProjectionWrite_env_start_close_door writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_start_close_door(writeState);
                            } else {
                                copiedState.env_start_close_door(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_start_close_door writeState = copiedState._update_for_env_start_close_door();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_start_close_door_lock(_ProjectionRead_env_start_close_door_mutex);
                                    _OpCache_with_parameter_env_start_close_door.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_start_close_door";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                LandingGear_R6::_ProjectionRead__tr_env_close_door read__tr_env_close_door_state = state._projected_state_for__tr_env_close_door();
                auto _trid_29_ptr = _OpCache_tr_env_close_door.find(read__tr_env_close_door_state);
                if(_trid_29_ptr == _OpCache_tr_env_close_door.end()) {
                    BSet<LandingGear_R6::POSITION> _trid_29 = state._tr_env_close_door();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_env_close_door_lock(_ProjectionRead__tr_env_close_door_mutex);
                        _OpCache_tr_env_close_door.insert({read__tr_env_close_door_state, _trid_29});
                    }
                    for(const LandingGear_R6::POSITION& param : _trid_29) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_close_door readState = state._projected_state_for_env_close_door();

                        auto _OpCache_with_parameter_env_close_door_ptr = _OpCache_env_close_door.find(param);
                        if(_OpCache_with_parameter_env_close_door_ptr == _OpCache_env_close_door.end()) {
                            copiedState.env_close_door(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_close_door writeState = copiedState._update_for_env_close_door();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_close_door, LandingGear_R6::_ProjectionWrite_env_close_door, LandingGear_R6::_ProjectionRead_env_close_door::Hash, LandingGear_R6::_ProjectionRead_env_close_door::HashEqual> _OpCache_with_parameter_env_close_door;
                            _OpCache_with_parameter_env_close_door.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_close_door_lock(_ProjectionRead_env_close_door_mutex);
                                _OpCache_env_close_door.insert({param, _OpCache_with_parameter_env_close_door});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_close_door, LandingGear_R6::_ProjectionWrite_env_close_door, LandingGear_R6::_ProjectionRead_env_close_door::Hash, LandingGear_R6::_ProjectionRead_env_close_door::HashEqual> _OpCache_with_parameter_env_close_door = _OpCache_with_parameter_env_close_door_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_close_door.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_close_door.end()) {
                                LandingGear_R6::_ProjectionWrite_env_close_door writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_close_door(writeState);
                            } else {
                                copiedState.env_close_door(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_close_door writeState = copiedState._update_for_env_close_door();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_close_door_lock(_ProjectionRead_env_close_door_mutex);
                                    _OpCache_with_parameter_env_close_door.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_close_door";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<LandingGear_R6::POSITION> _trid_29 = _trid_29_ptr->second;
                    for(const LandingGear_R6::POSITION& param : _trid_29) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_close_door readState = state._projected_state_for_env_close_door();

                        auto _OpCache_with_parameter_env_close_door_ptr = _OpCache_env_close_door.find(param);
                        if(_OpCache_with_parameter_env_close_door_ptr == _OpCache_env_close_door.end()) {
                            copiedState.env_close_door(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_close_door writeState = copiedState._update_for_env_close_door();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_close_door, LandingGear_R6::_ProjectionWrite_env_close_door, LandingGear_R6::_ProjectionRead_env_close_door::Hash, LandingGear_R6::_ProjectionRead_env_close_door::HashEqual> _OpCache_with_parameter_env_close_door;
                            _OpCache_with_parameter_env_close_door.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_close_door_lock(_ProjectionRead_env_close_door_mutex);
                                _OpCache_env_close_door.insert({param, _OpCache_with_parameter_env_close_door});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_close_door, LandingGear_R6::_ProjectionWrite_env_close_door, LandingGear_R6::_ProjectionRead_env_close_door::Hash, LandingGear_R6::_ProjectionRead_env_close_door::HashEqual> _OpCache_with_parameter_env_close_door = _OpCache_with_parameter_env_close_door_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_close_door.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_close_door.end()) {
                                LandingGear_R6::_ProjectionWrite_env_close_door writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_close_door(writeState);
                            } else {
                                copiedState.env_close_door(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_close_door writeState = copiedState._update_for_env_close_door();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_close_door_lock(_ProjectionRead_env_close_door_mutex);
                                    _OpCache_with_parameter_env_close_door.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_close_door";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                LandingGear_R6::_ProjectionRead__tr_env_close_door_skip read__tr_env_close_door_skip_state = state._projected_state_for__tr_env_close_door_skip();
                auto _trid_30_ptr = _OpCache_tr_env_close_door_skip.find(read__tr_env_close_door_skip_state);
                if(_trid_30_ptr == _OpCache_tr_env_close_door_skip.end()) {
                    BSet<LandingGear_R6::POSITION> _trid_30 = state._tr_env_close_door_skip();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_env_close_door_skip_lock(_ProjectionRead__tr_env_close_door_skip_mutex);
                        _OpCache_tr_env_close_door_skip.insert({read__tr_env_close_door_skip_state, _trid_30});
                    }
                    for(const LandingGear_R6::POSITION& param : _trid_30) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_close_door_skip readState = state._projected_state_for_env_close_door_skip();

                        auto _OpCache_with_parameter_env_close_door_skip_ptr = _OpCache_env_close_door_skip.find(param);
                        if(_OpCache_with_parameter_env_close_door_skip_ptr == _OpCache_env_close_door_skip.end()) {
                            copiedState.env_close_door_skip(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_close_door_skip writeState = copiedState._update_for_env_close_door_skip();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_close_door_skip, LandingGear_R6::_ProjectionWrite_env_close_door_skip, LandingGear_R6::_ProjectionRead_env_close_door_skip::Hash, LandingGear_R6::_ProjectionRead_env_close_door_skip::HashEqual> _OpCache_with_parameter_env_close_door_skip;
                            _OpCache_with_parameter_env_close_door_skip.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_close_door_skip_lock(_ProjectionRead_env_close_door_skip_mutex);
                                _OpCache_env_close_door_skip.insert({param, _OpCache_with_parameter_env_close_door_skip});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_close_door_skip, LandingGear_R6::_ProjectionWrite_env_close_door_skip, LandingGear_R6::_ProjectionRead_env_close_door_skip::Hash, LandingGear_R6::_ProjectionRead_env_close_door_skip::HashEqual> _OpCache_with_parameter_env_close_door_skip = _OpCache_with_parameter_env_close_door_skip_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_close_door_skip.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_close_door_skip.end()) {
                                LandingGear_R6::_ProjectionWrite_env_close_door_skip writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_close_door_skip(writeState);
                            } else {
                                copiedState.env_close_door_skip(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_close_door_skip writeState = copiedState._update_for_env_close_door_skip();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_close_door_skip_lock(_ProjectionRead_env_close_door_skip_mutex);
                                    _OpCache_with_parameter_env_close_door_skip.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_close_door_skip";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<LandingGear_R6::POSITION> _trid_30 = _trid_30_ptr->second;
                    for(const LandingGear_R6::POSITION& param : _trid_30) {
                        LandingGear_R6::POSITION _tmp_1 = param;

                        LandingGear_R6 copiedState = state._copy();
                        LandingGear_R6::_ProjectionRead_env_close_door_skip readState = state._projected_state_for_env_close_door_skip();

                        auto _OpCache_with_parameter_env_close_door_skip_ptr = _OpCache_env_close_door_skip.find(param);
                        if(_OpCache_with_parameter_env_close_door_skip_ptr == _OpCache_env_close_door_skip.end()) {
                            copiedState.env_close_door_skip(_tmp_1);
                            LandingGear_R6::_ProjectionWrite_env_close_door_skip writeState = copiedState._update_for_env_close_door_skip();
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_close_door_skip, LandingGear_R6::_ProjectionWrite_env_close_door_skip, LandingGear_R6::_ProjectionRead_env_close_door_skip::Hash, LandingGear_R6::_ProjectionRead_env_close_door_skip::HashEqual> _OpCache_with_parameter_env_close_door_skip;
                            _OpCache_with_parameter_env_close_door_skip.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_close_door_skip_lock(_ProjectionRead_env_close_door_skip_mutex);
                                _OpCache_env_close_door_skip.insert({param, _OpCache_with_parameter_env_close_door_skip});
                            }

                        } else {
                            std::unordered_map<LandingGear_R6::_ProjectionRead_env_close_door_skip, LandingGear_R6::_ProjectionWrite_env_close_door_skip, LandingGear_R6::_ProjectionRead_env_close_door_skip::Hash, LandingGear_R6::_ProjectionRead_env_close_door_skip::HashEqual> _OpCache_with_parameter_env_close_door_skip = _OpCache_with_parameter_env_close_door_skip_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_env_close_door_skip.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_env_close_door_skip.end()) {
                                LandingGear_R6::_ProjectionWrite_env_close_door_skip writeState = writeState_ptr->second;
                                copiedState._apply_update_for_env_close_door_skip(writeState);
                            } else {
                                copiedState.env_close_door_skip(_tmp_1);
                                LandingGear_R6::_ProjectionWrite_env_close_door_skip writeState = copiedState._update_for_env_close_door_skip();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_env_close_door_skip_lock(_ProjectionRead_env_close_door_skip_mutex);
                                    _OpCache_with_parameter_env_close_door_skip.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "env_close_door_skip";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                LandingGear_R6::_ProjectionRead__tr_toggle_handle_up read__tr_toggle_handle_up_state = state._projected_state_for__tr_toggle_handle_up();
                bool _trid_31;
                auto _obj__trid_31_ptr = _OpCache_tr_toggle_handle_up.find(read__tr_toggle_handle_up_state);
                if(_obj__trid_31_ptr == _OpCache_tr_toggle_handle_up.end()) {
                    _trid_31 = state._tr_toggle_handle_up();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_toggle_handle_up_lock(_ProjectionRead__tr_toggle_handle_up_mutex);
                        _OpCache_tr_toggle_handle_up.insert({read__tr_toggle_handle_up_state, _trid_31});
                    }
                } else {
                    _trid_31 = _obj__trid_31_ptr->second;
                }
                if(_trid_31) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_toggle_handle_up readState = state._projected_state_for_toggle_handle_up();

                    auto _OpCache_with_parameter_toggle_handle_up_ptr = _OpCache_toggle_handle_up.find(_trid_31);
                    if(_OpCache_with_parameter_toggle_handle_up_ptr == _OpCache_toggle_handle_up.end()) {
                        copiedState.toggle_handle_up();
                        LandingGear_R6::_ProjectionWrite_toggle_handle_up writeState = copiedState._update_for_toggle_handle_up();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_toggle_handle_up, LandingGear_R6::_ProjectionWrite_toggle_handle_up, LandingGear_R6::_ProjectionRead_toggle_handle_up::Hash, LandingGear_R6::_ProjectionRead_toggle_handle_up::HashEqual> _OpCache_with_parameter_toggle_handle_up;
                        _OpCache_with_parameter_toggle_handle_up.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_toggle_handle_up_lock(_ProjectionRead_toggle_handle_up_mutex);
                            _OpCache_toggle_handle_up.insert({_trid_31, _OpCache_with_parameter_toggle_handle_up});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_toggle_handle_up, LandingGear_R6::_ProjectionWrite_toggle_handle_up, LandingGear_R6::_ProjectionRead_toggle_handle_up::Hash, LandingGear_R6::_ProjectionRead_toggle_handle_up::HashEqual> _OpCache_with_parameter_toggle_handle_up = _OpCache_with_parameter_toggle_handle_up_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_toggle_handle_up.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_toggle_handle_up.end()) {
                            LandingGear_R6::_ProjectionWrite_toggle_handle_up writeState = writeState_ptr->second;
                            copiedState._apply_update_for_toggle_handle_up(writeState);
                        } else {
                            copiedState.toggle_handle_up();
                            LandingGear_R6::_ProjectionWrite_toggle_handle_up writeState = copiedState._update_for_toggle_handle_up();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_toggle_handle_up_lock(_ProjectionRead_toggle_handle_up_mutex);
                                _OpCache_with_parameter_toggle_handle_up.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "toggle_handle_up";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_toggle_handle_down read__tr_toggle_handle_down_state = state._projected_state_for__tr_toggle_handle_down();
                bool _trid_32;
                auto _obj__trid_32_ptr = _OpCache_tr_toggle_handle_down.find(read__tr_toggle_handle_down_state);
                if(_obj__trid_32_ptr == _OpCache_tr_toggle_handle_down.end()) {
                    _trid_32 = state._tr_toggle_handle_down();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_toggle_handle_down_lock(_ProjectionRead__tr_toggle_handle_down_mutex);
                        _OpCache_tr_toggle_handle_down.insert({read__tr_toggle_handle_down_state, _trid_32});
                    }
                } else {
                    _trid_32 = _obj__trid_32_ptr->second;
                }
                if(_trid_32) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_toggle_handle_down readState = state._projected_state_for_toggle_handle_down();

                    auto _OpCache_with_parameter_toggle_handle_down_ptr = _OpCache_toggle_handle_down.find(_trid_32);
                    if(_OpCache_with_parameter_toggle_handle_down_ptr == _OpCache_toggle_handle_down.end()) {
                        copiedState.toggle_handle_down();
                        LandingGear_R6::_ProjectionWrite_toggle_handle_down writeState = copiedState._update_for_toggle_handle_down();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_toggle_handle_down, LandingGear_R6::_ProjectionWrite_toggle_handle_down, LandingGear_R6::_ProjectionRead_toggle_handle_down::Hash, LandingGear_R6::_ProjectionRead_toggle_handle_down::HashEqual> _OpCache_with_parameter_toggle_handle_down;
                        _OpCache_with_parameter_toggle_handle_down.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_toggle_handle_down_lock(_ProjectionRead_toggle_handle_down_mutex);
                            _OpCache_toggle_handle_down.insert({_trid_32, _OpCache_with_parameter_toggle_handle_down});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_toggle_handle_down, LandingGear_R6::_ProjectionWrite_toggle_handle_down, LandingGear_R6::_ProjectionRead_toggle_handle_down::Hash, LandingGear_R6::_ProjectionRead_toggle_handle_down::HashEqual> _OpCache_with_parameter_toggle_handle_down = _OpCache_with_parameter_toggle_handle_down_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_toggle_handle_down.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_toggle_handle_down.end()) {
                            LandingGear_R6::_ProjectionWrite_toggle_handle_down writeState = writeState_ptr->second;
                            copiedState._apply_update_for_toggle_handle_down(writeState);
                        } else {
                            copiedState.toggle_handle_down();
                            LandingGear_R6::_ProjectionWrite_toggle_handle_down writeState = copiedState._update_for_toggle_handle_down();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_toggle_handle_down_lock(_ProjectionRead_toggle_handle_down_mutex);
                                _OpCache_with_parameter_toggle_handle_down.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "toggle_handle_down";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_con_stimulate_general_valve read__tr_con_stimulate_general_valve_state = state._projected_state_for__tr_con_stimulate_general_valve();
                bool _trid_33;
                auto _obj__trid_33_ptr = _OpCache_tr_con_stimulate_general_valve.find(read__tr_con_stimulate_general_valve_state);
                if(_obj__trid_33_ptr == _OpCache_tr_con_stimulate_general_valve.end()) {
                    _trid_33 = state._tr_con_stimulate_general_valve();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_con_stimulate_general_valve_lock(_ProjectionRead__tr_con_stimulate_general_valve_mutex);
                        _OpCache_tr_con_stimulate_general_valve.insert({read__tr_con_stimulate_general_valve_state, _trid_33});
                    }
                } else {
                    _trid_33 = _obj__trid_33_ptr->second;
                }
                if(_trid_33) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_con_stimulate_general_valve readState = state._projected_state_for_con_stimulate_general_valve();

                    auto _OpCache_with_parameter_con_stimulate_general_valve_ptr = _OpCache_con_stimulate_general_valve.find(_trid_33);
                    if(_OpCache_with_parameter_con_stimulate_general_valve_ptr == _OpCache_con_stimulate_general_valve.end()) {
                        copiedState.con_stimulate_general_valve();
                        LandingGear_R6::_ProjectionWrite_con_stimulate_general_valve writeState = copiedState._update_for_con_stimulate_general_valve();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_con_stimulate_general_valve, LandingGear_R6::_ProjectionWrite_con_stimulate_general_valve, LandingGear_R6::_ProjectionRead_con_stimulate_general_valve::Hash, LandingGear_R6::_ProjectionRead_con_stimulate_general_valve::HashEqual> _OpCache_with_parameter_con_stimulate_general_valve;
                        _OpCache_with_parameter_con_stimulate_general_valve.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_con_stimulate_general_valve_lock(_ProjectionRead_con_stimulate_general_valve_mutex);
                            _OpCache_con_stimulate_general_valve.insert({_trid_33, _OpCache_with_parameter_con_stimulate_general_valve});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_con_stimulate_general_valve, LandingGear_R6::_ProjectionWrite_con_stimulate_general_valve, LandingGear_R6::_ProjectionRead_con_stimulate_general_valve::Hash, LandingGear_R6::_ProjectionRead_con_stimulate_general_valve::HashEqual> _OpCache_with_parameter_con_stimulate_general_valve = _OpCache_with_parameter_con_stimulate_general_valve_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_con_stimulate_general_valve.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_con_stimulate_general_valve.end()) {
                            LandingGear_R6::_ProjectionWrite_con_stimulate_general_valve writeState = writeState_ptr->second;
                            copiedState._apply_update_for_con_stimulate_general_valve(writeState);
                        } else {
                            copiedState.con_stimulate_general_valve();
                            LandingGear_R6::_ProjectionWrite_con_stimulate_general_valve writeState = copiedState._update_for_con_stimulate_general_valve();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_con_stimulate_general_valve_lock(_ProjectionRead_con_stimulate_general_valve_mutex);
                                _OpCache_with_parameter_con_stimulate_general_valve.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "con_stimulate_general_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_con_stop_stimulate_general_valve read__tr_con_stop_stimulate_general_valve_state = state._projected_state_for__tr_con_stop_stimulate_general_valve();
                bool _trid_34;
                auto _obj__trid_34_ptr = _OpCache_tr_con_stop_stimulate_general_valve.find(read__tr_con_stop_stimulate_general_valve_state);
                if(_obj__trid_34_ptr == _OpCache_tr_con_stop_stimulate_general_valve.end()) {
                    _trid_34 = state._tr_con_stop_stimulate_general_valve();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_con_stop_stimulate_general_valve_lock(_ProjectionRead__tr_con_stop_stimulate_general_valve_mutex);
                        _OpCache_tr_con_stop_stimulate_general_valve.insert({read__tr_con_stop_stimulate_general_valve_state, _trid_34});
                    }
                } else {
                    _trid_34 = _obj__trid_34_ptr->second;
                }
                if(_trid_34) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_con_stop_stimulate_general_valve readState = state._projected_state_for_con_stop_stimulate_general_valve();

                    auto _OpCache_with_parameter_con_stop_stimulate_general_valve_ptr = _OpCache_con_stop_stimulate_general_valve.find(_trid_34);
                    if(_OpCache_with_parameter_con_stop_stimulate_general_valve_ptr == _OpCache_con_stop_stimulate_general_valve.end()) {
                        copiedState.con_stop_stimulate_general_valve();
                        LandingGear_R6::_ProjectionWrite_con_stop_stimulate_general_valve writeState = copiedState._update_for_con_stop_stimulate_general_valve();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_con_stop_stimulate_general_valve, LandingGear_R6::_ProjectionWrite_con_stop_stimulate_general_valve, LandingGear_R6::_ProjectionRead_con_stop_stimulate_general_valve::Hash, LandingGear_R6::_ProjectionRead_con_stop_stimulate_general_valve::HashEqual> _OpCache_with_parameter_con_stop_stimulate_general_valve;
                        _OpCache_with_parameter_con_stop_stimulate_general_valve.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_con_stop_stimulate_general_valve_lock(_ProjectionRead_con_stop_stimulate_general_valve_mutex);
                            _OpCache_con_stop_stimulate_general_valve.insert({_trid_34, _OpCache_with_parameter_con_stop_stimulate_general_valve});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_con_stop_stimulate_general_valve, LandingGear_R6::_ProjectionWrite_con_stop_stimulate_general_valve, LandingGear_R6::_ProjectionRead_con_stop_stimulate_general_valve::Hash, LandingGear_R6::_ProjectionRead_con_stop_stimulate_general_valve::HashEqual> _OpCache_with_parameter_con_stop_stimulate_general_valve = _OpCache_with_parameter_con_stop_stimulate_general_valve_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_con_stop_stimulate_general_valve.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_con_stop_stimulate_general_valve.end()) {
                            LandingGear_R6::_ProjectionWrite_con_stop_stimulate_general_valve writeState = writeState_ptr->second;
                            copiedState._apply_update_for_con_stop_stimulate_general_valve(writeState);
                        } else {
                            copiedState.con_stop_stimulate_general_valve();
                            LandingGear_R6::_ProjectionWrite_con_stop_stimulate_general_valve writeState = copiedState._update_for_con_stop_stimulate_general_valve();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_con_stop_stimulate_general_valve_lock(_ProjectionRead_con_stop_stimulate_general_valve_mutex);
                                _OpCache_with_parameter_con_stop_stimulate_general_valve.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "con_stop_stimulate_general_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_evn_open_general_valve read__tr_evn_open_general_valve_state = state._projected_state_for__tr_evn_open_general_valve();
                bool _trid_35;
                auto _obj__trid_35_ptr = _OpCache_tr_evn_open_general_valve.find(read__tr_evn_open_general_valve_state);
                if(_obj__trid_35_ptr == _OpCache_tr_evn_open_general_valve.end()) {
                    _trid_35 = state._tr_evn_open_general_valve();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_evn_open_general_valve_lock(_ProjectionRead__tr_evn_open_general_valve_mutex);
                        _OpCache_tr_evn_open_general_valve.insert({read__tr_evn_open_general_valve_state, _trid_35});
                    }
                } else {
                    _trid_35 = _obj__trid_35_ptr->second;
                }
                if(_trid_35) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_evn_open_general_valve readState = state._projected_state_for_evn_open_general_valve();

                    auto _OpCache_with_parameter_evn_open_general_valve_ptr = _OpCache_evn_open_general_valve.find(_trid_35);
                    if(_OpCache_with_parameter_evn_open_general_valve_ptr == _OpCache_evn_open_general_valve.end()) {
                        copiedState.evn_open_general_valve();
                        LandingGear_R6::_ProjectionWrite_evn_open_general_valve writeState = copiedState._update_for_evn_open_general_valve();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_evn_open_general_valve, LandingGear_R6::_ProjectionWrite_evn_open_general_valve, LandingGear_R6::_ProjectionRead_evn_open_general_valve::Hash, LandingGear_R6::_ProjectionRead_evn_open_general_valve::HashEqual> _OpCache_with_parameter_evn_open_general_valve;
                        _OpCache_with_parameter_evn_open_general_valve.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_evn_open_general_valve_lock(_ProjectionRead_evn_open_general_valve_mutex);
                            _OpCache_evn_open_general_valve.insert({_trid_35, _OpCache_with_parameter_evn_open_general_valve});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_evn_open_general_valve, LandingGear_R6::_ProjectionWrite_evn_open_general_valve, LandingGear_R6::_ProjectionRead_evn_open_general_valve::Hash, LandingGear_R6::_ProjectionRead_evn_open_general_valve::HashEqual> _OpCache_with_parameter_evn_open_general_valve = _OpCache_with_parameter_evn_open_general_valve_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_evn_open_general_valve.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_evn_open_general_valve.end()) {
                            LandingGear_R6::_ProjectionWrite_evn_open_general_valve writeState = writeState_ptr->second;
                            copiedState._apply_update_for_evn_open_general_valve(writeState);
                        } else {
                            copiedState.evn_open_general_valve();
                            LandingGear_R6::_ProjectionWrite_evn_open_general_valve writeState = copiedState._update_for_evn_open_general_valve();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_evn_open_general_valve_lock(_ProjectionRead_evn_open_general_valve_mutex);
                                _OpCache_with_parameter_evn_open_general_valve.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "evn_open_general_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_evn_close_general_valve read__tr_evn_close_general_valve_state = state._projected_state_for__tr_evn_close_general_valve();
                bool _trid_36;
                auto _obj__trid_36_ptr = _OpCache_tr_evn_close_general_valve.find(read__tr_evn_close_general_valve_state);
                if(_obj__trid_36_ptr == _OpCache_tr_evn_close_general_valve.end()) {
                    _trid_36 = state._tr_evn_close_general_valve();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_evn_close_general_valve_lock(_ProjectionRead__tr_evn_close_general_valve_mutex);
                        _OpCache_tr_evn_close_general_valve.insert({read__tr_evn_close_general_valve_state, _trid_36});
                    }
                } else {
                    _trid_36 = _obj__trid_36_ptr->second;
                }
                if(_trid_36) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_evn_close_general_valve readState = state._projected_state_for_evn_close_general_valve();

                    auto _OpCache_with_parameter_evn_close_general_valve_ptr = _OpCache_evn_close_general_valve.find(_trid_36);
                    if(_OpCache_with_parameter_evn_close_general_valve_ptr == _OpCache_evn_close_general_valve.end()) {
                        copiedState.evn_close_general_valve();
                        LandingGear_R6::_ProjectionWrite_evn_close_general_valve writeState = copiedState._update_for_evn_close_general_valve();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_evn_close_general_valve, LandingGear_R6::_ProjectionWrite_evn_close_general_valve, LandingGear_R6::_ProjectionRead_evn_close_general_valve::Hash, LandingGear_R6::_ProjectionRead_evn_close_general_valve::HashEqual> _OpCache_with_parameter_evn_close_general_valve;
                        _OpCache_with_parameter_evn_close_general_valve.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_evn_close_general_valve_lock(_ProjectionRead_evn_close_general_valve_mutex);
                            _OpCache_evn_close_general_valve.insert({_trid_36, _OpCache_with_parameter_evn_close_general_valve});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_evn_close_general_valve, LandingGear_R6::_ProjectionWrite_evn_close_general_valve, LandingGear_R6::_ProjectionRead_evn_close_general_valve::Hash, LandingGear_R6::_ProjectionRead_evn_close_general_valve::HashEqual> _OpCache_with_parameter_evn_close_general_valve = _OpCache_with_parameter_evn_close_general_valve_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_evn_close_general_valve.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_evn_close_general_valve.end()) {
                            LandingGear_R6::_ProjectionWrite_evn_close_general_valve writeState = writeState_ptr->second;
                            copiedState._apply_update_for_evn_close_general_valve(writeState);
                        } else {
                            copiedState.evn_close_general_valve();
                            LandingGear_R6::_ProjectionWrite_evn_close_general_valve writeState = copiedState._update_for_evn_close_general_valve();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_evn_close_general_valve_lock(_ProjectionRead_evn_close_general_valve_mutex);
                                _OpCache_with_parameter_evn_close_general_valve.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "evn_close_general_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_env_close_analogical_switch read__tr_env_close_analogical_switch_state = state._projected_state_for__tr_env_close_analogical_switch();
                bool _trid_37;
                auto _obj__trid_37_ptr = _OpCache_tr_env_close_analogical_switch.find(read__tr_env_close_analogical_switch_state);
                if(_obj__trid_37_ptr == _OpCache_tr_env_close_analogical_switch.end()) {
                    _trid_37 = state._tr_env_close_analogical_switch();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_env_close_analogical_switch_lock(_ProjectionRead__tr_env_close_analogical_switch_mutex);
                        _OpCache_tr_env_close_analogical_switch.insert({read__tr_env_close_analogical_switch_state, _trid_37});
                    }
                } else {
                    _trid_37 = _obj__trid_37_ptr->second;
                }
                if(_trid_37) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_env_close_analogical_switch readState = state._projected_state_for_env_close_analogical_switch();

                    auto _OpCache_with_parameter_env_close_analogical_switch_ptr = _OpCache_env_close_analogical_switch.find(_trid_37);
                    if(_OpCache_with_parameter_env_close_analogical_switch_ptr == _OpCache_env_close_analogical_switch.end()) {
                        copiedState.env_close_analogical_switch();
                        LandingGear_R6::_ProjectionWrite_env_close_analogical_switch writeState = copiedState._update_for_env_close_analogical_switch();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_env_close_analogical_switch, LandingGear_R6::_ProjectionWrite_env_close_analogical_switch, LandingGear_R6::_ProjectionRead_env_close_analogical_switch::Hash, LandingGear_R6::_ProjectionRead_env_close_analogical_switch::HashEqual> _OpCache_with_parameter_env_close_analogical_switch;
                        _OpCache_with_parameter_env_close_analogical_switch.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_env_close_analogical_switch_lock(_ProjectionRead_env_close_analogical_switch_mutex);
                            _OpCache_env_close_analogical_switch.insert({_trid_37, _OpCache_with_parameter_env_close_analogical_switch});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_env_close_analogical_switch, LandingGear_R6::_ProjectionWrite_env_close_analogical_switch, LandingGear_R6::_ProjectionRead_env_close_analogical_switch::Hash, LandingGear_R6::_ProjectionRead_env_close_analogical_switch::HashEqual> _OpCache_with_parameter_env_close_analogical_switch = _OpCache_with_parameter_env_close_analogical_switch_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_env_close_analogical_switch.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_env_close_analogical_switch.end()) {
                            LandingGear_R6::_ProjectionWrite_env_close_analogical_switch writeState = writeState_ptr->second;
                            copiedState._apply_update_for_env_close_analogical_switch(writeState);
                        } else {
                            copiedState.env_close_analogical_switch();
                            LandingGear_R6::_ProjectionWrite_env_close_analogical_switch writeState = copiedState._update_for_env_close_analogical_switch();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_close_analogical_switch_lock(_ProjectionRead_env_close_analogical_switch_mutex);
                                _OpCache_with_parameter_env_close_analogical_switch.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "env_close_analogical_switch";
                    result.insert(copiedState);
                    transitions += 1;
                }
                LandingGear_R6::_ProjectionRead__tr_env_open_analogical_switch read__tr_env_open_analogical_switch_state = state._projected_state_for__tr_env_open_analogical_switch();
                bool _trid_38;
                auto _obj__trid_38_ptr = _OpCache_tr_env_open_analogical_switch.find(read__tr_env_open_analogical_switch_state);
                if(_obj__trid_38_ptr == _OpCache_tr_env_open_analogical_switch.end()) {
                    _trid_38 = state._tr_env_open_analogical_switch();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_env_open_analogical_switch_lock(_ProjectionRead__tr_env_open_analogical_switch_mutex);
                        _OpCache_tr_env_open_analogical_switch.insert({read__tr_env_open_analogical_switch_state, _trid_38});
                    }
                } else {
                    _trid_38 = _obj__trid_38_ptr->second;
                }
                if(_trid_38) {
                    LandingGear_R6 copiedState = state._copy();
                    LandingGear_R6::_ProjectionRead_env_open_analogical_switch readState = state._projected_state_for_env_open_analogical_switch();

                    auto _OpCache_with_parameter_env_open_analogical_switch_ptr = _OpCache_env_open_analogical_switch.find(_trid_38);
                    if(_OpCache_with_parameter_env_open_analogical_switch_ptr == _OpCache_env_open_analogical_switch.end()) {
                        copiedState.env_open_analogical_switch();
                        LandingGear_R6::_ProjectionWrite_env_open_analogical_switch writeState = copiedState._update_for_env_open_analogical_switch();
                        std::unordered_map<LandingGear_R6::_ProjectionRead_env_open_analogical_switch, LandingGear_R6::_ProjectionWrite_env_open_analogical_switch, LandingGear_R6::_ProjectionRead_env_open_analogical_switch::Hash, LandingGear_R6::_ProjectionRead_env_open_analogical_switch::HashEqual> _OpCache_with_parameter_env_open_analogical_switch;
                        _OpCache_with_parameter_env_open_analogical_switch.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_env_open_analogical_switch_lock(_ProjectionRead_env_open_analogical_switch_mutex);
                            _OpCache_env_open_analogical_switch.insert({_trid_38, _OpCache_with_parameter_env_open_analogical_switch});
                        }

                    } else {
                        std::unordered_map<LandingGear_R6::_ProjectionRead_env_open_analogical_switch, LandingGear_R6::_ProjectionWrite_env_open_analogical_switch, LandingGear_R6::_ProjectionRead_env_open_analogical_switch::Hash, LandingGear_R6::_ProjectionRead_env_open_analogical_switch::HashEqual> _OpCache_with_parameter_env_open_analogical_switch = _OpCache_with_parameter_env_open_analogical_switch_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_env_open_analogical_switch.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_env_open_analogical_switch.end()) {
                            LandingGear_R6::_ProjectionWrite_env_open_analogical_switch writeState = writeState_ptr->second;
                            copiedState._apply_update_for_env_open_analogical_switch(writeState);
                        } else {
                            copiedState.env_open_analogical_switch();
                            LandingGear_R6::_ProjectionWrite_env_open_analogical_switch writeState = copiedState._update_for_env_open_analogical_switch();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_env_open_analogical_switch_lock(_ProjectionRead_env_open_analogical_switch_mutex);
                                _OpCache_with_parameter_env_open_analogical_switch.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "env_open_analogical_switch";
                    result.insert(copiedState);
                    transitions += 1;
                }

            } else {
                if(state._tr_begin_flying()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.begin_flying();
                    copiedState.stateAccessedVia = "begin_flying";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_land_plane()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.land_plane();
                    copiedState.stateAccessedVia = "land_plane";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_open_valve_door_open()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.open_valve_door_open();
                    copiedState.stateAccessedVia = "open_valve_door_open";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_close_valve_door_open()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.close_valve_door_open();
                    copiedState.stateAccessedVia = "close_valve_door_open";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_open_valve_door_close()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.open_valve_door_close();
                    copiedState.stateAccessedVia = "open_valve_door_close";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_close_valve_door_close()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.close_valve_door_close();
                    copiedState.stateAccessedVia = "close_valve_door_close";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_open_valve_retract_gear()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.open_valve_retract_gear();
                    copiedState.stateAccessedVia = "open_valve_retract_gear";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_close_valve_retract_gear()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.close_valve_retract_gear();
                    copiedState.stateAccessedVia = "close_valve_retract_gear";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_open_valve_extend_gear()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.open_valve_extend_gear();
                    copiedState.stateAccessedVia = "open_valve_extend_gear";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_close_valve_extend_gear()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.close_valve_extend_gear();
                    copiedState.stateAccessedVia = "close_valve_extend_gear";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_con_stimulate_open_door_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.con_stimulate_open_door_valve();
                    copiedState.stateAccessedVia = "con_stimulate_open_door_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_con_stop_stimulate_open_door_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.con_stop_stimulate_open_door_valve();
                    copiedState.stateAccessedVia = "con_stop_stimulate_open_door_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_con_stimulate_close_door_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.con_stimulate_close_door_valve();
                    copiedState.stateAccessedVia = "con_stimulate_close_door_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_con_stop_stimulate_close_door_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.con_stop_stimulate_close_door_valve();
                    copiedState.stateAccessedVia = "con_stop_stimulate_close_door_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_con_stimulate_retract_gear_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.con_stimulate_retract_gear_valve();
                    copiedState.stateAccessedVia = "con_stimulate_retract_gear_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_con_stop_stimulate_retract_gear_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.con_stop_stimulate_retract_gear_valve();
                    copiedState.stateAccessedVia = "con_stop_stimulate_retract_gear_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_con_stimulate_extend_gear_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.con_stimulate_extend_gear_valve();
                    copiedState.stateAccessedVia = "con_stimulate_extend_gear_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_con_stop_stimulate_extend_gear_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.con_stop_stimulate_extend_gear_valve();
                    copiedState.stateAccessedVia = "con_stop_stimulate_extend_gear_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<LandingGear_R6::POSITION> _trid_19 = state._tr_env_start_retracting_first();
                for(const LandingGear_R6::POSITION& param : _trid_19) {
                    LandingGear_R6::POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_start_retracting_first(_tmp_1);
                    copiedState.stateAccessedVia = "env_start_retracting_first";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<LandingGear_R6::POSITION> _trid_20 = state._tr_env_retract_gear_skip();
                for(const LandingGear_R6::POSITION& param : _trid_20) {
                    LandingGear_R6::POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_retract_gear_skip(_tmp_1);
                    copiedState.stateAccessedVia = "env_retract_gear_skip";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<LandingGear_R6::POSITION> _trid_21 = state._tr_env_retract_gear_last();
                for(const LandingGear_R6::POSITION& param : _trid_21) {
                    LandingGear_R6::POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_retract_gear_last(_tmp_1);
                    copiedState.stateAccessedVia = "env_retract_gear_last";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<LandingGear_R6::POSITION> _trid_22 = state._tr_env_start_extending();
                for(const LandingGear_R6::POSITION& param : _trid_22) {
                    LandingGear_R6::POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_start_extending(_tmp_1);
                    copiedState.stateAccessedVia = "env_start_extending";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<LandingGear_R6::POSITION> _trid_23 = state._tr_env_extend_gear_last();
                for(const LandingGear_R6::POSITION& param : _trid_23) {
                    LandingGear_R6::POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_extend_gear_last(_tmp_1);
                    copiedState.stateAccessedVia = "env_extend_gear_last";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<LandingGear_R6::POSITION> _trid_24 = state._tr_env_extend_gear_skip();
                for(const LandingGear_R6::POSITION& param : _trid_24) {
                    LandingGear_R6::POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_extend_gear_skip(_tmp_1);
                    copiedState.stateAccessedVia = "env_extend_gear_skip";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<LandingGear_R6::POSITION> _trid_25 = state._tr_env_start_open_door();
                for(const LandingGear_R6::POSITION& param : _trid_25) {
                    LandingGear_R6::POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_start_open_door(_tmp_1);
                    copiedState.stateAccessedVia = "env_start_open_door";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<LandingGear_R6::POSITION> _trid_26 = state._tr_env_open_door_last();
                for(const LandingGear_R6::POSITION& param : _trid_26) {
                    LandingGear_R6::POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_open_door_last(_tmp_1);
                    copiedState.stateAccessedVia = "env_open_door_last";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<LandingGear_R6::POSITION> _trid_27 = state._tr_env_open_door_skip();
                for(const LandingGear_R6::POSITION& param : _trid_27) {
                    LandingGear_R6::POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_open_door_skip(_tmp_1);
                    copiedState.stateAccessedVia = "env_open_door_skip";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<LandingGear_R6::POSITION> _trid_28 = state._tr_env_start_close_door();
                for(const LandingGear_R6::POSITION& param : _trid_28) {
                    LandingGear_R6::POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_start_close_door(_tmp_1);
                    copiedState.stateAccessedVia = "env_start_close_door";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<LandingGear_R6::POSITION> _trid_29 = state._tr_env_close_door();
                for(const LandingGear_R6::POSITION& param : _trid_29) {
                    LandingGear_R6::POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_close_door(_tmp_1);
                    copiedState.stateAccessedVia = "env_close_door";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<LandingGear_R6::POSITION> _trid_30 = state._tr_env_close_door_skip();
                for(const LandingGear_R6::POSITION& param : _trid_30) {
                    LandingGear_R6::POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_close_door_skip(_tmp_1);
                    copiedState.stateAccessedVia = "env_close_door_skip";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_toggle_handle_up()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.toggle_handle_up();
                    copiedState.stateAccessedVia = "toggle_handle_up";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_toggle_handle_down()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.toggle_handle_down();
                    copiedState.stateAccessedVia = "toggle_handle_down";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_con_stimulate_general_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.con_stimulate_general_valve();
                    copiedState.stateAccessedVia = "con_stimulate_general_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_con_stop_stimulate_general_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.con_stop_stimulate_general_valve();
                    copiedState.stateAccessedVia = "con_stop_stimulate_general_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_evn_open_general_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.evn_open_general_valve();
                    copiedState.stateAccessedVia = "evn_open_general_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_evn_close_general_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.evn_close_general_valve();
                    copiedState.stateAccessedVia = "evn_close_general_valve";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_env_close_analogical_switch()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_close_analogical_switch();
                    copiedState.stateAccessedVia = "env_close_analogical_switch";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_env_open_analogical_switch()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_open_analogical_switch();
                    copiedState.stateAccessedVia = "env_open_analogical_switch";
                    result.insert(copiedState);
                    transitions += 1;
                }

            }
            return result;
        }

        bool invariantViolated(const LandingGear_R6& state) {
            bool _check_inv_1;
            if(isCaching) {
                LandingGear_R6::_ProjectionRead__check_inv_1 read__check_inv_1_state = state._projected_state_for__check_inv_1();
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
                LandingGear_R6::_ProjectionRead__check_inv_2 read__check_inv_2_state = state._projected_state_for__check_inv_2();
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
                LandingGear_R6::_ProjectionRead__check_inv_3 read__check_inv_3_state = state._projected_state_for__check_inv_3();
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
                LandingGear_R6::_ProjectionRead__check_inv_4 read__check_inv_4_state = state._projected_state_for__check_inv_4();
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
                LandingGear_R6::_ProjectionRead__check_inv_5 read__check_inv_5_state = state._projected_state_for__check_inv_5();
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
                LandingGear_R6::_ProjectionRead__check_inv_6 read__check_inv_6_state = state._projected_state_for__check_inv_6();
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
                LandingGear_R6::_ProjectionRead__check_inv_7 read__check_inv_7_state = state._projected_state_for__check_inv_7();
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
                LandingGear_R6::_ProjectionRead__check_inv_8 read__check_inv_8_state = state._projected_state_for__check_inv_8();
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
                LandingGear_R6::_ProjectionRead__check_inv_9 read__check_inv_9_state = state._projected_state_for__check_inv_9();
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
                LandingGear_R6::_ProjectionRead__check_inv_10 read__check_inv_10_state = state._projected_state_for__check_inv_10();
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
                LandingGear_R6::_ProjectionRead__check_inv_11 read__check_inv_11_state = state._projected_state_for__check_inv_11();
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
                LandingGear_R6::_ProjectionRead__check_inv_12 read__check_inv_12_state = state._projected_state_for__check_inv_12();
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
                LandingGear_R6::_ProjectionRead__check_inv_13 read__check_inv_13_state = state._projected_state_for__check_inv_13();
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
                LandingGear_R6::_ProjectionRead__check_inv_14 read__check_inv_14_state = state._projected_state_for__check_inv_14();
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
                LandingGear_R6::_ProjectionRead__check_inv_15 read__check_inv_15_state = state._projected_state_for__check_inv_15();
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
                LandingGear_R6::_ProjectionRead__check_inv_16 read__check_inv_16_state = state._projected_state_for__check_inv_16();
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
                LandingGear_R6::_ProjectionRead__check_inv_17 read__check_inv_17_state = state._projected_state_for__check_inv_17();
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
                LandingGear_R6::_ProjectionRead__check_inv_18 read__check_inv_18_state = state._projected_state_for__check_inv_18();
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
                LandingGear_R6::_ProjectionRead__check_inv_19 read__check_inv_19_state = state._projected_state_for__check_inv_19();
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
                LandingGear_R6::_ProjectionRead__check_inv_20 read__check_inv_20_state = state._projected_state_for__check_inv_20();
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
            bool _check_inv_21;
            if(isCaching) {
                LandingGear_R6::_ProjectionRead__check_inv_21 read__check_inv_21_state = state._projected_state_for__check_inv_21();
                auto _obj__check_inv_21_ptr = _InvCache__check_inv_21.find(read__check_inv_21_state);
                if(_obj__check_inv_21_ptr == _InvCache__check_inv_21.end()) {
                    _check_inv_21 = state._check_inv_21();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_21_lock(_ProjectionRead__check_inv_21_mutex);
                        _InvCache__check_inv_21.insert({read__check_inv_21_state, _check_inv_21});
                    }
                } else {
                    _check_inv_21 = _obj__check_inv_21_ptr->second;
                }
            } else {
                _check_inv_21 = state._check_inv_21();
            }
            if(!_check_inv_21) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_21" << "\n";
              return true;
            }
            bool _check_inv_22;
            if(isCaching) {
                LandingGear_R6::_ProjectionRead__check_inv_22 read__check_inv_22_state = state._projected_state_for__check_inv_22();
                auto _obj__check_inv_22_ptr = _InvCache__check_inv_22.find(read__check_inv_22_state);
                if(_obj__check_inv_22_ptr == _InvCache__check_inv_22.end()) {
                    _check_inv_22 = state._check_inv_22();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_22_lock(_ProjectionRead__check_inv_22_mutex);
                        _InvCache__check_inv_22.insert({read__check_inv_22_state, _check_inv_22});
                    }
                } else {
                    _check_inv_22 = _obj__check_inv_22_ptr->second;
                }
            } else {
                _check_inv_22 = state._check_inv_22();
            }
            if(!_check_inv_22) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_22" << "\n";
              return true;
            }
            bool _check_inv_23;
            if(isCaching) {
                LandingGear_R6::_ProjectionRead__check_inv_23 read__check_inv_23_state = state._projected_state_for__check_inv_23();
                auto _obj__check_inv_23_ptr = _InvCache__check_inv_23.find(read__check_inv_23_state);
                if(_obj__check_inv_23_ptr == _InvCache__check_inv_23.end()) {
                    _check_inv_23 = state._check_inv_23();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_23_lock(_ProjectionRead__check_inv_23_mutex);
                        _InvCache__check_inv_23.insert({read__check_inv_23_state, _check_inv_23});
                    }
                } else {
                    _check_inv_23 = _obj__check_inv_23_ptr->second;
                }
            } else {
                _check_inv_23 = state._check_inv_23();
            }
            if(!_check_inv_23) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_23" << "\n";
              return true;
            }
            bool _check_inv_24;
            if(isCaching) {
                LandingGear_R6::_ProjectionRead__check_inv_24 read__check_inv_24_state = state._projected_state_for__check_inv_24();
                auto _obj__check_inv_24_ptr = _InvCache__check_inv_24.find(read__check_inv_24_state);
                if(_obj__check_inv_24_ptr == _InvCache__check_inv_24.end()) {
                    _check_inv_24 = state._check_inv_24();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_24_lock(_ProjectionRead__check_inv_24_mutex);
                        _InvCache__check_inv_24.insert({read__check_inv_24_state, _check_inv_24});
                    }
                } else {
                    _check_inv_24 = _obj__check_inv_24_ptr->second;
                }
            } else {
                _check_inv_24 = state._check_inv_24();
            }
            if(!_check_inv_24) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_24" << "\n";
              return true;
            }
            bool _check_inv_25;
            if(isCaching) {
                LandingGear_R6::_ProjectionRead__check_inv_25 read__check_inv_25_state = state._projected_state_for__check_inv_25();
                auto _obj__check_inv_25_ptr = _InvCache__check_inv_25.find(read__check_inv_25_state);
                if(_obj__check_inv_25_ptr == _InvCache__check_inv_25.end()) {
                    _check_inv_25 = state._check_inv_25();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_25_lock(_ProjectionRead__check_inv_25_mutex);
                        _InvCache__check_inv_25.insert({read__check_inv_25_state, _check_inv_25});
                    }
                } else {
                    _check_inv_25 = _obj__check_inv_25_ptr->second;
                }
            } else {
                _check_inv_25 = state._check_inv_25();
            }
            if(!_check_inv_25) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_25" << "\n";
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

    LandingGear_R6::Type type;

    if(std::string("mixed").compare(strategy) == 0) {
        type = LandingGear_R6::Type::MIXED;
    } else if(std::string("bf").compare(strategy) == 0) {
        type = LandingGear_R6::Type::BFS;
    } else if (std::string("df").compare(strategy) == 0) {
        type = LandingGear_R6::Type::DFS;
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