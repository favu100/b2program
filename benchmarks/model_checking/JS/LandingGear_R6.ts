import {BTuple} from './btypes/BTuple.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BRelation} from './btypes/BRelation.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BUtils} from "./btypes/BUtils.js";
import * as immutable from "./immutable/dist/immutable.es.js";
import {LinkedList} from  "./modelchecking/LinkedList.js";


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
        return (31 * 1) ^ (this.value << 1);
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
        return (31 * 1) ^ (this.value << 1);
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
        return (31 * 1) ^ (this.value << 1);
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
        return (31 * 1) ^ (this.value << 1);
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
        return (31 * 1) ^ (this.value << 1);
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
        return (31 * 1) ^ (this.value << 1);
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
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_VALVE_STATE[this.value].toString();
    }

    static get_valve_open () {return new VALVE_STATE(enum_VALVE_STATE.valve_open);}
    static get_valve_closed () {return new VALVE_STATE(enum_VALVE_STATE.valve_closed);}


}


export enum Type {
    BFS,
    DFS,
    MIXED
}

export default class LandingGear_R6 {

    parent: LandingGear_R6;
    dependentGuard: immutable.Set<string> = immutable.Set();
    guardCache: immutable.Map = immutable.Map();
    dependentInvariant: immutable.Set<string> = immutable.Set();
    stateAccessedVia: string;



