import de.hhu.stups.btypes.BTuple;
import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BObject;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.Future;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import clojure.java.api.Clojure;
import clojure.lang.PersistentHashMap;
import clojure.lang.RT;
import clojure.lang.Var;
import java.util.Objects;
import java.util.Arrays;
import de.hhu.stups.btypes.PreconditionOrAssertionViolation;
import de.hhu.stups.btypes.StateNotReachableError;
import de.hhu.stups.btypes.BUtils;


public class Cruise_finite1_deterministic_MC {


    private static final Var ASSOC;
    private static final Var GET;

    static {
        RT.var("clojure.core", "require").invoke(Clojure.read("clojure.set"));
        ASSOC = RT.var("clojure.core", "assoc");
        GET = RT.var("clojure.core", "get");
    }

    public static enum Type {
        BFS,
        DFS,
        MIXED
    }

    public Cruise_finite1_deterministic_MC parent;
    public Set<String> dependentGuard = new HashSet<>();
    public PersistentHashMap guardCache = PersistentHashMap.EMPTY;
    public Set<String> dependentInvariant = new HashSet<>();
    public String stateAccessedVia;





    public enum RSset implements BObject {
        RSnone, 
        RSpos, 
        RSneg, 
        RSequal;

        public BBoolean equal(RSset o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(RSset o) {
            return new BBoolean(this != o);
        }
    }

    public enum ODset implements BObject {
        ODnone, 
        ODclose, 
        ODveryclose;

        public BBoolean equal(ODset o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(ODset o) {
            return new BBoolean(this != o);
        }
    }

    private static BSet<RSset> _RSset = new BSet<RSset>(RSset.RSnone, RSset.RSpos, RSset.RSneg, RSset.RSequal);
    private static BSet<ODset> _ODset = new BSet<ODset>(ODset.ODnone, ODset.ODclose, ODset.ODveryclose);

    private BBoolean CruiseAllowed;
    private BBoolean CruiseActive;
    private BBoolean VehicleAtCruiseSpeed;
    private BBoolean VehicleCanKeepSpeed;
    private BBoolean VehicleTryKeepSpeed;
    private BBoolean SpeedAboveMax;
    private BBoolean VehicleTryKeepTimeGap;
    private BBoolean CruiseSpeedAtMax;
    private BBoolean ObstaclePresent;
    private ODset ObstacleDistance;
    private RSset ObstacleRelativeSpeed;
    private BBoolean ObstacleStatusJustChanged;
    private BBoolean CCInitialisationInProgress;
    private BBoolean CruiseSpeedChangeInProgress;
    private BInteger NumberOfSetCruise;

    public Cruise_finite1_deterministic_MC() {
        CruiseAllowed = new BBoolean(true);
        CruiseActive = new BBoolean(false);
        VehicleAtCruiseSpeed = new BBoolean(false);
        VehicleCanKeepSpeed = new BBoolean(false);
        VehicleTryKeepSpeed = new BBoolean(false);
        SpeedAboveMax = new BBoolean(false);
        VehicleTryKeepTimeGap = new BBoolean(false);
        NumberOfSetCruise = new BInteger(0);
        CruiseSpeedAtMax = new BBoolean(false);
        ObstacleDistance = ODset.ODnone;
        ObstacleStatusJustChanged = new BBoolean(false);
        CCInitialisationInProgress = new BBoolean(false);
        CruiseSpeedChangeInProgress = new BBoolean(false);
        ObstaclePresent = new BBoolean(false);
        ObstacleRelativeSpeed = RSset.RSnone;
    }


    public Cruise_finite1_deterministic_MC(BBoolean CruiseAllowed, BBoolean CruiseActive, BBoolean VehicleAtCruiseSpeed, BBoolean VehicleCanKeepSpeed, BBoolean VehicleTryKeepSpeed, BBoolean SpeedAboveMax, BBoolean VehicleTryKeepTimeGap, BBoolean CruiseSpeedAtMax, BBoolean ObstaclePresent, ODset ObstacleDistance, RSset ObstacleRelativeSpeed, BBoolean ObstacleStatusJustChanged, BBoolean CCInitialisationInProgress, BBoolean CruiseSpeedChangeInProgress, BInteger NumberOfSetCruise) {
        this.CruiseAllowed = CruiseAllowed;
        this.CruiseActive = CruiseActive;
        this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
        this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
        this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
        this.SpeedAboveMax = SpeedAboveMax;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        this.CruiseSpeedAtMax = CruiseSpeedAtMax;
        this.ObstaclePresent = ObstaclePresent;
        this.ObstacleDistance = ObstacleDistance;
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        this.NumberOfSetCruise = NumberOfSetCruise;
    }


    public void CruiseBecomesNotAllowed() {
        CruiseAllowed = new BBoolean(false);
        CruiseActive = new BBoolean(false);
        VehicleCanKeepSpeed = new BBoolean(false);
        VehicleTryKeepSpeed = new BBoolean(false);
        VehicleAtCruiseSpeed = new BBoolean(false);
        VehicleTryKeepTimeGap = new BBoolean(false);
        CruiseSpeedAtMax = new BBoolean(false);
        ObstacleDistance = ODset.ODnone;
        NumberOfSetCruise = new BInteger(0);
        ObstacleStatusJustChanged = new BBoolean(false);
        CCInitialisationInProgress = new BBoolean(false);
        CruiseSpeedChangeInProgress = new BBoolean(false);

    }

    public void CruiseBecomesAllowed() {
        CruiseAllowed = new BBoolean(true);

    }

    public void SetCruiseSpeed(BBoolean vcks, BBoolean csam) {
        BInteger _ld_NumberOfSetCruise = NumberOfSetCruise;
        BBoolean _ld_CruiseActive = CruiseActive;
        CruiseActive = new BBoolean(true);
        VehicleCanKeepSpeed = vcks;
        if((SpeedAboveMax.equal(new BBoolean(false))).booleanValue()) {
            VehicleAtCruiseSpeed = new BBoolean(true);
            CruiseSpeedAtMax = csam;
        } else {
            CruiseSpeedAtMax = new BBoolean(true);
        }

        ObstacleStatusJustChanged = new BBoolean(true);
        if((_ld_CruiseActive.equal(new BBoolean(true))).booleanValue()) {
            CruiseSpeedChangeInProgress = new BBoolean(true);
        } else {
            CCInitialisationInProgress = new BBoolean(true);
        }

        if((_ld_NumberOfSetCruise.less(new BInteger(1))).booleanValue()) {
            NumberOfSetCruise = _ld_NumberOfSetCruise.plus(new BInteger(1));
        } 


    }

    public void CCInitialisationFinished(BBoolean vtks, BBoolean vtktg) {
        VehicleTryKeepTimeGap = vtktg;
        VehicleTryKeepSpeed = vtks;

    }

    public void CCInitialisationDelayFinished() {
        CCInitialisationInProgress = new BBoolean(true);

    }

    public void CruiseSpeedChangeFinished(BBoolean vtks, BBoolean vtktg) {
        VehicleTryKeepTimeGap = vtktg;
        VehicleTryKeepSpeed = vtks;

    }

    public void CruiseSpeedChangeDelayFinished() {
        CruiseSpeedChangeInProgress = new BBoolean(true);

    }

    public void CruiseOff() {
        CruiseActive = new BBoolean(false);
        VehicleCanKeepSpeed = new BBoolean(false);
        VehicleTryKeepSpeed = new BBoolean(false);
        VehicleAtCruiseSpeed = new BBoolean(false);
        VehicleTryKeepTimeGap = new BBoolean(false);
        CruiseSpeedAtMax = new BBoolean(false);
        ObstacleDistance = ODset.ODnone;
        NumberOfSetCruise = new BInteger(0);
        ObstacleStatusJustChanged = new BBoolean(false);
        CCInitialisationInProgress = new BBoolean(false);
        CruiseSpeedChangeInProgress = new BBoolean(false);

    }

    public void ExternalForcesBecomesExtreme() {
        VehicleCanKeepSpeed = new BBoolean(false);

    }

    public void ExternalForcesBecomesNormal() {
        VehicleCanKeepSpeed = new BBoolean(true);

    }

    public void VehicleLeavesCruiseSpeed() {
        VehicleAtCruiseSpeed = new BBoolean(false);

    }

    public void VehicleReachesCruiseSpeed() {
        VehicleAtCruiseSpeed = new BBoolean(true);

    }

    public void VehicleExceedsMaxCruiseSpeed() {
        SpeedAboveMax = new BBoolean(true);
        VehicleAtCruiseSpeed = new BBoolean(false);

    }

