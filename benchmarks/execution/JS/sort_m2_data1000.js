import { BTuple } from './btypes/BTuple.js';
import { BInteger } from './btypes/BInteger.js';
import { BRelation } from './btypes/BRelation.js';
import { BBoolean } from './btypes/BBoolean.js';
import { BSet } from './btypes/BSet.js';
import { SelectError } from "./btypes/BUtils.js";
export default class sort_m2_data1000 {
    constructor() {
        this.g = sort_m2_data1000.f;
        this.k = new BInteger(1);
        this.l = new BInteger(1);
        this.j = new BInteger(1);
    }
    progress() {
        if ((new BBoolean(this.k.unequal(sort_m2_data1000.n).booleanValue() && this.j.equal(sort_m2_data1000.n).booleanValue())).booleanValue()) {
            let _ld_l = this.l;
            let _ld_g = this.g;
            let _ld_k = this.k;
            this.g = _ld_g.override(new BRelation(new BTuple(_ld_k, _ld_g.functionCall(_ld_l))).override(new BRelation(new BTuple(_ld_l, _ld_g.functionCall(_ld_k)))));
            this.k = _ld_k.plus(new BInteger(1));
            this.j = _ld_k.plus(new BInteger(1));
            this.l = _ld_k.plus(new BInteger(1));
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    prog1() {
        if ((new BBoolean(new BBoolean(this.k.unequal(sort_m2_data1000.n).booleanValue() && this.j.unequal(sort_m2_data1000.n).booleanValue()).booleanValue() && this.g.functionCall(this.l).lessEqual(this.g.functionCall(this.j.plus(new BInteger(1)))).booleanValue())).booleanValue()) {
            let _ld_j = this.j;
            let _ld_l = this.l;
            this.l = _ld_l;
            this.j = _ld_j.plus(new BInteger(1));
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    prog2() {
        if ((new BBoolean(new BBoolean(this.k.unequal(sort_m2_data1000.n).booleanValue() && this.j.unequal(sort_m2_data1000.n).booleanValue()).booleanValue() && this.g.functionCall(this.l).greater(this.g.functionCall(this.j.plus(new BInteger(1)))).booleanValue())).booleanValue()) {
            let _ld_j = this.j;
            this.j = _ld_j.plus(new BInteger(1));
            this.l = _ld_j.plus(new BInteger(1));
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    final_evt() {
        if ((this.k.equal(sort_m2_data1000.n)).booleanValue()) {
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    _get_n() {
        return sort_m2_data1000.n;
    }
    _get_f() {
        return sort_m2_data1000.f;
    }
    _get_j() {
        return this.j;
    }
    _get_k() {
        return this.k;
    }
    _get_l() {
        return this.l;
    }
    _get_g() {
        return this.g;
    }
}
(() => {
    sort_m2_data1000.n = new BInteger(1000);
    let _ic_set_0 = new BRelation();
    for (let _ic_i_1 of BSet.interval(new BInteger(1), sort_m2_data1000.n)) {
        _ic_set_0 = _ic_set_0.union(new BRelation(new BTuple(_ic_i_1, new BInteger(15000).minus(_ic_i_1))));
    }
    sort_m2_data1000.f = _ic_set_0;
})();
