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

export enum enum_Nodes {
    node1,
    node2,
    node3,
    node4,
    node5
}

export class Nodes implements BObject{
    value: enum_Nodes;

    constructor(value: enum_Nodes) {
        this.value = value;
    }

    equal(other: Nodes) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: Nodes) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof Nodes)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_Nodes[this.value].toString();
    }

    static get_node1 () {return new Nodes(enum_Nodes.node1);}
    static get_node2 () {return new Nodes(enum_Nodes.node2);}
    static get_node3 () {return new Nodes(enum_Nodes.node3);}
    static get_node4 () {return new Nodes(enum_Nodes.node4);}
    static get_node5 () {return new Nodes(enum_Nodes.node5);}


}

export enum enum_Slots {
    slot1,
    slot2,
    slot3,
    slot4
}

export class Slots implements BObject{
    value: enum_Slots;

    constructor(value: enum_Slots) {
        this.value = value;
    }

    equal(other: Slots) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: Slots) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof Slots)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_Slots[this.value].toString();
    }

    static get_slot1 () {return new Slots(enum_Slots.slot1);}
    static get_slot2 () {return new Slots(enum_Slots.slot2);}
    static get_slot3 () {return new Slots(enum_Slots.slot3);}
    static get_slot4 () {return new Slots(enum_Slots.slot4);}


}


class _ProjectionRead_elapse_time {

    public time: Slots;

