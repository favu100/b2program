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


export enum enum_TC_SET {
    TC_SET1,
    TC_SET2
}

export class TC_SET implements BObject{
    value: enum_TC_SET;

    constructor(value: enum_TC_SET) {
        this.value = value;
    }

    equal(other: TC_SET) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: TC_SET) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof TC_SET)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_TC_SET[this.value].toString();
    }

    static get_TC_SET1 () {return new TC_SET(enum_TC_SET.TC_SET1);}
    static get_TC_SET2 () {return new TC_SET(enum_TC_SET.TC_SET2);}


}

export enum enum_TC_STATUSES {
    TC_Unchecked,
    TC_Accepted,
    TC_Rejected,
    TC_Waiting_for_Execution,
    TC_Successfully_Executed,
    TC_Execution_Failed,
    TC_Removable
}

export class TC_STATUSES implements BObject{
    value: enum_TC_STATUSES;

    constructor(value: enum_TC_STATUSES) {
        this.value = value;
    }

    equal(other: TC_STATUSES) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: TC_STATUSES) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof TC_STATUSES)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_TC_STATUSES[this.value].toString();
    }

    static get_TC_Unchecked () {return new TC_STATUSES(enum_TC_STATUSES.TC_Unchecked);}
    static get_TC_Accepted () {return new TC_STATUSES(enum_TC_STATUSES.TC_Accepted);}
    static get_TC_Rejected () {return new TC_STATUSES(enum_TC_STATUSES.TC_Rejected);}
    static get_TC_Waiting_for_Execution () {return new TC_STATUSES(enum_TC_STATUSES.TC_Waiting_for_Execution);}
    static get_TC_Successfully_Executed () {return new TC_STATUSES(enum_TC_STATUSES.TC_Successfully_Executed);}
    static get_TC_Execution_Failed () {return new TC_STATUSES(enum_TC_STATUSES.TC_Execution_Failed);}
    static get_TC_Removable () {return new TC_STATUSES(enum_TC_STATUSES.TC_Removable);}


}

export enum enum_TM_STATUSES {
    TM_Effective,
    TM_Removable
}

export class TM_STATUSES implements BObject{
    value: enum_TM_STATUSES;

    constructor(value: enum_TM_STATUSES) {
        this.value = value;
    }

    equal(other: TM_STATUSES) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: TM_STATUSES) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof TM_STATUSES)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_TM_STATUSES[this.value].toString();
    }

    static get_TM_Effective () {return new TM_STATUSES(enum_TM_STATUSES.TM_Effective);}
    static get_TM_Removable () {return new TM_STATUSES(enum_TM_STATUSES.TM_Removable);}


}

export enum enum_PACKET_START_ADDRESSES_IN_TC_BUFFER {
    PACKET_START_ADDRESSES_IN_TC_BUFFER1,
    PACKET_START_ADDRESSES_IN_TC_BUFFER2
}

export class PACKET_START_ADDRESSES_IN_TC_BUFFER implements BObject{
    value: enum_PACKET_START_ADDRESSES_IN_TC_BUFFER;

    constructor(value: enum_PACKET_START_ADDRESSES_IN_TC_BUFFER) {
        this.value = value;
    }

    equal(other: PACKET_START_ADDRESSES_IN_TC_BUFFER) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: PACKET_START_ADDRESSES_IN_TC_BUFFER) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof PACKET_START_ADDRESSES_IN_TC_BUFFER)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_PACKET_START_ADDRESSES_IN_TC_BUFFER[this.value].toString();
    }

    static get_PACKET_START_ADDRESSES_IN_TC_BUFFER1 () {return new PACKET_START_ADDRESSES_IN_TC_BUFFER(enum_PACKET_START_ADDRESSES_IN_TC_BUFFER.PACKET_START_ADDRESSES_IN_TC_BUFFER1);}
    static get_PACKET_START_ADDRESSES_IN_TC_BUFFER2 () {return new PACKET_START_ADDRESSES_IN_TC_BUFFER(enum_PACKET_START_ADDRESSES_IN_TC_BUFFER.PACKET_START_ADDRESSES_IN_TC_BUFFER2);}


}

export enum enum_PACKET_START_ADDRESSES_IN_TC_POOL {
    PACKET_START_ADDRESSES_IN_TC_POOL1,
    PACKET_START_ADDRESSES_IN_TC_POOL2
}

export class PACKET_START_ADDRESSES_IN_TC_POOL implements BObject{
    value: enum_PACKET_START_ADDRESSES_IN_TC_POOL;

    constructor(value: enum_PACKET_START_ADDRESSES_IN_TC_POOL) {
        this.value = value;
    }

    equal(other: PACKET_START_ADDRESSES_IN_TC_POOL) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: PACKET_START_ADDRESSES_IN_TC_POOL) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof PACKET_START_ADDRESSES_IN_TC_POOL)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_PACKET_START_ADDRESSES_IN_TC_POOL[this.value].toString();
    }

    static get_PACKET_START_ADDRESSES_IN_TC_POOL1 () {return new PACKET_START_ADDRESSES_IN_TC_POOL(enum_PACKET_START_ADDRESSES_IN_TC_POOL.PACKET_START_ADDRESSES_IN_TC_POOL1);}
    static get_PACKET_START_ADDRESSES_IN_TC_POOL2 () {return new PACKET_START_ADDRESSES_IN_TC_POOL(enum_PACKET_START_ADDRESSES_IN_TC_POOL.PACKET_START_ADDRESSES_IN_TC_POOL2);}


}

export enum enum_PACKET_START_ADDRESSES_IN_TM_BUFFER {
    PACKET_START_ADDRESSES_IN_TM_BUFFER1,
    PACKET_START_ADDRESSES_IN_TM_BUFFER2
}

export class PACKET_START_ADDRESSES_IN_TM_BUFFER implements BObject{
    value: enum_PACKET_START_ADDRESSES_IN_TM_BUFFER;

    constructor(value: enum_PACKET_START_ADDRESSES_IN_TM_BUFFER) {
        this.value = value;
    }

    equal(other: PACKET_START_ADDRESSES_IN_TM_BUFFER) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: PACKET_START_ADDRESSES_IN_TM_BUFFER) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof PACKET_START_ADDRESSES_IN_TM_BUFFER)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_PACKET_START_ADDRESSES_IN_TM_BUFFER[this.value].toString();
    }

    static get_PACKET_START_ADDRESSES_IN_TM_BUFFER1 () {return new PACKET_START_ADDRESSES_IN_TM_BUFFER(enum_PACKET_START_ADDRESSES_IN_TM_BUFFER.PACKET_START_ADDRESSES_IN_TM_BUFFER1);}
    static get_PACKET_START_ADDRESSES_IN_TM_BUFFER2 () {return new PACKET_START_ADDRESSES_IN_TM_BUFFER(enum_PACKET_START_ADDRESSES_IN_TM_BUFFER.PACKET_START_ADDRESSES_IN_TM_BUFFER2);}


}

export enum enum_PACKET_START_ADDRESSES_IN_TM_POOL {
    PACKET_START_ADDRESSES_IN_TM_POOL1,
    PACKET_START_ADDRESSES_IN_TM_POOL2
}

export class PACKET_START_ADDRESSES_IN_TM_POOL implements BObject{
    value: enum_PACKET_START_ADDRESSES_IN_TM_POOL;

    constructor(value: enum_PACKET_START_ADDRESSES_IN_TM_POOL) {
        this.value = value;
    }

    equal(other: PACKET_START_ADDRESSES_IN_TM_POOL) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: PACKET_START_ADDRESSES_IN_TM_POOL) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof PACKET_START_ADDRESSES_IN_TM_POOL)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_PACKET_START_ADDRESSES_IN_TM_POOL[this.value].toString();
    }

    static get_PACKET_START_ADDRESSES_IN_TM_POOL1 () {return new PACKET_START_ADDRESSES_IN_TM_POOL(enum_PACKET_START_ADDRESSES_IN_TM_POOL.PACKET_START_ADDRESSES_IN_TM_POOL1);}
    static get_PACKET_START_ADDRESSES_IN_TM_POOL2 () {return new PACKET_START_ADDRESSES_IN_TM_POOL(enum_PACKET_START_ADDRESSES_IN_TM_POOL.PACKET_START_ADDRESSES_IN_TM_POOL2);}


}

export enum enum_TM_SET {
    TM_SET1,
    TM_SET2
}

export class TM_SET implements BObject{
    value: enum_TM_SET;

    constructor(value: enum_TM_SET) {
        this.value = value;
    }

    equal(other: TM_SET) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: TM_SET) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof TM_SET)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_TM_SET[this.value].toString();
    }

    static get_TM_SET1 () {return new TM_SET(enum_TM_SET.TM_SET1);}
    static get_TM_SET2 () {return new TM_SET(enum_TM_SET.TM_SET2);}


}


class _ProjectionRead_env_Receive_TC {

    public TCbuffer: BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET>;

