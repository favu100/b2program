import { BInteger } from './btypes/BInteger.js';
import Lift from './Lift.js';
export default class LiftExec {
    constructor() {
        this._Lift = new Lift();
        this.counter = new BInteger(0);
    }
    simulate() {
        while ((this.counter.less(new BInteger(10000000))).booleanValue()) {
            let i = null;
            i = new BInteger(0);
            while ((i.less(new BInteger(100))).booleanValue()) {
                this._Lift.inc();
                i = i.plus(new BInteger(1));
            }
            let _i = null;
            _i = new BInteger(0);
            while ((_i.less(new BInteger(100))).booleanValue()) {
                this._Lift.dec();
                _i = _i.plus(new BInteger(1));
            }
            this.counter = this.counter.plus(new BInteger(1));
        }
    }
    getCounter() {
        let out = null;
        out = this.counter;
        return out;
    }
    _get_counter() {
        return this.counter;
    }
}
