import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;

public class RangeBig {






    private BInteger counter;
    private BSet set;

    public RangeBig() {
        counter = (BInteger) new BInteger(0);
        set = (BSet) new BSet();
    }

    public void simulate() {
        while((counter.less(new BInteger(1000))).booleanValue()) {
            set = (BSet) BSet.range(new BInteger(1),new BInteger(25000));
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        RangeBig exec = new RangeBig();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }

}
