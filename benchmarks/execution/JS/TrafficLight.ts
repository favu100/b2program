import {BBoolean} from './btypes/BBoolean.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";

export enum enum_colors {
    red,
    redyellow,
    yellow,
    green
}

export class colors implements BObject{
    value: enum_colors;

    constructor(value: enum_colors) {
        this.value = value;
    }

    equal(other: colors) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: colors) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof colors)) {
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

    static get_red () {return new colors(enum_colors.red);}
    static get_redyellow () {return new colors(enum_colors.redyellow);}
    static get_yellow () {return new colors(enum_colors.yellow);}
    static get_green () {return new colors(enum_colors.green);}


}


export default class TrafficLight {



    private static _colors: BSet<colors> = new BSet<colors>(new colors(enum_colors.red), new colors(enum_colors.redyellow), new colors(enum_colors.yellow), new colors(enum_colors.green));

    private tl_cars: colors;
    private tl_peds: colors;

    constructor() {
        this.tl_cars = new colors(enum_colors.red);
        this.tl_peds = new colors(enum_colors.red);
    }


     cars_ry(): void {
        if((new BBoolean(this.tl_cars.equal(new colors(enum_colors.red)).booleanValue() && this.tl_peds.equal(new colors(enum_colors.red)).booleanValue())).booleanValue()) {
            this.tl_cars = new colors(enum_colors.redyellow);
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     cars_y(): void {
        if((new BBoolean(this.tl_cars.equal(new colors(enum_colors.green)).booleanValue() && this.tl_peds.equal(new colors(enum_colors.red)).booleanValue())).booleanValue()) {
            this.tl_cars = new colors(enum_colors.yellow);
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     cars_g(): void {
        if((new BBoolean(this.tl_cars.equal(new colors(enum_colors.redyellow)).booleanValue() && this.tl_peds.equal(new colors(enum_colors.red)).booleanValue())).booleanValue()) {
            this.tl_cars = new colors(enum_colors.green);
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     cars_r(): void {
        if((new BBoolean(this.tl_cars.equal(new colors(enum_colors.yellow)).booleanValue() && this.tl_peds.equal(new colors(enum_colors.red)).booleanValue())).booleanValue()) {
            this.tl_cars = new colors(enum_colors.red);
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     peds_r(): void {
        if((new BBoolean(this.tl_peds.equal(new colors(enum_colors.green)).booleanValue() && this.tl_cars.equal(new colors(enum_colors.red)).booleanValue())).booleanValue()) {
            this.tl_peds = new colors(enum_colors.red);
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     peds_g(): void {
        if((new BBoolean(this.tl_peds.equal(new colors(enum_colors.red)).booleanValue() && this.tl_cars.equal(new colors(enum_colors.red)).booleanValue())).booleanValue()) {
            this.tl_peds = new colors(enum_colors.green);
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     getCars(): colors {
        let out: colors = null;
        out = this.tl_cars;
        return out;
    }

     getPeds(): colors {
        let out: colors = null;
        out = this.tl_peds;
        return out;
    }

    _get_tl_cars(): colors {
        return this.tl_cars;
    }

    _get_tl_peds(): colors {
        return this.tl_peds;
    }

    _get__colors(): BSet<colors> {
        return TrafficLight._colors;
    }


}

