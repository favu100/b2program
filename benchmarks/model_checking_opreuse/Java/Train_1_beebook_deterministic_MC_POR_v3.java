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


public class Train_1_beebook_deterministic_MC_POR_v3 {


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

    public Train_1_beebook_deterministic_MC_POR_v3 parent;
    public String stateAccessedVia;

    public static class _ProjectionRead_route_reservation {

        public BSet<ROUTES> resrt;
        public BSet<BLOCKS> resbl;
        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead_route_reservation(BSet<ROUTES> resrt, BSet<BLOCKS> resbl, BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.resrt = resrt;
            this.resbl = resbl;
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "resrt: " + this.resrt + "," + "resbl: " + this.resbl + "," + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_route_reservation)) {
                return false;
            }
            _ProjectionRead_route_reservation o = (_ProjectionRead_route_reservation) other;
            return this.resrt.equals(o.resrt) && this.resbl.equals(o.resbl) && this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(resrt, resbl, rsrtbl);
        }
    }

    public static class _ProjectionRead__tr_route_reservation {

        public BSet<ROUTES> resrt;
        public BSet<BLOCKS> resbl;
        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead__tr_route_reservation(BSet<ROUTES> resrt, BSet<BLOCKS> resbl, BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.resrt = resrt;
            this.resbl = resbl;
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "resrt: " + this.resrt + "," + "resbl: " + this.resbl + "," + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_route_reservation)) {
                return false;
            }
            _ProjectionRead__tr_route_reservation o = (_ProjectionRead__tr_route_reservation) other;
            return this.resrt.equals(o.resrt) && this.resbl.equals(o.resbl) && this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(resrt, resbl, rsrtbl);
        }
    }

    public static class _ProjectionWrite_route_reservation {

        public BSet<ROUTES> resrt;
        public BSet<BLOCKS> resbl;
        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionWrite_route_reservation(BSet<ROUTES> resrt, BSet<BLOCKS> resbl, BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.resrt = resrt;
            this.resbl = resbl;
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "resrt: " + this.resrt + "," + "resbl: " + this.resbl + "," + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_route_reservation)) {
                return false;
            }
            _ProjectionWrite_route_reservation o = (_ProjectionWrite_route_reservation) other;
            return this.resrt.equals(o.resrt) && this.resbl.equals(o.resbl) && this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(resrt, resbl, rsrtbl);
        }
    }

    public static class _ProjectionRead_route_freeing {

        public BSet<ROUTES> frm;
        public BSet<ROUTES> resrt;
        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead_route_freeing(BSet<ROUTES> frm, BSet<ROUTES> resrt, BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.frm = frm;
            this.resrt = resrt;
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "frm: " + this.frm + "," + "resrt: " + this.resrt + "," + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_route_freeing)) {
                return false;
            }
            _ProjectionRead_route_freeing o = (_ProjectionRead_route_freeing) other;
            return this.frm.equals(o.frm) && this.resrt.equals(o.resrt) && this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(frm, resrt, rsrtbl);
        }
    }

    public static class _ProjectionRead__tr_route_freeing {

        public BSet<ROUTES> resrt;
        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead__tr_route_freeing(BSet<ROUTES> resrt, BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.resrt = resrt;
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "resrt: " + this.resrt + "," + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_route_freeing)) {
                return false;
            }
            _ProjectionRead__tr_route_freeing o = (_ProjectionRead__tr_route_freeing) other;
            return this.resrt.equals(o.resrt) && this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(resrt, rsrtbl);
        }
    }

    public static class _ProjectionWrite_route_freeing {

        public BSet<ROUTES> frm;
        public BSet<ROUTES> resrt;

        public _ProjectionWrite_route_freeing(BSet<ROUTES> frm, BSet<ROUTES> resrt) {
            this.frm = frm;
            this.resrt = resrt;
        }

        public String toString() {
            return "{" + "frm: " + this.frm + "," + "resrt: " + this.resrt + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_route_freeing)) {
                return false;
            }
            _ProjectionWrite_route_freeing o = (_ProjectionWrite_route_freeing) other;
            return this.frm.equals(o.frm) && this.resrt.equals(o.resrt);
        }

        public int hashCode() {
            return Objects.hash(frm, resrt);
        }
    }

    public static class _ProjectionRead_FRONT_MOVE_1 {

        public BSet<ROUTES> frm;
        public BSet<ROUTES> resrt;
        public BSet<BLOCKS> resbl;
        public BSet<BLOCKS> OCC;
        public BRelation<BLOCKS, ROUTES> rsrtbl;
        public BSet<BLOCKS> LBT;

        public _ProjectionRead_FRONT_MOVE_1(BSet<ROUTES> frm, BSet<ROUTES> resrt, BSet<BLOCKS> resbl, BSet<BLOCKS> OCC, BRelation<BLOCKS, ROUTES> rsrtbl, BSet<BLOCKS> LBT) {
            this.frm = frm;
            this.resrt = resrt;
            this.resbl = resbl;
            this.OCC = OCC;
            this.rsrtbl = rsrtbl;
            this.LBT = LBT;
        }

        public String toString() {
            return "{" + "frm: " + this.frm + "," + "resrt: " + this.resrt + "," + "resbl: " + this.resbl + "," + "OCC: " + this.OCC + "," + "rsrtbl: " + this.rsrtbl + "," + "LBT: " + this.LBT + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_FRONT_MOVE_1)) {
                return false;
            }
            _ProjectionRead_FRONT_MOVE_1 o = (_ProjectionRead_FRONT_MOVE_1) other;
            return this.frm.equals(o.frm) && this.resrt.equals(o.resrt) && this.resbl.equals(o.resbl) && this.OCC.equals(o.OCC) && this.rsrtbl.equals(o.rsrtbl) && this.LBT.equals(o.LBT);
        }

        public int hashCode() {
            return Objects.hash(frm, resrt, resbl, OCC, rsrtbl, LBT);
        }
    }

    public static class _ProjectionRead__tr_FRONT_MOVE_1 {

        public BSet<ROUTES> frm;
        public BSet<ROUTES> resrt;
        public BSet<BLOCKS> resbl;
        public BSet<BLOCKS> OCC;
        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead__tr_FRONT_MOVE_1(BSet<ROUTES> frm, BSet<ROUTES> resrt, BSet<BLOCKS> resbl, BSet<BLOCKS> OCC, BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.frm = frm;
            this.resrt = resrt;
            this.resbl = resbl;
            this.OCC = OCC;
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "frm: " + this.frm + "," + "resrt: " + this.resrt + "," + "resbl: " + this.resbl + "," + "OCC: " + this.OCC + "," + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_FRONT_MOVE_1)) {
                return false;
            }
            _ProjectionRead__tr_FRONT_MOVE_1 o = (_ProjectionRead__tr_FRONT_MOVE_1) other;
            return this.frm.equals(o.frm) && this.resrt.equals(o.resrt) && this.resbl.equals(o.resbl) && this.OCC.equals(o.OCC) && this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(frm, resrt, resbl, OCC, rsrtbl);
        }
    }

    public static class _ProjectionWrite_FRONT_MOVE_1 {

        public BSet<BLOCKS> OCC;
        public BSet<BLOCKS> LBT;

        public _ProjectionWrite_FRONT_MOVE_1(BSet<BLOCKS> OCC, BSet<BLOCKS> LBT) {
            this.OCC = OCC;
            this.LBT = LBT;
        }

        public String toString() {
            return "{" + "OCC: " + this.OCC + "," + "LBT: " + this.LBT + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_FRONT_MOVE_1)) {
                return false;
            }
            _ProjectionWrite_FRONT_MOVE_1 o = (_ProjectionWrite_FRONT_MOVE_1) other;
            return this.OCC.equals(o.OCC) && this.LBT.equals(o.LBT);
        }

        public int hashCode() {
            return Objects.hash(OCC, LBT);
        }
    }

    public static class _ProjectionRead_FRONT_MOVE_2 {

        public BRelation<BLOCKS, BLOCKS> TRK;
        public BSet<BLOCKS> OCC;

        public _ProjectionRead_FRONT_MOVE_2(BRelation<BLOCKS, BLOCKS> TRK, BSet<BLOCKS> OCC) {
            this.TRK = TRK;
            this.OCC = OCC;
        }

        public String toString() {
            return "{" + "TRK: " + this.TRK + "," + "OCC: " + this.OCC + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_FRONT_MOVE_2)) {
                return false;
            }
            _ProjectionRead_FRONT_MOVE_2 o = (_ProjectionRead_FRONT_MOVE_2) other;
            return this.TRK.equals(o.TRK) && this.OCC.equals(o.OCC);
        }

        public int hashCode() {
            return Objects.hash(TRK, OCC);
        }
    }

    public static class _ProjectionRead__tr_FRONT_MOVE_2 {

        public BRelation<BLOCKS, BLOCKS> TRK;
        public BSet<BLOCKS> OCC;

        public _ProjectionRead__tr_FRONT_MOVE_2(BRelation<BLOCKS, BLOCKS> TRK, BSet<BLOCKS> OCC) {
            this.TRK = TRK;
            this.OCC = OCC;
        }

        public String toString() {
            return "{" + "TRK: " + this.TRK + "," + "OCC: " + this.OCC + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_FRONT_MOVE_2)) {
                return false;
            }
            _ProjectionRead__tr_FRONT_MOVE_2 o = (_ProjectionRead__tr_FRONT_MOVE_2) other;
            return this.TRK.equals(o.TRK) && this.OCC.equals(o.OCC);
        }

        public int hashCode() {
            return Objects.hash(TRK, OCC);
        }
    }

    public static class _ProjectionWrite_FRONT_MOVE_2 {

        public BSet<BLOCKS> OCC;

        public _ProjectionWrite_FRONT_MOVE_2(BSet<BLOCKS> OCC) {
            this.OCC = OCC;
        }

        public String toString() {
            return "{" + "OCC: " + this.OCC + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_FRONT_MOVE_2)) {
                return false;
            }
            _ProjectionWrite_FRONT_MOVE_2 o = (_ProjectionWrite_FRONT_MOVE_2) other;
            return this.OCC.equals(o.OCC);
        }

        public int hashCode() {
            return Objects.hash(OCC);
        }
    }

    public static class _ProjectionRead_BACK_MOVE_1 {

        public BSet<ROUTES> resrt;
        public BRelation<BLOCKS, BLOCKS> TRK;
        public BSet<BLOCKS> resbl;
        public BSet<BLOCKS> OCC;
        public BSet<BLOCKS> LBT;
        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead_BACK_MOVE_1(BSet<ROUTES> resrt, BRelation<BLOCKS, BLOCKS> TRK, BSet<BLOCKS> resbl, BSet<BLOCKS> OCC, BSet<BLOCKS> LBT, BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.resrt = resrt;
            this.TRK = TRK;
            this.resbl = resbl;
            this.OCC = OCC;
            this.LBT = LBT;
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "resrt: " + this.resrt + "," + "TRK: " + this.TRK + "," + "resbl: " + this.resbl + "," + "OCC: " + this.OCC + "," + "LBT: " + this.LBT + "," + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_BACK_MOVE_1)) {
                return false;
            }
            _ProjectionRead_BACK_MOVE_1 o = (_ProjectionRead_BACK_MOVE_1) other;
            return this.resrt.equals(o.resrt) && this.TRK.equals(o.TRK) && this.resbl.equals(o.resbl) && this.OCC.equals(o.OCC) && this.LBT.equals(o.LBT) && this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(resrt, TRK, resbl, OCC, LBT, rsrtbl);
        }
    }

    public static class _ProjectionRead__tr_BACK_MOVE_1 {

        public BSet<ROUTES> resrt;
        public BRelation<BLOCKS, BLOCKS> TRK;
        public BSet<BLOCKS> LBT;
        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead__tr_BACK_MOVE_1(BSet<ROUTES> resrt, BRelation<BLOCKS, BLOCKS> TRK, BSet<BLOCKS> LBT, BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.resrt = resrt;
            this.TRK = TRK;
            this.LBT = LBT;
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "resrt: " + this.resrt + "," + "TRK: " + this.TRK + "," + "LBT: " + this.LBT + "," + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_BACK_MOVE_1)) {
                return false;
            }
            _ProjectionRead__tr_BACK_MOVE_1 o = (_ProjectionRead__tr_BACK_MOVE_1) other;
            return this.resrt.equals(o.resrt) && this.TRK.equals(o.TRK) && this.LBT.equals(o.LBT) && this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(resrt, TRK, LBT, rsrtbl);
        }
    }

    public static class _ProjectionWrite_BACK_MOVE_1 {

        public BSet<BLOCKS> resbl;
        public BSet<BLOCKS> OCC;
        public BRelation<BLOCKS, ROUTES> rsrtbl;
        public BSet<BLOCKS> LBT;

        public _ProjectionWrite_BACK_MOVE_1(BSet<BLOCKS> resbl, BSet<BLOCKS> OCC, BRelation<BLOCKS, ROUTES> rsrtbl, BSet<BLOCKS> LBT) {
            this.resbl = resbl;
            this.OCC = OCC;
            this.rsrtbl = rsrtbl;
            this.LBT = LBT;
        }

        public String toString() {
            return "{" + "resbl: " + this.resbl + "," + "OCC: " + this.OCC + "," + "rsrtbl: " + this.rsrtbl + "," + "LBT: " + this.LBT + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_BACK_MOVE_1)) {
                return false;
            }
            _ProjectionWrite_BACK_MOVE_1 o = (_ProjectionWrite_BACK_MOVE_1) other;
            return this.resbl.equals(o.resbl) && this.OCC.equals(o.OCC) && this.rsrtbl.equals(o.rsrtbl) && this.LBT.equals(o.LBT);
        }

        public int hashCode() {
            return Objects.hash(resbl, OCC, rsrtbl, LBT);
        }
    }

    public static class _ProjectionRead_BACK_MOVE_2 {

        public BSet<ROUTES> resrt;
        public BRelation<BLOCKS, BLOCKS> TRK;
        public BSet<BLOCKS> resbl;
        public BSet<BLOCKS> OCC;
        public BSet<BLOCKS> LBT;
        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead_BACK_MOVE_2(BSet<ROUTES> resrt, BRelation<BLOCKS, BLOCKS> TRK, BSet<BLOCKS> resbl, BSet<BLOCKS> OCC, BSet<BLOCKS> LBT, BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.resrt = resrt;
            this.TRK = TRK;
            this.resbl = resbl;
            this.OCC = OCC;
            this.LBT = LBT;
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "resrt: " + this.resrt + "," + "TRK: " + this.TRK + "," + "resbl: " + this.resbl + "," + "OCC: " + this.OCC + "," + "LBT: " + this.LBT + "," + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_BACK_MOVE_2)) {
                return false;
            }
            _ProjectionRead_BACK_MOVE_2 o = (_ProjectionRead_BACK_MOVE_2) other;
            return this.resrt.equals(o.resrt) && this.TRK.equals(o.TRK) && this.resbl.equals(o.resbl) && this.OCC.equals(o.OCC) && this.LBT.equals(o.LBT) && this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(resrt, TRK, resbl, OCC, LBT, rsrtbl);
        }
    }

    public static class _ProjectionRead__tr_BACK_MOVE_2 {

        public BSet<ROUTES> resrt;
        public BRelation<BLOCKS, BLOCKS> TRK;
        public BSet<BLOCKS> OCC;
        public BSet<BLOCKS> LBT;
        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead__tr_BACK_MOVE_2(BSet<ROUTES> resrt, BRelation<BLOCKS, BLOCKS> TRK, BSet<BLOCKS> OCC, BSet<BLOCKS> LBT, BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.resrt = resrt;
            this.TRK = TRK;
            this.OCC = OCC;
            this.LBT = LBT;
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "resrt: " + this.resrt + "," + "TRK: " + this.TRK + "," + "OCC: " + this.OCC + "," + "LBT: " + this.LBT + "," + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_BACK_MOVE_2)) {
                return false;
            }
            _ProjectionRead__tr_BACK_MOVE_2 o = (_ProjectionRead__tr_BACK_MOVE_2) other;
            return this.resrt.equals(o.resrt) && this.TRK.equals(o.TRK) && this.OCC.equals(o.OCC) && this.LBT.equals(o.LBT) && this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(resrt, TRK, OCC, LBT, rsrtbl);
        }
    }

    public static class _ProjectionWrite_BACK_MOVE_2 {

        public BSet<BLOCKS> resbl;
        public BSet<BLOCKS> OCC;
        public BRelation<BLOCKS, ROUTES> rsrtbl;
        public BSet<BLOCKS> LBT;

        public _ProjectionWrite_BACK_MOVE_2(BSet<BLOCKS> resbl, BSet<BLOCKS> OCC, BRelation<BLOCKS, ROUTES> rsrtbl, BSet<BLOCKS> LBT) {
            this.resbl = resbl;
            this.OCC = OCC;
            this.rsrtbl = rsrtbl;
            this.LBT = LBT;
        }

        public String toString() {
            return "{" + "resbl: " + this.resbl + "," + "OCC: " + this.OCC + "," + "rsrtbl: " + this.rsrtbl + "," + "LBT: " + this.LBT + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_BACK_MOVE_2)) {
                return false;
            }
            _ProjectionWrite_BACK_MOVE_2 o = (_ProjectionWrite_BACK_MOVE_2) other;
            return this.resbl.equals(o.resbl) && this.OCC.equals(o.OCC) && this.rsrtbl.equals(o.rsrtbl) && this.LBT.equals(o.LBT);
        }

        public int hashCode() {
            return Objects.hash(resbl, OCC, rsrtbl, LBT);
        }
    }

    public static class _ProjectionRead_point_positionning {

        public BSet<ROUTES> frm;
        public BSet<ROUTES> resrt;
        public BRelation<BLOCKS, BLOCKS> TRK;
        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead_point_positionning(BSet<ROUTES> frm, BSet<ROUTES> resrt, BRelation<BLOCKS, BLOCKS> TRK, BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.frm = frm;
            this.resrt = resrt;
            this.TRK = TRK;
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "frm: " + this.frm + "," + "resrt: " + this.resrt + "," + "TRK: " + this.TRK + "," + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_point_positionning)) {
                return false;
            }
            _ProjectionRead_point_positionning o = (_ProjectionRead_point_positionning) other;
            return this.frm.equals(o.frm) && this.resrt.equals(o.resrt) && this.TRK.equals(o.TRK) && this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(frm, resrt, TRK, rsrtbl);
        }
    }

    public static class _ProjectionRead__tr_point_positionning {

        public BSet<ROUTES> frm;
        public BSet<ROUTES> resrt;
        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead__tr_point_positionning(BSet<ROUTES> frm, BSet<ROUTES> resrt, BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.frm = frm;
            this.resrt = resrt;
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "frm: " + this.frm + "," + "resrt: " + this.resrt + "," + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_point_positionning)) {
                return false;
            }
            _ProjectionRead__tr_point_positionning o = (_ProjectionRead__tr_point_positionning) other;
            return this.frm.equals(o.frm) && this.resrt.equals(o.resrt) && this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(frm, resrt, rsrtbl);
        }
    }

    public static class _ProjectionWrite_point_positionning {

        public BRelation<BLOCKS, BLOCKS> TRK;

        public _ProjectionWrite_point_positionning(BRelation<BLOCKS, BLOCKS> TRK) {
            this.TRK = TRK;
        }

        public String toString() {
            return "{" + "TRK: " + this.TRK + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_point_positionning)) {
                return false;
            }
            _ProjectionWrite_point_positionning o = (_ProjectionWrite_point_positionning) other;
            return this.TRK.equals(o.TRK);
        }

        public int hashCode() {
            return Objects.hash(TRK);
        }
    }

    public static class _ProjectionRead_route_formation {

        public BSet<ROUTES> frm;
        public BSet<ROUTES> resrt;
        public BRelation<BLOCKS, BLOCKS> TRK;
        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead_route_formation(BSet<ROUTES> frm, BSet<ROUTES> resrt, BRelation<BLOCKS, BLOCKS> TRK, BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.frm = frm;
            this.resrt = resrt;
            this.TRK = TRK;
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "frm: " + this.frm + "," + "resrt: " + this.resrt + "," + "TRK: " + this.TRK + "," + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_route_formation)) {
                return false;
            }
            _ProjectionRead_route_formation o = (_ProjectionRead_route_formation) other;
            return this.frm.equals(o.frm) && this.resrt.equals(o.resrt) && this.TRK.equals(o.TRK) && this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(frm, resrt, TRK, rsrtbl);
        }
    }

    public static class _ProjectionRead__tr_route_formation {

        public BSet<ROUTES> frm;
        public BSet<ROUTES> resrt;
        public BRelation<BLOCKS, BLOCKS> TRK;
        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead__tr_route_formation(BSet<ROUTES> frm, BSet<ROUTES> resrt, BRelation<BLOCKS, BLOCKS> TRK, BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.frm = frm;
            this.resrt = resrt;
            this.TRK = TRK;
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "frm: " + this.frm + "," + "resrt: " + this.resrt + "," + "TRK: " + this.TRK + "," + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_route_formation)) {
                return false;
            }
            _ProjectionRead__tr_route_formation o = (_ProjectionRead__tr_route_formation) other;
            return this.frm.equals(o.frm) && this.resrt.equals(o.resrt) && this.TRK.equals(o.TRK) && this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(frm, resrt, TRK, rsrtbl);
        }
    }

    public static class _ProjectionWrite_route_formation {

        public BSet<ROUTES> frm;

        public _ProjectionWrite_route_formation(BSet<ROUTES> frm) {
            this.frm = frm;
        }

        public String toString() {
            return "{" + "frm: " + this.frm + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_route_formation)) {
                return false;
            }
            _ProjectionWrite_route_formation o = (_ProjectionWrite_route_formation) other;
            return this.frm.equals(o.frm);
        }

        public int hashCode() {
            return Objects.hash(frm);
        }
    }

    public static class _ProjectionRead__check_inv_1 {

        public BSet<ROUTES> resrt;
        public BSet<BLOCKS> resbl;
        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead__check_inv_1(BSet<ROUTES> resrt, BSet<BLOCKS> resbl, BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.resrt = resrt;
            this.resbl = resbl;
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "resrt: " + this.resrt + "," + "resbl: " + this.resbl + "," + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_1)) {
                return false;
            }
            _ProjectionRead__check_inv_1 o = (_ProjectionRead__check_inv_1) other;
            return this.resrt.equals(o.resrt) && this.resbl.equals(o.resbl) && this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(resrt, resbl, rsrtbl);
        }
    }

    public static class _ProjectionRead__check_inv_2 {

        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead__check_inv_2(BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_2)) {
                return false;
            }
            _ProjectionRead__check_inv_2 o = (_ProjectionRead__check_inv_2) other;
            return this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(rsrtbl);
        }
    }

    public static class _ProjectionRead__check_inv_3 {

        public BSet<BLOCKS> resbl;
        public BSet<BLOCKS> OCC;

        public _ProjectionRead__check_inv_3(BSet<BLOCKS> resbl, BSet<BLOCKS> OCC) {
            this.resbl = resbl;
            this.OCC = OCC;
        }

        public String toString() {
            return "{" + "resbl: " + this.resbl + "," + "OCC: " + this.OCC + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_3)) {
                return false;
            }
            _ProjectionRead__check_inv_3 o = (_ProjectionRead__check_inv_3) other;
            return this.resbl.equals(o.resbl) && this.OCC.equals(o.OCC);
        }

        public int hashCode() {
            return Objects.hash(resbl, OCC);
        }
    }

    public static class _ProjectionRead__check_inv_4 {

        public BSet<BLOCKS> OCC;
        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead__check_inv_4(BSet<BLOCKS> OCC, BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.OCC = OCC;
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "OCC: " + this.OCC + "," + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_4)) {
                return false;
            }
            _ProjectionRead__check_inv_4 o = (_ProjectionRead__check_inv_4) other;
            return this.OCC.equals(o.OCC) && this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(OCC, rsrtbl);
        }
    }

    public static class _ProjectionRead__check_inv_5 {

        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead__check_inv_5(BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_5)) {
                return false;
            }
            _ProjectionRead__check_inv_5 o = (_ProjectionRead__check_inv_5) other;
            return this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(rsrtbl);
        }
    }

    public static class _ProjectionRead__check_inv_6 {

        public BSet<BLOCKS> OCC;
        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead__check_inv_6(BSet<BLOCKS> OCC, BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.OCC = OCC;
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "OCC: " + this.OCC + "," + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_6)) {
                return false;
            }
            _ProjectionRead__check_inv_6 o = (_ProjectionRead__check_inv_6) other;
            return this.OCC.equals(o.OCC) && this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(OCC, rsrtbl);
        }
    }

    public static class _ProjectionRead__check_inv_7 {

        public BRelation<BLOCKS, BLOCKS> TRK;

        public _ProjectionRead__check_inv_7(BRelation<BLOCKS, BLOCKS> TRK) {
            this.TRK = TRK;
        }

        public String toString() {
            return "{" + "TRK: " + this.TRK + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_7)) {
                return false;
            }
            _ProjectionRead__check_inv_7 o = (_ProjectionRead__check_inv_7) other;
            return this.TRK.equals(o.TRK);
        }

        public int hashCode() {
            return Objects.hash(TRK);
        }
    }

    public static class _ProjectionRead__check_inv_8 {

        public BSet<ROUTES> frm;
        public BSet<ROUTES> resrt;

        public _ProjectionRead__check_inv_8(BSet<ROUTES> frm, BSet<ROUTES> resrt) {
            this.frm = frm;
            this.resrt = resrt;
        }

        public String toString() {
            return "{" + "frm: " + this.frm + "," + "resrt: " + this.resrt + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_8)) {
                return false;
            }
            _ProjectionRead__check_inv_8 o = (_ProjectionRead__check_inv_8) other;
            return this.frm.equals(o.frm) && this.resrt.equals(o.resrt);
        }

        public int hashCode() {
            return Objects.hash(frm, resrt);
        }
    }

    public static class _ProjectionRead__check_inv_9 {

        public BSet<ROUTES> frm;
        public BSet<BLOCKS> OCC;
        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead__check_inv_9(BSet<ROUTES> frm, BSet<BLOCKS> OCC, BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.frm = frm;
            this.OCC = OCC;
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "frm: " + this.frm + "," + "OCC: " + this.OCC + "," + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_9)) {
                return false;
            }
            _ProjectionRead__check_inv_9 o = (_ProjectionRead__check_inv_9) other;
            return this.frm.equals(o.frm) && this.OCC.equals(o.OCC) && this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(frm, OCC, rsrtbl);
        }
    }

    public static class _ProjectionRead__check_inv_10 {

        public BSet<ROUTES> frm;
        public BSet<ROUTES> resrt;
        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead__check_inv_10(BSet<ROUTES> frm, BSet<ROUTES> resrt, BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.frm = frm;
            this.resrt = resrt;
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "frm: " + this.frm + "," + "resrt: " + this.resrt + "," + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_10)) {
                return false;
            }
            _ProjectionRead__check_inv_10 o = (_ProjectionRead__check_inv_10) other;
            return this.frm.equals(o.frm) && this.resrt.equals(o.resrt) && this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(frm, resrt, rsrtbl);
        }
    }

    public static class _ProjectionRead__check_inv_11 {

        public BRelation<BLOCKS, BLOCKS> TRK;

        public _ProjectionRead__check_inv_11(BRelation<BLOCKS, BLOCKS> TRK) {
            this.TRK = TRK;
        }

        public String toString() {
            return "{" + "TRK: " + this.TRK + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_11)) {
                return false;
            }
            _ProjectionRead__check_inv_11 o = (_ProjectionRead__check_inv_11) other;
            return this.TRK.equals(o.TRK);
        }

        public int hashCode() {
            return Objects.hash(TRK);
        }
    }

    public static class _ProjectionRead__check_inv_12 {

        public BSet<ROUTES> frm;
        public BRelation<BLOCKS, BLOCKS> TRK;
        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead__check_inv_12(BSet<ROUTES> frm, BRelation<BLOCKS, BLOCKS> TRK, BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.frm = frm;
            this.TRK = TRK;
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "frm: " + this.frm + "," + "TRK: " + this.TRK + "," + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_12)) {
                return false;
            }
            _ProjectionRead__check_inv_12 o = (_ProjectionRead__check_inv_12) other;
            return this.frm.equals(o.frm) && this.TRK.equals(o.TRK) && this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(frm, TRK, rsrtbl);
        }
    }

    public static class _ProjectionRead__check_inv_13 {

        public BSet<BLOCKS> OCC;
        public BSet<BLOCKS> LBT;

        public _ProjectionRead__check_inv_13(BSet<BLOCKS> OCC, BSet<BLOCKS> LBT) {
            this.OCC = OCC;
            this.LBT = LBT;
        }

        public String toString() {
            return "{" + "OCC: " + this.OCC + "," + "LBT: " + this.LBT + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_13)) {
                return false;
            }
            _ProjectionRead__check_inv_13 o = (_ProjectionRead__check_inv_13) other;
            return this.OCC.equals(o.OCC) && this.LBT.equals(o.LBT);
        }

        public int hashCode() {
            return Objects.hash(OCC, LBT);
        }
    }

    public static class _ProjectionRead__check_inv_14 {

        public BSet<BLOCKS> LBT;
        public BRelation<BLOCKS, ROUTES> rsrtbl;

        public _ProjectionRead__check_inv_14(BSet<BLOCKS> LBT, BRelation<BLOCKS, ROUTES> rsrtbl) {
            this.LBT = LBT;
            this.rsrtbl = rsrtbl;
        }

        public String toString() {
            return "{" + "LBT: " + this.LBT + "," + "rsrtbl: " + this.rsrtbl + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_14)) {
                return false;
            }
            _ProjectionRead__check_inv_14 o = (_ProjectionRead__check_inv_14) other;
            return this.LBT.equals(o.LBT) && this.rsrtbl.equals(o.rsrtbl);
        }

        public int hashCode() {
            return Objects.hash(LBT, rsrtbl);
        }
    }




    private static BRelation<ROUTES, BLOCKS> fst;
    private static BRelation<ROUTES, BLOCKS> lst;
    private static BRelation<ROUTES, BRelation<BLOCKS, BLOCKS>> nxt;
    private static BRelation<BLOCKS, ROUTES> rtbl;
    private static BRelation<ROUTES, BLOCKS> __aux_constant_1;


    public enum BLOCKS implements BObject {
        A, 
        B, 
        C, 
        D, 
        E, 
        F, 
        G, 
        H, 
        I, 
        J, 
        K, 
        L, 
        M, 
        N;

        public BBoolean equal(BLOCKS o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(BLOCKS o) {
            return new BBoolean(this != o);
        }
    }

    public enum ROUTES implements BObject {
        R1, 
        R2, 
        R3, 
        R4, 
        R5, 
        R6, 
        R7, 
        R8, 
        R9, 
        R10;

        public BBoolean equal(ROUTES o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(ROUTES o) {
            return new BBoolean(this != o);
        }
    }

    private static BSet<BLOCKS> _BLOCKS = new BSet<BLOCKS>(BLOCKS.A, BLOCKS.B, BLOCKS.C, BLOCKS.D, BLOCKS.E, BLOCKS.F, BLOCKS.G, BLOCKS.H, BLOCKS.I, BLOCKS.J, BLOCKS.K, BLOCKS.L, BLOCKS.M, BLOCKS.N);
    private static BSet<ROUTES> _ROUTES = new BSet<ROUTES>(ROUTES.R1, ROUTES.R2, ROUTES.R3, ROUTES.R4, ROUTES.R5, ROUTES.R6, ROUTES.R7, ROUTES.R8, ROUTES.R9, ROUTES.R10);

    private BSet<BLOCKS> LBT;
    private BRelation<BLOCKS, BLOCKS> TRK;
    private BSet<ROUTES> frm;
    private BSet<BLOCKS> OCC;
    private BSet<BLOCKS> resbl;
    private BSet<ROUTES> resrt;
    private BRelation<BLOCKS, ROUTES> rsrtbl;

    static {
        fst = new BRelation<ROUTES, BLOCKS>(new BTuple<ROUTES, BLOCKS>(ROUTES.R1, BLOCKS.L), new BTuple<ROUTES, BLOCKS>(ROUTES.R2, BLOCKS.L), new BTuple<ROUTES, BLOCKS>(ROUTES.R3, BLOCKS.L), new BTuple<ROUTES, BLOCKS>(ROUTES.R4, BLOCKS.M), new BTuple<ROUTES, BLOCKS>(ROUTES.R5, BLOCKS.M), new BTuple<ROUTES, BLOCKS>(ROUTES.R6, BLOCKS.C), new BTuple<ROUTES, BLOCKS>(ROUTES.R7, BLOCKS.G), new BTuple<ROUTES, BLOCKS>(ROUTES.R8, BLOCKS.N), new BTuple<ROUTES, BLOCKS>(ROUTES.R9, BLOCKS.G), new BTuple<ROUTES, BLOCKS>(ROUTES.R10, BLOCKS.N));
        lst = new BRelation<ROUTES, BLOCKS>(new BTuple<ROUTES, BLOCKS>(ROUTES.R1, BLOCKS.C), new BTuple<ROUTES, BLOCKS>(ROUTES.R2, BLOCKS.G), new BTuple<ROUTES, BLOCKS>(ROUTES.R3, BLOCKS.N), new BTuple<ROUTES, BLOCKS>(ROUTES.R4, BLOCKS.G), new BTuple<ROUTES, BLOCKS>(ROUTES.R5, BLOCKS.N), new BTuple<ROUTES, BLOCKS>(ROUTES.R6, BLOCKS.L), new BTuple<ROUTES, BLOCKS>(ROUTES.R7, BLOCKS.L), new BTuple<ROUTES, BLOCKS>(ROUTES.R8, BLOCKS.L), new BTuple<ROUTES, BLOCKS>(ROUTES.R9, BLOCKS.M), new BTuple<ROUTES, BLOCKS>(ROUTES.R10, BLOCKS.M));
        nxt = new BRelation<ROUTES, BRelation<BLOCKS, BLOCKS>>(new BTuple<ROUTES, BRelation<BLOCKS, BLOCKS>>(ROUTES.R1, new BRelation<BLOCKS, BLOCKS>(new BTuple<BLOCKS, BLOCKS>(BLOCKS.L, BLOCKS.A), new BTuple<BLOCKS, BLOCKS>(BLOCKS.A, BLOCKS.B), new BTuple<BLOCKS, BLOCKS>(BLOCKS.B, BLOCKS.C))), new BTuple<ROUTES, BRelation<BLOCKS, BLOCKS>>(ROUTES.R2, new BRelation<BLOCKS, BLOCKS>(new BTuple<BLOCKS, BLOCKS>(BLOCKS.L, BLOCKS.A), new BTuple<BLOCKS, BLOCKS>(BLOCKS.A, BLOCKS.B), new BTuple<BLOCKS, BLOCKS>(BLOCKS.B, BLOCKS.D), new BTuple<BLOCKS, BLOCKS>(BLOCKS.D, BLOCKS.E), new BTuple<BLOCKS, BLOCKS>(BLOCKS.E, BLOCKS.F), new BTuple<BLOCKS, BLOCKS>(BLOCKS.F, BLOCKS.G))), new BTuple<ROUTES, BRelation<BLOCKS, BLOCKS>>(ROUTES.R3, new BRelation<BLOCKS, BLOCKS>(new BTuple<BLOCKS, BLOCKS>(BLOCKS.L, BLOCKS.A), new BTuple<BLOCKS, BLOCKS>(BLOCKS.A, BLOCKS.B), new BTuple<BLOCKS, BLOCKS>(BLOCKS.B, BLOCKS.D), new BTuple<BLOCKS, BLOCKS>(BLOCKS.D, BLOCKS.K), new BTuple<BLOCKS, BLOCKS>(BLOCKS.K, BLOCKS.J), new BTuple<BLOCKS, BLOCKS>(BLOCKS.J, BLOCKS.N))), new BTuple<ROUTES, BRelation<BLOCKS, BLOCKS>>(ROUTES.R4, new BRelation<BLOCKS, BLOCKS>(new BTuple<BLOCKS, BLOCKS>(BLOCKS.M, BLOCKS.H), new BTuple<BLOCKS, BLOCKS>(BLOCKS.H, BLOCKS.I), new BTuple<BLOCKS, BLOCKS>(BLOCKS.I, BLOCKS.K), new BTuple<BLOCKS, BLOCKS>(BLOCKS.K, BLOCKS.F), new BTuple<BLOCKS, BLOCKS>(BLOCKS.F, BLOCKS.G))), new BTuple<ROUTES, BRelation<BLOCKS, BLOCKS>>(ROUTES.R5, new BRelation<BLOCKS, BLOCKS>(new BTuple<BLOCKS, BLOCKS>(BLOCKS.M, BLOCKS.H), new BTuple<BLOCKS, BLOCKS>(BLOCKS.H, BLOCKS.I), new BTuple<BLOCKS, BLOCKS>(BLOCKS.I, BLOCKS.J), new BTuple<BLOCKS, BLOCKS>(BLOCKS.J, BLOCKS.N))), new BTuple<ROUTES, BRelation<BLOCKS, BLOCKS>>(ROUTES.R6, new BRelation<BLOCKS, BLOCKS>(new BTuple<BLOCKS, BLOCKS>(BLOCKS.C, BLOCKS.B), new BTuple<BLOCKS, BLOCKS>(BLOCKS.B, BLOCKS.A), new BTuple<BLOCKS, BLOCKS>(BLOCKS.A, BLOCKS.L))), new BTuple<ROUTES, BRelation<BLOCKS, BLOCKS>>(ROUTES.R7, new BRelation<BLOCKS, BLOCKS>(new BTuple<BLOCKS, BLOCKS>(BLOCKS.G, BLOCKS.F), new BTuple<BLOCKS, BLOCKS>(BLOCKS.F, BLOCKS.E), new BTuple<BLOCKS, BLOCKS>(BLOCKS.E, BLOCKS.D), new BTuple<BLOCKS, BLOCKS>(BLOCKS.D, BLOCKS.B), new BTuple<BLOCKS, BLOCKS>(BLOCKS.B, BLOCKS.A), new BTuple<BLOCKS, BLOCKS>(BLOCKS.A, BLOCKS.L))), new BTuple<ROUTES, BRelation<BLOCKS, BLOCKS>>(ROUTES.R8, new BRelation<BLOCKS, BLOCKS>(new BTuple<BLOCKS, BLOCKS>(BLOCKS.N, BLOCKS.J), new BTuple<BLOCKS, BLOCKS>(BLOCKS.J, BLOCKS.K), new BTuple<BLOCKS, BLOCKS>(BLOCKS.K, BLOCKS.D), new BTuple<BLOCKS, BLOCKS>(BLOCKS.D, BLOCKS.B), new BTuple<BLOCKS, BLOCKS>(BLOCKS.B, BLOCKS.A), new BTuple<BLOCKS, BLOCKS>(BLOCKS.A, BLOCKS.L))), new BTuple<ROUTES, BRelation<BLOCKS, BLOCKS>>(ROUTES.R9, new BRelation<BLOCKS, BLOCKS>(new BTuple<BLOCKS, BLOCKS>(BLOCKS.G, BLOCKS.F), new BTuple<BLOCKS, BLOCKS>(BLOCKS.F, BLOCKS.K), new BTuple<BLOCKS, BLOCKS>(BLOCKS.K, BLOCKS.I), new BTuple<BLOCKS, BLOCKS>(BLOCKS.I, BLOCKS.H), new BTuple<BLOCKS, BLOCKS>(BLOCKS.H, BLOCKS.M))), new BTuple<ROUTES, BRelation<BLOCKS, BLOCKS>>(ROUTES.R10, new BRelation<BLOCKS, BLOCKS>(new BTuple<BLOCKS, BLOCKS>(BLOCKS.N, BLOCKS.J), new BTuple<BLOCKS, BLOCKS>(BLOCKS.J, BLOCKS.I), new BTuple<BLOCKS, BLOCKS>(BLOCKS.I, BLOCKS.H), new BTuple<BLOCKS, BLOCKS>(BLOCKS.H, BLOCKS.M))));
        BRelation<BLOCKS, ROUTES> _ic_set_0 = new BRelation<BLOCKS, ROUTES>();
        for(BLOCKS _ic_b_1 : _BLOCKS) {
            for(ROUTES _ic_r_1 : _ROUTES) {
                if((new BBoolean(nxt.isInDomain(_ic_r_1).booleanValue() && new BBoolean(nxt.functionCall(_ic_r_1).isInDomain(_ic_b_1).booleanValue() || nxt.functionCall(_ic_r_1).isInRange(_ic_b_1).booleanValue()).booleanValue())).booleanValue()) {
                    _ic_set_0 = _ic_set_0.union(new BRelation<BLOCKS, ROUTES>(new BTuple<BLOCKS, ROUTES>(_ic_b_1, _ic_r_1)));
                }

            }

        }

        rtbl = _ic_set_0;
        __aux_constant_1 = rtbl.inverse();
        BBoolean _ic_boolean_1 = new BBoolean(true);
        if(new BBoolean(new BBoolean(rtbl.domain().equal(_BLOCKS).booleanValue() && rtbl.range().equal(_ROUTES).booleanValue()).booleanValue() && nxt.domain().equal(_ROUTES).booleanValue()).booleanValue()) {
            for(BRelation<BLOCKS, BLOCKS> _ic__opt_1_1 : nxt.range()) {
                if(!(_ic__opt_1_1.checkDomain(_BLOCKS).and(_ic__opt_1_1.checkRange(_BLOCKS)).and(_ic__opt_1_1.isFunction()).and(_ic__opt_1_1.isPartial(_BLOCKS)).and(_ic__opt_1_1.isInjection())).booleanValue()) {
                    _ic_boolean_1 = new BBoolean(false);
                    break;
                }

            }
        }

        BBoolean _ic_boolean_2 = new BBoolean(true);
        if(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(rtbl.domain().equal(_BLOCKS).booleanValue() && rtbl.range().equal(_ROUTES).booleanValue()).booleanValue() && nxt.domain().equal(_ROUTES).booleanValue()).booleanValue() && _ic_boolean_1.booleanValue()).booleanValue() && fst.checkDomain(_ROUTES).and(fst.checkRange(_BLOCKS)).and(fst.isFunction()).and(fst.isTotal(_ROUTES)).booleanValue()).booleanValue() && lst.checkDomain(_ROUTES).and(lst.checkRange(_BLOCKS)).and(lst.isFunction()).and(lst.isTotal(_ROUTES)).booleanValue()).booleanValue()) {
            for(BTuple<BLOCKS, ROUTES> _ic__opt_2_1 : fst.inverse()) {
                if(!(rtbl.elementOf(_ic__opt_2_1)).booleanValue()) {
                    _ic_boolean_2 = new BBoolean(false);
                    break;
                }

            }
        }

        BBoolean _ic_boolean_3 = new BBoolean(true);
        if(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(rtbl.domain().equal(_BLOCKS).booleanValue() && rtbl.range().equal(_ROUTES).booleanValue()).booleanValue() && nxt.domain().equal(_ROUTES).booleanValue()).booleanValue() && _ic_boolean_1.booleanValue()).booleanValue() && fst.checkDomain(_ROUTES).and(fst.checkRange(_BLOCKS)).and(fst.isFunction()).and(fst.isTotal(_ROUTES)).booleanValue()).booleanValue() && lst.checkDomain(_ROUTES).and(lst.checkRange(_BLOCKS)).and(lst.isFunction()).and(lst.isTotal(_ROUTES)).booleanValue()).booleanValue() && _ic_boolean_2.booleanValue()).booleanValue()) {
            for(BTuple<BLOCKS, ROUTES> _ic__opt_3_1 : lst.inverse()) {
                if(!(rtbl.elementOf(_ic__opt_3_1)).booleanValue()) {
                    _ic_boolean_3 = new BBoolean(false);
                    break;
                }

            }
        }

        BBoolean _ic_boolean_4 = new BBoolean(true);
        if(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(rtbl.domain().equal(_BLOCKS).booleanValue() && rtbl.range().equal(_ROUTES).booleanValue()).booleanValue() && nxt.domain().equal(_ROUTES).booleanValue()).booleanValue() && _ic_boolean_1.booleanValue()).booleanValue() && fst.checkDomain(_ROUTES).and(fst.checkRange(_BLOCKS)).and(fst.isFunction()).and(fst.isTotal(_ROUTES)).booleanValue()).booleanValue() && lst.checkDomain(_ROUTES).and(lst.checkRange(_BLOCKS)).and(lst.isFunction()).and(lst.isTotal(_ROUTES)).booleanValue()).booleanValue() && _ic_boolean_2.booleanValue()).booleanValue() && _ic_boolean_3.booleanValue()).booleanValue()) {
            for(ROUTES _ic_r_1 : _ROUTES) {
                if(!(fst.functionCall(_ic_r_1).unequal(lst.functionCall(_ic_r_1))).booleanValue()) {
                    _ic_boolean_4 = new BBoolean(false);
                    break;
                }

            }
        }

        BBoolean _ic_boolean_6 = new BBoolean(true);
        if(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(rtbl.domain().equal(_BLOCKS).booleanValue() && rtbl.range().equal(_ROUTES).booleanValue()).booleanValue() && nxt.domain().equal(_ROUTES).booleanValue()).booleanValue() && _ic_boolean_1.booleanValue()).booleanValue() && fst.checkDomain(_ROUTES).and(fst.checkRange(_BLOCKS)).and(fst.isFunction()).and(fst.isTotal(_ROUTES)).booleanValue()).booleanValue() && lst.checkDomain(_ROUTES).and(lst.checkRange(_BLOCKS)).and(lst.isFunction()).and(lst.isTotal(_ROUTES)).booleanValue()).booleanValue() && _ic_boolean_2.booleanValue()).booleanValue() && _ic_boolean_3.booleanValue()).booleanValue() && _ic_boolean_4.booleanValue()).booleanValue()) {
            for(ROUTES _ic_r_1 : _ROUTES) {
                BBoolean _ic_boolean_5 = new BBoolean(true);
                for(BSet<BLOCKS> _ic_S_1 : nxt.functionCall(_ic_r_1).range().pow()) {
                    if(!(new BBoolean(!_ic_S_1.subset(nxt.functionCall(_ic_r_1).relationImage(_ic_S_1)).booleanValue() || _ic_S_1.equal(new BSet<BLOCKS>()).booleanValue())).booleanValue()) {
                        _ic_boolean_5 = new BBoolean(false);
                        break;
                    }

                }

                if(!(_ic_boolean_5).booleanValue()) {
                    _ic_boolean_6 = new BBoolean(false);
                    break;
                }

            }
        }

        BBoolean _ic_boolean_7 = new BBoolean(true);
        if(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(rtbl.domain().equal(_BLOCKS).booleanValue() && rtbl.range().equal(_ROUTES).booleanValue()).booleanValue() && nxt.domain().equal(_ROUTES).booleanValue()).booleanValue() && _ic_boolean_1.booleanValue()).booleanValue() && fst.checkDomain(_ROUTES).and(fst.checkRange(_BLOCKS)).and(fst.isFunction()).and(fst.isTotal(_ROUTES)).booleanValue()).booleanValue() && lst.checkDomain(_ROUTES).and(lst.checkRange(_BLOCKS)).and(lst.isFunction()).and(lst.isTotal(_ROUTES)).booleanValue()).booleanValue() && _ic_boolean_2.booleanValue()).booleanValue() && _ic_boolean_3.booleanValue()).booleanValue() && _ic_boolean_4.booleanValue()).booleanValue() && _ic_boolean_6.booleanValue()).booleanValue()) {
            for(ROUTES _ic_r_1 : _ROUTES) {
                if(!(nxt.functionCall(_ic_r_1).checkDomain(rtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)).difference(new BSet<BLOCKS>(lst.functionCall(_ic_r_1)))).and(nxt.functionCall(_ic_r_1).checkRange(rtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)).difference(new BSet<BLOCKS>(fst.functionCall(_ic_r_1))))).and(nxt.functionCall(_ic_r_1).isFunction()).and(nxt.functionCall(_ic_r_1).isTotal(rtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)).difference(new BSet<BLOCKS>(lst.functionCall(_ic_r_1))))).and(nxt.functionCall(_ic_r_1).isBijection(rtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)).difference(new BSet<BLOCKS>(fst.functionCall(_ic_r_1)))))).booleanValue()) {
                    _ic_boolean_7 = new BBoolean(false);
                    break;
                }

            }
        }

        BBoolean _ic_boolean_8 = new BBoolean(true);
        if(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(rtbl.domain().equal(_BLOCKS).booleanValue() && rtbl.range().equal(_ROUTES).booleanValue()).booleanValue() && nxt.domain().equal(_ROUTES).booleanValue()).booleanValue() && _ic_boolean_1.booleanValue()).booleanValue() && fst.checkDomain(_ROUTES).and(fst.checkRange(_BLOCKS)).and(fst.isFunction()).and(fst.isTotal(_ROUTES)).booleanValue()).booleanValue() && lst.checkDomain(_ROUTES).and(lst.checkRange(_BLOCKS)).and(lst.isFunction()).and(lst.isTotal(_ROUTES)).booleanValue()).booleanValue() && _ic_boolean_2.booleanValue()).booleanValue() && _ic_boolean_3.booleanValue()).booleanValue() && _ic_boolean_4.booleanValue()).booleanValue() && _ic_boolean_6.booleanValue()).booleanValue() && _ic_boolean_7.booleanValue()).booleanValue()) {
            for(ROUTES _ic_r_1 : _ROUTES) {
                for(ROUTES _ic_s_1 : _ROUTES) {
                    if(!(new BBoolean(!_ic_r_1.unequal(_ic_s_1).booleanValue() || new BBoolean(new BSet<BLOCKS>(fst.functionCall(_ic_s_1), lst.functionCall(_ic_s_1)).elementOf(fst.functionCall(_ic_r_1)).booleanValue() || rtbl.inverse().isNotInRelationalImage(fst.functionCall(_ic_r_1), new BSet<ROUTES>(_ic_s_1)).booleanValue()).booleanValue())).booleanValue()) {
                        _ic_boolean_8 = new BBoolean(false);
                        break;
                    }

                }

            }
        }

        BBoolean _ic_boolean_9 = new BBoolean(true);
        if(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(rtbl.domain().equal(_BLOCKS).booleanValue() && rtbl.range().equal(_ROUTES).booleanValue()).booleanValue() && nxt.domain().equal(_ROUTES).booleanValue()).booleanValue() && _ic_boolean_1.booleanValue()).booleanValue() && fst.checkDomain(_ROUTES).and(fst.checkRange(_BLOCKS)).and(fst.isFunction()).and(fst.isTotal(_ROUTES)).booleanValue()).booleanValue() && lst.checkDomain(_ROUTES).and(lst.checkRange(_BLOCKS)).and(lst.isFunction()).and(lst.isTotal(_ROUTES)).booleanValue()).booleanValue() && _ic_boolean_2.booleanValue()).booleanValue() && _ic_boolean_3.booleanValue()).booleanValue() && _ic_boolean_4.booleanValue()).booleanValue() && _ic_boolean_6.booleanValue()).booleanValue() && _ic_boolean_7.booleanValue()).booleanValue() && _ic_boolean_8.booleanValue()).booleanValue()) {
            for(ROUTES _ic_r_1 : _ROUTES) {
                for(ROUTES _ic_s_1 : _ROUTES) {
                    if(!(new BBoolean(!_ic_r_1.unequal(_ic_s_1).booleanValue() || new BBoolean(new BSet<BLOCKS>(fst.functionCall(_ic_s_1), lst.functionCall(_ic_s_1)).elementOf(lst.functionCall(_ic_r_1)).booleanValue() || rtbl.inverse().isNotInRelationalImage(lst.functionCall(_ic_r_1), new BSet<ROUTES>(_ic_s_1)).booleanValue()).booleanValue())).booleanValue()) {
                        _ic_boolean_9 = new BBoolean(false);
                        break;
                    }

                }

            }
        }

        if(!(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(rtbl.domain().equal(_BLOCKS).booleanValue() && rtbl.range().equal(_ROUTES).booleanValue()).booleanValue() && nxt.domain().equal(_ROUTES).booleanValue()).booleanValue() && _ic_boolean_1.booleanValue()).booleanValue() && fst.checkDomain(_ROUTES).and(fst.checkRange(_BLOCKS)).and(fst.isFunction()).and(fst.isTotal(_ROUTES)).booleanValue()).booleanValue() && lst.checkDomain(_ROUTES).and(lst.checkRange(_BLOCKS)).and(lst.isFunction()).and(lst.isTotal(_ROUTES)).booleanValue()).booleanValue() && _ic_boolean_2.booleanValue()).booleanValue() && _ic_boolean_3.booleanValue()).booleanValue() && _ic_boolean_4.booleanValue()).booleanValue() && _ic_boolean_6.booleanValue()).booleanValue() && _ic_boolean_7.booleanValue()).booleanValue() && _ic_boolean_8.booleanValue()).booleanValue() && _ic_boolean_9.booleanValue())).booleanValue()) {
            throw new RuntimeException("Contradiction in PROPERTIES detected!");
        }
    }

    public Train_1_beebook_deterministic_MC_POR_v3() {
        resrt = new BSet<ROUTES>();
        resbl = new BSet<BLOCKS>();
        rsrtbl = new BRelation<BLOCKS, ROUTES>();
        OCC = new BSet<BLOCKS>();
        TRK = new BRelation<BLOCKS, BLOCKS>();
        frm = new BSet<ROUTES>();
        LBT = new BSet<BLOCKS>();
    }

    public Train_1_beebook_deterministic_MC_POR_v3(Train_1_beebook_deterministic_MC_POR_v3 copy) {
        this.fst = copy.fst;
        this.lst = copy.lst;
        this.nxt = copy.nxt;
        this.rtbl = copy.rtbl;
        this.__aux_constant_1 = copy.__aux_constant_1;
        this.LBT = copy.LBT;
        this.TRK = copy.TRK;
        this.frm = copy.frm;
        this.OCC = copy.OCC;
        this.resbl = copy.resbl;
        this.resrt = copy.resrt;
        this.rsrtbl = copy.rsrtbl;
    }

    public void route_reservation(ROUTES r) {
        BSet<ROUTES> _ld_resrt = resrt;
        BRelation<BLOCKS, ROUTES> _ld_rsrtbl = rsrtbl;
        BSet<BLOCKS> _ld_resbl = resbl;
        resrt = _ld_resrt.union(new BSet<ROUTES>(r));
        rsrtbl = _ld_rsrtbl.union(rtbl.rangeRestriction(new BSet<ROUTES>(r)));
        resbl = _ld_resbl.union(__aux_constant_1.relationImage(new BSet<ROUTES>(r)));

    }

    public void route_freeing(ROUTES r) {
        BSet<ROUTES> _ld_resrt = resrt;
        BSet<ROUTES> _ld_frm = frm;
        resrt = _ld_resrt.difference(new BSet<ROUTES>(r));
        frm = _ld_frm.difference(new BSet<ROUTES>(r));

    }

    public void FRONT_MOVE_1(ROUTES r) {
        BSet<BLOCKS> _ld_OCC = OCC;

        BSet<BLOCKS> _ld_LBT = LBT;
        OCC = _ld_OCC.union(new BSet<BLOCKS>(fst.functionCall(r)));
        LBT = _ld_LBT.union(new BSet<BLOCKS>(fst.functionCall(r)));

    }

    public void FRONT_MOVE_2(BLOCKS b) {
        OCC = OCC.union(new BSet<BLOCKS>(TRK.functionCall(b)));

    }

    public void BACK_MOVE_1(BLOCKS b) {
        BSet<BLOCKS> _ld_OCC = OCC;

        BSet<BLOCKS> _ld_LBT = LBT;
        BRelation<BLOCKS, ROUTES> _ld_rsrtbl = rsrtbl;
        BSet<BLOCKS> _ld_resbl = resbl;
        OCC = _ld_OCC.difference(new BSet<BLOCKS>(b));
        rsrtbl = _ld_rsrtbl.domainSubstraction(new BSet<BLOCKS>(b));
        resbl = _ld_resbl.difference(new BSet<BLOCKS>(b));
        LBT = _ld_LBT.difference(new BSet<BLOCKS>(b));

    }

    public void BACK_MOVE_2(BLOCKS b) {
        BSet<BLOCKS> _ld_OCC = OCC;

        BSet<BLOCKS> _ld_LBT = LBT;
        BRelation<BLOCKS, ROUTES> _ld_rsrtbl = rsrtbl;
        BSet<BLOCKS> _ld_resbl = resbl;
        OCC = _ld_OCC.difference(new BSet<BLOCKS>(b));
        rsrtbl = _ld_rsrtbl.domainSubstraction(new BSet<BLOCKS>(b));
        resbl = _ld_resbl.difference(new BSet<BLOCKS>(b));
        LBT = _ld_LBT.difference(new BSet<BLOCKS>(b)).union(new BSet<BLOCKS>(TRK.functionCall(b)));

    }

    public void point_positionning(ROUTES r) {
        TRK = TRK.domainSubstraction(nxt.functionCall(r).domain()).rangeSubstraction(nxt.functionCall(r).range()).union(nxt.functionCall(r));

    }

    public void route_formation(ROUTES r) {
        frm = frm.union(new BSet<ROUTES>(r));

    }

    public BRelation<ROUTES, BLOCKS> _get_fst() {
        return fst;
    }

    public BRelation<ROUTES, BLOCKS> _get_lst() {
        return lst;
    }

    public BRelation<ROUTES, BRelation<BLOCKS, BLOCKS>> _get_nxt() {
        return nxt;
    }

    public BRelation<BLOCKS, ROUTES> _get_rtbl() {
        return rtbl;
    }

    public BRelation<ROUTES, BLOCKS> _get___aux_constant_1() {
        return __aux_constant_1;
    }

    public BSet<BLOCKS> _get_LBT() {
        return LBT;
    }

    public BRelation<BLOCKS, BLOCKS> _get_TRK() {
        return TRK;
    }

    public BSet<ROUTES> _get_frm() {
        return frm;
    }

    public BSet<BLOCKS> _get_OCC() {
        return OCC;
    }

    public BSet<BLOCKS> _get_resbl() {
        return resbl;
    }

    public BSet<ROUTES> _get_resrt() {
        return resrt;
    }

    public BRelation<BLOCKS, ROUTES> _get_rsrtbl() {
        return rsrtbl;
    }

    public BSet<BLOCKS> _get__BLOCKS() {
        return _BLOCKS;
    }

    public BSet<ROUTES> _get__ROUTES() {
        return _ROUTES;
    }

    @Override
    public boolean equals(Object o) {
        Train_1_beebook_deterministic_MC_POR_v3 o1 = this;
        Train_1_beebook_deterministic_MC_POR_v3 o2 = (Train_1_beebook_deterministic_MC_POR_v3) o;
        return o1._get_LBT().equals(o2._get_LBT()) && o1._get_TRK().equals(o2._get_TRK()) && o1._get_frm().equals(o2._get_frm()) && o1._get_OCC().equals(o2._get_OCC()) && o1._get_resbl().equals(o2._get_resbl()) && o1._get_resrt().equals(o2._get_resrt()) && o1._get_rsrtbl().equals(o2._get_rsrtbl());
    }



    @Override
    public int hashCode() {
        return this._hashCode_1();
    }

    public int _hashCode_1() {
        int result = 1;
        result = (1543 * result) ^ ((this._get_LBT()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_TRK()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_frm()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_OCC()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_resbl()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_resrt()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_rsrtbl()).hashCode() << 1);
        return result;
    }

    public int _hashCode_2() {
        int result = 1;
        result = (6151 * result) ^ ((this._get_LBT()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_TRK()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_frm()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_OCC()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_resbl()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_resrt()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_rsrtbl()).hashCode() << 1);
        return result;
    }

    @Override
    public String toString() {
        return String.join("\n", "_get_LBT: " + (this._get_LBT()).toString(), "_get_TRK: " + (this._get_TRK()).toString(), "_get_frm: " + (this._get_frm()).toString(), "_get_OCC: " + (this._get_OCC()).toString(), "_get_resbl: " + (this._get_resbl()).toString(), "_get_resrt: " + (this._get_resrt()).toString(), "_get_rsrtbl: " + (this._get_rsrtbl()).toString());
    }

    public Train_1_beebook_deterministic_MC_POR_v3 _copy() {
        return new Train_1_beebook_deterministic_MC_POR_v3(this);
    }


    public BSet<ROUTES> _tr_route_reservation() {
        BSet<ROUTES> _ic_set_10 = new BSet<ROUTES>();
        for(ROUTES _ic_r_1 : _ROUTES.difference(resrt)) {
            if((new BBoolean(__aux_constant_1.relationImage(new BSet<ROUTES>(_ic_r_1)).intersect(resbl).equal(new BSet<BLOCKS>()).booleanValue() && new BSet<ROUTES>().equal(resrt.difference(rsrtbl.range())).booleanValue())).booleanValue()) {
                _ic_set_10 = _ic_set_10.union(new BSet<ROUTES>(_ic_r_1));
            }

        }

        return _ic_set_10;
    }

    public BSet<ROUTES> _tr_route_freeing() {
        BSet<ROUTES> _ic_set_11 = new BSet<ROUTES>();
        for(ROUTES _ic_r_1 : resrt.difference(rsrtbl.range())) {
            _ic_set_11 = _ic_set_11.union(new BSet<ROUTES>(_ic_r_1));

        }

        return _ic_set_11;
    }

    public BSet<ROUTES> _tr_FRONT_MOVE_1() {
        BSet<ROUTES> _ic_set_12 = new BSet<ROUTES>();
        for(ROUTES _ic_r_1 : frm) {
            if((new BBoolean(new BBoolean(resbl.difference(OCC).elementOf(fst.functionCall(_ic_r_1)).booleanValue() && _ic_r_1.equal(rsrtbl.functionCall(fst.functionCall(_ic_r_1))).booleanValue()).booleanValue() && new BSet<ROUTES>().equal(resrt.difference(rsrtbl.range())).booleanValue())).booleanValue()) {
                _ic_set_12 = _ic_set_12.union(new BSet<ROUTES>(_ic_r_1));
            }

        }

        return _ic_set_12;
    }

    public BSet<BLOCKS> _tr_FRONT_MOVE_2() {
        BSet<BLOCKS> _ic_set_13 = new BSet<BLOCKS>();
        for(BLOCKS _ic_b_1 : OCC.intersect(TRK.domain())) {
            if((OCC.notElementOf(TRK.functionCall(_ic_b_1))).booleanValue()) {
                _ic_set_13 = _ic_set_13.union(new BSet<BLOCKS>(_ic_b_1));
            }

        }

        return _ic_set_13;
    }

    public BSet<BLOCKS> _tr_BACK_MOVE_1() {
        BSet<BLOCKS> _ic_set_14 = new BSet<BLOCKS>();
        for(BLOCKS _ic_b_1 : LBT.difference(TRK.domain())) {
            if((new BSet<ROUTES>().equal(resrt.difference(rsrtbl.range()))).booleanValue()) {
                _ic_set_14 = _ic_set_14.union(new BSet<BLOCKS>(_ic_b_1));
            }

        }

        return _ic_set_14;
    }

    public BSet<BLOCKS> _tr_BACK_MOVE_2() {
        BSet<BLOCKS> _ic_set_15 = new BSet<BLOCKS>();
        for(BLOCKS _ic_b_1 : LBT.intersect(TRK.domain())) {
            if((new BBoolean(OCC.elementOf(TRK.functionCall(_ic_b_1)).booleanValue() && new BSet<ROUTES>().equal(resrt.difference(rsrtbl.range())).booleanValue())).booleanValue()) {
                _ic_set_15 = _ic_set_15.union(new BSet<BLOCKS>(_ic_b_1));
            }

        }

        return _ic_set_15;
    }

    public BSet<ROUTES> _tr_point_positionning() {
        BSet<ROUTES> _ic_set_16 = new BSet<ROUTES>();
        for(ROUTES _ic_r_1 : resrt.difference(frm)) {
            if((new BSet<ROUTES>().equal(resrt.difference(rsrtbl.range()))).booleanValue()) {
                _ic_set_16 = _ic_set_16.union(new BSet<ROUTES>(_ic_r_1));
            }

        }

        return _ic_set_16;
    }

    public BSet<ROUTES> _tr_route_formation() {
        BSet<ROUTES> _ic_set_17 = new BSet<ROUTES>();
        for(ROUTES _ic_r_1 : resrt.difference(frm)) {
            if((new BBoolean(nxt.functionCall(_ic_r_1).domainRestriction(rsrtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1))).equal(TRK.domainRestriction(rsrtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)))).booleanValue() && new BSet<ROUTES>().equal(resrt.difference(rsrtbl.range())).booleanValue())).booleanValue()) {
                _ic_set_17 = _ic_set_17.union(new BSet<ROUTES>(_ic_r_1));
            }

        }

        return _ic_set_17;
    }

    public _ProjectionRead_point_positionning _projected_state_for_point_positionning() {
        return new _ProjectionRead_point_positionning(frm,resrt,TRK,rsrtbl);
    }

    public _ProjectionRead_route_reservation _projected_state_for_route_reservation() {
        return new _ProjectionRead_route_reservation(resrt,resbl,rsrtbl);
    }

    public _ProjectionRead_FRONT_MOVE_1 _projected_state_for_FRONT_MOVE_1() {
        return new _ProjectionRead_FRONT_MOVE_1(frm,resrt,resbl,OCC,rsrtbl,LBT);
    }

    public _ProjectionRead_BACK_MOVE_1 _projected_state_for_BACK_MOVE_1() {
        return new _ProjectionRead_BACK_MOVE_1(resrt,TRK,resbl,OCC,LBT,rsrtbl);
    }

    public _ProjectionRead_FRONT_MOVE_2 _projected_state_for_FRONT_MOVE_2() {
        return new _ProjectionRead_FRONT_MOVE_2(TRK,OCC);
    }

    public _ProjectionRead_route_formation _projected_state_for_route_formation() {
        return new _ProjectionRead_route_formation(frm,resrt,TRK,rsrtbl);
    }

    public _ProjectionRead_route_freeing _projected_state_for_route_freeing() {
        return new _ProjectionRead_route_freeing(frm,resrt,rsrtbl);
    }

    public _ProjectionRead_BACK_MOVE_2 _projected_state_for_BACK_MOVE_2() {
        return new _ProjectionRead_BACK_MOVE_2(resrt,TRK,resbl,OCC,LBT,rsrtbl);
    }

    public _ProjectionRead__tr_route_formation _projected_state_for__tr_route_formation() {
        return new _ProjectionRead__tr_route_formation(frm,resrt,TRK,rsrtbl);
    }

    public _ProjectionRead__tr_FRONT_MOVE_1 _projected_state_for__tr_FRONT_MOVE_1() {
        return new _ProjectionRead__tr_FRONT_MOVE_1(frm,resrt,resbl,OCC,rsrtbl);
    }

    public _ProjectionRead__tr_route_reservation _projected_state_for__tr_route_reservation() {
        return new _ProjectionRead__tr_route_reservation(resrt,resbl,rsrtbl);
    }

    public _ProjectionRead__tr_route_freeing _projected_state_for__tr_route_freeing() {
        return new _ProjectionRead__tr_route_freeing(resrt,rsrtbl);
    }

    public _ProjectionRead__tr_BACK_MOVE_1 _projected_state_for__tr_BACK_MOVE_1() {
        return new _ProjectionRead__tr_BACK_MOVE_1(resrt,TRK,LBT,rsrtbl);
    }

    public _ProjectionRead__tr_point_positionning _projected_state_for__tr_point_positionning() {
        return new _ProjectionRead__tr_point_positionning(frm,resrt,rsrtbl);
    }

    public _ProjectionRead__tr_FRONT_MOVE_2 _projected_state_for__tr_FRONT_MOVE_2() {
        return new _ProjectionRead__tr_FRONT_MOVE_2(TRK,OCC);
    }

    public _ProjectionRead__tr_BACK_MOVE_2 _projected_state_for__tr_BACK_MOVE_2() {
        return new _ProjectionRead__tr_BACK_MOVE_2(resrt,TRK,OCC,LBT,rsrtbl);
    }

    public _ProjectionRead__check_inv_6 _projected_state_for__check_inv_6() {
        return new _ProjectionRead__check_inv_6(OCC,rsrtbl);
    }

    public _ProjectionRead__check_inv_10 _projected_state_for__check_inv_10() {
        return new _ProjectionRead__check_inv_10(frm,resrt,rsrtbl);
    }

    public _ProjectionRead__check_inv_7 _projected_state_for__check_inv_7() {
        return new _ProjectionRead__check_inv_7(TRK);
    }

    public _ProjectionRead__check_inv_4 _projected_state_for__check_inv_4() {
        return new _ProjectionRead__check_inv_4(OCC,rsrtbl);
    }

    public _ProjectionRead__check_inv_5 _projected_state_for__check_inv_5() {
        return new _ProjectionRead__check_inv_5(rsrtbl);
    }

    public _ProjectionRead__check_inv_14 _projected_state_for__check_inv_14() {
        return new _ProjectionRead__check_inv_14(LBT,rsrtbl);
    }

    public _ProjectionRead__check_inv_13 _projected_state_for__check_inv_13() {
        return new _ProjectionRead__check_inv_13(OCC,LBT);
    }

    public _ProjectionRead__check_inv_8 _projected_state_for__check_inv_8() {
        return new _ProjectionRead__check_inv_8(frm,resrt);
    }

    public _ProjectionRead__check_inv_12 _projected_state_for__check_inv_12() {
        return new _ProjectionRead__check_inv_12(frm,TRK,rsrtbl);
    }

    public _ProjectionRead__check_inv_9 _projected_state_for__check_inv_9() {
        return new _ProjectionRead__check_inv_9(frm,OCC,rsrtbl);
    }

    public _ProjectionRead__check_inv_11 _projected_state_for__check_inv_11() {
        return new _ProjectionRead__check_inv_11(TRK);
    }

    public _ProjectionRead__check_inv_2 _projected_state_for__check_inv_2() {
        return new _ProjectionRead__check_inv_2(rsrtbl);
    }

    public _ProjectionRead__check_inv_3 _projected_state_for__check_inv_3() {
        return new _ProjectionRead__check_inv_3(resbl,OCC);
    }

    public _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() {
        return new _ProjectionRead__check_inv_1(resrt,resbl,rsrtbl);
    }

    public _ProjectionWrite_point_positionning _update_for_point_positionning() {
        return new _ProjectionWrite_point_positionning(TRK);
    }

    public _ProjectionWrite_route_reservation _update_for_route_reservation() {
        return new _ProjectionWrite_route_reservation(resrt,resbl,rsrtbl);
    }

    public _ProjectionWrite_FRONT_MOVE_1 _update_for_FRONT_MOVE_1() {
        return new _ProjectionWrite_FRONT_MOVE_1(OCC,LBT);
    }

    public _ProjectionWrite_BACK_MOVE_1 _update_for_BACK_MOVE_1() {
        return new _ProjectionWrite_BACK_MOVE_1(resbl,OCC,rsrtbl,LBT);
    }

    public _ProjectionWrite_FRONT_MOVE_2 _update_for_FRONT_MOVE_2() {
        return new _ProjectionWrite_FRONT_MOVE_2(OCC);
    }

    public _ProjectionWrite_route_formation _update_for_route_formation() {
        return new _ProjectionWrite_route_formation(frm);
    }

    public _ProjectionWrite_route_freeing _update_for_route_freeing() {
        return new _ProjectionWrite_route_freeing(frm,resrt);
    }

    public _ProjectionWrite_BACK_MOVE_2 _update_for_BACK_MOVE_2() {
        return new _ProjectionWrite_BACK_MOVE_2(resbl,OCC,rsrtbl,LBT);
    }

    public void _apply_update_for_point_positionning(_ProjectionWrite_point_positionning update) {
        this.TRK = update.TRK;
    }

    public void _apply_update_for_route_reservation(_ProjectionWrite_route_reservation update) {
        this.resrt = update.resrt;
        this.resbl = update.resbl;
        this.rsrtbl = update.rsrtbl;
    }

    public void _apply_update_for_FRONT_MOVE_1(_ProjectionWrite_FRONT_MOVE_1 update) {
        this.OCC = update.OCC;
        this.LBT = update.LBT;
    }

    public void _apply_update_for_BACK_MOVE_1(_ProjectionWrite_BACK_MOVE_1 update) {
        this.resbl = update.resbl;
        this.OCC = update.OCC;
        this.rsrtbl = update.rsrtbl;
        this.LBT = update.LBT;
    }

    public void _apply_update_for_FRONT_MOVE_2(_ProjectionWrite_FRONT_MOVE_2 update) {
        this.OCC = update.OCC;
    }

    public void _apply_update_for_route_formation(_ProjectionWrite_route_formation update) {
        this.frm = update.frm;
    }

    public void _apply_update_for_route_freeing(_ProjectionWrite_route_freeing update) {
        this.frm = update.frm;
        this.resrt = update.resrt;
    }

    public void _apply_update_for_BACK_MOVE_2(_ProjectionWrite_BACK_MOVE_2 update) {
        this.resbl = update.resbl;
        this.OCC = update.OCC;
        this.rsrtbl = update.rsrtbl;
        this.LBT = update.LBT;
    }

    public boolean _check_inv_1() {
        return rsrtbl.checkDomain(resbl).and(rsrtbl.checkRange(resrt)).and(rsrtbl.isFunction()).and(rsrtbl.isTotal(resbl)).booleanValue();
    }

    public boolean _check_inv_2() {
        BBoolean _ic_boolean_18 = new BBoolean(true);
        for(BTuple<BLOCKS, ROUTES> _ic__opt_4_1 : rsrtbl) {
            if(!(rtbl.elementOf(_ic__opt_4_1)).booleanValue()) {
                _ic_boolean_18 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_18.booleanValue();
    }

    public boolean _check_inv_3() {
        BBoolean _ic_boolean_19 = new BBoolean(true);
        for(BLOCKS _ic__opt_5_1 : OCC) {
            if(!(resbl.elementOf(_ic__opt_5_1)).booleanValue()) {
                _ic_boolean_19 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_19.booleanValue();
    }

    public boolean _check_inv_4() {
        BBoolean _ic_boolean_20 = new BBoolean(true);
        for(ROUTES _ic_r_1 : _ROUTES) {
            if(!(nxt.functionCall(_ic_r_1).relationImage(__aux_constant_1.relationImage(new BSet<ROUTES>(_ic_r_1)).difference(rsrtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)))).intersect(rsrtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)).difference(OCC)).equal(new BSet<BLOCKS>())).booleanValue()) {
                _ic_boolean_20 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_20.booleanValue();
    }

    public boolean _check_inv_5() {
        BBoolean _ic_boolean_22 = new BBoolean(true);
        for(ROUTES _ic_r_1 : _ROUTES) {
            BBoolean _ic_boolean_21 = new BBoolean(true);
            for(BLOCKS _ic__opt_6_1 : nxt.functionCall(_ic_r_1).relationImage(rsrtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)))) {
                if(!(rsrtbl.inverse().isInRelationalImage(_ic__opt_6_1, new BSet<ROUTES>(_ic_r_1))).booleanValue()) {
                    _ic_boolean_21 = new BBoolean(false);
                    break;
                }

            }

            if(!(_ic_boolean_21).booleanValue()) {
                _ic_boolean_22 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_22.booleanValue();
    }

    public boolean _check_inv_6() {
        BBoolean _ic_boolean_24 = new BBoolean(true);
        for(ROUTES _ic_r_1 : _ROUTES) {
            BBoolean _ic_boolean_23 = new BBoolean(true);
            for(BLOCKS _ic__opt_7_1 : nxt.functionCall(_ic_r_1).relationImage(rsrtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)).difference(OCC))) {
                if(!(new BBoolean(rsrtbl.inverse().isInRelationalImage(_ic__opt_7_1, new BSet<ROUTES>(_ic_r_1)).booleanValue() && OCC.notElementOf(_ic__opt_7_1).booleanValue())).booleanValue()) {
                    _ic_boolean_23 = new BBoolean(false);
                    break;
                }

            }

            if(!(_ic_boolean_23).booleanValue()) {
                _ic_boolean_24 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_24.booleanValue();
    }

    public boolean _check_inv_7() {
        return TRK.checkDomain(_BLOCKS).and(TRK.checkRange(_BLOCKS)).and(TRK.isFunction()).and(TRK.isPartial(_BLOCKS)).and(TRK.isInjection()).booleanValue();
    }

    public boolean _check_inv_8() {
        BBoolean _ic_boolean_25 = new BBoolean(true);
        for(ROUTES _ic__opt_8_1 : frm) {
            if(!(resrt.elementOf(_ic__opt_8_1)).booleanValue()) {
                _ic_boolean_25 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_25.booleanValue();
    }

    public boolean _check_inv_9() {
        BBoolean _ic_boolean_26 = new BBoolean(true);
        for(ROUTES _ic__opt_9_1 : rsrtbl.relationImage(OCC)) {
            if(!(frm.elementOf(_ic__opt_9_1)).booleanValue()) {
                _ic_boolean_26 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_26.booleanValue();
    }

    public boolean _check_inv_10() {
        BBoolean _ic_boolean_27 = new BBoolean(true);
        for(ROUTES _ic_r_1 : resrt.difference(frm)) {
            if(!(rtbl.rangeRestriction(new BSet<ROUTES>(_ic_r_1)).equal(rsrtbl.rangeRestriction(new BSet<ROUTES>(_ic_r_1)))).booleanValue()) {
                _ic_boolean_27 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_27.booleanValue();
    }

    public boolean _check_inv_11() {
        BBoolean _ic_boolean_29 = new BBoolean(true);
        for(BLOCKS _ic_x_1 : _BLOCKS) {
            for(BLOCKS _ic_y_1 : _BLOCKS) {
                BBoolean _ic_boolean_28 = new BBoolean(false);
                for(ROUTES _ic_r_1 : _ROUTES) {
                    if((nxt.functionCall(_ic_r_1).elementOf(new BTuple<BLOCKS, BLOCKS>(_ic_x_1, _ic_y_1))).booleanValue()) {
                        _ic_boolean_28 = new BBoolean(true);
                        break;
                    }

                }

                if(!(new BBoolean(!TRK.elementOf(new BTuple<BLOCKS, BLOCKS>(_ic_x_1, _ic_y_1)).booleanValue() || _ic_boolean_28.booleanValue())).booleanValue()) {
                    _ic_boolean_29 = new BBoolean(false);
                    break;
                }

            }

        }

        return _ic_boolean_29.booleanValue();
    }

    public boolean _check_inv_12() {
        BBoolean _ic_boolean_30 = new BBoolean(true);
        for(ROUTES _ic_r_1 : frm) {
            if(!(nxt.functionCall(_ic_r_1).domainRestriction(rsrtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1))).equal(TRK.domainRestriction(rsrtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1))))).booleanValue()) {
                _ic_boolean_30 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_30.booleanValue();
    }

    public boolean _check_inv_13() {
        BBoolean _ic_boolean_31 = new BBoolean(true);
        for(BLOCKS _ic__opt_10_1 : LBT) {
            if(!(OCC.elementOf(_ic__opt_10_1)).booleanValue()) {
                _ic_boolean_31 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_31.booleanValue();
    }

    public boolean _check_inv_14() {
        BBoolean _ic_boolean_32 = new BBoolean(true);
        for(BLOCKS _ic_a_1 : _BLOCKS) {
            for(BLOCKS _ic_b_1 : LBT) {
                if(!(new BBoolean(!new BBoolean(new BBoolean(nxt.functionCall(rsrtbl.functionCall(_ic_b_1)).isInRange(_ic_b_1).booleanValue() && _ic_a_1.equal(nxt.functionCall(rsrtbl.functionCall(_ic_b_1)).inverse().functionCall(_ic_b_1)).booleanValue()).booleanValue() && rsrtbl.isInDomain(_ic_a_1).booleanValue()).booleanValue() || rsrtbl.functionCall(_ic_a_1).unequal(rsrtbl.functionCall(_ic_b_1)).booleanValue())).booleanValue()) {
                    _ic_boolean_32 = new BBoolean(false);
                    break;
                }

            }

        }

        return _ic_boolean_32.booleanValue();
    }


    private static class ModelChecker {
        private final Type type;
        private final int threads;
        private final boolean isCaching;
        private final boolean isDebug;

        private final LinkedList<Train_1_beebook_deterministic_MC_POR_v3> unvisitedStates = new LinkedList<>();
        private final Set<Train_1_beebook_deterministic_MC_POR_v3> states = ConcurrentHashMap.newKeySet();
        private AtomicInteger transitions = new AtomicInteger(0);
        private ThreadPoolExecutor threadPool;
        private Object waitLock = new Object();

        private AtomicBoolean invariantViolated = new AtomicBoolean(false);
        private AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        private Train_1_beebook_deterministic_MC_POR_v3 counterExampleState = null;

        PersistentHashMap _OpCache_route_reservation = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_route_reservation = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_route_freeing = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_route_freeing = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_FRONT_MOVE_1 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_FRONT_MOVE_1 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_FRONT_MOVE_2 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_FRONT_MOVE_2 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_BACK_MOVE_1 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_BACK_MOVE_1 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_BACK_MOVE_2 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_BACK_MOVE_2 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_point_positionning = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_point_positionning = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_route_formation = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_route_formation = PersistentHashMap.EMPTY;
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
            Train_1_beebook_deterministic_MC_POR_v3 machine = new Train_1_beebook_deterministic_MC_POR_v3();
            states.add(machine);
            unvisitedStates.add(machine);

            while(!unvisitedStates.isEmpty()) {
                Train_1_beebook_deterministic_MC_POR_v3 state = next();

                Set<Train_1_beebook_deterministic_MC_POR_v3> nextStates = generateNextStates(state);

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
            Train_1_beebook_deterministic_MC_POR_v3 machine = new Train_1_beebook_deterministic_MC_POR_v3();
            states.add(machine);
            unvisitedStates.add(machine);

            AtomicBoolean stopThreads = new AtomicBoolean(false);
            AtomicInteger possibleQueueChanges = new AtomicInteger(0);

            while(!unvisitedStates.isEmpty() && !stopThreads.get()) {
                possibleQueueChanges.incrementAndGet();
                Train_1_beebook_deterministic_MC_POR_v3 state = next();
                Runnable task = () -> {
                    Set<Train_1_beebook_deterministic_MC_POR_v3> nextStates = generateNextStates(state);

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

        private Train_1_beebook_deterministic_MC_POR_v3 next() {
            synchronized(this.unvisitedStates) {
                return switch(type) {
                    case BFS -> this.unvisitedStates.removeFirst();
                    case DFS -> this.unvisitedStates.removeLast();
                    case MIXED -> this.unvisitedStates.size() % 2 == 0 ? this.unvisitedStates.removeFirst() : this.unvisitedStates.removeLast();
                };
            }
        }

        @SuppressWarnings("unchecked")
        private Set<Train_1_beebook_deterministic_MC_POR_v3> generateNextStates(final Train_1_beebook_deterministic_MC_POR_v3 state) {
            Set<Train_1_beebook_deterministic_MC_POR_v3> result = new HashSet<>();
            if(isCaching) {
                _ProjectionRead__tr_route_reservation read__tr_route_reservation_state = state._projected_state_for__tr_route_reservation();
                BSet<ROUTES> _trid_1 = (BSet<ROUTES>) GET.invoke(_OpCache_tr_route_reservation, read__tr_route_reservation_state);
                if(_trid_1 == null) {
                    _trid_1 = state._tr_route_reservation();
                    _OpCache_tr_route_reservation = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_route_reservation, read__tr_route_reservation_state, _trid_1);
                }
                for(ROUTES param : _trid_1) {
                    ROUTES _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    _ProjectionRead_route_reservation readState = state._projected_state_for_route_reservation();
                    PersistentHashMap _OpCache_with_parameter_route_reservation = (PersistentHashMap) GET.invoke(_OpCache_route_reservation, param);
                    if(_OpCache_with_parameter_route_reservation != null) {
                        _ProjectionWrite_route_reservation writeState = (_ProjectionWrite_route_reservation) GET.invoke(_OpCache_with_parameter_route_reservation, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_route_reservation(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.route_reservation(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_route_reservation();
                            _OpCache_with_parameter_route_reservation = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_route_reservation, readState, writeState);
                            _OpCache_route_reservation = (PersistentHashMap) ASSOC.invoke(_OpCache_route_reservation, param, _OpCache_with_parameter_route_reservation);
                        }

                    } else {
                        copiedState.route_reservation(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_route_reservation writeState = copiedState._update_for_route_reservation();
                        _OpCache_with_parameter_route_reservation = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_route_reservation = (PersistentHashMap) ASSOC.invoke(_OpCache_route_reservation, param, _OpCache_with_parameter_route_reservation);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_route_freeing read__tr_route_freeing_state = state._projected_state_for__tr_route_freeing();
                BSet<ROUTES> _trid_2 = (BSet<ROUTES>) GET.invoke(_OpCache_tr_route_freeing, read__tr_route_freeing_state);
                if(_trid_2 == null) {
                    _trid_2 = state._tr_route_freeing();
                    _OpCache_tr_route_freeing = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_route_freeing, read__tr_route_freeing_state, _trid_2);
                }
                for(ROUTES param : _trid_2) {
                    ROUTES _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    _ProjectionRead_route_freeing readState = state._projected_state_for_route_freeing();
                    PersistentHashMap _OpCache_with_parameter_route_freeing = (PersistentHashMap) GET.invoke(_OpCache_route_freeing, param);
                    if(_OpCache_with_parameter_route_freeing != null) {
                        _ProjectionWrite_route_freeing writeState = (_ProjectionWrite_route_freeing) GET.invoke(_OpCache_with_parameter_route_freeing, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_route_freeing(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.route_freeing(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_route_freeing();
                            _OpCache_with_parameter_route_freeing = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_route_freeing, readState, writeState);
                            _OpCache_route_freeing = (PersistentHashMap) ASSOC.invoke(_OpCache_route_freeing, param, _OpCache_with_parameter_route_freeing);
                        }

                    } else {
                        copiedState.route_freeing(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_route_freeing writeState = copiedState._update_for_route_freeing();
                        _OpCache_with_parameter_route_freeing = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_route_freeing = (PersistentHashMap) ASSOC.invoke(_OpCache_route_freeing, param, _OpCache_with_parameter_route_freeing);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_FRONT_MOVE_1 read__tr_FRONT_MOVE_1_state = state._projected_state_for__tr_FRONT_MOVE_1();
                BSet<ROUTES> _trid_3 = (BSet<ROUTES>) GET.invoke(_OpCache_tr_FRONT_MOVE_1, read__tr_FRONT_MOVE_1_state);
                if(_trid_3 == null) {
                    _trid_3 = state._tr_FRONT_MOVE_1();
                    _OpCache_tr_FRONT_MOVE_1 = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_FRONT_MOVE_1, read__tr_FRONT_MOVE_1_state, _trid_3);
                }
                for(ROUTES param : _trid_3) {
                    ROUTES _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    _ProjectionRead_FRONT_MOVE_1 readState = state._projected_state_for_FRONT_MOVE_1();
                    PersistentHashMap _OpCache_with_parameter_FRONT_MOVE_1 = (PersistentHashMap) GET.invoke(_OpCache_FRONT_MOVE_1, param);
                    if(_OpCache_with_parameter_FRONT_MOVE_1 != null) {
                        _ProjectionWrite_FRONT_MOVE_1 writeState = (_ProjectionWrite_FRONT_MOVE_1) GET.invoke(_OpCache_with_parameter_FRONT_MOVE_1, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_FRONT_MOVE_1(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.FRONT_MOVE_1(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_FRONT_MOVE_1();
                            _OpCache_with_parameter_FRONT_MOVE_1 = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_FRONT_MOVE_1, readState, writeState);
                            _OpCache_FRONT_MOVE_1 = (PersistentHashMap) ASSOC.invoke(_OpCache_FRONT_MOVE_1, param, _OpCache_with_parameter_FRONT_MOVE_1);
                        }

                    } else {
                        copiedState.FRONT_MOVE_1(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_FRONT_MOVE_1 writeState = copiedState._update_for_FRONT_MOVE_1();
                        _OpCache_with_parameter_FRONT_MOVE_1 = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_FRONT_MOVE_1 = (PersistentHashMap) ASSOC.invoke(_OpCache_FRONT_MOVE_1, param, _OpCache_with_parameter_FRONT_MOVE_1);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_FRONT_MOVE_2 read__tr_FRONT_MOVE_2_state = state._projected_state_for__tr_FRONT_MOVE_2();
                BSet<BLOCKS> _trid_4 = (BSet<BLOCKS>) GET.invoke(_OpCache_tr_FRONT_MOVE_2, read__tr_FRONT_MOVE_2_state);
                if(_trid_4 == null) {
                    _trid_4 = state._tr_FRONT_MOVE_2();
                    _OpCache_tr_FRONT_MOVE_2 = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_FRONT_MOVE_2, read__tr_FRONT_MOVE_2_state, _trid_4);
                }
                for(BLOCKS param : _trid_4) {
                    BLOCKS _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    _ProjectionRead_FRONT_MOVE_2 readState = state._projected_state_for_FRONT_MOVE_2();
                    PersistentHashMap _OpCache_with_parameter_FRONT_MOVE_2 = (PersistentHashMap) GET.invoke(_OpCache_FRONT_MOVE_2, param);
                    if(_OpCache_with_parameter_FRONT_MOVE_2 != null) {
                        _ProjectionWrite_FRONT_MOVE_2 writeState = (_ProjectionWrite_FRONT_MOVE_2) GET.invoke(_OpCache_with_parameter_FRONT_MOVE_2, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_FRONT_MOVE_2(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.FRONT_MOVE_2(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_FRONT_MOVE_2();
                            _OpCache_with_parameter_FRONT_MOVE_2 = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_FRONT_MOVE_2, readState, writeState);
                            _OpCache_FRONT_MOVE_2 = (PersistentHashMap) ASSOC.invoke(_OpCache_FRONT_MOVE_2, param, _OpCache_with_parameter_FRONT_MOVE_2);
                        }

                    } else {
                        copiedState.FRONT_MOVE_2(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_FRONT_MOVE_2 writeState = copiedState._update_for_FRONT_MOVE_2();
                        _OpCache_with_parameter_FRONT_MOVE_2 = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_FRONT_MOVE_2 = (PersistentHashMap) ASSOC.invoke(_OpCache_FRONT_MOVE_2, param, _OpCache_with_parameter_FRONT_MOVE_2);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_BACK_MOVE_1 read__tr_BACK_MOVE_1_state = state._projected_state_for__tr_BACK_MOVE_1();
                BSet<BLOCKS> _trid_5 = (BSet<BLOCKS>) GET.invoke(_OpCache_tr_BACK_MOVE_1, read__tr_BACK_MOVE_1_state);
                if(_trid_5 == null) {
                    _trid_5 = state._tr_BACK_MOVE_1();
                    _OpCache_tr_BACK_MOVE_1 = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_BACK_MOVE_1, read__tr_BACK_MOVE_1_state, _trid_5);
                }
                for(BLOCKS param : _trid_5) {
                    BLOCKS _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    _ProjectionRead_BACK_MOVE_1 readState = state._projected_state_for_BACK_MOVE_1();
                    PersistentHashMap _OpCache_with_parameter_BACK_MOVE_1 = (PersistentHashMap) GET.invoke(_OpCache_BACK_MOVE_1, param);
                    if(_OpCache_with_parameter_BACK_MOVE_1 != null) {
                        _ProjectionWrite_BACK_MOVE_1 writeState = (_ProjectionWrite_BACK_MOVE_1) GET.invoke(_OpCache_with_parameter_BACK_MOVE_1, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_BACK_MOVE_1(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.BACK_MOVE_1(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_BACK_MOVE_1();
                            _OpCache_with_parameter_BACK_MOVE_1 = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_BACK_MOVE_1, readState, writeState);
                            _OpCache_BACK_MOVE_1 = (PersistentHashMap) ASSOC.invoke(_OpCache_BACK_MOVE_1, param, _OpCache_with_parameter_BACK_MOVE_1);
                        }

                    } else {
                        copiedState.BACK_MOVE_1(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_BACK_MOVE_1 writeState = copiedState._update_for_BACK_MOVE_1();
                        _OpCache_with_parameter_BACK_MOVE_1 = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_BACK_MOVE_1 = (PersistentHashMap) ASSOC.invoke(_OpCache_BACK_MOVE_1, param, _OpCache_with_parameter_BACK_MOVE_1);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_BACK_MOVE_2 read__tr_BACK_MOVE_2_state = state._projected_state_for__tr_BACK_MOVE_2();
                BSet<BLOCKS> _trid_6 = (BSet<BLOCKS>) GET.invoke(_OpCache_tr_BACK_MOVE_2, read__tr_BACK_MOVE_2_state);
                if(_trid_6 == null) {
                    _trid_6 = state._tr_BACK_MOVE_2();
                    _OpCache_tr_BACK_MOVE_2 = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_BACK_MOVE_2, read__tr_BACK_MOVE_2_state, _trid_6);
                }
                for(BLOCKS param : _trid_6) {
                    BLOCKS _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    _ProjectionRead_BACK_MOVE_2 readState = state._projected_state_for_BACK_MOVE_2();
                    PersistentHashMap _OpCache_with_parameter_BACK_MOVE_2 = (PersistentHashMap) GET.invoke(_OpCache_BACK_MOVE_2, param);
                    if(_OpCache_with_parameter_BACK_MOVE_2 != null) {
                        _ProjectionWrite_BACK_MOVE_2 writeState = (_ProjectionWrite_BACK_MOVE_2) GET.invoke(_OpCache_with_parameter_BACK_MOVE_2, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_BACK_MOVE_2(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.BACK_MOVE_2(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_BACK_MOVE_2();
                            _OpCache_with_parameter_BACK_MOVE_2 = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_BACK_MOVE_2, readState, writeState);
                            _OpCache_BACK_MOVE_2 = (PersistentHashMap) ASSOC.invoke(_OpCache_BACK_MOVE_2, param, _OpCache_with_parameter_BACK_MOVE_2);
                        }

                    } else {
                        copiedState.BACK_MOVE_2(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_BACK_MOVE_2 writeState = copiedState._update_for_BACK_MOVE_2();
                        _OpCache_with_parameter_BACK_MOVE_2 = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_BACK_MOVE_2 = (PersistentHashMap) ASSOC.invoke(_OpCache_BACK_MOVE_2, param, _OpCache_with_parameter_BACK_MOVE_2);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_point_positionning read__tr_point_positionning_state = state._projected_state_for__tr_point_positionning();
                BSet<ROUTES> _trid_7 = (BSet<ROUTES>) GET.invoke(_OpCache_tr_point_positionning, read__tr_point_positionning_state);
                if(_trid_7 == null) {
                    _trid_7 = state._tr_point_positionning();
                    _OpCache_tr_point_positionning = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_point_positionning, read__tr_point_positionning_state, _trid_7);
                }
                for(ROUTES param : _trid_7) {
                    ROUTES _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    _ProjectionRead_point_positionning readState = state._projected_state_for_point_positionning();
                    PersistentHashMap _OpCache_with_parameter_point_positionning = (PersistentHashMap) GET.invoke(_OpCache_point_positionning, param);
                    if(_OpCache_with_parameter_point_positionning != null) {
                        _ProjectionWrite_point_positionning writeState = (_ProjectionWrite_point_positionning) GET.invoke(_OpCache_with_parameter_point_positionning, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_point_positionning(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.point_positionning(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_point_positionning();
                            _OpCache_with_parameter_point_positionning = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_point_positionning, readState, writeState);
                            _OpCache_point_positionning = (PersistentHashMap) ASSOC.invoke(_OpCache_point_positionning, param, _OpCache_with_parameter_point_positionning);
                        }

                    } else {
                        copiedState.point_positionning(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_point_positionning writeState = copiedState._update_for_point_positionning();
                        _OpCache_with_parameter_point_positionning = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_point_positionning = (PersistentHashMap) ASSOC.invoke(_OpCache_point_positionning, param, _OpCache_with_parameter_point_positionning);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_route_formation read__tr_route_formation_state = state._projected_state_for__tr_route_formation();
                BSet<ROUTES> _trid_8 = (BSet<ROUTES>) GET.invoke(_OpCache_tr_route_formation, read__tr_route_formation_state);
                if(_trid_8 == null) {
                    _trid_8 = state._tr_route_formation();
                    _OpCache_tr_route_formation = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_route_formation, read__tr_route_formation_state, _trid_8);
                }
                for(ROUTES param : _trid_8) {
                    ROUTES _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    _ProjectionRead_route_formation readState = state._projected_state_for_route_formation();
                    PersistentHashMap _OpCache_with_parameter_route_formation = (PersistentHashMap) GET.invoke(_OpCache_route_formation, param);
                    if(_OpCache_with_parameter_route_formation != null) {
                        _ProjectionWrite_route_formation writeState = (_ProjectionWrite_route_formation) GET.invoke(_OpCache_with_parameter_route_formation, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_route_formation(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.route_formation(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_route_formation();
                            _OpCache_with_parameter_route_formation = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_route_formation, readState, writeState);
                            _OpCache_route_formation = (PersistentHashMap) ASSOC.invoke(_OpCache_route_formation, param, _OpCache_with_parameter_route_formation);
                        }

                    } else {
                        copiedState.route_formation(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_route_formation writeState = copiedState._update_for_route_formation();
                        _OpCache_with_parameter_route_formation = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_route_formation = (PersistentHashMap) ASSOC.invoke(_OpCache_route_formation, param, _OpCache_with_parameter_route_formation);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            } else {
                BSet<ROUTES> _trid_1 = state._tr_route_reservation();
                for(ROUTES param : _trid_1) {
                    ROUTES _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    copiedState.route_reservation(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<ROUTES> _trid_2 = state._tr_route_freeing();
                for(ROUTES param : _trid_2) {
                    ROUTES _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    copiedState.route_freeing(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<ROUTES> _trid_3 = state._tr_FRONT_MOVE_1();
                for(ROUTES param : _trid_3) {
                    ROUTES _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    copiedState.FRONT_MOVE_1(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BLOCKS> _trid_4 = state._tr_FRONT_MOVE_2();
                for(BLOCKS param : _trid_4) {
                    BLOCKS _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    copiedState.FRONT_MOVE_2(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BLOCKS> _trid_5 = state._tr_BACK_MOVE_1();
                for(BLOCKS param : _trid_5) {
                    BLOCKS _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    copiedState.BACK_MOVE_1(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BLOCKS> _trid_6 = state._tr_BACK_MOVE_2();
                for(BLOCKS param : _trid_6) {
                    BLOCKS _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    copiedState.BACK_MOVE_2(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<ROUTES> _trid_7 = state._tr_point_positionning();
                for(ROUTES param : _trid_7) {
                    ROUTES _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    copiedState.point_positionning(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<ROUTES> _trid_8 = state._tr_route_formation();
                for(ROUTES param : _trid_8) {
                    ROUTES _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    copiedState.route_formation(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            }
            return result;
        }

        private boolean invariantViolated(final Train_1_beebook_deterministic_MC_POR_v3 state) {
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
