import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class RangeComplementSmall {






    private BInteger counter;
    private BSet set1;
    private BSet set2;

    public RangeComplementSmall2() {
        counter = (BInteger) new BInteger(0);
        set1 = (BSet) BSet.range(new BInteger(0),new BInteger(5));
        set2 = (BSet) BSet.range(new BInteger(1),new BInteger(2));
    }

    public void simulate() {
        while((counter.less(new BInteger(5000000))).booleanValue()) {
            set1 = (BSet) set1.complement(set2);
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }



}
