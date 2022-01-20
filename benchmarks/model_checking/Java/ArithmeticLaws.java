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


public class ArithmeticLaws {


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







    private BInteger x;
    private BInteger y;
    private BInteger z;

    public ArithmeticLaws() {
        x = new BInteger(3).negative();
        y = new BInteger(3).negative();
        z = new BInteger(3).negative();
    }

    public ArithmeticLaws(BInteger x, BInteger y, BInteger z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public void IncX() {
        x = x.plus(new BInteger(1));

    }

    public void IncY() {
        y = y.plus(new BInteger(1));

    }

    public void IncZ() {
        z = z.plus(new BInteger(1));

    }

    public void Reset() {
        x = new BInteger(3).negative();
        y = new BInteger(3).negative();
        z = new BInteger(3).negative();
    }

    public BInteger _get_x() {
        return x;
    }

    public BInteger _get_y() {
        return y;
    }

    public BInteger _get_z() {
        return z;
    }


    public boolean _tr_IncX() {
        return x.less(new BInteger(50)).booleanValue();
    }

    public boolean _tr_IncY() {
        return y.less(new BInteger(9)).booleanValue();
    }

    public boolean _tr_IncZ() {
        return z.less(new BInteger(4)).booleanValue();
    }

    public boolean _tr_Reset() {
        return true;
    }

    public boolean _check_inv_1() {
        return x.isInteger().booleanValue();
    }

    public boolean _check_inv_2() {
        return y.isInteger().booleanValue();
    }

    public boolean _check_inv_3() {
        return z.isInteger().booleanValue();
    }

    public boolean _check_inv_4() {
        return x.multiply(y).equal(y.multiply(x)).booleanValue();
    }

    public boolean _check_inv_5() {
        return x.multiply(y.plus(z)).equal(x.multiply(y).plus(x.multiply(z))).booleanValue();
    }

    public boolean _check_inv_6() {
        return x.plus(y).equal(y.plus(x)).booleanValue();
    }

    public boolean _check_inv_7() {
        return x.multiply(new BInteger(1)).equal(x).booleanValue();
    }

    public boolean _check_inv_8() {
        return new BInteger(1).multiply(x).equal(x).booleanValue();
    }

    public boolean _check_inv_9() {
        return x.multiply(new BInteger(0)).equal(new BInteger(0)).booleanValue();
    }

    public boolean _check_inv_10() {
        return new BInteger(0).multiply(x).equal(new BInteger(0)).booleanValue();
    }

    public boolean _check_inv_11() {
        return x.plus(y).plus(z).equal(x.plus(y.plus(z))).booleanValue();
    }

    public boolean _check_inv_12() {
        return x.multiply(y).multiply(z).equal(x.multiply(y.multiply(z))).booleanValue();
    }

    public boolean _check_inv_13() {
        return new BInteger(2).multiply(x).equal(x.plus(x)).booleanValue();
    }

    public boolean _check_inv_14() {
        return x.power(new BInteger(2)).equal(x.multiply(x)).booleanValue();
    }

    public boolean _check_inv_15() {
        return new BBoolean(!x.greaterEqual(new BInteger(0)).booleanValue() || new BBoolean((!x.divide(new BInteger(2)).multiply(new BInteger(2)).equal(x).booleanValue() || x.modulo(new BInteger(2)).equal(new BInteger(0)).booleanValue()) && (!x.modulo(new BInteger(2)).equal(new BInteger(0)).booleanValue() || x.divide(new BInteger(2)).multiply(new BInteger(2)).equal(x).booleanValue())).booleanValue()).booleanValue();
    }

    public boolean _check_inv_16() {
        return new BBoolean(!x.greater(new BInteger(0)).booleanValue() || new BInteger(2).power(x).equal(new BInteger(2).multiply(new BInteger(2).power(x.minus(new BInteger(1))))).booleanValue()).booleanValue();
    }

    public boolean _check_inv_17() {
        return new BBoolean(!x.greater(new BInteger(0)).booleanValue() || new BInteger(2).power(new BInteger(10).multiply(x)).equal(new BInteger(2).multiply(new BInteger(2).power(new BInteger(10).multiply(x).minus(new BInteger(1))))).booleanValue()).booleanValue();
    }

    public boolean _check_inv_18() {
        return new BBoolean(!x.greater(new BInteger(0)).booleanValue() || new BInteger(3).power(new BInteger(10).multiply(x)).equal(new BInteger(3).multiply(new BInteger(3).power(new BInteger(10).multiply(x).minus(new BInteger(1))))).booleanValue()).booleanValue();
    }

    public boolean _check_inv_19() {
        BSet<BInteger> _ic_set_4 = new BSet<BInteger>();
        if(new BBoolean(new BBoolean(x.greaterEqual(new BInteger(0)).booleanValue() && y.greater(new BInteger(0)).booleanValue()).booleanValue() && x.modulo(y).equal(x.minus(y.multiply(x.divide(y)))).booleanValue()).booleanValue()) {
            for(BInteger _ic_q_1 : BSet.interval(new BInteger(0), x)) {
                if((x.less(y.multiply(_ic_q_1.plus(new BInteger(1))))).booleanValue()) {
                    _ic_set_4 = _ic_set_4.union(new BSet<BInteger>(_ic_q_1));
                }

            }
        }

        return new BBoolean(!y.unequal(new BInteger(0)).booleanValue() || new BBoolean(new BBoolean(x.negative().divide(y).equal(x.divide(y).negative()).booleanValue() && x.divide(y.negative()).equal(x.divide(y).negative()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(x.greaterEqual(new BInteger(0)).booleanValue() && y.greater(new BInteger(0)).booleanValue()).booleanValue() || new BBoolean(x.modulo(y).equal(x.minus(y.multiply(x.divide(y)))).booleanValue() && x.divide(y).equal(_ic_set_4.min()).booleanValue()).booleanValue()).booleanValue()).booleanValue()).booleanValue();
    }

    public boolean _check_inv_20() {
        return new BBoolean(x.greater(y).booleanValue() || x.lessEqual(y).booleanValue()).booleanValue();
    }

    public boolean _check_inv_21() {
        return new BBoolean(new BBoolean(x.greater(y).booleanValue() || x.equal(y).booleanValue()).booleanValue() || x.less(y).booleanValue()).booleanValue();
    }

    public boolean _check_inv_22() {
        return new BBoolean(x.greaterEqual(y).booleanValue() || x.less(y).booleanValue()).booleanValue();
    }

    public boolean _check_inv_23() {
        return new BBoolean(x.greaterEqual(y).booleanValue() || x.lessEqual(y).booleanValue()).booleanValue();
    }

    public boolean _check_inv_24() {
        return new BBoolean(x.greater(y).booleanValue() && x.lessEqual(y).booleanValue()).not().booleanValue();
    }

    public boolean _check_inv_25() {
        return new BBoolean(x.less(y).booleanValue() && y.less(x).booleanValue()).not().booleanValue();
    }

    public boolean _check_inv_26() {
        return x.minus(x).equal(new BInteger(0)).booleanValue();
    }

    public boolean _check_inv_27() {
        return new BBoolean((!x.equal(y).booleanValue() || x.minus(y).equal(new BInteger(0)).booleanValue()) && (!x.minus(y).equal(new BInteger(0)).booleanValue() || x.equal(y).booleanValue())).booleanValue();
    }

    public boolean _check_inv_28() {
        return new BBoolean((!x.greater(y).booleanValue() || x.greaterEqual(y.plus(new BInteger(1))).booleanValue()) && (!x.greaterEqual(y.plus(new BInteger(1))).booleanValue() || x.greater(y).booleanValue())).booleanValue();
    }

    public boolean _check_inv_29() {
        return new BBoolean((!x.less(y).booleanValue() || x.lessEqual(y.minus(new BInteger(1))).booleanValue()) && (!x.lessEqual(y.minus(new BInteger(1))).booleanValue() || x.less(y).booleanValue())).booleanValue();
    }

    public boolean _check_inv_30() {
        return new BBoolean((!new BBoolean(x.less(y).booleanValue() || y.less(x).booleanValue()).booleanValue() || x.unequal(y).booleanValue()) && (!x.unequal(y).booleanValue() || new BBoolean(x.less(y).booleanValue() || y.less(x).booleanValue()).booleanValue())).booleanValue();
    }

    public boolean _check_inv_31() {
        return new BBoolean(!new BBoolean(x.less(y).booleanValue() && y.lessEqual(z).booleanValue()).booleanValue() || x.less(z).booleanValue()).booleanValue();
    }

    public boolean _check_inv_32() {
        return new BBoolean(!new BBoolean(x.less(y).booleanValue() && y.less(z).booleanValue()).booleanValue() || x.less(z).booleanValue()).booleanValue();
    }

    public boolean _check_inv_33() {
        return new BBoolean(!new BBoolean(x.lessEqual(y).booleanValue() && y.less(z).booleanValue()).booleanValue() || x.less(z).booleanValue()).booleanValue();
    }

    public boolean _check_inv_34() {
        return new BBoolean(!new BBoolean(x.lessEqual(y).booleanValue() && y.lessEqual(z).booleanValue()).booleanValue() || x.lessEqual(z).booleanValue()).booleanValue();
    }

    public boolean _check_inv_35() {
        return new BBoolean(!new BBoolean(x.lessEqual(y).booleanValue() && y.lessEqual(x).booleanValue()).booleanValue() || x.equal(y).booleanValue()).booleanValue();
    }

    public boolean _check_inv_36() {
        return new BBoolean((!x.equal(y).booleanValue() || y.equal(x).booleanValue()) && (!y.equal(x).booleanValue() || x.equal(y).booleanValue())).booleanValue();
    }

    public boolean _check_inv_37() {
        return new BBoolean((!x.unequal(y).booleanValue() || y.unequal(x).booleanValue()) && (!y.unequal(x).booleanValue() || x.unequal(y).booleanValue())).booleanValue();
    }

    public boolean _check_inv_38() {
        return new BBoolean((!x.less(y).booleanValue() || y.greater(x).booleanValue()) && (!y.greater(x).booleanValue() || x.less(y).booleanValue())).booleanValue();
    }

    public boolean _check_inv_39() {
        return new BBoolean((!x.greater(y).booleanValue() || y.less(x).booleanValue()) && (!y.less(x).booleanValue() || x.greater(y).booleanValue())).booleanValue();
    }

    public boolean _check_inv_40() {
        return new BBoolean((!x.lessEqual(y).booleanValue() || y.greaterEqual(x).booleanValue()) && (!y.greaterEqual(x).booleanValue() || x.lessEqual(y).booleanValue())).booleanValue();
    }

    public boolean _check_inv_41() {
        return new BBoolean((!x.greaterEqual(y).booleanValue() || y.lessEqual(x).booleanValue()) && (!y.lessEqual(x).booleanValue() || x.greaterEqual(y).booleanValue())).booleanValue();
    }

    public boolean _check_inv_42() {
        return new BBoolean((!x.less(y).not().booleanValue() || x.greaterEqual(y).booleanValue()) && (!x.greaterEqual(y).booleanValue() || x.less(y).not().booleanValue())).booleanValue();
    }

    public boolean _check_inv_43() {
        return new BBoolean((!x.lessEqual(y).not().booleanValue() || x.greater(y).booleanValue()) && (!x.greater(y).booleanValue() || x.lessEqual(y).not().booleanValue())).booleanValue();
    }

    public boolean _check_inv_44() {
        return new BBoolean(!new BBoolean(x.equal(y).booleanValue() || x.equal(z).booleanValue()).booleanValue() || new BBoolean(y.equal(x).booleanValue() || z.equal(x).booleanValue()).booleanValue()).booleanValue();
    }

    public boolean _check_inv_45() {
        return new BBoolean((!new BBoolean(x.equal(y).booleanValue() || x.equal(z).booleanValue()).booleanValue() || new BBoolean(y.equal(x).booleanValue() || z.equal(x).booleanValue()).booleanValue()) && (!new BBoolean(y.equal(x).booleanValue() || z.equal(x).booleanValue()).booleanValue() || new BBoolean(x.equal(y).booleanValue() || x.equal(z).booleanValue()).booleanValue())).booleanValue();
    }

    public boolean _check_inv_46() {
        return new BBoolean(!new BBoolean((!x.equal(y).booleanValue() || x.equal(z).booleanValue()) && (!x.equal(z).booleanValue() || x.equal(y).booleanValue())).booleanValue() || new BBoolean(y.equal(z).booleanValue() || x.unequal(y).booleanValue()).booleanValue()).booleanValue();
    }

    public boolean _check_inv_47() {
        return x.minus(y).minus(x).plus(y).equal(new BInteger(0)).booleanValue();
    }

    public boolean _check_inv_48() {
        return x.multiply(x).greaterEqual(new BInteger(0)).booleanValue();
    }

    public boolean _check_inv_49() {
        return new BBoolean((!x.multiply(x).equal(new BInteger(0)).booleanValue() || x.equal(new BInteger(0)).booleanValue()) && (!x.equal(new BInteger(0)).booleanValue() || x.multiply(x).equal(new BInteger(0)).booleanValue())).booleanValue();
    }

    public boolean _check_inv_50() {
        return x.multiply(x).equal(x.negative().multiply(x.negative())).booleanValue();
    }

    public boolean _check_inv_51() {
        return new BBoolean((!x.lessEqual(y).booleanValue() || new BSet<BInteger>(x, y).min().equal(x).booleanValue()) && (!new BSet<BInteger>(x, y).min().equal(x).booleanValue() || x.lessEqual(y).booleanValue())).booleanValue();
    }

    public boolean _check_inv_52() {
        return new BBoolean((!x.lessEqual(y).booleanValue() || new BSet<BInteger>(x, y).max().equal(y).booleanValue()) && (!new BSet<BInteger>(x, y).max().equal(y).booleanValue() || x.lessEqual(y).booleanValue())).booleanValue();
    }

    public boolean _check_inv_53() {
        return new BBoolean((!x.less(y).booleanValue() || new BSet<BInteger>(x, y).max().unequal(x).booleanValue()) && (!new BSet<BInteger>(x, y).max().unequal(x).booleanValue() || x.less(y).booleanValue())).booleanValue();
    }

    public boolean _check_inv_54() {
        return new BBoolean((!x.less(y).booleanValue() || new BSet<BInteger>(x, y).min().unequal(y).booleanValue()) && (!new BSet<BInteger>(x, y).min().unequal(y).booleanValue() || x.less(y).booleanValue())).booleanValue();
    }

    public boolean _check_inv_55() {
        return new BBoolean(!new BBoolean(x.greaterEqual(new BInteger(0)).booleanValue() && y.greater(new BInteger(0)).booleanValue()).booleanValue() || x.divide(y).multiply(y).equal(x.minus(x.modulo(y))).booleanValue()).booleanValue();
    }

    public boolean _check_inv_56() {
        BInteger _ic_integer_5 = new BInteger(0);
        if(new BBoolean(new BBoolean(x.unequal(y).booleanValue() && x.unequal(z).booleanValue()).booleanValue() && y.unequal(z).booleanValue()).booleanValue()) {
            for(BInteger _ic_zz_1 : new BSet<BInteger>(x, y, z)) {
                _ic_integer_5 = _ic_integer_5.plus(_ic_zz_1);

            }
        }

        return new BBoolean(!new BBoolean(new BBoolean(x.unequal(y).booleanValue() && x.unequal(z).booleanValue()).booleanValue() && y.unequal(z).booleanValue()).booleanValue() || _ic_integer_5.equal(x.plus(y).plus(z)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_57() {
        BInteger _ic_integer_6 = new BInteger(1);
        if(new BBoolean(new BBoolean(x.unequal(y).booleanValue() && x.unequal(z).booleanValue()).booleanValue() && y.unequal(z).booleanValue()).booleanValue()) {
            for(BInteger _ic_zz_1 : new BSet<BInteger>(x, y, z)) {
                _ic_integer_6 = _ic_integer_6.multiply(_ic_zz_1);

            }
        }

        return new BBoolean(!new BBoolean(new BBoolean(x.unequal(y).booleanValue() && x.unequal(z).booleanValue()).booleanValue() && y.unequal(z).booleanValue()).booleanValue() || _ic_integer_6.equal(x.multiply(y).multiply(z)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_58() {
        BInteger _ic_integer_7 = new BInteger(0);
        for(BInteger _ic_zz_1 : new BSet<BInteger>(x)) {
            _ic_integer_7 = _ic_integer_7.plus(_ic_zz_1);

        }

        return _ic_integer_7.equal(x).booleanValue();
    }

    public boolean _check_inv_59() {
        BInteger _ic_integer_8 = new BInteger(1);
        for(BInteger _ic_zz_1 : new BSet<BInteger>(x)) {
            _ic_integer_8 = _ic_integer_8.multiply(_ic_zz_1);

        }

        return _ic_integer_8.equal(x).booleanValue();
    }

    public boolean _check_inv_60() {
        return x.succ().equal(x.plus(new BInteger(1))).booleanValue();
    }

    public boolean _check_inv_61() {
        return x.pred().equal(x.minus(new BInteger(1))).booleanValue();
    }

    public boolean _check_inv_62() {
        return x.less(x.succ()).booleanValue();
    }

    public boolean _check_inv_63() {
        return x.greater(x.pred()).booleanValue();
    }

    public boolean _check_inv_64() {
        return x.succ().pred().equal(x).booleanValue();
    }

    public boolean _check_inv_65() {
        return x.plus(y.succ()).equal(x.plus(y).succ()).booleanValue();
    }

    public boolean _check_inv_66() {
        return x.multiply(y.succ()).equal(x.plus(x.multiply(y))).booleanValue();
    }

    public boolean _check_inv_67() {
        return new BBoolean(!x.greaterEqual(new BInteger(0)).booleanValue() || new BInteger(1).power(x).equal(new BInteger(1)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_68() {
        return x.power(new BInteger(1)).equal(x).booleanValue();
    }

    public boolean _check_inv_69() {
        return x.power(new BInteger(0)).equal(new BInteger(1)).booleanValue();
    }

    public boolean _check_inv_70() {
        return new BBoolean(!x.greater(new BInteger(0)).booleanValue() || new BInteger(0).power(x).equal(new BInteger(0)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_71() {
        return new BBoolean(!z.greaterEqual(new BInteger(0)).booleanValue() || x.multiply(y).power(z).equal(x.power(z).multiply(y.power(z))).booleanValue()).booleanValue();
    }

    public boolean _check_inv_72() {
        return new BBoolean(!new BBoolean(y.greaterEqual(new BInteger(0)).booleanValue() && z.greaterEqual(new BInteger(0)).booleanValue()).booleanValue() || x.power(y.plus(z)).equal(x.power(y).multiply(x.power(z))).booleanValue()).booleanValue();
    }

    public boolean _check_inv_73() {
        return new BBoolean(!new BBoolean(y.greaterEqual(new BInteger(0)).booleanValue() && z.greaterEqual(new BInteger(0)).booleanValue()).booleanValue() || x.power(y.multiply(z)).equal(x.power(y).power(z)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_74() {
        return new BSet<BInteger>(x).min().equal(x).booleanValue();
    }

    public boolean _check_inv_75() {
        return new BBoolean(!x.lessEqual(y).booleanValue() || new BSet<BInteger>(x, y).min().equal(x).booleanValue()).booleanValue();
    }

    public boolean _check_inv_76() {
        return new BBoolean(!y.lessEqual(x).booleanValue() || new BSet<BInteger>(x, y).min().equal(y).booleanValue()).booleanValue();
    }

    public boolean _check_inv_77() {
        return new BSet<BInteger>(x).union(new BSet<BInteger>(y, z)).min().equal(new BSet<BInteger>(new BSet<BInteger>(x).min(), new BSet<BInteger>(y, z).min()).min()).booleanValue();
    }

    public boolean _check_inv_78() {
        return new BSet<BInteger>(y, z).union(new BSet<BInteger>(x)).min().equal(new BSet<BInteger>(new BSet<BInteger>(y, z).min(), x).min()).booleanValue();
    }

    public boolean _check_inv_79() {
        return new BSet<BInteger>(x).max().equal(x).booleanValue();
    }

    public boolean _check_inv_80() {
        return new BBoolean(!y.lessEqual(x).booleanValue() || new BSet<BInteger>(x, y).max().equal(x).booleanValue()).booleanValue();
    }

    public boolean _check_inv_81() {
        return new BBoolean(!x.lessEqual(y).booleanValue() || new BSet<BInteger>(x, y).max().equal(y).booleanValue()).booleanValue();
    }

    public boolean _check_inv_82() {
        return new BSet<BInteger>(x).union(new BSet<BInteger>(y, z)).max().equal(new BSet<BInteger>(new BSet<BInteger>(x).max(), new BSet<BInteger>(y, z).max()).max()).booleanValue();
    }

    public boolean _check_inv_83() {
        return new BSet<BInteger>(y, z).union(new BSet<BInteger>(x)).max().equal(new BSet<BInteger>(new BSet<BInteger>(y, z).max(), x).max()).booleanValue();
    }

    public ArithmeticLaws _copy() {
        return new ArithmeticLaws(x, y, z);
    }

    @Override
    public boolean equals(Object o) {
        ArithmeticLaws o1 = this;
        ArithmeticLaws o2 = (ArithmeticLaws) o;
        return o1._get_x().equals(o2._get_x()) && o1._get_y().equals(o2._get_y()) && o1._get_z().equals(o2._get_z());
    }



    @Override
    public int hashCode() {
        return this._hashCode_1();
    }

    public int _hashCode_1() {
        int result = 1;
        result = (1543 * result) ^ ((this._get_x()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_y()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_z()).hashCode() << 1);
        return result;
    }

    public int _hashCode_2() {
        int result = 1;
        result = (6151 * result) ^ ((this._get_x()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_y()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_z()).hashCode() << 1);
        return result;
    }

    @Override
    public String toString() {
        return String.join("\n", "_get_x: " + (this._get_x()).toString(), "_get_y: " + (this._get_y()).toString(), "_get_z: " + (this._get_z()).toString());
    }

    @SuppressWarnings("unchecked")
    private static Set<ArithmeticLaws> generateNextStates(Object guardLock, ArithmeticLaws state, boolean isCaching, Map<String, Set<String>> invariantDependency, Map<ArithmeticLaws, Set<String>> dependentInvariant, Map<String, Set<String>> guardDependency, Map<ArithmeticLaws, Set<String>> dependentGuard, Map<ArithmeticLaws, PersistentHashMap> guardCache, Map<ArithmeticLaws, ArithmeticLaws> parents, Map<ArithmeticLaws, String> stateAccessedVia, AtomicInteger transitions) {
        Set<ArithmeticLaws> result = new HashSet<>();
        if(isCaching) {
            PersistentHashMap parentsGuard = guardCache.get(parents.get(state));
            PersistentHashMap newCache = parentsGuard == null ? PersistentHashMap.EMPTY : parentsGuard;
            Set<String> dependentGuardsOfState = dependentGuard.get(state);
            Object cachedValue = null;
            boolean dependentGuardsBoolean = true;
            boolean _trid_1;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_IncX");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_IncX");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_1 = state._tr_IncX();
            } else {
                _trid_1 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_IncX", _trid_1);
            if(_trid_1) {
                ArithmeticLaws copiedState = state._copy();
                copiedState.IncX();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("IncX"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("IncX"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "IncX");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_2;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_IncY");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_IncY");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_2 = state._tr_IncY();
            } else {
                _trid_2 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_IncY", _trid_2);
            if(_trid_2) {
                ArithmeticLaws copiedState = state._copy();
                copiedState.IncY();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("IncY"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("IncY"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "IncY");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_3;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_IncZ");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_IncZ");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_3 = state._tr_IncZ();
            } else {
                _trid_3 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_IncZ", _trid_3);
            if(_trid_3) {
                ArithmeticLaws copiedState = state._copy();
                copiedState.IncZ();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("IncZ"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("IncZ"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "IncZ");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_4;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_Reset");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_Reset");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_4 = state._tr_Reset();
            } else {
                _trid_4 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_Reset", _trid_4);
            if(_trid_4) {
                ArithmeticLaws copiedState = state._copy();
                copiedState.Reset();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("Reset"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("Reset"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "Reset");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }

            synchronized(guardLock) {
                guardCache.put(state, newCache);
            }
        } else {
            if(state._tr_IncX()) {
                ArithmeticLaws copiedState = state._copy();
                copiedState.IncX();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "IncX");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_IncY()) {
                ArithmeticLaws copiedState = state._copy();
                copiedState.IncY();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "IncY");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_IncZ()) {
                ArithmeticLaws copiedState = state._copy();
                copiedState.IncZ();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "IncZ");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_Reset()) {
                ArithmeticLaws copiedState = state._copy();
                copiedState.Reset();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "Reset");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }

        }
        return result;
    }


    public static boolean checkInvariants(Object guardLock, ArithmeticLaws state, boolean isCaching, Map<ArithmeticLaws, Set<String>> dependentInvariant) {
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
            if(dependentInvariantsOfState.contains("_check_inv_26")) {
                if(!state._check_inv_26()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_27")) {
                if(!state._check_inv_27()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_28")) {
                if(!state._check_inv_28()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_29")) {
                if(!state._check_inv_29()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_30")) {
                if(!state._check_inv_30()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_31")) {
                if(!state._check_inv_31()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_32")) {
                if(!state._check_inv_32()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_33")) {
                if(!state._check_inv_33()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_34")) {
                if(!state._check_inv_34()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_35")) {
                if(!state._check_inv_35()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_36")) {
                if(!state._check_inv_36()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_37")) {
                if(!state._check_inv_37()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_38")) {
                if(!state._check_inv_38()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_39")) {
                if(!state._check_inv_39()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_40")) {
                if(!state._check_inv_40()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_41")) {
                if(!state._check_inv_41()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_42")) {
                if(!state._check_inv_42()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_43")) {
                if(!state._check_inv_43()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_44")) {
                if(!state._check_inv_44()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_45")) {
                if(!state._check_inv_45()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_46")) {
                if(!state._check_inv_46()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_47")) {
                if(!state._check_inv_47()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_48")) {
                if(!state._check_inv_48()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_49")) {
                if(!state._check_inv_49()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_50")) {
                if(!state._check_inv_50()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_51")) {
                if(!state._check_inv_51()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_52")) {
                if(!state._check_inv_52()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_53")) {
                if(!state._check_inv_53()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_54")) {
                if(!state._check_inv_54()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_55")) {
                if(!state._check_inv_55()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_56")) {
                if(!state._check_inv_56()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_57")) {
                if(!state._check_inv_57()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_58")) {
                if(!state._check_inv_58()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_59")) {
                if(!state._check_inv_59()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_60")) {
                if(!state._check_inv_60()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_61")) {
                if(!state._check_inv_61()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_62")) {
                if(!state._check_inv_62()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_63")) {
                if(!state._check_inv_63()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_64")) {
                if(!state._check_inv_64()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_65")) {
                if(!state._check_inv_65()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_66")) {
                if(!state._check_inv_66()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_67")) {
                if(!state._check_inv_67()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_68")) {
                if(!state._check_inv_68()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_69")) {
                if(!state._check_inv_69()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_70")) {
                if(!state._check_inv_70()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_71")) {
                if(!state._check_inv_71()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_72")) {
                if(!state._check_inv_72()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_73")) {
                if(!state._check_inv_73()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_74")) {
                if(!state._check_inv_74()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_75")) {
                if(!state._check_inv_75()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_76")) {
                if(!state._check_inv_76()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_77")) {
                if(!state._check_inv_77()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_78")) {
                if(!state._check_inv_78()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_79")) {
                if(!state._check_inv_79()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_80")) {
                if(!state._check_inv_80()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_81")) {
                if(!state._check_inv_81()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_82")) {
                if(!state._check_inv_82()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_83")) {
                if(!state._check_inv_83()) {
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6() || !state._check_inv_7() || !state._check_inv_8() || !state._check_inv_9() || !state._check_inv_10() || !state._check_inv_11() || !state._check_inv_12() || !state._check_inv_13() || !state._check_inv_14() || !state._check_inv_15() || !state._check_inv_16() || !state._check_inv_17() || !state._check_inv_18() || !state._check_inv_19() || !state._check_inv_20() || !state._check_inv_21() || !state._check_inv_22() || !state._check_inv_23() || !state._check_inv_24() || !state._check_inv_25() || !state._check_inv_26() || !state._check_inv_27() || !state._check_inv_28() || !state._check_inv_29() || !state._check_inv_30() || !state._check_inv_31() || !state._check_inv_32() || !state._check_inv_33() || !state._check_inv_34() || !state._check_inv_35() || !state._check_inv_36() || !state._check_inv_37() || !state._check_inv_38() || !state._check_inv_39() || !state._check_inv_40() || !state._check_inv_41() || !state._check_inv_42() || !state._check_inv_43() || !state._check_inv_44() || !state._check_inv_45() || !state._check_inv_46() || !state._check_inv_47() || !state._check_inv_48() || !state._check_inv_49() || !state._check_inv_50() || !state._check_inv_51() || !state._check_inv_52() || !state._check_inv_53() || !state._check_inv_54() || !state._check_inv_55() || !state._check_inv_56() || !state._check_inv_57() || !state._check_inv_58() || !state._check_inv_59() || !state._check_inv_60() || !state._check_inv_61() || !state._check_inv_62() || !state._check_inv_63() || !state._check_inv_64() || !state._check_inv_65() || !state._check_inv_66() || !state._check_inv_67() || !state._check_inv_68() || !state._check_inv_69() || !state._check_inv_70() || !state._check_inv_71() || !state._check_inv_72() || !state._check_inv_73() || !state._check_inv_74() || !state._check_inv_75() || !state._check_inv_76() || !state._check_inv_77() || !state._check_inv_78() || !state._check_inv_79() || !state._check_inv_80() || !state._check_inv_81() || !state._check_inv_82() || !state._check_inv_83());
    }

    private static void printResult(int states, int transitions, boolean deadlockDetected, boolean invariantViolated, List<ArithmeticLaws> counterExampleState, Map<ArithmeticLaws, ArithmeticLaws> parents, Map<ArithmeticLaws, String> stateAccessedVia) {

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
                ArithmeticLaws currentState = counterExampleState.get(0);
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

    private static ArithmeticLaws next(LinkedList<ArithmeticLaws> collection, Object lock, Type type) {
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

        ArithmeticLaws machine = new ArithmeticLaws();


        AtomicBoolean invariantViolated = new AtomicBoolean(false);
        AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        AtomicBoolean stopThreads = new AtomicBoolean(false);

        Set<ArithmeticLaws> states = new HashSet<>();
        states.add(machine);
        AtomicInteger numberStates = new AtomicInteger(1);

        LinkedList<ArithmeticLaws> collection = new LinkedList<>();
        collection.add(machine);

        Map<String, Set<String>> invariantDependency = new HashMap<>();
        Map<String, Set<String>> guardDependency = new HashMap<>();
        Map<ArithmeticLaws, Set<String>> dependentInvariant = new HashMap<>();
        Map<ArithmeticLaws, Set<String>> dependentGuard = new HashMap<>();
        Map<ArithmeticLaws, PersistentHashMap> guardCache = new HashMap<>();
        Map<ArithmeticLaws, ArithmeticLaws> parents = new HashMap<>();
        Map<ArithmeticLaws, String> stateAccessedVia = new HashMap<>();
        if(isCaching) {
            invariantDependency.put("IncX", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_17", "_check_inv_16", "_check_inv_15", "_check_inv_59", "_check_inv_19", "_check_inv_10", "_check_inv_54", "_check_inv_53", "_check_inv_52", "_check_inv_51", "_check_inv_14", "_check_inv_58", "_check_inv_13", "_check_inv_57", "_check_inv_12", "_check_inv_56", "_check_inv_11", "_check_inv_55", "_check_inv_61", "_check_inv_60", "_check_inv_49", "_check_inv_48", "_check_inv_6", "_check_inv_43", "_check_inv_7", "_check_inv_42", "_check_inv_4", "_check_inv_41", "_check_inv_5", "_check_inv_40", "_check_inv_47", "_check_inv_46", "_check_inv_8", "_check_inv_45", "_check_inv_9", "_check_inv_44", "_check_inv_50", "_check_inv_1", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_76", "_check_inv_31", "_check_inv_75", "_check_inv_30", "_check_inv_74", "_check_inv_73", "_check_inv_36", "_check_inv_35", "_check_inv_79", "_check_inv_34", "_check_inv_78", "_check_inv_33", "_check_inv_77", "_check_inv_83", "_check_inv_82", "_check_inv_81", "_check_inv_80", "_check_inv_29", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_65", "_check_inv_20", "_check_inv_64", "_check_inv_63", "_check_inv_62", "_check_inv_25", "_check_inv_69", "_check_inv_24", "_check_inv_68", "_check_inv_23", "_check_inv_67", "_check_inv_22", "_check_inv_66", "_check_inv_72", "_check_inv_71", "_check_inv_70")));
            invariantDependency.put("IncY", new HashSet<>(Arrays.asList("_check_inv_19", "_check_inv_54", "_check_inv_53", "_check_inv_52", "_check_inv_51", "_check_inv_57", "_check_inv_12", "_check_inv_56", "_check_inv_11", "_check_inv_55", "_check_inv_6", "_check_inv_43", "_check_inv_42", "_check_inv_4", "_check_inv_41", "_check_inv_5", "_check_inv_40", "_check_inv_47", "_check_inv_46", "_check_inv_45", "_check_inv_44", "_check_inv_2", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_76", "_check_inv_31", "_check_inv_75", "_check_inv_30", "_check_inv_73", "_check_inv_36", "_check_inv_35", "_check_inv_34", "_check_inv_78", "_check_inv_33", "_check_inv_77", "_check_inv_83", "_check_inv_82", "_check_inv_81", "_check_inv_80", "_check_inv_29", "_check_inv_28", "_check_inv_27", "_check_inv_21", "_check_inv_65", "_check_inv_20", "_check_inv_25", "_check_inv_24", "_check_inv_23", "_check_inv_22", "_check_inv_66", "_check_inv_72", "_check_inv_71")));
            invariantDependency.put("Reset", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_17", "_check_inv_16", "_check_inv_15", "_check_inv_59", "_check_inv_19", "_check_inv_10", "_check_inv_54", "_check_inv_53", "_check_inv_52", "_check_inv_51", "_check_inv_14", "_check_inv_58", "_check_inv_13", "_check_inv_57", "_check_inv_12", "_check_inv_56", "_check_inv_11", "_check_inv_55", "_check_inv_61", "_check_inv_60", "_check_inv_49", "_check_inv_48", "_check_inv_6", "_check_inv_43", "_check_inv_7", "_check_inv_42", "_check_inv_4", "_check_inv_41", "_check_inv_5", "_check_inv_40", "_check_inv_47", "_check_inv_46", "_check_inv_8", "_check_inv_45", "_check_inv_9", "_check_inv_44", "_check_inv_2", "_check_inv_50", "_check_inv_3", "_check_inv_1", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_76", "_check_inv_31", "_check_inv_75", "_check_inv_30", "_check_inv_74", "_check_inv_73", "_check_inv_36", "_check_inv_35", "_check_inv_79", "_check_inv_34", "_check_inv_78", "_check_inv_33", "_check_inv_77", "_check_inv_83", "_check_inv_82", "_check_inv_81", "_check_inv_80", "_check_inv_29", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_65", "_check_inv_20", "_check_inv_64", "_check_inv_63", "_check_inv_62", "_check_inv_25", "_check_inv_69", "_check_inv_24", "_check_inv_68", "_check_inv_23", "_check_inv_67", "_check_inv_22", "_check_inv_66", "_check_inv_72", "_check_inv_71", "_check_inv_70")));
            invariantDependency.put("IncZ", new HashSet<>(Arrays.asList("_check_inv_32", "_check_inv_31", "_check_inv_5", "_check_inv_73", "_check_inv_57", "_check_inv_46", "_check_inv_12", "_check_inv_56", "_check_inv_45", "_check_inv_34", "_check_inv_78", "_check_inv_11", "_check_inv_44", "_check_inv_33", "_check_inv_77", "_check_inv_83", "_check_inv_72", "_check_inv_3", "_check_inv_82", "_check_inv_71")));
            guardDependency.put("IncX", new HashSet<>(Arrays.asList("_tr_IncX")));
            guardDependency.put("IncY", new HashSet<>(Arrays.asList("_tr_IncY")));
            guardDependency.put("Reset", new HashSet<>(Arrays.asList("_tr_IncX", "_tr_IncY", "_tr_IncZ")));
            guardDependency.put("IncZ", new HashSet<>(Arrays.asList("_tr_IncZ")));
            dependentInvariant.put(machine, new HashSet<>());
        }
        List<ArithmeticLaws> counterExampleState = new ArrayList<>();
        parents.put(machine, null);

        AtomicInteger transitions = new AtomicInteger(0);

        while(!collection.isEmpty() && !stopThreads.get()) {
            ArithmeticLaws state = next(collection, lock, type);

            Set<ArithmeticLaws> nextStates = generateNextStates(guardLock, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, stateAccessedVia, transitions);

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

        ArithmeticLaws machine = new ArithmeticLaws();


        AtomicBoolean invariantViolated = new AtomicBoolean(false);
        AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        AtomicBoolean stopThreads = new AtomicBoolean(false);
        AtomicInteger possibleQueueChanges = new AtomicInteger(0);

        Set<ArithmeticLaws> states = new HashSet<>();
        states.add(machine);
        AtomicInteger numberStates = new AtomicInteger(1);

        LinkedList<ArithmeticLaws> collection = new LinkedList<>();
        collection.add(machine);

        Map<String, Set<String>> invariantDependency = new HashMap<>();
        Map<String, Set<String>> guardDependency = new HashMap<>();
        Map<ArithmeticLaws, Set<String>> dependentInvariant = new HashMap<>();
        Map<ArithmeticLaws, Set<String>> dependentGuard = new HashMap<>();
        Map<ArithmeticLaws, PersistentHashMap> guardCache = new HashMap<>();
        Map<ArithmeticLaws, ArithmeticLaws> parents = new HashMap<>();
        Map<ArithmeticLaws, String> stateAccessedVia = new HashMap<>();
        if(isCaching) {
            invariantDependency.put("IncX", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_17", "_check_inv_16", "_check_inv_15", "_check_inv_59", "_check_inv_19", "_check_inv_10", "_check_inv_54", "_check_inv_53", "_check_inv_52", "_check_inv_51", "_check_inv_14", "_check_inv_58", "_check_inv_13", "_check_inv_57", "_check_inv_12", "_check_inv_56", "_check_inv_11", "_check_inv_55", "_check_inv_61", "_check_inv_60", "_check_inv_49", "_check_inv_48", "_check_inv_6", "_check_inv_43", "_check_inv_7", "_check_inv_42", "_check_inv_4", "_check_inv_41", "_check_inv_5", "_check_inv_40", "_check_inv_47", "_check_inv_46", "_check_inv_8", "_check_inv_45", "_check_inv_9", "_check_inv_44", "_check_inv_50", "_check_inv_1", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_76", "_check_inv_31", "_check_inv_75", "_check_inv_30", "_check_inv_74", "_check_inv_73", "_check_inv_36", "_check_inv_35", "_check_inv_79", "_check_inv_34", "_check_inv_78", "_check_inv_33", "_check_inv_77", "_check_inv_83", "_check_inv_82", "_check_inv_81", "_check_inv_80", "_check_inv_29", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_65", "_check_inv_20", "_check_inv_64", "_check_inv_63", "_check_inv_62", "_check_inv_25", "_check_inv_69", "_check_inv_24", "_check_inv_68", "_check_inv_23", "_check_inv_67", "_check_inv_22", "_check_inv_66", "_check_inv_72", "_check_inv_71", "_check_inv_70")));
            invariantDependency.put("IncY", new HashSet<>(Arrays.asList("_check_inv_19", "_check_inv_54", "_check_inv_53", "_check_inv_52", "_check_inv_51", "_check_inv_57", "_check_inv_12", "_check_inv_56", "_check_inv_11", "_check_inv_55", "_check_inv_6", "_check_inv_43", "_check_inv_42", "_check_inv_4", "_check_inv_41", "_check_inv_5", "_check_inv_40", "_check_inv_47", "_check_inv_46", "_check_inv_45", "_check_inv_44", "_check_inv_2", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_76", "_check_inv_31", "_check_inv_75", "_check_inv_30", "_check_inv_73", "_check_inv_36", "_check_inv_35", "_check_inv_34", "_check_inv_78", "_check_inv_33", "_check_inv_77", "_check_inv_83", "_check_inv_82", "_check_inv_81", "_check_inv_80", "_check_inv_29", "_check_inv_28", "_check_inv_27", "_check_inv_21", "_check_inv_65", "_check_inv_20", "_check_inv_25", "_check_inv_24", "_check_inv_23", "_check_inv_22", "_check_inv_66", "_check_inv_72", "_check_inv_71")));
            invariantDependency.put("Reset", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_17", "_check_inv_16", "_check_inv_15", "_check_inv_59", "_check_inv_19", "_check_inv_10", "_check_inv_54", "_check_inv_53", "_check_inv_52", "_check_inv_51", "_check_inv_14", "_check_inv_58", "_check_inv_13", "_check_inv_57", "_check_inv_12", "_check_inv_56", "_check_inv_11", "_check_inv_55", "_check_inv_61", "_check_inv_60", "_check_inv_49", "_check_inv_48", "_check_inv_6", "_check_inv_43", "_check_inv_7", "_check_inv_42", "_check_inv_4", "_check_inv_41", "_check_inv_5", "_check_inv_40", "_check_inv_47", "_check_inv_46", "_check_inv_8", "_check_inv_45", "_check_inv_9", "_check_inv_44", "_check_inv_2", "_check_inv_50", "_check_inv_3", "_check_inv_1", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_76", "_check_inv_31", "_check_inv_75", "_check_inv_30", "_check_inv_74", "_check_inv_73", "_check_inv_36", "_check_inv_35", "_check_inv_79", "_check_inv_34", "_check_inv_78", "_check_inv_33", "_check_inv_77", "_check_inv_83", "_check_inv_82", "_check_inv_81", "_check_inv_80", "_check_inv_29", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_65", "_check_inv_20", "_check_inv_64", "_check_inv_63", "_check_inv_62", "_check_inv_25", "_check_inv_69", "_check_inv_24", "_check_inv_68", "_check_inv_23", "_check_inv_67", "_check_inv_22", "_check_inv_66", "_check_inv_72", "_check_inv_71", "_check_inv_70")));
            invariantDependency.put("IncZ", new HashSet<>(Arrays.asList("_check_inv_32", "_check_inv_31", "_check_inv_5", "_check_inv_73", "_check_inv_57", "_check_inv_46", "_check_inv_12", "_check_inv_56", "_check_inv_45", "_check_inv_34", "_check_inv_78", "_check_inv_11", "_check_inv_44", "_check_inv_33", "_check_inv_77", "_check_inv_83", "_check_inv_72", "_check_inv_3", "_check_inv_82", "_check_inv_71")));
            guardDependency.put("IncX", new HashSet<>(Arrays.asList("_tr_IncX")));
            guardDependency.put("IncY", new HashSet<>(Arrays.asList("_tr_IncY")));
            guardDependency.put("Reset", new HashSet<>(Arrays.asList("_tr_IncX", "_tr_IncY", "_tr_IncZ")));
            guardDependency.put("IncZ", new HashSet<>(Arrays.asList("_tr_IncZ")));
            dependentInvariant.put(machine, new HashSet<>());
        }
        List<ArithmeticLaws> counterExampleState = new ArrayList<>();
        parents.put(machine, null);
        stateAccessedVia.put(machine, null);

        AtomicInteger transitions = new AtomicInteger(0);

        while(!collection.isEmpty() && !stopThreads.get()) {
            possibleQueueChanges.incrementAndGet();
            ArithmeticLaws state = next(collection, lock, type);
            Runnable task = () -> {
                Set<ArithmeticLaws> nextStates = generateNextStates(guardLock, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, stateAccessedVia, transitions);

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
