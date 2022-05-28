import {BTuple} from './btypes/BTuple.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BRelation} from './btypes/BRelation.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";

export enum enum_DOOR_STATE {
    open,
    closed,
    door_moving
}

export class DOOR_STATE implements BObject{
    value: enum_DOOR_STATE;

    constructor(value: enum_DOOR_STATE) {
        this.value = value;
    }

    equal(other: DOOR_STATE) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: DOOR_STATE) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof DOOR_STATE)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return 0;
    }

    toString() {
        return enum_DOOR_STATE[this.value].toString();
    }

    static get_open () {return new DOOR_STATE(enum_DOOR_STATE.open);}
    static get_closed () {return new DOOR_STATE(enum_DOOR_STATE.closed);}
    static get_door_moving () {return new DOOR_STATE(enum_DOOR_STATE.door_moving);}


}

export enum enum_GEAR_STATE {
    retracted,
    extended,
    gear_moving
}

export class GEAR_STATE implements BObject{
    value: enum_GEAR_STATE;

    constructor(value: enum_GEAR_STATE) {
        this.value = value;
    }

    equal(other: GEAR_STATE) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: GEAR_STATE) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof GEAR_STATE)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return 0;
    }

    toString() {
        return enum_GEAR_STATE[this.value].toString();
    }

    static get_retracted () {return new GEAR_STATE(enum_GEAR_STATE.retracted);}
    static get_extended () {return new GEAR_STATE(enum_GEAR_STATE.extended);}
    static get_gear_moving () {return new GEAR_STATE(enum_GEAR_STATE.gear_moving);}


}

export enum enum_HANDLE_STATE {
    up,
    down
}

export class HANDLE_STATE implements BObject{
    value: enum_HANDLE_STATE;

    constructor(value: enum_HANDLE_STATE) {
        this.value = value;
    }

    equal(other: HANDLE_STATE) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: HANDLE_STATE) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof HANDLE_STATE)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return 0;
    }

    toString() {
        return enum_HANDLE_STATE[this.value].toString();
    }

    static get_up () {return new HANDLE_STATE(enum_HANDLE_STATE.up);}
    static get_down () {return new HANDLE_STATE(enum_HANDLE_STATE.down);}


}

export enum enum_POSITION {
    fr,
    lt,
    rt
}

export class POSITION implements BObject{
    value: enum_POSITION;

    constructor(value: enum_POSITION) {
        this.value = value;
    }

    equal(other: POSITION) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: POSITION) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof POSITION)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return 0;
    }

    toString() {
        return enum_POSITION[this.value].toString();
    }

    static get_fr () {return new POSITION(enum_POSITION.fr);}
    static get_lt () {return new POSITION(enum_POSITION.lt);}
    static get_rt () {return new POSITION(enum_POSITION.rt);}


}

export enum enum_SWITCH_STATE {
    switch_open,
    switch_closed
}

export class SWITCH_STATE implements BObject{
    value: enum_SWITCH_STATE;

    constructor(value: enum_SWITCH_STATE) {
        this.value = value;
    }

    equal(other: SWITCH_STATE) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: SWITCH_STATE) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof SWITCH_STATE)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return 0;
    }

    toString() {
        return enum_SWITCH_STATE[this.value].toString();
    }

    static get_switch_open () {return new SWITCH_STATE(enum_SWITCH_STATE.switch_open);}
    static get_switch_closed () {return new SWITCH_STATE(enum_SWITCH_STATE.switch_closed);}


}

export enum enum_PLANE_STATE {
    ground,
    flight
}

export class PLANE_STATE implements BObject{
    value: enum_PLANE_STATE;

    constructor(value: enum_PLANE_STATE) {
        this.value = value;
    }

    equal(other: PLANE_STATE) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: PLANE_STATE) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof PLANE_STATE)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return 0;
    }

    toString() {
        return enum_PLANE_STATE[this.value].toString();
    }

    static get_ground () {return new PLANE_STATE(enum_PLANE_STATE.ground);}
    static get_flight () {return new PLANE_STATE(enum_PLANE_STATE.flight);}


}

export enum enum_VALVE_STATE {
    valve_open,
    valve_closed
}

export class VALVE_STATE implements BObject{
    value: enum_VALVE_STATE;

    constructor(value: enum_VALVE_STATE) {
        this.value = value;
    }

