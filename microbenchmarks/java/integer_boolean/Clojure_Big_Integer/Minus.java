import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class Minus {






    private BInteger counter;
    private BInteger value;

    public Minus() {
        counter = new BInteger("0");
        value = new BInteger("0");
    }

    public void simulate() {
        while((counter.less(new BInteger("5000000"))).booleanValue()) {
            counter = counter.plus(new BInteger("1"));
            value = value.minus(new BInteger("1"));
        }
    }

    public static void main(String[] args) {
        Minus exec = new Minus();
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
