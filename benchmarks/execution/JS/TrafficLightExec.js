import { BInteger } from './btypes/BInteger.js';
import TrafficLight from './TrafficLight.js';
export default class TrafficLightExec {
    constructor() {
        this._TrafficLight = new TrafficLight();
        this.counter = new BInteger(0);
    }
    simulate() {
        while ((this.counter.less(new BInteger(300000000))).booleanValue()) {
            this._TrafficLight.cars_ry();
            this._TrafficLight.cars_g();
            this._TrafficLight.cars_y();
            this._TrafficLight.cars_r();
            this._TrafficLight.peds_g();
            this._TrafficLight.peds_r();
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
