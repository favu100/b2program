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


public class obsw_M001_2 {


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

    public obsw_M001_2 parent;
    public String stateAccessedVia;

    public static class _ProjectionRead_env_Receive_TC {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET> TCbuffer;

        public _ProjectionRead_env_Receive_TC(BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET> TCbuffer) {
            this.TCbuffer = TCbuffer;
        }

        public String toString() {
            return "{" + "TCbuffer: " + this.TCbuffer + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_env_Receive_TC)) {
                return false;
            }
            _ProjectionRead_env_Receive_TC o = (_ProjectionRead_env_Receive_TC) other;
            return this.TCbuffer.equals(o.TCbuffer);
        }

        public int hashCode() {
            return Objects.hash(TCbuffer);
        }
    }

    public static class _ProjectionRead__tr_env_Receive_TC {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET> TCbuffer;

        public _ProjectionRead__tr_env_Receive_TC(BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET> TCbuffer) {
            this.TCbuffer = TCbuffer;
        }

        public String toString() {
            return "{" + "TCbuffer: " + this.TCbuffer + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_env_Receive_TC)) {
                return false;
            }
            _ProjectionRead__tr_env_Receive_TC o = (_ProjectionRead__tr_env_Receive_TC) other;
            return this.TCbuffer.equals(o.TCbuffer);
        }

        public int hashCode() {
            return Objects.hash(TCbuffer);
        }
    }

    public static class _ProjectionWrite_env_Receive_TC {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET> TCbuffer;

        public _ProjectionWrite_env_Receive_TC(BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET> TCbuffer) {
            this.TCbuffer = TCbuffer;
        }

        public String toString() {
            return "{" + "TCbuffer: " + this.TCbuffer + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_env_Receive_TC)) {
                return false;
            }
            _ProjectionWrite_env_Receive_TC o = (_ProjectionWrite_env_Receive_TC) other;
            return this.TCbuffer.equals(o.TCbuffer);
        }

        public int hashCode() {
            return Objects.hash(TCbuffer);
        }
    }

    public static class _ProjectionRead_Poll_TC {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET> TCbuffer;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead_Poll_TC(BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET> TCbuffer, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCbuffer = TCbuffer;
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCbuffer: " + this.TCbuffer + "," + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_Poll_TC)) {
                return false;
            }
            _ProjectionRead_Poll_TC o = (_ProjectionRead_Poll_TC) other;
            return this.TCbuffer.equals(o.TCbuffer) && this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCbuffer, TCpool, TCstatus);
        }
    }

    public static class _ProjectionRead__tr_Poll_TC {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET> TCbuffer;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;

        public _ProjectionRead__tr_Poll_TC(BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET> TCbuffer, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool) {
            this.TCbuffer = TCbuffer;
            this.TCpool = TCpool;
        }

        public String toString() {
            return "{" + "TCbuffer: " + this.TCbuffer + "," + "TCpool: " + this.TCpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_Poll_TC)) {
                return false;
            }
            _ProjectionRead__tr_Poll_TC o = (_ProjectionRead__tr_Poll_TC) other;
            return this.TCbuffer.equals(o.TCbuffer) && this.TCpool.equals(o.TCpool);
        }

        public int hashCode() {
            return Objects.hash(TCbuffer, TCpool);
        }
    }

    public static class _ProjectionWrite_Poll_TC {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET> TCbuffer;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionWrite_Poll_TC(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET> TCbuffer, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCbuffer = TCbuffer;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCbuffer: " + this.TCbuffer + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_Poll_TC)) {
                return false;
            }
            _ProjectionWrite_Poll_TC o = (_ProjectionWrite_Poll_TC) other;
            return this.TCpool.equals(o.TCpool) && this.TCbuffer.equals(o.TCbuffer) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCbuffer, TCstatus);
        }
    }

    public static class _ProjectionRead_Accept_TC {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead_Accept_TC(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_Accept_TC)) {
                return false;
            }
            _ProjectionRead_Accept_TC o = (_ProjectionRead_Accept_TC) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionRead__tr_Accept_TC {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead__tr_Accept_TC(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_Accept_TC)) {
                return false;
            }
            _ProjectionRead__tr_Accept_TC o = (_ProjectionRead__tr_Accept_TC) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionWrite_Accept_TC {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionWrite_Accept_TC(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_Accept_TC)) {
                return false;
            }
            _ProjectionWrite_Accept_TC o = (_ProjectionWrite_Accept_TC) other;
            return this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCstatus);
        }
    }

    public static class _ProjectionRead_Reject_TC {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead_Reject_TC(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_Reject_TC)) {
                return false;
            }
            _ProjectionRead_Reject_TC o = (_ProjectionRead_Reject_TC) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionRead__tr_Reject_TC {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead__tr_Reject_TC(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_Reject_TC)) {
                return false;
            }
            _ProjectionRead__tr_Reject_TC o = (_ProjectionRead__tr_Reject_TC) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionWrite_Reject_TC {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionWrite_Reject_TC(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_Reject_TC)) {
                return false;
            }
            _ProjectionWrite_Reject_TC o = (_ProjectionWrite_Reject_TC) other;
            return this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCstatus);
        }
    }

    public static class _ProjectionRead_Report_TC_Acceptance {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionRead_Report_TC_Acceptance(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
            this.TMstatus = TMstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "," + "TMstatus: " + this.TMstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_Report_TC_Acceptance)) {
                return false;
            }
            _ProjectionRead_Report_TC_Acceptance o = (_ProjectionRead_Report_TC_Acceptance) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus) && this.TMstatus.equals(o.TMstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus, TMstatus, TMpool);
        }
    }

    public static class _ProjectionRead__tr_Report_TC_Acceptance {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionRead__tr_Report_TC_Acceptance(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_Report_TC_Acceptance)) {
                return false;
            }
            _ProjectionRead__tr_Report_TC_Acceptance o = (_ProjectionRead__tr_Report_TC_Acceptance) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus, TMpool);
        }
    }

    public static class _ProjectionWrite_Report_TC_Acceptance {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionWrite_Report_TC_Acceptance(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TCstatus = TCstatus;
            this.TMstatus = TMstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TCstatus: " + this.TCstatus + "," + "TMstatus: " + this.TMstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_Report_TC_Acceptance)) {
                return false;
            }
            _ProjectionWrite_Report_TC_Acceptance o = (_ProjectionWrite_Report_TC_Acceptance) other;
            return this.TCstatus.equals(o.TCstatus) && this.TMstatus.equals(o.TMstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TCstatus, TMstatus, TMpool);
        }
    }

    public static class _ProjectionRead_Skip_TC_Acceptance_Report {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead_Skip_TC_Acceptance_Report(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_Skip_TC_Acceptance_Report)) {
                return false;
            }
            _ProjectionRead_Skip_TC_Acceptance_Report o = (_ProjectionRead_Skip_TC_Acceptance_Report) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionRead__tr_Skip_TC_Acceptance_Report {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead__tr_Skip_TC_Acceptance_Report(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_Skip_TC_Acceptance_Report)) {
                return false;
            }
            _ProjectionRead__tr_Skip_TC_Acceptance_Report o = (_ProjectionRead__tr_Skip_TC_Acceptance_Report) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionWrite_Skip_TC_Acceptance_Report {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionWrite_Skip_TC_Acceptance_Report(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_Skip_TC_Acceptance_Report)) {
                return false;
            }
            _ProjectionWrite_Skip_TC_Acceptance_Report o = (_ProjectionWrite_Skip_TC_Acceptance_Report) other;
            return this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCstatus);
        }
    }

    public static class _ProjectionRead_Report_TC_Rejection {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionRead_Report_TC_Rejection(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
            this.TMstatus = TMstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "," + "TMstatus: " + this.TMstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_Report_TC_Rejection)) {
                return false;
            }
            _ProjectionRead_Report_TC_Rejection o = (_ProjectionRead_Report_TC_Rejection) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus) && this.TMstatus.equals(o.TMstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus, TMstatus, TMpool);
        }
    }

    public static class _ProjectionRead__tr_Report_TC_Rejection {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionRead__tr_Report_TC_Rejection(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_Report_TC_Rejection)) {
                return false;
            }
            _ProjectionRead__tr_Report_TC_Rejection o = (_ProjectionRead__tr_Report_TC_Rejection) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus, TMpool);
        }
    }

    public static class _ProjectionWrite_Report_TC_Rejection {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionWrite_Report_TC_Rejection(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TCstatus = TCstatus;
            this.TMstatus = TMstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TCstatus: " + this.TCstatus + "," + "TMstatus: " + this.TMstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_Report_TC_Rejection)) {
                return false;
            }
            _ProjectionWrite_Report_TC_Rejection o = (_ProjectionWrite_Report_TC_Rejection) other;
            return this.TCstatus.equals(o.TCstatus) && this.TMstatus.equals(o.TMstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TCstatus, TMstatus, TMpool);
        }
    }

    public static class _ProjectionRead_Skip_TC_Rejection_Report {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead_Skip_TC_Rejection_Report(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_Skip_TC_Rejection_Report)) {
                return false;
            }
            _ProjectionRead_Skip_TC_Rejection_Report o = (_ProjectionRead_Skip_TC_Rejection_Report) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionRead__tr_Skip_TC_Rejection_Report {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead__tr_Skip_TC_Rejection_Report(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_Skip_TC_Rejection_Report)) {
                return false;
            }
            _ProjectionRead__tr_Skip_TC_Rejection_Report o = (_ProjectionRead__tr_Skip_TC_Rejection_Report) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionWrite_Skip_TC_Rejection_Report {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionWrite_Skip_TC_Rejection_Report(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_Skip_TC_Rejection_Report)) {
                return false;
            }
            _ProjectionWrite_Skip_TC_Rejection_Report o = (_ProjectionWrite_Skip_TC_Rejection_Report) other;
            return this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCstatus);
        }
    }

    public static class _ProjectionRead_Execute_TC_Successfully {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead_Execute_TC_Successfully(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_Execute_TC_Successfully)) {
                return false;
            }
            _ProjectionRead_Execute_TC_Successfully o = (_ProjectionRead_Execute_TC_Successfully) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionRead__tr_Execute_TC_Successfully {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead__tr_Execute_TC_Successfully(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_Execute_TC_Successfully)) {
                return false;
            }
            _ProjectionRead__tr_Execute_TC_Successfully o = (_ProjectionRead__tr_Execute_TC_Successfully) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionWrite_Execute_TC_Successfully {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionWrite_Execute_TC_Successfully(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_Execute_TC_Successfully)) {
                return false;
            }
            _ProjectionWrite_Execute_TC_Successfully o = (_ProjectionWrite_Execute_TC_Successfully) other;
            return this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCstatus);
        }
    }

    public static class _ProjectionRead_Reset_TM_Buffer {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead_Reset_TM_Buffer(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_Reset_TM_Buffer)) {
                return false;
            }
            _ProjectionRead_Reset_TM_Buffer o = (_ProjectionRead_Reset_TM_Buffer) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionRead__tr_Reset_TM_Buffer {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead__tr_Reset_TM_Buffer(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_Reset_TM_Buffer)) {
                return false;
            }
            _ProjectionRead__tr_Reset_TM_Buffer o = (_ProjectionRead__tr_Reset_TM_Buffer) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionWrite_Reset_TM_Buffer {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET> TMbuffer;

        public _ProjectionWrite_Reset_TM_Buffer(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET> TMbuffer) {
            this.TCstatus = TCstatus;
            this.TMbuffer = TMbuffer;
        }

        public String toString() {
            return "{" + "TCstatus: " + this.TCstatus + "," + "TMbuffer: " + this.TMbuffer + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_Reset_TM_Buffer)) {
                return false;
            }
            _ProjectionWrite_Reset_TM_Buffer o = (_ProjectionWrite_Reset_TM_Buffer) other;
            return this.TCstatus.equals(o.TCstatus) && this.TMbuffer.equals(o.TMbuffer);
        }

        public int hashCode() {
            return Objects.hash(TCstatus, TMbuffer);
        }
    }

    public static class _ProjectionRead_Fail_TC_Execution {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead_Fail_TC_Execution(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_Fail_TC_Execution)) {
                return false;
            }
            _ProjectionRead_Fail_TC_Execution o = (_ProjectionRead_Fail_TC_Execution) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionRead__tr_Fail_TC_Execution {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead__tr_Fail_TC_Execution(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_Fail_TC_Execution)) {
                return false;
            }
            _ProjectionRead__tr_Fail_TC_Execution o = (_ProjectionRead__tr_Fail_TC_Execution) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionWrite_Fail_TC_Execution {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionWrite_Fail_TC_Execution(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_Fail_TC_Execution)) {
                return false;
            }
            _ProjectionWrite_Fail_TC_Execution o = (_ProjectionWrite_Fail_TC_Execution) other;
            return this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCstatus);
        }
    }

    public static class _ProjectionRead_Report_TC_Execution_Success {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionRead_Report_TC_Execution_Success(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
            this.TMstatus = TMstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "," + "TMstatus: " + this.TMstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_Report_TC_Execution_Success)) {
                return false;
            }
            _ProjectionRead_Report_TC_Execution_Success o = (_ProjectionRead_Report_TC_Execution_Success) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus) && this.TMstatus.equals(o.TMstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus, TMstatus, TMpool);
        }
    }

    public static class _ProjectionRead__tr_Report_TC_Execution_Success {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionRead__tr_Report_TC_Execution_Success(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_Report_TC_Execution_Success)) {
                return false;
            }
            _ProjectionRead__tr_Report_TC_Execution_Success o = (_ProjectionRead__tr_Report_TC_Execution_Success) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus, TMpool);
        }
    }

    public static class _ProjectionWrite_Report_TC_Execution_Success {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionWrite_Report_TC_Execution_Success(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TCstatus = TCstatus;
            this.TMstatus = TMstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TCstatus: " + this.TCstatus + "," + "TMstatus: " + this.TMstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_Report_TC_Execution_Success)) {
                return false;
            }
            _ProjectionWrite_Report_TC_Execution_Success o = (_ProjectionWrite_Report_TC_Execution_Success) other;
            return this.TCstatus.equals(o.TCstatus) && this.TMstatus.equals(o.TMstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TCstatus, TMstatus, TMpool);
        }
    }

    public static class _ProjectionRead_Skip_TC_Success_Report {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead_Skip_TC_Success_Report(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_Skip_TC_Success_Report)) {
                return false;
            }
            _ProjectionRead_Skip_TC_Success_Report o = (_ProjectionRead_Skip_TC_Success_Report) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionRead__tr_Skip_TC_Success_Report {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead__tr_Skip_TC_Success_Report(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_Skip_TC_Success_Report)) {
                return false;
            }
            _ProjectionRead__tr_Skip_TC_Success_Report o = (_ProjectionRead__tr_Skip_TC_Success_Report) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionWrite_Skip_TC_Success_Report {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionWrite_Skip_TC_Success_Report(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_Skip_TC_Success_Report)) {
                return false;
            }
            _ProjectionWrite_Skip_TC_Success_Report o = (_ProjectionWrite_Skip_TC_Success_Report) other;
            return this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCstatus);
        }
    }

    public static class _ProjectionRead_Report_TC_Execution_Failure {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionRead_Report_TC_Execution_Failure(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
            this.TMstatus = TMstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "," + "TMstatus: " + this.TMstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_Report_TC_Execution_Failure)) {
                return false;
            }
            _ProjectionRead_Report_TC_Execution_Failure o = (_ProjectionRead_Report_TC_Execution_Failure) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus) && this.TMstatus.equals(o.TMstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus, TMstatus, TMpool);
        }
    }

    public static class _ProjectionRead__tr_Report_TC_Execution_Failure {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionRead__tr_Report_TC_Execution_Failure(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_Report_TC_Execution_Failure)) {
                return false;
            }
            _ProjectionRead__tr_Report_TC_Execution_Failure o = (_ProjectionRead__tr_Report_TC_Execution_Failure) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus, TMpool);
        }
    }

    public static class _ProjectionWrite_Report_TC_Execution_Failure {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionWrite_Report_TC_Execution_Failure(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TCstatus = TCstatus;
            this.TMstatus = TMstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TCstatus: " + this.TCstatus + "," + "TMstatus: " + this.TMstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_Report_TC_Execution_Failure)) {
                return false;
            }
            _ProjectionWrite_Report_TC_Execution_Failure o = (_ProjectionWrite_Report_TC_Execution_Failure) other;
            return this.TCstatus.equals(o.TCstatus) && this.TMstatus.equals(o.TMstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TCstatus, TMstatus, TMpool);
        }
    }

    public static class _ProjectionRead_Skip_TC_Failure_Report {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead_Skip_TC_Failure_Report(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_Skip_TC_Failure_Report)) {
                return false;
            }
            _ProjectionRead_Skip_TC_Failure_Report o = (_ProjectionRead_Skip_TC_Failure_Report) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionRead__tr_Skip_TC_Failure_Report {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead__tr_Skip_TC_Failure_Report(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_Skip_TC_Failure_Report)) {
                return false;
            }
            _ProjectionRead__tr_Skip_TC_Failure_Report o = (_ProjectionRead__tr_Skip_TC_Failure_Report) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionWrite_Skip_TC_Failure_Report {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionWrite_Skip_TC_Failure_Report(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_Skip_TC_Failure_Report)) {
                return false;
            }
            _ProjectionWrite_Skip_TC_Failure_Report o = (_ProjectionWrite_Skip_TC_Failure_Report) other;
            return this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCstatus);
        }
    }

    public static class _ProjectionRead_Drop_TC {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead_Drop_TC(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_Drop_TC)) {
                return false;
            }
            _ProjectionRead_Drop_TC o = (_ProjectionRead_Drop_TC) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionRead__tr_Drop_TC {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead__tr_Drop_TC(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_Drop_TC)) {
                return false;
            }
            _ProjectionRead__tr_Drop_TC o = (_ProjectionRead__tr_Drop_TC) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionWrite_Drop_TC {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionWrite_Drop_TC(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_Drop_TC)) {
                return false;
            }
            _ProjectionWrite_Drop_TC o = (_ProjectionWrite_Drop_TC) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionRead_Produce_TM {

        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionRead_Produce_TM(BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TMstatus = TMstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TMstatus: " + this.TMstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_Produce_TM)) {
                return false;
            }
            _ProjectionRead_Produce_TM o = (_ProjectionRead_Produce_TM) other;
            return this.TMstatus.equals(o.TMstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TMstatus, TMpool);
        }
    }

    public static class _ProjectionRead__tr_Produce_TM {

        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionRead__tr_Produce_TM(BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_Produce_TM)) {
                return false;
            }
            _ProjectionRead__tr_Produce_TM o = (_ProjectionRead__tr_Produce_TM) other;
            return this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TMpool);
        }
    }

    public static class _ProjectionWrite_Produce_TM {

        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionWrite_Produce_TM(BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TMstatus = TMstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TMstatus: " + this.TMstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_Produce_TM)) {
                return false;
            }
            _ProjectionWrite_Produce_TM o = (_ProjectionWrite_Produce_TM) other;
            return this.TMstatus.equals(o.TMstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TMstatus, TMpool);
        }
    }

    public static class _ProjectionRead_Pass_TM {

        public BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET> TMbuffer;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionRead_Pass_TM(BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET> TMbuffer, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TMbuffer = TMbuffer;
            this.TMstatus = TMstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TMbuffer: " + this.TMbuffer + "," + "TMstatus: " + this.TMstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_Pass_TM)) {
                return false;
            }
            _ProjectionRead_Pass_TM o = (_ProjectionRead_Pass_TM) other;
            return this.TMbuffer.equals(o.TMbuffer) && this.TMstatus.equals(o.TMstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TMbuffer, TMstatus, TMpool);
        }
    }

    public static class _ProjectionRead__tr_Pass_TM {

        public BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET> TMbuffer;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionRead__tr_Pass_TM(BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET> TMbuffer, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TMbuffer = TMbuffer;
            this.TMstatus = TMstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TMbuffer: " + this.TMbuffer + "," + "TMstatus: " + this.TMstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_Pass_TM)) {
                return false;
            }
            _ProjectionRead__tr_Pass_TM o = (_ProjectionRead__tr_Pass_TM) other;
            return this.TMbuffer.equals(o.TMbuffer) && this.TMstatus.equals(o.TMstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TMbuffer, TMstatus, TMpool);
        }
    }

    public static class _ProjectionWrite_Pass_TM {

        public BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET> TMbuffer;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;

        public _ProjectionWrite_Pass_TM(BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET> TMbuffer, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus) {
            this.TMbuffer = TMbuffer;
            this.TMstatus = TMstatus;
        }

        public String toString() {
            return "{" + "TMbuffer: " + this.TMbuffer + "," + "TMstatus: " + this.TMstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_Pass_TM)) {
                return false;
            }
            _ProjectionWrite_Pass_TM o = (_ProjectionWrite_Pass_TM) other;
            return this.TMbuffer.equals(o.TMbuffer) && this.TMstatus.equals(o.TMstatus);
        }

        public int hashCode() {
            return Objects.hash(TMbuffer, TMstatus);
        }
    }

    public static class _ProjectionRead_Cancel_TM {

        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionRead_Cancel_TM(BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TMstatus = TMstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TMstatus: " + this.TMstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_Cancel_TM)) {
                return false;
            }
            _ProjectionRead_Cancel_TM o = (_ProjectionRead_Cancel_TM) other;
            return this.TMstatus.equals(o.TMstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TMstatus, TMpool);
        }
    }

    public static class _ProjectionRead__tr_Cancel_TM {

        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionRead__tr_Cancel_TM(BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TMstatus = TMstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TMstatus: " + this.TMstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_Cancel_TM)) {
                return false;
            }
            _ProjectionRead__tr_Cancel_TM o = (_ProjectionRead__tr_Cancel_TM) other;
            return this.TMstatus.equals(o.TMstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TMstatus, TMpool);
        }
    }

    public static class _ProjectionWrite_Cancel_TM {

        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;

        public _ProjectionWrite_Cancel_TM(BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus) {
            this.TMstatus = TMstatus;
        }

        public String toString() {
            return "{" + "TMstatus: " + this.TMstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_Cancel_TM)) {
                return false;
            }
            _ProjectionWrite_Cancel_TM o = (_ProjectionWrite_Cancel_TM) other;
            return this.TMstatus.equals(o.TMstatus);
        }

        public int hashCode() {
            return Objects.hash(TMstatus);
        }
    }

    public static class _ProjectionRead_Drop_TM {

        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionRead_Drop_TM(BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TMstatus = TMstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TMstatus: " + this.TMstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_Drop_TM)) {
                return false;
            }
            _ProjectionRead_Drop_TM o = (_ProjectionRead_Drop_TM) other;
            return this.TMstatus.equals(o.TMstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TMstatus, TMpool);
        }
    }

    public static class _ProjectionRead__tr_Drop_TM {

        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionRead__tr_Drop_TM(BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TMstatus = TMstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TMstatus: " + this.TMstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_Drop_TM)) {
                return false;
            }
            _ProjectionRead__tr_Drop_TM o = (_ProjectionRead__tr_Drop_TM) other;
            return this.TMstatus.equals(o.TMstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TMstatus, TMpool);
        }
    }

    public static class _ProjectionWrite_Drop_TM {

        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionWrite_Drop_TM(BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TMstatus = TMstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TMstatus: " + this.TMstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_Drop_TM)) {
                return false;
            }
            _ProjectionWrite_Drop_TM o = (_ProjectionWrite_Drop_TM) other;
            return this.TMstatus.equals(o.TMstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TMstatus, TMpool);
        }
    }

    public static class _ProjectionRead_env_Deliver_TM {

        public BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET> TMbuffer;

        public _ProjectionRead_env_Deliver_TM(BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET> TMbuffer) {
            this.TMbuffer = TMbuffer;
        }

        public String toString() {
            return "{" + "TMbuffer: " + this.TMbuffer + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_env_Deliver_TM)) {
                return false;
            }
            _ProjectionRead_env_Deliver_TM o = (_ProjectionRead_env_Deliver_TM) other;
            return this.TMbuffer.equals(o.TMbuffer);
        }

        public int hashCode() {
            return Objects.hash(TMbuffer);
        }
    }

    public static class _ProjectionRead__tr_env_Deliver_TM {

        public BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET> TMbuffer;

        public _ProjectionRead__tr_env_Deliver_TM(BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET> TMbuffer) {
            this.TMbuffer = TMbuffer;
        }

        public String toString() {
            return "{" + "TMbuffer: " + this.TMbuffer + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_env_Deliver_TM)) {
                return false;
            }
            _ProjectionRead__tr_env_Deliver_TM o = (_ProjectionRead__tr_env_Deliver_TM) other;
            return this.TMbuffer.equals(o.TMbuffer);
        }

        public int hashCode() {
            return Objects.hash(TMbuffer);
        }
    }

    public static class _ProjectionWrite_env_Deliver_TM {

        public BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET> TMbuffer;

        public _ProjectionWrite_env_Deliver_TM(BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET> TMbuffer) {
            this.TMbuffer = TMbuffer;
        }

        public String toString() {
            return "{" + "TMbuffer: " + this.TMbuffer + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_env_Deliver_TM)) {
                return false;
            }
            _ProjectionWrite_env_Deliver_TM o = (_ProjectionWrite_env_Deliver_TM) other;
            return this.TMbuffer.equals(o.TMbuffer);
        }

        public int hashCode() {
            return Objects.hash(TMbuffer);
        }
    }

    public static class _ProjectionRead__check_inv_1 {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead__check_inv_1(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_1)) {
                return false;
            }
            _ProjectionRead__check_inv_1 o = (_ProjectionRead__check_inv_1) other;
            return this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCstatus);
        }
    }

    public static class _ProjectionRead__check_inv_2 {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead__check_inv_2(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_2)) {
                return false;
            }
            _ProjectionRead__check_inv_2 o = (_ProjectionRead__check_inv_2) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionRead__check_inv_3 {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;

        public _ProjectionRead__check_inv_3(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool, BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus) {
            this.TCpool = TCpool;
            this.TCstatus = TCstatus;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "," + "TCstatus: " + this.TCstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_3)) {
                return false;
            }
            _ProjectionRead__check_inv_3 o = (_ProjectionRead__check_inv_3) other;
            return this.TCpool.equals(o.TCpool) && this.TCstatus.equals(o.TCstatus);
        }

        public int hashCode() {
            return Objects.hash(TCpool, TCstatus);
        }
    }

    public static class _ProjectionRead__check_inv_4 {

        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;

        public _ProjectionRead__check_inv_4(BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus) {
            this.TMstatus = TMstatus;
        }

        public String toString() {
            return "{" + "TMstatus: " + this.TMstatus + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_4)) {
                return false;
            }
            _ProjectionRead__check_inv_4 o = (_ProjectionRead__check_inv_4) other;
            return this.TMstatus.equals(o.TMstatus);
        }

        public int hashCode() {
            return Objects.hash(TMstatus);
        }
    }

    public static class _ProjectionRead__check_inv_5 {

        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;
        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionRead__check_inv_5(BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus, BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TMstatus = TMstatus;
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TMstatus: " + this.TMstatus + "," + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_5)) {
                return false;
            }
            _ProjectionRead__check_inv_5 o = (_ProjectionRead__check_inv_5) other;
            return this.TMstatus.equals(o.TMstatus) && this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TMstatus, TMpool);
        }
    }

    public static class _ProjectionRead__check_inv_6 {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET> TCbuffer;

        public _ProjectionRead__check_inv_6(BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET> TCbuffer) {
            this.TCbuffer = TCbuffer;
        }

        public String toString() {
            return "{" + "TCbuffer: " + this.TCbuffer + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_6)) {
                return false;
            }
            _ProjectionRead__check_inv_6 o = (_ProjectionRead__check_inv_6) other;
            return this.TCbuffer.equals(o.TCbuffer);
        }

        public int hashCode() {
            return Objects.hash(TCbuffer);
        }
    }

    public static class _ProjectionRead__check_inv_7 {

        public BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET> TMbuffer;

        public _ProjectionRead__check_inv_7(BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET> TMbuffer) {
            this.TMbuffer = TMbuffer;
        }

        public String toString() {
            return "{" + "TMbuffer: " + this.TMbuffer + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_7)) {
                return false;
            }
            _ProjectionRead__check_inv_7 o = (_ProjectionRead__check_inv_7) other;
            return this.TMbuffer.equals(o.TMbuffer);
        }

        public int hashCode() {
            return Objects.hash(TMbuffer);
        }
    }

    public static class _ProjectionRead__check_inv_8 {

        public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;

        public _ProjectionRead__check_inv_8(BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool) {
            this.TCpool = TCpool;
        }

        public String toString() {
            return "{" + "TCpool: " + this.TCpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_8)) {
                return false;
            }
            _ProjectionRead__check_inv_8 o = (_ProjectionRead__check_inv_8) other;
            return this.TCpool.equals(o.TCpool);
        }

        public int hashCode() {
            return Objects.hash(TCpool);
        }
    }

    public static class _ProjectionRead__check_inv_9 {

        public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

        public _ProjectionRead__check_inv_9(BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool) {
            this.TMpool = TMpool;
        }

        public String toString() {
            return "{" + "TMpool: " + this.TMpool + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_9)) {
                return false;
            }
            _ProjectionRead__check_inv_9 o = (_ProjectionRead__check_inv_9) other;
            return this.TMpool.equals(o.TMpool);
        }

        public int hashCode() {
            return Objects.hash(TMpool);
        }
    }




    private static BSet<TC_SET> VALID_TCS;


    public enum TC_SET implements BObject {
        TC_SET1, 
        TC_SET2;

        public BBoolean equal(TC_SET o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(TC_SET o) {
            return new BBoolean(this != o);
        }
    }

    public enum TC_STATUSES implements BObject {
        TC_Unchecked, 
        TC_Accepted, 
        TC_Rejected, 
        TC_Waiting_for_Execution, 
        TC_Successfully_Executed, 
        TC_Execution_Failed, 
        TC_Removable;

        public BBoolean equal(TC_STATUSES o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(TC_STATUSES o) {
            return new BBoolean(this != o);
        }
    }

    public enum TM_STATUSES implements BObject {
        TM_Effective, 
        TM_Removable;

        public BBoolean equal(TM_STATUSES o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(TM_STATUSES o) {
            return new BBoolean(this != o);
        }
    }

    public enum PACKET_START_ADDRESSES_IN_TC_BUFFER implements BObject {
        PACKET_START_ADDRESSES_IN_TC_BUFFER1, 
        PACKET_START_ADDRESSES_IN_TC_BUFFER2;

        public BBoolean equal(PACKET_START_ADDRESSES_IN_TC_BUFFER o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(PACKET_START_ADDRESSES_IN_TC_BUFFER o) {
            return new BBoolean(this != o);
        }
    }

    public enum PACKET_START_ADDRESSES_IN_TC_POOL implements BObject {
        PACKET_START_ADDRESSES_IN_TC_POOL1, 
        PACKET_START_ADDRESSES_IN_TC_POOL2;

        public BBoolean equal(PACKET_START_ADDRESSES_IN_TC_POOL o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(PACKET_START_ADDRESSES_IN_TC_POOL o) {
            return new BBoolean(this != o);
        }
    }

    public enum PACKET_START_ADDRESSES_IN_TM_BUFFER implements BObject {
        PACKET_START_ADDRESSES_IN_TM_BUFFER1, 
        PACKET_START_ADDRESSES_IN_TM_BUFFER2;

        public BBoolean equal(PACKET_START_ADDRESSES_IN_TM_BUFFER o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(PACKET_START_ADDRESSES_IN_TM_BUFFER o) {
            return new BBoolean(this != o);
        }
    }

    public enum PACKET_START_ADDRESSES_IN_TM_POOL implements BObject {
        PACKET_START_ADDRESSES_IN_TM_POOL1, 
        PACKET_START_ADDRESSES_IN_TM_POOL2;

        public BBoolean equal(PACKET_START_ADDRESSES_IN_TM_POOL o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(PACKET_START_ADDRESSES_IN_TM_POOL o) {
            return new BBoolean(this != o);
        }
    }

    public enum TM_SET implements BObject {
        TM_SET1, 
        TM_SET2;

        public BBoolean equal(TM_SET o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(TM_SET o) {
            return new BBoolean(this != o);
        }
    }

    private static BSet<TC_SET> _TC_SET = new BSet<TC_SET>(TC_SET.TC_SET1, TC_SET.TC_SET2);
    private static BSet<TC_STATUSES> _TC_STATUSES = new BSet<TC_STATUSES>(TC_STATUSES.TC_Unchecked, TC_STATUSES.TC_Accepted, TC_STATUSES.TC_Rejected, TC_STATUSES.TC_Waiting_for_Execution, TC_STATUSES.TC_Successfully_Executed, TC_STATUSES.TC_Execution_Failed, TC_STATUSES.TC_Removable);
    private static BSet<TM_STATUSES> _TM_STATUSES = new BSet<TM_STATUSES>(TM_STATUSES.TM_Effective, TM_STATUSES.TM_Removable);
    private static BSet<PACKET_START_ADDRESSES_IN_TC_BUFFER> _PACKET_START_ADDRESSES_IN_TC_BUFFER = new BSet<PACKET_START_ADDRESSES_IN_TC_BUFFER>(PACKET_START_ADDRESSES_IN_TC_BUFFER.PACKET_START_ADDRESSES_IN_TC_BUFFER1, PACKET_START_ADDRESSES_IN_TC_BUFFER.PACKET_START_ADDRESSES_IN_TC_BUFFER2);
    private static BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _PACKET_START_ADDRESSES_IN_TC_POOL = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(PACKET_START_ADDRESSES_IN_TC_POOL.PACKET_START_ADDRESSES_IN_TC_POOL1, PACKET_START_ADDRESSES_IN_TC_POOL.PACKET_START_ADDRESSES_IN_TC_POOL2);
    private static BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER> _PACKET_START_ADDRESSES_IN_TM_BUFFER = new BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER>(PACKET_START_ADDRESSES_IN_TM_BUFFER.PACKET_START_ADDRESSES_IN_TM_BUFFER1, PACKET_START_ADDRESSES_IN_TM_BUFFER.PACKET_START_ADDRESSES_IN_TM_BUFFER2);
    private static BSet<PACKET_START_ADDRESSES_IN_TM_POOL> _PACKET_START_ADDRESSES_IN_TM_POOL = new BSet<PACKET_START_ADDRESSES_IN_TM_POOL>(PACKET_START_ADDRESSES_IN_TM_POOL.PACKET_START_ADDRESSES_IN_TM_POOL1, PACKET_START_ADDRESSES_IN_TM_POOL.PACKET_START_ADDRESSES_IN_TM_POOL2);
    private static BSet<TM_SET> _TM_SET = new BSet<TM_SET>(TM_SET.TM_SET1, TM_SET.TM_SET2);

    private BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> TCstatus;
    private BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> TMstatus;
    private BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET> TCbuffer;
    private BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> TCpool;
    private BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET> TMbuffer;
    private BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> TMpool;

    static {
        VALID_TCS = new BSet<TC_SET>(TC_SET.TC_SET1);
    }

    public obsw_M001_2() {
        TCbuffer = new BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET>();
        TMbuffer = new BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>();
        TCpool = new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>();
        TMpool = new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>();
        TCstatus = new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>();
        TMstatus = new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>();
    }

    public obsw_M001_2(obsw_M001_2 copy) {
        this.VALID_TCS = copy.VALID_TCS;
        this.TCstatus = copy.TCstatus;
        this.TMstatus = copy.TMstatus;
        this.TCbuffer = copy.TCbuffer;
        this.TCpool = copy.TCpool;
        this.TMbuffer = copy.TMbuffer;
        this.TMpool = copy.TMpool;
    }

    public void env_Receive_TC(TC_SET tc, PACKET_START_ADDRESSES_IN_TC_BUFFER tc_pointer) {
        TCbuffer = TCbuffer.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET>(new BTuple<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET>(tc_pointer, tc)));

    }

    public void Poll_TC(PACKET_START_ADDRESSES_IN_TC_POOL tc_handler, PACKET_START_ADDRESSES_IN_TC_BUFFER tc_pointer) {
        BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET> _ld_TCbuffer = TCbuffer;
        BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> _ld_TCpool = TCpool;
        BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> _ld_TCstatus = TCstatus;
        TCpool = _ld_TCpool.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>(new BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>(tc_handler, _ld_TCbuffer.functionCall(tc_pointer))));
        TCbuffer = _ld_TCbuffer.domainSubstraction(new BSet<PACKET_START_ADDRESSES_IN_TC_BUFFER>(tc_pointer));
        TCstatus = _ld_TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(tc_handler, TC_STATUSES.TC_Unchecked)));

    }

    public void Accept_TC(PACKET_START_ADDRESSES_IN_TC_POOL tc_handler) {
        TCstatus = TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(tc_handler, TC_STATUSES.TC_Accepted)));

    }

    public void Reject_TC(PACKET_START_ADDRESSES_IN_TC_POOL tc_handler) {
        TCstatus = TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(tc_handler, TC_STATUSES.TC_Rejected)));

    }

    public void Report_TC_Acceptance(PACKET_START_ADDRESSES_IN_TC_POOL tc_handler, TM_SET tm, PACKET_START_ADDRESSES_IN_TM_POOL tm_handler) {
        BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> _ld_TMpool = TMpool;

        BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> _ld_TMstatus = TMstatus;
        BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> _ld_TCstatus = TCstatus;
        TMpool = _ld_TMpool.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>(new BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>(tm_handler, tm)));
        TCstatus = _ld_TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(tc_handler, TC_STATUSES.TC_Waiting_for_Execution)));
        TMstatus = _ld_TMstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>(new BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>(tm_handler, TM_STATUSES.TM_Effective)));

    }

    public void Skip_TC_Acceptance_Report(PACKET_START_ADDRESSES_IN_TC_POOL tc_handler) {
        TCstatus = TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(tc_handler, TC_STATUSES.TC_Waiting_for_Execution)));

    }

    public void Report_TC_Rejection(PACKET_START_ADDRESSES_IN_TC_POOL tc_handler, TM_SET tm, PACKET_START_ADDRESSES_IN_TM_POOL tm_handler) {
        BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> _ld_TMpool = TMpool;

        BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> _ld_TMstatus = TMstatus;
        BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> _ld_TCstatus = TCstatus;
        TMpool = _ld_TMpool.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>(new BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>(tm_handler, tm)));
        TCstatus = _ld_TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(tc_handler, TC_STATUSES.TC_Removable)));
        TMstatus = _ld_TMstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>(new BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>(tm_handler, TM_STATUSES.TM_Effective)));

    }

    public void Skip_TC_Rejection_Report(PACKET_START_ADDRESSES_IN_TC_POOL tc_handler) {
        TCstatus = TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(tc_handler, TC_STATUSES.TC_Removable)));

    }

    public void Execute_TC_Successfully(PACKET_START_ADDRESSES_IN_TC_POOL tc_handler) {
        TCstatus = TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(tc_handler, TC_STATUSES.TC_Successfully_Executed)));

    }

    public void Reset_TM_Buffer(PACKET_START_ADDRESSES_IN_TC_POOL tc_handler) {
        BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> _ld_TCstatus = TCstatus;
        TMbuffer = new BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>();
        TCstatus = _ld_TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(tc_handler, TC_STATUSES.TC_Successfully_Executed)));

    }

    public void Fail_TC_Execution(PACKET_START_ADDRESSES_IN_TC_POOL tc_handler) {
        TCstatus = TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(tc_handler, TC_STATUSES.TC_Execution_Failed)));

    }

    public void Report_TC_Execution_Success(PACKET_START_ADDRESSES_IN_TC_POOL tc_handler, TM_SET tm, PACKET_START_ADDRESSES_IN_TM_POOL tm_handler) {
        BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> _ld_TMpool = TMpool;

        BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> _ld_TMstatus = TMstatus;
        BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> _ld_TCstatus = TCstatus;
        TMpool = _ld_TMpool.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>(new BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>(tm_handler, tm)));
        TCstatus = _ld_TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(tc_handler, TC_STATUSES.TC_Removable)));
        TMstatus = _ld_TMstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>(new BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>(tm_handler, TM_STATUSES.TM_Effective)));

    }

    public void Skip_TC_Success_Report(PACKET_START_ADDRESSES_IN_TC_POOL tc_handler) {
        TCstatus = TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(tc_handler, TC_STATUSES.TC_Removable)));

    }

    public void Report_TC_Execution_Failure(PACKET_START_ADDRESSES_IN_TC_POOL tc_handler, TM_SET tm, PACKET_START_ADDRESSES_IN_TM_POOL tm_handler) {
        BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> _ld_TMpool = TMpool;

        BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> _ld_TMstatus = TMstatus;
        BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> _ld_TCstatus = TCstatus;
        TMpool = _ld_TMpool.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>(new BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>(tm_handler, tm)));
        TCstatus = _ld_TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(tc_handler, TC_STATUSES.TC_Removable)));
        TMstatus = _ld_TMstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>(new BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>(tm_handler, TM_STATUSES.TM_Effective)));

    }

    public void Skip_TC_Failure_Report(PACKET_START_ADDRESSES_IN_TC_POOL tc_handler) {
        TCstatus = TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(tc_handler, TC_STATUSES.TC_Removable)));

    }

    public void Drop_TC(PACKET_START_ADDRESSES_IN_TC_POOL tc_handler) {
        BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> _ld_TCpool = TCpool;
        BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> _ld_TCstatus = TCstatus;
        TCpool = _ld_TCpool.domainSubstraction(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(tc_handler));
        TCstatus = _ld_TCstatus.domainSubstraction(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(tc_handler));

    }

    public void Produce_TM(TM_SET tm, PACKET_START_ADDRESSES_IN_TM_POOL tm_handler) {
        BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> _ld_TMpool = TMpool;

        BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> _ld_TMstatus = TMstatus;
        TMpool = _ld_TMpool.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>(new BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>(tm_handler, tm)));
        TMstatus = _ld_TMstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>(new BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>(tm_handler, TM_STATUSES.TM_Effective)));

    }

    public void Pass_TM(PACKET_START_ADDRESSES_IN_TM_POOL tm_handler, PACKET_START_ADDRESSES_IN_TM_BUFFER tm_pointer) {
        BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET> _ld_TMbuffer = TMbuffer;

        BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> _ld_TMstatus = TMstatus;
        TMbuffer = _ld_TMbuffer.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>(new BTuple<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>(tm_pointer, TMpool.functionCall(tm_handler))));
        TMstatus = _ld_TMstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>(new BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>(tm_handler, TM_STATUSES.TM_Removable)));

    }

    public void Cancel_TM(PACKET_START_ADDRESSES_IN_TM_POOL tm_handler) {
        TMstatus = TMstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>(new BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>(tm_handler, TM_STATUSES.TM_Removable)));

    }

    public void Drop_TM(PACKET_START_ADDRESSES_IN_TM_POOL tm_handler) {
        BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> _ld_TMpool = TMpool;

        BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> _ld_TMstatus = TMstatus;
        TMpool = _ld_TMpool.domainSubstraction(new BSet<PACKET_START_ADDRESSES_IN_TM_POOL>(tm_handler));
        TMstatus = _ld_TMstatus.domainSubstraction(new BSet<PACKET_START_ADDRESSES_IN_TM_POOL>(tm_handler));

    }

    public void env_Deliver_TM(PACKET_START_ADDRESSES_IN_TM_BUFFER tm_pointer) {
        TMbuffer = TMbuffer.domainSubstraction(new BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER>(tm_pointer));

    }

    public BSet<TC_SET> _get_VALID_TCS() {
        return VALID_TCS;
    }

    public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> _get_TCstatus() {
        return TCstatus;
    }

    public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> _get_TMstatus() {
        return TMstatus;
    }

    public BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET> _get_TCbuffer() {
        return TCbuffer;
    }

    public BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> _get_TCpool() {
        return TCpool;
    }

    public BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET> _get_TMbuffer() {
        return TMbuffer;
    }

    public BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> _get_TMpool() {
        return TMpool;
    }

    public BSet<TC_SET> _get__TC_SET() {
        return _TC_SET;
    }

    public BSet<TC_STATUSES> _get__TC_STATUSES() {
        return _TC_STATUSES;
    }

    public BSet<TM_STATUSES> _get__TM_STATUSES() {
        return _TM_STATUSES;
    }

    @Override
    public boolean equals(Object o) {
        obsw_M001_2 o1 = this;
        obsw_M001_2 o2 = (obsw_M001_2) o;
        return o1._get_TCstatus().equals(o2._get_TCstatus()) && o1._get_TMstatus().equals(o2._get_TMstatus()) && o1._get_TCbuffer().equals(o2._get_TCbuffer()) && o1._get_TCpool().equals(o2._get_TCpool()) && o1._get_TMbuffer().equals(o2._get_TMbuffer()) && o1._get_TMpool().equals(o2._get_TMpool());
    }



    @Override
    public int hashCode() {
        return this._hashCode_1();
    }

    public int _hashCode_1() {
        int result = 1;
        result = (1543 * result) ^ ((this._get_TCstatus()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_TMstatus()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_TCbuffer()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_TCpool()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_TMbuffer()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_TMpool()).hashCode() << 1);
        return result;
    }

    public int _hashCode_2() {
        int result = 1;
        result = (6151 * result) ^ ((this._get_TCstatus()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_TMstatus()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_TCbuffer()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_TCpool()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_TMbuffer()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_TMpool()).hashCode() << 1);
        return result;
    }

    @Override
    public String toString() {
        return String.join("\n", "_get_TCstatus: " + (this._get_TCstatus()).toString(), "_get_TMstatus: " + (this._get_TMstatus()).toString(), "_get_TCbuffer: " + (this._get_TCbuffer()).toString(), "_get_TCpool: " + (this._get_TCpool()).toString(), "_get_TMbuffer: " + (this._get_TMbuffer()).toString(), "_get_TMpool: " + (this._get_TMpool()).toString());
    }

    public obsw_M001_2 _copy() {
        return new obsw_M001_2(this);
    }


    public BSet<BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER>> _tr_env_Receive_TC() {
        BSet<BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER>> _ic_set_0 = new BSet<BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER>>();
        for(PACKET_START_ADDRESSES_IN_TC_BUFFER _ic_tc_pointer_1 : _PACKET_START_ADDRESSES_IN_TC_BUFFER) {
            if(TCbuffer.isNotInDomain(_ic_tc_pointer_1).booleanValue()) {
                for(TC_SET _ic_tc_1 : _TC_SET) {
                    if((_TC_SET.elementOf(_ic_tc_1)).booleanValue()) {
                        _ic_set_0 = _ic_set_0.union(new BSet<BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER>>(new BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER>(_ic_tc_1, _ic_tc_pointer_1)));
                    }

                }

            }
        }

        return _ic_set_0;
    }

    public BSet<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER>> _tr_Poll_TC() {
        BSet<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER>> _ic_set_1 = new BSet<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER>>();
        for(PACKET_START_ADDRESSES_IN_TC_BUFFER _ic_tc_pointer_1 : TCbuffer.domain()) {
            for(PACKET_START_ADDRESSES_IN_TC_POOL _ic_tc_handler_1 : _PACKET_START_ADDRESSES_IN_TC_POOL) {
                if((TCpool.isNotInDomain(_ic_tc_handler_1)).booleanValue()) {
                    _ic_set_1 = _ic_set_1.union(new BSet<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER>>(new BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER>(_ic_tc_handler_1, _ic_tc_pointer_1)));
                }

            }

        }

        return _ic_set_1;
    }

    public BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _tr_Accept_TC() {
        BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _ic_set_2 = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
        for(PACKET_START_ADDRESSES_IN_TC_POOL _ic_tc_handler_1 : TCpool.domain()) {
            if((new BBoolean(new BBoolean(VALID_TCS.elementOf(TCpool.functionCall(_ic_tc_handler_1)).booleanValue() && TCstatus.isInDomain(_ic_tc_handler_1).booleanValue()).booleanValue() && TCstatus.functionCall(_ic_tc_handler_1).equal(TC_STATUSES.TC_Unchecked).booleanValue())).booleanValue()) {
                _ic_set_2 = _ic_set_2.union(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
            }

        }

        return _ic_set_2;
    }

    public BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _tr_Reject_TC() {
        BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _ic_set_3 = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
        for(PACKET_START_ADDRESSES_IN_TC_POOL _ic_tc_handler_1 : TCpool.domain()) {
            if((new BBoolean(TCstatus.isInDomain(_ic_tc_handler_1).booleanValue() && TCstatus.functionCall(_ic_tc_handler_1).equal(TC_STATUSES.TC_Unchecked).booleanValue())).booleanValue()) {
                _ic_set_3 = _ic_set_3.union(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
            }

        }

        return _ic_set_3;
    }

    public BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> _tr_Report_TC_Acceptance() {
        BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> _ic_set_4 = new BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>();
        for(PACKET_START_ADDRESSES_IN_TC_POOL _ic_tc_handler_1 : TCpool.domain()) {
            if(TCstatus.isInDomain(_ic_tc_handler_1).booleanValue()) {
                if(TCstatus.functionCall(_ic_tc_handler_1).equal(TC_STATUSES.TC_Accepted).booleanValue()) {
                    for(TM_SET _ic_tm_1 : _TM_SET) {
                        for(PACKET_START_ADDRESSES_IN_TM_POOL _ic_tm_handler_1 : _PACKET_START_ADDRESSES_IN_TM_POOL) {
                            if((TMpool.isNotInDomain(_ic_tm_handler_1)).booleanValue()) {
                                _ic_set_4 = _ic_set_4.union(new BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>(new BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>(new BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>(_ic_tc_handler_1, _ic_tm_1), _ic_tm_handler_1)));
                            }

                        }

                    }

                }
            }
        }

        return _ic_set_4;
    }

    public BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _tr_Skip_TC_Acceptance_Report() {
        BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _ic_set_5 = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
        for(PACKET_START_ADDRESSES_IN_TC_POOL _ic_tc_handler_1 : TCpool.domain()) {
            if((new BBoolean(TCstatus.isInDomain(_ic_tc_handler_1).booleanValue() && TCstatus.functionCall(_ic_tc_handler_1).equal(TC_STATUSES.TC_Accepted).booleanValue())).booleanValue()) {
                _ic_set_5 = _ic_set_5.union(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
            }

        }

        return _ic_set_5;
    }

    public BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> _tr_Report_TC_Rejection() {
        BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> _ic_set_6 = new BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>();
        for(PACKET_START_ADDRESSES_IN_TC_POOL _ic_tc_handler_1 : TCpool.domain()) {
            if(TCstatus.isInDomain(_ic_tc_handler_1).booleanValue()) {
                if(TCstatus.functionCall(_ic_tc_handler_1).equal(TC_STATUSES.TC_Rejected).booleanValue()) {
                    for(TM_SET _ic_tm_1 : _TM_SET) {
                        for(PACKET_START_ADDRESSES_IN_TM_POOL _ic_tm_handler_1 : _PACKET_START_ADDRESSES_IN_TM_POOL) {
                            if((TMpool.isNotInDomain(_ic_tm_handler_1)).booleanValue()) {
                                _ic_set_6 = _ic_set_6.union(new BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>(new BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>(new BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>(_ic_tc_handler_1, _ic_tm_1), _ic_tm_handler_1)));
                            }

                        }

                    }

                }
            }
        }

        return _ic_set_6;
    }

    public BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _tr_Skip_TC_Rejection_Report() {
        BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _ic_set_7 = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
        for(PACKET_START_ADDRESSES_IN_TC_POOL _ic_tc_handler_1 : TCpool.domain()) {
            if((new BBoolean(TCstatus.isInDomain(_ic_tc_handler_1).booleanValue() && TCstatus.functionCall(_ic_tc_handler_1).equal(TC_STATUSES.TC_Rejected).booleanValue())).booleanValue()) {
                _ic_set_7 = _ic_set_7.union(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
            }

        }

        return _ic_set_7;
    }

    public BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _tr_Execute_TC_Successfully() {
        BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _ic_set_8 = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
        for(PACKET_START_ADDRESSES_IN_TC_POOL _ic_tc_handler_1 : TCpool.domain()) {
            if((new BBoolean(TCstatus.isInDomain(_ic_tc_handler_1).booleanValue() && TCstatus.functionCall(_ic_tc_handler_1).equal(TC_STATUSES.TC_Waiting_for_Execution).booleanValue())).booleanValue()) {
                _ic_set_8 = _ic_set_8.union(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
            }

        }

        return _ic_set_8;
    }

    public BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _tr_Reset_TM_Buffer() {
        BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _ic_set_9 = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
        for(PACKET_START_ADDRESSES_IN_TC_POOL _ic_tc_handler_1 : TCpool.domain()) {
            if((new BBoolean(TCstatus.isInDomain(_ic_tc_handler_1).booleanValue() && TCstatus.functionCall(_ic_tc_handler_1).equal(TC_STATUSES.TC_Waiting_for_Execution).booleanValue())).booleanValue()) {
                _ic_set_9 = _ic_set_9.union(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
            }

        }

        return _ic_set_9;
    }

    public BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _tr_Fail_TC_Execution() {
        BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _ic_set_10 = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
        for(PACKET_START_ADDRESSES_IN_TC_POOL _ic_tc_handler_1 : TCpool.domain()) {
            if((new BBoolean(TCstatus.isInDomain(_ic_tc_handler_1).booleanValue() && TCstatus.functionCall(_ic_tc_handler_1).equal(TC_STATUSES.TC_Waiting_for_Execution).booleanValue())).booleanValue()) {
                _ic_set_10 = _ic_set_10.union(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
            }

        }

        return _ic_set_10;
    }

    public BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> _tr_Report_TC_Execution_Success() {
        BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> _ic_set_11 = new BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>();
        for(PACKET_START_ADDRESSES_IN_TC_POOL _ic_tc_handler_1 : TCpool.domain()) {
            if(TCstatus.isInDomain(_ic_tc_handler_1).booleanValue()) {
                if(TCstatus.functionCall(_ic_tc_handler_1).equal(TC_STATUSES.TC_Successfully_Executed).booleanValue()) {
                    for(TM_SET _ic_tm_1 : _TM_SET) {
                        for(PACKET_START_ADDRESSES_IN_TM_POOL _ic_tm_handler_1 : _PACKET_START_ADDRESSES_IN_TM_POOL) {
                            if((TMpool.isNotInDomain(_ic_tm_handler_1)).booleanValue()) {
                                _ic_set_11 = _ic_set_11.union(new BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>(new BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>(new BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>(_ic_tc_handler_1, _ic_tm_1), _ic_tm_handler_1)));
                            }

                        }

                    }

                }
            }
        }

        return _ic_set_11;
    }

    public BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _tr_Skip_TC_Success_Report() {
        BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _ic_set_12 = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
        for(PACKET_START_ADDRESSES_IN_TC_POOL _ic_tc_handler_1 : TCpool.domain()) {
            if((new BBoolean(TCstatus.isInDomain(_ic_tc_handler_1).booleanValue() && TCstatus.functionCall(_ic_tc_handler_1).equal(TC_STATUSES.TC_Successfully_Executed).booleanValue())).booleanValue()) {
                _ic_set_12 = _ic_set_12.union(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
            }

        }

        return _ic_set_12;
    }

    public BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> _tr_Report_TC_Execution_Failure() {
        BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> _ic_set_13 = new BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>();
        for(PACKET_START_ADDRESSES_IN_TC_POOL _ic_tc_handler_1 : TCpool.domain()) {
            if(TCstatus.isInDomain(_ic_tc_handler_1).booleanValue()) {
                if(TCstatus.functionCall(_ic_tc_handler_1).equal(TC_STATUSES.TC_Execution_Failed).booleanValue()) {
                    for(TM_SET _ic_tm_1 : _TM_SET) {
                        for(PACKET_START_ADDRESSES_IN_TM_POOL _ic_tm_handler_1 : _PACKET_START_ADDRESSES_IN_TM_POOL) {
                            if((TMpool.isNotInDomain(_ic_tm_handler_1)).booleanValue()) {
                                _ic_set_13 = _ic_set_13.union(new BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>(new BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>(new BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>(_ic_tc_handler_1, _ic_tm_1), _ic_tm_handler_1)));
                            }

                        }

                    }

                }
            }
        }

        return _ic_set_13;
    }

    public BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _tr_Skip_TC_Failure_Report() {
        BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _ic_set_14 = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
        for(PACKET_START_ADDRESSES_IN_TC_POOL _ic_tc_handler_1 : TCpool.domain()) {
            if((new BBoolean(TCstatus.isInDomain(_ic_tc_handler_1).booleanValue() && TCstatus.functionCall(_ic_tc_handler_1).equal(TC_STATUSES.TC_Execution_Failed).booleanValue())).booleanValue()) {
                _ic_set_14 = _ic_set_14.union(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
            }

        }

        return _ic_set_14;
    }

    public BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _tr_Drop_TC() {
        BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _ic_set_15 = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
        for(PACKET_START_ADDRESSES_IN_TC_POOL _ic_tc_handler_1 : TCpool.domain()) {
            if((new BBoolean(TCstatus.isInDomain(_ic_tc_handler_1).booleanValue() && TCstatus.functionCall(_ic_tc_handler_1).equal(TC_STATUSES.TC_Removable).booleanValue())).booleanValue()) {
                _ic_set_15 = _ic_set_15.union(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
            }

        }

        return _ic_set_15;
    }

    public BSet<BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL>> _tr_Produce_TM() {
        BSet<BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL>> _ic_set_16 = new BSet<BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL>>();
        for(TM_SET _ic_tm_1 : _TM_SET) {
            for(PACKET_START_ADDRESSES_IN_TM_POOL _ic_tm_handler_1 : _PACKET_START_ADDRESSES_IN_TM_POOL) {
                if((TMpool.isNotInDomain(_ic_tm_handler_1)).booleanValue()) {
                    _ic_set_16 = _ic_set_16.union(new BSet<BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL>>(new BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL>(_ic_tm_1, _ic_tm_handler_1)));
                }

            }

        }

        return _ic_set_16;
    }

    public BSet<BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER>> _tr_Pass_TM() {
        BSet<BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER>> _ic_set_17 = new BSet<BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER>>();
        for(PACKET_START_ADDRESSES_IN_TM_POOL _ic_tm_handler_1 : TMpool.domain()) {
            if(TMstatus.isInDomain(_ic_tm_handler_1).booleanValue()) {
                if(TMstatus.functionCall(_ic_tm_handler_1).equal(TM_STATUSES.TM_Effective).booleanValue()) {
                    for(PACKET_START_ADDRESSES_IN_TM_BUFFER _ic_tm_pointer_1 : _PACKET_START_ADDRESSES_IN_TM_BUFFER) {
                        if((TMbuffer.isNotInDomain(_ic_tm_pointer_1)).booleanValue()) {
                            _ic_set_17 = _ic_set_17.union(new BSet<BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER>>(new BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER>(_ic_tm_handler_1, _ic_tm_pointer_1)));
                        }

                    }

                }
            }
        }

        return _ic_set_17;
    }

    public BSet<PACKET_START_ADDRESSES_IN_TM_POOL> _tr_Cancel_TM() {
        BSet<PACKET_START_ADDRESSES_IN_TM_POOL> _ic_set_18 = new BSet<PACKET_START_ADDRESSES_IN_TM_POOL>();
        for(PACKET_START_ADDRESSES_IN_TM_POOL _ic_tm_handler_1 : TMpool.domain()) {
            if((new BBoolean(TMstatus.isInDomain(_ic_tm_handler_1).booleanValue() && TMstatus.functionCall(_ic_tm_handler_1).equal(TM_STATUSES.TM_Effective).booleanValue())).booleanValue()) {
                _ic_set_18 = _ic_set_18.union(new BSet<PACKET_START_ADDRESSES_IN_TM_POOL>(_ic_tm_handler_1));
            }

        }

        return _ic_set_18;
    }

    public BSet<PACKET_START_ADDRESSES_IN_TM_POOL> _tr_Drop_TM() {
        BSet<PACKET_START_ADDRESSES_IN_TM_POOL> _ic_set_19 = new BSet<PACKET_START_ADDRESSES_IN_TM_POOL>();
        for(PACKET_START_ADDRESSES_IN_TM_POOL _ic_tm_handler_1 : TMpool.domain()) {
            if((new BBoolean(TMstatus.isInDomain(_ic_tm_handler_1).booleanValue() && TMstatus.functionCall(_ic_tm_handler_1).equal(TM_STATUSES.TM_Removable).booleanValue())).booleanValue()) {
                _ic_set_19 = _ic_set_19.union(new BSet<PACKET_START_ADDRESSES_IN_TM_POOL>(_ic_tm_handler_1));
            }

        }

        return _ic_set_19;
    }

    public BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER> _tr_env_Deliver_TM() {
        BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER> _ic_set_20 = new BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER>();
        for(PACKET_START_ADDRESSES_IN_TM_BUFFER _ic_tm_pointer_1 : TMbuffer.domain()) {
            _ic_set_20 = _ic_set_20.union(new BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER>(_ic_tm_pointer_1));

        }

        return _ic_set_20;
    }

    public _ProjectionRead_Report_TC_Rejection _projected_state_for_Report_TC_Rejection() {
        return new _ProjectionRead_Report_TC_Rejection(TCpool,TCstatus,TMstatus,TMpool);
    }

    public _ProjectionRead_Report_TC_Execution_Success _projected_state_for_Report_TC_Execution_Success() {
        return new _ProjectionRead_Report_TC_Execution_Success(TCpool,TCstatus,TMstatus,TMpool);
    }

    public _ProjectionRead_Cancel_TM _projected_state_for_Cancel_TM() {
        return new _ProjectionRead_Cancel_TM(TMstatus,TMpool);
    }

    public _ProjectionRead_env_Receive_TC _projected_state_for_env_Receive_TC() {
        return new _ProjectionRead_env_Receive_TC(TCbuffer);
    }

    public _ProjectionRead_Report_TC_Execution_Failure _projected_state_for_Report_TC_Execution_Failure() {
        return new _ProjectionRead_Report_TC_Execution_Failure(TCpool,TCstatus,TMstatus,TMpool);
    }

    public _ProjectionRead_Pass_TM _projected_state_for_Pass_TM() {
        return new _ProjectionRead_Pass_TM(TMbuffer,TMstatus,TMpool);
    }

    public _ProjectionRead_Drop_TM _projected_state_for_Drop_TM() {
        return new _ProjectionRead_Drop_TM(TMstatus,TMpool);
    }

    public _ProjectionRead_Reset_TM_Buffer _projected_state_for_Reset_TM_Buffer() {
        return new _ProjectionRead_Reset_TM_Buffer(TCpool,TCstatus);
    }

    public _ProjectionRead_Skip_TC_Failure_Report _projected_state_for_Skip_TC_Failure_Report() {
        return new _ProjectionRead_Skip_TC_Failure_Report(TCpool,TCstatus);
    }

    public _ProjectionRead_Poll_TC _projected_state_for_Poll_TC() {
        return new _ProjectionRead_Poll_TC(TCbuffer,TCpool,TCstatus);
    }

    public _ProjectionRead_Skip_TC_Acceptance_Report _projected_state_for_Skip_TC_Acceptance_Report() {
        return new _ProjectionRead_Skip_TC_Acceptance_Report(TCpool,TCstatus);
    }

    public _ProjectionRead_Accept_TC _projected_state_for_Accept_TC() {
        return new _ProjectionRead_Accept_TC(TCpool,TCstatus);
    }

    public _ProjectionRead_Fail_TC_Execution _projected_state_for_Fail_TC_Execution() {
        return new _ProjectionRead_Fail_TC_Execution(TCpool,TCstatus);
    }

    public _ProjectionRead_Report_TC_Acceptance _projected_state_for_Report_TC_Acceptance() {
        return new _ProjectionRead_Report_TC_Acceptance(TCpool,TCstatus,TMstatus,TMpool);
    }

    public _ProjectionRead_Reject_TC _projected_state_for_Reject_TC() {
        return new _ProjectionRead_Reject_TC(TCpool,TCstatus);
    }

    public _ProjectionRead_Skip_TC_Rejection_Report _projected_state_for_Skip_TC_Rejection_Report() {
        return new _ProjectionRead_Skip_TC_Rejection_Report(TCpool,TCstatus);
    }

    public _ProjectionRead_env_Deliver_TM _projected_state_for_env_Deliver_TM() {
        return new _ProjectionRead_env_Deliver_TM(TMbuffer);
    }

    public _ProjectionRead_Execute_TC_Successfully _projected_state_for_Execute_TC_Successfully() {
        return new _ProjectionRead_Execute_TC_Successfully(TCpool,TCstatus);
    }

    public _ProjectionRead_Skip_TC_Success_Report _projected_state_for_Skip_TC_Success_Report() {
        return new _ProjectionRead_Skip_TC_Success_Report(TCpool,TCstatus);
    }

    public _ProjectionRead_Drop_TC _projected_state_for_Drop_TC() {
        return new _ProjectionRead_Drop_TC(TCpool,TCstatus);
    }

    public _ProjectionRead_Produce_TM _projected_state_for_Produce_TM() {
        return new _ProjectionRead_Produce_TM(TMstatus,TMpool);
    }

    public _ProjectionRead__tr_Poll_TC _projected_state_for__tr_Poll_TC() {
        return new _ProjectionRead__tr_Poll_TC(TCbuffer,TCpool);
    }

    public _ProjectionRead__tr_Reset_TM_Buffer _projected_state_for__tr_Reset_TM_Buffer() {
        return new _ProjectionRead__tr_Reset_TM_Buffer(TCpool,TCstatus);
    }

    public _ProjectionRead__tr_Drop_TM _projected_state_for__tr_Drop_TM() {
        return new _ProjectionRead__tr_Drop_TM(TMstatus,TMpool);
    }

    public _ProjectionRead__tr_env_Receive_TC _projected_state_for__tr_env_Receive_TC() {
        return new _ProjectionRead__tr_env_Receive_TC(TCbuffer);
    }

    public _ProjectionRead__tr_Accept_TC _projected_state_for__tr_Accept_TC() {
        return new _ProjectionRead__tr_Accept_TC(TCpool,TCstatus);
    }

    public _ProjectionRead__tr_Skip_TC_Failure_Report _projected_state_for__tr_Skip_TC_Failure_Report() {
        return new _ProjectionRead__tr_Skip_TC_Failure_Report(TCpool,TCstatus);
    }

    public _ProjectionRead__tr_Cancel_TM _projected_state_for__tr_Cancel_TM() {
        return new _ProjectionRead__tr_Cancel_TM(TMstatus,TMpool);
    }

    public _ProjectionRead__tr_Report_TC_Execution_Success _projected_state_for__tr_Report_TC_Execution_Success() {
        return new _ProjectionRead__tr_Report_TC_Execution_Success(TCpool,TCstatus,TMpool);
    }

    public _ProjectionRead__tr_Execute_TC_Successfully _projected_state_for__tr_Execute_TC_Successfully() {
        return new _ProjectionRead__tr_Execute_TC_Successfully(TCpool,TCstatus);
    }

    public _ProjectionRead__tr_Drop_TC _projected_state_for__tr_Drop_TC() {
        return new _ProjectionRead__tr_Drop_TC(TCpool,TCstatus);
    }

    public _ProjectionRead__tr_Skip_TC_Acceptance_Report _projected_state_for__tr_Skip_TC_Acceptance_Report() {
        return new _ProjectionRead__tr_Skip_TC_Acceptance_Report(TCpool,TCstatus);
    }

    public _ProjectionRead__tr_Report_TC_Rejection _projected_state_for__tr_Report_TC_Rejection() {
        return new _ProjectionRead__tr_Report_TC_Rejection(TCpool,TCstatus,TMpool);
    }

    public _ProjectionRead__tr_Produce_TM _projected_state_for__tr_Produce_TM() {
        return new _ProjectionRead__tr_Produce_TM(TMpool);
    }

    public _ProjectionRead__tr_Pass_TM _projected_state_for__tr_Pass_TM() {
        return new _ProjectionRead__tr_Pass_TM(TMbuffer,TMstatus,TMpool);
    }

    public _ProjectionRead__tr_Fail_TC_Execution _projected_state_for__tr_Fail_TC_Execution() {
        return new _ProjectionRead__tr_Fail_TC_Execution(TCpool,TCstatus);
    }

    public _ProjectionRead__tr_Report_TC_Acceptance _projected_state_for__tr_Report_TC_Acceptance() {
        return new _ProjectionRead__tr_Report_TC_Acceptance(TCpool,TCstatus,TMpool);
    }

    public _ProjectionRead__tr_Reject_TC _projected_state_for__tr_Reject_TC() {
        return new _ProjectionRead__tr_Reject_TC(TCpool,TCstatus);
    }

    public _ProjectionRead__tr_Skip_TC_Success_Report _projected_state_for__tr_Skip_TC_Success_Report() {
        return new _ProjectionRead__tr_Skip_TC_Success_Report(TCpool,TCstatus);
    }

    public _ProjectionRead__tr_Report_TC_Execution_Failure _projected_state_for__tr_Report_TC_Execution_Failure() {
        return new _ProjectionRead__tr_Report_TC_Execution_Failure(TCpool,TCstatus,TMpool);
    }

    public _ProjectionRead__tr_env_Deliver_TM _projected_state_for__tr_env_Deliver_TM() {
        return new _ProjectionRead__tr_env_Deliver_TM(TMbuffer);
    }

    public _ProjectionRead__tr_Skip_TC_Rejection_Report _projected_state_for__tr_Skip_TC_Rejection_Report() {
        return new _ProjectionRead__tr_Skip_TC_Rejection_Report(TCpool,TCstatus);
    }

    public _ProjectionRead__check_inv_2 _projected_state_for__check_inv_2() {
        return new _ProjectionRead__check_inv_2(TCpool,TCstatus);
    }

    public _ProjectionRead__check_inv_3 _projected_state_for__check_inv_3() {
        return new _ProjectionRead__check_inv_3(TCpool,TCstatus);
    }

    public _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() {
        return new _ProjectionRead__check_inv_1(TCstatus);
    }

    public _ProjectionRead__check_inv_6 _projected_state_for__check_inv_6() {
        return new _ProjectionRead__check_inv_6(TCbuffer);
    }

    public _ProjectionRead__check_inv_7 _projected_state_for__check_inv_7() {
        return new _ProjectionRead__check_inv_7(TMbuffer);
    }

    public _ProjectionRead__check_inv_4 _projected_state_for__check_inv_4() {
        return new _ProjectionRead__check_inv_4(TMstatus);
    }

    public _ProjectionRead__check_inv_5 _projected_state_for__check_inv_5() {
        return new _ProjectionRead__check_inv_5(TMstatus,TMpool);
    }

    public _ProjectionRead__check_inv_8 _projected_state_for__check_inv_8() {
        return new _ProjectionRead__check_inv_8(TCpool);
    }

    public _ProjectionRead__check_inv_9 _projected_state_for__check_inv_9() {
        return new _ProjectionRead__check_inv_9(TMpool);
    }

    public _ProjectionWrite_Report_TC_Rejection _update_for_Report_TC_Rejection() {
        return new _ProjectionWrite_Report_TC_Rejection(TCstatus,TMstatus,TMpool);
    }

    public _ProjectionWrite_Report_TC_Execution_Success _update_for_Report_TC_Execution_Success() {
        return new _ProjectionWrite_Report_TC_Execution_Success(TCstatus,TMstatus,TMpool);
    }

    public _ProjectionWrite_Cancel_TM _update_for_Cancel_TM() {
        return new _ProjectionWrite_Cancel_TM(TMstatus);
    }

    public _ProjectionWrite_env_Receive_TC _update_for_env_Receive_TC() {
        return new _ProjectionWrite_env_Receive_TC(TCbuffer);
    }

    public _ProjectionWrite_Report_TC_Execution_Failure _update_for_Report_TC_Execution_Failure() {
        return new _ProjectionWrite_Report_TC_Execution_Failure(TCstatus,TMstatus,TMpool);
    }

    public _ProjectionWrite_Pass_TM _update_for_Pass_TM() {
        return new _ProjectionWrite_Pass_TM(TMbuffer,TMstatus);
    }

    public _ProjectionWrite_Drop_TM _update_for_Drop_TM() {
        return new _ProjectionWrite_Drop_TM(TMstatus,TMpool);
    }

    public _ProjectionWrite_Reset_TM_Buffer _update_for_Reset_TM_Buffer() {
        return new _ProjectionWrite_Reset_TM_Buffer(TCstatus,TMbuffer);
    }

    public _ProjectionWrite_Skip_TC_Failure_Report _update_for_Skip_TC_Failure_Report() {
        return new _ProjectionWrite_Skip_TC_Failure_Report(TCstatus);
    }

    public _ProjectionWrite_Poll_TC _update_for_Poll_TC() {
        return new _ProjectionWrite_Poll_TC(TCpool,TCbuffer,TCstatus);
    }

    public _ProjectionWrite_Skip_TC_Acceptance_Report _update_for_Skip_TC_Acceptance_Report() {
        return new _ProjectionWrite_Skip_TC_Acceptance_Report(TCstatus);
    }

    public _ProjectionWrite_Accept_TC _update_for_Accept_TC() {
        return new _ProjectionWrite_Accept_TC(TCstatus);
    }

    public _ProjectionWrite_Fail_TC_Execution _update_for_Fail_TC_Execution() {
        return new _ProjectionWrite_Fail_TC_Execution(TCstatus);
    }

    public _ProjectionWrite_Report_TC_Acceptance _update_for_Report_TC_Acceptance() {
        return new _ProjectionWrite_Report_TC_Acceptance(TCstatus,TMstatus,TMpool);
    }

    public _ProjectionWrite_Reject_TC _update_for_Reject_TC() {
        return new _ProjectionWrite_Reject_TC(TCstatus);
    }

    public _ProjectionWrite_Skip_TC_Rejection_Report _update_for_Skip_TC_Rejection_Report() {
        return new _ProjectionWrite_Skip_TC_Rejection_Report(TCstatus);
    }

    public _ProjectionWrite_env_Deliver_TM _update_for_env_Deliver_TM() {
        return new _ProjectionWrite_env_Deliver_TM(TMbuffer);
    }

    public _ProjectionWrite_Execute_TC_Successfully _update_for_Execute_TC_Successfully() {
        return new _ProjectionWrite_Execute_TC_Successfully(TCstatus);
    }

    public _ProjectionWrite_Skip_TC_Success_Report _update_for_Skip_TC_Success_Report() {
        return new _ProjectionWrite_Skip_TC_Success_Report(TCstatus);
    }

    public _ProjectionWrite_Drop_TC _update_for_Drop_TC() {
        return new _ProjectionWrite_Drop_TC(TCpool,TCstatus);
    }

    public _ProjectionWrite_Produce_TM _update_for_Produce_TM() {
        return new _ProjectionWrite_Produce_TM(TMstatus,TMpool);
    }

    public void _apply_update_for_Report_TC_Rejection(_ProjectionWrite_Report_TC_Rejection update) {
        this.TCstatus = update.TCstatus;
        this.TMstatus = update.TMstatus;
        this.TMpool = update.TMpool;
    }

    public void _apply_update_for_Report_TC_Execution_Success(_ProjectionWrite_Report_TC_Execution_Success update) {
        this.TCstatus = update.TCstatus;
        this.TMstatus = update.TMstatus;
        this.TMpool = update.TMpool;
    }

    public void _apply_update_for_Cancel_TM(_ProjectionWrite_Cancel_TM update) {
        this.TMstatus = update.TMstatus;
    }

    public void _apply_update_for_env_Receive_TC(_ProjectionWrite_env_Receive_TC update) {
        this.TCbuffer = update.TCbuffer;
    }

    public void _apply_update_for_Report_TC_Execution_Failure(_ProjectionWrite_Report_TC_Execution_Failure update) {
        this.TCstatus = update.TCstatus;
        this.TMstatus = update.TMstatus;
        this.TMpool = update.TMpool;
    }

    public void _apply_update_for_Pass_TM(_ProjectionWrite_Pass_TM update) {
        this.TMbuffer = update.TMbuffer;
        this.TMstatus = update.TMstatus;
    }

    public void _apply_update_for_Drop_TM(_ProjectionWrite_Drop_TM update) {
        this.TMstatus = update.TMstatus;
        this.TMpool = update.TMpool;
    }

    public void _apply_update_for_Reset_TM_Buffer(_ProjectionWrite_Reset_TM_Buffer update) {
        this.TCstatus = update.TCstatus;
        this.TMbuffer = update.TMbuffer;
    }

    public void _apply_update_for_Skip_TC_Failure_Report(_ProjectionWrite_Skip_TC_Failure_Report update) {
        this.TCstatus = update.TCstatus;
    }

    public void _apply_update_for_Poll_TC(_ProjectionWrite_Poll_TC update) {
        this.TCpool = update.TCpool;
        this.TCbuffer = update.TCbuffer;
        this.TCstatus = update.TCstatus;
    }

    public void _apply_update_for_Skip_TC_Acceptance_Report(_ProjectionWrite_Skip_TC_Acceptance_Report update) {
        this.TCstatus = update.TCstatus;
    }

    public void _apply_update_for_Accept_TC(_ProjectionWrite_Accept_TC update) {
        this.TCstatus = update.TCstatus;
    }

    public void _apply_update_for_Fail_TC_Execution(_ProjectionWrite_Fail_TC_Execution update) {
        this.TCstatus = update.TCstatus;
    }

    public void _apply_update_for_Report_TC_Acceptance(_ProjectionWrite_Report_TC_Acceptance update) {
        this.TCstatus = update.TCstatus;
        this.TMstatus = update.TMstatus;
        this.TMpool = update.TMpool;
    }

    public void _apply_update_for_Reject_TC(_ProjectionWrite_Reject_TC update) {
        this.TCstatus = update.TCstatus;
    }

    public void _apply_update_for_Skip_TC_Rejection_Report(_ProjectionWrite_Skip_TC_Rejection_Report update) {
        this.TCstatus = update.TCstatus;
    }

    public void _apply_update_for_env_Deliver_TM(_ProjectionWrite_env_Deliver_TM update) {
        this.TMbuffer = update.TMbuffer;
    }

    public void _apply_update_for_Execute_TC_Successfully(_ProjectionWrite_Execute_TC_Successfully update) {
        this.TCstatus = update.TCstatus;
    }

    public void _apply_update_for_Skip_TC_Success_Report(_ProjectionWrite_Skip_TC_Success_Report update) {
        this.TCstatus = update.TCstatus;
    }

    public void _apply_update_for_Drop_TC(_ProjectionWrite_Drop_TC update) {
        this.TCpool = update.TCpool;
        this.TCstatus = update.TCstatus;
    }

    public void _apply_update_for_Produce_TM(_ProjectionWrite_Produce_TM update) {
        this.TMstatus = update.TMstatus;
        this.TMpool = update.TMpool;
    }

    public boolean _check_inv_1() {
        return TCstatus.checkDomain(_PACKET_START_ADDRESSES_IN_TC_POOL).and(TCstatus.checkRange(_TC_STATUSES)).and(TCstatus.isFunction()).and(TCstatus.isPartial(_PACKET_START_ADDRESSES_IN_TC_POOL)).booleanValue();
    }

    public boolean _check_inv_2() {
        return TCstatus.domain().equal(TCpool.domain()).booleanValue();
    }

    public boolean _check_inv_3() {
        BBoolean _ic_boolean_21 = new BBoolean(true);
        for(PACKET_START_ADDRESSES_IN_TC_POOL _ic_tc_handler_1 : TCstatus.domain()) {
            if(!(new BBoolean(!new BSet<TC_STATUSES>(TC_STATUSES.TC_Accepted, TC_STATUSES.TC_Waiting_for_Execution, TC_STATUSES.TC_Successfully_Executed, TC_STATUSES.TC_Execution_Failed).elementOf(TCstatus.functionCall(_ic_tc_handler_1)).booleanValue() || VALID_TCS.elementOf(TCpool.functionCall(_ic_tc_handler_1)).booleanValue())).booleanValue()) {
                _ic_boolean_21 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_21.booleanValue();
    }

    public boolean _check_inv_4() {
        return TMstatus.checkDomain(_PACKET_START_ADDRESSES_IN_TM_POOL).and(TMstatus.checkRange(_TM_STATUSES)).and(TMstatus.isFunction()).and(TMstatus.isPartial(_PACKET_START_ADDRESSES_IN_TM_POOL)).booleanValue();
    }

    public boolean _check_inv_5() {
        return TMstatus.domain().equal(TMpool.domain()).booleanValue();
    }

    public boolean _check_inv_6() {
        return TCbuffer.checkDomain(_PACKET_START_ADDRESSES_IN_TC_BUFFER).and(TCbuffer.checkRange(_TC_SET)).and(TCbuffer.isFunction()).and(TCbuffer.isPartial(_PACKET_START_ADDRESSES_IN_TC_BUFFER)).booleanValue();
    }

    public boolean _check_inv_7() {
        return TMbuffer.checkDomain(_PACKET_START_ADDRESSES_IN_TM_BUFFER).and(TMbuffer.checkRange(_TM_SET)).and(TMbuffer.isFunction()).and(TMbuffer.isPartial(_PACKET_START_ADDRESSES_IN_TM_BUFFER)).booleanValue();
    }

    public boolean _check_inv_8() {
        return TCpool.checkDomain(_PACKET_START_ADDRESSES_IN_TC_POOL).and(TCpool.checkRange(_TC_SET)).and(TCpool.isFunction()).and(TCpool.isPartial(_PACKET_START_ADDRESSES_IN_TC_POOL)).booleanValue();
    }

    public boolean _check_inv_9() {
        return TMpool.checkDomain(_PACKET_START_ADDRESSES_IN_TM_POOL).and(TMpool.checkRange(_TM_SET)).and(TMpool.isFunction()).and(TMpool.isPartial(_PACKET_START_ADDRESSES_IN_TM_POOL)).booleanValue();
    }


    private static class ModelChecker {
        private final Type type;
        private final int threads;
        private final boolean isCaching;
        private final boolean isDebug;

        private final LinkedList<obsw_M001_2> unvisitedStates = new LinkedList<>();
        private final Set<obsw_M001_2> states = ConcurrentHashMap.newKeySet();
        private AtomicInteger transitions = new AtomicInteger(0);
        private ThreadPoolExecutor threadPool;
        private Object waitLock = new Object();

        private AtomicBoolean invariantViolated = new AtomicBoolean(false);
        private AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        private obsw_M001_2 counterExampleState = null;

        PersistentHashMap _OpCache_env_Receive_TC = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_env_Receive_TC = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_Poll_TC = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_Poll_TC = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_Accept_TC = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_Accept_TC = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_Reject_TC = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_Reject_TC = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_Report_TC_Acceptance = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_Report_TC_Acceptance = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_Skip_TC_Acceptance_Report = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_Skip_TC_Acceptance_Report = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_Report_TC_Rejection = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_Report_TC_Rejection = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_Skip_TC_Rejection_Report = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_Skip_TC_Rejection_Report = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_Execute_TC_Successfully = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_Execute_TC_Successfully = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_Reset_TM_Buffer = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_Reset_TM_Buffer = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_Fail_TC_Execution = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_Fail_TC_Execution = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_Report_TC_Execution_Success = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_Report_TC_Execution_Success = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_Skip_TC_Success_Report = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_Skip_TC_Success_Report = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_Report_TC_Execution_Failure = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_Report_TC_Execution_Failure = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_Skip_TC_Failure_Report = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_Skip_TC_Failure_Report = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_Drop_TC = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_Drop_TC = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_Produce_TM = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_Produce_TM = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_Pass_TM = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_Pass_TM = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_Cancel_TM = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_Cancel_TM = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_Drop_TM = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_Drop_TM = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_env_Deliver_TM = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_env_Deliver_TM = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_1 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_2 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_3 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_4 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_5 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_6 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_7 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_8 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_9 = PersistentHashMap.EMPTY;

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
            obsw_M001_2 machine = new obsw_M001_2();
            states.add(machine);
            unvisitedStates.add(machine);

            while(!unvisitedStates.isEmpty()) {
                obsw_M001_2 state = next();

                Set<obsw_M001_2> nextStates = generateNextStates(state);

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
            obsw_M001_2 machine = new obsw_M001_2();
            states.add(machine);
            unvisitedStates.add(machine);

            AtomicBoolean stopThreads = new AtomicBoolean(false);
            AtomicInteger possibleQueueChanges = new AtomicInteger(0);

            while(!unvisitedStates.isEmpty() && !stopThreads.get()) {
                possibleQueueChanges.incrementAndGet();
                obsw_M001_2 state = next();
                Runnable task = () -> {
                    Set<obsw_M001_2> nextStates = generateNextStates(state);

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

        private obsw_M001_2 next() {
            synchronized(this.unvisitedStates) {
                return switch(type) {
                    case BFS -> this.unvisitedStates.removeFirst();
                    case DFS -> this.unvisitedStates.removeLast();
                    case MIXED -> this.unvisitedStates.size() % 2 == 0 ? this.unvisitedStates.removeFirst() : this.unvisitedStates.removeLast();
                };
            }
        }

        @SuppressWarnings("unchecked")
        private Set<obsw_M001_2> generateNextStates(final obsw_M001_2 state) {
            Set<obsw_M001_2> result = new HashSet<>();
            if(isCaching) {
                _ProjectionRead__tr_env_Receive_TC read__tr_env_Receive_TC_state = state._projected_state_for__tr_env_Receive_TC();
                BSet<BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER>> _trid_1 = (BSet<BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER>>) GET.invoke(_OpCache_tr_env_Receive_TC, read__tr_env_Receive_TC_state);
                if(_trid_1 == null) {
                    _trid_1 = state._tr_env_Receive_TC();
                    _OpCache_tr_env_Receive_TC = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_env_Receive_TC, read__tr_env_Receive_TC_state, _trid_1);
                }
                for(BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER> param : _trid_1) {
                    PACKET_START_ADDRESSES_IN_TC_BUFFER _tmp_1 = param.projection2();
                    TC_SET _tmp_2 = param.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    _ProjectionRead_env_Receive_TC readState = state._projected_state_for_env_Receive_TC();
                    PersistentHashMap _OpCache_with_parameter_env_Receive_TC = (PersistentHashMap) GET.invoke(_OpCache_env_Receive_TC, param);
                    if(_OpCache_with_parameter_env_Receive_TC != null) {
                        _ProjectionWrite_env_Receive_TC writeState = (_ProjectionWrite_env_Receive_TC) GET.invoke(_OpCache_with_parameter_env_Receive_TC, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_env_Receive_TC(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.env_Receive_TC(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_env_Receive_TC();
                            _OpCache_with_parameter_env_Receive_TC = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_env_Receive_TC, readState, writeState);
                            _OpCache_env_Receive_TC = (PersistentHashMap) ASSOC.invoke(_OpCache_env_Receive_TC, param, _OpCache_with_parameter_env_Receive_TC);
                        }

                    } else {
                        copiedState.env_Receive_TC(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_env_Receive_TC writeState = copiedState._update_for_env_Receive_TC();
                        _OpCache_with_parameter_env_Receive_TC = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_env_Receive_TC = (PersistentHashMap) ASSOC.invoke(_OpCache_env_Receive_TC, param, _OpCache_with_parameter_env_Receive_TC);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_Poll_TC read__tr_Poll_TC_state = state._projected_state_for__tr_Poll_TC();
                BSet<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER>> _trid_2 = (BSet<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER>>) GET.invoke(_OpCache_tr_Poll_TC, read__tr_Poll_TC_state);
                if(_trid_2 == null) {
                    _trid_2 = state._tr_Poll_TC();
                    _OpCache_tr_Poll_TC = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_Poll_TC, read__tr_Poll_TC_state, _trid_2);
                }
                for(BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER> param : _trid_2) {
                    PACKET_START_ADDRESSES_IN_TC_BUFFER _tmp_1 = param.projection2();
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_2 = param.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    _ProjectionRead_Poll_TC readState = state._projected_state_for_Poll_TC();
                    PersistentHashMap _OpCache_with_parameter_Poll_TC = (PersistentHashMap) GET.invoke(_OpCache_Poll_TC, param);
                    if(_OpCache_with_parameter_Poll_TC != null) {
                        _ProjectionWrite_Poll_TC writeState = (_ProjectionWrite_Poll_TC) GET.invoke(_OpCache_with_parameter_Poll_TC, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_Poll_TC(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.Poll_TC(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_Poll_TC();
                            _OpCache_with_parameter_Poll_TC = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_Poll_TC, readState, writeState);
                            _OpCache_Poll_TC = (PersistentHashMap) ASSOC.invoke(_OpCache_Poll_TC, param, _OpCache_with_parameter_Poll_TC);
                        }

                    } else {
                        copiedState.Poll_TC(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_Poll_TC writeState = copiedState._update_for_Poll_TC();
                        _OpCache_with_parameter_Poll_TC = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_Poll_TC = (PersistentHashMap) ASSOC.invoke(_OpCache_Poll_TC, param, _OpCache_with_parameter_Poll_TC);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_Accept_TC read__tr_Accept_TC_state = state._projected_state_for__tr_Accept_TC();
                BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _trid_3 = (BSet<PACKET_START_ADDRESSES_IN_TC_POOL>) GET.invoke(_OpCache_tr_Accept_TC, read__tr_Accept_TC_state);
                if(_trid_3 == null) {
                    _trid_3 = state._tr_Accept_TC();
                    _OpCache_tr_Accept_TC = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_Accept_TC, read__tr_Accept_TC_state, _trid_3);
                }
                for(PACKET_START_ADDRESSES_IN_TC_POOL param : _trid_3) {
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    _ProjectionRead_Accept_TC readState = state._projected_state_for_Accept_TC();
                    PersistentHashMap _OpCache_with_parameter_Accept_TC = (PersistentHashMap) GET.invoke(_OpCache_Accept_TC, param);
                    if(_OpCache_with_parameter_Accept_TC != null) {
                        _ProjectionWrite_Accept_TC writeState = (_ProjectionWrite_Accept_TC) GET.invoke(_OpCache_with_parameter_Accept_TC, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_Accept_TC(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.Accept_TC(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_Accept_TC();
                            _OpCache_with_parameter_Accept_TC = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_Accept_TC, readState, writeState);
                            _OpCache_Accept_TC = (PersistentHashMap) ASSOC.invoke(_OpCache_Accept_TC, param, _OpCache_with_parameter_Accept_TC);
                        }

                    } else {
                        copiedState.Accept_TC(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_Accept_TC writeState = copiedState._update_for_Accept_TC();
                        _OpCache_with_parameter_Accept_TC = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_Accept_TC = (PersistentHashMap) ASSOC.invoke(_OpCache_Accept_TC, param, _OpCache_with_parameter_Accept_TC);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_Reject_TC read__tr_Reject_TC_state = state._projected_state_for__tr_Reject_TC();
                BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _trid_4 = (BSet<PACKET_START_ADDRESSES_IN_TC_POOL>) GET.invoke(_OpCache_tr_Reject_TC, read__tr_Reject_TC_state);
                if(_trid_4 == null) {
                    _trid_4 = state._tr_Reject_TC();
                    _OpCache_tr_Reject_TC = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_Reject_TC, read__tr_Reject_TC_state, _trid_4);
                }
                for(PACKET_START_ADDRESSES_IN_TC_POOL param : _trid_4) {
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    _ProjectionRead_Reject_TC readState = state._projected_state_for_Reject_TC();
                    PersistentHashMap _OpCache_with_parameter_Reject_TC = (PersistentHashMap) GET.invoke(_OpCache_Reject_TC, param);
                    if(_OpCache_with_parameter_Reject_TC != null) {
                        _ProjectionWrite_Reject_TC writeState = (_ProjectionWrite_Reject_TC) GET.invoke(_OpCache_with_parameter_Reject_TC, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_Reject_TC(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.Reject_TC(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_Reject_TC();
                            _OpCache_with_parameter_Reject_TC = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_Reject_TC, readState, writeState);
                            _OpCache_Reject_TC = (PersistentHashMap) ASSOC.invoke(_OpCache_Reject_TC, param, _OpCache_with_parameter_Reject_TC);
                        }

                    } else {
                        copiedState.Reject_TC(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_Reject_TC writeState = copiedState._update_for_Reject_TC();
                        _OpCache_with_parameter_Reject_TC = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_Reject_TC = (PersistentHashMap) ASSOC.invoke(_OpCache_Reject_TC, param, _OpCache_with_parameter_Reject_TC);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_Report_TC_Acceptance read__tr_Report_TC_Acceptance_state = state._projected_state_for__tr_Report_TC_Acceptance();
                BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> _trid_5 = (BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>) GET.invoke(_OpCache_tr_Report_TC_Acceptance, read__tr_Report_TC_Acceptance_state);
                if(_trid_5 == null) {
                    _trid_5 = state._tr_Report_TC_Acceptance();
                    _OpCache_tr_Report_TC_Acceptance = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_Report_TC_Acceptance, read__tr_Report_TC_Acceptance_state, _trid_5);
                }
                for(BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL> param : _trid_5) {
                    PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                    BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET> _tmp_2 = param.projection1();
                    TM_SET _tmp_3 = _tmp_2.projection2();
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_4 = _tmp_2.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    _ProjectionRead_Report_TC_Acceptance readState = state._projected_state_for_Report_TC_Acceptance();
                    PersistentHashMap _OpCache_with_parameter_Report_TC_Acceptance = (PersistentHashMap) GET.invoke(_OpCache_Report_TC_Acceptance, param);
                    if(_OpCache_with_parameter_Report_TC_Acceptance != null) {
                        _ProjectionWrite_Report_TC_Acceptance writeState = (_ProjectionWrite_Report_TC_Acceptance) GET.invoke(_OpCache_with_parameter_Report_TC_Acceptance, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_Report_TC_Acceptance(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.Report_TC_Acceptance(_tmp_4, _tmp_3, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_Report_TC_Acceptance();
                            _OpCache_with_parameter_Report_TC_Acceptance = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_Report_TC_Acceptance, readState, writeState);
                            _OpCache_Report_TC_Acceptance = (PersistentHashMap) ASSOC.invoke(_OpCache_Report_TC_Acceptance, param, _OpCache_with_parameter_Report_TC_Acceptance);
                        }

                    } else {
                        copiedState.Report_TC_Acceptance(_tmp_4, _tmp_3, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_Report_TC_Acceptance writeState = copiedState._update_for_Report_TC_Acceptance();
                        _OpCache_with_parameter_Report_TC_Acceptance = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_Report_TC_Acceptance = (PersistentHashMap) ASSOC.invoke(_OpCache_Report_TC_Acceptance, param, _OpCache_with_parameter_Report_TC_Acceptance);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_Skip_TC_Acceptance_Report read__tr_Skip_TC_Acceptance_Report_state = state._projected_state_for__tr_Skip_TC_Acceptance_Report();
                BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _trid_6 = (BSet<PACKET_START_ADDRESSES_IN_TC_POOL>) GET.invoke(_OpCache_tr_Skip_TC_Acceptance_Report, read__tr_Skip_TC_Acceptance_Report_state);
                if(_trid_6 == null) {
                    _trid_6 = state._tr_Skip_TC_Acceptance_Report();
                    _OpCache_tr_Skip_TC_Acceptance_Report = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_Skip_TC_Acceptance_Report, read__tr_Skip_TC_Acceptance_Report_state, _trid_6);
                }
                for(PACKET_START_ADDRESSES_IN_TC_POOL param : _trid_6) {
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    _ProjectionRead_Skip_TC_Acceptance_Report readState = state._projected_state_for_Skip_TC_Acceptance_Report();
                    PersistentHashMap _OpCache_with_parameter_Skip_TC_Acceptance_Report = (PersistentHashMap) GET.invoke(_OpCache_Skip_TC_Acceptance_Report, param);
                    if(_OpCache_with_parameter_Skip_TC_Acceptance_Report != null) {
                        _ProjectionWrite_Skip_TC_Acceptance_Report writeState = (_ProjectionWrite_Skip_TC_Acceptance_Report) GET.invoke(_OpCache_with_parameter_Skip_TC_Acceptance_Report, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_Skip_TC_Acceptance_Report(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.Skip_TC_Acceptance_Report(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_Skip_TC_Acceptance_Report();
                            _OpCache_with_parameter_Skip_TC_Acceptance_Report = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_Skip_TC_Acceptance_Report, readState, writeState);
                            _OpCache_Skip_TC_Acceptance_Report = (PersistentHashMap) ASSOC.invoke(_OpCache_Skip_TC_Acceptance_Report, param, _OpCache_with_parameter_Skip_TC_Acceptance_Report);
                        }

                    } else {
                        copiedState.Skip_TC_Acceptance_Report(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_Skip_TC_Acceptance_Report writeState = copiedState._update_for_Skip_TC_Acceptance_Report();
                        _OpCache_with_parameter_Skip_TC_Acceptance_Report = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_Skip_TC_Acceptance_Report = (PersistentHashMap) ASSOC.invoke(_OpCache_Skip_TC_Acceptance_Report, param, _OpCache_with_parameter_Skip_TC_Acceptance_Report);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_Report_TC_Rejection read__tr_Report_TC_Rejection_state = state._projected_state_for__tr_Report_TC_Rejection();
                BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> _trid_7 = (BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>) GET.invoke(_OpCache_tr_Report_TC_Rejection, read__tr_Report_TC_Rejection_state);
                if(_trid_7 == null) {
                    _trid_7 = state._tr_Report_TC_Rejection();
                    _OpCache_tr_Report_TC_Rejection = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_Report_TC_Rejection, read__tr_Report_TC_Rejection_state, _trid_7);
                }
                for(BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL> param : _trid_7) {
                    PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                    BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET> _tmp_2 = param.projection1();
                    TM_SET _tmp_3 = _tmp_2.projection2();
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_4 = _tmp_2.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    _ProjectionRead_Report_TC_Rejection readState = state._projected_state_for_Report_TC_Rejection();
                    PersistentHashMap _OpCache_with_parameter_Report_TC_Rejection = (PersistentHashMap) GET.invoke(_OpCache_Report_TC_Rejection, param);
                    if(_OpCache_with_parameter_Report_TC_Rejection != null) {
                        _ProjectionWrite_Report_TC_Rejection writeState = (_ProjectionWrite_Report_TC_Rejection) GET.invoke(_OpCache_with_parameter_Report_TC_Rejection, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_Report_TC_Rejection(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.Report_TC_Rejection(_tmp_4, _tmp_3, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_Report_TC_Rejection();
                            _OpCache_with_parameter_Report_TC_Rejection = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_Report_TC_Rejection, readState, writeState);
                            _OpCache_Report_TC_Rejection = (PersistentHashMap) ASSOC.invoke(_OpCache_Report_TC_Rejection, param, _OpCache_with_parameter_Report_TC_Rejection);
                        }

                    } else {
                        copiedState.Report_TC_Rejection(_tmp_4, _tmp_3, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_Report_TC_Rejection writeState = copiedState._update_for_Report_TC_Rejection();
                        _OpCache_with_parameter_Report_TC_Rejection = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_Report_TC_Rejection = (PersistentHashMap) ASSOC.invoke(_OpCache_Report_TC_Rejection, param, _OpCache_with_parameter_Report_TC_Rejection);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_Skip_TC_Rejection_Report read__tr_Skip_TC_Rejection_Report_state = state._projected_state_for__tr_Skip_TC_Rejection_Report();
                BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _trid_8 = (BSet<PACKET_START_ADDRESSES_IN_TC_POOL>) GET.invoke(_OpCache_tr_Skip_TC_Rejection_Report, read__tr_Skip_TC_Rejection_Report_state);
                if(_trid_8 == null) {
                    _trid_8 = state._tr_Skip_TC_Rejection_Report();
                    _OpCache_tr_Skip_TC_Rejection_Report = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_Skip_TC_Rejection_Report, read__tr_Skip_TC_Rejection_Report_state, _trid_8);
                }
                for(PACKET_START_ADDRESSES_IN_TC_POOL param : _trid_8) {
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    _ProjectionRead_Skip_TC_Rejection_Report readState = state._projected_state_for_Skip_TC_Rejection_Report();
                    PersistentHashMap _OpCache_with_parameter_Skip_TC_Rejection_Report = (PersistentHashMap) GET.invoke(_OpCache_Skip_TC_Rejection_Report, param);
                    if(_OpCache_with_parameter_Skip_TC_Rejection_Report != null) {
                        _ProjectionWrite_Skip_TC_Rejection_Report writeState = (_ProjectionWrite_Skip_TC_Rejection_Report) GET.invoke(_OpCache_with_parameter_Skip_TC_Rejection_Report, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_Skip_TC_Rejection_Report(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.Skip_TC_Rejection_Report(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_Skip_TC_Rejection_Report();
                            _OpCache_with_parameter_Skip_TC_Rejection_Report = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_Skip_TC_Rejection_Report, readState, writeState);
                            _OpCache_Skip_TC_Rejection_Report = (PersistentHashMap) ASSOC.invoke(_OpCache_Skip_TC_Rejection_Report, param, _OpCache_with_parameter_Skip_TC_Rejection_Report);
                        }

                    } else {
                        copiedState.Skip_TC_Rejection_Report(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_Skip_TC_Rejection_Report writeState = copiedState._update_for_Skip_TC_Rejection_Report();
                        _OpCache_with_parameter_Skip_TC_Rejection_Report = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_Skip_TC_Rejection_Report = (PersistentHashMap) ASSOC.invoke(_OpCache_Skip_TC_Rejection_Report, param, _OpCache_with_parameter_Skip_TC_Rejection_Report);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_Execute_TC_Successfully read__tr_Execute_TC_Successfully_state = state._projected_state_for__tr_Execute_TC_Successfully();
                BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _trid_9 = (BSet<PACKET_START_ADDRESSES_IN_TC_POOL>) GET.invoke(_OpCache_tr_Execute_TC_Successfully, read__tr_Execute_TC_Successfully_state);
                if(_trid_9 == null) {
                    _trid_9 = state._tr_Execute_TC_Successfully();
                    _OpCache_tr_Execute_TC_Successfully = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_Execute_TC_Successfully, read__tr_Execute_TC_Successfully_state, _trid_9);
                }
                for(PACKET_START_ADDRESSES_IN_TC_POOL param : _trid_9) {
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    _ProjectionRead_Execute_TC_Successfully readState = state._projected_state_for_Execute_TC_Successfully();
                    PersistentHashMap _OpCache_with_parameter_Execute_TC_Successfully = (PersistentHashMap) GET.invoke(_OpCache_Execute_TC_Successfully, param);
                    if(_OpCache_with_parameter_Execute_TC_Successfully != null) {
                        _ProjectionWrite_Execute_TC_Successfully writeState = (_ProjectionWrite_Execute_TC_Successfully) GET.invoke(_OpCache_with_parameter_Execute_TC_Successfully, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_Execute_TC_Successfully(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.Execute_TC_Successfully(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_Execute_TC_Successfully();
                            _OpCache_with_parameter_Execute_TC_Successfully = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_Execute_TC_Successfully, readState, writeState);
                            _OpCache_Execute_TC_Successfully = (PersistentHashMap) ASSOC.invoke(_OpCache_Execute_TC_Successfully, param, _OpCache_with_parameter_Execute_TC_Successfully);
                        }

                    } else {
                        copiedState.Execute_TC_Successfully(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_Execute_TC_Successfully writeState = copiedState._update_for_Execute_TC_Successfully();
                        _OpCache_with_parameter_Execute_TC_Successfully = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_Execute_TC_Successfully = (PersistentHashMap) ASSOC.invoke(_OpCache_Execute_TC_Successfully, param, _OpCache_with_parameter_Execute_TC_Successfully);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_Reset_TM_Buffer read__tr_Reset_TM_Buffer_state = state._projected_state_for__tr_Reset_TM_Buffer();
                BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _trid_10 = (BSet<PACKET_START_ADDRESSES_IN_TC_POOL>) GET.invoke(_OpCache_tr_Reset_TM_Buffer, read__tr_Reset_TM_Buffer_state);
                if(_trid_10 == null) {
                    _trid_10 = state._tr_Reset_TM_Buffer();
                    _OpCache_tr_Reset_TM_Buffer = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_Reset_TM_Buffer, read__tr_Reset_TM_Buffer_state, _trid_10);
                }
                for(PACKET_START_ADDRESSES_IN_TC_POOL param : _trid_10) {
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    _ProjectionRead_Reset_TM_Buffer readState = state._projected_state_for_Reset_TM_Buffer();
                    PersistentHashMap _OpCache_with_parameter_Reset_TM_Buffer = (PersistentHashMap) GET.invoke(_OpCache_Reset_TM_Buffer, param);
                    if(_OpCache_with_parameter_Reset_TM_Buffer != null) {
                        _ProjectionWrite_Reset_TM_Buffer writeState = (_ProjectionWrite_Reset_TM_Buffer) GET.invoke(_OpCache_with_parameter_Reset_TM_Buffer, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_Reset_TM_Buffer(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.Reset_TM_Buffer(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_Reset_TM_Buffer();
                            _OpCache_with_parameter_Reset_TM_Buffer = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_Reset_TM_Buffer, readState, writeState);
                            _OpCache_Reset_TM_Buffer = (PersistentHashMap) ASSOC.invoke(_OpCache_Reset_TM_Buffer, param, _OpCache_with_parameter_Reset_TM_Buffer);
                        }

                    } else {
                        copiedState.Reset_TM_Buffer(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_Reset_TM_Buffer writeState = copiedState._update_for_Reset_TM_Buffer();
                        _OpCache_with_parameter_Reset_TM_Buffer = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_Reset_TM_Buffer = (PersistentHashMap) ASSOC.invoke(_OpCache_Reset_TM_Buffer, param, _OpCache_with_parameter_Reset_TM_Buffer);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_Fail_TC_Execution read__tr_Fail_TC_Execution_state = state._projected_state_for__tr_Fail_TC_Execution();
                BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _trid_11 = (BSet<PACKET_START_ADDRESSES_IN_TC_POOL>) GET.invoke(_OpCache_tr_Fail_TC_Execution, read__tr_Fail_TC_Execution_state);
                if(_trid_11 == null) {
                    _trid_11 = state._tr_Fail_TC_Execution();
                    _OpCache_tr_Fail_TC_Execution = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_Fail_TC_Execution, read__tr_Fail_TC_Execution_state, _trid_11);
                }
                for(PACKET_START_ADDRESSES_IN_TC_POOL param : _trid_11) {
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    _ProjectionRead_Fail_TC_Execution readState = state._projected_state_for_Fail_TC_Execution();
                    PersistentHashMap _OpCache_with_parameter_Fail_TC_Execution = (PersistentHashMap) GET.invoke(_OpCache_Fail_TC_Execution, param);
                    if(_OpCache_with_parameter_Fail_TC_Execution != null) {
                        _ProjectionWrite_Fail_TC_Execution writeState = (_ProjectionWrite_Fail_TC_Execution) GET.invoke(_OpCache_with_parameter_Fail_TC_Execution, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_Fail_TC_Execution(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.Fail_TC_Execution(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_Fail_TC_Execution();
                            _OpCache_with_parameter_Fail_TC_Execution = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_Fail_TC_Execution, readState, writeState);
                            _OpCache_Fail_TC_Execution = (PersistentHashMap) ASSOC.invoke(_OpCache_Fail_TC_Execution, param, _OpCache_with_parameter_Fail_TC_Execution);
                        }

                    } else {
                        copiedState.Fail_TC_Execution(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_Fail_TC_Execution writeState = copiedState._update_for_Fail_TC_Execution();
                        _OpCache_with_parameter_Fail_TC_Execution = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_Fail_TC_Execution = (PersistentHashMap) ASSOC.invoke(_OpCache_Fail_TC_Execution, param, _OpCache_with_parameter_Fail_TC_Execution);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_Report_TC_Execution_Success read__tr_Report_TC_Execution_Success_state = state._projected_state_for__tr_Report_TC_Execution_Success();
                BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> _trid_12 = (BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>) GET.invoke(_OpCache_tr_Report_TC_Execution_Success, read__tr_Report_TC_Execution_Success_state);
                if(_trid_12 == null) {
                    _trid_12 = state._tr_Report_TC_Execution_Success();
                    _OpCache_tr_Report_TC_Execution_Success = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_Report_TC_Execution_Success, read__tr_Report_TC_Execution_Success_state, _trid_12);
                }
                for(BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL> param : _trid_12) {
                    PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                    BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET> _tmp_2 = param.projection1();
                    TM_SET _tmp_3 = _tmp_2.projection2();
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_4 = _tmp_2.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    _ProjectionRead_Report_TC_Execution_Success readState = state._projected_state_for_Report_TC_Execution_Success();
                    PersistentHashMap _OpCache_with_parameter_Report_TC_Execution_Success = (PersistentHashMap) GET.invoke(_OpCache_Report_TC_Execution_Success, param);
                    if(_OpCache_with_parameter_Report_TC_Execution_Success != null) {
                        _ProjectionWrite_Report_TC_Execution_Success writeState = (_ProjectionWrite_Report_TC_Execution_Success) GET.invoke(_OpCache_with_parameter_Report_TC_Execution_Success, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_Report_TC_Execution_Success(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.Report_TC_Execution_Success(_tmp_4, _tmp_3, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_Report_TC_Execution_Success();
                            _OpCache_with_parameter_Report_TC_Execution_Success = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_Report_TC_Execution_Success, readState, writeState);
                            _OpCache_Report_TC_Execution_Success = (PersistentHashMap) ASSOC.invoke(_OpCache_Report_TC_Execution_Success, param, _OpCache_with_parameter_Report_TC_Execution_Success);
                        }

                    } else {
                        copiedState.Report_TC_Execution_Success(_tmp_4, _tmp_3, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_Report_TC_Execution_Success writeState = copiedState._update_for_Report_TC_Execution_Success();
                        _OpCache_with_parameter_Report_TC_Execution_Success = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_Report_TC_Execution_Success = (PersistentHashMap) ASSOC.invoke(_OpCache_Report_TC_Execution_Success, param, _OpCache_with_parameter_Report_TC_Execution_Success);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_Skip_TC_Success_Report read__tr_Skip_TC_Success_Report_state = state._projected_state_for__tr_Skip_TC_Success_Report();
                BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _trid_13 = (BSet<PACKET_START_ADDRESSES_IN_TC_POOL>) GET.invoke(_OpCache_tr_Skip_TC_Success_Report, read__tr_Skip_TC_Success_Report_state);
                if(_trid_13 == null) {
                    _trid_13 = state._tr_Skip_TC_Success_Report();
                    _OpCache_tr_Skip_TC_Success_Report = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_Skip_TC_Success_Report, read__tr_Skip_TC_Success_Report_state, _trid_13);
                }
                for(PACKET_START_ADDRESSES_IN_TC_POOL param : _trid_13) {
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    _ProjectionRead_Skip_TC_Success_Report readState = state._projected_state_for_Skip_TC_Success_Report();
                    PersistentHashMap _OpCache_with_parameter_Skip_TC_Success_Report = (PersistentHashMap) GET.invoke(_OpCache_Skip_TC_Success_Report, param);
                    if(_OpCache_with_parameter_Skip_TC_Success_Report != null) {
                        _ProjectionWrite_Skip_TC_Success_Report writeState = (_ProjectionWrite_Skip_TC_Success_Report) GET.invoke(_OpCache_with_parameter_Skip_TC_Success_Report, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_Skip_TC_Success_Report(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.Skip_TC_Success_Report(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_Skip_TC_Success_Report();
                            _OpCache_with_parameter_Skip_TC_Success_Report = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_Skip_TC_Success_Report, readState, writeState);
                            _OpCache_Skip_TC_Success_Report = (PersistentHashMap) ASSOC.invoke(_OpCache_Skip_TC_Success_Report, param, _OpCache_with_parameter_Skip_TC_Success_Report);
                        }

                    } else {
                        copiedState.Skip_TC_Success_Report(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_Skip_TC_Success_Report writeState = copiedState._update_for_Skip_TC_Success_Report();
                        _OpCache_with_parameter_Skip_TC_Success_Report = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_Skip_TC_Success_Report = (PersistentHashMap) ASSOC.invoke(_OpCache_Skip_TC_Success_Report, param, _OpCache_with_parameter_Skip_TC_Success_Report);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_Report_TC_Execution_Failure read__tr_Report_TC_Execution_Failure_state = state._projected_state_for__tr_Report_TC_Execution_Failure();
                BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> _trid_14 = (BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>) GET.invoke(_OpCache_tr_Report_TC_Execution_Failure, read__tr_Report_TC_Execution_Failure_state);
                if(_trid_14 == null) {
                    _trid_14 = state._tr_Report_TC_Execution_Failure();
                    _OpCache_tr_Report_TC_Execution_Failure = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_Report_TC_Execution_Failure, read__tr_Report_TC_Execution_Failure_state, _trid_14);
                }
                for(BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL> param : _trid_14) {
                    PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                    BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET> _tmp_2 = param.projection1();
                    TM_SET _tmp_3 = _tmp_2.projection2();
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_4 = _tmp_2.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    _ProjectionRead_Report_TC_Execution_Failure readState = state._projected_state_for_Report_TC_Execution_Failure();
                    PersistentHashMap _OpCache_with_parameter_Report_TC_Execution_Failure = (PersistentHashMap) GET.invoke(_OpCache_Report_TC_Execution_Failure, param);
                    if(_OpCache_with_parameter_Report_TC_Execution_Failure != null) {
                        _ProjectionWrite_Report_TC_Execution_Failure writeState = (_ProjectionWrite_Report_TC_Execution_Failure) GET.invoke(_OpCache_with_parameter_Report_TC_Execution_Failure, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_Report_TC_Execution_Failure(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.Report_TC_Execution_Failure(_tmp_4, _tmp_3, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_Report_TC_Execution_Failure();
                            _OpCache_with_parameter_Report_TC_Execution_Failure = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_Report_TC_Execution_Failure, readState, writeState);
                            _OpCache_Report_TC_Execution_Failure = (PersistentHashMap) ASSOC.invoke(_OpCache_Report_TC_Execution_Failure, param, _OpCache_with_parameter_Report_TC_Execution_Failure);
                        }

                    } else {
                        copiedState.Report_TC_Execution_Failure(_tmp_4, _tmp_3, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_Report_TC_Execution_Failure writeState = copiedState._update_for_Report_TC_Execution_Failure();
                        _OpCache_with_parameter_Report_TC_Execution_Failure = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_Report_TC_Execution_Failure = (PersistentHashMap) ASSOC.invoke(_OpCache_Report_TC_Execution_Failure, param, _OpCache_with_parameter_Report_TC_Execution_Failure);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_Skip_TC_Failure_Report read__tr_Skip_TC_Failure_Report_state = state._projected_state_for__tr_Skip_TC_Failure_Report();
                BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _trid_15 = (BSet<PACKET_START_ADDRESSES_IN_TC_POOL>) GET.invoke(_OpCache_tr_Skip_TC_Failure_Report, read__tr_Skip_TC_Failure_Report_state);
                if(_trid_15 == null) {
                    _trid_15 = state._tr_Skip_TC_Failure_Report();
                    _OpCache_tr_Skip_TC_Failure_Report = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_Skip_TC_Failure_Report, read__tr_Skip_TC_Failure_Report_state, _trid_15);
                }
                for(PACKET_START_ADDRESSES_IN_TC_POOL param : _trid_15) {
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    _ProjectionRead_Skip_TC_Failure_Report readState = state._projected_state_for_Skip_TC_Failure_Report();
                    PersistentHashMap _OpCache_with_parameter_Skip_TC_Failure_Report = (PersistentHashMap) GET.invoke(_OpCache_Skip_TC_Failure_Report, param);
                    if(_OpCache_with_parameter_Skip_TC_Failure_Report != null) {
                        _ProjectionWrite_Skip_TC_Failure_Report writeState = (_ProjectionWrite_Skip_TC_Failure_Report) GET.invoke(_OpCache_with_parameter_Skip_TC_Failure_Report, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_Skip_TC_Failure_Report(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.Skip_TC_Failure_Report(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_Skip_TC_Failure_Report();
                            _OpCache_with_parameter_Skip_TC_Failure_Report = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_Skip_TC_Failure_Report, readState, writeState);
                            _OpCache_Skip_TC_Failure_Report = (PersistentHashMap) ASSOC.invoke(_OpCache_Skip_TC_Failure_Report, param, _OpCache_with_parameter_Skip_TC_Failure_Report);
                        }

                    } else {
                        copiedState.Skip_TC_Failure_Report(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_Skip_TC_Failure_Report writeState = copiedState._update_for_Skip_TC_Failure_Report();
                        _OpCache_with_parameter_Skip_TC_Failure_Report = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_Skip_TC_Failure_Report = (PersistentHashMap) ASSOC.invoke(_OpCache_Skip_TC_Failure_Report, param, _OpCache_with_parameter_Skip_TC_Failure_Report);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_Drop_TC read__tr_Drop_TC_state = state._projected_state_for__tr_Drop_TC();
                BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _trid_16 = (BSet<PACKET_START_ADDRESSES_IN_TC_POOL>) GET.invoke(_OpCache_tr_Drop_TC, read__tr_Drop_TC_state);
                if(_trid_16 == null) {
                    _trid_16 = state._tr_Drop_TC();
                    _OpCache_tr_Drop_TC = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_Drop_TC, read__tr_Drop_TC_state, _trid_16);
                }
                for(PACKET_START_ADDRESSES_IN_TC_POOL param : _trid_16) {
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    _ProjectionRead_Drop_TC readState = state._projected_state_for_Drop_TC();
                    PersistentHashMap _OpCache_with_parameter_Drop_TC = (PersistentHashMap) GET.invoke(_OpCache_Drop_TC, param);
                    if(_OpCache_with_parameter_Drop_TC != null) {
                        _ProjectionWrite_Drop_TC writeState = (_ProjectionWrite_Drop_TC) GET.invoke(_OpCache_with_parameter_Drop_TC, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_Drop_TC(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.Drop_TC(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_Drop_TC();
                            _OpCache_with_parameter_Drop_TC = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_Drop_TC, readState, writeState);
                            _OpCache_Drop_TC = (PersistentHashMap) ASSOC.invoke(_OpCache_Drop_TC, param, _OpCache_with_parameter_Drop_TC);
                        }

                    } else {
                        copiedState.Drop_TC(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_Drop_TC writeState = copiedState._update_for_Drop_TC();
                        _OpCache_with_parameter_Drop_TC = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_Drop_TC = (PersistentHashMap) ASSOC.invoke(_OpCache_Drop_TC, param, _OpCache_with_parameter_Drop_TC);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_Produce_TM read__tr_Produce_TM_state = state._projected_state_for__tr_Produce_TM();
                BSet<BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL>> _trid_17 = (BSet<BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL>>) GET.invoke(_OpCache_tr_Produce_TM, read__tr_Produce_TM_state);
                if(_trid_17 == null) {
                    _trid_17 = state._tr_Produce_TM();
                    _OpCache_tr_Produce_TM = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_Produce_TM, read__tr_Produce_TM_state, _trid_17);
                }
                for(BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL> param : _trid_17) {
                    PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                    TM_SET _tmp_2 = param.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    _ProjectionRead_Produce_TM readState = state._projected_state_for_Produce_TM();
                    PersistentHashMap _OpCache_with_parameter_Produce_TM = (PersistentHashMap) GET.invoke(_OpCache_Produce_TM, param);
                    if(_OpCache_with_parameter_Produce_TM != null) {
                        _ProjectionWrite_Produce_TM writeState = (_ProjectionWrite_Produce_TM) GET.invoke(_OpCache_with_parameter_Produce_TM, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_Produce_TM(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.Produce_TM(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_Produce_TM();
                            _OpCache_with_parameter_Produce_TM = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_Produce_TM, readState, writeState);
                            _OpCache_Produce_TM = (PersistentHashMap) ASSOC.invoke(_OpCache_Produce_TM, param, _OpCache_with_parameter_Produce_TM);
                        }

                    } else {
                        copiedState.Produce_TM(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_Produce_TM writeState = copiedState._update_for_Produce_TM();
                        _OpCache_with_parameter_Produce_TM = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_Produce_TM = (PersistentHashMap) ASSOC.invoke(_OpCache_Produce_TM, param, _OpCache_with_parameter_Produce_TM);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_Pass_TM read__tr_Pass_TM_state = state._projected_state_for__tr_Pass_TM();
                BSet<BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER>> _trid_18 = (BSet<BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER>>) GET.invoke(_OpCache_tr_Pass_TM, read__tr_Pass_TM_state);
                if(_trid_18 == null) {
                    _trid_18 = state._tr_Pass_TM();
                    _OpCache_tr_Pass_TM = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_Pass_TM, read__tr_Pass_TM_state, _trid_18);
                }
                for(BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER> param : _trid_18) {
                    PACKET_START_ADDRESSES_IN_TM_BUFFER _tmp_1 = param.projection2();
                    PACKET_START_ADDRESSES_IN_TM_POOL _tmp_2 = param.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    _ProjectionRead_Pass_TM readState = state._projected_state_for_Pass_TM();
                    PersistentHashMap _OpCache_with_parameter_Pass_TM = (PersistentHashMap) GET.invoke(_OpCache_Pass_TM, param);
                    if(_OpCache_with_parameter_Pass_TM != null) {
                        _ProjectionWrite_Pass_TM writeState = (_ProjectionWrite_Pass_TM) GET.invoke(_OpCache_with_parameter_Pass_TM, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_Pass_TM(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.Pass_TM(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_Pass_TM();
                            _OpCache_with_parameter_Pass_TM = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_Pass_TM, readState, writeState);
                            _OpCache_Pass_TM = (PersistentHashMap) ASSOC.invoke(_OpCache_Pass_TM, param, _OpCache_with_parameter_Pass_TM);
                        }

                    } else {
                        copiedState.Pass_TM(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_Pass_TM writeState = copiedState._update_for_Pass_TM();
                        _OpCache_with_parameter_Pass_TM = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_Pass_TM = (PersistentHashMap) ASSOC.invoke(_OpCache_Pass_TM, param, _OpCache_with_parameter_Pass_TM);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_Cancel_TM read__tr_Cancel_TM_state = state._projected_state_for__tr_Cancel_TM();
                BSet<PACKET_START_ADDRESSES_IN_TM_POOL> _trid_19 = (BSet<PACKET_START_ADDRESSES_IN_TM_POOL>) GET.invoke(_OpCache_tr_Cancel_TM, read__tr_Cancel_TM_state);
                if(_trid_19 == null) {
                    _trid_19 = state._tr_Cancel_TM();
                    _OpCache_tr_Cancel_TM = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_Cancel_TM, read__tr_Cancel_TM_state, _trid_19);
                }
                for(PACKET_START_ADDRESSES_IN_TM_POOL param : _trid_19) {
                    PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    _ProjectionRead_Cancel_TM readState = state._projected_state_for_Cancel_TM();
                    PersistentHashMap _OpCache_with_parameter_Cancel_TM = (PersistentHashMap) GET.invoke(_OpCache_Cancel_TM, param);
                    if(_OpCache_with_parameter_Cancel_TM != null) {
                        _ProjectionWrite_Cancel_TM writeState = (_ProjectionWrite_Cancel_TM) GET.invoke(_OpCache_with_parameter_Cancel_TM, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_Cancel_TM(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.Cancel_TM(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_Cancel_TM();
                            _OpCache_with_parameter_Cancel_TM = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_Cancel_TM, readState, writeState);
                            _OpCache_Cancel_TM = (PersistentHashMap) ASSOC.invoke(_OpCache_Cancel_TM, param, _OpCache_with_parameter_Cancel_TM);
                        }

                    } else {
                        copiedState.Cancel_TM(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_Cancel_TM writeState = copiedState._update_for_Cancel_TM();
                        _OpCache_with_parameter_Cancel_TM = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_Cancel_TM = (PersistentHashMap) ASSOC.invoke(_OpCache_Cancel_TM, param, _OpCache_with_parameter_Cancel_TM);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_Drop_TM read__tr_Drop_TM_state = state._projected_state_for__tr_Drop_TM();
                BSet<PACKET_START_ADDRESSES_IN_TM_POOL> _trid_20 = (BSet<PACKET_START_ADDRESSES_IN_TM_POOL>) GET.invoke(_OpCache_tr_Drop_TM, read__tr_Drop_TM_state);
                if(_trid_20 == null) {
                    _trid_20 = state._tr_Drop_TM();
                    _OpCache_tr_Drop_TM = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_Drop_TM, read__tr_Drop_TM_state, _trid_20);
                }
                for(PACKET_START_ADDRESSES_IN_TM_POOL param : _trid_20) {
                    PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    _ProjectionRead_Drop_TM readState = state._projected_state_for_Drop_TM();
                    PersistentHashMap _OpCache_with_parameter_Drop_TM = (PersistentHashMap) GET.invoke(_OpCache_Drop_TM, param);
                    if(_OpCache_with_parameter_Drop_TM != null) {
                        _ProjectionWrite_Drop_TM writeState = (_ProjectionWrite_Drop_TM) GET.invoke(_OpCache_with_parameter_Drop_TM, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_Drop_TM(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.Drop_TM(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_Drop_TM();
                            _OpCache_with_parameter_Drop_TM = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_Drop_TM, readState, writeState);
                            _OpCache_Drop_TM = (PersistentHashMap) ASSOC.invoke(_OpCache_Drop_TM, param, _OpCache_with_parameter_Drop_TM);
                        }

                    } else {
                        copiedState.Drop_TM(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_Drop_TM writeState = copiedState._update_for_Drop_TM();
                        _OpCache_with_parameter_Drop_TM = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_Drop_TM = (PersistentHashMap) ASSOC.invoke(_OpCache_Drop_TM, param, _OpCache_with_parameter_Drop_TM);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_env_Deliver_TM read__tr_env_Deliver_TM_state = state._projected_state_for__tr_env_Deliver_TM();
                BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER> _trid_21 = (BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER>) GET.invoke(_OpCache_tr_env_Deliver_TM, read__tr_env_Deliver_TM_state);
                if(_trid_21 == null) {
                    _trid_21 = state._tr_env_Deliver_TM();
                    _OpCache_tr_env_Deliver_TM = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_env_Deliver_TM, read__tr_env_Deliver_TM_state, _trid_21);
                }
                for(PACKET_START_ADDRESSES_IN_TM_BUFFER param : _trid_21) {
                    PACKET_START_ADDRESSES_IN_TM_BUFFER _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    _ProjectionRead_env_Deliver_TM readState = state._projected_state_for_env_Deliver_TM();
                    PersistentHashMap _OpCache_with_parameter_env_Deliver_TM = (PersistentHashMap) GET.invoke(_OpCache_env_Deliver_TM, param);
                    if(_OpCache_with_parameter_env_Deliver_TM != null) {
                        _ProjectionWrite_env_Deliver_TM writeState = (_ProjectionWrite_env_Deliver_TM) GET.invoke(_OpCache_with_parameter_env_Deliver_TM, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_env_Deliver_TM(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.env_Deliver_TM(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_env_Deliver_TM();
                            _OpCache_with_parameter_env_Deliver_TM = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_env_Deliver_TM, readState, writeState);
                            _OpCache_env_Deliver_TM = (PersistentHashMap) ASSOC.invoke(_OpCache_env_Deliver_TM, param, _OpCache_with_parameter_env_Deliver_TM);
                        }

                    } else {
                        copiedState.env_Deliver_TM(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_env_Deliver_TM writeState = copiedState._update_for_env_Deliver_TM();
                        _OpCache_with_parameter_env_Deliver_TM = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_env_Deliver_TM = (PersistentHashMap) ASSOC.invoke(_OpCache_env_Deliver_TM, param, _OpCache_with_parameter_env_Deliver_TM);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            } else {
                BSet<BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER>> _trid_1 = state._tr_env_Receive_TC();
                for(BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER> param : _trid_1) {
                    PACKET_START_ADDRESSES_IN_TC_BUFFER _tmp_1 = param.projection2();
                    TC_SET _tmp_2 = param.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.env_Receive_TC(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER>> _trid_2 = state._tr_Poll_TC();
                for(BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER> param : _trid_2) {
                    PACKET_START_ADDRESSES_IN_TC_BUFFER _tmp_1 = param.projection2();
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_2 = param.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Poll_TC(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _trid_3 = state._tr_Accept_TC();
                for(PACKET_START_ADDRESSES_IN_TC_POOL param : _trid_3) {
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Accept_TC(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _trid_4 = state._tr_Reject_TC();
                for(PACKET_START_ADDRESSES_IN_TC_POOL param : _trid_4) {
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Reject_TC(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> _trid_5 = state._tr_Report_TC_Acceptance();
                for(BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL> param : _trid_5) {
                    PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                    BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET> _tmp_2 = param.projection1();
                    TM_SET _tmp_3 = _tmp_2.projection2();
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_4 = _tmp_2.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Report_TC_Acceptance(_tmp_4, _tmp_3, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _trid_6 = state._tr_Skip_TC_Acceptance_Report();
                for(PACKET_START_ADDRESSES_IN_TC_POOL param : _trid_6) {
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Skip_TC_Acceptance_Report(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> _trid_7 = state._tr_Report_TC_Rejection();
                for(BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL> param : _trid_7) {
                    PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                    BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET> _tmp_2 = param.projection1();
                    TM_SET _tmp_3 = _tmp_2.projection2();
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_4 = _tmp_2.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Report_TC_Rejection(_tmp_4, _tmp_3, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _trid_8 = state._tr_Skip_TC_Rejection_Report();
                for(PACKET_START_ADDRESSES_IN_TC_POOL param : _trid_8) {
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Skip_TC_Rejection_Report(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _trid_9 = state._tr_Execute_TC_Successfully();
                for(PACKET_START_ADDRESSES_IN_TC_POOL param : _trid_9) {
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Execute_TC_Successfully(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _trid_10 = state._tr_Reset_TM_Buffer();
                for(PACKET_START_ADDRESSES_IN_TC_POOL param : _trid_10) {
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Reset_TM_Buffer(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _trid_11 = state._tr_Fail_TC_Execution();
                for(PACKET_START_ADDRESSES_IN_TC_POOL param : _trid_11) {
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Fail_TC_Execution(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> _trid_12 = state._tr_Report_TC_Execution_Success();
                for(BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL> param : _trid_12) {
                    PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                    BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET> _tmp_2 = param.projection1();
                    TM_SET _tmp_3 = _tmp_2.projection2();
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_4 = _tmp_2.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Report_TC_Execution_Success(_tmp_4, _tmp_3, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _trid_13 = state._tr_Skip_TC_Success_Report();
                for(PACKET_START_ADDRESSES_IN_TC_POOL param : _trid_13) {
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Skip_TC_Success_Report(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> _trid_14 = state._tr_Report_TC_Execution_Failure();
                for(BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL> param : _trid_14) {
                    PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                    BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET> _tmp_2 = param.projection1();
                    TM_SET _tmp_3 = _tmp_2.projection2();
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_4 = _tmp_2.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Report_TC_Execution_Failure(_tmp_4, _tmp_3, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _trid_15 = state._tr_Skip_TC_Failure_Report();
                for(PACKET_START_ADDRESSES_IN_TC_POOL param : _trid_15) {
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Skip_TC_Failure_Report(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<PACKET_START_ADDRESSES_IN_TC_POOL> _trid_16 = state._tr_Drop_TC();
                for(PACKET_START_ADDRESSES_IN_TC_POOL param : _trid_16) {
                    PACKET_START_ADDRESSES_IN_TC_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Drop_TC(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL>> _trid_17 = state._tr_Produce_TM();
                for(BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL> param : _trid_17) {
                    PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param.projection2();
                    TM_SET _tmp_2 = param.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Produce_TM(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER>> _trid_18 = state._tr_Pass_TM();
                for(BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER> param : _trid_18) {
                    PACKET_START_ADDRESSES_IN_TM_BUFFER _tmp_1 = param.projection2();
                    PACKET_START_ADDRESSES_IN_TM_POOL _tmp_2 = param.projection1();

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Pass_TM(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<PACKET_START_ADDRESSES_IN_TM_POOL> _trid_19 = state._tr_Cancel_TM();
                for(PACKET_START_ADDRESSES_IN_TM_POOL param : _trid_19) {
                    PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Cancel_TM(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<PACKET_START_ADDRESSES_IN_TM_POOL> _trid_20 = state._tr_Drop_TM();
                for(PACKET_START_ADDRESSES_IN_TM_POOL param : _trid_20) {
                    PACKET_START_ADDRESSES_IN_TM_POOL _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.Drop_TM(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER> _trid_21 = state._tr_env_Deliver_TM();
                for(PACKET_START_ADDRESSES_IN_TM_BUFFER param : _trid_21) {
                    PACKET_START_ADDRESSES_IN_TM_BUFFER _tmp_1 = param;

                    obsw_M001_2 copiedState = state._copy();
                    copiedState.env_Deliver_TM(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            }
            return result;
        }

        private boolean invariantViolated(final obsw_M001_2 state) {
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
