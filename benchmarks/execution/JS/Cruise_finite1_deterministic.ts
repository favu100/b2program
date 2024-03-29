import {BInteger} from './btypes/BInteger.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";

export enum enum_RSset {
    RSnone,
    RSpos,
    RSneg,
    RSequal
}

export class RSset implements BObject{
    value: enum_RSset;

    constructor(value: enum_RSset) {
        this.value = value;
    }

    equal(other: RSset) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: RSset) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof RSset)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_RSset[this.value].toString();
    }

    static get_RSnone () {return new RSset(enum_RSset.RSnone);}
    static get_RSpos () {return new RSset(enum_RSset.RSpos);}
    static get_RSneg () {return new RSset(enum_RSset.RSneg);}
    static get_RSequal () {return new RSset(enum_RSset.RSequal);}


}

export enum enum_ODset {
    ODnone,
    ODclose,
    ODveryclose
}

export class ODset implements BObject{
    value: enum_ODset;

    constructor(value: enum_ODset) {
        this.value = value;
    }

    equal(other: ODset) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: ODset) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof ODset)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_ODset[this.value].toString();
    }

    static get_ODnone () {return new ODset(enum_ODset.ODnone);}
    static get_ODclose () {return new ODset(enum_ODset.ODclose);}
    static get_ODveryclose () {return new ODset(enum_ODset.ODveryclose);}


}


export default class Cruise_finite1_deterministic {



    private static _RSset: BSet<RSset> = new BSet<RSset>(new RSset(enum_RSset.RSnone), new RSset(enum_RSset.RSpos), new RSset(enum_RSset.RSneg), new RSset(enum_RSset.RSequal));
    private static _ODset: BSet<ODset> = new BSet<ODset>(new ODset(enum_ODset.ODnone), new ODset(enum_ODset.ODclose), new ODset(enum_ODset.ODveryclose));

    private CruiseAllowed: BBoolean;
    private CruiseActive: BBoolean;
    private VehicleAtCruiseSpeed: BBoolean;
    private VehicleCanKeepSpeed: BBoolean;
    private VehicleTryKeepSpeed: BBoolean;
    private SpeedAboveMax: BBoolean;
    private VehicleTryKeepTimeGap: BBoolean;
    private CruiseSpeedAtMax: BBoolean;
    private ObstaclePresent: BBoolean;
    private ObstacleDistance: ODset;
    private ObstacleRelativeSpeed: RSset;
    private ObstacleStatusJustChanged: BBoolean;
    private CCInitialisationInProgress: BBoolean;
    private CruiseSpeedChangeInProgress: BBoolean;
    private NumberOfSetCruise: BInteger;

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


