import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;

public class SetCardSmall2 {






    private BInteger counter;
    private BSet set;
    private BInteger result;

    public SetCardSmall2() {
        counter = (BInteger) new BInteger(0);
        set = (BSet) new BSet(new BInteger(1));
        result = (BInteger) new BInteger(0);
    }

    public void simulate() {
        while((counter.less(new BInteger(5000000))).booleanValue()) {
            result = (BInteger) set.card();
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        SetCardSmall2 exec = new SetCardSmall2();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }

}
