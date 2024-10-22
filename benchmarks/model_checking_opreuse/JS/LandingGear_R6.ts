import {BTuple} from './btypes/BTuple.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BRelation} from './btypes/BRelation.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";
import {VariantViolation} from "./btypes/BUtils.js";
import {LoopInvariantViolation} from "./btypes/BUtils.js";
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


class _ProjectionRead_begin_flying {

    public shock_absorber: PLANE_STATE;

    constructor(shock_absorber : PLANE_STATE) {
        this.shock_absorber = shock_absorber;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_begin_flying = this;
        let o2: _ProjectionRead_begin_flying = other as _ProjectionRead_begin_flying;
        return o1.shock_absorber.equals(o2.shock_absorber);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.shock_absorber.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_begin_flying {

    public shock_absorber: PLANE_STATE;

    constructor(shock_absorber : PLANE_STATE) {
        this.shock_absorber = shock_absorber;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_begin_flying = this;
        let o2: _ProjectionRead__tr_begin_flying = other as _ProjectionRead__tr_begin_flying;
        return o1.shock_absorber.equals(o2.shock_absorber);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.shock_absorber.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_begin_flying {

    public shock_absorber: PLANE_STATE;

    constructor(shock_absorber : PLANE_STATE) {
        this.shock_absorber = shock_absorber;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_begin_flying = this;
        let o2: _ProjectionWrite_begin_flying = other as _ProjectionWrite_begin_flying;
        return o1.shock_absorber.equals(o2.shock_absorber);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.shock_absorber.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_land_plane {

    public shock_absorber: PLANE_STATE;

    constructor(shock_absorber : PLANE_STATE) {
        this.shock_absorber = shock_absorber;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_land_plane = this;
        let o2: _ProjectionRead_land_plane = other as _ProjectionRead_land_plane;
        return o1.shock_absorber.equals(o2.shock_absorber);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.shock_absorber.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_land_plane {

    public shock_absorber: PLANE_STATE;

    constructor(shock_absorber : PLANE_STATE) {
        this.shock_absorber = shock_absorber;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_land_plane = this;
        let o2: _ProjectionRead__tr_land_plane = other as _ProjectionRead__tr_land_plane;
        return o1.shock_absorber.equals(o2.shock_absorber);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.shock_absorber.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_land_plane {

    public shock_absorber: PLANE_STATE;

    constructor(shock_absorber : PLANE_STATE) {
        this.shock_absorber = shock_absorber;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_land_plane = this;
        let o2: _ProjectionWrite_land_plane = other as _ProjectionWrite_land_plane;
        return o1.shock_absorber.equals(o2.shock_absorber);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.shock_absorber.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_open_valve_door_open {

    public valve_open_door: VALVE_STATE;
    public open_EV: BBoolean;

    constructor(valve_open_door : VALVE_STATE, open_EV : BBoolean) {
        this.valve_open_door = valve_open_door;
        this.open_EV = open_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_open_valve_door_open = this;
        let o2: _ProjectionRead_open_valve_door_open = other as _ProjectionRead_open_valve_door_open;
        return o1.valve_open_door.equals(o2.valve_open_door) && o1.open_EV.equals(o2.open_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_open_door.hashCode() << 1);
        result = 31 * result + (this.open_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_open_valve_door_open {

    public valve_open_door: VALVE_STATE;
    public open_EV: BBoolean;

    constructor(valve_open_door : VALVE_STATE, open_EV : BBoolean) {
        this.valve_open_door = valve_open_door;
        this.open_EV = open_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_open_valve_door_open = this;
        let o2: _ProjectionRead__tr_open_valve_door_open = other as _ProjectionRead__tr_open_valve_door_open;
        return o1.valve_open_door.equals(o2.valve_open_door) && o1.open_EV.equals(o2.open_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_open_door.hashCode() << 1);
        result = 31 * result + (this.open_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_open_valve_door_open {

    public valve_open_door: VALVE_STATE;

    constructor(valve_open_door : VALVE_STATE) {
        this.valve_open_door = valve_open_door;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_open_valve_door_open = this;
        let o2: _ProjectionWrite_open_valve_door_open = other as _ProjectionWrite_open_valve_door_open;
        return o1.valve_open_door.equals(o2.valve_open_door);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_open_door.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_close_valve_door_open {

    public valve_open_door: VALVE_STATE;
    public open_EV: BBoolean;

    constructor(valve_open_door : VALVE_STATE, open_EV : BBoolean) {
        this.valve_open_door = valve_open_door;
        this.open_EV = open_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_close_valve_door_open = this;
        let o2: _ProjectionRead_close_valve_door_open = other as _ProjectionRead_close_valve_door_open;
        return o1.valve_open_door.equals(o2.valve_open_door) && o1.open_EV.equals(o2.open_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_open_door.hashCode() << 1);
        result = 31 * result + (this.open_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_close_valve_door_open {

    public valve_open_door: VALVE_STATE;
    public open_EV: BBoolean;

    constructor(valve_open_door : VALVE_STATE, open_EV : BBoolean) {
        this.valve_open_door = valve_open_door;
        this.open_EV = open_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_close_valve_door_open = this;
        let o2: _ProjectionRead__tr_close_valve_door_open = other as _ProjectionRead__tr_close_valve_door_open;
        return o1.valve_open_door.equals(o2.valve_open_door) && o1.open_EV.equals(o2.open_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_open_door.hashCode() << 1);
        result = 31 * result + (this.open_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_close_valve_door_open {

    public valve_open_door: VALVE_STATE;

    constructor(valve_open_door : VALVE_STATE) {
        this.valve_open_door = valve_open_door;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_close_valve_door_open = this;
        let o2: _ProjectionWrite_close_valve_door_open = other as _ProjectionWrite_close_valve_door_open;
        return o1.valve_open_door.equals(o2.valve_open_door);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_open_door.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_open_valve_door_close {

    public valve_close_door: VALVE_STATE;
    public close_EV: BBoolean;

    constructor(valve_close_door : VALVE_STATE, close_EV : BBoolean) {
        this.valve_close_door = valve_close_door;
        this.close_EV = close_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_open_valve_door_close = this;
        let o2: _ProjectionRead_open_valve_door_close = other as _ProjectionRead_open_valve_door_close;
        return o1.valve_close_door.equals(o2.valve_close_door) && o1.close_EV.equals(o2.close_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_close_door.hashCode() << 1);
        result = 31 * result + (this.close_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_open_valve_door_close {

    public valve_close_door: VALVE_STATE;
    public close_EV: BBoolean;

    constructor(valve_close_door : VALVE_STATE, close_EV : BBoolean) {
        this.valve_close_door = valve_close_door;
        this.close_EV = close_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_open_valve_door_close = this;
        let o2: _ProjectionRead__tr_open_valve_door_close = other as _ProjectionRead__tr_open_valve_door_close;
        return o1.valve_close_door.equals(o2.valve_close_door) && o1.close_EV.equals(o2.close_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_close_door.hashCode() << 1);
        result = 31 * result + (this.close_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_open_valve_door_close {

    public valve_close_door: VALVE_STATE;

    constructor(valve_close_door : VALVE_STATE) {
        this.valve_close_door = valve_close_door;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_open_valve_door_close = this;
        let o2: _ProjectionWrite_open_valve_door_close = other as _ProjectionWrite_open_valve_door_close;
        return o1.valve_close_door.equals(o2.valve_close_door);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_close_door.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_close_valve_door_close {

    public valve_close_door: VALVE_STATE;
    public close_EV: BBoolean;

    constructor(valve_close_door : VALVE_STATE, close_EV : BBoolean) {
        this.valve_close_door = valve_close_door;
        this.close_EV = close_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_close_valve_door_close = this;
        let o2: _ProjectionRead_close_valve_door_close = other as _ProjectionRead_close_valve_door_close;
        return o1.valve_close_door.equals(o2.valve_close_door) && o1.close_EV.equals(o2.close_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_close_door.hashCode() << 1);
        result = 31 * result + (this.close_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_close_valve_door_close {

    public valve_close_door: VALVE_STATE;
    public close_EV: BBoolean;

    constructor(valve_close_door : VALVE_STATE, close_EV : BBoolean) {
        this.valve_close_door = valve_close_door;
        this.close_EV = close_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_close_valve_door_close = this;
        let o2: _ProjectionRead__tr_close_valve_door_close = other as _ProjectionRead__tr_close_valve_door_close;
        return o1.valve_close_door.equals(o2.valve_close_door) && o1.close_EV.equals(o2.close_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_close_door.hashCode() << 1);
        result = 31 * result + (this.close_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_close_valve_door_close {

    public valve_close_door: VALVE_STATE;

    constructor(valve_close_door : VALVE_STATE) {
        this.valve_close_door = valve_close_door;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_close_valve_door_close = this;
        let o2: _ProjectionWrite_close_valve_door_close = other as _ProjectionWrite_close_valve_door_close;
        return o1.valve_close_door.equals(o2.valve_close_door);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_close_door.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_open_valve_retract_gear {

    public valve_retract_gear: VALVE_STATE;
    public retract_EV: BBoolean;

    constructor(valve_retract_gear : VALVE_STATE, retract_EV : BBoolean) {
        this.valve_retract_gear = valve_retract_gear;
        this.retract_EV = retract_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_open_valve_retract_gear = this;
        let o2: _ProjectionRead_open_valve_retract_gear = other as _ProjectionRead_open_valve_retract_gear;
        return o1.valve_retract_gear.equals(o2.valve_retract_gear) && o1.retract_EV.equals(o2.retract_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_retract_gear.hashCode() << 1);
        result = 31 * result + (this.retract_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_open_valve_retract_gear {

    public valve_retract_gear: VALVE_STATE;
    public retract_EV: BBoolean;

    constructor(valve_retract_gear : VALVE_STATE, retract_EV : BBoolean) {
        this.valve_retract_gear = valve_retract_gear;
        this.retract_EV = retract_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_open_valve_retract_gear = this;
        let o2: _ProjectionRead__tr_open_valve_retract_gear = other as _ProjectionRead__tr_open_valve_retract_gear;
        return o1.valve_retract_gear.equals(o2.valve_retract_gear) && o1.retract_EV.equals(o2.retract_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_retract_gear.hashCode() << 1);
        result = 31 * result + (this.retract_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_open_valve_retract_gear {

    public valve_retract_gear: VALVE_STATE;

    constructor(valve_retract_gear : VALVE_STATE) {
        this.valve_retract_gear = valve_retract_gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_open_valve_retract_gear = this;
        let o2: _ProjectionWrite_open_valve_retract_gear = other as _ProjectionWrite_open_valve_retract_gear;
        return o1.valve_retract_gear.equals(o2.valve_retract_gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_retract_gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_close_valve_retract_gear {

    public valve_retract_gear: VALVE_STATE;
    public retract_EV: BBoolean;

    constructor(valve_retract_gear : VALVE_STATE, retract_EV : BBoolean) {
        this.valve_retract_gear = valve_retract_gear;
        this.retract_EV = retract_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_close_valve_retract_gear = this;
        let o2: _ProjectionRead_close_valve_retract_gear = other as _ProjectionRead_close_valve_retract_gear;
        return o1.valve_retract_gear.equals(o2.valve_retract_gear) && o1.retract_EV.equals(o2.retract_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_retract_gear.hashCode() << 1);
        result = 31 * result + (this.retract_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_close_valve_retract_gear {

    public valve_retract_gear: VALVE_STATE;
    public retract_EV: BBoolean;

    constructor(valve_retract_gear : VALVE_STATE, retract_EV : BBoolean) {
        this.valve_retract_gear = valve_retract_gear;
        this.retract_EV = retract_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_close_valve_retract_gear = this;
        let o2: _ProjectionRead__tr_close_valve_retract_gear = other as _ProjectionRead__tr_close_valve_retract_gear;
        return o1.valve_retract_gear.equals(o2.valve_retract_gear) && o1.retract_EV.equals(o2.retract_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_retract_gear.hashCode() << 1);
        result = 31 * result + (this.retract_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_close_valve_retract_gear {

    public valve_retract_gear: VALVE_STATE;

    constructor(valve_retract_gear : VALVE_STATE) {
        this.valve_retract_gear = valve_retract_gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_close_valve_retract_gear = this;
        let o2: _ProjectionWrite_close_valve_retract_gear = other as _ProjectionWrite_close_valve_retract_gear;
        return o1.valve_retract_gear.equals(o2.valve_retract_gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_retract_gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_open_valve_extend_gear {

    public extend_EV: BBoolean;
    public valve_extend_gear: VALVE_STATE;

    constructor(extend_EV : BBoolean, valve_extend_gear : VALVE_STATE) {
        this.extend_EV = extend_EV;
        this.valve_extend_gear = valve_extend_gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_open_valve_extend_gear = this;
        let o2: _ProjectionRead_open_valve_extend_gear = other as _ProjectionRead_open_valve_extend_gear;
        return o1.extend_EV.equals(o2.extend_EV) && o1.valve_extend_gear.equals(o2.valve_extend_gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.extend_EV.hashCode() << 1);
        result = 31 * result + (this.valve_extend_gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_open_valve_extend_gear {

    public extend_EV: BBoolean;
    public valve_extend_gear: VALVE_STATE;

    constructor(extend_EV : BBoolean, valve_extend_gear : VALVE_STATE) {
        this.extend_EV = extend_EV;
        this.valve_extend_gear = valve_extend_gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_open_valve_extend_gear = this;
        let o2: _ProjectionRead__tr_open_valve_extend_gear = other as _ProjectionRead__tr_open_valve_extend_gear;
        return o1.extend_EV.equals(o2.extend_EV) && o1.valve_extend_gear.equals(o2.valve_extend_gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.extend_EV.hashCode() << 1);
        result = 31 * result + (this.valve_extend_gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_open_valve_extend_gear {

    public valve_extend_gear: VALVE_STATE;

    constructor(valve_extend_gear : VALVE_STATE) {
        this.valve_extend_gear = valve_extend_gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_open_valve_extend_gear = this;
        let o2: _ProjectionWrite_open_valve_extend_gear = other as _ProjectionWrite_open_valve_extend_gear;
        return o1.valve_extend_gear.equals(o2.valve_extend_gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_extend_gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_close_valve_extend_gear {

    public extend_EV: BBoolean;
    public valve_extend_gear: VALVE_STATE;

    constructor(extend_EV : BBoolean, valve_extend_gear : VALVE_STATE) {
        this.extend_EV = extend_EV;
        this.valve_extend_gear = valve_extend_gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_close_valve_extend_gear = this;
        let o2: _ProjectionRead_close_valve_extend_gear = other as _ProjectionRead_close_valve_extend_gear;
        return o1.extend_EV.equals(o2.extend_EV) && o1.valve_extend_gear.equals(o2.valve_extend_gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.extend_EV.hashCode() << 1);
        result = 31 * result + (this.valve_extend_gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_close_valve_extend_gear {

    public extend_EV: BBoolean;
    public valve_extend_gear: VALVE_STATE;

    constructor(extend_EV : BBoolean, valve_extend_gear : VALVE_STATE) {
        this.extend_EV = extend_EV;
        this.valve_extend_gear = valve_extend_gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_close_valve_extend_gear = this;
        let o2: _ProjectionRead__tr_close_valve_extend_gear = other as _ProjectionRead__tr_close_valve_extend_gear;
        return o1.extend_EV.equals(o2.extend_EV) && o1.valve_extend_gear.equals(o2.valve_extend_gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.extend_EV.hashCode() << 1);
        result = 31 * result + (this.valve_extend_gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_close_valve_extend_gear {

    public valve_extend_gear: VALVE_STATE;

    constructor(valve_extend_gear : VALVE_STATE) {
        this.valve_extend_gear = valve_extend_gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_close_valve_extend_gear = this;
        let o2: _ProjectionWrite_close_valve_extend_gear = other as _ProjectionWrite_close_valve_extend_gear;
        return o1.valve_extend_gear.equals(o2.valve_extend_gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_extend_gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_con_stimulate_open_door_valve {

    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public open_EV: BBoolean;
    public shock_absorber: PLANE_STATE;
    public close_EV: BBoolean;
    public general_EV: BBoolean;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, open_EV : BBoolean, shock_absorber : PLANE_STATE, close_EV : BBoolean, general_EV : BBoolean, gears : BRelation<POSITION, GEAR_STATE>) {
        this.handle = handle;
        this.doors = doors;
        this.open_EV = open_EV;
        this.shock_absorber = shock_absorber;
        this.close_EV = close_EV;
        this.general_EV = general_EV;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_con_stimulate_open_door_valve = this;
        let o2: _ProjectionRead_con_stimulate_open_door_valve = other as _ProjectionRead_con_stimulate_open_door_valve;
        return o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.open_EV.equals(o2.open_EV) && o1.shock_absorber.equals(o2.shock_absorber) && o1.close_EV.equals(o2.close_EV) && o1.general_EV.equals(o2.general_EV) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.open_EV.hashCode() << 1);
        result = 31 * result + (this.shock_absorber.hashCode() << 1);
        result = 31 * result + (this.close_EV.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_con_stimulate_open_door_valve {

    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public open_EV: BBoolean;
    public shock_absorber: PLANE_STATE;
    public close_EV: BBoolean;
    public general_EV: BBoolean;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, open_EV : BBoolean, shock_absorber : PLANE_STATE, close_EV : BBoolean, general_EV : BBoolean, gears : BRelation<POSITION, GEAR_STATE>) {
        this.handle = handle;
        this.doors = doors;
        this.open_EV = open_EV;
        this.shock_absorber = shock_absorber;
        this.close_EV = close_EV;
        this.general_EV = general_EV;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_con_stimulate_open_door_valve = this;
        let o2: _ProjectionRead__tr_con_stimulate_open_door_valve = other as _ProjectionRead__tr_con_stimulate_open_door_valve;
        return o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.open_EV.equals(o2.open_EV) && o1.shock_absorber.equals(o2.shock_absorber) && o1.close_EV.equals(o2.close_EV) && o1.general_EV.equals(o2.general_EV) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.open_EV.hashCode() << 1);
        result = 31 * result + (this.shock_absorber.hashCode() << 1);
        result = 31 * result + (this.close_EV.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_con_stimulate_open_door_valve {

    public open_EV: BBoolean;

    constructor(open_EV : BBoolean) {
        this.open_EV = open_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_con_stimulate_open_door_valve = this;
        let o2: _ProjectionWrite_con_stimulate_open_door_valve = other as _ProjectionWrite_con_stimulate_open_door_valve;
        return o1.open_EV.equals(o2.open_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.open_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_con_stop_stimulate_open_door_valve {

    public extend_EV: BBoolean;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public open_EV: BBoolean;
    public shock_absorber: PLANE_STATE;
    public general_EV: BBoolean;
    public retract_EV: BBoolean;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(extend_EV : BBoolean, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, open_EV : BBoolean, shock_absorber : PLANE_STATE, general_EV : BBoolean, retract_EV : BBoolean, gears : BRelation<POSITION, GEAR_STATE>) {
        this.extend_EV = extend_EV;
        this.handle = handle;
        this.doors = doors;
        this.open_EV = open_EV;
        this.shock_absorber = shock_absorber;
        this.general_EV = general_EV;
        this.retract_EV = retract_EV;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_con_stop_stimulate_open_door_valve = this;
        let o2: _ProjectionRead_con_stop_stimulate_open_door_valve = other as _ProjectionRead_con_stop_stimulate_open_door_valve;
        return o1.extend_EV.equals(o2.extend_EV) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.open_EV.equals(o2.open_EV) && o1.shock_absorber.equals(o2.shock_absorber) && o1.general_EV.equals(o2.general_EV) && o1.retract_EV.equals(o2.retract_EV) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.extend_EV.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.open_EV.hashCode() << 1);
        result = 31 * result + (this.shock_absorber.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        result = 31 * result + (this.retract_EV.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_con_stop_stimulate_open_door_valve {

    public extend_EV: BBoolean;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public open_EV: BBoolean;
    public shock_absorber: PLANE_STATE;
    public general_EV: BBoolean;
    public retract_EV: BBoolean;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(extend_EV : BBoolean, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, open_EV : BBoolean, shock_absorber : PLANE_STATE, general_EV : BBoolean, retract_EV : BBoolean, gears : BRelation<POSITION, GEAR_STATE>) {
        this.extend_EV = extend_EV;
        this.handle = handle;
        this.doors = doors;
        this.open_EV = open_EV;
        this.shock_absorber = shock_absorber;
        this.general_EV = general_EV;
        this.retract_EV = retract_EV;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_con_stop_stimulate_open_door_valve = this;
        let o2: _ProjectionRead__tr_con_stop_stimulate_open_door_valve = other as _ProjectionRead__tr_con_stop_stimulate_open_door_valve;
        return o1.extend_EV.equals(o2.extend_EV) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.open_EV.equals(o2.open_EV) && o1.shock_absorber.equals(o2.shock_absorber) && o1.general_EV.equals(o2.general_EV) && o1.retract_EV.equals(o2.retract_EV) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.extend_EV.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.open_EV.hashCode() << 1);
        result = 31 * result + (this.shock_absorber.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        result = 31 * result + (this.retract_EV.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_con_stop_stimulate_open_door_valve {

    public open_EV: BBoolean;

    constructor(open_EV : BBoolean) {
        this.open_EV = open_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_con_stop_stimulate_open_door_valve = this;
        let o2: _ProjectionWrite_con_stop_stimulate_open_door_valve = other as _ProjectionWrite_con_stop_stimulate_open_door_valve;
        return o1.open_EV.equals(o2.open_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.open_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_con_stimulate_close_door_valve {

    public extend_EV: BBoolean;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public open_EV: BBoolean;
    public shock_absorber: PLANE_STATE;
    public close_EV: BBoolean;
    public general_EV: BBoolean;
    public retract_EV: BBoolean;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(extend_EV : BBoolean, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, open_EV : BBoolean, shock_absorber : PLANE_STATE, close_EV : BBoolean, general_EV : BBoolean, retract_EV : BBoolean, gears : BRelation<POSITION, GEAR_STATE>) {
        this.extend_EV = extend_EV;
        this.handle = handle;
        this.doors = doors;
        this.open_EV = open_EV;
        this.shock_absorber = shock_absorber;
        this.close_EV = close_EV;
        this.general_EV = general_EV;
        this.retract_EV = retract_EV;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_con_stimulate_close_door_valve = this;
        let o2: _ProjectionRead_con_stimulate_close_door_valve = other as _ProjectionRead_con_stimulate_close_door_valve;
        return o1.extend_EV.equals(o2.extend_EV) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.open_EV.equals(o2.open_EV) && o1.shock_absorber.equals(o2.shock_absorber) && o1.close_EV.equals(o2.close_EV) && o1.general_EV.equals(o2.general_EV) && o1.retract_EV.equals(o2.retract_EV) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.extend_EV.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.open_EV.hashCode() << 1);
        result = 31 * result + (this.shock_absorber.hashCode() << 1);
        result = 31 * result + (this.close_EV.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        result = 31 * result + (this.retract_EV.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_con_stimulate_close_door_valve {

    public extend_EV: BBoolean;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public open_EV: BBoolean;
    public shock_absorber: PLANE_STATE;
    public close_EV: BBoolean;
    public general_EV: BBoolean;
    public retract_EV: BBoolean;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(extend_EV : BBoolean, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, open_EV : BBoolean, shock_absorber : PLANE_STATE, close_EV : BBoolean, general_EV : BBoolean, retract_EV : BBoolean, gears : BRelation<POSITION, GEAR_STATE>) {
        this.extend_EV = extend_EV;
        this.handle = handle;
        this.doors = doors;
        this.open_EV = open_EV;
        this.shock_absorber = shock_absorber;
        this.close_EV = close_EV;
        this.general_EV = general_EV;
        this.retract_EV = retract_EV;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_con_stimulate_close_door_valve = this;
        let o2: _ProjectionRead__tr_con_stimulate_close_door_valve = other as _ProjectionRead__tr_con_stimulate_close_door_valve;
        return o1.extend_EV.equals(o2.extend_EV) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.open_EV.equals(o2.open_EV) && o1.shock_absorber.equals(o2.shock_absorber) && o1.close_EV.equals(o2.close_EV) && o1.general_EV.equals(o2.general_EV) && o1.retract_EV.equals(o2.retract_EV) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.extend_EV.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.open_EV.hashCode() << 1);
        result = 31 * result + (this.shock_absorber.hashCode() << 1);
        result = 31 * result + (this.close_EV.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        result = 31 * result + (this.retract_EV.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_con_stimulate_close_door_valve {

    public close_EV: BBoolean;

    constructor(close_EV : BBoolean) {
        this.close_EV = close_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_con_stimulate_close_door_valve = this;
        let o2: _ProjectionWrite_con_stimulate_close_door_valve = other as _ProjectionWrite_con_stimulate_close_door_valve;
        return o1.close_EV.equals(o2.close_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.close_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_con_stop_stimulate_close_door_valve {

    public doors: BRelation<POSITION, DOOR_STATE>;
    public shock_absorber: PLANE_STATE;
    public handle: HANDLE_STATE;
    public close_EV: BBoolean;
    public general_EV: BBoolean;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(doors : BRelation<POSITION, DOOR_STATE>, shock_absorber : PLANE_STATE, handle : HANDLE_STATE, close_EV : BBoolean, general_EV : BBoolean, gears : BRelation<POSITION, GEAR_STATE>) {
        this.doors = doors;
        this.shock_absorber = shock_absorber;
        this.handle = handle;
        this.close_EV = close_EV;
        this.general_EV = general_EV;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_con_stop_stimulate_close_door_valve = this;
        let o2: _ProjectionRead_con_stop_stimulate_close_door_valve = other as _ProjectionRead_con_stop_stimulate_close_door_valve;
        return o1.doors.equals(o2.doors) && o1.shock_absorber.equals(o2.shock_absorber) && o1.handle.equals(o2.handle) && o1.close_EV.equals(o2.close_EV) && o1.general_EV.equals(o2.general_EV) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.shock_absorber.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.close_EV.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_con_stop_stimulate_close_door_valve {

    public doors: BRelation<POSITION, DOOR_STATE>;
    public shock_absorber: PLANE_STATE;
    public handle: HANDLE_STATE;
    public close_EV: BBoolean;
    public general_EV: BBoolean;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(doors : BRelation<POSITION, DOOR_STATE>, shock_absorber : PLANE_STATE, handle : HANDLE_STATE, close_EV : BBoolean, general_EV : BBoolean, gears : BRelation<POSITION, GEAR_STATE>) {
        this.doors = doors;
        this.shock_absorber = shock_absorber;
        this.handle = handle;
        this.close_EV = close_EV;
        this.general_EV = general_EV;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_con_stop_stimulate_close_door_valve = this;
        let o2: _ProjectionRead__tr_con_stop_stimulate_close_door_valve = other as _ProjectionRead__tr_con_stop_stimulate_close_door_valve;
        return o1.doors.equals(o2.doors) && o1.shock_absorber.equals(o2.shock_absorber) && o1.handle.equals(o2.handle) && o1.close_EV.equals(o2.close_EV) && o1.general_EV.equals(o2.general_EV) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.shock_absorber.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.close_EV.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_con_stop_stimulate_close_door_valve {

    public close_EV: BBoolean;

    constructor(close_EV : BBoolean) {
        this.close_EV = close_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_con_stop_stimulate_close_door_valve = this;
        let o2: _ProjectionWrite_con_stop_stimulate_close_door_valve = other as _ProjectionWrite_con_stop_stimulate_close_door_valve;
        return o1.close_EV.equals(o2.close_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.close_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_con_stimulate_retract_gear_valve {

    public extend_EV: BBoolean;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public open_EV: BBoolean;
    public shock_absorber: PLANE_STATE;
    public handle: HANDLE_STATE;
    public general_EV: BBoolean;
    public retract_EV: BBoolean;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(extend_EV : BBoolean, doors : BRelation<POSITION, DOOR_STATE>, open_EV : BBoolean, shock_absorber : PLANE_STATE, handle : HANDLE_STATE, general_EV : BBoolean, retract_EV : BBoolean, gears : BRelation<POSITION, GEAR_STATE>) {
        this.extend_EV = extend_EV;
        this.doors = doors;
        this.open_EV = open_EV;
        this.shock_absorber = shock_absorber;
        this.handle = handle;
        this.general_EV = general_EV;
        this.retract_EV = retract_EV;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_con_stimulate_retract_gear_valve = this;
        let o2: _ProjectionRead_con_stimulate_retract_gear_valve = other as _ProjectionRead_con_stimulate_retract_gear_valve;
        return o1.extend_EV.equals(o2.extend_EV) && o1.doors.equals(o2.doors) && o1.open_EV.equals(o2.open_EV) && o1.shock_absorber.equals(o2.shock_absorber) && o1.handle.equals(o2.handle) && o1.general_EV.equals(o2.general_EV) && o1.retract_EV.equals(o2.retract_EV) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.extend_EV.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.open_EV.hashCode() << 1);
        result = 31 * result + (this.shock_absorber.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        result = 31 * result + (this.retract_EV.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_con_stimulate_retract_gear_valve {

    public extend_EV: BBoolean;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public open_EV: BBoolean;
    public shock_absorber: PLANE_STATE;
    public handle: HANDLE_STATE;
    public general_EV: BBoolean;
    public retract_EV: BBoolean;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(extend_EV : BBoolean, doors : BRelation<POSITION, DOOR_STATE>, open_EV : BBoolean, shock_absorber : PLANE_STATE, handle : HANDLE_STATE, general_EV : BBoolean, retract_EV : BBoolean, gears : BRelation<POSITION, GEAR_STATE>) {
        this.extend_EV = extend_EV;
        this.doors = doors;
        this.open_EV = open_EV;
        this.shock_absorber = shock_absorber;
        this.handle = handle;
        this.general_EV = general_EV;
        this.retract_EV = retract_EV;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_con_stimulate_retract_gear_valve = this;
        let o2: _ProjectionRead__tr_con_stimulate_retract_gear_valve = other as _ProjectionRead__tr_con_stimulate_retract_gear_valve;
        return o1.extend_EV.equals(o2.extend_EV) && o1.doors.equals(o2.doors) && o1.open_EV.equals(o2.open_EV) && o1.shock_absorber.equals(o2.shock_absorber) && o1.handle.equals(o2.handle) && o1.general_EV.equals(o2.general_EV) && o1.retract_EV.equals(o2.retract_EV) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.extend_EV.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.open_EV.hashCode() << 1);
        result = 31 * result + (this.shock_absorber.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        result = 31 * result + (this.retract_EV.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_con_stimulate_retract_gear_valve {

    public retract_EV: BBoolean;

    constructor(retract_EV : BBoolean) {
        this.retract_EV = retract_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_con_stimulate_retract_gear_valve = this;
        let o2: _ProjectionWrite_con_stimulate_retract_gear_valve = other as _ProjectionWrite_con_stimulate_retract_gear_valve;
        return o1.retract_EV.equals(o2.retract_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.retract_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_con_stop_stimulate_retract_gear_valve {

    public handle: HANDLE_STATE;
    public general_EV: BBoolean;
    public retract_EV: BBoolean;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(handle : HANDLE_STATE, general_EV : BBoolean, retract_EV : BBoolean, gears : BRelation<POSITION, GEAR_STATE>) {
        this.handle = handle;
        this.general_EV = general_EV;
        this.retract_EV = retract_EV;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_con_stop_stimulate_retract_gear_valve = this;
        let o2: _ProjectionRead_con_stop_stimulate_retract_gear_valve = other as _ProjectionRead_con_stop_stimulate_retract_gear_valve;
        return o1.handle.equals(o2.handle) && o1.general_EV.equals(o2.general_EV) && o1.retract_EV.equals(o2.retract_EV) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        result = 31 * result + (this.retract_EV.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve {

    public handle: HANDLE_STATE;
    public general_EV: BBoolean;
    public retract_EV: BBoolean;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(handle : HANDLE_STATE, general_EV : BBoolean, retract_EV : BBoolean, gears : BRelation<POSITION, GEAR_STATE>) {
        this.handle = handle;
        this.general_EV = general_EV;
        this.retract_EV = retract_EV;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve = this;
        let o2: _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve = other as _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve;
        return o1.handle.equals(o2.handle) && o1.general_EV.equals(o2.general_EV) && o1.retract_EV.equals(o2.retract_EV) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        result = 31 * result + (this.retract_EV.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_con_stop_stimulate_retract_gear_valve {

    public retract_EV: BBoolean;

    constructor(retract_EV : BBoolean) {
        this.retract_EV = retract_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_con_stop_stimulate_retract_gear_valve = this;
        let o2: _ProjectionWrite_con_stop_stimulate_retract_gear_valve = other as _ProjectionWrite_con_stop_stimulate_retract_gear_valve;
        return o1.retract_EV.equals(o2.retract_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.retract_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_con_stimulate_extend_gear_valve {

    public extend_EV: BBoolean;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public open_EV: BBoolean;
    public handle: HANDLE_STATE;
    public general_EV: BBoolean;
    public retract_EV: BBoolean;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(extend_EV : BBoolean, doors : BRelation<POSITION, DOOR_STATE>, open_EV : BBoolean, handle : HANDLE_STATE, general_EV : BBoolean, retract_EV : BBoolean, gears : BRelation<POSITION, GEAR_STATE>) {
        this.extend_EV = extend_EV;
        this.doors = doors;
        this.open_EV = open_EV;
        this.handle = handle;
        this.general_EV = general_EV;
        this.retract_EV = retract_EV;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_con_stimulate_extend_gear_valve = this;
        let o2: _ProjectionRead_con_stimulate_extend_gear_valve = other as _ProjectionRead_con_stimulate_extend_gear_valve;
        return o1.extend_EV.equals(o2.extend_EV) && o1.doors.equals(o2.doors) && o1.open_EV.equals(o2.open_EV) && o1.handle.equals(o2.handle) && o1.general_EV.equals(o2.general_EV) && o1.retract_EV.equals(o2.retract_EV) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.extend_EV.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.open_EV.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        result = 31 * result + (this.retract_EV.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_con_stimulate_extend_gear_valve {

    public extend_EV: BBoolean;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public open_EV: BBoolean;
    public handle: HANDLE_STATE;
    public general_EV: BBoolean;
    public retract_EV: BBoolean;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(extend_EV : BBoolean, doors : BRelation<POSITION, DOOR_STATE>, open_EV : BBoolean, handle : HANDLE_STATE, general_EV : BBoolean, retract_EV : BBoolean, gears : BRelation<POSITION, GEAR_STATE>) {
        this.extend_EV = extend_EV;
        this.doors = doors;
        this.open_EV = open_EV;
        this.handle = handle;
        this.general_EV = general_EV;
        this.retract_EV = retract_EV;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_con_stimulate_extend_gear_valve = this;
        let o2: _ProjectionRead__tr_con_stimulate_extend_gear_valve = other as _ProjectionRead__tr_con_stimulate_extend_gear_valve;
        return o1.extend_EV.equals(o2.extend_EV) && o1.doors.equals(o2.doors) && o1.open_EV.equals(o2.open_EV) && o1.handle.equals(o2.handle) && o1.general_EV.equals(o2.general_EV) && o1.retract_EV.equals(o2.retract_EV) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.extend_EV.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.open_EV.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        result = 31 * result + (this.retract_EV.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_con_stimulate_extend_gear_valve {

    public extend_EV: BBoolean;

    constructor(extend_EV : BBoolean) {
        this.extend_EV = extend_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_con_stimulate_extend_gear_valve = this;
        let o2: _ProjectionWrite_con_stimulate_extend_gear_valve = other as _ProjectionWrite_con_stimulate_extend_gear_valve;
        return o1.extend_EV.equals(o2.extend_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.extend_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_con_stop_stimulate_extend_gear_valve {

    public extend_EV: BBoolean;
    public handle: HANDLE_STATE;
    public general_EV: BBoolean;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(extend_EV : BBoolean, handle : HANDLE_STATE, general_EV : BBoolean, gears : BRelation<POSITION, GEAR_STATE>) {
        this.extend_EV = extend_EV;
        this.handle = handle;
        this.general_EV = general_EV;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_con_stop_stimulate_extend_gear_valve = this;
        let o2: _ProjectionRead_con_stop_stimulate_extend_gear_valve = other as _ProjectionRead_con_stop_stimulate_extend_gear_valve;
        return o1.extend_EV.equals(o2.extend_EV) && o1.handle.equals(o2.handle) && o1.general_EV.equals(o2.general_EV) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.extend_EV.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve {

    public extend_EV: BBoolean;
    public handle: HANDLE_STATE;
    public general_EV: BBoolean;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(extend_EV : BBoolean, handle : HANDLE_STATE, general_EV : BBoolean, gears : BRelation<POSITION, GEAR_STATE>) {
        this.extend_EV = extend_EV;
        this.handle = handle;
        this.general_EV = general_EV;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve = this;
        let o2: _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve = other as _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve;
        return o1.extend_EV.equals(o2.extend_EV) && o1.handle.equals(o2.handle) && o1.general_EV.equals(o2.general_EV) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.extend_EV.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_con_stop_stimulate_extend_gear_valve {

    public extend_EV: BBoolean;

    constructor(extend_EV : BBoolean) {
        this.extend_EV = extend_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_con_stop_stimulate_extend_gear_valve = this;
        let o2: _ProjectionWrite_con_stop_stimulate_extend_gear_valve = other as _ProjectionWrite_con_stop_stimulate_extend_gear_valve;
        return o1.extend_EV.equals(o2.extend_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.extend_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_env_start_retracting_first {

    public door: DOOR_STATE;
    public handle: HANDLE_STATE;
    public valve_retract_gear: VALVE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public general_valve: VALVE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(door : DOOR_STATE, handle : HANDLE_STATE, valve_retract_gear : VALVE_STATE, doors : BRelation<POSITION, DOOR_STATE>, general_valve : VALVE_STATE, gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.door = door;
        this.handle = handle;
        this.valve_retract_gear = valve_retract_gear;
        this.doors = doors;
        this.general_valve = general_valve;
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_env_start_retracting_first = this;
        let o2: _ProjectionRead_env_start_retracting_first = other as _ProjectionRead_env_start_retracting_first;
        return o1.door.equals(o2.door) && o1.handle.equals(o2.handle) && o1.valve_retract_gear.equals(o2.valve_retract_gear) && o1.doors.equals(o2.doors) && o1.general_valve.equals(o2.general_valve) && o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.door.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.valve_retract_gear.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_env_start_retracting_first {

    public door: DOOR_STATE;
    public handle: HANDLE_STATE;
    public valve_retract_gear: VALVE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public general_valve: VALVE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(door : DOOR_STATE, handle : HANDLE_STATE, valve_retract_gear : VALVE_STATE, doors : BRelation<POSITION, DOOR_STATE>, general_valve : VALVE_STATE, gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.door = door;
        this.handle = handle;
        this.valve_retract_gear = valve_retract_gear;
        this.doors = doors;
        this.general_valve = general_valve;
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_env_start_retracting_first = this;
        let o2: _ProjectionRead__tr_env_start_retracting_first = other as _ProjectionRead__tr_env_start_retracting_first;
        return o1.door.equals(o2.door) && o1.handle.equals(o2.handle) && o1.valve_retract_gear.equals(o2.valve_retract_gear) && o1.doors.equals(o2.doors) && o1.general_valve.equals(o2.general_valve) && o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.door.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.valve_retract_gear.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_env_start_retracting_first {

    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_env_start_retracting_first = this;
        let o2: _ProjectionWrite_env_start_retracting_first = other as _ProjectionWrite_env_start_retracting_first;
        return o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_env_retract_gear_skip {

    public doors: BRelation<POSITION, DOOR_STATE>;
    public general_valve: VALVE_STATE;
    public handle: HANDLE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(doors : BRelation<POSITION, DOOR_STATE>, general_valve : VALVE_STATE, handle : HANDLE_STATE, gears : BRelation<POSITION, GEAR_STATE>) {
        this.doors = doors;
        this.general_valve = general_valve;
        this.handle = handle;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_env_retract_gear_skip = this;
        let o2: _ProjectionRead_env_retract_gear_skip = other as _ProjectionRead_env_retract_gear_skip;
        return o1.doors.equals(o2.doors) && o1.general_valve.equals(o2.general_valve) && o1.handle.equals(o2.handle) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_env_retract_gear_skip {

    public doors: BRelation<POSITION, DOOR_STATE>;
    public general_valve: VALVE_STATE;
    public handle: HANDLE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(doors : BRelation<POSITION, DOOR_STATE>, general_valve : VALVE_STATE, handle : HANDLE_STATE, gears : BRelation<POSITION, GEAR_STATE>) {
        this.doors = doors;
        this.general_valve = general_valve;
        this.handle = handle;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_env_retract_gear_skip = this;
        let o2: _ProjectionRead__tr_env_retract_gear_skip = other as _ProjectionRead__tr_env_retract_gear_skip;
        return o1.doors.equals(o2.doors) && o1.general_valve.equals(o2.general_valve) && o1.handle.equals(o2.handle) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_env_retract_gear_skip {

    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(gears : BRelation<POSITION, GEAR_STATE>) {
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_env_retract_gear_skip = this;
        let o2: _ProjectionWrite_env_retract_gear_skip = other as _ProjectionWrite_env_retract_gear_skip;
        return o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_env_retract_gear_last {

    public door: DOOR_STATE;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public general_valve: VALVE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(door : DOOR_STATE, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, general_valve : VALVE_STATE, gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.door = door;
        this.handle = handle;
        this.doors = doors;
        this.general_valve = general_valve;
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_env_retract_gear_last = this;
        let o2: _ProjectionRead_env_retract_gear_last = other as _ProjectionRead_env_retract_gear_last;
        return o1.door.equals(o2.door) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.general_valve.equals(o2.general_valve) && o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.door.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_env_retract_gear_last {

    public door: DOOR_STATE;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public general_valve: VALVE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(door : DOOR_STATE, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, general_valve : VALVE_STATE, gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.door = door;
        this.handle = handle;
        this.doors = doors;
        this.general_valve = general_valve;
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_env_retract_gear_last = this;
        let o2: _ProjectionRead__tr_env_retract_gear_last = other as _ProjectionRead__tr_env_retract_gear_last;
        return o1.door.equals(o2.door) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.general_valve.equals(o2.general_valve) && o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.door.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_env_retract_gear_last {

    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_env_retract_gear_last = this;
        let o2: _ProjectionWrite_env_retract_gear_last = other as _ProjectionWrite_env_retract_gear_last;
        return o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_env_start_extending {

    public door: DOOR_STATE;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public general_valve: VALVE_STATE;
    public valve_extend_gear: VALVE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(door : DOOR_STATE, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, general_valve : VALVE_STATE, valve_extend_gear : VALVE_STATE, gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.door = door;
        this.handle = handle;
        this.doors = doors;
        this.general_valve = general_valve;
        this.valve_extend_gear = valve_extend_gear;
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_env_start_extending = this;
        let o2: _ProjectionRead_env_start_extending = other as _ProjectionRead_env_start_extending;
        return o1.door.equals(o2.door) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.general_valve.equals(o2.general_valve) && o1.valve_extend_gear.equals(o2.valve_extend_gear) && o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.door.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.valve_extend_gear.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_env_start_extending {

    public door: DOOR_STATE;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public general_valve: VALVE_STATE;
    public valve_extend_gear: VALVE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(door : DOOR_STATE, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, general_valve : VALVE_STATE, valve_extend_gear : VALVE_STATE, gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.door = door;
        this.handle = handle;
        this.doors = doors;
        this.general_valve = general_valve;
        this.valve_extend_gear = valve_extend_gear;
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_env_start_extending = this;
        let o2: _ProjectionRead__tr_env_start_extending = other as _ProjectionRead__tr_env_start_extending;
        return o1.door.equals(o2.door) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.general_valve.equals(o2.general_valve) && o1.valve_extend_gear.equals(o2.valve_extend_gear) && o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.door.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.valve_extend_gear.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_env_start_extending {

    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_env_start_extending = this;
        let o2: _ProjectionWrite_env_start_extending = other as _ProjectionWrite_env_start_extending;
        return o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_env_extend_gear_last {

    public door: DOOR_STATE;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public general_valve: VALVE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(door : DOOR_STATE, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, general_valve : VALVE_STATE, gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.door = door;
        this.handle = handle;
        this.doors = doors;
        this.general_valve = general_valve;
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_env_extend_gear_last = this;
        let o2: _ProjectionRead_env_extend_gear_last = other as _ProjectionRead_env_extend_gear_last;
        return o1.door.equals(o2.door) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.general_valve.equals(o2.general_valve) && o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.door.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_env_extend_gear_last {

    public door: DOOR_STATE;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public general_valve: VALVE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(door : DOOR_STATE, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, general_valve : VALVE_STATE, gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.door = door;
        this.handle = handle;
        this.doors = doors;
        this.general_valve = general_valve;
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_env_extend_gear_last = this;
        let o2: _ProjectionRead__tr_env_extend_gear_last = other as _ProjectionRead__tr_env_extend_gear_last;
        return o1.door.equals(o2.door) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.general_valve.equals(o2.general_valve) && o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.door.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_env_extend_gear_last {

    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_env_extend_gear_last = this;
        let o2: _ProjectionWrite_env_extend_gear_last = other as _ProjectionWrite_env_extend_gear_last;
        return o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_env_extend_gear_skip {

    public doors: BRelation<POSITION, DOOR_STATE>;
    public general_valve: VALVE_STATE;
    public handle: HANDLE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(doors : BRelation<POSITION, DOOR_STATE>, general_valve : VALVE_STATE, handle : HANDLE_STATE, gears : BRelation<POSITION, GEAR_STATE>) {
        this.doors = doors;
        this.general_valve = general_valve;
        this.handle = handle;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_env_extend_gear_skip = this;
        let o2: _ProjectionRead_env_extend_gear_skip = other as _ProjectionRead_env_extend_gear_skip;
        return o1.doors.equals(o2.doors) && o1.general_valve.equals(o2.general_valve) && o1.handle.equals(o2.handle) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_env_extend_gear_skip {

    public doors: BRelation<POSITION, DOOR_STATE>;
    public general_valve: VALVE_STATE;
    public handle: HANDLE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(doors : BRelation<POSITION, DOOR_STATE>, general_valve : VALVE_STATE, handle : HANDLE_STATE, gears : BRelation<POSITION, GEAR_STATE>) {
        this.doors = doors;
        this.general_valve = general_valve;
        this.handle = handle;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_env_extend_gear_skip = this;
        let o2: _ProjectionRead__tr_env_extend_gear_skip = other as _ProjectionRead__tr_env_extend_gear_skip;
        return o1.doors.equals(o2.doors) && o1.general_valve.equals(o2.general_valve) && o1.handle.equals(o2.handle) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_env_extend_gear_skip {

    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(gears : BRelation<POSITION, GEAR_STATE>) {
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_env_extend_gear_skip = this;
        let o2: _ProjectionWrite_env_extend_gear_skip = other as _ProjectionWrite_env_extend_gear_skip;
        return o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_env_start_open_door {

    public valve_open_door: VALVE_STATE;
    public door: DOOR_STATE;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public general_valve: VALVE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(valve_open_door : VALVE_STATE, door : DOOR_STATE, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, general_valve : VALVE_STATE, gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.valve_open_door = valve_open_door;
        this.door = door;
        this.handle = handle;
        this.doors = doors;
        this.general_valve = general_valve;
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_env_start_open_door = this;
        let o2: _ProjectionRead_env_start_open_door = other as _ProjectionRead_env_start_open_door;
        return o1.valve_open_door.equals(o2.valve_open_door) && o1.door.equals(o2.door) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.general_valve.equals(o2.general_valve) && o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_open_door.hashCode() << 1);
        result = 31 * result + (this.door.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_env_start_open_door {

    public valve_open_door: VALVE_STATE;
    public door: DOOR_STATE;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public general_valve: VALVE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(valve_open_door : VALVE_STATE, door : DOOR_STATE, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, general_valve : VALVE_STATE, gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.valve_open_door = valve_open_door;
        this.door = door;
        this.handle = handle;
        this.doors = doors;
        this.general_valve = general_valve;
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_env_start_open_door = this;
        let o2: _ProjectionRead__tr_env_start_open_door = other as _ProjectionRead__tr_env_start_open_door;
        return o1.valve_open_door.equals(o2.valve_open_door) && o1.door.equals(o2.door) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.general_valve.equals(o2.general_valve) && o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_open_door.hashCode() << 1);
        result = 31 * result + (this.door.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_env_start_open_door {

    public doors: BRelation<POSITION, DOOR_STATE>;
    public door: DOOR_STATE;

    constructor(doors : BRelation<POSITION, DOOR_STATE>, door : DOOR_STATE) {
        this.doors = doors;
        this.door = door;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_env_start_open_door = this;
        let o2: _ProjectionWrite_env_start_open_door = other as _ProjectionWrite_env_start_open_door;
        return o1.doors.equals(o2.doors) && o1.door.equals(o2.door);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.door.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_env_open_door_last {

    public valve_open_door: VALVE_STATE;
    public door: DOOR_STATE;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public general_valve: VALVE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(valve_open_door : VALVE_STATE, door : DOOR_STATE, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, general_valve : VALVE_STATE, gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.valve_open_door = valve_open_door;
        this.door = door;
        this.handle = handle;
        this.doors = doors;
        this.general_valve = general_valve;
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_env_open_door_last = this;
        let o2: _ProjectionRead_env_open_door_last = other as _ProjectionRead_env_open_door_last;
        return o1.valve_open_door.equals(o2.valve_open_door) && o1.door.equals(o2.door) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.general_valve.equals(o2.general_valve) && o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_open_door.hashCode() << 1);
        result = 31 * result + (this.door.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_env_open_door_last {

    public valve_open_door: VALVE_STATE;
    public door: DOOR_STATE;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public general_valve: VALVE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(valve_open_door : VALVE_STATE, door : DOOR_STATE, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, general_valve : VALVE_STATE, gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.valve_open_door = valve_open_door;
        this.door = door;
        this.handle = handle;
        this.doors = doors;
        this.general_valve = general_valve;
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_env_open_door_last = this;
        let o2: _ProjectionRead__tr_env_open_door_last = other as _ProjectionRead__tr_env_open_door_last;
        return o1.valve_open_door.equals(o2.valve_open_door) && o1.door.equals(o2.door) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.general_valve.equals(o2.general_valve) && o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_open_door.hashCode() << 1);
        result = 31 * result + (this.door.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_env_open_door_last {

    public doors: BRelation<POSITION, DOOR_STATE>;
    public door: DOOR_STATE;

    constructor(doors : BRelation<POSITION, DOOR_STATE>, door : DOOR_STATE) {
        this.doors = doors;
        this.door = door;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_env_open_door_last = this;
        let o2: _ProjectionWrite_env_open_door_last = other as _ProjectionWrite_env_open_door_last;
        return o1.doors.equals(o2.doors) && o1.door.equals(o2.door);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.door.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_env_open_door_skip {

    public valve_open_door: VALVE_STATE;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public general_valve: VALVE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(valve_open_door : VALVE_STATE, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, general_valve : VALVE_STATE, gears : BRelation<POSITION, GEAR_STATE>) {
        this.valve_open_door = valve_open_door;
        this.handle = handle;
        this.doors = doors;
        this.general_valve = general_valve;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_env_open_door_skip = this;
        let o2: _ProjectionRead_env_open_door_skip = other as _ProjectionRead_env_open_door_skip;
        return o1.valve_open_door.equals(o2.valve_open_door) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.general_valve.equals(o2.general_valve) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_open_door.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_env_open_door_skip {

    public valve_open_door: VALVE_STATE;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public general_valve: VALVE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(valve_open_door : VALVE_STATE, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, general_valve : VALVE_STATE, gears : BRelation<POSITION, GEAR_STATE>) {
        this.valve_open_door = valve_open_door;
        this.handle = handle;
        this.doors = doors;
        this.general_valve = general_valve;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_env_open_door_skip = this;
        let o2: _ProjectionRead__tr_env_open_door_skip = other as _ProjectionRead__tr_env_open_door_skip;
        return o1.valve_open_door.equals(o2.valve_open_door) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.general_valve.equals(o2.general_valve) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_open_door.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_env_open_door_skip {

    public doors: BRelation<POSITION, DOOR_STATE>;

    constructor(doors : BRelation<POSITION, DOOR_STATE>) {
        this.doors = doors;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_env_open_door_skip = this;
        let o2: _ProjectionWrite_env_open_door_skip = other as _ProjectionWrite_env_open_door_skip;
        return o1.doors.equals(o2.doors);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.doors.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_env_start_close_door {

    public door: DOOR_STATE;
    public valve_close_door: VALVE_STATE;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public general_valve: VALVE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(door : DOOR_STATE, valve_close_door : VALVE_STATE, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, general_valve : VALVE_STATE, gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.door = door;
        this.valve_close_door = valve_close_door;
        this.handle = handle;
        this.doors = doors;
        this.general_valve = general_valve;
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_env_start_close_door = this;
        let o2: _ProjectionRead_env_start_close_door = other as _ProjectionRead_env_start_close_door;
        return o1.door.equals(o2.door) && o1.valve_close_door.equals(o2.valve_close_door) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.general_valve.equals(o2.general_valve) && o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.door.hashCode() << 1);
        result = 31 * result + (this.valve_close_door.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_env_start_close_door {

    public door: DOOR_STATE;
    public valve_close_door: VALVE_STATE;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public general_valve: VALVE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(door : DOOR_STATE, valve_close_door : VALVE_STATE, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, general_valve : VALVE_STATE, gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.door = door;
        this.valve_close_door = valve_close_door;
        this.handle = handle;
        this.doors = doors;
        this.general_valve = general_valve;
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_env_start_close_door = this;
        let o2: _ProjectionRead__tr_env_start_close_door = other as _ProjectionRead__tr_env_start_close_door;
        return o1.door.equals(o2.door) && o1.valve_close_door.equals(o2.valve_close_door) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.general_valve.equals(o2.general_valve) && o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.door.hashCode() << 1);
        result = 31 * result + (this.valve_close_door.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_env_start_close_door {

    public doors: BRelation<POSITION, DOOR_STATE>;
    public door: DOOR_STATE;

    constructor(doors : BRelation<POSITION, DOOR_STATE>, door : DOOR_STATE) {
        this.doors = doors;
        this.door = door;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_env_start_close_door = this;
        let o2: _ProjectionWrite_env_start_close_door = other as _ProjectionWrite_env_start_close_door;
        return o1.doors.equals(o2.doors) && o1.door.equals(o2.door);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.door.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_env_close_door {

    public door: DOOR_STATE;
    public valve_close_door: VALVE_STATE;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public shock_absorber: PLANE_STATE;
    public general_valve: VALVE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(door : DOOR_STATE, valve_close_door : VALVE_STATE, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, shock_absorber : PLANE_STATE, general_valve : VALVE_STATE, gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.door = door;
        this.valve_close_door = valve_close_door;
        this.handle = handle;
        this.doors = doors;
        this.shock_absorber = shock_absorber;
        this.general_valve = general_valve;
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_env_close_door = this;
        let o2: _ProjectionRead_env_close_door = other as _ProjectionRead_env_close_door;
        return o1.door.equals(o2.door) && o1.valve_close_door.equals(o2.valve_close_door) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.shock_absorber.equals(o2.shock_absorber) && o1.general_valve.equals(o2.general_valve) && o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.door.hashCode() << 1);
        result = 31 * result + (this.valve_close_door.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.shock_absorber.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_env_close_door {

    public door: DOOR_STATE;
    public valve_close_door: VALVE_STATE;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public shock_absorber: PLANE_STATE;
    public general_valve: VALVE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(door : DOOR_STATE, valve_close_door : VALVE_STATE, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, shock_absorber : PLANE_STATE, general_valve : VALVE_STATE, gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.door = door;
        this.valve_close_door = valve_close_door;
        this.handle = handle;
        this.doors = doors;
        this.shock_absorber = shock_absorber;
        this.general_valve = general_valve;
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_env_close_door = this;
        let o2: _ProjectionRead__tr_env_close_door = other as _ProjectionRead__tr_env_close_door;
        return o1.door.equals(o2.door) && o1.valve_close_door.equals(o2.valve_close_door) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.shock_absorber.equals(o2.shock_absorber) && o1.general_valve.equals(o2.general_valve) && o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.door.hashCode() << 1);
        result = 31 * result + (this.valve_close_door.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.shock_absorber.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_env_close_door {

    public doors: BRelation<POSITION, DOOR_STATE>;
    public door: DOOR_STATE;

    constructor(doors : BRelation<POSITION, DOOR_STATE>, door : DOOR_STATE) {
        this.doors = doors;
        this.door = door;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_env_close_door = this;
        let o2: _ProjectionWrite_env_close_door = other as _ProjectionWrite_env_close_door;
        return o1.doors.equals(o2.doors) && o1.door.equals(o2.door);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.door.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_env_close_door_skip {

    public valve_close_door: VALVE_STATE;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public shock_absorber: PLANE_STATE;
    public general_valve: VALVE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(valve_close_door : VALVE_STATE, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, shock_absorber : PLANE_STATE, general_valve : VALVE_STATE, gears : BRelation<POSITION, GEAR_STATE>) {
        this.valve_close_door = valve_close_door;
        this.handle = handle;
        this.doors = doors;
        this.shock_absorber = shock_absorber;
        this.general_valve = general_valve;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_env_close_door_skip = this;
        let o2: _ProjectionRead_env_close_door_skip = other as _ProjectionRead_env_close_door_skip;
        return o1.valve_close_door.equals(o2.valve_close_door) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.shock_absorber.equals(o2.shock_absorber) && o1.general_valve.equals(o2.general_valve) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_close_door.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.shock_absorber.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_env_close_door_skip {

    public valve_close_door: VALVE_STATE;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public shock_absorber: PLANE_STATE;
    public general_valve: VALVE_STATE;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(valve_close_door : VALVE_STATE, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, shock_absorber : PLANE_STATE, general_valve : VALVE_STATE, gears : BRelation<POSITION, GEAR_STATE>) {
        this.valve_close_door = valve_close_door;
        this.handle = handle;
        this.doors = doors;
        this.shock_absorber = shock_absorber;
        this.general_valve = general_valve;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_env_close_door_skip = this;
        let o2: _ProjectionRead__tr_env_close_door_skip = other as _ProjectionRead__tr_env_close_door_skip;
        return o1.valve_close_door.equals(o2.valve_close_door) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.shock_absorber.equals(o2.shock_absorber) && o1.general_valve.equals(o2.general_valve) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_close_door.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.shock_absorber.hashCode() << 1);
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_env_close_door_skip {

    public doors: BRelation<POSITION, DOOR_STATE>;

    constructor(doors : BRelation<POSITION, DOOR_STATE>) {
        this.doors = doors;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_env_close_door_skip = this;
        let o2: _ProjectionWrite_env_close_door_skip = other as _ProjectionWrite_env_close_door_skip;
        return o1.doors.equals(o2.doors);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.doors.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_toggle_handle_up {

    public handle: HANDLE_STATE;

    constructor(handle : HANDLE_STATE) {
        this.handle = handle;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_toggle_handle_up = this;
        let o2: _ProjectionRead_toggle_handle_up = other as _ProjectionRead_toggle_handle_up;
        return o1.handle.equals(o2.handle);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.handle.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_toggle_handle_up {

    public handle: HANDLE_STATE;

    constructor(handle : HANDLE_STATE) {
        this.handle = handle;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_toggle_handle_up = this;
        let o2: _ProjectionRead__tr_toggle_handle_up = other as _ProjectionRead__tr_toggle_handle_up;
        return o1.handle.equals(o2.handle);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.handle.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_toggle_handle_up {

    public handle: HANDLE_STATE;
    public handle_move: BBoolean;

    constructor(handle : HANDLE_STATE, handle_move : BBoolean) {
        this.handle = handle;
        this.handle_move = handle_move;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_toggle_handle_up = this;
        let o2: _ProjectionWrite_toggle_handle_up = other as _ProjectionWrite_toggle_handle_up;
        return o1.handle.equals(o2.handle) && o1.handle_move.equals(o2.handle_move);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.handle_move.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_toggle_handle_down {

    public handle: HANDLE_STATE;

    constructor(handle : HANDLE_STATE) {
        this.handle = handle;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_toggle_handle_down = this;
        let o2: _ProjectionRead_toggle_handle_down = other as _ProjectionRead_toggle_handle_down;
        return o1.handle.equals(o2.handle);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.handle.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_toggle_handle_down {

    public handle: HANDLE_STATE;

    constructor(handle : HANDLE_STATE) {
        this.handle = handle;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_toggle_handle_down = this;
        let o2: _ProjectionRead__tr_toggle_handle_down = other as _ProjectionRead__tr_toggle_handle_down;
        return o1.handle.equals(o2.handle);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.handle.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_toggle_handle_down {

    public handle: HANDLE_STATE;
    public handle_move: BBoolean;

    constructor(handle : HANDLE_STATE, handle_move : BBoolean) {
        this.handle = handle;
        this.handle_move = handle_move;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_toggle_handle_down = this;
        let o2: _ProjectionWrite_toggle_handle_down = other as _ProjectionWrite_toggle_handle_down;
        return o1.handle.equals(o2.handle) && o1.handle_move.equals(o2.handle_move);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.handle_move.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_con_stimulate_general_valve {

    public handle_move: BBoolean;
    public general_EV: BBoolean;

    constructor(handle_move : BBoolean, general_EV : BBoolean) {
        this.handle_move = handle_move;
        this.general_EV = general_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_con_stimulate_general_valve = this;
        let o2: _ProjectionRead_con_stimulate_general_valve = other as _ProjectionRead_con_stimulate_general_valve;
        return o1.handle_move.equals(o2.handle_move) && o1.general_EV.equals(o2.general_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.handle_move.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_con_stimulate_general_valve {

    public handle_move: BBoolean;
    public general_EV: BBoolean;

    constructor(handle_move : BBoolean, general_EV : BBoolean) {
        this.handle_move = handle_move;
        this.general_EV = general_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_con_stimulate_general_valve = this;
        let o2: _ProjectionRead__tr_con_stimulate_general_valve = other as _ProjectionRead__tr_con_stimulate_general_valve;
        return o1.handle_move.equals(o2.handle_move) && o1.general_EV.equals(o2.general_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.handle_move.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_con_stimulate_general_valve {

    public general_EV: BBoolean;

    constructor(general_EV : BBoolean) {
        this.general_EV = general_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_con_stimulate_general_valve = this;
        let o2: _ProjectionWrite_con_stimulate_general_valve = other as _ProjectionWrite_con_stimulate_general_valve;
        return o1.general_EV.equals(o2.general_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.general_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_con_stop_stimulate_general_valve {

    public extend_EV: BBoolean;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public open_EV: BBoolean;
    public close_EV: BBoolean;
    public general_EV: BBoolean;
    public retract_EV: BBoolean;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(extend_EV : BBoolean, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, open_EV : BBoolean, close_EV : BBoolean, general_EV : BBoolean, retract_EV : BBoolean, gears : BRelation<POSITION, GEAR_STATE>) {
        this.extend_EV = extend_EV;
        this.handle = handle;
        this.doors = doors;
        this.open_EV = open_EV;
        this.close_EV = close_EV;
        this.general_EV = general_EV;
        this.retract_EV = retract_EV;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_con_stop_stimulate_general_valve = this;
        let o2: _ProjectionRead_con_stop_stimulate_general_valve = other as _ProjectionRead_con_stop_stimulate_general_valve;
        return o1.extend_EV.equals(o2.extend_EV) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.open_EV.equals(o2.open_EV) && o1.close_EV.equals(o2.close_EV) && o1.general_EV.equals(o2.general_EV) && o1.retract_EV.equals(o2.retract_EV) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.extend_EV.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.open_EV.hashCode() << 1);
        result = 31 * result + (this.close_EV.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        result = 31 * result + (this.retract_EV.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_con_stop_stimulate_general_valve {

    public extend_EV: BBoolean;
    public handle: HANDLE_STATE;
    public doors: BRelation<POSITION, DOOR_STATE>;
    public open_EV: BBoolean;
    public close_EV: BBoolean;
    public general_EV: BBoolean;
    public retract_EV: BBoolean;
    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(extend_EV : BBoolean, handle : HANDLE_STATE, doors : BRelation<POSITION, DOOR_STATE>, open_EV : BBoolean, close_EV : BBoolean, general_EV : BBoolean, retract_EV : BBoolean, gears : BRelation<POSITION, GEAR_STATE>) {
        this.extend_EV = extend_EV;
        this.handle = handle;
        this.doors = doors;
        this.open_EV = open_EV;
        this.close_EV = close_EV;
        this.general_EV = general_EV;
        this.retract_EV = retract_EV;
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_con_stop_stimulate_general_valve = this;
        let o2: _ProjectionRead__tr_con_stop_stimulate_general_valve = other as _ProjectionRead__tr_con_stop_stimulate_general_valve;
        return o1.extend_EV.equals(o2.extend_EV) && o1.handle.equals(o2.handle) && o1.doors.equals(o2.doors) && o1.open_EV.equals(o2.open_EV) && o1.close_EV.equals(o2.close_EV) && o1.general_EV.equals(o2.general_EV) && o1.retract_EV.equals(o2.retract_EV) && o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.extend_EV.hashCode() << 1);
        result = 31 * result + (this.handle.hashCode() << 1);
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.open_EV.hashCode() << 1);
        result = 31 * result + (this.close_EV.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        result = 31 * result + (this.retract_EV.hashCode() << 1);
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_con_stop_stimulate_general_valve {

    public handle_move: BBoolean;
    public general_EV: BBoolean;

    constructor(handle_move : BBoolean, general_EV : BBoolean) {
        this.handle_move = handle_move;
        this.general_EV = general_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_con_stop_stimulate_general_valve = this;
        let o2: _ProjectionWrite_con_stop_stimulate_general_valve = other as _ProjectionWrite_con_stop_stimulate_general_valve;
        return o1.handle_move.equals(o2.handle_move) && o1.general_EV.equals(o2.general_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.handle_move.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_evn_open_general_valve {

    public general_valve: VALVE_STATE;
    public analogical_switch: SWITCH_STATE;
    public general_EV: BBoolean;

    constructor(general_valve : VALVE_STATE, analogical_switch : SWITCH_STATE, general_EV : BBoolean) {
        this.general_valve = general_valve;
        this.analogical_switch = analogical_switch;
        this.general_EV = general_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_evn_open_general_valve = this;
        let o2: _ProjectionRead_evn_open_general_valve = other as _ProjectionRead_evn_open_general_valve;
        return o1.general_valve.equals(o2.general_valve) && o1.analogical_switch.equals(o2.analogical_switch) && o1.general_EV.equals(o2.general_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.analogical_switch.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_evn_open_general_valve {

    public general_valve: VALVE_STATE;
    public analogical_switch: SWITCH_STATE;
    public general_EV: BBoolean;

    constructor(general_valve : VALVE_STATE, analogical_switch : SWITCH_STATE, general_EV : BBoolean) {
        this.general_valve = general_valve;
        this.analogical_switch = analogical_switch;
        this.general_EV = general_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_evn_open_general_valve = this;
        let o2: _ProjectionRead__tr_evn_open_general_valve = other as _ProjectionRead__tr_evn_open_general_valve;
        return o1.general_valve.equals(o2.general_valve) && o1.analogical_switch.equals(o2.analogical_switch) && o1.general_EV.equals(o2.general_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.analogical_switch.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_evn_open_general_valve {

    public general_valve: VALVE_STATE;

    constructor(general_valve : VALVE_STATE) {
        this.general_valve = general_valve;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_evn_open_general_valve = this;
        let o2: _ProjectionWrite_evn_open_general_valve = other as _ProjectionWrite_evn_open_general_valve;
        return o1.general_valve.equals(o2.general_valve);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.general_valve.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_evn_close_general_valve {

    public general_valve: VALVE_STATE;
    public analogical_switch: SWITCH_STATE;
    public general_EV: BBoolean;

    constructor(general_valve : VALVE_STATE, analogical_switch : SWITCH_STATE, general_EV : BBoolean) {
        this.general_valve = general_valve;
        this.analogical_switch = analogical_switch;
        this.general_EV = general_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_evn_close_general_valve = this;
        let o2: _ProjectionRead_evn_close_general_valve = other as _ProjectionRead_evn_close_general_valve;
        return o1.general_valve.equals(o2.general_valve) && o1.analogical_switch.equals(o2.analogical_switch) && o1.general_EV.equals(o2.general_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.analogical_switch.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_evn_close_general_valve {

    public general_valve: VALVE_STATE;
    public analogical_switch: SWITCH_STATE;
    public general_EV: BBoolean;

    constructor(general_valve : VALVE_STATE, analogical_switch : SWITCH_STATE, general_EV : BBoolean) {
        this.general_valve = general_valve;
        this.analogical_switch = analogical_switch;
        this.general_EV = general_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_evn_close_general_valve = this;
        let o2: _ProjectionRead__tr_evn_close_general_valve = other as _ProjectionRead__tr_evn_close_general_valve;
        return o1.general_valve.equals(o2.general_valve) && o1.analogical_switch.equals(o2.analogical_switch) && o1.general_EV.equals(o2.general_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.general_valve.hashCode() << 1);
        result = 31 * result + (this.analogical_switch.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_evn_close_general_valve {

    public general_valve: VALVE_STATE;

    constructor(general_valve : VALVE_STATE) {
        this.general_valve = general_valve;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_evn_close_general_valve = this;
        let o2: _ProjectionWrite_evn_close_general_valve = other as _ProjectionWrite_evn_close_general_valve;
        return o1.general_valve.equals(o2.general_valve);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.general_valve.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_env_close_analogical_switch {

    public analogical_switch: SWITCH_STATE;
    public handle_move: BBoolean;

    constructor(analogical_switch : SWITCH_STATE, handle_move : BBoolean) {
        this.analogical_switch = analogical_switch;
        this.handle_move = handle_move;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_env_close_analogical_switch = this;
        let o2: _ProjectionRead_env_close_analogical_switch = other as _ProjectionRead_env_close_analogical_switch;
        return o1.analogical_switch.equals(o2.analogical_switch) && o1.handle_move.equals(o2.handle_move);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.analogical_switch.hashCode() << 1);
        result = 31 * result + (this.handle_move.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_env_close_analogical_switch {

    public analogical_switch: SWITCH_STATE;
    public handle_move: BBoolean;

    constructor(analogical_switch : SWITCH_STATE, handle_move : BBoolean) {
        this.analogical_switch = analogical_switch;
        this.handle_move = handle_move;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_env_close_analogical_switch = this;
        let o2: _ProjectionRead__tr_env_close_analogical_switch = other as _ProjectionRead__tr_env_close_analogical_switch;
        return o1.analogical_switch.equals(o2.analogical_switch) && o1.handle_move.equals(o2.handle_move);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.analogical_switch.hashCode() << 1);
        result = 31 * result + (this.handle_move.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_env_close_analogical_switch {

    public analogical_switch: SWITCH_STATE;

    constructor(analogical_switch : SWITCH_STATE) {
        this.analogical_switch = analogical_switch;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_env_close_analogical_switch = this;
        let o2: _ProjectionWrite_env_close_analogical_switch = other as _ProjectionWrite_env_close_analogical_switch;
        return o1.analogical_switch.equals(o2.analogical_switch);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.analogical_switch.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_env_open_analogical_switch {

    public analogical_switch: SWITCH_STATE;

    constructor(analogical_switch : SWITCH_STATE) {
        this.analogical_switch = analogical_switch;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_env_open_analogical_switch = this;
        let o2: _ProjectionRead_env_open_analogical_switch = other as _ProjectionRead_env_open_analogical_switch;
        return o1.analogical_switch.equals(o2.analogical_switch);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.analogical_switch.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_env_open_analogical_switch {

    public analogical_switch: SWITCH_STATE;

    constructor(analogical_switch : SWITCH_STATE) {
        this.analogical_switch = analogical_switch;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_env_open_analogical_switch = this;
        let o2: _ProjectionRead__tr_env_open_analogical_switch = other as _ProjectionRead__tr_env_open_analogical_switch;
        return o1.analogical_switch.equals(o2.analogical_switch);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.analogical_switch.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_env_open_analogical_switch {

    public analogical_switch: SWITCH_STATE;

    constructor(analogical_switch : SWITCH_STATE) {
        this.analogical_switch = analogical_switch;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_env_open_analogical_switch = this;
        let o2: _ProjectionWrite_env_open_analogical_switch = other as _ProjectionWrite_env_open_analogical_switch;
        return o1.analogical_switch.equals(o2.analogical_switch);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.analogical_switch.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_1 {

    public analogical_switch: SWITCH_STATE;

    constructor(analogical_switch : SWITCH_STATE) {
        this.analogical_switch = analogical_switch;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_1 = this;
        let o2: _ProjectionRead__check_inv_1 = other as _ProjectionRead__check_inv_1;
        return o1.analogical_switch.equals(o2.analogical_switch);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.analogical_switch.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_2 {

    public general_EV: BBoolean;

    constructor(general_EV : BBoolean) {
        this.general_EV = general_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_2 = this;
        let o2: _ProjectionRead__check_inv_2 = other as _ProjectionRead__check_inv_2;
        return o1.general_EV.equals(o2.general_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.general_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_3 {

    public general_valve: VALVE_STATE;

    constructor(general_valve : VALVE_STATE) {
        this.general_valve = general_valve;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_3 = this;
        let o2: _ProjectionRead__check_inv_3 = other as _ProjectionRead__check_inv_3;
        return o1.general_valve.equals(o2.general_valve);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.general_valve.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_4 {

    public handle_move: BBoolean;

    constructor(handle_move : BBoolean) {
        this.handle_move = handle_move;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_4 = this;
        let o2: _ProjectionRead__check_inv_4 = other as _ProjectionRead__check_inv_4;
        return o1.handle_move.equals(o2.handle_move);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.handle_move.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_5 {

    public close_EV: BBoolean;

    constructor(close_EV : BBoolean) {
        this.close_EV = close_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_5 = this;
        let o2: _ProjectionRead__check_inv_5 = other as _ProjectionRead__check_inv_5;
        return o1.close_EV.equals(o2.close_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.close_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_6 {

    public extend_EV: BBoolean;

    constructor(extend_EV : BBoolean) {
        this.extend_EV = extend_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_6 = this;
        let o2: _ProjectionRead__check_inv_6 = other as _ProjectionRead__check_inv_6;
        return o1.extend_EV.equals(o2.extend_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.extend_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_7 {

    public open_EV: BBoolean;

    constructor(open_EV : BBoolean) {
        this.open_EV = open_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_7 = this;
        let o2: _ProjectionRead__check_inv_7 = other as _ProjectionRead__check_inv_7;
        return o1.open_EV.equals(o2.open_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.open_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_8 {

    public retract_EV: BBoolean;

    constructor(retract_EV : BBoolean) {
        this.retract_EV = retract_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_8 = this;
        let o2: _ProjectionRead__check_inv_8 = other as _ProjectionRead__check_inv_8;
        return o1.retract_EV.equals(o2.retract_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.retract_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_9 {

    public shock_absorber: PLANE_STATE;

    constructor(shock_absorber : PLANE_STATE) {
        this.shock_absorber = shock_absorber;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_9 = this;
        let o2: _ProjectionRead__check_inv_9 = other as _ProjectionRead__check_inv_9;
        return o1.shock_absorber.equals(o2.shock_absorber);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.shock_absorber.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_10 {

    public valve_close_door: VALVE_STATE;

    constructor(valve_close_door : VALVE_STATE) {
        this.valve_close_door = valve_close_door;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_10 = this;
        let o2: _ProjectionRead__check_inv_10 = other as _ProjectionRead__check_inv_10;
        return o1.valve_close_door.equals(o2.valve_close_door);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_close_door.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_11 {

    public valve_extend_gear: VALVE_STATE;

    constructor(valve_extend_gear : VALVE_STATE) {
        this.valve_extend_gear = valve_extend_gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_11 = this;
        let o2: _ProjectionRead__check_inv_11 = other as _ProjectionRead__check_inv_11;
        return o1.valve_extend_gear.equals(o2.valve_extend_gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_extend_gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_12 {

    public valve_open_door: VALVE_STATE;

    constructor(valve_open_door : VALVE_STATE) {
        this.valve_open_door = valve_open_door;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_12 = this;
        let o2: _ProjectionRead__check_inv_12 = other as _ProjectionRead__check_inv_12;
        return o1.valve_open_door.equals(o2.valve_open_door);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_open_door.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_13 {

    public valve_retract_gear: VALVE_STATE;

    constructor(valve_retract_gear : VALVE_STATE) {
        this.valve_retract_gear = valve_retract_gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_13 = this;
        let o2: _ProjectionRead__check_inv_13 = other as _ProjectionRead__check_inv_13;
        return o1.valve_retract_gear.equals(o2.valve_retract_gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.valve_retract_gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_14 {

    public handle: HANDLE_STATE;

    constructor(handle : HANDLE_STATE) {
        this.handle = handle;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_14 = this;
        let o2: _ProjectionRead__check_inv_14 = other as _ProjectionRead__check_inv_14;
        return o1.handle.equals(o2.handle);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.handle.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_15 {

    public door: DOOR_STATE;

    constructor(door : DOOR_STATE) {
        this.door = door;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_15 = this;
        let o2: _ProjectionRead__check_inv_15 = other as _ProjectionRead__check_inv_15;
        return o1.door.equals(o2.door);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.door.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_16 {

    public gear: GEAR_STATE;

    constructor(gear : GEAR_STATE) {
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_16 = this;
        let o2: _ProjectionRead__check_inv_16 = other as _ProjectionRead__check_inv_16;
        return o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_17 {

    public extend_EV: BBoolean;
    public open_EV: BBoolean;
    public close_EV: BBoolean;
    public general_EV: BBoolean;
    public retract_EV: BBoolean;

    constructor(extend_EV : BBoolean, open_EV : BBoolean, close_EV : BBoolean, general_EV : BBoolean, retract_EV : BBoolean) {
        this.extend_EV = extend_EV;
        this.open_EV = open_EV;
        this.close_EV = close_EV;
        this.general_EV = general_EV;
        this.retract_EV = retract_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_17 = this;
        let o2: _ProjectionRead__check_inv_17 = other as _ProjectionRead__check_inv_17;
        return o1.extend_EV.equals(o2.extend_EV) && o1.open_EV.equals(o2.open_EV) && o1.close_EV.equals(o2.close_EV) && o1.general_EV.equals(o2.general_EV) && o1.retract_EV.equals(o2.retract_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.extend_EV.hashCode() << 1);
        result = 31 * result + (this.open_EV.hashCode() << 1);
        result = 31 * result + (this.close_EV.hashCode() << 1);
        result = 31 * result + (this.general_EV.hashCode() << 1);
        result = 31 * result + (this.retract_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_18 {

    public open_EV: BBoolean;
    public close_EV: BBoolean;

    constructor(open_EV : BBoolean, close_EV : BBoolean) {
        this.open_EV = open_EV;
        this.close_EV = close_EV;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_18 = this;
        let o2: _ProjectionRead__check_inv_18 = other as _ProjectionRead__check_inv_18;
        return o1.open_EV.equals(o2.open_EV) && o1.close_EV.equals(o2.close_EV);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.open_EV.hashCode() << 1);
        result = 31 * result + (this.close_EV.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_19 {

    public gears: BRelation<POSITION, GEAR_STATE>;

    constructor(gears : BRelation<POSITION, GEAR_STATE>) {
        this.gears = gears;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_19 = this;
        let o2: _ProjectionRead__check_inv_19 = other as _ProjectionRead__check_inv_19;
        return o1.gears.equals(o2.gears);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.gears.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_20 {

    public doors: BRelation<POSITION, DOOR_STATE>;

    constructor(doors : BRelation<POSITION, DOOR_STATE>) {
        this.doors = doors;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_20 = this;
        let o2: _ProjectionRead__check_inv_20 = other as _ProjectionRead__check_inv_20;
        return o1.doors.equals(o2.doors);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.doors.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_21 {

    public doors: BRelation<POSITION, DOOR_STATE>;
    public door: DOOR_STATE;

    constructor(doors : BRelation<POSITION, DOOR_STATE>, door : DOOR_STATE) {
        this.doors = doors;
        this.door = door;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_21 = this;
        let o2: _ProjectionRead__check_inv_21 = other as _ProjectionRead__check_inv_21;
        return o1.doors.equals(o2.doors) && o1.door.equals(o2.door);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.door.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_22 {

    public doors: BRelation<POSITION, DOOR_STATE>;
    public door: DOOR_STATE;

    constructor(doors : BRelation<POSITION, DOOR_STATE>, door : DOOR_STATE) {
        this.doors = doors;
        this.door = door;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_22 = this;
        let o2: _ProjectionRead__check_inv_22 = other as _ProjectionRead__check_inv_22;
        return o1.doors.equals(o2.doors) && o1.door.equals(o2.door);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.doors.hashCode() << 1);
        result = 31 * result + (this.door.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_23 {

    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_23 = this;
        let o2: _ProjectionRead__check_inv_23 = other as _ProjectionRead__check_inv_23;
        return o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_24 {

    public gears: BRelation<POSITION, GEAR_STATE>;
    public gear: GEAR_STATE;

    constructor(gears : BRelation<POSITION, GEAR_STATE>, gear : GEAR_STATE) {
        this.gears = gears;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_24 = this;
        let o2: _ProjectionRead__check_inv_24 = other as _ProjectionRead__check_inv_24;
        return o1.gears.equals(o2.gears) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.gears.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_25 {

    public door: DOOR_STATE;
    public gear: GEAR_STATE;

    constructor(door : DOOR_STATE, gear : GEAR_STATE) {
        this.door = door;
        this.gear = gear;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_25 = this;
        let o2: _ProjectionRead__check_inv_25 = other as _ProjectionRead__check_inv_25;
        return o1.door.equals(o2.door) && o1.gear.equals(o2.gear);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.door.hashCode() << 1);
        result = 31 * result + (this.gear.hashCode() << 1);
        return result;
    }
}


export enum Type {
    BFS,
    DFS,
    MIXED
}

export default class LandingGear_R6 {

    parent: LandingGear_R6;
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
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.closed)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.isNotInRange(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.closed), new DOOR_STATE(enum_DOOR_STATE.door_moving)).elementOf(this.door).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
                _ic_set_24 = _ic_set_24.union(new BSet<POSITION>(_ic_gr_1));
            }

        }

        return _ic_set_24;
    }

    _tr_env_open_door_last(): BSet<POSITION> {
        let _ic_set_25: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.isNotInRange(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet<POSITION>(_ic_gr_1))).equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
                _ic_set_25 = _ic_set_25.union(new BSet<POSITION>(_ic_gr_1));
            }

        }

        return _ic_set_25;
    }

    _tr_env_open_door_skip(): BSet<POSITION> {
        let _ic_set_26: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.isNotInRange(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet<POSITION>(_ic_gr_1))).unequal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
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
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.isNotInRange(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet<POSITION>(_ic_gr_1))).equal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended), new GEAR_STATE(enum_GEAR_STATE.retracted)).elementOf(this.gear).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
                _ic_set_28 = _ic_set_28.union(new BSet<POSITION>(_ic_gr_1));
            }

        }

        return _ic_set_28;
    }

    _tr_env_close_door_skip(): BSet<POSITION> {
        let _ic_set_29: BSet<POSITION> = new BSet<POSITION>();
        for(let _ic_gr_1 of this.gears.domain()) {
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.isNotInRange(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet<POSITION>(_ic_gr_1))).unequal(new BSet<DOOR_STATE>(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet<GEAR_STATE>(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
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

    _projected_state_for_close_valve_door_close(): _ProjectionRead_close_valve_door_close {
        return new _ProjectionRead_close_valve_door_close(this.valve_close_door,this.close_EV);
    }

    _projected_state_for_close_valve_retract_gear(): _ProjectionRead_close_valve_retract_gear {
        return new _ProjectionRead_close_valve_retract_gear(this.valve_retract_gear,this.retract_EV);
    }

    _projected_state_for_con_stimulate_open_door_valve(): _ProjectionRead_con_stimulate_open_door_valve {
        return new _ProjectionRead_con_stimulate_open_door_valve(this.handle,this.doors,this.open_EV,this.shock_absorber,this.close_EV,this.general_EV,this.gears);
    }

    _projected_state_for_env_close_door(): _ProjectionRead_env_close_door {
        return new _ProjectionRead_env_close_door(this.door,this.valve_close_door,this.handle,this.doors,this.shock_absorber,this.general_valve,this.gears,this.gear);
    }

    _projected_state_for_env_start_close_door(): _ProjectionRead_env_start_close_door {
        return new _ProjectionRead_env_start_close_door(this.door,this.valve_close_door,this.handle,this.doors,this.general_valve,this.gears,this.gear);
    }

    _projected_state_for_toggle_handle_up(): _ProjectionRead_toggle_handle_up {
        return new _ProjectionRead_toggle_handle_up(this.handle);
    }

    _projected_state_for_toggle_handle_down(): _ProjectionRead_toggle_handle_down {
        return new _ProjectionRead_toggle_handle_down(this.handle);
    }

    _projected_state_for_open_valve_door_open(): _ProjectionRead_open_valve_door_open {
        return new _ProjectionRead_open_valve_door_open(this.valve_open_door,this.open_EV);
    }

    _projected_state_for_env_retract_gear_last(): _ProjectionRead_env_retract_gear_last {
        return new _ProjectionRead_env_retract_gear_last(this.door,this.handle,this.doors,this.general_valve,this.gears,this.gear);
    }

    _projected_state_for_env_open_door_last(): _ProjectionRead_env_open_door_last {
        return new _ProjectionRead_env_open_door_last(this.valve_open_door,this.door,this.handle,this.doors,this.general_valve,this.gears,this.gear);
    }

    _projected_state_for_con_stop_stimulate_retract_gear_valve(): _ProjectionRead_con_stop_stimulate_retract_gear_valve {
        return new _ProjectionRead_con_stop_stimulate_retract_gear_valve(this.handle,this.general_EV,this.retract_EV,this.gears);
    }

    _projected_state_for_env_close_door_skip(): _ProjectionRead_env_close_door_skip {
        return new _ProjectionRead_env_close_door_skip(this.valve_close_door,this.handle,this.doors,this.shock_absorber,this.general_valve,this.gears);
    }

    _projected_state_for_con_stop_stimulate_close_door_valve(): _ProjectionRead_con_stop_stimulate_close_door_valve {
        return new _ProjectionRead_con_stop_stimulate_close_door_valve(this.doors,this.shock_absorber,this.handle,this.close_EV,this.general_EV,this.gears);
    }

    _projected_state_for_env_open_analogical_switch(): _ProjectionRead_env_open_analogical_switch {
        return new _ProjectionRead_env_open_analogical_switch(this.analogical_switch);
    }

    _projected_state_for_con_stop_stimulate_general_valve(): _ProjectionRead_con_stop_stimulate_general_valve {
        return new _ProjectionRead_con_stop_stimulate_general_valve(this.extend_EV,this.handle,this.doors,this.open_EV,this.close_EV,this.general_EV,this.retract_EV,this.gears);
    }

    _projected_state_for_env_extend_gear_last(): _ProjectionRead_env_extend_gear_last {
        return new _ProjectionRead_env_extend_gear_last(this.door,this.handle,this.doors,this.general_valve,this.gears,this.gear);
    }

    _projected_state_for_evn_open_general_valve(): _ProjectionRead_evn_open_general_valve {
        return new _ProjectionRead_evn_open_general_valve(this.general_valve,this.analogical_switch,this.general_EV);
    }

    _projected_state_for_land_plane(): _ProjectionRead_land_plane {
        return new _ProjectionRead_land_plane(this.shock_absorber);
    }

    _projected_state_for_con_stimulate_retract_gear_valve(): _ProjectionRead_con_stimulate_retract_gear_valve {
        return new _ProjectionRead_con_stimulate_retract_gear_valve(this.extend_EV,this.doors,this.open_EV,this.shock_absorber,this.handle,this.general_EV,this.retract_EV,this.gears);
    }

    _projected_state_for_con_stimulate_general_valve(): _ProjectionRead_con_stimulate_general_valve {
        return new _ProjectionRead_con_stimulate_general_valve(this.handle_move,this.general_EV);
    }

    _projected_state_for_env_start_retracting_first(): _ProjectionRead_env_start_retracting_first {
        return new _ProjectionRead_env_start_retracting_first(this.door,this.handle,this.valve_retract_gear,this.doors,this.general_valve,this.gears,this.gear);
    }

    _projected_state_for_env_retract_gear_skip(): _ProjectionRead_env_retract_gear_skip {
        return new _ProjectionRead_env_retract_gear_skip(this.doors,this.general_valve,this.handle,this.gears);
    }

    _projected_state_for_open_valve_extend_gear(): _ProjectionRead_open_valve_extend_gear {
        return new _ProjectionRead_open_valve_extend_gear(this.extend_EV,this.valve_extend_gear);
    }

    _projected_state_for_begin_flying(): _ProjectionRead_begin_flying {
        return new _ProjectionRead_begin_flying(this.shock_absorber);
    }

    _projected_state_for_open_valve_retract_gear(): _ProjectionRead_open_valve_retract_gear {
        return new _ProjectionRead_open_valve_retract_gear(this.valve_retract_gear,this.retract_EV);
    }

    _projected_state_for_env_close_analogical_switch(): _ProjectionRead_env_close_analogical_switch {
        return new _ProjectionRead_env_close_analogical_switch(this.analogical_switch,this.handle_move);
    }

    _projected_state_for_env_start_extending(): _ProjectionRead_env_start_extending {
        return new _ProjectionRead_env_start_extending(this.door,this.handle,this.doors,this.general_valve,this.valve_extend_gear,this.gears,this.gear);
    }

    _projected_state_for_open_valve_door_close(): _ProjectionRead_open_valve_door_close {
        return new _ProjectionRead_open_valve_door_close(this.valve_close_door,this.close_EV);
    }

    _projected_state_for_con_stop_stimulate_open_door_valve(): _ProjectionRead_con_stop_stimulate_open_door_valve {
        return new _ProjectionRead_con_stop_stimulate_open_door_valve(this.extend_EV,this.handle,this.doors,this.open_EV,this.shock_absorber,this.general_EV,this.retract_EV,this.gears);
    }

    _projected_state_for_con_stop_stimulate_extend_gear_valve(): _ProjectionRead_con_stop_stimulate_extend_gear_valve {
        return new _ProjectionRead_con_stop_stimulate_extend_gear_valve(this.extend_EV,this.handle,this.general_EV,this.gears);
    }

    _projected_state_for_evn_close_general_valve(): _ProjectionRead_evn_close_general_valve {
        return new _ProjectionRead_evn_close_general_valve(this.general_valve,this.analogical_switch,this.general_EV);
    }

    _projected_state_for_close_valve_extend_gear(): _ProjectionRead_close_valve_extend_gear {
        return new _ProjectionRead_close_valve_extend_gear(this.extend_EV,this.valve_extend_gear);
    }

    _projected_state_for_con_stimulate_extend_gear_valve(): _ProjectionRead_con_stimulate_extend_gear_valve {
        return new _ProjectionRead_con_stimulate_extend_gear_valve(this.extend_EV,this.doors,this.open_EV,this.handle,this.general_EV,this.retract_EV,this.gears);
    }

    _projected_state_for_close_valve_door_open(): _ProjectionRead_close_valve_door_open {
        return new _ProjectionRead_close_valve_door_open(this.valve_open_door,this.open_EV);
    }

    _projected_state_for_con_stimulate_close_door_valve(): _ProjectionRead_con_stimulate_close_door_valve {
        return new _ProjectionRead_con_stimulate_close_door_valve(this.extend_EV,this.handle,this.doors,this.open_EV,this.shock_absorber,this.close_EV,this.general_EV,this.retract_EV,this.gears);
    }

    _projected_state_for_env_extend_gear_skip(): _ProjectionRead_env_extend_gear_skip {
        return new _ProjectionRead_env_extend_gear_skip(this.doors,this.general_valve,this.handle,this.gears);
    }

    _projected_state_for_env_open_door_skip(): _ProjectionRead_env_open_door_skip {
        return new _ProjectionRead_env_open_door_skip(this.valve_open_door,this.handle,this.doors,this.general_valve,this.gears);
    }

    _projected_state_for_env_start_open_door(): _ProjectionRead_env_start_open_door {
        return new _ProjectionRead_env_start_open_door(this.valve_open_door,this.door,this.handle,this.doors,this.general_valve,this.gears,this.gear);
    }

    _projected_state_for__tr_env_retract_gear_last(): _ProjectionRead__tr_env_retract_gear_last {
        return new _ProjectionRead__tr_env_retract_gear_last(this.door,this.handle,this.doors,this.general_valve,this.gears,this.gear);
    }

    _projected_state_for__tr_open_valve_door_open(): _ProjectionRead__tr_open_valve_door_open {
        return new _ProjectionRead__tr_open_valve_door_open(this.valve_open_door,this.open_EV);
    }

    _projected_state_for__tr_env_open_analogical_switch(): _ProjectionRead__tr_env_open_analogical_switch {
        return new _ProjectionRead__tr_env_open_analogical_switch(this.analogical_switch);
    }

    _projected_state_for__tr_con_stimulate_extend_gear_valve(): _ProjectionRead__tr_con_stimulate_extend_gear_valve {
        return new _ProjectionRead__tr_con_stimulate_extend_gear_valve(this.extend_EV,this.doors,this.open_EV,this.handle,this.general_EV,this.retract_EV,this.gears);
    }

    _projected_state_for__tr_env_close_door_skip(): _ProjectionRead__tr_env_close_door_skip {
        return new _ProjectionRead__tr_env_close_door_skip(this.valve_close_door,this.handle,this.doors,this.shock_absorber,this.general_valve,this.gears);
    }

    _projected_state_for__tr_con_stop_stimulate_open_door_valve(): _ProjectionRead__tr_con_stop_stimulate_open_door_valve {
        return new _ProjectionRead__tr_con_stop_stimulate_open_door_valve(this.extend_EV,this.handle,this.doors,this.open_EV,this.shock_absorber,this.general_EV,this.retract_EV,this.gears);
    }

    _projected_state_for__tr_con_stimulate_close_door_valve(): _ProjectionRead__tr_con_stimulate_close_door_valve {
        return new _ProjectionRead__tr_con_stimulate_close_door_valve(this.extend_EV,this.handle,this.doors,this.open_EV,this.shock_absorber,this.close_EV,this.general_EV,this.retract_EV,this.gears);
    }

    _projected_state_for__tr_env_close_analogical_switch(): _ProjectionRead__tr_env_close_analogical_switch {
        return new _ProjectionRead__tr_env_close_analogical_switch(this.analogical_switch,this.handle_move);
    }

    _projected_state_for__tr_evn_close_general_valve(): _ProjectionRead__tr_evn_close_general_valve {
        return new _ProjectionRead__tr_evn_close_general_valve(this.general_valve,this.analogical_switch,this.general_EV);
    }

    _projected_state_for__tr_con_stop_stimulate_retract_gear_valve(): _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve {
        return new _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve(this.handle,this.general_EV,this.retract_EV,this.gears);
    }

    _projected_state_for__tr_land_plane(): _ProjectionRead__tr_land_plane {
        return new _ProjectionRead__tr_land_plane(this.shock_absorber);
    }

    _projected_state_for__tr_open_valve_door_close(): _ProjectionRead__tr_open_valve_door_close {
        return new _ProjectionRead__tr_open_valve_door_close(this.valve_close_door,this.close_EV);
    }

    _projected_state_for__tr_con_stop_stimulate_general_valve(): _ProjectionRead__tr_con_stop_stimulate_general_valve {
        return new _ProjectionRead__tr_con_stop_stimulate_general_valve(this.extend_EV,this.handle,this.doors,this.open_EV,this.close_EV,this.general_EV,this.retract_EV,this.gears);
    }

    _projected_state_for__tr_con_stimulate_open_door_valve(): _ProjectionRead__tr_con_stimulate_open_door_valve {
        return new _ProjectionRead__tr_con_stimulate_open_door_valve(this.handle,this.doors,this.open_EV,this.shock_absorber,this.close_EV,this.general_EV,this.gears);
    }

    _projected_state_for__tr_env_start_extending(): _ProjectionRead__tr_env_start_extending {
        return new _ProjectionRead__tr_env_start_extending(this.door,this.handle,this.doors,this.general_valve,this.valve_extend_gear,this.gears,this.gear);
    }

    _projected_state_for__tr_env_extend_gear_last(): _ProjectionRead__tr_env_extend_gear_last {
        return new _ProjectionRead__tr_env_extend_gear_last(this.door,this.handle,this.doors,this.general_valve,this.gears,this.gear);
    }

    _projected_state_for__tr_env_open_door_skip(): _ProjectionRead__tr_env_open_door_skip {
        return new _ProjectionRead__tr_env_open_door_skip(this.valve_open_door,this.handle,this.doors,this.general_valve,this.gears);
    }

    _projected_state_for__tr_close_valve_retract_gear(): _ProjectionRead__tr_close_valve_retract_gear {
        return new _ProjectionRead__tr_close_valve_retract_gear(this.valve_retract_gear,this.retract_EV);
    }

    _projected_state_for__tr_close_valve_extend_gear(): _ProjectionRead__tr_close_valve_extend_gear {
        return new _ProjectionRead__tr_close_valve_extend_gear(this.extend_EV,this.valve_extend_gear);
    }

    _projected_state_for__tr_con_stimulate_general_valve(): _ProjectionRead__tr_con_stimulate_general_valve {
        return new _ProjectionRead__tr_con_stimulate_general_valve(this.handle_move,this.general_EV);
    }

    _projected_state_for__tr_open_valve_extend_gear(): _ProjectionRead__tr_open_valve_extend_gear {
        return new _ProjectionRead__tr_open_valve_extend_gear(this.extend_EV,this.valve_extend_gear);
    }

    _projected_state_for__tr_con_stimulate_retract_gear_valve(): _ProjectionRead__tr_con_stimulate_retract_gear_valve {
        return new _ProjectionRead__tr_con_stimulate_retract_gear_valve(this.extend_EV,this.doors,this.open_EV,this.shock_absorber,this.handle,this.general_EV,this.retract_EV,this.gears);
    }

    _projected_state_for__tr_evn_open_general_valve(): _ProjectionRead__tr_evn_open_general_valve {
        return new _ProjectionRead__tr_evn_open_general_valve(this.general_valve,this.analogical_switch,this.general_EV);
    }

    _projected_state_for__tr_env_retract_gear_skip(): _ProjectionRead__tr_env_retract_gear_skip {
        return new _ProjectionRead__tr_env_retract_gear_skip(this.doors,this.general_valve,this.handle,this.gears);
    }

    _projected_state_for__tr_env_start_open_door(): _ProjectionRead__tr_env_start_open_door {
        return new _ProjectionRead__tr_env_start_open_door(this.valve_open_door,this.door,this.handle,this.doors,this.general_valve,this.gears,this.gear);
    }

    _projected_state_for__tr_env_close_door(): _ProjectionRead__tr_env_close_door {
        return new _ProjectionRead__tr_env_close_door(this.door,this.valve_close_door,this.handle,this.doors,this.shock_absorber,this.general_valve,this.gears,this.gear);
    }

    _projected_state_for__tr_con_stop_stimulate_extend_gear_valve(): _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve {
        return new _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve(this.extend_EV,this.handle,this.general_EV,this.gears);
    }

    _projected_state_for__tr_close_valve_door_open(): _ProjectionRead__tr_close_valve_door_open {
        return new _ProjectionRead__tr_close_valve_door_open(this.valve_open_door,this.open_EV);
    }

    _projected_state_for__tr_env_start_retracting_first(): _ProjectionRead__tr_env_start_retracting_first {
        return new _ProjectionRead__tr_env_start_retracting_first(this.door,this.handle,this.valve_retract_gear,this.doors,this.general_valve,this.gears,this.gear);
    }

    _projected_state_for__tr_env_extend_gear_skip(): _ProjectionRead__tr_env_extend_gear_skip {
        return new _ProjectionRead__tr_env_extend_gear_skip(this.doors,this.general_valve,this.handle,this.gears);
    }

    _projected_state_for__tr_toggle_handle_down(): _ProjectionRead__tr_toggle_handle_down {
        return new _ProjectionRead__tr_toggle_handle_down(this.handle);
    }

    _projected_state_for__tr_begin_flying(): _ProjectionRead__tr_begin_flying {
        return new _ProjectionRead__tr_begin_flying(this.shock_absorber);
    }

    _projected_state_for__tr_open_valve_retract_gear(): _ProjectionRead__tr_open_valve_retract_gear {
        return new _ProjectionRead__tr_open_valve_retract_gear(this.valve_retract_gear,this.retract_EV);
    }

    _projected_state_for__tr_env_open_door_last(): _ProjectionRead__tr_env_open_door_last {
        return new _ProjectionRead__tr_env_open_door_last(this.valve_open_door,this.door,this.handle,this.doors,this.general_valve,this.gears,this.gear);
    }

    _projected_state_for__tr_toggle_handle_up(): _ProjectionRead__tr_toggle_handle_up {
        return new _ProjectionRead__tr_toggle_handle_up(this.handle);
    }

    _projected_state_for__tr_env_start_close_door(): _ProjectionRead__tr_env_start_close_door {
        return new _ProjectionRead__tr_env_start_close_door(this.door,this.valve_close_door,this.handle,this.doors,this.general_valve,this.gears,this.gear);
    }

    _projected_state_for__tr_con_stop_stimulate_close_door_valve(): _ProjectionRead__tr_con_stop_stimulate_close_door_valve {
        return new _ProjectionRead__tr_con_stop_stimulate_close_door_valve(this.doors,this.shock_absorber,this.handle,this.close_EV,this.general_EV,this.gears);
    }

    _projected_state_for__tr_close_valve_door_close(): _ProjectionRead__tr_close_valve_door_close {
        return new _ProjectionRead__tr_close_valve_door_close(this.valve_close_door,this.close_EV);
    }

    _projected_state_for__check_inv_18(): _ProjectionRead__check_inv_18 {
        return new _ProjectionRead__check_inv_18(this.open_EV,this.close_EV);
    }

    _projected_state_for__check_inv_17(): _ProjectionRead__check_inv_17 {
        return new _ProjectionRead__check_inv_17(this.extend_EV,this.open_EV,this.close_EV,this.general_EV,this.retract_EV);
    }

    _projected_state_for__check_inv_16(): _ProjectionRead__check_inv_16 {
        return new _ProjectionRead__check_inv_16(this.gear);
    }

    _projected_state_for__check_inv_15(): _ProjectionRead__check_inv_15 {
        return new _ProjectionRead__check_inv_15(this.door);
    }

    _projected_state_for__check_inv_19(): _ProjectionRead__check_inv_19 {
        return new _ProjectionRead__check_inv_19(this.gears);
    }

    _projected_state_for__check_inv_10(): _ProjectionRead__check_inv_10 {
        return new _ProjectionRead__check_inv_10(this.valve_close_door);
    }

    _projected_state_for__check_inv_14(): _ProjectionRead__check_inv_14 {
        return new _ProjectionRead__check_inv_14(this.handle);
    }

    _projected_state_for__check_inv_13(): _ProjectionRead__check_inv_13 {
        return new _ProjectionRead__check_inv_13(this.valve_retract_gear);
    }

    _projected_state_for__check_inv_12(): _ProjectionRead__check_inv_12 {
        return new _ProjectionRead__check_inv_12(this.valve_open_door);
    }

    _projected_state_for__check_inv_11(): _ProjectionRead__check_inv_11 {
        return new _ProjectionRead__check_inv_11(this.valve_extend_gear);
    }

    _projected_state_for__check_inv_6(): _ProjectionRead__check_inv_6 {
        return new _ProjectionRead__check_inv_6(this.extend_EV);
    }

    _projected_state_for__check_inv_21(): _ProjectionRead__check_inv_21 {
        return new _ProjectionRead__check_inv_21(this.doors,this.door);
    }

    _projected_state_for__check_inv_7(): _ProjectionRead__check_inv_7 {
        return new _ProjectionRead__check_inv_7(this.open_EV);
    }

    _projected_state_for__check_inv_20(): _ProjectionRead__check_inv_20 {
        return new _ProjectionRead__check_inv_20(this.doors);
    }

    _projected_state_for__check_inv_4(): _ProjectionRead__check_inv_4 {
        return new _ProjectionRead__check_inv_4(this.handle_move);
    }

    _projected_state_for__check_inv_5(): _ProjectionRead__check_inv_5 {
        return new _ProjectionRead__check_inv_5(this.close_EV);
    }

    _projected_state_for__check_inv_25(): _ProjectionRead__check_inv_25 {
        return new _ProjectionRead__check_inv_25(this.door,this.gear);
    }

    _projected_state_for__check_inv_24(): _ProjectionRead__check_inv_24 {
        return new _ProjectionRead__check_inv_24(this.gears,this.gear);
    }

    _projected_state_for__check_inv_8(): _ProjectionRead__check_inv_8 {
        return new _ProjectionRead__check_inv_8(this.retract_EV);
    }

    _projected_state_for__check_inv_23(): _ProjectionRead__check_inv_23 {
        return new _ProjectionRead__check_inv_23(this.gears,this.gear);
    }

    _projected_state_for__check_inv_9(): _ProjectionRead__check_inv_9 {
        return new _ProjectionRead__check_inv_9(this.shock_absorber);
    }

    _projected_state_for__check_inv_22(): _ProjectionRead__check_inv_22 {
        return new _ProjectionRead__check_inv_22(this.doors,this.door);
    }

    _projected_state_for__check_inv_2(): _ProjectionRead__check_inv_2 {
        return new _ProjectionRead__check_inv_2(this.general_EV);
    }

    _projected_state_for__check_inv_3(): _ProjectionRead__check_inv_3 {
        return new _ProjectionRead__check_inv_3(this.general_valve);
    }

    _projected_state_for__check_inv_1(): _ProjectionRead__check_inv_1 {
        return new _ProjectionRead__check_inv_1(this.analogical_switch);
    }

    _update_for_close_valve_door_close(): _ProjectionWrite_close_valve_door_close {
        return new _ProjectionWrite_close_valve_door_close(this.valve_close_door);
    }

    _update_for_close_valve_retract_gear(): _ProjectionWrite_close_valve_retract_gear {
        return new _ProjectionWrite_close_valve_retract_gear(this.valve_retract_gear);
    }

    _update_for_con_stimulate_open_door_valve(): _ProjectionWrite_con_stimulate_open_door_valve {
        return new _ProjectionWrite_con_stimulate_open_door_valve(this.open_EV);
    }

    _update_for_env_close_door(): _ProjectionWrite_env_close_door {
        return new _ProjectionWrite_env_close_door(this.doors,this.door);
    }

    _update_for_env_start_close_door(): _ProjectionWrite_env_start_close_door {
        return new _ProjectionWrite_env_start_close_door(this.doors,this.door);
    }

    _update_for_toggle_handle_up(): _ProjectionWrite_toggle_handle_up {
        return new _ProjectionWrite_toggle_handle_up(this.handle,this.handle_move);
    }

    _update_for_toggle_handle_down(): _ProjectionWrite_toggle_handle_down {
        return new _ProjectionWrite_toggle_handle_down(this.handle,this.handle_move);
    }

    _update_for_open_valve_door_open(): _ProjectionWrite_open_valve_door_open {
        return new _ProjectionWrite_open_valve_door_open(this.valve_open_door);
    }

    _update_for_env_retract_gear_last(): _ProjectionWrite_env_retract_gear_last {
        return new _ProjectionWrite_env_retract_gear_last(this.gears,this.gear);
    }

    _update_for_env_open_door_last(): _ProjectionWrite_env_open_door_last {
        return new _ProjectionWrite_env_open_door_last(this.doors,this.door);
    }

    _update_for_con_stop_stimulate_retract_gear_valve(): _ProjectionWrite_con_stop_stimulate_retract_gear_valve {
        return new _ProjectionWrite_con_stop_stimulate_retract_gear_valve(this.retract_EV);
    }

    _update_for_env_close_door_skip(): _ProjectionWrite_env_close_door_skip {
        return new _ProjectionWrite_env_close_door_skip(this.doors);
    }

    _update_for_con_stop_stimulate_close_door_valve(): _ProjectionWrite_con_stop_stimulate_close_door_valve {
        return new _ProjectionWrite_con_stop_stimulate_close_door_valve(this.close_EV);
    }

    _update_for_env_open_analogical_switch(): _ProjectionWrite_env_open_analogical_switch {
        return new _ProjectionWrite_env_open_analogical_switch(this.analogical_switch);
    }

    _update_for_con_stop_stimulate_general_valve(): _ProjectionWrite_con_stop_stimulate_general_valve {
        return new _ProjectionWrite_con_stop_stimulate_general_valve(this.handle_move,this.general_EV);
    }

    _update_for_env_extend_gear_last(): _ProjectionWrite_env_extend_gear_last {
        return new _ProjectionWrite_env_extend_gear_last(this.gears,this.gear);
    }

    _update_for_evn_open_general_valve(): _ProjectionWrite_evn_open_general_valve {
        return new _ProjectionWrite_evn_open_general_valve(this.general_valve);
    }

    _update_for_land_plane(): _ProjectionWrite_land_plane {
        return new _ProjectionWrite_land_plane(this.shock_absorber);
    }

    _update_for_con_stimulate_retract_gear_valve(): _ProjectionWrite_con_stimulate_retract_gear_valve {
        return new _ProjectionWrite_con_stimulate_retract_gear_valve(this.retract_EV);
    }

    _update_for_con_stimulate_general_valve(): _ProjectionWrite_con_stimulate_general_valve {
        return new _ProjectionWrite_con_stimulate_general_valve(this.general_EV);
    }

    _update_for_env_start_retracting_first(): _ProjectionWrite_env_start_retracting_first {
        return new _ProjectionWrite_env_start_retracting_first(this.gears,this.gear);
    }

    _update_for_env_retract_gear_skip(): _ProjectionWrite_env_retract_gear_skip {
        return new _ProjectionWrite_env_retract_gear_skip(this.gears);
    }

    _update_for_open_valve_extend_gear(): _ProjectionWrite_open_valve_extend_gear {
        return new _ProjectionWrite_open_valve_extend_gear(this.valve_extend_gear);
    }

    _update_for_begin_flying(): _ProjectionWrite_begin_flying {
        return new _ProjectionWrite_begin_flying(this.shock_absorber);
    }

    _update_for_open_valve_retract_gear(): _ProjectionWrite_open_valve_retract_gear {
        return new _ProjectionWrite_open_valve_retract_gear(this.valve_retract_gear);
    }

    _update_for_env_close_analogical_switch(): _ProjectionWrite_env_close_analogical_switch {
        return new _ProjectionWrite_env_close_analogical_switch(this.analogical_switch);
    }

    _update_for_env_start_extending(): _ProjectionWrite_env_start_extending {
        return new _ProjectionWrite_env_start_extending(this.gears,this.gear);
    }

    _update_for_open_valve_door_close(): _ProjectionWrite_open_valve_door_close {
        return new _ProjectionWrite_open_valve_door_close(this.valve_close_door);
    }

    _update_for_con_stop_stimulate_open_door_valve(): _ProjectionWrite_con_stop_stimulate_open_door_valve {
        return new _ProjectionWrite_con_stop_stimulate_open_door_valve(this.open_EV);
    }

    _update_for_con_stop_stimulate_extend_gear_valve(): _ProjectionWrite_con_stop_stimulate_extend_gear_valve {
        return new _ProjectionWrite_con_stop_stimulate_extend_gear_valve(this.extend_EV);
    }

    _update_for_evn_close_general_valve(): _ProjectionWrite_evn_close_general_valve {
        return new _ProjectionWrite_evn_close_general_valve(this.general_valve);
    }

    _update_for_close_valve_extend_gear(): _ProjectionWrite_close_valve_extend_gear {
        return new _ProjectionWrite_close_valve_extend_gear(this.valve_extend_gear);
    }

    _update_for_con_stimulate_extend_gear_valve(): _ProjectionWrite_con_stimulate_extend_gear_valve {
        return new _ProjectionWrite_con_stimulate_extend_gear_valve(this.extend_EV);
    }

    _update_for_close_valve_door_open(): _ProjectionWrite_close_valve_door_open {
        return new _ProjectionWrite_close_valve_door_open(this.valve_open_door);
    }

    _update_for_con_stimulate_close_door_valve(): _ProjectionWrite_con_stimulate_close_door_valve {
        return new _ProjectionWrite_con_stimulate_close_door_valve(this.close_EV);
    }

    _update_for_env_extend_gear_skip(): _ProjectionWrite_env_extend_gear_skip {
        return new _ProjectionWrite_env_extend_gear_skip(this.gears);
    }

    _update_for_env_open_door_skip(): _ProjectionWrite_env_open_door_skip {
        return new _ProjectionWrite_env_open_door_skip(this.doors);
    }

    _update_for_env_start_open_door(): _ProjectionWrite_env_start_open_door {
        return new _ProjectionWrite_env_start_open_door(this.doors,this.door);
    }

    _apply_update_for_close_valve_door_close(update : _ProjectionWrite_close_valve_door_close): void {
        this.valve_close_door = update.valve_close_door;
    }

    _apply_update_for_close_valve_retract_gear(update : _ProjectionWrite_close_valve_retract_gear): void {
        this.valve_retract_gear = update.valve_retract_gear;
    }

    _apply_update_for_con_stimulate_open_door_valve(update : _ProjectionWrite_con_stimulate_open_door_valve): void {
        this.open_EV = update.open_EV;
    }

    _apply_update_for_env_close_door(update : _ProjectionWrite_env_close_door): void {
        this.doors = update.doors;
        this.door = update.door;
    }

    _apply_update_for_env_start_close_door(update : _ProjectionWrite_env_start_close_door): void {
        this.doors = update.doors;
        this.door = update.door;
    }

    _apply_update_for_toggle_handle_up(update : _ProjectionWrite_toggle_handle_up): void {
        this.handle = update.handle;
        this.handle_move = update.handle_move;
    }

    _apply_update_for_toggle_handle_down(update : _ProjectionWrite_toggle_handle_down): void {
        this.handle = update.handle;
        this.handle_move = update.handle_move;
    }

    _apply_update_for_open_valve_door_open(update : _ProjectionWrite_open_valve_door_open): void {
        this.valve_open_door = update.valve_open_door;
    }

    _apply_update_for_env_retract_gear_last(update : _ProjectionWrite_env_retract_gear_last): void {
        this.gears = update.gears;
        this.gear = update.gear;
    }

    _apply_update_for_env_open_door_last(update : _ProjectionWrite_env_open_door_last): void {
        this.doors = update.doors;
        this.door = update.door;
    }

    _apply_update_for_con_stop_stimulate_retract_gear_valve(update : _ProjectionWrite_con_stop_stimulate_retract_gear_valve): void {
        this.retract_EV = update.retract_EV;
    }

    _apply_update_for_env_close_door_skip(update : _ProjectionWrite_env_close_door_skip): void {
        this.doors = update.doors;
    }

    _apply_update_for_con_stop_stimulate_close_door_valve(update : _ProjectionWrite_con_stop_stimulate_close_door_valve): void {
        this.close_EV = update.close_EV;
    }

    _apply_update_for_env_open_analogical_switch(update : _ProjectionWrite_env_open_analogical_switch): void {
        this.analogical_switch = update.analogical_switch;
    }

    _apply_update_for_con_stop_stimulate_general_valve(update : _ProjectionWrite_con_stop_stimulate_general_valve): void {
        this.handle_move = update.handle_move;
        this.general_EV = update.general_EV;
    }

    _apply_update_for_env_extend_gear_last(update : _ProjectionWrite_env_extend_gear_last): void {
        this.gears = update.gears;
        this.gear = update.gear;
    }

    _apply_update_for_evn_open_general_valve(update : _ProjectionWrite_evn_open_general_valve): void {
        this.general_valve = update.general_valve;
    }

    _apply_update_for_land_plane(update : _ProjectionWrite_land_plane): void {
        this.shock_absorber = update.shock_absorber;
    }

    _apply_update_for_con_stimulate_retract_gear_valve(update : _ProjectionWrite_con_stimulate_retract_gear_valve): void {
        this.retract_EV = update.retract_EV;
    }

    _apply_update_for_con_stimulate_general_valve(update : _ProjectionWrite_con_stimulate_general_valve): void {
        this.general_EV = update.general_EV;
    }

    _apply_update_for_env_start_retracting_first(update : _ProjectionWrite_env_start_retracting_first): void {
        this.gears = update.gears;
        this.gear = update.gear;
    }

    _apply_update_for_env_retract_gear_skip(update : _ProjectionWrite_env_retract_gear_skip): void {
        this.gears = update.gears;
    }

    _apply_update_for_open_valve_extend_gear(update : _ProjectionWrite_open_valve_extend_gear): void {
        this.valve_extend_gear = update.valve_extend_gear;
    }

    _apply_update_for_begin_flying(update : _ProjectionWrite_begin_flying): void {
        this.shock_absorber = update.shock_absorber;
    }

    _apply_update_for_open_valve_retract_gear(update : _ProjectionWrite_open_valve_retract_gear): void {
        this.valve_retract_gear = update.valve_retract_gear;
    }

    _apply_update_for_env_close_analogical_switch(update : _ProjectionWrite_env_close_analogical_switch): void {
        this.analogical_switch = update.analogical_switch;
    }

    _apply_update_for_env_start_extending(update : _ProjectionWrite_env_start_extending): void {
        this.gears = update.gears;
        this.gear = update.gear;
    }

    _apply_update_for_open_valve_door_close(update : _ProjectionWrite_open_valve_door_close): void {
        this.valve_close_door = update.valve_close_door;
    }

    _apply_update_for_con_stop_stimulate_open_door_valve(update : _ProjectionWrite_con_stop_stimulate_open_door_valve): void {
        this.open_EV = update.open_EV;
    }

    _apply_update_for_con_stop_stimulate_extend_gear_valve(update : _ProjectionWrite_con_stop_stimulate_extend_gear_valve): void {
        this.extend_EV = update.extend_EV;
    }

    _apply_update_for_evn_close_general_valve(update : _ProjectionWrite_evn_close_general_valve): void {
        this.general_valve = update.general_valve;
    }

    _apply_update_for_close_valve_extend_gear(update : _ProjectionWrite_close_valve_extend_gear): void {
        this.valve_extend_gear = update.valve_extend_gear;
    }

    _apply_update_for_con_stimulate_extend_gear_valve(update : _ProjectionWrite_con_stimulate_extend_gear_valve): void {
        this.extend_EV = update.extend_EV;
    }

    _apply_update_for_close_valve_door_open(update : _ProjectionWrite_close_valve_door_open): void {
        this.valve_open_door = update.valve_open_door;
    }

    _apply_update_for_con_stimulate_close_door_valve(update : _ProjectionWrite_con_stimulate_close_door_valve): void {
        this.close_EV = update.close_EV;
    }

    _apply_update_for_env_extend_gear_skip(update : _ProjectionWrite_env_extend_gear_skip): void {
        this.gears = update.gears;
    }

    _apply_update_for_env_open_door_skip(update : _ProjectionWrite_env_open_door_skip): void {
        this.doors = update.doors;
    }

    _apply_update_for_env_start_open_door(update : _ProjectionWrite_env_start_open_door): void {
        this.doors = update.doors;
        this.door = update.door;
    }

    _check_inv_1() {
        return LandingGear_R6._SWITCH_STATE.elementOf(this.analogical_switch).booleanValue();
    }

    _check_inv_2() {
        return this.general_EV.isBoolean().booleanValue();
    }

    _check_inv_3() {
        return LandingGear_R6._VALVE_STATE.elementOf(this.general_valve).booleanValue();
    }

    _check_inv_4() {
        return this.handle_move.isBoolean().booleanValue();
    }

    _check_inv_5() {
        return this.close_EV.isBoolean().booleanValue();
    }

    _check_inv_6() {
        return this.extend_EV.isBoolean().booleanValue();
    }

    _check_inv_7() {
        return this.open_EV.isBoolean().booleanValue();
    }

    _check_inv_8() {
        return this.retract_EV.isBoolean().booleanValue();
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

    _OpCache_begin_flying: immutable.Map<boolean, immutable.Map<_ProjectionRead_begin_flying, _ProjectionWrite_begin_flying>> = new immutable.Map();
    _OpCache_tr_begin_flying: immutable.Map<_ProjectionRead__tr_begin_flying, boolean> = new immutable.Map();

    _OpCache_land_plane: immutable.Map<boolean, immutable.Map<_ProjectionRead_land_plane, _ProjectionWrite_land_plane>> = new immutable.Map();
    _OpCache_tr_land_plane: immutable.Map<_ProjectionRead__tr_land_plane, boolean> = new immutable.Map();

    _OpCache_open_valve_door_open: immutable.Map<boolean, immutable.Map<_ProjectionRead_open_valve_door_open, _ProjectionWrite_open_valve_door_open>> = new immutable.Map();
    _OpCache_tr_open_valve_door_open: immutable.Map<_ProjectionRead__tr_open_valve_door_open, boolean> = new immutable.Map();

    _OpCache_close_valve_door_open: immutable.Map<boolean, immutable.Map<_ProjectionRead_close_valve_door_open, _ProjectionWrite_close_valve_door_open>> = new immutable.Map();
    _OpCache_tr_close_valve_door_open: immutable.Map<_ProjectionRead__tr_close_valve_door_open, boolean> = new immutable.Map();

    _OpCache_open_valve_door_close: immutable.Map<boolean, immutable.Map<_ProjectionRead_open_valve_door_close, _ProjectionWrite_open_valve_door_close>> = new immutable.Map();
    _OpCache_tr_open_valve_door_close: immutable.Map<_ProjectionRead__tr_open_valve_door_close, boolean> = new immutable.Map();

    _OpCache_close_valve_door_close: immutable.Map<boolean, immutable.Map<_ProjectionRead_close_valve_door_close, _ProjectionWrite_close_valve_door_close>> = new immutable.Map();
    _OpCache_tr_close_valve_door_close: immutable.Map<_ProjectionRead__tr_close_valve_door_close, boolean> = new immutable.Map();

    _OpCache_open_valve_retract_gear: immutable.Map<boolean, immutable.Map<_ProjectionRead_open_valve_retract_gear, _ProjectionWrite_open_valve_retract_gear>> = new immutable.Map();
    _OpCache_tr_open_valve_retract_gear: immutable.Map<_ProjectionRead__tr_open_valve_retract_gear, boolean> = new immutable.Map();

    _OpCache_close_valve_retract_gear: immutable.Map<boolean, immutable.Map<_ProjectionRead_close_valve_retract_gear, _ProjectionWrite_close_valve_retract_gear>> = new immutable.Map();
    _OpCache_tr_close_valve_retract_gear: immutable.Map<_ProjectionRead__tr_close_valve_retract_gear, boolean> = new immutable.Map();

    _OpCache_open_valve_extend_gear: immutable.Map<boolean, immutable.Map<_ProjectionRead_open_valve_extend_gear, _ProjectionWrite_open_valve_extend_gear>> = new immutable.Map();
    _OpCache_tr_open_valve_extend_gear: immutable.Map<_ProjectionRead__tr_open_valve_extend_gear, boolean> = new immutable.Map();

    _OpCache_close_valve_extend_gear: immutable.Map<boolean, immutable.Map<_ProjectionRead_close_valve_extend_gear, _ProjectionWrite_close_valve_extend_gear>> = new immutable.Map();
    _OpCache_tr_close_valve_extend_gear: immutable.Map<_ProjectionRead__tr_close_valve_extend_gear, boolean> = new immutable.Map();

    _OpCache_con_stimulate_open_door_valve: immutable.Map<boolean, immutable.Map<_ProjectionRead_con_stimulate_open_door_valve, _ProjectionWrite_con_stimulate_open_door_valve>> = new immutable.Map();
    _OpCache_tr_con_stimulate_open_door_valve: immutable.Map<_ProjectionRead__tr_con_stimulate_open_door_valve, boolean> = new immutable.Map();

    _OpCache_con_stop_stimulate_open_door_valve: immutable.Map<boolean, immutable.Map<_ProjectionRead_con_stop_stimulate_open_door_valve, _ProjectionWrite_con_stop_stimulate_open_door_valve>> = new immutable.Map();
    _OpCache_tr_con_stop_stimulate_open_door_valve: immutable.Map<_ProjectionRead__tr_con_stop_stimulate_open_door_valve, boolean> = new immutable.Map();

    _OpCache_con_stimulate_close_door_valve: immutable.Map<boolean, immutable.Map<_ProjectionRead_con_stimulate_close_door_valve, _ProjectionWrite_con_stimulate_close_door_valve>> = new immutable.Map();
    _OpCache_tr_con_stimulate_close_door_valve: immutable.Map<_ProjectionRead__tr_con_stimulate_close_door_valve, boolean> = new immutable.Map();

    _OpCache_con_stop_stimulate_close_door_valve: immutable.Map<boolean, immutable.Map<_ProjectionRead_con_stop_stimulate_close_door_valve, _ProjectionWrite_con_stop_stimulate_close_door_valve>> = new immutable.Map();
    _OpCache_tr_con_stop_stimulate_close_door_valve: immutable.Map<_ProjectionRead__tr_con_stop_stimulate_close_door_valve, boolean> = new immutable.Map();

    _OpCache_con_stimulate_retract_gear_valve: immutable.Map<boolean, immutable.Map<_ProjectionRead_con_stimulate_retract_gear_valve, _ProjectionWrite_con_stimulate_retract_gear_valve>> = new immutable.Map();
    _OpCache_tr_con_stimulate_retract_gear_valve: immutable.Map<_ProjectionRead__tr_con_stimulate_retract_gear_valve, boolean> = new immutable.Map();

    _OpCache_con_stop_stimulate_retract_gear_valve: immutable.Map<boolean, immutable.Map<_ProjectionRead_con_stop_stimulate_retract_gear_valve, _ProjectionWrite_con_stop_stimulate_retract_gear_valve>> = new immutable.Map();
    _OpCache_tr_con_stop_stimulate_retract_gear_valve: immutable.Map<_ProjectionRead__tr_con_stop_stimulate_retract_gear_valve, boolean> = new immutable.Map();

    _OpCache_con_stimulate_extend_gear_valve: immutable.Map<boolean, immutable.Map<_ProjectionRead_con_stimulate_extend_gear_valve, _ProjectionWrite_con_stimulate_extend_gear_valve>> = new immutable.Map();
    _OpCache_tr_con_stimulate_extend_gear_valve: immutable.Map<_ProjectionRead__tr_con_stimulate_extend_gear_valve, boolean> = new immutable.Map();

    _OpCache_con_stop_stimulate_extend_gear_valve: immutable.Map<boolean, immutable.Map<_ProjectionRead_con_stop_stimulate_extend_gear_valve, _ProjectionWrite_con_stop_stimulate_extend_gear_valve>> = new immutable.Map();
    _OpCache_tr_con_stop_stimulate_extend_gear_valve: immutable.Map<_ProjectionRead__tr_con_stop_stimulate_extend_gear_valve, boolean> = new immutable.Map();

    _OpCache_env_start_retracting_first: immutable.Map<BSet<POSITION>, immutable.Map<_ProjectionRead_env_start_retracting_first, _ProjectionWrite_env_start_retracting_first>> = new immutable.Map();
    _OpCache_tr_env_start_retracting_first: immutable.Map<_ProjectionRead__tr_env_start_retracting_first, BSet<POSITION>> = new immutable.Map();

    _OpCache_env_retract_gear_skip: immutable.Map<BSet<POSITION>, immutable.Map<_ProjectionRead_env_retract_gear_skip, _ProjectionWrite_env_retract_gear_skip>> = new immutable.Map();
    _OpCache_tr_env_retract_gear_skip: immutable.Map<_ProjectionRead__tr_env_retract_gear_skip, BSet<POSITION>> = new immutable.Map();

    _OpCache_env_retract_gear_last: immutable.Map<BSet<POSITION>, immutable.Map<_ProjectionRead_env_retract_gear_last, _ProjectionWrite_env_retract_gear_last>> = new immutable.Map();
    _OpCache_tr_env_retract_gear_last: immutable.Map<_ProjectionRead__tr_env_retract_gear_last, BSet<POSITION>> = new immutable.Map();

    _OpCache_env_start_extending: immutable.Map<BSet<POSITION>, immutable.Map<_ProjectionRead_env_start_extending, _ProjectionWrite_env_start_extending>> = new immutable.Map();
    _OpCache_tr_env_start_extending: immutable.Map<_ProjectionRead__tr_env_start_extending, BSet<POSITION>> = new immutable.Map();

    _OpCache_env_extend_gear_last: immutable.Map<BSet<POSITION>, immutable.Map<_ProjectionRead_env_extend_gear_last, _ProjectionWrite_env_extend_gear_last>> = new immutable.Map();
    _OpCache_tr_env_extend_gear_last: immutable.Map<_ProjectionRead__tr_env_extend_gear_last, BSet<POSITION>> = new immutable.Map();

    _OpCache_env_extend_gear_skip: immutable.Map<BSet<POSITION>, immutable.Map<_ProjectionRead_env_extend_gear_skip, _ProjectionWrite_env_extend_gear_skip>> = new immutable.Map();
    _OpCache_tr_env_extend_gear_skip: immutable.Map<_ProjectionRead__tr_env_extend_gear_skip, BSet<POSITION>> = new immutable.Map();

    _OpCache_env_start_open_door: immutable.Map<BSet<POSITION>, immutable.Map<_ProjectionRead_env_start_open_door, _ProjectionWrite_env_start_open_door>> = new immutable.Map();
    _OpCache_tr_env_start_open_door: immutable.Map<_ProjectionRead__tr_env_start_open_door, BSet<POSITION>> = new immutable.Map();

    _OpCache_env_open_door_last: immutable.Map<BSet<POSITION>, immutable.Map<_ProjectionRead_env_open_door_last, _ProjectionWrite_env_open_door_last>> = new immutable.Map();
    _OpCache_tr_env_open_door_last: immutable.Map<_ProjectionRead__tr_env_open_door_last, BSet<POSITION>> = new immutable.Map();

    _OpCache_env_open_door_skip: immutable.Map<BSet<POSITION>, immutable.Map<_ProjectionRead_env_open_door_skip, _ProjectionWrite_env_open_door_skip>> = new immutable.Map();
    _OpCache_tr_env_open_door_skip: immutable.Map<_ProjectionRead__tr_env_open_door_skip, BSet<POSITION>> = new immutable.Map();

    _OpCache_env_start_close_door: immutable.Map<BSet<POSITION>, immutable.Map<_ProjectionRead_env_start_close_door, _ProjectionWrite_env_start_close_door>> = new immutable.Map();
    _OpCache_tr_env_start_close_door: immutable.Map<_ProjectionRead__tr_env_start_close_door, BSet<POSITION>> = new immutable.Map();

    _OpCache_env_close_door: immutable.Map<BSet<POSITION>, immutable.Map<_ProjectionRead_env_close_door, _ProjectionWrite_env_close_door>> = new immutable.Map();
    _OpCache_tr_env_close_door: immutable.Map<_ProjectionRead__tr_env_close_door, BSet<POSITION>> = new immutable.Map();

    _OpCache_env_close_door_skip: immutable.Map<BSet<POSITION>, immutable.Map<_ProjectionRead_env_close_door_skip, _ProjectionWrite_env_close_door_skip>> = new immutable.Map();
    _OpCache_tr_env_close_door_skip: immutable.Map<_ProjectionRead__tr_env_close_door_skip, BSet<POSITION>> = new immutable.Map();

    _OpCache_toggle_handle_up: immutable.Map<boolean, immutable.Map<_ProjectionRead_toggle_handle_up, _ProjectionWrite_toggle_handle_up>> = new immutable.Map();
    _OpCache_tr_toggle_handle_up: immutable.Map<_ProjectionRead__tr_toggle_handle_up, boolean> = new immutable.Map();

    _OpCache_toggle_handle_down: immutable.Map<boolean, immutable.Map<_ProjectionRead_toggle_handle_down, _ProjectionWrite_toggle_handle_down>> = new immutable.Map();
    _OpCache_tr_toggle_handle_down: immutable.Map<_ProjectionRead__tr_toggle_handle_down, boolean> = new immutable.Map();

    _OpCache_con_stimulate_general_valve: immutable.Map<boolean, immutable.Map<_ProjectionRead_con_stimulate_general_valve, _ProjectionWrite_con_stimulate_general_valve>> = new immutable.Map();
    _OpCache_tr_con_stimulate_general_valve: immutable.Map<_ProjectionRead__tr_con_stimulate_general_valve, boolean> = new immutable.Map();

    _OpCache_con_stop_stimulate_general_valve: immutable.Map<boolean, immutable.Map<_ProjectionRead_con_stop_stimulate_general_valve, _ProjectionWrite_con_stop_stimulate_general_valve>> = new immutable.Map();
    _OpCache_tr_con_stop_stimulate_general_valve: immutable.Map<_ProjectionRead__tr_con_stop_stimulate_general_valve, boolean> = new immutable.Map();

    _OpCache_evn_open_general_valve: immutable.Map<boolean, immutable.Map<_ProjectionRead_evn_open_general_valve, _ProjectionWrite_evn_open_general_valve>> = new immutable.Map();
    _OpCache_tr_evn_open_general_valve: immutable.Map<_ProjectionRead__tr_evn_open_general_valve, boolean> = new immutable.Map();

    _OpCache_evn_close_general_valve: immutable.Map<boolean, immutable.Map<_ProjectionRead_evn_close_general_valve, _ProjectionWrite_evn_close_general_valve>> = new immutable.Map();
    _OpCache_tr_evn_close_general_valve: immutable.Map<_ProjectionRead__tr_evn_close_general_valve, boolean> = new immutable.Map();

    _OpCache_env_close_analogical_switch: immutable.Map<boolean, immutable.Map<_ProjectionRead_env_close_analogical_switch, _ProjectionWrite_env_close_analogical_switch>> = new immutable.Map();
    _OpCache_tr_env_close_analogical_switch: immutable.Map<_ProjectionRead__tr_env_close_analogical_switch, boolean> = new immutable.Map();

    _OpCache_env_open_analogical_switch: immutable.Map<boolean, immutable.Map<_ProjectionRead_env_open_analogical_switch, _ProjectionWrite_env_open_analogical_switch>> = new immutable.Map();
    _OpCache_tr_env_open_analogical_switch: immutable.Map<_ProjectionRead__tr_env_open_analogical_switch, boolean> = new immutable.Map();

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
            let read__tr_begin_flying_state : _ProjectionRead__tr_begin_flying = state._projected_state_for__tr_begin_flying();
            let _obj__trid_1: any = this._OpCache_tr_begin_flying.get(read__tr_begin_flying_state);
            let _trid_1: boolean;
            if(_obj__trid_1 == null) {
                _trid_1 = state._tr_begin_flying();
                this._OpCache_tr_begin_flying = this._OpCache_tr_begin_flying.set(read__tr_begin_flying_state, _trid_1);
            } else {
                _trid_1 = _obj__trid_1;
            }

            if(_trid_1) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_begin_flying = state._projected_state_for_begin_flying();
                let _OpCache_with_parameter_begin_flying: immutable.Map = this._OpCache_begin_flying.get(_trid_1);
                if(_OpCache_with_parameter_begin_flying != null) {
                    let writeState: _ProjectionWrite_begin_flying = _OpCache_with_parameter_begin_flying.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_begin_flying(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.begin_flying();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_begin_flying();
                        _OpCache_with_parameter_begin_flying = _OpCache_with_parameter_begin_flying.set(readState, writeState);
                        this._OpCache_begin_flying = this._OpCache_begin_flying.set(_trid_1, _OpCache_with_parameter_begin_flying);
                    }

                } else {
                    copiedState.begin_flying();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_begin_flying = copiedState._update_for_begin_flying();
                    _OpCache_with_parameter_begin_flying = new immutable.Map().set(readState, writeState);
                    this._OpCache_begin_flying = this._OpCache_begin_flying.set(_trid_1, _OpCache_with_parameter_begin_flying);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_land_plane_state : _ProjectionRead__tr_land_plane = state._projected_state_for__tr_land_plane();
            let _obj__trid_2: any = this._OpCache_tr_land_plane.get(read__tr_land_plane_state);
            let _trid_2: boolean;
            if(_obj__trid_2 == null) {
                _trid_2 = state._tr_land_plane();
                this._OpCache_tr_land_plane = this._OpCache_tr_land_plane.set(read__tr_land_plane_state, _trid_2);
            } else {
                _trid_2 = _obj__trid_2;
            }

            if(_trid_2) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_land_plane = state._projected_state_for_land_plane();
                let _OpCache_with_parameter_land_plane: immutable.Map = this._OpCache_land_plane.get(_trid_2);
                if(_OpCache_with_parameter_land_plane != null) {
                    let writeState: _ProjectionWrite_land_plane = _OpCache_with_parameter_land_plane.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_land_plane(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.land_plane();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_land_plane();
                        _OpCache_with_parameter_land_plane = _OpCache_with_parameter_land_plane.set(readState, writeState);
                        this._OpCache_land_plane = this._OpCache_land_plane.set(_trid_2, _OpCache_with_parameter_land_plane);
                    }

                } else {
                    copiedState.land_plane();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_land_plane = copiedState._update_for_land_plane();
                    _OpCache_with_parameter_land_plane = new immutable.Map().set(readState, writeState);
                    this._OpCache_land_plane = this._OpCache_land_plane.set(_trid_2, _OpCache_with_parameter_land_plane);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_open_valve_door_open_state : _ProjectionRead__tr_open_valve_door_open = state._projected_state_for__tr_open_valve_door_open();
            let _obj__trid_3: any = this._OpCache_tr_open_valve_door_open.get(read__tr_open_valve_door_open_state);
            let _trid_3: boolean;
            if(_obj__trid_3 == null) {
                _trid_3 = state._tr_open_valve_door_open();
                this._OpCache_tr_open_valve_door_open = this._OpCache_tr_open_valve_door_open.set(read__tr_open_valve_door_open_state, _trid_3);
            } else {
                _trid_3 = _obj__trid_3;
            }

            if(_trid_3) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_open_valve_door_open = state._projected_state_for_open_valve_door_open();
                let _OpCache_with_parameter_open_valve_door_open: immutable.Map = this._OpCache_open_valve_door_open.get(_trid_3);
                if(_OpCache_with_parameter_open_valve_door_open != null) {
                    let writeState: _ProjectionWrite_open_valve_door_open = _OpCache_with_parameter_open_valve_door_open.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_open_valve_door_open(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.open_valve_door_open();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_open_valve_door_open();
                        _OpCache_with_parameter_open_valve_door_open = _OpCache_with_parameter_open_valve_door_open.set(readState, writeState);
                        this._OpCache_open_valve_door_open = this._OpCache_open_valve_door_open.set(_trid_3, _OpCache_with_parameter_open_valve_door_open);
                    }

                } else {
                    copiedState.open_valve_door_open();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_open_valve_door_open = copiedState._update_for_open_valve_door_open();
                    _OpCache_with_parameter_open_valve_door_open = new immutable.Map().set(readState, writeState);
                    this._OpCache_open_valve_door_open = this._OpCache_open_valve_door_open.set(_trid_3, _OpCache_with_parameter_open_valve_door_open);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_close_valve_door_open_state : _ProjectionRead__tr_close_valve_door_open = state._projected_state_for__tr_close_valve_door_open();
            let _obj__trid_4: any = this._OpCache_tr_close_valve_door_open.get(read__tr_close_valve_door_open_state);
            let _trid_4: boolean;
            if(_obj__trid_4 == null) {
                _trid_4 = state._tr_close_valve_door_open();
                this._OpCache_tr_close_valve_door_open = this._OpCache_tr_close_valve_door_open.set(read__tr_close_valve_door_open_state, _trid_4);
            } else {
                _trid_4 = _obj__trid_4;
            }

            if(_trid_4) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_close_valve_door_open = state._projected_state_for_close_valve_door_open();
                let _OpCache_with_parameter_close_valve_door_open: immutable.Map = this._OpCache_close_valve_door_open.get(_trid_4);
                if(_OpCache_with_parameter_close_valve_door_open != null) {
                    let writeState: _ProjectionWrite_close_valve_door_open = _OpCache_with_parameter_close_valve_door_open.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_close_valve_door_open(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.close_valve_door_open();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_close_valve_door_open();
                        _OpCache_with_parameter_close_valve_door_open = _OpCache_with_parameter_close_valve_door_open.set(readState, writeState);
                        this._OpCache_close_valve_door_open = this._OpCache_close_valve_door_open.set(_trid_4, _OpCache_with_parameter_close_valve_door_open);
                    }

                } else {
                    copiedState.close_valve_door_open();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_close_valve_door_open = copiedState._update_for_close_valve_door_open();
                    _OpCache_with_parameter_close_valve_door_open = new immutable.Map().set(readState, writeState);
                    this._OpCache_close_valve_door_open = this._OpCache_close_valve_door_open.set(_trid_4, _OpCache_with_parameter_close_valve_door_open);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_open_valve_door_close_state : _ProjectionRead__tr_open_valve_door_close = state._projected_state_for__tr_open_valve_door_close();
            let _obj__trid_5: any = this._OpCache_tr_open_valve_door_close.get(read__tr_open_valve_door_close_state);
            let _trid_5: boolean;
            if(_obj__trid_5 == null) {
                _trid_5 = state._tr_open_valve_door_close();
                this._OpCache_tr_open_valve_door_close = this._OpCache_tr_open_valve_door_close.set(read__tr_open_valve_door_close_state, _trid_5);
            } else {
                _trid_5 = _obj__trid_5;
            }

            if(_trid_5) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_open_valve_door_close = state._projected_state_for_open_valve_door_close();
                let _OpCache_with_parameter_open_valve_door_close: immutable.Map = this._OpCache_open_valve_door_close.get(_trid_5);
                if(_OpCache_with_parameter_open_valve_door_close != null) {
                    let writeState: _ProjectionWrite_open_valve_door_close = _OpCache_with_parameter_open_valve_door_close.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_open_valve_door_close(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.open_valve_door_close();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_open_valve_door_close();
                        _OpCache_with_parameter_open_valve_door_close = _OpCache_with_parameter_open_valve_door_close.set(readState, writeState);
                        this._OpCache_open_valve_door_close = this._OpCache_open_valve_door_close.set(_trid_5, _OpCache_with_parameter_open_valve_door_close);
                    }

                } else {
                    copiedState.open_valve_door_close();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_open_valve_door_close = copiedState._update_for_open_valve_door_close();
                    _OpCache_with_parameter_open_valve_door_close = new immutable.Map().set(readState, writeState);
                    this._OpCache_open_valve_door_close = this._OpCache_open_valve_door_close.set(_trid_5, _OpCache_with_parameter_open_valve_door_close);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_close_valve_door_close_state : _ProjectionRead__tr_close_valve_door_close = state._projected_state_for__tr_close_valve_door_close();
            let _obj__trid_6: any = this._OpCache_tr_close_valve_door_close.get(read__tr_close_valve_door_close_state);
            let _trid_6: boolean;
            if(_obj__trid_6 == null) {
                _trid_6 = state._tr_close_valve_door_close();
                this._OpCache_tr_close_valve_door_close = this._OpCache_tr_close_valve_door_close.set(read__tr_close_valve_door_close_state, _trid_6);
            } else {
                _trid_6 = _obj__trid_6;
            }

            if(_trid_6) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_close_valve_door_close = state._projected_state_for_close_valve_door_close();
                let _OpCache_with_parameter_close_valve_door_close: immutable.Map = this._OpCache_close_valve_door_close.get(_trid_6);
                if(_OpCache_with_parameter_close_valve_door_close != null) {
                    let writeState: _ProjectionWrite_close_valve_door_close = _OpCache_with_parameter_close_valve_door_close.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_close_valve_door_close(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.close_valve_door_close();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_close_valve_door_close();
                        _OpCache_with_parameter_close_valve_door_close = _OpCache_with_parameter_close_valve_door_close.set(readState, writeState);
                        this._OpCache_close_valve_door_close = this._OpCache_close_valve_door_close.set(_trid_6, _OpCache_with_parameter_close_valve_door_close);
                    }

                } else {
                    copiedState.close_valve_door_close();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_close_valve_door_close = copiedState._update_for_close_valve_door_close();
                    _OpCache_with_parameter_close_valve_door_close = new immutable.Map().set(readState, writeState);
                    this._OpCache_close_valve_door_close = this._OpCache_close_valve_door_close.set(_trid_6, _OpCache_with_parameter_close_valve_door_close);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_open_valve_retract_gear_state : _ProjectionRead__tr_open_valve_retract_gear = state._projected_state_for__tr_open_valve_retract_gear();
            let _obj__trid_7: any = this._OpCache_tr_open_valve_retract_gear.get(read__tr_open_valve_retract_gear_state);
            let _trid_7: boolean;
            if(_obj__trid_7 == null) {
                _trid_7 = state._tr_open_valve_retract_gear();
                this._OpCache_tr_open_valve_retract_gear = this._OpCache_tr_open_valve_retract_gear.set(read__tr_open_valve_retract_gear_state, _trid_7);
            } else {
                _trid_7 = _obj__trid_7;
            }

            if(_trid_7) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_open_valve_retract_gear = state._projected_state_for_open_valve_retract_gear();
                let _OpCache_with_parameter_open_valve_retract_gear: immutable.Map = this._OpCache_open_valve_retract_gear.get(_trid_7);
                if(_OpCache_with_parameter_open_valve_retract_gear != null) {
                    let writeState: _ProjectionWrite_open_valve_retract_gear = _OpCache_with_parameter_open_valve_retract_gear.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_open_valve_retract_gear(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.open_valve_retract_gear();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_open_valve_retract_gear();
                        _OpCache_with_parameter_open_valve_retract_gear = _OpCache_with_parameter_open_valve_retract_gear.set(readState, writeState);
                        this._OpCache_open_valve_retract_gear = this._OpCache_open_valve_retract_gear.set(_trid_7, _OpCache_with_parameter_open_valve_retract_gear);
                    }

                } else {
                    copiedState.open_valve_retract_gear();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_open_valve_retract_gear = copiedState._update_for_open_valve_retract_gear();
                    _OpCache_with_parameter_open_valve_retract_gear = new immutable.Map().set(readState, writeState);
                    this._OpCache_open_valve_retract_gear = this._OpCache_open_valve_retract_gear.set(_trid_7, _OpCache_with_parameter_open_valve_retract_gear);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_close_valve_retract_gear_state : _ProjectionRead__tr_close_valve_retract_gear = state._projected_state_for__tr_close_valve_retract_gear();
            let _obj__trid_8: any = this._OpCache_tr_close_valve_retract_gear.get(read__tr_close_valve_retract_gear_state);
            let _trid_8: boolean;
            if(_obj__trid_8 == null) {
                _trid_8 = state._tr_close_valve_retract_gear();
                this._OpCache_tr_close_valve_retract_gear = this._OpCache_tr_close_valve_retract_gear.set(read__tr_close_valve_retract_gear_state, _trid_8);
            } else {
                _trid_8 = _obj__trid_8;
            }

            if(_trid_8) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_close_valve_retract_gear = state._projected_state_for_close_valve_retract_gear();
                let _OpCache_with_parameter_close_valve_retract_gear: immutable.Map = this._OpCache_close_valve_retract_gear.get(_trid_8);
                if(_OpCache_with_parameter_close_valve_retract_gear != null) {
                    let writeState: _ProjectionWrite_close_valve_retract_gear = _OpCache_with_parameter_close_valve_retract_gear.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_close_valve_retract_gear(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.close_valve_retract_gear();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_close_valve_retract_gear();
                        _OpCache_with_parameter_close_valve_retract_gear = _OpCache_with_parameter_close_valve_retract_gear.set(readState, writeState);
                        this._OpCache_close_valve_retract_gear = this._OpCache_close_valve_retract_gear.set(_trid_8, _OpCache_with_parameter_close_valve_retract_gear);
                    }

                } else {
                    copiedState.close_valve_retract_gear();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_close_valve_retract_gear = copiedState._update_for_close_valve_retract_gear();
                    _OpCache_with_parameter_close_valve_retract_gear = new immutable.Map().set(readState, writeState);
                    this._OpCache_close_valve_retract_gear = this._OpCache_close_valve_retract_gear.set(_trid_8, _OpCache_with_parameter_close_valve_retract_gear);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_open_valve_extend_gear_state : _ProjectionRead__tr_open_valve_extend_gear = state._projected_state_for__tr_open_valve_extend_gear();
            let _obj__trid_9: any = this._OpCache_tr_open_valve_extend_gear.get(read__tr_open_valve_extend_gear_state);
            let _trid_9: boolean;
            if(_obj__trid_9 == null) {
                _trid_9 = state._tr_open_valve_extend_gear();
                this._OpCache_tr_open_valve_extend_gear = this._OpCache_tr_open_valve_extend_gear.set(read__tr_open_valve_extend_gear_state, _trid_9);
            } else {
                _trid_9 = _obj__trid_9;
            }

            if(_trid_9) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_open_valve_extend_gear = state._projected_state_for_open_valve_extend_gear();
                let _OpCache_with_parameter_open_valve_extend_gear: immutable.Map = this._OpCache_open_valve_extend_gear.get(_trid_9);
                if(_OpCache_with_parameter_open_valve_extend_gear != null) {
                    let writeState: _ProjectionWrite_open_valve_extend_gear = _OpCache_with_parameter_open_valve_extend_gear.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_open_valve_extend_gear(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.open_valve_extend_gear();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_open_valve_extend_gear();
                        _OpCache_with_parameter_open_valve_extend_gear = _OpCache_with_parameter_open_valve_extend_gear.set(readState, writeState);
                        this._OpCache_open_valve_extend_gear = this._OpCache_open_valve_extend_gear.set(_trid_9, _OpCache_with_parameter_open_valve_extend_gear);
                    }

                } else {
                    copiedState.open_valve_extend_gear();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_open_valve_extend_gear = copiedState._update_for_open_valve_extend_gear();
                    _OpCache_with_parameter_open_valve_extend_gear = new immutable.Map().set(readState, writeState);
                    this._OpCache_open_valve_extend_gear = this._OpCache_open_valve_extend_gear.set(_trid_9, _OpCache_with_parameter_open_valve_extend_gear);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_close_valve_extend_gear_state : _ProjectionRead__tr_close_valve_extend_gear = state._projected_state_for__tr_close_valve_extend_gear();
            let _obj__trid_10: any = this._OpCache_tr_close_valve_extend_gear.get(read__tr_close_valve_extend_gear_state);
            let _trid_10: boolean;
            if(_obj__trid_10 == null) {
                _trid_10 = state._tr_close_valve_extend_gear();
                this._OpCache_tr_close_valve_extend_gear = this._OpCache_tr_close_valve_extend_gear.set(read__tr_close_valve_extend_gear_state, _trid_10);
            } else {
                _trid_10 = _obj__trid_10;
            }

            if(_trid_10) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_close_valve_extend_gear = state._projected_state_for_close_valve_extend_gear();
                let _OpCache_with_parameter_close_valve_extend_gear: immutable.Map = this._OpCache_close_valve_extend_gear.get(_trid_10);
                if(_OpCache_with_parameter_close_valve_extend_gear != null) {
                    let writeState: _ProjectionWrite_close_valve_extend_gear = _OpCache_with_parameter_close_valve_extend_gear.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_close_valve_extend_gear(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.close_valve_extend_gear();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_close_valve_extend_gear();
                        _OpCache_with_parameter_close_valve_extend_gear = _OpCache_with_parameter_close_valve_extend_gear.set(readState, writeState);
                        this._OpCache_close_valve_extend_gear = this._OpCache_close_valve_extend_gear.set(_trid_10, _OpCache_with_parameter_close_valve_extend_gear);
                    }

                } else {
                    copiedState.close_valve_extend_gear();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_close_valve_extend_gear = copiedState._update_for_close_valve_extend_gear();
                    _OpCache_with_parameter_close_valve_extend_gear = new immutable.Map().set(readState, writeState);
                    this._OpCache_close_valve_extend_gear = this._OpCache_close_valve_extend_gear.set(_trid_10, _OpCache_with_parameter_close_valve_extend_gear);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_con_stimulate_open_door_valve_state : _ProjectionRead__tr_con_stimulate_open_door_valve = state._projected_state_for__tr_con_stimulate_open_door_valve();
            let _obj__trid_11: any = this._OpCache_tr_con_stimulate_open_door_valve.get(read__tr_con_stimulate_open_door_valve_state);
            let _trid_11: boolean;
            if(_obj__trid_11 == null) {
                _trid_11 = state._tr_con_stimulate_open_door_valve();
                this._OpCache_tr_con_stimulate_open_door_valve = this._OpCache_tr_con_stimulate_open_door_valve.set(read__tr_con_stimulate_open_door_valve_state, _trid_11);
            } else {
                _trid_11 = _obj__trid_11;
            }

            if(_trid_11) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_con_stimulate_open_door_valve = state._projected_state_for_con_stimulate_open_door_valve();
                let _OpCache_with_parameter_con_stimulate_open_door_valve: immutable.Map = this._OpCache_con_stimulate_open_door_valve.get(_trid_11);
                if(_OpCache_with_parameter_con_stimulate_open_door_valve != null) {
                    let writeState: _ProjectionWrite_con_stimulate_open_door_valve = _OpCache_with_parameter_con_stimulate_open_door_valve.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_con_stimulate_open_door_valve(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.con_stimulate_open_door_valve();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_con_stimulate_open_door_valve();
                        _OpCache_with_parameter_con_stimulate_open_door_valve = _OpCache_with_parameter_con_stimulate_open_door_valve.set(readState, writeState);
                        this._OpCache_con_stimulate_open_door_valve = this._OpCache_con_stimulate_open_door_valve.set(_trid_11, _OpCache_with_parameter_con_stimulate_open_door_valve);
                    }

                } else {
                    copiedState.con_stimulate_open_door_valve();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_con_stimulate_open_door_valve = copiedState._update_for_con_stimulate_open_door_valve();
                    _OpCache_with_parameter_con_stimulate_open_door_valve = new immutable.Map().set(readState, writeState);
                    this._OpCache_con_stimulate_open_door_valve = this._OpCache_con_stimulate_open_door_valve.set(_trid_11, _OpCache_with_parameter_con_stimulate_open_door_valve);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_con_stop_stimulate_open_door_valve_state : _ProjectionRead__tr_con_stop_stimulate_open_door_valve = state._projected_state_for__tr_con_stop_stimulate_open_door_valve();
            let _obj__trid_12: any = this._OpCache_tr_con_stop_stimulate_open_door_valve.get(read__tr_con_stop_stimulate_open_door_valve_state);
            let _trid_12: boolean;
            if(_obj__trid_12 == null) {
                _trid_12 = state._tr_con_stop_stimulate_open_door_valve();
                this._OpCache_tr_con_stop_stimulate_open_door_valve = this._OpCache_tr_con_stop_stimulate_open_door_valve.set(read__tr_con_stop_stimulate_open_door_valve_state, _trid_12);
            } else {
                _trid_12 = _obj__trid_12;
            }

            if(_trid_12) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_con_stop_stimulate_open_door_valve = state._projected_state_for_con_stop_stimulate_open_door_valve();
                let _OpCache_with_parameter_con_stop_stimulate_open_door_valve: immutable.Map = this._OpCache_con_stop_stimulate_open_door_valve.get(_trid_12);
                if(_OpCache_with_parameter_con_stop_stimulate_open_door_valve != null) {
                    let writeState: _ProjectionWrite_con_stop_stimulate_open_door_valve = _OpCache_with_parameter_con_stop_stimulate_open_door_valve.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_con_stop_stimulate_open_door_valve(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.con_stop_stimulate_open_door_valve();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_con_stop_stimulate_open_door_valve();
                        _OpCache_with_parameter_con_stop_stimulate_open_door_valve = _OpCache_with_parameter_con_stop_stimulate_open_door_valve.set(readState, writeState);
                        this._OpCache_con_stop_stimulate_open_door_valve = this._OpCache_con_stop_stimulate_open_door_valve.set(_trid_12, _OpCache_with_parameter_con_stop_stimulate_open_door_valve);
                    }

                } else {
                    copiedState.con_stop_stimulate_open_door_valve();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_con_stop_stimulate_open_door_valve = copiedState._update_for_con_stop_stimulate_open_door_valve();
                    _OpCache_with_parameter_con_stop_stimulate_open_door_valve = new immutable.Map().set(readState, writeState);
                    this._OpCache_con_stop_stimulate_open_door_valve = this._OpCache_con_stop_stimulate_open_door_valve.set(_trid_12, _OpCache_with_parameter_con_stop_stimulate_open_door_valve);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_con_stimulate_close_door_valve_state : _ProjectionRead__tr_con_stimulate_close_door_valve = state._projected_state_for__tr_con_stimulate_close_door_valve();
            let _obj__trid_13: any = this._OpCache_tr_con_stimulate_close_door_valve.get(read__tr_con_stimulate_close_door_valve_state);
            let _trid_13: boolean;
            if(_obj__trid_13 == null) {
                _trid_13 = state._tr_con_stimulate_close_door_valve();
                this._OpCache_tr_con_stimulate_close_door_valve = this._OpCache_tr_con_stimulate_close_door_valve.set(read__tr_con_stimulate_close_door_valve_state, _trid_13);
            } else {
                _trid_13 = _obj__trid_13;
            }

            if(_trid_13) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_con_stimulate_close_door_valve = state._projected_state_for_con_stimulate_close_door_valve();
                let _OpCache_with_parameter_con_stimulate_close_door_valve: immutable.Map = this._OpCache_con_stimulate_close_door_valve.get(_trid_13);
                if(_OpCache_with_parameter_con_stimulate_close_door_valve != null) {
                    let writeState: _ProjectionWrite_con_stimulate_close_door_valve = _OpCache_with_parameter_con_stimulate_close_door_valve.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_con_stimulate_close_door_valve(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.con_stimulate_close_door_valve();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_con_stimulate_close_door_valve();
                        _OpCache_with_parameter_con_stimulate_close_door_valve = _OpCache_with_parameter_con_stimulate_close_door_valve.set(readState, writeState);
                        this._OpCache_con_stimulate_close_door_valve = this._OpCache_con_stimulate_close_door_valve.set(_trid_13, _OpCache_with_parameter_con_stimulate_close_door_valve);
                    }

                } else {
                    copiedState.con_stimulate_close_door_valve();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_con_stimulate_close_door_valve = copiedState._update_for_con_stimulate_close_door_valve();
                    _OpCache_with_parameter_con_stimulate_close_door_valve = new immutable.Map().set(readState, writeState);
                    this._OpCache_con_stimulate_close_door_valve = this._OpCache_con_stimulate_close_door_valve.set(_trid_13, _OpCache_with_parameter_con_stimulate_close_door_valve);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_con_stop_stimulate_close_door_valve_state : _ProjectionRead__tr_con_stop_stimulate_close_door_valve = state._projected_state_for__tr_con_stop_stimulate_close_door_valve();
            let _obj__trid_14: any = this._OpCache_tr_con_stop_stimulate_close_door_valve.get(read__tr_con_stop_stimulate_close_door_valve_state);
            let _trid_14: boolean;
            if(_obj__trid_14 == null) {
                _trid_14 = state._tr_con_stop_stimulate_close_door_valve();
                this._OpCache_tr_con_stop_stimulate_close_door_valve = this._OpCache_tr_con_stop_stimulate_close_door_valve.set(read__tr_con_stop_stimulate_close_door_valve_state, _trid_14);
            } else {
                _trid_14 = _obj__trid_14;
            }

            if(_trid_14) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_con_stop_stimulate_close_door_valve = state._projected_state_for_con_stop_stimulate_close_door_valve();
                let _OpCache_with_parameter_con_stop_stimulate_close_door_valve: immutable.Map = this._OpCache_con_stop_stimulate_close_door_valve.get(_trid_14);
                if(_OpCache_with_parameter_con_stop_stimulate_close_door_valve != null) {
                    let writeState: _ProjectionWrite_con_stop_stimulate_close_door_valve = _OpCache_with_parameter_con_stop_stimulate_close_door_valve.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_con_stop_stimulate_close_door_valve(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.con_stop_stimulate_close_door_valve();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_con_stop_stimulate_close_door_valve();
                        _OpCache_with_parameter_con_stop_stimulate_close_door_valve = _OpCache_with_parameter_con_stop_stimulate_close_door_valve.set(readState, writeState);
                        this._OpCache_con_stop_stimulate_close_door_valve = this._OpCache_con_stop_stimulate_close_door_valve.set(_trid_14, _OpCache_with_parameter_con_stop_stimulate_close_door_valve);
                    }

                } else {
                    copiedState.con_stop_stimulate_close_door_valve();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_con_stop_stimulate_close_door_valve = copiedState._update_for_con_stop_stimulate_close_door_valve();
                    _OpCache_with_parameter_con_stop_stimulate_close_door_valve = new immutable.Map().set(readState, writeState);
                    this._OpCache_con_stop_stimulate_close_door_valve = this._OpCache_con_stop_stimulate_close_door_valve.set(_trid_14, _OpCache_with_parameter_con_stop_stimulate_close_door_valve);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_con_stimulate_retract_gear_valve_state : _ProjectionRead__tr_con_stimulate_retract_gear_valve = state._projected_state_for__tr_con_stimulate_retract_gear_valve();
            let _obj__trid_15: any = this._OpCache_tr_con_stimulate_retract_gear_valve.get(read__tr_con_stimulate_retract_gear_valve_state);
            let _trid_15: boolean;
            if(_obj__trid_15 == null) {
                _trid_15 = state._tr_con_stimulate_retract_gear_valve();
                this._OpCache_tr_con_stimulate_retract_gear_valve = this._OpCache_tr_con_stimulate_retract_gear_valve.set(read__tr_con_stimulate_retract_gear_valve_state, _trid_15);
            } else {
                _trid_15 = _obj__trid_15;
            }

            if(_trid_15) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_con_stimulate_retract_gear_valve = state._projected_state_for_con_stimulate_retract_gear_valve();
                let _OpCache_with_parameter_con_stimulate_retract_gear_valve: immutable.Map = this._OpCache_con_stimulate_retract_gear_valve.get(_trid_15);
                if(_OpCache_with_parameter_con_stimulate_retract_gear_valve != null) {
                    let writeState: _ProjectionWrite_con_stimulate_retract_gear_valve = _OpCache_with_parameter_con_stimulate_retract_gear_valve.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_con_stimulate_retract_gear_valve(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.con_stimulate_retract_gear_valve();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_con_stimulate_retract_gear_valve();
                        _OpCache_with_parameter_con_stimulate_retract_gear_valve = _OpCache_with_parameter_con_stimulate_retract_gear_valve.set(readState, writeState);
                        this._OpCache_con_stimulate_retract_gear_valve = this._OpCache_con_stimulate_retract_gear_valve.set(_trid_15, _OpCache_with_parameter_con_stimulate_retract_gear_valve);
                    }

                } else {
                    copiedState.con_stimulate_retract_gear_valve();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_con_stimulate_retract_gear_valve = copiedState._update_for_con_stimulate_retract_gear_valve();
                    _OpCache_with_parameter_con_stimulate_retract_gear_valve = new immutable.Map().set(readState, writeState);
                    this._OpCache_con_stimulate_retract_gear_valve = this._OpCache_con_stimulate_retract_gear_valve.set(_trid_15, _OpCache_with_parameter_con_stimulate_retract_gear_valve);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_con_stop_stimulate_retract_gear_valve_state : _ProjectionRead__tr_con_stop_stimulate_retract_gear_valve = state._projected_state_for__tr_con_stop_stimulate_retract_gear_valve();
            let _obj__trid_16: any = this._OpCache_tr_con_stop_stimulate_retract_gear_valve.get(read__tr_con_stop_stimulate_retract_gear_valve_state);
            let _trid_16: boolean;
            if(_obj__trid_16 == null) {
                _trid_16 = state._tr_con_stop_stimulate_retract_gear_valve();
                this._OpCache_tr_con_stop_stimulate_retract_gear_valve = this._OpCache_tr_con_stop_stimulate_retract_gear_valve.set(read__tr_con_stop_stimulate_retract_gear_valve_state, _trid_16);
            } else {
                _trid_16 = _obj__trid_16;
            }

            if(_trid_16) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_con_stop_stimulate_retract_gear_valve = state._projected_state_for_con_stop_stimulate_retract_gear_valve();
                let _OpCache_with_parameter_con_stop_stimulate_retract_gear_valve: immutable.Map = this._OpCache_con_stop_stimulate_retract_gear_valve.get(_trid_16);
                if(_OpCache_with_parameter_con_stop_stimulate_retract_gear_valve != null) {
                    let writeState: _ProjectionWrite_con_stop_stimulate_retract_gear_valve = _OpCache_with_parameter_con_stop_stimulate_retract_gear_valve.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_con_stop_stimulate_retract_gear_valve(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.con_stop_stimulate_retract_gear_valve();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_con_stop_stimulate_retract_gear_valve();
                        _OpCache_with_parameter_con_stop_stimulate_retract_gear_valve = _OpCache_with_parameter_con_stop_stimulate_retract_gear_valve.set(readState, writeState);
                        this._OpCache_con_stop_stimulate_retract_gear_valve = this._OpCache_con_stop_stimulate_retract_gear_valve.set(_trid_16, _OpCache_with_parameter_con_stop_stimulate_retract_gear_valve);
                    }

                } else {
                    copiedState.con_stop_stimulate_retract_gear_valve();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_con_stop_stimulate_retract_gear_valve = copiedState._update_for_con_stop_stimulate_retract_gear_valve();
                    _OpCache_with_parameter_con_stop_stimulate_retract_gear_valve = new immutable.Map().set(readState, writeState);
                    this._OpCache_con_stop_stimulate_retract_gear_valve = this._OpCache_con_stop_stimulate_retract_gear_valve.set(_trid_16, _OpCache_with_parameter_con_stop_stimulate_retract_gear_valve);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_con_stimulate_extend_gear_valve_state : _ProjectionRead__tr_con_stimulate_extend_gear_valve = state._projected_state_for__tr_con_stimulate_extend_gear_valve();
            let _obj__trid_17: any = this._OpCache_tr_con_stimulate_extend_gear_valve.get(read__tr_con_stimulate_extend_gear_valve_state);
            let _trid_17: boolean;
            if(_obj__trid_17 == null) {
                _trid_17 = state._tr_con_stimulate_extend_gear_valve();
                this._OpCache_tr_con_stimulate_extend_gear_valve = this._OpCache_tr_con_stimulate_extend_gear_valve.set(read__tr_con_stimulate_extend_gear_valve_state, _trid_17);
            } else {
                _trid_17 = _obj__trid_17;
            }

            if(_trid_17) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_con_stimulate_extend_gear_valve = state._projected_state_for_con_stimulate_extend_gear_valve();
                let _OpCache_with_parameter_con_stimulate_extend_gear_valve: immutable.Map = this._OpCache_con_stimulate_extend_gear_valve.get(_trid_17);
                if(_OpCache_with_parameter_con_stimulate_extend_gear_valve != null) {
                    let writeState: _ProjectionWrite_con_stimulate_extend_gear_valve = _OpCache_with_parameter_con_stimulate_extend_gear_valve.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_con_stimulate_extend_gear_valve(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.con_stimulate_extend_gear_valve();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_con_stimulate_extend_gear_valve();
                        _OpCache_with_parameter_con_stimulate_extend_gear_valve = _OpCache_with_parameter_con_stimulate_extend_gear_valve.set(readState, writeState);
                        this._OpCache_con_stimulate_extend_gear_valve = this._OpCache_con_stimulate_extend_gear_valve.set(_trid_17, _OpCache_with_parameter_con_stimulate_extend_gear_valve);
                    }

                } else {
                    copiedState.con_stimulate_extend_gear_valve();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_con_stimulate_extend_gear_valve = copiedState._update_for_con_stimulate_extend_gear_valve();
                    _OpCache_with_parameter_con_stimulate_extend_gear_valve = new immutable.Map().set(readState, writeState);
                    this._OpCache_con_stimulate_extend_gear_valve = this._OpCache_con_stimulate_extend_gear_valve.set(_trid_17, _OpCache_with_parameter_con_stimulate_extend_gear_valve);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_con_stop_stimulate_extend_gear_valve_state : _ProjectionRead__tr_con_stop_stimulate_extend_gear_valve = state._projected_state_for__tr_con_stop_stimulate_extend_gear_valve();
            let _obj__trid_18: any = this._OpCache_tr_con_stop_stimulate_extend_gear_valve.get(read__tr_con_stop_stimulate_extend_gear_valve_state);
            let _trid_18: boolean;
            if(_obj__trid_18 == null) {
                _trid_18 = state._tr_con_stop_stimulate_extend_gear_valve();
                this._OpCache_tr_con_stop_stimulate_extend_gear_valve = this._OpCache_tr_con_stop_stimulate_extend_gear_valve.set(read__tr_con_stop_stimulate_extend_gear_valve_state, _trid_18);
            } else {
                _trid_18 = _obj__trid_18;
            }

            if(_trid_18) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_con_stop_stimulate_extend_gear_valve = state._projected_state_for_con_stop_stimulate_extend_gear_valve();
                let _OpCache_with_parameter_con_stop_stimulate_extend_gear_valve: immutable.Map = this._OpCache_con_stop_stimulate_extend_gear_valve.get(_trid_18);
                if(_OpCache_with_parameter_con_stop_stimulate_extend_gear_valve != null) {
                    let writeState: _ProjectionWrite_con_stop_stimulate_extend_gear_valve = _OpCache_with_parameter_con_stop_stimulate_extend_gear_valve.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_con_stop_stimulate_extend_gear_valve(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.con_stop_stimulate_extend_gear_valve();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_con_stop_stimulate_extend_gear_valve();
                        _OpCache_with_parameter_con_stop_stimulate_extend_gear_valve = _OpCache_with_parameter_con_stop_stimulate_extend_gear_valve.set(readState, writeState);
                        this._OpCache_con_stop_stimulate_extend_gear_valve = this._OpCache_con_stop_stimulate_extend_gear_valve.set(_trid_18, _OpCache_with_parameter_con_stop_stimulate_extend_gear_valve);
                    }

                } else {
                    copiedState.con_stop_stimulate_extend_gear_valve();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_con_stop_stimulate_extend_gear_valve = copiedState._update_for_con_stop_stimulate_extend_gear_valve();
                    _OpCache_with_parameter_con_stop_stimulate_extend_gear_valve = new immutable.Map().set(readState, writeState);
                    this._OpCache_con_stop_stimulate_extend_gear_valve = this._OpCache_con_stop_stimulate_extend_gear_valve.set(_trid_18, _OpCache_with_parameter_con_stop_stimulate_extend_gear_valve);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_env_start_retracting_first_state : _ProjectionRead__tr_env_start_retracting_first = state._projected_state_for__tr_env_start_retracting_first();
            let _trid_19 : BSet<POSITION>  = this._OpCache_tr_env_start_retracting_first.get(read__tr_env_start_retracting_first_state);
            if(_trid_19 == null) {
                _trid_19 = state._tr_env_start_retracting_first();
                this._OpCache_tr_env_start_retracting_first = this._OpCache_tr_env_start_retracting_first.set(read__tr_env_start_retracting_first_state, _trid_19);
            }

            for(let param of _trid_19) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_env_start_retracting_first = state._projected_state_for_env_start_retracting_first();
                let _OpCache_with_parameter_env_start_retracting_first: immutable.Map = this._OpCache_env_start_retracting_first.get(param);
                if(_OpCache_with_parameter_env_start_retracting_first != null) {
                    let writeState: _ProjectionWrite_env_start_retracting_first = _OpCache_with_parameter_env_start_retracting_first.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_env_start_retracting_first(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.env_start_retracting_first(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_env_start_retracting_first();
                        _OpCache_with_parameter_env_start_retracting_first = _OpCache_with_parameter_env_start_retracting_first.set(readState, writeState);
                        this._OpCache_env_start_retracting_first = this._OpCache_env_start_retracting_first.set(param, _OpCache_with_parameter_env_start_retracting_first);
                    }

                } else {
                    copiedState.env_start_retracting_first(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_env_start_retracting_first = copiedState._update_for_env_start_retracting_first();
                    _OpCache_with_parameter_env_start_retracting_first = new immutable.Map().set(readState, writeState);
                    this._OpCache_env_start_retracting_first = this._OpCache_env_start_retracting_first.set(param, _OpCache_with_parameter_env_start_retracting_first);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_env_retract_gear_skip_state : _ProjectionRead__tr_env_retract_gear_skip = state._projected_state_for__tr_env_retract_gear_skip();
            let _trid_20 : BSet<POSITION>  = this._OpCache_tr_env_retract_gear_skip.get(read__tr_env_retract_gear_skip_state);
            if(_trid_20 == null) {
                _trid_20 = state._tr_env_retract_gear_skip();
                this._OpCache_tr_env_retract_gear_skip = this._OpCache_tr_env_retract_gear_skip.set(read__tr_env_retract_gear_skip_state, _trid_20);
            }

            for(let param of _trid_20) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_env_retract_gear_skip = state._projected_state_for_env_retract_gear_skip();
                let _OpCache_with_parameter_env_retract_gear_skip: immutable.Map = this._OpCache_env_retract_gear_skip.get(param);
                if(_OpCache_with_parameter_env_retract_gear_skip != null) {
                    let writeState: _ProjectionWrite_env_retract_gear_skip = _OpCache_with_parameter_env_retract_gear_skip.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_env_retract_gear_skip(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.env_retract_gear_skip(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_env_retract_gear_skip();
                        _OpCache_with_parameter_env_retract_gear_skip = _OpCache_with_parameter_env_retract_gear_skip.set(readState, writeState);
                        this._OpCache_env_retract_gear_skip = this._OpCache_env_retract_gear_skip.set(param, _OpCache_with_parameter_env_retract_gear_skip);
                    }

                } else {
                    copiedState.env_retract_gear_skip(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_env_retract_gear_skip = copiedState._update_for_env_retract_gear_skip();
                    _OpCache_with_parameter_env_retract_gear_skip = new immutable.Map().set(readState, writeState);
                    this._OpCache_env_retract_gear_skip = this._OpCache_env_retract_gear_skip.set(param, _OpCache_with_parameter_env_retract_gear_skip);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_env_retract_gear_last_state : _ProjectionRead__tr_env_retract_gear_last = state._projected_state_for__tr_env_retract_gear_last();
            let _trid_21 : BSet<POSITION>  = this._OpCache_tr_env_retract_gear_last.get(read__tr_env_retract_gear_last_state);
            if(_trid_21 == null) {
                _trid_21 = state._tr_env_retract_gear_last();
                this._OpCache_tr_env_retract_gear_last = this._OpCache_tr_env_retract_gear_last.set(read__tr_env_retract_gear_last_state, _trid_21);
            }

            for(let param of _trid_21) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_env_retract_gear_last = state._projected_state_for_env_retract_gear_last();
                let _OpCache_with_parameter_env_retract_gear_last: immutable.Map = this._OpCache_env_retract_gear_last.get(param);
                if(_OpCache_with_parameter_env_retract_gear_last != null) {
                    let writeState: _ProjectionWrite_env_retract_gear_last = _OpCache_with_parameter_env_retract_gear_last.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_env_retract_gear_last(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.env_retract_gear_last(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_env_retract_gear_last();
                        _OpCache_with_parameter_env_retract_gear_last = _OpCache_with_parameter_env_retract_gear_last.set(readState, writeState);
                        this._OpCache_env_retract_gear_last = this._OpCache_env_retract_gear_last.set(param, _OpCache_with_parameter_env_retract_gear_last);
                    }

                } else {
                    copiedState.env_retract_gear_last(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_env_retract_gear_last = copiedState._update_for_env_retract_gear_last();
                    _OpCache_with_parameter_env_retract_gear_last = new immutable.Map().set(readState, writeState);
                    this._OpCache_env_retract_gear_last = this._OpCache_env_retract_gear_last.set(param, _OpCache_with_parameter_env_retract_gear_last);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_env_start_extending_state : _ProjectionRead__tr_env_start_extending = state._projected_state_for__tr_env_start_extending();
            let _trid_22 : BSet<POSITION>  = this._OpCache_tr_env_start_extending.get(read__tr_env_start_extending_state);
            if(_trid_22 == null) {
                _trid_22 = state._tr_env_start_extending();
                this._OpCache_tr_env_start_extending = this._OpCache_tr_env_start_extending.set(read__tr_env_start_extending_state, _trid_22);
            }

            for(let param of _trid_22) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_env_start_extending = state._projected_state_for_env_start_extending();
                let _OpCache_with_parameter_env_start_extending: immutable.Map = this._OpCache_env_start_extending.get(param);
                if(_OpCache_with_parameter_env_start_extending != null) {
                    let writeState: _ProjectionWrite_env_start_extending = _OpCache_with_parameter_env_start_extending.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_env_start_extending(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.env_start_extending(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_env_start_extending();
                        _OpCache_with_parameter_env_start_extending = _OpCache_with_parameter_env_start_extending.set(readState, writeState);
                        this._OpCache_env_start_extending = this._OpCache_env_start_extending.set(param, _OpCache_with_parameter_env_start_extending);
                    }

                } else {
                    copiedState.env_start_extending(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_env_start_extending = copiedState._update_for_env_start_extending();
                    _OpCache_with_parameter_env_start_extending = new immutable.Map().set(readState, writeState);
                    this._OpCache_env_start_extending = this._OpCache_env_start_extending.set(param, _OpCache_with_parameter_env_start_extending);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_env_extend_gear_last_state : _ProjectionRead__tr_env_extend_gear_last = state._projected_state_for__tr_env_extend_gear_last();
            let _trid_23 : BSet<POSITION>  = this._OpCache_tr_env_extend_gear_last.get(read__tr_env_extend_gear_last_state);
            if(_trid_23 == null) {
                _trid_23 = state._tr_env_extend_gear_last();
                this._OpCache_tr_env_extend_gear_last = this._OpCache_tr_env_extend_gear_last.set(read__tr_env_extend_gear_last_state, _trid_23);
            }

            for(let param of _trid_23) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_env_extend_gear_last = state._projected_state_for_env_extend_gear_last();
                let _OpCache_with_parameter_env_extend_gear_last: immutable.Map = this._OpCache_env_extend_gear_last.get(param);
                if(_OpCache_with_parameter_env_extend_gear_last != null) {
                    let writeState: _ProjectionWrite_env_extend_gear_last = _OpCache_with_parameter_env_extend_gear_last.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_env_extend_gear_last(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.env_extend_gear_last(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_env_extend_gear_last();
                        _OpCache_with_parameter_env_extend_gear_last = _OpCache_with_parameter_env_extend_gear_last.set(readState, writeState);
                        this._OpCache_env_extend_gear_last = this._OpCache_env_extend_gear_last.set(param, _OpCache_with_parameter_env_extend_gear_last);
                    }

                } else {
                    copiedState.env_extend_gear_last(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_env_extend_gear_last = copiedState._update_for_env_extend_gear_last();
                    _OpCache_with_parameter_env_extend_gear_last = new immutable.Map().set(readState, writeState);
                    this._OpCache_env_extend_gear_last = this._OpCache_env_extend_gear_last.set(param, _OpCache_with_parameter_env_extend_gear_last);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_env_extend_gear_skip_state : _ProjectionRead__tr_env_extend_gear_skip = state._projected_state_for__tr_env_extend_gear_skip();
            let _trid_24 : BSet<POSITION>  = this._OpCache_tr_env_extend_gear_skip.get(read__tr_env_extend_gear_skip_state);
            if(_trid_24 == null) {
                _trid_24 = state._tr_env_extend_gear_skip();
                this._OpCache_tr_env_extend_gear_skip = this._OpCache_tr_env_extend_gear_skip.set(read__tr_env_extend_gear_skip_state, _trid_24);
            }

            for(let param of _trid_24) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_env_extend_gear_skip = state._projected_state_for_env_extend_gear_skip();
                let _OpCache_with_parameter_env_extend_gear_skip: immutable.Map = this._OpCache_env_extend_gear_skip.get(param);
                if(_OpCache_with_parameter_env_extend_gear_skip != null) {
                    let writeState: _ProjectionWrite_env_extend_gear_skip = _OpCache_with_parameter_env_extend_gear_skip.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_env_extend_gear_skip(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.env_extend_gear_skip(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_env_extend_gear_skip();
                        _OpCache_with_parameter_env_extend_gear_skip = _OpCache_with_parameter_env_extend_gear_skip.set(readState, writeState);
                        this._OpCache_env_extend_gear_skip = this._OpCache_env_extend_gear_skip.set(param, _OpCache_with_parameter_env_extend_gear_skip);
                    }

                } else {
                    copiedState.env_extend_gear_skip(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_env_extend_gear_skip = copiedState._update_for_env_extend_gear_skip();
                    _OpCache_with_parameter_env_extend_gear_skip = new immutable.Map().set(readState, writeState);
                    this._OpCache_env_extend_gear_skip = this._OpCache_env_extend_gear_skip.set(param, _OpCache_with_parameter_env_extend_gear_skip);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_env_start_open_door_state : _ProjectionRead__tr_env_start_open_door = state._projected_state_for__tr_env_start_open_door();
            let _trid_25 : BSet<POSITION>  = this._OpCache_tr_env_start_open_door.get(read__tr_env_start_open_door_state);
            if(_trid_25 == null) {
                _trid_25 = state._tr_env_start_open_door();
                this._OpCache_tr_env_start_open_door = this._OpCache_tr_env_start_open_door.set(read__tr_env_start_open_door_state, _trid_25);
            }

            for(let param of _trid_25) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_env_start_open_door = state._projected_state_for_env_start_open_door();
                let _OpCache_with_parameter_env_start_open_door: immutable.Map = this._OpCache_env_start_open_door.get(param);
                if(_OpCache_with_parameter_env_start_open_door != null) {
                    let writeState: _ProjectionWrite_env_start_open_door = _OpCache_with_parameter_env_start_open_door.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_env_start_open_door(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.env_start_open_door(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_env_start_open_door();
                        _OpCache_with_parameter_env_start_open_door = _OpCache_with_parameter_env_start_open_door.set(readState, writeState);
                        this._OpCache_env_start_open_door = this._OpCache_env_start_open_door.set(param, _OpCache_with_parameter_env_start_open_door);
                    }

                } else {
                    copiedState.env_start_open_door(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_env_start_open_door = copiedState._update_for_env_start_open_door();
                    _OpCache_with_parameter_env_start_open_door = new immutable.Map().set(readState, writeState);
                    this._OpCache_env_start_open_door = this._OpCache_env_start_open_door.set(param, _OpCache_with_parameter_env_start_open_door);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_env_open_door_last_state : _ProjectionRead__tr_env_open_door_last = state._projected_state_for__tr_env_open_door_last();
            let _trid_26 : BSet<POSITION>  = this._OpCache_tr_env_open_door_last.get(read__tr_env_open_door_last_state);
            if(_trid_26 == null) {
                _trid_26 = state._tr_env_open_door_last();
                this._OpCache_tr_env_open_door_last = this._OpCache_tr_env_open_door_last.set(read__tr_env_open_door_last_state, _trid_26);
            }

            for(let param of _trid_26) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_env_open_door_last = state._projected_state_for_env_open_door_last();
                let _OpCache_with_parameter_env_open_door_last: immutable.Map = this._OpCache_env_open_door_last.get(param);
                if(_OpCache_with_parameter_env_open_door_last != null) {
                    let writeState: _ProjectionWrite_env_open_door_last = _OpCache_with_parameter_env_open_door_last.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_env_open_door_last(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.env_open_door_last(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_env_open_door_last();
                        _OpCache_with_parameter_env_open_door_last = _OpCache_with_parameter_env_open_door_last.set(readState, writeState);
                        this._OpCache_env_open_door_last = this._OpCache_env_open_door_last.set(param, _OpCache_with_parameter_env_open_door_last);
                    }

                } else {
                    copiedState.env_open_door_last(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_env_open_door_last = copiedState._update_for_env_open_door_last();
                    _OpCache_with_parameter_env_open_door_last = new immutable.Map().set(readState, writeState);
                    this._OpCache_env_open_door_last = this._OpCache_env_open_door_last.set(param, _OpCache_with_parameter_env_open_door_last);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_env_open_door_skip_state : _ProjectionRead__tr_env_open_door_skip = state._projected_state_for__tr_env_open_door_skip();
            let _trid_27 : BSet<POSITION>  = this._OpCache_tr_env_open_door_skip.get(read__tr_env_open_door_skip_state);
            if(_trid_27 == null) {
                _trid_27 = state._tr_env_open_door_skip();
                this._OpCache_tr_env_open_door_skip = this._OpCache_tr_env_open_door_skip.set(read__tr_env_open_door_skip_state, _trid_27);
            }

            for(let param of _trid_27) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_env_open_door_skip = state._projected_state_for_env_open_door_skip();
                let _OpCache_with_parameter_env_open_door_skip: immutable.Map = this._OpCache_env_open_door_skip.get(param);
                if(_OpCache_with_parameter_env_open_door_skip != null) {
                    let writeState: _ProjectionWrite_env_open_door_skip = _OpCache_with_parameter_env_open_door_skip.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_env_open_door_skip(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.env_open_door_skip(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_env_open_door_skip();
                        _OpCache_with_parameter_env_open_door_skip = _OpCache_with_parameter_env_open_door_skip.set(readState, writeState);
                        this._OpCache_env_open_door_skip = this._OpCache_env_open_door_skip.set(param, _OpCache_with_parameter_env_open_door_skip);
                    }

                } else {
                    copiedState.env_open_door_skip(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_env_open_door_skip = copiedState._update_for_env_open_door_skip();
                    _OpCache_with_parameter_env_open_door_skip = new immutable.Map().set(readState, writeState);
                    this._OpCache_env_open_door_skip = this._OpCache_env_open_door_skip.set(param, _OpCache_with_parameter_env_open_door_skip);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_env_start_close_door_state : _ProjectionRead__tr_env_start_close_door = state._projected_state_for__tr_env_start_close_door();
            let _trid_28 : BSet<POSITION>  = this._OpCache_tr_env_start_close_door.get(read__tr_env_start_close_door_state);
            if(_trid_28 == null) {
                _trid_28 = state._tr_env_start_close_door();
                this._OpCache_tr_env_start_close_door = this._OpCache_tr_env_start_close_door.set(read__tr_env_start_close_door_state, _trid_28);
            }

            for(let param of _trid_28) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_env_start_close_door = state._projected_state_for_env_start_close_door();
                let _OpCache_with_parameter_env_start_close_door: immutable.Map = this._OpCache_env_start_close_door.get(param);
                if(_OpCache_with_parameter_env_start_close_door != null) {
                    let writeState: _ProjectionWrite_env_start_close_door = _OpCache_with_parameter_env_start_close_door.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_env_start_close_door(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.env_start_close_door(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_env_start_close_door();
                        _OpCache_with_parameter_env_start_close_door = _OpCache_with_parameter_env_start_close_door.set(readState, writeState);
                        this._OpCache_env_start_close_door = this._OpCache_env_start_close_door.set(param, _OpCache_with_parameter_env_start_close_door);
                    }

                } else {
                    copiedState.env_start_close_door(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_env_start_close_door = copiedState._update_for_env_start_close_door();
                    _OpCache_with_parameter_env_start_close_door = new immutable.Map().set(readState, writeState);
                    this._OpCache_env_start_close_door = this._OpCache_env_start_close_door.set(param, _OpCache_with_parameter_env_start_close_door);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_env_close_door_state : _ProjectionRead__tr_env_close_door = state._projected_state_for__tr_env_close_door();
            let _trid_29 : BSet<POSITION>  = this._OpCache_tr_env_close_door.get(read__tr_env_close_door_state);
            if(_trid_29 == null) {
                _trid_29 = state._tr_env_close_door();
                this._OpCache_tr_env_close_door = this._OpCache_tr_env_close_door.set(read__tr_env_close_door_state, _trid_29);
            }

            for(let param of _trid_29) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_env_close_door = state._projected_state_for_env_close_door();
                let _OpCache_with_parameter_env_close_door: immutable.Map = this._OpCache_env_close_door.get(param);
                if(_OpCache_with_parameter_env_close_door != null) {
                    let writeState: _ProjectionWrite_env_close_door = _OpCache_with_parameter_env_close_door.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_env_close_door(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.env_close_door(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_env_close_door();
                        _OpCache_with_parameter_env_close_door = _OpCache_with_parameter_env_close_door.set(readState, writeState);
                        this._OpCache_env_close_door = this._OpCache_env_close_door.set(param, _OpCache_with_parameter_env_close_door);
                    }

                } else {
                    copiedState.env_close_door(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_env_close_door = copiedState._update_for_env_close_door();
                    _OpCache_with_parameter_env_close_door = new immutable.Map().set(readState, writeState);
                    this._OpCache_env_close_door = this._OpCache_env_close_door.set(param, _OpCache_with_parameter_env_close_door);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_env_close_door_skip_state : _ProjectionRead__tr_env_close_door_skip = state._projected_state_for__tr_env_close_door_skip();
            let _trid_30 : BSet<POSITION>  = this._OpCache_tr_env_close_door_skip.get(read__tr_env_close_door_skip_state);
            if(_trid_30 == null) {
                _trid_30 = state._tr_env_close_door_skip();
                this._OpCache_tr_env_close_door_skip = this._OpCache_tr_env_close_door_skip.set(read__tr_env_close_door_skip_state, _trid_30);
            }

            for(let param of _trid_30) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_env_close_door_skip = state._projected_state_for_env_close_door_skip();
                let _OpCache_with_parameter_env_close_door_skip: immutable.Map = this._OpCache_env_close_door_skip.get(param);
                if(_OpCache_with_parameter_env_close_door_skip != null) {
                    let writeState: _ProjectionWrite_env_close_door_skip = _OpCache_with_parameter_env_close_door_skip.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_env_close_door_skip(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.env_close_door_skip(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_env_close_door_skip();
                        _OpCache_with_parameter_env_close_door_skip = _OpCache_with_parameter_env_close_door_skip.set(readState, writeState);
                        this._OpCache_env_close_door_skip = this._OpCache_env_close_door_skip.set(param, _OpCache_with_parameter_env_close_door_skip);
                    }

                } else {
                    copiedState.env_close_door_skip(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_env_close_door_skip = copiedState._update_for_env_close_door_skip();
                    _OpCache_with_parameter_env_close_door_skip = new immutable.Map().set(readState, writeState);
                    this._OpCache_env_close_door_skip = this._OpCache_env_close_door_skip.set(param, _OpCache_with_parameter_env_close_door_skip);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_toggle_handle_up_state : _ProjectionRead__tr_toggle_handle_up = state._projected_state_for__tr_toggle_handle_up();
            let _obj__trid_31: any = this._OpCache_tr_toggle_handle_up.get(read__tr_toggle_handle_up_state);
            let _trid_31: boolean;
            if(_obj__trid_31 == null) {
                _trid_31 = state._tr_toggle_handle_up();
                this._OpCache_tr_toggle_handle_up = this._OpCache_tr_toggle_handle_up.set(read__tr_toggle_handle_up_state, _trid_31);
            } else {
                _trid_31 = _obj__trid_31;
            }

            if(_trid_31) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_toggle_handle_up = state._projected_state_for_toggle_handle_up();
                let _OpCache_with_parameter_toggle_handle_up: immutable.Map = this._OpCache_toggle_handle_up.get(_trid_31);
                if(_OpCache_with_parameter_toggle_handle_up != null) {
                    let writeState: _ProjectionWrite_toggle_handle_up = _OpCache_with_parameter_toggle_handle_up.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_toggle_handle_up(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.toggle_handle_up();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_toggle_handle_up();
                        _OpCache_with_parameter_toggle_handle_up = _OpCache_with_parameter_toggle_handle_up.set(readState, writeState);
                        this._OpCache_toggle_handle_up = this._OpCache_toggle_handle_up.set(_trid_31, _OpCache_with_parameter_toggle_handle_up);
                    }

                } else {
                    copiedState.toggle_handle_up();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_toggle_handle_up = copiedState._update_for_toggle_handle_up();
                    _OpCache_with_parameter_toggle_handle_up = new immutable.Map().set(readState, writeState);
                    this._OpCache_toggle_handle_up = this._OpCache_toggle_handle_up.set(_trid_31, _OpCache_with_parameter_toggle_handle_up);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_toggle_handle_down_state : _ProjectionRead__tr_toggle_handle_down = state._projected_state_for__tr_toggle_handle_down();
            let _obj__trid_32: any = this._OpCache_tr_toggle_handle_down.get(read__tr_toggle_handle_down_state);
            let _trid_32: boolean;
            if(_obj__trid_32 == null) {
                _trid_32 = state._tr_toggle_handle_down();
                this._OpCache_tr_toggle_handle_down = this._OpCache_tr_toggle_handle_down.set(read__tr_toggle_handle_down_state, _trid_32);
            } else {
                _trid_32 = _obj__trid_32;
            }

            if(_trid_32) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_toggle_handle_down = state._projected_state_for_toggle_handle_down();
                let _OpCache_with_parameter_toggle_handle_down: immutable.Map = this._OpCache_toggle_handle_down.get(_trid_32);
                if(_OpCache_with_parameter_toggle_handle_down != null) {
                    let writeState: _ProjectionWrite_toggle_handle_down = _OpCache_with_parameter_toggle_handle_down.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_toggle_handle_down(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.toggle_handle_down();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_toggle_handle_down();
                        _OpCache_with_parameter_toggle_handle_down = _OpCache_with_parameter_toggle_handle_down.set(readState, writeState);
                        this._OpCache_toggle_handle_down = this._OpCache_toggle_handle_down.set(_trid_32, _OpCache_with_parameter_toggle_handle_down);
                    }

                } else {
                    copiedState.toggle_handle_down();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_toggle_handle_down = copiedState._update_for_toggle_handle_down();
                    _OpCache_with_parameter_toggle_handle_down = new immutable.Map().set(readState, writeState);
                    this._OpCache_toggle_handle_down = this._OpCache_toggle_handle_down.set(_trid_32, _OpCache_with_parameter_toggle_handle_down);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_con_stimulate_general_valve_state : _ProjectionRead__tr_con_stimulate_general_valve = state._projected_state_for__tr_con_stimulate_general_valve();
            let _obj__trid_33: any = this._OpCache_tr_con_stimulate_general_valve.get(read__tr_con_stimulate_general_valve_state);
            let _trid_33: boolean;
            if(_obj__trid_33 == null) {
                _trid_33 = state._tr_con_stimulate_general_valve();
                this._OpCache_tr_con_stimulate_general_valve = this._OpCache_tr_con_stimulate_general_valve.set(read__tr_con_stimulate_general_valve_state, _trid_33);
            } else {
                _trid_33 = _obj__trid_33;
            }

            if(_trid_33) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_con_stimulate_general_valve = state._projected_state_for_con_stimulate_general_valve();
                let _OpCache_with_parameter_con_stimulate_general_valve: immutable.Map = this._OpCache_con_stimulate_general_valve.get(_trid_33);
                if(_OpCache_with_parameter_con_stimulate_general_valve != null) {
                    let writeState: _ProjectionWrite_con_stimulate_general_valve = _OpCache_with_parameter_con_stimulate_general_valve.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_con_stimulate_general_valve(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.con_stimulate_general_valve();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_con_stimulate_general_valve();
                        _OpCache_with_parameter_con_stimulate_general_valve = _OpCache_with_parameter_con_stimulate_general_valve.set(readState, writeState);
                        this._OpCache_con_stimulate_general_valve = this._OpCache_con_stimulate_general_valve.set(_trid_33, _OpCache_with_parameter_con_stimulate_general_valve);
                    }

                } else {
                    copiedState.con_stimulate_general_valve();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_con_stimulate_general_valve = copiedState._update_for_con_stimulate_general_valve();
                    _OpCache_with_parameter_con_stimulate_general_valve = new immutable.Map().set(readState, writeState);
                    this._OpCache_con_stimulate_general_valve = this._OpCache_con_stimulate_general_valve.set(_trid_33, _OpCache_with_parameter_con_stimulate_general_valve);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_con_stop_stimulate_general_valve_state : _ProjectionRead__tr_con_stop_stimulate_general_valve = state._projected_state_for__tr_con_stop_stimulate_general_valve();
            let _obj__trid_34: any = this._OpCache_tr_con_stop_stimulate_general_valve.get(read__tr_con_stop_stimulate_general_valve_state);
            let _trid_34: boolean;
            if(_obj__trid_34 == null) {
                _trid_34 = state._tr_con_stop_stimulate_general_valve();
                this._OpCache_tr_con_stop_stimulate_general_valve = this._OpCache_tr_con_stop_stimulate_general_valve.set(read__tr_con_stop_stimulate_general_valve_state, _trid_34);
            } else {
                _trid_34 = _obj__trid_34;
            }

            if(_trid_34) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_con_stop_stimulate_general_valve = state._projected_state_for_con_stop_stimulate_general_valve();
                let _OpCache_with_parameter_con_stop_stimulate_general_valve: immutable.Map = this._OpCache_con_stop_stimulate_general_valve.get(_trid_34);
                if(_OpCache_with_parameter_con_stop_stimulate_general_valve != null) {
                    let writeState: _ProjectionWrite_con_stop_stimulate_general_valve = _OpCache_with_parameter_con_stop_stimulate_general_valve.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_con_stop_stimulate_general_valve(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.con_stop_stimulate_general_valve();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_con_stop_stimulate_general_valve();
                        _OpCache_with_parameter_con_stop_stimulate_general_valve = _OpCache_with_parameter_con_stop_stimulate_general_valve.set(readState, writeState);
                        this._OpCache_con_stop_stimulate_general_valve = this._OpCache_con_stop_stimulate_general_valve.set(_trid_34, _OpCache_with_parameter_con_stop_stimulate_general_valve);
                    }

                } else {
                    copiedState.con_stop_stimulate_general_valve();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_con_stop_stimulate_general_valve = copiedState._update_for_con_stop_stimulate_general_valve();
                    _OpCache_with_parameter_con_stop_stimulate_general_valve = new immutable.Map().set(readState, writeState);
                    this._OpCache_con_stop_stimulate_general_valve = this._OpCache_con_stop_stimulate_general_valve.set(_trid_34, _OpCache_with_parameter_con_stop_stimulate_general_valve);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_evn_open_general_valve_state : _ProjectionRead__tr_evn_open_general_valve = state._projected_state_for__tr_evn_open_general_valve();
            let _obj__trid_35: any = this._OpCache_tr_evn_open_general_valve.get(read__tr_evn_open_general_valve_state);
            let _trid_35: boolean;
            if(_obj__trid_35 == null) {
                _trid_35 = state._tr_evn_open_general_valve();
                this._OpCache_tr_evn_open_general_valve = this._OpCache_tr_evn_open_general_valve.set(read__tr_evn_open_general_valve_state, _trid_35);
            } else {
                _trid_35 = _obj__trid_35;
            }

            if(_trid_35) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_evn_open_general_valve = state._projected_state_for_evn_open_general_valve();
                let _OpCache_with_parameter_evn_open_general_valve: immutable.Map = this._OpCache_evn_open_general_valve.get(_trid_35);
                if(_OpCache_with_parameter_evn_open_general_valve != null) {
                    let writeState: _ProjectionWrite_evn_open_general_valve = _OpCache_with_parameter_evn_open_general_valve.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_evn_open_general_valve(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.evn_open_general_valve();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_evn_open_general_valve();
                        _OpCache_with_parameter_evn_open_general_valve = _OpCache_with_parameter_evn_open_general_valve.set(readState, writeState);
                        this._OpCache_evn_open_general_valve = this._OpCache_evn_open_general_valve.set(_trid_35, _OpCache_with_parameter_evn_open_general_valve);
                    }

                } else {
                    copiedState.evn_open_general_valve();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_evn_open_general_valve = copiedState._update_for_evn_open_general_valve();
                    _OpCache_with_parameter_evn_open_general_valve = new immutable.Map().set(readState, writeState);
                    this._OpCache_evn_open_general_valve = this._OpCache_evn_open_general_valve.set(_trid_35, _OpCache_with_parameter_evn_open_general_valve);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_evn_close_general_valve_state : _ProjectionRead__tr_evn_close_general_valve = state._projected_state_for__tr_evn_close_general_valve();
            let _obj__trid_36: any = this._OpCache_tr_evn_close_general_valve.get(read__tr_evn_close_general_valve_state);
            let _trid_36: boolean;
            if(_obj__trid_36 == null) {
                _trid_36 = state._tr_evn_close_general_valve();
                this._OpCache_tr_evn_close_general_valve = this._OpCache_tr_evn_close_general_valve.set(read__tr_evn_close_general_valve_state, _trid_36);
            } else {
                _trid_36 = _obj__trid_36;
            }

            if(_trid_36) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_evn_close_general_valve = state._projected_state_for_evn_close_general_valve();
                let _OpCache_with_parameter_evn_close_general_valve: immutable.Map = this._OpCache_evn_close_general_valve.get(_trid_36);
                if(_OpCache_with_parameter_evn_close_general_valve != null) {
                    let writeState: _ProjectionWrite_evn_close_general_valve = _OpCache_with_parameter_evn_close_general_valve.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_evn_close_general_valve(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.evn_close_general_valve();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_evn_close_general_valve();
                        _OpCache_with_parameter_evn_close_general_valve = _OpCache_with_parameter_evn_close_general_valve.set(readState, writeState);
                        this._OpCache_evn_close_general_valve = this._OpCache_evn_close_general_valve.set(_trid_36, _OpCache_with_parameter_evn_close_general_valve);
                    }

                } else {
                    copiedState.evn_close_general_valve();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_evn_close_general_valve = copiedState._update_for_evn_close_general_valve();
                    _OpCache_with_parameter_evn_close_general_valve = new immutable.Map().set(readState, writeState);
                    this._OpCache_evn_close_general_valve = this._OpCache_evn_close_general_valve.set(_trid_36, _OpCache_with_parameter_evn_close_general_valve);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_env_close_analogical_switch_state : _ProjectionRead__tr_env_close_analogical_switch = state._projected_state_for__tr_env_close_analogical_switch();
            let _obj__trid_37: any = this._OpCache_tr_env_close_analogical_switch.get(read__tr_env_close_analogical_switch_state);
            let _trid_37: boolean;
            if(_obj__trid_37 == null) {
                _trid_37 = state._tr_env_close_analogical_switch();
                this._OpCache_tr_env_close_analogical_switch = this._OpCache_tr_env_close_analogical_switch.set(read__tr_env_close_analogical_switch_state, _trid_37);
            } else {
                _trid_37 = _obj__trid_37;
            }

            if(_trid_37) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_env_close_analogical_switch = state._projected_state_for_env_close_analogical_switch();
                let _OpCache_with_parameter_env_close_analogical_switch: immutable.Map = this._OpCache_env_close_analogical_switch.get(_trid_37);
                if(_OpCache_with_parameter_env_close_analogical_switch != null) {
                    let writeState: _ProjectionWrite_env_close_analogical_switch = _OpCache_with_parameter_env_close_analogical_switch.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_env_close_analogical_switch(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.env_close_analogical_switch();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_env_close_analogical_switch();
                        _OpCache_with_parameter_env_close_analogical_switch = _OpCache_with_parameter_env_close_analogical_switch.set(readState, writeState);
                        this._OpCache_env_close_analogical_switch = this._OpCache_env_close_analogical_switch.set(_trid_37, _OpCache_with_parameter_env_close_analogical_switch);
                    }

                } else {
                    copiedState.env_close_analogical_switch();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_env_close_analogical_switch = copiedState._update_for_env_close_analogical_switch();
                    _OpCache_with_parameter_env_close_analogical_switch = new immutable.Map().set(readState, writeState);
                    this._OpCache_env_close_analogical_switch = this._OpCache_env_close_analogical_switch.set(_trid_37, _OpCache_with_parameter_env_close_analogical_switch);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_env_open_analogical_switch_state : _ProjectionRead__tr_env_open_analogical_switch = state._projected_state_for__tr_env_open_analogical_switch();
            let _obj__trid_38: any = this._OpCache_tr_env_open_analogical_switch.get(read__tr_env_open_analogical_switch_state);
            let _trid_38: boolean;
            if(_obj__trid_38 == null) {
                _trid_38 = state._tr_env_open_analogical_switch();
                this._OpCache_tr_env_open_analogical_switch = this._OpCache_tr_env_open_analogical_switch.set(read__tr_env_open_analogical_switch_state, _trid_38);
            } else {
                _trid_38 = _obj__trid_38;
            }

            if(_trid_38) {
                let copiedState: LandingGear_R6 = state._copy();
                let readState: _ProjectionRead_env_open_analogical_switch = state._projected_state_for_env_open_analogical_switch();
                let _OpCache_with_parameter_env_open_analogical_switch: immutable.Map = this._OpCache_env_open_analogical_switch.get(_trid_38);
                if(_OpCache_with_parameter_env_open_analogical_switch != null) {
                    let writeState: _ProjectionWrite_env_open_analogical_switch = _OpCache_with_parameter_env_open_analogical_switch.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_env_open_analogical_switch(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.env_open_analogical_switch();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_env_open_analogical_switch();
                        _OpCache_with_parameter_env_open_analogical_switch = _OpCache_with_parameter_env_open_analogical_switch.set(readState, writeState);
                        this._OpCache_env_open_analogical_switch = this._OpCache_env_open_analogical_switch.set(_trid_38, _OpCache_with_parameter_env_open_analogical_switch);
                    }

                } else {
                    copiedState.env_open_analogical_switch();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_env_open_analogical_switch = copiedState._update_for_env_open_analogical_switch();
                    _OpCache_with_parameter_env_open_analogical_switch = new immutable.Map().set(readState, writeState);
                    this._OpCache_env_open_analogical_switch = this._OpCache_env_open_analogical_switch.set(_trid_38, _OpCache_with_parameter_env_open_analogical_switch);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        } else {
            if(state._tr_begin_flying()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.begin_flying();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_land_plane()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.land_plane();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_open_valve_door_open()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.open_valve_door_open();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_close_valve_door_open()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.close_valve_door_open();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_open_valve_door_close()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.open_valve_door_close();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_close_valve_door_close()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.close_valve_door_close();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_open_valve_retract_gear()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.open_valve_retract_gear();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_close_valve_retract_gear()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.close_valve_retract_gear();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_open_valve_extend_gear()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.open_valve_extend_gear();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_close_valve_extend_gear()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.close_valve_extend_gear();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_con_stimulate_open_door_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stimulate_open_door_valve();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_con_stop_stimulate_open_door_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stop_stimulate_open_door_valve();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_con_stimulate_close_door_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stimulate_close_door_valve();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_con_stop_stimulate_close_door_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stop_stimulate_close_door_valve();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_con_stimulate_retract_gear_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stimulate_retract_gear_valve();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_con_stop_stimulate_retract_gear_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stop_stimulate_retract_gear_valve();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_con_stimulate_extend_gear_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stimulate_extend_gear_valve();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_con_stop_stimulate_extend_gear_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stop_stimulate_extend_gear_valve();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_19: BSet<POSITION> = state._tr_env_start_retracting_first();
            for(let param of _trid_19) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_start_retracting_first(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_20: BSet<POSITION> = state._tr_env_retract_gear_skip();
            for(let param of _trid_20) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_retract_gear_skip(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_21: BSet<POSITION> = state._tr_env_retract_gear_last();
            for(let param of _trid_21) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_retract_gear_last(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_22: BSet<POSITION> = state._tr_env_start_extending();
            for(let param of _trid_22) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_start_extending(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_23: BSet<POSITION> = state._tr_env_extend_gear_last();
            for(let param of _trid_23) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_extend_gear_last(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_24: BSet<POSITION> = state._tr_env_extend_gear_skip();
            for(let param of _trid_24) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_extend_gear_skip(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_25: BSet<POSITION> = state._tr_env_start_open_door();
            for(let param of _trid_25) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_start_open_door(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_26: BSet<POSITION> = state._tr_env_open_door_last();
            for(let param of _trid_26) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_open_door_last(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_27: BSet<POSITION> = state._tr_env_open_door_skip();
            for(let param of _trid_27) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_open_door_skip(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_28: BSet<POSITION> = state._tr_env_start_close_door();
            for(let param of _trid_28) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_start_close_door(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_29: BSet<POSITION> = state._tr_env_close_door();
            for(let param of _trid_29) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_close_door(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_30: BSet<POSITION> = state._tr_env_close_door_skip();
            for(let param of _trid_30) {
                let _tmp_1: POSITION = param;

                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_close_door_skip(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_toggle_handle_up()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.toggle_handle_up();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_toggle_handle_down()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.toggle_handle_down();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_con_stimulate_general_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stimulate_general_valve();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_con_stop_stimulate_general_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.con_stop_stimulate_general_valve();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_evn_open_general_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.evn_open_general_valve();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_evn_close_general_valve()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.evn_close_general_valve();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_env_close_analogical_switch()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_close_analogical_switch();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_env_open_analogical_switch()) {
                let copiedState: LandingGear_R6 = state._copy();
                copiedState.env_open_analogical_switch();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        }
        return result;
    }

    invViolated(state: LandingGear_R6): boolean {
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

