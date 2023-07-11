import {BTuple} from './btypes/BTuple.js';
import {BInteger} from './btypes/BInteger.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BRelation} from './btypes/BRelation.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";
import * as immutable from "./immutable/dist/immutable.es.js";
import {LinkedList} from  "./modelchecking/LinkedList.js";


export enum enum_DIRECTIONS {
    left_blink,
    right_blink,
    neutral_blink
}

export class DIRECTIONS implements BObject{
    value: enum_DIRECTIONS;

    constructor(value: enum_DIRECTIONS) {
        this.value = value;
    }

    equal(other: DIRECTIONS) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: DIRECTIONS) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof DIRECTIONS)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_DIRECTIONS[this.value].toString();
    }

    static get_left_blink () {return new DIRECTIONS(enum_DIRECTIONS.left_blink);}
    static get_right_blink () {return new DIRECTIONS(enum_DIRECTIONS.right_blink);}
    static get_neutral_blink () {return new DIRECTIONS(enum_DIRECTIONS.neutral_blink);}


}


export enum Type {
    BFS,
    DFS,
    MIXED
}

export default class BlinkLamps_v3 {

    parent: BlinkLamps_v3;
    dependentGuard: immutable.Set<string> = immutable.Set();
    guardCache: immutable.Map = immutable.Map();
    dependentInvariant: immutable.Set<string> = immutable.Set();
    stateAccessedVia: string;


    private static BLINK_DIRECTION: BSet<DIRECTIONS>;
    private static LAMP_STATUS: BSet<BInteger>;
    private static lamp_on: BInteger;
    private static lamp_off: BInteger;
    private static BLINK_CYCLE_COUNTER: BSet<BInteger>;
    private static cycleMaxLampStatus: BRelation<BBoolean, BInteger>;

    private static _DIRECTIONS: BSet<DIRECTIONS> = new BSet<DIRECTIONS>(new DIRECTIONS(enum_DIRECTIONS.left_blink), new DIRECTIONS(enum_DIRECTIONS.right_blink), new DIRECTIONS(enum_DIRECTIONS.neutral_blink));

    private active_blinkers: BSet<DIRECTIONS>;
    private remaining_blinks: BInteger;
    private onCycle: BBoolean;
    private blinkLeft: BInteger;
    private blinkRight: BInteger;

    static {
        BlinkLamps_v3.BLINK_DIRECTION = new BSet<DIRECTIONS>(new DIRECTIONS(enum_DIRECTIONS.left_blink), new DIRECTIONS(enum_DIRECTIONS.right_blink));
        BlinkLamps_v3.LAMP_STATUS = new BSet<BInteger>(new BInteger(0), new BInteger(100));
        BlinkLamps_v3.lamp_off = new BInteger(0);
        BlinkLamps_v3.lamp_on = new BInteger(100);
        BlinkLamps_v3.BLINK_CYCLE_COUNTER = BSet.interval(new BInteger(1).negative(), new BInteger(3));
        BlinkLamps_v3.cycleMaxLampStatus = new BRelation<BBoolean, BInteger>(new BTuple(new BBoolean(false), BlinkLamps_v3.lamp_off), new BTuple(new BBoolean(true), BlinkLamps_v3.lamp_on));
    }

    constructor(copy? : BlinkLamps_v3) {
        if(copy) {
            this.active_blinkers = copy.active_blinkers;
            this.remaining_blinks = copy.remaining_blinks;
            this.onCycle = copy.onCycle;
            this.blinkLeft = copy.blinkLeft;
            this.blinkRight = copy.blinkRight;
        } else {
            this.active_blinkers = new BSet<DIRECTIONS>();
            this.blinkLeft = BlinkLamps_v3.lamp_off;
            this.blinkRight = BlinkLamps_v3.lamp_off;
            this.remaining_blinks = new BInteger(0);
            this.onCycle = new BBoolean(false);
        }
    }



    SET_AllBlinkersOff(): void {
        this.active_blinkers = new BSet<DIRECTIONS>();
        this.remaining_blinks = new BInteger(0);
        this.blinkLeft = BlinkLamps_v3.lamp_off;
        this.blinkRight = BlinkLamps_v3.lamp_off;
    }

    SET_AllBlinkersOn(): void {
        this.active_blinkers = BlinkLamps_v3.BLINK_DIRECTION;
        this.remaining_blinks = new BInteger(1).negative();
        this.blinkLeft = BlinkLamps_v3.cycleMaxLampStatus.functionCall(this.onCycle);
        this.blinkRight = BlinkLamps_v3.cycleMaxLampStatus.functionCall(this.onCycle);
    }

    SET_BlinkersOn(direction: DIRECTIONS, rem: BInteger): void {
        this.active_blinkers = new BSet<DIRECTIONS>(direction);
        this.remaining_blinks = rem;
        if((direction.equal(new DIRECTIONS(enum_DIRECTIONS.right_blink))).booleanValue()) {
            this.blinkLeft = BlinkLamps_v3.lamp_off;
            this.blinkRight = BlinkLamps_v3.cycleMaxLampStatus.functionCall(this.onCycle);
        } else {
            this.blinkLeft = BlinkLamps_v3.cycleMaxLampStatus.functionCall(this.onCycle);
            this.blinkRight = BlinkLamps_v3.lamp_off;
        }

    }

    SET_RemainingBlinks(rem: BInteger): void {
        this.remaining_blinks = rem;

    }

