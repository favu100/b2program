import {BTuple} from './btypes/BTuple.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BRelation} from './btypes/BRelation.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";
import {PreconditionOrAssertionViolation} from "./btypes/BUtils.js";
import {VariantViolation} from "./btypes/BUtils.js";
import {LoopInvariantViolation} from "./btypes/BUtils.js";
import * as immutable from "./immutable/dist/immutable.es.js";
import {LinkedList} from  "./modelchecking/LinkedList.js";


export enum enum_BLOCKS {
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N
}

export class BLOCKS implements BObject{
    value: enum_BLOCKS;

    constructor(value: enum_BLOCKS) {
        this.value = value;
    }

    equal(other: BLOCKS) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: BLOCKS) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof BLOCKS)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_BLOCKS[this.value].toString();
    }

    static get_A () {return new BLOCKS(enum_BLOCKS.A);}
    static get_B () {return new BLOCKS(enum_BLOCKS.B);}
    static get_C () {return new BLOCKS(enum_BLOCKS.C);}
    static get_D () {return new BLOCKS(enum_BLOCKS.D);}
    static get_E () {return new BLOCKS(enum_BLOCKS.E);}
    static get_F () {return new BLOCKS(enum_BLOCKS.F);}
    static get_G () {return new BLOCKS(enum_BLOCKS.G);}
    static get_H () {return new BLOCKS(enum_BLOCKS.H);}
    static get_I () {return new BLOCKS(enum_BLOCKS.I);}
    static get_J () {return new BLOCKS(enum_BLOCKS.J);}
    static get_K () {return new BLOCKS(enum_BLOCKS.K);}
    static get_L () {return new BLOCKS(enum_BLOCKS.L);}
    static get_M () {return new BLOCKS(enum_BLOCKS.M);}
    static get_N () {return new BLOCKS(enum_BLOCKS.N);}


}

export enum enum_ROUTES {
    R1,
    R2,
    R3,
    R4,
    R5,
    R6,
    R7,
    R8,
    R9,
    R10
}

export class ROUTES implements BObject{
    value: enum_ROUTES;

    constructor(value: enum_ROUTES) {
        this.value = value;
    }

    equal(other: ROUTES) {
        return new BBoolean(this.value === other.value);
    }

    unequal(other: ROUTES) {
        return new BBoolean(this.value !== other.value);
    }

    equals(o: any) {
        if(!(o instanceof ROUTES)) {
            return false;
        }
        return this.value === o.value;
    }

    hashCode() {
        return (31 * 1) ^ (this.value << 1);
    }

    toString() {
        return enum_ROUTES[this.value].toString();
    }

    static get_R1 () {return new ROUTES(enum_ROUTES.R1);}
    static get_R2 () {return new ROUTES(enum_ROUTES.R2);}
    static get_R3 () {return new ROUTES(enum_ROUTES.R3);}
    static get_R4 () {return new ROUTES(enum_ROUTES.R4);}
    static get_R5 () {return new ROUTES(enum_ROUTES.R5);}
    static get_R6 () {return new ROUTES(enum_ROUTES.R6);}
    static get_R7 () {return new ROUTES(enum_ROUTES.R7);}
    static get_R8 () {return new ROUTES(enum_ROUTES.R8);}
    static get_R9 () {return new ROUTES(enum_ROUTES.R9);}
    static get_R10 () {return new ROUTES(enum_ROUTES.R10);}


}


class _ProjectionRead_route_reservation {

