import de.hhu.stups.btypes.BRelation;
import de.hhu.stups.btypes.BTuple;
import de.hhu.stups.btypes.BSet;
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


public class sort_m2_data1000_MC {


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

    public sort_m2_data1000_MC parent;
    public String stateAccessedVia;

    public static class _ProjectionRead_progress {

        public BRelation<BInteger, BInteger> g;
        public BInteger j;
        public BInteger k;
        public BInteger l;

        public _ProjectionRead_progress(BRelation<BInteger, BInteger> g, BInteger j, BInteger k, BInteger l) {
            this.g = g;
            this.j = j;
            this.k = k;
            this.l = l;
        }

        public String toString() {
            return "{" + "g: " + this.g + "," + "j: " + this.j + "," + "k: " + this.k + "," + "l: " + this.l + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_progress)) {
                return false;
            }
            _ProjectionRead_progress o = (_ProjectionRead_progress) other;
            return this.g.equals(o.g) && this.j.equals(o.j) && this.k.equals(o.k) && this.l.equals(o.l);
        }

        public int hashCode() {
            return Objects.hash(g, j, k, l);
        }
    }

    public static class _ProjectionRead__tr_progress {

        public BInteger j;
        public BInteger k;

        public _ProjectionRead__tr_progress(BInteger j, BInteger k) {
            this.j = j;
            this.k = k;
        }

        public String toString() {
            return "{" + "j: " + this.j + "," + "k: " + this.k + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_progress)) {
                return false;
            }
            _ProjectionRead__tr_progress o = (_ProjectionRead__tr_progress) other;
            return this.j.equals(o.j) && this.k.equals(o.k);
        }

        public int hashCode() {
            return Objects.hash(j, k);
        }
    }

    public static class _ProjectionWrite_progress {

        public BRelation<BInteger, BInteger> g;
        public BInteger j;
        public BInteger k;
        public BInteger l;

        public _ProjectionWrite_progress(BRelation<BInteger, BInteger> g, BInteger j, BInteger k, BInteger l) {
            this.g = g;
            this.j = j;
            this.k = k;
            this.l = l;
        }

        public String toString() {
            return "{" + "g: " + this.g + "," + "j: " + this.j + "," + "k: " + this.k + "," + "l: " + this.l + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_progress)) {
                return false;
            }
            _ProjectionWrite_progress o = (_ProjectionWrite_progress) other;
            return this.g.equals(o.g) && this.j.equals(o.j) && this.k.equals(o.k) && this.l.equals(o.l);
        }

        public int hashCode() {
            return Objects.hash(g, j, k, l);
        }
    }

    public static class _ProjectionRead_prog1 {

        public BRelation<BInteger, BInteger> g;
        public BInteger j;
        public BInteger k;
        public BInteger l;

        public _ProjectionRead_prog1(BRelation<BInteger, BInteger> g, BInteger j, BInteger k, BInteger l) {
            this.g = g;
            this.j = j;
            this.k = k;
            this.l = l;
        }

        public String toString() {
            return "{" + "g: " + this.g + "," + "j: " + this.j + "," + "k: " + this.k + "," + "l: " + this.l + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_prog1)) {
                return false;
            }
            _ProjectionRead_prog1 o = (_ProjectionRead_prog1) other;
            return this.g.equals(o.g) && this.j.equals(o.j) && this.k.equals(o.k) && this.l.equals(o.l);
        }

        public int hashCode() {
            return Objects.hash(g, j, k, l);
        }
    }

    public static class _ProjectionRead__tr_prog1 {

        public BRelation<BInteger, BInteger> g;
        public BInteger j;
        public BInteger k;
        public BInteger l;

        public _ProjectionRead__tr_prog1(BRelation<BInteger, BInteger> g, BInteger j, BInteger k, BInteger l) {
            this.g = g;
            this.j = j;
            this.k = k;
            this.l = l;
        }

        public String toString() {
            return "{" + "g: " + this.g + "," + "j: " + this.j + "," + "k: " + this.k + "," + "l: " + this.l + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_prog1)) {
                return false;
            }
            _ProjectionRead__tr_prog1 o = (_ProjectionRead__tr_prog1) other;
            return this.g.equals(o.g) && this.j.equals(o.j) && this.k.equals(o.k) && this.l.equals(o.l);
        }

        public int hashCode() {
            return Objects.hash(g, j, k, l);
        }
    }

    public static class _ProjectionWrite_prog1 {

        public BInteger j;
        public BInteger l;

        public _ProjectionWrite_prog1(BInteger j, BInteger l) {
            this.j = j;
            this.l = l;
        }

        public String toString() {
            return "{" + "j: " + this.j + "," + "l: " + this.l + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_prog1)) {
                return false;
            }
            _ProjectionWrite_prog1 o = (_ProjectionWrite_prog1) other;
            return this.j.equals(o.j) && this.l.equals(o.l);
        }

        public int hashCode() {
            return Objects.hash(j, l);
        }
    }

    public static class _ProjectionRead_prog2 {

        public BRelation<BInteger, BInteger> g;
        public BInteger j;
        public BInteger k;
        public BInteger l;

        public _ProjectionRead_prog2(BRelation<BInteger, BInteger> g, BInteger j, BInteger k, BInteger l) {
            this.g = g;
            this.j = j;
            this.k = k;
            this.l = l;
        }

        public String toString() {
            return "{" + "g: " + this.g + "," + "j: " + this.j + "," + "k: " + this.k + "," + "l: " + this.l + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_prog2)) {
                return false;
            }
            _ProjectionRead_prog2 o = (_ProjectionRead_prog2) other;
            return this.g.equals(o.g) && this.j.equals(o.j) && this.k.equals(o.k) && this.l.equals(o.l);
        }

        public int hashCode() {
            return Objects.hash(g, j, k, l);
        }
    }

    public static class _ProjectionRead__tr_prog2 {

        public BRelation<BInteger, BInteger> g;
        public BInteger j;
        public BInteger k;
        public BInteger l;

        public _ProjectionRead__tr_prog2(BRelation<BInteger, BInteger> g, BInteger j, BInteger k, BInteger l) {
            this.g = g;
            this.j = j;
            this.k = k;
            this.l = l;
        }

        public String toString() {
            return "{" + "g: " + this.g + "," + "j: " + this.j + "," + "k: " + this.k + "," + "l: " + this.l + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_prog2)) {
                return false;
            }
            _ProjectionRead__tr_prog2 o = (_ProjectionRead__tr_prog2) other;
            return this.g.equals(o.g) && this.j.equals(o.j) && this.k.equals(o.k) && this.l.equals(o.l);
        }

        public int hashCode() {
            return Objects.hash(g, j, k, l);
        }
    }

    public static class _ProjectionWrite_prog2 {

        public BInteger j;
        public BInteger l;

        public _ProjectionWrite_prog2(BInteger j, BInteger l) {
            this.j = j;
            this.l = l;
        }

        public String toString() {
            return "{" + "j: " + this.j + "," + "l: " + this.l + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_prog2)) {
                return false;
            }
            _ProjectionWrite_prog2 o = (_ProjectionWrite_prog2) other;
            return this.j.equals(o.j) && this.l.equals(o.l);
        }

        public int hashCode() {
            return Objects.hash(j, l);
        }
    }

    public static class _ProjectionRead_final_evt {

        public BInteger k;

        public _ProjectionRead_final_evt(BInteger k) {
            this.k = k;
        }

        public String toString() {
            return "{" + "k: " + this.k + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_final_evt)) {
                return false;
            }
            _ProjectionRead_final_evt o = (_ProjectionRead_final_evt) other;
            return this.k.equals(o.k);
        }

        public int hashCode() {
            return Objects.hash(k);
        }
    }

    public static class _ProjectionRead__tr_final_evt {

        public BInteger k;

        public _ProjectionRead__tr_final_evt(BInteger k) {
            this.k = k;
        }

        public String toString() {
            return "{" + "k: " + this.k + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_final_evt)) {
                return false;
            }
            _ProjectionRead__tr_final_evt o = (_ProjectionRead__tr_final_evt) other;
            return this.k.equals(o.k);
        }

        public int hashCode() {
            return Objects.hash(k);
        }
    }

    public static class _ProjectionWrite_final_evt {


        public _ProjectionWrite_final_evt() {
        }

        public String toString() {
            return "{}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_final_evt)) {
                return false;
            }
            _ProjectionWrite_final_evt o = (_ProjectionWrite_final_evt) other;
            return true;
        }

        public int hashCode() {
            return Objects.hash();
        }
    }

    public static class _ProjectionRead__check_inv_1 {

        public BInteger j;
        public BInteger k;

        public _ProjectionRead__check_inv_1(BInteger j, BInteger k) {
            this.j = j;
            this.k = k;
        }

        public String toString() {
            return "{" + "j: " + this.j + "," + "k: " + this.k + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_1)) {
                return false;
            }
            _ProjectionRead__check_inv_1 o = (_ProjectionRead__check_inv_1) other;
            return this.j.equals(o.j) && this.k.equals(o.k);
        }

        public int hashCode() {
            return Objects.hash(j, k);
        }
    }

    public static class _ProjectionRead__check_inv_2 {

        public BInteger j;

        public _ProjectionRead__check_inv_2(BInteger j) {
            this.j = j;
        }

        public String toString() {
            return "{" + "j: " + this.j + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_2)) {
                return false;
            }
            _ProjectionRead__check_inv_2 o = (_ProjectionRead__check_inv_2) other;
            return this.j.equals(o.j);
        }

        public int hashCode() {
            return Objects.hash(j);
        }
    }

    public static class _ProjectionRead__check_inv_3 {

        public BInteger k;
        public BInteger l;

        public _ProjectionRead__check_inv_3(BInteger k, BInteger l) {
            this.k = k;
            this.l = l;
        }

        public String toString() {
            return "{" + "k: " + this.k + "," + "l: " + this.l + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_3)) {
                return false;
            }
            _ProjectionRead__check_inv_3 o = (_ProjectionRead__check_inv_3) other;
            return this.k.equals(o.k) && this.l.equals(o.l);
        }

        public int hashCode() {
            return Objects.hash(k, l);
        }
    }

    public static class _ProjectionRead__check_inv_4 {

        public BInteger j;

        public _ProjectionRead__check_inv_4(BInteger j) {
            this.j = j;
        }

        public String toString() {
            return "{" + "j: " + this.j + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_4)) {
                return false;
            }
            _ProjectionRead__check_inv_4 o = (_ProjectionRead__check_inv_4) other;
            return this.j.equals(o.j);
        }

        public int hashCode() {
            return Objects.hash(j);
        }
    }

    public static class _ProjectionRead__check_inv_5 {

        public BRelation<BInteger, BInteger> g;
        public BInteger j;
        public BInteger k;
        public BInteger l;

        public _ProjectionRead__check_inv_5(BRelation<BInteger, BInteger> g, BInteger j, BInteger k, BInteger l) {
            this.g = g;
            this.j = j;
            this.k = k;
            this.l = l;
        }

        public String toString() {
            return "{" + "g: " + this.g + "," + "j: " + this.j + "," + "k: " + this.k + "," + "l: " + this.l + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_5)) {
                return false;
            }
            _ProjectionRead__check_inv_5 o = (_ProjectionRead__check_inv_5) other;
            return this.g.equals(o.g) && this.j.equals(o.j) && this.k.equals(o.k) && this.l.equals(o.l);
        }

        public int hashCode() {
            return Objects.hash(g, j, k, l);
        }
    }

    public static class _ProjectionRead__check_inv_6 {

        public BRelation<BInteger, BInteger> g;

        public _ProjectionRead__check_inv_6(BRelation<BInteger, BInteger> g) {
            this.g = g;
        }

        public String toString() {
            return "{" + "g: " + this.g + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_6)) {
                return false;
            }
            _ProjectionRead__check_inv_6 o = (_ProjectionRead__check_inv_6) other;
            return this.g.equals(o.g);
        }

        public int hashCode() {
            return Objects.hash(g);
        }
    }




    private static BInteger n;
    private static BRelation<BInteger, BInteger> f;




    private BInteger j;
    private BInteger k;
    private BInteger l;
    private BRelation<BInteger, BInteger> g;

    static {
        n = new BInteger(1000);
        BRelation<BInteger, BInteger> _ic_set_0 = new BRelation<BInteger, BInteger>();
        for(BInteger _ic_i_1 : BSet.interval(new BInteger(1), n)) {
            _ic_set_0 = _ic_set_0.union(new BRelation<BInteger, BInteger>(new BTuple<>(_ic_i_1, new BInteger(15000).minus(_ic_i_1))));

        }
        f = _ic_set_0;
    }

    public sort_m2_data1000_MC() {
        g = f;
        k = new BInteger(1);
        l = new BInteger(1);
        j = new BInteger(1);
    }

    public sort_m2_data1000_MC(sort_m2_data1000_MC copy) {
        this.n = copy.n;
        this.f = copy.f;
        this.j = copy.j;
        this.k = copy.k;
        this.l = copy.l;
        this.g = copy.g;
    }

    public void progress() {
        BRelation<BInteger, BInteger> _ld_g = g;
        BInteger _ld_k = k;
        BInteger _ld_l = l;
        g = _ld_g.override(new BRelation<BInteger, BInteger>(new BTuple<>(_ld_k, _ld_g.functionCall(_ld_l))).override(new BRelation<BInteger, BInteger>(new BTuple<>(_ld_l, _ld_g.functionCall(_ld_k)))));
        k = _ld_k.plus(new BInteger(1));
        j = _ld_k.plus(new BInteger(1));
        l = _ld_k.plus(new BInteger(1));

    }

    public void prog1() {
        BInteger _ld_j = j;
        BInteger _ld_l = l;
        l = _ld_l;
        j = _ld_j.plus(new BInteger(1));

    }

    public void prog2() {
        BInteger _ld_j = j;
        j = _ld_j.plus(new BInteger(1));
        l = _ld_j.plus(new BInteger(1));

    }

    public void final_evt() {
    }

    public BInteger _get_n() {
        return n;
    }

    public BRelation<BInteger, BInteger> _get_f() {
        return f;
    }

    public BInteger _get_j() {
        return j;
    }

    public BInteger _get_k() {
        return k;
    }

    public BInteger _get_l() {
        return l;
    }

    public BRelation<BInteger, BInteger> _get_g() {
        return g;
    }

    @Override
    public boolean equals(Object o) {
        sort_m2_data1000_MC o1 = this;
        sort_m2_data1000_MC o2 = (sort_m2_data1000_MC) o;
        return o1._get_j().equals(o2._get_j()) && o1._get_k().equals(o2._get_k()) && o1._get_l().equals(o2._get_l()) && o1._get_g().equals(o2._get_g());
    }



    @Override
    public int hashCode() {
        return this._hashCode_1();
    }

    public int _hashCode_1() {
        int result = 1;
        result = (1543 * result) ^ ((this._get_j()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_k()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_l()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_g()).hashCode() << 1);
        return result;
    }

    public int _hashCode_2() {
        int result = 1;
        result = (6151 * result) ^ ((this._get_j()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_k()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_l()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_g()).hashCode() << 1);
        return result;
    }

    @Override
    public String toString() {
        return String.join("\n", "_get_j: " + (this._get_j()).toString(), "_get_k: " + (this._get_k()).toString(), "_get_l: " + (this._get_l()).toString(), "_get_g: " + (this._get_g()).toString());
    }

    public sort_m2_data1000_MC _copy() {
        return new sort_m2_data1000_MC(this);
    }


    public boolean _tr_progress() {
        return new BBoolean(k.unequal(n).booleanValue() && j.equal(n).booleanValue()).booleanValue();
    }

    public boolean _tr_prog1() {
        return new BBoolean(new BBoolean(k.unequal(n).booleanValue() && j.unequal(n).booleanValue()).booleanValue() && g.functionCall(l).lessEqual(g.functionCall(j.plus(new BInteger(1)))).booleanValue()).booleanValue();
    }

    public boolean _tr_prog2() {
        return new BBoolean(new BBoolean(k.unequal(n).booleanValue() && j.unequal(n).booleanValue()).booleanValue() && g.functionCall(l).greater(g.functionCall(j.plus(new BInteger(1)))).booleanValue()).booleanValue();
    }

    public boolean _tr_final_evt() {
        return k.equal(n).booleanValue();
    }

    public _ProjectionRead_prog2 _projected_state_for_prog2() {
        return new _ProjectionRead_prog2(g,j,k,l);
    }

    public _ProjectionRead_prog1 _projected_state_for_prog1() {
        return new _ProjectionRead_prog1(g,j,k,l);
    }

    public _ProjectionRead_progress _projected_state_for_progress() {
        return new _ProjectionRead_progress(g,j,k,l);
    }

    public _ProjectionRead_final_evt _projected_state_for_final_evt() {
        return new _ProjectionRead_final_evt(k);
    }

    public _ProjectionRead__tr_final_evt _projected_state_for__tr_final_evt() {
        return new _ProjectionRead__tr_final_evt(k);
    }

    public _ProjectionRead__tr_progress _projected_state_for__tr_progress() {
        return new _ProjectionRead__tr_progress(j,k);
    }

    public _ProjectionRead__tr_prog1 _projected_state_for__tr_prog1() {
        return new _ProjectionRead__tr_prog1(g,j,k,l);
    }

    public _ProjectionRead__tr_prog2 _projected_state_for__tr_prog2() {
        return new _ProjectionRead__tr_prog2(g,j,k,l);
    }

    public _ProjectionRead__check_inv_2 _projected_state_for__check_inv_2() {
        return new _ProjectionRead__check_inv_2(j);
    }

    public _ProjectionRead__check_inv_3 _projected_state_for__check_inv_3() {
        return new _ProjectionRead__check_inv_3(k,l);
    }

    public _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() {
        return new _ProjectionRead__check_inv_1(j,k);
    }

    public _ProjectionRead__check_inv_6 _projected_state_for__check_inv_6() {
        return new _ProjectionRead__check_inv_6(g);
    }

    public _ProjectionRead__check_inv_4 _projected_state_for__check_inv_4() {
        return new _ProjectionRead__check_inv_4(j);
    }

    public _ProjectionRead__check_inv_5 _projected_state_for__check_inv_5() {
        return new _ProjectionRead__check_inv_5(g,j,k,l);
    }

    public _ProjectionWrite_prog2 _update_for_prog2() {
        return new _ProjectionWrite_prog2(j,l);
    }

    public _ProjectionWrite_prog1 _update_for_prog1() {
        return new _ProjectionWrite_prog1(j,l);
    }

    public _ProjectionWrite_progress _update_for_progress() {
        return new _ProjectionWrite_progress(g,j,k,l);
    }

    public _ProjectionWrite_final_evt _update_for_final_evt() {
        return new _ProjectionWrite_final_evt();
    }

    public void _apply_update_for_prog2(_ProjectionWrite_prog2 update) {
        this.j = update.j;
        this.l = update.l;
    }

    public void _apply_update_for_prog1(_ProjectionWrite_prog1 update) {
        this.j = update.j;
        this.l = update.l;
    }

    public void _apply_update_for_progress(_ProjectionWrite_progress update) {
        this.g = update.g;
        this.j = update.j;
        this.k = update.k;
        this.l = update.l;
    }

    public void _apply_update_for_final_evt(_ProjectionWrite_final_evt update) {
    }

    public boolean _check_inv_1() {
        return j.greaterEqual(k).booleanValue();
    }

    public boolean _check_inv_2() {
        return j.lessEqual(n).booleanValue();
    }

    public boolean _check_inv_3() {
        return l.greaterEqual(k).booleanValue();
    }

    public boolean _check_inv_4() {
        return j.lessEqual(j).booleanValue();
    }

    public boolean _check_inv_5() {
        return g.functionCall(l).equal(g.relationImage(BSet.interval(k, j)).min()).booleanValue();
    }

    public boolean _check_inv_6() {
        return g.checkDomain(BSet.interval(new BInteger(1), n)).and(g.checkRangeNatural()).and(g.isFunction()).and(g.isTotal(BSet.interval(new BInteger(1), n))).booleanValue();
    }


    private static class ModelChecker {
        private final Type type;
        private final int threads;
        private final boolean isCaching;
        private final boolean isDebug;

        private final LinkedList<sort_m2_data1000_MC> unvisitedStates = new LinkedList<>();
        private final Set<sort_m2_data1000_MC> states = ConcurrentHashMap.newKeySet();
        private AtomicInteger transitions = new AtomicInteger(0);
        private ThreadPoolExecutor threadPool;
        private Object waitLock = new Object();

        private AtomicBoolean invariantViolated = new AtomicBoolean(false);
        private AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        private sort_m2_data1000_MC counterExampleState = null;

        PersistentHashMap _OpCache_progress = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_progress = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_prog1 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_prog1 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_prog2 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_prog2 = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_final_evt = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_final_evt = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_1 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_2 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_3 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_4 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_5 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_6 = PersistentHashMap.EMPTY;

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
            sort_m2_data1000_MC machine = new sort_m2_data1000_MC();
            states.add(machine);
            unvisitedStates.add(machine);

            while(!unvisitedStates.isEmpty()) {
                sort_m2_data1000_MC state = next();

                Set<sort_m2_data1000_MC> nextStates = generateNextStates(state);

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
            sort_m2_data1000_MC machine = new sort_m2_data1000_MC();
            states.add(machine);
            unvisitedStates.add(machine);

            AtomicBoolean stopThreads = new AtomicBoolean(false);
            AtomicInteger possibleQueueChanges = new AtomicInteger(0);

            while(!unvisitedStates.isEmpty() && !stopThreads.get()) {
                possibleQueueChanges.incrementAndGet();
                sort_m2_data1000_MC state = next();
                Runnable task = () -> {
                    Set<sort_m2_data1000_MC> nextStates = generateNextStates(state);

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

        private sort_m2_data1000_MC next() {
            synchronized(this.unvisitedStates) {
                return switch(type) {
                    case BFS -> this.unvisitedStates.removeFirst();
                    case DFS -> this.unvisitedStates.removeLast();
                    case MIXED -> this.unvisitedStates.size() % 2 == 0 ? this.unvisitedStates.removeFirst() : this.unvisitedStates.removeLast();
                };
            }
        }

        @SuppressWarnings("unchecked")
        private Set<sort_m2_data1000_MC> generateNextStates(final sort_m2_data1000_MC state) {
            Set<sort_m2_data1000_MC> result = new HashSet<>();
            if(isCaching) {
                _ProjectionRead__tr_progress read__tr_progress_state = state._projected_state_for__tr_progress();
                Object _obj__trid_1 = GET.invoke(_OpCache_tr_progress, read__tr_progress_state);
                boolean _trid_1;
                if(_obj__trid_1 == null) {
                    _trid_1 = state._tr_progress();
                    _OpCache_tr_progress = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_progress, read__tr_progress_state, _trid_1);
                } else {
                    _trid_1 = (boolean) _obj__trid_1;
                }
                if(_trid_1) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    _ProjectionRead_progress readState = state._projected_state_for_progress();
                    PersistentHashMap _OpCache_with_parameter_progress = (PersistentHashMap) GET.invoke(_OpCache_progress, _trid_1);
                    if(_OpCache_with_parameter_progress != null) {
                        _ProjectionWrite_progress writeState = (_ProjectionWrite_progress) GET.invoke(_OpCache_with_parameter_progress, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_progress(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.progress();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_progress();
                            _OpCache_with_parameter_progress = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_progress, readState, writeState);
                            _OpCache_progress = (PersistentHashMap) ASSOC.invoke(_OpCache_progress, _trid_1, _OpCache_with_parameter_progress);
                        }

                    } else {
                        copiedState.progress();
                        copiedState.parent = state;
                        _ProjectionWrite_progress writeState = copiedState._update_for_progress();
                        _OpCache_with_parameter_progress = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_progress = (PersistentHashMap) ASSOC.invoke(_OpCache_progress, _trid_1, _OpCache_with_parameter_progress);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_prog1 read__tr_prog1_state = state._projected_state_for__tr_prog1();
                Object _obj__trid_2 = GET.invoke(_OpCache_tr_prog1, read__tr_prog1_state);
                boolean _trid_2;
                if(_obj__trid_2 == null) {
                    _trid_2 = state._tr_prog1();
                    _OpCache_tr_prog1 = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_prog1, read__tr_prog1_state, _trid_2);
                } else {
                    _trid_2 = (boolean) _obj__trid_2;
                }
                if(_trid_2) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    _ProjectionRead_prog1 readState = state._projected_state_for_prog1();
                    PersistentHashMap _OpCache_with_parameter_prog1 = (PersistentHashMap) GET.invoke(_OpCache_prog1, _trid_2);
                    if(_OpCache_with_parameter_prog1 != null) {
                        _ProjectionWrite_prog1 writeState = (_ProjectionWrite_prog1) GET.invoke(_OpCache_with_parameter_prog1, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_prog1(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.prog1();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_prog1();
                            _OpCache_with_parameter_prog1 = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_prog1, readState, writeState);
                            _OpCache_prog1 = (PersistentHashMap) ASSOC.invoke(_OpCache_prog1, _trid_2, _OpCache_with_parameter_prog1);
                        }

                    } else {
                        copiedState.prog1();
                        copiedState.parent = state;
                        _ProjectionWrite_prog1 writeState = copiedState._update_for_prog1();
                        _OpCache_with_parameter_prog1 = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_prog1 = (PersistentHashMap) ASSOC.invoke(_OpCache_prog1, _trid_2, _OpCache_with_parameter_prog1);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_prog2 read__tr_prog2_state = state._projected_state_for__tr_prog2();
                Object _obj__trid_3 = GET.invoke(_OpCache_tr_prog2, read__tr_prog2_state);
                boolean _trid_3;
                if(_obj__trid_3 == null) {
                    _trid_3 = state._tr_prog2();
                    _OpCache_tr_prog2 = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_prog2, read__tr_prog2_state, _trid_3);
                } else {
                    _trid_3 = (boolean) _obj__trid_3;
                }
                if(_trid_3) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    _ProjectionRead_prog2 readState = state._projected_state_for_prog2();
                    PersistentHashMap _OpCache_with_parameter_prog2 = (PersistentHashMap) GET.invoke(_OpCache_prog2, _trid_3);
                    if(_OpCache_with_parameter_prog2 != null) {
                        _ProjectionWrite_prog2 writeState = (_ProjectionWrite_prog2) GET.invoke(_OpCache_with_parameter_prog2, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_prog2(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.prog2();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_prog2();
                            _OpCache_with_parameter_prog2 = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_prog2, readState, writeState);
                            _OpCache_prog2 = (PersistentHashMap) ASSOC.invoke(_OpCache_prog2, _trid_3, _OpCache_with_parameter_prog2);
                        }

                    } else {
                        copiedState.prog2();
                        copiedState.parent = state;
                        _ProjectionWrite_prog2 writeState = copiedState._update_for_prog2();
                        _OpCache_with_parameter_prog2 = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_prog2 = (PersistentHashMap) ASSOC.invoke(_OpCache_prog2, _trid_3, _OpCache_with_parameter_prog2);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_final_evt read__tr_final_evt_state = state._projected_state_for__tr_final_evt();
                Object _obj__trid_4 = GET.invoke(_OpCache_tr_final_evt, read__tr_final_evt_state);
                boolean _trid_4;
                if(_obj__trid_4 == null) {
                    _trid_4 = state._tr_final_evt();
                    _OpCache_tr_final_evt = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_final_evt, read__tr_final_evt_state, _trid_4);
                } else {
                    _trid_4 = (boolean) _obj__trid_4;
                }
                if(_trid_4) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    _ProjectionRead_final_evt readState = state._projected_state_for_final_evt();
                    PersistentHashMap _OpCache_with_parameter_final_evt = (PersistentHashMap) GET.invoke(_OpCache_final_evt, _trid_4);
                    if(_OpCache_with_parameter_final_evt != null) {
                        _ProjectionWrite_final_evt writeState = (_ProjectionWrite_final_evt) GET.invoke(_OpCache_with_parameter_final_evt, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_final_evt(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.final_evt();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_final_evt();
                            _OpCache_with_parameter_final_evt = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_final_evt, readState, writeState);
                            _OpCache_final_evt = (PersistentHashMap) ASSOC.invoke(_OpCache_final_evt, _trid_4, _OpCache_with_parameter_final_evt);
                        }

                    } else {
                        copiedState.final_evt();
                        copiedState.parent = state;
                        _ProjectionWrite_final_evt writeState = copiedState._update_for_final_evt();
                        _OpCache_with_parameter_final_evt = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_final_evt = (PersistentHashMap) ASSOC.invoke(_OpCache_final_evt, _trid_4, _OpCache_with_parameter_final_evt);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            } else {
                if(state._tr_progress()) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    copiedState.progress();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_prog1()) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    copiedState.prog1();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_prog2()) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    copiedState.prog2();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_final_evt()) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    copiedState.final_evt();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            }
            return result;
        }

        private boolean invariantViolated(final sort_m2_data1000_MC state) {
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
