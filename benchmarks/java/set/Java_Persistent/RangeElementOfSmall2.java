import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;

public class RangeElementOfSmall2 {






    private BInteger counter;
    private BSet set;

    public RangeElementOfSmall2() {
        counter = (BInteger) new BInteger(0);
        set = (BSet) BSet.range(new BInteger(0),new BInteger(5));
    }

    public void simulate() {
        while((counter.less(new BInteger(5000000)).and(set.elementOf(new BInteger(1)))).booleanValue()) {
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        RangeElementOfSmall2 exec = new RangeElementOfSmall2();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }

}
