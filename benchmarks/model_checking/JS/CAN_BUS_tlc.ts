import {BTuple} from './btypes/BTuple.js';
import {BInteger} from './btypes/BInteger.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BRelation} from './btypes/BRelation.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BUtils} from "./btypes/BUtils.js";
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


export enum Type {
    BFS,
    DFS,
    MIXED
}

export default class CAN_BUS_tlc {

    parent: CAN_BUS_tlc;
    dependentGuard: immutable.Set<string> = immutable.Set();
    guardCache: immutable.Map = immutable.Map();
    dependentInvariant: immutable.Set<string> = immutable.Set();
    stateAccessedVia: string;


    private static NATSET: BSet<BInteger>;

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

    _tr_T1Evaluate(): boolean {
        return new BBoolean(this.T1_timer.equal(new BInteger(0)).booleanValue() && this.T1_state.equal(new T1state(enum_T1state.T1_EN)).booleanValue()).booleanValue();
    }

    _tr_T1Calculate(): BSet<BInteger> {
        let _ic_set_1: BSet<BInteger> = new BSet<BInteger>();
        for(let _ic_p_1 of BSet.interval(new BInteger(1).negative(), new BInteger(3))) {
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
            if((new BBoolean(this.BUSwrite.domain().elementOf(_ic_ppriority_1).booleanValue() && this.T2_state.equal(new T2state(enum_T2state.T2_RELEASE)).booleanValue())).booleanValue()) {
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

    _check_inv_1() {
        return this.T2v.isInteger().booleanValue();
    }

    _check_inv_2() {
        return BUtils.BOOL.elementOf(this.T3_evaluated).booleanValue();
    }

    _check_inv_3() {
        return BUtils.BOOL.elementOf(this.T3_enabled).booleanValue();
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
        return this.BUSwrite.domain().elementOf(new BInteger(0)).booleanValue();
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

    private invariantDependency: immutable.Map<string, immutable.Set<string>> = new immutable.Map();
    private guardDependency: immutable.Map<string, immutable.Set<string>> = new immutable.Map();

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

        if(this.isCaching) {
            this.initCache(machine);
        }

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

    initCache(machine: CAN_BUS_tlc ): void {
        this.invariantDependency = this.invariantDependency.set("T1Wait", immutable.Set(["_check_inv_10", "_check_inv_4"]));
        this.invariantDependency = this.invariantDependency.set("T1Calculate", immutable.Set(["_check_inv_7", "_check_inv_4"]));
        this.invariantDependency = this.invariantDependency.set("T1SendResult", immutable.Set(["_check_inv_18", "_check_inv_19", "_check_inv_20", "_check_inv_4"]));
        this.invariantDependency = this.invariantDependency.set("T2ReadBus", immutable.Set(["_check_inv_17", "_check_inv_5", "_check_inv_9"]));
        this.invariantDependency = this.invariantDependency.set("T2Reset", immutable.Set(["_check_inv_1", "_check_inv_5", "_check_inv_8", "_check_inv_12"]));
        this.invariantDependency = this.invariantDependency.set("T2Complete", immutable.Set(["_check_inv_5", "_check_inv_12"]));
        this.invariantDependency = this.invariantDependency.set("T2Evaluate", immutable.Set(["_check_inv_5", "_check_inv_11"]));
        this.invariantDependency = this.invariantDependency.set("T3Evaluate", immutable.Set(["_check_inv_6"]));
        this.invariantDependency = this.invariantDependency.set("T3ReleaseBus", immutable.Set(["_check_inv_18", "_check_inv_19", "_check_inv_6", "_check_inv_20"]));
        this.invariantDependency = this.invariantDependency.set("T1Evaluate", immutable.Set(["_check_inv_10", "_check_inv_4"]));
        this.invariantDependency = this.invariantDependency.set("T3Initiate", immutable.Set(["_check_inv_3", "_check_inv_6"]));
        this.invariantDependency = this.invariantDependency.set("T3ReEnableWait", immutable.Set(["_check_inv_2", "_check_inv_3", "_check_inv_6"]));
        this.invariantDependency = this.invariantDependency.set("T3writebus", immutable.Set(["_check_inv_18", "_check_inv_19", "_check_inv_6", "_check_inv_20"]));
        this.invariantDependency = this.invariantDependency.set("Update", immutable.Set(["_check_inv_2", "_check_inv_10", "_check_inv_14", "_check_inv_13", "_check_inv_11"]));
        this.invariantDependency = this.invariantDependency.set("T2ReleaseBus", immutable.Set(["_check_inv_18", "_check_inv_19", "_check_inv_20", "_check_inv_5"]));
        this.invariantDependency = this.invariantDependency.set("T2Wait", immutable.Set(["_check_inv_5", "_check_inv_11"]));
        this.invariantDependency = this.invariantDependency.set("T3Poll", immutable.Set(["_check_inv_6"]));
        this.invariantDependency = this.invariantDependency.set("T2Calculate", immutable.Set(["_check_inv_1", "_check_inv_5"]));
        this.invariantDependency = this.invariantDependency.set("T3Read", immutable.Set(["_check_inv_16", "_check_inv_15", "_check_inv_6"]));
        this.invariantDependency = this.invariantDependency.set("T3Wait", immutable.Set(["_check_inv_2", "_check_inv_6"]));
        this.invariantDependency = this.invariantDependency.set("T2WriteBus", immutable.Set(["_check_inv_18", "_check_inv_19", "_check_inv_20", "_check_inv_5"]));
        this.guardDependency = this.guardDependency.set("T1Wait", immutable.Set(["_tr_T1Evaluate", "_tr_Update", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"]));
        this.guardDependency = this.guardDependency.set("T1Calculate", immutable.Set(["_tr_T1Evaluate", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"]));
        this.guardDependency = this.guardDependency.set("T1SendResult", immutable.Set(["_tr_T1Evaluate", "_tr_T2ReleaseBus", "_tr_Update", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"]));
        this.guardDependency = this.guardDependency.set("T2ReadBus", immutable.Set(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
        this.guardDependency = this.guardDependency.set("T2Reset", immutable.Set(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
        this.guardDependency = this.guardDependency.set("T2Complete", immutable.Set(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
        this.guardDependency = this.guardDependency.set("T2Evaluate", immutable.Set(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
        this.guardDependency = this.guardDependency.set("T3Evaluate", immutable.Set(["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
        this.guardDependency = this.guardDependency.set("T3ReleaseBus", immutable.Set(["_tr_T2ReleaseBus", "_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
        this.guardDependency = this.guardDependency.set("T1Evaluate", immutable.Set(["_tr_T1Evaluate", "_tr_Update", "_tr_T1SendResult", "_tr_T1Calculate", "_tr_T1Wait"]));
        this.guardDependency = this.guardDependency.set("T3Initiate", immutable.Set(["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
        this.guardDependency = this.guardDependency.set("T3ReEnableWait", immutable.Set(["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
        this.guardDependency = this.guardDependency.set("T3writebus", immutable.Set(["_tr_T2ReleaseBus", "_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
        this.guardDependency = this.guardDependency.set("Update", immutable.Set(["_tr_T1Evaluate", "_tr_T3Read", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T3Evaluate", "_tr_T3Initiate"]));
        this.guardDependency = this.guardDependency.set("T2ReleaseBus", immutable.Set(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
        this.guardDependency = this.guardDependency.set("T2Wait", immutable.Set(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
        this.guardDependency = this.guardDependency.set("T3Poll", immutable.Set(["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
        this.guardDependency = this.guardDependency.set("T2Calculate", immutable.Set(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
        this.guardDependency = this.guardDependency.set("T3Read", immutable.Set(["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
        this.guardDependency = this.guardDependency.set("T3Wait", immutable.Set(["_tr_T3writebus", "_tr_T3Read", "_tr_T3ReleaseBus", "_tr_T3Poll", "_tr_Update", "_tr_T3ReEnableWait", "_tr_T3Evaluate", "_tr_T3Wait", "_tr_T3Initiate"]));
        this.guardDependency = this.guardDependency.set("T2WriteBus", immutable.Set(["_tr_T2Reset", "_tr_T2ReleaseBus", "_tr_T2Complete", "_tr_T2Calculate", "_tr_T2Evaluate", "_tr_Update", "_tr_T2ReadBus", "_tr_T2WriteBus", "_tr_T2Wait"]));
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
            let parentsGuard: immutable.Map = state.guardCache;
            let newCache: immutable.Map = parentsGuard == null ? immutable.Map() : parentsGuard;
            let cachedValue: any = null;
            let dependentGuardsBoolean: boolean = true;
            let _trid_1: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_T1Evaluate");
                dependentGuardsBoolean = "_tr_T1Evaluate" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_1 = state._tr_T1Evaluate();
            } else {
                _trid_1 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_T1Evaluate", _trid_1);
            if(_trid_1) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T1Evaluate();
                copiedState.parent = state;
                this.addCachedInfos("T1Evaluate", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_2: BSet<BInteger>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_T1Calculate");
                dependentGuardsBoolean = "_tr_T1Calculate" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_2 = state._tr_T1Calculate();
            } else {
                _trid_2 = cachedValue as BSet<BInteger>;
            }
            newCache = newCache.set("_tr_T1Calculate", _trid_2);
            for(let param of _trid_2) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T1Calculate(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("T1Calculate", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_3: BSet<BTuple<BInteger, BInteger>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_T1SendResult");
                dependentGuardsBoolean = "_tr_T1SendResult" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_3 = state._tr_T1SendResult();
            } else {
                _trid_3 = cachedValue as BSet<BTuple<BInteger, BInteger>>;
            }
            newCache = newCache.set("_tr_T1SendResult", _trid_3);
            for(let param of _trid_3) {
                let _tmp_1: BInteger = param.projection2();
                let _tmp_2: BInteger = param.projection1();

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T1SendResult(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("T1SendResult", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_4: BSet<BInteger>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_T1Wait");
                dependentGuardsBoolean = "_tr_T1Wait" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_4 = state._tr_T1Wait();
            } else {
                _trid_4 = cachedValue as BSet<BInteger>;
            }
            newCache = newCache.set("_tr_T1Wait", _trid_4);
            for(let param of _trid_4) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T1Wait(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("T1Wait", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_5: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_T2Evaluate");
                dependentGuardsBoolean = "_tr_T2Evaluate" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_5 = state._tr_T2Evaluate();
            } else {
                _trid_5 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_T2Evaluate", _trid_5);
            if(_trid_5) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2Evaluate();
                copiedState.parent = state;
                this.addCachedInfos("T2Evaluate", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_6: BSet<BTuple<BInteger, BInteger>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_T2ReadBus");
                dependentGuardsBoolean = "_tr_T2ReadBus" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_6 = state._tr_T2ReadBus();
            } else {
                _trid_6 = cachedValue as BSet<BTuple<BInteger, BInteger>>;
            }
            newCache = newCache.set("_tr_T2ReadBus", _trid_6);
            for(let param of _trid_6) {
                let _tmp_1: BInteger = param.projection2();
                let _tmp_2: BInteger = param.projection1();

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2ReadBus(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("T2ReadBus", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_7: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_T2Reset");
                dependentGuardsBoolean = "_tr_T2Reset" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_7 = state._tr_T2Reset();
            } else {
                _trid_7 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_T2Reset", _trid_7);
            if(_trid_7) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2Reset();
                copiedState.parent = state;
                this.addCachedInfos("T2Reset", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_8: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_T2Complete");
                dependentGuardsBoolean = "_tr_T2Complete" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_8 = state._tr_T2Complete();
            } else {
                _trid_8 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_T2Complete", _trid_8);
            if(_trid_8) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2Complete();
                copiedState.parent = state;
                this.addCachedInfos("T2Complete", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_9: BSet<BInteger>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_T2ReleaseBus");
                dependentGuardsBoolean = "_tr_T2ReleaseBus" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_9 = state._tr_T2ReleaseBus();
            } else {
                _trid_9 = cachedValue as BSet<BInteger>;
            }
            newCache = newCache.set("_tr_T2ReleaseBus", _trid_9);
            for(let param of _trid_9) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2ReleaseBus(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("T2ReleaseBus", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_10: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_T2Calculate");
                dependentGuardsBoolean = "_tr_T2Calculate" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_10 = state._tr_T2Calculate();
            } else {
                _trid_10 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_T2Calculate", _trid_10);
            if(_trid_10) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2Calculate();
                copiedState.parent = state;
                this.addCachedInfos("T2Calculate", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_11: BSet<BTuple<BInteger, BInteger>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_T2WriteBus");
                dependentGuardsBoolean = "_tr_T2WriteBus" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_11 = state._tr_T2WriteBus();
            } else {
                _trid_11 = cachedValue as BSet<BTuple<BInteger, BInteger>>;
            }
            newCache = newCache.set("_tr_T2WriteBus", _trid_11);
            for(let param of _trid_11) {
                let _tmp_1: BInteger = param.projection2();
                let _tmp_2: BInteger = param.projection1();

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2WriteBus(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("T2WriteBus", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_12: BSet<BInteger>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_T2Wait");
                dependentGuardsBoolean = "_tr_T2Wait" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_12 = state._tr_T2Wait();
            } else {
                _trid_12 = cachedValue as BSet<BInteger>;
            }
            newCache = newCache.set("_tr_T2Wait", _trid_12);
            for(let param of _trid_12) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2Wait(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("T2Wait", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_13: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_T3Initiate");
                dependentGuardsBoolean = "_tr_T3Initiate" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_13 = state._tr_T3Initiate();
            } else {
                _trid_13 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_T3Initiate", _trid_13);
            if(_trid_13) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3Initiate();
                copiedState.parent = state;
                this.addCachedInfos("T3Initiate", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_14: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_T3Evaluate");
                dependentGuardsBoolean = "_tr_T3Evaluate" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_14 = state._tr_T3Evaluate();
            } else {
                _trid_14 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_T3Evaluate", _trid_14);
            if(_trid_14) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3Evaluate();
                copiedState.parent = state;
                this.addCachedInfos("T3Evaluate", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_15: BSet<BTuple<BInteger, BInteger>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_T3writebus");
                dependentGuardsBoolean = "_tr_T3writebus" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_15 = state._tr_T3writebus();
            } else {
                _trid_15 = cachedValue as BSet<BTuple<BInteger, BInteger>>;
            }
            newCache = newCache.set("_tr_T3writebus", _trid_15);
            for(let param of _trid_15) {
                let _tmp_1: BInteger = param.projection2();
                let _tmp_2: BInteger = param.projection1();

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3writebus(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("T3writebus", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_16: BSet<BTuple<BInteger, BInteger>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_T3Read");
                dependentGuardsBoolean = "_tr_T3Read" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_16 = state._tr_T3Read();
            } else {
                _trid_16 = cachedValue as BSet<BTuple<BInteger, BInteger>>;
            }
            newCache = newCache.set("_tr_T3Read", _trid_16);
            for(let param of _trid_16) {
                let _tmp_1: BInteger = param.projection2();
                let _tmp_2: BInteger = param.projection1();

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3Read(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("T3Read", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_17: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_T3Poll");
                dependentGuardsBoolean = "_tr_T3Poll" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_17 = state._tr_T3Poll();
            } else {
                _trid_17 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_T3Poll", _trid_17);
            if(_trid_17) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3Poll();
                copiedState.parent = state;
                this.addCachedInfos("T3Poll", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_18: BSet<BInteger>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_T3ReleaseBus");
                dependentGuardsBoolean = "_tr_T3ReleaseBus" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_18 = state._tr_T3ReleaseBus();
            } else {
                _trid_18 = cachedValue as BSet<BInteger>;
            }
            newCache = newCache.set("_tr_T3ReleaseBus", _trid_18);
            for(let param of _trid_18) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3ReleaseBus(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("T3ReleaseBus", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_19: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_T3Wait");
                dependentGuardsBoolean = "_tr_T3Wait" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_19 = state._tr_T3Wait();
            } else {
                _trid_19 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_T3Wait", _trid_19);
            if(_trid_19) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3Wait();
                copiedState.parent = state;
                this.addCachedInfos("T3Wait", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_20: boolean;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_T3ReEnableWait");
                dependentGuardsBoolean = "_tr_T3ReEnableWait" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_20 = state._tr_T3ReEnableWait();
            } else {
                _trid_20 = cachedValue as boolean;
            }

            newCache = newCache.set("_tr_T3ReEnableWait", _trid_20);
            if(_trid_20) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3ReEnableWait();
                copiedState.parent = state;
                this.addCachedInfos("T3ReEnableWait", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_21: BSet<BInteger>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_Update");
                dependentGuardsBoolean = "_tr_Update" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_21 = state._tr_Update();
            } else {
                _trid_21 = cachedValue as BSet<BInteger>;
            }
            newCache = newCache.set("_tr_Update", _trid_21);
            for(let param of _trid_21) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.Update(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("Update", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

            state.guardCache = newCache;
        } else {
            if(state._tr_T1Evaluate()) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T1Evaluate();
                copiedState.parent = state;
                this.addCachedInfos("T1Evaluate", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_2: BSet<BInteger> = state._tr_T1Calculate();
            for(let param of _trid_2) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T1Calculate(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("T1Calculate", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_3: BSet<BTuple<BInteger, BInteger>> = state._tr_T1SendResult();
            for(let param of _trid_3) {
                let _tmp_1: BInteger = param.projection2();
                let _tmp_2: BInteger = param.projection1();

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T1SendResult(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("T1SendResult", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_4: BSet<BInteger> = state._tr_T1Wait();
            for(let param of _trid_4) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T1Wait(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("T1Wait", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_T2Evaluate()) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2Evaluate();
                copiedState.parent = state;
                this.addCachedInfos("T2Evaluate", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_6: BSet<BTuple<BInteger, BInteger>> = state._tr_T2ReadBus();
            for(let param of _trid_6) {
                let _tmp_1: BInteger = param.projection2();
                let _tmp_2: BInteger = param.projection1();

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2ReadBus(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("T2ReadBus", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_T2Reset()) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2Reset();
                copiedState.parent = state;
                this.addCachedInfos("T2Reset", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_T2Complete()) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2Complete();
                copiedState.parent = state;
                this.addCachedInfos("T2Complete", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_9: BSet<BInteger> = state._tr_T2ReleaseBus();
            for(let param of _trid_9) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2ReleaseBus(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("T2ReleaseBus", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_T2Calculate()) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2Calculate();
                copiedState.parent = state;
                this.addCachedInfos("T2Calculate", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_11: BSet<BTuple<BInteger, BInteger>> = state._tr_T2WriteBus();
            for(let param of _trid_11) {
                let _tmp_1: BInteger = param.projection2();
                let _tmp_2: BInteger = param.projection1();

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2WriteBus(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("T2WriteBus", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_12: BSet<BInteger> = state._tr_T2Wait();
            for(let param of _trid_12) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T2Wait(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("T2Wait", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_T3Initiate()) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3Initiate();
                copiedState.parent = state;
                this.addCachedInfos("T3Initiate", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_T3Evaluate()) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3Evaluate();
                copiedState.parent = state;
                this.addCachedInfos("T3Evaluate", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_15: BSet<BTuple<BInteger, BInteger>> = state._tr_T3writebus();
            for(let param of _trid_15) {
                let _tmp_1: BInteger = param.projection2();
                let _tmp_2: BInteger = param.projection1();

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3writebus(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("T3writebus", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_16: BSet<BTuple<BInteger, BInteger>> = state._tr_T3Read();
            for(let param of _trid_16) {
                let _tmp_1: BInteger = param.projection2();
                let _tmp_2: BInteger = param.projection1();

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3Read(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("T3Read", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_T3Poll()) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3Poll();
                copiedState.parent = state;
                this.addCachedInfos("T3Poll", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_18: BSet<BInteger> = state._tr_T3ReleaseBus();
            for(let param of _trid_18) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3ReleaseBus(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("T3ReleaseBus", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_T3Wait()) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3Wait();
                copiedState.parent = state;
                this.addCachedInfos("T3Wait", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            if(state._tr_T3ReEnableWait()) {
                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.T3ReEnableWait();
                copiedState.parent = state;
                this.addCachedInfos("T3ReEnableWait", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_21: BSet<BInteger> = state._tr_Update();
            for(let param of _trid_21) {
                let _tmp_1: BInteger = param;

                let copiedState: CAN_BUS_tlc = state._copy();
                copiedState.Update(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("Update", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        }
        return result;
    }

    invViolated(state: CAN_BUS_tlc): boolean {
        if(!(this.isCaching) || "_check_inv_1" in state.dependentInvariant) {
            if(!state._check_inv_1()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_1");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_2" in state.dependentInvariant) {
            if(!state._check_inv_2()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_2");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_3" in state.dependentInvariant) {
            if(!state._check_inv_3()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_3");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_4" in state.dependentInvariant) {
            if(!state._check_inv_4()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_4");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_5" in state.dependentInvariant) {
            if(!state._check_inv_5()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_5");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_6" in state.dependentInvariant) {
            if(!state._check_inv_6()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_6");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_7" in state.dependentInvariant) {
            if(!state._check_inv_7()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_7");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_8" in state.dependentInvariant) {
            if(!state._check_inv_8()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_8");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_9" in state.dependentInvariant) {
            if(!state._check_inv_9()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_9");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_10" in state.dependentInvariant) {
            if(!state._check_inv_10()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_10");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_11" in state.dependentInvariant) {
            if(!state._check_inv_11()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_11");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_12" in state.dependentInvariant) {
            if(!state._check_inv_12()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_12");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_13" in state.dependentInvariant) {
            if(!state._check_inv_13()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_13");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_14" in state.dependentInvariant) {
            if(!state._check_inv_14()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_14");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_15" in state.dependentInvariant) {
            if(!state._check_inv_15()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_15");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_16" in state.dependentInvariant) {
            if(!state._check_inv_16()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_16");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_17" in state.dependentInvariant) {
            if(!state._check_inv_17()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_17");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_18" in state.dependentInvariant) {
            if(!state._check_inv_18()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_18");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_19" in state.dependentInvariant) {
            if(!state._check_inv_19()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_19");
                return true;
            }
        }
        if(!(this.isCaching) || "_check_inv_20" in state.dependentInvariant) {
            if(!state._check_inv_20()) {
                console.log("INVARIANT CONJUNCT VIOLATED: _check_inv_20");
                return true;
            }
        }
        return false;
    }

    addCachedInfos(operation: string, state: CAN_BUS_tlc, copiedState: CAN_BUS_tlc): void {
        if(this.isCaching) {
            copiedState.dependentInvariant = this.invariantDependency.get(operation);
            copiedState.dependentGuard = this.guardDependency.get(operation);
        }
        copiedState.stateAccessedVia = operation;
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

