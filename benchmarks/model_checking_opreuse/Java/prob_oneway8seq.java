import de.hhu.stups.btypes.BRelation;
import de.hhu.stups.btypes.BTuple;
import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BObject;
import de.hhu.stups.btypes.BInteger;
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


public class prob_oneway8seq {


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

    public prob_oneway8seq parent;
    public String stateAccessedVia;

    public static class _ProjectionRead_move0 {

        public BInteger P0;
        public BInteger P1;
        public BInteger P2;
        public BInteger P3;
        public BInteger P4;
        public BInteger P5;
        public BInteger P6;
        public BInteger P7;
        public BInteger RA;
        public BInteger RB;

        public _ProjectionRead_move0(BInteger P0, BInteger P1, BInteger P2, BInteger P3, BInteger P4, BInteger P5, BInteger P6, BInteger P7, BInteger RA, BInteger RB) {
            this.P0 = P0;
            this.P1 = P1;
            this.P2 = P2;
            this.P3 = P3;
            this.P4 = P4;
            this.P5 = P5;
            this.P6 = P6;
            this.P7 = P7;
            this.RA = RA;
            this.RB = RB;
        }

        public String toString() {
            return "{" + "P0: " + this.P0 + "," + "P1: " + this.P1 + "," + "P2: " + this.P2 + "," + "P3: " + this.P3 + "," + "P4: " + this.P4 + "," + "P5: " + this.P5 + "," + "P6: " + this.P6 + "," + "P7: " + this.P7 + "," + "RA: " + this.RA + "," + "RB: " + this.RB + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_move0)) {
                return false;
            }
            _ProjectionRead_move0 o = (_ProjectionRead_move0) other;
            return this.P0.equals(o.P0) && this.P1.equals(o.P1) && this.P2.equals(o.P2) && this.P3.equals(o.P3) && this.P4.equals(o.P4) && this.P5.equals(o.P5) && this.P6.equals(o.P6) && this.P7.equals(o.P7) && this.RA.equals(o.RA) && this.RB.equals(o.RB);
        }

        public int hashCode() {
            return Objects.hash(P0, P1, P2, P3, P4, P5, P6, P7, RA, RB);
        }
    }

    public static class _ProjectionRead__tr_move0 {

        public BInteger P0;
        public BInteger P1;
        public BInteger P2;
        public BInteger P3;
        public BInteger P4;
        public BInteger P5;
        public BInteger P6;
        public BInteger P7;
        public BInteger RA;
        public BInteger RB;

        public _ProjectionRead__tr_move0(BInteger P0, BInteger P1, BInteger P2, BInteger P3, BInteger P4, BInteger P5, BInteger P6, BInteger P7, BInteger RA, BInteger RB) {
            this.P0 = P0;
            this.P1 = P1;
            this.P2 = P2;
            this.P3 = P3;
            this.P4 = P4;
            this.P5 = P5;
            this.P6 = P6;
            this.P7 = P7;
            this.RA = RA;
            this.RB = RB;
        }

        public String toString() {
            return "{" + "P0: " + this.P0 + "," + "P1: " + this.P1 + "," + "P2: " + this.P2 + "," + "P3: " + this.P3 + "," + "P4: " + this.P4 + "," + "P5: " + this.P5 + "," + "P6: " + this.P6 + "," + "P7: " + this.P7 + "," + "RA: " + this.RA + "," + "RB: " + this.RB + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_move0)) {
                return false;
            }
            _ProjectionRead__tr_move0 o = (_ProjectionRead__tr_move0) other;
            return this.P0.equals(o.P0) && this.P1.equals(o.P1) && this.P2.equals(o.P2) && this.P3.equals(o.P3) && this.P4.equals(o.P4) && this.P5.equals(o.P5) && this.P6.equals(o.P6) && this.P7.equals(o.P7) && this.RA.equals(o.RA) && this.RB.equals(o.RB);
        }

        public int hashCode() {
            return Objects.hash(P0, P1, P2, P3, P4, P5, P6, P7, RA, RB);
        }
    }

    public static class _ProjectionWrite_move0 {

        public BInteger P0;
        public BInteger RB;
        public BInteger RA;

        public _ProjectionWrite_move0(BInteger P0, BInteger RB, BInteger RA) {
            this.P0 = P0;
            this.RB = RB;
            this.RA = RA;
        }

        public String toString() {
            return "{" + "P0: " + this.P0 + "," + "RB: " + this.RB + "," + "RA: " + this.RA + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_move0)) {
                return false;
            }
            _ProjectionWrite_move0 o = (_ProjectionWrite_move0) other;
            return this.P0.equals(o.P0) && this.RB.equals(o.RB) && this.RA.equals(o.RA);
        }

        public int hashCode() {
            return Objects.hash(P0, RB, RA);
        }
    }

    public static class _ProjectionRead_move1 {

        public BInteger P0;
        public BInteger P1;
        public BInteger P2;
        public BInteger P3;
        public BInteger P4;
        public BInteger P5;
        public BInteger P6;
        public BInteger P7;
        public BInteger RA;
        public BInteger RB;

        public _ProjectionRead_move1(BInteger P0, BInteger P1, BInteger P2, BInteger P3, BInteger P4, BInteger P5, BInteger P6, BInteger P7, BInteger RA, BInteger RB) {
            this.P0 = P0;
            this.P1 = P1;
            this.P2 = P2;
            this.P3 = P3;
            this.P4 = P4;
            this.P5 = P5;
            this.P6 = P6;
            this.P7 = P7;
            this.RA = RA;
            this.RB = RB;
        }

        public String toString() {
            return "{" + "P0: " + this.P0 + "," + "P1: " + this.P1 + "," + "P2: " + this.P2 + "," + "P3: " + this.P3 + "," + "P4: " + this.P4 + "," + "P5: " + this.P5 + "," + "P6: " + this.P6 + "," + "P7: " + this.P7 + "," + "RA: " + this.RA + "," + "RB: " + this.RB + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_move1)) {
                return false;
            }
            _ProjectionRead_move1 o = (_ProjectionRead_move1) other;
            return this.P0.equals(o.P0) && this.P1.equals(o.P1) && this.P2.equals(o.P2) && this.P3.equals(o.P3) && this.P4.equals(o.P4) && this.P5.equals(o.P5) && this.P6.equals(o.P6) && this.P7.equals(o.P7) && this.RA.equals(o.RA) && this.RB.equals(o.RB);
        }

        public int hashCode() {
            return Objects.hash(P0, P1, P2, P3, P4, P5, P6, P7, RA, RB);
        }
    }

    public static class _ProjectionRead__tr_move1 {

        public BInteger P0;
        public BInteger P1;
        public BInteger P2;
        public BInteger P3;
        public BInteger P4;
        public BInteger P5;
        public BInteger P6;
        public BInteger P7;
        public BInteger RA;
        public BInteger RB;

        public _ProjectionRead__tr_move1(BInteger P0, BInteger P1, BInteger P2, BInteger P3, BInteger P4, BInteger P5, BInteger P6, BInteger P7, BInteger RA, BInteger RB) {
            this.P0 = P0;
            this.P1 = P1;
            this.P2 = P2;
            this.P3 = P3;
            this.P4 = P4;
            this.P5 = P5;
            this.P6 = P6;
            this.P7 = P7;
            this.RA = RA;
            this.RB = RB;
        }

        public String toString() {
            return "{" + "P0: " + this.P0 + "," + "P1: " + this.P1 + "," + "P2: " + this.P2 + "," + "P3: " + this.P3 + "," + "P4: " + this.P4 + "," + "P5: " + this.P5 + "," + "P6: " + this.P6 + "," + "P7: " + this.P7 + "," + "RA: " + this.RA + "," + "RB: " + this.RB + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_move1)) {
                return false;
            }
            _ProjectionRead__tr_move1 o = (_ProjectionRead__tr_move1) other;
            return this.P0.equals(o.P0) && this.P1.equals(o.P1) && this.P2.equals(o.P2) && this.P3.equals(o.P3) && this.P4.equals(o.P4) && this.P5.equals(o.P5) && this.P6.equals(o.P6) && this.P7.equals(o.P7) && this.RA.equals(o.RA) && this.RB.equals(o.RB);
        }

        public int hashCode() {
            return Objects.hash(P0, P1, P2, P3, P4, P5, P6, P7, RA, RB);
        }
    }

    public static class _ProjectionWrite_move1 {

        public BInteger RB;
        public BInteger P1;
        public BInteger RA;

        public _ProjectionWrite_move1(BInteger RB, BInteger P1, BInteger RA) {
            this.RB = RB;
            this.P1 = P1;
            this.RA = RA;
        }

        public String toString() {
            return "{" + "RB: " + this.RB + "," + "P1: " + this.P1 + "," + "RA: " + this.RA + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_move1)) {
                return false;
            }
            _ProjectionWrite_move1 o = (_ProjectionWrite_move1) other;
            return this.RB.equals(o.RB) && this.P1.equals(o.P1) && this.RA.equals(o.RA);
        }

        public int hashCode() {
            return Objects.hash(RB, P1, RA);
        }
    }

    public static class _ProjectionRead_move2 {

        public BInteger P0;
        public BInteger P1;
        public BInteger P2;
        public BInteger P3;
        public BInteger P4;
        public BInteger P5;
        public BInteger P6;
        public BInteger P7;
        public BInteger RA;
        public BInteger RB;

        public _ProjectionRead_move2(BInteger P0, BInteger P1, BInteger P2, BInteger P3, BInteger P4, BInteger P5, BInteger P6, BInteger P7, BInteger RA, BInteger RB) {
            this.P0 = P0;
            this.P1 = P1;
            this.P2 = P2;
            this.P3 = P3;
            this.P4 = P4;
            this.P5 = P5;
            this.P6 = P6;
            this.P7 = P7;
            this.RA = RA;
            this.RB = RB;
        }

        public String toString() {
            return "{" + "P0: " + this.P0 + "," + "P1: " + this.P1 + "," + "P2: " + this.P2 + "," + "P3: " + this.P3 + "," + "P4: " + this.P4 + "," + "P5: " + this.P5 + "," + "P6: " + this.P6 + "," + "P7: " + this.P7 + "," + "RA: " + this.RA + "," + "RB: " + this.RB + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_move2)) {
                return false;
            }
            _ProjectionRead_move2 o = (_ProjectionRead_move2) other;
            return this.P0.equals(o.P0) && this.P1.equals(o.P1) && this.P2.equals(o.P2) && this.P3.equals(o.P3) && this.P4.equals(o.P4) && this.P5.equals(o.P5) && this.P6.equals(o.P6) && this.P7.equals(o.P7) && this.RA.equals(o.RA) && this.RB.equals(o.RB);
        }

        public int hashCode() {
            return Objects.hash(P0, P1, P2, P3, P4, P5, P6, P7, RA, RB);
        }
    }

    public static class _ProjectionRead__tr_move2 {

        public BInteger P0;
        public BInteger P1;
        public BInteger P2;
        public BInteger P3;
        public BInteger P4;
        public BInteger P5;
        public BInteger P6;
        public BInteger P7;
        public BInteger RA;
        public BInteger RB;

        public _ProjectionRead__tr_move2(BInteger P0, BInteger P1, BInteger P2, BInteger P3, BInteger P4, BInteger P5, BInteger P6, BInteger P7, BInteger RA, BInteger RB) {
            this.P0 = P0;
            this.P1 = P1;
            this.P2 = P2;
            this.P3 = P3;
            this.P4 = P4;
            this.P5 = P5;
            this.P6 = P6;
            this.P7 = P7;
            this.RA = RA;
            this.RB = RB;
        }

        public String toString() {
            return "{" + "P0: " + this.P0 + "," + "P1: " + this.P1 + "," + "P2: " + this.P2 + "," + "P3: " + this.P3 + "," + "P4: " + this.P4 + "," + "P5: " + this.P5 + "," + "P6: " + this.P6 + "," + "P7: " + this.P7 + "," + "RA: " + this.RA + "," + "RB: " + this.RB + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_move2)) {
                return false;
            }
            _ProjectionRead__tr_move2 o = (_ProjectionRead__tr_move2) other;
            return this.P0.equals(o.P0) && this.P1.equals(o.P1) && this.P2.equals(o.P2) && this.P3.equals(o.P3) && this.P4.equals(o.P4) && this.P5.equals(o.P5) && this.P6.equals(o.P6) && this.P7.equals(o.P7) && this.RA.equals(o.RA) && this.RB.equals(o.RB);
        }

        public int hashCode() {
            return Objects.hash(P0, P1, P2, P3, P4, P5, P6, P7, RA, RB);
        }
    }

    public static class _ProjectionWrite_move2 {

        public BInteger RB;
        public BInteger P2;
        public BInteger RA;

        public _ProjectionWrite_move2(BInteger RB, BInteger P2, BInteger RA) {
            this.RB = RB;
            this.P2 = P2;
            this.RA = RA;
        }

        public String toString() {
            return "{" + "RB: " + this.RB + "," + "P2: " + this.P2 + "," + "RA: " + this.RA + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_move2)) {
                return false;
            }
            _ProjectionWrite_move2 o = (_ProjectionWrite_move2) other;
            return this.RB.equals(o.RB) && this.P2.equals(o.P2) && this.RA.equals(o.RA);
        }

        public int hashCode() {
            return Objects.hash(RB, P2, RA);
        }
    }

    public static class _ProjectionRead_move3 {

        public BInteger P0;
        public BInteger P1;
        public BInteger P2;
        public BInteger P3;
        public BInteger P4;
        public BInteger P5;
        public BInteger P6;
        public BInteger P7;
        public BInteger RA;
        public BInteger RB;

        public _ProjectionRead_move3(BInteger P0, BInteger P1, BInteger P2, BInteger P3, BInteger P4, BInteger P5, BInteger P6, BInteger P7, BInteger RA, BInteger RB) {
            this.P0 = P0;
            this.P1 = P1;
            this.P2 = P2;
            this.P3 = P3;
            this.P4 = P4;
            this.P5 = P5;
            this.P6 = P6;
            this.P7 = P7;
            this.RA = RA;
            this.RB = RB;
        }

        public String toString() {
            return "{" + "P0: " + this.P0 + "," + "P1: " + this.P1 + "," + "P2: " + this.P2 + "," + "P3: " + this.P3 + "," + "P4: " + this.P4 + "," + "P5: " + this.P5 + "," + "P6: " + this.P6 + "," + "P7: " + this.P7 + "," + "RA: " + this.RA + "," + "RB: " + this.RB + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_move3)) {
                return false;
            }
            _ProjectionRead_move3 o = (_ProjectionRead_move3) other;
            return this.P0.equals(o.P0) && this.P1.equals(o.P1) && this.P2.equals(o.P2) && this.P3.equals(o.P3) && this.P4.equals(o.P4) && this.P5.equals(o.P5) && this.P6.equals(o.P6) && this.P7.equals(o.P7) && this.RA.equals(o.RA) && this.RB.equals(o.RB);
        }

        public int hashCode() {
            return Objects.hash(P0, P1, P2, P3, P4, P5, P6, P7, RA, RB);
        }
    }

    public static class _ProjectionRead__tr_move3 {

        public BInteger P0;
        public BInteger P1;
        public BInteger P2;
        public BInteger P3;
        public BInteger P4;
        public BInteger P5;
        public BInteger P6;
        public BInteger P7;
        public BInteger RA;
        public BInteger RB;

        public _ProjectionRead__tr_move3(BInteger P0, BInteger P1, BInteger P2, BInteger P3, BInteger P4, BInteger P5, BInteger P6, BInteger P7, BInteger RA, BInteger RB) {
            this.P0 = P0;
            this.P1 = P1;
            this.P2 = P2;
            this.P3 = P3;
            this.P4 = P4;
            this.P5 = P5;
            this.P6 = P6;
            this.P7 = P7;
            this.RA = RA;
            this.RB = RB;
        }

        public String toString() {
            return "{" + "P0: " + this.P0 + "," + "P1: " + this.P1 + "," + "P2: " + this.P2 + "," + "P3: " + this.P3 + "," + "P4: " + this.P4 + "," + "P5: " + this.P5 + "," + "P6: " + this.P6 + "," + "P7: " + this.P7 + "," + "RA: " + this.RA + "," + "RB: " + this.RB + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_move3)) {
                return false;
            }
            _ProjectionRead__tr_move3 o = (_ProjectionRead__tr_move3) other;
            return this.P0.equals(o.P0) && this.P1.equals(o.P1) && this.P2.equals(o.P2) && this.P3.equals(o.P3) && this.P4.equals(o.P4) && this.P5.equals(o.P5) && this.P6.equals(o.P6) && this.P7.equals(o.P7) && this.RA.equals(o.RA) && this.RB.equals(o.RB);
        }

        public int hashCode() {
            return Objects.hash(P0, P1, P2, P3, P4, P5, P6, P7, RA, RB);
        }
    }

    public static class _ProjectionWrite_move3 {

        public BInteger RB;
        public BInteger P3;
        public BInteger RA;

        public _ProjectionWrite_move3(BInteger RB, BInteger P3, BInteger RA) {
            this.RB = RB;
            this.P3 = P3;
            this.RA = RA;
        }

        public String toString() {
            return "{" + "RB: " + this.RB + "," + "P3: " + this.P3 + "," + "RA: " + this.RA + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_move3)) {
                return false;
            }
            _ProjectionWrite_move3 o = (_ProjectionWrite_move3) other;
            return this.RB.equals(o.RB) && this.P3.equals(o.P3) && this.RA.equals(o.RA);
        }

        public int hashCode() {
            return Objects.hash(RB, P3, RA);
        }
    }

    public static class _ProjectionRead_move4 {

        public BInteger P0;
        public BInteger P1;
        public BInteger P2;
        public BInteger P3;
        public BInteger P4;
        public BInteger P5;
        public BInteger P6;
        public BInteger P7;
        public BInteger RA;
        public BInteger RB;

        public _ProjectionRead_move4(BInteger P0, BInteger P1, BInteger P2, BInteger P3, BInteger P4, BInteger P5, BInteger P6, BInteger P7, BInteger RA, BInteger RB) {
            this.P0 = P0;
            this.P1 = P1;
            this.P2 = P2;
            this.P3 = P3;
            this.P4 = P4;
            this.P5 = P5;
            this.P6 = P6;
            this.P7 = P7;
            this.RA = RA;
            this.RB = RB;
        }

        public String toString() {
            return "{" + "P0: " + this.P0 + "," + "P1: " + this.P1 + "," + "P2: " + this.P2 + "," + "P3: " + this.P3 + "," + "P4: " + this.P4 + "," + "P5: " + this.P5 + "," + "P6: " + this.P6 + "," + "P7: " + this.P7 + "," + "RA: " + this.RA + "," + "RB: " + this.RB + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_move4)) {
                return false;
            }
            _ProjectionRead_move4 o = (_ProjectionRead_move4) other;
            return this.P0.equals(o.P0) && this.P1.equals(o.P1) && this.P2.equals(o.P2) && this.P3.equals(o.P3) && this.P4.equals(o.P4) && this.P5.equals(o.P5) && this.P6.equals(o.P6) && this.P7.equals(o.P7) && this.RA.equals(o.RA) && this.RB.equals(o.RB);
        }

        public int hashCode() {
            return Objects.hash(P0, P1, P2, P3, P4, P5, P6, P7, RA, RB);
        }
    }

    public static class _ProjectionRead__tr_move4 {

        public BInteger P0;
        public BInteger P1;
        public BInteger P2;
        public BInteger P3;
        public BInteger P4;
        public BInteger P5;
        public BInteger P6;
        public BInteger P7;
        public BInteger RA;
        public BInteger RB;

        public _ProjectionRead__tr_move4(BInteger P0, BInteger P1, BInteger P2, BInteger P3, BInteger P4, BInteger P5, BInteger P6, BInteger P7, BInteger RA, BInteger RB) {
            this.P0 = P0;
            this.P1 = P1;
            this.P2 = P2;
            this.P3 = P3;
            this.P4 = P4;
            this.P5 = P5;
            this.P6 = P6;
            this.P7 = P7;
            this.RA = RA;
            this.RB = RB;
        }

        public String toString() {
            return "{" + "P0: " + this.P0 + "," + "P1: " + this.P1 + "," + "P2: " + this.P2 + "," + "P3: " + this.P3 + "," + "P4: " + this.P4 + "," + "P5: " + this.P5 + "," + "P6: " + this.P6 + "," + "P7: " + this.P7 + "," + "RA: " + this.RA + "," + "RB: " + this.RB + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_move4)) {
                return false;
            }
            _ProjectionRead__tr_move4 o = (_ProjectionRead__tr_move4) other;
            return this.P0.equals(o.P0) && this.P1.equals(o.P1) && this.P2.equals(o.P2) && this.P3.equals(o.P3) && this.P4.equals(o.P4) && this.P5.equals(o.P5) && this.P6.equals(o.P6) && this.P7.equals(o.P7) && this.RA.equals(o.RA) && this.RB.equals(o.RB);
        }

        public int hashCode() {
            return Objects.hash(P0, P1, P2, P3, P4, P5, P6, P7, RA, RB);
        }
    }

    public static class _ProjectionWrite_move4 {

        public BInteger RB;
        public BInteger P4;
        public BInteger RA;

        public _ProjectionWrite_move4(BInteger RB, BInteger P4, BInteger RA) {
            this.RB = RB;
            this.P4 = P4;
            this.RA = RA;
        }

        public String toString() {
            return "{" + "RB: " + this.RB + "," + "P4: " + this.P4 + "," + "RA: " + this.RA + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_move4)) {
                return false;
            }
            _ProjectionWrite_move4 o = (_ProjectionWrite_move4) other;
            return this.RB.equals(o.RB) && this.P4.equals(o.P4) && this.RA.equals(o.RA);
        }

        public int hashCode() {
            return Objects.hash(RB, P4, RA);
        }
    }

    public static class _ProjectionRead_move5 {

        public BInteger P0;
        public BInteger P1;
        public BInteger P2;
        public BInteger P3;
        public BInteger P4;
        public BInteger P5;
        public BInteger P6;
        public BInteger P7;
        public BInteger RA;
        public BInteger RB;

        public _ProjectionRead_move5(BInteger P0, BInteger P1, BInteger P2, BInteger P3, BInteger P4, BInteger P5, BInteger P6, BInteger P7, BInteger RA, BInteger RB) {
            this.P0 = P0;
            this.P1 = P1;
            this.P2 = P2;
            this.P3 = P3;
            this.P4 = P4;
            this.P5 = P5;
            this.P6 = P6;
            this.P7 = P7;
            this.RA = RA;
            this.RB = RB;
        }

        public String toString() {
            return "{" + "P0: " + this.P0 + "," + "P1: " + this.P1 + "," + "P2: " + this.P2 + "," + "P3: " + this.P3 + "," + "P4: " + this.P4 + "," + "P5: " + this.P5 + "," + "P6: " + this.P6 + "," + "P7: " + this.P7 + "," + "RA: " + this.RA + "," + "RB: " + this.RB + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_move5)) {
                return false;
            }
            _ProjectionRead_move5 o = (_ProjectionRead_move5) other;
            return this.P0.equals(o.P0) && this.P1.equals(o.P1) && this.P2.equals(o.P2) && this.P3.equals(o.P3) && this.P4.equals(o.P4) && this.P5.equals(o.P5) && this.P6.equals(o.P6) && this.P7.equals(o.P7) && this.RA.equals(o.RA) && this.RB.equals(o.RB);
        }

        public int hashCode() {
            return Objects.hash(P0, P1, P2, P3, P4, P5, P6, P7, RA, RB);
        }
    }

    public static class _ProjectionRead__tr_move5 {

        public BInteger P0;
        public BInteger P1;
        public BInteger P2;
        public BInteger P3;
        public BInteger P4;
        public BInteger P5;
        public BInteger P6;
        public BInteger P7;
        public BInteger RA;
        public BInteger RB;

        public _ProjectionRead__tr_move5(BInteger P0, BInteger P1, BInteger P2, BInteger P3, BInteger P4, BInteger P5, BInteger P6, BInteger P7, BInteger RA, BInteger RB) {
            this.P0 = P0;
            this.P1 = P1;
            this.P2 = P2;
            this.P3 = P3;
            this.P4 = P4;
            this.P5 = P5;
            this.P6 = P6;
            this.P7 = P7;
            this.RA = RA;
            this.RB = RB;
        }

        public String toString() {
            return "{" + "P0: " + this.P0 + "," + "P1: " + this.P1 + "," + "P2: " + this.P2 + "," + "P3: " + this.P3 + "," + "P4: " + this.P4 + "," + "P5: " + this.P5 + "," + "P6: " + this.P6 + "," + "P7: " + this.P7 + "," + "RA: " + this.RA + "," + "RB: " + this.RB + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_move5)) {
                return false;
            }
            _ProjectionRead__tr_move5 o = (_ProjectionRead__tr_move5) other;
            return this.P0.equals(o.P0) && this.P1.equals(o.P1) && this.P2.equals(o.P2) && this.P3.equals(o.P3) && this.P4.equals(o.P4) && this.P5.equals(o.P5) && this.P6.equals(o.P6) && this.P7.equals(o.P7) && this.RA.equals(o.RA) && this.RB.equals(o.RB);
        }

        public int hashCode() {
            return Objects.hash(P0, P1, P2, P3, P4, P5, P6, P7, RA, RB);
        }
    }

    public static class _ProjectionWrite_move5 {

        public BInteger RB;
        public BInteger P5;
        public BInteger RA;

        public _ProjectionWrite_move5(BInteger RB, BInteger P5, BInteger RA) {
            this.RB = RB;
            this.P5 = P5;
            this.RA = RA;
        }

        public String toString() {
            return "{" + "RB: " + this.RB + "," + "P5: " + this.P5 + "," + "RA: " + this.RA + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_move5)) {
                return false;
            }
            _ProjectionWrite_move5 o = (_ProjectionWrite_move5) other;
            return this.RB.equals(o.RB) && this.P5.equals(o.P5) && this.RA.equals(o.RA);
        }

        public int hashCode() {
            return Objects.hash(RB, P5, RA);
        }
    }

    public static class _ProjectionRead_move6 {

        public BInteger P0;
        public BInteger P1;
        public BInteger P2;
        public BInteger P3;
        public BInteger P4;
        public BInteger P5;
        public BInteger P6;
        public BInteger P7;
        public BInteger RA;
        public BInteger RB;

        public _ProjectionRead_move6(BInteger P0, BInteger P1, BInteger P2, BInteger P3, BInteger P4, BInteger P5, BInteger P6, BInteger P7, BInteger RA, BInteger RB) {
            this.P0 = P0;
            this.P1 = P1;
            this.P2 = P2;
            this.P3 = P3;
            this.P4 = P4;
            this.P5 = P5;
            this.P6 = P6;
            this.P7 = P7;
            this.RA = RA;
            this.RB = RB;
        }

        public String toString() {
            return "{" + "P0: " + this.P0 + "," + "P1: " + this.P1 + "," + "P2: " + this.P2 + "," + "P3: " + this.P3 + "," + "P4: " + this.P4 + "," + "P5: " + this.P5 + "," + "P6: " + this.P6 + "," + "P7: " + this.P7 + "," + "RA: " + this.RA + "," + "RB: " + this.RB + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_move6)) {
                return false;
            }
            _ProjectionRead_move6 o = (_ProjectionRead_move6) other;
            return this.P0.equals(o.P0) && this.P1.equals(o.P1) && this.P2.equals(o.P2) && this.P3.equals(o.P3) && this.P4.equals(o.P4) && this.P5.equals(o.P5) && this.P6.equals(o.P6) && this.P7.equals(o.P7) && this.RA.equals(o.RA) && this.RB.equals(o.RB);
        }

        public int hashCode() {
            return Objects.hash(P0, P1, P2, P3, P4, P5, P6, P7, RA, RB);
        }
    }

    public static class _ProjectionRead__tr_move6 {

        public BInteger P0;
        public BInteger P1;
        public BInteger P2;
        public BInteger P3;
        public BInteger P4;
        public BInteger P5;
        public BInteger P6;
        public BInteger P7;
        public BInteger RA;
        public BInteger RB;

        public _ProjectionRead__tr_move6(BInteger P0, BInteger P1, BInteger P2, BInteger P3, BInteger P4, BInteger P5, BInteger P6, BInteger P7, BInteger RA, BInteger RB) {
            this.P0 = P0;
            this.P1 = P1;
            this.P2 = P2;
            this.P3 = P3;
            this.P4 = P4;
            this.P5 = P5;
            this.P6 = P6;
            this.P7 = P7;
            this.RA = RA;
            this.RB = RB;
        }

        public String toString() {
            return "{" + "P0: " + this.P0 + "," + "P1: " + this.P1 + "," + "P2: " + this.P2 + "," + "P3: " + this.P3 + "," + "P4: " + this.P4 + "," + "P5: " + this.P5 + "," + "P6: " + this.P6 + "," + "P7: " + this.P7 + "," + "RA: " + this.RA + "," + "RB: " + this.RB + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_move6)) {
                return false;
            }
            _ProjectionRead__tr_move6 o = (_ProjectionRead__tr_move6) other;
            return this.P0.equals(o.P0) && this.P1.equals(o.P1) && this.P2.equals(o.P2) && this.P3.equals(o.P3) && this.P4.equals(o.P4) && this.P5.equals(o.P5) && this.P6.equals(o.P6) && this.P7.equals(o.P7) && this.RA.equals(o.RA) && this.RB.equals(o.RB);
        }

        public int hashCode() {
            return Objects.hash(P0, P1, P2, P3, P4, P5, P6, P7, RA, RB);
        }
    }

    public static class _ProjectionWrite_move6 {

        public BInteger RB;
        public BInteger P6;
        public BInteger RA;

        public _ProjectionWrite_move6(BInteger RB, BInteger P6, BInteger RA) {
            this.RB = RB;
            this.P6 = P6;
            this.RA = RA;
        }

        public String toString() {
            return "{" + "RB: " + this.RB + "," + "P6: " + this.P6 + "," + "RA: " + this.RA + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_move6)) {
                return false;
            }
            _ProjectionWrite_move6 o = (_ProjectionWrite_move6) other;
            return this.RB.equals(o.RB) && this.P6.equals(o.P6) && this.RA.equals(o.RA);
        }

        public int hashCode() {
            return Objects.hash(RB, P6, RA);
        }
    }

    public static class _ProjectionRead_move7 {

        public BInteger P0;
        public BInteger P1;
        public BInteger P2;
        public BInteger P3;
        public BInteger P4;
        public BInteger P5;
        public BInteger P6;
        public BInteger P7;
        public BInteger RA;
        public BInteger RB;

        public _ProjectionRead_move7(BInteger P0, BInteger P1, BInteger P2, BInteger P3, BInteger P4, BInteger P5, BInteger P6, BInteger P7, BInteger RA, BInteger RB) {
            this.P0 = P0;
            this.P1 = P1;
            this.P2 = P2;
            this.P3 = P3;
            this.P4 = P4;
            this.P5 = P5;
            this.P6 = P6;
            this.P7 = P7;
            this.RA = RA;
            this.RB = RB;
        }

        public String toString() {
            return "{" + "P0: " + this.P0 + "," + "P1: " + this.P1 + "," + "P2: " + this.P2 + "," + "P3: " + this.P3 + "," + "P4: " + this.P4 + "," + "P5: " + this.P5 + "," + "P6: " + this.P6 + "," + "P7: " + this.P7 + "," + "RA: " + this.RA + "," + "RB: " + this.RB + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_move7)) {
                return false;
            }
            _ProjectionRead_move7 o = (_ProjectionRead_move7) other;
            return this.P0.equals(o.P0) && this.P1.equals(o.P1) && this.P2.equals(o.P2) && this.P3.equals(o.P3) && this.P4.equals(o.P4) && this.P5.equals(o.P5) && this.P6.equals(o.P6) && this.P7.equals(o.P7) && this.RA.equals(o.RA) && this.RB.equals(o.RB);
        }

        public int hashCode() {
            return Objects.hash(P0, P1, P2, P3, P4, P5, P6, P7, RA, RB);
        }
    }

    public static class _ProjectionRead__tr_move7 {

        public BInteger P0;
        public BInteger P1;
        public BInteger P2;
        public BInteger P3;
        public BInteger P4;
        public BInteger P5;
        public BInteger P6;
        public BInteger P7;
        public BInteger RA;
        public BInteger RB;

        public _ProjectionRead__tr_move7(BInteger P0, BInteger P1, BInteger P2, BInteger P3, BInteger P4, BInteger P5, BInteger P6, BInteger P7, BInteger RA, BInteger RB) {
            this.P0 = P0;
            this.P1 = P1;
            this.P2 = P2;
            this.P3 = P3;
            this.P4 = P4;
            this.P5 = P5;
            this.P6 = P6;
            this.P7 = P7;
            this.RA = RA;
            this.RB = RB;
        }

        public String toString() {
            return "{" + "P0: " + this.P0 + "," + "P1: " + this.P1 + "," + "P2: " + this.P2 + "," + "P3: " + this.P3 + "," + "P4: " + this.P4 + "," + "P5: " + this.P5 + "," + "P6: " + this.P6 + "," + "P7: " + this.P7 + "," + "RA: " + this.RA + "," + "RB: " + this.RB + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_move7)) {
                return false;
            }
            _ProjectionRead__tr_move7 o = (_ProjectionRead__tr_move7) other;
            return this.P0.equals(o.P0) && this.P1.equals(o.P1) && this.P2.equals(o.P2) && this.P3.equals(o.P3) && this.P4.equals(o.P4) && this.P5.equals(o.P5) && this.P6.equals(o.P6) && this.P7.equals(o.P7) && this.RA.equals(o.RA) && this.RB.equals(o.RB);
        }

        public int hashCode() {
            return Objects.hash(P0, P1, P2, P3, P4, P5, P6, P7, RA, RB);
        }
    }

    public static class _ProjectionWrite_move7 {

        public BInteger RB;
        public BInteger P7;
        public BInteger RA;

        public _ProjectionWrite_move7(BInteger RB, BInteger P7, BInteger RA) {
            this.RB = RB;
            this.P7 = P7;
            this.RA = RA;
        }

        public String toString() {
            return "{" + "RB: " + this.RB + "," + "P7: " + this.P7 + "," + "RA: " + this.RA + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_move7)) {
                return false;
            }
            _ProjectionWrite_move7 o = (_ProjectionWrite_move7) other;
            return this.RB.equals(o.RB) && this.P7.equals(o.P7) && this.RA.equals(o.RA);
        }

        public int hashCode() {
            return Objects.hash(RB, P7, RA);
        }
    }

    public static class _ProjectionRead_arrived {

        public BInteger P0;
        public BInteger P1;
        public BInteger P2;
        public BInteger P3;
        public BInteger P4;
        public BInteger P5;
        public BInteger P6;
        public BInteger P7;

        public _ProjectionRead_arrived(BInteger P0, BInteger P1, BInteger P2, BInteger P3, BInteger P4, BInteger P5, BInteger P6, BInteger P7) {
            this.P0 = P0;
            this.P1 = P1;
            this.P2 = P2;
            this.P3 = P3;
            this.P4 = P4;
            this.P5 = P5;
            this.P6 = P6;
            this.P7 = P7;
        }

        public String toString() {
            return "{" + "P0: " + this.P0 + "," + "P1: " + this.P1 + "," + "P2: " + this.P2 + "," + "P3: " + this.P3 + "," + "P4: " + this.P4 + "," + "P5: " + this.P5 + "," + "P6: " + this.P6 + "," + "P7: " + this.P7 + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_arrived)) {
                return false;
            }
            _ProjectionRead_arrived o = (_ProjectionRead_arrived) other;
            return this.P0.equals(o.P0) && this.P1.equals(o.P1) && this.P2.equals(o.P2) && this.P3.equals(o.P3) && this.P4.equals(o.P4) && this.P5.equals(o.P5) && this.P6.equals(o.P6) && this.P7.equals(o.P7);
        }

        public int hashCode() {
            return Objects.hash(P0, P1, P2, P3, P4, P5, P6, P7);
        }
    }

    public static class _ProjectionRead__tr_arrived {

        public BInteger P0;
        public BInteger P1;
        public BInteger P2;
        public BInteger P3;
        public BInteger P4;
        public BInteger P5;
        public BInteger P6;
        public BInteger P7;

        public _ProjectionRead__tr_arrived(BInteger P0, BInteger P1, BInteger P2, BInteger P3, BInteger P4, BInteger P5, BInteger P6, BInteger P7) {
            this.P0 = P0;
            this.P1 = P1;
            this.P2 = P2;
            this.P3 = P3;
            this.P4 = P4;
            this.P5 = P5;
            this.P6 = P6;
            this.P7 = P7;
        }

        public String toString() {
            return "{" + "P0: " + this.P0 + "," + "P1: " + this.P1 + "," + "P2: " + this.P2 + "," + "P3: " + this.P3 + "," + "P4: " + this.P4 + "," + "P5: " + this.P5 + "," + "P6: " + this.P6 + "," + "P7: " + this.P7 + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_arrived)) {
                return false;
            }
            _ProjectionRead__tr_arrived o = (_ProjectionRead__tr_arrived) other;
            return this.P0.equals(o.P0) && this.P1.equals(o.P1) && this.P2.equals(o.P2) && this.P3.equals(o.P3) && this.P4.equals(o.P4) && this.P5.equals(o.P5) && this.P6.equals(o.P6) && this.P7.equals(o.P7);
        }

        public int hashCode() {
            return Objects.hash(P0, P1, P2, P3, P4, P5, P6, P7);
        }
    }

    public static class _ProjectionWrite_arrived {


        public _ProjectionWrite_arrived() {
        }

        public String toString() {
            return "{}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_arrived)) {
                return false;
            }
            _ProjectionWrite_arrived o = (_ProjectionWrite_arrived) other;
            return true;
        }

        public int hashCode() {
            return Objects.hash();
        }
    }

    public static class _ProjectionRead__check_inv_1 {

        public BInteger P0;

        public _ProjectionRead__check_inv_1(BInteger P0) {
            this.P0 = P0;
        }

        public String toString() {
            return "{" + "P0: " + this.P0 + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_1)) {
                return false;
            }
            _ProjectionRead__check_inv_1 o = (_ProjectionRead__check_inv_1) other;
            return this.P0.equals(o.P0);
        }

        public int hashCode() {
            return Objects.hash(P0);
        }
    }

    public static class _ProjectionRead__check_inv_2 {

        public BInteger P1;

        public _ProjectionRead__check_inv_2(BInteger P1) {
            this.P1 = P1;
        }

        public String toString() {
            return "{" + "P1: " + this.P1 + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_2)) {
                return false;
            }
            _ProjectionRead__check_inv_2 o = (_ProjectionRead__check_inv_2) other;
            return this.P1.equals(o.P1);
        }

        public int hashCode() {
            return Objects.hash(P1);
        }
    }

    public static class _ProjectionRead__check_inv_3 {

        public BInteger P2;

        public _ProjectionRead__check_inv_3(BInteger P2) {
            this.P2 = P2;
        }

        public String toString() {
            return "{" + "P2: " + this.P2 + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_3)) {
                return false;
            }
            _ProjectionRead__check_inv_3 o = (_ProjectionRead__check_inv_3) other;
            return this.P2.equals(o.P2);
        }

        public int hashCode() {
            return Objects.hash(P2);
        }
    }

    public static class _ProjectionRead__check_inv_4 {

        public BInteger P3;

        public _ProjectionRead__check_inv_4(BInteger P3) {
            this.P3 = P3;
        }

        public String toString() {
            return "{" + "P3: " + this.P3 + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_4)) {
                return false;
            }
            _ProjectionRead__check_inv_4 o = (_ProjectionRead__check_inv_4) other;
            return this.P3.equals(o.P3);
        }

        public int hashCode() {
            return Objects.hash(P3);
        }
    }

    public static class _ProjectionRead__check_inv_5 {

        public BInteger P4;

        public _ProjectionRead__check_inv_5(BInteger P4) {
            this.P4 = P4;
        }

        public String toString() {
            return "{" + "P4: " + this.P4 + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_5)) {
                return false;
            }
            _ProjectionRead__check_inv_5 o = (_ProjectionRead__check_inv_5) other;
            return this.P4.equals(o.P4);
        }

        public int hashCode() {
            return Objects.hash(P4);
        }
    }

    public static class _ProjectionRead__check_inv_6 {

        public BInteger P5;

        public _ProjectionRead__check_inv_6(BInteger P5) {
            this.P5 = P5;
        }

        public String toString() {
            return "{" + "P5: " + this.P5 + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_6)) {
                return false;
            }
            _ProjectionRead__check_inv_6 o = (_ProjectionRead__check_inv_6) other;
            return this.P5.equals(o.P5);
        }

        public int hashCode() {
            return Objects.hash(P5);
        }
    }

    public static class _ProjectionRead__check_inv_7 {

        public BInteger P6;

        public _ProjectionRead__check_inv_7(BInteger P6) {
            this.P6 = P6;
        }

        public String toString() {
            return "{" + "P6: " + this.P6 + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_7)) {
                return false;
            }
            _ProjectionRead__check_inv_7 o = (_ProjectionRead__check_inv_7) other;
            return this.P6.equals(o.P6);
        }

        public int hashCode() {
            return Objects.hash(P6);
        }
    }

    public static class _ProjectionRead__check_inv_8 {

        public BInteger P7;

        public _ProjectionRead__check_inv_8(BInteger P7) {
            this.P7 = P7;
        }

        public String toString() {
            return "{" + "P7: " + this.P7 + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_8)) {
                return false;
            }
            _ProjectionRead__check_inv_8 o = (_ProjectionRead__check_inv_8) other;
            return this.P7.equals(o.P7);
        }

        public int hashCode() {
            return Objects.hash(P7);
        }
    }

    public static class _ProjectionRead__check_inv_9 {

        public BInteger RA;

        public _ProjectionRead__check_inv_9(BInteger RA) {
            this.RA = RA;
        }

        public String toString() {
            return "{" + "RA: " + this.RA + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_9)) {
                return false;
            }
            _ProjectionRead__check_inv_9 o = (_ProjectionRead__check_inv_9) other;
            return this.RA.equals(o.RA);
        }

        public int hashCode() {
            return Objects.hash(RA);
        }
    }

    public static class _ProjectionRead__check_inv_10 {

        public BInteger RB;

        public _ProjectionRead__check_inv_10(BInteger RB) {
            this.RB = RB;
        }

        public String toString() {
            return "{" + "RB: " + this.RB + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_10)) {
                return false;
            }
            _ProjectionRead__check_inv_10 o = (_ProjectionRead__check_inv_10) other;
            return this.RB.equals(o.RB);
        }

        public int hashCode() {
            return Objects.hash(RB);
        }
    }




    private static BRelation<BInteger, BInteger> T0;
    private static BRelation<BInteger, BInteger> T1;
    private static BRelation<BInteger, BInteger> T2;
    private static BRelation<BInteger, BInteger> T3;
    private static BRelation<BInteger, BInteger> T4;
    private static BRelation<BInteger, BInteger> T5;
    private static BRelation<BInteger, BInteger> T6;
    private static BRelation<BInteger, BInteger> T7;
    private static BRelation<BInteger, BInteger> A0;
    private static BRelation<BInteger, BInteger> A1;
    private static BRelation<BInteger, BInteger> A2;
    private static BRelation<BInteger, BInteger> A3;
    private static BRelation<BInteger, BInteger> A4;
    private static BRelation<BInteger, BInteger> A5;
    private static BRelation<BInteger, BInteger> A6;
    private static BRelation<BInteger, BInteger> A7;
    private static BRelation<BInteger, BInteger> B0;
    private static BRelation<BInteger, BInteger> B1;
    private static BRelation<BInteger, BInteger> B2;
    private static BRelation<BInteger, BInteger> B3;
    private static BRelation<BInteger, BInteger> B4;
    private static BRelation<BInteger, BInteger> B5;
    private static BRelation<BInteger, BInteger> B6;
    private static BRelation<BInteger, BInteger> B7;
    private static BInteger LA;
    private static BInteger LB;




    private BInteger P0;
    private BInteger P1;
    private BInteger P2;
    private BInteger P3;
    private BInteger P4;
    private BInteger P5;
    private BInteger P6;
    private BInteger P7;
    private BInteger RA;
    private BInteger RB;

    static {
        T0 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(1)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(9)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(10)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(13)), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(15)), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(20)), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(23)));
        T1 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(3)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(9)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(10)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(13)), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(15)), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(20)), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(24)));
        T2 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(5)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(27)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(11)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(13)), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(16)), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(20)), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(25)));
        T3 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(7)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(27)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(11)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(13)), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(16)), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(20)), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(26)));
        T4 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(23)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(22)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(17)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(18)), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(11)), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(9)), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(2)));
        T5 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(24)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(22)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(17)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(18)), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(11)), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(9)), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(4)));
        T6 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(25)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(22)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(17)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(18)), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(12)), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(27)), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(6)));
        T7 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(26)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(22)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(17)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(18)), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(12)), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(27)), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(8)));
        A0 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(1)), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(1).negative()), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(0)));
        A1 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(1)), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(1).negative()), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(0)));
        A2 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(1)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(1).negative()), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(1)), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(0)));
        A3 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(1)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(1).negative()), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(0)));
        A4 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(1)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(1).negative()), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(0)));
        A5 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(1)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(1).negative()), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(0)));
        A6 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(1).negative()), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(0)));
        A7 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(1)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(1).negative()), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(0)));
        B0 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(1)), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(1).negative()), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(0)));
        B1 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(1)), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(1).negative()), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(0)));
        B2 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(1)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(1).negative()), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(0)));
        B3 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(1)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(1).negative()), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(1)), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(0)));
        B4 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(1)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(0).negative()), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(1).negative()), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(0)));
        B5 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(1)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(1).negative()), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(0)));
        B6 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(1)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(1).negative()), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(0)));
        B7 = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(1), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(2), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(3), new BInteger(1).negative()), new BTuple<BInteger, BInteger>(new BInteger(4), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(5), new BInteger(0)), new BTuple<BInteger, BInteger>(new BInteger(6), new BInteger(0)));
        LA = new BInteger(7);
        LB = new BInteger(7);
        if(!(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(T0.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(T0.checkRange(BSet.interval(new BInteger(1), new BInteger(27)))).and(T0.isFunction()).and(T0.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue() && T1.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(T1.checkRange(BSet.interval(new BInteger(1), new BInteger(27)))).and(T1.isFunction()).and(T1.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && T2.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(T2.checkRange(BSet.interval(new BInteger(1), new BInteger(27)))).and(T2.isFunction()).and(T2.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && T3.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(T3.checkRange(BSet.interval(new BInteger(1), new BInteger(27)))).and(T3.isFunction()).and(T3.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && T4.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(T4.checkRange(BSet.interval(new BInteger(1), new BInteger(27)))).and(T4.isFunction()).and(T4.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && T5.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(T5.checkRange(BSet.interval(new BInteger(1), new BInteger(27)))).and(T5.isFunction()).and(T5.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && T6.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(T6.checkRange(BSet.interval(new BInteger(1), new BInteger(27)))).and(T6.isFunction()).and(T6.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && T7.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(T7.checkRange(BSet.interval(new BInteger(1), new BInteger(27)))).and(T7.isFunction()).and(T7.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && A0.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(A0.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(A0.isFunction()).and(A0.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && A1.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(A1.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(A1.isFunction()).and(A1.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && A2.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(A2.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(A2.isFunction()).and(A2.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && A3.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(A3.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(A3.isFunction()).and(A3.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && A4.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(A4.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(A4.isFunction()).and(A4.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && A5.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(A5.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(A5.isFunction()).and(A5.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && A6.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(A6.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(A6.isFunction()).and(A6.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && A7.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(A7.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(A7.isFunction()).and(A7.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && B0.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(B0.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(B0.isFunction()).and(B0.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && B1.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(B1.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(B1.isFunction()).and(B1.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && B2.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(B2.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(B2.isFunction()).and(B2.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && B3.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(B3.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(B3.isFunction()).and(B3.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && B4.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(B4.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(B4.isFunction()).and(B4.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && B5.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(B5.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(B5.isFunction()).and(B5.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && B6.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(B6.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(B6.isFunction()).and(B6.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && B7.checkDomain(BSet.interval(new BInteger(0), new BInteger(6))).and(B7.checkRange(BSet.interval(new BInteger(1).negative(), new BInteger(1)))).and(B7.isFunction()).and(B7.isTotal(BSet.interval(new BInteger(0), new BInteger(6)))).booleanValue()).booleanValue() && T0.functionCall(new BInteger(0)).equal(new BInteger(1)).booleanValue()).booleanValue() && T0.functionCall(new BInteger(1)).equal(new BInteger(9)).booleanValue()).booleanValue() && T0.functionCall(new BInteger(2)).equal(new BInteger(10)).booleanValue()).booleanValue() && T0.functionCall(new BInteger(3)).equal(new BInteger(13)).booleanValue()).booleanValue() && T0.functionCall(new BInteger(4)).equal(new BInteger(15)).booleanValue()).booleanValue() && T0.functionCall(new BInteger(5)).equal(new BInteger(20)).booleanValue()).booleanValue() && T0.functionCall(new BInteger(6)).equal(new BInteger(23)).booleanValue()).booleanValue() && T1.functionCall(new BInteger(0)).equal(new BInteger(3)).booleanValue()).booleanValue() && T1.functionCall(new BInteger(1)).equal(new BInteger(9)).booleanValue()).booleanValue() && T1.functionCall(new BInteger(2)).equal(new BInteger(10)).booleanValue()).booleanValue() && T1.functionCall(new BInteger(3)).equal(new BInteger(13)).booleanValue()).booleanValue() && T1.functionCall(new BInteger(4)).equal(new BInteger(15)).booleanValue()).booleanValue() && T1.functionCall(new BInteger(5)).equal(new BInteger(20)).booleanValue()).booleanValue() && T1.functionCall(new BInteger(6)).equal(new BInteger(24)).booleanValue()).booleanValue() && T2.functionCall(new BInteger(0)).equal(new BInteger(5)).booleanValue()).booleanValue() && T2.functionCall(new BInteger(1)).equal(new BInteger(27)).booleanValue()).booleanValue() && T2.functionCall(new BInteger(2)).equal(new BInteger(11)).booleanValue()).booleanValue() && T2.functionCall(new BInteger(3)).equal(new BInteger(13)).booleanValue()).booleanValue() && T2.functionCall(new BInteger(4)).equal(new BInteger(16)).booleanValue()).booleanValue() && T2.functionCall(new BInteger(5)).equal(new BInteger(20)).booleanValue()).booleanValue() && T2.functionCall(new BInteger(6)).equal(new BInteger(25)).booleanValue()).booleanValue() && T3.functionCall(new BInteger(0)).equal(new BInteger(7)).booleanValue()).booleanValue() && T3.functionCall(new BInteger(1)).equal(new BInteger(27)).booleanValue()).booleanValue() && T3.functionCall(new BInteger(2)).equal(new BInteger(11)).booleanValue()).booleanValue() && T3.functionCall(new BInteger(3)).equal(new BInteger(13)).booleanValue()).booleanValue() && T3.functionCall(new BInteger(4)).equal(new BInteger(16)).booleanValue()).booleanValue() && T3.functionCall(new BInteger(5)).equal(new BInteger(20)).booleanValue()).booleanValue() && T3.functionCall(new BInteger(6)).equal(new BInteger(26)).booleanValue()).booleanValue() && T4.functionCall(new BInteger(0)).equal(new BInteger(23)).booleanValue()).booleanValue() && T4.functionCall(new BInteger(1)).equal(new BInteger(22)).booleanValue()).booleanValue() && T4.functionCall(new BInteger(2)).equal(new BInteger(17)).booleanValue()).booleanValue() && T4.functionCall(new BInteger(3)).equal(new BInteger(18)).booleanValue()).booleanValue() && T4.functionCall(new BInteger(4)).equal(new BInteger(11)).booleanValue()).booleanValue() && T4.functionCall(new BInteger(5)).equal(new BInteger(9)).booleanValue()).booleanValue() && T4.functionCall(new BInteger(6)).equal(new BInteger(2)).booleanValue()).booleanValue() && T5.functionCall(new BInteger(0)).equal(new BInteger(24)).booleanValue()).booleanValue() && T5.functionCall(new BInteger(1)).equal(new BInteger(22)).booleanValue()).booleanValue() && T5.functionCall(new BInteger(2)).equal(new BInteger(17)).booleanValue()).booleanValue() && T5.functionCall(new BInteger(3)).equal(new BInteger(18)).booleanValue()).booleanValue() && T5.functionCall(new BInteger(4)).equal(new BInteger(11)).booleanValue()).booleanValue() && T5.functionCall(new BInteger(5)).equal(new BInteger(9)).booleanValue()).booleanValue() && T5.functionCall(new BInteger(6)).equal(new BInteger(4)).booleanValue()).booleanValue() && T6.functionCall(new BInteger(0)).equal(new BInteger(25)).booleanValue()).booleanValue() && T6.functionCall(new BInteger(1)).equal(new BInteger(22)).booleanValue()).booleanValue() && T6.functionCall(new BInteger(2)).equal(new BInteger(17)).booleanValue()).booleanValue() && T6.functionCall(new BInteger(3)).equal(new BInteger(18)).booleanValue()).booleanValue() && T6.functionCall(new BInteger(4)).equal(new BInteger(12)).booleanValue()).booleanValue() && T6.functionCall(new BInteger(5)).equal(new BInteger(27)).booleanValue()).booleanValue() && T6.functionCall(new BInteger(6)).equal(new BInteger(6)).booleanValue()).booleanValue() && T7.functionCall(new BInteger(0)).equal(new BInteger(26)).booleanValue()).booleanValue() && T7.functionCall(new BInteger(1)).equal(new BInteger(22)).booleanValue()).booleanValue() && T7.functionCall(new BInteger(2)).equal(new BInteger(17)).booleanValue()).booleanValue() && T7.functionCall(new BInteger(3)).equal(new BInteger(18)).booleanValue()).booleanValue() && T7.functionCall(new BInteger(4)).equal(new BInteger(12)).booleanValue()).booleanValue() && T7.functionCall(new BInteger(5)).equal(new BInteger(27)).booleanValue()).booleanValue() && T7.functionCall(new BInteger(6)).equal(new BInteger(8)).booleanValue()).booleanValue() && A0.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && A0.functionCall(new BInteger(1)).equal(new BInteger(0)).booleanValue()).booleanValue() && A0.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && A0.functionCall(new BInteger(3)).equal(new BInteger(1)).booleanValue()).booleanValue() && A0.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && A0.functionCall(new BInteger(5)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && A0.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && A1.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && A1.functionCall(new BInteger(1)).equal(new BInteger(0)).booleanValue()).booleanValue() && A1.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && A1.functionCall(new BInteger(3)).equal(new BInteger(1)).booleanValue()).booleanValue() && A1.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && A1.functionCall(new BInteger(5)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && A1.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && A2.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && A2.functionCall(new BInteger(1)).equal(new BInteger(0)).booleanValue()).booleanValue() && A2.functionCall(new BInteger(2)).equal(new BInteger(1)).booleanValue()).booleanValue() && A2.functionCall(new BInteger(3)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && A2.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && A2.functionCall(new BInteger(5)).equal(new BInteger(1)).booleanValue()).booleanValue() && A2.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && A3.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && A3.functionCall(new BInteger(1)).equal(new BInteger(0)).booleanValue()).booleanValue() && A3.functionCall(new BInteger(2)).equal(new BInteger(1)).booleanValue()).booleanValue() && A3.functionCall(new BInteger(3)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && A3.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && A3.functionCall(new BInteger(5)).equal(new BInteger(0)).booleanValue()).booleanValue() && A3.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && A4.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && A4.functionCall(new BInteger(1)).equal(new BInteger(1)).booleanValue()).booleanValue() && A4.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && A4.functionCall(new BInteger(3)).equal(new BInteger(0)).booleanValue()).booleanValue() && A4.functionCall(new BInteger(4)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && A4.functionCall(new BInteger(5)).equal(new BInteger(0)).booleanValue()).booleanValue() && A4.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && A5.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && A5.functionCall(new BInteger(1)).equal(new BInteger(1)).booleanValue()).booleanValue() && A5.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && A5.functionCall(new BInteger(3)).equal(new BInteger(0)).booleanValue()).booleanValue() && A5.functionCall(new BInteger(4)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && A5.functionCall(new BInteger(5)).equal(new BInteger(0)).booleanValue()).booleanValue() && A5.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && A6.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && A6.functionCall(new BInteger(1)).equal(new BInteger(0)).booleanValue()).booleanValue() && A6.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && A6.functionCall(new BInteger(3)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && A6.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && A6.functionCall(new BInteger(5)).equal(new BInteger(0)).booleanValue()).booleanValue() && A6.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && A7.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && A7.functionCall(new BInteger(1)).equal(new BInteger(1)).booleanValue()).booleanValue() && A7.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && A7.functionCall(new BInteger(3)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && A7.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && A7.functionCall(new BInteger(5)).equal(new BInteger(0)).booleanValue()).booleanValue() && A7.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && B0.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && B0.functionCall(new BInteger(1)).equal(new BInteger(0)).booleanValue()).booleanValue() && B0.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && B0.functionCall(new BInteger(3)).equal(new BInteger(1)).booleanValue()).booleanValue() && B0.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && B0.functionCall(new BInteger(5)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && B0.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && B1.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && B1.functionCall(new BInteger(1)).equal(new BInteger(0)).booleanValue()).booleanValue() && B1.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && B1.functionCall(new BInteger(3)).equal(new BInteger(1)).booleanValue()).booleanValue() && B1.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && B1.functionCall(new BInteger(5)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && B1.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && B2.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && B2.functionCall(new BInteger(1)).equal(new BInteger(0)).booleanValue()).booleanValue() && B2.functionCall(new BInteger(2)).equal(new BInteger(1)).booleanValue()).booleanValue() && B2.functionCall(new BInteger(3)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && B2.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && B2.functionCall(new BInteger(5)).equal(new BInteger(0)).booleanValue()).booleanValue() && B2.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && B3.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && B3.functionCall(new BInteger(1)).equal(new BInteger(0)).booleanValue()).booleanValue() && B3.functionCall(new BInteger(2)).equal(new BInteger(1)).booleanValue()).booleanValue() && B3.functionCall(new BInteger(3)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && B3.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && B3.functionCall(new BInteger(5)).equal(new BInteger(1)).booleanValue()).booleanValue() && B3.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && B4.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && B4.functionCall(new BInteger(1)).equal(new BInteger(1)).booleanValue()).booleanValue() && B4.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && B4.functionCall(new BInteger(3)).equal(new BInteger(0).negative()).booleanValue()).booleanValue() && B4.functionCall(new BInteger(4)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && B4.functionCall(new BInteger(5)).equal(new BInteger(0)).booleanValue()).booleanValue() && B4.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && B5.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && B5.functionCall(new BInteger(1)).equal(new BInteger(1)).booleanValue()).booleanValue() && B5.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && B5.functionCall(new BInteger(3)).equal(new BInteger(0)).booleanValue()).booleanValue() && B5.functionCall(new BInteger(4)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && B5.functionCall(new BInteger(5)).equal(new BInteger(0)).booleanValue()).booleanValue() && B5.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && B6.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && B6.functionCall(new BInteger(1)).equal(new BInteger(1)).booleanValue()).booleanValue() && B6.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && B6.functionCall(new BInteger(3)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && B6.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && B6.functionCall(new BInteger(5)).equal(new BInteger(0)).booleanValue()).booleanValue() && B6.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue()).booleanValue() && B7.functionCall(new BInteger(0)).equal(new BInteger(0)).booleanValue()).booleanValue() && B7.functionCall(new BInteger(1)).equal(new BInteger(0)).booleanValue()).booleanValue() && B7.functionCall(new BInteger(2)).equal(new BInteger(0)).booleanValue()).booleanValue() && B7.functionCall(new BInteger(3)).equal(new BInteger(1).negative()).booleanValue()).booleanValue() && B7.functionCall(new BInteger(4)).equal(new BInteger(0)).booleanValue()).booleanValue() && B7.functionCall(new BInteger(5)).equal(new BInteger(0)).booleanValue()).booleanValue() && B7.functionCall(new BInteger(6)).equal(new BInteger(0)).booleanValue())).booleanValue()) {
            throw new RuntimeException("Contradiction in PROPERTIES detected!");
        }
    }

    public prob_oneway8seq() {
        P0 = new BInteger(0);
        P1 = new BInteger(0);
        P2 = new BInteger(0);
        P3 = new BInteger(0);
        P4 = new BInteger(0);
        P5 = new BInteger(0);
        P6 = new BInteger(0);
        P7 = new BInteger(0);
        RA = new BInteger(1);
        RB = new BInteger(1);
    }

    public prob_oneway8seq(prob_oneway8seq copy) {
        this.T0 = copy.T0;
        this.T1 = copy.T1;
        this.T2 = copy.T2;
        this.T3 = copy.T3;
        this.T4 = copy.T4;
        this.T5 = copy.T5;
        this.T6 = copy.T6;
        this.T7 = copy.T7;
        this.A0 = copy.A0;
        this.A1 = copy.A1;
        this.A2 = copy.A2;
        this.A3 = copy.A3;
        this.A4 = copy.A4;
        this.A5 = copy.A5;
        this.A6 = copy.A6;
        this.A7 = copy.A7;
        this.B0 = copy.B0;
        this.B1 = copy.B1;
        this.B2 = copy.B2;
        this.B3 = copy.B3;
        this.B4 = copy.B4;
        this.B5 = copy.B5;
        this.B6 = copy.B6;
        this.B7 = copy.B7;
        this.LA = copy.LA;
        this.LB = copy.LB;
        this.P0 = copy.P0;
        this.P1 = copy.P1;
        this.P2 = copy.P2;
        this.P3 = copy.P3;
        this.P4 = copy.P4;
        this.P5 = copy.P5;
        this.P6 = copy.P6;
        this.P7 = copy.P7;
        this.RA = copy.RA;
        this.RB = copy.RB;
    }

    public void move0() {
        P0 = P0.plus(new BInteger(1));
        RA = RA.plus(A0.functionCall(P0));
        RB = RB.plus(B0.functionCall(P0));

    }

    public void move1() {
        P1 = P1.plus(new BInteger(1));
        RA = RA.plus(A1.functionCall(P1));
        RB = RB.plus(B1.functionCall(P1));

    }

    public void move2() {
        P2 = P2.plus(new BInteger(1));
        RA = RA.plus(A2.functionCall(P2));
        RB = RB.plus(B2.functionCall(P2));

    }

    public void move3() {
        P3 = P3.plus(new BInteger(1));
        RA = RA.plus(A3.functionCall(P3));
        RB = RB.plus(B3.functionCall(P3));

    }

    public void move4() {
        P4 = P4.plus(new BInteger(1));
        RA = RA.plus(A4.functionCall(P4));
        RB = RB.plus(B4.functionCall(P4));

    }

    public void move5() {
        P5 = P5.plus(new BInteger(1));
        RA = RA.plus(A5.functionCall(P5));
        RB = RB.plus(B5.functionCall(P5));

    }

    public void move6() {
        P6 = P6.plus(new BInteger(1));
        RA = RA.plus(A6.functionCall(P6));
        RB = RB.plus(B6.functionCall(P6));

    }

    public void move7() {
        P7 = P7.plus(new BInteger(1));
        RA = RA.plus(A7.functionCall(P7));
        RB = RB.plus(B7.functionCall(P7));

    }

    public void arrived() {
    }

    public BRelation<BInteger, BInteger> _get_T0() {
        return T0;
    }

    public BRelation<BInteger, BInteger> _get_T1() {
        return T1;
    }

    public BRelation<BInteger, BInteger> _get_T2() {
        return T2;
    }

    public BRelation<BInteger, BInteger> _get_T3() {
        return T3;
    }

    public BRelation<BInteger, BInteger> _get_T4() {
        return T4;
    }

    public BRelation<BInteger, BInteger> _get_T5() {
        return T5;
    }

    public BRelation<BInteger, BInteger> _get_T6() {
        return T6;
    }

    public BRelation<BInteger, BInteger> _get_T7() {
        return T7;
    }

    public BRelation<BInteger, BInteger> _get_A0() {
        return A0;
    }

    public BRelation<BInteger, BInteger> _get_A1() {
        return A1;
    }

    public BRelation<BInteger, BInteger> _get_A2() {
        return A2;
    }

    public BRelation<BInteger, BInteger> _get_A3() {
        return A3;
    }

    public BRelation<BInteger, BInteger> _get_A4() {
        return A4;
    }

    public BRelation<BInteger, BInteger> _get_A5() {
        return A5;
    }

    public BRelation<BInteger, BInteger> _get_A6() {
        return A6;
    }

    public BRelation<BInteger, BInteger> _get_A7() {
        return A7;
    }

    public BRelation<BInteger, BInteger> _get_B0() {
        return B0;
    }

    public BRelation<BInteger, BInteger> _get_B1() {
        return B1;
    }

    public BRelation<BInteger, BInteger> _get_B2() {
        return B2;
    }

    public BRelation<BInteger, BInteger> _get_B3() {
        return B3;
    }

    public BRelation<BInteger, BInteger> _get_B4() {
        return B4;
    }

    public BRelation<BInteger, BInteger> _get_B5() {
        return B5;
    }

    public BRelation<BInteger, BInteger> _get_B6() {
        return B6;
    }

    public BRelation<BInteger, BInteger> _get_B7() {
        return B7;
    }

    public BInteger _get_LA() {
        return LA;
    }

    public BInteger _get_LB() {
        return LB;
    }

    public BInteger _get_P0() {
        return P0;
    }

    public BInteger _get_P1() {
        return P1;
    }

    public BInteger _get_P2() {
        return P2;
    }

    public BInteger _get_P3() {
        return P3;
    }

    public BInteger _get_P4() {
        return P4;
    }

    public BInteger _get_P5() {
        return P5;
    }

    public BInteger _get_P6() {
        return P6;
    }

    public BInteger _get_P7() {
        return P7;
    }

    public BInteger _get_RA() {
        return RA;
    }

    public BInteger _get_RB() {
        return RB;
    }

    @Override
    public boolean equals(Object o) {
        prob_oneway8seq o1 = this;
        prob_oneway8seq o2 = (prob_oneway8seq) o;
        return o1._get_P0().equals(o2._get_P0()) && o1._get_P1().equals(o2._get_P1()) && o1._get_P2().equals(o2._get_P2()) && o1._get_P3().equals(o2._get_P3()) && o1._get_P4().equals(o2._get_P4()) && o1._get_P5().equals(o2._get_P5()) && o1._get_P6().equals(o2._get_P6()) && o1._get_P7().equals(o2._get_P7()) && o1._get_RA().equals(o2._get_RA()) && o1._get_RB().equals(o2._get_RB());
    }



    @Override
    public int hashCode() {
        return this._hashCode_1();
    }

    public int _hashCode_1() {
        int result = 1;
        result = (1543 * result) ^ ((this._get_P0()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_P1()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_P2()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_P3()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_P4()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_P5()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_P6()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_P7()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_RA()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_RB()).hashCode() << 1);
        return result;
    }

    public int _hashCode_2() {
        int result = 1;
        result = (6151 * result) ^ ((this._get_P0()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_P1()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_P2()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_P3()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_P4()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_P5()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_P6()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_P7()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_RA()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_RB()).hashCode() << 1);
        return result;
    }

    @Override
    public String toString() {
        return String.join("\n", "_get_P0: " + (this._get_P0()).toString(), "_get_P1: " + (this._get_P1()).toString(), "_get_P2: " + (this._get_P2()).toString(), "_get_P3: " + (this._get_P3()).toString(), "_get_P4: " + (this._get_P4()).toString(), "_get_P5: " + (this._get_P5()).toString(), "_get_P6: " + (this._get_P6()).toString(), "_get_P7: " + (this._get_P7()).toString(), "_get_RA: " + (this._get_RA()).toString(), "_get_RB: " + (this._get_RB()).toString());
    }

    public prob_oneway8seq _copy() {
        return new prob_oneway8seq(this);
    }


    public boolean _tr_move0() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(P0.less(new BInteger(6)).booleanValue() && T0.functionCall(P0.plus(new BInteger(1))).unequal(T1.functionCall(P1)).booleanValue()).booleanValue() && T0.functionCall(P0.plus(new BInteger(1))).unequal(T2.functionCall(P2)).booleanValue()).booleanValue() && T0.functionCall(P0.plus(new BInteger(1))).unequal(T3.functionCall(P3)).booleanValue()).booleanValue() && T0.functionCall(P0.plus(new BInteger(1))).unequal(T4.functionCall(P4)).booleanValue()).booleanValue() && T0.functionCall(P0.plus(new BInteger(1))).unequal(T5.functionCall(P5)).booleanValue()).booleanValue() && T0.functionCall(P0.plus(new BInteger(1))).unequal(T6.functionCall(P6)).booleanValue()).booleanValue() && T0.functionCall(P0.plus(new BInteger(1))).unequal(T7.functionCall(P7)).booleanValue()).booleanValue() && RA.plus(A0.functionCall(P0.plus(new BInteger(1)))).lessEqual(LA).booleanValue()).booleanValue() && RB.plus(B0.functionCall(P0.plus(new BInteger(1)))).lessEqual(LB).booleanValue()).booleanValue();
    }

    public boolean _tr_move1() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(P1.less(new BInteger(6)).booleanValue() && T1.functionCall(P1.plus(new BInteger(1))).unequal(T0.functionCall(P0)).booleanValue()).booleanValue() && T1.functionCall(P1.plus(new BInteger(1))).unequal(T2.functionCall(P2)).booleanValue()).booleanValue() && T1.functionCall(P1.plus(new BInteger(1))).unequal(T3.functionCall(P3)).booleanValue()).booleanValue() && T1.functionCall(P1.plus(new BInteger(1))).unequal(T4.functionCall(P4)).booleanValue()).booleanValue() && T1.functionCall(P1.plus(new BInteger(1))).unequal(T5.functionCall(P5)).booleanValue()).booleanValue() && T1.functionCall(P1.plus(new BInteger(1))).unequal(T6.functionCall(P6)).booleanValue()).booleanValue() && T1.functionCall(P1.plus(new BInteger(1))).unequal(T7.functionCall(P7)).booleanValue()).booleanValue() && RA.plus(A1.functionCall(P1.plus(new BInteger(1)))).lessEqual(LA).booleanValue()).booleanValue() && RB.plus(B1.functionCall(P1.plus(new BInteger(1)))).lessEqual(LB).booleanValue()).booleanValue();
    }

    public boolean _tr_move2() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(P2.less(new BInteger(6)).booleanValue() && T2.functionCall(P2.plus(new BInteger(1))).unequal(T0.functionCall(P0)).booleanValue()).booleanValue() && T2.functionCall(P2.plus(new BInteger(1))).unequal(T1.functionCall(P1)).booleanValue()).booleanValue() && T2.functionCall(P2.plus(new BInteger(1))).unequal(T3.functionCall(P3)).booleanValue()).booleanValue() && T2.functionCall(P2.plus(new BInteger(1))).unequal(T4.functionCall(P4)).booleanValue()).booleanValue() && T2.functionCall(P2.plus(new BInteger(1))).unequal(T5.functionCall(P5)).booleanValue()).booleanValue() && T2.functionCall(P2.plus(new BInteger(1))).unequal(T6.functionCall(P6)).booleanValue()).booleanValue() && T2.functionCall(P2.plus(new BInteger(1))).unequal(T7.functionCall(P7)).booleanValue()).booleanValue() && RA.plus(A2.functionCall(P2.plus(new BInteger(1)))).lessEqual(LA).booleanValue()).booleanValue() && RB.plus(B2.functionCall(P2.plus(new BInteger(1)))).lessEqual(LB).booleanValue()).booleanValue();
    }

    public boolean _tr_move3() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(P3.less(new BInteger(6)).booleanValue() && T3.functionCall(P3.plus(new BInteger(1))).unequal(T0.functionCall(P0)).booleanValue()).booleanValue() && T3.functionCall(P3.plus(new BInteger(1))).unequal(T1.functionCall(P1)).booleanValue()).booleanValue() && T3.functionCall(P3.plus(new BInteger(1))).unequal(T2.functionCall(P2)).booleanValue()).booleanValue() && T3.functionCall(P3.plus(new BInteger(1))).unequal(T4.functionCall(P4)).booleanValue()).booleanValue() && T3.functionCall(P3.plus(new BInteger(1))).unequal(T5.functionCall(P5)).booleanValue()).booleanValue() && T3.functionCall(P3.plus(new BInteger(1))).unequal(T6.functionCall(P6)).booleanValue()).booleanValue() && T3.functionCall(P3.plus(new BInteger(1))).unequal(T7.functionCall(P7)).booleanValue()).booleanValue() && RA.plus(A3.functionCall(P3.plus(new BInteger(1)))).lessEqual(LA).booleanValue()).booleanValue() && RB.plus(B3.functionCall(P3.plus(new BInteger(1)))).lessEqual(LB).booleanValue()).booleanValue();
    }

    public boolean _tr_move4() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(P4.less(new BInteger(6)).booleanValue() && T4.functionCall(P4.plus(new BInteger(1))).unequal(T0.functionCall(P0)).booleanValue()).booleanValue() && T4.functionCall(P4.plus(new BInteger(1))).unequal(T1.functionCall(P1)).booleanValue()).booleanValue() && T4.functionCall(P4.plus(new BInteger(1))).unequal(T2.functionCall(P2)).booleanValue()).booleanValue() && T4.functionCall(P4.plus(new BInteger(1))).unequal(T3.functionCall(P3)).booleanValue()).booleanValue() && T4.functionCall(P4.plus(new BInteger(1))).unequal(T5.functionCall(P5)).booleanValue()).booleanValue() && T4.functionCall(P4.plus(new BInteger(1))).unequal(T6.functionCall(P6)).booleanValue()).booleanValue() && T4.functionCall(P4.plus(new BInteger(1))).unequal(T7.functionCall(P7)).booleanValue()).booleanValue() && RA.plus(A4.functionCall(P4.plus(new BInteger(1)))).lessEqual(LA).booleanValue()).booleanValue() && RB.plus(B4.functionCall(P4.plus(new BInteger(1)))).lessEqual(LB).booleanValue()).booleanValue();
    }

    public boolean _tr_move5() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(P5.less(new BInteger(6)).booleanValue() && T5.functionCall(P5.plus(new BInteger(1))).unequal(T0.functionCall(P0)).booleanValue()).booleanValue() && T5.functionCall(P5.plus(new BInteger(1))).unequal(T1.functionCall(P1)).booleanValue()).booleanValue() && T5.functionCall(P5.plus(new BInteger(1))).unequal(T2.functionCall(P2)).booleanValue()).booleanValue() && T5.functionCall(P5.plus(new BInteger(1))).unequal(T3.functionCall(P3)).booleanValue()).booleanValue() && T5.functionCall(P5.plus(new BInteger(1))).unequal(T4.functionCall(P4)).booleanValue()).booleanValue() && T5.functionCall(P5.plus(new BInteger(1))).unequal(T6.functionCall(P6)).booleanValue()).booleanValue() && T5.functionCall(P5.plus(new BInteger(1))).unequal(T7.functionCall(P7)).booleanValue()).booleanValue() && RA.plus(A5.functionCall(P5.plus(new BInteger(1)))).lessEqual(LA).booleanValue()).booleanValue() && RB.plus(B5.functionCall(P5.plus(new BInteger(1)))).lessEqual(LB).booleanValue()).booleanValue();
    }

    public boolean _tr_move6() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(P6.less(new BInteger(6)).booleanValue() && T6.functionCall(P6.plus(new BInteger(1))).unequal(T0.functionCall(P0)).booleanValue()).booleanValue() && T6.functionCall(P6.plus(new BInteger(1))).unequal(T1.functionCall(P1)).booleanValue()).booleanValue() && T6.functionCall(P6.plus(new BInteger(1))).unequal(T2.functionCall(P2)).booleanValue()).booleanValue() && T6.functionCall(P6.plus(new BInteger(1))).unequal(T3.functionCall(P3)).booleanValue()).booleanValue() && T6.functionCall(P6.plus(new BInteger(1))).unequal(T4.functionCall(P4)).booleanValue()).booleanValue() && T6.functionCall(P6.plus(new BInteger(1))).unequal(T5.functionCall(P5)).booleanValue()).booleanValue() && T6.functionCall(P6.plus(new BInteger(1))).unequal(T7.functionCall(P7)).booleanValue()).booleanValue() && RA.plus(A6.functionCall(P6.plus(new BInteger(1)))).lessEqual(LA).booleanValue()).booleanValue() && RB.plus(B6.functionCall(P6.plus(new BInteger(1)))).lessEqual(LB).booleanValue()).booleanValue();
    }

    public boolean _tr_move7() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(P7.less(new BInteger(6)).booleanValue() && T7.functionCall(P7.plus(new BInteger(1))).unequal(T0.functionCall(P0)).booleanValue()).booleanValue() && T7.functionCall(P7.plus(new BInteger(1))).unequal(T1.functionCall(P1)).booleanValue()).booleanValue() && T7.functionCall(P7.plus(new BInteger(1))).unequal(T2.functionCall(P2)).booleanValue()).booleanValue() && T7.functionCall(P7.plus(new BInteger(1))).unequal(T3.functionCall(P3)).booleanValue()).booleanValue() && T7.functionCall(P7.plus(new BInteger(1))).unequal(T4.functionCall(P4)).booleanValue()).booleanValue() && T7.functionCall(P7.plus(new BInteger(1))).unequal(T5.functionCall(P5)).booleanValue()).booleanValue() && T7.functionCall(P7.plus(new BInteger(1))).unequal(T6.functionCall(P6)).booleanValue()).booleanValue() && RA.plus(A7.functionCall(P7.plus(new BInteger(1)))).lessEqual(LA).booleanValue()).booleanValue() && RB.plus(B7.functionCall(P7.plus(new BInteger(1)))).lessEqual(LB).booleanValue()).booleanValue();
    }

    public boolean _tr_arrived() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(P0.equal(new BInteger(6)).booleanValue() && P1.equal(new BInteger(6)).booleanValue()).booleanValue() && P2.equal(new BInteger(6)).booleanValue()).booleanValue() && P3.equal(new BInteger(6)).booleanValue()).booleanValue() && P4.equal(new BInteger(6)).booleanValue()).booleanValue() && P5.equal(new BInteger(6)).booleanValue()).booleanValue() && P6.equal(new BInteger(6)).booleanValue()).booleanValue() && P7.equal(new BInteger(6)).booleanValue()).booleanValue();
    }

    public _ProjectionRead_move5 _projected_state_for_move5() {
        return new _ProjectionRead_move5(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
    }

    public _ProjectionRead_move6 _projected_state_for_move6() {
        return new _ProjectionRead_move6(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
    }

    public _ProjectionRead_arrived _projected_state_for_arrived() {
        return new _ProjectionRead_arrived(P0,P1,P2,P3,P4,P5,P6,P7);
    }

    public _ProjectionRead_move7 _projected_state_for_move7() {
        return new _ProjectionRead_move7(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
    }

    public _ProjectionRead_move1 _projected_state_for_move1() {
        return new _ProjectionRead_move1(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
    }

    public _ProjectionRead_move2 _projected_state_for_move2() {
        return new _ProjectionRead_move2(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
    }

    public _ProjectionRead_move3 _projected_state_for_move3() {
        return new _ProjectionRead_move3(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
    }

    public _ProjectionRead_move4 _projected_state_for_move4() {
        return new _ProjectionRead_move4(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
    }

    public _ProjectionRead_move0 _projected_state_for_move0() {
        return new _ProjectionRead_move0(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
    }

    public _ProjectionRead__tr_move7 _projected_state_for__tr_move7() {
        return new _ProjectionRead__tr_move7(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
    }

    public _ProjectionRead__tr_arrived _projected_state_for__tr_arrived() {
        return new _ProjectionRead__tr_arrived(P0,P1,P2,P3,P4,P5,P6,P7);
    }

    public _ProjectionRead__tr_move3 _projected_state_for__tr_move3() {
        return new _ProjectionRead__tr_move3(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
    }

    public _ProjectionRead__tr_move4 _projected_state_for__tr_move4() {
        return new _ProjectionRead__tr_move4(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
    }

    public _ProjectionRead__tr_move5 _projected_state_for__tr_move5() {
        return new _ProjectionRead__tr_move5(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
    }

    public _ProjectionRead__tr_move6 _projected_state_for__tr_move6() {
        return new _ProjectionRead__tr_move6(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
    }

    public _ProjectionRead__tr_move0 _projected_state_for__tr_move0() {
        return new _ProjectionRead__tr_move0(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
    }

    public _ProjectionRead__tr_move1 _projected_state_for__tr_move1() {
        return new _ProjectionRead__tr_move1(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
    }

    public _ProjectionRead__tr_move2 _projected_state_for__tr_move2() {
        return new _ProjectionRead__tr_move2(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
    }

    public _ProjectionRead__check_inv_2 _projected_state_for__check_inv_2() {
        return new _ProjectionRead__check_inv_2(P1);
    }

    public _ProjectionRead__check_inv_3 _projected_state_for__check_inv_3() {
        return new _ProjectionRead__check_inv_3(P2);
    }

    public _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() {
        return new _ProjectionRead__check_inv_1(P0);
    }

    public _ProjectionRead__check_inv_6 _projected_state_for__check_inv_6() {
        return new _ProjectionRead__check_inv_6(P5);
    }

    public _ProjectionRead__check_inv_10 _projected_state_for__check_inv_10() {
        return new _ProjectionRead__check_inv_10(RB);
    }

    public _ProjectionRead__check_inv_7 _projected_state_for__check_inv_7() {
        return new _ProjectionRead__check_inv_7(P6);
    }

    public _ProjectionRead__check_inv_4 _projected_state_for__check_inv_4() {
        return new _ProjectionRead__check_inv_4(P3);
    }

    public _ProjectionRead__check_inv_5 _projected_state_for__check_inv_5() {
        return new _ProjectionRead__check_inv_5(P4);
    }

    public _ProjectionRead__check_inv_8 _projected_state_for__check_inv_8() {
        return new _ProjectionRead__check_inv_8(P7);
    }

    public _ProjectionRead__check_inv_9 _projected_state_for__check_inv_9() {
        return new _ProjectionRead__check_inv_9(RA);
    }

    public _ProjectionWrite_move5 _update_for_move5() {
        return new _ProjectionWrite_move5(RB,P5,RA);
    }

    public _ProjectionWrite_move6 _update_for_move6() {
        return new _ProjectionWrite_move6(RB,P6,RA);
    }

    public _ProjectionWrite_arrived _update_for_arrived() {
        return new _ProjectionWrite_arrived();
    }

    public _ProjectionWrite_move7 _update_for_move7() {
        return new _ProjectionWrite_move7(RB,P7,RA);
    }

    public _ProjectionWrite_move1 _update_for_move1() {
        return new _ProjectionWrite_move1(RB,P1,RA);
    }

    public _ProjectionWrite_move2 _update_for_move2() {
        return new _ProjectionWrite_move2(RB,P2,RA);
    }

    public _ProjectionWrite_move3 _update_for_move3() {
        return new _ProjectionWrite_move3(RB,P3,RA);
    }

    public _ProjectionWrite_move4 _update_for_move4() {
        return new _ProjectionWrite_move4(RB,P4,RA);
    }

    public _ProjectionWrite_move0 _update_for_move0() {
        return new _ProjectionWrite_move0(P0,RB,RA);
    }

    public void _apply_update_for_move5(_ProjectionWrite_move5 update) {
        this.RB = update.RB;
        this.P5 = update.P5;
        this.RA = update.RA;
    }

    public void _apply_update_for_move6(_ProjectionWrite_move6 update) {
        this.RB = update.RB;
        this.P6 = update.P6;
        this.RA = update.RA;
    }

    public void _apply_update_for_arrived(_ProjectionWrite_arrived update) {
    }

    public void _apply_update_for_move7(_ProjectionWrite_move7 update) {
        this.RB = update.RB;
        this.P7 = update.P7;
        this.RA = update.RA;
    }

    public void _apply_update_for_move1(_ProjectionWrite_move1 update) {
        this.RB = update.RB;
        this.P1 = update.P1;
        this.RA = update.RA;
    }

    public void _apply_update_for_move2(_ProjectionWrite_move2 update) {
        this.RB = update.RB;
        this.P2 = update.P2;
        this.RA = update.RA;
    }

    public void _apply_update_for_move3(_ProjectionWrite_move3 update) {
        this.RB = update.RB;
        this.P3 = update.P3;
        this.RA = update.RA;
    }

    public void _apply_update_for_move4(_ProjectionWrite_move4 update) {
        this.RB = update.RB;
        this.P4 = update.P4;
        this.RA = update.RA;
    }

    public void _apply_update_for_move0(_ProjectionWrite_move0 update) {
        this.P0 = update.P0;
        this.RB = update.RB;
        this.RA = update.RA;
    }

    public boolean _check_inv_1() {
        return new BBoolean(P0.greaterEqual(new BInteger(0)).booleanValue() && P0.lessEqual(new BInteger(6)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_2() {
        return new BBoolean(P1.greaterEqual(new BInteger(0)).booleanValue() && P1.lessEqual(new BInteger(6)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_3() {
        return new BBoolean(P2.greaterEqual(new BInteger(0)).booleanValue() && P2.lessEqual(new BInteger(6)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_4() {
        return new BBoolean(P3.greaterEqual(new BInteger(0)).booleanValue() && P3.lessEqual(new BInteger(6)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_5() {
        return new BBoolean(P4.greaterEqual(new BInteger(0)).booleanValue() && P4.lessEqual(new BInteger(6)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_6() {
        return new BBoolean(P5.greaterEqual(new BInteger(0)).booleanValue() && P5.lessEqual(new BInteger(6)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_7() {
        return new BBoolean(P6.greaterEqual(new BInteger(0)).booleanValue() && P6.lessEqual(new BInteger(6)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_8() {
        return new BBoolean(P7.greaterEqual(new BInteger(0)).booleanValue() && P7.lessEqual(new BInteger(6)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_9() {
        return new BBoolean(RA.greaterEqual(new BInteger(0)).booleanValue() && RA.lessEqual(new BInteger(8)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_10() {
        return new BBoolean(RB.greaterEqual(new BInteger(0)).booleanValue() && RB.lessEqual(new BInteger(8)).booleanValue()).booleanValue();
    }


    private static class ModelChecker {
        private final Type type;
        private final int threads;
        private final boolean isCaching;
        private final boolean isDebug;

        private final LinkedList<prob_oneway8seq> unvisitedStates = new LinkedList<>();
        private final Set<prob_oneway8seq> states = ConcurrentHashMap.newKeySet();
        private AtomicInteger transitions = new AtomicInteger(0);
        private ThreadPoolExecutor threadPool;
        private Object waitLock = new Object();

        private AtomicBoolean invariantViolated = new AtomicBoolean(false);
        private AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        private prob_oneway8seq counterExampleState = null;

        PersistentHashMap _OpCache_move0 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_move0 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_move1 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_move1 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_move2 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_move2 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_move3 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_move3 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_move4 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_move4 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_move5 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_move5 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_move6 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_move6 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_move7 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_move7 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_arrived = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_arrived = PersistentHashMap.EMPTY;
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
            prob_oneway8seq machine = new prob_oneway8seq();
            states.add(machine);
            unvisitedStates.add(machine);

            while(!unvisitedStates.isEmpty()) {
                prob_oneway8seq state = next();

                Set<prob_oneway8seq> nextStates = generateNextStates(state);

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
            prob_oneway8seq machine = new prob_oneway8seq();
            states.add(machine);
            unvisitedStates.add(machine);

            AtomicBoolean stopThreads = new AtomicBoolean(false);
            AtomicInteger possibleQueueChanges = new AtomicInteger(0);

            while(!unvisitedStates.isEmpty() && !stopThreads.get()) {
                possibleQueueChanges.incrementAndGet();
                prob_oneway8seq state = next();
                Runnable task = () -> {
                    Set<prob_oneway8seq> nextStates = generateNextStates(state);

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

        private prob_oneway8seq next() {
            synchronized(this.unvisitedStates) {
                return switch(type) {
                    case BFS -> this.unvisitedStates.removeFirst();
                    case DFS -> this.unvisitedStates.removeLast();
                    case MIXED -> this.unvisitedStates.size() % 2 == 0 ? this.unvisitedStates.removeFirst() : this.unvisitedStates.removeLast();
                };
            }
        }

        @SuppressWarnings("unchecked")
        private Set<prob_oneway8seq> generateNextStates(final prob_oneway8seq state) {
            Set<prob_oneway8seq> result = new HashSet<>();
            if(isCaching) {
                _ProjectionRead__tr_move0 read__tr_move0_state = state._projected_state_for__tr_move0();
                Object _obj__trid_1 = GET.invoke(_OpCache_tr_move0, read__tr_move0_state);
                boolean _trid_1;
                if(_obj__trid_1 == null) {
                    _trid_1 = state._tr_move0();
                    _OpCache_tr_move0 = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_move0, read__tr_move0_state, _trid_1);
                } else {
                    _trid_1 = (boolean) _obj__trid_1;
                }
                if(_trid_1) {
                    prob_oneway8seq copiedState = state._copy();
                    _ProjectionRead_move0 readState = state._projected_state_for_move0();
                    PersistentHashMap _OpCache_with_parameter_move0 = (PersistentHashMap) GET.invoke(_OpCache_move0, _trid_1);
                    if(_OpCache_with_parameter_move0 != null) {
                        _ProjectionWrite_move0 writeState = (_ProjectionWrite_move0) GET.invoke(_OpCache_with_parameter_move0, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_move0(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.move0();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_move0();
                            _OpCache_with_parameter_move0 = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_move0, readState, writeState);
                            _OpCache_move0 = (PersistentHashMap) ASSOC.invoke(_OpCache_move0, _trid_1, _OpCache_with_parameter_move0);
                        }

                    } else {
                        copiedState.move0();
                        copiedState.parent = state;
                        _ProjectionWrite_move0 writeState = copiedState._update_for_move0();
                        _OpCache_with_parameter_move0 = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_move0 = (PersistentHashMap) ASSOC.invoke(_OpCache_move0, _trid_1, _OpCache_with_parameter_move0);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_move1 read__tr_move1_state = state._projected_state_for__tr_move1();
                Object _obj__trid_2 = GET.invoke(_OpCache_tr_move1, read__tr_move1_state);
                boolean _trid_2;
                if(_obj__trid_2 == null) {
                    _trid_2 = state._tr_move1();
                    _OpCache_tr_move1 = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_move1, read__tr_move1_state, _trid_2);
                } else {
                    _trid_2 = (boolean) _obj__trid_2;
                }
                if(_trid_2) {
                    prob_oneway8seq copiedState = state._copy();
                    _ProjectionRead_move1 readState = state._projected_state_for_move1();
                    PersistentHashMap _OpCache_with_parameter_move1 = (PersistentHashMap) GET.invoke(_OpCache_move1, _trid_2);
                    if(_OpCache_with_parameter_move1 != null) {
                        _ProjectionWrite_move1 writeState = (_ProjectionWrite_move1) GET.invoke(_OpCache_with_parameter_move1, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_move1(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.move1();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_move1();
                            _OpCache_with_parameter_move1 = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_move1, readState, writeState);
                            _OpCache_move1 = (PersistentHashMap) ASSOC.invoke(_OpCache_move1, _trid_2, _OpCache_with_parameter_move1);
                        }

                    } else {
                        copiedState.move1();
                        copiedState.parent = state;
                        _ProjectionWrite_move1 writeState = copiedState._update_for_move1();
                        _OpCache_with_parameter_move1 = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_move1 = (PersistentHashMap) ASSOC.invoke(_OpCache_move1, _trid_2, _OpCache_with_parameter_move1);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_move2 read__tr_move2_state = state._projected_state_for__tr_move2();
                Object _obj__trid_3 = GET.invoke(_OpCache_tr_move2, read__tr_move2_state);
                boolean _trid_3;
                if(_obj__trid_3 == null) {
                    _trid_3 = state._tr_move2();
                    _OpCache_tr_move2 = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_move2, read__tr_move2_state, _trid_3);
                } else {
                    _trid_3 = (boolean) _obj__trid_3;
                }
                if(_trid_3) {
                    prob_oneway8seq copiedState = state._copy();
                    _ProjectionRead_move2 readState = state._projected_state_for_move2();
                    PersistentHashMap _OpCache_with_parameter_move2 = (PersistentHashMap) GET.invoke(_OpCache_move2, _trid_3);
                    if(_OpCache_with_parameter_move2 != null) {
                        _ProjectionWrite_move2 writeState = (_ProjectionWrite_move2) GET.invoke(_OpCache_with_parameter_move2, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_move2(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.move2();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_move2();
                            _OpCache_with_parameter_move2 = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_move2, readState, writeState);
                            _OpCache_move2 = (PersistentHashMap) ASSOC.invoke(_OpCache_move2, _trid_3, _OpCache_with_parameter_move2);
                        }

                    } else {
                        copiedState.move2();
                        copiedState.parent = state;
                        _ProjectionWrite_move2 writeState = copiedState._update_for_move2();
                        _OpCache_with_parameter_move2 = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_move2 = (PersistentHashMap) ASSOC.invoke(_OpCache_move2, _trid_3, _OpCache_with_parameter_move2);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_move3 read__tr_move3_state = state._projected_state_for__tr_move3();
                Object _obj__trid_4 = GET.invoke(_OpCache_tr_move3, read__tr_move3_state);
                boolean _trid_4;
                if(_obj__trid_4 == null) {
                    _trid_4 = state._tr_move3();
                    _OpCache_tr_move3 = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_move3, read__tr_move3_state, _trid_4);
                } else {
                    _trid_4 = (boolean) _obj__trid_4;
                }
                if(_trid_4) {
                    prob_oneway8seq copiedState = state._copy();
                    _ProjectionRead_move3 readState = state._projected_state_for_move3();
                    PersistentHashMap _OpCache_with_parameter_move3 = (PersistentHashMap) GET.invoke(_OpCache_move3, _trid_4);
                    if(_OpCache_with_parameter_move3 != null) {
                        _ProjectionWrite_move3 writeState = (_ProjectionWrite_move3) GET.invoke(_OpCache_with_parameter_move3, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_move3(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.move3();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_move3();
                            _OpCache_with_parameter_move3 = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_move3, readState, writeState);
                            _OpCache_move3 = (PersistentHashMap) ASSOC.invoke(_OpCache_move3, _trid_4, _OpCache_with_parameter_move3);
                        }

                    } else {
                        copiedState.move3();
                        copiedState.parent = state;
                        _ProjectionWrite_move3 writeState = copiedState._update_for_move3();
                        _OpCache_with_parameter_move3 = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_move3 = (PersistentHashMap) ASSOC.invoke(_OpCache_move3, _trid_4, _OpCache_with_parameter_move3);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_move4 read__tr_move4_state = state._projected_state_for__tr_move4();
                Object _obj__trid_5 = GET.invoke(_OpCache_tr_move4, read__tr_move4_state);
                boolean _trid_5;
                if(_obj__trid_5 == null) {
                    _trid_5 = state._tr_move4();
                    _OpCache_tr_move4 = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_move4, read__tr_move4_state, _trid_5);
                } else {
                    _trid_5 = (boolean) _obj__trid_5;
                }
                if(_trid_5) {
                    prob_oneway8seq copiedState = state._copy();
                    _ProjectionRead_move4 readState = state._projected_state_for_move4();
                    PersistentHashMap _OpCache_with_parameter_move4 = (PersistentHashMap) GET.invoke(_OpCache_move4, _trid_5);
                    if(_OpCache_with_parameter_move4 != null) {
                        _ProjectionWrite_move4 writeState = (_ProjectionWrite_move4) GET.invoke(_OpCache_with_parameter_move4, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_move4(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.move4();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_move4();
                            _OpCache_with_parameter_move4 = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_move4, readState, writeState);
                            _OpCache_move4 = (PersistentHashMap) ASSOC.invoke(_OpCache_move4, _trid_5, _OpCache_with_parameter_move4);
                        }

                    } else {
                        copiedState.move4();
                        copiedState.parent = state;
                        _ProjectionWrite_move4 writeState = copiedState._update_for_move4();
                        _OpCache_with_parameter_move4 = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_move4 = (PersistentHashMap) ASSOC.invoke(_OpCache_move4, _trid_5, _OpCache_with_parameter_move4);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_move5 read__tr_move5_state = state._projected_state_for__tr_move5();
                Object _obj__trid_6 = GET.invoke(_OpCache_tr_move5, read__tr_move5_state);
                boolean _trid_6;
                if(_obj__trid_6 == null) {
                    _trid_6 = state._tr_move5();
                    _OpCache_tr_move5 = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_move5, read__tr_move5_state, _trid_6);
                } else {
                    _trid_6 = (boolean) _obj__trid_6;
                }
                if(_trid_6) {
                    prob_oneway8seq copiedState = state._copy();
                    _ProjectionRead_move5 readState = state._projected_state_for_move5();
                    PersistentHashMap _OpCache_with_parameter_move5 = (PersistentHashMap) GET.invoke(_OpCache_move5, _trid_6);
                    if(_OpCache_with_parameter_move5 != null) {
                        _ProjectionWrite_move5 writeState = (_ProjectionWrite_move5) GET.invoke(_OpCache_with_parameter_move5, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_move5(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.move5();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_move5();
                            _OpCache_with_parameter_move5 = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_move5, readState, writeState);
                            _OpCache_move5 = (PersistentHashMap) ASSOC.invoke(_OpCache_move5, _trid_6, _OpCache_with_parameter_move5);
                        }

                    } else {
                        copiedState.move5();
                        copiedState.parent = state;
                        _ProjectionWrite_move5 writeState = copiedState._update_for_move5();
                        _OpCache_with_parameter_move5 = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_move5 = (PersistentHashMap) ASSOC.invoke(_OpCache_move5, _trid_6, _OpCache_with_parameter_move5);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_move6 read__tr_move6_state = state._projected_state_for__tr_move6();
                Object _obj__trid_7 = GET.invoke(_OpCache_tr_move6, read__tr_move6_state);
                boolean _trid_7;
                if(_obj__trid_7 == null) {
                    _trid_7 = state._tr_move6();
                    _OpCache_tr_move6 = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_move6, read__tr_move6_state, _trid_7);
                } else {
                    _trid_7 = (boolean) _obj__trid_7;
                }
                if(_trid_7) {
                    prob_oneway8seq copiedState = state._copy();
                    _ProjectionRead_move6 readState = state._projected_state_for_move6();
                    PersistentHashMap _OpCache_with_parameter_move6 = (PersistentHashMap) GET.invoke(_OpCache_move6, _trid_7);
                    if(_OpCache_with_parameter_move6 != null) {
                        _ProjectionWrite_move6 writeState = (_ProjectionWrite_move6) GET.invoke(_OpCache_with_parameter_move6, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_move6(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.move6();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_move6();
                            _OpCache_with_parameter_move6 = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_move6, readState, writeState);
                            _OpCache_move6 = (PersistentHashMap) ASSOC.invoke(_OpCache_move6, _trid_7, _OpCache_with_parameter_move6);
                        }

                    } else {
                        copiedState.move6();
                        copiedState.parent = state;
                        _ProjectionWrite_move6 writeState = copiedState._update_for_move6();
                        _OpCache_with_parameter_move6 = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_move6 = (PersistentHashMap) ASSOC.invoke(_OpCache_move6, _trid_7, _OpCache_with_parameter_move6);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_move7 read__tr_move7_state = state._projected_state_for__tr_move7();
                Object _obj__trid_8 = GET.invoke(_OpCache_tr_move7, read__tr_move7_state);
                boolean _trid_8;
                if(_obj__trid_8 == null) {
                    _trid_8 = state._tr_move7();
                    _OpCache_tr_move7 = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_move7, read__tr_move7_state, _trid_8);
                } else {
                    _trid_8 = (boolean) _obj__trid_8;
                }
                if(_trid_8) {
                    prob_oneway8seq copiedState = state._copy();
                    _ProjectionRead_move7 readState = state._projected_state_for_move7();
                    PersistentHashMap _OpCache_with_parameter_move7 = (PersistentHashMap) GET.invoke(_OpCache_move7, _trid_8);
                    if(_OpCache_with_parameter_move7 != null) {
                        _ProjectionWrite_move7 writeState = (_ProjectionWrite_move7) GET.invoke(_OpCache_with_parameter_move7, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_move7(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.move7();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_move7();
                            _OpCache_with_parameter_move7 = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_move7, readState, writeState);
                            _OpCache_move7 = (PersistentHashMap) ASSOC.invoke(_OpCache_move7, _trid_8, _OpCache_with_parameter_move7);
                        }

                    } else {
                        copiedState.move7();
                        copiedState.parent = state;
                        _ProjectionWrite_move7 writeState = copiedState._update_for_move7();
                        _OpCache_with_parameter_move7 = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_move7 = (PersistentHashMap) ASSOC.invoke(_OpCache_move7, _trid_8, _OpCache_with_parameter_move7);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_arrived read__tr_arrived_state = state._projected_state_for__tr_arrived();
                Object _obj__trid_9 = GET.invoke(_OpCache_tr_arrived, read__tr_arrived_state);
                boolean _trid_9;
                if(_obj__trid_9 == null) {
                    _trid_9 = state._tr_arrived();
                    _OpCache_tr_arrived = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_arrived, read__tr_arrived_state, _trid_9);
                } else {
                    _trid_9 = (boolean) _obj__trid_9;
                }
                if(_trid_9) {
                    prob_oneway8seq copiedState = state._copy();
                    _ProjectionRead_arrived readState = state._projected_state_for_arrived();
                    PersistentHashMap _OpCache_with_parameter_arrived = (PersistentHashMap) GET.invoke(_OpCache_arrived, _trid_9);
                    if(_OpCache_with_parameter_arrived != null) {
                        _ProjectionWrite_arrived writeState = (_ProjectionWrite_arrived) GET.invoke(_OpCache_with_parameter_arrived, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_arrived(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.arrived();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_arrived();
                            _OpCache_with_parameter_arrived = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_arrived, readState, writeState);
                            _OpCache_arrived = (PersistentHashMap) ASSOC.invoke(_OpCache_arrived, _trid_9, _OpCache_with_parameter_arrived);
                        }

                    } else {
                        copiedState.arrived();
                        copiedState.parent = state;
                        _ProjectionWrite_arrived writeState = copiedState._update_for_arrived();
                        _OpCache_with_parameter_arrived = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_arrived = (PersistentHashMap) ASSOC.invoke(_OpCache_arrived, _trid_9, _OpCache_with_parameter_arrived);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            } else {
                if(state._tr_move0()) {
                    prob_oneway8seq copiedState = state._copy();
                    copiedState.move0();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_move1()) {
                    prob_oneway8seq copiedState = state._copy();
                    copiedState.move1();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_move2()) {
                    prob_oneway8seq copiedState = state._copy();
                    copiedState.move2();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_move3()) {
                    prob_oneway8seq copiedState = state._copy();
                    copiedState.move3();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_move4()) {
                    prob_oneway8seq copiedState = state._copy();
                    copiedState.move4();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_move5()) {
                    prob_oneway8seq copiedState = state._copy();
                    copiedState.move5();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_move6()) {
                    prob_oneway8seq copiedState = state._copy();
                    copiedState.move6();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_move7()) {
                    prob_oneway8seq copiedState = state._copy();
                    copiedState.move7();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_arrived()) {
                    prob_oneway8seq copiedState = state._copy();
                    copiedState.arrived();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            }
            return result;
        }

        private boolean invariantViolated(final prob_oneway8seq state) {
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
