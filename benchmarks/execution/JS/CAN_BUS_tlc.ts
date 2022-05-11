import {BTuple} from './btypes/BTuple.js';
import {BInteger} from './btypes/BInteger.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BRelation} from './btypes/BRelation.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BUtils} from "./btypes/BUtils.js";

export enum enum_T1state {
    T1_EN,
    T1_CALC,
    T1_SEND,
    T1_WAIT
}

export class T1state implements BObject{
    value: enum_T1state;

    constructor(value: enum_T1state) {
        this.value = value;
    }

    equal(other: T1state) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: T1state) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof T1state)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return 0;
    }

    toString() {
        return enum_T1state[this.value].toString();
    }

    static get_T1_EN () {return new T1state(enum_T1state.T1_EN);}
    static get_T1_CALC () {return new T1state(enum_T1state.T1_CALC);}
    static get_T1_SEND () {return new T1state(enum_T1state.T1_SEND);}
    static get_T1_WAIT () {return new T1state(enum_T1state.T1_WAIT);}


}

export enum enum_T2mode {
    T2MODE_SENSE,
    T2MODE_TRANSMIT,
    T2MODE_RELEASE
}

export class T2mode implements BObject{
    value: enum_T2mode;

    constructor(value: enum_T2mode) {
        this.value = value;
    }

    equal(other: T2mode) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: T2mode) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof T2mode)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return 0;
    }

    toString() {
        return enum_T2mode[this.value].toString();
    }

    static get_T2MODE_SENSE () {return new T2mode(enum_T2mode.T2MODE_SENSE);}
    static get_T2MODE_TRANSMIT () {return new T2mode(enum_T2mode.T2MODE_TRANSMIT);}
    static get_T2MODE_RELEASE () {return new T2mode(enum_T2mode.T2MODE_RELEASE);}


}

export enum enum_T2state {
    T2_EN,
    T2_RCV,
    T2_PROC,
    T2_CALC,
    T2_SEND,
    T2_WAIT,
    T2_RELEASE
}

export class T2state implements BObject{
    value: enum_T2state;

    constructor(value: enum_T2state) {
        this.value = value;
    }

    equal(other: T2state) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: T2state) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof T2state)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return 0;
    }

    toString() {
        return enum_T2state[this.value].toString();
    }

    static get_T2_EN () {return new T2state(enum_T2state.T2_EN);}
    static get_T2_RCV () {return new T2state(enum_T2state.T2_RCV);}
    static get_T2_PROC () {return new T2state(enum_T2state.T2_PROC);}
    static get_T2_CALC () {return new T2state(enum_T2state.T2_CALC);}
    static get_T2_SEND () {return new T2state(enum_T2state.T2_SEND);}
    static get_T2_WAIT () {return new T2state(enum_T2state.T2_WAIT);}
    static get_T2_RELEASE () {return new T2state(enum_T2state.T2_RELEASE);}


}

export enum enum_T3state {
    T3_READY,
    T3_WRITE,
    T3_RELEASE,
    T3_READ,
    T3_PROC,
    T3_WAIT
}

export class T3state implements BObject{
    value: enum_T3state;

    constructor(value: enum_T3state) {
        this.value = value;
    }

    equal(other: T3state) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: T3state) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof T3state)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return 0;
    }

    toString() {
        return enum_T3state[this.value].toString();
    }

    static get_T3_READY () {return new T3state(enum_T3state.T3_READY);}
    static get_T3_WRITE () {return new T3state(enum_T3state.T3_WRITE);}
    static get_T3_RELEASE () {return new T3state(enum_T3state.T3_RELEASE);}
    static get_T3_READ () {return new T3state(enum_T3state.T3_READ);}
    static get_T3_PROC () {return new T3state(enum_T3state.T3_PROC);}
    static get_T3_WAIT () {return new T3state(enum_T3state.T3_WAIT);}


}


export default class CAN_BUS_tlc {


    private static NATSET: BSet<BInteger>;

