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


public class CAN_BUS_tlc {


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

    public CAN_BUS_tlc parent;
    public String stateAccessedVia;

    public static class _ProjectionRead_T1Evaluate {

        public T1state T1_state;
        public BInteger T1_timer;

        public _ProjectionRead_T1Evaluate(T1state T1_state, BInteger T1_timer) {
            this.T1_state = T1_state;
            this.T1_timer = T1_timer;
        }

        public String toString() {
            return "{" + "T1_state: " + this.T1_state + "," + "T1_timer: " + this.T1_timer + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_T1Evaluate)) {
                return false;
            }
            _ProjectionRead_T1Evaluate o = (_ProjectionRead_T1Evaluate) other;
            return this.T1_state.equals(o.T1_state) && this.T1_timer.equals(o.T1_timer);
        }

        public int hashCode() {
            return Objects.hash(T1_state, T1_timer);
        }
    }

    public static class _ProjectionRead__tr_T1Evaluate {

        public T1state T1_state;
        public BInteger T1_timer;

        public _ProjectionRead__tr_T1Evaluate(T1state T1_state, BInteger T1_timer) {
            this.T1_state = T1_state;
            this.T1_timer = T1_timer;
        }

        public String toString() {
            return "{" + "T1_state: " + this.T1_state + "," + "T1_timer: " + this.T1_timer + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_T1Evaluate)) {
                return false;
            }
            _ProjectionRead__tr_T1Evaluate o = (_ProjectionRead__tr_T1Evaluate) other;
            return this.T1_state.equals(o.T1_state) && this.T1_timer.equals(o.T1_timer);
        }

        public int hashCode() {
            return Objects.hash(T1_state, T1_timer);
        }
    }

    public static class _ProjectionWrite_T1Evaluate {

        public T1state T1_state;
        public BInteger T1_timer;

        public _ProjectionWrite_T1Evaluate(T1state T1_state, BInteger T1_timer) {
            this.T1_state = T1_state;
            this.T1_timer = T1_timer;
        }

        public String toString() {
            return "{" + "T1_state: " + this.T1_state + "," + "T1_timer: " + this.T1_timer + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_T1Evaluate)) {
                return false;
            }
            _ProjectionWrite_T1Evaluate o = (_ProjectionWrite_T1Evaluate) other;
            return this.T1_state.equals(o.T1_state) && this.T1_timer.equals(o.T1_timer);
        }

        public int hashCode() {
            return Objects.hash(T1_state, T1_timer);
        }
    }

    public static class _ProjectionRead_T1Calculate {

        public T1state T1_state;

        public _ProjectionRead_T1Calculate(T1state T1_state) {
            this.T1_state = T1_state;
        }

        public String toString() {
            return "{" + "T1_state: " + this.T1_state + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_T1Calculate)) {
                return false;
            }
            _ProjectionRead_T1Calculate o = (_ProjectionRead_T1Calculate) other;
            return this.T1_state.equals(o.T1_state);
        }

        public int hashCode() {
            return Objects.hash(T1_state);
        }
    }

    public static class _ProjectionRead__tr_T1Calculate {

        public T1state T1_state;

        public _ProjectionRead__tr_T1Calculate(T1state T1_state) {
            this.T1_state = T1_state;
        }

        public String toString() {
            return "{" + "T1_state: " + this.T1_state + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_T1Calculate)) {
                return false;
            }
            _ProjectionRead__tr_T1Calculate o = (_ProjectionRead__tr_T1Calculate) other;
            return this.T1_state.equals(o.T1_state);
        }

        public int hashCode() {
            return Objects.hash(T1_state);
        }
    }

    public static class _ProjectionWrite_T1Calculate {

        public T1state T1_state;
        public BInteger T1_writevalue;

        public _ProjectionWrite_T1Calculate(T1state T1_state, BInteger T1_writevalue) {
            this.T1_state = T1_state;
            this.T1_writevalue = T1_writevalue;
        }

        public String toString() {
            return "{" + "T1_state: " + this.T1_state + "," + "T1_writevalue: " + this.T1_writevalue + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_T1Calculate)) {
                return false;
            }
            _ProjectionWrite_T1Calculate o = (_ProjectionWrite_T1Calculate) other;
            return this.T1_state.equals(o.T1_state) && this.T1_writevalue.equals(o.T1_writevalue);
        }

        public int hashCode() {
            return Objects.hash(T1_state, T1_writevalue);
        }
    }

    public static class _ProjectionRead_T1SendResult {

        public T1state T1_state;
        public BInteger T1_writevalue;
        public BRelation<BInteger, BInteger> BUSwrite;

        public _ProjectionRead_T1SendResult(T1state T1_state, BInteger T1_writevalue, BRelation<BInteger, BInteger> BUSwrite) {
            this.T1_state = T1_state;
            this.T1_writevalue = T1_writevalue;
            this.BUSwrite = BUSwrite;
        }

        public String toString() {
            return "{" + "T1_state: " + this.T1_state + "," + "T1_writevalue: " + this.T1_writevalue + "," + "BUSwrite: " + this.BUSwrite + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_T1SendResult)) {
                return false;
            }
            _ProjectionRead_T1SendResult o = (_ProjectionRead_T1SendResult) other;
            return this.T1_state.equals(o.T1_state) && this.T1_writevalue.equals(o.T1_writevalue) && this.BUSwrite.equals(o.BUSwrite);
        }

        public int hashCode() {
            return Objects.hash(T1_state, T1_writevalue, BUSwrite);
        }
    }

    public static class _ProjectionRead__tr_T1SendResult {

        public T1state T1_state;
        public BInteger T1_writevalue;

        public _ProjectionRead__tr_T1SendResult(T1state T1_state, BInteger T1_writevalue) {
            this.T1_state = T1_state;
            this.T1_writevalue = T1_writevalue;
        }

        public String toString() {
            return "{" + "T1_state: " + this.T1_state + "," + "T1_writevalue: " + this.T1_writevalue + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_T1SendResult)) {
                return false;
            }
            _ProjectionRead__tr_T1SendResult o = (_ProjectionRead__tr_T1SendResult) other;
            return this.T1_state.equals(o.T1_state) && this.T1_writevalue.equals(o.T1_writevalue);
        }

        public int hashCode() {
            return Objects.hash(T1_state, T1_writevalue);
        }
    }

    public static class _ProjectionWrite_T1SendResult {

        public T1state T1_state;
        public BRelation<BInteger, BInteger> BUSwrite;

        public _ProjectionWrite_T1SendResult(T1state T1_state, BRelation<BInteger, BInteger> BUSwrite) {
            this.T1_state = T1_state;
            this.BUSwrite = BUSwrite;
        }

        public String toString() {
            return "{" + "T1_state: " + this.T1_state + "," + "BUSwrite: " + this.BUSwrite + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_T1SendResult)) {
                return false;
            }
            _ProjectionWrite_T1SendResult o = (_ProjectionWrite_T1SendResult) other;
            return this.T1_state.equals(o.T1_state) && this.BUSwrite.equals(o.BUSwrite);
        }

        public int hashCode() {
            return Objects.hash(T1_state, BUSwrite);
        }
    }

    public static class _ProjectionRead_T1Wait {

        public T1state T1_state;

        public _ProjectionRead_T1Wait(T1state T1_state) {
            this.T1_state = T1_state;
        }

        public String toString() {
            return "{" + "T1_state: " + this.T1_state + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_T1Wait)) {
                return false;
            }
            _ProjectionRead_T1Wait o = (_ProjectionRead_T1Wait) other;
            return this.T1_state.equals(o.T1_state);
        }

        public int hashCode() {
            return Objects.hash(T1_state);
        }
    }

    public static class _ProjectionRead__tr_T1Wait {

        public T1state T1_state;

        public _ProjectionRead__tr_T1Wait(T1state T1_state) {
            this.T1_state = T1_state;
        }

        public String toString() {
            return "{" + "T1_state: " + this.T1_state + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_T1Wait)) {
                return false;
            }
            _ProjectionRead__tr_T1Wait o = (_ProjectionRead__tr_T1Wait) other;
            return this.T1_state.equals(o.T1_state);
        }

        public int hashCode() {
            return Objects.hash(T1_state);
        }
    }

    public static class _ProjectionWrite_T1Wait {

        public T1state T1_state;
        public BInteger T1_timer;

        public _ProjectionWrite_T1Wait(T1state T1_state, BInteger T1_timer) {
            this.T1_state = T1_state;
            this.T1_timer = T1_timer;
        }

        public String toString() {
            return "{" + "T1_state: " + this.T1_state + "," + "T1_timer: " + this.T1_timer + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_T1Wait)) {
                return false;
            }
            _ProjectionWrite_T1Wait o = (_ProjectionWrite_T1Wait) other;
            return this.T1_state.equals(o.T1_state) && this.T1_timer.equals(o.T1_timer);
        }

        public int hashCode() {
            return Objects.hash(T1_state, T1_timer);
        }
    }

    public static class _ProjectionRead_T2Evaluate {

        public T2state T2_state;
        public BInteger T2_timer;

        public _ProjectionRead_T2Evaluate(T2state T2_state, BInteger T2_timer) {
            this.T2_state = T2_state;
            this.T2_timer = T2_timer;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "T2_timer: " + this.T2_timer + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_T2Evaluate)) {
                return false;
            }
            _ProjectionRead_T2Evaluate o = (_ProjectionRead_T2Evaluate) other;
            return this.T2_state.equals(o.T2_state) && this.T2_timer.equals(o.T2_timer);
        }

        public int hashCode() {
            return Objects.hash(T2_state, T2_timer);
        }
    }

    public static class _ProjectionRead__tr_T2Evaluate {

        public T2state T2_state;
        public BInteger T2_timer;

        public _ProjectionRead__tr_T2Evaluate(T2state T2_state, BInteger T2_timer) {
            this.T2_state = T2_state;
            this.T2_timer = T2_timer;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "T2_timer: " + this.T2_timer + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_T2Evaluate)) {
                return false;
            }
            _ProjectionRead__tr_T2Evaluate o = (_ProjectionRead__tr_T2Evaluate) other;
            return this.T2_state.equals(o.T2_state) && this.T2_timer.equals(o.T2_timer);
        }

        public int hashCode() {
            return Objects.hash(T2_state, T2_timer);
        }
    }

    public static class _ProjectionWrite_T2Evaluate {

        public T2state T2_state;
        public BInteger T2_timer;

        public _ProjectionWrite_T2Evaluate(T2state T2_state, BInteger T2_timer) {
            this.T2_state = T2_state;
            this.T2_timer = T2_timer;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "T2_timer: " + this.T2_timer + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_T2Evaluate)) {
                return false;
            }
            _ProjectionWrite_T2Evaluate o = (_ProjectionWrite_T2Evaluate) other;
            return this.T2_state.equals(o.T2_state) && this.T2_timer.equals(o.T2_timer);
        }

        public int hashCode() {
            return Objects.hash(T2_state, T2_timer);
        }
    }

    public static class _ProjectionRead_T2ReadBus {

        public T2state T2_state;
        public BInteger BUSpriority;
        public BInteger BUSvalue;

        public _ProjectionRead_T2ReadBus(T2state T2_state, BInteger BUSpriority, BInteger BUSvalue) {
            this.T2_state = T2_state;
            this.BUSpriority = BUSpriority;
            this.BUSvalue = BUSvalue;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "BUSpriority: " + this.BUSpriority + "," + "BUSvalue: " + this.BUSvalue + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_T2ReadBus)) {
                return false;
            }
            _ProjectionRead_T2ReadBus o = (_ProjectionRead_T2ReadBus) other;
            return this.T2_state.equals(o.T2_state) && this.BUSpriority.equals(o.BUSpriority) && this.BUSvalue.equals(o.BUSvalue);
        }

        public int hashCode() {
            return Objects.hash(T2_state, BUSpriority, BUSvalue);
        }
    }

    public static class _ProjectionRead__tr_T2ReadBus {

        public T2state T2_state;
        public BInteger BUSpriority;
        public BInteger BUSvalue;

        public _ProjectionRead__tr_T2ReadBus(T2state T2_state, BInteger BUSpriority, BInteger BUSvalue) {
            this.T2_state = T2_state;
            this.BUSpriority = BUSpriority;
            this.BUSvalue = BUSvalue;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "BUSpriority: " + this.BUSpriority + "," + "BUSvalue: " + this.BUSvalue + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_T2ReadBus)) {
                return false;
            }
            _ProjectionRead__tr_T2ReadBus o = (_ProjectionRead__tr_T2ReadBus) other;
            return this.T2_state.equals(o.T2_state) && this.BUSpriority.equals(o.BUSpriority) && this.BUSvalue.equals(o.BUSvalue);
        }

        public int hashCode() {
            return Objects.hash(T2_state, BUSpriority, BUSvalue);
        }
    }

    public static class _ProjectionWrite_T2ReadBus {

        public T2state T2_state;
        public BInteger T2_readpriority;
        public BInteger T2_readvalue;

        public _ProjectionWrite_T2ReadBus(T2state T2_state, BInteger T2_readpriority, BInteger T2_readvalue) {
            this.T2_state = T2_state;
            this.T2_readpriority = T2_readpriority;
            this.T2_readvalue = T2_readvalue;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "T2_readpriority: " + this.T2_readpriority + "," + "T2_readvalue: " + this.T2_readvalue + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_T2ReadBus)) {
                return false;
            }
            _ProjectionWrite_T2ReadBus o = (_ProjectionWrite_T2ReadBus) other;
            return this.T2_state.equals(o.T2_state) && this.T2_readpriority.equals(o.T2_readpriority) && this.T2_readvalue.equals(o.T2_readvalue);
        }

        public int hashCode() {
            return Objects.hash(T2_state, T2_readpriority, T2_readvalue);
        }
    }

    public static class _ProjectionRead_T2Reset {

        public T2state T2_state;
        public BInteger T2_readpriority;
        public BInteger T2v;

        public _ProjectionRead_T2Reset(T2state T2_state, BInteger T2_readpriority, BInteger T2v) {
            this.T2_state = T2_state;
            this.T2_readpriority = T2_readpriority;
            this.T2v = T2v;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "T2_readpriority: " + this.T2_readpriority + "," + "T2v: " + this.T2v + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_T2Reset)) {
                return false;
            }
            _ProjectionRead_T2Reset o = (_ProjectionRead_T2Reset) other;
            return this.T2_state.equals(o.T2_state) && this.T2_readpriority.equals(o.T2_readpriority) && this.T2v.equals(o.T2v);
        }

        public int hashCode() {
            return Objects.hash(T2_state, T2_readpriority, T2v);
        }
    }

    public static class _ProjectionRead__tr_T2Reset {

        public T2state T2_state;
        public BInteger T2_readpriority;

        public _ProjectionRead__tr_T2Reset(T2state T2_state, BInteger T2_readpriority) {
            this.T2_state = T2_state;
            this.T2_readpriority = T2_readpriority;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "T2_readpriority: " + this.T2_readpriority + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_T2Reset)) {
                return false;
            }
            _ProjectionRead__tr_T2Reset o = (_ProjectionRead__tr_T2Reset) other;
            return this.T2_state.equals(o.T2_state) && this.T2_readpriority.equals(o.T2_readpriority);
        }

        public int hashCode() {
            return Objects.hash(T2_state, T2_readpriority);
        }
    }

    public static class _ProjectionWrite_T2Reset {

        public T2state T2_state;
        public BInteger T2_writevalue;
        public BInteger T2v;
        public T2mode T2_mode;

        public _ProjectionWrite_T2Reset(T2state T2_state, BInteger T2_writevalue, BInteger T2v, T2mode T2_mode) {
            this.T2_state = T2_state;
            this.T2_writevalue = T2_writevalue;
            this.T2v = T2v;
            this.T2_mode = T2_mode;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "T2_writevalue: " + this.T2_writevalue + "," + "T2v: " + this.T2v + "," + "T2_mode: " + this.T2_mode + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_T2Reset)) {
                return false;
            }
            _ProjectionWrite_T2Reset o = (_ProjectionWrite_T2Reset) other;
            return this.T2_state.equals(o.T2_state) && this.T2_writevalue.equals(o.T2_writevalue) && this.T2v.equals(o.T2v) && this.T2_mode.equals(o.T2_mode);
        }

        public int hashCode() {
            return Objects.hash(T2_state, T2_writevalue, T2v, T2_mode);
        }
    }

    public static class _ProjectionRead_T2Complete {

        public T2state T2_state;
        public BInteger T2_readpriority;
        public T2mode T2_mode;

        public _ProjectionRead_T2Complete(T2state T2_state, BInteger T2_readpriority, T2mode T2_mode) {
            this.T2_state = T2_state;
            this.T2_readpriority = T2_readpriority;
            this.T2_mode = T2_mode;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "T2_readpriority: " + this.T2_readpriority + "," + "T2_mode: " + this.T2_mode + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_T2Complete)) {
                return false;
            }
            _ProjectionRead_T2Complete o = (_ProjectionRead_T2Complete) other;
            return this.T2_state.equals(o.T2_state) && this.T2_readpriority.equals(o.T2_readpriority) && this.T2_mode.equals(o.T2_mode);
        }

        public int hashCode() {
            return Objects.hash(T2_state, T2_readpriority, T2_mode);
        }
    }

    public static class _ProjectionRead__tr_T2Complete {

        public T2state T2_state;
        public BInteger T2_readpriority;
        public T2mode T2_mode;

        public _ProjectionRead__tr_T2Complete(T2state T2_state, BInteger T2_readpriority, T2mode T2_mode) {
            this.T2_state = T2_state;
            this.T2_readpriority = T2_readpriority;
            this.T2_mode = T2_mode;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "T2_readpriority: " + this.T2_readpriority + "," + "T2_mode: " + this.T2_mode + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_T2Complete)) {
                return false;
            }
            _ProjectionRead__tr_T2Complete o = (_ProjectionRead__tr_T2Complete) other;
            return this.T2_state.equals(o.T2_state) && this.T2_readpriority.equals(o.T2_readpriority) && this.T2_mode.equals(o.T2_mode);
        }

        public int hashCode() {
            return Objects.hash(T2_state, T2_readpriority, T2_mode);
        }
    }

    public static class _ProjectionWrite_T2Complete {

        public T2state T2_state;
        public T2mode T2_mode;

        public _ProjectionWrite_T2Complete(T2state T2_state, T2mode T2_mode) {
            this.T2_state = T2_state;
            this.T2_mode = T2_mode;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "T2_mode: " + this.T2_mode + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_T2Complete)) {
                return false;
            }
            _ProjectionWrite_T2Complete o = (_ProjectionWrite_T2Complete) other;
            return this.T2_state.equals(o.T2_state) && this.T2_mode.equals(o.T2_mode);
        }

        public int hashCode() {
            return Objects.hash(T2_state, T2_mode);
        }
    }

    public static class _ProjectionRead_T2ReleaseBus {

        public T2state T2_state;
        public BInteger T2_readpriority;
        public BRelation<BInteger, BInteger> BUSwrite;

        public _ProjectionRead_T2ReleaseBus(T2state T2_state, BInteger T2_readpriority, BRelation<BInteger, BInteger> BUSwrite) {
            this.T2_state = T2_state;
            this.T2_readpriority = T2_readpriority;
            this.BUSwrite = BUSwrite;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "T2_readpriority: " + this.T2_readpriority + "," + "BUSwrite: " + this.BUSwrite + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_T2ReleaseBus)) {
                return false;
            }
            _ProjectionRead_T2ReleaseBus o = (_ProjectionRead_T2ReleaseBus) other;
            return this.T2_state.equals(o.T2_state) && this.T2_readpriority.equals(o.T2_readpriority) && this.BUSwrite.equals(o.BUSwrite);
        }

        public int hashCode() {
            return Objects.hash(T2_state, T2_readpriority, BUSwrite);
        }
    }

    public static class _ProjectionRead__tr_T2ReleaseBus {

        public T2state T2_state;
        public BInteger T2_readpriority;
        public BRelation<BInteger, BInteger> BUSwrite;

        public _ProjectionRead__tr_T2ReleaseBus(T2state T2_state, BInteger T2_readpriority, BRelation<BInteger, BInteger> BUSwrite) {
            this.T2_state = T2_state;
            this.T2_readpriority = T2_readpriority;
            this.BUSwrite = BUSwrite;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "T2_readpriority: " + this.T2_readpriority + "," + "BUSwrite: " + this.BUSwrite + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_T2ReleaseBus)) {
                return false;
            }
            _ProjectionRead__tr_T2ReleaseBus o = (_ProjectionRead__tr_T2ReleaseBus) other;
            return this.T2_state.equals(o.T2_state) && this.T2_readpriority.equals(o.T2_readpriority) && this.BUSwrite.equals(o.BUSwrite);
        }

        public int hashCode() {
            return Objects.hash(T2_state, T2_readpriority, BUSwrite);
        }
    }

    public static class _ProjectionWrite_T2ReleaseBus {

        public T2state T2_state;
        public BRelation<BInteger, BInteger> BUSwrite;

        public _ProjectionWrite_T2ReleaseBus(T2state T2_state, BRelation<BInteger, BInteger> BUSwrite) {
            this.T2_state = T2_state;
            this.BUSwrite = BUSwrite;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "BUSwrite: " + this.BUSwrite + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_T2ReleaseBus)) {
                return false;
            }
            _ProjectionWrite_T2ReleaseBus o = (_ProjectionWrite_T2ReleaseBus) other;
            return this.T2_state.equals(o.T2_state) && this.BUSwrite.equals(o.BUSwrite);
        }

        public int hashCode() {
            return Objects.hash(T2_state, BUSwrite);
        }
    }

    public static class _ProjectionRead_T2Calculate {

        public T2state T2_state;
        public BInteger T2_readpriority;
        public BInteger T2_readvalue;

        public _ProjectionRead_T2Calculate(T2state T2_state, BInteger T2_readpriority, BInteger T2_readvalue) {
            this.T2_state = T2_state;
            this.T2_readpriority = T2_readpriority;
            this.T2_readvalue = T2_readvalue;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "T2_readpriority: " + this.T2_readpriority + "," + "T2_readvalue: " + this.T2_readvalue + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_T2Calculate)) {
                return false;
            }
            _ProjectionRead_T2Calculate o = (_ProjectionRead_T2Calculate) other;
            return this.T2_state.equals(o.T2_state) && this.T2_readpriority.equals(o.T2_readpriority) && this.T2_readvalue.equals(o.T2_readvalue);
        }

        public int hashCode() {
            return Objects.hash(T2_state, T2_readpriority, T2_readvalue);
        }
    }

    public static class _ProjectionRead__tr_T2Calculate {

        public T2state T2_state;
        public BInteger T2_readpriority;

        public _ProjectionRead__tr_T2Calculate(T2state T2_state, BInteger T2_readpriority) {
            this.T2_state = T2_state;
            this.T2_readpriority = T2_readpriority;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "T2_readpriority: " + this.T2_readpriority + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_T2Calculate)) {
                return false;
            }
            _ProjectionRead__tr_T2Calculate o = (_ProjectionRead__tr_T2Calculate) other;
            return this.T2_state.equals(o.T2_state) && this.T2_readpriority.equals(o.T2_readpriority);
        }

        public int hashCode() {
            return Objects.hash(T2_state, T2_readpriority);
        }
    }

    public static class _ProjectionWrite_T2Calculate {

        public T2state T2_state;
        public BInteger T2v;

        public _ProjectionWrite_T2Calculate(T2state T2_state, BInteger T2v) {
            this.T2_state = T2_state;
            this.T2v = T2v;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "T2v: " + this.T2v + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_T2Calculate)) {
                return false;
            }
            _ProjectionWrite_T2Calculate o = (_ProjectionWrite_T2Calculate) other;
            return this.T2_state.equals(o.T2_state) && this.T2v.equals(o.T2v);
        }

        public int hashCode() {
            return Objects.hash(T2_state, T2v);
        }
    }

    public static class _ProjectionRead_T2WriteBus {

        public T2state T2_state;
        public BInteger T2_writevalue;
        public BRelation<BInteger, BInteger> BUSwrite;

        public _ProjectionRead_T2WriteBus(T2state T2_state, BInteger T2_writevalue, BRelation<BInteger, BInteger> BUSwrite) {
            this.T2_state = T2_state;
            this.T2_writevalue = T2_writevalue;
            this.BUSwrite = BUSwrite;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "T2_writevalue: " + this.T2_writevalue + "," + "BUSwrite: " + this.BUSwrite + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_T2WriteBus)) {
                return false;
            }
            _ProjectionRead_T2WriteBus o = (_ProjectionRead_T2WriteBus) other;
            return this.T2_state.equals(o.T2_state) && this.T2_writevalue.equals(o.T2_writevalue) && this.BUSwrite.equals(o.BUSwrite);
        }

        public int hashCode() {
            return Objects.hash(T2_state, T2_writevalue, BUSwrite);
        }
    }

    public static class _ProjectionRead__tr_T2WriteBus {

        public T2state T2_state;
        public BInteger T2_writevalue;

        public _ProjectionRead__tr_T2WriteBus(T2state T2_state, BInteger T2_writevalue) {
            this.T2_state = T2_state;
            this.T2_writevalue = T2_writevalue;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "T2_writevalue: " + this.T2_writevalue + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_T2WriteBus)) {
                return false;
            }
            _ProjectionRead__tr_T2WriteBus o = (_ProjectionRead__tr_T2WriteBus) other;
            return this.T2_state.equals(o.T2_state) && this.T2_writevalue.equals(o.T2_writevalue);
        }

        public int hashCode() {
            return Objects.hash(T2_state, T2_writevalue);
        }
    }

    public static class _ProjectionWrite_T2WriteBus {

        public T2state T2_state;
        public BRelation<BInteger, BInteger> BUSwrite;

        public _ProjectionWrite_T2WriteBus(T2state T2_state, BRelation<BInteger, BInteger> BUSwrite) {
            this.T2_state = T2_state;
            this.BUSwrite = BUSwrite;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "BUSwrite: " + this.BUSwrite + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_T2WriteBus)) {
                return false;
            }
            _ProjectionWrite_T2WriteBus o = (_ProjectionWrite_T2WriteBus) other;
            return this.T2_state.equals(o.T2_state) && this.BUSwrite.equals(o.BUSwrite);
        }

        public int hashCode() {
            return Objects.hash(T2_state, BUSwrite);
        }
    }

    public static class _ProjectionRead_T2Wait {

        public T2state T2_state;

        public _ProjectionRead_T2Wait(T2state T2_state) {
            this.T2_state = T2_state;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_T2Wait)) {
                return false;
            }
            _ProjectionRead_T2Wait o = (_ProjectionRead_T2Wait) other;
            return this.T2_state.equals(o.T2_state);
        }

        public int hashCode() {
            return Objects.hash(T2_state);
        }
    }

    public static class _ProjectionRead__tr_T2Wait {

        public T2state T2_state;

        public _ProjectionRead__tr_T2Wait(T2state T2_state) {
            this.T2_state = T2_state;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_T2Wait)) {
                return false;
            }
            _ProjectionRead__tr_T2Wait o = (_ProjectionRead__tr_T2Wait) other;
            return this.T2_state.equals(o.T2_state);
        }

        public int hashCode() {
            return Objects.hash(T2_state);
        }
    }

    public static class _ProjectionWrite_T2Wait {

        public T2state T2_state;
        public BInteger T2_timer;

        public _ProjectionWrite_T2Wait(T2state T2_state, BInteger T2_timer) {
            this.T2_state = T2_state;
            this.T2_timer = T2_timer;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "," + "T2_timer: " + this.T2_timer + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_T2Wait)) {
                return false;
            }
            _ProjectionWrite_T2Wait o = (_ProjectionWrite_T2Wait) other;
            return this.T2_state.equals(o.T2_state) && this.T2_timer.equals(o.T2_timer);
        }

        public int hashCode() {
            return Objects.hash(T2_state, T2_timer);
        }
    }

    public static class _ProjectionRead_T3Initiate {

        public BBoolean T3_evaluated;
        public T3state T3_state;
        public BBoolean T3_enabled;

        public _ProjectionRead_T3Initiate(BBoolean T3_evaluated, T3state T3_state, BBoolean T3_enabled) {
            this.T3_evaluated = T3_evaluated;
            this.T3_state = T3_state;
            this.T3_enabled = T3_enabled;
        }

        public String toString() {
            return "{" + "T3_evaluated: " + this.T3_evaluated + "," + "T3_state: " + this.T3_state + "," + "T3_enabled: " + this.T3_enabled + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_T3Initiate)) {
                return false;
            }
            _ProjectionRead_T3Initiate o = (_ProjectionRead_T3Initiate) other;
            return this.T3_evaluated.equals(o.T3_evaluated) && this.T3_state.equals(o.T3_state) && this.T3_enabled.equals(o.T3_enabled);
        }

        public int hashCode() {
            return Objects.hash(T3_evaluated, T3_state, T3_enabled);
        }
    }

    public static class _ProjectionRead__tr_T3Initiate {

        public BBoolean T3_evaluated;
        public T3state T3_state;
        public BBoolean T3_enabled;

        public _ProjectionRead__tr_T3Initiate(BBoolean T3_evaluated, T3state T3_state, BBoolean T3_enabled) {
            this.T3_evaluated = T3_evaluated;
            this.T3_state = T3_state;
            this.T3_enabled = T3_enabled;
        }

        public String toString() {
            return "{" + "T3_evaluated: " + this.T3_evaluated + "," + "T3_state: " + this.T3_state + "," + "T3_enabled: " + this.T3_enabled + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_T3Initiate)) {
                return false;
            }
            _ProjectionRead__tr_T3Initiate o = (_ProjectionRead__tr_T3Initiate) other;
            return this.T3_evaluated.equals(o.T3_evaluated) && this.T3_state.equals(o.T3_state) && this.T3_enabled.equals(o.T3_enabled);
        }

        public int hashCode() {
            return Objects.hash(T3_evaluated, T3_state, T3_enabled);
        }
    }

    public static class _ProjectionWrite_T3Initiate {

        public T3state T3_state;
        public BBoolean T3_enabled;

        public _ProjectionWrite_T3Initiate(T3state T3_state, BBoolean T3_enabled) {
            this.T3_state = T3_state;
            this.T3_enabled = T3_enabled;
        }

        public String toString() {
            return "{" + "T3_state: " + this.T3_state + "," + "T3_enabled: " + this.T3_enabled + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_T3Initiate)) {
                return false;
            }
            _ProjectionWrite_T3Initiate o = (_ProjectionWrite_T3Initiate) other;
            return this.T3_state.equals(o.T3_state) && this.T3_enabled.equals(o.T3_enabled);
        }

        public int hashCode() {
            return Objects.hash(T3_state, T3_enabled);
        }
    }

    public static class _ProjectionRead_T3Evaluate {

        public BBoolean T3_evaluated;
        public T3state T3_state;
        public BBoolean T3_enabled;

        public _ProjectionRead_T3Evaluate(BBoolean T3_evaluated, T3state T3_state, BBoolean T3_enabled) {
            this.T3_evaluated = T3_evaluated;
            this.T3_state = T3_state;
            this.T3_enabled = T3_enabled;
        }

        public String toString() {
            return "{" + "T3_evaluated: " + this.T3_evaluated + "," + "T3_state: " + this.T3_state + "," + "T3_enabled: " + this.T3_enabled + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_T3Evaluate)) {
                return false;
            }
            _ProjectionRead_T3Evaluate o = (_ProjectionRead_T3Evaluate) other;
            return this.T3_evaluated.equals(o.T3_evaluated) && this.T3_state.equals(o.T3_state) && this.T3_enabled.equals(o.T3_enabled);
        }

        public int hashCode() {
            return Objects.hash(T3_evaluated, T3_state, T3_enabled);
        }
    }

    public static class _ProjectionRead__tr_T3Evaluate {

        public BBoolean T3_evaluated;
        public T3state T3_state;
        public BBoolean T3_enabled;

        public _ProjectionRead__tr_T3Evaluate(BBoolean T3_evaluated, T3state T3_state, BBoolean T3_enabled) {
            this.T3_evaluated = T3_evaluated;
            this.T3_state = T3_state;
            this.T3_enabled = T3_enabled;
        }

        public String toString() {
            return "{" + "T3_evaluated: " + this.T3_evaluated + "," + "T3_state: " + this.T3_state + "," + "T3_enabled: " + this.T3_enabled + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_T3Evaluate)) {
                return false;
            }
            _ProjectionRead__tr_T3Evaluate o = (_ProjectionRead__tr_T3Evaluate) other;
            return this.T3_evaluated.equals(o.T3_evaluated) && this.T3_state.equals(o.T3_state) && this.T3_enabled.equals(o.T3_enabled);
        }

        public int hashCode() {
            return Objects.hash(T3_evaluated, T3_state, T3_enabled);
        }
    }

    public static class _ProjectionWrite_T3Evaluate {

        public T3state T3_state;

        public _ProjectionWrite_T3Evaluate(T3state T3_state) {
            this.T3_state = T3_state;
        }

        public String toString() {
            return "{" + "T3_state: " + this.T3_state + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_T3Evaluate)) {
                return false;
            }
            _ProjectionWrite_T3Evaluate o = (_ProjectionWrite_T3Evaluate) other;
            return this.T3_state.equals(o.T3_state);
        }

        public int hashCode() {
            return Objects.hash(T3_state);
        }
    }

    public static class _ProjectionRead_T3writebus {

        public T3state T3_state;
        public BRelation<BInteger, BInteger> BUSwrite;

        public _ProjectionRead_T3writebus(T3state T3_state, BRelation<BInteger, BInteger> BUSwrite) {
            this.T3_state = T3_state;
            this.BUSwrite = BUSwrite;
        }

        public String toString() {
            return "{" + "T3_state: " + this.T3_state + "," + "BUSwrite: " + this.BUSwrite + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_T3writebus)) {
                return false;
            }
            _ProjectionRead_T3writebus o = (_ProjectionRead_T3writebus) other;
            return this.T3_state.equals(o.T3_state) && this.BUSwrite.equals(o.BUSwrite);
        }

        public int hashCode() {
            return Objects.hash(T3_state, BUSwrite);
        }
    }

    public static class _ProjectionRead__tr_T3writebus {

        public T3state T3_state;

        public _ProjectionRead__tr_T3writebus(T3state T3_state) {
            this.T3_state = T3_state;
        }

        public String toString() {
            return "{" + "T3_state: " + this.T3_state + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_T3writebus)) {
                return false;
            }
            _ProjectionRead__tr_T3writebus o = (_ProjectionRead__tr_T3writebus) other;
            return this.T3_state.equals(o.T3_state);
        }

        public int hashCode() {
            return Objects.hash(T3_state);
        }
    }

    public static class _ProjectionWrite_T3writebus {

        public T3state T3_state;
        public BRelation<BInteger, BInteger> BUSwrite;

        public _ProjectionWrite_T3writebus(T3state T3_state, BRelation<BInteger, BInteger> BUSwrite) {
            this.T3_state = T3_state;
            this.BUSwrite = BUSwrite;
        }

        public String toString() {
            return "{" + "T3_state: " + this.T3_state + "," + "BUSwrite: " + this.BUSwrite + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_T3writebus)) {
                return false;
            }
            _ProjectionWrite_T3writebus o = (_ProjectionWrite_T3writebus) other;
            return this.T3_state.equals(o.T3_state) && this.BUSwrite.equals(o.BUSwrite);
        }

        public int hashCode() {
            return Objects.hash(T3_state, BUSwrite);
        }
    }

    public static class _ProjectionRead_T3Read {

        public BInteger BUSpriority;
        public T3state T3_state;
        public BInteger BUSvalue;

        public _ProjectionRead_T3Read(BInteger BUSpriority, T3state T3_state, BInteger BUSvalue) {
            this.BUSpriority = BUSpriority;
            this.T3_state = T3_state;
            this.BUSvalue = BUSvalue;
        }

        public String toString() {
            return "{" + "BUSpriority: " + this.BUSpriority + "," + "T3_state: " + this.T3_state + "," + "BUSvalue: " + this.BUSvalue + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_T3Read)) {
                return false;
            }
            _ProjectionRead_T3Read o = (_ProjectionRead_T3Read) other;
            return this.BUSpriority.equals(o.BUSpriority) && this.T3_state.equals(o.T3_state) && this.BUSvalue.equals(o.BUSvalue);
        }

        public int hashCode() {
            return Objects.hash(BUSpriority, T3_state, BUSvalue);
        }
    }

    public static class _ProjectionRead__tr_T3Read {

        public BInteger BUSpriority;
        public T3state T3_state;
        public BInteger BUSvalue;

        public _ProjectionRead__tr_T3Read(BInteger BUSpriority, T3state T3_state, BInteger BUSvalue) {
            this.BUSpriority = BUSpriority;
            this.T3_state = T3_state;
            this.BUSvalue = BUSvalue;
        }

        public String toString() {
            return "{" + "BUSpriority: " + this.BUSpriority + "," + "T3_state: " + this.T3_state + "," + "BUSvalue: " + this.BUSvalue + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_T3Read)) {
                return false;
            }
            _ProjectionRead__tr_T3Read o = (_ProjectionRead__tr_T3Read) other;
            return this.BUSpriority.equals(o.BUSpriority) && this.T3_state.equals(o.T3_state) && this.BUSvalue.equals(o.BUSvalue);
        }

        public int hashCode() {
            return Objects.hash(BUSpriority, T3_state, BUSvalue);
        }
    }

    public static class _ProjectionWrite_T3Read {

        public BInteger T3_readpriority;
        public BInteger T3_readvalue;
        public T3state T3_state;

        public _ProjectionWrite_T3Read(BInteger T3_readpriority, BInteger T3_readvalue, T3state T3_state) {
            this.T3_readpriority = T3_readpriority;
            this.T3_readvalue = T3_readvalue;
            this.T3_state = T3_state;
        }

        public String toString() {
            return "{" + "T3_readpriority: " + this.T3_readpriority + "," + "T3_readvalue: " + this.T3_readvalue + "," + "T3_state: " + this.T3_state + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_T3Read)) {
                return false;
            }
            _ProjectionWrite_T3Read o = (_ProjectionWrite_T3Read) other;
            return this.T3_readpriority.equals(o.T3_readpriority) && this.T3_readvalue.equals(o.T3_readvalue) && this.T3_state.equals(o.T3_state);
        }

        public int hashCode() {
            return Objects.hash(T3_readpriority, T3_readvalue, T3_state);
        }
    }

    public static class _ProjectionRead_T3Poll {

        public BInteger T3_readpriority;
        public T3state T3_state;

        public _ProjectionRead_T3Poll(BInteger T3_readpriority, T3state T3_state) {
            this.T3_readpriority = T3_readpriority;
            this.T3_state = T3_state;
        }

        public String toString() {
            return "{" + "T3_readpriority: " + this.T3_readpriority + "," + "T3_state: " + this.T3_state + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_T3Poll)) {
                return false;
            }
            _ProjectionRead_T3Poll o = (_ProjectionRead_T3Poll) other;
            return this.T3_readpriority.equals(o.T3_readpriority) && this.T3_state.equals(o.T3_state);
        }

        public int hashCode() {
            return Objects.hash(T3_readpriority, T3_state);
        }
    }

    public static class _ProjectionRead__tr_T3Poll {

        public BInteger T3_readpriority;
        public T3state T3_state;

        public _ProjectionRead__tr_T3Poll(BInteger T3_readpriority, T3state T3_state) {
            this.T3_readpriority = T3_readpriority;
            this.T3_state = T3_state;
        }

        public String toString() {
            return "{" + "T3_readpriority: " + this.T3_readpriority + "," + "T3_state: " + this.T3_state + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_T3Poll)) {
                return false;
            }
            _ProjectionRead__tr_T3Poll o = (_ProjectionRead__tr_T3Poll) other;
            return this.T3_readpriority.equals(o.T3_readpriority) && this.T3_state.equals(o.T3_state);
        }

        public int hashCode() {
            return Objects.hash(T3_readpriority, T3_state);
        }
    }

    public static class _ProjectionWrite_T3Poll {

        public T3state T3_state;

        public _ProjectionWrite_T3Poll(T3state T3_state) {
            this.T3_state = T3_state;
        }

        public String toString() {
            return "{" + "T3_state: " + this.T3_state + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_T3Poll)) {
                return false;
            }
            _ProjectionWrite_T3Poll o = (_ProjectionWrite_T3Poll) other;
            return this.T3_state.equals(o.T3_state);
        }

        public int hashCode() {
            return Objects.hash(T3_state);
        }
    }

    public static class _ProjectionRead_T3ReleaseBus {

        public BInteger T3_readpriority;
        public T3state T3_state;
        public BRelation<BInteger, BInteger> BUSwrite;

        public _ProjectionRead_T3ReleaseBus(BInteger T3_readpriority, T3state T3_state, BRelation<BInteger, BInteger> BUSwrite) {
            this.T3_readpriority = T3_readpriority;
            this.T3_state = T3_state;
            this.BUSwrite = BUSwrite;
        }

        public String toString() {
            return "{" + "T3_readpriority: " + this.T3_readpriority + "," + "T3_state: " + this.T3_state + "," + "BUSwrite: " + this.BUSwrite + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_T3ReleaseBus)) {
                return false;
            }
            _ProjectionRead_T3ReleaseBus o = (_ProjectionRead_T3ReleaseBus) other;
            return this.T3_readpriority.equals(o.T3_readpriority) && this.T3_state.equals(o.T3_state) && this.BUSwrite.equals(o.BUSwrite);
        }

        public int hashCode() {
            return Objects.hash(T3_readpriority, T3_state, BUSwrite);
        }
    }

    public static class _ProjectionRead__tr_T3ReleaseBus {

        public BInteger T3_readpriority;
        public T3state T3_state;

        public _ProjectionRead__tr_T3ReleaseBus(BInteger T3_readpriority, T3state T3_state) {
            this.T3_readpriority = T3_readpriority;
            this.T3_state = T3_state;
        }

        public String toString() {
            return "{" + "T3_readpriority: " + this.T3_readpriority + "," + "T3_state: " + this.T3_state + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_T3ReleaseBus)) {
                return false;
            }
            _ProjectionRead__tr_T3ReleaseBus o = (_ProjectionRead__tr_T3ReleaseBus) other;
            return this.T3_readpriority.equals(o.T3_readpriority) && this.T3_state.equals(o.T3_state);
        }

        public int hashCode() {
            return Objects.hash(T3_readpriority, T3_state);
        }
    }

    public static class _ProjectionWrite_T3ReleaseBus {

        public T3state T3_state;
        public BRelation<BInteger, BInteger> BUSwrite;

        public _ProjectionWrite_T3ReleaseBus(T3state T3_state, BRelation<BInteger, BInteger> BUSwrite) {
            this.T3_state = T3_state;
            this.BUSwrite = BUSwrite;
        }

        public String toString() {
            return "{" + "T3_state: " + this.T3_state + "," + "BUSwrite: " + this.BUSwrite + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_T3ReleaseBus)) {
                return false;
            }
            _ProjectionWrite_T3ReleaseBus o = (_ProjectionWrite_T3ReleaseBus) other;
            return this.T3_state.equals(o.T3_state) && this.BUSwrite.equals(o.BUSwrite);
        }

        public int hashCode() {
            return Objects.hash(T3_state, BUSwrite);
        }
    }

    public static class _ProjectionRead_T3Wait {

        public T3state T3_state;

        public _ProjectionRead_T3Wait(T3state T3_state) {
            this.T3_state = T3_state;
        }

        public String toString() {
            return "{" + "T3_state: " + this.T3_state + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_T3Wait)) {
                return false;
            }
            _ProjectionRead_T3Wait o = (_ProjectionRead_T3Wait) other;
            return this.T3_state.equals(o.T3_state);
        }

        public int hashCode() {
            return Objects.hash(T3_state);
        }
    }

    public static class _ProjectionRead__tr_T3Wait {

        public T3state T3_state;

        public _ProjectionRead__tr_T3Wait(T3state T3_state) {
            this.T3_state = T3_state;
        }

        public String toString() {
            return "{" + "T3_state: " + this.T3_state + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_T3Wait)) {
                return false;
            }
            _ProjectionRead__tr_T3Wait o = (_ProjectionRead__tr_T3Wait) other;
            return this.T3_state.equals(o.T3_state);
        }

        public int hashCode() {
            return Objects.hash(T3_state);
        }
    }

    public static class _ProjectionWrite_T3Wait {

        public BBoolean T3_evaluated;
        public T3state T3_state;

        public _ProjectionWrite_T3Wait(BBoolean T3_evaluated, T3state T3_state) {
            this.T3_evaluated = T3_evaluated;
            this.T3_state = T3_state;
        }

        public String toString() {
            return "{" + "T3_evaluated: " + this.T3_evaluated + "," + "T3_state: " + this.T3_state + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_T3Wait)) {
                return false;
            }
            _ProjectionWrite_T3Wait o = (_ProjectionWrite_T3Wait) other;
            return this.T3_evaluated.equals(o.T3_evaluated) && this.T3_state.equals(o.T3_state);
        }

        public int hashCode() {
            return Objects.hash(T3_evaluated, T3_state);
        }
    }

    public static class _ProjectionRead_T3ReEnableWait {

        public T3state T3_state;

        public _ProjectionRead_T3ReEnableWait(T3state T3_state) {
            this.T3_state = T3_state;
        }

        public String toString() {
            return "{" + "T3_state: " + this.T3_state + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_T3ReEnableWait)) {
                return false;
            }
            _ProjectionRead_T3ReEnableWait o = (_ProjectionRead_T3ReEnableWait) other;
            return this.T3_state.equals(o.T3_state);
        }

        public int hashCode() {
            return Objects.hash(T3_state);
        }
    }

    public static class _ProjectionRead__tr_T3ReEnableWait {

        public T3state T3_state;

        public _ProjectionRead__tr_T3ReEnableWait(T3state T3_state) {
            this.T3_state = T3_state;
        }

        public String toString() {
            return "{" + "T3_state: " + this.T3_state + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_T3ReEnableWait)) {
                return false;
            }
            _ProjectionRead__tr_T3ReEnableWait o = (_ProjectionRead__tr_T3ReEnableWait) other;
            return this.T3_state.equals(o.T3_state);
        }

        public int hashCode() {
            return Objects.hash(T3_state);
        }
    }

    public static class _ProjectionWrite_T3ReEnableWait {

        public BBoolean T3_evaluated;
        public T3state T3_state;
        public BBoolean T3_enabled;

        public _ProjectionWrite_T3ReEnableWait(BBoolean T3_evaluated, T3state T3_state, BBoolean T3_enabled) {
            this.T3_evaluated = T3_evaluated;
            this.T3_state = T3_state;
            this.T3_enabled = T3_enabled;
        }

        public String toString() {
            return "{" + "T3_evaluated: " + this.T3_evaluated + "," + "T3_state: " + this.T3_state + "," + "T3_enabled: " + this.T3_enabled + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_T3ReEnableWait)) {
                return false;
            }
            _ProjectionWrite_T3ReEnableWait o = (_ProjectionWrite_T3ReEnableWait) other;
            return this.T3_evaluated.equals(o.T3_evaluated) && this.T3_state.equals(o.T3_state) && this.T3_enabled.equals(o.T3_enabled);
        }

        public int hashCode() {
            return Objects.hash(T3_evaluated, T3_state, T3_enabled);
        }
    }

    public static class _ProjectionRead_Update {

        public BBoolean T3_evaluated;
        public BInteger T1_timer;
        public BBoolean T3_enabled;
        public BRelation<BInteger, BInteger> BUSwrite;
        public BInteger T2_timer;

        public _ProjectionRead_Update(BBoolean T3_evaluated, BInteger T1_timer, BBoolean T3_enabled, BRelation<BInteger, BInteger> BUSwrite, BInteger T2_timer) {
            this.T3_evaluated = T3_evaluated;
            this.T1_timer = T1_timer;
            this.T3_enabled = T3_enabled;
            this.BUSwrite = BUSwrite;
            this.T2_timer = T2_timer;
        }

        public String toString() {
            return "{" + "T3_evaluated: " + this.T3_evaluated + "," + "T1_timer: " + this.T1_timer + "," + "T3_enabled: " + this.T3_enabled + "," + "BUSwrite: " + this.BUSwrite + "," + "T2_timer: " + this.T2_timer + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_Update)) {
                return false;
            }
            _ProjectionRead_Update o = (_ProjectionRead_Update) other;
            return this.T3_evaluated.equals(o.T3_evaluated) && this.T1_timer.equals(o.T1_timer) && this.T3_enabled.equals(o.T3_enabled) && this.BUSwrite.equals(o.BUSwrite) && this.T2_timer.equals(o.T2_timer);
        }

        public int hashCode() {
            return Objects.hash(T3_evaluated, T1_timer, T3_enabled, BUSwrite, T2_timer);
        }
    }

    public static class _ProjectionRead__tr_Update {

        public BBoolean T3_evaluated;
        public BInteger T1_timer;
        public BBoolean T3_enabled;
        public BRelation<BInteger, BInteger> BUSwrite;
        public BInteger T2_timer;

        public _ProjectionRead__tr_Update(BBoolean T3_evaluated, BInteger T1_timer, BBoolean T3_enabled, BRelation<BInteger, BInteger> BUSwrite, BInteger T2_timer) {
            this.T3_evaluated = T3_evaluated;
            this.T1_timer = T1_timer;
            this.T3_enabled = T3_enabled;
            this.BUSwrite = BUSwrite;
            this.T2_timer = T2_timer;
        }

        public String toString() {
            return "{" + "T3_evaluated: " + this.T3_evaluated + "," + "T1_timer: " + this.T1_timer + "," + "T3_enabled: " + this.T3_enabled + "," + "BUSwrite: " + this.BUSwrite + "," + "T2_timer: " + this.T2_timer + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_Update)) {
                return false;
            }
            _ProjectionRead__tr_Update o = (_ProjectionRead__tr_Update) other;
            return this.T3_evaluated.equals(o.T3_evaluated) && this.T1_timer.equals(o.T1_timer) && this.T3_enabled.equals(o.T3_enabled) && this.BUSwrite.equals(o.BUSwrite) && this.T2_timer.equals(o.T2_timer);
        }

        public int hashCode() {
            return Objects.hash(T3_evaluated, T1_timer, T3_enabled, BUSwrite, T2_timer);
        }
    }

    public static class _ProjectionWrite_Update {

        public BBoolean T3_evaluated;
        public BInteger BUSpriority;
        public BInteger T1_timer;
        public BInteger T2_timer;
        public BInteger BUSvalue;

        public _ProjectionWrite_Update(BBoolean T3_evaluated, BInteger BUSpriority, BInteger T1_timer, BInteger T2_timer, BInteger BUSvalue) {
            this.T3_evaluated = T3_evaluated;
            this.BUSpriority = BUSpriority;
            this.T1_timer = T1_timer;
            this.T2_timer = T2_timer;
            this.BUSvalue = BUSvalue;
        }

        public String toString() {
            return "{" + "T3_evaluated: " + this.T3_evaluated + "," + "BUSpriority: " + this.BUSpriority + "," + "T1_timer: " + this.T1_timer + "," + "T2_timer: " + this.T2_timer + "," + "BUSvalue: " + this.BUSvalue + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_Update)) {
                return false;
            }
            _ProjectionWrite_Update o = (_ProjectionWrite_Update) other;
            return this.T3_evaluated.equals(o.T3_evaluated) && this.BUSpriority.equals(o.BUSpriority) && this.T1_timer.equals(o.T1_timer) && this.T2_timer.equals(o.T2_timer) && this.BUSvalue.equals(o.BUSvalue);
        }

        public int hashCode() {
            return Objects.hash(T3_evaluated, BUSpriority, T1_timer, T2_timer, BUSvalue);
        }
    }

    public static class _ProjectionRead__check_inv_1 {

        public BInteger T2v;

        public _ProjectionRead__check_inv_1(BInteger T2v) {
            this.T2v = T2v;
        }

        public String toString() {
            return "{" + "T2v: " + this.T2v + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_1)) {
                return false;
            }
            _ProjectionRead__check_inv_1 o = (_ProjectionRead__check_inv_1) other;
            return this.T2v.equals(o.T2v);
        }

        public int hashCode() {
            return Objects.hash(T2v);
        }
    }

    public static class _ProjectionRead__check_inv_2 {

        public BBoolean T3_evaluated;

        public _ProjectionRead__check_inv_2(BBoolean T3_evaluated) {
            this.T3_evaluated = T3_evaluated;
        }

        public String toString() {
            return "{" + "T3_evaluated: " + this.T3_evaluated + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_2)) {
                return false;
            }
            _ProjectionRead__check_inv_2 o = (_ProjectionRead__check_inv_2) other;
            return this.T3_evaluated.equals(o.T3_evaluated);
        }

        public int hashCode() {
            return Objects.hash(T3_evaluated);
        }
    }

    public static class _ProjectionRead__check_inv_3 {

        public BBoolean T3_enabled;

        public _ProjectionRead__check_inv_3(BBoolean T3_enabled) {
            this.T3_enabled = T3_enabled;
        }

        public String toString() {
            return "{" + "T3_enabled: " + this.T3_enabled + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_3)) {
                return false;
            }
            _ProjectionRead__check_inv_3 o = (_ProjectionRead__check_inv_3) other;
            return this.T3_enabled.equals(o.T3_enabled);
        }

        public int hashCode() {
            return Objects.hash(T3_enabled);
        }
    }

    public static class _ProjectionRead__check_inv_4 {

        public T1state T1_state;

        public _ProjectionRead__check_inv_4(T1state T1_state) {
            this.T1_state = T1_state;
        }

        public String toString() {
            return "{" + "T1_state: " + this.T1_state + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_4)) {
                return false;
            }
            _ProjectionRead__check_inv_4 o = (_ProjectionRead__check_inv_4) other;
            return this.T1_state.equals(o.T1_state);
        }

        public int hashCode() {
            return Objects.hash(T1_state);
        }
    }

    public static class _ProjectionRead__check_inv_5 {

        public T2state T2_state;

        public _ProjectionRead__check_inv_5(T2state T2_state) {
            this.T2_state = T2_state;
        }

        public String toString() {
            return "{" + "T2_state: " + this.T2_state + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_5)) {
                return false;
            }
            _ProjectionRead__check_inv_5 o = (_ProjectionRead__check_inv_5) other;
            return this.T2_state.equals(o.T2_state);
        }

        public int hashCode() {
            return Objects.hash(T2_state);
        }
    }

    public static class _ProjectionRead__check_inv_6 {

        public T3state T3_state;

        public _ProjectionRead__check_inv_6(T3state T3_state) {
            this.T3_state = T3_state;
        }

        public String toString() {
            return "{" + "T3_state: " + this.T3_state + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_6)) {
                return false;
            }
            _ProjectionRead__check_inv_6 o = (_ProjectionRead__check_inv_6) other;
            return this.T3_state.equals(o.T3_state);
        }

        public int hashCode() {
            return Objects.hash(T3_state);
        }
    }

    public static class _ProjectionRead__check_inv_7 {

        public BInteger T1_writevalue;

        public _ProjectionRead__check_inv_7(BInteger T1_writevalue) {
            this.T1_writevalue = T1_writevalue;
        }

        public String toString() {
            return "{" + "T1_writevalue: " + this.T1_writevalue + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_7)) {
                return false;
            }
            _ProjectionRead__check_inv_7 o = (_ProjectionRead__check_inv_7) other;
            return this.T1_writevalue.equals(o.T1_writevalue);
        }

        public int hashCode() {
            return Objects.hash(T1_writevalue);
        }
    }

    public static class _ProjectionRead__check_inv_8 {

        public BInteger T2_writevalue;

        public _ProjectionRead__check_inv_8(BInteger T2_writevalue) {
            this.T2_writevalue = T2_writevalue;
        }

        public String toString() {
            return "{" + "T2_writevalue: " + this.T2_writevalue + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_8)) {
                return false;
            }
            _ProjectionRead__check_inv_8 o = (_ProjectionRead__check_inv_8) other;
            return this.T2_writevalue.equals(o.T2_writevalue);
        }

        public int hashCode() {
            return Objects.hash(T2_writevalue);
        }
    }

    public static class _ProjectionRead__check_inv_9 {

        public BInteger T2_readvalue;

        public _ProjectionRead__check_inv_9(BInteger T2_readvalue) {
            this.T2_readvalue = T2_readvalue;
        }

        public String toString() {
            return "{" + "T2_readvalue: " + this.T2_readvalue + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_9)) {
                return false;
            }
            _ProjectionRead__check_inv_9 o = (_ProjectionRead__check_inv_9) other;
            return this.T2_readvalue.equals(o.T2_readvalue);
        }

        public int hashCode() {
            return Objects.hash(T2_readvalue);
        }
    }

    public static class _ProjectionRead__check_inv_10 {

        public BInteger T1_timer;

        public _ProjectionRead__check_inv_10(BInteger T1_timer) {
            this.T1_timer = T1_timer;
        }

        public String toString() {
            return "{" + "T1_timer: " + this.T1_timer + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_10)) {
                return false;
            }
            _ProjectionRead__check_inv_10 o = (_ProjectionRead__check_inv_10) other;
            return this.T1_timer.equals(o.T1_timer);
        }

        public int hashCode() {
            return Objects.hash(T1_timer);
        }
    }

    public static class _ProjectionRead__check_inv_11 {

        public BInteger T2_timer;

        public _ProjectionRead__check_inv_11(BInteger T2_timer) {
            this.T2_timer = T2_timer;
        }

        public String toString() {
            return "{" + "T2_timer: " + this.T2_timer + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_11)) {
                return false;
            }
            _ProjectionRead__check_inv_11 o = (_ProjectionRead__check_inv_11) other;
            return this.T2_timer.equals(o.T2_timer);
        }

        public int hashCode() {
            return Objects.hash(T2_timer);
        }
    }

    public static class _ProjectionRead__check_inv_12 {

        public T2mode T2_mode;

        public _ProjectionRead__check_inv_12(T2mode T2_mode) {
            this.T2_mode = T2_mode;
        }

        public String toString() {
            return "{" + "T2_mode: " + this.T2_mode + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_12)) {
                return false;
            }
            _ProjectionRead__check_inv_12 o = (_ProjectionRead__check_inv_12) other;
            return this.T2_mode.equals(o.T2_mode);
        }

        public int hashCode() {
            return Objects.hash(T2_mode);
        }
    }

    public static class _ProjectionRead__check_inv_13 {

        public BInteger BUSvalue;

        public _ProjectionRead__check_inv_13(BInteger BUSvalue) {
            this.BUSvalue = BUSvalue;
        }

        public String toString() {
            return "{" + "BUSvalue: " + this.BUSvalue + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_13)) {
                return false;
            }
            _ProjectionRead__check_inv_13 o = (_ProjectionRead__check_inv_13) other;
            return this.BUSvalue.equals(o.BUSvalue);
        }

        public int hashCode() {
            return Objects.hash(BUSvalue);
        }
    }

    public static class _ProjectionRead__check_inv_14 {

        public BInteger BUSpriority;

        public _ProjectionRead__check_inv_14(BInteger BUSpriority) {
            this.BUSpriority = BUSpriority;
        }

        public String toString() {
            return "{" + "BUSpriority: " + this.BUSpriority + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_14)) {
                return false;
            }
            _ProjectionRead__check_inv_14 o = (_ProjectionRead__check_inv_14) other;
            return this.BUSpriority.equals(o.BUSpriority);
        }

        public int hashCode() {
            return Objects.hash(BUSpriority);
        }
    }

    public static class _ProjectionRead__check_inv_15 {

        public BInteger T3_readvalue;

        public _ProjectionRead__check_inv_15(BInteger T3_readvalue) {
            this.T3_readvalue = T3_readvalue;
        }

        public String toString() {
            return "{" + "T3_readvalue: " + this.T3_readvalue + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_15)) {
                return false;
            }
            _ProjectionRead__check_inv_15 o = (_ProjectionRead__check_inv_15) other;
            return this.T3_readvalue.equals(o.T3_readvalue);
        }

        public int hashCode() {
            return Objects.hash(T3_readvalue);
        }
    }

    public static class _ProjectionRead__check_inv_16 {

        public BInteger T3_readpriority;

        public _ProjectionRead__check_inv_16(BInteger T3_readpriority) {
            this.T3_readpriority = T3_readpriority;
        }

        public String toString() {
            return "{" + "T3_readpriority: " + this.T3_readpriority + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_16)) {
                return false;
            }
            _ProjectionRead__check_inv_16 o = (_ProjectionRead__check_inv_16) other;
            return this.T3_readpriority.equals(o.T3_readpriority);
        }

        public int hashCode() {
            return Objects.hash(T3_readpriority);
        }
    }

    public static class _ProjectionRead__check_inv_17 {

        public BInteger T2_readpriority;

        public _ProjectionRead__check_inv_17(BInteger T2_readpriority) {
            this.T2_readpriority = T2_readpriority;
        }

        public String toString() {
            return "{" + "T2_readpriority: " + this.T2_readpriority + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_17)) {
                return false;
            }
            _ProjectionRead__check_inv_17 o = (_ProjectionRead__check_inv_17) other;
            return this.T2_readpriority.equals(o.T2_readpriority);
        }

        public int hashCode() {
            return Objects.hash(T2_readpriority);
        }
    }

    public static class _ProjectionRead__check_inv_18 {

        public BRelation<BInteger, BInteger> BUSwrite;

        public _ProjectionRead__check_inv_18(BRelation<BInteger, BInteger> BUSwrite) {
            this.BUSwrite = BUSwrite;
        }

        public String toString() {
            return "{" + "BUSwrite: " + this.BUSwrite + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_18)) {
                return false;
            }
            _ProjectionRead__check_inv_18 o = (_ProjectionRead__check_inv_18) other;
            return this.BUSwrite.equals(o.BUSwrite);
        }

        public int hashCode() {
            return Objects.hash(BUSwrite);
        }
    }

    public static class _ProjectionRead__check_inv_19 {

        public BRelation<BInteger, BInteger> BUSwrite;

        public _ProjectionRead__check_inv_19(BRelation<BInteger, BInteger> BUSwrite) {
            this.BUSwrite = BUSwrite;
        }

        public String toString() {
            return "{" + "BUSwrite: " + this.BUSwrite + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_19)) {
                return false;
            }
            _ProjectionRead__check_inv_19 o = (_ProjectionRead__check_inv_19) other;
            return this.BUSwrite.equals(o.BUSwrite);
        }

        public int hashCode() {
            return Objects.hash(BUSwrite);
        }
    }

    public static class _ProjectionRead__check_inv_20 {

        public BRelation<BInteger, BInteger> BUSwrite;

        public _ProjectionRead__check_inv_20(BRelation<BInteger, BInteger> BUSwrite) {
            this.BUSwrite = BUSwrite;
        }

        public String toString() {
            return "{" + "BUSwrite: " + this.BUSwrite + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_20)) {
                return false;
            }
            _ProjectionRead__check_inv_20 o = (_ProjectionRead__check_inv_20) other;
            return this.BUSwrite.equals(o.BUSwrite);
        }

        public int hashCode() {
            return Objects.hash(BUSwrite);
        }
    }




    private static BSet<BInteger> NATSET;
    private static BSet<BInteger> __aux_constant_1;


    public enum T1state implements BObject {
        T1_EN, 
        T1_CALC, 
        T1_SEND, 
        T1_WAIT;

        public BBoolean equal(T1state o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(T1state o) {
            return new BBoolean(this != o);
        }
    }

    public enum T2mode implements BObject {
        T2MODE_SENSE, 
        T2MODE_TRANSMIT, 
        T2MODE_RELEASE;

        public BBoolean equal(T2mode o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(T2mode o) {
            return new BBoolean(this != o);
        }
    }

    public enum T2state implements BObject {
        T2_EN, 
        T2_RCV, 
        T2_PROC, 
        T2_CALC, 
        T2_SEND, 
        T2_WAIT, 
        T2_RELEASE;

        public BBoolean equal(T2state o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(T2state o) {
            return new BBoolean(this != o);
        }
    }

    public enum T3state implements BObject {
        T3_READY, 
        T3_WRITE, 
        T3_RELEASE, 
        T3_READ, 
        T3_PROC, 
        T3_WAIT;

        public BBoolean equal(T3state o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(T3state o) {
            return new BBoolean(this != o);
        }
    }

    private static BSet<T1state> _T1state = new BSet<T1state>(T1state.T1_EN, T1state.T1_CALC, T1state.T1_SEND, T1state.T1_WAIT);
    private static BSet<T2mode> _T2mode = new BSet<T2mode>(T2mode.T2MODE_SENSE, T2mode.T2MODE_TRANSMIT, T2mode.T2MODE_RELEASE);
    private static BSet<T2state> _T2state = new BSet<T2state>(T2state.T2_EN, T2state.T2_RCV, T2state.T2_PROC, T2state.T2_CALC, T2state.T2_SEND, T2state.T2_WAIT, T2state.T2_RELEASE);
    private static BSet<T3state> _T3state = new BSet<T3state>(T3state.T3_READY, T3state.T3_WRITE, T3state.T3_RELEASE, T3state.T3_READ, T3state.T3_PROC, T3state.T3_WAIT);

    private BInteger BUSpriority;
    private BInteger BUSvalue;
    private BRelation<BInteger, BInteger> BUSwrite;
    private T1state T1_state;
    private BInteger T1_timer;
    private BInteger T1_writevalue;
    private T2mode T2_mode;
    private BInteger T2_readpriority;
    private BInteger T2_readvalue;
    private T2state T2_state;
    private BInteger T2_timer;
    private BInteger T2_writevalue;
    private BInteger T2v;
    private BBoolean T3_enabled;
    private BBoolean T3_evaluated;
    private BInteger T3_readpriority;
    private BInteger T3_readvalue;
    private T3state T3_state;

    static {
        NATSET = BSet.interval(new BInteger(0), new BInteger(5));
        __aux_constant_1 = BSet.interval(new BInteger(1).negative(), new BInteger(3));
    }

    public CAN_BUS_tlc() {
        T2v = new BInteger(0);
        T3_evaluated = new BBoolean(true);
        T3_enabled = new BBoolean(true);
        T1_state = T1state.T1_EN;
        T2_state = T2state.T2_EN;
        T3_state = T3state.T3_READY;
        T1_writevalue = new BInteger(0);
        T2_writevalue = new BInteger(0);
        T2_readvalue = new BInteger(0);
        T2_readpriority = new BInteger(0);
        T3_readvalue = new BInteger(0);
        T3_readpriority = new BInteger(0);
        T1_timer = new BInteger(2);
        T2_timer = new BInteger(3);
        BUSwrite = new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(new BInteger(0), new BInteger(0)));
        BUSvalue = new BInteger(0);
        BUSpriority = new BInteger(0);
        T2_mode = T2mode.T2MODE_SENSE;
    }

    public CAN_BUS_tlc(CAN_BUS_tlc copy) {
        this.NATSET = copy.NATSET;
        this.__aux_constant_1 = copy.__aux_constant_1;
        this.BUSpriority = copy.BUSpriority;
        this.BUSvalue = copy.BUSvalue;
        this.BUSwrite = copy.BUSwrite;
        this.T1_state = copy.T1_state;
        this.T1_timer = copy.T1_timer;
        this.T1_writevalue = copy.T1_writevalue;
        this.T2_mode = copy.T2_mode;
        this.T2_readpriority = copy.T2_readpriority;
        this.T2_readvalue = copy.T2_readvalue;
        this.T2_state = copy.T2_state;
        this.T2_timer = copy.T2_timer;
        this.T2_writevalue = copy.T2_writevalue;
        this.T2v = copy.T2v;
        this.T3_enabled = copy.T3_enabled;
        this.T3_evaluated = copy.T3_evaluated;
        this.T3_readpriority = copy.T3_readpriority;
        this.T3_readvalue = copy.T3_readvalue;
        this.T3_state = copy.T3_state;
    }

    public void T1Evaluate() {
        T1_timer = new BInteger(0);
        T1_state = T1state.T1_CALC;

    }

    public void T1Calculate(BInteger p) {
        T1_writevalue = p;
        T1_state = T1state.T1_SEND;

    }

    public void T1SendResult(BInteger ppriority, BInteger pv) {
        BRelation<BInteger, BInteger> _ld_BUSwrite = BUSwrite;
        BUSwrite = _ld_BUSwrite.override(new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(ppriority, pv)));
        T1_state = T1state.T1_WAIT;

    }

    public void T1Wait(BInteger pt) {
        T1_timer = pt;
        T1_state = T1state.T1_EN;

    }

    public void T2Evaluate() {
        T2_timer = new BInteger(0);
        T2_state = T2state.T2_RCV;

    }

    public void T2ReadBus(BInteger ppriority, BInteger pv) {
        T2_readvalue = pv;
        T2_readpriority = ppriority;
        T2_state = T2state.T2_PROC;

    }

    public void T2Reset() {
        BInteger _ld_T2v = T2v;
        T2_writevalue = _ld_T2v;
        T2v = new BInteger(0);
        T2_state = T2state.T2_SEND;
        T2_mode = T2mode.T2MODE_TRANSMIT;

    }

    public void T2Complete() {
        T2_state = T2state.T2_RELEASE;
        T2_mode = T2mode.T2MODE_SENSE;

    }

    public void T2ReleaseBus(BInteger ppriority) {
        BRelation<BInteger, BInteger> _ld_BUSwrite = BUSwrite;
        BUSwrite = _ld_BUSwrite.domainSubstraction(new BSet<BInteger>(ppriority));
        T2_state = T2state.T2_WAIT;

    }

    public void T2Calculate() {
        T2v = T2_readvalue;
        T2_state = T2state.T2_WAIT;

    }

    public void T2WriteBus(BInteger ppriority, BInteger pv) {
        BRelation<BInteger, BInteger> _ld_BUSwrite = BUSwrite;
        BUSwrite = _ld_BUSwrite.override(new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(ppriority, pv)));
        T2_state = T2state.T2_WAIT;

    }

    public void T2Wait(BInteger pt) {
        T2_timer = pt;
        T2_state = T2state.T2_EN;

    }

    public void T3Initiate() {
        T3_state = T3state.T3_WRITE;
        T3_enabled = new BBoolean(false);

    }

    public void T3Evaluate() {
        T3_state = T3state.T3_READ;

    }

    public void T3writebus(BInteger ppriority, BInteger pv) {
        BRelation<BInteger, BInteger> _ld_BUSwrite = BUSwrite;
        BUSwrite = _ld_BUSwrite.override(new BRelation<BInteger, BInteger>(new BTuple<BInteger, BInteger>(ppriority, pv)));
        T3_state = T3state.T3_WAIT;

    }

    public void T3Read(BInteger ppriority, BInteger pv) {
        T3_readvalue = pv;
        T3_readpriority = ppriority;
        T3_state = T3state.T3_PROC;

    }

    public void T3Poll() {
        T3_state = T3state.T3_WAIT;

    }

    public void T3ReleaseBus(BInteger ppriority) {
        BRelation<BInteger, BInteger> _ld_BUSwrite = BUSwrite;
        BUSwrite = _ld_BUSwrite.domainSubstraction(new BSet<BInteger>(ppriority));
        T3_state = T3state.T3_RELEASE;

    }

    public void T3Wait() {
        T3_state = T3state.T3_READY;
        T3_evaluated = new BBoolean(true);

    }

    public void T3ReEnableWait() {
        T3_state = T3state.T3_READY;
        T3_evaluated = new BBoolean(true);
        T3_enabled = new BBoolean(true);

    }

    public void Update(BInteger pmax) {
        BInteger _ld_T2_timer = T2_timer;
        BInteger _ld_T1_timer = T1_timer;
        BUSvalue = BUSwrite.functionCall(pmax);
        BUSpriority = pmax;
        T1_timer = _ld_T1_timer.minus(new BInteger(1));
        T2_timer = _ld_T2_timer.minus(new BInteger(1));
        T3_evaluated = new BBoolean(false);

    }

    public BSet<BInteger> _get_NATSET() {
        return NATSET;
    }

    public BSet<BInteger> _get___aux_constant_1() {
        return __aux_constant_1;
    }

    public BInteger _get_BUSpriority() {
        return BUSpriority;
    }

    public BInteger _get_BUSvalue() {
        return BUSvalue;
    }

    public BRelation<BInteger, BInteger> _get_BUSwrite() {
        return BUSwrite;
    }

    public T1state _get_T1_state() {
        return T1_state;
    }

    public BInteger _get_T1_timer() {
        return T1_timer;
    }

    public BInteger _get_T1_writevalue() {
        return T1_writevalue;
    }

    public T2mode _get_T2_mode() {
        return T2_mode;
    }

    public BInteger _get_T2_readpriority() {
        return T2_readpriority;
    }

    public BInteger _get_T2_readvalue() {
        return T2_readvalue;
    }

    public T2state _get_T2_state() {
        return T2_state;
    }

    public BInteger _get_T2_timer() {
        return T2_timer;
    }

    public BInteger _get_T2_writevalue() {
        return T2_writevalue;
    }

    public BInteger _get_T2v() {
        return T2v;
    }

    public BBoolean _get_T3_enabled() {
        return T3_enabled;
    }

    public BBoolean _get_T3_evaluated() {
        return T3_evaluated;
    }

    public BInteger _get_T3_readpriority() {
        return T3_readpriority;
    }

    public BInteger _get_T3_readvalue() {
        return T3_readvalue;
    }

    public T3state _get_T3_state() {
        return T3_state;
    }

    public BSet<T1state> _get__T1state() {
        return _T1state;
    }

    public BSet<T2mode> _get__T2mode() {
        return _T2mode;
    }

    public BSet<T2state> _get__T2state() {
        return _T2state;
    }

    public BSet<T3state> _get__T3state() {
        return _T3state;
    }

    @Override
    public boolean equals(Object o) {
        CAN_BUS_tlc o1 = this;
        CAN_BUS_tlc o2 = (CAN_BUS_tlc) o;
        return o1._get_BUSpriority().equals(o2._get_BUSpriority()) && o1._get_BUSvalue().equals(o2._get_BUSvalue()) && o1._get_BUSwrite().equals(o2._get_BUSwrite()) && o1._get_T1_state().equals(o2._get_T1_state()) && o1._get_T1_timer().equals(o2._get_T1_timer()) && o1._get_T1_writevalue().equals(o2._get_T1_writevalue()) && o1._get_T2_mode().equals(o2._get_T2_mode()) && o1._get_T2_readpriority().equals(o2._get_T2_readpriority()) && o1._get_T2_readvalue().equals(o2._get_T2_readvalue()) && o1._get_T2_state().equals(o2._get_T2_state()) && o1._get_T2_timer().equals(o2._get_T2_timer()) && o1._get_T2_writevalue().equals(o2._get_T2_writevalue()) && o1._get_T2v().equals(o2._get_T2v()) && o1._get_T3_enabled().equals(o2._get_T3_enabled()) && o1._get_T3_evaluated().equals(o2._get_T3_evaluated()) && o1._get_T3_readpriority().equals(o2._get_T3_readpriority()) && o1._get_T3_readvalue().equals(o2._get_T3_readvalue()) && o1._get_T3_state().equals(o2._get_T3_state());
    }



    @Override
    public int hashCode() {
        return this._hashCode_1();
    }

    public int _hashCode_1() {
        int result = 1;
        result = (1543 * result) ^ ((this._get_BUSpriority()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_BUSvalue()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_BUSwrite()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T1_state()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T1_timer()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T1_writevalue()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T2_mode()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T2_readpriority()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T2_readvalue()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T2_state()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T2_timer()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T2_writevalue()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T2v()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T3_enabled()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T3_evaluated()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T3_readpriority()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T3_readvalue()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T3_state()).hashCode() << 1);
        return result;
    }

    public int _hashCode_2() {
        int result = 1;
        result = (6151 * result) ^ ((this._get_BUSpriority()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_BUSvalue()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_BUSwrite()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T1_state()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T1_timer()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T1_writevalue()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T2_mode()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T2_readpriority()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T2_readvalue()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T2_state()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T2_timer()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T2_writevalue()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T2v()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T3_enabled()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T3_evaluated()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T3_readpriority()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T3_readvalue()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T3_state()).hashCode() << 1);
        return result;
    }

    @Override
    public String toString() {
        return String.join("\n", "_get_BUSpriority: " + (this._get_BUSpriority()).toString(), "_get_BUSvalue: " + (this._get_BUSvalue()).toString(), "_get_BUSwrite: " + (this._get_BUSwrite()).toString(), "_get_T1_state: " + (this._get_T1_state()).toString(), "_get_T1_timer: " + (this._get_T1_timer()).toString(), "_get_T1_writevalue: " + (this._get_T1_writevalue()).toString(), "_get_T2_mode: " + (this._get_T2_mode()).toString(), "_get_T2_readpriority: " + (this._get_T2_readpriority()).toString(), "_get_T2_readvalue: " + (this._get_T2_readvalue()).toString(), "_get_T2_state: " + (this._get_T2_state()).toString(), "_get_T2_timer: " + (this._get_T2_timer()).toString(), "_get_T2_writevalue: " + (this._get_T2_writevalue()).toString(), "_get_T2v: " + (this._get_T2v()).toString(), "_get_T3_enabled: " + (this._get_T3_enabled()).toString(), "_get_T3_evaluated: " + (this._get_T3_evaluated()).toString(), "_get_T3_readpriority: " + (this._get_T3_readpriority()).toString(), "_get_T3_readvalue: " + (this._get_T3_readvalue()).toString(), "_get_T3_state: " + (this._get_T3_state()).toString());
    }

    public CAN_BUS_tlc _copy() {
        return new CAN_BUS_tlc(this);
    }


    public boolean _tr_T1Evaluate() {
        return new BBoolean(T1_timer.equal(new BInteger(0)).booleanValue() && T1_state.equal(T1state.T1_EN).booleanValue()).booleanValue();
    }

    public BSet<BInteger> _tr_T1Calculate() {
        BSet<BInteger> _ic_set_1 = new BSet<BInteger>();
        for(BInteger _ic_p_1 : __aux_constant_1) {
            if((T1_state.equal(T1state.T1_CALC)).booleanValue()) {
                _ic_set_1 = _ic_set_1.union(new BSet<BInteger>(_ic_p_1));
            }

        }

        return _ic_set_1;
    }

    public BSet<BTuple<BInteger, BInteger>> _tr_T1SendResult() {
        BSet<BTuple<BInteger, BInteger>> _ic_set_2 = new BSet<BTuple<BInteger, BInteger>>();
        for(BInteger _ic_ppriority_1 : Arrays.asList(new BInteger(3))) {
            for(BInteger _ic_pv_1 : Arrays.asList(T1_writevalue)) {
                if((T1_state.equal(T1state.T1_SEND)).booleanValue()) {
                    _ic_set_2 = _ic_set_2.union(new BSet<BTuple<BInteger, BInteger>>(new BTuple<BInteger, BInteger>(_ic_ppriority_1, _ic_pv_1)));
                }

            }

        }

        return _ic_set_2;
    }

    public BSet<BInteger> _tr_T1Wait() {
        BSet<BInteger> _ic_set_3 = new BSet<BInteger>();
        for(BInteger _ic_pt_1 : Arrays.asList(new BInteger(2))) {
            if((T1_state.equal(T1state.T1_WAIT)).booleanValue()) {
                _ic_set_3 = _ic_set_3.union(new BSet<BInteger>(_ic_pt_1));
            }

        }

        return _ic_set_3;
    }

    public boolean _tr_T2Evaluate() {
        return new BBoolean(T2_timer.equal(new BInteger(0)).booleanValue() && T2_state.equal(T2state.T2_EN).booleanValue()).booleanValue();
    }

    public BSet<BTuple<BInteger, BInteger>> _tr_T2ReadBus() {
        BSet<BTuple<BInteger, BInteger>> _ic_set_5 = new BSet<BTuple<BInteger, BInteger>>();
        for(BInteger _ic_ppriority_1 : Arrays.asList(BUSpriority)) {
            for(BInteger _ic_pv_1 : Arrays.asList(BUSvalue)) {
                if((T2_state.equal(T2state.T2_RCV)).booleanValue()) {
                    _ic_set_5 = _ic_set_5.union(new BSet<BTuple<BInteger, BInteger>>(new BTuple<BInteger, BInteger>(_ic_ppriority_1, _ic_pv_1)));
                }

            }

        }

        return _ic_set_5;
    }

    public boolean _tr_T2Reset() {
        return new BBoolean(T2_readpriority.equal(new BInteger(4)).booleanValue() && T2_state.equal(T2state.T2_PROC).booleanValue()).booleanValue();
    }

    public boolean _tr_T2Complete() {
        return new BBoolean(new BBoolean(T2_state.equal(T2state.T2_PROC).booleanValue() && T2_readpriority.equal(new BInteger(5)).booleanValue()).booleanValue() && T2_mode.equal(T2mode.T2MODE_TRANSMIT).booleanValue()).booleanValue();
    }

    public BSet<BInteger> _tr_T2ReleaseBus() {
        BSet<BInteger> _ic_set_8 = new BSet<BInteger>();
        for(BInteger _ic_ppriority_1 : Arrays.asList(T2_readpriority)) {
            if((new BBoolean(BUSwrite.isInDomain(_ic_ppriority_1).booleanValue() && T2_state.equal(T2state.T2_RELEASE).booleanValue())).booleanValue()) {
                _ic_set_8 = _ic_set_8.union(new BSet<BInteger>(_ic_ppriority_1));
            }

        }

        return _ic_set_8;
    }

    public boolean _tr_T2Calculate() {
        return new BBoolean(T2_readpriority.equal(new BInteger(3)).booleanValue() && T2_state.equal(T2state.T2_PROC).booleanValue()).booleanValue();
    }

    public BSet<BTuple<BInteger, BInteger>> _tr_T2WriteBus() {
        BSet<BTuple<BInteger, BInteger>> _ic_set_10 = new BSet<BTuple<BInteger, BInteger>>();
        for(BInteger _ic_ppriority_1 : Arrays.asList(new BInteger(5))) {
            for(BInteger _ic_pv_1 : Arrays.asList(T2_writevalue)) {
                if((T2_state.equal(T2state.T2_SEND)).booleanValue()) {
                    _ic_set_10 = _ic_set_10.union(new BSet<BTuple<BInteger, BInteger>>(new BTuple<BInteger, BInteger>(_ic_ppriority_1, _ic_pv_1)));
                }

            }

        }

        return _ic_set_10;
    }

    public BSet<BInteger> _tr_T2Wait() {
        BSet<BInteger> _ic_set_11 = new BSet<BInteger>();
        for(BInteger _ic_pt_1 : Arrays.asList(new BInteger(3))) {
            if((T2_state.equal(T2state.T2_WAIT)).booleanValue()) {
                _ic_set_11 = _ic_set_11.union(new BSet<BInteger>(_ic_pt_1));
            }

        }

        return _ic_set_11;
    }

    public boolean _tr_T3Initiate() {
        return new BBoolean(new BBoolean(T3_state.equal(T3state.T3_READY).booleanValue() && T3_evaluated.equal(new BBoolean(false)).booleanValue()).booleanValue() && T3_enabled.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public boolean _tr_T3Evaluate() {
        return new BBoolean(new BBoolean(T3_state.equal(T3state.T3_READY).booleanValue() && T3_evaluated.equal(new BBoolean(false)).booleanValue()).booleanValue() && T3_enabled.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public BSet<BTuple<BInteger, BInteger>> _tr_T3writebus() {
        BSet<BTuple<BInteger, BInteger>> _ic_set_14 = new BSet<BTuple<BInteger, BInteger>>();
        for(BInteger _ic_ppriority_1 : Arrays.asList(new BInteger(4))) {
            for(BInteger _ic_pv_1 : Arrays.asList(new BInteger(0))) {
                if((T3_state.equal(T3state.T3_WRITE)).booleanValue()) {
                    _ic_set_14 = _ic_set_14.union(new BSet<BTuple<BInteger, BInteger>>(new BTuple<BInteger, BInteger>(_ic_ppriority_1, _ic_pv_1)));
                }

            }

        }

        return _ic_set_14;
    }

    public BSet<BTuple<BInteger, BInteger>> _tr_T3Read() {
        BSet<BTuple<BInteger, BInteger>> _ic_set_15 = new BSet<BTuple<BInteger, BInteger>>();
        for(BInteger _ic_ppriority_1 : Arrays.asList(BUSpriority)) {
            for(BInteger _ic_pv_1 : Arrays.asList(BUSvalue)) {
                if((T3_state.equal(T3state.T3_READ)).booleanValue()) {
                    _ic_set_15 = _ic_set_15.union(new BSet<BTuple<BInteger, BInteger>>(new BTuple<BInteger, BInteger>(_ic_ppriority_1, _ic_pv_1)));
                }

            }

        }

        return _ic_set_15;
    }

    public boolean _tr_T3Poll() {
        return new BBoolean(T3_readpriority.less(new BInteger(5)).booleanValue() && T3_state.equal(T3state.T3_PROC).booleanValue()).booleanValue();
    }

    public BSet<BInteger> _tr_T3ReleaseBus() {
        BSet<BInteger> _ic_set_17 = new BSet<BInteger>();
        for(BInteger _ic_ppriority_1 : Arrays.asList(new BInteger(4))) {
            if((new BBoolean(T3_readpriority.equal(new BInteger(5)).booleanValue() && T3_state.equal(T3state.T3_PROC).booleanValue())).booleanValue()) {
                _ic_set_17 = _ic_set_17.union(new BSet<BInteger>(_ic_ppriority_1));
            }

        }

        return _ic_set_17;
    }

    public boolean _tr_T3Wait() {
        return T3_state.equal(T3state.T3_WAIT).booleanValue();
    }

    public boolean _tr_T3ReEnableWait() {
        return T3_state.equal(T3state.T3_RELEASE).booleanValue();
    }

    public BSet<BInteger> _tr_Update() {
        BSet<BInteger> _ic_set_20 = new BSet<BInteger>();
        for(BInteger _ic_pmax_1 : Arrays.asList(BUSwrite.domain().max())) {
            if((new BBoolean(new BBoolean(T1_timer.greater(new BInteger(0)).booleanValue() && T2_timer.greater(new BInteger(0)).booleanValue()).booleanValue() && new BBoolean(T3_enabled.equal(new BBoolean(true)).booleanValue() || T3_evaluated.equal(new BBoolean(true)).booleanValue()).booleanValue())).booleanValue()) {
                _ic_set_20 = _ic_set_20.union(new BSet<BInteger>(_ic_pmax_1));
            }

        }

        return _ic_set_20;
    }

    public _ProjectionRead_T1Wait _projected_state_for_T1Wait() {
        return new _ProjectionRead_T1Wait(T1_state);
    }

    public _ProjectionRead_T1Calculate _projected_state_for_T1Calculate() {
        return new _ProjectionRead_T1Calculate(T1_state);
    }

    public _ProjectionRead_T1SendResult _projected_state_for_T1SendResult() {
        return new _ProjectionRead_T1SendResult(T1_state,T1_writevalue,BUSwrite);
    }

    public _ProjectionRead_T2ReadBus _projected_state_for_T2ReadBus() {
        return new _ProjectionRead_T2ReadBus(T2_state,BUSpriority,BUSvalue);
    }

    public _ProjectionRead_T2Reset _projected_state_for_T2Reset() {
        return new _ProjectionRead_T2Reset(T2_state,T2_readpriority,T2v);
    }

    public _ProjectionRead_T2Complete _projected_state_for_T2Complete() {
        return new _ProjectionRead_T2Complete(T2_state,T2_readpriority,T2_mode);
    }

    public _ProjectionRead_T2Evaluate _projected_state_for_T2Evaluate() {
        return new _ProjectionRead_T2Evaluate(T2_state,T2_timer);
    }

    public _ProjectionRead_T3Evaluate _projected_state_for_T3Evaluate() {
        return new _ProjectionRead_T3Evaluate(T3_evaluated,T3_state,T3_enabled);
    }

    public _ProjectionRead_T3ReleaseBus _projected_state_for_T3ReleaseBus() {
        return new _ProjectionRead_T3ReleaseBus(T3_readpriority,T3_state,BUSwrite);
    }

    public _ProjectionRead_T1Evaluate _projected_state_for_T1Evaluate() {
        return new _ProjectionRead_T1Evaluate(T1_state,T1_timer);
    }

    public _ProjectionRead_T3Initiate _projected_state_for_T3Initiate() {
        return new _ProjectionRead_T3Initiate(T3_evaluated,T3_state,T3_enabled);
    }

    public _ProjectionRead_T3ReEnableWait _projected_state_for_T3ReEnableWait() {
        return new _ProjectionRead_T3ReEnableWait(T3_state);
    }

    public _ProjectionRead_T3writebus _projected_state_for_T3writebus() {
        return new _ProjectionRead_T3writebus(T3_state,BUSwrite);
    }

    public _ProjectionRead_Update _projected_state_for_Update() {
        return new _ProjectionRead_Update(T3_evaluated,T1_timer,T3_enabled,BUSwrite,T2_timer);
    }

    public _ProjectionRead_T2ReleaseBus _projected_state_for_T2ReleaseBus() {
        return new _ProjectionRead_T2ReleaseBus(T2_state,T2_readpriority,BUSwrite);
    }

    public _ProjectionRead_T2Wait _projected_state_for_T2Wait() {
        return new _ProjectionRead_T2Wait(T2_state);
    }

    public _ProjectionRead_T3Poll _projected_state_for_T3Poll() {
        return new _ProjectionRead_T3Poll(T3_readpriority,T3_state);
    }

    public _ProjectionRead_T2Calculate _projected_state_for_T2Calculate() {
        return new _ProjectionRead_T2Calculate(T2_state,T2_readpriority,T2_readvalue);
    }

    public _ProjectionRead_T3Read _projected_state_for_T3Read() {
        return new _ProjectionRead_T3Read(BUSpriority,T3_state,BUSvalue);
    }

    public _ProjectionRead_T3Wait _projected_state_for_T3Wait() {
        return new _ProjectionRead_T3Wait(T3_state);
    }

    public _ProjectionRead_T2WriteBus _projected_state_for_T2WriteBus() {
        return new _ProjectionRead_T2WriteBus(T2_state,T2_writevalue,BUSwrite);
    }

    public _ProjectionRead__tr_T1Evaluate _projected_state_for__tr_T1Evaluate() {
        return new _ProjectionRead__tr_T1Evaluate(T1_state,T1_timer);
    }

    public _ProjectionRead__tr_T2Complete _projected_state_for__tr_T2Complete() {
        return new _ProjectionRead__tr_T2Complete(T2_state,T2_readpriority,T2_mode);
    }

    public _ProjectionRead__tr_T2Calculate _projected_state_for__tr_T2Calculate() {
        return new _ProjectionRead__tr_T2Calculate(T2_state,T2_readpriority);
    }

    public _ProjectionRead__tr_T2Evaluate _projected_state_for__tr_T2Evaluate() {
        return new _ProjectionRead__tr_T2Evaluate(T2_state,T2_timer);
    }

    public _ProjectionRead__tr_T3Poll _projected_state_for__tr_T3Poll() {
        return new _ProjectionRead__tr_T3Poll(T3_readpriority,T3_state);
    }

    public _ProjectionRead__tr_T3ReEnableWait _projected_state_for__tr_T3ReEnableWait() {
        return new _ProjectionRead__tr_T3ReEnableWait(T3_state);
    }

    public _ProjectionRead__tr_T2ReadBus _projected_state_for__tr_T2ReadBus() {
        return new _ProjectionRead__tr_T2ReadBus(T2_state,BUSpriority,BUSvalue);
    }

    public _ProjectionRead__tr_T2WriteBus _projected_state_for__tr_T2WriteBus() {
        return new _ProjectionRead__tr_T2WriteBus(T2_state,T2_writevalue);
    }

    public _ProjectionRead__tr_T2Wait _projected_state_for__tr_T2Wait() {
        return new _ProjectionRead__tr_T2Wait(T2_state);
    }

    public _ProjectionRead__tr_T2Reset _projected_state_for__tr_T2Reset() {
        return new _ProjectionRead__tr_T2Reset(T2_state,T2_readpriority);
    }

    public _ProjectionRead__tr_T2ReleaseBus _projected_state_for__tr_T2ReleaseBus() {
        return new _ProjectionRead__tr_T2ReleaseBus(T2_state,T2_readpriority,BUSwrite);
    }

    public _ProjectionRead__tr_T3writebus _projected_state_for__tr_T3writebus() {
        return new _ProjectionRead__tr_T3writebus(T3_state);
    }

    public _ProjectionRead__tr_T3Read _projected_state_for__tr_T3Read() {
        return new _ProjectionRead__tr_T3Read(BUSpriority,T3_state,BUSvalue);
    }

    public _ProjectionRead__tr_T3ReleaseBus _projected_state_for__tr_T3ReleaseBus() {
        return new _ProjectionRead__tr_T3ReleaseBus(T3_readpriority,T3_state);
    }

    public _ProjectionRead__tr_Update _projected_state_for__tr_Update() {
        return new _ProjectionRead__tr_Update(T3_evaluated,T1_timer,T3_enabled,BUSwrite,T2_timer);
    }

    public _ProjectionRead__tr_T1SendResult _projected_state_for__tr_T1SendResult() {
        return new _ProjectionRead__tr_T1SendResult(T1_state,T1_writevalue);
    }

    public _ProjectionRead__tr_T3Evaluate _projected_state_for__tr_T3Evaluate() {
        return new _ProjectionRead__tr_T3Evaluate(T3_evaluated,T3_state,T3_enabled);
    }

    public _ProjectionRead__tr_T1Calculate _projected_state_for__tr_T1Calculate() {
        return new _ProjectionRead__tr_T1Calculate(T1_state);
    }

    public _ProjectionRead__tr_T3Wait _projected_state_for__tr_T3Wait() {
        return new _ProjectionRead__tr_T3Wait(T3_state);
    }

    public _ProjectionRead__tr_T1Wait _projected_state_for__tr_T1Wait() {
        return new _ProjectionRead__tr_T1Wait(T1_state);
    }

    public _ProjectionRead__tr_T3Initiate _projected_state_for__tr_T3Initiate() {
        return new _ProjectionRead__tr_T3Initiate(T3_evaluated,T3_state,T3_enabled);
    }

    public _ProjectionRead__check_inv_18 _projected_state_for__check_inv_18() {
        return new _ProjectionRead__check_inv_18(BUSwrite);
    }

    public _ProjectionRead__check_inv_17 _projected_state_for__check_inv_17() {
        return new _ProjectionRead__check_inv_17(T2_readpriority);
    }

    public _ProjectionRead__check_inv_16 _projected_state_for__check_inv_16() {
        return new _ProjectionRead__check_inv_16(T3_readpriority);
    }

    public _ProjectionRead__check_inv_15 _projected_state_for__check_inv_15() {
        return new _ProjectionRead__check_inv_15(T3_readvalue);
    }

    public _ProjectionRead__check_inv_19 _projected_state_for__check_inv_19() {
        return new _ProjectionRead__check_inv_19(BUSwrite);
    }

    public _ProjectionRead__check_inv_6 _projected_state_for__check_inv_6() {
        return new _ProjectionRead__check_inv_6(T3_state);
    }

    public _ProjectionRead__check_inv_10 _projected_state_for__check_inv_10() {
        return new _ProjectionRead__check_inv_10(T1_timer);
    }

    public _ProjectionRead__check_inv_7 _projected_state_for__check_inv_7() {
        return new _ProjectionRead__check_inv_7(T1_writevalue);
    }

    public _ProjectionRead__check_inv_20 _projected_state_for__check_inv_20() {
        return new _ProjectionRead__check_inv_20(BUSwrite);
    }

    public _ProjectionRead__check_inv_4 _projected_state_for__check_inv_4() {
        return new _ProjectionRead__check_inv_4(T1_state);
    }

    public _ProjectionRead__check_inv_5 _projected_state_for__check_inv_5() {
        return new _ProjectionRead__check_inv_5(T2_state);
    }

    public _ProjectionRead__check_inv_14 _projected_state_for__check_inv_14() {
        return new _ProjectionRead__check_inv_14(BUSpriority);
    }

    public _ProjectionRead__check_inv_13 _projected_state_for__check_inv_13() {
        return new _ProjectionRead__check_inv_13(BUSvalue);
    }

    public _ProjectionRead__check_inv_8 _projected_state_for__check_inv_8() {
        return new _ProjectionRead__check_inv_8(T2_writevalue);
    }

    public _ProjectionRead__check_inv_12 _projected_state_for__check_inv_12() {
        return new _ProjectionRead__check_inv_12(T2_mode);
    }

    public _ProjectionRead__check_inv_9 _projected_state_for__check_inv_9() {
        return new _ProjectionRead__check_inv_9(T2_readvalue);
    }

    public _ProjectionRead__check_inv_11 _projected_state_for__check_inv_11() {
        return new _ProjectionRead__check_inv_11(T2_timer);
    }

    public _ProjectionRead__check_inv_2 _projected_state_for__check_inv_2() {
        return new _ProjectionRead__check_inv_2(T3_evaluated);
    }

    public _ProjectionRead__check_inv_3 _projected_state_for__check_inv_3() {
        return new _ProjectionRead__check_inv_3(T3_enabled);
    }

    public _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() {
        return new _ProjectionRead__check_inv_1(T2v);
    }

    public _ProjectionWrite_T1Wait _update_for_T1Wait() {
        return new _ProjectionWrite_T1Wait(T1_state,T1_timer);
    }

    public _ProjectionWrite_T1Calculate _update_for_T1Calculate() {
        return new _ProjectionWrite_T1Calculate(T1_state,T1_writevalue);
    }

    public _ProjectionWrite_T1SendResult _update_for_T1SendResult() {
        return new _ProjectionWrite_T1SendResult(T1_state,BUSwrite);
    }

    public _ProjectionWrite_T2ReadBus _update_for_T2ReadBus() {
        return new _ProjectionWrite_T2ReadBus(T2_state,T2_readpriority,T2_readvalue);
    }

    public _ProjectionWrite_T2Reset _update_for_T2Reset() {
        return new _ProjectionWrite_T2Reset(T2_state,T2_writevalue,T2v,T2_mode);
    }

    public _ProjectionWrite_T2Complete _update_for_T2Complete() {
        return new _ProjectionWrite_T2Complete(T2_state,T2_mode);
    }

    public _ProjectionWrite_T2Evaluate _update_for_T2Evaluate() {
        return new _ProjectionWrite_T2Evaluate(T2_state,T2_timer);
    }

    public _ProjectionWrite_T3Evaluate _update_for_T3Evaluate() {
        return new _ProjectionWrite_T3Evaluate(T3_state);
    }

    public _ProjectionWrite_T3ReleaseBus _update_for_T3ReleaseBus() {
        return new _ProjectionWrite_T3ReleaseBus(T3_state,BUSwrite);
    }

    public _ProjectionWrite_T1Evaluate _update_for_T1Evaluate() {
        return new _ProjectionWrite_T1Evaluate(T1_state,T1_timer);
    }

    public _ProjectionWrite_T3Initiate _update_for_T3Initiate() {
        return new _ProjectionWrite_T3Initiate(T3_state,T3_enabled);
    }

    public _ProjectionWrite_T3ReEnableWait _update_for_T3ReEnableWait() {
        return new _ProjectionWrite_T3ReEnableWait(T3_evaluated,T3_state,T3_enabled);
    }

    public _ProjectionWrite_T3writebus _update_for_T3writebus() {
        return new _ProjectionWrite_T3writebus(T3_state,BUSwrite);
    }

    public _ProjectionWrite_Update _update_for_Update() {
        return new _ProjectionWrite_Update(T3_evaluated,BUSpriority,T1_timer,T2_timer,BUSvalue);
    }

    public _ProjectionWrite_T2ReleaseBus _update_for_T2ReleaseBus() {
        return new _ProjectionWrite_T2ReleaseBus(T2_state,BUSwrite);
    }

    public _ProjectionWrite_T2Wait _update_for_T2Wait() {
        return new _ProjectionWrite_T2Wait(T2_state,T2_timer);
    }

    public _ProjectionWrite_T3Poll _update_for_T3Poll() {
        return new _ProjectionWrite_T3Poll(T3_state);
    }

    public _ProjectionWrite_T2Calculate _update_for_T2Calculate() {
        return new _ProjectionWrite_T2Calculate(T2_state,T2v);
    }

    public _ProjectionWrite_T3Read _update_for_T3Read() {
        return new _ProjectionWrite_T3Read(T3_readpriority,T3_readvalue,T3_state);
    }

    public _ProjectionWrite_T3Wait _update_for_T3Wait() {
        return new _ProjectionWrite_T3Wait(T3_evaluated,T3_state);
    }

    public _ProjectionWrite_T2WriteBus _update_for_T2WriteBus() {
        return new _ProjectionWrite_T2WriteBus(T2_state,BUSwrite);
    }

    public void _apply_update_for_T1Wait(_ProjectionWrite_T1Wait update) {
        this.T1_state = update.T1_state;
        this.T1_timer = update.T1_timer;
    }

    public void _apply_update_for_T1Calculate(_ProjectionWrite_T1Calculate update) {
        this.T1_state = update.T1_state;
        this.T1_writevalue = update.T1_writevalue;
    }

    public void _apply_update_for_T1SendResult(_ProjectionWrite_T1SendResult update) {
        this.T1_state = update.T1_state;
        this.BUSwrite = update.BUSwrite;
    }

    public void _apply_update_for_T2ReadBus(_ProjectionWrite_T2ReadBus update) {
        this.T2_state = update.T2_state;
        this.T2_readpriority = update.T2_readpriority;
        this.T2_readvalue = update.T2_readvalue;
    }

    public void _apply_update_for_T2Reset(_ProjectionWrite_T2Reset update) {
        this.T2_state = update.T2_state;
        this.T2_writevalue = update.T2_writevalue;
        this.T2v = update.T2v;
        this.T2_mode = update.T2_mode;
    }

    public void _apply_update_for_T2Complete(_ProjectionWrite_T2Complete update) {
        this.T2_state = update.T2_state;
        this.T2_mode = update.T2_mode;
    }

    public void _apply_update_for_T2Evaluate(_ProjectionWrite_T2Evaluate update) {
        this.T2_state = update.T2_state;
        this.T2_timer = update.T2_timer;
    }

    public void _apply_update_for_T3Evaluate(_ProjectionWrite_T3Evaluate update) {
        this.T3_state = update.T3_state;
    }

    public void _apply_update_for_T3ReleaseBus(_ProjectionWrite_T3ReleaseBus update) {
        this.T3_state = update.T3_state;
        this.BUSwrite = update.BUSwrite;
    }

    public void _apply_update_for_T1Evaluate(_ProjectionWrite_T1Evaluate update) {
        this.T1_state = update.T1_state;
        this.T1_timer = update.T1_timer;
    }

    public void _apply_update_for_T3Initiate(_ProjectionWrite_T3Initiate update) {
        this.T3_state = update.T3_state;
        this.T3_enabled = update.T3_enabled;
    }

    public void _apply_update_for_T3ReEnableWait(_ProjectionWrite_T3ReEnableWait update) {
        this.T3_evaluated = update.T3_evaluated;
        this.T3_state = update.T3_state;
        this.T3_enabled = update.T3_enabled;
    }

    public void _apply_update_for_T3writebus(_ProjectionWrite_T3writebus update) {
        this.T3_state = update.T3_state;
        this.BUSwrite = update.BUSwrite;
    }

    public void _apply_update_for_Update(_ProjectionWrite_Update update) {
        this.T3_evaluated = update.T3_evaluated;
        this.BUSpriority = update.BUSpriority;
        this.T1_timer = update.T1_timer;
        this.T2_timer = update.T2_timer;
        this.BUSvalue = update.BUSvalue;
    }

    public void _apply_update_for_T2ReleaseBus(_ProjectionWrite_T2ReleaseBus update) {
        this.T2_state = update.T2_state;
        this.BUSwrite = update.BUSwrite;
    }

    public void _apply_update_for_T2Wait(_ProjectionWrite_T2Wait update) {
        this.T2_state = update.T2_state;
        this.T2_timer = update.T2_timer;
    }

    public void _apply_update_for_T3Poll(_ProjectionWrite_T3Poll update) {
        this.T3_state = update.T3_state;
    }

    public void _apply_update_for_T2Calculate(_ProjectionWrite_T2Calculate update) {
        this.T2_state = update.T2_state;
        this.T2v = update.T2v;
    }

    public void _apply_update_for_T3Read(_ProjectionWrite_T3Read update) {
        this.T3_readpriority = update.T3_readpriority;
        this.T3_readvalue = update.T3_readvalue;
        this.T3_state = update.T3_state;
    }

    public void _apply_update_for_T3Wait(_ProjectionWrite_T3Wait update) {
        this.T3_evaluated = update.T3_evaluated;
        this.T3_state = update.T3_state;
    }

    public void _apply_update_for_T2WriteBus(_ProjectionWrite_T2WriteBus update) {
        this.T2_state = update.T2_state;
        this.BUSwrite = update.BUSwrite;
    }

    public boolean _check_inv_1() {
        return T2v.isInteger().booleanValue();
    }

    public boolean _check_inv_2() {
        return T3_evaluated.isBoolean().booleanValue();
    }

    public boolean _check_inv_3() {
        return T3_enabled.isBoolean().booleanValue();
    }

    public boolean _check_inv_4() {
        return _T1state.elementOf(T1_state).booleanValue();
    }

    public boolean _check_inv_5() {
        return _T2state.elementOf(T2_state).booleanValue();
    }

    public boolean _check_inv_6() {
        return _T3state.elementOf(T3_state).booleanValue();
    }

    public boolean _check_inv_7() {
        return T1_writevalue.isInteger().booleanValue();
    }

    public boolean _check_inv_8() {
        return T2_writevalue.isInteger().booleanValue();
    }

    public boolean _check_inv_9() {
        return T2_readvalue.isInteger().booleanValue();
    }

    public boolean _check_inv_10() {
        return T1_timer.isNatural().booleanValue();
    }

    public boolean _check_inv_11() {
        return T2_timer.isNatural().booleanValue();
    }

    public boolean _check_inv_12() {
        return _T2mode.elementOf(T2_mode).booleanValue();
    }

    public boolean _check_inv_13() {
        return BUSvalue.isInteger().booleanValue();
    }

    public boolean _check_inv_14() {
        return NATSET.elementOf(BUSpriority).booleanValue();
    }

    public boolean _check_inv_15() {
        return T3_readvalue.isInteger().booleanValue();
    }

    public boolean _check_inv_16() {
        return NATSET.elementOf(T3_readpriority).booleanValue();
    }

    public boolean _check_inv_17() {
        return NATSET.elementOf(T2_readpriority).booleanValue();
    }

    public boolean _check_inv_18() {
        return BUSwrite.checkDomain(NATSET).and(BUSwrite.checkRangeInteger()).and(BUSwrite.isFunction()).and(BUSwrite.isPartial(NATSET)).booleanValue();
    }

    public boolean _check_inv_19() {
        return BUSwrite.unequal(new BRelation<BInteger, BInteger>()).booleanValue();
    }

    public boolean _check_inv_20() {
        return BUSwrite.isInDomain(new BInteger(0)).booleanValue();
    }


    private static class ModelChecker {
        private final Type type;
        private final int threads;
        private final boolean isCaching;
        private final boolean isDebug;

        private final LinkedList<CAN_BUS_tlc> unvisitedStates = new LinkedList<>();
        private final Set<CAN_BUS_tlc> states = ConcurrentHashMap.newKeySet();
        private AtomicInteger transitions = new AtomicInteger(0);
        private ThreadPoolExecutor threadPool;
        private Object waitLock = new Object();

        private AtomicBoolean invariantViolated = new AtomicBoolean(false);
        private AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        private CAN_BUS_tlc counterExampleState = null;

        PersistentHashMap _OpCache_T1Evaluate = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_T1Evaluate = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_T1Calculate = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_T1Calculate = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_T1SendResult = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_T1SendResult = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_T1Wait = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_T1Wait = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_T2Evaluate = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_T2Evaluate = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_T2ReadBus = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_T2ReadBus = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_T2Reset = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_T2Reset = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_T2Complete = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_T2Complete = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_T2ReleaseBus = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_T2ReleaseBus = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_T2Calculate = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_T2Calculate = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_T2WriteBus = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_T2WriteBus = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_T2Wait = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_T2Wait = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_T3Initiate = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_T3Initiate = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_T3Evaluate = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_T3Evaluate = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_T3writebus = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_T3writebus = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_T3Read = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_T3Read = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_T3Poll = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_T3Poll = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_T3ReleaseBus = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_T3ReleaseBus = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_T3Wait = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_T3Wait = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_T3ReEnableWait = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_T3ReEnableWait = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_Update = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_Update = PersistentHashMap.EMPTY;
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
            CAN_BUS_tlc machine = new CAN_BUS_tlc();
            states.add(machine);
            unvisitedStates.add(machine);

            while(!unvisitedStates.isEmpty()) {
                CAN_BUS_tlc state = next();

                Set<CAN_BUS_tlc> nextStates = generateNextStates(state);

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
            CAN_BUS_tlc machine = new CAN_BUS_tlc();
            states.add(machine);
            unvisitedStates.add(machine);

            AtomicBoolean stopThreads = new AtomicBoolean(false);
            AtomicInteger possibleQueueChanges = new AtomicInteger(0);

            while(!unvisitedStates.isEmpty() && !stopThreads.get()) {
                possibleQueueChanges.incrementAndGet();
                CAN_BUS_tlc state = next();
                Runnable task = () -> {
                    Set<CAN_BUS_tlc> nextStates = generateNextStates(state);

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

        private CAN_BUS_tlc next() {
            synchronized(this.unvisitedStates) {
                return switch(type) {
                    case BFS -> this.unvisitedStates.removeFirst();
                    case DFS -> this.unvisitedStates.removeLast();
                    case MIXED -> this.unvisitedStates.size() % 2 == 0 ? this.unvisitedStates.removeFirst() : this.unvisitedStates.removeLast();
                };
            }
        }

        @SuppressWarnings("unchecked")
        private Set<CAN_BUS_tlc> generateNextStates(final CAN_BUS_tlc state) {
            Set<CAN_BUS_tlc> result = new HashSet<>();
            if(isCaching) {
                _ProjectionRead__tr_T1Evaluate read__tr_T1Evaluate_state = state._projected_state_for__tr_T1Evaluate();
                Object _obj__trid_1 = GET.invoke(_OpCache_tr_T1Evaluate, read__tr_T1Evaluate_state);
                boolean _trid_1;
                if(_obj__trid_1 == null) {
                    _trid_1 = state._tr_T1Evaluate();
                    _OpCache_tr_T1Evaluate = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_T1Evaluate, read__tr_T1Evaluate_state, _trid_1);
                } else {
                    _trid_1 = (boolean) _obj__trid_1;
                }
                if(_trid_1) {
                    CAN_BUS_tlc copiedState = state._copy();
                    _ProjectionRead_T1Evaluate readState = state._projected_state_for_T1Evaluate();
                    PersistentHashMap _OpCache_with_parameter_T1Evaluate = (PersistentHashMap) GET.invoke(_OpCache_T1Evaluate, _trid_1);
                    if(_OpCache_with_parameter_T1Evaluate != null) {
                        _ProjectionWrite_T1Evaluate writeState = (_ProjectionWrite_T1Evaluate) GET.invoke(_OpCache_with_parameter_T1Evaluate, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_T1Evaluate(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.T1Evaluate();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_T1Evaluate();
                            _OpCache_with_parameter_T1Evaluate = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_T1Evaluate, readState, writeState);
                            _OpCache_T1Evaluate = (PersistentHashMap) ASSOC.invoke(_OpCache_T1Evaluate, _trid_1, _OpCache_with_parameter_T1Evaluate);
                        }

                    } else {
                        copiedState.T1Evaluate();
                        copiedState.parent = state;
                        _ProjectionWrite_T1Evaluate writeState = copiedState._update_for_T1Evaluate();
                        _OpCache_with_parameter_T1Evaluate = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_T1Evaluate = (PersistentHashMap) ASSOC.invoke(_OpCache_T1Evaluate, _trid_1, _OpCache_with_parameter_T1Evaluate);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_T1Calculate read__tr_T1Calculate_state = state._projected_state_for__tr_T1Calculate();
                BSet<BInteger> _trid_2 = (BSet<BInteger>) GET.invoke(_OpCache_tr_T1Calculate, read__tr_T1Calculate_state);
                if(_trid_2 == null) {
                    _trid_2 = state._tr_T1Calculate();
                    _OpCache_tr_T1Calculate = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_T1Calculate, read__tr_T1Calculate_state, _trid_2);
                }
                for(BInteger param : _trid_2) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    _ProjectionRead_T1Calculate readState = state._projected_state_for_T1Calculate();
                    PersistentHashMap _OpCache_with_parameter_T1Calculate = (PersistentHashMap) GET.invoke(_OpCache_T1Calculate, param);
                    if(_OpCache_with_parameter_T1Calculate != null) {
                        _ProjectionWrite_T1Calculate writeState = (_ProjectionWrite_T1Calculate) GET.invoke(_OpCache_with_parameter_T1Calculate, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_T1Calculate(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.T1Calculate(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_T1Calculate();
                            _OpCache_with_parameter_T1Calculate = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_T1Calculate, readState, writeState);
                            _OpCache_T1Calculate = (PersistentHashMap) ASSOC.invoke(_OpCache_T1Calculate, param, _OpCache_with_parameter_T1Calculate);
                        }

                    } else {
                        copiedState.T1Calculate(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_T1Calculate writeState = copiedState._update_for_T1Calculate();
                        _OpCache_with_parameter_T1Calculate = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_T1Calculate = (PersistentHashMap) ASSOC.invoke(_OpCache_T1Calculate, param, _OpCache_with_parameter_T1Calculate);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_T1SendResult read__tr_T1SendResult_state = state._projected_state_for__tr_T1SendResult();
                BSet<BTuple<BInteger, BInteger>> _trid_3 = (BSet<BTuple<BInteger, BInteger>>) GET.invoke(_OpCache_tr_T1SendResult, read__tr_T1SendResult_state);
                if(_trid_3 == null) {
                    _trid_3 = state._tr_T1SendResult();
                    _OpCache_tr_T1SendResult = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_T1SendResult, read__tr_T1SendResult_state, _trid_3);
                }
                for(BTuple<BInteger, BInteger> param : _trid_3) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    _ProjectionRead_T1SendResult readState = state._projected_state_for_T1SendResult();
                    PersistentHashMap _OpCache_with_parameter_T1SendResult = (PersistentHashMap) GET.invoke(_OpCache_T1SendResult, param);
                    if(_OpCache_with_parameter_T1SendResult != null) {
                        _ProjectionWrite_T1SendResult writeState = (_ProjectionWrite_T1SendResult) GET.invoke(_OpCache_with_parameter_T1SendResult, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_T1SendResult(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.T1SendResult(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_T1SendResult();
                            _OpCache_with_parameter_T1SendResult = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_T1SendResult, readState, writeState);
                            _OpCache_T1SendResult = (PersistentHashMap) ASSOC.invoke(_OpCache_T1SendResult, param, _OpCache_with_parameter_T1SendResult);
                        }

                    } else {
                        copiedState.T1SendResult(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_T1SendResult writeState = copiedState._update_for_T1SendResult();
                        _OpCache_with_parameter_T1SendResult = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_T1SendResult = (PersistentHashMap) ASSOC.invoke(_OpCache_T1SendResult, param, _OpCache_with_parameter_T1SendResult);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_T1Wait read__tr_T1Wait_state = state._projected_state_for__tr_T1Wait();
                BSet<BInteger> _trid_4 = (BSet<BInteger>) GET.invoke(_OpCache_tr_T1Wait, read__tr_T1Wait_state);
                if(_trid_4 == null) {
                    _trid_4 = state._tr_T1Wait();
                    _OpCache_tr_T1Wait = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_T1Wait, read__tr_T1Wait_state, _trid_4);
                }
                for(BInteger param : _trid_4) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    _ProjectionRead_T1Wait readState = state._projected_state_for_T1Wait();
                    PersistentHashMap _OpCache_with_parameter_T1Wait = (PersistentHashMap) GET.invoke(_OpCache_T1Wait, param);
                    if(_OpCache_with_parameter_T1Wait != null) {
                        _ProjectionWrite_T1Wait writeState = (_ProjectionWrite_T1Wait) GET.invoke(_OpCache_with_parameter_T1Wait, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_T1Wait(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.T1Wait(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_T1Wait();
                            _OpCache_with_parameter_T1Wait = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_T1Wait, readState, writeState);
                            _OpCache_T1Wait = (PersistentHashMap) ASSOC.invoke(_OpCache_T1Wait, param, _OpCache_with_parameter_T1Wait);
                        }

                    } else {
                        copiedState.T1Wait(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_T1Wait writeState = copiedState._update_for_T1Wait();
                        _OpCache_with_parameter_T1Wait = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_T1Wait = (PersistentHashMap) ASSOC.invoke(_OpCache_T1Wait, param, _OpCache_with_parameter_T1Wait);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_T2Evaluate read__tr_T2Evaluate_state = state._projected_state_for__tr_T2Evaluate();
                Object _obj__trid_5 = GET.invoke(_OpCache_tr_T2Evaluate, read__tr_T2Evaluate_state);
                boolean _trid_5;
                if(_obj__trid_5 == null) {
                    _trid_5 = state._tr_T2Evaluate();
                    _OpCache_tr_T2Evaluate = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_T2Evaluate, read__tr_T2Evaluate_state, _trid_5);
                } else {
                    _trid_5 = (boolean) _obj__trid_5;
                }
                if(_trid_5) {
                    CAN_BUS_tlc copiedState = state._copy();
                    _ProjectionRead_T2Evaluate readState = state._projected_state_for_T2Evaluate();
                    PersistentHashMap _OpCache_with_parameter_T2Evaluate = (PersistentHashMap) GET.invoke(_OpCache_T2Evaluate, _trid_5);
                    if(_OpCache_with_parameter_T2Evaluate != null) {
                        _ProjectionWrite_T2Evaluate writeState = (_ProjectionWrite_T2Evaluate) GET.invoke(_OpCache_with_parameter_T2Evaluate, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_T2Evaluate(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.T2Evaluate();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_T2Evaluate();
                            _OpCache_with_parameter_T2Evaluate = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_T2Evaluate, readState, writeState);
                            _OpCache_T2Evaluate = (PersistentHashMap) ASSOC.invoke(_OpCache_T2Evaluate, _trid_5, _OpCache_with_parameter_T2Evaluate);
                        }

                    } else {
                        copiedState.T2Evaluate();
                        copiedState.parent = state;
                        _ProjectionWrite_T2Evaluate writeState = copiedState._update_for_T2Evaluate();
                        _OpCache_with_parameter_T2Evaluate = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_T2Evaluate = (PersistentHashMap) ASSOC.invoke(_OpCache_T2Evaluate, _trid_5, _OpCache_with_parameter_T2Evaluate);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_T2ReadBus read__tr_T2ReadBus_state = state._projected_state_for__tr_T2ReadBus();
                BSet<BTuple<BInteger, BInteger>> _trid_6 = (BSet<BTuple<BInteger, BInteger>>) GET.invoke(_OpCache_tr_T2ReadBus, read__tr_T2ReadBus_state);
                if(_trid_6 == null) {
                    _trid_6 = state._tr_T2ReadBus();
                    _OpCache_tr_T2ReadBus = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_T2ReadBus, read__tr_T2ReadBus_state, _trid_6);
                }
                for(BTuple<BInteger, BInteger> param : _trid_6) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    _ProjectionRead_T2ReadBus readState = state._projected_state_for_T2ReadBus();
                    PersistentHashMap _OpCache_with_parameter_T2ReadBus = (PersistentHashMap) GET.invoke(_OpCache_T2ReadBus, param);
                    if(_OpCache_with_parameter_T2ReadBus != null) {
                        _ProjectionWrite_T2ReadBus writeState = (_ProjectionWrite_T2ReadBus) GET.invoke(_OpCache_with_parameter_T2ReadBus, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_T2ReadBus(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.T2ReadBus(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_T2ReadBus();
                            _OpCache_with_parameter_T2ReadBus = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_T2ReadBus, readState, writeState);
                            _OpCache_T2ReadBus = (PersistentHashMap) ASSOC.invoke(_OpCache_T2ReadBus, param, _OpCache_with_parameter_T2ReadBus);
                        }

                    } else {
                        copiedState.T2ReadBus(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_T2ReadBus writeState = copiedState._update_for_T2ReadBus();
                        _OpCache_with_parameter_T2ReadBus = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_T2ReadBus = (PersistentHashMap) ASSOC.invoke(_OpCache_T2ReadBus, param, _OpCache_with_parameter_T2ReadBus);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_T2Reset read__tr_T2Reset_state = state._projected_state_for__tr_T2Reset();
                Object _obj__trid_7 = GET.invoke(_OpCache_tr_T2Reset, read__tr_T2Reset_state);
                boolean _trid_7;
                if(_obj__trid_7 == null) {
                    _trid_7 = state._tr_T2Reset();
                    _OpCache_tr_T2Reset = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_T2Reset, read__tr_T2Reset_state, _trid_7);
                } else {
                    _trid_7 = (boolean) _obj__trid_7;
                }
                if(_trid_7) {
                    CAN_BUS_tlc copiedState = state._copy();
                    _ProjectionRead_T2Reset readState = state._projected_state_for_T2Reset();
                    PersistentHashMap _OpCache_with_parameter_T2Reset = (PersistentHashMap) GET.invoke(_OpCache_T2Reset, _trid_7);
                    if(_OpCache_with_parameter_T2Reset != null) {
                        _ProjectionWrite_T2Reset writeState = (_ProjectionWrite_T2Reset) GET.invoke(_OpCache_with_parameter_T2Reset, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_T2Reset(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.T2Reset();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_T2Reset();
                            _OpCache_with_parameter_T2Reset = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_T2Reset, readState, writeState);
                            _OpCache_T2Reset = (PersistentHashMap) ASSOC.invoke(_OpCache_T2Reset, _trid_7, _OpCache_with_parameter_T2Reset);
                        }

                    } else {
                        copiedState.T2Reset();
                        copiedState.parent = state;
                        _ProjectionWrite_T2Reset writeState = copiedState._update_for_T2Reset();
                        _OpCache_with_parameter_T2Reset = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_T2Reset = (PersistentHashMap) ASSOC.invoke(_OpCache_T2Reset, _trid_7, _OpCache_with_parameter_T2Reset);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_T2Complete read__tr_T2Complete_state = state._projected_state_for__tr_T2Complete();
                Object _obj__trid_8 = GET.invoke(_OpCache_tr_T2Complete, read__tr_T2Complete_state);
                boolean _trid_8;
                if(_obj__trid_8 == null) {
                    _trid_8 = state._tr_T2Complete();
                    _OpCache_tr_T2Complete = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_T2Complete, read__tr_T2Complete_state, _trid_8);
                } else {
                    _trid_8 = (boolean) _obj__trid_8;
                }
                if(_trid_8) {
                    CAN_BUS_tlc copiedState = state._copy();
                    _ProjectionRead_T2Complete readState = state._projected_state_for_T2Complete();
                    PersistentHashMap _OpCache_with_parameter_T2Complete = (PersistentHashMap) GET.invoke(_OpCache_T2Complete, _trid_8);
                    if(_OpCache_with_parameter_T2Complete != null) {
                        _ProjectionWrite_T2Complete writeState = (_ProjectionWrite_T2Complete) GET.invoke(_OpCache_with_parameter_T2Complete, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_T2Complete(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.T2Complete();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_T2Complete();
                            _OpCache_with_parameter_T2Complete = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_T2Complete, readState, writeState);
                            _OpCache_T2Complete = (PersistentHashMap) ASSOC.invoke(_OpCache_T2Complete, _trid_8, _OpCache_with_parameter_T2Complete);
                        }

                    } else {
                        copiedState.T2Complete();
                        copiedState.parent = state;
                        _ProjectionWrite_T2Complete writeState = copiedState._update_for_T2Complete();
                        _OpCache_with_parameter_T2Complete = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_T2Complete = (PersistentHashMap) ASSOC.invoke(_OpCache_T2Complete, _trid_8, _OpCache_with_parameter_T2Complete);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_T2ReleaseBus read__tr_T2ReleaseBus_state = state._projected_state_for__tr_T2ReleaseBus();
                BSet<BInteger> _trid_9 = (BSet<BInteger>) GET.invoke(_OpCache_tr_T2ReleaseBus, read__tr_T2ReleaseBus_state);
                if(_trid_9 == null) {
                    _trid_9 = state._tr_T2ReleaseBus();
                    _OpCache_tr_T2ReleaseBus = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_T2ReleaseBus, read__tr_T2ReleaseBus_state, _trid_9);
                }
                for(BInteger param : _trid_9) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    _ProjectionRead_T2ReleaseBus readState = state._projected_state_for_T2ReleaseBus();
                    PersistentHashMap _OpCache_with_parameter_T2ReleaseBus = (PersistentHashMap) GET.invoke(_OpCache_T2ReleaseBus, param);
                    if(_OpCache_with_parameter_T2ReleaseBus != null) {
                        _ProjectionWrite_T2ReleaseBus writeState = (_ProjectionWrite_T2ReleaseBus) GET.invoke(_OpCache_with_parameter_T2ReleaseBus, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_T2ReleaseBus(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.T2ReleaseBus(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_T2ReleaseBus();
                            _OpCache_with_parameter_T2ReleaseBus = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_T2ReleaseBus, readState, writeState);
                            _OpCache_T2ReleaseBus = (PersistentHashMap) ASSOC.invoke(_OpCache_T2ReleaseBus, param, _OpCache_with_parameter_T2ReleaseBus);
                        }

                    } else {
                        copiedState.T2ReleaseBus(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_T2ReleaseBus writeState = copiedState._update_for_T2ReleaseBus();
                        _OpCache_with_parameter_T2ReleaseBus = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_T2ReleaseBus = (PersistentHashMap) ASSOC.invoke(_OpCache_T2ReleaseBus, param, _OpCache_with_parameter_T2ReleaseBus);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_T2Calculate read__tr_T2Calculate_state = state._projected_state_for__tr_T2Calculate();
                Object _obj__trid_10 = GET.invoke(_OpCache_tr_T2Calculate, read__tr_T2Calculate_state);
                boolean _trid_10;
                if(_obj__trid_10 == null) {
                    _trid_10 = state._tr_T2Calculate();
                    _OpCache_tr_T2Calculate = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_T2Calculate, read__tr_T2Calculate_state, _trid_10);
                } else {
                    _trid_10 = (boolean) _obj__trid_10;
                }
                if(_trid_10) {
                    CAN_BUS_tlc copiedState = state._copy();
                    _ProjectionRead_T2Calculate readState = state._projected_state_for_T2Calculate();
                    PersistentHashMap _OpCache_with_parameter_T2Calculate = (PersistentHashMap) GET.invoke(_OpCache_T2Calculate, _trid_10);
                    if(_OpCache_with_parameter_T2Calculate != null) {
                        _ProjectionWrite_T2Calculate writeState = (_ProjectionWrite_T2Calculate) GET.invoke(_OpCache_with_parameter_T2Calculate, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_T2Calculate(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.T2Calculate();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_T2Calculate();
                            _OpCache_with_parameter_T2Calculate = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_T2Calculate, readState, writeState);
                            _OpCache_T2Calculate = (PersistentHashMap) ASSOC.invoke(_OpCache_T2Calculate, _trid_10, _OpCache_with_parameter_T2Calculate);
                        }

                    } else {
                        copiedState.T2Calculate();
                        copiedState.parent = state;
                        _ProjectionWrite_T2Calculate writeState = copiedState._update_for_T2Calculate();
                        _OpCache_with_parameter_T2Calculate = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_T2Calculate = (PersistentHashMap) ASSOC.invoke(_OpCache_T2Calculate, _trid_10, _OpCache_with_parameter_T2Calculate);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_T2WriteBus read__tr_T2WriteBus_state = state._projected_state_for__tr_T2WriteBus();
                BSet<BTuple<BInteger, BInteger>> _trid_11 = (BSet<BTuple<BInteger, BInteger>>) GET.invoke(_OpCache_tr_T2WriteBus, read__tr_T2WriteBus_state);
                if(_trid_11 == null) {
                    _trid_11 = state._tr_T2WriteBus();
                    _OpCache_tr_T2WriteBus = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_T2WriteBus, read__tr_T2WriteBus_state, _trid_11);
                }
                for(BTuple<BInteger, BInteger> param : _trid_11) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    _ProjectionRead_T2WriteBus readState = state._projected_state_for_T2WriteBus();
                    PersistentHashMap _OpCache_with_parameter_T2WriteBus = (PersistentHashMap) GET.invoke(_OpCache_T2WriteBus, param);
                    if(_OpCache_with_parameter_T2WriteBus != null) {
                        _ProjectionWrite_T2WriteBus writeState = (_ProjectionWrite_T2WriteBus) GET.invoke(_OpCache_with_parameter_T2WriteBus, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_T2WriteBus(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.T2WriteBus(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_T2WriteBus();
                            _OpCache_with_parameter_T2WriteBus = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_T2WriteBus, readState, writeState);
                            _OpCache_T2WriteBus = (PersistentHashMap) ASSOC.invoke(_OpCache_T2WriteBus, param, _OpCache_with_parameter_T2WriteBus);
                        }

                    } else {
                        copiedState.T2WriteBus(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_T2WriteBus writeState = copiedState._update_for_T2WriteBus();
                        _OpCache_with_parameter_T2WriteBus = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_T2WriteBus = (PersistentHashMap) ASSOC.invoke(_OpCache_T2WriteBus, param, _OpCache_with_parameter_T2WriteBus);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_T2Wait read__tr_T2Wait_state = state._projected_state_for__tr_T2Wait();
                BSet<BInteger> _trid_12 = (BSet<BInteger>) GET.invoke(_OpCache_tr_T2Wait, read__tr_T2Wait_state);
                if(_trid_12 == null) {
                    _trid_12 = state._tr_T2Wait();
                    _OpCache_tr_T2Wait = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_T2Wait, read__tr_T2Wait_state, _trid_12);
                }
                for(BInteger param : _trid_12) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    _ProjectionRead_T2Wait readState = state._projected_state_for_T2Wait();
                    PersistentHashMap _OpCache_with_parameter_T2Wait = (PersistentHashMap) GET.invoke(_OpCache_T2Wait, param);
                    if(_OpCache_with_parameter_T2Wait != null) {
                        _ProjectionWrite_T2Wait writeState = (_ProjectionWrite_T2Wait) GET.invoke(_OpCache_with_parameter_T2Wait, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_T2Wait(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.T2Wait(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_T2Wait();
                            _OpCache_with_parameter_T2Wait = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_T2Wait, readState, writeState);
                            _OpCache_T2Wait = (PersistentHashMap) ASSOC.invoke(_OpCache_T2Wait, param, _OpCache_with_parameter_T2Wait);
                        }

                    } else {
                        copiedState.T2Wait(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_T2Wait writeState = copiedState._update_for_T2Wait();
                        _OpCache_with_parameter_T2Wait = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_T2Wait = (PersistentHashMap) ASSOC.invoke(_OpCache_T2Wait, param, _OpCache_with_parameter_T2Wait);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_T3Initiate read__tr_T3Initiate_state = state._projected_state_for__tr_T3Initiate();
                Object _obj__trid_13 = GET.invoke(_OpCache_tr_T3Initiate, read__tr_T3Initiate_state);
                boolean _trid_13;
                if(_obj__trid_13 == null) {
                    _trid_13 = state._tr_T3Initiate();
                    _OpCache_tr_T3Initiate = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_T3Initiate, read__tr_T3Initiate_state, _trid_13);
                } else {
                    _trid_13 = (boolean) _obj__trid_13;
                }
                if(_trid_13) {
                    CAN_BUS_tlc copiedState = state._copy();
                    _ProjectionRead_T3Initiate readState = state._projected_state_for_T3Initiate();
                    PersistentHashMap _OpCache_with_parameter_T3Initiate = (PersistentHashMap) GET.invoke(_OpCache_T3Initiate, _trid_13);
                    if(_OpCache_with_parameter_T3Initiate != null) {
                        _ProjectionWrite_T3Initiate writeState = (_ProjectionWrite_T3Initiate) GET.invoke(_OpCache_with_parameter_T3Initiate, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_T3Initiate(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.T3Initiate();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_T3Initiate();
                            _OpCache_with_parameter_T3Initiate = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_T3Initiate, readState, writeState);
                            _OpCache_T3Initiate = (PersistentHashMap) ASSOC.invoke(_OpCache_T3Initiate, _trid_13, _OpCache_with_parameter_T3Initiate);
                        }

                    } else {
                        copiedState.T3Initiate();
                        copiedState.parent = state;
                        _ProjectionWrite_T3Initiate writeState = copiedState._update_for_T3Initiate();
                        _OpCache_with_parameter_T3Initiate = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_T3Initiate = (PersistentHashMap) ASSOC.invoke(_OpCache_T3Initiate, _trid_13, _OpCache_with_parameter_T3Initiate);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_T3Evaluate read__tr_T3Evaluate_state = state._projected_state_for__tr_T3Evaluate();
                Object _obj__trid_14 = GET.invoke(_OpCache_tr_T3Evaluate, read__tr_T3Evaluate_state);
                boolean _trid_14;
                if(_obj__trid_14 == null) {
                    _trid_14 = state._tr_T3Evaluate();
                    _OpCache_tr_T3Evaluate = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_T3Evaluate, read__tr_T3Evaluate_state, _trid_14);
                } else {
                    _trid_14 = (boolean) _obj__trid_14;
                }
                if(_trid_14) {
                    CAN_BUS_tlc copiedState = state._copy();
                    _ProjectionRead_T3Evaluate readState = state._projected_state_for_T3Evaluate();
                    PersistentHashMap _OpCache_with_parameter_T3Evaluate = (PersistentHashMap) GET.invoke(_OpCache_T3Evaluate, _trid_14);
                    if(_OpCache_with_parameter_T3Evaluate != null) {
                        _ProjectionWrite_T3Evaluate writeState = (_ProjectionWrite_T3Evaluate) GET.invoke(_OpCache_with_parameter_T3Evaluate, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_T3Evaluate(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.T3Evaluate();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_T3Evaluate();
                            _OpCache_with_parameter_T3Evaluate = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_T3Evaluate, readState, writeState);
                            _OpCache_T3Evaluate = (PersistentHashMap) ASSOC.invoke(_OpCache_T3Evaluate, _trid_14, _OpCache_with_parameter_T3Evaluate);
                        }

                    } else {
                        copiedState.T3Evaluate();
                        copiedState.parent = state;
                        _ProjectionWrite_T3Evaluate writeState = copiedState._update_for_T3Evaluate();
                        _OpCache_with_parameter_T3Evaluate = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_T3Evaluate = (PersistentHashMap) ASSOC.invoke(_OpCache_T3Evaluate, _trid_14, _OpCache_with_parameter_T3Evaluate);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_T3writebus read__tr_T3writebus_state = state._projected_state_for__tr_T3writebus();
                BSet<BTuple<BInteger, BInteger>> _trid_15 = (BSet<BTuple<BInteger, BInteger>>) GET.invoke(_OpCache_tr_T3writebus, read__tr_T3writebus_state);
                if(_trid_15 == null) {
                    _trid_15 = state._tr_T3writebus();
                    _OpCache_tr_T3writebus = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_T3writebus, read__tr_T3writebus_state, _trid_15);
                }
                for(BTuple<BInteger, BInteger> param : _trid_15) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    _ProjectionRead_T3writebus readState = state._projected_state_for_T3writebus();
                    PersistentHashMap _OpCache_with_parameter_T3writebus = (PersistentHashMap) GET.invoke(_OpCache_T3writebus, param);
                    if(_OpCache_with_parameter_T3writebus != null) {
                        _ProjectionWrite_T3writebus writeState = (_ProjectionWrite_T3writebus) GET.invoke(_OpCache_with_parameter_T3writebus, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_T3writebus(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.T3writebus(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_T3writebus();
                            _OpCache_with_parameter_T3writebus = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_T3writebus, readState, writeState);
                            _OpCache_T3writebus = (PersistentHashMap) ASSOC.invoke(_OpCache_T3writebus, param, _OpCache_with_parameter_T3writebus);
                        }

                    } else {
                        copiedState.T3writebus(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_T3writebus writeState = copiedState._update_for_T3writebus();
                        _OpCache_with_parameter_T3writebus = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_T3writebus = (PersistentHashMap) ASSOC.invoke(_OpCache_T3writebus, param, _OpCache_with_parameter_T3writebus);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_T3Read read__tr_T3Read_state = state._projected_state_for__tr_T3Read();
                BSet<BTuple<BInteger, BInteger>> _trid_16 = (BSet<BTuple<BInteger, BInteger>>) GET.invoke(_OpCache_tr_T3Read, read__tr_T3Read_state);
                if(_trid_16 == null) {
                    _trid_16 = state._tr_T3Read();
                    _OpCache_tr_T3Read = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_T3Read, read__tr_T3Read_state, _trid_16);
                }
                for(BTuple<BInteger, BInteger> param : _trid_16) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    _ProjectionRead_T3Read readState = state._projected_state_for_T3Read();
                    PersistentHashMap _OpCache_with_parameter_T3Read = (PersistentHashMap) GET.invoke(_OpCache_T3Read, param);
                    if(_OpCache_with_parameter_T3Read != null) {
                        _ProjectionWrite_T3Read writeState = (_ProjectionWrite_T3Read) GET.invoke(_OpCache_with_parameter_T3Read, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_T3Read(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.T3Read(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_T3Read();
                            _OpCache_with_parameter_T3Read = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_T3Read, readState, writeState);
                            _OpCache_T3Read = (PersistentHashMap) ASSOC.invoke(_OpCache_T3Read, param, _OpCache_with_parameter_T3Read);
                        }

                    } else {
                        copiedState.T3Read(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_T3Read writeState = copiedState._update_for_T3Read();
                        _OpCache_with_parameter_T3Read = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_T3Read = (PersistentHashMap) ASSOC.invoke(_OpCache_T3Read, param, _OpCache_with_parameter_T3Read);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_T3Poll read__tr_T3Poll_state = state._projected_state_for__tr_T3Poll();
                Object _obj__trid_17 = GET.invoke(_OpCache_tr_T3Poll, read__tr_T3Poll_state);
                boolean _trid_17;
                if(_obj__trid_17 == null) {
                    _trid_17 = state._tr_T3Poll();
                    _OpCache_tr_T3Poll = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_T3Poll, read__tr_T3Poll_state, _trid_17);
                } else {
                    _trid_17 = (boolean) _obj__trid_17;
                }
                if(_trid_17) {
                    CAN_BUS_tlc copiedState = state._copy();
                    _ProjectionRead_T3Poll readState = state._projected_state_for_T3Poll();
                    PersistentHashMap _OpCache_with_parameter_T3Poll = (PersistentHashMap) GET.invoke(_OpCache_T3Poll, _trid_17);
                    if(_OpCache_with_parameter_T3Poll != null) {
                        _ProjectionWrite_T3Poll writeState = (_ProjectionWrite_T3Poll) GET.invoke(_OpCache_with_parameter_T3Poll, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_T3Poll(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.T3Poll();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_T3Poll();
                            _OpCache_with_parameter_T3Poll = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_T3Poll, readState, writeState);
                            _OpCache_T3Poll = (PersistentHashMap) ASSOC.invoke(_OpCache_T3Poll, _trid_17, _OpCache_with_parameter_T3Poll);
                        }

                    } else {
                        copiedState.T3Poll();
                        copiedState.parent = state;
                        _ProjectionWrite_T3Poll writeState = copiedState._update_for_T3Poll();
                        _OpCache_with_parameter_T3Poll = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_T3Poll = (PersistentHashMap) ASSOC.invoke(_OpCache_T3Poll, _trid_17, _OpCache_with_parameter_T3Poll);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_T3ReleaseBus read__tr_T3ReleaseBus_state = state._projected_state_for__tr_T3ReleaseBus();
                BSet<BInteger> _trid_18 = (BSet<BInteger>) GET.invoke(_OpCache_tr_T3ReleaseBus, read__tr_T3ReleaseBus_state);
                if(_trid_18 == null) {
                    _trid_18 = state._tr_T3ReleaseBus();
                    _OpCache_tr_T3ReleaseBus = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_T3ReleaseBus, read__tr_T3ReleaseBus_state, _trid_18);
                }
                for(BInteger param : _trid_18) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    _ProjectionRead_T3ReleaseBus readState = state._projected_state_for_T3ReleaseBus();
                    PersistentHashMap _OpCache_with_parameter_T3ReleaseBus = (PersistentHashMap) GET.invoke(_OpCache_T3ReleaseBus, param);
                    if(_OpCache_with_parameter_T3ReleaseBus != null) {
                        _ProjectionWrite_T3ReleaseBus writeState = (_ProjectionWrite_T3ReleaseBus) GET.invoke(_OpCache_with_parameter_T3ReleaseBus, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_T3ReleaseBus(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.T3ReleaseBus(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_T3ReleaseBus();
                            _OpCache_with_parameter_T3ReleaseBus = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_T3ReleaseBus, readState, writeState);
                            _OpCache_T3ReleaseBus = (PersistentHashMap) ASSOC.invoke(_OpCache_T3ReleaseBus, param, _OpCache_with_parameter_T3ReleaseBus);
                        }

                    } else {
                        copiedState.T3ReleaseBus(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_T3ReleaseBus writeState = copiedState._update_for_T3ReleaseBus();
                        _OpCache_with_parameter_T3ReleaseBus = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_T3ReleaseBus = (PersistentHashMap) ASSOC.invoke(_OpCache_T3ReleaseBus, param, _OpCache_with_parameter_T3ReleaseBus);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_T3Wait read__tr_T3Wait_state = state._projected_state_for__tr_T3Wait();
                Object _obj__trid_19 = GET.invoke(_OpCache_tr_T3Wait, read__tr_T3Wait_state);
                boolean _trid_19;
                if(_obj__trid_19 == null) {
                    _trid_19 = state._tr_T3Wait();
                    _OpCache_tr_T3Wait = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_T3Wait, read__tr_T3Wait_state, _trid_19);
                } else {
                    _trid_19 = (boolean) _obj__trid_19;
                }
                if(_trid_19) {
                    CAN_BUS_tlc copiedState = state._copy();
                    _ProjectionRead_T3Wait readState = state._projected_state_for_T3Wait();
                    PersistentHashMap _OpCache_with_parameter_T3Wait = (PersistentHashMap) GET.invoke(_OpCache_T3Wait, _trid_19);
                    if(_OpCache_with_parameter_T3Wait != null) {
                        _ProjectionWrite_T3Wait writeState = (_ProjectionWrite_T3Wait) GET.invoke(_OpCache_with_parameter_T3Wait, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_T3Wait(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.T3Wait();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_T3Wait();
                            _OpCache_with_parameter_T3Wait = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_T3Wait, readState, writeState);
                            _OpCache_T3Wait = (PersistentHashMap) ASSOC.invoke(_OpCache_T3Wait, _trid_19, _OpCache_with_parameter_T3Wait);
                        }

                    } else {
                        copiedState.T3Wait();
                        copiedState.parent = state;
                        _ProjectionWrite_T3Wait writeState = copiedState._update_for_T3Wait();
                        _OpCache_with_parameter_T3Wait = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_T3Wait = (PersistentHashMap) ASSOC.invoke(_OpCache_T3Wait, _trid_19, _OpCache_with_parameter_T3Wait);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_T3ReEnableWait read__tr_T3ReEnableWait_state = state._projected_state_for__tr_T3ReEnableWait();
                Object _obj__trid_20 = GET.invoke(_OpCache_tr_T3ReEnableWait, read__tr_T3ReEnableWait_state);
                boolean _trid_20;
                if(_obj__trid_20 == null) {
                    _trid_20 = state._tr_T3ReEnableWait();
                    _OpCache_tr_T3ReEnableWait = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_T3ReEnableWait, read__tr_T3ReEnableWait_state, _trid_20);
                } else {
                    _trid_20 = (boolean) _obj__trid_20;
                }
                if(_trid_20) {
                    CAN_BUS_tlc copiedState = state._copy();
                    _ProjectionRead_T3ReEnableWait readState = state._projected_state_for_T3ReEnableWait();
                    PersistentHashMap _OpCache_with_parameter_T3ReEnableWait = (PersistentHashMap) GET.invoke(_OpCache_T3ReEnableWait, _trid_20);
                    if(_OpCache_with_parameter_T3ReEnableWait != null) {
                        _ProjectionWrite_T3ReEnableWait writeState = (_ProjectionWrite_T3ReEnableWait) GET.invoke(_OpCache_with_parameter_T3ReEnableWait, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_T3ReEnableWait(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.T3ReEnableWait();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_T3ReEnableWait();
                            _OpCache_with_parameter_T3ReEnableWait = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_T3ReEnableWait, readState, writeState);
                            _OpCache_T3ReEnableWait = (PersistentHashMap) ASSOC.invoke(_OpCache_T3ReEnableWait, _trid_20, _OpCache_with_parameter_T3ReEnableWait);
                        }

                    } else {
                        copiedState.T3ReEnableWait();
                        copiedState.parent = state;
                        _ProjectionWrite_T3ReEnableWait writeState = copiedState._update_for_T3ReEnableWait();
                        _OpCache_with_parameter_T3ReEnableWait = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_T3ReEnableWait = (PersistentHashMap) ASSOC.invoke(_OpCache_T3ReEnableWait, _trid_20, _OpCache_with_parameter_T3ReEnableWait);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_Update read__tr_Update_state = state._projected_state_for__tr_Update();
                BSet<BInteger> _trid_21 = (BSet<BInteger>) GET.invoke(_OpCache_tr_Update, read__tr_Update_state);
                if(_trid_21 == null) {
                    _trid_21 = state._tr_Update();
                    _OpCache_tr_Update = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_Update, read__tr_Update_state, _trid_21);
                }
                for(BInteger param : _trid_21) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    _ProjectionRead_Update readState = state._projected_state_for_Update();
                    PersistentHashMap _OpCache_with_parameter_Update = (PersistentHashMap) GET.invoke(_OpCache_Update, param);
                    if(_OpCache_with_parameter_Update != null) {
                        _ProjectionWrite_Update writeState = (_ProjectionWrite_Update) GET.invoke(_OpCache_with_parameter_Update, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_Update(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.Update(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_Update();
                            _OpCache_with_parameter_Update = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_Update, readState, writeState);
                            _OpCache_Update = (PersistentHashMap) ASSOC.invoke(_OpCache_Update, param, _OpCache_with_parameter_Update);
                        }

                    } else {
                        copiedState.Update(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_Update writeState = copiedState._update_for_Update();
                        _OpCache_with_parameter_Update = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_Update = (PersistentHashMap) ASSOC.invoke(_OpCache_Update, param, _OpCache_with_parameter_Update);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            } else {
                if(state._tr_T1Evaluate()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T1Evaluate();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BInteger> _trid_2 = state._tr_T1Calculate();
                for(BInteger param : _trid_2) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T1Calculate(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BInteger, BInteger>> _trid_3 = state._tr_T1SendResult();
                for(BTuple<BInteger, BInteger> param : _trid_3) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T1SendResult(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BInteger> _trid_4 = state._tr_T1Wait();
                for(BInteger param : _trid_4) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T1Wait(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_T2Evaluate()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2Evaluate();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BInteger, BInteger>> _trid_6 = state._tr_T2ReadBus();
                for(BTuple<BInteger, BInteger> param : _trid_6) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2ReadBus(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_T2Reset()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2Reset();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_T2Complete()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2Complete();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BInteger> _trid_9 = state._tr_T2ReleaseBus();
                for(BInteger param : _trid_9) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2ReleaseBus(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_T2Calculate()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2Calculate();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BInteger, BInteger>> _trid_11 = state._tr_T2WriteBus();
                for(BTuple<BInteger, BInteger> param : _trid_11) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2WriteBus(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BInteger> _trid_12 = state._tr_T2Wait();
                for(BInteger param : _trid_12) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2Wait(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_T3Initiate()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3Initiate();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_T3Evaluate()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3Evaluate();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BInteger, BInteger>> _trid_15 = state._tr_T3writebus();
                for(BTuple<BInteger, BInteger> param : _trid_15) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3writebus(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BInteger, BInteger>> _trid_16 = state._tr_T3Read();
                for(BTuple<BInteger, BInteger> param : _trid_16) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3Read(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_T3Poll()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3Poll();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BInteger> _trid_18 = state._tr_T3ReleaseBus();
                for(BInteger param : _trid_18) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3ReleaseBus(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_T3Wait()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3Wait();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_T3ReEnableWait()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3ReEnableWait();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BInteger> _trid_21 = state._tr_Update();
                for(BInteger param : _trid_21) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.Update(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            }
            return result;
        }

        private boolean invariantViolated(final CAN_BUS_tlc state) {
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
