import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;

public class RangeComplementBig2 {






    private BInteger counter;
    private BSet set1;
    private BSet set2;

    public RangeComplementBig2() {
        counter = (BInteger) new BInteger(0);
        set1 = (BSet) BSet.range(new BInteger(1),new BInteger(25000));
        set2 = (BSet) BSet.range(new BInteger(1),new BInteger(3000));
    }

    public void simulate() {
        while((counter.less(new BInteger(10000))).booleanValue()) {
            set1 = (BSet) set1.complement(set2);
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        RangeComplementBig2 exec = new RangeComplementBig2();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }

}