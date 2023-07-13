import { BTuple } from 'https://favu100.github.io/b2program/visualizations/LandingGear/GearsDoors/btypes/BTuple.js';
import { BBoolean } from 'https://favu100.github.io/b2program/visualizations/LandingGear/GearsDoors/btypes/BBoolean.js';
import { BRelation } from 'https://favu100.github.io/b2program/visualizations/LandingGear/GearsDoors/btypes/BRelation.js';
import { BSet } from 'https://favu100.github.io/b2program/visualizations/LandingGear/GearsDoors/btypes/BSet.js';
import { BUtils } from "https://favu100.github.io/b2program/visualizations/LandingGear/GearsDoors/btypes/BUtils.js";
import { SelectError } from "https://favu100.github.io/b2program/visualizations/LandingGear/GearsDoors/btypes/BUtils.js";
import * as immutable from "https://favu100.github.io/b2program/visualizations/LandingGear/GearsDoors/immutable/dist/immutable.es.js";
export var enum_DOOR_STATE;
(function (enum_DOOR_STATE) {
    enum_DOOR_STATE[enum_DOOR_STATE["open"] = 0] = "open";
    enum_DOOR_STATE[enum_DOOR_STATE["closed"] = 1] = "closed";
    enum_DOOR_STATE[enum_DOOR_STATE["door_moving"] = 2] = "door_moving";
})(enum_DOOR_STATE || (enum_DOOR_STATE = {}));
export class DOOR_STATE {
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
        if (!(o instanceof DOOR_STATE)) {
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
    static get_open() { return new DOOR_STATE(enum_DOOR_STATE.open); }
    static get_closed() { return new DOOR_STATE(enum_DOOR_STATE.closed); }
    static get_door_moving() { return new DOOR_STATE(enum_DOOR_STATE.door_moving); }
}
export var enum_GEAR_STATE;
(function (enum_GEAR_STATE) {
    enum_GEAR_STATE[enum_GEAR_STATE["retracted"] = 0] = "retracted";
    enum_GEAR_STATE[enum_GEAR_STATE["extended"] = 1] = "extended";
    enum_GEAR_STATE[enum_GEAR_STATE["gear_moving"] = 2] = "gear_moving";
})(enum_GEAR_STATE || (enum_GEAR_STATE = {}));
export class GEAR_STATE {
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
        if (!(o instanceof GEAR_STATE)) {
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
    static get_retracted() { return new GEAR_STATE(enum_GEAR_STATE.retracted); }
    static get_extended() { return new GEAR_STATE(enum_GEAR_STATE.extended); }
    static get_gear_moving() { return new GEAR_STATE(enum_GEAR_STATE.gear_moving); }
}
export var enum_HANDLE_STATE;
(function (enum_HANDLE_STATE) {
    enum_HANDLE_STATE[enum_HANDLE_STATE["up"] = 0] = "up";
    enum_HANDLE_STATE[enum_HANDLE_STATE["down"] = 1] = "down";
})(enum_HANDLE_STATE || (enum_HANDLE_STATE = {}));
export class HANDLE_STATE {
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
        if (!(o instanceof HANDLE_STATE)) {
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
    static get_up() { return new HANDLE_STATE(enum_HANDLE_STATE.up); }
    static get_down() { return new HANDLE_STATE(enum_HANDLE_STATE.down); }
}
export var enum_POSITION;
(function (enum_POSITION) {
    enum_POSITION[enum_POSITION["fr"] = 0] = "fr";
    enum_POSITION[enum_POSITION["lt"] = 1] = "lt";
    enum_POSITION[enum_POSITION["rt"] = 2] = "rt";
})(enum_POSITION || (enum_POSITION = {}));
export class POSITION {
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
        if (!(o instanceof POSITION)) {
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
    static get_fr() { return new POSITION(enum_POSITION.fr); }
    static get_lt() { return new POSITION(enum_POSITION.lt); }
    static get_rt() { return new POSITION(enum_POSITION.rt); }
}
export var enum_SWITCH_STATE;
(function (enum_SWITCH_STATE) {
    enum_SWITCH_STATE[enum_SWITCH_STATE["switch_open"] = 0] = "switch_open";
    enum_SWITCH_STATE[enum_SWITCH_STATE["switch_closed"] = 1] = "switch_closed";
})(enum_SWITCH_STATE || (enum_SWITCH_STATE = {}));
export class SWITCH_STATE {
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
        if (!(o instanceof SWITCH_STATE)) {
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
    static get_switch_open() { return new SWITCH_STATE(enum_SWITCH_STATE.switch_open); }
    static get_switch_closed() { return new SWITCH_STATE(enum_SWITCH_STATE.switch_closed); }
}
export var enum_PLANE_STATE;
(function (enum_PLANE_STATE) {
    enum_PLANE_STATE[enum_PLANE_STATE["ground"] = 0] = "ground";
    enum_PLANE_STATE[enum_PLANE_STATE["flight"] = 1] = "flight";
})(enum_PLANE_STATE || (enum_PLANE_STATE = {}));
export class PLANE_STATE {
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
        if (!(o instanceof PLANE_STATE)) {
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
    static get_ground() { return new PLANE_STATE(enum_PLANE_STATE.ground); }
    static get_flight() { return new PLANE_STATE(enum_PLANE_STATE.flight); }
}
export var enum_VALVE_STATE;
(function (enum_VALVE_STATE) {
    enum_VALVE_STATE[enum_VALVE_STATE["valve_open"] = 0] = "valve_open";
    enum_VALVE_STATE[enum_VALVE_STATE["valve_closed"] = 1] = "valve_closed";
})(enum_VALVE_STATE || (enum_VALVE_STATE = {}));
export class VALVE_STATE {
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
        if (!(o instanceof VALVE_STATE)) {
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
    static get_valve_open() { return new VALVE_STATE(enum_VALVE_STATE.valve_open); }
    static get_valve_closed() { return new VALVE_STATE(enum_VALVE_STATE.valve_closed); }
}
export var Type;
(function (Type) {
    Type[Type["BFS"] = 0] = "BFS";
    Type[Type["DFS"] = 1] = "DFS";
    Type[Type["MIXED"] = 2] = "MIXED";
})(Type || (Type = {}));
export default class LandingGear_R6 {
    constructor(copy) {
        this.dependentGuard = immutable.Set();
        this.guardCache = immutable.Map();
        this.dependentInvariant = immutable.Set();
        if (copy) {
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
        }
        else {
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
    }
    begin_flying() {
        if ((this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground))).booleanValue()) {
            this.shock_absorber = new PLANE_STATE(enum_PLANE_STATE.flight);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    land_plane() {
        if ((this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.flight))).booleanValue()) {
            this.shock_absorber = new PLANE_STATE(enum_PLANE_STATE.ground);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    open_valve_door_open() {
        if ((new BBoolean(this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_closed)).booleanValue() && this.open_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.valve_open_door = new VALVE_STATE(enum_VALVE_STATE.valve_open);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    close_valve_door_open() {
        if ((new BBoolean(this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
            this.valve_open_door = new VALVE_STATE(enum_VALVE_STATE.valve_closed);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    open_valve_door_close() {
        if ((new BBoolean(this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_closed)).booleanValue() && this.close_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.valve_close_door = new VALVE_STATE(enum_VALVE_STATE.valve_open);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    close_valve_door_close() {
        if ((new BBoolean(this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() && this.close_EV.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
            this.valve_close_door = new VALVE_STATE(enum_VALVE_STATE.valve_closed);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    open_valve_retract_gear() {
        if ((new BBoolean(this.valve_retract_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_closed)).booleanValue() && this.retract_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.valve_retract_gear = new VALVE_STATE(enum_VALVE_STATE.valve_open);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    close_valve_retract_gear() {
        if ((new BBoolean(this.valve_retract_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
            this.valve_retract_gear = new VALVE_STATE(enum_VALVE_STATE.valve_closed);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    open_valve_extend_gear() {
        if ((new BBoolean(this.valve_extend_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_closed)).booleanValue() && this.extend_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.valve_extend_gear = new VALVE_STATE(enum_VALVE_STATE.valve_open);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    close_valve_extend_gear() {
        if ((new BBoolean(this.valve_extend_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
            this.valve_extend_gear = new VALVE_STATE(enum_VALVE_STATE.valve_closed);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    con_stimulate_open_door_valve() {
        if ((new BBoolean(new BBoolean(new BBoolean(this.open_EV.equal(new BBoolean(false)).booleanValue() && this.close_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).not().booleanValue()).booleanValue() || new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).not().booleanValue()).booleanValue() && new BBoolean(this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).not().booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.open_EV = new BBoolean(true);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    con_stop_stimulate_open_door_valve() {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.open_EV.equal(new BBoolean(true)).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.open_EV = new BBoolean(false);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    con_stimulate_close_door_valve() {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.close_EV.equal(new BBoolean(false)).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).not().booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.close_EV = new BBoolean(true);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    con_stop_stimulate_close_door_valve() {
        if ((new BBoolean(new BBoolean(this.close_EV.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() || new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.close_EV = new BBoolean(false);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    con_stimulate_retract_gear_valve() {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.retract_EV.equal(new BBoolean(false)).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(true)).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue()).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).not().booleanValue()).booleanValue() && this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.flight)).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.retract_EV = new BBoolean(true);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    con_stop_stimulate_retract_gear_valve() {
        if ((new BBoolean(new BBoolean(this.retract_EV.equal(new BBoolean(true)).booleanValue() && new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.retract_EV = new BBoolean(false);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    con_stimulate_extend_gear_valve() {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.extend_EV.equal(new BBoolean(false)).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(true)).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue()).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).not().booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.extend_EV = new BBoolean(true);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    con_stop_stimulate_extend_gear_valve() {
        if ((new BBoolean(new BBoolean(this.extend_EV.equal(new BBoolean(true)).booleanValue() && new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.extend_EV = new BBoolean(false);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    env_start_retracting_first(gr) {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue()).booleanValue() && this.gears.functionCall(gr).equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue() && this.valve_retract_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BSet(new GEAR_STATE(enum_GEAR_STATE.extended), new GEAR_STATE(enum_GEAR_STATE.gear_moving)).elementOf(this.gear).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue()) {
            let _ld_gears = this.gears;
            this.gears = _ld_gears.override(new BRelation(new BTuple(gr, new GEAR_STATE(enum_GEAR_STATE.gear_moving))));
            this.gear = new GEAR_STATE(enum_GEAR_STATE.gear_moving);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    env_retract_gear_skip(gr) {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.gears.relationImage(LandingGear_R6._POSITION.difference(new BSet(gr))).unequal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue()).booleanValue() && this.gears.functionCall(gr).equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
            this.gears = this.gears.override(new BRelation(new BTuple(gr, new GEAR_STATE(enum_GEAR_STATE.retracted))));
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    env_retract_gear_last(gr) {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.gears.relationImage(LandingGear_R6._POSITION.difference(new BSet(gr))).equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue()).booleanValue() && this.gears.functionCall(gr).equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue()) {
            let _ld_gears = this.gears;
            this.gears = _ld_gears.override(new BRelation(new BTuple(gr, new GEAR_STATE(enum_GEAR_STATE.retracted))));
            this.gear = new GEAR_STATE(enum_GEAR_STATE.retracted);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    env_start_extending(gr) {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue()).booleanValue() && this.gears.functionCall(gr).equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue()).booleanValue() && this.valve_extend_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BSet(new GEAR_STATE(enum_GEAR_STATE.gear_moving), new GEAR_STATE(enum_GEAR_STATE.retracted)).elementOf(this.gear).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue()) {
            let _ld_gears = this.gears;
            this.gears = _ld_gears.override(new BRelation(new BTuple(gr, new GEAR_STATE(enum_GEAR_STATE.gear_moving))));
            this.gear = new GEAR_STATE(enum_GEAR_STATE.gear_moving);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    env_extend_gear_last(gr) {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue()).booleanValue() && this.gears.relationImage(LandingGear_R6._POSITION.difference(new BSet(gr))).equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.gears.functionCall(gr).equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue()) {
            let _ld_gears = this.gears;
            this.gears = _ld_gears.override(new BRelation(new BTuple(gr, new GEAR_STATE(enum_GEAR_STATE.extended))));
            this.gear = new GEAR_STATE(enum_GEAR_STATE.extended);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    env_extend_gear_skip(gr) {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue()).booleanValue() && this.gears.relationImage(LandingGear_R6._POSITION.difference(new BSet(gr))).unequal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.gears.functionCall(gr).equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
            this.gears = this.gears.override(new BRelation(new BTuple(gr, new GEAR_STATE(enum_GEAR_STATE.extended))));
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    env_start_open_door(gr) {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.functionCall(gr).equal(new DOOR_STATE(enum_DOOR_STATE.closed)).booleanValue()).booleanValue() && this.gears.functionCall(gr).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BSet(new DOOR_STATE(enum_DOOR_STATE.closed), new DOOR_STATE(enum_DOOR_STATE.door_moving)).elementOf(this.door).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
            let _ld_doors = this.doors;
            this.doors = _ld_doors.override(new BRelation(new BTuple(gr, new DOOR_STATE(enum_DOOR_STATE.door_moving))));
            this.door = new DOOR_STATE(enum_DOOR_STATE.door_moving);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    env_open_door_last(gr) {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.functionCall(gr).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue()).booleanValue() && this.gears.functionCall(gr).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet(gr))).equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
            let _ld_doors = this.doors;
            this.doors = _ld_doors.override(new BRelation(new BTuple(gr, new DOOR_STATE(enum_DOOR_STATE.open))));
            this.door = new DOOR_STATE(enum_DOOR_STATE.open);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    env_open_door_skip(gr) {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.functionCall(gr).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue()).booleanValue() && this.gears.functionCall(gr).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet(gr))).unequal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
            this.doors = this.doors.override(new BRelation(new BTuple(gr, new DOOR_STATE(enum_DOOR_STATE.open))));
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    env_start_close_door(gr) {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.functionCall(gr).equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue()).booleanValue() && this.gears.functionCall(gr).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BSet(new DOOR_STATE(enum_DOOR_STATE.door_moving), new DOOR_STATE(enum_DOOR_STATE.open)).elementOf(this.door).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BSet(new GEAR_STATE(enum_GEAR_STATE.extended), new GEAR_STATE(enum_GEAR_STATE.retracted)).elementOf(this.gear).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
            let _ld_doors = this.doors;
            this.doors = _ld_doors.override(new BRelation(new BTuple(gr, new DOOR_STATE(enum_DOOR_STATE.door_moving))));
            this.door = new DOOR_STATE(enum_DOOR_STATE.door_moving);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    env_close_door(gr) {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.functionCall(gr).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue()).booleanValue() && this.gears.functionCall(gr).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet(gr))).equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BSet(new GEAR_STATE(enum_GEAR_STATE.extended), new GEAR_STATE(enum_GEAR_STATE.retracted)).elementOf(this.gear).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
            let _ld_doors = this.doors;
            this.doors = _ld_doors.override(new BRelation(new BTuple(gr, new DOOR_STATE(enum_DOOR_STATE.closed))));
            this.door = new DOOR_STATE(enum_DOOR_STATE.closed);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    env_close_door_skip(gr) {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.gears.domain().elementOf(gr).booleanValue() && this.doors.functionCall(gr).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue()).booleanValue() && this.gears.functionCall(gr).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet(gr))).unequal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
            this.doors = this.doors.override(new BRelation(new BTuple(gr, new DOOR_STATE(enum_DOOR_STATE.closed))));
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    toggle_handle_up() {
        if ((this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down))).booleanValue()) {
            this.handle = new HANDLE_STATE(enum_HANDLE_STATE.up);
            this.handle_move = new BBoolean(true);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    toggle_handle_down() {
        if ((this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up))).booleanValue()) {
            this.handle = new HANDLE_STATE(enum_HANDLE_STATE.down);
            this.handle_move = new BBoolean(true);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    con_stimulate_general_valve() {
        if ((new BBoolean(this.general_EV.equal(new BBoolean(false)).booleanValue() && this.handle_move.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.general_EV = new BBoolean(true);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    con_stop_stimulate_general_valve() {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.general_EV.equal(new BBoolean(true)).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.close_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.close_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() || new BBoolean(new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() || new BBoolean(new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
            this.general_EV = new BBoolean(false);
            this.handle_move = new BBoolean(false);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    evn_open_general_valve() {
        if ((new BBoolean(new BBoolean(this.general_EV.equal(new BBoolean(true)).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_closed)).booleanValue()).booleanValue() && this.analogical_switch.equal(new SWITCH_STATE(enum_SWITCH_STATE.switch_closed)).booleanValue())).booleanValue()) {
            this.general_valve = new VALVE_STATE(enum_VALVE_STATE.valve_open);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    evn_close_general_valve() {
        if ((new BBoolean(new BBoolean(this.general_EV.equal(new BBoolean(false)).booleanValue() || this.analogical_switch.equal(new SWITCH_STATE(enum_SWITCH_STATE.switch_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
            this.general_valve = new VALVE_STATE(enum_VALVE_STATE.valve_closed);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    env_close_analogical_switch() {
        if ((new BBoolean(this.analogical_switch.equal(new SWITCH_STATE(enum_SWITCH_STATE.switch_open)).booleanValue() && this.handle_move.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            this.analogical_switch = new SWITCH_STATE(enum_SWITCH_STATE.switch_closed);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    env_open_analogical_switch() {
        if ((this.analogical_switch.equal(new SWITCH_STATE(enum_SWITCH_STATE.switch_closed))).booleanValue()) {
            this.analogical_switch = new SWITCH_STATE(enum_SWITCH_STATE.switch_open);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    _get_analogical_switch() {
        return this.analogical_switch;
    }
    _get_general_EV() {
        return this.general_EV;
    }
    _get_general_valve() {
        return this.general_valve;
    }
    _get_handle_move() {
        return this.handle_move;
    }
    _get_close_EV() {
        return this.close_EV;
    }
    _get_extend_EV() {
        return this.extend_EV;
    }
    _get_open_EV() {
        return this.open_EV;
    }
    _get_retract_EV() {
        return this.retract_EV;
    }
    _get_shock_absorber() {
        return this.shock_absorber;
    }
    _get_valve_close_door() {
        return this.valve_close_door;
    }
    _get_valve_extend_gear() {
        return this.valve_extend_gear;
    }
    _get_valve_open_door() {
        return this.valve_open_door;
    }
    _get_valve_retract_gear() {
        return this.valve_retract_gear;
    }
    _get_doors() {
        return this.doors;
    }
    _get_gears() {
        return this.gears;
    }
    _get_handle() {
        return this.handle;
    }
    _get_door() {
        return this.door;
    }
    _get_gear() {
        return this.gear;
    }
    _get__DOOR_STATE() {
        return LandingGear_R6._DOOR_STATE;
    }
    _get__GEAR_STATE() {
        return LandingGear_R6._GEAR_STATE;
    }
    _get__HANDLE_STATE() {
        return LandingGear_R6._HANDLE_STATE;
    }
    _get__POSITION() {
        return LandingGear_R6._POSITION;
    }
    _get__SWITCH_STATE() {
        return LandingGear_R6._SWITCH_STATE;
    }
    _get__PLANE_STATE() {
        return LandingGear_R6._PLANE_STATE;
    }
    _get__VALVE_STATE() {
        return LandingGear_R6._VALVE_STATE;
    }
    _tr_begin_flying() {
        return this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue();
    }
    _tr_land_plane() {
        return this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.flight)).booleanValue();
    }
    _tr_open_valve_door_open() {
        return new BBoolean(this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_closed)).booleanValue() && this.open_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }
    _tr_close_valve_door_open() {
        return new BBoolean(this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }
    _tr_open_valve_door_close() {
        return new BBoolean(this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_closed)).booleanValue() && this.close_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }
    _tr_close_valve_door_close() {
        return new BBoolean(this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() && this.close_EV.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }
    _tr_open_valve_retract_gear() {
        return new BBoolean(this.valve_retract_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_closed)).booleanValue() && this.retract_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }
    _tr_close_valve_retract_gear() {
        return new BBoolean(this.valve_retract_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }
    _tr_open_valve_extend_gear() {
        return new BBoolean(this.valve_extend_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_closed)).booleanValue() && this.extend_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }
    _tr_close_valve_extend_gear() {
        return new BBoolean(this.valve_extend_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }
    _tr_con_stimulate_open_door_valve() {
        return new BBoolean(new BBoolean(new BBoolean(this.open_EV.equal(new BBoolean(false)).booleanValue() && this.close_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).not().booleanValue()).booleanValue() || new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).not().booleanValue()).booleanValue() && new BBoolean(this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).not().booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }
    _tr_con_stop_stimulate_open_door_valve() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.open_EV.equal(new BBoolean(true)).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }
    _tr_con_stimulate_close_door_valve() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.close_EV.equal(new BBoolean(false)).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).not().booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }
    _tr_con_stop_stimulate_close_door_valve() {
        return new BBoolean(new BBoolean(this.close_EV.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() || new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }
    _tr_con_stimulate_retract_gear_valve() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.retract_EV.equal(new BBoolean(false)).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(true)).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue()).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).not().booleanValue()).booleanValue() && this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.flight)).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }
    _tr_con_stop_stimulate_retract_gear_valve() {
        return new BBoolean(new BBoolean(this.retract_EV.equal(new BBoolean(true)).booleanValue() && new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }
    _tr_con_stimulate_extend_gear_valve() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.extend_EV.equal(new BBoolean(false)).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(true)).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue()).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).not().booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }
    _tr_con_stop_stimulate_extend_gear_valve() {
        return new BBoolean(new BBoolean(this.extend_EV.equal(new BBoolean(true)).booleanValue() && new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() && this.general_EV.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }
    _tr_env_start_retracting_first() {
        let _ic_set_18 = new BSet();
        for (let _ic_gr_1 of this.gears.domain()) {
            if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue()).booleanValue() && this.gears.functionCall(_ic_gr_1).equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue() && this.valve_retract_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BSet(new GEAR_STATE(enum_GEAR_STATE.extended), new GEAR_STATE(enum_GEAR_STATE.gear_moving)).elementOf(this.gear).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue()) {
                _ic_set_18 = _ic_set_18.union(new BSet(_ic_gr_1));
            }
        }
        return _ic_set_18;
    }
    _tr_env_retract_gear_skip() {
        let _ic_set_19 = new BSet();
        for (let _ic_gr_1 of this.gears.domain()) {
            if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.gears.relationImage(LandingGear_R6._POSITION.difference(new BSet(_ic_gr_1))).unequal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue()).booleanValue() && this.gears.functionCall(_ic_gr_1).equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
                _ic_set_19 = _ic_set_19.union(new BSet(_ic_gr_1));
            }
        }
        return _ic_set_19;
    }
    _tr_env_retract_gear_last() {
        let _ic_set_20 = new BSet();
        for (let _ic_gr_1 of this.gears.domain()) {
            if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.gears.relationImage(LandingGear_R6._POSITION.difference(new BSet(_ic_gr_1))).equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue()).booleanValue() && this.gears.functionCall(_ic_gr_1).equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue()) {
                _ic_set_20 = _ic_set_20.union(new BSet(_ic_gr_1));
            }
        }
        return _ic_set_20;
    }
    _tr_env_start_extending() {
        let _ic_set_21 = new BSet();
        for (let _ic_gr_1 of this.gears.domain()) {
            if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue()).booleanValue() && this.gears.functionCall(_ic_gr_1).equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue()).booleanValue() && this.valve_extend_gear.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BSet(new GEAR_STATE(enum_GEAR_STATE.gear_moving), new GEAR_STATE(enum_GEAR_STATE.retracted)).elementOf(this.gear).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue()) {
                _ic_set_21 = _ic_set_21.union(new BSet(_ic_gr_1));
            }
        }
        return _ic_set_21;
    }
    _tr_env_extend_gear_last() {
        let _ic_set_22 = new BSet();
        for (let _ic_gr_1 of this.gears.domain()) {
            if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue()).booleanValue() && this.gears.relationImage(LandingGear_R6._POSITION.difference(new BSet(_ic_gr_1))).equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.gears.functionCall(_ic_gr_1).equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue()) {
                _ic_set_22 = _ic_set_22.union(new BSet(_ic_gr_1));
            }
        }
        return _ic_set_22;
    }
    _tr_env_extend_gear_skip() {
        let _ic_set_23 = new BSet();
        for (let _ic_gr_1 of this.gears.domain()) {
            if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() && this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue()).booleanValue() && this.gears.relationImage(LandingGear_R6._POSITION.difference(new BSet(_ic_gr_1))).unequal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.gears.functionCall(_ic_gr_1).equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
                _ic_set_23 = _ic_set_23.union(new BSet(_ic_gr_1));
            }
        }
        return _ic_set_23;
    }
    _tr_env_start_open_door() {
        let _ic_set_24 = new BSet();
        for (let _ic_gr_1 of this.gears.domain()) {
            if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.closed)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BSet(new DOOR_STATE(enum_DOOR_STATE.closed), new DOOR_STATE(enum_DOOR_STATE.door_moving)).elementOf(this.door).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
                _ic_set_24 = _ic_set_24.union(new BSet(_ic_gr_1));
            }
        }
        return _ic_set_24;
    }
    _tr_env_open_door_last() {
        let _ic_set_25 = new BSet();
        for (let _ic_gr_1 of this.gears.domain()) {
            if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet(_ic_gr_1))).equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
                _ic_set_25 = _ic_set_25.union(new BSet(_ic_gr_1));
            }
        }
        return _ic_set_25;
    }
    _tr_env_open_door_skip() {
        let _ic_set_26 = new BSet();
        for (let _ic_gr_1 of this.gears.domain()) {
            if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet(_ic_gr_1))).unequal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_open_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
                _ic_set_26 = _ic_set_26.union(new BSet(_ic_gr_1));
            }
        }
        return _ic_set_26;
    }
    _tr_env_start_close_door() {
        let _ic_set_27 = new BSet();
        for (let _ic_gr_1 of this.gears.domain()) {
            if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BSet(new DOOR_STATE(enum_DOOR_STATE.door_moving), new DOOR_STATE(enum_DOOR_STATE.open)).elementOf(this.door).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BSet(new GEAR_STATE(enum_GEAR_STATE.extended), new GEAR_STATE(enum_GEAR_STATE.retracted)).elementOf(this.gear).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
                _ic_set_27 = _ic_set_27.union(new BSet(_ic_gr_1));
            }
        }
        return _ic_set_27;
    }
    _tr_env_close_door() {
        let _ic_set_28 = new BSet();
        for (let _ic_gr_1 of this.gears.domain()) {
            if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet(_ic_gr_1))).equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && this.door.equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue()).booleanValue() && this.gear.unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BSet(new GEAR_STATE(enum_GEAR_STATE.extended), new GEAR_STATE(enum_GEAR_STATE.retracted)).elementOf(this.gear).booleanValue()).booleanValue()).booleanValue())).booleanValue()) {
                _ic_set_28 = _ic_set_28.union(new BSet(_ic_gr_1));
            }
        }
        return _ic_set_28;
    }
    _tr_env_close_door_skip() {
        let _ic_set_29 = new BSet();
        for (let _ic_gr_1 of this.gears.domain()) {
            if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.doors.functionCall(_ic_gr_1).equal(new DOOR_STATE(enum_DOOR_STATE.door_moving)).booleanValue() && this.gears.functionCall(_ic_gr_1).unequal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.gears.range().notElementOf(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue()).booleanValue() && this.doors.relationImage(LandingGear_R6._POSITION.difference(new BSet(_ic_gr_1))).unequal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && new BBoolean(this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue() || new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue()).booleanValue()).booleanValue() && this.valve_close_door.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() || this.shock_absorber.equal(new PLANE_STATE(enum_PLANE_STATE.ground)).booleanValue()).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue())).booleanValue()) {
                _ic_set_29 = _ic_set_29.union(new BSet(_ic_gr_1));
            }
        }
        return _ic_set_29;
    }
    _tr_toggle_handle_up() {
        return this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue();
    }
    _tr_toggle_handle_down() {
        return this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue();
    }
    _tr_con_stimulate_general_valve() {
        return new BBoolean(this.general_EV.equal(new BBoolean(false)).booleanValue() && this.handle_move.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }
    _tr_con_stop_stimulate_general_valve() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.general_EV.equal(new BBoolean(true)).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.close_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.retract_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.extend_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.close_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue() || new BBoolean(new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.down)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() || new BBoolean(new BBoolean(new BBoolean(this.handle.equal(new HANDLE_STATE(enum_HANDLE_STATE.up)).booleanValue() && this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()).booleanValue() && this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()).booleanValue() && this.open_EV.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue()).booleanValue();
    }
    _tr_evn_open_general_valve() {
        return new BBoolean(new BBoolean(this.general_EV.equal(new BBoolean(true)).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_closed)).booleanValue()).booleanValue() && this.analogical_switch.equal(new SWITCH_STATE(enum_SWITCH_STATE.switch_closed)).booleanValue()).booleanValue();
    }
    _tr_evn_close_general_valve() {
        return new BBoolean(new BBoolean(this.general_EV.equal(new BBoolean(false)).booleanValue() || this.analogical_switch.equal(new SWITCH_STATE(enum_SWITCH_STATE.switch_open)).booleanValue()).booleanValue() && this.general_valve.equal(new VALVE_STATE(enum_VALVE_STATE.valve_open)).booleanValue()).booleanValue();
    }
    _tr_env_close_analogical_switch() {
        return new BBoolean(this.analogical_switch.equal(new SWITCH_STATE(enum_SWITCH_STATE.switch_open)).booleanValue() && this.handle_move.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }
    _tr_env_open_analogical_switch() {
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
        return new BBoolean((!this.door.equal(new DOOR_STATE(enum_DOOR_STATE.closed)).booleanValue() || this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue()) && (!this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.closed))).booleanValue() || this.door.equal(new DOOR_STATE(enum_DOOR_STATE.closed)).booleanValue())).booleanValue();
    }
    _check_inv_22() {
        return new BBoolean((!this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue() || this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue()) && (!this.doors.range().equal(new BSet(new DOOR_STATE(enum_DOOR_STATE.open))).booleanValue() || this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue())).booleanValue();
    }
    _check_inv_23() {
        return new BBoolean((!this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue()) && (!this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.extended))).booleanValue() || this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.extended)).booleanValue())).booleanValue();
    }
    _check_inv_24() {
        return new BBoolean((!this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue() || this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue()) && (!this.gears.range().equal(new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted))).booleanValue() || this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.retracted)).booleanValue())).booleanValue();
    }
    _check_inv_25() {
        return new BBoolean(!this.gear.equal(new GEAR_STATE(enum_GEAR_STATE.gear_moving)).booleanValue() || this.door.equal(new DOOR_STATE(enum_DOOR_STATE.open)).booleanValue()).booleanValue();
    }
    equals(o) {
        let o1 = this;
        let o2 = o;
        return o1._get_analogical_switch().equals(o2._get_analogical_switch()) && o1._get_general_EV().equals(o2._get_general_EV()) && o1._get_general_valve().equals(o2._get_general_valve()) && o1._get_handle_move().equals(o2._get_handle_move()) && o1._get_close_EV().equals(o2._get_close_EV()) && o1._get_extend_EV().equals(o2._get_extend_EV()) && o1._get_open_EV().equals(o2._get_open_EV()) && o1._get_retract_EV().equals(o2._get_retract_EV()) && o1._get_shock_absorber().equals(o2._get_shock_absorber()) && o1._get_valve_close_door().equals(o2._get_valve_close_door()) && o1._get_valve_extend_gear().equals(o2._get_valve_extend_gear()) && o1._get_valve_open_door().equals(o2._get_valve_open_door()) && o1._get_valve_retract_gear().equals(o2._get_valve_retract_gear()) && o1._get_doors().equals(o2._get_doors()) && o1._get_gears().equals(o2._get_gears()) && o1._get_handle().equals(o2._get_handle()) && o1._get_door().equals(o2._get_door()) && o1._get_gear().equals(o2._get_gear());
    }
    hashCode() {
        return this._hashCode_1();
    }
    _hashCode_1() {
        let result = 1;
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
    _hashCode_2() {
        let result = 1;
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
    _copy() {
        return new LandingGear_R6(this);
    }
}
LandingGear_R6._DOOR_STATE = new BSet(new DOOR_STATE(enum_DOOR_STATE.open), new DOOR_STATE(enum_DOOR_STATE.closed), new DOOR_STATE(enum_DOOR_STATE.door_moving));
LandingGear_R6._GEAR_STATE = new BSet(new GEAR_STATE(enum_GEAR_STATE.retracted), new GEAR_STATE(enum_GEAR_STATE.extended), new GEAR_STATE(enum_GEAR_STATE.gear_moving));
LandingGear_R6._HANDLE_STATE = new BSet(new HANDLE_STATE(enum_HANDLE_STATE.up), new HANDLE_STATE(enum_HANDLE_STATE.down));
LandingGear_R6._POSITION = new BSet(new POSITION(enum_POSITION.fr), new POSITION(enum_POSITION.lt), new POSITION(enum_POSITION.rt));
LandingGear_R6._SWITCH_STATE = new BSet(new SWITCH_STATE(enum_SWITCH_STATE.switch_open), new SWITCH_STATE(enum_SWITCH_STATE.switch_closed));
LandingGear_R6._PLANE_STATE = new BSet(new PLANE_STATE(enum_PLANE_STATE.ground), new PLANE_STATE(enum_PLANE_STATE.flight));
LandingGear_R6._VALVE_STATE = new BSet(new VALVE_STATE(enum_VALVE_STATE.valve_open), new VALVE_STATE(enum_VALVE_STATE.valve_closed));
