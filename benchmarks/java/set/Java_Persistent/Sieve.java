import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;

public class Sieve {






    private BSet numbers;
    private BInteger cur;
    private BInteger limit;

    public Sieve() {
        numbers = (BSet) BSet.range(new BInteger(2),new BInteger(10000));
        cur = (BInteger) new BInteger(2);
        limit = (BInteger) new BInteger(10000);
    }

    public BInteger ComputeNumberOfPrimes() {
        BInteger res = null;
        while((cur.greater(new BInteger(1)).and(cur.multiply(cur).lessEqual(limit))).booleanValue()) {
            if((numbers.elementOf(cur)).booleanValue()) {
                BInteger n = null;
                BSet set = null;
                n = (BInteger) cur;
                set = (BSet) new BSet();
                while((n.lessEqual(limit.divide(cur))).booleanValue()) {
                    set = (BSet) set.union(new BSet(cur.multiply(n)));
                    n = (BInteger) n.plus(new BInteger(1));
                }
                numbers = (BSet) numbers.complement(set);
            } 
            cur = (BInteger) cur.plus(new BInteger(1));
        }
        res = (BInteger) numbers.card();
        return res;
    }

    public static void main(String[] args) {
        Sieve exec = new Sieve();
        long start = System.nanoTime();
        exec.ComputeNumberOfPrimes();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }

}
