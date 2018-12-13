import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class LessEqual {






    private BInteger counter;

    public LessEqual() {
        counter = (BInteger) new BInteger(0);
    }

    public void simulate() {
        while((counter.less(new BInteger(5000000)).and(new BInteger(1).lessEqual(new BInteger(2)))).booleanValue()) {
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        LessEqual exec = new LessEqual();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }

}
