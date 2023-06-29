import { BInteger } from './btypes/BInteger.js';
export default class Lift {
    constructor() {
        this.floor = new BInteger(0);
    }
    inc() {
        this.floor = this.floor.plus(new BInteger(1));
    }
    dec() {
        this.floor = this.floor.minus(new BInteger(1));
    }
    getFloor() {
        let out = null;
        out = this.floor;
        return out;
    }
    _get_floor() {
        return this.floor;
    }
}
