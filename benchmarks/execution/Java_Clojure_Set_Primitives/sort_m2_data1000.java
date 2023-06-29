import de.hhu.stups.btypes.BRelation;
import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BTuple;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import java.util.Objects;
import java.util.Arrays;
import de.hhu.stups.btypes.PreconditionOrAssertionViolation;
import de.hhu.stups.btypes.StateNotReachableError;
import de.hhu.stups.btypes.BUtils;


public class sort_m2_data1000 {



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

    public sort_m2_data1000() {
        g = f;
        k = new BInteger(1);
        l = new BInteger(1);
        j = new BInteger(1);
    }

    public void progress() {
        if((new BBoolean(k.unequal(n).booleanValue() && j.equal(n).booleanValue())).booleanValue()) {
            BRelation<BInteger, BInteger> _ld_g = g;
            BInteger _ld_k = k;
            BInteger _ld_l = l;
            g = _ld_g.override(new BRelation<BInteger, BInteger>(new BTuple<>(_ld_k, _ld_g.functionCall(_ld_l))).override(new BRelation<BInteger, BInteger>(new BTuple<>(_ld_l, _ld_g.functionCall(_ld_k)))));
            k = _ld_k.plus(new BInteger(1));
            j = _ld_k.plus(new BInteger(1));
            l = _ld_k.plus(new BInteger(1));
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void prog1() {
        if((new BBoolean(new BBoolean(k.unequal(n).booleanValue() && j.unequal(n).booleanValue()).booleanValue() && g.functionCall(l).lessEqual(g.functionCall(j.plus(new BInteger(1)))).booleanValue())).booleanValue()) {
            BInteger _ld_j = j;
            BInteger _ld_l = l;
            l = _ld_l;
            j = _ld_j.plus(new BInteger(1));
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void prog2() {
        if((new BBoolean(new BBoolean(k.unequal(n).booleanValue() && j.unequal(n).booleanValue()).booleanValue() && g.functionCall(l).greater(g.functionCall(j.plus(new BInteger(1)))).booleanValue())).booleanValue()) {
            BInteger _ld_j = j;
            j = _ld_j.plus(new BInteger(1));
            l = _ld_j.plus(new BInteger(1));
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void final_evt() {
        if((k.equal(n)).booleanValue()) {
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

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



}