    constructor(TCbuffer : BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET>) {
        this.TCbuffer = TCbuffer;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_env_Receive_TC = this;
        let o2: _ProjectionRead_env_Receive_TC = other as _ProjectionRead_env_Receive_TC;
        return o1.TCbuffer.equals(o2.TCbuffer);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCbuffer.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_env_Receive_TC {

    public TCbuffer: BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET>;

    constructor(TCbuffer : BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET>) {
        this.TCbuffer = TCbuffer;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_env_Receive_TC = this;
        let o2: _ProjectionRead__tr_env_Receive_TC = other as _ProjectionRead__tr_env_Receive_TC;
        return o1.TCbuffer.equals(o2.TCbuffer);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCbuffer.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_env_Receive_TC {

    public TCbuffer: BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET>;

    constructor(TCbuffer : BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET>) {
        this.TCbuffer = TCbuffer;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_env_Receive_TC = this;
        let o2: _ProjectionWrite_env_Receive_TC = other as _ProjectionWrite_env_Receive_TC;
        return o1.TCbuffer.equals(o2.TCbuffer);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCbuffer.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_Poll_TC {

    public TCbuffer: BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET>;
    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCbuffer : BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET>, TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCbuffer = TCbuffer;
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_Poll_TC = this;
        let o2: _ProjectionRead_Poll_TC = other as _ProjectionRead_Poll_TC;
        return o1.TCbuffer.equals(o2.TCbuffer) && o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCbuffer.hashCode() << 1);
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_Poll_TC {

    public TCbuffer: BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET>;
    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;

    constructor(TCbuffer : BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET>, TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>) {
        this.TCbuffer = TCbuffer;
        this.TCpool = TCpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_Poll_TC = this;
        let o2: _ProjectionRead__tr_Poll_TC = other as _ProjectionRead__tr_Poll_TC;
        return o1.TCbuffer.equals(o2.TCbuffer) && o1.TCpool.equals(o2.TCpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCbuffer.hashCode() << 1);
        result = 31 * result + (this.TCpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_Poll_TC {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCbuffer: BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCbuffer : BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCbuffer = TCbuffer;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_Poll_TC = this;
        let o2: _ProjectionWrite_Poll_TC = other as _ProjectionWrite_Poll_TC;
        return o1.TCpool.equals(o2.TCpool) && o1.TCbuffer.equals(o2.TCbuffer) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCbuffer.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_Accept_TC {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_Accept_TC = this;
        let o2: _ProjectionRead_Accept_TC = other as _ProjectionRead_Accept_TC;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_Accept_TC {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_Accept_TC = this;
        let o2: _ProjectionRead__tr_Accept_TC = other as _ProjectionRead__tr_Accept_TC;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_Accept_TC {

    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_Accept_TC = this;
        let o2: _ProjectionWrite_Accept_TC = other as _ProjectionWrite_Accept_TC;
        return o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_Reject_TC {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_Reject_TC = this;
        let o2: _ProjectionRead_Reject_TC = other as _ProjectionRead_Reject_TC;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_Reject_TC {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_Reject_TC = this;
        let o2: _ProjectionRead__tr_Reject_TC = other as _ProjectionRead__tr_Reject_TC;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_Reject_TC {

    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_Reject_TC = this;
        let o2: _ProjectionWrite_Reject_TC = other as _ProjectionWrite_Reject_TC;
        return o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_Report_TC_Acceptance {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;
    public TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>, TMstatus : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
        this.TMstatus = TMstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_Report_TC_Acceptance = this;
        let o2: _ProjectionRead_Report_TC_Acceptance = other as _ProjectionRead_Report_TC_Acceptance;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus) && o1.TMstatus.equals(o2.TMstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        result = 31 * result + (this.TMstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_Report_TC_Acceptance {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_Report_TC_Acceptance = this;
        let o2: _ProjectionRead__tr_Report_TC_Acceptance = other as _ProjectionRead__tr_Report_TC_Acceptance;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_Report_TC_Acceptance {

    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;
    public TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>, TMstatus : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TCstatus = TCstatus;
        this.TMstatus = TMstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_Report_TC_Acceptance = this;
        let o2: _ProjectionWrite_Report_TC_Acceptance = other as _ProjectionWrite_Report_TC_Acceptance;
        return o1.TCstatus.equals(o2.TCstatus) && o1.TMstatus.equals(o2.TMstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        result = 31 * result + (this.TMstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_Skip_TC_Acceptance_Report {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_Skip_TC_Acceptance_Report = this;
        let o2: _ProjectionRead_Skip_TC_Acceptance_Report = other as _ProjectionRead_Skip_TC_Acceptance_Report;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_Skip_TC_Acceptance_Report {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_Skip_TC_Acceptance_Report = this;
        let o2: _ProjectionRead__tr_Skip_TC_Acceptance_Report = other as _ProjectionRead__tr_Skip_TC_Acceptance_Report;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_Skip_TC_Acceptance_Report {

    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_Skip_TC_Acceptance_Report = this;
        let o2: _ProjectionWrite_Skip_TC_Acceptance_Report = other as _ProjectionWrite_Skip_TC_Acceptance_Report;
        return o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_Report_TC_Rejection {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;
    public TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>, TMstatus : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
        this.TMstatus = TMstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_Report_TC_Rejection = this;
        let o2: _ProjectionRead_Report_TC_Rejection = other as _ProjectionRead_Report_TC_Rejection;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus) && o1.TMstatus.equals(o2.TMstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        result = 31 * result + (this.TMstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_Report_TC_Rejection {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_Report_TC_Rejection = this;
        let o2: _ProjectionRead__tr_Report_TC_Rejection = other as _ProjectionRead__tr_Report_TC_Rejection;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_Report_TC_Rejection {

    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;
    public TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>, TMstatus : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TCstatus = TCstatus;
        this.TMstatus = TMstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_Report_TC_Rejection = this;
        let o2: _ProjectionWrite_Report_TC_Rejection = other as _ProjectionWrite_Report_TC_Rejection;
        return o1.TCstatus.equals(o2.TCstatus) && o1.TMstatus.equals(o2.TMstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        result = 31 * result + (this.TMstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_Skip_TC_Rejection_Report {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_Skip_TC_Rejection_Report = this;
        let o2: _ProjectionRead_Skip_TC_Rejection_Report = other as _ProjectionRead_Skip_TC_Rejection_Report;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_Skip_TC_Rejection_Report {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_Skip_TC_Rejection_Report = this;
        let o2: _ProjectionRead__tr_Skip_TC_Rejection_Report = other as _ProjectionRead__tr_Skip_TC_Rejection_Report;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_Skip_TC_Rejection_Report {

    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_Skip_TC_Rejection_Report = this;
        let o2: _ProjectionWrite_Skip_TC_Rejection_Report = other as _ProjectionWrite_Skip_TC_Rejection_Report;
        return o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_Execute_TC_Successfully {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_Execute_TC_Successfully = this;
        let o2: _ProjectionRead_Execute_TC_Successfully = other as _ProjectionRead_Execute_TC_Successfully;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_Execute_TC_Successfully {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_Execute_TC_Successfully = this;
        let o2: _ProjectionRead__tr_Execute_TC_Successfully = other as _ProjectionRead__tr_Execute_TC_Successfully;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_Execute_TC_Successfully {

    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_Execute_TC_Successfully = this;
        let o2: _ProjectionWrite_Execute_TC_Successfully = other as _ProjectionWrite_Execute_TC_Successfully;
        return o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_Reset_TM_Buffer {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_Reset_TM_Buffer = this;
        let o2: _ProjectionRead_Reset_TM_Buffer = other as _ProjectionRead_Reset_TM_Buffer;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_Reset_TM_Buffer {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_Reset_TM_Buffer = this;
        let o2: _ProjectionRead__tr_Reset_TM_Buffer = other as _ProjectionRead__tr_Reset_TM_Buffer;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_Reset_TM_Buffer {

    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;
    public TMbuffer: BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>;

    constructor(TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>, TMbuffer : BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>) {
        this.TCstatus = TCstatus;
        this.TMbuffer = TMbuffer;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_Reset_TM_Buffer = this;
        let o2: _ProjectionWrite_Reset_TM_Buffer = other as _ProjectionWrite_Reset_TM_Buffer;
        return o1.TCstatus.equals(o2.TCstatus) && o1.TMbuffer.equals(o2.TMbuffer);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        result = 31 * result + (this.TMbuffer.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_Fail_TC_Execution {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_Fail_TC_Execution = this;
        let o2: _ProjectionRead_Fail_TC_Execution = other as _ProjectionRead_Fail_TC_Execution;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_Fail_TC_Execution {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_Fail_TC_Execution = this;
        let o2: _ProjectionRead__tr_Fail_TC_Execution = other as _ProjectionRead__tr_Fail_TC_Execution;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_Fail_TC_Execution {

    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_Fail_TC_Execution = this;
        let o2: _ProjectionWrite_Fail_TC_Execution = other as _ProjectionWrite_Fail_TC_Execution;
        return o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_Report_TC_Execution_Success {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;
    public TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>, TMstatus : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
        this.TMstatus = TMstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_Report_TC_Execution_Success = this;
        let o2: _ProjectionRead_Report_TC_Execution_Success = other as _ProjectionRead_Report_TC_Execution_Success;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus) && o1.TMstatus.equals(o2.TMstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        result = 31 * result + (this.TMstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_Report_TC_Execution_Success {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_Report_TC_Execution_Success = this;
        let o2: _ProjectionRead__tr_Report_TC_Execution_Success = other as _ProjectionRead__tr_Report_TC_Execution_Success;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_Report_TC_Execution_Success {

    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;
    public TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>, TMstatus : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TCstatus = TCstatus;
        this.TMstatus = TMstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_Report_TC_Execution_Success = this;
        let o2: _ProjectionWrite_Report_TC_Execution_Success = other as _ProjectionWrite_Report_TC_Execution_Success;
        return o1.TCstatus.equals(o2.TCstatus) && o1.TMstatus.equals(o2.TMstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        result = 31 * result + (this.TMstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_Skip_TC_Success_Report {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_Skip_TC_Success_Report = this;
        let o2: _ProjectionRead_Skip_TC_Success_Report = other as _ProjectionRead_Skip_TC_Success_Report;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_Skip_TC_Success_Report {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_Skip_TC_Success_Report = this;
        let o2: _ProjectionRead__tr_Skip_TC_Success_Report = other as _ProjectionRead__tr_Skip_TC_Success_Report;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_Skip_TC_Success_Report {

    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_Skip_TC_Success_Report = this;
        let o2: _ProjectionWrite_Skip_TC_Success_Report = other as _ProjectionWrite_Skip_TC_Success_Report;
        return o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_Report_TC_Execution_Failure {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;
    public TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>, TMstatus : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
        this.TMstatus = TMstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_Report_TC_Execution_Failure = this;
        let o2: _ProjectionRead_Report_TC_Execution_Failure = other as _ProjectionRead_Report_TC_Execution_Failure;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus) && o1.TMstatus.equals(o2.TMstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        result = 31 * result + (this.TMstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_Report_TC_Execution_Failure {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_Report_TC_Execution_Failure = this;
        let o2: _ProjectionRead__tr_Report_TC_Execution_Failure = other as _ProjectionRead__tr_Report_TC_Execution_Failure;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_Report_TC_Execution_Failure {

    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;
    public TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>, TMstatus : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TCstatus = TCstatus;
        this.TMstatus = TMstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_Report_TC_Execution_Failure = this;
        let o2: _ProjectionWrite_Report_TC_Execution_Failure = other as _ProjectionWrite_Report_TC_Execution_Failure;
        return o1.TCstatus.equals(o2.TCstatus) && o1.TMstatus.equals(o2.TMstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        result = 31 * result + (this.TMstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_Skip_TC_Failure_Report {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_Skip_TC_Failure_Report = this;
        let o2: _ProjectionRead_Skip_TC_Failure_Report = other as _ProjectionRead_Skip_TC_Failure_Report;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_Skip_TC_Failure_Report {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_Skip_TC_Failure_Report = this;
        let o2: _ProjectionRead__tr_Skip_TC_Failure_Report = other as _ProjectionRead__tr_Skip_TC_Failure_Report;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_Skip_TC_Failure_Report {

    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_Skip_TC_Failure_Report = this;
        let o2: _ProjectionWrite_Skip_TC_Failure_Report = other as _ProjectionWrite_Skip_TC_Failure_Report;
        return o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_Drop_TC {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_Drop_TC = this;
        let o2: _ProjectionRead_Drop_TC = other as _ProjectionRead_Drop_TC;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_Drop_TC {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_Drop_TC = this;
        let o2: _ProjectionRead__tr_Drop_TC = other as _ProjectionRead__tr_Drop_TC;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_Drop_TC {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_Drop_TC = this;
        let o2: _ProjectionWrite_Drop_TC = other as _ProjectionWrite_Drop_TC;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_Produce_TM {

    public TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TMstatus : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TMstatus = TMstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_Produce_TM = this;
        let o2: _ProjectionRead_Produce_TM = other as _ProjectionRead_Produce_TM;
        return o1.TMstatus.equals(o2.TMstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TMstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_Produce_TM {

    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_Produce_TM = this;
        let o2: _ProjectionRead__tr_Produce_TM = other as _ProjectionRead__tr_Produce_TM;
        return o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_Produce_TM {

    public TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TMstatus : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TMstatus = TMstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_Produce_TM = this;
        let o2: _ProjectionWrite_Produce_TM = other as _ProjectionWrite_Produce_TM;
        return o1.TMstatus.equals(o2.TMstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TMstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_Pass_TM {

    public TMbuffer: BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>;
    public TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TMbuffer : BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>, TMstatus : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TMbuffer = TMbuffer;
        this.TMstatus = TMstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_Pass_TM = this;
        let o2: _ProjectionRead_Pass_TM = other as _ProjectionRead_Pass_TM;
        return o1.TMbuffer.equals(o2.TMbuffer) && o1.TMstatus.equals(o2.TMstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TMbuffer.hashCode() << 1);
        result = 31 * result + (this.TMstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_Pass_TM {

    public TMbuffer: BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>;
    public TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TMbuffer : BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>, TMstatus : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TMbuffer = TMbuffer;
        this.TMstatus = TMstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_Pass_TM = this;
        let o2: _ProjectionRead__tr_Pass_TM = other as _ProjectionRead__tr_Pass_TM;
        return o1.TMbuffer.equals(o2.TMbuffer) && o1.TMstatus.equals(o2.TMstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TMbuffer.hashCode() << 1);
        result = 31 * result + (this.TMstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_Pass_TM {

    public TMbuffer: BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>;
    public TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;

    constructor(TMbuffer : BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>, TMstatus : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>) {
        this.TMbuffer = TMbuffer;
        this.TMstatus = TMstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_Pass_TM = this;
        let o2: _ProjectionWrite_Pass_TM = other as _ProjectionWrite_Pass_TM;
        return o1.TMbuffer.equals(o2.TMbuffer) && o1.TMstatus.equals(o2.TMstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TMbuffer.hashCode() << 1);
        result = 31 * result + (this.TMstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_Cancel_TM {

    public TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TMstatus : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TMstatus = TMstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_Cancel_TM = this;
        let o2: _ProjectionRead_Cancel_TM = other as _ProjectionRead_Cancel_TM;
        return o1.TMstatus.equals(o2.TMstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TMstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_Cancel_TM {

    public TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TMstatus : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TMstatus = TMstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_Cancel_TM = this;
        let o2: _ProjectionRead__tr_Cancel_TM = other as _ProjectionRead__tr_Cancel_TM;
        return o1.TMstatus.equals(o2.TMstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TMstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_Cancel_TM {

    public TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;

    constructor(TMstatus : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>) {
        this.TMstatus = TMstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_Cancel_TM = this;
        let o2: _ProjectionWrite_Cancel_TM = other as _ProjectionWrite_Cancel_TM;
        return o1.TMstatus.equals(o2.TMstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TMstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_Drop_TM {

    public TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TMstatus : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TMstatus = TMstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_Drop_TM = this;
        let o2: _ProjectionRead_Drop_TM = other as _ProjectionRead_Drop_TM;
        return o1.TMstatus.equals(o2.TMstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TMstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_Drop_TM {

    public TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TMstatus : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TMstatus = TMstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_Drop_TM = this;
        let o2: _ProjectionRead__tr_Drop_TM = other as _ProjectionRead__tr_Drop_TM;
        return o1.TMstatus.equals(o2.TMstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TMstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_Drop_TM {

    public TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TMstatus : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TMstatus = TMstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_Drop_TM = this;
        let o2: _ProjectionWrite_Drop_TM = other as _ProjectionWrite_Drop_TM;
        return o1.TMstatus.equals(o2.TMstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TMstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_env_Deliver_TM {

    public TMbuffer: BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>;

    constructor(TMbuffer : BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>) {
        this.TMbuffer = TMbuffer;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_env_Deliver_TM = this;
        let o2: _ProjectionRead_env_Deliver_TM = other as _ProjectionRead_env_Deliver_TM;
        return o1.TMbuffer.equals(o2.TMbuffer);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TMbuffer.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_env_Deliver_TM {

    public TMbuffer: BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>;

    constructor(TMbuffer : BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>) {
        this.TMbuffer = TMbuffer;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_env_Deliver_TM = this;
        let o2: _ProjectionRead__tr_env_Deliver_TM = other as _ProjectionRead__tr_env_Deliver_TM;
        return o1.TMbuffer.equals(o2.TMbuffer);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TMbuffer.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_env_Deliver_TM {

    public TMbuffer: BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>;

    constructor(TMbuffer : BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>) {
        this.TMbuffer = TMbuffer;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_env_Deliver_TM = this;
        let o2: _ProjectionWrite_env_Deliver_TM = other as _ProjectionWrite_env_Deliver_TM;
        return o1.TMbuffer.equals(o2.TMbuffer);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TMbuffer.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_1 {

    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_1 = this;
        let o2: _ProjectionRead__check_inv_1 = other as _ProjectionRead__check_inv_1;
        return o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_2 {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_2 = this;
        let o2: _ProjectionRead__check_inv_2 = other as _ProjectionRead__check_inv_2;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_3 {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    public TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>, TCstatus : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>) {
        this.TCpool = TCpool;
        this.TCstatus = TCstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_3 = this;
        let o2: _ProjectionRead__check_inv_3 = other as _ProjectionRead__check_inv_3;
        return o1.TCpool.equals(o2.TCpool) && o1.TCstatus.equals(o2.TCstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        result = 31 * result + (this.TCstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_4 {

    public TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;

    constructor(TMstatus : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>) {
        this.TMstatus = TMstatus;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_4 = this;
        let o2: _ProjectionRead__check_inv_4 = other as _ProjectionRead__check_inv_4;
        return o1.TMstatus.equals(o2.TMstatus);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TMstatus.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_5 {

    public TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;
    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TMstatus : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>, TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TMstatus = TMstatus;
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_5 = this;
        let o2: _ProjectionRead__check_inv_5 = other as _ProjectionRead__check_inv_5;
        return o1.TMstatus.equals(o2.TMstatus) && o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TMstatus.hashCode() << 1);
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_6 {

    public TCbuffer: BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET>;

    constructor(TCbuffer : BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET>) {
        this.TCbuffer = TCbuffer;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_6 = this;
        let o2: _ProjectionRead__check_inv_6 = other as _ProjectionRead__check_inv_6;
        return o1.TCbuffer.equals(o2.TCbuffer);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCbuffer.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_7 {

    public TMbuffer: BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>;

    constructor(TMbuffer : BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>) {
        this.TMbuffer = TMbuffer;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_7 = this;
        let o2: _ProjectionRead__check_inv_7 = other as _ProjectionRead__check_inv_7;
        return o1.TMbuffer.equals(o2.TMbuffer);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TMbuffer.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_8 {

    public TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;

    constructor(TCpool : BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>) {
        this.TCpool = TCpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_8 = this;
        let o2: _ProjectionRead__check_inv_8 = other as _ProjectionRead__check_inv_8;
        return o1.TCpool.equals(o2.TCpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TCpool.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_9 {

    public TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    constructor(TMpool : BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>) {
        this.TMpool = TMpool;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_9 = this;
        let o2: _ProjectionRead__check_inv_9 = other as _ProjectionRead__check_inv_9;
        return o1.TMpool.equals(o2.TMpool);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TMpool.hashCode() << 1);
        return result;
    }
}


export enum Type {
    BFS,
    DFS,
    MIXED
}

export default class obsw_M001_1 {

    parent: obsw_M001_1;
    stateAccessedVia: string;


    private static VALID_TCS: BSet<TC_SET>;

    private static _TC_SET: BSet<TC_SET> = new BSet<TC_SET>(new TC_SET(enum_TC_SET.TC_SET1), new TC_SET(enum_TC_SET.TC_SET2));
    private static _TC_STATUSES: BSet<TC_STATUSES> = new BSet<TC_STATUSES>(new TC_STATUSES(enum_TC_STATUSES.TC_Unchecked), new TC_STATUSES(enum_TC_STATUSES.TC_Accepted), new TC_STATUSES(enum_TC_STATUSES.TC_Rejected), new TC_STATUSES(enum_TC_STATUSES.TC_Waiting_for_Execution), new TC_STATUSES(enum_TC_STATUSES.TC_Successfully_Executed), new TC_STATUSES(enum_TC_STATUSES.TC_Execution_Failed), new TC_STATUSES(enum_TC_STATUSES.TC_Removable));
    private static _TM_STATUSES: BSet<TM_STATUSES> = new BSet<TM_STATUSES>(new TM_STATUSES(enum_TM_STATUSES.TM_Effective), new TM_STATUSES(enum_TM_STATUSES.TM_Removable));
    private static _PACKET_START_ADDRESSES_IN_TC_BUFFER: BSet<PACKET_START_ADDRESSES_IN_TC_BUFFER> = new BSet<PACKET_START_ADDRESSES_IN_TC_BUFFER>(new PACKET_START_ADDRESSES_IN_TC_BUFFER(enum_PACKET_START_ADDRESSES_IN_TC_BUFFER.PACKET_START_ADDRESSES_IN_TC_BUFFER1), new PACKET_START_ADDRESSES_IN_TC_BUFFER(enum_PACKET_START_ADDRESSES_IN_TC_BUFFER.PACKET_START_ADDRESSES_IN_TC_BUFFER2));
    private static _PACKET_START_ADDRESSES_IN_TC_POOL: BSet<PACKET_START_ADDRESSES_IN_TC_POOL> = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(new PACKET_START_ADDRESSES_IN_TC_POOL(enum_PACKET_START_ADDRESSES_IN_TC_POOL.PACKET_START_ADDRESSES_IN_TC_POOL1), new PACKET_START_ADDRESSES_IN_TC_POOL(enum_PACKET_START_ADDRESSES_IN_TC_POOL.PACKET_START_ADDRESSES_IN_TC_POOL2));
    private static _PACKET_START_ADDRESSES_IN_TM_BUFFER: BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER> = new BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER>(new PACKET_START_ADDRESSES_IN_TM_BUFFER(enum_PACKET_START_ADDRESSES_IN_TM_BUFFER.PACKET_START_ADDRESSES_IN_TM_BUFFER1), new PACKET_START_ADDRESSES_IN_TM_BUFFER(enum_PACKET_START_ADDRESSES_IN_TM_BUFFER.PACKET_START_ADDRESSES_IN_TM_BUFFER2));
    private static _PACKET_START_ADDRESSES_IN_TM_POOL: BSet<PACKET_START_ADDRESSES_IN_TM_POOL> = new BSet<PACKET_START_ADDRESSES_IN_TM_POOL>(new PACKET_START_ADDRESSES_IN_TM_POOL(enum_PACKET_START_ADDRESSES_IN_TM_POOL.PACKET_START_ADDRESSES_IN_TM_POOL1), new PACKET_START_ADDRESSES_IN_TM_POOL(enum_PACKET_START_ADDRESSES_IN_TM_POOL.PACKET_START_ADDRESSES_IN_TM_POOL2));
    private static _TM_SET: BSet<TM_SET> = new BSet<TM_SET>(new TM_SET(enum_TM_SET.TM_SET1), new TM_SET(enum_TM_SET.TM_SET2));

    private TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>;
    private TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>;
    private TCbuffer: BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET>;
    private TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>;
    private TMbuffer: BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>;
    private TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>;

    static {
        obsw_M001_1.VALID_TCS = new BSet<TC_SET>();
        if(!(new BBoolean(obsw_M001_1._TC_SET.card().equal(new BInteger(2)).booleanValue() && obsw_M001_1._TC_SET.difference(obsw_M001_1.VALID_TCS).unequal(new BSet<TC_SET>()).booleanValue())).booleanValue()) {
            throw new Error("Contradiction in PROPERTIES detected!");
        }
    }

    constructor(copy? : obsw_M001_1) {
        if(copy) {
            this.TCstatus = copy.TCstatus;
            this.TMstatus = copy.TMstatus;
            this.TCbuffer = copy.TCbuffer;
            this.TCpool = copy.TCpool;
            this.TMbuffer = copy.TMbuffer;
            this.TMpool = copy.TMpool;
        } else {
            this.TCbuffer = new BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET>();
            this.TMbuffer = new BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>();
            this.TCpool = new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>();
            this.TMpool = new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>();
            this.TCstatus = new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>();
            this.TMstatus = new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>();
        }
    }



    env_Receive_TC(tc: TC_SET, tc_pointer: PACKET_START_ADDRESSES_IN_TC_BUFFER): void {
        this.TCbuffer = this.TCbuffer.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET>(new BTuple(tc_pointer, tc)));

    }

    Poll_TC(tc_handler: PACKET_START_ADDRESSES_IN_TC_POOL, tc_pointer: PACKET_START_ADDRESSES_IN_TC_BUFFER): void {
        let _ld_TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> = this.TCpool;
        let _ld_TCbuffer: BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET> = this.TCbuffer;
        let _ld_TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> = this.TCstatus;
        this.TCpool = _ld_TCpool.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>(new BTuple(tc_handler, _ld_TCbuffer.functionCall(tc_pointer))));
        this.TCbuffer = _ld_TCbuffer.domainSubstraction(new BSet<PACKET_START_ADDRESSES_IN_TC_BUFFER>(tc_pointer));
        this.TCstatus = _ld_TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple(tc_handler, new TC_STATUSES(enum_TC_STATUSES.TC_Unchecked))));

    }

    Accept_TC(tc_handler: PACKET_START_ADDRESSES_IN_TC_POOL): void {
        this.TCstatus = this.TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple(tc_handler, new TC_STATUSES(enum_TC_STATUSES.TC_Accepted))));

    }

    Reject_TC(tc_handler: PACKET_START_ADDRESSES_IN_TC_POOL): void {
        this.TCstatus = this.TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple(tc_handler, new TC_STATUSES(enum_TC_STATUSES.TC_Rejected))));

    }

    Report_TC_Acceptance(tc_handler: PACKET_START_ADDRESSES_IN_TC_POOL, tm: TM_SET, tm_handler: PACKET_START_ADDRESSES_IN_TM_POOL): void {
        let _ld_TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> = this.TMstatus;
        let _ld_TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> = this.TCstatus;
        let _ld_TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> = this.TMpool;
        this.TMpool = _ld_TMpool.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>(new BTuple(tm_handler, tm)));
        this.TCstatus = _ld_TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple(tc_handler, new TC_STATUSES(enum_TC_STATUSES.TC_Waiting_for_Execution))));
        this.TMstatus = _ld_TMstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>(new BTuple(tm_handler, new TM_STATUSES(enum_TM_STATUSES.TM_Effective))));

    }

    Skip_TC_Acceptance_Report(tc_handler: PACKET_START_ADDRESSES_IN_TC_POOL): void {
        this.TCstatus = this.TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple(tc_handler, new TC_STATUSES(enum_TC_STATUSES.TC_Waiting_for_Execution))));

    }

    Report_TC_Rejection(tc_handler: PACKET_START_ADDRESSES_IN_TC_POOL, tm: TM_SET, tm_handler: PACKET_START_ADDRESSES_IN_TM_POOL): void {
        let _ld_TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> = this.TMstatus;
        let _ld_TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> = this.TCstatus;
        let _ld_TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> = this.TMpool;
        this.TMpool = _ld_TMpool.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>(new BTuple(tm_handler, tm)));
        this.TCstatus = _ld_TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple(tc_handler, new TC_STATUSES(enum_TC_STATUSES.TC_Removable))));
        this.TMstatus = _ld_TMstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>(new BTuple(tm_handler, new TM_STATUSES(enum_TM_STATUSES.TM_Effective))));

    }

    Skip_TC_Rejection_Report(tc_handler: PACKET_START_ADDRESSES_IN_TC_POOL): void {
        this.TCstatus = this.TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple(tc_handler, new TC_STATUSES(enum_TC_STATUSES.TC_Removable))));

    }

    Execute_TC_Successfully(tc_handler: PACKET_START_ADDRESSES_IN_TC_POOL): void {
        this.TCstatus = this.TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple(tc_handler, new TC_STATUSES(enum_TC_STATUSES.TC_Successfully_Executed))));

    }

    Reset_TM_Buffer(tc_handler: PACKET_START_ADDRESSES_IN_TC_POOL): void {
        let _ld_TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> = this.TCstatus;
        this.TMbuffer = new BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>();
        this.TCstatus = _ld_TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple(tc_handler, new TC_STATUSES(enum_TC_STATUSES.TC_Successfully_Executed))));

    }

    Fail_TC_Execution(tc_handler: PACKET_START_ADDRESSES_IN_TC_POOL): void {
        this.TCstatus = this.TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple(tc_handler, new TC_STATUSES(enum_TC_STATUSES.TC_Execution_Failed))));

    }

    Report_TC_Execution_Success(tc_handler: PACKET_START_ADDRESSES_IN_TC_POOL, tm: TM_SET, tm_handler: PACKET_START_ADDRESSES_IN_TM_POOL): void {
        let _ld_TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> = this.TMstatus;
        let _ld_TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> = this.TCstatus;
        let _ld_TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> = this.TMpool;
        this.TMpool = _ld_TMpool.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>(new BTuple(tm_handler, tm)));
        this.TCstatus = _ld_TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple(tc_handler, new TC_STATUSES(enum_TC_STATUSES.TC_Removable))));
        this.TMstatus = _ld_TMstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>(new BTuple(tm_handler, new TM_STATUSES(enum_TM_STATUSES.TM_Effective))));

    }

    Skip_TC_Success_Report(tc_handler: PACKET_START_ADDRESSES_IN_TC_POOL): void {
        this.TCstatus = this.TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple(tc_handler, new TC_STATUSES(enum_TC_STATUSES.TC_Removable))));

    }

    Report_TC_Execution_Failure(tc_handler: PACKET_START_ADDRESSES_IN_TC_POOL, tm: TM_SET, tm_handler: PACKET_START_ADDRESSES_IN_TM_POOL): void {
        let _ld_TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> = this.TMstatus;
        let _ld_TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> = this.TCstatus;
        let _ld_TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> = this.TMpool;
        this.TMpool = _ld_TMpool.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>(new BTuple(tm_handler, tm)));
        this.TCstatus = _ld_TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple(tc_handler, new TC_STATUSES(enum_TC_STATUSES.TC_Removable))));
        this.TMstatus = _ld_TMstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>(new BTuple(tm_handler, new TM_STATUSES(enum_TM_STATUSES.TM_Effective))));

    }

    Skip_TC_Failure_Report(tc_handler: PACKET_START_ADDRESSES_IN_TC_POOL): void {
        this.TCstatus = this.TCstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>(new BTuple(tc_handler, new TC_STATUSES(enum_TC_STATUSES.TC_Removable))));

    }

    Drop_TC(tc_handler: PACKET_START_ADDRESSES_IN_TC_POOL): void {
        let _ld_TCpool: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> = this.TCpool;
        let _ld_TCstatus: BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> = this.TCstatus;
        this.TCpool = _ld_TCpool.domainSubstraction(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(tc_handler));
        this.TCstatus = _ld_TCstatus.domainSubstraction(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(tc_handler));

    }

    Produce_TM(tm: TM_SET, tm_handler: PACKET_START_ADDRESSES_IN_TM_POOL): void {
        let _ld_TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> = this.TMstatus;
        let _ld_TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> = this.TMpool;
        this.TMpool = _ld_TMpool.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>(new BTuple(tm_handler, tm)));
        this.TMstatus = _ld_TMstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>(new BTuple(tm_handler, new TM_STATUSES(enum_TM_STATUSES.TM_Effective))));

    }

    Pass_TM(tm_handler: PACKET_START_ADDRESSES_IN_TM_POOL, tm_pointer: PACKET_START_ADDRESSES_IN_TM_BUFFER): void {
        let _ld_TMbuffer: BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET> = this.TMbuffer;
        let _ld_TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> = this.TMstatus;
        this.TMbuffer = _ld_TMbuffer.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>(new BTuple(tm_pointer, this.TMpool.functionCall(tm_handler))));
        this.TMstatus = _ld_TMstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>(new BTuple(tm_handler, new TM_STATUSES(enum_TM_STATUSES.TM_Removable))));

    }

    Cancel_TM(tm_handler: PACKET_START_ADDRESSES_IN_TM_POOL): void {
        this.TMstatus = this.TMstatus.override(new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>(new BTuple(tm_handler, new TM_STATUSES(enum_TM_STATUSES.TM_Removable))));

    }

    Drop_TM(tm_handler: PACKET_START_ADDRESSES_IN_TM_POOL): void {
        let _ld_TMstatus: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> = this.TMstatus;
        let _ld_TMpool: BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> = this.TMpool;
        this.TMpool = _ld_TMpool.domainSubstraction(new BSet<PACKET_START_ADDRESSES_IN_TM_POOL>(tm_handler));
        this.TMstatus = _ld_TMstatus.domainSubstraction(new BSet<PACKET_START_ADDRESSES_IN_TM_POOL>(tm_handler));

    }

    env_Deliver_TM(tm_pointer: PACKET_START_ADDRESSES_IN_TM_BUFFER): void {
        this.TMbuffer = this.TMbuffer.domainSubstraction(new BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER>(tm_pointer));

    }

    _get_VALID_TCS(): BSet<TC_SET> {
        return obsw_M001_1.VALID_TCS;
    }

    _get_TCstatus(): BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES> {
        return this.TCstatus;
    }

    _get_TMstatus(): BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES> {
        return this.TMstatus;
    }

    _get_TCbuffer(): BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET> {
        return this.TCbuffer;
    }

    _get_TCpool(): BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET> {
        return this.TCpool;
    }

    _get_TMbuffer(): BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET> {
        return this.TMbuffer;
    }

    _get_TMpool(): BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET> {
        return this.TMpool;
    }

    _get__TC_SET(): BSet<TC_SET> {
        return obsw_M001_1._TC_SET;
    }

    _get__TC_STATUSES(): BSet<TC_STATUSES> {
        return obsw_M001_1._TC_STATUSES;
    }

    _get__TM_STATUSES(): BSet<TM_STATUSES> {
        return obsw_M001_1._TM_STATUSES;
    }

    equals(o: any): boolean {
        let o1: obsw_M001_1 = this;
        let o2: obsw_M001_1 = o as obsw_M001_1;
        return o1._get_TCstatus().equals(o2._get_TCstatus()) && o1._get_TMstatus().equals(o2._get_TMstatus()) && o1._get_TCbuffer().equals(o2._get_TCbuffer()) && o1._get_TCpool().equals(o2._get_TCpool()) && o1._get_TMbuffer().equals(o2._get_TMbuffer()) && o1._get_TMpool().equals(o2._get_TMpool());
    }



    hashCode(): number {
        return this._hashCode_1();
    }

    _hashCode_1(): number {
        let result: number = 1;
        result = (1543 * result) ^ ((this._get_TCstatus()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_TMstatus()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_TCbuffer()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_TCpool()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_TMbuffer()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_TMpool()).hashCode() << 1);
        return result;
    }

    _hashCode_2(): number {
        let result: number = 1;
        result = (6151 * result) ^ ((this._get_TCstatus()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_TMstatus()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_TCbuffer()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_TCpool()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_TMbuffer()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_TMpool()).hashCode() << 1);
        return result;
    }

    /* TODO
    toString(): string {
        return String.join("\n", "_get_TCstatus: " + (this._get_TCstatus()).toString(), "_get_TMstatus: " + (this._get_TMstatus()).toString(), "_get_TCbuffer: " + (this._get_TCbuffer()).toString(), "_get_TCpool: " + (this._get_TCpool()).toString(), "_get_TMbuffer: " + (this._get_TMbuffer()).toString(), "_get_TMpool: " + (this._get_TMpool()).toString());
    }
    */

    _tr_env_Receive_TC(): BSet<BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER>> {
        let _ic_set_0: BSet<BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER>> = new BSet<BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER>>();
        for(let _ic_tc_pointer_1 of obsw_M001_1._PACKET_START_ADDRESSES_IN_TC_BUFFER) {
            if(this.TCbuffer.isNotInDomain(_ic_tc_pointer_1).booleanValue()) {
                for(let _ic_tc_1 of obsw_M001_1._TC_SET) {
                    if((obsw_M001_1._TC_SET.elementOf(_ic_tc_1)).booleanValue()) {
                        _ic_set_0 = _ic_set_0.union(new BSet<BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER>>(new BTuple(_ic_tc_1, _ic_tc_pointer_1)));
                    }

                }

            }
        }

        return _ic_set_0;
    }

    _tr_Poll_TC(): BSet<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER>> {
        let _ic_set_1: BSet<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER>> = new BSet<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER>>();
        for(let _ic_tc_pointer_1 of this.TCbuffer.domain()) {
            for(let _ic_tc_handler_1 of obsw_M001_1._PACKET_START_ADDRESSES_IN_TC_POOL) {
                if((this.TCpool.isNotInDomain(_ic_tc_handler_1)).booleanValue()) {
                    _ic_set_1 = _ic_set_1.union(new BSet<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER>>(new BTuple(_ic_tc_handler_1, _ic_tc_pointer_1)));
                }

            }

        }

        return _ic_set_1;
    }

    _tr_Accept_TC(): BSet<PACKET_START_ADDRESSES_IN_TC_POOL> {
        let _ic_set_2: BSet<PACKET_START_ADDRESSES_IN_TC_POOL> = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
        for(let _ic_tc_handler_1 of this.TCpool.domain()) {
            if((new BBoolean(new BBoolean(obsw_M001_1.VALID_TCS.elementOf(this.TCpool.functionCall(_ic_tc_handler_1)).booleanValue() && this.TCstatus.isInDomain(_ic_tc_handler_1).booleanValue()).booleanValue() && this.TCstatus.functionCall(_ic_tc_handler_1).equal(new TC_STATUSES(enum_TC_STATUSES.TC_Unchecked)).booleanValue())).booleanValue()) {
                _ic_set_2 = _ic_set_2.union(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
            }

        }

        return _ic_set_2;
    }

    _tr_Reject_TC(): BSet<PACKET_START_ADDRESSES_IN_TC_POOL> {
        let _ic_set_3: BSet<PACKET_START_ADDRESSES_IN_TC_POOL> = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
        for(let _ic_tc_handler_1 of this.TCpool.domain()) {
            if((new BBoolean(this.TCstatus.isInDomain(_ic_tc_handler_1).booleanValue() && this.TCstatus.functionCall(_ic_tc_handler_1).equal(new TC_STATUSES(enum_TC_STATUSES.TC_Unchecked)).booleanValue())).booleanValue()) {
                _ic_set_3 = _ic_set_3.union(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
            }

        }

        return _ic_set_3;
    }

    _tr_Report_TC_Acceptance(): BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> {
        let _ic_set_4: BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> = new BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>();
        for(let _ic_tc_handler_1 of this.TCpool.domain()) {
            if(this.TCstatus.isInDomain(_ic_tc_handler_1).booleanValue()) {
                if(this.TCstatus.functionCall(_ic_tc_handler_1).equal(new TC_STATUSES(enum_TC_STATUSES.TC_Accepted)).booleanValue()) {
                    for(let _ic_tm_1 of obsw_M001_1._TM_SET) {
                        for(let _ic_tm_handler_1 of obsw_M001_1._PACKET_START_ADDRESSES_IN_TM_POOL) {
                            if((this.TMpool.isNotInDomain(_ic_tm_handler_1)).booleanValue()) {
                                _ic_set_4 = _ic_set_4.union(new BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>(new BTuple(new BTuple(_ic_tc_handler_1, _ic_tm_1), _ic_tm_handler_1)));
                            }

                        }

                    }

                }
            }
        }

        return _ic_set_4;
    }

    _tr_Skip_TC_Acceptance_Report(): BSet<PACKET_START_ADDRESSES_IN_TC_POOL> {
        let _ic_set_5: BSet<PACKET_START_ADDRESSES_IN_TC_POOL> = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
        for(let _ic_tc_handler_1 of this.TCpool.domain()) {
            if((new BBoolean(this.TCstatus.isInDomain(_ic_tc_handler_1).booleanValue() && this.TCstatus.functionCall(_ic_tc_handler_1).equal(new TC_STATUSES(enum_TC_STATUSES.TC_Accepted)).booleanValue())).booleanValue()) {
                _ic_set_5 = _ic_set_5.union(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
            }

        }

        return _ic_set_5;
    }

    _tr_Report_TC_Rejection(): BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> {
        let _ic_set_6: BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> = new BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>();
        for(let _ic_tc_handler_1 of this.TCpool.domain()) {
            if(this.TCstatus.isInDomain(_ic_tc_handler_1).booleanValue()) {
                if(this.TCstatus.functionCall(_ic_tc_handler_1).equal(new TC_STATUSES(enum_TC_STATUSES.TC_Rejected)).booleanValue()) {
                    for(let _ic_tm_1 of obsw_M001_1._TM_SET) {
                        for(let _ic_tm_handler_1 of obsw_M001_1._PACKET_START_ADDRESSES_IN_TM_POOL) {
                            if((this.TMpool.isNotInDomain(_ic_tm_handler_1)).booleanValue()) {
                                _ic_set_6 = _ic_set_6.union(new BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>(new BTuple(new BTuple(_ic_tc_handler_1, _ic_tm_1), _ic_tm_handler_1)));
                            }

                        }

                    }

                }
            }
        }

        return _ic_set_6;
    }

    _tr_Skip_TC_Rejection_Report(): BSet<PACKET_START_ADDRESSES_IN_TC_POOL> {
        let _ic_set_7: BSet<PACKET_START_ADDRESSES_IN_TC_POOL> = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
        for(let _ic_tc_handler_1 of this.TCpool.domain()) {
            if((new BBoolean(this.TCstatus.isInDomain(_ic_tc_handler_1).booleanValue() && this.TCstatus.functionCall(_ic_tc_handler_1).equal(new TC_STATUSES(enum_TC_STATUSES.TC_Rejected)).booleanValue())).booleanValue()) {
                _ic_set_7 = _ic_set_7.union(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
            }

        }

        return _ic_set_7;
    }

    _tr_Execute_TC_Successfully(): BSet<PACKET_START_ADDRESSES_IN_TC_POOL> {
        let _ic_set_8: BSet<PACKET_START_ADDRESSES_IN_TC_POOL> = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
        for(let _ic_tc_handler_1 of this.TCpool.domain()) {
            if((new BBoolean(this.TCstatus.isInDomain(_ic_tc_handler_1).booleanValue() && this.TCstatus.functionCall(_ic_tc_handler_1).equal(new TC_STATUSES(enum_TC_STATUSES.TC_Waiting_for_Execution)).booleanValue())).booleanValue()) {
                _ic_set_8 = _ic_set_8.union(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
            }

        }

        return _ic_set_8;
    }

    _tr_Reset_TM_Buffer(): BSet<PACKET_START_ADDRESSES_IN_TC_POOL> {
        let _ic_set_9: BSet<PACKET_START_ADDRESSES_IN_TC_POOL> = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
        for(let _ic_tc_handler_1 of this.TCpool.domain()) {
            if((new BBoolean(this.TCstatus.isInDomain(_ic_tc_handler_1).booleanValue() && this.TCstatus.functionCall(_ic_tc_handler_1).equal(new TC_STATUSES(enum_TC_STATUSES.TC_Waiting_for_Execution)).booleanValue())).booleanValue()) {
                _ic_set_9 = _ic_set_9.union(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
            }

        }

        return _ic_set_9;
    }

    _tr_Fail_TC_Execution(): BSet<PACKET_START_ADDRESSES_IN_TC_POOL> {
        let _ic_set_10: BSet<PACKET_START_ADDRESSES_IN_TC_POOL> = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
        for(let _ic_tc_handler_1 of this.TCpool.domain()) {
            if((new BBoolean(this.TCstatus.isInDomain(_ic_tc_handler_1).booleanValue() && this.TCstatus.functionCall(_ic_tc_handler_1).equal(new TC_STATUSES(enum_TC_STATUSES.TC_Waiting_for_Execution)).booleanValue())).booleanValue()) {
                _ic_set_10 = _ic_set_10.union(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
            }

        }

        return _ic_set_10;
    }

    _tr_Report_TC_Execution_Success(): BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> {
        let _ic_set_11: BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> = new BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>();
        for(let _ic_tc_handler_1 of this.TCpool.domain()) {
            if(this.TCstatus.isInDomain(_ic_tc_handler_1).booleanValue()) {
                if(this.TCstatus.functionCall(_ic_tc_handler_1).equal(new TC_STATUSES(enum_TC_STATUSES.TC_Successfully_Executed)).booleanValue()) {
                    for(let _ic_tm_1 of obsw_M001_1._TM_SET) {
                        for(let _ic_tm_handler_1 of obsw_M001_1._PACKET_START_ADDRESSES_IN_TM_POOL) {
                            if((this.TMpool.isNotInDomain(_ic_tm_handler_1)).booleanValue()) {
                                _ic_set_11 = _ic_set_11.union(new BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>(new BTuple(new BTuple(_ic_tc_handler_1, _ic_tm_1), _ic_tm_handler_1)));
                            }

                        }

                    }

                }
            }
        }

        return _ic_set_11;
    }

    _tr_Skip_TC_Success_Report(): BSet<PACKET_START_ADDRESSES_IN_TC_POOL> {
        let _ic_set_12: BSet<PACKET_START_ADDRESSES_IN_TC_POOL> = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
        for(let _ic_tc_handler_1 of this.TCpool.domain()) {
            if((new BBoolean(this.TCstatus.isInDomain(_ic_tc_handler_1).booleanValue() && this.TCstatus.functionCall(_ic_tc_handler_1).equal(new TC_STATUSES(enum_TC_STATUSES.TC_Successfully_Executed)).booleanValue())).booleanValue()) {
                _ic_set_12 = _ic_set_12.union(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
            }

        }

        return _ic_set_12;
    }

    _tr_Report_TC_Execution_Failure(): BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> {
        let _ic_set_13: BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> = new BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>();
        for(let _ic_tc_handler_1 of this.TCpool.domain()) {
            if(this.TCstatus.isInDomain(_ic_tc_handler_1).booleanValue()) {
                if(this.TCstatus.functionCall(_ic_tc_handler_1).equal(new TC_STATUSES(enum_TC_STATUSES.TC_Execution_Failed)).booleanValue()) {
                    for(let _ic_tm_1 of obsw_M001_1._TM_SET) {
                        for(let _ic_tm_handler_1 of obsw_M001_1._PACKET_START_ADDRESSES_IN_TM_POOL) {
                            if((this.TMpool.isNotInDomain(_ic_tm_handler_1)).booleanValue()) {
                                _ic_set_13 = _ic_set_13.union(new BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>(new BTuple(new BTuple(_ic_tc_handler_1, _ic_tm_1), _ic_tm_handler_1)));
                            }

                        }

                    }

                }
            }
        }

        return _ic_set_13;
    }

    _tr_Skip_TC_Failure_Report(): BSet<PACKET_START_ADDRESSES_IN_TC_POOL> {
        let _ic_set_14: BSet<PACKET_START_ADDRESSES_IN_TC_POOL> = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
        for(let _ic_tc_handler_1 of this.TCpool.domain()) {
            if((new BBoolean(this.TCstatus.isInDomain(_ic_tc_handler_1).booleanValue() && this.TCstatus.functionCall(_ic_tc_handler_1).equal(new TC_STATUSES(enum_TC_STATUSES.TC_Execution_Failed)).booleanValue())).booleanValue()) {
                _ic_set_14 = _ic_set_14.union(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
            }

        }

        return _ic_set_14;
    }

    _tr_Drop_TC(): BSet<PACKET_START_ADDRESSES_IN_TC_POOL> {
        let _ic_set_15: BSet<PACKET_START_ADDRESSES_IN_TC_POOL> = new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>();
        for(let _ic_tc_handler_1 of this.TCpool.domain()) {
            if((new BBoolean(this.TCstatus.isInDomain(_ic_tc_handler_1).booleanValue() && this.TCstatus.functionCall(_ic_tc_handler_1).equal(new TC_STATUSES(enum_TC_STATUSES.TC_Removable)).booleanValue())).booleanValue()) {
                _ic_set_15 = _ic_set_15.union(new BSet<PACKET_START_ADDRESSES_IN_TC_POOL>(_ic_tc_handler_1));
            }

        }

        return _ic_set_15;
    }

    _tr_Produce_TM(): BSet<BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL>> {
        let _ic_set_16: BSet<BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL>> = new BSet<BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL>>();
        for(let _ic_tm_1 of obsw_M001_1._TM_SET) {
            for(let _ic_tm_handler_1 of obsw_M001_1._PACKET_START_ADDRESSES_IN_TM_POOL) {
                if((this.TMpool.isNotInDomain(_ic_tm_handler_1)).booleanValue()) {
                    _ic_set_16 = _ic_set_16.union(new BSet<BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL>>(new BTuple(_ic_tm_1, _ic_tm_handler_1)));
                }

            }

        }

        return _ic_set_16;
    }

    _tr_Pass_TM(): BSet<BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER>> {
        let _ic_set_17: BSet<BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER>> = new BSet<BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER>>();
        for(let _ic_tm_handler_1 of this.TMpool.domain()) {
            if(this.TMstatus.isInDomain(_ic_tm_handler_1).booleanValue()) {
                if(this.TMstatus.functionCall(_ic_tm_handler_1).equal(new TM_STATUSES(enum_TM_STATUSES.TM_Effective)).booleanValue()) {
                    for(let _ic_tm_pointer_1 of obsw_M001_1._PACKET_START_ADDRESSES_IN_TM_BUFFER) {
                        if((this.TMbuffer.isNotInDomain(_ic_tm_pointer_1)).booleanValue()) {
                            _ic_set_17 = _ic_set_17.union(new BSet<BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER>>(new BTuple(_ic_tm_handler_1, _ic_tm_pointer_1)));
                        }

                    }

                }
            }
        }

        return _ic_set_17;
    }

    _tr_Cancel_TM(): BSet<PACKET_START_ADDRESSES_IN_TM_POOL> {
        let _ic_set_18: BSet<PACKET_START_ADDRESSES_IN_TM_POOL> = new BSet<PACKET_START_ADDRESSES_IN_TM_POOL>();
        for(let _ic_tm_handler_1 of this.TMpool.domain()) {
            if((new BBoolean(this.TMstatus.isInDomain(_ic_tm_handler_1).booleanValue() && this.TMstatus.functionCall(_ic_tm_handler_1).equal(new TM_STATUSES(enum_TM_STATUSES.TM_Effective)).booleanValue())).booleanValue()) {
                _ic_set_18 = _ic_set_18.union(new BSet<PACKET_START_ADDRESSES_IN_TM_POOL>(_ic_tm_handler_1));
            }

        }

        return _ic_set_18;
    }

    _tr_Drop_TM(): BSet<PACKET_START_ADDRESSES_IN_TM_POOL> {
        let _ic_set_19: BSet<PACKET_START_ADDRESSES_IN_TM_POOL> = new BSet<PACKET_START_ADDRESSES_IN_TM_POOL>();
        for(let _ic_tm_handler_1 of this.TMpool.domain()) {
            if((new BBoolean(this.TMstatus.isInDomain(_ic_tm_handler_1).booleanValue() && this.TMstatus.functionCall(_ic_tm_handler_1).equal(new TM_STATUSES(enum_TM_STATUSES.TM_Removable)).booleanValue())).booleanValue()) {
                _ic_set_19 = _ic_set_19.union(new BSet<PACKET_START_ADDRESSES_IN_TM_POOL>(_ic_tm_handler_1));
            }

        }

        return _ic_set_19;
    }

    _tr_env_Deliver_TM(): BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER> {
        let _ic_set_20: BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER> = new BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER>();
        for(let _ic_tm_pointer_1 of this.TMbuffer.domain()) {
            _ic_set_20 = _ic_set_20.union(new BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER>(_ic_tm_pointer_1));

        }

        return _ic_set_20;
    }

    _projected_state_for_Report_TC_Rejection(): _ProjectionRead_Report_TC_Rejection {
        return new _ProjectionRead_Report_TC_Rejection(this.TCpool,this.TCstatus,this.TMstatus,this.TMpool);
    }

    _projected_state_for_Report_TC_Execution_Success(): _ProjectionRead_Report_TC_Execution_Success {
        return new _ProjectionRead_Report_TC_Execution_Success(this.TCpool,this.TCstatus,this.TMstatus,this.TMpool);
    }

    _projected_state_for_Cancel_TM(): _ProjectionRead_Cancel_TM {
        return new _ProjectionRead_Cancel_TM(this.TMstatus,this.TMpool);
    }

    _projected_state_for_env_Receive_TC(): _ProjectionRead_env_Receive_TC {
        return new _ProjectionRead_env_Receive_TC(this.TCbuffer);
    }

    _projected_state_for_Report_TC_Execution_Failure(): _ProjectionRead_Report_TC_Execution_Failure {
        return new _ProjectionRead_Report_TC_Execution_Failure(this.TCpool,this.TCstatus,this.TMstatus,this.TMpool);
    }

    _projected_state_for_Pass_TM(): _ProjectionRead_Pass_TM {
        return new _ProjectionRead_Pass_TM(this.TMbuffer,this.TMstatus,this.TMpool);
    }

    _projected_state_for_Drop_TM(): _ProjectionRead_Drop_TM {
        return new _ProjectionRead_Drop_TM(this.TMstatus,this.TMpool);
    }

    _projected_state_for_Reset_TM_Buffer(): _ProjectionRead_Reset_TM_Buffer {
        return new _ProjectionRead_Reset_TM_Buffer(this.TCpool,this.TCstatus);
    }

    _projected_state_for_Skip_TC_Failure_Report(): _ProjectionRead_Skip_TC_Failure_Report {
        return new _ProjectionRead_Skip_TC_Failure_Report(this.TCpool,this.TCstatus);
    }

    _projected_state_for_Poll_TC(): _ProjectionRead_Poll_TC {
        return new _ProjectionRead_Poll_TC(this.TCbuffer,this.TCpool,this.TCstatus);
    }

    _projected_state_for_Skip_TC_Acceptance_Report(): _ProjectionRead_Skip_TC_Acceptance_Report {
        return new _ProjectionRead_Skip_TC_Acceptance_Report(this.TCpool,this.TCstatus);
    }

    _projected_state_for_Accept_TC(): _ProjectionRead_Accept_TC {
        return new _ProjectionRead_Accept_TC(this.TCpool,this.TCstatus);
    }

    _projected_state_for_Fail_TC_Execution(): _ProjectionRead_Fail_TC_Execution {
        return new _ProjectionRead_Fail_TC_Execution(this.TCpool,this.TCstatus);
    }

    _projected_state_for_Report_TC_Acceptance(): _ProjectionRead_Report_TC_Acceptance {
        return new _ProjectionRead_Report_TC_Acceptance(this.TCpool,this.TCstatus,this.TMstatus,this.TMpool);
    }

    _projected_state_for_Reject_TC(): _ProjectionRead_Reject_TC {
        return new _ProjectionRead_Reject_TC(this.TCpool,this.TCstatus);
    }

    _projected_state_for_Skip_TC_Rejection_Report(): _ProjectionRead_Skip_TC_Rejection_Report {
        return new _ProjectionRead_Skip_TC_Rejection_Report(this.TCpool,this.TCstatus);
    }

    _projected_state_for_env_Deliver_TM(): _ProjectionRead_env_Deliver_TM {
        return new _ProjectionRead_env_Deliver_TM(this.TMbuffer);
    }

    _projected_state_for_Execute_TC_Successfully(): _ProjectionRead_Execute_TC_Successfully {
        return new _ProjectionRead_Execute_TC_Successfully(this.TCpool,this.TCstatus);
    }

    _projected_state_for_Skip_TC_Success_Report(): _ProjectionRead_Skip_TC_Success_Report {
        return new _ProjectionRead_Skip_TC_Success_Report(this.TCpool,this.TCstatus);
    }

    _projected_state_for_Drop_TC(): _ProjectionRead_Drop_TC {
        return new _ProjectionRead_Drop_TC(this.TCpool,this.TCstatus);
    }

    _projected_state_for_Produce_TM(): _ProjectionRead_Produce_TM {
        return new _ProjectionRead_Produce_TM(this.TMstatus,this.TMpool);
    }

    _projected_state_for__tr_Poll_TC(): _ProjectionRead__tr_Poll_TC {
        return new _ProjectionRead__tr_Poll_TC(this.TCbuffer,this.TCpool);
    }

    _projected_state_for__tr_Reset_TM_Buffer(): _ProjectionRead__tr_Reset_TM_Buffer {
        return new _ProjectionRead__tr_Reset_TM_Buffer(this.TCpool,this.TCstatus);
    }

    _projected_state_for__tr_Drop_TM(): _ProjectionRead__tr_Drop_TM {
        return new _ProjectionRead__tr_Drop_TM(this.TMstatus,this.TMpool);
    }

    _projected_state_for__tr_env_Receive_TC(): _ProjectionRead__tr_env_Receive_TC {
        return new _ProjectionRead__tr_env_Receive_TC(this.TCbuffer);
    }

    _projected_state_for__tr_Accept_TC(): _ProjectionRead__tr_Accept_TC {
        return new _ProjectionRead__tr_Accept_TC(this.TCpool,this.TCstatus);
    }

    _projected_state_for__tr_Skip_TC_Failure_Report(): _ProjectionRead__tr_Skip_TC_Failure_Report {
        return new _ProjectionRead__tr_Skip_TC_Failure_Report(this.TCpool,this.TCstatus);
    }

    _projected_state_for__tr_Cancel_TM(): _ProjectionRead__tr_Cancel_TM {
        return new _ProjectionRead__tr_Cancel_TM(this.TMstatus,this.TMpool);
    }

    _projected_state_for__tr_Report_TC_Execution_Success(): _ProjectionRead__tr_Report_TC_Execution_Success {
        return new _ProjectionRead__tr_Report_TC_Execution_Success(this.TCpool,this.TCstatus,this.TMpool);
    }

    _projected_state_for__tr_Execute_TC_Successfully(): _ProjectionRead__tr_Execute_TC_Successfully {
        return new _ProjectionRead__tr_Execute_TC_Successfully(this.TCpool,this.TCstatus);
    }

    _projected_state_for__tr_Drop_TC(): _ProjectionRead__tr_Drop_TC {
        return new _ProjectionRead__tr_Drop_TC(this.TCpool,this.TCstatus);
    }

    _projected_state_for__tr_Skip_TC_Acceptance_Report(): _ProjectionRead__tr_Skip_TC_Acceptance_Report {
        return new _ProjectionRead__tr_Skip_TC_Acceptance_Report(this.TCpool,this.TCstatus);
    }

    _projected_state_for__tr_Report_TC_Rejection(): _ProjectionRead__tr_Report_TC_Rejection {
        return new _ProjectionRead__tr_Report_TC_Rejection(this.TCpool,this.TCstatus,this.TMpool);
    }

    _projected_state_for__tr_Produce_TM(): _ProjectionRead__tr_Produce_TM {
        return new _ProjectionRead__tr_Produce_TM(this.TMpool);
    }

    _projected_state_for__tr_Pass_TM(): _ProjectionRead__tr_Pass_TM {
        return new _ProjectionRead__tr_Pass_TM(this.TMbuffer,this.TMstatus,this.TMpool);
    }

    _projected_state_for__tr_Fail_TC_Execution(): _ProjectionRead__tr_Fail_TC_Execution {
        return new _ProjectionRead__tr_Fail_TC_Execution(this.TCpool,this.TCstatus);
    }

    _projected_state_for__tr_Report_TC_Acceptance(): _ProjectionRead__tr_Report_TC_Acceptance {
        return new _ProjectionRead__tr_Report_TC_Acceptance(this.TCpool,this.TCstatus,this.TMpool);
    }

    _projected_state_for__tr_Reject_TC(): _ProjectionRead__tr_Reject_TC {
        return new _ProjectionRead__tr_Reject_TC(this.TCpool,this.TCstatus);
    }

    _projected_state_for__tr_Skip_TC_Success_Report(): _ProjectionRead__tr_Skip_TC_Success_Report {
        return new _ProjectionRead__tr_Skip_TC_Success_Report(this.TCpool,this.TCstatus);
    }

    _projected_state_for__tr_Report_TC_Execution_Failure(): _ProjectionRead__tr_Report_TC_Execution_Failure {
        return new _ProjectionRead__tr_Report_TC_Execution_Failure(this.TCpool,this.TCstatus,this.TMpool);
    }

    _projected_state_for__tr_env_Deliver_TM(): _ProjectionRead__tr_env_Deliver_TM {
        return new _ProjectionRead__tr_env_Deliver_TM(this.TMbuffer);
    }

    _projected_state_for__tr_Skip_TC_Rejection_Report(): _ProjectionRead__tr_Skip_TC_Rejection_Report {
        return new _ProjectionRead__tr_Skip_TC_Rejection_Report(this.TCpool,this.TCstatus);
    }

    _projected_state_for__check_inv_2(): _ProjectionRead__check_inv_2 {
        return new _ProjectionRead__check_inv_2(this.TCpool,this.TCstatus);
    }

    _projected_state_for__check_inv_3(): _ProjectionRead__check_inv_3 {
        return new _ProjectionRead__check_inv_3(this.TCpool,this.TCstatus);
    }

    _projected_state_for__check_inv_1(): _ProjectionRead__check_inv_1 {
        return new _ProjectionRead__check_inv_1(this.TCstatus);
    }

    _projected_state_for__check_inv_6(): _ProjectionRead__check_inv_6 {
        return new _ProjectionRead__check_inv_6(this.TCbuffer);
    }

    _projected_state_for__check_inv_7(): _ProjectionRead__check_inv_7 {
        return new _ProjectionRead__check_inv_7(this.TMbuffer);
    }

    _projected_state_for__check_inv_4(): _ProjectionRead__check_inv_4 {
        return new _ProjectionRead__check_inv_4(this.TMstatus);
    }

    _projected_state_for__check_inv_5(): _ProjectionRead__check_inv_5 {
        return new _ProjectionRead__check_inv_5(this.TMstatus,this.TMpool);
    }

    _projected_state_for__check_inv_8(): _ProjectionRead__check_inv_8 {
        return new _ProjectionRead__check_inv_8(this.TCpool);
    }

    _projected_state_for__check_inv_9(): _ProjectionRead__check_inv_9 {
        return new _ProjectionRead__check_inv_9(this.TMpool);
    }

    _update_for_Report_TC_Rejection(): _ProjectionWrite_Report_TC_Rejection {
        return new _ProjectionWrite_Report_TC_Rejection(this.TCstatus,this.TMstatus,this.TMpool);
    }

    _update_for_Report_TC_Execution_Success(): _ProjectionWrite_Report_TC_Execution_Success {
        return new _ProjectionWrite_Report_TC_Execution_Success(this.TCstatus,this.TMstatus,this.TMpool);
    }

    _update_for_Cancel_TM(): _ProjectionWrite_Cancel_TM {
        return new _ProjectionWrite_Cancel_TM(this.TMstatus);
    }

    _update_for_env_Receive_TC(): _ProjectionWrite_env_Receive_TC {
        return new _ProjectionWrite_env_Receive_TC(this.TCbuffer);
    }

    _update_for_Report_TC_Execution_Failure(): _ProjectionWrite_Report_TC_Execution_Failure {
        return new _ProjectionWrite_Report_TC_Execution_Failure(this.TCstatus,this.TMstatus,this.TMpool);
    }

    _update_for_Pass_TM(): _ProjectionWrite_Pass_TM {
        return new _ProjectionWrite_Pass_TM(this.TMbuffer,this.TMstatus);
    }

    _update_for_Drop_TM(): _ProjectionWrite_Drop_TM {
        return new _ProjectionWrite_Drop_TM(this.TMstatus,this.TMpool);
    }

    _update_for_Reset_TM_Buffer(): _ProjectionWrite_Reset_TM_Buffer {
        return new _ProjectionWrite_Reset_TM_Buffer(this.TCstatus,this.TMbuffer);
    }

    _update_for_Skip_TC_Failure_Report(): _ProjectionWrite_Skip_TC_Failure_Report {
        return new _ProjectionWrite_Skip_TC_Failure_Report(this.TCstatus);
    }

    _update_for_Poll_TC(): _ProjectionWrite_Poll_TC {
        return new _ProjectionWrite_Poll_TC(this.TCpool,this.TCbuffer,this.TCstatus);
    }

    _update_for_Skip_TC_Acceptance_Report(): _ProjectionWrite_Skip_TC_Acceptance_Report {
        return new _ProjectionWrite_Skip_TC_Acceptance_Report(this.TCstatus);
    }

    _update_for_Accept_TC(): _ProjectionWrite_Accept_TC {
        return new _ProjectionWrite_Accept_TC(this.TCstatus);
    }

    _update_for_Fail_TC_Execution(): _ProjectionWrite_Fail_TC_Execution {
        return new _ProjectionWrite_Fail_TC_Execution(this.TCstatus);
    }

    _update_for_Report_TC_Acceptance(): _ProjectionWrite_Report_TC_Acceptance {
        return new _ProjectionWrite_Report_TC_Acceptance(this.TCstatus,this.TMstatus,this.TMpool);
    }

    _update_for_Reject_TC(): _ProjectionWrite_Reject_TC {
        return new _ProjectionWrite_Reject_TC(this.TCstatus);
    }

    _update_for_Skip_TC_Rejection_Report(): _ProjectionWrite_Skip_TC_Rejection_Report {
        return new _ProjectionWrite_Skip_TC_Rejection_Report(this.TCstatus);
    }

    _update_for_env_Deliver_TM(): _ProjectionWrite_env_Deliver_TM {
        return new _ProjectionWrite_env_Deliver_TM(this.TMbuffer);
    }

    _update_for_Execute_TC_Successfully(): _ProjectionWrite_Execute_TC_Successfully {
        return new _ProjectionWrite_Execute_TC_Successfully(this.TCstatus);
    }

    _update_for_Skip_TC_Success_Report(): _ProjectionWrite_Skip_TC_Success_Report {
        return new _ProjectionWrite_Skip_TC_Success_Report(this.TCstatus);
    }

    _update_for_Drop_TC(): _ProjectionWrite_Drop_TC {
        return new _ProjectionWrite_Drop_TC(this.TCpool,this.TCstatus);
    }

    _update_for_Produce_TM(): _ProjectionWrite_Produce_TM {
        return new _ProjectionWrite_Produce_TM(this.TMstatus,this.TMpool);
    }

    _apply_update_for_Report_TC_Rejection(update : _ProjectionWrite_Report_TC_Rejection): void {
        this.TCstatus = update.TCstatus;
        this.TMstatus = update.TMstatus;
        this.TMpool = update.TMpool;
    }

    _apply_update_for_Report_TC_Execution_Success(update : _ProjectionWrite_Report_TC_Execution_Success): void {
        this.TCstatus = update.TCstatus;
        this.TMstatus = update.TMstatus;
        this.TMpool = update.TMpool;
    }

    _apply_update_for_Cancel_TM(update : _ProjectionWrite_Cancel_TM): void {
        this.TMstatus = update.TMstatus;
    }

    _apply_update_for_env_Receive_TC(update : _ProjectionWrite_env_Receive_TC): void {
        this.TCbuffer = update.TCbuffer;
    }

    _apply_update_for_Report_TC_Execution_Failure(update : _ProjectionWrite_Report_TC_Execution_Failure): void {
        this.TCstatus = update.TCstatus;
        this.TMstatus = update.TMstatus;
        this.TMpool = update.TMpool;
    }

    _apply_update_for_Pass_TM(update : _ProjectionWrite_Pass_TM): void {
        this.TMbuffer = update.TMbuffer;
        this.TMstatus = update.TMstatus;
    }

    _apply_update_for_Drop_TM(update : _ProjectionWrite_Drop_TM): void {
        this.TMstatus = update.TMstatus;
        this.TMpool = update.TMpool;
    }

    _apply_update_for_Reset_TM_Buffer(update : _ProjectionWrite_Reset_TM_Buffer): void {
        this.TCstatus = update.TCstatus;
        this.TMbuffer = update.TMbuffer;
    }

    _apply_update_for_Skip_TC_Failure_Report(update : _ProjectionWrite_Skip_TC_Failure_Report): void {
        this.TCstatus = update.TCstatus;
    }

    _apply_update_for_Poll_TC(update : _ProjectionWrite_Poll_TC): void {
        this.TCpool = update.TCpool;
        this.TCbuffer = update.TCbuffer;
        this.TCstatus = update.TCstatus;
    }

    _apply_update_for_Skip_TC_Acceptance_Report(update : _ProjectionWrite_Skip_TC_Acceptance_Report): void {
        this.TCstatus = update.TCstatus;
    }

    _apply_update_for_Accept_TC(update : _ProjectionWrite_Accept_TC): void {
        this.TCstatus = update.TCstatus;
    }

    _apply_update_for_Fail_TC_Execution(update : _ProjectionWrite_Fail_TC_Execution): void {
        this.TCstatus = update.TCstatus;
    }

    _apply_update_for_Report_TC_Acceptance(update : _ProjectionWrite_Report_TC_Acceptance): void {
        this.TCstatus = update.TCstatus;
        this.TMstatus = update.TMstatus;
        this.TMpool = update.TMpool;
    }

    _apply_update_for_Reject_TC(update : _ProjectionWrite_Reject_TC): void {
        this.TCstatus = update.TCstatus;
    }

    _apply_update_for_Skip_TC_Rejection_Report(update : _ProjectionWrite_Skip_TC_Rejection_Report): void {
        this.TCstatus = update.TCstatus;
    }

    _apply_update_for_env_Deliver_TM(update : _ProjectionWrite_env_Deliver_TM): void {
        this.TMbuffer = update.TMbuffer;
    }

    _apply_update_for_Execute_TC_Successfully(update : _ProjectionWrite_Execute_TC_Successfully): void {
        this.TCstatus = update.TCstatus;
    }

    _apply_update_for_Skip_TC_Success_Report(update : _ProjectionWrite_Skip_TC_Success_Report): void {
        this.TCstatus = update.TCstatus;
    }

    _apply_update_for_Drop_TC(update : _ProjectionWrite_Drop_TC): void {
        this.TCpool = update.TCpool;
        this.TCstatus = update.TCstatus;
    }

    _apply_update_for_Produce_TM(update : _ProjectionWrite_Produce_TM): void {
        this.TMstatus = update.TMstatus;
        this.TMpool = update.TMpool;
    }

    _check_inv_1() {
        return this.TCstatus.checkDomain(obsw_M001_1._PACKET_START_ADDRESSES_IN_TC_POOL).and(this.TCstatus.checkRange(obsw_M001_1._TC_STATUSES)).and(this.TCstatus.isFunction()).and(this.TCstatus.isPartial(obsw_M001_1._PACKET_START_ADDRESSES_IN_TC_POOL)).booleanValue();
    }

    _check_inv_2() {
        return this.TCstatus.domain().equal(this.TCpool.domain()).booleanValue();
    }

    _check_inv_3() {
        let _ic_boolean_21: BBoolean = new BBoolean(true);
        for(let _ic_tc_handler_1 of this.TCstatus.domain()) {
            if(!(new BBoolean(!new BSet<TC_STATUSES>(new TC_STATUSES(enum_TC_STATUSES.TC_Accepted), new TC_STATUSES(enum_TC_STATUSES.TC_Waiting_for_Execution), new TC_STATUSES(enum_TC_STATUSES.TC_Successfully_Executed), new TC_STATUSES(enum_TC_STATUSES.TC_Execution_Failed)).elementOf(this.TCstatus.functionCall(_ic_tc_handler_1)).booleanValue() || obsw_M001_1.VALID_TCS.elementOf(this.TCpool.functionCall(_ic_tc_handler_1)).booleanValue())).booleanValue()) {
                _ic_boolean_21 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_21.booleanValue();
    }

    _check_inv_4() {
        return this.TMstatus.checkDomain(obsw_M001_1._PACKET_START_ADDRESSES_IN_TM_POOL).and(this.TMstatus.checkRange(obsw_M001_1._TM_STATUSES)).and(this.TMstatus.isFunction()).and(this.TMstatus.isPartial(obsw_M001_1._PACKET_START_ADDRESSES_IN_TM_POOL)).booleanValue();
    }

    _check_inv_5() {
        return this.TMstatus.domain().equal(this.TMpool.domain()).booleanValue();
    }

    _check_inv_6() {
        return this.TCbuffer.checkDomain(obsw_M001_1._PACKET_START_ADDRESSES_IN_TC_BUFFER).and(this.TCbuffer.checkRange(obsw_M001_1._TC_SET)).and(this.TCbuffer.isFunction()).and(this.TCbuffer.isPartial(obsw_M001_1._PACKET_START_ADDRESSES_IN_TC_BUFFER)).booleanValue();
    }

    _check_inv_7() {
        return this.TMbuffer.checkDomain(obsw_M001_1._PACKET_START_ADDRESSES_IN_TM_BUFFER).and(this.TMbuffer.checkRange(obsw_M001_1._TM_SET)).and(this.TMbuffer.isFunction()).and(this.TMbuffer.isPartial(obsw_M001_1._PACKET_START_ADDRESSES_IN_TM_BUFFER)).booleanValue();
    }

    _check_inv_8() {
        return this.TCpool.checkDomain(obsw_M001_1._PACKET_START_ADDRESSES_IN_TC_POOL).and(this.TCpool.checkRange(obsw_M001_1._TC_SET)).and(this.TCpool.isFunction()).and(this.TCpool.isPartial(obsw_M001_1._PACKET_START_ADDRESSES_IN_TC_POOL)).booleanValue();
    }

    _check_inv_9() {
        return this.TMpool.checkDomain(obsw_M001_1._PACKET_START_ADDRESSES_IN_TM_POOL).and(this.TMpool.checkRange(obsw_M001_1._TM_SET)).and(this.TMpool.isFunction()).and(this.TMpool.isPartial(obsw_M001_1._PACKET_START_ADDRESSES_IN_TM_POOL)).booleanValue();
    }


    public _copy(): obsw_M001_1 {
      return new obsw_M001_1(this);
    }


}


export class ModelChecker {
    private type: Type;
    private isCaching: boolean;
    private isDebug: boolean;

    private unvisitedStates: LinkedList<obsw_M001_1> = new LinkedList<obsw_M001_1>;
    private states: immutable.Set<obsw_M001_1> = new immutable.Set();
    private transitions: number = 0;

    private invariantViolated: boolean = false;
    private deadlockDetected: boolean = false;
    private counterExampleState: obsw_M001_1 = undefined;

    _OpCache_env_Receive_TC: immutable.Map<BSet<BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER>>, immutable.Map<_ProjectionRead_env_Receive_TC, _ProjectionWrite_env_Receive_TC>> = new immutable.Map();
    _OpCache_tr_env_Receive_TC: immutable.Map<_ProjectionRead__tr_env_Receive_TC, BSet<BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER>>> = new immutable.Map();

    _OpCache_Poll_TC: immutable.Map<BSet<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER>>, immutable.Map<_ProjectionRead_Poll_TC, _ProjectionWrite_Poll_TC>> = new immutable.Map();
    _OpCache_tr_Poll_TC: immutable.Map<_ProjectionRead__tr_Poll_TC, BSet<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER>>> = new immutable.Map();

    _OpCache_Accept_TC: immutable.Map<BSet<PACKET_START_ADDRESSES_IN_TC_POOL>, immutable.Map<_ProjectionRead_Accept_TC, _ProjectionWrite_Accept_TC>> = new immutable.Map();
    _OpCache_tr_Accept_TC: immutable.Map<_ProjectionRead__tr_Accept_TC, BSet<PACKET_START_ADDRESSES_IN_TC_POOL>> = new immutable.Map();

    _OpCache_Reject_TC: immutable.Map<BSet<PACKET_START_ADDRESSES_IN_TC_POOL>, immutable.Map<_ProjectionRead_Reject_TC, _ProjectionWrite_Reject_TC>> = new immutable.Map();
    _OpCache_tr_Reject_TC: immutable.Map<_ProjectionRead__tr_Reject_TC, BSet<PACKET_START_ADDRESSES_IN_TC_POOL>> = new immutable.Map();

    _OpCache_Report_TC_Acceptance: immutable.Map<BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>, immutable.Map<_ProjectionRead_Report_TC_Acceptance, _ProjectionWrite_Report_TC_Acceptance>> = new immutable.Map();
    _OpCache_tr_Report_TC_Acceptance: immutable.Map<_ProjectionRead__tr_Report_TC_Acceptance, BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>> = new immutable.Map();

    _OpCache_Skip_TC_Acceptance_Report: immutable.Map<BSet<PACKET_START_ADDRESSES_IN_TC_POOL>, immutable.Map<_ProjectionRead_Skip_TC_Acceptance_Report, _ProjectionWrite_Skip_TC_Acceptance_Report>> = new immutable.Map();
    _OpCache_tr_Skip_TC_Acceptance_Report: immutable.Map<_ProjectionRead__tr_Skip_TC_Acceptance_Report, BSet<PACKET_START_ADDRESSES_IN_TC_POOL>> = new immutable.Map();

    _OpCache_Report_TC_Rejection: immutable.Map<BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>, immutable.Map<_ProjectionRead_Report_TC_Rejection, _ProjectionWrite_Report_TC_Rejection>> = new immutable.Map();
    _OpCache_tr_Report_TC_Rejection: immutable.Map<_ProjectionRead__tr_Report_TC_Rejection, BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>> = new immutable.Map();

    _OpCache_Skip_TC_Rejection_Report: immutable.Map<BSet<PACKET_START_ADDRESSES_IN_TC_POOL>, immutable.Map<_ProjectionRead_Skip_TC_Rejection_Report, _ProjectionWrite_Skip_TC_Rejection_Report>> = new immutable.Map();
    _OpCache_tr_Skip_TC_Rejection_Report: immutable.Map<_ProjectionRead__tr_Skip_TC_Rejection_Report, BSet<PACKET_START_ADDRESSES_IN_TC_POOL>> = new immutable.Map();

    _OpCache_Execute_TC_Successfully: immutable.Map<BSet<PACKET_START_ADDRESSES_IN_TC_POOL>, immutable.Map<_ProjectionRead_Execute_TC_Successfully, _ProjectionWrite_Execute_TC_Successfully>> = new immutable.Map();
    _OpCache_tr_Execute_TC_Successfully: immutable.Map<_ProjectionRead__tr_Execute_TC_Successfully, BSet<PACKET_START_ADDRESSES_IN_TC_POOL>> = new immutable.Map();

    _OpCache_Reset_TM_Buffer: immutable.Map<BSet<PACKET_START_ADDRESSES_IN_TC_POOL>, immutable.Map<_ProjectionRead_Reset_TM_Buffer, _ProjectionWrite_Reset_TM_Buffer>> = new immutable.Map();
    _OpCache_tr_Reset_TM_Buffer: immutable.Map<_ProjectionRead__tr_Reset_TM_Buffer, BSet<PACKET_START_ADDRESSES_IN_TC_POOL>> = new immutable.Map();

    _OpCache_Fail_TC_Execution: immutable.Map<BSet<PACKET_START_ADDRESSES_IN_TC_POOL>, immutable.Map<_ProjectionRead_Fail_TC_Execution, _ProjectionWrite_Fail_TC_Execution>> = new immutable.Map();
    _OpCache_tr_Fail_TC_Execution: immutable.Map<_ProjectionRead__tr_Fail_TC_Execution, BSet<PACKET_START_ADDRESSES_IN_TC_POOL>> = new immutable.Map();

    _OpCache_Report_TC_Execution_Success: immutable.Map<BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>, immutable.Map<_ProjectionRead_Report_TC_Execution_Success, _ProjectionWrite_Report_TC_Execution_Success>> = new immutable.Map();
    _OpCache_tr_Report_TC_Execution_Success: immutable.Map<_ProjectionRead__tr_Report_TC_Execution_Success, BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>> = new immutable.Map();

    _OpCache_Skip_TC_Success_Report: immutable.Map<BSet<PACKET_START_ADDRESSES_IN_TC_POOL>, immutable.Map<_ProjectionRead_Skip_TC_Success_Report, _ProjectionWrite_Skip_TC_Success_Report>> = new immutable.Map();
    _OpCache_tr_Skip_TC_Success_Report: immutable.Map<_ProjectionRead__tr_Skip_TC_Success_Report, BSet<PACKET_START_ADDRESSES_IN_TC_POOL>> = new immutable.Map();

    _OpCache_Report_TC_Execution_Failure: immutable.Map<BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>, immutable.Map<_ProjectionRead_Report_TC_Execution_Failure, _ProjectionWrite_Report_TC_Execution_Failure>> = new immutable.Map();
    _OpCache_tr_Report_TC_Execution_Failure: immutable.Map<_ProjectionRead__tr_Report_TC_Execution_Failure, BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>> = new immutable.Map();

    _OpCache_Skip_TC_Failure_Report: immutable.Map<BSet<PACKET_START_ADDRESSES_IN_TC_POOL>, immutable.Map<_ProjectionRead_Skip_TC_Failure_Report, _ProjectionWrite_Skip_TC_Failure_Report>> = new immutable.Map();
    _OpCache_tr_Skip_TC_Failure_Report: immutable.Map<_ProjectionRead__tr_Skip_TC_Failure_Report, BSet<PACKET_START_ADDRESSES_IN_TC_POOL>> = new immutable.Map();

    _OpCache_Drop_TC: immutable.Map<BSet<PACKET_START_ADDRESSES_IN_TC_POOL>, immutable.Map<_ProjectionRead_Drop_TC, _ProjectionWrite_Drop_TC>> = new immutable.Map();
    _OpCache_tr_Drop_TC: immutable.Map<_ProjectionRead__tr_Drop_TC, BSet<PACKET_START_ADDRESSES_IN_TC_POOL>> = new immutable.Map();

    _OpCache_Produce_TM: immutable.Map<BSet<BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL>>, immutable.Map<_ProjectionRead_Produce_TM, _ProjectionWrite_Produce_TM>> = new immutable.Map();
    _OpCache_tr_Produce_TM: immutable.Map<_ProjectionRead__tr_Produce_TM, BSet<BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL>>> = new immutable.Map();

    _OpCache_Pass_TM: immutable.Map<BSet<BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER>>, immutable.Map<_ProjectionRead_Pass_TM, _ProjectionWrite_Pass_TM>> = new immutable.Map();
    _OpCache_tr_Pass_TM: immutable.Map<_ProjectionRead__tr_Pass_TM, BSet<BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER>>> = new immutable.Map();

    _OpCache_Cancel_TM: immutable.Map<BSet<PACKET_START_ADDRESSES_IN_TM_POOL>, immutable.Map<_ProjectionRead_Cancel_TM, _ProjectionWrite_Cancel_TM>> = new immutable.Map();
    _OpCache_tr_Cancel_TM: immutable.Map<_ProjectionRead__tr_Cancel_TM, BSet<PACKET_START_ADDRESSES_IN_TM_POOL>> = new immutable.Map();

    _OpCache_Drop_TM: immutable.Map<BSet<PACKET_START_ADDRESSES_IN_TM_POOL>, immutable.Map<_ProjectionRead_Drop_TM, _ProjectionWrite_Drop_TM>> = new immutable.Map();
    _OpCache_tr_Drop_TM: immutable.Map<_ProjectionRead__tr_Drop_TM, BSet<PACKET_START_ADDRESSES_IN_TM_POOL>> = new immutable.Map();

    _OpCache_env_Deliver_TM: immutable.Map<BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER>, immutable.Map<_ProjectionRead_env_Deliver_TM, _ProjectionWrite_env_Deliver_TM>> = new immutable.Map();
    _OpCache_tr_env_Deliver_TM: immutable.Map<_ProjectionRead__tr_env_Deliver_TM, BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER>> = new immutable.Map();

    _InvCache__check_inv_1: immutable.Map<_ProjectionRead__check_inv_1, boolean> = new immutable.Map();
    _InvCache__check_inv_2: immutable.Map<_ProjectionRead__check_inv_2, boolean> = new immutable.Map();
    _InvCache__check_inv_3: immutable.Map<_ProjectionRead__check_inv_3, boolean> = new immutable.Map();
    _InvCache__check_inv_4: immutable.Map<_ProjectionRead__check_inv_4, boolean> = new immutable.Map();
    _InvCache__check_inv_5: immutable.Map<_ProjectionRead__check_inv_5, boolean> = new immutable.Map();
    _InvCache__check_inv_6: immutable.Map<_ProjectionRead__check_inv_6, boolean> = new immutable.Map();
    _InvCache__check_inv_7: immutable.Map<_ProjectionRead__check_inv_7, boolean> = new immutable.Map();
    _InvCache__check_inv_8: immutable.Map<_ProjectionRead__check_inv_8, boolean> = new immutable.Map();
    _InvCache__check_inv_9: immutable.Map<_ProjectionRead__check_inv_9, boolean> = new immutable.Map();

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
        let machine: obsw_M001_1 = new obsw_M001_1();
        this.states = this.states.add(machine);
        this.unvisitedStates.pushBack(machine);

        while(!(this.unvisitedStates.length === 0)) {
            let state: obsw_M001_1 = this.next();

            let nextStates: Set<obsw_M001_1> = this.generateNextStates(state);

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

    next(): obsw_M001_1 {
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

    generateNextStates(state: obsw_M001_1): Set<obsw_M001_1> {
        let result: immutable.Set<obsw_M001_1> = immutable.Set();
        if(this.isCaching) {
            let read__tr_env_Receive_TC_state : _ProjectionRead__tr_env_Receive_TC = state._projected_state_for__tr_env_Receive_TC();
            let _trid_1 : BSet<BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER>>  = this._OpCache_tr_env_Receive_TC.get(read__tr_env_Receive_TC_state);
            if(_trid_1 == null) {
                _trid_1 = state._tr_env_Receive_TC();
                this._OpCache_tr_env_Receive_TC = this._OpCache_tr_env_Receive_TC.set(read__tr_env_Receive_TC_state, _trid_1);
            }

            for(let param of _trid_1) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_BUFFER = param.projection2();
                let _tmp_2: TC_SET = param.projection1();

                let copiedState: obsw_M001_1 = state._copy();
                let readState: _ProjectionRead_env_Receive_TC = state._projected_state_for_env_Receive_TC();
                let _OpCache_with_parameter_env_Receive_TC: immutable.Map = this._OpCache_env_Receive_TC.get(param);
                if(_OpCache_with_parameter_env_Receive_TC != null) {
                    let writeState: _ProjectionWrite_env_Receive_TC = _OpCache_with_parameter_env_Receive_TC.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_env_Receive_TC(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.env_Receive_TC(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_env_Receive_TC();
                        _OpCache_with_parameter_env_Receive_TC = _OpCache_with_parameter_env_Receive_TC.set(readState, writeState);
                        this._OpCache_env_Receive_TC = this._OpCache_env_Receive_TC.set(param, _OpCache_with_parameter_env_Receive_TC);
                    }

                } else {
                    copiedState.env_Receive_TC(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_env_Receive_TC = copiedState._update_for_env_Receive_TC();
                    _OpCache_with_parameter_env_Receive_TC = new immutable.Map().set(readState, writeState);
                    this._OpCache_env_Receive_TC = this._OpCache_env_Receive_TC.set(param, _OpCache_with_parameter_env_Receive_TC);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_Poll_TC_state : _ProjectionRead__tr_Poll_TC = state._projected_state_for__tr_Poll_TC();
            let _trid_2 : BSet<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER>>  = this._OpCache_tr_Poll_TC.get(read__tr_Poll_TC_state);
            if(_trid_2 == null) {
                _trid_2 = state._tr_Poll_TC();
                this._OpCache_tr_Poll_TC = this._OpCache_tr_Poll_TC.set(read__tr_Poll_TC_state, _trid_2);
            }

            for(let param of _trid_2) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_BUFFER = param.projection2();
                let _tmp_2: PACKET_START_ADDRESSES_IN_TC_POOL = param.projection1();

                let copiedState: obsw_M001_1 = state._copy();
                let readState: _ProjectionRead_Poll_TC = state._projected_state_for_Poll_TC();
                let _OpCache_with_parameter_Poll_TC: immutable.Map = this._OpCache_Poll_TC.get(param);
                if(_OpCache_with_parameter_Poll_TC != null) {
                    let writeState: _ProjectionWrite_Poll_TC = _OpCache_with_parameter_Poll_TC.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_Poll_TC(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.Poll_TC(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_Poll_TC();
                        _OpCache_with_parameter_Poll_TC = _OpCache_with_parameter_Poll_TC.set(readState, writeState);
                        this._OpCache_Poll_TC = this._OpCache_Poll_TC.set(param, _OpCache_with_parameter_Poll_TC);
                    }

                } else {
                    copiedState.Poll_TC(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_Poll_TC = copiedState._update_for_Poll_TC();
                    _OpCache_with_parameter_Poll_TC = new immutable.Map().set(readState, writeState);
                    this._OpCache_Poll_TC = this._OpCache_Poll_TC.set(param, _OpCache_with_parameter_Poll_TC);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_Accept_TC_state : _ProjectionRead__tr_Accept_TC = state._projected_state_for__tr_Accept_TC();
            let _trid_3 : BSet<PACKET_START_ADDRESSES_IN_TC_POOL>  = this._OpCache_tr_Accept_TC.get(read__tr_Accept_TC_state);
            if(_trid_3 == null) {
                _trid_3 = state._tr_Accept_TC();
                this._OpCache_tr_Accept_TC = this._OpCache_tr_Accept_TC.set(read__tr_Accept_TC_state, _trid_3);
            }

            for(let param of _trid_3) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                let readState: _ProjectionRead_Accept_TC = state._projected_state_for_Accept_TC();
                let _OpCache_with_parameter_Accept_TC: immutable.Map = this._OpCache_Accept_TC.get(param);
                if(_OpCache_with_parameter_Accept_TC != null) {
                    let writeState: _ProjectionWrite_Accept_TC = _OpCache_with_parameter_Accept_TC.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_Accept_TC(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.Accept_TC(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_Accept_TC();
                        _OpCache_with_parameter_Accept_TC = _OpCache_with_parameter_Accept_TC.set(readState, writeState);
                        this._OpCache_Accept_TC = this._OpCache_Accept_TC.set(param, _OpCache_with_parameter_Accept_TC);
                    }

                } else {
                    copiedState.Accept_TC(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_Accept_TC = copiedState._update_for_Accept_TC();
                    _OpCache_with_parameter_Accept_TC = new immutable.Map().set(readState, writeState);
                    this._OpCache_Accept_TC = this._OpCache_Accept_TC.set(param, _OpCache_with_parameter_Accept_TC);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_Reject_TC_state : _ProjectionRead__tr_Reject_TC = state._projected_state_for__tr_Reject_TC();
            let _trid_4 : BSet<PACKET_START_ADDRESSES_IN_TC_POOL>  = this._OpCache_tr_Reject_TC.get(read__tr_Reject_TC_state);
            if(_trid_4 == null) {
                _trid_4 = state._tr_Reject_TC();
                this._OpCache_tr_Reject_TC = this._OpCache_tr_Reject_TC.set(read__tr_Reject_TC_state, _trid_4);
            }

            for(let param of _trid_4) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                let readState: _ProjectionRead_Reject_TC = state._projected_state_for_Reject_TC();
                let _OpCache_with_parameter_Reject_TC: immutable.Map = this._OpCache_Reject_TC.get(param);
                if(_OpCache_with_parameter_Reject_TC != null) {
                    let writeState: _ProjectionWrite_Reject_TC = _OpCache_with_parameter_Reject_TC.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_Reject_TC(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.Reject_TC(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_Reject_TC();
                        _OpCache_with_parameter_Reject_TC = _OpCache_with_parameter_Reject_TC.set(readState, writeState);
                        this._OpCache_Reject_TC = this._OpCache_Reject_TC.set(param, _OpCache_with_parameter_Reject_TC);
                    }

                } else {
                    copiedState.Reject_TC(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_Reject_TC = copiedState._update_for_Reject_TC();
                    _OpCache_with_parameter_Reject_TC = new immutable.Map().set(readState, writeState);
                    this._OpCache_Reject_TC = this._OpCache_Reject_TC.set(param, _OpCache_with_parameter_Reject_TC);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_Report_TC_Acceptance_state : _ProjectionRead__tr_Report_TC_Acceptance = state._projected_state_for__tr_Report_TC_Acceptance();
            let _trid_5 : BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>  = this._OpCache_tr_Report_TC_Acceptance.get(read__tr_Report_TC_Acceptance_state);
            if(_trid_5 == null) {
                _trid_5 = state._tr_Report_TC_Acceptance();
                this._OpCache_tr_Report_TC_Acceptance = this._OpCache_tr_Report_TC_Acceptance.set(read__tr_Report_TC_Acceptance_state, _trid_5);
            }

            for(let param of _trid_5) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TM_POOL = param.projection2();
                let _tmp_2: BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET> = param.projection1();
                let _tmp_3: TM_SET = _tmp_2.projection2();
                let _tmp_4: PACKET_START_ADDRESSES_IN_TC_POOL = _tmp_2.projection1();

                let copiedState: obsw_M001_1 = state._copy();
                let readState: _ProjectionRead_Report_TC_Acceptance = state._projected_state_for_Report_TC_Acceptance();
                let _OpCache_with_parameter_Report_TC_Acceptance: immutable.Map = this._OpCache_Report_TC_Acceptance.get(param);
                if(_OpCache_with_parameter_Report_TC_Acceptance != null) {
                    let writeState: _ProjectionWrite_Report_TC_Acceptance = _OpCache_with_parameter_Report_TC_Acceptance.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_Report_TC_Acceptance(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.Report_TC_Acceptance(_tmp_4, _tmp_3, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_Report_TC_Acceptance();
                        _OpCache_with_parameter_Report_TC_Acceptance = _OpCache_with_parameter_Report_TC_Acceptance.set(readState, writeState);
                        this._OpCache_Report_TC_Acceptance = this._OpCache_Report_TC_Acceptance.set(param, _OpCache_with_parameter_Report_TC_Acceptance);
                    }

                } else {
                    copiedState.Report_TC_Acceptance(_tmp_4, _tmp_3, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_Report_TC_Acceptance = copiedState._update_for_Report_TC_Acceptance();
                    _OpCache_with_parameter_Report_TC_Acceptance = new immutable.Map().set(readState, writeState);
                    this._OpCache_Report_TC_Acceptance = this._OpCache_Report_TC_Acceptance.set(param, _OpCache_with_parameter_Report_TC_Acceptance);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_Skip_TC_Acceptance_Report_state : _ProjectionRead__tr_Skip_TC_Acceptance_Report = state._projected_state_for__tr_Skip_TC_Acceptance_Report();
            let _trid_6 : BSet<PACKET_START_ADDRESSES_IN_TC_POOL>  = this._OpCache_tr_Skip_TC_Acceptance_Report.get(read__tr_Skip_TC_Acceptance_Report_state);
            if(_trid_6 == null) {
                _trid_6 = state._tr_Skip_TC_Acceptance_Report();
                this._OpCache_tr_Skip_TC_Acceptance_Report = this._OpCache_tr_Skip_TC_Acceptance_Report.set(read__tr_Skip_TC_Acceptance_Report_state, _trid_6);
            }

            for(let param of _trid_6) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                let readState: _ProjectionRead_Skip_TC_Acceptance_Report = state._projected_state_for_Skip_TC_Acceptance_Report();
                let _OpCache_with_parameter_Skip_TC_Acceptance_Report: immutable.Map = this._OpCache_Skip_TC_Acceptance_Report.get(param);
                if(_OpCache_with_parameter_Skip_TC_Acceptance_Report != null) {
                    let writeState: _ProjectionWrite_Skip_TC_Acceptance_Report = _OpCache_with_parameter_Skip_TC_Acceptance_Report.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_Skip_TC_Acceptance_Report(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.Skip_TC_Acceptance_Report(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_Skip_TC_Acceptance_Report();
                        _OpCache_with_parameter_Skip_TC_Acceptance_Report = _OpCache_with_parameter_Skip_TC_Acceptance_Report.set(readState, writeState);
                        this._OpCache_Skip_TC_Acceptance_Report = this._OpCache_Skip_TC_Acceptance_Report.set(param, _OpCache_with_parameter_Skip_TC_Acceptance_Report);
                    }

                } else {
                    copiedState.Skip_TC_Acceptance_Report(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_Skip_TC_Acceptance_Report = copiedState._update_for_Skip_TC_Acceptance_Report();
                    _OpCache_with_parameter_Skip_TC_Acceptance_Report = new immutable.Map().set(readState, writeState);
                    this._OpCache_Skip_TC_Acceptance_Report = this._OpCache_Skip_TC_Acceptance_Report.set(param, _OpCache_with_parameter_Skip_TC_Acceptance_Report);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_Report_TC_Rejection_state : _ProjectionRead__tr_Report_TC_Rejection = state._projected_state_for__tr_Report_TC_Rejection();
            let _trid_7 : BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>  = this._OpCache_tr_Report_TC_Rejection.get(read__tr_Report_TC_Rejection_state);
            if(_trid_7 == null) {
                _trid_7 = state._tr_Report_TC_Rejection();
                this._OpCache_tr_Report_TC_Rejection = this._OpCache_tr_Report_TC_Rejection.set(read__tr_Report_TC_Rejection_state, _trid_7);
            }

            for(let param of _trid_7) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TM_POOL = param.projection2();
                let _tmp_2: BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET> = param.projection1();
                let _tmp_3: TM_SET = _tmp_2.projection2();
                let _tmp_4: PACKET_START_ADDRESSES_IN_TC_POOL = _tmp_2.projection1();

                let copiedState: obsw_M001_1 = state._copy();
                let readState: _ProjectionRead_Report_TC_Rejection = state._projected_state_for_Report_TC_Rejection();
                let _OpCache_with_parameter_Report_TC_Rejection: immutable.Map = this._OpCache_Report_TC_Rejection.get(param);
                if(_OpCache_with_parameter_Report_TC_Rejection != null) {
                    let writeState: _ProjectionWrite_Report_TC_Rejection = _OpCache_with_parameter_Report_TC_Rejection.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_Report_TC_Rejection(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.Report_TC_Rejection(_tmp_4, _tmp_3, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_Report_TC_Rejection();
                        _OpCache_with_parameter_Report_TC_Rejection = _OpCache_with_parameter_Report_TC_Rejection.set(readState, writeState);
                        this._OpCache_Report_TC_Rejection = this._OpCache_Report_TC_Rejection.set(param, _OpCache_with_parameter_Report_TC_Rejection);
                    }

                } else {
                    copiedState.Report_TC_Rejection(_tmp_4, _tmp_3, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_Report_TC_Rejection = copiedState._update_for_Report_TC_Rejection();
                    _OpCache_with_parameter_Report_TC_Rejection = new immutable.Map().set(readState, writeState);
                    this._OpCache_Report_TC_Rejection = this._OpCache_Report_TC_Rejection.set(param, _OpCache_with_parameter_Report_TC_Rejection);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_Skip_TC_Rejection_Report_state : _ProjectionRead__tr_Skip_TC_Rejection_Report = state._projected_state_for__tr_Skip_TC_Rejection_Report();
            let _trid_8 : BSet<PACKET_START_ADDRESSES_IN_TC_POOL>  = this._OpCache_tr_Skip_TC_Rejection_Report.get(read__tr_Skip_TC_Rejection_Report_state);
            if(_trid_8 == null) {
                _trid_8 = state._tr_Skip_TC_Rejection_Report();
                this._OpCache_tr_Skip_TC_Rejection_Report = this._OpCache_tr_Skip_TC_Rejection_Report.set(read__tr_Skip_TC_Rejection_Report_state, _trid_8);
            }

            for(let param of _trid_8) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                let readState: _ProjectionRead_Skip_TC_Rejection_Report = state._projected_state_for_Skip_TC_Rejection_Report();
                let _OpCache_with_parameter_Skip_TC_Rejection_Report: immutable.Map = this._OpCache_Skip_TC_Rejection_Report.get(param);
                if(_OpCache_with_parameter_Skip_TC_Rejection_Report != null) {
                    let writeState: _ProjectionWrite_Skip_TC_Rejection_Report = _OpCache_with_parameter_Skip_TC_Rejection_Report.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_Skip_TC_Rejection_Report(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.Skip_TC_Rejection_Report(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_Skip_TC_Rejection_Report();
                        _OpCache_with_parameter_Skip_TC_Rejection_Report = _OpCache_with_parameter_Skip_TC_Rejection_Report.set(readState, writeState);
                        this._OpCache_Skip_TC_Rejection_Report = this._OpCache_Skip_TC_Rejection_Report.set(param, _OpCache_with_parameter_Skip_TC_Rejection_Report);
                    }

                } else {
                    copiedState.Skip_TC_Rejection_Report(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_Skip_TC_Rejection_Report = copiedState._update_for_Skip_TC_Rejection_Report();
                    _OpCache_with_parameter_Skip_TC_Rejection_Report = new immutable.Map().set(readState, writeState);
                    this._OpCache_Skip_TC_Rejection_Report = this._OpCache_Skip_TC_Rejection_Report.set(param, _OpCache_with_parameter_Skip_TC_Rejection_Report);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_Execute_TC_Successfully_state : _ProjectionRead__tr_Execute_TC_Successfully = state._projected_state_for__tr_Execute_TC_Successfully();
            let _trid_9 : BSet<PACKET_START_ADDRESSES_IN_TC_POOL>  = this._OpCache_tr_Execute_TC_Successfully.get(read__tr_Execute_TC_Successfully_state);
            if(_trid_9 == null) {
                _trid_9 = state._tr_Execute_TC_Successfully();
                this._OpCache_tr_Execute_TC_Successfully = this._OpCache_tr_Execute_TC_Successfully.set(read__tr_Execute_TC_Successfully_state, _trid_9);
            }

            for(let param of _trid_9) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                let readState: _ProjectionRead_Execute_TC_Successfully = state._projected_state_for_Execute_TC_Successfully();
                let _OpCache_with_parameter_Execute_TC_Successfully: immutable.Map = this._OpCache_Execute_TC_Successfully.get(param);
                if(_OpCache_with_parameter_Execute_TC_Successfully != null) {
                    let writeState: _ProjectionWrite_Execute_TC_Successfully = _OpCache_with_parameter_Execute_TC_Successfully.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_Execute_TC_Successfully(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.Execute_TC_Successfully(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_Execute_TC_Successfully();
                        _OpCache_with_parameter_Execute_TC_Successfully = _OpCache_with_parameter_Execute_TC_Successfully.set(readState, writeState);
                        this._OpCache_Execute_TC_Successfully = this._OpCache_Execute_TC_Successfully.set(param, _OpCache_with_parameter_Execute_TC_Successfully);
                    }

                } else {
                    copiedState.Execute_TC_Successfully(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_Execute_TC_Successfully = copiedState._update_for_Execute_TC_Successfully();
                    _OpCache_with_parameter_Execute_TC_Successfully = new immutable.Map().set(readState, writeState);
                    this._OpCache_Execute_TC_Successfully = this._OpCache_Execute_TC_Successfully.set(param, _OpCache_with_parameter_Execute_TC_Successfully);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_Reset_TM_Buffer_state : _ProjectionRead__tr_Reset_TM_Buffer = state._projected_state_for__tr_Reset_TM_Buffer();
            let _trid_10 : BSet<PACKET_START_ADDRESSES_IN_TC_POOL>  = this._OpCache_tr_Reset_TM_Buffer.get(read__tr_Reset_TM_Buffer_state);
            if(_trid_10 == null) {
                _trid_10 = state._tr_Reset_TM_Buffer();
                this._OpCache_tr_Reset_TM_Buffer = this._OpCache_tr_Reset_TM_Buffer.set(read__tr_Reset_TM_Buffer_state, _trid_10);
            }

            for(let param of _trid_10) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                let readState: _ProjectionRead_Reset_TM_Buffer = state._projected_state_for_Reset_TM_Buffer();
                let _OpCache_with_parameter_Reset_TM_Buffer: immutable.Map = this._OpCache_Reset_TM_Buffer.get(param);
                if(_OpCache_with_parameter_Reset_TM_Buffer != null) {
                    let writeState: _ProjectionWrite_Reset_TM_Buffer = _OpCache_with_parameter_Reset_TM_Buffer.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_Reset_TM_Buffer(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.Reset_TM_Buffer(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_Reset_TM_Buffer();
                        _OpCache_with_parameter_Reset_TM_Buffer = _OpCache_with_parameter_Reset_TM_Buffer.set(readState, writeState);
                        this._OpCache_Reset_TM_Buffer = this._OpCache_Reset_TM_Buffer.set(param, _OpCache_with_parameter_Reset_TM_Buffer);
                    }

                } else {
                    copiedState.Reset_TM_Buffer(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_Reset_TM_Buffer = copiedState._update_for_Reset_TM_Buffer();
                    _OpCache_with_parameter_Reset_TM_Buffer = new immutable.Map().set(readState, writeState);
                    this._OpCache_Reset_TM_Buffer = this._OpCache_Reset_TM_Buffer.set(param, _OpCache_with_parameter_Reset_TM_Buffer);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_Fail_TC_Execution_state : _ProjectionRead__tr_Fail_TC_Execution = state._projected_state_for__tr_Fail_TC_Execution();
            let _trid_11 : BSet<PACKET_START_ADDRESSES_IN_TC_POOL>  = this._OpCache_tr_Fail_TC_Execution.get(read__tr_Fail_TC_Execution_state);
            if(_trid_11 == null) {
                _trid_11 = state._tr_Fail_TC_Execution();
                this._OpCache_tr_Fail_TC_Execution = this._OpCache_tr_Fail_TC_Execution.set(read__tr_Fail_TC_Execution_state, _trid_11);
            }

            for(let param of _trid_11) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                let readState: _ProjectionRead_Fail_TC_Execution = state._projected_state_for_Fail_TC_Execution();
                let _OpCache_with_parameter_Fail_TC_Execution: immutable.Map = this._OpCache_Fail_TC_Execution.get(param);
                if(_OpCache_with_parameter_Fail_TC_Execution != null) {
                    let writeState: _ProjectionWrite_Fail_TC_Execution = _OpCache_with_parameter_Fail_TC_Execution.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_Fail_TC_Execution(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.Fail_TC_Execution(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_Fail_TC_Execution();
                        _OpCache_with_parameter_Fail_TC_Execution = _OpCache_with_parameter_Fail_TC_Execution.set(readState, writeState);
                        this._OpCache_Fail_TC_Execution = this._OpCache_Fail_TC_Execution.set(param, _OpCache_with_parameter_Fail_TC_Execution);
                    }

                } else {
                    copiedState.Fail_TC_Execution(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_Fail_TC_Execution = copiedState._update_for_Fail_TC_Execution();
                    _OpCache_with_parameter_Fail_TC_Execution = new immutable.Map().set(readState, writeState);
                    this._OpCache_Fail_TC_Execution = this._OpCache_Fail_TC_Execution.set(param, _OpCache_with_parameter_Fail_TC_Execution);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_Report_TC_Execution_Success_state : _ProjectionRead__tr_Report_TC_Execution_Success = state._projected_state_for__tr_Report_TC_Execution_Success();
            let _trid_12 : BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>  = this._OpCache_tr_Report_TC_Execution_Success.get(read__tr_Report_TC_Execution_Success_state);
            if(_trid_12 == null) {
                _trid_12 = state._tr_Report_TC_Execution_Success();
                this._OpCache_tr_Report_TC_Execution_Success = this._OpCache_tr_Report_TC_Execution_Success.set(read__tr_Report_TC_Execution_Success_state, _trid_12);
            }

            for(let param of _trid_12) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TM_POOL = param.projection2();
                let _tmp_2: BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET> = param.projection1();
                let _tmp_3: TM_SET = _tmp_2.projection2();
                let _tmp_4: PACKET_START_ADDRESSES_IN_TC_POOL = _tmp_2.projection1();

                let copiedState: obsw_M001_1 = state._copy();
                let readState: _ProjectionRead_Report_TC_Execution_Success = state._projected_state_for_Report_TC_Execution_Success();
                let _OpCache_with_parameter_Report_TC_Execution_Success: immutable.Map = this._OpCache_Report_TC_Execution_Success.get(param);
                if(_OpCache_with_parameter_Report_TC_Execution_Success != null) {
                    let writeState: _ProjectionWrite_Report_TC_Execution_Success = _OpCache_with_parameter_Report_TC_Execution_Success.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_Report_TC_Execution_Success(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.Report_TC_Execution_Success(_tmp_4, _tmp_3, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_Report_TC_Execution_Success();
                        _OpCache_with_parameter_Report_TC_Execution_Success = _OpCache_with_parameter_Report_TC_Execution_Success.set(readState, writeState);
                        this._OpCache_Report_TC_Execution_Success = this._OpCache_Report_TC_Execution_Success.set(param, _OpCache_with_parameter_Report_TC_Execution_Success);
                    }

                } else {
                    copiedState.Report_TC_Execution_Success(_tmp_4, _tmp_3, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_Report_TC_Execution_Success = copiedState._update_for_Report_TC_Execution_Success();
                    _OpCache_with_parameter_Report_TC_Execution_Success = new immutable.Map().set(readState, writeState);
                    this._OpCache_Report_TC_Execution_Success = this._OpCache_Report_TC_Execution_Success.set(param, _OpCache_with_parameter_Report_TC_Execution_Success);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_Skip_TC_Success_Report_state : _ProjectionRead__tr_Skip_TC_Success_Report = state._projected_state_for__tr_Skip_TC_Success_Report();
            let _trid_13 : BSet<PACKET_START_ADDRESSES_IN_TC_POOL>  = this._OpCache_tr_Skip_TC_Success_Report.get(read__tr_Skip_TC_Success_Report_state);
            if(_trid_13 == null) {
                _trid_13 = state._tr_Skip_TC_Success_Report();
                this._OpCache_tr_Skip_TC_Success_Report = this._OpCache_tr_Skip_TC_Success_Report.set(read__tr_Skip_TC_Success_Report_state, _trid_13);
            }

            for(let param of _trid_13) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                let readState: _ProjectionRead_Skip_TC_Success_Report = state._projected_state_for_Skip_TC_Success_Report();
                let _OpCache_with_parameter_Skip_TC_Success_Report: immutable.Map = this._OpCache_Skip_TC_Success_Report.get(param);
                if(_OpCache_with_parameter_Skip_TC_Success_Report != null) {
                    let writeState: _ProjectionWrite_Skip_TC_Success_Report = _OpCache_with_parameter_Skip_TC_Success_Report.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_Skip_TC_Success_Report(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.Skip_TC_Success_Report(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_Skip_TC_Success_Report();
                        _OpCache_with_parameter_Skip_TC_Success_Report = _OpCache_with_parameter_Skip_TC_Success_Report.set(readState, writeState);
                        this._OpCache_Skip_TC_Success_Report = this._OpCache_Skip_TC_Success_Report.set(param, _OpCache_with_parameter_Skip_TC_Success_Report);
                    }

                } else {
                    copiedState.Skip_TC_Success_Report(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_Skip_TC_Success_Report = copiedState._update_for_Skip_TC_Success_Report();
                    _OpCache_with_parameter_Skip_TC_Success_Report = new immutable.Map().set(readState, writeState);
                    this._OpCache_Skip_TC_Success_Report = this._OpCache_Skip_TC_Success_Report.set(param, _OpCache_with_parameter_Skip_TC_Success_Report);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_Report_TC_Execution_Failure_state : _ProjectionRead__tr_Report_TC_Execution_Failure = state._projected_state_for__tr_Report_TC_Execution_Failure();
            let _trid_14 : BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>>  = this._OpCache_tr_Report_TC_Execution_Failure.get(read__tr_Report_TC_Execution_Failure_state);
            if(_trid_14 == null) {
                _trid_14 = state._tr_Report_TC_Execution_Failure();
                this._OpCache_tr_Report_TC_Execution_Failure = this._OpCache_tr_Report_TC_Execution_Failure.set(read__tr_Report_TC_Execution_Failure_state, _trid_14);
            }

            for(let param of _trid_14) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TM_POOL = param.projection2();
                let _tmp_2: BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET> = param.projection1();
                let _tmp_3: TM_SET = _tmp_2.projection2();
                let _tmp_4: PACKET_START_ADDRESSES_IN_TC_POOL = _tmp_2.projection1();

                let copiedState: obsw_M001_1 = state._copy();
                let readState: _ProjectionRead_Report_TC_Execution_Failure = state._projected_state_for_Report_TC_Execution_Failure();
                let _OpCache_with_parameter_Report_TC_Execution_Failure: immutable.Map = this._OpCache_Report_TC_Execution_Failure.get(param);
                if(_OpCache_with_parameter_Report_TC_Execution_Failure != null) {
                    let writeState: _ProjectionWrite_Report_TC_Execution_Failure = _OpCache_with_parameter_Report_TC_Execution_Failure.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_Report_TC_Execution_Failure(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.Report_TC_Execution_Failure(_tmp_4, _tmp_3, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_Report_TC_Execution_Failure();
                        _OpCache_with_parameter_Report_TC_Execution_Failure = _OpCache_with_parameter_Report_TC_Execution_Failure.set(readState, writeState);
                        this._OpCache_Report_TC_Execution_Failure = this._OpCache_Report_TC_Execution_Failure.set(param, _OpCache_with_parameter_Report_TC_Execution_Failure);
                    }

                } else {
                    copiedState.Report_TC_Execution_Failure(_tmp_4, _tmp_3, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_Report_TC_Execution_Failure = copiedState._update_for_Report_TC_Execution_Failure();
                    _OpCache_with_parameter_Report_TC_Execution_Failure = new immutable.Map().set(readState, writeState);
                    this._OpCache_Report_TC_Execution_Failure = this._OpCache_Report_TC_Execution_Failure.set(param, _OpCache_with_parameter_Report_TC_Execution_Failure);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_Skip_TC_Failure_Report_state : _ProjectionRead__tr_Skip_TC_Failure_Report = state._projected_state_for__tr_Skip_TC_Failure_Report();
            let _trid_15 : BSet<PACKET_START_ADDRESSES_IN_TC_POOL>  = this._OpCache_tr_Skip_TC_Failure_Report.get(read__tr_Skip_TC_Failure_Report_state);
            if(_trid_15 == null) {
                _trid_15 = state._tr_Skip_TC_Failure_Report();
                this._OpCache_tr_Skip_TC_Failure_Report = this._OpCache_tr_Skip_TC_Failure_Report.set(read__tr_Skip_TC_Failure_Report_state, _trid_15);
            }

            for(let param of _trid_15) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                let readState: _ProjectionRead_Skip_TC_Failure_Report = state._projected_state_for_Skip_TC_Failure_Report();
                let _OpCache_with_parameter_Skip_TC_Failure_Report: immutable.Map = this._OpCache_Skip_TC_Failure_Report.get(param);
                if(_OpCache_with_parameter_Skip_TC_Failure_Report != null) {
                    let writeState: _ProjectionWrite_Skip_TC_Failure_Report = _OpCache_with_parameter_Skip_TC_Failure_Report.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_Skip_TC_Failure_Report(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.Skip_TC_Failure_Report(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_Skip_TC_Failure_Report();
                        _OpCache_with_parameter_Skip_TC_Failure_Report = _OpCache_with_parameter_Skip_TC_Failure_Report.set(readState, writeState);
                        this._OpCache_Skip_TC_Failure_Report = this._OpCache_Skip_TC_Failure_Report.set(param, _OpCache_with_parameter_Skip_TC_Failure_Report);
                    }

                } else {
                    copiedState.Skip_TC_Failure_Report(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_Skip_TC_Failure_Report = copiedState._update_for_Skip_TC_Failure_Report();
                    _OpCache_with_parameter_Skip_TC_Failure_Report = new immutable.Map().set(readState, writeState);
                    this._OpCache_Skip_TC_Failure_Report = this._OpCache_Skip_TC_Failure_Report.set(param, _OpCache_with_parameter_Skip_TC_Failure_Report);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_Drop_TC_state : _ProjectionRead__tr_Drop_TC = state._projected_state_for__tr_Drop_TC();
            let _trid_16 : BSet<PACKET_START_ADDRESSES_IN_TC_POOL>  = this._OpCache_tr_Drop_TC.get(read__tr_Drop_TC_state);
            if(_trid_16 == null) {
                _trid_16 = state._tr_Drop_TC();
                this._OpCache_tr_Drop_TC = this._OpCache_tr_Drop_TC.set(read__tr_Drop_TC_state, _trid_16);
            }

            for(let param of _trid_16) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                let readState: _ProjectionRead_Drop_TC = state._projected_state_for_Drop_TC();
                let _OpCache_with_parameter_Drop_TC: immutable.Map = this._OpCache_Drop_TC.get(param);
                if(_OpCache_with_parameter_Drop_TC != null) {
                    let writeState: _ProjectionWrite_Drop_TC = _OpCache_with_parameter_Drop_TC.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_Drop_TC(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.Drop_TC(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_Drop_TC();
                        _OpCache_with_parameter_Drop_TC = _OpCache_with_parameter_Drop_TC.set(readState, writeState);
                        this._OpCache_Drop_TC = this._OpCache_Drop_TC.set(param, _OpCache_with_parameter_Drop_TC);
                    }

                } else {
                    copiedState.Drop_TC(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_Drop_TC = copiedState._update_for_Drop_TC();
                    _OpCache_with_parameter_Drop_TC = new immutable.Map().set(readState, writeState);
                    this._OpCache_Drop_TC = this._OpCache_Drop_TC.set(param, _OpCache_with_parameter_Drop_TC);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_Produce_TM_state : _ProjectionRead__tr_Produce_TM = state._projected_state_for__tr_Produce_TM();
            let _trid_17 : BSet<BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL>>  = this._OpCache_tr_Produce_TM.get(read__tr_Produce_TM_state);
            if(_trid_17 == null) {
                _trid_17 = state._tr_Produce_TM();
                this._OpCache_tr_Produce_TM = this._OpCache_tr_Produce_TM.set(read__tr_Produce_TM_state, _trid_17);
            }

            for(let param of _trid_17) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TM_POOL = param.projection2();
                let _tmp_2: TM_SET = param.projection1();

                let copiedState: obsw_M001_1 = state._copy();
                let readState: _ProjectionRead_Produce_TM = state._projected_state_for_Produce_TM();
                let _OpCache_with_parameter_Produce_TM: immutable.Map = this._OpCache_Produce_TM.get(param);
                if(_OpCache_with_parameter_Produce_TM != null) {
                    let writeState: _ProjectionWrite_Produce_TM = _OpCache_with_parameter_Produce_TM.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_Produce_TM(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.Produce_TM(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_Produce_TM();
                        _OpCache_with_parameter_Produce_TM = _OpCache_with_parameter_Produce_TM.set(readState, writeState);
                        this._OpCache_Produce_TM = this._OpCache_Produce_TM.set(param, _OpCache_with_parameter_Produce_TM);
                    }

                } else {
                    copiedState.Produce_TM(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_Produce_TM = copiedState._update_for_Produce_TM();
                    _OpCache_with_parameter_Produce_TM = new immutable.Map().set(readState, writeState);
                    this._OpCache_Produce_TM = this._OpCache_Produce_TM.set(param, _OpCache_with_parameter_Produce_TM);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_Pass_TM_state : _ProjectionRead__tr_Pass_TM = state._projected_state_for__tr_Pass_TM();
            let _trid_18 : BSet<BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER>>  = this._OpCache_tr_Pass_TM.get(read__tr_Pass_TM_state);
            if(_trid_18 == null) {
                _trid_18 = state._tr_Pass_TM();
                this._OpCache_tr_Pass_TM = this._OpCache_tr_Pass_TM.set(read__tr_Pass_TM_state, _trid_18);
            }

            for(let param of _trid_18) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TM_BUFFER = param.projection2();
                let _tmp_2: PACKET_START_ADDRESSES_IN_TM_POOL = param.projection1();

                let copiedState: obsw_M001_1 = state._copy();
                let readState: _ProjectionRead_Pass_TM = state._projected_state_for_Pass_TM();
                let _OpCache_with_parameter_Pass_TM: immutable.Map = this._OpCache_Pass_TM.get(param);
                if(_OpCache_with_parameter_Pass_TM != null) {
                    let writeState: _ProjectionWrite_Pass_TM = _OpCache_with_parameter_Pass_TM.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_Pass_TM(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.Pass_TM(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_Pass_TM();
                        _OpCache_with_parameter_Pass_TM = _OpCache_with_parameter_Pass_TM.set(readState, writeState);
                        this._OpCache_Pass_TM = this._OpCache_Pass_TM.set(param, _OpCache_with_parameter_Pass_TM);
                    }

                } else {
                    copiedState.Pass_TM(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_Pass_TM = copiedState._update_for_Pass_TM();
                    _OpCache_with_parameter_Pass_TM = new immutable.Map().set(readState, writeState);
                    this._OpCache_Pass_TM = this._OpCache_Pass_TM.set(param, _OpCache_with_parameter_Pass_TM);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_Cancel_TM_state : _ProjectionRead__tr_Cancel_TM = state._projected_state_for__tr_Cancel_TM();
            let _trid_19 : BSet<PACKET_START_ADDRESSES_IN_TM_POOL>  = this._OpCache_tr_Cancel_TM.get(read__tr_Cancel_TM_state);
            if(_trid_19 == null) {
                _trid_19 = state._tr_Cancel_TM();
                this._OpCache_tr_Cancel_TM = this._OpCache_tr_Cancel_TM.set(read__tr_Cancel_TM_state, _trid_19);
            }

            for(let param of _trid_19) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TM_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                let readState: _ProjectionRead_Cancel_TM = state._projected_state_for_Cancel_TM();
                let _OpCache_with_parameter_Cancel_TM: immutable.Map = this._OpCache_Cancel_TM.get(param);
                if(_OpCache_with_parameter_Cancel_TM != null) {
                    let writeState: _ProjectionWrite_Cancel_TM = _OpCache_with_parameter_Cancel_TM.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_Cancel_TM(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.Cancel_TM(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_Cancel_TM();
                        _OpCache_with_parameter_Cancel_TM = _OpCache_with_parameter_Cancel_TM.set(readState, writeState);
                        this._OpCache_Cancel_TM = this._OpCache_Cancel_TM.set(param, _OpCache_with_parameter_Cancel_TM);
                    }

                } else {
                    copiedState.Cancel_TM(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_Cancel_TM = copiedState._update_for_Cancel_TM();
                    _OpCache_with_parameter_Cancel_TM = new immutable.Map().set(readState, writeState);
                    this._OpCache_Cancel_TM = this._OpCache_Cancel_TM.set(param, _OpCache_with_parameter_Cancel_TM);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_Drop_TM_state : _ProjectionRead__tr_Drop_TM = state._projected_state_for__tr_Drop_TM();
            let _trid_20 : BSet<PACKET_START_ADDRESSES_IN_TM_POOL>  = this._OpCache_tr_Drop_TM.get(read__tr_Drop_TM_state);
            if(_trid_20 == null) {
                _trid_20 = state._tr_Drop_TM();
                this._OpCache_tr_Drop_TM = this._OpCache_tr_Drop_TM.set(read__tr_Drop_TM_state, _trid_20);
            }

            for(let param of _trid_20) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TM_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                let readState: _ProjectionRead_Drop_TM = state._projected_state_for_Drop_TM();
                let _OpCache_with_parameter_Drop_TM: immutable.Map = this._OpCache_Drop_TM.get(param);
                if(_OpCache_with_parameter_Drop_TM != null) {
                    let writeState: _ProjectionWrite_Drop_TM = _OpCache_with_parameter_Drop_TM.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_Drop_TM(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.Drop_TM(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_Drop_TM();
                        _OpCache_with_parameter_Drop_TM = _OpCache_with_parameter_Drop_TM.set(readState, writeState);
                        this._OpCache_Drop_TM = this._OpCache_Drop_TM.set(param, _OpCache_with_parameter_Drop_TM);
                    }

                } else {
                    copiedState.Drop_TM(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_Drop_TM = copiedState._update_for_Drop_TM();
                    _OpCache_with_parameter_Drop_TM = new immutable.Map().set(readState, writeState);
                    this._OpCache_Drop_TM = this._OpCache_Drop_TM.set(param, _OpCache_with_parameter_Drop_TM);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_env_Deliver_TM_state : _ProjectionRead__tr_env_Deliver_TM = state._projected_state_for__tr_env_Deliver_TM();
            let _trid_21 : BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER>  = this._OpCache_tr_env_Deliver_TM.get(read__tr_env_Deliver_TM_state);
            if(_trid_21 == null) {
                _trid_21 = state._tr_env_Deliver_TM();
                this._OpCache_tr_env_Deliver_TM = this._OpCache_tr_env_Deliver_TM.set(read__tr_env_Deliver_TM_state, _trid_21);
            }

            for(let param of _trid_21) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TM_BUFFER = param;

                let copiedState: obsw_M001_1 = state._copy();
                let readState: _ProjectionRead_env_Deliver_TM = state._projected_state_for_env_Deliver_TM();
                let _OpCache_with_parameter_env_Deliver_TM: immutable.Map = this._OpCache_env_Deliver_TM.get(param);
                if(_OpCache_with_parameter_env_Deliver_TM != null) {
                    let writeState: _ProjectionWrite_env_Deliver_TM = _OpCache_with_parameter_env_Deliver_TM.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_env_Deliver_TM(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.env_Deliver_TM(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_env_Deliver_TM();
                        _OpCache_with_parameter_env_Deliver_TM = _OpCache_with_parameter_env_Deliver_TM.set(readState, writeState);
                        this._OpCache_env_Deliver_TM = this._OpCache_env_Deliver_TM.set(param, _OpCache_with_parameter_env_Deliver_TM);
                    }

                } else {
                    copiedState.env_Deliver_TM(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_env_Deliver_TM = copiedState._update_for_env_Deliver_TM();
                    _OpCache_with_parameter_env_Deliver_TM = new immutable.Map().set(readState, writeState);
                    this._OpCache_env_Deliver_TM = this._OpCache_env_Deliver_TM.set(param, _OpCache_with_parameter_env_Deliver_TM);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        } else {
            let _trid_1: BSet<BTuple<TC_SET, PACKET_START_ADDRESSES_IN_TC_BUFFER>> = state._tr_env_Receive_TC();
            for(let param of _trid_1) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_BUFFER = param.projection2();
                let _tmp_2: TC_SET = param.projection1();

                let copiedState: obsw_M001_1 = state._copy();
                copiedState.env_Receive_TC(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_2: BSet<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, PACKET_START_ADDRESSES_IN_TC_BUFFER>> = state._tr_Poll_TC();
            for(let param of _trid_2) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_BUFFER = param.projection2();
                let _tmp_2: PACKET_START_ADDRESSES_IN_TC_POOL = param.projection1();

                let copiedState: obsw_M001_1 = state._copy();
                copiedState.Poll_TC(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_3: BSet<PACKET_START_ADDRESSES_IN_TC_POOL> = state._tr_Accept_TC();
            for(let param of _trid_3) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                copiedState.Accept_TC(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_4: BSet<PACKET_START_ADDRESSES_IN_TC_POOL> = state._tr_Reject_TC();
            for(let param of _trid_4) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                copiedState.Reject_TC(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_5: BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> = state._tr_Report_TC_Acceptance();
            for(let param of _trid_5) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TM_POOL = param.projection2();
                let _tmp_2: BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET> = param.projection1();
                let _tmp_3: TM_SET = _tmp_2.projection2();
                let _tmp_4: PACKET_START_ADDRESSES_IN_TC_POOL = _tmp_2.projection1();

                let copiedState: obsw_M001_1 = state._copy();
                copiedState.Report_TC_Acceptance(_tmp_4, _tmp_3, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_6: BSet<PACKET_START_ADDRESSES_IN_TC_POOL> = state._tr_Skip_TC_Acceptance_Report();
            for(let param of _trid_6) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                copiedState.Skip_TC_Acceptance_Report(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_7: BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> = state._tr_Report_TC_Rejection();
            for(let param of _trid_7) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TM_POOL = param.projection2();
                let _tmp_2: BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET> = param.projection1();
                let _tmp_3: TM_SET = _tmp_2.projection2();
                let _tmp_4: PACKET_START_ADDRESSES_IN_TC_POOL = _tmp_2.projection1();

                let copiedState: obsw_M001_1 = state._copy();
                copiedState.Report_TC_Rejection(_tmp_4, _tmp_3, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_8: BSet<PACKET_START_ADDRESSES_IN_TC_POOL> = state._tr_Skip_TC_Rejection_Report();
            for(let param of _trid_8) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                copiedState.Skip_TC_Rejection_Report(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_9: BSet<PACKET_START_ADDRESSES_IN_TC_POOL> = state._tr_Execute_TC_Successfully();
            for(let param of _trid_9) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                copiedState.Execute_TC_Successfully(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_10: BSet<PACKET_START_ADDRESSES_IN_TC_POOL> = state._tr_Reset_TM_Buffer();
            for(let param of _trid_10) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                copiedState.Reset_TM_Buffer(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_11: BSet<PACKET_START_ADDRESSES_IN_TC_POOL> = state._tr_Fail_TC_Execution();
            for(let param of _trid_11) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                copiedState.Fail_TC_Execution(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_12: BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> = state._tr_Report_TC_Execution_Success();
            for(let param of _trid_12) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TM_POOL = param.projection2();
                let _tmp_2: BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET> = param.projection1();
                let _tmp_3: TM_SET = _tmp_2.projection2();
                let _tmp_4: PACKET_START_ADDRESSES_IN_TC_POOL = _tmp_2.projection1();

                let copiedState: obsw_M001_1 = state._copy();
                copiedState.Report_TC_Execution_Success(_tmp_4, _tmp_3, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_13: BSet<PACKET_START_ADDRESSES_IN_TC_POOL> = state._tr_Skip_TC_Success_Report();
            for(let param of _trid_13) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                copiedState.Skip_TC_Success_Report(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_14: BSet<BTuple<BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET>, PACKET_START_ADDRESSES_IN_TM_POOL>> = state._tr_Report_TC_Execution_Failure();
            for(let param of _trid_14) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TM_POOL = param.projection2();
                let _tmp_2: BTuple<PACKET_START_ADDRESSES_IN_TC_POOL, TM_SET> = param.projection1();
                let _tmp_3: TM_SET = _tmp_2.projection2();
                let _tmp_4: PACKET_START_ADDRESSES_IN_TC_POOL = _tmp_2.projection1();

                let copiedState: obsw_M001_1 = state._copy();
                copiedState.Report_TC_Execution_Failure(_tmp_4, _tmp_3, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_15: BSet<PACKET_START_ADDRESSES_IN_TC_POOL> = state._tr_Skip_TC_Failure_Report();
            for(let param of _trid_15) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                copiedState.Skip_TC_Failure_Report(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_16: BSet<PACKET_START_ADDRESSES_IN_TC_POOL> = state._tr_Drop_TC();
            for(let param of _trid_16) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TC_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                copiedState.Drop_TC(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_17: BSet<BTuple<TM_SET, PACKET_START_ADDRESSES_IN_TM_POOL>> = state._tr_Produce_TM();
            for(let param of _trid_17) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TM_POOL = param.projection2();
                let _tmp_2: TM_SET = param.projection1();

                let copiedState: obsw_M001_1 = state._copy();
                copiedState.Produce_TM(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_18: BSet<BTuple<PACKET_START_ADDRESSES_IN_TM_POOL, PACKET_START_ADDRESSES_IN_TM_BUFFER>> = state._tr_Pass_TM();
            for(let param of _trid_18) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TM_BUFFER = param.projection2();
                let _tmp_2: PACKET_START_ADDRESSES_IN_TM_POOL = param.projection1();

                let copiedState: obsw_M001_1 = state._copy();
                copiedState.Pass_TM(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_19: BSet<PACKET_START_ADDRESSES_IN_TM_POOL> = state._tr_Cancel_TM();
            for(let param of _trid_19) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TM_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                copiedState.Cancel_TM(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_20: BSet<PACKET_START_ADDRESSES_IN_TM_POOL> = state._tr_Drop_TM();
            for(let param of _trid_20) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TM_POOL = param;

                let copiedState: obsw_M001_1 = state._copy();
                copiedState.Drop_TM(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_21: BSet<PACKET_START_ADDRESSES_IN_TM_BUFFER> = state._tr_env_Deliver_TM();
            for(let param of _trid_21) {
                let _tmp_1: PACKET_START_ADDRESSES_IN_TM_BUFFER = param;

                let copiedState: obsw_M001_1 = state._copy();
                copiedState.env_Deliver_TM(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        }
        return result;
    }

    invViolated(state: obsw_M001_1): boolean {
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

