import { BBoolean } from './btypes/BBoolean.js';
import { BSet } from './btypes/BSet.js';
import { SelectError } from "./btypes/BUtils.js";
export var enum_PID;
(function (enum_PID) {
    enum_PID[enum_PID["process1"] = 0] = "process1";
    enum_PID[enum_PID["process2"] = 1] = "process2";
    enum_PID[enum_PID["process3"] = 2] = "process3";
})(enum_PID || (enum_PID = {}));
export class PID {
    constructor(value) {
        this.value = value;
    }
    equal(other) {
        return new BBoolean(this.value === other.value);
    }
    unequal(other) {
        return new BBoolean(this.value !== other.value);
    }
    equals(o) {
        if (!(o instanceof PID)) {
            return false;
        }
        return this.value === o.value;
    }
    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }
    toString() {
        return enum_PID[this.value].toString();
    }
    static get_process1() { return new PID(enum_PID.process1); }
    static get_process2() { return new PID(enum_PID.process2); }
    static get_process3() { return new PID(enum_PID.process3); }
}
export default class scheduler_deterministic {
    constructor() {
        this.active = new BSet();
        this._ready = new BSet();
        this.waiting = new BSet();
    }
    _new(pp) {
        if ((new BBoolean(new BBoolean(scheduler_deterministic._PID.elementOf(pp).booleanValue() && this.active.notElementOf(pp).booleanValue()).booleanValue() && this._ready.union(this.waiting).notElementOf(pp).booleanValue())).booleanValue()) {
            this.waiting = this.waiting.union(new BSet(pp));
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    del(pp) {
        if ((this.waiting.elementOf(pp)).booleanValue()) {
            this.waiting = this.waiting.difference(new BSet(pp));
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    ready(rr) {
        if ((this.waiting.elementOf(rr)).booleanValue()) {
            this.waiting = this.waiting.difference(new BSet(rr));
            if ((this.active.equal(new BSet())).booleanValue()) {
                this.active = new BSet(rr);
            }
            else {
                this._ready = this._ready.union(new BSet(rr));
            }
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    swap(pp) {
        if ((this.active.unequal(new BSet())).booleanValue()) {
            this.waiting = this.waiting.union(this.active);
            if ((this._ready.equal(new BSet())).booleanValue()) {
                this.active = new BSet();
            }
            else {
                this.active = new BSet(pp);
                this._ready = this._ready.difference(new BSet(pp));
            }
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    _get_active() {
        return this.active;
    }
    _get__ready() {
        return this._ready;
    }
    _get_waiting() {
        return this.waiting;
    }
    _get__PID() {
        return scheduler_deterministic._PID;
    }
}
scheduler_deterministic._PID = new BSet(new PID(enum_PID.process1), new PID(enum_PID.process2), new PID(enum_PID.process3));
