import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;

public class SetUnionBig2 {






    private BInteger counter;
    private BSet set1;
    private BSet set2;

    public SetUnionBig2() {
        counter = (BInteger) new BInteger(0);
        set1 = (BSet) BSet.range(new BInteger(1),new BInteger(25000)).complement(new BSet(new BInteger(24999)));
        set2 = (BSet) BSet.range(new BInteger(1),new BInteger(3000));
    }

    public void simulate() {
        while((counter.less(new BInteger(10000))).booleanValue()) {
            set1 = (BSet) set1.union(set2);
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        SetUnionBig2 exec = new SetUnionBig2();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }

}