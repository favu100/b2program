import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BObject;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import java.util.Objects;
import java.util.Arrays;
import de.hhu.stups.btypes.PreconditionOrAssertionViolation;
import de.hhu.stups.btypes.StateNotReachableError;
import de.hhu.stups.btypes.BUtils;


public class Cruise_finite1_deterministic {





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

    public Cruise_finite1_deterministic() {
        CruiseAllowed = new BBoolean(false);
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

    public void CruiseBecomesNotAllowed() {
        if((CruiseAllowed.equal(new BBoolean(true))).booleanValue()) {
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
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void CruiseBecomesAllowed() {
        if((CruiseAllowed.equal(new BBoolean(false))).booleanValue()) {
            CruiseAllowed = new BBoolean(true);
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void SetCruiseSpeed(BBoolean vcks, BBoolean csam) {
        if((CruiseAllowed.equal(new BBoolean(true))).booleanValue()) {
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

        } else {
            throw new StateNotReachableError("State is not reachable.");
        }


    }

    public void CCInitialisationFinished(BBoolean vtks, BBoolean vtktg) {
        if((CCInitialisationInProgress.equal(new BBoolean(true))).booleanValue()) {
            VehicleTryKeepTimeGap = vtktg;
            VehicleTryKeepSpeed = vtks;
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }


    }

    public void CCInitialisationDelayFinished() {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue() || ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue()).booleanValue() || CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!ObstacleDistance.equal(ODset.ODnone).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue())).booleanValue()) {
            CCInitialisationInProgress = new BBoolean(true);
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void CruiseSpeedChangeFinished(BBoolean vtks, BBoolean vtktg) {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(BUtils.BOOL.elementOf(vtks).booleanValue() && BUtils.BOOL.elementOf(vtktg).booleanValue()).booleanValue() && new BBoolean(new BBoolean(new BBoolean(vtks.equal(new BBoolean(true)).booleanValue() || vtktg.equal(new BBoolean(true)).booleanValue()).booleanValue() || ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue()).booleanValue() || CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!ObstaclePresent.equal(new BBoolean(false)).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!ObstacleDistance.equal(ODset.ODnone).booleanValue() || vtks.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || vtks.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSequal).booleanValue() && ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue() && ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue())).booleanValue()) {
            if((CruiseSpeedChangeInProgress.equal(new BBoolean(true))).booleanValue()) {
                VehicleTryKeepTimeGap = vtktg;
                VehicleTryKeepSpeed = vtks;
            } else {
                throw new StateNotReachableError("State is not reachable.");
            }

        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void CruiseSpeedChangeDelayFinished() {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue() || ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue()).booleanValue() || CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!ObstacleDistance.equal(ODset.ODnone).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue())).booleanValue()) {
            CruiseSpeedChangeInProgress = new BBoolean(true);
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void CruiseOff() {
        if((CruiseActive.equal(new BBoolean(true))).booleanValue()) {
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
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void ExternalForcesBecomesExtreme() {
        if((VehicleCanKeepSpeed.equal(new BBoolean(true))).booleanValue()) {
            VehicleCanKeepSpeed = new BBoolean(false);
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void ExternalForcesBecomesNormal() {
        if((new BBoolean(CruiseActive.equal(new BBoolean(true)).booleanValue() && VehicleCanKeepSpeed.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
            VehicleCanKeepSpeed = new BBoolean(true);
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void VehicleLeavesCruiseSpeed() {
        if((new BBoolean(new BBoolean(VehicleAtCruiseSpeed.equal(new BBoolean(true)).booleanValue() && new BBoolean(VehicleCanKeepSpeed.equal(new BBoolean(false)).booleanValue() && VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
            VehicleAtCruiseSpeed = new BBoolean(false);
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void VehicleReachesCruiseSpeed() {
        if((new BBoolean(new BBoolean(CruiseActive.equal(new BBoolean(true)).booleanValue() && VehicleAtCruiseSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue() && SpeedAboveMax.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
            VehicleAtCruiseSpeed = new BBoolean(true);
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void VehicleExceedsMaxCruiseSpeed() {
        if((new BBoolean(SpeedAboveMax.equal(new BBoolean(false)).booleanValue() && new BBoolean(new BBoolean(CruiseActive.equal(new BBoolean(false)).booleanValue() || VehicleCanKeepSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue() || new BBoolean(new BBoolean(ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).not().booleanValue()).booleanValue())).booleanValue()) {
            SpeedAboveMax = new BBoolean(true);
            VehicleAtCruiseSpeed = new BBoolean(false);
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void VehicleFallsBelowMaxCruiseSpeed() {
        if((SpeedAboveMax.equal(new BBoolean(true))).booleanValue()) {
            SpeedAboveMax = new BBoolean(false);
            if((new BBoolean(CruiseActive.equal(new BBoolean(true)).booleanValue() && CruiseSpeedAtMax.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
                VehicleAtCruiseSpeed = new BBoolean(true);
            } 

        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void ObstacleDistanceBecomesVeryClose() {
        if((new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue())).booleanValue()) {
            ObstacleDistance = ODset.ODveryclose;
            ObstacleStatusJustChanged = new BBoolean(true);
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void ObstacleDistanceBecomesClose() {
        if((new BBoolean(new BBoolean(ObstaclePresent.equal(new BBoolean(true)).booleanValue() && CruiseActive.equal(new BBoolean(true)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue()).booleanValue() || new BBoolean(ObstacleDistance.equal(ODset.ODnone).booleanValue() && ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
            ObstacleDistance = ODset.ODclose;
            ObstacleStatusJustChanged = new BBoolean(true);
            if((ObstacleRelativeSpeed.equal(RSset.RSpos)).booleanValue()) {
                VehicleTryKeepTimeGap = new BBoolean(false);
            } 

        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void ObstacleDistanceBecomesBig() {
        if((new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue())).booleanValue()) {
            ObstacleStatusJustChanged = new BBoolean(true);
            ObstacleDistance = ODset.ODnone;
            VehicleTryKeepTimeGap = new BBoolean(false);
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void ObstacleStartsTravelFaster() {
        if((new BBoolean(ObstaclePresent.equal(new BBoolean(true)).booleanValue() && ObstacleRelativeSpeed.equal(RSset.RSequal).booleanValue())).booleanValue()) {
            ObstacleRelativeSpeed = RSset.RSpos;
            if((CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                ObstacleStatusJustChanged = new BBoolean(true);
            } 

            if((ObstacleDistance.unequal(ODset.ODveryclose)).booleanValue()) {
                VehicleTryKeepTimeGap = new BBoolean(false);
            } 

        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void ObstacleStopsTravelFaster() {
        if((ObstacleRelativeSpeed.equal(RSset.RSpos)).booleanValue()) {
            ObstacleRelativeSpeed = RSset.RSequal;
            if((CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                ObstacleStatusJustChanged = new BBoolean(true);
            } 

        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void ObstacleStartsTravelSlower() {
        if((ObstacleRelativeSpeed.equal(RSset.RSequal)).booleanValue()) {
            ObstacleRelativeSpeed = RSset.RSneg;
            if((CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                ObstacleStatusJustChanged = new BBoolean(true);
            } 

        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void ObstacleStopsTravelSlower() {
        if((ObstacleRelativeSpeed.equal(RSset.RSneg)).booleanValue()) {
            ObstacleRelativeSpeed = RSset.RSequal;
            if((CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                ObstacleStatusJustChanged = new BBoolean(true);
            } 

        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void ObstacleAppearsWhenCruiseActive(RSset ors, ODset od) {
        if((new BBoolean(ObstaclePresent.equal(new BBoolean(false)).booleanValue() && CruiseActive.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            ObstaclePresent = new BBoolean(true);
            ObstacleStatusJustChanged = new BBoolean(true);
            ObstacleRelativeSpeed = ors;
            ObstacleDistance = od;
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }


    }

    public void ObstacleAppearsWhenCruiseInactive(RSset ors) {
        if((new BBoolean(ObstaclePresent.equal(new BBoolean(false)).booleanValue() && CruiseActive.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
            ObstaclePresent = new BBoolean(true);
            ObstacleRelativeSpeed = ors;
            ObstacleDistance = ODset.ODnone;
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }


    }

    public void ObstacleDisappears() {
        if((ObstaclePresent.equal(new BBoolean(true))).booleanValue()) {
            ObstaclePresent = new BBoolean(false);
            ObstacleRelativeSpeed = RSset.RSnone;
            if((CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                ObstacleStatusJustChanged = new BBoolean(true);
            } 

            ObstacleDistance = ODset.ODnone;
            VehicleTryKeepTimeGap = new BBoolean(false);
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void VehicleManageObstacle(BBoolean vtks, BBoolean vtktg) {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(BUtils.BOOL.elementOf(vtks).booleanValue() && BUtils.BOOL.elementOf(vtktg).booleanValue()).booleanValue() && new BBoolean(new BBoolean(new BBoolean(vtks.equal(new BBoolean(true)).booleanValue() || vtktg.equal(new BBoolean(true)).booleanValue()).booleanValue() || CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue() || CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!ObstaclePresent.equal(new BBoolean(false)).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!ObstacleDistance.equal(ODset.ODnone).booleanValue() || vtks.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || vtks.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSequal).booleanValue() && ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue() && ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue())).booleanValue()) {
            if((ObstacleStatusJustChanged.equal(new BBoolean(true))).booleanValue()) {
                VehicleTryKeepTimeGap = vtktg;
                VehicleTryKeepSpeed = vtks;
            } else {
                throw new StateNotReachableError("State is not reachable.");
            }

        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void ObstacleBecomesOld() {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue() || CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue() || CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!ObstacleDistance.equal(ODset.ODnone).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue())).booleanValue()) {
            ObstacleStatusJustChanged = new BBoolean(false);
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

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



}
