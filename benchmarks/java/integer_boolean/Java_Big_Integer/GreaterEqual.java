import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;

public class GreaterEqual {






    private BInteger counter;

    public GreaterEqual() {
        counter = (BInteger) new BInteger("0");
    }

    public void simulate() {
        while((counter.less(new BInteger("5000000")).and(new BInteger("2").greaterEqual(new BInteger("1")))).booleanValue()) {
            counter = (BInteger) counter.plus(new BInteger("1"));
        }
    }

    public static void main(String[] args) {
        GreaterEqual exec = new GreaterEqual();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }

}
