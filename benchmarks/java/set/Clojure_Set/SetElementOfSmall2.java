import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;

public class SetElementOfSmall2 {






    private BInteger counter;
    private BSet set;

    public SetElementOfSmall2() {
        counter = (BInteger) new BInteger(0);
        set = (BSet) new BSet(new BInteger(1));
    }

    public void simulate() {
        while((counter.less(new BInteger(5000000)).and(set.elementOf(new BInteger(1)))).booleanValue()) {
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        SetElementOfSmall2 exec = new SetElementOfSmall2();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }

}
