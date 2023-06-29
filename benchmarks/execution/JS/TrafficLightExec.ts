import {BInteger} from './btypes/BInteger.js';
import {BBoolean} from './btypes/BBoolean.js';
import TrafficLight from './TrafficLight.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";



export default class TrafficLightExec {

    _TrafficLight: TrafficLight = new TrafficLight();



    private counter: BInteger;

    constructor() {
        this.counter = new BInteger(0);
    }


     simulate(): void {
        while((this.counter.less(new BInteger(15000000))).booleanValue()) {
            this._TrafficLight.cars_ry();
            this._TrafficLight.cars_g();
            this._TrafficLight.cars_y();
            this._TrafficLight.cars_r();
            this._TrafficLight.peds_g();
            this._TrafficLight.peds_r();
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

