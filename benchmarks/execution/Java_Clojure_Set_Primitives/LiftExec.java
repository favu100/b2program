import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import java.util.Objects;
import java.util.Arrays;
import de.hhu.stups.btypes.PreconditionOrAssertionViolation;
import de.hhu.stups.btypes.StateNotReachableError;
import de.hhu.stups.btypes.BUtils;


public class LiftExec {




    private Lift _Lift = new Lift();



    private BInteger counter;

    public LiftExec() {
        counter = new BInteger(0);
    }

    public void simulate() {
        while((counter.less(new BInteger(3000))).booleanValue()) {
            BInteger i = null;
            i = new BInteger(0);
            while((i.less(new BInteger(100))).booleanValue()) {
                this._Lift.inc();
                i = i.plus(new BInteger(1));
            }
            BInteger _i = null;
            _i = new BInteger(0);
            while((_i.less(new BInteger(100))).booleanValue()) {
                this._Lift.dec();
                _i = _i.plus(new BInteger(1));
            }
            counter = counter.plus(new BInteger(1));
        }
    }

    public BInteger getCounter() {
        BInteger out = null;
        out = counter;
        return out;
    }

    public BInteger _get_counter() {
        return counter;
    }


    public static void main(String[] args) {
        LiftExec lift = new LiftExec();
        lift.simulate();
        System.out.println(lift.getCounter());
    }

}
