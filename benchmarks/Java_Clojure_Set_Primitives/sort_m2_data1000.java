import de.hhu.stups.btypes.BRelation;
import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BTuple;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class sort_m2_data1000 {

    private final BRelation<BInteger, BInteger> f;
    private final BInteger n;




    private BInteger j;
    private BInteger k;
    private BInteger l;
    private BRelation<BInteger, BInteger> g;

    public sort_m2_data1000() {
        BRelation<BInteger, BInteger> _ic_set_0 = new BRelation<BInteger, BInteger>();
        for(BInteger _ic_i : BSet.interval(new BInteger(1),new BInteger(1000))) {
            _ic_set_0 = _ic_set_0.union(new BRelation<BInteger, BInteger>(new BTuple<>(_ic_i, new BInteger(1500).minus(_ic_i))));

        }
        f = _ic_set_0;
        n = new BInteger(1000);
        g = f;
        k = new BInteger(1);
        l = new BInteger(1);
        j = new BInteger(1);
    }

    public void progress() {
        if((k.unequal(n).and(j.equal(n))).booleanValue()) {
            BRelation<BInteger, BInteger> _ld_g = g;
            BInteger _ld_k = k;
            BInteger _ld_l = l;
            g = _ld_g.override(new BRelation<BInteger, BInteger>(new BTuple<>(_ld_k, _ld_g.functionCall(_ld_l))).override(new BRelation<BInteger, BInteger>(new BTuple<>(_ld_l, _ld_g.functionCall(_ld_k)))));
            k = _ld_k.plus(new BInteger(1));
            j = _ld_k.plus(new BInteger(1));
            l = _ld_k.plus(new BInteger(1));
        }
    }

    public void prog1() {
        if((k.unequal(n).and(j.unequal(n)).and(g.functionCall(l).lessEqual(g.functionCall(j.plus(new BInteger(1)))))).booleanValue()) {
            BInteger _ld_j = j;
            BInteger _ld_l = l;
            l = _ld_l;
            j = _ld_j.plus(new BInteger(1));
        }
    }

    public void prog2() {
        if((k.unequal(n).and(j.unequal(n)).and(g.functionCall(l).greater(g.functionCall(j.plus(new BInteger(1)))))).booleanValue()) {
            BInteger _ld_j = j;
            j = _ld_j.plus(new BInteger(1));
            l = _ld_j.plus(new BInteger(1));
        }
    }

    public void final_evt() {
        if((k.equal(n)).booleanValue()) {
        }
    }



}
