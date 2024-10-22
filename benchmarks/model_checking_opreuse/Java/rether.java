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


public class rether {


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

    public rether parent;
    public String stateAccessedVia;

    public static class _ProjectionRead_elapse_time {

        public Slots time;

        public _ProjectionRead_elapse_time(Slots time) {
            this.time = time;
        }

        public String toString() {
            return "{" + "time: " + this.time + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_elapse_time)) {
                return false;
            }
            _ProjectionRead_elapse_time o = (_ProjectionRead_elapse_time) other;
            return this.time.equals(o.time);
        }

        public int hashCode() {
            return Objects.hash(time);
        }
    }

    public static class _ProjectionRead__tr_elapse_time {

        public Slots time;

        public _ProjectionRead__tr_elapse_time(Slots time) {
            this.time = time;
        }

        public String toString() {
            return "{" + "time: " + this.time + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_elapse_time)) {
                return false;
            }
            _ProjectionRead__tr_elapse_time o = (_ProjectionRead__tr_elapse_time) other;
            return this.time.equals(o.time);
        }

        public int hashCode() {
            return Objects.hash(time);
        }
    }

    public static class _ProjectionWrite_elapse_time {

        public Slots time;

        public _ProjectionWrite_elapse_time(Slots time) {
            this.time = time;
        }

        public String toString() {
            return "{" + "time: " + this.time + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_elapse_time)) {
                return false;
            }
            _ProjectionWrite_elapse_time o = (_ProjectionWrite_elapse_time) other;
            return this.time.equals(o.time);
        }

        public int hashCode() {
            return Objects.hash(time);
        }
    }

    public static class _ProjectionRead_reserve {

        public BRelation<Nodes, Slots> grants;
        public BRelation<Nodes, Slots> open_reservations;

        public _ProjectionRead_reserve(BRelation<Nodes, Slots> grants, BRelation<Nodes, Slots> open_reservations) {
            this.grants = grants;
            this.open_reservations = open_reservations;
        }

        public String toString() {
            return "{" + "grants: " + this.grants + "," + "open_reservations: " + this.open_reservations + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_reserve)) {
                return false;
            }
            _ProjectionRead_reserve o = (_ProjectionRead_reserve) other;
            return this.grants.equals(o.grants) && this.open_reservations.equals(o.open_reservations);
        }

        public int hashCode() {
            return Objects.hash(grants, open_reservations);
        }
    }

    public static class _ProjectionRead__tr_reserve {

        public BRelation<Nodes, Slots> grants;
        public BRelation<Nodes, Slots> open_reservations;

        public _ProjectionRead__tr_reserve(BRelation<Nodes, Slots> grants, BRelation<Nodes, Slots> open_reservations) {
            this.grants = grants;
            this.open_reservations = open_reservations;
        }

        public String toString() {
            return "{" + "grants: " + this.grants + "," + "open_reservations: " + this.open_reservations + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_reserve)) {
                return false;
            }
            _ProjectionRead__tr_reserve o = (_ProjectionRead__tr_reserve) other;
            return this.grants.equals(o.grants) && this.open_reservations.equals(o.open_reservations);
        }

        public int hashCode() {
            return Objects.hash(grants, open_reservations);
        }
    }

    public static class _ProjectionWrite_reserve {

        public BRelation<Nodes, Slots> open_reservations;

        public _ProjectionWrite_reserve(BRelation<Nodes, Slots> open_reservations) {
            this.open_reservations = open_reservations;
        }

        public String toString() {
            return "{" + "open_reservations: " + this.open_reservations + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_reserve)) {
                return false;
            }
            _ProjectionWrite_reserve o = (_ProjectionWrite_reserve) other;
            return this.open_reservations.equals(o.open_reservations);
        }

        public int hashCode() {
            return Objects.hash(open_reservations);
        }
    }

    public static class _ProjectionRead_release {

        public BRelation<Nodes, Slots> grants;
        public BInteger RT_count;

        public _ProjectionRead_release(BRelation<Nodes, Slots> grants, BInteger RT_count) {
            this.grants = grants;
            this.RT_count = RT_count;
        }

        public String toString() {
            return "{" + "grants: " + this.grants + "," + "RT_count: " + this.RT_count + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_release)) {
                return false;
            }
            _ProjectionRead_release o = (_ProjectionRead_release) other;
            return this.grants.equals(o.grants) && this.RT_count.equals(o.RT_count);
        }

        public int hashCode() {
            return Objects.hash(grants, RT_count);
        }
    }

    public static class _ProjectionRead__tr_release {

        public BRelation<Nodes, Slots> grants;

        public _ProjectionRead__tr_release(BRelation<Nodes, Slots> grants) {
            this.grants = grants;
        }

        public String toString() {
            return "{" + "grants: " + this.grants + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_release)) {
                return false;
            }
            _ProjectionRead__tr_release o = (_ProjectionRead__tr_release) other;
            return this.grants.equals(o.grants);
        }

        public int hashCode() {
            return Objects.hash(grants);
        }
    }

    public static class _ProjectionWrite_release {

        public BRelation<Nodes, Slots> grants;
        public BInteger RT_count;

        public _ProjectionWrite_release(BRelation<Nodes, Slots> grants, BInteger RT_count) {
            this.grants = grants;
            this.RT_count = RT_count;
        }

        public String toString() {
            return "{" + "grants: " + this.grants + "," + "RT_count: " + this.RT_count + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_release)) {
                return false;
            }
            _ProjectionWrite_release o = (_ProjectionWrite_release) other;
            return this.grants.equals(o.grants) && this.RT_count.equals(o.RT_count);
        }

        public int hashCode() {
            return Objects.hash(grants, RT_count);
        }
    }

    public static class _ProjectionRead_grant {

        public BRelation<Nodes, Slots> grants;
        public BRelation<Nodes, Slots> open_reservations;
        public BInteger RT_count;

        public _ProjectionRead_grant(BRelation<Nodes, Slots> grants, BRelation<Nodes, Slots> open_reservations, BInteger RT_count) {
            this.grants = grants;
            this.open_reservations = open_reservations;
            this.RT_count = RT_count;
        }

        public String toString() {
            return "{" + "grants: " + this.grants + "," + "open_reservations: " + this.open_reservations + "," + "RT_count: " + this.RT_count + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_grant)) {
                return false;
            }
            _ProjectionRead_grant o = (_ProjectionRead_grant) other;
            return this.grants.equals(o.grants) && this.open_reservations.equals(o.open_reservations) && this.RT_count.equals(o.RT_count);
        }

        public int hashCode() {
            return Objects.hash(grants, open_reservations, RT_count);
        }
    }

    public static class _ProjectionRead__tr_grant {

        public BRelation<Nodes, Slots> open_reservations;
        public BInteger RT_count;

        public _ProjectionRead__tr_grant(BRelation<Nodes, Slots> open_reservations, BInteger RT_count) {
            this.open_reservations = open_reservations;
            this.RT_count = RT_count;
        }

        public String toString() {
            return "{" + "open_reservations: " + this.open_reservations + "," + "RT_count: " + this.RT_count + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_grant)) {
                return false;
            }
            _ProjectionRead__tr_grant o = (_ProjectionRead__tr_grant) other;
            return this.open_reservations.equals(o.open_reservations) && this.RT_count.equals(o.RT_count);
        }

        public int hashCode() {
            return Objects.hash(open_reservations, RT_count);
        }
    }

    public static class _ProjectionWrite_grant {

        public BRelation<Nodes, Slots> grants;
        public BRelation<Nodes, Slots> open_reservations;
        public BInteger RT_count;

        public _ProjectionWrite_grant(BRelation<Nodes, Slots> grants, BRelation<Nodes, Slots> open_reservations, BInteger RT_count) {
            this.grants = grants;
            this.open_reservations = open_reservations;
            this.RT_count = RT_count;
        }

        public String toString() {
            return "{" + "grants: " + this.grants + "," + "open_reservations: " + this.open_reservations + "," + "RT_count: " + this.RT_count + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_grant)) {
                return false;
            }
            _ProjectionWrite_grant o = (_ProjectionWrite_grant) other;
            return this.grants.equals(o.grants) && this.open_reservations.equals(o.open_reservations) && this.RT_count.equals(o.RT_count);
        }

        public int hashCode() {
            return Objects.hash(grants, open_reservations, RT_count);
        }
    }

    public static class _ProjectionRead_no_grant {

        public BRelation<Nodes, Slots> open_reservations;

        public _ProjectionRead_no_grant(BRelation<Nodes, Slots> open_reservations) {
            this.open_reservations = open_reservations;
        }

        public String toString() {
            return "{" + "open_reservations: " + this.open_reservations + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_no_grant)) {
                return false;
            }
            _ProjectionRead_no_grant o = (_ProjectionRead_no_grant) other;
            return this.open_reservations.equals(o.open_reservations);
        }

        public int hashCode() {
            return Objects.hash(open_reservations);
        }
    }

    public static class _ProjectionRead__tr_no_grant {

        public BRelation<Nodes, Slots> open_reservations;

        public _ProjectionRead__tr_no_grant(BRelation<Nodes, Slots> open_reservations) {
            this.open_reservations = open_reservations;
        }

        public String toString() {
            return "{" + "open_reservations: " + this.open_reservations + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_no_grant)) {
                return false;
            }
            _ProjectionRead__tr_no_grant o = (_ProjectionRead__tr_no_grant) other;
            return this.open_reservations.equals(o.open_reservations);
        }

        public int hashCode() {
            return Objects.hash(open_reservations);
        }
    }

    public static class _ProjectionWrite_no_grant {

        public BRelation<Nodes, Slots> open_reservations;

        public _ProjectionWrite_no_grant(BRelation<Nodes, Slots> open_reservations) {
            this.open_reservations = open_reservations;
        }

        public String toString() {
            return "{" + "open_reservations: " + this.open_reservations + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_no_grant)) {
                return false;
            }
            _ProjectionWrite_no_grant o = (_ProjectionWrite_no_grant) other;
            return this.open_reservations.equals(o.open_reservations);
        }

        public int hashCode() {
            return Objects.hash(open_reservations);
        }
    }

    public static class _ProjectionRead_use_RT_Slot {

        public BRelation<Nodes, Slots> grants;
        public Slots time;
        public Nodes token;

        public _ProjectionRead_use_RT_Slot(BRelation<Nodes, Slots> grants, Slots time, Nodes token) {
            this.grants = grants;
            this.time = time;
            this.token = token;
        }

        public String toString() {
            return "{" + "grants: " + this.grants + "," + "time: " + this.time + "," + "token: " + this.token + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_use_RT_Slot)) {
                return false;
            }
            _ProjectionRead_use_RT_Slot o = (_ProjectionRead_use_RT_Slot) other;
            return this.grants.equals(o.grants) && this.time.equals(o.time) && this.token.equals(o.token);
        }

        public int hashCode() {
            return Objects.hash(grants, time, token);
        }
    }

    public static class _ProjectionRead__tr_use_RT_Slot {

        public BRelation<Nodes, Slots> grants;
        public Slots time;
        public Nodes token;

        public _ProjectionRead__tr_use_RT_Slot(BRelation<Nodes, Slots> grants, Slots time, Nodes token) {
            this.grants = grants;
            this.time = time;
            this.token = token;
        }

        public String toString() {
            return "{" + "grants: " + this.grants + "," + "time: " + this.time + "," + "token: " + this.token + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_use_RT_Slot)) {
                return false;
            }
            _ProjectionRead__tr_use_RT_Slot o = (_ProjectionRead__tr_use_RT_Slot) other;
            return this.grants.equals(o.grants) && this.time.equals(o.time) && this.token.equals(o.token);
        }

        public int hashCode() {
            return Objects.hash(grants, time, token);
        }
    }

    public static class _ProjectionWrite_use_RT_Slot {


        public _ProjectionWrite_use_RT_Slot() {
        }

        public String toString() {
            return "{}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_use_RT_Slot)) {
                return false;
            }
            _ProjectionWrite_use_RT_Slot o = (_ProjectionWrite_use_RT_Slot) other;
            return true;
        }

        public int hashCode() {
            return Objects.hash();
        }
    }

    public static class _ProjectionRead_use_NRT_Slot {

        public BRelation<Nodes, Slots> grants;
        public Slots time;
        public Nodes token;

        public _ProjectionRead_use_NRT_Slot(BRelation<Nodes, Slots> grants, Slots time, Nodes token) {
            this.grants = grants;
            this.time = time;
            this.token = token;
        }

        public String toString() {
            return "{" + "grants: " + this.grants + "," + "time: " + this.time + "," + "token: " + this.token + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_use_NRT_Slot)) {
                return false;
            }
            _ProjectionRead_use_NRT_Slot o = (_ProjectionRead_use_NRT_Slot) other;
            return this.grants.equals(o.grants) && this.time.equals(o.time) && this.token.equals(o.token);
        }

        public int hashCode() {
            return Objects.hash(grants, time, token);
        }
    }

    public static class _ProjectionRead__tr_use_NRT_Slot {

        public BRelation<Nodes, Slots> grants;
        public Slots time;
        public Nodes token;

        public _ProjectionRead__tr_use_NRT_Slot(BRelation<Nodes, Slots> grants, Slots time, Nodes token) {
            this.grants = grants;
            this.time = time;
            this.token = token;
        }

        public String toString() {
            return "{" + "grants: " + this.grants + "," + "time: " + this.time + "," + "token: " + this.token + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_use_NRT_Slot)) {
                return false;
            }
            _ProjectionRead__tr_use_NRT_Slot o = (_ProjectionRead__tr_use_NRT_Slot) other;
            return this.grants.equals(o.grants) && this.time.equals(o.time) && this.token.equals(o.token);
        }

        public int hashCode() {
            return Objects.hash(grants, time, token);
        }
    }

    public static class _ProjectionWrite_use_NRT_Slot {


        public _ProjectionWrite_use_NRT_Slot() {
        }

        public String toString() {
            return "{}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_use_NRT_Slot)) {
                return false;
            }
            _ProjectionWrite_use_NRT_Slot o = (_ProjectionWrite_use_NRT_Slot) other;
            return true;
        }

        public int hashCode() {
            return Objects.hash();
        }
    }

    public static class _ProjectionRead_pass_token {

        public Nodes token;

        public _ProjectionRead_pass_token(Nodes token) {
            this.token = token;
        }

        public String toString() {
            return "{" + "token: " + this.token + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_pass_token)) {
                return false;
            }
            _ProjectionRead_pass_token o = (_ProjectionRead_pass_token) other;
            return this.token.equals(o.token);
        }

        public int hashCode() {
            return Objects.hash(token);
        }
    }

    public static class _ProjectionRead__tr_pass_token {

        public Nodes token;

        public _ProjectionRead__tr_pass_token(Nodes token) {
            this.token = token;
        }

        public String toString() {
            return "{" + "token: " + this.token + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_pass_token)) {
                return false;
            }
            _ProjectionRead__tr_pass_token o = (_ProjectionRead__tr_pass_token) other;
            return this.token.equals(o.token);
        }

        public int hashCode() {
            return Objects.hash(token);
        }
    }

    public static class _ProjectionWrite_pass_token {

        public Nodes token;

        public _ProjectionWrite_pass_token(Nodes token) {
            this.token = token;
        }

        public String toString() {
            return "{" + "token: " + this.token + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_pass_token)) {
                return false;
            }
            _ProjectionWrite_pass_token o = (_ProjectionWrite_pass_token) other;
            return this.token.equals(o.token);
        }

        public int hashCode() {
            return Objects.hash(token);
        }
    }

    public static class _ProjectionRead__check_inv_1 {

        public Slots time;

        public _ProjectionRead__check_inv_1(Slots time) {
            this.time = time;
        }

        public String toString() {
            return "{" + "time: " + this.time + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_1)) {
                return false;
            }
            _ProjectionRead__check_inv_1 o = (_ProjectionRead__check_inv_1) other;
            return this.time.equals(o.time);
        }

        public int hashCode() {
            return Objects.hash(time);
        }
    }

    public static class _ProjectionRead__check_inv_2 {

        public Nodes token;

        public _ProjectionRead__check_inv_2(Nodes token) {
            this.token = token;
        }

        public String toString() {
            return "{" + "token: " + this.token + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_2)) {
                return false;
            }
            _ProjectionRead__check_inv_2 o = (_ProjectionRead__check_inv_2) other;
            return this.token.equals(o.token);
        }

        public int hashCode() {
            return Objects.hash(token);
        }
    }

    public static class _ProjectionRead__check_inv_3 {

        public BRelation<Nodes, Slots> open_reservations;

        public _ProjectionRead__check_inv_3(BRelation<Nodes, Slots> open_reservations) {
            this.open_reservations = open_reservations;
        }

        public String toString() {
            return "{" + "open_reservations: " + this.open_reservations + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_3)) {
                return false;
            }
            _ProjectionRead__check_inv_3 o = (_ProjectionRead__check_inv_3) other;
            return this.open_reservations.equals(o.open_reservations);
        }

        public int hashCode() {
            return Objects.hash(open_reservations);
        }
    }

    public static class _ProjectionRead__check_inv_4 {

        public BRelation<Nodes, Slots> grants;

        public _ProjectionRead__check_inv_4(BRelation<Nodes, Slots> grants) {
            this.grants = grants;
        }

        public String toString() {
            return "{" + "grants: " + this.grants + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_4)) {
                return false;
            }
            _ProjectionRead__check_inv_4 o = (_ProjectionRead__check_inv_4) other;
            return this.grants.equals(o.grants);
        }

        public int hashCode() {
            return Objects.hash(grants);
        }
    }

    public static class _ProjectionRead__check_inv_5 {

        public BInteger RT_count;

        public _ProjectionRead__check_inv_5(BInteger RT_count) {
            this.RT_count = RT_count;
        }

        public String toString() {
            return "{" + "RT_count: " + this.RT_count + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_5)) {
                return false;
            }
            _ProjectionRead__check_inv_5 o = (_ProjectionRead__check_inv_5) other;
            return this.RT_count.equals(o.RT_count);
        }

        public int hashCode() {
            return Objects.hash(RT_count);
        }
    }




    private static BSet<Slots> RT_Slots;
    private static BRelation<Nodes, Nodes> nextNodes;
    private static BRelation<Slots, Slots> nextSlots;


    public enum Nodes implements BObject {
        node1, 
        node2, 
        node3, 
        node4, 
        node5;

        public BBoolean equal(Nodes o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(Nodes o) {
            return new BBoolean(this != o);
        }
    }

    public enum Slots implements BObject {
        slot1, 
        slot2, 
        slot3, 
        slot4;

        public BBoolean equal(Slots o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(Slots o) {
            return new BBoolean(this != o);
        }
    }

    private static BSet<Nodes> _Nodes = new BSet<Nodes>(Nodes.node1, Nodes.node2, Nodes.node3, Nodes.node4, Nodes.node5);
    private static BSet<Slots> _Slots = new BSet<Slots>(Slots.slot1, Slots.slot2, Slots.slot3, Slots.slot4);

    private BInteger RT_count;
    private BRelation<Nodes, Slots> grants;
    private BRelation<Nodes, Slots> open_reservations;
    private Slots time;
    private Nodes token;

    static {
        RT_Slots = new BSet<Slots>(Slots.slot1, Slots.slot2);
        nextNodes = new BRelation<Nodes, Nodes>(new BTuple<Nodes, Nodes>(Nodes.node1, Nodes.node2), new BTuple<Nodes, Nodes>(Nodes.node2, Nodes.node3), new BTuple<Nodes, Nodes>(Nodes.node3, Nodes.node4), new BTuple<Nodes, Nodes>(Nodes.node4, Nodes.node1), new BTuple<Nodes, Nodes>(Nodes.node5, Nodes.node1));
        nextSlots = new BRelation<Slots, Slots>(new BTuple<Slots, Slots>(Slots.slot1, Slots.slot2), new BTuple<Slots, Slots>(Slots.slot2, Slots.slot3), new BTuple<Slots, Slots>(Slots.slot3, Slots.slot1), new BTuple<Slots, Slots>(Slots.slot4, Slots.slot1));
        if(!(new BBoolean(new BBoolean(nextSlots.checkDomain(_Slots).and(nextSlots.checkRange(_Slots)).and(nextSlots.isFunction()).and(nextSlots.isTotal(_Slots)).booleanValue() && RT_Slots.strictSubset(_Slots).booleanValue()).booleanValue() && nextNodes.checkDomain(_Nodes).and(nextNodes.checkRange(_Nodes)).and(nextNodes.isFunction()).and(nextNodes.isTotal(_Nodes)).booleanValue())).booleanValue()) {
            throw new RuntimeException("Contradiction in PROPERTIES detected!");
        }
    }

    public rether() {
        time = Slots.slot1;
        token = Nodes.node1;
        open_reservations = new BRelation<Nodes, Slots>();
        grants = new BRelation<Nodes, Slots>();
        RT_count = RT_Slots.card();
    }

    public rether(rether copy) {
        this.RT_Slots = copy.RT_Slots;
        this.nextNodes = copy.nextNodes;
        this.nextSlots = copy.nextSlots;
        this.RT_count = copy.RT_count;
        this.grants = copy.grants;
        this.open_reservations = copy.open_reservations;
        this.time = copy.time;
        this.token = copy.token;
    }

    public void elapse_time(Slots next, Slots slot) {
        time = next;

    }

    public void reserve(Nodes node, Slots slot) {
        open_reservations = open_reservations.union(new BRelation<Nodes, Slots>(new BTuple<Nodes, Slots>(node, slot)));

    }

    public void release(Nodes node, Slots slot) {
        BInteger _ld_RT_count = RT_count;
        BRelation<Nodes, Slots> _ld_grants = grants;
        grants = _ld_grants.difference(new BRelation<Nodes, Slots>(new BTuple<Nodes, Slots>(node, slot)));
        RT_count = _ld_RT_count.plus(new BInteger(1));

    }

    public void grant(Nodes node, Slots slot) {
        BInteger _ld_RT_count = RT_count;
        BRelation<Nodes, Slots> _ld_open_reservations = open_reservations;
        BRelation<Nodes, Slots> _ld_grants = grants;
        open_reservations = _ld_open_reservations.difference(new BRelation<Nodes, Slots>(new BTuple<Nodes, Slots>(node, slot)));
        grants = _ld_grants.union(new BRelation<Nodes, Slots>(new BTuple<Nodes, Slots>(node, slot)));
        RT_count = _ld_RT_count.minus(new BInteger(1));

    }

    public void no_grant(Nodes node, Slots slot) {
        open_reservations = open_reservations.difference(new BRelation<Nodes, Slots>(new BTuple<Nodes, Slots>(node, slot)));

    }

    public void use_RT_Slot(Nodes node, Slots slot) {
    }

    public void use_NRT_Slot(Nodes node, Slots slot) {
    }

    public void pass_token(Nodes node) {
        token = nextNodes.functionCall(node);

    }

    public BSet<Slots> _get_RT_Slots() {
        return RT_Slots;
    }

    public BRelation<Nodes, Nodes> _get_nextNodes() {
        return nextNodes;
    }

    public BRelation<Slots, Slots> _get_nextSlots() {
        return nextSlots;
    }

    public BInteger _get_RT_count() {
        return RT_count;
    }

    public BRelation<Nodes, Slots> _get_grants() {
        return grants;
    }

    public BRelation<Nodes, Slots> _get_open_reservations() {
        return open_reservations;
    }

    public Slots _get_time() {
        return time;
    }

    public Nodes _get_token() {
        return token;
    }

    public BSet<Nodes> _get__Nodes() {
        return _Nodes;
    }

    public BSet<Slots> _get__Slots() {
        return _Slots;
    }

    @Override
    public boolean equals(Object o) {
        rether o1 = this;
        rether o2 = (rether) o;
        return o1._get_RT_count().equals(o2._get_RT_count()) && o1._get_grants().equals(o2._get_grants()) && o1._get_open_reservations().equals(o2._get_open_reservations()) && o1._get_time().equals(o2._get_time()) && o1._get_token().equals(o2._get_token());
    }



    @Override
    public int hashCode() {
        return this._hashCode_1();
    }

    public int _hashCode_1() {
        int result = 1;
        result = (1543 * result) ^ ((this._get_RT_count()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_grants()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_open_reservations()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_time()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_token()).hashCode() << 1);
        return result;
    }

    public int _hashCode_2() {
        int result = 1;
        result = (6151 * result) ^ ((this._get_RT_count()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_grants()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_open_reservations()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_time()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_token()).hashCode() << 1);
        return result;
    }

    @Override
    public String toString() {
        return String.join("\n", "_get_RT_count: " + (this._get_RT_count()).toString(), "_get_grants: " + (this._get_grants()).toString(), "_get_open_reservations: " + (this._get_open_reservations()).toString(), "_get_time: " + (this._get_time()).toString(), "_get_token: " + (this._get_token()).toString());
    }

    public rether _copy() {
        return new rether(this);
    }


    public BSet<BTuple<Slots, Slots>> _tr_elapse_time() {
        BSet<BTuple<Slots, Slots>> _ic_set_0 = new BSet<BTuple<Slots, Slots>>();
        for(Slots _ic_next_1 : _Slots) {
            for(Slots _ic_slot_1 : _Slots) {
                if((new BBoolean(nextSlots.elementOf(new BTuple<Slots, Slots>(_ic_slot_1, _ic_next_1)).booleanValue() && _ic_slot_1.equal(time).booleanValue())).booleanValue()) {
                    _ic_set_0 = _ic_set_0.union(new BSet<BTuple<Slots, Slots>>(new BTuple<Slots, Slots>(_ic_next_1, _ic_slot_1)));
                }

            }

        }

        return _ic_set_0;
    }

    public BSet<BTuple<Nodes, Slots>> _tr_reserve() {
        BSet<BTuple<Nodes, Slots>> _ic_set_1 = new BSet<BTuple<Nodes, Slots>>();
        for(Nodes _ic_node_1 : _Nodes) {
            for(Slots _ic_slot_1 : _Slots) {
                if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(open_reservations.isNotInDomain(_ic_node_1).booleanValue() && open_reservations.isNotInRange(_ic_slot_1).booleanValue()).booleanValue() && open_reservations.notElementOf(new BTuple<Nodes, Slots>(_ic_node_1, _ic_slot_1)).booleanValue()).booleanValue() && grants.isNotInDomain(_ic_node_1).booleanValue()).booleanValue() && grants.isNotInRange(_ic_slot_1).booleanValue())).booleanValue()) {
                    _ic_set_1 = _ic_set_1.union(new BSet<BTuple<Nodes, Slots>>(new BTuple<Nodes, Slots>(_ic_node_1, _ic_slot_1)));
                }

            }

        }

        return _ic_set_1;
    }

    public BSet<BTuple<Nodes, Slots>> _tr_release() {
        BSet<BTuple<Nodes, Slots>> _ic_set_2 = new BSet<BTuple<Nodes, Slots>>();
        for(Nodes _ic_node_1 : _Nodes) {
            for(Slots _ic_slot_1 : _Slots) {
                if((grants.elementOf(new BTuple<Nodes, Slots>(_ic_node_1, _ic_slot_1))).booleanValue()) {
                    _ic_set_2 = _ic_set_2.union(new BSet<BTuple<Nodes, Slots>>(new BTuple<Nodes, Slots>(_ic_node_1, _ic_slot_1)));
                }

            }

        }

        return _ic_set_2;
    }

    public BSet<BTuple<Nodes, Slots>> _tr_grant() {
        BSet<BTuple<Nodes, Slots>> _ic_set_3 = new BSet<BTuple<Nodes, Slots>>();
        for(Nodes _ic_node_1 : _Nodes) {
            for(Slots _ic_slot_1 : _Slots) {
                if((new BBoolean(new BBoolean(new BBoolean(open_reservations.isInDomain(_ic_node_1).booleanValue() && open_reservations.isInRange(_ic_slot_1).booleanValue()).booleanValue() && open_reservations.elementOf(new BTuple<Nodes, Slots>(_ic_node_1, _ic_slot_1)).booleanValue()).booleanValue() && RT_count.greater(new BInteger(0)).booleanValue())).booleanValue()) {
                    _ic_set_3 = _ic_set_3.union(new BSet<BTuple<Nodes, Slots>>(new BTuple<Nodes, Slots>(_ic_node_1, _ic_slot_1)));
                }

            }

        }

        return _ic_set_3;
    }

    public BSet<BTuple<Nodes, Slots>> _tr_no_grant() {
        BSet<BTuple<Nodes, Slots>> _ic_set_4 = new BSet<BTuple<Nodes, Slots>>();
        for(Nodes _ic_node_1 : _Nodes) {
            for(Slots _ic_slot_1 : _Slots) {
                if((new BBoolean(new BBoolean(open_reservations.isInDomain(_ic_node_1).booleanValue() && open_reservations.isInRange(_ic_slot_1).booleanValue()).booleanValue() && open_reservations.elementOf(new BTuple<Nodes, Slots>(_ic_node_1, _ic_slot_1)).booleanValue())).booleanValue()) {
                    _ic_set_4 = _ic_set_4.union(new BSet<BTuple<Nodes, Slots>>(new BTuple<Nodes, Slots>(_ic_node_1, _ic_slot_1)));
                }

            }

        }

        return _ic_set_4;
    }

    public BSet<BTuple<Nodes, Slots>> _tr_use_RT_Slot() {
        BSet<BTuple<Nodes, Slots>> _ic_set_5 = new BSet<BTuple<Nodes, Slots>>();
        for(Nodes _ic_node_1 : _Nodes) {
            for(Slots _ic_slot_1 : _Slots) {
                if((new BBoolean(new BBoolean(grants.elementOf(new BTuple<Nodes, Slots>(_ic_node_1, _ic_slot_1)).booleanValue() && _ic_slot_1.equal(time).booleanValue()).booleanValue() && _ic_node_1.equal(token).booleanValue())).booleanValue()) {
                    _ic_set_5 = _ic_set_5.union(new BSet<BTuple<Nodes, Slots>>(new BTuple<Nodes, Slots>(_ic_node_1, _ic_slot_1)));
                }

            }

        }

        return _ic_set_5;
    }

    public BSet<BTuple<Nodes, Slots>> _tr_use_NRT_Slot() {
        BSet<BTuple<Nodes, Slots>> _ic_set_6 = new BSet<BTuple<Nodes, Slots>>();
        for(Nodes _ic_node_1 : _Nodes) {
            for(Slots _ic_slot_1 : _Slots) {
                if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(grants.notElementOf(new BTuple<Nodes, Slots>(_ic_node_1, _ic_slot_1)).booleanValue() && _ic_slot_1.equal(time).booleanValue()).booleanValue() && grants.isNotInDomain(_ic_node_1).booleanValue()).booleanValue() && grants.isNotInRange(_ic_slot_1).booleanValue()).booleanValue() && _ic_node_1.equal(token).booleanValue())).booleanValue()) {
                    _ic_set_6 = _ic_set_6.union(new BSet<BTuple<Nodes, Slots>>(new BTuple<Nodes, Slots>(_ic_node_1, _ic_slot_1)));
                }

            }

        }

        return _ic_set_6;
    }

    public BSet<Nodes> _tr_pass_token() {
        BSet<Nodes> _ic_set_7 = new BSet<Nodes>();
        for(Nodes _ic_node_1 : _Nodes) {
            if((_ic_node_1.equal(token)).booleanValue()) {
                _ic_set_7 = _ic_set_7.union(new BSet<Nodes>(_ic_node_1));
            }

        }

        return _ic_set_7;
    }

    public _ProjectionRead_release _projected_state_for_release() {
        return new _ProjectionRead_release(grants,RT_count);
    }

    public _ProjectionRead_reserve _projected_state_for_reserve() {
        return new _ProjectionRead_reserve(grants,open_reservations);
    }

    public _ProjectionRead_use_RT_Slot _projected_state_for_use_RT_Slot() {
        return new _ProjectionRead_use_RT_Slot(grants,time,token);
    }

    public _ProjectionRead_use_NRT_Slot _projected_state_for_use_NRT_Slot() {
        return new _ProjectionRead_use_NRT_Slot(grants,time,token);
    }

    public _ProjectionRead_elapse_time _projected_state_for_elapse_time() {
        return new _ProjectionRead_elapse_time(time);
    }

    public _ProjectionRead_grant _projected_state_for_grant() {
        return new _ProjectionRead_grant(grants,open_reservations,RT_count);
    }

    public _ProjectionRead_no_grant _projected_state_for_no_grant() {
        return new _ProjectionRead_no_grant(open_reservations);
    }

    public _ProjectionRead_pass_token _projected_state_for_pass_token() {
        return new _ProjectionRead_pass_token(token);
    }

    public _ProjectionRead__tr_pass_token _projected_state_for__tr_pass_token() {
        return new _ProjectionRead__tr_pass_token(token);
    }

    public _ProjectionRead__tr_elapse_time _projected_state_for__tr_elapse_time() {
        return new _ProjectionRead__tr_elapse_time(time);
    }

    public _ProjectionRead__tr_use_NRT_Slot _projected_state_for__tr_use_NRT_Slot() {
        return new _ProjectionRead__tr_use_NRT_Slot(grants,time,token);
    }

    public _ProjectionRead__tr_reserve _projected_state_for__tr_reserve() {
        return new _ProjectionRead__tr_reserve(grants,open_reservations);
    }

    public _ProjectionRead__tr_no_grant _projected_state_for__tr_no_grant() {
        return new _ProjectionRead__tr_no_grant(open_reservations);
    }

    public _ProjectionRead__tr_release _projected_state_for__tr_release() {
        return new _ProjectionRead__tr_release(grants);
    }

    public _ProjectionRead__tr_grant _projected_state_for__tr_grant() {
        return new _ProjectionRead__tr_grant(open_reservations,RT_count);
    }

    public _ProjectionRead__tr_use_RT_Slot _projected_state_for__tr_use_RT_Slot() {
        return new _ProjectionRead__tr_use_RT_Slot(grants,time,token);
    }

    public _ProjectionRead__check_inv_2 _projected_state_for__check_inv_2() {
        return new _ProjectionRead__check_inv_2(token);
    }

    public _ProjectionRead__check_inv_3 _projected_state_for__check_inv_3() {
        return new _ProjectionRead__check_inv_3(open_reservations);
    }

    public _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() {
        return new _ProjectionRead__check_inv_1(time);
    }

    public _ProjectionRead__check_inv_4 _projected_state_for__check_inv_4() {
        return new _ProjectionRead__check_inv_4(grants);
    }

    public _ProjectionRead__check_inv_5 _projected_state_for__check_inv_5() {
        return new _ProjectionRead__check_inv_5(RT_count);
    }

    public _ProjectionWrite_release _update_for_release() {
        return new _ProjectionWrite_release(grants,RT_count);
    }

    public _ProjectionWrite_reserve _update_for_reserve() {
        return new _ProjectionWrite_reserve(open_reservations);
    }

    public _ProjectionWrite_use_RT_Slot _update_for_use_RT_Slot() {
        return new _ProjectionWrite_use_RT_Slot();
    }

    public _ProjectionWrite_use_NRT_Slot _update_for_use_NRT_Slot() {
        return new _ProjectionWrite_use_NRT_Slot();
    }

    public _ProjectionWrite_elapse_time _update_for_elapse_time() {
        return new _ProjectionWrite_elapse_time(time);
    }

    public _ProjectionWrite_grant _update_for_grant() {
        return new _ProjectionWrite_grant(grants,open_reservations,RT_count);
    }

    public _ProjectionWrite_no_grant _update_for_no_grant() {
        return new _ProjectionWrite_no_grant(open_reservations);
    }

    public _ProjectionWrite_pass_token _update_for_pass_token() {
        return new _ProjectionWrite_pass_token(token);
    }

    public void _apply_update_for_release(_ProjectionWrite_release update) {
        this.grants = update.grants;
        this.RT_count = update.RT_count;
    }

    public void _apply_update_for_reserve(_ProjectionWrite_reserve update) {
        this.open_reservations = update.open_reservations;
    }

    public void _apply_update_for_use_RT_Slot(_ProjectionWrite_use_RT_Slot update) {
    }

    public void _apply_update_for_use_NRT_Slot(_ProjectionWrite_use_NRT_Slot update) {
    }

    public void _apply_update_for_elapse_time(_ProjectionWrite_elapse_time update) {
        this.time = update.time;
    }

    public void _apply_update_for_grant(_ProjectionWrite_grant update) {
        this.grants = update.grants;
        this.open_reservations = update.open_reservations;
        this.RT_count = update.RT_count;
    }

    public void _apply_update_for_no_grant(_ProjectionWrite_no_grant update) {
        this.open_reservations = update.open_reservations;
    }

    public void _apply_update_for_pass_token(_ProjectionWrite_pass_token update) {
        this.token = update.token;
    }

    public boolean _check_inv_1() {
        return _Slots.elementOf(time).booleanValue();
    }

    public boolean _check_inv_2() {
        return _Nodes.elementOf(token).booleanValue();
    }

    public boolean _check_inv_3() {
        return open_reservations.checkDomain(_Nodes).and(open_reservations.checkRange(_Slots)).and(open_reservations.isFunction()).and(open_reservations.isPartial(_Nodes)).booleanValue();
    }

    public boolean _check_inv_4() {
        return grants.checkDomain(_Nodes).and(grants.checkRange(_Slots)).and(grants.isFunction()).and(grants.isPartial(_Nodes)).booleanValue();
    }

    public boolean _check_inv_5() {
        return new BBoolean(RT_count.greaterEqual(new BInteger(0)).booleanValue() && RT_count.lessEqual(new BInteger(32768)).booleanValue()).booleanValue();
    }


    private static class ModelChecker {
        private final Type type;
        private final int threads;
        private final boolean isCaching;
        private final boolean isDebug;

        private final LinkedList<rether> unvisitedStates = new LinkedList<>();
        private final Set<rether> states = ConcurrentHashMap.newKeySet();
        private AtomicInteger transitions = new AtomicInteger(0);
        private ThreadPoolExecutor threadPool;
        private Object waitLock = new Object();

        private AtomicBoolean invariantViolated = new AtomicBoolean(false);
        private AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        private rether counterExampleState = null;

        PersistentHashMap _OpCache_elapse_time = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_elapse_time = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_reserve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_reserve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_release = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_release = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_grant = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_grant = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_no_grant = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_no_grant = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_use_RT_Slot = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_use_RT_Slot = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_use_NRT_Slot = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_use_NRT_Slot = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_pass_token = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_pass_token = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_1 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_2 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_3 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_4 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_5 = PersistentHashMap.EMPTY;

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
            rether machine = new rether();
            states.add(machine);
            unvisitedStates.add(machine);

            while(!unvisitedStates.isEmpty()) {
                rether state = next();

                Set<rether> nextStates = generateNextStates(state);

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
            rether machine = new rether();
            states.add(machine);
            unvisitedStates.add(machine);

            AtomicBoolean stopThreads = new AtomicBoolean(false);
            AtomicInteger possibleQueueChanges = new AtomicInteger(0);

            while(!unvisitedStates.isEmpty() && !stopThreads.get()) {
                possibleQueueChanges.incrementAndGet();
                rether state = next();
                Runnable task = () -> {
                    Set<rether> nextStates = generateNextStates(state);

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

        private rether next() {
            synchronized(this.unvisitedStates) {
                return switch(type) {
                    case BFS -> this.unvisitedStates.removeFirst();
                    case DFS -> this.unvisitedStates.removeLast();
                    case MIXED -> this.unvisitedStates.size() % 2 == 0 ? this.unvisitedStates.removeFirst() : this.unvisitedStates.removeLast();
                };
            }
        }

        @SuppressWarnings("unchecked")
        private Set<rether> generateNextStates(final rether state) {
            Set<rether> result = new HashSet<>();
            if(isCaching) {
                _ProjectionRead__tr_elapse_time read__tr_elapse_time_state = state._projected_state_for__tr_elapse_time();
                BSet<BTuple<Slots, Slots>> _trid_1 = (BSet<BTuple<Slots, Slots>>) GET.invoke(_OpCache_tr_elapse_time, read__tr_elapse_time_state);
                if(_trid_1 == null) {
                    _trid_1 = state._tr_elapse_time();
                    _OpCache_tr_elapse_time = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_elapse_time, read__tr_elapse_time_state, _trid_1);
                }
                for(BTuple<Slots, Slots> param : _trid_1) {
                    Slots _tmp_1 = param.projection2();
                    Slots _tmp_2 = param.projection1();

                    rether copiedState = state._copy();
                    _ProjectionRead_elapse_time readState = state._projected_state_for_elapse_time();
                    PersistentHashMap _OpCache_with_parameter_elapse_time = (PersistentHashMap) GET.invoke(_OpCache_elapse_time, param);
                    if(_OpCache_with_parameter_elapse_time != null) {
                        _ProjectionWrite_elapse_time writeState = (_ProjectionWrite_elapse_time) GET.invoke(_OpCache_with_parameter_elapse_time, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_elapse_time(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.elapse_time(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_elapse_time();
                            _OpCache_with_parameter_elapse_time = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_elapse_time, readState, writeState);
                            _OpCache_elapse_time = (PersistentHashMap) ASSOC.invoke(_OpCache_elapse_time, param, _OpCache_with_parameter_elapse_time);
                        }

                    } else {
                        copiedState.elapse_time(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_elapse_time writeState = copiedState._update_for_elapse_time();
                        _OpCache_with_parameter_elapse_time = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_elapse_time = (PersistentHashMap) ASSOC.invoke(_OpCache_elapse_time, param, _OpCache_with_parameter_elapse_time);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_reserve read__tr_reserve_state = state._projected_state_for__tr_reserve();
                BSet<BTuple<Nodes, Slots>> _trid_2 = (BSet<BTuple<Nodes, Slots>>) GET.invoke(_OpCache_tr_reserve, read__tr_reserve_state);
                if(_trid_2 == null) {
                    _trid_2 = state._tr_reserve();
                    _OpCache_tr_reserve = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_reserve, read__tr_reserve_state, _trid_2);
                }
                for(BTuple<Nodes, Slots> param : _trid_2) {
                    Slots _tmp_1 = param.projection2();
                    Nodes _tmp_2 = param.projection1();

                    rether copiedState = state._copy();
                    _ProjectionRead_reserve readState = state._projected_state_for_reserve();
                    PersistentHashMap _OpCache_with_parameter_reserve = (PersistentHashMap) GET.invoke(_OpCache_reserve, param);
                    if(_OpCache_with_parameter_reserve != null) {
                        _ProjectionWrite_reserve writeState = (_ProjectionWrite_reserve) GET.invoke(_OpCache_with_parameter_reserve, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_reserve(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.reserve(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_reserve();
                            _OpCache_with_parameter_reserve = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_reserve, readState, writeState);
                            _OpCache_reserve = (PersistentHashMap) ASSOC.invoke(_OpCache_reserve, param, _OpCache_with_parameter_reserve);
                        }

                    } else {
                        copiedState.reserve(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_reserve writeState = copiedState._update_for_reserve();
                        _OpCache_with_parameter_reserve = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_reserve = (PersistentHashMap) ASSOC.invoke(_OpCache_reserve, param, _OpCache_with_parameter_reserve);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_release read__tr_release_state = state._projected_state_for__tr_release();
                BSet<BTuple<Nodes, Slots>> _trid_3 = (BSet<BTuple<Nodes, Slots>>) GET.invoke(_OpCache_tr_release, read__tr_release_state);
                if(_trid_3 == null) {
                    _trid_3 = state._tr_release();
                    _OpCache_tr_release = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_release, read__tr_release_state, _trid_3);
                }
                for(BTuple<Nodes, Slots> param : _trid_3) {
                    Slots _tmp_1 = param.projection2();
                    Nodes _tmp_2 = param.projection1();

                    rether copiedState = state._copy();
                    _ProjectionRead_release readState = state._projected_state_for_release();
                    PersistentHashMap _OpCache_with_parameter_release = (PersistentHashMap) GET.invoke(_OpCache_release, param);
                    if(_OpCache_with_parameter_release != null) {
                        _ProjectionWrite_release writeState = (_ProjectionWrite_release) GET.invoke(_OpCache_with_parameter_release, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_release(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.release(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_release();
                            _OpCache_with_parameter_release = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_release, readState, writeState);
                            _OpCache_release = (PersistentHashMap) ASSOC.invoke(_OpCache_release, param, _OpCache_with_parameter_release);
                        }

                    } else {
                        copiedState.release(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_release writeState = copiedState._update_for_release();
                        _OpCache_with_parameter_release = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_release = (PersistentHashMap) ASSOC.invoke(_OpCache_release, param, _OpCache_with_parameter_release);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_grant read__tr_grant_state = state._projected_state_for__tr_grant();
                BSet<BTuple<Nodes, Slots>> _trid_4 = (BSet<BTuple<Nodes, Slots>>) GET.invoke(_OpCache_tr_grant, read__tr_grant_state);
                if(_trid_4 == null) {
                    _trid_4 = state._tr_grant();
                    _OpCache_tr_grant = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_grant, read__tr_grant_state, _trid_4);
                }
                for(BTuple<Nodes, Slots> param : _trid_4) {
                    Slots _tmp_1 = param.projection2();
                    Nodes _tmp_2 = param.projection1();

                    rether copiedState = state._copy();
                    _ProjectionRead_grant readState = state._projected_state_for_grant();
                    PersistentHashMap _OpCache_with_parameter_grant = (PersistentHashMap) GET.invoke(_OpCache_grant, param);
                    if(_OpCache_with_parameter_grant != null) {
                        _ProjectionWrite_grant writeState = (_ProjectionWrite_grant) GET.invoke(_OpCache_with_parameter_grant, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_grant(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.grant(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_grant();
                            _OpCache_with_parameter_grant = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_grant, readState, writeState);
                            _OpCache_grant = (PersistentHashMap) ASSOC.invoke(_OpCache_grant, param, _OpCache_with_parameter_grant);
                        }

                    } else {
                        copiedState.grant(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_grant writeState = copiedState._update_for_grant();
                        _OpCache_with_parameter_grant = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_grant = (PersistentHashMap) ASSOC.invoke(_OpCache_grant, param, _OpCache_with_parameter_grant);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_no_grant read__tr_no_grant_state = state._projected_state_for__tr_no_grant();
                BSet<BTuple<Nodes, Slots>> _trid_5 = (BSet<BTuple<Nodes, Slots>>) GET.invoke(_OpCache_tr_no_grant, read__tr_no_grant_state);
                if(_trid_5 == null) {
                    _trid_5 = state._tr_no_grant();
                    _OpCache_tr_no_grant = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_no_grant, read__tr_no_grant_state, _trid_5);
                }
                for(BTuple<Nodes, Slots> param : _trid_5) {
                    Slots _tmp_1 = param.projection2();
                    Nodes _tmp_2 = param.projection1();

                    rether copiedState = state._copy();
                    _ProjectionRead_no_grant readState = state._projected_state_for_no_grant();
                    PersistentHashMap _OpCache_with_parameter_no_grant = (PersistentHashMap) GET.invoke(_OpCache_no_grant, param);
                    if(_OpCache_with_parameter_no_grant != null) {
                        _ProjectionWrite_no_grant writeState = (_ProjectionWrite_no_grant) GET.invoke(_OpCache_with_parameter_no_grant, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_no_grant(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.no_grant(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_no_grant();
                            _OpCache_with_parameter_no_grant = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_no_grant, readState, writeState);
                            _OpCache_no_grant = (PersistentHashMap) ASSOC.invoke(_OpCache_no_grant, param, _OpCache_with_parameter_no_grant);
                        }

                    } else {
                        copiedState.no_grant(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_no_grant writeState = copiedState._update_for_no_grant();
                        _OpCache_with_parameter_no_grant = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_no_grant = (PersistentHashMap) ASSOC.invoke(_OpCache_no_grant, param, _OpCache_with_parameter_no_grant);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_use_RT_Slot read__tr_use_RT_Slot_state = state._projected_state_for__tr_use_RT_Slot();
                BSet<BTuple<Nodes, Slots>> _trid_6 = (BSet<BTuple<Nodes, Slots>>) GET.invoke(_OpCache_tr_use_RT_Slot, read__tr_use_RT_Slot_state);
                if(_trid_6 == null) {
                    _trid_6 = state._tr_use_RT_Slot();
                    _OpCache_tr_use_RT_Slot = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_use_RT_Slot, read__tr_use_RT_Slot_state, _trid_6);
                }
                for(BTuple<Nodes, Slots> param : _trid_6) {
                    Slots _tmp_1 = param.projection2();
                    Nodes _tmp_2 = param.projection1();

                    rether copiedState = state._copy();
                    _ProjectionRead_use_RT_Slot readState = state._projected_state_for_use_RT_Slot();
                    PersistentHashMap _OpCache_with_parameter_use_RT_Slot = (PersistentHashMap) GET.invoke(_OpCache_use_RT_Slot, param);
                    if(_OpCache_with_parameter_use_RT_Slot != null) {
                        _ProjectionWrite_use_RT_Slot writeState = (_ProjectionWrite_use_RT_Slot) GET.invoke(_OpCache_with_parameter_use_RT_Slot, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_use_RT_Slot(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.use_RT_Slot(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_use_RT_Slot();
                            _OpCache_with_parameter_use_RT_Slot = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_use_RT_Slot, readState, writeState);
                            _OpCache_use_RT_Slot = (PersistentHashMap) ASSOC.invoke(_OpCache_use_RT_Slot, param, _OpCache_with_parameter_use_RT_Slot);
                        }

                    } else {
                        copiedState.use_RT_Slot(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_use_RT_Slot writeState = copiedState._update_for_use_RT_Slot();
                        _OpCache_with_parameter_use_RT_Slot = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_use_RT_Slot = (PersistentHashMap) ASSOC.invoke(_OpCache_use_RT_Slot, param, _OpCache_with_parameter_use_RT_Slot);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_use_NRT_Slot read__tr_use_NRT_Slot_state = state._projected_state_for__tr_use_NRT_Slot();
                BSet<BTuple<Nodes, Slots>> _trid_7 = (BSet<BTuple<Nodes, Slots>>) GET.invoke(_OpCache_tr_use_NRT_Slot, read__tr_use_NRT_Slot_state);
                if(_trid_7 == null) {
                    _trid_7 = state._tr_use_NRT_Slot();
                    _OpCache_tr_use_NRT_Slot = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_use_NRT_Slot, read__tr_use_NRT_Slot_state, _trid_7);
                }
                for(BTuple<Nodes, Slots> param : _trid_7) {
                    Slots _tmp_1 = param.projection2();
                    Nodes _tmp_2 = param.projection1();

                    rether copiedState = state._copy();
                    _ProjectionRead_use_NRT_Slot readState = state._projected_state_for_use_NRT_Slot();
                    PersistentHashMap _OpCache_with_parameter_use_NRT_Slot = (PersistentHashMap) GET.invoke(_OpCache_use_NRT_Slot, param);
                    if(_OpCache_with_parameter_use_NRT_Slot != null) {
                        _ProjectionWrite_use_NRT_Slot writeState = (_ProjectionWrite_use_NRT_Slot) GET.invoke(_OpCache_with_parameter_use_NRT_Slot, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_use_NRT_Slot(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.use_NRT_Slot(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_use_NRT_Slot();
                            _OpCache_with_parameter_use_NRT_Slot = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_use_NRT_Slot, readState, writeState);
                            _OpCache_use_NRT_Slot = (PersistentHashMap) ASSOC.invoke(_OpCache_use_NRT_Slot, param, _OpCache_with_parameter_use_NRT_Slot);
                        }

                    } else {
                        copiedState.use_NRT_Slot(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_use_NRT_Slot writeState = copiedState._update_for_use_NRT_Slot();
                        _OpCache_with_parameter_use_NRT_Slot = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_use_NRT_Slot = (PersistentHashMap) ASSOC.invoke(_OpCache_use_NRT_Slot, param, _OpCache_with_parameter_use_NRT_Slot);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_pass_token read__tr_pass_token_state = state._projected_state_for__tr_pass_token();
                BSet<Nodes> _trid_8 = (BSet<Nodes>) GET.invoke(_OpCache_tr_pass_token, read__tr_pass_token_state);
                if(_trid_8 == null) {
                    _trid_8 = state._tr_pass_token();
                    _OpCache_tr_pass_token = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_pass_token, read__tr_pass_token_state, _trid_8);
                }
                for(Nodes param : _trid_8) {
                    Nodes _tmp_1 = param;

                    rether copiedState = state._copy();
                    _ProjectionRead_pass_token readState = state._projected_state_for_pass_token();
                    PersistentHashMap _OpCache_with_parameter_pass_token = (PersistentHashMap) GET.invoke(_OpCache_pass_token, param);
                    if(_OpCache_with_parameter_pass_token != null) {
                        _ProjectionWrite_pass_token writeState = (_ProjectionWrite_pass_token) GET.invoke(_OpCache_with_parameter_pass_token, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_pass_token(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.pass_token(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_pass_token();
                            _OpCache_with_parameter_pass_token = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_pass_token, readState, writeState);
                            _OpCache_pass_token = (PersistentHashMap) ASSOC.invoke(_OpCache_pass_token, param, _OpCache_with_parameter_pass_token);
                        }

                    } else {
                        copiedState.pass_token(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_pass_token writeState = copiedState._update_for_pass_token();
                        _OpCache_with_parameter_pass_token = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_pass_token = (PersistentHashMap) ASSOC.invoke(_OpCache_pass_token, param, _OpCache_with_parameter_pass_token);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            } else {
                BSet<BTuple<Slots, Slots>> _trid_1 = state._tr_elapse_time();
                for(BTuple<Slots, Slots> param : _trid_1) {
                    Slots _tmp_1 = param.projection2();
                    Slots _tmp_2 = param.projection1();

                    rether copiedState = state._copy();
                    copiedState.elapse_time(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<Nodes, Slots>> _trid_2 = state._tr_reserve();
                for(BTuple<Nodes, Slots> param : _trid_2) {
                    Slots _tmp_1 = param.projection2();
                    Nodes _tmp_2 = param.projection1();

                    rether copiedState = state._copy();
                    copiedState.reserve(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<Nodes, Slots>> _trid_3 = state._tr_release();
                for(BTuple<Nodes, Slots> param : _trid_3) {
                    Slots _tmp_1 = param.projection2();
                    Nodes _tmp_2 = param.projection1();

                    rether copiedState = state._copy();
                    copiedState.release(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<Nodes, Slots>> _trid_4 = state._tr_grant();
                for(BTuple<Nodes, Slots> param : _trid_4) {
                    Slots _tmp_1 = param.projection2();
                    Nodes _tmp_2 = param.projection1();

                    rether copiedState = state._copy();
                    copiedState.grant(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<Nodes, Slots>> _trid_5 = state._tr_no_grant();
                for(BTuple<Nodes, Slots> param : _trid_5) {
                    Slots _tmp_1 = param.projection2();
                    Nodes _tmp_2 = param.projection1();

                    rether copiedState = state._copy();
                    copiedState.no_grant(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<Nodes, Slots>> _trid_6 = state._tr_use_RT_Slot();
                for(BTuple<Nodes, Slots> param : _trid_6) {
                    Slots _tmp_1 = param.projection2();
                    Nodes _tmp_2 = param.projection1();

                    rether copiedState = state._copy();
                    copiedState.use_RT_Slot(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<Nodes, Slots>> _trid_7 = state._tr_use_NRT_Slot();
                for(BTuple<Nodes, Slots> param : _trid_7) {
                    Slots _tmp_1 = param.projection2();
                    Nodes _tmp_2 = param.projection1();

                    rether copiedState = state._copy();
                    copiedState.use_NRT_Slot(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<Nodes> _trid_8 = state._tr_pass_token();
                for(Nodes param : _trid_8) {
                    Nodes _tmp_1 = param;

                    rether copiedState = state._copy();
                    copiedState.pass_token(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            }
            return result;
        }

        private boolean invariantViolated(final rether state) {
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
