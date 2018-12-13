import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class Implies {






    private BInteger counter;

    public Implies() {
        counter = (BInteger) new BInteger(0);
    }

    public void simulate() {
        while((new BInteger(1).equal(new BInteger(1)).implies(counter.less(new BInteger(5000000)))).booleanValue()) {
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        Implies exec = new Implies();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }

}
