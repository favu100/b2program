import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class Not {






    private BInteger counter;

    public Not() {
        counter = (BInteger) new BInteger(0);
    }

    public void simulate() {
        while((counter.greaterEqual(new BInteger(5000000)).not()).booleanValue()) {
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        Not exec = new Not();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }

}
