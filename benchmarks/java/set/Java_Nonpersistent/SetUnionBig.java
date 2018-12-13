import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class SetUnionBig {






    private BInteger counter;
    private BSet set;

    public SetUnionBig() {
        counter = (BInteger) new BInteger(0);
        set = (BSet) BSet.range(new BInteger(1),new BInteger(25000)).complement(new BSet(new BInteger(24999)));
    }

    public void simulate() {
        while((counter.less(new BInteger(10000))).booleanValue()) {
            set = (BSet) set.union(BSet.range(new BInteger(1),new BInteger(3000)));
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        SetUnionBig exec = new SetUnionBig();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }

}
