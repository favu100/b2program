import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class And {






    private BInteger counter;

    public And() {
        counter = (BInteger) new BInteger(0);
    }

    public void simulate() {
        while((counter.less(new BInteger(5000000)).and(new BInteger(1).equal(new BInteger(1)))).booleanValue()) {
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        And exec = new And();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }


}