    private static _T1state: BSet<T1state> = new BSet(new T1state(enum_T1state.T1_EN), new T1state(enum_T1state.T1_CALC), new T1state(enum_T1state.T1_SEND), new T1state(enum_T1state.T1_WAIT));
    private static _T2mode: BSet<T2mode> = new BSet(new T2mode(enum_T2mode.T2MODE_SENSE), new T2mode(enum_T2mode.T2MODE_TRANSMIT), new T2mode(enum_T2mode.T2MODE_RELEASE));
    private static _T2state: BSet<T2state> = new BSet(new T2state(enum_T2state.T2_EN), new T2state(enum_T2state.T2_RCV), new T2state(enum_T2state.T2_PROC), new T2state(enum_T2state.T2_CALC), new T2state(enum_T2state.T2_SEND), new T2state(enum_T2state.T2_WAIT), new T2state(enum_T2state.T2_RELEASE));
    private static _T3state: BSet<T3state> = new BSet(new T3state(enum_T3state.T3_READY), new T3state(enum_T3state.T3_WRITE), new T3state(enum_T3state.T3_RELEASE), new T3state(enum_T3state.T3_READ), new T3state(enum_T3state.T3_PROC), new T3state(enum_T3state.T3_WAIT));

    private BUSpriority: BInteger;
    private BUSvalue: BInteger;
    private BUSwrite: BRelation<BInteger, BInteger>;
    private T1_state: T1state;
    private T1_timer: BInteger;
    private T1_writevalue: BInteger;
    private T2_mode: T2mode;
    private T2_readpriority: BInteger;
    private T2_readvalue: BInteger;
    private T2_state: T2state;
    private T2_timer: BInteger;
    private T2_writevalue: BInteger;
    private T2v: BInteger;
    private T3_enabled: BBoolean;
    private T3_evaluated: BBoolean;
    private T3_readpriority: BInteger;
    private T3_readvalue: BInteger;
    private T3_state: T3state;

    constructor() {
        CAN_BUS_tlc.NATSET = BSet.interval(new BInteger(0), new BInteger(5));
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
        this.BUSwrite = new BRelation<BInteger, BInteger>(new BTuple(new BInteger(0), new BInteger(0)));
        this.BUSvalue = new BInteger(0);
        this.BUSpriority = new BInteger(0);
        this.T2_mode = new T2mode(enum_T2mode.T2MODE_SENSE);
    }

     T1Evaluate(): void {
        this.T1_timer = new BInteger(0);
        this.T1_state = new T1state(enum_T1state.T1_CALC);
    }

     T1Calculate(p: BInteger): void {
        this.T1_writevalue = p;
        this.T1_state = new T1state(enum_T1state.T1_SEND);
    }

     T1SendResult(ppriority: BInteger, pv: BInteger): void {
        let _ld_BUSwrite: BRelation<BInteger, BInteger> = this.BUSwrite;
        this.BUSwrite = _ld_BUSwrite.override(new BRelation<BInteger, BInteger>(new BTuple(ppriority, pv)));
        this.T1_state = new T1state(enum_T1state.T1_WAIT);
    }

     T1Wait(pt: BInteger): void {
        this.T1_timer = pt;
        this.T1_state = new T1state(enum_T1state.T1_EN);
    }

     T2Evaluate(): void {
        this.T2_timer = new BInteger(0);
        this.T2_state = new T2state(enum_T2state.T2_RCV);
    }

     T2ReadBus(ppriority: BInteger, pv: BInteger): void {
        this.T2_readvalue = pv;
        this.T2_readpriority = ppriority;
        this.T2_state = new T2state(enum_T2state.T2_PROC);
    }

     T2Reset(): void {
        let _ld_T2v: BInteger = this.T2v;
        this.T2_writevalue = _ld_T2v;
        this.T2v = new BInteger(0);
        this.T2_state = new T2state(enum_T2state.T2_SEND);
        this.T2_mode = new T2mode(enum_T2mode.T2MODE_TRANSMIT);
    }

     T2Complete(): void {
        this.T2_state = new T2state(enum_T2state.T2_RELEASE);
        this.T2_mode = new T2mode(enum_T2mode.T2MODE_SENSE);
    }

     T2ReleaseBus(ppriority: BInteger): void {
        let _ld_BUSwrite: BRelation<BInteger, BInteger> = this.BUSwrite;
        this.BUSwrite = _ld_BUSwrite.domainSubstraction(new BSet(ppriority));
        this.T2_state = new T2state(enum_T2state.T2_WAIT);
    }

     T2Calculate(): void {
        this.T2v = this.T2_readvalue;
        this.T2_state = new T2state(enum_T2state.T2_WAIT);
    }

     T2WriteBus(ppriority: BInteger, pv: BInteger): void {
        let _ld_BUSwrite: BRelation<BInteger, BInteger> = this.BUSwrite;
        this.BUSwrite = _ld_BUSwrite.override(new BRelation<BInteger, BInteger>(new BTuple(ppriority, pv)));
        this.T2_state = new T2state(enum_T2state.T2_WAIT);
    }

