import {BTuple} from './btypes/BTuple.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";
import * as immutable from "./immutable/dist/immutable.es.js";
import {LinkedList} from  "./modelchecking/LinkedList.js";


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


export enum Type {
    BFS,
    DFS,
    MIXED
}

export default class TrafficLight {

    parent: TrafficLight;
    dependentGuard: immutable.Set<string> = immutable.Set();
    guardCache: immutable.Map = immutable.Map();
    dependentInvariant: immutable.Set<string> = immutable.Set();
    stateAccessedVia: string;



    private static _colors: BSet<colors> = new BSet<colors>(new colors(enum_colors.red), new colors(enum_colors.redyellow), new colors(enum_colors.yellow), new colors(enum_colors.green));

    private tl_cars: colors;
    private tl_peds: colors;

    constructor(copy? : TrafficLight) {
        if(copy) {
            this.tl_cars = copy.tl_cars;
            this.tl_peds = copy.tl_peds;
        } else {
            this.tl_cars = new colors(enum_colors.red);
            this.tl_peds = new colors(enum_colors.red);
        }
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

    _get_tl_cars(): colors {
        return this.tl_cars;
    }

    _get_tl_peds(): colors {
        return this.tl_peds;
    }

    _get__colors(): BSet<colors> {
        return TrafficLight._colors;
    }

    _tr_cars_ry(): boolean {
        return new BBoolean(this.tl_cars.equal(new colors(enum_colors.red)).booleanValue() && this.tl_peds.equal(new colors(enum_colors.red)).booleanValue()).booleanValue();
    }

    _tr_cars_y(): boolean {
        return new BBoolean(this.tl_cars.equal(new colors(enum_colors.green)).booleanValue() && this.tl_peds.equal(new colors(enum_colors.red)).booleanValue()).booleanValue();
    }

    _tr_cars_g(): boolean {
        return new BBoolean(this.tl_cars.equal(new colors(enum_colors.redyellow)).booleanValue() && this.tl_peds.equal(new colors(enum_colors.red)).booleanValue()).booleanValue();
    }

    _tr_cars_r(): boolean {
        return new BBoolean(this.tl_cars.equal(new colors(enum_colors.yellow)).booleanValue() && this.tl_peds.equal(new colors(enum_colors.red)).booleanValue()).booleanValue();
    }

    _tr_peds_r(): boolean {
        return new BBoolean(this.tl_peds.equal(new colors(enum_colors.green)).booleanValue() && this.tl_cars.equal(new colors(enum_colors.red)).booleanValue()).booleanValue();
    }

    _tr_peds_g(): boolean {
        return new BBoolean(this.tl_peds.equal(new colors(enum_colors.red)).booleanValue() && this.tl_cars.equal(new colors(enum_colors.red)).booleanValue()).booleanValue();
    }

    _check_inv_1() {
        return TrafficLight._colors.elementOf(this.tl_cars).booleanValue();
    }

    _check_inv_2() {
        return new BSet<colors>(new colors(enum_colors.red), new colors(enum_colors.green)).elementOf(this.tl_peds).booleanValue();
    }

    _check_inv_3() {
        return new BBoolean(this.tl_peds.equal(new colors(enum_colors.red)).booleanValue() || this.tl_cars.equal(new colors(enum_colors.red)).booleanValue()).booleanValue();
    }

    equals(o: any): boolean {
        let o1: TrafficLight = this;
        let o2: TrafficLight = o as TrafficLight;
        return o1._get_tl_cars().equals(o2._get_tl_cars()) && o1._get_tl_peds().equals(o2._get_tl_peds());
    }



    hashCode(): number {
        return this._hashCode_1();
    }

    _hashCode_1(): number {
        let result: number = 1;
        result = (1543 * result) ^ ((this._get_tl_cars()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_tl_peds()).hashCode() << 1);
        return result;
    }

    _hashCode_2(): number {
        let result: number = 1;
        result = (6151 * result) ^ ((this._get_tl_cars()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_tl_peds()).hashCode() << 1);
        return result;
    }

    /* TODO
    toString(): string {
        return String.join("\n", "_get_tl_cars: " + (this._get_tl_cars()).toString(), "_get_tl_peds: " + (this._get_tl_peds()).toString());
    }
    */


    public _copy(): TrafficLight {
      return new TrafficLight(this);
    }


}

