import {BBoolean} from './btypes/BBoolean.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";
import * as immutable from "./immutable/dist/immutable.es.js";
import {LinkedList} from  "./modelchecking/LinkedList.js";


export enum enum_SWITCH_STATUS {
    switch_on,
    switch_off
}

export class SWITCH_STATUS implements BObject{
    value: enum_SWITCH_STATUS;

    constructor(value: enum_SWITCH_STATUS) {
        this.value = value;
    }

    equal(other: SWITCH_STATUS) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: SWITCH_STATUS) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof SWITCH_STATUS)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_SWITCH_STATUS[this.value].toString();
    }

    static get_switch_on () {return new SWITCH_STATUS(enum_SWITCH_STATUS.switch_on);}
    static get_switch_off () {return new SWITCH_STATUS(enum_SWITCH_STATUS.switch_off);}


}

export enum enum_PITMAN_POSITION {
    Neutral,
    Downward5,
    Downward7,
    Upward5,
    Upward7
}

export class PITMAN_POSITION implements BObject{
    value: enum_PITMAN_POSITION;

    constructor(value: enum_PITMAN_POSITION) {
        this.value = value;
    }

    equal(other: PITMAN_POSITION) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: PITMAN_POSITION) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof PITMAN_POSITION)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_PITMAN_POSITION[this.value].toString();
    }

    static get_Neutral () {return new PITMAN_POSITION(enum_PITMAN_POSITION.Neutral);}
    static get_Downward5 () {return new PITMAN_POSITION(enum_PITMAN_POSITION.Downward5);}
    static get_Downward7 () {return new PITMAN_POSITION(enum_PITMAN_POSITION.Downward7);}
    static get_Upward5 () {return new PITMAN_POSITION(enum_PITMAN_POSITION.Upward5);}
    static get_Upward7 () {return new PITMAN_POSITION(enum_PITMAN_POSITION.Upward7);}


}

export enum enum_KEY_STATE {
    NoKeyInserted,
    KeyInserted,
    KeyInsertedOnPosition
}

export class KEY_STATE implements BObject{
    value: enum_KEY_STATE;

    constructor(value: enum_KEY_STATE) {
        this.value = value;
    }

    equal(other: KEY_STATE) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: KEY_STATE) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof KEY_STATE)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_KEY_STATE[this.value].toString();
    }

    static get_NoKeyInserted () {return new KEY_STATE(enum_KEY_STATE.NoKeyInserted);}
    static get_KeyInserted () {return new KEY_STATE(enum_KEY_STATE.KeyInserted);}
    static get_KeyInsertedOnPosition () {return new KEY_STATE(enum_KEY_STATE.KeyInsertedOnPosition);}


}


export enum Type {
    BFS,
    DFS,
    MIXED
}

export default class Sensors {

    parent: Sensors;
    dependentGuard: immutable.Set<string> = immutable.Set();
    guardCache: immutable.Map = immutable.Map();
    dependentInvariant: immutable.Set<string> = immutable.Set();
    stateAccessedVia: string;


    private static PITMAN_DIRECTION_BLINKING: BSet<PITMAN_POSITION>;
    private static PITMAN_TIP_BLINKING: BSet<PITMAN_POSITION>;

    private static _SWITCH_STATUS: BSet<SWITCH_STATUS> = new BSet<SWITCH_STATUS>(new SWITCH_STATUS(enum_SWITCH_STATUS.switch_on), new SWITCH_STATUS(enum_SWITCH_STATUS.switch_off));
    private static _PITMAN_POSITION: BSet<PITMAN_POSITION> = new BSet<PITMAN_POSITION>(new PITMAN_POSITION(enum_PITMAN_POSITION.Neutral), new PITMAN_POSITION(enum_PITMAN_POSITION.Downward5), new PITMAN_POSITION(enum_PITMAN_POSITION.Downward7), new PITMAN_POSITION(enum_PITMAN_POSITION.Upward5), new PITMAN_POSITION(enum_PITMAN_POSITION.Upward7));
    private static _KEY_STATE: BSet<KEY_STATE> = new BSet<KEY_STATE>(new KEY_STATE(enum_KEY_STATE.NoKeyInserted), new KEY_STATE(enum_KEY_STATE.KeyInserted), new KEY_STATE(enum_KEY_STATE.KeyInsertedOnPosition));

    private hazardWarningSwitchOn: SWITCH_STATUS;
    private pitmanArmUpDown: PITMAN_POSITION;
    private keyState: KEY_STATE;
    private engineOn: BBoolean;

    static {
        Sensors.PITMAN_DIRECTION_BLINKING = new BSet<PITMAN_POSITION>(new PITMAN_POSITION(enum_PITMAN_POSITION.Downward7), new PITMAN_POSITION(enum_PITMAN_POSITION.Upward7));
        Sensors.PITMAN_TIP_BLINKING = new BSet<PITMAN_POSITION>(new PITMAN_POSITION(enum_PITMAN_POSITION.Downward5), new PITMAN_POSITION(enum_PITMAN_POSITION.Upward5));
    }

