import {BTuple} from './btypes/BTuple.js';
import {BInteger} from './btypes/BInteger.js';
import {BRelation} from './btypes/BRelation.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";
import {VariantViolation} from "./btypes/BUtils.js";
import {LoopInvariantViolation} from "./btypes/BUtils.js";
import * as immutable from "./immutable/dist/immutable.es.js";
import {LinkedList} from  "./modelchecking/LinkedList.js";




class _ProjectionRead_progress {

    public g: BRelation<BInteger, BInteger>;
    public j: BInteger;
    public k: BInteger;
    public l: BInteger;

    constructor(g : BRelation<BInteger, BInteger>, j : BInteger, k : BInteger, l : BInteger) {
        this.g = g;
        this.j = j;
        this.k = k;
        this.l = l;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_progress = this;
        let o2: _ProjectionRead_progress = other as _ProjectionRead_progress;
        return o1.g.equals(o2.g) && o1.j.equals(o2.j) && o1.k.equals(o2.k) && o1.l.equals(o2.l);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.g.hashCode() << 1);
        result = 31 * result + (this.j.hashCode() << 1);
        result = 31 * result + (this.k.hashCode() << 1);
        result = 31 * result + (this.l.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_progress {

    public j: BInteger;
    public k: BInteger;

    constructor(j : BInteger, k : BInteger) {
        this.j = j;
        this.k = k;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_progress = this;
        let o2: _ProjectionRead__tr_progress = other as _ProjectionRead__tr_progress;
        return o1.j.equals(o2.j) && o1.k.equals(o2.k);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.j.hashCode() << 1);
        result = 31 * result + (this.k.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_progress {

    public g: BRelation<BInteger, BInteger>;
    public j: BInteger;
    public k: BInteger;
    public l: BInteger;

    constructor(g : BRelation<BInteger, BInteger>, j : BInteger, k : BInteger, l : BInteger) {
        this.g = g;
        this.j = j;
        this.k = k;
        this.l = l;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_progress = this;
        let o2: _ProjectionWrite_progress = other as _ProjectionWrite_progress;
        return o1.g.equals(o2.g) && o1.j.equals(o2.j) && o1.k.equals(o2.k) && o1.l.equals(o2.l);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.g.hashCode() << 1);
        result = 31 * result + (this.j.hashCode() << 1);
        result = 31 * result + (this.k.hashCode() << 1);
        result = 31 * result + (this.l.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_prog1 {

    public g: BRelation<BInteger, BInteger>;
    public j: BInteger;
    public k: BInteger;
    public l: BInteger;

    constructor(g : BRelation<BInteger, BInteger>, j : BInteger, k : BInteger, l : BInteger) {
        this.g = g;
        this.j = j;
        this.k = k;
        this.l = l;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_prog1 = this;
        let o2: _ProjectionRead_prog1 = other as _ProjectionRead_prog1;
        return o1.g.equals(o2.g) && o1.j.equals(o2.j) && o1.k.equals(o2.k) && o1.l.equals(o2.l);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.g.hashCode() << 1);
        result = 31 * result + (this.j.hashCode() << 1);
        result = 31 * result + (this.k.hashCode() << 1);
        result = 31 * result + (this.l.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_prog1 {

    public g: BRelation<BInteger, BInteger>;
    public j: BInteger;
    public k: BInteger;
    public l: BInteger;

    constructor(g : BRelation<BInteger, BInteger>, j : BInteger, k : BInteger, l : BInteger) {
        this.g = g;
        this.j = j;
        this.k = k;
        this.l = l;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_prog1 = this;
        let o2: _ProjectionRead__tr_prog1 = other as _ProjectionRead__tr_prog1;
        return o1.g.equals(o2.g) && o1.j.equals(o2.j) && o1.k.equals(o2.k) && o1.l.equals(o2.l);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.g.hashCode() << 1);
        result = 31 * result + (this.j.hashCode() << 1);
        result = 31 * result + (this.k.hashCode() << 1);
        result = 31 * result + (this.l.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_prog1 {

    public j: BInteger;
    public l: BInteger;

    constructor(j : BInteger, l : BInteger) {
        this.j = j;
        this.l = l;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_prog1 = this;
        let o2: _ProjectionWrite_prog1 = other as _ProjectionWrite_prog1;
        return o1.j.equals(o2.j) && o1.l.equals(o2.l);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.j.hashCode() << 1);
        result = 31 * result + (this.l.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_prog2 {

    public g: BRelation<BInteger, BInteger>;
    public j: BInteger;
    public k: BInteger;
    public l: BInteger;

    constructor(g : BRelation<BInteger, BInteger>, j : BInteger, k : BInteger, l : BInteger) {
        this.g = g;
        this.j = j;
        this.k = k;
        this.l = l;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_prog2 = this;
        let o2: _ProjectionRead_prog2 = other as _ProjectionRead_prog2;
        return o1.g.equals(o2.g) && o1.j.equals(o2.j) && o1.k.equals(o2.k) && o1.l.equals(o2.l);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.g.hashCode() << 1);
        result = 31 * result + (this.j.hashCode() << 1);
        result = 31 * result + (this.k.hashCode() << 1);
        result = 31 * result + (this.l.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_prog2 {

    public g: BRelation<BInteger, BInteger>;
    public j: BInteger;
    public k: BInteger;
    public l: BInteger;

    constructor(g : BRelation<BInteger, BInteger>, j : BInteger, k : BInteger, l : BInteger) {
        this.g = g;
        this.j = j;
        this.k = k;
        this.l = l;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_prog2 = this;
        let o2: _ProjectionRead__tr_prog2 = other as _ProjectionRead__tr_prog2;
        return o1.g.equals(o2.g) && o1.j.equals(o2.j) && o1.k.equals(o2.k) && o1.l.equals(o2.l);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.g.hashCode() << 1);
        result = 31 * result + (this.j.hashCode() << 1);
        result = 31 * result + (this.k.hashCode() << 1);
        result = 31 * result + (this.l.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_prog2 {

    public j: BInteger;
    public l: BInteger;

    constructor(j : BInteger, l : BInteger) {
        this.j = j;
        this.l = l;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_prog2 = this;
        let o2: _ProjectionWrite_prog2 = other as _ProjectionWrite_prog2;
        return o1.j.equals(o2.j) && o1.l.equals(o2.l);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.j.hashCode() << 1);
        result = 31 * result + (this.l.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_final_evt {

    public k: BInteger;

    constructor(k : BInteger) {
        this.k = k;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_final_evt = this;
        let o2: _ProjectionRead_final_evt = other as _ProjectionRead_final_evt;
        return o1.k.equals(o2.k);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.k.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_final_evt {

    public k: BInteger;

    constructor(k : BInteger) {
        this.k = k;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_final_evt = this;
        let o2: _ProjectionRead__tr_final_evt = other as _ProjectionRead__tr_final_evt;
        return o1.k.equals(o2.k);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.k.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_final_evt {


    constructor() {
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_final_evt = this;
        let o2: _ProjectionWrite_final_evt = other as _ProjectionWrite_final_evt;
        return true;
    }

    hashCode(): number {
        let result: number = 1;
        return result;
    }
}


class _ProjectionRead__check_inv_1 {

    public j: BInteger;
    public k: BInteger;

    constructor(j : BInteger, k : BInteger) {
        this.j = j;
        this.k = k;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_1 = this;
        let o2: _ProjectionRead__check_inv_1 = other as _ProjectionRead__check_inv_1;
        return o1.j.equals(o2.j) && o1.k.equals(o2.k);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.j.hashCode() << 1);
        result = 31 * result + (this.k.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_2 {

    public j: BInteger;
    public k: BInteger;
    public l: BInteger;

    constructor(j : BInteger, k : BInteger, l : BInteger) {
        this.j = j;
        this.k = k;
        this.l = l;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_2 = this;
        let o2: _ProjectionRead__check_inv_2 = other as _ProjectionRead__check_inv_2;
        return o1.j.equals(o2.j) && o1.k.equals(o2.k) && o1.l.equals(o2.l);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.j.hashCode() << 1);
        result = 31 * result + (this.k.hashCode() << 1);
        result = 31 * result + (this.l.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_3 {

    public g: BRelation<BInteger, BInteger>;
    public j: BInteger;
    public k: BInteger;
    public l: BInteger;

    constructor(g : BRelation<BInteger, BInteger>, j : BInteger, k : BInteger, l : BInteger) {
        this.g = g;
        this.j = j;
        this.k = k;
        this.l = l;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_3 = this;
        let o2: _ProjectionRead__check_inv_3 = other as _ProjectionRead__check_inv_3;
        return o1.g.equals(o2.g) && o1.j.equals(o2.j) && o1.k.equals(o2.k) && o1.l.equals(o2.l);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.g.hashCode() << 1);
        result = 31 * result + (this.j.hashCode() << 1);
        result = 31 * result + (this.k.hashCode() << 1);
        result = 31 * result + (this.l.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_4 {

    public g: BRelation<BInteger, BInteger>;

    constructor(g : BRelation<BInteger, BInteger>) {
        this.g = g;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_4 = this;
        let o2: _ProjectionRead__check_inv_4 = other as _ProjectionRead__check_inv_4;
        return o1.g.equals(o2.g);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.g.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_5 {

    public g: BRelation<BInteger, BInteger>;

    constructor(g : BRelation<BInteger, BInteger>) {
        this.g = g;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_5 = this;
        let o2: _ProjectionRead__check_inv_5 = other as _ProjectionRead__check_inv_5;
        return o1.g.equals(o2.g);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.g.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_6 {

    public k: BInteger;

    constructor(k : BInteger) {
        this.k = k;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_6 = this;
        let o2: _ProjectionRead__check_inv_6 = other as _ProjectionRead__check_inv_6;
        return o1.k.equals(o2.k);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.k.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_7 {

    public l: BInteger;

    constructor(l : BInteger) {
        this.l = l;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_7 = this;
        let o2: _ProjectionRead__check_inv_7 = other as _ProjectionRead__check_inv_7;
        return o1.l.equals(o2.l);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.l.hashCode() << 1);
        return result;
    }
}


export enum Type {
    BFS,
    DFS,
    MIXED
}

export default class sort_m2_data1000_MC {

    parent: sort_m2_data1000_MC;
    stateAccessedVia: string;


    private static n: BInteger;
    private static f: BRelation<BInteger, BInteger>;
    private static __aux_constant_2: BSet<BInteger>;
    private static __aux_constant_1: BSet<BInteger>;


    private j: BInteger;
    private k: BInteger;
    private l: BInteger;
    private g: BRelation<BInteger, BInteger>;

    static {
        sort_m2_data1000_MC.n = new BInteger(1000);
        let _ic_set_0: BRelation<BInteger, BInteger> = new BRelation<BInteger, BInteger>();
        for(let _ic_i_1 of BSet.interval(new BInteger(1), sort_m2_data1000_MC.n)) {
            _ic_set_0 = _ic_set_0.union(new BRelation<BInteger, BInteger>(new BTuple(_ic_i_1, new BInteger(15000).minus(_ic_i_1))));

        }

        sort_m2_data1000_MC.f = _ic_set_0;
        sort_m2_data1000_MC.__aux_constant_2 = sort_m2_data1000_MC.f.range();
        sort_m2_data1000_MC.__aux_constant_1 = BSet.interval(new BInteger(1), sort_m2_data1000_MC.n);
        if(!(new BBoolean(new BBoolean(sort_m2_data1000_MC.n.isInteger().booleanValue() && sort_m2_data1000_MC.n.greater(new BInteger(0)).booleanValue()).booleanValue() && sort_m2_data1000_MC.f.checkDomain(BSet.interval(new BInteger(1), sort_m2_data1000_MC.n)).and(sort_m2_data1000_MC.f.checkRangeNatural()).and(sort_m2_data1000_MC.f.isFunction()).and(sort_m2_data1000_MC.f.isTotal(BSet.interval(new BInteger(1), sort_m2_data1000_MC.n))).booleanValue())).booleanValue()) {
            throw new Error("Contradiction in PROPERTIES detected!");
        }
    }

    constructor(copy? : sort_m2_data1000_MC) {
        if(copy) {
            this.j = copy.j;
            this.k = copy.k;
            this.l = copy.l;
            this.g = copy.g;
        } else {
            this.g = sort_m2_data1000_MC.f;
            this.k = new BInteger(1);
            this.l = new BInteger(1);
            this.j = new BInteger(1);
        }
    }



    progress(): void {
        let _ld_l: BInteger = this.l;
        let _ld_g: BRelation<BInteger, BInteger> = this.g;
        let _ld_k: BInteger = this.k;
        this.g = _ld_g.override(new BRelation<BInteger, BInteger>(new BTuple(_ld_k, _ld_g.functionCall(_ld_l))).override(new BRelation<BInteger, BInteger>(new BTuple(_ld_l, _ld_g.functionCall(_ld_k)))));
        this.k = _ld_k.plus(new BInteger(1));
        this.j = _ld_k.plus(new BInteger(1));
        this.l = _ld_k.plus(new BInteger(1));

    }

    prog1(): void {
        let _ld_j: BInteger = this.j;
        let _ld_l: BInteger = this.l;
        this.l = _ld_l;
        this.j = _ld_j.plus(new BInteger(1));

    }

    prog2(): void {
        let _ld_j: BInteger = this.j;
        this.j = _ld_j.plus(new BInteger(1));
        this.l = _ld_j.plus(new BInteger(1));

    }

    final_evt(): void {
    }

    _get_n(): BInteger {
        return sort_m2_data1000_MC.n;
    }

    _get_f(): BRelation<BInteger, BInteger> {
        return sort_m2_data1000_MC.f;
    }

    _get___aux_constant_2(): BSet<BInteger> {
        return sort_m2_data1000_MC.__aux_constant_2;
    }

    _get___aux_constant_1(): BSet<BInteger> {
        return sort_m2_data1000_MC.__aux_constant_1;
    }

    _get_j(): BInteger {
        return this.j;
    }

    _get_k(): BInteger {
        return this.k;
    }

    _get_l(): BInteger {
        return this.l;
    }

    _get_g(): BRelation<BInteger, BInteger> {
        return this.g;
    }

    equals(o: any): boolean {
        let o1: sort_m2_data1000_MC = this;
        let o2: sort_m2_data1000_MC = o as sort_m2_data1000_MC;
        return o1._get_j().equals(o2._get_j()) && o1._get_k().equals(o2._get_k()) && o1._get_l().equals(o2._get_l()) && o1._get_g().equals(o2._get_g());
    }



    hashCode(): number {
        return this._hashCode_1();
    }

    _hashCode_1(): number {
        let result: number = 1;
        result = (1543 * result) ^ ((this._get_j()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_k()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_l()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_g()).hashCode() << 1);
        return result;
    }

    _hashCode_2(): number {
        let result: number = 1;
        result = (6151 * result) ^ ((this._get_j()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_k()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_l()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_g()).hashCode() << 1);
        return result;
    }

    /* TODO
    toString(): string {
        return String.join("\n", "_get_j: " + (this._get_j()).toString(), "_get_k: " + (this._get_k()).toString(), "_get_l: " + (this._get_l()).toString(), "_get_g: " + (this._get_g()).toString());
    }
    */

    _tr_progress(): boolean {
        return new BBoolean(this.k.unequal(sort_m2_data1000_MC.n).booleanValue() && this.j.equal(sort_m2_data1000_MC.n).booleanValue()).booleanValue();
    }

    _tr_prog1(): boolean {
        return new BBoolean(new BBoolean(this.k.unequal(sort_m2_data1000_MC.n).booleanValue() && this.j.unequal(sort_m2_data1000_MC.n).booleanValue()).booleanValue() && this.g.functionCall(this.l).lessEqual(this.g.functionCall(this.j.plus(new BInteger(1)))).booleanValue()).booleanValue();
    }

    _tr_prog2(): boolean {
        return new BBoolean(new BBoolean(this.k.unequal(sort_m2_data1000_MC.n).booleanValue() && this.j.unequal(sort_m2_data1000_MC.n).booleanValue()).booleanValue() && this.g.functionCall(this.l).greater(this.g.functionCall(this.j.plus(new BInteger(1)))).booleanValue()).booleanValue();
    }

    _tr_final_evt(): boolean {
        return this.k.equal(sort_m2_data1000_MC.n).booleanValue();
    }

    _projected_state_for_prog2(): _ProjectionRead_prog2 {
        return new _ProjectionRead_prog2(this.g,this.j,this.k,this.l);
    }

    _projected_state_for_prog1(): _ProjectionRead_prog1 {
        return new _ProjectionRead_prog1(this.g,this.j,this.k,this.l);
    }

    _projected_state_for_progress(): _ProjectionRead_progress {
        return new _ProjectionRead_progress(this.g,this.j,this.k,this.l);
    }

    _projected_state_for_final_evt(): _ProjectionRead_final_evt {
        return new _ProjectionRead_final_evt(this.k);
    }

    _projected_state_for__tr_final_evt(): _ProjectionRead__tr_final_evt {
        return new _ProjectionRead__tr_final_evt(this.k);
    }

    _projected_state_for__tr_progress(): _ProjectionRead__tr_progress {
        return new _ProjectionRead__tr_progress(this.j,this.k);
    }

    _projected_state_for__tr_prog1(): _ProjectionRead__tr_prog1 {
        return new _ProjectionRead__tr_prog1(this.g,this.j,this.k,this.l);
    }

    _projected_state_for__tr_prog2(): _ProjectionRead__tr_prog2 {
        return new _ProjectionRead__tr_prog2(this.g,this.j,this.k,this.l);
    }

    _projected_state_for__check_inv_2(): _ProjectionRead__check_inv_2 {
        return new _ProjectionRead__check_inv_2(this.j,this.k,this.l);
    }

    _projected_state_for__check_inv_3(): _ProjectionRead__check_inv_3 {
        return new _ProjectionRead__check_inv_3(this.g,this.j,this.k,this.l);
    }

    _projected_state_for__check_inv_1(): _ProjectionRead__check_inv_1 {
        return new _ProjectionRead__check_inv_1(this.j,this.k);
    }

    _projected_state_for__check_inv_6(): _ProjectionRead__check_inv_6 {
        return new _ProjectionRead__check_inv_6(this.k);
    }

    _projected_state_for__check_inv_7(): _ProjectionRead__check_inv_7 {
        return new _ProjectionRead__check_inv_7(this.l);
    }

    _projected_state_for__check_inv_4(): _ProjectionRead__check_inv_4 {
        return new _ProjectionRead__check_inv_4(this.g);
    }

    _projected_state_for__check_inv_5(): _ProjectionRead__check_inv_5 {
        return new _ProjectionRead__check_inv_5(this.g);
    }

    _update_for_prog2(): _ProjectionWrite_prog2 {
        return new _ProjectionWrite_prog2(this.j,this.l);
    }

    _update_for_prog1(): _ProjectionWrite_prog1 {
        return new _ProjectionWrite_prog1(this.j,this.l);
    }

    _update_for_progress(): _ProjectionWrite_progress {
        return new _ProjectionWrite_progress(this.g,this.j,this.k,this.l);
    }

    _update_for_final_evt(): _ProjectionWrite_final_evt {
        return new _ProjectionWrite_final_evt();
    }

    _apply_update_for_prog2(update : _ProjectionWrite_prog2): void {
        this.j = update.j;
        this.l = update.l;
    }

    _apply_update_for_prog1(update : _ProjectionWrite_prog1): void {
        this.j = update.j;
        this.l = update.l;
    }

    _apply_update_for_progress(update : _ProjectionWrite_progress): void {
        this.g = update.g;
        this.j = update.j;
        this.k = update.k;
        this.l = update.l;
    }

    _apply_update_for_final_evt(update : _ProjectionWrite_final_evt): void {
    }

    _check_inv_1() {
        return new BBoolean(this.j.greaterEqual(this.k).booleanValue() && this.j.lessEqual(sort_m2_data1000_MC.n).booleanValue()).booleanValue();
    }

    _check_inv_2() {
        return new BBoolean(this.l.greaterEqual(this.k).booleanValue() && this.l.lessEqual(this.j).booleanValue()).booleanValue();
    }

    _check_inv_3() {
        return this.g.functionCall(this.l).equal(this.g.relationImage(BSet.interval(this.k, this.j)).min()).booleanValue();
    }

    _check_inv_4() {
        return this.g.checkDomain(sort_m2_data1000_MC.__aux_constant_1).and(this.g.checkRangeNatural()).and(this.g.isFunction()).and(this.g.isTotal(sort_m2_data1000_MC.__aux_constant_1)).booleanValue();
    }

    _check_inv_5() {
        return this.g.range().equal(sort_m2_data1000_MC.__aux_constant_2).booleanValue();
    }

    _check_inv_6() {
        return new BBoolean(this.k.greaterEqual(new BInteger(1)).booleanValue() && this.k.lessEqual(sort_m2_data1000_MC.n).booleanValue()).booleanValue();
    }

    _check_inv_7() {
        return this.l.isNatural().booleanValue();
    }


    public _copy(): sort_m2_data1000_MC {
      return new sort_m2_data1000_MC(this);
    }


}


export class ModelChecker {
    private type: Type;
    private isCaching: boolean;
    private isDebug: boolean;

    private unvisitedStates: LinkedList<sort_m2_data1000_MC> = new LinkedList<sort_m2_data1000_MC>;
    private states: immutable.Set<sort_m2_data1000_MC> = new immutable.Set();
    private transitions: number = 0;

    private invariantViolated: boolean = false;
    private deadlockDetected: boolean = false;
    private counterExampleState: sort_m2_data1000_MC = undefined;

    _OpCache_progress: immutable.Map<boolean, immutable.Map<_ProjectionRead_progress, _ProjectionWrite_progress>> = new immutable.Map();
    _OpCache_tr_progress: immutable.Map<_ProjectionRead__tr_progress, boolean> = new immutable.Map();

    _OpCache_prog1: immutable.Map<boolean, immutable.Map<_ProjectionRead_prog1, _ProjectionWrite_prog1>> = new immutable.Map();
    _OpCache_tr_prog1: immutable.Map<_ProjectionRead__tr_prog1, boolean> = new immutable.Map();

    _OpCache_prog2: immutable.Map<boolean, immutable.Map<_ProjectionRead_prog2, _ProjectionWrite_prog2>> = new immutable.Map();
    _OpCache_tr_prog2: immutable.Map<_ProjectionRead__tr_prog2, boolean> = new immutable.Map();

    _OpCache_final_evt: immutable.Map<boolean, immutable.Map<_ProjectionRead_final_evt, _ProjectionWrite_final_evt>> = new immutable.Map();
    _OpCache_tr_final_evt: immutable.Map<_ProjectionRead__tr_final_evt, boolean> = new immutable.Map();

    _InvCache__check_inv_1: immutable.Map<_ProjectionRead__check_inv_1, boolean> = new immutable.Map();
    _InvCache__check_inv_2: immutable.Map<_ProjectionRead__check_inv_2, boolean> = new immutable.Map();
    _InvCache__check_inv_3: immutable.Map<_ProjectionRead__check_inv_3, boolean> = new immutable.Map();
    _InvCache__check_inv_4: immutable.Map<_ProjectionRead__check_inv_4, boolean> = new immutable.Map();
    _InvCache__check_inv_5: immutable.Map<_ProjectionRead__check_inv_5, boolean> = new immutable.Map();
    _InvCache__check_inv_6: immutable.Map<_ProjectionRead__check_inv_6, boolean> = new immutable.Map();
    _InvCache__check_inv_7: immutable.Map<_ProjectionRead__check_inv_7, boolean> = new immutable.Map();

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
        let machine: sort_m2_data1000_MC = new sort_m2_data1000_MC();
        this.states = this.states.add(machine);
        this.unvisitedStates.pushBack(machine);

        while(!(this.unvisitedStates.length === 0)) {
            let state: sort_m2_data1000_MC = this.next();

            let nextStates: Set<sort_m2_data1000_MC> = this.generateNextStates(state);

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

    next(): sort_m2_data1000_MC {
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

    generateNextStates(state: sort_m2_data1000_MC): Set<sort_m2_data1000_MC> {
        let result: immutable.Set<sort_m2_data1000_MC> = immutable.Set();
        if(this.isCaching) {
            let read__tr_progress_state : _ProjectionRead__tr_progress = state._projected_state_for__tr_progress();
            let _obj__trid_1: any = this._OpCache_tr_progress.get(read__tr_progress_state);
            let _trid_1: boolean;
            if(_obj__trid_1 == null) {
                _trid_1 = state._tr_progress();
                this._OpCache_tr_progress = this._OpCache_tr_progress.set(read__tr_progress_state, _trid_1);
            } else {
                _trid_1 = _obj__trid_1;
            }

            if(_trid_1) {
                let copiedState: sort_m2_data1000_MC = state._copy();
                let readState: _ProjectionRead_progress = state._projected_state_for_progress();
                let _OpCache_with_parameter_progress: immutable.Map = this._OpCache_progress.get(_trid_1);
                if(_OpCache_with_parameter_progress != null) {
                    let writeState: _ProjectionWrite_progress = _OpCache_with_parameter_progress.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_progress(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.progress();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_progress();
                        _OpCache_with_parameter_progress = _OpCache_with_parameter_progress.set(readState, writeState);
                        this._OpCache_progress = this._OpCache_progress.set(_trid_1, _OpCache_with_parameter_progress);
                    }

                } else {
                    copiedState.progress();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_progress = copiedState._update_for_progress();
                    _OpCache_with_parameter_progress = new immutable.Map().set(readState, writeState);
                    this._OpCache_progress = this._OpCache_progress.set(_trid_1, _OpCache_with_parameter_progress);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_prog1_state : _ProjectionRead__tr_prog1 = state._projected_state_for__tr_prog1();
            let _obj__trid_2: any = this._OpCache_tr_prog1.get(read__tr_prog1_state);
            let _trid_2: boolean;
            if(_obj__trid_2 == null) {
                _trid_2 = state._tr_prog1();
                this._OpCache_tr_prog1 = this._OpCache_tr_prog1.set(read__tr_prog1_state, _trid_2);
            } else {
                _trid_2 = _obj__trid_2;
            }

            if(_trid_2) {
                let copiedState: sort_m2_data1000_MC = state._copy();
                let readState: _ProjectionRead_prog1 = state._projected_state_for_prog1();
                let _OpCache_with_parameter_prog1: immutable.Map = this._OpCache_prog1.get(_trid_2);
                if(_OpCache_with_parameter_prog1 != null) {
                    let writeState: _ProjectionWrite_prog1 = _OpCache_with_parameter_prog1.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_prog1(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.prog1();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_prog1();
                        _OpCache_with_parameter_prog1 = _OpCache_with_parameter_prog1.set(readState, writeState);
                        this._OpCache_prog1 = this._OpCache_prog1.set(_trid_2, _OpCache_with_parameter_prog1);
                    }

                } else {
                    copiedState.prog1();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_prog1 = copiedState._update_for_prog1();
                    _OpCache_with_parameter_prog1 = new immutable.Map().set(readState, writeState);
                    this._OpCache_prog1 = this._OpCache_prog1.set(_trid_2, _OpCache_with_parameter_prog1);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_prog2_state : _ProjectionRead__tr_prog2 = state._projected_state_for__tr_prog2();
            let _obj__trid_3: any = this._OpCache_tr_prog2.get(read__tr_prog2_state);
            let _trid_3: boolean;
            if(_obj__trid_3 == null) {
                _trid_3 = state._tr_prog2();
                this._OpCache_tr_prog2 = this._OpCache_tr_prog2.set(read__tr_prog2_state, _trid_3);
            } else {
                _trid_3 = _obj__trid_3;
            }

            if(_trid_3) {
                let copiedState: sort_m2_data1000_MC = state._copy();
                let readState: _ProjectionRead_prog2 = state._projected_state_for_prog2();
                let _OpCache_with_parameter_prog2: immutable.Map = this._OpCache_prog2.get(_trid_3);
                if(_OpCache_with_parameter_prog2 != null) {
                    let writeState: _ProjectionWrite_prog2 = _OpCache_with_parameter_prog2.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_prog2(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.prog2();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_prog2();
                        _OpCache_with_parameter_prog2 = _OpCache_with_parameter_prog2.set(readState, writeState);
                        this._OpCache_prog2 = this._OpCache_prog2.set(_trid_3, _OpCache_with_parameter_prog2);
                    }

                } else {
                    copiedState.prog2();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_prog2 = copiedState._update_for_prog2();
                    _OpCache_with_parameter_prog2 = new immutable.Map().set(readState, writeState);
                    this._OpCache_prog2 = this._OpCache_prog2.set(_trid_3, _OpCache_with_parameter_prog2);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_final_evt_state : _ProjectionRead__tr_final_evt = state._projected_state_for__tr_final_evt();
            let _obj__trid_4: any = this._OpCache_tr_final_evt.get(read__tr_final_evt_state);
            let _trid_4: boolean;
            if(_obj__trid_4 == null) {
                _trid_4 = state._tr_final_evt();
                this._OpCache_tr_final_evt = this._OpCache_tr_final_evt.set(read__tr_final_evt_state, _trid_4);
            } else {
                _trid_4 = _obj__trid_4;
            }

            if(_trid_4) {
                let copiedState: sort_m2_data1000_MC = state._copy();
                let readState: _ProjectionRead_final_evt = state._projected_state_for_final_evt();
                let _OpCache_with_parameter_final_evt: immutable.Map = this._OpCache_final_evt.get(_trid_4);
                if(_OpCache_with_parameter_final_evt != null) {
                    let writeState: _ProjectionWrite_final_evt = _OpCache_with_parameter_final_evt.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_final_evt(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.final_evt();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_final_evt();
                        _OpCache_with_parameter_final_evt = _OpCache_with_parameter_final_evt.set(readState, writeState);
                        this._OpCache_final_evt = this._OpCache_final_evt.set(_trid_4, _OpCache_with_parameter_final_evt);
                    }

                } else {
                    copiedState.final_evt();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_final_evt = copiedState._update_for_final_evt();
                    _OpCache_with_parameter_final_evt = new immutable.Map().set(readState, writeState);
                    this._OpCache_final_evt = this._OpCache_final_evt.set(_trid_4, _OpCache_with_parameter_final_evt);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        } else {
            if(state._tr_progress()) {
                let copiedState: sort_m2_data1000_MC = state._copy();
                copiedState.progress();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_prog1()) {
                let copiedState: sort_m2_data1000_MC = state._copy();
                copiedState.prog1();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_prog2()) {
                let copiedState: sort_m2_data1000_MC = state._copy();
                copiedState.prog2();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_final_evt()) {
                let copiedState: sort_m2_data1000_MC = state._copy();
                copiedState.final_evt();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        }
        return result;
    }

    invViolated(state: sort_m2_data1000_MC): boolean {
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