    public void VehicleFallsBelowMaxCruiseSpeed() {
        SpeedAboveMax = new BBoolean(false);
        if((new BBoolean(CruiseActive.equal(new BBoolean(true)).booleanValue() && CruiseSpeedAtMax.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            VehicleAtCruiseSpeed = new BBoolean(true);
        } 


    }

    public void ObstacleDistanceBecomesVeryClose() {
        ObstacleDistance = ODset.ODveryclose;
        ObstacleStatusJustChanged = new BBoolean(true);

    }

    public void ObstacleDistanceBecomesClose() {
        ObstacleDistance = ODset.ODclose;
        ObstacleStatusJustChanged = new BBoolean(true);
        if((ObstacleRelativeSpeed.equal(RSset.RSpos)).booleanValue()) {
            VehicleTryKeepTimeGap = new BBoolean(false);
        } 


    }

    public void ObstacleDistanceBecomesBig() {
        ObstacleStatusJustChanged = new BBoolean(true);
        ObstacleDistance = ODset.ODnone;
        VehicleTryKeepTimeGap = new BBoolean(false);

    }

    public void ObstacleStartsTravelFaster() {
        ObstacleRelativeSpeed = RSset.RSpos;
        if((CruiseActive.equal(new BBoolean(true))).booleanValue()) {
            ObstacleStatusJustChanged = new BBoolean(true);
        } 

        if((ObstacleDistance.unequal(ODset.ODveryclose)).booleanValue()) {
            VehicleTryKeepTimeGap = new BBoolean(false);
        } 


    }

    public void ObstacleStopsTravelFaster() {
        ObstacleRelativeSpeed = RSset.RSequal;
        if((CruiseActive.equal(new BBoolean(true))).booleanValue()) {
            ObstacleStatusJustChanged = new BBoolean(true);
        } 


    }

    public void ObstacleStartsTravelSlower() {
        ObstacleRelativeSpeed = RSset.RSneg;
        if((CruiseActive.equal(new BBoolean(true))).booleanValue()) {
            ObstacleStatusJustChanged = new BBoolean(true);
        } 


    }

    public void ObstacleStopsTravelSlower() {
        ObstacleRelativeSpeed = RSset.RSequal;
        if((CruiseActive.equal(new BBoolean(true))).booleanValue()) {
            ObstacleStatusJustChanged = new BBoolean(true);
        } 


    }

    public void ObstacleAppearsWhenCruiseActive(RSset ors, ODset od) {
        ObstaclePresent = new BBoolean(true);
        ObstacleStatusJustChanged = new BBoolean(true);
        ObstacleRelativeSpeed = ors;
        ObstacleDistance = od;

    }

    public void ObstacleAppearsWhenCruiseInactive(RSset ors) {
        ObstaclePresent = new BBoolean(true);
        ObstacleRelativeSpeed = ors;
        ObstacleDistance = ODset.ODnone;

    }

    public void ObstacleDisappears() {
        ObstaclePresent = new BBoolean(false);
        ObstacleRelativeSpeed = RSset.RSnone;
        if((CruiseActive.equal(new BBoolean(true))).booleanValue()) {
            ObstacleStatusJustChanged = new BBoolean(true);
        } 

        ObstacleDistance = ODset.ODnone;
        VehicleTryKeepTimeGap = new BBoolean(false);

    }

    public void VehicleManageObstacle(BBoolean vtks, BBoolean vtktg) {
        VehicleTryKeepTimeGap = vtktg;
        VehicleTryKeepSpeed = vtks;

    }

    public void ObstacleBecomesOld() {
        ObstacleStatusJustChanged = new BBoolean(false);

    }

    public BBoolean _get_CruiseAllowed() {
        return CruiseAllowed;
    }

    public BBoolean _get_CruiseActive() {
        return CruiseActive;
    }

    public BBoolean _get_VehicleAtCruiseSpeed() {
        return VehicleAtCruiseSpeed;
    }

    public BBoolean _get_VehicleCanKeepSpeed() {
        return VehicleCanKeepSpeed;
    }

    public BBoolean _get_VehicleTryKeepSpeed() {
        return VehicleTryKeepSpeed;
    }

    public BBoolean _get_SpeedAboveMax() {
        return SpeedAboveMax;
    }

    public BBoolean _get_VehicleTryKeepTimeGap() {
        return VehicleTryKeepTimeGap;
    }

    public BBoolean _get_CruiseSpeedAtMax() {
        return CruiseSpeedAtMax;
    }

    public BBoolean _get_ObstaclePresent() {
        return ObstaclePresent;
    }

    public ODset _get_ObstacleDistance() {
        return ObstacleDistance;
    }

    public RSset _get_ObstacleRelativeSpeed() {
        return ObstacleRelativeSpeed;
    }

    public BBoolean _get_ObstacleStatusJustChanged() {
        return ObstacleStatusJustChanged;
    }

    public BBoolean _get_CCInitialisationInProgress() {
        return CCInitialisationInProgress;
    }

    public BBoolean _get_CruiseSpeedChangeInProgress() {
        return CruiseSpeedChangeInProgress;
    }

    public BInteger _get_NumberOfSetCruise() {
        return NumberOfSetCruise;
    }

    public BSet<RSset> _get__RSset() {
        return _RSset;
    }

    public BSet<ODset> _get__ODset() {
        return _ODset;
    }


    public boolean _tr_CruiseBecomesNotAllowed() {
        return CruiseAllowed.equal(new BBoolean(true)).booleanValue();
    }

    public boolean _tr_CruiseBecomesAllowed() {
        return CruiseAllowed.equal(new BBoolean(false)).booleanValue();
    }

    public BSet<BTuple<BBoolean, BBoolean>> _tr_SetCruiseSpeed() {
        BSet<BTuple<BBoolean, BBoolean>> _ic_set_2 = new BSet<BTuple<BBoolean, BBoolean>>();
        for(BBoolean _ic_vcks_1 : BUtils.BOOL) {
            for(BBoolean _ic_csam_1 : BUtils.BOOL) {
                if((CruiseAllowed.equal(new BBoolean(true))).booleanValue()) {
                    _ic_set_2 = _ic_set_2.union(new BSet<BTuple<BBoolean, BBoolean>>(new BTuple<>(_ic_vcks_1, _ic_csam_1)));
                }

            }
        }
        return _ic_set_2;
    }

    public BSet<BTuple<BBoolean, BBoolean>> _tr_CCInitialisationFinished() {
        BSet<BTuple<BBoolean, BBoolean>> _ic_set_3 = new BSet<BTuple<BBoolean, BBoolean>>();
        for(BBoolean _ic_vtks_1 : BUtils.BOOL) {
            for(BBoolean _ic_vtktg_1 : BUtils.BOOL) {
                if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(_ic_vtks_1.equal(new BBoolean(true)).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue() || ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue()).booleanValue() || CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue() && new BBoolean(!ObstaclePresent.equal(new BBoolean(false)).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!ObstacleDistance.equal(ODset.ODnone).booleanValue() || _ic_vtks_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtks_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSequal).booleanValue() && ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue() && ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
                    _ic_set_3 = _ic_set_3.union(new BSet<BTuple<BBoolean, BBoolean>>(new BTuple<>(_ic_vtks_1, _ic_vtktg_1)));
                }

            }
        }
        return _ic_set_3;
    }

    public boolean _tr_CCInitialisationDelayFinished() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue() || ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue()).booleanValue() || CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!ObstacleDistance.equal(ODset.ODnone).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue();
    }

    public BSet<BTuple<BBoolean, BBoolean>> _tr_CruiseSpeedChangeFinished() {
        BSet<BTuple<BBoolean, BBoolean>> _ic_set_5 = new BSet<BTuple<BBoolean, BBoolean>>();
        for(BBoolean _ic_vtks_1 : BUtils.BOOL) {
            for(BBoolean _ic_vtktg_1 : BUtils.BOOL) {
                if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(_ic_vtks_1.equal(new BBoolean(true)).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue() || ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue()).booleanValue() || CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue() && new BBoolean(!ObstaclePresent.equal(new BBoolean(false)).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!ObstacleDistance.equal(ODset.ODnone).booleanValue() || _ic_vtks_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtks_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSequal).booleanValue() && ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue() && ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
                    _ic_set_5 = _ic_set_5.union(new BSet<BTuple<BBoolean, BBoolean>>(new BTuple<>(_ic_vtks_1, _ic_vtktg_1)));
                }

            }
        }
        return _ic_set_5;
    }

