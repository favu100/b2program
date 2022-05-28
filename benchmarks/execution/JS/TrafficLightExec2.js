import { BInteger } from './btypes/BInteger.js';
import TrafficLight from './TrafficLight.js';
export default class TrafficLightExec {
    constructor() {
        this._TrafficLight = new TrafficLight();
        this.counter = new BInteger(0);
    }
    simulate() {
        while ((this.counter.less(new BInteger(300000000))).booleanValue()) {
            this.counter = this.counter.plus(new BInteger(1));
        }
    }
    _get_counter() {
        return this.counter;
    }
}
let traffic = new TrafficLightExec();
traffic.simulate();
