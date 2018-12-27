import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;

public class RangeCardBig {






    private BInteger counter;
    private BInteger result;

    public RangeCardBig() {
        counter = (BInteger) new BInteger(0);
        result = (BInteger) new BInteger(0);
    }

    public void simulate() {
        while((counter.less(new BInteger(10000))).booleanValue()) {
            result = (BInteger) BSet.range(new BInteger(1),new BInteger(25000)).card();
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        RangeCardBig exec = new RangeCardBig();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }

}