    constructor(copy? : Sensors) {
        if(copy) {
            this.hazardWarningSwitchOn = copy.hazardWarningSwitchOn;
            this.pitmanArmUpDown = copy.pitmanArmUpDown;
            this.keyState = copy.keyState;
            this.engineOn = copy.engineOn;
        } else {
            this.hazardWarningSwitchOn = new SWITCH_STATUS(enum_SWITCH_STATUS.switch_off);
            this.pitmanArmUpDown = new PITMAN_POSITION(enum_PITMAN_POSITION.Neutral);
            this.keyState = new KEY_STATE(enum_KEY_STATE.KeyInsertedOnPosition);
            this.engineOn = new BBoolean(false);
        }
    }



    SET_EngineOn(): void {
        if((new BBoolean(this.engineOn.equal(new BBoolean(false)).booleanValue() && this.keyState.equal(new KEY_STATE(enum_KEY_STATE.KeyInsertedOnPosition)).booleanValue())).booleanValue()) {
            this.engineOn = new BBoolean(true);
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

    SET_EngineOff(): void {
        if((this.engineOn.equal(new BBoolean(true))).booleanValue()) {
            this.engineOn = new BBoolean(false);
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

    SET_Pitman_DirectionBlinking(newPos: PITMAN_POSITION): void {
        if((new BBoolean(Sensors.PITMAN_DIRECTION_BLINKING.elementOf(newPos).booleanValue() && newPos.unequal(this.pitmanArmUpDown).booleanValue())).booleanValue()) {
            this.pitmanArmUpDown = newPos;
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

    SET_Pitman_Reset_to_Neutral(): void {
        if((this.pitmanArmUpDown.unequal(new PITMAN_POSITION(enum_PITMAN_POSITION.Neutral))).booleanValue()) {
            this.pitmanArmUpDown = new PITMAN_POSITION(enum_PITMAN_POSITION.Neutral);
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

    SET_Pitman_Tip_blinking_short(newPos: PITMAN_POSITION): void {
        if((new BBoolean(Sensors.PITMAN_TIP_BLINKING.elementOf(newPos).booleanValue() && newPos.unequal(this.pitmanArmUpDown).booleanValue())).booleanValue()) {
            this.pitmanArmUpDown = newPos;
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

    SET_Hazard_blinking(newSwitchPos: SWITCH_STATUS): void {
        if((new BBoolean(Sensors._SWITCH_STATUS.elementOf(newSwitchPos).booleanValue() && newSwitchPos.unequal(this.hazardWarningSwitchOn).booleanValue())).booleanValue()) {
            this.hazardWarningSwitchOn = newSwitchPos;
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

    _get_PITMAN_DIRECTION_BLINKING(): BSet<PITMAN_POSITION> {
        return Sensors.PITMAN_DIRECTION_BLINKING;
    }

    _get_PITMAN_TIP_BLINKING(): BSet<PITMAN_POSITION> {
        return Sensors.PITMAN_TIP_BLINKING;
    }

    _get_hazardWarningSwitchOn(): SWITCH_STATUS {
        return this.hazardWarningSwitchOn;
    }

    _get_pitmanArmUpDown(): PITMAN_POSITION {
        return this.pitmanArmUpDown;
    }

    _get_keyState(): KEY_STATE {
        return this.keyState;
    }

    _get_engineOn(): BBoolean {
        return this.engineOn;
    }

    _get__SWITCH_STATUS(): BSet<SWITCH_STATUS> {
        return Sensors._SWITCH_STATUS;
    }

    _get__PITMAN_POSITION(): BSet<PITMAN_POSITION> {
        return Sensors._PITMAN_POSITION;
    }

    _get__KEY_STATE(): BSet<KEY_STATE> {
        return Sensors._KEY_STATE;
    }



    equals(o: any): boolean {
        let o1: Sensors = this;
        let o2: Sensors = o as Sensors;
        return o1._get_hazardWarningSwitchOn().equals(o2._get_hazardWarningSwitchOn()) && o1._get_pitmanArmUpDown().equals(o2._get_pitmanArmUpDown()) && o1._get_keyState().equals(o2._get_keyState()) && o1._get_engineOn().equals(o2._get_engineOn());
    }



    hashCode(): number {
        return this._hashCode_1();
    }

    _hashCode_1(): number {
        let result: number = 1;
        result = (1543 * result) ^ ((this._get_hazardWarningSwitchOn()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_pitmanArmUpDown()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_keyState()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_engineOn()).hashCode() << 1);
        return result;
    }

    _hashCode_2(): number {
        let result: number = 1;
        result = (6151 * result) ^ ((this._get_hazardWarningSwitchOn()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_pitmanArmUpDown()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_keyState()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_engineOn()).hashCode() << 1);
        return result;
    }

    /* TODO
    toString(): string {
        return String.join("\n", "_get_hazardWarningSwitchOn: " + (this._get_hazardWarningSwitchOn()).toString(), "_get_pitmanArmUpDown: " + (this._get_pitmanArmUpDown()).toString(), "_get_keyState: " + (this._get_keyState()).toString(), "_get_engineOn: " + (this._get_engineOn()).toString());
    }
    */


    public _copy(): Sensors {
      return new Sensors(this);
    }


}

