import { BInteger } from './btypes/BInteger.js';
import sort_m2_data1000 from './sort_m2_data1000.js';
export default class sort_m2_data1000_exec {
    constructor() {
        this._sort_m2_data1000 = new sort_m2_data1000();
        this.counter = new BInteger(0);
        this.sorted = new BInteger(0);
    }
    simulate() {
        while ((this.sorted.less(new BInteger(500))).booleanValue()) {
            this.counter = new BInteger(0);
            while ((this.counter.less(new BInteger(999).minus(new BInteger(2).multiply(this.sorted)))).booleanValue()) {
                this._sort_m2_data1000.prog2();
                this.counter = this.counter.plus(new BInteger(1));
            }
            this.counter = new BInteger(0);
            while ((this.counter.less(this.sorted)).booleanValue()) {
                this._sort_m2_data1000.prog1();
                this.counter = this.counter.plus(new BInteger(1));
            }
            this._sort_m2_data1000.progress();
            this.sorted = this.sorted.plus(new BInteger(1));
        }
        while ((this.sorted.less(new BInteger(999))).booleanValue()) {
            this.counter = new BInteger(0);
            while ((this.counter.less(new BInteger(999).minus(this.sorted))).booleanValue()) {
                this._sort_m2_data1000.prog1();
                this.counter = this.counter.plus(new BInteger(1));
            }
            this._sort_m2_data1000.progress();
            this.sorted = this.sorted.plus(new BInteger(1));
        }
        this._sort_m2_data1000.final_evt();
    }
    _get_counter() {
        return this.counter;
    }
    _get_sorted() {
        return this.sorted;
    }
}
let exec = new sort_m2_data1000_exec();
exec.simulate();
