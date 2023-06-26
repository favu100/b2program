import {BTuple} from './btypes/BTuple.js';
import {BInteger} from './btypes/BInteger.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BRelation} from './btypes/BRelation.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BStruct} from './btypes/BStruct.js';
import {BUtils} from "./btypes/BUtils.js";
import * as immutable from "./immutable/dist/immutable.es.js";


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

export enum Type {
    BFS,
    DFS,
    MIXED
}

export default class nota_v2 {

    parent: nota_v2;
    dependentGuard: immutable.Set<string> = immutable.Set();
    guardCache: immutable.Map = immutable.Map();
    dependentInvariant: immutable.Set<string> = immutable.Set();
    stateAccessedVia: string;



    private static _INTERCONNECTNODE: BSet<INTERCONNECTNODE> = new BSet(new INTERCONNECTNODE(enum_INTERCONNECTNODE.node1), new INTERCONNECTNODE(enum_INTERCONNECTNODE.node2));
    private static _SOCKET: BSet<SOCKET> = new BSet(new SOCKET(enum_SOCKET.socket1), new SOCKET(enum_SOCKET.socket2));
    private static _SERVICE: BSet<SERVICE> = new BSet(new SERVICE(enum_SERVICE.service1), new SERVICE(enum_SERVICE.service2));
    private static _RESOURCEMANAGER: BSet<RESOURCEMANAGER> = new BSet(new RESOURCEMANAGER(enum_RESOURCEMANAGER.resource1), new RESOURCEMANAGER(enum_RESOURCEMANAGER.resource2));
    private static _SID: BSet<SID> = new BSet(new SID(enum_SID.SID1), new SID(enum_SID.SID2));
    private static _RM_ERROR_CODES: BSet<RM_ERROR_CODES> = new BSet(new RM_ERROR_CODES(enum_RM_ERROR_CODES.RM_SERVICE_FOUND), new RM_ERROR_CODES(enum_RM_ERROR_CODES.RM_SERVICE_NOT_FOUND));
    private static _IN_ERROR_CODES: BSet<IN_ERROR_CODES> = new BSet(new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_REGISTRATION_OK), new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_REGISTRATION_FAILED), new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_DEREGISTRATION_OK), new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_DEREGISTRATION_FAILED), new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_NO_SOCKET_CONNECTION), new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_SOCKET_CONNECTION_OK), new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_NO_AVAILABLE_SERVICE), new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_SERVICE_AVAILABLE), new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_TARGET_SOCKET_GRANTED), new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_TARGET_SOCKET_NOT_GRANTED));

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

    constructor() {
        this.interconnectNodes = new BSet();
        this.sockets = new BSet();
        this.services = new BSet();
        this.resourceManagers = new BSet();
        this.sids = new BSet();
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


     constructor_interconnectNode(newic: INTERCONNECTNODE): INTERCONNECTNODE {
        let oid: INTERCONNECTNODE = null;
        if((nota_v2._INTERCONNECTNODE.difference(this.interconnectNodes).elementOf(newic)).booleanValue()) {
            let _ld_interconnectNodes: BSet<INTERCONNECTNODE> = this.interconnectNodes;

            this.interconnectNodes = _ld_interconnectNodes.union(new BSet(newic));
            this.in_resourceManager = this.in_resourceManager.override(new BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>(new BTuple<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>(newic,new BSet())));
            oid = newic;
        } 
        return oid;
    }

     constructor_resourceManager(newrm: RESOURCEMANAGER): RESOURCEMANAGER {
        let oid: RESOURCEMANAGER = null;
        let _ld_resourceManagers: BSet<RESOURCEMANAGER> = this.resourceManagers;
        this.resourceManagers = _ld_resourceManagers.union(new BSet(newrm));
        this.rm_services = this.rm_services.override(new BRelation<RESOURCEMANAGER, BSet<SERVICE>>(new BTuple<RESOURCEMANAGER, BSet<SERVICE>>(newrm,new BSet())));
        oid = newrm;
        return oid;
    }

     constructor_service(ii: INTERCONNECTNODE, newsvc: SERVICE): SERVICE {
        let oid: SERVICE = null;
        let _ld_services: BSet<SERVICE> = this.services;
        this.services = _ld_services.union(new BSet(newsvc));
        this.svc_registered = this.svc_registered.override(new BRelation<SERVICE, BBoolean>(new BTuple<SERVICE, BBoolean>(newsvc,new BBoolean(false))));
        this.svc_sockets = this.svc_sockets.override(new BRelation<SERVICE, BSet<SOCKET>>(new BTuple<SERVICE, BSet<SOCKET>>(newsvc,new BSet())));
        this.svc_ICNode = this.svc_ICNode.override(new BRelation<SERVICE, INTERCONNECTNODE>(new BTuple<SERVICE, INTERCONNECTNODE>(newsvc,ii)));
        this.svc_serviceID = new BRelation<SERVICE, SID>();
        oid = newsvc;
        return oid;
    }

     constructor_socket(ii: INTERCONNECTNODE, srcsid: SID, targsid: SID, newsoc: SOCKET): SOCKET {
        let oid: SOCKET = null;
        let _ld_sockets: BSet<SOCKET> = this.sockets;
        this.sockets = _ld_sockets.union(new BSet(newsoc));
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
        sid = new BSet(this.rm_sids.functionCall(ss));
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
        this.in_resourceManager = this.in_resourceManager.override(new BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>(new BTuple<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>(self,this.in_resourceManager.functionCall(self).union(new BSet(rm)))));
    }

     in_register_success(self: INTERCONNECTNODE, ss: SERVICE, si: SID): _Struct3 {
        let sid: BSet<SID> = null;
        let err: IN_ERROR_CODES = null;
        let _ld_in_localServices: BRelation<SID, INTERCONNECTNODE> = this.in_localServices;
        let _ld_sids: BSet<SID> = this.sids;
        this.sids = _ld_sids.union(new BSet(si));
        this.in_localServices = _ld_in_localServices.union(new BRelation<SID, INTERCONNECTNODE>(new BTuple(si, self)));
        err = new IN_ERROR_CODES(enum_IN_ERROR_CODES.IN_REGISTRATION_OK);
        sid = new BSet(si);
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
        this.sockets = _ld_sockets.union(new BSet(newsoc));
        soc = new BSet(newsoc);
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
            if((new BBoolean(this.rm_services.domain().notElementOf(_ic_newrm_1).booleanValue() && this.resourceManagers.equal(new BSet()).booleanValue())).booleanValue()) {
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
                if((this.in_resourceManager.functionCall(_ic_self_1).equal(new BSet())).booleanValue()) {
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

    _check_inv_1() {
        return this.interconnectNodes.subset(nota_v2._INTERCONNECTNODE).booleanValue();
    }

    _check_inv_2() {
        return this.sockets.subset(nota_v2._SOCKET).booleanValue();
    }

    _check_inv_3() {
        return this.services.subset(nota_v2._SERVICE).booleanValue();
    }

    _check_inv_4() {
        return this.resourceManagers.subset(nota_v2._RESOURCEMANAGER).booleanValue();
    }

    _check_inv_5() {
        return this.sids.subset(nota_v2._SID).booleanValue();
    }

    _check_inv_6() {
        return this.rm_services.checkDomain(this.resourceManagers).and(this.rm_services.checkRange(this.services.pow())).and(this.rm_services.isFunction()).and(this.rm_services.isTotal(this.resourceManagers)).booleanValue();
    }

    _check_inv_7() {
        let _ic_boolean_14: BBoolean = new BBoolean(true);
        for(let _ic_a1_1 of this.rm_services.domain()) {
            for(let _ic_a2_1 of this.rm_services.domain()) {
                if(!(new BBoolean(!_ic_a1_1.unequal(_ic_a2_1).booleanValue() || this.rm_services.functionCall(_ic_a1_1).intersect(this.rm_services.functionCall(_ic_a2_1)).equal(new BSet()).booleanValue())).booleanValue()) {
                    _ic_boolean_14 = new BBoolean(false);
                    break;
                }

            }
        }
        return _ic_boolean_14.booleanValue();
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
        return this.svc_registered.checkDomain(this.services).and(this.svc_registered.checkRange(BUtils.BOOL)).and(this.svc_registered.isFunction()).and(this.svc_registered.isTotal(this.services)).booleanValue();
    }

    _check_inv_18() {
        return new BBoolean(!this.resourceManagers.equal(new BSet()).not().booleanValue() || this.resourceManagers.card().equal(new BInteger(1)).booleanValue()).booleanValue();
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
      const _instance = new nota_v2();
      for (const key of Object.keys(this)) {
        _instance[key] = typeof this[key] === 'object' && this[key] !== null
          ? this[key]._copy?.() ?? this[key]
          : this[key];
      }
      return _instance;
    }


}


export class ModelChecker {
    private type: Type;
    private isCaching: boolean;
    private isDebug: boolean;

    private unvisitedStates: nota_v2[] = new Array();
    private states: immutable.Set<nota_v2> = new immutable.Set();
    private transitions: number = 0;

    private invariantViolated: boolean = false;
    private deadlockDetected: boolean = false;
    private counterExampleState: nota_v2 = undefined;

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
        let machine: nota_v2 = new nota_v2();
        this.states = this.states.add(machine);
        this.unvisitedStates.push(machine);

        if(this.isCaching) {
            this.initCache(machine);
        }

        while(!(this.unvisitedStates.length === 0)) {
            let state: nota_v2 = this.next();

            let nextStates: Set<nota_v2> = this.generateNextStates(state);

            for(let nextState of nextStates) {
                if(!this.states.has(nextState)) {
                    this.states = this.states.add(nextState);
                    this.unvisitedStates.push(nextState);
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

    initCache(machine: nota_v2 ): void {
        this.invariantDependency = this.invariantDependency.set("in_register_success", immutable.Set(["_check_inv_5", "_check_inv_14", "_check_inv_13", "_check_inv_8", "_check_inv_12", "_check_inv_9"]));
        this.invariantDependency = this.invariantDependency.set("in_announceResourceManager", immutable.Set(["_check_inv_11"]));
        this.invariantDependency = this.invariantDependency.set("in_requestTargetSocket_Granted", immutable.Set(["_check_inv_15", "_check_inv_2", "_check_inv_10", "_check_inv_13", "_check_inv_12"]));
        this.invariantDependency = this.invariantDependency.set("constructor_service", immutable.Set(["_check_inv_17", "_check_inv_16", "_check_inv_15", "_check_inv_3", "_check_inv_6", "_check_inv_14", "_check_inv_8"]));
        this.invariantDependency = this.invariantDependency.set("constructor_socket", immutable.Set(["_check_inv_15", "_check_inv_2", "_check_inv_10", "_check_inv_13", "_check_inv_12"]));
        this.invariantDependency = this.invariantDependency.set("in_requestTargetSocket_NotGranted", immutable.Set([]));
        this.invariantDependency = this.invariantDependency.set("constructor_interconnectNode", immutable.Set(["_check_inv_16", "_check_inv_1", "_check_inv_10", "_check_inv_9", "_check_inv_11"]));
        this.invariantDependency = this.invariantDependency.set("rm_getSid", immutable.Set([]));
        this.invariantDependency = this.invariantDependency.set("rm_deregister", immutable.Set([]));
        this.invariantDependency = this.invariantDependency.set("constructor_resourceManager", immutable.Set(["_check_inv_18", "_check_inv_6", "_check_inv_7", "_check_inv_4", "_check_inv_11"]));
        this.invariantDependency = this.invariantDependency.set("in_register_failed", immutable.Set([]));
        this.invariantDependency = this.invariantDependency.set("rm_register", immutable.Set([]));
        this.invariantDependency = this.invariantDependency.set("rm_getSid_Not_Found", immutable.Set([]));
        this.invariantDependency = this.invariantDependency.set("svc_register", immutable.Set(["_check_inv_17"]));
        this.guardDependency = this.guardDependency.set("in_register_success", immutable.Set(["_tr_in_register_success", "_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket"]));
        this.guardDependency = this.guardDependency.set("in_announceResourceManager", immutable.Set(["_tr_in_announceResourceManager"]));
        this.guardDependency = this.guardDependency.set("in_requestTargetSocket_Granted", immutable.Set(["_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket"]));
        this.guardDependency = this.guardDependency.set("constructor_service", immutable.Set(["_tr_constructor_service", "_tr_rm_getSid", "_tr_in_register_success", "_tr_svc_register", "_tr_in_register_failed", "_tr_rm_register", "_tr_rm_getSid_Not_Found", "_tr_rm_deregister"]));
        this.guardDependency = this.guardDependency.set("constructor_socket", immutable.Set(["_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket"]));
        this.guardDependency = this.guardDependency.set("in_requestTargetSocket_NotGranted", immutable.Set([]));
        this.guardDependency = this.guardDependency.set("constructor_interconnectNode", immutable.Set(["_tr_constructor_service", "_tr_in_register_success", "_tr_in_requestTargetSocket_Granted", "_tr_in_register_failed", "_tr_rm_register", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket", "_tr_rm_deregister", "_tr_constructor_interconnectNode", "_tr_in_announceResourceManager"]));
        this.guardDependency = this.guardDependency.set("rm_getSid", immutable.Set([]));
        this.guardDependency = this.guardDependency.set("rm_deregister", immutable.Set([]));
        this.guardDependency = this.guardDependency.set("constructor_resourceManager", immutable.Set(["_tr_rm_getSid", "_tr_constructor_resourceManager", "_tr_rm_register", "_tr_rm_getSid_Not_Found", "_tr_rm_deregister", "_tr_in_announceResourceManager"]));
        this.guardDependency = this.guardDependency.set("in_register_failed", immutable.Set([]));
        this.guardDependency = this.guardDependency.set("rm_register", immutable.Set([]));
        this.guardDependency = this.guardDependency.set("rm_getSid_Not_Found", immutable.Set([]));
        this.guardDependency = this.guardDependency.set("svc_register", immutable.Set(["_tr_svc_register"]));
    }

    next(): nota_v2 {
        switch(this.type) {
            case Type.BFS:
                return this.unvisitedStates.shift();
            case Type.DFS:
                return this.unvisitedStates.pop();
            case Type.MIXED:
                if(this.unvisitedStates.length % 2 == 0) {
                    return this.unvisitedStates.shift();
                } else {
                    return this.unvisitedStates.pop();
                }
            default:
                break;
        }
        return undefined;
    }

    generateNextStates(state: nota_v2): Set<nota_v2> {
        let result: immutable.Set<nota_v2> = immutable.Set();
        if(this.isCaching) {
            let parentsGuard: immutable.Map = state.guardCache;
            let newCache: immutable.Map = parentsGuard == null ? immutable.Map() : parentsGuard;
            let cachedValue: any = null;
            let dependentGuardsBoolean: boolean = true;
            let _trid_1: BSet<INTERCONNECTNODE>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_constructor_interconnectNode");
                dependentGuardsBoolean = "_tr_constructor_interconnectNode" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_1 = state._tr_constructor_interconnectNode();
            } else {
                _trid_1 = cachedValue as BSet<INTERCONNECTNODE>;
            }
            newCache = newCache.set("_tr_constructor_interconnectNode", _trid_1);
            for(let param of _trid_1) {
                let _tmp_1: INTERCONNECTNODE = param;

                let copiedState: nota_v2 = state._copy();
                copiedState.constructor_interconnectNode(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("constructor_interconnectNode", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_2: BSet<RESOURCEMANAGER>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_constructor_resourceManager");
                dependentGuardsBoolean = "_tr_constructor_resourceManager" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_2 = state._tr_constructor_resourceManager();
            } else {
                _trid_2 = cachedValue as BSet<RESOURCEMANAGER>;
            }
            newCache = newCache.set("_tr_constructor_resourceManager", _trid_2);
            for(let param of _trid_2) {
                let _tmp_1: RESOURCEMANAGER = param;

                let copiedState: nota_v2 = state._copy();
                copiedState.constructor_resourceManager(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("constructor_resourceManager", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_3: BSet<BTuple<INTERCONNECTNODE, SERVICE>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_constructor_service");
                dependentGuardsBoolean = "_tr_constructor_service" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_3 = state._tr_constructor_service();
            } else {
                _trid_3 = cachedValue as BSet<BTuple<INTERCONNECTNODE, SERVICE>>;
            }
            newCache = newCache.set("_tr_constructor_service", _trid_3);
            for(let param of _trid_3) {
                let _tmp_1: SERVICE = param.projection2();
                let _tmp_2: INTERCONNECTNODE = param.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.constructor_service(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("constructor_service", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_4: BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_constructor_socket");
                dependentGuardsBoolean = "_tr_constructor_socket" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_4 = state._tr_constructor_socket();
            } else {
                _trid_4 = cachedValue as BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>>;
            }
            newCache = newCache.set("_tr_constructor_socket", _trid_4);
            for(let param of _trid_4) {
                let _tmp_1: SOCKET = param.projection2();
                let _tmp_2: BTuple<BTuple<INTERCONNECTNODE, SID>, SID> = param.projection1();
                let _tmp_3: SID = _tmp_2.projection2();
                let _tmp_4: BTuple<INTERCONNECTNODE, SID> = _tmp_2.projection1();
                let _tmp_5: SID = _tmp_4.projection2();
                let _tmp_6: INTERCONNECTNODE = _tmp_4.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.constructor_socket(_tmp_6, _tmp_5, _tmp_3, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("constructor_socket", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_5: BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_rm_register");
                dependentGuardsBoolean = "_tr_rm_register" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_5 = state._tr_rm_register();
            } else {
                _trid_5 = cachedValue as BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>;
            }
            newCache = newCache.set("_tr_rm_register", _trid_5);
            for(let param of _trid_5) {
                let _tmp_1: INTERCONNECTNODE = param.projection2();
                let _tmp_2: BTuple<RESOURCEMANAGER, SERVICE> = param.projection1();
                let _tmp_3: SERVICE = _tmp_2.projection2();
                let _tmp_4: RESOURCEMANAGER = _tmp_2.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.rm_register(_tmp_4, _tmp_3, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("rm_register", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_6: BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_rm_deregister");
                dependentGuardsBoolean = "_tr_rm_deregister" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_6 = state._tr_rm_deregister();
            } else {
                _trid_6 = cachedValue as BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>;
            }
            newCache = newCache.set("_tr_rm_deregister", _trid_6);
            for(let param of _trid_6) {
                let _tmp_1: INTERCONNECTNODE = param.projection2();
                let _tmp_2: BTuple<RESOURCEMANAGER, SERVICE> = param.projection1();
                let _tmp_3: SERVICE = _tmp_2.projection2();
                let _tmp_4: RESOURCEMANAGER = _tmp_2.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.rm_deregister(_tmp_4, _tmp_3, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("rm_deregister", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_7: BSet<BTuple<RESOURCEMANAGER, SERVICE>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_rm_getSid");
                dependentGuardsBoolean = "_tr_rm_getSid" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_7 = state._tr_rm_getSid();
            } else {
                _trid_7 = cachedValue as BSet<BTuple<RESOURCEMANAGER, SERVICE>>;
            }
            newCache = newCache.set("_tr_rm_getSid", _trid_7);
            for(let param of _trid_7) {
                let _tmp_1: SERVICE = param.projection2();
                let _tmp_2: RESOURCEMANAGER = param.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.rm_getSid(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("rm_getSid", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_8: BSet<BTuple<RESOURCEMANAGER, SERVICE>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_rm_getSid_Not_Found");
                dependentGuardsBoolean = "_tr_rm_getSid_Not_Found" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_8 = state._tr_rm_getSid_Not_Found();
            } else {
                _trid_8 = cachedValue as BSet<BTuple<RESOURCEMANAGER, SERVICE>>;
            }
            newCache = newCache.set("_tr_rm_getSid_Not_Found", _trid_8);
            for(let param of _trid_8) {
                let _tmp_1: SERVICE = param.projection2();
                let _tmp_2: RESOURCEMANAGER = param.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.rm_getSid_Not_Found(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("rm_getSid_Not_Found", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_9: BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_in_announceResourceManager");
                dependentGuardsBoolean = "_tr_in_announceResourceManager" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_9 = state._tr_in_announceResourceManager();
            } else {
                _trid_9 = cachedValue as BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>>;
            }
            newCache = newCache.set("_tr_in_announceResourceManager", _trid_9);
            for(let param of _trid_9) {
                let _tmp_1: RESOURCEMANAGER = param.projection2();
                let _tmp_2: INTERCONNECTNODE = param.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.in_announceResourceManager(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("in_announceResourceManager", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_10: BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_in_register_success");
                dependentGuardsBoolean = "_tr_in_register_success" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_10 = state._tr_in_register_success();
            } else {
                _trid_10 = cachedValue as BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>>;
            }
            newCache = newCache.set("_tr_in_register_success", _trid_10);
            for(let param of _trid_10) {
                let _tmp_1: SID = param.projection2();
                let _tmp_2: BTuple<INTERCONNECTNODE, SERVICE> = param.projection1();
                let _tmp_3: SERVICE = _tmp_2.projection2();
                let _tmp_4: INTERCONNECTNODE = _tmp_2.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.in_register_success(_tmp_4, _tmp_3, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("in_register_success", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_11: BSet<BTuple<INTERCONNECTNODE, SERVICE>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_in_register_failed");
                dependentGuardsBoolean = "_tr_in_register_failed" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_11 = state._tr_in_register_failed();
            } else {
                _trid_11 = cachedValue as BSet<BTuple<INTERCONNECTNODE, SERVICE>>;
            }
            newCache = newCache.set("_tr_in_register_failed", _trid_11);
            for(let param of _trid_11) {
                let _tmp_1: SERVICE = param.projection2();
                let _tmp_2: INTERCONNECTNODE = param.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.in_register_failed(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("in_register_failed", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_12: BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_in_requestTargetSocket_Granted");
                dependentGuardsBoolean = "_tr_in_requestTargetSocket_Granted" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_12 = state._tr_in_requestTargetSocket_Granted();
            } else {
                _trid_12 = cachedValue as BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>>;
            }
            newCache = newCache.set("_tr_in_requestTargetSocket_Granted", _trid_12);
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
                copiedState.parent = state;
                this.addCachedInfos("in_requestTargetSocket_Granted", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_13: BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_in_requestTargetSocket_NotGranted");
                dependentGuardsBoolean = "_tr_in_requestTargetSocket_NotGranted" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_13 = state._tr_in_requestTargetSocket_NotGranted();
            } else {
                _trid_13 = cachedValue as BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>>;
            }
            newCache = newCache.set("_tr_in_requestTargetSocket_NotGranted", _trid_13);
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
                copiedState.parent = state;
                this.addCachedInfos("in_requestTargetSocket_NotGranted", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_14: BSet<SERVICE>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_svc_register");
                dependentGuardsBoolean = "_tr_svc_register" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_14 = state._tr_svc_register();
            } else {
                _trid_14 = cachedValue as BSet<SERVICE>;
            }
            newCache = newCache.set("_tr_svc_register", _trid_14);
            for(let param of _trid_14) {
                let _tmp_1: SERVICE = param;

                let copiedState: nota_v2 = state._copy();
                copiedState.svc_register(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("svc_register", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

            state.guardCache = newCache;
        } else {
            let _trid_1: BSet<INTERCONNECTNODE> = state._tr_constructor_interconnectNode();
            for(let param of _trid_1) {
                let _tmp_1: INTERCONNECTNODE = param;

                let copiedState: nota_v2 = state._copy();
                copiedState.constructor_interconnectNode(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("constructor_interconnectNode", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_2: BSet<RESOURCEMANAGER> = state._tr_constructor_resourceManager();
            for(let param of _trid_2) {
                let _tmp_1: RESOURCEMANAGER = param;

                let copiedState: nota_v2 = state._copy();
                copiedState.constructor_resourceManager(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("constructor_resourceManager", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_3: BSet<BTuple<INTERCONNECTNODE, SERVICE>> = state._tr_constructor_service();
            for(let param of _trid_3) {
                let _tmp_1: SERVICE = param.projection2();
                let _tmp_2: INTERCONNECTNODE = param.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.constructor_service(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("constructor_service", state, copiedState);
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
                copiedState.parent = state;
                this.addCachedInfos("constructor_socket", state, copiedState);
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
                copiedState.parent = state;
                this.addCachedInfos("rm_register", state, copiedState);
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
                copiedState.parent = state;
                this.addCachedInfos("rm_deregister", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_7: BSet<BTuple<RESOURCEMANAGER, SERVICE>> = state._tr_rm_getSid();
            for(let param of _trid_7) {
                let _tmp_1: SERVICE = param.projection2();
                let _tmp_2: RESOURCEMANAGER = param.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.rm_getSid(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("rm_getSid", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_8: BSet<BTuple<RESOURCEMANAGER, SERVICE>> = state._tr_rm_getSid_Not_Found();
            for(let param of _trid_8) {
                let _tmp_1: SERVICE = param.projection2();
                let _tmp_2: RESOURCEMANAGER = param.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.rm_getSid_Not_Found(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("rm_getSid_Not_Found", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_9: BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>> = state._tr_in_announceResourceManager();
            for(let param of _trid_9) {
                let _tmp_1: RESOURCEMANAGER = param.projection2();
                let _tmp_2: INTERCONNECTNODE = param.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.in_announceResourceManager(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("in_announceResourceManager", state, copiedState);
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
                copiedState.parent = state;
                this.addCachedInfos("in_register_success", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_11: BSet<BTuple<INTERCONNECTNODE, SERVICE>> = state._tr_in_register_failed();
            for(let param of _trid_11) {
                let _tmp_1: SERVICE = param.projection2();
                let _tmp_2: INTERCONNECTNODE = param.projection1();

                let copiedState: nota_v2 = state._copy();
                copiedState.in_register_failed(_tmp_2, _tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("in_register_failed", state, copiedState);
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
                copiedState.parent = state;
                this.addCachedInfos("in_requestTargetSocket_Granted", state, copiedState);
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
                copiedState.parent = state;
                this.addCachedInfos("in_requestTargetSocket_NotGranted", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_14: BSet<SERVICE> = state._tr_svc_register();
            for(let param of _trid_14) {
                let _tmp_1: SERVICE = param;

                let copiedState: nota_v2 = state._copy();
                copiedState.svc_register(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("svc_register", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        }
        return result;
    }

    invViolated(state: nota_v2): boolean {
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
        return false;
    }

    addCachedInfos(operation: string, state: nota_v2, copiedState: nota_v2): void {
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