     CruiseBecomesNotAllowed(): void {
        if((this.CruiseAllowed.equal(new BBoolean(true))).booleanValue()) {
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
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     CruiseBecomesAllowed(): void {
        if((this.CruiseAllowed.equal(new BBoolean(false))).booleanValue()) {
            this.CruiseAllowed = new BBoolean(true);
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     SetCruiseSpeed(vcks: BBoolean, csam: BBoolean): void {
        if((this.CruiseAllowed.equal(new BBoolean(true))).booleanValue()) {
            let _ld_CruiseActive: BBoolean = this.CruiseActive;
            let _ld_NumberOfSetCruise: BInteger = this.NumberOfSetCruise;
            this.CruiseActive = new BBoolean(true);
            this.VehicleCanKeepSpeed = vcks;
            if((this.SpeedAboveMax.equal(new BBoolean(false))).booleanValue()) {
                this.VehicleAtCruiseSpeed = new BBoolean(true);
                this.CruiseSpeedAtMax = csam;
            } else {
                this.CruiseSpeedAtMax = new BBoolean(true);
            }
            this.ObstacleStatusJustChanged = new BBoolean(true);
            if((_ld_CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                this.CruiseSpeedChangeInProgress = new BBoolean(true);
            } else {
                this.CCInitialisationInProgress = new BBoolean(true);
            }
            if((_ld_NumberOfSetCruise.less(new BInteger(1))).booleanValue()) {
                this.NumberOfSetCruise = _ld_NumberOfSetCruise.plus(new BInteger(1));
            } 
        } else {
            throw new SelectError("Parameters are invalid!");
        }

    }

     CCInitialisationFinished(vtks: BBoolean, vtktg: BBoolean): void {
        if((this.CCInitialisationInProgress.equal(new BBoolean(true))).booleanValue()) {
            this.VehicleTryKeepTimeGap = vtktg;
            this.VehicleTryKeepSpeed = vtks;
        } else {
            throw new SelectError("Parameters are invalid!");
        }

    }

     CCInitialisationDelayFinished(): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.unequal(new RSset(enum_RSset.RSpos)).booleanValue()).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODveryclose)).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue())).booleanValue()) {
            this.CCInitialisationInProgress = new BBoolean(true);
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     CruiseSpeedChangeFinished(vtks: BBoolean, vtktg: BBoolean): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(BUtils.BOOL.elementOf(vtks).booleanValue() && BUtils.BOOL.elementOf(vtktg).booleanValue()).booleanValue() && new BBoolean(new BBoolean(new BBoolean(vtks.equal(new BBoolean(true)).booleanValue() || vtktg.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!this.ObstaclePresent.equal(new BBoolean(false)).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue() || vtks.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.unequal(new RSset(enum_RSset.RSpos)).booleanValue()).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODveryclose)).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || vtks.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSequal)).booleanValue() && this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSneg)).booleanValue() && this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue())).booleanValue()) {
            if((this.CruiseSpeedChangeInProgress.equal(new BBoolean(true))).booleanValue()) {
                this.VehicleTryKeepTimeGap = vtktg;
                this.VehicleTryKeepSpeed = vtks;
            } else {
                throw new SelectError("Parameters are invalid!");
            }
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     CruiseSpeedChangeDelayFinished(): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.unequal(new RSset(enum_RSset.RSpos)).booleanValue()).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODveryclose)).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue())).booleanValue()) {
            this.CruiseSpeedChangeInProgress = new BBoolean(true);
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     CruiseOff(): void {
        if((this.CruiseActive.equal(new BBoolean(true))).booleanValue()) {
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
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     ExternalForcesBecomesExtreme(): void {
        if((this.VehicleCanKeepSpeed.equal(new BBoolean(true))).booleanValue()) {
            this.VehicleCanKeepSpeed = new BBoolean(false);
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     ExternalForcesBecomesNormal(): void {
        if((new BBoolean(this.CruiseActive.equal(new BBoolean(true)).booleanValue() && this.VehicleCanKeepSpeed.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
            this.VehicleCanKeepSpeed = new BBoolean(true);
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     VehicleLeavesCruiseSpeed(): void {
        if((new BBoolean(new BBoolean(this.VehicleAtCruiseSpeed.equal(new BBoolean(true)).booleanValue() && new BBoolean(this.VehicleCanKeepSpeed.equal(new BBoolean(false)).booleanValue() && this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
            this.VehicleAtCruiseSpeed = new BBoolean(false);
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     VehicleReachesCruiseSpeed(): void {
        if((new BBoolean(new BBoolean(this.CruiseActive.equal(new BBoolean(true)).booleanValue() && this.VehicleAtCruiseSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.SpeedAboveMax.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
            this.VehicleAtCruiseSpeed = new BBoolean(true);
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     VehicleExceedsMaxCruiseSpeed(): void {
        if((new BBoolean(this.SpeedAboveMax.equal(new BBoolean(false)).booleanValue() && new BBoolean(new BBoolean(this.CruiseActive.equal(new BBoolean(false)).booleanValue() || this.VehicleCanKeepSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue() || new BBoolean(new BBoolean(this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).not().booleanValue()).booleanValue())).booleanValue()) {
            this.SpeedAboveMax = new BBoolean(true);
            this.VehicleAtCruiseSpeed = new BBoolean(false);
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     VehicleFallsBelowMaxCruiseSpeed(): void {
        if((this.SpeedAboveMax.equal(new BBoolean(true))).booleanValue()) {
            this.SpeedAboveMax = new BBoolean(false);
            if((new BBoolean(this.CruiseActive.equal(new BBoolean(true)).booleanValue() && this.CruiseSpeedAtMax.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
                this.VehicleAtCruiseSpeed = new BBoolean(true);
            } 
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     ObstacleDistanceBecomesVeryClose(): void {
        if((new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSneg)).booleanValue())).booleanValue()) {
            this.ObstacleDistance = new ODset(enum_ODset.ODveryclose);
            this.ObstacleStatusJustChanged = new BBoolean(true);
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     ObstacleDistanceBecomesClose(): void {
        if((new BBoolean(new BBoolean(this.ObstaclePresent.equal(new BBoolean(true)).booleanValue() && this.CruiseActive.equal(new BBoolean(true)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODveryclose)).booleanValue() && this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue()).booleanValue() || new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue() && this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSneg)).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
            this.ObstacleDistance = new ODset(enum_ODset.ODclose);
            this.ObstacleStatusJustChanged = new BBoolean(true);
            if((this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos))).booleanValue()) {
                this.VehicleTryKeepTimeGap = new BBoolean(false);
            } 
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     ObstacleDistanceBecomesBig(): void {
        if((new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue())).booleanValue()) {
            this.ObstacleStatusJustChanged = new BBoolean(true);
            this.ObstacleDistance = new ODset(enum_ODset.ODnone);
            this.VehicleTryKeepTimeGap = new BBoolean(false);
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     ObstacleStartsTravelFaster(): void {
        if((new BBoolean(this.ObstaclePresent.equal(new BBoolean(true)).booleanValue() && this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSequal)).booleanValue())).booleanValue()) {
            this.ObstacleRelativeSpeed = new RSset(enum_RSset.RSpos);
            if((this.CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                this.ObstacleStatusJustChanged = new BBoolean(true);
            } 
            if((this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose))).booleanValue()) {
                this.VehicleTryKeepTimeGap = new BBoolean(false);
            } 
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     ObstacleStopsTravelFaster(): void {
        if((this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos))).booleanValue()) {
            this.ObstacleRelativeSpeed = new RSset(enum_RSset.RSequal);
            if((this.CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                this.ObstacleStatusJustChanged = new BBoolean(true);
            } 
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     ObstacleStartsTravelSlower(): void {
        if((this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSequal))).booleanValue()) {
            this.ObstacleRelativeSpeed = new RSset(enum_RSset.RSneg);
            if((this.CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                this.ObstacleStatusJustChanged = new BBoolean(true);
            } 
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     ObstacleStopsTravelSlower(): void {
        if((this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSneg))).booleanValue()) {
            this.ObstacleRelativeSpeed = new RSset(enum_RSset.RSequal);
            if((this.CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                this.ObstacleStatusJustChanged = new BBoolean(true);
            } 
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     ObstacleAppearsWhenCruiseActive(ors: RSset, od: ODset): void {
        if((new BBoolean(this.ObstaclePresent.equal(new BBoolean(false)).booleanValue() && this.CruiseActive.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.ObstaclePresent = new BBoolean(true);
            this.ObstacleStatusJustChanged = new BBoolean(true);
            this.ObstacleRelativeSpeed = ors;
            this.ObstacleDistance = od;
        } else {
            throw new SelectError("Parameters are invalid!");
        }

    }

     ObstacleAppearsWhenCruiseInactive(ors: RSset): void {
        if((new BBoolean(this.ObstaclePresent.equal(new BBoolean(false)).booleanValue() && this.CruiseActive.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
            this.ObstaclePresent = new BBoolean(true);
            this.ObstacleRelativeSpeed = ors;
            this.ObstacleDistance = new ODset(enum_ODset.ODnone);
        } else {
            throw new SelectError("Parameters are invalid!");
        }

    }

     ObstacleDisappears(): void {
        if((this.ObstaclePresent.equal(new BBoolean(true))).booleanValue()) {
            this.ObstaclePresent = new BBoolean(false);
            this.ObstacleRelativeSpeed = new RSset(enum_RSset.RSnone);
            if((this.CruiseActive.equal(new BBoolean(true))).booleanValue()) {
                this.ObstacleStatusJustChanged = new BBoolean(true);
            } 
            this.ObstacleDistance = new ODset(enum_ODset.ODnone);
            this.VehicleTryKeepTimeGap = new BBoolean(false);
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     VehicleManageObstacle(vtks: BBoolean, vtktg: BBoolean): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(BUtils.BOOL.elementOf(vtks).booleanValue() && BUtils.BOOL.elementOf(vtktg).booleanValue()).booleanValue() && new BBoolean(new BBoolean(new BBoolean(vtks.equal(new BBoolean(true)).booleanValue() || vtktg.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!this.ObstaclePresent.equal(new BBoolean(false)).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue() || vtks.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.unequal(new RSset(enum_RSset.RSpos)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODveryclose)).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || vtks.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSequal)).booleanValue() && this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSneg)).booleanValue() && this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() || vtktg.equal(new BBoolean(false)).booleanValue()).booleanValue())).booleanValue()) {
            if((this.ObstacleStatusJustChanged.equal(new BBoolean(true))).booleanValue()) {
                this.VehicleTryKeepTimeGap = vtktg;
                this.VehicleTryKeepSpeed = vtks;
            } else {
                throw new SelectError("Parameters are invalid!");
            }
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     ObstacleBecomesOld(): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.unequal(new RSset(enum_RSset.RSpos)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODveryclose)).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue())).booleanValue()) {
            this.ObstacleStatusJustChanged = new BBoolean(false);
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

    _get_CruiseAllowed(): BBoolean {
        return this.CruiseAllowed;
    }

    _get_CruiseActive(): BBoolean {
        return this.CruiseActive;
    }

    _get_VehicleAtCruiseSpeed(): BBoolean {
        return this.VehicleAtCruiseSpeed;
    }

    _get_VehicleCanKeepSpeed(): BBoolean {
        return this.VehicleCanKeepSpeed;
    }

    _get_VehicleTryKeepSpeed(): BBoolean {
        return this.VehicleTryKeepSpeed;
    }

    _get_SpeedAboveMax(): BBoolean {
        return this.SpeedAboveMax;
    }

    _get_VehicleTryKeepTimeGap(): BBoolean {
        return this.VehicleTryKeepTimeGap;
    }

    _get_CruiseSpeedAtMax(): BBoolean {
        return this.CruiseSpeedAtMax;
    }

    _get_ObstaclePresent(): BBoolean {
        return this.ObstaclePresent;
    }

    _get_ObstacleDistance(): ODset {
        return this.ObstacleDistance;
    }

    _get_ObstacleRelativeSpeed(): RSset {
        return this.ObstacleRelativeSpeed;
    }

    _get_ObstacleStatusJustChanged(): BBoolean {
        return this.ObstacleStatusJustChanged;
    }

    _get_CCInitialisationInProgress(): BBoolean {
        return this.CCInitialisationInProgress;
    }

    _get_CruiseSpeedChangeInProgress(): BBoolean {
        return this.CruiseSpeedChangeInProgress;
    }

    _get_NumberOfSetCruise(): BInteger {
        return this.NumberOfSetCruise;
    }

    _get__RSset(): BSet<RSset> {
        return Cruise_finite1_deterministic._RSset;
    }

    _get__ODset(): BSet<ODset> {
        return Cruise_finite1_deterministic._ODset;
    }


}

