import { BInteger } from './btypes/BInteger.js';
import { BBoolean } from './btypes/BBoolean.js';
import { BSet } from './btypes/BSet.js';
import { BUtils } from "./btypes/BUtils.js";
export var enum_RSset;
(function (enum_RSset) {
    enum_RSset[enum_RSset["RSnone"] = 0] = "RSnone";
    enum_RSset[enum_RSset["RSpos"] = 1] = "RSpos";
    enum_RSset[enum_RSset["RSneg"] = 2] = "RSneg";
    enum_RSset[enum_RSset["RSequal"] = 3] = "RSequal";
})(enum_RSset || (enum_RSset = {}));
export class RSset {
    constructor(value) {
        this.value = value;
    }
    equal(other) {
        return new BBoolean(this.value === other.value);
    }
    unequal(other) {
        return new BBoolean(this.value !== other.value);
    }
    equals(o) {
        if (!(o instanceof RSset)) {
            return false;
        }
        return this.value === o.value;
    }
    hashCode() {
        return 0;
    }
    toString() {
        return enum_RSset[this.value].toString();
    }
    static get_RSnone() { return new RSset(enum_RSset.RSnone); }
    static get_RSpos() { return new RSset(enum_RSset.RSpos); }
    static get_RSneg() { return new RSset(enum_RSset.RSneg); }
    static get_RSequal() { return new RSset(enum_RSset.RSequal); }
}
export var enum_ODset;
(function (enum_ODset) {
    enum_ODset[enum_ODset["ODnone"] = 0] = "ODnone";
    enum_ODset[enum_ODset["ODclose"] = 1] = "ODclose";
    enum_ODset[enum_ODset["ODveryclose"] = 2] = "ODveryclose";
})(enum_ODset || (enum_ODset = {}));
export class ODset {
    constructor(value) {
        this.value = value;
    }
    equal(other) {
        return new BBoolean(this.value === other.value);
    }
    unequal(other) {
        return new BBoolean(this.value !== other.value);
    }
    equals(o) {
        if (!(o instanceof ODset)) {
            return false;
        }
        return this.value === o.value;
    }
    hashCode() {
        return 0;
    }
    toString() {
        return enum_ODset[this.value].toString();
    }
    static get_ODnone() { return new ODset(enum_ODset.ODnone); }
    static get_ODclose() { return new ODset(enum_ODset.ODclose); }
    static get_ODveryclose() { return new ODset(enum_ODset.ODveryclose); }
}
export default class Cruise_finite1_deterministic {
    constructor() {
        this.CruiseAllowed = new BBoolean(false);
        this.CruiseActive = new BBoolean(false);
        this.VehicleAtCruiseSpeed = new BBoolean(false);
        this.VehicleCanKeepSpeed = new BBoolean(false);
        this.VehicleTryKeepSpeed = new BBoolean(false);
        this.SpeedAboveMax = new BBoolean(false);
        this.VehicleTryKeepTimeGap = new BBoolean(false);
        this.NumberOfSetCruise = new BInteger(0);
        this.CruiseSpeedAtMax = new BBoolean(false);
        this.ObstacleDistance = new ODset(enum_ODset.ODnone);
        this.ObstacleStatusJustChanged = new BBoolean(false);
        this.CCInitialisationInProgress = new BBoolean(false);
        this.CruiseSpeedChangeInProgress = new BBoolean(false);
        this.ObstaclePresent = new BBoolean(false);
        this.ObstacleRelativeSpeed = new RSset(enum_RSset.RSnone);
    }
    CruiseBecomesNotAllowed() {
        if ((this.CruiseAllowed.equal(new BBoolean(true))).booleanValue()) {
            this.CruiseAllowed = new BBoolean(false);
            this.CruiseActive = new BBoolean(false);
            this.VehicleCanKeepSpeed = new BBoolean(false);
            this.VehicleTryKeepSpeed = new BBoolean(false);
            this.VehicleAtCruiseSpeed = new BBoolean(false);
            this.VehicleTryKeepTimeGap = new BBoolean(false);
            this.CruiseSpeedAtMax = new BBoolean(false);
            this.ObstacleDistance = new ODset(enum_ODset.ODnone);
            this.NumberOfSetCruise = new BInteger(0);
            this.ObstacleStatusJustChanged = new BBoolean(false);
            this.CCInitialisationInProgress = new BBoolean(false);
            this.CruiseSpeedChangeInProgress = new BBoolean(false);
        }
    }
    CruiseBecomesAllowed() {
        if ((this.CruiseAllowed.equal(new BBoolean(false))).booleanValue()) {
            this.CruiseAllowed = new BBoolean(true);
        }
    }
    SetCruiseSpeed(vcks, csam) {
        if ((this.CruiseAllowed.equal(new BBoolean(true))).booleanValue()) {
            let _ld_CruiseActive = this.CruiseActive;
            let _ld_NumberOfSetCruise = this.NumberOfSetCruise;
            this.CruiseActive = new BBoolean(true);
            this.VehicleCanKeepSpeed = vcks;
            if ((this.SpeedAboveMax.equal(new BBoolean(false))).booleanValue()) {
                this.VehicleAtCruiseSpeed = new BBoolean(true);
                this.CruiseSpeedAtMax = csam;
            }
            else {
                this.CruiseSpeedAtMax = new BBoolean(true);
            }
            this.ObstacleStatusJustChanged = new BBoolean(true);
            if ((_ld_CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                this.CruiseSpeedChangeInProgress = new BBoolean(true);
            }
            else {
                this.CCInitialisationInProgress = new BBoolean(true);
            }
            if ((_ld_NumberOfSetCruise.less(new BInteger(1))).booleanValue()) {
                this.NumberOfSetCruise = _ld_NumberOfSetCruise.plus(new BInteger(1));
            }
        }
    }
    CCInitialisationFinished(vtks, vtktg) {
        if ((this.CCInitialisationInProgress.equal(new BBoolean(true))).booleanValue()) {
            this.VehicleTryKeepTimeGap = vtktg;
            this.VehicleTryKeepSpeed = vtks;
        }
    }
    CCInitialisationDelayFinished() {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.unequal(new RSset(enum_RSset.RSpos)).booleanValue()).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODveryclose)).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue())).booleanValue()) {
            this.CCInitialisationInProgress = new BBoolean(true);
        }
    }
    CruiseSpeedChangeFinished(vtks, vtktg) {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(BUtils.BOOL.elementOf(vtks).booleanValue() && BUtils.BOOL.elementOf(vtktg).booleanValue()).booleanValue() && new BBoolean(new BBoolean(new BBoolean(vtks.equal(new BBoolean(true)).booleanValue() || vtktg.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!this.ObstaclePresent.equal(new BBoolean(false)).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue() || vtks.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.unequal(new RSset(enum_RSset.RSpos)).booleanValue()).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODveryclose)).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || vtks.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSequal)).booleanValue() && this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSneg)).booleanValue() && this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue())).booleanValue()) {
            if ((this.CruiseSpeedChangeInProgress.equal(new BBoolean(true))).booleanValue()) {
                this.VehicleTryKeepTimeGap = vtktg;
                this.VehicleTryKeepSpeed = vtks;
            }
        }
    }
    CruiseSpeedChangeDelayFinished() {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.unequal(new RSset(enum_RSset.RSpos)).booleanValue()).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODveryclose)).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue())).booleanValue()) {
            this.CruiseSpeedChangeInProgress = new BBoolean(true);
        }
    }
    CruiseOff() {
        if ((this.CruiseActive.equal(new BBoolean(true))).booleanValue()) {
            this.CruiseActive = new BBoolean(false);
            this.VehicleCanKeepSpeed = new BBoolean(false);
            this.VehicleTryKeepSpeed = new BBoolean(false);
            this.VehicleAtCruiseSpeed = new BBoolean(false);
            this.VehicleTryKeepTimeGap = new BBoolean(false);
            this.CruiseSpeedAtMax = new BBoolean(false);
            this.ObstacleDistance = new ODset(enum_ODset.ODnone);
            this.NumberOfSetCruise = new BInteger(0);
            this.ObstacleStatusJustChanged = new BBoolean(false);
            this.CCInitialisationInProgress = new BBoolean(false);
            this.CruiseSpeedChangeInProgress = new BBoolean(false);
        }
    }
    ExternalForcesBecomesExtreme() {
        if ((this.VehicleCanKeepSpeed.equal(new BBoolean(true))).booleanValue()) {
            this.VehicleCanKeepSpeed = new BBoolean(false);
        }
    }
    ExternalForcesBecomesNormal() {
        if ((new BBoolean(this.CruiseActive.equal(new BBoolean(true)).booleanValue() && this.VehicleCanKeepSpeed.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
            this.VehicleCanKeepSpeed = new BBoolean(true);
        }
    }
    VehicleLeavesCruiseSpeed() {
        if ((new BBoolean(new BBoolean(this.VehicleAtCruiseSpeed.equal(new BBoolean(true)).booleanValue() && new BBoolean(this.VehicleCanKeepSpeed.equal(new BBoolean(false)).booleanValue() && this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
            this.VehicleAtCruiseSpeed = new BBoolean(false);
        }
    }
    VehicleReachesCruiseSpeed() {
        if ((new BBoolean(new BBoolean(this.CruiseActive.equal(new BBoolean(true)).booleanValue() && this.VehicleAtCruiseSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.SpeedAboveMax.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
            this.VehicleAtCruiseSpeed = new BBoolean(true);
        }
    }
    VehicleExceedsMaxCruiseSpeed() {
        if ((new BBoolean(this.SpeedAboveMax.equal(new BBoolean(false)).booleanValue() && new BBoolean(new BBoolean(this.CruiseActive.equal(new BBoolean(false)).booleanValue() || this.VehicleCanKeepSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue() || new BBoolean(new BBoolean(this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).not().booleanValue()).booleanValue())).booleanValue()) {
            this.SpeedAboveMax = new BBoolean(true);
            this.VehicleAtCruiseSpeed = new BBoolean(false);
        }
    }
    VehicleFallsBelowMaxCruiseSpeed() {
        if ((this.SpeedAboveMax.equal(new BBoolean(true))).booleanValue()) {
            this.SpeedAboveMax = new BBoolean(false);
            if ((new BBoolean(this.CruiseActive.equal(new BBoolean(true)).booleanValue() && this.CruiseSpeedAtMax.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
                this.VehicleAtCruiseSpeed = new BBoolean(true);
            }
        }
    }
    ObstacleDistanceBecomesVeryClose() {
        if ((new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSneg)).booleanValue())).booleanValue()) {
            this.ObstacleDistance = new ODset(enum_ODset.ODveryclose);
            this.ObstacleStatusJustChanged = new BBoolean(true);
        }
    }
    ObstacleDistanceBecomesClose() {
        if ((new BBoolean(new BBoolean(this.ObstaclePresent.equal(new BBoolean(true)).booleanValue() && this.CruiseActive.equal(new BBoolean(true)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODveryclose)).booleanValue() && this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue()).booleanValue() || new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue() && this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSneg)).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
            this.ObstacleDistance = new ODset(enum_ODset.ODclose);
            this.ObstacleStatusJustChanged = new BBoolean(true);
            if ((this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos))).booleanValue()) {
                this.VehicleTryKeepTimeGap = new BBoolean(false);
            }
        }
    }
    ObstacleDistanceBecomesBig() {
        if ((new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue())).booleanValue()) {
            this.ObstacleStatusJustChanged = new BBoolean(true);
            this.ObstacleDistance = new ODset(enum_ODset.ODnone);
            this.VehicleTryKeepTimeGap = new BBoolean(false);
        }
    }
    ObstacleStartsTravelFaster() {
        if ((new BBoolean(this.ObstaclePresent.equal(new BBoolean(true)).booleanValue() && this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSequal)).booleanValue())).booleanValue()) {
            this.ObstacleRelativeSpeed = new RSset(enum_RSset.RSpos);
            if ((this.CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                this.ObstacleStatusJustChanged = new BBoolean(true);
            }
            if ((this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose))).booleanValue()) {
                this.VehicleTryKeepTimeGap = new BBoolean(false);
            }
        }
    }
    ObstacleStopsTravelFaster() {
        if ((this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos))).booleanValue()) {
            this.ObstacleRelativeSpeed = new RSset(enum_RSset.RSequal);
            if ((this.CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                this.ObstacleStatusJustChanged = new BBoolean(true);
            }
        }
    }
    ObstacleStartsTravelSlower() {
        if ((this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSequal))).booleanValue()) {
            this.ObstacleRelativeSpeed = new RSset(enum_RSset.RSneg);
            if ((this.CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                this.ObstacleStatusJustChanged = new BBoolean(true);
            }
        }
    }
    ObstacleStopsTravelSlower() {
        if ((this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSneg))).booleanValue()) {
            this.ObstacleRelativeSpeed = new RSset(enum_RSset.RSequal);
            if ((this.CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                this.ObstacleStatusJustChanged = new BBoolean(true);
            }
        }
    }
    ObstacleAppearsWhenCruiseActive(ors, od) {
        if ((new BBoolean(this.ObstaclePresent.equal(new BBoolean(false)).booleanValue() && this.CruiseActive.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.ObstaclePresent = new BBoolean(true);
            this.ObstacleStatusJustChanged = new BBoolean(true);
            this.ObstacleRelativeSpeed = ors;
            this.ObstacleDistance = od;
        }
    }
    ObstacleAppearsWhenCruiseInactive(ors) {
        if ((new BBoolean(this.ObstaclePresent.equal(new BBoolean(false)).booleanValue() && this.CruiseActive.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
            this.ObstaclePresent = new BBoolean(true);
            this.ObstacleRelativeSpeed = ors;
            this.ObstacleDistance = new ODset(enum_ODset.ODnone);
        }
    }
    ObstacleDisappears() {
        if ((this.ObstaclePresent.equal(new BBoolean(true))).booleanValue()) {
            this.ObstaclePresent = new BBoolean(false);
            this.ObstacleRelativeSpeed = new RSset(enum_RSset.RSnone);
            if ((this.CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                this.ObstacleStatusJustChanged = new BBoolean(true);
            }
            this.ObstacleDistance = new ODset(enum_ODset.ODnone);
            this.VehicleTryKeepTimeGap = new BBoolean(false);
        }
    }
    VehicleManageObstacle(vtks, vtktg) {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(BUtils.BOOL.elementOf(vtks).booleanValue() && BUtils.BOOL.elementOf(vtktg).booleanValue()).booleanValue() && new BBoolean(new BBoolean(new BBoolean(vtks.equal(new BBoolean(true)).booleanValue() || vtktg.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!this.ObstaclePresent.equal(new BBoolean(false)).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue() || vtks.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.unequal(new RSset(enum_RSset.RSpos)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODveryclose)).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || vtks.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSequal)).booleanValue() && this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSneg)).booleanValue() && this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue())).booleanValue()) {
            if ((this.ObstacleStatusJustChanged.equal(new BBoolean(true))).booleanValue()) {
                this.VehicleTryKeepTimeGap = vtktg;
                this.VehicleTryKeepSpeed = vtks;
            }
        }
    }
    ObstacleBecomesOld() {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.unequal(new RSset(enum_RSset.RSpos)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODveryclose)).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue())).booleanValue()) {
            this.ObstacleStatusJustChanged = new BBoolean(false);
        }
    }
    _get_CruiseAllowed() {
        return this.CruiseAllowed;
    }
    _get_CruiseActive() {
        return this.CruiseActive;
    }
    _get_VehicleAtCruiseSpeed() {
        return this.VehicleAtCruiseSpeed;
    }
    _get_VehicleCanKeepSpeed() {
        return this.VehicleCanKeepSpeed;
    }
    _get_VehicleTryKeepSpeed() {
        return this.VehicleTryKeepSpeed;
    }
    _get_SpeedAboveMax() {
        return this.SpeedAboveMax;
    }
    _get_VehicleTryKeepTimeGap() {
        return this.VehicleTryKeepTimeGap;
    }
    _get_CruiseSpeedAtMax() {
        return this.CruiseSpeedAtMax;
    }
    _get_ObstaclePresent() {
        return this.ObstaclePresent;
    }
    _get_ObstacleDistance() {
        return this.ObstacleDistance;
    }
    _get_ObstacleRelativeSpeed() {
        return this.ObstacleRelativeSpeed;
    }
    _get_ObstacleStatusJustChanged() {
        return this.ObstacleStatusJustChanged;
    }
    _get_CCInitialisationInProgress() {
        return this.CCInitialisationInProgress;
    }
    _get_CruiseSpeedChangeInProgress() {
        return this.CruiseSpeedChangeInProgress;
    }
    _get_NumberOfSetCruise() {
        return this.NumberOfSetCruise;
    }
    _get__RSset() {
        return Cruise_finite1_deterministic._RSset;
    }
    _get__ODset() {
        return Cruise_finite1_deterministic._ODset;
    }
}
Cruise_finite1_deterministic._RSset = new BSet(new RSset(enum_RSset.RSnone), new RSset(enum_RSset.RSpos), new RSset(enum_RSset.RSneg), new RSset(enum_RSset.RSequal));
Cruise_finite1_deterministic._ODset = new BSet(new ODset(enum_ODset.ODnone), new ODset(enum_ODset.ODclose), new ODset(enum_ODset.ODveryclose));
