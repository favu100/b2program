import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BUtils;

public class Lift {





    private BInteger floor;

    public Lift() {
        floor = new BInteger(0);
    }

    public void inc() {
        floor = floor.plus(new BInteger(1));
    }

    public void dec() {
        floor = floor.minus(new BInteger(1));
    }



}
