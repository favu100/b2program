import {BTuple} from './btypes/BTuple.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BRelation} from './btypes/BRelation.js';
import {BSet} from './btypes/BSet.js';
import {BObject} from './btypes/BObject.js';
import {BUtils} from "./btypes/BUtils.js";
import * as immutable from "./immutable/dist/immutable.es.js";


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


export enum Type {
    BFS,
    DFS,
    MIXED
}

export default class Train_1_beebook_deterministic_MC_POR_v2 {

    parent: Train_1_beebook_deterministic_MC_POR_v2;
    dependentGuard: immutable.Set<string> = immutable.Set();
    guardCache: immutable.Map = immutable.Map();
    dependentInvariant: immutable.Set<string> = immutable.Set();
    stateAccessedVia: string;


    private static fst: BRelation<ROUTES, BLOCKS>;
    private static lst: BRelation<ROUTES, BLOCKS>;
    private static nxt: BRelation<ROUTES, BRelation<BLOCKS, BLOCKS>>;
    private static rtbl: BRelation<BLOCKS, ROUTES>;

    private static _BLOCKS: BSet<BLOCKS> = new BSet(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.C), new BLOCKS(enum_BLOCKS.D), new BLOCKS(enum_BLOCKS.E), new BLOCKS(enum_BLOCKS.F), new BLOCKS(enum_BLOCKS.G), new BLOCKS(enum_BLOCKS.H), new BLOCKS(enum_BLOCKS.I), new BLOCKS(enum_BLOCKS.J), new BLOCKS(enum_BLOCKS.K), new BLOCKS(enum_BLOCKS.L), new BLOCKS(enum_BLOCKS.M), new BLOCKS(enum_BLOCKS.N));
    private static _ROUTES: BSet<ROUTES> = new BSet(new ROUTES(enum_ROUTES.R1), new ROUTES(enum_ROUTES.R2), new ROUTES(enum_ROUTES.R3), new ROUTES(enum_ROUTES.R4), new ROUTES(enum_ROUTES.R5), new ROUTES(enum_ROUTES.R6), new ROUTES(enum_ROUTES.R7), new ROUTES(enum_ROUTES.R8), new ROUTES(enum_ROUTES.R9), new ROUTES(enum_ROUTES.R10));

    private LBT: BSet<BLOCKS>;
    private TRK: BRelation<BLOCKS, BLOCKS>;
    private frm: BSet<ROUTES>;
    private OCC: BSet<BLOCKS>;
    private resbl: BSet<BLOCKS>;
    private resrt: BSet<ROUTES>;
    private rsrtbl: BRelation<BLOCKS, ROUTES>;

    constructor() {
        Train_1_beebook_deterministic_MC_POR_v2.nxt = new BRelation<ROUTES, BRelation<BLOCKS, BLOCKS>>(new BTuple(new ROUTES(enum_ROUTES.R1), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.L), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.C)))), new BTuple(new ROUTES(enum_ROUTES.R2), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.L), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.D)), new BTuple(new BLOCKS(enum_BLOCKS.D), new BLOCKS(enum_BLOCKS.E)), new BTuple(new BLOCKS(enum_BLOCKS.E), new BLOCKS(enum_BLOCKS.F)), new BTuple(new BLOCKS(enum_BLOCKS.F), new BLOCKS(enum_BLOCKS.G)))), new BTuple(new ROUTES(enum_ROUTES.R3), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.L), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.D)), new BTuple(new BLOCKS(enum_BLOCKS.D), new BLOCKS(enum_BLOCKS.K)), new BTuple(new BLOCKS(enum_BLOCKS.K), new BLOCKS(enum_BLOCKS.J)), new BTuple(new BLOCKS(enum_BLOCKS.J), new BLOCKS(enum_BLOCKS.N)))), new BTuple(new ROUTES(enum_ROUTES.R4), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.M), new BLOCKS(enum_BLOCKS.H)), new BTuple(new BLOCKS(enum_BLOCKS.H), new BLOCKS(enum_BLOCKS.I)), new BTuple(new BLOCKS(enum_BLOCKS.I), new BLOCKS(enum_BLOCKS.K)), new BTuple(new BLOCKS(enum_BLOCKS.K), new BLOCKS(enum_BLOCKS.F)), new BTuple(new BLOCKS(enum_BLOCKS.F), new BLOCKS(enum_BLOCKS.G)))), new BTuple(new ROUTES(enum_ROUTES.R5), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.M), new BLOCKS(enum_BLOCKS.H)), new BTuple(new BLOCKS(enum_BLOCKS.H), new BLOCKS(enum_BLOCKS.I)), new BTuple(new BLOCKS(enum_BLOCKS.I), new BLOCKS(enum_BLOCKS.J)), new BTuple(new BLOCKS(enum_BLOCKS.J), new BLOCKS(enum_BLOCKS.N)))), new BTuple(new ROUTES(enum_ROUTES.R6), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.C), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.L)))), new BTuple(new ROUTES(enum_ROUTES.R7), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.G), new BLOCKS(enum_BLOCKS.F)), new BTuple(new BLOCKS(enum_BLOCKS.F), new BLOCKS(enum_BLOCKS.E)), new BTuple(new BLOCKS(enum_BLOCKS.E), new BLOCKS(enum_BLOCKS.D)), new BTuple(new BLOCKS(enum_BLOCKS.D), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.L)))), new BTuple(new ROUTES(enum_ROUTES.R8), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.N), new BLOCKS(enum_BLOCKS.J)), new BTuple(new BLOCKS(enum_BLOCKS.J), new BLOCKS(enum_BLOCKS.K)), new BTuple(new BLOCKS(enum_BLOCKS.K), new BLOCKS(enum_BLOCKS.D)), new BTuple(new BLOCKS(enum_BLOCKS.D), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.L)))), new BTuple(new ROUTES(enum_ROUTES.R9), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.G), new BLOCKS(enum_BLOCKS.F)), new BTuple(new BLOCKS(enum_BLOCKS.F), new BLOCKS(enum_BLOCKS.K)), new BTuple(new BLOCKS(enum_BLOCKS.K), new BLOCKS(enum_BLOCKS.I)), new BTuple(new BLOCKS(enum_BLOCKS.I), new BLOCKS(enum_BLOCKS.H)), new BTuple(new BLOCKS(enum_BLOCKS.H), new BLOCKS(enum_BLOCKS.M)))), new BTuple(new ROUTES(enum_ROUTES.R10), new BRelation<BLOCKS, BLOCKS>(new BTuple(new BLOCKS(enum_BLOCKS.N), new BLOCKS(enum_BLOCKS.J)), new BTuple(new BLOCKS(enum_BLOCKS.J), new BLOCKS(enum_BLOCKS.I)), new BTuple(new BLOCKS(enum_BLOCKS.I), new BLOCKS(enum_BLOCKS.H)), new BTuple(new BLOCKS(enum_BLOCKS.H), new BLOCKS(enum_BLOCKS.M)))));
        Train_1_beebook_deterministic_MC_POR_v2.fst = new BRelation<ROUTES, BLOCKS>(new BTuple(new ROUTES(enum_ROUTES.R1), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R2), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R3), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R4), new BLOCKS(enum_BLOCKS.M)), new BTuple(new ROUTES(enum_ROUTES.R5), new BLOCKS(enum_BLOCKS.M)), new BTuple(new ROUTES(enum_ROUTES.R6), new BLOCKS(enum_BLOCKS.C)), new BTuple(new ROUTES(enum_ROUTES.R7), new BLOCKS(enum_BLOCKS.G)), new BTuple(new ROUTES(enum_ROUTES.R8), new BLOCKS(enum_BLOCKS.N)), new BTuple(new ROUTES(enum_ROUTES.R9), new BLOCKS(enum_BLOCKS.G)), new BTuple(new ROUTES(enum_ROUTES.R10), new BLOCKS(enum_BLOCKS.N)));
        Train_1_beebook_deterministic_MC_POR_v2.lst = new BRelation<ROUTES, BLOCKS>(new BTuple(new ROUTES(enum_ROUTES.R1), new BLOCKS(enum_BLOCKS.C)), new BTuple(new ROUTES(enum_ROUTES.R2), new BLOCKS(enum_BLOCKS.G)), new BTuple(new ROUTES(enum_ROUTES.R3), new BLOCKS(enum_BLOCKS.N)), new BTuple(new ROUTES(enum_ROUTES.R4), new BLOCKS(enum_BLOCKS.G)), new BTuple(new ROUTES(enum_ROUTES.R5), new BLOCKS(enum_BLOCKS.N)), new BTuple(new ROUTES(enum_ROUTES.R6), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R7), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R8), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R9), new BLOCKS(enum_BLOCKS.M)), new BTuple(new ROUTES(enum_ROUTES.R10), new BLOCKS(enum_BLOCKS.M)));
        let _ic_set_0: BRelation<BLOCKS, ROUTES> = new BRelation<BLOCKS, ROUTES>();
        for(let _ic_b_1 of Train_1_beebook_deterministic_MC_POR_v2._BLOCKS) {
            for(let _ic_r_1 of Train_1_beebook_deterministic_MC_POR_v2._ROUTES) {
                if((new BBoolean(Train_1_beebook_deterministic_MC_POR_v2.nxt.domain().elementOf(_ic_r_1).booleanValue() && new BBoolean(Train_1_beebook_deterministic_MC_POR_v2.nxt.functionCall(_ic_r_1).domain().elementOf(_ic_b_1).booleanValue() || Train_1_beebook_deterministic_MC_POR_v2.nxt.functionCall(_ic_r_1).range().elementOf(_ic_b_1).booleanValue()).booleanValue())).booleanValue()) {
                    _ic_set_0 = _ic_set_0.union(new BRelation<BLOCKS, ROUTES>(new BTuple(_ic_b_1, _ic_r_1)));
                }

            }
        }
        Train_1_beebook_deterministic_MC_POR_v2.rtbl = _ic_set_0;
        this.resrt = new BSet();
        this.resbl = new BSet();
        this.rsrtbl = new BRelation<BLOCKS, ROUTES>();
        this.OCC = new BSet();
        this.TRK = new BRelation<BLOCKS, BLOCKS>();
        this.frm = new BSet();
        this.LBT = new BSet();
    }


     route_reservation(r: ROUTES): void {
        let _ld_resrt: BSet<ROUTES> = this.resrt;

        let _ld_rsrtbl: BRelation<BLOCKS, ROUTES> = this.rsrtbl;
        let _ld_resbl: BSet<BLOCKS> = this.resbl;
        this.resrt = _ld_resrt.union(new BSet(r));
        this.rsrtbl = _ld_rsrtbl.union(Train_1_beebook_deterministic_MC_POR_v2.rtbl.rangeRestriction(new BSet(r)));
        this.resbl = _ld_resbl.union(Train_1_beebook_deterministic_MC_POR_v2.rtbl.inverse().relationImage(new BSet(r)));
    }

     route_freeing(r: ROUTES): void {
        let _ld_resrt: BSet<ROUTES> = this.resrt;

        let _ld_frm: BSet<ROUTES> = this.frm;
        this.resrt = _ld_resrt.difference(new BSet(r));
        this.frm = _ld_frm.difference(new BSet(r));
    }

     FRONT_MOVE_1(r: ROUTES): void {
        let _ld_OCC: BSet<BLOCKS> = this.OCC;
        let _ld_LBT: BSet<BLOCKS> = this.LBT;
        this.OCC = _ld_OCC.union(new BSet(Train_1_beebook_deterministic_MC_POR_v2.fst.functionCall(r)));
        this.LBT = _ld_LBT.union(new BSet(Train_1_beebook_deterministic_MC_POR_v2.fst.functionCall(r)));
    }

     FRONT_MOVE_2(b: BLOCKS): void {
        this.OCC = this.OCC.union(new BSet(this.TRK.functionCall(b)));
    }

     BACK_MOVE_1(b: BLOCKS): void {
        let _ld_OCC: BSet<BLOCKS> = this.OCC;
        let _ld_rsrtbl: BRelation<BLOCKS, ROUTES> = this.rsrtbl;
        let _ld_resbl: BSet<BLOCKS> = this.resbl;
        let _ld_LBT: BSet<BLOCKS> = this.LBT;
        this.OCC = _ld_OCC.difference(new BSet(b));
        this.rsrtbl = _ld_rsrtbl.domainSubstraction(new BSet(b));
        this.resbl = _ld_resbl.difference(new BSet(b));
        this.LBT = _ld_LBT.difference(new BSet(b));
    }

     BACK_MOVE_2(b: BLOCKS): void {
        let _ld_OCC: BSet<BLOCKS> = this.OCC;
        let _ld_rsrtbl: BRelation<BLOCKS, ROUTES> = this.rsrtbl;
        let _ld_resbl: BSet<BLOCKS> = this.resbl;
        let _ld_LBT: BSet<BLOCKS> = this.LBT;
        this.OCC = _ld_OCC.difference(new BSet(b));
        this.rsrtbl = _ld_rsrtbl.domainSubstraction(new BSet(b));
        this.resbl = _ld_resbl.difference(new BSet(b));
        this.LBT = _ld_LBT.difference(new BSet(b)).union(new BSet(this.TRK.functionCall(b)));
    }

     point_positionning(r: ROUTES): void {
        this.TRK = this.TRK.domainSubstraction(Train_1_beebook_deterministic_MC_POR_v2.nxt.functionCall(r).domain()).rangeSubstraction(Train_1_beebook_deterministic_MC_POR_v2.nxt.functionCall(r).range()).union(Train_1_beebook_deterministic_MC_POR_v2.nxt.functionCall(r));
    }

     route_formation(r: ROUTES): void {
        this.frm = this.frm.union(new BSet(r));
    }

    _get_fst(): BRelation<ROUTES, BLOCKS> {
        return Train_1_beebook_deterministic_MC_POR_v2.fst;
    }

    _get_lst(): BRelation<ROUTES, BLOCKS> {
        return Train_1_beebook_deterministic_MC_POR_v2.lst;
    }

    _get_nxt(): BRelation<ROUTES, BRelation<BLOCKS, BLOCKS>> {
        return Train_1_beebook_deterministic_MC_POR_v2.nxt;
    }

    _get_rtbl(): BRelation<BLOCKS, ROUTES> {
        return Train_1_beebook_deterministic_MC_POR_v2.rtbl;
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
        return Train_1_beebook_deterministic_MC_POR_v2._BLOCKS;
    }

    _get__ROUTES(): BSet<ROUTES> {
        return Train_1_beebook_deterministic_MC_POR_v2._ROUTES;
    }

    _tr_route_reservation(): BSet<ROUTES> {
        let _ic_set_1: BSet<ROUTES> = new BSet<ROUTES>();
        for(let _ic_r_1 of Train_1_beebook_deterministic_MC_POR_v2._ROUTES.difference(this.resrt)) {
            if((new BBoolean(Train_1_beebook_deterministic_MC_POR_v2.rtbl.inverse().relationImage(new BSet(_ic_r_1)).intersect(this.resbl).equal(new BSet()).booleanValue() && new BSet().equal(this.resrt.difference(this.rsrtbl.range())).booleanValue())).booleanValue()) {
                _ic_set_1 = _ic_set_1.union(new BSet<ROUTES>(_ic_r_1));
            }

        }
        return _ic_set_1;
    }

    _tr_route_freeing(): BSet<ROUTES> {
        let _ic_set_2: BSet<ROUTES> = new BSet<ROUTES>();
        for(let _ic_r_1 of this.resrt.difference(this.rsrtbl.range())) {
            _ic_set_2 = _ic_set_2.union(new BSet<ROUTES>(_ic_r_1));

        }
        return _ic_set_2;
    }

    _tr_FRONT_MOVE_1(): BSet<ROUTES> {
        let _ic_set_3: BSet<ROUTES> = new BSet<ROUTES>();
        for(let _ic_r_1 of this.frm) {
            if((new BBoolean(new BBoolean(this.resbl.difference(this.OCC).elementOf(Train_1_beebook_deterministic_MC_POR_v2.fst.functionCall(_ic_r_1)).booleanValue() && _ic_r_1.equal(this.rsrtbl.functionCall(Train_1_beebook_deterministic_MC_POR_v2.fst.functionCall(_ic_r_1))).booleanValue()).booleanValue() && new BSet().equal(this.resrt.difference(this.rsrtbl.range())).booleanValue())).booleanValue()) {
                _ic_set_3 = _ic_set_3.union(new BSet<ROUTES>(_ic_r_1));
            }

        }
        return _ic_set_3;
    }

    _tr_FRONT_MOVE_2(): BSet<BLOCKS> {
        let _ic_set_4: BSet<BLOCKS> = new BSet<BLOCKS>();
        for(let _ic_b_1 of this.OCC.intersect(this.TRK.domain())) {
            if((this.OCC.notElementOf(this.TRK.functionCall(_ic_b_1))).booleanValue()) {
                _ic_set_4 = _ic_set_4.union(new BSet<BLOCKS>(_ic_b_1));
            }

        }
        return _ic_set_4;
    }

    _tr_BACK_MOVE_1(): BSet<BLOCKS> {
        let _ic_set_5: BSet<BLOCKS> = new BSet<BLOCKS>();
        for(let _ic_b_1 of this.LBT.difference(this.TRK.domain())) {
            if((new BSet().equal(this.resrt.difference(this.rsrtbl.range()))).booleanValue()) {
                _ic_set_5 = _ic_set_5.union(new BSet<BLOCKS>(_ic_b_1));
            }

        }
        return _ic_set_5;
    }

    _tr_BACK_MOVE_2(): BSet<BLOCKS> {
        let _ic_set_6: BSet<BLOCKS> = new BSet<BLOCKS>();
        for(let _ic_b_1 of this.LBT.intersect(this.TRK.domain())) {
            if((new BBoolean(this.OCC.elementOf(this.TRK.functionCall(_ic_b_1)).booleanValue() && new BSet().equal(this.resrt.difference(this.rsrtbl.range())).booleanValue())).booleanValue()) {
                _ic_set_6 = _ic_set_6.union(new BSet<BLOCKS>(_ic_b_1));
            }

        }
        return _ic_set_6;
    }

    _tr_point_positionning(): BSet<ROUTES> {
        let _ic_set_7: BSet<ROUTES> = new BSet<ROUTES>();
        for(let _ic_r_1 of this.resrt.difference(this.frm)) {
            if((new BSet().equal(this.resrt.difference(this.rsrtbl.range()))).booleanValue()) {
                _ic_set_7 = _ic_set_7.union(new BSet<ROUTES>(_ic_r_1));
            }

        }
        return _ic_set_7;
    }

    _tr_route_formation(): BSet<ROUTES> {
        let _ic_set_8: BSet<ROUTES> = new BSet<ROUTES>();
        for(let _ic_r_1 of this.resrt.difference(this.frm)) {
            if((new BBoolean(Train_1_beebook_deterministic_MC_POR_v2.nxt.functionCall(_ic_r_1).domainRestriction(this.rsrtbl.inverse().relationImage(new BSet(_ic_r_1))).equal(this.TRK.domainRestriction(this.rsrtbl.inverse().relationImage(new BSet(_ic_r_1)))).booleanValue() && new BSet().equal(this.resrt.difference(this.rsrtbl.range())).booleanValue())).booleanValue()) {
                _ic_set_8 = _ic_set_8.union(new BSet<ROUTES>(_ic_r_1));
            }

        }
        return _ic_set_8;
    }

    _check_inv_1() {
        return this.TRK.checkDomain(Train_1_beebook_deterministic_MC_POR_v2._BLOCKS).and(this.TRK.checkRange(Train_1_beebook_deterministic_MC_POR_v2._BLOCKS)).and(this.TRK.isFunction()).and(this.TRK.isPartial(Train_1_beebook_deterministic_MC_POR_v2._BLOCKS)).and(this.TRK.isInjection()).booleanValue();
    }

    _check_inv_2() {
        let _ic_boolean_9: BBoolean = new BBoolean(true);
        for(let _ic_r_1 of this.resrt.difference(this.frm)) {
            for(let _ic_a_1 of Array.of(new BSet(_ic_r_1))) {
                if(!(Train_1_beebook_deterministic_MC_POR_v2.rtbl.rangeRestriction(_ic_a_1).equal(this.rsrtbl.rangeRestriction(_ic_a_1))).booleanValue()) {
                    _ic_boolean_9 = new BBoolean(false);
                    break;
                }

            }

        }
        return _ic_boolean_9.booleanValue();
    }

    _check_inv_3() {
        let _ic_boolean_11: BBoolean = new BBoolean(true);
        for(let _ic_x_1 of this.TRK.domain()) {
            for(let _ic_y_1 of this.TRK.relationImage(new BSet(_ic_x_1))) {
                let _ic_boolean_10: BBoolean = new BBoolean(false);
                for(let _ic_r_1 of Train_1_beebook_deterministic_MC_POR_v2._ROUTES) {
                    if((Train_1_beebook_deterministic_MC_POR_v2.nxt.functionCall(_ic_r_1).elementOf(new BTuple(_ic_x_1, _ic_y_1))).booleanValue()) {
                        _ic_boolean_10 = new BBoolean(true);
                        break;
                    }

                }
                if(!(_ic_boolean_10).booleanValue()) {
                    _ic_boolean_11 = new BBoolean(false);
                    break;
                }

            }
        }
        return _ic_boolean_11.booleanValue();
    }

    _check_inv_4() {
        let _ic_boolean_12: BBoolean = new BBoolean(true);
        for(let _ic_r_1 of this.frm) {
            for(let _ic_a_1 of Array.of(this.rsrtbl.inverse().relationImage(new BSet(_ic_r_1)))) {
                if(!(Train_1_beebook_deterministic_MC_POR_v2.nxt.functionCall(_ic_r_1).domainRestriction(_ic_a_1).equal(this.TRK.domainRestriction(_ic_a_1))).booleanValue()) {
                    _ic_boolean_12 = new BBoolean(false);
                    break;
                }

            }

        }
        return _ic_boolean_12.booleanValue();
    }

    _check_inv_5() {
        return this.LBT.subset(this.OCC).booleanValue();
    }

    _check_inv_6() {
        let _ic_boolean_13: BBoolean = new BBoolean(true);
        for(let _ic_a_1 of this.rsrtbl.domain()) {
            for(let _ic_b_1 of this.LBT) {
                for(let _ic_c_1 of Array.of(this.rsrtbl.functionCall(_ic_b_1))) {
                    for(let _ic_d_1 of Array.of(Train_1_beebook_deterministic_MC_POR_v2.nxt.functionCall(_ic_c_1))) {
                        if(!(new BBoolean(!new BBoolean(_ic_d_1.range().elementOf(_ic_b_1).booleanValue() && _ic_a_1.equal(_ic_d_1.inverse().functionCall(_ic_b_1)).booleanValue()).booleanValue() || this.rsrtbl.functionCall(_ic_a_1).unequal(_ic_c_1).booleanValue())).booleanValue()) {
                            _ic_boolean_13 = new BBoolean(false);
                            break;
                        }

                    }

                }

            }
        }
        return _ic_boolean_13.booleanValue();
    }

    _check_inv_7() {
        return this.rsrtbl.checkDomain(this.resbl).and(this.rsrtbl.checkRange(this.resrt)).and(this.rsrtbl.isFunction()).and(this.rsrtbl.isTotal(this.resbl)).booleanValue();
    }

    _check_inv_8() {
        return this.rsrtbl.subset(Train_1_beebook_deterministic_MC_POR_v2.rtbl).booleanValue();
    }

    _check_inv_9() {
        return this.OCC.subset(this.resbl).booleanValue();
    }

    _check_inv_10() {
        let _ic_boolean_14: BBoolean = new BBoolean(true);
        for(let _ic_r_1 of Train_1_beebook_deterministic_MC_POR_v2._ROUTES) {
            for(let _ic_a_1 of Array.of(Train_1_beebook_deterministic_MC_POR_v2.nxt.functionCall(_ic_r_1))) {
                for(let _ic_b_1 of Array.of(this.rsrtbl.inverse().relationImage(new BSet(_ic_r_1)))) {
                    for(let _ic_c_1 of Array.of(_ic_b_1.difference(this.OCC))) {
                        if(!(new BBoolean(new BBoolean(_ic_a_1.relationImage(Train_1_beebook_deterministic_MC_POR_v2.rtbl.inverse().relationImage(new BSet(_ic_r_1)).difference(_ic_b_1)).intersect(_ic_c_1).equal(new BSet()).booleanValue() && _ic_a_1.relationImage(_ic_b_1).subset(_ic_b_1).booleanValue()).booleanValue() && _ic_a_1.relationImage(_ic_c_1).subset(_ic_c_1).booleanValue())).booleanValue()) {
                            _ic_boolean_14 = new BBoolean(false);
                            break;
                        }

                    }

                }

            }

        }
        return _ic_boolean_14.booleanValue();
    }

    _check_inv_11() {
        return this.frm.subset(this.resrt).booleanValue();
    }

    _check_inv_12() {
        return this.rsrtbl.relationImage(this.OCC).subset(this.frm).booleanValue();
    }

    equals(o: any): boolean {
        let o1: Train_1_beebook_deterministic_MC_POR_v2 = this;
        let o2: Train_1_beebook_deterministic_MC_POR_v2 = o as Train_1_beebook_deterministic_MC_POR_v2;
        return o1._get_fst().equals(o2._get_fst()) && o1._get_lst().equals(o2._get_lst()) && o1._get_nxt().equals(o2._get_nxt()) && o1._get_rtbl().equals(o2._get_rtbl()) && o1._get_LBT().equals(o2._get_LBT()) && o1._get_TRK().equals(o2._get_TRK()) && o1._get_frm().equals(o2._get_frm()) && o1._get_OCC().equals(o2._get_OCC()) && o1._get_resbl().equals(o2._get_resbl()) && o1._get_resrt().equals(o2._get_resrt()) && o1._get_rsrtbl().equals(o2._get_rsrtbl());
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


    public _copy(): Train_1_beebook_deterministic_MC_POR_v2 {
      const _instance = new Train_1_beebook_deterministic_MC_POR_v2();
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

    private unvisitedStates: Train_1_beebook_deterministic_MC_POR_v2[] = new Array();
    private states: immutable.Set<Train_1_beebook_deterministic_MC_POR_v2> = new immutable.Set();
    private transitions: number = 0;

    private invariantViolated: boolean = false;
    private deadlockDetected: boolean = false;
    private counterExampleState: Train_1_beebook_deterministic_MC_POR_v2 = undefined;

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
        let machine: Train_1_beebook_deterministic_MC_POR_v2 = new Train_1_beebook_deterministic_MC_POR_v2();
        this.states = this.states.add(machine);
        this.unvisitedStates.push(machine);

        if(this.isCaching) {
            this.initCache(machine);
        }

        while(!(this.unvisitedStates.length === 0)) {
            let state: Train_1_beebook_deterministic_MC_POR_v2 = this.next();

            let nextStates: Set<Train_1_beebook_deterministic_MC_POR_v2> = this.generateNextStates(state);

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

    initCache(machine: Train_1_beebook_deterministic_MC_POR_v2 ): void {
        this.invariantDependency = this.invariantDependency.set("point_positionning", immutable.Set(["_check_inv_3", "_check_inv_1", "_check_inv_4"]));
        this.invariantDependency = this.invariantDependency.set("route_reservation", immutable.Set(["_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_8", "_check_inv_12", "_check_inv_9", "_check_inv_11"]));
        this.invariantDependency = this.invariantDependency.set("FRONT_MOVE_1", immutable.Set(["_check_inv_6", "_check_inv_10", "_check_inv_5", "_check_inv_12", "_check_inv_9"]));
        this.invariantDependency = this.invariantDependency.set("BACK_MOVE_1", immutable.Set(["_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_5", "_check_inv_8", "_check_inv_12", "_check_inv_9"]));
        this.invariantDependency = this.invariantDependency.set("FRONT_MOVE_2", immutable.Set(["_check_inv_10", "_check_inv_5", "_check_inv_12", "_check_inv_9"]));
        this.invariantDependency = this.invariantDependency.set("route_formation", immutable.Set(["_check_inv_2", "_check_inv_4", "_check_inv_12", "_check_inv_11"]));
        this.invariantDependency = this.invariantDependency.set("route_freeing", immutable.Set(["_check_inv_2", "_check_inv_7", "_check_inv_4", "_check_inv_12", "_check_inv_11"]));
        this.invariantDependency = this.invariantDependency.set("BACK_MOVE_2", immutable.Set(["_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_5", "_check_inv_8", "_check_inv_12", "_check_inv_9"]));
        this.guardDependency = this.guardDependency.set("point_positionning", immutable.Set(["_tr_route_formation", "_tr_BACK_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"]));
        this.guardDependency = this.guardDependency.set("route_reservation", immutable.Set(["_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_BACK_MOVE_2"]));
        this.guardDependency = this.guardDependency.set("FRONT_MOVE_1", immutable.Set(["_tr_FRONT_MOVE_1", "_tr_BACK_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"]));
        this.guardDependency = this.guardDependency.set("BACK_MOVE_1", immutable.Set(["_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"]));
        this.guardDependency = this.guardDependency.set("FRONT_MOVE_2", immutable.Set(["_tr_FRONT_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"]));
        this.guardDependency = this.guardDependency.set("route_formation", immutable.Set(["_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_point_positionning"]));
        this.guardDependency = this.guardDependency.set("route_freeing", immutable.Set(["_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_BACK_MOVE_2"]));
        this.guardDependency = this.guardDependency.set("BACK_MOVE_2", immutable.Set(["_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"]));
    }

    next(): Train_1_beebook_deterministic_MC_POR_v2 {
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

    generateNextStates(state: Train_1_beebook_deterministic_MC_POR_v2): Set<Train_1_beebook_deterministic_MC_POR_v2> {
        let result: immutable.Set<Train_1_beebook_deterministic_MC_POR_v2> = immutable.Set();
        if(this.isCaching) {
            let parentsGuard: immutable.Map = state.guardCache;
            let newCache: immutable.Map = parentsGuard == null ? immutable.Map() : parentsGuard;
            let cachedValue: any = null;
            let dependentGuardsBoolean: boolean = true;
            let _trid_1: BSet<ROUTES>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_route_reservation");
                dependentGuardsBoolean = "_tr_route_reservation" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_1 = state._tr_route_reservation();
            } else {
                _trid_1 = cachedValue as BSet<ROUTES>;
            }
            newCache = newCache.set("_tr_route_reservation", _trid_1);
            for(let param of _trid_1) {
                let _tmp_1: ROUTES = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v2 = state._copy();
                copiedState.route_reservation(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("route_reservation", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_2: BSet<ROUTES>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_route_freeing");
                dependentGuardsBoolean = "_tr_route_freeing" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_2 = state._tr_route_freeing();
            } else {
                _trid_2 = cachedValue as BSet<ROUTES>;
            }
            newCache = newCache.set("_tr_route_freeing", _trid_2);
            for(let param of _trid_2) {
                let _tmp_1: ROUTES = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v2 = state._copy();
                copiedState.route_freeing(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("route_freeing", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_3: BSet<ROUTES>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_FRONT_MOVE_1");
                dependentGuardsBoolean = "_tr_FRONT_MOVE_1" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_3 = state._tr_FRONT_MOVE_1();
            } else {
                _trid_3 = cachedValue as BSet<ROUTES>;
            }
            newCache = newCache.set("_tr_FRONT_MOVE_1", _trid_3);
            for(let param of _trid_3) {
                let _tmp_1: ROUTES = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v2 = state._copy();
                copiedState.FRONT_MOVE_1(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("FRONT_MOVE_1", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_4: BSet<BLOCKS>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_FRONT_MOVE_2");
                dependentGuardsBoolean = "_tr_FRONT_MOVE_2" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_4 = state._tr_FRONT_MOVE_2();
            } else {
                _trid_4 = cachedValue as BSet<BLOCKS>;
            }
            newCache = newCache.set("_tr_FRONT_MOVE_2", _trid_4);
            for(let param of _trid_4) {
                let _tmp_1: BLOCKS = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v2 = state._copy();
                copiedState.FRONT_MOVE_2(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("FRONT_MOVE_2", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_5: BSet<BLOCKS>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_BACK_MOVE_1");
                dependentGuardsBoolean = "_tr_BACK_MOVE_1" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_5 = state._tr_BACK_MOVE_1();
            } else {
                _trid_5 = cachedValue as BSet<BLOCKS>;
            }
            newCache = newCache.set("_tr_BACK_MOVE_1", _trid_5);
            for(let param of _trid_5) {
                let _tmp_1: BLOCKS = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v2 = state._copy();
                copiedState.BACK_MOVE_1(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("BACK_MOVE_1", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_6: BSet<BLOCKS>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_BACK_MOVE_2");
                dependentGuardsBoolean = "_tr_BACK_MOVE_2" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_6 = state._tr_BACK_MOVE_2();
            } else {
                _trid_6 = cachedValue as BSet<BLOCKS>;
            }
            newCache = newCache.set("_tr_BACK_MOVE_2", _trid_6);
            for(let param of _trid_6) {
                let _tmp_1: BLOCKS = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v2 = state._copy();
                copiedState.BACK_MOVE_2(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("BACK_MOVE_2", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_7: BSet<ROUTES>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_point_positionning");
                dependentGuardsBoolean = "_tr_point_positionning" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_7 = state._tr_point_positionning();
            } else {
                _trid_7 = cachedValue as BSet<ROUTES>;
            }
            newCache = newCache.set("_tr_point_positionning", _trid_7);
            for(let param of _trid_7) {
                let _tmp_1: ROUTES = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v2 = state._copy();
                copiedState.point_positionning(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("point_positionning", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_8: BSet<ROUTES>;
            if(!(state.dependentGuard.size === 0)) {
                cachedValue = parentsGuard.get("_tr_route_formation");
                dependentGuardsBoolean = "_tr_route_formation" in state.dependentGuard;
            }

            if(state.dependentGuard.size === 0 || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_8 = state._tr_route_formation();
            } else {
                _trid_8 = cachedValue as BSet<ROUTES>;
            }
            newCache = newCache.set("_tr_route_formation", _trid_8);
            for(let param of _trid_8) {
                let _tmp_1: ROUTES = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v2 = state._copy();
                copiedState.route_formation(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("route_formation", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

            state.guardCache = newCache;
        } else {
            let _trid_1: BSet<ROUTES> = state._tr_route_reservation();
            for(let param of _trid_1) {
                let _tmp_1: ROUTES = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v2 = state._copy();
                copiedState.route_reservation(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("route_reservation", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_2: BSet<ROUTES> = state._tr_route_freeing();
            for(let param of _trid_2) {
                let _tmp_1: ROUTES = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v2 = state._copy();
                copiedState.route_freeing(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("route_freeing", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_3: BSet<ROUTES> = state._tr_FRONT_MOVE_1();
            for(let param of _trid_3) {
                let _tmp_1: ROUTES = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v2 = state._copy();
                copiedState.FRONT_MOVE_1(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("FRONT_MOVE_1", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_4: BSet<BLOCKS> = state._tr_FRONT_MOVE_2();
            for(let param of _trid_4) {
                let _tmp_1: BLOCKS = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v2 = state._copy();
                copiedState.FRONT_MOVE_2(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("FRONT_MOVE_2", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_5: BSet<BLOCKS> = state._tr_BACK_MOVE_1();
            for(let param of _trid_5) {
                let _tmp_1: BLOCKS = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v2 = state._copy();
                copiedState.BACK_MOVE_1(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("BACK_MOVE_1", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_6: BSet<BLOCKS> = state._tr_BACK_MOVE_2();
            for(let param of _trid_6) {
                let _tmp_1: BLOCKS = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v2 = state._copy();
                copiedState.BACK_MOVE_2(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("BACK_MOVE_2", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_7: BSet<ROUTES> = state._tr_point_positionning();
            for(let param of _trid_7) {
                let _tmp_1: ROUTES = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v2 = state._copy();
                copiedState.point_positionning(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("point_positionning", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }
            let _trid_8: BSet<ROUTES> = state._tr_route_formation();
            for(let param of _trid_8) {
                let _tmp_1: ROUTES = param;

                let copiedState: Train_1_beebook_deterministic_MC_POR_v2 = state._copy();
                copiedState.route_formation(_tmp_1);
                copiedState.parent = state;
                this.addCachedInfos("route_formation", state, copiedState);
                result = result.add(copiedState);
                this.transitions = this.transitions + 1;
            }

        }
        return result;
    }

    invViolated(state: Train_1_beebook_deterministic_MC_POR_v2): boolean {
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
        return false;
    }

    addCachedInfos(operation: string, state: Train_1_beebook_deterministic_MC_POR_v2, copiedState: Train_1_beebook_deterministic_MC_POR_v2): void {
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