    TIME_BlinkerOn(): void {
        if((new BBoolean(new BBoolean(this.blinkLeft.equal(BlinkLamps_v3.lamp_off).booleanValue() && this.blinkRight.equal(BlinkLamps_v3.lamp_off).booleanValue()).booleanValue() && this.remaining_blinks.unequal(new BInteger(0)).booleanValue())).booleanValue()) {
            let _ld_remaining_blinks: BInteger = this.remaining_blinks;
            this.onCycle = new BBoolean(true);
            if((this.active_blinkers.elementOf(new DIRECTIONS(enum_DIRECTIONS.left_blink))).booleanValue()) {
                this.blinkLeft = BlinkLamps_v3.lamp_on;
            } 
            if((this.active_blinkers.elementOf(new DIRECTIONS(enum_DIRECTIONS.right_blink))).booleanValue()) {
                this.blinkRight = BlinkLamps_v3.lamp_on;
            } 
            if((_ld_remaining_blinks.greater(new BInteger(0))).booleanValue()) {
                this.remaining_blinks = _ld_remaining_blinks.minus(new BInteger(1));
            } 
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

    TIME_BlinkerOff(): void {
        if((new BBoolean(this.blinkLeft.equal(BlinkLamps_v3.lamp_off).booleanValue() && this.blinkRight.equal(BlinkLamps_v3.lamp_off).booleanValue()).not()).booleanValue()) {
            this.blinkLeft = BlinkLamps_v3.lamp_off;
            this.blinkRight = BlinkLamps_v3.lamp_off;
            this.onCycle = new BBoolean(false);
            if((this.remaining_blinks.equal(new BInteger(0))).booleanValue()) {
                this.active_blinkers = new BSet<DIRECTIONS>();
            } 
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

    TIME_Nothing(newOnCycle: BBoolean): void {
        if((new BBoolean(new BBoolean(newOnCycle.equal(new BBoolean(false)).booleanValue() && new BBoolean(this.blinkLeft.equal(BlinkLamps_v3.lamp_off).booleanValue() && this.blinkRight.equal(BlinkLamps_v3.lamp_off).booleanValue()).booleanValue()).booleanValue() && this.active_blinkers.equal(new BSet<DIRECTIONS>()).booleanValue())).booleanValue()) {
            this.onCycle = newOnCycle;
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

    _get_BLINK_DIRECTION(): BSet<DIRECTIONS> {
        return BlinkLamps_v3.BLINK_DIRECTION;
    }

    _get_LAMP_STATUS(): BSet<BInteger> {
        return BlinkLamps_v3.LAMP_STATUS;
    }

    _get_lamp_on(): BInteger {
        return BlinkLamps_v3.lamp_on;
    }

    _get_lamp_off(): BInteger {
        return BlinkLamps_v3.lamp_off;
    }

    _get_BLINK_CYCLE_COUNTER(): BSet<BInteger> {
        return BlinkLamps_v3.BLINK_CYCLE_COUNTER;
    }

    _get_cycleMaxLampStatus(): BRelation<BBoolean, BInteger> {
        return BlinkLamps_v3.cycleMaxLampStatus;
    }

    _get_active_blinkers(): BSet<DIRECTIONS> {
        return this.active_blinkers;
    }

    _get_remaining_blinks(): BInteger {
        return this.remaining_blinks;
    }

    _get_onCycle(): BBoolean {
        return this.onCycle;
    }

    _get_blinkLeft(): BInteger {
        return this.blinkLeft;
    }

    _get_blinkRight(): BInteger {
        return this.blinkRight;
    }

    _get__DIRECTIONS(): BSet<DIRECTIONS> {
        return BlinkLamps_v3._DIRECTIONS;
    }



    equals(o: any): boolean {
        let o1: BlinkLamps_v3 = this;
        let o2: BlinkLamps_v3 = o as BlinkLamps_v3;
        return o1._get_active_blinkers().equals(o2._get_active_blinkers()) && o1._get_remaining_blinks().equals(o2._get_remaining_blinks()) && o1._get_onCycle().equals(o2._get_onCycle()) && o1._get_blinkLeft().equals(o2._get_blinkLeft()) && o1._get_blinkRight().equals(o2._get_blinkRight());
    }



    hashCode(): number {
        return this._hashCode_1();
    }

    _hashCode_1(): number {
        let result: number = 1;
        result = (1543 * result) ^ ((this._get_active_blinkers()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_remaining_blinks()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_onCycle()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_blinkLeft()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_blinkRight()).hashCode() << 1);
        return result;
    }

    _hashCode_2(): number {
        let result: number = 1;
        result = (6151 * result) ^ ((this._get_active_blinkers()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_remaining_blinks()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_onCycle()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_blinkLeft()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_blinkRight()).hashCode() << 1);
        return result;
    }

    /* TODO
    toString(): string {
        return String.join("\n", "_get_active_blinkers: " + (this._get_active_blinkers()).toString(), "_get_remaining_blinks: " + (this._get_remaining_blinks()).toString(), "_get_onCycle: " + (this._get_onCycle()).toString(), "_get_blinkLeft: " + (this._get_blinkLeft()).toString(), "_get_blinkRight: " + (this._get_blinkRight()).toString());
    }
    */


    public _copy(): BlinkLamps_v3 {
      return new BlinkLamps_v3(this);
    }


}

