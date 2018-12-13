import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class Negative {






    private BInteger counter;
    private BInteger value;

    public Negative() {
        counter = (BInteger) new BInteger(0);
        value = (BInteger) new BInteger(0);
    }

    public void simulate() {
        while((counter.less(new BInteger(5000000))).booleanValue()) {
            counter = (BInteger) counter.plus(new BInteger(1));
            value = (BInteger) value.negative();
        }
    }

    public static void main(String[] args) {
        Negative exec = new Negative();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }

}