    public resrt: BSet<ROUTES>;
    public resbl: BSet<BLOCKS>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(resrt : BSet<ROUTES>, resbl : BSet<BLOCKS>, rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.resrt = resrt;
        this.resbl = resbl;
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_route_reservation = this;
        let o2: _ProjectionRead_route_reservation = other as _ProjectionRead_route_reservation;
        return o1.resrt.equals(o2.resrt) && o1.resbl.equals(o2.resbl) && o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.resrt.hashCode() << 1);
        result = 31 * result + (this.resbl.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_route_reservation {

    public resrt: BSet<ROUTES>;
    public resbl: BSet<BLOCKS>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(resrt : BSet<ROUTES>, resbl : BSet<BLOCKS>, rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.resrt = resrt;
        this.resbl = resbl;
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_route_reservation = this;
        let o2: _ProjectionRead__tr_route_reservation = other as _ProjectionRead__tr_route_reservation;
        return o1.resrt.equals(o2.resrt) && o1.resbl.equals(o2.resbl) && o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.resrt.hashCode() << 1);
        result = 31 * result + (this.resbl.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_route_reservation {

    public resrt: BSet<ROUTES>;
    public resbl: BSet<BLOCKS>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(resrt : BSet<ROUTES>, resbl : BSet<BLOCKS>, rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.resrt = resrt;
        this.resbl = resbl;
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_route_reservation = this;
        let o2: _ProjectionWrite_route_reservation = other as _ProjectionWrite_route_reservation;
        return o1.resrt.equals(o2.resrt) && o1.resbl.equals(o2.resbl) && o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.resrt.hashCode() << 1);
        result = 31 * result + (this.resbl.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_route_freeing {

    public frm: BSet<ROUTES>;
    public resrt: BSet<ROUTES>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(frm : BSet<ROUTES>, resrt : BSet<ROUTES>, rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.frm = frm;
        this.resrt = resrt;
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_route_freeing = this;
        let o2: _ProjectionRead_route_freeing = other as _ProjectionRead_route_freeing;
        return o1.frm.equals(o2.frm) && o1.resrt.equals(o2.resrt) && o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.frm.hashCode() << 1);
        result = 31 * result + (this.resrt.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_route_freeing {

    public resrt: BSet<ROUTES>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(resrt : BSet<ROUTES>, rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.resrt = resrt;
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_route_freeing = this;
        let o2: _ProjectionRead__tr_route_freeing = other as _ProjectionRead__tr_route_freeing;
        return o1.resrt.equals(o2.resrt) && o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.resrt.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_route_freeing {

    public frm: BSet<ROUTES>;
    public resrt: BSet<ROUTES>;

    constructor(frm : BSet<ROUTES>, resrt : BSet<ROUTES>) {
        this.frm = frm;
        this.resrt = resrt;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_route_freeing = this;
        let o2: _ProjectionWrite_route_freeing = other as _ProjectionWrite_route_freeing;
        return o1.frm.equals(o2.frm) && o1.resrt.equals(o2.resrt);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.frm.hashCode() << 1);
        result = 31 * result + (this.resrt.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_FRONT_MOVE_1 {

    public frm: BSet<ROUTES>;
    public resrt: BSet<ROUTES>;
    public resbl: BSet<BLOCKS>;
    public OCC: BSet<BLOCKS>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;
    public LBT: BSet<BLOCKS>;

    constructor(frm : BSet<ROUTES>, resrt : BSet<ROUTES>, resbl : BSet<BLOCKS>, OCC : BSet<BLOCKS>, rsrtbl : BRelation<BLOCKS, ROUTES>, LBT : BSet<BLOCKS>) {
        this.frm = frm;
        this.resrt = resrt;
        this.resbl = resbl;
        this.OCC = OCC;
        this.rsrtbl = rsrtbl;
        this.LBT = LBT;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_FRONT_MOVE_1 = this;
        let o2: _ProjectionRead_FRONT_MOVE_1 = other as _ProjectionRead_FRONT_MOVE_1;
        return o1.frm.equals(o2.frm) && o1.resrt.equals(o2.resrt) && o1.resbl.equals(o2.resbl) && o1.OCC.equals(o2.OCC) && o1.rsrtbl.equals(o2.rsrtbl) && o1.LBT.equals(o2.LBT);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.frm.hashCode() << 1);
        result = 31 * result + (this.resrt.hashCode() << 1);
        result = 31 * result + (this.resbl.hashCode() << 1);
        result = 31 * result + (this.OCC.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        result = 31 * result + (this.LBT.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_FRONT_MOVE_1 {

    public frm: BSet<ROUTES>;
    public resrt: BSet<ROUTES>;
    public resbl: BSet<BLOCKS>;
    public OCC: BSet<BLOCKS>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(frm : BSet<ROUTES>, resrt : BSet<ROUTES>, resbl : BSet<BLOCKS>, OCC : BSet<BLOCKS>, rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.frm = frm;
        this.resrt = resrt;
        this.resbl = resbl;
        this.OCC = OCC;
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_FRONT_MOVE_1 = this;
        let o2: _ProjectionRead__tr_FRONT_MOVE_1 = other as _ProjectionRead__tr_FRONT_MOVE_1;
        return o1.frm.equals(o2.frm) && o1.resrt.equals(o2.resrt) && o1.resbl.equals(o2.resbl) && o1.OCC.equals(o2.OCC) && o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.frm.hashCode() << 1);
        result = 31 * result + (this.resrt.hashCode() << 1);
        result = 31 * result + (this.resbl.hashCode() << 1);
        result = 31 * result + (this.OCC.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_FRONT_MOVE_1 {

    public OCC: BSet<BLOCKS>;
    public LBT: BSet<BLOCKS>;

    constructor(OCC : BSet<BLOCKS>, LBT : BSet<BLOCKS>) {
        this.OCC = OCC;
        this.LBT = LBT;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_FRONT_MOVE_1 = this;
        let o2: _ProjectionWrite_FRONT_MOVE_1 = other as _ProjectionWrite_FRONT_MOVE_1;
        return o1.OCC.equals(o2.OCC) && o1.LBT.equals(o2.LBT);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.OCC.hashCode() << 1);
        result = 31 * result + (this.LBT.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_FRONT_MOVE_2 {

    public TRK: BRelation<BLOCKS, BLOCKS>;
    public OCC: BSet<BLOCKS>;

    constructor(TRK : BRelation<BLOCKS, BLOCKS>, OCC : BSet<BLOCKS>) {
        this.TRK = TRK;
        this.OCC = OCC;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_FRONT_MOVE_2 = this;
        let o2: _ProjectionRead_FRONT_MOVE_2 = other as _ProjectionRead_FRONT_MOVE_2;
        return o1.TRK.equals(o2.TRK) && o1.OCC.equals(o2.OCC);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TRK.hashCode() << 1);
        result = 31 * result + (this.OCC.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_FRONT_MOVE_2 {

    public TRK: BRelation<BLOCKS, BLOCKS>;
    public OCC: BSet<BLOCKS>;

    constructor(TRK : BRelation<BLOCKS, BLOCKS>, OCC : BSet<BLOCKS>) {
        this.TRK = TRK;
        this.OCC = OCC;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_FRONT_MOVE_2 = this;
        let o2: _ProjectionRead__tr_FRONT_MOVE_2 = other as _ProjectionRead__tr_FRONT_MOVE_2;
        return o1.TRK.equals(o2.TRK) && o1.OCC.equals(o2.OCC);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TRK.hashCode() << 1);
        result = 31 * result + (this.OCC.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_FRONT_MOVE_2 {

    public OCC: BSet<BLOCKS>;

    constructor(OCC : BSet<BLOCKS>) {
        this.OCC = OCC;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_FRONT_MOVE_2 = this;
        let o2: _ProjectionWrite_FRONT_MOVE_2 = other as _ProjectionWrite_FRONT_MOVE_2;
        return o1.OCC.equals(o2.OCC);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.OCC.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_BACK_MOVE_1 {

    public resrt: BSet<ROUTES>;
    public TRK: BRelation<BLOCKS, BLOCKS>;
    public resbl: BSet<BLOCKS>;
    public OCC: BSet<BLOCKS>;
    public LBT: BSet<BLOCKS>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(resrt : BSet<ROUTES>, TRK : BRelation<BLOCKS, BLOCKS>, resbl : BSet<BLOCKS>, OCC : BSet<BLOCKS>, LBT : BSet<BLOCKS>, rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.resrt = resrt;
        this.TRK = TRK;
        this.resbl = resbl;
        this.OCC = OCC;
        this.LBT = LBT;
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_BACK_MOVE_1 = this;
        let o2: _ProjectionRead_BACK_MOVE_1 = other as _ProjectionRead_BACK_MOVE_1;
        return o1.resrt.equals(o2.resrt) && o1.TRK.equals(o2.TRK) && o1.resbl.equals(o2.resbl) && o1.OCC.equals(o2.OCC) && o1.LBT.equals(o2.LBT) && o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.resrt.hashCode() << 1);
        result = 31 * result + (this.TRK.hashCode() << 1);
        result = 31 * result + (this.resbl.hashCode() << 1);
        result = 31 * result + (this.OCC.hashCode() << 1);
        result = 31 * result + (this.LBT.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_BACK_MOVE_1 {

    public resrt: BSet<ROUTES>;
    public TRK: BRelation<BLOCKS, BLOCKS>;
    public LBT: BSet<BLOCKS>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(resrt : BSet<ROUTES>, TRK : BRelation<BLOCKS, BLOCKS>, LBT : BSet<BLOCKS>, rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.resrt = resrt;
        this.TRK = TRK;
        this.LBT = LBT;
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_BACK_MOVE_1 = this;
        let o2: _ProjectionRead__tr_BACK_MOVE_1 = other as _ProjectionRead__tr_BACK_MOVE_1;
        return o1.resrt.equals(o2.resrt) && o1.TRK.equals(o2.TRK) && o1.LBT.equals(o2.LBT) && o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.resrt.hashCode() << 1);
        result = 31 * result + (this.TRK.hashCode() << 1);
        result = 31 * result + (this.LBT.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_BACK_MOVE_1 {

    public resbl: BSet<BLOCKS>;
    public OCC: BSet<BLOCKS>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;
    public LBT: BSet<BLOCKS>;

    constructor(resbl : BSet<BLOCKS>, OCC : BSet<BLOCKS>, rsrtbl : BRelation<BLOCKS, ROUTES>, LBT : BSet<BLOCKS>) {
        this.resbl = resbl;
        this.OCC = OCC;
        this.rsrtbl = rsrtbl;
        this.LBT = LBT;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_BACK_MOVE_1 = this;
        let o2: _ProjectionWrite_BACK_MOVE_1 = other as _ProjectionWrite_BACK_MOVE_1;
        return o1.resbl.equals(o2.resbl) && o1.OCC.equals(o2.OCC) && o1.rsrtbl.equals(o2.rsrtbl) && o1.LBT.equals(o2.LBT);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.resbl.hashCode() << 1);
        result = 31 * result + (this.OCC.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        result = 31 * result + (this.LBT.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_BACK_MOVE_2 {

    public resrt: BSet<ROUTES>;
    public TRK: BRelation<BLOCKS, BLOCKS>;
    public resbl: BSet<BLOCKS>;
    public OCC: BSet<BLOCKS>;
    public LBT: BSet<BLOCKS>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(resrt : BSet<ROUTES>, TRK : BRelation<BLOCKS, BLOCKS>, resbl : BSet<BLOCKS>, OCC : BSet<BLOCKS>, LBT : BSet<BLOCKS>, rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.resrt = resrt;
        this.TRK = TRK;
        this.resbl = resbl;
        this.OCC = OCC;
        this.LBT = LBT;
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_BACK_MOVE_2 = this;
        let o2: _ProjectionRead_BACK_MOVE_2 = other as _ProjectionRead_BACK_MOVE_2;
        return o1.resrt.equals(o2.resrt) && o1.TRK.equals(o2.TRK) && o1.resbl.equals(o2.resbl) && o1.OCC.equals(o2.OCC) && o1.LBT.equals(o2.LBT) && o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.resrt.hashCode() << 1);
        result = 31 * result + (this.TRK.hashCode() << 1);
        result = 31 * result + (this.resbl.hashCode() << 1);
        result = 31 * result + (this.OCC.hashCode() << 1);
        result = 31 * result + (this.LBT.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_BACK_MOVE_2 {

    public resrt: BSet<ROUTES>;
    public TRK: BRelation<BLOCKS, BLOCKS>;
    public OCC: BSet<BLOCKS>;
    public LBT: BSet<BLOCKS>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(resrt : BSet<ROUTES>, TRK : BRelation<BLOCKS, BLOCKS>, OCC : BSet<BLOCKS>, LBT : BSet<BLOCKS>, rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.resrt = resrt;
        this.TRK = TRK;
        this.OCC = OCC;
        this.LBT = LBT;
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_BACK_MOVE_2 = this;
        let o2: _ProjectionRead__tr_BACK_MOVE_2 = other as _ProjectionRead__tr_BACK_MOVE_2;
        return o1.resrt.equals(o2.resrt) && o1.TRK.equals(o2.TRK) && o1.OCC.equals(o2.OCC) && o1.LBT.equals(o2.LBT) && o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.resrt.hashCode() << 1);
        result = 31 * result + (this.TRK.hashCode() << 1);
        result = 31 * result + (this.OCC.hashCode() << 1);
        result = 31 * result + (this.LBT.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_BACK_MOVE_2 {

    public resbl: BSet<BLOCKS>;
    public OCC: BSet<BLOCKS>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;
    public LBT: BSet<BLOCKS>;

    constructor(resbl : BSet<BLOCKS>, OCC : BSet<BLOCKS>, rsrtbl : BRelation<BLOCKS, ROUTES>, LBT : BSet<BLOCKS>) {
        this.resbl = resbl;
        this.OCC = OCC;
        this.rsrtbl = rsrtbl;
        this.LBT = LBT;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_BACK_MOVE_2 = this;
        let o2: _ProjectionWrite_BACK_MOVE_2 = other as _ProjectionWrite_BACK_MOVE_2;
        return o1.resbl.equals(o2.resbl) && o1.OCC.equals(o2.OCC) && o1.rsrtbl.equals(o2.rsrtbl) && o1.LBT.equals(o2.LBT);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.resbl.hashCode() << 1);
        result = 31 * result + (this.OCC.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        result = 31 * result + (this.LBT.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_point_positionning {

    public frm: BSet<ROUTES>;
    public resrt: BSet<ROUTES>;
    public TRK: BRelation<BLOCKS, BLOCKS>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(frm : BSet<ROUTES>, resrt : BSet<ROUTES>, TRK : BRelation<BLOCKS, BLOCKS>, rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.frm = frm;
        this.resrt = resrt;
        this.TRK = TRK;
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_point_positionning = this;
        let o2: _ProjectionRead_point_positionning = other as _ProjectionRead_point_positionning;
        return o1.frm.equals(o2.frm) && o1.resrt.equals(o2.resrt) && o1.TRK.equals(o2.TRK) && o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.frm.hashCode() << 1);
        result = 31 * result + (this.resrt.hashCode() << 1);
        result = 31 * result + (this.TRK.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_point_positionning {

    public frm: BSet<ROUTES>;
    public resrt: BSet<ROUTES>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(frm : BSet<ROUTES>, resrt : BSet<ROUTES>, rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.frm = frm;
        this.resrt = resrt;
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_point_positionning = this;
        let o2: _ProjectionRead__tr_point_positionning = other as _ProjectionRead__tr_point_positionning;
        return o1.frm.equals(o2.frm) && o1.resrt.equals(o2.resrt) && o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.frm.hashCode() << 1);
        result = 31 * result + (this.resrt.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_point_positionning {

    public TRK: BRelation<BLOCKS, BLOCKS>;

    constructor(TRK : BRelation<BLOCKS, BLOCKS>) {
        this.TRK = TRK;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_point_positionning = this;
        let o2: _ProjectionWrite_point_positionning = other as _ProjectionWrite_point_positionning;
        return o1.TRK.equals(o2.TRK);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TRK.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead_route_formation {

    public frm: BSet<ROUTES>;
    public resrt: BSet<ROUTES>;
    public TRK: BRelation<BLOCKS, BLOCKS>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(frm : BSet<ROUTES>, resrt : BSet<ROUTES>, TRK : BRelation<BLOCKS, BLOCKS>, rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.frm = frm;
        this.resrt = resrt;
        this.TRK = TRK;
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead_route_formation = this;
        let o2: _ProjectionRead_route_formation = other as _ProjectionRead_route_formation;
        return o1.frm.equals(o2.frm) && o1.resrt.equals(o2.resrt) && o1.TRK.equals(o2.TRK) && o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.frm.hashCode() << 1);
        result = 31 * result + (this.resrt.hashCode() << 1);
        result = 31 * result + (this.TRK.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__tr_route_formation {

    public frm: BSet<ROUTES>;
    public resrt: BSet<ROUTES>;
    public TRK: BRelation<BLOCKS, BLOCKS>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(frm : BSet<ROUTES>, resrt : BSet<ROUTES>, TRK : BRelation<BLOCKS, BLOCKS>, rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.frm = frm;
        this.resrt = resrt;
        this.TRK = TRK;
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__tr_route_formation = this;
        let o2: _ProjectionRead__tr_route_formation = other as _ProjectionRead__tr_route_formation;
        return o1.frm.equals(o2.frm) && o1.resrt.equals(o2.resrt) && o1.TRK.equals(o2.TRK) && o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.frm.hashCode() << 1);
        result = 31 * result + (this.resrt.hashCode() << 1);
        result = 31 * result + (this.TRK.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionWrite_route_formation {

    public frm: BSet<ROUTES>;

    constructor(frm : BSet<ROUTES>) {
        this.frm = frm;
    }

    equals(other: any): boolean {
        let o1: _ProjectionWrite_route_formation = this;
        let o2: _ProjectionWrite_route_formation = other as _ProjectionWrite_route_formation;
        return o1.frm.equals(o2.frm);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.frm.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_1 {

    public resrt: BSet<ROUTES>;
    public resbl: BSet<BLOCKS>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(resrt : BSet<ROUTES>, resbl : BSet<BLOCKS>, rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.resrt = resrt;
        this.resbl = resbl;
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_1 = this;
        let o2: _ProjectionRead__check_inv_1 = other as _ProjectionRead__check_inv_1;
        return o1.resrt.equals(o2.resrt) && o1.resbl.equals(o2.resbl) && o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.resrt.hashCode() << 1);
        result = 31 * result + (this.resbl.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_2 {

    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_2 = this;
        let o2: _ProjectionRead__check_inv_2 = other as _ProjectionRead__check_inv_2;
        return o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_3 {

    public resbl: BSet<BLOCKS>;
    public OCC: BSet<BLOCKS>;

    constructor(resbl : BSet<BLOCKS>, OCC : BSet<BLOCKS>) {
        this.resbl = resbl;
        this.OCC = OCC;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_3 = this;
        let o2: _ProjectionRead__check_inv_3 = other as _ProjectionRead__check_inv_3;
        return o1.resbl.equals(o2.resbl) && o1.OCC.equals(o2.OCC);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.resbl.hashCode() << 1);
        result = 31 * result + (this.OCC.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_4 {

    public OCC: BSet<BLOCKS>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(OCC : BSet<BLOCKS>, rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.OCC = OCC;
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_4 = this;
        let o2: _ProjectionRead__check_inv_4 = other as _ProjectionRead__check_inv_4;
        return o1.OCC.equals(o2.OCC) && o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.OCC.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_5 {

    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_5 = this;
        let o2: _ProjectionRead__check_inv_5 = other as _ProjectionRead__check_inv_5;
        return o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_6 {

    public OCC: BSet<BLOCKS>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(OCC : BSet<BLOCKS>, rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.OCC = OCC;
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_6 = this;
        let o2: _ProjectionRead__check_inv_6 = other as _ProjectionRead__check_inv_6;
        return o1.OCC.equals(o2.OCC) && o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.OCC.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_7 {

    public TRK: BRelation<BLOCKS, BLOCKS>;

    constructor(TRK : BRelation<BLOCKS, BLOCKS>) {
        this.TRK = TRK;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_7 = this;
        let o2: _ProjectionRead__check_inv_7 = other as _ProjectionRead__check_inv_7;
        return o1.TRK.equals(o2.TRK);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TRK.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_8 {

    public frm: BSet<ROUTES>;
    public resrt: BSet<ROUTES>;

    constructor(frm : BSet<ROUTES>, resrt : BSet<ROUTES>) {
        this.frm = frm;
        this.resrt = resrt;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_8 = this;
        let o2: _ProjectionRead__check_inv_8 = other as _ProjectionRead__check_inv_8;
        return o1.frm.equals(o2.frm) && o1.resrt.equals(o2.resrt);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.frm.hashCode() << 1);
        result = 31 * result + (this.resrt.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_9 {

    public frm: BSet<ROUTES>;
    public OCC: BSet<BLOCKS>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(frm : BSet<ROUTES>, OCC : BSet<BLOCKS>, rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.frm = frm;
        this.OCC = OCC;
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_9 = this;
        let o2: _ProjectionRead__check_inv_9 = other as _ProjectionRead__check_inv_9;
        return o1.frm.equals(o2.frm) && o1.OCC.equals(o2.OCC) && o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.frm.hashCode() << 1);
        result = 31 * result + (this.OCC.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_10 {

    public frm: BSet<ROUTES>;
    public resrt: BSet<ROUTES>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(frm : BSet<ROUTES>, resrt : BSet<ROUTES>, rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.frm = frm;
        this.resrt = resrt;
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_10 = this;
        let o2: _ProjectionRead__check_inv_10 = other as _ProjectionRead__check_inv_10;
        return o1.frm.equals(o2.frm) && o1.resrt.equals(o2.resrt) && o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.frm.hashCode() << 1);
        result = 31 * result + (this.resrt.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_11 {

    public TRK: BRelation<BLOCKS, BLOCKS>;

    constructor(TRK : BRelation<BLOCKS, BLOCKS>) {
        this.TRK = TRK;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_11 = this;
        let o2: _ProjectionRead__check_inv_11 = other as _ProjectionRead__check_inv_11;
        return o1.TRK.equals(o2.TRK);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.TRK.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_12 {

    public frm: BSet<ROUTES>;
    public TRK: BRelation<BLOCKS, BLOCKS>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(frm : BSet<ROUTES>, TRK : BRelation<BLOCKS, BLOCKS>, rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.frm = frm;
        this.TRK = TRK;
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_12 = this;
        let o2: _ProjectionRead__check_inv_12 = other as _ProjectionRead__check_inv_12;
        return o1.frm.equals(o2.frm) && o1.TRK.equals(o2.TRK) && o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.frm.hashCode() << 1);
        result = 31 * result + (this.TRK.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_13 {

    public OCC: BSet<BLOCKS>;
    public LBT: BSet<BLOCKS>;

    constructor(OCC : BSet<BLOCKS>, LBT : BSet<BLOCKS>) {
        this.OCC = OCC;
        this.LBT = LBT;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_13 = this;
        let o2: _ProjectionRead__check_inv_13 = other as _ProjectionRead__check_inv_13;
        return o1.OCC.equals(o2.OCC) && o1.LBT.equals(o2.LBT);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.OCC.hashCode() << 1);
        result = 31 * result + (this.LBT.hashCode() << 1);
        return result;
    }
}


class _ProjectionRead__check_inv_14 {

    public LBT: BSet<BLOCKS>;
    public rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor(LBT : BSet<BLOCKS>, rsrtbl : BRelation<BLOCKS, ROUTES>) {
        this.LBT = LBT;
        this.rsrtbl = rsrtbl;
    }

    equals(other: any): boolean {
        let o1: _ProjectionRead__check_inv_14 = this;
        let o2: _ProjectionRead__check_inv_14 = other as _ProjectionRead__check_inv_14;
        return o1.LBT.equals(o2.LBT) && o1.rsrtbl.equals(o2.rsrtbl);
    }

    hashCode(): number {
        let result: number = 1;
        result = 31 * result + (this.LBT.hashCode() << 1);
        result = 31 * result + (this.rsrtbl.hashCode() << 1);
        return result;
    }
}


export enum Type {
    BFS,
    DFS,
    MIXED
}

export default class Train_1_beebook_deterministic_MC_POR_v3 {

    parent: Train_1_beebook_deterministic_MC_POR_v3;
    stateAccessedVia: string;


    private static fst: BRelation<ROUTES, BLOCKS>;
    private static lst: BRelation<ROUTES, BLOCKS>;
    private static nxt: BRelation<ROUTES, BRelation<BLOCKS, BLOCKS>>;
    private static rtbl: BRelation<BLOCKS, ROUTES>;
    private static __aux_constant_1: BRelation<ROUTES, BLOCKS>;

    private static _BLOCKS: BSet<BLOCKS> = new BSet<BLOCKS>(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.C), new BLOCKS(enum_BLOCKS.D), new BLOCKS(enum_BLOCKS.E), new BLOCKS(enum_BLOCKS.F), new BLOCKS(enum_BLOCKS.G), new BLOCKS(enum_BLOCKS.H), new BLOCKS(enum_BLOCKS.I), new BLOCKS(enum_BLOCKS.J), new BLOCKS(enum_BLOCKS.K), new BLOCKS(enum_BLOCKS.L), new BLOCKS(enum_BLOCKS.M), new BLOCKS(enum_BLOCKS.N));
    private static _ROUTES: BSet<ROUTES> = new BSet<ROUTES>(new ROUTES(enum_ROUTES.R1), new ROUTES(enum_ROUTES.R2), new ROUTES(enum_ROUTES.R3), new ROUTES(enum_ROUTES.R4), new ROUTES(enum_ROUTES.R5), new ROUTES(enum_ROUTES.R6), new ROUTES(enum_ROUTES.R7), new ROUTES(enum_ROUTES.R8), new ROUTES(enum_ROUTES.R9), new ROUTES(enum_ROUTES.R10));

    private LBT: BSet<BLOCKS>;
    private TRK: BRelation<BLOCKS, BLOCKS>;
    private frm: BSet<ROUTES>;
    private OCC: BSet<BLOCKS>;
    private resbl: BSet<BLOCKS>;
    private resrt: BSet<ROUTES>;
    private rsrtbl: BRelation<BLOCKS, ROUTES>;

    static {
        Train_1_beebook_deterministic_MC_POR_v3.fst = new BRelation<ROUTES, BLOCKS>(new BTuple(new ROUTES(enum_ROUTES.R1), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R2), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R3), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R4), new BLOCKS(enum_BLOCKS.M)), new BTuple(new ROUTES(enum_ROUTES.R5), new BLOCKS(enum_BLOCKS.M)), new BTuple(new ROUTES(enum_ROUTES.R6), new BLOCKS(enum_BLOCKS.C)), new BTuple(new ROUTES(enum_ROUTES.R7), new BLOCKS(enum_BLOCKS.G)), new BTuple(new ROUTES(enum_ROUTES.R8), new BLOCKS(enum_BLOCKS.N)), new BTuple(new ROUTES(enum_ROUTES.R9), new BLOCKS(enum_BLOCKS.G)), new BTuple(new ROUTES(enum_ROUTES.R10), new BLOCKS(enum_BLOCKS.N)));
        Train_1_beebook_deterministic_MC_POR_v3.lst = new BRelation<ROUTES, BLOCKS>(new BTuple(new ROUTES(enum_ROUTES.R1), new BLOCKS(enum_BLOCKS.C)), new BTuple(new ROUTES(enum_ROUTES.R2), new BLOCKS(enum_BLOCKS.G)), new BTuple(new ROUTES(enum_ROUTES.R3), new BLOCKS(enum_BLOCKS.N)), new BTuple(new ROUTES(enum_ROUTES.R4), new BLOCKS(enum_BLOCKS.G)), new BTuple(new ROUTES(enum_ROUTES.R5), new BLOCKS(enum_BLOCKS.N)), new BTuple(new ROUTES(enum_ROUTES.R6), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R7), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R8), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R9), new BLOCKS(enum_BLOCKS.M)), new BTuple(new ROUTES(enum_ROUTES.R10), new BLOCKS(enum_BLOCKS.M)));
        Train_1_beebook_deterministic_MC_POR_v3.nxt = new BRelation<ROUTES, BRelation<BLOCKS, BLOCKS>>(new BTuple(new ROUTES(enum_ROUTES.R1), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.L), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.C)))), new BTuple(new ROUTES(enum_ROUTES.R2), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.L), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.D)), new BTuple(new BLOCKS(enum_BLOCKS.D), new BLOCKS(enum_BLOCKS.E)), new BTuple(new BLOCKS(enum_BLOCKS.E), new BLOCKS(enum_BLOCKS.F)), new BTuple(new BLOCKS(enum_BLOCKS.F), new BLOCKS(enum_BLOCKS.G)))), new BTuple(new ROUTES(enum_ROUTES.R3), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.L), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.D)), new BTuple(new BLOCKS(enum_BLOCKS.D), new BLOCKS(enum_BLOCKS.K)), new BTuple(new BLOCKS(enum_BLOCKS.K), new BLOCKS(enum_BLOCKS.J)), new BTuple(new BLOCKS(enum_BLOCKS.J), new BLOCKS(enum_BLOCKS.N)))), new BTuple(new ROUTES(enum_ROUTES.R4), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.M), new BLOCKS(enum_BLOCKS.H)), new BTuple(new BLOCKS(enum_BLOCKS.H), new BLOCKS(enum_BLOCKS.I)), new BTuple(new BLOCKS(enum_BLOCKS.I), new BLOCKS(enum_BLOCKS.K)), new BTuple(new BLOCKS(enum_BLOCKS.K), new BLOCKS(enum_BLOCKS.F)), new BTuple(new BLOCKS(enum_BLOCKS.F), new BLOCKS(enum_BLOCKS.G)))), new BTuple(new ROUTES(enum_ROUTES.R5), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.M), new BLOCKS(enum_BLOCKS.H)), new BTuple(new BLOCKS(enum_BLOCKS.H), new BLOCKS(enum_BLOCKS.I)), new BTuple(new BLOCKS(enum_BLOCKS.I), new BLOCKS(enum_BLOCKS.J)), new BTuple(new BLOCKS(enum_BLOCKS.J), new BLOCKS(enum_BLOCKS.N)))), new BTuple(new ROUTES(enum_ROUTES.R6), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.C), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.L)))), new BTuple(new ROUTES(enum_ROUTES.R7), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.G), new BLOCKS(enum_BLOCKS.F)), new BTuple(new BLOCKS(enum_BLOCKS.F), new BLOCKS(enum_BLOCKS.E)), new BTuple(new BLOCKS(enum_BLOCKS.E), new BLOCKS(enum_BLOCKS.D)), new BTuple(new BLOCKS(enum_BLOCKS.D), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.L)))), new BTuple(new ROUTES(enum_ROUTES.R8), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.N), new BLOCKS(enum_BLOCKS.J)), new BTuple(new BLOCKS(enum_BLOCKS.J), new BLOCKS(enum_BLOCKS.K)), new BTuple(new BLOCKS(enum_BLOCKS.K), new BLOCKS(enum_BLOCKS.D)), new BTuple(new BLOCKS(enum_BLOCKS.D), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.L)))), new BTuple(new ROUTES(enum_ROUTES.R9), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.G), new BLOCKS(enum_BLOCKS.F)), new BTuple(new BLOCKS(enum_BLOCKS.F), new BLOCKS(enum_BLOCKS.K)), new BTuple(new BLOCKS(enum_BLOCKS.K), new BLOCKS(enum_BLOCKS.I)), new BTuple(new BLOCKS(enum_BLOCKS.I), new BLOCKS(enum_BLOCKS.H)), new BTuple(new BLOCKS(enum_BLOCKS.H), new BLOCKS(enum_BLOCKS.M)))), new BTuple(new ROUTES(enum_ROUTES.R10), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.N), new BLOCKS(enum_BLOCKS.J)), new BTuple(new BLOCKS(enum_BLOCKS.J), new BLOCKS(enum_BLOCKS.I)), new BTuple(new BLOCKS(enum_BLOCKS.I), new BLOCKS(enum_BLOCKS.H)), new BTuple(new BLOCKS(enum_BLOCKS.H), new BLOCKS(enum_BLOCKS.M)))));
        let _ic_set_0: BRelation<BLOCKS, ROUTES> = new BRelation<BLOCKS, ROUTES>();
        for(let _ic_b_1 of Train_1_beebook_deterministic_MC_POR_v3._BLOCKS) {
            for(let _ic_r_1 of Train_1_beebook_deterministic_MC_POR_v3._ROUTES) {
                if((new BBoolean(Train_1_beebook_deterministic_MC_POR_v3.nxt.isInDomain(_ic_r_1).booleanValue() && new BBoolean(Train_1_beebook_deterministic_MC_POR_v3.nxt.functionCall(_ic_r_1).isInDomain(_ic_b_1).booleanValue() || Train_1_beebook_deterministic_MC_POR_v3.nxt.functionCall(_ic_r_1).isInRange(_ic_b_1).booleanValue()).booleanValue())).booleanValue()) {
                    _ic_set_0 = _ic_set_0.union(new BRelation<BLOCKS, ROUTES>(new BTuple(_ic_b_1, _ic_r_1)));
                }

            }

        }

        Train_1_beebook_deterministic_MC_POR_v3.rtbl = _ic_set_0;
        Train_1_beebook_deterministic_MC_POR_v3.__aux_constant_1 = Train_1_beebook_deterministic_MC_POR_v3.rtbl.inverse();
        let _ic_boolean_1: BBoolean = new BBoolean(true);
        if(new BBoolean(new BBoolean(Train_1_beebook_deterministic_MC_POR_v3.rtbl.domain().equal(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.rtbl.range().equal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.nxt.domain().equal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).booleanValue()).booleanValue()) {
            for(let _ic__opt_1_1 of Train_1_beebook_deterministic_MC_POR_v3.nxt.range()) {
                if(!(_ic__opt_1_1.checkDomain(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS).and(_ic__opt_1_1.checkRange(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS)).and(_ic__opt_1_1.isFunction()).and(_ic__opt_1_1.isPartial(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS)).and(_ic__opt_1_1.isInjection())).booleanValue()) {
                    _ic_boolean_1 = new BBoolean(false);
                    break;
                }

            }
        }

        let _ic_boolean_2: BBoolean = new BBoolean(true);
        if(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(Train_1_beebook_deterministic_MC_POR_v3.rtbl.domain().equal(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.rtbl.range().equal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.nxt.domain().equal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).booleanValue()).booleanValue() && _ic_boolean_1.booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.fst.checkDomain(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).and(Train_1_beebook_deterministic_MC_POR_v3.fst.checkRange(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS)).and(Train_1_beebook_deterministic_MC_POR_v3.fst.isFunction()).and(Train_1_beebook_deterministic_MC_POR_v3.fst.isTotal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES)).booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.lst.checkDomain(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).and(Train_1_beebook_deterministic_MC_POR_v3.lst.checkRange(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS)).and(Train_1_beebook_deterministic_MC_POR_v3.lst.isFunction()).and(Train_1_beebook_deterministic_MC_POR_v3.lst.isTotal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES)).booleanValue()).booleanValue()) {
            for(let _ic__opt_2_1 of Train_1_beebook_deterministic_MC_POR_v3.fst.inverse()) {
                if(!(Train_1_beebook_deterministic_MC_POR_v3.rtbl.elementOf(_ic__opt_2_1)).booleanValue()) {
                    _ic_boolean_2 = new BBoolean(false);
                    break;
                }

            }
        }

        let _ic_boolean_3: BBoolean = new BBoolean(true);
        if(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(Train_1_beebook_deterministic_MC_POR_v3.rtbl.domain().equal(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.rtbl.range().equal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.nxt.domain().equal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).booleanValue()).booleanValue() && _ic_boolean_1.booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.fst.checkDomain(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).and(Train_1_beebook_deterministic_MC_POR_v3.fst.checkRange(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS)).and(Train_1_beebook_deterministic_MC_POR_v3.fst.isFunction()).and(Train_1_beebook_deterministic_MC_POR_v3.fst.isTotal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES)).booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.lst.checkDomain(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).and(Train_1_beebook_deterministic_MC_POR_v3.lst.checkRange(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS)).and(Train_1_beebook_deterministic_MC_POR_v3.lst.isFunction()).and(Train_1_beebook_deterministic_MC_POR_v3.lst.isTotal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES)).booleanValue()).booleanValue() && _ic_boolean_2.booleanValue()).booleanValue()) {
            for(let _ic__opt_3_1 of Train_1_beebook_deterministic_MC_POR_v3.lst.inverse()) {
                if(!(Train_1_beebook_deterministic_MC_POR_v3.rtbl.elementOf(_ic__opt_3_1)).booleanValue()) {
                    _ic_boolean_3 = new BBoolean(false);
                    break;
                }

            }
        }

        let _ic_boolean_4: BBoolean = new BBoolean(true);
        if(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(Train_1_beebook_deterministic_MC_POR_v3.rtbl.domain().equal(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.rtbl.range().equal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.nxt.domain().equal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).booleanValue()).booleanValue() && _ic_boolean_1.booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.fst.checkDomain(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).and(Train_1_beebook_deterministic_MC_POR_v3.fst.checkRange(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS)).and(Train_1_beebook_deterministic_MC_POR_v3.fst.isFunction()).and(Train_1_beebook_deterministic_MC_POR_v3.fst.isTotal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES)).booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.lst.checkDomain(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).and(Train_1_beebook_deterministic_MC_POR_v3.lst.checkRange(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS)).and(Train_1_beebook_deterministic_MC_POR_v3.lst.isFunction()).and(Train_1_beebook_deterministic_MC_POR_v3.lst.isTotal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES)).booleanValue()).booleanValue() && _ic_boolean_2.booleanValue()).booleanValue() && _ic_boolean_3.booleanValue()).booleanValue()) {
            for(let _ic_r_1 of Train_1_beebook_deterministic_MC_POR_v3._ROUTES) {
                if(!(Train_1_beebook_deterministic_MC_POR_v3.fst.functionCall(_ic_r_1).unequal(Train_1_beebook_deterministic_MC_POR_v3.lst.functionCall(_ic_r_1))).booleanValue()) {
                    _ic_boolean_4 = new BBoolean(false);
                    break;
                }

            }
        }

        let _ic_boolean_6: BBoolean = new BBoolean(true);
        if(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(Train_1_beebook_deterministic_MC_POR_v3.rtbl.domain().equal(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.rtbl.range().equal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.nxt.domain().equal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).booleanValue()).booleanValue() && _ic_boolean_1.booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.fst.checkDomain(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).and(Train_1_beebook_deterministic_MC_POR_v3.fst.checkRange(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS)).and(Train_1_beebook_deterministic_MC_POR_v3.fst.isFunction()).and(Train_1_beebook_deterministic_MC_POR_v3.fst.isTotal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES)).booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.lst.checkDomain(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).and(Train_1_beebook_deterministic_MC_POR_v3.lst.checkRange(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS)).and(Train_1_beebook_deterministic_MC_POR_v3.lst.isFunction()).and(Train_1_beebook_deterministic_MC_POR_v3.lst.isTotal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES)).booleanValue()).booleanValue() && _ic_boolean_2.booleanValue()).booleanValue() && _ic_boolean_3.booleanValue()).booleanValue() && _ic_boolean_4.booleanValue()).booleanValue()) {
            for(let _ic_r_1 of Train_1_beebook_deterministic_MC_POR_v3._ROUTES) {
                let _ic_boolean_5: BBoolean = new BBoolean(true);
                for(let _ic_S_1 of Train_1_beebook_deterministic_MC_POR_v3.nxt.functionCall(_ic_r_1).range().pow()) {
                    if(!(new BBoolean(!_ic_S_1.subset(Train_1_beebook_deterministic_MC_POR_v3.nxt.functionCall(_ic_r_1).relationImage(_ic_S_1)).booleanValue() || _ic_S_1.equal(new BSet<BLOCKS>()).booleanValue())).booleanValue()) {
                        _ic_boolean_5 = new BBoolean(false);
                        break;
                    }

                }

                if(!(_ic_boolean_5).booleanValue()) {
                    _ic_boolean_6 = new BBoolean(false);
                    break;
                }

            }
        }

        let _ic_boolean_7: BBoolean = new BBoolean(true);
        if(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(Train_1_beebook_deterministic_MC_POR_v3.rtbl.domain().equal(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.rtbl.range().equal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.nxt.domain().equal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).booleanValue()).booleanValue() && _ic_boolean_1.booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.fst.checkDomain(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).and(Train_1_beebook_deterministic_MC_POR_v3.fst.checkRange(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS)).and(Train_1_beebook_deterministic_MC_POR_v3.fst.isFunction()).and(Train_1_beebook_deterministic_MC_POR_v3.fst.isTotal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES)).booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.lst.checkDomain(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).and(Train_1_beebook_deterministic_MC_POR_v3.lst.checkRange(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS)).and(Train_1_beebook_deterministic_MC_POR_v3.lst.isFunction()).and(Train_1_beebook_deterministic_MC_POR_v3.lst.isTotal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES)).booleanValue()).booleanValue() && _ic_boolean_2.booleanValue()).booleanValue() && _ic_boolean_3.booleanValue()).booleanValue() && _ic_boolean_4.booleanValue()).booleanValue() && _ic_boolean_6.booleanValue()).booleanValue()) {
            for(let _ic_r_1 of Train_1_beebook_deterministic_MC_POR_v3._ROUTES) {
                if(!(Train_1_beebook_deterministic_MC_POR_v3.nxt.functionCall(_ic_r_1).checkDomain(Train_1_beebook_deterministic_MC_POR_v3.rtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)).difference(new BSet<BLOCKS>(Train_1_beebook_deterministic_MC_POR_v3.lst.functionCall(_ic_r_1)))).and(Train_1_beebook_deterministic_MC_POR_v3.nxt.functionCall(_ic_r_1).checkRange(Train_1_beebook_deterministic_MC_POR_v3.rtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)).difference(new BSet<BLOCKS>(Train_1_beebook_deterministic_MC_POR_v3.fst.functionCall(_ic_r_1))))).and(Train_1_beebook_deterministic_MC_POR_v3.nxt.functionCall(_ic_r_1).isFunction()).and(Train_1_beebook_deterministic_MC_POR_v3.nxt.functionCall(_ic_r_1).isTotal(Train_1_beebook_deterministic_MC_POR_v3.rtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)).difference(new BSet<BLOCKS>(Train_1_beebook_deterministic_MC_POR_v3.lst.functionCall(_ic_r_1))))).and(Train_1_beebook_deterministic_MC_POR_v3.nxt.functionCall(_ic_r_1).isBijection(Train_1_beebook_deterministic_MC_POR_v3.rtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)).difference(new BSet<BLOCKS>(Train_1_beebook_deterministic_MC_POR_v3.fst.functionCall(_ic_r_1)))))).booleanValue()) {
                    _ic_boolean_7 = new BBoolean(false);
                    break;
                }

            }
        }

        let _ic_boolean_8: BBoolean = new BBoolean(true);
        if(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(Train_1_beebook_deterministic_MC_POR_v3.rtbl.domain().equal(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.rtbl.range().equal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.nxt.domain().equal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).booleanValue()).booleanValue() && _ic_boolean_1.booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.fst.checkDomain(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).and(Train_1_beebook_deterministic_MC_POR_v3.fst.checkRange(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS)).and(Train_1_beebook_deterministic_MC_POR_v3.fst.isFunction()).and(Train_1_beebook_deterministic_MC_POR_v3.fst.isTotal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES)).booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.lst.checkDomain(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).and(Train_1_beebook_deterministic_MC_POR_v3.lst.checkRange(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS)).and(Train_1_beebook_deterministic_MC_POR_v3.lst.isFunction()).and(Train_1_beebook_deterministic_MC_POR_v3.lst.isTotal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES)).booleanValue()).booleanValue() && _ic_boolean_2.booleanValue()).booleanValue() && _ic_boolean_3.booleanValue()).booleanValue() && _ic_boolean_4.booleanValue()).booleanValue() && _ic_boolean_6.booleanValue()).booleanValue() && _ic_boolean_7.booleanValue()).booleanValue()) {
            for(let _ic_r_1 of Train_1_beebook_deterministic_MC_POR_v3._ROUTES) {
                for(let _ic_s_1 of Train_1_beebook_deterministic_MC_POR_v3._ROUTES) {
                    if(!(new BBoolean(!_ic_r_1.unequal(_ic_s_1).booleanValue() || new BBoolean(new BSet<BLOCKS>(Train_1_beebook_deterministic_MC_POR_v3.fst.functionCall(_ic_s_1), Train_1_beebook_deterministic_MC_POR_v3.lst.functionCall(_ic_s_1)).elementOf(Train_1_beebook_deterministic_MC_POR_v3.fst.functionCall(_ic_r_1)).booleanValue() || Train_1_beebook_deterministic_MC_POR_v3.rtbl.inverse().isNotInRelationalImage(Train_1_beebook_deterministic_MC_POR_v3.fst.functionCall(_ic_r_1), new BSet<ROUTES>(_ic_s_1)).booleanValue()).booleanValue())).booleanValue()) {
                        _ic_boolean_8 = new BBoolean(false);
                        break;
                    }

                }

            }
        }

        let _ic_boolean_9: BBoolean = new BBoolean(true);
        if(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(Train_1_beebook_deterministic_MC_POR_v3.rtbl.domain().equal(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.rtbl.range().equal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.nxt.domain().equal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).booleanValue()).booleanValue() && _ic_boolean_1.booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.fst.checkDomain(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).and(Train_1_beebook_deterministic_MC_POR_v3.fst.checkRange(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS)).and(Train_1_beebook_deterministic_MC_POR_v3.fst.isFunction()).and(Train_1_beebook_deterministic_MC_POR_v3.fst.isTotal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES)).booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.lst.checkDomain(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).and(Train_1_beebook_deterministic_MC_POR_v3.lst.checkRange(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS)).and(Train_1_beebook_deterministic_MC_POR_v3.lst.isFunction()).and(Train_1_beebook_deterministic_MC_POR_v3.lst.isTotal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES)).booleanValue()).booleanValue() && _ic_boolean_2.booleanValue()).booleanValue() && _ic_boolean_3.booleanValue()).booleanValue() && _ic_boolean_4.booleanValue()).booleanValue() && _ic_boolean_6.booleanValue()).booleanValue() && _ic_boolean_7.booleanValue()).booleanValue() && _ic_boolean_8.booleanValue()).booleanValue()) {
            for(let _ic_r_1 of Train_1_beebook_deterministic_MC_POR_v3._ROUTES) {
                for(let _ic_s_1 of Train_1_beebook_deterministic_MC_POR_v3._ROUTES) {
                    if(!(new BBoolean(!_ic_r_1.unequal(_ic_s_1).booleanValue() || new BBoolean(new BSet<BLOCKS>(Train_1_beebook_deterministic_MC_POR_v3.fst.functionCall(_ic_s_1), Train_1_beebook_deterministic_MC_POR_v3.lst.functionCall(_ic_s_1)).elementOf(Train_1_beebook_deterministic_MC_POR_v3.lst.functionCall(_ic_r_1)).booleanValue() || Train_1_beebook_deterministic_MC_POR_v3.rtbl.inverse().isNotInRelationalImage(Train_1_beebook_deterministic_MC_POR_v3.lst.functionCall(_ic_r_1), new BSet<ROUTES>(_ic_s_1)).booleanValue()).booleanValue())).booleanValue()) {
                        _ic_boolean_9 = new BBoolean(false);
                        break;
                    }

                }

            }
        }

        if(!(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(Train_1_beebook_deterministic_MC_POR_v3.rtbl.domain().equal(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.rtbl.range().equal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.nxt.domain().equal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).booleanValue()).booleanValue() && _ic_boolean_1.booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.fst.checkDomain(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).and(Train_1_beebook_deterministic_MC_POR_v3.fst.checkRange(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS)).and(Train_1_beebook_deterministic_MC_POR_v3.fst.isFunction()).and(Train_1_beebook_deterministic_MC_POR_v3.fst.isTotal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES)).booleanValue()).booleanValue() && Train_1_beebook_deterministic_MC_POR_v3.lst.checkDomain(Train_1_beebook_deterministic_MC_POR_v3._ROUTES).and(Train_1_beebook_deterministic_MC_POR_v3.lst.checkRange(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS)).and(Train_1_beebook_deterministic_MC_POR_v3.lst.isFunction()).and(Train_1_beebook_deterministic_MC_POR_v3.lst.isTotal(Train_1_beebook_deterministic_MC_POR_v3._ROUTES)).booleanValue()).booleanValue() && _ic_boolean_2.booleanValue()).booleanValue() && _ic_boolean_3.booleanValue()).booleanValue() && _ic_boolean_4.booleanValue()).booleanValue() && _ic_boolean_6.booleanValue()).booleanValue() && _ic_boolean_7.booleanValue()).booleanValue() && _ic_boolean_8.booleanValue()).booleanValue() && _ic_boolean_9.booleanValue())).booleanValue()) {
            throw new Error("Contradiction in PROPERTIES detected!");
        }
    }

    constructor(copy? : Train_1_beebook_deterministic_MC_POR_v3) {
        if(copy) {
            this.LBT = copy.LBT;
            this.TRK = copy.TRK;
            this.frm = copy.frm;
            this.OCC = copy.OCC;
            this.resbl = copy.resbl;
            this.resrt = copy.resrt;
            this.rsrtbl = copy.rsrtbl;
        } else {
            this.resrt = new BSet<ROUTES>();
            this.resbl = new BSet<BLOCKS>();
            this.rsrtbl = new BRelation<BLOCKS, ROUTES>();
            this.OCC = new BSet<BLOCKS>();
            this.TRK = new BRelation<BLOCKS, BLOCKS>();
            this.frm = new BSet<ROUTES>();
            this.LBT = new BSet<BLOCKS>();
        }
    }



    route_reservation(r: ROUTES): void {
        let _ld_resrt: BSet<ROUTES> = this.resrt;

        let _ld_rsrtbl: BRelation<BLOCKS, ROUTES> = this.rsrtbl;
        let _ld_resbl: BSet<BLOCKS> = this.resbl;
        this.resrt = _ld_resrt.union(new BSet<ROUTES>(r));
        this.rsrtbl = _ld_rsrtbl.union(Train_1_beebook_deterministic_MC_POR_v3.rtbl.rangeRestriction(new BSet<ROUTES>(r)));
        this.resbl = _ld_resbl.union(Train_1_beebook_deterministic_MC_POR_v3.__aux_constant_1.relationImage(new BSet<ROUTES>(r)));

    }

    route_freeing(r: ROUTES): void {
        let _ld_resrt: BSet<ROUTES> = this.resrt;

        let _ld_frm: BSet<ROUTES> = this.frm;
        this.resrt = _ld_resrt.difference(new BSet<ROUTES>(r));
        this.frm = _ld_frm.difference(new BSet<ROUTES>(r));

    }

    FRONT_MOVE_1(r: ROUTES): void {
        let _ld_OCC: BSet<BLOCKS> = this.OCC;
        let _ld_LBT: BSet<BLOCKS> = this.LBT;
        this.OCC = _ld_OCC.union(new BSet<BLOCKS>(Train_1_beebook_deterministic_MC_POR_v3.fst.functionCall(r)));
        this.LBT = _ld_LBT.union(new BSet<BLOCKS>(Train_1_beebook_deterministic_MC_POR_v3.fst.functionCall(r)));

    }

    FRONT_MOVE_2(b: BLOCKS): void {
        this.OCC = this.OCC.union(new BSet<BLOCKS>(this.TRK.functionCall(b)));

    }

    BACK_MOVE_1(b: BLOCKS): void {
        let _ld_OCC: BSet<BLOCKS> = this.OCC;
        let _ld_rsrtbl: BRelation<BLOCKS, ROUTES> = this.rsrtbl;
        let _ld_resbl: BSet<BLOCKS> = this.resbl;
        let _ld_LBT: BSet<BLOCKS> = this.LBT;
        this.OCC = _ld_OCC.difference(new BSet<BLOCKS>(b));
        this.rsrtbl = _ld_rsrtbl.domainSubstraction(new BSet<BLOCKS>(b));
        this.resbl = _ld_resbl.difference(new BSet<BLOCKS>(b));
        this.LBT = _ld_LBT.difference(new BSet<BLOCKS>(b));

    }

    BACK_MOVE_2(b: BLOCKS): void {
        let _ld_OCC: BSet<BLOCKS> = this.OCC;
        let _ld_rsrtbl: BRelation<BLOCKS, ROUTES> = this.rsrtbl;
        let _ld_resbl: BSet<BLOCKS> = this.resbl;
        let _ld_LBT: BSet<BLOCKS> = this.LBT;
        this.OCC = _ld_OCC.difference(new BSet<BLOCKS>(b));
        this.rsrtbl = _ld_rsrtbl.domainSubstraction(new BSet<BLOCKS>(b));
        this.resbl = _ld_resbl.difference(new BSet<BLOCKS>(b));
        this.LBT = _ld_LBT.difference(new BSet<BLOCKS>(b)).union(new BSet<BLOCKS>(this.TRK.functionCall(b)));

    }

    point_positionning(r: ROUTES): void {
        this.TRK = this.TRK.domainSubstraction(Train_1_beebook_deterministic_MC_POR_v3.nxt.functionCall(r).domain()).rangeSubstraction(Train_1_beebook_deterministic_MC_POR_v3.nxt.functionCall(r).range()).union(Train_1_beebook_deterministic_MC_POR_v3.nxt.functionCall(r));

    }

    route_formation(r: ROUTES): void {
        this.frm = this.frm.union(new BSet<ROUTES>(r));

    }

    _get_fst(): BRelation<ROUTES, BLOCKS> {
        return Train_1_beebook_deterministic_MC_POR_v3.fst;
    }

    _get_lst(): BRelation<ROUTES, BLOCKS> {
        return Train_1_beebook_deterministic_MC_POR_v3.lst;
    }

    _get_nxt(): BRelation<ROUTES, BRelation<BLOCKS, BLOCKS>> {
        return Train_1_beebook_deterministic_MC_POR_v3.nxt;
    }

    _get_rtbl(): BRelation<BLOCKS, ROUTES> {
        return Train_1_beebook_deterministic_MC_POR_v3.rtbl;
    }

    _get___aux_constant_1(): BRelation<ROUTES, BLOCKS> {
        return Train_1_beebook_deterministic_MC_POR_v3.__aux_constant_1;
    }

    _get_LBT(): BSet<BLOCKS> {
        return this.LBT;
    }

    _get_TRK(): BRelation<BLOCKS, BLOCKS> {
        return this.TRK;
    }

    _get_frm(): BSet<ROUTES> {
        return this.frm;
    }

    _get_OCC(): BSet<BLOCKS> {
        return this.OCC;
    }

    _get_resbl(): BSet<BLOCKS> {
        return this.resbl;
    }

    _get_resrt(): BSet<ROUTES> {
        return this.resrt;
    }

    _get_rsrtbl(): BRelation<BLOCKS, ROUTES> {
        return this.rsrtbl;
    }

    _get__BLOCKS(): BSet<BLOCKS> {
        return Train_1_beebook_deterministic_MC_POR_v3._BLOCKS;
    }

    _get__ROUTES(): BSet<ROUTES> {
        return Train_1_beebook_deterministic_MC_POR_v3._ROUTES;
    }

    equals(o: any): boolean {
        let o1: Train_1_beebook_deterministic_MC_POR_v3 = this;
        let o2: Train_1_beebook_deterministic_MC_POR_v3 = o as Train_1_beebook_deterministic_MC_POR_v3;
        return o1._get_LBT().equals(o2._get_LBT()) && o1._get_TRK().equals(o2._get_TRK()) && o1._get_frm().equals(o2._get_frm()) && o1._get_OCC().equals(o2._get_OCC()) && o1._get_resbl().equals(o2._get_resbl()) && o1._get_resrt().equals(o2._get_resrt()) && o1._get_rsrtbl().equals(o2._get_rsrtbl());
    }



    hashCode(): number {
        return this._hashCode_1();
    }

    _hashCode_1(): number {
        let result: number = 1;
        result = (1543 * result) ^ ((this._get_LBT()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_TRK()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_frm()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_OCC()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_resbl()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_resrt()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_rsrtbl()).hashCode() << 1);
        return result;
    }

    _hashCode_2(): number {
        let result: number = 1;
        result = (6151 * result) ^ ((this._get_LBT()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_TRK()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_frm()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_OCC()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_resbl()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_resrt()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_rsrtbl()).hashCode() << 1);
        return result;
    }

    /* TODO
    toString(): string {
        return String.join("\n", "_get_LBT: " + (this._get_LBT()).toString(), "_get_TRK: " + (this._get_TRK()).toString(), "_get_frm: " + (this._get_frm()).toString(), "_get_OCC: " + (this._get_OCC()).toString(), "_get_resbl: " + (this._get_resbl()).toString(), "_get_resrt: " + (this._get_resrt()).toString(), "_get_rsrtbl: " + (this._get_rsrtbl()).toString());
    }
    */

    _tr_route_reservation(): BSet<ROUTES> {
        let _ic_set_10: BSet<ROUTES> = new BSet<ROUTES>();
        for(let _ic_r_1 of Train_1_beebook_deterministic_MC_POR_v3._ROUTES.difference(this.resrt)) {
            if((new BBoolean(Train_1_beebook_deterministic_MC_POR_v3.__aux_constant_1.relationImage(new BSet<ROUTES>(_ic_r_1)).intersect(this.resbl).equal(new BSet<BLOCKS>()).booleanValue() && new BSet<ROUTES>().equal(this.resrt.difference(this.rsrtbl.range())).booleanValue())).booleanValue()) {
                _ic_set_10 = _ic_set_10.union(new BSet<ROUTES>(_ic_r_1));
            }

        }

        return _ic_set_10;
    }

    _tr_route_freeing(): BSet<ROUTES> {
        let _ic_set_11: BSet<ROUTES> = new BSet<ROUTES>();
        for(let _ic_r_1 of this.resrt.difference(this.rsrtbl.range())) {
            _ic_set_11 = _ic_set_11.union(new BSet<ROUTES>(_ic_r_1));

        }

        return _ic_set_11;
    }

    _tr_FRONT_MOVE_1(): BSet<ROUTES> {
        let _ic_set_12: BSet<ROUTES> = new BSet<ROUTES>();
        for(let _ic_r_1 of this.frm) {
            if((new BBoolean(new BBoolean(this.resbl.difference(this.OCC).elementOf(Train_1_beebook_deterministic_MC_POR_v3.fst.functionCall(_ic_r_1)).booleanValue() && _ic_r_1.equal(this.rsrtbl.functionCall(Train_1_beebook_deterministic_MC_POR_v3.fst.functionCall(_ic_r_1))).booleanValue()).booleanValue() && new BSet<ROUTES>().equal(this.resrt.difference(this.rsrtbl.range())).booleanValue())).booleanValue()) {
                _ic_set_12 = _ic_set_12.union(new BSet<ROUTES>(_ic_r_1));
            }

        }

        return _ic_set_12;
    }

    _tr_FRONT_MOVE_2(): BSet<BLOCKS> {
        let _ic_set_13: BSet<BLOCKS> = new BSet<BLOCKS>();
        for(let _ic_b_1 of this.OCC.intersect(this.TRK.domain())) {
            if((this.OCC.notElementOf(this.TRK.functionCall(_ic_b_1))).booleanValue()) {
                _ic_set_13 = _ic_set_13.union(new BSet<BLOCKS>(_ic_b_1));
            }

        }

        return _ic_set_13;
    }

    _tr_BACK_MOVE_1(): BSet<BLOCKS> {
        let _ic_set_14: BSet<BLOCKS> = new BSet<BLOCKS>();
        for(let _ic_b_1 of this.LBT.difference(this.TRK.domain())) {
            if((new BSet<ROUTES>().equal(this.resrt.difference(this.rsrtbl.range()))).booleanValue()) {
                _ic_set_14 = _ic_set_14.union(new BSet<BLOCKS>(_ic_b_1));
            }

        }

        return _ic_set_14;
    }

    _tr_BACK_MOVE_2(): BSet<BLOCKS> {
        let _ic_set_15: BSet<BLOCKS> = new BSet<BLOCKS>();
        for(let _ic_b_1 of this.LBT.intersect(this.TRK.domain())) {
            if((new BBoolean(this.OCC.elementOf(this.TRK.functionCall(_ic_b_1)).booleanValue() && new BSet<ROUTES>().equal(this.resrt.difference(this.rsrtbl.range())).booleanValue())).booleanValue()) {
                _ic_set_15 = _ic_set_15.union(new BSet<BLOCKS>(_ic_b_1));
            }

        }

        return _ic_set_15;
    }

    _tr_point_positionning(): BSet<ROUTES> {
        let _ic_set_16: BSet<ROUTES> = new BSet<ROUTES>();
        for(let _ic_r_1 of this.resrt.difference(this.frm)) {
            if((new BSet<ROUTES>().equal(this.resrt.difference(this.rsrtbl.range()))).booleanValue()) {
                _ic_set_16 = _ic_set_16.union(new BSet<ROUTES>(_ic_r_1));
            }

        }

        return _ic_set_16;
    }

    _tr_route_formation(): BSet<ROUTES> {
        let _ic_set_17: BSet<ROUTES> = new BSet<ROUTES>();
        for(let _ic_r_1 of this.resrt.difference(this.frm)) {
            if((new BBoolean(Train_1_beebook_deterministic_MC_POR_v3.nxt.functionCall(_ic_r_1).domainRestriction(this.rsrtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1))).equal(this.TRK.domainRestriction(this.rsrtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)))).booleanValue() && new BSet<ROUTES>().equal(this.resrt.difference(this.rsrtbl.range())).booleanValue())).booleanValue()) {
                _ic_set_17 = _ic_set_17.union(new BSet<ROUTES>(_ic_r_1));
            }

        }

        return _ic_set_17;
    }

    _projected_state_for_point_positionning(): _ProjectionRead_point_positionning {
        return new _ProjectionRead_point_positionning(this.frm,this.resrt,this.TRK,this.rsrtbl);
    }

    _projected_state_for_route_reservation(): _ProjectionRead_route_reservation {
        return new _ProjectionRead_route_reservation(this.resrt,this.resbl,this.rsrtbl);
    }

    _projected_state_for_FRONT_MOVE_1(): _ProjectionRead_FRONT_MOVE_1 {
        return new _ProjectionRead_FRONT_MOVE_1(this.frm,this.resrt,this.resbl,this.OCC,this.rsrtbl,this.LBT);
    }

    _projected_state_for_BACK_MOVE_1(): _ProjectionRead_BACK_MOVE_1 {
        return new _ProjectionRead_BACK_MOVE_1(this.resrt,this.TRK,this.resbl,this.OCC,this.LBT,this.rsrtbl);
    }

    _projected_state_for_FRONT_MOVE_2(): _ProjectionRead_FRONT_MOVE_2 {
        return new _ProjectionRead_FRONT_MOVE_2(this.TRK,this.OCC);
    }

    _projected_state_for_route_formation(): _ProjectionRead_route_formation {
        return new _ProjectionRead_route_formation(this.frm,this.resrt,this.TRK,this.rsrtbl);
    }

    _projected_state_for_route_freeing(): _ProjectionRead_route_freeing {
        return new _ProjectionRead_route_freeing(this.frm,this.resrt,this.rsrtbl);
    }

    _projected_state_for_BACK_MOVE_2(): _ProjectionRead_BACK_MOVE_2 {
        return new _ProjectionRead_BACK_MOVE_2(this.resrt,this.TRK,this.resbl,this.OCC,this.LBT,this.rsrtbl);
    }

    _projected_state_for__tr_route_formation(): _ProjectionRead__tr_route_formation {
        return new _ProjectionRead__tr_route_formation(this.frm,this.resrt,this.TRK,this.rsrtbl);
    }

    _projected_state_for__tr_FRONT_MOVE_1(): _ProjectionRead__tr_FRONT_MOVE_1 {
        return new _ProjectionRead__tr_FRONT_MOVE_1(this.frm,this.resrt,this.resbl,this.OCC,this.rsrtbl);
    }

    _projected_state_for__tr_route_reservation(): _ProjectionRead__tr_route_reservation {
        return new _ProjectionRead__tr_route_reservation(this.resrt,this.resbl,this.rsrtbl);
    }

    _projected_state_for__tr_route_freeing(): _ProjectionRead__tr_route_freeing {
        return new _ProjectionRead__tr_route_freeing(this.resrt,this.rsrtbl);
    }

    _projected_state_for__tr_BACK_MOVE_1(): _ProjectionRead__tr_BACK_MOVE_1 {
        return new _ProjectionRead__tr_BACK_MOVE_1(this.resrt,this.TRK,this.LBT,this.rsrtbl);
    }

    _projected_state_for__tr_point_positionning(): _ProjectionRead__tr_point_positionning {
        return new _ProjectionRead__tr_point_positionning(this.frm,this.resrt,this.rsrtbl);
    }

    _projected_state_for__tr_FRONT_MOVE_2(): _ProjectionRead__tr_FRONT_MOVE_2 {
        return new _ProjectionRead__tr_FRONT_MOVE_2(this.TRK,this.OCC);
    }

    _projected_state_for__tr_BACK_MOVE_2(): _ProjectionRead__tr_BACK_MOVE_2 {
        return new _ProjectionRead__tr_BACK_MOVE_2(this.resrt,this.TRK,this.OCC,this.LBT,this.rsrtbl);
    }

    _projected_state_for__check_inv_6(): _ProjectionRead__check_inv_6 {
        return new _ProjectionRead__check_inv_6(this.OCC,this.rsrtbl);
    }

    _projected_state_for__check_inv_10(): _ProjectionRead__check_inv_10 {
        return new _ProjectionRead__check_inv_10(this.frm,this.resrt,this.rsrtbl);
    }

    _projected_state_for__check_inv_7(): _ProjectionRead__check_inv_7 {
        return new _ProjectionRead__check_inv_7(this.TRK);
    }

    _projected_state_for__check_inv_4(): _ProjectionRead__check_inv_4 {
        return new _ProjectionRead__check_inv_4(this.OCC,this.rsrtbl);
    }

    _projected_state_for__check_inv_5(): _ProjectionRead__check_inv_5 {
        return new _ProjectionRead__check_inv_5(this.rsrtbl);
    }

    _projected_state_for__check_inv_14(): _ProjectionRead__check_inv_14 {
        return new _ProjectionRead__check_inv_14(this.LBT,this.rsrtbl);
    }

    _projected_state_for__check_inv_13(): _ProjectionRead__check_inv_13 {
        return new _ProjectionRead__check_inv_13(this.OCC,this.LBT);
    }

    _projected_state_for__check_inv_8(): _ProjectionRead__check_inv_8 {
        return new _ProjectionRead__check_inv_8(this.frm,this.resrt);
    }

    _projected_state_for__check_inv_12(): _ProjectionRead__check_inv_12 {
        return new _ProjectionRead__check_inv_12(this.frm,this.TRK,this.rsrtbl);
    }

    _projected_state_for__check_inv_9(): _ProjectionRead__check_inv_9 {
        return new _ProjectionRead__check_inv_9(this.frm,this.OCC,this.rsrtbl);
    }

    _projected_state_for__check_inv_11(): _ProjectionRead__check_inv_11 {
        return new _ProjectionRead__check_inv_11(this.TRK);
    }

    _projected_state_for__check_inv_2(): _ProjectionRead__check_inv_2 {
        return new _ProjectionRead__check_inv_2(this.rsrtbl);
    }

    _projected_state_for__check_inv_3(): _ProjectionRead__check_inv_3 {
        return new _ProjectionRead__check_inv_3(this.resbl,this.OCC);
    }

    _projected_state_for__check_inv_1(): _ProjectionRead__check_inv_1 {
        return new _ProjectionRead__check_inv_1(this.resrt,this.resbl,this.rsrtbl);
    }

    _update_for_point_positionning(): _ProjectionWrite_point_positionning {
        return new _ProjectionWrite_point_positionning(this.TRK);
    }

    _update_for_route_reservation(): _ProjectionWrite_route_reservation {
        return new _ProjectionWrite_route_reservation(this.resrt,this.resbl,this.rsrtbl);
    }

    _update_for_FRONT_MOVE_1(): _ProjectionWrite_FRONT_MOVE_1 {
        return new _ProjectionWrite_FRONT_MOVE_1(this.OCC,this.LBT);
    }

    _update_for_BACK_MOVE_1(): _ProjectionWrite_BACK_MOVE_1 {
        return new _ProjectionWrite_BACK_MOVE_1(this.resbl,this.OCC,this.rsrtbl,this.LBT);
    }

    _update_for_FRONT_MOVE_2(): _ProjectionWrite_FRONT_MOVE_2 {
        return new _ProjectionWrite_FRONT_MOVE_2(this.OCC);
    }

    _update_for_route_formation(): _ProjectionWrite_route_formation {
        return new _ProjectionWrite_route_formation(this.frm);
    }

    _update_for_route_freeing(): _ProjectionWrite_route_freeing {
        return new _ProjectionWrite_route_freeing(this.frm,this.resrt);
    }

    _update_for_BACK_MOVE_2(): _ProjectionWrite_BACK_MOVE_2 {
        return new _ProjectionWrite_BACK_MOVE_2(this.resbl,this.OCC,this.rsrtbl,this.LBT);
    }

    _apply_update_for_point_positionning(update : _ProjectionWrite_point_positionning): void {
        this.TRK = update.TRK;
    }

    _apply_update_for_route_reservation(update : _ProjectionWrite_route_reservation): void {
        this.resrt = update.resrt;
        this.resbl = update.resbl;
        this.rsrtbl = update.rsrtbl;
    }

    _apply_update_for_FRONT_MOVE_1(update : _ProjectionWrite_FRONT_MOVE_1): void {
        this.OCC = update.OCC;
        this.LBT = update.LBT;
    }

    _apply_update_for_BACK_MOVE_1(update : _ProjectionWrite_BACK_MOVE_1): void {
        this.resbl = update.resbl;
        this.OCC = update.OCC;
        this.rsrtbl = update.rsrtbl;
        this.LBT = update.LBT;
    }

    _apply_update_for_FRONT_MOVE_2(update : _ProjectionWrite_FRONT_MOVE_2): void {
        this.OCC = update.OCC;
    }

    _apply_update_for_route_formation(update : _ProjectionWrite_route_formation): void {
        this.frm = update.frm;
    }

    _apply_update_for_route_freeing(update : _ProjectionWrite_route_freeing): void {
        this.frm = update.frm;
        this.resrt = update.resrt;
    }

    _apply_update_for_BACK_MOVE_2(update : _ProjectionWrite_BACK_MOVE_2): void {
        this.resbl = update.resbl;
        this.OCC = update.OCC;
        this.rsrtbl = update.rsrtbl;
        this.LBT = update.LBT;
    }

    _check_inv_1() {
        return this.rsrtbl.checkDomain(this.resbl).and(this.rsrtbl.checkRange(this.resrt)).and(this.rsrtbl.isFunction()).and(this.rsrtbl.isTotal(this.resbl)).booleanValue();
    }

    _check_inv_2() {
        let _ic_boolean_18: BBoolean = new BBoolean(true);
        for(let _ic__opt_4_1 of this.rsrtbl) {
            if(!(Train_1_beebook_deterministic_MC_POR_v3.rtbl.elementOf(_ic__opt_4_1)).booleanValue()) {
                _ic_boolean_18 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_18.booleanValue();
    }

    _check_inv_3() {
        let _ic_boolean_19: BBoolean = new BBoolean(true);
        for(let _ic__opt_5_1 of this.OCC) {
            if(!(this.resbl.elementOf(_ic__opt_5_1)).booleanValue()) {
                _ic_boolean_19 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_19.booleanValue();
    }

    _check_inv_4() {
        let _ic_boolean_20: BBoolean = new BBoolean(true);
        for(let _ic_r_1 of Train_1_beebook_deterministic_MC_POR_v3._ROUTES) {
            if(!(Train_1_beebook_deterministic_MC_POR_v3.nxt.functionCall(_ic_r_1).relationImage(Train_1_beebook_deterministic_MC_POR_v3.__aux_constant_1.relationImage(new BSet<ROUTES>(_ic_r_1)).difference(this.rsrtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)))).intersect(this.rsrtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)).difference(this.OCC)).equal(new BSet<BLOCKS>())).booleanValue()) {
                _ic_boolean_20 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_20.booleanValue();
    }

    _check_inv_5() {
        let _ic_boolean_22: BBoolean = new BBoolean(true);
        for(let _ic_r_1 of Train_1_beebook_deterministic_MC_POR_v3._ROUTES) {
            let _ic_boolean_21: BBoolean = new BBoolean(true);
            for(let _ic__opt_6_1 of Train_1_beebook_deterministic_MC_POR_v3.nxt.functionCall(_ic_r_1).relationImage(this.rsrtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)))) {
                if(!(this.rsrtbl.inverse().isInRelationalImage(_ic__opt_6_1, new BSet<ROUTES>(_ic_r_1))).booleanValue()) {
                    _ic_boolean_21 = new BBoolean(false);
                    break;
                }

            }

            if(!(_ic_boolean_21).booleanValue()) {
                _ic_boolean_22 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_22.booleanValue();
    }

    _check_inv_6() {
        let _ic_boolean_24: BBoolean = new BBoolean(true);
        for(let _ic_r_1 of Train_1_beebook_deterministic_MC_POR_v3._ROUTES) {
            let _ic_boolean_23: BBoolean = new BBoolean(true);
            for(let _ic__opt_7_1 of Train_1_beebook_deterministic_MC_POR_v3.nxt.functionCall(_ic_r_1).relationImage(this.rsrtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)).difference(this.OCC))) {
                if(!(new BBoolean(this.rsrtbl.inverse().isInRelationalImage(_ic__opt_7_1, new BSet<ROUTES>(_ic_r_1)).booleanValue() && this.OCC.notElementOf(_ic__opt_7_1).booleanValue())).booleanValue()) {
                    _ic_boolean_23 = new BBoolean(false);
                    break;
                }

            }

            if(!(_ic_boolean_23).booleanValue()) {
                _ic_boolean_24 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_24.booleanValue();
    }

    _check_inv_7() {
        return this.TRK.checkDomain(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS).and(this.TRK.checkRange(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS)).and(this.TRK.isFunction()).and(this.TRK.isPartial(Train_1_beebook_deterministic_MC_POR_v3._BLOCKS)).and(this.TRK.isInjection()).booleanValue();
    }

    _check_inv_8() {
        let _ic_boolean_25: BBoolean = new BBoolean(true);
        for(let _ic__opt_8_1 of this.frm) {
            if(!(this.resrt.elementOf(_ic__opt_8_1)).booleanValue()) {
                _ic_boolean_25 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_25.booleanValue();
    }

    _check_inv_9() {
        let _ic_boolean_26: BBoolean = new BBoolean(true);
        for(let _ic__opt_9_1 of this.rsrtbl.relationImage(this.OCC)) {
            if(!(this.frm.elementOf(_ic__opt_9_1)).booleanValue()) {
                _ic_boolean_26 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_26.booleanValue();
    }

    _check_inv_10() {
        let _ic_boolean_27: BBoolean = new BBoolean(true);
        for(let _ic_r_1 of this.resrt.difference(this.frm)) {
            if(!(Train_1_beebook_deterministic_MC_POR_v3.rtbl.rangeRestriction(new BSet<ROUTES>(_ic_r_1)).equal(this.rsrtbl.rangeRestriction(new BSet<ROUTES>(_ic_r_1)))).booleanValue()) {
                _ic_boolean_27 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_27.booleanValue();
    }

    _check_inv_11() {
        let _ic_boolean_29: BBoolean = new BBoolean(true);
        for(let _ic_x_1 of Train_1_beebook_deterministic_MC_POR_v3._BLOCKS) {
            for(let _ic_y_1 of Train_1_beebook_deterministic_MC_POR_v3._BLOCKS) {
                let _ic_boolean_28: BBoolean = new BBoolean(false);
                for(let _ic_r_1 of Train_1_beebook_deterministic_MC_POR_v3._ROUTES) {
                    if((Train_1_beebook_deterministic_MC_POR_v3.nxt.functionCall(_ic_r_1).elementOf(new BTuple(_ic_x_1, _ic_y_1))).booleanValue()) {
                        _ic_boolean_28 = new BBoolean(true);
                        break;
                    }

                }

                if(!(new BBoolean(!this.TRK.elementOf(new BTuple(_ic_x_1, _ic_y_1)).booleanValue() || _ic_boolean_28.booleanValue())).booleanValue()) {
                    _ic_boolean_29 = new BBoolean(false);
                    break;
                }

            }

        }

        return _ic_boolean_29.booleanValue();
    }

    _check_inv_12() {
        let _ic_boolean_30: BBoolean = new BBoolean(true);
        for(let _ic_r_1 of this.frm) {
            if(!(Train_1_beebook_deterministic_MC_POR_v3.nxt.functionCall(_ic_r_1).domainRestriction(this.rsrtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1))).equal(this.TRK.domainRestriction(this.rsrtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1))))).booleanValue()) {
                _ic_boolean_30 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_30.booleanValue();
    }

    _check_inv_13() {
        let _ic_boolean_31: BBoolean = new BBoolean(true);
        for(let _ic__opt_10_1 of this.LBT) {
            if(!(this.OCC.elementOf(_ic__opt_10_1)).booleanValue()) {
                _ic_boolean_31 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_31.booleanValue();
    }

    _check_inv_14() {
        let _ic_boolean_32: BBoolean = new BBoolean(true);
        for(let _ic_a_1 of Train_1_beebook_deterministic_MC_POR_v3._BLOCKS) {
            for(let _ic_b_1 of this.LBT) {
                if(!(new BBoolean(!new BBoolean(new BBoolean(Train_1_beebook_deterministic_MC_POR_v3.nxt.functionCall(this.rsrtbl.functionCall(_ic_b_1)).isInRange(_ic_b_1).booleanValue() && _ic_a_1.equal(Train_1_beebook_deterministic_MC_POR_v3.nxt.functionCall(this.rsrtbl.functionCall(_ic_b_1)).inverse().functionCall(_ic_b_1)).booleanValue()).booleanValue() && this.rsrtbl.isInDomain(_ic_a_1).booleanValue()).booleanValue() || this.rsrtbl.functionCall(_ic_a_1).unequal(this.rsrtbl.functionCall(_ic_b_1)).booleanValue())).booleanValue()) {
                    _ic_boolean_32 = new BBoolean(false);
                    break;
                }

            }

        }

        return _ic_boolean_32.booleanValue();
    }


    public _copy(): Train_1_beebook_deterministic_MC_POR_v3 {
      return new Train_1_beebook_deterministic_MC_POR_v3(this);
    }


}


export class ModelChecker {
    private type: Type;
    private isCaching: boolean;
    private isDebug: boolean;

    private unvisitedStates: LinkedList<Train_1_beebook_deterministic_MC_POR_v3> = new LinkedList<Train_1_beebook_deterministic_MC_POR_v3>;
    private states: immutable.Set<Train_1_beebook_deterministic_MC_POR_v3> = new immutable.Set();
    private transitions: number = 0;

    private invariantViolated: boolean = false;
    private deadlockDetected: boolean = false;
    private counterExampleState: Train_1_beebook_deterministic_MC_POR_v3 = undefined;

    _OpCache_route_reservation: immutable.Map<BSet<ROUTES>, immutable.Map<_ProjectionRead_route_reservation, _ProjectionWrite_route_reservation>> = new immutable.Map();
    _OpCache_tr_route_reservation: immutable.Map<_ProjectionRead__tr_route_reservation, BSet<ROUTES>> = new immutable.Map();

    _OpCache_route_freeing: immutable.Map<BSet<ROUTES>, immutable.Map<_ProjectionRead_route_freeing, _ProjectionWrite_route_freeing>> = new immutable.Map();
    _OpCache_tr_route_freeing: immutable.Map<_ProjectionRead__tr_route_freeing, BSet<ROUTES>> = new immutable.Map();

    _OpCache_FRONT_MOVE_1: immutable.Map<BSet<ROUTES>, immutable.Map<_ProjectionRead_FRONT_MOVE_1, _ProjectionWrite_FRONT_MOVE_1>> = new immutable.Map();
    _OpCache_tr_FRONT_MOVE_1: immutable.Map<_ProjectionRead__tr_FRONT_MOVE_1, BSet<ROUTES>> = new immutable.Map();

    _OpCache_FRONT_MOVE_2: immutable.Map<BSet<BLOCKS>, immutable.Map<_ProjectionRead_FRONT_MOVE_2, _ProjectionWrite_FRONT_MOVE_2>> = new immutable.Map();
    _OpCache_tr_FRONT_MOVE_2: immutable.Map<_ProjectionRead__tr_FRONT_MOVE_2, BSet<BLOCKS>> = new immutable.Map();

    _OpCache_BACK_MOVE_1: immutable.Map<BSet<BLOCKS>, immutable.Map<_ProjectionRead_BACK_MOVE_1, _ProjectionWrite_BACK_MOVE_1>> = new immutable.Map();
    _OpCache_tr_BACK_MOVE_1: immutable.Map<_ProjectionRead__tr_BACK_MOVE_1, BSet<BLOCKS>> = new immutable.Map();

    _OpCache_BACK_MOVE_2: immutable.Map<BSet<BLOCKS>, immutable.Map<_ProjectionRead_BACK_MOVE_2, _ProjectionWrite_BACK_MOVE_2>> = new immutable.Map();
    _OpCache_tr_BACK_MOVE_2: immutable.Map<_ProjectionRead__tr_BACK_MOVE_2, BSet<BLOCKS>> = new immutable.Map();

    _OpCache_point_positionning: immutable.Map<BSet<ROUTES>, immutable.Map<_ProjectionRead_point_positionning, _ProjectionWrite_point_positionning>> = new immutable.Map();
    _OpCache_tr_point_positionning: immutable.Map<_ProjectionRead__tr_point_positionning, BSet<ROUTES>> = new immutable.Map();

    _OpCache_route_formation: immutable.Map<BSet<ROUTES>, immutable.Map<_ProjectionRead_route_formation, _ProjectionWrite_route_formation>> = new immutable.Map();
    _OpCache_tr_route_formation: immutable.Map<_ProjectionRead__tr_route_formation, BSet<ROUTES>> = new immutable.Map();

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
        let machine: Train_1_beebook_deterministic_MC_POR_v3 = new Train_1_beebook_deterministic_MC_POR_v3();
        this.states = this.states.add(machine);
        this.unvisitedStates.pushBack(machine);

        while(!(this.unvisitedStates.length === 0)) {
            let state: Train_1_beebook_deterministic_MC_POR_v3 = this.next();

            let nextStates: Set<Train_1_beebook_deterministic_MC_POR_v3> = this.generateNextStates(state);

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

    next(): Train_1_beebook_deterministic_MC_POR_v3 {
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

    generateNextStates(state: Train_1_beebook_deterministic_MC_POR_v3): Set<Train_1_beebook_deterministic_MC_POR_v3> {
        let result: immutable.Set<Train_1_beebook_deterministic_MC_POR_v3> = immutable.Set();
        if(this.isCaching) {
            let read__tr_route_reservation_state : _ProjectionRead__tr_route_reservation = state._projected_state_for__tr_route_reservation();
            let _trid_1 : BSet<ROUTES>  = this._OpCache_tr_route_reservation.get(read__tr_route_reservation_state);
            if(_trid_1 == null) {
                _trid_1 = state._tr_route_reservation();
                this._OpCache_tr_route_reservation = this._OpCache_tr_route_reservation.set(read__tr_route_reservation_state, _trid_1);
            }

            for(let param of _trid_1) {
                let _tmp_1: ROUTES = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v3 = state._copy();
                let readState: _ProjectionRead_route_reservation = state._projected_state_for_route_reservation();
                let _OpCache_with_parameter_route_reservation: immutable.Map = this._OpCache_route_reservation.get(param);
                if(_OpCache_with_parameter_route_reservation != null) {
                    let writeState: _ProjectionWrite_route_reservation = _OpCache_with_parameter_route_reservation.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_route_reservation(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.route_reservation(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_route_reservation();
                        _OpCache_with_parameter_route_reservation = _OpCache_with_parameter_route_reservation.set(readState, writeState);
                        this._OpCache_route_reservation = this._OpCache_route_reservation.set(param, _OpCache_with_parameter_route_reservation);
                    }

                } else {
                    copiedState.route_reservation(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_route_reservation = copiedState._update_for_route_reservation();
                    _OpCache_with_parameter_route_reservation = new immutable.Map().set(readState, writeState);
                    this._OpCache_route_reservation = this._OpCache_route_reservation.set(param, _OpCache_with_parameter_route_reservation);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_route_freeing_state : _ProjectionRead__tr_route_freeing = state._projected_state_for__tr_route_freeing();
            let _trid_2 : BSet<ROUTES>  = this._OpCache_tr_route_freeing.get(read__tr_route_freeing_state);
            if(_trid_2 == null) {
                _trid_2 = state._tr_route_freeing();
                this._OpCache_tr_route_freeing = this._OpCache_tr_route_freeing.set(read__tr_route_freeing_state, _trid_2);
            }

            for(let param of _trid_2) {
                let _tmp_1: ROUTES = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v3 = state._copy();
                let readState: _ProjectionRead_route_freeing = state._projected_state_for_route_freeing();
                let _OpCache_with_parameter_route_freeing: immutable.Map = this._OpCache_route_freeing.get(param);
                if(_OpCache_with_parameter_route_freeing != null) {
                    let writeState: _ProjectionWrite_route_freeing = _OpCache_with_parameter_route_freeing.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_route_freeing(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.route_freeing(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_route_freeing();
                        _OpCache_with_parameter_route_freeing = _OpCache_with_parameter_route_freeing.set(readState, writeState);
                        this._OpCache_route_freeing = this._OpCache_route_freeing.set(param, _OpCache_with_parameter_route_freeing);
                    }

                } else {
                    copiedState.route_freeing(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_route_freeing = copiedState._update_for_route_freeing();
                    _OpCache_with_parameter_route_freeing = new immutable.Map().set(readState, writeState);
                    this._OpCache_route_freeing = this._OpCache_route_freeing.set(param, _OpCache_with_parameter_route_freeing);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_FRONT_MOVE_1_state : _ProjectionRead__tr_FRONT_MOVE_1 = state._projected_state_for__tr_FRONT_MOVE_1();
            let _trid_3 : BSet<ROUTES>  = this._OpCache_tr_FRONT_MOVE_1.get(read__tr_FRONT_MOVE_1_state);
            if(_trid_3 == null) {
                _trid_3 = state._tr_FRONT_MOVE_1();
                this._OpCache_tr_FRONT_MOVE_1 = this._OpCache_tr_FRONT_MOVE_1.set(read__tr_FRONT_MOVE_1_state, _trid_3);
            }

            for(let param of _trid_3) {
                let _tmp_1: ROUTES = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v3 = state._copy();
                let readState: _ProjectionRead_FRONT_MOVE_1 = state._projected_state_for_FRONT_MOVE_1();
                let _OpCache_with_parameter_FRONT_MOVE_1: immutable.Map = this._OpCache_FRONT_MOVE_1.get(param);
                if(_OpCache_with_parameter_FRONT_MOVE_1 != null) {
                    let writeState: _ProjectionWrite_FRONT_MOVE_1 = _OpCache_with_parameter_FRONT_MOVE_1.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_FRONT_MOVE_1(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.FRONT_MOVE_1(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_FRONT_MOVE_1();
                        _OpCache_with_parameter_FRONT_MOVE_1 = _OpCache_with_parameter_FRONT_MOVE_1.set(readState, writeState);
                        this._OpCache_FRONT_MOVE_1 = this._OpCache_FRONT_MOVE_1.set(param, _OpCache_with_parameter_FRONT_MOVE_1);
                    }

                } else {
                    copiedState.FRONT_MOVE_1(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_FRONT_MOVE_1 = copiedState._update_for_FRONT_MOVE_1();
                    _OpCache_with_parameter_FRONT_MOVE_1 = new immutable.Map().set(readState, writeState);
                    this._OpCache_FRONT_MOVE_1 = this._OpCache_FRONT_MOVE_1.set(param, _OpCache_with_parameter_FRONT_MOVE_1);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_FRONT_MOVE_2_state : _ProjectionRead__tr_FRONT_MOVE_2 = state._projected_state_for__tr_FRONT_MOVE_2();
            let _trid_4 : BSet<BLOCKS>  = this._OpCache_tr_FRONT_MOVE_2.get(read__tr_FRONT_MOVE_2_state);
            if(_trid_4 == null) {
                _trid_4 = state._tr_FRONT_MOVE_2();
                this._OpCache_tr_FRONT_MOVE_2 = this._OpCache_tr_FRONT_MOVE_2.set(read__tr_FRONT_MOVE_2_state, _trid_4);
            }

            for(let param of _trid_4) {
                let _tmp_1: BLOCKS = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v3 = state._copy();
                let readState: _ProjectionRead_FRONT_MOVE_2 = state._projected_state_for_FRONT_MOVE_2();
                let _OpCache_with_parameter_FRONT_MOVE_2: immutable.Map = this._OpCache_FRONT_MOVE_2.get(param);
                if(_OpCache_with_parameter_FRONT_MOVE_2 != null) {
                    let writeState: _ProjectionWrite_FRONT_MOVE_2 = _OpCache_with_parameter_FRONT_MOVE_2.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_FRONT_MOVE_2(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.FRONT_MOVE_2(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_FRONT_MOVE_2();
                        _OpCache_with_parameter_FRONT_MOVE_2 = _OpCache_with_parameter_FRONT_MOVE_2.set(readState, writeState);
                        this._OpCache_FRONT_MOVE_2 = this._OpCache_FRONT_MOVE_2.set(param, _OpCache_with_parameter_FRONT_MOVE_2);
                    }

                } else {
                    copiedState.FRONT_MOVE_2(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_FRONT_MOVE_2 = copiedState._update_for_FRONT_MOVE_2();
                    _OpCache_with_parameter_FRONT_MOVE_2 = new immutable.Map().set(readState, writeState);
                    this._OpCache_FRONT_MOVE_2 = this._OpCache_FRONT_MOVE_2.set(param, _OpCache_with_parameter_FRONT_MOVE_2);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_BACK_MOVE_1_state : _ProjectionRead__tr_BACK_MOVE_1 = state._projected_state_for__tr_BACK_MOVE_1();
            let _trid_5 : BSet<BLOCKS>  = this._OpCache_tr_BACK_MOVE_1.get(read__tr_BACK_MOVE_1_state);
            if(_trid_5 == null) {
                _trid_5 = state._tr_BACK_MOVE_1();
                this._OpCache_tr_BACK_MOVE_1 = this._OpCache_tr_BACK_MOVE_1.set(read__tr_BACK_MOVE_1_state, _trid_5);
            }

            for(let param of _trid_5) {
                let _tmp_1: BLOCKS = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v3 = state._copy();
                let readState: _ProjectionRead_BACK_MOVE_1 = state._projected_state_for_BACK_MOVE_1();
                let _OpCache_with_parameter_BACK_MOVE_1: immutable.Map = this._OpCache_BACK_MOVE_1.get(param);
                if(_OpCache_with_parameter_BACK_MOVE_1 != null) {
                    let writeState: _ProjectionWrite_BACK_MOVE_1 = _OpCache_with_parameter_BACK_MOVE_1.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_BACK_MOVE_1(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.BACK_MOVE_1(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_BACK_MOVE_1();
                        _OpCache_with_parameter_BACK_MOVE_1 = _OpCache_with_parameter_BACK_MOVE_1.set(readState, writeState);
                        this._OpCache_BACK_MOVE_1 = this._OpCache_BACK_MOVE_1.set(param, _OpCache_with_parameter_BACK_MOVE_1);
                    }

                } else {
                    copiedState.BACK_MOVE_1(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_BACK_MOVE_1 = copiedState._update_for_BACK_MOVE_1();
                    _OpCache_with_parameter_BACK_MOVE_1 = new immutable.Map().set(readState, writeState);
                    this._OpCache_BACK_MOVE_1 = this._OpCache_BACK_MOVE_1.set(param, _OpCache_with_parameter_BACK_MOVE_1);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_BACK_MOVE_2_state : _ProjectionRead__tr_BACK_MOVE_2 = state._projected_state_for__tr_BACK_MOVE_2();
            let _trid_6 : BSet<BLOCKS>  = this._OpCache_tr_BACK_MOVE_2.get(read__tr_BACK_MOVE_2_state);
            if(_trid_6 == null) {
                _trid_6 = state._tr_BACK_MOVE_2();
                this._OpCache_tr_BACK_MOVE_2 = this._OpCache_tr_BACK_MOVE_2.set(read__tr_BACK_MOVE_2_state, _trid_6);
            }

            for(let param of _trid_6) {
                let _tmp_1: BLOCKS = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v3 = state._copy();
                let readState: _ProjectionRead_BACK_MOVE_2 = state._projected_state_for_BACK_MOVE_2();
                let _OpCache_with_parameter_BACK_MOVE_2: immutable.Map = this._OpCache_BACK_MOVE_2.get(param);
                if(_OpCache_with_parameter_BACK_MOVE_2 != null) {
                    let writeState: _ProjectionWrite_BACK_MOVE_2 = _OpCache_with_parameter_BACK_MOVE_2.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_BACK_MOVE_2(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.BACK_MOVE_2(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_BACK_MOVE_2();
                        _OpCache_with_parameter_BACK_MOVE_2 = _OpCache_with_parameter_BACK_MOVE_2.set(readState, writeState);
                        this._OpCache_BACK_MOVE_2 = this._OpCache_BACK_MOVE_2.set(param, _OpCache_with_parameter_BACK_MOVE_2);
                    }

                } else {
                    copiedState.BACK_MOVE_2(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_BACK_MOVE_2 = copiedState._update_for_BACK_MOVE_2();
                    _OpCache_with_parameter_BACK_MOVE_2 = new immutable.Map().set(readState, writeState);
                    this._OpCache_BACK_MOVE_2 = this._OpCache_BACK_MOVE_2.set(param, _OpCache_with_parameter_BACK_MOVE_2);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_point_positionning_state : _ProjectionRead__tr_point_positionning = state._projected_state_for__tr_point_positionning();
            let _trid_7 : BSet<ROUTES>  = this._OpCache_tr_point_positionning.get(read__tr_point_positionning_state);
            if(_trid_7 == null) {
                _trid_7 = state._tr_point_positionning();
                this._OpCache_tr_point_positionning = this._OpCache_tr_point_positionning.set(read__tr_point_positionning_state, _trid_7);
            }

            for(let param of _trid_7) {
                let _tmp_1: ROUTES = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v3 = state._copy();
                let readState: _ProjectionRead_point_positionning = state._projected_state_for_point_positionning();
                let _OpCache_with_parameter_point_positionning: immutable.Map = this._OpCache_point_positionning.get(param);
                if(_OpCache_with_parameter_point_positionning != null) {
                    let writeState: _ProjectionWrite_point_positionning = _OpCache_with_parameter_point_positionning.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_point_positionning(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.point_positionning(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_point_positionning();
                        _OpCache_with_parameter_point_positionning = _OpCache_with_parameter_point_positionning.set(readState, writeState);
                        this._OpCache_point_positionning = this._OpCache_point_positionning.set(param, _OpCache_with_parameter_point_positionning);
                    }

                } else {
                    copiedState.point_positionning(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_point_positionning = copiedState._update_for_point_positionning();
                    _OpCache_with_parameter_point_positionning = new immutable.Map().set(readState, writeState);
                    this._OpCache_point_positionning = this._OpCache_point_positionning.set(param, _OpCache_with_parameter_point_positionning);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let read__tr_route_formation_state : _ProjectionRead__tr_route_formation = state._projected_state_for__tr_route_formation();
            let _trid_8 : BSet<ROUTES>  = this._OpCache_tr_route_formation.get(read__tr_route_formation_state);
            if(_trid_8 == null) {
                _trid_8 = state._tr_route_formation();
                this._OpCache_tr_route_formation = this._OpCache_tr_route_formation.set(read__tr_route_formation_state, _trid_8);
            }

            for(let param of _trid_8) {
                let _tmp_1: ROUTES = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v3 = state._copy();
                let readState: _ProjectionRead_route_formation = state._projected_state_for_route_formation();
                let _OpCache_with_parameter_route_formation: immutable.Map = this._OpCache_route_formation.get(param);
                if(_OpCache_with_parameter_route_formation != null) {
                    let writeState: _ProjectionWrite_route_formation = _OpCache_with_parameter_route_formation.get(readState);
                    if(writeState != null) {
                        copiedState._apply_update_for_route_formation(writeState);
                        copiedState.parent = state;
                    } else {
                        copiedState.route_formation(_tmp_1);
                        copiedState.parent = state;
                        writeState = copiedState._update_for_route_formation();
                        _OpCache_with_parameter_route_formation = _OpCache_with_parameter_route_formation.set(readState, writeState);
                        this._OpCache_route_formation = this._OpCache_route_formation.set(param, _OpCache_with_parameter_route_formation);
                    }

                } else {
                    copiedState.route_formation(_tmp_1);
                    copiedState.parent = state;
                    let writeState : _ProjectionWrite_route_formation = copiedState._update_for_route_formation();
                    _OpCache_with_parameter_route_formation = new immutable.Map().set(readState, writeState);
                    this._OpCache_route_formation = this._OpCache_route_formation.set(param, _OpCache_with_parameter_route_formation);
                }
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        } else {
            let _trid_1: BSet<ROUTES> = state._tr_route_reservation();
            for(let param of _trid_1) {
                let _tmp_1: ROUTES = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v3 = state._copy();
                copiedState.route_reservation(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_2: BSet<ROUTES> = state._tr_route_freeing();
            for(let param of _trid_2) {
                let _tmp_1: ROUTES = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v3 = state._copy();
                copiedState.route_freeing(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_3: BSet<ROUTES> = state._tr_FRONT_MOVE_1();
            for(let param of _trid_3) {
                let _tmp_1: ROUTES = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v3 = state._copy();
                copiedState.FRONT_MOVE_1(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_4: BSet<BLOCKS> = state._tr_FRONT_MOVE_2();
            for(let param of _trid_4) {
                let _tmp_1: BLOCKS = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v3 = state._copy();
                copiedState.FRONT_MOVE_2(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_5: BSet<BLOCKS> = state._tr_BACK_MOVE_1();
            for(let param of _trid_5) {
                let _tmp_1: BLOCKS = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v3 = state._copy();
                copiedState.BACK_MOVE_1(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_6: BSet<BLOCKS> = state._tr_BACK_MOVE_2();
            for(let param of _trid_6) {
                let _tmp_1: BLOCKS = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v3 = state._copy();
                copiedState.BACK_MOVE_2(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_7: BSet<ROUTES> = state._tr_point_positionning();
            for(let param of _trid_7) {
                let _tmp_1: ROUTES = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v3 = state._copy();
                copiedState.point_positionning(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_8: BSet<ROUTES> = state._tr_route_formation();
            for(let param of _trid_8) {
                let _tmp_1: ROUTES = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v3 = state._copy();
                copiedState.route_formation(_tmp_1);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        }
        return result;
    }

    invViolated(state: Train_1_beebook_deterministic_MC_POR_v3): boolean {
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