    public boolean _tr_CruiseSpeedChangeDelayFinished() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue() || ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue()).booleanValue() || CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!ObstacleDistance.equal(ODset.ODnone).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue();
    }

    public boolean _tr_CruiseOff() {
        return CruiseActive.equal(new BBoolean(true)).booleanValue();
    }

    public boolean _tr_ExternalForcesBecomesExtreme() {
        return VehicleCanKeepSpeed.equal(new BBoolean(true)).booleanValue();
    }

    public boolean _tr_ExternalForcesBecomesNormal() {
        return new BBoolean(CruiseActive.equal(new BBoolean(true)).booleanValue() && VehicleCanKeepSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _tr_VehicleLeavesCruiseSpeed() {
        return new BBoolean(new BBoolean(VehicleAtCruiseSpeed.equal(new BBoolean(true)).booleanValue() && new BBoolean(VehicleCanKeepSpeed.equal(new BBoolean(false)).booleanValue() && VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _tr_VehicleReachesCruiseSpeed() {
        return new BBoolean(new BBoolean(CruiseActive.equal(new BBoolean(true)).booleanValue() && VehicleAtCruiseSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue() && SpeedAboveMax.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _tr_VehicleExceedsMaxCruiseSpeed() {
        return new BBoolean(SpeedAboveMax.equal(new BBoolean(false)).booleanValue() && new BBoolean(new BBoolean(CruiseActive.equal(new BBoolean(false)).booleanValue() || VehicleCanKeepSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue() || new BBoolean(new BBoolean(ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue()).booleanValue();
    }

    public boolean _tr_VehicleFallsBelowMaxCruiseSpeed() {
        return SpeedAboveMax.equal(new BBoolean(true)).booleanValue();
    }

    public boolean _tr_ObstacleDistanceBecomesVeryClose() {
        return new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue()).booleanValue();
    }

    public boolean _tr_ObstacleDistanceBecomesClose() {
        return new BBoolean(new BBoolean(ObstaclePresent.equal(new BBoolean(true)).booleanValue() && CruiseActive.equal(new BBoolean(true)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue()).booleanValue() || new BBoolean(ObstacleDistance.equal(ODset.ODnone).booleanValue() && ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue()).booleanValue()).booleanValue()).booleanValue();
    }

    public boolean _tr_ObstacleDistanceBecomesBig() {
        return new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue()).booleanValue();
    }

    public boolean _tr_ObstacleStartsTravelFaster() {
        return new BBoolean(ObstaclePresent.equal(new BBoolean(true)).booleanValue() && ObstacleRelativeSpeed.equal(RSset.RSequal).booleanValue()).booleanValue();
    }

    public boolean _tr_ObstacleStopsTravelFaster() {
        return ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue();
    }

    public boolean _tr_ObstacleStartsTravelSlower() {
        return ObstacleRelativeSpeed.equal(RSset.RSequal).booleanValue();
    }

    public boolean _tr_ObstacleStopsTravelSlower() {
        return ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue();
    }

    public BSet<BTuple<RSset, ODset>> _tr_ObstacleAppearsWhenCruiseActive() {
        BSet<BTuple<RSset, ODset>> _ic_set_21 = new BSet<BTuple<RSset, ODset>>();
        for(RSset _ic_ors_1 : _RSset.difference(new BSet<RSset>(RSset.RSnone))) {
            for(ODset _ic_od_1 : _ODset.difference(new BSet<ODset>(ODset.ODnone))) {
                if((new BBoolean(ObstaclePresent.equal(new BBoolean(false)).booleanValue() && CruiseActive.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
                    _ic_set_21 = _ic_set_21.union(new BSet<BTuple<RSset, ODset>>(new BTuple<>(_ic_ors_1, _ic_od_1)));
                }

            }
        }
        return _ic_set_21;
    }

    public BSet<RSset> _tr_ObstacleAppearsWhenCruiseInactive() {
        BSet<RSset> _ic_set_22 = new BSet<RSset>();
        for(RSset _ic_ors_1 : _RSset.difference(new BSet<RSset>(RSset.RSnone))) {
            if((new BBoolean(ObstaclePresent.equal(new BBoolean(false)).booleanValue() && CruiseActive.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
                _ic_set_22 = _ic_set_22.union(new BSet<RSset>(_ic_ors_1));
            }

        }
        return _ic_set_22;
    }

    public boolean _tr_ObstacleDisappears() {
        return ObstaclePresent.equal(new BBoolean(true)).booleanValue();
    }

    public BSet<BTuple<BBoolean, BBoolean>> _tr_VehicleManageObstacle() {
        BSet<BTuple<BBoolean, BBoolean>> _ic_set_24 = new BSet<BTuple<BBoolean, BBoolean>>();
        for(BBoolean _ic_vtks_1 : BUtils.BOOL) {
            for(BBoolean _ic_vtktg_1 : BUtils.BOOL) {
                if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(_ic_vtks_1.equal(new BBoolean(true)).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue() || CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue() || CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue() && new BBoolean(!ObstaclePresent.equal(new BBoolean(false)).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!ObstacleDistance.equal(ODset.ODnone).booleanValue() || _ic_vtks_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtks_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSequal).booleanValue() && ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue() && ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
                    _ic_set_24 = _ic_set_24.union(new BSet<BTuple<BBoolean, BBoolean>>(new BTuple<>(_ic_vtks_1, _ic_vtktg_1)));
                }

            }
        }
        return _ic_set_24;
    }

    public boolean _tr_ObstacleBecomesOld() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue() || CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue() || CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!ObstacleDistance.equal(ODset.ODnone).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue();
    }

    public boolean _check_inv_1() {
        return BUtils.BOOL.elementOf(CruiseAllowed).booleanValue();
    }

    public boolean _check_inv_2() {
        return BUtils.BOOL.elementOf(CruiseActive).booleanValue();
    }

    public boolean _check_inv_3() {
        return BUtils.BOOL.elementOf(VehicleAtCruiseSpeed).booleanValue();
    }

    public boolean _check_inv_4() {
        return BUtils.BOOL.elementOf(VehicleCanKeepSpeed).booleanValue();
    }

    public boolean _check_inv_5() {
        return BUtils.BOOL.elementOf(VehicleTryKeepSpeed).booleanValue();
    }

    public boolean _check_inv_6() {
        return BUtils.BOOL.elementOf(SpeedAboveMax).booleanValue();
    }

    public boolean _check_inv_7() {
        return BUtils.BOOL.elementOf(VehicleTryKeepTimeGap).booleanValue();
    }

    public boolean _check_inv_8() {
        return BUtils.BOOL.elementOf(CruiseSpeedAtMax).booleanValue();
    }

    public boolean _check_inv_9() {
        return NumberOfSetCruise.isNatural().booleanValue();
    }

    public boolean _check_inv_10() {
        return BSet.interval(new BInteger(0), new BInteger(1)).elementOf(NumberOfSetCruise).booleanValue();
    }

    public boolean _check_inv_11() {
        return BUtils.BOOL.elementOf(ObstaclePresent).booleanValue();
    }

    public boolean _check_inv_12() {
        return _ODset.elementOf(ObstacleDistance).booleanValue();
    }

    public boolean _check_inv_13() {
        return _RSset.elementOf(ObstacleRelativeSpeed).booleanValue();
    }

    public boolean _check_inv_14() {
        return BUtils.BOOL.elementOf(ObstacleStatusJustChanged).booleanValue();
    }

    public boolean _check_inv_15() {
        return BUtils.BOOL.elementOf(CCInitialisationInProgress).booleanValue();
    }

    public boolean _check_inv_16() {
        return BUtils.BOOL.elementOf(CruiseSpeedChangeInProgress).booleanValue();
    }

    public boolean _check_inv_17() {
        return new BBoolean(!CruiseActive.equal(new BBoolean(false)).booleanValue() || VehicleAtCruiseSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_18() {
        return new BBoolean(!CruiseActive.equal(new BBoolean(false)).booleanValue() || VehicleCanKeepSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_19() {
        return new BBoolean(!CruiseActive.equal(new BBoolean(false)).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_20() {
        return new BBoolean((!NumberOfSetCruise.equal(new BInteger(0)).booleanValue() || CruiseActive.equal(new BBoolean(false)).booleanValue()) && (!CruiseActive.equal(new BBoolean(false)).booleanValue() || NumberOfSetCruise.equal(new BInteger(0)).booleanValue())).booleanValue();
    }

    public boolean _check_inv_21() {
        return new BBoolean(!CruiseActive.equal(new BBoolean(false)).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_22() {
        return new BBoolean(!CruiseActive.equal(new BBoolean(false)).booleanValue() || CruiseSpeedAtMax.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_23() {
        return new BBoolean(!CruiseActive.equal(new BBoolean(false)).booleanValue() || ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue();
    }

    public boolean _check_inv_24() {
        return new BBoolean(!CruiseActive.equal(new BBoolean(false)).booleanValue() || ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_25() {
        return new BBoolean(!CruiseActive.equal(new BBoolean(false)).booleanValue() || CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_26() {
        return new BBoolean(!CruiseActive.equal(new BBoolean(false)).booleanValue() || CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_27() {
        return new BBoolean(!ObstaclePresent.equal(new BBoolean(false)).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_28() {
        return new BBoolean(!ObstaclePresent.equal(new BBoolean(false)).booleanValue() || ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue();
    }

    public boolean _check_inv_29() {
        return new BBoolean((!ObstaclePresent.equal(new BBoolean(false)).booleanValue() || ObstacleRelativeSpeed.equal(RSset.RSnone).booleanValue()) && (!ObstacleRelativeSpeed.equal(RSset.RSnone).booleanValue() || ObstaclePresent.equal(new BBoolean(false)).booleanValue())).booleanValue();
    }

    public boolean _check_inv_30() {
        return new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSequal).booleanValue() && ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_31() {
        return new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue() && ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_32() {
        return new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_33() {
        return new BBoolean(!CruiseAllowed.equal(new BBoolean(false)).booleanValue() || CruiseActive.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_34() {
        return new BBoolean(!SpeedAboveMax.equal(new BBoolean(true)).booleanValue() || VehicleAtCruiseSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_35() {
        return new BBoolean(!CruiseActive.equal(new BBoolean(true)).booleanValue() || new BBoolean(new BBoolean(VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue() || new BBoolean(new BBoolean(ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).not().booleanValue()).booleanValue()).booleanValue();
    }

    public boolean _check_inv_36() {
        return new BBoolean(!new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODnone).booleanValue() && CruiseActive.equal(new BBoolean(true)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_37() {
        return new BBoolean(!new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() && new BBoolean(new BBoolean(ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_38() {
        return new BBoolean(!new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && new BBoolean(new BBoolean(ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_39() {
        return new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() && CruiseActive.equal(new BBoolean(true)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public Cruise_finite1_deterministic_MC _copy() {
        return new Cruise_finite1_deterministic_MC(CruiseAllowed, CruiseActive, VehicleAtCruiseSpeed, VehicleCanKeepSpeed, VehicleTryKeepSpeed, SpeedAboveMax, VehicleTryKeepTimeGap, CruiseSpeedAtMax, ObstaclePresent, ObstacleDistance, ObstacleRelativeSpeed, ObstacleStatusJustChanged, CCInitialisationInProgress, CruiseSpeedChangeInProgress, NumberOfSetCruise);
    }

    @Override
    public boolean equals(Object o) {
        Cruise_finite1_deterministic_MC o1 = this;
        Cruise_finite1_deterministic_MC o2 = (Cruise_finite1_deterministic_MC) o;
        return o1._get_CruiseAllowed().equals(o2._get_CruiseAllowed()) && o1._get_CruiseActive().equals(o2._get_CruiseActive()) && o1._get_VehicleAtCruiseSpeed().equals(o2._get_VehicleAtCruiseSpeed()) && o1._get_VehicleCanKeepSpeed().equals(o2._get_VehicleCanKeepSpeed()) && o1._get_VehicleTryKeepSpeed().equals(o2._get_VehicleTryKeepSpeed()) && o1._get_SpeedAboveMax().equals(o2._get_SpeedAboveMax()) && o1._get_VehicleTryKeepTimeGap().equals(o2._get_VehicleTryKeepTimeGap()) && o1._get_CruiseSpeedAtMax().equals(o2._get_CruiseSpeedAtMax()) && o1._get_ObstaclePresent().equals(o2._get_ObstaclePresent()) && o1._get_ObstacleDistance().equals(o2._get_ObstacleDistance()) && o1._get_ObstacleRelativeSpeed().equals(o2._get_ObstacleRelativeSpeed()) && o1._get_ObstacleStatusJustChanged().equals(o2._get_ObstacleStatusJustChanged()) && o1._get_CCInitialisationInProgress().equals(o2._get_CCInitialisationInProgress()) && o1._get_CruiseSpeedChangeInProgress().equals(o2._get_CruiseSpeedChangeInProgress()) && o1._get_NumberOfSetCruise().equals(o2._get_NumberOfSetCruise());
    }



    @Override
    public int hashCode() {
        return this._hashCode_1();
    }

    public int _hashCode_1() {
        int result = 1;
        result = (1543 * result) ^ ((this._get_CruiseAllowed()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_CruiseActive()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_VehicleAtCruiseSpeed()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_VehicleCanKeepSpeed()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_VehicleTryKeepSpeed()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_SpeedAboveMax()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_VehicleTryKeepTimeGap()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_CruiseSpeedAtMax()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_ObstaclePresent()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_ObstacleDistance()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_ObstacleRelativeSpeed()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_ObstacleStatusJustChanged()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_CCInitialisationInProgress()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_CruiseSpeedChangeInProgress()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_NumberOfSetCruise()).hashCode() << 1);
        return result;
    }

    public int _hashCode_2() {
        int result = 1;
        result = (6151 * result) ^ ((this._get_CruiseAllowed()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_CruiseActive()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_VehicleAtCruiseSpeed()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_VehicleCanKeepSpeed()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_VehicleTryKeepSpeed()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_SpeedAboveMax()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_VehicleTryKeepTimeGap()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_CruiseSpeedAtMax()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_ObstaclePresent()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_ObstacleDistance()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_ObstacleRelativeSpeed()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_ObstacleStatusJustChanged()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_CCInitialisationInProgress()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_CruiseSpeedChangeInProgress()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_NumberOfSetCruise()).hashCode() << 1);
        return result;
    }

    @Override
    public String toString() {
        return String.join("\n", "_get_CruiseAllowed: " + (this._get_CruiseAllowed()).toString(), "_get_CruiseActive: " + (this._get_CruiseActive()).toString(), "_get_VehicleAtCruiseSpeed: " + (this._get_VehicleAtCruiseSpeed()).toString(), "_get_VehicleCanKeepSpeed: " + (this._get_VehicleCanKeepSpeed()).toString(), "_get_VehicleTryKeepSpeed: " + (this._get_VehicleTryKeepSpeed()).toString(), "_get_SpeedAboveMax: " + (this._get_SpeedAboveMax()).toString(), "_get_VehicleTryKeepTimeGap: " + (this._get_VehicleTryKeepTimeGap()).toString(), "_get_CruiseSpeedAtMax: " + (this._get_CruiseSpeedAtMax()).toString(), "_get_ObstaclePresent: " + (this._get_ObstaclePresent()).toString(), "_get_ObstacleDistance: " + (this._get_ObstacleDistance()).toString(), "_get_ObstacleRelativeSpeed: " + (this._get_ObstacleRelativeSpeed()).toString(), "_get_ObstacleStatusJustChanged: " + (this._get_ObstacleStatusJustChanged()).toString(), "_get_CCInitialisationInProgress: " + (this._get_CCInitialisationInProgress()).toString(), "_get_CruiseSpeedChangeInProgress: " + (this._get_CruiseSpeedChangeInProgress()).toString(), "_get_NumberOfSetCruise: " + (this._get_NumberOfSetCruise()).toString());
    }


    private static class ModelChecker {
        private final Type type;
        private final int threads;
        private final boolean isCaching;
        private final boolean isDebug;

        private final LinkedList<Cruise_finite1_deterministic_MC> unvisitedStates = new LinkedList<>();
        private final Set<Cruise_finite1_deterministic_MC> states = new HashSet<>();
        private AtomicInteger transitions = new AtomicInteger(0);
        private ThreadPoolExecutor threadPool;
        private Object waitLock = new Object();

        private AtomicBoolean invariantViolated = new AtomicBoolean(false);
        private AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        private Cruise_finite1_deterministic_MC counterExampleState = null;

        private final Map<String, Set<String>> invariantDependency = new HashMap<>();
        private final Map<String, Set<String>> guardDependency = new HashMap<>();

        public ModelChecker(final Type type, final int threads, final boolean isCaching, final boolean isDebug) {
            this.type = type;
            this.threads = threads;
            this.isCaching = isCaching;
            this.isDebug = isDebug;
        }

        public void modelCheck() {
            if (isDebug) {
                System.out.println("Starting Modelchecking, STRATEGY=" + type + ", THREADS=" + threads + ", CACHING=" + isCaching);
            }

            if (threads <= 1) {
                modelCheckSingleThreaded();
            } else {
                this.threadPool = (ThreadPoolExecutor) Executors.newFixedThreadPool(threads-1);
                modelCheckMultiThreaded();
            }
        }

        private void modelCheckSingleThreaded() {
            Cruise_finite1_deterministic_MC machine = new Cruise_finite1_deterministic_MC();
            states.add(machine); // TODO: store hashes instead of machine?
            unvisitedStates.add(machine);

            if(isCaching) {
                initCache(machine);
            }

            while(!unvisitedStates.isEmpty()) {
                Cruise_finite1_deterministic_MC state = next();

                Set<Cruise_finite1_deterministic_MC> nextStates = generateNextStates(state);

                nextStates.forEach(nextState -> {
                    if(!states.contains(nextState)) {
                        states.add(nextState);
                        unvisitedStates.add(nextState);
                        if(states.size() % 50000 == 0 && isDebug) {
                            System.out.println("VISITED STATES: " + states.size());
                            System.out.println("EVALUATED TRANSITIONS: " + transitions.get());
                            System.out.println("-------------------");
                        }
                    }
                });

                if(invariantViolated(state)) {
                    invariantViolated.set(true);
                    counterExampleState = state;
                    break;
                }

                if(nextStates.isEmpty()) {
                    deadlockDetected.set(true);
                    counterExampleState = state;
                    break;
                }

            }
            printResult(states.size(), transitions.get());
        }

        private void modelCheckMultiThreaded() {
            Cruise_finite1_deterministic_MC machine = new Cruise_finite1_deterministic_MC();
            states.add(machine);
            unvisitedStates.add(machine);

            AtomicBoolean stopThreads = new AtomicBoolean(false);
            AtomicInteger possibleQueueChanges = new AtomicInteger(0);

            if(isCaching) {
                initCache(machine);
            }

            while(!unvisitedStates.isEmpty() && !stopThreads.get()) {
                possibleQueueChanges.incrementAndGet();
                Cruise_finite1_deterministic_MC state = next();
                Runnable task = () -> {
                    Set<Cruise_finite1_deterministic_MC> nextStates = generateNextStates(state);

                    nextStates.forEach(nextState -> {
                        synchronized (states) {
                            if(!states.contains(nextState)) {
                                states.add(nextState);
                                synchronized (unvisitedStates) {
                                    unvisitedStates.add(nextState);
                                }
                                if(states.size() % 50000 == 0 && isDebug) {
                                    System.out.println("VISITED STATES: " + states.size());
                                    System.out.println("EVALUATED TRANSITIONS: " + transitions.get());
                                    System.out.println("-------------------");
                                }
                            }
                        }
                    });

                    synchronized (unvisitedStates) {
                        int running = possibleQueueChanges.decrementAndGet();
                        if (!unvisitedStates.isEmpty() || running == 0) {
                            synchronized (waitLock) {
                                waitLock.notify();
                            }
                        }
                    }

                    if(invariantViolated(state)) {
                        invariantViolated.set(true);
                        counterExampleState = state;
                        stopThreads.set(true);
                    }

                    if(nextStates.isEmpty()) {
                        deadlockDetected.set(true);
                        counterExampleState = state;
                        stopThreads.set(true);
                    }
                };
                threadPool.submit(task);
                synchronized(waitLock) {
                    if (unvisitedStates.isEmpty() && possibleQueueChanges.get() > 0) {
                        try {
                            waitLock.wait();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                }
            }
            threadPool.shutdown();
            try {
                threadPool.awaitTermination(24, TimeUnit.HOURS);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            printResult(states.size(), transitions.get());
        }

        private void initCache(final Cruise_finite1_deterministic_MC machine) {
            invariantDependency.put("ObstacleStopsTravelSlower", new HashSet<>(Arrays.asList("_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24")));
            invariantDependency.put("SetCruiseSpeed", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_17", "_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_19", "_check_inv_10", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_34", "_check_inv_33", "_check_inv_26", "_check_inv_21", "_check_inv_20", "_check_inv_4", "_check_inv_25", "_check_inv_24", "_check_inv_8", "_check_inv_23", "_check_inv_9", "_check_inv_22", "_check_inv_2", "_check_inv_3")));
            invariantDependency.put("VehicleLeavesCruiseSpeed", new HashSet<>(Arrays.asList("_check_inv_17", "_check_inv_3", "_check_inv_34")));
            invariantDependency.put("VehicleFallsBelowMaxCruiseSpeed", new HashSet<>(Arrays.asList("_check_inv_17", "_check_inv_3", "_check_inv_6", "_check_inv_34")));
            invariantDependency.put("CCInitialisationFinished", new HashSet<>(Arrays.asList("_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_19", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_5", "_check_inv_36", "_check_inv_35")));
            invariantDependency.put("VehicleReachesCruiseSpeed", new HashSet<>(Arrays.asList("_check_inv_17", "_check_inv_3", "_check_inv_34")));
            invariantDependency.put("ObstacleAppearsWhenCruiseActive", new HashSet<>(Arrays.asList("_check_inv_29", "_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23", "_check_inv_11")));
            invariantDependency.put("ObstacleStartsTravelSlower", new HashSet<>(Arrays.asList("_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24")));
            invariantDependency.put("CruiseBecomesNotAllowed", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_17", "_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_19", "_check_inv_10", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_12", "_check_inv_34", "_check_inv_33", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_7", "_check_inv_20", "_check_inv_4", "_check_inv_5", "_check_inv_25", "_check_inv_24", "_check_inv_8", "_check_inv_23", "_check_inv_9", "_check_inv_22", "_check_inv_2", "_check_inv_3", "_check_inv_1")));
            invariantDependency.put("ObstacleAppearsWhenCruiseInactive", new HashSet<>(Arrays.asList("_check_inv_29", "_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_36", "_check_inv_13", "_check_inv_12", "_check_inv_23", "_check_inv_11")));
            invariantDependency.put("CCInitialisationDelayFinished", new HashSet<>(Arrays.asList("_check_inv_39", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_36", "_check_inv_25", "_check_inv_35")));
            invariantDependency.put("ObstacleDistanceBecomesClose", new HashSet<>(Arrays.asList("_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23")));
            invariantDependency.put("ObstacleStartsTravelFaster", new HashSet<>(Arrays.asList("_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24")));
            invariantDependency.put("ExternalForcesBecomesExtreme", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_4")));
            invariantDependency.put("CruiseOff", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_17", "_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_19", "_check_inv_10", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_12", "_check_inv_34", "_check_inv_33", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_7", "_check_inv_20", "_check_inv_4", "_check_inv_5", "_check_inv_25", "_check_inv_24", "_check_inv_8", "_check_inv_23", "_check_inv_9", "_check_inv_22", "_check_inv_2", "_check_inv_3")));
            invariantDependency.put("CruiseSpeedChangeDelayFinished", new HashSet<>(Arrays.asList("_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_37", "_check_inv_26", "_check_inv_36", "_check_inv_35")));
            invariantDependency.put("ObstacleStopsTravelFaster", new HashSet<>(Arrays.asList("_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24")));
            invariantDependency.put("ObstacleDistanceBecomesVeryClose", new HashSet<>(Arrays.asList("_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23")));
            invariantDependency.put("VehicleManageObstacle", new HashSet<>(Arrays.asList("_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_19", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_5", "_check_inv_36", "_check_inv_35")));
            invariantDependency.put("CruiseBecomesAllowed", new HashSet<>(Arrays.asList("_check_inv_1", "_check_inv_33")));
            invariantDependency.put("VehicleExceedsMaxCruiseSpeed", new HashSet<>(Arrays.asList("_check_inv_17", "_check_inv_3", "_check_inv_6", "_check_inv_34")));
            invariantDependency.put("CruiseSpeedChangeFinished", new HashSet<>(Arrays.asList("_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_19", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_5", "_check_inv_36", "_check_inv_35")));
            invariantDependency.put("ObstacleDisappears", new HashSet<>(Arrays.asList("_check_inv_29", "_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23", "_check_inv_11")));
            invariantDependency.put("ExternalForcesBecomesNormal", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_4")));
            invariantDependency.put("ObstacleBecomesOld", new HashSet<>(Arrays.asList("_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24")));
            invariantDependency.put("ObstacleDistanceBecomesBig", new HashSet<>(Arrays.asList("_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23")));
            guardDependency.put("ObstacleStopsTravelSlower", new HashSet<>(Arrays.asList("_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose")));
            guardDependency.put("SetCruiseSpeed", new HashSet<>(Arrays.asList("_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesClose", "_tr_ExternalForcesBecomesNormal", "_tr_CruiseSpeedChangeFinished", "_tr_ExternalForcesBecomesExtreme", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleReachesCruiseSpeed", "_tr_CruiseOff", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleAppearsWhenCruiseInactive")));
            guardDependency.put("VehicleLeavesCruiseSpeed", new HashSet<>(Arrays.asList("_tr_VehicleReachesCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed")));
            guardDependency.put("VehicleFallsBelowMaxCruiseSpeed", new HashSet<>(Arrays.asList("_tr_VehicleReachesCruiseSpeed", "_tr_VehicleFallsBelowMaxCruiseSpeed", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed")));
            guardDependency.put("CCInitialisationFinished", new HashSet<>(Arrays.asList("_tr_ObstacleBecomesOld", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed")));
            guardDependency.put("VehicleReachesCruiseSpeed", new HashSet<>(Arrays.asList("_tr_VehicleReachesCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed")));
            guardDependency.put("ObstacleAppearsWhenCruiseActive", new HashSet<>(Arrays.asList("_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleDisappears", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive")));
            guardDependency.put("ObstacleStartsTravelSlower", new HashSet<>(Arrays.asList("_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose")));
            guardDependency.put("CruiseBecomesNotAllowed", new HashSet<>(Arrays.asList("_tr_SetCruiseSpeed", "_tr_VehicleManageObstacle", "_tr_CruiseBecomesAllowed", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseBecomesNotAllowed", "_tr_ExternalForcesBecomesNormal", "_tr_CruiseSpeedChangeFinished", "_tr_ExternalForcesBecomesExtreme", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleReachesCruiseSpeed", "_tr_CruiseOff", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive")));
            guardDependency.put("ObstacleAppearsWhenCruiseInactive", new HashSet<>(Arrays.asList("_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleDisappears", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive")));
            guardDependency.put("CCInitialisationDelayFinished", new HashSet<>(Arrays.asList("_tr_VehicleManageObstacle", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished")));
            guardDependency.put("ObstacleDistanceBecomesClose", new HashSet<>(Arrays.asList("_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished")));
            guardDependency.put("ObstacleStartsTravelFaster", new HashSet<>(Arrays.asList("_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose")));
            guardDependency.put("ExternalForcesBecomesExtreme", new HashSet<>(Arrays.asList("_tr_ExternalForcesBecomesNormal", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ExternalForcesBecomesExtreme", "_tr_VehicleLeavesCruiseSpeed")));
            guardDependency.put("CruiseOff", new HashSet<>(Arrays.asList("_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_ExternalForcesBecomesNormal", "_tr_CruiseSpeedChangeFinished", "_tr_ExternalForcesBecomesExtreme", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleReachesCruiseSpeed", "_tr_CruiseOff", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive")));
            guardDependency.put("CruiseSpeedChangeDelayFinished", new HashSet<>(Arrays.asList("_tr_VehicleManageObstacle", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished")));
            guardDependency.put("ObstacleStopsTravelFaster", new HashSet<>(Arrays.asList("_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose")));
            guardDependency.put("ObstacleDistanceBecomesVeryClose", new HashSet<>(Arrays.asList("_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished")));
            guardDependency.put("VehicleManageObstacle", new HashSet<>(Arrays.asList("_tr_ObstacleBecomesOld", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed")));
            guardDependency.put("CruiseBecomesAllowed", new HashSet<>(Arrays.asList("_tr_SetCruiseSpeed", "_tr_CruiseBecomesAllowed", "_tr_CruiseBecomesNotAllowed")));
            guardDependency.put("VehicleExceedsMaxCruiseSpeed", new HashSet<>(Arrays.asList("_tr_VehicleReachesCruiseSpeed", "_tr_VehicleFallsBelowMaxCruiseSpeed", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed")));
            guardDependency.put("CruiseSpeedChangeFinished", new HashSet<>(Arrays.asList("_tr_ObstacleBecomesOld", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed")));
            guardDependency.put("ObstacleDisappears", new HashSet<>(Arrays.asList("_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleDisappears", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive")));
            guardDependency.put("ExternalForcesBecomesNormal", new HashSet<>(Arrays.asList("_tr_ExternalForcesBecomesNormal", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ExternalForcesBecomesExtreme", "_tr_VehicleLeavesCruiseSpeed")));
            guardDependency.put("ObstacleBecomesOld", new HashSet<>(Arrays.asList("_tr_VehicleManageObstacle", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished")));
            guardDependency.put("ObstacleDistanceBecomesBig", new HashSet<>(Arrays.asList("_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished")));
        }

        private Cruise_finite1_deterministic_MC next() {
            synchronized(this.unvisitedStates) {
                return switch(type) {
                    case BFS -> this.unvisitedStates.removeFirst();
                    case DFS -> this.unvisitedStates.removeLast();
                    case MIXED -> this.unvisitedStates.size() % 2 == 0 ? this.unvisitedStates.removeFirst() : this.unvisitedStates.removeLast();
                };
            }
        }

        @SuppressWarnings("unchecked")
        private Set<Cruise_finite1_deterministic_MC> generateNextStates(final Cruise_finite1_deterministic_MC state) {
            Set<Cruise_finite1_deterministic_MC> result = new HashSet<>();
            if(isCaching) {
                PersistentHashMap parentsGuard = state.guardCache;
                PersistentHashMap newCache = parentsGuard == null ? PersistentHashMap.EMPTY : parentsGuard;
                Object cachedValue = null;
                boolean dependentGuardsBoolean = true;
                boolean _trid_1;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_CruiseBecomesNotAllowed");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_CruiseBecomesNotAllowed");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_1 = state._tr_CruiseBecomesNotAllowed();
                } else {
                    _trid_1 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_CruiseBecomesNotAllowed", _trid_1);
                if(_trid_1) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CruiseBecomesNotAllowed();
                    copiedState.parent = state;
                    addCachedInfos("CruiseBecomesNotAllowed", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_2;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_CruiseBecomesAllowed");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_CruiseBecomesAllowed");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_2 = state._tr_CruiseBecomesAllowed();
                } else {
                    _trid_2 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_CruiseBecomesAllowed", _trid_2);
                if(_trid_2) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CruiseBecomesAllowed();
                    copiedState.parent = state;
                    addCachedInfos("CruiseBecomesAllowed", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BBoolean, BBoolean>> _trid_3;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_SetCruiseSpeed");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_SetCruiseSpeed");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_3 = state._tr_SetCruiseSpeed();
                } else {
                    _trid_3 = (BSet<BTuple<BBoolean, BBoolean>>) cachedValue;
                }
                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_SetCruiseSpeed", _trid_3);
                for(BTuple<BBoolean, BBoolean> param : _trid_3) {
                    BBoolean _tmp_1 = param.projection2();
                    BBoolean _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.SetCruiseSpeed(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("SetCruiseSpeed", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BBoolean, BBoolean>> _trid_4;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_CCInitialisationFinished");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_CCInitialisationFinished");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_4 = state._tr_CCInitialisationFinished();
                } else {
                    _trid_4 = (BSet<BTuple<BBoolean, BBoolean>>) cachedValue;
                }
                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_CCInitialisationFinished", _trid_4);
                for(BTuple<BBoolean, BBoolean> param : _trid_4) {
                    BBoolean _tmp_1 = param.projection2();
                    BBoolean _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CCInitialisationFinished(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("CCInitialisationFinished", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_5;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_CCInitialisationDelayFinished");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_CCInitialisationDelayFinished");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_5 = state._tr_CCInitialisationDelayFinished();
                } else {
                    _trid_5 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_CCInitialisationDelayFinished", _trid_5);
                if(_trid_5) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CCInitialisationDelayFinished();
                    copiedState.parent = state;
                    addCachedInfos("CCInitialisationDelayFinished", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BBoolean, BBoolean>> _trid_6;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_CruiseSpeedChangeFinished");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_CruiseSpeedChangeFinished");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_6 = state._tr_CruiseSpeedChangeFinished();
                } else {
                    _trid_6 = (BSet<BTuple<BBoolean, BBoolean>>) cachedValue;
                }
                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_CruiseSpeedChangeFinished", _trid_6);
                for(BTuple<BBoolean, BBoolean> param : _trid_6) {
                    BBoolean _tmp_1 = param.projection2();
                    BBoolean _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CruiseSpeedChangeFinished(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("CruiseSpeedChangeFinished", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_7;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_CruiseSpeedChangeDelayFinished");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_CruiseSpeedChangeDelayFinished");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_7 = state._tr_CruiseSpeedChangeDelayFinished();
                } else {
                    _trid_7 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_CruiseSpeedChangeDelayFinished", _trid_7);
                if(_trid_7) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CruiseSpeedChangeDelayFinished();
                    copiedState.parent = state;
                    addCachedInfos("CruiseSpeedChangeDelayFinished", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_8;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_CruiseOff");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_CruiseOff");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_8 = state._tr_CruiseOff();
                } else {
                    _trid_8 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_CruiseOff", _trid_8);
                if(_trid_8) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CruiseOff();
                    copiedState.parent = state;
                    addCachedInfos("CruiseOff", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_9;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_ExternalForcesBecomesExtreme");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_ExternalForcesBecomesExtreme");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_9 = state._tr_ExternalForcesBecomesExtreme();
                } else {
                    _trid_9 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_ExternalForcesBecomesExtreme", _trid_9);
                if(_trid_9) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ExternalForcesBecomesExtreme();
                    copiedState.parent = state;
                    addCachedInfos("ExternalForcesBecomesExtreme", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_10;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_ExternalForcesBecomesNormal");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_ExternalForcesBecomesNormal");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_10 = state._tr_ExternalForcesBecomesNormal();
                } else {
                    _trid_10 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_ExternalForcesBecomesNormal", _trid_10);
                if(_trid_10) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ExternalForcesBecomesNormal();
                    copiedState.parent = state;
                    addCachedInfos("ExternalForcesBecomesNormal", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_11;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_VehicleLeavesCruiseSpeed");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_VehicleLeavesCruiseSpeed");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_11 = state._tr_VehicleLeavesCruiseSpeed();
                } else {
                    _trid_11 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_VehicleLeavesCruiseSpeed", _trid_11);
                if(_trid_11) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.VehicleLeavesCruiseSpeed();
                    copiedState.parent = state;
                    addCachedInfos("VehicleLeavesCruiseSpeed", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_12;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_VehicleReachesCruiseSpeed");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_VehicleReachesCruiseSpeed");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_12 = state._tr_VehicleReachesCruiseSpeed();
                } else {
                    _trid_12 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_VehicleReachesCruiseSpeed", _trid_12);
                if(_trid_12) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.VehicleReachesCruiseSpeed();
                    copiedState.parent = state;
                    addCachedInfos("VehicleReachesCruiseSpeed", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_13;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_VehicleExceedsMaxCruiseSpeed");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_VehicleExceedsMaxCruiseSpeed");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_13 = state._tr_VehicleExceedsMaxCruiseSpeed();
                } else {
                    _trid_13 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_VehicleExceedsMaxCruiseSpeed", _trid_13);
                if(_trid_13) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.VehicleExceedsMaxCruiseSpeed();
                    copiedState.parent = state;
                    addCachedInfos("VehicleExceedsMaxCruiseSpeed", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_14;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_VehicleFallsBelowMaxCruiseSpeed");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_VehicleFallsBelowMaxCruiseSpeed");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_14 = state._tr_VehicleFallsBelowMaxCruiseSpeed();
                } else {
                    _trid_14 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_VehicleFallsBelowMaxCruiseSpeed", _trid_14);
                if(_trid_14) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.VehicleFallsBelowMaxCruiseSpeed();
                    copiedState.parent = state;
                    addCachedInfos("VehicleFallsBelowMaxCruiseSpeed", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_15;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_ObstacleDistanceBecomesVeryClose");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_ObstacleDistanceBecomesVeryClose");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_15 = state._tr_ObstacleDistanceBecomesVeryClose();
                } else {
                    _trid_15 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_ObstacleDistanceBecomesVeryClose", _trid_15);
                if(_trid_15) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleDistanceBecomesVeryClose();
                    copiedState.parent = state;
                    addCachedInfos("ObstacleDistanceBecomesVeryClose", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_16;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_ObstacleDistanceBecomesClose");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_ObstacleDistanceBecomesClose");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_16 = state._tr_ObstacleDistanceBecomesClose();
                } else {
                    _trid_16 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_ObstacleDistanceBecomesClose", _trid_16);
                if(_trid_16) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleDistanceBecomesClose();
                    copiedState.parent = state;
                    addCachedInfos("ObstacleDistanceBecomesClose", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_17;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_ObstacleDistanceBecomesBig");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_ObstacleDistanceBecomesBig");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_17 = state._tr_ObstacleDistanceBecomesBig();
                } else {
                    _trid_17 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_ObstacleDistanceBecomesBig", _trid_17);
                if(_trid_17) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleDistanceBecomesBig();
                    copiedState.parent = state;
                    addCachedInfos("ObstacleDistanceBecomesBig", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_18;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_ObstacleStartsTravelFaster");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_ObstacleStartsTravelFaster");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_18 = state._tr_ObstacleStartsTravelFaster();
                } else {
                    _trid_18 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_ObstacleStartsTravelFaster", _trid_18);
                if(_trid_18) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleStartsTravelFaster();
                    copiedState.parent = state;
                    addCachedInfos("ObstacleStartsTravelFaster", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_19;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_ObstacleStopsTravelFaster");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_ObstacleStopsTravelFaster");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_19 = state._tr_ObstacleStopsTravelFaster();
                } else {
                    _trid_19 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_ObstacleStopsTravelFaster", _trid_19);
                if(_trid_19) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleStopsTravelFaster();
                    copiedState.parent = state;
                    addCachedInfos("ObstacleStopsTravelFaster", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_20;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_ObstacleStartsTravelSlower");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_ObstacleStartsTravelSlower");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_20 = state._tr_ObstacleStartsTravelSlower();
                } else {
                    _trid_20 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_ObstacleStartsTravelSlower", _trid_20);
                if(_trid_20) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleStartsTravelSlower();
                    copiedState.parent = state;
                    addCachedInfos("ObstacleStartsTravelSlower", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_21;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_ObstacleStopsTravelSlower");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_ObstacleStopsTravelSlower");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_21 = state._tr_ObstacleStopsTravelSlower();
                } else {
                    _trid_21 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_ObstacleStopsTravelSlower", _trid_21);
                if(_trid_21) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleStopsTravelSlower();
                    copiedState.parent = state;
                    addCachedInfos("ObstacleStopsTravelSlower", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<RSset, ODset>> _trid_22;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_ObstacleAppearsWhenCruiseActive");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_ObstacleAppearsWhenCruiseActive");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_22 = state._tr_ObstacleAppearsWhenCruiseActive();
                } else {
                    _trid_22 = (BSet<BTuple<RSset, ODset>>) cachedValue;
                }
                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_ObstacleAppearsWhenCruiseActive", _trid_22);
                for(BTuple<RSset, ODset> param : _trid_22) {
                    ODset _tmp_1 = param.projection2();
                    RSset _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleAppearsWhenCruiseActive(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("ObstacleAppearsWhenCruiseActive", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<RSset> _trid_23;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_ObstacleAppearsWhenCruiseInactive");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_ObstacleAppearsWhenCruiseInactive");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_23 = state._tr_ObstacleAppearsWhenCruiseInactive();
                } else {
                    _trid_23 = (BSet<RSset>) cachedValue;
                }
                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_ObstacleAppearsWhenCruiseInactive", _trid_23);
                for(RSset param : _trid_23) {
                    RSset _tmp_1 = param;

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleAppearsWhenCruiseInactive(_tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("ObstacleAppearsWhenCruiseInactive", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_24;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_ObstacleDisappears");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_ObstacleDisappears");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_24 = state._tr_ObstacleDisappears();
                } else {
                    _trid_24 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_ObstacleDisappears", _trid_24);
                if(_trid_24) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleDisappears();
                    copiedState.parent = state;
                    addCachedInfos("ObstacleDisappears", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BBoolean, BBoolean>> _trid_25;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_VehicleManageObstacle");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_VehicleManageObstacle");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_25 = state._tr_VehicleManageObstacle();
                } else {
                    _trid_25 = (BSet<BTuple<BBoolean, BBoolean>>) cachedValue;
                }
                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_VehicleManageObstacle", _trid_25);
                for(BTuple<BBoolean, BBoolean> param : _trid_25) {
                    BBoolean _tmp_1 = param.projection2();
                    BBoolean _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.VehicleManageObstacle(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("VehicleManageObstacle", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_26;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_ObstacleBecomesOld");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_ObstacleBecomesOld");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_26 = state._tr_ObstacleBecomesOld();
                } else {
                    _trid_26 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_ObstacleBecomesOld", _trid_26);
                if(_trid_26) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleBecomesOld();
                    copiedState.parent = state;
                    addCachedInfos("ObstacleBecomesOld", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

                state.guardCache = newCache;
            } else {
                if(state._tr_CruiseBecomesNotAllowed()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CruiseBecomesNotAllowed();
                    copiedState.parent = state;
                    addCachedInfos("CruiseBecomesNotAllowed", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_CruiseBecomesAllowed()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CruiseBecomesAllowed();
                    copiedState.parent = state;
                    addCachedInfos("CruiseBecomesAllowed", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BBoolean, BBoolean>> _trid_3 = state._tr_SetCruiseSpeed();
                for(BTuple<BBoolean, BBoolean> param : _trid_3) {
                    BBoolean _tmp_1 = param.projection2();
                    BBoolean _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.SetCruiseSpeed(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("SetCruiseSpeed", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BBoolean, BBoolean>> _trid_4 = state._tr_CCInitialisationFinished();
                for(BTuple<BBoolean, BBoolean> param : _trid_4) {
                    BBoolean _tmp_1 = param.projection2();
                    BBoolean _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CCInitialisationFinished(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("CCInitialisationFinished", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_CCInitialisationDelayFinished()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CCInitialisationDelayFinished();
                    copiedState.parent = state;
                    addCachedInfos("CCInitialisationDelayFinished", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BBoolean, BBoolean>> _trid_6 = state._tr_CruiseSpeedChangeFinished();
                for(BTuple<BBoolean, BBoolean> param : _trid_6) {
                    BBoolean _tmp_1 = param.projection2();
                    BBoolean _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CruiseSpeedChangeFinished(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("CruiseSpeedChangeFinished", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_CruiseSpeedChangeDelayFinished()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CruiseSpeedChangeDelayFinished();
                    copiedState.parent = state;
                    addCachedInfos("CruiseSpeedChangeDelayFinished", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_CruiseOff()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CruiseOff();
                    copiedState.parent = state;
                    addCachedInfos("CruiseOff", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ExternalForcesBecomesExtreme()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ExternalForcesBecomesExtreme();
                    copiedState.parent = state;
                    addCachedInfos("ExternalForcesBecomesExtreme", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ExternalForcesBecomesNormal()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ExternalForcesBecomesNormal();
                    copiedState.parent = state;
                    addCachedInfos("ExternalForcesBecomesNormal", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_VehicleLeavesCruiseSpeed()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.VehicleLeavesCruiseSpeed();
                    copiedState.parent = state;
                    addCachedInfos("VehicleLeavesCruiseSpeed", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_VehicleReachesCruiseSpeed()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.VehicleReachesCruiseSpeed();
                    copiedState.parent = state;
                    addCachedInfos("VehicleReachesCruiseSpeed", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_VehicleExceedsMaxCruiseSpeed()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.VehicleExceedsMaxCruiseSpeed();
                    copiedState.parent = state;
                    addCachedInfos("VehicleExceedsMaxCruiseSpeed", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_VehicleFallsBelowMaxCruiseSpeed()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.VehicleFallsBelowMaxCruiseSpeed();
                    copiedState.parent = state;
                    addCachedInfos("VehicleFallsBelowMaxCruiseSpeed", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ObstacleDistanceBecomesVeryClose()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleDistanceBecomesVeryClose();
                    copiedState.parent = state;
                    addCachedInfos("ObstacleDistanceBecomesVeryClose", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ObstacleDistanceBecomesClose()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleDistanceBecomesClose();
                    copiedState.parent = state;
                    addCachedInfos("ObstacleDistanceBecomesClose", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ObstacleDistanceBecomesBig()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleDistanceBecomesBig();
                    copiedState.parent = state;
                    addCachedInfos("ObstacleDistanceBecomesBig", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ObstacleStartsTravelFaster()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleStartsTravelFaster();
                    copiedState.parent = state;
                    addCachedInfos("ObstacleStartsTravelFaster", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ObstacleStopsTravelFaster()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleStopsTravelFaster();
                    copiedState.parent = state;
                    addCachedInfos("ObstacleStopsTravelFaster", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ObstacleStartsTravelSlower()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleStartsTravelSlower();
                    copiedState.parent = state;
                    addCachedInfos("ObstacleStartsTravelSlower", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ObstacleStopsTravelSlower()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleStopsTravelSlower();
                    copiedState.parent = state;
                    addCachedInfos("ObstacleStopsTravelSlower", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<RSset, ODset>> _trid_22 = state._tr_ObstacleAppearsWhenCruiseActive();
                for(BTuple<RSset, ODset> param : _trid_22) {
                    ODset _tmp_1 = param.projection2();
                    RSset _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleAppearsWhenCruiseActive(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("ObstacleAppearsWhenCruiseActive", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<RSset> _trid_23 = state._tr_ObstacleAppearsWhenCruiseInactive();
                for(RSset param : _trid_23) {
                    RSset _tmp_1 = param;

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleAppearsWhenCruiseInactive(_tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("ObstacleAppearsWhenCruiseInactive", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ObstacleDisappears()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleDisappears();
                    copiedState.parent = state;
                    addCachedInfos("ObstacleDisappears", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BBoolean, BBoolean>> _trid_25 = state._tr_VehicleManageObstacle();
                for(BTuple<BBoolean, BBoolean> param : _trid_25) {
                    BBoolean _tmp_1 = param.projection2();
                    BBoolean _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.VehicleManageObstacle(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    addCachedInfos("VehicleManageObstacle", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ObstacleBecomesOld()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleBecomesOld();
                    copiedState.parent = state;
                    addCachedInfos("ObstacleBecomesOld", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            }
            return result;
        }

        private boolean invariantViolated(final Cruise_finite1_deterministic_MC state) {
            if(!isCaching || state.dependentInvariant.contains("_check_inv_1")) {
                if(!state._check_inv_1()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_1");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_2")) {
                if(!state._check_inv_2()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_2");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_3")) {
                if(!state._check_inv_3()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_3");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_4")) {
                if(!state._check_inv_4()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_4");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_5")) {
                if(!state._check_inv_5()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_5");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_6")) {
                if(!state._check_inv_6()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_6");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_7")) {
                if(!state._check_inv_7()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_7");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_8")) {
                if(!state._check_inv_8()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_8");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_9")) {
                if(!state._check_inv_9()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_9");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_10")) {
                if(!state._check_inv_10()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_10");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_11")) {
                if(!state._check_inv_11()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_11");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_12")) {
                if(!state._check_inv_12()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_12");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_13")) {
                if(!state._check_inv_13()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_13");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_14")) {
                if(!state._check_inv_14()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_14");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_15")) {
                if(!state._check_inv_15()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_15");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_16")) {
                if(!state._check_inv_16()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_16");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_17")) {
                if(!state._check_inv_17()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_17");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_18")) {
                if(!state._check_inv_18()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_18");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_19")) {
                if(!state._check_inv_19()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_19");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_20")) {
                if(!state._check_inv_20()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_20");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_21")) {
                if(!state._check_inv_21()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_21");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_22")) {
                if(!state._check_inv_22()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_22");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_23")) {
                if(!state._check_inv_23()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_23");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_24")) {
                if(!state._check_inv_24()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_24");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_25")) {
                if(!state._check_inv_25()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_25");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_26")) {
                if(!state._check_inv_26()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_26");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_27")) {
                if(!state._check_inv_27()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_27");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_28")) {
                if(!state._check_inv_28()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_28");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_29")) {
                if(!state._check_inv_29()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_29");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_30")) {
                if(!state._check_inv_30()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_30");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_31")) {
                if(!state._check_inv_31()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_31");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_32")) {
                if(!state._check_inv_32()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_32");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_33")) {
                if(!state._check_inv_33()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_33");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_34")) {
                if(!state._check_inv_34()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_34");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_35")) {
                if(!state._check_inv_35()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_35");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_36")) {
                if(!state._check_inv_36()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_36");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_37")) {
                if(!state._check_inv_37()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_37");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_38")) {
                if(!state._check_inv_38()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_38");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_39")) {
                if(!state._check_inv_39()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_39");
                    return true;
                }
            }
            return false;
        }

        private void addCachedInfos(final String operation, final Cruise_finite1_deterministic_MC state, final Cruise_finite1_deterministic_MC copiedState) {
            if(isCaching) {
                copiedState.dependentInvariant = invariantDependency.get(operation);
                copiedState.dependentGuard = guardDependency.get(operation);
            }
            copiedState.stateAccessedVia = operation;
        }

        private void printResult(final int states, final int transitions) {
            if(invariantViolated.get() || deadlockDetected.get()) {
                if(deadlockDetected.get()) {
                    System.out.println("DEADLOCK DETECTED");
                } else {
                    System.out.println("INVARIANT VIOLATED");
                }

                System.out.println("COUNTER EXAMPLE TRACE: ");
                StringBuilder sb = new StringBuilder();
                while(counterExampleState != null) {
                    sb.insert(0, counterExampleState);
                    sb.insert(0, "\n");
                    if(counterExampleState.stateAccessedVia != null) {
                        sb.insert(0, counterExampleState.stateAccessedVia);
                    }
                    sb.insert(0, "\n\n");
                    counterExampleState = counterExampleState.parent;
                }
                System.out.println(sb);
            } else {
                System.out.println("MODEL CHECKING SUCCESSFUL");
            }

            System.out.println("Number of States: " + states);
            System.out.println("Number of Transitions: " + transitions);
        }
    }


    public static void main(String[] args) {
        if(args.length > 4) {
            System.out.println("Expecting 3 command-line arguments: STRATEGY THREADS CACHING DEBUG");
            return;
        }
        Type type = Type.MIXED;
        int threads = 0;
        boolean isCaching = false;
        boolean isDebug = false;

        if(args.length > 0) { 
            if("mixed".equals(args[0])) {
                type = Type.MIXED;
            } else if("bf".equals(args[0])) {
                type = Type.BFS;
            } else if ("df".equals(args[0])) {
                type = Type.DFS;
            } else {
                System.out.println("Value for command-line argument STRATEGY is wrong.");
                System.out.println("Expecting mixed, bf or df.");
                return;
            }
        }
        if(args.length > 1) { 
            try {
                threads = Integer.parseInt(args[1]);
            } catch(NumberFormatException e) {
                System.out.println("Value for command-line argument THREADS is not a number.");
                return;
            }
            if(threads <= 0) {
                System.out.println("Value for command-line argument THREADS must be positive.");
                return;
            }
        }
        if(args.length > 2) { 
            try {
                isCaching = Boolean.parseBoolean(args[2]);
            } catch(Exception e) {
                System.out.println("Value for command-line argument CACHING is not a boolean.");
                return;
            }
        }
        if(args.length > 3) { 
            try {
                isDebug = Boolean.parseBoolean(args[3]);
            } catch(Exception e) {
                System.out.println("Value for command-line argument DEBUG is not a boolean.");
                return;
            }
        }

        ModelChecker modelchecker = new ModelChecker(type, threads, isCaching, isDebug);
        modelchecker.modelCheck();
    }




}
