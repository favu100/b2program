import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class RangeIntersectionBig2 {






    private BInteger counter;
    private BSet<BInteger> set1;
    private BSet<BInteger> set2;

    public RangeIntersectionBig2() {
        counter = new BInteger(0);
        set1 = BSet.range(new BInteger(1),new BInteger(25000));
        set2 = BSet.range(new BInteger(1),new BInteger(3000));
    }

    public void simulate() {
        while((counter.less(new BInteger(10000))).booleanValue()) {
            set1 = set1.intersect(set2);
            counter = counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        RangeIntersectionBig2 exec = new RangeIntersectionBig2();
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
