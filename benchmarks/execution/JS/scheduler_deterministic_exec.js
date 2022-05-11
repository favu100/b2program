import { BInteger } from './btypes/BInteger.js';
import { enum_PID } from "./scheduler_deterministic.js";
import { PID } from "./scheduler_deterministic.js";
import scheduler_deterministic from './scheduler_deterministic.js';
export default class scheduler_deterministic_exec {
    constructor() {
        this._scheduler_deterministic = new scheduler_deterministic();
        this.counter = new BInteger(0);
    }
    simulate() {
        while ((this.counter.less(new BInteger(300000))).booleanValue()) {
            this._scheduler_deterministic._new(new PID(enum_PID.process1));
            this._scheduler_deterministic._new(new PID(enum_PID.process2));
            this._scheduler_deterministic._new(new PID(enum_PID.process3));
            this._scheduler_deterministic.del(new PID(enum_PID.process1));
            this._scheduler_deterministic._new(new PID(enum_PID.process1));
            this._scheduler_deterministic.del(new PID(enum_PID.process2));
            this._scheduler_deterministic.del(new PID(enum_PID.process1));
            this._scheduler_deterministic.del(new PID(enum_PID.process3));
            this._scheduler_deterministic._new(new PID(enum_PID.process1));
            this._scheduler_deterministic._new(new PID(enum_PID.process2));
            this._scheduler_deterministic.del(new PID(enum_PID.process1));
            this._scheduler_deterministic.ready(new PID(enum_PID.process2));
            this._scheduler_deterministic._new(new PID(enum_PID.process1));
            this._scheduler_deterministic._new(new PID(enum_PID.process3));
            this._scheduler_deterministic.del(new PID(enum_PID.process1));
            this._scheduler_deterministic.ready(new PID(enum_PID.process3));
            this._scheduler_deterministic._new(new PID(enum_PID.process1));
            this._scheduler_deterministic.ready(new PID(enum_PID.process1));
            this._scheduler_deterministic.swap(new PID(enum_PID.process1));
            this._scheduler_deterministic.del(new PID(enum_PID.process2));
            this._scheduler_deterministic.swap(new PID(enum_PID.process3));
            this._scheduler_deterministic._new(new PID(enum_PID.process2));
            this._scheduler_deterministic.del(new PID(enum_PID.process1));
            this._scheduler_deterministic.del(new PID(enum_PID.process2));
            this._scheduler_deterministic.swap(new PID(enum_PID.process1));
            this._scheduler_deterministic._new(new PID(enum_PID.process1));
            this._scheduler_deterministic._new(new PID(enum_PID.process2));
            this._scheduler_deterministic.del(new PID(enum_PID.process1));
            this._scheduler_deterministic.del(new PID(enum_PID.process3));
            this._scheduler_deterministic._new(new PID(enum_PID.process1));
            this._scheduler_deterministic.del(new PID(enum_PID.process2));
            this._scheduler_deterministic.del(new PID(enum_PID.process1));
            this.counter = this.counter.plus(new BInteger(1));
        }
    }
    _get_counter() {
        return this.counter;
    }
}
let _exec = new scheduler_deterministic_exec();
_exec.simulate();
