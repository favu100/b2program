import {BTuple} from './btypes/BTuple.js';
import {BInteger} from './btypes/BInteger.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";
import * as immutable from "./immutable/dist/immutable.es.js";
import {LinkedList} from  "./modelchecking/LinkedList.js";


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


export enum Type {
    BFS,
    DFS,
    MIXED
}

export default class Cruise_finite1_deterministic_MC {

    parent: Cruise_finite1_deterministic_MC;
    dependentGuard: immutable.Set<string> = immutable.Set();
    guardCache: immutable.Map = immutable.Map();
    dependentInvariant: immutable.Set<string> = immutable.Set();
    stateAccessedVia: string;



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

    constructor(copy? : Cruise_finite1_deterministic_MC) {
        if(copy) {
            this.CruiseAllowed = copy.CruiseAllowed;
            this.CruiseActive = copy.CruiseActive;
            this.VehicleAtCruiseSpeed = copy.VehicleAtCruiseSpeed;
            this.VehicleCanKeepSpeed = copy.VehicleCanKeepSpeed;
            this.VehicleTryKeepSpeed = copy.VehicleTryKeepSpeed;
            this.SpeedAboveMax = copy.SpeedAboveMax;
            this.VehicleTryKeepTimeGap = copy.VehicleTryKeepTimeGap;
            this.CruiseSpeedAtMax = copy.CruiseSpeedAtMax;
            this.ObstaclePresent = copy.ObstaclePresent;
            this.ObstacleDistance = copy.ObstacleDistance;
            this.ObstacleRelativeSpeed = copy.ObstacleRelativeSpeed;
            this.ObstacleStatusJustChanged = copy.ObstacleStatusJustChanged;
            this.CCInitialisationInProgress = copy.CCInitialisationInProgress;
            this.CruiseSpeedChangeInProgress = copy.CruiseSpeedChangeInProgress;
            this.NumberOfSetCruise = copy.NumberOfSetCruise;
        } else {
            this.CruiseAllowed = new BBoolean(true);
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
    }



    CruiseBecomesNotAllowed(): void {
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

    CruiseBecomesAllowed(): void {
        this.CruiseAllowed = new BBoolean(true);

    }

    SetCruiseSpeed(vcks: BBoolean, csam: BBoolean): void {
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

    }

    CCInitialisationFinished(vtks: BBoolean, vtktg: BBoolean): void {
        this.VehicleTryKeepTimeGap = vtktg;
        this.VehicleTryKeepSpeed = vtks;

    }

    CCInitialisationDelayFinished(): void {
        this.CCInitialisationInProgress = new BBoolean(true);

    }

    CruiseSpeedChangeFinished(vtks: BBoolean, vtktg: BBoolean): void {
        this.VehicleTryKeepTimeGap = vtktg;
        this.VehicleTryKeepSpeed = vtks;

    }

    CruiseSpeedChangeDelayFinished(): void {
        this.CruiseSpeedChangeInProgress = new BBoolean(true);

    }

    CruiseOff(): void {
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

    ExternalForcesBecomesExtreme(): void {
        this.VehicleCanKeepSpeed = new BBoolean(false);

    }

    ExternalForcesBecomesNormal(): void {
        this.VehicleCanKeepSpeed = new BBoolean(true);

    }

    VehicleLeavesCruiseSpeed(): void {
        this.VehicleAtCruiseSpeed = new BBoolean(false);

    }

    VehicleReachesCruiseSpeed(): void {
        this.VehicleAtCruiseSpeed = new BBoolean(true);

    }

    VehicleExceedsMaxCruiseSpeed(): void {
        this.SpeedAboveMax = new BBoolean(true);
        this.VehicleAtCruiseSpeed = new BBoolean(false);

    }

    VehicleFallsBelowMaxCruiseSpeed(): void {
        this.SpeedAboveMax = new BBoolean(false);
        if((new BBoolean(this.CruiseActive.equal(new BBoolean(true)).booleanValue() && this.CruiseSpeedAtMax.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.VehicleAtCruiseSpeed = new BBoolean(true);
        } 

    }

    ObstacleDistanceBecomesVeryClose(): void {
        this.ObstacleDistance = new ODset(enum_ODset.ODveryclose);
        this.ObstacleStatusJustChanged = new BBoolean(true);

    }

    ObstacleDistanceBecomesClose(): void {
        this.ObstacleDistance = new ODset(enum_ODset.ODclose);
        this.ObstacleStatusJustChanged = new BBoolean(true);
        if((this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos))).booleanValue()) {
            this.VehicleTryKeepTimeGap = new BBoolean(false);
        } 

    }

    ObstacleDistanceBecomesBig(): void {
        this.ObstacleStatusJustChanged = new BBoolean(true);
        this.ObstacleDistance = new ODset(enum_ODset.ODnone);
        this.VehicleTryKeepTimeGap = new BBoolean(false);

    }

    ObstacleStartsTravelFaster(): void {
        this.ObstacleRelativeSpeed = new RSset(enum_RSset.RSpos);
        if((this.CruiseActive.equal(new BBoolean(true))).booleanValue()) {
            this.ObstacleStatusJustChanged = new BBoolean(true);
        } 
        if((this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose))).booleanValue()) {
            this.VehicleTryKeepTimeGap = new BBoolean(false);
        } 

    }

    ObstacleStopsTravelFaster(): void {
        this.ObstacleRelativeSpeed = new RSset(enum_RSset.RSequal);
        if((this.CruiseActive.equal(new BBoolean(true))).booleanValue()) {
            this.ObstacleStatusJustChanged = new BBoolean(true);
        } 

    }

    ObstacleStartsTravelSlower(): void {
        this.ObstacleRelativeSpeed = new RSset(enum_RSset.RSneg);
        if((this.CruiseActive.equal(new BBoolean(true))).booleanValue()) {
            this.ObstacleStatusJustChanged = new BBoolean(true);
        } 

    }

    ObstacleStopsTravelSlower(): void {
        this.ObstacleRelativeSpeed = new RSset(enum_RSset.RSequal);
        if((this.CruiseActive.equal(new BBoolean(true))).booleanValue()) {
            this.ObstacleStatusJustChanged = new BBoolean(true);
        } 

    }

    ObstacleAppearsWhenCruiseActive(ors: RSset, od: ODset): void {
        this.ObstaclePresent = new BBoolean(true);
        this.ObstacleStatusJustChanged = new BBoolean(true);
        this.ObstacleRelativeSpeed = ors;
        this.ObstacleDistance = od;

    }

    ObstacleAppearsWhenCruiseInactive(ors: RSset): void {
        this.ObstaclePresent = new BBoolean(true);
        this.ObstacleRelativeSpeed = ors;
        this.ObstacleDistance = new ODset(enum_ODset.ODnone);

    }

    ObstacleDisappears(): void {
        this.ObstaclePresent = new BBoolean(false);
        this.ObstacleRelativeSpeed = new RSset(enum_RSset.RSnone);
        if((this.CruiseActive.equal(new BBoolean(true))).booleanValue()) {
            this.ObstacleStatusJustChanged = new BBoolean(true);
        } 
        this.ObstacleDistance = new ODset(enum_ODset.ODnone);
        this.VehicleTryKeepTimeGap = new BBoolean(false);

    }

    VehicleManageObstacle(vtks: BBoolean, vtktg: BBoolean): void {
        this.VehicleTryKeepTimeGap = vtktg;
        this.VehicleTryKeepSpeed = vtks;

    }

    ObstacleBecomesOld(): void {
        this.ObstacleStatusJustChanged = new BBoolean(false);

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
        return Cruise_finite1_deterministic_MC._RSset;
    }

    _get__ODset(): BSet<ODset> {
        return Cruise_finite1_deterministic_MC._ODset;
    }

    _tr_CruiseBecomesNotAllowed(): boolean {
        return this.CruiseAllowed.equal(new BBoolean(true)).booleanValue();
    }

    _tr_CruiseBecomesAllowed(): boolean {
        return this.CruiseAllowed.equal(new BBoolean(false)).booleanValue();
    }

    _tr_SetCruiseSpeed(): BSet<BTuple<BBoolean, BBoolean>> {
        let _ic_set_2: BSet<BTuple<BBoolean, BBoolean>> = new BSet<BTuple<BBoolean, BBoolean>>();
        for(let _ic_vcks_1 of BUtils.BOOL) {
            for(let _ic_csam_1 of BUtils.BOOL) {
                if((this.CruiseAllowed.equal(new BBoolean(true))).booleanValue()) {
                    _ic_set_2 = _ic_set_2.union(new BSet<BTuple<BBoolean, BBoolean>>(new BTuple(_ic_vcks_1, _ic_csam_1)));
                }

            }
        }
        return _ic_set_2;
    }

    _tr_CCInitialisationFinished(): BSet<BTuple<BBoolean, BBoolean>> {
        let _ic_set_3: BSet<BTuple<BBoolean, BBoolean>> = new BSet<BTuple<BBoolean, BBoolean>>();
        for(let _ic_vtks_1 of BUtils.BOOL) {
            for(let _ic_vtktg_1 of BUtils.BOOL) {
                if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(_ic_vtks_1.equal(new BBoolean(true)).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue() && new BBoolean(!this.ObstaclePresent.equal(new BBoolean(false)).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue() || _ic_vtks_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.unequal(new RSset(enum_RSset.RSpos)).booleanValue()).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODveryclose)).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtks_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSequal)).booleanValue() && this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSneg)).booleanValue() && this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
                    _ic_set_3 = _ic_set_3.union(new BSet<BTuple<BBoolean, BBoolean>>(new BTuple(_ic_vtks_1, _ic_vtktg_1)));
                }

            }
        }
        return _ic_set_3;
    }

    _tr_CCInitialisationDelayFinished(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.unequal(new RSset(enum_RSset.RSpos)).booleanValue()).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODveryclose)).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue();
    }

    _tr_CruiseSpeedChangeFinished(): BSet<BTuple<BBoolean, BBoolean>> {
        let _ic_set_5: BSet<BTuple<BBoolean, BBoolean>> = new BSet<BTuple<BBoolean, BBoolean>>();
        for(let _ic_vtks_1 of BUtils.BOOL) {
            for(let _ic_vtktg_1 of BUtils.BOOL) {
                if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(_ic_vtks_1.equal(new BBoolean(true)).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue() && new BBoolean(!this.ObstaclePresent.equal(new BBoolean(false)).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue() || _ic_vtks_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.unequal(new RSset(enum_RSset.RSpos)).booleanValue()).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODveryclose)).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtks_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSequal)).booleanValue() && this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSneg)).booleanValue() && this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
                    _ic_set_5 = _ic_set_5.union(new BSet<BTuple<BBoolean, BBoolean>>(new BTuple(_ic_vtks_1, _ic_vtktg_1)));
                }

            }
        }
        return _ic_set_5;
    }

    _tr_CruiseSpeedChangeDelayFinished(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.unequal(new RSset(enum_RSset.RSpos)).booleanValue()).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODveryclose)).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue();
    }

    _tr_CruiseOff(): boolean {
        return this.CruiseActive.equal(new BBoolean(true)).booleanValue();
    }

    _tr_ExternalForcesBecomesExtreme(): boolean {
        return this.VehicleCanKeepSpeed.equal(new BBoolean(true)).booleanValue();
    }

    _tr_ExternalForcesBecomesNormal(): boolean {
        return new BBoolean(this.CruiseActive.equal(new BBoolean(true)).booleanValue() && this.VehicleCanKeepSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _tr_VehicleLeavesCruiseSpeed(): boolean {
        return new BBoolean(new BBoolean(this.VehicleAtCruiseSpeed.equal(new BBoolean(true)).booleanValue() && new BBoolean(this.VehicleCanKeepSpeed.equal(new BBoolean(false)).booleanValue() && this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _tr_VehicleReachesCruiseSpeed(): boolean {
        return new BBoolean(new BBoolean(this.CruiseActive.equal(new BBoolean(true)).booleanValue() && this.VehicleAtCruiseSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.SpeedAboveMax.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _tr_VehicleExceedsMaxCruiseSpeed(): boolean {
        return new BBoolean(this.SpeedAboveMax.equal(new BBoolean(false)).booleanValue() && new BBoolean(new BBoolean(this.CruiseActive.equal(new BBoolean(false)).booleanValue() || this.VehicleCanKeepSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue() || new BBoolean(new BBoolean(this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue()).booleanValue();
    }

    _tr_VehicleFallsBelowMaxCruiseSpeed(): boolean {
        return this.SpeedAboveMax.equal(new BBoolean(true)).booleanValue();
    }

    _tr_ObstacleDistanceBecomesVeryClose(): boolean {
        return new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSneg)).booleanValue()).booleanValue();
    }

    _tr_ObstacleDistanceBecomesClose(): boolean {
        return new BBoolean(new BBoolean(this.ObstaclePresent.equal(new BBoolean(true)).booleanValue() && this.CruiseActive.equal(new BBoolean(true)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODveryclose)).booleanValue() && this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue()).booleanValue() || new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue() && this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSneg)).booleanValue()).booleanValue()).booleanValue()).booleanValue();
    }

    _tr_ObstacleDistanceBecomesBig(): boolean {
        return new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue()).booleanValue();
    }

    _tr_ObstacleStartsTravelFaster(): boolean {
        return new BBoolean(this.ObstaclePresent.equal(new BBoolean(true)).booleanValue() && this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSequal)).booleanValue()).booleanValue();
    }

    _tr_ObstacleStopsTravelFaster(): boolean {
        return this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue();
    }

    _tr_ObstacleStartsTravelSlower(): boolean {
        return this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSequal)).booleanValue();
    }

    _tr_ObstacleStopsTravelSlower(): boolean {
        return this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSneg)).booleanValue();
    }

    _tr_ObstacleAppearsWhenCruiseActive(): BSet<BTuple<RSset, ODset>> {
        let _ic_set_21: BSet<BTuple<RSset, ODset>> = new BSet<BTuple<RSset, ODset>>();
        for(let _ic_ors_1 of Cruise_finite1_deterministic_MC._RSset.difference(new BSet<RSset>(new RSset(enum_RSset.RSnone)))) {
            for(let _ic_od_1 of Cruise_finite1_deterministic_MC._ODset.difference(new BSet<ODset>(new ODset(enum_ODset.ODnone)))) {
                if((new BBoolean(this.ObstaclePresent.equal(new BBoolean(false)).booleanValue() && this.CruiseActive.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
                    _ic_set_21 = _ic_set_21.union(new BSet<BTuple<RSset, ODset>>(new BTuple(_ic_ors_1, _ic_od_1)));
                }

            }
        }
        return _ic_set_21;
    }

    _tr_ObstacleAppearsWhenCruiseInactive(): BSet<RSset> {
        let _ic_set_22: BSet<RSset> = new BSet<RSset>();
        for(let _ic_ors_1 of Cruise_finite1_deterministic_MC._RSset.difference(new BSet<RSset>(new RSset(enum_RSset.RSnone)))) {
            if((new BBoolean(this.ObstaclePresent.equal(new BBoolean(false)).booleanValue() && this.CruiseActive.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
                _ic_set_22 = _ic_set_22.union(new BSet<RSset>(_ic_ors_1));
            }

        }
        return _ic_set_22;
    }

    _tr_ObstacleDisappears(): boolean {
        return this.ObstaclePresent.equal(new BBoolean(true)).booleanValue();
    }

    _tr_VehicleManageObstacle(): BSet<BTuple<BBoolean, BBoolean>> {
        let _ic_set_24: BSet<BTuple<BBoolean, BBoolean>> = new BSet<BTuple<BBoolean, BBoolean>>();
        for(let _ic_vtks_1 of BUtils.BOOL) {
            for(let _ic_vtktg_1 of BUtils.BOOL) {
                if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(_ic_vtks_1.equal(new BBoolean(true)).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue() && new BBoolean(!this.ObstaclePresent.equal(new BBoolean(false)).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue() || _ic_vtks_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.unequal(new RSset(enum_RSset.RSpos)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODveryclose)).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtks_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSequal)).booleanValue() && this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSneg)).booleanValue() && this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && this.ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
                    _ic_set_24 = _ic_set_24.union(new BSet<BTuple<BBoolean, BBoolean>>(new BTuple(_ic_vtks_1, _ic_vtktg_1)));
                }

            }
        }
        return _ic_set_24;
    }

    _tr_ObstacleBecomesOld(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.unequal(new RSset(enum_RSset.RSpos)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODveryclose)).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue();
    }

    _check_inv_1() {
        return BUtils.BOOL.elementOf(this.CruiseAllowed).booleanValue();
    }

    _check_inv_2() {
        return BUtils.BOOL.elementOf(this.CruiseActive).booleanValue();
    }

    _check_inv_3() {
        return BUtils.BOOL.elementOf(this.VehicleAtCruiseSpeed).booleanValue();
    }

    _check_inv_4() {
        return BUtils.BOOL.elementOf(this.VehicleCanKeepSpeed).booleanValue();
    }

    _check_inv_5() {
        return BUtils.BOOL.elementOf(this.VehicleTryKeepSpeed).booleanValue();
    }

    _check_inv_6() {
        return BUtils.BOOL.elementOf(this.SpeedAboveMax).booleanValue();
    }

    _check_inv_7() {
        return BUtils.BOOL.elementOf(this.VehicleTryKeepTimeGap).booleanValue();
    }

    _check_inv_8() {
        return BUtils.BOOL.elementOf(this.CruiseSpeedAtMax).booleanValue();
    }

    _check_inv_9() {
        return this.NumberOfSetCruise.isNatural().booleanValue();
    }

    _check_inv_10() {
        return new BBoolean(this.NumberOfSetCruise.greaterEqual(new BInteger(0)).booleanValue() && this.NumberOfSetCruise.lessEqual(new BInteger(1)).booleanValue()).booleanValue();
    }

    _check_inv_11() {
        return BUtils.BOOL.elementOf(this.ObstaclePresent).booleanValue();
    }

    _check_inv_12() {
        return Cruise_finite1_deterministic_MC._ODset.elementOf(this.ObstacleDistance).booleanValue();
    }

    _check_inv_13() {
        return Cruise_finite1_deterministic_MC._RSset.elementOf(this.ObstacleRelativeSpeed).booleanValue();
    }

    _check_inv_14() {
        return BUtils.BOOL.elementOf(this.ObstacleStatusJustChanged).booleanValue();
    }

    _check_inv_15() {
        return BUtils.BOOL.elementOf(this.CCInitialisationInProgress).booleanValue();
    }

    _check_inv_16() {
        return BUtils.BOOL.elementOf(this.CruiseSpeedChangeInProgress).booleanValue();
    }

    _check_inv_17() {
        return new BBoolean(!this.CruiseActive.equal(new BBoolean(false)).booleanValue() || this.VehicleAtCruiseSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _check_inv_18() {
        return new BBoolean(!this.CruiseActive.equal(new BBoolean(false)).booleanValue() || this.VehicleCanKeepSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _check_inv_19() {
        return new BBoolean(!this.CruiseActive.equal(new BBoolean(false)).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _check_inv_20() {
        return new BBoolean((!this.NumberOfSetCruise.equal(new BInteger(0)).booleanValue() || this.CruiseActive.equal(new BBoolean(false)).booleanValue()) && (!this.CruiseActive.equal(new BBoolean(false)).booleanValue() || this.NumberOfSetCruise.equal(new BInteger(0)).booleanValue())).booleanValue();
    }

    _check_inv_21() {
        return new BBoolean(!this.CruiseActive.equal(new BBoolean(false)).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _check_inv_22() {
        return new BBoolean(!this.CruiseActive.equal(new BBoolean(false)).booleanValue() || this.CruiseSpeedAtMax.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _check_inv_23() {
        return new BBoolean(!this.CruiseActive.equal(new BBoolean(false)).booleanValue() || this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue()).booleanValue();
    }

    _check_inv_24() {
        return new BBoolean(!this.CruiseActive.equal(new BBoolean(false)).booleanValue() || this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _check_inv_25() {
        return new BBoolean(!this.CruiseActive.equal(new BBoolean(false)).booleanValue() || this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _check_inv_26() {
        return new BBoolean(!this.CruiseActive.equal(new BBoolean(false)).booleanValue() || this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _check_inv_27() {
        return new BBoolean(!this.ObstaclePresent.equal(new BBoolean(false)).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _check_inv_28() {
        return new BBoolean(!this.ObstaclePresent.equal(new BBoolean(false)).booleanValue() || this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue()).booleanValue();
    }

    _check_inv_29() {
        return new BBoolean((!this.ObstaclePresent.equal(new BBoolean(false)).booleanValue() || this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSnone)).booleanValue()) && (!this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSnone)).booleanValue() || this.ObstaclePresent.equal(new BBoolean(false)).booleanValue())).booleanValue();
    }

    _check_inv_30() {
        return new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSequal)).booleanValue() && this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _check_inv_31() {
        return new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSneg)).booleanValue() && this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _check_inv_32() {
        return new BBoolean(!new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _check_inv_33() {
        return new BBoolean(!this.CruiseAllowed.equal(new BBoolean(false)).booleanValue() || this.CruiseActive.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _check_inv_34() {
        return new BBoolean(!this.SpeedAboveMax.equal(new BBoolean(true)).booleanValue() || this.VehicleAtCruiseSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _check_inv_35() {
        return new BBoolean(!this.CruiseActive.equal(new BBoolean(true)).booleanValue() || new BBoolean(new BBoolean(this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue() || new BBoolean(new BBoolean(this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).not().booleanValue()).booleanValue()).booleanValue();
    }

    _check_inv_36() {
        return new BBoolean(!new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODnone)).booleanValue() && this.CruiseActive.equal(new BBoolean(true)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _check_inv_37() {
        return new BBoolean(!new BBoolean(new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODclose)).booleanValue() && this.ObstacleRelativeSpeed.unequal(new RSset(enum_RSset.RSpos)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _check_inv_38() {
        return new BBoolean(!new BBoolean(this.ObstacleDistance.equal(new ODset(enum_ODset.ODveryclose)).booleanValue() && new BBoolean(new BBoolean(this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() || this.VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _check_inv_39() {
        return new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.ObstacleRelativeSpeed.equal(new RSset(enum_RSset.RSpos)).booleanValue() && this.ObstacleDistance.unequal(new ODset(enum_ODset.ODveryclose)).booleanValue()).booleanValue() && this.CruiseActive.equal(new BBoolean(true)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue() && this.CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() || this.VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    equals(o: any): boolean {
        let o1: Cruise_finite1_deterministic_MC = this;
        let o2: Cruise_finite1_deterministic_MC = o as Cruise_finite1_deterministic_MC;
        return o1._get_CruiseAllowed().equals(o2._get_CruiseAllowed()) && o1._get_CruiseActive().equals(o2._get_CruiseActive()) && o1._get_VehicleAtCruiseSpeed().equals(o2._get_VehicleAtCruiseSpeed()) && o1._get_VehicleCanKeepSpeed().equals(o2._get_VehicleCanKeepSpeed()) && o1._get_VehicleTryKeepSpeed().equals(o2._get_VehicleTryKeepSpeed()) && o1._get_SpeedAboveMax().equals(o2._get_SpeedAboveMax()) && o1._get_VehicleTryKeepTimeGap().equals(o2._get_VehicleTryKeepTimeGap()) && o1._get_CruiseSpeedAtMax().equals(o2._get_CruiseSpeedAtMax()) && o1._get_ObstaclePresent().equals(o2._get_ObstaclePresent()) && o1._get_ObstacleDistance().equals(o2._get_ObstacleDistance()) && o1._get_ObstacleRelativeSpeed().equals(o2._get_ObstacleRelativeSpeed()) && o1._get_ObstacleStatusJustChanged().equals(o2._get_ObstacleStatusJustChanged()) && o1._get_CCInitialisationInProgress().equals(o2._get_CCInitialisationInProgress()) && o1._get_CruiseSpeedChangeInProgress().equals(o2._get_CruiseSpeedChangeInProgress()) && o1._get_NumberOfSetCruise().equals(o2._get_NumberOfSetCruise());
    }



    hashCode(): number {
        return this._hashCode_1();
    }

    _hashCode_1(): number {
        let result: number = 1;
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

    _hashCode_2(): number {
        let result: number = 1;
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

    /* TODO
    toString(): string {
        return String.join("\n", "_get_CruiseAllowed: " + (this._get_CruiseAllowed()).toString(), "_get_CruiseActive: " + (this._get_CruiseActive()).toString(), "_get_VehicleAtCruiseSpeed: " + (this._get_VehicleAtCruiseSpeed()).toString(), "_get_VehicleCanKeepSpeed: " + (this._get_VehicleCanKeepSpeed()).toString(), "_get_VehicleTryKeepSpeed: " + (this._get_VehicleTryKeepSpeed()).toString(), "_get_SpeedAboveMax: " + (this._get_SpeedAboveMax()).toString(), "_get_VehicleTryKeepTimeGap: " + (this._get_VehicleTryKeepTimeGap()).toString(), "_get_CruiseSpeedAtMax: " + (this._get_CruiseSpeedAtMax()).toString(), "_get_ObstaclePresent: " + (this._get_ObstaclePresent()).toString(), "_get_ObstacleDistance: " + (this._get_ObstacleDistance()).toString(), "_get_ObstacleRelativeSpeed: " + (this._get_ObstacleRelativeSpeed()).toString(), "_get_ObstacleStatusJustChanged: " + (this._get_ObstacleStatusJustChanged()).toString(), "_get_CCInitialisationInProgress: " + (this._get_CCInitialisationInProgress()).toString(), "_get_CruiseSpeedChangeInProgress: " + (this._get_CruiseSpeedChangeInProgress()).toString(), "_get_NumberOfSetCruise: " + (this._get_NumberOfSetCruise()).toString());
    }
    */


    public _copy(): Cruise_finite1_deterministic_MC {
      return new Cruise_finite1_deterministic_MC(this);
    }


}


export class ModelChecker {
    private type: Type;
    private isCaching: boolean;
    private isDebug: boolean;

    private unvisitedStates: LinkedList<Cruise_finite1_deterministic_MC> = new LinkedList<Cruise_finite1_deterministic_MC>;
    private states: immutable.Set<Cruise_finite1_deterministic_MC> = new immutable.Set();
    private transitions: number = 0;

    private invariantViolated: boolean = false;
    private deadlockDetected: boolean = false;
    private counterExampleState: Cruise_finite1_deterministic_MC = undefined;

    private invariantDependency: immutable.Map<string, immutable.Set<string>> = new immutable.Map();
    private guardDependency: immutable.Map<string, immutable.Set<string>> = new immutable.Map();

    constructor(type: Type, isCaching: boolean, isDebug: boolean) {
        this.type = type;
        this.isCaching = isCaching;
        this.isDebug = isDebug;
    }

    modelCheck(): void {
        if (this.isDebug) {
            console.log("Starting Modelchecking, STRATEGY=" + this.type + ", CACHING=" + this.isCaching);
        }
        this.modelCheckSingleThreaded();
    }

    modelCheckSingleThreaded(): void {
        let machine: Cruise_finite1_deterministic_MC = new Cruise_finite1_deterministic_MC();
        this.states = this.states.add(machine);
        this.unvisitedStates.pushBack(machine);

        if(this.isCaching) {
            this.initCache(machine);
        }

        while(!(this.unvisitedStates.length === 0)) {
            let state: Cruise_finite1_deterministic_MC = this.next();

            let nextStates: Set<Cruise_finite1_deterministic_MC> = this.generateNextStates(state);

            for(let nextState of nextStates) {
                if(!this.states.has(nextState)) {
                    this.states = this.states.add(nextState);
                    this.unvisitedStates.pushBack(nextState);
                    if(this.states.size % 50000 == 0 && this.isDebug) {
                        console.log("VISITED STATES: " + this.states.size);
                        console.log("EVALUATED TRANSITIONS: " + this.transitions);
                        console.log("-------------------");
                    }
                }
            }

            if(this.invViolated(state)) {
                this.invariantViolated = true;
                this.counterExampleState = state;
                break;
            }

            if(nextStates.size == 0) {
                this.deadlockDetected = true;
                this.counterExampleState = state;
                break;
            }

        }
        this.printResult(this.states.size, this.transitions);
    }

    initCache(machine: Cruise_finite1_deterministic_MC ): void {
        this.invariantDependency = this.invariantDependency.set("ObstacleStopsTravelSlower", immutable.Set(["_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"]));
        this.invariantDependency = this.invariantDependency.set("SetCruiseSpeed", immutable.Set(["_check_inv_18", "_check_inv_17", "_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_19", "_check_inv_10", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_34", "_check_inv_33", "_check_inv_26", "_check_inv_21", "_check_inv_20", "_check_inv_4", "_check_inv_25", "_check_inv_24", "_check_inv_8", "_check_inv_23", "_check_inv_9", "_check_inv_22", "_check_inv_2", "_check_inv_3"]));
        this.invariantDependency = this.invariantDependency.set("VehicleLeavesCruiseSpeed", immutable.Set(["_check_inv_17", "_check_inv_3", "_check_inv_34"]));
        this.invariantDependency = this.invariantDependency.set("VehicleFallsBelowMaxCruiseSpeed", immutable.Set(["_check_inv_17", "_check_inv_3", "_check_inv_6", "_check_inv_34"]));
        this.invariantDependency = this.invariantDependency.set("CCInitialisationFinished", immutable.Set(["_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_19", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_5", "_check_inv_36", "_check_inv_35"]));
        this.invariantDependency = this.invariantDependency.set("VehicleReachesCruiseSpeed", immutable.Set(["_check_inv_17", "_check_inv_3", "_check_inv_34"]));
        this.invariantDependency = this.invariantDependency.set("ObstacleAppearsWhenCruiseActive", immutable.Set(["_check_inv_29", "_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23", "_check_inv_11"]));
        this.invariantDependency = this.invariantDependency.set("ObstacleStartsTravelSlower", immutable.Set(["_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"]));
        this.invariantDependency = this.invariantDependency.set("CruiseBecomesNotAllowed", immutable.Set(["_check_inv_18", "_check_inv_17", "_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_19", "_check_inv_10", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_12", "_check_inv_34", "_check_inv_33", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_7", "_check_inv_20", "_check_inv_4", "_check_inv_5", "_check_inv_25", "_check_inv_24", "_check_inv_8", "_check_inv_23", "_check_inv_9", "_check_inv_22", "_check_inv_2", "_check_inv_3", "_check_inv_1"]));
        this.invariantDependency = this.invariantDependency.set("ObstacleAppearsWhenCruiseInactive", immutable.Set(["_check_inv_29", "_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_36", "_check_inv_13", "_check_inv_12", "_check_inv_23", "_check_inv_11"]));
        this.invariantDependency = this.invariantDependency.set("CCInitialisationDelayFinished", immutable.Set(["_check_inv_39", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_36", "_check_inv_25", "_check_inv_35"]));
        this.invariantDependency = this.invariantDependency.set("ObstacleDistanceBecomesClose", immutable.Set(["_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23"]));
        this.invariantDependency = this.invariantDependency.set("ObstacleStartsTravelFaster", immutable.Set(["_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"]));
        this.invariantDependency = this.invariantDependency.set("ExternalForcesBecomesExtreme", immutable.Set(["_check_inv_18", "_check_inv_4"]));
        this.invariantDependency = this.invariantDependency.set("CruiseOff", immutable.Set(["_check_inv_18", "_check_inv_17", "_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_19", "_check_inv_10", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_12", "_check_inv_34", "_check_inv_33", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_7", "_check_inv_20", "_check_inv_4", "_check_inv_5", "_check_inv_25", "_check_inv_24", "_check_inv_8", "_check_inv_23", "_check_inv_9", "_check_inv_22", "_check_inv_2", "_check_inv_3"]));
        this.invariantDependency = this.invariantDependency.set("CruiseSpeedChangeDelayFinished", immutable.Set(["_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_37", "_check_inv_26", "_check_inv_36", "_check_inv_35"]));
        this.invariantDependency = this.invariantDependency.set("ObstacleStopsTravelFaster", immutable.Set(["_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"]));
        this.invariantDependency = this.invariantDependency.set("ObstacleDistanceBecomesVeryClose", immutable.Set(["_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23"]));
        this.invariantDependency = this.invariantDependency.set("VehicleManageObstacle", immutable.Set(["_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_19", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_5", "_check_inv_36", "_check_inv_35"]));
        this.invariantDependency = this.invariantDependency.set("CruiseBecomesAllowed", immutable.Set(["_check_inv_1", "_check_inv_33"]));
        this.invariantDependency = this.invariantDependency.set("VehicleExceedsMaxCruiseSpeed", immutable.Set(["_check_inv_17", "_check_inv_3", "_check_inv_6", "_check_inv_34"]));
        this.invariantDependency = this.invariantDependency.set("CruiseSpeedChangeFinished", immutable.Set(["_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_19", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_5", "_check_inv_36", "_check_inv_35"]));
        this.invariantDependency = this.invariantDependency.set("ObstacleDisappears", immutable.Set(["_check_inv_29", "_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23", "_check_inv_11"]));
        this.invariantDependency = this.invariantDependency.set("ExternalForcesBecomesNormal", immutable.Set(["_check_inv_18", "_check_inv_4"]));
        this.invariantDependency = this.invariantDependency.set("ObstacleBecomesOld", immutable.Set(["_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24"]));
        this.invariantDependency = this.invariantDependency.set("ObstacleDistanceBecomesBig", immutable.Set(["_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23"]));
        this.guardDependency = this.guardDependency.set("ObstacleStopsTravelSlower", immutable.Set(["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"]));
        this.guardDependency = this.guardDependency.set("SetCruiseSpeed", immutable.Set(["_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesClose", "_tr_ExternalForcesBecomesNormal", "_tr_CruiseSpeedChangeFinished", "_tr_ExternalForcesBecomesExtreme", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleReachesCruiseSpeed", "_tr_CruiseOff", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleAppearsWhenCruiseInactive"]));
        this.guardDependency = this.guardDependency.set("VehicleLeavesCruiseSpeed", immutable.Set(["_tr_VehicleReachesCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"]));
        this.guardDependency = this.guardDependency.set("VehicleFallsBelowMaxCruiseSpeed", immutable.Set(["_tr_VehicleReachesCruiseSpeed", "_tr_VehicleFallsBelowMaxCruiseSpeed", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"]));
        this.guardDependency = this.guardDependency.set("CCInitialisationFinished", immutable.Set(["_tr_ObstacleBecomesOld", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed"]));
        this.guardDependency = this.guardDependency.set("VehicleReachesCruiseSpeed", immutable.Set(["_tr_VehicleReachesCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"]));
        this.guardDependency = this.guardDependency.set("ObstacleAppearsWhenCruiseActive", immutable.Set(["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleDisappears", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"]));
        this.guardDependency = this.guardDependency.set("ObstacleStartsTravelSlower", immutable.Set(["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"]));
        this.guardDependency = this.guardDependency.set("CruiseBecomesNotAllowed", immutable.Set(["_tr_SetCruiseSpeed", "_tr_VehicleManageObstacle", "_tr_CruiseBecomesAllowed", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseBecomesNotAllowed", "_tr_ExternalForcesBecomesNormal", "_tr_CruiseSpeedChangeFinished", "_tr_ExternalForcesBecomesExtreme", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleReachesCruiseSpeed", "_tr_CruiseOff", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"]));
        this.guardDependency = this.guardDependency.set("ObstacleAppearsWhenCruiseInactive", immutable.Set(["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleDisappears", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"]));
        this.guardDependency = this.guardDependency.set("CCInitialisationDelayFinished", immutable.Set(["_tr_VehicleManageObstacle", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"]));
        this.guardDependency = this.guardDependency.set("ObstacleDistanceBecomesClose", immutable.Set(["_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"]));
        this.guardDependency = this.guardDependency.set("ObstacleStartsTravelFaster", immutable.Set(["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"]));
        this.guardDependency = this.guardDependency.set("ExternalForcesBecomesExtreme", immutable.Set(["_tr_ExternalForcesBecomesNormal", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ExternalForcesBecomesExtreme", "_tr_VehicleLeavesCruiseSpeed"]));
        this.guardDependency = this.guardDependency.set("CruiseOff", immutable.Set(["_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_ExternalForcesBecomesNormal", "_tr_CruiseSpeedChangeFinished", "_tr_ExternalForcesBecomesExtreme", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleReachesCruiseSpeed", "_tr_CruiseOff", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"]));
        this.guardDependency = this.guardDependency.set("CruiseSpeedChangeDelayFinished", immutable.Set(["_tr_VehicleManageObstacle", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"]));
        this.guardDependency = this.guardDependency.set("ObstacleStopsTravelFaster", immutable.Set(["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"]));
        this.guardDependency = this.guardDependency.set("ObstacleDistanceBecomesVeryClose", immutable.Set(["_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"]));
        this.guardDependency = this.guardDependency.set("VehicleManageObstacle", immutable.Set(["_tr_ObstacleBecomesOld", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed"]));
        this.guardDependency = this.guardDependency.set("CruiseBecomesAllowed", immutable.Set(["_tr_SetCruiseSpeed", "_tr_CruiseBecomesAllowed", "_tr_CruiseBecomesNotAllowed"]));
        this.guardDependency = this.guardDependency.set("VehicleExceedsMaxCruiseSpeed", immutable.Set(["_tr_VehicleReachesCruiseSpeed", "_tr_VehicleFallsBelowMaxCruiseSpeed", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"]));
        this.guardDependency = this.guardDependency.set("CruiseSpeedChangeFinished", immutable.Set(["_tr_ObstacleBecomesOld", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed"]));
        this.guardDependency = this.guardDependency.set("ObstacleDisappears", immutable.Set(["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleDisappears", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"]));
        this.guardDependency = this.guardDependency.set("ExternalForcesBecomesNormal", immutable.Set(["_tr_ExternalForcesBecomesNormal", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ExternalForcesBecomesExtreme", "_tr_VehicleLeavesCruiseSpeed"]));
        this.guardDependency = this.guardDependency.set("ObstacleBecomesOld", immutable.Set(["_tr_VehicleManageObstacle", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"]));
        this.guardDependency = this.guardDependency.set("ObstacleDistanceBecomesBig", immutable.Set(["_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"]));
    }

    next(): Cruise_finite1_deterministic_MC {
        switch(this.type) {
            case Type.BFS:
                return this.unvisitedStates.popFront();
            case Type.DFS:
                return this.unvisitedStates.popBack();
            case Type.MIXED:
                if(this.unvisitedStates.length % 2 == 0) {
                    return this.unvisitedStates.popFront();
                } else {
                    return this.unvisitedStates.popBack();
                }
            default:
                break;
        }
        return undefined;
    }

    generateNextStates(state: Cruise_finite1_deterministic_MC): Set<Cruise_finite1_deterministic_MC> {
        let result: immutable.Set<Cruise_finite1_deterministic_MC> = immutable.Set();
        if(this.isCaching) {
            let parentsGuard: immutable.Map = state.guardCache;
            let newCache: immutable.Map = parentsGuard == null ? immutable.Map() : parentsGuard;
            let cachedValue: any = null;
            let dependentGuardsBoolean: boolean = true;
            let _trid_1: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_CruiseBecomesNotAllowed");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_CruiseBecomesNotAllowed");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_1 = state._tr_CruiseBecomesNotAllowed();
            } else {
                _trid_1 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_CruiseBecomesNotAllowed", _trid_1);
            if(_trid_1) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.CruiseBecomesNotAllowed();
                copiedState.parent = state;
                this.addCachedInfos("CruiseBecomesNotAllowed", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_2: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_CruiseBecomesAllowed");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_CruiseBecomesAllowed");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_2 = state._tr_CruiseBecomesAllowed();
            } else {
                _trid_2 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_CruiseBecomesAllowed", _trid_2);
            if(_trid_2) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.CruiseBecomesAllowed();
                copiedState.parent = state;
                this.addCachedInfos("CruiseBecomesAllowed", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_3: BSet<BTuple<BBoolean, BBoolean>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_SetCruiseSpeed");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_SetCruiseSpeed");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_3 = state._tr_SetCruiseSpeed();
            } else {
                _trid_3 = cachedValue as BSet<BTuple<BBoolean, BBoolean>>;
            }
            newCache = newCache.set("_tr_SetCruiseSpeed", _trid_3);
            for(let param of _trid_3) {
                let _tmp_1: BBoolean = param.projection2();
                let _tmp_2: BBoolean = param.projection1();

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.SetCruiseSpeed(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("SetCruiseSpeed", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_4: BSet<BTuple<BBoolean, BBoolean>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_CCInitialisationFinished");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_CCInitialisationFinished");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_4 = state._tr_CCInitialisationFinished();
            } else {
                _trid_4 = cachedValue as BSet<BTuple<BBoolean, BBoolean>>;
            }
            newCache = newCache.set("_tr_CCInitialisationFinished", _trid_4);
            for(let param of _trid_4) {
                let _tmp_1: BBoolean = param.projection2();
                let _tmp_2: BBoolean = param.projection1();

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.CCInitialisationFinished(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("CCInitialisationFinished", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_5: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_CCInitialisationDelayFinished");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_CCInitialisationDelayFinished");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_5 = state._tr_CCInitialisationDelayFinished();
            } else {
                _trid_5 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_CCInitialisationDelayFinished", _trid_5);
            if(_trid_5) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.CCInitialisationDelayFinished();
                copiedState.parent = state;
                this.addCachedInfos("CCInitialisationDelayFinished", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_6: BSet<BTuple<BBoolean, BBoolean>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_CruiseSpeedChangeFinished");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_CruiseSpeedChangeFinished");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_6 = state._tr_CruiseSpeedChangeFinished();
            } else {
                _trid_6 = cachedValue as BSet<BTuple<BBoolean, BBoolean>>;
            }
            newCache = newCache.set("_tr_CruiseSpeedChangeFinished", _trid_6);
            for(let param of _trid_6) {
                let _tmp_1: BBoolean = param.projection2();
                let _tmp_2: BBoolean = param.projection1();

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.CruiseSpeedChangeFinished(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("CruiseSpeedChangeFinished", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_7: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_CruiseSpeedChangeDelayFinished");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_CruiseSpeedChangeDelayFinished");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_7 = state._tr_CruiseSpeedChangeDelayFinished();
            } else {
                _trid_7 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_CruiseSpeedChangeDelayFinished", _trid_7);
            if(_trid_7) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.CruiseSpeedChangeDelayFinished();
                copiedState.parent = state;
                this.addCachedInfos("CruiseSpeedChangeDelayFinished", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_8: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_CruiseOff");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_CruiseOff");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_8 = state._tr_CruiseOff();
            } else {
                _trid_8 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_CruiseOff", _trid_8);
            if(_trid_8) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.CruiseOff();
                copiedState.parent = state;
                this.addCachedInfos("CruiseOff", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_9: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_ExternalForcesBecomesExtreme");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_ExternalForcesBecomesExtreme");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_9 = state._tr_ExternalForcesBecomesExtreme();
            } else {
                _trid_9 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_ExternalForcesBecomesExtreme", _trid_9);
            if(_trid_9) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ExternalForcesBecomesExtreme();
                copiedState.parent = state;
                this.addCachedInfos("ExternalForcesBecomesExtreme", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_10: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_ExternalForcesBecomesNormal");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_ExternalForcesBecomesNormal");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_10 = state._tr_ExternalForcesBecomesNormal();
            } else {
                _trid_10 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_ExternalForcesBecomesNormal", _trid_10);
            if(_trid_10) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ExternalForcesBecomesNormal();
                copiedState.parent = state;
                this.addCachedInfos("ExternalForcesBecomesNormal", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_11: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_VehicleLeavesCruiseSpeed");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_VehicleLeavesCruiseSpeed");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_11 = state._tr_VehicleLeavesCruiseSpeed();
            } else {
                _trid_11 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_VehicleLeavesCruiseSpeed", _trid_11);
            if(_trid_11) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.VehicleLeavesCruiseSpeed();
                copiedState.parent = state;
                this.addCachedInfos("VehicleLeavesCruiseSpeed", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_12: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_VehicleReachesCruiseSpeed");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_VehicleReachesCruiseSpeed");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_12 = state._tr_VehicleReachesCruiseSpeed();
            } else {
                _trid_12 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_VehicleReachesCruiseSpeed", _trid_12);
            if(_trid_12) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.VehicleReachesCruiseSpeed();
                copiedState.parent = state;
                this.addCachedInfos("VehicleReachesCruiseSpeed", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_13: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_VehicleExceedsMaxCruiseSpeed");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_VehicleExceedsMaxCruiseSpeed");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_13 = state._tr_VehicleExceedsMaxCruiseSpeed();
            } else {
                _trid_13 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_VehicleExceedsMaxCruiseSpeed", _trid_13);
            if(_trid_13) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.VehicleExceedsMaxCruiseSpeed();
                copiedState.parent = state;
                this.addCachedInfos("VehicleExceedsMaxCruiseSpeed", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_14: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_VehicleFallsBelowMaxCruiseSpeed");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_VehicleFallsBelowMaxCruiseSpeed");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_14 = state._tr_VehicleFallsBelowMaxCruiseSpeed();
            } else {
                _trid_14 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_VehicleFallsBelowMaxCruiseSpeed", _trid_14);
            if(_trid_14) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.VehicleFallsBelowMaxCruiseSpeed();
                copiedState.parent = state;
                this.addCachedInfos("VehicleFallsBelowMaxCruiseSpeed", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_15: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_ObstacleDistanceBecomesVeryClose");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_ObstacleDistanceBecomesVeryClose");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_15 = state._tr_ObstacleDistanceBecomesVeryClose();
            } else {
                _trid_15 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_ObstacleDistanceBecomesVeryClose", _trid_15);
            if(_trid_15) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleDistanceBecomesVeryClose();
                copiedState.parent = state;
                this.addCachedInfos("ObstacleDistanceBecomesVeryClose", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_16: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_ObstacleDistanceBecomesClose");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_ObstacleDistanceBecomesClose");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_16 = state._tr_ObstacleDistanceBecomesClose();
            } else {
                _trid_16 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_ObstacleDistanceBecomesClose", _trid_16);
            if(_trid_16) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleDistanceBecomesClose();
                copiedState.parent = state;
                this.addCachedInfos("ObstacleDistanceBecomesClose", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_17: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_ObstacleDistanceBecomesBig");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_ObstacleDistanceBecomesBig");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_17 = state._tr_ObstacleDistanceBecomesBig();
            } else {
                _trid_17 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_ObstacleDistanceBecomesBig", _trid_17);
            if(_trid_17) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleDistanceBecomesBig();
                copiedState.parent = state;
                this.addCachedInfos("ObstacleDistanceBecomesBig", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_18: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_ObstacleStartsTravelFaster");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_ObstacleStartsTravelFaster");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_18 = state._tr_ObstacleStartsTravelFaster();
            } else {
                _trid_18 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_ObstacleStartsTravelFaster", _trid_18);
            if(_trid_18) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleStartsTravelFaster();
                copiedState.parent = state;
                this.addCachedInfos("ObstacleStartsTravelFaster", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_19: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_ObstacleStopsTravelFaster");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_ObstacleStopsTravelFaster");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_19 = state._tr_ObstacleStopsTravelFaster();
            } else {
                _trid_19 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_ObstacleStopsTravelFaster", _trid_19);
            if(_trid_19) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleStopsTravelFaster();
                copiedState.parent = state;
                this.addCachedInfos("ObstacleStopsTravelFaster", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_20: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_ObstacleStartsTravelSlower");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_ObstacleStartsTravelSlower");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_20 = state._tr_ObstacleStartsTravelSlower();
            } else {
                _trid_20 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_ObstacleStartsTravelSlower", _trid_20);
            if(_trid_20) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleStartsTravelSlower();
                copiedState.parent = state;
                this.addCachedInfos("ObstacleStartsTravelSlower", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_21: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_ObstacleStopsTravelSlower");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_ObstacleStopsTravelSlower");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_21 = state._tr_ObstacleStopsTravelSlower();
            } else {
                _trid_21 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_ObstacleStopsTravelSlower", _trid_21);
            if(_trid_21) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleStopsTravelSlower();
                copiedState.parent = state;
                this.addCachedInfos("ObstacleStopsTravelSlower", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_22: BSet<BTuple<RSset, ODset>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_ObstacleAppearsWhenCruiseActive");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_ObstacleAppearsWhenCruiseActive");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_22 = state._tr_ObstacleAppearsWhenCruiseActive();
            } else {
                _trid_22 = cachedValue as BSet<BTuple<RSset, ODset>>;
            }
            newCache = newCache.set("_tr_ObstacleAppearsWhenCruiseActive", _trid_22);
            for(let param of _trid_22) {
                let _tmp_1: ODset = param.projection2();
                let _tmp_2: RSset = param.projection1();

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleAppearsWhenCruiseActive(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("ObstacleAppearsWhenCruiseActive", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_23: BSet<RSset>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_ObstacleAppearsWhenCruiseInactive");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_ObstacleAppearsWhenCruiseInactive");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_23 = state._tr_ObstacleAppearsWhenCruiseInactive();
            } else {
                _trid_23 = cachedValue as BSet<RSset>;
            }
            newCache = newCache.set("_tr_ObstacleAppearsWhenCruiseInactive", _trid_23);
            for(let param of _trid_23) {
                let _tmp_1: RSset = param;

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleAppearsWhenCruiseInactive(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("ObstacleAppearsWhenCruiseInactive", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_24: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_ObstacleDisappears");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_ObstacleDisappears");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_24 = state._tr_ObstacleDisappears();
            } else {
                _trid_24 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_ObstacleDisappears", _trid_24);
            if(_trid_24) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleDisappears();
                copiedState.parent = state;
                this.addCachedInfos("ObstacleDisappears", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_25: BSet<BTuple<BBoolean, BBoolean>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_VehicleManageObstacle");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_VehicleManageObstacle");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_25 = state._tr_VehicleManageObstacle();
            } else {
                _trid_25 = cachedValue as BSet<BTuple<BBoolean, BBoolean>>;
            }
            newCache = newCache.set("_tr_VehicleManageObstacle", _trid_25);
            for(let param of _trid_25) {
                let _tmp_1: BBoolean = param.projection2();
                let _tmp_2: BBoolean = param.projection1();

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.VehicleManageObstacle(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("VehicleManageObstacle", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_26: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_ObstacleBecomesOld");
                dependentGuardsBoolean = state.dependentGuard.has("_tr_ObstacleBecomesOld");
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_26 = state._tr_ObstacleBecomesOld();
            } else {
                _trid_26 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_ObstacleBecomesOld", _trid_26);
            if(_trid_26) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleBecomesOld();
                copiedState.parent = state;
                this.addCachedInfos("ObstacleBecomesOld", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

            state.guardCache = newCache;
        } else {
            if(state._tr_CruiseBecomesNotAllowed()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.CruiseBecomesNotAllowed();
                copiedState.parent = state;
                this.addCachedInfos("CruiseBecomesNotAllowed", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_CruiseBecomesAllowed()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.CruiseBecomesAllowed();
                copiedState.parent = state;
                this.addCachedInfos("CruiseBecomesAllowed", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_3: BSet<BTuple<BBoolean, BBoolean>> = state._tr_SetCruiseSpeed();
            for(let param of _trid_3) {
                let _tmp_1: BBoolean = param.projection2();
                let _tmp_2: BBoolean = param.projection1();

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.SetCruiseSpeed(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("SetCruiseSpeed", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_4: BSet<BTuple<BBoolean, BBoolean>> = state._tr_CCInitialisationFinished();
            for(let param of _trid_4) {
                let _tmp_1: BBoolean = param.projection2();
                let _tmp_2: BBoolean = param.projection1();

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.CCInitialisationFinished(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("CCInitialisationFinished", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_CCInitialisationDelayFinished()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.CCInitialisationDelayFinished();
                copiedState.parent = state;
                this.addCachedInfos("CCInitialisationDelayFinished", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_6: BSet<BTuple<BBoolean, BBoolean>> = state._tr_CruiseSpeedChangeFinished();
            for(let param of _trid_6) {
                let _tmp_1: BBoolean = param.projection2();
                let _tmp_2: BBoolean = param.projection1();

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.CruiseSpeedChangeFinished(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("CruiseSpeedChangeFinished", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_CruiseSpeedChangeDelayFinished()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.CruiseSpeedChangeDelayFinished();
                copiedState.parent = state;
                this.addCachedInfos("CruiseSpeedChangeDelayFinished", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_CruiseOff()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.CruiseOff();
                copiedState.parent = state;
                this.addCachedInfos("CruiseOff", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ExternalForcesBecomesExtreme()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ExternalForcesBecomesExtreme();
                copiedState.parent = state;
                this.addCachedInfos("ExternalForcesBecomesExtreme", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ExternalForcesBecomesNormal()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ExternalForcesBecomesNormal();
                copiedState.parent = state;
                this.addCachedInfos("ExternalForcesBecomesNormal", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_VehicleLeavesCruiseSpeed()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.VehicleLeavesCruiseSpeed();
                copiedState.parent = state;
                this.addCachedInfos("VehicleLeavesCruiseSpeed", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_VehicleReachesCruiseSpeed()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.VehicleReachesCruiseSpeed();
                copiedState.parent = state;
                this.addCachedInfos("VehicleReachesCruiseSpeed", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_VehicleExceedsMaxCruiseSpeed()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.VehicleExceedsMaxCruiseSpeed();
                copiedState.parent = state;
                this.addCachedInfos("VehicleExceedsMaxCruiseSpeed", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_VehicleFallsBelowMaxCruiseSpeed()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.VehicleFallsBelowMaxCruiseSpeed();
                copiedState.parent = state;
                this.addCachedInfos("VehicleFallsBelowMaxCruiseSpeed", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ObstacleDistanceBecomesVeryClose()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleDistanceBecomesVeryClose();
                copiedState.parent = state;
                this.addCachedInfos("ObstacleDistanceBecomesVeryClose", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ObstacleDistanceBecomesClose()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleDistanceBecomesClose();
                copiedState.parent = state;
                this.addCachedInfos("ObstacleDistanceBecomesClose", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ObstacleDistanceBecomesBig()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleDistanceBecomesBig();
                copiedState.parent = state;
                this.addCachedInfos("ObstacleDistanceBecomesBig", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ObstacleStartsTravelFaster()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleStartsTravelFaster();
                copiedState.parent = state;
                this.addCachedInfos("ObstacleStartsTravelFaster", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ObstacleStopsTravelFaster()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleStopsTravelFaster();
                copiedState.parent = state;
                this.addCachedInfos("ObstacleStopsTravelFaster", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ObstacleStartsTravelSlower()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleStartsTravelSlower();
                copiedState.parent = state;
                this.addCachedInfos("ObstacleStartsTravelSlower", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ObstacleStopsTravelSlower()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleStopsTravelSlower();
                copiedState.parent = state;
                this.addCachedInfos("ObstacleStopsTravelSlower", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_22: BSet<BTuple<RSset, ODset>> = state._tr_ObstacleAppearsWhenCruiseActive();
            for(let param of _trid_22) {
                let _tmp_1: ODset = param.projection2();
                let _tmp_2: RSset = param.projection1();

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleAppearsWhenCruiseActive(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("ObstacleAppearsWhenCruiseActive", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_23: BSet<RSset> = state._tr_ObstacleAppearsWhenCruiseInactive();
            for(let param of _trid_23) {
                let _tmp_1: RSset = param;

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleAppearsWhenCruiseInactive(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("ObstacleAppearsWhenCruiseInactive", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ObstacleDisappears()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleDisappears();
                copiedState.parent = state;
                this.addCachedInfos("ObstacleDisappears", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_25: BSet<BTuple<BBoolean, BBoolean>> = state._tr_VehicleManageObstacle();
            for(let param of _trid_25) {
                let _tmp_1: BBoolean = param.projection2();
                let _tmp_2: BBoolean = param.projection1();

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.VehicleManageObstacle(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("VehicleManageObstacle", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ObstacleBecomesOld()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleBecomesOld();
                copiedState.parent = state;
                this.addCachedInfos("ObstacleBecomesOld", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        }
        return result;
    }

    invViolated(state: Cruise_finite1_deterministic_MC): boolean {
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_1")) {
            if(!state._check_inv_1()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_1");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_2")) {
            if(!state._check_inv_2()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_2");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_3")) {
            if(!state._check_inv_3()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_3");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_4")) {
            if(!state._check_inv_4()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_4");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_5")) {
            if(!state._check_inv_5()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_5");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_6")) {
            if(!state._check_inv_6()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_6");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_7")) {
            if(!state._check_inv_7()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_7");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_8")) {
            if(!state._check_inv_8()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_8");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_9")) {
            if(!state._check_inv_9()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_9");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_10")) {
            if(!state._check_inv_10()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_10");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_11")) {
            if(!state._check_inv_11()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_11");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_12")) {
            if(!state._check_inv_12()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_12");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_13")) {
            if(!state._check_inv_13()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_13");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_14")) {
            if(!state._check_inv_14()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_14");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_15")) {
            if(!state._check_inv_15()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_15");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_16")) {
            if(!state._check_inv_16()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_16");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_17")) {
            if(!state._check_inv_17()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_17");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_18")) {
            if(!state._check_inv_18()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_18");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_19")) {
            if(!state._check_inv_19()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_19");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_20")) {
            if(!state._check_inv_20()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_20");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_21")) {
            if(!state._check_inv_21()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_21");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_22")) {
            if(!state._check_inv_22()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_22");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_23")) {
            if(!state._check_inv_23()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_23");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_24")) {
            if(!state._check_inv_24()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_24");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_25")) {
            if(!state._check_inv_25()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_25");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_26")) {
            if(!state._check_inv_26()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_26");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_27")) {
            if(!state._check_inv_27()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_27");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_28")) {
            if(!state._check_inv_28()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_28");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_29")) {
            if(!state._check_inv_29()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_29");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_30")) {
            if(!state._check_inv_30()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_30");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_31")) {
            if(!state._check_inv_31()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_31");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_32")) {
            if(!state._check_inv_32()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_32");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_33")) {
            if(!state._check_inv_33()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_33");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_34")) {
            if(!state._check_inv_34()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_34");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_35")) {
            if(!state._check_inv_35()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_35");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_36")) {
            if(!state._check_inv_36()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_36");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_37")) {
            if(!state._check_inv_37()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_37");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_38")) {
            if(!state._check_inv_38()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_38");
                return true;
            }
        }
        if(!(this.isCaching) || state.dependentInvariant.has("_check_inv_39")) {
            if(!state._check_inv_39()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_39");
                return true;
            }
        }
        return false;
    }

    addCachedInfos(operation: string, state: Cruise_finite1_deterministic_MC, copiedState: Cruise_finite1_deterministic_MC): void {
        if(this.isCaching) {
            copiedState.dependentInvariant = this.invariantDependency.get(operation);
            copiedState.dependentGuard = this.guardDependency.get(operation);
        }
        copiedState.stateAccessedVia = operation;
    }

    printResult(states: number, transitions: number): void {
        if(this.invariantViolated || this.deadlockDetected) {
            if(this.deadlockDetected) {
                console.log("DEADLOCK DETECTED");
            } else {
                console.log("INVARIANT VIOLATED");
            }

            console.log("COUNTER EXAMPLE TRACE: ");
            let sb: string = '';
            while(this.counterExampleState != null) {
                sb = this.counterExampleState + '\n' + sb;
                if(this.counterExampleState.stateAccessedVia != null) {
                    sb = this.counterExampleState.stateAccessedVia + sb;
                }
                sb = '\n\n' + sb;
                this.counterExampleState = this.counterExampleState.parent;
            }
            console.log(sb);
        } else {
            console.log("MODEL CHECKING SUCCESSFUL");
        }

        console.log("Number of States: " + this.states.size);
        console.log("Number of Transitions: " + this.transitions);
    }
}


let args : string[] = process.argv;
if(args.length > 5) {
    console.log("Expecting 3 command-line arguments: STRATEGY CACHING DEBUG");
    process.exit(-1);
}
let type: Type = Type.MIXED;
let threads: number = 0;
let isCaching: boolean = false;
let isDebug: boolean = false;

if(args.length > 2) {
    if("mixed" === args[2]) {
        type = Type.MIXED;
    } else if("bf" === args[2]) {
        type = Type.BFS;
    } else if ("df" === args[2]) {
        type = Type.DFS;
    } else {
        console.log("Value for command-line argument STRATEGY is wrong.");
        console.log("Expecting mixed, bf or df.");
        process.exit(-1);
    }
}
if(args.length > 3) {
    try {
        isCaching = JSON.parse(args[3].toLowerCase());
    } catch(e) {
        console.log("Value for command-line argument CACHING is not a boolean.");
        process.exit(-1);
    }
}
if(args.length > 4) {
    try {
        isDebug = JSON.parse(args[4].toLowerCase());
    } catch(e) {
        console.log("Value for command-line argument DEBUG is not a boolean.");
        process.exit(-1);
    }
}
let modelchecker: ModelChecker = new ModelChecker(type, isCaching, isDebug);
modelchecker.modelCheck();

