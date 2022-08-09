import de.hhu.stups.btypes.BRelation;
import de.hhu.stups.btypes.BTuple;
import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BObject;
import de.hhu.stups.btypes.BBoolean;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.Future;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import clojure.java.api.Clojure;
import clojure.lang.PersistentHashMap;
import clojure.lang.RT;
import clojure.lang.Var;
import java.util.Objects;
import java.util.Arrays;
import de.hhu.stups.btypes.PreconditionOrAssertionViolation;
import de.hhu.stups.btypes.StateNotReachableError;
import de.hhu.stups.btypes.BUtils;


public class LandingGear_R6 {


    private static final Var ASSOC;
    private static final Var GET;

    static {
        RT.var("clojure.core", "require").invoke(Clojure.read("clojure.set"));
        ASSOC = RT.var("clojure.core", "assoc");
        GET = RT.var("clojure.core", "get");
    }

    public static enum Type {
        BFS,
        DFS,
        MIXED
    }





    public enum DOOR_STATE implements BObject {
        open,
        closed,
        door_moving;

        public BBoolean equal(DOOR_STATE o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(DOOR_STATE o) {
            return new BBoolean(this != o);
        }
    }

    public enum GEAR_STATE implements BObject {
        retracted,
        extended,
        gear_moving;

        public BBoolean equal(GEAR_STATE o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(GEAR_STATE o) {
            return new BBoolean(this != o);
        }
    }

    public enum HANDLE_STATE implements BObject {
        up,
        down;

        public BBoolean equal(HANDLE_STATE o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(HANDLE_STATE o) {
            return new BBoolean(this != o);
        }
    }

    public enum POSITION implements BObject {
        fr,
        lt,
        rt;

        public BBoolean equal(POSITION o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(POSITION o) {
            return new BBoolean(this != o);
        }
    }

    public enum SWITCH_STATE implements BObject {
        switch_open,
        switch_closed;

        public BBoolean equal(SWITCH_STATE o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(SWITCH_STATE o) {
            return new BBoolean(this != o);
        }
    }

    public enum PLANE_STATE implements BObject {
        ground,
        flight;

        public BBoolean equal(PLANE_STATE o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(PLANE_STATE o) {
            return new BBoolean(this != o);
        }
    }

    public enum VALVE_STATE implements BObject {
        valve_open,
        valve_closed;

        public BBoolean equal(VALVE_STATE o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(VALVE_STATE o) {
            return new BBoolean(this != o);
        }
    }

    private static BSet<DOOR_STATE> _DOOR_STATE = new BSet<DOOR_STATE>(DOOR_STATE.open, DOOR_STATE.closed, DOOR_STATE.door_moving);
    private static BSet<GEAR_STATE> _GEAR_STATE = new BSet<GEAR_STATE>(GEAR_STATE.retracted, GEAR_STATE.extended, GEAR_STATE.gear_moving);
    private static BSet<HANDLE_STATE> _HANDLE_STATE = new BSet<HANDLE_STATE>(HANDLE_STATE.up, HANDLE_STATE.down);
    private static BSet<POSITION> _POSITION = new BSet<POSITION>(POSITION.fr, POSITION.lt, POSITION.rt);
    private static BSet<SWITCH_STATE> _SWITCH_STATE = new BSet<SWITCH_STATE>(SWITCH_STATE.switch_open, SWITCH_STATE.switch_closed);
    private static BSet<PLANE_STATE> _PLANE_STATE = new BSet<PLANE_STATE>(PLANE_STATE.ground, PLANE_STATE.flight);
    private static BSet<VALVE_STATE> _VALVE_STATE = new BSet<VALVE_STATE>(VALVE_STATE.valve_open, VALVE_STATE.valve_closed);

    private SWITCH_STATE analogical_switch;
    private BBoolean general_EV;
    private VALVE_STATE general_valve;
    private BBoolean handle_move;
    private BBoolean close_EV;
    private BBoolean extend_EV;
    private BBoolean open_EV;
    private BBoolean retract_EV;
    private PLANE_STATE shock_absorber;
    private VALVE_STATE valve_close_door;
    private VALVE_STATE valve_extend_gear;
    private VALVE_STATE valve_open_door;
    private VALVE_STATE valve_retract_gear;
    private BRelation<POSITION, DOOR_STATE> doors;
    private BRelation<POSITION, GEAR_STATE> gears;
    private HANDLE_STATE handle;
    private DOOR_STATE door;
    private GEAR_STATE gear;

    public LandingGear_R6() {
        gears = BRelation.cartesianProduct(_POSITION, new BSet<GEAR_STATE>(GEAR_STATE.extended));
        doors = BRelation.cartesianProduct(_POSITION, new BSet<DOOR_STATE>(DOOR_STATE.closed));
        handle = HANDLE_STATE.down;
        valve_extend_gear = VALVE_STATE.valve_closed;
        valve_retract_gear = VALVE_STATE.valve_closed;
        valve_open_door = VALVE_STATE.valve_closed;
        valve_close_door = VALVE_STATE.valve_closed;
        open_EV = new BBoolean(false);
        close_EV = new BBoolean(false);
        retract_EV = new BBoolean(false);
        extend_EV = new BBoolean(false);
        shock_absorber = PLANE_STATE.ground;
        general_EV = new BBoolean(false);
        general_valve = VALVE_STATE.valve_closed;
        analogical_switch = SWITCH_STATE.switch_open;
        handle_move = new BBoolean(false);
        gear = GEAR_STATE.extended;
        door = DOOR_STATE.closed;
    }

    public LandingGear_R6(SWITCH_STATE analogical_switch, BBoolean general_EV, VALVE_STATE general_valve, BBoolean handle_move, BBoolean close_EV, BBoolean extend_EV, BBoolean open_EV, BBoolean retract_EV, PLANE_STATE shock_absorber, VALVE_STATE valve_close_door, VALVE_STATE valve_extend_gear, VALVE_STATE valve_open_door, VALVE_STATE valve_retract_gear, BRelation<POSITION, DOOR_STATE> doors, BRelation<POSITION, GEAR_STATE> gears, HANDLE_STATE handle, DOOR_STATE door, GEAR_STATE gear) {
        this.analogical_switch = analogical_switch;
        this.general_EV = general_EV;
        this.general_valve = general_valve;
        this.handle_move = handle_move;
        this.close_EV = close_EV;
        this.extend_EV = extend_EV;
        this.open_EV = open_EV;
        this.retract_EV = retract_EV;
        this.shock_absorber = shock_absorber;
        this.valve_close_door = valve_close_door;
        this.valve_extend_gear = valve_extend_gear;
        this.valve_open_door = valve_open_door;
        this.valve_retract_gear = valve_retract_gear;
        this.doors = doors;
        this.gears = gears;
        this.handle = handle;
        this.door = door;
        this.gear = gear;
    }

    public void begin_flying() {
        shock_absorber = PLANE_STATE.flight;

    }

    public void land_plane() {
        shock_absorber = PLANE_STATE.ground;

    }

    public void open_valve_door_open() {
        valve_open_door = VALVE_STATE.valve_open;

    }

    public void close_valve_door_open() {
        valve_open_door = VALVE_STATE.valve_closed;

    }

    public void open_valve_door_close() {
        valve_close_door = VALVE_STATE.valve_open;

    }

    public void close_valve_door_close() {
        valve_close_door = VALVE_STATE.valve_closed;

    }

    public void open_valve_retract_gear() {
        valve_retract_gear = VALVE_STATE.valve_open;

    }

    public void close_valve_retract_gear() {
        valve_retract_gear = VALVE_STATE.valve_closed;

    }

    public void open_valve_extend_gear() {
        valve_extend_gear = VALVE_STATE.valve_open;

    }

    public void close_valve_extend_gear() {
        valve_extend_gear = VALVE_STATE.valve_closed;

    }

    public void con_stimulate_open_door_valve() {
        open_EV = new BBoolean(true);

    }

    public void con_stop_stimulate_open_door_valve() {
        open_EV = new BBoolean(false);

    }

    public void con_stimulate_close_door_valve() {
        close_EV = new BBoolean(true);

    }

    public void con_stop_stimulate_close_door_valve() {
        close_EV = new BBoolean(false);

    }

    public void con_stimulate_retract_gear_valve() {
        retract_EV = new BBoolean(true);

    }

    public void con_stop_stimulate_retract_gear_valve() {
        retract_EV = new BBoolean(false);

    }

    public void con_stimulate_extend_gear_valve() {
        extend_EV = new BBoolean(true);

    }

    public void con_stop_stimulate_extend_gear_valve() {
        extend_EV = new BBoolean(false);

    }

    public void env_start_retracting_first(POSITION gr) {
        BRelation<POSITION, GEAR_STATE> _ld_gears = gears;
        gears = _ld_gears.override(new BRelation<POSITION, GEAR_STATE>(new BTuple<>(gr, GEAR_STATE.gear_moving)));
        gear = GEAR_STATE.gear_moving;

    }

    public void env_retract_gear_skip(POSITION gr) {
        gears = gears.override(new BRelation<POSITION, GEAR_STATE>(new BTuple<>(gr, GEAR_STATE.retracted)));

    }

    public void env_retract_gear_last(POSITION gr) {
        BRelation<POSITION, GEAR_STATE> _ld_gears = gears;
        gears = _ld_gears.override(new BRelation<POSITION, GEAR_STATE>(new BTuple<>(gr, GEAR_STATE.retracted)));
        gear = GEAR_STATE.retracted;

    }

    public void env_start_extending(POSITION gr) {
        BRelation<POSITION, GEAR_STATE> _ld_gears = gears;
        gears = _ld_gears.override(new BRelation<POSITION, GEAR_STATE>(new BTuple<>(gr, GEAR_STATE.gear_moving)));
        gear = GEAR_STATE.gear_moving;

    }

    public void env_extend_gear_last(POSITION gr) {
        BRelation<POSITION, GEAR_STATE> _ld_gears = gears;
        gears = _ld_gears.override(new BRelation<POSITION, GEAR_STATE>(new BTuple<>(gr, GEAR_STATE.extended)));
        gear = GEAR_STATE.extended;

    }

    public void env_extend_gear_skip(POSITION gr) {
        gears = gears.override(new BRelation<POSITION, GEAR_STATE>(new BTuple<>(gr, GEAR_STATE.extended)));

    }

    public void env_start_open_door(POSITION gr) {
        BRelation<POSITION, DOOR_STATE> _ld_doors = doors;
        doors = _ld_doors.override(new BRelation<POSITION, DOOR_STATE>(new BTuple<>(gr, DOOR_STATE.door_moving)));
        door = DOOR_STATE.door_moving;

    }

    public void env_open_door_last(POSITION gr) {
        BRelation<POSITION, DOOR_STATE> _ld_doors = doors;
        doors = _ld_doors.override(new BRelation<POSITION, DOOR_STATE>(new BTuple<>(gr, DOOR_STATE.open)));
        door = DOOR_STATE.open;

    }

    public void env_open_door_skip(POSITION gr) {
        doors = doors.override(new BRelation<POSITION, DOOR_STATE>(new BTuple<>(gr, DOOR_STATE.open)));

    }

    public void env_start_close_door(POSITION gr) {
        BRelation<POSITION, DOOR_STATE> _ld_doors = doors;
        doors = _ld_doors.override(new BRelation<POSITION, DOOR_STATE>(new BTuple<>(gr, DOOR_STATE.door_moving)));
        door = DOOR_STATE.door_moving;

    }

    public void env_close_door(POSITION gr) {
        BRelation<POSITION, DOOR_STATE> _ld_doors = doors;
        doors = _ld_doors.override(new BRelation<POSITION, DOOR_STATE>(new BTuple<>(gr, DOOR_STATE.closed)));
        door = DOOR_STATE.closed;

    }

    public void env_close_door_skip(POSITION gr) {
        doors = doors.override(new BRelation<POSITION, DOOR_STATE>(new BTuple<>(gr, DOOR_STATE.closed)));

    }

    public void toggle_handle_up() {
        handle = HANDLE_STATE.up;
        handle_move = new BBoolean(true);

    }

    public void toggle_handle_down() {
        handle = HANDLE_STATE.down;
        handle_move = new BBoolean(true);

    }

    public void con_stimulate_general_valve() {
        general_EV = new BBoolean(true);

    }

