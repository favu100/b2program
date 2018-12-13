import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;

public class RangeIntersectionSmall {






    private BInteger counter;
    private BSet set;

    public RangeIntersectionSmall() {
        counter = (BInteger) new BInteger(0);
        set = (BSet) BSet.range(new BInteger(0),new BInteger(5));
    }

    public void simulate() {
        while((counter.less(new BInteger(5000000))).booleanValue()) {
            set = (BSet) set.intersect(BSet.range(new BInteger(0),new BInteger(5)));
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        RangeIntersectionSmall exec = new RangeIntersectionSmall();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }

}
