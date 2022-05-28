import { BBoolean } from './btypes/BBoolean.js';
import { BSet } from './btypes/BSet.js';
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
    cars_ry() {
        if ((new BBoolean(this.tl_cars.equal(new colors(enum_colors.red)).booleanValue() && this.tl_peds.equal(new colors(enum_colors.red)).booleanValue())).booleanValue()) {
            this.tl_cars = new colors(enum_colors.redyellow);
        }
    }
    cars_y() {
        if ((new BBoolean(this.tl_cars.equal(new colors(enum_colors.green)).booleanValue() && this.tl_peds.equal(new colors(enum_colors.red)).booleanValue())).booleanValue()) {
            this.tl_cars = new colors(enum_colors.yellow);
        }
    }
    cars_g() {
        if ((new BBoolean(this.tl_cars.equal(new colors(enum_colors.redyellow)).booleanValue() && this.tl_peds.equal(new colors(enum_colors.red)).booleanValue())).booleanValue()) {
            this.tl_cars = new colors(enum_colors.green);
        }
    }
    cars_r() {
        if ((new BBoolean(this.tl_cars.equal(new colors(enum_colors.yellow)).booleanValue() && this.tl_peds.equal(new colors(enum_colors.red)).booleanValue())).booleanValue()) {
            this.tl_cars = new colors(enum_colors.red);
        }
    }
    peds_r() {
        if ((new BBoolean(this.tl_peds.equal(new colors(enum_colors.green)).booleanValue() && this.tl_cars.equal(new colors(enum_colors.red)).booleanValue())).booleanValue()) {
            this.tl_peds = new colors(enum_colors.red);
        }
    }
    peds_g() {
        if ((new BBoolean(this.tl_peds.equal(new colors(enum_colors.red)).booleanValue() && this.tl_cars.equal(new colors(enum_colors.red)).booleanValue())).booleanValue()) {
            this.tl_peds = new colors(enum_colors.green);
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
}
TrafficLight._colors = new BSet(new colors(enum_colors.red), new colors(enum_colors.redyellow), new colors(enum_colors.yellow), new colors(enum_colors.green));
