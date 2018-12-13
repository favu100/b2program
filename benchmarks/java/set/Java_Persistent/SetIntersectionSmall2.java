import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;

public class SetIntersectionSmall2 {






    private BInteger counter;
    private BSet set1;
    private BSet set2;

    public SetIntersectionSmall2() {
        counter = (BInteger) new BInteger(0);
        set1 = (BSet) new BSet(new BInteger(1));
        set2 = (BSet) new BSet(new BInteger(1));
    }

    public void simulate() {
        while((counter.less(new BInteger(5000000))).booleanValue()) {
            set1 = (BSet) set1.intersect(set2);
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        SetIntersectionSmall2 exec = new SetIntersectionSmall2();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }


}
