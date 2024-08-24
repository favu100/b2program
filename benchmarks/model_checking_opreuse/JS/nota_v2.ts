import {BTuple} from './btypes/BTuple.js';
import {BInteger} from './btypes/BInteger.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BRelation} from './btypes/BRelation.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BStruct} from './btypes/BStruct.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";
import {VariantViolation} from "./btypes/BUtils.js";
import {LoopInvariantViolation} from "./btypes/BUtils.js";
import * as immutable from "./immutable/dist/immutable.es.js";
import {LinkedList} from  "./modelchecking/LinkedList.js";


export enum enum_INTERCONNECTNODE {
    node1,
    node2
}

export class INTERCONNECTNODE implements BObject{
    value: enum_INTERCONNECTNODE;

    constructor(value: enum_INTERCONNECTNODE) {
        this.value = value;
    }

    equal(other: INTERCONNECTNODE) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: INTERCONNECTNODE) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof INTERCONNECTNODE)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_INTERCONNECTNODE[this.value].toString();
    }

    static get_node1 () {return new INTERCONNECTNODE(enum_INTERCONNECTNODE.node1);}
    static get_node2 () {return new INTERCONNECTNODE(enum_INTERCONNECTNODE.node2);}


}

export enum enum_SOCKET {
    socket1,
    socket2
}

export class SOCKET implements BObject{
    value: enum_SOCKET;

    constructor(value: enum_SOCKET) {
        this.value = value;
    }

    equal(other: SOCKET) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: SOCKET) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof SOCKET)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_SOCKET[this.value].toString();
    }

    static get_socket1 () {return new SOCKET(enum_SOCKET.socket1);}
    static get_socket2 () {return new SOCKET(enum_SOCKET.socket2);}


}

export enum enum_SERVICE {
    service1,
    service2
}

export class SERVICE implements BObject{
    value: enum_SERVICE;

    constructor(value: enum_SERVICE) {
        this.value = value;
    }

    equal(other: SERVICE) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: SERVICE) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof SERVICE)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_SERVICE[this.value].toString();
    }

    static get_service1 () {return new SERVICE(enum_SERVICE.service1);}
    static get_service2 () {return new SERVICE(enum_SERVICE.service2);}


}

export enum enum_RESOURCEMANAGER {
    resource1,
    resource2
}

export class RESOURCEMANAGER implements BObject{
    value: enum_RESOURCEMANAGER;

    constructor(value: enum_RESOURCEMANAGER) {
        this.value = value;
    }

    equal(other: RESOURCEMANAGER) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: RESOURCEMANAGER) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof RESOURCEMANAGER)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_RESOURCEMANAGER[this.value].toString();
    }

    static get_resource1 () {return new RESOURCEMANAGER(enum_RESOURCEMANAGER.resource1);}
    static get_resource2 () {return new RESOURCEMANAGER(enum_RESOURCEMANAGER.resource2);}


}

export enum enum_SID {
    SID1,
    SID2
}

export class SID implements BObject{
    value: enum_SID;

    constructor(value: enum_SID) {
        this.value = value;
    }

    equal(other: SID) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: SID) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof SID)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_SID[this.value].toString();
    }

    static get_SID1 () {return new SID(enum_SID.SID1);}
    static get_SID2 () {return new SID(enum_SID.SID2);}


}

export enum enum_RM_ERROR_CODES {
    RM_SERVICE_FOUND,
    RM_SERVICE_NOT_FOUND
}

export class RM_ERROR_CODES implements BObject{
    value: enum_RM_ERROR_CODES;

    constructor(value: enum_RM_ERROR_CODES) {
        this.value = value;
    }

    equal(other: RM_ERROR_CODES) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: RM_ERROR_CODES) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof RM_ERROR_CODES)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_RM_ERROR_CODES[this.value].toString();
    }

    static get_RM_SERVICE_FOUND () {return new RM_ERROR_CODES(enum_RM_ERROR_CODES.RM_SERVICE_FOUND);}
    static get_RM_SERVICE_NOT_FOUND () {return new RM_ERROR_CODES(enum_RM_ERROR_CODES.RM_SERVICE_NOT_FOUND);}


}

export enum enum_IN_ERROR_CODES {
    IN_REGISTRATION_OK,
    IN_REGISTRATION_FAILED,
    IN_DEREGISTRATION_OK,
    IN_DEREGISTRATION_FAILED,
    IN_NO_SOCKET_CONNECTION,
    IN_SOCKET_CONNECTION_OK,
    IN_NO_AVAILABLE_SERVICE,
    IN_SERVICE_AVAILABLE,
    IN_TARGET_SOCKET_GRANTED,
    IN_TARGET_SOCKET_NOT_GRANTED
}

export class IN_ERROR_CODES implements BObject{
    value: enum_IN_ERROR_CODES;

    constructor(value: enum_IN_ERROR_CODES) {
        this.value = value;
    }

    equal(other: IN_ERROR_CODES) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: IN_ERROR_CODES) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof IN_ERROR_CODES)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_IN_ERROR_CODES[this.value].toString();
    }

    static get_IN_REGISTRATION_OK () {return new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_REGISTRATION_OK);}
    static get_IN_REGISTRATION_FAILED () {return new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_REGISTRATION_FAILED);}
    static get_IN_DEREGISTRATION_OK () {return new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_DEREGISTRATION_OK);}
    static get_IN_DEREGISTRATION_FAILED () {return new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_DEREGISTRATION_FAILED);}
    static get_IN_NO_SOCKET_CONNECTION () {return new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_NO_SOCKET_CONNECTION);}
    static get_IN_SOCKET_CONNECTION_OK () {return new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_SOCKET_CONNECTION_OK);}
    static get_IN_NO_AVAILABLE_SERVICE () {return new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_NO_AVAILABLE_SERVICE);}
    static get_IN_SERVICE_AVAILABLE () {return new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_SERVICE_AVAILABLE);}
    static get_IN_TARGET_SOCKET_GRANTED () {return new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_TARGET_SOCKET_GRANTED);}
    static get_IN_TARGET_SOCKET_NOT_GRANTED () {return new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_TARGET_SOCKET_NOT_GRANTED);}


}

class _Struct3 extends BStruct {
    private sid: BSet<SID>;
    private err: IN_ERROR_CODES;

    constructor(sid: BSet<SID>, err: IN_ERROR_CODES) {
        super();
        this.sid = sid;
        this.err = err;
    }

    get_sid(): BSet<SID> {
        return this.sid;
    }

    get_err(): IN_ERROR_CODES {
        return this.err;
    }

    override_sid(sid: BSet<SID>): _Struct3 {
        return new _Struct3(sid, this.err);
    }

    override_err(err: IN_ERROR_CODES): _Struct3 {
        return new _Struct3(this.sid, err);
    }

    equal(o: _Struct3): BBoolean {
        return new BBoolean(this.sid === o.sid && this.err === o.err);
    }

    unequal(o: _Struct3): BBoolean {
        return new BBoolean(this.sid !== o.sid || this.err !== o.err);
    }

    toString(): string {
        return "(" + "sid : " + this.sid + "," + "err : " + this.err + ")";
    }

    equals(other: any): boolean {
        if(!(other instanceof _Struct3)) {
            return false;
        }
        let o: _Struct3 = other as _Struct3;
        return this.sid === o.sid && this.err === o.err;
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.sid.hashCode() << 1);
        result = 31 * result + (this.err.hashCode() << 1);
        return result;
    }

    isRecord() {
        return new BBoolean(true);
    }

    isNotRecord() {
        return new BBoolean(false);
    }
}

class _Struct5 extends BStruct {
    private soc: BSet<SOCKET>;
    private err: IN_ERROR_CODES;

    constructor(soc: BSet<SOCKET>, err: IN_ERROR_CODES) {
        super();
        this.soc = soc;
        this.err = err;
    }

    get_soc(): BSet<SOCKET> {
        return this.soc;
    }

    get_err(): IN_ERROR_CODES {
        return this.err;
    }

    override_soc(soc: BSet<SOCKET>): _Struct5 {
        return new _Struct5(soc, this.err);
    }

    override_err(err: IN_ERROR_CODES): _Struct5 {
        return new _Struct5(this.soc, err);
    }

    equal(o: _Struct5): BBoolean {
        return new BBoolean(this.soc === o.soc && this.err === o.err);
    }

    unequal(o: _Struct5): BBoolean {
        return new BBoolean(this.soc !== o.soc || this.err !== o.err);
    }

    toString(): string {
        return "(" + "soc : " + this.soc + "," + "err : " + this.err + ")";
    }

    equals(other: any): boolean {
        if(!(other instanceof _Struct5)) {
            return false;
        }
        let o: _Struct5 = other as _Struct5;
        return this.soc === o.soc && this.err === o.err;
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.soc.hashCode() << 1);
        result = 31 * result + (this.err.hashCode() << 1);
        return result;
    }

    isRecord() {
        return new BBoolean(true);
    }

    isNotRecord() {
        return new BBoolean(false);
    }
}

class _Struct1 extends BStruct {
    private sid: BSet<SID>;
    private err: RM_ERROR_CODES;

    constructor(sid: BSet<SID>, err: RM_ERROR_CODES) {
        super();
        this.sid = sid;
        this.err = err;
    }

    get_sid(): BSet<SID> {
        return this.sid;
    }

    get_err(): RM_ERROR_CODES {
        return this.err;
    }

    override_sid(sid: BSet<SID>): _Struct1 {
        return new _Struct1(sid, this.err);
    }

    override_err(err: RM_ERROR_CODES): _Struct1 {
        return new _Struct1(this.sid, err);
    }

    equal(o: _Struct1): BBoolean {
        return new BBoolean(this.sid === o.sid && this.err === o.err);
    }

    unequal(o: _Struct1): BBoolean {
        return new BBoolean(this.sid !== o.sid || this.err !== o.err);
    }

    toString(): string {
        return "(" + "sid : " + this.sid + "," + "err : " + this.err + ")";
    }

    equals(other: any): boolean {
        if(!(other instanceof _Struct1)) {
            return false;
        }
        let o: _Struct1 = other as _Struct1;
        return this.sid === o.sid && this.err === o.err;
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.sid.hashCode() << 1);
        result = 31 * result + (this.err.hashCode() << 1);
        return result;
    }

    isRecord() {
        return new BBoolean(true);
    }

    isNotRecord() {
        return new BBoolean(false);
    }
}

class _ProjectionRead_constructor_interconnectNode {

    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public in_resourceManager: BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>;

