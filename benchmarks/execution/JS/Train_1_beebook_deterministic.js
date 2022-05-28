import { BTuple } from './btypes/BTuple.js';
import { BBoolean } from './btypes/BBoolean.js';
import { BRelation } from './btypes/BRelation.js';
import { BSet } from './btypes/BSet.js';
export var enum_BLOCKS;
(function (enum_BLOCKS) {
    enum_BLOCKS[enum_BLOCKS["A"] = 0] = "A";
    enum_BLOCKS[enum_BLOCKS["B"] = 1] = "B";
    enum_BLOCKS[enum_BLOCKS["C"] = 2] = "C";
    enum_BLOCKS[enum_BLOCKS["D"] = 3] = "D";
    enum_BLOCKS[enum_BLOCKS["E"] = 4] = "E";
    enum_BLOCKS[enum_BLOCKS["F"] = 5] = "F";
    enum_BLOCKS[enum_BLOCKS["G"] = 6] = "G";
    enum_BLOCKS[enum_BLOCKS["H"] = 7] = "H";
    enum_BLOCKS[enum_BLOCKS["I"] = 8] = "I";
    enum_BLOCKS[enum_BLOCKS["J"] = 9] = "J";
    enum_BLOCKS[enum_BLOCKS["K"] = 10] = "K";
    enum_BLOCKS[enum_BLOCKS["L"] = 11] = "L";
    enum_BLOCKS[enum_BLOCKS["M"] = 12] = "M";
    enum_BLOCKS[enum_BLOCKS["N"] = 13] = "N";
})(enum_BLOCKS || (enum_BLOCKS = {}));
export class BLOCKS {
    constructor(value) {
        this.value = value;
    }
    equal(other) {
        return new BBoolean(this.value === other.value);
    }
    unequal(other) {
        return new BBoolean(this.value !== other.value);
    }
    equals(o) {
        if (!(o instanceof BLOCKS)) {
            return false;
        }
        return this.value === o.value;
    }
    hashCode() {
        return 0;
    }
    toString() {
        return enum_BLOCKS[this.value].toString();
    }
    static get_A() { return new BLOCKS(enum_BLOCKS.A); }
    static get_B() { return new BLOCKS(enum_BLOCKS.B); }
    static get_C() { return new BLOCKS(enum_BLOCKS.C); }
    static get_D() { return new BLOCKS(enum_BLOCKS.D); }
    static get_E() { return new BLOCKS(enum_BLOCKS.E); }
    static get_F() { return new BLOCKS(enum_BLOCKS.F); }
    static get_G() { return new BLOCKS(enum_BLOCKS.G); }
    static get_H() { return new BLOCKS(enum_BLOCKS.H); }
    static get_I() { return new BLOCKS(enum_BLOCKS.I); }
    static get_J() { return new BLOCKS(enum_BLOCKS.J); }
    static get_K() { return new BLOCKS(enum_BLOCKS.K); }
    static get_L() { return new BLOCKS(enum_BLOCKS.L); }
    static get_M() { return new BLOCKS(enum_BLOCKS.M); }
    static get_N() { return new BLOCKS(enum_BLOCKS.N); }
}
export var enum_ROUTES;
(function (enum_ROUTES) {
    enum_ROUTES[enum_ROUTES["R1"] = 0] = "R1";
    enum_ROUTES[enum_ROUTES["R2"] = 1] = "R2";
    enum_ROUTES[enum_ROUTES["R3"] = 2] = "R3";
    enum_ROUTES[enum_ROUTES["R4"] = 3] = "R4";
    enum_ROUTES[enum_ROUTES["R5"] = 4] = "R5";
    enum_ROUTES[enum_ROUTES["R6"] = 5] = "R6";
    enum_ROUTES[enum_ROUTES["R7"] = 6] = "R7";
    enum_ROUTES[enum_ROUTES["R8"] = 7] = "R8";
    enum_ROUTES[enum_ROUTES["R9"] = 8] = "R9";
    enum_ROUTES[enum_ROUTES["R10"] = 9] = "R10";
})(enum_ROUTES || (enum_ROUTES = {}));
export class ROUTES {
    constructor(value) {
        this.value = value;
    }
    equal(other) {
        return new BBoolean(this.value === other.value);
    }
    unequal(other) {
        return new BBoolean(this.value !== other.value);
    }
    equals(o) {
        if (!(o instanceof ROUTES)) {
            return false;
        }
        return this.value === o.value;
    }
    hashCode() {
        return 0;
    }
    toString() {
        return enum_ROUTES[this.value].toString();
    }
    static get_R1() { return new ROUTES(enum_ROUTES.R1); }
    static get_R2() { return new ROUTES(enum_ROUTES.R2); }
    static get_R3() { return new ROUTES(enum_ROUTES.R3); }
    static get_R4() { return new ROUTES(enum_ROUTES.R4); }
    static get_R5() { return new ROUTES(enum_ROUTES.R5); }
    static get_R6() { return new ROUTES(enum_ROUTES.R6); }
    static get_R7() { return new ROUTES(enum_ROUTES.R7); }
    static get_R8() { return new ROUTES(enum_ROUTES.R8); }
    static get_R9() { return new ROUTES(enum_ROUTES.R9); }
    static get_R10() { return new ROUTES(enum_ROUTES.R10); }
}
export default class Train_1_beebook_deterministic {
    constructor() {
        Train_1_beebook_deterministic.fst = new BRelation(new BTuple(new ROUTES(enum_ROUTES.R1), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R2), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R3), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R4), new BLOCKS(enum_BLOCKS.M)), new BTuple(new ROUTES(enum_ROUTES.R5), new BLOCKS(enum_BLOCKS.M)), new BTuple(new ROUTES(enum_ROUTES.R6), new BLOCKS(enum_BLOCKS.C)), new BTuple(new ROUTES(enum_ROUTES.R7), new BLOCKS(enum_BLOCKS.G)), new BTuple(new ROUTES(enum_ROUTES.R8), new BLOCKS(enum_BLOCKS.N)), new BTuple(new ROUTES(enum_ROUTES.R9), new BLOCKS(enum_BLOCKS.G)), new BTuple(new ROUTES(enum_ROUTES.R10), new BLOCKS(enum_BLOCKS.N)));
        Train_1_beebook_deterministic.lst = new BRelation(new BTuple(new ROUTES(enum_ROUTES.R1), new BLOCKS(enum_BLOCKS.C)), new BTuple(new ROUTES(enum_ROUTES.R2), new BLOCKS(enum_BLOCKS.G)), new BTuple(new ROUTES(enum_ROUTES.R3), new BLOCKS(enum_BLOCKS.N)), new BTuple(new ROUTES(enum_ROUTES.R4), new BLOCKS(enum_BLOCKS.G)), new BTuple(new ROUTES(enum_ROUTES.R5), new BLOCKS(enum_BLOCKS.N)), new BTuple(new ROUTES(enum_ROUTES.R6), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R7), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R8), new BLOCKS(enum_BLOCKS.L)), new BTuple(new ROUTES(enum_ROUTES.R9), new BLOCKS(enum_BLOCKS.M)), new BTuple(new ROUTES(enum_ROUTES.R10), new BLOCKS(enum_BLOCKS.M)));
        Train_1_beebook_deterministic.nxt = new BRelation(new BTuple(new ROUTES(enum_ROUTES.R1), new BRelation(new BTuple(new BLOCKS(enum_BLOCKS.L), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.C)))), new BTuple(new ROUTES(enum_ROUTES.R2), new BRelation(new BTuple(new BLOCKS(enum_BLOCKS.L), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.D)), new BTuple(new BLOCKS(enum_BLOCKS.D), new BLOCKS(enum_BLOCKS.E)), new BTuple(new BLOCKS(enum_BLOCKS.E), new BLOCKS(enum_BLOCKS.F)), new BTuple(new BLOCKS(enum_BLOCKS.F), new BLOCKS(enum_BLOCKS.G)))), new BTuple(new ROUTES(enum_ROUTES.R3), new BRelation(new BTuple(new BLOCKS(enum_BLOCKS.L), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.D)), new BTuple(new BLOCKS(enum_BLOCKS.D), new BLOCKS(enum_BLOCKS.K)), new BTuple(new BLOCKS(enum_BLOCKS.K), new BLOCKS(enum_BLOCKS.J)), new BTuple(new BLOCKS(enum_BLOCKS.J), new BLOCKS(enum_BLOCKS.N)))), new BTuple(new ROUTES(enum_ROUTES.R4), new BRelation(new BTuple(new BLOCKS(enum_BLOCKS.M), new BLOCKS(enum_BLOCKS.H)), new BTuple(new BLOCKS(enum_BLOCKS.H), new BLOCKS(enum_BLOCKS.I)), new BTuple(new BLOCKS(enum_BLOCKS.I), new BLOCKS(enum_BLOCKS.K)), new BTuple(new BLOCKS(enum_BLOCKS.K), new BLOCKS(enum_BLOCKS.F)), new BTuple(new BLOCKS(enum_BLOCKS.F), new BLOCKS(enum_BLOCKS.G)))), new BTuple(new ROUTES(enum_ROUTES.R5), new BRelation(new BTuple(new BLOCKS(enum_BLOCKS.M), new BLOCKS(enum_BLOCKS.H)), new BTuple(new BLOCKS(enum_BLOCKS.H), new BLOCKS(enum_BLOCKS.I)), new BTuple(new BLOCKS(enum_BLOCKS.I), new BLOCKS(enum_BLOCKS.J)), new BTuple(new BLOCKS(enum_BLOCKS.J), new BLOCKS(enum_BLOCKS.N)))), new BTuple(new ROUTES(enum_ROUTES.R6), new BRelation(new BTuple(new BLOCKS(enum_BLOCKS.C), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.L)))), new BTuple(new ROUTES(enum_ROUTES.R7), new BRelation(new BTuple(new BLOCKS(enum_BLOCKS.G), new BLOCKS(enum_BLOCKS.F)), new BTuple(new BLOCKS(enum_BLOCKS.F), new BLOCKS(enum_BLOCKS.E)), new BTuple(new BLOCKS(enum_BLOCKS.E), new BLOCKS(enum_BLOCKS.D)), new BTuple(new BLOCKS(enum_BLOCKS.D), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.L)))), new BTuple(new ROUTES(enum_ROUTES.R8), new BRelation(new BTuple(new BLOCKS(enum_BLOCKS.N), new BLOCKS(enum_BLOCKS.J)), new BTuple(new BLOCKS(enum_BLOCKS.J), new BLOCKS(enum_BLOCKS.K)), new BTuple(new BLOCKS(enum_BLOCKS.K), new BLOCKS(enum_BLOCKS.D)), new BTuple(new BLOCKS(enum_BLOCKS.D), new BLOCKS(enum_BLOCKS.B)), new BTuple(new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.A)), new BTuple(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.L)))), new BTuple(new ROUTES(enum_ROUTES.R9), new BRelation(new BTuple(new BLOCKS(enum_BLOCKS.G), new BLOCKS(enum_BLOCKS.F)), new BTuple(new BLOCKS(enum_BLOCKS.F), new BLOCKS(enum_BLOCKS.K)), new BTuple(new BLOCKS(enum_BLOCKS.K), new BLOCKS(enum_BLOCKS.I)), new BTuple(new BLOCKS(enum_BLOCKS.I), new BLOCKS(enum_BLOCKS.H)), new BTuple(new BLOCKS(enum_BLOCKS.H), new BLOCKS(enum_BLOCKS.M)))), new BTuple(new ROUTES(enum_ROUTES.R10), new BRelation(new BTuple(new BLOCKS(enum_BLOCKS.N), new BLOCKS(enum_BLOCKS.J)), new BTuple(new BLOCKS(enum_BLOCKS.J), new BLOCKS(enum_BLOCKS.I)), new BTuple(new BLOCKS(enum_BLOCKS.I), new BLOCKS(enum_BLOCKS.H)), new BTuple(new BLOCKS(enum_BLOCKS.H), new BLOCKS(enum_BLOCKS.M)))));
        let _ic_set_0 = new BRelation();
        for (let _ic_b_1 of Train_1_beebook_deterministic._BLOCKS) {
            for (let _ic_r_1 of Train_1_beebook_deterministic._ROUTES) {
                if ((new BBoolean(Train_1_beebook_deterministic.nxt.domain().elementOf(_ic_r_1).booleanValue() && new BBoolean(Train_1_beebook_deterministic.nxt.functionCall(_ic_r_1).domain().elementOf(_ic_b_1).booleanValue() || Train_1_beebook_deterministic.nxt.functionCall(_ic_r_1).range().elementOf(_ic_b_1).booleanValue()).booleanValue())).booleanValue()) {
                    _ic_set_0 = _ic_set_0.union(new BRelation(new BTuple(_ic_b_1, _ic_r_1)));
                }
            }
        }
        Train_1_beebook_deterministic.rtbl = _ic_set_0;
        this.resrt = new BSet();
        this.resbl = new BSet();
        this.rsrtbl = new BRelation();
        this.OCC = new BSet();
        this.TRK = new BRelation();
        this.frm = new BSet();
        this.LBT = new BSet();
    }
    route_reservation(r) {
        let _ld_resrt = this.resrt;
        let _ld_rsrtbl = this.rsrtbl;
        let _ld_resbl = this.resbl;
        this.resrt = _ld_resrt.union(new BSet(r));
        this.rsrtbl = _ld_rsrtbl.union(Train_1_beebook_deterministic.rtbl.rangeRestriction(new BSet(r)));
        this.resbl = _ld_resbl.union(Train_1_beebook_deterministic.rtbl.inverse().relationImage(new BSet(r)));
    }
    route_freeing(r) {
        let _ld_resrt = this.resrt;
        let _ld_frm = this.frm;
        this.resrt = _ld_resrt.difference(new BSet(r));
        this.frm = _ld_frm.difference(new BSet(r));
    }
    FRONT_MOVE_1(r) {
        let _ld_OCC = this.OCC;
        let _ld_LBT = this.LBT;
        this.OCC = _ld_OCC.union(new BSet(Train_1_beebook_deterministic.fst.functionCall(r)));
        this.LBT = _ld_LBT.union(new BSet(Train_1_beebook_deterministic.fst.functionCall(r)));
    }
    FRONT_MOVE_2(b) {
        this.OCC = this.OCC.union(new BSet(this.TRK.functionCall(b)));
    }
    BACK_MOVE_1(b) {
        let _ld_OCC = this.OCC;
        let _ld_rsrtbl = this.rsrtbl;
        let _ld_resbl = this.resbl;
        let _ld_LBT = this.LBT;
        this.OCC = _ld_OCC.difference(new BSet(b));
        this.rsrtbl = _ld_rsrtbl.domainSubstraction(new BSet(b));
        this.resbl = _ld_resbl.difference(new BSet(b));
        this.LBT = _ld_LBT.difference(new BSet(b));
    }
    BACK_MOVE_2(b) {
        let _ld_OCC = this.OCC;
        let _ld_rsrtbl = this.rsrtbl;
        let _ld_resbl = this.resbl;
        let _ld_LBT = this.LBT;
        this.OCC = _ld_OCC.difference(new BSet(b));
        this.rsrtbl = _ld_rsrtbl.domainSubstraction(new BSet(b));
        this.resbl = _ld_resbl.difference(new BSet(b));
        this.LBT = _ld_LBT.difference(new BSet(b)).union(new BSet(this.TRK.functionCall(b)));
    }
    point_positionning(r) {
        this.TRK = this.TRK.domainSubstraction(Train_1_beebook_deterministic.nxt.functionCall(r).domain()).rangeSubstraction(Train_1_beebook_deterministic.nxt.functionCall(r).range()).union(Train_1_beebook_deterministic.nxt.functionCall(r));
    }
    route_formation(r) {
        this.frm = this.frm.union(new BSet(r));
    }
    _get_fst() {
        return Train_1_beebook_deterministic.fst;
    }
    _get_lst() {
        return Train_1_beebook_deterministic.lst;
    }
    _get_nxt() {
        return Train_1_beebook_deterministic.nxt;
    }
    _get_rtbl() {
        return Train_1_beebook_deterministic.rtbl;
    }
    _get_LBT() {
        return this.LBT;
    }
    _get_TRK() {
        return this.TRK;
    }
    _get_frm() {
        return this.frm;
    }
    _get_OCC() {
        return this.OCC;
    }
    _get_resbl() {
        return this.resbl;
    }
    _get_resrt() {
        return this.resrt;
    }
    _get_rsrtbl() {
        return this.rsrtbl;
    }
    _get__BLOCKS() {
        return Train_1_beebook_deterministic._BLOCKS;
    }
    _get__ROUTES() {
        return Train_1_beebook_deterministic._ROUTES;
    }
}
Train_1_beebook_deterministic._BLOCKS = new BSet(new BLOCKS(enum_BLOCKS.A), new BLOCKS(enum_BLOCKS.B), new BLOCKS(enum_BLOCKS.C), new BLOCKS(enum_BLOCKS.D), new BLOCKS(enum_BLOCKS.E), new BLOCKS(enum_BLOCKS.F), new BLOCKS(enum_BLOCKS.G), new BLOCKS(enum_BLOCKS.H), new BLOCKS(enum_BLOCKS.I), new BLOCKS(enum_BLOCKS.J), new BLOCKS(enum_BLOCKS.K), new BLOCKS(enum_BLOCKS.L), new BLOCKS(enum_BLOCKS.M), new BLOCKS(enum_BLOCKS.N));
Train_1_beebook_deterministic._ROUTES = new BSet(new ROUTES(enum_ROUTES.R1), new ROUTES(enum_ROUTES.R2), new ROUTES(enum_ROUTES.R3), new ROUTES(enum_ROUTES.R4), new ROUTES(enum_ROUTES.R5), new ROUTES(enum_ROUTES.R6), new ROUTES(enum_ROUTES.R7), new ROUTES(enum_ROUTES.R8), new ROUTES(enum_ROUTES.R9), new ROUTES(enum_ROUTES.R10));
