import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;

public class RangeUnionBig2 {






    private BInteger counter;
    private BSet set1;
    private BSet set2;

    public RangeUnionBig2() {
        counter = (BInteger) new BInteger(0);
        set1 = (BSet) BSet.range(new BInteger(1),new BInteger(25000));
        set2 = (BSet) BSet.range(new BInteger(1),new BInteger(3000));
    }

    public void simulate() {
        while((counter.less(new BInteger(10000))).booleanValue()) {
            set1 = (BSet) set1.union(set2);
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        RangeUnionBig2 exec = new RangeUnionBig2();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }

}