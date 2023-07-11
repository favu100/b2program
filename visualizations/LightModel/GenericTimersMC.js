import { BTuple } from './btypes/BTuple.js';
import { BBoolean } from './btypes/BBoolean.js';
import { BRelation } from './btypes/BRelation.js';
import { BSet } from './btypes/BSet.js';
import { SelectError } from "./btypes/BUtils.js";
import * as immutable from "./immutable/dist/immutable.es.js";
export var enum_TIMERS;
(function (enum_TIMERS) {
    enum_TIMERS[enum_TIMERS["blink_deadline"] = 0] = "blink_deadline";
    enum_TIMERS[enum_TIMERS["tip_deadline"] = 1] = "tip_deadline";
})(enum_TIMERS || (enum_TIMERS = {}));
export class TIMERS {
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
        if (!(o instanceof TIMERS)) {
            return false;
        }
        return this.value === o.value;
    }
    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }
    toString() {
        return enum_TIMERS[this.value].toString();
    }
    static get_blink_deadline() { return new TIMERS(enum_TIMERS.blink_deadline); }
    static get_tip_deadline() { return new TIMERS(enum_TIMERS.tip_deadline); }
}
export var Type;
(function (Type) {
    Type[Type["BFS"] = 0] = "BFS";
    Type[Type["DFS"] = 1] = "DFS";
    Type[Type["MIXED"] = 2] = "MIXED";
})(Type || (Type = {}));
export default class GenericTimersMC {
    constructor(copy) {
        this.dependentGuard = immutable.Set();
        this.guardCache = immutable.Map();
        this.dependentInvariant = immutable.Set();
        if (copy) {
            this.curDeadlines = copy.curDeadlines;
        }
        else {
            this.curDeadlines = new BRelation();
        }
    }
    AbsoluteSetDeadline(timer, deadline) {
        this.curDeadlines = this.curDeadlines.override(new BRelation(new BTuple(timer, deadline)));
    }
    AddDeadline(timer, deadline) {
        this.curDeadlines = this.curDeadlines.override(new BRelation(new BTuple(timer, deadline)));
    }
    IncreaseTime(delta) {
        if ((new BBoolean(delta.isNatural().booleanValue() && new BBoolean(!this.curDeadlines.unequal(new BRelation()).booleanValue() || delta.lessEqual(this.curDeadlines.range().min()).booleanValue()).booleanValue())).booleanValue()) {
            let _ic_set_0 = new BRelation();
            for (let _ic_x_1 of this.curDeadlines.domain()) {
                _ic_set_0 = _ic_set_0.union(new BRelation(new BTuple(_ic_x_1, this.curDeadlines.functionCall(_ic_x_1).minus(delta))));
            }
            this.curDeadlines = _ic_set_0;
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    IncreaseTimeUntilDeadline(timer, delta) {
        if ((new BBoolean(new BBoolean(new BBoolean(this.curDeadlines.domain().elementOf(timer).booleanValue() && delta.isNatural().booleanValue()).booleanValue() && delta.equal(this.curDeadlines.range().min()).booleanValue()).booleanValue() && delta.equal(this.curDeadlines.functionCall(timer)).booleanValue())).booleanValue()) {
            let _ic_set_1 = new BRelation();
            for (let _ic_x_1 of this.curDeadlines.domain().difference(new BSet(timer))) {
                _ic_set_1 = _ic_set_1.union(new BRelation(new BTuple(_ic_x_1, this.curDeadlines.functionCall(_ic_x_1).minus(delta))));
            }
            this.curDeadlines = _ic_set_1;
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    IncreaseTimeUntilCyclicDeadline(timer, delta, newDelta) {
        if ((new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.curDeadlines.domain().elementOf(timer).booleanValue() && delta.isNatural().booleanValue()).booleanValue() && newDelta.isNatural().booleanValue()).booleanValue() && delta.equal(this.curDeadlines.functionCall(timer)).booleanValue()).booleanValue() && delta.equal(this.curDeadlines.range().min()).booleanValue())).booleanValue()) {
            let _ic_set_2 = new BRelation();
            for (let _ic_x_1 of this.curDeadlines.domain().difference(new BSet(timer))) {
                _ic_set_2 = _ic_set_2.union(new BRelation(new BTuple(_ic_x_1, this.curDeadlines.functionCall(_ic_x_1).minus(delta))));
            }
            this.curDeadlines = _ic_set_2.union(new BRelation(new BTuple(timer, newDelta)));
        }
        else {
            throw new SelectError("Parameters are invalid!");
        }
    }
    _get_curDeadlines() {
        return this.curDeadlines;
    }
    _get__TIMERS() {
        return GenericTimersMC._TIMERS;
    }
    equals(o) {
        let o1 = this;
        let o2 = o;
        return o1._get_curDeadlines().equals(o2._get_curDeadlines());
    }
    hashCode() {
        return this._hashCode_1();
    }
    _hashCode_1() {
        let result = 1;
        result = (1543 * result) ^ ((this._get_curDeadlines()).hashCode() << 1);
        return result;
    }
    _hashCode_2() {
        let result = 1;
        result = (6151 * result) ^ ((this._get_curDeadlines()).hashCode() << 1);
        return result;
    }
    /* TODO
    toString(): string {
        return String.join("\n", "_get_curDeadlines: " + (this._get_curDeadlines()).toString());
    }
    */
    _copy() {
        return new GenericTimersMC(this);
    }
}
GenericTimersMC._TIMERS = new BSet(new TIMERS(enum_TIMERS.blink_deadline), new TIMERS(enum_TIMERS.tip_deadline));
