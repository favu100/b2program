import { BBoolean } from './btypes/BBoolean.js';
import { BSet } from './btypes/BSet.js';
import { SelectError } from "./btypes/BUtils.js";
export var enum_SWITCH_STATUS;
(function (enum_SWITCH_STATUS) {
    enum_SWITCH_STATUS[enum_SWITCH_STATUS["switch_on"] = 0] = "switch_on";
    enum_SWITCH_STATUS[enum_SWITCH_STATUS["switch_off"] = 1] = "switch_off";
})(enum_SWITCH_STATUS || (enum_SWITCH_STATUS = {}));
export class SWITCH_STATUS {
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
        if (!(o instanceof SWITCH_STATUS)) {
            return false;
        }
        return this.value === o.value;
    }
    hashCode() {
        return 0;
    }
    toString() {
        return enum_SWITCH_STATUS[this.value].toString();
    }
    static get_switch_on() { return new SWITCH_STATUS(enum_SWITCH_STATUS.switch_on); }
    static get_switch_off() { return new SWITCH_STATUS(enum_SWITCH_STATUS.switch_off); }
}
export var enum_PITMAN_POSITION;
(function (enum_PITMAN_POSITION) {
    enum_PITMAN_POSITION[enum_PITMAN_POSITION["Neutral"] = 0] = "Neutral";
    enum_PITMAN_POSITION[enum_PITMAN_POSITION["Downward5"] = 1] = "Downward5";
    enum_PITMAN_POSITION[enum_PITMAN_POSITION["Downward7"] = 2] = "Downward7";
    enum_PITMAN_POSITION[enum_PITMAN_POSITION["Upward5"] = 3] = "Upward5";
    enum_PITMAN_POSITION[enum_PITMAN_POSITION["Upward7"] = 4] = "Upward7";
})(enum_PITMAN_POSITION || (enum_PITMAN_POSITION = {}));
export class PITMAN_POSITION {
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
        if (!(o instanceof PITMAN_POSITION)) {
            return false;
        }
        return this.value === o.value;
    }
    hashCode() {
        return 0;
    }
    toString() {
        return enum_PITMAN_POSITION[this.value].toString();
    }
    static get_Neutral() { return new PITMAN_POSITION(enum_PITMAN_POSITION.Neutral); }
    static get_Downward5() { return new PITMAN_POSITION(enum_PITMAN_POSITION.Downward5); }
    static get_Downward7() { return new PITMAN_POSITION(enum_PITMAN_POSITION.Downward7); }
    static get_Upward5() { return new PITMAN_POSITION(enum_PITMAN_POSITION.Upward5); }
    static get_Upward7() { return new PITMAN_POSITION(enum_PITMAN_POSITION.Upward7); }
}
export var enum_KEY_STATE;
(function (enum_KEY_STATE) {
    enum_KEY_STATE[enum_KEY_STATE["NoKeyInserted"] = 0] = "NoKeyInserted";
    enum_KEY_STATE[enum_KEY_STATE["KeyInserted"] = 1] = "KeyInserted";
    enum_KEY_STATE[enum_KEY_STATE["KeyInsertedOnPosition"] = 2] = "KeyInsertedOnPosition";
})(enum_KEY_STATE || (enum_KEY_STATE = {}));
export class KEY_STATE {
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
        if (!(o instanceof KEY_STATE)) {
            return false;
        }
        return this.value === o.value;
    }
    hashCode() {
        return 0;
    }
    toString() {
        return enum_KEY_STATE[this.value].toString();
    }
    static get_NoKeyInserted() { return new KEY_STATE(enum_KEY_STATE.NoKeyInserted); }
    static get_KeyInserted() { return new KEY_STATE(enum_KEY_STATE.KeyInserted); }
    static get_KeyInsertedOnPosition() { return new KEY_STATE(enum_KEY_STATE.KeyInsertedOnPosition); }
}
export default class Sensors {
    constructor() {
        Sensors.PITMAN_DIRECTION_BLINKING = new BSet(new PITMAN_POSITION(enum_PITMAN_POSITION.Downward7), new PITMAN_POSITION(enum_PITMAN_POSITION.Upward7));
        Sensors.PITMAN_TIP_BLINKING = new BSet(new PITMAN_POSITION(enum_PITMAN_POSITION.Downward5), new PITMAN_POSITION(enum_PITMAN_POSITION.Upward5));
        this.hazardWarningSwitchOn = new SWITCH_STATUS(enum_SWITCH_STATUS.switch_off);
        this.pitmanArmUpDown = new PITMAN_POSITION(enum_PITMAN_POSITION.Neutral);
        this.keyState = new KEY_STATE(enum_KEY_STATE.KeyInsertedOnPosition);
        this.engineOn = new BBoolean(false);
    }
    _copy() {
        var _a, _b, _c;
        let _instance = Object.create(Sensors.prototype);
        for (let key of Object.keys(this)) {
            _instance[key] = (_c = (_b = (_a = this[key])._copy) === null || _b === void 0 ? void 0 : _b.call(_a)) !== null && _c !== void 0 ? _c : this[key];
        }
        return _instance;
    }
    SET_EngineOn() {
        if ((new BBoolean(this.engineOn.equal(new BBoolean(false)).booleanValue() && this.keyState.equal(new KEY_STATE(enum_KEY_STATE.KeyInsertedOnPosition)).booleanValue())).booleanValue()) {
            this.engineOn = new BBoolean(true);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    SET_EngineOff() {
        if ((this.engineOn.equal(new BBoolean(true))).booleanValue()) {
            this.engineOn = new BBoolean(false);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    SET_Pitman_DirectionBlinking(newPos) {
        if ((new BBoolean(Sensors.PITMAN_DIRECTION_BLINKING.elementOf(newPos).booleanValue() && newPos.unequal(this.pitmanArmUpDown).booleanValue())).booleanValue()) {
            this.pitmanArmUpDown = newPos;
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    SET_Pitman_Reset_to_Neutral() {
        if ((this.pitmanArmUpDown.unequal(new PITMAN_POSITION(enum_PITMAN_POSITION.Neutral))).booleanValue()) {
            this.pitmanArmUpDown = new PITMAN_POSITION(enum_PITMAN_POSITION.Neutral);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    SET_Pitman_Tip_blinking_short(newPos) {
        if ((new BBoolean(Sensors.PITMAN_TIP_BLINKING.elementOf(newPos).booleanValue() && newPos.unequal(this.pitmanArmUpDown).booleanValue())).booleanValue()) {
            this.pitmanArmUpDown = newPos;
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    SET_Hazard_blinking(newSwitchPos) {
        if ((new BBoolean(Sensors._SWITCH_STATUS.elementOf(newSwitchPos).booleanValue() && newSwitchPos.unequal(this.hazardWarningSwitchOn).booleanValue())).booleanValue()) {
            this.hazardWarningSwitchOn = newSwitchPos;
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    _get_PITMAN_DIRECTION_BLINKING() {
        return Sensors.PITMAN_DIRECTION_BLINKING;
    }
    _get_PITMAN_TIP_BLINKING() {
        return Sensors.PITMAN_TIP_BLINKING;
    }
    _get_hazardWarningSwitchOn() {
        return this.hazardWarningSwitchOn;
    }
    _get_pitmanArmUpDown() {
        return this.pitmanArmUpDown;
    }
    _get_keyState() {
        return this.keyState;
    }
    _get_engineOn() {
        return this.engineOn;
    }
    _get__SWITCH_STATUS() {
        return Sensors._SWITCH_STATUS;
    }
    _get__PITMAN_POSITION() {
        return Sensors._PITMAN_POSITION;
    }
    _get__KEY_STATE() {
        return Sensors._KEY_STATE;
    }
}
Sensors._SWITCH_STATUS = new BSet(new SWITCH_STATUS(enum_SWITCH_STATUS.switch_on), new SWITCH_STATUS(enum_SWITCH_STATUS.switch_off));
Sensors._PITMAN_POSITION = new BSet(new PITMAN_POSITION(enum_PITMAN_POSITION.Neutral), new PITMAN_POSITION(enum_PITMAN_POSITION.Downward5), new PITMAN_POSITION(enum_PITMAN_POSITION.Downward7), new PITMAN_POSITION(enum_PITMAN_POSITION.Upward5), new PITMAN_POSITION(enum_PITMAN_POSITION.Upward7));
Sensors._KEY_STATE = new BSet(new KEY_STATE(enum_KEY_STATE.NoKeyInserted), new KEY_STATE(enum_KEY_STATE.KeyInserted), new KEY_STATE(enum_KEY_STATE.KeyInsertedOnPosition));
