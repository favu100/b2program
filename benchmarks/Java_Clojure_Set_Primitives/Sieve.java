import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import java.util.Objects;
import de.hhu.stups.btypes.BUtils;

public class Sieve {






    private BSet<BInteger> numbers;
    private BInteger cur;
    private BInteger limit;

    public Sieve() {
        numbers = BSet.interval(new BInteger(2),new BInteger(1000000));
        cur = new BInteger(2);
        limit = new BInteger(1000000);
    }

    public BInteger ComputeNumberOfPrimes() {
        BInteger res = null;
        while((new BBoolean(cur.greater(new BInteger(1)).booleanValue() && cur.multiply(cur).lessEqual(limit).booleanValue())).booleanValue()) {
            if((numbers.elementOf(cur)).booleanValue()) {
                BInteger n = null;
                BSet<BInteger> set = null;
                n = cur;
                set = new BSet<BInteger>();
                while((n.lessEqual(limit.divide(cur))).booleanValue()) {
                    set = set.union(new BSet<BInteger>(cur.multiply(n)));
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
        Sieve sieve = new Sieve();
        sieve.ComputeNumberOfPrimes();
    }


}
