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


export enum Type {
    BFS,
    DFS,
    MIXED
}

export default class rether {

    parent: rether;
    stateAccessedVia: string;


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

    constructor(copy? : rether) {
        if(copy) {
            this.RT_count = copy.RT_count;
            this.grants = copy.grants;
            this.open_reservations = copy.open_reservations;
            this.time = copy.time;
            this.token = copy.token;
        } else {
            this.time = new Slots(enum_Slots.slot1);
            this.token = new Nodes(enum_Nodes.node1);
            this.open_reservations = new BRelation<Nodes, Slots>();
            this.grants = new BRelation<Nodes, Slots>();
            this.RT_count = rether.RT_Slots.card();
        }
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

    _tr_elapse_time(): BSet<BTuple<Slots, Slots>> {
        let _ic_set_0: BSet<BTuple<Slots, Slots>> = new BSet<BTuple<Slots, Slots>>();
        for(let _ic_next_1 of rether._Slots) {
            for(let _ic_slot_1 of rether._Slots) {
                if((new BBoolean(rether.nextSlots.elementOf(new BTuple(_ic_slot_1, _ic_next_1)).booleanValue() && _ic_slot_1.equal(this.time).booleanValue())).booleanValue()) {
                    _ic_set_0 = _ic_set_0.union(new BSet<BTuple<Slots, Slots>>(new BTuple(_ic_next_1, _ic_slot_1)));
                }

            }

        }

        return _ic_set_0;
    }

    _tr_reserve(): BSet<BTuple<Nodes, Slots>> {
        let _ic_set_1: BSet<BTuple<Nodes, Slots>> = new BSet<BTuple<Nodes, Slots>>();
        for(let _ic_node_1 of rether._Nodes) {
            for(let _ic_slot_1 of rether._Slots) {
                if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.open_reservations.isNotInDomain(_ic_node_1).booleanValue() && this.open_reservations.isNotInRange(_ic_slot_1).booleanValue()).booleanValue() && this.open_reservations.notElementOf(new BTuple(_ic_node_1, _ic_slot_1)).booleanValue()).booleanValue() && this.grants.isNotInDomain(_ic_node_1).booleanValue()).booleanValue() && this.grants.isNotInRange(_ic_slot_1).booleanValue())).booleanValue()) {
                    _ic_set_1 = _ic_set_1.union(new BSet<BTuple<Nodes, Slots>>(new BTuple(_ic_node_1, _ic_slot_1)));
                }

            }

        }

        return _ic_set_1;
    }

    _tr_release(): BSet<BTuple<Nodes, Slots>> {
        let _ic_set_2: BSet<BTuple<Nodes, Slots>> = new BSet<BTuple<Nodes, Slots>>();
        for(let _ic_node_1 of rether._Nodes) {
            for(let _ic_slot_1 of rether._Slots) {
                if((this.grants.elementOf(new BTuple(_ic_node_1, _ic_slot_1))).booleanValue()) {
                    _ic_set_2 = _ic_set_2.union(new BSet<BTuple<Nodes, Slots>>(new BTuple(_ic_node_1, _ic_slot_1)));
                }

            }

        }

        return _ic_set_2;
    }

    _tr_grant(): BSet<BTuple<Nodes, Slots>> {
        let _ic_set_3: BSet<BTuple<Nodes, Slots>> = new BSet<BTuple<Nodes, Slots>>();
        for(let _ic_node_1 of rether._Nodes) {
            for(let _ic_slot_1 of rether._Slots) {
                if((new BBoolean(new BBoolean(new BBoolean(this.open_reservations.isInDomain(_ic_node_1).booleanValue() && this.open_reservations.isInRange(_ic_slot_1).booleanValue()).booleanValue() && this.open_reservations.elementOf(new BTuple(_ic_node_1, _ic_slot_1)).booleanValue()).booleanValue() && this.RT_count.greater(new BInteger(0)).booleanValue())).booleanValue()) {
                    _ic_set_3 = _ic_set_3.union(new BSet<BTuple<Nodes, Slots>>(new BTuple(_ic_node_1, _ic_slot_1)));
                }

            }

        }

        return _ic_set_3;
    }

    _tr_no_grant(): BSet<BTuple<Nodes, Slots>> {
        let _ic_set_4: BSet<BTuple<Nodes, Slots>> = new BSet<BTuple<Nodes, Slots>>();
        for(let _ic_node_1 of rether._Nodes) {
            for(let _ic_slot_1 of rether._Slots) {
                if((new BBoolean(new BBoolean(this.open_reservations.isInDomain(_ic_node_1).booleanValue() && this.open_reservations.isInRange(_ic_slot_1).booleanValue()).booleanValue() && this.open_reservations.elementOf(new BTuple(_ic_node_1, _ic_slot_1)).booleanValue())).booleanValue()) {
                    _ic_set_4 = _ic_set_4.union(new BSet<BTuple<Nodes, Slots>>(new BTuple(_ic_node_1, _ic_slot_1)));
                }

            }

        }

        return _ic_set_4;
    }

    _tr_use_RT_Slot(): BSet<BTuple<Nodes, Slots>> {
        let _ic_set_5: BSet<BTuple<Nodes, Slots>> = new BSet<BTuple<Nodes, Slots>>();
        for(let _ic_node_1 of rether._Nodes) {
            for(let _ic_slot_1 of rether._Slots) {
                if((new BBoolean(new BBoolean(this.grants.elementOf(new BTuple(_ic_node_1, _ic_slot_1)).booleanValue() && _ic_slot_1.equal(this.time).booleanValue()).booleanValue() && _ic_node_1.equal(this.token).booleanValue())).booleanValue()) {
                    _ic_set_5 = _ic_set_5.union(new BSet<BTuple<Nodes, Slots>>(new BTuple(_ic_node_1, _ic_slot_1)));
                }

            }

        }

        return _ic_set_5;
    }

    _tr_use_NRT_Slot(): BSet<BTuple<Nodes, Slots>> {
        let _ic_set_6: BSet<BTuple<Nodes, Slots>> = new BSet<BTuple<Nodes, Slots>>();
        for(let _ic_node_1 of rether._Nodes) {
            for(let _ic_slot_1 of rether._Slots) {
                if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(this.grants.notElementOf(new BTuple(_ic_node_1, _ic_slot_1)).booleanValue() && _ic_slot_1.equal(this.time).booleanValue()).booleanValue() && this.grants.isNotInDomain(_ic_node_1).booleanValue()).booleanValue() && this.grants.isNotInRange(_ic_slot_1).booleanValue()).booleanValue() && _ic_node_1.equal(this.token).booleanValue())).booleanValue()) {
                    _ic_set_6 = _ic_set_6.union(new BSet<BTuple<Nodes, Slots>>(new BTuple(_ic_node_1, _ic_slot_1)));
                }

            }

        }

        return _ic_set_6;
    }

    _tr_pass_token(): BSet<Nodes> {
        let _ic_set_7: BSet<Nodes> = new BSet<Nodes>();
        for(let _ic_node_1 of rether._Nodes) {
            if((_ic_node_1.equal(this.token)).booleanValue()) {
                _ic_set_7 = _ic_set_7.union(new BSet<Nodes>(_ic_node_1));
            }

        }

        return _ic_set_7;
    }

    _projected_state_for_release(): _ProjectionRead_release {
        return new _ProjectionRead_release(this.grants,this.RT_count);
    }

    _projected_state_for_reserve(): _ProjectionRead_reserve {
        return new _ProjectionRead_reserve(this.grants,this.open_reservations);
    }

    _projected_state_for_use_RT_Slot(): _ProjectionRead_use_RT_Slot {
        return new _ProjectionRead_use_RT_Slot(this.grants,this.time,this.token);
    }

    _projected_state_for_use_NRT_Slot(): _ProjectionRead_use_NRT_Slot {
        return new _ProjectionRead_use_NRT_Slot(this.grants,this.time,this.token);
    }

    _projected_state_for_elapse_time(): _ProjectionRead_elapse_time {
        return new _ProjectionRead_elapse_time(this.time);
    }

    _projected_state_for_grant(): _ProjectionRead_grant {
        return new _ProjectionRead_grant(this.grants,this.open_reservations,this.RT_count);
    }

    _projected_state_for_no_grant(): _ProjectionRead_no_grant {
        return new _ProjectionRead_no_grant(this.open_reservations);
    }

    _projected_state_for_pass_token(): _ProjectionRead_pass_token {
        return new _ProjectionRead_pass_token(this.token);
    }

    _projected_state_for__tr_pass_token(): _ProjectionRead__tr_pass_token {
        return new _ProjectionRead__tr_pass_token(this.token);
    }

    _projected_state_for__tr_elapse_time(): _ProjectionRead__tr_elapse_time {
        return new _ProjectionRead__tr_elapse_time(this.time);
    }

    _projected_state_for__tr_use_NRT_Slot(): _ProjectionRead__tr_use_NRT_Slot {
        return new _ProjectionRead__tr_use_NRT_Slot(this.grants,this.time,this.token);
    }

    _projected_state_for__tr_reserve(): _ProjectionRead__tr_reserve {
        return new _ProjectionRead__tr_reserve(this.grants,this.open_reservations);
    }

    _projected_state_for__tr_no_grant(): _ProjectionRead__tr_no_grant {
        return new _ProjectionRead__tr_no_grant(this.open_reservations);
    }

    _projected_state_for__tr_release(): _ProjectionRead__tr_release {
        return new _ProjectionRead__tr_release(this.grants);
    }

    _projected_state_for__tr_grant(): _ProjectionRead__tr_grant {
        return new _ProjectionRead__tr_grant(this.open_reservations,this.RT_count);
    }

    _projected_state_for__tr_use_RT_Slot(): _ProjectionRead__tr_use_RT_Slot {
        return new _ProjectionRead__tr_use_RT_Slot(this.grants,this.time,this.token);
    }

    _projected_state_for__check_inv_2(): _ProjectionRead__check_inv_2 {
        return new _ProjectionRead__check_inv_2(this.token);
    }

    _projected_state_for__check_inv_3(): _ProjectionRead__check_inv_3 {
        return new _ProjectionRead__check_inv_3(this.open_reservations);
    }

    _projected_state_for__check_inv_1(): _ProjectionRead__check_inv_1 {
        return new _ProjectionRead__check_inv_1(this.time);
    }

    _projected_state_for__check_inv_4(): _ProjectionRead__check_inv_4 {
        return new _ProjectionRead__check_inv_4(this.grants);
    }

    _projected_state_for__check_inv_5(): _ProjectionRead__check_inv_5 {
        return new _ProjectionRead__check_inv_5(this.RT_count);
    }

    _update_for_release(): _ProjectionWrite_release {
        return new _ProjectionWrite_release(this.grants,this.RT_count);
    }

    _update_for_reserve(): _ProjectionWrite_reserve {
        return new _ProjectionWrite_reserve(this.open_reservations);
    }

    _update_for_use_RT_Slot(): _ProjectionWrite_use_RT_Slot {
        return new _ProjectionWrite_use_RT_Slot();
    }

    _update_for_use_NRT_Slot(): _ProjectionWrite_use_NRT_Slot {
        return new _ProjectionWrite_use_NRT_Slot();
    }

    _update_for_elapse_time(): _ProjectionWrite_elapse_time {
        return new _ProjectionWrite_elapse_time(this.time);
    }

    _update_for_grant(): _ProjectionWrite_grant {
        return new _ProjectionWrite_grant(this.grants,this.open_reservations,this.RT_count);
    }

    _update_for_no_grant(): _ProjectionWrite_no_grant {
        return new _ProjectionWrite_no_grant(this.open_reservations);
    }

    _update_for_pass_token(): _ProjectionWrite_pass_token {
        return new _ProjectionWrite_pass_token(this.token);
    }

    _apply_update_for_release(update : _ProjectionWrite_release): void {
        this.grants = update.grants;
        this.RT_count = update.RT_count;
    }

    _apply_update_for_reserve(update : _ProjectionWrite_reserve): void {
        this.open_reservations = update.open_reservations;
    }

    _apply_update_for_use_RT_Slot(update : _ProjectionWrite_use_RT_Slot): void {
    }

    _apply_update_for_use_NRT_Slot(update : _ProjectionWrite_use_NRT_Slot): void {
    }

    _apply_update_for_elapse_time(update : _ProjectionWrite_elapse_time): void {
        this.time = update.time;
    }

    _apply_update_for_grant(update : _ProjectionWrite_grant): void {
        this.grants = update.grants;
        this.open_reservations = update.open_reservations;
        this.RT_count = update.RT_count;
    }

    _apply_update_for_no_grant(update : _ProjectionWrite_no_grant): void {
        this.open_reservations = update.open_reservations;
    }

    _apply_update_for_pass_token(update : _ProjectionWrite_pass_token): void {
        this.token = update.token;
    }

    _check_inv_1() {
        return rether._Slots.elementOf(this.time).booleanValue();
    }

    _check_inv_2() {
        return rether._Nodes.elementOf(this.token).booleanValue();
    }

    _check_inv_3() {
        return this.open_reservations.checkDomain(rether._Nodes).and(this.open_reservations.checkRange(rether._Slots)).and(this.open_reservations.isFunction()).and(this.open_reservations.isPartial(rether._Nodes)).booleanValue();
    }

    _check_inv_4() {
        return this.grants.checkDomain(rether._Nodes).and(this.grants.checkRange(rether._Slots)).and(this.grants.isFunction()).and(this.grants.isPartial(rether._Nodes)).booleanValue();
    }

    _check_inv_5() {
        return new BBoolean(this.RT_count.greaterEqual(new BInteger(0)).booleanValue() && this.RT_count.lessEqual(new BInteger(2147483647)).booleanValue()).booleanValue();
    }


    public _copy(): rether {
      return new rether(this);
    }


}


