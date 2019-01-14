import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;

public class SetUnionSmall {






    private BInteger counter;
    private BSet set;

    public SetUnionSmall() {
        counter = (BInteger) new BInteger(0);
        set = (BSet) new BSet(new BInteger(1));
    }

    public void simulate() {
        while((counter.less(new BInteger(5000000))).booleanValue()) {
            set = (BSet) set.union(new BSet(new BInteger(2)));
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        SetUnionSmall exec = new SetUnionSmall();
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
