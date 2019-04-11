import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class Sieve {






    private BSet<BInteger> numbers;
    private BInteger cur;
    private BInteger limit;

    public Sieve() {
        numbers = BSet.range(new BInteger(2),new BInteger(10000));
        cur = new BInteger(2);
        limit = new BInteger(10000);
    }

    public BInteger ComputeNumberOfPrimes() {
        BInteger res = null;
        while((cur.greater(new BInteger(1)).and(cur.multiply(cur).lessEqual(limit))).booleanValue()) {
            if((numbers.elementOf(cur)).booleanValue()) {
                BInteger n = null;
                BSet<BInteger> set = null;
                n = cur;
                set = new BSet<>();
                while((n.lessEqual(limit.divide(cur))).booleanValue()) {
                    set = set.union(new BSet<>(cur.multiply(n)));
                    n = n.plus(new BInteger(1));
                }
                numbers = numbers.difference(set);
            } 
            cur = cur.plus(new BInteger(1));
        }
        res = numbers.card();
        return res;
    }

    public static void main(String[] args) {
        Sieve exec = new Sieve();
        long start = System.nanoTime();
        exec.ComputeNumberOfPrimes();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));

        Runtime runtime = Runtime.getRuntime();
        long memory = runtime.totalMemory() - runtime.freeMemory();
        System.out.println("Used memory is bytes: " + memory);
        System.out.println("Used memory is megabytes: "
                + (memory / (1024L * 1024L)));
    }


}
