#include <iostream>
#include <string>
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


    public:

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
            for(POSITION _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue())).booleanValue() && gears.functionCall(_ic_gr_1).equal((GEAR_STATE(GEAR_STATE::extended))).booleanValue())).booleanValue() && valve_retract_gear.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && (BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended)), (GEAR_STATE(GEAR_STATE::gear_moving)))).elementOf(gear).booleanValue())).booleanValue() && door.equal((DOOR_STATE(DOOR_STATE::open))).booleanValue()))).booleanValue()) {
                    _ic_set_18 = _ic_set_18._union(BSet<POSITION>(_ic_gr_1));
                }

            }
            return _ic_set_18;
        }

        BSet<POSITION> _tr_env_retract_gear_skip() const {
            BSet<POSITION> _ic_set_19 = BSet<POSITION>();
            for(POSITION _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean(doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue() && gears.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).unequal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue())).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue())).booleanValue() && gears.functionCall(_ic_gr_1).equal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue()))).booleanValue()) {
                    _ic_set_19 = _ic_set_19._union(BSet<POSITION>(_ic_gr_1));
                }

            }
            return _ic_set_19;
        }

        BSet<POSITION> _tr_env_retract_gear_last() const {
            BSet<POSITION> _ic_set_20 = BSet<POSITION>();
            for(POSITION _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue() && gears.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue())).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue())).booleanValue() && gears.functionCall(_ic_gr_1).equal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && door.equal((DOOR_STATE(DOOR_STATE::open))).booleanValue()))).booleanValue()) {
                    _ic_set_20 = _ic_set_20._union(BSet<POSITION>(_ic_gr_1));
                }

            }
            return _ic_set_20;
        }

        BSet<POSITION> _tr_env_start_extending() const {
            BSet<POSITION> _ic_set_21 = BSet<POSITION>();
            for(POSITION _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue())).booleanValue() && gears.functionCall(_ic_gr_1).equal((GEAR_STATE(GEAR_STATE::retracted))).booleanValue())).booleanValue() && valve_extend_gear.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && (BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::gear_moving)), (GEAR_STATE(GEAR_STATE::retracted)))).elementOf(gear).booleanValue())).booleanValue() && door.equal((DOOR_STATE(DOOR_STATE::open))).booleanValue()))).booleanValue()) {
                    _ic_set_21 = _ic_set_21._union(BSet<POSITION>(_ic_gr_1));
                }

            }
            return _ic_set_21;
        }

        BSet<POSITION> _tr_env_extend_gear_last() const {
            BSet<POSITION> _ic_set_22 = BSet<POSITION>();
            for(POSITION _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue())).booleanValue() && gears.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() && gears.functionCall(_ic_gr_1).equal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && door.equal((DOOR_STATE(DOOR_STATE::open))).booleanValue()))).booleanValue()) {
                    _ic_set_22 = _ic_set_22._union(BSet<POSITION>(_ic_gr_1));
                }

            }
            return _ic_set_22;
        }

        BSet<POSITION> _tr_env_extend_gear_skip() const {
            BSet<POSITION> _ic_set_23 = BSet<POSITION>();
            for(POSITION _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean(doors.range().equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue() && handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue())).booleanValue() && gears.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).unequal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() && gears.functionCall(_ic_gr_1).equal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue()))).booleanValue()) {
                    _ic_set_23 = _ic_set_23._union(BSet<POSITION>(_ic_gr_1));
                }

            }
            return _ic_set_23;
        }

        BSet<POSITION> _tr_env_start_open_door() const {
            BSet<POSITION> _ic_set_24 = BSet<POSITION>();
            for(POSITION _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.functionCall(_ic_gr_1).equal((DOOR_STATE(DOOR_STATE::closed))).booleanValue() && gears.functionCall(_ic_gr_1).unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && gears.range().notElementOf((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && valve_open_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && (BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed)), (DOOR_STATE(DOOR_STATE::door_moving)))).elementOf(door).booleanValue())).booleanValue() && gear.unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::retracted))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::extended))).booleanValue())).booleanValue())).booleanValue()))).booleanValue()) {
                    _ic_set_24 = _ic_set_24._union(BSet<POSITION>(_ic_gr_1));
                }

            }
            return _ic_set_24;
        }

        BSet<POSITION> _tr_env_open_door_last() const {
            BSet<POSITION> _ic_set_25 = BSet<POSITION>();
            for(POSITION _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.functionCall(_ic_gr_1).equal((DOOR_STATE(DOOR_STATE::door_moving))).booleanValue() && gears.functionCall(_ic_gr_1).unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && gears.range().notElementOf((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && doors.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && valve_open_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && door.equal((DOOR_STATE(DOOR_STATE::door_moving))).booleanValue())).booleanValue() && gear.unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::retracted))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::extended))).booleanValue())).booleanValue())).booleanValue()))).booleanValue()) {
                    _ic_set_25 = _ic_set_25._union(BSet<POSITION>(_ic_gr_1));
                }

            }
            return _ic_set_25;
        }

        BSet<POSITION> _tr_env_open_door_skip() const {
            BSet<POSITION> _ic_set_26 = BSet<POSITION>();
            for(POSITION _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.functionCall(_ic_gr_1).equal((DOOR_STATE(DOOR_STATE::door_moving))).booleanValue() && gears.functionCall(_ic_gr_1).unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && gears.range().notElementOf((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && doors.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).unequal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::open))))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && valve_open_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue()))).booleanValue()) {
                    _ic_set_26 = _ic_set_26._union(BSet<POSITION>(_ic_gr_1));
                }

            }
            return _ic_set_26;
        }

        BSet<POSITION> _tr_env_start_close_door() const {
            BSet<POSITION> _ic_set_27 = BSet<POSITION>();
            for(POSITION _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.functionCall(_ic_gr_1).equal((DOOR_STATE(DOOR_STATE::open))).booleanValue() && gears.functionCall(_ic_gr_1).unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && (BBoolean(gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue() || gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && valve_close_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && (BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::door_moving)), (DOOR_STATE(DOOR_STATE::open)))).elementOf(door).booleanValue())).booleanValue() && gear.unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::extended))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && (BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended)), (GEAR_STATE(GEAR_STATE::retracted)))).elementOf(gear).booleanValue())).booleanValue())).booleanValue()))).booleanValue()) {
                    _ic_set_27 = _ic_set_27._union(BSet<POSITION>(_ic_gr_1));
                }

            }
            return _ic_set_27;
        }

        BSet<POSITION> _tr_env_close_door() const {
            BSet<POSITION> _ic_set_28 = BSet<POSITION>();
            for(POSITION _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.functionCall(_ic_gr_1).equal((DOOR_STATE(DOOR_STATE::door_moving))).booleanValue() && gears.functionCall(_ic_gr_1).unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && gears.range().notElementOf((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && doors.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).equal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed))))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && (BBoolean(gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue() || gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && valve_close_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() || shock_absorber.equal((PLANE_STATE(PLANE_STATE::ground))).booleanValue())).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && door.equal((DOOR_STATE(DOOR_STATE::door_moving))).booleanValue())).booleanValue() && gear.unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gear.equal((GEAR_STATE(GEAR_STATE::extended))).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && (BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended)), (GEAR_STATE(GEAR_STATE::retracted)))).elementOf(gear).booleanValue())).booleanValue())).booleanValue()))).booleanValue()) {
                    _ic_set_28 = _ic_set_28._union(BSet<POSITION>(_ic_gr_1));
                }

            }
            return _ic_set_28;
        }

        BSet<POSITION> _tr_env_close_door_skip() const {
            BSet<POSITION> _ic_set_29 = BSet<POSITION>();
            for(POSITION _ic_gr_1 : gears.domain()) {
                if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(doors.functionCall(_ic_gr_1).equal((DOOR_STATE(DOOR_STATE::door_moving))).booleanValue() && gears.functionCall(_ic_gr_1).unequal((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && gears.range().notElementOf((GEAR_STATE(GEAR_STATE::gear_moving))).booleanValue())).booleanValue() && doors.relationImage(_POSITION.difference((BSet<POSITION >(_ic_gr_1)))).unequal((BSet<DOOR_STATE >((DOOR_STATE(DOOR_STATE::closed))))).booleanValue())).booleanValue() && (BBoolean((BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && (BBoolean(gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::retracted))))).booleanValue() || gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue() || (BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::down))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue())).booleanValue())).booleanValue() && valve_close_door.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(handle.equal((HANDLE_STATE(HANDLE_STATE::up))).booleanValue() && gears.range().equal((BSet<GEAR_STATE >((GEAR_STATE(GEAR_STATE::extended))))).booleanValue())).booleanValue() || shock_absorber.equal((PLANE_STATE(PLANE_STATE::ground))).booleanValue())).booleanValue())).booleanValue() && general_valve.equal((VALVE_STATE(VALVE_STATE::valve_open))).booleanValue()))).booleanValue()) {
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

        LandingGear_R6 _copy() const {
            return LandingGear_R6(analogical_switch, general_EV, general_valve, handle_move, close_EV, extend_EV, open_EV, retract_EV, shock_absorber, valve_close_door, valve_extend_gear, valve_open_door, valve_retract_gear, doors, gears, handle, door, gear);
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


static std::unordered_set<LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual> generateNextStates(std::mutex& guardMutex, const LandingGear_R6& state, bool isCaching, std::unordered_map<string, std::unordered_set<string>>& invariantDependency, std::unordered_map<LandingGear_R6, std::unordered_set<string>, LandingGear_R6::Hash, LandingGear_R6::HashEqual>& dependentInvariant, std::unordered_map<string, std::unordered_set<string>>& guardDependency, std::unordered_map<LandingGear_R6, std::unordered_set<string>, LandingGear_R6::Hash, LandingGear_R6::HashEqual>& dependentGuard, std::unordered_map<LandingGear_R6, immer::map<string, boost::any>, LandingGear_R6::Hash, LandingGear_R6::HashEqual>& guardCache, std::unordered_map<LandingGear_R6, LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual>& parents, std::atomic<int>& transitions) {
    std::unordered_set<LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual> result = std::unordered_set<LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual>();
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
            cachedValue = parentsGuard["_tr_begin_flying"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_begin_flying") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_1 = state._tr_begin_flying();
        } else {
            _trid_1 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_begin_flying", _trid_1);
        if(_trid_1) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.begin_flying();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["begin_flying"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["begin_flying"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_2;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_land_plane"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_land_plane") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_2 = state._tr_land_plane();
        } else {
            _trid_2 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_land_plane", _trid_2);
        if(_trid_2) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.land_plane();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["land_plane"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["land_plane"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_3;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_open_valve_door_open"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_open_valve_door_open") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_3 = state._tr_open_valve_door_open();
        } else {
            _trid_3 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_open_valve_door_open", _trid_3);
        if(_trid_3) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.open_valve_door_open();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["open_valve_door_open"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["open_valve_door_open"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_4;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_close_valve_door_open"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_close_valve_door_open") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_4 = state._tr_close_valve_door_open();
        } else {
            _trid_4 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_close_valve_door_open", _trid_4);
        if(_trid_4) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.close_valve_door_open();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["close_valve_door_open"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["close_valve_door_open"]});
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
            cachedValue = parentsGuard["_tr_open_valve_door_close"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_open_valve_door_close") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_5 = state._tr_open_valve_door_close();
        } else {
            _trid_5 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_open_valve_door_close", _trid_5);
        if(_trid_5) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.open_valve_door_close();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["open_valve_door_close"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["open_valve_door_close"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_6;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_close_valve_door_close"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_close_valve_door_close") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_6 = state._tr_close_valve_door_close();
        } else {
            _trid_6 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_close_valve_door_close", _trid_6);
        if(_trid_6) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.close_valve_door_close();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["close_valve_door_close"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["close_valve_door_close"]});
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
            cachedValue = parentsGuard["_tr_open_valve_retract_gear"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_open_valve_retract_gear") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_7 = state._tr_open_valve_retract_gear();
        } else {
            _trid_7 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_open_valve_retract_gear", _trid_7);
        if(_trid_7) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.open_valve_retract_gear();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["open_valve_retract_gear"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["open_valve_retract_gear"]});
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
            cachedValue = parentsGuard["_tr_close_valve_retract_gear"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_close_valve_retract_gear") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_8 = state._tr_close_valve_retract_gear();
        } else {
            _trid_8 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_close_valve_retract_gear", _trid_8);
        if(_trid_8) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.close_valve_retract_gear();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["close_valve_retract_gear"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["close_valve_retract_gear"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_9;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_open_valve_extend_gear"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_open_valve_extend_gear") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_9 = state._tr_open_valve_extend_gear();
        } else {
            _trid_9 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_open_valve_extend_gear", _trid_9);
        if(_trid_9) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.open_valve_extend_gear();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["open_valve_extend_gear"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["open_valve_extend_gear"]});
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
            cachedValue = parentsGuard["_tr_close_valve_extend_gear"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_close_valve_extend_gear") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_10 = state._tr_close_valve_extend_gear();
        } else {
            _trid_10 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_close_valve_extend_gear", _trid_10);
        if(_trid_10) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.close_valve_extend_gear();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["close_valve_extend_gear"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["close_valve_extend_gear"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_11;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_con_stimulate_open_door_valve"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_con_stimulate_open_door_valve") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_11 = state._tr_con_stimulate_open_door_valve();
        } else {
            _trid_11 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_con_stimulate_open_door_valve", _trid_11);
        if(_trid_11) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.con_stimulate_open_door_valve();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["con_stimulate_open_door_valve"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["con_stimulate_open_door_valve"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_12;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_con_stop_stimulate_open_door_valve"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_con_stop_stimulate_open_door_valve") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_12 = state._tr_con_stop_stimulate_open_door_valve();
        } else {
            _trid_12 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_con_stop_stimulate_open_door_valve", _trid_12);
        if(_trid_12) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.con_stop_stimulate_open_door_valve();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["con_stop_stimulate_open_door_valve"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["con_stop_stimulate_open_door_valve"]});
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
            cachedValue = parentsGuard["_tr_con_stimulate_close_door_valve"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_con_stimulate_close_door_valve") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_13 = state._tr_con_stimulate_close_door_valve();
        } else {
            _trid_13 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_con_stimulate_close_door_valve", _trid_13);
        if(_trid_13) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.con_stimulate_close_door_valve();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["con_stimulate_close_door_valve"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["con_stimulate_close_door_valve"]});
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
            cachedValue = parentsGuard["_tr_con_stop_stimulate_close_door_valve"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_con_stop_stimulate_close_door_valve") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_14 = state._tr_con_stop_stimulate_close_door_valve();
        } else {
            _trid_14 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_con_stop_stimulate_close_door_valve", _trid_14);
        if(_trid_14) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.con_stop_stimulate_close_door_valve();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["con_stop_stimulate_close_door_valve"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["con_stop_stimulate_close_door_valve"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_15;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_con_stimulate_retract_gear_valve"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_con_stimulate_retract_gear_valve") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_15 = state._tr_con_stimulate_retract_gear_valve();
        } else {
            _trid_15 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_con_stimulate_retract_gear_valve", _trid_15);
        if(_trid_15) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.con_stimulate_retract_gear_valve();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["con_stimulate_retract_gear_valve"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["con_stimulate_retract_gear_valve"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_16;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_con_stop_stimulate_retract_gear_valve"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_con_stop_stimulate_retract_gear_valve") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_16 = state._tr_con_stop_stimulate_retract_gear_valve();
        } else {
            _trid_16 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_con_stop_stimulate_retract_gear_valve", _trid_16);
        if(_trid_16) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.con_stop_stimulate_retract_gear_valve();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["con_stop_stimulate_retract_gear_valve"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["con_stop_stimulate_retract_gear_valve"]});
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
            cachedValue = parentsGuard["_tr_con_stimulate_extend_gear_valve"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_con_stimulate_extend_gear_valve") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_17 = state._tr_con_stimulate_extend_gear_valve();
        } else {
            _trid_17 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_con_stimulate_extend_gear_valve", _trid_17);
        if(_trid_17) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.con_stimulate_extend_gear_valve();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["con_stimulate_extend_gear_valve"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["con_stimulate_extend_gear_valve"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_18;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_con_stop_stimulate_extend_gear_valve"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_con_stop_stimulate_extend_gear_valve") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_18 = state._tr_con_stop_stimulate_extend_gear_valve();
        } else {
            _trid_18 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_con_stop_stimulate_extend_gear_valve", _trid_18);
        if(_trid_18) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.con_stop_stimulate_extend_gear_valve();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["con_stop_stimulate_extend_gear_valve"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["con_stop_stimulate_extend_gear_valve"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_19;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_env_start_retracting_first"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_env_start_retracting_first") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_19 = state._tr_env_start_retracting_first();
        } else {
            _trid_19 = boost::any_cast<BSet<LandingGear_R6::POSITION>>(cachedValue);
        }
        newCache = newCache.set("_tr_env_start_retracting_first", _trid_19);
        for(const LandingGear_R6::POSITION& param : _trid_19) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_start_retracting_first(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["env_start_retracting_first"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["env_start_retracting_first"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_20;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_env_retract_gear_skip"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_env_retract_gear_skip") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_20 = state._tr_env_retract_gear_skip();
        } else {
            _trid_20 = boost::any_cast<BSet<LandingGear_R6::POSITION>>(cachedValue);
        }
        newCache = newCache.set("_tr_env_retract_gear_skip", _trid_20);
        for(const LandingGear_R6::POSITION& param : _trid_20) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_retract_gear_skip(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["env_retract_gear_skip"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["env_retract_gear_skip"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_21;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_env_retract_gear_last"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_env_retract_gear_last") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_21 = state._tr_env_retract_gear_last();
        } else {
            _trid_21 = boost::any_cast<BSet<LandingGear_R6::POSITION>>(cachedValue);
        }
        newCache = newCache.set("_tr_env_retract_gear_last", _trid_21);
        for(const LandingGear_R6::POSITION& param : _trid_21) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_retract_gear_last(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["env_retract_gear_last"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["env_retract_gear_last"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_22;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_env_start_extending"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_env_start_extending") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_22 = state._tr_env_start_extending();
        } else {
            _trid_22 = boost::any_cast<BSet<LandingGear_R6::POSITION>>(cachedValue);
        }
        newCache = newCache.set("_tr_env_start_extending", _trid_22);
        for(const LandingGear_R6::POSITION& param : _trid_22) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_start_extending(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["env_start_extending"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["env_start_extending"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_23;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_env_extend_gear_last"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_env_extend_gear_last") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_23 = state._tr_env_extend_gear_last();
        } else {
            _trid_23 = boost::any_cast<BSet<LandingGear_R6::POSITION>>(cachedValue);
        }
        newCache = newCache.set("_tr_env_extend_gear_last", _trid_23);
        for(const LandingGear_R6::POSITION& param : _trid_23) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_extend_gear_last(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["env_extend_gear_last"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["env_extend_gear_last"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_24;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_env_extend_gear_skip"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_env_extend_gear_skip") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_24 = state._tr_env_extend_gear_skip();
        } else {
            _trid_24 = boost::any_cast<BSet<LandingGear_R6::POSITION>>(cachedValue);
        }
        newCache = newCache.set("_tr_env_extend_gear_skip", _trid_24);
        for(const LandingGear_R6::POSITION& param : _trid_24) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_extend_gear_skip(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["env_extend_gear_skip"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["env_extend_gear_skip"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_25;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_env_start_open_door"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_env_start_open_door") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_25 = state._tr_env_start_open_door();
        } else {
            _trid_25 = boost::any_cast<BSet<LandingGear_R6::POSITION>>(cachedValue);
        }
        newCache = newCache.set("_tr_env_start_open_door", _trid_25);
        for(const LandingGear_R6::POSITION& param : _trid_25) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_start_open_door(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["env_start_open_door"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["env_start_open_door"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_26;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_env_open_door_last"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_env_open_door_last") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_26 = state._tr_env_open_door_last();
        } else {
            _trid_26 = boost::any_cast<BSet<LandingGear_R6::POSITION>>(cachedValue);
        }
        newCache = newCache.set("_tr_env_open_door_last", _trid_26);
        for(const LandingGear_R6::POSITION& param : _trid_26) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_open_door_last(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["env_open_door_last"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["env_open_door_last"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_27;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_env_open_door_skip"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_env_open_door_skip") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_27 = state._tr_env_open_door_skip();
        } else {
            _trid_27 = boost::any_cast<BSet<LandingGear_R6::POSITION>>(cachedValue);
        }
        newCache = newCache.set("_tr_env_open_door_skip", _trid_27);
        for(const LandingGear_R6::POSITION& param : _trid_27) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_open_door_skip(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["env_open_door_skip"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["env_open_door_skip"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_28;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_env_start_close_door"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_env_start_close_door") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_28 = state._tr_env_start_close_door();
        } else {
            _trid_28 = boost::any_cast<BSet<LandingGear_R6::POSITION>>(cachedValue);
        }
        newCache = newCache.set("_tr_env_start_close_door", _trid_28);
        for(const LandingGear_R6::POSITION& param : _trid_28) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_start_close_door(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["env_start_close_door"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["env_start_close_door"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_29;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_env_close_door"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_env_close_door") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_29 = state._tr_env_close_door();
        } else {
            _trid_29 = boost::any_cast<BSet<LandingGear_R6::POSITION>>(cachedValue);
        }
        newCache = newCache.set("_tr_env_close_door", _trid_29);
        for(const LandingGear_R6::POSITION& param : _trid_29) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_close_door(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["env_close_door"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["env_close_door"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_30;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_env_close_door_skip"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_env_close_door_skip") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_30 = state._tr_env_close_door_skip();
        } else {
            _trid_30 = boost::any_cast<BSet<LandingGear_R6::POSITION>>(cachedValue);
        }
        newCache = newCache.set("_tr_env_close_door_skip", _trid_30);
        for(const LandingGear_R6::POSITION& param : _trid_30) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_close_door_skip(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["env_close_door_skip"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["env_close_door_skip"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_31;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_toggle_handle_up"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_toggle_handle_up") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_31 = state._tr_toggle_handle_up();
        } else {
            _trid_31 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_toggle_handle_up", _trid_31);
        if(_trid_31) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.toggle_handle_up();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["toggle_handle_up"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["toggle_handle_up"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_32;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_toggle_handle_down"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_toggle_handle_down") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_32 = state._tr_toggle_handle_down();
        } else {
            _trid_32 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_toggle_handle_down", _trid_32);
        if(_trid_32) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.toggle_handle_down();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["toggle_handle_down"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["toggle_handle_down"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_33;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_con_stimulate_general_valve"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_con_stimulate_general_valve") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_33 = state._tr_con_stimulate_general_valve();
        } else {
            _trid_33 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_con_stimulate_general_valve", _trid_33);
        if(_trid_33) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.con_stimulate_general_valve();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["con_stimulate_general_valve"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["con_stimulate_general_valve"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_34;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_con_stop_stimulate_general_valve"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_con_stop_stimulate_general_valve") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_34 = state._tr_con_stop_stimulate_general_valve();
        } else {
            _trid_34 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_con_stop_stimulate_general_valve", _trid_34);
        if(_trid_34) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.con_stop_stimulate_general_valve();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["con_stop_stimulate_general_valve"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["con_stop_stimulate_general_valve"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_35;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_evn_open_general_valve"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_evn_open_general_valve") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_35 = state._tr_evn_open_general_valve();
        } else {
            _trid_35 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_evn_open_general_valve", _trid_35);
        if(_trid_35) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.evn_open_general_valve();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["evn_open_general_valve"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["evn_open_general_valve"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_36;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_evn_close_general_valve"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_evn_close_general_valve") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_36 = state._tr_evn_close_general_valve();
        } else {
            _trid_36 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_evn_close_general_valve", _trid_36);
        if(_trid_36) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.evn_close_general_valve();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["evn_close_general_valve"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["evn_close_general_valve"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_37;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_env_close_analogical_switch"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_env_close_analogical_switch") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_37 = state._tr_env_close_analogical_switch();
        } else {
            _trid_37 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_env_close_analogical_switch", _trid_37);
        if(_trid_37) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.env_close_analogical_switch();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["env_close_analogical_switch"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["env_close_analogical_switch"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_38;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_env_open_analogical_switch"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_env_open_analogical_switch") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_38 = state._tr_env_open_analogical_switch();
        } else {
            _trid_38 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_env_open_analogical_switch", _trid_38);
        if(_trid_38) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.env_open_analogical_switch();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["env_open_analogical_switch"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["env_open_analogical_switch"]});
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
        if(state._tr_begin_flying()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.begin_flying();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_land_plane()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.land_plane();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_open_valve_door_open()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.open_valve_door_open();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_close_valve_door_open()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.close_valve_door_open();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_open_valve_door_close()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.open_valve_door_close();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_close_valve_door_close()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.close_valve_door_close();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_open_valve_retract_gear()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.open_valve_retract_gear();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_close_valve_retract_gear()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.close_valve_retract_gear();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_open_valve_extend_gear()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.open_valve_extend_gear();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_close_valve_extend_gear()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.close_valve_extend_gear();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_con_stimulate_open_door_valve()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.con_stimulate_open_door_valve();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_con_stop_stimulate_open_door_valve()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.con_stop_stimulate_open_door_valve();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_con_stimulate_close_door_valve()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.con_stimulate_close_door_valve();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_con_stop_stimulate_close_door_valve()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.con_stop_stimulate_close_door_valve();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_con_stimulate_retract_gear_valve()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.con_stimulate_retract_gear_valve();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_con_stop_stimulate_retract_gear_valve()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.con_stop_stimulate_retract_gear_valve();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_con_stimulate_extend_gear_valve()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.con_stimulate_extend_gear_valve();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_con_stop_stimulate_extend_gear_valve()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.con_stop_stimulate_extend_gear_valve();
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_19 = state._tr_env_start_retracting_first();
        for(const LandingGear_R6::POSITION& param : _trid_19) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_start_retracting_first(_tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_20 = state._tr_env_retract_gear_skip();
        for(const LandingGear_R6::POSITION& param : _trid_20) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_retract_gear_skip(_tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_21 = state._tr_env_retract_gear_last();
        for(const LandingGear_R6::POSITION& param : _trid_21) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_retract_gear_last(_tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_22 = state._tr_env_start_extending();
        for(const LandingGear_R6::POSITION& param : _trid_22) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_start_extending(_tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_23 = state._tr_env_extend_gear_last();
        for(const LandingGear_R6::POSITION& param : _trid_23) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_extend_gear_last(_tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_24 = state._tr_env_extend_gear_skip();
        for(const LandingGear_R6::POSITION& param : _trid_24) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_extend_gear_skip(_tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_25 = state._tr_env_start_open_door();
        for(const LandingGear_R6::POSITION& param : _trid_25) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_start_open_door(_tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_26 = state._tr_env_open_door_last();
        for(const LandingGear_R6::POSITION& param : _trid_26) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_open_door_last(_tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_27 = state._tr_env_open_door_skip();
        for(const LandingGear_R6::POSITION& param : _trid_27) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_open_door_skip(_tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_28 = state._tr_env_start_close_door();
        for(const LandingGear_R6::POSITION& param : _trid_28) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_start_close_door(_tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_29 = state._tr_env_close_door();
        for(const LandingGear_R6::POSITION& param : _trid_29) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_close_door(_tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<LandingGear_R6::POSITION> _trid_30 = state._tr_env_close_door_skip();
        for(const LandingGear_R6::POSITION& param : _trid_30) {
            LandingGear_R6::POSITION _tmp_1 = param;

            LandingGear_R6 copiedState = state._copy();
            copiedState.env_close_door_skip(_tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_toggle_handle_up()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.toggle_handle_up();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_toggle_handle_down()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.toggle_handle_down();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_con_stimulate_general_valve()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.con_stimulate_general_valve();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_con_stop_stimulate_general_valve()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.con_stop_stimulate_general_valve();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_evn_open_general_valve()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.evn_open_general_valve();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_evn_close_general_valve()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.evn_close_general_valve();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_env_close_analogical_switch()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.env_close_analogical_switch();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_env_open_analogical_switch()) {
            LandingGear_R6 copiedState = state._copy();
            copiedState.env_open_analogical_switch();
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

static bool checkInvariants(std::mutex& guardMutex, const LandingGear_R6& state, bool isCaching, std::unordered_map<LandingGear_R6, std::unordered_set<string>, LandingGear_R6::Hash, LandingGear_R6::HashEqual>& dependentInvariant) {
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
        if(dependentInvariantsOfState.find("_check_inv_21") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_21()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_22") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_22()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_23") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_23()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_24") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_24()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_25") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_25()) {
                return false;
            }
        }
        return true;
    }
    return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6() || !state._check_inv_7() || !state._check_inv_8() || !state._check_inv_9() || !state._check_inv_10() || !state._check_inv_11() || !state._check_inv_12() || !state._check_inv_13() || !state._check_inv_14() || !state._check_inv_15() || !state._check_inv_16() || !state._check_inv_17() || !state._check_inv_18() || !state._check_inv_19() || !state._check_inv_20() || !state._check_inv_21() || !state._check_inv_22() || !state._check_inv_23() || !state._check_inv_24() || !state._check_inv_25());
}

static LandingGear_R6 next(std::list<LandingGear_R6>& collection, std::mutex& mutex, LandingGear_R6::Type type) {
    std::unique_lock<std::mutex> lock(mutex);
    switch(type) {
        case LandingGear_R6::BFS: {
            LandingGear_R6 state = collection.front();
            collection.pop_front();
            return state;
        }
        case LandingGear_R6::DFS: {
            LandingGear_R6 state = collection.back();
            collection.pop_back();
            return state;
        }
        case LandingGear_R6::MIXED: {
            if(collection.size() % 2 == 0) {
                LandingGear_R6 state = collection.front();
                collection.pop_front();
                return state;
            } else {
                LandingGear_R6 state = collection.back();
                collection.pop_back();
                return state;
            }
        }
    };
}

static void modelCheckSingleThreaded(LandingGear_R6::Type type, bool isCaching) {
    std::mutex mutex;
    std::mutex guardMutex;

    LandingGear_R6 machine = LandingGear_R6();

    std::atomic<bool> invariantViolated;
    invariantViolated = false;
    std::atomic<bool> deadlockDetected;
    deadlockDetected = false;
    std::atomic<bool> stopThreads;
    stopThreads = false;

    if(!machine._check_inv_1() || !machine._check_inv_2() || !machine._check_inv_3() || !machine._check_inv_4() || !machine._check_inv_5() || !machine._check_inv_6() || !machine._check_inv_7() || !machine._check_inv_8() || !machine._check_inv_9() || !machine._check_inv_10() || !machine._check_inv_11() || !machine._check_inv_12() || !machine._check_inv_13() || !machine._check_inv_14() || !machine._check_inv_15() || !machine._check_inv_16() || !machine._check_inv_17() || !machine._check_inv_18() || !machine._check_inv_19() || !machine._check_inv_20() || !machine._check_inv_21() || !machine._check_inv_22() || !machine._check_inv_23() || !machine._check_inv_24() || !machine._check_inv_25()) {
        invariantViolated = true;
    }

    std::unordered_set<LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual> states = std::unordered_set<LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual>();
    states.insert(machine);
    std::atomic<int> numberStates;
    numberStates = 1;

    std::list<LandingGear_R6> collection = std::list<LandingGear_R6>();
    collection.push_back(machine);

    std::atomic<int> transitions;
    transitions = 0;

    std::unordered_map<string, std::unordered_set<string>> invariantDependency;
    std::unordered_map<string, std::unordered_set<string>> guardDependency;
    std::unordered_map<LandingGear_R6, std::unordered_set<string>, LandingGear_R6::Hash, LandingGear_R6::HashEqual> dependentInvariant;
    std::unordered_map<LandingGear_R6, std::unordered_set<string>, LandingGear_R6::Hash, LandingGear_R6::HashEqual> dependentGuard;
    std::unordered_map<LandingGear_R6, immer::map<string, boost::any>, LandingGear_R6::Hash, LandingGear_R6::HashEqual> guardCache;
    std::unordered_map<LandingGear_R6, LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual> parents;
    if(isCaching) {
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
        dependentInvariant.insert({machine, std::unordered_set<string>()});
    }

    while(!collection.empty() && !stopThreads) {
        LandingGear_R6 state = next(collection, mutex, type);
        std::unordered_set<LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual> nextStates = generateNextStates(guardMutex, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, transitions);
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

        if(!checkInvariants(guardMutex, state, isCaching, dependentInvariant)) {
            invariantViolated = true;
            stopThreads = true;
        }

    }
    printResult(numberStates, transitions, deadlockDetected, invariantViolated);
}

static void modelCheckMultiThreaded(LandingGear_R6::Type type, int threads, bool isCaching) {
    std::mutex mutex;
    std::mutex waitMutex;
    std::mutex guardMutex;
    std::condition_variable waitCV;

    LandingGear_R6 machine = LandingGear_R6();


    std::atomic<bool> invariantViolated;
    invariantViolated = false;
    std::atomic<bool> deadlockDetected;
    deadlockDetected = false;
    std::atomic<bool> stopThreads;
    stopThreads = false;

    if(!machine._check_inv_1() || !machine._check_inv_2() || !machine._check_inv_3() || !machine._check_inv_4() || !machine._check_inv_5() || !machine._check_inv_6() || !machine._check_inv_7() || !machine._check_inv_8() || !machine._check_inv_9() || !machine._check_inv_10() || !machine._check_inv_11() || !machine._check_inv_12() || !machine._check_inv_13() || !machine._check_inv_14() || !machine._check_inv_15() || !machine._check_inv_16() || !machine._check_inv_17() || !machine._check_inv_18() || !machine._check_inv_19() || !machine._check_inv_20() || !machine._check_inv_21() || !machine._check_inv_22() || !machine._check_inv_23() || !machine._check_inv_24() || !machine._check_inv_25()) {
        invariantViolated = true;
    }

    std::unordered_set<LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual> states = std::unordered_set<LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual>();
    states.insert(machine);
    std::atomic<int> numberStates;
    numberStates = 1;

    std::list<LandingGear_R6> collection = std::list<LandingGear_R6>();
    collection.push_back(machine);

    std::atomic<int> transitions;
    transitions = 0;

    std::atomic<int> possibleQueueChanges;
    possibleQueueChanges = 0;

    std::atomic<bool> waitFlag;
    waitFlag = true;

    std::unordered_map<string, std::unordered_set<string>> invariantDependency;
    std::unordered_map<string, std::unordered_set<string>> guardDependency;
    std::unordered_map<LandingGear_R6, std::unordered_set<string>, LandingGear_R6::Hash, LandingGear_R6::HashEqual> dependentInvariant;
    std::unordered_map<LandingGear_R6, std::unordered_set<string>, LandingGear_R6::Hash, LandingGear_R6::HashEqual> dependentGuard;
    std::unordered_map<LandingGear_R6, immer::map<string, boost::any>, LandingGear_R6::Hash, LandingGear_R6::HashEqual> guardCache;
    std::unordered_map<LandingGear_R6, LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual> parents;
    if(isCaching) {
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
        dependentInvariant.insert({machine, std::unordered_set<string>()});
    }

    boost::asio::thread_pool workers(threads);

    while(!collection.empty() && !stopThreads) {
        possibleQueueChanges += 1;
        LandingGear_R6 state = next(collection, mutex, type);
        std::packaged_task<void()> task([&, state] {
            std::unordered_set<LandingGear_R6, LandingGear_R6::Hash, LandingGear_R6::HashEqual> nextStates = generateNextStates(guardMutex, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, transitions);


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
    if(argc != 3) {
        cout << "Number of arguments errorneous\n";
        return -1;
    }
    string strategy = argv[0];
    string numberThreads = argv[1];
    string caching = argv[2];

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
    } else if(std::string("false").compare(strategy) == 0) {
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