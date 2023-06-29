import {BTuple} from './btypes/BTuple.js';
import {BInteger} from './btypes/BInteger.js';
import {BRelation} from './btypes/BRelation.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BSet} from './btypes/BSet.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";



export default class sort_m2_data1000 {


    private static n: BInteger;
    private static f: BRelation<BInteger, BInteger>;


    private j: BInteger;
    private k: BInteger;
    private l: BInteger;
    private g: BRelation<BInteger, BInteger>;

    static {
        sort_m2_data1000.n = new BInteger(1000);
        let _ic_set_0: BRelation<BInteger, BInteger> = new BRelation<BInteger, BInteger>();
        for(let _ic_i_1 of BSet.interval(new BInteger(1), sort_m2_data1000.n)) {
            _ic_set_0 = _ic_set_0.union(new BRelation<BInteger, BInteger>(new BTuple(_ic_i_1, new BInteger(15000).minus(_ic_i_1))));

        }
        sort_m2_data1000.f = _ic_set_0;
    }

    constructor() {
        this.g = sort_m2_data1000.f;
        this.k = new BInteger(1);
        this.l = new BInteger(1);
        this.j = new BInteger(1);
    }


     progress(): void {
        if((new BBoolean(this.k.unequal(sort_m2_data1000.n).booleanValue() && this.j.equal(sort_m2_data1000.n).booleanValue())).booleanValue()) {
            let _ld_l: BInteger = this.l;
            let _ld_g: BRelation<BInteger, BInteger> = this.g;
            let _ld_k: BInteger = this.k;
            this.g = _ld_g.override(new BRelation<BInteger, BInteger>(new BTuple(_ld_k, _ld_g.functionCall(_ld_l))).override(new BRelation<BInteger, BInteger>(new BTuple(_ld_l, _ld_g.functionCall(_ld_k)))));
            this.k = _ld_k.plus(new BInteger(1));
            this.j = _ld_k.plus(new BInteger(1));
            this.l = _ld_k.plus(new BInteger(1));
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     prog1(): void {
        if((new BBoolean(new BBoolean(this.k.unequal(sort_m2_data1000.n).booleanValue() && this.j.unequal(sort_m2_data1000.n).booleanValue()).booleanValue() && this.g.functionCall(this.l).lessEqual(this.g.functionCall(this.j.plus(new BInteger(1)))).booleanValue())).booleanValue()) {
            let _ld_j: BInteger = this.j;
            let _ld_l: BInteger = this.l;
            this.l = _ld_l;
            this.j = _ld_j.plus(new BInteger(1));
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     prog2(): void {
        if((new BBoolean(new BBoolean(this.k.unequal(sort_m2_data1000.n).booleanValue() && this.j.unequal(sort_m2_data1000.n).booleanValue()).booleanValue() && this.g.functionCall(this.l).greater(this.g.functionCall(this.j.plus(new BInteger(1)))).booleanValue())).booleanValue()) {
            let _ld_j: BInteger = this.j;
            this.j = _ld_j.plus(new BInteger(1));
            this.l = _ld_j.plus(new BInteger(1));
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     final_evt(): void {
        if((this.k.equal(sort_m2_data1000.n)).booleanValue()) {
        } else {
            throw new SelectError("Parameters are invalid!");
        }
    }

    _get_n(): BInteger {
        return sort_m2_data1000.n;
    }

    _get_f(): BRelation<BInteger, BInteger> {
        return sort_m2_data1000.f;
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


}