    private static _DOOR_STATE: BSet<DOOR_STATE> = new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.open), new DOOR_STATE(enum_DOOR_STATE.closed), new DOOR_STATE(enum_DOOR_STATE.door_moving));
    private static _GEAR_STATE: BSet<GEAR_STATE> = new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted), new GEAR_STATE(enum_GEAR_STATE.extended), new GEAR_STATE(enum_GEAR_STATE.gear_moving));
    private static _HANDLE_STATE: BSet<HANDLE_STATE> = new BSet<HANDLE_STATE>(new HANDLE_STATE(enum_HANDLE_STATE.up), new HANDLE_STATE(enum_HANDLE_STATE.down));
    private static _POSITION: BSet<POSITION> = new BSet<POSITION>(new POSITION(enum_POSITION.fr), new POSITION(enum_POSITION.lt), new POSITION(enum_POSITION.rt));
    private static _SWITCH_STATE: BSet<SWITCH_STATE> = new BSet<SWITCH_STATE>(new SWITCH_STATE(enum_SWITCH_STATE.switch_open), new SWITCH_STATE(enum_SWITCH_STATE.switch_closed));
    private static _PLANE_STATE: BSet<PLANE_STATE> = new BSet<PLANE_STATE>(new PLANE_STATE(enum_PLANE_STATE.ground), new PLANE_STATE(enum_PLANE_STATE.flight));
    private static _VALVE_STATE: BSet<VALVE_STATE> = new BSet<VALVE_STATE>(new VALVE_STATE(enum_VALVE_STATE.valve_open), new VALVE_STATE(enum_VALVE_STATE.valve_closed));

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

    constructor(copy? : LandingGear_R6) {
        if(copy) {
            this.analogical_switch = copy.analogical_switch;
            this.general_EV = copy.general_EV;
            this.general_valve = copy.general_valve;
            this.handle_move = copy.handle_move;
            this.close_EV = copy.close_EV;
            this.extend_EV = copy.extend_EV;
            this.open_EV = copy.open_EV;
            this.retract_EV = copy.retract_EV;
            this.shock_absorber = copy.shock_absorber;
            this.valve_close_door = copy.valve_close_door;
            this.valve_extend_gear = copy.valve_extend_gear;
            this.valve_open_door = copy.valve_open_door;
            this.valve_retract_gear = copy.valve_retract_gear;
            this.doors = copy.doors;
            this.gears = copy.gears;
            this.handle = copy.handle;
            this.door = copy.door;
            this.gear = copy.gear;
        } else {
            this.gears = BRelation.cartesianProduct(LandingGear_R6._POSITION, new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended)));
            this.doors = BRelation.cartesianProduct(LandingGear_R6._POSITION, new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.closed)));
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
    }


     begin_flying(): void {
        this.shock_absorber = new PLANE_STATE(enum_PLANE_STATE.flight);

    }

     land_plane(): void {
        this.shock_absorber = new PLANE_STATE(enum_PLANE_STATE.ground);

    }

     open_valve_door_open(): void {
        this.valve_open_door = new VALVE_STATE(enum_VALVE_STATE.valve_open);

    }

     close_valve_door_open(): void {
        this.valve_open_door = new VALVE_STATE(enum_VALVE_STATE.valve_closed);

    }

     open_valve_door_close(): void {
        this.valve_close_door = new VALVE_STATE(enum_VALVE_STATE.valve_open);

    }

     close_valve_door_close(): void {
        this.valve_close_door = new VALVE_STATE(enum_VALVE_STATE.valve_closed);

    }

     open_valve_retract_gear(): void {
        this.valve_retract_gear = new VALVE_STATE(enum_VALVE_STATE.valve_open);

    }

     close_valve_retract_gear(): void {
        this.valve_retract_gear = new VALVE_STATE(enum_VALVE_STATE.valve_closed);

    }

     open_valve_extend_gear(): void {
        this.valve_extend_gear = new VALVE_STATE(enum_VALVE_STATE.valve_open);

    }

     close_valve_extend_gear(): void {
        this.valve_extend_gear = new VALVE_STATE(enum_VALVE_STATE.valve_closed);

    }

     con_stimulate_open_door_valve(): void {
        this.open_EV = new BBoolean(true);

    }

     con_stop_stimulate_open_door_valve(): void {
        this.open_EV = new BBoolean(false);

    }

     con_stimulate_close_door_valve(): void {
        this.close_EV = new BBoolean(true);

    }

     con_stop_stimulate_close_door_valve(): void {
        this.close_EV = new BBoolean(false);

    }

     con_stimulate_retract_gear_valve(): void {
        this.retract_EV = new BBoolean(true);

    }

     con_stop_stimulate_retract_gear_valve(): void {
        this.retract_EV = new BBoolean(false);

    }

     con_stimulate_extend_gear_valve(): void {
        this.extend_EV = new BBoolean(true);

    }

     con_stop_stimulate_extend_gear_valve(): void {
        this.extend_EV = new BBoolean(false);

    }

     env_start_retracting_first(gr: POSITION): void {
        let _ld_gears: BRelation<POSITION, GEAR_STATE> = this.gears;
        this.gears = _ld_gears.override(new BRelation<POSITION, GEAR_STATE>(new BTuple(gr, new GEAR_STATE(enum_GEAR_STATE.gear_moving))));
        this.gear = new GEAR_STATE(enum_GEAR_STATE.gear_moving);

    }

     env_retract_gear_skip(gr: POSITION): void {
        this.gears = this.gears.override(new BRelation<POSITION, GEAR_STATE>(new BTuple(gr, new GEAR_STATE(enum_GEAR_STATE.retracted))));

    }

     env_retract_gear_last(gr: POSITION): void {
        let _ld_gears: BRelation<POSITION, GEAR_STATE> = this.gears;
        this.gears = _ld_gears.override(new BRelation<POSITION, GEAR_STATE>(new BTuple(gr, new GEAR_STATE(enum_GEAR_STATE.retracted))));
        this.gear = new GEAR_STATE(enum_GEAR_STATE.retracted);

    }

     env_start_extending(gr: POSITION): void {
        let _ld_gears: BRelation<POSITION, GEAR_STATE> = this.gears;
        this.gears = _ld_gears.override(new BRelation<POSITION, GEAR_STATE>(new BTuple(gr, new GEAR_STATE(enum_GEAR_STATE.gear_moving))));
        this.gear = new GEAR_STATE(enum_GEAR_STATE.gear_moving);

    }

     env_extend_gear_last(gr: POSITION): void {
        let _ld_gears: BRelation<POSITION, GEAR_STATE> = this.gears;
        this.gears = _ld_gears.override(new BRelation<POSITION, GEAR_STATE>(new BTuple(gr, new GEAR_STATE(enum_GEAR_STATE.extended))));
        this.gear = new GEAR_STATE(enum_GEAR_STATE.extended);

    }

     env_extend_gear_skip(gr: POSITION): void {
        this.gears = this.gears.override(new BRelation<POSITION, GEAR_STATE>(new BTuple(gr, new GEAR_STATE(enum_GEAR_STATE.extended))));

    }

     env_start_open_door(gr: POSITION): void {
        let _ld_doors: BRelation<POSITION, DOOR_STATE> = this.doors;
        this.doors = _ld_doors.override(new BRelation<POSITION, DOOR_STATE>(new BTuple(gr, new DOOR_STATE(enum_DOOR_STATE.door_moving))));
        this.door = new DOOR_STATE(enum_DOOR_STATE.door_moving);

    }

     env_open_door_last(gr: POSITION): void {
        let _ld_doors: BRelation<POSITION, DOOR_STATE> = this.doors;
        this.doors = _ld_doors.override(new BRelation<POSITION, DOOR_STATE>(new BTuple(gr, new DOOR_STATE(enum_DOOR_STATE.open))));
        this.door = new DOOR_STATE(enum_DOOR_STATE.open);

    }

     env_open_door_skip(gr: POSITION): void {
        this.doors = this.doors.override(new BRelation<POSITION, DOOR_STATE>(new BTuple(gr, new DOOR_STATE(enum_DOOR_STATE.open))));

    }

     env_start_close_door(gr: POSITION): void {
        let _ld_doors: BRelation<POSITION, DOOR_STATE> = this.doors;
        this.doors = _ld_doors.override(new BRelation<POSITION, DOOR_STATE>(new BTuple(gr, new DOOR_STATE(enum_DOOR_STATE.door_moving))));
        this.door = new DOOR_STATE(enum_DOOR_STATE.door_moving);

    }

     env_close_door(gr: POSITION): void {
        let _ld_doors: BRelation<POSITION, DOOR_STATE> = this.doors;
        this.doors = _ld_doors.override(new BRelation<POSITION, DOOR_STATE>(new BTuple(gr, new DOOR_STATE(enum_DOOR_STATE.closed))));
        this.door = new DOOR_STATE(enum_DOOR_STATE.closed);

    }

     env_close_door_skip(gr: POSITION): void {
        this.doors = this.doors.override(new BRelation<POSITION, DOOR_STATE>(new BTuple(gr, new DOOR_STATE(enum_DOOR_STATE.closed))));

    }

     toggle_handle_up(): void {
        this.handle = new HANDLE_STATE(enum_HANDLE_STATE.up);
        this.handle_move = new BBoolean(true);

    }

     toggle_handle_down(): void {
        this.handle = new HANDLE_STATE(enum_HANDLE_STATE.down);
        this.handle_move = new BBoolean(true);

    }

     con_stimulate_general_valve(): void {
        this.general_EV = new BBoolean(true);

    }

     con_stop_stimulate_general_valve(): void {
        this.general_EV = new BBoolean(false);
        this.handle_move = new BBoolean(false);

    }

     evn_open_general_valve(): void {
        this.general_valve = new VALVE_STATE(enum_VALVE_STATE.valve_open);

    }

     evn_close_general_valve(): void {
        this.general_valve = new VALVE_STATE(enum_VALVE_STATE.valve_closed);

    }

     env_close_analogical_switch(): void {
        this.analogical_switch = new SWITCH_STATE(enum_SWITCH_STATE.switch_closed);

    }

     env_open_analogical_switch(): void {
        this.analogical_switch = new SWITCH_STATE(enum_SWITCH_STATE.switch_open);

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
        return new BBoolean(new BBoolean(new BBoolean(this.open_EV.equal(new BBoolean(false)).booleanValue() && this.close_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).not().booleanValue()).booleanValue() || new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).not().booleanValue()).booleanValue() && new BBoolean(this.doors.range().equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).not().booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_con_stop_stimulate_open_door_valve(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.open_EV.equal(new BBoolean(true)).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.doors.range().equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_con_stimulate_close_door_valve(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.close_EV.equal(new BBoolean(false)).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.doors.range().equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.closed))).not().booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_con_stop_stimulate_close_door_valve(): boolean {
        return new BBoolean(new BBoolean(this.close_EV.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.doors.range().equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() || new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.doors.range().equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_con_stimulate_retract_gear_valve(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.retract_EV.equal(new BBoolean(false)).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(true)).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue()).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).not().booleanValue()).booleanValue() && this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.flight)).booleanValue()).booleanValue() && this.doors.range().equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_con_stop_stimulate_retract_gear_valve(): boolean {
        return new BBoolean(new BBoolean(this.retract_EV.equal(new BBoolean(true)).booleanValue() && new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() || this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_con_stimulate_extend_gear_valve(): boolean {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.extend_EV.equal(new BBoolean(false)).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(true)).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue()).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).not().booleanValue()).booleanValue() && this.doors.range().equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_con_stop_stimulate_extend_gear_valve(): boolean {
        return new BBoolean(new BBoolean(this.extend_EV.equal(new BBoolean(true)).booleanValue() && new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() || this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_env_start_retracting_first(): BSet<POSITION> {
        let _ic_set_18: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.range().equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue()).booleanValue() && this.gears.functionCall(_ic_gr_1).equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue() && this.valve_retract_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended), new GEAR_STATE(enum_GEAR_STATE.gear_moving)).elementOf(this.gear).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue()) {
                _ic_set_18 = _ic_set_18.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_18;
    }

    _tr_env_retract_gear_skip(): BSet<POSITION> {
        let _ic_set_19: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.range().equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.gears.relationImage(LandingGear_R6._POSITION.difference(new BSet<POSITION>(_ic_gr_1))).unequal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue()).booleanValue() && this.gears.functionCall(_ic_gr_1).equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
                _ic_set_19 = _ic_set_19.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_19;
    }

    _tr_env_retract_gear_last(): BSet<POSITION> {
        let _ic_set_20: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.range().equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.gears.relationImage(LandingGear_R6._POSITION.difference(new BSet<POSITION>(_ic_gr_1))).equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue()).booleanValue() && this.gears.functionCall(_ic_gr_1).equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue()) {
                _ic_set_20 = _ic_set_20.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_20;
    }

    _tr_env_start_extending(): BSet<POSITION> {
        let _ic_set_21: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.range().equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue()).booleanValue() && this.gears.functionCall(_ic_gr_1).equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue()).booleanValue() && this.valve_extend_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.gear_moving), new GEAR_STATE(enum_GEAR_STATE.retracted)).elementOf(this.gear).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue()) {
                _ic_set_21 = _ic_set_21.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_21;
    }

    _tr_env_extend_gear_last(): BSet<POSITION> {
        let _ic_set_22: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.range().equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue()).booleanValue() && this.gears.relationImage(LandingGear_R6._POSITION.difference(new BSet<POSITION>(_ic_gr_1))).equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.gears.functionCall(_ic_gr_1).equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue()) {
                _ic_set_22 = _ic_set_22.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_22;
    }

    _tr_env_extend_gear_skip(): BSet<POSITION> {
        let _ic_set_23: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.range().equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue()).booleanValue() && this.gears.relationImage(LandingGear_R6._POSITION.difference(new BSet<POSITION>(_ic_gr_1))).unequal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.gears.functionCall(_ic_gr_1).equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
                _ic_set_23 = _ic_set_23.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_23;
    }

    _tr_env_start_open_door(): BSet<POSITION> {
        let _ic_set_24: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.closed)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.closed), new DOOR_STATE(enum_DOOR_STATE.door_moving)).elementOf(this.door).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
                _ic_set_24 = _ic_set_24.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_24;
    }

    _tr_env_open_door_last(): BSet<POSITION> {
        let _ic_set_25: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet<POSITION>(_ic_gr_1))).equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
                _ic_set_25 = _ic_set_25.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_25;
    }

    _tr_env_open_door_skip(): BSet<POSITION> {
        let _ic_set_26: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet<POSITION>(_ic_gr_1))).unequal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
                _ic_set_26 = _ic_set_26.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_26;
    }

    _tr_env_start_close_door(): BSet<POSITION> {
        let _ic_set_27: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.door_moving), new DOOR_STATE(enum_DOOR_STATE.open)).elementOf(this.door).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended), new GEAR_STATE(enum_GEAR_STATE.retracted)).elementOf(this.gear).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
                _ic_set_27 = _ic_set_27.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_27;
    }

    _tr_env_close_door(): BSet<POSITION> {
        let _ic_set_28: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet<POSITION>(_ic_gr_1))).equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended), new GEAR_STATE(enum_GEAR_STATE.retracted)).elementOf(this.gear).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
                _ic_set_28 = _ic_set_28.union(new BSet<POSITION>(_ic_gr_1));
            }

        }
        return _ic_set_28;
    }

    _tr_env_close_door_skip(): BSet<POSITION> {
        let _ic_set_29: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet<POSITION>(_ic_gr_1))).unequal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
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
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.general_EV.equal(new BBoolean(true)).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.close_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.close_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() && this.doors.range().equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() || new BBoolean(new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.doors.range().equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() || new BBoolean(new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.doors.range().equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue()).booleanValue();
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
    }

    _check_inv_2() {
        return BUtils.BOOL.elementOf(this.general_EV).booleanValue();
    }

    _check_inv_3() {
        return LandingGear_R6._VALVE_STATE.elementOf(this.general_valve).booleanValue();
    }

    _check_inv_4() {
        return BUtils.BOOL.elementOf(this.handle_move).booleanValue();
    }

    _check_inv_5() {
        return BUtils.BOOL.elementOf(this.close_EV).booleanValue();
    }

    _check_inv_6() {
        return BUtils.BOOL.elementOf(this.extend_EV).booleanValue();
    }

    _check_inv_7() {
        return BUtils.BOOL.elementOf(this.open_EV).booleanValue();
    }

    _check_inv_8() {
        return BUtils.BOOL.elementOf(this.retract_EV).booleanValue();
    }

    _check_inv_9() {
        return LandingGear_R6._PLANE_STATE.elementOf(this.shock_absorber).booleanValue();
    }

    _check_inv_10() {
        return LandingGear_R6._VALVE_STATE.elementOf(this.valve_close_door).booleanValue();
    }

    _check_inv_11() {
        return LandingGear_R6._VALVE_STATE.elementOf(this.valve_extend_gear).booleanValue();
    }

    _check_inv_12() {
        return LandingGear_R6._VALVE_STATE.elementOf(this.valve_open_door).booleanValue();
    }

    _check_inv_13() {
        return LandingGear_R6._VALVE_STATE.elementOf(this.valve_retract_gear).booleanValue();
    }

    _check_inv_14() {
        return LandingGear_R6._HANDLE_STATE.elementOf(this.handle).booleanValue();
    }

    _check_inv_15() {
        return LandingGear_R6._DOOR_STATE.elementOf(this.door).booleanValue();
    }

    _check_inv_16() {
        return LandingGear_R6._GEAR_STATE.elementOf(this.gear).booleanValue();
    }

    _check_inv_17() {
        return new BBoolean(!new BBoolean(new BBoolean(new BBoolean(this.open_EV.equal(new BBoolean(true)).booleanValue() || this.close_EV.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.retract_EV.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.extend_EV.equal(new BBoolean(true)).booleanValue()).booleanValue() || this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _check_inv_18() {
        return new BBoolean(this.open_EV.equal(new BBoolean(true)).booleanValue() && this.close_EV.equal(new BBoolean(true)).booleanValue()).not().booleanValue();
    }

    _check_inv_19() {
        return this.gears.checkDomain(LandingGear_R6._POSITION).and(this.gears.checkRange(LandingGear_R6._GEAR_STATE)).and(this.gears.isFunction()).and(this.gears.isTotal(LandingGear_R6._POSITION)).booleanValue();
    }

    _check_inv_20() {
        return this.doors.checkDomain(LandingGear_R6._POSITION).and(this.doors.checkRange(LandingGear_R6._DOOR_STATE)).and(this.doors.isFunction()).and(this.doors.isTotal(LandingGear_R6._POSITION)).booleanValue();
    }

    _check_inv_21() {
        return new BBoolean((!this.door.equal(new DOOR_STATE(enum_DOOR_STATE.closed)).booleanValue() || this.doors.range().equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()) && (!this.doors.range().equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue() || this.door.equal(new DOOR_STATE(enum_DOOR_STATE.closed)).booleanValue())).booleanValue();
    }

    _check_inv_22() {
        return new BBoolean((!this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue() || this.doors.range().equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()) && (!this.doors.range().equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() || this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue();
    }

    _check_inv_23() {
        return new BBoolean((!this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue() || this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()) && (!this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue() || this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue())).booleanValue();
    }

    _check_inv_24() {
        return new BBoolean((!this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue() || this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()) && (!this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue())).booleanValue();
    }

    _check_inv_25() {
        return new BBoolean(!this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue() || this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue()).booleanValue();
    }

    equals(o: any): boolean {
        let o1: LandingGear_R6 = this;
        let o2: LandingGear_R6 = o as LandingGear_R6;
        return o1._get_analogical_switch().equals(o2._get_analogical_switch()) && o1._get_general_EV().equals(o2._get_general_EV()) && o1._get_general_valve().equals(o2._get_general_valve()) && o1._get_handle_move().equals(o2._get_handle_move()) && o1._get_close_EV().equals(o2._get_close_EV()) && o1._get_extend_EV().equals(o2._get_extend_EV()) && o1._get_open_EV().equals(o2._get_open_EV()) && o1._get_retract_EV().equals(o2._get_retract_EV()) && o1._get_shock_absorber().equals(o2._get_shock_absorber()) && o1._get_valve_close_door().equals(o2._get_valve_close_door()) && o1._get_valve_extend_gear().equals(o2._get_valve_extend_gear()) && o1._get_valve_open_door().equals(o2._get_valve_open_door()) && o1._get_valve_retract_gear().equals(o2._get_valve_retract_gear()) && o1._get_doors().equals(o2._get_doors()) && o1._get_gears().equals(o2._get_gears()) && o1._get_handle().equals(o2._get_handle()) && o1._get_door().equals(o2._get_door()) && o1._get_gear().equals(o2._get_gear());
    }



    hashCode(): number {
        return this._hashCode_1();
    }

    _hashCode_1(): number {
        let result: number = 1;
        result = (1543 * result) ^ ((this._get_analogical_switch()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_general_EV()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_general_valve()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_handle_move()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_close_EV()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_extend_EV()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_open_EV()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_retract_EV()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_shock_absorber()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_valve_close_door()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_valve_extend_gear()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_valve_open_door()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_valve_retract_gear()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_doors()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_gears()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_handle()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_door()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_gear()).hashCode() << 1);
        return result;
    }

    _hashCode_2(): number {
        let result: number = 1;
        result = (6151 * result) ^ ((this._get_analogical_switch()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_general_EV()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_general_valve()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_handle_move()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_close_EV()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_extend_EV()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_open_EV()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_retract_EV()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_shock_absorber()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_valve_close_door()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_valve_extend_gear()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_valve_open_door()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_valve_retract_gear()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_doors()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_gears()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_handle()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_door()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_gear()).hashCode() << 1);
        return result;
    }

    /* TODO
    toString(): string {
        return String.join("\n", "_get_analogical_switch: " + (this._get_analogical_switch()).toString(), "_get_general_EV: " + (this._get_general_EV()).toString(), "_get_general_valve: " + (this._get_general_valve()).toString(), "_get_handle_move: " + (this._get_handle_move()).toString(), "_get_close_EV: " + (this._get_close_EV()).toString(), "_get_extend_EV: " + (this._get_extend_EV()).toString(), "_get_open_EV: " + (this._get_open_EV()).toString(), "_get_retract_EV: " + (this._get_retract_EV()).toString(), "_get_shock_absorber: " + (this._get_shock_absorber()).toString(), "_get_valve_close_door: " + (this._get_valve_close_door()).toString(), "_get_valve_extend_gear: " + (this._get_valve_extend_gear()).toString(), "_get_valve_open_door: " + (this._get_valve_open_door()).toString(), "_get_valve_retract_gear: " + (this._get_valve_retract_gear()).toString(), "_get_doors: " + (this._get_doors()).toString(), "_get_gears: " + (this._get_gears()).toString(), "_get_handle: " + (this._get_handle()).toString(), "_get_door: " + (this._get_door()).toString(), "_get_gear: " + (this._get_gear()).toString());
    }
    */


    public _copy(): LandingGear_R6 {
      return new LandingGear_R6(this);
    }


}


export class ModelChecker {
    private type: Type;
    private isCaching: boolean;
    private isDebug: boolean;

    private unvisitedStates: LinkedList<LandingGear_R6> = new LinkedList<LandingGear_R6>;
    private states: immutable.Set<LandingGear_R6> = new immutable.Set();
    private transitions: number = 0;

    private invariantViolated: boolean = false;
    private deadlockDetected: boolean = false;
    private counterExampleState: LandingGear_R6 = undefined;

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
        let machine: LandingGear_R6 = new LandingGear_R6();
        this.states = this.states.add(machine);
        this.unvisitedStates.pushBack(machine);

        if(this.isCaching) {
            this.initCache(machine);
        }

        while(!(this.unvisitedStates.length === 0)) {
            let state: LandingGear_R6 = this.next();

            let nextStates: Set<LandingGear_R6> = this.generateNextStates(state);

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

    initCache(machine: LandingGear_R6 ): void {
        this.invariantDependency = this.invariantDependency.set("close_valve_door_close", immutable.Set(["_check_inv_10"]));
        this.invariantDependency = this.invariantDependency.set("close_valve_retract_gear", immutable.Set(["_check_inv_13"]));
        this.invariantDependency = this.invariantDependency.set("con_stimulate_open_door_valve", immutable.Set(["_check_inv_18", "_check_inv_17", "_check_inv_7"]));
        this.invariantDependency = this.invariantDependency.set("env_close_door", immutable.Set(["_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22"]));
        this.invariantDependency = this.invariantDependency.set("env_start_close_door", immutable.Set(["_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22"]));
        this.invariantDependency = this.invariantDependency.set("toggle_handle_up", immutable.Set(["_check_inv_4", "_check_inv_14"]));
        this.invariantDependency = this.invariantDependency.set("toggle_handle_down", immutable.Set(["_check_inv_4", "_check_inv_14"]));
        this.invariantDependency = this.invariantDependency.set("open_valve_door_open", immutable.Set(["_check_inv_12"]));
        this.invariantDependency = this.invariantDependency.set("env_retract_gear_last", immutable.Set(["_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23"]));
        this.invariantDependency = this.invariantDependency.set("env_open_door_last", immutable.Set(["_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22"]));
        this.invariantDependency = this.invariantDependency.set("con_stop_stimulate_retract_gear_valve", immutable.Set(["_check_inv_17", "_check_inv_8"]));
        this.invariantDependency = this.invariantDependency.set("env_close_door_skip", immutable.Set(["_check_inv_21", "_check_inv_20", "_check_inv_22"]));
        this.invariantDependency = this.invariantDependency.set("con_stop_stimulate_close_door_valve", immutable.Set(["_check_inv_18", "_check_inv_17", "_check_inv_5"]));
        this.invariantDependency = this.invariantDependency.set("env_open_analogical_switch", immutable.Set(["_check_inv_1"]));
        this.invariantDependency = this.invariantDependency.set("con_stop_stimulate_general_valve", immutable.Set(["_check_inv_17", "_check_inv_2", "_check_inv_4"]));
        this.invariantDependency = this.invariantDependency.set("env_extend_gear_last", immutable.Set(["_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23"]));
        this.invariantDependency = this.invariantDependency.set("evn_open_general_valve", immutable.Set(["_check_inv_3"]));
        this.invariantDependency = this.invariantDependency.set("land_plane", immutable.Set(["_check_inv_9"]));
        this.invariantDependency = this.invariantDependency.set("con_stimulate_retract_gear_valve", immutable.Set(["_check_inv_17", "_check_inv_8"]));
        this.invariantDependency = this.invariantDependency.set("con_stimulate_general_valve", immutable.Set(["_check_inv_17", "_check_inv_2"]));
        this.invariantDependency = this.invariantDependency.set("env_start_retracting_first", immutable.Set(["_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23"]));
        this.invariantDependency = this.invariantDependency.set("env_retract_gear_skip", immutable.Set(["_check_inv_19", "_check_inv_24", "_check_inv_23"]));
        this.invariantDependency = this.invariantDependency.set("open_valve_extend_gear", immutable.Set(["_check_inv_11"]));
        this.invariantDependency = this.invariantDependency.set("begin_flying", immutable.Set(["_check_inv_9"]));
        this.invariantDependency = this.invariantDependency.set("open_valve_retract_gear", immutable.Set(["_check_inv_13"]));
        this.invariantDependency = this.invariantDependency.set("env_close_analogical_switch", immutable.Set(["_check_inv_1"]));
        this.invariantDependency = this.invariantDependency.set("env_start_extending", immutable.Set(["_check_inv_16", "_check_inv_19", "_check_inv_25", "_check_inv_24", "_check_inv_23"]));
        this.invariantDependency = this.invariantDependency.set("open_valve_door_close", immutable.Set(["_check_inv_10"]));
        this.invariantDependency = this.invariantDependency.set("con_stop_stimulate_open_door_valve", immutable.Set(["_check_inv_18", "_check_inv_17", "_check_inv_7"]));
        this.invariantDependency = this.invariantDependency.set("con_stop_stimulate_extend_gear_valve", immutable.Set(["_check_inv_17", "_check_inv_6"]));
        this.invariantDependency = this.invariantDependency.set("evn_close_general_valve", immutable.Set(["_check_inv_3"]));
        this.invariantDependency = this.invariantDependency.set("close_valve_extend_gear", immutable.Set(["_check_inv_11"]));
        this.invariantDependency = this.invariantDependency.set("con_stimulate_extend_gear_valve", immutable.Set(["_check_inv_17", "_check_inv_6"]));
        this.invariantDependency = this.invariantDependency.set("close_valve_door_open", immutable.Set(["_check_inv_12"]));
        this.invariantDependency = this.invariantDependency.set("con_stimulate_close_door_valve", immutable.Set(["_check_inv_18", "_check_inv_17", "_check_inv_5"]));
        this.invariantDependency = this.invariantDependency.set("env_extend_gear_skip", immutable.Set(["_check_inv_19", "_check_inv_24", "_check_inv_23"]));
        this.invariantDependency = this.invariantDependency.set("env_open_door_skip", immutable.Set(["_check_inv_21", "_check_inv_20", "_check_inv_22"]));
        this.invariantDependency = this.invariantDependency.set("env_start_open_door", immutable.Set(["_check_inv_15", "_check_inv_21", "_check_inv_20", "_check_inv_25", "_check_inv_22"]));
        this.guardDependency = this.guardDependency.set("close_valve_door_close", immutable.Set(["_tr_open_valve_door_close", "_tr_env_close_door_skip", "_tr_env_start_close_door", "_tr_env_close_door", "_tr_close_valve_door_close"]));
        this.guardDependency = this.guardDependency.set("close_valve_retract_gear", immutable.Set(["_tr_close_valve_retract_gear", "_tr_open_valve_retract_gear", "_tr_env_start_retracting_first"]));
        this.guardDependency = this.guardDependency.set("con_stimulate_open_door_valve", immutable.Set(["_tr_open_valve_door_open", "_tr_con_stimulate_extend_gear_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_open"]));
        this.guardDependency = this.guardDependency.set("env_close_door", immutable.Set(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
        this.guardDependency = this.guardDependency.set("env_start_close_door", immutable.Set(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
        this.guardDependency = this.guardDependency.set("toggle_handle_up", immutable.Set(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_close_analogical_switch", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip", "_tr_con_stimulate_general_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_toggle_handle_down", "_tr_env_open_door_last", "_tr_toggle_handle_up", "_tr_env_start_close_door", "_tr_con_stop_stimulate_close_door_valve"]));
        this.guardDependency = this.guardDependency.set("toggle_handle_down", immutable.Set(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_close_analogical_switch", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip", "_tr_con_stimulate_general_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_toggle_handle_down", "_tr_env_open_door_last", "_tr_toggle_handle_up", "_tr_env_start_close_door", "_tr_con_stop_stimulate_close_door_valve"]));
        this.guardDependency = this.guardDependency.set("open_valve_door_open", immutable.Set(["_tr_open_valve_door_open", "_tr_env_open_door_last", "_tr_env_start_open_door", "_tr_env_open_door_skip", "_tr_close_valve_door_open"]));
        this.guardDependency = this.guardDependency.set("env_retract_gear_last", immutable.Set(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
        this.guardDependency = this.guardDependency.set("env_open_door_last", immutable.Set(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
        this.guardDependency = this.guardDependency.set("con_stop_stimulate_retract_gear_valve", immutable.Set(["_tr_close_valve_retract_gear", "_tr_con_stimulate_extend_gear_valve", "_tr_open_valve_retract_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_retract_gear_valve"]));
        this.guardDependency = this.guardDependency.set("env_close_door_skip", immutable.Set(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
        this.guardDependency = this.guardDependency.set("con_stop_stimulate_close_door_valve", immutable.Set(["_tr_open_valve_door_close", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_close"]));
        this.guardDependency = this.guardDependency.set("env_open_analogical_switch", immutable.Set(["_tr_env_open_analogical_switch", "_tr_evn_open_general_valve", "_tr_env_close_analogical_switch", "_tr_evn_close_general_valve"]));
        this.guardDependency = this.guardDependency.set("con_stop_stimulate_general_valve", immutable.Set(["_tr_con_stimulate_extend_gear_valve", "_tr_con_stimulate_general_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_evn_open_general_valve", "_tr_env_close_analogical_switch", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_evn_close_general_valve", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve"]));
        this.guardDependency = this.guardDependency.set("env_extend_gear_last", immutable.Set(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
        this.guardDependency = this.guardDependency.set("evn_open_general_valve", immutable.Set(["_tr_env_retract_gear_last", "_tr_env_close_door_skip", "_tr_evn_open_general_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_evn_close_general_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
        this.guardDependency = this.guardDependency.set("land_plane", immutable.Set(["_tr_land_plane", "_tr_begin_flying", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_close_door"]));
        this.guardDependency = this.guardDependency.set("con_stimulate_retract_gear_valve", immutable.Set(["_tr_close_valve_retract_gear", "_tr_con_stimulate_extend_gear_valve", "_tr_open_valve_retract_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_retract_gear_valve"]));
        this.guardDependency = this.guardDependency.set("con_stimulate_general_valve", immutable.Set(["_tr_con_stimulate_extend_gear_valve", "_tr_con_stimulate_general_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_evn_open_general_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_evn_close_general_valve", "_tr_con_stop_stimulate_retract_gear_valve"]));
        this.guardDependency = this.guardDependency.set("env_start_retracting_first", immutable.Set(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
        this.guardDependency = this.guardDependency.set("env_retract_gear_skip", immutable.Set(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
        this.guardDependency = this.guardDependency.set("open_valve_extend_gear", immutable.Set(["_tr_close_valve_extend_gear", "_tr_open_valve_extend_gear", "_tr_env_start_extending"]));
        this.guardDependency = this.guardDependency.set("begin_flying", immutable.Set(["_tr_land_plane", "_tr_begin_flying", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_close_door"]));
        this.guardDependency = this.guardDependency.set("open_valve_retract_gear", immutable.Set(["_tr_close_valve_retract_gear", "_tr_open_valve_retract_gear", "_tr_env_start_retracting_first"]));
        this.guardDependency = this.guardDependency.set("env_close_analogical_switch", immutable.Set(["_tr_env_open_analogical_switch", "_tr_evn_open_general_valve", "_tr_env_close_analogical_switch", "_tr_evn_close_general_valve"]));
        this.guardDependency = this.guardDependency.set("env_start_extending", immutable.Set(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
        this.guardDependency = this.guardDependency.set("open_valve_door_close", immutable.Set(["_tr_open_valve_door_close", "_tr_env_close_door_skip", "_tr_env_start_close_door", "_tr_env_close_door", "_tr_close_valve_door_close"]));
        this.guardDependency = this.guardDependency.set("con_stop_stimulate_open_door_valve", immutable.Set(["_tr_open_valve_door_open", "_tr_con_stimulate_extend_gear_valve", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_open"]));
        this.guardDependency = this.guardDependency.set("con_stop_stimulate_extend_gear_valve", immutable.Set(["_tr_con_stimulate_extend_gear_valve", "_tr_close_valve_extend_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_open_valve_extend_gear", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_extend_gear_valve"]));
        this.guardDependency = this.guardDependency.set("evn_close_general_valve", immutable.Set(["_tr_env_retract_gear_last", "_tr_env_close_door_skip", "_tr_evn_open_general_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_evn_close_general_valve", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
        this.guardDependency = this.guardDependency.set("close_valve_extend_gear", immutable.Set(["_tr_close_valve_extend_gear", "_tr_open_valve_extend_gear", "_tr_env_start_extending"]));
        this.guardDependency = this.guardDependency.set("con_stimulate_extend_gear_valve", immutable.Set(["_tr_con_stimulate_extend_gear_valve", "_tr_close_valve_extend_gear", "_tr_con_stop_stimulate_open_door_valve", "_tr_open_valve_extend_gear", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_extend_gear_valve"]));
        this.guardDependency = this.guardDependency.set("close_valve_door_open", immutable.Set(["_tr_open_valve_door_open", "_tr_env_open_door_last", "_tr_env_start_open_door", "_tr_env_open_door_skip", "_tr_close_valve_door_open"]));
        this.guardDependency = this.guardDependency.set("con_stimulate_close_door_valve", immutable.Set(["_tr_open_valve_door_close", "_tr_con_stimulate_close_door_valve", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_close_valve_door_close"]));
        this.guardDependency = this.guardDependency.set("env_extend_gear_skip", immutable.Set(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_con_stop_stimulate_extend_gear_valve", "_tr_env_start_retracting_first", "_tr_con_stop_stimulate_retract_gear_valve", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
        this.guardDependency = this.guardDependency.set("env_open_door_skip", immutable.Set(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
        this.guardDependency = this.guardDependency.set("env_start_open_door", immutable.Set(["_tr_env_retract_gear_last", "_tr_con_stimulate_extend_gear_valve", "_tr_env_close_door_skip", "_tr_con_stop_stimulate_open_door_valve", "_tr_con_stimulate_retract_gear_valve", "_tr_con_stimulate_close_door_valve", "_tr_env_retract_gear_skip", "_tr_env_start_open_door", "_tr_env_close_door", "_tr_env_start_retracting_first", "_tr_env_extend_gear_skip", "_tr_env_open_door_last", "_tr_env_start_close_door", "_tr_con_stop_stimulate_general_valve", "_tr_con_stop_stimulate_close_door_valve", "_tr_con_stimulate_open_door_valve", "_tr_env_start_extending", "_tr_env_extend_gear_last", "_tr_env_open_door_skip"]));
    }

    next(): LandingGear_R6 {
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

    generateNextStates(state: LandingGear_R6): Set<LandingGear_R6> {
        let result: immutable.Set<LandingGear_R6> = immutable.Set();
        if(this.isCaching) {
            let parentsGuard: immutable.Map = state.guardCache;
            let newCache: immutable.Map = parentsGuard == null ? immutable.Map() : parentsGuard;
            let cachedValue: any = null;
            let dependentGuardsBoolean: boolean = true;
            let _trid_1: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_begin_flying");
                dependentGuardsBoolean = "_tr_begin_flying" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_1 = state._tr_begin_flying();
            } else {
                _trid_1 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_begin_flying", _trid_1);
            if(_trid_1) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.begin_flying();
                copiedState.parent = state;
                this.addCachedInfos("begin_flying", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_2: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_land_plane");
                dependentGuardsBoolean = "_tr_land_plane" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_2 = state._tr_land_plane();
            } else {
                _trid_2 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_land_plane", _trid_2);
            if(_trid_2) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.land_plane();
                copiedState.parent = state;
                this.addCachedInfos("land_plane", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_3: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_open_valve_door_open");
                dependentGuardsBoolean = "_tr_open_valve_door_open" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_3 = state._tr_open_valve_door_open();
            } else {
                _trid_3 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_open_valve_door_open", _trid_3);
            if(_trid_3) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.open_valve_door_open();
                copiedState.parent = state;
                this.addCachedInfos("open_valve_door_open", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_4: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_close_valve_door_open");
                dependentGuardsBoolean = "_tr_close_valve_door_open" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_4 = state._tr_close_valve_door_open();
            } else {
                _trid_4 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_close_valve_door_open", _trid_4);
            if(_trid_4) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.close_valve_door_open();
                copiedState.parent = state;
                this.addCachedInfos("close_valve_door_open", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_5: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_open_valve_door_close");
                dependentGuardsBoolean = "_tr_open_valve_door_close" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_5 = state._tr_open_valve_door_close();
            } else {
                _trid_5 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_open_valve_door_close", _trid_5);
            if(_trid_5) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.open_valve_door_close();
                copiedState.parent = state;
                this.addCachedInfos("open_valve_door_close", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_6: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_close_valve_door_close");
                dependentGuardsBoolean = "_tr_close_valve_door_close" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_6 = state._tr_close_valve_door_close();
            } else {
                _trid_6 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_close_valve_door_close", _trid_6);
            if(_trid_6) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.close_valve_door_close();
                copiedState.parent = state;
                this.addCachedInfos("close_valve_door_close", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_7: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_open_valve_retract_gear");
                dependentGuardsBoolean = "_tr_open_valve_retract_gear" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_7 = state._tr_open_valve_retract_gear();
            } else {
                _trid_7 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_open_valve_retract_gear", _trid_7);
            if(_trid_7) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.open_valve_retract_gear();
                copiedState.parent = state;
                this.addCachedInfos("open_valve_retract_gear", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_8: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_close_valve_retract_gear");
                dependentGuardsBoolean = "_tr_close_valve_retract_gear" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_8 = state._tr_close_valve_retract_gear();
            } else {
                _trid_8 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_close_valve_retract_gear", _trid_8);
            if(_trid_8) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.close_valve_retract_gear();
                copiedState.parent = state;
                this.addCachedInfos("close_valve_retract_gear", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_9: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_open_valve_extend_gear");
                dependentGuardsBoolean = "_tr_open_valve_extend_gear" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_9 = state._tr_open_valve_extend_gear();
            } else {
                _trid_9 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_open_valve_extend_gear", _trid_9);
            if(_trid_9) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.open_valve_extend_gear();
                copiedState.parent = state;
                this.addCachedInfos("open_valve_extend_gear", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_10: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_close_valve_extend_gear");
                dependentGuardsBoolean = "_tr_close_valve_extend_gear" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_10 = state._tr_close_valve_extend_gear();
            } else {
                _trid_10 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_close_valve_extend_gear", _trid_10);
            if(_trid_10) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.close_valve_extend_gear();
                copiedState.parent = state;
                this.addCachedInfos("close_valve_extend_gear", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_11: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_con_stimulate_open_door_valve");
                dependentGuardsBoolean = "_tr_con_stimulate_open_door_valve" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_11 = state._tr_con_stimulate_open_door_valve();
            } else {
                _trid_11 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_con_stimulate_open_door_valve", _trid_11);
            if(_trid_11) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stimulate_open_door_valve();
                copiedState.parent = state;
                this.addCachedInfos("con_stimulate_open_door_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_12: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_con_stop_stimulate_open_door_valve");
                dependentGuardsBoolean = "_tr_con_stop_stimulate_open_door_valve" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_12 = state._tr_con_stop_stimulate_open_door_valve();
            } else {
                _trid_12 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_con_stop_stimulate_open_door_valve", _trid_12);
            if(_trid_12) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stop_stimulate_open_door_valve();
                copiedState.parent = state;
                this.addCachedInfos("con_stop_stimulate_open_door_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_13: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_con_stimulate_close_door_valve");
                dependentGuardsBoolean = "_tr_con_stimulate_close_door_valve" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_13 = state._tr_con_stimulate_close_door_valve();
            } else {
                _trid_13 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_con_stimulate_close_door_valve", _trid_13);
            if(_trid_13) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stimulate_close_door_valve();
                copiedState.parent = state;
                this.addCachedInfos("con_stimulate_close_door_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_14: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_con_stop_stimulate_close_door_valve");
                dependentGuardsBoolean = "_tr_con_stop_stimulate_close_door_valve" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_14 = state._tr_con_stop_stimulate_close_door_valve();
            } else {
                _trid_14 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_con_stop_stimulate_close_door_valve", _trid_14);
            if(_trid_14) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stop_stimulate_close_door_valve();
                copiedState.parent = state;
                this.addCachedInfos("con_stop_stimulate_close_door_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_15: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_con_stimulate_retract_gear_valve");
                dependentGuardsBoolean = "_tr_con_stimulate_retract_gear_valve" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_15 = state._tr_con_stimulate_retract_gear_valve();
            } else {
                _trid_15 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_con_stimulate_retract_gear_valve", _trid_15);
            if(_trid_15) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stimulate_retract_gear_valve();
                copiedState.parent = state;
                this.addCachedInfos("con_stimulate_retract_gear_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_16: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_con_stop_stimulate_retract_gear_valve");
                dependentGuardsBoolean = "_tr_con_stop_stimulate_retract_gear_valve" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_16 = state._tr_con_stop_stimulate_retract_gear_valve();
            } else {
                _trid_16 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_con_stop_stimulate_retract_gear_valve", _trid_16);
            if(_trid_16) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stop_stimulate_retract_gear_valve();
                copiedState.parent = state;
                this.addCachedInfos("con_stop_stimulate_retract_gear_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_17: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_con_stimulate_extend_gear_valve");
                dependentGuardsBoolean = "_tr_con_stimulate_extend_gear_valve" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_17 = state._tr_con_stimulate_extend_gear_valve();
            } else {
                _trid_17 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_con_stimulate_extend_gear_valve", _trid_17);
            if(_trid_17) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stimulate_extend_gear_valve();
                copiedState.parent = state;
                this.addCachedInfos("con_stimulate_extend_gear_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_18: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_con_stop_stimulate_extend_gear_valve");
                dependentGuardsBoolean = "_tr_con_stop_stimulate_extend_gear_valve" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_18 = state._tr_con_stop_stimulate_extend_gear_valve();
            } else {
                _trid_18 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_con_stop_stimulate_extend_gear_valve", _trid_18);
            if(_trid_18) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stop_stimulate_extend_gear_valve();
                copiedState.parent = state;
                this.addCachedInfos("con_stop_stimulate_extend_gear_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_19: BSet<POSITION>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_env_start_retracting_first");
                dependentGuardsBoolean = "_tr_env_start_retracting_first" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_19 = state._tr_env_start_retracting_first();
            } else {
                _trid_19 = cachedValue as BSet<POSITION>;
            }
            newCache = newCache.set("_tr_env_start_retracting_first", _trid_19);
            for(let param of _trid_19) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_start_retracting_first(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_start_retracting_first", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_20: BSet<POSITION>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_env_retract_gear_skip");
                dependentGuardsBoolean = "_tr_env_retract_gear_skip" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_20 = state._tr_env_retract_gear_skip();
            } else {
                _trid_20 = cachedValue as BSet<POSITION>;
            }
            newCache = newCache.set("_tr_env_retract_gear_skip", _trid_20);
            for(let param of _trid_20) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_retract_gear_skip(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_retract_gear_skip", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_21: BSet<POSITION>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_env_retract_gear_last");
                dependentGuardsBoolean = "_tr_env_retract_gear_last" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_21 = state._tr_env_retract_gear_last();
            } else {
                _trid_21 = cachedValue as BSet<POSITION>;
            }
            newCache = newCache.set("_tr_env_retract_gear_last", _trid_21);
            for(let param of _trid_21) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_retract_gear_last(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_retract_gear_last", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_22: BSet<POSITION>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_env_start_extending");
                dependentGuardsBoolean = "_tr_env_start_extending" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_22 = state._tr_env_start_extending();
            } else {
                _trid_22 = cachedValue as BSet<POSITION>;
            }
            newCache = newCache.set("_tr_env_start_extending", _trid_22);
            for(let param of _trid_22) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_start_extending(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_start_extending", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_23: BSet<POSITION>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_env_extend_gear_last");
                dependentGuardsBoolean = "_tr_env_extend_gear_last" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_23 = state._tr_env_extend_gear_last();
            } else {
                _trid_23 = cachedValue as BSet<POSITION>;
            }
            newCache = newCache.set("_tr_env_extend_gear_last", _trid_23);
            for(let param of _trid_23) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_extend_gear_last(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_extend_gear_last", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_24: BSet<POSITION>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_env_extend_gear_skip");
                dependentGuardsBoolean = "_tr_env_extend_gear_skip" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_24 = state._tr_env_extend_gear_skip();
            } else {
                _trid_24 = cachedValue as BSet<POSITION>;
            }
            newCache = newCache.set("_tr_env_extend_gear_skip", _trid_24);
            for(let param of _trid_24) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_extend_gear_skip(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_extend_gear_skip", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_25: BSet<POSITION>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_env_start_open_door");
                dependentGuardsBoolean = "_tr_env_start_open_door" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_25 = state._tr_env_start_open_door();
            } else {
                _trid_25 = cachedValue as BSet<POSITION>;
            }
            newCache = newCache.set("_tr_env_start_open_door", _trid_25);
            for(let param of _trid_25) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_start_open_door(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_start_open_door", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_26: BSet<POSITION>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_env_open_door_last");
                dependentGuardsBoolean = "_tr_env_open_door_last" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_26 = state._tr_env_open_door_last();
            } else {
                _trid_26 = cachedValue as BSet<POSITION>;
            }
            newCache = newCache.set("_tr_env_open_door_last", _trid_26);
            for(let param of _trid_26) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_open_door_last(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_open_door_last", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_27: BSet<POSITION>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_env_open_door_skip");
                dependentGuardsBoolean = "_tr_env_open_door_skip" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_27 = state._tr_env_open_door_skip();
            } else {
                _trid_27 = cachedValue as BSet<POSITION>;
            }
            newCache = newCache.set("_tr_env_open_door_skip", _trid_27);
            for(let param of _trid_27) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_open_door_skip(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_open_door_skip", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_28: BSet<POSITION>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_env_start_close_door");
                dependentGuardsBoolean = "_tr_env_start_close_door" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_28 = state._tr_env_start_close_door();
            } else {
                _trid_28 = cachedValue as BSet<POSITION>;
            }
            newCache = newCache.set("_tr_env_start_close_door", _trid_28);
            for(let param of _trid_28) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_start_close_door(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_start_close_door", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_29: BSet<POSITION>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_env_close_door");
                dependentGuardsBoolean = "_tr_env_close_door" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_29 = state._tr_env_close_door();
            } else {
                _trid_29 = cachedValue as BSet<POSITION>;
            }
            newCache = newCache.set("_tr_env_close_door", _trid_29);
            for(let param of _trid_29) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_close_door(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_close_door", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_30: BSet<POSITION>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_env_close_door_skip");
                dependentGuardsBoolean = "_tr_env_close_door_skip" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_30 = state._tr_env_close_door_skip();
            } else {
                _trid_30 = cachedValue as BSet<POSITION>;
            }
            newCache = newCache.set("_tr_env_close_door_skip", _trid_30);
            for(let param of _trid_30) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_close_door_skip(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_close_door_skip", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_31: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_toggle_handle_up");
                dependentGuardsBoolean = "_tr_toggle_handle_up" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_31 = state._tr_toggle_handle_up();
            } else {
                _trid_31 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_toggle_handle_up", _trid_31);
            if(_trid_31) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.toggle_handle_up();
                copiedState.parent = state;
                this.addCachedInfos("toggle_handle_up", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_32: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_toggle_handle_down");
                dependentGuardsBoolean = "_tr_toggle_handle_down" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_32 = state._tr_toggle_handle_down();
            } else {
                _trid_32 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_toggle_handle_down", _trid_32);
            if(_trid_32) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.toggle_handle_down();
                copiedState.parent = state;
                this.addCachedInfos("toggle_handle_down", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_33: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_con_stimulate_general_valve");
                dependentGuardsBoolean = "_tr_con_stimulate_general_valve" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_33 = state._tr_con_stimulate_general_valve();
            } else {
                _trid_33 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_con_stimulate_general_valve", _trid_33);
            if(_trid_33) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stimulate_general_valve();
                copiedState.parent = state;
                this.addCachedInfos("con_stimulate_general_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_34: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_con_stop_stimulate_general_valve");
                dependentGuardsBoolean = "_tr_con_stop_stimulate_general_valve" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_34 = state._tr_con_stop_stimulate_general_valve();
            } else {
                _trid_34 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_con_stop_stimulate_general_valve", _trid_34);
            if(_trid_34) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stop_stimulate_general_valve();
                copiedState.parent = state;
                this.addCachedInfos("con_stop_stimulate_general_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_35: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_evn_open_general_valve");
                dependentGuardsBoolean = "_tr_evn_open_general_valve" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_35 = state._tr_evn_open_general_valve();
            } else {
                _trid_35 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_evn_open_general_valve", _trid_35);
            if(_trid_35) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.evn_open_general_valve();
                copiedState.parent = state;
                this.addCachedInfos("evn_open_general_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_36: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_evn_close_general_valve");
                dependentGuardsBoolean = "_tr_evn_close_general_valve" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_36 = state._tr_evn_close_general_valve();
            } else {
                _trid_36 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_evn_close_general_valve", _trid_36);
            if(_trid_36) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.evn_close_general_valve();
                copiedState.parent = state;
                this.addCachedInfos("evn_close_general_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_37: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_env_close_analogical_switch");
                dependentGuardsBoolean = "_tr_env_close_analogical_switch" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_37 = state._tr_env_close_analogical_switch();
            } else {
                _trid_37 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_env_close_analogical_switch", _trid_37);
            if(_trid_37) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_close_analogical_switch();
                copiedState.parent = state;
                this.addCachedInfos("env_close_analogical_switch", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_38: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_env_open_analogical_switch");
                dependentGuardsBoolean = "_tr_env_open_analogical_switch" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_38 = state._tr_env_open_analogical_switch();
            } else {
                _trid_38 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_env_open_analogical_switch", _trid_38);
            if(_trid_38) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_open_analogical_switch();
                copiedState.parent = state;
                this.addCachedInfos("env_open_analogical_switch", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

            state.guardCache = newCache;
        } else {
            if(state._tr_begin_flying()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.begin_flying();
                copiedState.parent = state;
                this.addCachedInfos("begin_flying", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_land_plane()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.land_plane();
                copiedState.parent = state;
                this.addCachedInfos("land_plane", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_open_valve_door_open()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.open_valve_door_open();
                copiedState.parent = state;
                this.addCachedInfos("open_valve_door_open", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_close_valve_door_open()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.close_valve_door_open();
                copiedState.parent = state;
                this.addCachedInfos("close_valve_door_open", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_open_valve_door_close()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.open_valve_door_close();
                copiedState.parent = state;
                this.addCachedInfos("open_valve_door_close", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_close_valve_door_close()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.close_valve_door_close();
                copiedState.parent = state;
                this.addCachedInfos("close_valve_door_close", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_open_valve_retract_gear()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.open_valve_retract_gear();
                copiedState.parent = state;
                this.addCachedInfos("open_valve_retract_gear", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_close_valve_retract_gear()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.close_valve_retract_gear();
                copiedState.parent = state;
                this.addCachedInfos("close_valve_retract_gear", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_open_valve_extend_gear()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.open_valve_extend_gear();
                copiedState.parent = state;
                this.addCachedInfos("open_valve_extend_gear", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_close_valve_extend_gear()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.close_valve_extend_gear();
                copiedState.parent = state;
                this.addCachedInfos("close_valve_extend_gear", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_con_stimulate_open_door_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stimulate_open_door_valve();
                copiedState.parent = state;
                this.addCachedInfos("con_stimulate_open_door_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_con_stop_stimulate_open_door_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stop_stimulate_open_door_valve();
                copiedState.parent = state;
                this.addCachedInfos("con_stop_stimulate_open_door_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_con_stimulate_close_door_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stimulate_close_door_valve();
                copiedState.parent = state;
                this.addCachedInfos("con_stimulate_close_door_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_con_stop_stimulate_close_door_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stop_stimulate_close_door_valve();
                copiedState.parent = state;
                this.addCachedInfos("con_stop_stimulate_close_door_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_con_stimulate_retract_gear_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stimulate_retract_gear_valve();
                copiedState.parent = state;
                this.addCachedInfos("con_stimulate_retract_gear_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_con_stop_stimulate_retract_gear_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stop_stimulate_retract_gear_valve();
                copiedState.parent = state;
                this.addCachedInfos("con_stop_stimulate_retract_gear_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_con_stimulate_extend_gear_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stimulate_extend_gear_valve();
                copiedState.parent = state;
                this.addCachedInfos("con_stimulate_extend_gear_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_con_stop_stimulate_extend_gear_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stop_stimulate_extend_gear_valve();
                copiedState.parent = state;
                this.addCachedInfos("con_stop_stimulate_extend_gear_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_19: BSet<POSITION> = state._tr_env_start_retracting_first();
            for(let param of _trid_19) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_start_retracting_first(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_start_retracting_first", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_20: BSet<POSITION> = state._tr_env_retract_gear_skip();
            for(let param of _trid_20) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_retract_gear_skip(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_retract_gear_skip", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_21: BSet<POSITION> = state._tr_env_retract_gear_last();
            for(let param of _trid_21) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_retract_gear_last(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_retract_gear_last", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_22: BSet<POSITION> = state._tr_env_start_extending();
            for(let param of _trid_22) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_start_extending(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_start_extending", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_23: BSet<POSITION> = state._tr_env_extend_gear_last();
            for(let param of _trid_23) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_extend_gear_last(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_extend_gear_last", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_24: BSet<POSITION> = state._tr_env_extend_gear_skip();
            for(let param of _trid_24) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_extend_gear_skip(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_extend_gear_skip", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_25: BSet<POSITION> = state._tr_env_start_open_door();
            for(let param of _trid_25) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_start_open_door(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_start_open_door", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_26: BSet<POSITION> = state._tr_env_open_door_last();
            for(let param of _trid_26) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_open_door_last(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_open_door_last", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_27: BSet<POSITION> = state._tr_env_open_door_skip();
            for(let param of _trid_27) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_open_door_skip(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_open_door_skip", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_28: BSet<POSITION> = state._tr_env_start_close_door();
            for(let param of _trid_28) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_start_close_door(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_start_close_door", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_29: BSet<POSITION> = state._tr_env_close_door();
            for(let param of _trid_29) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_close_door(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_close_door", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_30: BSet<POSITION> = state._tr_env_close_door_skip();
            for(let param of _trid_30) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_close_door_skip(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("env_close_door_skip", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_toggle_handle_up()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.toggle_handle_up();
                copiedState.parent = state;
                this.addCachedInfos("toggle_handle_up", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_toggle_handle_down()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.toggle_handle_down();
                copiedState.parent = state;
                this.addCachedInfos("toggle_handle_down", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_con_stimulate_general_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stimulate_general_valve();
                copiedState.parent = state;
                this.addCachedInfos("con_stimulate_general_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_con_stop_stimulate_general_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stop_stimulate_general_valve();
                copiedState.parent = state;
                this.addCachedInfos("con_stop_stimulate_general_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_evn_open_general_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.evn_open_general_valve();
                copiedState.parent = state;
                this.addCachedInfos("evn_open_general_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_evn_close_general_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.evn_close_general_valve();
                copiedState.parent = state;
                this.addCachedInfos("evn_close_general_valve", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_env_close_analogical_switch()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_close_analogical_switch();
                copiedState.parent = state;
                this.addCachedInfos("env_close_analogical_switch", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_env_open_analogical_switch()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_open_analogical_switch();
                copiedState.parent = state;
                this.addCachedInfos("env_open_analogical_switch", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        }
        return result;
    }

    invViolated(state: LandingGear_R6): boolean {
        if(!(this.isCaching) || "_check_inv_1" in state.dependentInvariant) {
            if(!state._check_inv_1()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_1");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_2" in state.dependentInvariant) {
            if(!state._check_inv_2()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_2");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_3" in state.dependentInvariant) {
            if(!state._check_inv_3()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_3");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_4" in state.dependentInvariant) {
            if(!state._check_inv_4()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_4");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_5" in state.dependentInvariant) {
            if(!state._check_inv_5()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_5");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_6" in state.dependentInvariant) {
            if(!state._check_inv_6()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_6");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_7" in state.dependentInvariant) {
            if(!state._check_inv_7()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_7");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_8" in state.dependentInvariant) {
            if(!state._check_inv_8()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_8");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_9" in state.dependentInvariant) {
            if(!state._check_inv_9()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_9");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_10" in state.dependentInvariant) {
            if(!state._check_inv_10()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_10");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_11" in state.dependentInvariant) {
            if(!state._check_inv_11()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_11");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_12" in state.dependentInvariant) {
            if(!state._check_inv_12()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_12");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_13" in state.dependentInvariant) {
            if(!state._check_inv_13()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_13");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_14" in state.dependentInvariant) {
            if(!state._check_inv_14()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_14");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_15" in state.dependentInvariant) {
            if(!state._check_inv_15()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_15");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_16" in state.dependentInvariant) {
            if(!state._check_inv_16()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_16");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_17" in state.dependentInvariant) {
            if(!state._check_inv_17()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_17");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_18" in state.dependentInvariant) {
            if(!state._check_inv_18()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_18");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_19" in state.dependentInvariant) {
            if(!state._check_inv_19()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_19");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_20" in state.dependentInvariant) {
            if(!state._check_inv_20()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_20");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_21" in state.dependentInvariant) {
            if(!state._check_inv_21()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_21");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_22" in state.dependentInvariant) {
            if(!state._check_inv_22()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_22");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_23" in state.dependentInvariant) {
            if(!state._check_inv_23()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_23");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_24" in state.dependentInvariant) {
            if(!state._check_inv_24()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_24");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_25" in state.dependentInvariant) {
            if(!state._check_inv_25()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_25");
                return true;
            }
        }
        return false;
    }

    addCachedInfos(operation: string, state: LandingGear_R6, copiedState: LandingGear_R6): void {
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

