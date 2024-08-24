import {BTuple} from './btypes/BTuple.js';
import {BInteger} from './btypes/BInteger.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";
import {VariantViolation} from "./btypes/BUtils.js";
import {LoopInvariantViolation} from "./btypes/BUtils.js";
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


class _ProjectionRead_CruiseBecomesNotAllowed {

    public CruiseAllowed: BBoolean;

    constructor(CruiseAllowed : BBoolean) {
        this.CruiseAllowed = CruiseAllowed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_CruiseBecomesNotAllowed = this;
        let o2: _ProjectionRead_CruiseBecomesNotAllowed = other as _ProjectionRead_CruiseBecomesNotAllowed;
        return o1.CruiseAllowed.equals(o2.CruiseAllowed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseAllowed.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_CruiseBecomesNotAllowed {

    public CruiseAllowed: BBoolean;

    constructor(CruiseAllowed : BBoolean) {
        this.CruiseAllowed = CruiseAllowed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_CruiseBecomesNotAllowed = this;
        let o2: _ProjectionRead__tr_CruiseBecomesNotAllowed = other as _ProjectionRead__tr_CruiseBecomesNotAllowed;
        return o1.CruiseAllowed.equals(o2.CruiseAllowed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseAllowed.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_CruiseBecomesNotAllowed {

    public VehicleTryKeepSpeed: BBoolean;
    public CruiseSpeedAtMax: BBoolean;
    public CruiseActive: BBoolean;
    public VehicleAtCruiseSpeed: BBoolean;
    public CruiseAllowed: BBoolean;
    public ObstacleStatusJustChanged: BBoolean;
    public CCInitialisationInProgress: BBoolean;
    public NumberOfSetCruise: BInteger;
    public VehicleTryKeepTimeGap: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;
    public VehicleCanKeepSpeed: BBoolean;
    public ObstacleDistance: ODset;

    constructor(VehicleTryKeepSpeed : BBoolean, CruiseSpeedAtMax : BBoolean, CruiseActive : BBoolean, VehicleAtCruiseSpeed : BBoolean, CruiseAllowed : BBoolean, ObstacleStatusJustChanged : BBoolean, CCInitialisationInProgress : BBoolean, NumberOfSetCruise : BInteger, VehicleTryKeepTimeGap : BBoolean, CruiseSpeedChangeInProgress : BBoolean, VehicleCanKeepSpeed : BBoolean, ObstacleDistance : ODset) {
        this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
        this.CruiseSpeedAtMax = CruiseSpeedAtMax;
        this.CruiseActive = CruiseActive;
        this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
        this.CruiseAllowed = CruiseAllowed;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.NumberOfSetCruise = NumberOfSetCruise;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_CruiseBecomesNotAllowed = this;
        let o2: _ProjectionWrite_CruiseBecomesNotAllowed = other as _ProjectionWrite_CruiseBecomesNotAllowed;
        return o1.VehicleTryKeepSpeed.equals(o2.VehicleTryKeepSpeed) && o1.CruiseSpeedAtMax.equals(o2.CruiseSpeedAtMax) && o1.CruiseActive.equals(o2.CruiseActive) && o1.VehicleAtCruiseSpeed.equals(o2.VehicleAtCruiseSpeed) && o1.CruiseAllowed.equals(o2.CruiseAllowed) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.NumberOfSetCruise.equals(o2.NumberOfSetCruise) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress) && o1.VehicleCanKeepSpeed.equals(o2.VehicleCanKeepSpeed) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleTryKeepSpeed.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedAtMax.hashCode() << 1);
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.VehicleAtCruiseSpeed.hashCode() << 1);
        result = 31 * result + (this.CruiseAllowed.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.NumberOfSetCruise.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        result = 31 * result + (this.VehicleCanKeepSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_CruiseBecomesAllowed {

    public CruiseAllowed: BBoolean;

    constructor(CruiseAllowed : BBoolean) {
        this.CruiseAllowed = CruiseAllowed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_CruiseBecomesAllowed = this;
        let o2: _ProjectionRead_CruiseBecomesAllowed = other as _ProjectionRead_CruiseBecomesAllowed;
        return o1.CruiseAllowed.equals(o2.CruiseAllowed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseAllowed.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_CruiseBecomesAllowed {

    public CruiseAllowed: BBoolean;

    constructor(CruiseAllowed : BBoolean) {
        this.CruiseAllowed = CruiseAllowed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_CruiseBecomesAllowed = this;
        let o2: _ProjectionRead__tr_CruiseBecomesAllowed = other as _ProjectionRead__tr_CruiseBecomesAllowed;
        return o1.CruiseAllowed.equals(o2.CruiseAllowed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseAllowed.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_CruiseBecomesAllowed {

    public CruiseAllowed: BBoolean;

    constructor(CruiseAllowed : BBoolean) {
        this.CruiseAllowed = CruiseAllowed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_CruiseBecomesAllowed = this;
        let o2: _ProjectionWrite_CruiseBecomesAllowed = other as _ProjectionWrite_CruiseBecomesAllowed;
        return o1.CruiseAllowed.equals(o2.CruiseAllowed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseAllowed.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_SetCruiseSpeed {

    public CruiseActive: BBoolean;
    public CruiseAllowed: BBoolean;
    public SpeedAboveMax: BBoolean;
    public NumberOfSetCruise: BInteger;

    constructor(CruiseActive : BBoolean, CruiseAllowed : BBoolean, SpeedAboveMax : BBoolean, NumberOfSetCruise : BInteger) {
        this.CruiseActive = CruiseActive;
        this.CruiseAllowed = CruiseAllowed;
        this.SpeedAboveMax = SpeedAboveMax;
        this.NumberOfSetCruise = NumberOfSetCruise;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_SetCruiseSpeed = this;
        let o2: _ProjectionRead_SetCruiseSpeed = other as _ProjectionRead_SetCruiseSpeed;
        return o1.CruiseActive.equals(o2.CruiseActive) && o1.CruiseAllowed.equals(o2.CruiseAllowed) && o1.SpeedAboveMax.equals(o2.SpeedAboveMax) && o1.NumberOfSetCruise.equals(o2.NumberOfSetCruise);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.CruiseAllowed.hashCode() << 1);
        result = 31 * result + (this.SpeedAboveMax.hashCode() << 1);
        result = 31 * result + (this.NumberOfSetCruise.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_SetCruiseSpeed {

    public CruiseAllowed: BBoolean;

    constructor(CruiseAllowed : BBoolean) {
        this.CruiseAllowed = CruiseAllowed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_SetCruiseSpeed = this;
        let o2: _ProjectionRead__tr_SetCruiseSpeed = other as _ProjectionRead__tr_SetCruiseSpeed;
        return o1.CruiseAllowed.equals(o2.CruiseAllowed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseAllowed.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_SetCruiseSpeed {

    public CruiseSpeedAtMax: BBoolean;
    public CruiseActive: BBoolean;
    public VehicleAtCruiseSpeed: BBoolean;
    public ObstacleStatusJustChanged: BBoolean;
    public CCInitialisationInProgress: BBoolean;
    public NumberOfSetCruise: BInteger;
    public CruiseSpeedChangeInProgress: BBoolean;
    public VehicleCanKeepSpeed: BBoolean;

    constructor(CruiseSpeedAtMax : BBoolean, CruiseActive : BBoolean, VehicleAtCruiseSpeed : BBoolean, ObstacleStatusJustChanged : BBoolean, CCInitialisationInProgress : BBoolean, NumberOfSetCruise : BInteger, CruiseSpeedChangeInProgress : BBoolean, VehicleCanKeepSpeed : BBoolean) {
        this.CruiseSpeedAtMax = CruiseSpeedAtMax;
        this.CruiseActive = CruiseActive;
        this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.NumberOfSetCruise = NumberOfSetCruise;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_SetCruiseSpeed = this;
        let o2: _ProjectionWrite_SetCruiseSpeed = other as _ProjectionWrite_SetCruiseSpeed;
        return o1.CruiseSpeedAtMax.equals(o2.CruiseSpeedAtMax) && o1.CruiseActive.equals(o2.CruiseActive) && o1.VehicleAtCruiseSpeed.equals(o2.VehicleAtCruiseSpeed) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.NumberOfSetCruise.equals(o2.NumberOfSetCruise) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress) && o1.VehicleCanKeepSpeed.equals(o2.VehicleCanKeepSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseSpeedAtMax.hashCode() << 1);
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.VehicleAtCruiseSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.NumberOfSetCruise.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        result = 31 * result + (this.VehicleCanKeepSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_CCInitialisationFinished {

    public ObstacleStatusJustChanged: BBoolean;
    public CCInitialisationInProgress: BBoolean;
    public ObstacleDistance: ODset;
    public ObstacleRelativeSpeed: RSset;
    public ObstaclePresent: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;

    constructor(ObstacleStatusJustChanged : BBoolean, CCInitialisationInProgress : BBoolean, ObstacleDistance : ODset, ObstacleRelativeSpeed : RSset, ObstaclePresent : BBoolean, CruiseSpeedChangeInProgress : BBoolean) {
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.ObstacleDistance = ObstacleDistance;
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstaclePresent = ObstaclePresent;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_CCInitialisationFinished = this;
        let o2: _ProjectionRead_CCInitialisationFinished = other as _ProjectionRead_CCInitialisationFinished;
        return o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.ObstacleDistance.equals(o2.ObstacleDistance) && o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstaclePresent.equals(o2.ObstaclePresent) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_CCInitialisationFinished {

    public ObstacleStatusJustChanged: BBoolean;
    public CCInitialisationInProgress: BBoolean;
    public ObstacleDistance: ODset;
    public ObstacleRelativeSpeed: RSset;
    public ObstaclePresent: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;

    constructor(ObstacleStatusJustChanged : BBoolean, CCInitialisationInProgress : BBoolean, ObstacleDistance : ODset, ObstacleRelativeSpeed : RSset, ObstaclePresent : BBoolean, CruiseSpeedChangeInProgress : BBoolean) {
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.ObstacleDistance = ObstacleDistance;
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstaclePresent = ObstaclePresent;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_CCInitialisationFinished = this;
        let o2: _ProjectionRead__tr_CCInitialisationFinished = other as _ProjectionRead__tr_CCInitialisationFinished;
        return o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.ObstacleDistance.equals(o2.ObstacleDistance) && o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstaclePresent.equals(o2.ObstaclePresent) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_CCInitialisationFinished {

    public VehicleTryKeepSpeed: BBoolean;
    public VehicleTryKeepTimeGap: BBoolean;

    constructor(VehicleTryKeepSpeed : BBoolean, VehicleTryKeepTimeGap : BBoolean) {
        this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_CCInitialisationFinished = this;
        let o2: _ProjectionWrite_CCInitialisationFinished = other as _ProjectionWrite_CCInitialisationFinished;
        return o1.VehicleTryKeepSpeed.equals(o2.VehicleTryKeepSpeed) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleTryKeepSpeed.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_CCInitialisationDelayFinished {

    public VehicleTryKeepSpeed: BBoolean;
    public ObstacleRelativeSpeed: RSset;
    public CCInitialisationInProgress: BBoolean;
    public ObstacleStatusJustChanged: BBoolean;
    public VehicleTryKeepTimeGap: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;
    public ObstacleDistance: ODset;

    constructor(VehicleTryKeepSpeed : BBoolean, ObstacleRelativeSpeed : RSset, CCInitialisationInProgress : BBoolean, ObstacleStatusJustChanged : BBoolean, VehicleTryKeepTimeGap : BBoolean, CruiseSpeedChangeInProgress : BBoolean, ObstacleDistance : ODset) {
        this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_CCInitialisationDelayFinished = this;
        let o2: _ProjectionRead_CCInitialisationDelayFinished = other as _ProjectionRead_CCInitialisationDelayFinished;
        return o1.VehicleTryKeepSpeed.equals(o2.VehicleTryKeepSpeed) && o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleTryKeepSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_CCInitialisationDelayFinished {

    public VehicleTryKeepSpeed: BBoolean;
    public ObstacleRelativeSpeed: RSset;
    public CCInitialisationInProgress: BBoolean;
    public ObstacleStatusJustChanged: BBoolean;
    public VehicleTryKeepTimeGap: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;
    public ObstacleDistance: ODset;

    constructor(VehicleTryKeepSpeed : BBoolean, ObstacleRelativeSpeed : RSset, CCInitialisationInProgress : BBoolean, ObstacleStatusJustChanged : BBoolean, VehicleTryKeepTimeGap : BBoolean, CruiseSpeedChangeInProgress : BBoolean, ObstacleDistance : ODset) {
        this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_CCInitialisationDelayFinished = this;
        let o2: _ProjectionRead__tr_CCInitialisationDelayFinished = other as _ProjectionRead__tr_CCInitialisationDelayFinished;
        return o1.VehicleTryKeepSpeed.equals(o2.VehicleTryKeepSpeed) && o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleTryKeepSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_CCInitialisationDelayFinished {

    public CCInitialisationInProgress: BBoolean;

    constructor(CCInitialisationInProgress : BBoolean) {
        this.CCInitialisationInProgress = CCInitialisationInProgress;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_CCInitialisationDelayFinished = this;
        let o2: _ProjectionWrite_CCInitialisationDelayFinished = other as _ProjectionWrite_CCInitialisationDelayFinished;
        return o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_CruiseSpeedChangeFinished {

    public ObstacleStatusJustChanged: BBoolean;
    public CCInitialisationInProgress: BBoolean;
    public ObstacleDistance: ODset;
    public ObstacleRelativeSpeed: RSset;
    public ObstaclePresent: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;

    constructor(ObstacleStatusJustChanged : BBoolean, CCInitialisationInProgress : BBoolean, ObstacleDistance : ODset, ObstacleRelativeSpeed : RSset, ObstaclePresent : BBoolean, CruiseSpeedChangeInProgress : BBoolean) {
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.ObstacleDistance = ObstacleDistance;
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstaclePresent = ObstaclePresent;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_CruiseSpeedChangeFinished = this;
        let o2: _ProjectionRead_CruiseSpeedChangeFinished = other as _ProjectionRead_CruiseSpeedChangeFinished;
        return o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.ObstacleDistance.equals(o2.ObstacleDistance) && o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstaclePresent.equals(o2.ObstaclePresent) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_CruiseSpeedChangeFinished {

    public ObstacleStatusJustChanged: BBoolean;
    public CCInitialisationInProgress: BBoolean;
    public ObstacleDistance: ODset;
    public ObstacleRelativeSpeed: RSset;
    public ObstaclePresent: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;

    constructor(ObstacleStatusJustChanged : BBoolean, CCInitialisationInProgress : BBoolean, ObstacleDistance : ODset, ObstacleRelativeSpeed : RSset, ObstaclePresent : BBoolean, CruiseSpeedChangeInProgress : BBoolean) {
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.ObstacleDistance = ObstacleDistance;
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstaclePresent = ObstaclePresent;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_CruiseSpeedChangeFinished = this;
        let o2: _ProjectionRead__tr_CruiseSpeedChangeFinished = other as _ProjectionRead__tr_CruiseSpeedChangeFinished;
        return o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.ObstacleDistance.equals(o2.ObstacleDistance) && o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstaclePresent.equals(o2.ObstaclePresent) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_CruiseSpeedChangeFinished {

    public VehicleTryKeepSpeed: BBoolean;
    public VehicleTryKeepTimeGap: BBoolean;

    constructor(VehicleTryKeepSpeed : BBoolean, VehicleTryKeepTimeGap : BBoolean) {
        this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_CruiseSpeedChangeFinished = this;
        let o2: _ProjectionWrite_CruiseSpeedChangeFinished = other as _ProjectionWrite_CruiseSpeedChangeFinished;
        return o1.VehicleTryKeepSpeed.equals(o2.VehicleTryKeepSpeed) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleTryKeepSpeed.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_CruiseSpeedChangeDelayFinished {

    public VehicleTryKeepSpeed: BBoolean;
    public ObstacleRelativeSpeed: RSset;
    public ObstacleStatusJustChanged: BBoolean;
    public CCInitialisationInProgress: BBoolean;
    public VehicleTryKeepTimeGap: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;
    public ObstacleDistance: ODset;

    constructor(VehicleTryKeepSpeed : BBoolean, ObstacleRelativeSpeed : RSset, ObstacleStatusJustChanged : BBoolean, CCInitialisationInProgress : BBoolean, VehicleTryKeepTimeGap : BBoolean, CruiseSpeedChangeInProgress : BBoolean, ObstacleDistance : ODset) {
        this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_CruiseSpeedChangeDelayFinished = this;
        let o2: _ProjectionRead_CruiseSpeedChangeDelayFinished = other as _ProjectionRead_CruiseSpeedChangeDelayFinished;
        return o1.VehicleTryKeepSpeed.equals(o2.VehicleTryKeepSpeed) && o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleTryKeepSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_CruiseSpeedChangeDelayFinished {

    public VehicleTryKeepSpeed: BBoolean;
    public ObstacleRelativeSpeed: RSset;
    public ObstacleStatusJustChanged: BBoolean;
    public CCInitialisationInProgress: BBoolean;
    public VehicleTryKeepTimeGap: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;
    public ObstacleDistance: ODset;

    constructor(VehicleTryKeepSpeed : BBoolean, ObstacleRelativeSpeed : RSset, ObstacleStatusJustChanged : BBoolean, CCInitialisationInProgress : BBoolean, VehicleTryKeepTimeGap : BBoolean, CruiseSpeedChangeInProgress : BBoolean, ObstacleDistance : ODset) {
        this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_CruiseSpeedChangeDelayFinished = this;
        let o2: _ProjectionRead__tr_CruiseSpeedChangeDelayFinished = other as _ProjectionRead__tr_CruiseSpeedChangeDelayFinished;
        return o1.VehicleTryKeepSpeed.equals(o2.VehicleTryKeepSpeed) && o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleTryKeepSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_CruiseSpeedChangeDelayFinished {

    public CruiseSpeedChangeInProgress: BBoolean;

    constructor(CruiseSpeedChangeInProgress : BBoolean) {
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_CruiseSpeedChangeDelayFinished = this;
        let o2: _ProjectionWrite_CruiseSpeedChangeDelayFinished = other as _ProjectionWrite_CruiseSpeedChangeDelayFinished;
        return o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_CruiseOff {

    public CruiseActive: BBoolean;

    constructor(CruiseActive : BBoolean) {
        this.CruiseActive = CruiseActive;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_CruiseOff = this;
        let o2: _ProjectionRead_CruiseOff = other as _ProjectionRead_CruiseOff;
        return o1.CruiseActive.equals(o2.CruiseActive);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_CruiseOff {

    public CruiseActive: BBoolean;

    constructor(CruiseActive : BBoolean) {
        this.CruiseActive = CruiseActive;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_CruiseOff = this;
        let o2: _ProjectionRead__tr_CruiseOff = other as _ProjectionRead__tr_CruiseOff;
        return o1.CruiseActive.equals(o2.CruiseActive);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_CruiseOff {

    public VehicleTryKeepSpeed: BBoolean;
    public CruiseSpeedAtMax: BBoolean;
    public CruiseActive: BBoolean;
    public VehicleAtCruiseSpeed: BBoolean;
    public ObstacleStatusJustChanged: BBoolean;
    public CCInitialisationInProgress: BBoolean;
    public NumberOfSetCruise: BInteger;
    public VehicleTryKeepTimeGap: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;
    public VehicleCanKeepSpeed: BBoolean;
    public ObstacleDistance: ODset;

    constructor(VehicleTryKeepSpeed : BBoolean, CruiseSpeedAtMax : BBoolean, CruiseActive : BBoolean, VehicleAtCruiseSpeed : BBoolean, ObstacleStatusJustChanged : BBoolean, CCInitialisationInProgress : BBoolean, NumberOfSetCruise : BInteger, VehicleTryKeepTimeGap : BBoolean, CruiseSpeedChangeInProgress : BBoolean, VehicleCanKeepSpeed : BBoolean, ObstacleDistance : ODset) {
        this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
        this.CruiseSpeedAtMax = CruiseSpeedAtMax;
        this.CruiseActive = CruiseActive;
        this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.NumberOfSetCruise = NumberOfSetCruise;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_CruiseOff = this;
        let o2: _ProjectionWrite_CruiseOff = other as _ProjectionWrite_CruiseOff;
        return o1.VehicleTryKeepSpeed.equals(o2.VehicleTryKeepSpeed) && o1.CruiseSpeedAtMax.equals(o2.CruiseSpeedAtMax) && o1.CruiseActive.equals(o2.CruiseActive) && o1.VehicleAtCruiseSpeed.equals(o2.VehicleAtCruiseSpeed) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.NumberOfSetCruise.equals(o2.NumberOfSetCruise) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress) && o1.VehicleCanKeepSpeed.equals(o2.VehicleCanKeepSpeed) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleTryKeepSpeed.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedAtMax.hashCode() << 1);
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.VehicleAtCruiseSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.NumberOfSetCruise.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        result = 31 * result + (this.VehicleCanKeepSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_ExternalForcesBecomesExtreme {

    public VehicleCanKeepSpeed: BBoolean;

    constructor(VehicleCanKeepSpeed : BBoolean) {
        this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_ExternalForcesBecomesExtreme = this;
        let o2: _ProjectionRead_ExternalForcesBecomesExtreme = other as _ProjectionRead_ExternalForcesBecomesExtreme;
        return o1.VehicleCanKeepSpeed.equals(o2.VehicleCanKeepSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleCanKeepSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_ExternalForcesBecomesExtreme {

    public VehicleCanKeepSpeed: BBoolean;

    constructor(VehicleCanKeepSpeed : BBoolean) {
        this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_ExternalForcesBecomesExtreme = this;
        let o2: _ProjectionRead__tr_ExternalForcesBecomesExtreme = other as _ProjectionRead__tr_ExternalForcesBecomesExtreme;
        return o1.VehicleCanKeepSpeed.equals(o2.VehicleCanKeepSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleCanKeepSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_ExternalForcesBecomesExtreme {

    public VehicleCanKeepSpeed: BBoolean;

    constructor(VehicleCanKeepSpeed : BBoolean) {
        this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_ExternalForcesBecomesExtreme = this;
        let o2: _ProjectionWrite_ExternalForcesBecomesExtreme = other as _ProjectionWrite_ExternalForcesBecomesExtreme;
        return o1.VehicleCanKeepSpeed.equals(o2.VehicleCanKeepSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleCanKeepSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_ExternalForcesBecomesNormal {

    public CruiseActive: BBoolean;
    public VehicleCanKeepSpeed: BBoolean;

    constructor(CruiseActive : BBoolean, VehicleCanKeepSpeed : BBoolean) {
        this.CruiseActive = CruiseActive;
        this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_ExternalForcesBecomesNormal = this;
        let o2: _ProjectionRead_ExternalForcesBecomesNormal = other as _ProjectionRead_ExternalForcesBecomesNormal;
        return o1.CruiseActive.equals(o2.CruiseActive) && o1.VehicleCanKeepSpeed.equals(o2.VehicleCanKeepSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.VehicleCanKeepSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_ExternalForcesBecomesNormal {

    public CruiseActive: BBoolean;
    public VehicleCanKeepSpeed: BBoolean;

    constructor(CruiseActive : BBoolean, VehicleCanKeepSpeed : BBoolean) {
        this.CruiseActive = CruiseActive;
        this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_ExternalForcesBecomesNormal = this;
        let o2: _ProjectionRead__tr_ExternalForcesBecomesNormal = other as _ProjectionRead__tr_ExternalForcesBecomesNormal;
        return o1.CruiseActive.equals(o2.CruiseActive) && o1.VehicleCanKeepSpeed.equals(o2.VehicleCanKeepSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.VehicleCanKeepSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_ExternalForcesBecomesNormal {

    public VehicleCanKeepSpeed: BBoolean;

    constructor(VehicleCanKeepSpeed : BBoolean) {
        this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_ExternalForcesBecomesNormal = this;
        let o2: _ProjectionWrite_ExternalForcesBecomesNormal = other as _ProjectionWrite_ExternalForcesBecomesNormal;
        return o1.VehicleCanKeepSpeed.equals(o2.VehicleCanKeepSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleCanKeepSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_VehicleLeavesCruiseSpeed {

    public VehicleTryKeepSpeed: BBoolean;
    public VehicleAtCruiseSpeed: BBoolean;
    public VehicleCanKeepSpeed: BBoolean;

    constructor(VehicleTryKeepSpeed : BBoolean, VehicleAtCruiseSpeed : BBoolean, VehicleCanKeepSpeed : BBoolean) {
        this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
        this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
        this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_VehicleLeavesCruiseSpeed = this;
        let o2: _ProjectionRead_VehicleLeavesCruiseSpeed = other as _ProjectionRead_VehicleLeavesCruiseSpeed;
        return o1.VehicleTryKeepSpeed.equals(o2.VehicleTryKeepSpeed) && o1.VehicleAtCruiseSpeed.equals(o2.VehicleAtCruiseSpeed) && o1.VehicleCanKeepSpeed.equals(o2.VehicleCanKeepSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleTryKeepSpeed.hashCode() << 1);
        result = 31 * result + (this.VehicleAtCruiseSpeed.hashCode() << 1);
        result = 31 * result + (this.VehicleCanKeepSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_VehicleLeavesCruiseSpeed {

    public VehicleTryKeepSpeed: BBoolean;
    public VehicleAtCruiseSpeed: BBoolean;
    public VehicleCanKeepSpeed: BBoolean;

    constructor(VehicleTryKeepSpeed : BBoolean, VehicleAtCruiseSpeed : BBoolean, VehicleCanKeepSpeed : BBoolean) {
        this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
        this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
        this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_VehicleLeavesCruiseSpeed = this;
        let o2: _ProjectionRead__tr_VehicleLeavesCruiseSpeed = other as _ProjectionRead__tr_VehicleLeavesCruiseSpeed;
        return o1.VehicleTryKeepSpeed.equals(o2.VehicleTryKeepSpeed) && o1.VehicleAtCruiseSpeed.equals(o2.VehicleAtCruiseSpeed) && o1.VehicleCanKeepSpeed.equals(o2.VehicleCanKeepSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleTryKeepSpeed.hashCode() << 1);
        result = 31 * result + (this.VehicleAtCruiseSpeed.hashCode() << 1);
        result = 31 * result + (this.VehicleCanKeepSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_VehicleLeavesCruiseSpeed {

    public VehicleAtCruiseSpeed: BBoolean;

    constructor(VehicleAtCruiseSpeed : BBoolean) {
        this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_VehicleLeavesCruiseSpeed = this;
        let o2: _ProjectionWrite_VehicleLeavesCruiseSpeed = other as _ProjectionWrite_VehicleLeavesCruiseSpeed;
        return o1.VehicleAtCruiseSpeed.equals(o2.VehicleAtCruiseSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleAtCruiseSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_VehicleReachesCruiseSpeed {

    public CruiseActive: BBoolean;
    public VehicleAtCruiseSpeed: BBoolean;
    public SpeedAboveMax: BBoolean;

    constructor(CruiseActive : BBoolean, VehicleAtCruiseSpeed : BBoolean, SpeedAboveMax : BBoolean) {
        this.CruiseActive = CruiseActive;
        this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
        this.SpeedAboveMax = SpeedAboveMax;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_VehicleReachesCruiseSpeed = this;
        let o2: _ProjectionRead_VehicleReachesCruiseSpeed = other as _ProjectionRead_VehicleReachesCruiseSpeed;
        return o1.CruiseActive.equals(o2.CruiseActive) && o1.VehicleAtCruiseSpeed.equals(o2.VehicleAtCruiseSpeed) && o1.SpeedAboveMax.equals(o2.SpeedAboveMax);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.VehicleAtCruiseSpeed.hashCode() << 1);
        result = 31 * result + (this.SpeedAboveMax.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_VehicleReachesCruiseSpeed {

    public CruiseActive: BBoolean;
    public VehicleAtCruiseSpeed: BBoolean;
    public SpeedAboveMax: BBoolean;

    constructor(CruiseActive : BBoolean, VehicleAtCruiseSpeed : BBoolean, SpeedAboveMax : BBoolean) {
        this.CruiseActive = CruiseActive;
        this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
        this.SpeedAboveMax = SpeedAboveMax;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_VehicleReachesCruiseSpeed = this;
        let o2: _ProjectionRead__tr_VehicleReachesCruiseSpeed = other as _ProjectionRead__tr_VehicleReachesCruiseSpeed;
        return o1.CruiseActive.equals(o2.CruiseActive) && o1.VehicleAtCruiseSpeed.equals(o2.VehicleAtCruiseSpeed) && o1.SpeedAboveMax.equals(o2.SpeedAboveMax);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.VehicleAtCruiseSpeed.hashCode() << 1);
        result = 31 * result + (this.SpeedAboveMax.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_VehicleReachesCruiseSpeed {

    public VehicleAtCruiseSpeed: BBoolean;

    constructor(VehicleAtCruiseSpeed : BBoolean) {
        this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_VehicleReachesCruiseSpeed = this;
        let o2: _ProjectionWrite_VehicleReachesCruiseSpeed = other as _ProjectionWrite_VehicleReachesCruiseSpeed;
        return o1.VehicleAtCruiseSpeed.equals(o2.VehicleAtCruiseSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleAtCruiseSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_VehicleExceedsMaxCruiseSpeed {

    public CruiseActive: BBoolean;
    public SpeedAboveMax: BBoolean;
    public ObstacleStatusJustChanged: BBoolean;
    public CCInitialisationInProgress: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;
    public VehicleCanKeepSpeed: BBoolean;

    constructor(CruiseActive : BBoolean, SpeedAboveMax : BBoolean, ObstacleStatusJustChanged : BBoolean, CCInitialisationInProgress : BBoolean, CruiseSpeedChangeInProgress : BBoolean, VehicleCanKeepSpeed : BBoolean) {
        this.CruiseActive = CruiseActive;
        this.SpeedAboveMax = SpeedAboveMax;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_VehicleExceedsMaxCruiseSpeed = this;
        let o2: _ProjectionRead_VehicleExceedsMaxCruiseSpeed = other as _ProjectionRead_VehicleExceedsMaxCruiseSpeed;
        return o1.CruiseActive.equals(o2.CruiseActive) && o1.SpeedAboveMax.equals(o2.SpeedAboveMax) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress) && o1.VehicleCanKeepSpeed.equals(o2.VehicleCanKeepSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.SpeedAboveMax.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        result = 31 * result + (this.VehicleCanKeepSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed {

    public CruiseActive: BBoolean;
    public SpeedAboveMax: BBoolean;
    public ObstacleStatusJustChanged: BBoolean;
    public CCInitialisationInProgress: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;
    public VehicleCanKeepSpeed: BBoolean;

    constructor(CruiseActive : BBoolean, SpeedAboveMax : BBoolean, ObstacleStatusJustChanged : BBoolean, CCInitialisationInProgress : BBoolean, CruiseSpeedChangeInProgress : BBoolean, VehicleCanKeepSpeed : BBoolean) {
        this.CruiseActive = CruiseActive;
        this.SpeedAboveMax = SpeedAboveMax;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed = this;
        let o2: _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed = other as _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed;
        return o1.CruiseActive.equals(o2.CruiseActive) && o1.SpeedAboveMax.equals(o2.SpeedAboveMax) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress) && o1.VehicleCanKeepSpeed.equals(o2.VehicleCanKeepSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.SpeedAboveMax.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        result = 31 * result + (this.VehicleCanKeepSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_VehicleExceedsMaxCruiseSpeed {

    public VehicleAtCruiseSpeed: BBoolean;
    public SpeedAboveMax: BBoolean;

    constructor(VehicleAtCruiseSpeed : BBoolean, SpeedAboveMax : BBoolean) {
        this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
        this.SpeedAboveMax = SpeedAboveMax;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_VehicleExceedsMaxCruiseSpeed = this;
        let o2: _ProjectionWrite_VehicleExceedsMaxCruiseSpeed = other as _ProjectionWrite_VehicleExceedsMaxCruiseSpeed;
        return o1.VehicleAtCruiseSpeed.equals(o2.VehicleAtCruiseSpeed) && o1.SpeedAboveMax.equals(o2.SpeedAboveMax);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleAtCruiseSpeed.hashCode() << 1);
        result = 31 * result + (this.SpeedAboveMax.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed {

    public CruiseSpeedAtMax: BBoolean;
    public CruiseActive: BBoolean;
    public SpeedAboveMax: BBoolean;

    constructor(CruiseSpeedAtMax : BBoolean, CruiseActive : BBoolean, SpeedAboveMax : BBoolean) {
        this.CruiseSpeedAtMax = CruiseSpeedAtMax;
        this.CruiseActive = CruiseActive;
        this.SpeedAboveMax = SpeedAboveMax;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed = this;
        let o2: _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed = other as _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed;
        return o1.CruiseSpeedAtMax.equals(o2.CruiseSpeedAtMax) && o1.CruiseActive.equals(o2.CruiseActive) && o1.SpeedAboveMax.equals(o2.SpeedAboveMax);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseSpeedAtMax.hashCode() << 1);
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.SpeedAboveMax.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed {

    public SpeedAboveMax: BBoolean;

    constructor(SpeedAboveMax : BBoolean) {
        this.SpeedAboveMax = SpeedAboveMax;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed = this;
        let o2: _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed = other as _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed;
        return o1.SpeedAboveMax.equals(o2.SpeedAboveMax);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.SpeedAboveMax.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed {

    public VehicleAtCruiseSpeed: BBoolean;
    public SpeedAboveMax: BBoolean;

    constructor(VehicleAtCruiseSpeed : BBoolean, SpeedAboveMax : BBoolean) {
        this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
        this.SpeedAboveMax = SpeedAboveMax;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed = this;
        let o2: _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed = other as _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed;
        return o1.VehicleAtCruiseSpeed.equals(o2.VehicleAtCruiseSpeed) && o1.SpeedAboveMax.equals(o2.SpeedAboveMax);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleAtCruiseSpeed.hashCode() << 1);
        result = 31 * result + (this.SpeedAboveMax.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_ObstacleDistanceBecomesVeryClose {

    public ObstacleRelativeSpeed: RSset;
    public ObstacleDistance: ODset;

    constructor(ObstacleRelativeSpeed : RSset, ObstacleDistance : ODset) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_ObstacleDistanceBecomesVeryClose = this;
        let o2: _ProjectionRead_ObstacleDistanceBecomesVeryClose = other as _ProjectionRead_ObstacleDistanceBecomesVeryClose;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose {

    public ObstacleRelativeSpeed: RSset;
    public ObstacleDistance: ODset;

    constructor(ObstacleRelativeSpeed : RSset, ObstacleDistance : ODset) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose = this;
        let o2: _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose = other as _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_ObstacleDistanceBecomesVeryClose {

    public ObstacleStatusJustChanged: BBoolean;
    public ObstacleDistance: ODset;

    constructor(ObstacleStatusJustChanged : BBoolean, ObstacleDistance : ODset) {
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_ObstacleDistanceBecomesVeryClose = this;
        let o2: _ProjectionWrite_ObstacleDistanceBecomesVeryClose = other as _ProjectionWrite_ObstacleDistanceBecomesVeryClose;
        return o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_ObstacleDistanceBecomesClose {

    public ObstacleRelativeSpeed: RSset;
    public CruiseActive: BBoolean;
    public ObstaclePresent: BBoolean;
    public ObstacleDistance: ODset;

    constructor(ObstacleRelativeSpeed : RSset, CruiseActive : BBoolean, ObstaclePresent : BBoolean, ObstacleDistance : ODset) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.CruiseActive = CruiseActive;
        this.ObstaclePresent = ObstaclePresent;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_ObstacleDistanceBecomesClose = this;
        let o2: _ProjectionRead_ObstacleDistanceBecomesClose = other as _ProjectionRead_ObstacleDistanceBecomesClose;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.CruiseActive.equals(o2.CruiseActive) && o1.ObstaclePresent.equals(o2.ObstaclePresent) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_ObstacleDistanceBecomesClose {

    public ObstacleRelativeSpeed: RSset;
    public CruiseActive: BBoolean;
    public ObstaclePresent: BBoolean;
    public ObstacleDistance: ODset;

    constructor(ObstacleRelativeSpeed : RSset, CruiseActive : BBoolean, ObstaclePresent : BBoolean, ObstacleDistance : ODset) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.CruiseActive = CruiseActive;
        this.ObstaclePresent = ObstaclePresent;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_ObstacleDistanceBecomesClose = this;
        let o2: _ProjectionRead__tr_ObstacleDistanceBecomesClose = other as _ProjectionRead__tr_ObstacleDistanceBecomesClose;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.CruiseActive.equals(o2.CruiseActive) && o1.ObstaclePresent.equals(o2.ObstaclePresent) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_ObstacleDistanceBecomesClose {

    public ObstacleStatusJustChanged: BBoolean;
    public VehicleTryKeepTimeGap: BBoolean;
    public ObstacleDistance: ODset;

    constructor(ObstacleStatusJustChanged : BBoolean, VehicleTryKeepTimeGap : BBoolean, ObstacleDistance : ODset) {
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_ObstacleDistanceBecomesClose = this;
        let o2: _ProjectionWrite_ObstacleDistanceBecomesClose = other as _ProjectionWrite_ObstacleDistanceBecomesClose;
        return o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_ObstacleDistanceBecomesBig {

    public ObstacleRelativeSpeed: RSset;
    public ObstacleDistance: ODset;

    constructor(ObstacleRelativeSpeed : RSset, ObstacleDistance : ODset) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_ObstacleDistanceBecomesBig = this;
        let o2: _ProjectionRead_ObstacleDistanceBecomesBig = other as _ProjectionRead_ObstacleDistanceBecomesBig;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_ObstacleDistanceBecomesBig {

    public ObstacleRelativeSpeed: RSset;
    public ObstacleDistance: ODset;

    constructor(ObstacleRelativeSpeed : RSset, ObstacleDistance : ODset) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_ObstacleDistanceBecomesBig = this;
        let o2: _ProjectionRead__tr_ObstacleDistanceBecomesBig = other as _ProjectionRead__tr_ObstacleDistanceBecomesBig;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_ObstacleDistanceBecomesBig {

    public ObstacleStatusJustChanged: BBoolean;
    public VehicleTryKeepTimeGap: BBoolean;
    public ObstacleDistance: ODset;

    constructor(ObstacleStatusJustChanged : BBoolean, VehicleTryKeepTimeGap : BBoolean, ObstacleDistance : ODset) {
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_ObstacleDistanceBecomesBig = this;
        let o2: _ProjectionWrite_ObstacleDistanceBecomesBig = other as _ProjectionWrite_ObstacleDistanceBecomesBig;
        return o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_ObstacleStartsTravelFaster {

    public ObstacleRelativeSpeed: RSset;
    public CruiseActive: BBoolean;
    public ObstaclePresent: BBoolean;
    public ObstacleDistance: ODset;

    constructor(ObstacleRelativeSpeed : RSset, CruiseActive : BBoolean, ObstaclePresent : BBoolean, ObstacleDistance : ODset) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.CruiseActive = CruiseActive;
        this.ObstaclePresent = ObstaclePresent;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_ObstacleStartsTravelFaster = this;
        let o2: _ProjectionRead_ObstacleStartsTravelFaster = other as _ProjectionRead_ObstacleStartsTravelFaster;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.CruiseActive.equals(o2.CruiseActive) && o1.ObstaclePresent.equals(o2.ObstaclePresent) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_ObstacleStartsTravelFaster {

    public ObstacleRelativeSpeed: RSset;
    public ObstaclePresent: BBoolean;

    constructor(ObstacleRelativeSpeed : RSset, ObstaclePresent : BBoolean) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstaclePresent = ObstaclePresent;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_ObstacleStartsTravelFaster = this;
        let o2: _ProjectionRead__tr_ObstacleStartsTravelFaster = other as _ProjectionRead__tr_ObstacleStartsTravelFaster;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstaclePresent.equals(o2.ObstaclePresent);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_ObstacleStartsTravelFaster {

    public ObstacleRelativeSpeed: RSset;
    public ObstacleStatusJustChanged: BBoolean;
    public VehicleTryKeepTimeGap: BBoolean;

    constructor(ObstacleRelativeSpeed : RSset, ObstacleStatusJustChanged : BBoolean, VehicleTryKeepTimeGap : BBoolean) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_ObstacleStartsTravelFaster = this;
        let o2: _ProjectionWrite_ObstacleStartsTravelFaster = other as _ProjectionWrite_ObstacleStartsTravelFaster;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_ObstacleStopsTravelFaster {

    public ObstacleRelativeSpeed: RSset;
    public CruiseActive: BBoolean;

    constructor(ObstacleRelativeSpeed : RSset, CruiseActive : BBoolean) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.CruiseActive = CruiseActive;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_ObstacleStopsTravelFaster = this;
        let o2: _ProjectionRead_ObstacleStopsTravelFaster = other as _ProjectionRead_ObstacleStopsTravelFaster;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.CruiseActive.equals(o2.CruiseActive);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_ObstacleStopsTravelFaster {

    public ObstacleRelativeSpeed: RSset;

    constructor(ObstacleRelativeSpeed : RSset) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_ObstacleStopsTravelFaster = this;
        let o2: _ProjectionRead__tr_ObstacleStopsTravelFaster = other as _ProjectionRead__tr_ObstacleStopsTravelFaster;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_ObstacleStopsTravelFaster {

    public ObstacleRelativeSpeed: RSset;
    public ObstacleStatusJustChanged: BBoolean;

    constructor(ObstacleRelativeSpeed : RSset, ObstacleStatusJustChanged : BBoolean) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_ObstacleStopsTravelFaster = this;
        let o2: _ProjectionWrite_ObstacleStopsTravelFaster = other as _ProjectionWrite_ObstacleStopsTravelFaster;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_ObstacleStartsTravelSlower {

    public ObstacleRelativeSpeed: RSset;
    public CruiseActive: BBoolean;

    constructor(ObstacleRelativeSpeed : RSset, CruiseActive : BBoolean) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.CruiseActive = CruiseActive;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_ObstacleStartsTravelSlower = this;
        let o2: _ProjectionRead_ObstacleStartsTravelSlower = other as _ProjectionRead_ObstacleStartsTravelSlower;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.CruiseActive.equals(o2.CruiseActive);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_ObstacleStartsTravelSlower {

    public ObstacleRelativeSpeed: RSset;

    constructor(ObstacleRelativeSpeed : RSset) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_ObstacleStartsTravelSlower = this;
        let o2: _ProjectionRead__tr_ObstacleStartsTravelSlower = other as _ProjectionRead__tr_ObstacleStartsTravelSlower;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_ObstacleStartsTravelSlower {

    public ObstacleRelativeSpeed: RSset;
    public ObstacleStatusJustChanged: BBoolean;

    constructor(ObstacleRelativeSpeed : RSset, ObstacleStatusJustChanged : BBoolean) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_ObstacleStartsTravelSlower = this;
        let o2: _ProjectionWrite_ObstacleStartsTravelSlower = other as _ProjectionWrite_ObstacleStartsTravelSlower;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_ObstacleStopsTravelSlower {

    public ObstacleRelativeSpeed: RSset;
    public CruiseActive: BBoolean;

    constructor(ObstacleRelativeSpeed : RSset, CruiseActive : BBoolean) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.CruiseActive = CruiseActive;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_ObstacleStopsTravelSlower = this;
        let o2: _ProjectionRead_ObstacleStopsTravelSlower = other as _ProjectionRead_ObstacleStopsTravelSlower;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.CruiseActive.equals(o2.CruiseActive);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_ObstacleStopsTravelSlower {

    public ObstacleRelativeSpeed: RSset;

    constructor(ObstacleRelativeSpeed : RSset) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_ObstacleStopsTravelSlower = this;
        let o2: _ProjectionRead__tr_ObstacleStopsTravelSlower = other as _ProjectionRead__tr_ObstacleStopsTravelSlower;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_ObstacleStopsTravelSlower {

    public ObstacleRelativeSpeed: RSset;
    public ObstacleStatusJustChanged: BBoolean;

    constructor(ObstacleRelativeSpeed : RSset, ObstacleStatusJustChanged : BBoolean) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_ObstacleStopsTravelSlower = this;
        let o2: _ProjectionWrite_ObstacleStopsTravelSlower = other as _ProjectionWrite_ObstacleStopsTravelSlower;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_ObstacleAppearsWhenCruiseActive {

    public CruiseActive: BBoolean;
    public ObstaclePresent: BBoolean;

    constructor(CruiseActive : BBoolean, ObstaclePresent : BBoolean) {
        this.CruiseActive = CruiseActive;
        this.ObstaclePresent = ObstaclePresent;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_ObstacleAppearsWhenCruiseActive = this;
        let o2: _ProjectionRead_ObstacleAppearsWhenCruiseActive = other as _ProjectionRead_ObstacleAppearsWhenCruiseActive;
        return o1.CruiseActive.equals(o2.CruiseActive) && o1.ObstaclePresent.equals(o2.ObstaclePresent);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive {

    public CruiseActive: BBoolean;
    public ObstaclePresent: BBoolean;

    constructor(CruiseActive : BBoolean, ObstaclePresent : BBoolean) {
        this.CruiseActive = CruiseActive;
        this.ObstaclePresent = ObstaclePresent;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive = this;
        let o2: _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive = other as _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive;
        return o1.CruiseActive.equals(o2.CruiseActive) && o1.ObstaclePresent.equals(o2.ObstaclePresent);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_ObstacleAppearsWhenCruiseActive {

    public ObstacleRelativeSpeed: RSset;
    public ObstaclePresent: BBoolean;
    public ObstacleStatusJustChanged: BBoolean;
    public ObstacleDistance: ODset;

    constructor(ObstacleRelativeSpeed : RSset, ObstaclePresent : BBoolean, ObstacleStatusJustChanged : BBoolean, ObstacleDistance : ODset) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstaclePresent = ObstaclePresent;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_ObstacleAppearsWhenCruiseActive = this;
        let o2: _ProjectionWrite_ObstacleAppearsWhenCruiseActive = other as _ProjectionWrite_ObstacleAppearsWhenCruiseActive;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstaclePresent.equals(o2.ObstaclePresent) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_ObstacleAppearsWhenCruiseInactive {

    public CruiseActive: BBoolean;
    public ObstaclePresent: BBoolean;

    constructor(CruiseActive : BBoolean, ObstaclePresent : BBoolean) {
        this.CruiseActive = CruiseActive;
        this.ObstaclePresent = ObstaclePresent;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_ObstacleAppearsWhenCruiseInactive = this;
        let o2: _ProjectionRead_ObstacleAppearsWhenCruiseInactive = other as _ProjectionRead_ObstacleAppearsWhenCruiseInactive;
        return o1.CruiseActive.equals(o2.CruiseActive) && o1.ObstaclePresent.equals(o2.ObstaclePresent);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive {

    public CruiseActive: BBoolean;
    public ObstaclePresent: BBoolean;

    constructor(CruiseActive : BBoolean, ObstaclePresent : BBoolean) {
        this.CruiseActive = CruiseActive;
        this.ObstaclePresent = ObstaclePresent;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive = this;
        let o2: _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive = other as _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive;
        return o1.CruiseActive.equals(o2.CruiseActive) && o1.ObstaclePresent.equals(o2.ObstaclePresent);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_ObstacleAppearsWhenCruiseInactive {

    public ObstacleRelativeSpeed: RSset;
    public ObstaclePresent: BBoolean;
    public ObstacleDistance: ODset;

    constructor(ObstacleRelativeSpeed : RSset, ObstaclePresent : BBoolean, ObstacleDistance : ODset) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstaclePresent = ObstaclePresent;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_ObstacleAppearsWhenCruiseInactive = this;
        let o2: _ProjectionWrite_ObstacleAppearsWhenCruiseInactive = other as _ProjectionWrite_ObstacleAppearsWhenCruiseInactive;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstaclePresent.equals(o2.ObstaclePresent) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_ObstacleDisappears {

    public CruiseActive: BBoolean;
    public ObstaclePresent: BBoolean;

    constructor(CruiseActive : BBoolean, ObstaclePresent : BBoolean) {
        this.CruiseActive = CruiseActive;
        this.ObstaclePresent = ObstaclePresent;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_ObstacleDisappears = this;
        let o2: _ProjectionRead_ObstacleDisappears = other as _ProjectionRead_ObstacleDisappears;
        return o1.CruiseActive.equals(o2.CruiseActive) && o1.ObstaclePresent.equals(o2.ObstaclePresent);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_ObstacleDisappears {

    public ObstaclePresent: BBoolean;

    constructor(ObstaclePresent : BBoolean) {
        this.ObstaclePresent = ObstaclePresent;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_ObstacleDisappears = this;
        let o2: _ProjectionRead__tr_ObstacleDisappears = other as _ProjectionRead__tr_ObstacleDisappears;
        return o1.ObstaclePresent.equals(o2.ObstaclePresent);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_ObstacleDisappears {

    public ObstacleRelativeSpeed: RSset;
    public ObstaclePresent: BBoolean;
    public ObstacleStatusJustChanged: BBoolean;
    public VehicleTryKeepTimeGap: BBoolean;
    public ObstacleDistance: ODset;

    constructor(ObstacleRelativeSpeed : RSset, ObstaclePresent : BBoolean, ObstacleStatusJustChanged : BBoolean, VehicleTryKeepTimeGap : BBoolean, ObstacleDistance : ODset) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstaclePresent = ObstaclePresent;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_ObstacleDisappears = this;
        let o2: _ProjectionWrite_ObstacleDisappears = other as _ProjectionWrite_ObstacleDisappears;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstaclePresent.equals(o2.ObstaclePresent) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_VehicleManageObstacle {

    public CCInitialisationInProgress: BBoolean;
    public ObstacleStatusJustChanged: BBoolean;
    public ObstacleDistance: ODset;
    public ObstacleRelativeSpeed: RSset;
    public ObstaclePresent: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;

    constructor(CCInitialisationInProgress : BBoolean, ObstacleStatusJustChanged : BBoolean, ObstacleDistance : ODset, ObstacleRelativeSpeed : RSset, ObstaclePresent : BBoolean, CruiseSpeedChangeInProgress : BBoolean) {
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.ObstacleDistance = ObstacleDistance;
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstaclePresent = ObstaclePresent;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_VehicleManageObstacle = this;
        let o2: _ProjectionRead_VehicleManageObstacle = other as _ProjectionRead_VehicleManageObstacle;
        return o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.ObstacleDistance.equals(o2.ObstacleDistance) && o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstaclePresent.equals(o2.ObstaclePresent) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_VehicleManageObstacle {

    public CCInitialisationInProgress: BBoolean;
    public ObstacleStatusJustChanged: BBoolean;
    public ObstacleDistance: ODset;
    public ObstacleRelativeSpeed: RSset;
    public ObstaclePresent: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;

    constructor(CCInitialisationInProgress : BBoolean, ObstacleStatusJustChanged : BBoolean, ObstacleDistance : ODset, ObstacleRelativeSpeed : RSset, ObstaclePresent : BBoolean, CruiseSpeedChangeInProgress : BBoolean) {
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.ObstacleDistance = ObstacleDistance;
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstaclePresent = ObstaclePresent;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_VehicleManageObstacle = this;
        let o2: _ProjectionRead__tr_VehicleManageObstacle = other as _ProjectionRead__tr_VehicleManageObstacle;
        return o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.ObstacleDistance.equals(o2.ObstacleDistance) && o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstaclePresent.equals(o2.ObstaclePresent) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_VehicleManageObstacle {

    public VehicleTryKeepSpeed: BBoolean;
    public VehicleTryKeepTimeGap: BBoolean;

    constructor(VehicleTryKeepSpeed : BBoolean, VehicleTryKeepTimeGap : BBoolean) {
        this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_VehicleManageObstacle = this;
        let o2: _ProjectionWrite_VehicleManageObstacle = other as _ProjectionWrite_VehicleManageObstacle;
        return o1.VehicleTryKeepSpeed.equals(o2.VehicleTryKeepSpeed) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleTryKeepSpeed.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_ObstacleBecomesOld {

    public VehicleTryKeepSpeed: BBoolean;
    public ObstacleRelativeSpeed: RSset;
    public ObstacleStatusJustChanged: BBoolean;
    public CCInitialisationInProgress: BBoolean;
    public VehicleTryKeepTimeGap: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;
    public ObstacleDistance: ODset;

    constructor(VehicleTryKeepSpeed : BBoolean, ObstacleRelativeSpeed : RSset, ObstacleStatusJustChanged : BBoolean, CCInitialisationInProgress : BBoolean, VehicleTryKeepTimeGap : BBoolean, CruiseSpeedChangeInProgress : BBoolean, ObstacleDistance : ODset) {
        this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_ObstacleBecomesOld = this;
        let o2: _ProjectionRead_ObstacleBecomesOld = other as _ProjectionRead_ObstacleBecomesOld;
        return o1.VehicleTryKeepSpeed.equals(o2.VehicleTryKeepSpeed) && o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleTryKeepSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_ObstacleBecomesOld {

    public VehicleTryKeepSpeed: BBoolean;
    public ObstacleRelativeSpeed: RSset;
    public ObstacleStatusJustChanged: BBoolean;
    public CCInitialisationInProgress: BBoolean;
    public VehicleTryKeepTimeGap: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;
    public ObstacleDistance: ODset;

    constructor(VehicleTryKeepSpeed : BBoolean, ObstacleRelativeSpeed : RSset, ObstacleStatusJustChanged : BBoolean, CCInitialisationInProgress : BBoolean, VehicleTryKeepTimeGap : BBoolean, CruiseSpeedChangeInProgress : BBoolean, ObstacleDistance : ODset) {
        this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_ObstacleBecomesOld = this;
        let o2: _ProjectionRead__tr_ObstacleBecomesOld = other as _ProjectionRead__tr_ObstacleBecomesOld;
        return o1.VehicleTryKeepSpeed.equals(o2.VehicleTryKeepSpeed) && o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleTryKeepSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_ObstacleBecomesOld {

    public ObstacleStatusJustChanged: BBoolean;

    constructor(ObstacleStatusJustChanged : BBoolean) {
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_ObstacleBecomesOld = this;
        let o2: _ProjectionWrite_ObstacleBecomesOld = other as _ProjectionWrite_ObstacleBecomesOld;
        return o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_1 {

    public CruiseAllowed: BBoolean;

    constructor(CruiseAllowed : BBoolean) {
        this.CruiseAllowed = CruiseAllowed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_1 = this;
        let o2: _ProjectionRead__check_inv_1 = other as _ProjectionRead__check_inv_1;
        return o1.CruiseAllowed.equals(o2.CruiseAllowed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseAllowed.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_2 {

    public CruiseActive: BBoolean;

    constructor(CruiseActive : BBoolean) {
        this.CruiseActive = CruiseActive;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_2 = this;
        let o2: _ProjectionRead__check_inv_2 = other as _ProjectionRead__check_inv_2;
        return o1.CruiseActive.equals(o2.CruiseActive);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_3 {

    public VehicleAtCruiseSpeed: BBoolean;

    constructor(VehicleAtCruiseSpeed : BBoolean) {
        this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_3 = this;
        let o2: _ProjectionRead__check_inv_3 = other as _ProjectionRead__check_inv_3;
        return o1.VehicleAtCruiseSpeed.equals(o2.VehicleAtCruiseSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleAtCruiseSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_4 {

    public VehicleCanKeepSpeed: BBoolean;

    constructor(VehicleCanKeepSpeed : BBoolean) {
        this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_4 = this;
        let o2: _ProjectionRead__check_inv_4 = other as _ProjectionRead__check_inv_4;
        return o1.VehicleCanKeepSpeed.equals(o2.VehicleCanKeepSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleCanKeepSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_5 {

    public VehicleTryKeepSpeed: BBoolean;

    constructor(VehicleTryKeepSpeed : BBoolean) {
        this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_5 = this;
        let o2: _ProjectionRead__check_inv_5 = other as _ProjectionRead__check_inv_5;
        return o1.VehicleTryKeepSpeed.equals(o2.VehicleTryKeepSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleTryKeepSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_6 {

    public SpeedAboveMax: BBoolean;

    constructor(SpeedAboveMax : BBoolean) {
        this.SpeedAboveMax = SpeedAboveMax;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_6 = this;
        let o2: _ProjectionRead__check_inv_6 = other as _ProjectionRead__check_inv_6;
        return o1.SpeedAboveMax.equals(o2.SpeedAboveMax);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.SpeedAboveMax.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_7 {

    public VehicleTryKeepTimeGap: BBoolean;

    constructor(VehicleTryKeepTimeGap : BBoolean) {
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_7 = this;
        let o2: _ProjectionRead__check_inv_7 = other as _ProjectionRead__check_inv_7;
        return o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_8 {

    public CruiseSpeedAtMax: BBoolean;

    constructor(CruiseSpeedAtMax : BBoolean) {
        this.CruiseSpeedAtMax = CruiseSpeedAtMax;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_8 = this;
        let o2: _ProjectionRead__check_inv_8 = other as _ProjectionRead__check_inv_8;
        return o1.CruiseSpeedAtMax.equals(o2.CruiseSpeedAtMax);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseSpeedAtMax.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_9 {

    public NumberOfSetCruise: BInteger;

    constructor(NumberOfSetCruise : BInteger) {
        this.NumberOfSetCruise = NumberOfSetCruise;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_9 = this;
        let o2: _ProjectionRead__check_inv_9 = other as _ProjectionRead__check_inv_9;
        return o1.NumberOfSetCruise.equals(o2.NumberOfSetCruise);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.NumberOfSetCruise.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_10 {

    public NumberOfSetCruise: BInteger;

    constructor(NumberOfSetCruise : BInteger) {
        this.NumberOfSetCruise = NumberOfSetCruise;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_10 = this;
        let o2: _ProjectionRead__check_inv_10 = other as _ProjectionRead__check_inv_10;
        return o1.NumberOfSetCruise.equals(o2.NumberOfSetCruise);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.NumberOfSetCruise.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_11 {

    public ObstaclePresent: BBoolean;

    constructor(ObstaclePresent : BBoolean) {
        this.ObstaclePresent = ObstaclePresent;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_11 = this;
        let o2: _ProjectionRead__check_inv_11 = other as _ProjectionRead__check_inv_11;
        return o1.ObstaclePresent.equals(o2.ObstaclePresent);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_12 {

    public ObstacleDistance: ODset;

    constructor(ObstacleDistance : ODset) {
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_12 = this;
        let o2: _ProjectionRead__check_inv_12 = other as _ProjectionRead__check_inv_12;
        return o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_13 {

    public ObstacleRelativeSpeed: RSset;

    constructor(ObstacleRelativeSpeed : RSset) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_13 = this;
        let o2: _ProjectionRead__check_inv_13 = other as _ProjectionRead__check_inv_13;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_14 {

    public ObstacleStatusJustChanged: BBoolean;

    constructor(ObstacleStatusJustChanged : BBoolean) {
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_14 = this;
        let o2: _ProjectionRead__check_inv_14 = other as _ProjectionRead__check_inv_14;
        return o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_15 {

    public CCInitialisationInProgress: BBoolean;

    constructor(CCInitialisationInProgress : BBoolean) {
        this.CCInitialisationInProgress = CCInitialisationInProgress;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_15 = this;
        let o2: _ProjectionRead__check_inv_15 = other as _ProjectionRead__check_inv_15;
        return o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_16 {

    public CruiseSpeedChangeInProgress: BBoolean;

    constructor(CruiseSpeedChangeInProgress : BBoolean) {
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_16 = this;
        let o2: _ProjectionRead__check_inv_16 = other as _ProjectionRead__check_inv_16;
        return o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_17 {

    public CruiseActive: BBoolean;
    public VehicleAtCruiseSpeed: BBoolean;

    constructor(CruiseActive : BBoolean, VehicleAtCruiseSpeed : BBoolean) {
        this.CruiseActive = CruiseActive;
        this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_17 = this;
        let o2: _ProjectionRead__check_inv_17 = other as _ProjectionRead__check_inv_17;
        return o1.CruiseActive.equals(o2.CruiseActive) && o1.VehicleAtCruiseSpeed.equals(o2.VehicleAtCruiseSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.VehicleAtCruiseSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_18 {

    public CruiseActive: BBoolean;
    public VehicleCanKeepSpeed: BBoolean;

    constructor(CruiseActive : BBoolean, VehicleCanKeepSpeed : BBoolean) {
        this.CruiseActive = CruiseActive;
        this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_18 = this;
        let o2: _ProjectionRead__check_inv_18 = other as _ProjectionRead__check_inv_18;
        return o1.CruiseActive.equals(o2.CruiseActive) && o1.VehicleCanKeepSpeed.equals(o2.VehicleCanKeepSpeed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.VehicleCanKeepSpeed.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_19 {

    public VehicleTryKeepSpeed: BBoolean;
    public CruiseActive: BBoolean;

    constructor(VehicleTryKeepSpeed : BBoolean, CruiseActive : BBoolean) {
        this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
        this.CruiseActive = CruiseActive;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_19 = this;
        let o2: _ProjectionRead__check_inv_19 = other as _ProjectionRead__check_inv_19;
        return o1.VehicleTryKeepSpeed.equals(o2.VehicleTryKeepSpeed) && o1.CruiseActive.equals(o2.CruiseActive);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleTryKeepSpeed.hashCode() << 1);
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_20 {

    public CruiseActive: BBoolean;
    public NumberOfSetCruise: BInteger;

    constructor(CruiseActive : BBoolean, NumberOfSetCruise : BInteger) {
        this.CruiseActive = CruiseActive;
        this.NumberOfSetCruise = NumberOfSetCruise;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_20 = this;
        let o2: _ProjectionRead__check_inv_20 = other as _ProjectionRead__check_inv_20;
        return o1.CruiseActive.equals(o2.CruiseActive) && o1.NumberOfSetCruise.equals(o2.NumberOfSetCruise);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.NumberOfSetCruise.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_21 {

    public CruiseActive: BBoolean;
    public VehicleTryKeepTimeGap: BBoolean;

    constructor(CruiseActive : BBoolean, VehicleTryKeepTimeGap : BBoolean) {
        this.CruiseActive = CruiseActive;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_21 = this;
        let o2: _ProjectionRead__check_inv_21 = other as _ProjectionRead__check_inv_21;
        return o1.CruiseActive.equals(o2.CruiseActive) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_22 {

    public CruiseSpeedAtMax: BBoolean;
    public CruiseActive: BBoolean;

    constructor(CruiseSpeedAtMax : BBoolean, CruiseActive : BBoolean) {
        this.CruiseSpeedAtMax = CruiseSpeedAtMax;
        this.CruiseActive = CruiseActive;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_22 = this;
        let o2: _ProjectionRead__check_inv_22 = other as _ProjectionRead__check_inv_22;
        return o1.CruiseSpeedAtMax.equals(o2.CruiseSpeedAtMax) && o1.CruiseActive.equals(o2.CruiseActive);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseSpeedAtMax.hashCode() << 1);
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_23 {

    public CruiseActive: BBoolean;
    public ObstacleDistance: ODset;

    constructor(CruiseActive : BBoolean, ObstacleDistance : ODset) {
        this.CruiseActive = CruiseActive;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_23 = this;
        let o2: _ProjectionRead__check_inv_23 = other as _ProjectionRead__check_inv_23;
        return o1.CruiseActive.equals(o2.CruiseActive) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_24 {

    public CruiseActive: BBoolean;
    public ObstacleStatusJustChanged: BBoolean;

    constructor(CruiseActive : BBoolean, ObstacleStatusJustChanged : BBoolean) {
        this.CruiseActive = CruiseActive;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_24 = this;
        let o2: _ProjectionRead__check_inv_24 = other as _ProjectionRead__check_inv_24;
        return o1.CruiseActive.equals(o2.CruiseActive) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_25 {

    public CruiseActive: BBoolean;
    public CCInitialisationInProgress: BBoolean;

    constructor(CruiseActive : BBoolean, CCInitialisationInProgress : BBoolean) {
        this.CruiseActive = CruiseActive;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_25 = this;
        let o2: _ProjectionRead__check_inv_25 = other as _ProjectionRead__check_inv_25;
        return o1.CruiseActive.equals(o2.CruiseActive) && o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_26 {

    public CruiseActive: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;

    constructor(CruiseActive : BBoolean, CruiseSpeedChangeInProgress : BBoolean) {
        this.CruiseActive = CruiseActive;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_26 = this;
        let o2: _ProjectionRead__check_inv_26 = other as _ProjectionRead__check_inv_26;
        return o1.CruiseActive.equals(o2.CruiseActive) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_27 {

    public ObstaclePresent: BBoolean;
    public VehicleTryKeepTimeGap: BBoolean;

    constructor(ObstaclePresent : BBoolean, VehicleTryKeepTimeGap : BBoolean) {
        this.ObstaclePresent = ObstaclePresent;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_27 = this;
        let o2: _ProjectionRead__check_inv_27 = other as _ProjectionRead__check_inv_27;
        return o1.ObstaclePresent.equals(o2.ObstaclePresent) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_28 {

    public ObstaclePresent: BBoolean;
    public ObstacleDistance: ODset;

    constructor(ObstaclePresent : BBoolean, ObstacleDistance : ODset) {
        this.ObstaclePresent = ObstaclePresent;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_28 = this;
        let o2: _ProjectionRead__check_inv_28 = other as _ProjectionRead__check_inv_28;
        return o1.ObstaclePresent.equals(o2.ObstaclePresent) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_29 {

    public ObstacleRelativeSpeed: RSset;
    public ObstaclePresent: BBoolean;

    constructor(ObstacleRelativeSpeed : RSset, ObstaclePresent : BBoolean) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstaclePresent = ObstaclePresent;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_29 = this;
        let o2: _ProjectionRead__check_inv_29 = other as _ProjectionRead__check_inv_29;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstaclePresent.equals(o2.ObstaclePresent);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstaclePresent.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_30 {

    public ObstacleRelativeSpeed: RSset;
    public VehicleTryKeepTimeGap: BBoolean;
    public ObstacleDistance: ODset;

    constructor(ObstacleRelativeSpeed : RSset, VehicleTryKeepTimeGap : BBoolean, ObstacleDistance : ODset) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_30 = this;
        let o2: _ProjectionRead__check_inv_30 = other as _ProjectionRead__check_inv_30;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_31 {

    public ObstacleRelativeSpeed: RSset;
    public VehicleTryKeepTimeGap: BBoolean;
    public ObstacleDistance: ODset;

    constructor(ObstacleRelativeSpeed : RSset, VehicleTryKeepTimeGap : BBoolean, ObstacleDistance : ODset) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_31 = this;
        let o2: _ProjectionRead__check_inv_31 = other as _ProjectionRead__check_inv_31;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_32 {

    public ObstacleRelativeSpeed: RSset;
    public VehicleTryKeepTimeGap: BBoolean;
    public ObstacleDistance: ODset;

    constructor(ObstacleRelativeSpeed : RSset, VehicleTryKeepTimeGap : BBoolean, ObstacleDistance : ODset) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_32 = this;
        let o2: _ProjectionRead__check_inv_32 = other as _ProjectionRead__check_inv_32;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_33 {

    public CruiseActive: BBoolean;
    public CruiseAllowed: BBoolean;

    constructor(CruiseActive : BBoolean, CruiseAllowed : BBoolean) {
        this.CruiseActive = CruiseActive;
        this.CruiseAllowed = CruiseAllowed;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_33 = this;
        let o2: _ProjectionRead__check_inv_33 = other as _ProjectionRead__check_inv_33;
        return o1.CruiseActive.equals(o2.CruiseActive) && o1.CruiseAllowed.equals(o2.CruiseAllowed);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.CruiseAllowed.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_34 {

    public VehicleAtCruiseSpeed: BBoolean;
    public SpeedAboveMax: BBoolean;

    constructor(VehicleAtCruiseSpeed : BBoolean, SpeedAboveMax : BBoolean) {
        this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
        this.SpeedAboveMax = SpeedAboveMax;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_34 = this;
        let o2: _ProjectionRead__check_inv_34 = other as _ProjectionRead__check_inv_34;
        return o1.VehicleAtCruiseSpeed.equals(o2.VehicleAtCruiseSpeed) && o1.SpeedAboveMax.equals(o2.SpeedAboveMax);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleAtCruiseSpeed.hashCode() << 1);
        result = 31 * result + (this.SpeedAboveMax.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_35 {

    public VehicleTryKeepSpeed: BBoolean;
    public CruiseActive: BBoolean;
    public ObstacleStatusJustChanged: BBoolean;
    public CCInitialisationInProgress: BBoolean;
    public VehicleTryKeepTimeGap: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;

    constructor(VehicleTryKeepSpeed : BBoolean, CruiseActive : BBoolean, ObstacleStatusJustChanged : BBoolean, CCInitialisationInProgress : BBoolean, VehicleTryKeepTimeGap : BBoolean, CruiseSpeedChangeInProgress : BBoolean) {
        this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
        this.CruiseActive = CruiseActive;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_35 = this;
        let o2: _ProjectionRead__check_inv_35 = other as _ProjectionRead__check_inv_35;
        return o1.VehicleTryKeepSpeed.equals(o2.VehicleTryKeepSpeed) && o1.CruiseActive.equals(o2.CruiseActive) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleTryKeepSpeed.hashCode() << 1);
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_36 {

    public VehicleTryKeepSpeed: BBoolean;
    public CruiseActive: BBoolean;
    public ObstacleStatusJustChanged: BBoolean;
    public CCInitialisationInProgress: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;
    public ObstacleDistance: ODset;

    constructor(VehicleTryKeepSpeed : BBoolean, CruiseActive : BBoolean, ObstacleStatusJustChanged : BBoolean, CCInitialisationInProgress : BBoolean, CruiseSpeedChangeInProgress : BBoolean, ObstacleDistance : ODset) {
        this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
        this.CruiseActive = CruiseActive;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_36 = this;
        let o2: _ProjectionRead__check_inv_36 = other as _ProjectionRead__check_inv_36;
        return o1.VehicleTryKeepSpeed.equals(o2.VehicleTryKeepSpeed) && o1.CruiseActive.equals(o2.CruiseActive) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleTryKeepSpeed.hashCode() << 1);
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_37 {

    public ObstacleRelativeSpeed: RSset;
    public ObstacleStatusJustChanged: BBoolean;
    public CCInitialisationInProgress: BBoolean;
    public VehicleTryKeepTimeGap: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;
    public ObstacleDistance: ODset;

    constructor(ObstacleRelativeSpeed : RSset, ObstacleStatusJustChanged : BBoolean, CCInitialisationInProgress : BBoolean, VehicleTryKeepTimeGap : BBoolean, CruiseSpeedChangeInProgress : BBoolean, ObstacleDistance : ODset) {
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_37 = this;
        let o2: _ProjectionRead__check_inv_37 = other as _ProjectionRead__check_inv_37;
        return o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_38 {

    public ObstacleStatusJustChanged: BBoolean;
    public CCInitialisationInProgress: BBoolean;
    public VehicleTryKeepTimeGap: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;
    public ObstacleDistance: ODset;

    constructor(ObstacleStatusJustChanged : BBoolean, CCInitialisationInProgress : BBoolean, VehicleTryKeepTimeGap : BBoolean, CruiseSpeedChangeInProgress : BBoolean, ObstacleDistance : ODset) {
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_38 = this;
        let o2: _ProjectionRead__check_inv_38 = other as _ProjectionRead__check_inv_38;
        return o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.VehicleTryKeepTimeGap.equals(o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.VehicleTryKeepTimeGap.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_39 {

    public VehicleTryKeepSpeed: BBoolean;
    public ObstacleRelativeSpeed: RSset;
    public CruiseActive: BBoolean;
    public ObstacleStatusJustChanged: BBoolean;
    public CCInitialisationInProgress: BBoolean;
    public CruiseSpeedChangeInProgress: BBoolean;
    public ObstacleDistance: ODset;

    constructor(VehicleTryKeepSpeed : BBoolean, ObstacleRelativeSpeed : RSset, CruiseActive : BBoolean, ObstacleStatusJustChanged : BBoolean, CCInitialisationInProgress : BBoolean, CruiseSpeedChangeInProgress : BBoolean, ObstacleDistance : ODset) {
        this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
        this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        this.CruiseActive = CruiseActive;
        this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = CCInitialisationInProgress;
        this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        this.ObstacleDistance = ObstacleDistance;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_39 = this;
        let o2: _ProjectionRead__check_inv_39 = other as _ProjectionRead__check_inv_39;
        return o1.VehicleTryKeepSpeed.equals(o2.VehicleTryKeepSpeed) && o1.ObstacleRelativeSpeed.equals(o2.ObstacleRelativeSpeed) && o1.CruiseActive.equals(o2.CruiseActive) && o1.ObstacleStatusJustChanged.equals(o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress.equals(o2.CCInitialisationInProgress) && o1.CruiseSpeedChangeInProgress.equals(o2.CruiseSpeedChangeInProgress) && o1.ObstacleDistance.equals(o2.ObstacleDistance);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.VehicleTryKeepSpeed.hashCode() << 1);
        result = 31 * result + (this.ObstacleRelativeSpeed.hashCode() << 1);
        result = 31 * result + (this.CruiseActive.hashCode() << 1);
        result = 31 * result + (this.ObstacleStatusJustChanged.hashCode() << 1);
        result = 31 * result + (this.CCInitialisationInProgress.hashCode() << 1);
        result = 31 * result + (this.CruiseSpeedChangeInProgress.hashCode() << 1);
        result = 31 * result + (this.ObstacleDistance.hashCode() << 1);
        return result;
    }
}


export enum Type {
    BFS,
    DFS,
    MIXED
}

export default class Cruise_finite1_deterministic_MC {

    parent: Cruise_finite1_deterministic_MC;
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

    _projected_state_for_ObstacleStopsTravelSlower(): _ProjectionRead_ObstacleStopsTravelSlower {
        return new _ProjectionRead_ObstacleStopsTravelSlower(this.ObstacleRelativeSpeed,this.CruiseActive);
    }

    _projected_state_for_SetCruiseSpeed(): _ProjectionRead_SetCruiseSpeed {
        return new _ProjectionRead_SetCruiseSpeed(this.CruiseActive,this.CruiseAllowed,this.SpeedAboveMax,this.NumberOfSetCruise);
    }

    _projected_state_for_VehicleLeavesCruiseSpeed(): _ProjectionRead_VehicleLeavesCruiseSpeed {
        return new _ProjectionRead_VehicleLeavesCruiseSpeed(this.VehicleTryKeepSpeed,this.VehicleAtCruiseSpeed,this.VehicleCanKeepSpeed);
    }

    _projected_state_for_VehicleFallsBelowMaxCruiseSpeed(): _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed {
        return new _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed(this.CruiseSpeedAtMax,this.CruiseActive,this.SpeedAboveMax);
    }

    _projected_state_for_CCInitialisationFinished(): _ProjectionRead_CCInitialisationFinished {
        return new _ProjectionRead_CCInitialisationFinished(this.ObstacleStatusJustChanged,this.CCInitialisationInProgress,this.ObstacleDistance,this.ObstacleRelativeSpeed,this.ObstaclePresent,this.CruiseSpeedChangeInProgress);
    }

    _projected_state_for_VehicleReachesCruiseSpeed(): _ProjectionRead_VehicleReachesCruiseSpeed {
        return new _ProjectionRead_VehicleReachesCruiseSpeed(this.CruiseActive,this.VehicleAtCruiseSpeed,this.SpeedAboveMax);
    }

    _projected_state_for_ObstacleAppearsWhenCruiseActive(): _ProjectionRead_ObstacleAppearsWhenCruiseActive {
        return new _ProjectionRead_ObstacleAppearsWhenCruiseActive(this.CruiseActive,this.ObstaclePresent);
    }

    _projected_state_for_ObstacleStartsTravelSlower(): _ProjectionRead_ObstacleStartsTravelSlower {
        return new _ProjectionRead_ObstacleStartsTravelSlower(this.ObstacleRelativeSpeed,this.CruiseActive);
    }

    _projected_state_for_CruiseBecomesNotAllowed(): _ProjectionRead_CruiseBecomesNotAllowed {
        return new _ProjectionRead_CruiseBecomesNotAllowed(this.CruiseAllowed);
    }

    _projected_state_for_ObstacleAppearsWhenCruiseInactive(): _ProjectionRead_ObstacleAppearsWhenCruiseInactive {
        return new _ProjectionRead_ObstacleAppearsWhenCruiseInactive(this.CruiseActive,this.ObstaclePresent);
    }

    _projected_state_for_CCInitialisationDelayFinished(): _ProjectionRead_CCInitialisationDelayFinished {
        return new _ProjectionRead_CCInitialisationDelayFinished(this.VehicleTryKeepSpeed,this.ObstacleRelativeSpeed,this.CCInitialisationInProgress,this.ObstacleStatusJustChanged,this.VehicleTryKeepTimeGap,this.CruiseSpeedChangeInProgress,this.ObstacleDistance);
    }

    _projected_state_for_ObstacleDistanceBecomesClose(): _ProjectionRead_ObstacleDistanceBecomesClose {
        return new _ProjectionRead_ObstacleDistanceBecomesClose(this.ObstacleRelativeSpeed,this.CruiseActive,this.ObstaclePresent,this.ObstacleDistance);
    }

    _projected_state_for_ObstacleStartsTravelFaster(): _ProjectionRead_ObstacleStartsTravelFaster {
        return new _ProjectionRead_ObstacleStartsTravelFaster(this.ObstacleRelativeSpeed,this.CruiseActive,this.ObstaclePresent,this.ObstacleDistance);
    }

    _projected_state_for_ExternalForcesBecomesExtreme(): _ProjectionRead_ExternalForcesBecomesExtreme {
        return new _ProjectionRead_ExternalForcesBecomesExtreme(this.VehicleCanKeepSpeed);
    }

    _projected_state_for_CruiseOff(): _ProjectionRead_CruiseOff {
        return new _ProjectionRead_CruiseOff(this.CruiseActive);
    }

    _projected_state_for_CruiseSpeedChangeDelayFinished(): _ProjectionRead_CruiseSpeedChangeDelayFinished {
        return new _ProjectionRead_CruiseSpeedChangeDelayFinished(this.VehicleTryKeepSpeed,this.ObstacleRelativeSpeed,this.ObstacleStatusJustChanged,this.CCInitialisationInProgress,this.VehicleTryKeepTimeGap,this.CruiseSpeedChangeInProgress,this.ObstacleDistance);
    }

    _projected_state_for_ObstacleStopsTravelFaster(): _ProjectionRead_ObstacleStopsTravelFaster {
        return new _ProjectionRead_ObstacleStopsTravelFaster(this.ObstacleRelativeSpeed,this.CruiseActive);
    }

    _projected_state_for_ObstacleDistanceBecomesVeryClose(): _ProjectionRead_ObstacleDistanceBecomesVeryClose {
        return new _ProjectionRead_ObstacleDistanceBecomesVeryClose(this.ObstacleRelativeSpeed,this.ObstacleDistance);
    }

    _projected_state_for_VehicleManageObstacle(): _ProjectionRead_VehicleManageObstacle {
        return new _ProjectionRead_VehicleManageObstacle(this.CCInitialisationInProgress,this.ObstacleStatusJustChanged,this.ObstacleDistance,this.ObstacleRelativeSpeed,this.ObstaclePresent,this.CruiseSpeedChangeInProgress);
    }

    _projected_state_for_CruiseBecomesAllowed(): _ProjectionRead_CruiseBecomesAllowed {
        return new _ProjectionRead_CruiseBecomesAllowed(this.CruiseAllowed);
    }

    _projected_state_for_VehicleExceedsMaxCruiseSpeed(): _ProjectionRead_VehicleExceedsMaxCruiseSpeed {
        return new _ProjectionRead_VehicleExceedsMaxCruiseSpeed(this.CruiseActive,this.SpeedAboveMax,this.ObstacleStatusJustChanged,this.CCInitialisationInProgress,this.CruiseSpeedChangeInProgress,this.VehicleCanKeepSpeed);
    }

    _projected_state_for_CruiseSpeedChangeFinished(): _ProjectionRead_CruiseSpeedChangeFinished {
        return new _ProjectionRead_CruiseSpeedChangeFinished(this.ObstacleStatusJustChanged,this.CCInitialisationInProgress,this.ObstacleDistance,this.ObstacleRelativeSpeed,this.ObstaclePresent,this.CruiseSpeedChangeInProgress);
    }

    _projected_state_for_ObstacleDisappears(): _ProjectionRead_ObstacleDisappears {
        return new _ProjectionRead_ObstacleDisappears(this.CruiseActive,this.ObstaclePresent);
    }

    _projected_state_for_ExternalForcesBecomesNormal(): _ProjectionRead_ExternalForcesBecomesNormal {
        return new _ProjectionRead_ExternalForcesBecomesNormal(this.CruiseActive,this.VehicleCanKeepSpeed);
    }

    _projected_state_for_ObstacleBecomesOld(): _ProjectionRead_ObstacleBecomesOld {
        return new _ProjectionRead_ObstacleBecomesOld(this.VehicleTryKeepSpeed,this.ObstacleRelativeSpeed,this.ObstacleStatusJustChanged,this.CCInitialisationInProgress,this.VehicleTryKeepTimeGap,this.CruiseSpeedChangeInProgress,this.ObstacleDistance);
    }

    _projected_state_for_ObstacleDistanceBecomesBig(): _ProjectionRead_ObstacleDistanceBecomesBig {
        return new _ProjectionRead_ObstacleDistanceBecomesBig(this.ObstacleRelativeSpeed,this.ObstacleDistance);
    }

    _projected_state_for__tr_ObstacleStopsTravelSlower(): _ProjectionRead__tr_ObstacleStopsTravelSlower {
        return new _ProjectionRead__tr_ObstacleStopsTravelSlower(this.ObstacleRelativeSpeed);
    }

    _projected_state_for__tr_ObstacleDistanceBecomesClose(): _ProjectionRead__tr_ObstacleDistanceBecomesClose {
        return new _ProjectionRead__tr_ObstacleDistanceBecomesClose(this.ObstacleRelativeSpeed,this.CruiseActive,this.ObstaclePresent,this.ObstacleDistance);
    }

    _projected_state_for__tr_ExternalForcesBecomesExtreme(): _ProjectionRead__tr_ExternalForcesBecomesExtreme {
        return new _ProjectionRead__tr_ExternalForcesBecomesExtreme(this.VehicleCanKeepSpeed);
    }

    _projected_state_for__tr_ObstacleStartsTravelSlower(): _ProjectionRead__tr_ObstacleStartsTravelSlower {
        return new _ProjectionRead__tr_ObstacleStartsTravelSlower(this.ObstacleRelativeSpeed);
    }

    _projected_state_for__tr_VehicleReachesCruiseSpeed(): _ProjectionRead__tr_VehicleReachesCruiseSpeed {
        return new _ProjectionRead__tr_VehicleReachesCruiseSpeed(this.CruiseActive,this.VehicleAtCruiseSpeed,this.SpeedAboveMax);
    }

    _projected_state_for__tr_CruiseOff(): _ProjectionRead__tr_CruiseOff {
        return new _ProjectionRead__tr_CruiseOff(this.CruiseActive);
    }

    _projected_state_for__tr_VehicleFallsBelowMaxCruiseSpeed(): _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed {
        return new _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed(this.SpeedAboveMax);
    }

    _projected_state_for__tr_ObstacleBecomesOld(): _ProjectionRead__tr_ObstacleBecomesOld {
        return new _ProjectionRead__tr_ObstacleBecomesOld(this.VehicleTryKeepSpeed,this.ObstacleRelativeSpeed,this.ObstacleStatusJustChanged,this.CCInitialisationInProgress,this.VehicleTryKeepTimeGap,this.CruiseSpeedChangeInProgress,this.ObstacleDistance);
    }

    _projected_state_for__tr_ObstacleDistanceBecomesVeryClose(): _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose {
        return new _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose(this.ObstacleRelativeSpeed,this.ObstacleDistance);
    }

    _projected_state_for__tr_ObstacleStopsTravelFaster(): _ProjectionRead__tr_ObstacleStopsTravelFaster {
        return new _ProjectionRead__tr_ObstacleStopsTravelFaster(this.ObstacleRelativeSpeed);
    }

    _projected_state_for__tr_SetCruiseSpeed(): _ProjectionRead__tr_SetCruiseSpeed {
        return new _ProjectionRead__tr_SetCruiseSpeed(this.CruiseAllowed);
    }

    _projected_state_for__tr_VehicleManageObstacle(): _ProjectionRead__tr_VehicleManageObstacle {
        return new _ProjectionRead__tr_VehicleManageObstacle(this.CCInitialisationInProgress,this.ObstacleStatusJustChanged,this.ObstacleDistance,this.ObstacleRelativeSpeed,this.ObstaclePresent,this.CruiseSpeedChangeInProgress);
    }

    _projected_state_for__tr_CruiseBecomesAllowed(): _ProjectionRead__tr_CruiseBecomesAllowed {
        return new _ProjectionRead__tr_CruiseBecomesAllowed(this.CruiseAllowed);
    }

    _projected_state_for__tr_ObstacleDistanceBecomesBig(): _ProjectionRead__tr_ObstacleDistanceBecomesBig {
        return new _ProjectionRead__tr_ObstacleDistanceBecomesBig(this.ObstacleRelativeSpeed,this.ObstacleDistance);
    }

    _projected_state_for__tr_CruiseBecomesNotAllowed(): _ProjectionRead__tr_CruiseBecomesNotAllowed {
        return new _ProjectionRead__tr_CruiseBecomesNotAllowed(this.CruiseAllowed);
    }

    _projected_state_for__tr_ExternalForcesBecomesNormal(): _ProjectionRead__tr_ExternalForcesBecomesNormal {
        return new _ProjectionRead__tr_ExternalForcesBecomesNormal(this.CruiseActive,this.VehicleCanKeepSpeed);
    }

    _projected_state_for__tr_CruiseSpeedChangeFinished(): _ProjectionRead__tr_CruiseSpeedChangeFinished {
        return new _ProjectionRead__tr_CruiseSpeedChangeFinished(this.ObstacleStatusJustChanged,this.CCInitialisationInProgress,this.ObstacleDistance,this.ObstacleRelativeSpeed,this.ObstaclePresent,this.CruiseSpeedChangeInProgress);
    }

    _projected_state_for__tr_ObstacleDisappears(): _ProjectionRead__tr_ObstacleDisappears {
        return new _ProjectionRead__tr_ObstacleDisappears(this.ObstaclePresent);
    }

    _projected_state_for__tr_CCInitialisationFinished(): _ProjectionRead__tr_CCInitialisationFinished {
        return new _ProjectionRead__tr_CCInitialisationFinished(this.ObstacleStatusJustChanged,this.CCInitialisationInProgress,this.ObstacleDistance,this.ObstacleRelativeSpeed,this.ObstaclePresent,this.CruiseSpeedChangeInProgress);
    }

    _projected_state_for__tr_CCInitialisationDelayFinished(): _ProjectionRead__tr_CCInitialisationDelayFinished {
        return new _ProjectionRead__tr_CCInitialisationDelayFinished(this.VehicleTryKeepSpeed,this.ObstacleRelativeSpeed,this.CCInitialisationInProgress,this.ObstacleStatusJustChanged,this.VehicleTryKeepTimeGap,this.CruiseSpeedChangeInProgress,this.ObstacleDistance);
    }

    _projected_state_for__tr_CruiseSpeedChangeDelayFinished(): _ProjectionRead__tr_CruiseSpeedChangeDelayFinished {
        return new _ProjectionRead__tr_CruiseSpeedChangeDelayFinished(this.VehicleTryKeepSpeed,this.ObstacleRelativeSpeed,this.ObstacleStatusJustChanged,this.CCInitialisationInProgress,this.VehicleTryKeepTimeGap,this.CruiseSpeedChangeInProgress,this.ObstacleDistance);
    }

    _projected_state_for__tr_VehicleLeavesCruiseSpeed(): _ProjectionRead__tr_VehicleLeavesCruiseSpeed {
        return new _ProjectionRead__tr_VehicleLeavesCruiseSpeed(this.VehicleTryKeepSpeed,this.VehicleAtCruiseSpeed,this.VehicleCanKeepSpeed);
    }

    _projected_state_for__tr_ObstacleStartsTravelFaster(): _ProjectionRead__tr_ObstacleStartsTravelFaster {
        return new _ProjectionRead__tr_ObstacleStartsTravelFaster(this.ObstacleRelativeSpeed,this.ObstaclePresent);
    }

    _projected_state_for__tr_ObstacleAppearsWhenCruiseActive(): _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive {
        return new _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive(this.CruiseActive,this.ObstaclePresent);
    }

    _projected_state_for__tr_VehicleExceedsMaxCruiseSpeed(): _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed {
        return new _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed(this.CruiseActive,this.SpeedAboveMax,this.ObstacleStatusJustChanged,this.CCInitialisationInProgress,this.CruiseSpeedChangeInProgress,this.VehicleCanKeepSpeed);
    }

    _projected_state_for__tr_ObstacleAppearsWhenCruiseInactive(): _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive {
        return new _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive(this.CruiseActive,this.ObstaclePresent);
    }

    _projected_state_for__check_inv_18(): _ProjectionRead__check_inv_18 {
        return new _ProjectionRead__check_inv_18(this.CruiseActive,this.VehicleCanKeepSpeed);
    }

    _projected_state_for__check_inv_17(): _ProjectionRead__check_inv_17 {
        return new _ProjectionRead__check_inv_17(this.CruiseActive,this.VehicleAtCruiseSpeed);
    }

    _projected_state_for__check_inv_39(): _ProjectionRead__check_inv_39 {
        return new _ProjectionRead__check_inv_39(this.VehicleTryKeepSpeed,this.ObstacleRelativeSpeed,this.CruiseActive,this.ObstacleStatusJustChanged,this.CCInitialisationInProgress,this.CruiseSpeedChangeInProgress,this.ObstacleDistance);
    }

    _projected_state_for__check_inv_16(): _ProjectionRead__check_inv_16 {
        return new _ProjectionRead__check_inv_16(this.CruiseSpeedChangeInProgress);
    }

    _projected_state_for__check_inv_38(): _ProjectionRead__check_inv_38 {
        return new _ProjectionRead__check_inv_38(this.ObstacleStatusJustChanged,this.CCInitialisationInProgress,this.VehicleTryKeepTimeGap,this.CruiseSpeedChangeInProgress,this.ObstacleDistance);
    }

    _projected_state_for__check_inv_15(): _ProjectionRead__check_inv_15 {
        return new _ProjectionRead__check_inv_15(this.CCInitialisationInProgress);
    }

    _projected_state_for__check_inv_37(): _ProjectionRead__check_inv_37 {
        return new _ProjectionRead__check_inv_37(this.ObstacleRelativeSpeed,this.ObstacleStatusJustChanged,this.CCInitialisationInProgress,this.VehicleTryKeepTimeGap,this.CruiseSpeedChangeInProgress,this.ObstacleDistance);
    }

    _projected_state_for__check_inv_19(): _ProjectionRead__check_inv_19 {
        return new _ProjectionRead__check_inv_19(this.VehicleTryKeepSpeed,this.CruiseActive);
    }

    _projected_state_for__check_inv_10(): _ProjectionRead__check_inv_10 {
        return new _ProjectionRead__check_inv_10(this.NumberOfSetCruise);
    }

    _projected_state_for__check_inv_32(): _ProjectionRead__check_inv_32 {
        return new _ProjectionRead__check_inv_32(this.ObstacleRelativeSpeed,this.VehicleTryKeepTimeGap,this.ObstacleDistance);
    }

    _projected_state_for__check_inv_31(): _ProjectionRead__check_inv_31 {
        return new _ProjectionRead__check_inv_31(this.ObstacleRelativeSpeed,this.VehicleTryKeepTimeGap,this.ObstacleDistance);
    }

    _projected_state_for__check_inv_30(): _ProjectionRead__check_inv_30 {
        return new _ProjectionRead__check_inv_30(this.ObstacleRelativeSpeed,this.VehicleTryKeepTimeGap,this.ObstacleDistance);
    }

    _projected_state_for__check_inv_14(): _ProjectionRead__check_inv_14 {
        return new _ProjectionRead__check_inv_14(this.ObstacleStatusJustChanged);
    }

    _projected_state_for__check_inv_36(): _ProjectionRead__check_inv_36 {
        return new _ProjectionRead__check_inv_36(this.VehicleTryKeepSpeed,this.CruiseActive,this.ObstacleStatusJustChanged,this.CCInitialisationInProgress,this.CruiseSpeedChangeInProgress,this.ObstacleDistance);
    }

    _projected_state_for__check_inv_13(): _ProjectionRead__check_inv_13 {
        return new _ProjectionRead__check_inv_13(this.ObstacleRelativeSpeed);
    }

    _projected_state_for__check_inv_35(): _ProjectionRead__check_inv_35 {
        return new _ProjectionRead__check_inv_35(this.VehicleTryKeepSpeed,this.CruiseActive,this.ObstacleStatusJustChanged,this.CCInitialisationInProgress,this.VehicleTryKeepTimeGap,this.CruiseSpeedChangeInProgress);
    }

    _projected_state_for__check_inv_12(): _ProjectionRead__check_inv_12 {
        return new _ProjectionRead__check_inv_12(this.ObstacleDistance);
    }

    _projected_state_for__check_inv_34(): _ProjectionRead__check_inv_34 {
        return new _ProjectionRead__check_inv_34(this.VehicleAtCruiseSpeed,this.SpeedAboveMax);
    }

    _projected_state_for__check_inv_11(): _ProjectionRead__check_inv_11 {
        return new _ProjectionRead__check_inv_11(this.ObstaclePresent);
    }

    _projected_state_for__check_inv_33(): _ProjectionRead__check_inv_33 {
        return new _ProjectionRead__check_inv_33(this.CruiseActive,this.CruiseAllowed);
    }

    _projected_state_for__check_inv_29(): _ProjectionRead__check_inv_29 {
        return new _ProjectionRead__check_inv_29(this.ObstacleRelativeSpeed,this.ObstaclePresent);
    }

    _projected_state_for__check_inv_28(): _ProjectionRead__check_inv_28 {
        return new _ProjectionRead__check_inv_28(this.ObstaclePresent,this.ObstacleDistance);
    }

    _projected_state_for__check_inv_27(): _ProjectionRead__check_inv_27 {
        return new _ProjectionRead__check_inv_27(this.ObstaclePresent,this.VehicleTryKeepTimeGap);
    }

    _projected_state_for__check_inv_26(): _ProjectionRead__check_inv_26 {
        return new _ProjectionRead__check_inv_26(this.CruiseActive,this.CruiseSpeedChangeInProgress);
    }

    _projected_state_for__check_inv_6(): _ProjectionRead__check_inv_6 {
        return new _ProjectionRead__check_inv_6(this.SpeedAboveMax);
    }

    _projected_state_for__check_inv_21(): _ProjectionRead__check_inv_21 {
        return new _ProjectionRead__check_inv_21(this.CruiseActive,this.VehicleTryKeepTimeGap);
    }

    _projected_state_for__check_inv_7(): _ProjectionRead__check_inv_7 {
        return new _ProjectionRead__check_inv_7(this.VehicleTryKeepTimeGap);
    }

    _projected_state_for__check_inv_20(): _ProjectionRead__check_inv_20 {
        return new _ProjectionRead__check_inv_20(this.CruiseActive,this.NumberOfSetCruise);
    }

    _projected_state_for__check_inv_4(): _ProjectionRead__check_inv_4 {
        return new _ProjectionRead__check_inv_4(this.VehicleCanKeepSpeed);
    }

    _projected_state_for__check_inv_5(): _ProjectionRead__check_inv_5 {
        return new _ProjectionRead__check_inv_5(this.VehicleTryKeepSpeed);
    }

    _projected_state_for__check_inv_25(): _ProjectionRead__check_inv_25 {
        return new _ProjectionRead__check_inv_25(this.CruiseActive,this.CCInitialisationInProgress);
    }

    _projected_state_for__check_inv_24(): _ProjectionRead__check_inv_24 {
        return new _ProjectionRead__check_inv_24(this.CruiseActive,this.ObstacleStatusJustChanged);
    }

    _projected_state_for__check_inv_8(): _ProjectionRead__check_inv_8 {
        return new _ProjectionRead__check_inv_8(this.CruiseSpeedAtMax);
    }

    _projected_state_for__check_inv_23(): _ProjectionRead__check_inv_23 {
        return new _ProjectionRead__check_inv_23(this.CruiseActive,this.ObstacleDistance);
    }

    _projected_state_for__check_inv_9(): _ProjectionRead__check_inv_9 {
        return new _ProjectionRead__check_inv_9(this.NumberOfSetCruise);
    }

    _projected_state_for__check_inv_22(): _ProjectionRead__check_inv_22 {
        return new _ProjectionRead__check_inv_22(this.CruiseSpeedAtMax,this.CruiseActive);
    }

    _projected_state_for__check_inv_2(): _ProjectionRead__check_inv_2 {
        return new _ProjectionRead__check_inv_2(this.CruiseActive);
    }

    _projected_state_for__check_inv_3(): _ProjectionRead__check_inv_3 {
        return new _ProjectionRead__check_inv_3(this.VehicleAtCruiseSpeed);
    }

    _projected_state_for__check_inv_1(): _ProjectionRead__check_inv_1 {
        return new _ProjectionRead__check_inv_1(this.CruiseAllowed);
    }

    _update_for_ObstacleStopsTravelSlower(): _ProjectionWrite_ObstacleStopsTravelSlower {
        return new _ProjectionWrite_ObstacleStopsTravelSlower(this.ObstacleRelativeSpeed,this.ObstacleStatusJustChanged);
    }

    _update_for_SetCruiseSpeed(): _ProjectionWrite_SetCruiseSpeed {
        return new _ProjectionWrite_SetCruiseSpeed(this.CruiseSpeedAtMax,this.CruiseActive,this.VehicleAtCruiseSpeed,this.ObstacleStatusJustChanged,this.CCInitialisationInProgress,this.NumberOfSetCruise,this.CruiseSpeedChangeInProgress,this.VehicleCanKeepSpeed);
    }

    _update_for_VehicleLeavesCruiseSpeed(): _ProjectionWrite_VehicleLeavesCruiseSpeed {
        return new _ProjectionWrite_VehicleLeavesCruiseSpeed(this.VehicleAtCruiseSpeed);
    }

    _update_for_VehicleFallsBelowMaxCruiseSpeed(): _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed {
        return new _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed(this.VehicleAtCruiseSpeed,this.SpeedAboveMax);
    }

    _update_for_CCInitialisationFinished(): _ProjectionWrite_CCInitialisationFinished {
        return new _ProjectionWrite_CCInitialisationFinished(this.VehicleTryKeepSpeed,this.VehicleTryKeepTimeGap);
    }

    _update_for_VehicleReachesCruiseSpeed(): _ProjectionWrite_VehicleReachesCruiseSpeed {
        return new _ProjectionWrite_VehicleReachesCruiseSpeed(this.VehicleAtCruiseSpeed);
    }

    _update_for_ObstacleAppearsWhenCruiseActive(): _ProjectionWrite_ObstacleAppearsWhenCruiseActive {
        return new _ProjectionWrite_ObstacleAppearsWhenCruiseActive(this.ObstacleRelativeSpeed,this.ObstaclePresent,this.ObstacleStatusJustChanged,this.ObstacleDistance);
    }

    _update_for_ObstacleStartsTravelSlower(): _ProjectionWrite_ObstacleStartsTravelSlower {
        return new _ProjectionWrite_ObstacleStartsTravelSlower(this.ObstacleRelativeSpeed,this.ObstacleStatusJustChanged);
    }

    _update_for_CruiseBecomesNotAllowed(): _ProjectionWrite_CruiseBecomesNotAllowed {
        return new _ProjectionWrite_CruiseBecomesNotAllowed(this.VehicleTryKeepSpeed,this.CruiseSpeedAtMax,this.CruiseActive,this.VehicleAtCruiseSpeed,this.CruiseAllowed,this.ObstacleStatusJustChanged,this.CCInitialisationInProgress,this.NumberOfSetCruise,this.VehicleTryKeepTimeGap,this.CruiseSpeedChangeInProgress,this.VehicleCanKeepSpeed,this.ObstacleDistance);
    }

    _update_for_ObstacleAppearsWhenCruiseInactive(): _ProjectionWrite_ObstacleAppearsWhenCruiseInactive {
        return new _ProjectionWrite_ObstacleAppearsWhenCruiseInactive(this.ObstacleRelativeSpeed,this.ObstaclePresent,this.ObstacleDistance);
    }

    _update_for_CCInitialisationDelayFinished(): _ProjectionWrite_CCInitialisationDelayFinished {
        return new _ProjectionWrite_CCInitialisationDelayFinished(this.CCInitialisationInProgress);
    }

    _update_for_ObstacleDistanceBecomesClose(): _ProjectionWrite_ObstacleDistanceBecomesClose {
        return new _ProjectionWrite_ObstacleDistanceBecomesClose(this.ObstacleStatusJustChanged,this.VehicleTryKeepTimeGap,this.ObstacleDistance);
    }

    _update_for_ObstacleStartsTravelFaster(): _ProjectionWrite_ObstacleStartsTravelFaster {
        return new _ProjectionWrite_ObstacleStartsTravelFaster(this.ObstacleRelativeSpeed,this.ObstacleStatusJustChanged,this.VehicleTryKeepTimeGap);
    }

    _update_for_ExternalForcesBecomesExtreme(): _ProjectionWrite_ExternalForcesBecomesExtreme {
        return new _ProjectionWrite_ExternalForcesBecomesExtreme(this.VehicleCanKeepSpeed);
    }

    _update_for_CruiseOff(): _ProjectionWrite_CruiseOff {
        return new _ProjectionWrite_CruiseOff(this.VehicleTryKeepSpeed,this.CruiseSpeedAtMax,this.CruiseActive,this.VehicleAtCruiseSpeed,this.ObstacleStatusJustChanged,this.CCInitialisationInProgress,this.NumberOfSetCruise,this.VehicleTryKeepTimeGap,this.CruiseSpeedChangeInProgress,this.VehicleCanKeepSpeed,this.ObstacleDistance);
    }

    _update_for_CruiseSpeedChangeDelayFinished(): _ProjectionWrite_CruiseSpeedChangeDelayFinished {
        return new _ProjectionWrite_CruiseSpeedChangeDelayFinished(this.CruiseSpeedChangeInProgress);
    }

    _update_for_ObstacleStopsTravelFaster(): _ProjectionWrite_ObstacleStopsTravelFaster {
        return new _ProjectionWrite_ObstacleStopsTravelFaster(this.ObstacleRelativeSpeed,this.ObstacleStatusJustChanged);
    }

    _update_for_ObstacleDistanceBecomesVeryClose(): _ProjectionWrite_ObstacleDistanceBecomesVeryClose {
        return new _ProjectionWrite_ObstacleDistanceBecomesVeryClose(this.ObstacleStatusJustChanged,this.ObstacleDistance);
    }

    _update_for_VehicleManageObstacle(): _ProjectionWrite_VehicleManageObstacle {
        return new _ProjectionWrite_VehicleManageObstacle(this.VehicleTryKeepSpeed,this.VehicleTryKeepTimeGap);
    }

    _update_for_CruiseBecomesAllowed(): _ProjectionWrite_CruiseBecomesAllowed {
        return new _ProjectionWrite_CruiseBecomesAllowed(this.CruiseAllowed);
    }

    _update_for_VehicleExceedsMaxCruiseSpeed(): _ProjectionWrite_VehicleExceedsMaxCruiseSpeed {
        return new _ProjectionWrite_VehicleExceedsMaxCruiseSpeed(this.VehicleAtCruiseSpeed,this.SpeedAboveMax);
    }

    _update_for_CruiseSpeedChangeFinished(): _ProjectionWrite_CruiseSpeedChangeFinished {
        return new _ProjectionWrite_CruiseSpeedChangeFinished(this.VehicleTryKeepSpeed,this.VehicleTryKeepTimeGap);
    }

    _update_for_ObstacleDisappears(): _ProjectionWrite_ObstacleDisappears {
        return new _ProjectionWrite_ObstacleDisappears(this.ObstacleRelativeSpeed,this.ObstaclePresent,this.ObstacleStatusJustChanged,this.VehicleTryKeepTimeGap,this.ObstacleDistance);
    }

    _update_for_ExternalForcesBecomesNormal(): _ProjectionWrite_ExternalForcesBecomesNormal {
        return new _ProjectionWrite_ExternalForcesBecomesNormal(this.VehicleCanKeepSpeed);
    }

    _update_for_ObstacleBecomesOld(): _ProjectionWrite_ObstacleBecomesOld {
        return new _ProjectionWrite_ObstacleBecomesOld(this.ObstacleStatusJustChanged);
    }

    _update_for_ObstacleDistanceBecomesBig(): _ProjectionWrite_ObstacleDistanceBecomesBig {
        return new _ProjectionWrite_ObstacleDistanceBecomesBig(this.ObstacleStatusJustChanged,this.VehicleTryKeepTimeGap,this.ObstacleDistance);
    }

    _apply_update_for_ObstacleStopsTravelSlower(update : _ProjectionWrite_ObstacleStopsTravelSlower): void {
        this.ObstacleRelativeSpeed = update.ObstacleRelativeSpeed;
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
    }

    _apply_update_for_SetCruiseSpeed(update : _ProjectionWrite_SetCruiseSpeed): void {
        this.CruiseSpeedAtMax = update.CruiseSpeedAtMax;
        this.CruiseActive = update.CruiseActive;
        this.VehicleAtCruiseSpeed = update.VehicleAtCruiseSpeed;
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = update.CCInitialisationInProgress;
        this.NumberOfSetCruise = update.NumberOfSetCruise;
        this.CruiseSpeedChangeInProgress = update.CruiseSpeedChangeInProgress;
        this.VehicleCanKeepSpeed = update.VehicleCanKeepSpeed;
    }

    _apply_update_for_VehicleLeavesCruiseSpeed(update : _ProjectionWrite_VehicleLeavesCruiseSpeed): void {
        this.VehicleAtCruiseSpeed = update.VehicleAtCruiseSpeed;
    }

    _apply_update_for_VehicleFallsBelowMaxCruiseSpeed(update : _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed): void {
        this.VehicleAtCruiseSpeed = update.VehicleAtCruiseSpeed;
        this.SpeedAboveMax = update.SpeedAboveMax;
    }

    _apply_update_for_CCInitialisationFinished(update : _ProjectionWrite_CCInitialisationFinished): void {
        this.VehicleTryKeepSpeed = update.VehicleTryKeepSpeed;
        this.VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
    }

    _apply_update_for_VehicleReachesCruiseSpeed(update : _ProjectionWrite_VehicleReachesCruiseSpeed): void {
        this.VehicleAtCruiseSpeed = update.VehicleAtCruiseSpeed;
    }

    _apply_update_for_ObstacleAppearsWhenCruiseActive(update : _ProjectionWrite_ObstacleAppearsWhenCruiseActive): void {
        this.ObstacleRelativeSpeed = update.ObstacleRelativeSpeed;
        this.ObstaclePresent = update.ObstaclePresent;
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        this.ObstacleDistance = update.ObstacleDistance;
    }

    _apply_update_for_ObstacleStartsTravelSlower(update : _ProjectionWrite_ObstacleStartsTravelSlower): void {
        this.ObstacleRelativeSpeed = update.ObstacleRelativeSpeed;
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
    }

    _apply_update_for_CruiseBecomesNotAllowed(update : _ProjectionWrite_CruiseBecomesNotAllowed): void {
        this.VehicleTryKeepSpeed = update.VehicleTryKeepSpeed;
        this.CruiseSpeedAtMax = update.CruiseSpeedAtMax;
        this.CruiseActive = update.CruiseActive;
        this.VehicleAtCruiseSpeed = update.VehicleAtCruiseSpeed;
        this.CruiseAllowed = update.CruiseAllowed;
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = update.CCInitialisationInProgress;
        this.NumberOfSetCruise = update.NumberOfSetCruise;
        this.VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
        this.CruiseSpeedChangeInProgress = update.CruiseSpeedChangeInProgress;
        this.VehicleCanKeepSpeed = update.VehicleCanKeepSpeed;
        this.ObstacleDistance = update.ObstacleDistance;
    }

    _apply_update_for_ObstacleAppearsWhenCruiseInactive(update : _ProjectionWrite_ObstacleAppearsWhenCruiseInactive): void {
        this.ObstacleRelativeSpeed = update.ObstacleRelativeSpeed;
        this.ObstaclePresent = update.ObstaclePresent;
        this.ObstacleDistance = update.ObstacleDistance;
    }

    _apply_update_for_CCInitialisationDelayFinished(update : _ProjectionWrite_CCInitialisationDelayFinished): void {
        this.CCInitialisationInProgress = update.CCInitialisationInProgress;
    }

    _apply_update_for_ObstacleDistanceBecomesClose(update : _ProjectionWrite_ObstacleDistanceBecomesClose): void {
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        this.VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
        this.ObstacleDistance = update.ObstacleDistance;
    }

    _apply_update_for_ObstacleStartsTravelFaster(update : _ProjectionWrite_ObstacleStartsTravelFaster): void {
        this.ObstacleRelativeSpeed = update.ObstacleRelativeSpeed;
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        this.VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
    }

    _apply_update_for_ExternalForcesBecomesExtreme(update : _ProjectionWrite_ExternalForcesBecomesExtreme): void {
        this.VehicleCanKeepSpeed = update.VehicleCanKeepSpeed;
    }

    _apply_update_for_CruiseOff(update : _ProjectionWrite_CruiseOff): void {
        this.VehicleTryKeepSpeed = update.VehicleTryKeepSpeed;
        this.CruiseSpeedAtMax = update.CruiseSpeedAtMax;
        this.CruiseActive = update.CruiseActive;
        this.VehicleAtCruiseSpeed = update.VehicleAtCruiseSpeed;
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = update.CCInitialisationInProgress;
        this.NumberOfSetCruise = update.NumberOfSetCruise;
        this.VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
        this.CruiseSpeedChangeInProgress = update.CruiseSpeedChangeInProgress;
        this.VehicleCanKeepSpeed = update.VehicleCanKeepSpeed;
        this.ObstacleDistance = update.ObstacleDistance;
    }

    _apply_update_for_CruiseSpeedChangeDelayFinished(update : _ProjectionWrite_CruiseSpeedChangeDelayFinished): void {
        this.CruiseSpeedChangeInProgress = update.CruiseSpeedChangeInProgress;
    }

    _apply_update_for_ObstacleStopsTravelFaster(update : _ProjectionWrite_ObstacleStopsTravelFaster): void {
        this.ObstacleRelativeSpeed = update.ObstacleRelativeSpeed;
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
    }

    _apply_update_for_ObstacleDistanceBecomesVeryClose(update : _ProjectionWrite_ObstacleDistanceBecomesVeryClose): void {
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        this.ObstacleDistance = update.ObstacleDistance;
    }

    _apply_update_for_VehicleManageObstacle(update : _ProjectionWrite_VehicleManageObstacle): void {
        this.VehicleTryKeepSpeed = update.VehicleTryKeepSpeed;
        this.VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
    }

    _apply_update_for_CruiseBecomesAllowed(update : _ProjectionWrite_CruiseBecomesAllowed): void {
        this.CruiseAllowed = update.CruiseAllowed;
    }

    _apply_update_for_VehicleExceedsMaxCruiseSpeed(update : _ProjectionWrite_VehicleExceedsMaxCruiseSpeed): void {
        this.VehicleAtCruiseSpeed = update.VehicleAtCruiseSpeed;
        this.SpeedAboveMax = update.SpeedAboveMax;
    }

    _apply_update_for_CruiseSpeedChangeFinished(update : _ProjectionWrite_CruiseSpeedChangeFinished): void {
        this.VehicleTryKeepSpeed = update.VehicleTryKeepSpeed;
        this.VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
    }

    _apply_update_for_ObstacleDisappears(update : _ProjectionWrite_ObstacleDisappears): void {
        this.ObstacleRelativeSpeed = update.ObstacleRelativeSpeed;
        this.ObstaclePresent = update.ObstaclePresent;
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        this.VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
        this.ObstacleDistance = update.ObstacleDistance;
    }

    _apply_update_for_ExternalForcesBecomesNormal(update : _ProjectionWrite_ExternalForcesBecomesNormal): void {
        this.VehicleCanKeepSpeed = update.VehicleCanKeepSpeed;
    }

    _apply_update_for_ObstacleBecomesOld(update : _ProjectionWrite_ObstacleBecomesOld): void {
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
    }

    _apply_update_for_ObstacleDistanceBecomesBig(update : _ProjectionWrite_ObstacleDistanceBecomesBig): void {
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        this.VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
        this.ObstacleDistance = update.ObstacleDistance;
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

    _OpCache_CruiseBecomesNotAllowed: immutable.Map<boolean, immutable.Map<_ProjectionRead_CruiseBecomesNotAllowed, _ProjectionWrite_CruiseBecomesNotAllowed>> = new immutable.Map();
    _OpCache_tr_CruiseBecomesNotAllowed: immutable.Map<_ProjectionRead__tr_CruiseBecomesNotAllowed, boolean> = new immutable.Map();

    _OpCache_CruiseBecomesAllowed: immutable.Map<boolean, immutable.Map<_ProjectionRead_CruiseBecomesAllowed, _ProjectionWrite_CruiseBecomesAllowed>> = new immutable.Map();
    _OpCache_tr_CruiseBecomesAllowed: immutable.Map<_ProjectionRead__tr_CruiseBecomesAllowed, boolean> = new immutable.Map();

    _OpCache_SetCruiseSpeed: immutable.Map<BSet<BTuple<BBoolean, BBoolean>>, immutable.Map<_ProjectionRead_SetCruiseSpeed, _ProjectionWrite_SetCruiseSpeed>> = new immutable.Map();
    _OpCache_tr_SetCruiseSpeed: immutable.Map<_ProjectionRead__tr_SetCruiseSpeed, BSet<BTuple<BBoolean, BBoolean>>> = new immutable.Map();

    _OpCache_CCInitialisationFinished: immutable.Map<BSet<BTuple<BBoolean, BBoolean>>, immutable.Map<_ProjectionRead_CCInitialisationFinished, _ProjectionWrite_CCInitialisationFinished>> = new immutable.Map();
    _OpCache_tr_CCInitialisationFinished: immutable.Map<_ProjectionRead__tr_CCInitialisationFinished, BSet<BTuple<BBoolean, BBoolean>>> = new immutable.Map();

    _OpCache_CCInitialisationDelayFinished: immutable.Map<boolean, immutable.Map<_ProjectionRead_CCInitialisationDelayFinished, _ProjectionWrite_CCInitialisationDelayFinished>> = new immutable.Map();
    _OpCache_tr_CCInitialisationDelayFinished: immutable.Map<_ProjectionRead__tr_CCInitialisationDelayFinished, boolean> = new immutable.Map();

    _OpCache_CruiseSpeedChangeFinished: immutable.Map<BSet<BTuple<BBoolean, BBoolean>>, immutable.Map<_ProjectionRead_CruiseSpeedChangeFinished, _ProjectionWrite_CruiseSpeedChangeFinished>> = new immutable.Map();
    _OpCache_tr_CruiseSpeedChangeFinished: immutable.Map<_ProjectionRead__tr_CruiseSpeedChangeFinished, BSet<BTuple<BBoolean, BBoolean>>> = new immutable.Map();

    _OpCache_CruiseSpeedChangeDelayFinished: immutable.Map<boolean, immutable.Map<_ProjectionRead_CruiseSpeedChangeDelayFinished, _ProjectionWrite_CruiseSpeedChangeDelayFinished>> = new immutable.Map();
    _OpCache_tr_CruiseSpeedChangeDelayFinished: immutable.Map<_ProjectionRead__tr_CruiseSpeedChangeDelayFinished, boolean> = new immutable.Map();

    _OpCache_CruiseOff: immutable.Map<boolean, immutable.Map<_ProjectionRead_CruiseOff, _ProjectionWrite_CruiseOff>> = new immutable.Map();
    _OpCache_tr_CruiseOff: immutable.Map<_ProjectionRead__tr_CruiseOff, boolean> = new immutable.Map();

    _OpCache_ExternalForcesBecomesExtreme: immutable.Map<boolean, immutable.Map<_ProjectionRead_ExternalForcesBecomesExtreme, _ProjectionWrite_ExternalForcesBecomesExtreme>> = new immutable.Map();
    _OpCache_tr_ExternalForcesBecomesExtreme: immutable.Map<_ProjectionRead__tr_ExternalForcesBecomesExtreme, boolean> = new immutable.Map();

    _OpCache_ExternalForcesBecomesNormal: immutable.Map<boolean, immutable.Map<_ProjectionRead_ExternalForcesBecomesNormal, _ProjectionWrite_ExternalForcesBecomesNormal>> = new immutable.Map();
    _OpCache_tr_ExternalForcesBecomesNormal: immutable.Map<_ProjectionRead__tr_ExternalForcesBecomesNormal, boolean> = new immutable.Map();

    _OpCache_VehicleLeavesCruiseSpeed: immutable.Map<boolean, immutable.Map<_ProjectionRead_VehicleLeavesCruiseSpeed, _ProjectionWrite_VehicleLeavesCruiseSpeed>> = new immutable.Map();
    _OpCache_tr_VehicleLeavesCruiseSpeed: immutable.Map<_ProjectionRead__tr_VehicleLeavesCruiseSpeed, boolean> = new immutable.Map();

    _OpCache_VehicleReachesCruiseSpeed: immutable.Map<boolean, immutable.Map<_ProjectionRead_VehicleReachesCruiseSpeed, _ProjectionWrite_VehicleReachesCruiseSpeed>> = new immutable.Map();
    _OpCache_tr_VehicleReachesCruiseSpeed: immutable.Map<_ProjectionRead__tr_VehicleReachesCruiseSpeed, boolean> = new immutable.Map();

    _OpCache_VehicleExceedsMaxCruiseSpeed: immutable.Map<boolean, immutable.Map<_ProjectionRead_VehicleExceedsMaxCruiseSpeed, _ProjectionWrite_VehicleExceedsMaxCruiseSpeed>> = new immutable.Map();
    _OpCache_tr_VehicleExceedsMaxCruiseSpeed: immutable.Map<_ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed, boolean> = new immutable.Map();

    _OpCache_VehicleFallsBelowMaxCruiseSpeed: immutable.Map<boolean, immutable.Map<_ProjectionRead_VehicleFallsBelowMaxCruiseSpeed, _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed>> = new immutable.Map();
    _OpCache_tr_VehicleFallsBelowMaxCruiseSpeed: immutable.Map<_ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed, boolean> = new immutable.Map();

    _OpCache_ObstacleDistanceBecomesVeryClose: immutable.Map<boolean, immutable.Map<_ProjectionRead_ObstacleDistanceBecomesVeryClose, _ProjectionWrite_ObstacleDistanceBecomesVeryClose>> = new immutable.Map();
    _OpCache_tr_ObstacleDistanceBecomesVeryClose: immutable.Map<_ProjectionRead__tr_ObstacleDistanceBecomesVeryClose, boolean> = new immutable.Map();

    _OpCache_ObstacleDistanceBecomesClose: immutable.Map<boolean, immutable.Map<_ProjectionRead_ObstacleDistanceBecomesClose, _ProjectionWrite_ObstacleDistanceBecomesClose>> = new immutable.Map();
    _OpCache_tr_ObstacleDistanceBecomesClose: immutable.Map<_ProjectionRead__tr_ObstacleDistanceBecomesClose, boolean> = new immutable.Map();

    _OpCache_ObstacleDistanceBecomesBig: immutable.Map<boolean, immutable.Map<_ProjectionRead_ObstacleDistanceBecomesBig, _ProjectionWrite_ObstacleDistanceBecomesBig>> = new immutable.Map();
    _OpCache_tr_ObstacleDistanceBecomesBig: immutable.Map<_ProjectionRead__tr_ObstacleDistanceBecomesBig, boolean> = new immutable.Map();

    _OpCache_ObstacleStartsTravelFaster: immutable.Map<boolean, immutable.Map<_ProjectionRead_ObstacleStartsTravelFaster, _ProjectionWrite_ObstacleStartsTravelFaster>> = new immutable.Map();
    _OpCache_tr_ObstacleStartsTravelFaster: immutable.Map<_ProjectionRead__tr_ObstacleStartsTravelFaster, boolean> = new immutable.Map();

    _OpCache_ObstacleStopsTravelFaster: immutable.Map<boolean, immutable.Map<_ProjectionRead_ObstacleStopsTravelFaster, _ProjectionWrite_ObstacleStopsTravelFaster>> = new immutable.Map();
    _OpCache_tr_ObstacleStopsTravelFaster: immutable.Map<_ProjectionRead__tr_ObstacleStopsTravelFaster, boolean> = new immutable.Map();

    _OpCache_ObstacleStartsTravelSlower: immutable.Map<boolean, immutable.Map<_ProjectionRead_ObstacleStartsTravelSlower, _ProjectionWrite_ObstacleStartsTravelSlower>> = new immutable.Map();
    _OpCache_tr_ObstacleStartsTravelSlower: immutable.Map<_ProjectionRead__tr_ObstacleStartsTravelSlower, boolean> = new immutable.Map();

    _OpCache_ObstacleStopsTravelSlower: immutable.Map<boolean, immutable.Map<_ProjectionRead_ObstacleStopsTravelSlower, _ProjectionWrite_ObstacleStopsTravelSlower>> = new immutable.Map();
    _OpCache_tr_ObstacleStopsTravelSlower: immutable.Map<_ProjectionRead__tr_ObstacleStopsTravelSlower, boolean> = new immutable.Map();

    _OpCache_ObstacleAppearsWhenCruiseActive: immutable.Map<BSet<BTuple<RSset, ODset>>, immutable.Map<_ProjectionRead_ObstacleAppearsWhenCruiseActive, _ProjectionWrite_ObstacleAppearsWhenCruiseActive>> = new immutable.Map();
    _OpCache_tr_ObstacleAppearsWhenCruiseActive: immutable.Map<_ProjectionRead__tr_ObstacleAppearsWhenCruiseActive, BSet<BTuple<RSset, ODset>>> = new immutable.Map();

    _OpCache_ObstacleAppearsWhenCruiseInactive: immutable.Map<BSet<RSset>, immutable.Map<_ProjectionRead_ObstacleAppearsWhenCruiseInactive, _ProjectionWrite_ObstacleAppearsWhenCruiseInactive>> = new immutable.Map();
    _OpCache_tr_ObstacleAppearsWhenCruiseInactive: immutable.Map<_ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive, BSet<RSset>> = new immutable.Map();

    _OpCache_ObstacleDisappears: immutable.Map<boolean, immutable.Map<_ProjectionRead_ObstacleDisappears, _ProjectionWrite_ObstacleDisappears>> = new immutable.Map();
    _OpCache_tr_ObstacleDisappears: immutable.Map<_ProjectionRead__tr_ObstacleDisappears, boolean> = new immutable.Map();

    _OpCache_VehicleManageObstacle: immutable.Map<BSet<BTuple<BBoolean, BBoolean>>, immutable.Map<_ProjectionRead_VehicleManageObstacle, _ProjectionWrite_VehicleManageObstacle>> = new immutable.Map();
    _OpCache_tr_VehicleManageObstacle: immutable.Map<_ProjectionRead__tr_VehicleManageObstacle, BSet<BTuple<BBoolean, BBoolean>>> = new immutable.Map();

    _OpCache_ObstacleBecomesOld: immutable.Map<boolean, immutable.Map<_ProjectionRead_ObstacleBecomesOld, _ProjectionWrite_ObstacleBecomesOld>> = new immutable.Map();
    _OpCache_tr_ObstacleBecomesOld: immutable.Map<_ProjectionRead__tr_ObstacleBecomesOld, boolean> = new immutable.Map();

    _InvCache__check_inv_1: immutable.Map<_ProjectionRead__check_inv_1, boolean> = new immutable.Map();
    _InvCache__check_inv_2: immutable.Map<_ProjectionRead__check_inv_2, boolean> = new immutable.Map();
    _InvCache__check_inv_3: immutable.Map<_ProjectionRead__check_inv_3, boolean> = new immutable.Map();
    _InvCache__check_inv_4: immutable.Map<_ProjectionRead__check_inv_4, boolean> = new immutable.Map();
    _InvCache__check_inv_5: immutable.Map<_ProjectionRead__check_inv_5, boolean> = new immutable.Map();
    _InvCache__check_inv_6: immutable.Map<_ProjectionRead__check_inv_6, boolean> = new immutable.Map();
    _InvCache__check_inv_7: immutable.Map<_ProjectionRead__check_inv_7, boolean> = new immutable.Map();
    _InvCache__check_inv_8: immutable.Map<_ProjectionRead__check_inv_8, boolean> = new immutable.Map();
    _InvCache__check_inv_9: immutable.Map<_ProjectionRead__check_inv_9, boolean> = new immutable.Map();
    _InvCache__check_inv_10: immutable.Map<_ProjectionRead__check_inv_10, boolean> = new immutable.Map();
    _InvCache__check_inv_11: immutable.Map<_ProjectionRead__check_inv_11, boolean> = new immutable.Map();
    _InvCache__check_inv_12: immutable.Map<_ProjectionRead__check_inv_12, boolean> = new immutable.Map();
    _InvCache__check_inv_13: immutable.Map<_ProjectionRead__check_inv_13, boolean> = new immutable.Map();
    _InvCache__check_inv_14: immutable.Map<_ProjectionRead__check_inv_14, boolean> = new immutable.Map();
    _InvCache__check_inv_15: immutable.Map<_ProjectionRead__check_inv_15, boolean> = new immutable.Map();
    _InvCache__check_inv_16: immutable.Map<_ProjectionRead__check_inv_16, boolean> = new immutable.Map();
    _InvCache__check_inv_17: immutable.Map<_ProjectionRead__check_inv_17, boolean> = new immutable.Map();
    _InvCache__check_inv_18: immutable.Map<_ProjectionRead__check_inv_18, boolean> = new immutable.Map();
    _InvCache__check_inv_19: immutable.Map<_ProjectionRead__check_inv_19, boolean> = new immutable.Map();
    _InvCache__check_inv_20: immutable.Map<_ProjectionRead__check_inv_20, boolean> = new immutable.Map();
    _InvCache__check_inv_21: immutable.Map<_ProjectionRead__check_inv_21, boolean> = new immutable.Map();
    _InvCache__check_inv_22: immutable.Map<_ProjectionRead__check_inv_22, boolean> = new immutable.Map();
    _InvCache__check_inv_23: immutable.Map<_ProjectionRead__check_inv_23, boolean> = new immutable.Map();
    _InvCache__check_inv_24: immutable.Map<_ProjectionRead__check_inv_24, boolean> = new immutable.Map();
    _InvCache__check_inv_25: immutable.Map<_ProjectionRead__check_inv_25, boolean> = new immutable.Map();
    _InvCache__check_inv_26: immutable.Map<_ProjectionRead__check_inv_26, boolean> = new immutable.Map();
    _InvCache__check_inv_27: immutable.Map<_ProjectionRead__check_inv_27, boolean> = new immutable.Map();
    _InvCache__check_inv_28: immutable.Map<_ProjectionRead__check_inv_28, boolean> = new immutable.Map();
    _InvCache__check_inv_29: immutable.Map<_ProjectionRead__check_inv_29, boolean> = new immutable.Map();
    _InvCache__check_inv_30: immutable.Map<_ProjectionRead__check_inv_30, boolean> = new immutable.Map();
    _InvCache__check_inv_31: immutable.Map<_ProjectionRead__check_inv_31, boolean> = new immutable.Map();
    _InvCache__check_inv_32: immutable.Map<_ProjectionRead__check_inv_32, boolean> = new immutable.Map();
    _InvCache__check_inv_33: immutable.Map<_ProjectionRead__check_inv_33, boolean> = new immutable.Map();
    _InvCache__check_inv_34: immutable.Map<_ProjectionRead__check_inv_34, boolean> = new immutable.Map();
    _InvCache__check_inv_35: immutable.Map<_ProjectionRead__check_inv_35, boolean> = new immutable.Map();
    _InvCache__check_inv_36: immutable.Map<_ProjectionRead__check_inv_36, boolean> = new immutable.Map();
    _InvCache__check_inv_37: immutable.Map<_ProjectionRead__check_inv_37, boolean> = new immutable.Map();
    _InvCache__check_inv_38: immutable.Map<_ProjectionRead__check_inv_38, boolean> = new immutable.Map();
    _InvCache__check_inv_39: immutable.Map<_ProjectionRead__check_inv_39, boolean> = new immutable.Map();

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
            let read__tr_CruiseBecomesNotAllowed_state : _ProjectionRead__tr_CruiseBecomesNotAllowed = state._projected_state_for__tr_CruiseBecomesNotAllowed();
            let _obj__trid_1: any = this._OpCache_tr_CruiseBecomesNotAllowed.get(read__tr_CruiseBecomesNotAllowed_state);
            let _trid_1: boolean;
            if(_obj__trid_1 == null) {
                _trid_1 = state._tr_CruiseBecomesNotAllowed();
                this._OpCache_tr_CruiseBecomesNotAllowed = this._OpCache_tr_CruiseBecomesNotAllowed.set(read__tr_CruiseBecomesNotAllowed_state, _trid_1);
            } else {
                _trid_1 = _obj__trid_1;
            }

            if(_trid_1) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_CruiseBecomesNotAllowed = state._projected_state_for_CruiseBecomesNotAllowed();
                let _OpCache_with_parameter_CruiseBecomesNotAllowed: immutable.Map = this._OpCache_CruiseBecomesNotAllowed.get(_trid_1);
                if(_OpCache_with_parameter_CruiseBecomesNotAllowed != null) {
                    let writeState: _ProjectionWrite_CruiseBecomesNotAllowed = _OpCache_with_parameter_CruiseBecomesNotAllowed.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_CruiseBecomesNotAllowed(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.CruiseBecomesNotAllowed();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_CruiseBecomesNotAllowed();
                        _OpCache_with_parameter_CruiseBecomesNotAllowed = _OpCache_with_parameter_CruiseBecomesNotAllowed.set(readState, writeState);
                        this._OpCache_CruiseBecomesNotAllowed = this._OpCache_CruiseBecomesNotAllowed.set(_trid_1, _OpCache_with_parameter_CruiseBecomesNotAllowed);
                    }

                } else {
                    copiedState.CruiseBecomesNotAllowed();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_CruiseBecomesNotAllowed = copiedState._update_for_CruiseBecomesNotAllowed();
                    _OpCache_with_parameter_CruiseBecomesNotAllowed = new immutable.Map().set(readState, writeState);
                    this._OpCache_CruiseBecomesNotAllowed = this._OpCache_CruiseBecomesNotAllowed.set(_trid_1, _OpCache_with_parameter_CruiseBecomesNotAllowed);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_CruiseBecomesAllowed_state : _ProjectionRead__tr_CruiseBecomesAllowed = state._projected_state_for__tr_CruiseBecomesAllowed();
            let _obj__trid_2: any = this._OpCache_tr_CruiseBecomesAllowed.get(read__tr_CruiseBecomesAllowed_state);
            let _trid_2: boolean;
            if(_obj__trid_2 == null) {
                _trid_2 = state._tr_CruiseBecomesAllowed();
                this._OpCache_tr_CruiseBecomesAllowed = this._OpCache_tr_CruiseBecomesAllowed.set(read__tr_CruiseBecomesAllowed_state, _trid_2);
            } else {
                _trid_2 = _obj__trid_2;
            }

            if(_trid_2) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_CruiseBecomesAllowed = state._projected_state_for_CruiseBecomesAllowed();
                let _OpCache_with_parameter_CruiseBecomesAllowed: immutable.Map = this._OpCache_CruiseBecomesAllowed.get(_trid_2);
                if(_OpCache_with_parameter_CruiseBecomesAllowed != null) {
                    let writeState: _ProjectionWrite_CruiseBecomesAllowed = _OpCache_with_parameter_CruiseBecomesAllowed.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_CruiseBecomesAllowed(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.CruiseBecomesAllowed();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_CruiseBecomesAllowed();
                        _OpCache_with_parameter_CruiseBecomesAllowed = _OpCache_with_parameter_CruiseBecomesAllowed.set(readState, writeState);
                        this._OpCache_CruiseBecomesAllowed = this._OpCache_CruiseBecomesAllowed.set(_trid_2, _OpCache_with_parameter_CruiseBecomesAllowed);
                    }

                } else {
                    copiedState.CruiseBecomesAllowed();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_CruiseBecomesAllowed = copiedState._update_for_CruiseBecomesAllowed();
                    _OpCache_with_parameter_CruiseBecomesAllowed = new immutable.Map().set(readState, writeState);
                    this._OpCache_CruiseBecomesAllowed = this._OpCache_CruiseBecomesAllowed.set(_trid_2, _OpCache_with_parameter_CruiseBecomesAllowed);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_SetCruiseSpeed_state : _ProjectionRead__tr_SetCruiseSpeed = state._projected_state_for__tr_SetCruiseSpeed();
            let _trid_3 : BSet<BTuple<BBoolean, BBoolean>>  = this._OpCache_tr_SetCruiseSpeed.get(read__tr_SetCruiseSpeed_state);
            if(_trid_3 == null) {
                _trid_3 = state._tr_SetCruiseSpeed();
                this._OpCache_tr_SetCruiseSpeed = this._OpCache_tr_SetCruiseSpeed.set(read__tr_SetCruiseSpeed_state, _trid_3);
            }

            for(let param of _trid_3) {
                let _tmp_1: BBoolean = param.projection2();
                let _tmp_2: BBoolean = param.projection1();

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_SetCruiseSpeed = state._projected_state_for_SetCruiseSpeed();
                let _OpCache_with_parameter_SetCruiseSpeed: immutable.Map = this._OpCache_SetCruiseSpeed.get(param);
                if(_OpCache_with_parameter_SetCruiseSpeed != null) {
                    let writeState: _ProjectionWrite_SetCruiseSpeed = _OpCache_with_parameter_SetCruiseSpeed.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_SetCruiseSpeed(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.SetCruiseSpeed(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_SetCruiseSpeed();
                        _OpCache_with_parameter_SetCruiseSpeed = _OpCache_with_parameter_SetCruiseSpeed.set(readState, writeState);
                        this._OpCache_SetCruiseSpeed = this._OpCache_SetCruiseSpeed.set(param, _OpCache_with_parameter_SetCruiseSpeed);
                    }

                } else {
                    copiedState.SetCruiseSpeed(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_SetCruiseSpeed = copiedState._update_for_SetCruiseSpeed();
                    _OpCache_with_parameter_SetCruiseSpeed = new immutable.Map().set(readState, writeState);
                    this._OpCache_SetCruiseSpeed = this._OpCache_SetCruiseSpeed.set(param, _OpCache_with_parameter_SetCruiseSpeed);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_CCInitialisationFinished_state : _ProjectionRead__tr_CCInitialisationFinished = state._projected_state_for__tr_CCInitialisationFinished();
            let _trid_4 : BSet<BTuple<BBoolean, BBoolean>>  = this._OpCache_tr_CCInitialisationFinished.get(read__tr_CCInitialisationFinished_state);
            if(_trid_4 == null) {
                _trid_4 = state._tr_CCInitialisationFinished();
                this._OpCache_tr_CCInitialisationFinished = this._OpCache_tr_CCInitialisationFinished.set(read__tr_CCInitialisationFinished_state, _trid_4);
            }

            for(let param of _trid_4) {
                let _tmp_1: BBoolean = param.projection2();
                let _tmp_2: BBoolean = param.projection1();

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_CCInitialisationFinished = state._projected_state_for_CCInitialisationFinished();
                let _OpCache_with_parameter_CCInitialisationFinished: immutable.Map = this._OpCache_CCInitialisationFinished.get(param);
                if(_OpCache_with_parameter_CCInitialisationFinished != null) {
                    let writeState: _ProjectionWrite_CCInitialisationFinished = _OpCache_with_parameter_CCInitialisationFinished.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_CCInitialisationFinished(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.CCInitialisationFinished(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_CCInitialisationFinished();
                        _OpCache_with_parameter_CCInitialisationFinished = _OpCache_with_parameter_CCInitialisationFinished.set(readState, writeState);
                        this._OpCache_CCInitialisationFinished = this._OpCache_CCInitialisationFinished.set(param, _OpCache_with_parameter_CCInitialisationFinished);
                    }

                } else {
                    copiedState.CCInitialisationFinished(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_CCInitialisationFinished = copiedState._update_for_CCInitialisationFinished();
                    _OpCache_with_parameter_CCInitialisationFinished = new immutable.Map().set(readState, writeState);
                    this._OpCache_CCInitialisationFinished = this._OpCache_CCInitialisationFinished.set(param, _OpCache_with_parameter_CCInitialisationFinished);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_CCInitialisationDelayFinished_state : _ProjectionRead__tr_CCInitialisationDelayFinished = state._projected_state_for__tr_CCInitialisationDelayFinished();
            let _obj__trid_5: any = this._OpCache_tr_CCInitialisationDelayFinished.get(read__tr_CCInitialisationDelayFinished_state);
            let _trid_5: boolean;
            if(_obj__trid_5 == null) {
                _trid_5 = state._tr_CCInitialisationDelayFinished();
                this._OpCache_tr_CCInitialisationDelayFinished = this._OpCache_tr_CCInitialisationDelayFinished.set(read__tr_CCInitialisationDelayFinished_state, _trid_5);
            } else {
                _trid_5 = _obj__trid_5;
            }

            if(_trid_5) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_CCInitialisationDelayFinished = state._projected_state_for_CCInitialisationDelayFinished();
                let _OpCache_with_parameter_CCInitialisationDelayFinished: immutable.Map = this._OpCache_CCInitialisationDelayFinished.get(_trid_5);
                if(_OpCache_with_parameter_CCInitialisationDelayFinished != null) {
                    let writeState: _ProjectionWrite_CCInitialisationDelayFinished = _OpCache_with_parameter_CCInitialisationDelayFinished.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_CCInitialisationDelayFinished(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.CCInitialisationDelayFinished();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_CCInitialisationDelayFinished();
                        _OpCache_with_parameter_CCInitialisationDelayFinished = _OpCache_with_parameter_CCInitialisationDelayFinished.set(readState, writeState);
                        this._OpCache_CCInitialisationDelayFinished = this._OpCache_CCInitialisationDelayFinished.set(_trid_5, _OpCache_with_parameter_CCInitialisationDelayFinished);
                    }

                } else {
                    copiedState.CCInitialisationDelayFinished();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_CCInitialisationDelayFinished = copiedState._update_for_CCInitialisationDelayFinished();
                    _OpCache_with_parameter_CCInitialisationDelayFinished = new immutable.Map().set(readState, writeState);
                    this._OpCache_CCInitialisationDelayFinished = this._OpCache_CCInitialisationDelayFinished.set(_trid_5, _OpCache_with_parameter_CCInitialisationDelayFinished);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_CruiseSpeedChangeFinished_state : _ProjectionRead__tr_CruiseSpeedChangeFinished = state._projected_state_for__tr_CruiseSpeedChangeFinished();
            let _trid_6 : BSet<BTuple<BBoolean, BBoolean>>  = this._OpCache_tr_CruiseSpeedChangeFinished.get(read__tr_CruiseSpeedChangeFinished_state);
            if(_trid_6 == null) {
                _trid_6 = state._tr_CruiseSpeedChangeFinished();
                this._OpCache_tr_CruiseSpeedChangeFinished = this._OpCache_tr_CruiseSpeedChangeFinished.set(read__tr_CruiseSpeedChangeFinished_state, _trid_6);
            }

            for(let param of _trid_6) {
                let _tmp_1: BBoolean = param.projection2();
                let _tmp_2: BBoolean = param.projection1();

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_CruiseSpeedChangeFinished = state._projected_state_for_CruiseSpeedChangeFinished();
                let _OpCache_with_parameter_CruiseSpeedChangeFinished: immutable.Map = this._OpCache_CruiseSpeedChangeFinished.get(param);
                if(_OpCache_with_parameter_CruiseSpeedChangeFinished != null) {
                    let writeState: _ProjectionWrite_CruiseSpeedChangeFinished = _OpCache_with_parameter_CruiseSpeedChangeFinished.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_CruiseSpeedChangeFinished(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.CruiseSpeedChangeFinished(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_CruiseSpeedChangeFinished();
                        _OpCache_with_parameter_CruiseSpeedChangeFinished = _OpCache_with_parameter_CruiseSpeedChangeFinished.set(readState, writeState);
                        this._OpCache_CruiseSpeedChangeFinished = this._OpCache_CruiseSpeedChangeFinished.set(param, _OpCache_with_parameter_CruiseSpeedChangeFinished);
                    }

                } else {
                    copiedState.CruiseSpeedChangeFinished(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_CruiseSpeedChangeFinished = copiedState._update_for_CruiseSpeedChangeFinished();
                    _OpCache_with_parameter_CruiseSpeedChangeFinished = new immutable.Map().set(readState, writeState);
                    this._OpCache_CruiseSpeedChangeFinished = this._OpCache_CruiseSpeedChangeFinished.set(param, _OpCache_with_parameter_CruiseSpeedChangeFinished);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_CruiseSpeedChangeDelayFinished_state : _ProjectionRead__tr_CruiseSpeedChangeDelayFinished = state._projected_state_for__tr_CruiseSpeedChangeDelayFinished();
            let _obj__trid_7: any = this._OpCache_tr_CruiseSpeedChangeDelayFinished.get(read__tr_CruiseSpeedChangeDelayFinished_state);
            let _trid_7: boolean;
            if(_obj__trid_7 == null) {
                _trid_7 = state._tr_CruiseSpeedChangeDelayFinished();
                this._OpCache_tr_CruiseSpeedChangeDelayFinished = this._OpCache_tr_CruiseSpeedChangeDelayFinished.set(read__tr_CruiseSpeedChangeDelayFinished_state, _trid_7);
            } else {
                _trid_7 = _obj__trid_7;
            }

            if(_trid_7) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_CruiseSpeedChangeDelayFinished = state._projected_state_for_CruiseSpeedChangeDelayFinished();
                let _OpCache_with_parameter_CruiseSpeedChangeDelayFinished: immutable.Map = this._OpCache_CruiseSpeedChangeDelayFinished.get(_trid_7);
                if(_OpCache_with_parameter_CruiseSpeedChangeDelayFinished != null) {
                    let writeState: _ProjectionWrite_CruiseSpeedChangeDelayFinished = _OpCache_with_parameter_CruiseSpeedChangeDelayFinished.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_CruiseSpeedChangeDelayFinished(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.CruiseSpeedChangeDelayFinished();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_CruiseSpeedChangeDelayFinished();
                        _OpCache_with_parameter_CruiseSpeedChangeDelayFinished = _OpCache_with_parameter_CruiseSpeedChangeDelayFinished.set(readState, writeState);
                        this._OpCache_CruiseSpeedChangeDelayFinished = this._OpCache_CruiseSpeedChangeDelayFinished.set(_trid_7, _OpCache_with_parameter_CruiseSpeedChangeDelayFinished);
                    }

                } else {
                    copiedState.CruiseSpeedChangeDelayFinished();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_CruiseSpeedChangeDelayFinished = copiedState._update_for_CruiseSpeedChangeDelayFinished();
                    _OpCache_with_parameter_CruiseSpeedChangeDelayFinished = new immutable.Map().set(readState, writeState);
                    this._OpCache_CruiseSpeedChangeDelayFinished = this._OpCache_CruiseSpeedChangeDelayFinished.set(_trid_7, _OpCache_with_parameter_CruiseSpeedChangeDelayFinished);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_CruiseOff_state : _ProjectionRead__tr_CruiseOff = state._projected_state_for__tr_CruiseOff();
            let _obj__trid_8: any = this._OpCache_tr_CruiseOff.get(read__tr_CruiseOff_state);
            let _trid_8: boolean;
            if(_obj__trid_8 == null) {
                _trid_8 = state._tr_CruiseOff();
                this._OpCache_tr_CruiseOff = this._OpCache_tr_CruiseOff.set(read__tr_CruiseOff_state, _trid_8);
            } else {
                _trid_8 = _obj__trid_8;
            }

            if(_trid_8) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_CruiseOff = state._projected_state_for_CruiseOff();
                let _OpCache_with_parameter_CruiseOff: immutable.Map = this._OpCache_CruiseOff.get(_trid_8);
                if(_OpCache_with_parameter_CruiseOff != null) {
                    let writeState: _ProjectionWrite_CruiseOff = _OpCache_with_parameter_CruiseOff.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_CruiseOff(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.CruiseOff();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_CruiseOff();
                        _OpCache_with_parameter_CruiseOff = _OpCache_with_parameter_CruiseOff.set(readState, writeState);
                        this._OpCache_CruiseOff = this._OpCache_CruiseOff.set(_trid_8, _OpCache_with_parameter_CruiseOff);
                    }

                } else {
                    copiedState.CruiseOff();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_CruiseOff = copiedState._update_for_CruiseOff();
                    _OpCache_with_parameter_CruiseOff = new immutable.Map().set(readState, writeState);
                    this._OpCache_CruiseOff = this._OpCache_CruiseOff.set(_trid_8, _OpCache_with_parameter_CruiseOff);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_ExternalForcesBecomesExtreme_state : _ProjectionRead__tr_ExternalForcesBecomesExtreme = state._projected_state_for__tr_ExternalForcesBecomesExtreme();
            let _obj__trid_9: any = this._OpCache_tr_ExternalForcesBecomesExtreme.get(read__tr_ExternalForcesBecomesExtreme_state);
            let _trid_9: boolean;
            if(_obj__trid_9 == null) {
                _trid_9 = state._tr_ExternalForcesBecomesExtreme();
                this._OpCache_tr_ExternalForcesBecomesExtreme = this._OpCache_tr_ExternalForcesBecomesExtreme.set(read__tr_ExternalForcesBecomesExtreme_state, _trid_9);
            } else {
                _trid_9 = _obj__trid_9;
            }

            if(_trid_9) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_ExternalForcesBecomesExtreme = state._projected_state_for_ExternalForcesBecomesExtreme();
                let _OpCache_with_parameter_ExternalForcesBecomesExtreme: immutable.Map = this._OpCache_ExternalForcesBecomesExtreme.get(_trid_9);
                if(_OpCache_with_parameter_ExternalForcesBecomesExtreme != null) {
                    let writeState: _ProjectionWrite_ExternalForcesBecomesExtreme = _OpCache_with_parameter_ExternalForcesBecomesExtreme.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_ExternalForcesBecomesExtreme(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.ExternalForcesBecomesExtreme();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_ExternalForcesBecomesExtreme();
                        _OpCache_with_parameter_ExternalForcesBecomesExtreme = _OpCache_with_parameter_ExternalForcesBecomesExtreme.set(readState, writeState);
                        this._OpCache_ExternalForcesBecomesExtreme = this._OpCache_ExternalForcesBecomesExtreme.set(_trid_9, _OpCache_with_parameter_ExternalForcesBecomesExtreme);
                    }

                } else {
                    copiedState.ExternalForcesBecomesExtreme();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_ExternalForcesBecomesExtreme = copiedState._update_for_ExternalForcesBecomesExtreme();
                    _OpCache_with_parameter_ExternalForcesBecomesExtreme = new immutable.Map().set(readState, writeState);
                    this._OpCache_ExternalForcesBecomesExtreme = this._OpCache_ExternalForcesBecomesExtreme.set(_trid_9, _OpCache_with_parameter_ExternalForcesBecomesExtreme);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_ExternalForcesBecomesNormal_state : _ProjectionRead__tr_ExternalForcesBecomesNormal = state._projected_state_for__tr_ExternalForcesBecomesNormal();
            let _obj__trid_10: any = this._OpCache_tr_ExternalForcesBecomesNormal.get(read__tr_ExternalForcesBecomesNormal_state);
            let _trid_10: boolean;
            if(_obj__trid_10 == null) {
                _trid_10 = state._tr_ExternalForcesBecomesNormal();
                this._OpCache_tr_ExternalForcesBecomesNormal = this._OpCache_tr_ExternalForcesBecomesNormal.set(read__tr_ExternalForcesBecomesNormal_state, _trid_10);
            } else {
                _trid_10 = _obj__trid_10;
            }

            if(_trid_10) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_ExternalForcesBecomesNormal = state._projected_state_for_ExternalForcesBecomesNormal();
                let _OpCache_with_parameter_ExternalForcesBecomesNormal: immutable.Map = this._OpCache_ExternalForcesBecomesNormal.get(_trid_10);
                if(_OpCache_with_parameter_ExternalForcesBecomesNormal != null) {
                    let writeState: _ProjectionWrite_ExternalForcesBecomesNormal = _OpCache_with_parameter_ExternalForcesBecomesNormal.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_ExternalForcesBecomesNormal(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.ExternalForcesBecomesNormal();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_ExternalForcesBecomesNormal();
                        _OpCache_with_parameter_ExternalForcesBecomesNormal = _OpCache_with_parameter_ExternalForcesBecomesNormal.set(readState, writeState);
                        this._OpCache_ExternalForcesBecomesNormal = this._OpCache_ExternalForcesBecomesNormal.set(_trid_10, _OpCache_with_parameter_ExternalForcesBecomesNormal);
                    }

                } else {
                    copiedState.ExternalForcesBecomesNormal();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_ExternalForcesBecomesNormal = copiedState._update_for_ExternalForcesBecomesNormal();
                    _OpCache_with_parameter_ExternalForcesBecomesNormal = new immutable.Map().set(readState, writeState);
                    this._OpCache_ExternalForcesBecomesNormal = this._OpCache_ExternalForcesBecomesNormal.set(_trid_10, _OpCache_with_parameter_ExternalForcesBecomesNormal);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_VehicleLeavesCruiseSpeed_state : _ProjectionRead__tr_VehicleLeavesCruiseSpeed = state._projected_state_for__tr_VehicleLeavesCruiseSpeed();
            let _obj__trid_11: any = this._OpCache_tr_VehicleLeavesCruiseSpeed.get(read__tr_VehicleLeavesCruiseSpeed_state);
            let _trid_11: boolean;
            if(_obj__trid_11 == null) {
                _trid_11 = state._tr_VehicleLeavesCruiseSpeed();
                this._OpCache_tr_VehicleLeavesCruiseSpeed = this._OpCache_tr_VehicleLeavesCruiseSpeed.set(read__tr_VehicleLeavesCruiseSpeed_state, _trid_11);
            } else {
                _trid_11 = _obj__trid_11;
            }

            if(_trid_11) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_VehicleLeavesCruiseSpeed = state._projected_state_for_VehicleLeavesCruiseSpeed();
                let _OpCache_with_parameter_VehicleLeavesCruiseSpeed: immutable.Map = this._OpCache_VehicleLeavesCruiseSpeed.get(_trid_11);
                if(_OpCache_with_parameter_VehicleLeavesCruiseSpeed != null) {
                    let writeState: _ProjectionWrite_VehicleLeavesCruiseSpeed = _OpCache_with_parameter_VehicleLeavesCruiseSpeed.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_VehicleLeavesCruiseSpeed(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.VehicleLeavesCruiseSpeed();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_VehicleLeavesCruiseSpeed();
                        _OpCache_with_parameter_VehicleLeavesCruiseSpeed = _OpCache_with_parameter_VehicleLeavesCruiseSpeed.set(readState, writeState);
                        this._OpCache_VehicleLeavesCruiseSpeed = this._OpCache_VehicleLeavesCruiseSpeed.set(_trid_11, _OpCache_with_parameter_VehicleLeavesCruiseSpeed);
                    }

                } else {
                    copiedState.VehicleLeavesCruiseSpeed();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_VehicleLeavesCruiseSpeed = copiedState._update_for_VehicleLeavesCruiseSpeed();
                    _OpCache_with_parameter_VehicleLeavesCruiseSpeed = new immutable.Map().set(readState, writeState);
                    this._OpCache_VehicleLeavesCruiseSpeed = this._OpCache_VehicleLeavesCruiseSpeed.set(_trid_11, _OpCache_with_parameter_VehicleLeavesCruiseSpeed);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_VehicleReachesCruiseSpeed_state : _ProjectionRead__tr_VehicleReachesCruiseSpeed = state._projected_state_for__tr_VehicleReachesCruiseSpeed();
            let _obj__trid_12: any = this._OpCache_tr_VehicleReachesCruiseSpeed.get(read__tr_VehicleReachesCruiseSpeed_state);
            let _trid_12: boolean;
            if(_obj__trid_12 == null) {
                _trid_12 = state._tr_VehicleReachesCruiseSpeed();
                this._OpCache_tr_VehicleReachesCruiseSpeed = this._OpCache_tr_VehicleReachesCruiseSpeed.set(read__tr_VehicleReachesCruiseSpeed_state, _trid_12);
            } else {
                _trid_12 = _obj__trid_12;
            }

            if(_trid_12) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_VehicleReachesCruiseSpeed = state._projected_state_for_VehicleReachesCruiseSpeed();
                let _OpCache_with_parameter_VehicleReachesCruiseSpeed: immutable.Map = this._OpCache_VehicleReachesCruiseSpeed.get(_trid_12);
                if(_OpCache_with_parameter_VehicleReachesCruiseSpeed != null) {
                    let writeState: _ProjectionWrite_VehicleReachesCruiseSpeed = _OpCache_with_parameter_VehicleReachesCruiseSpeed.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_VehicleReachesCruiseSpeed(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.VehicleReachesCruiseSpeed();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_VehicleReachesCruiseSpeed();
                        _OpCache_with_parameter_VehicleReachesCruiseSpeed = _OpCache_with_parameter_VehicleReachesCruiseSpeed.set(readState, writeState);
                        this._OpCache_VehicleReachesCruiseSpeed = this._OpCache_VehicleReachesCruiseSpeed.set(_trid_12, _OpCache_with_parameter_VehicleReachesCruiseSpeed);
                    }

                } else {
                    copiedState.VehicleReachesCruiseSpeed();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_VehicleReachesCruiseSpeed = copiedState._update_for_VehicleReachesCruiseSpeed();
                    _OpCache_with_parameter_VehicleReachesCruiseSpeed = new immutable.Map().set(readState, writeState);
                    this._OpCache_VehicleReachesCruiseSpeed = this._OpCache_VehicleReachesCruiseSpeed.set(_trid_12, _OpCache_with_parameter_VehicleReachesCruiseSpeed);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_VehicleExceedsMaxCruiseSpeed_state : _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed = state._projected_state_for__tr_VehicleExceedsMaxCruiseSpeed();
            let _obj__trid_13: any = this._OpCache_tr_VehicleExceedsMaxCruiseSpeed.get(read__tr_VehicleExceedsMaxCruiseSpeed_state);
            let _trid_13: boolean;
            if(_obj__trid_13 == null) {
                _trid_13 = state._tr_VehicleExceedsMaxCruiseSpeed();
                this._OpCache_tr_VehicleExceedsMaxCruiseSpeed = this._OpCache_tr_VehicleExceedsMaxCruiseSpeed.set(read__tr_VehicleExceedsMaxCruiseSpeed_state, _trid_13);
            } else {
                _trid_13 = _obj__trid_13;
            }

            if(_trid_13) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_VehicleExceedsMaxCruiseSpeed = state._projected_state_for_VehicleExceedsMaxCruiseSpeed();
                let _OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed: immutable.Map = this._OpCache_VehicleExceedsMaxCruiseSpeed.get(_trid_13);
                if(_OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed != null) {
                    let writeState: _ProjectionWrite_VehicleExceedsMaxCruiseSpeed = _OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_VehicleExceedsMaxCruiseSpeed(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.VehicleExceedsMaxCruiseSpeed();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_VehicleExceedsMaxCruiseSpeed();
                        _OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed = _OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed.set(readState, writeState);
                        this._OpCache_VehicleExceedsMaxCruiseSpeed = this._OpCache_VehicleExceedsMaxCruiseSpeed.set(_trid_13, _OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed);
                    }

                } else {
                    copiedState.VehicleExceedsMaxCruiseSpeed();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_VehicleExceedsMaxCruiseSpeed = copiedState._update_for_VehicleExceedsMaxCruiseSpeed();
                    _OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed = new immutable.Map().set(readState, writeState);
                    this._OpCache_VehicleExceedsMaxCruiseSpeed = this._OpCache_VehicleExceedsMaxCruiseSpeed.set(_trid_13, _OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_VehicleFallsBelowMaxCruiseSpeed_state : _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed = state._projected_state_for__tr_VehicleFallsBelowMaxCruiseSpeed();
            let _obj__trid_14: any = this._OpCache_tr_VehicleFallsBelowMaxCruiseSpeed.get(read__tr_VehicleFallsBelowMaxCruiseSpeed_state);
            let _trid_14: boolean;
            if(_obj__trid_14 == null) {
                _trid_14 = state._tr_VehicleFallsBelowMaxCruiseSpeed();
                this._OpCache_tr_VehicleFallsBelowMaxCruiseSpeed = this._OpCache_tr_VehicleFallsBelowMaxCruiseSpeed.set(read__tr_VehicleFallsBelowMaxCruiseSpeed_state, _trid_14);
            } else {
                _trid_14 = _obj__trid_14;
            }

            if(_trid_14) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed = state._projected_state_for_VehicleFallsBelowMaxCruiseSpeed();
                let _OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed: immutable.Map = this._OpCache_VehicleFallsBelowMaxCruiseSpeed.get(_trid_14);
                if(_OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed != null) {
                    let writeState: _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed = _OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_VehicleFallsBelowMaxCruiseSpeed(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.VehicleFallsBelowMaxCruiseSpeed();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_VehicleFallsBelowMaxCruiseSpeed();
                        _OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed = _OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed.set(readState, writeState);
                        this._OpCache_VehicleFallsBelowMaxCruiseSpeed = this._OpCache_VehicleFallsBelowMaxCruiseSpeed.set(_trid_14, _OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed);
                    }

                } else {
                    copiedState.VehicleFallsBelowMaxCruiseSpeed();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed = copiedState._update_for_VehicleFallsBelowMaxCruiseSpeed();
                    _OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed = new immutable.Map().set(readState, writeState);
                    this._OpCache_VehicleFallsBelowMaxCruiseSpeed = this._OpCache_VehicleFallsBelowMaxCruiseSpeed.set(_trid_14, _OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_ObstacleDistanceBecomesVeryClose_state : _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose = state._projected_state_for__tr_ObstacleDistanceBecomesVeryClose();
            let _obj__trid_15: any = this._OpCache_tr_ObstacleDistanceBecomesVeryClose.get(read__tr_ObstacleDistanceBecomesVeryClose_state);
            let _trid_15: boolean;
            if(_obj__trid_15 == null) {
                _trid_15 = state._tr_ObstacleDistanceBecomesVeryClose();
                this._OpCache_tr_ObstacleDistanceBecomesVeryClose = this._OpCache_tr_ObstacleDistanceBecomesVeryClose.set(read__tr_ObstacleDistanceBecomesVeryClose_state, _trid_15);
            } else {
                _trid_15 = _obj__trid_15;
            }

            if(_trid_15) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_ObstacleDistanceBecomesVeryClose = state._projected_state_for_ObstacleDistanceBecomesVeryClose();
                let _OpCache_with_parameter_ObstacleDistanceBecomesVeryClose: immutable.Map = this._OpCache_ObstacleDistanceBecomesVeryClose.get(_trid_15);
                if(_OpCache_with_parameter_ObstacleDistanceBecomesVeryClose != null) {
                    let writeState: _ProjectionWrite_ObstacleDistanceBecomesVeryClose = _OpCache_with_parameter_ObstacleDistanceBecomesVeryClose.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_ObstacleDistanceBecomesVeryClose(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.ObstacleDistanceBecomesVeryClose();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_ObstacleDistanceBecomesVeryClose();
                        _OpCache_with_parameter_ObstacleDistanceBecomesVeryClose = _OpCache_with_parameter_ObstacleDistanceBecomesVeryClose.set(readState, writeState);
                        this._OpCache_ObstacleDistanceBecomesVeryClose = this._OpCache_ObstacleDistanceBecomesVeryClose.set(_trid_15, _OpCache_with_parameter_ObstacleDistanceBecomesVeryClose);
                    }

                } else {
                    copiedState.ObstacleDistanceBecomesVeryClose();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_ObstacleDistanceBecomesVeryClose = copiedState._update_for_ObstacleDistanceBecomesVeryClose();
                    _OpCache_with_parameter_ObstacleDistanceBecomesVeryClose = new immutable.Map().set(readState, writeState);
                    this._OpCache_ObstacleDistanceBecomesVeryClose = this._OpCache_ObstacleDistanceBecomesVeryClose.set(_trid_15, _OpCache_with_parameter_ObstacleDistanceBecomesVeryClose);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_ObstacleDistanceBecomesClose_state : _ProjectionRead__tr_ObstacleDistanceBecomesClose = state._projected_state_for__tr_ObstacleDistanceBecomesClose();
            let _obj__trid_16: any = this._OpCache_tr_ObstacleDistanceBecomesClose.get(read__tr_ObstacleDistanceBecomesClose_state);
            let _trid_16: boolean;
            if(_obj__trid_16 == null) {
                _trid_16 = state._tr_ObstacleDistanceBecomesClose();
                this._OpCache_tr_ObstacleDistanceBecomesClose = this._OpCache_tr_ObstacleDistanceBecomesClose.set(read__tr_ObstacleDistanceBecomesClose_state, _trid_16);
            } else {
                _trid_16 = _obj__trid_16;
            }

            if(_trid_16) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_ObstacleDistanceBecomesClose = state._projected_state_for_ObstacleDistanceBecomesClose();
                let _OpCache_with_parameter_ObstacleDistanceBecomesClose: immutable.Map = this._OpCache_ObstacleDistanceBecomesClose.get(_trid_16);
                if(_OpCache_with_parameter_ObstacleDistanceBecomesClose != null) {
                    let writeState: _ProjectionWrite_ObstacleDistanceBecomesClose = _OpCache_with_parameter_ObstacleDistanceBecomesClose.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_ObstacleDistanceBecomesClose(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.ObstacleDistanceBecomesClose();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_ObstacleDistanceBecomesClose();
                        _OpCache_with_parameter_ObstacleDistanceBecomesClose = _OpCache_with_parameter_ObstacleDistanceBecomesClose.set(readState, writeState);
                        this._OpCache_ObstacleDistanceBecomesClose = this._OpCache_ObstacleDistanceBecomesClose.set(_trid_16, _OpCache_with_parameter_ObstacleDistanceBecomesClose);
                    }

                } else {
                    copiedState.ObstacleDistanceBecomesClose();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_ObstacleDistanceBecomesClose = copiedState._update_for_ObstacleDistanceBecomesClose();
                    _OpCache_with_parameter_ObstacleDistanceBecomesClose = new immutable.Map().set(readState, writeState);
                    this._OpCache_ObstacleDistanceBecomesClose = this._OpCache_ObstacleDistanceBecomesClose.set(_trid_16, _OpCache_with_parameter_ObstacleDistanceBecomesClose);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_ObstacleDistanceBecomesBig_state : _ProjectionRead__tr_ObstacleDistanceBecomesBig = state._projected_state_for__tr_ObstacleDistanceBecomesBig();
            let _obj__trid_17: any = this._OpCache_tr_ObstacleDistanceBecomesBig.get(read__tr_ObstacleDistanceBecomesBig_state);
            let _trid_17: boolean;
            if(_obj__trid_17 == null) {
                _trid_17 = state._tr_ObstacleDistanceBecomesBig();
                this._OpCache_tr_ObstacleDistanceBecomesBig = this._OpCache_tr_ObstacleDistanceBecomesBig.set(read__tr_ObstacleDistanceBecomesBig_state, _trid_17);
            } else {
                _trid_17 = _obj__trid_17;
            }

            if(_trid_17) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_ObstacleDistanceBecomesBig = state._projected_state_for_ObstacleDistanceBecomesBig();
                let _OpCache_with_parameter_ObstacleDistanceBecomesBig: immutable.Map = this._OpCache_ObstacleDistanceBecomesBig.get(_trid_17);
                if(_OpCache_with_parameter_ObstacleDistanceBecomesBig != null) {
                    let writeState: _ProjectionWrite_ObstacleDistanceBecomesBig = _OpCache_with_parameter_ObstacleDistanceBecomesBig.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_ObstacleDistanceBecomesBig(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.ObstacleDistanceBecomesBig();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_ObstacleDistanceBecomesBig();
                        _OpCache_with_parameter_ObstacleDistanceBecomesBig = _OpCache_with_parameter_ObstacleDistanceBecomesBig.set(readState, writeState);
                        this._OpCache_ObstacleDistanceBecomesBig = this._OpCache_ObstacleDistanceBecomesBig.set(_trid_17, _OpCache_with_parameter_ObstacleDistanceBecomesBig);
                    }

                } else {
                    copiedState.ObstacleDistanceBecomesBig();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_ObstacleDistanceBecomesBig = copiedState._update_for_ObstacleDistanceBecomesBig();
                    _OpCache_with_parameter_ObstacleDistanceBecomesBig = new immutable.Map().set(readState, writeState);
                    this._OpCache_ObstacleDistanceBecomesBig = this._OpCache_ObstacleDistanceBecomesBig.set(_trid_17, _OpCache_with_parameter_ObstacleDistanceBecomesBig);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_ObstacleStartsTravelFaster_state : _ProjectionRead__tr_ObstacleStartsTravelFaster = state._projected_state_for__tr_ObstacleStartsTravelFaster();
            let _obj__trid_18: any = this._OpCache_tr_ObstacleStartsTravelFaster.get(read__tr_ObstacleStartsTravelFaster_state);
            let _trid_18: boolean;
            if(_obj__trid_18 == null) {
                _trid_18 = state._tr_ObstacleStartsTravelFaster();
                this._OpCache_tr_ObstacleStartsTravelFaster = this._OpCache_tr_ObstacleStartsTravelFaster.set(read__tr_ObstacleStartsTravelFaster_state, _trid_18);
            } else {
                _trid_18 = _obj__trid_18;
            }

            if(_trid_18) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_ObstacleStartsTravelFaster = state._projected_state_for_ObstacleStartsTravelFaster();
                let _OpCache_with_parameter_ObstacleStartsTravelFaster: immutable.Map = this._OpCache_ObstacleStartsTravelFaster.get(_trid_18);
                if(_OpCache_with_parameter_ObstacleStartsTravelFaster != null) {
                    let writeState: _ProjectionWrite_ObstacleStartsTravelFaster = _OpCache_with_parameter_ObstacleStartsTravelFaster.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_ObstacleStartsTravelFaster(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.ObstacleStartsTravelFaster();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_ObstacleStartsTravelFaster();
                        _OpCache_with_parameter_ObstacleStartsTravelFaster = _OpCache_with_parameter_ObstacleStartsTravelFaster.set(readState, writeState);
                        this._OpCache_ObstacleStartsTravelFaster = this._OpCache_ObstacleStartsTravelFaster.set(_trid_18, _OpCache_with_parameter_ObstacleStartsTravelFaster);
                    }

                } else {
                    copiedState.ObstacleStartsTravelFaster();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_ObstacleStartsTravelFaster = copiedState._update_for_ObstacleStartsTravelFaster();
                    _OpCache_with_parameter_ObstacleStartsTravelFaster = new immutable.Map().set(readState, writeState);
                    this._OpCache_ObstacleStartsTravelFaster = this._OpCache_ObstacleStartsTravelFaster.set(_trid_18, _OpCache_with_parameter_ObstacleStartsTravelFaster);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_ObstacleStopsTravelFaster_state : _ProjectionRead__tr_ObstacleStopsTravelFaster = state._projected_state_for__tr_ObstacleStopsTravelFaster();
            let _obj__trid_19: any = this._OpCache_tr_ObstacleStopsTravelFaster.get(read__tr_ObstacleStopsTravelFaster_state);
            let _trid_19: boolean;
            if(_obj__trid_19 == null) {
                _trid_19 = state._tr_ObstacleStopsTravelFaster();
                this._OpCache_tr_ObstacleStopsTravelFaster = this._OpCache_tr_ObstacleStopsTravelFaster.set(read__tr_ObstacleStopsTravelFaster_state, _trid_19);
            } else {
                _trid_19 = _obj__trid_19;
            }

            if(_trid_19) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_ObstacleStopsTravelFaster = state._projected_state_for_ObstacleStopsTravelFaster();
                let _OpCache_with_parameter_ObstacleStopsTravelFaster: immutable.Map = this._OpCache_ObstacleStopsTravelFaster.get(_trid_19);
                if(_OpCache_with_parameter_ObstacleStopsTravelFaster != null) {
                    let writeState: _ProjectionWrite_ObstacleStopsTravelFaster = _OpCache_with_parameter_ObstacleStopsTravelFaster.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_ObstacleStopsTravelFaster(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.ObstacleStopsTravelFaster();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_ObstacleStopsTravelFaster();
                        _OpCache_with_parameter_ObstacleStopsTravelFaster = _OpCache_with_parameter_ObstacleStopsTravelFaster.set(readState, writeState);
                        this._OpCache_ObstacleStopsTravelFaster = this._OpCache_ObstacleStopsTravelFaster.set(_trid_19, _OpCache_with_parameter_ObstacleStopsTravelFaster);
                    }

                } else {
                    copiedState.ObstacleStopsTravelFaster();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_ObstacleStopsTravelFaster = copiedState._update_for_ObstacleStopsTravelFaster();
                    _OpCache_with_parameter_ObstacleStopsTravelFaster = new immutable.Map().set(readState, writeState);
                    this._OpCache_ObstacleStopsTravelFaster = this._OpCache_ObstacleStopsTravelFaster.set(_trid_19, _OpCache_with_parameter_ObstacleStopsTravelFaster);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_ObstacleStartsTravelSlower_state : _ProjectionRead__tr_ObstacleStartsTravelSlower = state._projected_state_for__tr_ObstacleStartsTravelSlower();
            let _obj__trid_20: any = this._OpCache_tr_ObstacleStartsTravelSlower.get(read__tr_ObstacleStartsTravelSlower_state);
            let _trid_20: boolean;
            if(_obj__trid_20 == null) {
                _trid_20 = state._tr_ObstacleStartsTravelSlower();
                this._OpCache_tr_ObstacleStartsTravelSlower = this._OpCache_tr_ObstacleStartsTravelSlower.set(read__tr_ObstacleStartsTravelSlower_state, _trid_20);
            } else {
                _trid_20 = _obj__trid_20;
            }

            if(_trid_20) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_ObstacleStartsTravelSlower = state._projected_state_for_ObstacleStartsTravelSlower();
                let _OpCache_with_parameter_ObstacleStartsTravelSlower: immutable.Map = this._OpCache_ObstacleStartsTravelSlower.get(_trid_20);
                if(_OpCache_with_parameter_ObstacleStartsTravelSlower != null) {
                    let writeState: _ProjectionWrite_ObstacleStartsTravelSlower = _OpCache_with_parameter_ObstacleStartsTravelSlower.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_ObstacleStartsTravelSlower(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.ObstacleStartsTravelSlower();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_ObstacleStartsTravelSlower();
                        _OpCache_with_parameter_ObstacleStartsTravelSlower = _OpCache_with_parameter_ObstacleStartsTravelSlower.set(readState, writeState);
                        this._OpCache_ObstacleStartsTravelSlower = this._OpCache_ObstacleStartsTravelSlower.set(_trid_20, _OpCache_with_parameter_ObstacleStartsTravelSlower);
                    }

                } else {
                    copiedState.ObstacleStartsTravelSlower();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_ObstacleStartsTravelSlower = copiedState._update_for_ObstacleStartsTravelSlower();
                    _OpCache_with_parameter_ObstacleStartsTravelSlower = new immutable.Map().set(readState, writeState);
                    this._OpCache_ObstacleStartsTravelSlower = this._OpCache_ObstacleStartsTravelSlower.set(_trid_20, _OpCache_with_parameter_ObstacleStartsTravelSlower);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_ObstacleStopsTravelSlower_state : _ProjectionRead__tr_ObstacleStopsTravelSlower = state._projected_state_for__tr_ObstacleStopsTravelSlower();
            let _obj__trid_21: any = this._OpCache_tr_ObstacleStopsTravelSlower.get(read__tr_ObstacleStopsTravelSlower_state);
            let _trid_21: boolean;
            if(_obj__trid_21 == null) {
                _trid_21 = state._tr_ObstacleStopsTravelSlower();
                this._OpCache_tr_ObstacleStopsTravelSlower = this._OpCache_tr_ObstacleStopsTravelSlower.set(read__tr_ObstacleStopsTravelSlower_state, _trid_21);
            } else {
                _trid_21 = _obj__trid_21;
            }

            if(_trid_21) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_ObstacleStopsTravelSlower = state._projected_state_for_ObstacleStopsTravelSlower();
                let _OpCache_with_parameter_ObstacleStopsTravelSlower: immutable.Map = this._OpCache_ObstacleStopsTravelSlower.get(_trid_21);
                if(_OpCache_with_parameter_ObstacleStopsTravelSlower != null) {
                    let writeState: _ProjectionWrite_ObstacleStopsTravelSlower = _OpCache_with_parameter_ObstacleStopsTravelSlower.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_ObstacleStopsTravelSlower(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.ObstacleStopsTravelSlower();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_ObstacleStopsTravelSlower();
                        _OpCache_with_parameter_ObstacleStopsTravelSlower = _OpCache_with_parameter_ObstacleStopsTravelSlower.set(readState, writeState);
                        this._OpCache_ObstacleStopsTravelSlower = this._OpCache_ObstacleStopsTravelSlower.set(_trid_21, _OpCache_with_parameter_ObstacleStopsTravelSlower);
                    }

                } else {
                    copiedState.ObstacleStopsTravelSlower();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_ObstacleStopsTravelSlower = copiedState._update_for_ObstacleStopsTravelSlower();
                    _OpCache_with_parameter_ObstacleStopsTravelSlower = new immutable.Map().set(readState, writeState);
                    this._OpCache_ObstacleStopsTravelSlower = this._OpCache_ObstacleStopsTravelSlower.set(_trid_21, _OpCache_with_parameter_ObstacleStopsTravelSlower);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_ObstacleAppearsWhenCruiseActive_state : _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive = state._projected_state_for__tr_ObstacleAppearsWhenCruiseActive();
            let _trid_22 : BSet<BTuple<RSset, ODset>>  = this._OpCache_tr_ObstacleAppearsWhenCruiseActive.get(read__tr_ObstacleAppearsWhenCruiseActive_state);
            if(_trid_22 == null) {
                _trid_22 = state._tr_ObstacleAppearsWhenCruiseActive();
                this._OpCache_tr_ObstacleAppearsWhenCruiseActive = this._OpCache_tr_ObstacleAppearsWhenCruiseActive.set(read__tr_ObstacleAppearsWhenCruiseActive_state, _trid_22);
            }

            for(let param of _trid_22) {
                let _tmp_1: ODset = param.projection2();
                let _tmp_2: RSset = param.projection1();

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_ObstacleAppearsWhenCruiseActive = state._projected_state_for_ObstacleAppearsWhenCruiseActive();
                let _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive: immutable.Map = this._OpCache_ObstacleAppearsWhenCruiseActive.get(param);
                if(_OpCache_with_parameter_ObstacleAppearsWhenCruiseActive != null) {
                    let writeState: _ProjectionWrite_ObstacleAppearsWhenCruiseActive = _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_ObstacleAppearsWhenCruiseActive(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.ObstacleAppearsWhenCruiseActive(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_ObstacleAppearsWhenCruiseActive();
                        _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive = _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive.set(readState, writeState);
                        this._OpCache_ObstacleAppearsWhenCruiseActive = this._OpCache_ObstacleAppearsWhenCruiseActive.set(param, _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive);
                    }

                } else {
                    copiedState.ObstacleAppearsWhenCruiseActive(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_ObstacleAppearsWhenCruiseActive = copiedState._update_for_ObstacleAppearsWhenCruiseActive();
                    _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive = new immutable.Map().set(readState, writeState);
                    this._OpCache_ObstacleAppearsWhenCruiseActive = this._OpCache_ObstacleAppearsWhenCruiseActive.set(param, _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_ObstacleAppearsWhenCruiseInactive_state : _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive = state._projected_state_for__tr_ObstacleAppearsWhenCruiseInactive();
            let _trid_23 : BSet<RSset>  = this._OpCache_tr_ObstacleAppearsWhenCruiseInactive.get(read__tr_ObstacleAppearsWhenCruiseInactive_state);
            if(_trid_23 == null) {
                _trid_23 = state._tr_ObstacleAppearsWhenCruiseInactive();
                this._OpCache_tr_ObstacleAppearsWhenCruiseInactive = this._OpCache_tr_ObstacleAppearsWhenCruiseInactive.set(read__tr_ObstacleAppearsWhenCruiseInactive_state, _trid_23);
            }

            for(let param of _trid_23) {
                let _tmp_1: RSset = param;

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_ObstacleAppearsWhenCruiseInactive = state._projected_state_for_ObstacleAppearsWhenCruiseInactive();
                let _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive: immutable.Map = this._OpCache_ObstacleAppearsWhenCruiseInactive.get(param);
                if(_OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive != null) {
                    let writeState: _ProjectionWrite_ObstacleAppearsWhenCruiseInactive = _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_ObstacleAppearsWhenCruiseInactive(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.ObstacleAppearsWhenCruiseInactive(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_ObstacleAppearsWhenCruiseInactive();
                        _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive = _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive.set(readState, writeState);
                        this._OpCache_ObstacleAppearsWhenCruiseInactive = this._OpCache_ObstacleAppearsWhenCruiseInactive.set(param, _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive);
                    }

                } else {
                    copiedState.ObstacleAppearsWhenCruiseInactive(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_ObstacleAppearsWhenCruiseInactive = copiedState._update_for_ObstacleAppearsWhenCruiseInactive();
                    _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive = new immutable.Map().set(readState, writeState);
                    this._OpCache_ObstacleAppearsWhenCruiseInactive = this._OpCache_ObstacleAppearsWhenCruiseInactive.set(param, _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_ObstacleDisappears_state : _ProjectionRead__tr_ObstacleDisappears = state._projected_state_for__tr_ObstacleDisappears();
            let _obj__trid_24: any = this._OpCache_tr_ObstacleDisappears.get(read__tr_ObstacleDisappears_state);
            let _trid_24: boolean;
            if(_obj__trid_24 == null) {
                _trid_24 = state._tr_ObstacleDisappears();
                this._OpCache_tr_ObstacleDisappears = this._OpCache_tr_ObstacleDisappears.set(read__tr_ObstacleDisappears_state, _trid_24);
            } else {
                _trid_24 = _obj__trid_24;
            }

            if(_trid_24) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_ObstacleDisappears = state._projected_state_for_ObstacleDisappears();
                let _OpCache_with_parameter_ObstacleDisappears: immutable.Map = this._OpCache_ObstacleDisappears.get(_trid_24);
                if(_OpCache_with_parameter_ObstacleDisappears != null) {
                    let writeState: _ProjectionWrite_ObstacleDisappears = _OpCache_with_parameter_ObstacleDisappears.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_ObstacleDisappears(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.ObstacleDisappears();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_ObstacleDisappears();
                        _OpCache_with_parameter_ObstacleDisappears = _OpCache_with_parameter_ObstacleDisappears.set(readState, writeState);
                        this._OpCache_ObstacleDisappears = this._OpCache_ObstacleDisappears.set(_trid_24, _OpCache_with_parameter_ObstacleDisappears);
                    }

                } else {
                    copiedState.ObstacleDisappears();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_ObstacleDisappears = copiedState._update_for_ObstacleDisappears();
                    _OpCache_with_parameter_ObstacleDisappears = new immutable.Map().set(readState, writeState);
                    this._OpCache_ObstacleDisappears = this._OpCache_ObstacleDisappears.set(_trid_24, _OpCache_with_parameter_ObstacleDisappears);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_VehicleManageObstacle_state : _ProjectionRead__tr_VehicleManageObstacle = state._projected_state_for__tr_VehicleManageObstacle();
            let _trid_25 : BSet<BTuple<BBoolean, BBoolean>>  = this._OpCache_tr_VehicleManageObstacle.get(read__tr_VehicleManageObstacle_state);
            if(_trid_25 == null) {
                _trid_25 = state._tr_VehicleManageObstacle();
                this._OpCache_tr_VehicleManageObstacle = this._OpCache_tr_VehicleManageObstacle.set(read__tr_VehicleManageObstacle_state, _trid_25);
            }

            for(let param of _trid_25) {
                let _tmp_1: BBoolean = param.projection2();
                let _tmp_2: BBoolean = param.projection1();

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_VehicleManageObstacle = state._projected_state_for_VehicleManageObstacle();
                let _OpCache_with_parameter_VehicleManageObstacle: immutable.Map = this._OpCache_VehicleManageObstacle.get(param);
                if(_OpCache_with_parameter_VehicleManageObstacle != null) {
                    let writeState: _ProjectionWrite_VehicleManageObstacle = _OpCache_with_parameter_VehicleManageObstacle.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_VehicleManageObstacle(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.VehicleManageObstacle(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_VehicleManageObstacle();
                        _OpCache_with_parameter_VehicleManageObstacle = _OpCache_with_parameter_VehicleManageObstacle.set(readState, writeState);
                        this._OpCache_VehicleManageObstacle = this._OpCache_VehicleManageObstacle.set(param, _OpCache_with_parameter_VehicleManageObstacle);
                    }

                } else {
                    copiedState.VehicleManageObstacle(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_VehicleManageObstacle = copiedState._update_for_VehicleManageObstacle();
                    _OpCache_with_parameter_VehicleManageObstacle = new immutable.Map().set(readState, writeState);
                    this._OpCache_VehicleManageObstacle = this._OpCache_VehicleManageObstacle.set(param, _OpCache_with_parameter_VehicleManageObstacle);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_ObstacleBecomesOld_state : _ProjectionRead__tr_ObstacleBecomesOld = state._projected_state_for__tr_ObstacleBecomesOld();
            let _obj__trid_26: any = this._OpCache_tr_ObstacleBecomesOld.get(read__tr_ObstacleBecomesOld_state);
            let _trid_26: boolean;
            if(_obj__trid_26 == null) {
                _trid_26 = state._tr_ObstacleBecomesOld();
                this._OpCache_tr_ObstacleBecomesOld = this._OpCache_tr_ObstacleBecomesOld.set(read__tr_ObstacleBecomesOld_state, _trid_26);
            } else {
                _trid_26 = _obj__trid_26;
            }

            if(_trid_26) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                let readState: _ProjectionRead_ObstacleBecomesOld = state._projected_state_for_ObstacleBecomesOld();
                let _OpCache_with_parameter_ObstacleBecomesOld: immutable.Map = this._OpCache_ObstacleBecomesOld.get(_trid_26);
                if(_OpCache_with_parameter_ObstacleBecomesOld != null) {
                    let writeState: _ProjectionWrite_ObstacleBecomesOld = _OpCache_with_parameter_ObstacleBecomesOld.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_ObstacleBecomesOld(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.ObstacleBecomesOld();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_ObstacleBecomesOld();
                        _OpCache_with_parameter_ObstacleBecomesOld = _OpCache_with_parameter_ObstacleBecomesOld.set(readState, writeState);
                        this._OpCache_ObstacleBecomesOld = this._OpCache_ObstacleBecomesOld.set(_trid_26, _OpCache_with_parameter_ObstacleBecomesOld);
                    }

                } else {
                    copiedState.ObstacleBecomesOld();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_ObstacleBecomesOld = copiedState._update_for_ObstacleBecomesOld();
                    _OpCache_with_parameter_ObstacleBecomesOld = new immutable.Map().set(readState, writeState);
                    this._OpCache_ObstacleBecomesOld = this._OpCache_ObstacleBecomesOld.set(_trid_26, _OpCache_with_parameter_ObstacleBecomesOld);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        } else {
            if(state._tr_CruiseBecomesNotAllowed()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.CruiseBecomesNotAllowed();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_CruiseBecomesAllowed()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.CruiseBecomesAllowed();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_3: BSet<BTuple<BBoolean, BBoolean>> = state._tr_SetCruiseSpeed();
            for(let param of _trid_3) {
                let _tmp_1: BBoolean = param.projection2();
                let _tmp_2: BBoolean = param.projection1();

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.SetCruiseSpeed(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_4: BSet<BTuple<BBoolean, BBoolean>> = state._tr_CCInitialisationFinished();
            for(let param of _trid_4) {
                let _tmp_1: BBoolean = param.projection2();
                let _tmp_2: BBoolean = param.projection1();

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.CCInitialisationFinished(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_CCInitialisationDelayFinished()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.CCInitialisationDelayFinished();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_6: BSet<BTuple<BBoolean, BBoolean>> = state._tr_CruiseSpeedChangeFinished();
            for(let param of _trid_6) {
                let _tmp_1: BBoolean = param.projection2();
                let _tmp_2: BBoolean = param.projection1();

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.CruiseSpeedChangeFinished(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_CruiseSpeedChangeDelayFinished()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.CruiseSpeedChangeDelayFinished();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_CruiseOff()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.CruiseOff();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ExternalForcesBecomesExtreme()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ExternalForcesBecomesExtreme();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ExternalForcesBecomesNormal()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ExternalForcesBecomesNormal();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_VehicleLeavesCruiseSpeed()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.VehicleLeavesCruiseSpeed();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_VehicleReachesCruiseSpeed()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.VehicleReachesCruiseSpeed();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_VehicleExceedsMaxCruiseSpeed()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.VehicleExceedsMaxCruiseSpeed();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_VehicleFallsBelowMaxCruiseSpeed()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.VehicleFallsBelowMaxCruiseSpeed();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ObstacleDistanceBecomesVeryClose()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleDistanceBecomesVeryClose();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ObstacleDistanceBecomesClose()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleDistanceBecomesClose();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ObstacleDistanceBecomesBig()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleDistanceBecomesBig();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ObstacleStartsTravelFaster()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleStartsTravelFaster();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ObstacleStopsTravelFaster()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleStopsTravelFaster();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ObstacleStartsTravelSlower()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleStartsTravelSlower();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ObstacleStopsTravelSlower()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleStopsTravelSlower();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_22: BSet<BTuple<RSset, ODset>> = state._tr_ObstacleAppearsWhenCruiseActive();
            for(let param of _trid_22) {
                let _tmp_1: ODset = param.projection2();
                let _tmp_2: RSset = param.projection1();

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleAppearsWhenCruiseActive(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_23: BSet<RSset> = state._tr_ObstacleAppearsWhenCruiseInactive();
            for(let param of _trid_23) {
                let _tmp_1: RSset = param;

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleAppearsWhenCruiseInactive(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ObstacleDisappears()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleDisappears();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_25: BSet<BTuple<BBoolean, BBoolean>> = state._tr_VehicleManageObstacle();
            for(let param of _trid_25) {
                let _tmp_1: BBoolean = param.projection2();
                let _tmp_2: BBoolean = param.projection1();

                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.VehicleManageObstacle(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_ObstacleBecomesOld()) {
                let copiedState: Cruise_finite1_deterministic_MC = state._copy();
                copiedState.ObstacleBecomesOld();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        }
        return result;
    }

    invViolated(state: Cruise_finite1_deterministic_MC): boolean {
        let _check_inv_1: boolean;
        if(isCaching) {
            let read__check_inv_1_state: _ProjectionRead__check_inv_1 = state._projected_state_for__check_inv_1();
            let _obj__check_inv_1: boolean = this._InvCache__check_inv_1.get(read__check_inv_1_state);
            if(_obj__check_inv_1 == null) {
                _check_inv_1 = state._check_inv_1();
                this._InvCache__check_inv_1 = this._InvCache__check_inv_1.set(read__check_inv_1_state, _check_inv_1);
            } else {
                _check_inv_1 = _obj__check_inv_1;
            }
        } else {
            _check_inv_1 = state._check_inv_1();
        }
        if(!_check_inv_1) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_1");
            return true;
        }
        let _check_inv_2: boolean;
        if(isCaching) {
            let read__check_inv_2_state: _ProjectionRead__check_inv_2 = state._projected_state_for__check_inv_2();
            let _obj__check_inv_2: boolean = this._InvCache__check_inv_2.get(read__check_inv_2_state);
            if(_obj__check_inv_2 == null) {
                _check_inv_2 = state._check_inv_2();
                this._InvCache__check_inv_2 = this._InvCache__check_inv_2.set(read__check_inv_2_state, _check_inv_2);
            } else {
                _check_inv_2 = _obj__check_inv_2;
            }
        } else {
            _check_inv_2 = state._check_inv_2();
        }
        if(!_check_inv_2) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_2");
            return true;
        }
        let _check_inv_3: boolean;
        if(isCaching) {
            let read__check_inv_3_state: _ProjectionRead__check_inv_3 = state._projected_state_for__check_inv_3();
            let _obj__check_inv_3: boolean = this._InvCache__check_inv_3.get(read__check_inv_3_state);
            if(_obj__check_inv_3 == null) {
                _check_inv_3 = state._check_inv_3();
                this._InvCache__check_inv_3 = this._InvCache__check_inv_3.set(read__check_inv_3_state, _check_inv_3);
            } else {
                _check_inv_3 = _obj__check_inv_3;
            }
        } else {
            _check_inv_3 = state._check_inv_3();
        }
        if(!_check_inv_3) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_3");
            return true;
        }
        let _check_inv_4: boolean;
        if(isCaching) {
            let read__check_inv_4_state: _ProjectionRead__check_inv_4 = state._projected_state_for__check_inv_4();
            let _obj__check_inv_4: boolean = this._InvCache__check_inv_4.get(read__check_inv_4_state);
            if(_obj__check_inv_4 == null) {
                _check_inv_4 = state._check_inv_4();
                this._InvCache__check_inv_4 = this._InvCache__check_inv_4.set(read__check_inv_4_state, _check_inv_4);
            } else {
                _check_inv_4 = _obj__check_inv_4;
            }
        } else {
            _check_inv_4 = state._check_inv_4();
        }
        if(!_check_inv_4) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_4");
            return true;
        }
        let _check_inv_5: boolean;
        if(isCaching) {
            let read__check_inv_5_state: _ProjectionRead__check_inv_5 = state._projected_state_for__check_inv_5();
            let _obj__check_inv_5: boolean = this._InvCache__check_inv_5.get(read__check_inv_5_state);
            if(_obj__check_inv_5 == null) {
                _check_inv_5 = state._check_inv_5();
                this._InvCache__check_inv_5 = this._InvCache__check_inv_5.set(read__check_inv_5_state, _check_inv_5);
            } else {
                _check_inv_5 = _obj__check_inv_5;
            }
        } else {
            _check_inv_5 = state._check_inv_5();
        }
        if(!_check_inv_5) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_5");
            return true;
        }
        let _check_inv_6: boolean;
        if(isCaching) {
            let read__check_inv_6_state: _ProjectionRead__check_inv_6 = state._projected_state_for__check_inv_6();
            let _obj__check_inv_6: boolean = this._InvCache__check_inv_6.get(read__check_inv_6_state);
            if(_obj__check_inv_6 == null) {
                _check_inv_6 = state._check_inv_6();
                this._InvCache__check_inv_6 = this._InvCache__check_inv_6.set(read__check_inv_6_state, _check_inv_6);
            } else {
                _check_inv_6 = _obj__check_inv_6;
            }
        } else {
            _check_inv_6 = state._check_inv_6();
        }
        if(!_check_inv_6) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_6");
            return true;
        }
        let _check_inv_7: boolean;
        if(isCaching) {
            let read__check_inv_7_state: _ProjectionRead__check_inv_7 = state._projected_state_for__check_inv_7();
            let _obj__check_inv_7: boolean = this._InvCache__check_inv_7.get(read__check_inv_7_state);
            if(_obj__check_inv_7 == null) {
                _check_inv_7 = state._check_inv_7();
                this._InvCache__check_inv_7 = this._InvCache__check_inv_7.set(read__check_inv_7_state, _check_inv_7);
            } else {
                _check_inv_7 = _obj__check_inv_7;
            }
        } else {
            _check_inv_7 = state._check_inv_7();
        }
        if(!_check_inv_7) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_7");
            return true;
        }
        let _check_inv_8: boolean;
        if(isCaching) {
            let read__check_inv_8_state: _ProjectionRead__check_inv_8 = state._projected_state_for__check_inv_8();
            let _obj__check_inv_8: boolean = this._InvCache__check_inv_8.get(read__check_inv_8_state);
            if(_obj__check_inv_8 == null) {
                _check_inv_8 = state._check_inv_8();
                this._InvCache__check_inv_8 = this._InvCache__check_inv_8.set(read__check_inv_8_state, _check_inv_8);
            } else {
                _check_inv_8 = _obj__check_inv_8;
            }
        } else {
            _check_inv_8 = state._check_inv_8();
        }
        if(!_check_inv_8) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_8");
            return true;
        }
        let _check_inv_9: boolean;
        if(isCaching) {
            let read__check_inv_9_state: _ProjectionRead__check_inv_9 = state._projected_state_for__check_inv_9();
            let _obj__check_inv_9: boolean = this._InvCache__check_inv_9.get(read__check_inv_9_state);
            if(_obj__check_inv_9 == null) {
                _check_inv_9 = state._check_inv_9();
                this._InvCache__check_inv_9 = this._InvCache__check_inv_9.set(read__check_inv_9_state, _check_inv_9);
            } else {
                _check_inv_9 = _obj__check_inv_9;
            }
        } else {
            _check_inv_9 = state._check_inv_9();
        }
        if(!_check_inv_9) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_9");
            return true;
        }
        let _check_inv_10: boolean;
        if(isCaching) {
            let read__check_inv_10_state: _ProjectionRead__check_inv_10 = state._projected_state_for__check_inv_10();
            let _obj__check_inv_10: boolean = this._InvCache__check_inv_10.get(read__check_inv_10_state);
            if(_obj__check_inv_10 == null) {
                _check_inv_10 = state._check_inv_10();
                this._InvCache__check_inv_10 = this._InvCache__check_inv_10.set(read__check_inv_10_state, _check_inv_10);
            } else {
                _check_inv_10 = _obj__check_inv_10;
            }
        } else {
            _check_inv_10 = state._check_inv_10();
        }
        if(!_check_inv_10) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_10");
            return true;
        }
        let _check_inv_11: boolean;
        if(isCaching) {
            let read__check_inv_11_state: _ProjectionRead__check_inv_11 = state._projected_state_for__check_inv_11();
            let _obj__check_inv_11: boolean = this._InvCache__check_inv_11.get(read__check_inv_11_state);
            if(_obj__check_inv_11 == null) {
                _check_inv_11 = state._check_inv_11();
                this._InvCache__check_inv_11 = this._InvCache__check_inv_11.set(read__check_inv_11_state, _check_inv_11);
            } else {
                _check_inv_11 = _obj__check_inv_11;
            }
        } else {
            _check_inv_11 = state._check_inv_11();
        }
        if(!_check_inv_11) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_11");
            return true;
        }
        let _check_inv_12: boolean;
        if(isCaching) {
            let read__check_inv_12_state: _ProjectionRead__check_inv_12 = state._projected_state_for__check_inv_12();
            let _obj__check_inv_12: boolean = this._InvCache__check_inv_12.get(read__check_inv_12_state);
            if(_obj__check_inv_12 == null) {
                _check_inv_12 = state._check_inv_12();
                this._InvCache__check_inv_12 = this._InvCache__check_inv_12.set(read__check_inv_12_state, _check_inv_12);
            } else {
                _check_inv_12 = _obj__check_inv_12;
            }
        } else {
            _check_inv_12 = state._check_inv_12();
        }
        if(!_check_inv_12) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_12");
            return true;
        }
        let _check_inv_13: boolean;
        if(isCaching) {
            let read__check_inv_13_state: _ProjectionRead__check_inv_13 = state._projected_state_for__check_inv_13();
            let _obj__check_inv_13: boolean = this._InvCache__check_inv_13.get(read__check_inv_13_state);
            if(_obj__check_inv_13 == null) {
                _check_inv_13 = state._check_inv_13();
                this._InvCache__check_inv_13 = this._InvCache__check_inv_13.set(read__check_inv_13_state, _check_inv_13);
            } else {
                _check_inv_13 = _obj__check_inv_13;
            }
        } else {
            _check_inv_13 = state._check_inv_13();
        }
        if(!_check_inv_13) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_13");
            return true;
        }
        let _check_inv_14: boolean;
        if(isCaching) {
            let read__check_inv_14_state: _ProjectionRead__check_inv_14 = state._projected_state_for__check_inv_14();
            let _obj__check_inv_14: boolean = this._InvCache__check_inv_14.get(read__check_inv_14_state);
            if(_obj__check_inv_14 == null) {
                _check_inv_14 = state._check_inv_14();
                this._InvCache__check_inv_14 = this._InvCache__check_inv_14.set(read__check_inv_14_state, _check_inv_14);
            } else {
                _check_inv_14 = _obj__check_inv_14;
            }
        } else {
            _check_inv_14 = state._check_inv_14();
        }
        if(!_check_inv_14) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_14");
            return true;
        }
        let _check_inv_15: boolean;
        if(isCaching) {
            let read__check_inv_15_state: _ProjectionRead__check_inv_15 = state._projected_state_for__check_inv_15();
            let _obj__check_inv_15: boolean = this._InvCache__check_inv_15.get(read__check_inv_15_state);
            if(_obj__check_inv_15 == null) {
                _check_inv_15 = state._check_inv_15();
                this._InvCache__check_inv_15 = this._InvCache__check_inv_15.set(read__check_inv_15_state, _check_inv_15);
            } else {
                _check_inv_15 = _obj__check_inv_15;
            }
        } else {
            _check_inv_15 = state._check_inv_15();
        }
        if(!_check_inv_15) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_15");
            return true;
        }
        let _check_inv_16: boolean;
        if(isCaching) {
            let read__check_inv_16_state: _ProjectionRead__check_inv_16 = state._projected_state_for__check_inv_16();
            let _obj__check_inv_16: boolean = this._InvCache__check_inv_16.get(read__check_inv_16_state);
            if(_obj__check_inv_16 == null) {
                _check_inv_16 = state._check_inv_16();
                this._InvCache__check_inv_16 = this._InvCache__check_inv_16.set(read__check_inv_16_state, _check_inv_16);
            } else {
                _check_inv_16 = _obj__check_inv_16;
            }
        } else {
            _check_inv_16 = state._check_inv_16();
        }
        if(!_check_inv_16) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_16");
            return true;
        }
        let _check_inv_17: boolean;
        if(isCaching) {
            let read__check_inv_17_state: _ProjectionRead__check_inv_17 = state._projected_state_for__check_inv_17();
            let _obj__check_inv_17: boolean = this._InvCache__check_inv_17.get(read__check_inv_17_state);
            if(_obj__check_inv_17 == null) {
                _check_inv_17 = state._check_inv_17();
                this._InvCache__check_inv_17 = this._InvCache__check_inv_17.set(read__check_inv_17_state, _check_inv_17);
            } else {
                _check_inv_17 = _obj__check_inv_17;
            }
        } else {
            _check_inv_17 = state._check_inv_17();
        }
        if(!_check_inv_17) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_17");
            return true;
        }
        let _check_inv_18: boolean;
        if(isCaching) {
            let read__check_inv_18_state: _ProjectionRead__check_inv_18 = state._projected_state_for__check_inv_18();
            let _obj__check_inv_18: boolean = this._InvCache__check_inv_18.get(read__check_inv_18_state);
            if(_obj__check_inv_18 == null) {
                _check_inv_18 = state._check_inv_18();
                this._InvCache__check_inv_18 = this._InvCache__check_inv_18.set(read__check_inv_18_state, _check_inv_18);
            } else {
                _check_inv_18 = _obj__check_inv_18;
            }
        } else {
            _check_inv_18 = state._check_inv_18();
        }
        if(!_check_inv_18) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_18");
            return true;
        }
        let _check_inv_19: boolean;
        if(isCaching) {
            let read__check_inv_19_state: _ProjectionRead__check_inv_19 = state._projected_state_for__check_inv_19();
            let _obj__check_inv_19: boolean = this._InvCache__check_inv_19.get(read__check_inv_19_state);
            if(_obj__check_inv_19 == null) {
                _check_inv_19 = state._check_inv_19();
                this._InvCache__check_inv_19 = this._InvCache__check_inv_19.set(read__check_inv_19_state, _check_inv_19);
            } else {
                _check_inv_19 = _obj__check_inv_19;
            }
        } else {
            _check_inv_19 = state._check_inv_19();
        }
        if(!_check_inv_19) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_19");
            return true;
        }
        let _check_inv_20: boolean;
        if(isCaching) {
            let read__check_inv_20_state: _ProjectionRead__check_inv_20 = state._projected_state_for__check_inv_20();
            let _obj__check_inv_20: boolean = this._InvCache__check_inv_20.get(read__check_inv_20_state);
            if(_obj__check_inv_20 == null) {
                _check_inv_20 = state._check_inv_20();
                this._InvCache__check_inv_20 = this._InvCache__check_inv_20.set(read__check_inv_20_state, _check_inv_20);
            } else {
                _check_inv_20 = _obj__check_inv_20;
            }
        } else {
            _check_inv_20 = state._check_inv_20();
        }
        if(!_check_inv_20) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_20");
            return true;
        }
        let _check_inv_21: boolean;
        if(isCaching) {
            let read__check_inv_21_state: _ProjectionRead__check_inv_21 = state._projected_state_for__check_inv_21();
            let _obj__check_inv_21: boolean = this._InvCache__check_inv_21.get(read__check_inv_21_state);
            if(_obj__check_inv_21 == null) {
                _check_inv_21 = state._check_inv_21();
                this._InvCache__check_inv_21 = this._InvCache__check_inv_21.set(read__check_inv_21_state, _check_inv_21);
            } else {
                _check_inv_21 = _obj__check_inv_21;
            }
        } else {
            _check_inv_21 = state._check_inv_21();
        }
        if(!_check_inv_21) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_21");
            return true;
        }
        let _check_inv_22: boolean;
        if(isCaching) {
            let read__check_inv_22_state: _ProjectionRead__check_inv_22 = state._projected_state_for__check_inv_22();
            let _obj__check_inv_22: boolean = this._InvCache__check_inv_22.get(read__check_inv_22_state);
            if(_obj__check_inv_22 == null) {
                _check_inv_22 = state._check_inv_22();
                this._InvCache__check_inv_22 = this._InvCache__check_inv_22.set(read__check_inv_22_state, _check_inv_22);
            } else {
                _check_inv_22 = _obj__check_inv_22;
            }
        } else {
            _check_inv_22 = state._check_inv_22();
        }
        if(!_check_inv_22) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_22");
            return true;
        }
        let _check_inv_23: boolean;
        if(isCaching) {
            let read__check_inv_23_state: _ProjectionRead__check_inv_23 = state._projected_state_for__check_inv_23();
            let _obj__check_inv_23: boolean = this._InvCache__check_inv_23.get(read__check_inv_23_state);
            if(_obj__check_inv_23 == null) {
                _check_inv_23 = state._check_inv_23();
                this._InvCache__check_inv_23 = this._InvCache__check_inv_23.set(read__check_inv_23_state, _check_inv_23);
            } else {
                _check_inv_23 = _obj__check_inv_23;
            }
        } else {
            _check_inv_23 = state._check_inv_23();
        }
        if(!_check_inv_23) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_23");
            return true;
        }
        let _check_inv_24: boolean;
        if(isCaching) {
            let read__check_inv_24_state: _ProjectionRead__check_inv_24 = state._projected_state_for__check_inv_24();
            let _obj__check_inv_24: boolean = this._InvCache__check_inv_24.get(read__check_inv_24_state);
            if(_obj__check_inv_24 == null) {
                _check_inv_24 = state._check_inv_24();
                this._InvCache__check_inv_24 = this._InvCache__check_inv_24.set(read__check_inv_24_state, _check_inv_24);
            } else {
                _check_inv_24 = _obj__check_inv_24;
            }
        } else {
            _check_inv_24 = state._check_inv_24();
        }
        if(!_check_inv_24) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_24");
            return true;
        }
        let _check_inv_25: boolean;
        if(isCaching) {
            let read__check_inv_25_state: _ProjectionRead__check_inv_25 = state._projected_state_for__check_inv_25();
            let _obj__check_inv_25: boolean = this._InvCache__check_inv_25.get(read__check_inv_25_state);
            if(_obj__check_inv_25 == null) {
                _check_inv_25 = state._check_inv_25();
                this._InvCache__check_inv_25 = this._InvCache__check_inv_25.set(read__check_inv_25_state, _check_inv_25);
            } else {
                _check_inv_25 = _obj__check_inv_25;
            }
        } else {
            _check_inv_25 = state._check_inv_25();
        }
        if(!_check_inv_25) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_25");
            return true;
        }
        let _check_inv_26: boolean;
        if(isCaching) {
            let read__check_inv_26_state: _ProjectionRead__check_inv_26 = state._projected_state_for__check_inv_26();
            let _obj__check_inv_26: boolean = this._InvCache__check_inv_26.get(read__check_inv_26_state);
            if(_obj__check_inv_26 == null) {
                _check_inv_26 = state._check_inv_26();
                this._InvCache__check_inv_26 = this._InvCache__check_inv_26.set(read__check_inv_26_state, _check_inv_26);
            } else {
                _check_inv_26 = _obj__check_inv_26;
            }
        } else {
            _check_inv_26 = state._check_inv_26();
        }
        if(!_check_inv_26) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_26");
            return true;
        }
        let _check_inv_27: boolean;
        if(isCaching) {
            let read__check_inv_27_state: _ProjectionRead__check_inv_27 = state._projected_state_for__check_inv_27();
            let _obj__check_inv_27: boolean = this._InvCache__check_inv_27.get(read__check_inv_27_state);
            if(_obj__check_inv_27 == null) {
                _check_inv_27 = state._check_inv_27();
                this._InvCache__check_inv_27 = this._InvCache__check_inv_27.set(read__check_inv_27_state, _check_inv_27);
            } else {
                _check_inv_27 = _obj__check_inv_27;
            }
        } else {
            _check_inv_27 = state._check_inv_27();
        }
        if(!_check_inv_27) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_27");
            return true;
        }
        let _check_inv_28: boolean;
        if(isCaching) {
            let read__check_inv_28_state: _ProjectionRead__check_inv_28 = state._projected_state_for__check_inv_28();
            let _obj__check_inv_28: boolean = this._InvCache__check_inv_28.get(read__check_inv_28_state);
            if(_obj__check_inv_28 == null) {
                _check_inv_28 = state._check_inv_28();
                this._InvCache__check_inv_28 = this._InvCache__check_inv_28.set(read__check_inv_28_state, _check_inv_28);
            } else {
                _check_inv_28 = _obj__check_inv_28;
            }
        } else {
            _check_inv_28 = state._check_inv_28();
        }
        if(!_check_inv_28) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_28");
            return true;
        }
        let _check_inv_29: boolean;
        if(isCaching) {
            let read__check_inv_29_state: _ProjectionRead__check_inv_29 = state._projected_state_for__check_inv_29();
            let _obj__check_inv_29: boolean = this._InvCache__check_inv_29.get(read__check_inv_29_state);
            if(_obj__check_inv_29 == null) {
                _check_inv_29 = state._check_inv_29();
                this._InvCache__check_inv_29 = this._InvCache__check_inv_29.set(read__check_inv_29_state, _check_inv_29);
            } else {
                _check_inv_29 = _obj__check_inv_29;
            }
        } else {
            _check_inv_29 = state._check_inv_29();
        }
        if(!_check_inv_29) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_29");
            return true;
        }
        let _check_inv_30: boolean;
        if(isCaching) {
            let read__check_inv_30_state: _ProjectionRead__check_inv_30 = state._projected_state_for__check_inv_30();
            let _obj__check_inv_30: boolean = this._InvCache__check_inv_30.get(read__check_inv_30_state);
            if(_obj__check_inv_30 == null) {
                _check_inv_30 = state._check_inv_30();
                this._InvCache__check_inv_30 = this._InvCache__check_inv_30.set(read__check_inv_30_state, _check_inv_30);
            } else {
                _check_inv_30 = _obj__check_inv_30;
            }
        } else {
            _check_inv_30 = state._check_inv_30();
        }
        if(!_check_inv_30) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_30");
            return true;
        }
        let _check_inv_31: boolean;
        if(isCaching) {
            let read__check_inv_31_state: _ProjectionRead__check_inv_31 = state._projected_state_for__check_inv_31();
            let _obj__check_inv_31: boolean = this._InvCache__check_inv_31.get(read__check_inv_31_state);
            if(_obj__check_inv_31 == null) {
                _check_inv_31 = state._check_inv_31();
                this._InvCache__check_inv_31 = this._InvCache__check_inv_31.set(read__check_inv_31_state, _check_inv_31);
            } else {
                _check_inv_31 = _obj__check_inv_31;
            }
        } else {
            _check_inv_31 = state._check_inv_31();
        }
        if(!_check_inv_31) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_31");
            return true;
        }
        let _check_inv_32: boolean;
        if(isCaching) {
            let read__check_inv_32_state: _ProjectionRead__check_inv_32 = state._projected_state_for__check_inv_32();
            let _obj__check_inv_32: boolean = this._InvCache__check_inv_32.get(read__check_inv_32_state);
            if(_obj__check_inv_32 == null) {
                _check_inv_32 = state._check_inv_32();
                this._InvCache__check_inv_32 = this._InvCache__check_inv_32.set(read__check_inv_32_state, _check_inv_32);
            } else {
                _check_inv_32 = _obj__check_inv_32;
            }
        } else {
            _check_inv_32 = state._check_inv_32();
        }
        if(!_check_inv_32) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_32");
            return true;
        }
        let _check_inv_33: boolean;
        if(isCaching) {
            let read__check_inv_33_state: _ProjectionRead__check_inv_33 = state._projected_state_for__check_inv_33();
            let _obj__check_inv_33: boolean = this._InvCache__check_inv_33.get(read__check_inv_33_state);
            if(_obj__check_inv_33 == null) {
                _check_inv_33 = state._check_inv_33();
                this._InvCache__check_inv_33 = this._InvCache__check_inv_33.set(read__check_inv_33_state, _check_inv_33);
            } else {
                _check_inv_33 = _obj__check_inv_33;
            }
        } else {
            _check_inv_33 = state._check_inv_33();
        }
        if(!_check_inv_33) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_33");
            return true;
        }
        let _check_inv_34: boolean;
        if(isCaching) {
            let read__check_inv_34_state: _ProjectionRead__check_inv_34 = state._projected_state_for__check_inv_34();
            let _obj__check_inv_34: boolean = this._InvCache__check_inv_34.get(read__check_inv_34_state);
            if(_obj__check_inv_34 == null) {
                _check_inv_34 = state._check_inv_34();
                this._InvCache__check_inv_34 = this._InvCache__check_inv_34.set(read__check_inv_34_state, _check_inv_34);
            } else {
                _check_inv_34 = _obj__check_inv_34;
            }
        } else {
            _check_inv_34 = state._check_inv_34();
        }
        if(!_check_inv_34) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_34");
            return true;
        }
        let _check_inv_35: boolean;
        if(isCaching) {
            let read__check_inv_35_state: _ProjectionRead__check_inv_35 = state._projected_state_for__check_inv_35();
            let _obj__check_inv_35: boolean = this._InvCache__check_inv_35.get(read__check_inv_35_state);
            if(_obj__check_inv_35 == null) {
                _check_inv_35 = state._check_inv_35();
                this._InvCache__check_inv_35 = this._InvCache__check_inv_35.set(read__check_inv_35_state, _check_inv_35);
            } else {
                _check_inv_35 = _obj__check_inv_35;
            }
        } else {
            _check_inv_35 = state._check_inv_35();
        }
        if(!_check_inv_35) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_35");
            return true;
        }
        let _check_inv_36: boolean;
        if(isCaching) {
            let read__check_inv_36_state: _ProjectionRead__check_inv_36 = state._projected_state_for__check_inv_36();
            let _obj__check_inv_36: boolean = this._InvCache__check_inv_36.get(read__check_inv_36_state);
            if(_obj__check_inv_36 == null) {
                _check_inv_36 = state._check_inv_36();
                this._InvCache__check_inv_36 = this._InvCache__check_inv_36.set(read__check_inv_36_state, _check_inv_36);
            } else {
                _check_inv_36 = _obj__check_inv_36;
            }
        } else {
            _check_inv_36 = state._check_inv_36();
        }
        if(!_check_inv_36) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_36");
            return true;
        }
        let _check_inv_37: boolean;
        if(isCaching) {
            let read__check_inv_37_state: _ProjectionRead__check_inv_37 = state._projected_state_for__check_inv_37();
            let _obj__check_inv_37: boolean = this._InvCache__check_inv_37.get(read__check_inv_37_state);
            if(_obj__check_inv_37 == null) {
                _check_inv_37 = state._check_inv_37();
                this._InvCache__check_inv_37 = this._InvCache__check_inv_37.set(read__check_inv_37_state, _check_inv_37);
            } else {
                _check_inv_37 = _obj__check_inv_37;
            }
        } else {
            _check_inv_37 = state._check_inv_37();
        }
        if(!_check_inv_37) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_37");
            return true;
        }
        let _check_inv_38: boolean;
        if(isCaching) {
            let read__check_inv_38_state: _ProjectionRead__check_inv_38 = state._projected_state_for__check_inv_38();
            let _obj__check_inv_38: boolean = this._InvCache__check_inv_38.get(read__check_inv_38_state);
            if(_obj__check_inv_38 == null) {
                _check_inv_38 = state._check_inv_38();
                this._InvCache__check_inv_38 = this._InvCache__check_inv_38.set(read__check_inv_38_state, _check_inv_38);
            } else {
                _check_inv_38 = _obj__check_inv_38;
            }
        } else {
            _check_inv_38 = state._check_inv_38();
        }
        if(!_check_inv_38) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_38");
            return true;
        }
        let _check_inv_39: boolean;
        if(isCaching) {
            let read__check_inv_39_state: _ProjectionRead__check_inv_39 = state._projected_state_for__check_inv_39();
            let _obj__check_inv_39: boolean = this._InvCache__check_inv_39.get(read__check_inv_39_state);
            if(_obj__check_inv_39 == null) {
                _check_inv_39 = state._check_inv_39();
                this._InvCache__check_inv_39 = this._InvCache__check_inv_39.set(read__check_inv_39_state, _check_inv_39);
            } else {
                _check_inv_39 = _obj__check_inv_39;
            }
        } else {
            _check_inv_39 = state._check_inv_39();
        }
        if(!_check_inv_39) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_39");
            return true;
        }
        return false;
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

