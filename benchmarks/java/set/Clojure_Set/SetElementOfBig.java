import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;

public class SetElementOfBig {






    private BInteger counter;

    public SetElementOfBig() {
        counter = (BInteger) new BInteger(0);
    }

    public void simulate() {
        while((counter.less(new BInteger(10000)).and(BSet.range(new BInteger(1),new BInteger(25000)).complement(new BSet(new BInteger(24999))).elementOf(new BInteger(25000)))).booleanValue()) {
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        SetElementOfBig exec = new SetElementOfBig();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }

}
