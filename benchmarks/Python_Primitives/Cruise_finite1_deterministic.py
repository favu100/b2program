from btypes.BBoolean import BBoolean
from btypes.BSet import BSet
from btypes.BInteger import BInteger
from btypes.BObject import BObject


from enum import Enum, auto
class RSset(BObject, Enum):
    RSnone = auto()
    RSpos = auto()
    RSneg = auto()
    RSequal = auto()


    def equal(self, o):
        return BBoolean(self == o)

    def unequal(o):
        return BBoolean(self != o)

    def __str__(self):
                if self == RSset.RSnone:
                    return "RSnone"
                if self == RSset.RSpos:
                    return "RSpos"
                if self == RSset.RSneg:
                    return "RSneg"
                if self == RSset.RSequal:
                    return "RSequal"


from enum import Enum, auto
class ODset(BObject, Enum):
    ODnone = auto()
    ODclose = auto()
    ODveryclose = auto()


    def equal(self, o):
        return BBoolean(self == o)

    def unequal(o):
        return BBoolean(self != o)

    def __str__(self):
                if self == ODset.ODnone:
                    return "ODnone"
                if self == ODset.ODclose:
                    return "ODclose"
                if self == ODset.ODveryclose:
                    return "ODveryclose"


class Cruise_finite1_deterministic:



    _RSset = BSet(RSset.RSnone, RSset.RSpos, RSset.RSneg, RSset.RSequal)
    _ODset = BSet(ODset.ODnone, ODset.ODclose, ODset.ODveryclose)

    def __init__(self):
        self.CruiseAllowed = BBoolean(False)
        self.CruiseActive = BBoolean(False)
        self.VehicleAtCruiseSpeed = BBoolean(False)
        self.VehicleCanKeepSpeed = BBoolean(False)
        self.VehicleTryKeepSpeed = BBoolean(False)
        self.SpeedAboveMax = BBoolean(False)
        self.VehicleTryKeepTimeGap = BBoolean(False)
        self.NumberOfSetCruise = BInteger(0)
        self.CruiseSpeedAtMax = BBoolean(False)
        self.ObstacleDistance = ODset.ODnone
        self.ObstacleStatusJustChanged = BBoolean(False)
        self.CCInitialisationInProgress = BBoolean(False)
        self.CruiseSpeedChangeInProgress = BBoolean(False)
        self.ObstaclePresent = BBoolean(False)
        self.ObstacleRelativeSpeed = RSset.RSnone

    def CruiseBecomesNotAllowed(self):
        if((self.CruiseAllowed.equal(BBoolean(True))).booleanValue()):
            self.CruiseAllowed = BBoolean(False)
            self.CruiseActive = BBoolean(False)
            self.VehicleCanKeepSpeed = BBoolean(False)
            self.VehicleTryKeepSpeed = BBoolean(False)
            self.VehicleAtCruiseSpeed = BBoolean(False)
            self.VehicleTryKeepTimeGap = BBoolean(False)
            self.CruiseSpeedAtMax = BBoolean(False)
            self.ObstacleDistance = ODset.ODnone
            self.NumberOfSetCruise = BInteger(0)
            self.ObstacleStatusJustChanged = BBoolean(False)
            self.CCInitialisationInProgress = BBoolean(False)
            self.CruiseSpeedChangeInProgress = BBoolean(False)


    def CruiseBecomesAllowed(self):
        if((self.CruiseAllowed.equal(BBoolean(False))).booleanValue()):
            self.CruiseAllowed = BBoolean(True)


    def SetCruiseSpeed(self, vcks, csam):
        if((self.CruiseAllowed.equal(BBoolean(True))).booleanValue()):
            _ld_NumberOfSetCruise = self.NumberOfSetCruise
            self.CruiseActive = BBoolean(True)
            self.VehicleCanKeepSpeed = vcks
            if((self.SpeedAboveMax.equal(BBoolean(False))).booleanValue()):
                self.VehicleAtCruiseSpeed = BBoolean(True)
                self.CruiseSpeedAtMax = csam
            else:
                self.CruiseSpeedAtMax = BBoolean(True)
            self.ObstacleStatusJustChanged = BBoolean(True)
            if((self.CruiseActive.equal(BBoolean(True))).booleanValue()):
                self.CruiseSpeedChangeInProgress = BBoolean(True)
            else:
                self.CCInitialisationInProgress = BBoolean(True)
            if((_ld_NumberOfSetCruise.less(BInteger(1))).booleanValue()):
                self.NumberOfSetCruise = _ld_NumberOfSetCruise.plus(BInteger(1))



    def CCInitialisationFinished(self, vtks, vtktg):
        if((self.CCInitialisationInProgress.equal(BBoolean(True))).booleanValue()):
            self.VehicleTryKeepTimeGap = vtktg
            self.VehicleTryKeepSpeed = vtks


    def CCInitialisationDelayFinished(self):
        if((BBoolean(BBoolean(BBoolean(BBoolean(BBoolean(self.CCInitialisationInProgress.equal(BBoolean(True)).booleanValue() and BBoolean(BBoolean(BBoolean(self.VehicleTryKeepSpeed.equal(BBoolean(True)).booleanValue() or self.VehicleTryKeepTimeGap.equal(BBoolean(True)).booleanValue()).booleanValue() or self.ObstacleStatusJustChanged.equal(BBoolean(True)).booleanValue()).booleanValue() or self.CruiseSpeedChangeInProgress.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not self.ObstacleDistance.equal(ODset.ODnone).booleanValue() or self.VehicleTryKeepSpeed.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not BBoolean(BBoolean(BBoolean(self.ObstacleDistance.equal(ODset.ODclose).booleanValue() and self.ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() and self.ObstacleStatusJustChanged.equal(BBoolean(False)).booleanValue()).booleanValue() and self.CruiseSpeedChangeInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() or self.VehicleTryKeepTimeGap.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not BBoolean(BBoolean(self.ObstacleDistance.equal(ODset.ODveryclose).booleanValue() and self.ObstacleStatusJustChanged.equal(BBoolean(False)).booleanValue()).booleanValue() and self.CruiseSpeedChangeInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() or self.VehicleTryKeepTimeGap.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not BBoolean(BBoolean(BBoolean(self.ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() and self.ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() and self.ObstacleStatusJustChanged.equal(BBoolean(False)).booleanValue()).booleanValue() and self.CruiseSpeedChangeInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() or self.VehicleTryKeepSpeed.equal(BBoolean(True)).booleanValue()).booleanValue())).booleanValue()):
            self.CCInitialisationInProgress = BBoolean(True)


    def CruiseSpeedChangeFinished(self, vtks, vtktg):
        if((BBoolean(BBoolean(BBoolean(BBoolean(BBoolean(BBoolean(BBoolean(BBoolean(BBoolean(BBoolean(BUtils.BOOL.elementOf(vtks).booleanValue() and BUtils.BOOL.elementOf(vtktg).booleanValue()).booleanValue() and BBoolean(BBoolean(BBoolean(vtks.equal(BBoolean(True)).booleanValue() or vtktg.equal(BBoolean(True)).booleanValue()).booleanValue() or self.ObstacleStatusJustChanged.equal(BBoolean(True)).booleanValue()).booleanValue() or self.CCInitialisationInProgress.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not self.ObstaclePresent.equal(BBoolean(False)).booleanValue() or vtktg.equal(BBoolean(False)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not self.ObstacleDistance.equal(ODset.ODnone).booleanValue() or vtks.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not BBoolean(BBoolean(BBoolean(self.ObstacleDistance.equal(ODset.ODclose).booleanValue() and self.ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() and self.ObstacleStatusJustChanged.equal(BBoolean(False)).booleanValue()).booleanValue() and self.CCInitialisationInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() or vtktg.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not BBoolean(BBoolean(self.ObstacleDistance.equal(ODset.ODveryclose).booleanValue() and self.ObstacleStatusJustChanged.equal(BBoolean(False)).booleanValue()).booleanValue() and self.CCInitialisationInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() or vtktg.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not BBoolean(BBoolean(BBoolean(self.ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() and self.ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() and self.ObstacleStatusJustChanged.equal(BBoolean(False)).booleanValue()).booleanValue() and self.CCInitialisationInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() or vtks.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not BBoolean(self.ObstacleRelativeSpeed.equal(RSset.RSequal).booleanValue() and self.ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() or vtktg.equal(BBoolean(False)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not BBoolean(self.ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue() and self.ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() or vtktg.equal(BBoolean(False)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not BBoolean(self.ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() and self.ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() or vtktg.equal(BBoolean(False)).booleanValue()).booleanValue())).booleanValue()):
            if((self.CruiseSpeedChangeInProgress.equal(BBoolean(True))).booleanValue()):
                self.VehicleTryKeepTimeGap = vtktg
                self.VehicleTryKeepSpeed = vtks


    def CruiseSpeedChangeDelayFinished(self):
        if((BBoolean(BBoolean(BBoolean(BBoolean(BBoolean(self.CruiseSpeedChangeInProgress.equal(BBoolean(True)).booleanValue() and BBoolean(BBoolean(BBoolean(self.VehicleTryKeepSpeed.equal(BBoolean(True)).booleanValue() or self.VehicleTryKeepTimeGap.equal(BBoolean(True)).booleanValue()).booleanValue() or self.ObstacleStatusJustChanged.equal(BBoolean(True)).booleanValue()).booleanValue() or self.CCInitialisationInProgress.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not self.ObstacleDistance.equal(ODset.ODnone).booleanValue() or self.VehicleTryKeepSpeed.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not BBoolean(BBoolean(BBoolean(self.ObstacleDistance.equal(ODset.ODclose).booleanValue() and self.ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() and self.ObstacleStatusJustChanged.equal(BBoolean(False)).booleanValue()).booleanValue() and self.CCInitialisationInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() or self.VehicleTryKeepTimeGap.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not BBoolean(BBoolean(self.ObstacleDistance.equal(ODset.ODveryclose).booleanValue() and self.ObstacleStatusJustChanged.equal(BBoolean(False)).booleanValue()).booleanValue() and self.CCInitialisationInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() or self.VehicleTryKeepTimeGap.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not BBoolean(BBoolean(BBoolean(self.ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() and self.ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() and self.ObstacleStatusJustChanged.equal(BBoolean(False)).booleanValue()).booleanValue() and self.CCInitialisationInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() or self.VehicleTryKeepSpeed.equal(BBoolean(True)).booleanValue()).booleanValue())).booleanValue()):
            self.CruiseSpeedChangeInProgress = BBoolean(True)


    def CruiseOff(self):
        if((self.CruiseActive.equal(BBoolean(True))).booleanValue()):
            self.CruiseActive = BBoolean(False)
            self.VehicleCanKeepSpeed = BBoolean(False)
            self.VehicleTryKeepSpeed = BBoolean(False)
            self.VehicleAtCruiseSpeed = BBoolean(False)
            self.VehicleTryKeepTimeGap = BBoolean(False)
            self.CruiseSpeedAtMax = BBoolean(False)
            self.ObstacleDistance = ODset.ODnone
            self.NumberOfSetCruise = BInteger(0)
            self.ObstacleStatusJustChanged = BBoolean(False)
            self.CCInitialisationInProgress = BBoolean(False)
            self.CruiseSpeedChangeInProgress = BBoolean(False)


    def ExternalForcesBecomesExtreme(self):
        if((self.VehicleCanKeepSpeed.equal(BBoolean(True))).booleanValue()):
            self.VehicleCanKeepSpeed = BBoolean(False)


    def ExternalForcesBecomesNormal(self):
        if((BBoolean(self.CruiseActive.equal(BBoolean(True)).booleanValue() and self.VehicleCanKeepSpeed.equal(BBoolean(False)).booleanValue())).booleanValue()):
            self.VehicleCanKeepSpeed = BBoolean(True)


    def VehicleLeavesCruiseSpeed(self):
        if((BBoolean(BBoolean(self.VehicleAtCruiseSpeed.equal(BBoolean(True)).booleanValue() and BBoolean(self.VehicleCanKeepSpeed.equal(BBoolean(False)).booleanValue() and self.VehicleTryKeepSpeed.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() or self.VehicleTryKeepSpeed.equal(BBoolean(False)).booleanValue())).booleanValue()):
            self.VehicleAtCruiseSpeed = BBoolean(False)


    def VehicleReachesCruiseSpeed(self):
        if((BBoolean(BBoolean(self.CruiseActive.equal(BBoolean(True)).booleanValue() and self.VehicleAtCruiseSpeed.equal(BBoolean(False)).booleanValue()).booleanValue() and self.SpeedAboveMax.equal(BBoolean(False)).booleanValue())).booleanValue()):
            self.VehicleAtCruiseSpeed = BBoolean(True)


    def VehicleExceedsMaxCruiseSpeed(self):
        if((BBoolean(self.SpeedAboveMax.equal(BBoolean(False)).booleanValue() and BBoolean(BBoolean(self.CruiseActive.equal(BBoolean(False)).booleanValue() or self.VehicleCanKeepSpeed.equal(BBoolean(False)).booleanValue()).booleanValue() or BBoolean(BBoolean(self.ObstacleStatusJustChanged.equal(BBoolean(False)).booleanValue() and self.CCInitialisationInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() and self.CruiseSpeedChangeInProgress.equal(BBoolean(False)).booleanValue())._not().booleanValue()).booleanValue())).booleanValue()):
            self.SpeedAboveMax = BBoolean(True)
            self.VehicleAtCruiseSpeed = BBoolean(False)


    def VehicleFallsBelowMaxCruiseSpeed(self):
        if((self.SpeedAboveMax.equal(BBoolean(True))).booleanValue()):
            self.SpeedAboveMax = BBoolean(False)
            if((BBoolean(self.CruiseActive.equal(BBoolean(True)).booleanValue() and self.CruiseSpeedAtMax.equal(BBoolean(True)).booleanValue())).booleanValue()):
                self.VehicleAtCruiseSpeed = BBoolean(True)



    def ObstacleDistanceBecomesVeryClose(self):
        if((BBoolean(self.ObstacleDistance.equal(ODset.ODclose).booleanValue() and self.ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue())).booleanValue()):
            self.ObstacleDistance = ODset.ODveryclose
            self.ObstacleStatusJustChanged = BBoolean(True)


    def ObstacleDistanceBecomesClose(self):
        if((BBoolean(BBoolean(self.ObstaclePresent.equal(BBoolean(True)).booleanValue() and self.CruiseActive.equal(BBoolean(True)).booleanValue()).booleanValue() and BBoolean(BBoolean(self.ObstacleDistance.equal(ODset.ODveryclose).booleanValue() and self.ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue()).booleanValue() or BBoolean(self.ObstacleDistance.equal(ODset.ODnone).booleanValue() and self.ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue()).booleanValue()).booleanValue())).booleanValue()):
            self.ObstacleDistance = ODset.ODclose
            self.ObstacleStatusJustChanged = BBoolean(True)
            if((self.ObstacleRelativeSpeed.equal(RSset.RSpos)).booleanValue()):
                self.VehicleTryKeepTimeGap = BBoolean(False)



    def ObstacleDistanceBecomesBig(self):
        if((BBoolean(self.ObstacleDistance.equal(ODset.ODclose).booleanValue() and self.ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue())).booleanValue()):
            self.ObstacleStatusJustChanged = BBoolean(True)
            self.ObstacleDistance = ODset.ODnone
            self.VehicleTryKeepTimeGap = BBoolean(False)


    def ObstacleStartsTravelFaster(self):
        if((BBoolean(self.ObstaclePresent.equal(BBoolean(True)).booleanValue() and self.ObstacleRelativeSpeed.equal(RSset.RSequal).booleanValue())).booleanValue()):
            self.ObstacleRelativeSpeed = RSset.RSpos
            if((self.CruiseActive.equal(BBoolean(True))).booleanValue()):
                self.ObstacleStatusJustChanged = BBoolean(True)

            if((self.ObstacleDistance.unequal(ODset.ODveryclose)).booleanValue()):
                self.VehicleTryKeepTimeGap = BBoolean(False)



    def ObstacleStopsTravelFaster(self):
        if((self.ObstacleRelativeSpeed.equal(RSset.RSpos)).booleanValue()):
            self.ObstacleRelativeSpeed = RSset.RSequal
            if((self.CruiseActive.equal(BBoolean(True))).booleanValue()):
                self.ObstacleStatusJustChanged = BBoolean(True)



    def ObstacleStartsTravelSlower(self):
        if((self.ObstacleRelativeSpeed.equal(RSset.RSequal)).booleanValue()):
            self.ObstacleRelativeSpeed = RSset.RSneg
            if((self.CruiseActive.equal(BBoolean(True))).booleanValue()):
                self.ObstacleStatusJustChanged = BBoolean(True)



    def ObstacleStopsTravelSlower(self):
        if((self.ObstacleRelativeSpeed.equal(RSset.RSneg)).booleanValue()):
            self.ObstacleRelativeSpeed = RSset.RSequal
            if((self.CruiseActive.equal(BBoolean(True))).booleanValue()):
                self.ObstacleStatusJustChanged = BBoolean(True)



    def ObstacleAppearsWhenCruiseActive(self, ors, od):
        if((BBoolean(self.ObstaclePresent.equal(BBoolean(False)).booleanValue() and self.CruiseActive.equal(BBoolean(True)).booleanValue())).booleanValue()):
            self.ObstaclePresent = BBoolean(True)
            self.ObstacleStatusJustChanged = BBoolean(True)
            self.ObstacleRelativeSpeed = ors
            self.ObstacleDistance = od


    def ObstacleAppearsWhenCruiseInactive(self, ors):
        if((BBoolean(self.ObstaclePresent.equal(BBoolean(False)).booleanValue() and self.CruiseActive.equal(BBoolean(False)).booleanValue())).booleanValue()):
            self.ObstaclePresent = BBoolean(True)
            self.ObstacleRelativeSpeed = ors
            self.ObstacleDistance = ODset.ODnone


    def ObstacleDisappears(self):
        if((self.ObstaclePresent.equal(BBoolean(True))).booleanValue()):
            self.ObstaclePresent = BBoolean(False)
            self.ObstacleRelativeSpeed = RSset.RSnone
            if((self.CruiseActive.equal(BBoolean(True))).booleanValue()):
                self.ObstacleStatusJustChanged = BBoolean(True)

            self.ObstacleDistance = ODset.ODnone
            self.VehicleTryKeepTimeGap = BBoolean(False)


    def VehicleManageObstacle(self, vtks, vtktg):
        if((BBoolean(BBoolean(BBoolean(BBoolean(BBoolean(BBoolean(BBoolean(BBoolean(BBoolean(BBoolean(BUtils.BOOL.elementOf(vtks).booleanValue() and BUtils.BOOL.elementOf(vtktg).booleanValue()).booleanValue() and BBoolean(BBoolean(BBoolean(vtks.equal(BBoolean(True)).booleanValue() or vtktg.equal(BBoolean(True)).booleanValue()).booleanValue() or self.CCInitialisationInProgress.equal(BBoolean(True)).booleanValue()).booleanValue() or self.CruiseSpeedChangeInProgress.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not self.ObstaclePresent.equal(BBoolean(False)).booleanValue() or vtktg.equal(BBoolean(False)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not self.ObstacleDistance.equal(ODset.ODnone).booleanValue() or vtks.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not BBoolean(BBoolean(BBoolean(self.ObstacleDistance.equal(ODset.ODclose).booleanValue() and self.ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() and self.CCInitialisationInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() and self.CruiseSpeedChangeInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() or vtktg.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not BBoolean(BBoolean(self.ObstacleDistance.equal(ODset.ODveryclose).booleanValue() and self.CCInitialisationInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() and self.CruiseSpeedChangeInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() or vtktg.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not BBoolean(BBoolean(BBoolean(self.ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() and self.ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() and self.CCInitialisationInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() and self.CruiseSpeedChangeInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() or vtks.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not BBoolean(self.ObstacleRelativeSpeed.equal(RSset.RSequal).booleanValue() and self.ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() or vtktg.equal(BBoolean(False)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not BBoolean(self.ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue() and self.ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() or vtktg.equal(BBoolean(False)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not BBoolean(self.ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() and self.ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() or vtktg.equal(BBoolean(False)).booleanValue()).booleanValue())).booleanValue()):
            if((self.ObstacleStatusJustChanged.equal(BBoolean(True))).booleanValue()):
                self.VehicleTryKeepTimeGap = vtktg
                self.VehicleTryKeepSpeed = vtks


    def ObstacleBecomesOld(self):
        if((BBoolean(BBoolean(BBoolean(BBoolean(BBoolean(self.ObstacleStatusJustChanged.equal(BBoolean(True)).booleanValue() and BBoolean(BBoolean(BBoolean(self.VehicleTryKeepSpeed.equal(BBoolean(True)).booleanValue() or self.VehicleTryKeepTimeGap.equal(BBoolean(True)).booleanValue()).booleanValue() or self.CCInitialisationInProgress.equal(BBoolean(True)).booleanValue()).booleanValue() or self.CruiseSpeedChangeInProgress.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not self.ObstacleDistance.equal(ODset.ODnone).booleanValue() or self.VehicleTryKeepSpeed.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not BBoolean(BBoolean(BBoolean(self.ObstacleDistance.equal(ODset.ODclose).booleanValue() and self.ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() and self.CCInitialisationInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() and self.CruiseSpeedChangeInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() or self.VehicleTryKeepTimeGap.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not BBoolean(BBoolean(self.ObstacleDistance.equal(ODset.ODveryclose).booleanValue() and self.CCInitialisationInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() and self.CruiseSpeedChangeInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() or self.VehicleTryKeepTimeGap.equal(BBoolean(True)).booleanValue()).booleanValue()).booleanValue() and BBoolean(not BBoolean(BBoolean(BBoolean(self.ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() and self.ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() and self.CCInitialisationInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() and self.CruiseSpeedChangeInProgress.equal(BBoolean(False)).booleanValue()).booleanValue() or self.VehicleTryKeepSpeed.equal(BBoolean(True)).booleanValue()).booleanValue())).booleanValue()):
            self.ObstacleStatusJustChanged = BBoolean(False)


    def _get_CruiseAllowed(self):
        return self.CruiseAllowed

    def _get_CruiseActive(self):
        return self.CruiseActive

    def _get_VehicleAtCruiseSpeed(self):
        return self.VehicleAtCruiseSpeed

    def _get_VehicleCanKeepSpeed(self):
        return self.VehicleCanKeepSpeed

    def _get_VehicleTryKeepSpeed(self):
        return self.VehicleTryKeepSpeed

    def _get_SpeedAboveMax(self):
        return self.SpeedAboveMax

    def _get_VehicleTryKeepTimeGap(self):
        return self.VehicleTryKeepTimeGap

    def _get_CruiseSpeedAtMax(self):
        return self.CruiseSpeedAtMax

    def _get_ObstaclePresent(self):
        return self.ObstaclePresent

    def _get_ObstacleDistance(self):
        return self.ObstacleDistance

    def _get_ObstacleRelativeSpeed(self):
        return self.ObstacleRelativeSpeed

    def _get_ObstacleStatusJustChanged(self):
        return self.ObstacleStatusJustChanged

    def _get_CCInitialisationInProgress(self):
        return self.CCInitialisationInProgress

    def _get_CruiseSpeedChangeInProgress(self):
        return self.CruiseSpeedChangeInProgress

    def _get_NumberOfSetCruise(self):
        return self.NumberOfSetCruise


