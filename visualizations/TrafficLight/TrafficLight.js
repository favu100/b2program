import { BBoolean } from 'https://favu100.github.io/b2program/visualizations/TrafficLight/btypes/BBoolean.js';
import { BSet } from 'https://favu100.github.io/b2program/visualizations/TrafficLight/btypes/BSet.js';
import { SelectError } from "https://favu100.github.io/b2program/visualizations/TrafficLight/btypes/BUtils.js";
import * as immutable from "https://favu100.github.io/b2program/visualizations/TrafficLight/immutable/dist/immutable.es.js";
export var enum_colors;
(function (enum_colors) {
    enum_colors[enum_colors["red"] = 0] = "red";
    enum_colors[enum_colors["redyellow"] = 1] = "redyellow";
    enum_colors[enum_colors["yellow"] = 2] = "yellow";
    enum_colors[enum_colors["green"] = 3] = "green";
})(enum_colors || (enum_colors = {}));
export class colors {
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
        if (!(o instanceof colors)) {
            return false;
        }
        return this.value === o.value;
    }
    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }
    toString() {
        return enum_colors[this.value].toString();
    }
    static get_red() { return new colors(enum_colors.red); }
    static get_redyellow() { return new colors(enum_colors.redyellow); }
    static get_yellow() { return new colors(enum_colors.yellow); }
    static get_green() { return new colors(enum_colors.green); }
}
export var Type;
(function (Type) {
    Type[Type["BFS"] = 0] = "BFS";
    Type[Type["DFS"] = 1] = "DFS";
    Type[Type["MIXED"] = 2] = "MIXED";
})(Type || (Type = {}));
export default class TrafficLight {
    constructor(copy) {
        this.dependentGuard = immutable.Set();
        this.guardCache = immutable.Map();
        this.dependentInvariant = immutable.Set();
        if (copy) {
            this.tl_cars = copy.tl_cars;
            this.tl_peds = copy.tl_peds;
        }
        else {
            this.tl_cars = new colors(enum_colors.red);
            this.tl_peds = new colors(enum_colors.red);
        }
    }
    cars_ry() {
        if ((new BBoolean(this.tl_cars.equal(new colors(enum_colors.red)).booleanValue() && this.tl_peds.equal(new colors(enum_colors.red)).booleanValue())).booleanValue()) {
            this.tl_cars = new colors(enum_colors.redyellow);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    cars_y() {
        if ((new BBoolean(this.tl_cars.equal(new colors(enum_colors.green)).booleanValue() && this.tl_peds.equal(new colors(enum_colors.red)).booleanValue())).booleanValue()) {
            this.tl_cars = new colors(enum_colors.yellow);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    cars_g() {
        if ((new BBoolean(this.tl_cars.equal(new colors(enum_colors.redyellow)).booleanValue() && this.tl_peds.equal(new colors(enum_colors.red)).booleanValue())).booleanValue()) {
            this.tl_cars = new colors(enum_colors.green);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    cars_r() {
        if ((new BBoolean(this.tl_cars.equal(new colors(enum_colors.yellow)).booleanValue() && this.tl_peds.equal(new colors(enum_colors.red)).booleanValue())).booleanValue()) {
            this.tl_cars = new colors(enum_colors.red);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    peds_r() {
        if ((new BBoolean(this.tl_peds.equal(new colors(enum_colors.green)).booleanValue() && this.tl_cars.equal(new colors(enum_colors.red)).booleanValue())).booleanValue()) {
            this.tl_peds = new colors(enum_colors.red);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    peds_g() {
        if ((new BBoolean(this.tl_peds.equal(new colors(enum_colors.red)).booleanValue() && this.tl_cars.equal(new colors(enum_colors.red)).booleanValue())).booleanValue()) {
            this.tl_peds = new colors(enum_colors.green);
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    _get_tl_cars() {
        return this.tl_cars;
    }
    _get_tl_peds() {
        return this.tl_peds;
    }
    _get__colors() {
        return TrafficLight._colors;
    }
    _tr_cars_ry() {
        return new BBoolean(this.tl_cars.equal(new colors(enum_colors.red)).booleanValue() && this.tl_peds.equal(new colors(enum_colors.red)).booleanValue()).booleanValue();
    }
    _tr_cars_y() {
        return new BBoolean(this.tl_cars.equal(new colors(enum_colors.green)).booleanValue() && this.tl_peds.equal(new colors(enum_colors.red)).booleanValue()).booleanValue();
    }
    _tr_cars_g() {
        return new BBoolean(this.tl_cars.equal(new colors(enum_colors.redyellow)).booleanValue() && this.tl_peds.equal(new colors(enum_colors.red)).booleanValue()).booleanValue();
    }
    _tr_cars_r() {
        return new BBoolean(this.tl_cars.equal(new colors(enum_colors.yellow)).booleanValue() && this.tl_peds.equal(new colors(enum_colors.red)).booleanValue()).booleanValue();
    }
    _tr_peds_r() {
        return new BBoolean(this.tl_peds.equal(new colors(enum_colors.green)).booleanValue() && this.tl_cars.equal(new colors(enum_colors.red)).booleanValue()).booleanValue();
    }
    _tr_peds_g() {
        return new BBoolean(this.tl_peds.equal(new colors(enum_colors.red)).booleanValue() && this.tl_cars.equal(new colors(enum_colors.red)).booleanValue()).booleanValue();
    }
    _check_inv_1() {
        return TrafficLight._colors.elementOf(this.tl_cars).booleanValue();
    }
    _check_inv_2() {
        return new BSet(new colors(enum_colors.red), new colors(enum_colors.green)).elementOf(this.tl_peds).booleanValue();
    }
    _check_inv_3() {
        return new BBoolean(this.tl_peds.equal(new colors(enum_colors.red)).booleanValue() || this.tl_cars.equal(new colors(enum_colors.red)).booleanValue()).booleanValue();
    }
    equals(o) {
        let o1 = this;
        let o2 = o;
        return o1._get_tl_cars().equals(o2._get_tl_cars()) && o1._get_tl_peds().equals(o2._get_tl_peds());
    }
    hashCode() {
        return this._hashCode_1();
    }
    _hashCode_1() {
        let result = 1;
        result = (1543 * result) ^ ((this._get_tl_cars()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_tl_peds()).hashCode() << 1);
        return result;
    }
    _hashCode_2() {
        let result = 1;
        result = (6151 * result) ^ ((this._get_tl_cars()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_tl_peds()).hashCode() << 1);
        return result;
    }
    /* TODO
    toString(): string {
        return String.join("\n", "_get_tl_cars: " + (this._get_tl_cars()).toString(), "_get_tl_peds: " + (this._get_tl_peds()).toString());
    }
    */
    _copy() {
        return new TrafficLight(this);
    }
}
TrafficLight._colors = new BSet(new colors(enum_colors.red), new colors(enum_colors.redyellow), new colors(enum_colors.yellow), new colors(enum_colors.green));
