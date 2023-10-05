import { BTuple } from './btypes/BTuple.js';
import { BInteger } from './btypes/BInteger.js';
import { BBoolean } from './btypes/BBoolean.js';
import { BRelation } from './btypes/BRelation.js';
import { BSet } from './btypes/BSet.js';
export var enum_T1state;
(function (enum_T1state) {
    enum_T1state[enum_T1state["T1_EN"] = 0] = "T1_EN";
    enum_T1state[enum_T1state["T1_CALC"] = 1] = "T1_CALC";
    enum_T1state[enum_T1state["T1_SEND"] = 2] = "T1_SEND";
    enum_T1state[enum_T1state["T1_WAIT"] = 3] = "T1_WAIT";
})(enum_T1state || (enum_T1state = {}));
export class T1state {
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
        if (!(o instanceof T1state)) {
            return false;
        }
        return this.value === o.value;
    }
    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }
    toString() {
        return enum_T1state[this.value].toString();
    }
    static get_T1_EN() { return new T1state(enum_T1state.T1_EN); }
    static get_T1_CALC() { return new T1state(enum_T1state.T1_CALC); }
    static get_T1_SEND() { return new T1state(enum_T1state.T1_SEND); }
    static get_T1_WAIT() { return new T1state(enum_T1state.T1_WAIT); }
}
export var enum_T2mode;
(function (enum_T2mode) {
    enum_T2mode[enum_T2mode["T2MODE_SENSE"] = 0] = "T2MODE_SENSE";
    enum_T2mode[enum_T2mode["T2MODE_TRANSMIT"] = 1] = "T2MODE_TRANSMIT";
    enum_T2mode[enum_T2mode["T2MODE_RELEASE"] = 2] = "T2MODE_RELEASE";
})(enum_T2mode || (enum_T2mode = {}));
export class T2mode {
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
        if (!(o instanceof T2mode)) {
            return false;
        }
        return this.value === o.value;
    }
    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }
    toString() {
        return enum_T2mode[this.value].toString();
    }
    static get_T2MODE_SENSE() { return new T2mode(enum_T2mode.T2MODE_SENSE); }
    static get_T2MODE_TRANSMIT() { return new T2mode(enum_T2mode.T2MODE_TRANSMIT); }
    static get_T2MODE_RELEASE() { return new T2mode(enum_T2mode.T2MODE_RELEASE); }
}
export var enum_T2state;
(function (enum_T2state) {
    enum_T2state[enum_T2state["T2_EN"] = 0] = "T2_EN";
    enum_T2state[enum_T2state["T2_RCV"] = 1] = "T2_RCV";
    enum_T2state[enum_T2state["T2_PROC"] = 2] = "T2_PROC";
    enum_T2state[enum_T2state["T2_CALC"] = 3] = "T2_CALC";
    enum_T2state[enum_T2state["T2_SEND"] = 4] = "T2_SEND";
    enum_T2state[enum_T2state["T2_WAIT"] = 5] = "T2_WAIT";
    enum_T2state[enum_T2state["T2_RELEASE"] = 6] = "T2_RELEASE";
})(enum_T2state || (enum_T2state = {}));
export class T2state {
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
        if (!(o instanceof T2state)) {
            return false;
        }
        return this.value === o.value;
    }
    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }
    toString() {
        return enum_T2state[this.value].toString();
    }
    static get_T2_EN() { return new T2state(enum_T2state.T2_EN); }
    static get_T2_RCV() { return new T2state(enum_T2state.T2_RCV); }
    static get_T2_PROC() { return new T2state(enum_T2state.T2_PROC); }
    static get_T2_CALC() { return new T2state(enum_T2state.T2_CALC); }
    static get_T2_SEND() { return new T2state(enum_T2state.T2_SEND); }
    static get_T2_WAIT() { return new T2state(enum_T2state.T2_WAIT); }
    static get_T2_RELEASE() { return new T2state(enum_T2state.T2_RELEASE); }
}
export var enum_T3state;
(function (enum_T3state) {
    enum_T3state[enum_T3state["T3_READY"] = 0] = "T3_READY";
    enum_T3state[enum_T3state["T3_WRITE"] = 1] = "T3_WRITE";
    enum_T3state[enum_T3state["T3_RELEASE"] = 2] = "T3_RELEASE";
    enum_T3state[enum_T3state["T3_READ"] = 3] = "T3_READ";
    enum_T3state[enum_T3state["T3_PROC"] = 4] = "T3_PROC";
    enum_T3state[enum_T3state["T3_WAIT"] = 5] = "T3_WAIT";
})(enum_T3state || (enum_T3state = {}));
export class T3state {
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
        if (!(o instanceof T3state)) {
            return false;
        }
        return this.value === o.value;
    }
    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }
    toString() {
        return enum_T3state[this.value].toString();
    }
    static get_T3_READY() { return new T3state(enum_T3state.T3_READY); }
    static get_T3_WRITE() { return new T3state(enum_T3state.T3_WRITE); }
    static get_T3_RELEASE() { return new T3state(enum_T3state.T3_RELEASE); }
    static get_T3_READ() { return new T3state(enum_T3state.T3_READ); }
    static get_T3_PROC() { return new T3state(enum_T3state.T3_PROC); }
    static get_T3_WAIT() { return new T3state(enum_T3state.T3_WAIT); }
}
export default class CAN_BUS_tlc {
    constructor() {
        this.T2v = new BInteger(0);
        this.T3_evaluated = new BBoolean(true);
        this.T3_enabled = new BBoolean(true);
        this.T1_state = new T1state(enum_T1state.T1_EN);
        this.T2_state = new T2state(enum_T2state.T2_EN);
        this.T3_state = new T3state(enum_T3state.T3_READY);
        this.T1_writevalue = new BInteger(0);
        this.T2_writevalue = new BInteger(0);
        this.T2_readvalue = new BInteger(0);
        this.T2_readpriority = new BInteger(0);
        this.T3_readvalue = new BInteger(0);
        this.T3_readpriority = new BInteger(0);
        this.T1_timer = new BInteger(2);
        this.T2_timer = new BInteger(3);
        this.BUSwrite = new BRelation(new BTuple(new BInteger(0), new BInteger(0)));
        this.BUSvalue = new BInteger(0);
        this.BUSpriority = new BInteger(0);
        this.T2_mode = new T2mode(enum_T2mode.T2MODE_SENSE);
    }
    T1Evaluate() {
        this.T1_timer = new BInteger(0);
        this.T1_state = new T1state(enum_T1state.T1_CALC);
    }
    T1Calculate(p) {
        this.T1_writevalue = p;
        this.T1_state = new T1state(enum_T1state.T1_SEND);
    }
    T1SendResult(ppriority, pv) {
        let _ld_BUSwrite = this.BUSwrite;
        this.BUSwrite = _ld_BUSwrite.override(new BRelation(new BTuple(ppriority, pv)));
        this.T1_state = new T1state(enum_T1state.T1_WAIT);
    }
    T1Wait(pt) {
        this.T1_timer = pt;
        this.T1_state = new T1state(enum_T1state.T1_EN);
    }
    T2Evaluate() {
        this.T2_timer = new BInteger(0);
        this.T2_state = new T2state(enum_T2state.T2_RCV);
    }
    T2ReadBus(ppriority, pv) {
        this.T2_readvalue = pv;
        this.T2_readpriority = ppriority;
        this.T2_state = new T2state(enum_T2state.T2_PROC);
    }
    T2Reset() {
        let _ld_T2v = this.T2v;
        this.T2_writevalue = _ld_T2v;
        this.T2v = new BInteger(0);
        this.T2_state = new T2state(enum_T2state.T2_SEND);
        this.T2_mode = new T2mode(enum_T2mode.T2MODE_TRANSMIT);
    }
    T2Complete() {
        this.T2_state = new T2state(enum_T2state.T2_RELEASE);
        this.T2_mode = new T2mode(enum_T2mode.T2MODE_SENSE);
    }
    T2ReleaseBus(ppriority) {
        let _ld_BUSwrite = this.BUSwrite;
        this.BUSwrite = _ld_BUSwrite.domainSubstraction(new BSet(ppriority));
        this.T2_state = new T2state(enum_T2state.T2_WAIT);
    }
    T2Calculate() {
        this.T2v = this.T2_readvalue;
        this.T2_state = new T2state(enum_T2state.T2_WAIT);
    }
    T2WriteBus(ppriority, pv) {
        let _ld_BUSwrite = this.BUSwrite;
        this.BUSwrite = _ld_BUSwrite.override(new BRelation(new BTuple(ppriority, pv)));
        this.T2_state = new T2state(enum_T2state.T2_WAIT);
    }
    T2Wait(pt) {
        this.T2_timer = pt;
        this.T2_state = new T2state(enum_T2state.T2_EN);
    }
    T3Initiate() {
        this.T3_state = new T3state(enum_T3state.T3_WRITE);
        this.T3_enabled = new BBoolean(false);
    }
    T3Evaluate() {
        this.T3_state = new T3state(enum_T3state.T3_READ);
    }
    T3writebus(ppriority, pv) {
        let _ld_BUSwrite = this.BUSwrite;
        this.BUSwrite = _ld_BUSwrite.override(new BRelation(new BTuple(ppriority, pv)));
        this.T3_state = new T3state(enum_T3state.T3_WAIT);
    }
    T3Read(ppriority, pv) {
        this.T3_readvalue = pv;
        this.T3_readpriority = ppriority;
        this.T3_state = new T3state(enum_T3state.T3_PROC);
    }
    T3Poll() {
        this.T3_state = new T3state(enum_T3state.T3_WAIT);
    }
    T3ReleaseBus(ppriority) {
        let _ld_BUSwrite = this.BUSwrite;
        this.BUSwrite = _ld_BUSwrite.domainSubstraction(new BSet(ppriority));
        this.T3_state = new T3state(enum_T3state.T3_RELEASE);
    }
    T3Wait() {
        this.T3_state = new T3state(enum_T3state.T3_READY);
        this.T3_evaluated = new BBoolean(true);
    }
    T3ReEnableWait() {
        this.T3_state = new T3state(enum_T3state.T3_READY);
        this.T3_evaluated = new BBoolean(true);
        this.T3_enabled = new BBoolean(true);
    }
    Update(pmax) {
        let _ld_T2_timer = this.T2_timer;
        let _ld_T1_timer = this.T1_timer;
        this.BUSvalue = this.BUSwrite.functionCall(pmax);
        this.BUSpriority = pmax;
        this.T1_timer = _ld_T1_timer.minus(new BInteger(1));
        this.T2_timer = _ld_T2_timer.minus(new BInteger(1));
        this.T3_evaluated = new BBoolean(false);
    }
    _get_NATSET() {
        return CAN_BUS_tlc.NATSET;
    }
    _get_BUSpriority() {
        return this.BUSpriority;
    }
    _get_BUSvalue() {
        return this.BUSvalue;
    }
    _get_BUSwrite() {
        return this.BUSwrite;
    }
    _get_T1_state() {
        return this.T1_state;
    }
    _get_T1_timer() {
        return this.T1_timer;
    }
    _get_T1_writevalue() {
        return this.T1_writevalue;
    }
    _get_T2_mode() {
        return this.T2_mode;
    }
    _get_T2_readpriority() {
        return this.T2_readpriority;
    }
    _get_T2_readvalue() {
        return this.T2_readvalue;
    }
    _get_T2_state() {
        return this.T2_state;
    }
    _get_T2_timer() {
        return this.T2_timer;
    }
    _get_T2_writevalue() {
        return this.T2_writevalue;
    }
    _get_T2v() {
        return this.T2v;
    }
    _get_T3_enabled() {
        return this.T3_enabled;
    }
    _get_T3_evaluated() {
        return this.T3_evaluated;
    }
    _get_T3_readpriority() {
        return this.T3_readpriority;
    }
    _get_T3_readvalue() {
        return this.T3_readvalue;
    }
    _get_T3_state() {
        return this.T3_state;
    }
    _get__T1state() {
        return CAN_BUS_tlc._T1state;
    }
    _get__T2mode() {
        return CAN_BUS_tlc._T2mode;
    }
    _get__T2state() {
        return CAN_BUS_tlc._T2state;
    }
    _get__T3state() {
        return CAN_BUS_tlc._T3state;
    }
}
CAN_BUS_tlc._T1state = new BSet(new T1state(enum_T1state.T1_EN), new T1state(enum_T1state.T1_CALC), new T1state(enum_T1state.T1_SEND), new T1state(enum_T1state.T1_WAIT));
CAN_BUS_tlc._T2mode = new BSet(new T2mode(enum_T2mode.T2MODE_SENSE), new T2mode(enum_T2mode.T2MODE_TRANSMIT), new T2mode(enum_T2mode.T2MODE_RELEASE));
CAN_BUS_tlc._T2state = new BSet(new T2state(enum_T2state.T2_EN), new T2state(enum_T2state.T2_RCV), new T2state(enum_T2state.T2_PROC), new T2state(enum_T2state.T2_CALC), new T2state(enum_T2state.T2_SEND), new T2state(enum_T2state.T2_WAIT), new T2state(enum_T2state.T2_RELEASE));
CAN_BUS_tlc._T3state = new BSet(new T3state(enum_T3state.T3_READY), new T3state(enum_T3state.T3_WRITE), new T3state(enum_T3state.T3_RELEASE), new T3state(enum_T3state.T3_READ), new T3state(enum_T3state.T3_PROC), new T3state(enum_T3state.T3_WAIT));
(() => {
    CAN_BUS_tlc.NATSET = BSet.interval(new BInteger(0), new BInteger(5));
})();
