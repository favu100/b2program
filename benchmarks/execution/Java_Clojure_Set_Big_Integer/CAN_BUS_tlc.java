import de.hhu.stups.btypes.BRelation;
import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BTuple;
import de.hhu.stups.btypes.BObject;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class CAN_BUS_tlc {

    private final BSet<BInteger> NATSET;


    public enum T1state implements BObject {
        T1_EN, 
        T1_CALC, 
        T1_SEND, 
        T1_WAIT;

        public BBoolean equal(T1state o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(T1state o) {
            return new BBoolean(this != o);
        }
    }

    public enum T2mode implements BObject {
        T2MODE_SENSE, 
        T2MODE_TRANSMIT, 
        T2MODE_RELEASE;

        public BBoolean equal(T2mode o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(T2mode o) {
            return new BBoolean(this != o);
        }
    }

    public enum T2state implements BObject {
        T2_EN, 
        T2_RCV, 
        T2_PROC, 
        T2_CALC, 
        T2_SEND, 
        T2_WAIT, 
        T2_RELEASE;

        public BBoolean equal(T2state o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(T2state o) {
            return new BBoolean(this != o);
        }
    }

    public enum T3state implements BObject {
        T3_READY, 
        T3_WRITE, 
        T3_RELEASE, 
        T3_READ, 
        T3_PROC, 
        T3_WAIT;

        public BBoolean equal(T3state o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(T3state o) {
            return new BBoolean(this != o);
        }
    }

    private BSet<T1state> _T1state = new BSet<T1state>(T1state.T1_EN, T1state.T1_CALC, T1state.T1_SEND, T1state.T1_WAIT);
    private BSet<T2mode> _T2mode = new BSet<T2mode>(T2mode.T2MODE_SENSE, T2mode.T2MODE_TRANSMIT, T2mode.T2MODE_RELEASE);
    private BSet<T2state> _T2state = new BSet<T2state>(T2state.T2_EN, T2state.T2_RCV, T2state.T2_PROC, T2state.T2_CALC, T2state.T2_SEND, T2state.T2_WAIT, T2state.T2_RELEASE);
    private BSet<T3state> _T3state = new BSet<T3state>(T3state.T3_READY, T3state.T3_WRITE, T3state.T3_RELEASE, T3state.T3_READ, T3state.T3_PROC, T3state.T3_WAIT);

    private BInteger BUSpriority;
    private BInteger BUSvalue;
    private BRelation<BInteger, BInteger> BUSwrite;
    private T1state T1_state;
    private BInteger T1_timer;
    private BInteger T1_writevalue;
    private T2mode T2_mode;
    private BInteger T2_readpriority;
    private BInteger T2_readvalue;
    private T2state T2_state;
    private BInteger T2_timer;
    private BInteger T2_writevalue;
    private BInteger T2v;
    private BBoolean T3_enabled;
    private BBoolean T3_evaluated;
    private BInteger T3_readpriority;
    private BInteger T3_readvalue;
    private T3state T3_state;

    public CAN_BUS_tlc() {
        NATSET = BSet.interval(new BInteger("0"),new BInteger("5"));
        T2v = new BInteger("0");
        T3_evaluated = new BBoolean(true);
        T3_enabled = new BBoolean(true);
        T1_state = T1state.T1_EN;
        T2_state = T2state.T2_EN;
        T3_state = T3state.T3_READY;
        T1_writevalue = new BInteger("0");
        T2_writevalue = new BInteger("0");
        T2_readvalue = new BInteger("0");
        T2_readpriority = new BInteger("0");
        T3_readvalue = new BInteger("0");
        T3_readpriority = new BInteger("0");
        T1_timer = new BInteger("2");
        T2_timer = new BInteger("3");
        BUSwrite = new BRelation<BInteger, BInteger>(new BTuple<>(new BInteger("0"), new BInteger("0")));
        BUSvalue = new BInteger("0");
        BUSpriority = new BInteger("0");
        T2_mode = T2mode.T2MODE_SENSE;
    }

    public void T1Evaluate() {
        T1_timer = new BInteger("0");
        T1_state = T1state.T1_CALC;
    }

    public void T1Calculate(BInteger p) {
        T1_writevalue = p;
        T1_state = T1state.T1_SEND;
    }

    public void T1SendResult(BInteger ppriority, BInteger pv) {
        BRelation<BInteger, BInteger> _ld_BUSwrite = BUSwrite;
        BUSwrite = _ld_BUSwrite.override(new BRelation<BInteger, BInteger>(new BTuple<>(ppriority, pv)));
        T1_state = T1state.T1_WAIT;
    }

    public void T1Wait(BInteger pt) {
        T1_timer = pt;
        T1_state = T1state.T1_EN;
    }

    public void T2Evaluate() {
        T2_timer = new BInteger("0");
        T2_state = T2state.T2_RCV;
    }

    public void T2ReadBus(BInteger ppriority, BInteger pv) {
        T2_readvalue = pv;
        T2_readpriority = ppriority;
        T2_state = T2state.T2_PROC;
    }

    public void T2Reset() {
        BInteger _ld_T2v = T2v;
        T2_writevalue = _ld_T2v;
        T2v = new BInteger("0");
        T2_state = T2state.T2_SEND;
        T2_mode = T2mode.T2MODE_TRANSMIT;
    }

    public void T2Complete() {
        T2_state = T2state.T2_RELEASE;
        T2_mode = T2mode.T2MODE_SENSE;
    }

    public void T2ReleaseBus(BInteger ppriority) {
        BRelation<BInteger, BInteger> _ld_BUSwrite = BUSwrite;
        BUSwrite = _ld_BUSwrite.domainSubstraction(new BSet<BInteger>(ppriority));
        T2_state = T2state.T2_WAIT;
    }

    public void T2Calculate() {
        T2v = T2_readvalue;
        T2_state = T2state.T2_WAIT;
    }

    public void T2WriteBus(BInteger ppriority, BInteger pv) {
        BRelation<BInteger, BInteger> _ld_BUSwrite = BUSwrite;
        BUSwrite = _ld_BUSwrite.override(new BRelation<BInteger, BInteger>(new BTuple<>(ppriority, pv)));
        T2_state = T2state.T2_WAIT;
    }

    public void T2Wait(BInteger pt) {
        T2_timer = pt;
        T2_state = T2state.T2_EN;
    }

    public void T3Initiate() {
        T3_state = T3state.T3_WRITE;
        T3_enabled = new BBoolean(false);
    }

    public void T3Evaluate() {
        T3_state = T3state.T3_READ;
    }

    public void T3writebus(BInteger ppriority, BInteger pv) {
        BRelation<BInteger, BInteger> _ld_BUSwrite = BUSwrite;
        BUSwrite = _ld_BUSwrite.override(new BRelation<BInteger, BInteger>(new BTuple<>(ppriority, pv)));
        T3_state = T3state.T3_WAIT;
    }

    public void T3Read(BInteger ppriority, BInteger pv) {
        T3_readvalue = pv;
        T3_readpriority = ppriority;
        T3_state = T3state.T3_PROC;
    }

    public void T3Poll() {
        T3_state = T3state.T3_WAIT;
    }

    public void T3ReleaseBus(BInteger ppriority) {
        BRelation<BInteger, BInteger> _ld_BUSwrite = BUSwrite;
        BUSwrite = _ld_BUSwrite.domainSubstraction(new BSet<BInteger>(ppriority));
        T3_state = T3state.T3_RELEASE;
    }

    public void T3Wait() {
        T3_state = T3state.T3_READY;
        T3_evaluated = new BBoolean(true);
    }

    public void T3ReEnableWait() {
        T3_state = T3state.T3_READY;
        T3_evaluated = new BBoolean(true);
        T3_enabled = new BBoolean(true);
    }

    public void Update(BInteger pmax) {
        BInteger _ld_T2_timer = T2_timer;
        BInteger _ld_T1_timer = T1_timer;
        BUSvalue = BUSwrite.functionCall(pmax);
        BUSpriority = pmax;
        T1_timer = _ld_T1_timer.minus(new BInteger("1"));
        T2_timer = _ld_T2_timer.minus(new BInteger("1"));
        T3_evaluated = new BBoolean(false);
    }



}
