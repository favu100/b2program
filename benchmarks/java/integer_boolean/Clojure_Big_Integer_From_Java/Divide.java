import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class Divide {






    private BInteger counter;
    private BInteger value;

    public Divide() {
        counter = (BInteger) new BInteger("0");
        value = (BInteger) new BInteger("0");
    }

    public void simulate() {
        while((counter.less(new BInteger("5000000"))).booleanValue()) {
            counter = (BInteger) counter.plus(new BInteger("1"));
            value = (BInteger) value.divide(new BInteger("1"));
        }
    }

    public static void main(String[] args) {
        Divide exec = new Divide();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }

}
