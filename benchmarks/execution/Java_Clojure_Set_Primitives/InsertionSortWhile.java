import de.hhu.stups.btypes.BRelation;
import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BTuple;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import java.util.Objects;
import de.hhu.stups.btypes.BUtils;

public class InsertionSortWhile {


    private final BInteger n;




    private BRelation<BInteger, BInteger> arr;
    private BBoolean sorted;

    public InsertionSortWhile() {
        n = new BInteger(1000);
        BRelation<BInteger, BInteger> _ic_set_0 = new BRelation<BInteger, BInteger>();
        for(BInteger _ic_i : BSet.interval(new BInteger(1),n)) {
            _ic_set_0 = _ic_set_0.union(new BRelation<BInteger, BInteger>(new BTuple<>(_ic_i, n.minus(_ic_i))));

        }
        arr = _ic_set_0;
        sorted = new BBoolean(false);
    }

    public void Sort() {
        if((sorted.equal(new BBoolean(false))).booleanValue()) {
            BInteger i = null;
            i = new BInteger(2);
            while((i.lessEqual(n)).booleanValue()) {
                BInteger key = null;
                BInteger j = null;
                key = arr.functionCall(i);
                j = i.minus(new BInteger(1));
                while((new BBoolean(j.greaterEqual(new BInteger(1)).booleanValue() && arr.functionCall(j).greater(key).booleanValue())).booleanValue()) {
                    arr = arr.override(new BRelation<BInteger, BInteger>(new BTuple<>(j.plus(new BInteger(1)),arr.functionCall(j))));
                    j = j.minus(new BInteger(1));
                }
                arr = arr.override(new BRelation<BInteger, BInteger>(new BTuple<>(j.plus(new BInteger(1)),key)));
                i = i.plus(new BInteger(1));
            }
            sorted = new BBoolean(true);
        }
    }

    public static void main(String[] args) {
        InsertionSortWhile exec = new InsertionSortWhile();
        exec.Sort();
    }

}
