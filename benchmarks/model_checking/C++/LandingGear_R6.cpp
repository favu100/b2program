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
#include <boost/optional.hpp>
#include <btypes_primitives/BUtils.hpp>
#include <btypes_primitives/StateNotReachableError.hpp>
#include <btypes_primitives/PreconditionOrAssertionViolation.hpp>
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

        mutable boost::optional<bool> _tr_cache_begin_flying;
        mutable boost::optional<bool> _tr_cache_land_plane;
        mutable boost::optional<bool> _tr_cache_open_valve_door_open;
        mutable boost::optional<bool> _tr_cache_close_valve_door_open;
        mutable boost::optional<bool> _tr_cache_open_valve_door_close;
        mutable boost::optional<bool> _tr_cache_close_valve_door_close;
        mutable boost::optional<bool> _tr_cache_open_valve_retract_gear;
        mutable boost::optional<bool> _tr_cache_close_valve_retract_gear;
        mutable boost::optional<bool> _tr_cache_open_valve_extend_gear;
        mutable boost::optional<bool> _tr_cache_close_valve_extend_gear;
        mutable boost::optional<bool> _tr_cache_con_stimulate_open_door_valve;
        mutable boost::optional<bool> _tr_cache_con_stop_stimulate_open_door_valve;
        mutable boost::optional<bool> _tr_cache_con_stimulate_close_door_valve;
        mutable boost::optional<bool> _tr_cache_con_stop_stimulate_close_door_valve;
        mutable boost::optional<bool> _tr_cache_con_stimulate_retract_gear_valve;
        mutable boost::optional<bool> _tr_cache_con_stop_stimulate_retract_gear_valve;
        mutable boost::optional<bool> _tr_cache_con_stimulate_extend_gear_valve;
        mutable boost::optional<bool> _tr_cache_con_stop_stimulate_extend_gear_valve;
        mutable boost::optional<BSet<POSITION>> _tr_cache_env_start_retracting_first;
        mutable boost::optional<BSet<POSITION>> _tr_cache_env_retract_gear_skip;
        mutable boost::optional<BSet<POSITION>> _tr_cache_env_retract_gear_last;
        mutable boost::optional<BSet<POSITION>> _tr_cache_env_start_extending;
        mutable boost::optional<BSet<POSITION>> _tr_cache_env_extend_gear_last;
        mutable boost::optional<BSet<POSITION>> _tr_cache_env_extend_gear_skip;
        mutable boost::optional<BSet<POSITION>> _tr_cache_env_start_open_door;
        mutable boost::optional<BSet<POSITION>> _tr_cache_env_open_door_last;
        mutable boost::optional<BSet<POSITION>> _tr_cache_env_open_door_skip;
        mutable boost::optional<BSet<POSITION>> _tr_cache_env_start_close_door;
        mutable boost::optional<BSet<POSITION>> _tr_cache_env_close_door;
        mutable boost::optional<BSet<POSITION>> _tr_cache_env_close_door_skip;
        mutable boost::optional<bool> _tr_cache_toggle_handle_up;
        mutable boost::optional<bool> _tr_cache_toggle_handle_down;
        mutable boost::optional<bool> _tr_cache_con_stimulate_general_valve;
        mutable boost::optional<bool> _tr_cache_con_stop_stimulate_general_valve;
        mutable boost::optional<bool> _tr_cache_evn_open_general_valve;
        mutable boost::optional<bool> _tr_cache_evn_close_general_valve;
        mutable boost::optional<bool> _tr_cache_env_close_analogical_switch;
        mutable boost::optional<bool> _tr_cache_env_open_analogical_switch;

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

        LandingGear_R6(const SWITCH_STATE& analogical_switch, const BBoolean& general_EV, const VALVE_STATE& general_valve, const BBoolean& handle_move, const BBoolean& close_EV, const BBoolean& extend_EV, const BBoolean& open_EV, const BBoolean& retract_EV, const PLANE_STATE& shock_absorber, const VALVE_STATE& valve_close_door, const VALVE_STATE& valve_extend_gear, const VALVE_STATE& valve_open_door, const VALVE_STATE& valve_retract_gear, const BRelation<POSITION, DOOR_STATE >& doors, const BRelation<POSITION, GEAR_STATE >& gears, const HANDLE_STATE& handle, const DOOR_STATE& door, const GEAR_STATE& gear) {
            this->analogical_switch = analogical_switch;
            this->general_EV = general_EV;
            this->general_valve = general_valve;
            this->handle_move = handle_move;
            this->close_EV = close_EV;
            this->extend_EV = extend_EV;
            this->open_EV = open_EV;
            this->retract_EV = retract_EV;
            this->shock_absorber = shock_absorber;
            this->valve_close_door = valve_close_door;
            this->valve_extend_gear = valve_extend_gear;
            this->valve_open_door = valve_open_door;
            this->valve_retract_gear = valve_retract_gear;
            this->doors = doors;
            this->gears = gears;
            this->handle = handle;
            this->door = door;
            this->gear = gear;
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


        bool _tr_begin_flying(bool isCaching) const {
            if (this->_tr_cache_begin_flying == boost::none){
                bool __tmp_result = (shock_absorber.equal((PLANE_STATE(PLANE_STATE::ground)))).booleanValue();
                if (isCaching) this->_tr_cache_begin_flying = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_begin_flying.get();
        }

        bool _tr_land_plane(bool isCaching) const {
            if (this->_tr_cache_land_plane == boost::none){
                bool __tmp_result = (shock_absorber.equal((PLANE_STATE(PLANE_STATE::flight)))).booleanValue();
                if (isCaching) this->_tr_cache_land_plane = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_land_plane.get();
        }

        bool _tr_open_valve_door_open(bool isCaching) const {
            if (this->_tr_cache_open_valve_door_open == boost::none){
                bool __tmp_result = ((BBoolean(valve_open_door.equal((VALVE_STATE(VALVE_STATE::valve_closed))).booleanValue() && open_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_open_valve_door_open = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_open_valve_door_open.get();
        }

        bool _tr_close_valve_door_open(bool isCaching) const {
            if (this->_tr_cache_close_valve_door_open == boost::none){
                bool __tmp_result = ((BBoolean(valve_open_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue() && open_EV.equal((BBoolean(false))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_close_valve_door_open = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_close_valve_door_open.get();
        }

        bool _tr_open_valve_door_close(bool isCaching) const {
            if (this->_tr_cache_open_valve_door_close == boost::none){
                bool __tmp_result = ((BBoolean(valve_close_door.equal((VALVE_STATE(VALVE_STATE::valve_closed))).booleanValue() && close_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_open_valve_door_close = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_open_valve_door_close.get();
        }

        bool _tr_close_valve_door_close(bool isCaching) const {
            if (this->_tr_cache_close_valve_door_close == boost::none){
                bool __tmp_result = ((BBoolean(valve_close_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue() && close_EV.equal((BBoolean(false))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_close_valve_door_close = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_close_valve_door_close.get();
        }

        bool _tr_open_valve_retract_gear(bool isCaching) const {
            if (this->_tr_cache_open_valve_retract_gear == boost::none){
                bool __tmp_result = ((BBoolean(valve_retract_gear.equal((VALVE_STATE(VALVE_STATE::valve_closed))).booleanValue() && retract_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_open_valve_retract_gear = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_open_valve_retract_gear.get();
        }

        bool _tr_close_valve_retract_gear(bool isCaching) const {
            if (this->_tr_cache_close_valve_retract_gear == boost::none){
                bool __tmp_result = ((BBoolean(valve_retract_gear.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue() && retract_EV.equal((BBoolean(false))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_close_valve_retract_gear = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_close_valve_retract_gear.get();
        }

        bool _tr_open_valve_extend_gear(bool isCaching) const {
            if (this->_tr_cache_open_valve_extend_gear == boost::none){
                bool __tmp_result = ((BBoolean(valve_extend_gear.equal((VALVE_STATE(VALVE_STATE::valve_closed))).booleanValue() && extend_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_open_valve_extend_gear = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_open_valve_extend_gear.get();
        }

        bool _tr_close_valve_extend_gear(bool isCaching) const {
            if (this->_tr_cache_close_valve_extend_gear == boost::none){
                bool __tmp_result = ((BBoolean(valve_extend_gear.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue() && extend_EV.equal((BBoolean(false))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_close_valve_extend_gear = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_close_valve_extend_gear.get();
        }

        bool _tr_con_stimulate_open_door_valve(bool isCaching) const {
            if (this->_tr_cache_con_stimulate_open_door_valve == boost::none){
                bool __tmp_result = ((BBoolean((BBoolean((BBoolean(open_EV.equal((BBoolean(false))).booleanValue() && close_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended)))))._not().booleanValue())).booleanValue() || (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted)))))._not().booleanValue())).booleanValue() && (BBoolean(doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue() && shock_absorber.equal((PLANE_STATE(PLANE_STATE::ground))).booleanValue()))._not().booleanValue())).booleanValue())).booleanValue())).booleanValue() && general_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_con_stimulate_open_door_valve = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_con_stimulate_open_door_valve.get();
        }

        bool _tr_con_stop_stimulate_open_door_valve(bool isCaching) const {
            if (this->_tr_cache_con_stop_stimulate_open_door_valve == boost::none){
                bool __tmp_result = ((BBoolean((BBoolean((BBoolean((BBoolean(open_EV.equal((BBoolean(true))).booleanValue() && extend_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && retract_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() || (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && (BBoolean(gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue() || shock_absorber.equal((PLANE_STATE(PLANE_STATE::ground))).booleanValue())).booleanValue())).booleanValue() && doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && general_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_con_stop_stimulate_open_door_valve = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_con_stop_stimulate_open_door_valve.get();
        }

        bool _tr_con_stimulate_close_door_valve(bool isCaching) const {
            if (this->_tr_cache_con_stimulate_close_door_valve == boost::none){
                bool __tmp_result = ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(close_EV.equal((BBoolean(false))).booleanValue() && open_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && extend_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && retract_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && (BBoolean(gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue() || shock_absorber.equal((PLANE_STATE(PLANE_STATE::ground))).booleanValue())).booleanValue())).booleanValue())).booleanValue())).booleanValue() && doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed)))))._not().booleanValue())).booleanValue() && general_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_con_stimulate_close_door_valve = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_con_stimulate_close_door_valve.get();
        }

        bool _tr_con_stop_stimulate_close_door_valve(bool isCaching) const {
            if (this->_tr_cache_con_stop_stimulate_close_door_valve == boost::none){
                bool __tmp_result = ((BBoolean((BBoolean(close_EV.equal((BBoolean(true))).booleanValue() && (BBoolean((BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() && doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed))))).booleanValue())).booleanValue() || (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && (BBoolean(gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue() || shock_absorber.equal((PLANE_STATE(PLANE_STATE::ground))).booleanValue())).booleanValue())).booleanValue() && doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && general_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_con_stop_stimulate_close_door_valve = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_con_stop_stimulate_close_door_valve.get();
        }

        bool _tr_con_stimulate_retract_gear_valve(bool isCaching) const {
            if (this->_tr_cache_con_stimulate_retract_gear_valve == boost::none){
                bool __tmp_result = ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(retract_EV.equal((BBoolean(false))).booleanValue() && extend_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && open_EV.equal((BBoolean(true))).booleanValue())).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue())).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted)))))._not().booleanValue())).booleanValue() && shock_absorber.equal((PLANE_STATE(PLANE_STATE::flight))).booleanValue())).booleanValue() && doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue())).booleanValue() && general_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_con_stimulate_retract_gear_valve = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_con_stimulate_retract_gear_valve.get();
        }

        bool _tr_con_stop_stimulate_retract_gear_valve(bool isCaching) const {
            if (this->_tr_cache_con_stop_stimulate_retract_gear_valve == boost::none){
                bool __tmp_result = ((BBoolean((BBoolean(retract_EV.equal((BBoolean(true))).booleanValue() && (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() || gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue())).booleanValue())).booleanValue() && general_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_con_stop_stimulate_retract_gear_valve = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_con_stop_stimulate_retract_gear_valve.get();
        }

        bool _tr_con_stimulate_extend_gear_valve(bool isCaching) const {
            if (this->_tr_cache_con_stimulate_extend_gear_valve == boost::none){
                bool __tmp_result = ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(extend_EV.equal((BBoolean(false))).booleanValue() && retract_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && open_EV.equal((BBoolean(true))).booleanValue())).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue())).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended)))))._not().booleanValue())).booleanValue() && doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue())).booleanValue() && general_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_con_stimulate_extend_gear_valve = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_con_stimulate_extend_gear_valve.get();
        }

        bool _tr_con_stop_stimulate_extend_gear_valve(bool isCaching) const {
            if (this->_tr_cache_con_stop_stimulate_extend_gear_valve == boost::none){
                bool __tmp_result = ((BBoolean((BBoolean(extend_EV.equal((BBoolean(true))).booleanValue() && (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() || gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue() && general_EV.equal((BBoolean(true))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_con_stop_stimulate_extend_gear_valve = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_con_stop_stimulate_extend_gear_valve.get();
        }

        BSet<POSITION> _tr_env_start_retracting_first(bool isCaching) const {
            if (this->_tr_cache_env_start_retracting_first == boost::none){
                BSet<POSITION> _ic_set_18 = BSet<POSITION>();
                for(const POSITION& _ic_gr_1 : gears.domain()) {
                    if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue())).booleanValue() && gears.functionCall(_ic_gr_1).equal((GEAR_STATE(GEAR_STATE::extended))).booleanValue())).booleanValue() && valve_retract_gear.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && (BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended)), (GEAR_STATE(GEAR_STATE::gear_moving)))).elementOf(gear).booleanValue())).booleanValue() && door.equal((DOOR_STATE(DOOR_STATE::open))).booleanValue()))).booleanValue()) {
                        _ic_set_18 = _ic_set_18._union(BSet<POSITION>(_ic_gr_1));
                    }

                }
                if (isCaching) this->_tr_cache_env_start_retracting_first = _ic_set_18;
                else return _ic_set_18;
            }
            return this->_tr_cache_env_start_retracting_first.get();
        }

        BSet<POSITION> _tr_env_retract_gear_skip(bool isCaching) const {
            if (this->_tr_cache_env_retract_gear_skip == boost::none){
                BSet<POSITION> _ic_set_19 = BSet<POSITION>();
                for(const POSITION& _ic_gr_1 : gears.domain()) {
                    if(((BBoolean((BBoolean((BBoolean((BBoolean(doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue() && gears.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).unequal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue())).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue())).booleanValue() && gears.functionCall(_ic_gr_1).equal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue()))).booleanValue()) {
                        _ic_set_19 = _ic_set_19._union(BSet<POSITION>(_ic_gr_1));
                    }

                }
                if (isCaching) this->_tr_cache_env_retract_gear_skip = _ic_set_19;
                else return _ic_set_19;
            }
            return this->_tr_cache_env_retract_gear_skip.get();
        }

        BSet<POSITION> _tr_env_retract_gear_last(bool isCaching) const {
            if (this->_tr_cache_env_retract_gear_last == boost::none){
                BSet<POSITION> _ic_set_20 = BSet<POSITION>();
                for(const POSITION& _ic_gr_1 : gears.domain()) {
                    if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue() && gears.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue())).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue())).booleanValue() && gears.functionCall(_ic_gr_1).equal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && door.equal((DOOR_STATE(DOOR_STATE::open))).booleanValue()))).booleanValue()) {
                        _ic_set_20 = _ic_set_20._union(BSet<POSITION>(_ic_gr_1));
                    }

                }
                if (isCaching) this->_tr_cache_env_retract_gear_last = _ic_set_20;
                else return _ic_set_20;
            }
            return this->_tr_cache_env_retract_gear_last.get();
        }

        BSet<POSITION> _tr_env_start_extending(bool isCaching) const {
            if (this->_tr_cache_env_start_extending == boost::none){
                BSet<POSITION> _ic_set_21 = BSet<POSITION>();
                for(const POSITION& _ic_gr_1 : gears.domain()) {
                    if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue())).booleanValue() && gears.functionCall(_ic_gr_1).equal((GEAR_STATE(GEAR_STATE::retracted))).booleanValue())).booleanValue() && valve_extend_gear.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && (BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::gear_moving)), (GEAR_STATE(GEAR_STATE::retracted)))).elementOf(gear).booleanValue())).booleanValue() && door.equal((DOOR_STATE(DOOR_STATE::open))).booleanValue()))).booleanValue()) {
                        _ic_set_21 = _ic_set_21._union(BSet<POSITION>(_ic_gr_1));
                    }

                }
                if (isCaching) this->_tr_cache_env_start_extending = _ic_set_21;
                else return _ic_set_21;
            }
            return this->_tr_cache_env_start_extending.get();
        }

        BSet<POSITION> _tr_env_extend_gear_last(bool isCaching) const {
            if (this->_tr_cache_env_extend_gear_last == boost::none){
                BSet<POSITION> _ic_set_22 = BSet<POSITION>();
                for(const POSITION& _ic_gr_1 : gears.domain()) {
                    if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue())).booleanValue() && gears.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() && gears.functionCall(_ic_gr_1).equal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && door.equal((DOOR_STATE(DOOR_STATE::open))).booleanValue()))).booleanValue()) {
                        _ic_set_22 = _ic_set_22._union(BSet<POSITION>(_ic_gr_1));
                    }

                }
                if (isCaching) this->_tr_cache_env_extend_gear_last = _ic_set_22;
                else return _ic_set_22;
            }
            return this->_tr_cache_env_extend_gear_last.get();
        }

        BSet<POSITION> _tr_env_extend_gear_skip(bool isCaching) const {
            if (this->_tr_cache_env_extend_gear_skip == boost::none){
                BSet<POSITION> _ic_set_23 = BSet<POSITION>();
                for(const POSITION& _ic_gr_1 : gears.domain()) {
                    if(((BBoolean((BBoolean((BBoolean((BBoolean(doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue())).booleanValue() && gears.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).unequal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() && gears.functionCall(_ic_gr_1).equal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue()))).booleanValue()) {
                        _ic_set_23 = _ic_set_23._union(BSet<POSITION>(_ic_gr_1));
                    }

                }
                if (isCaching) this->_tr_cache_env_extend_gear_skip = _ic_set_23;
                else return _ic_set_23;
            }
            return this->_tr_cache_env_extend_gear_skip.get();
        }

        BSet<POSITION> _tr_env_start_open_door(bool isCaching) const {
            if (this->_tr_cache_env_start_open_door == boost::none){
                BSet<POSITION> _ic_set_24 = BSet<POSITION>();
                for(const POSITION& _ic_gr_1 : gears.domain()) {
                    if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.functionCall(_ic_gr_1).equal((DOOR_STATE(DOOR_STATE::closed))).booleanValue() && gears.functionCall(_ic_gr_1).unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && gears.range().notElementOf((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && valve_open_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && (BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed)), (DOOR_STATE(DOOR_STATE::door_moving)))).elementOf(door).booleanValue())).booleanValue() && gear.unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::retracted))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::extended))).booleanValue())).booleanValue())).booleanValue()))).booleanValue()) {
                        _ic_set_24 = _ic_set_24._union(BSet<POSITION>(_ic_gr_1));
                    }

                }
                if (isCaching) this->_tr_cache_env_start_open_door = _ic_set_24;
                else return _ic_set_24;
            }
            return this->_tr_cache_env_start_open_door.get();
        }

        BSet<POSITION> _tr_env_open_door_last(bool isCaching) const {
            if (this->_tr_cache_env_open_door_last == boost::none){
                BSet<POSITION> _ic_set_25 = BSet<POSITION>();
                for(const POSITION& _ic_gr_1 : gears.domain()) {
                    if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.functionCall(_ic_gr_1).equal((DOOR_STATE(DOOR_STATE::door_moving))).booleanValue() && gears.functionCall(_ic_gr_1).unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && gears.range().notElementOf((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && doors.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && valve_open_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && door.equal((DOOR_STATE(DOOR_STATE::door_moving))).booleanValue())).booleanValue() && gear.unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::retracted))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::extended))).booleanValue())).booleanValue())).booleanValue()))).booleanValue()) {
                        _ic_set_25 = _ic_set_25._union(BSet<POSITION>(_ic_gr_1));
                    }

                }
                if (isCaching) this->_tr_cache_env_open_door_last = _ic_set_25;
                else return _ic_set_25;
            }
            return this->_tr_cache_env_open_door_last.get();
        }

        BSet<POSITION> _tr_env_open_door_skip(bool isCaching) const {
            if (this->_tr_cache_env_open_door_skip == boost::none){
                BSet<POSITION> _ic_set_26 = BSet<POSITION>();
                for(const POSITION& _ic_gr_1 : gears.domain()) {
                    if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.functionCall(_ic_gr_1).equal((DOOR_STATE(DOOR_STATE::door_moving))).booleanValue() && gears.functionCall(_ic_gr_1).unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && gears.range().notElementOf((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && doors.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).unequal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && valve_open_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue()))).booleanValue()) {
                        _ic_set_26 = _ic_set_26._union(BSet<POSITION>(_ic_gr_1));
                    }

                }
                if (isCaching) this->_tr_cache_env_open_door_skip = _ic_set_26;
                else return _ic_set_26;
            }
            return this->_tr_cache_env_open_door_skip.get();
        }

        BSet<POSITION> _tr_env_start_close_door(bool isCaching) const {
            if (this->_tr_cache_env_start_close_door == boost::none){
                BSet<POSITION> _ic_set_27 = BSet<POSITION>();
                for(const POSITION& _ic_gr_1 : gears.domain()) {
                    if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.functionCall(_ic_gr_1).equal((DOOR_STATE(DOOR_STATE::open))).booleanValue() && gears.functionCall(_ic_gr_1).unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && (BBoolean(gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue() || gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && valve_close_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && (BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::door_moving)), (DOOR_STATE(DOOR_STATE::open)))).elementOf(door).booleanValue())).booleanValue() && gear.unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::extended))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && (BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended)), (GEAR_STATE(GEAR_STATE::retracted)))).elementOf(gear).booleanValue())).booleanValue())).booleanValue()))).booleanValue()) {
                        _ic_set_27 = _ic_set_27._union(BSet<POSITION>(_ic_gr_1));
                    }

                }
                if (isCaching) this->_tr_cache_env_start_close_door = _ic_set_27;
                else return _ic_set_27;
            }
            return this->_tr_cache_env_start_close_door.get();
        }

        BSet<POSITION> _tr_env_close_door(bool isCaching) const {
            if (this->_tr_cache_env_close_door == boost::none){
                BSet<POSITION> _ic_set_28 = BSet<POSITION>();
                for(const POSITION& _ic_gr_1 : gears.domain()) {
                    if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.functionCall(_ic_gr_1).equal((DOOR_STATE(DOOR_STATE::door_moving))).booleanValue() && gears.functionCall(_ic_gr_1).unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && gears.range().notElementOf((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && doors.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed))))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && (BBoolean(gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue() || gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && valve_close_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() || shock_absorber.equal((PLANE_STATE(PLANE_STATE::ground))).booleanValue())).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && door.equal((DOOR_STATE(DOOR_STATE::door_moving))).booleanValue())).booleanValue() && gear.unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::extended))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && (BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended)), (GEAR_STATE(GEAR_STATE::retracted)))).elementOf(gear).booleanValue())).booleanValue())).booleanValue()))).booleanValue()) {
                        _ic_set_28 = _ic_set_28._union(BSet<POSITION>(_ic_gr_1));
                    }

                }
                if (isCaching) this->_tr_cache_env_close_door = _ic_set_28;
                else return _ic_set_28;
            }
            return this->_tr_cache_env_close_door.get();
        }

        BSet<POSITION> _tr_env_close_door_skip(bool isCaching) const {
            if (this->_tr_cache_env_close_door_skip == boost::none){
                BSet<POSITION> _ic_set_29 = BSet<POSITION>();
                for(const POSITION& _ic_gr_1 : gears.domain()) {
                    if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.functionCall(_ic_gr_1).equal((DOOR_STATE(DOOR_STATE::door_moving))).booleanValue() && gears.functionCall(_ic_gr_1).unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && gears.range().notElementOf((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && doors.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).unequal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed))))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && (BBoolean(gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue() || gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && valve_close_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() || shock_absorber.equal((PLANE_STATE(PLANE_STATE::ground))).booleanValue())).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue()))).booleanValue()) {
                        _ic_set_29 = _ic_set_29._union(BSet<POSITION>(_ic_gr_1));
                    }

                }
                if (isCaching) this->_tr_cache_env_close_door_skip = _ic_set_29;
                else return _ic_set_29;
            }
            return this->_tr_cache_env_close_door_skip.get();
        }

        bool _tr_toggle_handle_up(bool isCaching) const {
            if (this->_tr_cache_toggle_handle_up == boost::none){
                bool __tmp_result = (handle.equal((HANDLE_STATE(HANDLE_STATE::down)))).booleanValue();
                if (isCaching) this->_tr_cache_toggle_handle_up = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_toggle_handle_up.get();
        }

        bool _tr_toggle_handle_down(bool isCaching) const {
            if (this->_tr_cache_toggle_handle_down == boost::none){
                bool __tmp_result = (handle.equal((HANDLE_STATE(HANDLE_STATE::up)))).booleanValue();
                if (isCaching) this->_tr_cache_toggle_handle_down = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_toggle_handle_down.get();
        }

        bool _tr_con_stimulate_general_valve(bool isCaching) const {
            if (this->_tr_cache_con_stimulate_general_valve == boost::none){
                bool __tmp_result = ((BBoolean(general_EV.equal((BBoolean(false))).booleanValue() && handle_move.equal((BBoolean(true))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_con_stimulate_general_valve = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_con_stimulate_general_valve.get();
        }

        bool _tr_con_stop_stimulate_general_valve(bool isCaching) const {
            if (this->_tr_cache_con_stop_stimulate_general_valve == boost::none){
                bool __tmp_result = ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(general_EV.equal((BBoolean(true))).booleanValue() && open_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && close_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && retract_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && extend_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && close_EV.equal((BBoolean(false))).booleanValue())).booleanValue() && (BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue())).booleanValue() && doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed))))).booleanValue())).booleanValue() && open_EV.equal((BBoolean(false))).booleanValue())).booleanValue() || (BBoolean((BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() && doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed))))).booleanValue())).booleanValue() && open_EV.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() || (BBoolean((BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() && doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed))))).booleanValue())).booleanValue() && open_EV.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_con_stop_stimulate_general_valve = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_con_stop_stimulate_general_valve.get();
        }

        bool _tr_evn_open_general_valve(bool isCaching) const {
            if (this->_tr_cache_evn_open_general_valve == boost::none){
                bool __tmp_result = ((BBoolean((BBoolean(general_EV.equal((BBoolean(true))).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_closed))).booleanValue())).booleanValue() && analogical_switch.equal((SWITCH_STATE(SWITCH_STATE::switch_closed))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_evn_open_general_valve = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_evn_open_general_valve.get();
        }

        bool _tr_evn_close_general_valve(bool isCaching) const {
            if (this->_tr_cache_evn_close_general_valve == boost::none){
                bool __tmp_result = ((BBoolean((BBoolean(general_EV.equal((BBoolean(false))).booleanValue() || analogical_switch.equal((SWITCH_STATE(SWITCH_STATE::switch_open))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_evn_close_general_valve = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_evn_close_general_valve.get();
        }

        bool _tr_env_close_analogical_switch(bool isCaching) const {
            if (this->_tr_cache_env_close_analogical_switch == boost::none){
                bool __tmp_result = ((BBoolean(analogical_switch.equal((SWITCH_STATE(SWITCH_STATE::switch_open))).booleanValue() && handle_move.equal((BBoolean(true))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_env_close_analogical_switch = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_env_close_analogical_switch.get();
        }

        bool _tr_env_open_analogical_switch(bool isCaching) const {
            if (this->_tr_cache_env_open_analogical_switch == boost::none){
                bool __tmp_result = (analogical_switch.equal((SWITCH_STATE(SWITCH_STATE::switch_closed)))).booleanValue();
                if (isCaching) this->_tr_cache_env_open_analogical_switch = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_env_open_analogical_switch.get();
        }

        bool _check_inv_1() const {
            return (_SWITCH_STATE.elementOf(analogical_switch)).booleanValue();
        }

        bool _check_inv_2() const {
            return ((BOOL).elementOf(general_EV)).booleanValue();
        }

        bool _check_inv_3() const {
            return (_VALVE_STATE.elementOf(general_valve)).booleanValue();
        }

        bool _check_inv_4() const {
            return ((BOOL).elementOf(handle_move)).booleanValue();
        }

        bool _check_inv_5() const {
            return ((BOOL).elementOf(close_EV)).booleanValue();
        }

        bool _check_inv_6() const {
            return ((BOOL).elementOf(extend_EV)).booleanValue();
        }

        bool _check_inv_7() const {
            return ((BOOL).elementOf(open_EV)).booleanValue();
        }

        bool _check_inv_8() const {
            return ((BOOL).elementOf(retract_EV)).booleanValue();
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

        static constexpr unsigned int strHash(const char *s, int off = 0) {
            return !s[off] ? 5381 : (strHash(s, off+1)*33) ^ s[off];
        }

        LandingGear_R6 _copy(unordered_set<string> toInvalidate) const {
            static const char* allTransitions[] = {"_tr_begin_flying", "_tr_land_plane", "_tr_open_valve_door_open", "_tr_close_valve_door_open", "_tr_open_valve_door_close", "_tr_close_valve_door_close", "_tr_open_valve_retract_gear", "_tr_close_valve_retract_gear", "_tr_open_valve_extend_gear", "_tr_close_valve_extend_gear", "_tr_con_stimulate_open_door_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stimulate_extend_gear_valve", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_env_retract_gear_skip", "_tr_env_retract_gear_last", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_extend_gear_skip", "_tr_env_start_open_door", "_tr_env_open_door_last", "_tr_env_open_door_skip", "_tr_env_start_close_door", "_tr_env_close_door", "_tr_env_close_door_skip", "_tr_toggle_handle_up", "_tr_toggle_handle_down", "_tr_con_stimulate_general_valve", "_tr_con_stop_stimulate_general_valve", "_tr_evn_open_general_valve", "_tr_evn_close_general_valve", "_tr_env_close_analogical_switch", "_tr_env_open_analogical_switch"};

            LandingGear_R6 result = LandingGear_R6(analogical_switch, general_EV, general_valve, handle_move, close_EV, extend_EV, open_EV, retract_EV, shock_absorber, valve_close_door, valve_extend_gear, valve_open_door, valve_retract_gear, doors, gears, handle, door, gear);

            for (const auto &item : allTransitions) {
                if(toInvalidate.find(item) == toInvalidate.end()) {
                    switch(strHash(item)) {
                        case strHash("_tr_begin_flying"): result._tr_cache_begin_flying = this->_tr_cache_begin_flying; break;
                        case strHash("_tr_land_plane"): result._tr_cache_land_plane = this->_tr_cache_land_plane; break;
                        case strHash("_tr_open_valve_door_open"): result._tr_cache_open_valve_door_open = this->_tr_cache_open_valve_door_open; break;
                        case strHash("_tr_close_valve_door_open"): result._tr_cache_close_valve_door_open = this->_tr_cache_close_valve_door_open; break;
                        case strHash("_tr_open_valve_door_close"): result._tr_cache_open_valve_door_close = this->_tr_cache_open_valve_door_close; break;
                        case strHash("_tr_close_valve_door_close"): result._tr_cache_close_valve_door_close = this->_tr_cache_close_valve_door_close; break;
                        case strHash("_tr_open_valve_retract_gear"): result._tr_cache_open_valve_retract_gear = this->_tr_cache_open_valve_retract_gear; break;
                        case strHash("_tr_close_valve_retract_gear"): result._tr_cache_close_valve_retract_gear = this->_tr_cache_close_valve_retract_gear; break;
                        case strHash("_tr_open_valve_extend_gear"): result._tr_cache_open_valve_extend_gear = this->_tr_cache_open_valve_extend_gear; break;
                        case strHash("_tr_close_valve_extend_gear"): result._tr_cache_close_valve_extend_gear = this->_tr_cache_close_valve_extend_gear; break;
                        case strHash("_tr_con_stimulate_open_door_valve"): result._tr_cache_con_stimulate_open_door_valve = this->_tr_cache_con_stimulate_open_door_valve; break;
                        case strHash("_tr_con_stop_stimulate_open_door_valve"): result._tr_cache_con_stop_stimulate_open_door_valve = this->_tr_cache_con_stop_stimulate_open_door_valve; break;
                        case strHash("_tr_con_stimulate_close_door_valve"): result._tr_cache_con_stimulate_close_door_valve = this->_tr_cache_con_stimulate_close_door_valve; break;
                        case strHash("_tr_con_stop_stimulate_close_door_valve"): result._tr_cache_con_stop_stimulate_close_door_valve = this->_tr_cache_con_stop_stimulate_close_door_valve; break;
                        case strHash("_tr_con_stimulate_retract_gear_valve"): result._tr_cache_con_stimulate_retract_gear_valve = this->_tr_cache_con_stimulate_retract_gear_valve; break;
                        case strHash("_tr_con_stop_stimulate_retract_gear_valve"): result._tr_cache_con_stop_stimulate_retract_gear_valve = this->_tr_cache_con_stop_stimulate_retract_gear_valve; break;
                        case strHash("_tr_con_stimulate_extend_gear_valve"): result._tr_cache_con_stimulate_extend_gear_valve = this->_tr_cache_con_stimulate_extend_gear_valve; break;
                        case strHash("_tr_con_stop_stimulate_extend_gear_valve"): result._tr_cache_con_stop_stimulate_extend_gear_valve = this->_tr_cache_con_stop_stimulate_extend_gear_valve; break;
                        case strHash("_tr_env_start_retracting_first"): result._tr_cache_env_start_retracting_first = this->_tr_cache_env_start_retracting_first; break;
                        case strHash("_tr_env_retract_gear_skip"): result._tr_cache_env_retract_gear_skip = this->_tr_cache_env_retract_gear_skip; break;
                        case strHash("_tr_env_retract_gear_last"): result._tr_cache_env_retract_gear_last = this->_tr_cache_env_retract_gear_last; break;
                        case strHash("_tr_env_start_extending"): result._tr_cache_env_start_extending = this->_tr_cache_env_start_extending; break;
                        case strHash("_tr_env_extend_gear_last"): result._tr_cache_env_extend_gear_last = this->_tr_cache_env_extend_gear_last; break;
                        case strHash("_tr_env_extend_gear_skip"): result._tr_cache_env_extend_gear_skip = this->_tr_cache_env_extend_gear_skip; break;
                        case strHash("_tr_env_start_open_door"): result._tr_cache_env_start_open_door = this->_tr_cache_env_start_open_door; break;
                        case strHash("_tr_env_open_door_last"): result._tr_cache_env_open_door_last = this->_tr_cache_env_open_door_last; break;
                        case strHash("_tr_env_open_door_skip"): result._tr_cache_env_open_door_skip = this->_tr_cache_env_open_door_skip; break;
                        case strHash("_tr_env_start_close_door"): result._tr_cache_env_start_close_door = this->_tr_cache_env_start_close_door; break;
                        case strHash("_tr_env_close_door"): result._tr_cache_env_close_door = this->_tr_cache_env_close_door; break;
                        case strHash("_tr_env_close_door_skip"): result._tr_cache_env_close_door_skip = this->_tr_cache_env_close_door_skip; break;
                        case strHash("_tr_toggle_handle_up"): result._tr_cache_toggle_handle_up = this->_tr_cache_toggle_handle_up; break;
                        case strHash("_tr_toggle_handle_down"): result._tr_cache_toggle_handle_down = this->_tr_cache_toggle_handle_down; break;
                        case strHash("_tr_con_stimulate_general_valve"): result._tr_cache_con_stimulate_general_valve = this->_tr_cache_con_stimulate_general_valve; break;
                        case strHash("_tr_con_stop_stimulate_general_valve"): result._tr_cache_con_stop_stimulate_general_valve = this->_tr_cache_con_stop_stimulate_general_valve; break;
                        case strHash("_tr_evn_open_general_valve"): result._tr_cache_evn_open_general_valve = this->_tr_cache_evn_open_general_valve; break;
                        case strHash("_tr_evn_close_general_valve"): result._tr_cache_evn_close_general_valve = this->_tr_cache_evn_close_general_valve; break;
                        case strHash("_tr_env_close_analogical_switch"): result._tr_cache_env_close_analogical_switch = this->_tr_cache_env_close_analogical_switch; break;
                        case strHash("_tr_env_open_analogical_switch"): result._tr_cache_env_open_analogical_switch = this->_tr_cache_env_open_analogical_switch; break;
                        default: cout << "Transition " << item << " not found!";
                    }
                }
            }
            return result;
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
        std::mutex guardMutex;
        std::condition_variable waitCV;

        std::atomic<bool> invariantViolatedBool;
        std::atomic<bool> deadlockDetected;
        LandingGear_R6 counterExampleState;

        std::unordered_map<string, std::unordered_set<string>> invariantDependency;
        std::unordered_map<string, std::unordered_set<string>> guardDependency;
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
                boost::asio::thread_pool workers(threads); // threads indicates the number of workers (without the coordinator)
                modelCheckMultiThreaded(workers);
            }
        }

        void modelCheckSingleThreaded() {
            LandingGear_R6 machine = LandingGear_R6();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            if (isCaching) {
                initCache(machine);
            }

            while(!unvisitedStates.empty()) {
                LandingGear_R6 state = next();

                std::unordered_set<LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual> nextStates = generateNextStates(state);

                for(auto& nextState : nextStates) {
                    if(states.find(nextState) == states.end()) {
                        states.insert(nextState);
                        parents.insert({nextState, state});
                        unvisitedStates.push_back(nextState);
                        if(states.size() % 50000 == 0) {
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

            std::atomic<bool> stopThreads;
            stopThreads = false;
            std::atomic<int> possibleQueueChanges;
            possibleQueueChanges = 0;

            if(isCaching) {
                initCache(machine);
            }

            std::atomic<bool> waitFlag;
            waitFlag = true;

            while(!unvisitedStates.empty() && !stopThreads) {
                possibleQueueChanges += 1;
                LandingGear_R6 state = next();
                std::packaged_task<void()> task([&, state] {
                    std::unordered_set<LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual> nextStates = generateNextStates(state);

                    for(auto& nextState : nextStates) {
                        {
                            std::unique_lock<std::mutex> lock(mutex);
                            if(states.find(nextState) == states.end()) {
                                states.insert(nextState);
                                parents.insert({nextState, state});
                                unvisitedStates.push_back(nextState); // TODO: sync ?
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
                    while (unvisitedStates.empty() && possibleQueueChanges > 0) {
                        waitCV.wait(lock, [&] {
                            return waitFlag == false;
                        });
                    }
                }
            }
            workers.join();
            printResult();
        }

        void initCache(LandingGear_R6& machine) {
            invariantDependency.insert({"close_valve_door_close", {"_check_inv_10"}});
            invariantDependency.insert({"close_valve_retract_gear", {"_check_inv_13"}});
            invariantDependency.insert({"con_stimulate_open_door_valve", {"_check_inv_18", "_check_inv_17", "_check_inv_7"}});
            invariantDependency.insert({"env_close_door", {"_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22"}});
            invariantDependency.insert({"env_start_close_door", {"_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22"}});
            invariantDependency.insert({"toggle_handle_up", {"_check_inv_4", "_check_inv_14"}});
            invariantDependency.insert({"toggle_handle_down", {"_check_inv_4", "_check_inv_14"}});
            invariantDependency.insert({"open_valve_door_open", {"_check_inv_12"}});
            invariantDependency.insert({"env_retract_gear_last", {"_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23"}});
            invariantDependency.insert({"env_open_door_last", {"_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22"}});
            invariantDependency.insert({"con_stop_stimulate_retract_gear_valve", {"_check_inv_17", "_check_inv_8"}});
            invariantDependency.insert({"env_close_door_skip", {"_check_inv_21", "_check_inv_20", "_check_inv_22"}});
            invariantDependency.insert({"con_stop_stimulate_close_door_valve", {"_check_inv_18", "_check_inv_17", "_check_inv_5"}});
            invariantDependency.insert({"env_open_analogical_switch", {"_check_inv_1"}});
            invariantDependency.insert({"con_stop_stimulate_general_valve", {"_check_inv_17", "_check_inv_2", "_check_inv_4"}});
            invariantDependency.insert({"env_extend_gear_last", {"_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23"}});
            invariantDependency.insert({"evn_open_general_valve", {"_check_inv_3"}});
            invariantDependency.insert({"land_plane", {"_check_inv_9"}});
            invariantDependency.insert({"con_stimulate_retract_gear_valve", {"_check_inv_17", "_check_inv_8"}});
            invariantDependency.insert({"con_stimulate_general_valve", {"_check_inv_17", "_check_inv_2"}});
            invariantDependency.insert({"env_start_retracting_first", {"_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23"}});
            invariantDependency.insert({"env_retract_gear_skip", {"_check_inv_19", "_check_inv_24", "_check_inv_23"}});
            invariantDependency.insert({"open_valve_extend_gear", {"_check_inv_11"}});
            invariantDependency.insert({"begin_flying", {"_check_inv_9"}});
            invariantDependency.insert({"open_valve_retract_gear", {"_check_inv_13"}});
            invariantDependency.insert({"env_close_analogical_switch", {"_check_inv_1"}});
            invariantDependency.insert({"env_start_extending", {"_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23"}});
            invariantDependency.insert({"open_valve_door_close", {"_check_inv_10"}});
            invariantDependency.insert({"con_stop_stimulate_open_door_valve", {"_check_inv_18", "_check_inv_17", "_check_inv_7"}});
            invariantDependency.insert({"con_stop_stimulate_extend_gear_valve", {"_check_inv_17", "_check_inv_6"}});
            invariantDependency.insert({"evn_close_general_valve", {"_check_inv_3"}});
            invariantDependency.insert({"close_valve_extend_gear", {"_check_inv_11"}});
            invariantDependency.insert({"con_stimulate_extend_gear_valve", {"_check_inv_17", "_check_inv_6"}});
            invariantDependency.insert({"close_valve_door_open", {"_check_inv_12"}});
            invariantDependency.insert({"con_stimulate_close_door_valve", {"_check_inv_18", "_check_inv_17", "_check_inv_5"}});
            invariantDependency.insert({"env_extend_gear_skip", {"_check_inv_19", "_check_inv_24", "_check_inv_23"}});
            invariantDependency.insert({"env_open_door_skip", {"_check_inv_21", "_check_inv_20", "_check_inv_22"}});
            invariantDependency.insert({"env_start_open_door", {"_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22"}});
            invariantDependency.insert({"", {}});
            guardDependency.insert({"close_valve_door_close", {"_tr_open_valve_door_close", "_tr_env_close_door_skip", "_tr_env_start_close_door", "_tr_env_close_door", "_tr_close_valve_door_close"}});
            guardDependency.insert({"close_valve_retract_gear", {"_tr_close_valve_retract_gear", "_tr_open_valve_retract_gear", "_tr_env_start_retracting_first"}});
            guardDependency.insert({"con_stimulate_open_door_valve", {"_tr_open_valve_door_open", "_tr_con_stimulate_extend_gear_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_open"}});
            guardDependency.insert({"env_close_door", {"_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"}});
            guardDependency.insert({"env_start_close_door", {"_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"}});
            guardDependency.insert({"toggle_handle_up", {"_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_close_analogical_switch", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip", "_tr_con_stimulate_general_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_toggle_handle_down", "_tr_env_open_door_last", "_tr_toggle_handle_up", "_tr_env_start_close_door", "_tr_con_stop_stimulate_close_door_valve"}});
            guardDependency.insert({"toggle_handle_down", {"_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_close_analogical_switch", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip", "_tr_con_stimulate_general_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_toggle_handle_down", "_tr_env_open_door_last", "_tr_toggle_handle_up", "_tr_env_start_close_door", "_tr_con_stop_stimulate_close_door_valve"}});
            guardDependency.insert({"open_valve_door_open", {"_tr_open_valve_door_open", "_tr_env_open_door_last", "_tr_env_start_open_door", "_tr_env_open_door_skip", "_tr_close_valve_door_open"}});
            guardDependency.insert({"env_retract_gear_last", {"_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"}});
            guardDependency.insert({"env_open_door_last", {"_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"}});
            guardDependency.insert({"con_stop_stimulate_retract_gear_valve", {"_tr_close_valve_retract_gear", "_tr_con_stimulate_extend_gear_valve", "_tr_open_valve_retract_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_retract_gear_valve"}});
            guardDependency.insert({"env_close_door_skip", {"_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"}});
            guardDependency.insert({"con_stop_stimulate_close_door_valve", {"_tr_open_valve_door_close", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_close"}});
            guardDependency.insert({"env_open_analogical_switch", {"_tr_env_open_analogical_switch", "_tr_evn_open_general_valve", "_tr_env_close_analogical_switch", "_tr_evn_close_general_valve"}});
            guardDependency.insert({"con_stop_stimulate_general_valve", {"_tr_con_stimulate_extend_gear_valve", "_tr_con_stimulate_general_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_evn_open_general_valve", "_tr_env_close_analogical_switch", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_evn_close_general_valve", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve"}});
            guardDependency.insert({"env_extend_gear_last", {"_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"}});
            guardDependency.insert({"evn_open_general_valve", {"_tr_env_retract_gear_last", "_tr_env_close_door_skip", "_tr_evn_open_general_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_evn_close_general_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"}});
            guardDependency.insert({"land_plane", {"_tr_land_plane", "_tr_begin_flying", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_close_door"}});
            guardDependency.insert({"con_stimulate_retract_gear_valve", {"_tr_close_valve_retract_gear", "_tr_con_stimulate_extend_gear_valve", "_tr_open_valve_retract_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_retract_gear_valve"}});
            guardDependency.insert({"con_stimulate_general_valve", {"_tr_con_stimulate_extend_gear_valve", "_tr_con_stimulate_general_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_evn_open_general_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_evn_close_general_valve", "_tr_con_stop_stimulate_retract_gear_valve"}});
            guardDependency.insert({"env_start_retracting_first", {"_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"}});
            guardDependency.insert({"env_retract_gear_skip", {"_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"}});
            guardDependency.insert({"open_valve_extend_gear", {"_tr_close_valve_extend_gear", "_tr_open_valve_extend_gear", "_tr_env_start_extending"}});
            guardDependency.insert({"begin_flying", {"_tr_land_plane", "_tr_begin_flying", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_close_door"}});
            guardDependency.insert({"open_valve_retract_gear", {"_tr_close_valve_retract_gear", "_tr_open_valve_retract_gear", "_tr_env_start_retracting_first"}});
            guardDependency.insert({"env_close_analogical_switch", {"_tr_env_open_analogical_switch", "_tr_evn_open_general_valve", "_tr_env_close_analogical_switch", "_tr_evn_close_general_valve"}});
            guardDependency.insert({"env_start_extending", {"_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"}});
            guardDependency.insert({"open_valve_door_close", {"_tr_open_valve_door_close", "_tr_env_close_door_skip", "_tr_env_start_close_door", "_tr_env_close_door", "_tr_close_valve_door_close"}});
            guardDependency.insert({"con_stop_stimulate_open_door_valve", {"_tr_open_valve_door_open", "_tr_con_stimulate_extend_gear_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_open"}});
            guardDependency.insert({"con_stop_stimulate_extend_gear_valve", {"_tr_con_stimulate_extend_gear_valve", "_tr_close_valve_extend_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_open_valve_extend_gear", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_extend_gear_valve"}});
            guardDependency.insert({"evn_close_general_valve", {"_tr_env_retract_gear_last", "_tr_env_close_door_skip", "_tr_evn_open_general_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_evn_close_general_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"}});
            guardDependency.insert({"close_valve_extend_gear", {"_tr_close_valve_extend_gear", "_tr_open_valve_extend_gear", "_tr_env_start_extending"}});
            guardDependency.insert({"con_stimulate_extend_gear_valve", {"_tr_con_stimulate_extend_gear_valve", "_tr_close_valve_extend_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_open_valve_extend_gear", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_extend_gear_valve"}});
            guardDependency.insert({"close_valve_door_open", {"_tr_open_valve_door_open", "_tr_env_open_door_last", "_tr_env_start_open_door", "_tr_env_open_door_skip", "_tr_close_valve_door_open"}});
            guardDependency.insert({"con_stimulate_close_door_valve", {"_tr_open_valve_door_close", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_close"}});
            guardDependency.insert({"env_extend_gear_skip", {"_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"}});
            guardDependency.insert({"env_open_door_skip", {"_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"}});
            guardDependency.insert({"env_start_open_door", {"_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"}});
        }


    private:
        LandingGear_R6 next() {
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
            };
        }

        std::unordered_set<LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual> generateNextStates(const LandingGear_R6& state) {
            std::unordered_set<LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual> result = std::unordered_set<LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual>();
            if(state._tr_begin_flying(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["begin_flying"]);
                copiedState.begin_flying();
                copiedState.stateAccessedVia = "begin_flying";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_land_plane(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["land_plane"]);
                copiedState.land_plane();
                copiedState.stateAccessedVia = "land_plane";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_open_valve_door_open(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["open_valve_door_open"]);
                copiedState.open_valve_door_open();
                copiedState.stateAccessedVia = "open_valve_door_open";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_close_valve_door_open(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["close_valve_door_open"]);
                copiedState.close_valve_door_open();
                copiedState.stateAccessedVia = "close_valve_door_open";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_open_valve_door_close(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["open_valve_door_close"]);
                copiedState.open_valve_door_close();
                copiedState.stateAccessedVia = "open_valve_door_close";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_close_valve_door_close(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["close_valve_door_close"]);
                copiedState.close_valve_door_close();
                copiedState.stateAccessedVia = "close_valve_door_close";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_open_valve_retract_gear(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["open_valve_retract_gear"]);
                copiedState.open_valve_retract_gear();
                copiedState.stateAccessedVia = "open_valve_retract_gear";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_close_valve_retract_gear(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["close_valve_retract_gear"]);
                copiedState.close_valve_retract_gear();
                copiedState.stateAccessedVia = "close_valve_retract_gear";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_open_valve_extend_gear(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["open_valve_extend_gear"]);
                copiedState.open_valve_extend_gear();
                copiedState.stateAccessedVia = "open_valve_extend_gear";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_close_valve_extend_gear(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["close_valve_extend_gear"]);
                copiedState.close_valve_extend_gear();
                copiedState.stateAccessedVia = "close_valve_extend_gear";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_con_stimulate_open_door_valve(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["con_stimulate_open_door_valve"]);
                copiedState.con_stimulate_open_door_valve();
                copiedState.stateAccessedVia = "con_stimulate_open_door_valve";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_con_stop_stimulate_open_door_valve(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["con_stop_stimulate_open_door_valve"]);
                copiedState.con_stop_stimulate_open_door_valve();
                copiedState.stateAccessedVia = "con_stop_stimulate_open_door_valve";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_con_stimulate_close_door_valve(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["con_stimulate_close_door_valve"]);
                copiedState.con_stimulate_close_door_valve();
                copiedState.stateAccessedVia = "con_stimulate_close_door_valve";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_con_stop_stimulate_close_door_valve(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["con_stop_stimulate_close_door_valve"]);
                copiedState.con_stop_stimulate_close_door_valve();
                copiedState.stateAccessedVia = "con_stop_stimulate_close_door_valve";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_con_stimulate_retract_gear_valve(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["con_stimulate_retract_gear_valve"]);
                copiedState.con_stimulate_retract_gear_valve();
                copiedState.stateAccessedVia = "con_stimulate_retract_gear_valve";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_con_stop_stimulate_retract_gear_valve(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["con_stop_stimulate_retract_gear_valve"]);
                copiedState.con_stop_stimulate_retract_gear_valve();
                copiedState.stateAccessedVia = "con_stop_stimulate_retract_gear_valve";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_con_stimulate_extend_gear_valve(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["con_stimulate_extend_gear_valve"]);
                copiedState.con_stimulate_extend_gear_valve();
                copiedState.stateAccessedVia = "con_stimulate_extend_gear_valve";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_con_stop_stimulate_extend_gear_valve(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["con_stop_stimulate_extend_gear_valve"]);
                copiedState.con_stop_stimulate_extend_gear_valve();
                copiedState.stateAccessedVia = "con_stop_stimulate_extend_gear_valve";
                result.insert(copiedState);
                transitions += 1;
            }
            BSet<LandingGear_R6::POSITION> _trid_19 = state._tr_env_start_retracting_first(isCaching);
            for(const LandingGear_R6::POSITION& param : _trid_19) {
                LandingGear_R6::POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy(guardDependency["env_start_retracting_first"]);
                copiedState.env_start_retracting_first(_tmp_1);
                copiedState.stateAccessedVia = "env_start_retracting_first";
                result.insert(copiedState);
                transitions += 1;
            }
            BSet<LandingGear_R6::POSITION> _trid_20 = state._tr_env_retract_gear_skip(isCaching);
            for(const LandingGear_R6::POSITION& param : _trid_20) {
                LandingGear_R6::POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy(guardDependency["env_retract_gear_skip"]);
                copiedState.env_retract_gear_skip(_tmp_1);
                copiedState.stateAccessedVia = "env_retract_gear_skip";
                result.insert(copiedState);
                transitions += 1;
            }
            BSet<LandingGear_R6::POSITION> _trid_21 = state._tr_env_retract_gear_last(isCaching);
            for(const LandingGear_R6::POSITION& param : _trid_21) {
                LandingGear_R6::POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy(guardDependency["env_retract_gear_last"]);
                copiedState.env_retract_gear_last(_tmp_1);
                copiedState.stateAccessedVia = "env_retract_gear_last";
                result.insert(copiedState);
                transitions += 1;
            }
            BSet<LandingGear_R6::POSITION> _trid_22 = state._tr_env_start_extending(isCaching);
            for(const LandingGear_R6::POSITION& param : _trid_22) {
                LandingGear_R6::POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy(guardDependency["env_start_extending"]);
                copiedState.env_start_extending(_tmp_1);
                copiedState.stateAccessedVia = "env_start_extending";
                result.insert(copiedState);
                transitions += 1;
            }
            BSet<LandingGear_R6::POSITION> _trid_23 = state._tr_env_extend_gear_last(isCaching);
            for(const LandingGear_R6::POSITION& param : _trid_23) {
                LandingGear_R6::POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy(guardDependency["env_extend_gear_last"]);
                copiedState.env_extend_gear_last(_tmp_1);
                copiedState.stateAccessedVia = "env_extend_gear_last";
                result.insert(copiedState);
                transitions += 1;
            }
            BSet<LandingGear_R6::POSITION> _trid_24 = state._tr_env_extend_gear_skip(isCaching);
            for(const LandingGear_R6::POSITION& param : _trid_24) {
                LandingGear_R6::POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy(guardDependency["env_extend_gear_skip"]);
                copiedState.env_extend_gear_skip(_tmp_1);
                copiedState.stateAccessedVia = "env_extend_gear_skip";
                result.insert(copiedState);
                transitions += 1;
            }
            BSet<LandingGear_R6::POSITION> _trid_25 = state._tr_env_start_open_door(isCaching);
            for(const LandingGear_R6::POSITION& param : _trid_25) {
                LandingGear_R6::POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy(guardDependency["env_start_open_door"]);
                copiedState.env_start_open_door(_tmp_1);
                copiedState.stateAccessedVia = "env_start_open_door";
                result.insert(copiedState);
                transitions += 1;
            }
            BSet<LandingGear_R6::POSITION> _trid_26 = state._tr_env_open_door_last(isCaching);
            for(const LandingGear_R6::POSITION& param : _trid_26) {
                LandingGear_R6::POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy(guardDependency["env_open_door_last"]);
                copiedState.env_open_door_last(_tmp_1);
                copiedState.stateAccessedVia = "env_open_door_last";
                result.insert(copiedState);
                transitions += 1;
            }
            BSet<LandingGear_R6::POSITION> _trid_27 = state._tr_env_open_door_skip(isCaching);
            for(const LandingGear_R6::POSITION& param : _trid_27) {
                LandingGear_R6::POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy(guardDependency["env_open_door_skip"]);
                copiedState.env_open_door_skip(_tmp_1);
                copiedState.stateAccessedVia = "env_open_door_skip";
                result.insert(copiedState);
                transitions += 1;
            }
            BSet<LandingGear_R6::POSITION> _trid_28 = state._tr_env_start_close_door(isCaching);
            for(const LandingGear_R6::POSITION& param : _trid_28) {
                LandingGear_R6::POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy(guardDependency["env_start_close_door"]);
                copiedState.env_start_close_door(_tmp_1);
                copiedState.stateAccessedVia = "env_start_close_door";
                result.insert(copiedState);
                transitions += 1;
            }
            BSet<LandingGear_R6::POSITION> _trid_29 = state._tr_env_close_door(isCaching);
            for(const LandingGear_R6::POSITION& param : _trid_29) {
                LandingGear_R6::POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy(guardDependency["env_close_door"]);
                copiedState.env_close_door(_tmp_1);
                copiedState.stateAccessedVia = "env_close_door";
                result.insert(copiedState);
                transitions += 1;
            }
            BSet<LandingGear_R6::POSITION> _trid_30 = state._tr_env_close_door_skip(isCaching);
            for(const LandingGear_R6::POSITION& param : _trid_30) {
                LandingGear_R6::POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy(guardDependency["env_close_door_skip"]);
                copiedState.env_close_door_skip(_tmp_1);
                copiedState.stateAccessedVia = "env_close_door_skip";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_toggle_handle_up(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["toggle_handle_up"]);
                copiedState.toggle_handle_up();
                copiedState.stateAccessedVia = "toggle_handle_up";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_toggle_handle_down(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["toggle_handle_down"]);
                copiedState.toggle_handle_down();
                copiedState.stateAccessedVia = "toggle_handle_down";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_con_stimulate_general_valve(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["con_stimulate_general_valve"]);
                copiedState.con_stimulate_general_valve();
                copiedState.stateAccessedVia = "con_stimulate_general_valve";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_con_stop_stimulate_general_valve(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["con_stop_stimulate_general_valve"]);
                copiedState.con_stop_stimulate_general_valve();
                copiedState.stateAccessedVia = "con_stop_stimulate_general_valve";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_evn_open_general_valve(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["evn_open_general_valve"]);
                copiedState.evn_open_general_valve();
                copiedState.stateAccessedVia = "evn_open_general_valve";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_evn_close_general_valve(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["evn_close_general_valve"]);
                copiedState.evn_close_general_valve();
                copiedState.stateAccessedVia = "evn_close_general_valve";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_env_close_analogical_switch(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["env_close_analogical_switch"]);
                copiedState.env_close_analogical_switch();
                copiedState.stateAccessedVia = "env_close_analogical_switch";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_env_open_analogical_switch(isCaching)) {
                LandingGear_R6 copiedState = state._copy(guardDependency["env_open_analogical_switch"]);
                copiedState.env_open_analogical_switch();
                copiedState.stateAccessedVia = "env_open_analogical_switch";
                result.insert(copiedState);
                transitions += 1;
            }

            return result;
        }

        bool invariantViolated(const LandingGear_R6& state) {
            std::unordered_set<string> dependentInvariantsOfState;
            if(isCaching) dependentInvariantsOfState = dependentInvariant[state];
            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_1") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_1()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_1" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_1()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_1" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_2") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_2()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_2" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_2()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_2" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_3") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_3()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_3" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_3()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_3" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_4") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_4()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_4" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_4()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_4" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_5") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_5()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_5" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_5()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_5" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_6") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_6()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_6" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_6()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_6" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_7") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_7()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_7" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_7()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_7" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_8") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_8()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_8" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_8()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_8" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_9") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_9()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_9" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_9()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_9" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_10") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_10()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_10" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_10()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_10" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_11") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_11()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_11" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_11()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_11" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_12") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_12()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_12" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_12()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_12" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_13") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_13()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_13" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_13()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_13" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_14") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_14()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_14" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_14()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_14" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_15") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_15()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_15" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_15()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_15" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_16") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_16()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_16" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_16()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_16" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_17") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_17()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_17" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_17()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_17" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_18") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_18()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_18" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_18()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_18" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_19") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_19()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_19" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_19()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_19" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_20") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_20()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_20" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_20()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_20" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_21") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_21()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_21" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_21()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_21" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_22") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_22()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_22" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_22()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_22" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_23") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_23()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_23" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_23()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_23" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_24") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_24()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_24" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_24()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_24" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_25") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_25()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_25" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_25()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_25" << "\n";
                  return true;
                }
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

    bool isDebug = true;
    // TODO

    ModelChecker modelchecker(type, threads, isCaching, isDebug);
    modelchecker.modelCheck();

    return 0;
}



#endif