import { BInteger } from './btypes/BInteger.js';
import { BBoolean } from './btypes/BBoolean.js';
import { BSet } from './btypes/BSet.js';
export default class Sieve {
    constructor() {
        this.numbers = BSet.interval(new BInteger(2), new BInteger(2000000));
        this.cur = new BInteger(2);
        this.limit = new BInteger(2000000);
    }
    ComputeNumberOfPrimes() {
        let res = null;
        while ((new BBoolean(this.cur.greater(new BInteger(1)).booleanValue() && this.cur.multiply(this.cur).lessEqual(this.limit).booleanValue())).booleanValue()) {
            if ((this.numbers.elementOf(this.cur)).booleanValue()) {
                let n = null;
                let set = null;
                n = this.cur;
                set = new BSet();
                while ((n.lessEqual(this.limit.divide(this.cur))).booleanValue()) {
                    set = set.union(new BSet(this.cur.multiply(n)));
                    n = n.plus(new BInteger(1));
                }
                this.numbers = this.numbers.difference(set);
            }
            this.cur = this.cur.plus(new BInteger(1));
        }
        res = this.numbers.card();
        return res;
    }
    _get_numbers() {
        return this.numbers;
    }
    _get_cur() {
        return this.cur;
    }
    _get_limit() {
        return this.limit;
    }
}
let sieve = new Sieve();
console.log(sieve.ComputeNumberOfPrimes());
