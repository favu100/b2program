import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BObject;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
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

    private BSet<RSset> _RSset = new BSet<RSset>(RSset.RSnone, RSset.RSpos, RSset.RSneg, RSset.RSequal);
    private BSet<ODset> _ODset = new BSet<ODset>(ODset.ODnone, ODset.ODclose, ODset.ODveryclose);

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
        }
    }

    public void CruiseBecomesAllowed() {
        if((CruiseAllowed.equal(new BBoolean(false))).booleanValue()) {
            CruiseAllowed = new BBoolean(true);
        }
    }

    public void SetCruiseSpeed(BBoolean vcks, BBoolean csam) {
        if((CruiseAllowed.equal(new BBoolean(true))).booleanValue()) {
            BInteger _ld_NumberOfSetCruise = NumberOfSetCruise;
            CruiseActive = new BBoolean(true);
            VehicleCanKeepSpeed = vcks;
            if((SpeedAboveMax.equal(new BBoolean(false))).booleanValue()) {
                VehicleAtCruiseSpeed = new BBoolean(true);
                CruiseSpeedAtMax = csam;
            } else {
                CruiseSpeedAtMax = new BBoolean(true);
            }
            ObstacleStatusJustChanged = new BBoolean(true);
            if((CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                CruiseSpeedChangeInProgress = new BBoolean(true);
            } else {
                CCInitialisationInProgress = new BBoolean(true);
            }
            if((_ld_NumberOfSetCruise.less(new BInteger(1))).booleanValue()) {
                NumberOfSetCruise = _ld_NumberOfSetCruise.plus(new BInteger(1));
            } 
        }
    }

    public void CCInitialisationFinished(BBoolean vtks, BBoolean vtktg) {
        if((CCInitialisationInProgress.equal(new BBoolean(true))).booleanValue()) {
            VehicleTryKeepTimeGap = vtktg;
            VehicleTryKeepSpeed = vtks;
        }
    }

    public void CCInitialisationDelayFinished() {
        if((CCInitialisationInProgress.equal(new BBoolean(true)).and(VehicleTryKeepSpeed.equal(new BBoolean(true)).or(VehicleTryKeepTimeGap.equal(new BBoolean(true))).or(ObstacleStatusJustChanged.equal(new BBoolean(true))).or(CruiseSpeedChangeInProgress.equal(new BBoolean(true)))).and(ObstacleDistance.equal(ODset.ODnone).implies(VehicleTryKeepSpeed.equal(new BBoolean(true)))).and(ObstacleDistance.equal(ODset.ODclose).and(ObstacleRelativeSpeed.unequal(RSset.RSpos)).and(ObstacleStatusJustChanged.equal(new BBoolean(false))).and(CruiseSpeedChangeInProgress.equal(new BBoolean(false))).implies(VehicleTryKeepTimeGap.equal(new BBoolean(true)))).and(ObstacleDistance.equal(ODset.ODveryclose).and(ObstacleStatusJustChanged.equal(new BBoolean(false))).and(CruiseSpeedChangeInProgress.equal(new BBoolean(false))).implies(VehicleTryKeepTimeGap.equal(new BBoolean(true)))).and(ObstacleRelativeSpeed.equal(RSset.RSpos).and(ObstacleDistance.unequal(ODset.ODveryclose)).and(ObstacleStatusJustChanged.equal(new BBoolean(false))).and(CruiseSpeedChangeInProgress.equal(new BBoolean(false))).implies(VehicleTryKeepSpeed.equal(new BBoolean(true))))).booleanValue()) {
            CCInitialisationInProgress = new BBoolean(true);
        }
    }

    public void CruiseSpeedChangeFinished(BBoolean vtks, BBoolean vtktg) {
        if((BUtils.BOOL.elementOf(vtks).and(BUtils.BOOL.elementOf(vtktg)).and(vtks.equal(new BBoolean(true)).or(vtktg.equal(new BBoolean(true))).or(ObstacleStatusJustChanged.equal(new BBoolean(true))).or(CCInitialisationInProgress.equal(new BBoolean(true)))).and(ObstaclePresent.equal(new BBoolean(false)).implies(vtktg.equal(new BBoolean(false)))).and(ObstacleDistance.equal(ODset.ODnone).implies(vtks.equal(new BBoolean(true)))).and(ObstacleDistance.equal(ODset.ODclose).and(ObstacleRelativeSpeed.unequal(RSset.RSpos)).and(ObstacleStatusJustChanged.equal(new BBoolean(false))).and(CCInitialisationInProgress.equal(new BBoolean(false))).implies(vtktg.equal(new BBoolean(true)))).and(ObstacleDistance.equal(ODset.ODveryclose).and(ObstacleStatusJustChanged.equal(new BBoolean(false))).and(CCInitialisationInProgress.equal(new BBoolean(false))).implies(vtktg.equal(new BBoolean(true)))).and(ObstacleRelativeSpeed.equal(RSset.RSpos).and(ObstacleDistance.unequal(ODset.ODveryclose)).and(ObstacleStatusJustChanged.equal(new BBoolean(false))).and(CCInitialisationInProgress.equal(new BBoolean(false))).implies(vtks.equal(new BBoolean(true)))).and(ObstacleRelativeSpeed.equal(RSset.RSequal).and(ObstacleDistance.equal(ODset.ODnone)).implies(vtktg.equal(new BBoolean(false)))).and(ObstacleRelativeSpeed.equal(RSset.RSneg).and(ObstacleDistance.equal(ODset.ODnone)).implies(vtktg.equal(new BBoolean(false)))).and(ObstacleRelativeSpeed.equal(RSset.RSpos).and(ObstacleDistance.unequal(ODset.ODveryclose)).implies(vtktg.equal(new BBoolean(false))))).booleanValue()) {
            if((CruiseSpeedChangeInProgress.equal(new BBoolean(true))).booleanValue()) {
                VehicleTryKeepTimeGap = vtktg;
                VehicleTryKeepSpeed = vtks;
            }
        }
    }

    public void CruiseSpeedChangeDelayFinished() {
        if((CruiseSpeedChangeInProgress.equal(new BBoolean(true)).and(VehicleTryKeepSpeed.equal(new BBoolean(true)).or(VehicleTryKeepTimeGap.equal(new BBoolean(true))).or(ObstacleStatusJustChanged.equal(new BBoolean(true))).or(CCInitialisationInProgress.equal(new BBoolean(true)))).and(ObstacleDistance.equal(ODset.ODnone).implies(VehicleTryKeepSpeed.equal(new BBoolean(true)))).and(ObstacleDistance.equal(ODset.ODclose).and(ObstacleRelativeSpeed.unequal(RSset.RSpos)).and(ObstacleStatusJustChanged.equal(new BBoolean(false))).and(CCInitialisationInProgress.equal(new BBoolean(false))).implies(VehicleTryKeepTimeGap.equal(new BBoolean(true)))).and(ObstacleDistance.equal(ODset.ODveryclose).and(ObstacleStatusJustChanged.equal(new BBoolean(false))).and(CCInitialisationInProgress.equal(new BBoolean(false))).implies(VehicleTryKeepTimeGap.equal(new BBoolean(true)))).and(ObstacleRelativeSpeed.equal(RSset.RSpos).and(ObstacleDistance.unequal(ODset.ODveryclose)).and(ObstacleStatusJustChanged.equal(new BBoolean(false))).and(CCInitialisationInProgress.equal(new BBoolean(false))).implies(VehicleTryKeepSpeed.equal(new BBoolean(true))))).booleanValue()) {
            CruiseSpeedChangeInProgress = new BBoolean(true);
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
        }
    }

    public void ExternalForcesBecomesExtreme() {
        if((VehicleCanKeepSpeed.equal(new BBoolean(true))).booleanValue()) {
            VehicleCanKeepSpeed = new BBoolean(false);
        }
    }

    public void ExternalForcesBecomesNormal() {
        if((CruiseActive.equal(new BBoolean(true)).and(VehicleCanKeepSpeed.equal(new BBoolean(false)))).booleanValue()) {
            VehicleCanKeepSpeed = new BBoolean(true);
        }
    }

    public void VehicleLeavesCruiseSpeed() {
        if((VehicleAtCruiseSpeed.equal(new BBoolean(true)).and(VehicleCanKeepSpeed.equal(new BBoolean(false)).and(VehicleTryKeepSpeed.equal(new BBoolean(true)))).and(VehicleTryKeepSpeed.equal(new BBoolean(false)))).booleanValue()) {
            VehicleAtCruiseSpeed = new BBoolean(false);
        }
    }

    public void VehicleReachesCruiseSpeed() {
        if((CruiseActive.equal(new BBoolean(true)).and(VehicleAtCruiseSpeed.equal(new BBoolean(false))).and(SpeedAboveMax.equal(new BBoolean(false)))).booleanValue()) {
            VehicleAtCruiseSpeed = new BBoolean(true);
        }
    }

    public void VehicleExceedsMaxCruiseSpeed() {
        if((SpeedAboveMax.equal(new BBoolean(false)).and(CruiseActive.equal(new BBoolean(false)).or(VehicleCanKeepSpeed.equal(new BBoolean(false))).or(ObstacleStatusJustChanged.equal(new BBoolean(false)).and(CCInitialisationInProgress.equal(new BBoolean(false))).and(CruiseSpeedChangeInProgress.equal(new BBoolean(false))).not()))).booleanValue()) {
            SpeedAboveMax = new BBoolean(true);
            VehicleAtCruiseSpeed = new BBoolean(false);
        }
    }

    public void VehicleFallsBelowMaxCruiseSpeed() {
        if((SpeedAboveMax.equal(new BBoolean(true))).booleanValue()) {
            SpeedAboveMax = new BBoolean(false);
            if((CruiseActive.equal(new BBoolean(true)).and(CruiseSpeedAtMax.equal(new BBoolean(true)))).booleanValue()) {
                VehicleAtCruiseSpeed = new BBoolean(true);
            } 
        }
    }

    public void ObstacleDistanceBecomesVeryClose() {
        if((ObstacleDistance.equal(ODset.ODclose).and(ObstacleRelativeSpeed.equal(RSset.RSneg))).booleanValue()) {
            ObstacleDistance = ODset.ODveryclose;
            ObstacleStatusJustChanged = new BBoolean(true);
        }
    }

    public void ObstacleDistanceBecomesClose() {
        if((ObstaclePresent.equal(new BBoolean(true)).and(CruiseActive.equal(new BBoolean(true))).and(ObstacleDistance.equal(ODset.ODveryclose).and(ObstacleRelativeSpeed.equal(RSset.RSpos)).or(ObstacleDistance.equal(ODset.ODnone).and(ObstacleRelativeSpeed.equal(RSset.RSneg))))).booleanValue()) {
            ObstacleDistance = ODset.ODclose;
            ObstacleStatusJustChanged = new BBoolean(true);
            if((ObstacleRelativeSpeed.equal(RSset.RSpos)).booleanValue()) {
                VehicleTryKeepTimeGap = new BBoolean(false);
            } 
        }
    }

    public void ObstacleDistanceBecomesBig() {
        if((ObstacleDistance.equal(ODset.ODclose).and(ObstacleRelativeSpeed.equal(RSset.RSpos))).booleanValue()) {
            ObstacleStatusJustChanged = new BBoolean(true);
            ObstacleDistance = ODset.ODnone;
            VehicleTryKeepTimeGap = new BBoolean(false);
        }
    }

    public void ObstacleStartsTravelFaster() {
        if((ObstaclePresent.equal(new BBoolean(true)).and(ObstacleRelativeSpeed.equal(RSset.RSequal))).booleanValue()) {
            ObstacleRelativeSpeed = RSset.RSpos;
            if((CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                ObstacleStatusJustChanged = new BBoolean(true);
            } 
            if((ObstacleDistance.unequal(ODset.ODveryclose)).booleanValue()) {
                VehicleTryKeepTimeGap = new BBoolean(false);
            } 
        }
    }

    public void ObstacleStopsTravelFaster() {
        if((ObstacleRelativeSpeed.equal(RSset.RSpos)).booleanValue()) {
            ObstacleRelativeSpeed = RSset.RSequal;
            if((CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                ObstacleStatusJustChanged = new BBoolean(true);
            } 
        }
    }

    public void ObstacleStartsTravelSlower() {
        if((ObstacleRelativeSpeed.equal(RSset.RSequal)).booleanValue()) {
            ObstacleRelativeSpeed = RSset.RSneg;
            if((CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                ObstacleStatusJustChanged = new BBoolean(true);
            } 
        }
    }

    public void ObstacleStopsTravelSlower() {
        if((ObstacleRelativeSpeed.equal(RSset.RSneg)).booleanValue()) {
            ObstacleRelativeSpeed = RSset.RSequal;
            if((CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                ObstacleStatusJustChanged = new BBoolean(true);
            } 
        }
    }

    public void ObstacleAppearsWhenCruiseActive(RSset ors, ODset od) {
        if((ObstaclePresent.equal(new BBoolean(false)).and(CruiseActive.equal(new BBoolean(true)))).booleanValue()) {
            ObstaclePresent = new BBoolean(true);
            ObstacleStatusJustChanged = new BBoolean(true);
            ObstacleRelativeSpeed = ors;
            ObstacleDistance = od;
        }
    }

    public void ObstacleAppearsWhenCruiseInactive(RSset ors) {
        if((ObstaclePresent.equal(new BBoolean(false)).and(CruiseActive.equal(new BBoolean(false)))).booleanValue()) {
            ObstaclePresent = new BBoolean(true);
            ObstacleRelativeSpeed = ors;
            ObstacleDistance = ODset.ODnone;
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
        }
    }

    public void VehicleManageObstacle(BBoolean vtks, BBoolean vtktg) {
        if((BUtils.BOOL.elementOf(vtks).and(BUtils.BOOL.elementOf(vtktg)).and(vtks.equal(new BBoolean(true)).or(vtktg.equal(new BBoolean(true))).or(CCInitialisationInProgress.equal(new BBoolean(true))).or(CruiseSpeedChangeInProgress.equal(new BBoolean(true)))).and(ObstaclePresent.equal(new BBoolean(false)).implies(vtktg.equal(new BBoolean(false)))).and(ObstacleDistance.equal(ODset.ODnone).implies(vtks.equal(new BBoolean(true)))).and(ObstacleDistance.equal(ODset.ODclose).and(ObstacleRelativeSpeed.unequal(RSset.RSpos)).and(CCInitialisationInProgress.equal(new BBoolean(false))).and(CruiseSpeedChangeInProgress.equal(new BBoolean(false))).implies(vtktg.equal(new BBoolean(true)))).and(ObstacleDistance.equal(ODset.ODveryclose).and(CCInitialisationInProgress.equal(new BBoolean(false))).and(CruiseSpeedChangeInProgress.equal(new BBoolean(false))).implies(vtktg.equal(new BBoolean(true)))).and(ObstacleRelativeSpeed.equal(RSset.RSpos).and(ObstacleDistance.unequal(ODset.ODveryclose)).and(CCInitialisationInProgress.equal(new BBoolean(false))).and(CruiseSpeedChangeInProgress.equal(new BBoolean(false))).implies(vtks.equal(new BBoolean(true)))).and(ObstacleRelativeSpeed.equal(RSset.RSequal).and(ObstacleDistance.equal(ODset.ODnone)).implies(vtktg.equal(new BBoolean(false)))).and(ObstacleRelativeSpeed.equal(RSset.RSneg).and(ObstacleDistance.equal(ODset.ODnone)).implies(vtktg.equal(new BBoolean(false)))).and(ObstacleRelativeSpeed.equal(RSset.RSpos).and(ObstacleDistance.unequal(ODset.ODveryclose)).implies(vtktg.equal(new BBoolean(false))))).booleanValue()) {
            if((ObstacleStatusJustChanged.equal(new BBoolean(true))).booleanValue()) {
                VehicleTryKeepTimeGap = vtktg;
                VehicleTryKeepSpeed = vtks;
            }
        }
    }

    public void ObstacleBecomesOld() {
        if((ObstacleStatusJustChanged.equal(new BBoolean(true)).and(VehicleTryKeepSpeed.equal(new BBoolean(true)).or(VehicleTryKeepTimeGap.equal(new BBoolean(true))).or(CCInitialisationInProgress.equal(new BBoolean(true))).or(CruiseSpeedChangeInProgress.equal(new BBoolean(true)))).and(ObstacleDistance.equal(ODset.ODnone).implies(VehicleTryKeepSpeed.equal(new BBoolean(true)))).and(ObstacleDistance.equal(ODset.ODclose).and(ObstacleRelativeSpeed.unequal(RSset.RSpos)).and(CCInitialisationInProgress.equal(new BBoolean(false))).and(CruiseSpeedChangeInProgress.equal(new BBoolean(false))).implies(VehicleTryKeepTimeGap.equal(new BBoolean(true)))).and(ObstacleDistance.equal(ODset.ODveryclose).and(CCInitialisationInProgress.equal(new BBoolean(false))).and(CruiseSpeedChangeInProgress.equal(new BBoolean(false))).implies(VehicleTryKeepTimeGap.equal(new BBoolean(true)))).and(ObstacleRelativeSpeed.equal(RSset.RSpos).and(ObstacleDistance.unequal(ODset.ODveryclose)).and(CCInitialisationInProgress.equal(new BBoolean(false))).and(CruiseSpeedChangeInProgress.equal(new BBoolean(false))).implies(VehicleTryKeepSpeed.equal(new BBoolean(true))))).booleanValue()) {
            ObstacleStatusJustChanged = new BBoolean(false);
        }
    }



}
