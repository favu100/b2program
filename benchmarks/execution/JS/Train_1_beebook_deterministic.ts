import {BTuple} from './btypes/BTuple.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BRelation} from './btypes/BRelation.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";

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


export default class Train_1_beebook_deterministic {


    private static fst: BRelation<ROUTES, BLOCKS>;
    private static lst: BRelation<ROUTES, BLOCKS>;
    private static nxt: BRelation<ROUTES, BRelation<BLOCKS, BLOCKS>>;
    private static rtbl: BRelation<BLOCKS, ROUTES>;

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
        Train_1_beebook_deterministic.nxt = new BRelation<ROUTES, BRelation<BLOCKS, BLOCKS>>(new BTuple(new ROUTES(enum_ROUTES.R1), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.L), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.C)))), new BTuple(new ROUTES(enum_ROUTES.R2), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.L), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.D)), new BTuple(new BLOCKS(enum_BLOCKS.D), new BLOCKS(enum_BLOCKS.E)), new BTuple(new BLOCKS(enum_BLOCKS.E), new BLOCKS(enum_BLOCKS.F)), new BTuple(new BLOCKS(enum_BLOCKS.F), new BLOCKS(enum_BLOCKS.G)))), new BTuple(new ROUTES(enum_ROUTES.R3), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.L), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.D)), new BTuple(new BLOCKS(enum_BLOCKS.D), new BLOCKS(enum_BLOCKS.K)), new BTuple(new BLOCKS(enum_BLOCKS.K), new BLOCKS(enum_BLOCKS.J)), new BTuple(new BLOCKS(enum_BLOCKS.J), new BLOCKS(enum_BLOCKS.N)))), new BTuple(new ROUTES(enum_ROUTES.R4), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.M), new BLOCKS(enum_BLOCKS.H)), new BTuple(new BLOCKS(enum_BLOCKS.H), new BLOCKS(enum_BLOCKS.I)), new BTuple(new BLOCKS(enum_BLOCKS.I), new BLOCKS(enum_BLOCKS.K)), new BTuple(new BLOCKS(enum_BLOCKS.K), new BLOCKS(enum_BLOCKS.F)), new BTuple(new BLOCKS(enum_BLOCKS.F), new BLOCKS(enum_BLOCKS.G)))), new BTuple(new ROUTES(enum_ROUTES.R5), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.M), new BLOCKS(enum_BLOCKS.H)), new BTuple(new BLOCKS(enum_BLOCKS.H), new BLOCKS(enum_BLOCKS.I)), new BTuple(new BLOCKS(enum_BLOCKS.I), new BLOCKS(enum_BLOCKS.J)), new BTuple(new BLOCKS(enum_BLOCKS.J), new BLOCKS(enum_BLOCKS.N)))), new BTuple(new ROUTES(enum_ROUTES.R6), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.C), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.L)))), new BTuple(new ROUTES(enum_ROUTES.R7), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.G), new BLOCKS(enum_BLOCKS.F)), new BTuple(new BLOCKS(enum_BLOCKS.F), new BLOCKS(enum_BLOCKS.E)), new BTuple(new BLOCKS(enum_BLOCKS.E), new BLOCKS(enum_BLOCKS.D)), new BTuple(new BLOCKS(enum_BLOCKS.D), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.L)))), new BTuple(new ROUTES(enum_ROUTES.R8), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.N), new BLOCKS(enum_BLOCKS.J)), new BTuple(new BLOCKS(enum_BLOCKS.J), new BLOCKS(enum_BLOCKS.K)), new BTuple(new BLOCKS(enum_BLOCKS.K), new BLOCKS(enum_BLOCKS.D)), new BTuple(new BLOCKS(enum_BLOCKS.D), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.L)))), new BTuple(new ROUTES(enum_ROUTES.R9), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.G), new BLOCKS(enum_BLOCKS.F)), new BTuple(new BLOCKS(enum_BLOCKS.F), new BLOCKS(enum_BLOCKS.K)), new BTuple(new BLOCKS(enum_BLOCKS.K), new BLOCKS(enum_BLOCKS.I)), new BTuple(new BLOCKS(enum_BLOCKS.I), new BLOCKS(enum_BLOCKS.H)), new BTuple(new BLOCKS(enum_BLOCKS.H), new BLOCKS(enum_BLOCKS.M)))), new BTuple(new ROUTES(enum_ROUTES.R10), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.N), new BLOCKS(enum_BLOCKS.J)), new BTuple(new BLOCKS(enum_BLOCKS.J), new BLOCKS(enum_BLOCKS.I)), new BTuple(new BLOCKS(enum_BLOCKS.I), new BLOCKS(enum_BLOCKS.H)), new BTuple(new BLOCKS(enum_BLOCKS.H), new BLOCKS(enum_BLOCKS.M)))));
        Train_1_beebook_deterministic.fst = new BRelation<ROUTES, BLOCKS>(new BTuple(new ROUTES(enum_ROUTES.R1), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R2), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R3), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R4), new BLOCKS(enum_BLOCKS.M)), new BTuple(new ROUTES(enum_ROUTES.R5), new BLOCKS(enum_BLOCKS.M)), new BTuple(new ROUTES(enum_ROUTES.R6), new BLOCKS(enum_BLOCKS.C)), new BTuple(new ROUTES(enum_ROUTES.R7), new BLOCKS(enum_BLOCKS.G)), new BTuple(new ROUTES(enum_ROUTES.R8), new BLOCKS(enum_BLOCKS.N)), new BTuple(new ROUTES(enum_ROUTES.R9), new BLOCKS(enum_BLOCKS.G)), new BTuple(new ROUTES(enum_ROUTES.R10), new BLOCKS(enum_BLOCKS.N)));
        Train_1_beebook_deterministic.lst = new BRelation<ROUTES, BLOCKS>(new BTuple(new ROUTES(enum_ROUTES.R1), new BLOCKS(enum_BLOCKS.C)), new BTuple(new ROUTES(enum_ROUTES.R2), new BLOCKS(enum_BLOCKS.G)), new BTuple(new ROUTES(enum_ROUTES.R3), new BLOCKS(enum_BLOCKS.N)), new BTuple(new ROUTES(enum_ROUTES.R4), new BLOCKS(enum_BLOCKS.G)), new BTuple(new ROUTES(enum_ROUTES.R5), new BLOCKS(enum_BLOCKS.N)), new BTuple(new ROUTES(enum_ROUTES.R6), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R7), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R8), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R9), new BLOCKS(enum_BLOCKS.M)), new BTuple(new ROUTES(enum_ROUTES.R10), new BLOCKS(enum_BLOCKS.M)));
        let _ic_set_0: BRelation<BLOCKS, ROUTES> = new BRelation<BLOCKS, ROUTES>();
        for(let _ic_b_1 of Train_1_beebook_deterministic._BLOCKS) {
            for(let _ic_r_1 of Train_1_beebook_deterministic._ROUTES) {
                if((new BBoolean(Train_1_beebook_deterministic.nxt.domain().elementOf(_ic_r_1).booleanValue() && new BBoolean(Train_1_beebook_deterministic.nxt.functionCall(_ic_r_1).domain().elementOf(_ic_b_1).booleanValue() || Train_1_beebook_deterministic.nxt.functionCall(_ic_r_1).range().elementOf(_ic_b_1).booleanValue()).booleanValue())).booleanValue()) {
                    _ic_set_0 = _ic_set_0.union(new BRelation<BLOCKS, ROUTES>(new BTuple(_ic_b_1, _ic_r_1)));
                }

            }
        }
        Train_1_beebook_deterministic.rtbl = _ic_set_0;
    }

    constructor() {
        this.resrt = new BSet<ROUTES>();
        this.resbl = new BSet<BLOCKS>();
        this.rsrtbl = new BRelation<BLOCKS, ROUTES>();
        this.OCC = new BSet<BLOCKS>();
        this.TRK = new BRelation<BLOCKS, BLOCKS>();
        this.frm = new BSet<ROUTES>();
        this.LBT = new BSet<BLOCKS>();
    }


     route_reservation(r: ROUTES): void {
        let _ld_resrt: BSet<ROUTES> = this.resrt;

        let _ld_rsrtbl: BRelation<BLOCKS, ROUTES> = this.rsrtbl;
        let _ld_resbl: BSet<BLOCKS> = this.resbl;
        this.resrt = _ld_resrt.union(new BSet<ROUTES>(r));
        this.rsrtbl = _ld_rsrtbl.union(Train_1_beebook_deterministic.rtbl.rangeRestriction(new BSet<ROUTES>(r)));
        this.resbl = _ld_resbl.union(Train_1_beebook_deterministic.rtbl.inverse().relationImage(new BSet<ROUTES>(r)));

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
        this.OCC = _ld_OCC.union(new BSet<BLOCKS>(Train_1_beebook_deterministic.fst.functionCall(r)));
        this.LBT = _ld_LBT.union(new BSet<BLOCKS>(Train_1_beebook_deterministic.fst.functionCall(r)));

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
        this.TRK = this.TRK.domainSubstraction(Train_1_beebook_deterministic.nxt.functionCall(r).domain()).rangeSubstraction(Train_1_beebook_deterministic.nxt.functionCall(r).range()).union(Train_1_beebook_deterministic.nxt.functionCall(r));

    }

     route_formation(r: ROUTES): void {
        this.frm = this.frm.union(new BSet<ROUTES>(r));

    }

    _get_fst(): BRelation<ROUTES, BLOCKS> {
        return Train_1_beebook_deterministic.fst;
    }

    _get_lst(): BRelation<ROUTES, BLOCKS> {
        return Train_1_beebook_deterministic.lst;
    }

    _get_nxt(): BRelation<ROUTES, BRelation<BLOCKS, BLOCKS>> {
        return Train_1_beebook_deterministic.nxt;
    }

    _get_rtbl(): BRelation<BLOCKS, ROUTES> {
        return Train_1_beebook_deterministic.rtbl;
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
        return Train_1_beebook_deterministic._BLOCKS;
    }

    _get__ROUTES(): BSet<ROUTES> {
        return Train_1_beebook_deterministic._ROUTES;
    }


}