export class ModelChecker {
    private type: Type;
    private isCaching: boolean;
    private isDebug: boolean;

    private unvisitedStates: LinkedList<rether> = new LinkedList<rether>;
    private states: immutable.Set<rether> = new immutable.Set();
    private transitions: number = 0;

    private invariantViolated: boolean = false;
    private deadlockDetected: boolean = false;
    private counterExampleState: rether = undefined;

    _OpCache_elapse_time: immutable.Map<BSet<BTuple<Slots, Slots>>, immutable.Map<_ProjectionRead_elapse_time, _ProjectionWrite_elapse_time>> = new immutable.Map();
    _OpCache_tr_elapse_time: immutable.Map<_ProjectionRead__tr_elapse_time, BSet<BTuple<Slots, Slots>>> = new immutable.Map();

    _OpCache_reserve: immutable.Map<BSet<BTuple<Nodes, Slots>>, immutable.Map<_ProjectionRead_reserve, _ProjectionWrite_reserve>> = new immutable.Map();
    _OpCache_tr_reserve: immutable.Map<_ProjectionRead__tr_reserve, BSet<BTuple<Nodes, Slots>>> = new immutable.Map();

    _OpCache_release: immutable.Map<BSet<BTuple<Nodes, Slots>>, immutable.Map<_ProjectionRead_release, _ProjectionWrite_release>> = new immutable.Map();
    _OpCache_tr_release: immutable.Map<_ProjectionRead__tr_release, BSet<BTuple<Nodes, Slots>>> = new immutable.Map();

