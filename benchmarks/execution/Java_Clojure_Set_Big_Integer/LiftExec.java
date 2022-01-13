import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class LiftExec {


    private Lift _Lift = new Lift();



    private BInteger counter;

    public LiftExec() {
        counter = new BInteger("0");
    }

    public void simulate() {
        while((counter.less(new BInteger("10000000"))).booleanValue()) {
            BInteger i = null;
            i = new BInteger("0");
            while((i.less(new BInteger("100"))).booleanValue()) {
                this._Lift.inc();
                i = i.plus(new BInteger("1"));
            }
            BInteger _i = null;
            _i = new BInteger("0");
            while((_i.less(new BInteger("100"))).booleanValue()) {
                this._Lift.dec();
                _i = _i.plus(new BInteger("1"));
            }
            counter = counter.plus(new BInteger("1"));
        }
    }

    public static void main(String[] args) {
        LiftExec exec = new LiftExec();
        exec.simulate();
    }

}
