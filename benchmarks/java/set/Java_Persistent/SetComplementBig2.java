import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;

public class SetComplementBig2 {






    private BInteger counter;
    private BSet set1;
    private BSet set2;

    public SetComplementBig2() {
        counter = (BInteger) new BInteger(0);
        set1 = (BSet) BSet.range(new BInteger(1),new BInteger(25000)).complement(new BSet(new BInteger(24999)));
        set2 = (BSet) BSet.range(new BInteger(1),new BInteger(3000));
    }

    public void simulate() {
        while((counter.less(new BInteger(10000))).booleanValue()) {
            set1 = (BSet) set1.complement(set2);
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        SetComplementBig2 exec = new SetComplementBig2();
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
