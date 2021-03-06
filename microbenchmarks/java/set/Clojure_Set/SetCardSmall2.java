import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class SetCardSmall2 {






    private BInteger counter;
    private BSet<BInteger> set;
    private BInteger result;

    public SetCardSmall2() {
        counter = new BInteger(0);
        set = new BSet<>(new BInteger(1));
        result = new BInteger(0);
    }

    public void simulate() {
        while((counter.less(new BInteger(5000000))).booleanValue()) {
            result = set.card();
            counter = counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        SetCardSmall2 exec = new SetCardSmall2();
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
