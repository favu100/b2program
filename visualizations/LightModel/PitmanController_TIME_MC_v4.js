import { BTuple } from './btypes/BTuple.js';
import { BInteger } from './btypes/BInteger.js';
import { BRelation } from './btypes/BRelation.js';
import { BBoolean } from './btypes/BBoolean.js';
import { BSet } from './btypes/BSet.js';
import { enum_PITMAN_POSITION } from "./Sensors.js";
import { PITMAN_POSITION } from "./Sensors.js";
import { enum_SWITCH_STATUS } from "./Sensors.js";
import { SWITCH_STATUS } from "./Sensors.js";
import { enum_TIMERS } from "./GenericTimersMC.js";
import { TIMERS } from "./GenericTimersMC.js";
import { enum_DIRECTIONS } from "./BlinkLamps_v3.js";
import { DIRECTIONS } from "./BlinkLamps_v3.js";
import GenericTimersMC from './GenericTimersMC.js';
import BlinkLamps_v3 from './BlinkLamps_v3.js';
import Sensors from './Sensors.js';
import { BUtils } from "./btypes/BUtils.js";
import { SelectError } from "./btypes/BUtils.js";
export default class PitmanController_TIME_MC_v4 {
    constructor() {
        this._BlinkLamps_v3 = new BlinkLamps_v3();
        this._Sensors = new Sensors();
        this._GenericTimersMC = new GenericTimersMC();
        PitmanController_TIME_MC_v4.pitman_direction = new BRelation(new BTuple(new PITMAN_POSITION(enum_PITMAN_POSITION.Neutral), new DIRECTIONS(enum_DIRECTIONS.neutral_blink)), new BTuple(new PITMAN_POSITION(enum_PITMAN_POSITION.Downward5), new DIRECTIONS(enum_DIRECTIONS.left_blink)), new BTuple(new PITMAN_POSITION(enum_PITMAN_POSITION.Downward7), new DIRECTIONS(enum_DIRECTIONS.left_blink)), new BTuple(new PITMAN_POSITION(enum_PITMAN_POSITION.Upward5), new DIRECTIONS(enum_DIRECTIONS.right_blink)), new BTuple(new PITMAN_POSITION(enum_PITMAN_POSITION.Upward7), new DIRECTIONS(enum_DIRECTIONS.right_blink)));
        this._GenericTimersMC.AbsoluteSetDeadline(new TIMERS(enum_TIMERS.blink_deadline), new BInteger(500));
    }
    _copy() {
        var _a, _b, _c;
        let _instance = Object.create(PitmanController_TIME_MC_v4.prototype);
        for (let key of Object.keys(this)) {
            _instance[key] = (_c = (_b = (_a = this[key])._copy) === null || _b === void 0 ? void 0 : _b.call(_a)) !== null && _c !== void 0 ? _c : this[key];
        }
        return _instance;
    }
    ENV_Pitman_Tip_blinking_start(newPos) {
        if ((new BBoolean(this._Sensors._get_PITMAN_TIP_BLINKING().elementOf(newPos).booleanValue() && newPos.unequal(this._Sensors._get_pitmanArmUpDown()).booleanValue())).booleanValue()) {
            this._Sensors.SET_Pitman_Tip_blinking_short(newPos);
            if ((new BBoolean(this._Sensors._get_hazardWarningSwitchOn().equal(new SWITCH_STATUS(enum_SWITCH_STATUS.switch_off)).booleanValue() && this._Sensors._get_engineOn().equal(new BBoolean(true)).booleanValue())).booleanValue()) {
                this._BlinkLamps_v3.SET_BlinkersOn(PitmanController_TIME_MC_v4.pitman_direction.functionCall(newPos), new BInteger(3));
            }
            this._GenericTimersMC.AddDeadline(new TIMERS(enum_TIMERS.tip_deadline), new BInteger(500));
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    RTIME_Tip_blinking_Timeout(delta) {
        if ((BSet.interval(new BInteger(0), new BInteger(500)).elementOf(delta)).booleanValue()) {
            if ((new BBoolean(new BBoolean(this._Sensors._get_PITMAN_TIP_BLINKING().elementOf(this._Sensors._get_pitmanArmUpDown()).booleanValue() && this._BlinkLamps_v3._get_remaining_blinks().greater(new BInteger(1)).booleanValue()).booleanValue() && this._BlinkLamps_v3._get_active_blinkers().equal(new BSet(PitmanController_TIME_MC_v4.pitman_direction.functionCall(this._Sensors._get_pitmanArmUpDown()))).booleanValue())).booleanValue()) {
                this._BlinkLamps_v3.SET_RemainingBlinks(new BInteger(1).negative());
            }
            this._GenericTimersMC.IncreaseTimeUntilDeadline(new TIMERS(enum_TIMERS.tip_deadline), delta);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    RTIME_BlinkerOn(delta) {
        if ((BSet.interval(new BInteger(0), new BInteger(500)).elementOf(delta)).booleanValue()) {
            this._BlinkLamps_v3.TIME_BlinkerOn();
            this._GenericTimersMC.IncreaseTimeUntilCyclicDeadline(new TIMERS(enum_TIMERS.blink_deadline), delta, new BInteger(500));
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    RTIME_BlinkerOff(delta) {
        if ((BSet.interval(new BInteger(0), new BInteger(500)).elementOf(delta)).booleanValue()) {
            this._BlinkLamps_v3.TIME_BlinkerOff();
            this._GenericTimersMC.IncreaseTimeUntilCyclicDeadline(new TIMERS(enum_TIMERS.blink_deadline), delta, new BInteger(500));
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    RTIME_Nothing(delta, newOnCycle) {
        if ((new BBoolean(BSet.interval(new BInteger(0), new BInteger(500)).elementOf(delta).booleanValue() && BUtils.BOOL.elementOf(newOnCycle).booleanValue())).booleanValue()) {
            this._BlinkLamps_v3.TIME_Nothing(newOnCycle);
            this._GenericTimersMC.IncreaseTimeUntilCyclicDeadline(new TIMERS(enum_TIMERS.blink_deadline), delta, new BInteger(100));
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    RTIME_Passes(delta) {
        if ((new BSet(new BInteger(100)).elementOf(delta)).booleanValue()) {
            this._GenericTimersMC.IncreaseTime(delta);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    ENV_Turn_EngineOn() {
        this._Sensors.SET_EngineOn();
        if ((new BBoolean(this._Sensors._get_PITMAN_DIRECTION_BLINKING().elementOf(this._Sensors._get_pitmanArmUpDown()).booleanValue() && this._Sensors._get_hazardWarningSwitchOn().equal(new SWITCH_STATUS(enum_SWITCH_STATUS.switch_off)).booleanValue())).booleanValue()) {
            this._BlinkLamps_v3.SET_BlinkersOn(PitmanController_TIME_MC_v4.pitman_direction.functionCall(this._Sensors._get_pitmanArmUpDown()), new BInteger(1).negative());
        }
    }
    ENV_Turn_EngineOff() {
        this._Sensors.SET_EngineOff();
        if ((this._Sensors._get_hazardWarningSwitchOn().equal(new SWITCH_STATUS(enum_SWITCH_STATUS.switch_off))).booleanValue()) {
            this._BlinkLamps_v3.SET_AllBlinkersOff();
        }
    }
    ENV_Pitman_DirectionBlinking(newPos) {
        if ((new BBoolean(this._Sensors._get_hazardWarningSwitchOn().equal(new SWITCH_STATUS(enum_SWITCH_STATUS.switch_off)).booleanValue() && this._Sensors._get_engineOn().equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this._BlinkLamps_v3.SET_BlinkersOn(PitmanController_TIME_MC_v4.pitman_direction.functionCall(newPos), new BInteger(1).negative());
        }
        this._Sensors.SET_Pitman_DirectionBlinking(newPos);
    }
    ENV_Pitman_Reset_to_Neutral() {
        this._Sensors.SET_Pitman_Reset_to_Neutral();
        if ((new BBoolean(this._Sensors._get_hazardWarningSwitchOn().equal(new SWITCH_STATUS(enum_SWITCH_STATUS.switch_off)).booleanValue() && this._BlinkLamps_v3._get_remaining_blinks().equal(new BInteger(1).negative()).booleanValue())).booleanValue()) {
            this._BlinkLamps_v3.SET_AllBlinkersOff();
        }
    }
    ENV_Hazard_blinking(newSwitchPos) {
        if ((new BBoolean(this._Sensors._get__SWITCH_STATUS().elementOf(newSwitchPos).booleanValue() && newSwitchPos.unequal(this._Sensors._get_hazardWarningSwitchOn()).booleanValue())).booleanValue()) {
            if ((newSwitchPos.equal(new SWITCH_STATUS(enum_SWITCH_STATUS.switch_on))).booleanValue()) {
                this._BlinkLamps_v3.SET_AllBlinkersOn();
            }
            else if ((newSwitchPos.equal(new SWITCH_STATUS(enum_SWITCH_STATUS.switch_off))).booleanValue()) {
                if ((new BBoolean(this._Sensors._get_pitmanArmUpDown().equal(new PITMAN_POSITION(enum_PITMAN_POSITION.Neutral)).booleanValue() || this._Sensors._get_engineOn().equal(new BBoolean(false)).booleanValue())).booleanValue()) {
                    this._BlinkLamps_v3.SET_AllBlinkersOff();
                }
                else if ((this._Sensors._get_PITMAN_DIRECTION_BLINKING().notElementOf(this._Sensors._get_pitmanArmUpDown())).booleanValue()) {
                    this._BlinkLamps_v3.SET_AllBlinkersOff();
                }
                else {
                    this._BlinkLamps_v3.SET_BlinkersOn(PitmanController_TIME_MC_v4.pitman_direction.functionCall(this._Sensors._get_pitmanArmUpDown()), this._BlinkLamps_v3._get_remaining_blinks());
                }
            }
            this._Sensors.SET_Hazard_blinking(newSwitchPos);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    _get_pitman_direction() {
        return PitmanController_TIME_MC_v4.pitman_direction;
    }
    _tr_ENV_Pitman_Tip_blinking_start() {
        let _ic_set_0 = new BSet();
        for (let _ic_newPos_1 of this._Sensors._get_PITMAN_TIP_BLINKING()) {
            if ((_ic_newPos_1.unequal(this._Sensors._get_pitmanArmUpDown())).booleanValue()) {
                _ic_set_0 = _ic_set_0.union(new BSet(_ic_newPos_1));
            }
        }
        return _ic_set_0;
    }
    _tr_RTIME_Tip_blinking_Timeout() {
        let _ic_set_1 = new BSet();
        for (let _ic_delta_1 of BSet.interval(new BInteger(0), new BInteger(500))) {
            _ic_set_1 = _ic_set_1.union(new BSet(_ic_delta_1));
        }
        return _ic_set_1;
    }
    _tr_RTIME_BlinkerOn() {
        let _ic_set_2 = new BSet();
        for (let _ic_delta_1 of BSet.interval(new BInteger(0), new BInteger(500))) {
            _ic_set_2 = _ic_set_2.union(new BSet(_ic_delta_1));
        }
        return _ic_set_2;
    }
    _tr_RTIME_BlinkerOff() {
        let _ic_set_3 = new BSet();
        for (let _ic_delta_1 of BSet.interval(new BInteger(0), new BInteger(500))) {
            _ic_set_3 = _ic_set_3.union(new BSet(_ic_delta_1));
        }
        return _ic_set_3;
    }
    _tr_RTIME_Nothing() {
        let _ic_set_4 = new BSet();
        for (let _ic_delta_1 of BSet.interval(new BInteger(0), new BInteger(500))) {
            for (let _ic_newOnCycle_1 of BUtils.BOOL) {
                _ic_set_4 = _ic_set_4.union(new BSet(new BTuple(_ic_delta_1, _ic_newOnCycle_1)));
            }
        }
        return _ic_set_4;
    }
    _tr_RTIME_Passes() {
        let _ic_set_5 = new BSet();
        for (let _ic_delta_1 of new BSet(new BInteger(100))) {
            _ic_set_5 = _ic_set_5.union(new BSet(_ic_delta_1));
        }
        return _ic_set_5;
    }
    _tr_ENV_Turn_EngineOn() {
        return true;
    }
    _tr_ENV_Turn_EngineOff() {
        return true;
    }
    _tr_ENV_Pitman_DirectionBlinking() {
        let _ic_set_8 = new BSet();
        for (let _ic_newPos_1 of this._Sensors._get__PITMAN_POSITION()) {
            if ((_ic_newPos_1.unequal(this._Sensors._get_pitmanArmUpDown())).booleanValue()) {
                _ic_set_8 = _ic_set_8.union(new BSet(_ic_newPos_1));
            }
        }
        return _ic_set_8;
    }
    _tr_ENV_Pitman_Reset_to_Neutral() {
        return true;
    }
    _tr_ENV_Hazard_blinking() {
        let _ic_set_10 = new BSet();
        for (let _ic_newSwitchPos_1 of this._Sensors._get__SWITCH_STATUS()) {
            if ((_ic_newSwitchPos_1.unequal(this._Sensors._get_hazardWarningSwitchOn())).booleanValue()) {
                _ic_set_10 = _ic_set_10.union(new BSet(_ic_newSwitchPos_1));
            }
        }
        return _ic_set_10;
    }
    _check_inv_1() {
        return new BBoolean(!this._Sensors._get_hazardWarningSwitchOn().equal(new SWITCH_STATUS(enum_SWITCH_STATUS.switch_on)).booleanValue() || this._BlinkLamps_v3._get_active_blinkers().equal(this._BlinkLamps_v3._get_BLINK_DIRECTION()).booleanValue()).booleanValue();
    }
    _check_inv_2() {
        return new BBoolean(!new BBoolean(this._Sensors._get_hazardWarningSwitchOn().equal(new SWITCH_STATUS(enum_SWITCH_STATUS.switch_off)).booleanValue() && this._BlinkLamps_v3._get_remaining_blinks().equal(new BInteger(1).negative()).booleanValue()).booleanValue() || this._BlinkLamps_v3._get_active_blinkers().equal(new BSet(PitmanController_TIME_MC_v4.pitman_direction.functionCall(this._Sensors._get_pitmanArmUpDown()))).booleanValue()).booleanValue();
    }
    _check_inv_3() {
        return new BBoolean(!new BBoolean(this._Sensors._get_PITMAN_DIRECTION_BLINKING().elementOf(this._Sensors._get_pitmanArmUpDown()).booleanValue() && this._Sensors._get_engineOn().equal(new BBoolean(true)).booleanValue()).booleanValue() || new BSet(PitmanController_TIME_MC_v4.pitman_direction.functionCall(this._Sensors._get_pitmanArmUpDown())).subset(this._BlinkLamps_v3._get_active_blinkers()).booleanValue()).booleanValue();
    }
    _check_inv_4() {
        return new BBoolean(!new BBoolean(this._Sensors._get_engineOn().equal(new BBoolean(false)).booleanValue() && this._Sensors._get_hazardWarningSwitchOn().equal(new SWITCH_STATUS(enum_SWITCH_STATUS.switch_off)).booleanValue()).booleanValue() || this._BlinkLamps_v3._get_active_blinkers().equal(new BSet()).booleanValue()).booleanValue();
    }
    _check_inv_5() {
        return new BBoolean(!this._Sensors._get_hazardWarningSwitchOn().equal(new SWITCH_STATUS(enum_SWITCH_STATUS.switch_on)).booleanValue() || this._BlinkLamps_v3._get_remaining_blinks().equal(new BInteger(1).negative()).booleanValue()).booleanValue();
    }
    _check_inv_6() {
        return new BBoolean(!new BBoolean(this._Sensors._get_PITMAN_DIRECTION_BLINKING().elementOf(this._Sensors._get_pitmanArmUpDown()).booleanValue() && this._Sensors._get_engineOn().equal(new BBoolean(true)).booleanValue()).booleanValue() || this._BlinkLamps_v3._get_remaining_blinks().equal(new BInteger(1).negative()).booleanValue()).booleanValue();
    }
}