    constructor(time : Slots) {
        this.time = time;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_elapse_time = this;
        let o2: _ProjectionRead_elapse_time = other as _ProjectionRead_elapse_time;
        return o1.time.equals(o2.time);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.time.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_elapse_time {

    public time: Slots;

    constructor(time : Slots) {
        this.time = time;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_elapse_time = this;
        let o2: _ProjectionRead__tr_elapse_time = other as _ProjectionRead__tr_elapse_time;
        return o1.time.equals(o2.time);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.time.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_elapse_time {

    public time: Slots;

    constructor(time : Slots) {
        this.time = time;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_elapse_time = this;
        let o2: _ProjectionWrite_elapse_time = other as _ProjectionWrite_elapse_time;
        return o1.time.equals(o2.time);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.time.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_reserve {

    public grants: BRelation<Nodes, Slots>;
    public open_reservations: BRelation<Nodes, Slots>;

    constructor(grants : BRelation<Nodes, Slots>, open_reservations : BRelation<Nodes, Slots>) {
        this.grants = grants;
        this.open_reservations = open_reservations;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_reserve = this;
        let o2: _ProjectionRead_reserve = other as _ProjectionRead_reserve;
        return o1.grants.equals(o2.grants) && o1.open_reservations.equals(o2.open_reservations);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.grants.hashCode() << 1);
        result = 31 * result + (this.open_reservations.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_reserve {

    public grants: BRelation<Nodes, Slots>;
    public open_reservations: BRelation<Nodes, Slots>;

    constructor(grants : BRelation<Nodes, Slots>, open_reservations : BRelation<Nodes, Slots>) {
        this.grants = grants;
        this.open_reservations = open_reservations;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_reserve = this;
        let o2: _ProjectionRead__tr_reserve = other as _ProjectionRead__tr_reserve;
        return o1.grants.equals(o2.grants) && o1.open_reservations.equals(o2.open_reservations);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.grants.hashCode() << 1);
        result = 31 * result + (this.open_reservations.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_reserve {

    public open_reservations: BRelation<Nodes, Slots>;

    constructor(open_reservations : BRelation<Nodes, Slots>) {
        this.open_reservations = open_reservations;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_reserve = this;
        let o2: _ProjectionWrite_reserve = other as _ProjectionWrite_reserve;
        return o1.open_reservations.equals(o2.open_reservations);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.open_reservations.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_release {

    public grants: BRelation<Nodes, Slots>;
    public RT_count: BInteger;

    constructor(grants : BRelation<Nodes, Slots>, RT_count : BInteger) {
        this.grants = grants;
        this.RT_count = RT_count;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_release = this;
        let o2: _ProjectionRead_release = other as _ProjectionRead_release;
        return o1.grants.equals(o2.grants) && o1.RT_count.equals(o2.RT_count);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.grants.hashCode() << 1);
        result = 31 * result + (this.RT_count.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_release {

    public grants: BRelation<Nodes, Slots>;

    constructor(grants : BRelation<Nodes, Slots>) {
        this.grants = grants;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_release = this;
        let o2: _ProjectionRead__tr_release = other as _ProjectionRead__tr_release;
        return o1.grants.equals(o2.grants);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.grants.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_release {

    public grants: BRelation<Nodes, Slots>;
    public RT_count: BInteger;

    constructor(grants : BRelation<Nodes, Slots>, RT_count : BInteger) {
        this.grants = grants;
        this.RT_count = RT_count;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_release = this;
        let o2: _ProjectionWrite_release = other as _ProjectionWrite_release;
        return o1.grants.equals(o2.grants) && o1.RT_count.equals(o2.RT_count);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.grants.hashCode() << 1);
        result = 31 * result + (this.RT_count.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_grant {

    public grants: BRelation<Nodes, Slots>;
    public open_reservations: BRelation<Nodes, Slots>;
    public RT_count: BInteger;

    constructor(grants : BRelation<Nodes, Slots>, open_reservations : BRelation<Nodes, Slots>, RT_count : BInteger) {
        this.grants = grants;
        this.open_reservations = open_reservations;
        this.RT_count = RT_count;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_grant = this;
        let o2: _ProjectionRead_grant = other as _ProjectionRead_grant;
        return o1.grants.equals(o2.grants) && o1.open_reservations.equals(o2.open_reservations) && o1.RT_count.equals(o2.RT_count);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.grants.hashCode() << 1);
        result = 31 * result + (this.open_reservations.hashCode() << 1);
        result = 31 * result + (this.RT_count.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_grant {

    public open_reservations: BRelation<Nodes, Slots>;
    public RT_count: BInteger;

    constructor(open_reservations : BRelation<Nodes, Slots>, RT_count : BInteger) {
        this.open_reservations = open_reservations;
        this.RT_count = RT_count;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_grant = this;
        let o2: _ProjectionRead__tr_grant = other as _ProjectionRead__tr_grant;
        return o1.open_reservations.equals(o2.open_reservations) && o1.RT_count.equals(o2.RT_count);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.open_reservations.hashCode() << 1);
        result = 31 * result + (this.RT_count.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_grant {

    public grants: BRelation<Nodes, Slots>;
    public open_reservations: BRelation<Nodes, Slots>;
    public RT_count: BInteger;

    constructor(grants : BRelation<Nodes, Slots>, open_reservations : BRelation<Nodes, Slots>, RT_count : BInteger) {
        this.grants = grants;
        this.open_reservations = open_reservations;
        this.RT_count = RT_count;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_grant = this;
        let o2: _ProjectionWrite_grant = other as _ProjectionWrite_grant;
        return o1.grants.equals(o2.grants) && o1.open_reservations.equals(o2.open_reservations) && o1.RT_count.equals(o2.RT_count);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.grants.hashCode() << 1);
        result = 31 * result + (this.open_reservations.hashCode() << 1);
        result = 31 * result + (this.RT_count.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_no_grant {

    public open_reservations: BRelation<Nodes, Slots>;

    constructor(open_reservations : BRelation<Nodes, Slots>) {
        this.open_reservations = open_reservations;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_no_grant = this;
        let o2: _ProjectionRead_no_grant = other as _ProjectionRead_no_grant;
        return o1.open_reservations.equals(o2.open_reservations);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.open_reservations.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_no_grant {

    public open_reservations: BRelation<Nodes, Slots>;

    constructor(open_reservations : BRelation<Nodes, Slots>) {
        this.open_reservations = open_reservations;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_no_grant = this;
        let o2: _ProjectionRead__tr_no_grant = other as _ProjectionRead__tr_no_grant;
        return o1.open_reservations.equals(o2.open_reservations);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.open_reservations.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_no_grant {

    public open_reservations: BRelation<Nodes, Slots>;

    constructor(open_reservations : BRelation<Nodes, Slots>) {
        this.open_reservations = open_reservations;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_no_grant = this;
        let o2: _ProjectionWrite_no_grant = other as _ProjectionWrite_no_grant;
        return o1.open_reservations.equals(o2.open_reservations);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.open_reservations.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_use_RT_Slot {

    public grants: BRelation<Nodes, Slots>;
    public time: Slots;
    public token: Nodes;

    constructor(grants : BRelation<Nodes, Slots>, time : Slots, token : Nodes) {
        this.grants = grants;
        this.time = time;
        this.token = token;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_use_RT_Slot = this;
        let o2: _ProjectionRead_use_RT_Slot = other as _ProjectionRead_use_RT_Slot;
        return o1.grants.equals(o2.grants) && o1.time.equals(o2.time) && o1.token.equals(o2.token);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.grants.hashCode() << 1);
        result = 31 * result + (this.time.hashCode() << 1);
        result = 31 * result + (this.token.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_use_RT_Slot {

    public grants: BRelation<Nodes, Slots>;
    public time: Slots;
    public token: Nodes;

    constructor(grants : BRelation<Nodes, Slots>, time : Slots, token : Nodes) {
        this.grants = grants;
        this.time = time;
        this.token = token;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_use_RT_Slot = this;
        let o2: _ProjectionRead__tr_use_RT_Slot = other as _ProjectionRead__tr_use_RT_Slot;
        return o1.grants.equals(o2.grants) && o1.time.equals(o2.time) && o1.token.equals(o2.token);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.grants.hashCode() << 1);
        result = 31 * result + (this.time.hashCode() << 1);
        result = 31 * result + (this.token.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_use_RT_Slot {


    constructor() {
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_use_RT_Slot = this;
        let o2: _ProjectionWrite_use_RT_Slot = other as _ProjectionWrite_use_RT_Slot;
        return true;
    }

    hashCode(): number {
        let result: number = 1;
        return result;
    }
}


class _ProjectionRead_use_NRT_Slot {

    public grants: BRelation<Nodes, Slots>;
    public time: Slots;
    public token: Nodes;

    constructor(grants : BRelation<Nodes, Slots>, time : Slots, token : Nodes) {
        this.grants = grants;
        this.time = time;
        this.token = token;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_use_NRT_Slot = this;
        let o2: _ProjectionRead_use_NRT_Slot = other as _ProjectionRead_use_NRT_Slot;
        return o1.grants.equals(o2.grants) && o1.time.equals(o2.time) && o1.token.equals(o2.token);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.grants.hashCode() << 1);
        result = 31 * result + (this.time.hashCode() << 1);
        result = 31 * result + (this.token.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_use_NRT_Slot {

    public grants: BRelation<Nodes, Slots>;
    public time: Slots;
    public token: Nodes;

    constructor(grants : BRelation<Nodes, Slots>, time : Slots, token : Nodes) {
        this.grants = grants;
        this.time = time;
        this.token = token;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_use_NRT_Slot = this;
        let o2: _ProjectionRead__tr_use_NRT_Slot = other as _ProjectionRead__tr_use_NRT_Slot;
        return o1.grants.equals(o2.grants) && o1.time.equals(o2.time) && o1.token.equals(o2.token);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.grants.hashCode() << 1);
        result = 31 * result + (this.time.hashCode() << 1);
        result = 31 * result + (this.token.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_use_NRT_Slot {


    constructor() {
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_use_NRT_Slot = this;
        let o2: _ProjectionWrite_use_NRT_Slot = other as _ProjectionWrite_use_NRT_Slot;
        return true;
    }

    hashCode(): number {
        let result: number = 1;
        return result;
    }
}


class _ProjectionRead_pass_token {

    public token: Nodes;

    constructor(token : Nodes) {
        this.token = token;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_pass_token = this;
        let o2: _ProjectionRead_pass_token = other as _ProjectionRead_pass_token;
        return o1.token.equals(o2.token);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.token.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_pass_token {

    public token: Nodes;

    constructor(token : Nodes) {
        this.token = token;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_pass_token = this;
        let o2: _ProjectionRead__tr_pass_token = other as _ProjectionRead__tr_pass_token;
        return o1.token.equals(o2.token);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.token.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_pass_token {

    public token: Nodes;

    constructor(token : Nodes) {
        this.token = token;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_pass_token = this;
        let o2: _ProjectionWrite_pass_token = other as _ProjectionWrite_pass_token;
        return o1.token.equals(o2.token);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.token.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_1 {

    public time: Slots;

    constructor(time : Slots) {
        this.time = time;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_1 = this;
        let o2: _ProjectionRead__check_inv_1 = other as _ProjectionRead__check_inv_1;
        return o1.time.equals(o2.time);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.time.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_2 {

    public token: Nodes;

    constructor(token : Nodes) {
        this.token = token;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_2 = this;
        let o2: _ProjectionRead__check_inv_2 = other as _ProjectionRead__check_inv_2;
        return o1.token.equals(o2.token);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.token.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_3 {

    public open_reservations: BRelation<Nodes, Slots>;

    constructor(open_reservations : BRelation<Nodes, Slots>) {
        this.open_reservations = open_reservations;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_3 = this;
        let o2: _ProjectionRead__check_inv_3 = other as _ProjectionRead__check_inv_3;
        return o1.open_reservations.equals(o2.open_reservations);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.open_reservations.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_4 {

    public grants: BRelation<Nodes, Slots>;

    constructor(grants : BRelation<Nodes, Slots>) {
        this.grants = grants;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_4 = this;
        let o2: _ProjectionRead__check_inv_4 = other as _ProjectionRead__check_inv_4;
        return o1.grants.equals(o2.grants);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.grants.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_5 {

    public RT_count: BInteger;

    constructor(RT_count : BInteger) {
        this.RT_count = RT_count;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_5 = this;
        let o2: _ProjectionRead__check_inv_5 = other as _ProjectionRead__check_inv_5;
        return o1.RT_count.equals(o2.RT_count);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.RT_count.hashCode() << 1);
        return result;
    }
}


export default class rether {


    private static RT_Slots: BSet<Slots>;
    private static nextNodes: BRelation<Nodes, Nodes>;
    private static nextSlots: BRelation<Slots, Slots>;

    private static _Nodes: BSet<Nodes> = new BSet<Nodes>(new Nodes(enum_Nodes.node1), new Nodes(enum_Nodes.node2), new Nodes(enum_Nodes.node3), new Nodes(enum_Nodes.node4), new Nodes(enum_Nodes.node5));
    private static _Slots: BSet<Slots> = new BSet<Slots>(new Slots(enum_Slots.slot1), new Slots(enum_Slots.slot2), new Slots(enum_Slots.slot3), new Slots(enum_Slots.slot4));

    private RT_count: BInteger;
    private grants: BRelation<Nodes, Slots>;
    private open_reservations: BRelation<Nodes, Slots>;
    private time: Slots;
    private token: Nodes;

    static {
        rether.RT_Slots = new BSet<Slots>(new Slots(enum_Slots.slot1), new Slots(enum_Slots.slot2));
        rether.nextNodes = new BRelation<Nodes, Nodes>(new BTuple(new Nodes(enum_Nodes.node1), new Nodes(enum_Nodes.node2)), new BTuple(new Nodes(enum_Nodes.node2), new Nodes(enum_Nodes.node3)), new BTuple(new Nodes(enum_Nodes.node3), new Nodes(enum_Nodes.node4)), new BTuple(new Nodes(enum_Nodes.node4), new Nodes(enum_Nodes.node1)), new BTuple(new Nodes(enum_Nodes.node5), new Nodes(enum_Nodes.node1)));
        rether.nextSlots = new BRelation<Slots, Slots>(new BTuple(new Slots(enum_Slots.slot1), new Slots(enum_Slots.slot2)), new BTuple(new Slots(enum_Slots.slot2), new Slots(enum_Slots.slot3)), new BTuple(new Slots(enum_Slots.slot3), new Slots(enum_Slots.slot1)), new BTuple(new Slots(enum_Slots.slot4), new Slots(enum_Slots.slot1)));
        if(!(new BBoolean(new BBoolean(rether.nextSlots.checkDomain(rether._Slots).and(rether.nextSlots.checkRange(rether._Slots)).and(rether.nextSlots.isFunction()).and(rether.nextSlots.isTotal(rether._Slots)).booleanValue() && rether.RT_Slots.strictSubset(rether._Slots).booleanValue()).booleanValue() && rether.nextNodes.checkDomain(rether._Nodes).and(rether.nextNodes.checkRange(rether._Nodes)).and(rether.nextNodes.isFunction()).and(rether.nextNodes.isTotal(rether._Nodes)).booleanValue())).booleanValue()) {
            throw new Error("Contradiction in PROPERTIES detected!");
        }
    }

    constructor() {
        this.time = new Slots(enum_Slots.slot1);
        this.token = new Nodes(enum_Nodes.node1);
        this.open_reservations = new BRelation<Nodes, Slots>();
        this.grants = new BRelation<Nodes, Slots>();
        this.RT_count = rether.RT_Slots.card();
    }


    elapse_time(next: Slots, slot: Slots): void {
        this.time = next;

    }

    reserve(node: Nodes, slot: Slots): void {
        this.open_reservations = this.open_reservations.union(new BRelation<Nodes, Slots>(new BTuple(node, slot)));

    }

    release(node: Nodes, slot: Slots): void {
        let _ld_RT_count: BInteger = this.RT_count;
        let _ld_grants: BRelation<Nodes, Slots> = this.grants;
        this.grants = _ld_grants.difference(new BRelation<Nodes, Slots>(new BTuple(node, slot)));
        this.RT_count = _ld_RT_count.plus(new BInteger(1));

    }

    grant(node: Nodes, slot: Slots): void {
        let _ld_RT_count: BInteger = this.RT_count;
        let _ld_open_reservations: BRelation<Nodes, Slots> = this.open_reservations;
        let _ld_grants: BRelation<Nodes, Slots> = this.grants;
        this.open_reservations = _ld_open_reservations.difference(new BRelation<Nodes, Slots>(new BTuple(node, slot)));
        this.grants = _ld_grants.union(new BRelation<Nodes, Slots>(new BTuple(node, slot)));
        this.RT_count = _ld_RT_count.minus(new BInteger(1));

    }

    no_grant(node: Nodes, slot: Slots): void {
        this.open_reservations = this.open_reservations.difference(new BRelation<Nodes, Slots>(new BTuple(node, slot)));

    }

    use_RT_Slot(node: Nodes, slot: Slots): void {
    }

    use_NRT_Slot(node: Nodes, slot: Slots): void {
    }

    pass_token(node: Nodes): void {
        this.token = rether.nextNodes.functionCall(node);

    }

    _get_RT_Slots(): BSet<Slots> {
        return rether.RT_Slots;
    }

    _get_nextNodes(): BRelation<Nodes, Nodes> {
        return rether.nextNodes;
    }

    _get_nextSlots(): BRelation<Slots, Slots> {
        return rether.nextSlots;
    }

    _get_RT_count(): BInteger {
        return this.RT_count;
    }

    _get_grants(): BRelation<Nodes, Slots> {
        return this.grants;
    }

    _get_open_reservations(): BRelation<Nodes, Slots> {
        return this.open_reservations;
    }

    _get_time(): Slots {
        return this.time;
    }

    _get_token(): Nodes {
        return this.token;
    }

    _get__Nodes(): BSet<Nodes> {
        return rether._Nodes;
    }

    _get__Slots(): BSet<Slots> {
        return rether._Slots;
    }

    equals(o: any): boolean {
        let o1: rether = this;
        let o2: rether = o as rether;
        return o1._get_RT_count().equals(o2._get_RT_count()) && o1._get_grants().equals(o2._get_grants()) && o1._get_open_reservations().equals(o2._get_open_reservations()) && o1._get_time().equals(o2._get_time()) && o1._get_token().equals(o2._get_token());
    }



    hashCode(): number {
        return this._hashCode_1();
    }

    _hashCode_1(): number {
        let result: number = 1;
        result = (1543 * result) ^ ((this._get_RT_count()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_grants()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_open_reservations()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_time()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_token()).hashCode() << 1);
        return result;
    }

    _hashCode_2(): number {
        let result: number = 1;
        result = (6151 * result) ^ ((this._get_RT_count()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_grants()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_open_reservations()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_time()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_token()).hashCode() << 1);
        return result;
    }

    /* TODO
    toString(): string {
        return String.join("\n", "_get_RT_count: " + (this._get_RT_count()).toString(), "_get_grants: " + (this._get_grants()).toString(), "_get_open_reservations: " + (this._get_open_reservations()).toString(), "_get_time: " + (this._get_time()).toString(), "_get_token: " + (this._get_token()).toString());
    }
    */


}

