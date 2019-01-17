import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class RangeDifferenceBig2 {






    private BInteger counter;
    private BSet<BInteger> set1;
    private BSet<BInteger> set2;

    public RangeDifferenceBig2() {
        counter = new BInteger(0);
        set1 = BSet.range(new BInteger(1),new BInteger(25000));
        set2 = BSet.range(new BInteger(1),new BInteger(3000));
    }

    public void simulate() {
        while((counter.less(new BInteger(10000))).booleanValue()) {
            set1 = set1.difference(set2);
            counter = counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        RangeDifferenceBig2 exec = new RangeDifferenceBig2();
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
