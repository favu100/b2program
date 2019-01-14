import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;

public class RangeComplementSmall {






    private BInteger counter;
    private BSet set;

    public RangeComplementSmall() {
        counter = (BInteger) new BInteger(0);
        set = (BSet) BSet.range(new BInteger(0),new BInteger(5));
    }

    public void simulate() {
        while((counter.less(new BInteger(5000000))).booleanValue()) {
            set = (BSet) set.complement(BSet.range(new BInteger(1),new BInteger(2)));
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        RangeComplementSmall exec = new RangeComplementSmall();
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
