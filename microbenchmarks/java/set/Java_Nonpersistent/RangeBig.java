import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class RangeBig {






    private BInteger counter;
    private BSet<BInteger> set;

    public RangeBig() {
        counter = new BInteger(0);
        set = new BSet<>();
    }

    public void simulate() {
        while((counter.less(new BInteger(1000))).booleanValue()) {
            set = BSet.range(new BInteger(1),new BInteger(25000));
            counter = counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        RangeBig exec = new RangeBig();
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
