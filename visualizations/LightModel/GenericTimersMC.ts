import {BTuple} from './btypes/BTuple.js';
import {BInteger} from './btypes/BInteger.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BRelation} from './btypes/BRelation.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";

export enum enum_TIMERS {
    blink_deadline,
    tip_deadline
}

export class TIMERS implements BObject{
    value: enum_TIMERS;

    constructor(value: enum_TIMERS) {
        this.value = value;
    }

    equal(other: TIMERS) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: TIMERS) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof TIMERS)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return 0;
    }

    toString() {
        return enum_TIMERS[this.value].toString();
    }

    static get_blink_deadline () {return new TIMERS(enum_TIMERS.blink_deadline);}
    static get_tip_deadline () {return new TIMERS(enum_TIMERS.tip_deadline);}


}


export default class GenericTimersMC {



    private static _TIMERS: BSet<TIMERS> = new BSet(new TIMERS(enum_TIMERS.blink_deadline), new TIMERS(enum_TIMERS.tip_deadline));

    private curDeadlines: BRelation<TIMERS, BInteger>;

    constructor() {
        this.curDeadlines = new BRelation<TIMERS, BInteger>();
    }

    public _copy(): GenericTimersMC {
        let _instance = Object.create(GenericTimersMC.prototype);
        for(let key of Object.keys(this)) {
            _instance[key] = this[key]._copy?.() ?? this[key];
        }
        return _instance;
    }

     AbsoluteSetDeadline(timer: TIMERS, deadline: BInteger): void {
        this.curDeadlines = this.curDeadlines.override(new BRelation<TIMERS, BInteger>(new BTuple<TIMERS, BInteger>(timer,deadline)));
    }

     AddDeadline(timer: TIMERS, deadline: BInteger): void {
        this.curDeadlines = this.curDeadlines.override(new BRelation<TIMERS, BInteger>(new BTuple<TIMERS, BInteger>(timer,deadline)));
    }

     IncreaseTime(delta: BInteger): void {
        if((new BBoolean(delta.isNatural().booleanValue() && new BBoolean(!this.curDeadlines.unequal(new BRelation<TIMERS, BInteger>()).booleanValue() || delta.lessEqual(this.curDeadlines.range().min()).booleanValue()).booleanValue())).booleanValue()) {
            let _ic_set_0: BRelation<TIMERS, BInteger> = new BRelation<TIMERS, BInteger>();
            for(let _ic_x_1 of this.curDeadlines.domain()) {
                _ic_set_0 = _ic_set_0.union(new BRelation<TIMERS, BInteger>(new BTuple(_ic_x_1, this.curDeadlines.functionCall(_ic_x_1).minus(delta))));

            }
            this.curDeadlines = _ic_set_0;
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     IncreaseTimeUntilDeadline(timer: TIMERS, delta: BInteger): void {
        if((new BBoolean(new BBoolean(new BBoolean(this.curDeadlines.domain().elementOf(timer).booleanValue() && delta.isNatural().booleanValue()).booleanValue() && delta.equal(this.curDeadlines.range().min()).booleanValue()).booleanValue() && delta.equal(this.curDeadlines.functionCall(timer)).booleanValue())).booleanValue()) {
            let _ic_set_1: BRelation<TIMERS, BInteger> = new BRelation<TIMERS, BInteger>();
            for(let _ic_x_1 of this.curDeadlines.domain().difference(new BSet(timer))) {
                _ic_set_1 = _ic_set_1.union(new BRelation<TIMERS, BInteger>(new BTuple(_ic_x_1, this.curDeadlines.functionCall(_ic_x_1).minus(delta))));

            }
            this.curDeadlines = _ic_set_1;
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

     IncreaseTimeUntilCyclicDeadline(timer: TIMERS, delta: BInteger, newDelta: BInteger): void {
        if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.curDeadlines.domain().elementOf(timer).booleanValue() && delta.isNatural().booleanValue()).booleanValue() && newDelta.isNatural().booleanValue()).booleanValue() && delta.equal(this.curDeadlines.functionCall(timer)).booleanValue()).booleanValue() && delta.equal(this.curDeadlines.range().min()).booleanValue())).booleanValue()) {
            let _ic_set_2: BRelation<TIMERS, BInteger> = new BRelation<TIMERS, BInteger>();
            for(let _ic_x_1 of this.curDeadlines.domain().difference(new BSet(timer))) {
                _ic_set_2 = _ic_set_2.union(new BRelation<TIMERS, BInteger>(new BTuple(_ic_x_1, this.curDeadlines.functionCall(_ic_x_1).minus(delta))));

            }
            this.curDeadlines = _ic_set_2.union(new BRelation<TIMERS, BInteger>(new BTuple(timer, newDelta)));
        }  else {
            throw new SelectError("Parameters are invalid!");
        }
    }

    _get_curDeadlines(): BRelation<TIMERS, BInteger> {
        return this.curDeadlines;
    }

    _get__TIMERS(): BSet<TIMERS> {
        return GenericTimersMC._TIMERS;
    }




}

