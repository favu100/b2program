import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;

public class RangeIntersectionBig {






    private BInteger counter;
    private BSet set;

    public RangeIntersectionBig() {
        counter = (BInteger) new BInteger(0);
        set = (BSet) BSet.range(new BInteger(1),new BInteger(25000));
    }

    public void simulate() {
        while((counter.less(new BInteger(10000))).booleanValue()) {
            set = (BSet) set.intersect(BSet.range(new BInteger(1),new BInteger(3000)));
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        RangeIntersectionBig exec = new RangeIntersectionBig();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));

        Runtime runtime = Runtime.getRuntime();
        long memory = runtime.totalMemory() - runtime.freeMemory();
        System.out.println("Used memory is bytes: " + memory);
        System.out.println("Used memory is megabytes: "
                + (memory / (1024L * 1024L)));
    }

}
