import { BTuple } from 'https://favu100.github.io/b2program/visualizations/LightModel/btypes/BTuple.js';
import { BInteger } from 'https://favu100.github.io/b2program/visualizations/LightModel/btypes/BInteger.js';
import { BBoolean } from 'https://favu100.github.io/b2program/visualizations/LightModel/btypes/BBoolean.js';
import { BRelation } from 'https://favu100.github.io/b2program/visualizations/LightModel/btypes/BRelation.js';
import { BSet } from 'https://favu100.github.io/b2program/visualizations/LightModel/btypes/BSet.js';
import { SelectError } from "https://favu100.github.io/b2program/visualizations/LightModel/btypes/BUtils.js";
import * as immutable from "https://favu100.github.io/b2program/visualizations/LightModel/immutable/dist/immutable.es.js";
export var enum_DIRECTIONS;
(function (enum_DIRECTIONS) {
    enum_DIRECTIONS[enum_DIRECTIONS["left_blink"] = 0] = "left_blink";
    enum_DIRECTIONS[enum_DIRECTIONS["right_blink"] = 1] = "right_blink";
    enum_DIRECTIONS[enum_DIRECTIONS["neutral_blink"] = 2] = "neutral_blink";
})(enum_DIRECTIONS || (enum_DIRECTIONS = {}));
export class DIRECTIONS {
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
        if (!(o instanceof DIRECTIONS)) {
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
    static get_left_blink() { return new DIRECTIONS(enum_DIRECTIONS.left_blink); }
    static get_right_blink() { return new DIRECTIONS(enum_DIRECTIONS.right_blink); }
    static get_neutral_blink() { return new DIRECTIONS(enum_DIRECTIONS.neutral_blink); }
}
export var Type;
(function (Type) {
    Type[Type["BFS"] = 0] = "BFS";
    Type[Type["DFS"] = 1] = "DFS";
    Type[Type["MIXED"] = 2] = "MIXED";
})(Type || (Type = {}));
export default class BlinkLamps_v3 {
    constructor(copy) {
        this.dependentGuard = immutable.Set();
        this.guardCache = immutable.Map();
        this.dependentInvariant = immutable.Set();
        if (copy) {
            this.active_blinkers = copy.active_blinkers;
            this.remaining_blinks = copy.remaining_blinks;
            this.onCycle = copy.onCycle;
            this.blinkLeft = copy.blinkLeft;
            this.blinkRight = copy.blinkRight;
        }
        else {
            this.active_blinkers = new BSet();
            this.blinkLeft = BlinkLamps_v3.lamp_off;
            this.blinkRight = BlinkLamps_v3.lamp_off;
            this.remaining_blinks = new BInteger(0);
            this.onCycle = new BBoolean(false);
        }
    }
    SET_AllBlinkersOff() {
        this.active_blinkers = new BSet();
        this.remaining_blinks = new BInteger(0);
        this.blinkLeft = BlinkLamps_v3.lamp_off;
        this.blinkRight = BlinkLamps_v3.lamp_off;
    }
    SET_AllBlinkersOn() {
        this.active_blinkers = BlinkLamps_v3.BLINK_DIRECTION;
        this.remaining_blinks = new BInteger(1).negative();
        this.blinkLeft = BlinkLamps_v3.cycleMaxLampStatus.functionCall(this.onCycle);
        this.blinkRight = BlinkLamps_v3.cycleMaxLampStatus.functionCall(this.onCycle);
    }
    SET_BlinkersOn(direction, rem) {
        this.active_blinkers = new BSet(direction);
        this.remaining_blinks = rem;
        if ((direction.equal(new DIRECTIONS(enum_DIRECTIONS.right_blink))).booleanValue()) {
            this.blinkLeft = BlinkLamps_v3.lamp_off;
            this.blinkRight = BlinkLamps_v3.cycleMaxLampStatus.functionCall(this.onCycle);
        }
        else {
            this.blinkLeft = BlinkLamps_v3.cycleMaxLampStatus.functionCall(this.onCycle);
            this.blinkRight = BlinkLamps_v3.lamp_off;
        }
    }
    SET_RemainingBlinks(rem) {
        this.remaining_blinks = rem;
    }
    TIME_BlinkerOn() {
        if ((new BBoolean(new BBoolean(this.blinkLeft.equal(BlinkLamps_v3.lamp_off).booleanValue() && this.blinkRight.equal(BlinkLamps_v3.lamp_off).booleanValue()).booleanValue() && this.remaining_blinks.unequal(new BInteger(0)).booleanValue())).booleanValue()) {
            let _ld_remaining_blinks = this.remaining_blinks;
            this.onCycle = new BBoolean(true);
            if ((this.active_blinkers.elementOf(new DIRECTIONS(enum_DIRECTIONS.left_blink))).booleanValue()) {
                this.blinkLeft = BlinkLamps_v3.lamp_on;
            }
            if ((this.active_blinkers.elementOf(new DIRECTIONS(enum_DIRECTIONS.right_blink))).booleanValue()) {
                this.blinkRight = BlinkLamps_v3.lamp_on;
            }
            if ((_ld_remaining_blinks.greater(new BInteger(0))).booleanValue()) {
                this.remaining_blinks = _ld_remaining_blinks.minus(new BInteger(1));
            }
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    TIME_BlinkerOff() {
        if ((new BBoolean(this.blinkLeft.equal(BlinkLamps_v3.lamp_off).booleanValue() && this.blinkRight.equal(BlinkLamps_v3.lamp_off).booleanValue()).not()).booleanValue()) {
            this.blinkLeft = BlinkLamps_v3.lamp_off;
            this.blinkRight = BlinkLamps_v3.lamp_off;
            this.onCycle = new BBoolean(false);
            if ((this.remaining_blinks.equal(new BInteger(0))).booleanValue()) {
                this.active_blinkers = new BSet();
            }
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    TIME_Nothing(newOnCycle) {
        if ((new BBoolean(new BBoolean(newOnCycle.equal(new BBoolean(false)).booleanValue() && new BBoolean(this.blinkLeft.equal(BlinkLamps_v3.lamp_off).booleanValue() && this.blinkRight.equal(BlinkLamps_v3.lamp_off).booleanValue()).booleanValue()).booleanValue() && this.active_blinkers.equal(new BSet()).booleanValue())).booleanValue()) {
            this.onCycle = newOnCycle;
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    _get_BLINK_DIRECTION() {
        return BlinkLamps_v3.BLINK_DIRECTION;
    }
    _get_LAMP_STATUS() {
        return BlinkLamps_v3.LAMP_STATUS;
    }
    _get_lamp_on() {
        return BlinkLamps_v3.lamp_on;
    }
    _get_lamp_off() {
        return BlinkLamps_v3.lamp_off;
    }
    _get_BLINK_CYCLE_COUNTER() {
        return BlinkLamps_v3.BLINK_CYCLE_COUNTER;
    }
    _get_cycleMaxLampStatus() {
        return BlinkLamps_v3.cycleMaxLampStatus;
    }
    _get_active_blinkers() {
        return this.active_blinkers;
    }
    _get_remaining_blinks() {
        return this.remaining_blinks;
    }
    _get_onCycle() {
        return this.onCycle;
    }
    _get_blinkLeft() {
        return this.blinkLeft;
    }
    _get_blinkRight() {
        return this.blinkRight;
    }
    _get__DIRECTIONS() {
        return BlinkLamps_v3._DIRECTIONS;
    }
    equals(o) {
        let o1 = this;
        let o2 = o;
        return o1._get_active_blinkers().equals(o2._get_active_blinkers()) && o1._get_remaining_blinks().equals(o2._get_remaining_blinks()) && o1._get_onCycle().equals(o2._get_onCycle()) && o1._get_blinkLeft().equals(o2._get_blinkLeft()) && o1._get_blinkRight().equals(o2._get_blinkRight());
    }
    hashCode() {
        return this._hashCode_1();
    }
    _hashCode_1() {
        let result = 1;
        result = (1543 * result) ^ ((this._get_active_blinkers()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_remaining_blinks()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_onCycle()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_blinkLeft()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_blinkRight()).hashCode() << 1);
        return result;
    }
    _hashCode_2() {
        let result = 1;
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
    _copy() {
        return new BlinkLamps_v3(this);
    }
}
BlinkLamps_v3._DIRECTIONS = new BSet(new DIRECTIONS(enum_DIRECTIONS.left_blink), new DIRECTIONS(enum_DIRECTIONS.right_blink), new DIRECTIONS(enum_DIRECTIONS.neutral_blink));
(() => {
    BlinkLamps_v3.BLINK_DIRECTION = new BSet(new DIRECTIONS(enum_DIRECTIONS.left_blink), new DIRECTIONS(enum_DIRECTIONS.right_blink));
    BlinkLamps_v3.LAMP_STATUS = new BSet(new BInteger(0), new BInteger(100));
    BlinkLamps_v3.lamp_off = new BInteger(0);
    BlinkLamps_v3.lamp_on = new BInteger(100);
    BlinkLamps_v3.BLINK_CYCLE_COUNTER = BSet.interval(new BInteger(1).negative(), new BInteger(3));
    BlinkLamps_v3.cycleMaxLampStatus = new BRelation(new BTuple(new BBoolean(false), BlinkLamps_v3.lamp_off), new BTuple(new BBoolean(true), BlinkLamps_v3.lamp_on));
})();
