import {BInteger} from './btypes/BInteger.js';
import {BBoolean} from './btypes/BBoolean.js';
import sort_m2_data1000 from './sort_m2_data1000.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";



export default class sort_m2_data1000_exec {

    _sort_m2_data1000: sort_m2_data1000 = new sort_m2_data1000();



    private counter: BInteger;
    private sorted: BInteger;

    constructor() {
        this.counter = new BInteger(0);
        this.sorted = new BInteger(0);
    }


     simulate(): void {
        while((this.sorted.less(new BInteger(1000))).booleanValue()) {
            while((this.counter.less(new BInteger(1000).minus(this.sorted))).booleanValue()) {
                this._sort_m2_data1000.prog2();
                this.counter = this.counter.plus(new BInteger(1));
            }
            this.counter = new BInteger(0);
            while((this.counter.less(this.sorted)).booleanValue()) {
                this._sort_m2_data1000.prog1();
                this.counter = this.counter.plus(new BInteger(1));
            }
            this._sort_m2_data1000.progress();
            this.sorted = this.sorted.plus(new BInteger(1));
        }
        this._sort_m2_data1000.final_evt();
    }

    _get_counter(): BInteger {
        return this.counter;
    }

    _get_sorted(): BInteger {
        return this.sorted;
    }


}

let exec: sort_m2_data1000_exec = new sort_m2_data1000_exec();
exec.simulate();