import {BTuple} from './btypes/BTuple.js';
import {BInteger} from './btypes/BInteger.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BRelation} from './btypes/BRelation.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";

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
        return 0;
    }

    toString() {
        return enum_DIRECTIONS[this.value].toString();
    }

    static get_left_blink () {return new DIRECTIONS(enum_DIRECTIONS.left_blink);}
    static get_right_blink () {return new DIRECTIONS(enum_DIRECTIONS.right_blink);}
    static get_neutral_blink () {return new DIRECTIONS(enum_DIRECTIONS.neutral_blink);}


}


export default class BlinkLamps_v3 {


    private static BLINK_DIRECTION: BSet<DIRECTIONS>;
    private static LAMP_STATUS: BSet<BInteger>;
    private static lamp_on: BInteger;
    private static lamp_off: BInteger;
    private static BLINK_CYCLE_COUNTER: BSet<BInteger>;
    private static cycleMaxLampStatus: BRelation<BBoolean, BInteger>;

    private static _DIRECTIONS: BSet<DIRECTIONS> = new BSet(new DIRECTIONS(enum_DIRECTIONS.left_blink), new DIRECTIONS(enum_DIRECTIONS.right_blink), new DIRECTIONS(enum_DIRECTIONS.neutral_blink));

    private active_blinkers: BSet<DIRECTIONS>;
    private remaining_blinks: BInteger;
    private onCycle: BBoolean;
    private blinkLeft: BInteger;
    private blinkRight: BInteger;

    constructor() {
        BlinkLamps_v3.BLINK_DIRECTION = new BSet(new DIRECTIONS(enum_DIRECTIONS.left_blink), new DIRECTIONS(enum_DIRECTIONS.right_blink));
        BlinkLamps_v3.LAMP_STATUS = new BSet(new BInteger(0), new BInteger(100));
        BlinkLamps_v3.lamp_on = new BInteger(100);
        BlinkLamps_v3.lamp_off = new BInteger(0);
        BlinkLamps_v3.BLINK_CYCLE_COUNTER = BSet.interval(new BInteger(1).negative(), new BInteger(3));
        BlinkLamps_v3.cycleMaxLampStatus = new BRelation<BBoolean, BInteger>(new BTuple(new BBoolean(false), BlinkLamps_v3.lamp_off), new BTuple(new BBoolean(true), BlinkLamps_v3.lamp_on));
        this.active_blinkers = new BSet();
        this.blinkLeft = BlinkLamps_v3.lamp_off;
        this.blinkRight = BlinkLamps_v3.lamp_off;
        this.remaining_blinks = new BInteger(0);
        this.onCycle = new BBoolean(false);
    }

    public _copy(): BlinkLamps_v3 {
        let _instance = Object.create(BlinkLamps_v3.prototype);
        for(let key of Object.keys(this)) {
            _instance[key] = this[key]._copy?.() ?? this[key];
        }
        return _instance;
    }

     SET_AllBlinkersOff(): void {
        this.active_blinkers = new BSet();
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
        this.active_blinkers = new BSet(direction);
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
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     TIME_BlinkerOff(): void {
        if((new BBoolean(this.blinkLeft.equal(BlinkLamps_v3.lamp_off).booleanValue() && this.blinkRight.equal(BlinkLamps_v3.lamp_off).booleanValue()).not()).booleanValue()) {
            this.blinkLeft = BlinkLamps_v3.lamp_off;
            this.blinkRight = BlinkLamps_v3.lamp_off;
            this.onCycle = new BBoolean(false);
            if((this.remaining_blinks.equal(new BInteger(0))).booleanValue()) {
                this.active_blinkers = new BSet();
            } 
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     TIME_Nothing(newOnCycle: BBoolean): void {
        if((new BBoolean(new BBoolean(newOnCycle.equal(new BBoolean(false)).booleanValue() && new BBoolean(this.blinkLeft.equal(BlinkLamps_v3.lamp_off).booleanValue() && this.blinkRight.equal(BlinkLamps_v3.lamp_off).booleanValue()).booleanValue()).booleanValue() && this.active_blinkers.equal(new BSet()).booleanValue())).booleanValue()) {
            this.onCycle = newOnCycle;
        }  else {
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




}