     T2Wait(pt: BInteger): void {
        this.T2_timer = pt;
        this.T2_state = new T2state(enum_T2state.T2_EN);
    }

     T3Initiate(): void {
        this.T3_state = new T3state(enum_T3state.T3_WRITE);
        this.T3_enabled = new BBoolean(false);
    }

     T3Evaluate(): void {
        this.T3_state = new T3state(enum_T3state.T3_READ);
    }

     T3writebus(ppriority: BInteger, pv: BInteger): void {
        let _ld_BUSwrite: BRelation<BInteger, BInteger> = this.BUSwrite;
        this.BUSwrite = _ld_BUSwrite.override(new BRelation<BInteger, BInteger>(new BTuple(ppriority, pv)));
        this.T3_state = new T3state(enum_T3state.T3_WAIT);
    }

     T3Read(ppriority: BInteger, pv: BInteger): void {
        this.T3_readvalue = pv;
        this.T3_readpriority = ppriority;
        this.T3_state = new T3state(enum_T3state.T3_PROC);
    }

     T3Poll(): void {
        this.T3_state = new T3state(enum_T3state.T3_WAIT);
    }

     T3ReleaseBus(ppriority: BInteger): void {
        let _ld_BUSwrite: BRelation<BInteger, BInteger> = this.BUSwrite;
        this.BUSwrite = _ld_BUSwrite.domainSubstraction(new BSet(ppriority));
        this.T3_state = new T3state(enum_T3state.T3_RELEASE);
    }

     T3Wait(): void {
        this.T3_state = new T3state(enum_T3state.T3_READY);
        this.T3_evaluated = new BBoolean(true);
    }

     T3ReEnableWait(): void {
        this.T3_state = new T3state(enum_T3state.T3_READY);
        this.T3_evaluated = new BBoolean(true);
        this.T3_enabled = new BBoolean(true);
    }

     Update(pmax: BInteger): void {
        let _ld_T2_timer: BInteger = this.T2_timer;
        let _ld_T1_timer: BInteger = this.T1_timer;
        this.BUSvalue = this.BUSwrite.functionCall(pmax);
        this.BUSpriority = pmax;
        this.T1_timer = _ld_T1_timer.minus(new BInteger(1));
        this.T2_timer = _ld_T2_timer.minus(new BInteger(1));
        this.T3_evaluated = new BBoolean(false);
    }

    _get_NATSET(): BSet<BInteger> {
        return CAN_BUS_tlc.NATSET;
    }

    _get_BUSpriority(): BInteger {
        return this.BUSpriority;
    }

    _get_BUSvalue(): BInteger {
        return this.BUSvalue;
    }

    _get_BUSwrite(): BRelation<BInteger, BInteger> {
        return this.BUSwrite;
    }

    _get_T1_state(): T1state {
        return this.T1_state;
    }

    _get_T1_timer(): BInteger {
        return this.T1_timer;
    }

    _get_T1_writevalue(): BInteger {
        return this.T1_writevalue;
    }

    _get_T2_mode(): T2mode {
        return this.T2_mode;
    }

    _get_T2_readpriority(): BInteger {
        return this.T2_readpriority;
    }

    _get_T2_readvalue(): BInteger {
        return this.T2_readvalue;
    }

    _get_T2_state(): T2state {
        return this.T2_state;
    }

    _get_T2_timer(): BInteger {
        return this.T2_timer;
    }

    _get_T2_writevalue(): BInteger {
        return this.T2_writevalue;
    }

    _get_T2v(): BInteger {
        return this.T2v;
    }

    _get_T3_enabled(): BBoolean {
        return this.T3_enabled;
    }

    _get_T3_evaluated(): BBoolean {
        return this.T3_evaluated;
    }

    _get_T3_readpriority(): BInteger {
        return this.T3_readpriority;
    }

    _get_T3_readvalue(): BInteger {
        return this.T3_readvalue;
    }

    _get_T3_state(): T3state {
        return this.T3_state;
    }

    _get__T1state(): BSet<T1state> {
        return CAN_BUS_tlc._T1state;
    }

    _get__T2mode(): BSet<T2mode> {
        return CAN_BUS_tlc._T2mode;
    }

    _get__T2state(): BSet<T2state> {
        return CAN_BUS_tlc._T2state;
    }

    _get__T3state(): BSet<T3state> {
        return CAN_BUS_tlc._T3state;
    }


}