    equal(other: VALVE_STATE) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: VALVE_STATE) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof VALVE_STATE)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return 0;
    }

    toString() {
        return enum_VALVE_STATE[this.value].toString();
    }

    static get_valve_open () {return new VALVE_STATE(enum_VALVE_STATE.valve_open);}
    static get_valve_closed () {return new VALVE_STATE(enum_VALVE_STATE.valve_closed);}


}


export default class LandingGear_R6 {



    private static _DOOR_STATE: BSet<DOOR_STATE> = new BSet(new DOOR_STATE(enum_DOOR_STATE.open), new DOOR_STATE(enum_DOOR_STATE.closed), new DOOR_STATE(enum_DOOR_STATE.door_moving));
    private static _GEAR_STATE: BSet<GEAR_STATE> = new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted), new GEAR_STATE(enum_GEAR_STATE.extended), new GEAR_STATE(enum_GEAR_STATE.gear_moving));
    private static _HANDLE_STATE: BSet<HANDLE_STATE> = new BSet(new HANDLE_STATE(enum_HANDLE_STATE.up), new HANDLE_STATE(enum_HANDLE_STATE.down));
    private static _POSITION: BSet<POSITION> = new BSet(new POSITION(enum_POSITION.fr), new POSITION(enum_POSITION.lt), new POSITION(enum_POSITION.rt));
    private static _SWITCH_STATE: BSet<SWITCH_STATE> = new BSet(new SWITCH_STATE(enum_SWITCH_STATE.switch_open), new SWITCH_STATE(enum_SWITCH_STATE.switch_closed));
    private static _PLANE_STATE: BSet<PLANE_STATE> = new BSet(new PLANE_STATE(enum_PLANE_STATE.ground), new PLANE_STATE(enum_PLANE_STATE.flight));
    private static _VALVE_STATE: BSet<VALVE_STATE> = new BSet(new VALVE_STATE(enum_VALVE_STATE.valve_open), new VALVE_STATE(enum_VALVE_STATE.valve_closed));

    private analogical_switch: SWITCH_STATE;
    private general_EV: BBoolean;
    private general_valve: VALVE_STATE;
    private handle_move: BBoolean;
    private close_EV: BBoolean;
    private extend_EV: BBoolean;
    private open_EV: BBoolean;
    private retract_EV: BBoolean;
    private shock_absorber: PLANE_STATE;
    private valve_close_door: VALVE_STATE;
    private valve_extend_gear: VALVE_STATE;
    private valve_open_door: VALVE_STATE;
    private valve_retract_gear: VALVE_STATE;
    private doors: BRelation<POSITION, DOOR_STATE>;
    private gears: BRelation<POSITION, GEAR_STATE>;
    private handle: HANDLE_STATE;
    private door: DOOR_STATE;
    private gear: GEAR_STATE;

    constructor() {
        this.gears = BRelation.cartesianProduct(LandingGear_R6._POSITION, new BSet(new GEAR_STATE(enum_GEAR_STATE.extended)));
        this.doors = BRelation.cartesianProduct(LandingGear_R6._POSITION, new BSet(new DOOR_STATE(enum_DOOR_STATE.closed)));
        this.handle = new HANDLE_STATE(enum_HANDLE_STATE.down);
        this.valve_extend_gear = new VALVE_STATE(enum_VALVE_STATE.valve_closed);
        this.valve_retract_gear = new VALVE_STATE(enum_VALVE_STATE.valve_closed);
        this.valve_open_door = new VALVE_STATE(enum_VALVE_STATE.valve_closed);
        this.valve_close_door = new VALVE_STATE(enum_VALVE_STATE.valve_closed);
        this.open_EV = new BBoolean(false);
        this.close_EV = new BBoolean(false);
        this.retract_EV = new BBoolean(false);
        this.extend_EV = new BBoolean(false);
        this.shock_absorber = new PLANE_STATE(enum_PLANE_STATE.ground);
        this.general_EV = new BBoolean(false);
        this.general_valve = new VALVE_STATE(enum_VALVE_STATE.valve_closed);
        this.analogical_switch = new SWITCH_STATE(enum_SWITCH_STATE.switch_open);
        this.handle_move = new BBoolean(false);
        this.gear = new GEAR_STATE(enum_GEAR_STATE.extended);
        this.door = new DOOR_STATE(enum_DOOR_STATE.closed);
    }

    public _copy(): LandingGear_R6 {
        let _instance = Object.create(LandingGear_R6.prototype);
        for(let key of Object.keys(this)) {
            _instance[key] = this[key]._copy?.() ?? this[key];
        }
        return _instance;
    }

     begin_flying(): void {
        if((this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground))).booleanValue()) {
            this.shock_absorber = new PLANE_STATE(enum_PLANE_STATE.flight);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     land_plane(): void {
        if((this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.flight))).booleanValue()) {
            this.shock_absorber = new PLANE_STATE(enum_PLANE_STATE.ground);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     open_valve_door_open(): void {
        if((new BBoolean(this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_closed)).booleanValue() && this.open_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.valve_open_door = new VALVE_STATE(enum_VALVE_STATE.valve_open);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     close_valve_door_open(): void {
        if((new BBoolean(this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
            this.valve_open_door = new VALVE_STATE(enum_VALVE_STATE.valve_closed);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     open_valve_door_close(): void {
        if((new BBoolean(this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_closed)).booleanValue() && this.close_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.valve_close_door = new VALVE_STATE(enum_VALVE_STATE.valve_open);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     close_valve_door_close(): void {
        if((new BBoolean(this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() && this.close_EV.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
            this.valve_close_door = new VALVE_STATE(enum_VALVE_STATE.valve_closed);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     open_valve_retract_gear(): void {
        if((new BBoolean(this.valve_retract_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_closed)).booleanValue() && this.retract_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.valve_retract_gear = new VALVE_STATE(enum_VALVE_STATE.valve_open);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     close_valve_retract_gear(): void {
        if((new BBoolean(this.valve_retract_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
            this.valve_retract_gear = new VALVE_STATE(enum_VALVE_STATE.valve_closed);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     open_valve_extend_gear(): void {
        if((new BBoolean(this.valve_extend_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_closed)).booleanValue() && this.extend_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.valve_extend_gear = new VALVE_STATE(enum_VALVE_STATE.valve_open);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     close_valve_extend_gear(): void {
        if((new BBoolean(this.valve_extend_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
            this.valve_extend_gear = new VALVE_STATE(enum_VALVE_STATE.valve_closed);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     con_stimulate_open_door_valve(): void {
        if((new BBoolean(new BBoolean(new BBoolean(this.open_EV.equal(new BBoolean(false)).booleanValue() && this.close_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).not().booleanValue()).booleanValue() || new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).not().booleanValue()).booleanValue() && new BBoolean(this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).not().booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.open_EV = new BBoolean(true);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     con_stop_stimulate_open_door_valve(): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.open_EV.equal(new BBoolean(true)).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.open_EV = new BBoolean(false);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     con_stimulate_close_door_valve(): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.close_EV.equal(new BBoolean(false)).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).not().booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.close_EV = new BBoolean(true);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     con_stop_stimulate_close_door_valve(): void {
        if((new BBoolean(new BBoolean(this.close_EV.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() || new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.close_EV = new BBoolean(false);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     con_stimulate_retract_gear_valve(): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.retract_EV.equal(new BBoolean(false)).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(true)).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue()).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).not().booleanValue()).booleanValue() && this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.flight)).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.retract_EV = new BBoolean(true);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     con_stop_stimulate_retract_gear_valve(): void {
        if((new BBoolean(new BBoolean(this.retract_EV.equal(new BBoolean(true)).booleanValue() && new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.retract_EV = new BBoolean(false);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     con_stimulate_extend_gear_valve(): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.extend_EV.equal(new BBoolean(false)).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(true)).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue()).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).not().booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.extend_EV = new BBoolean(true);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     con_stop_stimulate_extend_gear_valve(): void {
        if((new BBoolean(new BBoolean(this.extend_EV.equal(new BBoolean(true)).booleanValue() && new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.extend_EV = new BBoolean(false);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     env_start_retracting_first(gr: POSITION): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue()).booleanValue() && this.gears.functionCall(gr).equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue() && this.valve_retract_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BSet(new GEAR_STATE(enum_GEAR_STATE.extended), new GEAR_STATE(enum_GEAR_STATE.gear_moving)).elementOf(this.gear).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue()) {
            let _ld_gears: BRelation<POSITION, GEAR_STATE> = this.gears;
            this.gears = _ld_gears.override(new BRelation<POSITION, GEAR_STATE>(new BTuple(gr, new GEAR_STATE(enum_GEAR_STATE.gear_moving))));
            this.gear = new GEAR_STATE(enum_GEAR_STATE.gear_moving);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     env_retract_gear_skip(gr: POSITION): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.gears.relationImage(LandingGear_R6._POSITION.difference(new BSet(gr))).unequal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue()).booleanValue() && this.gears.functionCall(gr).equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
            this.gears = this.gears.override(new BRelation<POSITION, GEAR_STATE>(new BTuple(gr, new GEAR_STATE(enum_GEAR_STATE.retracted))));
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     env_retract_gear_last(gr: POSITION): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.gears.relationImage(LandingGear_R6._POSITION.difference(new BSet(gr))).equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue()).booleanValue() && this.gears.functionCall(gr).equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue()) {
            let _ld_gears: BRelation<POSITION, GEAR_STATE> = this.gears;
            this.gears = _ld_gears.override(new BRelation<POSITION, GEAR_STATE>(new BTuple(gr, new GEAR_STATE(enum_GEAR_STATE.retracted))));
            this.gear = new GEAR_STATE(enum_GEAR_STATE.retracted);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     env_start_extending(gr: POSITION): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue()).booleanValue() && this.gears.functionCall(gr).equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue()).booleanValue() && this.valve_extend_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BSet(new GEAR_STATE(enum_GEAR_STATE.gear_moving), new GEAR_STATE(enum_GEAR_STATE.retracted)).elementOf(this.gear).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue()) {
            let _ld_gears: BRelation<POSITION, GEAR_STATE> = this.gears;
            this.gears = _ld_gears.override(new BRelation<POSITION, GEAR_STATE>(new BTuple(gr, new GEAR_STATE(enum_GEAR_STATE.gear_moving))));
            this.gear = new GEAR_STATE(enum_GEAR_STATE.gear_moving);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     env_extend_gear_last(gr: POSITION): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue()).booleanValue() && this.gears.relationImage(LandingGear_R6._POSITION.difference(new BSet(gr))).equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.gears.functionCall(gr).equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue()) {
            let _ld_gears: BRelation<POSITION, GEAR_STATE> = this.gears;
            this.gears = _ld_gears.override(new BRelation<POSITION, GEAR_STATE>(new BTuple(gr, new GEAR_STATE(enum_GEAR_STATE.extended))));
            this.gear = new GEAR_STATE(enum_GEAR_STATE.extended);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     env_extend_gear_skip(gr: POSITION): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue()).booleanValue() && this.gears.relationImage(LandingGear_R6._POSITION.difference(new BSet(gr))).unequal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.gears.functionCall(gr).equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
            this.gears = this.gears.override(new BRelation<POSITION, GEAR_STATE>(new BTuple(gr, new GEAR_STATE(enum_GEAR_STATE.extended))));
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     env_start_open_door(gr: POSITION): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.functionCall(gr).equal(new DOOR_STATE(enum_DOOR_STATE.closed)).booleanValue()).booleanValue() && this.gears.functionCall(gr).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BSet(new DOOR_STATE(enum_DOOR_STATE.closed), new DOOR_STATE(enum_DOOR_STATE.door_moving)).elementOf(this.door).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
            let _ld_doors: BRelation<POSITION, DOOR_STATE> = this.doors;
            this.doors = _ld_doors.override(new BRelation<POSITION, DOOR_STATE>(new BTuple(gr, new DOOR_STATE(enum_DOOR_STATE.door_moving))));
            this.door = new DOOR_STATE(enum_DOOR_STATE.door_moving);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     env_open_door_last(gr: POSITION): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.functionCall(gr).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue()).booleanValue() && this.gears.functionCall(gr).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet(gr))).equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
            let _ld_doors: BRelation<POSITION, DOOR_STATE> = this.doors;
            this.doors = _ld_doors.override(new BRelation<POSITION, DOOR_STATE>(new BTuple(gr, new DOOR_STATE(enum_DOOR_STATE.open))));
            this.door = new DOOR_STATE(enum_DOOR_STATE.open);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     env_open_door_skip(gr: POSITION): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.functionCall(gr).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue()).booleanValue() && this.gears.functionCall(gr).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet(gr))).unequal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
            this.doors = this.doors.override(new BRelation<POSITION, DOOR_STATE>(new BTuple(gr, new DOOR_STATE(enum_DOOR_STATE.open))));
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     env_start_close_door(gr: POSITION): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.functionCall(gr).equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue()).booleanValue() && this.gears.functionCall(gr).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BSet(new DOOR_STATE(enum_DOOR_STATE.door_moving), new DOOR_STATE(enum_DOOR_STATE.open)).elementOf(this.door).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BSet(new GEAR_STATE(enum_GEAR_STATE.extended), new GEAR_STATE(enum_GEAR_STATE.retracted)).elementOf(this.gear).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
            let _ld_doors: BRelation<POSITION, DOOR_STATE> = this.doors;
            this.doors = _ld_doors.override(new BRelation<POSITION, DOOR_STATE>(new BTuple(gr, new DOOR_STATE(enum_DOOR_STATE.door_moving))));
            this.door = new DOOR_STATE(enum_DOOR_STATE.door_moving);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     env_close_door(gr: POSITION): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.functionCall(gr).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue()).booleanValue() && this.gears.functionCall(gr).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet(gr))).equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BSet(new GEAR_STATE(enum_GEAR_STATE.extended), new GEAR_STATE(enum_GEAR_STATE.retracted)).elementOf(this.gear).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
            let _ld_doors: BRelation<POSITION, DOOR_STATE> = this.doors;
            this.doors = _ld_doors.override(new BRelation<POSITION, DOOR_STATE>(new BTuple(gr, new DOOR_STATE(enum_DOOR_STATE.closed))));
            this.door = new DOOR_STATE(enum_DOOR_STATE.closed);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     env_close_door_skip(gr: POSITION): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.functionCall(gr).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue()).booleanValue() && this.gears.functionCall(gr).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet(gr))).unequal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
            this.doors = this.doors.override(new BRelation<POSITION, DOOR_STATE>(new BTuple(gr, new DOOR_STATE(enum_DOOR_STATE.closed))));
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     toggle_handle_up(): void {
        if((this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down))).booleanValue()) {
            this.handle = new HANDLE_STATE(enum_HANDLE_STATE.up);
            this.handle_move = new BBoolean(true);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     toggle_handle_down(): void {
        if((this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up))).booleanValue()) {
            this.handle = new HANDLE_STATE(enum_HANDLE_STATE.down);
            this.handle_move = new BBoolean(true);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     con_stimulate_general_valve(): void {
        if((new BBoolean(this.general_EV.equal(new BBoolean(false)).booleanValue() && this.handle_move.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.general_EV = new BBoolean(true);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     con_stop_stimulate_general_valve(): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.general_EV.equal(new BBoolean(true)).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.close_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.close_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() || new BBoolean(new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() || new BBoolean(new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
            this.general_EV = new BBoolean(false);
            this.handle_move = new BBoolean(false);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     evn_open_general_valve(): void {
        if((new BBoolean(new BBoolean(this.general_EV.equal(new BBoolean(true)).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_closed)).booleanValue()).booleanValue() && this.analogical_switch.equal(new SWITCH_STATE(enum_SWITCH_STATE.switch_closed)).booleanValue())).booleanValue()) {
            this.general_valve = new VALVE_STATE(enum_VALVE_STATE.valve_open);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     evn_close_general_valve(): void {
        if((new BBoolean(new BBoolean(this.general_EV.equal(new BBoolean(false)).booleanValue() || this.analogical_switch.equal(new SWITCH_STATE(enum_SWITCH_STATE.switch_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
            this.general_valve = new VALVE_STATE(enum_VALVE_STATE.valve_closed);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     env_close_analogical_switch(): void {
        if((new BBoolean(this.analogical_switch.equal(new SWITCH_STATE(enum_SWITCH_STATE.switch_open)).booleanValue() && this.handle_move.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.analogical_switch = new SWITCH_STATE(enum_SWITCH_STATE.switch_closed);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     env_open_analogical_switch(): void {
        if((this.analogical_switch.equal(new SWITCH_STATE(enum_SWITCH_STATE.switch_closed))).booleanValue()) {
            this.analogical_switch = new SWITCH_STATE(enum_SWITCH_STATE.switch_open);
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

    _get_analogical_switch(): SWITCH_STATE {
        return this.analogical_switch;
    }

    _get_general_EV(): BBoolean {
        return this.general_EV;
    }

    _get_general_valve(): VALVE_STATE {
        return this.general_valve;
    }

    _get_handle_move(): BBoolean {
        return this.handle_move;
    }

    _get_close_EV(): BBoolean {
        return this.close_EV;
    }

    _get_extend_EV(): BBoolean {
        return this.extend_EV;
    }

    _get_open_EV(): BBoolean {
        return this.open_EV;
    }

    _get_retract_EV(): BBoolean {
        return this.retract_EV;
    }

    _get_shock_absorber(): PLANE_STATE {
        return this.shock_absorber;
    }

    _get_valve_close_door(): VALVE_STATE {
        return this.valve_close_door;
    }

    _get_valve_extend_gear(): VALVE_STATE {
        return this.valve_extend_gear;
    }

    _get_valve_open_door(): VALVE_STATE {
        return this.valve_open_door;
    }

    _get_valve_retract_gear(): VALVE_STATE {
        return this.valve_retract_gear;
    }

    _get_doors(): BRelation<POSITION, DOOR_STATE> {
        return this.doors;
    }

    _get_gears(): BRelation<POSITION, GEAR_STATE> {
        return this.gears;
    }

    _get_handle(): HANDLE_STATE {
        return this.handle;
    }

    _get_door(): DOOR_STATE {
        return this.door;
    }

    _get_gear(): GEAR_STATE {
        return this.gear;
    }

    _get__DOOR_STATE(): BSet<DOOR_STATE> {
        return LandingGear_R6._DOOR_STATE;
    }

    _get__GEAR_STATE(): BSet<GEAR_STATE> {
        return LandingGear_R6._GEAR_STATE;
    }

    _get__HANDLE_STATE(): BSet<HANDLE_STATE> {
        return LandingGear_R6._HANDLE_STATE;
    }

    _get__POSITION(): BSet<POSITION> {
        return LandingGear_R6._POSITION;
    }

    _get__SWITCH_STATE(): BSet<SWITCH_STATE> {
        return LandingGear_R6._SWITCH_STATE;
    }

    _get__PLANE_STATE(): BSet<PLANE_STATE> {
        return LandingGear_R6._PLANE_STATE;
    }

    _get__VALVE_STATE(): BSet<VALVE_STATE> {
        return LandingGear_R6._VALVE_STATE;
    }

    _tr_begin_flying(): boolean {
        return this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue();
    }

    _tr_land_plane(): boolean {
        return this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.flight)).booleanValue();
    }

    _tr_open_valve_door_open(): boolean {
        return new BBoolean(this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_closed)).booleanValue() && this.open_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_close_valve_door_open(): boolean {
        return new BBoolean(this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _tr_open_valve_door_close(): boolean {
        return new BBoolean(this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_closed)).booleanValue() && this.close_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_close_valve_door_close(): boolean {
        return new BBoolean(this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() && this.close_EV.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _tr_open_valve_retract_gear(): boolean {
        return new BBoolean(this.valve_retract_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_closed)).booleanValue() && this.retract_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_close_valve_retract_gear(): boolean {
        return new BBoolean(this.valve_retract_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _tr_open_valve_extend_gear(): boolean {
        return new BBoolean(this.valve_extend_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_closed)).booleanValue() && this.extend_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_close_valve_extend_gear(): boolean {
        return new BBoolean(this.valve_extend_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _tr_con_stimulate_open_door_valve(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(this.open_EV.equal(new BBoolean(false)).booleanValue() && this.close_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).not().booleanValue()).booleanValue() || new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).not().booleanValue()).booleanValue() && new BBoolean(this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).not().booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_con_stop_stimulate_open_door_valve(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.open_EV.equal(new BBoolean(true)).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_con_stimulate_close_door_valve(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.close_EV.equal(new BBoolean(false)).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).not().booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_con_stop_stimulate_close_door_valve(): boolean {
        return new BBoolean(new BBoolean(this.close_EV.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() || new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_con_stimulate_retract_gear_valve(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.retract_EV.equal(new BBoolean(false)).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(true)).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue()).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).not().booleanValue()).booleanValue() && this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.flight)).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_con_stop_stimulate_retract_gear_valve(): boolean {
        return new BBoolean(new BBoolean(this.retract_EV.equal(new BBoolean(true)).booleanValue() && new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_con_stimulate_extend_gear_valve(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.extend_EV.equal(new BBoolean(false)).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(true)).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue()).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).not().booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_con_stop_stimulate_extend_gear_valve(): boolean {
        return new BBoolean(new BBoolean(this.extend_EV.equal(new BBoolean(true)).booleanValue() && new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_env_start_retracting_first(): BSet<POSITION> {
        let _ic_set_18: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue()).booleanValue() && this.gears.functionCall(_ic_gr_1).equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue() && this.valve_retract_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BSet(new GEAR_STATE(enum_GEAR_STATE.extended), new GEAR_STATE(enum_GEAR_STATE.gear_moving)).elementOf(this.gear).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue()) {
                _ic_set_18 = _ic_set_18.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_18;
    }

    _tr_env_retract_gear_skip(): BSet<POSITION> {
        let _ic_set_19: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.gears.relationImage(LandingGear_R6._POSITION.difference(new BSet(_ic_gr_1))).unequal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue()).booleanValue() && this.gears.functionCall(_ic_gr_1).equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
                _ic_set_19 = _ic_set_19.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_19;
    }

    _tr_env_retract_gear_last(): BSet<POSITION> {
        let _ic_set_20: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.gears.relationImage(LandingGear_R6._POSITION.difference(new BSet(_ic_gr_1))).equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue()).booleanValue() && this.gears.functionCall(_ic_gr_1).equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue()) {
                _ic_set_20 = _ic_set_20.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_20;
    }

    _tr_env_start_extending(): BSet<POSITION> {
        let _ic_set_21: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue()).booleanValue() && this.gears.functionCall(_ic_gr_1).equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue()).booleanValue() && this.valve_extend_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BSet(new GEAR_STATE(enum_GEAR_STATE.gear_moving), new GEAR_STATE(enum_GEAR_STATE.retracted)).elementOf(this.gear).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue()) {
                _ic_set_21 = _ic_set_21.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_21;
    }

    _tr_env_extend_gear_last(): BSet<POSITION> {
        let _ic_set_22: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue()).booleanValue() && this.gears.relationImage(LandingGear_R6._POSITION.difference(new BSet(_ic_gr_1))).equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.gears.functionCall(_ic_gr_1).equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue()) {
                _ic_set_22 = _ic_set_22.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_22;
    }

    _tr_env_extend_gear_skip(): BSet<POSITION> {
        let _ic_set_23: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue()).booleanValue() && this.gears.relationImage(LandingGear_R6._POSITION.difference(new BSet(_ic_gr_1))).unequal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.gears.functionCall(_ic_gr_1).equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
                _ic_set_23 = _ic_set_23.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_23;
    }

    _tr_env_start_open_door(): BSet<POSITION> {
        let _ic_set_24: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.closed)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BSet(new DOOR_STATE(enum_DOOR_STATE.closed), new DOOR_STATE(enum_DOOR_STATE.door_moving)).elementOf(this.door).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
                _ic_set_24 = _ic_set_24.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_24;
    }

    _tr_env_open_door_last(): BSet<POSITION> {
        let _ic_set_25: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet(_ic_gr_1))).equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
                _ic_set_25 = _ic_set_25.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_25;
    }

    _tr_env_open_door_skip(): BSet<POSITION> {
        let _ic_set_26: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet(_ic_gr_1))).unequal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
                _ic_set_26 = _ic_set_26.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_26;
    }

    _tr_env_start_close_door(): BSet<POSITION> {
        let _ic_set_27: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BSet(new DOOR_STATE(enum_DOOR_STATE.door_moving), new DOOR_STATE(enum_DOOR_STATE.open)).elementOf(this.door).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BSet(new GEAR_STATE(enum_GEAR_STATE.extended), new GEAR_STATE(enum_GEAR_STATE.retracted)).elementOf(this.gear).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
                _ic_set_27 = _ic_set_27.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_27;
    }

    _tr_env_close_door(): BSet<POSITION> {
        let _ic_set_28: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet(_ic_gr_1))).equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BSet(new GEAR_STATE(enum_GEAR_STATE.extended), new GEAR_STATE(enum_GEAR_STATE.retracted)).elementOf(this.gear).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
                _ic_set_28 = _ic_set_28.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_28;
    }

    _tr_env_close_door_skip(): BSet<POSITION> {
        let _ic_set_29: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet(_ic_gr_1))).unequal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
                _ic_set_29 = _ic_set_29.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_29;
    }

    _tr_toggle_handle_up(): boolean {
        return this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue();
    }

    _tr_toggle_handle_down(): boolean {
        return this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue();
    }

    _tr_con_stimulate_general_valve(): boolean {
        return new BBoolean(this.general_EV.equal(new BBoolean(false)).booleanValue() && this.handle_move.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_con_stop_stimulate_general_valve(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.general_EV.equal(new BBoolean(true)).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.close_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.close_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() || new BBoolean(new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() || new BBoolean(new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue()).booleanValue();
    }

    _tr_evn_open_general_valve(): boolean {
        return new BBoolean(new BBoolean(this.general_EV.equal(new BBoolean(true)).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_closed)).booleanValue()).booleanValue() && this.analogical_switch.equal(new SWITCH_STATE(enum_SWITCH_STATE.switch_closed)).booleanValue()).booleanValue();
    }

    _tr_evn_close_general_valve(): boolean {
        return new BBoolean(new BBoolean(this.general_EV.equal(new BBoolean(false)).booleanValue() || this.analogical_switch.equal(new SWITCH_STATE(enum_SWITCH_STATE.switch_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue();
    }

    _tr_env_close_analogical_switch(): boolean {
        return new BBoolean(this.analogical_switch.equal(new SWITCH_STATE(enum_SWITCH_STATE.switch_open)).booleanValue() && this.handle_move.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_env_open_analogical_switch(): boolean {
        return this.analogical_switch.equal(new SWITCH_STATE(enum_SWITCH_STATE.switch_closed)).booleanValue();
    }

    _check_inv_1() {
        return LandingGear_R6._SWITCH_STATE.elementOf(this.analogical_switch).booleanValue();
    }_check_inv_2() {
        return BUtils.BOOL.elementOf(this.general_EV).booleanValue();
    }_check_inv_3() {
        return LandingGear_R6._VALVE_STATE.elementOf(this.general_valve).booleanValue();
    }_check_inv_4() {
        return BUtils.BOOL.elementOf(this.handle_move).booleanValue();
    }_check_inv_5() {
        return BUtils.BOOL.elementOf(this.close_EV).booleanValue();
    }_check_inv_6() {
        return BUtils.BOOL.elementOf(this.extend_EV).booleanValue();
    }_check_inv_7() {
        return BUtils.BOOL.elementOf(this.open_EV).booleanValue();
    }_check_inv_8() {
        return BUtils.BOOL.elementOf(this.retract_EV).booleanValue();
    }_check_inv_9() {
        return LandingGear_R6._PLANE_STATE.elementOf(this.shock_absorber).booleanValue();
    }_check_inv_10() {
        return LandingGear_R6._VALVE_STATE.elementOf(this.valve_close_door).booleanValue();
    }_check_inv_11() {
        return LandingGear_R6._VALVE_STATE.elementOf(this.valve_extend_gear).booleanValue();
    }_check_inv_12() {
        return LandingGear_R6._VALVE_STATE.elementOf(this.valve_open_door).booleanValue();
    }_check_inv_13() {
        return LandingGear_R6._VALVE_STATE.elementOf(this.valve_retract_gear).booleanValue();
    }_check_inv_14() {
        return LandingGear_R6._HANDLE_STATE.elementOf(this.handle).booleanValue();
    }_check_inv_15() {
        return LandingGear_R6._DOOR_STATE.elementOf(this.door).booleanValue();
    }_check_inv_16() {
        return LandingGear_R6._GEAR_STATE.elementOf(this.gear).booleanValue();
    }_check_inv_17() {
        return new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.open_EV.equal(new BBoolean(true)).booleanValue() || this.close_EV.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.retract_EV.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.extend_EV.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }_check_inv_18() {
        return new BBoolean(this.open_EV.equal(new BBoolean(true)).booleanValue() && this.close_EV.equal(new BBoolean(true)).booleanValue()).not().booleanValue();
    }_check_inv_19() {
        return this.gears.checkDomain(LandingGear_R6._POSITION).and(this.gears.checkRange(LandingGear_R6._GEAR_STATE)).and(this.gears.isFunction()).and(this.gears.isTotal(LandingGear_R6._POSITION)).booleanValue();
    }_check_inv_20() {
        return this.doors.checkDomain(LandingGear_R6._POSITION).and(this.doors.checkRange(LandingGear_R6._DOOR_STATE)).and(this.doors.isFunction()).and(this.doors.isTotal(LandingGear_R6._POSITION)).booleanValue();
    }_check_inv_21() {
        return new BBoolean((!this.door.equal(new DOOR_STATE(enum_DOOR_STATE.closed)).booleanValue() || this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()) && (!this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue() || this.door.equal(new DOOR_STATE(enum_DOOR_STATE.closed)).booleanValue())).booleanValue();
    }_check_inv_22() {
        return new BBoolean((!this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue() || this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()) && (!this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() || this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue();
    }_check_inv_23() {
        return new BBoolean((!this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()) && (!this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue() || this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue())).booleanValue();
    }_check_inv_24() {
        return new BBoolean((!this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()) && (!this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue())).booleanValue();
    }_check_inv_25() {
        return new BBoolean(!this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue() || this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue()).booleanValue();
    }


}

