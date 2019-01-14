import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;

public class SetElementOfBig2 {






    private BInteger counter;
    private BSet set;

    public SetElementOfBig2() {
        counter = (BInteger) new BInteger(0);
        set = (BSet) BSet.range(new BInteger(1),new BInteger(25000)).complement(new BSet(new BInteger(24999)));
    }

    public void simulate() {
        while((counter.less(new BInteger(10000)).and(set.elementOf(new BInteger(25000)))).booleanValue()) {
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        SetElementOfBig2 exec = new SetElementOfBig2();
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