    public void con_stop_stimulate_general_valve() {
        general_EV = new BBoolean(false);
        handle_move = new BBoolean(false);

    }

    public void evn_open_general_valve() {
        general_valve = VALVE_STATE.valve_open;

    }

    public void evn_close_general_valve() {
        general_valve = VALVE_STATE.valve_closed;

    }

    public void env_close_analogical_switch() {
        analogical_switch = SWITCH_STATE.switch_closed;

    }

    public void env_open_analogical_switch() {
        analogical_switch = SWITCH_STATE.switch_open;

    }

    public SWITCH_STATE _get_analogical_switch() {
        return analogical_switch;
    }

    public BBoolean _get_general_EV() {
        return general_EV;
    }

    public VALVE_STATE _get_general_valve() {
        return general_valve;
    }

    public BBoolean _get_handle_move() {
        return handle_move;
    }

    public BBoolean _get_close_EV() {
        return close_EV;
    }

    public BBoolean _get_extend_EV() {
        return extend_EV;
    }

    public BBoolean _get_open_EV() {
        return open_EV;
    }

    public BBoolean _get_retract_EV() {
        return retract_EV;
    }

    public PLANE_STATE _get_shock_absorber() {
        return shock_absorber;
    }

    public VALVE_STATE _get_valve_close_door() {
        return valve_close_door;
    }

    public VALVE_STATE _get_valve_extend_gear() {
        return valve_extend_gear;
    }

    public VALVE_STATE _get_valve_open_door() {
        return valve_open_door;
    }

    public VALVE_STATE _get_valve_retract_gear() {
        return valve_retract_gear;
    }

    public BRelation<POSITION, DOOR_STATE> _get_doors() {
        return doors;
    }

    public BRelation<POSITION, GEAR_STATE> _get_gears() {
        return gears;
    }

    public HANDLE_STATE _get_handle() {
        return handle;
    }

    public DOOR_STATE _get_door() {
        return door;
    }

    public GEAR_STATE _get_gear() {
        return gear;
    }

    public BSet<DOOR_STATE> _get__DOOR_STATE() {
        return _DOOR_STATE;
    }

    public BSet<GEAR_STATE> _get__GEAR_STATE() {
        return _GEAR_STATE;
    }

    public BSet<HANDLE_STATE> _get__HANDLE_STATE() {
        return _HANDLE_STATE;
    }

    public BSet<POSITION> _get__POSITION() {
        return _POSITION;
    }

    public BSet<SWITCH_STATE> _get__SWITCH_STATE() {
        return _SWITCH_STATE;
    }

    public BSet<PLANE_STATE> _get__PLANE_STATE() {
        return _PLANE_STATE;
    }

    public BSet<VALVE_STATE> _get__VALVE_STATE() {
        return _VALVE_STATE;
    }


    public boolean _tr_begin_flying() {
        return shock_absorber.equal(PLANE_STATE.ground).booleanValue();
    }

    public boolean _tr_land_plane() {
        return shock_absorber.equal(PLANE_STATE.flight).booleanValue();
    }

