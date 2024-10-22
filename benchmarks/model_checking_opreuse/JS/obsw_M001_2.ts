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


export default class obsw_M001_2 {


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
        obsw_M001_2.VALID_TCS = new BSet<TC_SET>(new TC_SET(enum_TC_SET.TC_SET1));
        if(!(new BBoolean(obsw_M001_2._TC_SET.card().equal(new BInteger(2)).booleanValue() && obsw_M001_2._TC_SET.difference(obsw_M001_2.VALID_TCS).unequal(new BSet<TC_SET>()).booleanValue())).booleanValue()) {
            throw new Error("Contradiction in PROPERTIES detected!");
        }
    }

    constructor() {
        this.TCbuffer = new BRelation<PACKET_START_ADDRESSES_IN_TC_BUFFER, TC_SET>();
        this.TMbuffer = new BRelation<PACKET_START_ADDRESSES_IN_TM_BUFFER, TM_SET>();
        this.TCpool = new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_SET>();
        this.TMpool = new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_SET>();
        this.TCstatus = new BRelation<PACKET_START_ADDRESSES_IN_TC_POOL, TC_STATUSES>();
        this.TMstatus = new BRelation<PACKET_START_ADDRESSES_IN_TM_POOL, TM_STATUSES>();
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
        return obsw_M001_2.VALID_TCS;
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
        return obsw_M001_2._TC_SET;
    }

    _get__TC_STATUSES(): BSet<TC_STATUSES> {
        return obsw_M001_2._TC_STATUSES;
    }

    _get__TM_STATUSES(): BSet<TM_STATUSES> {
        return obsw_M001_2._TM_STATUSES;
    }

    equals(o: any): boolean {
        let o1: obsw_M001_2 = this;
        let o2: obsw_M001_2 = o as obsw_M001_2;
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


}

