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
import java.util.concurrent.ConcurrentHashMap;
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
import de.hhu.stups.btypes.LoopInvariantViolation;
import de.hhu.stups.btypes.VariantViolation;
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

    public LandingGear_R6 parent;
    public String stateAccessedVia;

    public static class _ProjectionRead_begin_flying {

        public PLANE_STATE shock_absorber;

        public _ProjectionRead_begin_flying(PLANE_STATE shock_absorber) {
            this.shock_absorber = shock_absorber;
        }

        public String toString() {
            return "{" + "shock_absorber: " + this.shock_absorber + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_begin_flying)) {
                return false;
            }
            _ProjectionRead_begin_flying o = (_ProjectionRead_begin_flying) other;
            return this.shock_absorber.equals(o.shock_absorber);
        }

        public int hashCode() {
            return Objects.hash(shock_absorber);
        }
    }

    public static class _ProjectionRead__tr_begin_flying {

        public PLANE_STATE shock_absorber;

        public _ProjectionRead__tr_begin_flying(PLANE_STATE shock_absorber) {
            this.shock_absorber = shock_absorber;
        }

        public String toString() {
            return "{" + "shock_absorber: " + this.shock_absorber + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_begin_flying)) {
                return false;
            }
            _ProjectionRead__tr_begin_flying o = (_ProjectionRead__tr_begin_flying) other;
            return this.shock_absorber.equals(o.shock_absorber);
        }

        public int hashCode() {
            return Objects.hash(shock_absorber);
        }
    }

    public static class _ProjectionWrite_begin_flying {

        public PLANE_STATE shock_absorber;

        public _ProjectionWrite_begin_flying(PLANE_STATE shock_absorber) {
            this.shock_absorber = shock_absorber;
        }

        public String toString() {
            return "{" + "shock_absorber: " + this.shock_absorber + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_begin_flying)) {
                return false;
            }
            _ProjectionWrite_begin_flying o = (_ProjectionWrite_begin_flying) other;
            return this.shock_absorber.equals(o.shock_absorber);
        }

        public int hashCode() {
            return Objects.hash(shock_absorber);
        }
    }

    public static class _ProjectionRead_land_plane {

        public PLANE_STATE shock_absorber;

        public _ProjectionRead_land_plane(PLANE_STATE shock_absorber) {
            this.shock_absorber = shock_absorber;
        }

        public String toString() {
            return "{" + "shock_absorber: " + this.shock_absorber + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_land_plane)) {
                return false;
            }
            _ProjectionRead_land_plane o = (_ProjectionRead_land_plane) other;
            return this.shock_absorber.equals(o.shock_absorber);
        }

        public int hashCode() {
            return Objects.hash(shock_absorber);
        }
    }

    public static class _ProjectionRead__tr_land_plane {

        public PLANE_STATE shock_absorber;

        public _ProjectionRead__tr_land_plane(PLANE_STATE shock_absorber) {
            this.shock_absorber = shock_absorber;
        }

        public String toString() {
            return "{" + "shock_absorber: " + this.shock_absorber + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_land_plane)) {
                return false;
            }
            _ProjectionRead__tr_land_plane o = (_ProjectionRead__tr_land_plane) other;
            return this.shock_absorber.equals(o.shock_absorber);
        }

        public int hashCode() {
            return Objects.hash(shock_absorber);
        }
    }

    public static class _ProjectionWrite_land_plane {

        public PLANE_STATE shock_absorber;

        public _ProjectionWrite_land_plane(PLANE_STATE shock_absorber) {
            this.shock_absorber = shock_absorber;
        }

        public String toString() {
            return "{" + "shock_absorber: " + this.shock_absorber + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_land_plane)) {
                return false;
            }
            _ProjectionWrite_land_plane o = (_ProjectionWrite_land_plane) other;
            return this.shock_absorber.equals(o.shock_absorber);
        }

        public int hashCode() {
            return Objects.hash(shock_absorber);
        }
    }

    public static class _ProjectionRead_open_valve_door_open {

        public VALVE_STATE valve_open_door;
        public BBoolean open_EV;

        public _ProjectionRead_open_valve_door_open(VALVE_STATE valve_open_door, BBoolean open_EV) {
            this.valve_open_door = valve_open_door;
            this.open_EV = open_EV;
        }

        public String toString() {
            return "{" + "valve_open_door: " + this.valve_open_door + "," + "open_EV: " + this.open_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_open_valve_door_open)) {
                return false;
            }
            _ProjectionRead_open_valve_door_open o = (_ProjectionRead_open_valve_door_open) other;
            return this.valve_open_door.equals(o.valve_open_door) && this.open_EV.equals(o.open_EV);
        }

        public int hashCode() {
            return Objects.hash(valve_open_door, open_EV);
        }
    }

    public static class _ProjectionRead__tr_open_valve_door_open {

        public VALVE_STATE valve_open_door;
        public BBoolean open_EV;

        public _ProjectionRead__tr_open_valve_door_open(VALVE_STATE valve_open_door, BBoolean open_EV) {
            this.valve_open_door = valve_open_door;
            this.open_EV = open_EV;
        }

        public String toString() {
            return "{" + "valve_open_door: " + this.valve_open_door + "," + "open_EV: " + this.open_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_open_valve_door_open)) {
                return false;
            }
            _ProjectionRead__tr_open_valve_door_open o = (_ProjectionRead__tr_open_valve_door_open) other;
            return this.valve_open_door.equals(o.valve_open_door) && this.open_EV.equals(o.open_EV);
        }

        public int hashCode() {
            return Objects.hash(valve_open_door, open_EV);
        }
    }

    public static class _ProjectionWrite_open_valve_door_open {

        public VALVE_STATE valve_open_door;

        public _ProjectionWrite_open_valve_door_open(VALVE_STATE valve_open_door) {
            this.valve_open_door = valve_open_door;
        }

        public String toString() {
            return "{" + "valve_open_door: " + this.valve_open_door + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_open_valve_door_open)) {
                return false;
            }
            _ProjectionWrite_open_valve_door_open o = (_ProjectionWrite_open_valve_door_open) other;
            return this.valve_open_door.equals(o.valve_open_door);
        }

        public int hashCode() {
            return Objects.hash(valve_open_door);
        }
    }

    public static class _ProjectionRead_close_valve_door_open {

        public VALVE_STATE valve_open_door;
        public BBoolean open_EV;

        public _ProjectionRead_close_valve_door_open(VALVE_STATE valve_open_door, BBoolean open_EV) {
            this.valve_open_door = valve_open_door;
            this.open_EV = open_EV;
        }

        public String toString() {
            return "{" + "valve_open_door: " + this.valve_open_door + "," + "open_EV: " + this.open_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_close_valve_door_open)) {
                return false;
            }
            _ProjectionRead_close_valve_door_open o = (_ProjectionRead_close_valve_door_open) other;
            return this.valve_open_door.equals(o.valve_open_door) && this.open_EV.equals(o.open_EV);
        }

        public int hashCode() {
            return Objects.hash(valve_open_door, open_EV);
        }
    }

    public static class _ProjectionRead__tr_close_valve_door_open {

        public VALVE_STATE valve_open_door;
        public BBoolean open_EV;

        public _ProjectionRead__tr_close_valve_door_open(VALVE_STATE valve_open_door, BBoolean open_EV) {
            this.valve_open_door = valve_open_door;
            this.open_EV = open_EV;
        }

        public String toString() {
            return "{" + "valve_open_door: " + this.valve_open_door + "," + "open_EV: " + this.open_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_close_valve_door_open)) {
                return false;
            }
            _ProjectionRead__tr_close_valve_door_open o = (_ProjectionRead__tr_close_valve_door_open) other;
            return this.valve_open_door.equals(o.valve_open_door) && this.open_EV.equals(o.open_EV);
        }

        public int hashCode() {
            return Objects.hash(valve_open_door, open_EV);
        }
    }

    public static class _ProjectionWrite_close_valve_door_open {

        public VALVE_STATE valve_open_door;

        public _ProjectionWrite_close_valve_door_open(VALVE_STATE valve_open_door) {
            this.valve_open_door = valve_open_door;
        }

        public String toString() {
            return "{" + "valve_open_door: " + this.valve_open_door + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_close_valve_door_open)) {
                return false;
            }
            _ProjectionWrite_close_valve_door_open o = (_ProjectionWrite_close_valve_door_open) other;
            return this.valve_open_door.equals(o.valve_open_door);
        }

        public int hashCode() {
            return Objects.hash(valve_open_door);
        }
    }

    public static class _ProjectionRead_open_valve_door_close {

        public VALVE_STATE valve_close_door;
        public BBoolean close_EV;

        public _ProjectionRead_open_valve_door_close(VALVE_STATE valve_close_door, BBoolean close_EV) {
            this.valve_close_door = valve_close_door;
            this.close_EV = close_EV;
        }

        public String toString() {
            return "{" + "valve_close_door: " + this.valve_close_door + "," + "close_EV: " + this.close_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_open_valve_door_close)) {
                return false;
            }
            _ProjectionRead_open_valve_door_close o = (_ProjectionRead_open_valve_door_close) other;
            return this.valve_close_door.equals(o.valve_close_door) && this.close_EV.equals(o.close_EV);
        }

        public int hashCode() {
            return Objects.hash(valve_close_door, close_EV);
        }
    }

    public static class _ProjectionRead__tr_open_valve_door_close {

        public VALVE_STATE valve_close_door;
        public BBoolean close_EV;

        public _ProjectionRead__tr_open_valve_door_close(VALVE_STATE valve_close_door, BBoolean close_EV) {
            this.valve_close_door = valve_close_door;
            this.close_EV = close_EV;
        }

        public String toString() {
            return "{" + "valve_close_door: " + this.valve_close_door + "," + "close_EV: " + this.close_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_open_valve_door_close)) {
                return false;
            }
            _ProjectionRead__tr_open_valve_door_close o = (_ProjectionRead__tr_open_valve_door_close) other;
            return this.valve_close_door.equals(o.valve_close_door) && this.close_EV.equals(o.close_EV);
        }

        public int hashCode() {
            return Objects.hash(valve_close_door, close_EV);
        }
    }

    public static class _ProjectionWrite_open_valve_door_close {

        public VALVE_STATE valve_close_door;

        public _ProjectionWrite_open_valve_door_close(VALVE_STATE valve_close_door) {
            this.valve_close_door = valve_close_door;
        }

        public String toString() {
            return "{" + "valve_close_door: " + this.valve_close_door + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_open_valve_door_close)) {
                return false;
            }
            _ProjectionWrite_open_valve_door_close o = (_ProjectionWrite_open_valve_door_close) other;
            return this.valve_close_door.equals(o.valve_close_door);
        }

        public int hashCode() {
            return Objects.hash(valve_close_door);
        }
    }

    public static class _ProjectionRead_close_valve_door_close {

        public VALVE_STATE valve_close_door;
        public BBoolean close_EV;

        public _ProjectionRead_close_valve_door_close(VALVE_STATE valve_close_door, BBoolean close_EV) {
            this.valve_close_door = valve_close_door;
            this.close_EV = close_EV;
        }

        public String toString() {
            return "{" + "valve_close_door: " + this.valve_close_door + "," + "close_EV: " + this.close_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_close_valve_door_close)) {
                return false;
            }
            _ProjectionRead_close_valve_door_close o = (_ProjectionRead_close_valve_door_close) other;
            return this.valve_close_door.equals(o.valve_close_door) && this.close_EV.equals(o.close_EV);
        }

        public int hashCode() {
            return Objects.hash(valve_close_door, close_EV);
        }
    }

    public static class _ProjectionRead__tr_close_valve_door_close {

        public VALVE_STATE valve_close_door;
        public BBoolean close_EV;

        public _ProjectionRead__tr_close_valve_door_close(VALVE_STATE valve_close_door, BBoolean close_EV) {
            this.valve_close_door = valve_close_door;
            this.close_EV = close_EV;
        }

        public String toString() {
            return "{" + "valve_close_door: " + this.valve_close_door + "," + "close_EV: " + this.close_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_close_valve_door_close)) {
                return false;
            }
            _ProjectionRead__tr_close_valve_door_close o = (_ProjectionRead__tr_close_valve_door_close) other;
            return this.valve_close_door.equals(o.valve_close_door) && this.close_EV.equals(o.close_EV);
        }

        public int hashCode() {
            return Objects.hash(valve_close_door, close_EV);
        }
    }

    public static class _ProjectionWrite_close_valve_door_close {

        public VALVE_STATE valve_close_door;

        public _ProjectionWrite_close_valve_door_close(VALVE_STATE valve_close_door) {
            this.valve_close_door = valve_close_door;
        }

        public String toString() {
            return "{" + "valve_close_door: " + this.valve_close_door + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_close_valve_door_close)) {
                return false;
            }
            _ProjectionWrite_close_valve_door_close o = (_ProjectionWrite_close_valve_door_close) other;
            return this.valve_close_door.equals(o.valve_close_door);
        }

        public int hashCode() {
            return Objects.hash(valve_close_door);
        }
    }

    public static class _ProjectionRead_open_valve_retract_gear {

        public VALVE_STATE valve_retract_gear;
        public BBoolean retract_EV;

        public _ProjectionRead_open_valve_retract_gear(VALVE_STATE valve_retract_gear, BBoolean retract_EV) {
            this.valve_retract_gear = valve_retract_gear;
            this.retract_EV = retract_EV;
        }

        public String toString() {
            return "{" + "valve_retract_gear: " + this.valve_retract_gear + "," + "retract_EV: " + this.retract_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_open_valve_retract_gear)) {
                return false;
            }
            _ProjectionRead_open_valve_retract_gear o = (_ProjectionRead_open_valve_retract_gear) other;
            return this.valve_retract_gear.equals(o.valve_retract_gear) && this.retract_EV.equals(o.retract_EV);
        }

        public int hashCode() {
            return Objects.hash(valve_retract_gear, retract_EV);
        }
    }

    public static class _ProjectionRead__tr_open_valve_retract_gear {

        public VALVE_STATE valve_retract_gear;
        public BBoolean retract_EV;

        public _ProjectionRead__tr_open_valve_retract_gear(VALVE_STATE valve_retract_gear, BBoolean retract_EV) {
            this.valve_retract_gear = valve_retract_gear;
            this.retract_EV = retract_EV;
        }

        public String toString() {
            return "{" + "valve_retract_gear: " + this.valve_retract_gear + "," + "retract_EV: " + this.retract_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_open_valve_retract_gear)) {
                return false;
            }
            _ProjectionRead__tr_open_valve_retract_gear o = (_ProjectionRead__tr_open_valve_retract_gear) other;
            return this.valve_retract_gear.equals(o.valve_retract_gear) && this.retract_EV.equals(o.retract_EV);
        }

        public int hashCode() {
            return Objects.hash(valve_retract_gear, retract_EV);
        }
    }

    public static class _ProjectionWrite_open_valve_retract_gear {

        public VALVE_STATE valve_retract_gear;

        public _ProjectionWrite_open_valve_retract_gear(VALVE_STATE valve_retract_gear) {
            this.valve_retract_gear = valve_retract_gear;
        }

        public String toString() {
            return "{" + "valve_retract_gear: " + this.valve_retract_gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_open_valve_retract_gear)) {
                return false;
            }
            _ProjectionWrite_open_valve_retract_gear o = (_ProjectionWrite_open_valve_retract_gear) other;
            return this.valve_retract_gear.equals(o.valve_retract_gear);
        }

        public int hashCode() {
            return Objects.hash(valve_retract_gear);
        }
    }

    public static class _ProjectionRead_close_valve_retract_gear {

        public VALVE_STATE valve_retract_gear;
        public BBoolean retract_EV;

        public _ProjectionRead_close_valve_retract_gear(VALVE_STATE valve_retract_gear, BBoolean retract_EV) {
            this.valve_retract_gear = valve_retract_gear;
            this.retract_EV = retract_EV;
        }

        public String toString() {
            return "{" + "valve_retract_gear: " + this.valve_retract_gear + "," + "retract_EV: " + this.retract_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_close_valve_retract_gear)) {
                return false;
            }
            _ProjectionRead_close_valve_retract_gear o = (_ProjectionRead_close_valve_retract_gear) other;
            return this.valve_retract_gear.equals(o.valve_retract_gear) && this.retract_EV.equals(o.retract_EV);
        }

        public int hashCode() {
            return Objects.hash(valve_retract_gear, retract_EV);
        }
    }

    public static class _ProjectionRead__tr_close_valve_retract_gear {

        public VALVE_STATE valve_retract_gear;
        public BBoolean retract_EV;

        public _ProjectionRead__tr_close_valve_retract_gear(VALVE_STATE valve_retract_gear, BBoolean retract_EV) {
            this.valve_retract_gear = valve_retract_gear;
            this.retract_EV = retract_EV;
        }

        public String toString() {
            return "{" + "valve_retract_gear: " + this.valve_retract_gear + "," + "retract_EV: " + this.retract_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_close_valve_retract_gear)) {
                return false;
            }
            _ProjectionRead__tr_close_valve_retract_gear o = (_ProjectionRead__tr_close_valve_retract_gear) other;
            return this.valve_retract_gear.equals(o.valve_retract_gear) && this.retract_EV.equals(o.retract_EV);
        }

        public int hashCode() {
            return Objects.hash(valve_retract_gear, retract_EV);
        }
    }

    public static class _ProjectionWrite_close_valve_retract_gear {

        public VALVE_STATE valve_retract_gear;

        public _ProjectionWrite_close_valve_retract_gear(VALVE_STATE valve_retract_gear) {
            this.valve_retract_gear = valve_retract_gear;
        }

        public String toString() {
            return "{" + "valve_retract_gear: " + this.valve_retract_gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_close_valve_retract_gear)) {
                return false;
            }
            _ProjectionWrite_close_valve_retract_gear o = (_ProjectionWrite_close_valve_retract_gear) other;
            return this.valve_retract_gear.equals(o.valve_retract_gear);
        }

        public int hashCode() {
            return Objects.hash(valve_retract_gear);
        }
    }

    public static class _ProjectionRead_open_valve_extend_gear {

        public BBoolean extend_EV;
        public VALVE_STATE valve_extend_gear;

        public _ProjectionRead_open_valve_extend_gear(BBoolean extend_EV, VALVE_STATE valve_extend_gear) {
            this.extend_EV = extend_EV;
            this.valve_extend_gear = valve_extend_gear;
        }

        public String toString() {
            return "{" + "extend_EV: " + this.extend_EV + "," + "valve_extend_gear: " + this.valve_extend_gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_open_valve_extend_gear)) {
                return false;
            }
            _ProjectionRead_open_valve_extend_gear o = (_ProjectionRead_open_valve_extend_gear) other;
            return this.extend_EV.equals(o.extend_EV) && this.valve_extend_gear.equals(o.valve_extend_gear);
        }

        public int hashCode() {
            return Objects.hash(extend_EV, valve_extend_gear);
        }
    }

    public static class _ProjectionRead__tr_open_valve_extend_gear {

        public BBoolean extend_EV;
        public VALVE_STATE valve_extend_gear;

        public _ProjectionRead__tr_open_valve_extend_gear(BBoolean extend_EV, VALVE_STATE valve_extend_gear) {
            this.extend_EV = extend_EV;
            this.valve_extend_gear = valve_extend_gear;
        }

        public String toString() {
            return "{" + "extend_EV: " + this.extend_EV + "," + "valve_extend_gear: " + this.valve_extend_gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_open_valve_extend_gear)) {
                return false;
            }
            _ProjectionRead__tr_open_valve_extend_gear o = (_ProjectionRead__tr_open_valve_extend_gear) other;
            return this.extend_EV.equals(o.extend_EV) && this.valve_extend_gear.equals(o.valve_extend_gear);
        }

        public int hashCode() {
            return Objects.hash(extend_EV, valve_extend_gear);
        }
    }

    public static class _ProjectionWrite_open_valve_extend_gear {

        public VALVE_STATE valve_extend_gear;

        public _ProjectionWrite_open_valve_extend_gear(VALVE_STATE valve_extend_gear) {
            this.valve_extend_gear = valve_extend_gear;
        }

        public String toString() {
            return "{" + "valve_extend_gear: " + this.valve_extend_gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_open_valve_extend_gear)) {
                return false;
            }
            _ProjectionWrite_open_valve_extend_gear o = (_ProjectionWrite_open_valve_extend_gear) other;
            return this.valve_extend_gear.equals(o.valve_extend_gear);
        }

        public int hashCode() {
            return Objects.hash(valve_extend_gear);
        }
    }

    public static class _ProjectionRead_close_valve_extend_gear {

        public BBoolean extend_EV;
        public VALVE_STATE valve_extend_gear;

        public _ProjectionRead_close_valve_extend_gear(BBoolean extend_EV, VALVE_STATE valve_extend_gear) {
            this.extend_EV = extend_EV;
            this.valve_extend_gear = valve_extend_gear;
        }

        public String toString() {
            return "{" + "extend_EV: " + this.extend_EV + "," + "valve_extend_gear: " + this.valve_extend_gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_close_valve_extend_gear)) {
                return false;
            }
            _ProjectionRead_close_valve_extend_gear o = (_ProjectionRead_close_valve_extend_gear) other;
            return this.extend_EV.equals(o.extend_EV) && this.valve_extend_gear.equals(o.valve_extend_gear);
        }

        public int hashCode() {
            return Objects.hash(extend_EV, valve_extend_gear);
        }
    }

    public static class _ProjectionRead__tr_close_valve_extend_gear {

        public BBoolean extend_EV;
        public VALVE_STATE valve_extend_gear;

        public _ProjectionRead__tr_close_valve_extend_gear(BBoolean extend_EV, VALVE_STATE valve_extend_gear) {
            this.extend_EV = extend_EV;
            this.valve_extend_gear = valve_extend_gear;
        }

        public String toString() {
            return "{" + "extend_EV: " + this.extend_EV + "," + "valve_extend_gear: " + this.valve_extend_gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_close_valve_extend_gear)) {
                return false;
            }
            _ProjectionRead__tr_close_valve_extend_gear o = (_ProjectionRead__tr_close_valve_extend_gear) other;
            return this.extend_EV.equals(o.extend_EV) && this.valve_extend_gear.equals(o.valve_extend_gear);
        }

        public int hashCode() {
            return Objects.hash(extend_EV, valve_extend_gear);
        }
    }

    public static class _ProjectionWrite_close_valve_extend_gear {

        public VALVE_STATE valve_extend_gear;

        public _ProjectionWrite_close_valve_extend_gear(VALVE_STATE valve_extend_gear) {
            this.valve_extend_gear = valve_extend_gear;
        }

        public String toString() {
            return "{" + "valve_extend_gear: " + this.valve_extend_gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_close_valve_extend_gear)) {
                return false;
            }
            _ProjectionWrite_close_valve_extend_gear o = (_ProjectionWrite_close_valve_extend_gear) other;
            return this.valve_extend_gear.equals(o.valve_extend_gear);
        }

        public int hashCode() {
            return Objects.hash(valve_extend_gear);
        }
    }

    public static class _ProjectionRead_con_stimulate_open_door_valve {

        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public BBoolean open_EV;
        public PLANE_STATE shock_absorber;
        public BBoolean close_EV;
        public BBoolean general_EV;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead_con_stimulate_open_door_valve(HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, BBoolean open_EV, PLANE_STATE shock_absorber, BBoolean close_EV, BBoolean general_EV, BRelation<POSITION, GEAR_STATE> gears) {
            this.handle = handle;
            this.doors = doors;
            this.open_EV = open_EV;
            this.shock_absorber = shock_absorber;
            this.close_EV = close_EV;
            this.general_EV = general_EV;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "open_EV: " + this.open_EV + "," + "shock_absorber: " + this.shock_absorber + "," + "close_EV: " + this.close_EV + "," + "general_EV: " + this.general_EV + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_con_stimulate_open_door_valve)) {
                return false;
            }
            _ProjectionRead_con_stimulate_open_door_valve o = (_ProjectionRead_con_stimulate_open_door_valve) other;
            return this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.open_EV.equals(o.open_EV) && this.shock_absorber.equals(o.shock_absorber) && this.close_EV.equals(o.close_EV) && this.general_EV.equals(o.general_EV) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(handle, doors, open_EV, shock_absorber, close_EV, general_EV, gears);
        }
    }

    public static class _ProjectionRead__tr_con_stimulate_open_door_valve {

        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public BBoolean open_EV;
        public PLANE_STATE shock_absorber;
        public BBoolean close_EV;
        public BBoolean general_EV;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead__tr_con_stimulate_open_door_valve(HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, BBoolean open_EV, PLANE_STATE shock_absorber, BBoolean close_EV, BBoolean general_EV, BRelation<POSITION, GEAR_STATE> gears) {
            this.handle = handle;
            this.doors = doors;
            this.open_EV = open_EV;
            this.shock_absorber = shock_absorber;
            this.close_EV = close_EV;
            this.general_EV = general_EV;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "open_EV: " + this.open_EV + "," + "shock_absorber: " + this.shock_absorber + "," + "close_EV: " + this.close_EV + "," + "general_EV: " + this.general_EV + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_con_stimulate_open_door_valve)) {
                return false;
            }
            _ProjectionRead__tr_con_stimulate_open_door_valve o = (_ProjectionRead__tr_con_stimulate_open_door_valve) other;
            return this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.open_EV.equals(o.open_EV) && this.shock_absorber.equals(o.shock_absorber) && this.close_EV.equals(o.close_EV) && this.general_EV.equals(o.general_EV) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(handle, doors, open_EV, shock_absorber, close_EV, general_EV, gears);
        }
    }

    public static class _ProjectionWrite_con_stimulate_open_door_valve {

        public BBoolean open_EV;

        public _ProjectionWrite_con_stimulate_open_door_valve(BBoolean open_EV) {
            this.open_EV = open_EV;
        }

        public String toString() {
            return "{" + "open_EV: " + this.open_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_con_stimulate_open_door_valve)) {
                return false;
            }
            _ProjectionWrite_con_stimulate_open_door_valve o = (_ProjectionWrite_con_stimulate_open_door_valve) other;
            return this.open_EV.equals(o.open_EV);
        }

        public int hashCode() {
            return Objects.hash(open_EV);
        }
    }

    public static class _ProjectionRead_con_stop_stimulate_open_door_valve {

        public BBoolean extend_EV;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public BBoolean open_EV;
        public PLANE_STATE shock_absorber;
        public BBoolean general_EV;
        public BBoolean retract_EV;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead_con_stop_stimulate_open_door_valve(BBoolean extend_EV, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, BBoolean open_EV, PLANE_STATE shock_absorber, BBoolean general_EV, BBoolean retract_EV, BRelation<POSITION, GEAR_STATE> gears) {
            this.extend_EV = extend_EV;
            this.handle = handle;
            this.doors = doors;
            this.open_EV = open_EV;
            this.shock_absorber = shock_absorber;
            this.general_EV = general_EV;
            this.retract_EV = retract_EV;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "extend_EV: " + this.extend_EV + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "open_EV: " + this.open_EV + "," + "shock_absorber: " + this.shock_absorber + "," + "general_EV: " + this.general_EV + "," + "retract_EV: " + this.retract_EV + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_con_stop_stimulate_open_door_valve)) {
                return false;
            }
            _ProjectionRead_con_stop_stimulate_open_door_valve o = (_ProjectionRead_con_stop_stimulate_open_door_valve) other;
            return this.extend_EV.equals(o.extend_EV) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.open_EV.equals(o.open_EV) && this.shock_absorber.equals(o.shock_absorber) && this.general_EV.equals(o.general_EV) && this.retract_EV.equals(o.retract_EV) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(extend_EV, handle, doors, open_EV, shock_absorber, general_EV, retract_EV, gears);
        }
    }

    public static class _ProjectionRead__tr_con_stop_stimulate_open_door_valve {

        public BBoolean extend_EV;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public BBoolean open_EV;
        public PLANE_STATE shock_absorber;
        public BBoolean general_EV;
        public BBoolean retract_EV;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead__tr_con_stop_stimulate_open_door_valve(BBoolean extend_EV, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, BBoolean open_EV, PLANE_STATE shock_absorber, BBoolean general_EV, BBoolean retract_EV, BRelation<POSITION, GEAR_STATE> gears) {
            this.extend_EV = extend_EV;
            this.handle = handle;
            this.doors = doors;
            this.open_EV = open_EV;
            this.shock_absorber = shock_absorber;
            this.general_EV = general_EV;
            this.retract_EV = retract_EV;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "extend_EV: " + this.extend_EV + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "open_EV: " + this.open_EV + "," + "shock_absorber: " + this.shock_absorber + "," + "general_EV: " + this.general_EV + "," + "retract_EV: " + this.retract_EV + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_con_stop_stimulate_open_door_valve)) {
                return false;
            }
            _ProjectionRead__tr_con_stop_stimulate_open_door_valve o = (_ProjectionRead__tr_con_stop_stimulate_open_door_valve) other;
            return this.extend_EV.equals(o.extend_EV) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.open_EV.equals(o.open_EV) && this.shock_absorber.equals(o.shock_absorber) && this.general_EV.equals(o.general_EV) && this.retract_EV.equals(o.retract_EV) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(extend_EV, handle, doors, open_EV, shock_absorber, general_EV, retract_EV, gears);
        }
    }

    public static class _ProjectionWrite_con_stop_stimulate_open_door_valve {

        public BBoolean open_EV;

        public _ProjectionWrite_con_stop_stimulate_open_door_valve(BBoolean open_EV) {
            this.open_EV = open_EV;
        }

        public String toString() {
            return "{" + "open_EV: " + this.open_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_con_stop_stimulate_open_door_valve)) {
                return false;
            }
            _ProjectionWrite_con_stop_stimulate_open_door_valve o = (_ProjectionWrite_con_stop_stimulate_open_door_valve) other;
            return this.open_EV.equals(o.open_EV);
        }

        public int hashCode() {
            return Objects.hash(open_EV);
        }
    }

    public static class _ProjectionRead_con_stimulate_close_door_valve {

        public BBoolean extend_EV;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public BBoolean open_EV;
        public PLANE_STATE shock_absorber;
        public BBoolean close_EV;
        public BBoolean general_EV;
        public BBoolean retract_EV;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead_con_stimulate_close_door_valve(BBoolean extend_EV, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, BBoolean open_EV, PLANE_STATE shock_absorber, BBoolean close_EV, BBoolean general_EV, BBoolean retract_EV, BRelation<POSITION, GEAR_STATE> gears) {
            this.extend_EV = extend_EV;
            this.handle = handle;
            this.doors = doors;
            this.open_EV = open_EV;
            this.shock_absorber = shock_absorber;
            this.close_EV = close_EV;
            this.general_EV = general_EV;
            this.retract_EV = retract_EV;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "extend_EV: " + this.extend_EV + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "open_EV: " + this.open_EV + "," + "shock_absorber: " + this.shock_absorber + "," + "close_EV: " + this.close_EV + "," + "general_EV: " + this.general_EV + "," + "retract_EV: " + this.retract_EV + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_con_stimulate_close_door_valve)) {
                return false;
            }
            _ProjectionRead_con_stimulate_close_door_valve o = (_ProjectionRead_con_stimulate_close_door_valve) other;
            return this.extend_EV.equals(o.extend_EV) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.open_EV.equals(o.open_EV) && this.shock_absorber.equals(o.shock_absorber) && this.close_EV.equals(o.close_EV) && this.general_EV.equals(o.general_EV) && this.retract_EV.equals(o.retract_EV) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(extend_EV, handle, doors, open_EV, shock_absorber, close_EV, general_EV, retract_EV, gears);
        }
    }

    public static class _ProjectionRead__tr_con_stimulate_close_door_valve {

        public BBoolean extend_EV;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public BBoolean open_EV;
        public PLANE_STATE shock_absorber;
        public BBoolean close_EV;
        public BBoolean general_EV;
        public BBoolean retract_EV;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead__tr_con_stimulate_close_door_valve(BBoolean extend_EV, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, BBoolean open_EV, PLANE_STATE shock_absorber, BBoolean close_EV, BBoolean general_EV, BBoolean retract_EV, BRelation<POSITION, GEAR_STATE> gears) {
            this.extend_EV = extend_EV;
            this.handle = handle;
            this.doors = doors;
            this.open_EV = open_EV;
            this.shock_absorber = shock_absorber;
            this.close_EV = close_EV;
            this.general_EV = general_EV;
            this.retract_EV = retract_EV;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "extend_EV: " + this.extend_EV + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "open_EV: " + this.open_EV + "," + "shock_absorber: " + this.shock_absorber + "," + "close_EV: " + this.close_EV + "," + "general_EV: " + this.general_EV + "," + "retract_EV: " + this.retract_EV + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_con_stimulate_close_door_valve)) {
                return false;
            }
            _ProjectionRead__tr_con_stimulate_close_door_valve o = (_ProjectionRead__tr_con_stimulate_close_door_valve) other;
            return this.extend_EV.equals(o.extend_EV) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.open_EV.equals(o.open_EV) && this.shock_absorber.equals(o.shock_absorber) && this.close_EV.equals(o.close_EV) && this.general_EV.equals(o.general_EV) && this.retract_EV.equals(o.retract_EV) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(extend_EV, handle, doors, open_EV, shock_absorber, close_EV, general_EV, retract_EV, gears);
        }
    }

    public static class _ProjectionWrite_con_stimulate_close_door_valve {

        public BBoolean close_EV;

        public _ProjectionWrite_con_stimulate_close_door_valve(BBoolean close_EV) {
            this.close_EV = close_EV;
        }

        public String toString() {
            return "{" + "close_EV: " + this.close_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_con_stimulate_close_door_valve)) {
                return false;
            }
            _ProjectionWrite_con_stimulate_close_door_valve o = (_ProjectionWrite_con_stimulate_close_door_valve) other;
            return this.close_EV.equals(o.close_EV);
        }

        public int hashCode() {
            return Objects.hash(close_EV);
        }
    }

    public static class _ProjectionRead_con_stop_stimulate_close_door_valve {

        public BRelation<POSITION, DOOR_STATE> doors;
        public PLANE_STATE shock_absorber;
        public HANDLE_STATE handle;
        public BBoolean close_EV;
        public BBoolean general_EV;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead_con_stop_stimulate_close_door_valve(BRelation<POSITION, DOOR_STATE> doors, PLANE_STATE shock_absorber, HANDLE_STATE handle, BBoolean close_EV, BBoolean general_EV, BRelation<POSITION, GEAR_STATE> gears) {
            this.doors = doors;
            this.shock_absorber = shock_absorber;
            this.handle = handle;
            this.close_EV = close_EV;
            this.general_EV = general_EV;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "doors: " + this.doors + "," + "shock_absorber: " + this.shock_absorber + "," + "handle: " + this.handle + "," + "close_EV: " + this.close_EV + "," + "general_EV: " + this.general_EV + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_con_stop_stimulate_close_door_valve)) {
                return false;
            }
            _ProjectionRead_con_stop_stimulate_close_door_valve o = (_ProjectionRead_con_stop_stimulate_close_door_valve) other;
            return this.doors.equals(o.doors) && this.shock_absorber.equals(o.shock_absorber) && this.handle.equals(o.handle) && this.close_EV.equals(o.close_EV) && this.general_EV.equals(o.general_EV) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(doors, shock_absorber, handle, close_EV, general_EV, gears);
        }
    }

    public static class _ProjectionRead__tr_con_stop_stimulate_close_door_valve {

        public BRelation<POSITION, DOOR_STATE> doors;
        public PLANE_STATE shock_absorber;
        public HANDLE_STATE handle;
        public BBoolean close_EV;
        public BBoolean general_EV;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead__tr_con_stop_stimulate_close_door_valve(BRelation<POSITION, DOOR_STATE> doors, PLANE_STATE shock_absorber, HANDLE_STATE handle, BBoolean close_EV, BBoolean general_EV, BRelation<POSITION, GEAR_STATE> gears) {
            this.doors = doors;
            this.shock_absorber = shock_absorber;
            this.handle = handle;
            this.close_EV = close_EV;
            this.general_EV = general_EV;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "doors: " + this.doors + "," + "shock_absorber: " + this.shock_absorber + "," + "handle: " + this.handle + "," + "close_EV: " + this.close_EV + "," + "general_EV: " + this.general_EV + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_con_stop_stimulate_close_door_valve)) {
                return false;
            }
            _ProjectionRead__tr_con_stop_stimulate_close_door_valve o = (_ProjectionRead__tr_con_stop_stimulate_close_door_valve) other;
            return this.doors.equals(o.doors) && this.shock_absorber.equals(o.shock_absorber) && this.handle.equals(o.handle) && this.close_EV.equals(o.close_EV) && this.general_EV.equals(o.general_EV) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(doors, shock_absorber, handle, close_EV, general_EV, gears);
        }
    }

    public static class _ProjectionWrite_con_stop_stimulate_close_door_valve {

        public BBoolean close_EV;

        public _ProjectionWrite_con_stop_stimulate_close_door_valve(BBoolean close_EV) {
            this.close_EV = close_EV;
        }

        public String toString() {
            return "{" + "close_EV: " + this.close_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_con_stop_stimulate_close_door_valve)) {
                return false;
            }
            _ProjectionWrite_con_stop_stimulate_close_door_valve o = (_ProjectionWrite_con_stop_stimulate_close_door_valve) other;
            return this.close_EV.equals(o.close_EV);
        }

        public int hashCode() {
            return Objects.hash(close_EV);
        }
    }

    public static class _ProjectionRead_con_stimulate_retract_gear_valve {

        public BBoolean extend_EV;
        public BRelation<POSITION, DOOR_STATE> doors;
        public BBoolean open_EV;
        public PLANE_STATE shock_absorber;
        public HANDLE_STATE handle;
        public BBoolean general_EV;
        public BBoolean retract_EV;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead_con_stimulate_retract_gear_valve(BBoolean extend_EV, BRelation<POSITION, DOOR_STATE> doors, BBoolean open_EV, PLANE_STATE shock_absorber, HANDLE_STATE handle, BBoolean general_EV, BBoolean retract_EV, BRelation<POSITION, GEAR_STATE> gears) {
            this.extend_EV = extend_EV;
            this.doors = doors;
            this.open_EV = open_EV;
            this.shock_absorber = shock_absorber;
            this.handle = handle;
            this.general_EV = general_EV;
            this.retract_EV = retract_EV;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "extend_EV: " + this.extend_EV + "," + "doors: " + this.doors + "," + "open_EV: " + this.open_EV + "," + "shock_absorber: " + this.shock_absorber + "," + "handle: " + this.handle + "," + "general_EV: " + this.general_EV + "," + "retract_EV: " + this.retract_EV + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_con_stimulate_retract_gear_valve)) {
                return false;
            }
            _ProjectionRead_con_stimulate_retract_gear_valve o = (_ProjectionRead_con_stimulate_retract_gear_valve) other;
            return this.extend_EV.equals(o.extend_EV) && this.doors.equals(o.doors) && this.open_EV.equals(o.open_EV) && this.shock_absorber.equals(o.shock_absorber) && this.handle.equals(o.handle) && this.general_EV.equals(o.general_EV) && this.retract_EV.equals(o.retract_EV) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(extend_EV, doors, open_EV, shock_absorber, handle, general_EV, retract_EV, gears);
        }
    }

    public static class _ProjectionRead__tr_con_stimulate_retract_gear_valve {

        public BBoolean extend_EV;
        public BRelation<POSITION, DOOR_STATE> doors;
        public BBoolean open_EV;
        public PLANE_STATE shock_absorber;
        public HANDLE_STATE handle;
        public BBoolean general_EV;
        public BBoolean retract_EV;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead__tr_con_stimulate_retract_gear_valve(BBoolean extend_EV, BRelation<POSITION, DOOR_STATE> doors, BBoolean open_EV, PLANE_STATE shock_absorber, HANDLE_STATE handle, BBoolean general_EV, BBoolean retract_EV, BRelation<POSITION, GEAR_STATE> gears) {
            this.extend_EV = extend_EV;
            this.doors = doors;
            this.open_EV = open_EV;
            this.shock_absorber = shock_absorber;
            this.handle = handle;
            this.general_EV = general_EV;
            this.retract_EV = retract_EV;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "extend_EV: " + this.extend_EV + "," + "doors: " + this.doors + "," + "open_EV: " + this.open_EV + "," + "shock_absorber: " + this.shock_absorber + "," + "handle: " + this.handle + "," + "general_EV: " + this.general_EV + "," + "retract_EV: " + this.retract_EV + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_con_stimulate_retract_gear_valve)) {
                return false;
            }
            _ProjectionRead__tr_con_stimulate_retract_gear_valve o = (_ProjectionRead__tr_con_stimulate_retract_gear_valve) other;
            return this.extend_EV.equals(o.extend_EV) && this.doors.equals(o.doors) && this.open_EV.equals(o.open_EV) && this.shock_absorber.equals(o.shock_absorber) && this.handle.equals(o.handle) && this.general_EV.equals(o.general_EV) && this.retract_EV.equals(o.retract_EV) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(extend_EV, doors, open_EV, shock_absorber, handle, general_EV, retract_EV, gears);
        }
    }

    public static class _ProjectionWrite_con_stimulate_retract_gear_valve {

        public BBoolean retract_EV;

        public _ProjectionWrite_con_stimulate_retract_gear_valve(BBoolean retract_EV) {
            this.retract_EV = retract_EV;
        }

        public String toString() {
            return "{" + "retract_EV: " + this.retract_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_con_stimulate_retract_gear_valve)) {
                return false;
            }
            _ProjectionWrite_con_stimulate_retract_gear_valve o = (_ProjectionWrite_con_stimulate_retract_gear_valve) other;
            return this.retract_EV.equals(o.retract_EV);
        }

        public int hashCode() {
            return Objects.hash(retract_EV);
        }
    }

    public static class _ProjectionRead_con_stop_stimulate_retract_gear_valve {

        public HANDLE_STATE handle;
        public BBoolean general_EV;
        public BBoolean retract_EV;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead_con_stop_stimulate_retract_gear_valve(HANDLE_STATE handle, BBoolean general_EV, BBoolean retract_EV, BRelation<POSITION, GEAR_STATE> gears) {
            this.handle = handle;
            this.general_EV = general_EV;
            this.retract_EV = retract_EV;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "handle: " + this.handle + "," + "general_EV: " + this.general_EV + "," + "retract_EV: " + this.retract_EV + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_con_stop_stimulate_retract_gear_valve)) {
                return false;
            }
            _ProjectionRead_con_stop_stimulate_retract_gear_valve o = (_ProjectionRead_con_stop_stimulate_retract_gear_valve) other;
            return this.handle.equals(o.handle) && this.general_EV.equals(o.general_EV) && this.retract_EV.equals(o.retract_EV) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(handle, general_EV, retract_EV, gears);
        }
    }

    public static class _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve {

        public HANDLE_STATE handle;
        public BBoolean general_EV;
        public BBoolean retract_EV;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve(HANDLE_STATE handle, BBoolean general_EV, BBoolean retract_EV, BRelation<POSITION, GEAR_STATE> gears) {
            this.handle = handle;
            this.general_EV = general_EV;
            this.retract_EV = retract_EV;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "handle: " + this.handle + "," + "general_EV: " + this.general_EV + "," + "retract_EV: " + this.retract_EV + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve)) {
                return false;
            }
            _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve o = (_ProjectionRead__tr_con_stop_stimulate_retract_gear_valve) other;
            return this.handle.equals(o.handle) && this.general_EV.equals(o.general_EV) && this.retract_EV.equals(o.retract_EV) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(handle, general_EV, retract_EV, gears);
        }
    }

    public static class _ProjectionWrite_con_stop_stimulate_retract_gear_valve {

        public BBoolean retract_EV;

        public _ProjectionWrite_con_stop_stimulate_retract_gear_valve(BBoolean retract_EV) {
            this.retract_EV = retract_EV;
        }

        public String toString() {
            return "{" + "retract_EV: " + this.retract_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_con_stop_stimulate_retract_gear_valve)) {
                return false;
            }
            _ProjectionWrite_con_stop_stimulate_retract_gear_valve o = (_ProjectionWrite_con_stop_stimulate_retract_gear_valve) other;
            return this.retract_EV.equals(o.retract_EV);
        }

        public int hashCode() {
            return Objects.hash(retract_EV);
        }
    }

    public static class _ProjectionRead_con_stimulate_extend_gear_valve {

        public BBoolean extend_EV;
        public BRelation<POSITION, DOOR_STATE> doors;
        public BBoolean open_EV;
        public HANDLE_STATE handle;
        public BBoolean general_EV;
        public BBoolean retract_EV;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead_con_stimulate_extend_gear_valve(BBoolean extend_EV, BRelation<POSITION, DOOR_STATE> doors, BBoolean open_EV, HANDLE_STATE handle, BBoolean general_EV, BBoolean retract_EV, BRelation<POSITION, GEAR_STATE> gears) {
            this.extend_EV = extend_EV;
            this.doors = doors;
            this.open_EV = open_EV;
            this.handle = handle;
            this.general_EV = general_EV;
            this.retract_EV = retract_EV;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "extend_EV: " + this.extend_EV + "," + "doors: " + this.doors + "," + "open_EV: " + this.open_EV + "," + "handle: " + this.handle + "," + "general_EV: " + this.general_EV + "," + "retract_EV: " + this.retract_EV + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_con_stimulate_extend_gear_valve)) {
                return false;
            }
            _ProjectionRead_con_stimulate_extend_gear_valve o = (_ProjectionRead_con_stimulate_extend_gear_valve) other;
            return this.extend_EV.equals(o.extend_EV) && this.doors.equals(o.doors) && this.open_EV.equals(o.open_EV) && this.handle.equals(o.handle) && this.general_EV.equals(o.general_EV) && this.retract_EV.equals(o.retract_EV) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(extend_EV, doors, open_EV, handle, general_EV, retract_EV, gears);
        }
    }

    public static class _ProjectionRead__tr_con_stimulate_extend_gear_valve {

        public BBoolean extend_EV;
        public BRelation<POSITION, DOOR_STATE> doors;
        public BBoolean open_EV;
        public HANDLE_STATE handle;
        public BBoolean general_EV;
        public BBoolean retract_EV;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead__tr_con_stimulate_extend_gear_valve(BBoolean extend_EV, BRelation<POSITION, DOOR_STATE> doors, BBoolean open_EV, HANDLE_STATE handle, BBoolean general_EV, BBoolean retract_EV, BRelation<POSITION, GEAR_STATE> gears) {
            this.extend_EV = extend_EV;
            this.doors = doors;
            this.open_EV = open_EV;
            this.handle = handle;
            this.general_EV = general_EV;
            this.retract_EV = retract_EV;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "extend_EV: " + this.extend_EV + "," + "doors: " + this.doors + "," + "open_EV: " + this.open_EV + "," + "handle: " + this.handle + "," + "general_EV: " + this.general_EV + "," + "retract_EV: " + this.retract_EV + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_con_stimulate_extend_gear_valve)) {
                return false;
            }
            _ProjectionRead__tr_con_stimulate_extend_gear_valve o = (_ProjectionRead__tr_con_stimulate_extend_gear_valve) other;
            return this.extend_EV.equals(o.extend_EV) && this.doors.equals(o.doors) && this.open_EV.equals(o.open_EV) && this.handle.equals(o.handle) && this.general_EV.equals(o.general_EV) && this.retract_EV.equals(o.retract_EV) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(extend_EV, doors, open_EV, handle, general_EV, retract_EV, gears);
        }
    }

    public static class _ProjectionWrite_con_stimulate_extend_gear_valve {

        public BBoolean extend_EV;

        public _ProjectionWrite_con_stimulate_extend_gear_valve(BBoolean extend_EV) {
            this.extend_EV = extend_EV;
        }

        public String toString() {
            return "{" + "extend_EV: " + this.extend_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_con_stimulate_extend_gear_valve)) {
                return false;
            }
            _ProjectionWrite_con_stimulate_extend_gear_valve o = (_ProjectionWrite_con_stimulate_extend_gear_valve) other;
            return this.extend_EV.equals(o.extend_EV);
        }

        public int hashCode() {
            return Objects.hash(extend_EV);
        }
    }

    public static class _ProjectionRead_con_stop_stimulate_extend_gear_valve {

        public BBoolean extend_EV;
        public HANDLE_STATE handle;
        public BBoolean general_EV;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead_con_stop_stimulate_extend_gear_valve(BBoolean extend_EV, HANDLE_STATE handle, BBoolean general_EV, BRelation<POSITION, GEAR_STATE> gears) {
            this.extend_EV = extend_EV;
            this.handle = handle;
            this.general_EV = general_EV;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "extend_EV: " + this.extend_EV + "," + "handle: " + this.handle + "," + "general_EV: " + this.general_EV + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_con_stop_stimulate_extend_gear_valve)) {
                return false;
            }
            _ProjectionRead_con_stop_stimulate_extend_gear_valve o = (_ProjectionRead_con_stop_stimulate_extend_gear_valve) other;
            return this.extend_EV.equals(o.extend_EV) && this.handle.equals(o.handle) && this.general_EV.equals(o.general_EV) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(extend_EV, handle, general_EV, gears);
        }
    }

    public static class _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve {

        public BBoolean extend_EV;
        public HANDLE_STATE handle;
        public BBoolean general_EV;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve(BBoolean extend_EV, HANDLE_STATE handle, BBoolean general_EV, BRelation<POSITION, GEAR_STATE> gears) {
            this.extend_EV = extend_EV;
            this.handle = handle;
            this.general_EV = general_EV;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "extend_EV: " + this.extend_EV + "," + "handle: " + this.handle + "," + "general_EV: " + this.general_EV + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve)) {
                return false;
            }
            _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve o = (_ProjectionRead__tr_con_stop_stimulate_extend_gear_valve) other;
            return this.extend_EV.equals(o.extend_EV) && this.handle.equals(o.handle) && this.general_EV.equals(o.general_EV) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(extend_EV, handle, general_EV, gears);
        }
    }

    public static class _ProjectionWrite_con_stop_stimulate_extend_gear_valve {

        public BBoolean extend_EV;

        public _ProjectionWrite_con_stop_stimulate_extend_gear_valve(BBoolean extend_EV) {
            this.extend_EV = extend_EV;
        }

        public String toString() {
            return "{" + "extend_EV: " + this.extend_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_con_stop_stimulate_extend_gear_valve)) {
                return false;
            }
            _ProjectionWrite_con_stop_stimulate_extend_gear_valve o = (_ProjectionWrite_con_stop_stimulate_extend_gear_valve) other;
            return this.extend_EV.equals(o.extend_EV);
        }

        public int hashCode() {
            return Objects.hash(extend_EV);
        }
    }

    public static class _ProjectionRead_env_start_retracting_first {

        public DOOR_STATE door;
        public HANDLE_STATE handle;
        public VALVE_STATE valve_retract_gear;
        public BRelation<POSITION, DOOR_STATE> doors;
        public VALVE_STATE general_valve;
        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionRead_env_start_retracting_first(DOOR_STATE door, HANDLE_STATE handle, VALVE_STATE valve_retract_gear, BRelation<POSITION, DOOR_STATE> doors, VALVE_STATE general_valve, BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.door = door;
            this.handle = handle;
            this.valve_retract_gear = valve_retract_gear;
            this.doors = doors;
            this.general_valve = general_valve;
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "door: " + this.door + "," + "handle: " + this.handle + "," + "valve_retract_gear: " + this.valve_retract_gear + "," + "doors: " + this.doors + "," + "general_valve: " + this.general_valve + "," + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_env_start_retracting_first)) {
                return false;
            }
            _ProjectionRead_env_start_retracting_first o = (_ProjectionRead_env_start_retracting_first) other;
            return this.door.equals(o.door) && this.handle.equals(o.handle) && this.valve_retract_gear.equals(o.valve_retract_gear) && this.doors.equals(o.doors) && this.general_valve.equals(o.general_valve) && this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(door, handle, valve_retract_gear, doors, general_valve, gears, gear);
        }
    }

    public static class _ProjectionRead__tr_env_start_retracting_first {

        public DOOR_STATE door;
        public HANDLE_STATE handle;
        public VALVE_STATE valve_retract_gear;
        public BRelation<POSITION, DOOR_STATE> doors;
        public VALVE_STATE general_valve;
        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionRead__tr_env_start_retracting_first(DOOR_STATE door, HANDLE_STATE handle, VALVE_STATE valve_retract_gear, BRelation<POSITION, DOOR_STATE> doors, VALVE_STATE general_valve, BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.door = door;
            this.handle = handle;
            this.valve_retract_gear = valve_retract_gear;
            this.doors = doors;
            this.general_valve = general_valve;
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "door: " + this.door + "," + "handle: " + this.handle + "," + "valve_retract_gear: " + this.valve_retract_gear + "," + "doors: " + this.doors + "," + "general_valve: " + this.general_valve + "," + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_env_start_retracting_first)) {
                return false;
            }
            _ProjectionRead__tr_env_start_retracting_first o = (_ProjectionRead__tr_env_start_retracting_first) other;
            return this.door.equals(o.door) && this.handle.equals(o.handle) && this.valve_retract_gear.equals(o.valve_retract_gear) && this.doors.equals(o.doors) && this.general_valve.equals(o.general_valve) && this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(door, handle, valve_retract_gear, doors, general_valve, gears, gear);
        }
    }

    public static class _ProjectionWrite_env_start_retracting_first {

        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionWrite_env_start_retracting_first(BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_env_start_retracting_first)) {
                return false;
            }
            _ProjectionWrite_env_start_retracting_first o = (_ProjectionWrite_env_start_retracting_first) other;
            return this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(gears, gear);
        }
    }

    public static class _ProjectionRead_env_retract_gear_skip {

        public BRelation<POSITION, DOOR_STATE> doors;
        public VALVE_STATE general_valve;
        public HANDLE_STATE handle;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead_env_retract_gear_skip(BRelation<POSITION, DOOR_STATE> doors, VALVE_STATE general_valve, HANDLE_STATE handle, BRelation<POSITION, GEAR_STATE> gears) {
            this.doors = doors;
            this.general_valve = general_valve;
            this.handle = handle;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "doors: " + this.doors + "," + "general_valve: " + this.general_valve + "," + "handle: " + this.handle + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_env_retract_gear_skip)) {
                return false;
            }
            _ProjectionRead_env_retract_gear_skip o = (_ProjectionRead_env_retract_gear_skip) other;
            return this.doors.equals(o.doors) && this.general_valve.equals(o.general_valve) && this.handle.equals(o.handle) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(doors, general_valve, handle, gears);
        }
    }

    public static class _ProjectionRead__tr_env_retract_gear_skip {

        public BRelation<POSITION, DOOR_STATE> doors;
        public VALVE_STATE general_valve;
        public HANDLE_STATE handle;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead__tr_env_retract_gear_skip(BRelation<POSITION, DOOR_STATE> doors, VALVE_STATE general_valve, HANDLE_STATE handle, BRelation<POSITION, GEAR_STATE> gears) {
            this.doors = doors;
            this.general_valve = general_valve;
            this.handle = handle;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "doors: " + this.doors + "," + "general_valve: " + this.general_valve + "," + "handle: " + this.handle + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_env_retract_gear_skip)) {
                return false;
            }
            _ProjectionRead__tr_env_retract_gear_skip o = (_ProjectionRead__tr_env_retract_gear_skip) other;
            return this.doors.equals(o.doors) && this.general_valve.equals(o.general_valve) && this.handle.equals(o.handle) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(doors, general_valve, handle, gears);
        }
    }

    public static class _ProjectionWrite_env_retract_gear_skip {

        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionWrite_env_retract_gear_skip(BRelation<POSITION, GEAR_STATE> gears) {
            this.gears = gears;
        }

        public String toString() {
            return "{" + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_env_retract_gear_skip)) {
                return false;
            }
            _ProjectionWrite_env_retract_gear_skip o = (_ProjectionWrite_env_retract_gear_skip) other;
            return this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(gears);
        }
    }

    public static class _ProjectionRead_env_retract_gear_last {

        public DOOR_STATE door;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public VALVE_STATE general_valve;
        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionRead_env_retract_gear_last(DOOR_STATE door, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, VALVE_STATE general_valve, BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.door = door;
            this.handle = handle;
            this.doors = doors;
            this.general_valve = general_valve;
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "door: " + this.door + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "general_valve: " + this.general_valve + "," + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_env_retract_gear_last)) {
                return false;
            }
            _ProjectionRead_env_retract_gear_last o = (_ProjectionRead_env_retract_gear_last) other;
            return this.door.equals(o.door) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.general_valve.equals(o.general_valve) && this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(door, handle, doors, general_valve, gears, gear);
        }
    }

    public static class _ProjectionRead__tr_env_retract_gear_last {

        public DOOR_STATE door;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public VALVE_STATE general_valve;
        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionRead__tr_env_retract_gear_last(DOOR_STATE door, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, VALVE_STATE general_valve, BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.door = door;
            this.handle = handle;
            this.doors = doors;
            this.general_valve = general_valve;
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "door: " + this.door + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "general_valve: " + this.general_valve + "," + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_env_retract_gear_last)) {
                return false;
            }
            _ProjectionRead__tr_env_retract_gear_last o = (_ProjectionRead__tr_env_retract_gear_last) other;
            return this.door.equals(o.door) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.general_valve.equals(o.general_valve) && this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(door, handle, doors, general_valve, gears, gear);
        }
    }

    public static class _ProjectionWrite_env_retract_gear_last {

        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionWrite_env_retract_gear_last(BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_env_retract_gear_last)) {
                return false;
            }
            _ProjectionWrite_env_retract_gear_last o = (_ProjectionWrite_env_retract_gear_last) other;
            return this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(gears, gear);
        }
    }

    public static class _ProjectionRead_env_start_extending {

        public DOOR_STATE door;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public VALVE_STATE general_valve;
        public VALVE_STATE valve_extend_gear;
        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionRead_env_start_extending(DOOR_STATE door, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, VALVE_STATE general_valve, VALVE_STATE valve_extend_gear, BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.door = door;
            this.handle = handle;
            this.doors = doors;
            this.general_valve = general_valve;
            this.valve_extend_gear = valve_extend_gear;
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "door: " + this.door + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "general_valve: " + this.general_valve + "," + "valve_extend_gear: " + this.valve_extend_gear + "," + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_env_start_extending)) {
                return false;
            }
            _ProjectionRead_env_start_extending o = (_ProjectionRead_env_start_extending) other;
            return this.door.equals(o.door) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.general_valve.equals(o.general_valve) && this.valve_extend_gear.equals(o.valve_extend_gear) && this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(door, handle, doors, general_valve, valve_extend_gear, gears, gear);
        }
    }

    public static class _ProjectionRead__tr_env_start_extending {

        public DOOR_STATE door;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public VALVE_STATE general_valve;
        public VALVE_STATE valve_extend_gear;
        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionRead__tr_env_start_extending(DOOR_STATE door, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, VALVE_STATE general_valve, VALVE_STATE valve_extend_gear, BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.door = door;
            this.handle = handle;
            this.doors = doors;
            this.general_valve = general_valve;
            this.valve_extend_gear = valve_extend_gear;
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "door: " + this.door + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "general_valve: " + this.general_valve + "," + "valve_extend_gear: " + this.valve_extend_gear + "," + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_env_start_extending)) {
                return false;
            }
            _ProjectionRead__tr_env_start_extending o = (_ProjectionRead__tr_env_start_extending) other;
            return this.door.equals(o.door) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.general_valve.equals(o.general_valve) && this.valve_extend_gear.equals(o.valve_extend_gear) && this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(door, handle, doors, general_valve, valve_extend_gear, gears, gear);
        }
    }

    public static class _ProjectionWrite_env_start_extending {

        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionWrite_env_start_extending(BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_env_start_extending)) {
                return false;
            }
            _ProjectionWrite_env_start_extending o = (_ProjectionWrite_env_start_extending) other;
            return this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(gears, gear);
        }
    }

    public static class _ProjectionRead_env_extend_gear_last {

        public DOOR_STATE door;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public VALVE_STATE general_valve;
        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionRead_env_extend_gear_last(DOOR_STATE door, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, VALVE_STATE general_valve, BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.door = door;
            this.handle = handle;
            this.doors = doors;
            this.general_valve = general_valve;
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "door: " + this.door + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "general_valve: " + this.general_valve + "," + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_env_extend_gear_last)) {
                return false;
            }
            _ProjectionRead_env_extend_gear_last o = (_ProjectionRead_env_extend_gear_last) other;
            return this.door.equals(o.door) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.general_valve.equals(o.general_valve) && this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(door, handle, doors, general_valve, gears, gear);
        }
    }

    public static class _ProjectionRead__tr_env_extend_gear_last {

        public DOOR_STATE door;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public VALVE_STATE general_valve;
        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionRead__tr_env_extend_gear_last(DOOR_STATE door, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, VALVE_STATE general_valve, BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.door = door;
            this.handle = handle;
            this.doors = doors;
            this.general_valve = general_valve;
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "door: " + this.door + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "general_valve: " + this.general_valve + "," + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_env_extend_gear_last)) {
                return false;
            }
            _ProjectionRead__tr_env_extend_gear_last o = (_ProjectionRead__tr_env_extend_gear_last) other;
            return this.door.equals(o.door) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.general_valve.equals(o.general_valve) && this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(door, handle, doors, general_valve, gears, gear);
        }
    }

    public static class _ProjectionWrite_env_extend_gear_last {

        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionWrite_env_extend_gear_last(BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_env_extend_gear_last)) {
                return false;
            }
            _ProjectionWrite_env_extend_gear_last o = (_ProjectionWrite_env_extend_gear_last) other;
            return this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(gears, gear);
        }
    }

    public static class _ProjectionRead_env_extend_gear_skip {

        public BRelation<POSITION, DOOR_STATE> doors;
        public VALVE_STATE general_valve;
        public HANDLE_STATE handle;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead_env_extend_gear_skip(BRelation<POSITION, DOOR_STATE> doors, VALVE_STATE general_valve, HANDLE_STATE handle, BRelation<POSITION, GEAR_STATE> gears) {
            this.doors = doors;
            this.general_valve = general_valve;
            this.handle = handle;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "doors: " + this.doors + "," + "general_valve: " + this.general_valve + "," + "handle: " + this.handle + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_env_extend_gear_skip)) {
                return false;
            }
            _ProjectionRead_env_extend_gear_skip o = (_ProjectionRead_env_extend_gear_skip) other;
            return this.doors.equals(o.doors) && this.general_valve.equals(o.general_valve) && this.handle.equals(o.handle) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(doors, general_valve, handle, gears);
        }
    }

    public static class _ProjectionRead__tr_env_extend_gear_skip {

        public BRelation<POSITION, DOOR_STATE> doors;
        public VALVE_STATE general_valve;
        public HANDLE_STATE handle;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead__tr_env_extend_gear_skip(BRelation<POSITION, DOOR_STATE> doors, VALVE_STATE general_valve, HANDLE_STATE handle, BRelation<POSITION, GEAR_STATE> gears) {
            this.doors = doors;
            this.general_valve = general_valve;
            this.handle = handle;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "doors: " + this.doors + "," + "general_valve: " + this.general_valve + "," + "handle: " + this.handle + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_env_extend_gear_skip)) {
                return false;
            }
            _ProjectionRead__tr_env_extend_gear_skip o = (_ProjectionRead__tr_env_extend_gear_skip) other;
            return this.doors.equals(o.doors) && this.general_valve.equals(o.general_valve) && this.handle.equals(o.handle) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(doors, general_valve, handle, gears);
        }
    }

    public static class _ProjectionWrite_env_extend_gear_skip {

        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionWrite_env_extend_gear_skip(BRelation<POSITION, GEAR_STATE> gears) {
            this.gears = gears;
        }

        public String toString() {
            return "{" + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_env_extend_gear_skip)) {
                return false;
            }
            _ProjectionWrite_env_extend_gear_skip o = (_ProjectionWrite_env_extend_gear_skip) other;
            return this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(gears);
        }
    }

    public static class _ProjectionRead_env_start_open_door {

        public VALVE_STATE valve_open_door;
        public DOOR_STATE door;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public VALVE_STATE general_valve;
        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionRead_env_start_open_door(VALVE_STATE valve_open_door, DOOR_STATE door, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, VALVE_STATE general_valve, BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.valve_open_door = valve_open_door;
            this.door = door;
            this.handle = handle;
            this.doors = doors;
            this.general_valve = general_valve;
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "valve_open_door: " + this.valve_open_door + "," + "door: " + this.door + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "general_valve: " + this.general_valve + "," + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_env_start_open_door)) {
                return false;
            }
            _ProjectionRead_env_start_open_door o = (_ProjectionRead_env_start_open_door) other;
            return this.valve_open_door.equals(o.valve_open_door) && this.door.equals(o.door) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.general_valve.equals(o.general_valve) && this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(valve_open_door, door, handle, doors, general_valve, gears, gear);
        }
    }

    public static class _ProjectionRead__tr_env_start_open_door {

        public VALVE_STATE valve_open_door;
        public DOOR_STATE door;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public VALVE_STATE general_valve;
        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionRead__tr_env_start_open_door(VALVE_STATE valve_open_door, DOOR_STATE door, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, VALVE_STATE general_valve, BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.valve_open_door = valve_open_door;
            this.door = door;
            this.handle = handle;
            this.doors = doors;
            this.general_valve = general_valve;
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "valve_open_door: " + this.valve_open_door + "," + "door: " + this.door + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "general_valve: " + this.general_valve + "," + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_env_start_open_door)) {
                return false;
            }
            _ProjectionRead__tr_env_start_open_door o = (_ProjectionRead__tr_env_start_open_door) other;
            return this.valve_open_door.equals(o.valve_open_door) && this.door.equals(o.door) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.general_valve.equals(o.general_valve) && this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(valve_open_door, door, handle, doors, general_valve, gears, gear);
        }
    }

    public static class _ProjectionWrite_env_start_open_door {

        public BRelation<POSITION, DOOR_STATE> doors;
        public DOOR_STATE door;

        public _ProjectionWrite_env_start_open_door(BRelation<POSITION, DOOR_STATE> doors, DOOR_STATE door) {
            this.doors = doors;
            this.door = door;
        }

        public String toString() {
            return "{" + "doors: " + this.doors + "," + "door: " + this.door + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_env_start_open_door)) {
                return false;
            }
            _ProjectionWrite_env_start_open_door o = (_ProjectionWrite_env_start_open_door) other;
            return this.doors.equals(o.doors) && this.door.equals(o.door);
        }

        public int hashCode() {
            return Objects.hash(doors, door);
        }
    }

    public static class _ProjectionRead_env_open_door_last {

        public VALVE_STATE valve_open_door;
        public DOOR_STATE door;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public VALVE_STATE general_valve;
        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionRead_env_open_door_last(VALVE_STATE valve_open_door, DOOR_STATE door, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, VALVE_STATE general_valve, BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.valve_open_door = valve_open_door;
            this.door = door;
            this.handle = handle;
            this.doors = doors;
            this.general_valve = general_valve;
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "valve_open_door: " + this.valve_open_door + "," + "door: " + this.door + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "general_valve: " + this.general_valve + "," + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_env_open_door_last)) {
                return false;
            }
            _ProjectionRead_env_open_door_last o = (_ProjectionRead_env_open_door_last) other;
            return this.valve_open_door.equals(o.valve_open_door) && this.door.equals(o.door) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.general_valve.equals(o.general_valve) && this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(valve_open_door, door, handle, doors, general_valve, gears, gear);
        }
    }

    public static class _ProjectionRead__tr_env_open_door_last {

        public VALVE_STATE valve_open_door;
        public DOOR_STATE door;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public VALVE_STATE general_valve;
        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionRead__tr_env_open_door_last(VALVE_STATE valve_open_door, DOOR_STATE door, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, VALVE_STATE general_valve, BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.valve_open_door = valve_open_door;
            this.door = door;
            this.handle = handle;
            this.doors = doors;
            this.general_valve = general_valve;
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "valve_open_door: " + this.valve_open_door + "," + "door: " + this.door + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "general_valve: " + this.general_valve + "," + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_env_open_door_last)) {
                return false;
            }
            _ProjectionRead__tr_env_open_door_last o = (_ProjectionRead__tr_env_open_door_last) other;
            return this.valve_open_door.equals(o.valve_open_door) && this.door.equals(o.door) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.general_valve.equals(o.general_valve) && this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(valve_open_door, door, handle, doors, general_valve, gears, gear);
        }
    }

    public static class _ProjectionWrite_env_open_door_last {

        public BRelation<POSITION, DOOR_STATE> doors;
        public DOOR_STATE door;

        public _ProjectionWrite_env_open_door_last(BRelation<POSITION, DOOR_STATE> doors, DOOR_STATE door) {
            this.doors = doors;
            this.door = door;
        }

        public String toString() {
            return "{" + "doors: " + this.doors + "," + "door: " + this.door + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_env_open_door_last)) {
                return false;
            }
            _ProjectionWrite_env_open_door_last o = (_ProjectionWrite_env_open_door_last) other;
            return this.doors.equals(o.doors) && this.door.equals(o.door);
        }

        public int hashCode() {
            return Objects.hash(doors, door);
        }
    }

    public static class _ProjectionRead_env_open_door_skip {

        public VALVE_STATE valve_open_door;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public VALVE_STATE general_valve;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead_env_open_door_skip(VALVE_STATE valve_open_door, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, VALVE_STATE general_valve, BRelation<POSITION, GEAR_STATE> gears) {
            this.valve_open_door = valve_open_door;
            this.handle = handle;
            this.doors = doors;
            this.general_valve = general_valve;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "valve_open_door: " + this.valve_open_door + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "general_valve: " + this.general_valve + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_env_open_door_skip)) {
                return false;
            }
            _ProjectionRead_env_open_door_skip o = (_ProjectionRead_env_open_door_skip) other;
            return this.valve_open_door.equals(o.valve_open_door) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.general_valve.equals(o.general_valve) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(valve_open_door, handle, doors, general_valve, gears);
        }
    }

    public static class _ProjectionRead__tr_env_open_door_skip {

        public VALVE_STATE valve_open_door;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public VALVE_STATE general_valve;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead__tr_env_open_door_skip(VALVE_STATE valve_open_door, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, VALVE_STATE general_valve, BRelation<POSITION, GEAR_STATE> gears) {
            this.valve_open_door = valve_open_door;
            this.handle = handle;
            this.doors = doors;
            this.general_valve = general_valve;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "valve_open_door: " + this.valve_open_door + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "general_valve: " + this.general_valve + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_env_open_door_skip)) {
                return false;
            }
            _ProjectionRead__tr_env_open_door_skip o = (_ProjectionRead__tr_env_open_door_skip) other;
            return this.valve_open_door.equals(o.valve_open_door) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.general_valve.equals(o.general_valve) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(valve_open_door, handle, doors, general_valve, gears);
        }
    }

    public static class _ProjectionWrite_env_open_door_skip {

        public BRelation<POSITION, DOOR_STATE> doors;

        public _ProjectionWrite_env_open_door_skip(BRelation<POSITION, DOOR_STATE> doors) {
            this.doors = doors;
        }

        public String toString() {
            return "{" + "doors: " + this.doors + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_env_open_door_skip)) {
                return false;
            }
            _ProjectionWrite_env_open_door_skip o = (_ProjectionWrite_env_open_door_skip) other;
            return this.doors.equals(o.doors);
        }

        public int hashCode() {
            return Objects.hash(doors);
        }
    }

    public static class _ProjectionRead_env_start_close_door {

        public DOOR_STATE door;
        public VALVE_STATE valve_close_door;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public VALVE_STATE general_valve;
        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionRead_env_start_close_door(DOOR_STATE door, VALVE_STATE valve_close_door, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, VALVE_STATE general_valve, BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.door = door;
            this.valve_close_door = valve_close_door;
            this.handle = handle;
            this.doors = doors;
            this.general_valve = general_valve;
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "door: " + this.door + "," + "valve_close_door: " + this.valve_close_door + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "general_valve: " + this.general_valve + "," + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_env_start_close_door)) {
                return false;
            }
            _ProjectionRead_env_start_close_door o = (_ProjectionRead_env_start_close_door) other;
            return this.door.equals(o.door) && this.valve_close_door.equals(o.valve_close_door) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.general_valve.equals(o.general_valve) && this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(door, valve_close_door, handle, doors, general_valve, gears, gear);
        }
    }

    public static class _ProjectionRead__tr_env_start_close_door {

        public DOOR_STATE door;
        public VALVE_STATE valve_close_door;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public VALVE_STATE general_valve;
        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionRead__tr_env_start_close_door(DOOR_STATE door, VALVE_STATE valve_close_door, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, VALVE_STATE general_valve, BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.door = door;
            this.valve_close_door = valve_close_door;
            this.handle = handle;
            this.doors = doors;
            this.general_valve = general_valve;
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "door: " + this.door + "," + "valve_close_door: " + this.valve_close_door + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "general_valve: " + this.general_valve + "," + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_env_start_close_door)) {
                return false;
            }
            _ProjectionRead__tr_env_start_close_door o = (_ProjectionRead__tr_env_start_close_door) other;
            return this.door.equals(o.door) && this.valve_close_door.equals(o.valve_close_door) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.general_valve.equals(o.general_valve) && this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(door, valve_close_door, handle, doors, general_valve, gears, gear);
        }
    }

    public static class _ProjectionWrite_env_start_close_door {

        public BRelation<POSITION, DOOR_STATE> doors;
        public DOOR_STATE door;

        public _ProjectionWrite_env_start_close_door(BRelation<POSITION, DOOR_STATE> doors, DOOR_STATE door) {
            this.doors = doors;
            this.door = door;
        }

        public String toString() {
            return "{" + "doors: " + this.doors + "," + "door: " + this.door + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_env_start_close_door)) {
                return false;
            }
            _ProjectionWrite_env_start_close_door o = (_ProjectionWrite_env_start_close_door) other;
            return this.doors.equals(o.doors) && this.door.equals(o.door);
        }

        public int hashCode() {
            return Objects.hash(doors, door);
        }
    }

    public static class _ProjectionRead_env_close_door {

        public DOOR_STATE door;
        public VALVE_STATE valve_close_door;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public PLANE_STATE shock_absorber;
        public VALVE_STATE general_valve;
        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionRead_env_close_door(DOOR_STATE door, VALVE_STATE valve_close_door, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, PLANE_STATE shock_absorber, VALVE_STATE general_valve, BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.door = door;
            this.valve_close_door = valve_close_door;
            this.handle = handle;
            this.doors = doors;
            this.shock_absorber = shock_absorber;
            this.general_valve = general_valve;
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "door: " + this.door + "," + "valve_close_door: " + this.valve_close_door + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "shock_absorber: " + this.shock_absorber + "," + "general_valve: " + this.general_valve + "," + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_env_close_door)) {
                return false;
            }
            _ProjectionRead_env_close_door o = (_ProjectionRead_env_close_door) other;
            return this.door.equals(o.door) && this.valve_close_door.equals(o.valve_close_door) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.shock_absorber.equals(o.shock_absorber) && this.general_valve.equals(o.general_valve) && this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(door, valve_close_door, handle, doors, shock_absorber, general_valve, gears, gear);
        }
    }

    public static class _ProjectionRead__tr_env_close_door {

        public DOOR_STATE door;
        public VALVE_STATE valve_close_door;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public PLANE_STATE shock_absorber;
        public VALVE_STATE general_valve;
        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionRead__tr_env_close_door(DOOR_STATE door, VALVE_STATE valve_close_door, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, PLANE_STATE shock_absorber, VALVE_STATE general_valve, BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.door = door;
            this.valve_close_door = valve_close_door;
            this.handle = handle;
            this.doors = doors;
            this.shock_absorber = shock_absorber;
            this.general_valve = general_valve;
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "door: " + this.door + "," + "valve_close_door: " + this.valve_close_door + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "shock_absorber: " + this.shock_absorber + "," + "general_valve: " + this.general_valve + "," + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_env_close_door)) {
                return false;
            }
            _ProjectionRead__tr_env_close_door o = (_ProjectionRead__tr_env_close_door) other;
            return this.door.equals(o.door) && this.valve_close_door.equals(o.valve_close_door) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.shock_absorber.equals(o.shock_absorber) && this.general_valve.equals(o.general_valve) && this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(door, valve_close_door, handle, doors, shock_absorber, general_valve, gears, gear);
        }
    }

    public static class _ProjectionWrite_env_close_door {

        public BRelation<POSITION, DOOR_STATE> doors;
        public DOOR_STATE door;

        public _ProjectionWrite_env_close_door(BRelation<POSITION, DOOR_STATE> doors, DOOR_STATE door) {
            this.doors = doors;
            this.door = door;
        }

        public String toString() {
            return "{" + "doors: " + this.doors + "," + "door: " + this.door + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_env_close_door)) {
                return false;
            }
            _ProjectionWrite_env_close_door o = (_ProjectionWrite_env_close_door) other;
            return this.doors.equals(o.doors) && this.door.equals(o.door);
        }

        public int hashCode() {
            return Objects.hash(doors, door);
        }
    }

    public static class _ProjectionRead_env_close_door_skip {

        public VALVE_STATE valve_close_door;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public PLANE_STATE shock_absorber;
        public VALVE_STATE general_valve;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead_env_close_door_skip(VALVE_STATE valve_close_door, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, PLANE_STATE shock_absorber, VALVE_STATE general_valve, BRelation<POSITION, GEAR_STATE> gears) {
            this.valve_close_door = valve_close_door;
            this.handle = handle;
            this.doors = doors;
            this.shock_absorber = shock_absorber;
            this.general_valve = general_valve;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "valve_close_door: " + this.valve_close_door + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "shock_absorber: " + this.shock_absorber + "," + "general_valve: " + this.general_valve + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_env_close_door_skip)) {
                return false;
            }
            _ProjectionRead_env_close_door_skip o = (_ProjectionRead_env_close_door_skip) other;
            return this.valve_close_door.equals(o.valve_close_door) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.shock_absorber.equals(o.shock_absorber) && this.general_valve.equals(o.general_valve) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(valve_close_door, handle, doors, shock_absorber, general_valve, gears);
        }
    }

    public static class _ProjectionRead__tr_env_close_door_skip {

        public VALVE_STATE valve_close_door;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public PLANE_STATE shock_absorber;
        public VALVE_STATE general_valve;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead__tr_env_close_door_skip(VALVE_STATE valve_close_door, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, PLANE_STATE shock_absorber, VALVE_STATE general_valve, BRelation<POSITION, GEAR_STATE> gears) {
            this.valve_close_door = valve_close_door;
            this.handle = handle;
            this.doors = doors;
            this.shock_absorber = shock_absorber;
            this.general_valve = general_valve;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "valve_close_door: " + this.valve_close_door + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "shock_absorber: " + this.shock_absorber + "," + "general_valve: " + this.general_valve + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_env_close_door_skip)) {
                return false;
            }
            _ProjectionRead__tr_env_close_door_skip o = (_ProjectionRead__tr_env_close_door_skip) other;
            return this.valve_close_door.equals(o.valve_close_door) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.shock_absorber.equals(o.shock_absorber) && this.general_valve.equals(o.general_valve) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(valve_close_door, handle, doors, shock_absorber, general_valve, gears);
        }
    }

    public static class _ProjectionWrite_env_close_door_skip {

        public BRelation<POSITION, DOOR_STATE> doors;

        public _ProjectionWrite_env_close_door_skip(BRelation<POSITION, DOOR_STATE> doors) {
            this.doors = doors;
        }

        public String toString() {
            return "{" + "doors: " + this.doors + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_env_close_door_skip)) {
                return false;
            }
            _ProjectionWrite_env_close_door_skip o = (_ProjectionWrite_env_close_door_skip) other;
            return this.doors.equals(o.doors);
        }

        public int hashCode() {
            return Objects.hash(doors);
        }
    }

    public static class _ProjectionRead_toggle_handle_up {

        public HANDLE_STATE handle;

        public _ProjectionRead_toggle_handle_up(HANDLE_STATE handle) {
            this.handle = handle;
        }

        public String toString() {
            return "{" + "handle: " + this.handle + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_toggle_handle_up)) {
                return false;
            }
            _ProjectionRead_toggle_handle_up o = (_ProjectionRead_toggle_handle_up) other;
            return this.handle.equals(o.handle);
        }

        public int hashCode() {
            return Objects.hash(handle);
        }
    }

    public static class _ProjectionRead__tr_toggle_handle_up {

        public HANDLE_STATE handle;

        public _ProjectionRead__tr_toggle_handle_up(HANDLE_STATE handle) {
            this.handle = handle;
        }

        public String toString() {
            return "{" + "handle: " + this.handle + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_toggle_handle_up)) {
                return false;
            }
            _ProjectionRead__tr_toggle_handle_up o = (_ProjectionRead__tr_toggle_handle_up) other;
            return this.handle.equals(o.handle);
        }

        public int hashCode() {
            return Objects.hash(handle);
        }
    }

    public static class _ProjectionWrite_toggle_handle_up {

        public HANDLE_STATE handle;
        public BBoolean handle_move;

        public _ProjectionWrite_toggle_handle_up(HANDLE_STATE handle, BBoolean handle_move) {
            this.handle = handle;
            this.handle_move = handle_move;
        }

        public String toString() {
            return "{" + "handle: " + this.handle + "," + "handle_move: " + this.handle_move + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_toggle_handle_up)) {
                return false;
            }
            _ProjectionWrite_toggle_handle_up o = (_ProjectionWrite_toggle_handle_up) other;
            return this.handle.equals(o.handle) && this.handle_move.equals(o.handle_move);
        }

        public int hashCode() {
            return Objects.hash(handle, handle_move);
        }
    }

    public static class _ProjectionRead_toggle_handle_down {

        public HANDLE_STATE handle;

        public _ProjectionRead_toggle_handle_down(HANDLE_STATE handle) {
            this.handle = handle;
        }

        public String toString() {
            return "{" + "handle: " + this.handle + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_toggle_handle_down)) {
                return false;
            }
            _ProjectionRead_toggle_handle_down o = (_ProjectionRead_toggle_handle_down) other;
            return this.handle.equals(o.handle);
        }

        public int hashCode() {
            return Objects.hash(handle);
        }
    }

    public static class _ProjectionRead__tr_toggle_handle_down {

        public HANDLE_STATE handle;

        public _ProjectionRead__tr_toggle_handle_down(HANDLE_STATE handle) {
            this.handle = handle;
        }

        public String toString() {
            return "{" + "handle: " + this.handle + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_toggle_handle_down)) {
                return false;
            }
            _ProjectionRead__tr_toggle_handle_down o = (_ProjectionRead__tr_toggle_handle_down) other;
            return this.handle.equals(o.handle);
        }

        public int hashCode() {
            return Objects.hash(handle);
        }
    }

    public static class _ProjectionWrite_toggle_handle_down {

        public HANDLE_STATE handle;
        public BBoolean handle_move;

        public _ProjectionWrite_toggle_handle_down(HANDLE_STATE handle, BBoolean handle_move) {
            this.handle = handle;
            this.handle_move = handle_move;
        }

        public String toString() {
            return "{" + "handle: " + this.handle + "," + "handle_move: " + this.handle_move + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_toggle_handle_down)) {
                return false;
            }
            _ProjectionWrite_toggle_handle_down o = (_ProjectionWrite_toggle_handle_down) other;
            return this.handle.equals(o.handle) && this.handle_move.equals(o.handle_move);
        }

        public int hashCode() {
            return Objects.hash(handle, handle_move);
        }
    }

    public static class _ProjectionRead_con_stimulate_general_valve {

        public BBoolean handle_move;
        public BBoolean general_EV;

        public _ProjectionRead_con_stimulate_general_valve(BBoolean handle_move, BBoolean general_EV) {
            this.handle_move = handle_move;
            this.general_EV = general_EV;
        }

        public String toString() {
            return "{" + "handle_move: " + this.handle_move + "," + "general_EV: " + this.general_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_con_stimulate_general_valve)) {
                return false;
            }
            _ProjectionRead_con_stimulate_general_valve o = (_ProjectionRead_con_stimulate_general_valve) other;
            return this.handle_move.equals(o.handle_move) && this.general_EV.equals(o.general_EV);
        }

        public int hashCode() {
            return Objects.hash(handle_move, general_EV);
        }
    }

    public static class _ProjectionRead__tr_con_stimulate_general_valve {

        public BBoolean handle_move;
        public BBoolean general_EV;

        public _ProjectionRead__tr_con_stimulate_general_valve(BBoolean handle_move, BBoolean general_EV) {
            this.handle_move = handle_move;
            this.general_EV = general_EV;
        }

        public String toString() {
            return "{" + "handle_move: " + this.handle_move + "," + "general_EV: " + this.general_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_con_stimulate_general_valve)) {
                return false;
            }
            _ProjectionRead__tr_con_stimulate_general_valve o = (_ProjectionRead__tr_con_stimulate_general_valve) other;
            return this.handle_move.equals(o.handle_move) && this.general_EV.equals(o.general_EV);
        }

        public int hashCode() {
            return Objects.hash(handle_move, general_EV);
        }
    }

    public static class _ProjectionWrite_con_stimulate_general_valve {

        public BBoolean general_EV;

        public _ProjectionWrite_con_stimulate_general_valve(BBoolean general_EV) {
            this.general_EV = general_EV;
        }

        public String toString() {
            return "{" + "general_EV: " + this.general_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_con_stimulate_general_valve)) {
                return false;
            }
            _ProjectionWrite_con_stimulate_general_valve o = (_ProjectionWrite_con_stimulate_general_valve) other;
            return this.general_EV.equals(o.general_EV);
        }

        public int hashCode() {
            return Objects.hash(general_EV);
        }
    }

    public static class _ProjectionRead_con_stop_stimulate_general_valve {

        public BBoolean extend_EV;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public BBoolean open_EV;
        public BBoolean close_EV;
        public BBoolean general_EV;
        public BBoolean retract_EV;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead_con_stop_stimulate_general_valve(BBoolean extend_EV, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, BBoolean open_EV, BBoolean close_EV, BBoolean general_EV, BBoolean retract_EV, BRelation<POSITION, GEAR_STATE> gears) {
            this.extend_EV = extend_EV;
            this.handle = handle;
            this.doors = doors;
            this.open_EV = open_EV;
            this.close_EV = close_EV;
            this.general_EV = general_EV;
            this.retract_EV = retract_EV;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "extend_EV: " + this.extend_EV + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "open_EV: " + this.open_EV + "," + "close_EV: " + this.close_EV + "," + "general_EV: " + this.general_EV + "," + "retract_EV: " + this.retract_EV + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_con_stop_stimulate_general_valve)) {
                return false;
            }
            _ProjectionRead_con_stop_stimulate_general_valve o = (_ProjectionRead_con_stop_stimulate_general_valve) other;
            return this.extend_EV.equals(o.extend_EV) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.open_EV.equals(o.open_EV) && this.close_EV.equals(o.close_EV) && this.general_EV.equals(o.general_EV) && this.retract_EV.equals(o.retract_EV) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(extend_EV, handle, doors, open_EV, close_EV, general_EV, retract_EV, gears);
        }
    }

    public static class _ProjectionRead__tr_con_stop_stimulate_general_valve {

        public BBoolean extend_EV;
        public HANDLE_STATE handle;
        public BRelation<POSITION, DOOR_STATE> doors;
        public BBoolean open_EV;
        public BBoolean close_EV;
        public BBoolean general_EV;
        public BBoolean retract_EV;
        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead__tr_con_stop_stimulate_general_valve(BBoolean extend_EV, HANDLE_STATE handle, BRelation<POSITION, DOOR_STATE> doors, BBoolean open_EV, BBoolean close_EV, BBoolean general_EV, BBoolean retract_EV, BRelation<POSITION, GEAR_STATE> gears) {
            this.extend_EV = extend_EV;
            this.handle = handle;
            this.doors = doors;
            this.open_EV = open_EV;
            this.close_EV = close_EV;
            this.general_EV = general_EV;
            this.retract_EV = retract_EV;
            this.gears = gears;
        }

        public String toString() {
            return "{" + "extend_EV: " + this.extend_EV + "," + "handle: " + this.handle + "," + "doors: " + this.doors + "," + "open_EV: " + this.open_EV + "," + "close_EV: " + this.close_EV + "," + "general_EV: " + this.general_EV + "," + "retract_EV: " + this.retract_EV + "," + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_con_stop_stimulate_general_valve)) {
                return false;
            }
            _ProjectionRead__tr_con_stop_stimulate_general_valve o = (_ProjectionRead__tr_con_stop_stimulate_general_valve) other;
            return this.extend_EV.equals(o.extend_EV) && this.handle.equals(o.handle) && this.doors.equals(o.doors) && this.open_EV.equals(o.open_EV) && this.close_EV.equals(o.close_EV) && this.general_EV.equals(o.general_EV) && this.retract_EV.equals(o.retract_EV) && this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(extend_EV, handle, doors, open_EV, close_EV, general_EV, retract_EV, gears);
        }
    }

    public static class _ProjectionWrite_con_stop_stimulate_general_valve {

        public BBoolean handle_move;
        public BBoolean general_EV;

        public _ProjectionWrite_con_stop_stimulate_general_valve(BBoolean handle_move, BBoolean general_EV) {
            this.handle_move = handle_move;
            this.general_EV = general_EV;
        }

        public String toString() {
            return "{" + "handle_move: " + this.handle_move + "," + "general_EV: " + this.general_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_con_stop_stimulate_general_valve)) {
                return false;
            }
            _ProjectionWrite_con_stop_stimulate_general_valve o = (_ProjectionWrite_con_stop_stimulate_general_valve) other;
            return this.handle_move.equals(o.handle_move) && this.general_EV.equals(o.general_EV);
        }

        public int hashCode() {
            return Objects.hash(handle_move, general_EV);
        }
    }

    public static class _ProjectionRead_evn_open_general_valve {

        public VALVE_STATE general_valve;
        public SWITCH_STATE analogical_switch;
        public BBoolean general_EV;

        public _ProjectionRead_evn_open_general_valve(VALVE_STATE general_valve, SWITCH_STATE analogical_switch, BBoolean general_EV) {
            this.general_valve = general_valve;
            this.analogical_switch = analogical_switch;
            this.general_EV = general_EV;
        }

        public String toString() {
            return "{" + "general_valve: " + this.general_valve + "," + "analogical_switch: " + this.analogical_switch + "," + "general_EV: " + this.general_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_evn_open_general_valve)) {
                return false;
            }
            _ProjectionRead_evn_open_general_valve o = (_ProjectionRead_evn_open_general_valve) other;
            return this.general_valve.equals(o.general_valve) && this.analogical_switch.equals(o.analogical_switch) && this.general_EV.equals(o.general_EV);
        }

        public int hashCode() {
            return Objects.hash(general_valve, analogical_switch, general_EV);
        }
    }

    public static class _ProjectionRead__tr_evn_open_general_valve {

        public VALVE_STATE general_valve;
        public SWITCH_STATE analogical_switch;
        public BBoolean general_EV;

        public _ProjectionRead__tr_evn_open_general_valve(VALVE_STATE general_valve, SWITCH_STATE analogical_switch, BBoolean general_EV) {
            this.general_valve = general_valve;
            this.analogical_switch = analogical_switch;
            this.general_EV = general_EV;
        }

        public String toString() {
            return "{" + "general_valve: " + this.general_valve + "," + "analogical_switch: " + this.analogical_switch + "," + "general_EV: " + this.general_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_evn_open_general_valve)) {
                return false;
            }
            _ProjectionRead__tr_evn_open_general_valve o = (_ProjectionRead__tr_evn_open_general_valve) other;
            return this.general_valve.equals(o.general_valve) && this.analogical_switch.equals(o.analogical_switch) && this.general_EV.equals(o.general_EV);
        }

        public int hashCode() {
            return Objects.hash(general_valve, analogical_switch, general_EV);
        }
    }

    public static class _ProjectionWrite_evn_open_general_valve {

        public VALVE_STATE general_valve;

        public _ProjectionWrite_evn_open_general_valve(VALVE_STATE general_valve) {
            this.general_valve = general_valve;
        }

        public String toString() {
            return "{" + "general_valve: " + this.general_valve + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_evn_open_general_valve)) {
                return false;
            }
            _ProjectionWrite_evn_open_general_valve o = (_ProjectionWrite_evn_open_general_valve) other;
            return this.general_valve.equals(o.general_valve);
        }

        public int hashCode() {
            return Objects.hash(general_valve);
        }
    }

    public static class _ProjectionRead_evn_close_general_valve {

        public VALVE_STATE general_valve;
        public SWITCH_STATE analogical_switch;
        public BBoolean general_EV;

        public _ProjectionRead_evn_close_general_valve(VALVE_STATE general_valve, SWITCH_STATE analogical_switch, BBoolean general_EV) {
            this.general_valve = general_valve;
            this.analogical_switch = analogical_switch;
            this.general_EV = general_EV;
        }

        public String toString() {
            return "{" + "general_valve: " + this.general_valve + "," + "analogical_switch: " + this.analogical_switch + "," + "general_EV: " + this.general_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_evn_close_general_valve)) {
                return false;
            }
            _ProjectionRead_evn_close_general_valve o = (_ProjectionRead_evn_close_general_valve) other;
            return this.general_valve.equals(o.general_valve) && this.analogical_switch.equals(o.analogical_switch) && this.general_EV.equals(o.general_EV);
        }

        public int hashCode() {
            return Objects.hash(general_valve, analogical_switch, general_EV);
        }
    }

    public static class _ProjectionRead__tr_evn_close_general_valve {

        public VALVE_STATE general_valve;
        public SWITCH_STATE analogical_switch;
        public BBoolean general_EV;

        public _ProjectionRead__tr_evn_close_general_valve(VALVE_STATE general_valve, SWITCH_STATE analogical_switch, BBoolean general_EV) {
            this.general_valve = general_valve;
            this.analogical_switch = analogical_switch;
            this.general_EV = general_EV;
        }

        public String toString() {
            return "{" + "general_valve: " + this.general_valve + "," + "analogical_switch: " + this.analogical_switch + "," + "general_EV: " + this.general_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_evn_close_general_valve)) {
                return false;
            }
            _ProjectionRead__tr_evn_close_general_valve o = (_ProjectionRead__tr_evn_close_general_valve) other;
            return this.general_valve.equals(o.general_valve) && this.analogical_switch.equals(o.analogical_switch) && this.general_EV.equals(o.general_EV);
        }

        public int hashCode() {
            return Objects.hash(general_valve, analogical_switch, general_EV);
        }
    }

    public static class _ProjectionWrite_evn_close_general_valve {

        public VALVE_STATE general_valve;

        public _ProjectionWrite_evn_close_general_valve(VALVE_STATE general_valve) {
            this.general_valve = general_valve;
        }

        public String toString() {
            return "{" + "general_valve: " + this.general_valve + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_evn_close_general_valve)) {
                return false;
            }
            _ProjectionWrite_evn_close_general_valve o = (_ProjectionWrite_evn_close_general_valve) other;
            return this.general_valve.equals(o.general_valve);
        }

        public int hashCode() {
            return Objects.hash(general_valve);
        }
    }

    public static class _ProjectionRead_env_close_analogical_switch {

        public SWITCH_STATE analogical_switch;
        public BBoolean handle_move;

        public _ProjectionRead_env_close_analogical_switch(SWITCH_STATE analogical_switch, BBoolean handle_move) {
            this.analogical_switch = analogical_switch;
            this.handle_move = handle_move;
        }

        public String toString() {
            return "{" + "analogical_switch: " + this.analogical_switch + "," + "handle_move: " + this.handle_move + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_env_close_analogical_switch)) {
                return false;
            }
            _ProjectionRead_env_close_analogical_switch o = (_ProjectionRead_env_close_analogical_switch) other;
            return this.analogical_switch.equals(o.analogical_switch) && this.handle_move.equals(o.handle_move);
        }

        public int hashCode() {
            return Objects.hash(analogical_switch, handle_move);
        }
    }

    public static class _ProjectionRead__tr_env_close_analogical_switch {

        public SWITCH_STATE analogical_switch;
        public BBoolean handle_move;

        public _ProjectionRead__tr_env_close_analogical_switch(SWITCH_STATE analogical_switch, BBoolean handle_move) {
            this.analogical_switch = analogical_switch;
            this.handle_move = handle_move;
        }

        public String toString() {
            return "{" + "analogical_switch: " + this.analogical_switch + "," + "handle_move: " + this.handle_move + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_env_close_analogical_switch)) {
                return false;
            }
            _ProjectionRead__tr_env_close_analogical_switch o = (_ProjectionRead__tr_env_close_analogical_switch) other;
            return this.analogical_switch.equals(o.analogical_switch) && this.handle_move.equals(o.handle_move);
        }

        public int hashCode() {
            return Objects.hash(analogical_switch, handle_move);
        }
    }

    public static class _ProjectionWrite_env_close_analogical_switch {

        public SWITCH_STATE analogical_switch;

        public _ProjectionWrite_env_close_analogical_switch(SWITCH_STATE analogical_switch) {
            this.analogical_switch = analogical_switch;
        }

        public String toString() {
            return "{" + "analogical_switch: " + this.analogical_switch + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_env_close_analogical_switch)) {
                return false;
            }
            _ProjectionWrite_env_close_analogical_switch o = (_ProjectionWrite_env_close_analogical_switch) other;
            return this.analogical_switch.equals(o.analogical_switch);
        }

        public int hashCode() {
            return Objects.hash(analogical_switch);
        }
    }

    public static class _ProjectionRead_env_open_analogical_switch {

        public SWITCH_STATE analogical_switch;

        public _ProjectionRead_env_open_analogical_switch(SWITCH_STATE analogical_switch) {
            this.analogical_switch = analogical_switch;
        }

        public String toString() {
            return "{" + "analogical_switch: " + this.analogical_switch + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_env_open_analogical_switch)) {
                return false;
            }
            _ProjectionRead_env_open_analogical_switch o = (_ProjectionRead_env_open_analogical_switch) other;
            return this.analogical_switch.equals(o.analogical_switch);
        }

        public int hashCode() {
            return Objects.hash(analogical_switch);
        }
    }

    public static class _ProjectionRead__tr_env_open_analogical_switch {

        public SWITCH_STATE analogical_switch;

        public _ProjectionRead__tr_env_open_analogical_switch(SWITCH_STATE analogical_switch) {
            this.analogical_switch = analogical_switch;
        }

        public String toString() {
            return "{" + "analogical_switch: " + this.analogical_switch + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_env_open_analogical_switch)) {
                return false;
            }
            _ProjectionRead__tr_env_open_analogical_switch o = (_ProjectionRead__tr_env_open_analogical_switch) other;
            return this.analogical_switch.equals(o.analogical_switch);
        }

        public int hashCode() {
            return Objects.hash(analogical_switch);
        }
    }

    public static class _ProjectionWrite_env_open_analogical_switch {

        public SWITCH_STATE analogical_switch;

        public _ProjectionWrite_env_open_analogical_switch(SWITCH_STATE analogical_switch) {
            this.analogical_switch = analogical_switch;
        }

        public String toString() {
            return "{" + "analogical_switch: " + this.analogical_switch + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_env_open_analogical_switch)) {
                return false;
            }
            _ProjectionWrite_env_open_analogical_switch o = (_ProjectionWrite_env_open_analogical_switch) other;
            return this.analogical_switch.equals(o.analogical_switch);
        }

        public int hashCode() {
            return Objects.hash(analogical_switch);
        }
    }

    public static class _ProjectionRead__check_inv_1 {

        public SWITCH_STATE analogical_switch;

        public _ProjectionRead__check_inv_1(SWITCH_STATE analogical_switch) {
            this.analogical_switch = analogical_switch;
        }

        public String toString() {
            return "{" + "analogical_switch: " + this.analogical_switch + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_1)) {
                return false;
            }
            _ProjectionRead__check_inv_1 o = (_ProjectionRead__check_inv_1) other;
            return this.analogical_switch.equals(o.analogical_switch);
        }

        public int hashCode() {
            return Objects.hash(analogical_switch);
        }
    }

    public static class _ProjectionRead__check_inv_2 {

        public BBoolean general_EV;

        public _ProjectionRead__check_inv_2(BBoolean general_EV) {
            this.general_EV = general_EV;
        }

        public String toString() {
            return "{" + "general_EV: " + this.general_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_2)) {
                return false;
            }
            _ProjectionRead__check_inv_2 o = (_ProjectionRead__check_inv_2) other;
            return this.general_EV.equals(o.general_EV);
        }

        public int hashCode() {
            return Objects.hash(general_EV);
        }
    }

    public static class _ProjectionRead__check_inv_3 {

        public VALVE_STATE general_valve;

        public _ProjectionRead__check_inv_3(VALVE_STATE general_valve) {
            this.general_valve = general_valve;
        }

        public String toString() {
            return "{" + "general_valve: " + this.general_valve + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_3)) {
                return false;
            }
            _ProjectionRead__check_inv_3 o = (_ProjectionRead__check_inv_3) other;
            return this.general_valve.equals(o.general_valve);
        }

        public int hashCode() {
            return Objects.hash(general_valve);
        }
    }

    public static class _ProjectionRead__check_inv_4 {

        public BBoolean handle_move;

        public _ProjectionRead__check_inv_4(BBoolean handle_move) {
            this.handle_move = handle_move;
        }

        public String toString() {
            return "{" + "handle_move: " + this.handle_move + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_4)) {
                return false;
            }
            _ProjectionRead__check_inv_4 o = (_ProjectionRead__check_inv_4) other;
            return this.handle_move.equals(o.handle_move);
        }

        public int hashCode() {
            return Objects.hash(handle_move);
        }
    }

    public static class _ProjectionRead__check_inv_5 {

        public BBoolean close_EV;

        public _ProjectionRead__check_inv_5(BBoolean close_EV) {
            this.close_EV = close_EV;
        }

        public String toString() {
            return "{" + "close_EV: " + this.close_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_5)) {
                return false;
            }
            _ProjectionRead__check_inv_5 o = (_ProjectionRead__check_inv_5) other;
            return this.close_EV.equals(o.close_EV);
        }

        public int hashCode() {
            return Objects.hash(close_EV);
        }
    }

    public static class _ProjectionRead__check_inv_6 {

        public BBoolean extend_EV;

        public _ProjectionRead__check_inv_6(BBoolean extend_EV) {
            this.extend_EV = extend_EV;
        }

        public String toString() {
            return "{" + "extend_EV: " + this.extend_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_6)) {
                return false;
            }
            _ProjectionRead__check_inv_6 o = (_ProjectionRead__check_inv_6) other;
            return this.extend_EV.equals(o.extend_EV);
        }

        public int hashCode() {
            return Objects.hash(extend_EV);
        }
    }

    public static class _ProjectionRead__check_inv_7 {

        public BBoolean open_EV;

        public _ProjectionRead__check_inv_7(BBoolean open_EV) {
            this.open_EV = open_EV;
        }

        public String toString() {
            return "{" + "open_EV: " + this.open_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_7)) {
                return false;
            }
            _ProjectionRead__check_inv_7 o = (_ProjectionRead__check_inv_7) other;
            return this.open_EV.equals(o.open_EV);
        }

        public int hashCode() {
            return Objects.hash(open_EV);
        }
    }

    public static class _ProjectionRead__check_inv_8 {

        public BBoolean retract_EV;

        public _ProjectionRead__check_inv_8(BBoolean retract_EV) {
            this.retract_EV = retract_EV;
        }

        public String toString() {
            return "{" + "retract_EV: " + this.retract_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_8)) {
                return false;
            }
            _ProjectionRead__check_inv_8 o = (_ProjectionRead__check_inv_8) other;
            return this.retract_EV.equals(o.retract_EV);
        }

        public int hashCode() {
            return Objects.hash(retract_EV);
        }
    }

    public static class _ProjectionRead__check_inv_9 {

        public PLANE_STATE shock_absorber;

        public _ProjectionRead__check_inv_9(PLANE_STATE shock_absorber) {
            this.shock_absorber = shock_absorber;
        }

        public String toString() {
            return "{" + "shock_absorber: " + this.shock_absorber + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_9)) {
                return false;
            }
            _ProjectionRead__check_inv_9 o = (_ProjectionRead__check_inv_9) other;
            return this.shock_absorber.equals(o.shock_absorber);
        }

        public int hashCode() {
            return Objects.hash(shock_absorber);
        }
    }

    public static class _ProjectionRead__check_inv_10 {

        public VALVE_STATE valve_close_door;

        public _ProjectionRead__check_inv_10(VALVE_STATE valve_close_door) {
            this.valve_close_door = valve_close_door;
        }

        public String toString() {
            return "{" + "valve_close_door: " + this.valve_close_door + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_10)) {
                return false;
            }
            _ProjectionRead__check_inv_10 o = (_ProjectionRead__check_inv_10) other;
            return this.valve_close_door.equals(o.valve_close_door);
        }

        public int hashCode() {
            return Objects.hash(valve_close_door);
        }
    }

    public static class _ProjectionRead__check_inv_11 {

        public VALVE_STATE valve_extend_gear;

        public _ProjectionRead__check_inv_11(VALVE_STATE valve_extend_gear) {
            this.valve_extend_gear = valve_extend_gear;
        }

        public String toString() {
            return "{" + "valve_extend_gear: " + this.valve_extend_gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_11)) {
                return false;
            }
            _ProjectionRead__check_inv_11 o = (_ProjectionRead__check_inv_11) other;
            return this.valve_extend_gear.equals(o.valve_extend_gear);
        }

        public int hashCode() {
            return Objects.hash(valve_extend_gear);
        }
    }

    public static class _ProjectionRead__check_inv_12 {

        public VALVE_STATE valve_open_door;

        public _ProjectionRead__check_inv_12(VALVE_STATE valve_open_door) {
            this.valve_open_door = valve_open_door;
        }

        public String toString() {
            return "{" + "valve_open_door: " + this.valve_open_door + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_12)) {
                return false;
            }
            _ProjectionRead__check_inv_12 o = (_ProjectionRead__check_inv_12) other;
            return this.valve_open_door.equals(o.valve_open_door);
        }

        public int hashCode() {
            return Objects.hash(valve_open_door);
        }
    }

    public static class _ProjectionRead__check_inv_13 {

        public VALVE_STATE valve_retract_gear;

        public _ProjectionRead__check_inv_13(VALVE_STATE valve_retract_gear) {
            this.valve_retract_gear = valve_retract_gear;
        }

        public String toString() {
            return "{" + "valve_retract_gear: " + this.valve_retract_gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_13)) {
                return false;
            }
            _ProjectionRead__check_inv_13 o = (_ProjectionRead__check_inv_13) other;
            return this.valve_retract_gear.equals(o.valve_retract_gear);
        }

        public int hashCode() {
            return Objects.hash(valve_retract_gear);
        }
    }

    public static class _ProjectionRead__check_inv_14 {

        public HANDLE_STATE handle;

        public _ProjectionRead__check_inv_14(HANDLE_STATE handle) {
            this.handle = handle;
        }

        public String toString() {
            return "{" + "handle: " + this.handle + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_14)) {
                return false;
            }
            _ProjectionRead__check_inv_14 o = (_ProjectionRead__check_inv_14) other;
            return this.handle.equals(o.handle);
        }

        public int hashCode() {
            return Objects.hash(handle);
        }
    }

    public static class _ProjectionRead__check_inv_15 {

        public DOOR_STATE door;

        public _ProjectionRead__check_inv_15(DOOR_STATE door) {
            this.door = door;
        }

        public String toString() {
            return "{" + "door: " + this.door + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_15)) {
                return false;
            }
            _ProjectionRead__check_inv_15 o = (_ProjectionRead__check_inv_15) other;
            return this.door.equals(o.door);
        }

        public int hashCode() {
            return Objects.hash(door);
        }
    }

    public static class _ProjectionRead__check_inv_16 {

        public GEAR_STATE gear;

        public _ProjectionRead__check_inv_16(GEAR_STATE gear) {
            this.gear = gear;
        }

        public String toString() {
            return "{" + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_16)) {
                return false;
            }
            _ProjectionRead__check_inv_16 o = (_ProjectionRead__check_inv_16) other;
            return this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(gear);
        }
    }

    public static class _ProjectionRead__check_inv_17 {

        public BBoolean extend_EV;
        public BBoolean open_EV;
        public BBoolean close_EV;
        public BBoolean general_EV;
        public BBoolean retract_EV;

        public _ProjectionRead__check_inv_17(BBoolean extend_EV, BBoolean open_EV, BBoolean close_EV, BBoolean general_EV, BBoolean retract_EV) {
            this.extend_EV = extend_EV;
            this.open_EV = open_EV;
            this.close_EV = close_EV;
            this.general_EV = general_EV;
            this.retract_EV = retract_EV;
        }

        public String toString() {
            return "{" + "extend_EV: " + this.extend_EV + "," + "open_EV: " + this.open_EV + "," + "close_EV: " + this.close_EV + "," + "general_EV: " + this.general_EV + "," + "retract_EV: " + this.retract_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_17)) {
                return false;
            }
            _ProjectionRead__check_inv_17 o = (_ProjectionRead__check_inv_17) other;
            return this.extend_EV.equals(o.extend_EV) && this.open_EV.equals(o.open_EV) && this.close_EV.equals(o.close_EV) && this.general_EV.equals(o.general_EV) && this.retract_EV.equals(o.retract_EV);
        }

        public int hashCode() {
            return Objects.hash(extend_EV, open_EV, close_EV, general_EV, retract_EV);
        }
    }

    public static class _ProjectionRead__check_inv_18 {

        public BBoolean open_EV;
        public BBoolean close_EV;

        public _ProjectionRead__check_inv_18(BBoolean open_EV, BBoolean close_EV) {
            this.open_EV = open_EV;
            this.close_EV = close_EV;
        }

        public String toString() {
            return "{" + "open_EV: " + this.open_EV + "," + "close_EV: " + this.close_EV + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_18)) {
                return false;
            }
            _ProjectionRead__check_inv_18 o = (_ProjectionRead__check_inv_18) other;
            return this.open_EV.equals(o.open_EV) && this.close_EV.equals(o.close_EV);
        }

        public int hashCode() {
            return Objects.hash(open_EV, close_EV);
        }
    }

    public static class _ProjectionRead__check_inv_19 {

        public BRelation<POSITION, GEAR_STATE> gears;

        public _ProjectionRead__check_inv_19(BRelation<POSITION, GEAR_STATE> gears) {
            this.gears = gears;
        }

        public String toString() {
            return "{" + "gears: " + this.gears + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_19)) {
                return false;
            }
            _ProjectionRead__check_inv_19 o = (_ProjectionRead__check_inv_19) other;
            return this.gears.equals(o.gears);
        }

        public int hashCode() {
            return Objects.hash(gears);
        }
    }

    public static class _ProjectionRead__check_inv_20 {

        public BRelation<POSITION, DOOR_STATE> doors;

        public _ProjectionRead__check_inv_20(BRelation<POSITION, DOOR_STATE> doors) {
            this.doors = doors;
        }

        public String toString() {
            return "{" + "doors: " + this.doors + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_20)) {
                return false;
            }
            _ProjectionRead__check_inv_20 o = (_ProjectionRead__check_inv_20) other;
            return this.doors.equals(o.doors);
        }

        public int hashCode() {
            return Objects.hash(doors);
        }
    }

    public static class _ProjectionRead__check_inv_21 {

        public BRelation<POSITION, DOOR_STATE> doors;
        public DOOR_STATE door;

        public _ProjectionRead__check_inv_21(BRelation<POSITION, DOOR_STATE> doors, DOOR_STATE door) {
            this.doors = doors;
            this.door = door;
        }

        public String toString() {
            return "{" + "doors: " + this.doors + "," + "door: " + this.door + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_21)) {
                return false;
            }
            _ProjectionRead__check_inv_21 o = (_ProjectionRead__check_inv_21) other;
            return this.doors.equals(o.doors) && this.door.equals(o.door);
        }

        public int hashCode() {
            return Objects.hash(doors, door);
        }
    }

    public static class _ProjectionRead__check_inv_22 {

        public BRelation<POSITION, DOOR_STATE> doors;
        public DOOR_STATE door;

        public _ProjectionRead__check_inv_22(BRelation<POSITION, DOOR_STATE> doors, DOOR_STATE door) {
            this.doors = doors;
            this.door = door;
        }

        public String toString() {
            return "{" + "doors: " + this.doors + "," + "door: " + this.door + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_22)) {
                return false;
            }
            _ProjectionRead__check_inv_22 o = (_ProjectionRead__check_inv_22) other;
            return this.doors.equals(o.doors) && this.door.equals(o.door);
        }

        public int hashCode() {
            return Objects.hash(doors, door);
        }
    }

    public static class _ProjectionRead__check_inv_23 {

        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionRead__check_inv_23(BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_23)) {
                return false;
            }
            _ProjectionRead__check_inv_23 o = (_ProjectionRead__check_inv_23) other;
            return this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(gears, gear);
        }
    }

    public static class _ProjectionRead__check_inv_24 {

        public BRelation<POSITION, GEAR_STATE> gears;
        public GEAR_STATE gear;

        public _ProjectionRead__check_inv_24(BRelation<POSITION, GEAR_STATE> gears, GEAR_STATE gear) {
            this.gears = gears;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "gears: " + this.gears + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_24)) {
                return false;
            }
            _ProjectionRead__check_inv_24 o = (_ProjectionRead__check_inv_24) other;
            return this.gears.equals(o.gears) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(gears, gear);
        }
    }

    public static class _ProjectionRead__check_inv_25 {

        public DOOR_STATE door;
        public GEAR_STATE gear;

        public _ProjectionRead__check_inv_25(DOOR_STATE door, GEAR_STATE gear) {
            this.door = door;
            this.gear = gear;
        }

        public String toString() {
            return "{" + "door: " + this.door + "," + "gear: " + this.gear + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_25)) {
                return false;
            }
            _ProjectionRead__check_inv_25 o = (_ProjectionRead__check_inv_25) other;
            return this.door.equals(o.door) && this.gear.equals(o.gear);
        }

        public int hashCode() {
            return Objects.hash(door, gear);
        }
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

    public LandingGear_R6(LandingGear_R6 copy) {
        this.analogical_switch = copy.analogical_switch;
        this.general_EV = copy.general_EV;
        this.general_valve = copy.general_valve;
        this.handle_move = copy.handle_move;
        this.close_EV = copy.close_EV;
        this.extend_EV = copy.extend_EV;
        this.open_EV = copy.open_EV;
        this.retract_EV = copy.retract_EV;
        this.shock_absorber = copy.shock_absorber;
        this.valve_close_door = copy.valve_close_door;
        this.valve_extend_gear = copy.valve_extend_gear;
        this.valve_open_door = copy.valve_open_door;
        this.valve_retract_gear = copy.valve_retract_gear;
        this.doors = copy.doors;
        this.gears = copy.gears;
        this.handle = copy.handle;
        this.door = copy.door;
        this.gear = copy.gear;
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

    public LandingGear_R6 _copy() {
        return new LandingGear_R6(this);
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

    public _ProjectionRead_close_valve_door_close _projected_state_for_close_valve_door_close() {
        return new _ProjectionRead_close_valve_door_close(valve_close_door,close_EV);
    }

    public _ProjectionRead_close_valve_retract_gear _projected_state_for_close_valve_retract_gear() {
        return new _ProjectionRead_close_valve_retract_gear(valve_retract_gear,retract_EV);
    }

    public _ProjectionRead_con_stimulate_open_door_valve _projected_state_for_con_stimulate_open_door_valve() {
        return new _ProjectionRead_con_stimulate_open_door_valve(handle,doors,open_EV,shock_absorber,close_EV,general_EV,gears);
    }

    public _ProjectionRead_env_close_door _projected_state_for_env_close_door() {
        return new _ProjectionRead_env_close_door(door,valve_close_door,handle,doors,shock_absorber,general_valve,gears,gear);
    }

    public _ProjectionRead_env_start_close_door _projected_state_for_env_start_close_door() {
        return new _ProjectionRead_env_start_close_door(door,valve_close_door,handle,doors,general_valve,gears,gear);
    }

    public _ProjectionRead_toggle_handle_up _projected_state_for_toggle_handle_up() {
        return new _ProjectionRead_toggle_handle_up(handle);
    }

    public _ProjectionRead_toggle_handle_down _projected_state_for_toggle_handle_down() {
        return new _ProjectionRead_toggle_handle_down(handle);
    }

    public _ProjectionRead_open_valve_door_open _projected_state_for_open_valve_door_open() {
        return new _ProjectionRead_open_valve_door_open(valve_open_door,open_EV);
    }

    public _ProjectionRead_env_retract_gear_last _projected_state_for_env_retract_gear_last() {
        return new _ProjectionRead_env_retract_gear_last(door,handle,doors,general_valve,gears,gear);
    }

    public _ProjectionRead_env_open_door_last _projected_state_for_env_open_door_last() {
        return new _ProjectionRead_env_open_door_last(valve_open_door,door,handle,doors,general_valve,gears,gear);
    }

    public _ProjectionRead_con_stop_stimulate_retract_gear_valve _projected_state_for_con_stop_stimulate_retract_gear_valve() {
        return new _ProjectionRead_con_stop_stimulate_retract_gear_valve(handle,general_EV,retract_EV,gears);
    }

    public _ProjectionRead_env_close_door_skip _projected_state_for_env_close_door_skip() {
        return new _ProjectionRead_env_close_door_skip(valve_close_door,handle,doors,shock_absorber,general_valve,gears);
    }

    public _ProjectionRead_con_stop_stimulate_close_door_valve _projected_state_for_con_stop_stimulate_close_door_valve() {
        return new _ProjectionRead_con_stop_stimulate_close_door_valve(doors,shock_absorber,handle,close_EV,general_EV,gears);
    }

    public _ProjectionRead_env_open_analogical_switch _projected_state_for_env_open_analogical_switch() {
        return new _ProjectionRead_env_open_analogical_switch(analogical_switch);
    }

    public _ProjectionRead_con_stop_stimulate_general_valve _projected_state_for_con_stop_stimulate_general_valve() {
        return new _ProjectionRead_con_stop_stimulate_general_valve(extend_EV,handle,doors,open_EV,close_EV,general_EV,retract_EV,gears);
    }

    public _ProjectionRead_env_extend_gear_last _projected_state_for_env_extend_gear_last() {
        return new _ProjectionRead_env_extend_gear_last(door,handle,doors,general_valve,gears,gear);
    }

    public _ProjectionRead_evn_open_general_valve _projected_state_for_evn_open_general_valve() {
        return new _ProjectionRead_evn_open_general_valve(general_valve,analogical_switch,general_EV);
    }

    public _ProjectionRead_land_plane _projected_state_for_land_plane() {
        return new _ProjectionRead_land_plane(shock_absorber);
    }

    public _ProjectionRead_con_stimulate_retract_gear_valve _projected_state_for_con_stimulate_retract_gear_valve() {
        return new _ProjectionRead_con_stimulate_retract_gear_valve(extend_EV,doors,open_EV,shock_absorber,handle,general_EV,retract_EV,gears);
    }

    public _ProjectionRead_con_stimulate_general_valve _projected_state_for_con_stimulate_general_valve() {
        return new _ProjectionRead_con_stimulate_general_valve(handle_move,general_EV);
    }

    public _ProjectionRead_env_start_retracting_first _projected_state_for_env_start_retracting_first() {
        return new _ProjectionRead_env_start_retracting_first(door,handle,valve_retract_gear,doors,general_valve,gears,gear);
    }

    public _ProjectionRead_env_retract_gear_skip _projected_state_for_env_retract_gear_skip() {
        return new _ProjectionRead_env_retract_gear_skip(doors,general_valve,handle,gears);
    }

    public _ProjectionRead_open_valve_extend_gear _projected_state_for_open_valve_extend_gear() {
        return new _ProjectionRead_open_valve_extend_gear(extend_EV,valve_extend_gear);
    }

    public _ProjectionRead_begin_flying _projected_state_for_begin_flying() {
        return new _ProjectionRead_begin_flying(shock_absorber);
    }

    public _ProjectionRead_open_valve_retract_gear _projected_state_for_open_valve_retract_gear() {
        return new _ProjectionRead_open_valve_retract_gear(valve_retract_gear,retract_EV);
    }

    public _ProjectionRead_env_close_analogical_switch _projected_state_for_env_close_analogical_switch() {
        return new _ProjectionRead_env_close_analogical_switch(analogical_switch,handle_move);
    }

    public _ProjectionRead_env_start_extending _projected_state_for_env_start_extending() {
        return new _ProjectionRead_env_start_extending(door,handle,doors,general_valve,valve_extend_gear,gears,gear);
    }

    public _ProjectionRead_open_valve_door_close _projected_state_for_open_valve_door_close() {
        return new _ProjectionRead_open_valve_door_close(valve_close_door,close_EV);
    }

    public _ProjectionRead_con_stop_stimulate_open_door_valve _projected_state_for_con_stop_stimulate_open_door_valve() {
        return new _ProjectionRead_con_stop_stimulate_open_door_valve(extend_EV,handle,doors,open_EV,shock_absorber,general_EV,retract_EV,gears);
    }

    public _ProjectionRead_con_stop_stimulate_extend_gear_valve _projected_state_for_con_stop_stimulate_extend_gear_valve() {
        return new _ProjectionRead_con_stop_stimulate_extend_gear_valve(extend_EV,handle,general_EV,gears);
    }

    public _ProjectionRead_evn_close_general_valve _projected_state_for_evn_close_general_valve() {
        return new _ProjectionRead_evn_close_general_valve(general_valve,analogical_switch,general_EV);
    }

    public _ProjectionRead_close_valve_extend_gear _projected_state_for_close_valve_extend_gear() {
        return new _ProjectionRead_close_valve_extend_gear(extend_EV,valve_extend_gear);
    }

    public _ProjectionRead_con_stimulate_extend_gear_valve _projected_state_for_con_stimulate_extend_gear_valve() {
        return new _ProjectionRead_con_stimulate_extend_gear_valve(extend_EV,doors,open_EV,handle,general_EV,retract_EV,gears);
    }

    public _ProjectionRead_close_valve_door_open _projected_state_for_close_valve_door_open() {
        return new _ProjectionRead_close_valve_door_open(valve_open_door,open_EV);
    }

    public _ProjectionRead_con_stimulate_close_door_valve _projected_state_for_con_stimulate_close_door_valve() {
        return new _ProjectionRead_con_stimulate_close_door_valve(extend_EV,handle,doors,open_EV,shock_absorber,close_EV,general_EV,retract_EV,gears);
    }

    public _ProjectionRead_env_extend_gear_skip _projected_state_for_env_extend_gear_skip() {
        return new _ProjectionRead_env_extend_gear_skip(doors,general_valve,handle,gears);
    }

    public _ProjectionRead_env_open_door_skip _projected_state_for_env_open_door_skip() {
        return new _ProjectionRead_env_open_door_skip(valve_open_door,handle,doors,general_valve,gears);
    }

    public _ProjectionRead_env_start_open_door _projected_state_for_env_start_open_door() {
        return new _ProjectionRead_env_start_open_door(valve_open_door,door,handle,doors,general_valve,gears,gear);
    }

    public _ProjectionRead__tr_env_retract_gear_last _projected_state_for__tr_env_retract_gear_last() {
        return new _ProjectionRead__tr_env_retract_gear_last(door,handle,doors,general_valve,gears,gear);
    }

    public _ProjectionRead__tr_open_valve_door_open _projected_state_for__tr_open_valve_door_open() {
        return new _ProjectionRead__tr_open_valve_door_open(valve_open_door,open_EV);
    }

    public _ProjectionRead__tr_env_open_analogical_switch _projected_state_for__tr_env_open_analogical_switch() {
        return new _ProjectionRead__tr_env_open_analogical_switch(analogical_switch);
    }

    public _ProjectionRead__tr_con_stimulate_extend_gear_valve _projected_state_for__tr_con_stimulate_extend_gear_valve() {
        return new _ProjectionRead__tr_con_stimulate_extend_gear_valve(extend_EV,doors,open_EV,handle,general_EV,retract_EV,gears);
    }

    public _ProjectionRead__tr_env_close_door_skip _projected_state_for__tr_env_close_door_skip() {
        return new _ProjectionRead__tr_env_close_door_skip(valve_close_door,handle,doors,shock_absorber,general_valve,gears);
    }

    public _ProjectionRead__tr_con_stop_stimulate_open_door_valve _projected_state_for__tr_con_stop_stimulate_open_door_valve() {
        return new _ProjectionRead__tr_con_stop_stimulate_open_door_valve(extend_EV,handle,doors,open_EV,shock_absorber,general_EV,retract_EV,gears);
    }

    public _ProjectionRead__tr_con_stimulate_close_door_valve _projected_state_for__tr_con_stimulate_close_door_valve() {
        return new _ProjectionRead__tr_con_stimulate_close_door_valve(extend_EV,handle,doors,open_EV,shock_absorber,close_EV,general_EV,retract_EV,gears);
    }

    public _ProjectionRead__tr_env_close_analogical_switch _projected_state_for__tr_env_close_analogical_switch() {
        return new _ProjectionRead__tr_env_close_analogical_switch(analogical_switch,handle_move);
    }

    public _ProjectionRead__tr_evn_close_general_valve _projected_state_for__tr_evn_close_general_valve() {
        return new _ProjectionRead__tr_evn_close_general_valve(general_valve,analogical_switch,general_EV);
    }

    public _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve _projected_state_for__tr_con_stop_stimulate_retract_gear_valve() {
        return new _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve(handle,general_EV,retract_EV,gears);
    }

    public _ProjectionRead__tr_land_plane _projected_state_for__tr_land_plane() {
        return new _ProjectionRead__tr_land_plane(shock_absorber);
    }

    public _ProjectionRead__tr_open_valve_door_close _projected_state_for__tr_open_valve_door_close() {
        return new _ProjectionRead__tr_open_valve_door_close(valve_close_door,close_EV);
    }

    public _ProjectionRead__tr_con_stop_stimulate_general_valve _projected_state_for__tr_con_stop_stimulate_general_valve() {
        return new _ProjectionRead__tr_con_stop_stimulate_general_valve(extend_EV,handle,doors,open_EV,close_EV,general_EV,retract_EV,gears);
    }

    public _ProjectionRead__tr_con_stimulate_open_door_valve _projected_state_for__tr_con_stimulate_open_door_valve() {
        return new _ProjectionRead__tr_con_stimulate_open_door_valve(handle,doors,open_EV,shock_absorber,close_EV,general_EV,gears);
    }

    public _ProjectionRead__tr_env_start_extending _projected_state_for__tr_env_start_extending() {
        return new _ProjectionRead__tr_env_start_extending(door,handle,doors,general_valve,valve_extend_gear,gears,gear);
    }

    public _ProjectionRead__tr_env_extend_gear_last _projected_state_for__tr_env_extend_gear_last() {
        return new _ProjectionRead__tr_env_extend_gear_last(door,handle,doors,general_valve,gears,gear);
    }

    public _ProjectionRead__tr_env_open_door_skip _projected_state_for__tr_env_open_door_skip() {
        return new _ProjectionRead__tr_env_open_door_skip(valve_open_door,handle,doors,general_valve,gears);
    }

    public _ProjectionRead__tr_close_valve_retract_gear _projected_state_for__tr_close_valve_retract_gear() {
        return new _ProjectionRead__tr_close_valve_retract_gear(valve_retract_gear,retract_EV);
    }

    public _ProjectionRead__tr_close_valve_extend_gear _projected_state_for__tr_close_valve_extend_gear() {
        return new _ProjectionRead__tr_close_valve_extend_gear(extend_EV,valve_extend_gear);
    }

    public _ProjectionRead__tr_con_stimulate_general_valve _projected_state_for__tr_con_stimulate_general_valve() {
        return new _ProjectionRead__tr_con_stimulate_general_valve(handle_move,general_EV);
    }

    public _ProjectionRead__tr_open_valve_extend_gear _projected_state_for__tr_open_valve_extend_gear() {
        return new _ProjectionRead__tr_open_valve_extend_gear(extend_EV,valve_extend_gear);
    }

    public _ProjectionRead__tr_con_stimulate_retract_gear_valve _projected_state_for__tr_con_stimulate_retract_gear_valve() {
        return new _ProjectionRead__tr_con_stimulate_retract_gear_valve(extend_EV,doors,open_EV,shock_absorber,handle,general_EV,retract_EV,gears);
    }

    public _ProjectionRead__tr_evn_open_general_valve _projected_state_for__tr_evn_open_general_valve() {
        return new _ProjectionRead__tr_evn_open_general_valve(general_valve,analogical_switch,general_EV);
    }

    public _ProjectionRead__tr_env_retract_gear_skip _projected_state_for__tr_env_retract_gear_skip() {
        return new _ProjectionRead__tr_env_retract_gear_skip(doors,general_valve,handle,gears);
    }

    public _ProjectionRead__tr_env_start_open_door _projected_state_for__tr_env_start_open_door() {
        return new _ProjectionRead__tr_env_start_open_door(valve_open_door,door,handle,doors,general_valve,gears,gear);
    }

    public _ProjectionRead__tr_env_close_door _projected_state_for__tr_env_close_door() {
        return new _ProjectionRead__tr_env_close_door(door,valve_close_door,handle,doors,shock_absorber,general_valve,gears,gear);
    }

    public _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve _projected_state_for__tr_con_stop_stimulate_extend_gear_valve() {
        return new _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve(extend_EV,handle,general_EV,gears);
    }

    public _ProjectionRead__tr_close_valve_door_open _projected_state_for__tr_close_valve_door_open() {
        return new _ProjectionRead__tr_close_valve_door_open(valve_open_door,open_EV);
    }

    public _ProjectionRead__tr_env_start_retracting_first _projected_state_for__tr_env_start_retracting_first() {
        return new _ProjectionRead__tr_env_start_retracting_first(door,handle,valve_retract_gear,doors,general_valve,gears,gear);
    }

    public _ProjectionRead__tr_env_extend_gear_skip _projected_state_for__tr_env_extend_gear_skip() {
        return new _ProjectionRead__tr_env_extend_gear_skip(doors,general_valve,handle,gears);
    }

    public _ProjectionRead__tr_toggle_handle_down _projected_state_for__tr_toggle_handle_down() {
        return new _ProjectionRead__tr_toggle_handle_down(handle);
    }

    public _ProjectionRead__tr_begin_flying _projected_state_for__tr_begin_flying() {
        return new _ProjectionRead__tr_begin_flying(shock_absorber);
    }

    public _ProjectionRead__tr_open_valve_retract_gear _projected_state_for__tr_open_valve_retract_gear() {
        return new _ProjectionRead__tr_open_valve_retract_gear(valve_retract_gear,retract_EV);
    }

    public _ProjectionRead__tr_env_open_door_last _projected_state_for__tr_env_open_door_last() {
        return new _ProjectionRead__tr_env_open_door_last(valve_open_door,door,handle,doors,general_valve,gears,gear);
    }

    public _ProjectionRead__tr_toggle_handle_up _projected_state_for__tr_toggle_handle_up() {
        return new _ProjectionRead__tr_toggle_handle_up(handle);
    }

    public _ProjectionRead__tr_env_start_close_door _projected_state_for__tr_env_start_close_door() {
        return new _ProjectionRead__tr_env_start_close_door(door,valve_close_door,handle,doors,general_valve,gears,gear);
    }

    public _ProjectionRead__tr_con_stop_stimulate_close_door_valve _projected_state_for__tr_con_stop_stimulate_close_door_valve() {
        return new _ProjectionRead__tr_con_stop_stimulate_close_door_valve(doors,shock_absorber,handle,close_EV,general_EV,gears);
    }

    public _ProjectionRead__tr_close_valve_door_close _projected_state_for__tr_close_valve_door_close() {
        return new _ProjectionRead__tr_close_valve_door_close(valve_close_door,close_EV);
    }

    public _ProjectionRead__check_inv_18 _projected_state_for__check_inv_18() {
        return new _ProjectionRead__check_inv_18(open_EV,close_EV);
    }

    public _ProjectionRead__check_inv_17 _projected_state_for__check_inv_17() {
        return new _ProjectionRead__check_inv_17(extend_EV,open_EV,close_EV,general_EV,retract_EV);
    }

    public _ProjectionRead__check_inv_16 _projected_state_for__check_inv_16() {
        return new _ProjectionRead__check_inv_16(gear);
    }

    public _ProjectionRead__check_inv_15 _projected_state_for__check_inv_15() {
        return new _ProjectionRead__check_inv_15(door);
    }

    public _ProjectionRead__check_inv_19 _projected_state_for__check_inv_19() {
        return new _ProjectionRead__check_inv_19(gears);
    }

    public _ProjectionRead__check_inv_10 _projected_state_for__check_inv_10() {
        return new _ProjectionRead__check_inv_10(valve_close_door);
    }

    public _ProjectionRead__check_inv_14 _projected_state_for__check_inv_14() {
        return new _ProjectionRead__check_inv_14(handle);
    }

    public _ProjectionRead__check_inv_13 _projected_state_for__check_inv_13() {
        return new _ProjectionRead__check_inv_13(valve_retract_gear);
    }

    public _ProjectionRead__check_inv_12 _projected_state_for__check_inv_12() {
        return new _ProjectionRead__check_inv_12(valve_open_door);
    }

    public _ProjectionRead__check_inv_11 _projected_state_for__check_inv_11() {
        return new _ProjectionRead__check_inv_11(valve_extend_gear);
    }

    public _ProjectionRead__check_inv_6 _projected_state_for__check_inv_6() {
        return new _ProjectionRead__check_inv_6(extend_EV);
    }

    public _ProjectionRead__check_inv_21 _projected_state_for__check_inv_21() {
        return new _ProjectionRead__check_inv_21(doors,door);
    }

    public _ProjectionRead__check_inv_7 _projected_state_for__check_inv_7() {
        return new _ProjectionRead__check_inv_7(open_EV);
    }

    public _ProjectionRead__check_inv_20 _projected_state_for__check_inv_20() {
        return new _ProjectionRead__check_inv_20(doors);
    }

    public _ProjectionRead__check_inv_4 _projected_state_for__check_inv_4() {
        return new _ProjectionRead__check_inv_4(handle_move);
    }

    public _ProjectionRead__check_inv_5 _projected_state_for__check_inv_5() {
        return new _ProjectionRead__check_inv_5(close_EV);
    }

    public _ProjectionRead__check_inv_25 _projected_state_for__check_inv_25() {
        return new _ProjectionRead__check_inv_25(door,gear);
    }

    public _ProjectionRead__check_inv_24 _projected_state_for__check_inv_24() {
        return new _ProjectionRead__check_inv_24(gears,gear);
    }

    public _ProjectionRead__check_inv_8 _projected_state_for__check_inv_8() {
        return new _ProjectionRead__check_inv_8(retract_EV);
    }

    public _ProjectionRead__check_inv_23 _projected_state_for__check_inv_23() {
        return new _ProjectionRead__check_inv_23(gears,gear);
    }

    public _ProjectionRead__check_inv_9 _projected_state_for__check_inv_9() {
        return new _ProjectionRead__check_inv_9(shock_absorber);
    }

    public _ProjectionRead__check_inv_22 _projected_state_for__check_inv_22() {
        return new _ProjectionRead__check_inv_22(doors,door);
    }

    public _ProjectionRead__check_inv_2 _projected_state_for__check_inv_2() {
        return new _ProjectionRead__check_inv_2(general_EV);
    }

    public _ProjectionRead__check_inv_3 _projected_state_for__check_inv_3() {
        return new _ProjectionRead__check_inv_3(general_valve);
    }

    public _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() {
        return new _ProjectionRead__check_inv_1(analogical_switch);
    }

    public _ProjectionWrite_close_valve_door_close _update_for_close_valve_door_close() {
        return new _ProjectionWrite_close_valve_door_close(valve_close_door);
    }

    public _ProjectionWrite_close_valve_retract_gear _update_for_close_valve_retract_gear() {
        return new _ProjectionWrite_close_valve_retract_gear(valve_retract_gear);
    }

    public _ProjectionWrite_con_stimulate_open_door_valve _update_for_con_stimulate_open_door_valve() {
        return new _ProjectionWrite_con_stimulate_open_door_valve(open_EV);
    }

    public _ProjectionWrite_env_close_door _update_for_env_close_door() {
        return new _ProjectionWrite_env_close_door(doors,door);
    }

    public _ProjectionWrite_env_start_close_door _update_for_env_start_close_door() {
        return new _ProjectionWrite_env_start_close_door(doors,door);
    }

    public _ProjectionWrite_toggle_handle_up _update_for_toggle_handle_up() {
        return new _ProjectionWrite_toggle_handle_up(handle,handle_move);
    }

    public _ProjectionWrite_toggle_handle_down _update_for_toggle_handle_down() {
        return new _ProjectionWrite_toggle_handle_down(handle,handle_move);
    }

    public _ProjectionWrite_open_valve_door_open _update_for_open_valve_door_open() {
        return new _ProjectionWrite_open_valve_door_open(valve_open_door);
    }

    public _ProjectionWrite_env_retract_gear_last _update_for_env_retract_gear_last() {
        return new _ProjectionWrite_env_retract_gear_last(gears,gear);
    }

    public _ProjectionWrite_env_open_door_last _update_for_env_open_door_last() {
        return new _ProjectionWrite_env_open_door_last(doors,door);
    }

    public _ProjectionWrite_con_stop_stimulate_retract_gear_valve _update_for_con_stop_stimulate_retract_gear_valve() {
        return new _ProjectionWrite_con_stop_stimulate_retract_gear_valve(retract_EV);
    }

    public _ProjectionWrite_env_close_door_skip _update_for_env_close_door_skip() {
        return new _ProjectionWrite_env_close_door_skip(doors);
    }

    public _ProjectionWrite_con_stop_stimulate_close_door_valve _update_for_con_stop_stimulate_close_door_valve() {
        return new _ProjectionWrite_con_stop_stimulate_close_door_valve(close_EV);
    }

    public _ProjectionWrite_env_open_analogical_switch _update_for_env_open_analogical_switch() {
        return new _ProjectionWrite_env_open_analogical_switch(analogical_switch);
    }

    public _ProjectionWrite_con_stop_stimulate_general_valve _update_for_con_stop_stimulate_general_valve() {
        return new _ProjectionWrite_con_stop_stimulate_general_valve(handle_move,general_EV);
    }

    public _ProjectionWrite_env_extend_gear_last _update_for_env_extend_gear_last() {
        return new _ProjectionWrite_env_extend_gear_last(gears,gear);
    }

    public _ProjectionWrite_evn_open_general_valve _update_for_evn_open_general_valve() {
        return new _ProjectionWrite_evn_open_general_valve(general_valve);
    }

    public _ProjectionWrite_land_plane _update_for_land_plane() {
        return new _ProjectionWrite_land_plane(shock_absorber);
    }

    public _ProjectionWrite_con_stimulate_retract_gear_valve _update_for_con_stimulate_retract_gear_valve() {
        return new _ProjectionWrite_con_stimulate_retract_gear_valve(retract_EV);
    }

    public _ProjectionWrite_con_stimulate_general_valve _update_for_con_stimulate_general_valve() {
        return new _ProjectionWrite_con_stimulate_general_valve(general_EV);
    }

    public _ProjectionWrite_env_start_retracting_first _update_for_env_start_retracting_first() {
        return new _ProjectionWrite_env_start_retracting_first(gears,gear);
    }

    public _ProjectionWrite_env_retract_gear_skip _update_for_env_retract_gear_skip() {
        return new _ProjectionWrite_env_retract_gear_skip(gears);
    }

    public _ProjectionWrite_open_valve_extend_gear _update_for_open_valve_extend_gear() {
        return new _ProjectionWrite_open_valve_extend_gear(valve_extend_gear);
    }

    public _ProjectionWrite_begin_flying _update_for_begin_flying() {
        return new _ProjectionWrite_begin_flying(shock_absorber);
    }

    public _ProjectionWrite_open_valve_retract_gear _update_for_open_valve_retract_gear() {
        return new _ProjectionWrite_open_valve_retract_gear(valve_retract_gear);
    }

    public _ProjectionWrite_env_close_analogical_switch _update_for_env_close_analogical_switch() {
        return new _ProjectionWrite_env_close_analogical_switch(analogical_switch);
    }

    public _ProjectionWrite_env_start_extending _update_for_env_start_extending() {
        return new _ProjectionWrite_env_start_extending(gears,gear);
    }

    public _ProjectionWrite_open_valve_door_close _update_for_open_valve_door_close() {
        return new _ProjectionWrite_open_valve_door_close(valve_close_door);
    }

    public _ProjectionWrite_con_stop_stimulate_open_door_valve _update_for_con_stop_stimulate_open_door_valve() {
        return new _ProjectionWrite_con_stop_stimulate_open_door_valve(open_EV);
    }

    public _ProjectionWrite_con_stop_stimulate_extend_gear_valve _update_for_con_stop_stimulate_extend_gear_valve() {
        return new _ProjectionWrite_con_stop_stimulate_extend_gear_valve(extend_EV);
    }

    public _ProjectionWrite_evn_close_general_valve _update_for_evn_close_general_valve() {
        return new _ProjectionWrite_evn_close_general_valve(general_valve);
    }

    public _ProjectionWrite_close_valve_extend_gear _update_for_close_valve_extend_gear() {
        return new _ProjectionWrite_close_valve_extend_gear(valve_extend_gear);
    }

    public _ProjectionWrite_con_stimulate_extend_gear_valve _update_for_con_stimulate_extend_gear_valve() {
        return new _ProjectionWrite_con_stimulate_extend_gear_valve(extend_EV);
    }

    public _ProjectionWrite_close_valve_door_open _update_for_close_valve_door_open() {
        return new _ProjectionWrite_close_valve_door_open(valve_open_door);
    }

    public _ProjectionWrite_con_stimulate_close_door_valve _update_for_con_stimulate_close_door_valve() {
        return new _ProjectionWrite_con_stimulate_close_door_valve(close_EV);
    }

    public _ProjectionWrite_env_extend_gear_skip _update_for_env_extend_gear_skip() {
        return new _ProjectionWrite_env_extend_gear_skip(gears);
    }

    public _ProjectionWrite_env_open_door_skip _update_for_env_open_door_skip() {
        return new _ProjectionWrite_env_open_door_skip(doors);
    }

    public _ProjectionWrite_env_start_open_door _update_for_env_start_open_door() {
        return new _ProjectionWrite_env_start_open_door(doors,door);
    }

    public void _apply_update_for_close_valve_door_close(_ProjectionWrite_close_valve_door_close update) {
        this.valve_close_door = update.valve_close_door;
    }

    public void _apply_update_for_close_valve_retract_gear(_ProjectionWrite_close_valve_retract_gear update) {
        this.valve_retract_gear = update.valve_retract_gear;
    }

    public void _apply_update_for_con_stimulate_open_door_valve(_ProjectionWrite_con_stimulate_open_door_valve update) {
        this.open_EV = update.open_EV;
    }

    public void _apply_update_for_env_close_door(_ProjectionWrite_env_close_door update) {
        this.doors = update.doors;
        this.door = update.door;
    }

    public void _apply_update_for_env_start_close_door(_ProjectionWrite_env_start_close_door update) {
        this.doors = update.doors;
        this.door = update.door;
    }

    public void _apply_update_for_toggle_handle_up(_ProjectionWrite_toggle_handle_up update) {
        this.handle = update.handle;
        this.handle_move = update.handle_move;
    }

    public void _apply_update_for_toggle_handle_down(_ProjectionWrite_toggle_handle_down update) {
        this.handle = update.handle;
        this.handle_move = update.handle_move;
    }

    public void _apply_update_for_open_valve_door_open(_ProjectionWrite_open_valve_door_open update) {
        this.valve_open_door = update.valve_open_door;
    }

    public void _apply_update_for_env_retract_gear_last(_ProjectionWrite_env_retract_gear_last update) {
        this.gears = update.gears;
        this.gear = update.gear;
    }

    public void _apply_update_for_env_open_door_last(_ProjectionWrite_env_open_door_last update) {
        this.doors = update.doors;
        this.door = update.door;
    }

    public void _apply_update_for_con_stop_stimulate_retract_gear_valve(_ProjectionWrite_con_stop_stimulate_retract_gear_valve update) {
        this.retract_EV = update.retract_EV;
    }

    public void _apply_update_for_env_close_door_skip(_ProjectionWrite_env_close_door_skip update) {
        this.doors = update.doors;
    }

    public void _apply_update_for_con_stop_stimulate_close_door_valve(_ProjectionWrite_con_stop_stimulate_close_door_valve update) {
        this.close_EV = update.close_EV;
    }

    public void _apply_update_for_env_open_analogical_switch(_ProjectionWrite_env_open_analogical_switch update) {
        this.analogical_switch = update.analogical_switch;
    }

    public void _apply_update_for_con_stop_stimulate_general_valve(_ProjectionWrite_con_stop_stimulate_general_valve update) {
        this.handle_move = update.handle_move;
        this.general_EV = update.general_EV;
    }

    public void _apply_update_for_env_extend_gear_last(_ProjectionWrite_env_extend_gear_last update) {
        this.gears = update.gears;
        this.gear = update.gear;
    }

    public void _apply_update_for_evn_open_general_valve(_ProjectionWrite_evn_open_general_valve update) {
        this.general_valve = update.general_valve;
    }

    public void _apply_update_for_land_plane(_ProjectionWrite_land_plane update) {
        this.shock_absorber = update.shock_absorber;
    }

    public void _apply_update_for_con_stimulate_retract_gear_valve(_ProjectionWrite_con_stimulate_retract_gear_valve update) {
        this.retract_EV = update.retract_EV;
    }

    public void _apply_update_for_con_stimulate_general_valve(_ProjectionWrite_con_stimulate_general_valve update) {
        this.general_EV = update.general_EV;
    }

    public void _apply_update_for_env_start_retracting_first(_ProjectionWrite_env_start_retracting_first update) {
        this.gears = update.gears;
        this.gear = update.gear;
    }

    public void _apply_update_for_env_retract_gear_skip(_ProjectionWrite_env_retract_gear_skip update) {
        this.gears = update.gears;
    }

    public void _apply_update_for_open_valve_extend_gear(_ProjectionWrite_open_valve_extend_gear update) {
        this.valve_extend_gear = update.valve_extend_gear;
    }

    public void _apply_update_for_begin_flying(_ProjectionWrite_begin_flying update) {
        this.shock_absorber = update.shock_absorber;
    }

    public void _apply_update_for_open_valve_retract_gear(_ProjectionWrite_open_valve_retract_gear update) {
        this.valve_retract_gear = update.valve_retract_gear;
    }

    public void _apply_update_for_env_close_analogical_switch(_ProjectionWrite_env_close_analogical_switch update) {
        this.analogical_switch = update.analogical_switch;
    }

    public void _apply_update_for_env_start_extending(_ProjectionWrite_env_start_extending update) {
        this.gears = update.gears;
        this.gear = update.gear;
    }

    public void _apply_update_for_open_valve_door_close(_ProjectionWrite_open_valve_door_close update) {
        this.valve_close_door = update.valve_close_door;
    }

    public void _apply_update_for_con_stop_stimulate_open_door_valve(_ProjectionWrite_con_stop_stimulate_open_door_valve update) {
        this.open_EV = update.open_EV;
    }

    public void _apply_update_for_con_stop_stimulate_extend_gear_valve(_ProjectionWrite_con_stop_stimulate_extend_gear_valve update) {
        this.extend_EV = update.extend_EV;
    }

    public void _apply_update_for_evn_close_general_valve(_ProjectionWrite_evn_close_general_valve update) {
        this.general_valve = update.general_valve;
    }

    public void _apply_update_for_close_valve_extend_gear(_ProjectionWrite_close_valve_extend_gear update) {
        this.valve_extend_gear = update.valve_extend_gear;
    }

    public void _apply_update_for_con_stimulate_extend_gear_valve(_ProjectionWrite_con_stimulate_extend_gear_valve update) {
        this.extend_EV = update.extend_EV;
    }

    public void _apply_update_for_close_valve_door_open(_ProjectionWrite_close_valve_door_open update) {
        this.valve_open_door = update.valve_open_door;
    }

    public void _apply_update_for_con_stimulate_close_door_valve(_ProjectionWrite_con_stimulate_close_door_valve update) {
        this.close_EV = update.close_EV;
    }

    public void _apply_update_for_env_extend_gear_skip(_ProjectionWrite_env_extend_gear_skip update) {
        this.gears = update.gears;
    }

    public void _apply_update_for_env_open_door_skip(_ProjectionWrite_env_open_door_skip update) {
        this.doors = update.doors;
    }

    public void _apply_update_for_env_start_open_door(_ProjectionWrite_env_start_open_door update) {
        this.doors = update.doors;
        this.door = update.door;
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


    private static class ModelChecker {
        private final Type type;
        private final int threads;
        private final boolean isCaching;
        private final boolean isDebug;

        private final LinkedList<LandingGear_R6> unvisitedStates = new LinkedList<>();
        private final Set<LandingGear_R6> states = ConcurrentHashMap.newKeySet();
        private AtomicInteger transitions = new AtomicInteger(0);
        private ThreadPoolExecutor threadPool;
        private Object waitLock = new Object();

        private AtomicBoolean invariantViolated = new AtomicBoolean(false);
        private AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        private LandingGear_R6 counterExampleState = null;

        PersistentHashMap _OpCache_begin_flying = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_begin_flying = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_land_plane = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_land_plane = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_open_valve_door_open = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_open_valve_door_open = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_close_valve_door_open = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_close_valve_door_open = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_open_valve_door_close = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_open_valve_door_close = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_close_valve_door_close = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_close_valve_door_close = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_open_valve_retract_gear = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_open_valve_retract_gear = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_close_valve_retract_gear = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_close_valve_retract_gear = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_open_valve_extend_gear = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_open_valve_extend_gear = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_close_valve_extend_gear = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_close_valve_extend_gear = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_con_stimulate_open_door_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_con_stimulate_open_door_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_con_stop_stimulate_open_door_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_con_stop_stimulate_open_door_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_con_stimulate_close_door_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_con_stimulate_close_door_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_con_stop_stimulate_close_door_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_con_stop_stimulate_close_door_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_con_stimulate_retract_gear_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_con_stimulate_retract_gear_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_con_stop_stimulate_retract_gear_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_con_stop_stimulate_retract_gear_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_con_stimulate_extend_gear_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_con_stimulate_extend_gear_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_con_stop_stimulate_extend_gear_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_con_stop_stimulate_extend_gear_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_env_start_retracting_first = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_env_start_retracting_first = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_env_retract_gear_skip = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_env_retract_gear_skip = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_env_retract_gear_last = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_env_retract_gear_last = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_env_start_extending = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_env_start_extending = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_env_extend_gear_last = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_env_extend_gear_last = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_env_extend_gear_skip = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_env_extend_gear_skip = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_env_start_open_door = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_env_start_open_door = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_env_open_door_last = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_env_open_door_last = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_env_open_door_skip = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_env_open_door_skip = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_env_start_close_door = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_env_start_close_door = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_env_close_door = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_env_close_door = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_env_close_door_skip = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_env_close_door_skip = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_toggle_handle_up = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_toggle_handle_up = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_toggle_handle_down = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_toggle_handle_down = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_con_stimulate_general_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_con_stimulate_general_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_con_stop_stimulate_general_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_con_stop_stimulate_general_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_evn_open_general_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_evn_open_general_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_evn_close_general_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_evn_close_general_valve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_env_close_analogical_switch = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_env_close_analogical_switch = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_env_open_analogical_switch = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_env_open_analogical_switch = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_1 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_2 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_3 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_4 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_5 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_6 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_7 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_8 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_9 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_10 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_11 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_12 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_13 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_14 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_15 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_16 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_17 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_18 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_19 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_20 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_21 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_22 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_23 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_24 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_25 = PersistentHashMap.EMPTY;

        public ModelChecker(final Type type, final int threads, final boolean isCaching, final boolean isDebug) {
            this.type = type;
            this.threads = threads;
            this.isCaching = isCaching;
            this.isDebug = isDebug;
        }

        public void modelCheck() {
            if (isDebug) {
                System.out.println("Starting Modelchecking, STRATEGY=" + type + ", THREADS=" + threads + ", CACHING=" + isCaching);
            }

            if (threads <= 1) {

                modelCheckSingleThreaded();
            } else {
                this.threadPool = (ThreadPoolExecutor) Executors.newFixedThreadPool(threads-1);
                modelCheckMultiThreaded();
            }
        }

        private void modelCheckSingleThreaded() {
            LandingGear_R6 machine = new LandingGear_R6();
            states.add(machine);
            unvisitedStates.add(machine);

            while(!unvisitedStates.isEmpty()) {
                LandingGear_R6 state = next();

                Set<LandingGear_R6> nextStates = generateNextStates(state);

                nextStates.forEach(nextState -> {
                    if(!states.contains(nextState)) {
                        states.add(nextState);
                        unvisitedStates.add(nextState);
                        if(isDebug && states.size() % 50000 == 0) {
                            System.out.println("VISITED STATES: " + states.size());
                            System.out.println("OPEN STATES: " + unvisitedStates.size());
                            System.out.println("EVALUATED TRANSITIONS: " + transitions.get());
                            System.out.println("-------------------");
                        }
                    }
                });

                if(invariantViolated(state)) {
                    invariantViolated.set(true);
                    counterExampleState = state;
                    break;
                }

                if(nextStates.isEmpty()) {
                    deadlockDetected.set(true);
                    counterExampleState = state;
                    break;
                }

            }
            printResult(states.size(), transitions.get());
        }

        private void modelCheckMultiThreaded() {
            LandingGear_R6 machine = new LandingGear_R6();
            states.add(machine);
            unvisitedStates.add(machine);

            AtomicBoolean stopThreads = new AtomicBoolean(false);
            AtomicInteger possibleQueueChanges = new AtomicInteger(0);

            while(!unvisitedStates.isEmpty() && !stopThreads.get()) {
                possibleQueueChanges.incrementAndGet();
                LandingGear_R6 state = next();
                Runnable task = () -> {
                    Set<LandingGear_R6> nextStates = generateNextStates(state);

                    nextStates.forEach(nextState -> {
                        if(states.add(nextState)) {
                            synchronized (unvisitedStates) {
                                unvisitedStates.add(nextState);
                            }
                            if(isDebug && states.size() % 50000 == 0) {
                                System.out.println("VISITED STATES: " + states.size());
                                System.out.println("OPEN STATES: " + unvisitedStates.size());
                                System.out.println("EVALUATED TRANSITIONS: " + transitions.get());
                                System.out.println("-------------------");
                            }
                        }
                    });

                    int running = possibleQueueChanges.decrementAndGet();
                    synchronized (unvisitedStates) {
                        if (!unvisitedStates.isEmpty() || running == 0) {
                            synchronized (waitLock) {
                                waitLock.notify();
                            }
                        }
                    }

                    if(invariantViolated(state)) {
                        invariantViolated.set(true);
                        counterExampleState = state;
                        stopThreads.set(true);
                    }

                    if(nextStates.isEmpty()) {
                        deadlockDetected.set(true);
                        counterExampleState = state;
                        stopThreads.set(true);
                    }
                };
                threadPool.submit(task);
                synchronized(waitLock) {
                    if (unvisitedStates.isEmpty() && possibleQueueChanges.get() > 0) {
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
                threadPool.awaitTermination(24, TimeUnit.HOURS);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            printResult(states.size(), transitions.get());
        }

        private LandingGear_R6 next() {
            synchronized(this.unvisitedStates) {
                return switch(type) {
                    case BFS -> this.unvisitedStates.removeFirst();
                    case DFS -> this.unvisitedStates.removeLast();
                    case MIXED -> this.unvisitedStates.size() % 2 == 0 ? this.unvisitedStates.removeFirst() : this.unvisitedStates.removeLast();
                };
            }
        }

        @SuppressWarnings("unchecked")
        private Set<LandingGear_R6> generateNextStates(final LandingGear_R6 state) {
            Set<LandingGear_R6> result = new HashSet<>();
            if(isCaching) {
                _ProjectionRead__tr_begin_flying read__tr_begin_flying_state = state._projected_state_for__tr_begin_flying();
                Object _obj__trid_1 = GET.invoke(_OpCache_tr_begin_flying, read__tr_begin_flying_state);
                boolean _trid_1;
                if(_obj__trid_1 == null) {
                    _trid_1 = state._tr_begin_flying();
                    _OpCache_tr_begin_flying = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_begin_flying, read__tr_begin_flying_state, _trid_1);
                } else {
                    _trid_1 = (boolean) _obj__trid_1;
                }
                if(_trid_1) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_begin_flying readState = state._projected_state_for_begin_flying();
                    PersistentHashMap _OpCache_with_parameter_begin_flying = (PersistentHashMap) GET.invoke(_OpCache_begin_flying, _trid_1);
                    if(_OpCache_with_parameter_begin_flying != null) {
                        _ProjectionWrite_begin_flying writeState = (_ProjectionWrite_begin_flying) GET.invoke(_OpCache_with_parameter_begin_flying, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_begin_flying(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.begin_flying();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_begin_flying();
                            _OpCache_with_parameter_begin_flying = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_begin_flying, readState, writeState);
                            _OpCache_begin_flying = (PersistentHashMap) ASSOC.invoke(_OpCache_begin_flying, _trid_1, _OpCache_with_parameter_begin_flying);
                        }

                    } else {
                        copiedState.begin_flying();
                        copiedState.parent = state;
                        _ProjectionWrite_begin_flying writeState = copiedState._update_for_begin_flying();
                        _OpCache_with_parameter_begin_flying = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_begin_flying = (PersistentHashMap) ASSOC.invoke(_OpCache_begin_flying, _trid_1, _OpCache_with_parameter_begin_flying);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_land_plane read__tr_land_plane_state = state._projected_state_for__tr_land_plane();
                Object _obj__trid_2 = GET.invoke(_OpCache_tr_land_plane, read__tr_land_plane_state);
                boolean _trid_2;
                if(_obj__trid_2 == null) {
                    _trid_2 = state._tr_land_plane();
                    _OpCache_tr_land_plane = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_land_plane, read__tr_land_plane_state, _trid_2);
                } else {
                    _trid_2 = (boolean) _obj__trid_2;
                }
                if(_trid_2) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_land_plane readState = state._projected_state_for_land_plane();
                    PersistentHashMap _OpCache_with_parameter_land_plane = (PersistentHashMap) GET.invoke(_OpCache_land_plane, _trid_2);
                    if(_OpCache_with_parameter_land_plane != null) {
                        _ProjectionWrite_land_plane writeState = (_ProjectionWrite_land_plane) GET.invoke(_OpCache_with_parameter_land_plane, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_land_plane(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.land_plane();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_land_plane();
                            _OpCache_with_parameter_land_plane = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_land_plane, readState, writeState);
                            _OpCache_land_plane = (PersistentHashMap) ASSOC.invoke(_OpCache_land_plane, _trid_2, _OpCache_with_parameter_land_plane);
                        }

                    } else {
                        copiedState.land_plane();
                        copiedState.parent = state;
                        _ProjectionWrite_land_plane writeState = copiedState._update_for_land_plane();
                        _OpCache_with_parameter_land_plane = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_land_plane = (PersistentHashMap) ASSOC.invoke(_OpCache_land_plane, _trid_2, _OpCache_with_parameter_land_plane);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_open_valve_door_open read__tr_open_valve_door_open_state = state._projected_state_for__tr_open_valve_door_open();
                Object _obj__trid_3 = GET.invoke(_OpCache_tr_open_valve_door_open, read__tr_open_valve_door_open_state);
                boolean _trid_3;
                if(_obj__trid_3 == null) {
                    _trid_3 = state._tr_open_valve_door_open();
                    _OpCache_tr_open_valve_door_open = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_open_valve_door_open, read__tr_open_valve_door_open_state, _trid_3);
                } else {
                    _trid_3 = (boolean) _obj__trid_3;
                }
                if(_trid_3) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_open_valve_door_open readState = state._projected_state_for_open_valve_door_open();
                    PersistentHashMap _OpCache_with_parameter_open_valve_door_open = (PersistentHashMap) GET.invoke(_OpCache_open_valve_door_open, _trid_3);
                    if(_OpCache_with_parameter_open_valve_door_open != null) {
                        _ProjectionWrite_open_valve_door_open writeState = (_ProjectionWrite_open_valve_door_open) GET.invoke(_OpCache_with_parameter_open_valve_door_open, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_open_valve_door_open(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.open_valve_door_open();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_open_valve_door_open();
                            _OpCache_with_parameter_open_valve_door_open = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_open_valve_door_open, readState, writeState);
                            _OpCache_open_valve_door_open = (PersistentHashMap) ASSOC.invoke(_OpCache_open_valve_door_open, _trid_3, _OpCache_with_parameter_open_valve_door_open);
                        }

                    } else {
                        copiedState.open_valve_door_open();
                        copiedState.parent = state;
                        _ProjectionWrite_open_valve_door_open writeState = copiedState._update_for_open_valve_door_open();
                        _OpCache_with_parameter_open_valve_door_open = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_open_valve_door_open = (PersistentHashMap) ASSOC.invoke(_OpCache_open_valve_door_open, _trid_3, _OpCache_with_parameter_open_valve_door_open);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_close_valve_door_open read__tr_close_valve_door_open_state = state._projected_state_for__tr_close_valve_door_open();
                Object _obj__trid_4 = GET.invoke(_OpCache_tr_close_valve_door_open, read__tr_close_valve_door_open_state);
                boolean _trid_4;
                if(_obj__trid_4 == null) {
                    _trid_4 = state._tr_close_valve_door_open();
                    _OpCache_tr_close_valve_door_open = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_close_valve_door_open, read__tr_close_valve_door_open_state, _trid_4);
                } else {
                    _trid_4 = (boolean) _obj__trid_4;
                }
                if(_trid_4) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_close_valve_door_open readState = state._projected_state_for_close_valve_door_open();
                    PersistentHashMap _OpCache_with_parameter_close_valve_door_open = (PersistentHashMap) GET.invoke(_OpCache_close_valve_door_open, _trid_4);
                    if(_OpCache_with_parameter_close_valve_door_open != null) {
                        _ProjectionWrite_close_valve_door_open writeState = (_ProjectionWrite_close_valve_door_open) GET.invoke(_OpCache_with_parameter_close_valve_door_open, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_close_valve_door_open(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.close_valve_door_open();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_close_valve_door_open();
                            _OpCache_with_parameter_close_valve_door_open = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_close_valve_door_open, readState, writeState);
                            _OpCache_close_valve_door_open = (PersistentHashMap) ASSOC.invoke(_OpCache_close_valve_door_open, _trid_4, _OpCache_with_parameter_close_valve_door_open);
                        }

                    } else {
                        copiedState.close_valve_door_open();
                        copiedState.parent = state;
                        _ProjectionWrite_close_valve_door_open writeState = copiedState._update_for_close_valve_door_open();
                        _OpCache_with_parameter_close_valve_door_open = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_close_valve_door_open = (PersistentHashMap) ASSOC.invoke(_OpCache_close_valve_door_open, _trid_4, _OpCache_with_parameter_close_valve_door_open);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_open_valve_door_close read__tr_open_valve_door_close_state = state._projected_state_for__tr_open_valve_door_close();
                Object _obj__trid_5 = GET.invoke(_OpCache_tr_open_valve_door_close, read__tr_open_valve_door_close_state);
                boolean _trid_5;
                if(_obj__trid_5 == null) {
                    _trid_5 = state._tr_open_valve_door_close();
                    _OpCache_tr_open_valve_door_close = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_open_valve_door_close, read__tr_open_valve_door_close_state, _trid_5);
                } else {
                    _trid_5 = (boolean) _obj__trid_5;
                }
                if(_trid_5) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_open_valve_door_close readState = state._projected_state_for_open_valve_door_close();
                    PersistentHashMap _OpCache_with_parameter_open_valve_door_close = (PersistentHashMap) GET.invoke(_OpCache_open_valve_door_close, _trid_5);
                    if(_OpCache_with_parameter_open_valve_door_close != null) {
                        _ProjectionWrite_open_valve_door_close writeState = (_ProjectionWrite_open_valve_door_close) GET.invoke(_OpCache_with_parameter_open_valve_door_close, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_open_valve_door_close(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.open_valve_door_close();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_open_valve_door_close();
                            _OpCache_with_parameter_open_valve_door_close = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_open_valve_door_close, readState, writeState);
                            _OpCache_open_valve_door_close = (PersistentHashMap) ASSOC.invoke(_OpCache_open_valve_door_close, _trid_5, _OpCache_with_parameter_open_valve_door_close);
                        }

                    } else {
                        copiedState.open_valve_door_close();
                        copiedState.parent = state;
                        _ProjectionWrite_open_valve_door_close writeState = copiedState._update_for_open_valve_door_close();
                        _OpCache_with_parameter_open_valve_door_close = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_open_valve_door_close = (PersistentHashMap) ASSOC.invoke(_OpCache_open_valve_door_close, _trid_5, _OpCache_with_parameter_open_valve_door_close);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_close_valve_door_close read__tr_close_valve_door_close_state = state._projected_state_for__tr_close_valve_door_close();
                Object _obj__trid_6 = GET.invoke(_OpCache_tr_close_valve_door_close, read__tr_close_valve_door_close_state);
                boolean _trid_6;
                if(_obj__trid_6 == null) {
                    _trid_6 = state._tr_close_valve_door_close();
                    _OpCache_tr_close_valve_door_close = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_close_valve_door_close, read__tr_close_valve_door_close_state, _trid_6);
                } else {
                    _trid_6 = (boolean) _obj__trid_6;
                }
                if(_trid_6) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_close_valve_door_close readState = state._projected_state_for_close_valve_door_close();
                    PersistentHashMap _OpCache_with_parameter_close_valve_door_close = (PersistentHashMap) GET.invoke(_OpCache_close_valve_door_close, _trid_6);
                    if(_OpCache_with_parameter_close_valve_door_close != null) {
                        _ProjectionWrite_close_valve_door_close writeState = (_ProjectionWrite_close_valve_door_close) GET.invoke(_OpCache_with_parameter_close_valve_door_close, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_close_valve_door_close(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.close_valve_door_close();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_close_valve_door_close();
                            _OpCache_with_parameter_close_valve_door_close = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_close_valve_door_close, readState, writeState);
                            _OpCache_close_valve_door_close = (PersistentHashMap) ASSOC.invoke(_OpCache_close_valve_door_close, _trid_6, _OpCache_with_parameter_close_valve_door_close);
                        }

                    } else {
                        copiedState.close_valve_door_close();
                        copiedState.parent = state;
                        _ProjectionWrite_close_valve_door_close writeState = copiedState._update_for_close_valve_door_close();
                        _OpCache_with_parameter_close_valve_door_close = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_close_valve_door_close = (PersistentHashMap) ASSOC.invoke(_OpCache_close_valve_door_close, _trid_6, _OpCache_with_parameter_close_valve_door_close);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_open_valve_retract_gear read__tr_open_valve_retract_gear_state = state._projected_state_for__tr_open_valve_retract_gear();
                Object _obj__trid_7 = GET.invoke(_OpCache_tr_open_valve_retract_gear, read__tr_open_valve_retract_gear_state);
                boolean _trid_7;
                if(_obj__trid_7 == null) {
                    _trid_7 = state._tr_open_valve_retract_gear();
                    _OpCache_tr_open_valve_retract_gear = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_open_valve_retract_gear, read__tr_open_valve_retract_gear_state, _trid_7);
                } else {
                    _trid_7 = (boolean) _obj__trid_7;
                }
                if(_trid_7) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_open_valve_retract_gear readState = state._projected_state_for_open_valve_retract_gear();
                    PersistentHashMap _OpCache_with_parameter_open_valve_retract_gear = (PersistentHashMap) GET.invoke(_OpCache_open_valve_retract_gear, _trid_7);
                    if(_OpCache_with_parameter_open_valve_retract_gear != null) {
                        _ProjectionWrite_open_valve_retract_gear writeState = (_ProjectionWrite_open_valve_retract_gear) GET.invoke(_OpCache_with_parameter_open_valve_retract_gear, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_open_valve_retract_gear(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.open_valve_retract_gear();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_open_valve_retract_gear();
                            _OpCache_with_parameter_open_valve_retract_gear = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_open_valve_retract_gear, readState, writeState);
                            _OpCache_open_valve_retract_gear = (PersistentHashMap) ASSOC.invoke(_OpCache_open_valve_retract_gear, _trid_7, _OpCache_with_parameter_open_valve_retract_gear);
                        }

                    } else {
                        copiedState.open_valve_retract_gear();
                        copiedState.parent = state;
                        _ProjectionWrite_open_valve_retract_gear writeState = copiedState._update_for_open_valve_retract_gear();
                        _OpCache_with_parameter_open_valve_retract_gear = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_open_valve_retract_gear = (PersistentHashMap) ASSOC.invoke(_OpCache_open_valve_retract_gear, _trid_7, _OpCache_with_parameter_open_valve_retract_gear);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_close_valve_retract_gear read__tr_close_valve_retract_gear_state = state._projected_state_for__tr_close_valve_retract_gear();
                Object _obj__trid_8 = GET.invoke(_OpCache_tr_close_valve_retract_gear, read__tr_close_valve_retract_gear_state);
                boolean _trid_8;
                if(_obj__trid_8 == null) {
                    _trid_8 = state._tr_close_valve_retract_gear();
                    _OpCache_tr_close_valve_retract_gear = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_close_valve_retract_gear, read__tr_close_valve_retract_gear_state, _trid_8);
                } else {
                    _trid_8 = (boolean) _obj__trid_8;
                }
                if(_trid_8) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_close_valve_retract_gear readState = state._projected_state_for_close_valve_retract_gear();
                    PersistentHashMap _OpCache_with_parameter_close_valve_retract_gear = (PersistentHashMap) GET.invoke(_OpCache_close_valve_retract_gear, _trid_8);
                    if(_OpCache_with_parameter_close_valve_retract_gear != null) {
                        _ProjectionWrite_close_valve_retract_gear writeState = (_ProjectionWrite_close_valve_retract_gear) GET.invoke(_OpCache_with_parameter_close_valve_retract_gear, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_close_valve_retract_gear(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.close_valve_retract_gear();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_close_valve_retract_gear();
                            _OpCache_with_parameter_close_valve_retract_gear = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_close_valve_retract_gear, readState, writeState);
                            _OpCache_close_valve_retract_gear = (PersistentHashMap) ASSOC.invoke(_OpCache_close_valve_retract_gear, _trid_8, _OpCache_with_parameter_close_valve_retract_gear);
                        }

                    } else {
                        copiedState.close_valve_retract_gear();
                        copiedState.parent = state;
                        _ProjectionWrite_close_valve_retract_gear writeState = copiedState._update_for_close_valve_retract_gear();
                        _OpCache_with_parameter_close_valve_retract_gear = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_close_valve_retract_gear = (PersistentHashMap) ASSOC.invoke(_OpCache_close_valve_retract_gear, _trid_8, _OpCache_with_parameter_close_valve_retract_gear);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_open_valve_extend_gear read__tr_open_valve_extend_gear_state = state._projected_state_for__tr_open_valve_extend_gear();
                Object _obj__trid_9 = GET.invoke(_OpCache_tr_open_valve_extend_gear, read__tr_open_valve_extend_gear_state);
                boolean _trid_9;
                if(_obj__trid_9 == null) {
                    _trid_9 = state._tr_open_valve_extend_gear();
                    _OpCache_tr_open_valve_extend_gear = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_open_valve_extend_gear, read__tr_open_valve_extend_gear_state, _trid_9);
                } else {
                    _trid_9 = (boolean) _obj__trid_9;
                }
                if(_trid_9) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_open_valve_extend_gear readState = state._projected_state_for_open_valve_extend_gear();
                    PersistentHashMap _OpCache_with_parameter_open_valve_extend_gear = (PersistentHashMap) GET.invoke(_OpCache_open_valve_extend_gear, _trid_9);
                    if(_OpCache_with_parameter_open_valve_extend_gear != null) {
                        _ProjectionWrite_open_valve_extend_gear writeState = (_ProjectionWrite_open_valve_extend_gear) GET.invoke(_OpCache_with_parameter_open_valve_extend_gear, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_open_valve_extend_gear(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.open_valve_extend_gear();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_open_valve_extend_gear();
                            _OpCache_with_parameter_open_valve_extend_gear = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_open_valve_extend_gear, readState, writeState);
                            _OpCache_open_valve_extend_gear = (PersistentHashMap) ASSOC.invoke(_OpCache_open_valve_extend_gear, _trid_9, _OpCache_with_parameter_open_valve_extend_gear);
                        }

                    } else {
                        copiedState.open_valve_extend_gear();
                        copiedState.parent = state;
                        _ProjectionWrite_open_valve_extend_gear writeState = copiedState._update_for_open_valve_extend_gear();
                        _OpCache_with_parameter_open_valve_extend_gear = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_open_valve_extend_gear = (PersistentHashMap) ASSOC.invoke(_OpCache_open_valve_extend_gear, _trid_9, _OpCache_with_parameter_open_valve_extend_gear);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_close_valve_extend_gear read__tr_close_valve_extend_gear_state = state._projected_state_for__tr_close_valve_extend_gear();
                Object _obj__trid_10 = GET.invoke(_OpCache_tr_close_valve_extend_gear, read__tr_close_valve_extend_gear_state);
                boolean _trid_10;
                if(_obj__trid_10 == null) {
                    _trid_10 = state._tr_close_valve_extend_gear();
                    _OpCache_tr_close_valve_extend_gear = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_close_valve_extend_gear, read__tr_close_valve_extend_gear_state, _trid_10);
                } else {
                    _trid_10 = (boolean) _obj__trid_10;
                }
                if(_trid_10) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_close_valve_extend_gear readState = state._projected_state_for_close_valve_extend_gear();
                    PersistentHashMap _OpCache_with_parameter_close_valve_extend_gear = (PersistentHashMap) GET.invoke(_OpCache_close_valve_extend_gear, _trid_10);
                    if(_OpCache_with_parameter_close_valve_extend_gear != null) {
                        _ProjectionWrite_close_valve_extend_gear writeState = (_ProjectionWrite_close_valve_extend_gear) GET.invoke(_OpCache_with_parameter_close_valve_extend_gear, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_close_valve_extend_gear(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.close_valve_extend_gear();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_close_valve_extend_gear();
                            _OpCache_with_parameter_close_valve_extend_gear = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_close_valve_extend_gear, readState, writeState);
                            _OpCache_close_valve_extend_gear = (PersistentHashMap) ASSOC.invoke(_OpCache_close_valve_extend_gear, _trid_10, _OpCache_with_parameter_close_valve_extend_gear);
                        }

                    } else {
                        copiedState.close_valve_extend_gear();
                        copiedState.parent = state;
                        _ProjectionWrite_close_valve_extend_gear writeState = copiedState._update_for_close_valve_extend_gear();
                        _OpCache_with_parameter_close_valve_extend_gear = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_close_valve_extend_gear = (PersistentHashMap) ASSOC.invoke(_OpCache_close_valve_extend_gear, _trid_10, _OpCache_with_parameter_close_valve_extend_gear);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_con_stimulate_open_door_valve read__tr_con_stimulate_open_door_valve_state = state._projected_state_for__tr_con_stimulate_open_door_valve();
                Object _obj__trid_11 = GET.invoke(_OpCache_tr_con_stimulate_open_door_valve, read__tr_con_stimulate_open_door_valve_state);
                boolean _trid_11;
                if(_obj__trid_11 == null) {
                    _trid_11 = state._tr_con_stimulate_open_door_valve();
                    _OpCache_tr_con_stimulate_open_door_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_con_stimulate_open_door_valve, read__tr_con_stimulate_open_door_valve_state, _trid_11);
                } else {
                    _trid_11 = (boolean) _obj__trid_11;
                }
                if(_trid_11) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_con_stimulate_open_door_valve readState = state._projected_state_for_con_stimulate_open_door_valve();
                    PersistentHashMap _OpCache_with_parameter_con_stimulate_open_door_valve = (PersistentHashMap) GET.invoke(_OpCache_con_stimulate_open_door_valve, _trid_11);
                    if(_OpCache_with_parameter_con_stimulate_open_door_valve != null) {
                        _ProjectionWrite_con_stimulate_open_door_valve writeState = (_ProjectionWrite_con_stimulate_open_door_valve) GET.invoke(_OpCache_with_parameter_con_stimulate_open_door_valve, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_con_stimulate_open_door_valve(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.con_stimulate_open_door_valve();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_con_stimulate_open_door_valve();
                            _OpCache_with_parameter_con_stimulate_open_door_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_con_stimulate_open_door_valve, readState, writeState);
                            _OpCache_con_stimulate_open_door_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_con_stimulate_open_door_valve, _trid_11, _OpCache_with_parameter_con_stimulate_open_door_valve);
                        }

                    } else {
                        copiedState.con_stimulate_open_door_valve();
                        copiedState.parent = state;
                        _ProjectionWrite_con_stimulate_open_door_valve writeState = copiedState._update_for_con_stimulate_open_door_valve();
                        _OpCache_with_parameter_con_stimulate_open_door_valve = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_con_stimulate_open_door_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_con_stimulate_open_door_valve, _trid_11, _OpCache_with_parameter_con_stimulate_open_door_valve);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_con_stop_stimulate_open_door_valve read__tr_con_stop_stimulate_open_door_valve_state = state._projected_state_for__tr_con_stop_stimulate_open_door_valve();
                Object _obj__trid_12 = GET.invoke(_OpCache_tr_con_stop_stimulate_open_door_valve, read__tr_con_stop_stimulate_open_door_valve_state);
                boolean _trid_12;
                if(_obj__trid_12 == null) {
                    _trid_12 = state._tr_con_stop_stimulate_open_door_valve();
                    _OpCache_tr_con_stop_stimulate_open_door_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_con_stop_stimulate_open_door_valve, read__tr_con_stop_stimulate_open_door_valve_state, _trid_12);
                } else {
                    _trid_12 = (boolean) _obj__trid_12;
                }
                if(_trid_12) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_con_stop_stimulate_open_door_valve readState = state._projected_state_for_con_stop_stimulate_open_door_valve();
                    PersistentHashMap _OpCache_with_parameter_con_stop_stimulate_open_door_valve = (PersistentHashMap) GET.invoke(_OpCache_con_stop_stimulate_open_door_valve, _trid_12);
                    if(_OpCache_with_parameter_con_stop_stimulate_open_door_valve != null) {
                        _ProjectionWrite_con_stop_stimulate_open_door_valve writeState = (_ProjectionWrite_con_stop_stimulate_open_door_valve) GET.invoke(_OpCache_with_parameter_con_stop_stimulate_open_door_valve, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_con_stop_stimulate_open_door_valve(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.con_stop_stimulate_open_door_valve();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_con_stop_stimulate_open_door_valve();
                            _OpCache_with_parameter_con_stop_stimulate_open_door_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_con_stop_stimulate_open_door_valve, readState, writeState);
                            _OpCache_con_stop_stimulate_open_door_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_con_stop_stimulate_open_door_valve, _trid_12, _OpCache_with_parameter_con_stop_stimulate_open_door_valve);
                        }

                    } else {
                        copiedState.con_stop_stimulate_open_door_valve();
                        copiedState.parent = state;
                        _ProjectionWrite_con_stop_stimulate_open_door_valve writeState = copiedState._update_for_con_stop_stimulate_open_door_valve();
                        _OpCache_with_parameter_con_stop_stimulate_open_door_valve = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_con_stop_stimulate_open_door_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_con_stop_stimulate_open_door_valve, _trid_12, _OpCache_with_parameter_con_stop_stimulate_open_door_valve);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_con_stimulate_close_door_valve read__tr_con_stimulate_close_door_valve_state = state._projected_state_for__tr_con_stimulate_close_door_valve();
                Object _obj__trid_13 = GET.invoke(_OpCache_tr_con_stimulate_close_door_valve, read__tr_con_stimulate_close_door_valve_state);
                boolean _trid_13;
                if(_obj__trid_13 == null) {
                    _trid_13 = state._tr_con_stimulate_close_door_valve();
                    _OpCache_tr_con_stimulate_close_door_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_con_stimulate_close_door_valve, read__tr_con_stimulate_close_door_valve_state, _trid_13);
                } else {
                    _trid_13 = (boolean) _obj__trid_13;
                }
                if(_trid_13) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_con_stimulate_close_door_valve readState = state._projected_state_for_con_stimulate_close_door_valve();
                    PersistentHashMap _OpCache_with_parameter_con_stimulate_close_door_valve = (PersistentHashMap) GET.invoke(_OpCache_con_stimulate_close_door_valve, _trid_13);
                    if(_OpCache_with_parameter_con_stimulate_close_door_valve != null) {
                        _ProjectionWrite_con_stimulate_close_door_valve writeState = (_ProjectionWrite_con_stimulate_close_door_valve) GET.invoke(_OpCache_with_parameter_con_stimulate_close_door_valve, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_con_stimulate_close_door_valve(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.con_stimulate_close_door_valve();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_con_stimulate_close_door_valve();
                            _OpCache_with_parameter_con_stimulate_close_door_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_con_stimulate_close_door_valve, readState, writeState);
                            _OpCache_con_stimulate_close_door_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_con_stimulate_close_door_valve, _trid_13, _OpCache_with_parameter_con_stimulate_close_door_valve);
                        }

                    } else {
                        copiedState.con_stimulate_close_door_valve();
                        copiedState.parent = state;
                        _ProjectionWrite_con_stimulate_close_door_valve writeState = copiedState._update_for_con_stimulate_close_door_valve();
                        _OpCache_with_parameter_con_stimulate_close_door_valve = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_con_stimulate_close_door_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_con_stimulate_close_door_valve, _trid_13, _OpCache_with_parameter_con_stimulate_close_door_valve);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_con_stop_stimulate_close_door_valve read__tr_con_stop_stimulate_close_door_valve_state = state._projected_state_for__tr_con_stop_stimulate_close_door_valve();
                Object _obj__trid_14 = GET.invoke(_OpCache_tr_con_stop_stimulate_close_door_valve, read__tr_con_stop_stimulate_close_door_valve_state);
                boolean _trid_14;
                if(_obj__trid_14 == null) {
                    _trid_14 = state._tr_con_stop_stimulate_close_door_valve();
                    _OpCache_tr_con_stop_stimulate_close_door_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_con_stop_stimulate_close_door_valve, read__tr_con_stop_stimulate_close_door_valve_state, _trid_14);
                } else {
                    _trid_14 = (boolean) _obj__trid_14;
                }
                if(_trid_14) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_con_stop_stimulate_close_door_valve readState = state._projected_state_for_con_stop_stimulate_close_door_valve();
                    PersistentHashMap _OpCache_with_parameter_con_stop_stimulate_close_door_valve = (PersistentHashMap) GET.invoke(_OpCache_con_stop_stimulate_close_door_valve, _trid_14);
                    if(_OpCache_with_parameter_con_stop_stimulate_close_door_valve != null) {
                        _ProjectionWrite_con_stop_stimulate_close_door_valve writeState = (_ProjectionWrite_con_stop_stimulate_close_door_valve) GET.invoke(_OpCache_with_parameter_con_stop_stimulate_close_door_valve, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_con_stop_stimulate_close_door_valve(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.con_stop_stimulate_close_door_valve();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_con_stop_stimulate_close_door_valve();
                            _OpCache_with_parameter_con_stop_stimulate_close_door_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_con_stop_stimulate_close_door_valve, readState, writeState);
                            _OpCache_con_stop_stimulate_close_door_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_con_stop_stimulate_close_door_valve, _trid_14, _OpCache_with_parameter_con_stop_stimulate_close_door_valve);
                        }

                    } else {
                        copiedState.con_stop_stimulate_close_door_valve();
                        copiedState.parent = state;
                        _ProjectionWrite_con_stop_stimulate_close_door_valve writeState = copiedState._update_for_con_stop_stimulate_close_door_valve();
                        _OpCache_with_parameter_con_stop_stimulate_close_door_valve = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_con_stop_stimulate_close_door_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_con_stop_stimulate_close_door_valve, _trid_14, _OpCache_with_parameter_con_stop_stimulate_close_door_valve);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_con_stimulate_retract_gear_valve read__tr_con_stimulate_retract_gear_valve_state = state._projected_state_for__tr_con_stimulate_retract_gear_valve();
                Object _obj__trid_15 = GET.invoke(_OpCache_tr_con_stimulate_retract_gear_valve, read__tr_con_stimulate_retract_gear_valve_state);
                boolean _trid_15;
                if(_obj__trid_15 == null) {
                    _trid_15 = state._tr_con_stimulate_retract_gear_valve();
                    _OpCache_tr_con_stimulate_retract_gear_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_con_stimulate_retract_gear_valve, read__tr_con_stimulate_retract_gear_valve_state, _trid_15);
                } else {
                    _trid_15 = (boolean) _obj__trid_15;
                }
                if(_trid_15) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_con_stimulate_retract_gear_valve readState = state._projected_state_for_con_stimulate_retract_gear_valve();
                    PersistentHashMap _OpCache_with_parameter_con_stimulate_retract_gear_valve = (PersistentHashMap) GET.invoke(_OpCache_con_stimulate_retract_gear_valve, _trid_15);
                    if(_OpCache_with_parameter_con_stimulate_retract_gear_valve != null) {
                        _ProjectionWrite_con_stimulate_retract_gear_valve writeState = (_ProjectionWrite_con_stimulate_retract_gear_valve) GET.invoke(_OpCache_with_parameter_con_stimulate_retract_gear_valve, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_con_stimulate_retract_gear_valve(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.con_stimulate_retract_gear_valve();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_con_stimulate_retract_gear_valve();
                            _OpCache_with_parameter_con_stimulate_retract_gear_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_con_stimulate_retract_gear_valve, readState, writeState);
                            _OpCache_con_stimulate_retract_gear_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_con_stimulate_retract_gear_valve, _trid_15, _OpCache_with_parameter_con_stimulate_retract_gear_valve);
                        }

                    } else {
                        copiedState.con_stimulate_retract_gear_valve();
                        copiedState.parent = state;
                        _ProjectionWrite_con_stimulate_retract_gear_valve writeState = copiedState._update_for_con_stimulate_retract_gear_valve();
                        _OpCache_with_parameter_con_stimulate_retract_gear_valve = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_con_stimulate_retract_gear_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_con_stimulate_retract_gear_valve, _trid_15, _OpCache_with_parameter_con_stimulate_retract_gear_valve);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve read__tr_con_stop_stimulate_retract_gear_valve_state = state._projected_state_for__tr_con_stop_stimulate_retract_gear_valve();
                Object _obj__trid_16 = GET.invoke(_OpCache_tr_con_stop_stimulate_retract_gear_valve, read__tr_con_stop_stimulate_retract_gear_valve_state);
                boolean _trid_16;
                if(_obj__trid_16 == null) {
                    _trid_16 = state._tr_con_stop_stimulate_retract_gear_valve();
                    _OpCache_tr_con_stop_stimulate_retract_gear_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_con_stop_stimulate_retract_gear_valve, read__tr_con_stop_stimulate_retract_gear_valve_state, _trid_16);
                } else {
                    _trid_16 = (boolean) _obj__trid_16;
                }
                if(_trid_16) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_con_stop_stimulate_retract_gear_valve readState = state._projected_state_for_con_stop_stimulate_retract_gear_valve();
                    PersistentHashMap _OpCache_with_parameter_con_stop_stimulate_retract_gear_valve = (PersistentHashMap) GET.invoke(_OpCache_con_stop_stimulate_retract_gear_valve, _trid_16);
                    if(_OpCache_with_parameter_con_stop_stimulate_retract_gear_valve != null) {
                        _ProjectionWrite_con_stop_stimulate_retract_gear_valve writeState = (_ProjectionWrite_con_stop_stimulate_retract_gear_valve) GET.invoke(_OpCache_with_parameter_con_stop_stimulate_retract_gear_valve, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_con_stop_stimulate_retract_gear_valve(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.con_stop_stimulate_retract_gear_valve();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_con_stop_stimulate_retract_gear_valve();
                            _OpCache_with_parameter_con_stop_stimulate_retract_gear_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_con_stop_stimulate_retract_gear_valve, readState, writeState);
                            _OpCache_con_stop_stimulate_retract_gear_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_con_stop_stimulate_retract_gear_valve, _trid_16, _OpCache_with_parameter_con_stop_stimulate_retract_gear_valve);
                        }

                    } else {
                        copiedState.con_stop_stimulate_retract_gear_valve();
                        copiedState.parent = state;
                        _ProjectionWrite_con_stop_stimulate_retract_gear_valve writeState = copiedState._update_for_con_stop_stimulate_retract_gear_valve();
                        _OpCache_with_parameter_con_stop_stimulate_retract_gear_valve = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_con_stop_stimulate_retract_gear_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_con_stop_stimulate_retract_gear_valve, _trid_16, _OpCache_with_parameter_con_stop_stimulate_retract_gear_valve);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_con_stimulate_extend_gear_valve read__tr_con_stimulate_extend_gear_valve_state = state._projected_state_for__tr_con_stimulate_extend_gear_valve();
                Object _obj__trid_17 = GET.invoke(_OpCache_tr_con_stimulate_extend_gear_valve, read__tr_con_stimulate_extend_gear_valve_state);
                boolean _trid_17;
                if(_obj__trid_17 == null) {
                    _trid_17 = state._tr_con_stimulate_extend_gear_valve();
                    _OpCache_tr_con_stimulate_extend_gear_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_con_stimulate_extend_gear_valve, read__tr_con_stimulate_extend_gear_valve_state, _trid_17);
                } else {
                    _trid_17 = (boolean) _obj__trid_17;
                }
                if(_trid_17) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_con_stimulate_extend_gear_valve readState = state._projected_state_for_con_stimulate_extend_gear_valve();
                    PersistentHashMap _OpCache_with_parameter_con_stimulate_extend_gear_valve = (PersistentHashMap) GET.invoke(_OpCache_con_stimulate_extend_gear_valve, _trid_17);
                    if(_OpCache_with_parameter_con_stimulate_extend_gear_valve != null) {
                        _ProjectionWrite_con_stimulate_extend_gear_valve writeState = (_ProjectionWrite_con_stimulate_extend_gear_valve) GET.invoke(_OpCache_with_parameter_con_stimulate_extend_gear_valve, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_con_stimulate_extend_gear_valve(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.con_stimulate_extend_gear_valve();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_con_stimulate_extend_gear_valve();
                            _OpCache_with_parameter_con_stimulate_extend_gear_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_con_stimulate_extend_gear_valve, readState, writeState);
                            _OpCache_con_stimulate_extend_gear_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_con_stimulate_extend_gear_valve, _trid_17, _OpCache_with_parameter_con_stimulate_extend_gear_valve);
                        }

                    } else {
                        copiedState.con_stimulate_extend_gear_valve();
                        copiedState.parent = state;
                        _ProjectionWrite_con_stimulate_extend_gear_valve writeState = copiedState._update_for_con_stimulate_extend_gear_valve();
                        _OpCache_with_parameter_con_stimulate_extend_gear_valve = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_con_stimulate_extend_gear_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_con_stimulate_extend_gear_valve, _trid_17, _OpCache_with_parameter_con_stimulate_extend_gear_valve);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve read__tr_con_stop_stimulate_extend_gear_valve_state = state._projected_state_for__tr_con_stop_stimulate_extend_gear_valve();
                Object _obj__trid_18 = GET.invoke(_OpCache_tr_con_stop_stimulate_extend_gear_valve, read__tr_con_stop_stimulate_extend_gear_valve_state);
                boolean _trid_18;
                if(_obj__trid_18 == null) {
                    _trid_18 = state._tr_con_stop_stimulate_extend_gear_valve();
                    _OpCache_tr_con_stop_stimulate_extend_gear_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_con_stop_stimulate_extend_gear_valve, read__tr_con_stop_stimulate_extend_gear_valve_state, _trid_18);
                } else {
                    _trid_18 = (boolean) _obj__trid_18;
                }
                if(_trid_18) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_con_stop_stimulate_extend_gear_valve readState = state._projected_state_for_con_stop_stimulate_extend_gear_valve();
                    PersistentHashMap _OpCache_with_parameter_con_stop_stimulate_extend_gear_valve = (PersistentHashMap) GET.invoke(_OpCache_con_stop_stimulate_extend_gear_valve, _trid_18);
                    if(_OpCache_with_parameter_con_stop_stimulate_extend_gear_valve != null) {
                        _ProjectionWrite_con_stop_stimulate_extend_gear_valve writeState = (_ProjectionWrite_con_stop_stimulate_extend_gear_valve) GET.invoke(_OpCache_with_parameter_con_stop_stimulate_extend_gear_valve, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_con_stop_stimulate_extend_gear_valve(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.con_stop_stimulate_extend_gear_valve();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_con_stop_stimulate_extend_gear_valve();
                            _OpCache_with_parameter_con_stop_stimulate_extend_gear_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_con_stop_stimulate_extend_gear_valve, readState, writeState);
                            _OpCache_con_stop_stimulate_extend_gear_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_con_stop_stimulate_extend_gear_valve, _trid_18, _OpCache_with_parameter_con_stop_stimulate_extend_gear_valve);
                        }

                    } else {
                        copiedState.con_stop_stimulate_extend_gear_valve();
                        copiedState.parent = state;
                        _ProjectionWrite_con_stop_stimulate_extend_gear_valve writeState = copiedState._update_for_con_stop_stimulate_extend_gear_valve();
                        _OpCache_with_parameter_con_stop_stimulate_extend_gear_valve = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_con_stop_stimulate_extend_gear_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_con_stop_stimulate_extend_gear_valve, _trid_18, _OpCache_with_parameter_con_stop_stimulate_extend_gear_valve);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_env_start_retracting_first read__tr_env_start_retracting_first_state = state._projected_state_for__tr_env_start_retracting_first();
                BSet<POSITION> _trid_19 = (BSet<POSITION>) GET.invoke(_OpCache_tr_env_start_retracting_first, read__tr_env_start_retracting_first_state);
                if(_trid_19 == null) {
                    _trid_19 = state._tr_env_start_retracting_first();
                    _OpCache_tr_env_start_retracting_first = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_env_start_retracting_first, read__tr_env_start_retracting_first_state, _trid_19);
                }
                for(POSITION param : _trid_19) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_env_start_retracting_first readState = state._projected_state_for_env_start_retracting_first();
                    PersistentHashMap _OpCache_with_parameter_env_start_retracting_first = (PersistentHashMap) GET.invoke(_OpCache_env_start_retracting_first, param);
                    if(_OpCache_with_parameter_env_start_retracting_first != null) {
                        _ProjectionWrite_env_start_retracting_first writeState = (_ProjectionWrite_env_start_retracting_first) GET.invoke(_OpCache_with_parameter_env_start_retracting_first, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_env_start_retracting_first(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.env_start_retracting_first(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_env_start_retracting_first();
                            _OpCache_with_parameter_env_start_retracting_first = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_env_start_retracting_first, readState, writeState);
                            _OpCache_env_start_retracting_first = (PersistentHashMap) ASSOC.invoke(_OpCache_env_start_retracting_first, param, _OpCache_with_parameter_env_start_retracting_first);
                        }

                    } else {
                        copiedState.env_start_retracting_first(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_env_start_retracting_first writeState = copiedState._update_for_env_start_retracting_first();
                        _OpCache_with_parameter_env_start_retracting_first = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_env_start_retracting_first = (PersistentHashMap) ASSOC.invoke(_OpCache_env_start_retracting_first, param, _OpCache_with_parameter_env_start_retracting_first);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_env_retract_gear_skip read__tr_env_retract_gear_skip_state = state._projected_state_for__tr_env_retract_gear_skip();
                BSet<POSITION> _trid_20 = (BSet<POSITION>) GET.invoke(_OpCache_tr_env_retract_gear_skip, read__tr_env_retract_gear_skip_state);
                if(_trid_20 == null) {
                    _trid_20 = state._tr_env_retract_gear_skip();
                    _OpCache_tr_env_retract_gear_skip = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_env_retract_gear_skip, read__tr_env_retract_gear_skip_state, _trid_20);
                }
                for(POSITION param : _trid_20) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_env_retract_gear_skip readState = state._projected_state_for_env_retract_gear_skip();
                    PersistentHashMap _OpCache_with_parameter_env_retract_gear_skip = (PersistentHashMap) GET.invoke(_OpCache_env_retract_gear_skip, param);
                    if(_OpCache_with_parameter_env_retract_gear_skip != null) {
                        _ProjectionWrite_env_retract_gear_skip writeState = (_ProjectionWrite_env_retract_gear_skip) GET.invoke(_OpCache_with_parameter_env_retract_gear_skip, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_env_retract_gear_skip(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.env_retract_gear_skip(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_env_retract_gear_skip();
                            _OpCache_with_parameter_env_retract_gear_skip = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_env_retract_gear_skip, readState, writeState);
                            _OpCache_env_retract_gear_skip = (PersistentHashMap) ASSOC.invoke(_OpCache_env_retract_gear_skip, param, _OpCache_with_parameter_env_retract_gear_skip);
                        }

                    } else {
                        copiedState.env_retract_gear_skip(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_env_retract_gear_skip writeState = copiedState._update_for_env_retract_gear_skip();
                        _OpCache_with_parameter_env_retract_gear_skip = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_env_retract_gear_skip = (PersistentHashMap) ASSOC.invoke(_OpCache_env_retract_gear_skip, param, _OpCache_with_parameter_env_retract_gear_skip);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_env_retract_gear_last read__tr_env_retract_gear_last_state = state._projected_state_for__tr_env_retract_gear_last();
                BSet<POSITION> _trid_21 = (BSet<POSITION>) GET.invoke(_OpCache_tr_env_retract_gear_last, read__tr_env_retract_gear_last_state);
                if(_trid_21 == null) {
                    _trid_21 = state._tr_env_retract_gear_last();
                    _OpCache_tr_env_retract_gear_last = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_env_retract_gear_last, read__tr_env_retract_gear_last_state, _trid_21);
                }
                for(POSITION param : _trid_21) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_env_retract_gear_last readState = state._projected_state_for_env_retract_gear_last();
                    PersistentHashMap _OpCache_with_parameter_env_retract_gear_last = (PersistentHashMap) GET.invoke(_OpCache_env_retract_gear_last, param);
                    if(_OpCache_with_parameter_env_retract_gear_last != null) {
                        _ProjectionWrite_env_retract_gear_last writeState = (_ProjectionWrite_env_retract_gear_last) GET.invoke(_OpCache_with_parameter_env_retract_gear_last, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_env_retract_gear_last(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.env_retract_gear_last(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_env_retract_gear_last();
                            _OpCache_with_parameter_env_retract_gear_last = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_env_retract_gear_last, readState, writeState);
                            _OpCache_env_retract_gear_last = (PersistentHashMap) ASSOC.invoke(_OpCache_env_retract_gear_last, param, _OpCache_with_parameter_env_retract_gear_last);
                        }

                    } else {
                        copiedState.env_retract_gear_last(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_env_retract_gear_last writeState = copiedState._update_for_env_retract_gear_last();
                        _OpCache_with_parameter_env_retract_gear_last = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_env_retract_gear_last = (PersistentHashMap) ASSOC.invoke(_OpCache_env_retract_gear_last, param, _OpCache_with_parameter_env_retract_gear_last);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_env_start_extending read__tr_env_start_extending_state = state._projected_state_for__tr_env_start_extending();
                BSet<POSITION> _trid_22 = (BSet<POSITION>) GET.invoke(_OpCache_tr_env_start_extending, read__tr_env_start_extending_state);
                if(_trid_22 == null) {
                    _trid_22 = state._tr_env_start_extending();
                    _OpCache_tr_env_start_extending = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_env_start_extending, read__tr_env_start_extending_state, _trid_22);
                }
                for(POSITION param : _trid_22) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_env_start_extending readState = state._projected_state_for_env_start_extending();
                    PersistentHashMap _OpCache_with_parameter_env_start_extending = (PersistentHashMap) GET.invoke(_OpCache_env_start_extending, param);
                    if(_OpCache_with_parameter_env_start_extending != null) {
                        _ProjectionWrite_env_start_extending writeState = (_ProjectionWrite_env_start_extending) GET.invoke(_OpCache_with_parameter_env_start_extending, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_env_start_extending(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.env_start_extending(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_env_start_extending();
                            _OpCache_with_parameter_env_start_extending = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_env_start_extending, readState, writeState);
                            _OpCache_env_start_extending = (PersistentHashMap) ASSOC.invoke(_OpCache_env_start_extending, param, _OpCache_with_parameter_env_start_extending);
                        }

                    } else {
                        copiedState.env_start_extending(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_env_start_extending writeState = copiedState._update_for_env_start_extending();
                        _OpCache_with_parameter_env_start_extending = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_env_start_extending = (PersistentHashMap) ASSOC.invoke(_OpCache_env_start_extending, param, _OpCache_with_parameter_env_start_extending);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_env_extend_gear_last read__tr_env_extend_gear_last_state = state._projected_state_for__tr_env_extend_gear_last();
                BSet<POSITION> _trid_23 = (BSet<POSITION>) GET.invoke(_OpCache_tr_env_extend_gear_last, read__tr_env_extend_gear_last_state);
                if(_trid_23 == null) {
                    _trid_23 = state._tr_env_extend_gear_last();
                    _OpCache_tr_env_extend_gear_last = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_env_extend_gear_last, read__tr_env_extend_gear_last_state, _trid_23);
                }
                for(POSITION param : _trid_23) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_env_extend_gear_last readState = state._projected_state_for_env_extend_gear_last();
                    PersistentHashMap _OpCache_with_parameter_env_extend_gear_last = (PersistentHashMap) GET.invoke(_OpCache_env_extend_gear_last, param);
                    if(_OpCache_with_parameter_env_extend_gear_last != null) {
                        _ProjectionWrite_env_extend_gear_last writeState = (_ProjectionWrite_env_extend_gear_last) GET.invoke(_OpCache_with_parameter_env_extend_gear_last, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_env_extend_gear_last(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.env_extend_gear_last(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_env_extend_gear_last();
                            _OpCache_with_parameter_env_extend_gear_last = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_env_extend_gear_last, readState, writeState);
                            _OpCache_env_extend_gear_last = (PersistentHashMap) ASSOC.invoke(_OpCache_env_extend_gear_last, param, _OpCache_with_parameter_env_extend_gear_last);
                        }

                    } else {
                        copiedState.env_extend_gear_last(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_env_extend_gear_last writeState = copiedState._update_for_env_extend_gear_last();
                        _OpCache_with_parameter_env_extend_gear_last = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_env_extend_gear_last = (PersistentHashMap) ASSOC.invoke(_OpCache_env_extend_gear_last, param, _OpCache_with_parameter_env_extend_gear_last);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_env_extend_gear_skip read__tr_env_extend_gear_skip_state = state._projected_state_for__tr_env_extend_gear_skip();
                BSet<POSITION> _trid_24 = (BSet<POSITION>) GET.invoke(_OpCache_tr_env_extend_gear_skip, read__tr_env_extend_gear_skip_state);
                if(_trid_24 == null) {
                    _trid_24 = state._tr_env_extend_gear_skip();
                    _OpCache_tr_env_extend_gear_skip = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_env_extend_gear_skip, read__tr_env_extend_gear_skip_state, _trid_24);
                }
                for(POSITION param : _trid_24) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_env_extend_gear_skip readState = state._projected_state_for_env_extend_gear_skip();
                    PersistentHashMap _OpCache_with_parameter_env_extend_gear_skip = (PersistentHashMap) GET.invoke(_OpCache_env_extend_gear_skip, param);
                    if(_OpCache_with_parameter_env_extend_gear_skip != null) {
                        _ProjectionWrite_env_extend_gear_skip writeState = (_ProjectionWrite_env_extend_gear_skip) GET.invoke(_OpCache_with_parameter_env_extend_gear_skip, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_env_extend_gear_skip(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.env_extend_gear_skip(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_env_extend_gear_skip();
                            _OpCache_with_parameter_env_extend_gear_skip = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_env_extend_gear_skip, readState, writeState);
                            _OpCache_env_extend_gear_skip = (PersistentHashMap) ASSOC.invoke(_OpCache_env_extend_gear_skip, param, _OpCache_with_parameter_env_extend_gear_skip);
                        }

                    } else {
                        copiedState.env_extend_gear_skip(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_env_extend_gear_skip writeState = copiedState._update_for_env_extend_gear_skip();
                        _OpCache_with_parameter_env_extend_gear_skip = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_env_extend_gear_skip = (PersistentHashMap) ASSOC.invoke(_OpCache_env_extend_gear_skip, param, _OpCache_with_parameter_env_extend_gear_skip);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_env_start_open_door read__tr_env_start_open_door_state = state._projected_state_for__tr_env_start_open_door();
                BSet<POSITION> _trid_25 = (BSet<POSITION>) GET.invoke(_OpCache_tr_env_start_open_door, read__tr_env_start_open_door_state);
                if(_trid_25 == null) {
                    _trid_25 = state._tr_env_start_open_door();
                    _OpCache_tr_env_start_open_door = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_env_start_open_door, read__tr_env_start_open_door_state, _trid_25);
                }
                for(POSITION param : _trid_25) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_env_start_open_door readState = state._projected_state_for_env_start_open_door();
                    PersistentHashMap _OpCache_with_parameter_env_start_open_door = (PersistentHashMap) GET.invoke(_OpCache_env_start_open_door, param);
                    if(_OpCache_with_parameter_env_start_open_door != null) {
                        _ProjectionWrite_env_start_open_door writeState = (_ProjectionWrite_env_start_open_door) GET.invoke(_OpCache_with_parameter_env_start_open_door, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_env_start_open_door(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.env_start_open_door(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_env_start_open_door();
                            _OpCache_with_parameter_env_start_open_door = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_env_start_open_door, readState, writeState);
                            _OpCache_env_start_open_door = (PersistentHashMap) ASSOC.invoke(_OpCache_env_start_open_door, param, _OpCache_with_parameter_env_start_open_door);
                        }

                    } else {
                        copiedState.env_start_open_door(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_env_start_open_door writeState = copiedState._update_for_env_start_open_door();
                        _OpCache_with_parameter_env_start_open_door = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_env_start_open_door = (PersistentHashMap) ASSOC.invoke(_OpCache_env_start_open_door, param, _OpCache_with_parameter_env_start_open_door);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_env_open_door_last read__tr_env_open_door_last_state = state._projected_state_for__tr_env_open_door_last();
                BSet<POSITION> _trid_26 = (BSet<POSITION>) GET.invoke(_OpCache_tr_env_open_door_last, read__tr_env_open_door_last_state);
                if(_trid_26 == null) {
                    _trid_26 = state._tr_env_open_door_last();
                    _OpCache_tr_env_open_door_last = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_env_open_door_last, read__tr_env_open_door_last_state, _trid_26);
                }
                for(POSITION param : _trid_26) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_env_open_door_last readState = state._projected_state_for_env_open_door_last();
                    PersistentHashMap _OpCache_with_parameter_env_open_door_last = (PersistentHashMap) GET.invoke(_OpCache_env_open_door_last, param);
                    if(_OpCache_with_parameter_env_open_door_last != null) {
                        _ProjectionWrite_env_open_door_last writeState = (_ProjectionWrite_env_open_door_last) GET.invoke(_OpCache_with_parameter_env_open_door_last, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_env_open_door_last(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.env_open_door_last(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_env_open_door_last();
                            _OpCache_with_parameter_env_open_door_last = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_env_open_door_last, readState, writeState);
                            _OpCache_env_open_door_last = (PersistentHashMap) ASSOC.invoke(_OpCache_env_open_door_last, param, _OpCache_with_parameter_env_open_door_last);
                        }

                    } else {
                        copiedState.env_open_door_last(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_env_open_door_last writeState = copiedState._update_for_env_open_door_last();
                        _OpCache_with_parameter_env_open_door_last = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_env_open_door_last = (PersistentHashMap) ASSOC.invoke(_OpCache_env_open_door_last, param, _OpCache_with_parameter_env_open_door_last);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_env_open_door_skip read__tr_env_open_door_skip_state = state._projected_state_for__tr_env_open_door_skip();
                BSet<POSITION> _trid_27 = (BSet<POSITION>) GET.invoke(_OpCache_tr_env_open_door_skip, read__tr_env_open_door_skip_state);
                if(_trid_27 == null) {
                    _trid_27 = state._tr_env_open_door_skip();
                    _OpCache_tr_env_open_door_skip = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_env_open_door_skip, read__tr_env_open_door_skip_state, _trid_27);
                }
                for(POSITION param : _trid_27) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_env_open_door_skip readState = state._projected_state_for_env_open_door_skip();
                    PersistentHashMap _OpCache_with_parameter_env_open_door_skip = (PersistentHashMap) GET.invoke(_OpCache_env_open_door_skip, param);
                    if(_OpCache_with_parameter_env_open_door_skip != null) {
                        _ProjectionWrite_env_open_door_skip writeState = (_ProjectionWrite_env_open_door_skip) GET.invoke(_OpCache_with_parameter_env_open_door_skip, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_env_open_door_skip(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.env_open_door_skip(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_env_open_door_skip();
                            _OpCache_with_parameter_env_open_door_skip = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_env_open_door_skip, readState, writeState);
                            _OpCache_env_open_door_skip = (PersistentHashMap) ASSOC.invoke(_OpCache_env_open_door_skip, param, _OpCache_with_parameter_env_open_door_skip);
                        }

                    } else {
                        copiedState.env_open_door_skip(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_env_open_door_skip writeState = copiedState._update_for_env_open_door_skip();
                        _OpCache_with_parameter_env_open_door_skip = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_env_open_door_skip = (PersistentHashMap) ASSOC.invoke(_OpCache_env_open_door_skip, param, _OpCache_with_parameter_env_open_door_skip);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_env_start_close_door read__tr_env_start_close_door_state = state._projected_state_for__tr_env_start_close_door();
                BSet<POSITION> _trid_28 = (BSet<POSITION>) GET.invoke(_OpCache_tr_env_start_close_door, read__tr_env_start_close_door_state);
                if(_trid_28 == null) {
                    _trid_28 = state._tr_env_start_close_door();
                    _OpCache_tr_env_start_close_door = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_env_start_close_door, read__tr_env_start_close_door_state, _trid_28);
                }
                for(POSITION param : _trid_28) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_env_start_close_door readState = state._projected_state_for_env_start_close_door();
                    PersistentHashMap _OpCache_with_parameter_env_start_close_door = (PersistentHashMap) GET.invoke(_OpCache_env_start_close_door, param);
                    if(_OpCache_with_parameter_env_start_close_door != null) {
                        _ProjectionWrite_env_start_close_door writeState = (_ProjectionWrite_env_start_close_door) GET.invoke(_OpCache_with_parameter_env_start_close_door, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_env_start_close_door(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.env_start_close_door(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_env_start_close_door();
                            _OpCache_with_parameter_env_start_close_door = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_env_start_close_door, readState, writeState);
                            _OpCache_env_start_close_door = (PersistentHashMap) ASSOC.invoke(_OpCache_env_start_close_door, param, _OpCache_with_parameter_env_start_close_door);
                        }

                    } else {
                        copiedState.env_start_close_door(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_env_start_close_door writeState = copiedState._update_for_env_start_close_door();
                        _OpCache_with_parameter_env_start_close_door = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_env_start_close_door = (PersistentHashMap) ASSOC.invoke(_OpCache_env_start_close_door, param, _OpCache_with_parameter_env_start_close_door);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_env_close_door read__tr_env_close_door_state = state._projected_state_for__tr_env_close_door();
                BSet<POSITION> _trid_29 = (BSet<POSITION>) GET.invoke(_OpCache_tr_env_close_door, read__tr_env_close_door_state);
                if(_trid_29 == null) {
                    _trid_29 = state._tr_env_close_door();
                    _OpCache_tr_env_close_door = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_env_close_door, read__tr_env_close_door_state, _trid_29);
                }
                for(POSITION param : _trid_29) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_env_close_door readState = state._projected_state_for_env_close_door();
                    PersistentHashMap _OpCache_with_parameter_env_close_door = (PersistentHashMap) GET.invoke(_OpCache_env_close_door, param);
                    if(_OpCache_with_parameter_env_close_door != null) {
                        _ProjectionWrite_env_close_door writeState = (_ProjectionWrite_env_close_door) GET.invoke(_OpCache_with_parameter_env_close_door, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_env_close_door(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.env_close_door(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_env_close_door();
                            _OpCache_with_parameter_env_close_door = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_env_close_door, readState, writeState);
                            _OpCache_env_close_door = (PersistentHashMap) ASSOC.invoke(_OpCache_env_close_door, param, _OpCache_with_parameter_env_close_door);
                        }

                    } else {
                        copiedState.env_close_door(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_env_close_door writeState = copiedState._update_for_env_close_door();
                        _OpCache_with_parameter_env_close_door = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_env_close_door = (PersistentHashMap) ASSOC.invoke(_OpCache_env_close_door, param, _OpCache_with_parameter_env_close_door);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_env_close_door_skip read__tr_env_close_door_skip_state = state._projected_state_for__tr_env_close_door_skip();
                BSet<POSITION> _trid_30 = (BSet<POSITION>) GET.invoke(_OpCache_tr_env_close_door_skip, read__tr_env_close_door_skip_state);
                if(_trid_30 == null) {
                    _trid_30 = state._tr_env_close_door_skip();
                    _OpCache_tr_env_close_door_skip = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_env_close_door_skip, read__tr_env_close_door_skip_state, _trid_30);
                }
                for(POSITION param : _trid_30) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_env_close_door_skip readState = state._projected_state_for_env_close_door_skip();
                    PersistentHashMap _OpCache_with_parameter_env_close_door_skip = (PersistentHashMap) GET.invoke(_OpCache_env_close_door_skip, param);
                    if(_OpCache_with_parameter_env_close_door_skip != null) {
                        _ProjectionWrite_env_close_door_skip writeState = (_ProjectionWrite_env_close_door_skip) GET.invoke(_OpCache_with_parameter_env_close_door_skip, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_env_close_door_skip(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.env_close_door_skip(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_env_close_door_skip();
                            _OpCache_with_parameter_env_close_door_skip = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_env_close_door_skip, readState, writeState);
                            _OpCache_env_close_door_skip = (PersistentHashMap) ASSOC.invoke(_OpCache_env_close_door_skip, param, _OpCache_with_parameter_env_close_door_skip);
                        }

                    } else {
                        copiedState.env_close_door_skip(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_env_close_door_skip writeState = copiedState._update_for_env_close_door_skip();
                        _OpCache_with_parameter_env_close_door_skip = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_env_close_door_skip = (PersistentHashMap) ASSOC.invoke(_OpCache_env_close_door_skip, param, _OpCache_with_parameter_env_close_door_skip);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_toggle_handle_up read__tr_toggle_handle_up_state = state._projected_state_for__tr_toggle_handle_up();
                Object _obj__trid_31 = GET.invoke(_OpCache_tr_toggle_handle_up, read__tr_toggle_handle_up_state);
                boolean _trid_31;
                if(_obj__trid_31 == null) {
                    _trid_31 = state._tr_toggle_handle_up();
                    _OpCache_tr_toggle_handle_up = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_toggle_handle_up, read__tr_toggle_handle_up_state, _trid_31);
                } else {
                    _trid_31 = (boolean) _obj__trid_31;
                }
                if(_trid_31) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_toggle_handle_up readState = state._projected_state_for_toggle_handle_up();
                    PersistentHashMap _OpCache_with_parameter_toggle_handle_up = (PersistentHashMap) GET.invoke(_OpCache_toggle_handle_up, _trid_31);
                    if(_OpCache_with_parameter_toggle_handle_up != null) {
                        _ProjectionWrite_toggle_handle_up writeState = (_ProjectionWrite_toggle_handle_up) GET.invoke(_OpCache_with_parameter_toggle_handle_up, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_toggle_handle_up(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.toggle_handle_up();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_toggle_handle_up();
                            _OpCache_with_parameter_toggle_handle_up = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_toggle_handle_up, readState, writeState);
                            _OpCache_toggle_handle_up = (PersistentHashMap) ASSOC.invoke(_OpCache_toggle_handle_up, _trid_31, _OpCache_with_parameter_toggle_handle_up);
                        }

                    } else {
                        copiedState.toggle_handle_up();
                        copiedState.parent = state;
                        _ProjectionWrite_toggle_handle_up writeState = copiedState._update_for_toggle_handle_up();
                        _OpCache_with_parameter_toggle_handle_up = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_toggle_handle_up = (PersistentHashMap) ASSOC.invoke(_OpCache_toggle_handle_up, _trid_31, _OpCache_with_parameter_toggle_handle_up);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_toggle_handle_down read__tr_toggle_handle_down_state = state._projected_state_for__tr_toggle_handle_down();
                Object _obj__trid_32 = GET.invoke(_OpCache_tr_toggle_handle_down, read__tr_toggle_handle_down_state);
                boolean _trid_32;
                if(_obj__trid_32 == null) {
                    _trid_32 = state._tr_toggle_handle_down();
                    _OpCache_tr_toggle_handle_down = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_toggle_handle_down, read__tr_toggle_handle_down_state, _trid_32);
                } else {
                    _trid_32 = (boolean) _obj__trid_32;
                }
                if(_trid_32) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_toggle_handle_down readState = state._projected_state_for_toggle_handle_down();
                    PersistentHashMap _OpCache_with_parameter_toggle_handle_down = (PersistentHashMap) GET.invoke(_OpCache_toggle_handle_down, _trid_32);
                    if(_OpCache_with_parameter_toggle_handle_down != null) {
                        _ProjectionWrite_toggle_handle_down writeState = (_ProjectionWrite_toggle_handle_down) GET.invoke(_OpCache_with_parameter_toggle_handle_down, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_toggle_handle_down(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.toggle_handle_down();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_toggle_handle_down();
                            _OpCache_with_parameter_toggle_handle_down = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_toggle_handle_down, readState, writeState);
                            _OpCache_toggle_handle_down = (PersistentHashMap) ASSOC.invoke(_OpCache_toggle_handle_down, _trid_32, _OpCache_with_parameter_toggle_handle_down);
                        }

                    } else {
                        copiedState.toggle_handle_down();
                        copiedState.parent = state;
                        _ProjectionWrite_toggle_handle_down writeState = copiedState._update_for_toggle_handle_down();
                        _OpCache_with_parameter_toggle_handle_down = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_toggle_handle_down = (PersistentHashMap) ASSOC.invoke(_OpCache_toggle_handle_down, _trid_32, _OpCache_with_parameter_toggle_handle_down);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_con_stimulate_general_valve read__tr_con_stimulate_general_valve_state = state._projected_state_for__tr_con_stimulate_general_valve();
                Object _obj__trid_33 = GET.invoke(_OpCache_tr_con_stimulate_general_valve, read__tr_con_stimulate_general_valve_state);
                boolean _trid_33;
                if(_obj__trid_33 == null) {
                    _trid_33 = state._tr_con_stimulate_general_valve();
                    _OpCache_tr_con_stimulate_general_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_con_stimulate_general_valve, read__tr_con_stimulate_general_valve_state, _trid_33);
                } else {
                    _trid_33 = (boolean) _obj__trid_33;
                }
                if(_trid_33) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_con_stimulate_general_valve readState = state._projected_state_for_con_stimulate_general_valve();
                    PersistentHashMap _OpCache_with_parameter_con_stimulate_general_valve = (PersistentHashMap) GET.invoke(_OpCache_con_stimulate_general_valve, _trid_33);
                    if(_OpCache_with_parameter_con_stimulate_general_valve != null) {
                        _ProjectionWrite_con_stimulate_general_valve writeState = (_ProjectionWrite_con_stimulate_general_valve) GET.invoke(_OpCache_with_parameter_con_stimulate_general_valve, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_con_stimulate_general_valve(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.con_stimulate_general_valve();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_con_stimulate_general_valve();
                            _OpCache_with_parameter_con_stimulate_general_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_con_stimulate_general_valve, readState, writeState);
                            _OpCache_con_stimulate_general_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_con_stimulate_general_valve, _trid_33, _OpCache_with_parameter_con_stimulate_general_valve);
                        }

                    } else {
                        copiedState.con_stimulate_general_valve();
                        copiedState.parent = state;
                        _ProjectionWrite_con_stimulate_general_valve writeState = copiedState._update_for_con_stimulate_general_valve();
                        _OpCache_with_parameter_con_stimulate_general_valve = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_con_stimulate_general_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_con_stimulate_general_valve, _trid_33, _OpCache_with_parameter_con_stimulate_general_valve);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_con_stop_stimulate_general_valve read__tr_con_stop_stimulate_general_valve_state = state._projected_state_for__tr_con_stop_stimulate_general_valve();
                Object _obj__trid_34 = GET.invoke(_OpCache_tr_con_stop_stimulate_general_valve, read__tr_con_stop_stimulate_general_valve_state);
                boolean _trid_34;
                if(_obj__trid_34 == null) {
                    _trid_34 = state._tr_con_stop_stimulate_general_valve();
                    _OpCache_tr_con_stop_stimulate_general_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_con_stop_stimulate_general_valve, read__tr_con_stop_stimulate_general_valve_state, _trid_34);
                } else {
                    _trid_34 = (boolean) _obj__trid_34;
                }
                if(_trid_34) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_con_stop_stimulate_general_valve readState = state._projected_state_for_con_stop_stimulate_general_valve();
                    PersistentHashMap _OpCache_with_parameter_con_stop_stimulate_general_valve = (PersistentHashMap) GET.invoke(_OpCache_con_stop_stimulate_general_valve, _trid_34);
                    if(_OpCache_with_parameter_con_stop_stimulate_general_valve != null) {
                        _ProjectionWrite_con_stop_stimulate_general_valve writeState = (_ProjectionWrite_con_stop_stimulate_general_valve) GET.invoke(_OpCache_with_parameter_con_stop_stimulate_general_valve, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_con_stop_stimulate_general_valve(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.con_stop_stimulate_general_valve();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_con_stop_stimulate_general_valve();
                            _OpCache_with_parameter_con_stop_stimulate_general_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_con_stop_stimulate_general_valve, readState, writeState);
                            _OpCache_con_stop_stimulate_general_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_con_stop_stimulate_general_valve, _trid_34, _OpCache_with_parameter_con_stop_stimulate_general_valve);
                        }

                    } else {
                        copiedState.con_stop_stimulate_general_valve();
                        copiedState.parent = state;
                        _ProjectionWrite_con_stop_stimulate_general_valve writeState = copiedState._update_for_con_stop_stimulate_general_valve();
                        _OpCache_with_parameter_con_stop_stimulate_general_valve = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_con_stop_stimulate_general_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_con_stop_stimulate_general_valve, _trid_34, _OpCache_with_parameter_con_stop_stimulate_general_valve);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_evn_open_general_valve read__tr_evn_open_general_valve_state = state._projected_state_for__tr_evn_open_general_valve();
                Object _obj__trid_35 = GET.invoke(_OpCache_tr_evn_open_general_valve, read__tr_evn_open_general_valve_state);
                boolean _trid_35;
                if(_obj__trid_35 == null) {
                    _trid_35 = state._tr_evn_open_general_valve();
                    _OpCache_tr_evn_open_general_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_evn_open_general_valve, read__tr_evn_open_general_valve_state, _trid_35);
                } else {
                    _trid_35 = (boolean) _obj__trid_35;
                }
                if(_trid_35) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_evn_open_general_valve readState = state._projected_state_for_evn_open_general_valve();
                    PersistentHashMap _OpCache_with_parameter_evn_open_general_valve = (PersistentHashMap) GET.invoke(_OpCache_evn_open_general_valve, _trid_35);
                    if(_OpCache_with_parameter_evn_open_general_valve != null) {
                        _ProjectionWrite_evn_open_general_valve writeState = (_ProjectionWrite_evn_open_general_valve) GET.invoke(_OpCache_with_parameter_evn_open_general_valve, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_evn_open_general_valve(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.evn_open_general_valve();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_evn_open_general_valve();
                            _OpCache_with_parameter_evn_open_general_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_evn_open_general_valve, readState, writeState);
                            _OpCache_evn_open_general_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_evn_open_general_valve, _trid_35, _OpCache_with_parameter_evn_open_general_valve);
                        }

                    } else {
                        copiedState.evn_open_general_valve();
                        copiedState.parent = state;
                        _ProjectionWrite_evn_open_general_valve writeState = copiedState._update_for_evn_open_general_valve();
                        _OpCache_with_parameter_evn_open_general_valve = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_evn_open_general_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_evn_open_general_valve, _trid_35, _OpCache_with_parameter_evn_open_general_valve);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_evn_close_general_valve read__tr_evn_close_general_valve_state = state._projected_state_for__tr_evn_close_general_valve();
                Object _obj__trid_36 = GET.invoke(_OpCache_tr_evn_close_general_valve, read__tr_evn_close_general_valve_state);
                boolean _trid_36;
                if(_obj__trid_36 == null) {
                    _trid_36 = state._tr_evn_close_general_valve();
                    _OpCache_tr_evn_close_general_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_evn_close_general_valve, read__tr_evn_close_general_valve_state, _trid_36);
                } else {
                    _trid_36 = (boolean) _obj__trid_36;
                }
                if(_trid_36) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_evn_close_general_valve readState = state._projected_state_for_evn_close_general_valve();
                    PersistentHashMap _OpCache_with_parameter_evn_close_general_valve = (PersistentHashMap) GET.invoke(_OpCache_evn_close_general_valve, _trid_36);
                    if(_OpCache_with_parameter_evn_close_general_valve != null) {
                        _ProjectionWrite_evn_close_general_valve writeState = (_ProjectionWrite_evn_close_general_valve) GET.invoke(_OpCache_with_parameter_evn_close_general_valve, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_evn_close_general_valve(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.evn_close_general_valve();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_evn_close_general_valve();
                            _OpCache_with_parameter_evn_close_general_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_evn_close_general_valve, readState, writeState);
                            _OpCache_evn_close_general_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_evn_close_general_valve, _trid_36, _OpCache_with_parameter_evn_close_general_valve);
                        }

                    } else {
                        copiedState.evn_close_general_valve();
                        copiedState.parent = state;
                        _ProjectionWrite_evn_close_general_valve writeState = copiedState._update_for_evn_close_general_valve();
                        _OpCache_with_parameter_evn_close_general_valve = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_evn_close_general_valve = (PersistentHashMap) ASSOC.invoke(_OpCache_evn_close_general_valve, _trid_36, _OpCache_with_parameter_evn_close_general_valve);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_env_close_analogical_switch read__tr_env_close_analogical_switch_state = state._projected_state_for__tr_env_close_analogical_switch();
                Object _obj__trid_37 = GET.invoke(_OpCache_tr_env_close_analogical_switch, read__tr_env_close_analogical_switch_state);
                boolean _trid_37;
                if(_obj__trid_37 == null) {
                    _trid_37 = state._tr_env_close_analogical_switch();
                    _OpCache_tr_env_close_analogical_switch = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_env_close_analogical_switch, read__tr_env_close_analogical_switch_state, _trid_37);
                } else {
                    _trid_37 = (boolean) _obj__trid_37;
                }
                if(_trid_37) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_env_close_analogical_switch readState = state._projected_state_for_env_close_analogical_switch();
                    PersistentHashMap _OpCache_with_parameter_env_close_analogical_switch = (PersistentHashMap) GET.invoke(_OpCache_env_close_analogical_switch, _trid_37);
                    if(_OpCache_with_parameter_env_close_analogical_switch != null) {
                        _ProjectionWrite_env_close_analogical_switch writeState = (_ProjectionWrite_env_close_analogical_switch) GET.invoke(_OpCache_with_parameter_env_close_analogical_switch, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_env_close_analogical_switch(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.env_close_analogical_switch();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_env_close_analogical_switch();
                            _OpCache_with_parameter_env_close_analogical_switch = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_env_close_analogical_switch, readState, writeState);
                            _OpCache_env_close_analogical_switch = (PersistentHashMap) ASSOC.invoke(_OpCache_env_close_analogical_switch, _trid_37, _OpCache_with_parameter_env_close_analogical_switch);
                        }

                    } else {
                        copiedState.env_close_analogical_switch();
                        copiedState.parent = state;
                        _ProjectionWrite_env_close_analogical_switch writeState = copiedState._update_for_env_close_analogical_switch();
                        _OpCache_with_parameter_env_close_analogical_switch = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_env_close_analogical_switch = (PersistentHashMap) ASSOC.invoke(_OpCache_env_close_analogical_switch, _trid_37, _OpCache_with_parameter_env_close_analogical_switch);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_env_open_analogical_switch read__tr_env_open_analogical_switch_state = state._projected_state_for__tr_env_open_analogical_switch();
                Object _obj__trid_38 = GET.invoke(_OpCache_tr_env_open_analogical_switch, read__tr_env_open_analogical_switch_state);
                boolean _trid_38;
                if(_obj__trid_38 == null) {
                    _trid_38 = state._tr_env_open_analogical_switch();
                    _OpCache_tr_env_open_analogical_switch = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_env_open_analogical_switch, read__tr_env_open_analogical_switch_state, _trid_38);
                } else {
                    _trid_38 = (boolean) _obj__trid_38;
                }
                if(_trid_38) {
                    LandingGear_R6 copiedState = state._copy();
                    _ProjectionRead_env_open_analogical_switch readState = state._projected_state_for_env_open_analogical_switch();
                    PersistentHashMap _OpCache_with_parameter_env_open_analogical_switch = (PersistentHashMap) GET.invoke(_OpCache_env_open_analogical_switch, _trid_38);
                    if(_OpCache_with_parameter_env_open_analogical_switch != null) {
                        _ProjectionWrite_env_open_analogical_switch writeState = (_ProjectionWrite_env_open_analogical_switch) GET.invoke(_OpCache_with_parameter_env_open_analogical_switch, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_env_open_analogical_switch(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.env_open_analogical_switch();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_env_open_analogical_switch();
                            _OpCache_with_parameter_env_open_analogical_switch = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_env_open_analogical_switch, readState, writeState);
                            _OpCache_env_open_analogical_switch = (PersistentHashMap) ASSOC.invoke(_OpCache_env_open_analogical_switch, _trid_38, _OpCache_with_parameter_env_open_analogical_switch);
                        }

                    } else {
                        copiedState.env_open_analogical_switch();
                        copiedState.parent = state;
                        _ProjectionWrite_env_open_analogical_switch writeState = copiedState._update_for_env_open_analogical_switch();
                        _OpCache_with_parameter_env_open_analogical_switch = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_env_open_analogical_switch = (PersistentHashMap) ASSOC.invoke(_OpCache_env_open_analogical_switch, _trid_38, _OpCache_with_parameter_env_open_analogical_switch);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            } else {
                if(state._tr_begin_flying()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.begin_flying();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_land_plane()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.land_plane();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_open_valve_door_open()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.open_valve_door_open();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_close_valve_door_open()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.close_valve_door_open();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_open_valve_door_close()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.open_valve_door_close();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_close_valve_door_close()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.close_valve_door_close();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_open_valve_retract_gear()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.open_valve_retract_gear();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_close_valve_retract_gear()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.close_valve_retract_gear();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_open_valve_extend_gear()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.open_valve_extend_gear();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_close_valve_extend_gear()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.close_valve_extend_gear();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_con_stimulate_open_door_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.con_stimulate_open_door_valve();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_con_stop_stimulate_open_door_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.con_stop_stimulate_open_door_valve();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_con_stimulate_close_door_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.con_stimulate_close_door_valve();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_con_stop_stimulate_close_door_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.con_stop_stimulate_close_door_valve();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_con_stimulate_retract_gear_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.con_stimulate_retract_gear_valve();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_con_stop_stimulate_retract_gear_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.con_stop_stimulate_retract_gear_valve();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_con_stimulate_extend_gear_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.con_stimulate_extend_gear_valve();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_con_stop_stimulate_extend_gear_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.con_stop_stimulate_extend_gear_valve();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<POSITION> _trid_19 = state._tr_env_start_retracting_first();
                for(POSITION param : _trid_19) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_start_retracting_first(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<POSITION> _trid_20 = state._tr_env_retract_gear_skip();
                for(POSITION param : _trid_20) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_retract_gear_skip(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<POSITION> _trid_21 = state._tr_env_retract_gear_last();
                for(POSITION param : _trid_21) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_retract_gear_last(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<POSITION> _trid_22 = state._tr_env_start_extending();
                for(POSITION param : _trid_22) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_start_extending(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<POSITION> _trid_23 = state._tr_env_extend_gear_last();
                for(POSITION param : _trid_23) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_extend_gear_last(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<POSITION> _trid_24 = state._tr_env_extend_gear_skip();
                for(POSITION param : _trid_24) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_extend_gear_skip(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<POSITION> _trid_25 = state._tr_env_start_open_door();
                for(POSITION param : _trid_25) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_start_open_door(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<POSITION> _trid_26 = state._tr_env_open_door_last();
                for(POSITION param : _trid_26) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_open_door_last(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<POSITION> _trid_27 = state._tr_env_open_door_skip();
                for(POSITION param : _trid_27) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_open_door_skip(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<POSITION> _trid_28 = state._tr_env_start_close_door();
                for(POSITION param : _trid_28) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_start_close_door(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<POSITION> _trid_29 = state._tr_env_close_door();
                for(POSITION param : _trid_29) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_close_door(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<POSITION> _trid_30 = state._tr_env_close_door_skip();
                for(POSITION param : _trid_30) {
                    POSITION _tmp_1 = param;

                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_close_door_skip(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_toggle_handle_up()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.toggle_handle_up();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_toggle_handle_down()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.toggle_handle_down();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_con_stimulate_general_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.con_stimulate_general_valve();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_con_stop_stimulate_general_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.con_stop_stimulate_general_valve();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_evn_open_general_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.evn_open_general_valve();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_evn_close_general_valve()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.evn_close_general_valve();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_env_close_analogical_switch()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_close_analogical_switch();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_env_open_analogical_switch()) {
                    LandingGear_R6 copiedState = state._copy();
                    copiedState.env_open_analogical_switch();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            }
            return result;
        }

        private boolean invariantViolated(final LandingGear_R6 state) {
            boolean _check_inv_1;
            if(isCaching) {
                _ProjectionRead__check_inv_1 read__check_inv_1_state = state._projected_state_for__check_inv_1();
                Object _obj__check_inv_1 = GET.invoke(_InvCache__check_inv_1, read__check_inv_1_state);
                if(_obj__check_inv_1 == null) {
                    _check_inv_1 = state._check_inv_1();
                    _InvCache__check_inv_1 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_1, read__check_inv_1_state, _check_inv_1);
                } else {
                    _check_inv_1 = (boolean) _obj__check_inv_1;
                }
            } else {
                _check_inv_1 = state._check_inv_1();
            }
            if(!_check_inv_1) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_1");
                return true;
            }
            boolean _check_inv_2;
            if(isCaching) {
                _ProjectionRead__check_inv_2 read__check_inv_2_state = state._projected_state_for__check_inv_2();
                Object _obj__check_inv_2 = GET.invoke(_InvCache__check_inv_2, read__check_inv_2_state);
                if(_obj__check_inv_2 == null) {
                    _check_inv_2 = state._check_inv_2();
                    _InvCache__check_inv_2 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_2, read__check_inv_2_state, _check_inv_2);
                } else {
                    _check_inv_2 = (boolean) _obj__check_inv_2;
                }
            } else {
                _check_inv_2 = state._check_inv_2();
            }
            if(!_check_inv_2) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_2");
                return true;
            }
            boolean _check_inv_3;
            if(isCaching) {
                _ProjectionRead__check_inv_3 read__check_inv_3_state = state._projected_state_for__check_inv_3();
                Object _obj__check_inv_3 = GET.invoke(_InvCache__check_inv_3, read__check_inv_3_state);
                if(_obj__check_inv_3 == null) {
                    _check_inv_3 = state._check_inv_3();
                    _InvCache__check_inv_3 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_3, read__check_inv_3_state, _check_inv_3);
                } else {
                    _check_inv_3 = (boolean) _obj__check_inv_3;
                }
            } else {
                _check_inv_3 = state._check_inv_3();
            }
            if(!_check_inv_3) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_3");
                return true;
            }
            boolean _check_inv_4;
            if(isCaching) {
                _ProjectionRead__check_inv_4 read__check_inv_4_state = state._projected_state_for__check_inv_4();
                Object _obj__check_inv_4 = GET.invoke(_InvCache__check_inv_4, read__check_inv_4_state);
                if(_obj__check_inv_4 == null) {
                    _check_inv_4 = state._check_inv_4();
                    _InvCache__check_inv_4 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_4, read__check_inv_4_state, _check_inv_4);
                } else {
                    _check_inv_4 = (boolean) _obj__check_inv_4;
                }
            } else {
                _check_inv_4 = state._check_inv_4();
            }
            if(!_check_inv_4) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_4");
                return true;
            }
            boolean _check_inv_5;
            if(isCaching) {
                _ProjectionRead__check_inv_5 read__check_inv_5_state = state._projected_state_for__check_inv_5();
                Object _obj__check_inv_5 = GET.invoke(_InvCache__check_inv_5, read__check_inv_5_state);
                if(_obj__check_inv_5 == null) {
                    _check_inv_5 = state._check_inv_5();
                    _InvCache__check_inv_5 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_5, read__check_inv_5_state, _check_inv_5);
                } else {
                    _check_inv_5 = (boolean) _obj__check_inv_5;
                }
            } else {
                _check_inv_5 = state._check_inv_5();
            }
            if(!_check_inv_5) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_5");
                return true;
            }
            boolean _check_inv_6;
            if(isCaching) {
                _ProjectionRead__check_inv_6 read__check_inv_6_state = state._projected_state_for__check_inv_6();
                Object _obj__check_inv_6 = GET.invoke(_InvCache__check_inv_6, read__check_inv_6_state);
                if(_obj__check_inv_6 == null) {
                    _check_inv_6 = state._check_inv_6();
                    _InvCache__check_inv_6 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_6, read__check_inv_6_state, _check_inv_6);
                } else {
                    _check_inv_6 = (boolean) _obj__check_inv_6;
                }
            } else {
                _check_inv_6 = state._check_inv_6();
            }
            if(!_check_inv_6) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_6");
                return true;
            }
            boolean _check_inv_7;
            if(isCaching) {
                _ProjectionRead__check_inv_7 read__check_inv_7_state = state._projected_state_for__check_inv_7();
                Object _obj__check_inv_7 = GET.invoke(_InvCache__check_inv_7, read__check_inv_7_state);
                if(_obj__check_inv_7 == null) {
                    _check_inv_7 = state._check_inv_7();
                    _InvCache__check_inv_7 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_7, read__check_inv_7_state, _check_inv_7);
                } else {
                    _check_inv_7 = (boolean) _obj__check_inv_7;
                }
            } else {
                _check_inv_7 = state._check_inv_7();
            }
            if(!_check_inv_7) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_7");
                return true;
            }
            boolean _check_inv_8;
            if(isCaching) {
                _ProjectionRead__check_inv_8 read__check_inv_8_state = state._projected_state_for__check_inv_8();
                Object _obj__check_inv_8 = GET.invoke(_InvCache__check_inv_8, read__check_inv_8_state);
                if(_obj__check_inv_8 == null) {
                    _check_inv_8 = state._check_inv_8();
                    _InvCache__check_inv_8 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_8, read__check_inv_8_state, _check_inv_8);
                } else {
                    _check_inv_8 = (boolean) _obj__check_inv_8;
                }
            } else {
                _check_inv_8 = state._check_inv_8();
            }
            if(!_check_inv_8) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_8");
                return true;
            }
            boolean _check_inv_9;
            if(isCaching) {
                _ProjectionRead__check_inv_9 read__check_inv_9_state = state._projected_state_for__check_inv_9();
                Object _obj__check_inv_9 = GET.invoke(_InvCache__check_inv_9, read__check_inv_9_state);
                if(_obj__check_inv_9 == null) {
                    _check_inv_9 = state._check_inv_9();
                    _InvCache__check_inv_9 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_9, read__check_inv_9_state, _check_inv_9);
                } else {
                    _check_inv_9 = (boolean) _obj__check_inv_9;
                }
            } else {
                _check_inv_9 = state._check_inv_9();
            }
            if(!_check_inv_9) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_9");
                return true;
            }
            boolean _check_inv_10;
            if(isCaching) {
                _ProjectionRead__check_inv_10 read__check_inv_10_state = state._projected_state_for__check_inv_10();
                Object _obj__check_inv_10 = GET.invoke(_InvCache__check_inv_10, read__check_inv_10_state);
                if(_obj__check_inv_10 == null) {
                    _check_inv_10 = state._check_inv_10();
                    _InvCache__check_inv_10 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_10, read__check_inv_10_state, _check_inv_10);
                } else {
                    _check_inv_10 = (boolean) _obj__check_inv_10;
                }
            } else {
                _check_inv_10 = state._check_inv_10();
            }
            if(!_check_inv_10) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_10");
                return true;
            }
            boolean _check_inv_11;
            if(isCaching) {
                _ProjectionRead__check_inv_11 read__check_inv_11_state = state._projected_state_for__check_inv_11();
                Object _obj__check_inv_11 = GET.invoke(_InvCache__check_inv_11, read__check_inv_11_state);
                if(_obj__check_inv_11 == null) {
                    _check_inv_11 = state._check_inv_11();
                    _InvCache__check_inv_11 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_11, read__check_inv_11_state, _check_inv_11);
                } else {
                    _check_inv_11 = (boolean) _obj__check_inv_11;
                }
            } else {
                _check_inv_11 = state._check_inv_11();
            }
            if(!_check_inv_11) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_11");
                return true;
            }
            boolean _check_inv_12;
            if(isCaching) {
                _ProjectionRead__check_inv_12 read__check_inv_12_state = state._projected_state_for__check_inv_12();
                Object _obj__check_inv_12 = GET.invoke(_InvCache__check_inv_12, read__check_inv_12_state);
                if(_obj__check_inv_12 == null) {
                    _check_inv_12 = state._check_inv_12();
                    _InvCache__check_inv_12 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_12, read__check_inv_12_state, _check_inv_12);
                } else {
                    _check_inv_12 = (boolean) _obj__check_inv_12;
                }
            } else {
                _check_inv_12 = state._check_inv_12();
            }
            if(!_check_inv_12) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_12");
                return true;
            }
            boolean _check_inv_13;
            if(isCaching) {
                _ProjectionRead__check_inv_13 read__check_inv_13_state = state._projected_state_for__check_inv_13();
                Object _obj__check_inv_13 = GET.invoke(_InvCache__check_inv_13, read__check_inv_13_state);
                if(_obj__check_inv_13 == null) {
                    _check_inv_13 = state._check_inv_13();
                    _InvCache__check_inv_13 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_13, read__check_inv_13_state, _check_inv_13);
                } else {
                    _check_inv_13 = (boolean) _obj__check_inv_13;
                }
            } else {
                _check_inv_13 = state._check_inv_13();
            }
            if(!_check_inv_13) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_13");
                return true;
            }
            boolean _check_inv_14;
            if(isCaching) {
                _ProjectionRead__check_inv_14 read__check_inv_14_state = state._projected_state_for__check_inv_14();
                Object _obj__check_inv_14 = GET.invoke(_InvCache__check_inv_14, read__check_inv_14_state);
                if(_obj__check_inv_14 == null) {
                    _check_inv_14 = state._check_inv_14();
                    _InvCache__check_inv_14 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_14, read__check_inv_14_state, _check_inv_14);
                } else {
                    _check_inv_14 = (boolean) _obj__check_inv_14;
                }
            } else {
                _check_inv_14 = state._check_inv_14();
            }
            if(!_check_inv_14) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_14");
                return true;
            }
            boolean _check_inv_15;
            if(isCaching) {
                _ProjectionRead__check_inv_15 read__check_inv_15_state = state._projected_state_for__check_inv_15();
                Object _obj__check_inv_15 = GET.invoke(_InvCache__check_inv_15, read__check_inv_15_state);
                if(_obj__check_inv_15 == null) {
                    _check_inv_15 = state._check_inv_15();
                    _InvCache__check_inv_15 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_15, read__check_inv_15_state, _check_inv_15);
                } else {
                    _check_inv_15 = (boolean) _obj__check_inv_15;
                }
            } else {
                _check_inv_15 = state._check_inv_15();
            }
            if(!_check_inv_15) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_15");
                return true;
            }
            boolean _check_inv_16;
            if(isCaching) {
                _ProjectionRead__check_inv_16 read__check_inv_16_state = state._projected_state_for__check_inv_16();
                Object _obj__check_inv_16 = GET.invoke(_InvCache__check_inv_16, read__check_inv_16_state);
                if(_obj__check_inv_16 == null) {
                    _check_inv_16 = state._check_inv_16();
                    _InvCache__check_inv_16 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_16, read__check_inv_16_state, _check_inv_16);
                } else {
                    _check_inv_16 = (boolean) _obj__check_inv_16;
                }
            } else {
                _check_inv_16 = state._check_inv_16();
            }
            if(!_check_inv_16) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_16");
                return true;
            }
            boolean _check_inv_17;
            if(isCaching) {
                _ProjectionRead__check_inv_17 read__check_inv_17_state = state._projected_state_for__check_inv_17();
                Object _obj__check_inv_17 = GET.invoke(_InvCache__check_inv_17, read__check_inv_17_state);
                if(_obj__check_inv_17 == null) {
                    _check_inv_17 = state._check_inv_17();
                    _InvCache__check_inv_17 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_17, read__check_inv_17_state, _check_inv_17);
                } else {
                    _check_inv_17 = (boolean) _obj__check_inv_17;
                }
            } else {
                _check_inv_17 = state._check_inv_17();
            }
            if(!_check_inv_17) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_17");
                return true;
            }
            boolean _check_inv_18;
            if(isCaching) {
                _ProjectionRead__check_inv_18 read__check_inv_18_state = state._projected_state_for__check_inv_18();
                Object _obj__check_inv_18 = GET.invoke(_InvCache__check_inv_18, read__check_inv_18_state);
                if(_obj__check_inv_18 == null) {
                    _check_inv_18 = state._check_inv_18();
                    _InvCache__check_inv_18 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_18, read__check_inv_18_state, _check_inv_18);
                } else {
                    _check_inv_18 = (boolean) _obj__check_inv_18;
                }
            } else {
                _check_inv_18 = state._check_inv_18();
            }
            if(!_check_inv_18) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_18");
                return true;
            }
            boolean _check_inv_19;
            if(isCaching) {
                _ProjectionRead__check_inv_19 read__check_inv_19_state = state._projected_state_for__check_inv_19();
                Object _obj__check_inv_19 = GET.invoke(_InvCache__check_inv_19, read__check_inv_19_state);
                if(_obj__check_inv_19 == null) {
                    _check_inv_19 = state._check_inv_19();
                    _InvCache__check_inv_19 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_19, read__check_inv_19_state, _check_inv_19);
                } else {
                    _check_inv_19 = (boolean) _obj__check_inv_19;
                }
            } else {
                _check_inv_19 = state._check_inv_19();
            }
            if(!_check_inv_19) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_19");
                return true;
            }
            boolean _check_inv_20;
            if(isCaching) {
                _ProjectionRead__check_inv_20 read__check_inv_20_state = state._projected_state_for__check_inv_20();
                Object _obj__check_inv_20 = GET.invoke(_InvCache__check_inv_20, read__check_inv_20_state);
                if(_obj__check_inv_20 == null) {
                    _check_inv_20 = state._check_inv_20();
                    _InvCache__check_inv_20 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_20, read__check_inv_20_state, _check_inv_20);
                } else {
                    _check_inv_20 = (boolean) _obj__check_inv_20;
                }
            } else {
                _check_inv_20 = state._check_inv_20();
            }
            if(!_check_inv_20) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_20");
                return true;
            }
            boolean _check_inv_21;
            if(isCaching) {
                _ProjectionRead__check_inv_21 read__check_inv_21_state = state._projected_state_for__check_inv_21();
                Object _obj__check_inv_21 = GET.invoke(_InvCache__check_inv_21, read__check_inv_21_state);
                if(_obj__check_inv_21 == null) {
                    _check_inv_21 = state._check_inv_21();
                    _InvCache__check_inv_21 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_21, read__check_inv_21_state, _check_inv_21);
                } else {
                    _check_inv_21 = (boolean) _obj__check_inv_21;
                }
            } else {
                _check_inv_21 = state._check_inv_21();
            }
            if(!_check_inv_21) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_21");
                return true;
            }
            boolean _check_inv_22;
            if(isCaching) {
                _ProjectionRead__check_inv_22 read__check_inv_22_state = state._projected_state_for__check_inv_22();
                Object _obj__check_inv_22 = GET.invoke(_InvCache__check_inv_22, read__check_inv_22_state);
                if(_obj__check_inv_22 == null) {
                    _check_inv_22 = state._check_inv_22();
                    _InvCache__check_inv_22 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_22, read__check_inv_22_state, _check_inv_22);
                } else {
                    _check_inv_22 = (boolean) _obj__check_inv_22;
                }
            } else {
                _check_inv_22 = state._check_inv_22();
            }
            if(!_check_inv_22) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_22");
                return true;
            }
            boolean _check_inv_23;
            if(isCaching) {
                _ProjectionRead__check_inv_23 read__check_inv_23_state = state._projected_state_for__check_inv_23();
                Object _obj__check_inv_23 = GET.invoke(_InvCache__check_inv_23, read__check_inv_23_state);
                if(_obj__check_inv_23 == null) {
                    _check_inv_23 = state._check_inv_23();
                    _InvCache__check_inv_23 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_23, read__check_inv_23_state, _check_inv_23);
                } else {
                    _check_inv_23 = (boolean) _obj__check_inv_23;
                }
            } else {
                _check_inv_23 = state._check_inv_23();
            }
            if(!_check_inv_23) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_23");
                return true;
            }
            boolean _check_inv_24;
            if(isCaching) {
                _ProjectionRead__check_inv_24 read__check_inv_24_state = state._projected_state_for__check_inv_24();
                Object _obj__check_inv_24 = GET.invoke(_InvCache__check_inv_24, read__check_inv_24_state);
                if(_obj__check_inv_24 == null) {
                    _check_inv_24 = state._check_inv_24();
                    _InvCache__check_inv_24 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_24, read__check_inv_24_state, _check_inv_24);
                } else {
                    _check_inv_24 = (boolean) _obj__check_inv_24;
                }
            } else {
                _check_inv_24 = state._check_inv_24();
            }
            if(!_check_inv_24) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_24");
                return true;
            }
            boolean _check_inv_25;
            if(isCaching) {
                _ProjectionRead__check_inv_25 read__check_inv_25_state = state._projected_state_for__check_inv_25();
                Object _obj__check_inv_25 = GET.invoke(_InvCache__check_inv_25, read__check_inv_25_state);
                if(_obj__check_inv_25 == null) {
                    _check_inv_25 = state._check_inv_25();
                    _InvCache__check_inv_25 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_25, read__check_inv_25_state, _check_inv_25);
                } else {
                    _check_inv_25 = (boolean) _obj__check_inv_25;
                }
            } else {
                _check_inv_25 = state._check_inv_25();
            }
            if(!_check_inv_25) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_25");
                return true;
            }
            return false;
        }

        private void printResult(final int states, final int transitions) {
            if(invariantViolated.get() || deadlockDetected.get()) {
                if(deadlockDetected.get()) {
                    System.out.println("DEADLOCK DETECTED");
                } else {
                    System.out.println("INVARIANT VIOLATED");
                }

                System.out.println("COUNTER EXAMPLE TRACE: ");
                StringBuilder sb = new StringBuilder();
                while(counterExampleState != null) {
                    sb.insert(0, counterExampleState);
                    sb.insert(0, "\n");
                    if(counterExampleState.stateAccessedVia != null) {
                        sb.insert(0, counterExampleState.stateAccessedVia);
                    }
                    sb.insert(0, "\n\n");
                    counterExampleState = counterExampleState.parent;
                }
                System.out.println(sb);
            } else {
                System.out.println("MODEL CHECKING SUCCESSFUL");
            }

            System.out.println("Number of States: " + states);
            System.out.println("Number of Transitions: " + transitions);
        }
    }


    public static void main(String[] args) {
        if(args.length > 4) {
            System.out.println("Expecting 3 command-line arguments: STRATEGY THREADS CACHING DEBUG");
            return;
        }
        Type type = Type.MIXED;
        int threads = 0;
        boolean isCaching = false;
        boolean isDebug = false;

        if(args.length > 0) { 
            if("mixed".equals(args[0])) {
                type = Type.MIXED;
            } else if("bf".equals(args[0])) {
                type = Type.BFS;
            } else if ("df".equals(args[0])) {
                type = Type.DFS;
            } else {
                System.out.println("Value for command-line argument STRATEGY is wrong.");
                System.out.println("Expecting mixed, bf or df.");
                return;
            }
        }
        if(args.length > 1) { 
            try {
                threads = Integer.parseInt(args[1]);
            } catch(NumberFormatException e) {
                System.out.println("Value for command-line argument THREADS is not a number.");
                return;
            }
            if(threads <= 0) {
                System.out.println("Value for command-line argument THREADS must be positive.");
                return;
            }
        }
        if(args.length > 2) { 
            try {
                isCaching = Boolean.parseBoolean(args[2]);
            } catch(Exception e) {
                System.out.println("Value for command-line argument CACHING is not a boolean.");
                return;
            }
        }
        if(args.length > 3) { 
            try {
                isDebug = Boolean.parseBoolean(args[3]);
            } catch(Exception e) {
                System.out.println("Value for command-line argument DEBUG is not a boolean.");
                return;
            }
        }

        System.out.println("Starting Model Checking, Search: "+type+", Threads: "+threads+", Caching: "+isCaching);
        long start = java.lang.System.currentTimeMillis();
        ModelChecker modelchecker = new ModelChecker(type, threads, isCaching, isDebug);
        modelchecker.modelCheck();
        long stop = java.lang.System.currentTimeMillis();
        System.out.println("Model Checking Time: "+ (stop-start) + " ms");
    }




}
