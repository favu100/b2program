import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class RangeIntersectionSmall {






    private BInteger counter;
    private BSet<BInteger> set;

    public RangeIntersectionSmall() {
        counter = new BInteger(0);
        set = BSet.range(new BInteger(0),new BInteger(5));
    }

    public void simulate() {
        while((counter.less(new BInteger(5000000))).booleanValue()) {
            set = set.intersect(BSet.range(new BInteger(0),new BInteger(5)));
            counter = counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        RangeIntersectionSmall exec = new RangeIntersectionSmall();
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
