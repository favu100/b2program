import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class SetElementOfSmall2 {






    private BInteger counter;
    private BSet<BInteger> set;

    public SetElementOfSmall2() {
        counter = new BInteger(0);
        set = new BSet<>(new BInteger(1));
    }

    public void simulate() {
        while((counter.less(new BInteger(5000000)).and(set.elementOf(new BInteger(1)))).booleanValue()) {
            counter = counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        SetElementOfSmall2 exec = new SetElementOfSmall2();
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
