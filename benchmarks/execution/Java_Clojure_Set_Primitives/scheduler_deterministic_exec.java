import de.hhu.stups.btypes.BObject;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import java.util.Objects;
import java.util.Arrays;
import de.hhu.stups.btypes.PreconditionOrAssertionViolation;
import de.hhu.stups.btypes.StateNotReachableError;
import de.hhu.stups.btypes.BUtils;


public class scheduler_deterministic_exec {




    private scheduler_deterministic _scheduler_deterministic = new scheduler_deterministic();



    private BInteger counter;

    public scheduler_deterministic_exec() {
        counter = new BInteger(0);
    }

    public void simulate() {
        while((counter.less(new BInteger(300000))).booleanValue()) {
            this._scheduler_deterministic._new(scheduler_deterministic.PID.process1);
            this._scheduler_deterministic._new(scheduler_deterministic.PID.process2);
            this._scheduler_deterministic._new(scheduler_deterministic.PID.process3);
            this._scheduler_deterministic.del(scheduler_deterministic.PID.process1);
            this._scheduler_deterministic._new(scheduler_deterministic.PID.process1);
            this._scheduler_deterministic.del(scheduler_deterministic.PID.process2);
            this._scheduler_deterministic.del(scheduler_deterministic.PID.process1);
            this._scheduler_deterministic.del(scheduler_deterministic.PID.process3);
            this._scheduler_deterministic._new(scheduler_deterministic.PID.process1);
            this._scheduler_deterministic._new(scheduler_deterministic.PID.process2);
            this._scheduler_deterministic.del(scheduler_deterministic.PID.process1);
            this._scheduler_deterministic.ready(scheduler_deterministic.PID.process2);
            this._scheduler_deterministic._new(scheduler_deterministic.PID.process1);
            this._scheduler_deterministic._new(scheduler_deterministic.PID.process3);
            this._scheduler_deterministic.del(scheduler_deterministic.PID.process1);
            this._scheduler_deterministic.ready(scheduler_deterministic.PID.process3);
            this._scheduler_deterministic._new(scheduler_deterministic.PID.process1);
            this._scheduler_deterministic.ready(scheduler_deterministic.PID.process1);
            this._scheduler_deterministic.swap(scheduler_deterministic.PID.process1);
            this._scheduler_deterministic.del(scheduler_deterministic.PID.process2);
            this._scheduler_deterministic.swap(scheduler_deterministic.PID.process3);
            this._scheduler_deterministic._new(scheduler_deterministic.PID.process2);
            this._scheduler_deterministic.del(scheduler_deterministic.PID.process1);
            this._scheduler_deterministic.del(scheduler_deterministic.PID.process2);
            this._scheduler_deterministic.swap(scheduler_deterministic.PID.process1);
            this._scheduler_deterministic._new(scheduler_deterministic.PID.process1);
            this._scheduler_deterministic._new(scheduler_deterministic.PID.process2);
            this._scheduler_deterministic.del(scheduler_deterministic.PID.process1);
            this._scheduler_deterministic.del(scheduler_deterministic.PID.process3);
            this._scheduler_deterministic._new(scheduler_deterministic.PID.process1);
            this._scheduler_deterministic.del(scheduler_deterministic.PID.process2);
            this._scheduler_deterministic.del(scheduler_deterministic.PID.process1);
            counter = counter.plus(new BInteger(1));
        }
    }

    public BInteger _get_counter() {
        return counter;
    }


    public static void main(String[] args) {
        scheduler_deterministic_exec exec = new scheduler_deterministic_exec();
        exec.simulate();
    }

}
