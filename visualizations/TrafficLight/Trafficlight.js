import { BBoolean } from './btypes/BBoolean.js';
import { BSet } from './btypes/BSet.js';
import { SelectError } from "./btypes/BUtils.js";
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
        return 0;
    }
    toString() {
        return enum_colors[this.value].toString();
    }
    static get_red() { return new colors(enum_colors.red); }
    static get_redyellow() { return new colors(enum_colors.redyellow); }
    static get_yellow() { return new colors(enum_colors.yellow); }
    static get_green() { return new colors(enum_colors.green); }
}
export default class TrafficLight {
    constructor() {
        this.tl_cars = new colors(enum_colors.red);
        this.tl_peds = new colors(enum_colors.red);
    }
    _copy() {
        var _a, _b, _c;
        let _instance = Object.create(TrafficLight.prototype);
        for (let key of Object.keys(this)) {
            _instance[key] = (_c = (_b = (_a = this[key])._copy) === null || _b === void 0 ? void 0 : _b.call(_a)) !== null && _c !== void 0 ? _c : this[key];
        }
        return _instance;
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
}
TrafficLight._colors = new BSet(new colors(enum_colors.red), new colors(enum_colors.redyellow), new colors(enum_colors.yellow), new colors(enum_colors.green));
