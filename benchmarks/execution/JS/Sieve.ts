import {BInteger} from './btypes/BInteger.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BSet} from './btypes/BSet.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";



export default class Sieve {




    private numbers: BSet<BInteger>;
    private cur: BInteger;
    private limit: BInteger;

    constructor() {
        this.numbers = BSet.interval(new BInteger(2), new BInteger(1000000));
        this.cur = new BInteger(2);
        this.limit = new BInteger(1000000);
    }


     ComputeNumberOfPrimes(): BInteger {
        let res: BInteger = null;
        while((new BBoolean(this.cur.greater(new BInteger(1)).booleanValue() && this.cur.multiply(this.cur).lessEqual(this.limit).booleanValue())).booleanValue()) {
            if((this.numbers.elementOf(this.cur)).booleanValue()) {
                let n: BInteger = null;
                let set: BSet<BInteger> = null;
                n = this.cur;
                set = new BSet<BInteger>();
                while((n.lessEqual(this.limit.divide(this.cur))).booleanValue()) {
                    set = set.union(new BSet<BInteger>(this.cur.multiply(n)));
                    n = n.plus(new BInteger(1));
                }
                this.numbers = this.numbers.difference(set);
            } 
            this.cur = this.cur.plus(new BInteger(1));
        }
        res = this.numbers.card();
        return res;
    }

    _get_numbers(): BSet<BInteger> {
        return this.numbers;
    }

    _get_cur(): BInteger {
        return this.cur;
    }

    _get_limit(): BInteger {
        return this.limit;
    }


}

let sieve: Sieve = new Sieve();
console.log(sieve.ComputeNumberOfPrimes().toString());