    constructor(interconnectNodes : BSet<INTERCONNECTNODE>, in_resourceManager : BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>) {
        this.interconnectNodes = interconnectNodes;
        this.in_resourceManager = in_resourceManager;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_constructor_interconnectNode = this;
        let o2: _ProjectionRead_constructor_interconnectNode = other as _ProjectionRead_constructor_interconnectNode;
        return o1.interconnectNodes.equals(o2.interconnectNodes) && o1.in_resourceManager.equals(o2.in_resourceManager);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.in_resourceManager.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_constructor_interconnectNode {

    public interconnectNodes: BSet<INTERCONNECTNODE>;

    constructor(interconnectNodes : BSet<INTERCONNECTNODE>) {
        this.interconnectNodes = interconnectNodes;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_constructor_interconnectNode = this;
        let o2: _ProjectionRead__tr_constructor_interconnectNode = other as _ProjectionRead__tr_constructor_interconnectNode;
        return o1.interconnectNodes.equals(o2.interconnectNodes);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_constructor_interconnectNode {

    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public in_resourceManager: BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>;

    constructor(interconnectNodes : BSet<INTERCONNECTNODE>, in_resourceManager : BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>) {
        this.interconnectNodes = interconnectNodes;
        this.in_resourceManager = in_resourceManager;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_constructor_interconnectNode = this;
        let o2: _ProjectionWrite_constructor_interconnectNode = other as _ProjectionWrite_constructor_interconnectNode;
        return o1.interconnectNodes.equals(o2.interconnectNodes) && o1.in_resourceManager.equals(o2.in_resourceManager);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.in_resourceManager.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_constructor_resourceManager {

    public rm_services: BRelation<RESOURCEMANAGER, BSet<SERVICE>>;
    public resourceManagers: BSet<RESOURCEMANAGER>;

    constructor(rm_services : BRelation<RESOURCEMANAGER, BSet<SERVICE>>, resourceManagers : BSet<RESOURCEMANAGER>) {
        this.rm_services = rm_services;
        this.resourceManagers = resourceManagers;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_constructor_resourceManager = this;
        let o2: _ProjectionRead_constructor_resourceManager = other as _ProjectionRead_constructor_resourceManager;
        return o1.rm_services.equals(o2.rm_services) && o1.resourceManagers.equals(o2.resourceManagers);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.rm_services.hashCode() << 1);
        result = 31 * result + (this.resourceManagers.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_constructor_resourceManager {

    public rm_services: BRelation<RESOURCEMANAGER, BSet<SERVICE>>;
    public resourceManagers: BSet<RESOURCEMANAGER>;

    constructor(rm_services : BRelation<RESOURCEMANAGER, BSet<SERVICE>>, resourceManagers : BSet<RESOURCEMANAGER>) {
        this.rm_services = rm_services;
        this.resourceManagers = resourceManagers;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_constructor_resourceManager = this;
        let o2: _ProjectionRead__tr_constructor_resourceManager = other as _ProjectionRead__tr_constructor_resourceManager;
        return o1.rm_services.equals(o2.rm_services) && o1.resourceManagers.equals(o2.resourceManagers);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.rm_services.hashCode() << 1);
        result = 31 * result + (this.resourceManagers.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_constructor_resourceManager {

    public rm_services: BRelation<RESOURCEMANAGER, BSet<SERVICE>>;
    public resourceManagers: BSet<RESOURCEMANAGER>;

    constructor(rm_services : BRelation<RESOURCEMANAGER, BSet<SERVICE>>, resourceManagers : BSet<RESOURCEMANAGER>) {
        this.rm_services = rm_services;
        this.resourceManagers = resourceManagers;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_constructor_resourceManager = this;
        let o2: _ProjectionWrite_constructor_resourceManager = other as _ProjectionWrite_constructor_resourceManager;
        return o1.rm_services.equals(o2.rm_services) && o1.resourceManagers.equals(o2.resourceManagers);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.rm_services.hashCode() << 1);
        result = 31 * result + (this.resourceManagers.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_constructor_service {

    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public svc_registered: BRelation<SERVICE, BBoolean>;
    public svc_sockets: BRelation<SERVICE, BSet<SOCKET>>;
    public services: BSet<SERVICE>;
    public svc_ICNode: BRelation<SERVICE, INTERCONNECTNODE>;

    constructor(interconnectNodes : BSet<INTERCONNECTNODE>, svc_registered : BRelation<SERVICE, BBoolean>, svc_sockets : BRelation<SERVICE, BSet<SOCKET>>, services : BSet<SERVICE>, svc_ICNode : BRelation<SERVICE, INTERCONNECTNODE>) {
        this.interconnectNodes = interconnectNodes;
        this.svc_registered = svc_registered;
        this.svc_sockets = svc_sockets;
        this.services = services;
        this.svc_ICNode = svc_ICNode;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_constructor_service = this;
        let o2: _ProjectionRead_constructor_service = other as _ProjectionRead_constructor_service;
        return o1.interconnectNodes.equals(o2.interconnectNodes) && o1.svc_registered.equals(o2.svc_registered) && o1.svc_sockets.equals(o2.svc_sockets) && o1.services.equals(o2.services) && o1.svc_ICNode.equals(o2.svc_ICNode);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.svc_registered.hashCode() << 1);
        result = 31 * result + (this.svc_sockets.hashCode() << 1);
        result = 31 * result + (this.services.hashCode() << 1);
        result = 31 * result + (this.svc_ICNode.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_constructor_service {

    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public services: BSet<SERVICE>;

    constructor(interconnectNodes : BSet<INTERCONNECTNODE>, services : BSet<SERVICE>) {
        this.interconnectNodes = interconnectNodes;
        this.services = services;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_constructor_service = this;
        let o2: _ProjectionRead__tr_constructor_service = other as _ProjectionRead__tr_constructor_service;
        return o1.interconnectNodes.equals(o2.interconnectNodes) && o1.services.equals(o2.services);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.services.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_constructor_service {

    public svc_registered: BRelation<SERVICE, BBoolean>;
    public svc_sockets: BRelation<SERVICE, BSet<SOCKET>>;
    public services: BSet<SERVICE>;
    public svc_serviceID: BRelation<SERVICE, SID>;
    public svc_ICNode: BRelation<SERVICE, INTERCONNECTNODE>;

    constructor(svc_registered : BRelation<SERVICE, BBoolean>, svc_sockets : BRelation<SERVICE, BSet<SOCKET>>, services : BSet<SERVICE>, svc_serviceID : BRelation<SERVICE, SID>, svc_ICNode : BRelation<SERVICE, INTERCONNECTNODE>) {
        this.svc_registered = svc_registered;
        this.svc_sockets = svc_sockets;
        this.services = services;
        this.svc_serviceID = svc_serviceID;
        this.svc_ICNode = svc_ICNode;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_constructor_service = this;
        let o2: _ProjectionWrite_constructor_service = other as _ProjectionWrite_constructor_service;
        return o1.svc_registered.equals(o2.svc_registered) && o1.svc_sockets.equals(o2.svc_sockets) && o1.services.equals(o2.services) && o1.svc_serviceID.equals(o2.svc_serviceID) && o1.svc_ICNode.equals(o2.svc_ICNode);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.svc_registered.hashCode() << 1);
        result = 31 * result + (this.svc_sockets.hashCode() << 1);
        result = 31 * result + (this.services.hashCode() << 1);
        result = 31 * result + (this.svc_serviceID.hashCode() << 1);
        result = 31 * result + (this.svc_ICNode.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_constructor_socket {

    public sids: BSet<SID>;
    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public in_sockets: BRelation<SOCKET, INTERCONNECTNODE>;
    public soc_to: BRelation<SOCKET, SID>;
    public soc_from: BRelation<SOCKET, SID>;
    public sockets: BSet<SOCKET>;

    constructor(sids : BSet<SID>, interconnectNodes : BSet<INTERCONNECTNODE>, in_sockets : BRelation<SOCKET, INTERCONNECTNODE>, soc_to : BRelation<SOCKET, SID>, soc_from : BRelation<SOCKET, SID>, sockets : BSet<SOCKET>) {
        this.sids = sids;
        this.interconnectNodes = interconnectNodes;
        this.in_sockets = in_sockets;
        this.soc_to = soc_to;
        this.soc_from = soc_from;
        this.sockets = sockets;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_constructor_socket = this;
        let o2: _ProjectionRead_constructor_socket = other as _ProjectionRead_constructor_socket;
        return o1.sids.equals(o2.sids) && o1.interconnectNodes.equals(o2.interconnectNodes) && o1.in_sockets.equals(o2.in_sockets) && o1.soc_to.equals(o2.soc_to) && o1.soc_from.equals(o2.soc_from) && o1.sockets.equals(o2.sockets);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.sids.hashCode() << 1);
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.in_sockets.hashCode() << 1);
        result = 31 * result + (this.soc_to.hashCode() << 1);
        result = 31 * result + (this.soc_from.hashCode() << 1);
        result = 31 * result + (this.sockets.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_constructor_socket {

    public sids: BSet<SID>;
    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public sockets: BSet<SOCKET>;

    constructor(sids : BSet<SID>, interconnectNodes : BSet<INTERCONNECTNODE>, sockets : BSet<SOCKET>) {
        this.sids = sids;
        this.interconnectNodes = interconnectNodes;
        this.sockets = sockets;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_constructor_socket = this;
        let o2: _ProjectionRead__tr_constructor_socket = other as _ProjectionRead__tr_constructor_socket;
        return o1.sids.equals(o2.sids) && o1.interconnectNodes.equals(o2.interconnectNodes) && o1.sockets.equals(o2.sockets);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.sids.hashCode() << 1);
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.sockets.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_constructor_socket {

    public in_sockets: BRelation<SOCKET, INTERCONNECTNODE>;
    public soc_to: BRelation<SOCKET, SID>;
    public soc_from: BRelation<SOCKET, SID>;
    public sockets: BSet<SOCKET>;

    constructor(in_sockets : BRelation<SOCKET, INTERCONNECTNODE>, soc_to : BRelation<SOCKET, SID>, soc_from : BRelation<SOCKET, SID>, sockets : BSet<SOCKET>) {
        this.in_sockets = in_sockets;
        this.soc_to = soc_to;
        this.soc_from = soc_from;
        this.sockets = sockets;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_constructor_socket = this;
        let o2: _ProjectionWrite_constructor_socket = other as _ProjectionWrite_constructor_socket;
        return o1.in_sockets.equals(o2.in_sockets) && o1.soc_to.equals(o2.soc_to) && o1.soc_from.equals(o2.soc_from) && o1.sockets.equals(o2.sockets);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.in_sockets.hashCode() << 1);
        result = 31 * result + (this.soc_to.hashCode() << 1);
        result = 31 * result + (this.soc_from.hashCode() << 1);
        result = 31 * result + (this.sockets.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_rm_register {

    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public services: BSet<SERVICE>;
    public resourceManagers: BSet<RESOURCEMANAGER>;

    constructor(interconnectNodes : BSet<INTERCONNECTNODE>, services : BSet<SERVICE>, resourceManagers : BSet<RESOURCEMANAGER>) {
        this.interconnectNodes = interconnectNodes;
        this.services = services;
        this.resourceManagers = resourceManagers;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_rm_register = this;
        let o2: _ProjectionRead_rm_register = other as _ProjectionRead_rm_register;
        return o1.interconnectNodes.equals(o2.interconnectNodes) && o1.services.equals(o2.services) && o1.resourceManagers.equals(o2.resourceManagers);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.services.hashCode() << 1);
        result = 31 * result + (this.resourceManagers.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_rm_register {

    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public services: BSet<SERVICE>;
    public resourceManagers: BSet<RESOURCEMANAGER>;

    constructor(interconnectNodes : BSet<INTERCONNECTNODE>, services : BSet<SERVICE>, resourceManagers : BSet<RESOURCEMANAGER>) {
        this.interconnectNodes = interconnectNodes;
        this.services = services;
        this.resourceManagers = resourceManagers;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_rm_register = this;
        let o2: _ProjectionRead__tr_rm_register = other as _ProjectionRead__tr_rm_register;
        return o1.interconnectNodes.equals(o2.interconnectNodes) && o1.services.equals(o2.services) && o1.resourceManagers.equals(o2.resourceManagers);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.services.hashCode() << 1);
        result = 31 * result + (this.resourceManagers.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_rm_register {


    constructor() {
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_rm_register = this;
        let o2: _ProjectionWrite_rm_register = other as _ProjectionWrite_rm_register;
        return true;
    }

    hashCode(): number {
        let result: number = 1;
        return result;
    }
}


class _ProjectionRead_rm_deregister {

    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public services: BSet<SERVICE>;
    public resourceManagers: BSet<RESOURCEMANAGER>;

    constructor(interconnectNodes : BSet<INTERCONNECTNODE>, services : BSet<SERVICE>, resourceManagers : BSet<RESOURCEMANAGER>) {
        this.interconnectNodes = interconnectNodes;
        this.services = services;
        this.resourceManagers = resourceManagers;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_rm_deregister = this;
        let o2: _ProjectionRead_rm_deregister = other as _ProjectionRead_rm_deregister;
        return o1.interconnectNodes.equals(o2.interconnectNodes) && o1.services.equals(o2.services) && o1.resourceManagers.equals(o2.resourceManagers);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.services.hashCode() << 1);
        result = 31 * result + (this.resourceManagers.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_rm_deregister {

    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public services: BSet<SERVICE>;
    public resourceManagers: BSet<RESOURCEMANAGER>;

    constructor(interconnectNodes : BSet<INTERCONNECTNODE>, services : BSet<SERVICE>, resourceManagers : BSet<RESOURCEMANAGER>) {
        this.interconnectNodes = interconnectNodes;
        this.services = services;
        this.resourceManagers = resourceManagers;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_rm_deregister = this;
        let o2: _ProjectionRead__tr_rm_deregister = other as _ProjectionRead__tr_rm_deregister;
        return o1.interconnectNodes.equals(o2.interconnectNodes) && o1.services.equals(o2.services) && o1.resourceManagers.equals(o2.resourceManagers);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.services.hashCode() << 1);
        result = 31 * result + (this.resourceManagers.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_rm_deregister {


    constructor() {
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_rm_deregister = this;
        let o2: _ProjectionWrite_rm_deregister = other as _ProjectionWrite_rm_deregister;
        return true;
    }

    hashCode(): number {
        let result: number = 1;
        return result;
    }
}


class _ProjectionRead_rm_getSid {

    public services: BSet<SERVICE>;
    public resourceManagers: BSet<RESOURCEMANAGER>;
    public rm_sids: BRelation<SERVICE, SID>;

    constructor(services : BSet<SERVICE>, resourceManagers : BSet<RESOURCEMANAGER>, rm_sids : BRelation<SERVICE, SID>) {
        this.services = services;
        this.resourceManagers = resourceManagers;
        this.rm_sids = rm_sids;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_rm_getSid = this;
        let o2: _ProjectionRead_rm_getSid = other as _ProjectionRead_rm_getSid;
        return o1.services.equals(o2.services) && o1.resourceManagers.equals(o2.resourceManagers) && o1.rm_sids.equals(o2.rm_sids);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.services.hashCode() << 1);
        result = 31 * result + (this.resourceManagers.hashCode() << 1);
        result = 31 * result + (this.rm_sids.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_rm_getSid {

    public services: BSet<SERVICE>;
    public resourceManagers: BSet<RESOURCEMANAGER>;
    public rm_sids: BRelation<SERVICE, SID>;

    constructor(services : BSet<SERVICE>, resourceManagers : BSet<RESOURCEMANAGER>, rm_sids : BRelation<SERVICE, SID>) {
        this.services = services;
        this.resourceManagers = resourceManagers;
        this.rm_sids = rm_sids;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_rm_getSid = this;
        let o2: _ProjectionRead__tr_rm_getSid = other as _ProjectionRead__tr_rm_getSid;
        return o1.services.equals(o2.services) && o1.resourceManagers.equals(o2.resourceManagers) && o1.rm_sids.equals(o2.rm_sids);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.services.hashCode() << 1);
        result = 31 * result + (this.resourceManagers.hashCode() << 1);
        result = 31 * result + (this.rm_sids.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_rm_getSid {


    constructor() {
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_rm_getSid = this;
        let o2: _ProjectionWrite_rm_getSid = other as _ProjectionWrite_rm_getSid;
        return true;
    }

    hashCode(): number {
        let result: number = 1;
        return result;
    }
}


class _ProjectionRead_rm_getSid_Not_Found {

    public services: BSet<SERVICE>;
    public resourceManagers: BSet<RESOURCEMANAGER>;

    constructor(services : BSet<SERVICE>, resourceManagers : BSet<RESOURCEMANAGER>) {
        this.services = services;
        this.resourceManagers = resourceManagers;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_rm_getSid_Not_Found = this;
        let o2: _ProjectionRead_rm_getSid_Not_Found = other as _ProjectionRead_rm_getSid_Not_Found;
        return o1.services.equals(o2.services) && o1.resourceManagers.equals(o2.resourceManagers);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.services.hashCode() << 1);
        result = 31 * result + (this.resourceManagers.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_rm_getSid_Not_Found {

    public services: BSet<SERVICE>;
    public resourceManagers: BSet<RESOURCEMANAGER>;

    constructor(services : BSet<SERVICE>, resourceManagers : BSet<RESOURCEMANAGER>) {
        this.services = services;
        this.resourceManagers = resourceManagers;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_rm_getSid_Not_Found = this;
        let o2: _ProjectionRead__tr_rm_getSid_Not_Found = other as _ProjectionRead__tr_rm_getSid_Not_Found;
        return o1.services.equals(o2.services) && o1.resourceManagers.equals(o2.resourceManagers);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.services.hashCode() << 1);
        result = 31 * result + (this.resourceManagers.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_rm_getSid_Not_Found {


    constructor() {
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_rm_getSid_Not_Found = this;
        let o2: _ProjectionWrite_rm_getSid_Not_Found = other as _ProjectionWrite_rm_getSid_Not_Found;
        return true;
    }

    hashCode(): number {
        let result: number = 1;
        return result;
    }
}


class _ProjectionRead_in_announceResourceManager {

    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public in_resourceManager: BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>;
    public resourceManagers: BSet<RESOURCEMANAGER>;

    constructor(interconnectNodes : BSet<INTERCONNECTNODE>, in_resourceManager : BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>, resourceManagers : BSet<RESOURCEMANAGER>) {
        this.interconnectNodes = interconnectNodes;
        this.in_resourceManager = in_resourceManager;
        this.resourceManagers = resourceManagers;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_in_announceResourceManager = this;
        let o2: _ProjectionRead_in_announceResourceManager = other as _ProjectionRead_in_announceResourceManager;
        return o1.interconnectNodes.equals(o2.interconnectNodes) && o1.in_resourceManager.equals(o2.in_resourceManager) && o1.resourceManagers.equals(o2.resourceManagers);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.in_resourceManager.hashCode() << 1);
        result = 31 * result + (this.resourceManagers.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_in_announceResourceManager {

    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public in_resourceManager: BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>;
    public resourceManagers: BSet<RESOURCEMANAGER>;

    constructor(interconnectNodes : BSet<INTERCONNECTNODE>, in_resourceManager : BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>, resourceManagers : BSet<RESOURCEMANAGER>) {
        this.interconnectNodes = interconnectNodes;
        this.in_resourceManager = in_resourceManager;
        this.resourceManagers = resourceManagers;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_in_announceResourceManager = this;
        let o2: _ProjectionRead__tr_in_announceResourceManager = other as _ProjectionRead__tr_in_announceResourceManager;
        return o1.interconnectNodes.equals(o2.interconnectNodes) && o1.in_resourceManager.equals(o2.in_resourceManager) && o1.resourceManagers.equals(o2.resourceManagers);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.in_resourceManager.hashCode() << 1);
        result = 31 * result + (this.resourceManagers.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_in_announceResourceManager {

    public in_resourceManager: BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>;

    constructor(in_resourceManager : BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>) {
        this.in_resourceManager = in_resourceManager;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_in_announceResourceManager = this;
        let o2: _ProjectionWrite_in_announceResourceManager = other as _ProjectionWrite_in_announceResourceManager;
        return o1.in_resourceManager.equals(o2.in_resourceManager);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.in_resourceManager.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_in_register_success {

    public sids: BSet<SID>;
    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public in_localServices: BRelation<SID, INTERCONNECTNODE>;
    public services: BSet<SERVICE>;

    constructor(sids : BSet<SID>, interconnectNodes : BSet<INTERCONNECTNODE>, in_localServices : BRelation<SID, INTERCONNECTNODE>, services : BSet<SERVICE>) {
        this.sids = sids;
        this.interconnectNodes = interconnectNodes;
        this.in_localServices = in_localServices;
        this.services = services;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_in_register_success = this;
        let o2: _ProjectionRead_in_register_success = other as _ProjectionRead_in_register_success;
        return o1.sids.equals(o2.sids) && o1.interconnectNodes.equals(o2.interconnectNodes) && o1.in_localServices.equals(o2.in_localServices) && o1.services.equals(o2.services);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.sids.hashCode() << 1);
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.in_localServices.hashCode() << 1);
        result = 31 * result + (this.services.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_in_register_success {

    public sids: BSet<SID>;
    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public in_localServices: BRelation<SID, INTERCONNECTNODE>;
    public services: BSet<SERVICE>;

    constructor(sids : BSet<SID>, interconnectNodes : BSet<INTERCONNECTNODE>, in_localServices : BRelation<SID, INTERCONNECTNODE>, services : BSet<SERVICE>) {
        this.sids = sids;
        this.interconnectNodes = interconnectNodes;
        this.in_localServices = in_localServices;
        this.services = services;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_in_register_success = this;
        let o2: _ProjectionRead__tr_in_register_success = other as _ProjectionRead__tr_in_register_success;
        return o1.sids.equals(o2.sids) && o1.interconnectNodes.equals(o2.interconnectNodes) && o1.in_localServices.equals(o2.in_localServices) && o1.services.equals(o2.services);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.sids.hashCode() << 1);
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.in_localServices.hashCode() << 1);
        result = 31 * result + (this.services.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_in_register_success {

    public sids: BSet<SID>;
    public in_localServices: BRelation<SID, INTERCONNECTNODE>;

    constructor(sids : BSet<SID>, in_localServices : BRelation<SID, INTERCONNECTNODE>) {
        this.sids = sids;
        this.in_localServices = in_localServices;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_in_register_success = this;
        let o2: _ProjectionWrite_in_register_success = other as _ProjectionWrite_in_register_success;
        return o1.sids.equals(o2.sids) && o1.in_localServices.equals(o2.in_localServices);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.sids.hashCode() << 1);
        result = 31 * result + (this.in_localServices.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_in_register_failed {

    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public services: BSet<SERVICE>;

    constructor(interconnectNodes : BSet<INTERCONNECTNODE>, services : BSet<SERVICE>) {
        this.interconnectNodes = interconnectNodes;
        this.services = services;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_in_register_failed = this;
        let o2: _ProjectionRead_in_register_failed = other as _ProjectionRead_in_register_failed;
        return o1.interconnectNodes.equals(o2.interconnectNodes) && o1.services.equals(o2.services);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.services.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_in_register_failed {

    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public services: BSet<SERVICE>;

    constructor(interconnectNodes : BSet<INTERCONNECTNODE>, services : BSet<SERVICE>) {
        this.interconnectNodes = interconnectNodes;
        this.services = services;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_in_register_failed = this;
        let o2: _ProjectionRead__tr_in_register_failed = other as _ProjectionRead__tr_in_register_failed;
        return o1.interconnectNodes.equals(o2.interconnectNodes) && o1.services.equals(o2.services);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.services.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_in_register_failed {


    constructor() {
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_in_register_failed = this;
        let o2: _ProjectionWrite_in_register_failed = other as _ProjectionWrite_in_register_failed;
        return true;
    }

    hashCode(): number {
        let result: number = 1;
        return result;
    }
}


class _ProjectionRead_in_requestTargetSocket_Granted {

    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public sids: BSet<SID>;
    public in_sockets: BRelation<SOCKET, INTERCONNECTNODE>;
    public soc_to: BRelation<SOCKET, SID>;
    public soc_from: BRelation<SOCKET, SID>;
    public sockets: BSet<SOCKET>;

    constructor(interconnectNodes : BSet<INTERCONNECTNODE>, sids : BSet<SID>, in_sockets : BRelation<SOCKET, INTERCONNECTNODE>, soc_to : BRelation<SOCKET, SID>, soc_from : BRelation<SOCKET, SID>, sockets : BSet<SOCKET>) {
        this.interconnectNodes = interconnectNodes;
        this.sids = sids;
        this.in_sockets = in_sockets;
        this.soc_to = soc_to;
        this.soc_from = soc_from;
        this.sockets = sockets;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_in_requestTargetSocket_Granted = this;
        let o2: _ProjectionRead_in_requestTargetSocket_Granted = other as _ProjectionRead_in_requestTargetSocket_Granted;
        return o1.interconnectNodes.equals(o2.interconnectNodes) && o1.sids.equals(o2.sids) && o1.in_sockets.equals(o2.in_sockets) && o1.soc_to.equals(o2.soc_to) && o1.soc_from.equals(o2.soc_from) && o1.sockets.equals(o2.sockets);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.sids.hashCode() << 1);
        result = 31 * result + (this.in_sockets.hashCode() << 1);
        result = 31 * result + (this.soc_to.hashCode() << 1);
        result = 31 * result + (this.soc_from.hashCode() << 1);
        result = 31 * result + (this.sockets.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_in_requestTargetSocket_Granted {

    public sids: BSet<SID>;
    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public in_sockets: BRelation<SOCKET, INTERCONNECTNODE>;
    public sockets: BSet<SOCKET>;

    constructor(sids : BSet<SID>, interconnectNodes : BSet<INTERCONNECTNODE>, in_sockets : BRelation<SOCKET, INTERCONNECTNODE>, sockets : BSet<SOCKET>) {
        this.sids = sids;
        this.interconnectNodes = interconnectNodes;
        this.in_sockets = in_sockets;
        this.sockets = sockets;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_in_requestTargetSocket_Granted = this;
        let o2: _ProjectionRead__tr_in_requestTargetSocket_Granted = other as _ProjectionRead__tr_in_requestTargetSocket_Granted;
        return o1.sids.equals(o2.sids) && o1.interconnectNodes.equals(o2.interconnectNodes) && o1.in_sockets.equals(o2.in_sockets) && o1.sockets.equals(o2.sockets);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.sids.hashCode() << 1);
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.in_sockets.hashCode() << 1);
        result = 31 * result + (this.sockets.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_in_requestTargetSocket_Granted {

    public in_sockets: BRelation<SOCKET, INTERCONNECTNODE>;
    public soc_to: BRelation<SOCKET, SID>;
    public soc_from: BRelation<SOCKET, SID>;
    public sockets: BSet<SOCKET>;

    constructor(in_sockets : BRelation<SOCKET, INTERCONNECTNODE>, soc_to : BRelation<SOCKET, SID>, soc_from : BRelation<SOCKET, SID>, sockets : BSet<SOCKET>) {
        this.in_sockets = in_sockets;
        this.soc_to = soc_to;
        this.soc_from = soc_from;
        this.sockets = sockets;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_in_requestTargetSocket_Granted = this;
        let o2: _ProjectionWrite_in_requestTargetSocket_Granted = other as _ProjectionWrite_in_requestTargetSocket_Granted;
        return o1.in_sockets.equals(o2.in_sockets) && o1.soc_to.equals(o2.soc_to) && o1.soc_from.equals(o2.soc_from) && o1.sockets.equals(o2.sockets);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.in_sockets.hashCode() << 1);
        result = 31 * result + (this.soc_to.hashCode() << 1);
        result = 31 * result + (this.soc_from.hashCode() << 1);
        result = 31 * result + (this.sockets.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_in_requestTargetSocket_NotGranted {

    public sids: BSet<SID>;
    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public in_sockets: BRelation<SOCKET, INTERCONNECTNODE>;
    public sockets: BSet<SOCKET>;

    constructor(sids : BSet<SID>, interconnectNodes : BSet<INTERCONNECTNODE>, in_sockets : BRelation<SOCKET, INTERCONNECTNODE>, sockets : BSet<SOCKET>) {
        this.sids = sids;
        this.interconnectNodes = interconnectNodes;
        this.in_sockets = in_sockets;
        this.sockets = sockets;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_in_requestTargetSocket_NotGranted = this;
        let o2: _ProjectionRead_in_requestTargetSocket_NotGranted = other as _ProjectionRead_in_requestTargetSocket_NotGranted;
        return o1.sids.equals(o2.sids) && o1.interconnectNodes.equals(o2.interconnectNodes) && o1.in_sockets.equals(o2.in_sockets) && o1.sockets.equals(o2.sockets);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.sids.hashCode() << 1);
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.in_sockets.hashCode() << 1);
        result = 31 * result + (this.sockets.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_in_requestTargetSocket_NotGranted {

    public sids: BSet<SID>;
    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public in_sockets: BRelation<SOCKET, INTERCONNECTNODE>;
    public sockets: BSet<SOCKET>;

    constructor(sids : BSet<SID>, interconnectNodes : BSet<INTERCONNECTNODE>, in_sockets : BRelation<SOCKET, INTERCONNECTNODE>, sockets : BSet<SOCKET>) {
        this.sids = sids;
        this.interconnectNodes = interconnectNodes;
        this.in_sockets = in_sockets;
        this.sockets = sockets;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_in_requestTargetSocket_NotGranted = this;
        let o2: _ProjectionRead__tr_in_requestTargetSocket_NotGranted = other as _ProjectionRead__tr_in_requestTargetSocket_NotGranted;
        return o1.sids.equals(o2.sids) && o1.interconnectNodes.equals(o2.interconnectNodes) && o1.in_sockets.equals(o2.in_sockets) && o1.sockets.equals(o2.sockets);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.sids.hashCode() << 1);
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.in_sockets.hashCode() << 1);
        result = 31 * result + (this.sockets.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_in_requestTargetSocket_NotGranted {


    constructor() {
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_in_requestTargetSocket_NotGranted = this;
        let o2: _ProjectionWrite_in_requestTargetSocket_NotGranted = other as _ProjectionWrite_in_requestTargetSocket_NotGranted;
        return true;
    }

    hashCode(): number {
        let result: number = 1;
        return result;
    }
}


class _ProjectionRead_svc_register {

    public svc_registered: BRelation<SERVICE, BBoolean>;
    public services: BSet<SERVICE>;

    constructor(svc_registered : BRelation<SERVICE, BBoolean>, services : BSet<SERVICE>) {
        this.svc_registered = svc_registered;
        this.services = services;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_svc_register = this;
        let o2: _ProjectionRead_svc_register = other as _ProjectionRead_svc_register;
        return o1.svc_registered.equals(o2.svc_registered) && o1.services.equals(o2.services);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.svc_registered.hashCode() << 1);
        result = 31 * result + (this.services.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_svc_register {

    public svc_registered: BRelation<SERVICE, BBoolean>;
    public services: BSet<SERVICE>;

    constructor(svc_registered : BRelation<SERVICE, BBoolean>, services : BSet<SERVICE>) {
        this.svc_registered = svc_registered;
        this.services = services;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_svc_register = this;
        let o2: _ProjectionRead__tr_svc_register = other as _ProjectionRead__tr_svc_register;
        return o1.svc_registered.equals(o2.svc_registered) && o1.services.equals(o2.services);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.svc_registered.hashCode() << 1);
        result = 31 * result + (this.services.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_svc_register {

    public svc_registered: BRelation<SERVICE, BBoolean>;

    constructor(svc_registered : BRelation<SERVICE, BBoolean>) {
        this.svc_registered = svc_registered;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_svc_register = this;
        let o2: _ProjectionWrite_svc_register = other as _ProjectionWrite_svc_register;
        return o1.svc_registered.equals(o2.svc_registered);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.svc_registered.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_1 {

    public interconnectNodes: BSet<INTERCONNECTNODE>;

    constructor(interconnectNodes : BSet<INTERCONNECTNODE>) {
        this.interconnectNodes = interconnectNodes;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_1 = this;
        let o2: _ProjectionRead__check_inv_1 = other as _ProjectionRead__check_inv_1;
        return o1.interconnectNodes.equals(o2.interconnectNodes);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_2 {

    public sockets: BSet<SOCKET>;

    constructor(sockets : BSet<SOCKET>) {
        this.sockets = sockets;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_2 = this;
        let o2: _ProjectionRead__check_inv_2 = other as _ProjectionRead__check_inv_2;
        return o1.sockets.equals(o2.sockets);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.sockets.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_3 {

    public services: BSet<SERVICE>;

    constructor(services : BSet<SERVICE>) {
        this.services = services;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_3 = this;
        let o2: _ProjectionRead__check_inv_3 = other as _ProjectionRead__check_inv_3;
        return o1.services.equals(o2.services);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.services.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_4 {

    public resourceManagers: BSet<RESOURCEMANAGER>;

    constructor(resourceManagers : BSet<RESOURCEMANAGER>) {
        this.resourceManagers = resourceManagers;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_4 = this;
        let o2: _ProjectionRead__check_inv_4 = other as _ProjectionRead__check_inv_4;
        return o1.resourceManagers.equals(o2.resourceManagers);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.resourceManagers.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_5 {

    public sids: BSet<SID>;

    constructor(sids : BSet<SID>) {
        this.sids = sids;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_5 = this;
        let o2: _ProjectionRead__check_inv_5 = other as _ProjectionRead__check_inv_5;
        return o1.sids.equals(o2.sids);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.sids.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_6 {

    public rm_services: BRelation<RESOURCEMANAGER, BSet<SERVICE>>;
    public services: BSet<SERVICE>;
    public resourceManagers: BSet<RESOURCEMANAGER>;

    constructor(rm_services : BRelation<RESOURCEMANAGER, BSet<SERVICE>>, services : BSet<SERVICE>, resourceManagers : BSet<RESOURCEMANAGER>) {
        this.rm_services = rm_services;
        this.services = services;
        this.resourceManagers = resourceManagers;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_6 = this;
        let o2: _ProjectionRead__check_inv_6 = other as _ProjectionRead__check_inv_6;
        return o1.rm_services.equals(o2.rm_services) && o1.services.equals(o2.services) && o1.resourceManagers.equals(o2.resourceManagers);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.rm_services.hashCode() << 1);
        result = 31 * result + (this.services.hashCode() << 1);
        result = 31 * result + (this.resourceManagers.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_7 {

    public rm_services: BRelation<RESOURCEMANAGER, BSet<SERVICE>>;

    constructor(rm_services : BRelation<RESOURCEMANAGER, BSet<SERVICE>>) {
        this.rm_services = rm_services;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_7 = this;
        let o2: _ProjectionRead__check_inv_7 = other as _ProjectionRead__check_inv_7;
        return o1.rm_services.equals(o2.rm_services);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.rm_services.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_8 {

    public sids: BSet<SID>;
    public services: BSet<SERVICE>;
    public rm_sids: BRelation<SERVICE, SID>;

    constructor(sids : BSet<SID>, services : BSet<SERVICE>, rm_sids : BRelation<SERVICE, SID>) {
        this.sids = sids;
        this.services = services;
        this.rm_sids = rm_sids;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_8 = this;
        let o2: _ProjectionRead__check_inv_8 = other as _ProjectionRead__check_inv_8;
        return o1.sids.equals(o2.sids) && o1.services.equals(o2.services) && o1.rm_sids.equals(o2.rm_sids);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.sids.hashCode() << 1);
        result = 31 * result + (this.services.hashCode() << 1);
        result = 31 * result + (this.rm_sids.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_9 {

    public sids: BSet<SID>;
    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public in_localServices: BRelation<SID, INTERCONNECTNODE>;

    constructor(sids : BSet<SID>, interconnectNodes : BSet<INTERCONNECTNODE>, in_localServices : BRelation<SID, INTERCONNECTNODE>) {
        this.sids = sids;
        this.interconnectNodes = interconnectNodes;
        this.in_localServices = in_localServices;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_9 = this;
        let o2: _ProjectionRead__check_inv_9 = other as _ProjectionRead__check_inv_9;
        return o1.sids.equals(o2.sids) && o1.interconnectNodes.equals(o2.interconnectNodes) && o1.in_localServices.equals(o2.in_localServices);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.sids.hashCode() << 1);
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.in_localServices.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_10 {

    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public in_sockets: BRelation<SOCKET, INTERCONNECTNODE>;
    public sockets: BSet<SOCKET>;

    constructor(interconnectNodes : BSet<INTERCONNECTNODE>, in_sockets : BRelation<SOCKET, INTERCONNECTNODE>, sockets : BSet<SOCKET>) {
        this.interconnectNodes = interconnectNodes;
        this.in_sockets = in_sockets;
        this.sockets = sockets;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_10 = this;
        let o2: _ProjectionRead__check_inv_10 = other as _ProjectionRead__check_inv_10;
        return o1.interconnectNodes.equals(o2.interconnectNodes) && o1.in_sockets.equals(o2.in_sockets) && o1.sockets.equals(o2.sockets);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.in_sockets.hashCode() << 1);
        result = 31 * result + (this.sockets.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_11 {

    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public in_resourceManager: BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>;
    public resourceManagers: BSet<RESOURCEMANAGER>;

    constructor(interconnectNodes : BSet<INTERCONNECTNODE>, in_resourceManager : BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>, resourceManagers : BSet<RESOURCEMANAGER>) {
        this.interconnectNodes = interconnectNodes;
        this.in_resourceManager = in_resourceManager;
        this.resourceManagers = resourceManagers;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_11 = this;
        let o2: _ProjectionRead__check_inv_11 = other as _ProjectionRead__check_inv_11;
        return o1.interconnectNodes.equals(o2.interconnectNodes) && o1.in_resourceManager.equals(o2.in_resourceManager) && o1.resourceManagers.equals(o2.resourceManagers);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.in_resourceManager.hashCode() << 1);
        result = 31 * result + (this.resourceManagers.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_12 {

    public sids: BSet<SID>;
    public soc_to: BRelation<SOCKET, SID>;
    public sockets: BSet<SOCKET>;

    constructor(sids : BSet<SID>, soc_to : BRelation<SOCKET, SID>, sockets : BSet<SOCKET>) {
        this.sids = sids;
        this.soc_to = soc_to;
        this.sockets = sockets;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_12 = this;
        let o2: _ProjectionRead__check_inv_12 = other as _ProjectionRead__check_inv_12;
        return o1.sids.equals(o2.sids) && o1.soc_to.equals(o2.soc_to) && o1.sockets.equals(o2.sockets);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.sids.hashCode() << 1);
        result = 31 * result + (this.soc_to.hashCode() << 1);
        result = 31 * result + (this.sockets.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_13 {

    public sids: BSet<SID>;
    public soc_from: BRelation<SOCKET, SID>;
    public sockets: BSet<SOCKET>;

    constructor(sids : BSet<SID>, soc_from : BRelation<SOCKET, SID>, sockets : BSet<SOCKET>) {
        this.sids = sids;
        this.soc_from = soc_from;
        this.sockets = sockets;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_13 = this;
        let o2: _ProjectionRead__check_inv_13 = other as _ProjectionRead__check_inv_13;
        return o1.sids.equals(o2.sids) && o1.soc_from.equals(o2.soc_from) && o1.sockets.equals(o2.sockets);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.sids.hashCode() << 1);
        result = 31 * result + (this.soc_from.hashCode() << 1);
        result = 31 * result + (this.sockets.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_14 {

    public sids: BSet<SID>;
    public services: BSet<SERVICE>;
    public svc_serviceID: BRelation<SERVICE, SID>;

    constructor(sids : BSet<SID>, services : BSet<SERVICE>, svc_serviceID : BRelation<SERVICE, SID>) {
        this.sids = sids;
        this.services = services;
        this.svc_serviceID = svc_serviceID;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_14 = this;
        let o2: _ProjectionRead__check_inv_14 = other as _ProjectionRead__check_inv_14;
        return o1.sids.equals(o2.sids) && o1.services.equals(o2.services) && o1.svc_serviceID.equals(o2.svc_serviceID);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.sids.hashCode() << 1);
        result = 31 * result + (this.services.hashCode() << 1);
        result = 31 * result + (this.svc_serviceID.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_15 {

    public svc_sockets: BRelation<SERVICE, BSet<SOCKET>>;
    public services: BSet<SERVICE>;
    public sockets: BSet<SOCKET>;

    constructor(svc_sockets : BRelation<SERVICE, BSet<SOCKET>>, services : BSet<SERVICE>, sockets : BSet<SOCKET>) {
        this.svc_sockets = svc_sockets;
        this.services = services;
        this.sockets = sockets;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_15 = this;
        let o2: _ProjectionRead__check_inv_15 = other as _ProjectionRead__check_inv_15;
        return o1.svc_sockets.equals(o2.svc_sockets) && o1.services.equals(o2.services) && o1.sockets.equals(o2.sockets);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.svc_sockets.hashCode() << 1);
        result = 31 * result + (this.services.hashCode() << 1);
        result = 31 * result + (this.sockets.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_16 {

    public interconnectNodes: BSet<INTERCONNECTNODE>;
    public services: BSet<SERVICE>;
    public svc_ICNode: BRelation<SERVICE, INTERCONNECTNODE>;

    constructor(interconnectNodes : BSet<INTERCONNECTNODE>, services : BSet<SERVICE>, svc_ICNode : BRelation<SERVICE, INTERCONNECTNODE>) {
        this.interconnectNodes = interconnectNodes;
        this.services = services;
        this.svc_ICNode = svc_ICNode;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_16 = this;
        let o2: _ProjectionRead__check_inv_16 = other as _ProjectionRead__check_inv_16;
        return o1.interconnectNodes.equals(o2.interconnectNodes) && o1.services.equals(o2.services) && o1.svc_ICNode.equals(o2.svc_ICNode);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.interconnectNodes.hashCode() << 1);
        result = 31 * result + (this.services.hashCode() << 1);
        result = 31 * result + (this.svc_ICNode.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_17 {

    public svc_registered: BRelation<SERVICE, BBoolean>;
    public services: BSet<SERVICE>;

    constructor(svc_registered : BRelation<SERVICE, BBoolean>, services : BSet<SERVICE>) {
        this.svc_registered = svc_registered;
        this.services = services;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_17 = this;
        let o2: _ProjectionRead__check_inv_17 = other as _ProjectionRead__check_inv_17;
        return o1.svc_registered.equals(o2.svc_registered) && o1.services.equals(o2.services);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.svc_registered.hashCode() << 1);
        result = 31 * result + (this.services.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_18 {

    public resourceManagers: BSet<RESOURCEMANAGER>;

    constructor(resourceManagers : BSet<RESOURCEMANAGER>) {
        this.resourceManagers = resourceManagers;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_18 = this;
        let o2: _ProjectionRead__check_inv_18 = other as _ProjectionRead__check_inv_18;
        return o1.resourceManagers.equals(o2.resourceManagers);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.resourceManagers.hashCode() << 1);
        return result;
    }
}


export enum Type {
    BFS,
    DFS,
    MIXED
}

export default class nota_v2 {

    parent: nota_v2;
    stateAccessedVia: string;



    private static _INTERCONNECTNODE: BSet<INTERCONNECTNODE> = new BSet<INTERCONNECTNODE>(new INTERCONNECTNODE(enum_INTERCONNECTNODE.node1), new INTERCONNECTNODE(enum_INTERCONNECTNODE.node2));
    private static _SOCKET: BSet<SOCKET> = new BSet<SOCKET>(new SOCKET(enum_SOCKET.socket1), new SOCKET(enum_SOCKET.socket2));
    private static _SERVICE: BSet<SERVICE> = new BSet<SERVICE>(new SERVICE(enum_SERVICE.service1), new SERVICE(enum_SERVICE.service2));
    private static _RESOURCEMANAGER: BSet<RESOURCEMANAGER> = new BSet<RESOURCEMANAGER>(new RESOURCEMANAGER(enum_RESOURCEMANAGER.resource1), new RESOURCEMANAGER(enum_RESOURCEMANAGER.resource2));
    private static _SID: BSet<SID> = new BSet<SID>(new SID(enum_SID.SID1), new SID(enum_SID.SID2));
    private static _RM_ERROR_CODES: BSet<RM_ERROR_CODES> = new BSet<RM_ERROR_CODES>(new RM_ERROR_CODES(enum_RM_ERROR_CODES.RM_SERVICE_FOUND), new RM_ERROR_CODES(enum_RM_ERROR_CODES.RM_SERVICE_NOT_FOUND));
    private static _IN_ERROR_CODES: BSet<IN_ERROR_CODES> = new BSet<IN_ERROR_CODES>(new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_REGISTRATION_OK), new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_REGISTRATION_FAILED), new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_DEREGISTRATION_OK), new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_DEREGISTRATION_FAILED), new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_NO_SOCKET_CONNECTION), new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_SOCKET_CONNECTION_OK), new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_NO_AVAILABLE_SERVICE), new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_SERVICE_AVAILABLE), new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_TARGET_SOCKET_GRANTED), new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_TARGET_SOCKET_NOT_GRANTED));

    private interconnectNodes: BSet<INTERCONNECTNODE>;
    private sockets: BSet<SOCKET>;
    private services: BSet<SERVICE>;
    private resourceManagers: BSet<RESOURCEMANAGER>;
    private sids: BSet<SID>;
    private rm_services: BRelation<RESOURCEMANAGER, BSet<SERVICE>>;
    private rm_sids: BRelation<SERVICE, SID>;
    private in_localServices: BRelation<SID, INTERCONNECTNODE>;
    private in_sockets: BRelation<SOCKET, INTERCONNECTNODE>;
    private in_resourceManager: BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>;
    private soc_to: BRelation<SOCKET, SID>;
    private soc_from: BRelation<SOCKET, SID>;
    private svc_serviceID: BRelation<SERVICE, SID>;
    private svc_sockets: BRelation<SERVICE, BSet<SOCKET>>;
    private svc_ICNode: BRelation<SERVICE, INTERCONNECTNODE>;
    private svc_registered: BRelation<SERVICE, BBoolean>;

    constructor(copy? : nota_v2) {
        if(copy) {
            this.interconnectNodes = copy.interconnectNodes;
            this.sockets = copy.sockets;
            this.services = copy.services;
            this.resourceManagers = copy.resourceManagers;
            this.sids = copy.sids;
            this.rm_services = copy.rm_services;
            this.rm_sids = copy.rm_sids;
            this.in_localServices = copy.in_localServices;
            this.in_sockets = copy.in_sockets;
            this.in_resourceManager = copy.in_resourceManager;
            this.soc_to = copy.soc_to;
            this.soc_from = copy.soc_from;
            this.svc_serviceID = copy.svc_serviceID;
            this.svc_sockets = copy.svc_sockets;
            this.svc_ICNode = copy.svc_ICNode;
            this.svc_registered = copy.svc_registered;
        } else {
            this.interconnectNodes = new BSet<INTERCONNECTNODE>();
            this.sockets = new BSet<SOCKET>();
            this.services = new BSet<SERVICE>();
            this.resourceManagers = new BSet<RESOURCEMANAGER>();
            this.sids = new BSet<SID>();
            this.rm_services = new BRelation<RESOURCEMANAGER, BSet<SERVICE>>();
            this.rm_sids = new BRelation<SERVICE, SID>();
            this.in_localServices = new BRelation<SID, INTERCONNECTNODE>();
            this.in_sockets = new BRelation<SOCKET, INTERCONNECTNODE>();
            this.in_resourceManager = new BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>();
            this.soc_to = new BRelation<SOCKET, SID>();
            this.soc_from = new BRelation<SOCKET, SID>();
            this.svc_serviceID = new BRelation<SERVICE, SID>();
            this.svc_sockets = new BRelation<SERVICE, BSet<SOCKET>>();
            this.svc_ICNode = new BRelation<SERVICE, INTERCONNECTNODE>();
            this.svc_registered = new BRelation<SERVICE, BBoolean>();
        }
    }



    constructor_interconnectNode(newic: INTERCONNECTNODE): INTERCONNECTNODE {
        let oid: INTERCONNECTNODE = null;
        let _ld_interconnectNodes: BSet<INTERCONNECTNODE> = this.interconnectNodes;

        this.interconnectNodes = _ld_interconnectNodes.union(new BSet<INTERCONNECTNODE>(newic));
        this.in_resourceManager = this.in_resourceManager.override(new BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>(new BTuple<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>(newic,new BSet<RESOURCEMANAGER>())));
        oid = newic;

        return oid;
    }

    constructor_resourceManager(newrm: RESOURCEMANAGER): RESOURCEMANAGER {
        let oid: RESOURCEMANAGER = null;
        let _ld_resourceManagers: BSet<RESOURCEMANAGER> = this.resourceManagers;
        this.resourceManagers = _ld_resourceManagers.union(new BSet<RESOURCEMANAGER>(newrm));
        this.rm_services = this.rm_services.override(new BRelation<RESOURCEMANAGER, BSet<SERVICE>>(new BTuple<RESOURCEMANAGER, BSet<SERVICE>>(newrm,new BSet<SERVICE>())));
        oid = newrm;

        return oid;
    }

    constructor_service(ii: INTERCONNECTNODE, newsvc: SERVICE): SERVICE {
        let oid: SERVICE = null;
        let _ld_services: BSet<SERVICE> = this.services;
        this.services = _ld_services.union(new BSet<SERVICE>(newsvc));
        this.svc_registered = this.svc_registered.override(new BRelation<SERVICE, BBoolean>(new BTuple<SERVICE, BBoolean>(newsvc,new BBoolean(false))));
        this.svc_sockets = this.svc_sockets.override(new BRelation<SERVICE, BSet<SOCKET>>(new BTuple<SERVICE, BSet<SOCKET>>(newsvc,new BSet<SOCKET>())));
        this.svc_ICNode = this.svc_ICNode.override(new BRelation<SERVICE, INTERCONNECTNODE>(new BTuple<SERVICE, INTERCONNECTNODE>(newsvc,ii)));
        this.svc_serviceID = new BRelation<SERVICE, SID>();
        oid = newsvc;

        return oid;
    }

    constructor_socket(ii: INTERCONNECTNODE, srcsid: SID, targsid: SID, newsoc: SOCKET): SOCKET {
        let oid: SOCKET = null;
        let _ld_sockets: BSet<SOCKET> = this.sockets;
        this.sockets = _ld_sockets.union(new BSet<SOCKET>(newsoc));
        oid = newsoc;
        this.in_sockets = this.in_sockets.override(new BRelation<SOCKET, INTERCONNECTNODE>(new BTuple<SOCKET, INTERCONNECTNODE>(newsoc,ii)));
        this.soc_to = this.soc_to.override(new BRelation<SOCKET, SID>(new BTuple<SOCKET, SID>(newsoc,srcsid)));
        this.soc_from = this.soc_from.override(new BRelation<SOCKET, SID>(new BTuple<SOCKET, SID>(newsoc,targsid)));

        return oid;
    }

    rm_register(self: RESOURCEMANAGER, ss: SERVICE, ii: INTERCONNECTNODE): void {
    }

    rm_deregister(self: RESOURCEMANAGER, ss: SERVICE, ii: INTERCONNECTNODE): void {
    }

    rm_getSid(self: RESOURCEMANAGER, ss: SERVICE): _Struct1 {
        let sid: BSet<SID> = null;
        let err: RM_ERROR_CODES = null;
        err = new RM_ERROR_CODES(enum_RM_ERROR_CODES.RM_SERVICE_FOUND);
        sid = new BSet<SID>(this.rm_sids.functionCall(ss));

        return new _Struct1(sid, err);
    }

    rm_getSid_Not_Found(self: RESOURCEMANAGER, ss: SERVICE): _Struct1 {
        let sid: BSet<SID> = null;
        let err: RM_ERROR_CODES = null;
        sid = nota_v2._SID.difference(nota_v2._SID);
        err = new RM_ERROR_CODES(enum_RM_ERROR_CODES.RM_SERVICE_NOT_FOUND);

        return new _Struct1(sid, err);
    }

    in_announceResourceManager(self: INTERCONNECTNODE, rm: RESOURCEMANAGER): void {
        this.in_resourceManager = this.in_resourceManager.override(new BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>(new BTuple<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>(self,this.in_resourceManager.functionCall(self).union(new BSet<RESOURCEMANAGER>(rm)))));

    }

    in_register_success(self: INTERCONNECTNODE, ss: SERVICE, si: SID): _Struct3 {
        let sid: BSet<SID> = null;
        let err: IN_ERROR_CODES = null;
        let _ld_in_localServices: BRelation<SID, INTERCONNECTNODE> = this.in_localServices;
        let _ld_sids: BSet<SID> = this.sids;
        this.sids = _ld_sids.union(new BSet<SID>(si));
        this.in_localServices = _ld_in_localServices.union(new BRelation<SID, INTERCONNECTNODE>(new BTuple(si, self)));
        err = new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_REGISTRATION_OK);
        sid = new BSet<SID>(si);

        return new _Struct3(sid, err);
    }

    in_register_failed(self: INTERCONNECTNODE, ss: SERVICE): _Struct3 {
        let sid: BSet<SID> = null;
        let err: IN_ERROR_CODES = null;
        sid = nota_v2._SID.difference(nota_v2._SID);
        err = new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_REGISTRATION_FAILED);

        return new _Struct3(sid, err);
    }

    in_requestTargetSocket_Granted(self: INTERCONNECTNODE, ii: INTERCONNECTNODE, srcsoc: SOCKET, srcsid: SID, targsid: SID, newsoc: SOCKET): _Struct5 {
        let soc: BSet<SOCKET> = null;
        let err: IN_ERROR_CODES = null;
        let _ld_in_sockets: BRelation<SOCKET, INTERCONNECTNODE> = this.in_sockets;
        let _ld_sockets: BSet<SOCKET> = this.sockets;
        this.sockets = _ld_sockets.union(new BSet<SOCKET>(newsoc));
        soc = new BSet<SOCKET>(newsoc);
        err = new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_TARGET_SOCKET_GRANTED);
        this.in_sockets = _ld_in_sockets.union(new BRelation<SOCKET, INTERCONNECTNODE>(new BTuple(newsoc, self)));
        this.soc_to = this.soc_to.override(new BRelation<SOCKET, SID>(new BTuple<SOCKET, SID>(newsoc,srcsid)));
        this.soc_from = this.soc_from.override(new BRelation<SOCKET, SID>(new BTuple<SOCKET, SID>(newsoc,targsid)));

        return new _Struct5(soc, err);
    }

    in_requestTargetSocket_NotGranted(self: INTERCONNECTNODE, ii: INTERCONNECTNODE, srcsoc: SOCKET, srcsid: SID, targsid: SID): _Struct5 {
        let soc: BSet<SOCKET> = null;
        let err: IN_ERROR_CODES = null;
        soc = nota_v2._SOCKET.difference(nota_v2._SOCKET);
        err = new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_TARGET_SOCKET_NOT_GRANTED);

        return new _Struct5(soc, err);
    }

    svc_register(self: SERVICE): void {
        this.svc_registered = this.svc_registered.override(new BRelation<SERVICE, BBoolean>(new BTuple<SERVICE, BBoolean>(self,new BBoolean(true))));

    }

    _get_interconnectNodes(): BSet<INTERCONNECTNODE> {
        return this.interconnectNodes;
    }

    _get_sockets(): BSet<SOCKET> {
        return this.sockets;
    }

    _get_services(): BSet<SERVICE> {
        return this.services;
    }

    _get_resourceManagers(): BSet<RESOURCEMANAGER> {
        return this.resourceManagers;
    }

    _get_sids(): BSet<SID> {
        return this.sids;
    }

    _get_rm_services(): BRelation<RESOURCEMANAGER, BSet<SERVICE>> {
        return this.rm_services;
    }

    _get_rm_sids(): BRelation<SERVICE, SID> {
        return this.rm_sids;
    }

    _get_in_localServices(): BRelation<SID, INTERCONNECTNODE> {
        return this.in_localServices;
    }

    _get_in_sockets(): BRelation<SOCKET, INTERCONNECTNODE> {
        return this.in_sockets;
    }

    _get_in_resourceManager(): BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>> {
        return this.in_resourceManager;
    }

    _get_soc_to(): BRelation<SOCKET, SID> {
        return this.soc_to;
    }

    _get_soc_from(): BRelation<SOCKET, SID> {
        return this.soc_from;
    }

    _get_svc_serviceID(): BRelation<SERVICE, SID> {
        return this.svc_serviceID;
    }

    _get_svc_sockets(): BRelation<SERVICE, BSet<SOCKET>> {
        return this.svc_sockets;
    }

    _get_svc_ICNode(): BRelation<SERVICE, INTERCONNECTNODE> {
        return this.svc_ICNode;
    }

    _get_svc_registered(): BRelation<SERVICE, BBoolean> {
        return this.svc_registered;
    }

    _get__INTERCONNECTNODE(): BSet<INTERCONNECTNODE> {
        return nota_v2._INTERCONNECTNODE;
    }

    _get__SOCKET(): BSet<SOCKET> {
        return nota_v2._SOCKET;
    }

    _get__SERVICE(): BSet<SERVICE> {
        return nota_v2._SERVICE;
    }

    _get__RESOURCEMANAGER(): BSet<RESOURCEMANAGER> {
        return nota_v2._RESOURCEMANAGER;
    }

    _get__SID(): BSet<SID> {
        return nota_v2._SID;
    }

    _get__RM_ERROR_CODES(): BSet<RM_ERROR_CODES> {
        return nota_v2._RM_ERROR_CODES;
    }

    _get__IN_ERROR_CODES(): BSet<IN_ERROR_CODES> {
        return nota_v2._IN_ERROR_CODES;
    }

    _tr_constructor_interconnectNode(): BSet<INTERCONNECTNODE> {
        let _ic_set_0: BSet<INTERCONNECTNODE> = new BSet<INTERCONNECTNODE>();
        for(let _ic_newic_1 of nota_v2._INTERCONNECTNODE.difference(this.interconnectNodes)) {
            _ic_set_0 = _ic_set_0.union(new BSet<INTERCONNECTNODE>(_ic_newic_1));

        }
        return _ic_set_0;
    }

    _tr_constructor_resourceManager(): BSet<RESOURCEMANAGER> {
        let _ic_set_1: BSet<RESOURCEMANAGER> = new BSet<RESOURCEMANAGER>();
        for(let _ic_newrm_1 of nota_v2._RESOURCEMANAGER.difference(this.resourceManagers)) {
            if((new BBoolean(this.rm_services.domain().notElementOf(_ic_newrm_1).booleanValue() && this.resourceManagers.equal(new BSet<RESOURCEMANAGER>()).booleanValue())).booleanValue()) {
                _ic_set_1 = _ic_set_1.union(new BSet<RESOURCEMANAGER>(_ic_newrm_1));
            }

        }
        return _ic_set_1;
    }

    _tr_constructor_service(): BSet<BTuple<INTERCONNECTNODE, SERVICE>> {
        let _ic_set_2: BSet<BTuple<INTERCONNECTNODE, SERVICE>> = new BSet<BTuple<INTERCONNECTNODE, SERVICE>>();
        for(let _ic_ii_1 of this.interconnectNodes) {
            for(let _ic_newsvc_1 of nota_v2._SERVICE.difference(this.services)) {
                _ic_set_2 = _ic_set_2.union(new BSet<BTuple<INTERCONNECTNODE, SERVICE>>(new BTuple(_ic_ii_1, _ic_newsvc_1)));

            }
        }
        return _ic_set_2;
    }

    _tr_constructor_socket(): BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>> {
        let _ic_set_3: BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>> = new BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>>();
        for(let _ic_ii_1 of this.interconnectNodes) {
            for(let _ic_srcsid_1 of this.sids) {
                for(let _ic_targsid_1 of this.sids) {
                    for(let _ic_newsoc_1 of nota_v2._SOCKET.difference(this.sockets)) {
                        _ic_set_3 = _ic_set_3.union(new BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>>(new BTuple(new BTuple(new BTuple(_ic_ii_1, _ic_srcsid_1), _ic_targsid_1), _ic_newsoc_1)));

                    }
                }
            }
        }
        return _ic_set_3;
    }

    _tr_rm_register(): BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>> {
        let _ic_set_4: BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>> = new BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>();
        for(let _ic_self_1 of this.resourceManagers) {
            for(let _ic_ss_1 of this.services) {
                for(let _ic_ii_1 of this.interconnectNodes) {
                    _ic_set_4 = _ic_set_4.union(new BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>(new BTuple(new BTuple(_ic_self_1, _ic_ss_1), _ic_ii_1)));

                }
            }
        }
        return _ic_set_4;
    }

    _tr_rm_deregister(): BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>> {
        let _ic_set_5: BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>> = new BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>();
        for(let _ic_self_1 of this.resourceManagers) {
            for(let _ic_ss_1 of this.services) {
                for(let _ic_ii_1 of this.interconnectNodes) {
                    _ic_set_5 = _ic_set_5.union(new BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>(new BTuple(new BTuple(_ic_self_1, _ic_ss_1), _ic_ii_1)));

                }
            }
        }
        return _ic_set_5;
    }

    _tr_rm_getSid(): BSet<BTuple<RESOURCEMANAGER, SERVICE>> {
        let _ic_set_6: BSet<BTuple<RESOURCEMANAGER, SERVICE>> = new BSet<BTuple<RESOURCEMANAGER, SERVICE>>();
        for(let _ic_self_1 of this.resourceManagers) {
            for(let _ic_ss_1 of this.services) {
                if((this.rm_sids.domain().elementOf(_ic_ss_1)).booleanValue()) {
                    _ic_set_6 = _ic_set_6.union(new BSet<BTuple<RESOURCEMANAGER, SERVICE>>(new BTuple(_ic_self_1, _ic_ss_1)));
                }

            }
        }
        return _ic_set_6;
    }

    _tr_rm_getSid_Not_Found(): BSet<BTuple<RESOURCEMANAGER, SERVICE>> {
        let _ic_set_7: BSet<BTuple<RESOURCEMANAGER, SERVICE>> = new BSet<BTuple<RESOURCEMANAGER, SERVICE>>();
        for(let _ic_self_1 of this.resourceManagers) {
            for(let _ic_ss_1 of this.services) {
                _ic_set_7 = _ic_set_7.union(new BSet<BTuple<RESOURCEMANAGER, SERVICE>>(new BTuple(_ic_self_1, _ic_ss_1)));

            }
        }
        return _ic_set_7;
    }

    _tr_in_announceResourceManager(): BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>> {
        let _ic_set_8: BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>> = new BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>>();
        for(let _ic_self_1 of this.interconnectNodes) {
            for(let _ic_rm_1 of this.resourceManagers) {
                if((this.in_resourceManager.functionCall(_ic_self_1).equal(new BSet<RESOURCEMANAGER>())).booleanValue()) {
                    _ic_set_8 = _ic_set_8.union(new BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>>(new BTuple(_ic_self_1, _ic_rm_1)));
                }

            }
        }
        return _ic_set_8;
    }

    _tr_in_register_success(): BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>> {
        let _ic_set_9: BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>> = new BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>>();
        for(let _ic_self_1 of this.interconnectNodes) {
            for(let _ic_ss_1 of this.services) {
                for(let _ic_si_1 of nota_v2._SID.difference(this.sids)) {
                    if((this.in_localServices.domain().elementOf(_ic_si_1).not()).booleanValue()) {
                        _ic_set_9 = _ic_set_9.union(new BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>>(new BTuple(new BTuple(_ic_self_1, _ic_ss_1), _ic_si_1)));
                    }

                }
            }
        }
        return _ic_set_9;
    }

    _tr_in_register_failed(): BSet<BTuple<INTERCONNECTNODE, SERVICE>> {
        let _ic_set_10: BSet<BTuple<INTERCONNECTNODE, SERVICE>> = new BSet<BTuple<INTERCONNECTNODE, SERVICE>>();
        for(let _ic_self_1 of this.interconnectNodes) {
            for(let _ic_ss_1 of this.services) {
                _ic_set_10 = _ic_set_10.union(new BSet<BTuple<INTERCONNECTNODE, SERVICE>>(new BTuple(_ic_self_1, _ic_ss_1)));

            }
        }
        return _ic_set_10;
    }

    _tr_in_requestTargetSocket_Granted(): BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>> {
        let _ic_set_11: BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>> = new BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>>();
        for(let _ic_self_1 of this.interconnectNodes) {
            for(let _ic_ii_1 of this.interconnectNodes) {
                for(let _ic_srcsoc_1 of this.sockets) {
                    for(let _ic_srcsid_1 of this.sids) {
                        for(let _ic_targsid_1 of this.sids) {
                            for(let _ic_newsoc_1 of nota_v2._SOCKET.difference(this.sockets)) {
                                if((new BBoolean(_ic_self_1.unequal(_ic_ii_1).booleanValue() && this.in_sockets.functionCall(_ic_srcsoc_1).equal(_ic_ii_1).booleanValue())).booleanValue()) {
                                    _ic_set_11 = _ic_set_11.union(new BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>>(new BTuple(new BTuple(new BTuple(new BTuple(new BTuple(_ic_self_1, _ic_ii_1), _ic_srcsoc_1), _ic_srcsid_1), _ic_targsid_1), _ic_newsoc_1)));
                                }

                            }
                        }
                    }
                }
            }
        }
        return _ic_set_11;
    }

    _tr_in_requestTargetSocket_NotGranted(): BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>> {
        let _ic_set_12: BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>> = new BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>>();
        for(let _ic_self_1 of this.interconnectNodes) {
            for(let _ic_ii_1 of this.interconnectNodes) {
                for(let _ic_srcsoc_1 of this.sockets) {
                    for(let _ic_srcsid_1 of this.sids) {
                        for(let _ic_targsid_1 of this.sids) {
                            if((new BBoolean(_ic_self_1.unequal(_ic_ii_1).booleanValue() && this.in_sockets.functionCall(_ic_srcsoc_1).equal(_ic_ii_1).booleanValue())).booleanValue()) {
                                _ic_set_12 = _ic_set_12.union(new BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>>(new BTuple(new BTuple(new BTuple(new BTuple(_ic_self_1, _ic_ii_1), _ic_srcsoc_1), _ic_srcsid_1), _ic_targsid_1)));
                            }

                        }
                    }
                }
            }
        }
        return _ic_set_12;
    }

    _tr_svc_register(): BSet<SERVICE> {
        let _ic_set_13: BSet<SERVICE> = new BSet<SERVICE>();
        for(let _ic_self_1 of this.services) {
            if((this.svc_registered.functionCall(_ic_self_1).equal(new BBoolean(false))).booleanValue()) {
                _ic_set_13 = _ic_set_13.union(new BSet<SERVICE>(_ic_self_1));
            }

        }
        return _ic_set_13;
    }

    _projected_state_for_in_register_success(): _ProjectionRead_in_register_success {
        return new _ProjectionRead_in_register_success(this.sids,this.interconnectNodes,this.in_localServices,this.services);
    }

    _projected_state_for_in_announceResourceManager(): _ProjectionRead_in_announceResourceManager {
        return new _ProjectionRead_in_announceResourceManager(this.interconnectNodes,this.in_resourceManager,this.resourceManagers);
    }

    _projected_state_for_in_requestTargetSocket_Granted(): _ProjectionRead_in_requestTargetSocket_Granted {
        return new _ProjectionRead_in_requestTargetSocket_Granted(this.interconnectNodes,this.sids,this.in_sockets,this.soc_to,this.soc_from,this.sockets);
    }

    _projected_state_for_constructor_service(): _ProjectionRead_constructor_service {
        return new _ProjectionRead_constructor_service(this.interconnectNodes,this.svc_registered,this.svc_sockets,this.services,this.svc_ICNode);
    }

    _projected_state_for_constructor_socket(): _ProjectionRead_constructor_socket {
        return new _ProjectionRead_constructor_socket(this.sids,this.interconnectNodes,this.in_sockets,this.soc_to,this.soc_from,this.sockets);
    }

    _projected_state_for_in_requestTargetSocket_NotGranted(): _ProjectionRead_in_requestTargetSocket_NotGranted {
        return new _ProjectionRead_in_requestTargetSocket_NotGranted(this.sids,this.interconnectNodes,this.in_sockets,this.sockets);
    }

    _projected_state_for_constructor_interconnectNode(): _ProjectionRead_constructor_interconnectNode {
        return new _ProjectionRead_constructor_interconnectNode(this.interconnectNodes,this.in_resourceManager);
    }

    _projected_state_for_rm_getSid(): _ProjectionRead_rm_getSid {
        return new _ProjectionRead_rm_getSid(this.services,this.resourceManagers,this.rm_sids);
    }

    _projected_state_for_rm_deregister(): _ProjectionRead_rm_deregister {
        return new _ProjectionRead_rm_deregister(this.interconnectNodes,this.services,this.resourceManagers);
    }

    _projected_state_for_constructor_resourceManager(): _ProjectionRead_constructor_resourceManager {
        return new _ProjectionRead_constructor_resourceManager(this.rm_services,this.resourceManagers);
    }

    _projected_state_for_in_register_failed(): _ProjectionRead_in_register_failed {
        return new _ProjectionRead_in_register_failed(this.interconnectNodes,this.services);
    }

    _projected_state_for_rm_register(): _ProjectionRead_rm_register {
        return new _ProjectionRead_rm_register(this.interconnectNodes,this.services,this.resourceManagers);
    }

    _projected_state_for_rm_getSid_Not_Found(): _ProjectionRead_rm_getSid_Not_Found {
        return new _ProjectionRead_rm_getSid_Not_Found(this.services,this.resourceManagers);
    }

    _projected_state_for_svc_register(): _ProjectionRead_svc_register {
        return new _ProjectionRead_svc_register(this.svc_registered,this.services);
    }

    _projected_state_for__tr_constructor_resourceManager(): _ProjectionRead__tr_constructor_resourceManager {
        return new _ProjectionRead__tr_constructor_resourceManager(this.rm_services,this.resourceManagers);
    }

    _projected_state_for__tr_in_register_failed(): _ProjectionRead__tr_in_register_failed {
        return new _ProjectionRead__tr_in_register_failed(this.interconnectNodes,this.services);
    }

    _projected_state_for__tr_rm_register(): _ProjectionRead__tr_rm_register {
        return new _ProjectionRead__tr_rm_register(this.interconnectNodes,this.services,this.resourceManagers);
    }

    _projected_state_for__tr_rm_getSid_Not_Found(): _ProjectionRead__tr_rm_getSid_Not_Found {
        return new _ProjectionRead__tr_rm_getSid_Not_Found(this.services,this.resourceManagers);
    }

    _projected_state_for__tr_in_requestTargetSocket_NotGranted(): _ProjectionRead__tr_in_requestTargetSocket_NotGranted {
        return new _ProjectionRead__tr_in_requestTargetSocket_NotGranted(this.sids,this.interconnectNodes,this.in_sockets,this.sockets);
    }

    _projected_state_for__tr_constructor_socket(): _ProjectionRead__tr_constructor_socket {
        return new _ProjectionRead__tr_constructor_socket(this.sids,this.interconnectNodes,this.sockets);
    }

    _projected_state_for__tr_rm_deregister(): _ProjectionRead__tr_rm_deregister {
        return new _ProjectionRead__tr_rm_deregister(this.interconnectNodes,this.services,this.resourceManagers);
    }

    _projected_state_for__tr_in_announceResourceManager(): _ProjectionRead__tr_in_announceResourceManager {
        return new _ProjectionRead__tr_in_announceResourceManager(this.interconnectNodes,this.in_resourceManager,this.resourceManagers);
    }

    _projected_state_for__tr_constructor_service(): _ProjectionRead__tr_constructor_service {
        return new _ProjectionRead__tr_constructor_service(this.interconnectNodes,this.services);
    }

    _projected_state_for__tr_rm_getSid(): _ProjectionRead__tr_rm_getSid {
        return new _ProjectionRead__tr_rm_getSid(this.services,this.resourceManagers,this.rm_sids);
    }

    _projected_state_for__tr_in_register_success(): _ProjectionRead__tr_in_register_success {
        return new _ProjectionRead__tr_in_register_success(this.sids,this.interconnectNodes,this.in_localServices,this.services);
    }

    _projected_state_for__tr_svc_register(): _ProjectionRead__tr_svc_register {
        return new _ProjectionRead__tr_svc_register(this.svc_registered,this.services);
    }

    _projected_state_for__tr_in_requestTargetSocket_Granted(): _ProjectionRead__tr_in_requestTargetSocket_Granted {
        return new _ProjectionRead__tr_in_requestTargetSocket_Granted(this.sids,this.interconnectNodes,this.in_sockets,this.sockets);
    }

    _projected_state_for__tr_constructor_interconnectNode(): _ProjectionRead__tr_constructor_interconnectNode {
        return new _ProjectionRead__tr_constructor_interconnectNode(this.interconnectNodes);
    }

    _projected_state_for__check_inv_18(): _ProjectionRead__check_inv_18 {
        return new _ProjectionRead__check_inv_18(this.resourceManagers);
    }

    _projected_state_for__check_inv_17(): _ProjectionRead__check_inv_17 {
        return new _ProjectionRead__check_inv_17(this.svc_registered,this.services);
    }

    _projected_state_for__check_inv_16(): _ProjectionRead__check_inv_16 {
        return new _ProjectionRead__check_inv_16(this.interconnectNodes,this.services,this.svc_ICNode);
    }

    _projected_state_for__check_inv_15(): _ProjectionRead__check_inv_15 {
        return new _ProjectionRead__check_inv_15(this.svc_sockets,this.services,this.sockets);
    }

    _projected_state_for__check_inv_6(): _ProjectionRead__check_inv_6 {
        return new _ProjectionRead__check_inv_6(this.rm_services,this.services,this.resourceManagers);
    }

    _projected_state_for__check_inv_10(): _ProjectionRead__check_inv_10 {
        return new _ProjectionRead__check_inv_10(this.interconnectNodes,this.in_sockets,this.sockets);
    }

    _projected_state_for__check_inv_7(): _ProjectionRead__check_inv_7 {
        return new _ProjectionRead__check_inv_7(this.rm_services);
    }

    _projected_state_for__check_inv_4(): _ProjectionRead__check_inv_4 {
        return new _ProjectionRead__check_inv_4(this.resourceManagers);
    }

    _projected_state_for__check_inv_5(): _ProjectionRead__check_inv_5 {
        return new _ProjectionRead__check_inv_5(this.sids);
    }

    _projected_state_for__check_inv_14(): _ProjectionRead__check_inv_14 {
        return new _ProjectionRead__check_inv_14(this.sids,this.services,this.svc_serviceID);
    }

    _projected_state_for__check_inv_13(): _ProjectionRead__check_inv_13 {
        return new _ProjectionRead__check_inv_13(this.sids,this.soc_from,this.sockets);
    }

    _projected_state_for__check_inv_8(): _ProjectionRead__check_inv_8 {
        return new _ProjectionRead__check_inv_8(this.sids,this.services,this.rm_sids);
    }

    _projected_state_for__check_inv_12(): _ProjectionRead__check_inv_12 {
        return new _ProjectionRead__check_inv_12(this.sids,this.soc_to,this.sockets);
    }

    _projected_state_for__check_inv_9(): _ProjectionRead__check_inv_9 {
        return new _ProjectionRead__check_inv_9(this.sids,this.interconnectNodes,this.in_localServices);
    }

    _projected_state_for__check_inv_11(): _ProjectionRead__check_inv_11 {
        return new _ProjectionRead__check_inv_11(this.interconnectNodes,this.in_resourceManager,this.resourceManagers);
    }

    _projected_state_for__check_inv_2(): _ProjectionRead__check_inv_2 {
        return new _ProjectionRead__check_inv_2(this.sockets);
    }

    _projected_state_for__check_inv_3(): _ProjectionRead__check_inv_3 {
        return new _ProjectionRead__check_inv_3(this.services);
    }

    _projected_state_for__check_inv_1(): _ProjectionRead__check_inv_1 {
        return new _ProjectionRead__check_inv_1(this.interconnectNodes);
    }

    _update_for_in_register_success(): _ProjectionWrite_in_register_success {
        return new _ProjectionWrite_in_register_success(this.sids,this.in_localServices);
    }

    _update_for_in_announceResourceManager(): _ProjectionWrite_in_announceResourceManager {
        return new _ProjectionWrite_in_announceResourceManager(this.in_resourceManager);
    }

    _update_for_in_requestTargetSocket_Granted(): _ProjectionWrite_in_requestTargetSocket_Granted {
        return new _ProjectionWrite_in_requestTargetSocket_Granted(this.in_sockets,this.soc_to,this.soc_from,this.sockets);
    }

    _update_for_constructor_service(): _ProjectionWrite_constructor_service {
        return new _ProjectionWrite_constructor_service(this.svc_registered,this.svc_sockets,this.services,this.svc_serviceID,this.svc_ICNode);
    }

    _update_for_constructor_socket(): _ProjectionWrite_constructor_socket {
        return new _ProjectionWrite_constructor_socket(this.in_sockets,this.soc_to,this.soc_from,this.sockets);
    }

    _update_for_in_requestTargetSocket_NotGranted(): _ProjectionWrite_in_requestTargetSocket_NotGranted {
        return new _ProjectionWrite_in_requestTargetSocket_NotGranted();
    }

    _update_for_constructor_interconnectNode(): _ProjectionWrite_constructor_interconnectNode {
        return new _ProjectionWrite_constructor_interconnectNode(this.interconnectNodes,this.in_resourceManager);
    }

    _update_for_rm_getSid(): _ProjectionWrite_rm_getSid {
        return new _ProjectionWrite_rm_getSid();
    }

    _update_for_rm_deregister(): _ProjectionWrite_rm_deregister {
        return new _ProjectionWrite_rm_deregister();
    }

    _update_for_constructor_resourceManager(): _ProjectionWrite_constructor_resourceManager {
        return new _ProjectionWrite_constructor_resourceManager(this.rm_services,this.resourceManagers);
    }

    _update_for_in_register_failed(): _ProjectionWrite_in_register_failed {
        return new _ProjectionWrite_in_register_failed();
    }

    _update_for_rm_register(): _ProjectionWrite_rm_register {
        return new _ProjectionWrite_rm_register();
    }

    _update_for_rm_getSid_Not_Found(): _ProjectionWrite_rm_getSid_Not_Found {
        return new _ProjectionWrite_rm_getSid_Not_Found();
    }

    _update_for_svc_register(): _ProjectionWrite_svc_register {
        return new _ProjectionWrite_svc_register(this.svc_registered);
    }

    _apply_update_for_in_register_success(update : _ProjectionWrite_in_register_success): void {
        this.sids = update.sids;
        this.in_localServices = update.in_localServices;
    }

    _apply_update_for_in_announceResourceManager(update : _ProjectionWrite_in_announceResourceManager): void {
        this.in_resourceManager = update.in_resourceManager;
    }

    _apply_update_for_in_requestTargetSocket_Granted(update : _ProjectionWrite_in_requestTargetSocket_Granted): void {
        this.in_sockets = update.in_sockets;
        this.soc_to = update.soc_to;
        this.soc_from = update.soc_from;
        this.sockets = update.sockets;
    }

    _apply_update_for_constructor_service(update : _ProjectionWrite_constructor_service): void {
        this.svc_registered = update.svc_registered;
        this.svc_sockets = update.svc_sockets;
        this.services = update.services;
        this.svc_serviceID = update.svc_serviceID;
        this.svc_ICNode = update.svc_ICNode;
    }

    _apply_update_for_constructor_socket(update : _ProjectionWrite_constructor_socket): void {
        this.in_sockets = update.in_sockets;
        this.soc_to = update.soc_to;
        this.soc_from = update.soc_from;
        this.sockets = update.sockets;
    }

    _apply_update_for_in_requestTargetSocket_NotGranted(update : _ProjectionWrite_in_requestTargetSocket_NotGranted): void {
    }

    _apply_update_for_constructor_interconnectNode(update : _ProjectionWrite_constructor_interconnectNode): void {
        this.interconnectNodes = update.interconnectNodes;
        this.in_resourceManager = update.in_resourceManager;
    }

    _apply_update_for_rm_getSid(update : _ProjectionWrite_rm_getSid): void {
    }

    _apply_update_for_rm_deregister(update : _ProjectionWrite_rm_deregister): void {
    }

    _apply_update_for_constructor_resourceManager(update : _ProjectionWrite_constructor_resourceManager): void {
        this.rm_services = update.rm_services;
        this.resourceManagers = update.resourceManagers;
    }

    _apply_update_for_in_register_failed(update : _ProjectionWrite_in_register_failed): void {
    }

    _apply_update_for_rm_register(update : _ProjectionWrite_rm_register): void {
    }

    _apply_update_for_rm_getSid_Not_Found(update : _ProjectionWrite_rm_getSid_Not_Found): void {
    }

    _apply_update_for_svc_register(update : _ProjectionWrite_svc_register): void {
        this.svc_registered = update.svc_registered;
    }

    _check_inv_1() {
        let _ic_boolean_14: BBoolean = new BBoolean(true);
        for(let _ic__opt_1_1 of this.interconnectNodes) {
            if(!(new BBoolean(!this.interconnectNodes.elementOf(_ic__opt_1_1).booleanValue() || nota_v2._INTERCONNECTNODE.elementOf(_ic__opt_1_1).booleanValue())).booleanValue()) {
                _ic_boolean_14 = new BBoolean(false);
                break;
            }

        }
        return _ic_boolean_14.booleanValue();
    }

    _check_inv_2() {
        let _ic_boolean_15: BBoolean = new BBoolean(true);
        for(let _ic__opt_2_1 of this.sockets) {
            if(!(new BBoolean(!this.sockets.elementOf(_ic__opt_2_1).booleanValue() || nota_v2._SOCKET.elementOf(_ic__opt_2_1).booleanValue())).booleanValue()) {
                _ic_boolean_15 = new BBoolean(false);
                break;
            }

        }
        return _ic_boolean_15.booleanValue();
    }

    _check_inv_3() {
        let _ic_boolean_16: BBoolean = new BBoolean(true);
        for(let _ic__opt_3_1 of this.services) {
            if(!(new BBoolean(!this.services.elementOf(_ic__opt_3_1).booleanValue() || nota_v2._SERVICE.elementOf(_ic__opt_3_1).booleanValue())).booleanValue()) {
                _ic_boolean_16 = new BBoolean(false);
                break;
            }

        }
        return _ic_boolean_16.booleanValue();
    }

    _check_inv_4() {
        let _ic_boolean_17: BBoolean = new BBoolean(true);
        for(let _ic__opt_4_1 of this.resourceManagers) {
            if(!(new BBoolean(!this.resourceManagers.elementOf(_ic__opt_4_1).booleanValue() || nota_v2._RESOURCEMANAGER.elementOf(_ic__opt_4_1).booleanValue())).booleanValue()) {
                _ic_boolean_17 = new BBoolean(false);
                break;
            }

        }
        return _ic_boolean_17.booleanValue();
    }

    _check_inv_5() {
        let _ic_boolean_18: BBoolean = new BBoolean(true);
        for(let _ic__opt_5_1 of this.sids) {
            if(!(new BBoolean(!this.sids.elementOf(_ic__opt_5_1).booleanValue() || nota_v2._SID.elementOf(_ic__opt_5_1).booleanValue())).booleanValue()) {
                _ic_boolean_18 = new BBoolean(false);
                break;
            }

        }
        return _ic_boolean_18.booleanValue();
    }

    _check_inv_6() {
        return this.rm_services.checkDomain(this.resourceManagers).and(this.rm_services.checkRange(this.services.pow())).and(this.rm_services.isFunction()).and(this.rm_services.isTotal(this.resourceManagers)).booleanValue();
    }

    _check_inv_7() {
        let _ic_boolean_19: BBoolean = new BBoolean(true);
        for(let _ic_a1_1 of this.rm_services.domain()) {
            for(let _ic_a2_1 of this.rm_services.domain()) {
                if(!(new BBoolean(!new BBoolean(new BBoolean(this.rm_services.domain().elementOf(_ic_a1_1).booleanValue() && this.rm_services.domain().elementOf(_ic_a2_1).booleanValue()).booleanValue() && _ic_a1_1.unequal(_ic_a2_1).booleanValue()).booleanValue() || this.rm_services.functionCall(_ic_a1_1).intersect(this.rm_services.functionCall(_ic_a2_1)).equal(new BSet<SERVICE>()).booleanValue())).booleanValue()) {
                    _ic_boolean_19 = new BBoolean(false);
                    break;
                }

            }
        }
        return _ic_boolean_19.booleanValue();
    }

    _check_inv_8() {
        return this.rm_sids.checkDomain(this.services).and(this.rm_sids.checkRange(this.sids)).and(this.rm_sids.isFunction()).and(this.rm_sids.isPartial(this.services)).and(this.rm_sids.isInjection()).booleanValue();
    }

    _check_inv_9() {
        return this.in_localServices.checkDomain(this.sids).and(this.in_localServices.checkRange(this.interconnectNodes)).and(this.in_localServices.isFunction()).and(this.in_localServices.isTotal(this.sids)).booleanValue();
    }

    _check_inv_10() {
        return this.in_sockets.checkDomain(this.sockets).and(this.in_sockets.checkRange(this.interconnectNodes)).and(this.in_sockets.isFunction()).and(this.in_sockets.isTotal(this.sockets)).booleanValue();
    }

    _check_inv_11() {
        return this.in_resourceManager.checkDomain(this.interconnectNodes).and(this.in_resourceManager.checkRange(this.resourceManagers.pow())).and(this.in_resourceManager.isFunction()).and(this.in_resourceManager.isTotal(this.interconnectNodes)).booleanValue();
    }

    _check_inv_12() {
        return this.soc_to.checkDomain(this.sockets).and(this.soc_to.checkRange(this.sids)).and(this.soc_to.isFunction()).and(this.soc_to.isTotal(this.sockets)).booleanValue();
    }

    _check_inv_13() {
        return this.soc_from.checkDomain(this.sockets).and(this.soc_from.checkRange(this.sids)).and(this.soc_from.isFunction()).and(this.soc_from.isTotal(this.sockets)).booleanValue();
    }

    _check_inv_14() {
        return this.svc_serviceID.checkDomain(this.services).and(this.svc_serviceID.checkRange(this.sids)).and(this.svc_serviceID.isFunction()).and(this.svc_serviceID.isPartial(this.services)).booleanValue();
    }

    _check_inv_15() {
        return this.svc_sockets.checkDomain(this.services).and(this.svc_sockets.checkRange(this.sockets.pow())).and(this.svc_sockets.isFunction()).and(this.svc_sockets.isTotal(this.services)).booleanValue();
    }

    _check_inv_16() {
        return this.svc_ICNode.checkDomain(this.services).and(this.svc_ICNode.checkRange(this.interconnectNodes)).and(this.svc_ICNode.isFunction()).and(this.svc_ICNode.isTotal(this.services)).booleanValue();
    }

    _check_inv_17() {
        return this.svc_registered.checkDomain(this.services).and(this.svc_registered.checkRangeBoolean()).and(this.svc_registered.isFunction()).and(this.svc_registered.isTotal(this.services)).booleanValue();
    }

    _check_inv_18() {
        return new BBoolean(!this.resourceManagers.equal(new BSet<RESOURCEMANAGER>()).not().booleanValue() || this.resourceManagers.card().equal(new BInteger(1)).booleanValue()).booleanValue();
    }

    equals(o: any): boolean {
        let o1: nota_v2 = this;
        let o2: nota_v2 = o as nota_v2;
        return o1._get_interconnectNodes().equals(o2._get_interconnectNodes()) && o1._get_sockets().equals(o2._get_sockets()) && o1._get_services().equals(o2._get_services()) && o1._get_resourceManagers().equals(o2._get_resourceManagers()) && o1._get_sids().equals(o2._get_sids()) && o1._get_rm_services().equals(o2._get_rm_services()) && o1._get_rm_sids().equals(o2._get_rm_sids()) && o1._get_in_localServices().equals(o2._get_in_localServices()) && o1._get_in_sockets().equals(o2._get_in_sockets()) && o1._get_in_resourceManager().equals(o2._get_in_resourceManager()) && o1._get_soc_to().equals(o2._get_soc_to()) && o1._get_soc_from().equals(o2._get_soc_from()) && o1._get_svc_serviceID().equals(o2._get_svc_serviceID()) && o1._get_svc_sockets().equals(o2._get_svc_sockets()) && o1._get_svc_ICNode().equals(o2._get_svc_ICNode()) && o1._get_svc_registered().equals(o2._get_svc_registered());
    }



    hashCode(): number {
        return this._hashCode_1();
    }

    _hashCode_1(): number {
        let result: number = 1;
        result = (1543 * result) ^ ((this._get_interconnectNodes()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_sockets()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_services()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_resourceManagers()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_sids()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_rm_services()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_rm_sids()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_in_localServices()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_in_sockets()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_in_resourceManager()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_soc_to()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_soc_from()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_svc_serviceID()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_svc_sockets()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_svc_ICNode()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_svc_registered()).hashCode() << 1);
        return result;
    }

    _hashCode_2(): number {
        let result: number = 1;
        result = (6151 * result) ^ ((this._get_interconnectNodes()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_sockets()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_services()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_resourceManagers()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_sids()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_rm_services()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_rm_sids()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_in_localServices()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_in_sockets()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_in_resourceManager()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_soc_to()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_soc_from()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_svc_serviceID()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_svc_sockets()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_svc_ICNode()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_svc_registered()).hashCode() << 1);
        return result;
    }

    /* TODO
    toString(): string {
        return String.join("\n", "_get_interconnectNodes: " + (this._get_interconnectNodes()).toString(), "_get_sockets: " + (this._get_sockets()).toString(), "_get_services: " + (this._get_services()).toString(), "_get_resourceManagers: " + (this._get_resourceManagers()).toString(), "_get_sids: " + (this._get_sids()).toString(), "_get_rm_services: " + (this._get_rm_services()).toString(), "_get_rm_sids: " + (this._get_rm_sids()).toString(), "_get_in_localServices: " + (this._get_in_localServices()).toString(), "_get_in_sockets: " + (this._get_in_sockets()).toString(), "_get_in_resourceManager: " + (this._get_in_resourceManager()).toString(), "_get_soc_to: " + (this._get_soc_to()).toString(), "_get_soc_from: " + (this._get_soc_from()).toString(), "_get_svc_serviceID: " + (this._get_svc_serviceID()).toString(), "_get_svc_sockets: " + (this._get_svc_sockets()).toString(), "_get_svc_ICNode: " + (this._get_svc_ICNode()).toString(), "_get_svc_registered: " + (this._get_svc_registered()).toString());
    }
    */


    public _copy(): nota_v2 {
      return new nota_v2(this);
    }


}


export class ModelChecker {
    private type: Type;
    private isCaching: boolean;
    private isDebug: boolean;

    private unvisitedStates: LinkedList<nota_v2> = new LinkedList<nota_v2>;
    private states: immutable.Set<nota_v2> = new immutable.Set();
    private transitions: number = 0;

    private invariantViolated: boolean = false;
    private deadlockDetected: boolean = false;
    private counterExampleState: nota_v2 = undefined;

    _OpCache_constructor_interconnectNode: immutable.Map<BSet<INTERCONNECTNODE>, immutable.Map<_ProjectionRead_constructor_interconnectNode, _ProjectionWrite_constructor_interconnectNode>> = new immutable.Map();
    _OpCache_tr_constructor_interconnectNode: immutable.Map<_ProjectionRead__tr_constructor_interconnectNode, BSet<INTERCONNECTNODE>> = new immutable.Map();

    _OpCache_constructor_resourceManager: immutable.Map<BSet<RESOURCEMANAGER>, immutable.Map<_ProjectionRead_constructor_resourceManager, _ProjectionWrite_constructor_resourceManager>> = new immutable.Map();
    _OpCache_tr_constructor_resourceManager: immutable.Map<_ProjectionRead__tr_constructor_resourceManager, BSet<RESOURCEMANAGER>> = new immutable.Map();

    _OpCache_constructor_service: immutable.Map<BSet<BTuple<INTERCONNECTNODE, SERVICE>>, immutable.Map<_ProjectionRead_constructor_service, _ProjectionWrite_constructor_service>> = new immutable.Map();
    _OpCache_tr_constructor_service: immutable.Map<_ProjectionRead__tr_constructor_service, BSet<BTuple<INTERCONNECTNODE, SERVICE>>> = new immutable.Map();

    _OpCache_constructor_socket: immutable.Map<BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>>, immutable.Map<_ProjectionRead_constructor_socket, _ProjectionWrite_constructor_socket>> = new immutable.Map();
    _OpCache_tr_constructor_socket: immutable.Map<_ProjectionRead__tr_constructor_socket, BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>>> = new immutable.Map();

    _OpCache_rm_register: immutable.Map<BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>, immutable.Map<_ProjectionRead_rm_register, _ProjectionWrite_rm_register>> = new immutable.Map();
    _OpCache_tr_rm_register: immutable.Map<_ProjectionRead__tr_rm_register, BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>> = new immutable.Map();

    _OpCache_rm_deregister: immutable.Map<BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>, immutable.Map<_ProjectionRead_rm_deregister, _ProjectionWrite_rm_deregister>> = new immutable.Map();
    _OpCache_tr_rm_deregister: immutable.Map<_ProjectionRead__tr_rm_deregister, BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>> = new immutable.Map();

    _OpCache_rm_getSid: immutable.Map<BSet<BTuple<RESOURCEMANAGER, SERVICE>>, immutable.Map<_ProjectionRead_rm_getSid, _ProjectionWrite_rm_getSid>> = new immutable.Map();
    _OpCache_tr_rm_getSid: immutable.Map<_ProjectionRead__tr_rm_getSid, BSet<BTuple<RESOURCEMANAGER, SERVICE>>> = new immutable.Map();

    _OpCache_rm_getSid_Not_Found: immutable.Map<BSet<BTuple<RESOURCEMANAGER, SERVICE>>, immutable.Map<_ProjectionRead_rm_getSid_Not_Found, _ProjectionWrite_rm_getSid_Not_Found>> = new immutable.Map();
    _OpCache_tr_rm_getSid_Not_Found: immutable.Map<_ProjectionRead__tr_rm_getSid_Not_Found, BSet<BTuple<RESOURCEMANAGER, SERVICE>>> = new immutable.Map();

    _OpCache_in_announceResourceManager: immutable.Map<BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>>, immutable.Map<_ProjectionRead_in_announceResourceManager, _ProjectionWrite_in_announceResourceManager>> = new immutable.Map();
    _OpCache_tr_in_announceResourceManager: immutable.Map<_ProjectionRead__tr_in_announceResourceManager, BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>>> = new immutable.Map();

    _OpCache_in_register_success: immutable.Map<BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>>, immutable.Map<_ProjectionRead_in_register_success, _ProjectionWrite_in_register_success>> = new immutable.Map();
    _OpCache_tr_in_register_success: immutable.Map<_ProjectionRead__tr_in_register_success, BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>>> = new immutable.Map();

    _OpCache_in_register_failed: immutable.Map<BSet<BTuple<INTERCONNECTNODE, SERVICE>>, immutable.Map<_ProjectionRead_in_register_failed, _ProjectionWrite_in_register_failed>> = new immutable.Map();
    _OpCache_tr_in_register_failed: immutable.Map<_ProjectionRead__tr_in_register_failed, BSet<BTuple<INTERCONNECTNODE, SERVICE>>> = new immutable.Map();

    _OpCache_in_requestTargetSocket_Granted: immutable.Map<BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>>, immutable.Map<_ProjectionRead_in_requestTargetSocket_Granted, _ProjectionWrite_in_requestTargetSocket_Granted>> = new immutable.Map();
    _OpCache_tr_in_requestTargetSocket_Granted: immutable.Map<_ProjectionRead__tr_in_requestTargetSocket_Granted, BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>>> = new immutable.Map();

    _OpCache_in_requestTargetSocket_NotGranted: immutable.Map<BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>>, immutable.Map<_ProjectionRead_in_requestTargetSocket_NotGranted, _ProjectionWrite_in_requestTargetSocket_NotGranted>> = new immutable.Map();
    _OpCache_tr_in_requestTargetSocket_NotGranted: immutable.Map<_ProjectionRead__tr_in_requestTargetSocket_NotGranted, BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>>> = new immutable.Map();

    _OpCache_svc_register: immutable.Map<BSet<SERVICE>, immutable.Map<_ProjectionRead_svc_register, _ProjectionWrite_svc_register>> = new immutable.Map();
    _OpCache_tr_svc_register: immutable.Map<_ProjectionRead__tr_svc_register, BSet<SERVICE>> = new immutable.Map();

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
        let machine: nota_v2 = new nota_v2();
        this.states = this.states.add(machine);
        this.unvisitedStates.pushBack(machine);

        while(!(this.unvisitedStates.length === 0)) {
            let state: nota_v2 = this.next();

            let nextStates: Set<nota_v2> = this.generateNextStates(state);

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

    next(): nota_v2 {
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

    generateNextStates(state: nota_v2): Set<nota_v2> {
        let result: immutable.Set<nota_v2> = immutable.Set();
        if(this.isCaching) {
            let read__tr_constructor_interconnectNode_state : _ProjectionRead__tr_constructor_interconnectNode = state._projected_state_for__tr_constructor_interconnectNode();
            let _trid_1 : BSet<INTERCONNECTNODE>  = this._OpCache_tr_constructor_interconnectNode.get(read__tr_constructor_interconnectNode_state);
            if(_trid_1 == null) {
                _trid_1 = state._tr_constructor_interconnectNode();
                this._OpCache_tr_constructor_interconnectNode = this._OpCache_tr_constructor_interconnectNode.set(read__tr_constructor_interconnectNode_state, _trid_1);
            }

            for(let param of _trid_1) {
                let _tmp_1: INTERCONNECTNODE = param;

                let copiedState: nota_v2 = state._copy();
                let readState: _ProjectionRead_constructor_interconnectNode = state._projected_state_for_constructor_interconnectNode();
                let _OpCache_with_parameter_constructor_interconnectNode: immutable.Map = this._OpCache_constructor_interconnectNode.get(param);
                if(_OpCache_with_parameter_constructor_interconnectNode != null) {
                    let writeState: _ProjectionWrite_constructor_interconnectNode = _OpCache_with_parameter_constructor_interconnectNode.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_constructor_interconnectNode(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.constructor_interconnectNode(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_constructor_interconnectNode();
                        _OpCache_with_parameter_constructor_interconnectNode = _OpCache_with_parameter_constructor_interconnectNode.set(readState, writeState);
                        this._OpCache_constructor_interconnectNode = this._OpCache_constructor_interconnectNode.set(param, _OpCache_with_parameter_constructor_interconnectNode);
                    }

                } else {
                    copiedState.constructor_interconnectNode(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_constructor_interconnectNode = copiedState._update_for_constructor_interconnectNode();
                    _OpCache_with_parameter_constructor_interconnectNode = new immutable.Map().set(readState, writeState);
                    this._OpCache_constructor_interconnectNode = this._OpCache_constructor_interconnectNode.set(param, _OpCache_with_parameter_constructor_interconnectNode);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_constructor_resourceManager_state : _ProjectionRead__tr_constructor_resourceManager = state._projected_state_for__tr_constructor_resourceManager();
            let _trid_2 : BSet<RESOURCEMANAGER>  = this._OpCache_tr_constructor_resourceManager.get(read__tr_constructor_resourceManager_state);
            if(_trid_2 == null) {
                _trid_2 = state._tr_constructor_resourceManager();
                this._OpCache_tr_constructor_resourceManager = this._OpCache_tr_constructor_resourceManager.set(read__tr_constructor_resourceManager_state, _trid_2);
            }

            for(let param of _trid_2) {
                let _tmp_1: RESOURCEMANAGER = param;

                let copiedState: nota_v2 = state._copy();
                let readState: _ProjectionRead_constructor_resourceManager = state._projected_state_for_constructor_resourceManager();
                let _OpCache_with_parameter_constructor_resourceManager: immutable.Map = this._OpCache_constructor_resourceManager.get(param);
                if(_OpCache_with_parameter_constructor_resourceManager != null) {
                    let writeState: _ProjectionWrite_constructor_resourceManager = _OpCache_with_parameter_constructor_resourceManager.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_constructor_resourceManager(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.constructor_resourceManager(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_constructor_resourceManager();
                        _OpCache_with_parameter_constructor_resourceManager = _OpCache_with_parameter_constructor_resourceManager.set(readState, writeState);
                        this._OpCache_constructor_resourceManager = this._OpCache_constructor_resourceManager.set(param, _OpCache_with_parameter_constructor_resourceManager);
                    }

                } else {
                    copiedState.constructor_resourceManager(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_constructor_resourceManager = copiedState._update_for_constructor_resourceManager();
                    _OpCache_with_parameter_constructor_resourceManager = new immutable.Map().set(readState, writeState);
                    this._OpCache_constructor_resourceManager = this._OpCache_constructor_resourceManager.set(param, _OpCache_with_parameter_constructor_resourceManager);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_constructor_service_state : _ProjectionRead__tr_constructor_service = state._projected_state_for__tr_constructor_service();
            let _trid_3 : BSet<BTuple<INTERCONNECTNODE, SERVICE>>  = this._OpCache_tr_constructor_service.get(read__tr_constructor_service_state);
            if(_trid_3 == null) {
                _trid_3 = state._tr_constructor_service();
                this._OpCache_tr_constructor_service = this._OpCache_tr_constructor_service.set(read__tr_constructor_service_state, _trid_3);
            }

            for(let param of _trid_3) {
                let _tmp_1: SERVICE = param.projection2();
                let _tmp_2: INTERCONNECTNODE = param.projection1();

                let copiedState: nota_v2 = state._copy();
                let readState: _ProjectionRead_constructor_service = state._projected_state_for_constructor_service();
                let _OpCache_with_parameter_constructor_service: immutable.Map = this._OpCache_constructor_service.get(param);
                if(_OpCache_with_parameter_constructor_service != null) {
                    let writeState: _ProjectionWrite_constructor_service = _OpCache_with_parameter_constructor_service.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_constructor_service(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.constructor_service(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_constructor_service();
                        _OpCache_with_parameter_constructor_service = _OpCache_with_parameter_constructor_service.set(readState, writeState);
                        this._OpCache_constructor_service = this._OpCache_constructor_service.set(param, _OpCache_with_parameter_constructor_service);
                    }

                } else {
                    copiedState.constructor_service(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_constructor_service = copiedState._update_for_constructor_service();
                    _OpCache_with_parameter_constructor_service = new immutable.Map().set(readState, writeState);
                    this._OpCache_constructor_service = this._OpCache_constructor_service.set(param, _OpCache_with_parameter_constructor_service);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_constructor_socket_state : _ProjectionRead__tr_constructor_socket = state._projected_state_for__tr_constructor_socket();
            let _trid_4 : BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>>  = this._OpCache_tr_constructor_socket.get(read__tr_constructor_socket_state);
            if(_trid_4 == null) {
                _trid_4 = state._tr_constructor_socket();
                this._OpCache_tr_constructor_socket = this._OpCache_tr_constructor_socket.set(read__tr_constructor_socket_state, _trid_4);
            }

            for(let param of _trid_4) {
                let _tmp_1: SOCKET = param.projection2();
                let _tmp_2: BTuple<BTuple<INTERCONNECTNODE, SID>, SID> = param.projection1();
                let _tmp_3: SID = _tmp_2.projection2();
                let _tmp_4: BTuple<INTERCONNECTNODE, SID> = _tmp_2.projection1();
                let _tmp_5: SID = _tmp_4.projection2();
                let _tmp_6: INTERCONNECTNODE = _tmp_4.projection1();

                let copiedState: nota_v2 = state._copy();
                let readState: _ProjectionRead_constructor_socket = state._projected_state_for_constructor_socket();
                let _OpCache_with_parameter_constructor_socket: immutable.Map = this._OpCache_constructor_socket.get(param);
                if(_OpCache_with_parameter_constructor_socket != null) {
                    let writeState: _ProjectionWrite_constructor_socket = _OpCache_with_parameter_constructor_socket.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_constructor_socket(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.constructor_socket(_tmp_6, _tmp_5, _tmp_3, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_constructor_socket();
                        _OpCache_with_parameter_constructor_socket = _OpCache_with_parameter_constructor_socket.set(readState, writeState);
                        this._OpCache_constructor_socket = this._OpCache_constructor_socket.set(param, _OpCache_with_parameter_constructor_socket);
                    }

                } else {
                    copiedState.constructor_socket(_tmp_6, _tmp_5, _tmp_3, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_constructor_socket = copiedState._update_for_constructor_socket();
                    _OpCache_with_parameter_constructor_socket = new immutable.Map().set(readState, writeState);
                    this._OpCache_constructor_socket = this._OpCache_constructor_socket.set(param, _OpCache_with_parameter_constructor_socket);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_rm_register_state : _ProjectionRead__tr_rm_register = state._projected_state_for__tr_rm_register();
            let _trid_5 : BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>  = this._OpCache_tr_rm_register.get(read__tr_rm_register_state);
            if(_trid_5 == null) {
                _trid_5 = state._tr_rm_register();
                this._OpCache_tr_rm_register = this._OpCache_tr_rm_register.set(read__tr_rm_register_state, _trid_5);
            }

            for(let param of _trid_5) {
                let _tmp_1: INTERCONNECTNODE = param.projection2();
                let _tmp_2: BTuple<RESOURCEMANAGER, SERVICE> = param.projection1();
                let _tmp_3: SERVICE = _tmp_2.projection2();
                let _tmp_4: RESOURCEMANAGER = _tmp_2.projection1();

                let copiedState: nota_v2 = state._copy();
                let readState: _ProjectionRead_rm_register = state._projected_state_for_rm_register();
                let _OpCache_with_parameter_rm_register: immutable.Map = this._OpCache_rm_register.get(param);
                if(_OpCache_with_parameter_rm_register != null) {
                    let writeState: _ProjectionWrite_rm_register = _OpCache_with_parameter_rm_register.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_rm_register(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.rm_register(_tmp_4, _tmp_3, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_rm_register();
                        _OpCache_with_parameter_rm_register = _OpCache_with_parameter_rm_register.set(readState, writeState);
                        this._OpCache_rm_register = this._OpCache_rm_register.set(param, _OpCache_with_parameter_rm_register);
                    }

                } else {
                    copiedState.rm_register(_tmp_4, _tmp_3, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_rm_register = copiedState._update_for_rm_register();
                    _OpCache_with_parameter_rm_register = new immutable.Map().set(readState, writeState);
                    this._OpCache_rm_register = this._OpCache_rm_register.set(param, _OpCache_with_parameter_rm_register);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_rm_deregister_state : _ProjectionRead__tr_rm_deregister = state._projected_state_for__tr_rm_deregister();
            let _trid_6 : BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>  = this._OpCache_tr_rm_deregister.get(read__tr_rm_deregister_state);
            if(_trid_6 == null) {
                _trid_6 = state._tr_rm_deregister();
                this._OpCache_tr_rm_deregister = this._OpCache_tr_rm_deregister.set(read__tr_rm_deregister_state, _trid_6);
            }

            for(let param of _trid_6) {
                let _tmp_1: INTERCONNECTNODE = param.projection2();
                let _tmp_2: BTuple<RESOURCEMANAGER, SERVICE> = param.projection1();
                let _tmp_3: SERVICE = _tmp_2.projection2();
                let _tmp_4: RESOURCEMANAGER = _tmp_2.projection1();

                let copiedState: nota_v2 = state._copy();
                let readState: _ProjectionRead_rm_deregister = state._projected_state_for_rm_deregister();
                let _OpCache_with_parameter_rm_deregister: immutable.Map = this._OpCache_rm_deregister.get(param);
                if(_OpCache_with_parameter_rm_deregister != null) {
                    let writeState: _ProjectionWrite_rm_deregister = _OpCache_with_parameter_rm_deregister.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_rm_deregister(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.rm_deregister(_tmp_4, _tmp_3, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_rm_deregister();
                        _OpCache_with_parameter_rm_deregister = _OpCache_with_parameter_rm_deregister.set(readState, writeState);
                        this._OpCache_rm_deregister = this._OpCache_rm_deregister.set(param, _OpCache_with_parameter_rm_deregister);
                    }

                } else {
                    copiedState.rm_deregister(_tmp_4, _tmp_3, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_rm_deregister = copiedState._update_for_rm_deregister();
                    _OpCache_with_parameter_rm_deregister = new immutable.Map().set(readState, writeState);
                    this._OpCache_rm_deregister = this._OpCache_rm_deregister.set(param, _OpCache_with_parameter_rm_deregister);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_rm_getSid_state : _ProjectionRead__tr_rm_getSid = state._projected_state_for__tr_rm_getSid();
            let _trid_7 : BSet<BTuple<RESOURCEMANAGER, SERVICE>>  = this._OpCache_tr_rm_getSid.get(read__tr_rm_getSid_state);
            if(_trid_7 == null) {
                _trid_7 = state._tr_rm_getSid();
                this._OpCache_tr_rm_getSid = this._OpCache_tr_rm_getSid.set(read__tr_rm_getSid_state, _trid_7);
            }

            for(let param of _trid_7) {
                let _tmp_1: SERVICE = param.projection2();
                let _tmp_2: RESOURCEMANAGER = param.projection1();

                let copiedState: nota_v2 = state._copy();
                let readState: _ProjectionRead_rm_getSid = state._projected_state_for_rm_getSid();
                let _OpCache_with_parameter_rm_getSid: immutable.Map = this._OpCache_rm_getSid.get(param);
                if(_OpCache_with_parameter_rm_getSid != null) {
                    let writeState: _ProjectionWrite_rm_getSid = _OpCache_with_parameter_rm_getSid.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_rm_getSid(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.rm_getSid(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_rm_getSid();
                        _OpCache_with_parameter_rm_getSid = _OpCache_with_parameter_rm_getSid.set(readState, writeState);
                        this._OpCache_rm_getSid = this._OpCache_rm_getSid.set(param, _OpCache_with_parameter_rm_getSid);
                    }

                } else {
                    copiedState.rm_getSid(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_rm_getSid = copiedState._update_for_rm_getSid();
                    _OpCache_with_parameter_rm_getSid = new immutable.Map().set(readState, writeState);
                    this._OpCache_rm_getSid = this._OpCache_rm_getSid.set(param, _OpCache_with_parameter_rm_getSid);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_rm_getSid_Not_Found_state : _ProjectionRead__tr_rm_getSid_Not_Found = state._projected_state_for__tr_rm_getSid_Not_Found();
            let _trid_8 : BSet<BTuple<RESOURCEMANAGER, SERVICE>>  = this._OpCache_tr_rm_getSid_Not_Found.get(read__tr_rm_getSid_Not_Found_state);
            if(_trid_8 == null) {
                _trid_8 = state._tr_rm_getSid_Not_Found();
                this._OpCache_tr_rm_getSid_Not_Found = this._OpCache_tr_rm_getSid_Not_Found.set(read__tr_rm_getSid_Not_Found_state, _trid_8);
            }

            for(let param of _trid_8) {
                let _tmp_1: SERVICE = param.projection2();
                let _tmp_2: RESOURCEMANAGER = param.projection1();

                let copiedState: nota_v2 = state._copy();
                let readState: _ProjectionRead_rm_getSid_Not_Found = state._projected_state_for_rm_getSid_Not_Found();
                let _OpCache_with_parameter_rm_getSid_Not_Found: immutable.Map = this._OpCache_rm_getSid_Not_Found.get(param);
                if(_OpCache_with_parameter_rm_getSid_Not_Found != null) {
                    let writeState: _ProjectionWrite_rm_getSid_Not_Found = _OpCache_with_parameter_rm_getSid_Not_Found.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_rm_getSid_Not_Found(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.rm_getSid_Not_Found(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_rm_getSid_Not_Found();
                        _OpCache_with_parameter_rm_getSid_Not_Found = _OpCache_with_parameter_rm_getSid_Not_Found.set(readState, writeState);
                        this._OpCache_rm_getSid_Not_Found = this._OpCache_rm_getSid_Not_Found.set(param, _OpCache_with_parameter_rm_getSid_Not_Found);
                    }

                } else {
                    copiedState.rm_getSid_Not_Found(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_rm_getSid_Not_Found = copiedState._update_for_rm_getSid_Not_Found();
                    _OpCache_with_parameter_rm_getSid_Not_Found = new immutable.Map().set(readState, writeState);
                    this._OpCache_rm_getSid_Not_Found = this._OpCache_rm_getSid_Not_Found.set(param, _OpCache_with_parameter_rm_getSid_Not_Found);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_in_announceResourceManager_state : _ProjectionRead__tr_in_announceResourceManager = state._projected_state_for__tr_in_announceResourceManager();
            let _trid_9 : BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>>  = this._OpCache_tr_in_announceResourceManager.get(read__tr_in_announceResourceManager_state);
            if(_trid_9 == null) {
                _trid_9 = state._tr_in_announceResourceManager();
                this._OpCache_tr_in_announceResourceManager = this._OpCache_tr_in_announceResourceManager.set(read__tr_in_announceResourceManager_state, _trid_9);
            }

            for(let param of _trid_9) {
                let _tmp_1: RESOURCEMANAGER = param.projection2();
                let _tmp_2: INTERCONNECTNODE = param.projection1();

                let copiedState: nota_v2 = state._copy();
                let readState: _ProjectionRead_in_announceResourceManager = state._projected_state_for_in_announceResourceManager();
                let _OpCache_with_parameter_in_announceResourceManager: immutable.Map = this._OpCache_in_announceResourceManager.get(param);
                if(_OpCache_with_parameter_in_announceResourceManager != null) {
                    let writeState: _ProjectionWrite_in_announceResourceManager = _OpCache_with_parameter_in_announceResourceManager.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_in_announceResourceManager(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.in_announceResourceManager(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_in_announceResourceManager();
                        _OpCache_with_parameter_in_announceResourceManager = _OpCache_with_parameter_in_announceResourceManager.set(readState, writeState);
                        this._OpCache_in_announceResourceManager = this._OpCache_in_announceResourceManager.set(param, _OpCache_with_parameter_in_announceResourceManager);
                    }

                } else {
                    copiedState.in_announceResourceManager(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_in_announceResourceManager = copiedState._update_for_in_announceResourceManager();
                    _OpCache_with_parameter_in_announceResourceManager = new immutable.Map().set(readState, writeState);
                    this._OpCache_in_announceResourceManager = this._OpCache_in_announceResourceManager.set(param, _OpCache_with_parameter_in_announceResourceManager);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_in_register_success_state : _ProjectionRead__tr_in_register_success = state._projected_state_for__tr_in_register_success();
            let _trid_10 : BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>>  = this._OpCache_tr_in_register_success.get(read__tr_in_register_success_state);
            if(_trid_10 == null) {
                _trid_10 = state._tr_in_register_success();
                this._OpCache_tr_in_register_success = this._OpCache_tr_in_register_success.set(read__tr_in_register_success_state, _trid_10);
            }

            for(let param of _trid_10) {
                let _tmp_1: SID = param.projection2();
                let _tmp_2: BTuple<INTERCONNECTNODE, SERVICE> = param.projection1();
                let _tmp_3: SERVICE = _tmp_2.projection2();
                let _tmp_4: INTERCONNECTNODE = _tmp_2.projection1();

                let copiedState: nota_v2 = state._copy();
                let readState: _ProjectionRead_in_register_success = state._projected_state_for_in_register_success();
                let _OpCache_with_parameter_in_register_success: immutable.Map = this._OpCache_in_register_success.get(param);
                if(_OpCache_with_parameter_in_register_success != null) {
                    let writeState: _ProjectionWrite_in_register_success = _OpCache_with_parameter_in_register_success.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_in_register_success(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.in_register_success(_tmp_4, _tmp_3, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_in_register_success();
                        _OpCache_with_parameter_in_register_success = _OpCache_with_parameter_in_register_success.set(readState, writeState);
                        this._OpCache_in_register_success = this._OpCache_in_register_success.set(param, _OpCache_with_parameter_in_register_success);
                    }

                } else {
                    copiedState.in_register_success(_tmp_4, _tmp_3, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_in_register_success = copiedState._update_for_in_register_success();
                    _OpCache_with_parameter_in_register_success = new immutable.Map().set(readState, writeState);
                    this._OpCache_in_register_success = this._OpCache_in_register_success.set(param, _OpCache_with_parameter_in_register_success);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_in_register_failed_state : _ProjectionRead__tr_in_register_failed = state._projected_state_for__tr_in_register_failed();
            let _trid_11 : BSet<BTuple<INTERCONNECTNODE, SERVICE>>  = this._OpCache_tr_in_register_failed.get(read__tr_in_register_failed_state);
            if(_trid_11 == null) {
                _trid_11 = state._tr_in_register_failed();
                this._OpCache_tr_in_register_failed = this._OpCache_tr_in_register_failed.set(read__tr_in_register_failed_state, _trid_11);
            }

            for(let param of _trid_11) {
                let _tmp_1: SERVICE = param.projection2();
                let _tmp_2: INTERCONNECTNODE = param.projection1();

                let copiedState: nota_v2 = state._copy();
                let readState: _ProjectionRead_in_register_failed = state._projected_state_for_in_register_failed();
                let _OpCache_with_parameter_in_register_failed: immutable.Map = this._OpCache_in_register_failed.get(param);
                if(_OpCache_with_parameter_in_register_failed != null) {
                    let writeState: _ProjectionWrite_in_register_failed = _OpCache_with_parameter_in_register_failed.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_in_register_failed(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.in_register_failed(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_in_register_failed();
                        _OpCache_with_parameter_in_register_failed = _OpCache_with_parameter_in_register_failed.set(readState, writeState);
                        this._OpCache_in_register_failed = this._OpCache_in_register_failed.set(param, _OpCache_with_parameter_in_register_failed);
                    }

                } else {
                    copiedState.in_register_failed(_tmp_2, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_in_register_failed = copiedState._update_for_in_register_failed();
                    _OpCache_with_parameter_in_register_failed = new immutable.Map().set(readState, writeState);
                    this._OpCache_in_register_failed = this._OpCache_in_register_failed.set(param, _OpCache_with_parameter_in_register_failed);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_in_requestTargetSocket_Granted_state : _ProjectionRead__tr_in_requestTargetSocket_Granted = state._projected_state_for__tr_in_requestTargetSocket_Granted();
            let _trid_12 : BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>>  = this._OpCache_tr_in_requestTargetSocket_Granted.get(read__tr_in_requestTargetSocket_Granted_state);
            if(_trid_12 == null) {
                _trid_12 = state._tr_in_requestTargetSocket_Granted();
                this._OpCache_tr_in_requestTargetSocket_Granted = this._OpCache_tr_in_requestTargetSocket_Granted.set(read__tr_in_requestTargetSocket_Granted_state, _trid_12);
            }

            for(let param of _trid_12) {
                let _tmp_1: SOCKET = param.projection2();
                let _tmp_2: BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID> = param.projection1();
                let _tmp_3: SID = _tmp_2.projection2();
                let _tmp_4: BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID> = _tmp_2.projection1();
                let _tmp_5: SID = _tmp_4.projection2();
                let _tmp_6: BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET> = _tmp_4.projection1();
                let _tmp_7: SOCKET = _tmp_6.projection2();
                let _tmp_8: BTuple<INTERCONNECTNODE, INTERCONNECTNODE> = _tmp_6.projection1();
                let _tmp_9: INTERCONNECTNODE = _tmp_8.projection2();
                let _tmp_10: INTERCONNECTNODE = _tmp_8.projection1();

                let copiedState: nota_v2 = state._copy();
                let readState: _ProjectionRead_in_requestTargetSocket_Granted = state._projected_state_for_in_requestTargetSocket_Granted();
                let _OpCache_with_parameter_in_requestTargetSocket_Granted: immutable.Map = this._OpCache_in_requestTargetSocket_Granted.get(param);
                if(_OpCache_with_parameter_in_requestTargetSocket_Granted != null) {
                    let writeState: _ProjectionWrite_in_requestTargetSocket_Granted = _OpCache_with_parameter_in_requestTargetSocket_Granted.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_in_requestTargetSocket_Granted(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.in_requestTargetSocket_Granted(_tmp_10, _tmp_9, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_in_requestTargetSocket_Granted();
                        _OpCache_with_parameter_in_requestTargetSocket_Granted = _OpCache_with_parameter_in_requestTargetSocket_Granted.set(readState, writeState);
                        this._OpCache_in_requestTargetSocket_Granted = this._OpCache_in_requestTargetSocket_Granted.set(param, _OpCache_with_parameter_in_requestTargetSocket_Granted);
                    }

                } else {
                    copiedState.in_requestTargetSocket_Granted(_tmp_10, _tmp_9, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_in_requestTargetSocket_Granted = copiedState._update_for_in_requestTargetSocket_Granted();
                    _OpCache_with_parameter_in_requestTargetSocket_Granted = new immutable.Map().set(readState, writeState);
                    this._OpCache_in_requestTargetSocket_Granted = this._OpCache_in_requestTargetSocket_Granted.set(param, _OpCache_with_parameter_in_requestTargetSocket_Granted);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_in_requestTargetSocket_NotGranted_state : _ProjectionRead__tr_in_requestTargetSocket_NotGranted = state._projected_state_for__tr_in_requestTargetSocket_NotGranted();
            let _trid_13 : BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>>  = this._OpCache_tr_in_requestTargetSocket_NotGranted.get(read__tr_in_requestTargetSocket_NotGranted_state);
            if(_trid_13 == null) {
                _trid_13 = state._tr_in_requestTargetSocket_NotGranted();
                this._OpCache_tr_in_requestTargetSocket_NotGranted = this._OpCache_tr_in_requestTargetSocket_NotGranted.set(read__tr_in_requestTargetSocket_NotGranted_state, _trid_13);
            }

            for(let param of _trid_13) {
                let _tmp_1: SID = param.projection2();
                let _tmp_2: BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID> = param.projection1();
                let _tmp_3: SID = _tmp_2.projection2();
                let _tmp_4: BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET> = _tmp_2.projection1();
                let _tmp_5: SOCKET = _tmp_4.projection2();
                let _tmp_6: BTuple<INTERCONNECTNODE, INTERCONNECTNODE> = _tmp_4.projection1();
                let _tmp_7: INTERCONNECTNODE = _tmp_6.projection2();
                let _tmp_8: INTERCONNECTNODE = _tmp_6.projection1();

                let copiedState: nota_v2 = state._copy();
                let readState: _ProjectionRead_in_requestTargetSocket_NotGranted = state._projected_state_for_in_requestTargetSocket_NotGranted();
                let _OpCache_with_parameter_in_requestTargetSocket_NotGranted: immutable.Map = this._OpCache_in_requestTargetSocket_NotGranted.get(param);
                if(_OpCache_with_parameter_in_requestTargetSocket_NotGranted != null) {
                    let writeState: _ProjectionWrite_in_requestTargetSocket_NotGranted = _OpCache_with_parameter_in_requestTargetSocket_NotGranted.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_in_requestTargetSocket_NotGranted(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.in_requestTargetSocket_NotGranted(_tmp_8, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_in_requestTargetSocket_NotGranted();
                        _OpCache_with_parameter_in_requestTargetSocket_NotGranted = _OpCache_with_parameter_in_requestTargetSocket_NotGranted.set(readState, writeState);
                        this._OpCache_in_requestTargetSocket_NotGranted = this._OpCache_in_requestTargetSocket_NotGranted.set(param, _OpCache_with_parameter_in_requestTargetSocket_NotGranted);
                    }

                } else {
                    copiedState.in_requestTargetSocket_NotGranted(_tmp_8, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_in_requestTargetSocket_NotGranted = copiedState._update_for_in_requestTargetSocket_NotGranted();
                    _OpCache_with_parameter_in_requestTargetSocket_NotGranted = new immutable.Map().set(readState, writeState);
                    this._OpCache_in_requestTargetSocket_NotGranted = this._OpCache_in_requestTargetSocket_NotGranted.set(param, _OpCache_with_parameter_in_requestTargetSocket_NotGranted);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_svc_register_state : _ProjectionRead__tr_svc_register = state._projected_state_for__tr_svc_register();
            let _trid_14 : BSet<SERVICE>  = this._OpCache_tr_svc_register.get(read__tr_svc_register_state);
            if(_trid_14 == null) {
                _trid_14 = state._tr_svc_register();
                this._OpCache_tr_svc_register = this._OpCache_tr_svc_register.set(read__tr_svc_register_state, _trid_14);
            }

            for(let param of _trid_14) {
                let _tmp_1: SERVICE = param;

                let copiedState: nota_v2 = state._copy();
                let readState: _ProjectionRead_svc_register = state._projected_state_for_svc_register();
                let _OpCache_with_parameter_svc_register: immutable.Map = this._OpCache_svc_register.get(param);
                if(_OpCache_with_parameter_svc_register != null) {
                    let writeState: _ProjectionWrite_svc_register = _OpCache_with_parameter_svc_register.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_svc_register(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.svc_register(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_svc_register();
                        _OpCache_with_parameter_svc_register = _OpCache_with_parameter_svc_register.set(readState, writeState);
                        this._OpCache_svc_register = this._OpCache_svc_register.set(param, _OpCache_with_parameter_svc_register);
                    }

                } else {
                    copiedState.svc_register(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_svc_register = copiedState._update_for_svc_register();
                    _OpCache_with_parameter_svc_register = new immutable.Map().set(readState, writeState);
                    this._OpCache_svc_register = this._OpCache_svc_register.set(param, _OpCache_with_parameter_svc_register);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        } else {
            let _trid_1: BSet<INTERCONNECTNODE> = state._tr_constructor_interconnectNode();
            for(let param of _trid_1) {
                let _tmp_1: INTERCONNECTNODE = param;

                let copiedState: nota_v2 = state._copy();
                copiedState.constructor_interconnectNode(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_2: BSet<RESOURCEMANAGER> = state._tr_constructor_resourceManager();
            for(let param of _trid_2) {
                let _tmp_1: RESOURCEMANAGER = param;

                let copiedState: nota_v2 = state._copy();
                copiedState.constructor_resourceManager(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_3: BSet<BTuple<INTERCONNECTNODE, SERVICE>> = state._tr_constructor_service();
            for(let param of _trid_3) {
                let _tmp_1: SERVICE = param.projection2();
                let _tmp_2: INTERCONNECTNODE = param.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.constructor_service(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_4: BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>> = state._tr_constructor_socket();
            for(let param of _trid_4) {
                let _tmp_1: SOCKET = param.projection2();
                let _tmp_2: BTuple<BTuple<INTERCONNECTNODE, SID>, SID> = param.projection1();
                let _tmp_3: SID = _tmp_2.projection2();
                let _tmp_4: BTuple<INTERCONNECTNODE, SID> = _tmp_2.projection1();
                let _tmp_5: SID = _tmp_4.projection2();
                let _tmp_6: INTERCONNECTNODE = _tmp_4.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.constructor_socket(_tmp_6, _tmp_5, _tmp_3, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_5: BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>> = state._tr_rm_register();
            for(let param of _trid_5) {
                let _tmp_1: INTERCONNECTNODE = param.projection2();
                let _tmp_2: BTuple<RESOURCEMANAGER, SERVICE> = param.projection1();
                let _tmp_3: SERVICE = _tmp_2.projection2();
                let _tmp_4: RESOURCEMANAGER = _tmp_2.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.rm_register(_tmp_4, _tmp_3, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_6: BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>> = state._tr_rm_deregister();
            for(let param of _trid_6) {
                let _tmp_1: INTERCONNECTNODE = param.projection2();
                let _tmp_2: BTuple<RESOURCEMANAGER, SERVICE> = param.projection1();
                let _tmp_3: SERVICE = _tmp_2.projection2();
                let _tmp_4: RESOURCEMANAGER = _tmp_2.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.rm_deregister(_tmp_4, _tmp_3, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_7: BSet<BTuple<RESOURCEMANAGER, SERVICE>> = state._tr_rm_getSid();
            for(let param of _trid_7) {
                let _tmp_1: SERVICE = param.projection2();
                let _tmp_2: RESOURCEMANAGER = param.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.rm_getSid(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_8: BSet<BTuple<RESOURCEMANAGER, SERVICE>> = state._tr_rm_getSid_Not_Found();
            for(let param of _trid_8) {
                let _tmp_1: SERVICE = param.projection2();
                let _tmp_2: RESOURCEMANAGER = param.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.rm_getSid_Not_Found(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_9: BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>> = state._tr_in_announceResourceManager();
            for(let param of _trid_9) {
                let _tmp_1: RESOURCEMANAGER = param.projection2();
                let _tmp_2: INTERCONNECTNODE = param.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.in_announceResourceManager(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_10: BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>> = state._tr_in_register_success();
            for(let param of _trid_10) {
                let _tmp_1: SID = param.projection2();
                let _tmp_2: BTuple<INTERCONNECTNODE, SERVICE> = param.projection1();
                let _tmp_3: SERVICE = _tmp_2.projection2();
                let _tmp_4: INTERCONNECTNODE = _tmp_2.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.in_register_success(_tmp_4, _tmp_3, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_11: BSet<BTuple<INTERCONNECTNODE, SERVICE>> = state._tr_in_register_failed();
            for(let param of _trid_11) {
                let _tmp_1: SERVICE = param.projection2();
                let _tmp_2: INTERCONNECTNODE = param.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.in_register_failed(_tmp_2, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_12: BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>> = state._tr_in_requestTargetSocket_Granted();
            for(let param of _trid_12) {
                let _tmp_1: SOCKET = param.projection2();
                let _tmp_2: BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID> = param.projection1();
                let _tmp_3: SID = _tmp_2.projection2();
                let _tmp_4: BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID> = _tmp_2.projection1();
                let _tmp_5: SID = _tmp_4.projection2();
                let _tmp_6: BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET> = _tmp_4.projection1();
                let _tmp_7: SOCKET = _tmp_6.projection2();
                let _tmp_8: BTuple<INTERCONNECTNODE, INTERCONNECTNODE> = _tmp_6.projection1();
                let _tmp_9: INTERCONNECTNODE = _tmp_8.projection2();
                let _tmp_10: INTERCONNECTNODE = _tmp_8.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.in_requestTargetSocket_Granted(_tmp_10, _tmp_9, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_13: BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>> = state._tr_in_requestTargetSocket_NotGranted();
            for(let param of _trid_13) {
                let _tmp_1: SID = param.projection2();
                let _tmp_2: BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID> = param.projection1();
                let _tmp_3: SID = _tmp_2.projection2();
                let _tmp_4: BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET> = _tmp_2.projection1();
                let _tmp_5: SOCKET = _tmp_4.projection2();
                let _tmp_6: BTuple<INTERCONNECTNODE, INTERCONNECTNODE> = _tmp_4.projection1();
                let _tmp_7: INTERCONNECTNODE = _tmp_6.projection2();
                let _tmp_8: INTERCONNECTNODE = _tmp_6.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.in_requestTargetSocket_NotGranted(_tmp_8, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_14: BSet<SERVICE> = state._tr_svc_register();
            for(let param of _trid_14) {
                let _tmp_1: SERVICE = param;

                let copiedState: nota_v2 = state._copy();
                copiedState.svc_register(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        }
        return result;
    }

    invViolated(state: nota_v2): boolean {
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

