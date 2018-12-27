import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;

public class RangeCardSmall {






    private BInteger counter;
    private BInteger result;

    public RangeCardSmall() {
        counter = (BInteger) new BInteger(0);
        result = (BInteger) new BInteger(0);
    }

    public void simulate() {
        while((counter.less(new BInteger(5000000))).booleanValue()) {
            result = (BInteger) BSet.range(new BInteger(0),new BInteger(5)).card();
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        RangeCardSmall exec = new RangeCardSmall();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }

}