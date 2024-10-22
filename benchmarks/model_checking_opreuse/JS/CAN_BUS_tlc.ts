import {BTuple} from './btypes/BTuple.js';
import {BInteger} from './btypes/BInteger.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BRelation} from './btypes/BRelation.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";
import {VariantViolation} from "./btypes/BUtils.js";
import {LoopInvariantViolation} from "./btypes/BUtils.js";
import * as immutable from "./immutable/dist/immutable.es.js";
import {LinkedList} from  "./modelchecking/LinkedList.js";


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
        return (31 * 1) ^ (this.value << 1);
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
        return (31 * 1) ^ (this.value << 1);
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
        return (31 * 1) ^ (this.value << 1);
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
        return (31 * 1) ^ (this.value << 1);
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


class _ProjectionRead_T1Evaluate {

    public T1_state: T1state;
    public T1_timer: BInteger;

    constructor(T1_state : T1state, T1_timer : BInteger) {
        this.T1_state = T1_state;
        this.T1_timer = T1_timer;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_T1Evaluate = this;
        let o2: _ProjectionRead_T1Evaluate = other as _ProjectionRead_T1Evaluate;
        return o1.T1_state.equals(o2.T1_state) && o1.T1_timer.equals(o2.T1_timer);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T1_state.hashCode() << 1);
        result = 31 * result + (this.T1_timer.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_T1Evaluate {

    public T1_state: T1state;
    public T1_timer: BInteger;

    constructor(T1_state : T1state, T1_timer : BInteger) {
        this.T1_state = T1_state;
        this.T1_timer = T1_timer;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_T1Evaluate = this;
        let o2: _ProjectionRead__tr_T1Evaluate = other as _ProjectionRead__tr_T1Evaluate;
        return o1.T1_state.equals(o2.T1_state) && o1.T1_timer.equals(o2.T1_timer);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T1_state.hashCode() << 1);
        result = 31 * result + (this.T1_timer.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_T1Evaluate {

    public T1_state: T1state;
    public T1_timer: BInteger;

    constructor(T1_state : T1state, T1_timer : BInteger) {
        this.T1_state = T1_state;
        this.T1_timer = T1_timer;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_T1Evaluate = this;
        let o2: _ProjectionWrite_T1Evaluate = other as _ProjectionWrite_T1Evaluate;
        return o1.T1_state.equals(o2.T1_state) && o1.T1_timer.equals(o2.T1_timer);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T1_state.hashCode() << 1);
        result = 31 * result + (this.T1_timer.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_T1Calculate {

    public T1_state: T1state;

    constructor(T1_state : T1state) {
        this.T1_state = T1_state;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_T1Calculate = this;
        let o2: _ProjectionRead_T1Calculate = other as _ProjectionRead_T1Calculate;
        return o1.T1_state.equals(o2.T1_state);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T1_state.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_T1Calculate {

    public T1_state: T1state;

    constructor(T1_state : T1state) {
        this.T1_state = T1_state;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_T1Calculate = this;
        let o2: _ProjectionRead__tr_T1Calculate = other as _ProjectionRead__tr_T1Calculate;
        return o1.T1_state.equals(o2.T1_state);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T1_state.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_T1Calculate {

    public T1_state: T1state;
    public T1_writevalue: BInteger;

    constructor(T1_state : T1state, T1_writevalue : BInteger) {
        this.T1_state = T1_state;
        this.T1_writevalue = T1_writevalue;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_T1Calculate = this;
        let o2: _ProjectionWrite_T1Calculate = other as _ProjectionWrite_T1Calculate;
        return o1.T1_state.equals(o2.T1_state) && o1.T1_writevalue.equals(o2.T1_writevalue);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T1_state.hashCode() << 1);
        result = 31 * result + (this.T1_writevalue.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_T1SendResult {

    public T1_state: T1state;
    public T1_writevalue: BInteger;
    public BUSwrite: BRelation<BInteger, BInteger>;

    constructor(T1_state : T1state, T1_writevalue : BInteger, BUSwrite : BRelation<BInteger, BInteger>) {
        this.T1_state = T1_state;
        this.T1_writevalue = T1_writevalue;
        this.BUSwrite = BUSwrite;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_T1SendResult = this;
        let o2: _ProjectionRead_T1SendResult = other as _ProjectionRead_T1SendResult;
        return o1.T1_state.equals(o2.T1_state) && o1.T1_writevalue.equals(o2.T1_writevalue) && o1.BUSwrite.equals(o2.BUSwrite);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T1_state.hashCode() << 1);
        result = 31 * result + (this.T1_writevalue.hashCode() << 1);
        result = 31 * result + (this.BUSwrite.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_T1SendResult {

    public T1_state: T1state;
    public T1_writevalue: BInteger;

    constructor(T1_state : T1state, T1_writevalue : BInteger) {
        this.T1_state = T1_state;
        this.T1_writevalue = T1_writevalue;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_T1SendResult = this;
        let o2: _ProjectionRead__tr_T1SendResult = other as _ProjectionRead__tr_T1SendResult;
        return o1.T1_state.equals(o2.T1_state) && o1.T1_writevalue.equals(o2.T1_writevalue);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T1_state.hashCode() << 1);
        result = 31 * result + (this.T1_writevalue.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_T1SendResult {

    public T1_state: T1state;
    public BUSwrite: BRelation<BInteger, BInteger>;

    constructor(T1_state : T1state, BUSwrite : BRelation<BInteger, BInteger>) {
        this.T1_state = T1_state;
        this.BUSwrite = BUSwrite;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_T1SendResult = this;
        let o2: _ProjectionWrite_T1SendResult = other as _ProjectionWrite_T1SendResult;
        return o1.T1_state.equals(o2.T1_state) && o1.BUSwrite.equals(o2.BUSwrite);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T1_state.hashCode() << 1);
        result = 31 * result + (this.BUSwrite.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_T1Wait {

    public T1_state: T1state;

    constructor(T1_state : T1state) {
        this.T1_state = T1_state;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_T1Wait = this;
        let o2: _ProjectionRead_T1Wait = other as _ProjectionRead_T1Wait;
        return o1.T1_state.equals(o2.T1_state);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T1_state.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_T1Wait {

    public T1_state: T1state;

    constructor(T1_state : T1state) {
        this.T1_state = T1_state;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_T1Wait = this;
        let o2: _ProjectionRead__tr_T1Wait = other as _ProjectionRead__tr_T1Wait;
        return o1.T1_state.equals(o2.T1_state);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T1_state.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_T1Wait {

    public T1_state: T1state;
    public T1_timer: BInteger;

    constructor(T1_state : T1state, T1_timer : BInteger) {
        this.T1_state = T1_state;
        this.T1_timer = T1_timer;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_T1Wait = this;
        let o2: _ProjectionWrite_T1Wait = other as _ProjectionWrite_T1Wait;
        return o1.T1_state.equals(o2.T1_state) && o1.T1_timer.equals(o2.T1_timer);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T1_state.hashCode() << 1);
        result = 31 * result + (this.T1_timer.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_T2Evaluate {

    public T2_state: T2state;
    public T2_timer: BInteger;

    constructor(T2_state : T2state, T2_timer : BInteger) {
        this.T2_state = T2_state;
        this.T2_timer = T2_timer;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_T2Evaluate = this;
        let o2: _ProjectionRead_T2Evaluate = other as _ProjectionRead_T2Evaluate;
        return o1.T2_state.equals(o2.T2_state) && o1.T2_timer.equals(o2.T2_timer);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.T2_timer.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_T2Evaluate {

    public T2_state: T2state;
    public T2_timer: BInteger;

    constructor(T2_state : T2state, T2_timer : BInteger) {
        this.T2_state = T2_state;
        this.T2_timer = T2_timer;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_T2Evaluate = this;
        let o2: _ProjectionRead__tr_T2Evaluate = other as _ProjectionRead__tr_T2Evaluate;
        return o1.T2_state.equals(o2.T2_state) && o1.T2_timer.equals(o2.T2_timer);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.T2_timer.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_T2Evaluate {

    public T2_state: T2state;
    public T2_timer: BInteger;

    constructor(T2_state : T2state, T2_timer : BInteger) {
        this.T2_state = T2_state;
        this.T2_timer = T2_timer;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_T2Evaluate = this;
        let o2: _ProjectionWrite_T2Evaluate = other as _ProjectionWrite_T2Evaluate;
        return o1.T2_state.equals(o2.T2_state) && o1.T2_timer.equals(o2.T2_timer);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.T2_timer.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_T2ReadBus {

    public T2_state: T2state;
    public BUSpriority: BInteger;
    public BUSvalue: BInteger;

    constructor(T2_state : T2state, BUSpriority : BInteger, BUSvalue : BInteger) {
        this.T2_state = T2_state;
        this.BUSpriority = BUSpriority;
        this.BUSvalue = BUSvalue;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_T2ReadBus = this;
        let o2: _ProjectionRead_T2ReadBus = other as _ProjectionRead_T2ReadBus;
        return o1.T2_state.equals(o2.T2_state) && o1.BUSpriority.equals(o2.BUSpriority) && o1.BUSvalue.equals(o2.BUSvalue);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.BUSpriority.hashCode() << 1);
        result = 31 * result + (this.BUSvalue.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_T2ReadBus {

    public T2_state: T2state;
    public BUSpriority: BInteger;
    public BUSvalue: BInteger;

    constructor(T2_state : T2state, BUSpriority : BInteger, BUSvalue : BInteger) {
        this.T2_state = T2_state;
        this.BUSpriority = BUSpriority;
        this.BUSvalue = BUSvalue;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_T2ReadBus = this;
        let o2: _ProjectionRead__tr_T2ReadBus = other as _ProjectionRead__tr_T2ReadBus;
        return o1.T2_state.equals(o2.T2_state) && o1.BUSpriority.equals(o2.BUSpriority) && o1.BUSvalue.equals(o2.BUSvalue);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.BUSpriority.hashCode() << 1);
        result = 31 * result + (this.BUSvalue.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_T2ReadBus {

    public T2_state: T2state;
    public T2_readpriority: BInteger;
    public T2_readvalue: BInteger;

    constructor(T2_state : T2state, T2_readpriority : BInteger, T2_readvalue : BInteger) {
        this.T2_state = T2_state;
        this.T2_readpriority = T2_readpriority;
        this.T2_readvalue = T2_readvalue;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_T2ReadBus = this;
        let o2: _ProjectionWrite_T2ReadBus = other as _ProjectionWrite_T2ReadBus;
        return o1.T2_state.equals(o2.T2_state) && o1.T2_readpriority.equals(o2.T2_readpriority) && o1.T2_readvalue.equals(o2.T2_readvalue);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.T2_readpriority.hashCode() << 1);
        result = 31 * result + (this.T2_readvalue.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_T2Reset {

    public T2_state: T2state;
    public T2_readpriority: BInteger;
    public T2v: BInteger;

    constructor(T2_state : T2state, T2_readpriority : BInteger, T2v : BInteger) {
        this.T2_state = T2_state;
        this.T2_readpriority = T2_readpriority;
        this.T2v = T2v;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_T2Reset = this;
        let o2: _ProjectionRead_T2Reset = other as _ProjectionRead_T2Reset;
        return o1.T2_state.equals(o2.T2_state) && o1.T2_readpriority.equals(o2.T2_readpriority) && o1.T2v.equals(o2.T2v);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.T2_readpriority.hashCode() << 1);
        result = 31 * result + (this.T2v.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_T2Reset {

    public T2_state: T2state;
    public T2_readpriority: BInteger;

    constructor(T2_state : T2state, T2_readpriority : BInteger) {
        this.T2_state = T2_state;
        this.T2_readpriority = T2_readpriority;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_T2Reset = this;
        let o2: _ProjectionRead__tr_T2Reset = other as _ProjectionRead__tr_T2Reset;
        return o1.T2_state.equals(o2.T2_state) && o1.T2_readpriority.equals(o2.T2_readpriority);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.T2_readpriority.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_T2Reset {

    public T2_state: T2state;
    public T2_writevalue: BInteger;
    public T2v: BInteger;
    public T2_mode: T2mode;

    constructor(T2_state : T2state, T2_writevalue : BInteger, T2v : BInteger, T2_mode : T2mode) {
        this.T2_state = T2_state;
        this.T2_writevalue = T2_writevalue;
        this.T2v = T2v;
        this.T2_mode = T2_mode;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_T2Reset = this;
        let o2: _ProjectionWrite_T2Reset = other as _ProjectionWrite_T2Reset;
        return o1.T2_state.equals(o2.T2_state) && o1.T2_writevalue.equals(o2.T2_writevalue) && o1.T2v.equals(o2.T2v) && o1.T2_mode.equals(o2.T2_mode);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.T2_writevalue.hashCode() << 1);
        result = 31 * result + (this.T2v.hashCode() << 1);
        result = 31 * result + (this.T2_mode.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_T2Complete {

    public T2_state: T2state;
    public T2_readpriority: BInteger;
    public T2_mode: T2mode;

    constructor(T2_state : T2state, T2_readpriority : BInteger, T2_mode : T2mode) {
        this.T2_state = T2_state;
        this.T2_readpriority = T2_readpriority;
        this.T2_mode = T2_mode;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_T2Complete = this;
        let o2: _ProjectionRead_T2Complete = other as _ProjectionRead_T2Complete;
        return o1.T2_state.equals(o2.T2_state) && o1.T2_readpriority.equals(o2.T2_readpriority) && o1.T2_mode.equals(o2.T2_mode);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.T2_readpriority.hashCode() << 1);
        result = 31 * result + (this.T2_mode.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_T2Complete {

    public T2_state: T2state;
    public T2_readpriority: BInteger;
    public T2_mode: T2mode;

    constructor(T2_state : T2state, T2_readpriority : BInteger, T2_mode : T2mode) {
        this.T2_state = T2_state;
        this.T2_readpriority = T2_readpriority;
        this.T2_mode = T2_mode;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_T2Complete = this;
        let o2: _ProjectionRead__tr_T2Complete = other as _ProjectionRead__tr_T2Complete;
        return o1.T2_state.equals(o2.T2_state) && o1.T2_readpriority.equals(o2.T2_readpriority) && o1.T2_mode.equals(o2.T2_mode);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.T2_readpriority.hashCode() << 1);
        result = 31 * result + (this.T2_mode.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_T2Complete {

    public T2_state: T2state;
    public T2_mode: T2mode;

    constructor(T2_state : T2state, T2_mode : T2mode) {
        this.T2_state = T2_state;
        this.T2_mode = T2_mode;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_T2Complete = this;
        let o2: _ProjectionWrite_T2Complete = other as _ProjectionWrite_T2Complete;
        return o1.T2_state.equals(o2.T2_state) && o1.T2_mode.equals(o2.T2_mode);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.T2_mode.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_T2ReleaseBus {

    public T2_state: T2state;
    public T2_readpriority: BInteger;
    public BUSwrite: BRelation<BInteger, BInteger>;

    constructor(T2_state : T2state, T2_readpriority : BInteger, BUSwrite : BRelation<BInteger, BInteger>) {
        this.T2_state = T2_state;
        this.T2_readpriority = T2_readpriority;
        this.BUSwrite = BUSwrite;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_T2ReleaseBus = this;
        let o2: _ProjectionRead_T2ReleaseBus = other as _ProjectionRead_T2ReleaseBus;
        return o1.T2_state.equals(o2.T2_state) && o1.T2_readpriority.equals(o2.T2_readpriority) && o1.BUSwrite.equals(o2.BUSwrite);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.T2_readpriority.hashCode() << 1);
        result = 31 * result + (this.BUSwrite.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_T2ReleaseBus {

    public T2_state: T2state;
    public T2_readpriority: BInteger;
    public BUSwrite: BRelation<BInteger, BInteger>;

    constructor(T2_state : T2state, T2_readpriority : BInteger, BUSwrite : BRelation<BInteger, BInteger>) {
        this.T2_state = T2_state;
        this.T2_readpriority = T2_readpriority;
        this.BUSwrite = BUSwrite;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_T2ReleaseBus = this;
        let o2: _ProjectionRead__tr_T2ReleaseBus = other as _ProjectionRead__tr_T2ReleaseBus;
        return o1.T2_state.equals(o2.T2_state) && o1.T2_readpriority.equals(o2.T2_readpriority) && o1.BUSwrite.equals(o2.BUSwrite);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.T2_readpriority.hashCode() << 1);
        result = 31 * result + (this.BUSwrite.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_T2ReleaseBus {

    public T2_state: T2state;
    public BUSwrite: BRelation<BInteger, BInteger>;

    constructor(T2_state : T2state, BUSwrite : BRelation<BInteger, BInteger>) {
        this.T2_state = T2_state;
        this.BUSwrite = BUSwrite;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_T2ReleaseBus = this;
        let o2: _ProjectionWrite_T2ReleaseBus = other as _ProjectionWrite_T2ReleaseBus;
        return o1.T2_state.equals(o2.T2_state) && o1.BUSwrite.equals(o2.BUSwrite);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.BUSwrite.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_T2Calculate {

    public T2_state: T2state;
    public T2_readpriority: BInteger;
    public T2_readvalue: BInteger;

    constructor(T2_state : T2state, T2_readpriority : BInteger, T2_readvalue : BInteger) {
        this.T2_state = T2_state;
        this.T2_readpriority = T2_readpriority;
        this.T2_readvalue = T2_readvalue;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_T2Calculate = this;
        let o2: _ProjectionRead_T2Calculate = other as _ProjectionRead_T2Calculate;
        return o1.T2_state.equals(o2.T2_state) && o1.T2_readpriority.equals(o2.T2_readpriority) && o1.T2_readvalue.equals(o2.T2_readvalue);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.T2_readpriority.hashCode() << 1);
        result = 31 * result + (this.T2_readvalue.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_T2Calculate {

    public T2_state: T2state;
    public T2_readpriority: BInteger;

    constructor(T2_state : T2state, T2_readpriority : BInteger) {
        this.T2_state = T2_state;
        this.T2_readpriority = T2_readpriority;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_T2Calculate = this;
        let o2: _ProjectionRead__tr_T2Calculate = other as _ProjectionRead__tr_T2Calculate;
        return o1.T2_state.equals(o2.T2_state) && o1.T2_readpriority.equals(o2.T2_readpriority);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.T2_readpriority.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_T2Calculate {

    public T2_state: T2state;
    public T2v: BInteger;

    constructor(T2_state : T2state, T2v : BInteger) {
        this.T2_state = T2_state;
        this.T2v = T2v;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_T2Calculate = this;
        let o2: _ProjectionWrite_T2Calculate = other as _ProjectionWrite_T2Calculate;
        return o1.T2_state.equals(o2.T2_state) && o1.T2v.equals(o2.T2v);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.T2v.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_T2WriteBus {

    public T2_state: T2state;
    public T2_writevalue: BInteger;
    public BUSwrite: BRelation<BInteger, BInteger>;

    constructor(T2_state : T2state, T2_writevalue : BInteger, BUSwrite : BRelation<BInteger, BInteger>) {
        this.T2_state = T2_state;
        this.T2_writevalue = T2_writevalue;
        this.BUSwrite = BUSwrite;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_T2WriteBus = this;
        let o2: _ProjectionRead_T2WriteBus = other as _ProjectionRead_T2WriteBus;
        return o1.T2_state.equals(o2.T2_state) && o1.T2_writevalue.equals(o2.T2_writevalue) && o1.BUSwrite.equals(o2.BUSwrite);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.T2_writevalue.hashCode() << 1);
        result = 31 * result + (this.BUSwrite.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_T2WriteBus {

    public T2_state: T2state;
    public T2_writevalue: BInteger;

    constructor(T2_state : T2state, T2_writevalue : BInteger) {
        this.T2_state = T2_state;
        this.T2_writevalue = T2_writevalue;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_T2WriteBus = this;
        let o2: _ProjectionRead__tr_T2WriteBus = other as _ProjectionRead__tr_T2WriteBus;
        return o1.T2_state.equals(o2.T2_state) && o1.T2_writevalue.equals(o2.T2_writevalue);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.T2_writevalue.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_T2WriteBus {

    public T2_state: T2state;
    public BUSwrite: BRelation<BInteger, BInteger>;

    constructor(T2_state : T2state, BUSwrite : BRelation<BInteger, BInteger>) {
        this.T2_state = T2_state;
        this.BUSwrite = BUSwrite;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_T2WriteBus = this;
        let o2: _ProjectionWrite_T2WriteBus = other as _ProjectionWrite_T2WriteBus;
        return o1.T2_state.equals(o2.T2_state) && o1.BUSwrite.equals(o2.BUSwrite);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.BUSwrite.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_T2Wait {

    public T2_state: T2state;

    constructor(T2_state : T2state) {
        this.T2_state = T2_state;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_T2Wait = this;
        let o2: _ProjectionRead_T2Wait = other as _ProjectionRead_T2Wait;
        return o1.T2_state.equals(o2.T2_state);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_T2Wait {

    public T2_state: T2state;

    constructor(T2_state : T2state) {
        this.T2_state = T2_state;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_T2Wait = this;
        let o2: _ProjectionRead__tr_T2Wait = other as _ProjectionRead__tr_T2Wait;
        return o1.T2_state.equals(o2.T2_state);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_T2Wait {

    public T2_state: T2state;
    public T2_timer: BInteger;

    constructor(T2_state : T2state, T2_timer : BInteger) {
        this.T2_state = T2_state;
        this.T2_timer = T2_timer;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_T2Wait = this;
        let o2: _ProjectionWrite_T2Wait = other as _ProjectionWrite_T2Wait;
        return o1.T2_state.equals(o2.T2_state) && o1.T2_timer.equals(o2.T2_timer);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        result = 31 * result + (this.T2_timer.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_T3Initiate {

    public T3_evaluated: BBoolean;
    public T3_state: T3state;
    public T3_enabled: BBoolean;

    constructor(T3_evaluated : BBoolean, T3_state : T3state, T3_enabled : BBoolean) {
        this.T3_evaluated = T3_evaluated;
        this.T3_state = T3_state;
        this.T3_enabled = T3_enabled;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_T3Initiate = this;
        let o2: _ProjectionRead_T3Initiate = other as _ProjectionRead_T3Initiate;
        return o1.T3_evaluated.equals(o2.T3_evaluated) && o1.T3_state.equals(o2.T3_state) && o1.T3_enabled.equals(o2.T3_enabled);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_evaluated.hashCode() << 1);
        result = 31 * result + (this.T3_state.hashCode() << 1);
        result = 31 * result + (this.T3_enabled.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_T3Initiate {

    public T3_evaluated: BBoolean;
    public T3_state: T3state;
    public T3_enabled: BBoolean;

    constructor(T3_evaluated : BBoolean, T3_state : T3state, T3_enabled : BBoolean) {
        this.T3_evaluated = T3_evaluated;
        this.T3_state = T3_state;
        this.T3_enabled = T3_enabled;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_T3Initiate = this;
        let o2: _ProjectionRead__tr_T3Initiate = other as _ProjectionRead__tr_T3Initiate;
        return o1.T3_evaluated.equals(o2.T3_evaluated) && o1.T3_state.equals(o2.T3_state) && o1.T3_enabled.equals(o2.T3_enabled);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_evaluated.hashCode() << 1);
        result = 31 * result + (this.T3_state.hashCode() << 1);
        result = 31 * result + (this.T3_enabled.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_T3Initiate {

    public T3_state: T3state;
    public T3_enabled: BBoolean;

    constructor(T3_state : T3state, T3_enabled : BBoolean) {
        this.T3_state = T3_state;
        this.T3_enabled = T3_enabled;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_T3Initiate = this;
        let o2: _ProjectionWrite_T3Initiate = other as _ProjectionWrite_T3Initiate;
        return o1.T3_state.equals(o2.T3_state) && o1.T3_enabled.equals(o2.T3_enabled);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_state.hashCode() << 1);
        result = 31 * result + (this.T3_enabled.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_T3Evaluate {

    public T3_evaluated: BBoolean;
    public T3_state: T3state;
    public T3_enabled: BBoolean;

    constructor(T3_evaluated : BBoolean, T3_state : T3state, T3_enabled : BBoolean) {
        this.T3_evaluated = T3_evaluated;
        this.T3_state = T3_state;
        this.T3_enabled = T3_enabled;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_T3Evaluate = this;
        let o2: _ProjectionRead_T3Evaluate = other as _ProjectionRead_T3Evaluate;
        return o1.T3_evaluated.equals(o2.T3_evaluated) && o1.T3_state.equals(o2.T3_state) && o1.T3_enabled.equals(o2.T3_enabled);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_evaluated.hashCode() << 1);
        result = 31 * result + (this.T3_state.hashCode() << 1);
        result = 31 * result + (this.T3_enabled.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_T3Evaluate {

    public T3_evaluated: BBoolean;
    public T3_state: T3state;
    public T3_enabled: BBoolean;

    constructor(T3_evaluated : BBoolean, T3_state : T3state, T3_enabled : BBoolean) {
        this.T3_evaluated = T3_evaluated;
        this.T3_state = T3_state;
        this.T3_enabled = T3_enabled;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_T3Evaluate = this;
        let o2: _ProjectionRead__tr_T3Evaluate = other as _ProjectionRead__tr_T3Evaluate;
        return o1.T3_evaluated.equals(o2.T3_evaluated) && o1.T3_state.equals(o2.T3_state) && o1.T3_enabled.equals(o2.T3_enabled);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_evaluated.hashCode() << 1);
        result = 31 * result + (this.T3_state.hashCode() << 1);
        result = 31 * result + (this.T3_enabled.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_T3Evaluate {

    public T3_state: T3state;

    constructor(T3_state : T3state) {
        this.T3_state = T3_state;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_T3Evaluate = this;
        let o2: _ProjectionWrite_T3Evaluate = other as _ProjectionWrite_T3Evaluate;
        return o1.T3_state.equals(o2.T3_state);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_state.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_T3writebus {

    public T3_state: T3state;
    public BUSwrite: BRelation<BInteger, BInteger>;

    constructor(T3_state : T3state, BUSwrite : BRelation<BInteger, BInteger>) {
        this.T3_state = T3_state;
        this.BUSwrite = BUSwrite;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_T3writebus = this;
        let o2: _ProjectionRead_T3writebus = other as _ProjectionRead_T3writebus;
        return o1.T3_state.equals(o2.T3_state) && o1.BUSwrite.equals(o2.BUSwrite);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_state.hashCode() << 1);
        result = 31 * result + (this.BUSwrite.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_T3writebus {

    public T3_state: T3state;

    constructor(T3_state : T3state) {
        this.T3_state = T3_state;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_T3writebus = this;
        let o2: _ProjectionRead__tr_T3writebus = other as _ProjectionRead__tr_T3writebus;
        return o1.T3_state.equals(o2.T3_state);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_state.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_T3writebus {

    public T3_state: T3state;
    public BUSwrite: BRelation<BInteger, BInteger>;

    constructor(T3_state : T3state, BUSwrite : BRelation<BInteger, BInteger>) {
        this.T3_state = T3_state;
        this.BUSwrite = BUSwrite;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_T3writebus = this;
        let o2: _ProjectionWrite_T3writebus = other as _ProjectionWrite_T3writebus;
        return o1.T3_state.equals(o2.T3_state) && o1.BUSwrite.equals(o2.BUSwrite);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_state.hashCode() << 1);
        result = 31 * result + (this.BUSwrite.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_T3Read {

    public BUSpriority: BInteger;
    public T3_state: T3state;
    public BUSvalue: BInteger;

    constructor(BUSpriority : BInteger, T3_state : T3state, BUSvalue : BInteger) {
        this.BUSpriority = BUSpriority;
        this.T3_state = T3_state;
        this.BUSvalue = BUSvalue;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_T3Read = this;
        let o2: _ProjectionRead_T3Read = other as _ProjectionRead_T3Read;
        return o1.BUSpriority.equals(o2.BUSpriority) && o1.T3_state.equals(o2.T3_state) && o1.BUSvalue.equals(o2.BUSvalue);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.BUSpriority.hashCode() << 1);
        result = 31 * result + (this.T3_state.hashCode() << 1);
        result = 31 * result + (this.BUSvalue.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_T3Read {

    public BUSpriority: BInteger;
    public T3_state: T3state;
    public BUSvalue: BInteger;

    constructor(BUSpriority : BInteger, T3_state : T3state, BUSvalue : BInteger) {
        this.BUSpriority = BUSpriority;
        this.T3_state = T3_state;
        this.BUSvalue = BUSvalue;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_T3Read = this;
        let o2: _ProjectionRead__tr_T3Read = other as _ProjectionRead__tr_T3Read;
        return o1.BUSpriority.equals(o2.BUSpriority) && o1.T3_state.equals(o2.T3_state) && o1.BUSvalue.equals(o2.BUSvalue);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.BUSpriority.hashCode() << 1);
        result = 31 * result + (this.T3_state.hashCode() << 1);
        result = 31 * result + (this.BUSvalue.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_T3Read {

    public T3_readpriority: BInteger;
    public T3_readvalue: BInteger;
    public T3_state: T3state;

    constructor(T3_readpriority : BInteger, T3_readvalue : BInteger, T3_state : T3state) {
        this.T3_readpriority = T3_readpriority;
        this.T3_readvalue = T3_readvalue;
        this.T3_state = T3_state;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_T3Read = this;
        let o2: _ProjectionWrite_T3Read = other as _ProjectionWrite_T3Read;
        return o1.T3_readpriority.equals(o2.T3_readpriority) && o1.T3_readvalue.equals(o2.T3_readvalue) && o1.T3_state.equals(o2.T3_state);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_readpriority.hashCode() << 1);
        result = 31 * result + (this.T3_readvalue.hashCode() << 1);
        result = 31 * result + (this.T3_state.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_T3Poll {

    public T3_readpriority: BInteger;
    public T3_state: T3state;

    constructor(T3_readpriority : BInteger, T3_state : T3state) {
        this.T3_readpriority = T3_readpriority;
        this.T3_state = T3_state;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_T3Poll = this;
        let o2: _ProjectionRead_T3Poll = other as _ProjectionRead_T3Poll;
        return o1.T3_readpriority.equals(o2.T3_readpriority) && o1.T3_state.equals(o2.T3_state);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_readpriority.hashCode() << 1);
        result = 31 * result + (this.T3_state.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_T3Poll {

    public T3_readpriority: BInteger;
    public T3_state: T3state;

    constructor(T3_readpriority : BInteger, T3_state : T3state) {
        this.T3_readpriority = T3_readpriority;
        this.T3_state = T3_state;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_T3Poll = this;
        let o2: _ProjectionRead__tr_T3Poll = other as _ProjectionRead__tr_T3Poll;
        return o1.T3_readpriority.equals(o2.T3_readpriority) && o1.T3_state.equals(o2.T3_state);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_readpriority.hashCode() << 1);
        result = 31 * result + (this.T3_state.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_T3Poll {

    public T3_state: T3state;

    constructor(T3_state : T3state) {
        this.T3_state = T3_state;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_T3Poll = this;
        let o2: _ProjectionWrite_T3Poll = other as _ProjectionWrite_T3Poll;
        return o1.T3_state.equals(o2.T3_state);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_state.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_T3ReleaseBus {

    public T3_readpriority: BInteger;
    public T3_state: T3state;
    public BUSwrite: BRelation<BInteger, BInteger>;

    constructor(T3_readpriority : BInteger, T3_state : T3state, BUSwrite : BRelation<BInteger, BInteger>) {
        this.T3_readpriority = T3_readpriority;
        this.T3_state = T3_state;
        this.BUSwrite = BUSwrite;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_T3ReleaseBus = this;
        let o2: _ProjectionRead_T3ReleaseBus = other as _ProjectionRead_T3ReleaseBus;
        return o1.T3_readpriority.equals(o2.T3_readpriority) && o1.T3_state.equals(o2.T3_state) && o1.BUSwrite.equals(o2.BUSwrite);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_readpriority.hashCode() << 1);
        result = 31 * result + (this.T3_state.hashCode() << 1);
        result = 31 * result + (this.BUSwrite.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_T3ReleaseBus {

    public T3_readpriority: BInteger;
    public T3_state: T3state;

    constructor(T3_readpriority : BInteger, T3_state : T3state) {
        this.T3_readpriority = T3_readpriority;
        this.T3_state = T3_state;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_T3ReleaseBus = this;
        let o2: _ProjectionRead__tr_T3ReleaseBus = other as _ProjectionRead__tr_T3ReleaseBus;
        return o1.T3_readpriority.equals(o2.T3_readpriority) && o1.T3_state.equals(o2.T3_state);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_readpriority.hashCode() << 1);
        result = 31 * result + (this.T3_state.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_T3ReleaseBus {

    public T3_state: T3state;
    public BUSwrite: BRelation<BInteger, BInteger>;

    constructor(T3_state : T3state, BUSwrite : BRelation<BInteger, BInteger>) {
        this.T3_state = T3_state;
        this.BUSwrite = BUSwrite;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_T3ReleaseBus = this;
        let o2: _ProjectionWrite_T3ReleaseBus = other as _ProjectionWrite_T3ReleaseBus;
        return o1.T3_state.equals(o2.T3_state) && o1.BUSwrite.equals(o2.BUSwrite);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_state.hashCode() << 1);
        result = 31 * result + (this.BUSwrite.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_T3Wait {

    public T3_state: T3state;

    constructor(T3_state : T3state) {
        this.T3_state = T3_state;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_T3Wait = this;
        let o2: _ProjectionRead_T3Wait = other as _ProjectionRead_T3Wait;
        return o1.T3_state.equals(o2.T3_state);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_state.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_T3Wait {

    public T3_state: T3state;

    constructor(T3_state : T3state) {
        this.T3_state = T3_state;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_T3Wait = this;
        let o2: _ProjectionRead__tr_T3Wait = other as _ProjectionRead__tr_T3Wait;
        return o1.T3_state.equals(o2.T3_state);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_state.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_T3Wait {

    public T3_evaluated: BBoolean;
    public T3_state: T3state;

    constructor(T3_evaluated : BBoolean, T3_state : T3state) {
        this.T3_evaluated = T3_evaluated;
        this.T3_state = T3_state;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_T3Wait = this;
        let o2: _ProjectionWrite_T3Wait = other as _ProjectionWrite_T3Wait;
        return o1.T3_evaluated.equals(o2.T3_evaluated) && o1.T3_state.equals(o2.T3_state);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_evaluated.hashCode() << 1);
        result = 31 * result + (this.T3_state.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_T3ReEnableWait {

    public T3_state: T3state;

    constructor(T3_state : T3state) {
        this.T3_state = T3_state;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_T3ReEnableWait = this;
        let o2: _ProjectionRead_T3ReEnableWait = other as _ProjectionRead_T3ReEnableWait;
        return o1.T3_state.equals(o2.T3_state);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_state.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_T3ReEnableWait {

    public T3_state: T3state;

    constructor(T3_state : T3state) {
        this.T3_state = T3_state;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_T3ReEnableWait = this;
        let o2: _ProjectionRead__tr_T3ReEnableWait = other as _ProjectionRead__tr_T3ReEnableWait;
        return o1.T3_state.equals(o2.T3_state);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_state.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_T3ReEnableWait {

    public T3_evaluated: BBoolean;
    public T3_state: T3state;
    public T3_enabled: BBoolean;

    constructor(T3_evaluated : BBoolean, T3_state : T3state, T3_enabled : BBoolean) {
        this.T3_evaluated = T3_evaluated;
        this.T3_state = T3_state;
        this.T3_enabled = T3_enabled;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_T3ReEnableWait = this;
        let o2: _ProjectionWrite_T3ReEnableWait = other as _ProjectionWrite_T3ReEnableWait;
        return o1.T3_evaluated.equals(o2.T3_evaluated) && o1.T3_state.equals(o2.T3_state) && o1.T3_enabled.equals(o2.T3_enabled);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_evaluated.hashCode() << 1);
        result = 31 * result + (this.T3_state.hashCode() << 1);
        result = 31 * result + (this.T3_enabled.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_Update {

    public T3_evaluated: BBoolean;
    public T1_timer: BInteger;
    public T3_enabled: BBoolean;
    public BUSwrite: BRelation<BInteger, BInteger>;
    public T2_timer: BInteger;

    constructor(T3_evaluated : BBoolean, T1_timer : BInteger, T3_enabled : BBoolean, BUSwrite : BRelation<BInteger, BInteger>, T2_timer : BInteger) {
        this.T3_evaluated = T3_evaluated;
        this.T1_timer = T1_timer;
        this.T3_enabled = T3_enabled;
        this.BUSwrite = BUSwrite;
        this.T2_timer = T2_timer;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_Update = this;
        let o2: _ProjectionRead_Update = other as _ProjectionRead_Update;
        return o1.T3_evaluated.equals(o2.T3_evaluated) && o1.T1_timer.equals(o2.T1_timer) && o1.T3_enabled.equals(o2.T3_enabled) && o1.BUSwrite.equals(o2.BUSwrite) && o1.T2_timer.equals(o2.T2_timer);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_evaluated.hashCode() << 1);
        result = 31 * result + (this.T1_timer.hashCode() << 1);
        result = 31 * result + (this.T3_enabled.hashCode() << 1);
        result = 31 * result + (this.BUSwrite.hashCode() << 1);
        result = 31 * result + (this.T2_timer.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_Update {

    public T3_evaluated: BBoolean;
    public T1_timer: BInteger;
    public T3_enabled: BBoolean;
    public BUSwrite: BRelation<BInteger, BInteger>;
    public T2_timer: BInteger;

    constructor(T3_evaluated : BBoolean, T1_timer : BInteger, T3_enabled : BBoolean, BUSwrite : BRelation<BInteger, BInteger>, T2_timer : BInteger) {
        this.T3_evaluated = T3_evaluated;
        this.T1_timer = T1_timer;
        this.T3_enabled = T3_enabled;
        this.BUSwrite = BUSwrite;
        this.T2_timer = T2_timer;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_Update = this;
        let o2: _ProjectionRead__tr_Update = other as _ProjectionRead__tr_Update;
        return o1.T3_evaluated.equals(o2.T3_evaluated) && o1.T1_timer.equals(o2.T1_timer) && o1.T3_enabled.equals(o2.T3_enabled) && o1.BUSwrite.equals(o2.BUSwrite) && o1.T2_timer.equals(o2.T2_timer);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_evaluated.hashCode() << 1);
        result = 31 * result + (this.T1_timer.hashCode() << 1);
        result = 31 * result + (this.T3_enabled.hashCode() << 1);
        result = 31 * result + (this.BUSwrite.hashCode() << 1);
        result = 31 * result + (this.T2_timer.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_Update {

    public T3_evaluated: BBoolean;
    public BUSpriority: BInteger;
    public T1_timer: BInteger;
    public T2_timer: BInteger;
    public BUSvalue: BInteger;

    constructor(T3_evaluated : BBoolean, BUSpriority : BInteger, T1_timer : BInteger, T2_timer : BInteger, BUSvalue : BInteger) {
        this.T3_evaluated = T3_evaluated;
        this.BUSpriority = BUSpriority;
        this.T1_timer = T1_timer;
        this.T2_timer = T2_timer;
        this.BUSvalue = BUSvalue;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_Update = this;
        let o2: _ProjectionWrite_Update = other as _ProjectionWrite_Update;
        return o1.T3_evaluated.equals(o2.T3_evaluated) && o1.BUSpriority.equals(o2.BUSpriority) && o1.T1_timer.equals(o2.T1_timer) && o1.T2_timer.equals(o2.T2_timer) && o1.BUSvalue.equals(o2.BUSvalue);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_evaluated.hashCode() << 1);
        result = 31 * result + (this.BUSpriority.hashCode() << 1);
        result = 31 * result + (this.T1_timer.hashCode() << 1);
        result = 31 * result + (this.T2_timer.hashCode() << 1);
        result = 31 * result + (this.BUSvalue.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_1 {

    public T2v: BInteger;

    constructor(T2v : BInteger) {
        this.T2v = T2v;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_1 = this;
        let o2: _ProjectionRead__check_inv_1 = other as _ProjectionRead__check_inv_1;
        return o1.T2v.equals(o2.T2v);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2v.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_2 {

    public T3_evaluated: BBoolean;

    constructor(T3_evaluated : BBoolean) {
        this.T3_evaluated = T3_evaluated;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_2 = this;
        let o2: _ProjectionRead__check_inv_2 = other as _ProjectionRead__check_inv_2;
        return o1.T3_evaluated.equals(o2.T3_evaluated);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_evaluated.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_3 {

    public T3_enabled: BBoolean;

    constructor(T3_enabled : BBoolean) {
        this.T3_enabled = T3_enabled;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_3 = this;
        let o2: _ProjectionRead__check_inv_3 = other as _ProjectionRead__check_inv_3;
        return o1.T3_enabled.equals(o2.T3_enabled);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_enabled.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_4 {

    public T1_state: T1state;

    constructor(T1_state : T1state) {
        this.T1_state = T1_state;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_4 = this;
        let o2: _ProjectionRead__check_inv_4 = other as _ProjectionRead__check_inv_4;
        return o1.T1_state.equals(o2.T1_state);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T1_state.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_5 {

    public T2_state: T2state;

    constructor(T2_state : T2state) {
        this.T2_state = T2_state;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_5 = this;
        let o2: _ProjectionRead__check_inv_5 = other as _ProjectionRead__check_inv_5;
        return o1.T2_state.equals(o2.T2_state);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_state.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_6 {

    public T3_state: T3state;

    constructor(T3_state : T3state) {
        this.T3_state = T3_state;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_6 = this;
        let o2: _ProjectionRead__check_inv_6 = other as _ProjectionRead__check_inv_6;
        return o1.T3_state.equals(o2.T3_state);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_state.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_7 {

    public T1_writevalue: BInteger;

    constructor(T1_writevalue : BInteger) {
        this.T1_writevalue = T1_writevalue;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_7 = this;
        let o2: _ProjectionRead__check_inv_7 = other as _ProjectionRead__check_inv_7;
        return o1.T1_writevalue.equals(o2.T1_writevalue);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T1_writevalue.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_8 {

    public T2_writevalue: BInteger;

    constructor(T2_writevalue : BInteger) {
        this.T2_writevalue = T2_writevalue;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_8 = this;
        let o2: _ProjectionRead__check_inv_8 = other as _ProjectionRead__check_inv_8;
        return o1.T2_writevalue.equals(o2.T2_writevalue);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_writevalue.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_9 {

    public T2_readvalue: BInteger;

    constructor(T2_readvalue : BInteger) {
        this.T2_readvalue = T2_readvalue;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_9 = this;
        let o2: _ProjectionRead__check_inv_9 = other as _ProjectionRead__check_inv_9;
        return o1.T2_readvalue.equals(o2.T2_readvalue);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_readvalue.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_10 {

    public T1_timer: BInteger;

    constructor(T1_timer : BInteger) {
        this.T1_timer = T1_timer;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_10 = this;
        let o2: _ProjectionRead__check_inv_10 = other as _ProjectionRead__check_inv_10;
        return o1.T1_timer.equals(o2.T1_timer);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T1_timer.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_11 {

    public T2_timer: BInteger;

    constructor(T2_timer : BInteger) {
        this.T2_timer = T2_timer;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_11 = this;
        let o2: _ProjectionRead__check_inv_11 = other as _ProjectionRead__check_inv_11;
        return o1.T2_timer.equals(o2.T2_timer);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_timer.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_12 {

    public T2_mode: T2mode;

    constructor(T2_mode : T2mode) {
        this.T2_mode = T2_mode;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_12 = this;
        let o2: _ProjectionRead__check_inv_12 = other as _ProjectionRead__check_inv_12;
        return o1.T2_mode.equals(o2.T2_mode);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_mode.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_13 {

    public BUSvalue: BInteger;

    constructor(BUSvalue : BInteger) {
        this.BUSvalue = BUSvalue;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_13 = this;
        let o2: _ProjectionRead__check_inv_13 = other as _ProjectionRead__check_inv_13;
        return o1.BUSvalue.equals(o2.BUSvalue);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.BUSvalue.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_14 {

    public BUSpriority: BInteger;

    constructor(BUSpriority : BInteger) {
        this.BUSpriority = BUSpriority;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_14 = this;
        let o2: _ProjectionRead__check_inv_14 = other as _ProjectionRead__check_inv_14;
        return o1.BUSpriority.equals(o2.BUSpriority);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.BUSpriority.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_15 {

    public T3_readvalue: BInteger;

    constructor(T3_readvalue : BInteger) {
        this.T3_readvalue = T3_readvalue;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_15 = this;
        let o2: _ProjectionRead__check_inv_15 = other as _ProjectionRead__check_inv_15;
        return o1.T3_readvalue.equals(o2.T3_readvalue);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_readvalue.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_16 {

    public T3_readpriority: BInteger;

    constructor(T3_readpriority : BInteger) {
        this.T3_readpriority = T3_readpriority;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_16 = this;
        let o2: _ProjectionRead__check_inv_16 = other as _ProjectionRead__check_inv_16;
        return o1.T3_readpriority.equals(o2.T3_readpriority);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T3_readpriority.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_17 {

    public T2_readpriority: BInteger;

    constructor(T2_readpriority : BInteger) {
        this.T2_readpriority = T2_readpriority;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_17 = this;
        let o2: _ProjectionRead__check_inv_17 = other as _ProjectionRead__check_inv_17;
        return o1.T2_readpriority.equals(o2.T2_readpriority);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.T2_readpriority.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_18 {

    public BUSwrite: BRelation<BInteger, BInteger>;

    constructor(BUSwrite : BRelation<BInteger, BInteger>) {
        this.BUSwrite = BUSwrite;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_18 = this;
        let o2: _ProjectionRead__check_inv_18 = other as _ProjectionRead__check_inv_18;
        return o1.BUSwrite.equals(o2.BUSwrite);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.BUSwrite.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_19 {

    public BUSwrite: BRelation<BInteger, BInteger>;

    constructor(BUSwrite : BRelation<BInteger, BInteger>) {
        this.BUSwrite = BUSwrite;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_19 = this;
        let o2: _ProjectionRead__check_inv_19 = other as _ProjectionRead__check_inv_19;
        return o1.BUSwrite.equals(o2.BUSwrite);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.BUSwrite.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_20 {

    public BUSwrite: BRelation<BInteger, BInteger>;

    constructor(BUSwrite : BRelation<BInteger, BInteger>) {
        this.BUSwrite = BUSwrite;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_20 = this;
        let o2: _ProjectionRead__check_inv_20 = other as _ProjectionRead__check_inv_20;
        return o1.BUSwrite.equals(o2.BUSwrite);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.BUSwrite.hashCode() << 1);
        return result;
    }
}


export enum Type {
    BFS,
    DFS,
    MIXED
}

export default class CAN_BUS_tlc {

    parent: CAN_BUS_tlc;
    stateAccessedVia: string;


    private static NATSET: BSet<BInteger>;
    private static __aux_constant_1: BSet<BInteger>;

    private static _T1state: BSet<T1state> = new BSet<T1state>(new T1state(enum_T1state.T1_EN), new T1state(enum_T1state.T1_CALC), new T1state(enum_T1state.T1_SEND), new T1state(enum_T1state.T1_WAIT));
    private static _T2mode: BSet<T2mode> = new BSet<T2mode>(new T2mode(enum_T2mode.T2MODE_SENSE), new T2mode(enum_T2mode.T2MODE_TRANSMIT), new T2mode(enum_T2mode.T2MODE_RELEASE));
    private static _T2state: BSet<T2state> = new BSet<T2state>(new T2state(enum_T2state.T2_EN), new T2state(enum_T2state.T2_RCV), new T2state(enum_T2state.T2_PROC), new T2state(enum_T2state.T2_CALC), new T2state(enum_T2state.T2_SEND), new T2state(enum_T2state.T2_WAIT), new T2state(enum_T2state.T2_RELEASE));
    private static _T3state: BSet<T3state> = new BSet<T3state>(new T3state(enum_T3state.T3_READY), new T3state(enum_T3state.T3_WRITE), new T3state(enum_T3state.T3_RELEASE), new T3state(enum_T3state.T3_READ), new T3state(enum_T3state.T3_PROC), new T3state(enum_T3state.T3_WAIT));

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

    static {
        CAN_BUS_tlc.NATSET = BSet.interval(new BInteger(0), new BInteger(5));
        CAN_BUS_tlc.__aux_constant_1 = BSet.interval(new BInteger(1).negative(), new BInteger(3));
    }

    constructor(copy? : CAN_BUS_tlc) {
        if(copy) {
            this.BUSpriority = copy.BUSpriority;
            this.BUSvalue = copy.BUSvalue;
            this.BUSwrite = copy.BUSwrite;
            this.T1_state = copy.T1_state;
            this.T1_timer = copy.T1_timer;
            this.T1_writevalue = copy.T1_writevalue;
            this.T2_mode = copy.T2_mode;
            this.T2_readpriority = copy.T2_readpriority;
            this.T2_readvalue = copy.T2_readvalue;
            this.T2_state = copy.T2_state;
            this.T2_timer = copy.T2_timer;
            this.T2_writevalue = copy.T2_writevalue;
            this.T2v = copy.T2v;
            this.T3_enabled = copy.T3_enabled;
            this.T3_evaluated = copy.T3_evaluated;
            this.T3_readpriority = copy.T3_readpriority;
            this.T3_readvalue = copy.T3_readvalue;
            this.T3_state = copy.T3_state;
        } else {
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
        this.BUSwrite = _ld_BUSwrite.domainSubstraction(new BSet<BInteger>(ppriority));
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
        this.BUSwrite = _ld_BUSwrite.domainSubstraction(new BSet<BInteger>(ppriority));
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

    _get___aux_constant_1(): BSet<BInteger> {
        return CAN_BUS_tlc.__aux_constant_1;
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

    equals(o: any): boolean {
        let o1: CAN_BUS_tlc = this;
        let o2: CAN_BUS_tlc = o as CAN_BUS_tlc;
        return o1._get_BUSpriority().equals(o2._get_BUSpriority()) && o1._get_BUSvalue().equals(o2._get_BUSvalue()) && o1._get_BUSwrite().equals(o2._get_BUSwrite()) && o1._get_T1_state().equals(o2._get_T1_state()) && o1._get_T1_timer().equals(o2._get_T1_timer()) && o1._get_T1_writevalue().equals(o2._get_T1_writevalue()) && o1._get_T2_mode().equals(o2._get_T2_mode()) && o1._get_T2_readpriority().equals(o2._get_T2_readpriority()) && o1._get_T2_readvalue().equals(o2._get_T2_readvalue()) && o1._get_T2_state().equals(o2._get_T2_state()) && o1._get_T2_timer().equals(o2._get_T2_timer()) && o1._get_T2_writevalue().equals(o2._get_T2_writevalue()) && o1._get_T2v().equals(o2._get_T2v()) && o1._get_T3_enabled().equals(o2._get_T3_enabled()) && o1._get_T3_evaluated().equals(o2._get_T3_evaluated()) && o1._get_T3_readpriority().equals(o2._get_T3_readpriority()) && o1._get_T3_readvalue().equals(o2._get_T3_readvalue()) && o1._get_T3_state().equals(o2._get_T3_state());
    }



    hashCode(): number {
        return this._hashCode_1();
    }

    _hashCode_1(): number {
        let result: number = 1;
        result = (1543 * result) ^ ((this._get_BUSpriority()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_BUSvalue()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_BUSwrite()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T1_state()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T1_timer()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T1_writevalue()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T2_mode()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T2_readpriority()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T2_readvalue()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T2_state()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T2_timer()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T2_writevalue()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T2v()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T3_enabled()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T3_evaluated()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T3_readpriority()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T3_readvalue()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_T3_state()).hashCode() << 1);
        return result;
    }

    _hashCode_2(): number {
        let result: number = 1;
        result = (6151 * result) ^ ((this._get_BUSpriority()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_BUSvalue()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_BUSwrite()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T1_state()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T1_timer()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T1_writevalue()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T2_mode()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T2_readpriority()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T2_readvalue()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T2_state()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T2_timer()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T2_writevalue()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T2v()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T3_enabled()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T3_evaluated()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T3_readpriority()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T3_readvalue()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_T3_state()).hashCode() << 1);
        return result;
    }

    /* TODO
    toString(): string {
        return String.join("\n", "_get_BUSpriority: " + (this._get_BUSpriority()).toString(), "_get_BUSvalue: " + (this._get_BUSvalue()).toString(), "_get_BUSwrite: " + (this._get_BUSwrite()).toString(), "_get_T1_state: " + (this._get_T1_state()).toString(), "_get_T1_timer: " + (this._get_T1_timer()).toString(), "_get_T1_writevalue: " + (this._get_T1_writevalue()).toString(), "_get_T2_mode: " + (this._get_T2_mode()).toString(), "_get_T2_readpriority: " + (this._get_T2_readpriority()).toString(), "_get_T2_readvalue: " + (this._get_T2_readvalue()).toString(), "_get_T2_state: " + (this._get_T2_state()).toString(), "_get_T2_timer: " + (this._get_T2_timer()).toString(), "_get_T2_writevalue: " + (this._get_T2_writevalue()).toString(), "_get_T2v: " + (this._get_T2v()).toString(), "_get_T3_enabled: " + (this._get_T3_enabled()).toString(), "_get_T3_evaluated: " + (this._get_T3_evaluated()).toString(), "_get_T3_readpriority: " + (this._get_T3_readpriority()).toString(), "_get_T3_readvalue: " + (this._get_T3_readvalue()).toString(), "_get_T3_state: " + (this._get_T3_state()).toString());
    }
    */

    _tr_T1Evaluate(): boolean {
        return new BBoolean(this.T1_timer.equal(new BInteger(0)).booleanValue() && this.T1_state.equal(new T1state(enum_T1state.T1_EN)).booleanValue()).booleanValue();
    }

    _tr_T1Calculate(): BSet<BInteger> {
        let _ic_set_1: BSet<BInteger> = new BSet<BInteger>();
        for(let _ic_p_1 of CAN_BUS_tlc.__aux_constant_1) {
            if((this.T1_state.equal(new T1state(enum_T1state.T1_CALC))).booleanValue()) {
                _ic_set_1 = _ic_set_1.union(new BSet<BInteger>(_ic_p_1));
            }

        }

        return _ic_set_1;
    }

    _tr_T1SendResult(): BSet<BTuple<BInteger, BInteger>> {
        let _ic_set_2: BSet<BTuple<BInteger, BInteger>> = new BSet<BTuple<BInteger, BInteger>>();
        for(let _ic_ppriority_1 of Array.of(new BInteger(3))) {
            for(let _ic_pv_1 of Array.of(this.T1_writevalue)) {
                if((this.T1_state.equal(new T1state(enum_T1state.T1_SEND))).booleanValue()) {
                    _ic_set_2 = _ic_set_2.union(new BSet<BTuple<BInteger, BInteger>>(new BTuple(_ic_ppriority_1, _ic_pv_1)));
                }

            }

        }

        return _ic_set_2;
    }

    _tr_T1Wait(): BSet<BInteger> {
        let _ic_set_3: BSet<BInteger> = new BSet<BInteger>();
        for(let _ic_pt_1 of Array.of(new BInteger(2))) {
            if((this.T1_state.equal(new T1state(enum_T1state.T1_WAIT))).booleanValue()) {
                _ic_set_3 = _ic_set_3.union(new BSet<BInteger>(_ic_pt_1));
            }

        }

        return _ic_set_3;
    }

    _tr_T2Evaluate(): boolean {
        return new BBoolean(this.T2_timer.equal(new BInteger(0)).booleanValue() && this.T2_state.equal(new T2state(enum_T2state.T2_EN)).booleanValue()).booleanValue();
    }

    _tr_T2ReadBus(): BSet<BTuple<BInteger, BInteger>> {
        let _ic_set_5: BSet<BTuple<BInteger, BInteger>> = new BSet<BTuple<BInteger, BInteger>>();
        for(let _ic_ppriority_1 of Array.of(this.BUSpriority)) {
            for(let _ic_pv_1 of Array.of(this.BUSvalue)) {
                if((this.T2_state.equal(new T2state(enum_T2state.T2_RCV))).booleanValue()) {
                    _ic_set_5 = _ic_set_5.union(new BSet<BTuple<BInteger, BInteger>>(new BTuple(_ic_ppriority_1, _ic_pv_1)));
                }

            }

        }

        return _ic_set_5;
    }

    _tr_T2Reset(): boolean {
        return new BBoolean(this.T2_readpriority.equal(new BInteger(4)).booleanValue() && this.T2_state.equal(new T2state(enum_T2state.T2_PROC)).booleanValue()).booleanValue();
    }

    _tr_T2Complete(): boolean {
        return new BBoolean(new BBoolean(this.T2_state.equal(new T2state(enum_T2state.T2_PROC)).booleanValue() && this.T2_readpriority.equal(new BInteger(5)).booleanValue()).booleanValue() && this.T2_mode.equal(new T2mode(enum_T2mode.T2MODE_TRANSMIT)).booleanValue()).booleanValue();
    }

    _tr_T2ReleaseBus(): BSet<BInteger> {
        let _ic_set_8: BSet<BInteger> = new BSet<BInteger>();
        for(let _ic_ppriority_1 of Array.of(this.T2_readpriority)) {
            if((new BBoolean(this.BUSwrite.isInDomain(_ic_ppriority_1).booleanValue() && this.T2_state.equal(new T2state(enum_T2state.T2_RELEASE)).booleanValue())).booleanValue()) {
                _ic_set_8 = _ic_set_8.union(new BSet<BInteger>(_ic_ppriority_1));
            }

        }

        return _ic_set_8;
    }

    _tr_T2Calculate(): boolean {
        return new BBoolean(this.T2_readpriority.equal(new BInteger(3)).booleanValue() && this.T2_state.equal(new T2state(enum_T2state.T2_PROC)).booleanValue()).booleanValue();
    }

    _tr_T2WriteBus(): BSet<BTuple<BInteger, BInteger>> {
        let _ic_set_10: BSet<BTuple<BInteger, BInteger>> = new BSet<BTuple<BInteger, BInteger>>();
        for(let _ic_ppriority_1 of Array.of(new BInteger(5))) {
            for(let _ic_pv_1 of Array.of(this.T2_writevalue)) {
                if((this.T2_state.equal(new T2state(enum_T2state.T2_SEND))).booleanValue()) {
                    _ic_set_10 = _ic_set_10.union(new BSet<BTuple<BInteger, BInteger>>(new BTuple(_ic_ppriority_1, _ic_pv_1)));
                }

            }

        }

        return _ic_set_10;
    }

    _tr_T2Wait(): BSet<BInteger> {
        let _ic_set_11: BSet<BInteger> = new BSet<BInteger>();
        for(let _ic_pt_1 of Array.of(new BInteger(3))) {
            if((this.T2_state.equal(new T2state(enum_T2state.T2_WAIT))).booleanValue()) {
                _ic_set_11 = _ic_set_11.union(new BSet<BInteger>(_ic_pt_1));
            }

        }

        return _ic_set_11;
    }

    _tr_T3Initiate(): boolean {
        return new BBoolean(new BBoolean(this.T3_state.equal(new T3state(enum_T3state.T3_READY)).booleanValue() && this.T3_evaluated.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.T3_enabled.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    _tr_T3Evaluate(): boolean {
        return new BBoolean(new BBoolean(this.T3_state.equal(new T3state(enum_T3state.T3_READY)).booleanValue() && this.T3_evaluated.equal(new BBoolean(false)).booleanValue()).booleanValue() && this.T3_enabled.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    _tr_T3writebus(): BSet<BTuple<BInteger, BInteger>> {
        let _ic_set_14: BSet<BTuple<BInteger, BInteger>> = new BSet<BTuple<BInteger, BInteger>>();
        for(let _ic_ppriority_1 of Array.of(new BInteger(4))) {
            for(let _ic_pv_1 of Array.of(new BInteger(0))) {
                if((this.T3_state.equal(new T3state(enum_T3state.T3_WRITE))).booleanValue()) {
                    _ic_set_14 = _ic_set_14.union(new BSet<BTuple<BInteger, BInteger>>(new BTuple(_ic_ppriority_1, _ic_pv_1)));
                }

            }

        }

        return _ic_set_14;
    }

    _tr_T3Read(): BSet<BTuple<BInteger, BInteger>> {
        let _ic_set_15: BSet<BTuple<BInteger, BInteger>> = new BSet<BTuple<BInteger, BInteger>>();
        for(let _ic_ppriority_1 of Array.of(this.BUSpriority)) {
            for(let _ic_pv_1 of Array.of(this.BUSvalue)) {
                if((this.T3_state.equal(new T3state(enum_T3state.T3_READ))).booleanValue()) {
                    _ic_set_15 = _ic_set_15.union(new BSet<BTuple<BInteger, BInteger>>(new BTuple(_ic_ppriority_1, _ic_pv_1)));
                }

            }

        }

        return _ic_set_15;
    }

    _tr_T3Poll(): boolean {
        return new BBoolean(this.T3_readpriority.less(new BInteger(5)).booleanValue() && this.T3_state.equal(new T3state(enum_T3state.T3_PROC)).booleanValue()).booleanValue();
    }

    _tr_T3ReleaseBus(): BSet<BInteger> {
        let _ic_set_17: BSet<BInteger> = new BSet<BInteger>();
        for(let _ic_ppriority_1 of Array.of(new BInteger(4))) {
            if((new BBoolean(this.T3_readpriority.equal(new BInteger(5)).booleanValue() && this.T3_state.equal(new T3state(enum_T3state.T3_PROC)).booleanValue())).booleanValue()) {
                _ic_set_17 = _ic_set_17.union(new BSet<BInteger>(_ic_ppriority_1));
            }

        }

        return _ic_set_17;
    }

    _tr_T3Wait(): boolean {
        return this.T3_state.equal(new T3state(enum_T3state.T3_WAIT)).booleanValue();
    }

    _tr_T3ReEnableWait(): boolean {
        return this.T3_state.equal(new T3state(enum_T3state.T3_RELEASE)).booleanValue();
    }

    _tr_Update(): BSet<BInteger> {
        let _ic_set_20: BSet<BInteger> = new BSet<BInteger>();
        for(let _ic_pmax_1 of Array.of(this.BUSwrite.domain().max())) {
            if((new BBoolean(new BBoolean(this.T1_timer.greater(new BInteger(0)).booleanValue() && this.T2_timer.greater(new BInteger(0)).booleanValue()).booleanValue() && new BBoolean(this.T3_enabled.equal(new BBoolean(true)).booleanValue() || this.T3_evaluated.equal(new BBoolean(true)).booleanValue()).booleanValue())).booleanValue()) {
                _ic_set_20 = _ic_set_20.union(new BSet<BInteger>(_ic_pmax_1));
            }

        }

        return _ic_set_20;
    }

    _projected_state_for_T1Wait(): _ProjectionRead_T1Wait {
        return new _ProjectionRead_T1Wait(this.T1_state);
    }

    _projected_state_for_T1Calculate(): _ProjectionRead_T1Calculate {
        return new _ProjectionRead_T1Calculate(this.T1_state);
    }

    _projected_state_for_T1SendResult(): _ProjectionRead_T1SendResult {
        return new _ProjectionRead_T1SendResult(this.T1_state,this.T1_writevalue,this.BUSwrite);
    }

    _projected_state_for_T2ReadBus(): _ProjectionRead_T2ReadBus {
        return new _ProjectionRead_T2ReadBus(this.T2_state,this.BUSpriority,this.BUSvalue);
    }

    _projected_state_for_T2Reset(): _ProjectionRead_T2Reset {
        return new _ProjectionRead_T2Reset(this.T2_state,this.T2_readpriority,this.T2v);
    }

    _projected_state_for_T2Complete(): _ProjectionRead_T2Complete {
        return new _ProjectionRead_T2Complete(this.T2_state,this.T2_readpriority,this.T2_mode);
    }

    _projected_state_for_T2Evaluate(): _ProjectionRead_T2Evaluate {
        return new _ProjectionRead_T2Evaluate(this.T2_state,this.T2_timer);
    }

    _projected_state_for_T3Evaluate(): _ProjectionRead_T3Evaluate {
        return new _ProjectionRead_T3Evaluate(this.T3_evaluated,this.T3_state,this.T3_enabled);
    }

    _projected_state_for_T3ReleaseBus(): _ProjectionRead_T3ReleaseBus {
        return new _ProjectionRead_T3ReleaseBus(this.T3_readpriority,this.T3_state,this.BUSwrite);
    }

    _projected_state_for_T1Evaluate(): _ProjectionRead_T1Evaluate {
        return new _ProjectionRead_T1Evaluate(this.T1_state,this.T1_timer);
    }

    _projected_state_for_T3Initiate(): _ProjectionRead_T3Initiate {
        return new _ProjectionRead_T3Initiate(this.T3_evaluated,this.T3_state,this.T3_enabled);
    }

    _projected_state_for_T3ReEnableWait(): _ProjectionRead_T3ReEnableWait {
        return new _ProjectionRead_T3ReEnableWait(this.T3_state);
    }

    _projected_state_for_T3writebus(): _ProjectionRead_T3writebus {
        return new _ProjectionRead_T3writebus(this.T3_state,this.BUSwrite);
    }

    _projected_state_for_Update(): _ProjectionRead_Update {
        return new _ProjectionRead_Update(this.T3_evaluated,this.T1_timer,this.T3_enabled,this.BUSwrite,this.T2_timer);
    }

    _projected_state_for_T2ReleaseBus(): _ProjectionRead_T2ReleaseBus {
        return new _ProjectionRead_T2ReleaseBus(this.T2_state,this.T2_readpriority,this.BUSwrite);
    }

    _projected_state_for_T2Wait(): _ProjectionRead_T2Wait {
        return new _ProjectionRead_T2Wait(this.T2_state);
    }

    _projected_state_for_T3Poll(): _ProjectionRead_T3Poll {
        return new _ProjectionRead_T3Poll(this.T3_readpriority,this.T3_state);
    }

    _projected_state_for_T2Calculate(): _ProjectionRead_T2Calculate {
        return new _ProjectionRead_T2Calculate(this.T2_state,this.T2_readpriority,this.T2_readvalue);
    }

    _projected_state_for_T3Read(): _ProjectionRead_T3Read {
        return new _ProjectionRead_T3Read(this.BUSpriority,this.T3_state,this.BUSvalue);
    }

    _projected_state_for_T3Wait(): _ProjectionRead_T3Wait {
        return new _ProjectionRead_T3Wait(this.T3_state);
    }

    _projected_state_for_T2WriteBus(): _ProjectionRead_T2WriteBus {
        return new _ProjectionRead_T2WriteBus(this.T2_state,this.T2_writevalue,this.BUSwrite);
    }

    _projected_state_for__tr_T1Evaluate(): _ProjectionRead__tr_T1Evaluate {
        return new _ProjectionRead__tr_T1Evaluate(this.T1_state,this.T1_timer);
    }

    _projected_state_for__tr_T2Complete(): _ProjectionRead__tr_T2Complete {
        return new _ProjectionRead__tr_T2Complete(this.T2_state,this.T2_readpriority,this.T2_mode);
    }

    _projected_state_for__tr_T2Calculate(): _ProjectionRead__tr_T2Calculate {
        return new _ProjectionRead__tr_T2Calculate(this.T2_state,this.T2_readpriority);
    }

    _projected_state_for__tr_T2Evaluate(): _ProjectionRead__tr_T2Evaluate {
        return new _ProjectionRead__tr_T2Evaluate(this.T2_state,this.T2_timer);
    }

    _projected_state_for__tr_T3Poll(): _ProjectionRead__tr_T3Poll {
        return new _ProjectionRead__tr_T3Poll(this.T3_readpriority,this.T3_state);
    }

    _projected_state_for__tr_T3ReEnableWait(): _ProjectionRead__tr_T3ReEnableWait {
        return new _ProjectionRead__tr_T3ReEnableWait(this.T3_state);
    }

    _projected_state_for__tr_T2ReadBus(): _ProjectionRead__tr_T2ReadBus {
        return new _ProjectionRead__tr_T2ReadBus(this.T2_state,this.BUSpriority,this.BUSvalue);
    }

    _projected_state_for__tr_T2WriteBus(): _ProjectionRead__tr_T2WriteBus {
        return new _ProjectionRead__tr_T2WriteBus(this.T2_state,this.T2_writevalue);
    }

    _projected_state_for__tr_T2Wait(): _ProjectionRead__tr_T2Wait {
        return new _ProjectionRead__tr_T2Wait(this.T2_state);
    }

    _projected_state_for__tr_T2Reset(): _ProjectionRead__tr_T2Reset {
        return new _ProjectionRead__tr_T2Reset(this.T2_state,this.T2_readpriority);
    }

    _projected_state_for__tr_T2ReleaseBus(): _ProjectionRead__tr_T2ReleaseBus {
        return new _ProjectionRead__tr_T2ReleaseBus(this.T2_state,this.T2_readpriority,this.BUSwrite);
    }

    _projected_state_for__tr_T3writebus(): _ProjectionRead__tr_T3writebus {
        return new _ProjectionRead__tr_T3writebus(this.T3_state);
    }

    _projected_state_for__tr_T3Read(): _ProjectionRead__tr_T3Read {
        return new _ProjectionRead__tr_T3Read(this.BUSpriority,this.T3_state,this.BUSvalue);
    }

    _projected_state_for__tr_T3ReleaseBus(): _ProjectionRead__tr_T3ReleaseBus {
        return new _ProjectionRead__tr_T3ReleaseBus(this.T3_readpriority,this.T3_state);
    }

    _projected_state_for__tr_Update(): _ProjectionRead__tr_Update {
        return new _ProjectionRead__tr_Update(this.T3_evaluated,this.T1_timer,this.T3_enabled,this.BUSwrite,this.T2_timer);
    }

    _projected_state_for__tr_T1SendResult(): _ProjectionRead__tr_T1SendResult {
        return new _ProjectionRead__tr_T1SendResult(this.T1_state,this.T1_writevalue);
    }

    _projected_state_for__tr_T3Evaluate(): _ProjectionRead__tr_T3Evaluate {
        return new _ProjectionRead__tr_T3Evaluate(this.T3_evaluated,this.T3_state,this.T3_enabled);
    }

    _projected_state_for__tr_T1Calculate(): _ProjectionRead__tr_T1Calculate {
        return new _ProjectionRead__tr_T1Calculate(this.T1_state);
    }

    _projected_state_for__tr_T3Wait(): _ProjectionRead__tr_T3Wait {
        return new _ProjectionRead__tr_T3Wait(this.T3_state);
    }

    _projected_state_for__tr_T1Wait(): _ProjectionRead__tr_T1Wait {
        return new _ProjectionRead__tr_T1Wait(this.T1_state);
    }

    _projected_state_for__tr_T3Initiate(): _ProjectionRead__tr_T3Initiate {
        return new _ProjectionRead__tr_T3Initiate(this.T3_evaluated,this.T3_state,this.T3_enabled);
    }

    _projected_state_for__check_inv_18(): _ProjectionRead__check_inv_18 {
        return new _ProjectionRead__check_inv_18(this.BUSwrite);
    }

    _projected_state_for__check_inv_17(): _ProjectionRead__check_inv_17 {
        return new _ProjectionRead__check_inv_17(this.T2_readpriority);
    }

    _projected_state_for__check_inv_16(): _ProjectionRead__check_inv_16 {
        return new _ProjectionRead__check_inv_16(this.T3_readpriority);
    }

    _projected_state_for__check_inv_15(): _ProjectionRead__check_inv_15 {
        return new _ProjectionRead__check_inv_15(this.T3_readvalue);
    }

    _projected_state_for__check_inv_19(): _ProjectionRead__check_inv_19 {
        return new _ProjectionRead__check_inv_19(this.BUSwrite);
    }

    _projected_state_for__check_inv_6(): _ProjectionRead__check_inv_6 {
        return new _ProjectionRead__check_inv_6(this.T3_state);
    }

    _projected_state_for__check_inv_10(): _ProjectionRead__check_inv_10 {
        return new _ProjectionRead__check_inv_10(this.T1_timer);
    }

    _projected_state_for__check_inv_7(): _ProjectionRead__check_inv_7 {
        return new _ProjectionRead__check_inv_7(this.T1_writevalue);
    }

    _projected_state_for__check_inv_20(): _ProjectionRead__check_inv_20 {
        return new _ProjectionRead__check_inv_20(this.BUSwrite);
    }

    _projected_state_for__check_inv_4(): _ProjectionRead__check_inv_4 {
        return new _ProjectionRead__check_inv_4(this.T1_state);
    }

    _projected_state_for__check_inv_5(): _ProjectionRead__check_inv_5 {
        return new _ProjectionRead__check_inv_5(this.T2_state);
    }

    _projected_state_for__check_inv_14(): _ProjectionRead__check_inv_14 {
        return new _ProjectionRead__check_inv_14(this.BUSpriority);
    }

    _projected_state_for__check_inv_13(): _ProjectionRead__check_inv_13 {
        return new _ProjectionRead__check_inv_13(this.BUSvalue);
    }

    _projected_state_for__check_inv_8(): _ProjectionRead__check_inv_8 {
        return new _ProjectionRead__check_inv_8(this.T2_writevalue);
    }

    _projected_state_for__check_inv_12(): _ProjectionRead__check_inv_12 {
        return new _ProjectionRead__check_inv_12(this.T2_mode);
    }

    _projected_state_for__check_inv_9(): _ProjectionRead__check_inv_9 {
        return new _ProjectionRead__check_inv_9(this.T2_readvalue);
    }

    _projected_state_for__check_inv_11(): _ProjectionRead__check_inv_11 {
        return new _ProjectionRead__check_inv_11(this.T2_timer);
    }

    _projected_state_for__check_inv_2(): _ProjectionRead__check_inv_2 {
        return new _ProjectionRead__check_inv_2(this.T3_evaluated);
    }

    _projected_state_for__check_inv_3(): _ProjectionRead__check_inv_3 {
        return new _ProjectionRead__check_inv_3(this.T3_enabled);
    }

    _projected_state_for__check_inv_1(): _ProjectionRead__check_inv_1 {
        return new _ProjectionRead__check_inv_1(this.T2v);
    }

    _update_for_T1Wait(): _ProjectionWrite_T1Wait {
        return new _ProjectionWrite_T1Wait(this.T1_state,this.T1_timer);
    }

    _update_for_T1Calculate(): _ProjectionWrite_T1Calculate {
        return new _ProjectionWrite_T1Calculate(this.T1_state,this.T1_writevalue);
    }

    _update_for_T1SendResult(): _ProjectionWrite_T1SendResult {
        return new _ProjectionWrite_T1SendResult(this.T1_state,this.BUSwrite);
    }

    _update_for_T2ReadBus(): _ProjectionWrite_T2ReadBus {
        return new _ProjectionWrite_T2ReadBus(this.T2_state,this.T2_readpriority,this.T2_readvalue);
    }

    _update_for_T2Reset(): _ProjectionWrite_T2Reset {
        return new _ProjectionWrite_T2Reset(this.T2_state,this.T2_writevalue,this.T2v,this.T2_mode);
    }

    _update_for_T2Complete(): _ProjectionWrite_T2Complete {
        return new _ProjectionWrite_T2Complete(this.T2_state,this.T2_mode);
    }

    _update_for_T2Evaluate(): _ProjectionWrite_T2Evaluate {
        return new _ProjectionWrite_T2Evaluate(this.T2_state,this.T2_timer);
    }

    _update_for_T3Evaluate(): _ProjectionWrite_T3Evaluate {
        return new _ProjectionWrite_T3Evaluate(this.T3_state);
    }

    _update_for_T3ReleaseBus(): _ProjectionWrite_T3ReleaseBus {
        return new _ProjectionWrite_T3ReleaseBus(this.T3_state,this.BUSwrite);
    }

    _update_for_T1Evaluate(): _ProjectionWrite_T1Evaluate {
        return new _ProjectionWrite_T1Evaluate(this.T1_state,this.T1_timer);
    }

    _update_for_T3Initiate(): _ProjectionWrite_T3Initiate {
        return new _ProjectionWrite_T3Initiate(this.T3_state,this.T3_enabled);
    }

    _update_for_T3ReEnableWait(): _ProjectionWrite_T3ReEnableWait {
        return new _ProjectionWrite_T3ReEnableWait(this.T3_evaluated,this.T3_state,this.T3_enabled);
    }

    _update_for_T3writebus(): _ProjectionWrite_T3writebus {
        return new _ProjectionWrite_T3writebus(this.T3_state,this.BUSwrite);
    }

    _update_for_Update(): _ProjectionWrite_Update {
        return new _ProjectionWrite_Update(this.T3_evaluated,this.BUSpriority,this.T1_timer,this.T2_timer,this.BUSvalue);
    }

    _update_for_T2ReleaseBus(): _ProjectionWrite_T2ReleaseBus {
        return new _ProjectionWrite_T2ReleaseBus(this.T2_state,this.BUSwrite);
    }

    _update_for_T2Wait(): _ProjectionWrite_T2Wait {
        return new _ProjectionWrite_T2Wait(this.T2_state,this.T2_timer);
    }

    _update_for_T3Poll(): _ProjectionWrite_T3Poll {
        return new _ProjectionWrite_T3Poll(this.T3_state);
    }

    _update_for_T2Calculate(): _ProjectionWrite_T2Calculate {
        return new _ProjectionWrite_T2Calculate(this.T2_state,this.T2v);
    }

    _update_for_T3Read(): _ProjectionWrite_T3Read {
        return new _ProjectionWrite_T3Read(this.T3_readpriority,this.T3_readvalue,this.T3_state);
    }

    _update_for_T3Wait(): _ProjectionWrite_T3Wait {
        return new _ProjectionWrite_T3Wait(this.T3_evaluated,this.T3_state);
    }

    _update_for_T2WriteBus(): _ProjectionWrite_T2WriteBus {
        return new _ProjectionWrite_T2WriteBus(this.T2_state,this.BUSwrite);
    }

    _apply_update_for_T1Wait(update : _ProjectionWrite_T1Wait): void {
        this.T1_state = update.T1_state;
        this.T1_timer = update.T1_timer;
    }

    _apply_update_for_T1Calculate(update : _ProjectionWrite_T1Calculate): void {
        this.T1_state = update.T1_state;
        this.T1_writevalue = update.T1_writevalue;
    }

    _apply_update_for_T1SendResult(update : _ProjectionWrite_T1SendResult): void {
        this.T1_state = update.T1_state;
        this.BUSwrite = update.BUSwrite;
    }

    _apply_update_for_T2ReadBus(update : _ProjectionWrite_T2ReadBus): void {
        this.T2_state = update.T2_state;
        this.T2_readpriority = update.T2_readpriority;
        this.T2_readvalue = update.T2_readvalue;
    }

    _apply_update_for_T2Reset(update : _ProjectionWrite_T2Reset): void {
        this.T2_state = update.T2_state;
        this.T2_writevalue = update.T2_writevalue;
        this.T2v = update.T2v;
        this.T2_mode = update.T2_mode;
    }

    _apply_update_for_T2Complete(update : _ProjectionWrite_T2Complete): void {
        this.T2_state = update.T2_state;
        this.T2_mode = update.T2_mode;
    }

    _apply_update_for_T2Evaluate(update : _ProjectionWrite_T2Evaluate): void {
        this.T2_state = update.T2_state;
        this.T2_timer = update.T2_timer;
    }

    _apply_update_for_T3Evaluate(update : _ProjectionWrite_T3Evaluate): void {
        this.T3_state = update.T3_state;
    }

    _apply_update_for_T3ReleaseBus(update : _ProjectionWrite_T3ReleaseBus): void {
        this.T3_state = update.T3_state;
        this.BUSwrite = update.BUSwrite;
    }

    _apply_update_for_T1Evaluate(update : _ProjectionWrite_T1Evaluate): void {
        this.T1_state = update.T1_state;
        this.T1_timer = update.T1_timer;
    }

    _apply_update_for_T3Initiate(update : _ProjectionWrite_T3Initiate): void {
        this.T3_state = update.T3_state;
        this.T3_enabled = update.T3_enabled;
    }

    _apply_update_for_T3ReEnableWait(update : _ProjectionWrite_T3ReEnableWait): void {
        this.T3_evaluated = update.T3_evaluated;
        this.T3_state = update.T3_state;
        this.T3_enabled = update.T3_enabled;
    }

    _apply_update_for_T3writebus(update : _ProjectionWrite_T3writebus): void {
        this.T3_state = update.T3_state;
        this.BUSwrite = update.BUSwrite;
    }

    _apply_update_for_Update(update : _ProjectionWrite_Update): void {
        this.T3_evaluated = update.T3_evaluated;
        this.BUSpriority = update.BUSpriority;
        this.T1_timer = update.T1_timer;
        this.T2_timer = update.T2_timer;
        this.BUSvalue = update.BUSvalue;
    }

    _apply_update_for_T2ReleaseBus(update : _ProjectionWrite_T2ReleaseBus): void {
        this.T2_state = update.T2_state;
        this.BUSwrite = update.BUSwrite;
    }

    _apply_update_for_T2Wait(update : _ProjectionWrite_T2Wait): void {
        this.T2_state = update.T2_state;
        this.T2_timer = update.T2_timer;
    }

    _apply_update_for_T3Poll(update : _ProjectionWrite_T3Poll): void {
        this.T3_state = update.T3_state;
    }

    _apply_update_for_T2Calculate(update : _ProjectionWrite_T2Calculate): void {
        this.T2_state = update.T2_state;
        this.T2v = update.T2v;
    }

    _apply_update_for_T3Read(update : _ProjectionWrite_T3Read): void {
        this.T3_readpriority = update.T3_readpriority;
        this.T3_readvalue = update.T3_readvalue;
        this.T3_state = update.T3_state;
    }

    _apply_update_for_T3Wait(update : _ProjectionWrite_T3Wait): void {
        this.T3_evaluated = update.T3_evaluated;
        this.T3_state = update.T3_state;
    }

    _apply_update_for_T2WriteBus(update : _ProjectionWrite_T2WriteBus): void {
        this.T2_state = update.T2_state;
        this.BUSwrite = update.BUSwrite;
    }

    _check_inv_1() {
        return this.T2v.isInteger().booleanValue();
    }

    _check_inv_2() {
        return this.T3_evaluated.isBoolean().booleanValue();
    }

    _check_inv_3() {
        return this.T3_enabled.isBoolean().booleanValue();
    }

    _check_inv_4() {
        return CAN_BUS_tlc._T1state.elementOf(this.T1_state).booleanValue();
    }

    _check_inv_5() {
        return CAN_BUS_tlc._T2state.elementOf(this.T2_state).booleanValue();
    }

    _check_inv_6() {
        return CAN_BUS_tlc._T3state.elementOf(this.T3_state).booleanValue();
    }

    _check_inv_7() {
        return this.T1_writevalue.isInteger().booleanValue();
    }

    _check_inv_8() {
        return this.T2_writevalue.isInteger().booleanValue();
    }

    _check_inv_9() {
        return this.T2_readvalue.isInteger().booleanValue();
    }

    _check_inv_10() {
        return this.T1_timer.isNatural().booleanValue();
    }

    _check_inv_11() {
        return this.T2_timer.isNatural().booleanValue();
    }

    _check_inv_12() {
        return CAN_BUS_tlc._T2mode.elementOf(this.T2_mode).booleanValue();
    }

    _check_inv_13() {
        return this.BUSvalue.isInteger().booleanValue();
    }

    _check_inv_14() {
        return CAN_BUS_tlc.NATSET.elementOf(this.BUSpriority).booleanValue();
    }

    _check_inv_15() {
        return this.T3_readvalue.isInteger().booleanValue();
    }

    _check_inv_16() {
        return CAN_BUS_tlc.NATSET.elementOf(this.T3_readpriority).booleanValue();
    }

    _check_inv_17() {
        return CAN_BUS_tlc.NATSET.elementOf(this.T2_readpriority).booleanValue();
    }

    _check_inv_18() {
        return this.BUSwrite.checkDomain(CAN_BUS_tlc.NATSET).and(this.BUSwrite.checkRangeInteger()).and(this.BUSwrite.isFunction()).and(this.BUSwrite.isPartial(CAN_BUS_tlc.NATSET)).booleanValue();
    }

    _check_inv_19() {
        return this.BUSwrite.unequal(new BRelation<BInteger, BInteger>()).booleanValue();
    }

    _check_inv_20() {
        return this.BUSwrite.isInDomain(new BInteger(0)).booleanValue();
    }


    public _copy(): CAN_BUS_tlc {
      return new CAN_BUS_tlc(this);
    }


}


export class ModelChecker {
    private type: Type;
    private isCaching: boolean;
    private isDebug: boolean;

    private unvisitedStates: LinkedList<CAN_BUS_tlc> = new LinkedList<CAN_BUS_tlc>;
    private states: immutable.Set<CAN_BUS_tlc> = new immutable.Set();
    private transitions: number = 0;

    private invariantViolated: boolean = false;
    private deadlockDetected: boolean = false;
    private counterExampleState: CAN_BUS_tlc = undefined;

    _OpCache_T1Evaluate: immutable.Map<boolean, immutable.Map<_ProjectionRead_T1Evaluate, _ProjectionWrite_T1Evaluate>> = new immutable.Map();
    _OpCache_tr_T1Evaluate: immutable.Map<_ProjectionRead__tr_T1Evaluate, boolean> = new immutable.Map();

    _OpCache_T1Calculate: immutable.Map<BSet<BInteger>, immutable.Map<_ProjectionRead_T1Calculate, _ProjectionWrite_T1Calculate>> = new immutable.Map();
    _OpCache_tr_T1Calculate: immutable.Map<_ProjectionRead__tr_T1Calculate, BSet<BInteger>> = new immutable.Map();

    _OpCache_T1SendResult: immutable.Map<BSet<BTuple<BInteger, BInteger>>, immutable.Map<_ProjectionRead_T1SendResult, _ProjectionWrite_T1SendResult>> = new immutable.Map();
    _OpCache_tr_T1SendResult: immutable.Map<_ProjectionRead__tr_T1SendResult, BSet<BTuple<BInteger, BInteger>>> = new immutable.Map();

    _OpCache_T1Wait: immutable.Map<BSet<BInteger>, immutable.Map<_ProjectionRead_T1Wait, _ProjectionWrite_T1Wait>> = new immutable.Map();
    _OpCache_tr_T1Wait: immutable.Map<_ProjectionRead__tr_T1Wait, BSet<BInteger>> = new immutable.Map();

    _OpCache_T2Evaluate: immutable.Map<boolean, immutable.Map<_ProjectionRead_T2Evaluate, _ProjectionWrite_T2Evaluate>> = new immutable.Map();
    _OpCache_tr_T2Evaluate: immutable.Map<_ProjectionRead__tr_T2Evaluate, boolean> = new immutable.Map();

    _OpCache_T2ReadBus: immutable.Map<BSet<BTuple<BInteger, BInteger>>, immutable.Map<_ProjectionRead_T2ReadBus, _ProjectionWrite_T2ReadBus>> = new immutable.Map();
    _OpCache_tr_T2ReadBus: immutable.Map<_ProjectionRead__tr_T2ReadBus, BSet<BTuple<BInteger, BInteger>>> = new immutable.Map();

    _OpCache_T2Reset: immutable.Map<boolean, immutable.Map<_ProjectionRead_T2Reset, _ProjectionWrite_T2Reset>> = new immutable.Map();
    _OpCache_tr_T2Reset: immutable.Map<_ProjectionRead__tr_T2Reset, boolean> = new immutable.Map();

    _OpCache_T2Complete: immutable.Map<boolean, immutable.Map<_ProjectionRead_T2Complete, _ProjectionWrite_T2Complete>> = new immutable.Map();
    _OpCache_tr_T2Complete: immutable.Map<_ProjectionRead__tr_T2Complete, boolean> = new immutable.Map();

    _OpCache_T2ReleaseBus: immutable.Map<BSet<BInteger>, immutable.Map<_ProjectionRead_T2ReleaseBus, _ProjectionWrite_T2ReleaseBus>> = new immutable.Map();
    _OpCache_tr_T2ReleaseBus: immutable.Map<_ProjectionRead__tr_T2ReleaseBus, BSet<BInteger>> = new immutable.Map();

    _OpCache_T2Calculate: immutable.Map<boolean, immutable.Map<_ProjectionRead_T2Calculate, _ProjectionWrite_T2Calculate>> = new immutable.Map();
    _OpCache_tr_T2Calculate: immutable.Map<_ProjectionRead__tr_T2Calculate, boolean> = new immutable.Map();

    _OpCache_T2WriteBus: immutable.Map<BSet<BTuple<BInteger, BInteger>>, immutable.Map<_ProjectionRead_T2WriteBus, _ProjectionWrite_T2WriteBus>> = new immutable.Map();
    _OpCache_tr_T2WriteBus: immutable.Map<_ProjectionRead__tr_T2WriteBus, BSet<BTuple<BInteger, BInteger>>> = new immutable.Map();

    _OpCache_T2Wait: immutable.Map<BSet<BInteger>, immutable.Map<_ProjectionRead_T2Wait, _ProjectionWrite_T2Wait>> = new immutable.Map();
    _OpCache_tr_T2Wait: immutable.Map<_ProjectionRead__tr_T2Wait, BSet<BInteger>> = new immutable.Map();

    _OpCache_T3Initiate: immutable.Map<boolean, immutable.Map<_ProjectionRead_T3Initiate, _ProjectionWrite_T3Initiate>> = new immutable.Map();
    _OpCache_tr_T3Initiate: immutable.Map<_ProjectionRead__tr_T3Initiate, boolean> = new immutable.Map();

    _OpCache_T3Evaluate: immutable.Map<boolean, immutable.Map<_ProjectionRead_T3Evaluate, _ProjectionWrite_T3Evaluate>> = new immutable.Map();
    _OpCache_tr_T3Evaluate: immutable.Map<_ProjectionRead__tr_T3Evaluate, boolean> = new immutable.Map();

    _OpCache_T3writebus: immutable.Map<BSet<BTuple<BInteger, BInteger>>, immutable.Map<_ProjectionRead_T3writebus, _ProjectionWrite_T3writebus>> = new immutable.Map();
    _OpCache_tr_T3writebus: immutable.Map<_ProjectionRead__tr_T3writebus, BSet<BTuple<BInteger, BInteger>>> = new immutable.Map();

    _OpCache_T3Read: immutable.Map<BSet<BTuple<BInteger, BInteger>>, immutable.Map<_ProjectionRead_T3Read, _ProjectionWrite_T3Read>> = new immutable.Map();
    _OpCache_tr_T3Read: immutable.Map<_ProjectionRead__tr_T3Read, BSet<BTuple<BInteger, BInteger>>> = new immutable.Map();

    _OpCache_T3Poll: immutable.Map<boolean, immutable.Map<_ProjectionRead_T3Poll, _ProjectionWrite_T3Poll>> = new immutable.Map();
    _OpCache_tr_T3Poll: immutable.Map<_ProjectionRead__tr_T3Poll, boolean> = new immutable.Map();

    _OpCache_T3ReleaseBus: immutable.Map<BSet<BInteger>, immutable.Map<_ProjectionRead_T3ReleaseBus, _ProjectionWrite_T3ReleaseBus>> = new immutable.Map();
    _OpCache_tr_T3ReleaseBus: immutable.Map<_ProjectionRead__tr_T3ReleaseBus, BSet<BInteger>> = new immutable.Map();

    _OpCache_T3Wait: immutable.Map<boolean, immutable.Map<_ProjectionRead_T3Wait, _ProjectionWrite_T3Wait>> = new immutable.Map();
    _OpCache_tr_T3Wait: immutable.Map<_ProjectionRead__tr_T3Wait, boolean> = new immutable.Map();

    _OpCache_T3ReEnableWait: immutable.Map<boolean, immutable.Map<_ProjectionRead_T3ReEnableWait, _ProjectionWrite_T3ReEnableWait>> = new immutable.Map();
    _OpCache_tr_T3ReEnableWait: immutable.Map<_ProjectionRead__tr_T3ReEnableWait, boolean> = new immutable.Map();

    _OpCache_Update: immutable.Map<BSet<BInteger>, immutable.Map<_ProjectionRead_Update, _ProjectionWrite_Update>> = new immutable.Map();
    _OpCache_tr_Update: immutable.Map<_ProjectionRead__tr_Update, BSet<BInteger>> = new immutable.Map();

    _InvCache__check_inv_1: immutable.Map<_ProjectionRead__check_inv_1, boolean> = new immutable.Map();
    _InvCache__check_inv_2: immutable.Map<_ProjectionRead__check_inv_2, boolean> = new immutable.Map();
    _InvCache__check_inv_3: immutable.Map<_ProjectionRead__check_inv_3, boolean> = new immutable.Map();
    _InvCache__check_inv_4: immutable.Map<_ProjectionRead__check_inv_4, boolean> = new immutable.Map();
    _InvCache__check_inv_5: immutable.Map<_ProjectionRead__check_inv_5, boolean> = new immutable.Map();
    _InvCache__check_inv_6: immutable.Map<_ProjectionRead__check_inv_6, boolean> = new immutable.Map();
    _InvCache__check_inv_7: immutable.Map<_ProjectionRead__check_inv_7, boolean> = new immutable.Map();
    _InvCache__check_inv_8: immutable.Map<_ProjectionRead__check_inv_8, boolean> = new immutable.Map();
    _InvCache__check_inv_9: immutable.Map<_ProjectionRead__check_inv_9, boolean> = new immutable.Map();
    _InvCache__check_inv_10: immutable.Map<_ProjectionRead__check_inv_10, boolean> = new immutable.Map();
    _InvCache__check_inv_11: immutable.Map<_ProjectionRead__check_inv_11, boolean> = new immutable.Map();
    _InvCache__check_inv_12: immutable.Map<_ProjectionRead__check_inv_12, boolean> = new immutable.Map();
    _InvCache__check_inv_13: immutable.Map<_ProjectionRead__check_inv_13, boolean> = new immutable.Map();
    _InvCache__check_inv_14: immutable.Map<_ProjectionRead__check_inv_14, boolean> = new immutable.Map();
    _InvCache__check_inv_15: immutable.Map<_ProjectionRead__check_inv_15, boolean> = new immutable.Map();
    _InvCache__check_inv_16: immutable.Map<_ProjectionRead__check_inv_16, boolean> = new immutable.Map();
    _InvCache__check_inv_17: immutable.Map<_ProjectionRead__check_inv_17, boolean> = new immutable.Map();
    _InvCache__check_inv_18: immutable.Map<_ProjectionRead__check_inv_18, boolean> = new immutable.Map();
    _InvCache__check_inv_19: immutable.Map<_ProjectionRead__check_inv_19, boolean> = new immutable.Map();
    _InvCache__check_inv_20: immutable.Map<_ProjectionRead__check_inv_20, boolean> = new immutable.Map();

    constructor(type: Type, isCaching: boolean, isDebug: boolean) {
        this.type = type;
        this.isCaching = isCaching;
        this.isDebug = isDebug;
    }

    modelCheck(): void {
        if (this.isDebug) {
            console.log("Starting Modelchecking, STRATEGY=" + this.type + ", CACHING=" + this.isCaching);
        }
        this.modelCheckSingleThreaded();
    }

    modelCheckSingleThreaded(): void {
        let machine: CAN_BUS_tlc = new CAN_BUS_tlc();
        this.states = this.states.add(machine);
        this.unvisitedStates.pushBack(machine);

        while(!(this.unvisitedStates.length === 0)) {
            let state: CAN_BUS_tlc = this.next();

            let nextStates: Set<CAN_BUS_tlc> = this.generateNextStates(state);

            for(let nextState of nextStates) {
                if(!this.states.has(nextState)) {
                    this.states = this.states.add(nextState);
                    this.unvisitedStates.pushBack(nextState);
                    if(this.states.size % 50000 == 0 && this.isDebug) {
                        console.log("VISITED STATES: " + this.states.size);
                        console.log("EVALUATED TRANSITIONS: " + this.transitions);
                        console.log("-------------------");
                    }
                }
            }

            if(this.invViolated(state)) {
                this.invariantViolated = true;
                this.counterExampleState = state;
                break;
            }

            if(nextStates.size == 0) {
                this.deadlockDetected = true;
                this.counterExampleState = state;
                break;
            }

        }
        this.printResult(this.states.size, this.transitions);
    }

    next(): CAN_BUS_tlc {
        switch(this.type) {
            case Type.BFS:
                return this.unvisitedStates.popFront();
            case Type.DFS:
                return this.unvisitedStates.popBack();
            case Type.MIXED:
                if(this.unvisitedStates.length % 2 == 0) {
                    return this.unvisitedStates.popFront();
                } else {
                    return this.unvisitedStates.popBack();
                }
            default:
                break;
        }
        return undefined;
    }

    generateNextStates(state: CAN_BUS_tlc): Set<CAN_BUS_tlc> {
        let result: immutable.Set<CAN_BUS_tlc> = immutable.Set();
        if(this.isCaching) {
            let read__tr_T1Evaluate_state : _ProjectionRead__tr_T1Evaluate = state._projected_state_for__tr_T1Evaluate();
            let _obj__trid_1: any = this._OpCache_tr_T1Evaluate.get(read__tr_T1Evaluate_state);
            let _trid_1: boolean;
            if(_obj__trid_1 == null) {
                _trid_1 = state._tr_T1Evaluate();
                this._OpCache_tr_T1Evaluate = this._OpCache_tr_T1Evaluate.set(read__tr_T1Evaluate_state, _trid_1);
            } else {
                _trid_1 = _obj__trid_1;
            }

            if(_trid_1) {
                let copiedState: CAN_BUS_tlc = state._copy();
                let readState: _ProjectionRead_T1Evaluate = state._projected_state_for_T1Evaluate();
                let _OpCache_with_parameter_T1Evaluate: immutable.Map = this._OpCache_T1Evaluate.get(_trid_1);
                if(_OpCache_with_parameter_T1Evaluate != null) {
                    let writeState: _ProjectionWrite_T1Evaluate = _OpCache_with_parameter_T1Evaluate.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_T1Evaluate(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.T1Evaluate();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_T1Evaluate();
                        _OpCache_with_parameter_T1Evaluate = _OpCache_with_parameter_T1Evaluate.set(readState, writeState);
                        this._OpCache_T1Evaluate = this._OpCache_T1Evaluate.set(_trid_1, _OpCache_with_parameter_T1Evaluate);
                    }

                } else {
                    copiedState.T1Evaluate();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_T1Evaluate = copiedState._update_for_T1Evaluate();
                    _OpCache_with_parameter_T1Evaluate = new immutable.Map().set(readState, writeState);
                    this._OpCache_T1Evaluate = this._OpCache_T1Evaluate.set(_trid_1, _OpCache_with_parameter_T1Evaluate);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_T1Calculate_state : _ProjectionRead__tr_T1Calculate = state._projected_state_for__tr_T1Calculate();
            let _trid_2 : BSet<BInteger>  = this._OpCache_tr_T1Calculate.get(read__tr_T1Calculate_state);
            if(_trid_2 == null) {
                _trid_2 = state._tr_T1Calculate();
                this._OpCache_tr_T1Calculate = this._OpCache_tr_T1Calculate.set(read__tr_T1Calculate_state, _trid_2);
            }

            for(let param of _trid_2) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                let readState: _ProjectionRead_T1Calculate = state._projected_state_for_T1Calculate();
                let _OpCache_with_parameter_T1Calculate: immutable.Map = this._OpCache_T1Calculate.get(param);
                if(_OpCache_with_parameter_T1Calculate != null) {
                    let writeState: _ProjectionWrite_T1Calculate = _OpCache_with_parameter_T1Calculate.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_T1Calculate(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.T1Calculate(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_T1Calculate();
                        _OpCache_with_parameter_T1Calculate = _OpCache_with_parameter_T1Calculate.set(readState, writeState);
                        this._OpCache_T1Calculate = this._OpCache_T1Calculate.set(param, _OpCache_with_parameter_T1Calculate);
                    }

                } else {
                    copiedState.T1Calculate(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_T1Calculate = copiedState._update_for_T1Calculate();
                    _OpCache_with_parameter_T1Calculate = new immutable.Map().set(readState, writeState);
                    this._OpCache_T1Calculate = this._OpCache_T1Calculate.set(param, _OpCache_with_parameter_T1Calculate);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_T1SendResult_state : _ProjectionRead__tr_T1SendResult = state._projected_state_for__tr_T1SendResult();
            let _trid_3 : BSet<BTuple<BInteger, BInteger>>  = this._OpCache_tr_T1SendResult.get(read__tr_T1SendResult_state);
            if(_trid_3 == null) {
                _trid_3 = state._tr_T1SendResult();
                this._OpCache_tr_T1SendResult = this._OpCache_tr_T1SendResult.set(read__tr_T1SendResult_state, _trid_3);
            }

            for(let param of _trid_3) {
                let _tmp_1: BInteger = param.projection2();
                let _tmp_2: BInteger = param.projection1();

                let copiedState: CAN_BUS_tlc = state._copy();
                let readState: _ProjectionRead_T1SendResult = state._projected_state_for_T1SendResult();
                let _OpCache_with_parameter_T1SendResult: immutable.Map = this._OpCache_T1SendResult.get(param);
                if(_OpCache_with_parameter_T1SendResult != null) {
                    let writeState: _ProjectionWrite_T1SendResult = _OpCache_with_parameter_T1SendResult.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_T1SendResult(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.T1SendResult(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_T1SendResult();
                        _OpCache_with_parameter_T1SendResult = _OpCache_with_parameter_T1SendResult.set(readState, writeState);
                        this._OpCache_T1SendResult = this._OpCache_T1SendResult.set(param, _OpCache_with_parameter_T1SendResult);
                    }

                } else {
                    copiedState.T1SendResult(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_T1SendResult = copiedState._update_for_T1SendResult();
                    _OpCache_with_parameter_T1SendResult = new immutable.Map().set(readState, writeState);
                    this._OpCache_T1SendResult = this._OpCache_T1SendResult.set(param, _OpCache_with_parameter_T1SendResult);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_T1Wait_state : _ProjectionRead__tr_T1Wait = state._projected_state_for__tr_T1Wait();
            let _trid_4 : BSet<BInteger>  = this._OpCache_tr_T1Wait.get(read__tr_T1Wait_state);
            if(_trid_4 == null) {
                _trid_4 = state._tr_T1Wait();
                this._OpCache_tr_T1Wait = this._OpCache_tr_T1Wait.set(read__tr_T1Wait_state, _trid_4);
            }

            for(let param of _trid_4) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                let readState: _ProjectionRead_T1Wait = state._projected_state_for_T1Wait();
                let _OpCache_with_parameter_T1Wait: immutable.Map = this._OpCache_T1Wait.get(param);
                if(_OpCache_with_parameter_T1Wait != null) {
                    let writeState: _ProjectionWrite_T1Wait = _OpCache_with_parameter_T1Wait.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_T1Wait(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.T1Wait(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_T1Wait();
                        _OpCache_with_parameter_T1Wait = _OpCache_with_parameter_T1Wait.set(readState, writeState);
                        this._OpCache_T1Wait = this._OpCache_T1Wait.set(param, _OpCache_with_parameter_T1Wait);
                    }

                } else {
                    copiedState.T1Wait(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_T1Wait = copiedState._update_for_T1Wait();
                    _OpCache_with_parameter_T1Wait = new immutable.Map().set(readState, writeState);
                    this._OpCache_T1Wait = this._OpCache_T1Wait.set(param, _OpCache_with_parameter_T1Wait);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_T2Evaluate_state : _ProjectionRead__tr_T2Evaluate = state._projected_state_for__tr_T2Evaluate();
            let _obj__trid_5: any = this._OpCache_tr_T2Evaluate.get(read__tr_T2Evaluate_state);
            let _trid_5: boolean;
            if(_obj__trid_5 == null) {
                _trid_5 = state._tr_T2Evaluate();
                this._OpCache_tr_T2Evaluate = this._OpCache_tr_T2Evaluate.set(read__tr_T2Evaluate_state, _trid_5);
            } else {
                _trid_5 = _obj__trid_5;
            }

            if(_trid_5) {
                let copiedState: CAN_BUS_tlc = state._copy();
                let readState: _ProjectionRead_T2Evaluate = state._projected_state_for_T2Evaluate();
                let _OpCache_with_parameter_T2Evaluate: immutable.Map = this._OpCache_T2Evaluate.get(_trid_5);
                if(_OpCache_with_parameter_T2Evaluate != null) {
                    let writeState: _ProjectionWrite_T2Evaluate = _OpCache_with_parameter_T2Evaluate.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_T2Evaluate(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.T2Evaluate();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_T2Evaluate();
                        _OpCache_with_parameter_T2Evaluate = _OpCache_with_parameter_T2Evaluate.set(readState, writeState);
                        this._OpCache_T2Evaluate = this._OpCache_T2Evaluate.set(_trid_5, _OpCache_with_parameter_T2Evaluate);
                    }

                } else {
                    copiedState.T2Evaluate();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_T2Evaluate = copiedState._update_for_T2Evaluate();
                    _OpCache_with_parameter_T2Evaluate = new immutable.Map().set(readState, writeState);
                    this._OpCache_T2Evaluate = this._OpCache_T2Evaluate.set(_trid_5, _OpCache_with_parameter_T2Evaluate);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_T2ReadBus_state : _ProjectionRead__tr_T2ReadBus = state._projected_state_for__tr_T2ReadBus();
            let _trid_6 : BSet<BTuple<BInteger, BInteger>>  = this._OpCache_tr_T2ReadBus.get(read__tr_T2ReadBus_state);
            if(_trid_6 == null) {
                _trid_6 = state._tr_T2ReadBus();
                this._OpCache_tr_T2ReadBus = this._OpCache_tr_T2ReadBus.set(read__tr_T2ReadBus_state, _trid_6);
            }

            for(let param of _trid_6) {
                let _tmp_1: BInteger = param.projection2();
                let _tmp_2: BInteger = param.projection1();

                let copiedState: CAN_BUS_tlc = state._copy();
                let readState: _ProjectionRead_T2ReadBus = state._projected_state_for_T2ReadBus();
                let _OpCache_with_parameter_T2ReadBus: immutable.Map = this._OpCache_T2ReadBus.get(param);
                if(_OpCache_with_parameter_T2ReadBus != null) {
                    let writeState: _ProjectionWrite_T2ReadBus = _OpCache_with_parameter_T2ReadBus.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_T2ReadBus(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.T2ReadBus(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_T2ReadBus();
                        _OpCache_with_parameter_T2ReadBus = _OpCache_with_parameter_T2ReadBus.set(readState, writeState);
                        this._OpCache_T2ReadBus = this._OpCache_T2ReadBus.set(param, _OpCache_with_parameter_T2ReadBus);
                    }

                } else {
                    copiedState.T2ReadBus(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_T2ReadBus = copiedState._update_for_T2ReadBus();
                    _OpCache_with_parameter_T2ReadBus = new immutable.Map().set(readState, writeState);
                    this._OpCache_T2ReadBus = this._OpCache_T2ReadBus.set(param, _OpCache_with_parameter_T2ReadBus);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_T2Reset_state : _ProjectionRead__tr_T2Reset = state._projected_state_for__tr_T2Reset();
            let _obj__trid_7: any = this._OpCache_tr_T2Reset.get(read__tr_T2Reset_state);
            let _trid_7: boolean;
            if(_obj__trid_7 == null) {
                _trid_7 = state._tr_T2Reset();
                this._OpCache_tr_T2Reset = this._OpCache_tr_T2Reset.set(read__tr_T2Reset_state, _trid_7);
            } else {
                _trid_7 = _obj__trid_7;
            }

            if(_trid_7) {
                let copiedState: CAN_BUS_tlc = state._copy();
                let readState: _ProjectionRead_T2Reset = state._projected_state_for_T2Reset();
                let _OpCache_with_parameter_T2Reset: immutable.Map = this._OpCache_T2Reset.get(_trid_7);
                if(_OpCache_with_parameter_T2Reset != null) {
                    let writeState: _ProjectionWrite_T2Reset = _OpCache_with_parameter_T2Reset.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_T2Reset(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.T2Reset();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_T2Reset();
                        _OpCache_with_parameter_T2Reset = _OpCache_with_parameter_T2Reset.set(readState, writeState);
                        this._OpCache_T2Reset = this._OpCache_T2Reset.set(_trid_7, _OpCache_with_parameter_T2Reset);
                    }

                } else {
                    copiedState.T2Reset();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_T2Reset = copiedState._update_for_T2Reset();
                    _OpCache_with_parameter_T2Reset = new immutable.Map().set(readState, writeState);
                    this._OpCache_T2Reset = this._OpCache_T2Reset.set(_trid_7, _OpCache_with_parameter_T2Reset);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_T2Complete_state : _ProjectionRead__tr_T2Complete = state._projected_state_for__tr_T2Complete();
            let _obj__trid_8: any = this._OpCache_tr_T2Complete.get(read__tr_T2Complete_state);
            let _trid_8: boolean;
            if(_obj__trid_8 == null) {
                _trid_8 = state._tr_T2Complete();
                this._OpCache_tr_T2Complete = this._OpCache_tr_T2Complete.set(read__tr_T2Complete_state, _trid_8);
            } else {
                _trid_8 = _obj__trid_8;
            }

            if(_trid_8) {
                let copiedState: CAN_BUS_tlc = state._copy();
                let readState: _ProjectionRead_T2Complete = state._projected_state_for_T2Complete();
                let _OpCache_with_parameter_T2Complete: immutable.Map = this._OpCache_T2Complete.get(_trid_8);
                if(_OpCache_with_parameter_T2Complete != null) {
                    let writeState: _ProjectionWrite_T2Complete = _OpCache_with_parameter_T2Complete.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_T2Complete(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.T2Complete();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_T2Complete();
                        _OpCache_with_parameter_T2Complete = _OpCache_with_parameter_T2Complete.set(readState, writeState);
                        this._OpCache_T2Complete = this._OpCache_T2Complete.set(_trid_8, _OpCache_with_parameter_T2Complete);
                    }

                } else {
                    copiedState.T2Complete();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_T2Complete = copiedState._update_for_T2Complete();
                    _OpCache_with_parameter_T2Complete = new immutable.Map().set(readState, writeState);
                    this._OpCache_T2Complete = this._OpCache_T2Complete.set(_trid_8, _OpCache_with_parameter_T2Complete);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_T2ReleaseBus_state : _ProjectionRead__tr_T2ReleaseBus = state._projected_state_for__tr_T2ReleaseBus();
            let _trid_9 : BSet<BInteger>  = this._OpCache_tr_T2ReleaseBus.get(read__tr_T2ReleaseBus_state);
            if(_trid_9 == null) {
                _trid_9 = state._tr_T2ReleaseBus();
                this._OpCache_tr_T2ReleaseBus = this._OpCache_tr_T2ReleaseBus.set(read__tr_T2ReleaseBus_state, _trid_9);
            }

            for(let param of _trid_9) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                let readState: _ProjectionRead_T2ReleaseBus = state._projected_state_for_T2ReleaseBus();
                let _OpCache_with_parameter_T2ReleaseBus: immutable.Map = this._OpCache_T2ReleaseBus.get(param);
                if(_OpCache_with_parameter_T2ReleaseBus != null) {
                    let writeState: _ProjectionWrite_T2ReleaseBus = _OpCache_with_parameter_T2ReleaseBus.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_T2ReleaseBus(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.T2ReleaseBus(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_T2ReleaseBus();
                        _OpCache_with_parameter_T2ReleaseBus = _OpCache_with_parameter_T2ReleaseBus.set(readState, writeState);
                        this._OpCache_T2ReleaseBus = this._OpCache_T2ReleaseBus.set(param, _OpCache_with_parameter_T2ReleaseBus);
                    }

                } else {
                    copiedState.T2ReleaseBus(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_T2ReleaseBus = copiedState._update_for_T2ReleaseBus();
                    _OpCache_with_parameter_T2ReleaseBus = new immutable.Map().set(readState, writeState);
                    this._OpCache_T2ReleaseBus = this._OpCache_T2ReleaseBus.set(param, _OpCache_with_parameter_T2ReleaseBus);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_T2Calculate_state : _ProjectionRead__tr_T2Calculate = state._projected_state_for__tr_T2Calculate();
            let _obj__trid_10: any = this._OpCache_tr_T2Calculate.get(read__tr_T2Calculate_state);
            let _trid_10: boolean;
            if(_obj__trid_10 == null) {
                _trid_10 = state._tr_T2Calculate();
                this._OpCache_tr_T2Calculate = this._OpCache_tr_T2Calculate.set(read__tr_T2Calculate_state, _trid_10);
            } else {
                _trid_10 = _obj__trid_10;
            }

            if(_trid_10) {
                let copiedState: CAN_BUS_tlc = state._copy();
                let readState: _ProjectionRead_T2Calculate = state._projected_state_for_T2Calculate();
                let _OpCache_with_parameter_T2Calculate: immutable.Map = this._OpCache_T2Calculate.get(_trid_10);
                if(_OpCache_with_parameter_T2Calculate != null) {
                    let writeState: _ProjectionWrite_T2Calculate = _OpCache_with_parameter_T2Calculate.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_T2Calculate(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.T2Calculate();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_T2Calculate();
                        _OpCache_with_parameter_T2Calculate = _OpCache_with_parameter_T2Calculate.set(readState, writeState);
                        this._OpCache_T2Calculate = this._OpCache_T2Calculate.set(_trid_10, _OpCache_with_parameter_T2Calculate);
                    }

                } else {
                    copiedState.T2Calculate();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_T2Calculate = copiedState._update_for_T2Calculate();
                    _OpCache_with_parameter_T2Calculate = new immutable.Map().set(readState, writeState);
                    this._OpCache_T2Calculate = this._OpCache_T2Calculate.set(_trid_10, _OpCache_with_parameter_T2Calculate);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_T2WriteBus_state : _ProjectionRead__tr_T2WriteBus = state._projected_state_for__tr_T2WriteBus();
            let _trid_11 : BSet<BTuple<BInteger, BInteger>>  = this._OpCache_tr_T2WriteBus.get(read__tr_T2WriteBus_state);
            if(_trid_11 == null) {
                _trid_11 = state._tr_T2WriteBus();
                this._OpCache_tr_T2WriteBus = this._OpCache_tr_T2WriteBus.set(read__tr_T2WriteBus_state, _trid_11);
            }

            for(let param of _trid_11) {
                let _tmp_1: BInteger = param.projection2();
                let _tmp_2: BInteger = param.projection1();

                let copiedState: CAN_BUS_tlc = state._copy();
                let readState: _ProjectionRead_T2WriteBus = state._projected_state_for_T2WriteBus();
                let _OpCache_with_parameter_T2WriteBus: immutable.Map = this._OpCache_T2WriteBus.get(param);
                if(_OpCache_with_parameter_T2WriteBus != null) {
                    let writeState: _ProjectionWrite_T2WriteBus = _OpCache_with_parameter_T2WriteBus.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_T2WriteBus(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.T2WriteBus(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_T2WriteBus();
                        _OpCache_with_parameter_T2WriteBus = _OpCache_with_parameter_T2WriteBus.set(readState, writeState);
                        this._OpCache_T2WriteBus = this._OpCache_T2WriteBus.set(param, _OpCache_with_parameter_T2WriteBus);
                    }

                } else {
                    copiedState.T2WriteBus(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_T2WriteBus = copiedState._update_for_T2WriteBus();
                    _OpCache_with_parameter_T2WriteBus = new immutable.Map().set(readState, writeState);
                    this._OpCache_T2WriteBus = this._OpCache_T2WriteBus.set(param, _OpCache_with_parameter_T2WriteBus);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_T2Wait_state : _ProjectionRead__tr_T2Wait = state._projected_state_for__tr_T2Wait();
            let _trid_12 : BSet<BInteger>  = this._OpCache_tr_T2Wait.get(read__tr_T2Wait_state);
            if(_trid_12 == null) {
                _trid_12 = state._tr_T2Wait();
                this._OpCache_tr_T2Wait = this._OpCache_tr_T2Wait.set(read__tr_T2Wait_state, _trid_12);
            }

            for(let param of _trid_12) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                let readState: _ProjectionRead_T2Wait = state._projected_state_for_T2Wait();
                let _OpCache_with_parameter_T2Wait: immutable.Map = this._OpCache_T2Wait.get(param);
                if(_OpCache_with_parameter_T2Wait != null) {
                    let writeState: _ProjectionWrite_T2Wait = _OpCache_with_parameter_T2Wait.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_T2Wait(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.T2Wait(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_T2Wait();
                        _OpCache_with_parameter_T2Wait = _OpCache_with_parameter_T2Wait.set(readState, writeState);
                        this._OpCache_T2Wait = this._OpCache_T2Wait.set(param, _OpCache_with_parameter_T2Wait);
                    }

                } else {
                    copiedState.T2Wait(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_T2Wait = copiedState._update_for_T2Wait();
                    _OpCache_with_parameter_T2Wait = new immutable.Map().set(readState, writeState);
                    this._OpCache_T2Wait = this._OpCache_T2Wait.set(param, _OpCache_with_parameter_T2Wait);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_T3Initiate_state : _ProjectionRead__tr_T3Initiate = state._projected_state_for__tr_T3Initiate();
            let _obj__trid_13: any = this._OpCache_tr_T3Initiate.get(read__tr_T3Initiate_state);
            let _trid_13: boolean;
            if(_obj__trid_13 == null) {
                _trid_13 = state._tr_T3Initiate();
                this._OpCache_tr_T3Initiate = this._OpCache_tr_T3Initiate.set(read__tr_T3Initiate_state, _trid_13);
            } else {
                _trid_13 = _obj__trid_13;
            }

            if(_trid_13) {
                let copiedState: CAN_BUS_tlc = state._copy();
                let readState: _ProjectionRead_T3Initiate = state._projected_state_for_T3Initiate();
                let _OpCache_with_parameter_T3Initiate: immutable.Map = this._OpCache_T3Initiate.get(_trid_13);
                if(_OpCache_with_parameter_T3Initiate != null) {
                    let writeState: _ProjectionWrite_T3Initiate = _OpCache_with_parameter_T3Initiate.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_T3Initiate(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.T3Initiate();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_T3Initiate();
                        _OpCache_with_parameter_T3Initiate = _OpCache_with_parameter_T3Initiate.set(readState, writeState);
                        this._OpCache_T3Initiate = this._OpCache_T3Initiate.set(_trid_13, _OpCache_with_parameter_T3Initiate);
                    }

                } else {
                    copiedState.T3Initiate();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_T3Initiate = copiedState._update_for_T3Initiate();
                    _OpCache_with_parameter_T3Initiate = new immutable.Map().set(readState, writeState);
                    this._OpCache_T3Initiate = this._OpCache_T3Initiate.set(_trid_13, _OpCache_with_parameter_T3Initiate);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_T3Evaluate_state : _ProjectionRead__tr_T3Evaluate = state._projected_state_for__tr_T3Evaluate();
            let _obj__trid_14: any = this._OpCache_tr_T3Evaluate.get(read__tr_T3Evaluate_state);
            let _trid_14: boolean;
            if(_obj__trid_14 == null) {
                _trid_14 = state._tr_T3Evaluate();
                this._OpCache_tr_T3Evaluate = this._OpCache_tr_T3Evaluate.set(read__tr_T3Evaluate_state, _trid_14);
            } else {
                _trid_14 = _obj__trid_14;
            }

            if(_trid_14) {
                let copiedState: CAN_BUS_tlc = state._copy();
                let readState: _ProjectionRead_T3Evaluate = state._projected_state_for_T3Evaluate();
                let _OpCache_with_parameter_T3Evaluate: immutable.Map = this._OpCache_T3Evaluate.get(_trid_14);
                if(_OpCache_with_parameter_T3Evaluate != null) {
                    let writeState: _ProjectionWrite_T3Evaluate = _OpCache_with_parameter_T3Evaluate.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_T3Evaluate(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.T3Evaluate();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_T3Evaluate();
                        _OpCache_with_parameter_T3Evaluate = _OpCache_with_parameter_T3Evaluate.set(readState, writeState);
                        this._OpCache_T3Evaluate = this._OpCache_T3Evaluate.set(_trid_14, _OpCache_with_parameter_T3Evaluate);
                    }

                } else {
                    copiedState.T3Evaluate();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_T3Evaluate = copiedState._update_for_T3Evaluate();
                    _OpCache_with_parameter_T3Evaluate = new immutable.Map().set(readState, writeState);
                    this._OpCache_T3Evaluate = this._OpCache_T3Evaluate.set(_trid_14, _OpCache_with_parameter_T3Evaluate);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_T3writebus_state : _ProjectionRead__tr_T3writebus = state._projected_state_for__tr_T3writebus();
            let _trid_15 : BSet<BTuple<BInteger, BInteger>>  = this._OpCache_tr_T3writebus.get(read__tr_T3writebus_state);
            if(_trid_15 == null) {
                _trid_15 = state._tr_T3writebus();
                this._OpCache_tr_T3writebus = this._OpCache_tr_T3writebus.set(read__tr_T3writebus_state, _trid_15);
            }

            for(let param of _trid_15) {
                let _tmp_1: BInteger = param.projection2();
                let _tmp_2: BInteger = param.projection1();

                let copiedState: CAN_BUS_tlc = state._copy();
                let readState: _ProjectionRead_T3writebus = state._projected_state_for_T3writebus();
                let _OpCache_with_parameter_T3writebus: immutable.Map = this._OpCache_T3writebus.get(param);
                if(_OpCache_with_parameter_T3writebus != null) {
                    let writeState: _ProjectionWrite_T3writebus = _OpCache_with_parameter_T3writebus.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_T3writebus(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.T3writebus(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_T3writebus();
                        _OpCache_with_parameter_T3writebus = _OpCache_with_parameter_T3writebus.set(readState, writeState);
                        this._OpCache_T3writebus = this._OpCache_T3writebus.set(param, _OpCache_with_parameter_T3writebus);
                    }

                } else {
                    copiedState.T3writebus(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_T3writebus = copiedState._update_for_T3writebus();
                    _OpCache_with_parameter_T3writebus = new immutable.Map().set(readState, writeState);
                    this._OpCache_T3writebus = this._OpCache_T3writebus.set(param, _OpCache_with_parameter_T3writebus);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_T3Read_state : _ProjectionRead__tr_T3Read = state._projected_state_for__tr_T3Read();
            let _trid_16 : BSet<BTuple<BInteger, BInteger>>  = this._OpCache_tr_T3Read.get(read__tr_T3Read_state);
            if(_trid_16 == null) {
                _trid_16 = state._tr_T3Read();
                this._OpCache_tr_T3Read = this._OpCache_tr_T3Read.set(read__tr_T3Read_state, _trid_16);
            }

            for(let param of _trid_16) {
                let _tmp_1: BInteger = param.projection2();
                let _tmp_2: BInteger = param.projection1();

                let copiedState: CAN_BUS_tlc = state._copy();
                let readState: _ProjectionRead_T3Read = state._projected_state_for_T3Read();
                let _OpCache_with_parameter_T3Read: immutable.Map = this._OpCache_T3Read.get(param);
                if(_OpCache_with_parameter_T3Read != null) {
                    let writeState: _ProjectionWrite_T3Read = _OpCache_with_parameter_T3Read.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_T3Read(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.T3Read(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_T3Read();
                        _OpCache_with_parameter_T3Read = _OpCache_with_parameter_T3Read.set(readState, writeState);
                        this._OpCache_T3Read = this._OpCache_T3Read.set(param, _OpCache_with_parameter_T3Read);
                    }

                } else {
                    copiedState.T3Read(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_T3Read = copiedState._update_for_T3Read();
                    _OpCache_with_parameter_T3Read = new immutable.Map().set(readState, writeState);
                    this._OpCache_T3Read = this._OpCache_T3Read.set(param, _OpCache_with_parameter_T3Read);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_T3Poll_state : _ProjectionRead__tr_T3Poll = state._projected_state_for__tr_T3Poll();
            let _obj__trid_17: any = this._OpCache_tr_T3Poll.get(read__tr_T3Poll_state);
            let _trid_17: boolean;
            if(_obj__trid_17 == null) {
                _trid_17 = state._tr_T3Poll();
                this._OpCache_tr_T3Poll = this._OpCache_tr_T3Poll.set(read__tr_T3Poll_state, _trid_17);
            } else {
                _trid_17 = _obj__trid_17;
            }

            if(_trid_17) {
                let copiedState: CAN_BUS_tlc = state._copy();
                let readState: _ProjectionRead_T3Poll = state._projected_state_for_T3Poll();
                let _OpCache_with_parameter_T3Poll: immutable.Map = this._OpCache_T3Poll.get(_trid_17);
                if(_OpCache_with_parameter_T3Poll != null) {
                    let writeState: _ProjectionWrite_T3Poll = _OpCache_with_parameter_T3Poll.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_T3Poll(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.T3Poll();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_T3Poll();
                        _OpCache_with_parameter_T3Poll = _OpCache_with_parameter_T3Poll.set(readState, writeState);
                        this._OpCache_T3Poll = this._OpCache_T3Poll.set(_trid_17, _OpCache_with_parameter_T3Poll);
                    }

                } else {
                    copiedState.T3Poll();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_T3Poll = copiedState._update_for_T3Poll();
                    _OpCache_with_parameter_T3Poll = new immutable.Map().set(readState, writeState);
                    this._OpCache_T3Poll = this._OpCache_T3Poll.set(_trid_17, _OpCache_with_parameter_T3Poll);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_T3ReleaseBus_state : _ProjectionRead__tr_T3ReleaseBus = state._projected_state_for__tr_T3ReleaseBus();
            let _trid_18 : BSet<BInteger>  = this._OpCache_tr_T3ReleaseBus.get(read__tr_T3ReleaseBus_state);
            if(_trid_18 == null) {
                _trid_18 = state._tr_T3ReleaseBus();
                this._OpCache_tr_T3ReleaseBus = this._OpCache_tr_T3ReleaseBus.set(read__tr_T3ReleaseBus_state, _trid_18);
            }

            for(let param of _trid_18) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                let readState: _ProjectionRead_T3ReleaseBus = state._projected_state_for_T3ReleaseBus();
                let _OpCache_with_parameter_T3ReleaseBus: immutable.Map = this._OpCache_T3ReleaseBus.get(param);
                if(_OpCache_with_parameter_T3ReleaseBus != null) {
                    let writeState: _ProjectionWrite_T3ReleaseBus = _OpCache_with_parameter_T3ReleaseBus.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_T3ReleaseBus(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.T3ReleaseBus(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_T3ReleaseBus();
                        _OpCache_with_parameter_T3ReleaseBus = _OpCache_with_parameter_T3ReleaseBus.set(readState, writeState);
                        this._OpCache_T3ReleaseBus = this._OpCache_T3ReleaseBus.set(param, _OpCache_with_parameter_T3ReleaseBus);
                    }

                } else {
                    copiedState.T3ReleaseBus(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_T3ReleaseBus = copiedState._update_for_T3ReleaseBus();
                    _OpCache_with_parameter_T3ReleaseBus = new immutable.Map().set(readState, writeState);
                    this._OpCache_T3ReleaseBus = this._OpCache_T3ReleaseBus.set(param, _OpCache_with_parameter_T3ReleaseBus);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_T3Wait_state : _ProjectionRead__tr_T3Wait = state._projected_state_for__tr_T3Wait();
            let _obj__trid_19: any = this._OpCache_tr_T3Wait.get(read__tr_T3Wait_state);
            let _trid_19: boolean;
            if(_obj__trid_19 == null) {
                _trid_19 = state._tr_T3Wait();
                this._OpCache_tr_T3Wait = this._OpCache_tr_T3Wait.set(read__tr_T3Wait_state, _trid_19);
            } else {
                _trid_19 = _obj__trid_19;
            }

            if(_trid_19) {
                let copiedState: CAN_BUS_tlc = state._copy();
                let readState: _ProjectionRead_T3Wait = state._projected_state_for_T3Wait();
                let _OpCache_with_parameter_T3Wait: immutable.Map = this._OpCache_T3Wait.get(_trid_19);
                if(_OpCache_with_parameter_T3Wait != null) {
                    let writeState: _ProjectionWrite_T3Wait = _OpCache_with_parameter_T3Wait.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_T3Wait(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.T3Wait();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_T3Wait();
                        _OpCache_with_parameter_T3Wait = _OpCache_with_parameter_T3Wait.set(readState, writeState);
                        this._OpCache_T3Wait = this._OpCache_T3Wait.set(_trid_19, _OpCache_with_parameter_T3Wait);
                    }

                } else {
                    copiedState.T3Wait();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_T3Wait = copiedState._update_for_T3Wait();
                    _OpCache_with_parameter_T3Wait = new immutable.Map().set(readState, writeState);
                    this._OpCache_T3Wait = this._OpCache_T3Wait.set(_trid_19, _OpCache_with_parameter_T3Wait);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_T3ReEnableWait_state : _ProjectionRead__tr_T3ReEnableWait = state._projected_state_for__tr_T3ReEnableWait();
            let _obj__trid_20: any = this._OpCache_tr_T3ReEnableWait.get(read__tr_T3ReEnableWait_state);
            let _trid_20: boolean;
            if(_obj__trid_20 == null) {
                _trid_20 = state._tr_T3ReEnableWait();
                this._OpCache_tr_T3ReEnableWait = this._OpCache_tr_T3ReEnableWait.set(read__tr_T3ReEnableWait_state, _trid_20);
            } else {
                _trid_20 = _obj__trid_20;
            }

            if(_trid_20) {
                let copiedState: CAN_BUS_tlc = state._copy();
                let readState: _ProjectionRead_T3ReEnableWait = state._projected_state_for_T3ReEnableWait();
                let _OpCache_with_parameter_T3ReEnableWait: immutable.Map = this._OpCache_T3ReEnableWait.get(_trid_20);
                if(_OpCache_with_parameter_T3ReEnableWait != null) {
                    let writeState: _ProjectionWrite_T3ReEnableWait = _OpCache_with_parameter_T3ReEnableWait.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_T3ReEnableWait(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.T3ReEnableWait();
                        copiedState.parent = state;
                        writeState = copiedState._update_for_T3ReEnableWait();
                        _OpCache_with_parameter_T3ReEnableWait = _OpCache_with_parameter_T3ReEnableWait.set(readState, writeState);
                        this._OpCache_T3ReEnableWait = this._OpCache_T3ReEnableWait.set(_trid_20, _OpCache_with_parameter_T3ReEnableWait);
                    }

                } else {
                    copiedState.T3ReEnableWait();
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_T3ReEnableWait = copiedState._update_for_T3ReEnableWait();
                    _OpCache_with_parameter_T3ReEnableWait = new immutable.Map().set(readState, writeState);
                    this._OpCache_T3ReEnableWait = this._OpCache_T3ReEnableWait.set(_trid_20, _OpCache_with_parameter_T3ReEnableWait);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_Update_state : _ProjectionRead__tr_Update = state._projected_state_for__tr_Update();
            let _trid_21 : BSet<BInteger>  = this._OpCache_tr_Update.get(read__tr_Update_state);
            if(_trid_21 == null) {
                _trid_21 = state._tr_Update();
                this._OpCache_tr_Update = this._OpCache_tr_Update.set(read__tr_Update_state, _trid_21);
            }

            for(let param of _trid_21) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                let readState: _ProjectionRead_Update = state._projected_state_for_Update();
                let _OpCache_with_parameter_Update: immutable.Map = this._OpCache_Update.get(param);
                if(_OpCache_with_parameter_Update != null) {
                    let writeState: _ProjectionWrite_Update = _OpCache_with_parameter_Update.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_Update(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.Update(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_Update();
                        _OpCache_with_parameter_Update = _OpCache_with_parameter_Update.set(readState, writeState);
                        this._OpCache_Update = this._OpCache_Update.set(param, _OpCache_with_parameter_Update);
                    }

                } else {
                    copiedState.Update(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_Update = copiedState._update_for_Update();
                    _OpCache_with_parameter_Update = new immutable.Map().set(readState, writeState);
                    this._OpCache_Update = this._OpCache_Update.set(param, _OpCache_with_parameter_Update);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        } else {
            if(state._tr_T1Evaluate()) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T1Evaluate();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_2: BSet<BInteger> = state._tr_T1Calculate();
            for(let param of _trid_2) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T1Calculate(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_3: BSet<BTuple<BInteger, BInteger>> = state._tr_T1SendResult();
            for(let param of _trid_3) {
                let _tmp_1: BInteger = param.projection2();
                let _tmp_2: BInteger = param.projection1();

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T1SendResult(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_4: BSet<BInteger> = state._tr_T1Wait();
            for(let param of _trid_4) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T1Wait(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_T2Evaluate()) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2Evaluate();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_6: BSet<BTuple<BInteger, BInteger>> = state._tr_T2ReadBus();
            for(let param of _trid_6) {
                let _tmp_1: BInteger = param.projection2();
                let _tmp_2: BInteger = param.projection1();

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2ReadBus(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_T2Reset()) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2Reset();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_T2Complete()) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2Complete();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_9: BSet<BInteger> = state._tr_T2ReleaseBus();
            for(let param of _trid_9) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2ReleaseBus(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_T2Calculate()) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2Calculate();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_11: BSet<BTuple<BInteger, BInteger>> = state._tr_T2WriteBus();
            for(let param of _trid_11) {
                let _tmp_1: BInteger = param.projection2();
                let _tmp_2: BInteger = param.projection1();

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2WriteBus(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_12: BSet<BInteger> = state._tr_T2Wait();
            for(let param of _trid_12) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2Wait(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_T3Initiate()) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3Initiate();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_T3Evaluate()) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3Evaluate();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_15: BSet<BTuple<BInteger, BInteger>> = state._tr_T3writebus();
            for(let param of _trid_15) {
                let _tmp_1: BInteger = param.projection2();
                let _tmp_2: BInteger = param.projection1();

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3writebus(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_16: BSet<BTuple<BInteger, BInteger>> = state._tr_T3Read();
            for(let param of _trid_16) {
                let _tmp_1: BInteger = param.projection2();
                let _tmp_2: BInteger = param.projection1();

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3Read(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_T3Poll()) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3Poll();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_18: BSet<BInteger> = state._tr_T3ReleaseBus();
            for(let param of _trid_18) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3ReleaseBus(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_T3Wait()) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3Wait();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_T3ReEnableWait()) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3ReEnableWait();
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_21: BSet<BInteger> = state._tr_Update();
            for(let param of _trid_21) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.Update(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        }
        return result;
    }

    invViolated(state: CAN_BUS_tlc): boolean {
        let _check_inv_1: boolean;
        if(isCaching) {
            let read__check_inv_1_state: _ProjectionRead__check_inv_1 = state._projected_state_for__check_inv_1();
            let _obj__check_inv_1: boolean = this._InvCache__check_inv_1.get(read__check_inv_1_state);
            if(_obj__check_inv_1 == null) {
                _check_inv_1 = state._check_inv_1();
                this._InvCache__check_inv_1 = this._InvCache__check_inv_1.set(read__check_inv_1_state, _check_inv_1);
            } else {
                _check_inv_1 = _obj__check_inv_1;
            }
        } else {
            _check_inv_1 = state._check_inv_1();
        }
        if(!_check_inv_1) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_1");
            return true;
        }
        let _check_inv_2: boolean;
        if(isCaching) {
            let read__check_inv_2_state: _ProjectionRead__check_inv_2 = state._projected_state_for__check_inv_2();
            let _obj__check_inv_2: boolean = this._InvCache__check_inv_2.get(read__check_inv_2_state);
            if(_obj__check_inv_2 == null) {
                _check_inv_2 = state._check_inv_2();
                this._InvCache__check_inv_2 = this._InvCache__check_inv_2.set(read__check_inv_2_state, _check_inv_2);
            } else {
                _check_inv_2 = _obj__check_inv_2;
            }
        } else {
            _check_inv_2 = state._check_inv_2();
        }
        if(!_check_inv_2) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_2");
            return true;
        }
        let _check_inv_3: boolean;
        if(isCaching) {
            let read__check_inv_3_state: _ProjectionRead__check_inv_3 = state._projected_state_for__check_inv_3();
            let _obj__check_inv_3: boolean = this._InvCache__check_inv_3.get(read__check_inv_3_state);
            if(_obj__check_inv_3 == null) {
                _check_inv_3 = state._check_inv_3();
                this._InvCache__check_inv_3 = this._InvCache__check_inv_3.set(read__check_inv_3_state, _check_inv_3);
            } else {
                _check_inv_3 = _obj__check_inv_3;
            }
        } else {
            _check_inv_3 = state._check_inv_3();
        }
        if(!_check_inv_3) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_3");
            return true;
        }
        let _check_inv_4: boolean;
        if(isCaching) {
            let read__check_inv_4_state: _ProjectionRead__check_inv_4 = state._projected_state_for__check_inv_4();
            let _obj__check_inv_4: boolean = this._InvCache__check_inv_4.get(read__check_inv_4_state);
            if(_obj__check_inv_4 == null) {
                _check_inv_4 = state._check_inv_4();
                this._InvCache__check_inv_4 = this._InvCache__check_inv_4.set(read__check_inv_4_state, _check_inv_4);
            } else {
                _check_inv_4 = _obj__check_inv_4;
            }
        } else {
            _check_inv_4 = state._check_inv_4();
        }
        if(!_check_inv_4) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_4");
            return true;
        }
        let _check_inv_5: boolean;
        if(isCaching) {
            let read__check_inv_5_state: _ProjectionRead__check_inv_5 = state._projected_state_for__check_inv_5();
            let _obj__check_inv_5: boolean = this._InvCache__check_inv_5.get(read__check_inv_5_state);
            if(_obj__check_inv_5 == null) {
                _check_inv_5 = state._check_inv_5();
                this._InvCache__check_inv_5 = this._InvCache__check_inv_5.set(read__check_inv_5_state, _check_inv_5);
            } else {
                _check_inv_5 = _obj__check_inv_5;
            }
        } else {
            _check_inv_5 = state._check_inv_5();
        }
        if(!_check_inv_5) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_5");
            return true;
        }
        let _check_inv_6: boolean;
        if(isCaching) {
            let read__check_inv_6_state: _ProjectionRead__check_inv_6 = state._projected_state_for__check_inv_6();
            let _obj__check_inv_6: boolean = this._InvCache__check_inv_6.get(read__check_inv_6_state);
            if(_obj__check_inv_6 == null) {
                _check_inv_6 = state._check_inv_6();
                this._InvCache__check_inv_6 = this._InvCache__check_inv_6.set(read__check_inv_6_state, _check_inv_6);
            } else {
                _check_inv_6 = _obj__check_inv_6;
            }
        } else {
            _check_inv_6 = state._check_inv_6();
        }
        if(!_check_inv_6) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_6");
            return true;
        }
        let _check_inv_7: boolean;
        if(isCaching) {
            let read__check_inv_7_state: _ProjectionRead__check_inv_7 = state._projected_state_for__check_inv_7();
            let _obj__check_inv_7: boolean = this._InvCache__check_inv_7.get(read__check_inv_7_state);
            if(_obj__check_inv_7 == null) {
                _check_inv_7 = state._check_inv_7();
                this._InvCache__check_inv_7 = this._InvCache__check_inv_7.set(read__check_inv_7_state, _check_inv_7);
            } else {
                _check_inv_7 = _obj__check_inv_7;
            }
        } else {
            _check_inv_7 = state._check_inv_7();
        }
        if(!_check_inv_7) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_7");
            return true;
        }
        let _check_inv_8: boolean;
        if(isCaching) {
            let read__check_inv_8_state: _ProjectionRead__check_inv_8 = state._projected_state_for__check_inv_8();
            let _obj__check_inv_8: boolean = this._InvCache__check_inv_8.get(read__check_inv_8_state);
            if(_obj__check_inv_8 == null) {
                _check_inv_8 = state._check_inv_8();
                this._InvCache__check_inv_8 = this._InvCache__check_inv_8.set(read__check_inv_8_state, _check_inv_8);
            } else {
                _check_inv_8 = _obj__check_inv_8;
            }
        } else {
            _check_inv_8 = state._check_inv_8();
        }
        if(!_check_inv_8) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_8");
            return true;
        }
        let _check_inv_9: boolean;
        if(isCaching) {
            let read__check_inv_9_state: _ProjectionRead__check_inv_9 = state._projected_state_for__check_inv_9();
            let _obj__check_inv_9: boolean = this._InvCache__check_inv_9.get(read__check_inv_9_state);
            if(_obj__check_inv_9 == null) {
                _check_inv_9 = state._check_inv_9();
                this._InvCache__check_inv_9 = this._InvCache__check_inv_9.set(read__check_inv_9_state, _check_inv_9);
            } else {
                _check_inv_9 = _obj__check_inv_9;
            }
        } else {
            _check_inv_9 = state._check_inv_9();
        }
        if(!_check_inv_9) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_9");
            return true;
        }
        let _check_inv_10: boolean;
        if(isCaching) {
            let read__check_inv_10_state: _ProjectionRead__check_inv_10 = state._projected_state_for__check_inv_10();
            let _obj__check_inv_10: boolean = this._InvCache__check_inv_10.get(read__check_inv_10_state);
            if(_obj__check_inv_10 == null) {
                _check_inv_10 = state._check_inv_10();
                this._InvCache__check_inv_10 = this._InvCache__check_inv_10.set(read__check_inv_10_state, _check_inv_10);
            } else {
                _check_inv_10 = _obj__check_inv_10;
            }
        } else {
            _check_inv_10 = state._check_inv_10();
        }
        if(!_check_inv_10) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_10");
            return true;
        }
        let _check_inv_11: boolean;
        if(isCaching) {
            let read__check_inv_11_state: _ProjectionRead__check_inv_11 = state._projected_state_for__check_inv_11();
            let _obj__check_inv_11: boolean = this._InvCache__check_inv_11.get(read__check_inv_11_state);
            if(_obj__check_inv_11 == null) {
                _check_inv_11 = state._check_inv_11();
                this._InvCache__check_inv_11 = this._InvCache__check_inv_11.set(read__check_inv_11_state, _check_inv_11);
            } else {
                _check_inv_11 = _obj__check_inv_11;
            }
        } else {
            _check_inv_11 = state._check_inv_11();
        }
        if(!_check_inv_11) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_11");
            return true;
        }
        let _check_inv_12: boolean;
        if(isCaching) {
            let read__check_inv_12_state: _ProjectionRead__check_inv_12 = state._projected_state_for__check_inv_12();
            let _obj__check_inv_12: boolean = this._InvCache__check_inv_12.get(read__check_inv_12_state);
            if(_obj__check_inv_12 == null) {
                _check_inv_12 = state._check_inv_12();
                this._InvCache__check_inv_12 = this._InvCache__check_inv_12.set(read__check_inv_12_state, _check_inv_12);
            } else {
                _check_inv_12 = _obj__check_inv_12;
            }
        } else {
            _check_inv_12 = state._check_inv_12();
        }
        if(!_check_inv_12) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_12");
            return true;
        }
        let _check_inv_13: boolean;
        if(isCaching) {
            let read__check_inv_13_state: _ProjectionRead__check_inv_13 = state._projected_state_for__check_inv_13();
            let _obj__check_inv_13: boolean = this._InvCache__check_inv_13.get(read__check_inv_13_state);
            if(_obj__check_inv_13 == null) {
                _check_inv_13 = state._check_inv_13();
                this._InvCache__check_inv_13 = this._InvCache__check_inv_13.set(read__check_inv_13_state, _check_inv_13);
            } else {
                _check_inv_13 = _obj__check_inv_13;
            }
        } else {
            _check_inv_13 = state._check_inv_13();
        }
        if(!_check_inv_13) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_13");
            return true;
        }
        let _check_inv_14: boolean;
        if(isCaching) {
            let read__check_inv_14_state: _ProjectionRead__check_inv_14 = state._projected_state_for__check_inv_14();
            let _obj__check_inv_14: boolean = this._InvCache__check_inv_14.get(read__check_inv_14_state);
            if(_obj__check_inv_14 == null) {
                _check_inv_14 = state._check_inv_14();
                this._InvCache__check_inv_14 = this._InvCache__check_inv_14.set(read__check_inv_14_state, _check_inv_14);
            } else {
                _check_inv_14 = _obj__check_inv_14;
            }
        } else {
            _check_inv_14 = state._check_inv_14();
        }
        if(!_check_inv_14) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_14");
            return true;
        }
        let _check_inv_15: boolean;
        if(isCaching) {
            let read__check_inv_15_state: _ProjectionRead__check_inv_15 = state._projected_state_for__check_inv_15();
            let _obj__check_inv_15: boolean = this._InvCache__check_inv_15.get(read__check_inv_15_state);
            if(_obj__check_inv_15 == null) {
                _check_inv_15 = state._check_inv_15();
                this._InvCache__check_inv_15 = this._InvCache__check_inv_15.set(read__check_inv_15_state, _check_inv_15);
            } else {
                _check_inv_15 = _obj__check_inv_15;
            }
        } else {
            _check_inv_15 = state._check_inv_15();
        }
        if(!_check_inv_15) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_15");
            return true;
        }
        let _check_inv_16: boolean;
        if(isCaching) {
            let read__check_inv_16_state: _ProjectionRead__check_inv_16 = state._projected_state_for__check_inv_16();
            let _obj__check_inv_16: boolean = this._InvCache__check_inv_16.get(read__check_inv_16_state);
            if(_obj__check_inv_16 == null) {
                _check_inv_16 = state._check_inv_16();
                this._InvCache__check_inv_16 = this._InvCache__check_inv_16.set(read__check_inv_16_state, _check_inv_16);
            } else {
                _check_inv_16 = _obj__check_inv_16;
            }
        } else {
            _check_inv_16 = state._check_inv_16();
        }
        if(!_check_inv_16) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_16");
            return true;
        }
        let _check_inv_17: boolean;
        if(isCaching) {
            let read__check_inv_17_state: _ProjectionRead__check_inv_17 = state._projected_state_for__check_inv_17();
            let _obj__check_inv_17: boolean = this._InvCache__check_inv_17.get(read__check_inv_17_state);
            if(_obj__check_inv_17 == null) {
                _check_inv_17 = state._check_inv_17();
                this._InvCache__check_inv_17 = this._InvCache__check_inv_17.set(read__check_inv_17_state, _check_inv_17);
            } else {
                _check_inv_17 = _obj__check_inv_17;
            }
        } else {
            _check_inv_17 = state._check_inv_17();
        }
        if(!_check_inv_17) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_17");
            return true;
        }
        let _check_inv_18: boolean;
        if(isCaching) {
            let read__check_inv_18_state: _ProjectionRead__check_inv_18 = state._projected_state_for__check_inv_18();
            let _obj__check_inv_18: boolean = this._InvCache__check_inv_18.get(read__check_inv_18_state);
            if(_obj__check_inv_18 == null) {
                _check_inv_18 = state._check_inv_18();
                this._InvCache__check_inv_18 = this._InvCache__check_inv_18.set(read__check_inv_18_state, _check_inv_18);
            } else {
                _check_inv_18 = _obj__check_inv_18;
            }
        } else {
            _check_inv_18 = state._check_inv_18();
        }
        if(!_check_inv_18) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_18");
            return true;
        }
        let _check_inv_19: boolean;
        if(isCaching) {
            let read__check_inv_19_state: _ProjectionRead__check_inv_19 = state._projected_state_for__check_inv_19();
            let _obj__check_inv_19: boolean = this._InvCache__check_inv_19.get(read__check_inv_19_state);
            if(_obj__check_inv_19 == null) {
                _check_inv_19 = state._check_inv_19();
                this._InvCache__check_inv_19 = this._InvCache__check_inv_19.set(read__check_inv_19_state, _check_inv_19);
            } else {
                _check_inv_19 = _obj__check_inv_19;
            }
        } else {
            _check_inv_19 = state._check_inv_19();
        }
        if(!_check_inv_19) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_19");
            return true;
        }
        let _check_inv_20: boolean;
        if(isCaching) {
            let read__check_inv_20_state: _ProjectionRead__check_inv_20 = state._projected_state_for__check_inv_20();
            let _obj__check_inv_20: boolean = this._InvCache__check_inv_20.get(read__check_inv_20_state);
            if(_obj__check_inv_20 == null) {
                _check_inv_20 = state._check_inv_20();
                this._InvCache__check_inv_20 = this._InvCache__check_inv_20.set(read__check_inv_20_state, _check_inv_20);
            } else {
                _check_inv_20 = _obj__check_inv_20;
            }
        } else {
            _check_inv_20 = state._check_inv_20();
        }
        if(!_check_inv_20) {
            console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_20");
            return true;
        }
        return false;
    }

    printResult(states: number, transitions: number): void {
        if(this.invariantViolated || this.deadlockDetected) {
            if(this.deadlockDetected) {
                console.log("DEADLOCK DETECTED");
            } else {
                console.log("INVARIANT VIOLATED");
            }

            console.log("COUNTER EXAMPLE TRACE: ");
            let sb: string = '';
            while(this.counterExampleState != null) {
                sb = this.counterExampleState + '\n' + sb;
                if(this.counterExampleState.stateAccessedVia != null) {
                    sb = this.counterExampleState.stateAccessedVia + sb;
                }
                sb = '\n\n' + sb;
                this.counterExampleState = this.counterExampleState.parent;
            }
            console.log(sb);
        } else {
            console.log("MODEL CHECKING SUCCESSFUL");
        }

        console.log("Number of States: " + this.states.size);
        console.log("Number of Transitions: " + this.transitions);
    }
}


let args : string[] = process.argv;
if(args.length > 5) {
    console.log("Expecting 3 command-line arguments: STRATEGY CACHING DEBUG");
    process.exit(-1);
}
let type: Type = Type.MIXED;
let threads: number = 0;
let isCaching: boolean = false;
let isDebug: boolean = false;

if(args.length > 2) {
    if("mixed" === args[2]) {
        type = Type.MIXED;
    } else if("bf" === args[2]) {
        type = Type.BFS;
    } else if ("df" === args[2]) {
        type = Type.DFS;
    } else {
        console.log("Value for command-line argument STRATEGY is wrong.");
        console.log("Expecting mixed, bf or df.");
        process.exit(-1);
    }
}
if(args.length > 3) {
    try {
        isCaching = JSON.parse(args[3].toLowerCase());
    } catch(e) {
        console.log("Value for command-line argument CACHING is not a boolean.");
        process.exit(-1);
    }
}
if(args.length > 4) {
    try {
        isDebug = JSON.parse(args[4].toLowerCase());
    } catch(e) {
        console.log("Value for command-line argument DEBUG is not a boolean.");
        process.exit(-1);
    }
}
let modelchecker: ModelChecker = new ModelChecker(type, isCaching, isDebug);
modelchecker.modelCheck();

