import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BObject;
import de.hhu.stups.btypes.BBoolean;
import java.util.Objects;
import java.util.Arrays;
import de.hhu.stups.btypes.PreconditionOrAssertionViolation;
import de.hhu.stups.btypes.StateNotReachableError;
import de.hhu.stups.btypes.BUtils;


public class scheduler_deterministic {





    public enum PID implements BObject {
        process1, 
        process2, 
        process3;

        public BBoolean equal(PID o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(PID o) {
            return new BBoolean(this != o);
        }
    }

    private static BSet<PID> _PID = new BSet<PID>(PID.process1, PID.process2, PID.process3);

    private BSet<PID> active;
    private BSet<PID> _ready;
    private BSet<PID> waiting;

    public scheduler_deterministic() {
        active = new BSet<PID>();
        _ready = new BSet<PID>();
        waiting = new BSet<PID>();
    }

    public void _new(PID pp) {
        if((new BBoolean(new BBoolean(_PID.elementOf(pp).booleanValue() && active.notElementOf(pp).booleanValue()).booleanValue() && _ready.union(waiting).notElementOf(pp).booleanValue())).booleanValue()) {
            waiting = waiting.union(new BSet<PID>(pp));
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void del(PID pp) {
        if((waiting.elementOf(pp)).booleanValue()) {
            waiting = waiting.difference(new BSet<PID>(pp));
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void ready(PID rr) {
        if((waiting.elementOf(rr)).booleanValue()) {
            waiting = waiting.difference(new BSet<PID>(rr));
            if((active.equal(new BSet<PID>())).booleanValue()) {
                active = new BSet<PID>(rr);
            } else {
                _ready = _ready.union(new BSet<PID>(rr));
            }

        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void swap(PID pp) {
        if((active.unequal(new BSet<PID>())).booleanValue()) {
            waiting = waiting.union(active);
            if((_ready.equal(new BSet<PID>())).booleanValue()) {
                active = new BSet<PID>();
            } else {
                active = new BSet<PID>(pp);
                _ready = _ready.difference(new BSet<PID>(pp));
            }

        } else {
            throw new StateNotReachableError("State is not reachable.");
        }


    }

    public BSet<PID> _get_active() {
        return active;
    }

    public BSet<PID> _get__ready() {
        return _ready;
    }

    public BSet<PID> _get_waiting() {
        return waiting;
    }

    public BSet<PID> _get__PID() {
        return _PID;
    }



}