    public boolean _tr_open_valve_door_open() {
        return new BBoolean(valve_open_door.equal(VALVE_STATE.valve_closed).booleanValue() && open_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public boolean _tr_close_valve_door_open() {
        return new BBoolean(valve_open_door.equal(VALVE_STATE.valve_open).booleanValue() && open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _tr_open_valve_door_close() {
        return new BBoolean(valve_close_door.equal(VALVE_STATE.valve_closed).booleanValue() && close_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public boolean _tr_close_valve_door_close() {
        return new BBoolean(valve_close_door.equal(VALVE_STATE.valve_open).booleanValue() && close_EV.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _tr_open_valve_retract_gear() {
        return new BBoolean(valve_retract_gear.equal(VALVE_STATE.valve_closed).booleanValue() && retract_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public boolean _tr_close_valve_retract_gear() {
        return new BBoolean(valve_retract_gear.equal(VALVE_STATE.valve_open).booleanValue() && retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _tr_open_valve_extend_gear() {
        return new BBoolean(valve_extend_gear.equal(VALVE_STATE.valve_closed).booleanValue() && extend_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public boolean _tr_close_valve_extend_gear() {
        return new BBoolean(valve_extend_gear.equal(VALVE_STATE.valve_open).booleanValue() && extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _tr_con_stimulate_open_door_valve() {
        return new BBoolean(new BBoolean(new BBoolean(open_EV.equal(new BBoolean(false)).booleanValue() && close_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(handle.equal(HANDLE_STATE.down).booleanValue() && gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).not().booleanValue()).booleanValue() || new BBoolean(new BBoolean(handle.equal(HANDLE_STATE.up).booleanValue() && gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.retracted)).not().booleanValue()).booleanValue() && new BBoolean(doors.range().equal(new BSet<DOOR_STATE>(DOOR_STATE.open)).booleanValue() && shock_absorber.equal(PLANE_STATE.ground).booleanValue()).not().booleanValue()).booleanValue()).booleanValue()).booleanValue() && general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public boolean _tr_con_stop_stimulate_open_door_valve() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(open_EV.equal(new BBoolean(true)).booleanValue() && extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(handle.equal(HANDLE_STATE.down).booleanValue() && gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).booleanValue()).booleanValue() || new BBoolean(new BBoolean(handle.equal(HANDLE_STATE.up).booleanValue() && new BBoolean(gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.retracted)).booleanValue() || shock_absorber.equal(PLANE_STATE.ground).booleanValue()).booleanValue()).booleanValue() && doors.range().equal(new BSet<DOOR_STATE>(DOOR_STATE.open)).booleanValue()).booleanValue()).booleanValue()).booleanValue() && general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public boolean _tr_con_stimulate_close_door_valve() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(close_EV.equal(new BBoolean(false)).booleanValue() && open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(handle.equal(HANDLE_STATE.down).booleanValue() && gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).booleanValue()).booleanValue() || new BBoolean(handle.equal(HANDLE_STATE.up).booleanValue() && new BBoolean(gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.retracted)).booleanValue() || shock_absorber.equal(PLANE_STATE.ground).booleanValue()).booleanValue()).booleanValue()).booleanValue()).booleanValue() && doors.range().equal(new BSet<DOOR_STATE>(DOOR_STATE.closed)).not().booleanValue()).booleanValue() && general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public boolean _tr_con_stop_stimulate_close_door_valve() {
        return new BBoolean(new BBoolean(close_EV.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(handle.equal(HANDLE_STATE.down).booleanValue() && gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).booleanValue()).booleanValue() && doors.range().equal(new BSet<DOOR_STATE>(DOOR_STATE.closed)).booleanValue()).booleanValue() || new BBoolean(new BBoolean(handle.equal(HANDLE_STATE.up).booleanValue() && new BBoolean(gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.retracted)).booleanValue() || shock_absorber.equal(PLANE_STATE.ground).booleanValue()).booleanValue()).booleanValue() && doors.range().equal(new BSet<DOOR_STATE>(DOOR_STATE.closed)).booleanValue()).booleanValue()).booleanValue()).booleanValue() && general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public boolean _tr_con_stimulate_retract_gear_valve() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(retract_EV.equal(new BBoolean(false)).booleanValue() && extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && open_EV.equal(new BBoolean(true)).booleanValue()).booleanValue() && handle.equal(HANDLE_STATE.up).booleanValue()).booleanValue() && gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.retracted)).not().booleanValue()).booleanValue() && shock_absorber.equal(PLANE_STATE.flight).booleanValue()).booleanValue() && doors.range().equal(new BSet<DOOR_STATE>(DOOR_STATE.open)).booleanValue()).booleanValue() && general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public boolean _tr_con_stop_stimulate_retract_gear_valve() {
        return new BBoolean(new BBoolean(retract_EV.equal(new BBoolean(true)).booleanValue() && new BBoolean(handle.equal(HANDLE_STATE.down).booleanValue() || gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.retracted)).booleanValue()).booleanValue()).booleanValue() && general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public boolean _tr_con_stimulate_extend_gear_valve() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(extend_EV.equal(new BBoolean(false)).booleanValue() && retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && open_EV.equal(new BBoolean(true)).booleanValue()).booleanValue() && handle.equal(HANDLE_STATE.down).booleanValue()).booleanValue() && gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).not().booleanValue()).booleanValue() && doors.range().equal(new BSet<DOOR_STATE>(DOOR_STATE.open)).booleanValue()).booleanValue() && general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public boolean _tr_con_stop_stimulate_extend_gear_valve() {
        return new BBoolean(new BBoolean(extend_EV.equal(new BBoolean(true)).booleanValue() && new BBoolean(handle.equal(HANDLE_STATE.up).booleanValue() || gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue() && general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public BSet<POSITION> _tr_env_start_retracting_first() {
        BSet<POSITION> _ic_set_18 = new BSet<POSITION>();
        for(POSITION _ic_gr_1 : gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(doors.range().equal(new BSet<DOOR_STATE>(DOOR_STATE.open)).booleanValue() && handle.equal(HANDLE_STATE.up).booleanValue()).booleanValue() && gears.functionCall(_ic_gr_1).equal(GEAR_STATE.extended).booleanValue()).booleanValue() && valve_retract_gear.equal(VALVE_STATE.valve_open).booleanValue()).booleanValue() && general_valve.equal(VALVE_STATE.valve_open).booleanValue()).booleanValue() && new BSet<GEAR_STATE>(GEAR_STATE.extended, GEAR_STATE.gear_moving).elementOf(gear).booleanValue()).booleanValue() && door.equal(DOOR_STATE.open).booleanValue())).booleanValue()) {
                _ic_set_18 = _ic_set_18.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_18;
    }

    public BSet<POSITION> _tr_env_retract_gear_skip() {
        BSet<POSITION> _ic_set_19 = new BSet<POSITION>();
        for(POSITION _ic_gr_1 : gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(doors.range().equal(new BSet<DOOR_STATE>(DOOR_STATE.open)).booleanValue() && gears.relationImage(_POSITION.difference(new BSet<POSITION>(_ic_gr_1))).unequal(new BSet<GEAR_STATE>(GEAR_STATE.retracted)).booleanValue()).booleanValue() && handle.equal(HANDLE_STATE.up).booleanValue()).booleanValue() && gears.functionCall(_ic_gr_1).equal(GEAR_STATE.gear_moving).booleanValue()).booleanValue() && general_valve.equal(VALVE_STATE.valve_open).booleanValue())).booleanValue()) {
                _ic_set_19 = _ic_set_19.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_19;
    }

    public BSet<POSITION> _tr_env_retract_gear_last() {
        BSet<POSITION> _ic_set_20 = new BSet<POSITION>();
        for(POSITION _ic_gr_1 : gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(doors.range().equal(new BSet<DOOR_STATE>(DOOR_STATE.open)).booleanValue() && gears.relationImage(_POSITION.difference(new BSet<POSITION>(_ic_gr_1))).equal(new BSet<GEAR_STATE>(GEAR_STATE.retracted)).booleanValue()).booleanValue() && handle.equal(HANDLE_STATE.up).booleanValue()).booleanValue() && gears.functionCall(_ic_gr_1).equal(GEAR_STATE.gear_moving).booleanValue()).booleanValue() && general_valve.equal(VALVE_STATE.valve_open).booleanValue()).booleanValue() && gear.equal(GEAR_STATE.gear_moving).booleanValue()).booleanValue() && door.equal(DOOR_STATE.open).booleanValue())).booleanValue()) {
                _ic_set_20 = _ic_set_20.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_20;
    }

    public BSet<POSITION> _tr_env_start_extending() {
        BSet<POSITION> _ic_set_21 = new BSet<POSITION>();
        for(POSITION _ic_gr_1 : gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(doors.range().equal(new BSet<DOOR_STATE>(DOOR_STATE.open)).booleanValue() && handle.equal(HANDLE_STATE.down).booleanValue()).booleanValue() && gears.functionCall(_ic_gr_1).equal(GEAR_STATE.retracted).booleanValue()).booleanValue() && valve_extend_gear.equal(VALVE_STATE.valve_open).booleanValue()).booleanValue() && general_valve.equal(VALVE_STATE.valve_open).booleanValue()).booleanValue() && new BSet<GEAR_STATE>(GEAR_STATE.gear_moving, GEAR_STATE.retracted).elementOf(gear).booleanValue()).booleanValue() && door.equal(DOOR_STATE.open).booleanValue())).booleanValue()) {
                _ic_set_21 = _ic_set_21.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_21;
    }

    public BSet<POSITION> _tr_env_extend_gear_last() {
        BSet<POSITION> _ic_set_22 = new BSet<POSITION>();
        for(POSITION _ic_gr_1 : gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(doors.range().equal(new BSet<DOOR_STATE>(DOOR_STATE.open)).booleanValue() && handle.equal(HANDLE_STATE.down).booleanValue()).booleanValue() && gears.relationImage(_POSITION.difference(new BSet<POSITION>(_ic_gr_1))).equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).booleanValue()).booleanValue() && gears.functionCall(_ic_gr_1).equal(GEAR_STATE.gear_moving).booleanValue()).booleanValue() && general_valve.equal(VALVE_STATE.valve_open).booleanValue()).booleanValue() && gear.equal(GEAR_STATE.gear_moving).booleanValue()).booleanValue() && door.equal(DOOR_STATE.open).booleanValue())).booleanValue()) {
                _ic_set_22 = _ic_set_22.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_22;
    }

    public BSet<POSITION> _tr_env_extend_gear_skip() {
        BSet<POSITION> _ic_set_23 = new BSet<POSITION>();
        for(POSITION _ic_gr_1 : gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(doors.range().equal(new BSet<DOOR_STATE>(DOOR_STATE.open)).booleanValue() && handle.equal(HANDLE_STATE.down).booleanValue()).booleanValue() && gears.relationImage(_POSITION.difference(new BSet<POSITION>(_ic_gr_1))).unequal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).booleanValue()).booleanValue() && gears.functionCall(_ic_gr_1).equal(GEAR_STATE.gear_moving).booleanValue()).booleanValue() && general_valve.equal(VALVE_STATE.valve_open).booleanValue())).booleanValue()) {
                _ic_set_23 = _ic_set_23.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_23;
    }

    public BSet<POSITION> _tr_env_start_open_door() {
        BSet<POSITION> _ic_set_24 = new BSet<POSITION>();
        for(POSITION _ic_gr_1 : gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(doors.functionCall(_ic_gr_1).equal(DOOR_STATE.closed).booleanValue() && gears.functionCall(_ic_gr_1).unequal(GEAR_STATE.gear_moving).booleanValue()).booleanValue() && gears.range().notElementOf(GEAR_STATE.gear_moving).booleanValue()).booleanValue() && new BBoolean(new BBoolean(handle.equal(HANDLE_STATE.down).booleanValue() && gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.retracted)).booleanValue()).booleanValue() || new BBoolean(handle.equal(HANDLE_STATE.up).booleanValue() && gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue()).booleanValue() && valve_open_door.equal(VALVE_STATE.valve_open).booleanValue()).booleanValue() && general_valve.equal(VALVE_STATE.valve_open).booleanValue()).booleanValue() && new BSet<DOOR_STATE>(DOOR_STATE.closed, DOOR_STATE.door_moving).elementOf(door).booleanValue()).booleanValue() && gear.unequal(GEAR_STATE.gear_moving).booleanValue()).booleanValue() && new BBoolean(new BBoolean(handle.equal(HANDLE_STATE.down).booleanValue() && gear.equal(GEAR_STATE.retracted).booleanValue()).booleanValue() || new BBoolean(handle.equal(HANDLE_STATE.up).booleanValue() && gear.equal(GEAR_STATE.extended).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
                _ic_set_24 = _ic_set_24.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_24;
    }

    public BSet<POSITION> _tr_env_open_door_last() {
        BSet<POSITION> _ic_set_25 = new BSet<POSITION>();
        for(POSITION _ic_gr_1 : gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(doors.functionCall(_ic_gr_1).equal(DOOR_STATE.door_moving).booleanValue() && gears.functionCall(_ic_gr_1).unequal(GEAR_STATE.gear_moving).booleanValue()).booleanValue() && gears.range().notElementOf(GEAR_STATE.gear_moving).booleanValue()).booleanValue() && doors.relationImage(_POSITION.difference(new BSet<POSITION>(_ic_gr_1))).equal(new BSet<DOOR_STATE>(DOOR_STATE.open)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(handle.equal(HANDLE_STATE.down).booleanValue() && gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.retracted)).booleanValue()).booleanValue() || new BBoolean(handle.equal(HANDLE_STATE.up).booleanValue() && gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue()).booleanValue() && valve_open_door.equal(VALVE_STATE.valve_open).booleanValue()).booleanValue() && general_valve.equal(VALVE_STATE.valve_open).booleanValue()).booleanValue() && door.equal(DOOR_STATE.door_moving).booleanValue()).booleanValue() && gear.unequal(GEAR_STATE.gear_moving).booleanValue()).booleanValue() && new BBoolean(new BBoolean(handle.equal(HANDLE_STATE.down).booleanValue() && gear.equal(GEAR_STATE.retracted).booleanValue()).booleanValue() || new BBoolean(handle.equal(HANDLE_STATE.up).booleanValue() && gear.equal(GEAR_STATE.extended).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
                _ic_set_25 = _ic_set_25.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_25;
    }

    public BSet<POSITION> _tr_env_open_door_skip() {
        BSet<POSITION> _ic_set_26 = new BSet<POSITION>();
        for(POSITION _ic_gr_1 : gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(doors.functionCall(_ic_gr_1).equal(DOOR_STATE.door_moving).booleanValue() && gears.functionCall(_ic_gr_1).unequal(GEAR_STATE.gear_moving).booleanValue()).booleanValue() && gears.range().notElementOf(GEAR_STATE.gear_moving).booleanValue()).booleanValue() && doors.relationImage(_POSITION.difference(new BSet<POSITION>(_ic_gr_1))).unequal(new BSet<DOOR_STATE>(DOOR_STATE.open)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(handle.equal(HANDLE_STATE.down).booleanValue() && gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.retracted)).booleanValue()).booleanValue() || new BBoolean(handle.equal(HANDLE_STATE.up).booleanValue() && gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue()).booleanValue() && valve_open_door.equal(VALVE_STATE.valve_open).booleanValue()).booleanValue() && general_valve.equal(VALVE_STATE.valve_open).booleanValue())).booleanValue()) {
                _ic_set_26 = _ic_set_26.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_26;
    }

    public BSet<POSITION> _tr_env_start_close_door() {
        BSet<POSITION> _ic_set_27 = new BSet<POSITION>();
        for(POSITION _ic_gr_1 : gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(doors.functionCall(_ic_gr_1).equal(DOOR_STATE.open).booleanValue() && gears.functionCall(_ic_gr_1).unequal(GEAR_STATE.gear_moving).booleanValue()).booleanValue() && new BBoolean(new BBoolean(handle.equal(HANDLE_STATE.up).booleanValue() && new BBoolean(gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.retracted)).booleanValue() || gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue() || new BBoolean(handle.equal(HANDLE_STATE.down).booleanValue() && gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue()).booleanValue() && valve_close_door.equal(VALVE_STATE.valve_open).booleanValue()).booleanValue() && general_valve.equal(VALVE_STATE.valve_open).booleanValue()).booleanValue() && new BSet<DOOR_STATE>(DOOR_STATE.door_moving, DOOR_STATE.open).elementOf(door).booleanValue()).booleanValue() && gear.unequal(GEAR_STATE.gear_moving).booleanValue()).booleanValue() && new BBoolean(new BBoolean(handle.equal(HANDLE_STATE.down).booleanValue() && gear.equal(GEAR_STATE.extended).booleanValue()).booleanValue() || new BBoolean(handle.equal(HANDLE_STATE.up).booleanValue() && new BSet<GEAR_STATE>(GEAR_STATE.extended, GEAR_STATE.retracted).elementOf(gear).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
                _ic_set_27 = _ic_set_27.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_27;
    }

    public BSet<POSITION> _tr_env_close_door() {
        BSet<POSITION> _ic_set_28 = new BSet<POSITION>();
        for(POSITION _ic_gr_1 : gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(doors.functionCall(_ic_gr_1).equal(DOOR_STATE.door_moving).booleanValue() && gears.functionCall(_ic_gr_1).unequal(GEAR_STATE.gear_moving).booleanValue()).booleanValue() && gears.range().notElementOf(GEAR_STATE.gear_moving).booleanValue()).booleanValue() && doors.relationImage(_POSITION.difference(new BSet<POSITION>(_ic_gr_1))).equal(new BSet<DOOR_STATE>(DOOR_STATE.closed)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(handle.equal(HANDLE_STATE.up).booleanValue() && new BBoolean(gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.retracted)).booleanValue() || gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue() || new BBoolean(handle.equal(HANDLE_STATE.down).booleanValue() && gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue()).booleanValue() && valve_close_door.equal(VALVE_STATE.valve_open).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(handle.equal(HANDLE_STATE.up).booleanValue() && gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).booleanValue()).booleanValue() || shock_absorber.equal(PLANE_STATE.ground).booleanValue()).booleanValue()).booleanValue() && general_valve.equal(VALVE_STATE.valve_open).booleanValue()).booleanValue() && door.equal(DOOR_STATE.door_moving).booleanValue()).booleanValue() && gear.unequal(GEAR_STATE.gear_moving).booleanValue()).booleanValue() && new BBoolean(new BBoolean(handle.equal(HANDLE_STATE.down).booleanValue() && gear.equal(GEAR_STATE.extended).booleanValue()).booleanValue() || new BBoolean(handle.equal(HANDLE_STATE.up).booleanValue() && new BSet<GEAR_STATE>(GEAR_STATE.extended, GEAR_STATE.retracted).elementOf(gear).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
                _ic_set_28 = _ic_set_28.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_28;
    }

    public BSet<POSITION> _tr_env_close_door_skip() {
        BSet<POSITION> _ic_set_29 = new BSet<POSITION>();
        for(POSITION _ic_gr_1 : gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(doors.functionCall(_ic_gr_1).equal(DOOR_STATE.door_moving).booleanValue() && gears.functionCall(_ic_gr_1).unequal(GEAR_STATE.gear_moving).booleanValue()).booleanValue() && gears.range().notElementOf(GEAR_STATE.gear_moving).booleanValue()).booleanValue() && doors.relationImage(_POSITION.difference(new BSet<POSITION>(_ic_gr_1))).unequal(new BSet<DOOR_STATE>(DOOR_STATE.closed)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(handle.equal(HANDLE_STATE.up).booleanValue() && new BBoolean(gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.retracted)).booleanValue() || gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue() || new BBoolean(handle.equal(HANDLE_STATE.down).booleanValue() && gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue()).booleanValue() && valve_close_door.equal(VALVE_STATE.valve_open).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(handle.equal(HANDLE_STATE.up).booleanValue() && gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).booleanValue()).booleanValue() || shock_absorber.equal(PLANE_STATE.ground).booleanValue()).booleanValue()).booleanValue() && general_valve.equal(VALVE_STATE.valve_open).booleanValue())).booleanValue()) {
                _ic_set_29 = _ic_set_29.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_29;
    }

    public boolean _tr_toggle_handle_up() {
        return handle.equal(HANDLE_STATE.down).booleanValue();
    }

    public boolean _tr_toggle_handle_down() {
        return handle.equal(HANDLE_STATE.up).booleanValue();
    }

    public boolean _tr_con_stimulate_general_valve() {
        return new BBoolean(general_EV.equal(new BBoolean(false)).booleanValue() && handle_move.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public boolean _tr_con_stop_stimulate_general_valve() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(general_EV.equal(new BBoolean(true)).booleanValue() && open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && close_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && close_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(handle.equal(HANDLE_STATE.up).booleanValue() && gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.retracted)).booleanValue()).booleanValue() && doors.range().equal(new BSet<DOOR_STATE>(DOOR_STATE.closed)).booleanValue()).booleanValue() && open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() || new BBoolean(new BBoolean(new BBoolean(handle.equal(HANDLE_STATE.down).booleanValue() && gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).booleanValue()).booleanValue() && doors.range().equal(new BSet<DOOR_STATE>(DOOR_STATE.closed)).booleanValue()).booleanValue() && open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() || new BBoolean(new BBoolean(new BBoolean(handle.equal(HANDLE_STATE.up).booleanValue() && gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).booleanValue()).booleanValue() && doors.range().equal(new BSet<DOOR_STATE>(DOOR_STATE.closed)).booleanValue()).booleanValue() && open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue()).booleanValue();
    }

    public boolean _tr_evn_open_general_valve() {
        return new BBoolean(new BBoolean(general_EV.equal(new BBoolean(true)).booleanValue() && general_valve.equal(VALVE_STATE.valve_closed).booleanValue()).booleanValue() && analogical_switch.equal(SWITCH_STATE.switch_closed).booleanValue()).booleanValue();
    }

    public boolean _tr_evn_close_general_valve() {
        return new BBoolean(new BBoolean(general_EV.equal(new BBoolean(false)).booleanValue() || analogical_switch.equal(SWITCH_STATE.switch_open).booleanValue()).booleanValue() && general_valve.equal(VALVE_STATE.valve_open).booleanValue()).booleanValue();
    }

    public boolean _tr_env_close_analogical_switch() {
        return new BBoolean(analogical_switch.equal(SWITCH_STATE.switch_open).booleanValue() && handle_move.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public boolean _tr_env_open_analogical_switch() {
        return analogical_switch.equal(SWITCH_STATE.switch_closed).booleanValue();
    }

    public boolean _check_inv_1() {
        return _SWITCH_STATE.elementOf(analogical_switch).booleanValue();
    }

    public boolean _check_inv_2() {
        return BUtils.BOOL.elementOf(general_EV).booleanValue();
    }

    public boolean _check_inv_3() {
        return _VALVE_STATE.elementOf(general_valve).booleanValue();
    }

    public boolean _check_inv_4() {
        return BUtils.BOOL.elementOf(handle_move).booleanValue();
    }

    public boolean _check_inv_5() {
        return BUtils.BOOL.elementOf(close_EV).booleanValue();
    }

    public boolean _check_inv_6() {
        return BUtils.BOOL.elementOf(extend_EV).booleanValue();
    }

    public boolean _check_inv_7() {
        return BUtils.BOOL.elementOf(open_EV).booleanValue();
    }

    public boolean _check_inv_8() {
        return BUtils.BOOL.elementOf(retract_EV).booleanValue();
    }

    public boolean _check_inv_9() {
        return _PLANE_STATE.elementOf(shock_absorber).booleanValue();
    }

    public boolean _check_inv_10() {
        return _VALVE_STATE.elementOf(valve_close_door).booleanValue();
    }

    public boolean _check_inv_11() {
        return _VALVE_STATE.elementOf(valve_extend_gear).booleanValue();
    }

    public boolean _check_inv_12() {
        return _VALVE_STATE.elementOf(valve_open_door).booleanValue();
    }

    public boolean _check_inv_13() {
        return _VALVE_STATE.elementOf(valve_retract_gear).booleanValue();
    }

    public boolean _check_inv_14() {
        return _HANDLE_STATE.elementOf(handle).booleanValue();
    }

    public boolean _check_inv_15() {
        return _DOOR_STATE.elementOf(door).booleanValue();
    }

    public boolean _check_inv_16() {
        return _GEAR_STATE.elementOf(gear).booleanValue();
    }

    public boolean _check_inv_17() {
        return new BBoolean(!new BBoolean(new BBoolean(new BBoolean(open_EV.equal(new BBoolean(true)).booleanValue() || close_EV.equal(new BBoolean(true)).booleanValue()).booleanValue() || retract_EV.equal(new BBoolean(true)).booleanValue()).booleanValue() || extend_EV.equal(new BBoolean(true)).booleanValue()).booleanValue() || general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_18() {
        return new BBoolean(open_EV.equal(new BBoolean(true)).booleanValue() && close_EV.equal(new BBoolean(true)).booleanValue()).not().booleanValue();
    }

    public boolean _check_inv_19() {
        return gears.checkDomain(_POSITION).and(gears.checkRange(_GEAR_STATE)).and(gears.isFunction()).and(gears.isTotal(_POSITION)).booleanValue();
    }

    public boolean _check_inv_20() {
        return doors.checkDomain(_POSITION).and(doors.checkRange(_DOOR_STATE)).and(doors.isFunction()).and(doors.isTotal(_POSITION)).booleanValue();
    }

    public boolean _check_inv_21() {
        return new BBoolean((!door.equal(DOOR_STATE.closed).booleanValue() || doors.range().equal(new BSet<DOOR_STATE>(DOOR_STATE.closed)).booleanValue()) && (!doors.range().equal(new BSet<DOOR_STATE>(DOOR_STATE.closed)).booleanValue() || door.equal(DOOR_STATE.closed).booleanValue())).booleanValue();
    }

    public boolean _check_inv_22() {
        return new BBoolean((!door.equal(DOOR_STATE.open).booleanValue() || doors.range().equal(new BSet<DOOR_STATE>(DOOR_STATE.open)).booleanValue()) && (!doors.range().equal(new BSet<DOOR_STATE>(DOOR_STATE.open)).booleanValue() || door.equal(DOOR_STATE.open).booleanValue())).booleanValue();
    }

    public boolean _check_inv_23() {
        return new BBoolean((!gear.equal(GEAR_STATE.extended).booleanValue() || gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).booleanValue()) && (!gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.extended)).booleanValue() || gear.equal(GEAR_STATE.extended).booleanValue())).booleanValue();
    }

    public boolean _check_inv_24() {
        return new BBoolean((!gear.equal(GEAR_STATE.retracted).booleanValue() || gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.retracted)).booleanValue()) && (!gears.range().equal(new BSet<GEAR_STATE>(GEAR_STATE.retracted)).booleanValue() || gear.equal(GEAR_STATE.retracted).booleanValue())).booleanValue();
    }

    public boolean _check_inv_25() {
        return new BBoolean(!gear.equal(GEAR_STATE.gear_moving).booleanValue() || door.equal(DOOR_STATE.open).booleanValue()).booleanValue();
    }

    public LandingGear_R6 _copy() {
        return new LandingGear_R6(analogical_switch, general_EV, general_valve, handle_move, close_EV, extend_EV, open_EV, retract_EV, shock_absorber, valve_close_door, valve_extend_gear, valve_open_door, valve_retract_gear, doors, gears, handle, door, gear);
    }

    @Override
    public boolean equals(Object o) {
        LandingGear_R6 o1 = this;
        LandingGear_R6 o2 = (LandingGear_R6) o;
        return o1._get_analogical_switch().equals(o2._get_analogical_switch()) && o1._get_general_EV().equals(o2._get_general_EV()) && o1._get_general_valve().equals(o2._get_general_valve()) && o1._get_handle_move().equals(o2._get_handle_move()) && o1._get_close_EV().equals(o2._get_close_EV()) && o1._get_extend_EV().equals(o2._get_extend_EV()) && o1._get_open_EV().equals(o2._get_open_EV()) && o1._get_retract_EV().equals(o2._get_retract_EV()) && o1._get_shock_absorber().equals(o2._get_shock_absorber()) && o1._get_valve_close_door().equals(o2._get_valve_close_door()) && o1._get_valve_extend_gear().equals(o2._get_valve_extend_gear()) && o1._get_valve_open_door().equals(o2._get_valve_open_door()) && o1._get_valve_retract_gear().equals(o2._get_valve_retract_gear()) && o1._get_doors().equals(o2._get_doors()) && o1._get_gears().equals(o2._get_gears()) && o1._get_handle().equals(o2._get_handle()) && o1._get_door().equals(o2._get_door()) && o1._get_gear().equals(o2._get_gear());
    }



    @Override
    public int hashCode() {
        return this._hashCode_1();
    }

    public int _hashCode_1() {
        int result = 1;
        result = (1543 * result) ^ ((this._get_analogical_switch()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_general_EV()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_general_valve()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_handle_move()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_close_EV()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_extend_EV()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_open_EV()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_retract_EV()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_shock_absorber()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_valve_close_door()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_valve_extend_gear()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_valve_open_door()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_valve_retract_gear()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_doors()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_gears()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_handle()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_door()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_gear()).hashCode() << 1);
        return result;
    }

    public int _hashCode_2() {
        int result = 1;
        result = (6151 * result) ^ ((this._get_analogical_switch()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_general_EV()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_general_valve()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_handle_move()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_close_EV()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_extend_EV()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_open_EV()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_retract_EV()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_shock_absorber()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_valve_close_door()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_valve_extend_gear()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_valve_open_door()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_valve_retract_gear()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_doors()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_gears()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_handle()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_door()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_gear()).hashCode() << 1);
        return result;
    }

    @Override
    public String toString() {
        return String.join("\n", "_get_analogical_switch: " + (this._get_analogical_switch()).toString(), "_get_general_EV: " + (this._get_general_EV()).toString(), "_get_general_valve: " + (this._get_general_valve()).toString(), "_get_handle_move: " + (this._get_handle_move()).toString(), "_get_close_EV: " + (this._get_close_EV()).toString(), "_get_extend_EV: " + (this._get_extend_EV()).toString(), "_get_open_EV: " + (this._get_open_EV()).toString(), "_get_retract_EV: " + (this._get_retract_EV()).toString(), "_get_shock_absorber: " + (this._get_shock_absorber()).toString(), "_get_valve_close_door: " + (this._get_valve_close_door()).toString(), "_get_valve_extend_gear: " + (this._get_valve_extend_gear()).toString(), "_get_valve_open_door: " + (this._get_valve_open_door()).toString(), "_get_valve_retract_gear: " + (this._get_valve_retract_gear()).toString(), "_get_doors: " + (this._get_doors()).toString(), "_get_gears: " + (this._get_gears()).toString(), "_get_handle: " + (this._get_handle()).toString(), "_get_door: " + (this._get_door()).toString(), "_get_gear: " + (this._get_gear()).toString());
    }

    @SuppressWarnings("unchecked")
    private static Set<LandingGear_R6> generateNextStates(Object guardLock, LandingGear_R6 state, boolean isCaching, Map<String, Set<String>> invariantDependency, Map<LandingGear_R6, Set<String>> dependentInvariant, Map<String, Set<String>> guardDependency, Map<LandingGear_R6, Set<String>> dependentGuard, Map<LandingGear_R6, PersistentHashMap> guardCache, Map<LandingGear_R6, LandingGear_R6> parents, Map<LandingGear_R6, String> stateAccessedVia, AtomicInteger transitions) {
        Set<LandingGear_R6> result = new HashSet<>();
        if(isCaching) {
            PersistentHashMap parentsGuard = guardCache.get(parents.get(state));
            PersistentHashMap newCache = parentsGuard == null ? PersistentHashMap.EMPTY : parentsGuard;
            Set<String> dependentGuardsOfState = dependentGuard.get(state);
            Object cachedValue = null;
            boolean dependentGuardsBoolean = true;
            boolean _trid_1;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_begin_flying");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_begin_flying");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_1 = state._tr_begin_flying();
            } else {
                _trid_1 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_begin_flying", _trid_1);
            if(_trid_1) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.begin_flying();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("begin_flying"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("begin_flying"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "begin_flying");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_2;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_land_plane");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_land_plane");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_2 = state._tr_land_plane();
            } else {
                _trid_2 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_land_plane", _trid_2);
            if(_trid_2) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.land_plane();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("land_plane"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("land_plane"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "land_plane");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_3;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_open_valve_door_open");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_open_valve_door_open");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_3 = state._tr_open_valve_door_open();
            } else {
                _trid_3 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_open_valve_door_open", _trid_3);
            if(_trid_3) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.open_valve_door_open();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("open_valve_door_open"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("open_valve_door_open"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "open_valve_door_open");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_4;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_close_valve_door_open");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_close_valve_door_open");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_4 = state._tr_close_valve_door_open();
            } else {
                _trid_4 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_close_valve_door_open", _trid_4);
            if(_trid_4) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.close_valve_door_open();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("close_valve_door_open"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("close_valve_door_open"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "close_valve_door_open");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_5;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_open_valve_door_close");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_open_valve_door_close");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_5 = state._tr_open_valve_door_close();
            } else {
                _trid_5 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_open_valve_door_close", _trid_5);
            if(_trid_5) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.open_valve_door_close();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("open_valve_door_close"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("open_valve_door_close"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "open_valve_door_close");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_6;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_close_valve_door_close");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_close_valve_door_close");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_6 = state._tr_close_valve_door_close();
            } else {
                _trid_6 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_close_valve_door_close", _trid_6);
            if(_trid_6) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.close_valve_door_close();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("close_valve_door_close"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("close_valve_door_close"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "close_valve_door_close");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_7;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_open_valve_retract_gear");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_open_valve_retract_gear");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_7 = state._tr_open_valve_retract_gear();
            } else {
                _trid_7 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_open_valve_retract_gear", _trid_7);
            if(_trid_7) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.open_valve_retract_gear();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("open_valve_retract_gear"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("open_valve_retract_gear"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "open_valve_retract_gear");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_8;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_close_valve_retract_gear");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_close_valve_retract_gear");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_8 = state._tr_close_valve_retract_gear();
            } else {
                _trid_8 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_close_valve_retract_gear", _trid_8);
            if(_trid_8) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.close_valve_retract_gear();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("close_valve_retract_gear"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("close_valve_retract_gear"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "close_valve_retract_gear");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_9;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_open_valve_extend_gear");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_open_valve_extend_gear");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_9 = state._tr_open_valve_extend_gear();
            } else {
                _trid_9 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_open_valve_extend_gear", _trid_9);
            if(_trid_9) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.open_valve_extend_gear();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("open_valve_extend_gear"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("open_valve_extend_gear"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "open_valve_extend_gear");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_10;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_close_valve_extend_gear");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_close_valve_extend_gear");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_10 = state._tr_close_valve_extend_gear();
            } else {
                _trid_10 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_close_valve_extend_gear", _trid_10);
            if(_trid_10) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.close_valve_extend_gear();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("close_valve_extend_gear"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("close_valve_extend_gear"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "close_valve_extend_gear");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_11;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_con_stimulate_open_door_valve");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_con_stimulate_open_door_valve");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_11 = state._tr_con_stimulate_open_door_valve();
            } else {
                _trid_11 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_con_stimulate_open_door_valve", _trid_11);
            if(_trid_11) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.con_stimulate_open_door_valve();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("con_stimulate_open_door_valve"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("con_stimulate_open_door_valve"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "con_stimulate_open_door_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_12;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_con_stop_stimulate_open_door_valve");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_con_stop_stimulate_open_door_valve");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_12 = state._tr_con_stop_stimulate_open_door_valve();
            } else {
                _trid_12 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_con_stop_stimulate_open_door_valve", _trid_12);
            if(_trid_12) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.con_stop_stimulate_open_door_valve();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("con_stop_stimulate_open_door_valve"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("con_stop_stimulate_open_door_valve"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "con_stop_stimulate_open_door_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_13;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_con_stimulate_close_door_valve");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_con_stimulate_close_door_valve");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_13 = state._tr_con_stimulate_close_door_valve();
            } else {
                _trid_13 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_con_stimulate_close_door_valve", _trid_13);
            if(_trid_13) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.con_stimulate_close_door_valve();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("con_stimulate_close_door_valve"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("con_stimulate_close_door_valve"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "con_stimulate_close_door_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_14;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_con_stop_stimulate_close_door_valve");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_con_stop_stimulate_close_door_valve");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_14 = state._tr_con_stop_stimulate_close_door_valve();
            } else {
                _trid_14 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_con_stop_stimulate_close_door_valve", _trid_14);
            if(_trid_14) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.con_stop_stimulate_close_door_valve();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("con_stop_stimulate_close_door_valve"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("con_stop_stimulate_close_door_valve"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "con_stop_stimulate_close_door_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_15;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_con_stimulate_retract_gear_valve");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_con_stimulate_retract_gear_valve");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_15 = state._tr_con_stimulate_retract_gear_valve();
            } else {
                _trid_15 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_con_stimulate_retract_gear_valve", _trid_15);
            if(_trid_15) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.con_stimulate_retract_gear_valve();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("con_stimulate_retract_gear_valve"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("con_stimulate_retract_gear_valve"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "con_stimulate_retract_gear_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_16;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_con_stop_stimulate_retract_gear_valve");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_con_stop_stimulate_retract_gear_valve");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_16 = state._tr_con_stop_stimulate_retract_gear_valve();
            } else {
                _trid_16 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_con_stop_stimulate_retract_gear_valve", _trid_16);
            if(_trid_16) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.con_stop_stimulate_retract_gear_valve();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("con_stop_stimulate_retract_gear_valve"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("con_stop_stimulate_retract_gear_valve"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "con_stop_stimulate_retract_gear_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_17;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_con_stimulate_extend_gear_valve");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_con_stimulate_extend_gear_valve");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_17 = state._tr_con_stimulate_extend_gear_valve();
            } else {
                _trid_17 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_con_stimulate_extend_gear_valve", _trid_17);
            if(_trid_17) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.con_stimulate_extend_gear_valve();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("con_stimulate_extend_gear_valve"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("con_stimulate_extend_gear_valve"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "con_stimulate_extend_gear_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_18;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_con_stop_stimulate_extend_gear_valve");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_con_stop_stimulate_extend_gear_valve");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_18 = state._tr_con_stop_stimulate_extend_gear_valve();
            } else {
                _trid_18 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_con_stop_stimulate_extend_gear_valve", _trid_18);
            if(_trid_18) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.con_stop_stimulate_extend_gear_valve();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("con_stop_stimulate_extend_gear_valve"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("con_stop_stimulate_extend_gear_valve"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "con_stop_stimulate_extend_gear_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_19;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_env_start_retracting_first");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_env_start_retracting_first");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_19 = state._tr_env_start_retracting_first();
            } else {
                _trid_19 = (BSet<POSITION>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_env_start_retracting_first", _trid_19);
            for(POSITION param : _trid_19) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_start_retracting_first(_tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("env_start_retracting_first"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("env_start_retracting_first"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_start_retracting_first");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_20;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_env_retract_gear_skip");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_env_retract_gear_skip");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_20 = state._tr_env_retract_gear_skip();
            } else {
                _trid_20 = (BSet<POSITION>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_env_retract_gear_skip", _trid_20);
            for(POSITION param : _trid_20) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_retract_gear_skip(_tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("env_retract_gear_skip"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("env_retract_gear_skip"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_retract_gear_skip");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_21;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_env_retract_gear_last");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_env_retract_gear_last");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_21 = state._tr_env_retract_gear_last();
            } else {
                _trid_21 = (BSet<POSITION>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_env_retract_gear_last", _trid_21);
            for(POSITION param : _trid_21) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_retract_gear_last(_tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("env_retract_gear_last"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("env_retract_gear_last"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_retract_gear_last");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_22;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_env_start_extending");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_env_start_extending");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_22 = state._tr_env_start_extending();
            } else {
                _trid_22 = (BSet<POSITION>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_env_start_extending", _trid_22);
            for(POSITION param : _trid_22) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_start_extending(_tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("env_start_extending"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("env_start_extending"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_start_extending");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_23;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_env_extend_gear_last");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_env_extend_gear_last");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_23 = state._tr_env_extend_gear_last();
            } else {
                _trid_23 = (BSet<POSITION>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_env_extend_gear_last", _trid_23);
            for(POSITION param : _trid_23) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_extend_gear_last(_tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("env_extend_gear_last"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("env_extend_gear_last"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_extend_gear_last");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_24;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_env_extend_gear_skip");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_env_extend_gear_skip");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_24 = state._tr_env_extend_gear_skip();
            } else {
                _trid_24 = (BSet<POSITION>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_env_extend_gear_skip", _trid_24);
            for(POSITION param : _trid_24) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_extend_gear_skip(_tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("env_extend_gear_skip"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("env_extend_gear_skip"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_extend_gear_skip");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_25;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_env_start_open_door");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_env_start_open_door");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_25 = state._tr_env_start_open_door();
            } else {
                _trid_25 = (BSet<POSITION>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_env_start_open_door", _trid_25);
            for(POSITION param : _trid_25) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_start_open_door(_tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("env_start_open_door"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("env_start_open_door"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_start_open_door");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_26;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_env_open_door_last");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_env_open_door_last");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_26 = state._tr_env_open_door_last();
            } else {
                _trid_26 = (BSet<POSITION>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_env_open_door_last", _trid_26);
            for(POSITION param : _trid_26) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_open_door_last(_tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("env_open_door_last"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("env_open_door_last"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_open_door_last");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_27;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_env_open_door_skip");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_env_open_door_skip");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_27 = state._tr_env_open_door_skip();
            } else {
                _trid_27 = (BSet<POSITION>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_env_open_door_skip", _trid_27);
            for(POSITION param : _trid_27) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_open_door_skip(_tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("env_open_door_skip"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("env_open_door_skip"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_open_door_skip");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_28;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_env_start_close_door");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_env_start_close_door");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_28 = state._tr_env_start_close_door();
            } else {
                _trid_28 = (BSet<POSITION>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_env_start_close_door", _trid_28);
            for(POSITION param : _trid_28) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_start_close_door(_tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("env_start_close_door"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("env_start_close_door"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_start_close_door");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_29;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_env_close_door");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_env_close_door");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_29 = state._tr_env_close_door();
            } else {
                _trid_29 = (BSet<POSITION>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_env_close_door", _trid_29);
            for(POSITION param : _trid_29) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_close_door(_tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("env_close_door"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("env_close_door"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_close_door");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_30;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_env_close_door_skip");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_env_close_door_skip");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_30 = state._tr_env_close_door_skip();
            } else {
                _trid_30 = (BSet<POSITION>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_env_close_door_skip", _trid_30);
            for(POSITION param : _trid_30) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_close_door_skip(_tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("env_close_door_skip"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("env_close_door_skip"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_close_door_skip");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_31;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_toggle_handle_up");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_toggle_handle_up");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_31 = state._tr_toggle_handle_up();
            } else {
                _trid_31 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_toggle_handle_up", _trid_31);
            if(_trid_31) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.toggle_handle_up();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("toggle_handle_up"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("toggle_handle_up"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "toggle_handle_up");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_32;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_toggle_handle_down");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_toggle_handle_down");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_32 = state._tr_toggle_handle_down();
            } else {
                _trid_32 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_toggle_handle_down", _trid_32);
            if(_trid_32) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.toggle_handle_down();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("toggle_handle_down"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("toggle_handle_down"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "toggle_handle_down");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_33;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_con_stimulate_general_valve");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_con_stimulate_general_valve");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_33 = state._tr_con_stimulate_general_valve();
            } else {
                _trid_33 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_con_stimulate_general_valve", _trid_33);
            if(_trid_33) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.con_stimulate_general_valve();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("con_stimulate_general_valve"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("con_stimulate_general_valve"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "con_stimulate_general_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_34;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_con_stop_stimulate_general_valve");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_con_stop_stimulate_general_valve");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_34 = state._tr_con_stop_stimulate_general_valve();
            } else {
                _trid_34 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_con_stop_stimulate_general_valve", _trid_34);
            if(_trid_34) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.con_stop_stimulate_general_valve();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("con_stop_stimulate_general_valve"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("con_stop_stimulate_general_valve"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "con_stop_stimulate_general_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_35;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_evn_open_general_valve");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_evn_open_general_valve");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_35 = state._tr_evn_open_general_valve();
            } else {
                _trid_35 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_evn_open_general_valve", _trid_35);
            if(_trid_35) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.evn_open_general_valve();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("evn_open_general_valve"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("evn_open_general_valve"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "evn_open_general_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_36;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_evn_close_general_valve");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_evn_close_general_valve");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_36 = state._tr_evn_close_general_valve();
            } else {
                _trid_36 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_evn_close_general_valve", _trid_36);
            if(_trid_36) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.evn_close_general_valve();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("evn_close_general_valve"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("evn_close_general_valve"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "evn_close_general_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_37;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_env_close_analogical_switch");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_env_close_analogical_switch");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_37 = state._tr_env_close_analogical_switch();
            } else {
                _trid_37 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_env_close_analogical_switch", _trid_37);
            if(_trid_37) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.env_close_analogical_switch();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("env_close_analogical_switch"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("env_close_analogical_switch"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_close_analogical_switch");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_38;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_env_open_analogical_switch");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_env_open_analogical_switch");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_38 = state._tr_env_open_analogical_switch();
            } else {
                _trid_38 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_env_open_analogical_switch", _trid_38);
            if(_trid_38) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.env_open_analogical_switch();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("env_open_analogical_switch"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("env_open_analogical_switch"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_open_analogical_switch");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }

            synchronized(guardLock) {
                guardCache.put(state, newCache);
            }
        } else {
            if(state._tr_begin_flying()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.begin_flying();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "begin_flying");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_land_plane()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.land_plane();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "land_plane");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_open_valve_door_open()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.open_valve_door_open();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "open_valve_door_open");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_close_valve_door_open()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.close_valve_door_open();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "close_valve_door_open");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_open_valve_door_close()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.open_valve_door_close();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "open_valve_door_close");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_close_valve_door_close()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.close_valve_door_close();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "close_valve_door_close");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_open_valve_retract_gear()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.open_valve_retract_gear();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "open_valve_retract_gear");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_close_valve_retract_gear()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.close_valve_retract_gear();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "close_valve_retract_gear");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_open_valve_extend_gear()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.open_valve_extend_gear();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "open_valve_extend_gear");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_close_valve_extend_gear()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.close_valve_extend_gear();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "close_valve_extend_gear");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_con_stimulate_open_door_valve()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.con_stimulate_open_door_valve();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "con_stimulate_open_door_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_con_stop_stimulate_open_door_valve()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.con_stop_stimulate_open_door_valve();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "con_stop_stimulate_open_door_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_con_stimulate_close_door_valve()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.con_stimulate_close_door_valve();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "con_stimulate_close_door_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_con_stop_stimulate_close_door_valve()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.con_stop_stimulate_close_door_valve();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "con_stop_stimulate_close_door_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_con_stimulate_retract_gear_valve()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.con_stimulate_retract_gear_valve();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "con_stimulate_retract_gear_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_con_stop_stimulate_retract_gear_valve()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.con_stop_stimulate_retract_gear_valve();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "con_stop_stimulate_retract_gear_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_con_stimulate_extend_gear_valve()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.con_stimulate_extend_gear_valve();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "con_stimulate_extend_gear_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_con_stop_stimulate_extend_gear_valve()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.con_stop_stimulate_extend_gear_valve();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "con_stop_stimulate_extend_gear_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_19 = state._tr_env_start_retracting_first();
            for(POSITION param : _trid_19) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_start_retracting_first(_tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_start_retracting_first");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_20 = state._tr_env_retract_gear_skip();
            for(POSITION param : _trid_20) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_retract_gear_skip(_tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_retract_gear_skip");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_21 = state._tr_env_retract_gear_last();
            for(POSITION param : _trid_21) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_retract_gear_last(_tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_retract_gear_last");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_22 = state._tr_env_start_extending();
            for(POSITION param : _trid_22) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_start_extending(_tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_start_extending");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_23 = state._tr_env_extend_gear_last();
            for(POSITION param : _trid_23) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_extend_gear_last(_tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_extend_gear_last");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_24 = state._tr_env_extend_gear_skip();
            for(POSITION param : _trid_24) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_extend_gear_skip(_tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_extend_gear_skip");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_25 = state._tr_env_start_open_door();
            for(POSITION param : _trid_25) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_start_open_door(_tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_start_open_door");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_26 = state._tr_env_open_door_last();
            for(POSITION param : _trid_26) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_open_door_last(_tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_open_door_last");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_27 = state._tr_env_open_door_skip();
            for(POSITION param : _trid_27) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_open_door_skip(_tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_open_door_skip");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_28 = state._tr_env_start_close_door();
            for(POSITION param : _trid_28) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_start_close_door(_tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_start_close_door");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_29 = state._tr_env_close_door();
            for(POSITION param : _trid_29) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_close_door(_tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_close_door");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<POSITION> _trid_30 = state._tr_env_close_door_skip();
            for(POSITION param : _trid_30) {
                POSITION _tmp_1 = param;

                LandingGear_R6 copiedState = state._copy();
                copiedState.env_close_door_skip(_tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_close_door_skip");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_toggle_handle_up()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.toggle_handle_up();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "toggle_handle_up");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_toggle_handle_down()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.toggle_handle_down();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "toggle_handle_down");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_con_stimulate_general_valve()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.con_stimulate_general_valve();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "con_stimulate_general_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_con_stop_stimulate_general_valve()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.con_stop_stimulate_general_valve();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "con_stop_stimulate_general_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_evn_open_general_valve()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.evn_open_general_valve();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "evn_open_general_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_evn_close_general_valve()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.evn_close_general_valve();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "evn_close_general_valve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_env_close_analogical_switch()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.env_close_analogical_switch();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_close_analogical_switch");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_env_open_analogical_switch()) {
                LandingGear_R6 copiedState = state._copy();
                copiedState.env_open_analogical_switch();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "env_open_analogical_switch");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }

        }
        return result;
    }


    public static boolean checkInvariants(Object guardLock, LandingGear_R6 state, boolean isCaching, Map<LandingGear_R6, Set<String>> dependentInvariant) {
        if(isCaching) {
            Set<String> dependentInvariantsOfState;
            synchronized(guardLock) {
                dependentInvariantsOfState = dependentInvariant.get(state);
            }
            if(dependentInvariantsOfState.contains("_check_inv_1")) {
                if(!state._check_inv_1()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_2")) {
                if(!state._check_inv_2()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_3")) {
                if(!state._check_inv_3()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_4")) {
                if(!state._check_inv_4()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_5")) {
                if(!state._check_inv_5()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_6")) {
                if(!state._check_inv_6()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_7")) {
                if(!state._check_inv_7()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_8")) {
                if(!state._check_inv_8()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_9")) {
                if(!state._check_inv_9()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_10")) {
                if(!state._check_inv_10()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_11")) {
                if(!state._check_inv_11()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_12")) {
                if(!state._check_inv_12()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_13")) {
                if(!state._check_inv_13()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_14")) {
                if(!state._check_inv_14()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_15")) {
                if(!state._check_inv_15()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_16")) {
                if(!state._check_inv_16()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_17")) {
                if(!state._check_inv_17()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_18")) {
                if(!state._check_inv_18()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_19")) {
                if(!state._check_inv_19()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_20")) {
                if(!state._check_inv_20()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_21")) {
                if(!state._check_inv_21()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_22")) {
                if(!state._check_inv_22()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_23")) {
                if(!state._check_inv_23()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_24")) {
                if(!state._check_inv_24()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_25")) {
                if(!state._check_inv_25()) {
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6() || !state._check_inv_7() || !state._check_inv_8() || !state._check_inv_9() || !state._check_inv_10() || !state._check_inv_11() || !state._check_inv_12() || !state._check_inv_13() || !state._check_inv_14() || !state._check_inv_15() || !state._check_inv_16() || !state._check_inv_17() || !state._check_inv_18() || !state._check_inv_19() || !state._check_inv_20() || !state._check_inv_21() || !state._check_inv_22() || !state._check_inv_23() || !state._check_inv_24() || !state._check_inv_25());
    }

    private static void printResult(int states, int transitions, boolean deadlockDetected, boolean invariantViolated, List<LandingGear_R6> counterExampleState, Map<LandingGear_R6, LandingGear_R6> parents, Map<LandingGear_R6, String> stateAccessedVia) {

        if(invariantViolated || deadlockDetected) {
            if(deadlockDetected) {
                System.out.println("DEADLOCK DETECTED");
            }
            if(invariantViolated) {
                System.out.println("INVARIANT VIOLATED");
            }
            System.out.println("COUNTER EXAMPLE TRACE: ");
            StringBuilder sb = new StringBuilder();
            if(counterExampleState.size() >= 1) {
                LandingGear_R6 currentState = counterExampleState.get(0);
                while(currentState != null) {
                    sb.insert(0, currentState.toString());
                    sb.insert(0, "\n");
                    sb.insert(0, stateAccessedVia.get(currentState));
                    sb.insert(0, "\n\n");
                    currentState = parents.get(currentState);
                }
            }
            System.out.println(sb.toString());

        }
        if(!deadlockDetected && !invariantViolated) {
            System.out.println("MODEL CHECKING SUCCESSFUL");
        }
        System.out.println("Number of States: " + states);
        System.out.println("Number of Transitions: " + transitions);
    }

    private static LandingGear_R6 next(LinkedList<LandingGear_R6> collection, Object lock, Type type) {
        synchronized(lock) {
            return switch(type) {
                case BFS -> collection.removeFirst();
                case DFS -> collection.removeLast();
                case MIXED -> collection.size() % 2 == 0 ? collection.removeFirst() : collection.removeLast();
            };
        }
    }

    private static void modelCheckSingleThreaded(Type type, boolean isCaching) {
        Object lock = new Object();
        Object guardLock = new Object();

        LandingGear_R6 machine = new LandingGear_R6();


        AtomicBoolean invariantViolated = new AtomicBoolean(false);
        AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        AtomicBoolean stopThreads = new AtomicBoolean(false);

        Set<LandingGear_R6> states = new HashSet<>();
        states.add(machine);
        AtomicInteger numberStates = new AtomicInteger(1);

        LinkedList<LandingGear_R6> collection = new LinkedList<>();
        collection.add(machine);

        Map<String, Set<String>> invariantDependency = new HashMap<>();
        Map<String, Set<String>> guardDependency = new HashMap<>();
        Map<LandingGear_R6, Set<String>> dependentInvariant = new HashMap<>();
        Map<LandingGear_R6, Set<String>> dependentGuard = new HashMap<>();
        Map<LandingGear_R6, PersistentHashMap> guardCache = new HashMap<>();
        Map<LandingGear_R6, LandingGear_R6> parents = new HashMap<>();
        Map<LandingGear_R6, String> stateAccessedVia = new HashMap<>();
        if(isCaching) {
            invariantDependency.put("close_valve_door_close", new HashSet<>(Arrays.asList("_check_inv_10")));
            invariantDependency.put("close_valve_retract_gear", new HashSet<>(Arrays.asList("_check_inv_13")));
            invariantDependency.put("con_stimulate_open_door_valve", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_17", "_check_inv_7")));
            invariantDependency.put("env_close_door", new HashSet<>(Arrays.asList("_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22")));
            invariantDependency.put("env_start_close_door", new HashSet<>(Arrays.asList("_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22")));
            invariantDependency.put("toggle_handle_up", new HashSet<>(Arrays.asList("_check_inv_4", "_check_inv_14")));
            invariantDependency.put("toggle_handle_down", new HashSet<>(Arrays.asList("_check_inv_4", "_check_inv_14")));
            invariantDependency.put("open_valve_door_open", new HashSet<>(Arrays.asList("_check_inv_12")));
            invariantDependency.put("env_retract_gear_last", new HashSet<>(Arrays.asList("_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23")));
            invariantDependency.put("env_open_door_last", new HashSet<>(Arrays.asList("_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22")));
            invariantDependency.put("con_stop_stimulate_retract_gear_valve", new HashSet<>(Arrays.asList("_check_inv_17", "_check_inv_8")));
            invariantDependency.put("env_close_door_skip", new HashSet<>(Arrays.asList("_check_inv_21", "_check_inv_20", "_check_inv_22")));
            invariantDependency.put("con_stop_stimulate_close_door_valve", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_17", "_check_inv_5")));
            invariantDependency.put("env_open_analogical_switch", new HashSet<>(Arrays.asList("_check_inv_1")));
            invariantDependency.put("con_stop_stimulate_general_valve", new HashSet<>(Arrays.asList("_check_inv_17", "_check_inv_2", "_check_inv_4")));
            invariantDependency.put("env_extend_gear_last", new HashSet<>(Arrays.asList("_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23")));
            invariantDependency.put("evn_open_general_valve", new HashSet<>(Arrays.asList("_check_inv_3")));
            invariantDependency.put("land_plane", new HashSet<>(Arrays.asList("_check_inv_9")));
            invariantDependency.put("con_stimulate_retract_gear_valve", new HashSet<>(Arrays.asList("_check_inv_17", "_check_inv_8")));
            invariantDependency.put("con_stimulate_general_valve", new HashSet<>(Arrays.asList("_check_inv_17", "_check_inv_2")));
            invariantDependency.put("env_start_retracting_first", new HashSet<>(Arrays.asList("_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23")));
            invariantDependency.put("env_retract_gear_skip", new HashSet<>(Arrays.asList("_check_inv_19", "_check_inv_24", "_check_inv_23")));
            invariantDependency.put("open_valve_extend_gear", new HashSet<>(Arrays.asList("_check_inv_11")));
            invariantDependency.put("begin_flying", new HashSet<>(Arrays.asList("_check_inv_9")));
            invariantDependency.put("open_valve_retract_gear", new HashSet<>(Arrays.asList("_check_inv_13")));
            invariantDependency.put("env_close_analogical_switch", new HashSet<>(Arrays.asList("_check_inv_1")));
            invariantDependency.put("env_start_extending", new HashSet<>(Arrays.asList("_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23")));
            invariantDependency.put("open_valve_door_close", new HashSet<>(Arrays.asList("_check_inv_10")));
            invariantDependency.put("con_stop_stimulate_open_door_valve", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_17", "_check_inv_7")));
            invariantDependency.put("con_stop_stimulate_extend_gear_valve", new HashSet<>(Arrays.asList("_check_inv_17", "_check_inv_6")));
            invariantDependency.put("evn_close_general_valve", new HashSet<>(Arrays.asList("_check_inv_3")));
            invariantDependency.put("close_valve_extend_gear", new HashSet<>(Arrays.asList("_check_inv_11")));
            invariantDependency.put("con_stimulate_extend_gear_valve", new HashSet<>(Arrays.asList("_check_inv_17", "_check_inv_6")));
            invariantDependency.put("close_valve_door_open", new HashSet<>(Arrays.asList("_check_inv_12")));
            invariantDependency.put("con_stimulate_close_door_valve", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_17", "_check_inv_5")));
            invariantDependency.put("env_extend_gear_skip", new HashSet<>(Arrays.asList("_check_inv_19", "_check_inv_24", "_check_inv_23")));
            invariantDependency.put("env_open_door_skip", new HashSet<>(Arrays.asList("_check_inv_21", "_check_inv_20", "_check_inv_22")));
            invariantDependency.put("env_start_open_door", new HashSet<>(Arrays.asList("_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22")));
            guardDependency.put("close_valve_door_close", new HashSet<>(Arrays.asList("_tr_open_valve_door_close", "_tr_env_close_door_skip", "_tr_env_start_close_door", "_tr_env_close_door", "_tr_close_valve_door_close")));
            guardDependency.put("close_valve_retract_gear", new HashSet<>(Arrays.asList("_tr_close_valve_retract_gear", "_tr_open_valve_retract_gear", "_tr_env_start_retracting_first")));
            guardDependency.put("con_stimulate_open_door_valve", new HashSet<>(Arrays.asList("_tr_open_valve_door_open", "_tr_con_stimulate_extend_gear_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_open")));
            guardDependency.put("env_close_door", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("env_start_close_door", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("toggle_handle_up", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_close_analogical_switch", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip", "_tr_con_stimulate_general_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_toggle_handle_down", "_tr_env_open_door_last", "_tr_toggle_handle_up", "_tr_env_start_close_door", "_tr_con_stop_stimulate_close_door_valve")));
            guardDependency.put("toggle_handle_down", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_close_analogical_switch", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip", "_tr_con_stimulate_general_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_toggle_handle_down", "_tr_env_open_door_last", "_tr_toggle_handle_up", "_tr_env_start_close_door", "_tr_con_stop_stimulate_close_door_valve")));
            guardDependency.put("open_valve_door_open", new HashSet<>(Arrays.asList("_tr_open_valve_door_open", "_tr_env_open_door_last", "_tr_env_start_open_door", "_tr_env_open_door_skip", "_tr_close_valve_door_open")));
            guardDependency.put("env_retract_gear_last", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("env_open_door_last", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("con_stop_stimulate_retract_gear_valve", new HashSet<>(Arrays.asList("_tr_close_valve_retract_gear", "_tr_con_stimulate_extend_gear_valve", "_tr_open_valve_retract_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_retract_gear_valve")));
            guardDependency.put("env_close_door_skip", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("con_stop_stimulate_close_door_valve", new HashSet<>(Arrays.asList("_tr_open_valve_door_close", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_close")));
            guardDependency.put("env_open_analogical_switch", new HashSet<>(Arrays.asList("_tr_env_open_analogical_switch", "_tr_evn_open_general_valve", "_tr_env_close_analogical_switch", "_tr_evn_close_general_valve")));
            guardDependency.put("con_stop_stimulate_general_valve", new HashSet<>(Arrays.asList("_tr_con_stimulate_extend_gear_valve", "_tr_con_stimulate_general_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_evn_open_general_valve", "_tr_env_close_analogical_switch", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_evn_close_general_valve", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve")));
            guardDependency.put("env_extend_gear_last", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("evn_open_general_valve", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_env_close_door_skip", "_tr_evn_open_general_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_evn_close_general_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("land_plane", new HashSet<>(Arrays.asList("_tr_land_plane", "_tr_begin_flying", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_close_door")));
            guardDependency.put("con_stimulate_retract_gear_valve", new HashSet<>(Arrays.asList("_tr_close_valve_retract_gear", "_tr_con_stimulate_extend_gear_valve", "_tr_open_valve_retract_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_retract_gear_valve")));
            guardDependency.put("con_stimulate_general_valve", new HashSet<>(Arrays.asList("_tr_con_stimulate_extend_gear_valve", "_tr_con_stimulate_general_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_evn_open_general_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_evn_close_general_valve", "_tr_con_stop_stimulate_retract_gear_valve")));
            guardDependency.put("env_start_retracting_first", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("env_retract_gear_skip", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("open_valve_extend_gear", new HashSet<>(Arrays.asList("_tr_close_valve_extend_gear", "_tr_open_valve_extend_gear", "_tr_env_start_extending")));
            guardDependency.put("begin_flying", new HashSet<>(Arrays.asList("_tr_land_plane", "_tr_begin_flying", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_close_door")));
            guardDependency.put("open_valve_retract_gear", new HashSet<>(Arrays.asList("_tr_close_valve_retract_gear", "_tr_open_valve_retract_gear", "_tr_env_start_retracting_first")));
            guardDependency.put("env_close_analogical_switch", new HashSet<>(Arrays.asList("_tr_env_open_analogical_switch", "_tr_evn_open_general_valve", "_tr_env_close_analogical_switch", "_tr_evn_close_general_valve")));
            guardDependency.put("env_start_extending", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("open_valve_door_close", new HashSet<>(Arrays.asList("_tr_open_valve_door_close", "_tr_env_close_door_skip", "_tr_env_start_close_door", "_tr_env_close_door", "_tr_close_valve_door_close")));
            guardDependency.put("con_stop_stimulate_open_door_valve", new HashSet<>(Arrays.asList("_tr_open_valve_door_open", "_tr_con_stimulate_extend_gear_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_open")));
            guardDependency.put("con_stop_stimulate_extend_gear_valve", new HashSet<>(Arrays.asList("_tr_con_stimulate_extend_gear_valve", "_tr_close_valve_extend_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_open_valve_extend_gear", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_extend_gear_valve")));
            guardDependency.put("evn_close_general_valve", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_env_close_door_skip", "_tr_evn_open_general_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_evn_close_general_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("close_valve_extend_gear", new HashSet<>(Arrays.asList("_tr_close_valve_extend_gear", "_tr_open_valve_extend_gear", "_tr_env_start_extending")));
            guardDependency.put("con_stimulate_extend_gear_valve", new HashSet<>(Arrays.asList("_tr_con_stimulate_extend_gear_valve", "_tr_close_valve_extend_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_open_valve_extend_gear", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_extend_gear_valve")));
            guardDependency.put("close_valve_door_open", new HashSet<>(Arrays.asList("_tr_open_valve_door_open", "_tr_env_open_door_last", "_tr_env_start_open_door", "_tr_env_open_door_skip", "_tr_close_valve_door_open")));
            guardDependency.put("con_stimulate_close_door_valve", new HashSet<>(Arrays.asList("_tr_open_valve_door_close", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_close")));
            guardDependency.put("env_extend_gear_skip", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("env_open_door_skip", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("env_start_open_door", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            dependentInvariant.put(machine, new HashSet<>());
        }
        List<LandingGear_R6> counterExampleState = new ArrayList<>();
        parents.put(machine, null);

        AtomicInteger transitions = new AtomicInteger(0);

        while(!collection.isEmpty() && !stopThreads.get()) {
            LandingGear_R6 state = next(collection, lock, type);

            Set<LandingGear_R6> nextStates = generateNextStates(guardLock, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, stateAccessedVia, transitions);

            nextStates.forEach(nextState -> {
                if(!states.contains(nextState)) {
                    numberStates.getAndIncrement();
                    states.add(nextState);
                    collection.add(nextState);
                    if(numberStates.get() % 50000 == 0) {
                        System.out.println("VISITED STATES: " + numberStates.get());
                        System.out.println("EVALUATED TRANSITIONS: " + transitions.get());
                        System.out.println("-------------------");
                    }
                }
            });

            if(!checkInvariants(guardLock, state, isCaching, dependentInvariant)) {
                invariantViolated.set(true);
                stopThreads.set(true);
                counterExampleState.add(state);
            }

            if(nextStates.isEmpty()) {
                deadlockDetected.set(true);
                stopThreads.set(true);
            }

        }
        printResult(numberStates.get(), transitions.get(), deadlockDetected.get(), invariantViolated.get(), counterExampleState, parents, stateAccessedVia);
    }


    private static void modelCheckMultiThreaded(Type type, int threads, boolean isCaching) {
        Object lock = new Object();
        Object guardLock = new Object();
        Object waitLock = new Object();
        ThreadPoolExecutor threadPool = (ThreadPoolExecutor) Executors.newFixedThreadPool(threads);

        LandingGear_R6 machine = new LandingGear_R6();


        AtomicBoolean invariantViolated = new AtomicBoolean(false);
        AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        AtomicBoolean stopThreads = new AtomicBoolean(false);
        AtomicInteger possibleQueueChanges = new AtomicInteger(0);

        Set<LandingGear_R6> states = new HashSet<>();
        states.add(machine);
        AtomicInteger numberStates = new AtomicInteger(1);

        LinkedList<LandingGear_R6> collection = new LinkedList<>();
        collection.add(machine);

        Map<String, Set<String>> invariantDependency = new HashMap<>();
        Map<String, Set<String>> guardDependency = new HashMap<>();
        Map<LandingGear_R6, Set<String>> dependentInvariant = new HashMap<>();
        Map<LandingGear_R6, Set<String>> dependentGuard = new HashMap<>();
        Map<LandingGear_R6, PersistentHashMap> guardCache = new HashMap<>();
        Map<LandingGear_R6, LandingGear_R6> parents = new HashMap<>();
        Map<LandingGear_R6, String> stateAccessedVia = new HashMap<>();
        if(isCaching) {
            invariantDependency.put("close_valve_door_close", new HashSet<>(Arrays.asList("_check_inv_10")));
            invariantDependency.put("close_valve_retract_gear", new HashSet<>(Arrays.asList("_check_inv_13")));
            invariantDependency.put("con_stimulate_open_door_valve", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_17", "_check_inv_7")));
            invariantDependency.put("env_close_door", new HashSet<>(Arrays.asList("_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22")));
            invariantDependency.put("env_start_close_door", new HashSet<>(Arrays.asList("_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22")));
            invariantDependency.put("toggle_handle_up", new HashSet<>(Arrays.asList("_check_inv_4", "_check_inv_14")));
            invariantDependency.put("toggle_handle_down", new HashSet<>(Arrays.asList("_check_inv_4", "_check_inv_14")));
            invariantDependency.put("open_valve_door_open", new HashSet<>(Arrays.asList("_check_inv_12")));
            invariantDependency.put("env_retract_gear_last", new HashSet<>(Arrays.asList("_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23")));
            invariantDependency.put("env_open_door_last", new HashSet<>(Arrays.asList("_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22")));
            invariantDependency.put("con_stop_stimulate_retract_gear_valve", new HashSet<>(Arrays.asList("_check_inv_17", "_check_inv_8")));
            invariantDependency.put("env_close_door_skip", new HashSet<>(Arrays.asList("_check_inv_21", "_check_inv_20", "_check_inv_22")));
            invariantDependency.put("con_stop_stimulate_close_door_valve", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_17", "_check_inv_5")));
            invariantDependency.put("env_open_analogical_switch", new HashSet<>(Arrays.asList("_check_inv_1")));
            invariantDependency.put("con_stop_stimulate_general_valve", new HashSet<>(Arrays.asList("_check_inv_17", "_check_inv_2", "_check_inv_4")));
            invariantDependency.put("env_extend_gear_last", new HashSet<>(Arrays.asList("_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23")));
            invariantDependency.put("evn_open_general_valve", new HashSet<>(Arrays.asList("_check_inv_3")));
            invariantDependency.put("land_plane", new HashSet<>(Arrays.asList("_check_inv_9")));
            invariantDependency.put("con_stimulate_retract_gear_valve", new HashSet<>(Arrays.asList("_check_inv_17", "_check_inv_8")));
            invariantDependency.put("con_stimulate_general_valve", new HashSet<>(Arrays.asList("_check_inv_17", "_check_inv_2")));
            invariantDependency.put("env_start_retracting_first", new HashSet<>(Arrays.asList("_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23")));
            invariantDependency.put("env_retract_gear_skip", new HashSet<>(Arrays.asList("_check_inv_19", "_check_inv_24", "_check_inv_23")));
            invariantDependency.put("open_valve_extend_gear", new HashSet<>(Arrays.asList("_check_inv_11")));
            invariantDependency.put("begin_flying", new HashSet<>(Arrays.asList("_check_inv_9")));
            invariantDependency.put("open_valve_retract_gear", new HashSet<>(Arrays.asList("_check_inv_13")));
            invariantDependency.put("env_close_analogical_switch", new HashSet<>(Arrays.asList("_check_inv_1")));
            invariantDependency.put("env_start_extending", new HashSet<>(Arrays.asList("_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23")));
            invariantDependency.put("open_valve_door_close", new HashSet<>(Arrays.asList("_check_inv_10")));
            invariantDependency.put("con_stop_stimulate_open_door_valve", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_17", "_check_inv_7")));
            invariantDependency.put("con_stop_stimulate_extend_gear_valve", new HashSet<>(Arrays.asList("_check_inv_17", "_check_inv_6")));
            invariantDependency.put("evn_close_general_valve", new HashSet<>(Arrays.asList("_check_inv_3")));
            invariantDependency.put("close_valve_extend_gear", new HashSet<>(Arrays.asList("_check_inv_11")));
            invariantDependency.put("con_stimulate_extend_gear_valve", new HashSet<>(Arrays.asList("_check_inv_17", "_check_inv_6")));
            invariantDependency.put("close_valve_door_open", new HashSet<>(Arrays.asList("_check_inv_12")));
            invariantDependency.put("con_stimulate_close_door_valve", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_17", "_check_inv_5")));
            invariantDependency.put("env_extend_gear_skip", new HashSet<>(Arrays.asList("_check_inv_19", "_check_inv_24", "_check_inv_23")));
            invariantDependency.put("env_open_door_skip", new HashSet<>(Arrays.asList("_check_inv_21", "_check_inv_20", "_check_inv_22")));
            invariantDependency.put("env_start_open_door", new HashSet<>(Arrays.asList("_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22")));
            guardDependency.put("close_valve_door_close", new HashSet<>(Arrays.asList("_tr_open_valve_door_close", "_tr_env_close_door_skip", "_tr_env_start_close_door", "_tr_env_close_door", "_tr_close_valve_door_close")));
            guardDependency.put("close_valve_retract_gear", new HashSet<>(Arrays.asList("_tr_close_valve_retract_gear", "_tr_open_valve_retract_gear", "_tr_env_start_retracting_first")));
            guardDependency.put("con_stimulate_open_door_valve", new HashSet<>(Arrays.asList("_tr_open_valve_door_open", "_tr_con_stimulate_extend_gear_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_open")));
            guardDependency.put("env_close_door", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("env_start_close_door", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("toggle_handle_up", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_close_analogical_switch", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip", "_tr_con_stimulate_general_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_toggle_handle_down", "_tr_env_open_door_last", "_tr_toggle_handle_up", "_tr_env_start_close_door", "_tr_con_stop_stimulate_close_door_valve")));
            guardDependency.put("toggle_handle_down", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_close_analogical_switch", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip", "_tr_con_stimulate_general_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_toggle_handle_down", "_tr_env_open_door_last", "_tr_toggle_handle_up", "_tr_env_start_close_door", "_tr_con_stop_stimulate_close_door_valve")));
            guardDependency.put("open_valve_door_open", new HashSet<>(Arrays.asList("_tr_open_valve_door_open", "_tr_env_open_door_last", "_tr_env_start_open_door", "_tr_env_open_door_skip", "_tr_close_valve_door_open")));
            guardDependency.put("env_retract_gear_last", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("env_open_door_last", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("con_stop_stimulate_retract_gear_valve", new HashSet<>(Arrays.asList("_tr_close_valve_retract_gear", "_tr_con_stimulate_extend_gear_valve", "_tr_open_valve_retract_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_retract_gear_valve")));
            guardDependency.put("env_close_door_skip", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("con_stop_stimulate_close_door_valve", new HashSet<>(Arrays.asList("_tr_open_valve_door_close", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_close")));
            guardDependency.put("env_open_analogical_switch", new HashSet<>(Arrays.asList("_tr_env_open_analogical_switch", "_tr_evn_open_general_valve", "_tr_env_close_analogical_switch", "_tr_evn_close_general_valve")));
            guardDependency.put("con_stop_stimulate_general_valve", new HashSet<>(Arrays.asList("_tr_con_stimulate_extend_gear_valve", "_tr_con_stimulate_general_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_evn_open_general_valve", "_tr_env_close_analogical_switch", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_evn_close_general_valve", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve")));
            guardDependency.put("env_extend_gear_last", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("evn_open_general_valve", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_env_close_door_skip", "_tr_evn_open_general_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_evn_close_general_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("land_plane", new HashSet<>(Arrays.asList("_tr_land_plane", "_tr_begin_flying", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_close_door")));
            guardDependency.put("con_stimulate_retract_gear_valve", new HashSet<>(Arrays.asList("_tr_close_valve_retract_gear", "_tr_con_stimulate_extend_gear_valve", "_tr_open_valve_retract_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_retract_gear_valve")));
            guardDependency.put("con_stimulate_general_valve", new HashSet<>(Arrays.asList("_tr_con_stimulate_extend_gear_valve", "_tr_con_stimulate_general_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_evn_open_general_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_evn_close_general_valve", "_tr_con_stop_stimulate_retract_gear_valve")));
            guardDependency.put("env_start_retracting_first", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("env_retract_gear_skip", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("open_valve_extend_gear", new HashSet<>(Arrays.asList("_tr_close_valve_extend_gear", "_tr_open_valve_extend_gear", "_tr_env_start_extending")));
            guardDependency.put("begin_flying", new HashSet<>(Arrays.asList("_tr_land_plane", "_tr_begin_flying", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_close_door")));
            guardDependency.put("open_valve_retract_gear", new HashSet<>(Arrays.asList("_tr_close_valve_retract_gear", "_tr_open_valve_retract_gear", "_tr_env_start_retracting_first")));
            guardDependency.put("env_close_analogical_switch", new HashSet<>(Arrays.asList("_tr_env_open_analogical_switch", "_tr_evn_open_general_valve", "_tr_env_close_analogical_switch", "_tr_evn_close_general_valve")));
            guardDependency.put("env_start_extending", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("open_valve_door_close", new HashSet<>(Arrays.asList("_tr_open_valve_door_close", "_tr_env_close_door_skip", "_tr_env_start_close_door", "_tr_env_close_door", "_tr_close_valve_door_close")));
            guardDependency.put("con_stop_stimulate_open_door_valve", new HashSet<>(Arrays.asList("_tr_open_valve_door_open", "_tr_con_stimulate_extend_gear_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_open")));
            guardDependency.put("con_stop_stimulate_extend_gear_valve", new HashSet<>(Arrays.asList("_tr_con_stimulate_extend_gear_valve", "_tr_close_valve_extend_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_open_valve_extend_gear", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_extend_gear_valve")));
            guardDependency.put("evn_close_general_valve", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_env_close_door_skip", "_tr_evn_open_general_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_evn_close_general_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("close_valve_extend_gear", new HashSet<>(Arrays.asList("_tr_close_valve_extend_gear", "_tr_open_valve_extend_gear", "_tr_env_start_extending")));
            guardDependency.put("con_stimulate_extend_gear_valve", new HashSet<>(Arrays.asList("_tr_con_stimulate_extend_gear_valve", "_tr_close_valve_extend_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_open_valve_extend_gear", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_extend_gear_valve")));
            guardDependency.put("close_valve_door_open", new HashSet<>(Arrays.asList("_tr_open_valve_door_open", "_tr_env_open_door_last", "_tr_env_start_open_door", "_tr_env_open_door_skip", "_tr_close_valve_door_open")));
            guardDependency.put("con_stimulate_close_door_valve", new HashSet<>(Arrays.asList("_tr_open_valve_door_close", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_close")));
            guardDependency.put("env_extend_gear_skip", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("env_open_door_skip", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            guardDependency.put("env_start_open_door", new HashSet<>(Arrays.asList("_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip")));
            dependentInvariant.put(machine, new HashSet<>());
        }
        List<LandingGear_R6> counterExampleState = new ArrayList<>();
        parents.put(machine, null);
        stateAccessedVia.put(machine, null);

        AtomicInteger transitions = new AtomicInteger(0);

        while(!collection.isEmpty() && !stopThreads.get()) {
            possibleQueueChanges.incrementAndGet();
            LandingGear_R6 state = next(collection, lock, type);
            Runnable task = () -> {
                Set<LandingGear_R6> nextStates = generateNextStates(guardLock, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, stateAccessedVia, transitions);

                nextStates.forEach(nextState -> {
                    synchronized(lock) {
                        if(!states.contains(nextState)) {
                            numberStates.getAndIncrement();
                            states.add(nextState);
                            collection.add(nextState);
                            if(numberStates.get() % 50000 == 0) {
                                System.out.println("VISITED STATES: " + numberStates.get());
                                System.out.println("EVALUATED TRANSITIONS: " + transitions.get());
                                System.out.println("-------------------");
                            }
                        }
                    }
                });

                synchronized (lock) {
                    int running = possibleQueueChanges.decrementAndGet();
                    if (!collection.isEmpty() || running == 0) {
                        synchronized (waitLock) {
                            waitLock.notify();
                        }
                    }
                }

                if(nextStates.isEmpty()) {
                    deadlockDetected.set(true);
                    stopThreads.set(true);
                }

                if(!checkInvariants(guardLock, state, isCaching, dependentInvariant)) {
                    invariantViolated.set(true);
                    stopThreads.set(true);
                    counterExampleState.add(state);
                }


            };
            threadPool.submit(task);
            synchronized(waitLock) {
                if (collection.isEmpty() && possibleQueueChanges.get() > 0) {
                    try {
                        waitLock.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }

        }
        threadPool.shutdown();
        try {
            threadPool.awaitTermination(5, TimeUnit.SECONDS);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        printResult(numberStates.get(), transitions.get(), deadlockDetected.get(), invariantViolated.get(), counterExampleState, parents, stateAccessedVia);
    }


    public static void main(String[] args) {
        if(args.length != 3) {
            System.out.println("Number of arguments errorneous");
            return;
        }
        String strategy = args[0];
        String numberThreads = args[1];
        String caching = args[2];

        Type type;

        if("mixed".equals(strategy)) {
            type = Type.MIXED;
        } else if("bf".equals(strategy)) {
            type = Type.BFS;
        } else if ("df".equals(strategy)) {
            type = Type.DFS;
        } else {
            System.out.println("Input for strategy is wrong.");
            return;
        }

        int threads = 0;
        try {
            threads = Integer.parseInt(numberThreads);
        } catch(NumberFormatException e) {
            System.out.println("Input for number of threads is wrong.");
            return;
        }
        if(threads <= 0) {
            System.out.println("Input for number of threads is wrong.");
            return;
        }

        boolean isCaching = true;
        try {
            isCaching = Boolean.parseBoolean(caching);
        } catch(Exception e) {
            System.out.println("Input for caching is wrong.");
            return;
        }
        if(threads == 1) {
            modelCheckSingleThreaded(type, isCaching);
        } else {
            modelCheckMultiThreaded(type, threads, isCaching);
        }
    }




}
