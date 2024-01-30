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
    public Set<String> dependentGuard = new HashSet<>();
    public PersistentHashMap guardCache = PersistentHashMap.EMPTY;
    public Set<String> dependentInvariant = new HashSet<>();
    public String stateAccessedVia;



    private static BSet<BInteger> NATSET;


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
        BUSwrite = new BRelation<BInteger, BInteger>(new BTuple<>(new BInteger(0), new BInteger(0)));
        BUSvalue = new BInteger(0);
        BUSpriority = new BInteger(0);
        T2_mode = T2mode.T2MODE_SENSE;
    }


    public CAN_BUS_tlc(BSet<BInteger> NATSET, BInteger BUSpriority, BInteger BUSvalue, BRelation<BInteger, BInteger> BUSwrite, T1state T1_state, BInteger T1_timer, BInteger T1_writevalue, T2mode T2_mode, BInteger T2_readpriority, BInteger T2_readvalue, T2state T2_state, BInteger T2_timer, BInteger T2_writevalue, BInteger T2v, BBoolean T3_enabled, BBoolean T3_evaluated, BInteger T3_readpriority, BInteger T3_readvalue, T3state T3_state) {
        this.NATSET = NATSET;
        this.BUSpriority = BUSpriority;
        this.BUSvalue = BUSvalue;
        this.BUSwrite = BUSwrite;
        this.T1_state = T1_state;
        this.T1_timer = T1_timer;
        this.T1_writevalue = T1_writevalue;
        this.T2_mode = T2_mode;
        this.T2_readpriority = T2_readpriority;
        this.T2_readvalue = T2_readvalue;
        this.T2_state = T2_state;
        this.T2_timer = T2_timer;
        this.T2_writevalue = T2_writevalue;
        this.T2v = T2v;
        this.T3_enabled = T3_enabled;
        this.T3_evaluated = T3_evaluated;
        this.T3_readpriority = T3_readpriority;
        this.T3_readvalue = T3_readvalue;
        this.T3_state = T3_state;
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
        BUSwrite = _ld_BUSwrite.override(new BRelation<BInteger, BInteger>(new BTuple<>(ppriority, pv)));
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
        BUSwrite = _ld_BUSwrite.override(new BRelation<BInteger, BInteger>(new BTuple<>(ppriority, pv)));
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
        BUSwrite = _ld_BUSwrite.override(new BRelation<BInteger, BInteger>(new BTuple<>(ppriority, pv)));
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


    public boolean _tr_T1Evaluate() {
        return new BBoolean(T1_timer.equal(new BInteger(0)).booleanValue() && T1_state.equal(T1state.T1_EN).booleanValue()).booleanValue();
    }

    public BSet<BInteger> _tr_T1Calculate() {
        BSet<BInteger> _ic_set_1 = new BSet<BInteger>();
        for(BInteger _ic_p_1 : BSet.interval(new BInteger(1).negative(), new BInteger(3))) {
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
                    _ic_set_2 = _ic_set_2.union(new BSet<BTuple<BInteger, BInteger>>(new BTuple<>(_ic_ppriority_1, _ic_pv_1)));
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
                    _ic_set_5 = _ic_set_5.union(new BSet<BTuple<BInteger, BInteger>>(new BTuple<>(_ic_ppriority_1, _ic_pv_1)));
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
            if((new BBoolean(BUSwrite.domain().elementOf(_ic_ppriority_1).booleanValue() && T2_state.equal(T2state.T2_RELEASE).booleanValue())).booleanValue()) {
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
                    _ic_set_10 = _ic_set_10.union(new BSet<BTuple<BInteger, BInteger>>(new BTuple<>(_ic_ppriority_1, _ic_pv_1)));
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
                    _ic_set_14 = _ic_set_14.union(new BSet<BTuple<BInteger, BInteger>>(new BTuple<>(_ic_ppriority_1, _ic_pv_1)));
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
                    _ic_set_15 = _ic_set_15.union(new BSet<BTuple<BInteger, BInteger>>(new BTuple<>(_ic_ppriority_1, _ic_pv_1)));
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

    public boolean _check_inv_1() {
        return T2v.isInteger().booleanValue();
    }

    public boolean _check_inv_2() {
        return BUtils.BOOL.elementOf(T3_evaluated).booleanValue();
    }

    public boolean _check_inv_3() {
        return BUtils.BOOL.elementOf(T3_enabled).booleanValue();
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
        return BUSwrite.domain().elementOf(new BInteger(0)).booleanValue();
    }

    public CAN_BUS_tlc _copy() {
        return new CAN_BUS_tlc(NATSET, BUSpriority, BUSvalue, BUSwrite, T1_state, T1_timer, T1_writevalue, T2_mode, T2_readpriority, T2_readvalue, T2_state, T2_timer, T2_writevalue, T2v, T3_enabled, T3_evaluated, T3_readpriority, T3_readvalue, T3_state);
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

        private final Map<String, Set<String>> invariantDependency = new HashMap<>();
        private final Map<String, Set<String>> guardDependency = new HashMap<>();

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

            if(isCaching) {
                initCache(machine);
            }

            while(!unvisitedStates.isEmpty()) {
                CAN_BUS_tlc state = next();

                Set<CAN_BUS_tlc> nextStates = generateNextStates(state);

                nextStates.forEach(nextState -> {
                    if(!states.contains(nextState)) {
                        states.add(nextState);
                        unvisitedStates.add(nextState);
                        if(states.size() % 50000 == 0 && isDebug) {
                            System.out.println("VISITED STATES: " + states.size());
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

            if(isCaching) {
                initCache(machine);
            }

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
                            if(states.size() % 50000 == 0 && isDebug) {
                                System.out.println("VISITED STATES: " + states.size());
                                System.out.println("EVALUATED TRANSITIONS: " + transitions.get());
                                System.out.println("-------------------");
                            }
                        }
                    });

                    synchronized (unvisitedStates) {
                        int running = possibleQueueChanges.decrementAndGet();
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

        private void initCache(final CAN_BUS_tlc machine) {
            invariantDependency.put("T1Wait", new HashSet<>(Arrays.asList("_check_inv_10", "_check_inv_4")));
            invariantDependency.put("T1Calculate", new HashSet<>(Arrays.asList("_check_inv_7", "_check_inv_4")));
            invariantDependency.put("T1SendResult", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_19", "_check_inv_20", "_check_inv_4")));
            invariantDependency.put("T2ReadBus", new HashSet<>(Arrays.asList("_check_inv_17", "_check_inv_5", "_check_inv_9")));
            invariantDependency.put("T2Reset", new HashSet<>(Arrays.asList("_check_inv_1", "_check_inv_5", "_check_inv_8", "_check_inv_12")));
            invariantDependency.put("T2Complete", new HashSet<>(Arrays.asList("_check_inv_5", "_check_inv_12")));
            invariantDependency.put("T2Evaluate", new HashSet<>(Arrays.asList("_check_inv_5", "_check_inv_11")));
            invariantDependency.put("T3Evaluate", new HashSet<>(Arrays.asList("_check_inv_6")));
            invariantDependency.put("T3ReleaseBus", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_19", "_check_inv_6", "_check_inv_20")));
            invariantDependency.put("T1Evaluate", new HashSet<>(Arrays.asList("_check_inv_10", "_check_inv_4")));
            invariantDependency.put("T3Initiate", new HashSet<>(Arrays.asList("_check_inv_3", "_check_inv_6")));
            invariantDependency.put("T3ReEnableWait", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_3", "_check_inv_6")));
            invariantDependency.put("T3writebus", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_19", "_check_inv_6", "_check_inv_20")));
            invariantDependency.put("Update", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_10", "_check_inv_14", "_check_inv_13", "_check_inv_11")));
            invariantDependency.put("T2ReleaseBus", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_19", "_check_inv_20", "_check_inv_5")));
            invariantDependency.put("T2Wait", new HashSet<>(Arrays.asList("_check_inv_5", "_check_inv_11")));
            invariantDependency.put("T3Poll", new HashSet<>(Arrays.asList("_check_inv_6")));
            invariantDependency.put("T2Calculate", new HashSet<>(Arrays.asList("_check_inv_1", "_check_inv_5")));
            invariantDependency.put("T3Read", new HashSet<>(Arrays.asList("_check_inv_16", "_check_inv_15", "_check_inv_6")));
            invariantDependency.put("T3Wait", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_6")));
            invariantDependency.put("T2WriteBus", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_19", "_check_inv_20", "_check_inv_5")));
            guardDependency.put("T1Wait", new HashSet<>(Arrays.asList("_tr_T1Evaluate", "_tr_Update", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait")));
            guardDependency.put("T1Calculate", new HashSet<>(Arrays.asList("_tr_T1Evaluate", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait")));
            guardDependency.put("T1SendResult", new HashSet<>(Arrays.asList("_tr_T1Evaluate", "_tr_T2ReleaseBus", "_tr_Update", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait")));
            guardDependency.put("T2ReadBus", new HashSet<>(Arrays.asList("_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait")));
            guardDependency.put("T2Reset", new HashSet<>(Arrays.asList("_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait")));
            guardDependency.put("T2Complete", new HashSet<>(Arrays.asList("_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait")));
            guardDependency.put("T2Evaluate", new HashSet<>(Arrays.asList("_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait")));
            guardDependency.put("T3Evaluate", new HashSet<>(Arrays.asList("_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate")));
            guardDependency.put("T3ReleaseBus", new HashSet<>(Arrays.asList("_tr_T2ReleaseBus", "_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate")));
            guardDependency.put("T1Evaluate", new HashSet<>(Arrays.asList("_tr_T1Evaluate", "_tr_Update", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait")));
            guardDependency.put("T3Initiate", new HashSet<>(Arrays.asList("_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate")));
            guardDependency.put("T3ReEnableWait", new HashSet<>(Arrays.asList("_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate")));
            guardDependency.put("T3writebus", new HashSet<>(Arrays.asList("_tr_T2ReleaseBus", "_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate")));
            guardDependency.put("Update", new HashSet<>(Arrays.asList("_tr_T1Evaluate", "_tr_T3Read", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T3Evaluate", "_tr_T3Initiate")));
            guardDependency.put("T2ReleaseBus", new HashSet<>(Arrays.asList("_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait")));
            guardDependency.put("T2Wait", new HashSet<>(Arrays.asList("_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait")));
            guardDependency.put("T3Poll", new HashSet<>(Arrays.asList("_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate")));
            guardDependency.put("T2Calculate", new HashSet<>(Arrays.asList("_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait")));
            guardDependency.put("T3Read", new HashSet<>(Arrays.asList("_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate")));
            guardDependency.put("T3Wait", new HashSet<>(Arrays.asList("_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate")));
            guardDependency.put("T2WriteBus", new HashSet<>(Arrays.asList("_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait")));
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
                PersistentHashMap parentsGuard = state.guardCache;
                PersistentHashMap newCache = parentsGuard == null ? PersistentHashMap.EMPTY : parentsGuard;
                Object cachedValue = null;
                boolean dependentGuardsBoolean = true;
                boolean _trid_1;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_T1Evaluate");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_T1Evaluate");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_1 = state._tr_T1Evaluate();
                } else {
                    _trid_1 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_T1Evaluate", _trid_1);
                if(_trid_1) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T1Evaluate();
                    copiedState.parent = state;
                    addCachedInfos("T1Evaluate", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BInteger> _trid_2;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_T1Calculate");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_T1Calculate");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_2 = state._tr_T1Calculate();
                } else {
                    _trid_2 = (BSet<BInteger>) cachedValue;
                }
                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_T1Calculate", _trid_2);
                for(BInteger param : _trid_2) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T1Calculate(_tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("T1Calculate", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BInteger, BInteger>> _trid_3;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_T1SendResult");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_T1SendResult");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_3 = state._tr_T1SendResult();
                } else {
                    _trid_3 = (BSet<BTuple<BInteger, BInteger>>) cachedValue;
                }
                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_T1SendResult", _trid_3);
                for(BTuple<BInteger, BInteger> param : _trid_3) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T1SendResult(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("T1SendResult", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BInteger> _trid_4;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_T1Wait");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_T1Wait");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_4 = state._tr_T1Wait();
                } else {
                    _trid_4 = (BSet<BInteger>) cachedValue;
                }
                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_T1Wait", _trid_4);
                for(BInteger param : _trid_4) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T1Wait(_tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("T1Wait", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_5;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_T2Evaluate");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_T2Evaluate");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_5 = state._tr_T2Evaluate();
                } else {
                    _trid_5 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_T2Evaluate", _trid_5);
                if(_trid_5) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2Evaluate();
                    copiedState.parent = state;
                    addCachedInfos("T2Evaluate", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BInteger, BInteger>> _trid_6;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_T2ReadBus");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_T2ReadBus");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_6 = state._tr_T2ReadBus();
                } else {
                    _trid_6 = (BSet<BTuple<BInteger, BInteger>>) cachedValue;
                }
                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_T2ReadBus", _trid_6);
                for(BTuple<BInteger, BInteger> param : _trid_6) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2ReadBus(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("T2ReadBus", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_7;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_T2Reset");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_T2Reset");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_7 = state._tr_T2Reset();
                } else {
                    _trid_7 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_T2Reset", _trid_7);
                if(_trid_7) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2Reset();
                    copiedState.parent = state;
                    addCachedInfos("T2Reset", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_8;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_T2Complete");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_T2Complete");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_8 = state._tr_T2Complete();
                } else {
                    _trid_8 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_T2Complete", _trid_8);
                if(_trid_8) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2Complete();
                    copiedState.parent = state;
                    addCachedInfos("T2Complete", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BInteger> _trid_9;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_T2ReleaseBus");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_T2ReleaseBus");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_9 = state._tr_T2ReleaseBus();
                } else {
                    _trid_9 = (BSet<BInteger>) cachedValue;
                }
                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_T2ReleaseBus", _trid_9);
                for(BInteger param : _trid_9) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2ReleaseBus(_tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("T2ReleaseBus", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_10;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_T2Calculate");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_T2Calculate");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_10 = state._tr_T2Calculate();
                } else {
                    _trid_10 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_T2Calculate", _trid_10);
                if(_trid_10) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2Calculate();
                    copiedState.parent = state;
                    addCachedInfos("T2Calculate", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BInteger, BInteger>> _trid_11;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_T2WriteBus");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_T2WriteBus");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_11 = state._tr_T2WriteBus();
                } else {
                    _trid_11 = (BSet<BTuple<BInteger, BInteger>>) cachedValue;
                }
                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_T2WriteBus", _trid_11);
                for(BTuple<BInteger, BInteger> param : _trid_11) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2WriteBus(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("T2WriteBus", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BInteger> _trid_12;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_T2Wait");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_T2Wait");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_12 = state._tr_T2Wait();
                } else {
                    _trid_12 = (BSet<BInteger>) cachedValue;
                }
                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_T2Wait", _trid_12);
                for(BInteger param : _trid_12) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2Wait(_tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("T2Wait", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_13;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_T3Initiate");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_T3Initiate");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_13 = state._tr_T3Initiate();
                } else {
                    _trid_13 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_T3Initiate", _trid_13);
                if(_trid_13) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3Initiate();
                    copiedState.parent = state;
                    addCachedInfos("T3Initiate", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_14;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_T3Evaluate");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_T3Evaluate");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_14 = state._tr_T3Evaluate();
                } else {
                    _trid_14 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_T3Evaluate", _trid_14);
                if(_trid_14) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3Evaluate();
                    copiedState.parent = state;
                    addCachedInfos("T3Evaluate", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BInteger, BInteger>> _trid_15;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_T3writebus");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_T3writebus");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_15 = state._tr_T3writebus();
                } else {
                    _trid_15 = (BSet<BTuple<BInteger, BInteger>>) cachedValue;
                }
                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_T3writebus", _trid_15);
                for(BTuple<BInteger, BInteger> param : _trid_15) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3writebus(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("T3writebus", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BInteger, BInteger>> _trid_16;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_T3Read");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_T3Read");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_16 = state._tr_T3Read();
                } else {
                    _trid_16 = (BSet<BTuple<BInteger, BInteger>>) cachedValue;
                }
                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_T3Read", _trid_16);
                for(BTuple<BInteger, BInteger> param : _trid_16) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3Read(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("T3Read", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_17;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_T3Poll");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_T3Poll");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_17 = state._tr_T3Poll();
                } else {
                    _trid_17 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_T3Poll", _trid_17);
                if(_trid_17) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3Poll();
                    copiedState.parent = state;
                    addCachedInfos("T3Poll", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BInteger> _trid_18;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_T3ReleaseBus");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_T3ReleaseBus");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_18 = state._tr_T3ReleaseBus();
                } else {
                    _trid_18 = (BSet<BInteger>) cachedValue;
                }
                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_T3ReleaseBus", _trid_18);
                for(BInteger param : _trid_18) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3ReleaseBus(_tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("T3ReleaseBus", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_19;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_T3Wait");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_T3Wait");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_19 = state._tr_T3Wait();
                } else {
                    _trid_19 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_T3Wait", _trid_19);
                if(_trid_19) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3Wait();
                    copiedState.parent = state;
                    addCachedInfos("T3Wait", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_20;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_T3ReEnableWait");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_T3ReEnableWait");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_20 = state._tr_T3ReEnableWait();
                } else {
                    _trid_20 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_T3ReEnableWait", _trid_20);
                if(_trid_20) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3ReEnableWait();
                    copiedState.parent = state;
                    addCachedInfos("T3ReEnableWait", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BInteger> _trid_21;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_Update");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_Update");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_21 = state._tr_Update();
                } else {
                    _trid_21 = (BSet<BInteger>) cachedValue;
                }
                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_Update", _trid_21);
                for(BInteger param : _trid_21) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.Update(_tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("Update", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

                state.guardCache = newCache;
            } else {
                if(state._tr_T1Evaluate()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T1Evaluate();
                    copiedState.parent = state;
                    addCachedInfos("T1Evaluate", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BInteger> _trid_2 = state._tr_T1Calculate();
                for(BInteger param : _trid_2) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T1Calculate(_tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("T1Calculate", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BInteger, BInteger>> _trid_3 = state._tr_T1SendResult();
                for(BTuple<BInteger, BInteger> param : _trid_3) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T1SendResult(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("T1SendResult", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BInteger> _trid_4 = state._tr_T1Wait();
                for(BInteger param : _trid_4) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T1Wait(_tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("T1Wait", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_T2Evaluate()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2Evaluate();
                    copiedState.parent = state;
                    addCachedInfos("T2Evaluate", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BInteger, BInteger>> _trid_6 = state._tr_T2ReadBus();
                for(BTuple<BInteger, BInteger> param : _trid_6) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2ReadBus(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("T2ReadBus", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_T2Reset()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2Reset();
                    copiedState.parent = state;
                    addCachedInfos("T2Reset", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_T2Complete()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2Complete();
                    copiedState.parent = state;
                    addCachedInfos("T2Complete", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BInteger> _trid_9 = state._tr_T2ReleaseBus();
                for(BInteger param : _trid_9) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2ReleaseBus(_tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("T2ReleaseBus", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_T2Calculate()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2Calculate();
                    copiedState.parent = state;
                    addCachedInfos("T2Calculate", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BInteger, BInteger>> _trid_11 = state._tr_T2WriteBus();
                for(BTuple<BInteger, BInteger> param : _trid_11) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2WriteBus(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("T2WriteBus", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BInteger> _trid_12 = state._tr_T2Wait();
                for(BInteger param : _trid_12) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T2Wait(_tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("T2Wait", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_T3Initiate()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3Initiate();
                    copiedState.parent = state;
                    addCachedInfos("T3Initiate", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_T3Evaluate()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3Evaluate();
                    copiedState.parent = state;
                    addCachedInfos("T3Evaluate", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BInteger, BInteger>> _trid_15 = state._tr_T3writebus();
                for(BTuple<BInteger, BInteger> param : _trid_15) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3writebus(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("T3writebus", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BInteger, BInteger>> _trid_16 = state._tr_T3Read();
                for(BTuple<BInteger, BInteger> param : _trid_16) {
                    BInteger _tmp_1 = param.projection2();
                    BInteger _tmp_2 = param.projection1();

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3Read(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("T3Read", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_T3Poll()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3Poll();
                    copiedState.parent = state;
                    addCachedInfos("T3Poll", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BInteger> _trid_18 = state._tr_T3ReleaseBus();
                for(BInteger param : _trid_18) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3ReleaseBus(_tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("T3ReleaseBus", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_T3Wait()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3Wait();
                    copiedState.parent = state;
                    addCachedInfos("T3Wait", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_T3ReEnableWait()) {
                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.T3ReEnableWait();
                    copiedState.parent = state;
                    addCachedInfos("T3ReEnableWait", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BInteger> _trid_21 = state._tr_Update();
                for(BInteger param : _trid_21) {
                    BInteger _tmp_1 = param;

                    CAN_BUS_tlc copiedState = state._copy();
                    copiedState.Update(_tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("Update", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            }
            return result;
        }

        private boolean invariantViolated(final CAN_BUS_tlc state) {
            if(!isCaching || state.dependentInvariant.contains("_check_inv_1")) {
                if(!state._check_inv_1()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_1");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_2")) {
                if(!state._check_inv_2()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_2");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_3")) {
                if(!state._check_inv_3()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_3");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_4")) {
                if(!state._check_inv_4()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_4");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_5")) {
                if(!state._check_inv_5()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_5");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_6")) {
                if(!state._check_inv_6()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_6");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_7")) {
                if(!state._check_inv_7()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_7");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_8")) {
                if(!state._check_inv_8()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_8");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_9")) {
                if(!state._check_inv_9()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_9");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_10")) {
                if(!state._check_inv_10()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_10");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_11")) {
                if(!state._check_inv_11()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_11");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_12")) {
                if(!state._check_inv_12()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_12");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_13")) {
                if(!state._check_inv_13()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_13");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_14")) {
                if(!state._check_inv_14()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_14");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_15")) {
                if(!state._check_inv_15()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_15");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_16")) {
                if(!state._check_inv_16()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_16");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_17")) {
                if(!state._check_inv_17()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_17");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_18")) {
                if(!state._check_inv_18()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_18");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_19")) {
                if(!state._check_inv_19()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_19");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_20")) {
                if(!state._check_inv_20()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_20");
                    return true;
                }
            }
            return false;
        }

        private void addCachedInfos(final String operation, final CAN_BUS_tlc state, final CAN_BUS_tlc copiedState) {
            if(isCaching) {
                copiedState.dependentInvariant = invariantDependency.get(operation);
                copiedState.dependentGuard = guardDependency.get(operation);
            }
            copiedState.stateAccessedVia = operation;
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

        ModelChecker modelchecker = new ModelChecker(type, threads, isCaching, isDebug);
        modelchecker.modelCheck();
    }




}