    _OpCache_grant: immutable.Map<BSet<BTuple<Nodes, Slots>>, immutable.Map<_ProjectionRead_grant, _ProjectionWrite_grant>> = new immutable.Map();
    _OpCache_tr_grant: immutable.Map<_ProjectionRead__tr_grant, BSet<BTuple<Nodes, Slots>>> = new immutable.Map();

    _OpCache_no_grant: immutable.Map<BSet<BTuple<Nodes, Slots>>, immutable.Map<_ProjectionRead_no_grant, _ProjectionWrite_no_grant>> = new immutable.Map();
    _OpCache_tr_no_grant: immutable.Map<_ProjectionRead__tr_no_grant, BSet<BTuple<Nodes, Slots>>> = new immutable.Map();

    _OpCache_use_RT_Slot: immutable.Map<BSet<BTuple<Nodes, Slots>>, immutable.Map<_ProjectionRead_use_RT_Slot, _ProjectionWrite_use_RT_Slot>> = new immutable.Map();
    _OpCache_tr_use_RT_Slot: immutable.Map<_ProjectionRead__tr_use_RT_Slot, BSet<BTuple<Nodes, Slots>>> = new immutable.Map();

    _OpCache_use_NRT_Slot: immutable.Map<BSet<BTuple<Nodes, Slots>>, immutable.Map<_ProjectionRead_use_NRT_Slot, _ProjectionWrite_use_NRT_Slot>> = new immutable.Map();
    _OpCache_tr_use_NRT_Slot: immutable.Map<_ProjectionRead__tr_use_NRT_Slot, BSet<BTuple<Nodes, Slots>>> = new immutable.Map();

