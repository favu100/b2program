import {BInteger} from './btypes/BInteger.js';
import {BBoolean} from './btypes/BBoolean.js';
import Lift from './Lift.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";



export default class LiftExec {

    _Lift: Lift = new Lift();



    private counter: BInteger;

    constructor() {
        this.counter = new BInteger(0);
    }


     simulate(): void {
        while((this.counter.less(new BInteger(10000000))).booleanValue()) {
            let i: BInteger = null;
            i = new BInteger(0);
            while((i.less(new BInteger(100))).booleanValue()) {
                this._Lift.inc();
                i = i.plus(new BInteger(1));
            }
            let _i: BInteger = null;
            _i = new BInteger(0);
            while((_i.less(new BInteger(100))).booleanValue()) {
                this._Lift.dec();
                _i = _i.plus(new BInteger(1));
            }
            this.counter = this.counter.plus(new BInteger(1));
        }
    }

     getCounter(): BInteger {
        let out: BInteger = null;
        out = this.counter;
        return out;
    }

    _get_counter(): BInteger {
        return this.counter;
    }


}

let exec: LiftExec = new LiftExec();
exec.simulate();