    _OpCache_pass_token: immutable.Map<BSet<Nodes>, immutable.Map<_ProjectionRead_pass_token, _ProjectionWrite_pass_token>> = new immutable.Map();
    _OpCache_tr_pass_token: immutable.Map<_ProjectionRead__tr_pass_token, BSet<Nodes>> = new immutable.Map();

    _InvCache__check_inv_1: immutable.Map<_ProjectionRead__check_inv_1, boolean> = new immutable.Map();
    _InvCache__check_inv_2: immutable.Map<_ProjectionRead__check_inv_2, boolean> = new immutable.Map();
    _InvCache__check_inv_3: immutable.Map<_ProjectionRead__check_inv_3, boolean> = new immutable.Map();
    _InvCache__check_inv_4: immutable.Map<_ProjectionRead__check_inv_4, boolean> = new immutable.Map();
    _InvCache__check_inv_5: immutable.Map<_ProjectionRead__check_inv_5, boolean> = new immutable.Map();

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
        let machine: rether = new rether();
        this.states = this.states.add(machine);
        this.unvisitedStates.pushBack(machine);

        while(!(this.unvisitedStates.length === 0)) {
            let state: rether = this.next();

            let nextStates: Set<rether> = this.generateNextStates(state);

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

    next(): rether {
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

    generateNextStates(state: rether): Set<rether> {
        let result: immutable.Set<rether> = immutable.Set();
        if(this.isCaching) {
            let read__tr_elapse_time_state : _ProjectionRead__tr_elapse_time = state._projected_state_for__tr_elapse_time();
            let _trid_1 : BSet<BTuple<Slots, Slots>>  = this._OpCache_tr_elapse_time.get(read__tr_elapse_time_state);
            if(_trid_1 == null) {
                _trid_1 = state._tr_elapse_time();
                this._OpCache_tr_elapse_time = this._OpCache_tr_elapse_time.set(read__tr_elapse_time_state, _trid_1);
            }

            for(let param of _trid_1) {
                let _tmp_1: Slots = param.projection2();
                let _tmp_2: Slots = param.projection1();

                let copiedState: rether = state._copy();
                let readState: _ProjectionRead_elapse_time = state._projected_state_for_elapse_time();
                let _OpCache_with_parameter_elapse_time: immutable.Map = this._OpCache_elapse_time.get(param);
                if(_OpCache_with_parameter_elapse_time != null) {
                    let writeState: _ProjectionWrite_elapse_time = _OpCache_with_parameter_elapse_time.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_elapse_time(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.elapse_time(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_elapse_time();
                        _OpCache_with_parameter_elapse_time = _OpCache_with_parameter_elapse_time.set(readState, writeState);
                        this._OpCache_elapse_time = this._OpCache_elapse_time.set(param, _OpCache_with_parameter_elapse_time);
                    }

                } else {
                    copiedState.elapse_time(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_elapse_time = copiedState._update_for_elapse_time();
                    _OpCache_with_parameter_elapse_time = new immutable.Map().set(readState, writeState);
                    this._OpCache_elapse_time = this._OpCache_elapse_time.set(param, _OpCache_with_parameter_elapse_time);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_reserve_state : _ProjectionRead__tr_reserve = state._projected_state_for__tr_reserve();
            let _trid_2 : BSet<BTuple<Nodes, Slots>>  = this._OpCache_tr_reserve.get(read__tr_reserve_state);
            if(_trid_2 == null) {
                _trid_2 = state._tr_reserve();
                this._OpCache_tr_reserve = this._OpCache_tr_reserve.set(read__tr_reserve_state, _trid_2);
            }

            for(let param of _trid_2) {
                let _tmp_1: Slots = param.projection2();
                let _tmp_2: Nodes = param.projection1();

                let copiedState: rether = state._copy();
                let readState: _ProjectionRead_reserve = state._projected_state_for_reserve();
                let _OpCache_with_parameter_reserve: immutable.Map = this._OpCache_reserve.get(param);
                if(_OpCache_with_parameter_reserve != null) {
                    let writeState: _ProjectionWrite_reserve = _OpCache_with_parameter_reserve.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_reserve(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.reserve(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_reserve();
                        _OpCache_with_parameter_reserve = _OpCache_with_parameter_reserve.set(readState, writeState);
                        this._OpCache_reserve = this._OpCache_reserve.set(param, _OpCache_with_parameter_reserve);
                    }

                } else {
                    copiedState.reserve(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_reserve = copiedState._update_for_reserve();
                    _OpCache_with_parameter_reserve = new immutable.Map().set(readState, writeState);
                    this._OpCache_reserve = this._OpCache_reserve.set(param, _OpCache_with_parameter_reserve);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_release_state : _ProjectionRead__tr_release = state._projected_state_for__tr_release();
            let _trid_3 : BSet<BTuple<Nodes, Slots>>  = this._OpCache_tr_release.get(read__tr_release_state);
            if(_trid_3 == null) {
                _trid_3 = state._tr_release();
                this._OpCache_tr_release = this._OpCache_tr_release.set(read__tr_release_state, _trid_3);
            }

            for(let param of _trid_3) {
                let _tmp_1: Slots = param.projection2();
                let _tmp_2: Nodes = param.projection1();

                let copiedState: rether = state._copy();
                let readState: _ProjectionRead_release = state._projected_state_for_release();
                let _OpCache_with_parameter_release: immutable.Map = this._OpCache_release.get(param);
                if(_OpCache_with_parameter_release != null) {
                    let writeState: _ProjectionWrite_release = _OpCache_with_parameter_release.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_release(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.release(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_release();
                        _OpCache_with_parameter_release = _OpCache_with_parameter_release.set(readState, writeState);
                        this._OpCache_release = this._OpCache_release.set(param, _OpCache_with_parameter_release);
                    }

                } else {
                    copiedState.release(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_release = copiedState._update_for_release();
                    _OpCache_with_parameter_release = new immutable.Map().set(readState, writeState);
                    this._OpCache_release = this._OpCache_release.set(param, _OpCache_with_parameter_release);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_grant_state : _ProjectionRead__tr_grant = state._projected_state_for__tr_grant();
            let _trid_4 : BSet<BTuple<Nodes, Slots>>  = this._OpCache_tr_grant.get(read__tr_grant_state);
            if(_trid_4 == null) {
                _trid_4 = state._tr_grant();
                this._OpCache_tr_grant = this._OpCache_tr_grant.set(read__tr_grant_state, _trid_4);
            }

            for(let param of _trid_4) {
                let _tmp_1: Slots = param.projection2();
                let _tmp_2: Nodes = param.projection1();

                let copiedState: rether = state._copy();
                let readState: _ProjectionRead_grant = state._projected_state_for_grant();
                let _OpCache_with_parameter_grant: immutable.Map = this._OpCache_grant.get(param);
                if(_OpCache_with_parameter_grant != null) {
                    let writeState: _ProjectionWrite_grant = _OpCache_with_parameter_grant.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_grant(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.grant(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_grant();
                        _OpCache_with_parameter_grant = _OpCache_with_parameter_grant.set(readState, writeState);
                        this._OpCache_grant = this._OpCache_grant.set(param, _OpCache_with_parameter_grant);
                    }

                } else {
                    copiedState.grant(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_grant = copiedState._update_for_grant();
                    _OpCache_with_parameter_grant = new immutable.Map().set(readState, writeState);
                    this._OpCache_grant = this._OpCache_grant.set(param, _OpCache_with_parameter_grant);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_no_grant_state : _ProjectionRead__tr_no_grant = state._projected_state_for__tr_no_grant();
            let _trid_5 : BSet<BTuple<Nodes, Slots>>  = this._OpCache_tr_no_grant.get(read__tr_no_grant_state);
            if(_trid_5 == null) {
                _trid_5 = state._tr_no_grant();
                this._OpCache_tr_no_grant = this._OpCache_tr_no_grant.set(read__tr_no_grant_state, _trid_5);
            }

            for(let param of _trid_5) {
                let _tmp_1: Slots = param.projection2();
                let _tmp_2: Nodes = param.projection1();

                let copiedState: rether = state._copy();
                let readState: _ProjectionRead_no_grant = state._projected_state_for_no_grant();
                let _OpCache_with_parameter_no_grant: immutable.Map = this._OpCache_no_grant.get(param);
                if(_OpCache_with_parameter_no_grant != null) {
                    let writeState: _ProjectionWrite_no_grant = _OpCache_with_parameter_no_grant.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_no_grant(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.no_grant(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_no_grant();
                        _OpCache_with_parameter_no_grant = _OpCache_with_parameter_no_grant.set(readState, writeState);
                        this._OpCache_no_grant = this._OpCache_no_grant.set(param, _OpCache_with_parameter_no_grant);
                    }

                } else {
                    copiedState.no_grant(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_no_grant = copiedState._update_for_no_grant();
                    _OpCache_with_parameter_no_grant = new immutable.Map().set(readState, writeState);
                    this._OpCache_no_grant = this._OpCache_no_grant.set(param, _OpCache_with_parameter_no_grant);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_use_RT_Slot_state : _ProjectionRead__tr_use_RT_Slot = state._projected_state_for__tr_use_RT_Slot();
            let _trid_6 : BSet<BTuple<Nodes, Slots>>  = this._OpCache_tr_use_RT_Slot.get(read__tr_use_RT_Slot_state);
            if(_trid_6 == null) {
                _trid_6 = state._tr_use_RT_Slot();
                this._OpCache_tr_use_RT_Slot = this._OpCache_tr_use_RT_Slot.set(read__tr_use_RT_Slot_state, _trid_6);
            }

            for(let param of _trid_6) {
                let _tmp_1: Slots = param.projection2();
                let _tmp_2: Nodes = param.projection1();

                let copiedState: rether = state._copy();
                let readState: _ProjectionRead_use_RT_Slot = state._projected_state_for_use_RT_Slot();
                let _OpCache_with_parameter_use_RT_Slot: immutable.Map = this._OpCache_use_RT_Slot.get(param);
                if(_OpCache_with_parameter_use_RT_Slot != null) {
                    let writeState: _ProjectionWrite_use_RT_Slot = _OpCache_with_parameter_use_RT_Slot.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_use_RT_Slot(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.use_RT_Slot(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_use_RT_Slot();
                        _OpCache_with_parameter_use_RT_Slot = _OpCache_with_parameter_use_RT_Slot.set(readState, writeState);
                        this._OpCache_use_RT_Slot = this._OpCache_use_RT_Slot.set(param, _OpCache_with_parameter_use_RT_Slot);
                    }

                } else {
                    copiedState.use_RT_Slot(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_use_RT_Slot = copiedState._update_for_use_RT_Slot();
                    _OpCache_with_parameter_use_RT_Slot = new immutable.Map().set(readState, writeState);
                    this._OpCache_use_RT_Slot = this._OpCache_use_RT_Slot.set(param, _OpCache_with_parameter_use_RT_Slot);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_use_NRT_Slot_state : _ProjectionRead__tr_use_NRT_Slot = state._projected_state_for__tr_use_NRT_Slot();
            let _trid_7 : BSet<BTuple<Nodes, Slots>>  = this._OpCache_tr_use_NRT_Slot.get(read__tr_use_NRT_Slot_state);
            if(_trid_7 == null) {
                _trid_7 = state._tr_use_NRT_Slot();
                this._OpCache_tr_use_NRT_Slot = this._OpCache_tr_use_NRT_Slot.set(read__tr_use_NRT_Slot_state, _trid_7);
            }

            for(let param of _trid_7) {
                let _tmp_1: Slots = param.projection2();
                let _tmp_2: Nodes = param.projection1();

                let copiedState: rether = state._copy();
                let readState: _ProjectionRead_use_NRT_Slot = state._projected_state_for_use_NRT_Slot();
                let _OpCache_with_parameter_use_NRT_Slot: immutable.Map = this._OpCache_use_NRT_Slot.get(param);
                if(_OpCache_with_parameter_use_NRT_Slot != null) {
                    let writeState: _ProjectionWrite_use_NRT_Slot = _OpCache_with_parameter_use_NRT_Slot.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_use_NRT_Slot(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.use_NRT_Slot(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_use_NRT_Slot();
                        _OpCache_with_parameter_use_NRT_Slot = _OpCache_with_parameter_use_NRT_Slot.set(readState, writeState);
                        this._OpCache_use_NRT_Slot = this._OpCache_use_NRT_Slot.set(param, _OpCache_with_parameter_use_NRT_Slot);
                    }

                } else {
                    copiedState.use_NRT_Slot(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_use_NRT_Slot = copiedState._update_for_use_NRT_Slot();
                    _OpCache_with_parameter_use_NRT_Slot = new immutable.Map().set(readState, writeState);
                    this._OpCache_use_NRT_Slot = this._OpCache_use_NRT_Slot.set(param, _OpCache_with_parameter_use_NRT_Slot);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_pass_token_state : _ProjectionRead__tr_pass_token = state._projected_state_for__tr_pass_token();
            let _trid_8 : BSet<Nodes>  = this._OpCache_tr_pass_token.get(read__tr_pass_token_state);
            if(_trid_8 == null) {
                _trid_8 = state._tr_pass_token();
                this._OpCache_tr_pass_token = this._OpCache_tr_pass_token.set(read__tr_pass_token_state, _trid_8);
            }

            for(let param of _trid_8) {
                let _tmp_1: Nodes = param;

                let copiedState: rether = state._copy();
                let readState: _ProjectionRead_pass_token = state._projected_state_for_pass_token();
                let _OpCache_with_parameter_pass_token: immutable.Map = this._OpCache_pass_token.get(param);
                if(_OpCache_with_parameter_pass_token != null) {
                    let writeState: _ProjectionWrite_pass_token = _OpCache_with_parameter_pass_token.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_pass_token(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.pass_token(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_pass_token();
                        _OpCache_with_parameter_pass_token = _OpCache_with_parameter_pass_token.set(readState, writeState);
                        this._OpCache_pass_token = this._OpCache_pass_token.set(param, _OpCache_with_parameter_pass_token);
                    }

                } else {
                    copiedState.pass_token(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_pass_token = copiedState._update_for_pass_token();
                    _OpCache_with_parameter_pass_token = new immutable.Map().set(readState, writeState);
                    this._OpCache_pass_token = this._OpCache_pass_token.set(param, _OpCache_with_parameter_pass_token);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        } else {
            let _trid_1: BSet<BTuple<Slots, Slots>> = state._tr_elapse_time();
            for(let param of _trid_1) {
                let _tmp_1: Slots = param.projection2();
                let _tmp_2: Slots = param.projection1();

                let copiedState: rether = state._copy();
                copiedState.elapse_time(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_2: BSet<BTuple<Nodes, Slots>> = state._tr_reserve();
            for(let param of _trid_2) {
                let _tmp_1: Slots = param.projection2();
                let _tmp_2: Nodes = param.projection1();

                let copiedState: rether = state._copy();
                copiedState.reserve(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_3: BSet<BTuple<Nodes, Slots>> = state._tr_release();
            for(let param of _trid_3) {
                let _tmp_1: Slots = param.projection2();
                let _tmp_2: Nodes = param.projection1();

                let copiedState: rether = state._copy();
                copiedState.release(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_4: BSet<BTuple<Nodes, Slots>> = state._tr_grant();
            for(let param of _trid_4) {
                let _tmp_1: Slots = param.projection2();
                let _tmp_2: Nodes = param.projection1();

                let copiedState: rether = state._copy();
                copiedState.grant(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_5: BSet<BTuple<Nodes, Slots>> = state._tr_no_grant();
            for(let param of _trid_5) {
                let _tmp_1: Slots = param.projection2();
                let _tmp_2: Nodes = param.projection1();

                let copiedState: rether = state._copy();
                copiedState.no_grant(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_6: BSet<BTuple<Nodes, Slots>> = state._tr_use_RT_Slot();
            for(let param of _trid_6) {
                let _tmp_1: Slots = param.projection2();
                let _tmp_2: Nodes = param.projection1();

                let copiedState: rether = state._copy();
                copiedState.use_RT_Slot(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_7: BSet<BTuple<Nodes, Slots>> = state._tr_use_NRT_Slot();
            for(let param of _trid_7) {
                let _tmp_1: Slots = param.projection2();
                let _tmp_2: Nodes = param.projection1();

                let copiedState: rether = state._copy();
                copiedState.use_NRT_Slot(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_8: BSet<Nodes> = state._tr_pass_token();
            for(let param of _trid_8) {
                let _tmp_1: Nodes = param;

                let copiedState: rether = state._copy();
                copiedState.pass_token(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        }
        return result;
    }

    invViolated(state: rether): boolean {
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

